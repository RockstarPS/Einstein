/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_sec_ctx.c
 *
 * \brief Helper functions to setup a SA2UL security context
 */

#include <string.h>
#include <masters.h>
#include <socmem.h>
#include <hosts.h>
#include <hosts_internal.h>
#include <common_funcs.h>
#include <sa2ul_sec_ctx.h>
#include <sa2ul_pkt_descr.h>
#include <hs/sa2ul.h>
#include "sa2ul_regs.h"
#include <firewall.h>
#include "sa2ul_aes_keyinv.h"
#include <keystore.h>

/**
 * \brief SA2UL SECCTL structure in context RAM, used by both encryption and
 *        authentication engines.
 *
 * \param scctl1 First word of SCCTL structure (see SA2UL spec)
 * \param scctl2 Second word of SCCTL structure (see SA2UL spec)
 * \param scptrH Second word of SCCTL structure including the higher 16-bits of
 *               security context pointer
 * \param scptrL Security context pointer (populated by IP, dont care for SW)
 */
struct sa2ul_ctx_scctl {
	u32	scctl1;
	u32	scctl2;
	u32	scptrH;
	u32	scptrL;
};

#define SA2UL_SCCTL1_OWNER_MASK  (0x80000000U)
#define SA2UL_SCCTL1_OWNER_SHIFT (31U)

#define SA2UL_SCCTL1_EVICT_DONE_MASK  (0x40000000U)
#define SA2UL_SCCTL1_EVICT_DONE_SHIFT (30U)

#define SA2UL_SCCTL1_FETCH_EVICT_CONTROL_MASK  (0xff0000U)
#define SA2UL_SCCTL1_FETCH_EVICT_CONTROL_SHIFT (16U)

#define SA2UL_SCCTL1_FETCH_EVICT_SIZE_MASK  (0xff0000U)
#define SA2UL_SCCTL1_FETCH_EVICT_SIZE_SHIFT (16U)

#define SA2UL_SCCTL1_SCID_MASK  (0xffffU)
#define SA2UL_SCCTL1_SCID_SHIFT (0U)

#define SA2UL_SCCTL2_OVERWRITE_FLOWID_MASK  (0x80000000U)
#define SA2UL_SCCTL2_OVERWRITE_FLOWID_SHIFT (31U)

#define SA2UL_SCCTL2_PRIVID_MASK  (0xff0000U)
#define SA2UL_SCCTL2_PRIVID_SHIFT (16U)

#define SA2UL_SCCTL2_PRIV_MASK  (0x300U)
#define SA2UL_SCCTL2_PRIV_SHIFT (8U)

#define SA2UL_SCCTL2_ALLOW_PROMOTE_MASK  (0x80U)
#define SA2UL_SCCTL2_ALLOW_PROMOTE_SHIFT (7U)

#define SA2UL_SCCTL2_ALLOW_DEMOTE_MASK  (0x40U)
#define SA2UL_SCCTL2_ALLOW_DEMOTE_SHIFT (6U)

#define SA2UL_SCCTL2_ALLOW_NON_SECURE_MASK  (0x20U)
#define SA2UL_SCCTL2_ALLOW_NON_SECURE_SHIFT (5U)

#define SA2UL_SCCTL2_SECURE_MASK  (0x1U)
#define SA2UL_SCCTL2_SECURE_SHIFT (0U)

#define SA2UL_SCPTRH_FLOWID_MASK  (0x3fff0000U)
#define SA2UL_SCPTRH_FLOWID_SHIFT (16U)

/**
 * \brief SA2UL context RAM structure for Authenticiation engine
 *
 * \param authctx1 Authentication context word 1
 *
 * \param reserved0 Reserved field
 *
 * \param auth_len_hi Authentication length in bits (upper 32-bits
 *                    of the 64-bit value)
 * \param auth_len_lo Authentication length in bits (lower 32-bits
 *                    of the 64-bit value)
 * \param reserved1 Reserved field
 *
 * \param key Key for SHA1/SHA2-256 HMAC or lower 32-byte key for SHA2-512 HMAC
 *
 * \param opad OPAD for SHA1/SHA2-256 HMAC or lower 32-byte opad for SHA2-512
 *             HMAC
 * \param key_high Upper 32-byte key for SHA2-512 HMAC
 *
 * \param opad_high Upper 32-byte opad for SHA2-512 HMAC
 */
struct sa2ul_sec_ctx_auth {
	u32	authctx1;
	u32	reserved0;
	u32	auth_len_hi;
	u32	auth_len_lo;
	u32	reserved1[4];
	u8	key[32];
	u8	opad[32];
	u8	key_high[32];
	u8	opad_high[32];
};

