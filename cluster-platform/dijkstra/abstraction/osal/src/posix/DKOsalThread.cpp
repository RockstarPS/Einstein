/**********************************************************************************
 **
 **  \file Thread.cpp
 **
 **  Created on: Apr 11, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                           
 **  |------------|----------|--------------------------------                          
 **  | 2017-04-11 | VMUTHUSU | Create Initial Module.
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
#include "DKOsalThread.h"
/* C Library includes */
#include <unistd.h>                   /* for getpid() inclusion for linux build */
#include <pthread.h>                  /* for pthread related inclusions */
/* C++ Library includes */
#include <cstring>                    /* for string related functions */
#include <cerrno>
/*!
 * \include      DKOsalMutexLock.h
 *  other library includes 
 *  project includes 
 * \brief        For Mutex Class inclusion,
 *               access to SYNCHRONIZED macro
 */
#include "DKOsalMutexLock.h"          /* access to SYNCHRONIZED macro */
/*!
 * \include      DKOsalTrace.h
 *  other library includes 
 *  project includes 
 * \brief        For OSAL_DBG inclusion
 */
#include "DKOsalTrace.h"              /* for OSAL_DBG inclusion */

namespace dk
{

namespace osal
{

/* START OF PUBLIC MEMBER FUNCTIONS */
/** 
 * \fn      Thread ( IRunnable *runnable, bool isDetached = false )  
 * \brief   Construct a new Thread with a IRunnable object
 * \param   runnable The IRunnable object whose <b>run()</b> method will be executed in this thread.
 * \param   isDetached A flag indicating whether the thread will be created in a detached state.
 * \details requirement id 751552
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_7_1_1_violation] : FALSE */
Thread::Thread ( IRunnable *runnable, const bool isDetached )
    :
    mThreadID()
    ,
    mMutex()
    ,
    mRunnable ( runnable )
    ,
    mNeedsJoin ( false )
    ,
    mActive ( false )
    ,
    mThreadName()
    ,
    mDetached ( isDetached )
    ,
    mResult ( NULL )
{
    (void) pthread_attr_init ( &mThreadAttribute );
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::Thread(runnable = %p,isDetached = %d) (this = %p)\n", runnable, isDetached,
            this );
}
/** 
 * \fn      Thread ( bool isDetached = false ) 
 * \brief   construct a new thread object
 * \param   isDetached A flag indicating whether the thread will be created in a detached state.
 * \details requirement id 751552
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
Thread::Thread ( const bool isDetached )
    :
    mThreadID()
    ,
    mMutex()
    ,
    mRunnable ( NULL )
    ,
    mNeedsJoin ( false )
    ,
    mActive ( false )
    ,
    mThreadName()
    ,
    mDetached ( isDetached )
    ,
    mResult ( NULL )
{
    (void) pthread_attr_init ( &mThreadAttribute );
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::Thread(isDetached = %d) (this = %p)\n", isDetached, this );
}
/** 
 * \fn      Thread ( bool isDetached = false ) 
 * \brief   Destructor for the Thread class
 * \param   isDetached A flag indicating whether the thread will be created in a detached state.
 * \details requirement id 751552
 */
Thread::~Thread()
{
    // TODO Auto-generated destructor stub
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::~Thread() destructor this = %p\n", this );

    if ( isRunning() )
    {
        cancel();
        (void) join();
    }
}
/**
 * \fn       void start ( ThreadConfigID id )
 * \brief    Start Executing the thread.
 *           If a IRunnable object was supplied in the constructor, its <b>run()</b> method is invoked;
 *           otherwise the thread object's <b>run()</b> method is called.If the thread is already running
 *           the call has no effect.
 *
 * \param id ID for thread parameter configuration
 * \details requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Thread::start ( ThreadConfigID const id )
{    
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::start(%p, \"%s\") (this = %p)\n", mRunnable, ( id ? id : "null" ),
            this );

    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        if ( mActive )
        {
            OSAL_WARN ( OSAL_SCOPE_THREAD, "Thread::start() thread already started. (this = %p)\n", this );
        }
        else
        {
            int64_t status;
            status = pthread_attr_setscope ( &mThreadAttribute, PTHREAD_SCOPE_SYSTEM );

            if ( 0 != status )
            {
                OSAL_ERR ( OSAL_SCOPE_THREAD,
                        "Thread::start(id = %s):pthread_attr_setscope(PTHREAD_SCOPE_SYSTEM) failed, error = %d [%s] (this = %p)\n",
                        id, errno, strerror ( errno ), this );
                OSAL_ABORT()
                ;
            }

            if ( !mDetached )
            {
                if ( NULL == mRunnable )
                {
                    /* coverity[cert_exp60_cpp_violation] : FALSE */
                    /* coverity[cert_exp56_cpp_violation] : FALSE */
                    status = pthread_create ( &mThreadID, &mThreadAttribute, &Thread::startThread,
                                    ( void * ) this );

