#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "DKOsalMutex.h"
#include "DKOsalClock.h"

#ifdef __GLIBC__
#define delay(x) usleep((x) * 1000U)
#endif

using namespace std;
using namespace dk;
using namespace osal;

char *firstname;
char *lastname;
static Mutex *s_Mutex;

/* The delays in the following routine are only there for
* demonstration purposes - to make the problem much more
* visible. If you remove the delays, it may happen you won't
* SEE the problem, yet it is still there because it's
* a race condition. */
void bushchanger_nomutex() {
    while (1) {
        strcpy(firstname, "George");
        delay(55);
        strcpy(lastname, "Bush");
        delay(55);
    }
}

void kerrychanger_nomutex() {
    while (1) {
        strcpy(firstname, "John");
        delay(77);
        strcpy(lastname, "Kerry");
        delay(77);
    }
}

/* Now the new, improved change routines:
* We are locking the mutex before we modify a part of
* our critical resource. We unlock it after we finished with
* the second part. This is because in this example, the
* two strings belong together. In a different case, it could
* also be imagined that each one represents a single resource
* and would be locked seperately.
* The general rule is: lock the mutex as short as possible!
* The delays here are only in for demonstration purposes!!
*/
void kerrychanger_mutex() {
    while (1) {
        // We lock the mutex to get exclusive access. If the
        // other thread has already locked it, this function
        // will not return unless the mutex becomes unlocked!
        s_Mutex->lock();
        strcpy(firstname, "John");
        delay(77); // delay to make the problem more visible
        strcpy(lastname, "Kerry");
        s_Mutex->unlock();
        delay(77);
    }
}

void bushchanger_mutex() {
    while (1) {
        // lock the mutex, ensure we have exclusive access.
        // our critical resources to protect are "firstname"
        // and "lastname".
        s_Mutex->lock();
        // Now no one else can access the resources, assuming
        // everyone who wants to also tries to lock the mutex
        // first.
        strcpy(firstname, "George");
        delay(55); // delay to make the problem more visible
        strcpy(lastname, "Bush");
        s_Mutex->unlock();
        delay(55);
    }
}

void thread_timedLockMS()
{
    timespec ts, ts1;
    while(1)
    {
        Clock::getMontonicTime(ts1);
        if (s_Mutex->timedLockMS(2000))
        {
            cout << "thread_timedLockMS own the mutex-lock" << endl;
        }
        else
        {
            Clock::getMontonicTime(ts);
            cout << "thread_timedLockMS Failed Mutex is already locked " << endl;
            int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedLockMS invoked time : "<<time_del/1000<<" MS"<<endl;
        }
    }
}

void thread_timedLockUS()
{
    timespec ts, ts1;
    while(1)
    {
        Clock::getMontonicTime(ts);
        if (s_Mutex->timedLockUS(2000))
        {
            cout << "thread_timedLockUS own the mutex-lock" << endl;
            
        } else
        {
            Clock::getMontonicTime(ts1);
            cout << "thread_timedLockUS Failed : Mutex is already locked "<< endl;
            int64_t time_def = Clock::getTimeDiffUS(ts, ts1);
            cout<<"getTimeDiffUS(): thread_timedLockUS invoked time : "<<time_def<<" US"<<endl;
        }
    }
}

int main(int argc, char *argv[])
{
    thread t1;
    thread t2;
    int cnt;
    firstname = (char *)malloc(32);
    lastname = (char *)malloc(32);
    
    int option;
    cout << "osal_mutex test started..!" << endl;
    
    option = atoi(argv[1]);
    switch (option)
    {
    case 1:
        cout << "threads without mutex synchronization..!" << endl;
        t1 =  thread(bushchanger_nomutex);
        t2 =  thread(kerrychanger_nomutex); 
        for (cnt=0; cnt<20; cnt++) {
            delay(500);
            cout<<firstname<<" "<<lastname<<" for president"<<endl;
        }
        t1.join();
        t2.join();
        break;
    case 2:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing lock() and unlock() API's..!" << endl;
        
        s_Mutex = new Mutex();
        t1 = thread(bushchanger_mutex);
        t2 = thread(kerrychanger_mutex);
        
        for (cnt=0; cnt<40; cnt++) {
            delay(500);
            s_Mutex->lock();
            cout<<firstname<<" "<<lastname<<" for president"<<endl;
            s_Mutex->unlock();
        }
        
        t1.join();
        t2.join();
        
        break;
    case 3:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing tryLock() API's..!" << endl;
        
        s_Mutex = new Mutex();
        s_Mutex->lock();
        if (s_Mutex->tryLock())
        {
            cout << "tryLock() - passed" << endl;
        }
        else
        {
            cout << "tryLock() - failed" << endl;
        }
        s_Mutex->unlock();

        if (s_Mutex->tryLock())
        {
            cout << "tryLock() - passed" << endl;
        }
        else
        {
            cout << "tryLock() - failed" << endl;
        }
        
        break;
    case 4:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing timedLockMS() API's..!" << endl;
        
        s_Mutex = new Mutex();
        
        if(s_Mutex->timedLockMS(100))
        {
            cout << "timedLockMS() - passed from main thread" << endl;
        }
        else
        { 
            cout << "timedLockMS() - failed from main thread" << endl; 
        }
        
        t1 = thread(thread_timedLockMS);
        t1.join();
        break;
    case 5:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing timedLockUS() API's..!" << endl;
        
        s_Mutex = new Mutex();
        
        if (s_Mutex->timedLockUS(100))
        {
            cout << "timedLockUS() - passed from main thread" << endl;
        }
        else
        { 
            cout << "timedLockUS() - failed from main thread" << endl; 
        }
        
        t1 = thread(thread_timedLockUS);
        t1.join();
        break;
        
    default:
        cout<<"usage "<<argv[0]<<" arg 1"<<endl;
        break;
    }

    cout << "osal_mutex test exit..!" << endl;

    return 0;
}
