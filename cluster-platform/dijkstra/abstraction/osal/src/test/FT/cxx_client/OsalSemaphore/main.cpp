#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "DKOsalSemaphore.h"
#include "DKOsalMutex.h"
#include "DKOsalClock.h"
#include <queue>

#ifdef __GLIBC__
#define delay(x) usleep((x) * 1000U)
#endif

using namespace std;
using namespace dk;
using namespace osal;
std::queue<int> que;

static Semaphore *o_Semaphore;
static Mutex *s_Mutex;

void thread_1(int loopFor)
{
    int cnt=0;
    while (cnt < loopFor)
    {
        o_Semaphore->wait();
        cout << "o_Semaphore->wait() unblocked => cnt : "<<cnt<< endl;
        cnt++;
    }
}

void produce(int loopFor) 
{
    int cnt = 0;
    while (cnt < loopFor)
    {
        sleep(1);
        int item = rand() % 100;
        s_Mutex->lock();
        que.push(item);
        s_Mutex->unlock();
        cout << "Produced item : " << item << endl;

        o_Semaphore->post();
        cnt++;
    }
}

void consume(int loopFor) 
{
    int cnt = 0;
    while (cnt < loopFor)
    {
        sleep(2);
        o_Semaphore->wait();
        cout << "Consumer_counter value: " << o_Semaphore->value()<< endl;
        cout << "Consumed item : " << que.front() << endl;
        s_Mutex->lock();
        que.pop();
        s_Mutex->unlock();

        cnt++;
    }
}

void thread_timedWaitMS(int loopFor)
{
    timespec ts, ts1;
    int cnt = 0;
    while(cnt < loopFor)
    {
        Clock::getMontonicTime(ts1);
        if (o_Semaphore->timedWaitMS(2000))
        {
            cout << "timedWaitMS() - passed from thread_timedWaitMS" << endl;
        }
        else
        {
            Clock::getMontonicTime(ts);
            cout << "timedWaitMS() - failed from thread_timedWaitMS" << endl;
            int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitMS invoked time  : "<<time_del/1000<<" MS"<<endl;
        }
        cnt++;
    }
}

void thread_timedWaitUS(int loopFor)
{
    timespec ts, ts1;
    int cnt = 0;
    while(cnt < loopFor)
    {
        Clock::getMontonicTime(ts1);
        if (o_Semaphore->timedWaitUS(2000))
        {
            cout << "timedWaitUS() - passed from thread_timedWaitUS"<< endl;
        }
        else
        {
            Clock::getMontonicTime(ts);
            cout << "timedWaitUS() - failed  from thread_timedWaitUS" << endl;
            int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitUS invoked time : "<<time_del<<" US"<<endl;
        }
        cnt++;
    }
}

void thread_tryWait(int loopFor)
{
    int cnt = 0;
    while(cnt < loopFor)
    {
        if (o_Semaphore->tryWait())
        {
            cout << "tryWait() - passed from thread_tryWait" << endl;
        }
        else
        {
            cout << "tryWait() - failed from thread_tryWait" << endl;
        }
        cnt++;
    }
}

int main(int argc, char *argv[]) {

    thread t1;
    thread t2;

    int option;
    int cnt = 0;

    cout << "Starting osal_semaphore test..!" << endl;
    option = atoi(argv[1]);
    switch (option) 
    {
    case 1: 
        {
            o_Semaphore = new Semaphore(0);
            t1 = thread(thread_1, 5);

            for (cnt = 0; cnt < 5; cnt++) {
                delay(55);
                cout << "calling o_Semaphore->post() from main thread with cnt : " << cnt << endl;
                delay(55);
                o_Semaphore->post();
            }
            t1.join();
        }
        break;
    case 2:
        o_Semaphore = new Semaphore(0);
        s_Mutex = new Mutex();
        t1 = thread(produce, 5);
        t2 = thread(consume, 5);
        t1.join();
        t2.join();
        break;
    case 3:
        o_Semaphore = new Semaphore(2);
        if(o_Semaphore->timedWaitMS(100))
        {
            cout << "timedWaitMS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedWaitMS() - failed from main thread" << endl;
        }

        t1 = thread(thread_timedWaitMS,4);
        t1.join();
        break;
    case 4:
        o_Semaphore = new Semaphore(2);
        if(o_Semaphore->timedWaitUS(100))
        {
            cout << "timedWaitUS() - passed from main thread" << endl;
        }
        else
        {
            cout << "timedWaitUS() - failed from main thread" << endl;
        }

        t1 = thread(thread_timedWaitUS,4);
        t1.join();
        break;
    case 5:
        o_Semaphore = new Semaphore(2);
        if (o_Semaphore->tryWait())
        {
            cout << "tryWait() - passed from main" << endl;
        }
        else
        {
            cout << "tryWait() - failed from main" << endl;
        }
        t1 = thread(thread_tryWait, 4);
        t1.join();
        break;
    default:
        cout << "usage " << argv[0] << " arg 1" << endl;
        break;
    }

    cout << "exiting from osal_semaphore test..!" << endl;

    return 0;
}
