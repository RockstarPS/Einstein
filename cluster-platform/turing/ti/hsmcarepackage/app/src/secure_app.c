/*
 * \file secure_app.c
 *
 * \brief TIFS framework shell for ISR and task.
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/* Use of various types definitions */
#include <types/errno.h>

#include <semaphorep.h>
#include <dmsc_core.h>

/* OSAL interface */
#include <osal_halt.h>

/* Local application include */
#include "ti_app.h"

void secure_msg_hwi_fxn(u32 a __attribute__((unused)))
{
	s32 ret = SUCCESS;

	/* Call TIFS isr handler */
	ret = HSM_isr();

	/* Custom handling for TIFS firmware */
	if (ret == HSM_SUCCESS) {
		/* Schedule the task to run for processing the data */
	} else if (ret == HSM_FAILURE) {
		/* Catastrophic failure, so halt */
		osal_system_halt(ret);
	}
}

void secure_msg_task_fxn(u32 a0 __attribute__((unused)), u32 a1 __attribute__((unused)))
{
	s32 ret = -EFAIL;
	//sbool ret_bool;
	volatile u32 loopForever = 1U;
	/* Call HSM processing handler */
	ret = HSM_SUCCESS;//HSM_process());
	if (ret == HSM_FAILURE) {
		osal_system_halt(ret);
	}
	
}
