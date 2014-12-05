#include "common.h"
#include <string>
#include <cstdio>
#include <cstdarg>
#include <cassert>


using namespace kid;
using namespace std;

std::string kid::Fmt(const char* pFormat, ...)
{
    assert(pFormat != NULL);

    char cBuf[512];
    va_list pArgList;

    va_start(pArgList, pFormat);
    vsnprintf(cBuf, sizeof(cBuf)-1, pFormat, pArgList);
    va_end(pArgList);

    return string(cBuf);
}
