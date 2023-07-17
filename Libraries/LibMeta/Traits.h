//
//  Traits.h
//  Riff
//
//  Created by krisna pranav on 17/07/23.
//

#pragma once

#include <Libraries/LibMeta/Declare.h>

namespace LibMeta
{
    struct Bool;
}

namespace LibMeta
{

    /**
     * @tparam T 
     */
    template <typename T>
    concept Void = __is_void(T);

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Nullptr = false;

    /**
     * @tparam  
     */
    template <>
    inline constexpr bool _Nullptr<decltype(nullptr)> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Nullptr = _Nullptr<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Boolean = false;

    /**
     * @tparam  
     */
    template <>
    inline constexpr bool _Boolean<bool> = true;

    /**
     * @tparam  
     */
    template <>
    inline constexpr bool _Boolean<LibMeta::Bool> = true;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Boolean = _Boolean<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    concept Float = __is_floating_point(T);

    /**
     * @tparam T 
     */
    template <typename T>
    concept Array = __is_array(T);

    /**
     * @brief Enum
     * 
     * @tparam T 
     */
    template <typename T>
    concept Enum = __is_enum(T);

    /**
     * @tparam T 
     */
    template <typename T>
    concept Union = __is_union(T);

    template <typename T>
    concept Struct = __is_class(T);

    template <typename T>
    concept Integral = __is_integral(T);

    template <typename T>
    concept Trivial = __is_trivial(T);

    template <typename T>
    concept Signed = __is_signed(T);

    /**
     * @tparam T 
     */
    template <typename T>
    concept Unsigned = __is_unsigned(T);

    /**
     * @tparam T 
     */
    template <typename T>
    concept SignedIntegral = Integral<T> and Signed<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    concept UnsignedIntegral = Integral<T> and Unsigned<T>;

    /**
     * @tparam T 
     */
    template <typename T>
    using UnderlyingType = __underlying_type(T);

    /**
     * @tparam Derived 
     * @tparam Base 
     */
    template <typename Derived, typename Base>
    concept Derive = __is_base_of(Base, Derived);

    /**
     * @tparam T 
     * @tparam Args 
     */
    template <typename T, typename... Args>
    concept Constructible = requires {
                                ::new T(declval<Args>()...);
                            };

    /**
     * @tparam T 
     */
    template <typename T>
    concept DefaultConstructible = Constructible<T>;

    /**
     * @tparam T 
     * @tparam U 
     */
    template <typename T, typename U = T>
    concept CopyConstructible = Constructible<T, U const &>;

    /**
     * @tparam T 
     * @tparam U 
     */
    template <typename T, typename U = T>
    concept MoveConstructible = Constructible<T, U &&>;

    /**
     * @tparam From 
     * @tparam To 
     */
    template <typename From, typename To>
    concept Convertible = requires {
                            declval<void (*)(To)>()(declval<From>());
                        };
    
    /**
     * @tparam T 
     * @tparam U 
     */
    template <typename T, typename U>
    inline constexpr bool _Same = false;

    /**
     * @tparam T 
     */
    template <typename T>
    inline constexpr bool _Same<T, T> = true;

    /**
     * @tparam T 
     * @tparam U 
     */
    template <typename T, typename U>
    concept Same = _Same<T, U>;

}
