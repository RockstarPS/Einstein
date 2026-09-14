/**********************************************************************************
 **
 **  \file TimerMgr.h
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

#ifndef SRC_DKOSALTIMERMGR_H_
#define SRC_DKOSALTIMERMGR_H_
/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/ 
#include <cstdint>              /* standard datatype inclusion   */
#include <list>                 /* for std::list inclusion       */
#include "DKOsalTimer.h"        /* for Timer class inclusion     */
#include "DKOsalMutex.h"        /* for Mutex Class inclusion     */
#include "DKOsalOsTimer.h"            /* for OsTimer class inclusion   */

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
class TimerMgr
{
    public:
        /**
         *  \fn      static TimerMgr &getInstance() 
         *  \brief   static funtion to getInstance of timerMgr.
         *  \return  Reference to TimerMgr.
         *  \details Requirement id  751535
         */
        static TimerMgr &getInstance();

        /**
         *  \fn        void startTimer ( Timer *const timerPr )
         *  \brief    Function to start timer.
         *  \param    Timer object.
         *  \details Requirement id 751605
         */
        void startTimer ( Timer *const timerPr );

        /**
         *  \fn      void stopTimer ( const Timer *const timer )
         *  \brief   Function to stop timer.
         *  \param   Timer object.
         *  \details Requirement id 751606
         */
        void stopTimer ( const Timer *const timerPr );

        /**
         *  \fn       void onOsTimeout() 
         *  \brief    This funtion is called when OS(system) timer is expired.
         */
        void onOsTimeout();

    private:
        struct TimerEntry
        {
            OsTimer::Timestamp expireTime;
            /* coverity[misra_cpp_2008_rule_2_10_1_violation] : FALSE */
            Timer *timer;
        };

        typedef std::list<TimerEntry> TimerList;

        TimerMgr();
        ~TimerMgr();
        void insertTimer ( const TimerEntry &entry );
        void eraseTimer ( const Timer *const timerPr );

        OsTimer mOsTimer;
        Mutex mMutex;
        TimerList mTimerList;
        bool mSetOsTimer;
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALTIMERMGR_H_ */
