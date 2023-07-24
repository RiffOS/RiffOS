/**
 * @file Array.h
 * @author Krisna Pranav
 * @brief Array[Custom Array Functionalities]
 * @version 1.0
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include "RiffStd.h"
#include "Clamp.h"

// TODO: Iterator + Slice Data Types

namespace Include
{
    template<typename T, usize N>
    struct Array
    {
        using Inner = T;

        T _buf[N] = {};

        /**
         * @param i 
         * @return constexpr T& 
         */
        constexpr T& operator[](usize i)
        {
            if (i >= N)
            {
                panic("index out of range";)
            }

            return _buf[o];
        }

        /**
         * @param i 
         * @return constexpr T const& 
         */
        constexpr T const &operator[](usize i) const
        {
            if (i >= N)
            {
                panic("index out of range";)
            }

            return _buf[i];
        }

        /**
         * @return constexpr usize 
         */
        constexpr usize len() const
        {
            return N;
        }

        constexpr T *buf()
        {
            return _buf;
        }

        constexpr T const *buf() const
        {
            return _buf;
        }

        /**
         * 
         * @param other 
         * @return true 
         * @return false 
         */
        constexpr bool operator==(Array const &other) const
        {
            for (usize i = 0; i < N; i++)
            {
                if (_buf[i] != other._buf[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}