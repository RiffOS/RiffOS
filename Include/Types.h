/**
 * @file Types.h
 * @author Krisna Pranav
 * @brief Types
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

namespace Include
{
    // Size
    using usize = size_t;
    using isize = ptrdiff_t;

    // UInts
    using u8 = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    // Ints
    using i8 = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;
    using i128 = __int128_t;
}