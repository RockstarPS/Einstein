

#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_dio.h"

int main ( int argc, char *argv[] )
{
	int pin_id = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_dio_init();
	uint32_t ret = dk_bspal_dio_set_direction( pin_id, e_gpio_direction_in);
	 printf ( "Return value is :%d\n", ret );
	if(ret==-1){
		printf("error while setting pin value , please check if the pin is configured already in kernel\n");
	}
	else{
		printf("setdirection in is successful\n");
	}

	dk_bspal_dio_deinit();
	printf ( "Exit: %s\n", argv[0] );

    return 0;
}
