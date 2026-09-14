#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "DKOsalRecursiveMutex.h"
#include "DKOsalClock.h"

using namespace std;
using namespace dk;
using namespace osal;

static int counter = 0;

static RecursiveMutex *s_Mutex;

void thread_1(char id, int loopFor) {

    if(loopFor < 0)
    return;

    cout<< " Entered thread_1 by Thread_Id "<< id << " "<< counter++ <<endl;
    thread_1(id, --loopFor);

    cout<< "exit thread_1 by Thread_Id "<< id <<endl;

}

void thread_2(char id, int loopFor) {

    if(loopFor < 0)
    return;

    s_Mutex->lock();

    cout<< "thread_2 locked by Thread_Id "<< id << " "<< counter++ <<endl;
    thread_2(id, --loopFor);
    s_Mutex->unlock();
    cout<< "thread_2 unlocked by Thread_Id "<< id <<endl;

}

void thread_3(int loopFor) {
    timespec ts, ts1;
    if(loopFor < 0)
    return;

    Clock::getMontonicTime(ts1);
    if(s_Mutex->timedLockMS(2000))
    {
        cout << "timedLockMS() - passed from thread_3" << endl; 
    }
    else
    {
        cout << "timedLockMS() - failed from thread_3" << endl;
        Clock::getMontonicTime(ts);
        int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
        cout<<"getTimeDiffUS(): thread_3 invoked time : "<<time_del/1000<<" MS"<<endl;
    }
    thread_3(--loopFor);
}

void thread_4(int loopFor) {
    timespec ts, ts1;
    if(loopFor < 0)
    return;

    Clock::getMontonicTime(ts1);
    if(s_Mutex->timedLockUS(2000))
    {
        cout << "timedLockUS() - passed from thread_4" << endl;
    }
    else
    {
        cout << "timedLockUS() - failed from thread_4" << endl;
        Clock::getMontonicTime(ts);
        int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
        cout<<"getTimeDiffUS(): thread_4 invoked time : "<<time_del<<" US"<<endl;
    }
    thread_4(--loopFor);
}
int main(int argc, char *argv[])
{
    thread t1;
    thread t2;
    int option;
    cout << "osal_recursive_mutex test started..!" << endl;
    option = atoi(argv[1]);

    switch (option)
    {
    case 1:
        cout << "two threads without recursive mutex synchronization..!" << endl;
        t1 = thread(thread_1, '1', 4);
        t2 = thread(thread_1, '2', 4);
        t1.join();
        t2.join();
        break;
    case 2:
        cout << "two threads with recursive mutex synchronization..!" << endl;
        cout << "testing lock() and unlock() API's..!" << endl;
        s_Mutex = new RecursiveMutex();
        t1 = thread(thread_2, '1', 4);
        t2 = thread(thread_2, '2', 4);
        t1.join();
        t2.join();
        break;
    case 3:
        cout << "two threads with recursive mutex synchronization..!" << endl;
        cout << "testing tryLock() API's..!" << endl;
        
        s_Mutex = new RecursiveMutex();
        s_Mutex->lock();

        if (s_Mutex->tryLock())
        {
            cout << "tryLock() - passed" << endl;
        }
        else
        {
            cout << "tryLock() - failed" << endl;
        }

        if (s_Mutex->tryLock())
        {
            cout << "tryLock() - passed" << endl;
        }
        else
        {
            cout << "tryLock() - failed" << endl;
        }
        
        if (s_Mutex->tryLock())
        {
            cout << "tryLock() - passed" << endl;
        }
        else
        {
            cout << "tryLock() - failed" << endl;
        }
        
        s_Mutex->unlock();
        s_Mutex->unlock();
        s_Mutex->unlock();
        s_Mutex->unlock();
        break;
    case 4:
        cout << "two threads with using recursive mutex synchronization..!" << endl;
        cout << "testing timedLockMS() API's..!" << endl;
        s_Mutex = new RecursiveMutex();
        
        if (s_Mutex->timedLockMS(10))
        {
            cout << "timedLockMS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockMS() - failed from main thread" << endl;
        }

        if (s_Mutex->timedLockMS(10))
        {
            cout << "timedLockMS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockMS() - failed from main thread" << endl;
        } 
        if (s_Mutex->timedLockMS(10))
        {
            cout << "timedLockMS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockMS() - failed from main thread" << endl;
        } 
        
        t1 = thread(thread_3,3);
        t1.join();
        break;
    case 5:
        cout << "two threads with using recursive mutex synchronization..!" << endl;
        cout << "testing timedLockUS() API's..!" << endl;
        s_Mutex = new RecursiveMutex();
        s_Mutex->lock();

        if (s_Mutex->timedLockUS(50))
        {
            cout << "timedLockUS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockUS() - failed from main thread" << endl;
        }

        if (s_Mutex->timedLockUS(50))
        {
            cout << "timedLockUS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockUS() - failed from main thread" << endl;
        }
        if (s_Mutex->timedLockUS(50))
        {
            cout << "timedLockUS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedLockUS() - failed from main thread" << endl;
        }
        t1 = thread(thread_4,3);
        t1.join();
        break;

    default:
        cout<<"usage "<<argv[0]<<" arg 1"<<endl;
        break;
    }

    cout << "exiting osal_recursive_mutex test..!" << endl;

    return 0;
}
