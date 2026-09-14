

#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_dio.h"

int main ( int argc, char *argv[] )
{
	uint32_t ret;
	int pin_num = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_dio_init();
	ret = dk_bspal_dio_set_value( pin_num, true );
	printf ( "Return value is :%d\n", ret );
	if(ret == -1){
		printf("error while setting pin value , please check if the pin is configured already in kernel\n");
		goto de_init;
	}
	else{

		printf("pin value  1 set successfully\n");

	}

de_init: dk_bspal_dio_deinit();
	 printf ( "Exit: %s\n", argv[0] );
	 return 0;
}
