
#include <stdio.h>
#include "CVmm_DK_BSPAL.h"

int main ( int argc, char *argv[] )
{
    int32_t ret = 0;

    printf ( "start vmm \n" );

    ret = dk_bspal_vmm_start ( 2 );

    if( ret < 0)
    {
        printf("vmm_start failed\n");
    } else {
        printf("vmm_start success\n");
    }

    return ret;
}
