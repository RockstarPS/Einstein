/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file aes.h
 *
 * \brief  DMSC AES driver
 *
 */

#ifndef AES_H_
#define AES_H_

#include <types/short_types.h>
#include <types/fterr.h>

#define AES_OP_DIRECTION_MASK  (1u)
#define AES_OP_DIRECTION_SHIFT (0u)
#define AES_OP_DECRYPT         (0u)
#define AES_OP_ENCRYPT         (1u)

#define AES_OP_KEY_SIZE_MASK   (6u)
#define AES_OP_KEY_SIZE_SHIFT  (1u)
#define AES_OP_KEY_SIZE_128    (2u)
#define AES_OP_KEY_SIZE_192    (4u)
#define AES_OP_KEY_SIZE_256    (6u)

#define AES_MODE_ECB           (0u)
#define AES_MODE_CBC           (1u)
#define AES_MODE_ICM           (2u)
#define AES_MODE_CFB           (3u)
#define AES_MODE_CTR           (4u)
#define AES_MODE_CMAC          (5u)
#define AES_MODE_GCM           (6u)
#define AES_MODE_CCM           (7u)

#define AES_KEK_OPTIONS_NO_KEK            (0u)
#define AES_KEK_OPTIONS_KEK_DIRECT        (1u)

#define AES_KEYLEN_WORDS      (8u)
#define AES_KEYLEN_BYTES      (32u)
#define AES_BLOCKLEN_WORDS    (4u)
#define AES_BLOCKLEN_BYTES    (16u)

/*
 * Specifies the counter width for AES-CTR mode in bits
 */
#define AES_CTR_WIDTH_32        (0U)
#define AES_CTR_WIDTH_64        (1U)
#define AES_CTR_WIDTH_96        (2U)
#define AES_CTR_WIDTH_128       (3U)

/**
 * \brief AES driver context
 *
 * The processing context for invoking the AES driver. The caller allocates a
 * context, populates the fields necessary and calls either one of one-shot
 * functions or calls the function sequence init-update*-final to complete a
 * AES operation.
 *
 * \param key_1 Primary key used by most aes modes, populated by the caller
 * \param key_2 Secondary key used in some AAD modes, populated by the caller
 * \param iv Initialization vector, populated by the caller initially, updated
 *           by the driver after an operation is complete
 * \param tag Tag Updated by the driver at the end of an operation for MAC and
 *            AAD modes.
 * \param op_key_size Key size one of AES_OP_KEY_SIZE_128, AES_OP_KEY_SIZE_192
 *                    and AES_OP_KEY_SIZE_256
 * \param mode One of AES_MODE_* modes of operation
 * \param kek_options Key usage options, one of AES_KEK_*
 * \param ctr_width counter width for AES-CTR mode, one of AES_CTR_WIDTH_*
 * \param rdata Residual data remaining after processing one block length of
 *              data at a time (Internal use only)
 * \param rdata_len Residual data length (Internal use only)
 * \param fixed_clen Length of data used in one-shot modes operating on fixed
 *                   data sizes. (not for init-update-final)
 * \param ccm_l "L" value used in CCM mode.
 * \param gcm_mode (Sub) Mode of operation of AES GCM
 * \param aad_len Length of AAD data for GCM and CCM modes
 */
struct aes_ctx {
	u32	key_1[AES_KEYLEN_WORDS];
	u32	key_2[AES_KEYLEN_WORDS];
	u32	iv[AES_BLOCKLEN_WORDS];
	u32	tag[AES_BLOCKLEN_WORDS];
	u8	op_key_size;
	u8	mode;
	u8	kek_options;
	u8	ctr_width;

	/* Internal data, not populated/used by callers */
	u32	rdata[AES_BLOCKLEN_WORDS];
	u32	rdata_len;
	u32	fixed_clen;
	u8	ccm_l;
	u8	gcm_mode;
	u32	aad_len;
};

/**
 * \brief Read out H/W revision of the IP
 *
 * \return Revision word of the IP
 */
u32 aes_revision(void);

/**
 * \brief Do a soft-reset of the IP
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_softreset(void);

/**
 * \brief External function to initialize a AES context
 *
 * \param ctx AES driver context
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_init(struct aes_ctx *ctx);

/**
 * \brief Function to process data in a AES context
 *
 * \param ctx AES driver context
 * \param in Input data to process
 * \param in_len Length of input data
 * \param out Output pointer to write the processed data
 * \param out_len Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_update(struct aes_ctx *ctx, const u8 *in, u32 in_len, u8 *out, u32 *out_len);

/**
 * \brief Function to finalize AES operations for a context
 *
 * Function called at the end to process residual data and write TAG/IV
 *
 * \param ctx AES driver context
 * \param out Output pointer to write the processed data
 * \param out_len Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_final(struct aes_ctx *ctx, u8 *out, u32 *out_len);

/**
 * \brief Function to process a encrypt/decrypt operation one-shot
 *
 * \param ctx AES driver context
 * \param in Input data to process
 * \param in_len Length of input data
 * \param out Output pointer to write the processed data
 * \param outlen Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_oneshot(struct aes_ctx *ctx, const u8 *in, u32 in_len, u8 *out, u32 *outlen);

/**
 * \brief Function to process AES CMAC operation one-shot
 *
 * \param ctx AES driver context
 * \param in Input data to process
 * \param in_len Length of input data
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_mac_oneshot(struct aes_ctx *ctx, const u8 *in, u32 in_len);

/**
 * \brief Authenticated encryption or decryption operation (GCM or CCM).
 *
 * \param ctx AES driver context
 * \param iv_len Length of IV for GCM, nonce for CCM, populated in ctx->iv
 * \param aad Additional authentication data
 * \param aad_len Additional authentication data length
 * \param in Input data to process
 * \param in_len Length of input data
 * \param out Output pointer to write the processed data
 * \param outlen Length of output written (output)
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_aenc_oneshot(struct aes_ctx *ctx, u32 iv_len, const u8 *aad, u32 aad_len, const u8 *in, u32 in_len, u8 *out, u32 *outlen);

#endif /* AES_H_ */
