/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_crypto.c
 *
 * \brief Helper functions to setup a SA2UL security context
 */

#include <string.h>
#include <socmem.h>
#include <sec_dma.h>
#include <hosts.h>
#include <hosts_internal.h>
#include <sa2ul_sec_ctx.h>
#include <sa2ul_pkt_descr.h>
#include <sa2ul.h>
#include <sa2ul_crypto.h>
#include <lib/trace.h>

/**
 * Time out for DMA completion for 1 Kbyte of data => 50 micro secs
 *
 * Roughly 20 MBps through put.
 */
#define SA2UL_TMOUT_US_PER_KBYTE  (50U)

/**
 * \brief calculate the maximum timeout required for an SA2UL hash or encryption
 * operation
 *
 * \param pkt_size Size of the DMA packet in bytes
 * \return timeout required in micro seconds
 */
static u32 calc_sa2ul_timeout(u32 pkt_size)
{
	u32 tmout;

	/* On receiving a packet, SA2UL performs context fetch */
	tmout = SA2UL_TMOUT_US_PER_KBYTE;

	/*
	 * add a timeout based on packet size and expected throughput
	 * packet size is rounded up the next KB
	 */
	tmout += (SA2UL_TMOUT_US_PER_KBYTE * (pkt_size + 1023U)) >> 10;

	return tmout;
}

/*
 * Maximum packet size allowed for SA2UL Hash engine (4MB - 1)
 * We are limiting this further to 32 KB as the test framework
 * only tests up to 32 KB fragments.
 */
#define SA2UL_HASH_MAX_PKT_SIZE (32U * 1024U)

/*
 * Maximum packet size allowed for SA2UL encryption engine (64KB - 1)
 * However input lengths to AES algorithm must be multiples of 16 bytes.
 * Effectively the maximum packet size is (64*1024 - 16) bytes.
 * We have chosen to constrain this further to 62 KB inline with the block
 * size used by ROM.
 */
#define SA2UL_ENC_MAX_PKT_SIZE (62U * 1024U)

#define SA2UL_HASH_ALG_SHA2_512         (0x16U)

/**
 * Hash lengths
 */
static const u8 sa2ul_crypto_hash_len[HASH_ALGO_N_ITEMS] = {
	32U,            /* HASH_ALGO_SHA2_256 */
	48U,            /* HASH_ALGO_SHA2_384 */
	64U,            /* HASH_ALGO_SHA2_512 */
	28U,            /* HASH_ALGO_SHA2_224 */
	20U,            /* HASH_ALGO_SHA1     */
	16U             /* HASH_ALGO_MD5      */
};

u32 sa2ul_crypto_get_hash_len(u8 hash_algo)
{
	u32 ret = 0;

	if (hash_algo < HASH_ALGO_N_ITEMS) {
		ret = (u32) sa2ul_crypto_hash_len[hash_algo];
	}

	return ret;
}

