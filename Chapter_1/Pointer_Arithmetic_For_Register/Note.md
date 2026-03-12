# Chapter 1.1: Memory-Mapped I/O & Register-Level Pointer Arithmetic

**Objective:** To understand and implement industry-standard methods for accessing hardware registers in C, bypassing abstraction layers (HALs) to ensure deterministic control, optimal performance, and safe memory manipulation.

**Target Hardware:** ARM Cortex-M architecture (e.g., STM32H7).

---

## 1. The Core Mechanisms: Raw Addresses to Pointers
In embedded systems, hardware peripherals (like GPIO, Timers, and ADCs) are controlled by reading and writing to specific memory addresses. To interact with a raw hex address (e.g., `0x40020C00`), we must explicitly tell the C compiler how to handle it.

### The `volatile` Keyword
Hardware registers can change state independently of the software (e.g., a pin goes HIGH due to an external sensor). 
* **Rule:** Always use `volatile` when pointing to a hardware register.
* **Why:** It forces the compiler to fetch the value directly from memory every single time, preventing it from optimizing the read/write operations into a cached CPU register.

---

## 2. Method 1: Direct Macro Mapping
For single, standalone registers—such as the Reset and Clock Control (RCC)—the standard approach is to use a preprocessor macro.

```c
// Enabling the clock for a specific peripheral port
#define RCC_IOPENR (*(volatile uint32_t*) 0x40021034)

void enable_clock(void) {
    RCC_IOPENR |= (1 << 3); // Set bit 3
}

```
## 3. C Struct Mapping (Industry Standard for Peripherals)
While macros are fine for single registers, peripherals like GPIO have multiple registers spaced apart by specific offsets. Defining individual macros for every register across every port violates the DRY (Don't Repeat Yourself) principle and makes code hard to maintain.

The professional solution is Struct-Based Mapping.

**Defining the Blueprint (The _t Convention)**
We define a struct matching the exact memory layout of the peripheral block. Because each member is a uint32_t (4 bytes), the compiler automatically calculates the 4-byte hardware offsets (`0x00`, `0x04`, `0x08`, etc.).

```c
#include <stdint.h>
#include <assert.h>

typedef struct {
    uint32_t MODER;   // Offset: 0x00 (Mode Register)
    uint32_t OTYPER;  // Offset: 0x04 (Output Type Register)
    uint32_t OSPEEDR; // Offset: 0x08 (Output Speed Register)
    uint32_t PUPDR;   // Offset: 0x0C (Pull-up/Pull-down Register)
    // ... remaining registers
} GPIO_t;

// Compiler validation: Ensure the struct size aligns with the datasheet
// Prevents accidental padding issues that would misalign hardware addresses
_Static_assert(sizeof(GPIO_t) == 40, "Error: GPIO_t size mismatch!");
```
Note: The `_t` suffix is a POSIX standard convention denoting a user-defined "type" blueprint rather than an active variable.

**Instantiating the Pointer**
Instead of dereferencing immediately, we declare a constant pointer to the base address of the peripheral block.

```c
// GPIOD base address mapped to our struct blueprint
volatile GPIO_t* const portd = (GPIO_t*)0x40020C00;
```

* **volatile `GPIO_t*`**: The hardware data at the address can change unexpectedly.

* **const portd**: The pointer itself is locked to 0x40020C00. It cannot be accidentally reassigned to point to another memory location.

## 4. Hardware Access: The Arrow Operator (->) 
To manipulate the hardware, we use the arrow operator ->. This operator safely performs two tasks simultaneously: it dereferences the struct pointer and applies the memory offset for the specific member.

**Read-Modify-Write Pattern**
Setting a pin mode (e.g., PA5) requires careful bitwise manipulation to avoid overwriting adjacent pin configurations.

```c
// Target: Configure Pin 5 (uses bits 10 and 11 in MODER)

// 1. CLEAR the target bits first (Industry Best Practice)
// 3 in binary is 0b11. Shifted left by 10, then inverted to clear only those two bits.
portd->MODER &= ~(3 << 10); 

// 2. SET the new configuration (e.g., Output mode is 0b01)
portd->MODER |= (1 << 10);
