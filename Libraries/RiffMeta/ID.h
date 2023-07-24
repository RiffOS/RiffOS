/**
 * @file ID.h
 * @author Krisna Pranav
 * @brief ID[Meta]
 * @version 1.0
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

#include <Include/Panic.h>
#include <Include/RiffStd.h>
#include "Traits.h"

namespace RiffMeta
{
    using Id = usize;

    template <typename T>
    static Id idOf()
    {
        return reinterpret_cast<Id>(__PRETTY_FUNCTION__ + 41);
    };

    template <typename T>
    static char const *nameOf()
    {
        return __PRETTY_FUNCTION__ + 40;
    }

    template <typename T = struct __noType>
    struct Type;

    template <typename T>
    struct Type
    {
        using TYPE = T;

        constexpr static Id id() 
        {
            return idOf<T>();
        }

        constexpr static char const *name() 
        {
            return nameOf<T>();
        }
    };

    template<>
    struct Type<struct __noType>
    {
        Id _id;
        char const *_name;

        constexpr Id id() const
        {
            return _id;
        }

        constexpr char const *name() const
        {
            return _name;
        }
    };

    template <typename T>
    Type<T> typeOf()
    {
        return Type<T>{};
    }
}