fterr sa2ul_hash_core(soc_phys_addr_t to, soc_phys_addr_t from, u32 tot_len,
		      u8 read_host, u8 write_host, u8 hash_algo, u8 *hash,
		      u32 max_pkt_size_req, ftbool output_in_place)
{
	fterr ret = EFTOK, tret;
	struct sa2ul_host_descr_tx *txd;
	struct sa2ul_host_descr_rx *rxd;
	u32 psdata_len, hash_len, tmout;
	u8 id;
	struct sa2ul_auth_ctx_req req;
	struct sa2ul_ctx_reply reply;
	ftbool force_teardown = FT_TRUE;
	volatile u32 HOLD=5000;
	/*
	 * When supporting in-place authentication without
	 * writing back to the source buffer, max_pkt_size
	 * can be smaller than the maximum supported by the
	 * hash engine.
	 */
	u32 max_pkt_size = SA2UL_HASH_MAX_PKT_SIZE;
	u32 num_pkts = 0;
	u32 i = 0U;
	u32 curr_pkt_size = 0U;
	u8 write_incr = 1U;

	if (max_pkt_size_req <= max_pkt_size) {
		max_pkt_size = max_pkt_size_req;
	}

	if (ft_is_true(output_in_place)) {
		write_incr = 0U;
	} else {
		write_incr = 1U;
	}

	/*
	 * Grab the dma resource
	 */
	ret = sec_dma_grab(read_host, write_host, FT_TRUE,
			   (local_phys_addr_t *) &txd,
			   (local_phys_addr_t *) &rxd);

	/* Get security context. Update credentials if necessary */
	if (ret == EFTOK) {
		req.ctx_id = 0U;
		req.mac_type = MAC_TYPE_HASH;
		req.hash_algo = hash_algo;
		ret = sa2ul_sec_ctx_auth_create(HOST_ID_HSM, &req,
						0U, &reply);
	}


	if (ret == EFTOK) {
			ret = sa2ul_sec_ctx_update_creds(0U, read_host);
	}
	
	if (ret!=EFTOK){
		while(1);
	}
	/* SA2UL AUTH engine already enabled from init */

	if (ret == EFTOK) {
		id = SA2UL_ENGINE_CODE_AUTHENTICATION_MODULE_P1;
		hash_len = sa2ul_crypto_get_hash_len(hash_algo);
	}

	num_pkts = (tot_len + max_pkt_size - 1U) / max_pkt_size;
	if (num_pkts == ((u32) 0U)) {
		ret = -EFAIL;
	}
	for (i = 0U; (i < num_pkts) && ft_is_ok(ret); i++) {
		ftbool final_pkt = FT_TRUE;
		if (i == (num_pkts - 1U)) {
			final_pkt = FT_TRUE;
			curr_pkt_size = (tot_len - (i * max_pkt_size));
		} else {
			final_pkt = FT_FALSE;
			curr_pkt_size = max_pkt_size;
		}

		ret = udmap_pkt_descr_init_host_rx(&rxd->base,
						   to + (i * write_incr * max_pkt_size),
						   curr_pkt_size);

		if (ret == EFTOK) {
			ret = sa2ul_pkt_descr_setup_epi_tx(&txd->epi,
							   reply.scptr,
							   final_pkt,
							   reply.scid,
							   id, (u16) hash_len);
		}

		if (ret == EFTOK) {
			ret = sa2ul_pkt_descr_setup_psdata_auth(&txd->psdata_tx,
								curr_pkt_size, (u64) tot_len,
								&psdata_len);
		}

		if (ret == EFTOK) {
			ret = sec_dma_init_tx_descr(&txd->base, from + (i * max_pkt_size), curr_pkt_size,
						    FT_TRUE, psdata_len >> 2);
		}

		if (ret == EFTOK) {
			TRACE_info(" ");
			ret = sec_dma_push_pkt();
		}
		if (ret == EFTOK) {
			TRACE_info(" ");
			tmout = calc_sa2ul_timeout(curr_pkt_size);
			ret = sec_dma_wait_for_pkt(tmout);
		}
		if (ret == EFTOK) {
			force_teardown = FT_FALSE;
		} else {
			force_teardown = FT_TRUE;
		}
		
	}

	/* Hash value is returned in the RX descriptor */
	if (ret == EFTOK) {
		ret = sa2ul_pkt_descr_read_result(rxd, curr_pkt_size, hash_len,
						  hash);
	}

	/*
	 * Wipe the security context, dont care about the return value
	 */
	(void) sa2ul_sec_ctx_wipe(0U, HOST_ID_HSM);
	/*
	 * Release the DMA resource
	 */
	tret = sec_dma_release(force_teardown);

	/*
	 * If sa2ul operations are success i.e. ret == EFTOK,
	 * error code is driven by sec dma teardown.
	 *
	 * If sa2ul operations are a failure, return code
	 * is an error code. The error code is -EFAILVERIFY
	 * if sec dma teardown failed or else it is from the
	 * sa2ul operation failure.
	 */
	if ((ret == EFTOK) || (tret == -EFAILVERIFY)) {
		ret = tret;
	}

	if (!ft_is_ok(ret)) {
		/* Issue with Hash operation */
		sec_trace(TRACE_SEC_BOOT, TRACE_SEC_VAL_BOOT_FAIL_HASH_OPN);
	}

	return ret;
}

fterr sa2ul_hash(soc_phys_addr_t to, soc_phys_addr_t from, u32 tot_len,
		 u8 read_host, u8 write_host, u8 hash_algo, u8 *hash)
{
	return sa2ul_hash_core(to, from, tot_len,
			       read_host, write_host, hash_algo, hash,
			       SA2UL_HASH_MAX_PKT_SIZE, FT_FALSE);
}

