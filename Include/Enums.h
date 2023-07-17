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
#include <Include/RiffStd.h>

namespace Include
{
    template<LibMeta::Enum E>
    struct Flags
    {
        E _value = {};

        Flags() = default;

        Flags(E value) : _value(value) {}

        bool has(E value) const
        {
            return (_value & value) == value;
        }

        void set(E value)
        {
            _value |= value;
        }

        void unset(E value)
        {
            _value &= ~value;
        }

        void clear() 
        {
            _value = {};
        }

        bool empty() const
        {
            return _value == (E)0
        }

        E val() const
        {
            return _value;
        }

        operator E() const
        {
            return _value;
        }

        operator bool() const
        {
            return _value != (E)0;
        }

        Flags operator~() const
        {
            return Flags(~_value);
        }

        Flags operator(Flags other) const
        {
            return Flags(_value | other._value);
        }

        Flags &operator&=(Flags other)
        {
            _value &= other._value;
            return *this;
        }
    }
}