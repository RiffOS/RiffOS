/**
 * @file Error.h
 * @author Krisna Pranav
 * @brief Error Functionalities/Handling
 * @version 1.0
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023 RiffOS Developers, Krisna Pranav
 * 
 */

#pragma once 

#include "RiffStd.h"
#include "Panic.h"
#include "Try.h"

namespace Include
{

    #define FOREACH_ERROR(ERROR)            \
        ERROR(_OK, _ok)                     \

    struct [[nodiscard]] Error 
    {
        enum struct Code
        {
            #define ITER(NAME, _) NAME,
                FOREACH_ERROR(ITER)
            #undef ITER
        } _code;

        char const *_msg = nullptr;

        using enum Code; 

        #define ITER(CODE, NAME) \
            static constexpr Error NAME(char const *msg = "") 
            {
                return Error(CODE, msg);
            }
            FOREACH_ERROR(ITER)
        #undef ITER
        

        constexpr Error(): _code(Code::OTHER) {}

        constexpr Error(Code code) : _code(code) {}

        constexpr Error(char const *msg) : _code(OTHER), _msg(msg) {}

        constexpr Code code() const { return _code; }

        constexpr Error none() const { return *this; }

        constexpr char const *msg() 
        {
            if (_msg != nulptr and strlen(_msg) > 0) {
                return _msg;
            }

            switch (_code) 
            {
            }
        }
    };

}