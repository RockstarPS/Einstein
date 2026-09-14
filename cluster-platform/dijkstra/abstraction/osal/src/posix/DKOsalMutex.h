/**********************************************************************************
 **
 **  \file Mutex.h
 **
 **  Created on: Apr 27, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description 
 **  |------------|----------|-------------------------------- 
 **  | 2017-04-27 | VMUTHUSU | Create Initial Module.
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
#ifndef SRC_DKOSALMUTEX_H_
#define SRC_DKOSALMUTEX_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \include      cstdint
                 header_files Dependancy_headers
 * \brief        The module shall use **cstdint** (standard datatype inclusion)data types.
 * \addtogroup   header_files
 */
#include <cstdint> 
/*!
 * \include      pthread.h
 * \brief        For pthread related inclusions 
 */
#include <pthread.h> 

namespace dk
{

namespace osal
{

/** 
 * \class   Mutex
 * \brief   A mutual-exclusion lock.
 *          Only one thread may have a Mutex locked at any one time.
 * \details requirement ID 751534
 */

class Mutex
{
    public:

        /** 
         * \fn      Mutex()
         * \brief   Construct a new Mutex
         * \details requirement ID 751559
         */
        Mutex();

        /** 
         * \fn      ~Mutex()
         * \brief   Destructor.
         * Note that destroying a locked mutex can lead to deadlock.
         * \details requirement ID 751559
         */
        ~Mutex();

        /** 
         * \fn      tryLock()
         * \brief   Try to lock the Mutex,
         *          The Mutex is locked if it is not locked by another user.
         * \return <b>true</b> lock acquired
         *         <b>false</b> lock is held by another user.
         * \details requirement ID 751560
         */
        bool tryLock();

        /**
         * \fn       timedLockMS ( const uint32_t msec ) 
         * \brief    The Mutex. (Waits for a timeout)
         *           Blocks the current thread until the lock is acquired, or the specified timeout milliseconds duration interval elapsed.
         * \param    msec The number of milliseconds to wait before the lock() is cancelled
         * \return   <b>true</b> lock acquired
         *           <b>false</b> timeout happened
         * \details  requirement ID 751561
         */
        bool timedLockMS ( const uint32_t msec );

        /** 
         * \fn      timedLockUS ( const uint32_t usec )
         * \brief   Lock the Mutex. (Waits for a timeout)
         *          Blocks the current thread until the lock is acquired, or the specified timeout  microseconds duration interval elapsed.
         * \param   usec The number of microseconds to wait before the lock() is cancelled
         * \return  <b>true</b> lock acquired
         *          <b>false</b> timeout happened
         * \details requirement ID 751562
         */
        bool timedLockUS ( const uint32_t usec );

        /** 
         * \fn      void lock()
         * \brief   lock the mutex.
         *          OsalMutex component shall provide APIs to lock the critical section using mutex lock functionality
         * \details requirement ID 751563
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        void lock();

        /** 
         * \fn      void unlock()
         * \brief   unlocks the mutex.
         *          OsalMutex component shall provide APIs to unlock the critical section
         * \details requirement ID 751564
         */
        void unlock();

    private:
        /**
         * \fn    Mutex ( const Mutex & )
         * \brief Disable Copy constructor and Assignment operator on Mutex
         */
        Mutex ( const Mutex & ) = delete;
        Mutex &operator= ( const Mutex & ) = delete;

        /** 
         * \fn      init()
         * \brief   Initialize the Mutex
         * \details requirement ID 751559
         */
        void init();

        /** 
         * \fn      pthread_mutex_t *getPthreadMutex()   
         * \brief   Get pointer to internal pthread_mutex
         * \details requirement ID 751534
         */
        pthread_mutex_t *getPthreadMutex();

        pthread_mutex_t mMutex;

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALMUTEX_H_ */
