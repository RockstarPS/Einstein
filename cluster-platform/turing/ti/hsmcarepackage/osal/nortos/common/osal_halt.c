/*
 * DMSC firmware
 *
 * Cortex-M3 (CM3) firmware system management
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file osal_halt.c
 *
 * \brief System Halt functionality
 */

#include <osal.h>
#include <osal_config.h>
#include <osal_halt.h>
#include <lib/trace.h>

extern u32 halt_flag;

#ifdef CONFIG_TRACE
#if 0
void osal_system_halt_internal(s32 error, const char *file, const u32 line)
#endif
void osal_system_halt_internal(s32 error, const u32 line) //kjohn
#else
void osal_system_halt_internal(s32 error __attribute__((unused)), const char *file __attribute__((unused)), const u32 line __attribute__((unused)))
#endif
{
	volatile u8 halt = 0xAAU;

	halt_flag = 1;

	TRACE_err("osal_system_halt!\n");
	TRACE_err_arg("errno: ", (u32) error);
	TRACE_err("\n");
	//TRACE_err((const u8 *) file);
	//TRACE_err_arg(" line: ", line);
	TRACE_err("\n");
	TRACE_info("\r\n HSM OSAL HALT");
	#if 0
	while (halt == 0xAAU) {
		/* Do Nothing for now - Just spin. */
	}*/
#endif
}

