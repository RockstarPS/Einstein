

#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_dio.h"

int main ( int argc, char *argv[] )
{
	int pin_num = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_dio_init();
	uint32_t ret = dk_bspal_dio_set_value(pin_num, false);
	printf ( "Return value is :%d\n", ret );
	if(ret == -1){
		printf("error while setting pin value\n");
		goto de_init;
	}
	else{

		printf("pin value  0 set successfully\n");

	}

de_init: dk_bspal_dio_deinit();
	 printf ( "Exit: %s\n", argv[0] );
	 return 0;
}