                    if ( 0 != status )
                    {
                        OSAL_ERR ( OSAL_SCOPE_THREAD,
                                "Thread::start(id=%s):pthread_create(Thread::startThread()) failed, error = %d [%s] (this = %p)\n",
                                id, errno, strerror ( errno ), this );
                        OSAL_ABORT()
                        ;
                    }
                    else
                    {
                        mNeedsJoin = true;
                        mActive = true;
                    }

                    OSAL_DBG ( OSAL_SCOPE_THREAD,
                            "Thread::start(id=%s):pthread_create(Thread::startThread()) success (this = %p)\n",
                            id, this );
                }
                else
                {
                    /* coverity[cert_exp60_cpp_violation] : FALSE */
                    /* coverity[cert_exp56_cpp_violation] : FALSE */
                    status = pthread_create ( &mThreadID, &mThreadAttribute, &Thread::startThreadRunnable,
                                    ( void * ) this );

                    if ( 0 != status )
                    {
                        OSAL_ERR ( OSAL_SCOPE_THREAD,
                                "Thread::start(id=%s):pthread_create(Thread::startThreadRunnable()) failed, error = %d [%s] (this = %p)\n",
                                id, errno, strerror ( errno ), this );
                        OSAL_ABORT()
                        ;
                    }
                    else
                    {
                        mNeedsJoin = true;
                        mActive = true;
                    }

                    OSAL_DBG ( OSAL_SCOPE_THREAD,
                            "Thread::start(id=%s):pthread_create(Thread::startThreadRunnable()) failed, error = %d [%s] (this = %p)\n",
                            id, errno, strerror ( errno ), this );
                }
            }
            else
            {
                status = pthread_attr_setdetachstate ( &mThreadAttribute, PTHREAD_CREATE_DETACHED );

                if ( 0 != status )
                {
                    OSAL_ERR ( OSAL_SCOPE_THREAD,
                            "Thread::start(id=%s):pthread_attr_setdetachstate(PTHREAD_CREATE_DETACHED) failed, error = %d [%s] (this = %p)\n",
                            id, errno, strerror ( errno ), this );
                    OSAL_ABORT()
                    ;
                }

                OSAL_DBG ( OSAL_SCOPE_THREAD,
                        "Thread::start(id=%s):pthread_attr_setdetachstate(PTHREAD_CREATE_DETACHED) success (this = %p) \n",
                        id, this );

                if ( NULL == mRunnable )
                {
                    /* coverity[cert_exp60_cpp_violation] : FALSE */
                    /* coverity[cert_exp56_cpp_violation] : FALSE */
                    status = pthread_create ( &mThreadID, &mThreadAttribute, &Thread::startThread,
                                    ( void * ) this );

                    if ( 0 != status )
                    {
                        OSAL_ERR ( OSAL_SCOPE_THREAD,
                                "Thread::start(id=%s):pthread_create(Thread::startThread()) failed, error = %d [%s] (this = %p)\n",
                                id, errno, strerror ( errno ), this );
                        OSAL_ABORT()
                        ;
                    }
                    else
                    {
                        mActive = true;
                    }

                    OSAL_DBG ( OSAL_SCOPE_THREAD,
                            "Thread::start(id=%s):pthread_create(Thread::startThread()) success (this = %p)\n",
                            id, this );
                }
                else
                {
                    /* coverity[cert_exp60_cpp_violation] : FALSE */
                    /* coverity[cert_exp56_cpp_violation] : FALSE */
                    status = pthread_create ( &mThreadID, &mThreadAttribute, &Thread::startThreadRunnable,
                                    ( void * ) this );

                    if ( 0 != status )
                    {
                        OSAL_ERR ( OSAL_SCOPE_THREAD,
                                "Thread::start(id=%s):pthread_create(Thread::startThreadRunnable()) failed, error = %d [%s] (this = %p)\n",
                                id, errno, strerror ( errno ), this );
                        OSAL_ABORT()
                        ;
                    }
                    else
                    {
                        mActive = true;
                    }

                    OSAL_DBG ( OSAL_SCOPE_THREAD,
                            "Thread::start(id=%s):pthread_create(Thread::startThreadRunnable()) failed, error = %d [%s] (this = %p)\n",
                            id, errno, strerror ( errno ), this );
                }
            }

            status = pthread_attr_destroy ( &mThreadAttribute );

            if ( 0 != status )
            {
                OSAL_ERR ( OSAL_SCOPE_THREAD,
                        "Thread::start(id=%s):pthread_destroy() failed error = %d [%s] (this = %p)\n",
                        id, errno, strerror ( errno ), this );
                OSAL_ABORT()
                ;
            }

            OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::start(id=%s):pthread_destroy() success (this = %p)\n", id,
                    this );
        }
    }
}
/**
 * \fn       void cancel()
 * \brief    stops this thread.
 * \details  requirement id 751555
 */
