/*
 * System Firmware Task Model data
 *
 * DMSC application specific data structure definitions
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef OSAL_DMSC_CORE_H
#define OSAL_DMSC_CORE_H

#include <lib/bitops.h>
#include <types/short_types.h>
#include <types/sbool.h>

#include <config.h>

#define OSAL_TASK_PENDING               BIT(0)
#define OSAL_TASK_PROCESSING_USER_MSG   BIT(1)
#define OSAL_TASK_PROCESSING_SECURE_MSG BIT(2)

enum {
#ifdef CONFIG_OSAL_MSG_FORWARDING
	FWD_PRIO,
#endif
#ifndef CONFIG_OSAL_MINIMAL_QUEUES
	HI_PRIO,
#endif
	LO_PRIO,
	MAX_NUM_PRIORITIES,
};

enum SEMAPHORE_IDS {
	SEMAPHORE_SEC = 0,
	SEMAPHORE_USER = 1,
	SEMAPHORE_USER_SYNC = 2,
	SEMAPHORE_MAX,
};

enum TASK_IDS {
	TASK_SEC = 0,
	TASK_USER = 1,
	TASK_MAX,
};

#define OSAL_SECURE_TASK_COUNT          1U
#define OSAL_USER_TASK_COUNT            1U

/**
 * \brief Initialize the secore core of the firmware
 *
 * \returns 0 on success, error code otherwise.
 */
s32 secure_core_init(void);

#endif /* OSAL_DMSC_CORE_H */
