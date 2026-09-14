/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2025. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <stdint.h>

#define LOGE(...) printf(__VA_ARGS__)

/**
 * @brief Generates a random encryption key.
 */
int32_t GenerateRandomKey(uint8_t *key_p8, size_t keyLength_u32) {
    int32_t ret = -1;
    if (key_p8 == NULL || keyLength_u32 == 0) {
        LOGE("Sanity check failed in GenerateRandomKey\n");
    } else {
        if (RAND_bytes(key_p8, keyLength_u32) != 1) {
            LOGE("Failed to generate random key\n");
        } else {
            ret = 0;
        }
    }
    return ret;
}

/**
 * @brief Encrypts a plaintext message using AES-256-CBC encryption.
 */
int32_t AesEncrypt(const uint8_t *key_p8, const uint8_t *plaintext_p, size_t plaintextLen_u32, 
                    uint8_t *ciphertext_p, size_t *ciphertextLen_p, const uint8_t *iv_p8) {
    int32_t ret = -1, len = 0;
    size_t totalLen = 0;  
    EVP_CIPHER_CTX *ctx = NULL;
    
    if (key_p8 == NULL || iv_p8 == NULL || plaintext_p == NULL || ciphertext_p == NULL || ciphertextLen_p == NULL) {
        LOGE("Sanity check failed in AesEncrypt\n");
    } else {
        ctx = EVP_CIPHER_CTX_new();
        if (ctx == NULL) {
            LOGE("EVP_CIPHER_CTX_new failed\n");
        } else {
            if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_p8, iv_p8) != 1) {
                LOGE("EVP_EncryptInit_ex failed\n");
            } else if (EVP_EncryptUpdate(ctx, ciphertext_p, &len, plaintext_p, plaintextLen_u32) != 1) {
                LOGE("EVP_EncryptUpdate failed\n");
            } else {
                totalLen = len;
                if (EVP_EncryptFinal_ex(ctx, ciphertext_p + len, &len) != 1) {
                    LOGE("EVP_EncryptFinal_ex failed\n");
                } else {
                    totalLen += len;
                    *ciphertextLen_p = totalLen;
                    ret = 0;
                }
            }
        }
        EVP_CIPHER_CTX_free(ctx);
    }
    return ret;
}

/**
 * @brief Decrypts an AES-encrypted ciphertext back into plaintext.
 */
int32_t AesDecrypt(const uint8_t *key_p8, const uint8_t *ciphertext_p, size_t ciphertextLen, 
                    uint8_t *plaintext_p, size_t *plaintextLen_p, const uint8_t *iv_p8) {
    int32_t ret = -1, len = 0;
    size_t totalLen = 0;  
    EVP_CIPHER_CTX *ctx = NULL;
    
    if (key_p8 == NULL || iv_p8 == NULL || ciphertext_p == NULL || plaintext_p == NULL || plaintextLen_p == NULL) {
        LOGE("Sanity check failed in AesDecrypt\n");
    } else {
        ctx = EVP_CIPHER_CTX_new();
        if (ctx == NULL) {
            LOGE("EVP_CIPHER_CTX_new failed\n");
        } else {
            if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_p8, iv_p8) != 1) {
                LOGE("EVP_DecryptInit_ex failed\n");
            } else if (EVP_DecryptUpdate(ctx, plaintext_p, &len, ciphertext_p, ciphertextLen) != 1) {
                LOGE("EVP_DecryptUpdate failed\n");
            } else {
                totalLen = len;
                if (EVP_DecryptFinal_ex(ctx, plaintext_p + len, &len) != 1) {
                    LOGE("EVP_DecryptFinal_ex failed\n");
                } else {
                    totalLen += len;
                    *plaintextLen_p = totalLen;
                    ret = 0;
                }
            }
        }
        EVP_CIPHER_CTX_free(ctx);
    }
    return ret;
}

/**
 * @brief Computes SHA-256 hash of the given data.
 */
int32_t Sha256Hash(const uint8_t *data_p, size_t dataLen_u32, uint8_t *hash_p, uint32_t *hashLen_p) {
    int32_t ret = -1;
    EVP_MD_CTX *mdctx = NULL;
    
    if (data_p == NULL || dataLen_u32 == 0 || hash_p == NULL || hashLen_p == NULL) {
        LOGE("Sanity check failed in Sha256Hash\n");
    } else {
        mdctx = EVP_MD_CTX_new();
        if (mdctx == NULL) {
            LOGE("EVP_MD_CTX_new failed\n");
        } else {
            if (EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL) != 1) {
                LOGE("EVP_DigestInit_ex failed\n");
            } else if (EVP_DigestUpdate(mdctx, data_p, dataLen_u32) != 1) {
                LOGE("EVP_DigestUpdate failed\n");
            } else if (EVP_DigestFinal_ex(mdctx, hash_p, hashLen_p) != 1) {
                LOGE("EVP_DigestFinal_ex failed\n");
            } else {
                ret = 0;
            }
        }
        EVP_MD_CTX_free(mdctx);
    }
    return ret;
}
