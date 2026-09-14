/*
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file common_funcs.c
 *
 * \brief  Common functions
 */

#include <common_funcs.h>
#include <osal_clock.h>


sbool reg_poll_timeout_us(volatile u32 raddr[1], u32 mask,
			  u32 val, u32 us)
{
	u32 start_time, time_diff, tmout_ns, clk_period;

	tmout_ns = us * 1000U;
	time_diff = ((u32) 0U);
	osal_create_system_clock();
	clk_period = osal_get_tick_period();
	start_time = osal_timestamp32_core();

	while (((readl(raddr) & mask) != val) && (time_diff < tmout_ns)) {
		if (osal_time_is_initialized()) {
			/*
			 * If BIOS is initialized, use a function that
			 * uses task_sleep() underneath
			 */

			/*
			* check if the time out value is less one tick before
			* sleeping
			*/
			if (us >= clk_period) {
				osal_sleep_ticks(0U);
			}
		} else {
			/*
			 * If BIOS is not initialized, use a function that
			 * does a busy loop until time out.
			 */
			osal_delay_core(1U);
		}
		time_diff = osal_timestamp32_core() - start_time;
	}
	return (readl(raddr) & mask) == val;
}
