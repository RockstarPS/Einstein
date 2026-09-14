/*
 * System Firmware OSAL
 *
 * Task OSAL API Definition
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_TASKP_H
#define OSAL_TASKP_H

#include <types/short_types.h>
#include <stdbool.h>

typedef void (*taskp_fxn)(u32 arg0, u32 arg1);

/**
 * \brief Contains task configuration information
 *
 * \param priority Priority level of this task
 * \param arg0 First argument that will be provided to the taskp_fxn at runtime.
 * \param arg1 Second argument that will be provided to the taskp_fxn at
 *	       runtime.
 * \param stack Pointer to a data region to use as stack for this task.
 * \param stack_size Size of the data region that will serve as stack.
 */
struct taskp_params {
	s32	priority;
	u32	arg0;
	u32	arg1;
	bool	priv;
	u8	*stack;
	u32	stack_size;
};

/**
 * \brief Construct a task in the static task list
 *
 * \param task_id Task ID Number
 * \param task_fxn Pointer to the task worker function
 * \param params Pointer to a struct containing configuration for this Task
 *
 * \return 0 on success, error code otherwise.
 *
 * This function statically constructs a new Task object which will run
 * as soon as BIOS_start is called. The task_id must fall below MAX_TASKS
 * or an error will occur.
 */
s32 taskp_create(u32 task_id, taskp_fxn task_fxn, const struct taskp_params *params);

/**
 * \brief Destruct a task in the static task list and prepare for reuse
 *
 * \param task_id Task ID Number
 *
 * \return 0 on success, error code otherwise.
 *
 * This function destructs an existing static task object and makes sure it
 * is ready for reuse through another call to taskp_create.
 */
s32 taskp_delete(u32 task_id);

/**
 * \brief Get the arguments for the currently executing task
 *
 * \param a0 Pointer for returning the first argument
 * \param a1 Pointer for returning the second argument
 *
 * \return 0 on success, error code otherwise.
 *
 * When a task is constructed two arguments can be provided, arg0 and arg1,
 * as part of the taskp_params that are passed to the taskp_fxn everytime it
 * is called. This function allows those arguments to be fetched from anywhere
 * within the currently executing task as it is not always possible to propagate
 * them through multiple levels of function calls and world context changes.
 */
s32 taskp_get_current_task_args(u32 *a0, u32 *a1);

/**
 * \brief Defer scheduling of task for a certain amount of time.
 *
 * \param clock_ticks Number of ticks of the system clock to defer scheduling
 *
 * \return 0 on success, error code otherwise.
 */
s32 taskp_sleep(u32 clock_ticks);

#endif /* OSAL_HWIP_H */
