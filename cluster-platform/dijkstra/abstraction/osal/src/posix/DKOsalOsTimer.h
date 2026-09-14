/**********************************************************************************
 **
 **  \file OsTimer.h
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
#ifndef SRC_DKOSALOSTIMER_H_
#define SRC_DKOSALOSTIMER_H_

#include <cstdint>                /* standard datatype inclusion   */
#include <ctime>                  /* for timespec struct inclusion */

namespace dk
{

namespace osal
{

class OsTimer
{
    public:
        typedef struct timespec Timestamp;

        /**
         * \fn      OsTimer::OsTimer()
         * \brief   OsalOsTimer shall abstract the control/configure timer functions provided by OS(constructor)
         * \details requirement ID 751535
         */
        OsTimer();
        
        /**
         * \fn      OsTimer::~OsTimer()
         * \brief   OsalOsTimer shall abstract the control/configure timer functions provided by OS(destrctor)
         * \details requirement ID 751535
         */
        ~OsTimer();
        
        /**
         * \fn      void OsTimer::start ( const Timestamp &expireTime ) const
         * \brief   OsalOsTimer component shall provide APIs to start timer with expiration time
         * \details requirement ID 751568
         */
        void start ( const Timestamp &expireTime ) const;
        
        /**
         * \fn      void stop() const
         * \brief   OsalOsTimer component shall provide APIs to stop the timer which is already running
         * \details requirement ID 751569
         */
        void stop() const;
        
        /**
         * \fn      void OsTimer::getCurrentTime ( Timestamp &ts )
         * \brief   OsalOsTimer component shall provide APIs to get the current time by using OS provided timer functions
         * \details requirement ID 751570
         */
        void getCurrentTime ( Timestamp &ts ) const;

        /**
         * \fn      void OsTimer::calcTimeOffsetMS ( const uint32_t timeoutMS, Timestamp &ts )
         * \brief   OsalOsTimer component shall provide APIs to calculate the millisecond offset by adding the timeout with known timespec value
         * \details requirement ID 751571
         */
        static void calcTimeOffsetMS ( const uint32_t timeoutMS, Timestamp &ts );
        
        /**
         * \fn      bool OsTimer::timeIsLessThan ( const Timestamp &ts1, const Timestamp &ts2 )
         * \brief   OsalOsTimer component shall provide APIs to compare the timespec values obtained for different instances
         * \details requirement ID 751572
         */
        static bool timeIsLessThan ( const Timestamp &ts1, const Timestamp &ts2 );
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALOSTIMER_H_ */

