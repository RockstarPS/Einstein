/*
 * System Firmware OSAL Trace layer
 *
 * OSAL Core Debug Trace layer APIs
 *
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/trace.h>

void osal_trace_print_output(u8 *buf, u32 len)
{
	u32 i;

	for (i = 0; i < len; i++) {
		/*
		 * The underlying RTOS implementation does not care
		 * about return value.
		 */
		(void) trace_print_output_char_core(buf[i]);
	}
}
