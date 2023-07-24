/**
 * @file Conditions.h
 * @author Krisna Pranav
 * @brief conditions
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

namespace RiffMeta
{
    template<bool condition, typename TTrue, typename TFalse>
    struct _Condition
    {
        using Type = TTrue;
    };

    template<typename TTrue, typename TFalse>
    struct _Condition<false, TTrue, TFalse>
    {
        using Type = TFalse;
    };

    template <bool condition, typename TTrue, typename TFalse>
    using Condition = typename _Condition<condition, TTrue, TFalse>::Type;

}