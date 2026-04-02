# Bare-Metal C String Library (`mystring_lib`)

A lightweight, standalone implementation of essential `string.h` functions, developed for resource-constrained embedded systems and R&D applications.

## 💡 Motivation
In the world of firmware engineering and TinyML, every byte and clock cycle counts. This project is a deep dive into the "guts" of C, moving away from high-level abstractions to master:
* **Manual Memory Management:** Handling contiguous blocks of RAM without the overhead of a standard library.
* **Pointer Arithmetic:** Traversing strings using direct memory address offsets.
* **Architectural Awareness:** Understanding how data types are promoted and truncated across different CPU architectures.

---

## 🛠 Implemented Functions

| Function | Signature | Key Engineering Lesson |
| :--- | :--- | :--- |
| `my_strlen` | `size_t my_strlen(const char *str)` | Implemented via **Pointer Subtraction** to eliminate extra counter variables. |
| `my_strcpy` | `char *my_strcpy(char *dest, const char *src)` | Managed the `const` contract and manual null-termination logic. |
| `my_strcmp` | `int my_strcmp(const char *l, const char *r)` | Used `unsigned char` casting to ensure consistent behavior across signed/unsigned architectures. |
| `my_memset` | `void *my_memset(void *ptr, int x, size_t n)` | Handled `void *` arithmetic by casting to a byte-addressable pointer. |
| `my_strchr` | `char *my_strchr(const char *str, int ch)` | Handled search logic including the null-terminator edge case. |

---

## 🏗 Build & Integration
This library is designed to be compiled as a **Static Library (`.a`)**, which allows for modularity and faster link times in larger firmware projects.

### 1. Compile Object Files
Generate machine code for each module without linking:
```bash
gcc -c my_strcmp.c my_strcpy.c my_strlen.c my_memset.c my_strchr.c
```

### 2. Create the Static Archive
Bundle the objects into a single library file:
```bash
ar rcs libmystring.a *.o
```
### 3. Link to an Application
Compile your main.c and link it against your custom library:
```bash
gcc main.c -L. -lmystring -o firmware_test
```

## 📈 Performance & Efficiency Analysis
To validate the efficiency of the implementation, I performed a benchmark on the strcpy logic using different GCC optimization levels:

* **Execution Time (1M iterations):**
#### 1. -O0 (No Optimization): 49.16ms
#### 2. -O3 (Speed Optimized): 32.89ms (~33% performance gain via loop unrolling).

* **Code Size:** The core logic remains extremely compact (approx. 200 bytes total), significantly reducing the Flash memory footprint compared to the standard Windows-linked string.h overhead.

## 👤 Author

Luqman Final-year Mechatronic Engineering Student

Focus: Embedded Systems, Firmware R&D, and TinyML.
