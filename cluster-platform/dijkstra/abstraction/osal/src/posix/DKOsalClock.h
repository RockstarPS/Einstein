/**********************************************************************************
 **
 **  \file Clock.h
 **
 **  Created on: Jun 20, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
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
/*!
 * \defgroup   header_files Dependancy_headers
 */
#ifndef SRC_DKOSALCLOCK_H_
#define SRC_DKOSALCLOCK_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \include     ctime
 * \brief       For timespec struct inclusion .
 * \addtogroup  header_files
 */
#include <ctime> 
/*!
 * \include     cstdint
 * \brief       For standard datatype inclusion .
 * \addtogroup  header_files
 */
#include <cstdint>

namespace dk
{

namespace osal
{

class Clock
{
    public:
        
        /**
        * \fn      static void getSystemTime ( struct timespec &ts )
        * \brief   Get current system time.
        *          (seconds + nanoseconds since epoch.)
        * \param   ts pointer to timespec where time-stamp is stored.
        * \details Requirement ID 751546
        */
        static void getSystemTime ( struct timespec &ts );

        /**
        *  \fn         static void getMontonicTime ( struct timespec &ts )
        *  \brief      Get a monotonic time-stamp.
        *              (seconds + nanoseconds since some unspecified start.)
        *  \param      ts pointer to timespec where time-stamp is stored.
        *  \details    requirement ID 751547
        */
        static void getMontonicTime ( struct timespec &ts );

        /**
        *  \fn      static void addTimeOffsetMS ( uint32_t msec, struct timespec &ts )
        *  \brief   Add offset in milliseconds to timespec
        *  \param   msec offset in milliseconds
        *  \param   ts pointer to timespec where time-stamp is stored. (ts must be normalized)
        *  \details Requirement ID 751548
        */
        static void addTimeOffsetMS ( const uint32_t msec, struct timespec &ts );

        /**
        *  \fn     static void addTimeOffsetUS ( uint32_t usec, struct timespec &ts )
        *  \brief  Add offset in microseconds to timespec
        *  \param  usec offset in microseconds
        *  \param  ts pointer to timespec where time-stamp is stored. (ts must be normalized)
        *  \details Requirement ID 751549
        */
        static void addTimeOffsetUS ( const uint32_t usec, struct timespec &ts );

        /**
        *  \fn         static int64_t getTimeDiffUS ( const struct timespec &ts1, const struct timespec &ts2 )
        *  \brief      Calculate time delta in microseconds between two timespecs.
        *  \param      ts1 start timespec
        *  \param      ts2 end timespec
        *  \return     time delta in microseconds
        *  \details    Requirement ID 751550
        */
        static int64_t getTimeDiffUS ( const struct timespec &ts1, const struct timespec &ts2 );

    private:

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALCLOCK_H_ */
