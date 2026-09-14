/**********************************************************************************
 **
 **  \file Clock.cpp
 **
 **  Created on: Jun 20, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-06-20 | VMUTHUSU | Create Initial Module.
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
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \include      unistd.h
 *                header_files Dependancy_headers 
 * \brief        The module shall added for the VS2015 compilation
 */
#include <unistd.h>	
/*!
 * \include      DKOsalClock.h
 * \brief        Contains the Header File Version ID of dk_osalclock
 */
#include "DKOsalClock.h"
/*!
 * \include      cstring
 * \brief        For string related functions
 */
#include <cstring>
/* for errno inclusion */
#include <cerrno>
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"

namespace dk
{

namespace osal
{

/**
 * \fn      void Clock::getSystemTime ( struct timespec &ts )
 * \brief   Get current system time.
 *          (seconds + nanoseconds since epoch.)
 * \param   ts pointer to timespec where time-stamp is stored.
 * \details Requirement ID 751546
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Clock::getSystemTime ( struct timespec &ts )
{
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getSystemTime(%p)\n", &ts );

/**
 * \fn      int64_t ret = clock_gettime ( CLOCK_REALTIME, &ts )
 * \brief   Function gets the current time of the clock specified by clock_id,
 *          and puts it into the buffer pointed to by tp.
 * \param   Returns 0 Success -1 An error occurred (errno is set).
 * Errors: 
 *          EFAULT- A fault occurred trying to access the buffers provided.
 *          EINVAL- Invalid clock_id.
 *          ESRCH- The process associated with this request doesn't exist.
 * \details Requirement ID 751546
 */
    const int32_t ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        ts.tv_sec = 0;
        ts.tv_nsec = 0;
        OSAL_ERR ( OSAL_SCOPE_CLOCK,
                "Clock::getSystemTime() : clock_gettime(CLOCK_REALTIME) failed error = %d [%s]\n",
                errno, strerror ( errno ) );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getSystemTime() : clock_gettime(CLOCK_REALTIME) succedded\n" );
}

/**
 *  \fn         void Clock::getMontonicTime ( struct timespec &ts )
 *  \brief      Get a monotonic time-stamp.
 *              (seconds + nanoseconds since some unspecified start.)
 *  \param      ts pointer to timespec where time-stamp is stored.
 *  \details    requirement ID 751547
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Clock::getMontonicTime ( struct timespec &ts )
{
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getMontonicTime(%p)\n", &ts );

    const int32_t ret = clock_gettime ( CLOCK_MONOTONIC, &ts );

    if ( ret != 0 )
    {
        ts.tv_sec = 0;
        ts.tv_nsec = 0;
        OSAL_ERR ( OSAL_SCOPE_CLOCK,
                "Clock::getMontonicTime() : clock_gettime(CLOCK_MONOTONIC) failed error = %d [%s]\n",
                errno, strerror ( errno ) );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getMontonicTime() : clock_gettime(CLOCK_MONOTONIC) succedded\n" );
}

/**
 *  \fn      void Clock::addTimeOffsetMS ( uint32_t msec, timespec &ts )
 *  \brief   Add offset in milliseconds to timespec
 *  \param   msec offset in milliseconds
 *  \param   ts pointer to timespec where time-stamp is stored. (ts must be normalized)
 *  \details Requirement ID 751548
 */
void Clock::addTimeOffsetMS ( const uint32_t msec, timespec &ts )
{
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::addTimeOffsetMS(%lu %p)\n", msec, &ts );
    // split msec to sec + nsec
    /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
    time_t sec = msec / 1000U;
    uint32_t nsec = ( msec % 1000U ) * 1000000U;

    // add sec from ts
    sec += ts.tv_sec;

    // add nsec from ts (highest value is 999000000 + 999999999)
    nsec += static_cast<uint32_t>( ts.tv_nsec );

    // normalize
    if ( nsec >= 1000000000U )
    {
        /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
        /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
        sec += nsec / 1000000000U;
        nsec = nsec % 1000000000U;
    }

    ts.tv_sec = sec;
    ts.tv_nsec = static_cast<int64_t>( nsec );
}

/**
 *  \fn     void Clock::addTimeOffsetUS ( uint32_t usec, timespec &ts )
 *  \brief  Add offset in microseconds to timespec
 *  \param  usec offset in microseconds
 *  \param  ts pointer to timespec where time-stamp is stored. (ts must be normalized)
 *  \details Requirement ID 751549
 */
void Clock::addTimeOffsetUS ( const uint32_t usec, timespec &ts )
{
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::addTimeOffsetUS(%lu %p)\n", usec, &ts );
    // split usec to sec + nsec
    /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
    time_t sec = usec / 1000000U;
    uint32_t nsec = ( usec % 1000000U ) * 1000U;

    // add sec from ts
    sec += ts.tv_sec;

    // add nsec from ts (highest value is 999999000 + 999999999)
    nsec += static_cast<uint32_t>( ts.tv_nsec );

    // normalize
    if ( nsec >= 1000000000U )
    {
        /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
        /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
        sec += nsec / 1000000000U;
        nsec = nsec % 1000000000U;
    }

    ts.tv_sec = sec;
    ts.tv_nsec = static_cast<int64_t>( nsec );
}

/**
 *  \fn         int64_t Clock::getTimeDiffUS ( const struct timespec &ts1, const struct timespec &ts2 )
 *  \brief      Calculate time delta in microseconds between two timespecs.
 *  \param      ts1 start timespec
 *  \param      ts2 end timespec
 *  \return     time delta in microseconds
 *  \details    Requirement ID 751550
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
int64_t Clock::getTimeDiffUS ( const struct timespec &ts1, const struct timespec &ts2 )
{
    int64_t timeDeltaUS;
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getTimeDiffUS(%p, %p)\n", &ts1, &ts2 );
    const int64_t diff_sec = ts2.tv_sec - ts1.tv_sec;
    const int64_t diff_nsec = ts2.tv_nsec - ts1.tv_nsec;
    timeDeltaUS = ( diff_sec * 1000000 ) + ( diff_nsec / 1000 );
    OSAL_DBG ( OSAL_SCOPE_CLOCK, "Clock::getTimeDiffUS() returns %lu\n", timeDeltaUS );
    return timeDeltaUS;
}

} /* namespace osal */

} /* namespace dk */
