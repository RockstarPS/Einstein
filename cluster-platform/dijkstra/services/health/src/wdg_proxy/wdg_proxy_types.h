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


#ifndef WDGPROXY_TYPES_H
#define WDGPROXY_TYPES_H

#include <stdint.h>
#include <unistd.h>
#include <string.h>

#ifndef TRUE
    #define TRUE            (1U)
#endif

#ifndef FALSE
    #define FALSE           (0U)
#endif

#define WP_OK           (0)
#define WP_FAIL         (-1)

#define WP_ACTION_NONE               (0x0U)
#define WP_ACTION_RESTART            (0x1U)
#define WP_ACTION_FATAL              (0x2U)

#define WP_RECORD_TYPE_NO_FATAL_ERROR   (0U)
#define WP_RECORD_TYPE_FATAL_ERROR      (1U)

#define WP_RESTART_EVENT_TYPE_UNKNOWN         (0U)
#define WP_RESTART_EVENT_TYPE_LOW_HB_MISS     (1U)
#define WP_RESTART_EVENT_TYPE_HIGH_HB_MISS    (2U)
#define WP_RESTART_EVENT_TYPE_DEATH           (3U)
#define WP_RESTART_EVENT_TYPE_WDG_FAILURE     (4U)
#define WP_RESTART_EVENT_TYPE_INACTIVE        (5U)

#endif /* WDGPROXY_TYPES_H */
