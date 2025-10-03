#include "CompileTimeCounter.hpp"

static_assert(state_full_counter::Counter() == 0);
static_assert(state_full_counter::Counter() == 1);
static_assert(state_full_counter::Counter() == 2);
static_assert(state_full_counter::Counter() == 3);

static_assert(state_full_counter::Counter<1>() == 0);
static_assert(state_full_counter::Counter<1>() == 1);
static_assert(state_full_counter::Counter<1>() == 2);
static_assert(state_full_counter::Counter<1>() == 3);
