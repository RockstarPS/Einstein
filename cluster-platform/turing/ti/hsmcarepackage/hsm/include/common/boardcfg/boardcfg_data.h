/*
 * System Firmware Source File
 *
 * Board Configuration Data Structures
 *
 * Copyright (C) 2018-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef BOARD_CFG_H
#define BOARD_CFG_H

#include <lib/bitops.h>
#include <types/ftbool.h>
#include <types/short_types.h>
#include <boardcfg/boardcfg_macros.h>

#include <hosts.h>

#define BOARDCFG_ABI_MAJ_VALUE                  0x00
#define BOARDCFG_ABI_MIN_VALUE                  0x01

#define BOARDCFG_SEC_ABI_MAJ_VALUE               0x00
#define BOARDCFG_SEC_ABI_MIN_VALUE               0x01

/**
 * \brief Contains a unique magic number for each substructure and the size
 *	  of the associated superstructure for data validation/API
 *	  compatibility checks.
 *
 * \param magic Unique magic number for data integrity check.
 * \param size `sizeof(superstructure containing this header)` for data
 *	       integrity check.
 */
struct boardcfg_substructure_header {
	u16	magic;
	u16	size;
} __attribute__((__packed__));

/**
 * \brief Board Config data ABI version.
 *
 * \param boardcfg_abi_maj Major Board Config data ABI version.
 * \param boardcfg_abi_min Minor Board Config data ABI version.
 */
struct boardcfg_abi_rev {
	u8	boardcfg_abi_maj;
	u8	boardcfg_abi_min;
} __attribute__((__packed__));

/**
 * \brief Used to enable/disable features in DMSC based on usecase.
 *
 * \param subhdr Magic and size for integrity check.
 * \param main_isolation_enable Enable/disable support for DMSC main
 *                              isolation. If disabled, main isolation
 *                              SCI message will be rejected with NAK.
 * \param main_isolation_hostid	Host-ID allowed to send SCI-message for
 *                              main isolation. If mismatch, SCI message
 *                              will be rejected with NAK.
 */
struct boardcfg_control {
	struct boardcfg_substructure_header	subhdr;
	ftbool					main_isolation_enable;
	u16					main_isolation_hostid;
} __attribute__((__packed__));

/**
 * \brief Secure proxy configuration.
 *
 * \param subhdr Magic and size for integrity check.
 * \param scaling_factor Memory allocation for messages scaling factor. In
 *			 current design, only value of "1" is supported. For
 *			 future design, a value of "2" would double all memory
 *			 allocations and credits, "3" would triple, and so on.
 * \param scaling_profile Memory allocation for messages profile number. In
 *			  current design, only a value of "1" is supported.
 *			  "0" is always invalid due to fault tolerance.
 * \param disable_main_nav_secure_proxy Do not configure main nav secure proxy.
 *					This removes all MSMC memory demands
 *					from DMSC but limits MPU channels to
 *					one set of secure and one set of
 *					insecure. Note this parameter is currently
 *					not used. Hence the value of '0' is used.
 */
struct boardcfg_secproxy {
	struct boardcfg_substructure_header	subhdr;
	u8					scaling_factor;
	u8					scaling_profile;
	u8					disable_main_nav_secure_proxy;
} __attribute__((__packed__));

/**
 * \brief Cache configuration so that MSMC can be used for main secure proxy
 *	  backing memory and ring memory.
 *
 * \param subhdr Magic and size for integrity check.
 * \param msmc_cache_size Fraction of msmc to be cache in /32 units. Rounds
 *			  up. Since current msmc support /8 allocation this
 *			  means that 1/32 rounds up to 1/8.
 */
struct boardcfg_msmc {
	struct boardcfg_substructure_header	subhdr;
	u8					msmc_cache_size;
} __attribute__((__packed__));

/* \brief How many masters that are permitted in proc acl for access */
#define PROCESSOR_ACL_SECONDARY_MASTERS_MAX (3U)

