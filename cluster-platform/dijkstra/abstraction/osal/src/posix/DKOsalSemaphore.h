/**********************************************************************************
 **
 **  \file Semaphore.h
 **
 **  Created on: Apr 28, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2017-04-28 | VMUTHUSU | Create Initial Module.
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

#ifndef SRC_DKOSALSEMAPHORE_H_
#define SRC_DKOSALSEMAPHORE_H_

/**********************************************************************************************************************
 * INCLUDE
 **********************************************************************************************************************/
#include <cstdint>                     /* standard datatype inclusion   */

/*!
 * \include      semaphore.h
 *               header_files Dependancy_headers
 * \brief        For sem_t inclusion
 */
#include <semaphore.h> 

namespace dk
{

namespace osal
{

class Semaphore
{
    public:
        /** 
         * \fn      Semaphore ( const uint32_t counter ) 
         * \brief   Constructor. 
         * \param   counter Initial value of the semaphore counter.
         * \details requirement ID 751538,751584
         */
        explicit Semaphore ( const uint32_t counter );

        /** 
         * \fn      ~Semaphore(); 
         * \brief   Destructor. 
         * \param   counter Initial value of the semaphore counter.
         * \details requirement ID 751538,751584
         */
        ~Semaphore();

        /** 
         * \fn      bool tryWait()
         * \brief   Try to wait for a semaphore
         *          If the counter is greater than "0", it will be decremented by "1"
         * \return  <b>true</b> semaphore counter greater thann "0"
         *          <b>false</b> semaphore counter is "0"
         * \details requirement ID 751585
         */
        bool tryWait();

        /** 
         * \fn      bool timedWaitMS ( const uint32_t msec )
         * \brief   Blocks the current thread until the semaphore counter is greater than "0", and then decrements
         *          the counter by "1". If the specified timeout interval elapses, the function is cancelled.
         * \param   msec number of milliseconds to wait before the wait() is cancelled
         * \return  <b>true</b> semaphore counter is greater than "0"
         *          <b>false</b> a timeout occurred
         * \details requirement ID 751586
         */ 
        bool timedWaitMS ( const uint32_t msec );
        
        /** 
         * \fn      bool timedWaitUS ( const uint32_t usec )
         * \brief   Semaphore wait operation (waits with a timeout)
         *          Blocks the current thread until the semaphore counter is greater than "0", and then decrements
         *          the counter by "1". If the specified timeout interval elapses, the function is cancelled.
         * \param   msec number of microseconds to wait before the wait() is cancelled
         * \return  <b>true</b> semaphore counter is greater than "0"
         *          <b>false</b> a timeout occurred
         * \details requirement ID 751587
         */
        bool timedWaitUS ( const uint32_t usec );

        /** 
         * \fn      void wait()
         * \brief   Semaphore wait operation
         *          Blocks the current thread until the semaphore is greater than "0", and then decrements the counter by "1"
         * \details requirement ID 751588
         */
        /* coverity[misra_cpp_2008_rule_2_10_6_violation] : FALSE */
        void wait();

        /** 
         * \fn      void post()
         * \brief   Semaphore post operation
         *          Increments the semaphore counter by "1" and then notifies the waiting threads.
         * \details requirement ID 751589
         */
        void post();

        /** 
         * \fn      uint32_t value()
         * \brief   Get counter value of semaphore
         * \return  current counter value
         * \details requirement ID 751590
         */
        uint32_t value();

    private:
        /**
         * \fn    Semaphore ( const Semaphore & )   
         * \brief Disable Copy Constructor and Assignment operators
         */
        Semaphore ( const Semaphore & ) = delete;
        Semaphore &operator= ( const Semaphore & ) = delete;

        /** 
         * \fn      void init ( const uint32_t counter )
         * \brief   Initialize the Semaphore
         * \details requirement ID 751591
         */
        /* coverity[misra_cpp_2008_rule_2_10_1_violation] : FALSE */
        void init ( const uint32_t counter );

        sem_t mSemaphore;

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALSEMAPHORE_H_ */
