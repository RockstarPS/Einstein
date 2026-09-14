#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "DKOsalMutex.h"
#include "DKOsalMutexLock.h"
#include "DKOsalRecursiveMutex.h"

using namespace std;
using namespace dk;
using namespace osal;

static int counter = 0;
static Mutex oMutex_T;
static RecursiveMutex oRecursiveMutex;

void thread_1(char id,  int loopFor)
{
    int cnt = 0;

    for(cnt = 0; cnt < loopFor; cnt++)
    {
        cout<< "Called thread_1 by Thread_Id "<< id << " "<< counter++ <<endl;
    }
}

void thread_2(char id,  int loopFor)
{
    int cnt = 0;
    
    MutexLock l_scoped_lock_C(oMutex_T);
    for(cnt = 0; cnt < loopFor; cnt++)
    {
        cout<< "thread_2 locked by Thread_Id "<< id << " "<< counter++ <<endl;
    }
}

void thread_3(char id,  int loopFor)
{
    if(loopFor < 0)
    return;

    MutexLock l_scoped_lock_C(oRecursiveMutex);
    cout<< "thread_3 locked by Thread_Id "<< id << " "<< counter++ <<endl;
    thread_3(id, --loopFor);

    cout<< "thread_3 unlocked by Thread_Id "<< id <<endl;
}

void thread_4(char id,  int loopFor)
{
    int cnt = 0;
    
    SYNCHRONIZED(oMutex_T)
    {
    for(cnt =0; cnt < loopFor; cnt++)
    {
        cout<< "thread_4 locked by Thread_Id "<< id << " "<< counter++ <<endl;
    }
    }
}

int main(int argc, char *argv[])
{
    thread t1;
    thread t2;
    int option;

    cout << "osal_mutex_Lock test start..!" << endl;
    option = atoi(argv[1]);
    
    switch (option)
    {
    case 1:
        cout << "threads without mutex synchronization..!" << endl;
        t1 = thread(thread_1, '1', 4);
        t2 = thread(thread_1, '2', 4);
        t1.join();
        t2.join();
        break;
    case 2:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing  scope lock with mutex..!" << endl;
        t1 = thread(thread_2, '1', 4);
        t2 = thread(thread_2, '2', 4);
        t1.join();
        t2.join();
        break;
    case 3:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing  scope lock with RecursiveMutex..!" << endl;
        t1 = thread(thread_3, '1', 4);
        t2 = thread(thread_3, '2', 4);
        t1.join();
        t2.join();
        break;
    case 4:
        cout << "threads with mutex synchronization..!" << endl;
        cout << "testing SYNCHRONIZED() with scope lock..!" << endl;
        t1 = thread(thread_4, '1', 4);
        t2 = thread(thread_4, '2', 4);
        t1.join();
        t2.join();
        break;
    default:
        cout<<"usage "<<argv[0]<<" arg 1"<<endl;
        break;
    }

    cout << "exit osal_mutex_Lock test..!" << endl;

    return 0;
}
