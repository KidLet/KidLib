#include "Datetime.h"
#include <sys/time.h>

string kid::tm2str(const string& sFormat, const time_t &t)
{
    char sTime[128];
    struct tm stTm;

    localtime_r(&t, &stTm);
    strftime(sTime, sizeof(sTime), sFormat.c_str(), &stTm);

    return sTime;
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

