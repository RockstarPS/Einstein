#ifndef __TRACYSYSTIME_HPP__
#define __TRACYSYSTIME_HPP__

#if defined _WIN32 || defined __CYGWIN__ || defined __linux__ || defined __QNX__ || defined __APPLE__
#  define TRACY_HAS_SYSTIME
#else
#  include <sys/param.h>
#endif

#ifdef BSD
#  define TRACY_HAS_SYSTIME
#endif

#ifdef TRACY_HAS_SYSTIME

#include <stdint.h>

namespace tracy
{

class SysTime
{
public:
    SysTime();
    float Get();

    void ReadTimes();
#  if defined(__QNX__)
   void CalcCPULoad();
# endif
private:
    uint64_t idle, used;
};

}
#endif

#endif