fterr sa2ul_hash_dmsc(void *ptr, u32 len, u8 hash_algo, u8 *hash)
{
	soc_phys_addr_t phys;
	fterr ret=EFTOK;

	ret = socmem_to_global((local_phys_addr_t) ptr, &phys);

	if (ret == EFTOK) {
	
		//TRACE_info("\r\n MEm Ok");
		/*
		 * Unfortunately, SA2UL cannot work without a copy,
		 * so copy data in-place
		 */
		ret = sa2ul_hash(phys, phys, len, HOST_ID_HSM, HOST_ID_HSM,
				 hash_algo, hash);
	}

	return ret;
}

fterr sa2ul_aes_256_cbc_decrypt_internal(soc_phys_addr_t addr, u32 tot_len, u8 host,
					 const u8 *key, const u8 *iv, u8 key_id)
{
	fterr ret = EFTOK;
	struct sa2ul_enc_ctx_req req;

	req.ctx_id = 0U;
	req.enc_algo = ENC_ALGO_AES;
	req.enc_dir = ENC_DIR_DECRYPT;
	req.enc_mode = ENC_MODE_CBC;
	req.key_id = key_id;
	req.key_len = ENC_KEYLEN_256;

	ret = sa2ul_perform_aes_crypto_opn(req, addr, addr, tot_len, host,
					   key, iv, key_id, (u16) 0U, NULL);

	return ret;
}

fterr sa2ul_aes_256_cbc_decrypt(soc_phys_addr_t addr, u32 tot_len, u8 host,
				const u8 *key, const u8 *iv)
{
	return sa2ul_aes_256_cbc_decrypt_internal(addr, tot_len, host, key, iv,
						  SA2UL_SEC_CTX_KEY_ID_IN_REQ);
}

fterr sa2ul_aes_256_ecb_encrypt_internal(soc_phys_addr_t addr, u32 tot_len, u8 host,
					 const u8 *key, u8 key_id)
{
	fterr ret = EFTOK;
	struct sa2ul_enc_ctx_req req;

	req.ctx_id = 0U;
	req.enc_algo = ENC_ALGO_AES;
	req.enc_dir = ENC_DIR_ENCRYPT;
	req.enc_mode = ENC_MODE_ECB;
	req.key_id = key_id;
	req.key_len = ENC_KEYLEN_256;

	ret = sa2ul_perform_aes_crypto_opn(req, addr, addr, tot_len, host,
					   key, NULL, key_id, (u16) 0U, NULL);

	return ret;
}

