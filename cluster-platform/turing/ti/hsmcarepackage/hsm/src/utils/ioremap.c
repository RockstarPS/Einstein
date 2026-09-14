/*
 * System Firmware
 *
 * Cortex-M3 (CM3) firmware for power management
 *
 * Copyright (C) 2015-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <config.h>
#include <lib/ioremap.h>
#include <rat.h>
#include <types/short_types.h>

u32 ioremap_internal(u32 a)
{
	u32 addr = a;
	u32 offset;
	u64 lowAddr, highAddr;
	s32 ret;

	/*
	 * The region from 0x0000_0000 to 0x5fff_ffff is remapped to the
	 * main SoC address space via IO windows. Fortunately, there is no
	 * overlap with the PMMC register space so we do not remap those
	 * addresses
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
	 * DMSC and SMS use addresses in the range 0x43700000 to 0x46000000
	 * as local addresses. So, we do not modify the addr if it is inside
	 * this range.
	 */
	if (((a >= 0x100000U) && a < (0x43700000U)) ||
	    ((a >= 0x46000000U) && (a < 0x60000000U))) {
		addr += CONFIG_ADDR_REMAP_OFFSET_SECURITY;
	}
	ret = rat_get_free_map_addr_range(&lowAddr, &highAddr);
	if (ret == SUCCESS) {
		/*
		 * Using a fixed map address for the free window, so need to get
		 * the absolute difference in the mapping for applying the
		 * offset.
		 */
		offset = ((RAT_FREE_WINDOW_VIRTUAL_ADDR > soc_phys_low_u32(lowAddr)) ?
			  RAT_FREE_WINDOW_VIRTUAL_ADDR - soc_phys_low_u32(lowAddr) :
			  soc_phys_low_u32(lowAddr) - RAT_FREE_WINDOW_VIRTUAL_ADDR);

		if ((a >= soc_phys_low_u32(lowAddr)) && (a < soc_phys_low_u32(highAddr))) {
			addr += offset;
		}
	}
	return addr;
}
