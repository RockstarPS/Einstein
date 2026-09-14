/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file aes_kdf.c
 *
 * \brief  AES CMAC based key derivation function
 *
 */

#include <types/short_types.h>
#include <string.h>
#include <aes.h>
#include <aes_kdf.h>

/*
 * This function is implemented according to
 * Recommendation for Key Derivation Using Pseudorandom Functions
 * https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-108.pdf
 */
fterr aes_cmac_kdf(const u8 local_ctx[KDF_MAX_INPUT_LEN], u32 local_ctx_len,
		   const u8 label[KDF_MAX_INPUT_LEN], u32 label_len,
		   const u8 context[KDF_MAX_INPUT_LEN], u32 context_len,
		   u8 dkey[KDF_MAX_OUTPUT_LEN], u32 dkey_len)
{
	struct aes_ctx ctx;
	u8 mac_input[KDF_MAX_INPUT_LEN + 4U];
	u8 mac_output[KDF_MAX_OUTPUT_LEN];
	u32 i, j, k;
	fterr ret = -EINVAL;

	if ((label_len <= KDF_MAX_INPUT_LEN) &&
	    (context_len <= KDF_MAX_INPUT_LEN) &&
	    (local_ctx_len <= KDF_MAX_INPUT_LEN) &&
	    ((label_len + context_len + local_ctx_len) <= KDF_MAX_INPUT_LEN) &&
	    (dkey_len <= KDF_MAX_OUTPUT_LEN)) {
		for (i = 0U; (i * AES_BLOCKLEN_BYTES) < dkey_len; i++) {
			/*
			 * Create input by concatenating
			 * ([i]2 || Label || 0x00 || Context || [L]2)
			 */
			j = 0U;
			mac_input[j++] = (u8) (i + 1U);
			memcpy(&mac_input[j], label, label_len);
			j += label_len;
			mac_input[j++] = (u8) 0UL;
			/* j = ( label_len + 2 ) */

			/*
			 * Add local context.
			 */
			for (k = 0U; k < local_ctx_len; k++) {
				mac_input[j++] = local_ctx[k];
			}
			/* j = ( label_len + 2 + local_context_len ) */

			memcpy(&mac_input[j], context, context_len);
			j += context_len;
			mac_input[j++] = (u8) ((dkey_len * 8U) / 256U);
			mac_input[j++] = (u8) ((dkey_len * 8U) % 256U);
			/* j = ( label_len + 3 + local_context_len + context_len ) */

			/*
			 * The if condition above ensures that
			 * ( label_len + local_context_len + context_len ) < KDF_MAX_INPUT_LEN
			 * Length of mac_input array is KDF_MAX_INPUT_LEN + 4
			 * There is no way the mac_input buffer can overflow.
			 * | KW_ID(72405), KW_ID(71939)
			 * | KW_CODE(ABV.GENERAL)
			 */
			memset(&ctx, 0, sizeof(ctx));
			ctx.op_key_size = AES_OP_KEY_SIZE_256 | AES_OP_ENCRYPT;
			ctx.mode = AES_MODE_CMAC;
			ctx.kek_options = AES_KEK_OPTIONS_KEK_DIRECT;

			ret = aes_mac_oneshot(&ctx, mac_input, j);
			if (ret != EFTOK) {
				break;
			}
			memcpy(&mac_output[(i * AES_BLOCKLEN_BYTES)], ctx.tag,
			       AES_BLOCKLEN_BYTES);
		}
		if (ret == EFTOK) {
			/*
			 * Return: KO := the leftmost L bits of result(n).
			 */
			memcpy(dkey, mac_output, dkey_len);
		}
	}
	return ret;
}