#define SA2UL_AUTHCTX1_MODESEL_MASK  (0x80000000U)
#define SA2UL_AUTHCTX1_MODESEL_SHIFT (31U)

#define SA2UL_AUTHCTX1_DEFAULT_NEXT_ENGINE_ID_MASK  (0x1f000000U)
#define SA2UL_AUTHCTX1_DEFAULT_NEXT_ENGINE_ID_SHIFT (24U)

#define SA2UL_AUTHCTX1_SW_CONTROL_MASK  (0xff0000U)
#define SA2UL_AUTHCTX1_SW_CONTROL_SHIFT (16U)

/**
 * \brief SA2UL context RAM structure for Encryption engine
 *
 * \param enc_ctrl Encryption control word
 *
 * \param mode_ctrl_instrs Mode control instructions
 *
 * \param hw_ctrl_word Hardware control word
 *
 * \param key Primary encryption key
 *
 * \param aux1 Additional data need for encryption, such as IV, CTR, etc...
 *
 * \param aux2 Additional data need for encryption, such as IV, CTR, etc...
 *
 * \param aux3 Additional data need for encryption, such as IV, CTR, etc...
 *
 * \param aux4 Additional data need for encryption, such as IV, CTR, etc...
 *
 * \param pre_crypto_data Scratch memory area for the IP, not used by SW
 */
struct sa2ul_sec_ctx_enc {
	u32	enc_ctrl;
	u32	mode_ctrl_instrs[6];
	u32	hw_ctrl_word;
	u32	key[8];
	u32	aux1[8];
	u32	aux2[4];
	u32	aux3[4];
	u32	aux4[4];
	u8	pre_crypto_data[15];
};

#define SA2UL_ENCRCTL_MODESEL_MASK  (0x80000000U)
#define SA2UL_ENCRCTL_MODESEL_SHIFT (31U)

#define SA2UL_ENCRCTL_USE_DKEK_MASK  (0x40000000U)
#define SA2UL_ENCRCTL_USE_DKEK_SHIFT (30U)

#define SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_MASK  (0x1f000000U)
#define SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_SHIFT (24U)

#define SA2UL_ENCRCTL_TRAILER_EVERY_CHUNK_MASK  (0x800000U)
#define SA2UL_ENCRCTL_TRAILER_EVERY_CHUNK_SHIFT (23U)

#define SA2UL_ENCRCTL_TRAILER_AT_END_MASK  (0x400000U)
#define SA2UL_ENCRCTL_TRAILER_AT_END_SHIFT (22U)

#define SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_MASK  (0x200000U)
#define SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_SHIFT (21U)

#define SA2UL_ENCRCTL_ENCRYPT_DECRYPT_MASK  (0x100000U)
#define SA2UL_ENCRCTL_ENCRYPT_DECRYPT_SHIFT (20U)

#define SA2UL_ENCRCTL_BLK_SIZE_MASK  (0x70000U)
#define SA2UL_ENCRCTL_BLK_SIZE_SHIFT (16U)

#define SA2UL_ENCRCTL_SOP_OFFSET_MASK  (0xF00U)
#define SA2UL_ENCRCTL_SOP_OFFSET_SHIFT (8U)

#define SA2UL_ENCRCTL_MIDDLE_OFFSET_MASK  (0xF0U)
#define SA2UL_ENCRCTL_MIDDLE_OFFSET_SHIFT (4U)

#define SA2UL_ENCRCTL_EOP_OFFSET_MASK  (0xFU)
#define SA2UL_ENCRCTL_EOP_OFFSET_SHIFT (0U)

/**
 * The authentication and encryption engine specific data starts at the
 * offset of 64bytes or 16 words in the context RAM
 */
#define SA2UL_CTX_ENG_WOFFSET        (16)

/**
 * Values of "Authentication core select" field in "AuthenticationSWControl"
 */
static const u8 sa2ul_ctx_hash_alg[HASH_ALGO_N_ITEMS] = {
	4U,     /* HASH_ALGO_SHA2_256 */
	5U,     /* HASH_ALGO_SHA2_384 */
	6U,     /* HASH_ALGO_SHA2_512 */
	3U,     /* HASH_ALGO_SHA2_224 */
	2U,     /* HASH_ALGO_SHA1     */
	1U      /* HASH_ALGO_MD5      */
};

static const u8 sa2ul_enc_ctx_blksize[ENC_ALGO_N_ITEMS] = {
	1U, 0U
};

/**
 * Mode control engine instructions for AES-CBC decryption
 */
