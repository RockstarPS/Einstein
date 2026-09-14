/*
 * System Firmware OSAL
 *
 * NORTOS Implementation of OSAL Clock API
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "osal_config.h"
#include "clockp.h"
#include "hwip.h"
#include "dmsc_hw.h"
#include "hsm.h"

#include "bitops.h"
#include "errno.h"

#ifndef SUCCESS
#define SUCCESS         0
#endif
/* Clock Flags */
#define CLOCKF_INITIALIZED                      BIT(0)  /* Clock is initialized */

/* SysTick timer implementation for clock tick */
#define SYST_BASE                               (0xE000E010u)
#define SYST_CSR                                (volatile u32 *) ((SYST_BASE) +0x00u)
#define SYST_RVR                                (volatile u32 *) ((SYST_BASE) +0x04u)
#define SYST_CVR                                (volatile u32 *) ((SYST_BASE) +0x08u)

/* System handler priority register for setting systick interrupt priority in the core */
#define SHPR3                                   (volatile u32 *) (0xE000ED20)
#define SYST_INT_PRIORITY                       (240u)
#define SYST_INDEX                              (8u * 3u)

/* SysTick CSR bit fields. */
#define SYST_TIMER_START                        BIT(0)
#define SYST_INT_EN                             BIT(1)
#define SYST_MCU_CLK_SEL                        BIT(2)
#define SYST_WRAP_BIT                           BIT(16)

#define SYST_TICK_PERIOD_US                     (1000u)

#define SYST_MAX_CNT                            (0xFFFFFFu)
#define SYST_INT_NUM                            (15u)
#define TIME_US_TO_NS_MULT                      (1000u)

#define BIT_MASK                                (0x1u)

#define UNUSED(x)                               (void) (x)

/**
 * \brief Local structure to be used for underlying implementation data.
 *
 * \param flags Flag bitfield used to store operational info about the clock.
 * \param timeout_ns Timeout period of interrupt occurence in nanoseconds.
 * \param ticks Number of times of timeout occurence
 */
struct clockp_info {
	u8	flags;
	u64	timeout_ns;
	u32	ticks;
};

/**
 * \brief File local static variable to allow the underlying clock implementation
 *        to be managed entirely inside this file.
 */
static struct clockp_info clock_local;

u32 halt_flag = 0;
#if 0
static void clockp_systicktimer_setup(void)
{
	
	volatile u32 *addr;
	u32 ctrl_val, count_val, reload_val;
	u64 timer_cycles;

	/* Initialize number of ticks to zero */
	clock_local.ticks = 0;

	/* Calculate timeout value in nanoseconds */
	clock_local.timeout_ns = SYST_TICK_PERIOD_US * TIME_US_TO_NS_MULT;

	/* Calculate number of cycles required for specified timeout value */
	timer_cycles =  ((u64) BOOT_FREQUENCY_HZ * clock_local.timeout_ns) / 1000000000U;

	/* This value corresponds to reload value register value */
	count_val = timer_cycles;

	/* keep reload value as 0, later if is auto-reload is enabled, it will be set a value > 0 */
	reload_val = 0;

	/* calculate control register value, keep timer disabled */
	ctrl_val = 0;

	/* select clock source as CPU clock */
	ctrl_val |= SYST_MCU_CLK_SEL;

	/* enable interrupt */
	ctrl_val |= SYST_INT_EN;

	/* autoreload timer */
	reload_val = count_val - 1;

	/* set timer control value */
	addr = SYST_CSR;
	*addr = ctrl_val;

	/* set reload value */
	addr = SYST_RVR;
	*addr = reload_val;

	/* set count value */
	addr = SYST_CVR;
	*addr = count_val - 1;
	
}
#endif
sbool clockp_is_initialized(void)
{
	return (clock_local.flags & CLOCKF_INITIALIZED) != 0U;
}

u32 clockp_get_time32(void)
{
	u32 timestamp, count1, count2, wrap, syst_csr = 0;
	unsigned int key;

	volatile u32 *addr_cvr = SYST_CVR;
	volatile u32 *addr_csr = SYST_CSR;
	volatile u32 *addr_rvr = SYST_RVR;

	if ((clock_local.flags & CLOCKF_INITIALIZED) != 0U) {
		key = hwip_disable();

		/* Get the number of counts for previous timeout events */
		timestamp = clock_local.ticks * ((*addr_rvr) + 1U);

		/* Compute remaining number of counts after timeouts */
		count1 = *(addr_cvr);
		syst_csr = *(addr_csr);
		count2 = *(addr_cvr);

		wrap = syst_csr & SYST_WRAP_BIT;        /* Get if systick timer wrapped around 0 now */

		if ((count1 > count2) && wrap) {        /* Update timestamp accordingly */
			timestamp += (((*addr_rvr) + 1U) - count1) + ((*addr_rvr) + 1);
		} else {
			timestamp += ((*addr_rvr) + 1U) - count1;
		}

		/* Get time in ns by dividing counts by frequency */
		timestamp *= (u32) (1000000000ULL / BOOT_FREQUENCY_HZ);

		hwip_restore(key);
	}

	return timestamp;
}

