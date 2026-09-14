#include <stdio.h>
#include "dk_bspal_sys_shutdown.h"

int main (int argc, char *argv[])
{
	int32_t ret =0;

	printf("start system rebooting\n");

	ret = dk_bspal_sys_shutdown(  ESysShutdown_Reboot, "system_rebooting" );

    return ret;
}
