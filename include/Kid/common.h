#ifndef __KIDLIB_COMMON_H__
#define __KIDLIB_COMMON_H__

#include <string>
#include <sstream>

//only support gcc
#define auto(name, ...) typeof(__VA_ARGS__) name((__VA_ARGS__))  

namespace kid
{
    
    template<typename T>
    std::string tostr(const T& type)
    {
        static std::ostringstream ostream;

        ostream.clear();
        ostream.str("");
        ostream << type;

        return ostream.str();
    }

    template<typename T>
    T strto(const std::string& str)
    {
        static std::stringstream stream;
        T temp; //performance problem

        stream.clear();
        stream.str("");
        stream << str;
        stream >> temp;

        return temp;
    }

    std::string Fmt(const char* pFormat, ...);
}

#endif
