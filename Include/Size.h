/**
 * @file Size.h
 * @author Krisna Pranav
 * @brief Size
 * @version 1.0
 * @date 2023-07-17
 *
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 *
 */

#pragma once

#include "RiffStd.h"

namespace Include 
{

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize kib(usize v) 
    { 
        return v * 1024; 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize mib(usize v) 
    { 
        return kib(v * 1024); 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize gib(usize v) 
    { 
        return mib(v * 1024); 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize tib(usize v) 
    { 
        return gib(v * 1024); 
    }

    // MARK :- convertion

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize toKib(usize v) 
    { 
        return v / 1024; 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize toMib(usize v) 
    { 
        return toKib(v) / 1024; 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize toGib(usize v) 
    { 
        return toMib(v) / 1024; 
    }

    /**
     * @param v 
     * @return constexpr usize 
     */
    inline constexpr usize toTib(usize v) 
    { 
        return toGib(v) / 1024; 
    }
} 