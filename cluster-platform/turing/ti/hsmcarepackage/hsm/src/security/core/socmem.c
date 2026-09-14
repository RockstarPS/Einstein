/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file socmem.c
 *
 * \brief  Function do local address to global and reverse lookups on DMSC
 *
 */
#include <types/short_types.h>
#include <types/fterr.h>

#include <socmem.h>
#include <common_funcs.h>

/**
 * \brief RAT regions
 *
 * \param CTRL RAT region control register
 * \param BASE Local address base
 * \param TRANS_L Translated external address (lower 32-bit)
 * \param TRANS_U Translated external address (upper 32-bit)
 */
struct rat_region {
	u32	CTRL;
	u32	BASE;
	u32	TRANS_L;
	u32	TRANS_U;
};

/**
 * \brief RAT registers
 *
 * \param PID Peripheral ID
 * \param CONFIG Configuration register
 * \param REGION RAT regions
 */
struct rat_registers {
	u32			PID;
	u32			CONFIG;
	u8			reserved0[0x20 - 0x8];
	struct rat_region	REGION[16];
};

/**
 * \brief RAT configuration registers for DMSC
 */
static volatile struct rat_registers *const RAT_REGS =
	(struct rat_registers *) 0x43a00000U;

fterr socmem_to_global(local_phys_addr_t ptr, soc_phys_addr_t *global_addr)
{
	u32 addr = (u32) ptr;
	u32 reg, len;
	soc_phys_addr_t ret;
	s32 i;

	if ((addr <= 0xFFFFFU)) {
		*global_addr = 0x43C00000U + addr;
		return EFTOK;
	}
	if ((addr >= 0x43C00000U) && (addr <= 0x45FFFFFFU)) {
		*global_addr = (soc_phys_addr_t) addr;
		return EFTOK;
	}

	if ((addr < 0x60000000U) || (addr > 0xDFFFFFFFU)) {
		return -EINVAL;
	}

	/* Loopup RAT entries */
	for (i = 0; i < 16; i++) {
		reg = readl(&RAT_REGS->REGION[i].CTRL);
		if (reg & (1U << 31)) {
			len = (1U << (reg & 0x1fU));
			reg = readl(&RAT_REGS->REGION[i].BASE);
			if (addr >= reg && addr < (reg + len)) {
				ret = readl(&RAT_REGS->REGION[i].TRANS_U);
				ret = (ret << 32);
				ret |= (soc_phys_addr_t)
				       readl(&RAT_REGS->REGION[i].TRANS_L);
				ret += (addr - reg);
				*global_addr = ret;
				return EFTOK;
			}
		}
	}
	return -EINVAL;
}

fterr socmem_to_local(soc_phys_addr_t global_addr, local_phys_addr_t *ptr)
{
	u32 reg, len, ret;
	soc_phys_addr_t trans;
	s32 i;


	if ((global_addr >= 0x43C00000U) && (global_addr <= 0x43cfffffULL)) {
		*ptr = (((u32) global_addr) - 0x43C00000U);
		return EFTOK;
	}

	if ((global_addr >= 0x43C00000U) && (global_addr <= 0x45FFFFFFULL)) {
		*ptr = ((u32) global_addr);
		return EFTOK;
	}

	ret = 0;

	/* Lookup RAT entries */
	for (i = 0; i < 16; i++) {
		reg = readl(&RAT_REGS->REGION[i].CTRL);
		if (reg & (1u << 31)) {
			len = (1u << (reg & 0x1fu));
			reg = readl(&RAT_REGS->REGION[i].BASE);
			trans = readl(&RAT_REGS->REGION[i].TRANS_U);
			trans = (trans << 32);
			trans |= (soc_phys_addr_t)
				 readl(&RAT_REGS->REGION[i].TRANS_L);
			if ((global_addr >= trans) &&
			    (global_addr < (trans + len))) {
				ret = ((u32) (global_addr - trans)) + reg;
				break;
			}
		}
	}

	if ((ret < 0x60000000ULL) || (ret > 0xDFFFFFFFULL)) {
		return -EINVAL;
	}

	*ptr = ret;
	return EFTOK;
}
