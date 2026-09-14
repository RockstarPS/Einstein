/*
 * Copyright (C) 2017-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file asn1_parse.h
 *
 * \brief  ASN1 DER parser for X.509 certificates and other encoded structures
 *
 */
#ifndef ASN1_PARSE_H_
#define ASN1_PARSE_H_

#include <config.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <types/ftbool.h>
#include <types/fterr.h>
#include <crypto_types.h>

/**
 * Maximum size of a encoded input byte array for the parser.
 */
#ifdef CONFIG_KEY_WRITER
#define ASN1P_IMAX            (CONFIG_KEY_WRITER_MAX_CERT_LEN)
#else
#define ASN1P_IMAX            (4096U)
#endif
/**
 * This macro defines the maximum number of CPU cores
 * we expect to encounter in any device of the KS3 family.
 */
#define ASN1P_MAX_CORES (32U)

/* Number of X509 extensions supported by the ASN1 parser */
#ifdef CONFIG_KEY_WRITER
#define NUM_EXT_OIDS                    25
#else
#define NUM_EXT_OIDS                    9
#endif

/* This has nothing to do with ASN1P in general. We are placing this macro
 * here as it will always be used in conjunction with X509 certificates.
 */
/** Length of a SHA2-512 hash in bytes */
#define ASN1P_SHA512_HASH_LEN (64U)

/**
 * Maximum nested level supported by the parser
 */
#define ASN1P_STACK_DEPTH     16UL

/* Enable firewall configuration when parsing */
#define SEC_BOOT_FIREWALL_CONFIGURE 1U
/* Disable firewall configuration when parsing */
#define SEC_BOOT_FIREWALL_SKIP_CONFIG 0U

/* check NUM_EXT_OIDS */
enum EXT_OID_TYPES {
	EXT_SYSFW_BOOT = 0u,
	EXT_SYSFW_IMAGE_INTEG = 1U,
	EXT_SWRV = 2U,
	EXT_ENCRYPTION = 3U,
	/* Extensions are numbered starting with 1 */
	EXT_SYSFW_LOAD = 4U,
	EXT_SYSFW_SEC_BCFG = 5U,
	EXT_RSVD7 = 6U,
	EXT_SYSFW_DEBUG = 7U,
#ifdef CONFIG_KEY_WRITER
	/* Keywriter Extensions */
	EXT_KEYWR_ENC_AES                       = 8U,
	EXT_KEYWR_ENC_SMPK_SIGN_AES             = 9U,
	EXT_KEYWR_ENC_BMPK_SIGN_AES             = 10U,
	EXT_KEYWR_AES_ENC_SMPKH                 = 11U,
	EXT_KEYWR_AES_ENC_SMEK                  = 12U,
	EXT_KEYWR_AES_ENC_SMPK_OPT              = 13U,
	EXT_KEYWR_AES_ENC_BMPKH                 = 14U,
	EXT_KEYWR_AES_ENC_BMEK                  = 15U,
	EXT_KEYWR_AES_ENC_BMPK_OPT              = 16U,
	EXT_KEYWR_AES_ENC_EXT_OTP               = 17U,
	EXT_KEYWR_PLAIN_MSV                     = 18U,
	EXT_KEYWR_PLAIN_KEY_REV                 = 19U,
	EXT_KEYWR_PLAIN_KEY_CNT                 = 20U,
	EXT_KEYWR_PLAIN_SWREV_SYSFW             = 21U,
	EXT_KEYWR_PLAIN_SWREV_SBL               = 22U,
	EXT_KEYWR_PLAIN_SWREV_SEC_BRDCFG        = 23U,
	EXT_KEYWR_PLAIN_KEYWR_MIN_VER           = 24U,
#else
	EXT_FIREWALL_CONF                       = 8U
#endif
};

/**
 * \brief ASN1 parser field, basically a pointer into the parsed input data
 *
 * \param offset Offset in the input data array where the field is found
 * \param size Size of the field in bytes
 */
struct asn1p_field {
	u32	offset;
	u32	size;
};

/** Current supported version of boot options */
#define TI_BOOT_OPTS_VER (1U)

/**
 * \brief Structure to capture core specific options information.
 *
 * These options are not interpreted by the ASN1 parser.
 *
 * \param flags_set indicates flags to be set when booting a core
 *
 * \param flags_clr indicates flags to be cleared when booting a core
 */
struct ti_boot_core_opts {
	u32	flags_set;
	u32	flags_clr;
};

/**
 * \brief Boot image authentication information
 *
 * Information extracted from TI defined X.509 custom extensions.
 *
 * \param core Core that runs the loaded image
 * \param core_opts Core options field
 * \param reset_vector Reset vector address
 */
struct ti_boot_info {
	u32				core;
	struct ti_boot_core_opts	core_opts;
	soc_phys_addr_t			reset_vector;
};

