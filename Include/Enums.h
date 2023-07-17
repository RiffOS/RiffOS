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

        Flags(E value)
            : _value(value) {}

        bool has(E value) const {
            return (_value & value) == value;
        }

        void set(E value) {
            _value |= value;
        }

        void unset(E value) {
            _value &= ~value;
        }

        void toggle(E value) {
            _value ^= value;
        }

        void clear() {
            _value = {};
        }

        bool empty() const {
            return _value == (E)0;
        }

        E val() const {
            return _value;
        }

        operator E() const {
            return _value;
        }

        operator bool() const {
            return _value != (E)0;
        }

        Flags operator~() const {
            return Flags(~_value);
        }

        Flags operator|(Flags other) const {
            return Flags(_value | other._value);
        }

        Flags operator&(Flags other) const {
            return Flags(_value & other._value);
        }

        Flags operator^(Flags other) const {
            return Flags(_value ^ other._value);
        }

        Flags &operator|=(Flags other) {
            _value |= other._value;
            return *this;
        }

        Flags &operator&=(Flags other) {
            _value &= other._value;
            return *this;
        }

        Flags &operator^=(Flags other) {
            _value ^= other._value;
            return *this;
        }

        bool operator!() const {
            return !_value;
        }

        bool operator==(Flags other) const {
            return _value == other._value;
        }

        bool operator!=(Flags other) const {
            return _value != other._value;
        }

        bool operator<(Flags other) const {
            return _value < other._value;
        }

        bool operator>(Flags other) const {
            return _value > other._value;
        }

        bool operator<=(Flags other) const {
            return _value <= other._value;
        }

        bool operator>=(Flags other) const {
            return _value >= other._value;
        }
    };

    #define FlagsEnum$(T)                              \
        inline T operator~(T a) {                      \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T) ~(U)a;                          \
        }                                              \
        inline T operator|(T a, T b) {                 \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T)((U)a | (U)b);                   \
        }                                              \
        inline T operator&(T a, T b) {                 \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T)((U)a & (U)b);                   \
        }                                              \
        inline T operator^(T a, T b) {                 \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T)((U)a ^ (U)b);                   \
        }                                              \
        inline bool operator!(T a) {                   \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return not(U) a;                           \
        }                                              \
        inline T &operator|=(T &a, T b) {              \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T &)((U &)a |= (U)b);              \
        }                                              \
        inline T &operator&=(T &a, T b) {              \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T &)((U &)a &= (U)b);              \
        }                                              \
        inline T &operator^=(T &a, T b) {              \
            using U = ::Karm::Meta::UnderlyingType<T>; \
            return (T &)((U &)a ^= (U)b);              \
        }

    template <Meta::Enum E, typename U = Meta::UnderlyingType<E>>
    U toUnderlyingType(E value) {
        return (U)value;
    };

}