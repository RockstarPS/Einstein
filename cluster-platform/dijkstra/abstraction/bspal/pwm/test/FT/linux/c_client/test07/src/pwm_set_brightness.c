

#include <stdio.h>
#include "dk_bspal_pwm.h"
#include <stdlib.h>

/*BackLight brightness*/

int main ( int argc, char *argv[] )
{
	uint32_t ret;
	uint32_t l_set_br_val;
	l_set_br_val = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_pwm_init();
	ret = dk_bspal_pwm_set_brightness( l_set_br_val );
	printf ( "Return value is :%d\n", ret );
	dk_bspal_pwm_deinit();
	printf ( "Exit: %s\n", argv[0] );

	return 0;
}
