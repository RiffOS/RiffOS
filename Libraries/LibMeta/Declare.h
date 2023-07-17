/**
 * @file Declare.h
 * @author Krisna Pranav
 * @brief Declaritive Functions
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

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