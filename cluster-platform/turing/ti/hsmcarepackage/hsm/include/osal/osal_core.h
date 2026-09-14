/*
 * System Firmware OSAL Core APIs
 *
 * OSAL Core Public APIs used for intialization and firmware control
 *
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_CORE_H
#define OSAL_CORE_H

#include <types/short_types.h>
#include <types/sbool.h>

#define SUBSYSTEM_ENABLED       ((u32) 0xAu)

#define SUBSYSTEM_BP_MASK       0x0000000Fu
#define SUBSYSTEM_BP_SHIFT      0u
#define SUBSYSTEM_BP            (SUBSYSTEM_ENABLED << SUBSYSTEM_BP_SHIFT)


void osal_subsystem_set_init(u32 subsystem);

void osal_subsystem_set_init_core(u32 subsystem);

sbool osal_subsystem_check_init(u32 subsystem);

/**
 * \brief check osal state whether core has been initialized.
 *
 * \return internal osal system initialization state
 */
sbool osal_core_is_configured(void);

/**
 * \brief To be invoked after boardcfg is received to allow OSAL to
 *        reconfigure itself as needed when boardcfg data is available.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 osal_core_post_config_init(void);

s32 osal_core_verify_host_id(u8 host_id);

/**
 * \brief Raw buffer output function for use with low level rtos printing.
 *
 * \param buf Pointer to collection of character to be output.
 * \param len Number of characters to be output.
 */
void osal_trace_print_output(u8 *buf, u32 len);

#endif /* OSAL_CORE_H */
