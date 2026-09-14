#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "dk_logger.h"

#define TEST_CASE "Test Case 13_1"


int main ( const int argc, char *const argv[] )
{
    const int n = atoi ( argv[1] );

    /*Touch unused variable*/
    (void)argc;

    (void)LOG_REGISTER_APP_SLOG2 ( "WC", "Watchdog Client" );

    (void)printf ( "Start: %s\n", TEST_CASE );
    (void)printf ( "sleeping for %d seconds\n", n );
    (void)sleep ( static_cast<uint32_t>(n) );
    (void)printf ( "Exit: %s\n", TEST_CASE );
    return EXIT_SUCCESS;
}
