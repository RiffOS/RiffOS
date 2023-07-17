/**
 * @file Macros.h
 * @author Krisna Pranav
 * @brief MACROS!!
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

namespace Include 
{

    #define goto _Pragma("GCC error \"goto is not allowed\"") goto

    #define arrayLen$(ARR) (sizeof(ARR) / sizeof(ARR[0]))

    #define __concat$(LHS, RHS) LHS##RHS

    #define concat$(LHS, RHS) __concat$(LHS, RHS)

    #define __stringify$(SYM) #SYM

    #define stringify$(SYM) __stringify$(SYM)

    #define var$(NAME) concat$(_MACRO_VAR_##NAME##__, __LINE__)

    #define ALWAYS_INLINE [[gnu::always_inline]]

    /**
     * @tparam T 
     * @tparam U 
     */
    template <typename T, typename U>
    ALWAYS_INLINE static inline T unionCast(U value)
        requires(sizeof(T) == sizeof(U))
    {
        union X 
        {
            U u;
            T t;
        };

        return X{.u = value}.t;
    }
}