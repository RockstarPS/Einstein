#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wdg_client.h>

#include "dk_logger.h"


#define TEST_CASE "Test Case 6"


int main ( void )
{
	(void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)printf ( "Start: %s\n", TEST_CASE );

    (void)printf ( "%s: calling connect()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->connect ( __progname, 1000U, 2, 4 );

    (void)printf ( "%s: calling start()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 1000 );
    (void)sleep ( 7U );

    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;;
}
