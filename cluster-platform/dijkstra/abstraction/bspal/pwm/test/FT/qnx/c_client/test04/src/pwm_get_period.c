
#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_pwm.h"


int main ( int argc, char *argv[] )
{
	uint32_t l_value;
	int pin_num = atoi(argv[1]);
    printf ( "Start: %s\n", argv[0] );
    dk_bspal_pwm_init();
	uint32_t ret = dk_bspal_pwm_get_period( pin_num, &l_value);
	if(ret==0)
	{
		printf("Value of pin %d is %d\n", pin_num, l_value);
	}
	printf ( "Return value is :%d\n", ret );
    dk_bspal_pwm_deinit();
    printf ( "Exit: %s\n", argv[0] );

    return 0;
}
