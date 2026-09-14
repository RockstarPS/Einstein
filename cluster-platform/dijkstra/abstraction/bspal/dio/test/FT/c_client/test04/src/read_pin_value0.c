
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dk_bspal_dio.h"



int main ( int argc, char *argv[] )
{
	bool l_value;
	int pin_num = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_dio_init();
	uint32_t ret1 = dk_bspal_dio_set_value( pin_num, false);
	printf ( "Return value dk_bspal_dio_set_value is :%d\n", ret1 );
	if(ret1 == 0)
	{
		uint32_t ret = dk_bspal_dio_get_value( pin_num, &l_value);
		if(ret==0)
		{
			printf("Value of pin %d is %d\n", pin_num, l_value);
		}
		printf ( "Return value dk_bspal_dio_get_value is :%d\n", ret );
	}
	else{
		printf("error while setting pin value , please check if the pin is configured already in kernel\n");
	}
	dk_bspal_dio_deinit();
	printf ( "Exit: %s\n", argv[0] );

    return 0;
}