static const u8 mcei_aes_cbc_dec[3][7] = {
	{ 0x80, 0x8a, 0xca, 0x98, 0xf4, 0x40, 0xc0 },
	{ 0x84, 0x8a, 0xca, 0x98, 0xf4, 0x40, 0xc0 },
	{ 0x88, 0x8a, 0xca, 0x98, 0xf4, 0x40, 0xc0 }
};

/**
 * Mode control engine instructions for AES-256-CBC encryption
 */
static const u8 mcei_aes_cbc_enc[3][6] = {
	{ 0x18, 0x88, 0x0a, 0xaa, 0x4b, 0x7e },
	{ 0x18, 0x88, 0x4a, 0xaa, 0x4b, 0x7e },
	{ 0x18, 0x88, 0x8a, 0xaa, 0x4b, 0x7e }
};

/**
 * Mode control engine instructions for AES-GCM encryption
 */
static const u8 mcei_aes_gcm_enc[3][24] = {
	{ 0x80, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x0a, 0x90, 0x71, 0x41, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e },
	{ 0x84, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x4a, 0x90, 0x71, 0x41, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e },
	{ 0x88, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x8a, 0x90, 0x71, 0x41, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e },
};

/**
 * Mode control engine instructions for AES-GCM decryption
 */
static const u8 mcei_aes_gcm_dec[3][24] = {
	{ 0x80, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x0a, 0x14, 0x19, 0x07, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e },
	{ 0x84, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x4a, 0x14, 0x19, 0x07, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e },
	{ 0x88, 0xa9, 0xfe, 0x83, 0x99, 0x7e, 0x58, 0x2e, 0x8a, 0x14, 0x19, 0x07, 0x83, 0x9d, 0x63, 0xaa, 0x0b, 0x7e, 0x9a, 0x78, 0x3a, 0xa3, 0x8b, 0x1e }
};

/**
 * Mode control engine instructions for AES-ECB
 */
static const u8 mcei_aes_ecb[3][5] = {
	{ 0x80, 0x8a, 0x04, 0xb7, 0x90 },
	{ 0x84, 0x8a, 0x04, 0xb7, 0x90 },
	{ 0x88, 0x8a, 0x04, 0xb7, 0x90 }
};

/**
 * Memory reserved for security contexts, align to 4K at firewall granularity
 */
static u32 sa2ul_sec_ctx_mem[SA2UL_SEC_CTX_NUM][SA2UL_SEC_CTX_LEN / 4U]
__attribute__((__section__(".sa2ul_sec_ctx_mem"), aligned(4096)));

extern const struct sa2ul_ctx_bootcfg sec_ctx_bootcfg_data;

/**
 * \brief Local state of SA2UL sec ctx module
 *
 * \param init_done This module is in initial configuration state
 * \param full_init_done Full init of this module is done
 * \param bootcfg Pointer to boot configuration data
 */
static struct sa2ul_ctx_state {
	ftbool				init_done;
	ftbool				full_init_done;
	const struct sa2ul_ctx_bootcfg	*bootcfg;
	soc_phys_addr_t			sec_ctx_mem_phys;
} sa2ul_ctx_st;


/**
 * \brief endian swap and copy from/to SA2UL context in the 64-byte little
 *        endian format that SA2UL expects
 *
 * \param dest Destination pointer
 * \param src Source pointer
 * \param len length of the data to copied
 */

static fterr sa2ul_ctx_get_mce_instr(u8 algo, u8 dir, u8 mode, u8 keylen,
				     const u8 **ptr, u32 *len)
{
	fterr ret = EFTOK;

	if ((algo != ENC_ALGO_AES) || /* Only AES supported now */
	    (dir >= ENC_DIR_N_ITEMS) ||
	    (mode >= ENC_MODE_N_ITEMS) ||
	    (keylen >= ENC_KEYLEN_MAX)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		switch (mode) {
		case ENC_MODE_ECB:
			*ptr = &mcei_aes_ecb[keylen][0];
			*len = sizeof(mcei_aes_ecb[0]);
			break;
		case ENC_MODE_CBC:
			if (dir == ENC_DIR_ENCRYPT) {
				*ptr = &mcei_aes_cbc_enc[keylen][0];
				*len = sizeof(mcei_aes_cbc_enc[0]);
			} else {
				*ptr = &mcei_aes_cbc_dec[keylen][0];
				*len = sizeof(mcei_aes_cbc_dec[0]);
			}
			break;
		case ENC_MODE_GCM:
			if (dir == ENC_DIR_ENCRYPT) {
				*ptr = &mcei_aes_gcm_enc[keylen][0];
				*len = sizeof(mcei_aes_gcm_enc[0]);
			} else {
				*ptr = &mcei_aes_gcm_dec[keylen][0];
				*len = sizeof(mcei_aes_gcm_dec[0]);
			}
			break;
		default:
			ret = -EINVAL;
			break;
		}
	}
	return ret;
}

