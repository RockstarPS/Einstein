/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <hosts.h>
#include <hosts_internal.h>
#include <master_ids.h>
#include "cred_bootcfg.h"

struct isc_cfg_cred_item isc_cred_32_0 = {
	.ch_start	= 0U,
	.ch_end		= 31U,
	.owner_index	= HOST_ID_TIFS,
};

DECL_ISC_CFG_CRED_GROUP(, 1) isc_cfg_cred_group_32 = {
	.id		= 0U,
	.num_items	= 1,
	.mmr_address	= 0x4580B000,
	{
		(struct isc_cfg_cred_item *) &isc_cred_32_0,
	},
};

/**
 * Tx Channels =  99
 * Rx Channels =  51
 * Total       = 150
 */
struct isc_cfg_cred_item isc_cred_150_0 = {
	.ch_start	= 0U,
	.ch_end		= 149U,
	.owner_index	= HOST_ID_RM,
};

/* design_name: pktdma_cred_cred */
/* name: PKTDMA_CRED             */
DECL_ISC_CFG_CRED_GROUP(, 1) isc_cfg_cred_group_150 = {
	.id		= 1U,
	.num_items	= 1,
	.mmr_address	= 0x45810000,
	{
		(struct isc_cfg_cred_item *) &isc_cred_150_0,
	},
};

struct isc_cfg_cred_item isc_cred_82_0 = {
	.ch_start	= 0U,
	.ch_end		= 81U,
	.owner_index	= HOST_ID_RM,
};

/* design_name: bcdma_cred_cred */
/* name: BCDMA_CRED             */
DECL_ISC_CFG_CRED_GROUP(, 1) isc_cfg_cred_group_82 = {
	.id		= 2U,
	.num_items	= 1,
	.mmr_address	= 0x45812000,
	{
		(struct isc_cfg_cred_item *) &isc_cred_82_0,
	},
};

struct isc_cfg_cred_item isc_cred_6_0 = {
	.ch_start	= 0U,
	.ch_end		= 5U,
	.owner_index	= HOST_ID_RM,
};

/* design_name: dmss_csi_am62a->bcdma_cred_cred    */
/* name: dmss_csi_am62a_main_0_bcdma_0->BCDMA_CRED */
DECL_ISC_CFG_CRED_GROUP(, 1) isc_cfg_cred_group_6 = {
	.id		= 3U,
	.num_items	= 1,
	.mmr_address	= 0x45813000,
	{
		(struct isc_cfg_cred_item *) &isc_cred_6_0,
	},
};

struct cred_bootcfg cred_bootcfg_data = {
	{
		(struct isc_cfg_cred_group *) &isc_cfg_cred_group_32,
		(struct isc_cfg_cred_group *) &isc_cfg_cred_group_150,
		(struct isc_cfg_cred_group *) &isc_cfg_cred_group_82,
		(struct isc_cfg_cred_group *) &isc_cfg_cred_group_6
	},
};
