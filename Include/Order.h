/**
 * @file Order.h
 * @author Krisna Pranav
 * @brief order
 * @version 1.0
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <LibMeta/Traits.h>
#include "Macros.h"
#include "RiffStd.h"

namespace Include 
{
    struct Order
    {
        enum Value: i8
        {
            LESS = -128,
            EQUAL = 0,
            GREATER = 127,
        };

        Value _value;

        ALWAYS_INLINE constexpr static Order from(isize cmp)
        {
            return cmp < 0 ? LESS : cmp > 0 ? GREATER : EQUAL;
        }

        ALWAYS_INLINE constexpr Order(Value value) : _value(value) {}

        ALWAYS_INLINE constexpr Order operator|(Order const &other) const
        {
            if (_value != EQUAL)
            {
                return _value
            }

            return other;
        }

        ALWAYS_INLINE constexpr bool operator==(Order const &other) const = default;

        ALWAYS_INLINE constexpr bool isEq() const 
        {
            return _value == EQUAL;
        };

        ALWAYS_INLINE constexpr bool isNe() const
        {
            return _value != EQUAL;
        }

        ALWAYS_INLINE constexpr bool isLt() const
        {
            return _value == LESS;
        }

        ALWAYS_INLINE constexpr bool isGt() const
        {
            return _value == GREATER;
        }

        ALWAYS_INLINE constexpr bool isLtEq() const
        {
            return _value != GREATER;
        }

        ALWAYS_INLINE constexpr isGetEq() const
        {
            return _value != LESS;
        }

    };

    template <typename T, typename U>
        requires Comparable<T, U>
    ALWAYS_INLINE constexpr Order cmp(T const &lhs, U const &rhs)
    {
        return lhs.cmp(rhs);
    }
}