#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wdg_client.h>

#include "dk_logger.h"

#define TEST_CASE "Test Case 5"

int main ( const int argc, char *const argv[] )
{
    const int n = atoi ( argv[1] );

    /*Touch unused variable*/    
    (void)argc;

    (void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );
    
    (void)printf ( "Start: %s\n", TEST_CASE );

    (void)printf ( "%s: calling connect()\n", TEST_CASE );

    /*int32_t connect ( const char *pProcessName = __progname,
                        uint32_t reqTimeoutPeriodMs = 1000u,
                        int32_t wdgLowMark = 1,
                        int32_t wdgHighMark = 2 );*/
    (void)dk::srvc::health::WdgClient::getInstance()->connect ( __progname, 1000U, 2, 4 );
    (void)sleep ( static_cast<uint32_t>(n) );

    (void)printf ( "%s: calling start()\n", TEST_CASE );
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 1000 );
    (void)sleep ( static_cast<uint32_t>(n) );

    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;;
}
