

#include <stdio.h>
#include "dk_bspal_sys_shutdown.h"

int main (int argc, char *argv[])
{
	int32_t ret =0;

	printf("start system shutdown\n");

	ret = dk_bspal_sys_shutdown(  ESysShutdown_Shutdown, "system_shutdown" );

    return ret;
}
