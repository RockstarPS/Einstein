/*
 * System Firmware OSAL
 *
 * NORTOS Implementation of OSAL Semaphore API
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <stdbool.h>

#include <osal_config.h>
#include <osal_secure.h>
#include <semaphorep.h>
#include <hwip.h>

#include <lib/bitops.h>
#include <types/errno.h>

/**
 * \def SEMAPHOREF_INITIALIZED
 * Semaphore is initialized and valid.
 */
#define SEMAPHOREF_INITIALIZED                  BIT(0)

struct semaphorep_info {
	u8 flags;
};

static u32 semaphore_count = 0;

static struct semaphorep_info semaphore[MAX_SEMAPHORES];

static inline sbool semaphorep_check_range(s32 semaphore_id)
{
	sbool result = STRUE;

	if ((semaphore_id >= (s32) MAX_SEMAPHORES) || (semaphore_id < 0)) {
		result = SFALSE;
	}

	return result;
}

static inline sbool semaphorep_check_valid(s32 semaphore_id)
{
	sbool result = STRUE;

	if ((semaphorep_check_range(semaphore_id) == SFALSE) ||
	    ((semaphore[semaphore_id].flags & SEMAPHOREF_INITIALIZED) == 0U)) {
		result = SFALSE;
	}

	return result;
}

s32 semaphorep_create(s32 semaphore_id, struct semaphorep_params *params)
{
	s32 error = 0;

	semaphore_count = 0;

	/*
	 * Only check range here as Semaphore cannot be valid before
	 * we initialize
	 */
	if (semaphorep_check_range(semaphore_id) == SFALSE) {
		error = -EINVAL;
	}

	if (params != NULL) {
		semaphore_count = params->count;
	}

	if (error == SUCCESS) {
		semaphore[semaphore_id].flags |= SEMAPHOREF_INITIALIZED;
	}

	return error;
}

s32 semaphorep_delete(s32 semaphore_id)
{
	s32 error = 0;

	if (semaphorep_check_valid(semaphore_id) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		semaphore[semaphore_id].flags = 0;
	}

	return error;
}

s32 semaphorep_post_core(s32 semaphore_id)
{
	s32 error = 0;

	if (semaphorep_check_valid(semaphore_id) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		u32 key = 0;

		key = hwip_disable();

		(semaphore_count)++;

		hwip_restore(key);
	}

	return error;
}

#pragma CODE_SECTION(semaphorep_post, ".kernel_wrapper_funcs");
s32 semaphorep_post(s32 semaphore_id)
{
	s32 ret;

	osal_enter_priv_mode();
	ret = semaphorep_post_core(semaphore_id);
	osal_restore_priv_mode();

	return ret;
}

sbool semaphorep_pend_core(s32 semaphore_id, u32 timeout)
{
	sbool result = STRUE;

	if (semaphorep_check_valid(semaphore_id) == SFALSE) {
		result = SFALSE;
	}

	if (result == STRUE) {
		bool res;
		u32 key = 0;

		key = hwip_disable();

		while ((semaphore_count == 0) && (timeout == OSAL_WAIT_FOREVER)) {
			hwip_restore(key);

			wfi();

			key = hwip_disable();
		}

		if (semaphore_count > 0) {
			(semaphore_count)--;
			res = true;
		} else {
			res = false;
		}

		hwip_restore(key);

		if (res == true) {
			result = STRUE;
		} else {
			result = SFALSE;
		}
	}

	return result;
}

#pragma CODE_SECTION(semaphorep_pend, ".kernel_wrapper_funcs");
sbool semaphorep_pend(s32 semaphore_id, u32 timeout)
{
	sbool ret;

	osal_enter_priv_mode();
	ret = semaphorep_pend_core(semaphore_id, timeout);
	osal_restore_priv_mode();

	return ret;
}
