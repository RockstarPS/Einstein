/*
 * System Firmware OSAL
 *
 * Semaphore OSAL API Definition
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_SEMAPHOREP_H
#define OSAL_SEMAPHOREP_H

#include <config.h>
#include <types/short_types.h>
#include <types/sbool.h>

#define OSAL_WAIT_FOREVER       ((u32) 0xFFFFFFFFUL)
#define OSAL_NO_WAIT            ((u32) 0x0UL)

/**
 * \struct semaphorep_params
 * \brief Contains semaphore configuration information
 *
 * \param count The initial semaphore count
 */
struct semaphorep_params {
	s32 count;
};

/**
 * \brief Statically constructs a new semaphore
 *
 * \param semaphore_id Semaphore ID number
 * \param params Pointer to a struct containing configuration for this semaphore
 *
 * \return 0 on success, error code otherwise.
 *
 * This function statically constructs a new semaphore object. Semaphores are
 * identified by a semaphoreId which is nothing more than an index into an
 * array of static Semaphore_Structs. All SemaphoreP calls use this same index
 * to identify semaphores to maintain the actual static data scope in this file
 * and avoid the need to pass around the Sempahore objects.
 */
s32 semaphorep_create(s32 semaphore_id, struct semaphorep_params *params);

/**
 * \brief Destruct a semaphore in the static task list and prepare for reuse
 *
 * \param semaphore_id Semaphore ID Number
 *
 * \return Returns 0 on success or error code on failure.
 *
 * This function destructs an existing static semaphore object and makes
 * sure it is ready for reuse through another call to semaphorep_create.
 */
s32 semaphorep_delete(s32 semaphore_id);

/**
 * \brief Increment the semaphore and return or let pending task run
 *
 * \param semaphore_id Semaphore ID number
 *
 * \return Returns 0 on success or error code on failure.
 *
 * This function can be called from user or secure task.
 */
s32 semaphorep_post(s32 semaphore_id);

/**
 * \brief Increment the semaphore and return or let pending task run
 *
 * \param semaphore_id Semaphore ID number
 *
 * This is intended for use INSIDE of HWI service calls, as it is not
 * wrapped for usage in secure or user mode, it can only run in secure mode.
 *
 * \return Returns 0 on success or error code on failure.
 */
s32 semaphorep_post_core(s32 semaphore_id);

/**
 * \brief Wait for semaphore to post or return if posted since last call
 *
 * \param semaphore_id Semaphore ID number
 * \param timeout Wait period for semaphore before returning failure
 *
 * \return Returns STRUE on success or SFALSE on timeout or invalid semaphoreId.
 *
 * For the timeout value special constants OSAL_WAIT_FOREVER to never timeout
 * and OSAL_NO_WAIT to return immediately can be used.
 *
 * This function can be called from user or secure task.
 */
sbool semaphorep_pend(s32 semaphore_id, u32 timeout);

/**
 * \brief Wait for semaphore to post or return if posted since last call
 *
 * \param semaphore_id Semaphore ID number
 * \param timeout Wait period for semaphore before returning failure
 *
 * \return Returns STRUE on success or SFALSE on timeout or invalid semaphoreId.
 *
 * For the timeout value special constants OSAL_WAIT_FOREVER to never timeout
 * and OSAL_NO_WAIT to return immediately can be used.
 *
 * This is intended for use INSIDE of HWI service calls, as it is not
 * wrapped for usage in secure or user mode, it can only run in secure mode.
 */
sbool semaphorep_pend_core(s32 semaphore_id, u32 timeout);

#endif /* OSAL_SEMAPHOREP_H */
