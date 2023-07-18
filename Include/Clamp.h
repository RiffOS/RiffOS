/**
 * @file Clamp.h
 * @author Krisna Pranav
 * @brief CLAMP
 * @version 1.0
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include "RiffStd.h"
#include "Order.h"
#include "Macros.h"

namespace Include
{

    /**
     * @param value 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto max(auto value) 
    { 
        return value; 
    }

    /**
     * @param first 
     * @param rest 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto max(auto first, auto... rest) 
    {
        auto rhs = max(rest...);
        return Orderp::gt(first, rhs) ? first : rhs;
    }

    /**
     * @param value 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto min(auto value) 
    { 
        return value; 
    }

    /**
     * @param first 
     * @param rest 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto min(auto first, auto... rest) 
    {
        auto rhs = min(rest...);
        return Orderp::lt(first, rhs) ? first : rhs;
    }

    /**
     * @param value 
     * @param min 
     * @param max 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto clamp(auto value, auto min, auto max) 
    {
        return Orderp::lt(value, min) ? min : Orderp::gt(value, max) ? max : value;
    }

    /**
     * @param value 
     * @return ALWAYS_INLINE constexpr 
     */
    ALWAYS_INLINE constexpr auto clamp01(auto value) 
    {
        return clamp(value, 0, 1);
    }

} 