/**
 * \brief image load information
 *
 * Information extracted from TI defined X.509 custom extensions.
 *
 * \param dest_addr Boot image destination address
 * \param auth_in_place Field indicating the type of authentication to perform
 * \param copy_as_host Field indicating the host id of the core which has to execute the binary
 */
struct ti_load_info {
	soc_phys_addr_t dest_addr;
	u8		auth_in_place;
	u8		copy_as_host;
};

/**
 * \brief Image integrity information
 *
 * Information extracted from TI defined X.509 custom extensions.
 *
 * \param image_size Size of the image in bytes
 * \param hash_algo Hash algorithm used for boot image integrity
 * \param hash_val Hash value of the boot image
 *
 */
struct ti_integ_info {
	u32			image_size;
	u8			hash_algo;
	struct asn1p_field	hash_val;
};

/**
 * Boot image encryption information
 *
 * \param initial_vector initial vector for encryption
 *
 * \param random_string  random string for image encryption
 *
 * \param iteration_cnt iteration count for key derivation.
 *                      0 indicates no key derivation.
 *
 * \param salt          Salt value for key derivation
 */
struct ti_enc_info {
	struct asn1p_field	initial_vector;
	struct asn1p_field	random_string;
	u32			iteration_cnt;
	struct asn1p_field	salt;
};

/**
 * Boardcfg data and encryption information
 *
 * \param initial_vector initial vector for encryption
 *
 * \param random_string  random string for image encryption
 *
 * \param iteration_cnt iteration count for key derivation.
 *                      0 indicates no key derivation.
 *
 * \param salt          Salt value for key derivation
 * \param sec_bcfg_hash Hash of the encrypted security board config
 *
 * \param sec_bcfg_ver Version of the security board configuration. This is
 * compared against the board configuration values in efuses.
 *
 * \param pm_bcfg_hash Hash of the PM board config
 * \param rm_bcfg_hash Hash of the RM board config
 * \param core_bcfg_hash Hash of the core/first board config
 */
struct ti_bcfg_info {
	struct asn1p_field	initial_vector;
	struct asn1p_field	random_string;
	u32			iteration_cnt;
	struct asn1p_field	salt;
	struct asn1p_field	sec_bcfg_hash;
	u32			sec_bcfg_ver;
	struct asn1p_field	pm_bcfg_hash;
	struct asn1p_field	rm_bcfg_hash;
	struct asn1p_field	core_bcfg_hash;
};
/**
 * information to open the debug port on secure devices
 *
 * \param uid unique identifer for the device. This is checked against the UID
 *            calculated by a specific algorithm to ensure that a single certificate
 *            can only open the debug port on one device.
 *
 * \param debug_priv_key_flags Compound field with debug privilege and key hiding flags.
 *                             debug privilige level is in the lower 16 bits.
 *                             key hiding flags are in the upper 16 bits.
 *
 * \param debug_core_sel the set of cores to be configured for non-secure debug.
 *                       The first index indicates the number of cores.
 *
 * \param sec_debug_core_sel the set of cores to be configured for secure debug.
 *                           The first index indicates the number of cores.
 *
 *
 */
struct ti_debug_ctrl {
	struct asn1p_field	uid;
	u32			debug_priv_key_flags;
	u32			debug_core_sel[BIGINT_LEN(ASN1P_MAX_CORES)];
	u32			sec_debug_core_sel[BIGINT_LEN(ASN1P_MAX_CORES)];
};

#ifdef CONFIG_KEY_WRITER
/**
 * Keywriter specific x509 extension structures
 *
 * \param val asn1p_field (index, and size) of the certificate section, which has
 *                        value of the encrypted extension field.
 * \param size size in bytes
 */
struct keywr_enc_field {
	struct asn1p_field	val;
	u32			size;
};

/**
 * Keywriter specific x509 extension strucutures
 *
 * \param val asn1p_field (index, and size) of the certificate section, which has
 *                        value of the encrypted extension field.
 * \param iv  Initial Value used for AES encryption
 * \param rs  Random String used for AES encryption
 * \param size size in bytes
 * \param action_flags Flags for WP-RP-OVRD-ACTIVE status information
 */
struct keywr_aes_enc_field {
	struct asn1p_field	val;
	struct asn1p_field	iv;
	struct asn1p_field	rs;
	u32			size;
	u32			action_flags;
};

struct keywr_plain_field {
	struct asn1p_field	val;
	u32			action_flags;
};

struct keywr_aes_enc_ext_otp_field {
	struct asn1p_field	val;
	struct asn1p_field	iv;
	struct asn1p_field	rs;
	struct asn1p_field	wprp;
	u32			index;
	u32			size;
	u32			action_flags;
};

#endif

