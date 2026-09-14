/*
 * System Firmware SMS Interrupt Router descriptions
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sms_ir.h
 *
 * \brief Include file for Secure Proxy Data descriptions and initialization
 *	routine
 */

#ifndef SMS_IR_DESC_H
#define SMS_IR_DESC_H

#include <types/sbool.h>
#include <types/short_types.h>
#include <types/address_types.h>


/**
 * \brief Describe and Interrupt Router instance for SMS
 * \param cfg_cfg - cfg region for IR
 * \param n_inp - Number of IR inputs
 * \param n_outp - Number of IR outputs
 * \param outp_to_sms_start - Output num connecting to start of SMS interrupts
 * \param inp0_mapping - Used to track usage of IR input 0
 */

struct sms_ir_instance {
	local_phys_addr_t	cfg_cfg;
	const u16		n_inp;
	const u16		n_outp;
	const u16		outp_to_sms_start;
	u16			inp0_mapping;
};

/** SMS Interrupt_router Instance */
extern struct sms_ir_instance sms_ir;

/**
 * \brief Initialize SMS Interrupt Router
 *
 */
#ifdef CONFIG_SMS_IR
extern s32 sms_ir_init(void);
#else
static inline s32 sms_ir_init(void)
{
	return 0;
}
#endif

#endif