static inline s32 sa2ul_ctx_get_keylen_bits(u8 keylen)
{
	return 128 + (64 * ((s32) keylen));
}


static void sa2ul_ctx_memcpy(u32 *dest, const u32 *src, u32 len)
{
	u32 i, d0, d1, d2, d3;

	for (i = 0U; i < (len >> 2); i += 4U) {
		d0 = src[i];
		d1 = src[i + 1U];
		d2 = src[i + 2U];
		d3 = src[i + 3U];
		dest[i] = d3;
		dest[i + 1U] = d2;
		dest[i + 2U] = d1;
		dest[i + 3U] = d0;
	}
}

static fterr sa2ul_sec_ctx_fetch_key(u8 host, struct sa2ul_enc_ctx_req *req,
				     u32 purpose)
{
	fterr ret = -EINVAL;

	if ((req->key_id == SA2UL_SEC_CTX_KEY_ID_IN_REQ) ||
	    (req->key_id == SA2UL_SEC_CTX_KEY_IS_DKEK)) {
		ret = EFTOK;
	} else {
		if (ft_is_true(sa2ul_ctx_st.full_init_done)) {
			/*
			 * fetch the key from keystore
			 */
			ret = keystore_read_skey(req->key_id, host, purpose,
						 req->key);
		}
	}
	return ret;
}


fterr sa2ul_sec_ctx_init_with_initial_cfg(void)
{
	fterr ret;

	ret = socmem_to_global((local_phys_addr_t)
			       &sa2ul_sec_ctx_mem[0][0],
			       &sa2ul_ctx_st.sec_ctx_mem_phys);

	if (ret == EFTOK) {
		sa2ul_ctx_st.init_done = FT_TRUE;
		sa2ul_ctx_st.full_init_done = FT_FALSE;
	}
	return ret;
}


fterr sa2ul_sec_ctx_init(const struct sa2ul_ctx_bootcfg *bootcfg)
{
	fterr ret = EFTOK;
	u32 i;
	struct sa2ul_ctx_scctl scctl;

	/*
	 * We need index 0 to be owned by DMSC always
	 */
	if (ret == EFTOK) {
		sa2ul_ctx_st.full_init_done = FT_TRUE;
		sa2ul_ctx_st.bootcfg = bootcfg;

		/* Clear the owner bit and initialize the context */
		scctl.scctl1 = 0U;
		scctl.scctl2 = 0U;
		scctl.scptrH = 0U;
		scctl.scptrL = 0U;

		for (i = 0U; i < SA2UL_SEC_CTX_NUM; i++) {
			sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[i][0],
					 (u32 *) &scctl, sizeof(scctl));
		}
	}

	return ret;
}

/**
 * \brief Common part of the code to do basic checks
 *
 * \param host Host ID of the caller
 *
 * \param id Index into the context array
 *
 */
static fterr sa2ul_sec_ctx_do_checks(u8 host, u8 id)
{
	fterr ret = EFTOK;

	if (!ft_is_true(sa2ul_ctx_st.init_done)) {
		ret = -EINVAL;
	}

	if ((ret == EFTOK) && (id >= SA2UL_SEC_CTX_NUM)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		/*
		 * If full init is not yet done, allow DMSC only
		 */
		if (!ft_is_true(sa2ul_ctx_st.full_init_done)) {
			if (host != sa2ul_ctx_st.bootcfg->owners[id]) {
				ret = -EINVAL;
			}
		}
	}
	return ret;
}

/**
 * \brief Set credentials in the security context
 *
 * \param host Host ID of the caller
 *
 * \param scctl Security context control structure pointer, populated
 *              with credentials
 */
