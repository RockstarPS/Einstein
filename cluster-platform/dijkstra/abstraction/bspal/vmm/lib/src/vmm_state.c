/* -------------------------------------------------------------------------
 *
 * Copyright (C) 2018-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved. Qualcomm Technologies Proprietary and Confidential.
 *
 *
 *//*!
 * \file   vmm_state.c
 * \brief
 *//*----------------------------------------------------------------------*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <amss/fdt_utils.h>
#include <pthread.h>
#include <stdbool.h>
#include <vmm_api.h>
#include "amss/lcm_utils.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include "CVmm_DK_BSPAL_Debug.h"

/* register as VMM client, and it will create a seperated thread */
#define BSPAL_VMM_PRIO 1 /* 0 is the highest level among [0,3] */
#define BSPAL_VMM_GVMS 0x1F
#define BSPAL_VMM_MAX 16

void *bspal_vmm_handle;

static int32_t bspal_vmmstate[BSPAL_VMM_MAX];

/* callback function for vmm */
static int bspal_vmm_callback(uint32_t vmid, uint32_t event, void *data)
{
    (void)data;

    bspal_vmmstate[vmid] = event;

    switch(event){
        case GVM_WDOG_BITE:
            LOG_DEBUG("gvm %d: wdog event\n", vmid);
            break;
        case GVM_CONTAINER_CRASH:
            LOG_DEBUG("gvm %d: container crash\n", vmid);
            break;
        case GVM_SHUTDOWN_LEVEL_2:
            LOG_DEBUG("gvm %d: shutdown level 2\n", vmid);
            break;
        case GVM_UP_AND_RUNNING:
            LOG_DEBUG("gvm %d: up and running\n", vmid);
            break;
        case GVM_STOPPED:
            LOG_DEBUG("gvm %d: stopped\n", vmid);
            break;
        default:
            LOG_DEBUG("vmm_state Client default  ");
            break;
    }

    return 0;
}

int32_t bspal_register_to_vmm(void)
{
    int ret = 0;
    int mask = 0;
    int32_t l_status_vmmreg = EOK;
    client_handler obj = &bspal_vmm_callback;

    /* The available GVMs' VMIDs could be different on different models,
     * and could be gotten from config files, e.g., DTS.
     * Currently, the hard-coding way is used as below.
     * Eventually, VMM can support the flexible "all-GVMs" registration.
     * Otherwise, hab_config.txt/DTS will have to be queried for the
     * vmids of "all-available-GVMs".
     */
    mask = (BSPAL_VMM_GVMS << VMID_SHIFT) | GVM_WDOG_BITE
            | GVM_SHUTDOWN_LEVEL_2 | GVM_CONTAINER_CRASH
            | GVM_UP_AND_RUNNING | GVM_STOPPED;

    ret = vmm_register_event_notification("bspal_vmm", obj, mask, BSPAL_VMM_PRIO, NULL, &bspal_vmm_handle);

    if (ret || !bspal_vmm_handle) {
        l_status_vmmreg = -1;
        LOG_ERROR("vmm register failed %d\n", ret);
    } else { }

    return l_status_vmmreg;
}

int32_t bspal_unregister_from_vmm( void )
{
    int ret = 0;
    int32_t l_status_vmmunreg = EOK;
    ret = vmm_unregister_event_notification(bspal_vmm_handle);

    if (ret) {
        l_status_vmmunreg = -1;
        LOG_ERROR("vmm unregister failed %d\n", ret);
    } else { }

    return l_status_vmmunreg;
}


int32_t bspal_read_status(int32_t vmm_id)
{
    return bspal_vmmstate[vmm_id];

}
