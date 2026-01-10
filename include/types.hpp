#ifndef OPTIMIZED_TYPES_HPP
#define OPTIMIZED_TYPES_HPP

#include <stdint.h>

namespace Optimized {

    typedef int8_t   i8;
    typedef uint8_t  u8;
    typedef int16_t  i16;
    typedef uint16_t u16;
    typedef int32_t  i32;
    typedef uint32_t u32;
    typedef int64_t  i64;
    typedef uint64_t u64;

    // Union for fast type punning (strict aliasing safe if used via memcpy or char*)
    // But in C++98, unions are often used for this.
    // We will stick to basic types here.

}

#endif // OPTIMIZED_TYPES_HPP
