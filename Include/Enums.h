/**
 * @file Enums.h
 * @author Krisna Pranav
 * @brief Custom Enumeration Functionalities
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <LibMeta/Traits.h>
#include "RiffStd.h"

namespace Include {

    template <LibMeta::Enum E>
    struct Flags {
        E _value = {};

        Flags() = default;

        /**
         * @brief Construct a new Flags object
         * 
         * @param value 
         */
        Flags(E value) : _value(value) {}

        /**
         * @param value 
         * @return true 
         * @return false 
         */
        bool has(E value) const 
        {
            return (_value & value) == value;
        }

        /**
         * @param value 
         */
        void set(E value) 
        {
            _value |= value;
        }

        /**
         * @param value 
         */
        void unset(E value) 
        {
            _value &= ~value;
        }

        /**
         * @param value 
         */
        void toggle(E value) 
        {
            _value ^= value;
        }

        /**
         * @brief *void clear
         * 
         */
        void clear() 
        {
            _value = {};
        }

        /**
         * @brief empty
         * 
         * @return true 
         * @return false 
         */
        bool empty() const 
        {
            return _value == (E)0;
        }

        /**
         * @return E 
         */
        E val() const 
        {
            return _value;
        }

        /**
         * @return E 
         */
        operator E() const 
        {
            return _value;
        }

        /**
         * @return true 
         * @return false 
         */
        operator bool() const 
        {
            return _value != (E)0;
        }

        /**
         * @return Flags 
         */
        Flags operator~() const 
        {
            return Flags(~_value);
        }

        /**
         * @param other 
         * @return Flags 
         */
        Flags operator|(Flags other) const 
        {
            return Flags(_value | other._value);
        }

        /**
         * @param other 
         * @return Flags 
         */
        Flags operator&(Flags other) const 
        {
            return Flags(_value & other._value);
        }

        /**
         * @param other 
         * @return Flags 
         */
        Flags operator^(Flags other) const 
        {
            return Flags(_value ^ other._value);
        }
        
        /**
         * @param other 
         * @return Flags& 
         */
        Flags &operator|=(Flags other) 
        {
            _value |= other._value;
            return *this;
        }

        /**
         * @param other 
         * @return Flags& 
         */
        Flags &operator&=(Flags other) 
        {
            _value &= other._value;
            return *this;
        }

        /**
         * @param other 
         * @return Flags& 
         */
        Flags &operator^=(Flags other) 
        {
            _value ^= other._value;
            return *this;
        }

        /**
         * @return true 
         * @return false 
         */
        bool operator!() const 
        {
            return !_value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator==(Flags other) const 
        {
            return _value == other._value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator!=(Flags other) const 
        {
            return _value != other._value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator<(Flags other) const 
        {
            return _value < other._value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator>(Flags other) const 
        {
            return _value > other._value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator<=(Flags other) const 
        {
            return _value <= other._value;
        }

        /**
         * @param other 
         * @return true 
         * @return false 
         */
        bool operator>=(Flags other) const 
        {
            return _value >= other._value;
        }
    };

    #define FlagsEnum$(T)                              \
        inline T operator~(T a)                     \
        {                                           \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T) ~(U)a;                          \
        }                                              \
        inline T operator|(T a, T b)                    \
        {                                                \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T)((U)a | (U)b);                   \
        }                                              \
        inline T operator&(T a, T b)                \
        {                                            \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T)((U)a & (U)b);                   \
        }                                              \
        inline T operator^(T a, T b)                    \
        {                                              \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T)((U)a ^ (U)b);                   \
        }                                              \
        inline bool operator!(T a)                  \
        {                                            \
            using U = ::LibMeta::UnderlyingType<T>; \
            return not(U) a;                           \
        }                                              \
        inline T &operator|=(T &a, T b)                 \
        {                                              \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T &)((U &)a |= (U)b);              \
        }                                              \
        inline T &operator&=(T &a, T b)                 \
        {                                               \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T &)((U &)a &= (U)b);              \
        }                                              \
        inline T &operator^=(T &a, T b)             \
        {                                           \
            using U = ::LibMeta::UnderlyingType<T>; \
            return (T &)((U &)a ^= (U)b);              \
        }

    /**
     * @tparam E 
     * @tparam U 
     * @param value 
     * @return U 
     */
    template <LibMeta::Enum E, typename U = LibMeta::UnderlyingType<E>>
    U toUnderlyingType(E value) 
    {
        return (U)value;
    };

}