void Thread::cancel()
{
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::cancel() (this = %p)\n", this );
    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        if ( mActive )
        {
            const int64_t status = pthread_cancel ( mThreadID );

            if ( 0 != status )
            {
                OSAL_ERR ( OSAL_SCOPE_THREAD, "Thread::cancel() failed, errno = %d [%s] (this = %p)\n", errno,
                        strerror ( errno ), this );
                OSAL_ABORT()
                ;
            }
        }
    }
}
/**
 * \fn       void *join()
 * \brief    Wait for the thread to terminate
 * \details  requirement id 751555
 */
void *Thread::join()
{
    bool needsJoin = false;
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::join() (this = %p)\n", this );

    /* A thread calling T.join() waits until thread T completes */
    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        needsJoin = mNeedsJoin;
        mNeedsJoin = false;
    }

    if ( needsJoin )
    {
        int64_t status;
        status = pthread_join ( mThreadID, NULL );

        /* result was already saved by thread start function */
        if ( 0 != status )
        {
            OSAL_ERR ( OSAL_SCOPE_THREAD, "Thread::join() failed error = %d [%s] (this = %p)\n", errno,
                    strerror ( errno ), this );
            OSAL_ABORT()
            ;
        }
        else
        {
            /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
            SYNCHRONIZED ( mMutex )
            {
                mActive = false;
            }
        }
    }
    else
    {
        OSAL_WARN ( OSAL_SCOPE_THREAD, "Thread::join() no thread to join (this = %p)\n", this );
    }

    return mResult;
}
/** 
 * \fn     void setName ( const std::string &name ) 
 * \brief  Set the name of this thread
 * \param  name thread name to be set
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Thread::setName ( const std::string &name )
{
    mThreadName = name;
    /* NON-POSIX API needs further study */
    (void) pthread_setname_np ( mThreadID, mThreadName.c_str() );
}
/** 
 * \fn      std::string getName() const
 * \brief   Get the name of this thread
 * \return  name of the thread.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
std::string Thread::getName() const
{
    return ( mThreadName );
}
/** 
 * \fn       static void exit()
 * \brief    Terminate the calling thread.
 *           If called from the main thread, this function will block until all other threads
 *           are finished.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
void Thread::exit()
{
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::exit()\n" );
    pthread_exit ( NULL );
}
/** 
 * \fn       uint32_t Thread::currentThreadId()
 * \brief    Get the Thread id (TID) from the calling thread
 * \return   the thread id.
 * \details  requirement id 751555
 */
