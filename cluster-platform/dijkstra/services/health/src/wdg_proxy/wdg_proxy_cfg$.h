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

#define WDG_VMF_GID                     (0x10)
#define WDG_VMF_HEALTHY_EID             (0x00)
#define WDG_VMF_FATAL_ERROR_EID         (0x01)

#define WDG_COMP_ID                     (0xFE)

#define WDG_DOMAIN_ID                     (0x01)

#define WDG_VMF_MSG_PERIODICITY         (1000)

#define PROCESS_MONITOR_LIST_SIZE       (4)

#ifdef __QNX__
#define PROCESS_MONITOR_LIST    \
    /*Entity Name    HB Enabled    HB Low Miss Action   HB High Miss Action      Death Action        Restart Count*/ \
    {"resmgr_jdi",     FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,          20},       \
    {"resmgr_dio",     FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,          20},       \
    {"resmgr_lp8860",  FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,          20},       \
    {"resmgr_pwm",     FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,          20},       \
    //  {"wdg_test",       TRUE,        WP_ACTION_NONE,     WP_ACTION_RESTART,    WP_ACTION_RESTART,          20}
#endif

#ifdef __linux__
#define PROCESS_MONITOR_LIST    \
    /*Process Name            Service Name                   Watchdog Enabled*/   \
    {"dlt-daemon",           "dlt-daemon.service",           false},              \
    {"power_mgr",            "power_mgr.service",            false},              \
    {"vmf",                  "vmf.service",                  false},              \
    {"ucl_proxy_vmf",        "ucl_proxy_vmf.service",        false}
#endif

#endif /* WDGPROXY_CFG_H */
