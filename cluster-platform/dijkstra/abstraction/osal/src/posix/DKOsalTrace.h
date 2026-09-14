/**********************************************************************************
 **
 **  \file osaltrace.h
 **
 **  Created on: Apr 25, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                           
 **  |------------|----------|--------------------------------                          
 **  | 2017-04-25 | VMUTHUSU | Create Initial Module.
 **  | 2023-09-20 | damudhar | Added Doxygen document
 **
 ** \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **********************************************************************************/
/**********************************************************************************************************************
 *  HEADER FILE GUARD
 **********************************************************************************************************************/ 

#ifndef SRC_DKOSALTRACE_H_
#define SRC_DKOSALTRACE_H_

#include <ctime>         /* for timespec struct inclusion */

/* OSAL Trace scope definitions */
#define OSAL_SCOPE_CONFIG  ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<0U) )
#define OSAL_SCOPE_THREAD  ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<1U) )
#define OSAL_SCOPE_PROCESS ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<2U) )

#define OSAL_SCOPE_MUTEX   ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<3U) )
#define OSAL_SCOPE_COND    ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<4U) )
#define OSAL_SCOPE_SEM     ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<5U) )
#define OSAL_SCOPE_SHM     ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<6U) )
#define OSAL_SCOPE_TIMER   ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<7U) )
#define OSAL_SCOPE_CLOCK   ( static_cast<uint16_t>((static_cast<uint16_t>(1U))<<8U) )

#define OSAL_SCOPE_ALL     (0xFFFFU)

/* OSAL debug switches. set to mask of trace scopes (0 to disable) */
#define OSAL_ENABLE_DEBUG   0
#define OSAL_ENABLE_WARNING OSAL_SCOPE_ALL
#define OSAL_ENABLE_ERROR   OSAL_SCOPE_ALL

#ifndef OSAL_ENABLE_TIMESTAMPS
    #define OSAL_ENABLE_TIMESTAMPS 1 /* set to 0 to avoid printing timestamps with OSAL_* messages */
#endif

namespace dk
{

namespace osal
{
#if ((OSAL_ENABLE_DEBUG) != 0)    
void osal_dbg ( const char *fmt, ... );
#endif
void osal_warn ( const char *fmt, ... );
void osal_error ( const char *fmt, ... );
void osal_abort();

} /* namespace osal */

} /* namespace dk */

#if ((OSAL_ENABLE_DEBUG) != 0)
    #define OSAL_DBG(scope, ...) do { if (scope & (OSAL_ENABLE_DEBUG)) dk::osal::osal_dbg(__VA_ARGS__); } while (false)
#else
    #define OSAL_DBG(scope, ...) do { } while (false)
#endif

#if ((OSAL_ENABLE_WARNING) != 0)
    #define OSAL_WARN(scope, ...) do { if ( ( (scope) & (OSAL_ENABLE_WARNING) ) != 0U ) { dk::osal::osal_warn(__VA_ARGS__); } } while (false)
#else
    #define OSAL_WARN(scope, ...) do { } while (false)
#endif

#if ((OSAL_ENABLE_ERROR) != 0)
    #define OSAL_ERR(scope, ...) do { if ( ( (scope) & (OSAL_ENABLE_ERROR)) != 0U ) { dk::osal::osal_error(__VA_ARGS__); } } while (false)
#else
    #define OSAL_ERR(scope, ...) do { } while (false)
#endif

#define OSAL_ABORT() do { dk::osal::osal_abort(); } while (false)

/* NOTE: The ## before the __VA_ARGS__ swallows the last comma, if __VA_ARGS__ is empty. */
#if (OSAL_ENABLE_TIMESTAMPS != 0)
/* coverity[misra_cpp_2008_rule_16_0_6_violation] : FALSE */
#define OSAL_OUTPUT_GENERIC(PREFIX, PIDTID, MSG, ...)                                                         \
    do {                                                                                                      \
        timespec _td;                                                                                         \
        const int32_t ret = clock_gettime(CLOCK_MONOTONIC,&_td);                                                   	  \
        if ( ret != 0 ){                         															  \
			(void) printf("OSAL ErrorWarn: clock_get time error %d\n", ret);						                  \
		}					                                                                                  \
        (void) printf(PREFIX " %02ld:%02ld:%02ld.%.06ld [" PIDTID "] %s", static_cast<int64_t>(_td.tv_sec / 3600),  \
                static_cast<int64_t>((_td.tv_sec / 60) % 60), static_cast<int64_t>(_td.tv_sec % 60),        \
                static_cast<int64_t>(_td.tv_nsec / 1000), (MSG), ##__VA_ARGS__);                               \
    } while(false)
#else
#define OSAL_OUTPUT_GENERIC(PREFIX, PIDTID, MSG, ...)
printf ( PREFIX " [" PIDTID "] %s", MSG, ##__VA_ARGS__);
#endif

#endif /* SRC_DKOSALTRACE_H_ */