/**
 * \brief ASN.1 parser stack
 *
 * \param len Length of a asn1 nested element under this tag
 * \param pos Offset to the first data byte of the asn1 element
 *            pos+len takes us to end of this tag.
 */
struct asn1p_stack {
	u32	len;
	u32	pos;
};

/**
 * \brief State of the ASN.1 DER parser
 *
 * The current state of the depth-first ASN1 DER bytestream parser using
 * a stack data strucure.
 *
 * \param cur_pos Current position in the stream while parsing
 * \param sp Stack pointer (current depth)
 * \param stack Parser stack
 */
struct asn1p_ctx {
	u32			cur_pos;
	u32			sp;
	struct asn1p_stack	stack[ASN1P_STACK_DEPTH];
};

#ifndef CONFIG_KEY_WRITER
/**
 * \brief Firewall configuration information
 *
 * \param req_host Host requesting the operation
 * \param flag Certificate is validated or not
 * \param ctx Parsing context at the point of
 *                              firewall parsing
 */
struct ti_fwl_config {
	u8			req_host;
	u8			flag;
	struct asn1p_ctx	ctx;
};
#endif 

/**
 * \brief Parsed X.509 certificate output from ASN.1 parser
 *
 * \param tbs To-Be-Signed part of the certificate the part which is covered by
 *            the signature
 * \param subject Subject field of the certificate
 * \param issuer Issuer field of the certificate
 * \param pubkey_der pubkey field of the certificate. This is in DER form.
 * \param sig_type Signature algorithm used by the certificate
 * \param pubkey_type Public key type
 * \param pubkey Public key parsed and imported from the certificate
 * \param sig Signature parsed and imported from the certificate
 * \param ec_curve_type EC curve type (if pubkey_type is EC)
 * \param ec_params EC curve parameter (if pubkey_type is EC & ec_curve_type is
 *                  explicit)
 * \param binfo Boot image information
 * \param enc_info Boot image encryption information
 * \param dbg_info information to configure debug access on secure devices
 * \param length length of the certificate. This is useful when payload is appended
 *               to certificate.
 * \param img_final_loc Final location of a boot image after authentication/decryption.
 * \param swrv Software revision value
 * \param keywr_enc_aes_info	TIFEK public encrypted random AES 256 key
 * \param keywr_enc_smpk_sign_aes_info	TIFEK public encrypted SMPK signed AES key
 * \param keywr_enc_bmpk_sign_aes_info	TIFEK public encrypted BMPK signed AES key
 * \param keywr_aes_enc_smpkh_info	AES key encrypted SMPKH
 * \param keywr_aes_enc_smek_info	AES key encrypted SMEK
 * \param keywr_plain_mpk_opt_info	AES key encrypted SMPK Options
 * \param keywr_aes_enc_bmpkh_info	AES key encrypted BMPKH
 * \param keywr_aes_enc_bmek_info	AES key encrypted BMEK
 * \param keywr_plain_mek_opt_info	AES key encrypted BMPK Options
 * \param keywr_aes_enc_ext_otp_info	AES key encryped extended OTP
 */
struct x509_cert {
	struct asn1p_field	tbs;
	struct asn1p_field	subject;
	struct asn1p_field	issuer;
	struct asn1p_field	pubkey_der;
	s32			sig_type;
	s32			pubkey_type;
	union {
		struct rsa_pubkey	rsa;
		struct ec_point		ec;
	} pubkey;
	union {
		u32			rsa[BIGINT_LEN(RSA_SIG_MAXLEN)];
		struct ecdsa_sig	ecdsa;
	} sig;
	s32					ec_curve_type;

	struct ec_prime_curve_p			ec_params;
	struct ti_boot_info			binfo;
	struct ti_load_info			load_info;
	struct ti_integ_info			integ_info;
	struct ti_enc_info			enc_info;
	struct ti_debug_ctrl			dbg_info;
	u32					length;
	fterr					ext_parsed[NUM_EXT_OIDS];
	soc_phys_addr_t				img_final_loc;
	struct ti_bcfg_info			sec_bcfg;
	u32					swrv;
#ifndef CONFIG_KEY_WRITER
	struct ti_fwl_config			fwl_cfg;
#else
	struct keywr_enc_field			keywr_enc_aes_info;
	struct keywr_enc_field			keywr_enc_smpk_sign_aes_info;
	struct keywr_enc_field			keywr_enc_bmpk_sign_aes_info;
	struct keywr_aes_enc_field		keywr_aes_enc_smpkh_info;
	struct keywr_aes_enc_field		keywr_aes_enc_smek_info;
	struct keywr_aes_enc_field		keywr_aes_enc_bmpkh_info;
	struct keywr_aes_enc_field		keywr_aes_enc_bmek_info;
	struct keywr_aes_enc_ext_otp_field	keywr_aes_enc_ext_otp_info;
	struct keywr_plain_field		keywr_plain_msv_info;
	struct keywr_plain_field		keywr_plain_key_rev_info;
	struct keywr_plain_field		keywr_plain_key_cnt_info;
	struct keywr_plain_field		keywr_plain_swrev_sysfw_info;
	struct keywr_plain_field		keywr_plain_swrev_sbl_info;
	struct keywr_plain_field		keywr_plain_swrev_sec_brdcfg_info;
	struct keywr_plain_field		keywr_plain_keywr_min_ver_info;
	struct keywr_plain_field		keywr_plain_mpk_opt_info;
	struct keywr_plain_field		keywr_plain_mek_opt_info;
#endif
};

