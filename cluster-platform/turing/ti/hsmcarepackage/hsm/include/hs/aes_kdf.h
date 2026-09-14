/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file aes_kdf.h
 *
 * \brief  AES Key derivation function
 *
 */

#ifndef AES_KDF_H_
#define AES_KDF_H_

#include <types/short_types.h>
#include <types/fterr.h>

/**
 * Max input length for Key derivation function
 */
#define KDF_MAX_INPUT_LEN        64U

/**
 * Max output length for Key derivation function
 */
#define KDF_MAX_OUTPUT_LEN       48U

/**
 * \brief AES CMAC Based Key Derivation Function
 *
 * This function is used to generate a derived KEK.
 *
 * Hardware KEK is only available to DMSC and other secure software entities
 * that need a device unique key calls DMSC API that make of this function.
 *
 * This function implements the counter method described in NIST Special
 * Publication 800-108 ( http://dx.doi.org/10.6028/NIST.SP.800-108 )
 *
 * The Key derivation function takes in 2 inputs other than the KEK.
 * 1. Context - Application specified context for key derivation. In this
 *    function, the context is split into 2 parts - locally generated in DMSC
 *    and input from external API caller. Locally generated context consists of
 *    information such as 'host' ID, etc.. that distinguishes one API caller
 *    from another.
 * 2. Label - Another input provided by application.
 *
 * \param local_ctx Local "Context" input to the KDF
 * \param local_ctx_len Length of the local context
 * \param label "Label" input to KDF
 * \param label_len Length of the "Label" input
 * \param context "Context" input to KDF
 * \param context_len Length of the "Context" input
 * \param dkey Output derived key
 * \param dkey_len Length of derived KEK asked for
 *
 * \return EFTOK on success, errorcode otherwise
 */
fterr aes_cmac_kdf(const u8 local_ctx[KDF_MAX_INPUT_LEN], u32 local_ctx_len, const u8 label[KDF_MAX_INPUT_LEN], u32 label_len, const u8 context[KDF_MAX_INPUT_LEN], u32 context_len,
		   u8 dkey[KDF_MAX_OUTPUT_LEN],
		   u32 dkey_len);

#endif /* AES_KDF_H_ */
