/*
 * NORTOS startup
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <string.h>
#include <types/short_types.h>
#include <lib/trace.h>
#include <arch/interrupt.h>
#include <osal_halt.h>
#include <types/errno.h>

/* Interrupt number of systick and supervisor call */
#define SYST_INT                                (15U)
#define SVC_INT                                 (11U)

extern u32 _privileged_bss_begin;
extern u32 _privileged_bss_end;

extern u32 _public_bss_begin;
extern u32 _public_bss_end;

extern int main(void);

void main_entry(void)
{
	/* Zero fill bss for ease of use */
	memset(&_privileged_bss_begin, 0, &_privileged_bss_end - &_privileged_bss_begin);
	memset(&_public_bss_begin, 0, &_public_bss_end - &_public_bss_begin);

	main();
}

void Default_handler()
{
	/* Get current interrupt number if an exception or unregistered interrupt has occured */
	u32 int_num = get_current_interrupt();

	/* If exception has occured from processor, excluding SVC and systick, notify */
	if (int_num < SYST_INT && int_num != SVC_INT) {
		TRACE_info("Exception occured");
	} else {
		TRACE_info("Unregistered Interrupt occured");
	}

	/* Terminate the execution */
	osal_system_halt(EFAIL);
}
