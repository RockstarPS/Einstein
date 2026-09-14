/*
 * System Firmware Source File
 *
 * SoC Data for Ring Accelerator Instances for AM62PX device
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
#include <soc_devgrps.h>

#include "ring_accelerator.h"
#include "ring_acel_soc_data.h"

const u8 soc_ring_accelerator_instances_num = SOC_MAX_RA_INSTANCES;

const struct ring_accelerator soc_ring_accelerator_instances[SOC_MAX_RA_INSTANCES] = {
	/*
	 * [1] RA instance: SA3_SS0_RINGACC_0
	 */
	[AM62PX_RA_IDX_SA3_SS0_RINGACC_0] = {
		.baseaddr_cfg__cfg	= 0x448C0000U,
		.baseaddr_cfg__rt	= 0x44C00000U,
		.num_rings		= 5U,
		.devgrp			= SOC_DEVGRP_AM62PX_HSM_INTERNAL,
	},
};
