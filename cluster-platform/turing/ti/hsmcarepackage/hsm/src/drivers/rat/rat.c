/*
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/* RAT mapping helps the HSM processor access the SoC global address space */
#include <rat.h>
#include <osal_secure.h>
#include <lib/bitops.h>

#define RAT_REGION_CTRL(a)              (0x20U + (a) * 0x10U)   /* Region  Control */
#define RAT_REGION_BASE(a)              (0x24U + (a) * 0x10U)   /* Region Base*/
#define RAT_REGION_TRANS_L(a)           (0x28U + (a) * 0x10U)   /* Reg Trans Lwr Addr */
#define RAT_REGION_TRANS_U(a)           (0x2cU + (a) * 0x10U)   /* Reg Trans Upr Addr */

#define RAT_REGION_CTRL_ENABLE          BIT(31)

#define RAT_BASE_ADDR                   0x43a00000U

#define RAT_FREE_WINDOW                 (0x3U)

static u8 free_map_used = FREE_MAP_UNUSED;
static u64 free_map_target_addr = (0x0ULL);

static void rat_writel(u32 v, u32 reg)
{
	*(volatile u32 *) (reg + RAT_BASE_ADDR) = v;
}

void rat_set_mapping(u32 window, u32 base, u64 address, u32 order)
{
	rat_writel(base, RAT_REGION_BASE(window));
	rat_writel((u32) (address & 0xffffffff), RAT_REGION_TRANS_L(window));
	rat_writel((u32) (address >> 32), RAT_REGION_TRANS_U(window));
	rat_writel(RAT_REGION_CTRL_ENABLE | order, RAT_REGION_CTRL(window));
}

void rat_disable_mapping(u32 window)
{
	rat_writel(0x0, RAT_REGION_CTRL(window));
}

s32 rat_init(void)
{
	u8 window;
	u32 start_num = 0x0U;
	/*rat mapping different for am62x and am62ax devices as ddr is mapped to 0x80000000 and 0x90000000 respectively by mcu-sdk release 9.0*/
#if  defined(CONFIG_SOC_AM62X) || defined(CONFIG_SOC_AM62PX)
	u32 rat3_phy_addr = 0x80000000;
#elif defined CONFIG_SOC_AM62AX
	u32 rat3_phy_addr = 0xA0000000;
#endif
	/* First disable all RAT mappings.. we will selectively enable */
	for (window = 0x0U; window < 16; window++) {
		rat_disable_mapping(window);
	}

	rat_set_mapping(start_num + 0U, RAT_ADDR0_VIRTUAL_ADDR, RAT_ADDR0_PHYSICAL_ADDR, ORDER_512MB);
	rat_set_mapping(start_num + 1U, RAT_ADDR1_VIRTUAL_ADDR, RAT_ADDR1_PHYSICAL_ADDR, ORDER_512MB);
	rat_set_mapping(start_num + 2U, RAT_ADDR2_VIRTUAL_ADDR, RAT_ADDR2_PHYSICAL_ADDR, ORDER_512MB);
	#if defined(CONFIG_SOC_AM62X) || defined(CONFIG_SOC_AM62AX) || defined(CONFIG_SOC_AM62PX)
	rat_set_mapping(start_num + 3U, RAT_ADDR3_VIRTUAL_ADDR, RAT_ADDR3_PHYSICAL_ADDR, ORDER_256MB);
	#endif
	rat_set_mapping(start_num + 4U, RAT_ADDR4_VIRTUAL_ADDR, RAT_ADDR4_PHYSICAL_ADDR, ORDER_256MB);
	return 0;
}

s32 rat_get_free_map_addr_range_user(u64 *lowAddr, u64 *highAddr)
{
	s32 ret = SUCCESS;

	osal_enter_priv_mode();
	ret = rat_get_free_map_addr_range(lowAddr, highAddr);
	osal_restore_priv_mode();
	return ret;
}
s32 rat_get_free_map_addr_range(u64 *lowAddr, u64 *highAddr)
{
	s32 ret = SUCCESS;

	if (free_map_used == FREE_MAP_UNUSED) {
		ret = -EBUSY;
	}
	if (ret == SUCCESS) {
		*lowAddr = free_map_target_addr;
		*highAddr = free_map_target_addr + (1ULL << ORDER_512MB);
	}
	return ret;
}

s32 rat_unmap_tmp_region(u64 addr)
{
	s32 ret = SUCCESS;
	u32 mappable_addr = (u32) (addr & (~RAT_TMP_REGION_INVAL_ADDR_MASK));

	if (free_map_used == FREE_MAP_UNUSED) {
		ret = -EBUSY;
	}
	if (ret == SUCCESS) {
		/* Cross check if the correct caller is trying to free */
		if (mappable_addr != free_map_target_addr) {
			ret = -EINVAL;
		}
	}
	if (ret == SUCCESS) {
		rat_disable_mapping(RAT_FREE_WINDOW);
		free_map_used = FREE_MAP_UNUSED;
		/*
		 * Don't need to reset free_map_target_addr -
		 * not used till mapped again.
		 */
	}
	return ret;
}


s32 rat_map_tmp_region(u64 addr, u32 *mapped_addr)
{
	s32 ret = SUCCESS;
	u32 mappable_addr = (u32) (addr & (~RAT_TMP_REGION_INVAL_ADDR_MASK));

	if (free_map_used != FREE_MAP_UNUSED) {
		/* Don't double allocate one single free slot we have */
		ret = -EBUSY;
	}
	if (ret == SUCCESS) {
		/* please give me a valid pointer. */
		if (mapped_addr == NULL) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* Deny Duplicate mapping of already static mapped regions */
		if (addr < (RAT_ADDR2_PHYSICAL_ADDR + (1ULL << ORDER_512MB))) {
			ret = -EINVAL;
		}
	}
	if (ret == SUCCESS) {
		free_map_used = FREE_MAP_USED;
		free_map_target_addr = mappable_addr;
		rat_set_mapping(RAT_FREE_WINDOW,
				RAT_FREE_WINDOW_VIRTUAL_ADDR,
				mappable_addr, ORDER_512MB);
		*mapped_addr = RAT_FREE_WINDOW_VIRTUAL_ADDR;
	}

	return ret;
}
