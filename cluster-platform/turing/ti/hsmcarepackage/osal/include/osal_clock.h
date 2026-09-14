/*
 * System Firmware OSAL Clock delay APIs
 *
 * OSAL Core Public APIs for delay and sleep
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef OSAL_CLK_H
#define OSAL_CLK_H

#include <types/short_types.h>
#include <types/sbool.h>

/**
 * \brief Create the system clock for the osal clock module
 *
 * \return SUCCESS upon succesful creation or error otherwise
 */
s32 osal_create_system_clock(void);

/**
 * \brief Cause the task to enter blocked state and not be scheduled until
 *	  `usecs` elapses. This is provided for convenience but will still
 *        actually use clock_ticks for the backend implementation, meaning
 *        the actual valid values will be limited to the system tick period
 *        and any aligned to the tick boundary will be rounded up to the next
 *        nearest tick.
 *
 * \param msecs Amount of time to wait until task is scheduled again.
 */
void osal_sleep_us(u32 msecs);

/**
 * \brief Cause the task to enter blocked state and not be scheduled until
 *	  `clock_ticks` elapses. The default time for a clock tick is 1000uS.
 *
 * \param clock_ticks Number of ticks of system clock to wait until task
 *	  is scheduled again.
 */
void osal_sleep_ticks(u32 clock_ticks);

/**
 * \brief Get the system clock tick period
 *
 * \return Period of the system clock tick
 */
u32 osal_get_tick_period(void);

/**
 * \brief Block inside the current task for the specified amount of time.
 *
 * \param usecs Amount of time to block before continuing execution. Max delay
 *		 is ((2^64 - 1)/1000) microseconds.
 *
 * NOTE: Able to be used in no interrupt context.
 */
void osal_delay_core(u64 usecs);

/**
 * \brief Return time in ns since system clock was started as 32-bit number.
 *
 * This returns a 32-bit number representing ns since syystem clock start
 * and wraps around once overflow occurs.
 *
 * \return 0 if timer is not yet initialized or ns since clock start.
 *
 * NOTE: Able to be used in no interrupt context.
 */
u32 osal_timestamp32_core(void);

/**
 * \brief Return time in ns since system clock was started as 64-bit number.
 *
 * This returns a 64-bit number representing ns since syystem clock start
 * and wraps around once overflow occurs.
 *
 * \return 0 if timer is not yet initialized or ns since clock start.
 *
 * NOTE: Able to be used in no interrupt context.
 */
u64 osal_timestamp64_core(void);

/**
 * \brief Return STRUE if OSAL time functions are initialized.
 *
 * \return STRUE if OSAL time functions are initialized, SFALSE otherwise.
 */
sbool osal_time_is_initialized(void);

#endif /* OSAL_CLK_H */
