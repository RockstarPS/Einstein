/*
 * \file irq-arm.c
 *
 * \brief C source for ARM IRQ low-level architecture functions
 *
 * Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "interrupt.h"

#define NVIC_ISPR (u32 *) 0xE000E280U
sbool is_interrupt_pending(u32 irq_num)
{
	sbool is_pending = SFALSE;
	u32 index, mask;
	u32 *ISPR = NVIC_ISPR;

	if (irq_num >= DMSC_NVIC_EXT_INT_OFFSET) {
		/* Get index of ISPR base offset (32 interrupts per register) */
		index = (irq_num - DMSC_NVIC_EXT_INT_OFFSET) >> 5U;

		/*
		 * Get bit mask within current index for checking active status
		 */
		mask = (u32) 1U << ((irq_num - DMSC_NVIC_EXT_INT_OFFSET) & 0x1FU);

		/* Check if bit pending to determine interrupt pending status */
		if ((ISPR[index] & mask) != 0U) {
			is_pending = STRUE;
		}
	}

	return is_pending;
}
