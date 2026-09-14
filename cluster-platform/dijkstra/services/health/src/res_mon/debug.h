//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <sys/slog2.h>
#include <sys/procmgr.h>

#define DEBUG_NONE      0x00u
#define DEBUG_VERBOSE   0x01u
#define DEBUG_INFO      0x02u
#define DEBUG_WARNING   0x03u
#define DEBUG_ERR       0x04u

extern char                        *__progname;
extern slog2_buffer_t              slog2_handle;
extern slog2_buffer_set_config_t   slog2_config;
extern uint8_t res_mon_enable_logging ( void );

#ifdef DEBUG_LOGGING_ENABLED
    #define DEBUG      (DEBUG_VERBOSE | DEBUG_INFO | DEBUG_WARNING | DEBUG_ERR)
#else
    #define DEBUG      (DEBUG_ERR)
#endif

#if (DEBUG) & DEBUG_VERBOSE
#define LOGV(fmt, ...)  \
    slog2f(slog2_handle, 0, SLOG2_DEBUG1, fmt, __VA_ARGS__)
#else
#define LOGV(fmt, ...)
#endif

#if (DEBUG) & DEBUG_INFO
#define LOGI(fmt, ...)  \
    slog2f(slog2_handle, 0, SLOG2_INFO, fmt, __VA_ARGS__)
#else
#define LOGI(fmt, ...)
#endif

#if (DEBUG) & DEBUG_WARNING
#define LOGW(fmt, ...)  \
    slog2f(slog2_handle, 0, SLOG2_WARNING, fmt, __VA_ARGS__)
#else
#define LOGW(fmt, ...)
#endif

#if (DEBUG) & DEBUG_ERR
#define LOGE(fmt, ...)  \
    slog2f(slog2_handle, 0, SLOG2_ERROR, fmt, __VA_ARGS__)
#else
#define LOGE(fmt, ...)
#endif

#endif  //DEBUG_H
