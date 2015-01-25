#ifndef __KIDLIB_STRING_H__
#define __KIDLIB_STRING_H__

#include <string>
#include <vector>

namespace kid
{
    std::string fmt(const char* format, ...);
    std::string trim(const std::string& src, const std::string& charlist = "\n\r\t ");
    std::string substring(const std::string& src, size_t begin_index, size_t end_index);
    std::string substring(const std::string& src, size_t begin_index);
    std::vector<std::string> split(const std::string& src, const std::string& delimiter, bool with_empty = true);

}

#endif
