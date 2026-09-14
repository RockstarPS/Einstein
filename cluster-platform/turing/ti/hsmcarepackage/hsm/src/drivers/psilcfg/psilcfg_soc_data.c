/*
 * System Firmware Source File
 *
 * PSILCFG SoC Data for AM62Px device
 *
 * Copyright (C) 2020-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file psilcfg_soc_data.c
 *
 * \brief PSILCFG SoC Data for AM62Px device
 */

#include <psilcfg.h>

/** Number of PSILCFG instances */
#define SOC_MAX_PSILCFG_INSTANCES 1
const u8 soc_psilcfg_instances_num = SOC_MAX_PSILCFG_INSTANCES;

const struct psilcfg soc_psilcfg_instances[
	SOC_MAX_PSILCFG_INSTANCES] = {
	/* PSILCFG Instance: SA3_SS0_PSILCFG_0 (inside DMSS_HSM) */
	[0] = {
		.cfg_proxy	= 0x44801000UL
	},
};
