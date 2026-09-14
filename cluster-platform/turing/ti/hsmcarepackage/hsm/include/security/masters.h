/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file masters.h
 *
 * \brief File that contains functions to manage/query the list of security
 *        masters in K3 system.
 *
 */

#ifndef MASTERS_H_
#define MASTERS_H_

#include <types/short_types.h>
#include <types/fterr.h>

#include <masters_bootcfg.h>

/**
 * \brief Intialize master list using bootcfg data
 *
 * \param bootcfg Boot configuration data
 *
 * \return EFTOK if successful
 */
fterr masters_init(const struct master_bootcfg_list *bootcfg);

/**
 * \brief Get priv-id of a master index
 *
 * \param index Master index
 * \return Priv-ID of the master
 */
u8 masters_get_privid(u8 index);

/**
 * \brief Check if the master needs to allow secure accesses
 *
 * \param index Master index
 * \return FT_TRUE if secure is allowed
 */
ftbool masters_allow_secure(u8 index);

/**
 * \brief Check if the master needs to allow non-secure accesses
 *
 * \param index Master index
 * \return FT_TRUE if non-secure is allowed
 */
ftbool masters_allow_nsecure(u8 index);

/**
 * \brief Check if the master needs to allow privileged accesses
 *
 * \param index Master index
 * \return FT_TRUE if privileged is allowed
 */
ftbool masters_allow_priv(u8 index);

/**
 * \brief Check if the master needs to allow user accesses
 *
 * \param index Master index
 * \return FT_TRUE if user is allowed
 */
ftbool masters_allow_user(u8 index);

/**
 * \brief Fetch the security attributes for a host
 *
 * \param host Host ID
 * \param creds Firewall credentials for this master
 * \param fwl_perm Firewall permission bits
 *
 * \return EFTOK if host ID is valid
 */
fterr masters_get_host_attrs(u8 host, struct master_creds *creds, u32 *fwl_perm);

#endif /* MASTERS_H_ */
