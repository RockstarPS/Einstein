
#include <stdio.h>
#include "CVmm_DK_BSPAL.h"

int main ( int argc, char *argv[] )
{
    int32_t ret = 0;

    printf ( "start vmm shutdown\n" );

    ret = dk_bspal_vmm_stop ( 2 );

    if( ret < 0)
    {
        printf("vmm_stop failed\n");
    } else {
        printf("vmm_stop success\n");
    }

    return ret;
}
