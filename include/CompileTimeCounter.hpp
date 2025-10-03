#pragma once

#include <cstddef>
#include <tuple>

namespace state_full_counter {

template <std::size_t J, std::size_t I>
struct LoopHoleADL {
  friend auto LoopHole(LoopHoleADL<J, I>);
};

template <std::size_t J, std::size_t I>
struct LoopHoleSet {
  friend auto LoopHole(LoopHoleADL<J, I> /*unused*/) { return 42; }
};

template <std::size_t J, std::size_t I, auto V>
constexpr std::size_t CounterImpl() {
  if constexpr (requires { LoopHole(LoopHoleADL<J, I>{}); }) {
    return CounterImpl<J, I + 1, V>();
  } else {
    (void)LoopHoleSet<J, I>{};
    return I;
  }
}

template <std::size_t CounterNumber = 0,
          auto BypassingCompilerOptimization = [] {}>
constexpr std::size_t Counter() {
  return CounterImpl<CounterNumber, 0, BypassingCompilerOptimization>();
}

};  // namespace state_full_counter