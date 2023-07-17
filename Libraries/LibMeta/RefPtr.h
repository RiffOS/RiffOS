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

    /// Mark :- Constants

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _CONST = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _CONST<T const> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Const = _CONST<T>;

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
    using CopyConst = Condition<Const<Src>, Dest const, RemoveConst<Dest> >;

    /// MARK :- Volatile

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
    struct _RemoveVolatile<T volatile> {
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
    using CopyVolatile = Condition<Volatile<Src>, Dest volatile, RemoveVolatile<Dest> >;

    /**
     * @tparam T 
     */
    template <typename T>
    using RemoveConstVolatile = RemoveConst<RemoveVolatile<T> >;


    /// MARK :- Ref

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

    template <typename T>
    using RemoveConstVolatileRef = RemoveConstVolatile<RemoveRef<T> >;

    /// MARK :- Pointers

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

    template <typename T>
    struct _RemovePtr<T *> 
    {
        using Type = T;
    };

    template <typename T>
    using RemovePtr = typename _RemovePtr<RemoveConstVolatile<T> >::Type;

} 