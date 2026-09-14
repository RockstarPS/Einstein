/*
 * System Firmware Source File
 *
 * SoC configs for secure proxy for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/io.h>
#include <lib/container_of.h>
#include <types/short_types.h>
#include <comm_memory_soc.h>
#include <ring_acel_config_data.h>

#include "ring_accelerator.h"
#include "ring_acel_soc_data.h"

const u16 soc_ring_configurations_num = SOC_MAX_RING_CONFIG_INSTANCES;

const struct ring_config soc_ring_configurations[SOC_MAX_RING_CONFIG_INSTANCES] = {
	[AM62PX_SA3_SS0_RINGACC_0_RING_0005_CONF_017] = {
		.ra_idx			= AM62PX_RA_IDX_SA3_SS0_RINGACC_0,
		.ring_index		= 4U,
		.num_entries		= 8U,
		.ring_mode		= RING_MODE_MESSAGE,
		.elsize			= RING_ELSIZE_64,
		.buffer_idx		= AM62PX_SPROXY_MEM_IDX_DMSS_HSM_IPC_SRAM,
		.buffer_neg_offset	= 0x00000800U,
	},
	[AM62PX_SA3_SS0_RINGACC_0_RING_0004_CONF_018] = {
		.ra_idx			= AM62PX_RA_IDX_SA3_SS0_RINGACC_0,
		.ring_index		= 4U,
		.num_entries		= 8U,
		.ring_mode		= RING_MODE_MESSAGE,
		.elsize			= RING_ELSIZE_64,
		.buffer_idx		= AM62PX_SPROXY_MEM_IDX_DMSS_HSM_IPC_SRAM,
		.buffer_neg_offset	= 0x00000800U,
	},
	[AM62PX_SA3_SS0_RINGACC_0_RING_0004_CONF_019] = {
		.ra_idx			= AM62PX_RA_IDX_SA3_SS0_RINGACC_0,
		.ring_index		= 4U,
		.num_entries		= 8U,
		.ring_mode		= RING_MODE_MESSAGE,
		.elsize			= RING_ELSIZE_64,
		.buffer_idx		= AM62PX_SPROXY_MEM_IDX_DMSS_HSM_IPC_SRAM,
		.buffer_neg_offset	= 0x00000800U,
	},
};
