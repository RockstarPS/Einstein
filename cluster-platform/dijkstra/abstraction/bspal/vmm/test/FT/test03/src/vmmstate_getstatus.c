
#include <stdio.h>
#include <unistd.h>
#include "CVmm_DK_BSPAL.h"

int main ( int argc, char *argv[] )
{
    int32_t ret = 0;

    printf ( "start vmm reg\n" );

    dk_bspal_vmm_init();

    ret = dk_bspal_vmm_stop ( 2 );

    if( ret < 0)
    {
        printf("vmm_stop failed\n");
    } else {
        printf("vmm_stop success\n");
    }

    sleep(10);

    printf ( "start vmm read\n" );

    ret = dk_bspal_vmm_getstatus(2);

    printf("status of vmid 2 is %d\n",ret);

    dk_bspal_vmm_deinit();

    return ret;
}
