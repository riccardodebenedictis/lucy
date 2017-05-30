#pragma once

#ifdef NDEBUG
#define LOG(msg) ((void)0)
#define WRITE(file_name, content) ((void)0)
#else
#include <cstring>
#include <iostream>
#include <fstream>
#if defined _WIN32 || defined __CYGWIN__
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
#define LOG(msg) std::cout << __FILENAME__ << "(" << __LINE__ << "): " << msg << std::endl
#define WRITE(file_name, content) \
    {                             \
        std::ofstream ofs;        \
        ofs.open(file_name);      \
        ofs << content;           \
        ofs.close();              \
    }
#endif