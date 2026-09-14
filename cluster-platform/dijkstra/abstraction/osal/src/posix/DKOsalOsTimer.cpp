/**********************************************************************************
 **
 **  \file OsTimer.cpp
 **
 **  Created on: Jun 20, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description 
 **  |------------|----------|-------------------------------- 
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
#ifndef _WIN32
/* Related Header file */
#include "DKOsalOsTimer.h"

/*!
 * \include      cstring
 * \brief        For memset functions
 */
#include <cstring>
/*!
 * \include      csignal
 * \brief        For siganl related inclusion for linux build
 */
#include <csignal>
/* for errno inclusion */
#include <cerrno>

/*!
 * \include      DKOsalClock.h
 * \brief        Contains the Header File Version ID of dk_osalclock
 */
#include "DKOsalClock.h"                 /* for Clock related functionality */
/*!
 * \include      DKOsalTimerMgr.h
 *  other library includes 
 *  project includes 
 * \brief        For TimerMgr class inclusion 
 */
#include "DKOsalTimerMgr.h" 
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

static timer_t sTimerId = 0;

// local methods
/**
 * \fn      static void sigEventThreadFunction ( const union sigval sigval )
 * \brief   Event function called on OS(system) timer expiry
 *          Notify the process by invoking sigev_notify_function as like the start function of a new thread.
 *          (Among the implementation possibilities here are that each timer notification  could  result
 *          in the creation of a new thread, or that a single thread is created to receive all notifications.)
 * \details requirement ID 751565
 */
/* coverity[misra_cpp_2008_rule_9_5_1_violation] : FALSE */
static void sigEventThreadFunction ( const union sigval sigval )
{
    if ( sigval.sival_ptr != NULL )
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER, "sigEventThreadFunction: alarm\n" );
        TimerMgr::getInstance().onOsTimeout();
    }
}
/**
 * \fn      OsTimer::OsTimer()
 * \brief   OsalOsTimer shall abstract the control/configure timer functions provided by OS(constructor)
 * \details requirement ID 751535
 */
OsTimer::OsTimer()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::OsTimer() constructor called (this = %p)\n", this );
    struct sigevent sigEvent;

    // Notify the timer expiration event by invoking sigev_notify_function
    // As if it were the start function of a new thread.
    (void) memset ( &sigEvent, 0, sizeof ( struct sigevent ) );
    /* coverity[misra_cpp_2008_rule_5_0_21_violation] : FALSE */
    sigEvent.sigev_notify = SIGEV_THREAD;
    sigEvent.sigev_notify_attributes = NULL;
    sigEvent.sigev_notify_function = &sigEventThreadFunction;
    sigEvent.sigev_value.sival_ptr = static_cast<void *>( &sTimerId );

    /**
     * \fn       int32_t ret = timer_create ( CLOCK_MONOTONIC, &sigEvent, &sTimerId )
     * \brief    The timer_create() function creates a per-process timer using the specified clock source,
     *           clock_id, as the timing base.
     *           The timer is created in the disabled state, and isn't enabled until you call timer_settime()
     * \returns: 0 Success, 
     *           -1 The timerid argument is set to the timer's ID.
     *           An error occurred (errno is set).
     * \param    errors:
     *           EAGAIN
     *           All timers are in use. You'll have to wait for a process to release one.
     *           EINVAL
     *           The clock_id isn't one of the valid CLOCK_* constants.
     *           EPERM
     *           The calling process doesn't have the required permission; see procmgr_ability().
     * \details  requirement ID 751566
    */
    const int32_t ret = timer_create ( CLOCK_MONOTONIC, &sigEvent, &sTimerId );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_TIMER,
                "OsTimer::OsTimer() : timer_create(CLOCK_MONOTONIC) failed error = %d [%s] (this = %p)\n",
                errno, strerror ( errno ), this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER,
                "OsTimer::OsTimer() : timer_create(CLOCK_MONOTONIC) succeeded (this = %p)\n", this );
    }
}

/**
 * \fn      OsTimer::~OsTimer()
 * \brief   OsalOsTimer shall abstract the control/configure timer functions provided by OS(destrctor)
 * \details requirement ID 751535
 */
OsTimer::~OsTimer()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::~OsTimer() destructor called (this = %p)\n", this );

    /**
     * \fn        int32_t ret = timer_delete ( sTimerId )
     * \brief     The timer_delete() function removes a previously attached timer based upon the
     *            timerid returned from the timer_create() function.     
     *            The timer is removed from the active system timer list,
     *            and returned to the free list of available timers.
     * \returns   0 Success, 
     *            -1 An error occurred (errno is set).
     * \param     errors:
     *            EINVAL
     *            The timer timerid isn't attached to the calling process.
     * \details   requirement ID 751567
    */
    
    const int32_t ret = timer_delete ( sTimerId );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_TIMER, "OsTimer::~OsTimer() : timer_delete() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::~OsTimer() : timer_delete() succeeded (this = %p)\n", this );
    }

    sTimerId = 0;
}


/**
 * \fn      void OsTimer::start ( const Timestamp &expireTime ) const
 * \brief   OsalOsTimer component shall provide APIs to start timer with expiration time
 * \details requirement ID 751568
 */
