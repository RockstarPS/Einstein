/**********************************************************************************
 **
 **  \file RecursiveMutex.h
 **
 **  Created on: Apr 28, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description 
 **  |------------|----------|-------------------------------- 
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
#ifndef SRC_DKOSALRECURSIVEMUTEX_H_
#define SRC_DKOSALRECURSIVEMUTEX_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \include      cstdint
                 header_files Dependancy_headers
 * \brief        The module shall use **cstdint** (standard datatype inclusion)data types.
 * \addtogroup   header_files
 */
#include <cstdint>                /* standard datatype inclusion   */
/*!
 * \include      pthread.h
 * \brief        For pthread related inclusions 
 */
#include <pthread.h>              /* for pthread related inclusions */

namespace dk
{

namespace osal
{

/** 
 * \class   RecursiveMutex
 * \brief   OsalRecursiveMutex shall abstract the recrursivemutex functions to lokc the process/thread in recursive manner
 * \details requirement ID 751537
 */
class RecursiveMutex
{
    public:
        /** 
         * \fn      RecursiveMutex()
         * \brief   Construct a new RecursiveMutex
         * \details requirement ID 751537
         */
        RecursiveMutex();
        /** 
         * \fn      RecursiveMutex()
         * \brief   Destruct a RecursiveMutex
         * \details requirement ID 751537
         */
        ~RecursiveMutex();

        /** 
         * \fn      tryLock()
         * \brief   Try to lock the RecursiveMutex,
         *          The RecursiveMutex is locked if it is not locked by another user.
         * \return <b>true</b> lock acquired
         *         <b>false</b> lock is held by another user.
         * \details requirement ID 751580
         */
        bool tryLock();

        /**
         * \fn       timedLockMS ( const uint32_t msec ) 
         * \brief    The RecursiveMutex. (Waits for a timeout)
         *           Blocks the current thread until the lock is acquired, or the specified timeout milliseconds duration interval elapsed.
         * \param    msec The number of milliseconds to wait before the lock() is cancelled
         * \return   <b>true</b> lock acquired
         *           <b>false</b> timeout happened
         * \details  requirement ID 751581
         */
        bool timedLockMS ( const uint32_t msec );

        /** 
         * \fn      timedLockUS ( const uint32_t usec )
         * \brief   Lock the RecursiveMutex. (Waits for a timeout)
         *          Blocks the current thread until the lock is acquired, or the specified timeout  microseconds duration interval elapsed.
         * \param   usec The number of microseconds to wait before the lock() is cancelled
         * \return  <b>true</b> lock acquired
         *          <b>false</b> timeout happened
         * \details requirement ID 751582
         */
        bool timedLockUS ( const uint32_t usec );

         /** 
         * \fn      void lock()
         * \brief   lock the RecursiveMutex.
         *          BLocks the current thread until the lock is acquired.
         * \details requirement ID 751580
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        void lock();

        /** 
         * \fn      void unlock()
         * \brief   unlocks the RecursiveMutex.
         *          OsalMutex component shall provide APIs to unlock the critical section
         * \details requirement ID 751583
         */
        void unlock();

    private:
        /**
         * \fn    RecursiveMutex ( const RecursiveMutex & )
         * \brief Disable Copy constructor and Assignment operator on RecursiveMutex
         */
        RecursiveMutex ( const RecursiveMutex & ) = delete;
        RecursiveMutex &operator= ( const RecursiveMutex & ) = delete;

        /** 
         * \fn      init()
         * \brief   Initialize the RecursiveMutex
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

#endif /* SRC_DKOSALRECURSIVEMUTEX_H_ */
