/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file tisci_security.h
 *
 * \brief Register TI-SCI clients security
 *
 */

#ifndef TISCI_SECURITY_H_
#define TISCI_SECURITY_H_

#include <types/short_types.h>
#include <types/fterr.h>
/**
 * Function to register clients with TI-SCI framework
 *
 * \return EFTOK if successful, error code otherwise
 */
fterr tisci_security_register_clients(void);

#endif /* TISCI_SECURITY_H_ */
