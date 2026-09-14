/*
 * Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_auth_rm.h
 *
 * \brief Management of SA2UL authentication resources
 *
 */

#ifndef SA2UL_AUTH_RM_H_
#define SA2UL_AUTH_RM_H_

#include <config.h>
#include <types/fterr.h>
#include <tisci/security/tisci_sa2ul_rm.h>

#if defined CONFIG_SECURITY_SA2UL_AUTH_RM
/**
 * Initialize the sa2ul auth resource management
 */
void sa2ul_rm_auth_init(void);

/**
 * \brief Acquire authentication resources
 *
 * \param host Host ID of the requestor
 */
fterr sa2ul_rm_auth_acquire(u8 host);

/**
 * \brief Release authentication resources
 *
 * \param host Host ID of the requestor
 */
fterr sa2ul_rm_auth_release(u8 host);

/**
 * Acquire semaphore for access to sa2ul authentication resources
 *
 * This function will pend on semaphore for auth resources with no timeout. If
 * the resource is available
 *
 * \return semaphore pend status
 */
fterr sa2ul_auth_sem_get(void);

/**
 * Release the sa2ul authentication semaphore
 */
void sa2ul_auth_sem_release(void);

#else
static inline fterr sa2ul_auth_sem_get(void)
{
	return EFTOK;
}

static inline void sa2ul_auth_sem_release(void)
{
	return;
}

#endif

#endif /* SA2UL_AUTH_RM_H_ */
