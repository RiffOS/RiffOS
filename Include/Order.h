/**
 * @file Order.h
 * @author Krisna Pranav
 * @brief order
 * @version 1.0
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <LibMeta/Traits.h>
#include "Macros.h"
#include "RiffStd.h"

namespace Include 
{

    struct Order 
    {
        enum Value : i8 
        {
            LESS = -128,
            EQUAL = 0,
            GREATER = 127,
        };

        Value _value;

        /**
         * @param cmp 
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr static Order from(isize cmp) 
        {
            return cmp < 0 ? LESS : cmp > 0 ? GREATER : EQUAL;
        }

        /**
         * @param value 
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr Order(Value value) : _value(value) {}

        /**
         * @param other 
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr Order operator|(Order const &other) const 
        {
            if (_value != EQUAL) 
            {
                return _value;
            }

            return other;
        }

        /**
         * @param other 
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool operator==(Order const &other) const = default;

        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isEq() const 
        { 
            return _value == EQUAL; 
        }
        
        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isNe() const 
        { 
            return _value != EQUAL; 
        }

        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isLt() const 
        { 
            return _value == LESS; 
        }

        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isGt() const 
        { 
            return _value == GREATER; 
        }

        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isLtEq() const 
        { 
            return _value != GREATER; 
        }

        /**
         * @return ALWAYS_INLINE constexpr 
         */
        ALWAYS_INLINE constexpr bool isGtEq() const 
        { 
            return _value != LESS; 
        }
    };

    /**
     * @tparam Lhs 
     * @tparam Rhs 
     */
    template <typename Lhs, typename Rhs = Lhs>
    concept Comparable = requires(Lhs const &lhs, Rhs const &rhs) 
    {
        { lhs.cmp(rhs) } -> LibMeta::Same<Order>;
    };

    /**
     * @tparam Lhs 
     * @tparam Rhs 
     */
    template <typename Lhs, typename Rhs = Lhs>
    concept ComparaisonOperator = requires(Lhs const &lhs, Rhs const &rhs) 
    {
        { lhs < rhs } -> LibMeta::Same<bool>;
        { lhs > rhs } -> LibMeta::Same<bool>;
        { lhs == rhs } -> LibMeta::Same<bool>;
    };
    
    /**
     * @tparam T 
     * @tparam U 
     * @param lhs 
     * @param rhs 
     * @return requires constexpr 
     */
    template <typename T, typename U>
        requires Comparable<T, U>
    ALWAYS_INLINE constexpr Order cmp(T const &lhs, U const &rhs) 
    {
        return lhs.cmp(rhs);
    }

    /**
     * @tparam Lhs 
     * @tparam Rhs 
     */
    template <typename Lhs, typename Rhs>
        requires(ComparaisonOperator<Lhs, Rhs>)
    ALWAYS_INLINE constexpr Order cmp(Lhs const &lhs, Rhs const &rhs) 
    {
        if (lhs < rhs) {
            return Order::LESS;
        } else if (lhs > rhs) {
            return Order::GREATER;
        } else {
            return Order::EQUAL;
        }
    }

    /**
     * @tparam T 
     * @param lhs 
     * @param lhs_len 
     * @param rhs 
     * @param rhs_len 
     * @return ALWAYS_INLINE 
     */
    template <typename T>
    ALWAYS_INLINE Order cmp(T const *lhs, usize lhs_len, T const *rhs, usize rhs_len) 
    {
        usize len = lhs_len < rhs_len ? lhs_len : rhs_len;

        for (usize i = 0; i < len; i++) {
            Order c = cmp(lhs[i], rhs[i]);
            if (c != Order::EQUAL) {
                return c;
            }
        }

        if (lhs_len < rhs_len) {
            return Order::LESS;
        } else if (lhs_len > rhs_len) {
            return Order::GREATER;
        } else {
            return Order::EQUAL;
        }
    }

    namespace OrderP 
    {

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool eq(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isEq();
        }

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool ne(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isNe();
        }

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool lt(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isLt();
        }

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool gt(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isGt();
        }

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool gteq(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isGtEq();
        }

        /**
         * @tparam Lhs 
         * @tparam Rhs 
         * @param lhs 
         * @param rhs 
         * @return ALWAYS_INLINE constexpr 
         */
        template <typename Lhs, typename Rhs>
        ALWAYS_INLINE constexpr bool lteq(Lhs const &lhs, Rhs const &rhs) 
        {
            return cmp(lhs, rhs).isLtEq();
        }

    } 

} 