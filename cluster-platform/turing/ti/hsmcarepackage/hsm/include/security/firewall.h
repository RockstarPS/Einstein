/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file firewall.h
 *
 * \brief  Firewall configuration module
 */

#ifndef FIREWALL_H_
#define FIREWALL_H_

#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>
#include <types/devgrps.h>
#include <config.h>

/*
 * Helpful constants
 */
/**
 * The wildcard privid
 */
#define PRIVID_WILDCARD       (195U)

/**
 * DMSC privid
 */
#define PRIVID_DMSC           (202U)

/**
 * UDMAP private privid
 */
#define PRIVID_UDMAP          (0U)

/**
 * The permission word that allows all
 */
#define PERM_ALLOW_ALL        (((u32) PRIVID_WILDCARD << 16) | 0xFFFFU)

/**
 * The permission word that allows DMSC
 */
#define PERM_ALLOW_DMSC       (((u32) PRIVID_DMSC << 16) | 0xFFFFU)

#define FWL_MAX_PRIVID_SLOTS (3U)


struct fwl_multi_region_data_item {
	u16			id;
	u8			region_number;
	u32			control;
	u8			n_permission_regs;
	u32			permission1;
	u32			permission2;
	u32			permission3;
	u32			start_address;
	u32			end_address;
} __attribute__((__packed__));

/*
 * Useful #defines to form the permissions word
 */
#define FWL_PERM_SEC_MASK                     (0x00FFU)
#define FWL_PERM_NSEC_MASK                    (0xFF00U)
#define FWL_PERM_PRIV_MASK                    (0x0F0FU)
#define FWL_PERM_USER_MASK                    (0xF0F0U)

#define FWL_PERM_WRITE_MASK                   (0x1111U)
#define FWL_PERM_READ_MASK                    (0x2222U)
#define FWL_PERM_CACHE_MASK                   (0x4444U)
#define FWL_PERM_DEBUG_MASK                   (0x8888U)

#define FWL_PERM_RW_ALL                        (FWL_PERM_WRITE_MASK | \
						FWL_PERM_READ_MASK | \
						FWL_PERM_CACHE_MASK | \
						FWL_PERM_DEBUG_MASK)

#define FWL_PERM_RO_ALL                        (FWL_PERM_READ_MASK | \
						FWL_PERM_CACHE_MASK | \
						FWL_PERM_DEBUG_MASK)

#define FWL_PERM_WO_ALL                        (FWL_PERM_WRITE_MASK | \
						FWL_PERM_CACHE_MASK | \
						FWL_PERM_DEBUG_MASK)

#define FWL_PERM_SEC_RW                        (FWL_PERM_SEC_MASK & \
						FWL_PERM_RW_ALL)

#define FWL_PERM_NSEC_RW                       (FWL_PERM_NSEC_MASK & \
						FWL_PERM_RW_ALL)

#define FWL_PERM_PRIV_RW                       (FWL_PERM_PRIV_MASK & \
						FWL_PERM_RW_ALL)

#define FWL_PERM_USER_RW                       (FWL_PERM_USER_MASK & \
						FWL_PERM_RW_ALL)

#define FWL_PERM_SEC_RO                        (FWL_PERM_SEC_MASK & \
						FWL_PERM_RO_ALL)

#define FWL_PERM_NSEC_RO                       (FWL_PERM_NSEC_MASK & \
						FWL_PERM_RO_ALL)

#define FWL_PERM_PRIV_RO                       (FWL_PERM_PRIV_MASK & \
						FWL_PERM_RO_ALL)

#define FWL_PERM_USER_RO                       (FWL_PERM_USER_MASK & \
						FWL_PERM_RO_ALL)

static inline u32 fwl_perm_word(u32 priv_id, u32 perm_bits)
{
	return (priv_id << 16) | perm_bits;
}

/*
 * Useful #defines to form the control word
 */
#define FWL_CONTROL_ENABLE_MASK      ((u32) 0xFU)
#define FWL_CONTROL_ENABLE           ((u32) 0xAU)
#define FWL_CONTROL_LOCK             ((u32) 0x10U)
#define FWL_CONTROL_BG               ((u32) 0x100U)
#define FWL_CONTROL_CACHE_MODE       ((u32) 0x200U)

#endif /* FIREWALL_H_ */
