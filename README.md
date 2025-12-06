# Systems Programming Overview

This document captures core knowledge about **C programming**, **Unix/Linux**, and how software interacts with the operating system.

## 1. Memory & Allocation

### Stack vs Heap
- **Stack**: automatic, fast, small, freed on scope exit.
- **Heap**: manual, dynamic (`malloc` / `free`), persists until freed.

### Memory Safety
- Always `free()` what you allocate.
- Set pointers to `NULL` after free to avoid **dangling pointers**.
- Leaks matter in long-running programs; OS cleans up on exit.

## 2. Types, Sizes & Pointers

### `size_t`
- Unsigned type representing object sizes.
- Result of `sizeof`.
- Architecture-dependent (32-bit vs 64-bit).

### Pointers
- Store memory addresses.
- Must point to valid memory before use.
- Arrays often **decay** to pointers when passed to functions.

## 3. Processes & Execution

### `fork()` and `exec()`
- `fork()` creates a child; returns different values to parent/child.
- `exec()` replaces the current process image.
- Typical model: **parent spawns, child runs, parent waits**.

## 4. System Calls, libc & Kernel

### System Calls
- Low-level interface between user programs and kernel.

### glibc
- Provides user-friendly wrappers, enforces standards, translates errors.

### Kernel ABI
- Binary contract defining calling conventions, syscall numbers, and data sizes.
- Must stay stable so old binaries continue to run.

## 5. Standards & Portability

### POSIX
- Defines standard APIs for Unix systems.

### Feature Test Macros
- Request specific standards behaviour in headers.
- E.g., `_POSIX_C_SOURCE`.

### Portability Trade-offs
- Static limits are simpler.
- Runtime queries are more correct but verbose.

## 6. Filesystem Basics (Linux/Unix)

- `/bin`, `/sbin`: essential binaries.
- `/usr`: shared binaries, headers, libraries.
- `/lib`: shared libraries.
- `/etc`: configuration.
- `/home`: user data.
- `/tmp`: temporary files.

Organisation is based on **shareability** and **variability**.

## 7. Documentation & Tools

- `man 2`: syscalls.
- `man 3`: library functions.
- `man 7`: concepts & standards.
- `man -k`: search.
- `grep -R`: recursive search.

## 8. What This Enables

- Understanding of how programs execute.
- Ability to diagnose crashes, leaks, and performance issues.
- Skills relevant for backend, systems, networking, security, embedded.

## Summary

You’ve covered key foundations of systems programming:
memory management, pointers, processes, syscalls, libc, standards, ABI, filesystem layout, and portability.

These concepts form the basis of **efficient, reliable, low-level software** on Unix-like systems.
