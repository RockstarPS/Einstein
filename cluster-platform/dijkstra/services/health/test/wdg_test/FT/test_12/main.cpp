#include <stdio.h>
#include <stdlib.h>
#include <wdg_client.h>
#include <process.h>

#include "dk_logger.h"

void thread1 ( void )
{
    int th_count = 10;
    
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 2000 );

    while ( th_count > 0 )
    {
        (void)printf ( "pet from thread 1 - %d: %d\n",gettid(), th_count );
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        th_count--;
        (void)delay ( 2500U );
    }

    (void)dk::srvc::health::WdgClient::getInstance()->stop();
}

void thread2 ( void )
{
    int th_count = 10;
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 3000 );

    while ( th_count > 0 )
    {
        (void)printf ( "pet from thread 2 - %d: %d\n",gettid(), th_count );
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        th_count--;
        (void)delay ( 2000U );
    }

    (void)dk::srvc::health::WdgClient::getInstance()->stop();
}

int main ( void )
{
    int count = 0;
    volatile int *const pCrash = NULL;

    (void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)puts ( "TEST 12" ); /* prints Hello World!!! */

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
            (void)delay ( 1500U );
            (void)printf ( "pet when %d\n", count );
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
        else if ( count == 25 )
        {
            (void)delay ( 3000U );
            (void)printf ( "pet when %d\n", count );
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
        else if ( count == 30 )
        {
            (void)printf ( "pCrash %d\n", count );
            *pCrash = 1;
        }
        else
        {
            (void)delay ( 900U);
            (void)printf ( "pet when %d\n", count );
            (void)dk::srvc::health::WdgClient::getInstance()->pet();
        }
    }

    return EXIT_SUCCESS;
}
