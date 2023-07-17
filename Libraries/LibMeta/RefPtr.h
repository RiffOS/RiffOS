/**
 * @file RefPtr.h
 * @author Krisna Pranav
 * @brief RefPtr
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */


#pragma once

#include "Conditions.h"

namespace LibMeta
{
    template <typename T>
    inline constexpr bool _Const = false;

    template <typename T>
    inline constexpr bool _Const<T const> = true;

    template<typename T>
    concept Const = _Const<T>;

    template<typename t>
    struct _RemoveConst
    {
        using Type = T;
    };

    template <typename T>
    struct _RemoveConst<T const>
    {
        using Type = T;
    };

    template <typename T>
    using RemoveConst = typename _RemoveConst<T>::Type;

    template<typename Src, typename Dest>
    using CopyConst = Condition<Const<Src>, Dest const, RemoveConst<Dest>>;


}
