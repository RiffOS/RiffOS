/**
 * @file Callable.h
 * @author Krisna Pranav
 * @brief Callable
 * @version 1.0
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

#include <Include/RiffStd.h>
#include "CVRP.h"
#include "Declare.h"

namespace RiffMeta
{
    /**
     * @tparam ypename 
     */
    template <typename>
    constexpr bool _Func = false;

    /**
     * @tparam Ret 
     * @tparam Args 
     */
    template <typename Ret, typename... Args>
    constexpr bool _Func<Ret(Args...)> = true;

    /**
     * @tparam Ret 
     * @tparam Args 
     */
    template <typename Ret, typename... Args>
    constexpr bool _Func<Ret(Args..., ...)> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Func = _Func<RemoveConstVolatileRef<T>>;

    /**
     * @tparam T 
     */
    template <typename T>
    concept FuncPtr = Ptr<T> and RiffMeta::Func<RemovePtr<T>>;
}