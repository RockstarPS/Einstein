/*
 * System Firmware OSAL
 *
 * HWI (Hardware Interrupt) OSAL API Definition
 *
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_HWIP_H
#define OSAL_HWIP_H

#include "interrupt.h"
#include "osal_hwi.h"
#include "short_types.h"

typedef void (*hwip_fxn)(u32 arg0);

/**
 * \brief Contains HWI configuration information
 *
 * \param priority Priority level of this interrupt
 * \param arg Argument that will be provided to the hwip_fxn at runtime.
 */
struct hwip_params {
	u32	priority;
	u32	arg;
};

/**
 * \brief Creates and initializes a static HWI object based on ID.
 *
 * \param hwi_id HWI ID number
 * \param int_num Hardware interrupt number
 * \param hwi_fxn Pointer to the interrupt handler for this interrupt
 * \param params Pointer to a struct containing configuration for this HWI
 *
 * \return 0 on success, error code otherwise.
 *
 * This function statically constructs a new HWI object to handle an interrupt.
 * Interrupts are identified by a hwi_id which is nothing more than an index
 * into an array of static Hwi_Structs. All hwip calls use this same index to
 * identify interrupts to maintain the actual static data scope in this file
 * and avoid the need to pass around the HWI objects. Each hwi can be assigned
 * an hwi_data struct to allow application specific data to be passed to the
 * hwi_fxn when it is executed. When an HWI is created the interrupt is
 * not-enabled at creation time. It must be enabled after with a call to
 * hwip_enable_interrupt.
 */
s32 hwip_create(u32 hwi_id, s32 int_num, hwip_fxn hwi_fxn, struct hwip_params *params);

/**
 * \brief Destruct an hwi in the static task list and prepare for reuse
 *
 * \param hwi_id HWI ID Number
 *
 * \return 0 on success, error code otherwise.
 *
 * This function destructs an existing static hwi object and makes sure it
 * is ready for reuse through another call to hwip_create.
 */
s32 hwip_delete(u32 hwi_id);

/**
 * \brief Clears a specific interrupt's pending status.
 *
 * \param irq_num Hardware interrupt number
 *
 * \return 0 on success, error code otherwise.
 */
s32 hwip_clear_interrupt(u32 irq_num);

/**
 * \brief Clears all interrupt's pending status.
 *
 * This function is potentially useful at boot time to ensure
 * a clean system. This clears all external interrupts to the DMSC
 * but does not touch internal exceptions.
 */
void hwip_clear_all_interrupts(void);

/**
 * \brief Disable a specific interrupt.
 *
 * \param irq_num Hardware interrupt number
 * \param key Value representing current state to be used with
 *	      hwip_restore_interrupt
 *
 * \return 0 on success, error code otherwise.
 */
s32 hwip_disable_interrupt(u32 irq_num, u32 *key);

/**
 * \brief Enable a specific interrupt.
 *
 * \param irq_num Hardware interrupt number
 * \param key Value representing current state to be used with
 *	      hwip_restore_interrupt
 *
 * \return 0 on success, error code otherwise.
 */
s32 hwip_enable_interrupt(u32 irq_num, u32 *key);

/**
 * \brief Restore an interrupt to a previous state held in key.
 *
 * \param irq_num Hardware interrupt number
 * \param key Key value from hwip_enable_interrupt or hwip_disable_interrupt.
 *
 * \return 0 on success, error code otherwise.
 *
 * This call is used to restore an interrupt to the state previous to a call
 * to hwip_enable_interrupt or hwip_disable_interrupt when the returned key
 * value is passed.
 */
s32 hwip_restore_interrupt(u32 irq_num, u32 key);

/**
 * \brief Disable interrupts globally and unconditionally.
 *
 * \return A key to be used with hwip_restore representing current state.
 */
u32 hwip_disable(void);

/**
 * \brief Enable interrupts globally and unconditionally.
 *
 * \return A key to be used with hwip_restore representing current state.
 */
u32 hwip_enable(void);

/**
 * \brief Restore interrupts to a previous state held in key.
 *
 * \param key Value returned from hwip_enable or hwip_disable.
 *
 * This call is used to restore interrupts to the state previous to a call
 * to hwip_enable or hwip_disable when the returned key value is passed.
 */
void hwip_restore(u32 key);

#endif /* OSAL_HWIP_H */
