/*
 * System Firmware Ring Accelerator Library
 *
 * Copyright (C) 2017-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file ring_accelerator.c
 *
 * \brief Ring accelerator initialization Library.
 */

#include <config.h>
#include <lib/io_internal.h>
#include <osal_clock.h>
#include <comm_memory.h>
#include "ring_accelerator.h"

/*
 * Register Macros
 */
#define RINGACC_CFG_RING_BASE(RING)                     ((RING) * 0x100U)
#define RINGACC_CFG_RING_BA_LO                          (0x00000040U)
#define RINGACC_CFG_RING_BA_HI                          (0x00000044U)
#define RINGACC_CFG_RING_SIZE                           (0x00000048U)
#define RINGACC_CFG_RING_EVENT                          (0x0000004CU)
#define RINGACC_CFG_RING_ORDERID                        (0x00000050U)

/* SIZE Fields */

#define RINGACC_CFG_RING_SIZE_QMODE_MASK                (0xC0000000U)
#define RINGACC_CFG_RING_SIZE_QMODE_SHIFT               (0x0000001EU)
#define RINGACC_CFG_RING_SIZE_QMODE_RESETVAL            (0x00000000U)
#define RINGACC_CFG_RING_SIZE_QMODE_MAX                 (0x00000003U)
#define RINGACC_CFG_RING_SIZE_ELSIZE_MASK               (0x07000000U)
#define RINGACC_CFG_RING_SIZE_ELSIZE_SHIFT              (0x00000018U)
#define RINGACC_CFG_RING_SIZE_ELSIZE_RESETVAL           (0x00000000U)
#define RINGACC_CFG_RING_SIZE_ELSIZE_MAX                (0x00000007U)

#define RINGACC_CFG_RING_SIZE_ELCNT_MASK                (0x000FFFFFU)
#define RINGACC_CFG_RING_SIZE_ELCNT_SHIFT               (0x00000000U)
#define RINGACC_CFG_RING_SIZE_ELCNT_RESETVAL            (0x00000000U)
#define RINGACC_CFG_RING_SIZE_ELCNT_MAX                 (0x000FFFFFU)

#define RINGACC_CFG_RING_SIZE_RESETVAL                  (0x00000000U)

#define RINGACC_CFG_RING_EVENT_EVT_MASK                 (0x0000FFFFU)
#define RINGACC_CFG_RING_EVENT_EVT_SHIFT                (0x00000000U)
#define RINGACC_CFG_RING_EVENT_EVT_RESETVAL             (0x0000FFFFU)

/*
 * Register Macros - RT registers
 */
