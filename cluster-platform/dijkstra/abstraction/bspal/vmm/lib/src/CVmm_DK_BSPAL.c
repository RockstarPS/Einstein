/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2018. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** @Name           CVmm_DK_BSAPAL.c
 **
 ** @Description    This module will be useful to Start/Stop/Read the VMM state.
 **
 **
 ** @Organization   GUI Software Section, Visteon
 **
 ** @Author         SKOPPISE
 **
 ** @Version
 **============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <devctl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>

#include "CVmm_DK_BSPAL.h"
#include "CVmm_DK_BSPAL_Debug.h"

int32_t vmm_fd;

static int32_t vmm_open( void );
static int32_t vmm_close( void );

static int32_t vmm_open( void )
{
    int32_t l_status_vmmopen_S32 = EOK;

    vmm_fd = open((char *) VMM_PATH, O_RDWR);

    if(vmm_fd != -1)
    {
        l_status_vmmopen_S32 = EOK;
    }
    else
    {
        l_status_vmmopen_S32 = -1;
        LOG_ERROR("vmm_bspal Failed to open '%d' ", vmm_fd);
    }
    
    return l_status_vmmopen_S32;
}

static int32_t vmm_close( void )
{
    int32_t l_status_vmmclose_S32 = EOK;

    if(0 == close(vmm_fd))
    {
        l_status_vmmclose_S32 = EOK;
    }

    return l_status_vmmclose_S32;
}

int32_t dk_bspal_vmm_init ( void )
{
    int32_t l_status_vmminit_S32 = EOK;

    l_status_vmminit_S32 = bspal_register_to_vmm();

    if ( l_status_vmminit_S32 < 0)
    {
        l_status_vmminit_S32 = -1;
        LOG_ERROR("vmm_bspal init failed");
    } else { }

    return l_status_vmminit_S32;
}

int32_t dk_bspal_vmm_deinit ( void )
{
    int32_t l_status_vmmdeinit_S32 = EOK;

    l_status_vmmdeinit_S32 = bspal_unregister_from_vmm();

    if ( l_status_vmmdeinit_S32 < 0)
    {
        l_status_vmmdeinit_S32 = -1;
        LOG_ERROR("vmm_bspal deinit failed");
    } else { }

    return l_status_vmmdeinit_S32;
}

int32_t dk_bspal_vmm_start(uint8_t vmm_id)
{
    int32_t l_status_vmmstart_S32 = EOK;
    char l_buf_S8[BUF_MAX];

    l_status_vmmstart_S32 = vmm_open();
    if ( l_status_vmmstart_S32 < 0)
    {
        l_status_vmmstart_S32 = -1;
        LOG_ERROR("vmm_bspal start :: Error opening %s", VMM_PATH);
    }
    else
    {
        (void) snprintf((char *) l_buf_S8, BUF_MAX, "control %d %d ", VMM_START, vmm_id);
        l_status_vmmstart_S32 = write(vmm_fd, l_buf_S8, sizeof(l_buf_S8));

        if ( l_status_vmmstart_S32 < 0 )
        {
            l_status_vmmstart_S32 = -1;
            LOG_ERROR("vmm_bspal start :: Error while write: %s", strerror ( l_status_vmmstart_S32 ));
        }
        else
        {
            l_status_vmmstart_S32 = vmm_close();
            if ( EOK != l_status_vmmstart_S32)
            {
                l_status_vmmstart_S32 = -1;
                LOG_ERROR("Error in  close fd: %s", strerror ( l_status_vmmstart_S32 ));
            }
            else
            {
                l_status_vmmstart_S32 = 1;
            }
        }
    }
    return l_status_vmmstart_S32;
}

int32_t dk_bspal_vmm_stop(uint8_t vmm_id)
{
    int32_t l_status_vmmstop_S32 = EOK;
    char l_buf_S8[BUF_MAX];

    l_status_vmmstop_S32 = vmm_open();
    if ( l_status_vmmstop_S32 < 0)
    {
        l_status_vmmstop_S32 = -1;
        LOG_ERROR("vmm_bspal stop :: Error opening %s", VMM_PATH);
    }
    else
    {
        (void) snprintf((char *) l_buf_S8, BUF_MAX, "control %d %d ", VMM_STOP, vmm_id);
        l_status_vmmstop_S32 = write(vmm_fd, l_buf_S8, sizeof(l_buf_S8));

        if ( l_status_vmmstop_S32 < 0 )
        {
            l_status_vmmstop_S32 = -1;
            LOG_ERROR("vmm_bspal stop :: Error while write: %s", strerror ( l_status_vmmstop_S32 ));
        }
        else
        {
            l_status_vmmstop_S32 = vmm_close();
            if ( EOK != l_status_vmmstop_S32)
            {
                l_status_vmmstop_S32 = -1;
                LOG_ERROR("Error in  close fd: %s", strerror ( l_status_vmmstop_S32 ));
            }
            else
            {
                l_status_vmmstop_S32 = 1;
            }
        }
    }
    return l_status_vmmstop_S32;
}

int32_t dk_bspal_vmm_getstatus(uint8_t vmm_id)
{
    int32_t l_status_vmmread_S32 = EOK;

    l_status_vmmread_S32 = bspal_read_status(vmm_id);

    return l_status_vmmread_S32;
}
