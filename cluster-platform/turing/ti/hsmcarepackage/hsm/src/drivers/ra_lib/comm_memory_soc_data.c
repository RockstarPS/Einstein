/*
 * System Firmware Source File
 *
 * SoC Data for Communication memories for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <comm_memory.h>
#include <comm_memory_soc.h>

/**
 * Communication memory instances for AM62PX device
 */
const struct comm_memory_instance comm_memory_instances[COMM_MEMORY_INSTANCE_COUNT] = {
	/**
	 * dmss_hsm_ipc_sram: dmss_hsm_ipc_sram
	 */
	[AM62PX_SPROXY_MEM_IDX_DMSS_HSM_IPC_SRAM] = {
		.default_endaddr	= 0x0000000000201000ULL,
		.size			= 0x00001000U,
	},
};
