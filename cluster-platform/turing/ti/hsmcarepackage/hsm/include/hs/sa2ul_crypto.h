/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_crypto.h
 *
 * \brief SA2_UL top-level crypto functions
 */
#ifndef SA2UL_CRYPTO_H_
#define SA2UL_CRYPTO_H_

#include <types/short_types.h>
#include <types/address_types.h>
#include <types/fterr.h>
#include <types/ftbool.h>
#include <crypto_types.h>
#include <sa2ul.h>
#include <sa2ul_sec_ctx.h>

/**
 * \brief Get hash length in bytes
 */
u32 sa2ul_crypto_get_hash_len(u8 hash_algo);

/**
 * \brief Perform a one-shot HASH computation with data transfer
 *
 * \param to Destination soc physical address
 * \param from Source soc physical address
 * \param len Length of data to transfer
 * \param read_host Host ID for read access
 * \param write_host Host ID for write access
 * \param hash_algo Hash algorithm
 * \param hash Hash output value
 *
 * \return EFTOK if successful
 */
fterr sa2ul_hash(soc_phys_addr_t to, soc_phys_addr_t from, u32 len, u8 read_host, u8 write_host, u8 hash_algo, u8 *hash);


/**
 * \brief Perform a one-shot HASH computation with data transfer with configurable packet size
 *
 * \param to Destination soc physical address
 * \param from Source soc physical address
 * \param len Length of data to transfer
 * \param read_host Host ID for read access
 * \param write_host Host ID for write access
 * \param hash_algo Hash algorithm
 * \param hash Hash output value
 * \param max_pkt_size_req Maximum size of DMA packet
 * \param output_in_place whether to reuse the same output buffer for
 *        each packet instead of incrementing the address by packet
 *        size
 *
 * \return EFTOK if successful
 */
fterr sa2ul_hash_core(soc_phys_addr_t to, soc_phys_addr_t from, u32 tot_len, u8 read_host, u8 write_host, u8 hash_algo, u8 *hash, u32 max_pkt_size_req, ftbool output_in_place);

/**
 * \brief Perform a one-shot HASH computation for internal DMSC use
 *
 * \param ptr Pointer to data to be hashed
 * \param len Length of data to transfer
 * \param hash_algo Hash algorithm
 * \param hash Hash output value
 *
 * \return EFTOK if successful
 */
fterr sa2ul_hash_dmsc(void *ptr, u32 len, u8 hash_algo, u8 *hash);

/**
 * \brief Perform a one-shot aes-256-cbc decryption with data transfer
 *        used for boot image decryption. The image decryption is done
 *        in-place.
 *
 * \param addr physical address where the encrypted image is located
 * \param len Length of image
 * \param host Host ID on whose behalf the decryption is done
 * \param key Key to be used for the decryption
 * \param iv IV to be used for the decryption
 *
 * \return EFTOK if successful
 */
fterr sa2ul_aes_256_cbc_decrypt(soc_phys_addr_t addr, u32 len, u8 host, const u8 *key, const u8 *iv);

/**
 * \brief Perform a one-shot aes-256-cbc decryption with data transfer
 *        used for boot image decryption. The image decryption is done
 *        in-place.
 *
 * \param addr physical address where the encrypted image is located
 * \param len Length of image
 * \param host Host ID on whose behalf the decryption is done
 * \param key Key to be used for the decryption
 * \param iv IV to be used for the decryption
 * \param key_id indicate whether key is in the request or if dkek must be used
 *
 * \return EFTOK if successful
 */
fterr sa2ul_aes_256_cbc_decrypt_internal(soc_phys_addr_t addr, u32 tot_len, u8 host, const u8 *key, const u8 *iv, u8 key_id);

/**
 * \brief Perform a aes-256-gcm encryption with data transfer
 *        used for lpm context store.
 *
 * \param from_addr physical address where plain text is situated
 * \param to_addr physical address where output data should be stored
 * \param tot_len Length of plain text
 * \param host Host ID on whose behalf the encryption is done
 * \param key Key to be used for the encryption
 * \param iv IV to be used for the encryption
 * \param key_id indicate whether key is in the request or if dkek must be used
 * \param tag GCM tag obtained after enryption
 *         should match with tag after decryption
 *
 * \return EFTOK if successful
 */
fterr sa2ul_aes_256_gcm_encrypt_internal(soc_phys_addr_t from_addr, soc_phys_addr_t to_addr, u32 tot_len, u8 host, const u8 *key, const u8 *iv, u8 key_id, u8 tag[ENC_GCM_TAG_LEN_BYTES]);

/**
 * \brief Perform a aes-256-gcm decryption with data transfer
 *        used for lpm context restore.
 *
 * \param from_addr physical address where cipher text is situated
 * \param to_addr physical address where output data should be stored
 * \param tot_len Length of cipher text
 * \param host Host ID on whose behalf the decryption is done
 * \param key Key to be used for the decryption
 * \param iv IV to be used for the decryption
 * \param key_id indicate whether key is in the request or if dkek must be used
 * \param tag GCM tag obtained after decryption
 *         should match with tag after encryption
 *
 * \return EFTOK if successful
 */
fterr sa2ul_aes_256_gcm_decrypt_internal(soc_phys_addr_t from_addr, soc_phys_addr_t to_addr, u32 tot_len, u8 host, const u8 *key, const u8 *iv, u8 key_id, u8 tag[ENC_GCM_TAG_LEN_BYTES]);

/**
 * \brief Perform a one-shot aes-256-ecb encryption with data transfer
 *
 * \param addr physical address where the data is located
 * \param tot_len Length of data to be encrypted
 * \param host Host ID on whose behalf the encryption is done
 * \param key Key to be used for the encryption
 * \param key_id indicate whether key is in the request or if dkek must be used
 *
 * \return EFTOK if successful
 */
fterr sa2ul_aes_256_ecb_encrypt_internal(soc_phys_addr_t addr, u32 tot_len, u8 host, const u8 *key, u8 key_id);

/**
 * \brief Perform a aes crypto operation with data transfer
 *
 * \param from_addr physical address where input data is situated
 * \param to_addr physical address where output data should be stored
 * \param tot_len Length of input text
 * \param host Host ID on whose behalf the crypto operation (enc/dec) is done
 * \param key Key to be used for the crypto operation
 * \param iv IV to be used for the crypto operation
 * \param key_id indicate whether key is in the request or if dkek must be used
 * \param tag GCM tag obtained after decryption
 *         should match with tag after encryption
 * \param psdata_rx_trailer_len Length of the ps data in egress packets, this
 *          depends on the algorithm
 * \param psdata_rx_trailer_data Pointer to buffer to store the ps data in egress
 *          packets, this depends on the algorithm
 *
 * \return EFTOK if successful
 */
fterr sa2ul_perform_aes_crypto_opn(struct sa2ul_enc_ctx_req info, soc_phys_addr_t from_addr, soc_phys_addr_t to_addr, u32 tot_len, u8 host, const u8 *key, const u8 *iv, u8 key_id,
				   u16 psdata_rx_trailer_len,
				   u8 *psdata_rx_trailer_data);

#endif /* SA2UL_CRYPTO_H_ */
