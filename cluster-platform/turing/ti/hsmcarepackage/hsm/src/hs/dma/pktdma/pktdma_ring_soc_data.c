/*
 * System Firmware Source File
 *
 * PKTDMA Ring SOC data for AM62p device
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "pktdma_ring.h"

#define SOC_MAX_PKTDMA_RING_INSTANCES (1U)

const u8 soc_pktdma_ring_instances_num = SOC_MAX_PKTDMA_RING_INSTANCES;

const struct pktdma_ring soc_pktdma_ring_instances[SOC_MAX_PKTDMA_RING_INSTANCES] = {
	/* inst_design_name: sa3ss_am62a_main_0_pktdma_0 */
	{
		/* design_name: pktdma__cfg__ring */
		.baseaddr_cfg__cfg      = 0x4491a000ULL,
		/* design_name: pktdma__cfg__ringrt */
		.baseaddr_cfg__rt       = 0x44940000ULL,
		.num_rings              = 32U,
	},
};
