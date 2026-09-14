/*
 * Timer.h
 *
 *  Created on: Jun 20, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALTIMER_H_
#define SRC_DKOSALTIMER_H_

#include "DKOsalITimerListener.h"

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
    void start ( uint32_t timeout, uint32_t repetitionInterval );
    void stop();
    
};


} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALTIMER_H_ */