static fterr sa2ul_sec_ctx_set_creds(u8 host, struct sa2ul_ctx_scctl *scctl)
{
	struct master_creds creds;
	fterr ret = EFTOK;

	/*
	 * When the firewalls are disabled, we are not configuring the ISC for
	 * the ring accelerator. As a result, the DMA uses the credentials of
	 * the initiator i.e. DMSC. When not using firewalls, the security
	 * context is also not initialized i.e. all the values are zeroed out.
	 * As a result, there is a mismatch between the security context and
	 * the settings in the SA2UL incoming packet.
	 *
	 * To avoid this issue
	 *  -  We are configuring the security context even when firewalls are off
	 *  -  We are using DMSC credentials for the security context.
	 */
	{
		/* Use DMSC credentials by default */
		creds.privid = PRIVID_DMSC;
		creds.secure = FT_FALSE;
		creds.priv = FT_TRUE;
		creds.nsecure = FT_TRUE;
		creds.user = FT_FALSE;
	}

#ifdef CONFIG_SECURITY_FIREWALL
//	if (ft_is_true(sa2ul_ctx_st.full_init_done))
        {
		/*
		 * Get the security attributes of the security context owner
		 */
		ret = masters_get_host_attrs(host, &creds, NULL);
	}
#endif

	if (ret == EFTOK) {
		scctl->scctl2 &= (~(SA2UL_SCCTL2_PRIVID_MASK |
				    SA2UL_SCCTL2_SECURE_MASK |
				    SA2UL_SCCTL2_ALLOW_PROMOTE_MASK |
				    SA2UL_SCCTL2_ALLOW_DEMOTE_MASK |
				    SA2UL_SCCTL2_ALLOW_NON_SECURE_MASK |
				    SA2UL_SCCTL2_PRIV_MASK));

		scctl->scctl2 |=
			((u32) creds.privid << SA2UL_SCCTL2_PRIVID_SHIFT) &
			SA2UL_SCCTL2_PRIVID_MASK;
		if (ft_is_true(creds.secure)) {
			scctl->scctl2 |= (1U << SA2UL_SCCTL2_SECURE_SHIFT) &
					 SA2UL_SCCTL2_SECURE_MASK;
		}
		if (ft_is_true(creds.priv)) {
			scctl->scctl2 |= (1U << SA2UL_SCCTL2_PRIV_SHIFT) &
					 SA2UL_SCCTL2_PRIV_MASK;
		}
	}
	return ret;
}

/**
 * \brief Common part of the code for creating a security context - initialize
 *        the SCCTL structure
 *
 * \param host Host ID of the caller
 *
 * \param id Index into the context array
 *
 * \param scctl Security context control structure pointer, populated
 *              with common fields
 */
static fterr sa2ul_sec_ctx_init_scctl(u8 host, u8 id,
				      struct sa2ul_ctx_scctl *scctl)
{
	fterr ret=EFTOK;

	ret = sa2ul_sec_ctx_do_checks(host, id);
	if (ret == EFTOK) {
		/*
		 * Check if SA2UL is still holding the context
		 * Skip this check if scctl is NULL
		 */
		sa2ul_ctx_memcpy((u32 *) scctl, &sa2ul_sec_ctx_mem[id][0],
				 sizeof(struct sa2ul_ctx_scctl));
		if ((scctl->scctl1 & SA2UL_SCCTL1_OWNER_MASK) != 0U) {
		 	ret = -EINVAL;
		}
	}
	if (ret == EFTOK) {
		(void) memset(scctl, 0, sizeof(struct sa2ul_ctx_scctl));

		scctl->scctl1 = (1U << SA2UL_SCCTL1_OWNER_SHIFT) &
				SA2UL_SCCTL1_OWNER_MASK;
		scctl->scctl1 |= (1U << SA2UL_SCCTL1_EVICT_DONE_SHIFT) &
				 SA2UL_SCCTL1_EVICT_DONE_MASK;

		ret = sa2ul_sec_ctx_set_creds(host, scctl);
	}
	return ret;
}

fterr sa2ul_sec_ctx_update_creds(u8 ctx_id, u8 host)
{
	fterr ret;
	struct sa2ul_ctx_scctl scctl;

	ret = sa2ul_sec_ctx_do_checks(HOST_ID_HSM, ctx_id);

	if (ret == EFTOK) {
		sa2ul_ctx_memcpy((u32 *) &scctl, &sa2ul_sec_ctx_mem[ctx_id][0],
				 sizeof(struct sa2ul_ctx_scctl));

		ret = sa2ul_sec_ctx_set_creds(host, &scctl);
	}

	if (ret == EFTOK) {
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[ctx_id][0], (u32 *) &scctl,
				 sizeof(scctl));
	}
	return ret;
}

fterr sa2ul_sec_ctx_wipe(u8 ctx_id, u8 host)
{
	fterr ret;

	/*
	 * Wipe the context regardless of SA2UL holding it
	 */
	ret = sa2ul_sec_ctx_do_checks(host, ctx_id);

	if (ret == EFTOK) {
		(void) memset(&sa2ul_sec_ctx_mem[ctx_id][0], 0,
			      SA2UL_SEC_CTX_LEN);
	}
	return ret;
}

