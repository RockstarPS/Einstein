/*============================================================================
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/

#include "dk_bspal_trng.h"
#include "trng_devctl.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define TRNG_RESMGR_PATH "/dev/trng"

uint8_t TRNG_Read(int filedes, uint8_t* trngbuf, size_t nbytes)
{
    trng_buf trng_buffer = {0};
    int      i;
    int      ret;
    ret = devctl(filedes, TRNG_READ, &trng_buffer, sizeof(trng_buffer), NULL);

    if (ret == EOK)
    {
        for (i = 0; i < nbytes; i++)
        {
            trngbuf[i] = trng_buffer.trngbf[i];
        }
    }

    return ret;
}

int32_t TRNG_Open()
{
    int32_t trng_fd;

    trng_fd = open(TRNG_RESMGR_PATH, O_RDWR);

    return trng_fd;
}

int32_t TRNG_Close(int32_t trng_fd)
{
    return close(trng_fd);
}
