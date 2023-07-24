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
    
    /**
     * @tparam T 
     * @return Id 
     */
    template <typename T>
    static Id idOf() 
    {
        return reinterpret_cast<Id>(__PRETTY_FUNCTION__ + 41);
    }

    /**
     * @tparam T 
     * @return char const* 
     */
    template <typename T>
    static char const *nameOf() 
    {
        return __PRETTY_FUNCTION__ + 40;
    }
    
    /**
     * @tparam __noType 
     */
    template <typename T = struct __noType>
    struct Type;

    /**
     * @tparam T 
     */
    template <typename T>
    struct Type 
    {
        using TYPE = T;

        /**
         * @return constexpr Id 
         */
        constexpr static Id id() 
        {
            return idOf<T>();
        }

        /**
         * @return constexpr char const* 
         */
        constexpr static char const *name() 
        {
            return nameOf<T>();
        }
    };

    /**
     * @tparam 
     */
    template <>
    struct Type<struct __noType> 
    {
        Id _id;
        char const *_name;

        /**
         * @tparam T 
         */
        template <typename T>
        constexpr Type(Type<T> type)
            : _id(type.id()), _name(type.name()) {}

        /**
         * @return constexpr Id 
         */
        constexpr Id id() const 
        {
            return _id;
        }

        /**
         * @return constexpr char const* 
         */
        constexpr char const *name() const 
        {
            return _name;
        }
    };

    /**
     * @tparam T 
     * @return Type<T> 
     */
    template <typename T>
    Type<T> typeOf() 
    {
        return Type<T>{};
    }

}