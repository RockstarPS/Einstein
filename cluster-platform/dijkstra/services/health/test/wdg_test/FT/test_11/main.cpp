#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wdg_client.h>

#include "dk_logger.h"


#define TEST_CASE "Test Case 11"


int main ( void )
{
    int count = 10;

    (void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)printf ( "Start: %s\n", TEST_CASE );

    (void)printf ( "%s: calling connect()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->connect ( __progname, 1000U, 2, 4 );

    (void)printf ( "%s: calling start()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 1000 );

    while ( count > 0 )
    {
        (void)printf ( "%s: calling pet() at interval of 1 sec: Call %d \n", TEST_CASE, count );
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        count--;
        (void)sleep ( 1U );
    }

    (void)printf ( "%s: calling pause()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->pause();

    (void)printf ( "sleeping for 8 seconds...\n" );
    (void)sleep ( 8U );

    (void)printf ( "%s: calling resume()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->resume();

    (void)printf ( "sleeping for 8 seconds...\n" );
    (void)sleep ( 8U );


    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;
}