fterr sa2ul_sec_ctx_auth_create(u8 host, const struct sa2ul_auth_ctx_req *req,
				u32 purpose __attribute__((unused)),
				struct sa2ul_ctx_reply *reply)
{
	fterr ret = EFTOK;
	u8 id;
	u32 reg;
	struct sa2ul_ctx_scctl scctl;
	struct sa2ul_sec_ctx_auth auth;

	/*
	 * purpose is currently unused, must be used when HMAC is implemented
	 */

	/* Only hash implemented at present */
	if ((req->mac_type != MAC_TYPE_HASH) ||
	    (req->hash_algo >= HASH_ALGO_N_ITEMS)) {
		ret = -EINVAL;
	}

	id = req->ctx_id;

	if (ret == EFTOK) {
		ret = sa2ul_sec_ctx_init_scctl(host, id, &scctl);
	}
	if (ret == EFTOK) {
		scctl.scctl1 |=
			(0x91U << SA2UL_SCCTL1_FETCH_EVICT_CONTROL_SHIFT) &
			SA2UL_SCCTL1_FETCH_EVICT_CONTROL_MASK;

		(void) memset(&auth, 0, sizeof(auth));

		/*
		 * Configuring the first byte of the authentication context RAM
		 * Bit   7 = 0    - Actual hash processing.
		 * Bit 6:5 = 0    - Reserved
		 * Bit 4:0 = 0x20 - Default egress port.
		 */
		auth.authctx1 = (SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT <<
				 SA2UL_AUTHCTX1_DEFAULT_NEXT_ENGINE_ID_SHIFT) &
				SA2UL_AUTHCTX1_DEFAULT_NEXT_ENGINE_ID_MASK;

		/*
		 * Configuring the second byte i.e. AuthenticationSWControl
		 * Bit   7 = 0 - Do not upload hash in trailer section for every chunk.
		 * Bit   6 = 1 - Upload hash in trailer section only after length defined in
		 *               AuthenticationLength field is processed.
		 * Bit   5 = 0 - reserved
		 * Bit 3:0     - hash algo
		 */
		reg = 0x40U | (u32) sa2ul_ctx_hash_alg[req->hash_algo];

		/* Bit 4 hash or HMAC */
		if (req->mac_type == MAC_TYPE_HASH) {
			reg |= 0x10U;
		}

		auth.authctx1 |= (reg << SA2UL_AUTHCTX1_SW_CONTROL_SHIFT) &
				 SA2UL_AUTHCTX1_SW_CONTROL_MASK;

		/* Copy back to context memory */
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][SA2UL_CTX_ENG_WOFFSET],
				 (u32 *) &auth, sizeof(auth));
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][0], (u32 *) &scctl,
				 sizeof(scctl));
		/*
		 * AuthenticationLength is left as zero. HW calculates
		 * the length based on actual bytes hashed.
		 */

		/* Populate reply */
		reply->scptr = sa2ul_ctx_st.sec_ctx_mem_phys +
			       ((u64) id * (u64) SA2UL_SEC_CTX_LEN);
		/* Use index as context ID */
		reply->scid = (u16) id;
	}

	return ret;
}

static ftbool sa2ul_get_aes_dpa_cm_enable(void)
{
	u32 instance;
	struct sa2ul_regs *regs;
	fterr status = -EINVAL;
	ftbool ret = FT_FALSE;

	/* Instance 0 is used by SYSFW */
	instance = 0;

	if (instance < sa2ul_socdata.num_instances) {
		status = EFTOK;
	}

	/* Retrieve the SA2UL registers */
	if (status == EFTOK) {
		status = socmem_to_local(sa2ul_socdata.base_addr[instance],
					 (local_phys_addr_t *) &regs);
	}

	/*
	 * Read the efuse enable register, and check bit index 4 to see
	 * if AES counter measures are enabled
	 */
	if (status == EFTOK) {
		if ((readl(&regs->EFUSE_EN) & (1U << SA2UL_EFUSE_AES_DPA_CM_EN_BIT))
		    != (1U << SA2UL_EFUSE_AES_DPA_CM_EN_BIT)) {
			status = -ENODEV;
		}
	}

	if (ft_is_ok(status)) {
		ret = FT_TRUE;
	}

	return ret;
}

fterr sa2ul_sec_ctx_enc_create(u8 host, struct sa2ul_enc_ctx_req *req,
			       u32 purpose,
			       struct sa2ul_ctx_reply *reply)
{
	fterr ret;
	u8 id;
	const u8 *mcei_ptr;
	u32 mcei_len;
	struct sa2ul_ctx_scctl scctl;
	struct sa2ul_sec_ctx_enc enc;
	s32 keylen_bits;
	ftbool aes_cm_flag;

