#include <stdio.h>
#include <stdlib.h>
#include <wdg_client.h>

#include "dk_logger.h"

#define TEST_CASE "Test Case 2"



int main ( void )
{
	(void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)printf ( "Start: %s\n", TEST_CASE );
    (void)printf ( "%s: calling connect()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->connect();
    ( void ) getchar();
    (void)printf ( "%s: calling disconnect()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->disconnect();
    ( void ) getchar();
    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;
}
