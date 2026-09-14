

#include <stdio.h>
#include "dk_bspal_display.h"



int main ( int argc, char *argv[] )
{
    printf ( "Start: %s\n", argv[0] );
    uint32_t ret = dk_bspal_display_set_power ( 0, EBspalDisplayPower_Off );
    printf ( "Return value is :%d\n", ret );
    printf ( "Exit: %s\n", argv[0] );

    return 0;
}
