/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file masters_bootcfg.h
 *
 * \brief  Boot configuration structure for security masters in the system
 *
 */
#ifndef MASTERS_BOOTCFG_H
#define MASTERS_BOOTCFG_H

#include <types/short_types.h>
#include <types/ftbool.h>

/**
 * Maximum number of masters that could be configured
 */
#define MAX_MASTERS   255

/**
 * Master ID that is not a valid value - used to fill gaps in host-id to
 * master-id mapping array
 */
#define MASTER_ID_INVALID   255U

/**
 * \brief Credentials data for masters in the system
 *
 * \struct master_bootcfg_item
 *
 * \param privid Priv-ID of the master
 *
 * \param secure
 * Security attribute bit that tells if this master needs 'secure' access
 *
 * \param nsecure
 * Security attribute bit that tells if this master needs 'non-secure' access
 *
 * \param priv
 * Security attribute bit that tells if this master needs 'privileged' access
 *
 * \param user
 * Security attribute bit that tells if this master needs 'user' access
 */
struct master_creds {
	u8	privid;
	ftbool	secure;
	ftbool	nsecure;
	ftbool	priv;
	ftbool	user;
} __attribute__((__packed__));

/**
 * \brief master list
 *
 * \struct master_bootcfg_list
 *
 * \param master_list_size Size of master list
 * \param host_to_master_id_map_size Size of host to master id mapping array
 * \param host_id_to_master_id_map Array indexed by host ID and contains the
 *                                 corresponding master_id
 * \param items Array of items in master list
 */
struct master_bootcfg_list {
	u32				master_list_size;
	u32				host_to_master_id_map_size;
	const u8			*host_to_master_id_map;
	const struct master_creds	*items;
} __attribute__((__packed__));

#endif /* MASTERS_BOOTCFG_H */
