/*
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef SEC_PROC_UTILS_H
#define SEC_PROC_UTILS_H

/**
 * Checks if a id represents a valid core in the current SOC.
 *
 * \param core_id id that needs to be validated.
 *
 * \return EFTOK if id is valid, error code otherwise.
 */
fterr is_core_id_valid(u8 core_id);

/**
 * Checks if a core supports secure debug
 *
 * \param core_id id of the core that needs to be checked.
 *
 * \return EFTOK if secure debug is supported, error code otherwise.
 */
fterr is_secure_debug_supported(u8 core_id);

/**
 * Configure secure/non secure debug for a core.
 *
 * \param core_id id of the core that needs to be configured.
 *
 * \param enable_non_sec_debug flag indicating whether non-secure debug
 * needs to be enabled. This includes both invasive and non invasive
 * non-secure debug.
 *
 * \param enable_sec_debug flag indicating whether secure debug
 * needs to be enabled. This includes both invasive and non invasive
 * secure debug.
 *
 * \return EFTOK if secure debug is supported, error code otherwise.
 */
fterr proc_debug_configure(u8 core_id, u8 enable_non_sec_debug, u8 enable_sec_debug);

/**
 * Get secure/non secure debug status for a core.
 *
 * \param core_id id of the core that needs to be configured.
 *
 * \param enable_non_sec_debug flag indicating whether non-secure debug is
 * enabled. This includes both invasive and non invasive non-secure debug.
 *
 * \param enable_sec_debug flag indicating whether secure debug is enabled. This
 * includes both invasive and non invasive secure debug.
 *
 * \return EFTOK if secure debug is supported, error code otherwise.
 */
fterr proc_debug_get(u8 core_id, u8 *enable_non_sec_debug, u8 *enable_sec_debug);
#endif
