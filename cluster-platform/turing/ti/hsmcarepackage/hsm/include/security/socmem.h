/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file socmem.h
 *
 * \brief  Function do local address to global and reverse lookups
 *
 */

#ifndef SOCMEM_H_
#define SOCMEM_H_

#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>

/**
 * \brief Lookup global address from local address
 *
 * \param ptr Local pointer to translate to global address
 * \param global_addr Global address returned
 *
 * \return EFTOK if a valid mapping was located
 */
fterr socmem_to_global(local_phys_addr_t ptr, soc_phys_addr_t *global_addr);

/**
 * \brief Lookup local address from global address
 *
 * \param global_addr Global address for which translation is needed
 * \param ptr Local pointer return value
 *
 * \return EFTOK if a valid mapping was located
 */
fterr socmem_to_local(soc_phys_addr_t global_addr, local_phys_addr_t *ptr);

#endif /* SOCMEM_H_ */
