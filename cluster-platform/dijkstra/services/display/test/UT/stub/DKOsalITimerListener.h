/*
 * ITimerListener.h
 *
 *  Created on: Jun 14, 2017
 *      Author: VMUTHUSU
 */

#ifndef DKOSALITIMERLISTENER_H_
#define DKOSALITIMERLISTENER_H_

namespace dk
{

namespace osal
{
class Timer;

/**
 *  @brief  Interface that provides a onTimeout method.
 *  (Used by Timer  to handle the Timer expiration jobs.)
 */
class ITimerListener
{
    public:
        /**
         *  @brief   Virtual destructor for ITimerListener.
         */
        virtual ~ITimerListener()
        {
        }

        /**
         *  @brief   Called on timer timeout.
         *  @param   timer pointer to timer which has expired.
         *           helps user to identify the timer if listener is same
         *  @return  None.
         */
        virtual void onTimeout ( const Timer &timer ) = 0;
        //virtual void onTimeout(Timer *timer) = 0;
};

} /* namespace osal */

} /* namespace dk */

#endif /* ITIMERLISTENER_H_ */
