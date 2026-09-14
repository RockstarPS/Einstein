/*
 * \file ti_app.h
 *
 * \brief Interface for TI application initialization
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */


#ifndef HSM_OSAL_H
#define HSM_OSAL_H

#include <config.h>
#include <types/array_size.h>
#include <hsm_core/hsm.h>

s32 ti_app_init(void);

/**
 * \brief Common handler function for various interrupts in security.
 *
 * \param a Private data structure of the ISR.
 */
void secure_msg_hwi_fxn(u32 a);

/**
 * \brief Common handler function for various interrupts in for non-secure
 *        messages.
 *
 * \param a Private data structure of the ISR.
 */
void user_msg_hwi_fxn(u32 a);

/**
 * \brief Common task to process secure messages
 *
 * \param a Private data structure of the ISR.
 */
void secure_msg_task_fxn(u32 a0, u32 a1 __attribute__((unused)));

/**
 * \brief Common task to process non-secure messages
 *
 * \param a Private data structure of the ISR.
 */
void user_msg_task_fxn(u32 a0, u32 a1 __attribute__((unused)));

#endif
