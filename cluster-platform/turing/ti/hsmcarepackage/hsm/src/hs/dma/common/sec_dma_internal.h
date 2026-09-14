/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_dma_internal.h
 *
 * \brief Internal APIs for DMA module use
 *
 */
#ifndef SEC_DMA_INTERNAL_H_
#define SEC_DMA_INTERNAL_H_

#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \param size currently unused
 *
 * \return Mapped address
 */
static inline mapped_addr_t sec_dma_map_region(
	soc_phys_addr_t phy_addr,
	u32		size __attribute__((unused)))
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

	if ((phy_addr >= 0x44800000U) && (phy_addr <= 0x44FFFFFFU)) {
		return soc_phys_low_u32(phy_addr);
	}

	return soc_phys_low_u32(phy_addr) + 0x60000000U;
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 *
 * \param size - currently unused
 */
static inline void sec_dma_unmap_region(
	soc_phys_addr_t phy_addr __attribute__((unused)),
	u32		size __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}

#endif /* SEC_DMA_INTERNAL_H_ */
