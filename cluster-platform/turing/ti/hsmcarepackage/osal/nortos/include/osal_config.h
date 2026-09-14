/*
 * System Firmware OSAL
 *
 * OSAL Configuration defines
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_CONFIG_H
#define OSAL_CONFIG_H

#include "config.h"
#include "dmsc_core.h"
#include "osal_platform.h"
#include "osal_hwi_ids.h"

/*
 * Because all HWIs, Tasks, and Semaphores are statically defined we
 * must know what the maximum possible number of each is at build time
 */
#define MAX_TASKS               TASK_MAX
#define MAX_HWIS                HWI_MAX
#define MAX_SEMAPHORES          SEMAPHORE_MAX

/*
 * Task stacks are also static memory blocks so the size must be
 * defined below.
 */
#define TASK_STACK_SIZE         (1536 + 128)

/**
 * \brief Number of clock ticks between calls to clock handler.
 */
#define CLK_FUNCTION_TIMEOUT_TICKS                      5

#endif /* OSAL_CONFIG_H */
