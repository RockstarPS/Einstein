/*
 * System Firmware Source File
 *
 * SoC Data for Secure Proxy Instances for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/io.h>
#include <lib/container_of.h>
#include <types/errno.h>
#include <types/short_types.h>
#include <comm_memory_soc.h>
#include <soc_devgrps.h>

#include "ring_accelerator.h"
#include "secure_proxy_description.h"
#include "sec_proxy_soc_data.h"
#include "ring_acel_soc_data.h"

const u8 soc_secure_proxy_instances_num = SOC_MAX_SEC_PROXY_INSTANCES;

const struct secure_proxy soc_secure_proxy_instances[SOC_MAX_SEC_PROXY_INSTANCES] = {
	/*
	 * [1] AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0: Secure proxy instance:
	 * SA3_SS0_SEC_PROXY_0 linked to RA inst: SA3_SS0_RINGACC_0
	 */
	[AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0] = {
		.baseaddr_cfg_rt		= 0x44880000ULL,
		.baseaddr_cfg_scfg		= 0x44860000ULL,
		.baseaddr_src_target_data	= 0x43600000ULL,
		.sproxy_target_hl		= 0x00400000ULL,
		.sproxy_ring_index_base		= 0U,
		.sproxy_ring_index_max		= 5U,
		.num_threads			= 16U,
		.devgrp				= SOC_DEVGRP_AM62PX_HSM_INTERNAL,
		.ra_idx				= AM62PX_RA_IDX_SA3_SS0_RINGACC_0,
		.buffer_idx			= AM62PX_SPROXY_MEM_IDX_DMSS_HSM_IPC_SRAM,
		.buffer_neg_offset		= 0x00000400U,
	},
};
