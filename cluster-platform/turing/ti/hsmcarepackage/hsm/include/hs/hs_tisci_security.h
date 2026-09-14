/*
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file hs_tisci_security.h
 *
 * \brief Register TI-SCI clients for security for HS devices
 *
 */

#ifndef HS_TISCI_SECURITY_H_
#define HS_TISCI_SECURITY_H_

#include <types/short_types.h>
#include <types/fterr.h>
/**
 * Function to register clients with TI-SCI framework for HS devices
 *
 * \return EFTOK if successful, error code otherwise
 */
fterr hs_tisci_security_register_clients(void);

#endif /* TISCI_SECURITY_H_ */
