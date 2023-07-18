/**
 * @file Panic.h
 * @author Krisna Pranav
 * @brief Panic MSGS
 * @version 1.0
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include "Embeded.h"

namespace Include 
{

    /**
     * @param msg 
     */
    inline void debug(char const *msg) 
    {
        Embeded::debug(msg);
    }

    /**
     * @param msg 
     */
    [[noreturn]] inline void panic(char const *msg) 
    {
        Embeded::panic(msg);
    }

    [[noreturn]] inline void notImplemented() 
    {
        panic("NOT IMPLEMENTED BROSKISSS");
    }

    /// @brief unreachable
    [[noreturn]] inline void unreachable() 
    {
        panic("UNRECHABLE!!!!! OUT OF TOWN!!!");
    }

}