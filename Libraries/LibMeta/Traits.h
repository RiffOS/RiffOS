//
//  Traits.h
//  Riff
//
//  Created by krisna pranav on 17/07/23.
//

#pragma once

#include "Declare.h"

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

    template <>
    inline constexpr booll _Nullptr<decltype(nullptr)> = true;

    template <typename T, typename U>
    concept Same = _Same<T, U>;
    

}

