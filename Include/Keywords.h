/**
 * @file Keywords.h
 * @author Krisna Pranav
 * @brief KeyWords[Move, Copy, Wrap]
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

#include <Include/Bool.h>

namespace Include
{
    struct Move {};

    constexpr inline auto MOVE = Move{};

    struct Copy {};
    
    constexpr inline auto COPY = Copy{};

    struct Wrap {};

    constexpr inline auto WRAP = Wrap{};

    struct None {};

    constexpr inline auto NONE = None{};

    /**
     * @tparam T 
     * @param ptr 
     * @return true 
     * @return false 
     */
    template<typename T>
    bool operator==(None, T *ptr) 
    {
        return ptr == nullptr;
    }
}