/**
 * \brief A single entry of Processor Access Control List
 *
 * \param processor_id - What processor ID are we restricting control over?
 * \param proc_access_master - Who is the master who can override control
 * \param proc_access_secondary - list of upto @ref PROCESSOR_ACL_SECONDARY_MASTERS_MAX
 */
struct boardcfg_proc_acl_entry {
	u8	processor_id;
	u8	proc_access_master;
	u8	proc_access_secondary[PROCESSOR_ACL_SECONDARY_MASTERS_MAX];
} __attribute__((__packed__));

/* \brief How many access control list entries for processors */
#define PROCESSOR_ACL_ENTRIES (32U)

/**
 * \brief Control list for which hosts can control which processors
 * \param subhdr - Magic and size for integrity check
 * \param proc_acl_entries - @ref boardcfg_proc_acl_entry entries upto @ref PROCESSOR_ACL_ENTRIES entries
 */
struct boardcfg_proc_acl {
	struct boardcfg_substructure_header	subhdr;
	struct boardcfg_proc_acl_entry		proc_acl_entries[
		PROCESSOR_ACL_ENTRIES];
} __attribute__((__packed__));

/**
 * \brief A single entry of Host hierarchy List
 *
 * \param host_id - Processing entity Host ID whose supervisor is specified
 * \param supervisor_host_id - Processing entity Host ID that is the supervisor
 *                             of the host_id
 */
struct boardcfg_host_hierarchy_entry {
	u8	host_id;
	u8	supervisor_host_id;
} __attribute__((__packed__));

/** \brief How many host hierarchy list entries for hosts */
#define HOST_HIERARCHY_ENTRIES (32U)

/**
 * \brief List of SoC hosts and their supervising hosts
 * \param subhdr - Magic and size for integrity check
 * \param host_hierarchy_entries - @ref boardcfg_host_hierarchy_entry entries
 *                                 upto @ref HOST_HIERARCHY_ENTRIES entries
 */
struct boardcfg_host_hierarchy {
	struct boardcfg_substructure_header	subhdr;
	struct boardcfg_host_hierarchy_entry	host_hierarchy_entries[HOST_HIERARCHY_ENTRIES];
} __attribute__((__packed__));

/**
 * \brief access configuration for one OTP MMR. Each MMR is 32 bit wide.
 *
 * \param host_id Id of the host owning the MMR
 *
 * \param host_perms 2 bit wide fields specifying permissions
 *                   bit 1:0 - 10b - non-secure, any other value secure
 *                   bit 7:2 - Reserved for future use
 */
struct boardcfg_extended_otp_entry {
	u8	host_id;
	u8	host_perms;
} __attribute__((__packed__));

/**
 * \brief Maximum number of OTP rows allowed by design
 */
#define MAX_NUM_EXT_OTP_MMRS (32U)

/**
 * \brief Access configuration for each OTP row
 * \param subhdr Magic and size for integrity check
 * \param otp_entry access configurations for each OTP MMR
 * \param write_host_id ID of the host allowed to perform OTP write/lock operations.
 */
struct boardcfg_extended_otp {
	struct boardcfg_substructure_header	subhdr;
	struct boardcfg_extended_otp_entry	otp_entry[MAX_NUM_EXT_OTP_MMRS];
	u8					write_host_id;
} __attribute__((__packed__));


#define MAX_NUM_DKEK_ALLOWED_HOSTS (4U)

/**
 * \brief Access configuration for DKEK
 * \param subhdr Magic and size for integrity check
 * \param allowed_hosts ID's of hosts allowed to use DKEK. Use HOST_ID_ALL if any host is allowed
 * \param allow_dkek_export_tisci If DKEK can be exported via TISCI interface to hosts. Set to 0x5A to allow.
 * \param rsvd Reserved field for future use. Set to 0.
 */
struct boardcfg_dkek {
	struct boardcfg_substructure_header	subhdr;
	u8					allowed_hosts[MAX_NUM_DKEK_ALLOWED_HOSTS];
	u8					allow_dkek_export_tisci;
	u8					rsvd[3];
} __attribute__((__packed__));

