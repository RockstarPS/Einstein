/**********************************************************************************
 **
 **  \file ITimerListener.h
 **
 **  Created on: jun 14, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                     
 **  |------------|----------|-------------------------------- 
 **  | 2017-06-14 | VMUTHUSU | Create Initial Module.
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
#ifndef DKOSALITIMERLISTENER_H_
#define DKOSALITIMERLISTENER_H_

namespace dk
{

namespace osal
{
class Timer;

/**
 * \class   ITimerListener
 * \brief   Interface that provides a onTimeout method.
 *          (Used by Timer  to handle the Timer expiration jobs.)
 * \details requirement ID 751535
 */
class ITimerListener
{
    public:
        /**
         * \fn       ~ITimerListener
         *  @brief   Virtual destructor for ITimerListener.
         */
        virtual ~ITimerListener()
        {
        }

        /**
         *  \fn      onTimeout
         *  \brief   Called on timer timeout.
         *  \param   timer pointer to timer which has expired.
         *           helps user to identify the timer if listener is same
         *  \return  None.
         */
        virtual void onTimeout ( const Timer &timerPr ) = 0;
};

} /* namespace osal */

} /* namespace dk */
#endif /* ITIMERLISTENER_H_ */