	id = req->ctx_id;
	ret = sa2ul_sec_ctx_init_scctl(host, id, &scctl);
	if (ret == EFTOK) {
		ret = sa2ul_sec_ctx_fetch_key(host, req, purpose);
	}
	if (ret == EFTOK) {
		/*
		 * Get MCE instructions, also validates encryption algorithm
		 * parameters
		 */
		ret = sa2ul_ctx_get_mce_instr(req->enc_algo, req->enc_dir,
					      req->enc_mode, req->key_len,
					      &mcei_ptr, &mcei_len);
	}
	if (ret == EFTOK) {
		scctl.scctl1 |=
			(0x8DU << SA2UL_SCCTL1_FETCH_EVICT_CONTROL_SHIFT) &
			SA2UL_SCCTL1_FETCH_EVICT_CONTROL_MASK;

		(void) memset(&enc, 0, sizeof(enc));

		enc.enc_ctrl = (SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT <<
				SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_SHIFT) &
			       SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_MASK;
		enc.enc_ctrl |= (1U <<
				 SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_SHIFT) &
				SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_MASK;

		enc.enc_ctrl |= ((u32) req->enc_dir <<
				 SA2UL_ENCRCTL_ENCRYPT_DECRYPT_SHIFT) &
				SA2UL_ENCRCTL_ENCRYPT_DECRYPT_MASK;

		enc.enc_ctrl |= ((u32) sa2ul_enc_ctx_blksize[req->enc_algo] <<
				 SA2UL_ENCRCTL_BLK_SIZE_SHIFT) &
				SA2UL_ENCRCTL_BLK_SIZE_MASK;

		if (req->key_id == SA2UL_SEC_CTX_KEY_IS_DKEK) {
			enc.enc_ctrl |= (1U << SA2UL_ENCRCTL_USE_DKEK_SHIFT) &
					SA2UL_ENCRCTL_USE_DKEK_MASK;
		}

		/*
		 * TODO: SA2UL_ENCRCTL_SOP_OFFSET, SA2UL_ENCRCTL_MIDDLE_OFFSET
		 * and SA2UL_ENCRCTL_EOP_OFFSET are set to zeros. Needs
		 * update when other modes are enabled
		 */

		sa2ul_u8_to_u32le(&enc.mode_ctrl_instrs[0], mcei_ptr,
				  mcei_len);
		enc.hw_ctrl_word = 0U;

		/* Copy the key value */
		sa2ul_u8_to_u32le(enc.key, req->key, ENC_MAX_KEY_LEN);

		/* Copy the IV value */
		if (req->iv != NULL) {
			sa2ul_u8_to_u32le(enc.aux2, req->iv, ENC_MAX_IV_LEN);
		}

		if (req->enc_dir == ENC_DIR_DECRYPT) {
			aes_cm_flag = sa2ul_get_aes_dpa_cm_enable();
			/* Invert the key in context */
			keylen_bits = sa2ul_ctx_get_keylen_bits(req->key_len);
			sa2ul_aes_invkey(enc.key, enc.key, keylen_bits, aes_cm_flag);
		}

		/* Copy back to context memory */
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][SA2UL_CTX_ENG_WOFFSET],
				 (u32 *) &enc, sizeof(enc));
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][0], (u32 *) &scctl,
				 sizeof(scctl));

		/* Erase enc after usage */
		(void) memset((void *) &enc, 0, sizeof(enc));

		/* Populate reply */
		reply->scptr = sa2ul_ctx_st.sec_ctx_mem_phys +
			       ((u64) id * (u64) SA2UL_SEC_CTX_LEN);
		/* Use index as context ID */
		reply->scid = (u16) id;
	}

	return ret;
}

fterr sa2ul_sec_ctx_gcm_enc_create(u8 host, struct sa2ul_enc_ctx_req *req,
				   u32 purpose,
				   struct sa2ul_ctx_reply *reply, u8 ghash[ENC_GCM_GHASH_LEN], u64 cipher_length)
{
	fterr ret;
	u8 id;
	const u8 *mcei_ptr;
	u32 mcei_len;
	struct sa2ul_ctx_scctl scctl;
	struct sa2ul_sec_ctx_enc enc;

