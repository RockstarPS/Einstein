/**********************************************************************************
 **
 **  \file RecursiveMutex.cpp
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
/* Related Header file */
#ifdef _WIN32
#include <unistd.h>            /* added for windows build to enable CLOCK_REALTIME*/
#endif
/*!
 * \include      DKOsalRecursiveMutex.h
 *  other library includes 
 *  project includes 
 * \brief        For RecursiveMutex class inclusion,
 *               access to SYNCHRONIZED macro
 */
#include "DKOsalRecursiveMutex.h"
/* C Library includes */
/* C++ Library includes */
#include <cstring>                           /* for string related functions       */
#include <cerrno>                            /* for errno such as EBUSY, ETIMEDOUT */
/*!
 * \include      DKOsalClock.h
 * \brief        Contains the Header File Version ID of dk_osalclock
 */
#include "DKOsalClock.h"                     /* for Clock related functionality */
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"     

namespace dk
{

namespace osal
{

/***********************************************************************************************************
 START OF PUBLIC MEMBER FUNCTIONS 
 ***********************************************************************************************************/
/** 
 * \fn      RecursiveMutex()
 * \brief   Construct a new RecursiveMutex
 * \details requirement ID 751537
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
RecursiveMutex::RecursiveMutex()
{
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::RecursiveMutex() constructor (this = %p)\n", this );
    init();
}

/** 
 * \fn      RecursiveMutex()
 * \brief   Destruct a RecursiveMutex
 * \details requirement ID 751537
 */
RecursiveMutex::~RecursiveMutex()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::~RecurvsiveMutex() destructor (this = %p)\n", this );

    ret = pthread_mutex_destroy ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::~RecursiveMutex() : pthread_mutex_destory() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_MUTEX,
            "RecursiveMutex::~RecursiveMutex() : pthread_mutex_destroy() success (this = %p)\n", this );
}

/** 
 * \fn      tryLock()
 * \brief   Try to lock the RecursiveMutex,
 *          The RecursiveMutex is locked if it is not locked by another user.
 * \return <b>true</b> lock acquired
 *         <b>false</b> lock is held by another user.
 * \details requirement ID 751580
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool RecursiveMutex::tryLock()
{
    int32_t ret;
    bool result;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::tryLock() (this = %p)\n", this );

    ret = pthread_mutex_trylock ( &mMutex );

    if ( ret != 0 )
    {
        if ( ret != EBUSY )
        {
            OSAL_ERR ( OSAL_SCOPE_MUTEX,
                    "RecursiveMutex::tryLock() : pthread_mutex_trylock() failed error = %d [%s] (this = %p)\n",
                    ret, strerror ( ret ), this );
            OSAL_ABORT()
            ;
        }

        result = false;
    }
    else
    {
        result = true;
        OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::tryLock() success (this = %p)\n", this );
    }

    return ( result );
}

/**
 * \fn       timedLockMS ( const uint32_t msec ) 
 * \brief    The RecursiveMutex. (Waits for a timeout)
 *           Blocks the current thread until the lock is acquired, or the specified timeout milliseconds duration interval elapsed.
 * \param    msec The number of milliseconds to wait before the lock() is cancelled
 * \return   <b>true</b> lock acquired
 *           <b>false</b> timeout happened
 * \details  requirement ID 751581,751571
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool RecursiveMutex::timedLockMS ( const uint32_t msec )
{
    int32_t ret;
    bool result;
    timespec ts;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::timedLockMS(%lu) (this = %p)\n", msec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockMS(%d) : clock_getime() failed error = %d [%s] (this = %p)\n",
                msec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    Clock::addTimeOffsetMS ( msec, ts );
    ret = pthread_mutex_timedlock ( &mMutex, &ts );

    if ( ret == 0 )
    {
        result = true;
    }
    else if ( ret != ETIMEDOUT )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockMS(%d) : pthread_mutex_timedlock() failed error = %d [%s] (this = %p)\n",
                msec, ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockMS(%lu) : pthread_mutex_timedlock() TIMEOUT (this = %p)\n",
                msec, this );
    }

    return result;
}

/** 
 * \fn      timedLockUS ( const uint32_t usec )
 * \brief   Lock the RecursiveMutex. (Waits for a timeout)
 *          Blocks the current thread until the lock is acquired, or the specified timeout  microseconds duration interval elapsed.
 * \param   usec The number of microseconds to wait before the lock() is cancelled
 * \return  <b>true</b> lock acquired
 *          <b>false</b> timeout happened
 * \details requirement ID 751582,751571
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool RecursiveMutex::timedLockUS ( const uint32_t usec )
{
    int32_t ret;
    bool result;
    timespec ts;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::timedLockUS(%lu) (this = %p)\n", usec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockUS(%d) : clock_getime() failed error = %d [%s] (this = %p)\n",
                usec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    Clock::addTimeOffsetUS ( usec, ts );
    ret = pthread_mutex_timedlock ( &mMutex, &ts );

    if ( ret == 0 )
    {
        result = true;
    }
    else if ( ret != ETIMEDOUT )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockUS(%d) : pthread_mutex_timedlock() failed error = %d [%s] (this = %p)\n",
                usec, ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::timedLockUS(%lu) : pthread_mutex_timedlock() TIMEOUT (this = %p)\n",
                usec, this );
    }

    return result;
}

/** 
 * \fn      void lock()
 * \brief   lock the RecursiveMutex.
 *          BLocks the current thread until the lock is acquired.
 * \details requirement ID 751580,751534
 */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
