#ifndef OPTIMIZED_BIT_UTILS_HPP
#define OPTIMIZED_BIT_UTILS_HPP

#include "types.hpp"

namespace Optimized {

    // Force inline for critical paths.
    // Note: 'inline' is a hint, 'always_inline' attribute forces it in GCC/Clang.
    #define FORCE_INLINE __attribute__((always_inline)) inline

    template <typename T>
    FORCE_INLINE void set_bit(T& value, u8 bit) {
        value |= (static_cast<T>(1) << bit);
    }

    template <typename T>
    FORCE_INLINE void clear_bit(T& value, u8 bit) {
        value &= ~(static_cast<T>(1) << bit);
    }

    template <typename T>
    FORCE_INLINE void toggle_bit(T& value, u8 bit) {
        value ^= (static_cast<T>(1) << bit);
    }

    template <typename T>
    FORCE_INLINE bool check_bit(const T& value, u8 bit) {
        return (value & (static_cast<T>(1) << bit)) != 0;
    }

    // Fast population count using compiler intrinsic
    FORCE_INLINE int popcount(u32 value) {
        return __builtin_popcount(value);
    }

    FORCE_INLINE int popcount(u64 value) {
        return __builtin_popcountll(value);
    }

    // Byte swap for endianness
    FORCE_INLINE u32 bswap(u32 value) {
        return __builtin_bswap32(value);
    }

    FORCE_INLINE u64 bswap(u64 value) {
        return __builtin_bswap64(value);
    }

    // Check if power of 2
    template <typename T>
    FORCE_INLINE bool is_power_of_two(T value) {
        return value && !(value & (value - 1));
    }
}

#endif // OPTIMIZED_BIT_UTILS_HPP
