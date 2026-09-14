/*
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file hs_security_init.h
 *
 * \brief Init function for HS only security component
 *
 * The functions in this file are internal to security
 * and must not be invoked directly SYSFW init.
 */

#ifndef HS_SECURITY_INIT_H_
#define HS_SECURITY_INIT_H_

#include <types/short_types.h>
#include <types/fterr.h>

/** SYSBIOS Startup function for security component specific to HS devices */
void hs_security_startup_fxn(void);

/**
 * \brief Perform security initialization that is
 * independent of user input for HS devices.
 *
 * \return EFTOK if successful, error code otherwise
 */
fterr hs_security_early_init(void);

fterr hs_security_early_init_hsm(void);

/**
 * \brief Init function for the security component specific to HS devices
 *
 * This initialization is performed after the security init message is received
 * from the user. Configuration options provided by the user in the security
 * init message determine the actions performed by this function.
 *
 * HS specific Security API's are available over TISCI interface only after this function
 * executes.
 *
 * \return EFTOK if successful, errorcode otherwise
 */
fterr hs_security_init(void);

#endif
