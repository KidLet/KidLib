#include "datetime.h"
#include <cstring>
#include <sys/time.h>

string kid::tm2str(const string& sFormat, const time_t &t)
{
    char sTime[128];
    struct tm stTm;

    localtime_r(&t, &stTm);
    strftime(sTime, sizeof(sTime), sFormat.c_str(), &stTm);

    return sTime;
}

time_t kid::str2tm(const string& sDate, const string& sFormat)
{
    struct tm stTm;
    ::memset(&stTm, 0, sizeof(struct tm)); //must be
    char *p = strptime(sDate.c_str(), sFormat.c_str(), &stTm);
    if(p != NULL)
        return mktime(&stTm);
    else 
        return 0;
}

int64_t kid::getNow()
{
    struct timeval stTv;

    ::gettimeofday(&stTv, NULL);
    return stTv.tv_sec;
}

int64_t kid::getNowMs()
{
    struct timeval stTv;

    ::gettimeofday(&stTv, NULL);
    return (stTv.tv_sec) * 1000 + (stTv.tv_usec / 1000);
}

