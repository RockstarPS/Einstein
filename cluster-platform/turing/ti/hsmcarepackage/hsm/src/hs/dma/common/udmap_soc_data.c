/*
 * System Firmware Source File
 *
 * UDMAP SoC Data for AM62p device
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file udmap_soc_data.c
 *
 * \brief UDMAP SoC Data for AM62p device
 */

#include "udmap.h"

/** Number of UDMAP instances */
#define SOC_MAX_UDMAP_INSTANCES 1
const u8 soc_udmap_instances_num = SOC_MAX_UDMAP_INSTANCES;

const struct udmap soc_udmap_instances[
	SOC_MAX_UDMAP_INSTANCES] = {
	/* inst_design_name: sa3ss_am62a_main_0_pktdma_0 */
	[0] = {
		.cfg_tchanrt	= 0x44918000ULL,
		.cfg_tchan	= 0x44913000ULL,
		.cfg_rchan	= 0x44912000ULL,
		.cfg_gcfg	= 0x44910000ULL,
		.cfg_rchanrt	= 0x44914000ULL,
		.cfg_rflow	= 0x44911000ULL,
		.num_tx_chans	= 2U,
		.num_rx_chans	= 4U,
		.num_rx_flows	= 16U
	},
};
