/*
 * Helper data for full SoC configuration
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SECURE_CORE_FULL
#define SECURE_CORE_FULL

#include <config.h>
#include <osal_config.h>
#include <dmsc_core.h>
#include <osal/user_core.h>
#include <msg/msg_private.h>
#include <hsm_data.h>
#include <dmsc_irq_map.h>

#ifdef CONFIG_SECURITY_BOOT_HSM_M4F
#pragma DATA_SECTION(secure_lo_tifs_msg_buffer,".data_secure");

static u32 secure_lo_tifs_msg_buffer[HW_QUEUE_SIZE];
static struct msg_data secure_lo_tifs_main_msg_data;
#endif
struct hsm_evt_data hsm_evt_data_list[] = {
	/* secure_lo_tifs_main_msg_data */
	{
		.irq_num = NVIC_IRQ(HSM_SEC_PROXY_RX_IRQ),
		.priority = 255,
		.evt_type = TIFS_EVT_TYPE_SEC_PROXY_MSG,
		.int_data.msg_data ={
			.hw_msg_queue_id		= 0U,
			.hw_msg_buffer			= secure_lo_tifs_msg_buffer,
			.hw_msg_buffer_sz		= HW_QUEUE_SIZE,
			.forwarded_hw_msg_buffer	= NULL,
			.forwarded_hw_msg_buffer_sz	= 0,

			.secure_msg_data		= &secure_lo_tifs_main_msg_data,
			.user_msg_data			= NULL,
			.is_secure			= STRUE,
		},
		.irq_handler = sec_proxy_isr_handler,
		.proc_handler = sec_proxy_process_handler,
	}
};

#endif
