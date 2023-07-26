/**
 * @file noncopy.h
 * @author Krisna Pranav
 * @brief NonCopyable
 * @version 1.0
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

namespace RiffMeta
{
    /// @brief NonCopyable
    struct NonCopy
    {
        NonCopy() = default;
        NonCopy(NonCopy const &) = delete;
        NonCopy &operator=(NonCopy const&) = delete;
    };

    /// @brief Static Functionalities
    struct Static
    {
        Static() = default;
        Static(Static &&) = delete;
        Static &operator=(Static &&) = delete
    };
};