/*
 * Helper data for full SoC configuration
 * Copyright (C) 2017-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SECURE_CORE_MINIMAL
#define SECURE_CORE_MINIMAL

#include <config.h>
#include <osal_config.h>
#include <dmsc_core.h>
#include <osal/user_core.h>
#include <msg/msg_private.h>
#include <hsm_data.h>

#pragma DATA_SECTION(secure_lo_main_msg_buffer,".data_secure");
#pragma DATA_SECTION(secure_lo_main_msg_data,".data_secure");

#pragma DATA_SECTION(secure_forwarded_lo_main_msg_buffer,".data_user");

#ifdef CONFIG_SECURITY_BOOT_HSM_M4F
#pragma DATA_SECTION(secure_lo_hsm_msg_buffer,".data_secure");
#endif

/** Buffers to be used by secure world ONLY */
static u32 secure_lo_main_msg_buffer[HW_QUEUE_SIZE];

static u32 secure_forwarded_lo_main_msg_buffer[HW_QUEUE_SIZE];

static struct msg_data secure_lo_main_msg_data;

static struct msg_data secure_forwarded_lo_main_msg_data;

#ifdef CONFIG_SECURITY_BOOT_HSM_M4F
static struct msg_data secure_lo_hsm_main_msg_data;

static u32 secure_lo_hsm_msg_buffer[HW_QUEUE_SIZE];
#endif

#ifdef CONFIG_SYSFW_FRAMEWORK_BUILD
#pragma DATA_SECTION(user_lo_main_msg_buffer,".data_user");
#pragma DATA_SECTION(user_lo_msg_state,".data_user");
#pragma DATA_SECTION(user_lo_main_msg_data,".data_user");
#pragma DATA_SECTION(secure_forwarded_lo_main_msg_data,".data_user");
#pragma DATA_SECTION(user_lo_task_stack,".data_user");

static u32 user_lo_main_msg_buffer[HW_QUEUE_SIZE];


/*
 * These lists must be in order such that the same index in this array as
 * the corresponding msg_data array below points to data for the
 * same queue.
 */
static u32 *const secure_forwarded_lo_msg_buffer_list[DMSC_SEC_PROXY_INSTANCE_COUNT] = {
	secure_forwarded_lo_main_msg_buffer
};

static u32 *const user_lo_msg_buffer_list[DMSC_SEC_PROXY_INSTANCE_COUNT] = {
	user_lo_main_msg_buffer,
};

static struct osal_task_state user_lo_msg_state;

static struct msg_data user_lo_main_msg_data;

static u8 user_lo_task_stack[TASK_STACK_SIZE];

static struct msg_data *const secure_forwarded_lo_msg_data_list[DMSC_SEC_PROXY_INSTANCE_COUNT] = {
	&secure_forwarded_lo_main_msg_data,
};

static struct msg_data *const user_lo_msg_data_list[DMSC_SEC_PROXY_INSTANCE_COUNT] = {
	&user_lo_main_msg_data,
};
#endif

#ifdef CONFIG_OSAL_MSG_FORWARDING
#pragma DATA_SECTION(secure_dm2dmsc_msg_buffer,".data_secure");
#pragma DATA_SECTION(secure_dmsc2dm_resp_msg_buffer,".data_secure");
#pragma DATA_SECTION(secure_dm2dmsc_msg_data,".data_secure");
#pragma DATA_SECTION(secure_dmsc2dm_resp_msg_data,".data_secure");

static u32 secure_dm2dmsc_msg_buffer[HW_QUEUE_SIZE];
static u32 secure_dmsc2dm_resp_msg_buffer[HW_QUEUE_SIZE];

static struct msg_data secure_dm2dmsc_msg_data;
static struct msg_data secure_dmsc2dm_resp_msg_data;
#endif

#ifdef CONFIG_SYSFW_FRAMEWORK_BUILD
const struct osal_queue_hwi_data osal_user_queue_hwi_list[] = {
	/* user_lo_main_msg_hwi_data */
	{
		.irq_num = NVIC_IRQ(SEC_PROXY_MAIN_QUEUE_NON_SEC_LOW_IRQ),
		.hw_msg_queue_id = SEC_PROXY_MAIN_QUEUE_NON_SEC_LOW,
		.hw_msg_buffer = user_lo_main_msg_buffer,
		.hw_msg_buffer_sz = HW_QUEUE_SIZE,
		.user_semaphore_id = (s32) SEMAPHORE_USER,

		.user_msg_data = &user_lo_main_msg_data,

		.is_secure = SFALSE,
		.priority = 255,
	},
};

const u32 osal_user_queue_hwi_list_size = ARRAY_SIZE(osal_user_queue_hwi_list);

const struct osal_task_data osal_user_task_list[] = {
	/* user_lo_msg_task_data */
	{
		.task_id = (u32) TASK_USER,
		.hw_msg_buffer_list = user_lo_msg_buffer_list,
		.hw_msg_buffer_count = DMSC_SEC_PROXY_INSTANCE_COUNT,
		.hw_msg_num_priorities = MAX_NUM_PRIORITIES,
		.hw_msg_buffer_sz = HW_QUEUE_SIZE,

		.forwarded_hw_msg_buffer_list = secure_forwarded_lo_msg_buffer_list,
		.forwarded_hw_msg_buffer_count = DMSC_SEC_PROXY_INSTANCE_COUNT,

		.semaphore_id = (s32) SEMAPHORE_USER,

		.state = &user_lo_msg_state,

		.secure_msg_data = secure_forwarded_lo_msg_data_list,
		.user_msg_data = user_lo_msg_data_list,

		.priority = 1,
		.stack = user_lo_task_stack,
	},
};

const u32 osal_user_task_list_size = ARRAY_SIZE(osal_user_task_list);
#endif

#endif
