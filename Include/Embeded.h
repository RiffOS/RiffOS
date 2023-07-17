/**
 * @file Embeded.h
 * @author Krisna Pranav
 * @brief Embed Functionalities
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once

namespace Include::Embeded
{

    /**
     * @brief error codes.
     * 
     * @return int 
     */
    [[nodiscard]] int error();

    
    /**
     * @brief relaxe(embed with source)
     * 
     */
    void relaxe();

    /**
     * @brief Enter&Leave Critical Modes
     * 
     */
    void enterCritical();
    void leaveCritical();

    /**
     * @brief debug
     * 
     * @param buf 
     */
    void debug(char const *buf);

    /**
     * @brief panic
     * 
     * @param buf 
     */
    [[noreturn]] void panic(char const *buf);

}
