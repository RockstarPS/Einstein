/*
 * Semaphore.h
 *
 *  Created on: Apr 28, 2017
 *      Author: VMUTHUSU
 */

#ifndef SRC_DKOSALSEMAPHORE_H_
#define SRC_DKOSALSEMAPHORE_H_

#include <cstdint>                     /* standard datatype inclusion   */
//#include <semaphore.h>                 /* for sem_t inclusion            */

namespace dk
{

namespace osal
{

class Semaphore
{
    public:
        /** Constructor
         * @param counter Initial value of the semaphore counter.
         */
        Semaphore ( uint32_t counter );

        /** Destructor
         */
        ~Semaphore();

        /** Try to wait for a semaphore
         * If the counter is greater than "0", it will be decremented by "1"
         * @return <b>true</b> semaphore counter greater thann "0"
         *         <b>false</b> semaphore counter is "0"
         */
        bool tryWait();

        /** Semaphore wait operation (waits with a timeout)
         * Blocks the current thread until the semaphore counter is greater than "0", and then decrements
         * the counter by "1". If the specified timeout interval elapses, the function is cancelled.
         * @param msec number of milliseconds to wait before the wait() is cancelled
         * @return <b>true</b> semaphore counter is greater than "0"
         *         <b>false</b> a timeout occurred
         */
        bool timedWaitMS ( uint32_t msec );

        /** Semaphore wait operation (waits with a timeout)
         * Blocks the current thread until the semaphore counter is greater than "0", and then decrements
         * the counter by "1". If the specified timeout interval elapses, the function is cancelled.
         * @param usec number of microseconds to wait before the wait() is cancelled
         * @return <b>true</b> semaphore counter is greater than "0"
         *         <b>false</b> a timeout occurred
         */
        bool timedWaitUS ( uint32_t usec );

        /** Semaphore wait operation
         * Blocks the current thread until the semaphore is greater than "0", and then decrements the counter
         * by "1"
         */
        void wait();

        /** Semaphore post operation
         * Increments the semaphore counter by "1" and then notifies the waiting threads.
         */
        void post();

        /** Get counter value of semaphore
         * @return current counter value.
         */
        uint32_t value();

    private:
        /** Disable Copy Constructor and Assignment operators
         */
        Semaphore ( const Semaphore & );
        Semaphore &operator= ( const Semaphore & );

        void init ( uint32_t counter );

        //sem_t mSemaphore;

};

} /* namespace osal */

} /* namespace dk */

#endif /* SRC_DKOSALSEMAPHORE_H_ */
