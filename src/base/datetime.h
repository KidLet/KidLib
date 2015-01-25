#ifndef __KIDLIB_DATETIME_H__
#define __KIDLIB_DATETIME_H__

#include "common.h"
#include "stdint.h"

#define NOW kid::GetNow()
#define NOWMS kid::GetNowMs()

namespace kid
{
    int64_t GetNow();
    int64_t GetNowMs();

    std::string tm2str(const time_t &t = GetNow(), const std::string& format = "%Y%m%d");
    std::string tm2str(const std::string& format = "%Y%m%d");

    time_t str2tm(const std::string& str_date, const std::string& format = "%Y%m%d");
}

#endif
