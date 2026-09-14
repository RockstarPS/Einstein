/*
 * System Firmware Ring Accelerator init functions
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef RINGACEL_H
#define RINGACEL_H

#include <config.h>
#include <types/short_types.h>
#include <types/devgrps.h>

/**
 * \brief Initialize all basic rings
 *
 * Initialize all the SoC rings necessary for operation
 *
 * \return 0 if all went fine, else return corresponding error
 * NOTE: On Error, rings may only be partially configured.
 */
#ifdef CONFIG_RA_LIB
extern s32 ralib_ring_init(void);
#else
static inline s32 ralib_ring_init(void)
{
	return 0;
}
#endif

/**
 * \brief Initialize the rings for a specific devgrp
 *
 * \param devgrp - devgrp to initialize for
 *
 * \return 0 if all went fine, else return corresponding error.
 * NOTE: On Error, rings may be partially configured.
 */
#ifdef CONFIG_RA_LIB
extern s32 ralib_init_devgrp(devgrp_t devgrp);
#else
static inline s32 ralib_init_devgrp(devgrp_t devgrp)
{
	return 0;
}
#endif

#endif  /* RINGACEL_H */
