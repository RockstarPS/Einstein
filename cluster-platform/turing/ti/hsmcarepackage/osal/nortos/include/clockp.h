/*
 * System Firmware OSAL
 *
 * Clock OSAL API Definition
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_CLOCKP_H
#define OSAL_CLOCKP_H

#include <types/short_types.h>
#include <types/sbool.h>

typedef void (*clockp_fxn)(u32 arg);

/**
 * \brief Construct the static system clock
 *
 * \param clk_fxn Periodic callback that runs in HWI context
 * \param ticks_per_timeout System timer ticks between triggering clock_fxn
 *
 * \return 0 on success
 *
 * This function creates the system clock, of which there should only be a
 * single instance, and immediately starts it running. It is driven
 * by a system timer and ticks the clock every 1000 uS. The provided clk_fxn
 * is called at every timeout as specified by ticks_per_timeout.
 *
 */
s32 clockp_create(clockp_fxn clk_fxn, u32 ticks_per_timeout);

/**
 * \brief Start the timer used for system clock tick.
 *
 * \return 0 on success
 *
 * This function can used to start the system clock tick. Implementation of this
 * depends on the specific type of timer used, though typically involves
 * enabling the timer counter to enable generation of tick events.
 */
s32 clockp_start(void);

/**
 * \brief Stop the timer used for system clock tick
 *
 * \return 0 on success
 *
 * This function can used to stop the system clock tick. Implementation of this
 * depends on the specific type of timer used, though typically involves
 * disabling the timer counter to stop generation of tick events.
 */
s32 clockp_stop(void);

/**
 * \brief Return STRUE if clockp has been initialized
 *
 * \return STRUE if initialized, SFALSE otherwise.
 *
 * This function can be used to determine if a system clock has
 * been created.
 */
sbool clockp_is_initialized(void);

/**
 * \brief Return the number of nanoseconds since the clock was created.
 *
 * \return 32-bit integer representing nanoseconds. Will return 0 if
 *         the clock has not been initialized.
 */
u32 clockp_get_time32(void);

/**
 * \brief Return the number of nanoseconds since the clock was created.
 *
 * This function may have greater latency than clockp_get_time32 due to the
 * need to build a 64 bit timestamp from a low and high word.
 *
 * \return 64-bit integer representing nanoseconds. Will return 0 if
 *         the clock has not been initialized.
 */
u64 clockp_get_time64(void);

/**
 * \brief Return the period of the clock tick in microseconds
 *
 * \return The period of the clock tick in microseconds. Will return 0 if
 *         the clock has not been initialized.
 */
u32 clockp_get_tick_period(void);

/**
 * \brief Suspend the system clock.
 *
 * \return SUCCESS on success
 *
 * This function stops and suspends the system clock.
 */
s32 clockp_suspend(void);

/**
 * \brief Resumes the system clock.
 *
 * \return SUCCESS on success
 *
 * This function resumes and starts the system clock.
 */
s32 clockp_resume(void);

#endif /* OSAL_CLOCKP_H */
