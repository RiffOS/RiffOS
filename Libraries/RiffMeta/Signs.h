/**
 * @file Signs.h
 * @author Krisna Pranav
 * @brief Signs
 * @version 1.0
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

namespace RiffMeta
{
    /**
     * @tparam T 
     */
    template<typename T>
    struct _MakeSigned 
    {
        using Type = void;
    };

    template<>
    struct _MakeSigned<char>
    {
        using Type = signed char;
    };

    template<>
    struct _MakeSigned<unsigned char>
    {
        using Type = signed char;
    };

    template<>
    struct _MakeSigned<short>
    {
        using Type = short;
    };

    template<>
    struct _MakeSigned<int>
    {
        using Type = int;
    };

    template<>
    struct _MakeSigned<unsigned int>
    {
        using Type = int;
    };

    template<>
    struct _MakeSigned<long>
    {
        using Type = long;
    };

    template<>
    struct _MakeSigned<unsigned long>
    {
        using Type = long;
    };
}