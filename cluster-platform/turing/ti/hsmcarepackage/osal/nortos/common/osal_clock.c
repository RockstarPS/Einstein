/*
 * System Firmware OSAL Clock layer
 *
 * OSAL Core clock layer
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "clockp.h"
#include "taskp.h"
#include "osal_halt.h"
#include "osal_clock.h"
#include "osal_core.h"
#include "osal_secure.h"
#include "osal_config.h"
#include "errno.h"
#include "short_types.h"
#include "dmsc_hw.h"

static void secure_core_clock_tick_fxn(u32 arg __attribute__((unused)))
{
	return;
}

s32 osal_create_system_clock(void)
{
	s32 ret;

	ret = clockp_create(secure_core_clock_tick_fxn,
			    CLK_FUNCTION_TIMEOUT_TICKS);
	return ret;
}

void osal_sleep_us(u32 usecs)
{
	u32 clock_ticks;
	u32 tick_period;

	tick_period = clockp_get_tick_period();

	/* Sleep only if we have completed CLOCKF initialization */
	if (tick_period != 0U) {
		clock_ticks = usecs / tick_period;

		/* Round up to nearest ms if usecs is not an even period*/
		if (usecs % tick_period != 0U) {
			clock_ticks = clock_ticks + 1U;
		}

		osal_sleep_ticks(clock_ticks);
	} else {
		/*
		 * There is no time reference for us to sleep if
		 * CLOCKF is not initialized. HALT to allow for debug
		 */
		osal_system_halt(-EINVAL);
	}
}

void osal_sleep_ticks(u32 clock_ticks)
{
	(void) taskp_sleep(clock_ticks);
}

u32 osal_get_tick_period(void)
{
	return clockp_get_tick_period();
}

void osal_delay_core(u64 usecs)
{
	u64 delay = usecs * 1000U; /* Convert to ns */

	if (clockp_is_initialized()) {
		u64 timestamp = clockp_get_time64();
		while ((clockp_get_time64() - timestamp) < delay) {
		}
	} else {
		/*
		 * Approximate uS delay. Assume 6 cycles per loop and convert
		 * from units of uS.
		 */
		delay *= BOOT_FREQUENCY_HZ / (6U * 1000000U);
		do {
			asm ("");
		} while (delay--);
	}
}

u32 osal_timestamp32_core(void)
{
	return clockp_get_time32();
}

u64 osal_timestamp64_core(void)
{
	return clockp_get_time64();
}

sbool osal_time_is_initialized(void)
{
	return clockp_is_initialized();
}
