/*
 * System Firmware Source File
 *
 * Board configuration Public API
 *
 * Copyright (C) 2018-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef BOARD_CFG_API_H
#define BOARD_CFG_API_H

#include <config.h>
#include <types/devgrps.h>
#include <types/fterr.h>
#include <boardcfg/boardcfg_data.h>

/**
 * \brief Get a pointer to the local copy of the boardcfg_control data.
 *
 * \return NULL if the local board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_control *boardcfg_get_control(void);

/**
 * \brief Get a pointer to the local copy of the boardcfg_secproxy data.
 *
 * \return NULL if the local board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_secproxy *boardcfg_get_secproxy(void);

/**
 * \brief Get a pointer to the local copy of the boardcfg_msmc data.
 *
 * \return NULL if the local board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_msmc *boardcfg_get_msmc(void);

/**
 * \brief Get a pointer to the local copy of boardcfg_proc_acl data
 *
  \return NULL if the local board data has not yet been received or is
 *	   invalid, pointer otherwise.
 */
const struct boardcfg_proc_acl *boardcfg_get_proc_acl(void);

/**
 * \brief Get a pointer to the local copy of boardcfg_host_hierarchy data
 *
 * \return NULL if the local board data has not yet been received or is
 *	   invalid, pointer otherwise.
 */
const struct boardcfg_host_hierarchy *boardcfg_get_host_hierarchy(void);