uint32_t Thread::currentThreadId()
{
#ifdef _WIN32   
    return ( uint32_t ) ::gettid(); /*added to compile with VS2015*/ 
#else   
    return  static_cast<uint32_t>(::pthread_self());
 #endif   
}
/** 
 * \fn         uint32_t Thread::currentProcessId()
 * \brief      Get the process id (PID) from the current process.
 * \return     the process id.
 * \details    requirement id 751555
 */
uint32_t Thread::currentProcessId()
{
    return static_cast<uint32_t>( ::getpid() );
}

/** 
 * \fn       static void sleepMS ( const uint32_t msec )
 * \brief    Blocks the calling thread for the specified time.
 * \param    msec the time to sleep in milliseconds
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Thread::sleepMS ( const uint32_t msec )
{
    struct timespec ts;
    int64_t ret;

    /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
    ts.tv_sec = msec / 1000U;
    ts.tv_nsec = ( msec % 1000U ) * 1000000U;

    do
    {
        ret = ::nanosleep ( &ts, &ts );
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    while ( ( ret != 0 ) && ( errno == EINTR ) );

}
/** 
 * \fn       static void sleepUS ( const uint32_t usec )
 * \brief    Blocks the calling thread for the specified time.
 * \param    nusec the time to sleep in microseconds.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
void Thread::sleepUS ( const uint32_t usec )
{
    struct timespec ts;
    int64_t ret;

    /* coverity[misra_cpp_2008_rule_5_0_3_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_0_4_violation] : FALSE */
    ts.tv_sec = usec / 1000000U;
    ts.tv_nsec = ( usec % 1000000U ) * 1000U;

    do
    {
        ret = ::nanosleep ( &ts, &ts );
    }
    /* coverity[misra_cpp_2008_rule_19_3_1_violation] : FALSE */
    while ( ( ret != 0 ) && ( errno == EINTR ) );
}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* START OF PROTECTED MENBER FUNCTIONS */
/** 
 * \fn       virtual void *run() 
 * \brief    Main function.
 *           Thread execution begins in this function. The default implementation does nothing.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_7_1_2_violation] : FALSE */
void *Thread::run()
{
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::run() (this = %p)\n", this );
    return NULL;
}

 /** 
 * \fn       virtual void cleanup() 
 * \brief    Cleanup function.
 *           This function will be executed by the thread just prior to termination. The default
 *           implementation is a no-operation.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_7_1_2_violation] : FALSE */
void Thread::cleanup()
{
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::cleanup() (this = %p)\n", this );
}

/** 
 * \fn       void yield() 
 * \brief    Yield the CPU to another thread with same priority.
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_9_3_3_violation] : FALSE */
/* coverity[cert_dcl51_cpp_violation] : FALSE */
void Thread::yield()
{
    (void) sched_yield();
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::yield() success (this = %p)\n", this );
}
/* END OF PROTECTED MEMBER FUNCTIONS */

/* START OF PRIVATE MEMBER FUNCTIONS */
/** 
*\fn       void setCompleted() 
*\brief    Called when run completes
*\details  requirement id 751555
*/
/* coverity[misra_cpp_2008_rule_0_1_8_violation] : FALSE */
/* coverity[misra_cpp_2008_rule_9_3_3_violation] : FALSE */
void Thread::setCompleted()
{
    /* completion handled by pthread_join() */
}
/** 
 * \fn      bool isRunning() 
 * \brief   Test if the thread is  currently running
 * \return <b>true</b> thread is running, <b>false</b> not started or finished
 * \details  requirement id 751555
 */