u64 clockp_get_time64(void)
{
	u64 timestamp = 0U;
	unsigned int key;

	u32 count1, count2, wrap, syst_csr = 0;

	volatile u32 *addr_cvr = SYST_CVR;
	volatile u32 *addr_csr = SYST_CSR;
	volatile u32 *addr_rvr = SYST_RVR;

	if ((clock_local.flags & CLOCKF_INITIALIZED) != 0U) {
		key = hwip_disable();

		/* Get the number of counts for previous timeout events */
		timestamp = ((u64) clock_local.ticks) * ((u64) ((*addr_rvr) + 1U));

		/* Compute remaining number of counts after timeouts */
		count1 = *(addr_cvr);
		syst_csr = *(addr_csr);
		count2 = *(addr_cvr);

		wrap = syst_csr & SYST_WRAP_BIT;        /* Get if systick timer wrapped around 0 now */

		if ((count1 > count2) && wrap) {        /* Update timestamp accordingly */
			timestamp += (u64) ((((*addr_rvr) + 1U) - count1) + ((*addr_rvr) + 1));
		} else {
			timestamp += (u64) (((*addr_rvr) + 1U) - count1);
		}

		/* Get time in ns by dividing counts by frequency */
		timestamp *= (u64) (1000000000ULL / BOOT_FREQUENCY_HZ);

		hwip_restore(key);
	}

	return timestamp;
}

u32 clockp_get_tick_period(void)
{
   return SYST_TICK_PERIOD_US;
}

s32 clockp_create(clockp_fxn clk_fxn, u32 ticks_per_timeout)
{

	s32 ret = SUCCESS;
	#if 0
	unsigned int key;
	volatile u32 *addr = SHPR3;

	UNUSED(clk_fxn);
	UNUSED(ticks_per_timeout);

	/* Set priority value for systick interrupt */
	*addr &= ~(0xFF >> SYST_INDEX);
	*addr |= (SYST_INT_PRIORITY << SYST_INDEX);

	/* protect the context by disable the interrupt */
	key = hwip_disable();

	/* stop timer */
	addr = SYST_CSR;
	*addr &= ~(SYST_TIMER_START);

	clockp_systicktimer_setup();

	/* Enable interrupts */
	hwip_restore(key);

	clock_local.flags |= CLOCKF_INITIALIZED;

	/* start timer */
	*addr |= SYST_TIMER_START;
	#endif
	return ret;
}

s32 clockp_start(void)
{
	s32 ret = SUCCESS;
#if 0
	volatile u32 *addr_csr = SYST_CSR;
	volatile u32 *addr_cvr = SYST_CVR;

	unsigned int key;

	key = hwip_disable();

	hwip_clear_interrupt(SYST_INT_NUM);
	hwip_enable_interrupt(SYST_INT_NUM, &key);

	*addr_cvr = 0;                                          /* Reset counter, forces reload of period value */
	*addr_csr |= (SYST_TIMER_START | SYST_MCU_CLK_SEL);     /* Start timer, select processor clock */

	hwip_restore(key);
#endif
	return ret;
}

s32 clockp_stop(void)
{
	s32 ret = SUCCESS;
#if 0
	/* Does not return anything */
	volatile u32 *addr = SYST_CSR;

	/* Stop timer */
	*addr &= ~(SYST_TIMER_START);
	hwip_disable();
#endif
	return ret;
}

s32 clockp_suspend(void)
{
	s32 ret;

	ret = clockp_stop();

	return ret;
}

s32 clockp_resume(void)
{
	s32 ret = SUCCESS;
#if 0
	u64 count_val = 0;
	volatile u32 *addr;

	count_val =  ((u64) BOOT_FREQUENCY_HZ * clock_local.timeout_ns) / 1000000000U;

	/* Set reload value */
	addr = SYST_RVR;
	*addr = count_val - 1;

	/* Set count value */
	addr = SYST_CVR;
	*addr = count_val - 1;

	ret = clockp_start();
#endif
	return ret;
}

void Systick_handler()
{
	volatile u32 *addr_cvr = SYST_CVR;

	/* Increment timeout ticks */
	clock_local.ticks++;

	/* Clear current status register and current value reister by writing any value to CVR */
	*addr_cvr = 0;
}
