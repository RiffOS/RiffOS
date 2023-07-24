/**
 * @file CVRP.h
 * @author Krisna Pranav
 * @brief CVRP
 * @version 1.0
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

#include "Conditions.h"
#include "RefPtr.h"

namespace RiffMeta
{

    /**
     * @tparam T 
     */
    template<typename T>
    inline constexpr bool _Const = false;

    /**
     * @tparam T 
     */
    template<typename T>
    inline constexpr bool _Const<T const> = true;

    /**
     * @tparam T 
     */
    template<typename T>
    concept Const = _Const<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveConst
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveConst<T const>
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveConst = typename _RemoveConst<T>::Type;

    /**
     * @tparam Src 
     * @tparam Dest 
     */
    template <typename Src, typename Dest>
    using Copyconst = Cond<Const<Src>, Dest const, RemoveConst<Dest>>;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Volatile = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Volatile<T volatile> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Volatile = _Volatile<T>;

    /**
     * @tparam T 
     */
    template<typename T>
    struct _RemoveVolatile 
    {
        using Type = T;
    };
}