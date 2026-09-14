/*
 * System Firmware DMSC Interrupt Aggregator descriptions
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file dmsc_ia.h
 *
 * \brief Include file for Secure Proxy Data descriptions and initialization
 *	routine
 */

#ifndef DMSC_IA_DESC_H
#define DMSC_IA_DESC_H

#include <types/sbool.h>
#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Describe an Interrupt Aggregator instance for DMSC
 * \param cfg_cfg - cfg region for IA
 * \param cfg_imap - imap region for IA
 * \param cfg_intr - intr region for IA
 * \param vintr_cnt - Number of virtual IRQs this IA can generate
 * \param sevt_cnt - How many events can this handle
 * \param local_irq_start - local IRQ on NVIC the first "virq" is hooked to
 * \param ia_offset - offset into IA mappings used in case of IA/IR combination
 * \param global_evt_base - What is the global event that routes to this IA
 */
struct dmsc_ia_instance {
	local_phys_addr_t	cfg_cfg;
	local_phys_addr_t	cfg_imap;
	local_phys_addr_t	cfg_intr;
	u16			vintr_cnt;
	u16			sevt_cnt;
	u8			local_irq_start;
	u8			ia_offset;
	u16			global_evt_base;
};

#define SOC_MAX_DMSC_IA_INSTANCES 1

/** DMSC Interrupt_aggregator Instance */
extern const struct dmsc_ia_instance dmsc_ia[SOC_MAX_DMSC_IA_INSTANCES];

/**
 * \brief Give one mapping of DMSC IA configuration
 * \param global_event_id - Global event ID that we want to program for:
 *	This must be within the range of \ref dmsc_ia 's global_evt_base up to
 *	sevt_cnt
 * \param local_irq - What is the local IRQ we want this to map to?
 *	This must be within the range of \ref dmsc_ia 's local_irq_start up to
 *	vintr_cnt
 *
 * Assumption here is that every event gets a unique IRQ, and there is no shared
 * IRQ (aka multiple events triggering same local_irq)
 */
struct dmsc_ia_map {
	u16	global_event_id;
	u8	local_irq;
};
/** How many DMSC IA configurations do we need to do? */
extern const u8 dmsc_ia_map_configuration_num[];

/** DMSC IA configuration */
extern const struct dmsc_ia_map *dmsc_ia_map_configurations[SOC_MAX_DMSC_IA_INSTANCES];

/**
 * \brief Initialize DMSC Interrupt Aggregator
 *
 */
#ifdef CONFIG_DMSC_IA
extern s32 dmsc_ia_init(void);
extern s32 dmsc_hsm_ia_init(void);
#else
static inline s32 dmsc_ia_init(void)
{
	return 0;
}

static inline s32 dmsc_hsm_ia_init(void)
{
	return 0;
}
#endif

#endif