/**
 * \brief Get a pointer to the local copy of the boardcfg_dbg_cfg data.
 *
 * \return NULL if the local board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_dbg_cfg *boardcfg_get_dbg_cfg(void);

/**
 * \brief Get a pointer to the local copy of the boardcfg_pmic_cfg data.
 *
 * \return NULL if the local board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_pmic_cfg *boardcfg_get_pmic_cfg(void);

/**
 * \brief Prototype for handler function to process boardcfg structure placed at specified addresss
 *
 * \param host Host ID of the sender
 * \param boardcfgp_low Low 32-bit of boardcfg struct address.
 * \param boardcfgp_high High 32-bit of boardcfg struct address.
 * \param boardcfg_size Size of the full boardcfg struct.
 * \param boardcfg_devgrp Device group for this boardcfg configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
typedef s32 (*boardcfg_process_fxn)(u8 host, u32 boardcfgp_low, u32 boardcfgp_high, u16 boardcfg_size, devgrp_t boardcfg_devgrp);

/**
 * \brief Receive a boardcfg power management structure placed at an
 *        external address and validate
 *
 * \param host Host ID of the sender
 * \param boardcfg_pmp_low Low 32-bit of boardcfg pm struct address.
 * \param boardcfg_pmp_high High 32-bit of boardcfg pm struct address.
 * \param boardcfg_pm_size Size of the full boardcfg pm struct.
 * \param boardcfg_pm_devgrp Device group for the PM configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_pm_receive_and_validate(u8 host, u32 boardcfg_pmp_low, u32 boardcfg_pmp_high, u16 boardcfg_pm_size, devgrp_t boardcfg_pm_devgrp);

/**
 * \brief Receive a boardcfg security placed at an external address and validate
 *
 * \param host Host ID of the sender
 * \param boardcfg_securityp_low Low 32-bit of boardcfg security struct address.
 * \param boardcfg_securityp_high High 32-bit of boardcfg security struct address.
 * \param boardcfg_security_size Size of the full boardcfg security struct.
 * \param boardcfg_security_devgrp Device group for the security configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_security_receive_and_validate(u8 host, u32 boardcfg_securityp_low, u32 boardcfg_securityp_high, u16 boardcfg_security_size, devgrp_t boardcfg_security_devgrp);

/**
 * \brief Receive a boardcfg resource management structure placed at an
 *        external address and validate
 *
 * \param host Host ID of the sender
 * \param boardcfg_rmp_low Low 32-bit of boardcfg rm struct address.
 * \param boardcfg_rmp_high High 32-bit of boardcfg rm struct address.
 * \param boardcfg_rm_size Size of the full boardcfg rm struct.
 * \param boardcfg_rm_devgrp Device group for the RM configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_rm_receive_and_validate(u8 host, u32 boardcfg_rmp_low, u32 boardcfg_rmp_high, u16 boardcfg_rm_size, devgrp_t boardcfg_rm_devgrp);

/**
 * \brief Receive a boardcfg placed at an external address and validate
 *
 * \param host Host ID of the sender
 * \param boardcfgp_low Low 32-bit of boardcfg struct address.
 * \param boardcfgp_high High 32-bit of boardcfg struct address.
 * \param boardcfg_size Size of the full boardcfg struct.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_receive_and_validate(u8 host, u32 boardcfgp_low, u32 boardcfgp_high, u16 boardcfg_size);


/**
 * \brief Copy the boardcfg hashes into dedicated memory.
 *
 * On a HS device, boardcfg needs to be integrity checked using hashes. In a
 * boot time optimized approach, these hashes are received via the SYSFW Outer
 * certificate. The SYSFW outer certificate is in a memory location used for
 * other purposes by SYSFW. This function copies the provided board
 * configuration hashes to a different location.
 *
 * This function is expected to be called during SYSFW init before sending the
 * ready notification to R5. This function does not parse the X509 certificate.
 * It only copies the provided hashes.
 *
 * \param sec_bcfg_hash pointer to security boardcfg hash
 * \param sec_bcfg_hash_len Length of the security boardcfg hash
 * \param sec_bcfg_iv pointer to security boardcfg iv
 * \param sec_bcfg_iv_len Length of the security boardcfg iv
 * \param sec_bcfg_rs pointer to security boardcfg rs
 * \param sec_bcfg_rs_len Length of the security boardcfg rs
 * \param pm_bcfg_hash pointer to pm boardcfg hash
 * \param pm_bcfg_hash_len Length of the pm boardcfg hash
 * \param rm_bcfg_hash pointer to rm boardcfg hash
 * \param rm_bcfg_hash_len Length of the rm boardcfg hash
 * \param core_bcfg_hash pointer to core boardcfg hash
 * \param core_bcfg_hash_len Length of the core boardcfg hash
 * \param sec_bcfg_ver security boardcfg version for roll back protection
 * \param sec_bcfg_num_iter Number of iterations for the KDF
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_receive_bcfg_hashes(const u8 *sec_bcfg_hash, u32 sec_bcfg_hash_len, const u8 *sec_bcfg_iv, u32 sec_bcfg_iv_len, const u8 *sec_bcfg_rs, u32 sec_bcfg_rs_len, const u8 *pm_bcfg_hash,
				 u32 pm_bcfg_hash_len, const u8 *rm_bcfg_hash, u32 rm_bcfg_hash_len, const u8 *core_bcfg_hash, u32 core_bcfg_hash_len, u8 sec_bcfg_ver,
				 u8 sec_bcfg_num_iter);

/**
 * \brief return the attributes for the specified otp mmr from board configuration
 *
 * \param mmr_idx Index of the MMR
 * \param owner   on return, contains the host id of the owner of this MMR
 * \param attr    on return, contains the attributes of this MMR
 *
 * \return Error code on failure, SUCCESS otherwise.
 *
 */
s32 boardcfg_sec_get_otp_mmr_attr(u8 mmr_idx, u8 *owner, u8 *attr);

/**
 * \brief check if the host has write permission to extended OTP area
 *
 * \param host Host ID of the sender
 *
 * \return STRUE if host has write permissions, SFALSE if board configuration
 * has not been received or if the host does not have write permissions
 */
sbool boardcfg_sec_is_write_host(u8 host);

/**
 * \brief check if the host can use DKEK
 *
 * \param host Host ID of the sender
 *
 * \return STRUE if host can use DKEK, SFALSE if board configuration
 * has not been received or if the host does not have permission
 */