void OsTimer::start ( const Timestamp &expireTime ) const
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::start(expireTime = %lu/%lu) (this = %p)\n", expireTime.tv_sec,
            expireTime.tv_nsec, this );
    struct itimerspec itval;

    itval.it_value.tv_sec = expireTime.tv_sec;
    itval.it_value.tv_nsec = expireTime.tv_nsec;
    itval.it_interval.tv_sec = 0;
    itval.it_interval.tv_nsec = 0;

    /**
     * \fn          int32_t ret = timer_settime ( sTimerId, TIMER_ABSTIME, &itval, NULL )
     * \brief       The timer_settime() function sets the expiration time of the timer specified
     *              by timerid from the it_value member of the value argument. If the it_value structure
     *              member of value is zero, then the timer is disarmed.
     * 
     * \returns     0 Success.
     *              -1 An error occurred (errno is set).
     * \param       Errors:
     *              EFAULT
     *              A fault occurred trying to access the buffers provided.
     *              EINVAL
     *              The timer timerid isn't attached to the calling process or the number of nanoseconds specified
     *              by the tv_nsec member of one of the timespec structures in the itimerspec structure pointed
     *              to by value is less than zero or greater than or equal to 1000 million.
     * \details     requirement ID 751568
     */
    const int32_t ret = timer_settime ( sTimerId, static_cast<int32_t>( TIMER_ABSTIME ), &itval, NULL );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_TIMER,
                "OsTimer::start(expireTime = %lu/%lu) : timer_settime(TIMER_ABSTIME) failed error = %d [%s] (this =%p)\n",
                expireTime.tv_sec, expireTime.tv_nsec, ret, strerror ( ret ), this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER,
                "OsTimer::start(expireTime = %lu/%lu) : timer_settime(TIMER_ABSTIME) succeeded (this =%p)\n",
                expireTime.tv_sec, expireTime.tv_nsec, this );
    }
}

/**
 * \fn      void OsTimer::start ( const Timestamp &expireTime ) const
 * \brief   OsalOsTimer component shall provide APIs to stop the timer which is already running
 * \details requirement ID 751569
 */
void OsTimer::stop() const
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::stop() (this = %p)\n", this );
    struct itimerspec itval;

    itval.it_value.tv_sec = 0;
    itval.it_value.tv_nsec = 0;
    itval.it_interval.tv_sec = 0;
    itval.it_interval.tv_nsec = 0;

    /**
     * \fn          int32_t ret = timer_settime ( sTimerId, TIMER_ABSTIME, &itval, NULL )
     * \brief       The timer_settime() function sets the expiration time of the timer specified
     *              by timerid from the it_value member of the value argument. If the it_value structure
     *              member of value is zero, then the timer is disarmed.
     * 
     * \returns     0 Success.
     *              -1 An error occurred (errno is set).
     * \param       Errors:
     *              EFAULT
     *              A fault occurred trying to access the buffers provided.
     *              EINVAL
     *              The timer timerid isn't attached to the calling process or the number of nanoseconds specified
     *              by the tv_nsec member of one of the timespec structures in the itimerspec structure pointed
     *              to by value is less than zero or greater than or equal to 1000 million.
     * \details     requirement ID 751569
     */
    const int32_t ret = timer_settime ( sTimerId, static_cast<int32_t>( TIMER_ABSTIME ), &itval, NULL );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_TIMER,
                "OsTimer::stop() : timer_settime(TIMER_ABSTIME) failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::stop() : timer_settime(TIMER_ABSTIME) succeeded (this = %p)\n",
                this );
    }
}

/**
 * \fn      void OsTimer::getCurrentTime ( Timestamp &ts )
 * \brief   OsalOsTimer component shall provide APIs to get the current time by using OS provided timer functions
 * \details requirement ID 751570
 */
void OsTimer::getCurrentTime ( Timestamp &ts ) const
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::getCurrentTime() (this = %p)\n", this );

    const int32_t ret = clock_gettime ( CLOCK_MONOTONIC, &ts );

    if ( ret != 0 )
    {
        ts.tv_sec = 0;
        ts.tv_nsec = 0;
        OSAL_ERR ( OSAL_SCOPE_TIMER,
                "OsTimer::getCurrentTime() : clock_gettime(CLOCK_MONOTONIC) failed error = %d [%s] (this = %p)\n",
                errno, strerror ( errno ), this );
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_TIMER,
                "OsTimer::getCurrentTime() : clock_gettime(CLOCK_MONOTONIC) succeeded (this =%p)\n",
                this );
    }
}


/**
 * \fn      void OsTimer::calcTimeOffsetMS ( const uint32_t timeoutMS, Timestamp &ts )
 * \brief   OsalOsTimer component shall provide APIs to calculate the millisecond offset by adding the timeout with known timespec value
 * \details requirement ID 751571
 */
void OsTimer::calcTimeOffsetMS ( const uint32_t timeoutMS, Timestamp &ts )
{
    Clock::addTimeOffsetMS ( timeoutMS, ts );
}

/**
 * \fn      bool OsTimer::timeIsLessThan ( const Timestamp &ts1, const Timestamp &ts2 )
 * \brief   OsalOsTimer component shall provide APIs to compare the timespec values obtained for different instances
 * \details requirement ID 751572
 */
bool OsTimer::timeIsLessThan ( const Timestamp &ts1, const Timestamp &ts2 )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "OsTimer::timeIsLessThan()\n" );
    return ( ( ts1.tv_sec < ts2.tv_sec ) || ( ( ts1.tv_sec == ts2.tv_sec ) && ( ts1.tv_nsec <= ts2.tv_nsec ) ) );
}

} /* namespace osal */

} /* namespace dk */
#endif
