# Systems Programming Notes

A summary/sample of my own extensive notes from the many things I've been learning relating to C and Linux systems programming.  

My goal has been to build a solid foundation in how software actually runs on a Unix system, beyond surface-level frameworks or tooling.

Many of these exercises can be attributed to/ much learning has come from reading the book "System Programming in Linux" by Stewart N. Weiss.  I have also been making extensive use of ChatGPT and other online resources throughout; by continually asking specific questions I have been able to accelerate learning and sharpen my mental models.

## What I’ve been learning

### Memory & Allocation
- Difference between **stack** (automatic, fast, limited) and **heap** (dynamic, manual).
- How to allocate memory with `malloc()` and release it with `free()`.
- Why forgetting to free causes **memory leaks**, and why it matters for long-running software.
- Why setting a pointer to `NULL` after `free()` prevents **use-after-free** bugs.

### Types, Sizes & Architecture
- `size_t` as the correct type for sizes and the return type of `sizeof`.
- Architecture differences (32-bit vs 64-bit), pointer widths, and how to inspect them.
- Understanding how arrays **decay to pointers** and why that matters for safety.

### Processes & Execution
- How Unix creates new processes using `fork()`.
- How a program image is replaced using `exec()`.
- Parent/child process behaviour and control flow.

### System Calls, glibc & the Kernel
- What a system call actually is, and how it crosses user/kernel boundaries.
- How glibc wraps syscalls, validates arguments, and converts return codes into `errno`.
- Why a stable **ABI** allows compiled binaries to keep running for years.

### Standards & Portability
- POSIX as a standard API model for UNIX-like systems.
- Linux not always being POSIX-compliant, and glibc filling in the gaps.
- Feature test macros (`_POSIX_C_SOURCE`, etc.) for enabling specific API contracts.
- Practical trade-offs between static buffers and runtime sizing.

### Filesystem & Tooling
- High-level layout of Linux directories: `/bin`, `/usr`, `/lib`, `/etc`, `/home`, `/tmp`.
- The idea of **shareability** and **variability** in filesystem design.
- Using man pages effectively (`man 2`, `man 3`, `man 7`, `man -k`).
- Navigating headers and source to understand behaviour.

## Why I’m learning this

To understand how software really works at the system level:
- memory safety,
- processes,
- syscalls,
- performance,
- standards,
- and portability.

This knowledge translates directly into better:
- debugging skills,
- architectural decisions,
- performance intuition,
- and the ability to understand and build things that aren’t just glued together with frameworks.

## What’s next

I want to keep going deeper into:
- Linux APIs, file I/O and sockets
- concurrency and synchronisation
- performance profiling
- systems-level tools and services

Ultimately building real projects that demonstrate practical systems engineering ability.

---

These notes will evolve as I learn more.  
The aim is practical understanding, not just academic theory.  I can't believe how much fun I'm having!
