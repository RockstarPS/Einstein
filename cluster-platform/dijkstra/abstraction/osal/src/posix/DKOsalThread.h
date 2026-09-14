/**********************************************************************************
 **
 **  \file Thread.h
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

#ifndef SRC_DKOSALTHREAD_H_
#define SRC_DKOSALTHREAD_H_

/**********************************************************************************************************************
 * INCLUDE
 **********************************************************************************************************************/
#include <cstdint>               /* standard datatype inclusion            */
#include <memory>                /* for auto_ptr reference in linux build  */
#include <iostream>              /* for string class reference             */
#include <pthread.h>             /* for pthread related inclusions         */
#include "DKOsalIRunnable.h"     /* for runnable interface reference       */
#include "DKOsalMutex.h"         /* for Mutex Class inclusion */
#include "DKOsalConfig.h"        /* ThreadConfigID is declared in DKOsalConfig.h */
#include "DKOsalErrorTypes.h"    /* for inclusion of our own Error data type */

namespace dk
{

namespace osal
{

class Thread
{
    public:

        /** 
         * \fn      Thread ( IRunnable *runnable, bool isDetached = false )  
         * \brief   Construct a new Thread with a IRunnable object
         * \param   runnable The IRunnable object whose <b>run()</b> method will be executed in this thread.
         * \param   isDetached A flag indicating whether the thread will be created in a detached state.
         * \details requirement id 751552
         */
        Thread ( IRunnable *runnable, const bool isDetached = false );

        /** 
         * \fn      Thread ( bool isDetached = false ) 
         * \brief   construct a new thread object
         * \param   isDetached A flag indicating whether the thread will be created in a detached state.
         * \details requirement id 751552
         */
        explicit Thread ( const bool isDetached = false );

        /** 
         * \fn      Thread ( bool isDetached = false ) 
         * \brief   Destructor for the Thread class
         * \param   isDetached A flag indicating whether the thread will be created in a detached state.
         * \details requirement id 751552
         */
        ~Thread();

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
        void start ( ThreadConfigID const id );

        /**
         * \fn       void cancel()
         * \brief    stops this thread.
         * \details  requirement id 751555
         */
        void cancel();

        /**
         * \fn       void *join()
         * \brief    Wait for the thread to terminate
         * \details  requirement id 751555
         */
        void *join();

        /** 
         * \fn     void setName ( const std::string &name ) 
         * \brief  Set the name of this thread
         * \param  name thread name to be set
         * \details  requirement id 751555
         */
        void setName ( const std::string &name );

        /** 
         * \fn      std::string getName() const
         * \brief   Get the name of this thread
         * \return  name of the thread.
         * \details  requirement id 751555
         */
        std::string getName() const;

        /** 
         * \fn       static void exit()
         * \brief    Terminate the calling thread.
         *           If called from the main thread, this function will block until all other threads
         *           are finished.
         * \details  requirement id 751555
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        static void exit();

        /** 
         * \fn       uint32_t Thread::currentThreadId()
         * \brief    Get the Thread id (TID) from the calling thread
         * \return   the thread id.
         * \details  requirement id 751555
         */
        static uint32_t currentThreadId();

        /** 
         * \fn         static uint32_t currentProcessId()
         * \brief      Get the process id (PID) from the current process.
         * \return     the process id.
         * \details    requirement id 751555
         */
        static uint32_t currentProcessId();

        /** 
         * \fn       static void sleepMS ( const uint32_t msec )
         * \brief    Blocks the calling thread for the specified time.
         * \param    msec the time to sleep in milliseconds
         * \details  requirement id 751555
         */
        static void sleepMS ( const uint32_t msec );

        /** 
         * \fn       static void sleepUS ( const uint32_t usec )
         * \brief    Blocks the calling thread for the specified time.
         * \param    nusec the time to sleep in microseconds.
         * \details  requirement id 751555
         */
        static void sleepUS ( const uint32_t usec );

    protected:

        /** 
         * \fn       virtual void *run() 
         * \brief    Main function.
         *           Thread execution begins in this function. The default implementation does nothing.
         * \details  requirement id 751555
         */
        virtual void *run();

         /** 
         * \fn       virtual void cleanup() 
         * \brief    Cleanup function.
         *           This function will be executed by the thread just prior to termination. The default
         *           implementation is a no-operation.
         * \details  requirement id 751555
         */
        virtual void cleanup();

        /** 
         * \fn       void yield() 
         * \brief    Yield the CPU to another thread with same priority.
         * \details  requirement id 751555
         */
        /* coverity[cert_dcl51_cpp_violation] : FALSE */
        void yield();

    private:
        /** 
         * \fn      Thread ( const Thread & )   
         * \brief   Disable copy-constructor and assignment operator to avoid copy operation
         *          and assignment operations
         *          if someone tries a copy/assignment will get a compiler error
         * \details  requirement id 751555
         */
        Thread ( const Thread & ) = delete;
        const Thread &operator= ( const Thread & ) = delete;

        /** 
         *\fn       void setCompleted() 
         *\brief    Called when run completes
         *\details  requirement id 751555
         */
        void setCompleted();

        /** 
         * \fn      bool isRunning() 
         * \brief   Test if the thread is  currently running
         * \return <b>true</b> thread is running, <b>false</b> not started or finished
         * \details  requirement id 751555
         */
        bool isRunning() const;

        /** 
         * \fn      bool isDetached() 
         * \brief   if the thread is detached
         * @return <b>true</b> if in detached state, <b>false</b> otherwise
         * \details  requirement id 751555
         */
        bool isDetached() const;

        /** 
         * \fn      static void *startThreadRunnable ( void *const parg )
         * \brief   method for threads created from IRunnable objects
         * \details requirement id 751555
         */
        static void *startThreadRunnable ( void *const parg );

        /** 
         * \fn      static void *startThread ( void *const parg )
         * \brief   method for threads created by inheriting from Class Thread
         * \details requirement id 751555
         */
        static void *startThread ( void *const parg );
        /**
         * \fn      static void cleanupDispatcher ( void *const parg )
         * \brief   method for threads created by inheriting from Class Thread
         * \details requirement id 751555
         */
        static void cleanupDispatcher ( void *const parg );

        pthread_t mThreadID;
        mutable Mutex mMutex;
        IRunnable *mRunnable;
        bool mNeedsJoin;
        bool mActive;

        std::string mThreadName;
        bool mDetached;
        /* stores return value from run() */
        void *mResult;
        pthread_attr_t mThreadAttribute;
};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALTHREAD_H_ */