sbool boardcfg_sec_is_dkek_accessible(u8 host);

/**
 * \brief Check if the host may access SA2UL authentication resources owned by
 *        SYSFW
 *
 * \param host Host ID of the host allowed to request acquire/release of the
 *             resources
 *
 * \return STRUE if host has permissions to make acquire/release request, SFALSE
 *         if board configuration has not been received or if the host does not
 *         have the access permissions.
 */
sbool boardcfg_sec_sa2ul_auth_res_accessible(u8 host);

/**
 * \brief Process a boardcfg structure placed at a specific address
 *
 * \param host Host ID of the sender
 * \param boardcfgp_low Low 32-bit of boardcfg struct address.
 * \param boardcfgp_high High 32-bit of boardcfg struct address.
 * \param boardcfg_size Size of the full boardcfg struct.
 * \param boardcfg_devgrp Device group for this boardcfg configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_process(u8 host, u32 boardcfgp_low, u32 boardcfgp_high, u16 boardcfg_size, devgrp_t boardcfg_devgrp);

/**
 * \brief Process a boardcfg security structure placed at a specific address
 *
 * \param host Host ID of the sender
 * \param boardcfg_securityp_low Low 32-bit of boardcfg security struct address.
 * \param boardcfg_securityp_high High 32-bit of boardcfg security struct address.
 * \param boardcfg_security_size Size of the full boardcfg security struct.
 * \param boardcfg_security_devgrp Device group for the Security configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_sec_process(u8 host, u32 boardcfg_securityp_low, u32 boardcfg_securityp_high, u16 boardcfg_security_size, devgrp_t boardcfg_security_devgrp);

/**
 * \brief Process a boardcfg power management structure placed at a
 *        specific address
 *
 * \param host Host ID of the sender
 * \param boardcfg_pmp_low Low 32-bit of boardcfg pm struct address.
 * \param boardcfg_pmp_high High 32-bit of boardcfg pm struct address.
 * \param boardcfg_pm_size Size of the full boardcfg pm struct.
 * \param boardcfg_pm_devgrp Device group for the PM configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_pm_process(u8 host, u32 boardcfg_pmp_low, u32 boardcfg_pmp_high, u16 boardcfg_pm_size, devgrp_t boardcfg_pm_devgrp);

/**
 * \brief Process a boardcfg structure placed at a specific address,
 *        omitting pll and trace
 *
 * \param boardcfg_devgrp Device group for this boardcfg configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_process_common(devgrp_t boardcfg_devgrp);

/**
 * \brief Process a boardcfg resource management structure placed at a
 *        specific address
 *
 * \param host Host ID of the sender
 * \param boardcfg_rmp_low Low 32-bit of boardcfg rm struct address.
 * \param boardcfg_rmp_high High 32-bit of boardcfg rm struct address.
 * \param boardcfg_rm_size Size of the full boardcfg rm struct.
 * \param boardcfg_rm_devgrp Device group for the RM configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_rm_process(u8 host, u32 boardcfg_rmp_low, u32 boardcfg_rmp_high, u16 boardcfg_rm_size, devgrp_t boardcfg_rm_devgrp);

/**
 * \brief Trigger automatic boardcfg processing using the given handler
 *
 * \param type Type of boardcfg
 * \param fxn Handler function for processing the boardcfg type
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_auto(u16 type, boardcfg_process_fxn fxn);

/**
 * \brief Trigger automatic boardcfg processing using the given handler
 *
 * \param type Type of boardcfg
 * \param fxn Handler function for processing the boardcfg type
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_user_auto(u16 type, boardcfg_process_fxn fxn);
/**
 * \brief check if JTAG can be unlocked at runtime using a signed certificate
 *
 * \return STRUE if jtag unlock is allowed, SFALSE if it is not.
 */
sbool boardcfg_sec_is_jtag_unlock_allowed(void);