#define RINGACC_RT_RINGRT_BASE(RINGRT)                  ((RINGRT) * 0x1000U)
#define RINGACC_RT_RINGRT_DB                            (0x00000010U)
#define RINGACC_RT_RINGRT_OCC                           (0x00000018U)
#define RINGACC_RT_RINGRT_INDX                          (0x0000001CU)
#define RINGACC_RT_RINGRT_HWOCC                         (0x00000020U)
#define RINGACC_RT_RINGRT_HWINDX                        (0x00000024U)

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static mapped_addr_t ra_map_region(soc_phys_addr_t phy_addr)
{
	/**
	 * TBD - we need RAT if the mapping is not available.
	 *
	 * NOTE: we will misuse pm/soc/am6/dmsc.c configuration for now:
	 *
	 * ~~~
	 * Physical address | mapped address | Size
	 * ----------------------------------------
	 * 0x00000000ULL    | 0x60000000UL   | 512MB
	 * 0x20000000ULL    | 0x80000000UL   | 512MB
	 * 0x40000000ULL    | 0xa0000000UL   | 512MB
	 * ~~~
	 *
	 * *NOTE*: This wont work for firewall setup and separated ops.
	 */

	/*
	 * Only modify addresses outside the range shown here, since SoCs
	 * with the SMS use addresses inside the range as local addresses.
	 */
	if ((soc_phys_low_u32(phy_addr) < (0x43700000U)) ||
	    (soc_phys_low_u32(phy_addr) >= (0x46000000U))) {
		return soc_phys_low_u32(phy_addr) + (0x60000000U);
	} else {
		/* Use unmodified address for RA targets in local memory map */
		return soc_phys_low_u32(phy_addr);
	}
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 */
static void ra_unmap_region(soc_phys_addr_t phy_addr __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}

/**
 * \brief helper function to do the configuration of the ring
 *
 * \param cfg_cfg_addr - Ring Accelerator's cfg_cfg address (mapped address)
 *
 * \param rid - Ring ID
 *
 * \param rmode - Ring Mode to configure
 *
 * \param buff_addr - Backing Data buffer address for the Ring
 *
 * \param elsize - Element size of the Ring
 *
 * \param num_el - Number of elements in the ring.
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return 0 if all went fine, else return corresponding error
 */
static s32 _ralib_setup_ring(mapped_addr_t cfg_cfg_addr, u16 rid, u8 rmode,
			     soc_phys_addr_t buff_addr, u8 elsize, u16 num_el)
{
	u32 ring_base = RINGACC_CFG_RING_BASE(rid) + cfg_cfg_addr;
	u32 buffer_low = soc_phys_low_u32(buff_addr);
	u32 buffer_high = soc_phys_high_u32(buff_addr);
	u32 size_reg;
	u32 evt_reg;
	s32 ret = SUCCESS;

	ret = writel_verified(buffer_low, ring_base + RINGACC_CFG_RING_BA_LO);

	if (ret == SUCCESS) {
		ret = writel_verified(buffer_high,
				      ring_base + RINGACC_CFG_RING_BA_HI);
	}

	size_reg =
		(rmode <<
		 RINGACC_CFG_RING_SIZE_QMODE_SHIFT) &
		RINGACC_CFG_RING_SIZE_QMODE_MASK;
	size_reg |=
		(elsize <<
		 RINGACC_CFG_RING_SIZE_ELSIZE_SHIFT) &
		RINGACC_CFG_RING_SIZE_ELSIZE_MASK;
	size_reg |=
		(num_el <<
		 RINGACC_CFG_RING_SIZE_ELCNT_SHIFT) &
		RINGACC_CFG_RING_SIZE_ELCNT_MASK;

	if (ret == SUCCESS) {
		ret = writel_verified(size_reg,
				      ring_base + RINGACC_CFG_RING_SIZE);
	}

	evt_reg =
		(RINGACC_CFG_RING_EVENT_EVT_RESETVAL <<
		 RINGACC_CFG_RING_EVENT_EVT_SHIFT) &
		RINGACC_CFG_RING_EVENT_EVT_MASK;

	if (ret == SUCCESS) {
		ret = writel_verified(evt_reg,
				      ring_base + RINGACC_CFG_RING_EVENT);
	}

	return ret;
}

static s32 ralib_check_devgrp(u16 ra_idx, devgrp_t devgrp)
{
	const struct ring_accelerator *ra = NULL;
	s32 ret = SUCCESS;

	if (ra_idx >= soc_ring_accelerator_instances_num) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		ra = &(soc_ring_accelerator_instances[ra_idx]);
	}

	if (ret == SUCCESS) {
		ret = is_devgrp(ra->devgrp, devgrp);
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * RALIB Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 ralib_setup_ring_ba(const struct ring_config *rconfig, soc_phys_addr_t buffer_baseaddr)
{
	const struct ring_accelerator *ra;
	mapped_addr_t mapped_addr = 0;
	s32 ret = SUCCESS;

	/* check for basic invalid pointer */
	if (rconfig == NULL) {
		ret = -EINVAL;
	}

	/* Do I have valid base address? */
	if (buffer_baseaddr == 0) {
		ret = -EINVAL;
	}

	/* Do I have a valid Ring accelerator? */
	if ((ret == SUCCESS) &&
	    (rconfig->ra_idx >= soc_ring_accelerator_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_ring_accelerator_instances[rconfig->ra_idx]);
	}

	if ((ret == SUCCESS) && (rconfig->num_entries == 0)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (rconfig->ring_index > ra->num_rings)) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		mapped_addr = ra_map_region(ra->baseaddr_cfg__cfg);

		ret = _ralib_setup_ring(mapped_addr, rconfig->ring_index,
					rconfig->ring_mode,
					buffer_baseaddr,
					rconfig->elsize,
					rconfig->num_entries);

		/* we need this only for initial configuration */
		ra_unmap_region(ra->baseaddr_cfg__cfg);
	}

	return ret;
}

s32 ralib_setup_ring(const struct ring_config *rconfig)
{
	s32 ret = SUCCESS;
	soc_phys_addr_t buffer_baseaddr;

	/* check for basic invalid pointer */
	if (rconfig == NULL) {
		ret = -EINVAL;
	} else {
		buffer_baseaddr = comm_memory_base_addr(rconfig->buffer_idx, rconfig->buffer_neg_offset);
	}
	if (ret == SUCCESS) {
		ret = ralib_setup_ring_ba(rconfig, buffer_baseaddr);
	}
	return ret;
}

s32 ralib_wait_for_mesg(u8 ra_idx, u16 ring_index, u32 tmout_us)
{
	const struct ring_accelerator *ra;
	mapped_addr_t mapped_addr = 0;
	u32 start_time, time_diff, tmout_ns;
	u32 ringrt_base;
	s32 ret = SUCCESS;

	/* Do I have a valid Ring accelerator? */
	if (ra_idx >= soc_ring_accelerator_instances_num) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ra = &(soc_ring_accelerator_instances[ra_idx]);

		if (ring_index > ra->num_rings) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		mapped_addr = ra_map_region(ra->baseaddr_cfg__rt);

		ringrt_base = RINGACC_RT_RINGRT_BASE(ring_index) + mapped_addr;

		tmout_ns = tmout_us * 1000U;
		time_diff = 0U;
		start_time = osal_timestamp32_core();

		while ((readl(ringrt_base + RINGACC_RT_RINGRT_OCC) == 0U) &&
		       (time_diff < tmout_ns)) {
			time_diff = osal_timestamp32_core() - start_time;
		}
		if (readl(ringrt_base + RINGACC_RT_RINGRT_OCC) == 0U) {
			ret = -ETIMEDOUT;
		}
		ra_unmap_region(ra->baseaddr_cfg__rt);
	}
	return ret;
}

s32 ralib_init_devgrp(devgrp_t devgrp)
{
	u16 i;
	s32 ret = SUCCESS;
	const struct ring_config *rconfig = NULL;

	for (i = 0; i < soc_ring_configurations_num; i++) {
		rconfig = &(soc_ring_configurations[i]);

		if (ralib_check_devgrp(rconfig->ra_idx, devgrp) == SUCCESS) {
			ret = ralib_setup_ring(rconfig);
		}
		if (ret != SUCCESS) {
			break;
		}
	}

	return ret;
}

s32 ralib_ring_init(void)
{
	s32 ret = SUCCESS;

	ret = ralib_init_devgrp(DEVGRP_HSM);

	return ret;
}
