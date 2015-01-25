#include "common.h"
#include <string>
#include <cstdio>
#include <cstdarg>
#include <cassert>

using namespace std;
using namespace kid;

string kid::Fmt(const char* pFormat, ...)
{
    assert(pFormat != NULL);

    //TODO buf size
    char cBuf[512];
    va_list pArgList;

    va_start(pArgList, pFormat);
    vsnprintf(cBuf, sizeof(cBuf)-1, pFormat, pArgList);
    va_end(pArgList);

    return string(cBuf);
}

string kid::trim(const string& sString, const string& sDelete)
{
    size_t iLeft = 0;
    size_t iRight = sString.length() - 1;

    while(iLeft <= iRight && sDelete.find(sString[iLeft]) != string::npos)
        iLeft++;
    
    while(iLeft <= iRight && sDelete.find(sString[iRight]) != string::npos)
        iRight--;

    return sString.substr(iLeft, iRight-iLeft+1);
}