bool Thread::isRunning() const
{
    bool result;
    result = false;
    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        result = mActive;
    }
    return result;
}
/** 
 * \fn      bool isDetached() 
 * \brief   if the thread is detached
 * @return <b>true</b> if in detached state, <b>false</b> otherwise
 * \details  requirement id 751555
 */
/* coverity[misra_cpp_2008_rule_0_1_10_violation] : FALSE */
bool Thread::isDetached() const
{
    bool result;
    result = false;
    /* coverity[misra_cpp_2008_rule_6_5_1_violation] : FALSE */
    SYNCHRONIZED ( mMutex )
    {
        result = mDetached;
    }
    return result;
}

/** 
 * \fn      static void *startThreadRunnable ( void *const parg )
 * \brief   method for threads created from IRunnable objects
 * \details requirement id 751555
 */
void *Thread::startThreadRunnable ( void *const parg )
{
    /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
    Thread *const runnableThread = static_cast<Thread *const> ( parg );
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::startThreadRunnable() calling mRunnable->run() %p\n",
            runnableThread->mRunnable );

    try
    {
        runnableThread->mResult = runnableThread->mRunnable->run();
    }
    catch ( std::exception &ex )
    {
        OSAL_ERR ( OSAL_SCOPE_THREAD,
                "Thread::startThreadRunnable: unhandled exception! what = \"%s \" (thread = %p)\n",
                ex.what(), runnableThread );
        OSAL_ABORT()
        ;
    }
    catch ( ... )
    {
        OSAL_ERR ( OSAL_SCOPE_THREAD, "Thread::startThreadRunnable: unhandled execption! thread = %p\n",
                runnableThread );
        OSAL_ABORT()
        ;
    }

    runnableThread->setCompleted();
    return runnableThread->mResult;
}

/** 
 * \fn      static void *startThread ( void *const parg )
 * \brief   method for threads created by inheriting from Class Thread
 * \details requirement id 751555
 */
void *Thread::startThread ( void *const parg )
{

    (void) pthread_setcancelstate ( PTHREAD_CANCEL_ENABLE, NULL );
    (void) pthread_setcanceltype ( PTHREAD_CANCEL_DEFERRED, NULL );

    /* coverity[misra_cpp_2008_rule_2_10_6_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_2_4_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
    /* coverity[cert_exp56_cpp_violation] : FALSE */
    /* coverity[cert_dcl51_cpp_violation] : FALSE */
    pthread_cleanup_push ( &Thread::cleanupDispatcher, parg )
    ;

    /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
    Thread *const threadL = static_cast<Thread *const> ( parg );
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::startThread() calling thread->run()\n" );

    try
    {
        threadL->mResult = threadL->run();
    }
    catch ( std::exception &ex )
    {
        OSAL_ERR ( OSAL_SCOPE_THREAD, "Thread::startThread: unhandled exception! what = \"%s \", thread = %p\n",
                ex.what(), threadL );
        OSAL_ABORT()
        ;
    }
    catch ( ... )
    {
        OSAL_ERR ( OSAL_SCOPE_THREAD, "Thread::startThrad: unhandled exception! thread = %p\n", threadL );
        OSAL_ABORT()
        ;
    }

    threadL->setCompleted();

    /* coverity[misra_cpp_2008_rule_5_2_4_violation] : FALSE */
    pthread_cleanup_pop ( true );

    return NULL;
}

/**
 * \fn      static void cleanupDispatcher ( void *const parg )
 * \brief   method for threads created by inheriting from Class Thread
 * \details requirement id 751555
 */
void Thread::cleanupDispatcher ( void *const parg )
{
    /* coverity[misra_cpp_2008_rule_5_2_8_violation] : FALSE */
    /* coverity[misra_cpp_2008_rule_7_1_1_violation] : FALSE */
    Thread *threadPr = static_cast<Thread *> ( parg );
    OSAL_DBG ( OSAL_SCOPE_THREAD, "Thread::cleanupDispatcher() calling thread->cleanup()\n" );
    threadPr->cleanup();
}
/* END OF PRIVATE MEMBER FUNCTIONS */

} /* namespace osal */

} /* namespace dk */