	id = req->ctx_id;
	ret = sa2ul_sec_ctx_init_scctl(host, id, &scctl);
	if (ret == EFTOK) {
		ret = sa2ul_sec_ctx_fetch_key(host, req, purpose);
	}
	if (ret == EFTOK) {
		/*
		 * Get MCE instructions, also validates encryption algorithm
		 * parameters
		 */
		ret = sa2ul_ctx_get_mce_instr(req->enc_algo, req->enc_dir,
					      req->enc_mode, req->key_len,
					      &mcei_ptr, &mcei_len);
	}
	if (ret == EFTOK) {
		scctl.scctl1 |=
			(0x8DU << SA2UL_SCCTL1_FETCH_EVICT_CONTROL_SHIFT) &
			SA2UL_SCCTL1_FETCH_EVICT_CONTROL_MASK;

		(void) memset(&enc, 0, sizeof(enc));

		enc.enc_ctrl = 0;

		/* Use_DKEK */
		if (req->key_id == SA2UL_SEC_CTX_KEY_IS_DKEK) {
			enc.enc_ctrl |= (1U << SA2UL_ENCRCTL_USE_DKEK_SHIFT) &
					SA2UL_ENCRCTL_USE_DKEK_MASK;
		}

		/* Default Next Engine-ID */
		enc.enc_ctrl |= (SA2UL_ENGINE_CODE_DEFAULT_EGRESS_PORT <<
				 SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_SHIFT) &
				SA2UL_ENCRCTL_DEFAULT_NEXT_ENGINE_ID_MASK;

		/* Update Trailer only after specified length has been processed. */
		enc.enc_ctrl |= (1U << SA2UL_ENCRCTL_TRAILER_AT_END_SHIFT) &
				SA2UL_ENCRCTL_TRAILER_AT_END_MASK;

		/* Packet Data section update */
		enc.enc_ctrl |= (1U << SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_SHIFT) &
				SA2UL_ENCRCTL_PKT_DATA_SECTION_UPDATE_MASK;

		/* EncryptionBlkSize */
		enc.enc_ctrl |= ((u32) sa2ul_enc_ctx_blksize[req->enc_algo] <<
				 SA2UL_ENCRCTL_BLK_SIZE_SHIFT) &
				SA2UL_ENCRCTL_BLK_SIZE_MASK;

		/* ModeCtrlInstrOffset */
		enc.enc_ctrl |= (0U << SA2UL_ENCRCTL_SOP_OFFSET_SHIFT) &
				SA2UL_ENCRCTL_SOP_OFFSET_MASK;

		enc.enc_ctrl |= (4U << SA2UL_ENCRCTL_MIDDLE_OFFSET_SHIFT) &
				SA2UL_ENCRCTL_MIDDLE_OFFSET_MASK;

		enc.enc_ctrl |= (4U << SA2UL_ENCRCTL_EOP_OFFSET_SHIFT) &
				SA2UL_ENCRCTL_EOP_OFFSET_MASK;

		/* ModeCtrlInstrs */
		sa2ul_u8_to_u32le(&enc.mode_ctrl_instrs[0], mcei_ptr,
				  mcei_len);

		/* HWCtrlWord: Software must initialize to zero's */
		enc.hw_ctrl_word = 0U;

		/* Encryption KeyValue */
		sa2ul_u8_to_u32le(enc.key, req->key, ENC_MAX_KEY_LEN);

		/**
		* EncryptionAux 1
		* Aux1[255:128] = hash key H (used in galois multiplication)
		*/
		sa2ul_u8_to_u32le(enc.aux1, ghash, ENC_GCM_GHASH_LEN);

		/**
		* EncryptionAux 1
		* Aux1[127:0] = Len(A) || Len(C)
		 * Note: cipher_length is required in bits
		*/
		enc.aux1[4] = (u32) 0x0U;
		enc.aux1[5] = (u32) 0x0U;
		cipher_length = cipher_length << 3;
		enc.aux1[6] = (cipher_length >> 32U);
		enc.aux1[7] = (cipher_length & 0xFFFFU);

		/**
		 * EncryptionAux 3
		 * Aux3 = {IV, CTR}
		 * Copy the {IV(96b), CTR(32b)} value */
		sa2ul_u8_to_u32le(enc.aux3, req->iv, ENC_GCM_IV_LEN_BYTES);
		enc.aux3[ENC_GCM_IV_LEN_BYTES / 4] = (u32) 0x1U;

		/* Copy back to context memory */
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][SA2UL_CTX_ENG_WOFFSET],
				 (u32 *) &enc, sizeof(enc));
		sa2ul_ctx_memcpy(&sa2ul_sec_ctx_mem[id][0], (u32 *) &scctl,
				 sizeof(scctl));

		/* Erase enc context after usage */
		(void) memset(&enc, 0, sizeof(enc));

		/* Populate reply */
		reply->scptr = sa2ul_ctx_st.sec_ctx_mem_phys +
			       ((u64) id * (u64) SA2UL_SEC_CTX_LEN);
		/* Use index as context ID */
		reply->scid = (u16) id;
	}

	return ret;
}


