/*
 * System Firmware OSAL
 *
 * NORTOS Implementation of OSAL HWI API
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "hwip.h"
#include "osal_config.h"

#include "bitops.h"
#include "errno.h"
#include "sbool.h"
#include <string.h>

#ifndef SUCCESS
#define SUCCESS         0
#endif
/**
 * \def HWIF_INITIALIZED
 * HWI is initialized and valid.
 */
#define HWIF_INITIALIZED                                BIT(0)

/* Maximum priority value for interrupt */
#define HWI_MAX_PRIORITY                                (256u)

/* Value to disable all interrupts above or equal to 32 priority value */
#define HWI_PRIORITY_DISABLE                            (32u)

#define NVIC_BASE                                       (0xE000E000u)
#define NVIC_ISER(x)                                    (volatile u32 *) ((NVIC_BASE) +0x100u + 4u * (x))
#define NVIC_ICER(x)                                    (volatile u32 *) ((NVIC_BASE) +0x180u + 4u * (x))
#define NVIC_ISPR(x)                                    (volatile u32 *) ((NVIC_BASE) +0x200u + 4u * (x))
#define NVIC_ICPR(x)                                    (volatile u32 *) ((NVIC_BASE) +0x280u + 4u * (x))
#define NVIC_IPRI(x)                                    (volatile u32 *) ((NVIC_BASE) +0x400u + 4u * (x))

#define SHPR(x)                                         (volatile u32 *) ((0xE000ED18) + 4u * (x))

#define SYST_CSR                                        (volatile u32 *) (0xE000E010u)
#define STIR                                            (volatile u32 *) (0xE000EF00u)
#define VTOR                                            (volatile u32 *) (0xE000ED08u)
#define ICSR                                            (volatile u32 *) (0xE000ED04u)

#define SYST_INT_EN                                     BIT(1)
#define SYST_INT_NUM                                    15U
#define EXT_INT_START                                   16
#define DIV_BY_32                                       >> 5U
#define DIV_BY_4                                        >> 2U
#define MUL_BY_8 \
	<< 3U
#define REG_MASK                                        31U
#define MPU_FAULT_INT_NUM                               4

#define UNUSED(x)                                       (void) (x)

struct hwip_info {
	u8 flags;
};

static struct hwip_info hwi;

extern u32 __Vectors[DMSC_MAX_INTERRUPTS];

static inline sbool hwip_check_valid(u32 irq_num)
{
	sbool result = SFALSE;

	if ((irq_num < DMSC_MAX_INTERRUPTS) && (hwi.flags
						& HWIF_INITIALIZED) == HWIF_INITIALIZED) {
		result = STRUE;
	}

	return result;
}

s32 hwip_create(u32 hwi_id, s32 int_num, hwip_fxn hwi_fxn,
		struct hwip_params *params)
{
	s32 error = 0;
	u32 index, mask, shift;

	UNUSED(hwi_id);