fterr sa2ul_perform_aes_crypto_opn(struct sa2ul_enc_ctx_req info, soc_phys_addr_t from_addr, soc_phys_addr_t to_addr, u32 tot_len, u8 host,
				   const u8 *key, const u8 *iv, u8 key_id, u16 psdata_rx_trailer_len,
				   u8 *psdata_rx_trailer_data)
{
	fterr ret = EFTOK, tret;
	struct sa2ul_host_descr_tx *txd;
	struct sa2ul_host_descr_rx *rxd;
	u32 psdata_len, tmout;
	u8 id;
	struct sa2ul_ctx_reply reply;
	ftbool force_teardown = FT_TRUE;
	u32 max_pkt_size = SA2UL_ENC_MAX_PKT_SIZE;
	u32 num_pkts = 0;
	u32 i = 0U;
	u32 curr_pkt_size = 0U;
	u8 ghash[ENC_GCM_GHASH_LEN];
	soc_phys_addr_t pbuf;

	/* Create the security context and populate IV in it */
	if (ret == EFTOK) {
		if (key_id == SA2UL_SEC_CTX_KEY_ID_IN_REQ) {
			(void) memcpy(info.key, key, ENC_MAX_KEY_LEN);
			if (iv != NULL) {
				(void) memcpy(info.iv, iv, ENC_MAX_IV_LEN);
			}
		}

		switch (info.enc_mode) {
		case ENC_MODE_CBC:
		case ENC_MODE_ECB:
			ret = sa2ul_sec_ctx_enc_create(HOST_ID_HSM, &info, 0U,
						       &reply);
			break;
		case ENC_MODE_GCM:

			ret = socmem_to_global((local_phys_addr_t) ghash, &pbuf);
			/* GHASH = AES-ECB(Key, 0) */
			(void) memset(ghash, 0x0, sizeof(ghash));

			/* Perform in-place AES 256 ECB encryption */
			ret = sa2ul_aes_256_ecb_encrypt_internal(pbuf,
								 sizeof(ghash), HOST_ID_HSM,
								 key, key_id);

			ret = sa2ul_sec_ctx_gcm_enc_create(HOST_ID_HSM, &info, 0U,
							   &reply, ghash, tot_len);
			break;
		}

		/* Erase info.key, info.iv etc.. after usage */
		(void) memset((void *) &info, 0, sizeof(info));
	}

	/*
	 * Grab the dma resource
	 */
	if (ret == EFTOK) {
		ret = sec_dma_grab(host, host, FT_TRUE,
				   (local_phys_addr_t *) &txd,
				   (local_phys_addr_t *) &rxd);
	}

	// if (ret == EFTOK) {
	// 	if (host != HOST_ID_TIFS) {
	// 		ret = sa2ul_sec_ctx_update_creds(0U, host);
	// 	}
	// }

	id = SA2UL_ENGINE_CODE_ENCRYPTION_MODULE_P1;

	/* SA2UL AUTH engine already enabled from init */

	/* Determine number of packets necessary for decrypting full buffer */
	num_pkts = (tot_len + max_pkt_size - 1U) / max_pkt_size;
	if (num_pkts == ((u32) 0U)) {
		ret = -EFAIL;
	}
	for (i = 0U; (i < num_pkts) && ft_is_ok(ret); i++) {
		ftbool final_pkt = FT_TRUE;
		if (i == (num_pkts - 1U)) {
			final_pkt = FT_TRUE;
			curr_pkt_size = (tot_len - (i * max_pkt_size));
		} else {
			final_pkt = FT_FALSE;
			curr_pkt_size = max_pkt_size;
		}

		/* Use from_addr of the current block as input. */
		ret = udmap_pkt_descr_init_host_rx(&rxd->base, from_addr + (i * max_pkt_size), curr_pkt_size);

		if (ret == EFTOK) {
			/*
			 * final_pkt flag controls whether the context is evicted from sa2ul
			 * at the end of the packet.
			 */
			ret = sa2ul_pkt_descr_setup_epi_tx(&txd->epi,
							   reply.scptr,
							   final_pkt,
							   reply.scid,
							   id, psdata_rx_trailer_len);
		}

		if (ret == EFTOK) {
			ret = sa2ul_pkt_descr_setup_psdata_enc(&txd->psdata_tx,
							       curr_pkt_size, NULL,
							       NULL, NULL,
							       &psdata_len);
		}

		if (ret == EFTOK) {
			/* Decryption: to_addr is used here */
			ret = sec_dma_init_tx_descr(&txd->base, to_addr + (i * max_pkt_size), curr_pkt_size,
						    FT_TRUE, psdata_len >> 2);
		}

		if (ret == EFTOK) {
			ret = sec_dma_push_pkt();
		}
		if (ret == EFTOK) {
			tmout = calc_sa2ul_timeout(curr_pkt_size);
			ret = sec_dma_wait_for_pkt(tmout);
		}
		if (ret == EFTOK) {
			force_teardown = FT_FALSE;
		} else {
			force_teardown = FT_TRUE;
		}
	}

	if (ret == EFTOK) {
		ret = sa2ul_pkt_descr_read_result(rxd, curr_pkt_size, psdata_rx_trailer_len, psdata_rx_trailer_data);
	}

	/*
	 * Wipe the security context, dont care about the return value
	 */
	(void) sa2ul_sec_ctx_wipe(0U, HOST_ID_TIFS);

	/*
	 * Release the DMA resource
	 */
	tret = sec_dma_release(force_teardown);

	/*
	 * If sa2ul operations are success i.e. ret == EFTOK,
	 * error code is driven by sec dma teardown.
	 *
	 * If sa2ul operations are a failure, return code
	 * is an error code. The error code is -EFAILVERIFY
	 * if sec dma teardown failed or else it is from the
	 * sa2ul operation failure.
	 */
	if ((ret == EFTOK) || (tret == -EFAILVERIFY)) {
		ret = tret;
	}

	return ret;
}
