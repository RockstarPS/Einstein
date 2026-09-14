

#include <stdio.h>
#include "dk_bspal_display.h"



int main ( int argc, char *argv[] )
{
	int32_t l_gamma_red = -1;
    int32_t l_gamma_green = -1;
    int32_t l_gamma_blue = -1;

    printf ( "Start: %s\n", argv[0] );
    uint32_t retp = dk_bspal_display_set_gamma_rgb ( 0, 100, 110, 120 );
    uint32_t ret = dk_bspal_display_get_gamma_rgb ( 0, &l_gamma_red, &l_gamma_green, &l_gamma_blue );
    printf ( "Return value is :%d\n", ret );
    if(ret == 0)
    {
    	printf("Gamma values for Red : %d, Green : %d, BLue : %d\n", l_gamma_red, l_gamma_green, l_gamma_blue);
    }

    printf ( "Exit: %s\n", argv[0] );

    return 0;
}

