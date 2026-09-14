/**********************************************************************************
 **
 **  \file Timer.cpp
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
#include "DKOsalTimer.h"
/* C Library includes */
/* C++ Library includes */
/*!
 * \include      DKOsalTimerMgr.h
 *  other library includes 
 *  project includes 
 * \brief        For TimerMgr reference
 */
#include "DKOsalTimerMgr.h"    /* for TimerMgr reference */
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"       /* for OSAL_DBG inclusion */

namespace dk
{

namespace osal
{

/****************************************************************************************** 
START OF PUBLIC MEMBER FUNCTIONS 
********************************************************************************************/
/**
 *  \fn      Timer ( ITimerListener &timerListener )
 *  \brief   Explicit constructor.
 *  \param   timerListener reference to TimerListner object.
 *  \details requirement ID 751540,751535
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Timer::Timer ( ITimerListener &timerListener )
    :
    listener ( timerListener )
    ,
    initialTimeout ( 0U )
    ,
    timerInterval ( 0U )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "Timer::Timer() constructor (this = %p)\n", this );
}
/**
 *  \fn      virtual ~Timer()
 *  \brief   Destructor.
 */
Timer::~Timer()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "Timer::~Timer() Destructor (this = %p)\n", this );
    /* stop the timers */
    stop();
}

/**
 *  \fn      void Timer::start ( const uint32_t initialInterval, const uint32_t repetitionInterval )
 *  \brief   API exposed to user to start a one-shot timer.
 *            (inline function)
 *  \param   timeout timeout value in msec
 *  \return  void.
 *  \details requirement ID 751600,7516001
 */
void Timer::start ( const uint32_t initialInterval, const uint32_t repetitionInterval )
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "Timer::start(%lu, %lu) (this = %p)\n", initialInterval, repetitionInterval,
            this );
    initialTimeout = initialInterval;
    timerInterval = repetitionInterval;
    TimerMgr::getInstance().startTimer ( this );
}

/**
 *  \fn      void Timer::stop()
 *  \brief   API exposed to user to stop timer.
 *  \return  void.
 *  \details requirement ID 751606
 */
void Timer::stop()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "Timer::stop() (this = %p)\n", this );
    initialTimeout = 0U;
    timerInterval = 0U;
    try
    {
        /* coverity[cert_err59_cpp_violation] : FALSE */
    	TimerMgr::getInstance().stopTimer ( this );
    }
    catch ( std::exception &ex )
    {
    	OSAL_ERR ( OSAL_SCOPE_TIMER, "Timer::stop: unhandled exception! what = \"%s \", (this = %p)\n",
    			 ex.what(), this );
    	OSAL_ABORT()
    	;
    }
    catch ( ... )
    {
        OSAL_ERR ( OSAL_SCOPE_TIMER, "Timer::stop: unhandled exception! \n" );
        OSAL_ABORT()
        ;
    }
}

/**
 *  \fn      void actOnTimerExpired()
 *  \brief   Action to be taken by timer on OS timeout happens.
 *  \return  void.
 */
void Timer::actOnTimerExpired()
{
    OSAL_DBG ( OSAL_SCOPE_TIMER, "Timer::actOnTimerExpired() (this = %p)\n", this );
    listener.onTimeout ( *this );
}

/* END OF PUBLIC MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
#endif
