/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul.h
 *
 * \brief SA2_UL common definitions and types
 */
#ifndef SA2UL_H_
#define SA2UL_H_

#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>
#include <crypto_types.h>


/**
 * Maximum number of SA2UL instances
 */
#define SA2UL_MAX_INSTANCES            (2U)

/**
 * Max number of users allowed for DKEK (from SA2UL spec)
 */
#define SA2UL_DKEK_MAX_USERS           4

#define SA2UL_MODULE_PKA               (0U)
#define SA2UL_MODULE_DKEK              (1U)
#define SA2UL_MODULE_AUTH              (2U)
#define SA2UL_MODULE_ENCR              (3U)
#define SA2UL_MODULE_TRNG              (4U)
#define SA2UL_MODULE_DRBG              (5U)

/*Main Domain SA2UL instance */
#define SA2UL_INSTANCE_HSM_PKA                 1U

/**
 * \brief SoC data for SA2UL
 *
 * \param num_instances Number of SA2UL instances on the SOC
 * \param base_addr Base addresses for the SA2UL instances
 * \param firewall_id ID of the firewall protecting the SA2UL instance
 * \param num_firewall_regions number of firewall regions in SA2UL firewall
 */
struct sa2ul {
	u32				num_instances;
	soc_phys_addr_t			base_addr[SA2UL_MAX_INSTANCES];
	struct fwl_bootcfg_group	*sa2ul_fwl[SA2UL_MAX_INSTANCES];
	u16				pka_region;
};

extern struct sa2ul sa2ul_socdata;

/**
 * \brief Enable the SA2UL instance clocks for internal use
 *
 * \param instance SA2UL instance number
 * \param module Module within SA2UL to be enabled
 */
fterr sa2ul_enable(u32 instance, u32 module);

/**
 * \brief Enable the SA2UL instance clocks for internal use
 *
 * \param instance SA2UL instance number
 * \param module Module within SA2UL to disable
 */
void sa2ul_disable(u32 instance, u32 module);

/**
 * \brief Enable all SA2UL engines
 *
 * Calls sa2ul_enable for all SA2UL submodules
 *
 * \param instance SA2UL instance number
 */
fterr sa2ul_enable_all_engines(u32 instance);


#endif /* SA2UL_H_ */
