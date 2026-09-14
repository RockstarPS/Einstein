
#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_pwm.h"


int main ( int argc, char *argv[] )
{

	uint32_t br_value;

	printf ( "Start: %s\n", argv[0] );
	dk_bspal_pwm_init();
	uint32_t ret = dk_bspal_pwm_get_brightness( &br_value);
	if(ret==0)
	{
		printf("Value of brightness is \n", br_value);
	}
	printf ( "Return value is :%d\n", ret );
	dk_bspal_pwm_deinit();
	printf ( "Exit: %s\n", argv[0] );

	return 0;
}
