/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_sec_ctx.h
 *
 * \brief Include file for SA2UL security context initialization
 */

#ifndef SA2UL_SEC_CTX_H
#define SA2UL_SEC_CTX_H

#include <types/fterr.h>
#include <types/ftbool.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <crypto_types.h>
#include <sa2ul_sec_ctx_bootcfg.h>

/**
 * Special key ID to indicate that the key is in the request
 */
#define SA2UL_SEC_CTX_KEY_ID_IN_REQ                      (0xFFU)

/**
 * Special key ID to indicate that the DKEK must be used for operation
 */
#define SA2UL_SEC_CTX_KEY_IS_DKEK                        (0xAAU)

/**
 * \brief Information required to create a SA2UL authentication context
 *
 * \param ctx_id ID (index) of the security context slot where to set up
 *               this context.
 * \param mac_type Type of operation - HMAC or plain hash
 *
 * \param hash_algo Hash algorithm
 *
 * \param key_id ID of the key for HMAC operation. This key ID refers to
 *               a key in the keystore
 * \param key_size Size of key for HMAC (if a key is provided in the message)
 *
 * \param key Key used for HMAC if key_id a key in keystore is not used
 */
struct sa2ul_auth_ctx_req {
	u8	ctx_id;
	u8	mac_type;
	u8	hash_algo;
	u8	key_id;
	u8	key_size;
	u8	key[ENC_MAX_KEY_LEN];
} __attribute__((__packed__));

/**
 * \brief Information required to create a SA2UL encryption context
 *
 * \param ctx_id ID (index) of the security context slot where to set up
 *               this context.
 * \param enc_algo Encryption algorithm
 *
 * \param enc_dir Encryption or decryption
 *
 * \param enc_mode Block encryption mode
 *
 * \param key_id ID of the key for the crypto operation. This key ID refers to
 *               a key in the keystore
 *
 * \param key_len Length of the key
 *
 * \param key Key used for encryption, if a key from keystore is not used
 *
 * \param iv IV used for the crypto operation
 */
struct sa2ul_enc_ctx_req {
	u8	ctx_id;
	u8	enc_algo;
	u8	enc_dir;
	u8	enc_mode;
	u8	key_id;
	u8	key_len;
	u8	key[ENC_MAX_KEY_LEN];
	u8	iv[ENC_MAX_IV_LEN];
} __attribute__((__packed__));

/**
 * \brief Reply message for SA2UL context creation request
 *
 * \param scptr Security context pointer
 *
 * \param scid Security context ID
 */

struct sa2ul_ctx_reply {
	u64	scptr;
	u16	scid;
} __attribute__((__packed__));

/**
 * \brief Initialize the SA2UL context module with initial configuration.
 *        (Before bootcfg data is available)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_init_with_initial_cfg(void);

/**
 * \brief Initialize the SA2UL context module
 *
 * \param bootcfg - Boot configuration data
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_init(const struct sa2ul_ctx_bootcfg *bootcfg);

/**
 * \brief Create a security context for SA2UL authentication engine
 *
 * \param host - Host ID of the caller
 *
 * \param req - Hash mode, algo and other relevant information needed
 *              to construct the authentication engine context
 *
 * \param purpose One or more of flags KEYSTORE_SKEY_USAGE_* indicating the
 *                intended use of the security context
 *
 * \param reply - Information returned to the caller if the call was
 *                successful
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_auth_create(u8 host, const struct sa2ul_auth_ctx_req *req, u32 purpose, struct sa2ul_ctx_reply *reply);

/**
 * \brief Create a security context for SA2UL encryption engine
 *
 * \param host - Host ID of the caller
 *
 * \param req - Encryption algo, mode and other relevant information needed
 *              to construct the encryption engine context
 *
 * \param purpose One or more of flags KEYSTORE_SKEY_USAGE_* indicating the
 *                intended use of the security context
 *
 * \param reply - Information returned to the caller if the call was
 *                successful
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_enc_create(u8 host, struct sa2ul_enc_ctx_req *req, u32 purpose, struct sa2ul_ctx_reply *reply);

/**
 * \brief Create a security context for SA2UL encryption engine (GCM Mode)
 *
 * \param host          - Host ID of the caller
 * \param req           - Encryption algo, mode and other relevant information
 *                          needed to construct the encryption engine context
 * \param purpose       - One or more of flags KEYSTORE_SKEY_USAGE_* indicating the
 *                          intended use of the security context
 * \param reply         - Information returned to the caller if the call was successful
 * \param ghash         - Galois Hash, calculated by encrypting 128 bit string of all
 *                          0's with the encryption key K (req.key)
 * \param cipher_length - length of cipher text (same as plain text)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_gcm_enc_create(u8 host, struct sa2ul_enc_ctx_req *req, u32 purpose, struct sa2ul_ctx_reply *reply, u8 ghash[ENC_GCM_GHASH_LEN], u64 cipher_length);

/**
 * \brief Create a security context for SA2UL encryption engine (ECB Mode)
 *
 * \param host          - Host ID of the caller
 * \param req           - Encryption algo, mode and other relevant information
 *                          needed to construct the encryption engine context
 * \param purpose       - One or more of flags KEYSTORE_SKEY_USAGE_* indicating the
 *                          intended use of the security context
 * \param reply         - Information returned to the caller if the call was successful
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_ecb_enc_create(u8 host, struct sa2ul_enc_ctx_req *req, u32 purpose, struct sa2ul_ctx_reply *reply);

/**
 * \brief Update security context credentials to a value other than the
 *        owner of the Security Context slot. This is a internal API
 *        only used for image decryption or authentication. This is only
 *        allowed for DMSC's SA2UL context slot.
 *
 * \param ctx_id ID (index) of the security context slot where to set up
 *               this context.
 *
 * \param host - Host ID to use for updating the credentials.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_update_creds(u8 ctx_id, u8 host);

/**
 * \brief Wipe the security context
 *
 * \param host - Host ID of the caller
 *
 * \param ctx_id ID (index) of the security context slot where to set up
 *               this context.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sa2ul_sec_ctx_wipe(u8 ctx_id, u8 host);

#endif
