#ifndef __KIDLIB_DATETIME_H__
#define __KIDLIB_DATETIME_H__

#include "common.h"
using namespace std;

#define NOW kid::getNow()
#define NOWMS kid::getNowMs()

namespace kid
{
    int64_t getNow();
    int64_t getNowMs();
    string tm2str(const string& sFormat = "%Y%m%d", const time_t &t = getNow());
}

#endif
