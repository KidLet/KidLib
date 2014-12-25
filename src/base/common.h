#ifndef __KIDLIB_COMMON_H__
#define __KIDLIB_COMMON_H__

#include <string>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include "String.h"
#include "Datetime.h"

//only support gcc
#define auto(name, ...) typeof(__VA_ARGS__) name((__VA_ARGS__))  

namespace kid
{
    typedef unsigned int uint;

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
        using namespace std;
        static stringstream stream;
        T temp; //performance problem

        stream.clear();
        stream.str("");
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
        static std::stringstream stream;

        stream.clear();
        stream.str("");
        stream << str;
        stream >> result;

        return result;
    }
}


#endif