	if (error == SUCCESS) {
		volatile u32 *addr;

		if (int_num >= EXT_INT_START) {
/* interrupts external to M4F */

			__Vectors[int_num] = (u32) hwi_fxn;

			index = (int_num - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((int_num - EXT_INT_START) & REG_MASK);

			addr = NVIC_ICER(index);
			*addr = mask;

/* clear only valid for interrupts external to M4F */
			addr = NVIC_ICPR(index);
			*addr = mask;

			if (params->priority < HWI_MAX_PRIORITY) {
				/* User interrupt (id >= 16) priorities are set in the IPR registers */

				/* Index of interrupt number in register. */
				shift = (((int_num - EXT_INT_START) & (BIT(0) | BIT(1)))MUL_BY_8);
				mask  = 0xFF << shift;
				/* Register index for external interrupt (out of 60 registers). */
				index = (int_num - EXT_INT_START)DIV_BY_4;

				addr = NVIC_IPRI(index);
				*addr &= ~(mask);                       /* clear priority */
				*addr |= (params->priority << shift);   /* set priority */
			}
		} else if ((int_num >= MPU_FAULT_INT_NUM) && (int_num < EXT_INT_START)) {
			if (int_num == SYST_INT_NUM) {
				u32 oldIntState;
				__Vectors[int_num] = (u32) hwi_fxn;
				addr = SYST_CSR;
				oldIntState = hwip_disable();
				*addr &= ~SYST_INT_EN;  /* disable SysTick interrupt */
				hwip_restore(oldIntState);
			}

			if (params->priority < HWI_MAX_PRIORITY) {
				/* System interrupt (id >= 4) priorities are set in the SHPR registers */

				shift = (((int_num - MPU_FAULT_INT_NUM) & (BIT(0) | BIT(1)))MUL_BY_8);
				mask  = 0xFF << shift;
				index = (int_num - MPU_FAULT_INT_NUM)DIV_BY_4;

				addr = SHPR(index);
				*addr &= ~(mask);                       /* clear priority */
				*addr |= (params->priority << shift);   /* set priority */
			}
		} else {
			/* System interrupts (id < 4) priorities  are fixed in hardware */
		}
		hwi.flags |= HWIF_INITIALIZED;
	}

	return error;
}

s32 hwip_delete(u32 hwi_id)
{
	s32 error = 0;

	UNUSED(hwi_id);

	hwi.flags = 0;

	return error;
}

s32 hwip_clear_interrupt(u32 irq_num)
{
	s32 error = 0;

	if (hwip_check_valid(irq_num) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		volatile u32 *addr;

		/* only valid for interrupts external to M4F */
		if (irq_num >= EXT_INT_START) {
			u32 index, mask;

			index = (irq_num - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((irq_num - EXT_INT_START) & REG_MASK);

			addr = NVIC_ICPR(index);
			*addr = mask;
		}
	}

	return error;
}

void hwip_clear_all_interrupts(void)
{
	u32 i;

	/*
	 * Start from the DMSC_NVIC_EXT_INT_OFFSET which is the first
	 * external interrupt number in the NVIC after the system
	 * exceptions.
	 */
	for (i = DMSC_NVIC_EXT_INT_OFFSET; i < DMSC_MAX_INTERRUPTS; i++) {
		volatile u32 *addr;

		/* only valid for interrupts external to M4F */
		if (i >= EXT_INT_START) {
			u32 index, mask;

			index = (i - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((i - EXT_INT_START) & REG_MASK);

			addr = NVIC_ICPR(index);
			*addr = mask;
		}
	}
}

s32 hwip_disable_interrupt(u32 irq_num, u32 *key)
{
	s32 error = 0;

	volatile u32 *addr;
	u32 oldEnableState;

	if (hwip_check_valid(irq_num) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		if (irq_num >= EXT_INT_START) {
			/* interrupts external to M4F */
			u32 index, mask;

			index = (irq_num - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((irq_num - EXT_INT_START) & REG_MASK);

			addr = NVIC_ISER(index);
			oldEnableState = *addr & mask;

			addr = NVIC_ICER(index);
			*addr = mask;
		} else if (irq_num == SYST_INT_NUM) {
			u32 oldIntState;

			addr = SYST_CSR;
			oldIntState = hwip_disable();
			oldEnableState = *addr & SYST_INT_EN;
			*addr &= ~SYST_INT_EN;  /* disable SysTick interrupt */
			hwip_restore(oldIntState);
		} else {
			oldEnableState = 0;
		}

		if (key != NULL) {
			*key = oldEnableState;
		} else {
			/*
			 * In this case we have intentionally decided not to record
			 * the current state of interrupts so ignore the return value.
			 */
		}
	}

	return error;
}

s32 hwip_enable_interrupt(u32 irq_num, u32 *key)
{
	s32 error = 0;
	u32 oldEnableState;

	if (hwip_check_valid(irq_num) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		volatile u32 *addr;

		if (irq_num >= EXT_INT_START) {
			/* interrupts external to M4F */
			u32 index, mask;

			index = (irq_num - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((irq_num - EXT_INT_START) & REG_MASK);

			addr = NVIC_ISER(index);
			oldEnableState = *addr & mask;
			*addr = mask;
		} else if (irq_num == SYST_INT_NUM) { /* SysTick interrupt */
			u32 oldIntState;

			addr = SYST_CSR;
			oldIntState = hwip_disable();
			oldEnableState = *addr & SYST_INT_EN;
			*addr |= SYST_INT_EN;   /* enable SysTick interrupt */
			hwip_restore(oldIntState);
		} else {
			oldEnableState = 0;
		}

		if (key != NULL) {
			*key = oldEnableState;
		} else {
			/*
			* In this case we have intentionally decided not to record
			* the current state of interrupts so ignore the return value.
			*/
		}
	}

	return error;
}

s32 hwip_restore_interrupt(u32 irq_num, u32 key)
{
	s32 error = 0;

	if (hwip_check_valid(irq_num) == SFALSE) {
		error = -EINVAL;
	}

	if (error == SUCCESS) {
		volatile u32 *addr;

		if (irq_num >= EXT_INT_START) {
			/* interrupts external to M4F */
			u32 index, mask;

			index = (irq_num - EXT_INT_START)DIV_BY_32;
			mask = (u32) 1U << ((irq_num - EXT_INT_START) & REG_MASK);

			if (key != 0U) {
				addr = NVIC_ISER(index);
			} else {
				addr = NVIC_ICER(index);
			}
			*addr = mask;
		} else if (irq_num == SYST_INT_NUM) {
			u32 oldIntState;

			addr = SYST_CSR;
			oldIntState = hwip_disable();
			if (key != 0U) {
				*addr |= SYST_INT_EN;           /* enable SysTick Int */
			} else {
				*addr &= ~SYST_INT_EN;          /* disable SysTick Int */
			}
			hwip_restore(oldIntState);
		}
	}

	return error;
}

u32 hwip_disable(void)
{
	return _set_interrupt_priority(HWI_PRIORITY_DISABLE);
}

u32 hwip_enable(void)
{
	return _set_interrupt_priority(0u);
}

void hwip_restore(u32 key)
{
	_set_interrupt_priority(key);
}
