/*
 * System Firmware OSAL HALT layer
 *
 * OSAL HALT layer for system halt callout
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef HALT_H
#define HALT_H

#include <types/short_types.h>

/**
 * \brief System Halt function
 *
 * Halt the system due to some impossible to recover scenario. This may,
 * optionally attempt to provide diagnostic information for debug if supported.
 */
/*workaround for cmake build*/
#if 0
void osal_system_halt_internal(s32 error, const char *file, const u32 line);
#endif
void osal_system_halt_internal(s32 error, const u32 line); //kjohn

/** Macro expected to be used by callers to invoke \ref osal_system_halt */
#define osal_system_halt(error)	\
    osal_system_halt_internal((error), __LINE__)
	//osal_system_halt_internal((error), __HALT_FILENAME__, __LINE__)

#endif
