/**********************************************************************************
 **
 **  \file Semaphore.cpp
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
 **********************************************************************************************************************/ 

/* Related Header file */
#ifdef _WIN32
#include <unistd.h>            /* added for windows build to enable CLOCK_REALTIME*/
#endif
/**********************************************************************************************************************
 * INCLUDE
 **********************************************************************************************************************/ 
/*!
 * \include      semaphore.h
 *               header_files Dependancy_headers
 * \brief        For sem_t inclusion
 */
#include "DKOsalSemaphore.h"
/* C Library includes */
/* C++ Library includes */
#include <cstring>                   /* for string related functions */
#include <cerrno>                    /* for errno such as EBUSY, ETIMEDOUT */
/*!
 * \include      DKOsalClock.h
 * \brief        Contains the Header File Version ID of dk_osalclock
 *               For Clock related functionality
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

/******************************************************************************************************************* 
START OF PUBLIC MEMBER FUNCTIONS 
*******************************************************************************************************************/
/** 
 * \fn      Semaphore ( const uint32_t counter ) 
 * \brief   Constructor. 
 * \param   counter Initial value of the semaphore counter.
 * \details requirement ID 751538,751584
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Semaphore::Semaphore ( const uint32_t counter )
{
    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::Semaphore(%lu) constructor (this = %p)\n", counter, this );
    init ( counter );
}

/** 
 * \fn      ~Semaphore() 
 * \brief   Destructor. 
 * \param   counter Initial value of the semaphore counter.
 * \details requirement ID 751538,751584
 */
Semaphore::~Semaphore()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::~Semaphore() destructor (this = %p)\n", this );

    ret = sem_destroy ( &mSemaphore );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM,
                "Semaphore::~Semaphore() : sem_destroy() failed error = %d [%s] (this = %p)\n", errno,
                strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::~Semaphore() : sem_destroy() success (this = %d)\n", this );
}

/** 
 * \fn      bool tryWait()
 * \brief   Try to wait for a semaphore
 *          If the counter is greater than "0", it will be decremented by "1"
 * \return  <b>true</b> semaphore counter greater thann "0"
 *          <b>false</b> semaphore counter is "0"
 * \details requirement ID 751585
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Semaphore::tryWait()
{
    int32_t ret;
    bool result;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::tryWait() (this = %p)\n", this );

    ret = sem_trywait ( &mSemaphore );

    if ( ret == 0 )
    {
        result = true;
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    else if ( errno != EBUSY )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM, "Semaphore::tryWait() : sem_tryWait() failed error = %d [%s] (this = %p)\n",
                errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::tryWait() : sem_tryWait() TIMEDOUT (this = %p)\n", this );
    }

    return result;
}

/** 
 * \fn      bool timedWaitMS ( const uint32_t msec )
 * \brief   Blocks the current thread until the semaphore counter is greater than "0", and then decrements
 *          the counter by "1". If the specified timeout interval elapses, the function is cancelled.
 * \param   msec number of milliseconds to wait before the wait() is cancelled
 * \return  <b>true</b> semaphore counter is greater than "0"
 *          <b>false</b> a timeout occurred
 * \details requirement ID 751586
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Semaphore::timedWaitMS ( const uint32_t msec )
{
    int32_t ret;
    bool result;
    timespec ts;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::timedWaitMS(%lu) (this = %o)\n", msec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM,
                "Semaphore::timedWaitMS(%u) : clock_gettime() failed error = %d [%s] (this = %p)\n",
                msec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    Clock::addTimeOffsetMS ( msec, ts );

    do
    {
        ret = sem_timedwait ( &mSemaphore, &ts );
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    while ( ( ret != 0 ) && ( errno == EINTR ) );

    if ( ret == 0 )
    {
        result = true;
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    else if ( errno != ETIMEDOUT )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM,
                "Semaphore::timedWaitMS(%u) : sem_timedwait() failed error = %d [%s] (this = %p)\n",
                msec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::timedWaitMS(%lu) : sem_timedwait() TIMEDOUT (this = %p)\n", msec,
                this );
    }

    return result;
}

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
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Semaphore::timedWaitUS ( const uint32_t usec )
{
    int32_t ret;
    bool result;
    timespec ts;
    result = false;

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::timedWaitUS(%lu) (this = %o)\n", usec, this );

    ret = clock_gettime ( CLOCK_REALTIME, &ts );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM,
                "Semaphore::timedWaitUS(%u) : clock_gettime() failed error = %d [%s] (this = %p)\n",
                usec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    Clock::addTimeOffsetUS ( usec, ts );

    do
    {
        ret = sem_timedwait ( &mSemaphore, &ts );
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    while ( ( ret != 0 ) && ( errno == EINTR ) );

    if ( ret == 0 )
    {
        result = true;
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    else if ( errno != ETIMEDOUT )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM,
                "Semaphore::timedWaitUS(%u) : sem_timedwait() failed error = %d [%s] (this = %p)\n",
                usec, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }
    else
    {
        OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::timedWaitUS(%lu) : sem_timedwait() TIMEDOUT (this = %p)\n", usec,
                this );
    }

    return result;
}

/** 
 * \fn      void wait()
 * \brief   Semaphore wait operation
 *          Blocks the current thread until the semaphore is greater than "0", and then decrements the counter by "1"
 * \details requirement ID 751588
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Semaphore::wait()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::wait() (this = %p)\n", this );

    do
    {
        ret = sem_wait ( &mSemaphore );
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    while ( ( ret != 0 ) && ( errno == EINTR ) );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM, "Semaphore::wait() failed error = %d [%s] (this = %p)\n", errno,
                strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }
}

/** 
 * \fn      void post()
 * \brief   Semaphore post operation
 *          Increments the semaphore counter by "1" and then notifies the waiting threads.
 * \details requirement ID 751589
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Semaphore::post()
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::post() (this = %p)\n", this );

    ret = sem_post ( &mSemaphore );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM, "Semaphore::post() failed error = %d [%s] (this = %p)\n", ret,
                strerror ( ret ), this );
        OSAL_ABORT()
        ;
    }
}

/** 
 * \fn      uint32_t value()
 * \brief   Get counter value of semaphore
 * \return  current counter value
 * \details requirement ID 751590
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
uint32_t Semaphore::value()
{
    int32_t ret;
    int32_t value;
    value = 0;

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::value() (this = %p)\n", this );

    ret = sem_getvalue ( &mSemaphore, &value );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM, "Semaphore::value() failed error = %d [%s] (this = %p)\n", errno,
                strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    if ( value < 0 )
    {
        value = 0;
    }

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::value() returns value = %lu\n", value );
    return static_cast<uint32_t>( value );
}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* START OF PRIVATE MEMBER FUNCTIONS */
/** 
 * \fn      void init ( const uint32_t counter )
 * \brief   Initialize the Semaphore
 * \details requirement ID 751591
 */
/* coverity[misra_cpp_2008_rule_2_10_5_violation] : FALSE */
void Semaphore::init ( const uint32_t counter )
{
    int32_t ret;
    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::init(%lu) (this = %p)\n", counter, this );
    ret = sem_init ( &mSemaphore, 0, counter );

    if ( ret != 0 )
    {
        OSAL_ERR ( OSAL_SCOPE_SEM, "Semaphore::init(%u) : sem_init() failed error = %d [%s] (this = %p)\n",
                counter, errno, strerror ( errno ), this );
        OSAL_ABORT()
        ;
    }

    OSAL_DBG ( OSAL_SCOPE_SEM, "Semaphore::init(%lu) : sem_init() success (this = %p)\n", counter, this );
}
/* END OF PRIVATE MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
