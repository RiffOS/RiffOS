/**
 * @file Bool.h
 * @author Krisna Pranav
 * @brief Customized Bool Function For Riff
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <RiffMeta/Traits.h>

namespace Include 
{

    struct Bool;

    struct Bool 
    {
        bool _val;

        /**
         * @brief Construct a new Bool object
         * 
         */
        Bool() = delete;

        constexpr Bool(RiffMeta::Boolean auto value) : _val(value) {}

        /**
         * @param value 
         * @return constexpr Bool& 
         */
        constexpr Bool &operator=(RiffMeta::Boolean auto value) 
        {
            _val = value;
            return *this;
        }

        /**
         * @return true 
         * @return false 
         */
        explicit constexpr operator bool() const 
        {
            return _val;
        }

        /**
         * @return constexpr Bool 
         */
        constexpr Bool operator!() const 
        {
            return Bool(not _val);
        }
    };

    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator==(Bool a, Bool b) 
    {
        return static_cast<bool>(a) == static_cast<bool>(b);
    }

    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator==(Bool a, RiffMeta::Boolean auto b) 
    {
        return static_cast<bool>(a) == static_cast<bool>(b);
    }
    
    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator==(RiffMeta::Boolean auto a, Bool &b) 
    {
        return static_cast<bool>(a) == static_cast<bool>(b);
    }

    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator!=(Bool a, Bool b) 
    {
        return static_cast<bool>(a) != static_cast<bool>(b);
    }

    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator!=(Bool a, RiffMeta::Boolean auto b) 
    {
        return static_cast<bool>(a) != static_cast<bool>(b);
    }

    /**
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    constexpr bool operator!=(RiffMeta::Boolean auto a, Bool b) 
    {
        return static_cast<bool>(a) != static_cast<bool>(b);
    }

}