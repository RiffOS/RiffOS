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

namespace RiffMeta 
{

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Const = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Const<T const> = true;

    /**
     * @tparam T 
     */
    template <typename T>
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
    using CopyConst = Condition<Const<Src>, Dest const, RemoveConst<Dest>>;

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
    template <typename T>
    struct _RemoveVolatile 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveVolatile<T volatile> 
    {
        using Type = T;
    };
    
    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveVolatile = typename _RemoveVolatile<T>::Type;

    /**
     * @tparam Src 
     * @tparam Dest 
     */
    template <typename Src, typename Dest>
    using CopyVolatile = Condition<Volatile<Src>, Dest volatile, RemoveVolatile<Dest>>;

    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveConstVolatile = RemoveConst<RemoveVolatile<T>>;

    /**
     * @tparam ypename 
     */
    template <typename>
    inline constexpr bool _LvalueRef = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _LvalueRef<T &> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept LvalueRef = _LvalueRef<T>;

    /**
     * @tparam ypename 
     */
    template <typename>
    inline constexpr bool _RvalueRef = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _RvalueRef<T &&> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept RvalueRef = _RvalueRef<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Ref = LvalueRef<T> or RvalueRef<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveRef 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveRef<T &> 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemoveRef<T &&> 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveRef = typename _RemoveRef<T>::Type;

    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveConstVolatileRef = RemoveConstVolatile<RemoveRef<T>>;

    /** 
     * @tparam ypename 
     */
    template <typename>
    inline constexpr bool _Ptr = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Ptr<T *> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Ptr = _Ptr<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemovePtr 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    struct _RemovePtr<T *> 
    {
        using Type = T;
    };

    /**
     * @tparam T 
     */
    template <typename T>
    using RemovePtr = typename _RemovePtr<RemoveConstVolatile<T>>::Type;

} 