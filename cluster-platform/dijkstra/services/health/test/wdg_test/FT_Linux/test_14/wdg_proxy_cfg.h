//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------


#ifndef WDGPROXY_CFG_H
#define WDGPROXY_CFG_H

#include "wdg_proxy_types.h"

#define WDG_VMF_GID                     (0x10U)
#define WDG_VMF_HEALTHY_EID             (0x00U)
#define WDG_VMF_FATAL_ERROR_EID         (0x01U)
#define WDG_VMF_HEALTH_EVENT_RECORD_EID (0x02U)

#define WDG_COMP_ID                     (0xFE)

#define WDG_DOMAIN_ID                     (0x01U)

#define WDG_VMF_MSG_PERIODICITY         (1000)

#define PROCESS_MONITOR_LIST_SIZE       (1U)

#define PROCESS_MONITOR_LIST    \
    /*Process Name            Service Name                   Watchdog Enabled*/   \
    {"test_14",               "test_14.service",             true}

#endif /* WDGPROXY_CFG_H */
