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

#define WDG_VMF_GID 					(DK_MSG_HEALTHDOMAINHEARTBEAT >> 8U)
#define WDG_VMF_HEALTHY_EID             (DK_MSG_HEALTHDOMAINHEARTBEAT & 0xFFU)
#define WDG_VMF_FATAL_ERROR_EID         (DK_MSG_HEALTHDOMAINFATALERROR & 0xFFU)
#define WDG_VMF_HEALTH_EVENT_RECORD_EID (DK_MSG_HEALTHEVENTRECORD & 0xFFU)

#define WDG_COMP_ID                     (0x00U)

#define WDG_DOMAIN_ID                   (0x01U)

#define WDG_VMF_MSG_PERIODICITY         (1000)

#define PROCESS_MONITOR_LIST_SIZE       (9U)

#define PROCESS_MONITOR_LIST    \
    /*Entity Name          HB Enabled    HB Low Miss Action   HB High Miss Action      Death Action        Restart Count*/   \
	{"power_mgr",             TRUE,        WP_ACTION_FATAL,    WP_ACTION_FATAL,      WP_ACTION_FATAL,             0},        \
	{"slogger2",              FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,           20},       \
	{"dumper",                FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,           20},       \
	{"pipe",                  FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,           20},       \
	{"io-pkt-v4-hc",          FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_FATAL,             0},        \
	{"mq",                    FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_FATAL,             0},        \
	{"vmf",                   FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_FATAL,             0},        \
	{"dlt-daemon",            FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,           20},       \
	{"dlt-qnx-system",        FALSE,       WP_ACTION_NONE,     WP_ACTION_NONE,       WP_ACTION_RESTART,           20},        

#endif /* WDGPROXY_CFG_H */
