/**********************************************************************************
 **
 **  \file TimerMgr.cpp
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
 **********************************************************************************************************************/ 
#ifndef _WIN32
/* Related Header file */
#include "DKOsalTimerMgr.h"
/* C Library includes */
/* C++ Library includes */
#include <cstddef>
/* other library includes */
/* project includes */
#include "DKOsalMutexLock.h"         /* access to SYNCHRONIZED macro */
#include "DKOsalTrace.h"             /* for OSAL_DBG inclusion */

namespace dk
{

namespace osal
{

/**
 * \class      TimerMgr
 * \brief      Maintains the list of Timer in ascending order of
 *             expiration time and owns the Os Timer
 * \details    requirement id  751535
 */ 
TimerMgr::TimerMgr()
    :
    mOsTimer()
    ,
    mMutex()
    ,
    mTimerList()
    ,
    mSetOsTimer ( true )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::TimerMgr() constructor (this = %p)\n", this );
}

TimerMgr::~TimerMgr()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::~TimerMgr() destructor (this = %p)\n", this );
}

/**
 *  \fn      static TimerMgr &getInstance() 
 *  \brief   static funtion to getInstance of timerMgr.
 *  \return  Reference to TimerMgr.
 *  \details Requirement id  751535
 */
TimerMgr &TimerMgr::getInstance()
{
    static TimerMgr *pTimerMgr = NULL;

    if ( NULL == pTimerMgr )
    {
        static Mutex initMutex;
        /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
        SYNCHRONIZED ( initMutex )
        {
            if ( NULL == pTimerMgr )
            {
                /* coverity[misra_cpp_2008_rule_18_4_1_violation] : FALSE */
                pTimerMgr = new TimerMgr;
            }
        }
    }

    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::getInstance() (Instance = %p)\n", pTimerMgr );
    return *pTimerMgr;
}

/**
 *  \fn       void startTimer ( Timer *const timerPr )
 *  \brief    Function to start timer.
 *  \param    Timer object.
 *  \details Requirement id 751605
 */
void TimerMgr::startTimer ( Timer *const timerPr )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::startTimer(%p) (this = %p)\n", timerPr, this );
    TimerEntry newEntry;
    /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
    bool wasFirst = false;

    mOsTimer.getCurrentTime ( newEntry.expireTime );
    newEntry.timer = timerPr;

    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        // if timer is already in list, remove it first.
        if ( !mTimerList.empty() )
        {
            /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
            wasFirst = ( mTimerList.front().timer == timerPr );
            eraseTimer ( timerPr );
        }

        OsTimer::calcTimeOffsetMS ( timerPr->getTimeout(), newEntry.expireTime );
        insertTimer ( newEntry );

        if ( mSetOsTimer )
        {
            // restart OsTimer if we were the first entry before restart or if we are now the first entry.
            const TimerEntry &firstEntry = mTimerList.front();

            if ( wasFirst || ( firstEntry.timer == timerPr ) )
            {
                mOsTimer.start ( firstEntry.expireTime );
            }
        }
    }
}

/**
 *  \fn      void stopTimer ( const Timer *const timerPr )
 *  \brief   Function to stop timer.
 *  \param   Timer object.
 *  \details Requirement id 751606
 */
void TimerMgr::stopTimer ( const Timer *const timerPr )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::stopTimer(%p) (this = %p)\n", timerPr, this );

    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        if ( !mTimerList.empty() )
        {
            /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
            const bool wasFirst = ( mTimerList.front().timer == timerPr );
            eraseTimer ( timerPr );

            if ( mSetOsTimer )
            {
                if ( mTimerList.empty() )
                {
                    // we were the only timer in the list.
                    mOsTimer.stop();
                }
                else if ( wasFirst )
                {
                    // we were the first timer in the list, restart for next entry.
                    const TimerEntry &entry = mTimerList.front();
                    mOsTimer.start ( entry.expireTime );
                }
                else
                {
                    /* MISRA */
                }
            }
        }
    }
}

// Callback is called on expire of OS (system) timer
/**
 *  \fn       void onOsTimeout() 
 *  \brief    This funtion is called when OS(system) timer is expired.
 */
void TimerMgr::onOsTimeout()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::onOsTimeout() (this = %p)\n", this );
    OsTimer::Timestamp currentTime;

    mOsTimer.getCurrentTime ( currentTime );

    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        // Handle all timers with elapsed expire time.
        while ( !mTimerList.empty() )
        {
            TimerEntry entry = mTimerList.front();

            if ( OsTimer::timeIsLessThan ( currentTime, entry.expireTime ) )
            {
                break;  // the remaining timers have not elapsed, yet.
            }

            mTimerList.pop_front();
            const uint32_t interval = entry.timer->getTimerInterval();

            if ( interval > 0U )
            {
                // Periodic timer, re-add with updated expire time.
                // note: must be done before running callback, since the callback might call timer.stop()
                OsTimer::calcTimeOffsetMS ( interval, entry.expireTime );
                insertTimer ( entry );
            }

            // do not start OsTimer while in timeout processing.
            mSetOsTimer = false;
            mMutex.unlock(); // release lock while processing callbacks

            OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::onOsTimeout() : handle timer %p\n", entry.timer );
            entry.timer->actOnTimerExpired();

            mMutex.lock();
            mSetOsTimer = true;
        }

        // start OsTimer for next entry
        if ( !mTimerList.empty() )
        {
            mOsTimer.start ( mTimerList.front().expireTime );
        }
    }
}

void TimerMgr::insertTimer ( const TimerEntry &entry )
{
    // insert timer in list, sorted by expire time.
    /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
    int64_t pos = 0;
    TimerList::iterator it = mTimerList.begin();

    while ( ( it != mTimerList.end() ) && ( OsTimer::timeIsLessThan ( ( *it ).expireTime, entry.expireTime ) ) )
    {
        /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
        pos++;
        ++it;
    }

    (void) mTimerList.insert ( it, entry );
    OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::inserTimer(%p): insert at pos %d\n", entry.timer, pos );
}

void TimerMgr::eraseTimer ( const Timer *const timerPr )
{
    /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
    int64_t pos = 0;

    for ( TimerList::iterator it = mTimerList.begin(); it != mTimerList.end(); ++it )
    {
        if ( ( *it ).timer == timerPr )
        {
            (void) mTimerList.erase ( it );
            OSAL_DBG ( OSAL_SCOPE_TIMER, "TimerMgr::eraseTimer(%p): erased at pos %d\n", timerPr, pos );
            break;
        }
        /* coverity[misra_cpp_2008_rule_0_1_6_violation] : FALSE */
        pos++;
    }
}

} /* namespace osal */

} /* namespace dk */
#endif
