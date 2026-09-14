/**********************************************************************************
 **
 **  \file Timer.h
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
#ifndef SRC_DKOSALTIMER_H_
#define SRC_DKOSALTIMER_H_

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/ 
#include <cstdint>                     /* standard datatype inclusion   */
/*!
 * \include      DKOsalITimerListener.h
 *  other library includes 
 *  project includes 
 * \brief        For ITimerListener interface
 */
#include "DKOsalITimerListener.h"            /* for ITimerListener interface  */

namespace dk
{

namespace osal
{

class TimerMgr;

class Timer
{
    public:

        /**
         *  \fn      Timer ( ITimerListener &timerListener )
         *  \brief   Explicit constructor.
         *  \param   timerListener reference to TimerListner object.
         *  \details requirement ID 751540,751535
         */
        Timer ( ITimerListener &timerListener );

        /**
         *  \fn      virtual ~Timer()
         *  \brief   Destructor.
         */
        virtual ~Timer();

        /**
         *  \fn      void start ( const uint32_t timeoutPr )
         *  \brief   API exposed to user to start a one-shot timer.
         *            (inline function)
         *  \param   timeoutPr timeout value in msec
         *  \return  void.
         *  \details requirement ID 751600
         */
        void start ( const uint32_t timeoutPr );

        /**
         *  \fn      void start ( const uint32_t initialInterval, const uint32_t repetitionInterval )
         *  \brief   API exposed to user to start a periodic timer.
         *  \param   initialInterval     The timer will fire after this amount of msecs for the first time.
         *  \param   repetitionInterval  The timeout interval for all following timer events.
         *  \return  void.
         *  \details requirement ID 751601
         */
        void start ( const uint32_t initialInterval, const uint32_t repetitionInterval );

        /**
         *  \fn      void stop()
         *  \brief   API exposed to user to stop timer.
         *  \return  void.
         *  \details requirement ID 751606
         */
        void stop();

        /**
         *  \fn      uint32_t getTimeout() 
         *  \brief   Get timeout in msec.
         *  \return  expiration time in msec.
         *  \details requirement ID 751602
         */
        uint32_t getTimeout() const;

        /**
         *  \fn      uint32_t getTimerInterval() 
         *  \brief   Get timerInterval in msec for periodic timers.
         *  \return  expiration time in msec.
         *  \details requirement ID 751603
         */
        uint32_t getTimerInterval() const;

    private:

        /**
         *  \fn      Timer()
         *  \brief   Private default constructor,
         */
        Timer()  = delete;

        /**
         *  \fn      Timer ( const Timer &timerPr )
         *  \brief   Private copy constructor,
         *            so as no copy of timer object is made.
         *  \param   timer const reference to timer
         */
        Timer ( const Timer &timerPr ) = delete;

        /**
         *  \fn      Timer &operator= ( const Timer & )
         *  \brief   Private assignment operator,
         *            so as no assignment for timer object is made.
         *  \param   Timer const reference to timer
         *  \return  Reference to Timer object.
         */
        Timer &operator= ( const Timer & )  = delete;

        /**
         *  \fn      void actOnTimerExpired()
         *  \brief   Action to be taken by timer on OS timeout happens.
         *  \return  void.
         */
        void actOnTimerExpired();

        // Reference to TimerListener
        ITimerListener &listener;

        // initial timeout value in msec
        uint32_t initialTimeout;

        // Repeat time interval in msec for periodic timer
        uint32_t timerInterval;

        // friend to use private function of timer
        // To access private actOnTimerExpired()
        friend class TimerMgr;
};
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
inline void Timer::start ( const uint32_t timeoutPr )
{
    start ( timeoutPr, 0U );
}

inline uint32_t Timer::getTimeout() const
{
    return initialTimeout;
}

inline uint32_t Timer::getTimerInterval() const
{
    return timerInterval;
}

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALTIMER_H_ */
