/*
 * Copyright (C) 2020-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef CRED_BOOTCFG_H_
#define CRED_BOOTCFG_H_

#include <types/short_types.h>
#include <types/ftbool.h>
#include <isc_limits.h>
#define ISC_CRED_GROUPS (4U)

struct isc_cfg_cred_item {
	u16	ch_start;
	u16	ch_end;
	u8	owner_index;
} __attribute__((packed));

struct isc_cfg_cred_group {
	u16				id;
	u16				num_items;
	u32				mmr_address;
	struct isc_cfg_cred_item	*items[ISC_MAX_CHANNELS];
} __attribute__((packed));

#define DECL_ISC_CFG_CRED_GROUP(name, actual_num_items)	\
	static struct name { \
		u16				id; \
		u16				num_items; \
		u32				mmr_address; \
		struct isc_cfg_cred_item	*items[actual_num_items]; \
	} __attribute__((packed))

struct cred_bootcfg {
	struct isc_cfg_cred_group *cred[ISC_CRED_GROUPS];
} __attribute__((__packed__));
#endif
