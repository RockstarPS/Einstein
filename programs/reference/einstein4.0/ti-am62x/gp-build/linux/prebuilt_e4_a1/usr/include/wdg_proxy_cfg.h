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
#include "dk_runtime_messages.h"

#define WDG_VMF_GID                     (DK_MSG_HEALTHDOMAINHEARTBEAT >> 8U)
#define WDG_VMF_HEALTHY_EID             (DK_MSG_HEALTHDOMAINHEARTBEAT & 0xFFU)
#define WDG_VMF_FATAL_ERROR_EID         (DK_MSG_HEALTHDOMAINFATALERROR & 0xFFU)
#define WDG_VMF_HEALTH_EVENT_RECORD_EID (DK_MSG_HEALTHEVENTRECORD & 0xFFU)

#define WDG_COMP_ID                     (0x00U)

#define WDG_DOMAIN_ID                   (0x01U)

#define WDG_VMF_MSG_PERIODICITY         (400)

#define PROCESS_MONITOR_LIST_SIZE       (4U)

#define PROCESS_MONITOR_LIST    \
    /*Process Name            Service Name                   Watchdog Enabled*/   \
    {"power_mgr",            "power_mgr.service",            false},              \
    {"display_mgr",          "display_mgr.service",          false},              \
    {"vmf",                  "vmf.service",                  false},              \
    {"ucl_proxy_vmf",        "ucl_proxy_vmf.service",        false}

#endif /* WDGPROXY_CFG_H */