/**
 * \brief Parse a x509 certificate and populate the "cert" structure
 *
 * \param in Input (encoded) data
 * \param size (input/output param) Size of input data and length of parsed
 *              data at the end of processing (fail or success).
 * \param cert Parsed certificate pointer
 *
 * \return EFTOK if parse was successful
 */
fterr asn1p_x509_certificate(const u8 in[ASN1P_IMAX], u32 size[1], struct x509_cert *cert);

/**
 * \brief Parse a RSA private key
 *
 * Parse a RSA private key asn1 DER encoded data as defined in PKCS #1 and
 * populate the "privkey" structure
 *
 * \param in Input (encoded) data
 * \param size Size of input data
 * \param privkey Parsed rsa_privkey
 *
 * \return EFTOK if parse was successful
 */
fterr asn1p_rsa_privkey(const u8 in[ASN1P_IMAX], u32 size, struct rsa_privkey *privkey);

/**
 * \brief Parse a EC private key
 *
 * Parse a EC private key asn1 DER encoded data as defined in RFC 5915 and
 * populate the "privkey" structure
 *
 * \param in Input (encoded) data
 * \param size Size of input data
 * \param privkey Parsed rsa_privkey
 *
 * \return EFTOK if parse was successful
 */
fterr asn1p_ec_privkey(const u8 in[ASN1P_IMAX], u32 size, struct ec_privkey *privkey);
/**
 * \brief determine length of x509 certificate
 *
 * Parse the header of the X509 certificate and determine the certificate
 * size. This can be used to ensure that all the certificate is in memory
 * for parsing.
 *
 * \param in Input (encoded) data
 * \param cert_len Pointer to hold the length of the certificate
 *
 * \return EFTOK if parse was successful
 */
fterr asn1p_cert_length(const u8 in[ASN1P_IMAX], u32 *cert_len);

/**
 * \brief return length of hash given the index.
 *
 * \param hash_index hash algo index populated during X509 parsing.
 *
 * \return length of hash in bytes if index is valid,
 *         0 otherwise
 */
u32 get_asn1p_hash_len(u8 hash_index);

/**
 * \brief return the hash algorithm used to sign certificate
 *
 * \param cert parsed certificate data structure
 *
 * \return ID of the hash algorithm used if valid
 *         (HASH_ALGO_N_ITEMS + 1) otherwise
 */
u8 get_asn1p_cert_hash_algo(const struct x509_cert *cert);

#ifndef CONFIG_KEY_WRITER
/**
 * \brief Parse the firewall extension and perform configurations.
 *
 * \param in Input (encoded) data
 * \param ctx ASN.1 parser context
 * \param cert parsed certificate data structure
 *
 * \return EFTOK is successful.
 */
fterr asn1p_firewall_conf(const u8 in[ASN1P_IMAX], struct asn1p_ctx *ctx, struct x509_cert *cert);
#endif

fterr is_boot_ext_parsed(const struct x509_cert *cert);
fterr is_image_integ_ext_parsed(const struct x509_cert *cert);
fterr is_swrv_ext_parsed(const struct x509_cert *cert);
fterr is_load_ext_parsed(const struct x509_cert *cert);
fterr is_debug_ext_parsed(const struct x509_cert *cert);
fterr is_encryption_ext_parsed(const struct x509_cert *cert);
fterr is_sec_bcfg_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_enc_aes_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_enc_smpk_sign_aes_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_enc_bmpk_sign_aes_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_aes_enc_smpkh_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_aes_enc_smek_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_mpk_opt_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_aes_enc_bmpkh_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_aes_enc_bmek_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_mek_opt_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_aes_enc_ext_otp_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_msv_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_key_rev_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_key_cnt_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_swrev_sysfw_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_swrev_sbl_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_swrev_sec_brdcfg_info_ext_parsed(const struct x509_cert *cert);
fterr is_keywr_plain_keywr_min_ver_info_ext_parsed(const struct x509_cert *cert);
fterr is_firewall_ext_parsed(const struct x509_cert *cert);
#endif /* ASN1_PARSE_H_ */