/**
 * \brief check if the certificate revision in the jtag unlock certificate is
 *        above the specified minimum. This is used for anti rollback protection.
 *
 * \param swrv Revision specified in the certificate.
 *
 * \return STRUE if swrv is above the specified minimum, SFALSE otherwise.
 */
sbool boardcfg_sec_check_jtag_unlock_cert_rev(u32 swrv);

/**
 * \brief check if the specified host can do jtag unlock with a certificate
 *
 * \param host_id ID of host sending the jtag unlock command
 *
 * \return STRUE if the host can unlock jtag with a certificate, SFALSE otherwise.
 */
sbool boardcfg_sec_check_jtag_unlock_host(u8 host_id);

/**
 * \brief check if JTAG can be unlocked at runtime using a wildcard signed certificate
 *
 * \return STRUE if wildcard jtag unlock is allowed, SFALSE if it is not.
 */
sbool boardcfg_sec_is_wildcard_jtag_unlock_allowed(void);

/**
 * \brief Get the security device group from the local boardcfg_security data.
 *
 * \param devgrp Pointer to a device group variable in which the device group
 *        is returned on SUCCESS
 *
 * \return EINIT if the local security board data has not yet been received or is
 *         invalid, SUCCESS if in the board data has been received and is valid.
 */
s32 boardcfg_get_sec_devgrp(devgrp_t *devgrp);

/**
 * \brief Trigger automatic boardcfg processing using the given handler
 *
 * \param msg_sender ID of the host sending the handover message
 * \param new_owner ID of the host receiving the security handover
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_sec_get_handover_hosts(u8 *msg_sender, u8 *new_owner);

/**
 * \brief Check to see if the flag for SAUL PSIL global config writes is enabled
 *
 * \return STRUE if it's enabled, or SFALSE if disabled
 */
sbool boardcfg_sec_is_saul_psil_global_config_writes_enabled(void);

/**
 * \brief Set the security device group from the local boardcfg_security data.
 *
 * \param devgrp Device group variable
 *
 * \return EINIT when the devgrp is not set
 *         SUCCESS if the devgrp is set
 */
s32 boardcfg_set_sec_devgrp(devgrp_t boardcfg_security_devgrp);

#ifdef CONFIG_SECURE_RM_DM_SUPPORT
/**
 * \brief Get the size of the local copy of the boardcfg_rm_resasg_entry data.
 *
 * \return Zero if the local Secure RM board data has not yet been received or is
 *         invalid, greater than zero otherwise.
 */
u16 boardcfg_get_sec_rm_resasg_size(void);

/**
 * \brief Get a pointer to the local copy of the boardcfg_rm_resasg data.
 *
 * \return NULL if the local Secure RM board data has not yet been received or is
 *         invalid, pointer otherwise.
 */
const struct boardcfg_rm_resasg_entry *boardcfg_get_sec_rm_resasg(void);

/**
 * \brief Receive a boardcfg resource management structure placed at an
 *        external address and validate
 *
 * \param host Host ID of the sender
 * \param boardcfg_rmp_low Low 32-bit of boardcfg rm struct address.
 * \param boardcfg_rmp_high High 32-bit of boardcfg rm struct address.
 * \param boardcfg_rm_size Size of the full boardcfg rm struct.
 * \param boardcfg_rm_devgrp Device group for the RM configuration.
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 boardcfg_sec_rm_process(u8 host, u32 boardcfg_rmp_low, u32 boardcfg_rmp_high, u16 boardcfg_rm_size, devgrp_t boardcfg_rm_devgrp);
#endif

#ifdef CONFIG_DEVICE_TYPE_HS
/**
 * \brief Check the SW revision against the dmsc_fw_cfgrev efuse value
 *
 * \param swrev Software revision found in the certificate binary
 */
s32 boardcfg_check_swrev(u8 swrev);
#else
static inline s32 boardcfg_check_swrev(u8 swrev __attribute__((unused)))
{
	return EFTOK;
}
#endif
#endif /* BOARD_CFG_API_H */