/**
 * \brief Configuration of SA2UL resources
 *
 * \param subhdr Magic and size for integrity check
 * \param auth_resource_owner ID of the host allowed to acquire/release the
 *                            authentication resources
 * \param enable_saul_psil_global_config_writes Flag for allowing pairing requests
 *                                              from PSIL. Set to 0x5A to enable
 * \param rsvd Reserved
 */
struct boardcfg_sa2ul_cfg {
	struct boardcfg_substructure_header	subhdr;
	u8					auth_resource_owner;
	ftbool					enable_saul_psil_global_config_writes;
	u8					rsvd[2];
};


/**
 * \brief Secure debug control
 *
 * \param subhdr Magic and size for integrity check
 *
 * \param allow_jtag_unlock Flag controlling runtime jtag unlock feature. Set to
 *                          0x5A to enable jtag unlock with a signed certificate.
 *
 * \param allow_wildcard_unlock Flag controlling whether a device unique
 *                              certificate is required for jtag unlock. Set to 0x5A to remove the device
 *                              uniqueness restriction on the certificate.
 *
 * \param allowed_debug_level_rsvd Reserved field to control the allowed debug level in
 *                                 future. Set to 0 currently.
 *
 *  \param rsvd reserved for future use.
 *
 * \param min_cert_rev Minimum SWREV value that must be present in the jtag
 *                     unlock certificate. Set to 0 to skip check
 *
 * \param jtag_unlock_hosts array of host ids that are allowed to unlock jtag
 *                          with a signed certificate at runtime. Set host id to 0 if unused. Set host id
 *                          to 128 if any host can unlock JTAG via the API.
 */
struct boardcfg_secure_debug_config {
	struct boardcfg_substructure_header	subhdr;
	u8					allow_jtag_unlock;
	u8					allow_wildcard_unlock;
	u8					allowed_debug_level_rsvd;
	u8					rsvd;
	u32					min_cert_rev;
	u8					jtag_unlock_hosts[BOARDCFG_SEC_MAX_NUM_JTAG_UNLOCK_HOSTS];
} __attribute__((__packed__));

/**
 * \brief Configuration of security handover
 *
 * Only applicable to certain devices
 *
 * \param subhdr Magic and size for integrity check
 * \param handover_msg_sender Host which will send the security handover message
 * \param handover_to_host_id Host to which security functionality is handed over
 * \param rsvd Reserved
 */
struct boardcfg_sec_handover {
	struct boardcfg_substructure_header	subhdr;
	u8					handover_msg_sender;
	u8					handover_to_host_id;
	u8					rsvd[4];
};

/**
 * \brief Format of the complete board configuration.
 *
 * \param boardcfg_abi_rev Secure Board Config ABI version (separate from DMSC ABI version)
 * \param boardcfg_proc_acl Processor Access control list
 * \param boardcfg_host_hierarchy Host hierarchy list
 * \param otp_config  OTP Configuration
 * \param dkek_config  DKEK Configuration
 * \param sec_dbg_config  Secure JTAG Unlock Configuration
 * \param boardcfg_sa2ul_cfg SA2UL resource configuration
 * \param sec_handover_cfg Security handover configuration
 */
struct boardcfg_sec {
	struct boardcfg_abi_rev			rev;
	struct boardcfg_proc_acl		processor_acl_list;
	struct boardcfg_host_hierarchy		host_hierarchy;
	struct boardcfg_extended_otp		otp_config;
	struct boardcfg_dkek			dkek_config;
	struct boardcfg_sa2ul_cfg		sa2ul_auth_cfg;
	struct boardcfg_secure_debug_config	sec_dbg_config;
	struct boardcfg_sec_handover		sec_handover_cfg;
} __attribute__((__packed__));

/**
 * \def BOARDCFG_TRACE_DST_UART0
 * Traces to UART0 in wakeupss enabled.
 *
 * \def BOARDCFG_TRACE_DST_ITM
 * Traces to UART attached to ITM(JTAG) enabled.
 *
 * \def BOARDCFG_TRACE_DST_MEM
 * Traces to memory buffer enabled.
 */
