# Compile-Time Counter
A minimal C++ library for stateful compile-time counting using template metaprogramming techniques.

## Requirements
- C++20 compatible compiler
- CMake 3.16+

## Quick Start
```bash
./runtests.sh
```

## Usage

```cpp
#include "CompileTimeCounter.hpp"

// Main counter
static_assert(state_full_counter::Counter() == 0);
static_assert(state_full_counter::Counter() == 1);
static_assert(state_full_counter::Counter() == 2);

// Independent counter #1  
static_assert(state_full_counter::Counter<1>() == 0);
static_assert(state_full_counter::Counter<1>() == 1);
```
