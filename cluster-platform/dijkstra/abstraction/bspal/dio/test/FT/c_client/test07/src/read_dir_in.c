
#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_dio.h"

int main(int argc, char* argv[])
{
	EDirection p_dir;

	int pin_id = atoi(argv[1]);
	printf ( "Start: %s\n", argv[0] );
	dk_bspal_dio_init();
	uint32_t ret = dk_bspal_dio_set_direction( pin_id, e_gpio_direction_in);
	printf ( "Return value dk_bspal_dio_set_direction  :%d\n", ret );
	if(ret == 0)
	{
		int32_t ret2 = dk_bspal_dio_get_direction ( pin_id, &p_dir );
		if(ret2 == 0)
		{
			printf("Direction of pin %d is %d\n", pin_id, (int)p_dir);
			printf ( "Return value dk_bspal_dio_get_direction is :%d\n", ret );
		}

	}
	else{
		printf("error while setting pin value , please check if the pin is configured already in kernel\n");
	}

	dk_bspal_dio_deinit();
	printf ( "Exit: %s\n", argv[0] );
	return 0;
}