void RecursiveMutex::lock()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::lock() (this = %p)\n", this );
    ret = pthread_mutex_lock ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::lock() : pthread_mutex_lock() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_MUTEX,
            "RecursiveMutex::lock() : pthread_mutex_lock() acquired successfully (this = %p)\n", this );
}

/** 
 * \fn      void unlock()
 * \brief   unlocks the RecursiveMutex.
 *          OsalMutex component shall provide APIs to unlock the critical section
 * \details requirement ID 751583
 */
void RecursiveMutex::unlock()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::unlock() (this = %p)\n", this );

    ret = pthread_mutex_unlock ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::unlock() : pthread_mutex_unlock() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_MUTEX,
            "RecursiveMutex::unlock() : pthread_mutex_unlock() released successfully (this = %p)\n",
            this );
}
/* END OF PUBLIC MEMBER FUNCTIONS */

/* START OF PRIVATE MEMBER FUNCTIONS */

/** 
 * \fn      init()
 * \brief   Initialize the RecursiveMutex
 * \details requirement ID 751559
 */
void RecursiveMutex::init()
{
    pthread_mutexattr_t attr;
    int32_t ret;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::init() (this = %p)\n", this );

    ret = pthread_mutexattr_init ( &attr );

    if ( ret == 0 )
    {
        ret = pthread_mutexattr_settype ( &attr, PTHREAD_MUTEX_RECURSIVE );
    }

    if ( ret == 0 )
    {
        ret = pthread_mutexattr_setpshared ( &attr, PTHREAD_PROCESS_PRIVATE );
    }

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::init() : setting attributes failed error = %d [%s] (this = %p)\n", ret,
                strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    ret = pthread_mutex_init ( &mMutex, &attr );

    (void) pthread_mutexattr_destroy ( &attr );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "RecursiveMutex::init() : pthread_mutex_init() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "RecursiveMutex::init() success (this = %p)\n", this );
}

/** 
 * \fn      pthread_mutex_t *getPthreadMutex()   
 * \brief   Get pointer to internal pthread_mutex
 * \details requirement ID 751534
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
pthread_mutex_t *RecursiveMutex::getPthreadMutex()
{
    /* coverity[misra_cpp_2008_rule_9_3_2_violation] : FALSE */
    return ( &mMutex );
}
/* END OF PRIVATE MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
