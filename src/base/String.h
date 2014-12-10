#ifndef __KIDLIB_STRING_H__
#define __KIDLIB_STRING_H__

namespace kid
{
    std::string Fmt(const char* pFormat, ...);
    std::string trim(const std::string& sString, const std::string& sDelete = "\n\r\t ");
}

#endif
