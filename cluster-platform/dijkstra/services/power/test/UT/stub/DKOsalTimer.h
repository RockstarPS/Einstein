/*
 * Timer.h
 *
 *  Created on: Jun 20, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALTIMER_H_
#define SRC_DKOSALTIMER_H_

#include <cstdint>                     /* standard datatype inclusion   */
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
         *  @brief   Explicit constructor.
         *  @param   timerListener reference to TimerListner object.
         */
        Timer ( ITimerListener &timerListener );

        /**
         *  @brief   Destructor.
         */
        virtual ~Timer();

        /**
         *  @brief   API exposed to user to start a one-shot timer.
         *            (inline function)
         *  @param   timeout timeout value in msec
         *  @return  void.
         */
        void start ( uint32_t timeout );

        /**
         *  @brief   API exposed to user to start a periodic timer.
         *  @param   initialInterval     The timer will fire after this amount of msecs for the first time.
         *  @param   repetitionInterval  The timeout interval for all following timer events.
         *  @return  void.
         */
        void start ( uint32_t timeout, uint32_t repetitionInterval );

        /**
         *  @brief   API exposed to user to stop timer.
         *  @return  void.
         */
        void stop();

        /**
         *  @brief   Get timeout in msec.
         *  @return  expiration time in msec.
         */
        uint32_t getTimeout() const;

        /**
         *  @brief   Get timerInterval in msec for periodic timers.
         *  @return  expiration time in msec.
         */
        uint32_t getTimerInterval() const;

    private:

        /**
         *  @brief   Private default constructor,
         */
        Timer();

        /**
         *  @brief   Private copy constructor,
         *            so as no copy of timer object is made.
         *  @param   timer const reference to timer
         */
        Timer ( const Timer &timer );

        /**
         *  @brief   Private assignment operator,
         *            so as no assignment for timer object is made.
         *  @param   Timer const reference to timer
         *  @return  Reference to Timer object.
         */
        Timer &operator= ( const Timer & );

        /**
         *  @brief   Action to be taken by timer on OS timeout happens.
         *  @return  void.
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

inline void Timer::start ( uint32_t timeout )
{
    start ( timeout, 0 );
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
