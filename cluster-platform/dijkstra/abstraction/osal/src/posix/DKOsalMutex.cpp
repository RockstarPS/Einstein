/**********************************************************************************
 **
 **  \file Mutex.cpp
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
/* Related Header file */
#ifdef _WIN32
/*!
 * \include      unistd.h
 *               header_files Dependancy_headers 
 * \brief        The module shall added for the VS2015 compilation
 */
#include <unistd.h>					
#endif
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*!
 * \include      DKOsalMutex.h
 *  other library includes 
 *  project includes 
 * \brief        access to SYNCHRONIZED macro
 */
#include "DKOsalMutex.h"
/*!
 * \include      cstring
 * C Library includes 
 * C++ Library includes
 * \brief        For string related functions
 */
#include <cstring>                     
/*!
 * \include      cerrno
 * \brief        for errno such as EBUSY, ETIMEDOUT  
 */
#include <cerrno>  
/*!
 * \include      DKOsalClock.h
 * \brief        For Clock related functionality 
 * Contains the Header File Version ID of dk_osalclock
 */
#include "DKOsalClock.h"                    
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

/*************************************************************************************************** 
* START OF PUBLIC MEMBER FUNCTIONS 
******************************************************************************************************/

/** 
 * \fn      Mutex()
 * \brief   Construct a new Mutex
 * \details requirement ID 751559,751534
 */
Mutex::Mutex()
{
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::Mutex() constructore (this = %p)\n", this );
    init();
}
/** 
 * \fn      ~Mutex()
 * \brief   Destructor.
 * Note that destroying a locked mutex can lead to deadlock.
 * \details requirement ID 751559,751534
 */
Mutex::~Mutex()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::~Mutex() (this = %p)\n", this );

    ret = pthread_mutex_destroy ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "Mutex::~Mutex(): pthread_mutex_destroy() failed error = %d [%s] (this = %p)\n", ret,
                strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
}
/** 
 * \fn      tryLock()
 * \brief   Try to lock the Mutex,
 *          The Mutex is locked if it is not locked by another user.
 * \return <b>true</b> lock acquired
 *         <b>false</b> lock is held by another user.
 * \details requirement ID 751560
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Mutex::tryLock()
{
    int32_t ret;
    bool result;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::tryLock() (this = %p)\n", this );

    ret = pthread_mutex_trylock ( &mMutex );

    if ( ret != 0 )
    {
        if ( ret != EBUSY )
        {
            OSAL_ERR ( OSAL_SCOPE_MUTEX,
                    "Mutex::tryLock() : pthread_mutex_trylock() failed error = %d [%s] (this = %p)\n",
                    ret, strerror ( ret ), this );
            OSAL_ABORT()
            ;
        }
        else
        {
            OSAL_WARN ( OSAL_SCOPE_MUTEX,
                    "Mutex::tryLock() : pthread_mutex_trylock() failed Mutex is already locked (this = %p)\n",
                    this );
        }

        result = false;
    }
    else
    {
        result = true;
        OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::tryLock() success (this = %p)\n", this );
    }

    return result;
}

/**
 * \fn       timedLockMS ( const uint32_t msec ) 
 * \brief    The Mutex. (Waits for a timeout)
 *           Blocks the current thread until the lock is acquired, or the specified timeout milliseconds duration interval elapsed.
 * \param    msec The number of milliseconds to wait before the lock() is cancelled
 * \return   <b>true</b> lock acquired
 *           <b>false</b> timeout happened
 * \details  requirement ID 751561
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Mutex::timedLockMS ( const uint32_t msec )
{
    int32_t ret;
    timespec ts;
    bool result;

    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::timedLockMS(timeout = %lu) (this = %p)\n", msec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "Mutex::timedLockMS(%d) : clock_gettime() failed error = %d [%s] (this = %p)\n", msec,
                errno, strerror ( errno ), this );
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
                "Mutex::timedLockMS(%d) : pthread_mutex_timedlock() failed error = %d [%s] (this = %p)\n",
                msec, ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_MUTEX,
                "Mutex::timedLockMS(%lu) : pthread_mutex_timedlock() TIMEDOUT (this = %p)\n", msec,
                this );
    }

    return result;
}

/** 
 * \fn      timedLockUS ( const uint32_t usec )
 * \brief   Lock the Mutex. (Waits for a timeout)
 *          Blocks the current thread until the lock is acquired, or the specified timeout  microseconds duration interval elapsed.
 * \param   usec The number of microseconds to wait before the lock() is cancelled
 * \return  <b>true</b> lock acquired
 *          <b>false</b> timeout happened
 * \details requirement ID 751562
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Mutex::timedLockUS ( const uint32_t usec )
{
    int32_t ret;
    timespec ts;
    bool result;

    result = false;

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::timedLockUS(timeout = %lu) (this = %p)\n", usec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "Mutex::timedLockUS(%d) : clock_gettime() failed error = %d [%s] (this = %p)\n", usec,
                errno, strerror ( errno ), this );
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
                "Mutex::timedLockUS(%d) : pthread_mutex_timedlock() failed error = %d [%s] (this = %p)\n",
                usec, ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_MUTEX,
                "Mutex::timedLockUS(%lu) : pthread_mutex_timedlock() TIMEDOUT (this = %p)\n", usec,
                this );
    }

    return result;
}
/** 
 * \fn      void lock()
 * \brief   lock the mutex.
 *          OsalMutex component shall provide APIs to lock the critical section using mutex lock functionality
 * \details requirement ID 751563
 */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
void Mutex::lock()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::lock() (this = %p)\n", this );

    ret = pthread_mutex_lock ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX, "Mutex::lock() : pthread_mutex_lock() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::lock() acquired (this = %p)\n", this );

}


/** 
 * \fn      void unlock()
 * \brief   unlocks the mutex.
 *          OsalMutex component shall provide APIs to unlock the critical section
 * \details requirement ID 751564
 */
void Mutex::unlock()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_MUTEX, "Mutex::unlock() (this = %p)\n", this );
    ret = pthread_mutex_unlock ( &mMutex );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX,
                "Mutex::unlock() : pthread_mutex_unlock() failed error = %d [%s] (this = %p)\n", ret,
                strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* START OF PRIVATE MEMBER FUNCTIONS */
/** 
 * \fn      init()
 * \brief   Initialize the Mutex
 * \details requirement ID 751559
 */
void Mutex::init()
{
    pthread_mutexattr_t attr;
    int32_t ret;

    ret = pthread_mutexattr_init ( &attr );

    if ( ret == 0 )
    {
        ret = pthread_mutexattr_settype ( &attr, PTHREAD_MUTEX_ERRORCHECK );
    }

    if ( ret == 0 )
    {
        ret = pthread_mutexattr_setpshared ( &attr, PTHREAD_PROCESS_PRIVATE );
    }

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX, "Mutex::init() setting attributes failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }

    ret = pthread_mutex_init ( &mMutex, &attr );
    (void) pthread_mutexattr_destroy ( &attr );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_MUTEX, "Mutex::init() : pthread_mutex_init() failed error = %d [%s] (this = %p)\n",
                ret, strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
}


/** 
 * \fn      pthread_mutex_t *getPthreadMutex()   
 * \brief   Get pointer to internal pthread_mutex
 * \details requirement ID 751534
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
pthread_mutex_t *Mutex::getPthreadMutex()
{
    /* coverity[misra_cpp_2008_rule_9_3_2_violation] : FALSE */
    return ( &mMutex );
}
/*END OF PRIVATE MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
