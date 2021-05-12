/**
    tchar_templates.hpp
    Purpose: Manage ASCII and UNICODE differences during build time.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include <iostream>
#include <string>

#ifndef _WINDOWS
// UNIX: Comment the line below if you want the character set to be ASCII.
//#define _UNICODE
#endif

namespace BLL {

#ifndef WIN32
    #ifdef _UNICODE
    #define _T(x)    L ## x
    typedef wchar_t TCHAR;
    #else
    #define _T(x)    x
    typedef char TCHAR;
    #endif
#endif

#ifdef _UNICODE
#define tcout std::wcout
#define tcin std::wcin
#else
#define tcout std::cout
#define tcin std::cin
#endif

typedef std::basic_string<TCHAR> tstring;
}
