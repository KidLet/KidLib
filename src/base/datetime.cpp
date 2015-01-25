#include "datetime.h"
#include <cstring>
#include <sys/time.h>

using namespace std;
using namespace kid;

string kid::tm2str(const time_t &t, const string& format)
{
    char time_buf[128];
    struct tm timeinfo;

    localtime_r(&t, &timeinfo);
    strftime(time_buf, sizeof(time_buf), format.c_str(), &timeinfo);

    return time_buf;
}

time_t kid::str2tm(const string& str_date, const string& format)
{
    struct tm timeinfo;

    ::memset(&timeinfo, 0, sizeof(struct tm)); //must be
    if(strptime(str_date.c_str(), format.c_str(), &timeinfo) != NULL)
    {
        return mktime(&timeinfo);
    }
    else 
    {
        //TODO throw a exception ?
        return 0;
    }
}

string tm2str(const std::string& format = "%Y%m%d")
{
    return tm2str(GetNow(), format);
}

int64_t kid::GetNow()
{
    struct timeval tv;

    ::gettimeofday(&tv, NULL);
    return tv.tv_sec;
}

int64_t kid::GetNowMs()
{
    struct timeval tv;

    ::gettimeofday(&tv, NULL);
    return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

