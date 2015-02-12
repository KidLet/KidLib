#ifndef __KIDLIB_KSTRING_H__
#define __KIDLIB_KSTRING_H__

#include <string>
#include <vector>
#include "kstring_join.h"

namespace kid
{
    std::string Fmt(const char* format, ...);
    std::string Trim(const std::string& src, const std::string& charlist = "\n\r\t ");

    std::string SubString(const std::string& src, size_t begin_index, size_t end_index);
    std::string SubString(const std::string& src, size_t begin_index);

    std::vector<std::string> Split(const std::string& src, const std::string& delimiter, bool with_empty = true);
    std::vector<std::string> Split(const std::string& src, const char array_delimiter[][128], bool with_empty = true);
    std::vector<std::string> Split(const std::string& src, const std::vector<std::string>& array_delimiter, bool with_empty = true);

    bool StartsWith(const std::string& src, const std::string& prefix, size_t offset = 0);
    bool EndsWith(const std::string& src, const std::string& prefix);

}

#endif
