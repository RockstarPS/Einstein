/*
 * System Firmware OSAL HWI layer
 *
 * OSAL HWI layer for generic peripheral interrupts
 *
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_OSAL_HWI_H
#define OSAL_OSAL_HWI_H

#include <types/short_types.h>

/**
 * \brief Clears a specific interrupt's pending status.
 *
 * \param irq_num Hardware interrupt number
 *
 * \return 0 on success, error code otherwise.
 */
u32 osal_hwip_clear_interrupt(u32 irq_num);

/**
 * \brief Disable a specific interrupt.
 *
 * \param irq_num Hardware interrupt number
 *
 * \return 0 on success, error code otherwise.
 */
u32 osal_hwip_disable_interrupt(u32 irq_num);

/**
 * \brief Enable a specific interrupt.
 *
 * \param irq_num Hardware interrupt number
 *
 * \return 0 on success, error code otherwise.
 */
u32 osal_hwip_enable_interrupt(u32 irq_num);

/**
 * \brief Disable interrupts globally and unconditionally.
 *
 * \return A key to be used with hwip_restore representing current state.
 */
u32 osal_hwip_disable(void);


/**
 * \brief Restore interrupts to a previous state held in key.
 *
 * \param key Value returned from hwip_enable or hwip_disable.
 *
 * This call is used to restore interrupts to the state previous to a call
 * to hwip_enable or hwip_disable when the returned key value is passed.
 */
void osal_hwip_restore(u32 key);

#endif /* OSAL_OSAL_HWI_H */
