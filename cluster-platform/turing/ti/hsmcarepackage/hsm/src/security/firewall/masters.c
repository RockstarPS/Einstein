/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file masters.c
 *
 * \brief File that contains functions to manage/query the list of security
 *        masters in K3 system.
 *
 */

#include <firewall.h>
#include <masters.h>

#define FWL_PERM_SEC_MASK                     (0x00FFU)
#define FWL_PERM_NSEC_MASK                    (0xFF00U)
#define FWL_PERM_PRIV_MASK                    (0x0F0FU)
#define FWL_PERM_USER_MASK                    (0xF0F0U)

static const struct master_bootcfg_list *master_list;

fterr masters_init(const struct master_bootcfg_list *bootcfg)
{
	master_list = bootcfg;

	return EFTOK;
}

fterr masters_get_host_attrs(u8 host, struct master_creds *creds,
			     u32 *fwl_perm)
{
	fterr ret = -EINVAL;
	u8 master_id;
	struct master_creds cr;
	u32 s_perm, p_perm, perm;

	if (host < master_list->host_to_master_id_map_size) {
		master_id = master_list->host_to_master_id_map[host];

		if (master_id < master_list->master_list_size) {
			cr = master_list->items[master_id];
			s_perm = 0U;
			p_perm = 0U;

			if (ft_is_true(cr.secure)) {
				s_perm |= FWL_PERM_SEC_MASK;
			}
			if (ft_is_true(cr.nsecure)) {
				s_perm |= FWL_PERM_NSEC_MASK;
			}
			if (ft_is_true(cr.priv)) {
				p_perm |= FWL_PERM_PRIV_MASK;
			}
			if (ft_is_true(cr.user)) {
				p_perm |= FWL_PERM_USER_MASK;
			}
			perm = fwl_perm_word(cr.privid, (s_perm & p_perm));

			if (creds != NULL) {
				*creds = cr;
			}

			if (fwl_perm != NULL) {
				*fwl_perm = perm;
			}

			ret = EFTOK;
		}
	}
	return ret;
}
