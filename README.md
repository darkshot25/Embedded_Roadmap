# Embedded Systems & Post-Silicon Validation: A 6-Month Upskilling Journey

Welcome to my technical documentation and portfolio repository. This repository tracks a comprehensive, 24-week continuous learning plan dedicated to mastering embedded firmware development and hardware validation. 

**Goal:** To bridge the gap between academic engineering principles and industry-standard R&D practices, specifically targeting Embedded Firmware and Post-Silicon Validation roles.
**Philosophy:** Prioritizing ecosystem understanding and low-level hardware interaction over high-level application development.

---

## 🧭 Core Skill Domains Developed
This roadmap is engineered to build proficiency across four critical industry domains:
1. **Firmware Development:** Transitioning from bare-metal C to RTOS integration (FreeRTOS) and ARM Cortex-M architecture optimization.
2. **Hardware-Software Interface:** Mastering memory-mapped I/O, volatile pointers, DMA, and asynchronous interrupt handling.
3. **Post-Silicon Validation:** Board bring-up, silicon characterization, and hardware fault injection/debugging.
4. **Test Automation & Tooling:** Developing automated test frameworks using Python, and utilizing logic analyzers and SWD/JTAG debuggers.

---

## 📂 Repository Structure

The documentation is organized chronologically to reflect the "just enough" progressive learning approach. Each chapter contains detailed study notes (`Note.md`), hardware setup configurations, and the corresponding `.c` source code.


* **`Chapter 1: Bare-Metal C & Register-Level GPIO`** (Weeks 1-2)
  * Memory models, pointer mechanics, and the `volatile` keyword.
* **`Chapter 2: Interrupts & Timing Architecture`** (Weeks 3-4)
  * NVIC, timer prescaling, and ISR design.
* **`Chapter 3: Communication Protocols Deep Dive`** (Weeks 5-6)
  * Custom drivers for UART, I2C, and SPI from scratch.
* **`Chapter 4: Memory, DMA, & Low-Power Optimization`** (Weeks 7-8)
  * CPU offloading and sleep/standby mode profiling.
* **`Chapter 5: RTOS Integration`** (Weeks 9-11)
  * FreeRTOS task scheduling, mutexes, semaphores, and queues.
* **`Chapter 6: ARM Cortex-M Architecture`** (Weeks 12-13)
  * Pipeline mechanics, bus matrix, and performance profiling using DWT/ITM.
* **`Chapter 7: System Integration Capstone`** (Weeks 14-16)
  * Complete Industrial IoT Data Logger combining RTOS, sensors, and storage.
* **`Chapter 8: Hardware Debugging & Bring-Up`** (Weeks 17-18)
  * Signal integrity validation and power sequencing.
* **`Chapter 9: Test Automation Frameworks`** (Weeks 19-24)
  * Python-based test harnesses and silicon characterization procedures.

---

## 🛠️ Key Hands-On Projects

Throughout this roadmap, I am developing 10 major portfolio projects. Highlights include:

* **Timer-Based Multi-Tasking (Bare Metal):** A non-blocking system managing multiple asynchronous events via timer interrupts.
* **Multi-Protocol Sensor Hub:** Interfacing with multiple sensors simultaneously via UART, I2C, and SPI using interrupt-driven, custom-built drivers.
* **Battery-Optimized DMA Data Logger:** Utilizing Direct Memory Access to achieve continuous ADC sampling while maintaining sub-20% CPU utilization in low-power modes.
* **Hardware Fault Injection Lab:** Intentionally inducing and debugging hardware failures (e.g., I2C pull-up removal, interrupt storms) using logic analyzers.
* **Python Automated Test Harness:** A custom CI/CD style framework communicating via serial to validate system boundaries and error recovery.

---

## 🔬 Methodology

Every script and module in this repository is built using a **Datasheet-First Approach**. I do not rely on high-level abstractions (like standard HALs) until the underlying register maps and electrical characteristics are fully understood and manually verified. 

> *"You don't truly understand a peripheral until you've configured its registers using bitwise logic."*
