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
