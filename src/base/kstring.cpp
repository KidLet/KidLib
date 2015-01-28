#include "common.h"
#include <string>
#include <cstdio>
#include <cstdarg>
#include <cassert>

using namespace std;
using namespace kid;

namespace kid
{

string fmt(const char* format, ...)
{
    assert(format != NULL);

    //TODO buf size
    char buf[512];
    va_list va_arglist;

    va_start(va_arglist, format);
    vsnprintf(buf, sizeof(buf) - 1, format, va_arglist);
    va_end(va_arglist);

    return string(buf);
}

string trim(const string& src, const string& charlist)
{
    size_t left = 0;
    size_t right = src.length() - 1;

    while(left <= right && charlist.find(src[left]) != string::npos)
        left++;
    
    while(left <= right && charlist.find(src[right]) != string::npos)
        right--;

    return src.substr(left, right - left + 1);
}

vector<string> split(const string& src, const string& delimiter, bool with_empty)
{
    vector<string> result;
    size_t current_pos = 0;
    size_t next_pos = string::npos;

    while(current_pos < src.size())
    {
        next_pos = src.find(delimiter, current_pos);

        if(with_empty || (with_empty == false && 
                            (next_pos == string::npos || next_pos - current_pos > 1)))
        {
            result.push_back(current_pos == next_pos ? "" :substring(src, current_pos, next_pos - 1));
        }

        if(next_pos == string::npos)
        {
            break;
        }
        else
        {
            current_pos = next_pos + delimiter.size();
            if(current_pos >= src.size() && with_empty)
            {
                result.push_back("");
            }
        }

    }

    if(result.empty())
    {
        result.push_back(src);
    }


    return result;
}

vector<string> split(const string& src, const char array_delimiter[][128], bool with_empty)
{
    vector<string> result;
    size_t array_count = sizeof(array_delimiter)/sizeof(array_delimiter[0]);

    for(size_t i=0; i<array_count; i++)
    {

    }


    return result;
}

vector<string> split(const string& src, const vector<string>& array_delimiter, bool with_empty)
{
    vector<string> result;
    size_t current_pos = 0;
    size_t next_pos = string::npos;
    size_t delimiter_pos;

    while(current_pos < src.size())
    {
        next_pos = string::npos;
        for(size_t i=0; i<array_delimiter.size(); i++)
        {
            size_t pos = src.find(array_delimiter[i], current_pos);
            if(next_pos > pos)
            {
                next_pos = pos;
                delimiter_pos = i;
            }
        }

        if(with_empty || (with_empty == false && 
                            (next_pos == string::npos || next_pos - current_pos > 1)))
        {
            result.push_back(current_pos == next_pos ? "" :substring(src, current_pos, next_pos - 1));
        }

        if(next_pos == string::npos)
        {
            break;
        }
        else
        {
            current_pos = next_pos + array_delimiter[delimiter_pos].size();
            if(current_pos >= src.size() && with_empty)
            {
                result.push_back("");
            }
        }

    }

    if(result.empty())
    {
        result.push_back(src);
    }


    return result;
}

string substring(const string& src, size_t begin_index, size_t end_index)
{
    end_index = (end_index >= src.size()) ? src.size() : end_index;

    if(end_index < begin_index)
    {
        //throw a exception ?
        return "";
    }
    return src.substr(begin_index, end_index - begin_index + 1);
}

string substring(const string& src, size_t begin_index)
{
    return substring(src, begin_index, src.size() - 1);
}


}
