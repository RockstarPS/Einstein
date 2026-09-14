/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stddef.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#include <sys/slog.h>
#include <sys/slogcodes.h>

#include <wfdqnx/wfdcfg.h>
#include <wfdqnx/wfdcfg_jacinto7.h>

#if defined(AM62X_EVB_DEBUG_ON)
	#define SLOG_DEBUG(x, ...)	slogf(_SLOGC_GRAPHICS_DISPLAY, _SLOG_DEBUG1,  "[wfdcfg] %s,%d: " x, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
	#define SLOG_DEBUG(x, ...)
#endif

#define SLOG_INFO(x, ...)		slogf(_SLOGC_GRAPHICS_DISPLAY, _SLOG_INFO,    "[wfdcfg] " x, ##__VA_ARGS__)
#define SLOG_WARNING(x, ...)	slogf(_SLOGC_GRAPHICS_DISPLAY, _SLOG_WARNING, "[wfdcfg] %s,%d: " x, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define SLOG_ERROR(x, ...)		slogf(_SLOGC_GRAPHICS_DISPLAY, _SLOG_ERROR,   "[wfdcfg] %s,%d: " x, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#endif /* _COMMON_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/common.h $ $Rev: 964147 $")
#endif