#define BOARDCFG_TRACE_DST_UART0                BIT(0)
#define BOARDCFG_TRACE_DST_ITM                  BIT(2)
#define BOARDCFG_TRACE_DST_MEM                  BIT(3)

/**
 * \def BOARDCFG_TRACE_SRC_PM
 * Traces from power management are allowed.
 *
 * \def BOARDCFG_TRACE_SRC_RM
 * Traces from resource management are allowed.
 *
 * \def BOARDCFG_TRACE_SRC_SEC
 * Traces from security management are allowed.
 *
 * \def BOARDCFG_TRACE_SRC_BASE
 * Traces from baseport are allowed.
 *
 * \def BOARDCFG_TRACE_SRC_USER
 * Traces from user tasks are allowed.
 *
 * \def BOARDCFG_TRACE_SRC_SUPR
 * Traces from supervisor tasks are allowed.
 */
#define BOARDCFG_TRACE_SRC_PM                   BIT(0)
#define BOARDCFG_TRACE_SRC_RM                   BIT(1)
#define BOARDCFG_TRACE_SRC_SEC                  BIT(2)
#define BOARDCFG_TRACE_SRC_BASE                 BIT(3)
#define BOARDCFG_TRACE_SRC_USER                 BIT(4)
#define BOARDCFG_TRACE_SRC_SUPR                 BIT(5)

/**
 * \brief Debug console configuration.
 *
 * \param subhdr Magic and size for integrity check.
 * \param trace_dst_enables;
 * \param trace_src_enables;
 */
struct boardcfg_dbg_cfg {
	struct boardcfg_substructure_header	subhdr;
	u16					trace_dst_enables;
	u16					trace_src_enables;
} __attribute__((__packed__));

/**
 * \brief Format of the complete board configuration.
 *
 * \param boardcfg_abi_rev Board Config ABI version (separate from DMSC ABI version)
 * \param control DMSC feature control selections
 * \param secproxy Secure proxy configuration
 * \param msmc MSMC configuration
 * \param debug_cfg Debug/trace configuration
 */
struct boardcfg {
	struct boardcfg_abi_rev		rev;
	struct boardcfg_control		control;
	struct boardcfg_secproxy	secproxy;
	struct boardcfg_msmc		msmc;
	struct boardcfg_dbg_cfg		debug_cfg;
} __attribute__((__packed__));


/**
 * \brief structure to hold the board configuration hashes received via X509 certificate
 *
 * \param sec_bcfg_hash Hash of encrypted security board configuration blob
 * \param rm_bcfg_hash Hash of RM board configuration blob
 * \param pm_bcfg_hash Hash of PM board configuration blob
 * \param core_bcfg_hash Hash of main board configuration blob
 * \param sec_bcfg_iv initial vector used during security board configuration encryption
 * \param sec_bcfg_rs byte string used to verify that security board configuration is
 *                    decrypted correctly.
 * \param sec_bcfg_ver version of the security board configuration
 * \param sec_bcfg_num_iter Number of iterations for the KDF
 * \param hashes_received Flag indicating whether SYSFW outer certificate contained boardcfg
 *                        information
 */
struct boardcfg_hashes_data {
	u8	sec_bcfg_hash[BOARDCFG_HASH_LEN_BYTES];
	u8	rm_bcfg_hash[BOARDCFG_HASH_LEN_BYTES];
	u8	pm_bcfg_hash[BOARDCFG_HASH_LEN_BYTES];
	u8	core_bcfg_hash[BOARDCFG_HASH_LEN_BYTES];
	u8	sec_bcfg_iv[BOARDCFG_SEC_IV_LEN];
	u8	sec_bcfg_rs[BOARDCFG_SEC_RS_LEN];
	u8	sec_bcfg_ver;
	u8	sec_bcfg_num_iter;
	ftbool	hashes_received;
};
#endif          /* BOARD_CFG_H */
