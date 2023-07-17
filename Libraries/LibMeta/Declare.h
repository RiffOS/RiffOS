//
//  Declare.h
//  Riff
//
//  Created by krisna pranav on 17/07/23.
//

#pragma once

namespace LibMeta
{
    /**
     * @tparam T 
     * @return T 
     */
    template <typename T>
    T declval();

    /** 
     * @tparam T 
     * @return T& 
     */
    template <typename T>
    T &declref();

    /** 
     * @tparam T 
     * @return T& 
     */
    template <typename T>
    T &declare();
}