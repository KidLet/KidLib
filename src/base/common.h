#ifndef __KIDLIB_COMMON_H__
#define __KIDLIB_COMMON_H__

#include <string>
#include <sstream>
#include "kstring.h"
#include "datetime.h"
#include <typeinfo>
#include <stdexcept>

//only support gcc
#define auto(name, ...) typeof(__VA_ARGS__) name((__VA_ARGS__))  

namespace kid
{
    typedef unsigned int uint;

    template<typename T>
    std::string tostr(const T& type)
    {
        std::ostringstream ostream;

        ostream << type;
        return ostream.str();
    }

    template<typename T>
    T strto(const std::string& str)
    {
        using namespace std;
        stringstream stream;
        T temp; //performance problem

        stream << str;
        if(stream >> temp)
            return temp;

        throw logic_error(string("Convert to ") + string(typeid(temp).name()) + string(" Error"));
        //throw std::exception(string("Convert to") + string("Error"));
    }

    // support the derivation of param template
    template<typename T>
    T strto(const std::string& str, T& result)
    {
        std::stringstream stream;

        stream << str;
        stream >> result;

        return result;
    }
}


#endif
