#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wdg_client.h>

#include "dk_logger.h"

#define TEST_CASE "Test Case 8"


int main ( void )
{
    int count = 10;

    (void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)printf ( "Start: %s\n", TEST_CASE );

    (void)printf ( "%s: calling connect()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->connect ( __progname, 1000U, 2, 4 );
    (void)sleep ( 5U );

    (void)printf ( "%s: calling start()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 1000 );

    while ( count > 0 )
    {
        (void)printf ( "calling pet() at interval of 1 sec: Call %d \n", count );
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        count--;
        (void)sleep ( 1U );
    }

    (void)printf ( "sleeping for 8 seconds..\n" );
    (void)sleep ( 8U );

    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;
}
