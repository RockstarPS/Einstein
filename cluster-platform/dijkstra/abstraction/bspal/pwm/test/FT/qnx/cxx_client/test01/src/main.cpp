
#include <stdio.h>
#include <stdlib.h>
#include "dk_bspal_dio.h"


int main ( int argc, char *argv[] )
{
	bool l_value;
	EDirection p_dir;
	uint32_t ret = -1;

	int pin_num = atoi(argv[1]);
    printf ( "Start: %s\n", argv[0] );
    dk_bspal_dio_init();
    //to set the value of dio pin
    uint32_t ret_set = dk_bspal_dio_set_value( pin_num, true );
    if(ret_set == 0)
    {
	//to read dio pin value
	uint32_t ret_get = dk_bspal_dio_get_value( pin_num, &l_value);
	if(ret_get == 0)
	{
		printf("Value of pin %d is %d\n", pin_num, l_value);
		//set dio pin direction to output
		uint32_t ret_dir_out = dk_bspal_dio_set_direction( pin_num, e_gpio_direction_out);
		if(ret_dir_out == 0)
		{
			//read direction of the pin
				ret = dk_bspal_dio_get_direction ( pin_num, &p_dir );
				printf("Direction of pin %d is %d\n", pin_num, (int)p_dir);
		}
	}
    }
    printf ( "Return value is :%d\n", ret );
    dk_bspal_dio_deinit();
    printf ( "Exit: %s\n", argv[0] );

    return 0;
}
