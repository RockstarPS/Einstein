

#include <stdio.h>
#include "dk_bspal_pwm.h"
#include <stdlib.h>


int main ( int argc, char *argv[] )
{
	uint32_t ret;

	int pin_num = atoi(argv[1]);


	printf ( "Start: %s\n", argv[0] );
	dk_bspal_pwm_init();
	ret = dk_bspal_pwm_set_period(pin_num, 50);
	printf ( "Return value is :%d\n", ret );
	dk_bspal_pwm_deinit();
	printf ( "Exit: %s\n", argv[0] );

	return 0;
}
