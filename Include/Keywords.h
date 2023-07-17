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
    /// @brief Move
    struct Move {};
    /// @brief Re-Assigne
    constexpr inline auto MOVE = Move{};

    /// @brief COPY
    struct Copy {};
    /// @brief Re-Assign
    constexpr inline auto COPY = Copy{};

    /// @brief WRAP[Take Copy Of Move]
    struct Wrap {};
    /// @brief Re-Assign
    constexpr inline auto WRAP = Wrap{};

    /// @brief  None[Empty-Object]
    struct None {
        constexpr None() {}

        /**
         * @return true 
         * @return false 
         */
        explicit operator bool() const 
        {
            return false;
        }
    };

    /// @brief NONE[Re-Assigne]
    constexpr inline auto NONE = None{};

    /**
     * @tparam T 
     * @param ptr 
     * @return true 
     * @return false 
     */
    template <typename T>
    bool operator==(None, T *ptr) 
    {
        return ptr == nullptr;
    }

}