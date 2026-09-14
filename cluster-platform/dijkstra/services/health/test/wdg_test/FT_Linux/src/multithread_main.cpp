#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <wdg_client.h>
#include "dk_logger.h"

void thread1 ( void )
{
    int th_count = 10;
    
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 2000 );

    while ( th_count > 0 )
    {
        std::cout << "pet from thread 1 - " << gettid() << th_count << "\n" << std::flush;
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        th_count--;
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    }

    (void)dk::srvc::health::WdgClient::getInstance()->stop();
}

void thread2 ( void )
{
    int th_count = 10;
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 3000 );

    while ( th_count > 0 )
    {
        std::cout << "pet from thread 2 - " << gettid() << th_count << "\n" << std::flush;
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        th_count--;
        std::this_thread::sleep_for(std::chrono::milliseconds( 2000 ));
    }

    (void)dk::srvc::health::WdgClient::getInstance()->stop();
}

int main ( const int argc, char *const argv[] )
{
    int32_t testcase = 0;
    int32_t count = 0;
    volatile int32_t *const pCrash = NULL;

    if(argc != 2)
    {
        std::cout << "Invalid no. of arguments \n" << std::flush;
    }
    else
    {
        testcase = atoi ( argv[1] );
    }

    (void)LOG_REGISTER_APP_DLT ( "TEST", "Watchdog Client" );

    std::cout << "Start - Test Case: " << testcase << "\n" << std::flush;

    (void)dk::srvc::health::WdgClient::getInstance()->connect();
    
    (void)sleep( 2U );
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 5000 );

    const std::thread t1 ( &thread1 );
    const std::thread t2 ( &thread2 );

    while ( true )
    {
        count++;

        if ( count == 20 )
        {
            std::this_thread::sleep_for(std::chrono::milliseconds( 1500 ));
            std::cout << "pet when " << count << "\n"<< std::flush;
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
        else if ( count == 25 )
        {
            std::this_thread::sleep_for(std::chrono::milliseconds( 3000 ));
            std::cout << "pet when " << count << "\n"<< std::flush;
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
        else if ( count == 30 )
        {
            std::cout << "pCrash " << count << "\n";
            *pCrash = 1;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds( 900 ));
            std::cout << "pet when " << count << "\n";
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
    }

    return EXIT_SUCCESS;
}
