/*
 * System Firmware ARM Cortex M3 interrupt routines
 *
 * Cortex-M3 (CM3) firmware for power management
 *
 * Copyright (C) 2014-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef ARCH_INTERRUPT_H
#define ARCH_INTERRUPT_H

#include <types/short_types.h>
#include <types/sbool.h>

/* Save IRQ state and disable IRQs */
extern u32 arch_local_irq_save(void);

/* Restore IRQ state */
extern void arch_local_irq_restore(u32 flags);

/**
 * \brief Get currently executing exception
 *
 * \return Current interrupt number if called in handler mode, or 0 if called in
 *         thread mode
 */
extern u32 get_current_interrupt(void);

/**
 * \brief Check if specific interrupt is pending
 *
 * \param irq_num Interrupt request to check if pending
 *
 * \return STRUE if irq is pending, else return SFLASE
 */
extern sbool is_interrupt_pending(u32 irq_num);

/** Make a call to wfi to wait for interrupt */
#define wfi()           asm (" wfi")

extern void unmask_interrupts(void);
extern void mask_interrupts(void);

#define DMSC_NVIC_EXT_INT_OFFSET 16U
/** NVIC Offset macro to add system interrupt offset to TRM IRQ numbers. */
#define NVIC_IRQ(_val)  (((u32) (_val)) + DMSC_NVIC_EXT_INT_OFFSET)

#endif /* ARCH_INTERRUPT_H */
