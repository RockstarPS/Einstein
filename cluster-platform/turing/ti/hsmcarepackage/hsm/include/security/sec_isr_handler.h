/**
 * \file sec_isr_handler.h
 *
 * Header for handling all security related interrupts in a single task,
 *
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SEC_ISR_HANDLER_H
#define SEC_ISR_HANDLER_H

#include <types/short_types.h>

#include <hwip.h>

typedef void (*sec_isr_fxn)(void *arg0);

/**
 * data for the security interrupt handler and the corresponding call back
 * function.
 *
 * \param irq_num The irq number for this HWI.
 *
 * \param func - call back function for HWI specific handling. A pointer to the
 * sec_isr_data structure is passed as an argument to this function.
 *
 * \param arg - pointer to any data required by the call back function.
 */
struct sec_isr_data {
	u32		irq_num;
	sec_isr_fxn	func;
	void		*arg;
};

extern struct sec_isr_data *sec_isr_data_list[];
extern const u8 sec_isr_data_list_count;

#endif
