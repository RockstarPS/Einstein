/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_sec_ctx_bootcfg.c
 *
 * \brief Boot configuration items for SA2UL Sec Ctx module
 */

#include <sa2ul_sec_ctx_bootcfg.h>
#include <hosts_internal.h>
#include <hosts.h>

const struct sa2ul_ctx_bootcfg sec_ctx_bootcfg_data = {
	.sa2ul_ctx_dma_privid	= 152U,
	{
		HOST_ID_TIFS,
		HOST_ID_WKUP_0_R5_0,
		HOST_ID_WKUP_0_R5_0,
		HOST_ID_WKUP_0_R5_0,
		HOST_ID_WKUP_0_R5_0,
		HOST_ID_WKUP_0_R5_0,
		HOST_ID_A53_0,
		HOST_ID_A53_0,
		HOST_ID_A53_0,
		HOST_ID_A53_0,
		HOST_ID_A53_0,
		HOST_ID_A53_2,
		HOST_ID_A53_2,
		HOST_ID_A53_2,
		HOST_ID_A53_2,
		HOST_ID_A53_2
	}
};
