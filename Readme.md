An exercise in using SDL2 and C++

A plan for C++

This study plan is designed for a senior Embedded C Expert moving into a Lead Architect role using Modern C++ (C++17/20/23) as of 2026. It focuses on high-performance, resource-constrained abstractions while avoiding common C++ "bloat".

Phase 1: The "Better C" Foundation (1-2 Weeks)
----------------------------------------------

Transition by replacing manual C patterns with safer, zero-cost C++ alternatives.

- Strong Typing & Scoping: Replace #define constants with constexpr and static const. Use enum class (scoped enums) to prevent name collisions and enable compiler-enforced type checks.
- References vs. Pointers: Master passing by reference (Type&) to eliminate null-pointer checks while maintaining the performance of pointer-based passing.
- Namespace Management: Organize legacy C codebases using namespaces to resolve naming conflicts without renaming every function.
- Extern "C": Learn to wrap C headers with extern "C" to ensure link-time compatibility between C++ and your existing C drivers.


Phase 2: Resource Management & RAII (2-3 Weeks)
-----------------------------------------------

The core architectural shift from C to C++ is moving from manual init/deinit to Resource Acquisition Is Initialization (RAII).

- Smart Life-cycles: Implement RAII guards for critical sections (interrupt disabling/enabling), hardware clocks, and peripheral locking.
- Zero-Overhead Memory: Learn std::unique_ptr with custom deleters for peripheral management. Crucial: Avoid std::shared_ptr and new/delete in real-time paths to prevent non-deterministic heap behavior.
- Move Semantics: Master std::move to transfer ownership of large buffers or peripheral handles without deep-copying data.

Phase 3: Hardware Abstraction & Templates (3-4 Weeks)
-----------------------------------------------------

Leverage C++ metaprogramming to build generic, reusable drivers that "melt away" at compile time.
- Templates for Drivers: Use class templates to parameterize drivers (e.g., UART<UART1_BASE>). This replaces C-style pointer-to-struct abstraction with compile-time constants, often resulting in faster code.
- Static Polymorphism: Use the CRTP (Curiously Recurring Template Pattern) instead of virtual functions to achieve polymorphism without the overhead of a VTable or indirect jumps.
- C++20 Concepts: Use concepts to define formal constraints on template parameters (e.g., ensuring a driver supports a write() method), replacing messy static_assert or SFINAE logic.


Phase 4: Embedded Modern STL & Safety (Ongoing)
-----------------------------------------------

Modern C++ (2020+) provides safe, fixed-size containers that replace error-prone C arrays.

- Fixed-Capacity Containers: Master std::array and std::span (C++20) for safe bounds-checked access to fixed buffers without dynamic allocation.
- Vocabulary Types: Use std::optional, std::variant, and std::expected (C++23) to replace error codes and tagged unions, making API failures explicit and type-safe.
- The "No-Go" Zone: As an architect, enforce a "subset" of C++. Generally, disable Exceptions (-fno-exceptions) and RTTI (-fno-rtti) to maintain code size and deterministic performance.

Recommended Resources for 2026
------------------------------
Core Reading: Real-Time C++ by Christopher Kormanyos.
Training: Doulos: Modern C++ for Embedded Microcontrollers.
Standards: Reference the MISRA C++ Guidelines and AUTOSAR C++14 for safety-critical architectural rules.
