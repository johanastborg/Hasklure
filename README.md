# Optimized Bit Utilities

A high-performance C++98 library and application for bit manipulation operations, leveraging compiler intrinsics for maximum efficiency.

## Overview

This project provides a collection of optimized bit manipulation utilities designed for C++98 environments. It focuses on performance by utilizing compiler-specific intrinsics (like `__builtin_popcount` and `__builtin_bswap`) and forcing inline expansion for critical paths. It is suitable for low-level systems programming, embedded systems, or performance-critical applications where bit-level control is required.

## Features

-   **High Performance:** Uses GCC/Clang built-in intrinsics for operations like population count and byte swapping.
-   **C++98 Compatible:** adhering to strict C++98 standards (`-std=c++98`) with support for fixed-width integers.
-   **Type Safety:** Includes a `types.hpp` header defining fixed-width integer types (`u8`, `u16`, `u32`, `u64`, etc.).
-   **Zero Overhead:** Key functions are marked with `__attribute__((always_inline))` to ensure no function call overhead.
-   **Utilities:**
    -   `set_bit`, `clear_bit`, `toggle_bit`, `check_bit`
    -   `popcount` (Population Count / Hamming Weight)
    -   `bswap` (Byte Swap for Endianness conversion)
    -   `is_power_of_two`

## Directory Structure

```
.
├── include/        # Header files
│   ├── BitUtils.hpp # Main utility implementation (Header-only)
│   └── types.hpp    # Fixed-width integer type definitions
├── src/            # Source files
│   └── main.cpp     # Example application
├── tests/          # Unit tests
│   └── test_bits.cpp # Tests for bit utilities
├── bin/            # Output executables (created during build)
├── build/          # Intermediate object files (created during build)
├── Makefile        # Build configuration
└── LICENSE         # Project license
```

## Prerequisites

-   **Compiler:** A C++ compiler supporting C++98 and GCC-style intrinsics (e.g., GCC, Clang).
-   **Make:** GNU Make or compatible build tool.

## Build Instructions

To build the main application:

```bash
make
```

This will create the executable at `bin/optimized_app`.

To clean the build artifacts:

```bash
make clean
```

## Running the Application

After building, you can run the example application:

```bash
./bin/optimized_app
```

**Output:**
```
Optimized C++98 Project Structure
Initial data: 0
After setting bits 0, 5, 10: 1057
Bit 5 is set: Yes
Bit 6 is set: No
Population count: 3
Byte swapped: 554303488
```

## Running Tests

To build and run the unit tests:

```bash
make test
```

This will compile the tests and execute `bin/run_tests`. If all tests pass, you will see:

```
test_set_bit passed.
test_clear_bit passed.
test_toggle_bit passed.
test_popcount passed.
test_is_power_of_two passed.
All tests passed!
```

## Usage

Include the header in your project:

```cpp
#include "BitUtils.hpp"
#include "types.hpp"

using namespace Optimized;

void example() {
    u32 value = 0;

    // Set the 3rd bit
    set_bit(value, 3);

    // Check if the 3rd bit is set
    if (check_bit(value, 3)) {
        // ...
    }

    // Count set bits
    int set_bits = popcount(value);
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
