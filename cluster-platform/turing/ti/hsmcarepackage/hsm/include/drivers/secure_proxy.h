/*
 * System Firmware Secure Proxy Configuration and Init APIs
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SECURE_PROXY_H
#define SECURE_PROXY_H

#include <config.h>
#include <types/short_types.h>
#include <types/devgrps.h>

/**
 * \brief Initialize all Secure proxies
 *
 * Initialize all the SoC Secure proxies necessary for operation
 *
 * \return 0 if all went fine, else return corresponding error
 * NOTE: On Error, rings may only be partially configured.
 */
#ifdef CONFIG_SEC_PROXY
extern s32 sproxy_init(void);
#else
static inline s32 sproxy_init(void)
{
	return 0;
}
#endif  /* CONFIG_SEC_PROXY */

/**
 * \brief Initialize the secure proxies for a specific devgrp
 *
 * \param devgrp - devgrp to initialize for
 *
 * \return 0 if all went fine, else return corresponding error.
 * NOTE: On Error, secure proxies may be partially configured.
 */
#ifdef CONFIG_SEC_PROXY
extern s32 sproxy_init_devgrp(devgrp_t devgrp);
#else
static inline s32 sproxy_init_devgrp(devgrp_t devgrp)
{
	return 0;
}
#endif  /* CONFIG_SEC_PROXY */

#endif  /* SECURE_PROXY_H */
