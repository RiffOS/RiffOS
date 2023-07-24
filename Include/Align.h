/**
 * @file Align.h
 * @author Krisna Pranav
 * @brief Alignment of addresses
 * @version 1.0
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include "RefPtr.h"
#include "RiffStd.h"

namespace Include 
{
    
    /**
     * @param addr 
     * @param align 
     * @return constexpr usize 
     */
    inline constexpr usize alignDown(usize addr, usize align) 
    {
        return addr & ~(align - 1);
    }

    /**
     * @param addr 
     * @param align 
     * @return constexpr usize 
     */
    inline constexpr usize alignUp(usize addr, usize align) {
        return (addr + align - 1) & ~(align - 1);
    }

    /**
     * @param addr 
     * @param align 
     * @return true 
     * @return false 
     */
    inline constexpr bool isAlign(usize addr, usize align) 
    {
        return alignDown(addr, align) == addr;
    }

    /**
     * @param addr 
     * @param align 
     * @return Res<> 
     */
    static inline Res<> ensureAlign(usize addr, usize align) 
    {
        if (not isAlign(addr, align)) 
        {
            return Error::invalidInput("not aligned");
        }

        return Ok();
    }

} 