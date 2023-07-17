//
//  Embeded.h
//  Riff
//
//  Created by krisna pranav on 17/07/23.
//

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
