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
#ifdef DEBUG_SLOG2
	#include <sys/slog2.h>
#endif
#ifdef DEBUG_SYSLOG
	#include <syslog.h>
#endif

#define DEBUG_NONE      0x00u
#define DEBUG_VERBOSE   0x01u
#define DEBUG_INFO      0x02u
#define DEBUG_ERR       0x04u

#ifdef DEBUG_SLOG2
	extern slog2_buffer_t slog2_handle;
#endif

#ifdef DEBUG
    #undef DEBUG
    #define DEBUG      (DEBUG_VERBOSE | DEBUG_INFO | DEBUG_ERR)
#else
    #define DEBUG      (DEBUG_ERR)
#endif

#if (DEBUG) & DEBUG_VERBOSE
	#ifdef DEBUG_SLOG2
		#define LOGV(fmt, ...)  \
			slog2f(slog2_handle, 0, SLOG2_DEBUG1, fmt, __VA_ARGS__)
	#elif DEBUG_SYSLOG
		#define LOGV(fmt, ...)  \
			syslog(LOG_DEBUG, fmt, __VA_ARGS__)
	#else
		#define LOGV(fmt, ...)  \
			fprintf(stderr, "VERBOSE [ %s:%d ] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__);
	#endif
#else
	#define LOGV(fmt, ...)
#endif

#if (DEBUG) & DEBUG_INFO
	#ifdef DEBUG_SLOG2
		#define LOGI(fmt, ...)  \
			slog2f(slog2_handle, 0, SLOG2_INFO, fmt, __VA_ARGS__)
	#elif DEBUG_SYSLOG
		#define LOGI(fmt, ...)  \
			syslog(LOG_INFO, fmt, __VA_ARGS__)
	#else
		#define LOGI(fmt, ...)  \
			fprintf(stderr, "INFO [ %s:%d ] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__);
	#endif
#else
	#define LOGI(fmt, ...)
#endif

#if (DEBUG) & DEBUG_ERR
	#ifdef DEBUG_SLOG2
		#define LOGE(fmt, ...)  \
			slog2f(slog2_handle, 0, SLOG2_ERROR, fmt, __VA_ARGS__)
	#elif DEBUG_SYSLOG
		#define LOGE(fmt, ...)  \
			syslog(LOG_ERR, fmt, __VA_ARGS__)
	#else
		#define LOGE(fmt, ...)  \
			fprintf(stderr, "ERROR [ %s:%d ] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__);
	#endif
#else
	#define LOGE(fmt, ...)
#endif

#endif  //DEBUG_H
