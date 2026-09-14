/*
 * System Firmware Source File
 *
 * DMSC IA maps for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/io.h>
#include <lib/container_of.h>
#include <types/short_types.h>
#include <dmsc_irq_map.h>

#include "dmsc_ia.h"


const u8 dmsc_ia_instances_num  = SOC_MAX_DMSC_IA_INSTANCES;

const u8 dmsc_ia_map_configuration_num[DMSC_1_IA_IRQ_INSTANCES] = {
	[0] = DMSC_1_IA_IRQ_INSTANCES,
};


const struct dmsc_ia_map dmsc_1_ia_map_configurations[DMSC_1_IA_IRQ_INSTANCES] = {
	[AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_CONF_1] = {
		.local_irq		= AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_IRQ,
		.global_event_id	= 0x0002U,
	},
};


const struct dmsc_ia_instance dmsc_ia[SOC_MAX_DMSC_IA_INSTANCES] = {
	[0] = {
		.cfg_cfg		= 0x44808000U,
		.cfg_imap		= 0x44809000U,
		.cfg_intr		= 0x44810000U,
		.vintr_cnt		= 8U,
		.sevt_cnt		= 100U,
		.local_irq_start	= 216U,
		.ia_offset		= 0U,
		.global_evt_base	= 0x0000U,
	},
};

const struct dmsc_ia_map *dmsc_ia_map_configurations[] = {
	[0] = &(dmsc_1_ia_map_configurations[0]),
};
