/*
 * Copyright (C) 2020-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <cred_bootcfg.h>
#include <types/ftbool.h>
#include <types/fterr.h>
#include <lib/bitops.h>
#include <cred.h>
#include <common_funcs.h>

extern struct cred_bootcfg cred_bootcfg_data;

static ftbool cred_lookup_item(u32 isc_id, u32 ring_id,
			       struct isc_cfg_cred_group *cred_group[1],
			       struct isc_cfg_cred_item *cred_item[1])
{
	u32 i = 0U, j = 0U;
	ftbool ret = FT_FALSE;
	struct isc_cfg_cred_group **grp = cred_bootcfg_data.cred;

	cred_group[0] = NULL;
	cred_item[0] = NULL;

	for (i = 0; i < ISC_CRED_GROUPS; i++) {
		if (grp[i]->id == isc_id) {
			for (j = 0; j < grp[i]->num_items; j++) {
				if ((grp[i]->items[j]->ch_start <= ring_id) &&
				    (ring_id <= grp[i]->items[j]->ch_end)) {
					ret = FT_TRUE;
					cred_group[0] = grp[i];
					cred_item[0] = grp[i]->items[j];
				}
			}
		}
	}

	return ret;
}

u32 cred_format_ctrl_word(struct master_creds *creds)
{
	u32 ctrl_reg_val = 0;

	if (creds != NULL) {
		/*  Set the privid */
		ctrl_reg_val = set_field(ctrl_reg_val, CRED_PRIVID_END,
					 CRED_PRIVID_START, creds->privid);

		/*  If master is secure, set the secure bit and the check secure flag */
		if (ft_is_true(creds->secure)) {
			ctrl_reg_val = set_field(ctrl_reg_val, CRED_SEC_END,
						 CRED_SEC_START, 1U);
			ctrl_reg_val = set_field(ctrl_reg_val,
						 CRED_CHECK_SEC_END,
						 CRED_CHECK_SEC_START, 1U);
		}
		/* if the master is priv, set the priv attribute */
		if (ft_is_true(creds->priv)) {
			ctrl_reg_val = set_field(ctrl_reg_val, CRED_PRIV_END,
						 CRED_PRIV_START, 1U);
		}
	}

	return ctrl_reg_val;
}

fterr cred_get_region(u8 host_id, u32 isc_id, u32 ring_id, u32 *control)
{
	ftbool flag = FT_FALSE;
	struct isc_cfg_cred_group *cred_group;
	struct isc_cfg_cred_item *cred_item;
	fterr ret = -EFAIL;

	*control = 0U;

	flag = cred_lookup_item(isc_id, ring_id, &cred_group, &cred_item);
	if (ft_is_true(flag)) {
		if (host_id == cred_item->owner_index) {
			u32 reg_addr = cred_group->mmr_address + (ring_id * CRED_RING_ADDR_OFFSET);
			*control =  readl((volatile u32 *) reg_addr);
			ret = EFTOK;
		}
	}
	return ret;
}

fterr cred_set_region(u8 host_id, u32 isc_id, u32 ring_id, u32 control)
{
	ftbool flag = FT_FALSE;
	struct isc_cfg_cred_group *cred_group;
	struct isc_cfg_cred_item *cred_item;
	fterr ret = -EFAIL;

	flag = cred_lookup_item(isc_id, ring_id, &cred_group, &cred_item);
	if (ft_is_true(flag)) {
		if (host_id == cred_item->owner_index) {
			u32 reg_addr = cred_group->mmr_address + (ring_id * CRED_RING_ADDR_OFFSET);
			ret = writel_verified((volatile u32 *) reg_addr, control);
		}
	}
	return ret;
}
