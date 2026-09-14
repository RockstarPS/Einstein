/*
 * System Firmware OSAL
 *
 * NORTOS Implementation of OSAL Task API
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <osal_config.h>
#include <taskp.h>
#include <hwip.h>

#include <lib/bitops.h>
#include <types/errno.h>
#include <types/sbool.h>
#include <string.h>

#define UNUSED(x)                                               (void) (x)

/* SysTick timer interrupt implementation */
#define SYST_BASE                               (0xE000E010u)
#define SYST_CVR                                (volatile u32 *) ((SYST_BASE) +0x08u)
#define SYST_RVR                                (volatile u32 *) ((SYST_BASE) +0x04u)
#define SYST_CSR                                (volatile u32 *) ((SYST_BASE) +0x00u)

s32 taskp_create(u32 task_id, taskp_fxn task_fxn,
		 const struct taskp_params *params)
{
	/* Task is not used in nortos. */
	UNUSED(task_id);
	UNUSED(task_fxn);
	UNUSED(params);

	return SUCCESS;
}

s32 taskp_delete(u32 task_id)
{
	UNUSED(task_id);

	return SUCCESS;
}

s32 taskp_get_current_task_args(u32 *a0, u32 *a1)
{
	UNUSED(a0);
	UNUSED(a1);

	return SUCCESS;
}

s32 taskp_sleep(u32 clock_ticks)
{
	volatile u32 *cvr = SYST_CVR;
	volatile u32 *rvr = SYST_RVR;
	volatile u32 *csr = SYST_CSR;

	unsigned int key;

	u32 current_num_ticks = *cvr;

	key = hwip_disable();

	/* Check if clock ticks can be counted down in current round. */
	if (current_num_ticks < clock_ticks) {
		/* If not, then wait for tick count to become zero. */
		while ((*csr & 0x10000) == 0) {
		}
		/* Decrement elapsed number of ticks from clock count. */
		clock_ticks -= current_num_ticks;
		/* Wait for the remaining number of ticks. */
		while (*cvr > (*rvr - clock_ticks)) {
		}
	} else {
		while (*cvr > (current_num_ticks - clock_ticks)) {
		}
	}

	hwip_restore(key);

	/* The SYS/BIOS implementation of this returns nothing so always return success */
	return SUCCESS;
}
