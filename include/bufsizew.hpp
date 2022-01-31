// MIT License
//
// Copyright (c) 2022 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
// for unix-like systems use bufsize [https://github.com/ferhatgec/bufsize]
// for both of them, wrap maybe?
//
// * why bufsizew not part of bufsize?
//  - idk
//
// * really why?
//  - idk
//
// * why?!
//  - idk
//
// idk is the best word like generics to use.

#ifndef BUFSIZEW_BUFSIZEW_HPP
#define BUFSIZEW_BUFSIZEW_HPP

#if defined(__has_include) && (defined(_WIN32) || defined(_WIN64))
    #if __has_include(<windows.h>)
        #include <windows.h>
    #elif __has_include(<Windows.h>)
        #include <Windows.h>
    #endif

    #define ABS(x) (x < 0) ? -x : x

    class __bufsize {
        CONSOLE_SCREEN_BUFFER_INFO data;
    public:
        unsigned columns = 0, rows = 0;
    public:

        void update() noexcept {
            if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &data))
                return;

            this->columns = ABS(this->data.srWindow.Right - this->data.srWindow.Left + 1);
            this->rows = ABS(this->data.srWindow.Bottom - this->data.srWindow.Top + 1);
        }
    };
#else
    #error
#endif // __has_include


#endif // BUFSIZEW_BUFSIZEW_HPP
