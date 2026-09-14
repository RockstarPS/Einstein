/*
 * System Firmware Ring Accelerator Library
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file ring_accelerator.c
 *
 * \brief Ring accelerator initialization Library.
 */

#include <config.h>
#include <lib/io_internal.h>
#include <lib/container_of.h>
#include <types/address_types.h>
#include <types/sbool.h>
#include "dmsc_ia.h"
#include <dmsc_irq_map.h>

u32 ioremap_internal(u32 a);
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * DMSC IA Helper APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define DMSC_IA_INTMAP_ENTRY_MAP_REGNUM_SHIFT           (8U)
#define DMSC_IA_INTMAP_ENTRY_MAP_REGNUM_MASK            (0x1FF00U)

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static mapped_addr_t dmsc_ia_map_region(soc_phys_addr_t phy_addr)
{
	/**
	 * This uses ioremap which will selectively use the RAT if the address
	 * is not accessible from the DMSC.
	 */

	return (mapped_addr_t) ioremap_internal(soc_phys_low_u32(phy_addr));
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 */
static void dmsc_ia_unmap_region(soc_phys_addr_t phy_addr __attribute__((unused)))
{
	/**
	 * TBD - we need RAT if the mapping is not available - Empty function
	 * for now.
	 */
	return;
}

static s32 dmsc_write_ia_vint_ctl(u16 vint_irq, u8 enable, const struct dmsc_ia_instance *dmsc_ia_inst)
{
	local_phys_addr_t vint_reg;
	u32 read_val, wr_val, exp_val;
	s32 res = SUCCESS;

	if (vint_irq > dmsc_ia_inst->vintr_cnt) {
		res = -EINVAL;
	}
	if (res == SUCCESS) {
		/* point to Set register */
		vint_reg = dmsc_ia_map_region(dmsc_ia_inst->cfg_intr) +
			   (vint_irq * ((local_phys_addr_t) 0x1000U));

		if (enable == 0U) {
			/* else point to clear register */
			vint_reg = vint_reg + 0x8U;
			exp_val = 0U;
			wr_val = 0xFFFFFFFFU;
		} else {
			/* we only control BIT(0) */
			exp_val = 0x1U;
			wr_val = 0x1U;
		}

		writel(wr_val, vint_reg);
		read_val = readl(vint_reg);

		if (read_val != exp_val) {
			res = -EFAILVERIFY;
		}
		dmsc_ia_unmap_region(vint_reg);
	}

	return res;
}

static s32 dmsc_write_ia_map(u16 event_idx, u16 vint_irq, const struct dmsc_ia_instance *dmsc_ia_inst)
{
	local_phys_addr_t dmsc_imap_addr = dmsc_ia_map_region(dmsc_ia_inst->cfg_imap);
	local_phys_addr_t event_reg;
	u32 reg_val, read_val;
	s32 res = SUCCESS;

	/* Check basic params */
	if (event_idx >= dmsc_ia_inst->sevt_cnt) {
		res = -EINVAL;
	}
	if (vint_irq >= dmsc_ia_inst->vintr_cnt) {
		res = -EINVAL;
	}
	if (res == SUCCESS) {
		reg_val = (((u32) vint_irq) << DMSC_IA_INTMAP_ENTRY_MAP_REGNUM_SHIFT) &
			  DMSC_IA_INTMAP_ENTRY_MAP_REGNUM_MASK;
		/* we leave it always as bit 0 */

		event_reg = dmsc_imap_addr + (event_idx * ((local_phys_addr_t) 0x8U));
		writel(reg_val, event_reg);

		read_val = readl(event_reg);

		if (read_val != reg_val) {
			res = -EFAILVERIFY;
		}
		if (res == SUCCESS) {
			res = dmsc_write_ia_vint_ctl(vint_irq, 1U, dmsc_ia_inst);
		}
	}

	dmsc_ia_unmap_region(dmsc_imap_addr);
	return res;
}

#ifndef CONFIG_DMSC_IA_SHARED
static s32 dmsc_ia_setup_default(u8 i)
{
	u16 evt;
	s32 ret = SUCCESS;
	u16 virq = 0U;
	const struct dmsc_ia_instance *dmsc_ia_inst = NULL;

	/* First Initialize DMSC IA Instances */
	dmsc_ia_inst = &(dmsc_ia[i]);

	/* use the last IRQ as "safe irq" */
	u16 safe_irq = dmsc_ia_inst->vintr_cnt - 1U;

	for (evt = 0U; evt < dmsc_ia_inst->sevt_cnt; evt++) {
		ret = dmsc_write_ia_map(evt, safe_irq, dmsc_ia_inst);
		/* Inability to configure DMSC IA will result in broken SoC */
		if (ret != SUCCESS) {
			break;
		}
	}

	/* Disable everyone including safe_irq */
	for (virq = 0U; virq < dmsc_ia_inst->vintr_cnt; virq++) {
		ret = dmsc_write_ia_vint_ctl(virq, 0U, dmsc_ia_inst);
		if (ret != SUCCESS) {
			break;
		}
	}

	return ret;
}
#endif

static s32 dmsc_ia_setup(const struct dmsc_ia_map *c, const struct dmsc_ia_instance *dmsc_ia_inst)
{
	u16 local_event_id;
	u16 local_virq;
	s32 res = SUCCESS;

	/* use the last IRQ as "safe irq" */
	u16 safe_irq = dmsc_ia_inst->vintr_cnt - 1U;

	if (c->global_event_id < dmsc_ia_inst->global_evt_base) {
		res = -EINVAL;
	}
	if ((res == SUCCESS) && (c->local_irq < dmsc_ia_inst->local_irq_start)) {
		res = -EINVAL;
	}

	if (res == SUCCESS) {
		local_event_id = c->global_event_id - dmsc_ia_inst->global_evt_base;
		local_virq = (u16) (c->local_irq - dmsc_ia_inst->local_irq_start);
		/* DON'T permit usage of safe_irq in map */
		if (local_virq == safe_irq) {
			res = -EINVAL;
		}
	}
#ifdef CONFIG_DMSC_IA_SHARED
	if (res == SUCCESS) {
		res = dmsc_write_ia_vint_ctl(local_virq, 0U, dmsc_ia_inst);
	}
#endif
	if (res == SUCCESS) {
		/* check valid other sub range in helper */
		/* Use ia_offset in case IA routes to an IR and first local_event_id has a non-zero offset */
		res = dmsc_write_ia_map(local_event_id, (local_virq + (u16) dmsc_ia_inst->ia_offset), dmsc_ia_inst);
	}


	return res;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * DMSC IA Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 dmsc_ia_init_by_instance(u8 j)
{
	u16 i;
	s32 ret = SUCCESS;
	const struct dmsc_ia_map *c = NULL;
	const struct dmsc_ia_instance *dmsc_ia_inst = NULL;

#ifndef CONFIG_DMSC_IA_SHARED
	ret = dmsc_ia_setup_default(j);
#endif

	/* First Initialize the DMSC IA Instance */
	dmsc_ia_inst = &(dmsc_ia[j]);

	for (i = 0u; i < dmsc_ia_map_configuration_num[j]; i++) {
		c = &(dmsc_ia_map_configurations[j][i]);
		ret = dmsc_ia_setup(c, dmsc_ia_inst);
		if (ret != SUCCESS) {
			break;
		}
	}

	/*
	 * Inability to configure IA will result in broken SoC. So, OK
	 * to break the system by hanging
	 */
	return ret;
}

s32 dmsc_ia_init(void)
{
	s32 ret = SUCCESS;

	ret = dmsc_ia_init_by_instance(0);

	return ret;
}
