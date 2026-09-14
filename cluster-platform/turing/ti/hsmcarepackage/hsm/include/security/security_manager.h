/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file security_manager.h
 *
 * \brief  DMSC security manager driver
 *
 */

#ifndef SECURITY_MANAGER_H_
#define SECURITY_MANAGER_H_

#include <types/short_types.h>
#include <types/ftbool.h>
#include <types/fterr.h>

/**
 * \brief check if this is a secure device (HS or EMU)
 *
 * \return FT_TRUE if secure device
 */
ftbool sec_mgr_is_secure_device(void);

/**
 * \brief check if this is a EMU device
 *
 * \return FT_TRUE if emu device
 */
ftbool sec_mgr_is_emu_device(void);

/**
 * \brief check if security is enforced or not
 * i.e. Security Enforced or Field Securable
 *
 * \return FT_TRUE if security enforced,
 *         FT_FALSE if field securable
 */
ftbool sec_mgr_is_security_enforced(void);

/**
 * \brief check if debug is enabled in the master debug control register
 *
 * \return FT_TRUE if debug enabled, FT_FALSE otherwise
 */
ftbool sec_mgr_is_debug_enabled(void);

/**
 * \brief read smek from security manager registers
 *
 * \param key Place to copy the SMEK
 *
 * \return EFTOK if successful
 */
fterr sec_mgr_read_smek(u32 *key);
fterr sec_mgr_read_bmek(u32 *key);

fterr sec_mgr_read_smpkh(u32 *hash);
fterr sec_mgr_read_bmpkh(u32 *hash);

/**
 * \brief lock access to TI MEK in the efuses
 *
 * ROM locks access to TI MEK only on prime devices.
 * System firmware does not have a usecase where TI MEK needs to be used.
 * To prevent key leakage, block RW access to it and lock the access config
 * register.
 *
 * \return EFTOK if successful
 */
fterr sec_mgr_lock_ti_mek(void);

/**
 * \brief Check that access to TI MEK is disabled.
 *
 * \return EFTOK if access is disabled, error code otherwise
 */
fterr sec_mgr_check_ti_mek_lock(void);

/**
 * \brief parse customer key count register and return customer key count.
 *
 * \return customer key count.
 */
u32 sec_mgr_get_cust_key_cnt(void);

/**
 * \brief parse customer key revision register and return customer key revision.
 *
 * \return customer key revision.
 */
u32 sec_mgr_get_cust_key_rev(void);

/**
 * \brief parse and return software revision.
 *
 * \param KEY_ID 0 for SWREV_SYSFW, 1 for SWREV_SBL.
 *
 * \return Requested software revision.
 */
u32 sec_mgr_get_swrev(u8 KEY_ID);

/**
 * \brief Copy the active customer encryption key (SMEK/BMEK)
 * into the provided buffer.
 *
 * \param key buffer to copy the key into. The buffer must be 32 bytes long.
 *
 * \return EFTOK if successful
 */
fterr sec_mgr_read_active_cmek(u32 *key);

/**
 * \brief Copy the active customer public key hash (SMPK/BMPK)
 * into the provided buffer.
 *
 * \param hash buffer to copy the hash into. The buffer must be 64 bytes long.
 *
 * \return EFTOK if successful
 */
fterr sec_mgr_read_active_cmpkh(u32 *hash);

/**
 * \brief Bypass SOC firewalls on HS devices
 *
 * \return EFTOK if SOC firewalls were disabled, error code otherwise.
 */
fterr sec_mgr_bypass_soc_fwls(void);

/**
 * \brief Open various debug taps in the system
 *
 * \param debug_level Indicate the debug level to be configured.
 *                    The value used here is an enum from SDBG_LEVELS
 *
 * \return EFOK if successful
 */
fterr sec_mgr_open_debug_taps(u32 debug_level);

/**
 * \brief Enable SAUL PSIL global config writes
 *
 * \return EFOK if successful
 */
fterr sec_mgr_enable_saul_psil_global_config_writes(void);

/**
 * \brief Configure the SOC debug and trace control
 *
 * \param debug_level Indicate the debug level to be configured.
 *                    The value used here is an enum from SDBG_LEVELS
 *
 * \return EFOK if successful
 */
fterr sec_mgr_set_soc_debug_trace_ctl(u32 debug_level);

/**
 * \brief Configure security manager to mirror status values into
 *        the publicly readable area.
 *
 * \return EFTOK if successful
 */
fterr sec_mgr_allow_status_mirroring(void);

/**
 * \brief Return value of OTP MMR
 *
 * \param mmr_idx Index of the OTP MMR that needs to be read
 * \param mmr_val Contains the value read from the MMR on return.
 *
 * \return EFTOK if successful, error code otherwise
 */
fterr sec_mgr_get_otp_mmr(u8 mmr_idx, u32 *mmr_val);

#endif /* SECURITY_MANAGER_H_ */
