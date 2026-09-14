#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "DKOsalThread.h"
#include "DKOsalClock.h"

#ifdef __GLIBC__
#define delay(x) usleep((x) * 1000U)
#endif

using namespace std;
using namespace dk;
using namespace osal;
void cancel_thread_2();
Thread Thread_obj;

class test_threadYield : public Thread
{
public:
    test_threadYield( bool id ) :
    myID(id)
    {
        cout << "test_threadYield::test_threadYield() constructor called id : "<<myID<< endl;  
    }
    void *run()
    {
        int i;
        for( ;; ) {
            /* Process something... */
            for( i = 0 ; i < 1000; ++i )
            loop_func();

            /* Yield to anyone else at the same priority */
            if( myID == 1)
            {
                Thread::yield();
            }
        }    
    }
    int loop_func() // sample func for testing yield
    {
        int i;
        for( i = 0 ; i < 10 ; ++i )
        i += i;
        
        return( i );
    }
private:
    bool myID;
};

class testThread : public Thread
{
public:
    testThread ( int id ) :
    myID ( id )
    {
        cout << "testThread::testThread() constructor called id : "<<myID<< endl;
    }
    void *run()
    {
        cout<<"testThread::run() : "<< myID <<endl;
        return nullptr;
    }
    void cleanup()
    {
        cout << "testThread::cleanup() invoked by thread_ID : "<<myID<< endl;
    }
private:
    int myID;
};

class Thread_cbk_1 : public dk::osal::IRunnable
{
public:
    void *run()
    {
        cout<<"Invoking the IRunnable threadcbk_1 "<<endl;
        uint32_t tid = Thread::currentThreadId();
        cout<<"Thread_cbk_1 thread id : "<<tid<<endl;
        return nullptr;
    }
};

class Thread_cbk_2 : public dk::osal::IRunnable
{
public:
    void *run()
    {
        int timercnt=0;
        while(1)
        {
            cout<<"Invoking the IRunnable threadcbk_2"<<endl;
            timercnt++;
            cout<<"running Thread_cbk_2 cnt : "<<timercnt<<endl;
            if(timercnt > 4)
            {
                cancel_thread_2();
            }
        }
    }
};

Thread_cbk_1 thread_1;
Thread o_thread_1(&thread_1);

Thread_cbk_2 thread_2;
Thread o_thread_2(&thread_2);

void cancel_thread_2()
{
    o_thread_2.cancel();
}

int main( int argc, char *argv[] )
{
    uint32_t tid;
    uint32_t pid;
    timespec ts, ts1;
    int option;
    int64_t time_del;
    std::string tid_name;
    std::string tid_name_1;

    option = atoi(argv[1]);
    switch (option)
    {
    case 1:
        {
            cout<<"Starting oslal_thread_testing"<<endl;
            cout<<"construct a new thread object"<<endl;
            cout<<"Testing currentThreadId() API"<<endl;
            tid = Thread::currentThreadId();
            cout<<"Printing current thread id : "<<tid<<endl;

            cout<<endl;

            cout<<"Testing currentProcessId() API"<<endl;
            pid = Thread::currentProcessId();
            cout<<"Printing current process id : "<<pid<<endl;
            sleep(10);

            cout<<endl;

            cout<<"Testing getName() API"<<endl;
            cout<<"Calling getName() API with out setting the name"<<endl;
            tid_name = Thread_obj.getName();
            cout<<"tid name : "<<tid_name<<endl;

            cout<<endl;

            cout<<"Testing setName() API"<<endl;
            tid_name = "main_process";
            Thread_obj.setName (tid_name);
            cout<<"Calling getName() API after setting the name"<<endl;
            tid_name_1 = Thread_obj.getName();
            cout<<"tid name : "<<tid_name_1<<endl;

            cout<<endl;

            cout<<"Testing sleepMS() API"<<endl;
            Clock::getMontonicTime(ts1);
            Thread::sleepMS(2000);
            Clock::getMontonicTime(ts);
            time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitMS invoked time  : "<<time_del/1000<<" MS"<<endl;

            cout<<"Testing sleepUS() API"<<endl;
            time_del = 0;
            Clock::getMontonicTime(ts1);
            Thread::sleepUS(5000);
            Clock::getMontonicTime(ts);
            time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitMS invoked time  : "<<time_del<<" US"<<endl;

            auto_ptr<testThread> thread_1 ( new testThread ( 1 ) );
            thread_1->start ( "THREAD_ONE" );
            delay(5);
            auto_ptr<testThread> thread_2 ( new testThread ( 2 ) );
            thread_2->start ( "THREAD_TWO" );

            thread_1->join();
            thread_2->join();
        }
        break;
    case 2:
        {
            tid = 0;
            pid = 0;
            cout<<"Construct a new Thread with a IRunnable object"<<endl;
            cout<<"Testing currentThreadId() API"<<endl;
            tid = o_thread_1.currentThreadId();
            cout<<"Printing current thread id : "<<tid<<endl;

            cout<<endl;

            cout<<"Testing currentProcessId() API"<<endl;
            pid = o_thread_1.currentProcessId();
            cout<<"Printing current process id : "<<pid<<endl;

            cout<<endl;

            cout<<"Testing setName() API"<<endl;
            tid_name = "Thread_cbk_1";
            o_thread_1.setName (tid_name);
            cout<<"Calling getName() API "<<endl;
            tid_name_1 = o_thread_1.getName();
            cout<<"thread name : "<<tid_name_1<<endl;

            cout<<endl;

            cout<<"Testing sleepMS() API"<<endl;
            time_del = 0;
            Clock::getMontonicTime(ts1);
            o_thread_1.sleepMS(2000);
            Clock::getMontonicTime(ts);
            int64_t time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitMS invoked time  : "<<time_del/1000<<" MS"<<endl;

            cout<<endl;

            cout<<"Testing sleepUS() API"<<endl;
            time_del = 0;
            Clock::getMontonicTime(ts1);
            o_thread_1.sleepUS(5000);
            Clock::getMontonicTime(ts);
            time_del = Clock::getTimeDiffUS(ts1, ts);
            cout<<"getTimeDiffUS(): thread_timedWaitMS invoked time  : "<<time_del<<" US"<<endl;

            o_thread_1.start("THREAD_ONE");
            o_thread_2.start("THREAD_TWO");

            o_thread_1.join();
            o_thread_2.join();
        }
        break;
    case 3:
        {
            auto_ptr<test_threadYield> thread_1 ( new test_threadYield ( 0 ) );
            thread_1->start ( "THREAD_ONE" );         
            thread_1->join();
        }
        break;
    case 4:
        {
            auto_ptr<test_threadYield> thread_1 ( new test_threadYield ( 1 ) );
            thread_1->start ( "THREAD_ONE" );         
            thread_1->join();
        }
        break;
    default:
        cout << "usage " << argv[0] << " arg 1" << endl;
        break;
    }

    cout<<"Testing exit() API"<<endl;
    Thread::exit();
    cout<<"exit() API failed "<<endl;
    return 0;
}

