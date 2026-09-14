/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  optee_securestorage_crypto.c                         *
*  Module Short Name :  Security manager test service                        *
*  Description       :  This file contains test service to validate the optee*
*                      security mananger library                             *
*                       		                                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* \authors
*          Name                     | CDSID     | Location                 | *
*          ------------------------ | --------- | ------------------------ | *
*          Vignesh Pandian          | vpandia1  | VTSC, Coimbatore, India  | *
* ---------------------------------------------------------------------------* 
*                                                                            *
******************************************************************************/

#include "SecurestorageCrypto_ca.h"
#include "otp_ca_ta.h"

#define SYMMETRIC_KEY_SIZE 16
#define DATASIZE 16
#define CIPHERBUFSIZE 128

#define SIZE_1K_BYTE 1024
#define IV_SIZE      16

#define IV_SIZE_GCM               12                  // AES-GCM recommended IV size
#define AES128_BLOCK_SIZE_BYTES    16U
#ifndef AES_BLOCK_SIZE
#define AES_BLOCK_SIZE 16
#endif
/******************************************************************************
 * Decryption Configuration
 *
 * Three types of AES decryption**:
 *   1. AES-128-CBC
 *   2. AES-GCM
 *   3. AES-ECB
 *
 *  You may enable **one macro per decryption type** (e.g., one for CBC,
 *    one for GCM, and one for ECB) to run them all in the same build.
 *
 *  However, within **each type**, you must **only enable ONE mode** of use:
 *    - Either the single-step API
 *    - Or the start-update-finish API (for streaming or large data)
 *    - Or the file-based variant of start-update-finish
 *
 *  Enabling more than one macro in the same group (CBC, GCM, or ECB)
 *    will cause undefined behavior or conflicts.
 *
 ******************************************************************************/

/*** AES-128-CBC Decryption Tests ***/

// Uncomment to test 32-byte AES-128-CBC decryption
//#define ENABLE_DECRYPT_32_BYTES

// Uncomment to decrypt a larger AES-128-CBC encrypted file
#define ENABLE_DECRYPT_LARGE_DATA


/*** AES-GCM Decryption Tests ***/

// Uncomment to test 32-byte AES-GCM decryption
// #define ENABLE_DECRYPT_GCM

// Uncomment to test AES-GCM using start-update-final API
// #define ENABLE_DECRYPT_GCM_START_UPDATE_FINAL

// Uncomment to decrypt a file using AES-GCM with start-update-final API
#define ENABLE_DECRYPT_GCM_START_UPDATE_FINAL_FILE


/*** AES-ECB Decryption Tests ***/

// Uncomment to test 32-byte AES-ECB decryption
// #define ENABLE_DECRYPT_ECB

// Uncomment to test AES-ECB using start-update-final API
// #define ENABLE_DECRYPT_ECB_START_UPDATE_FINAL

// Uncomment to decrypt a file using AES-ECB with start-update-final API
#define ENABLE_DECRYPT_ECB_START_UPDATE_FINAL_FILE

/******************************************************************************
 * WARNING:
 * Ensure that only **one** macro is uncommented at any time in each section.
 ******************************************************************************/

static void usage(int argc, char *argv[])
{
	const char *pname = "TI_Crypto";

	if (argc)
		pname = argv[0];

	fprintf(stderr, "usage: %s <requested operation>\n", pname);
	fprintf(stderr, "Operations can be requested in : %s are storekey ,decryptfile, Digest, encryptstringwithpad, decryptstringwithpad, encryptstringwithpad_gcm, decryptstringwithpad_gcm, ECB_encryptstringwopad, ECB_decryptstringwopad, encryptstringwopad, decryptstringwopad ,signverify2k, signverify3k, ecdsaverify, ecdsahash, signgenerate, keygen, certverify, keycnt_rev, cmac_gen, cmac_verify, cmac_gen_startupdatefinish, cmac_verify_startupdatefinish \n", pname);
	exit(1);
}

static void get_args(int argc, char *argv[], void **request)
{

	if (argc !=2) {
		warnx("Unexpected number of arguments %d (expected 2)",
		      argc - 1);
		usage(argc, argv);
	}

	*request = argv[1];
}

TEEC_Result securestorage(struct TEE_resource_ctx *ctx){

    TEEC_Result res;
    static uint8_t ipsec_pem_data[] = {
    0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x42, 0x45, 0x47, 0x49, 0x4e, 0x20, 0x45,
    0x43, 0x20, 0x50, 0x52, 0x49, 0x56, 0x41, 0x54, 0x45, 0x20, 0x4b, 0x45,
    0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a, 0x4d, 0x49, 0x47, 0x6b, 0x41,
    0x67, 0x45, 0x42, 0x42, 0x44, 0x44, 0x41, 0x7a, 0x64, 0x4b, 0x6a, 0x71,
    0x41, 0x58, 0x48, 0x4b, 0x4f, 0x4a, 0x78, 0x55, 0x70, 0x46, 0x69, 0x66,
    0x63, 0x4e, 0x33, 0x63, 0x6b, 0x32, 0x73, 0x54, 0x43, 0x6b, 0x67, 0x6e,
    0x4f, 0x49, 0x50, 0x73, 0x4a, 0x61, 0x4a, 0x33, 0x71, 0x6d, 0x7a, 0x70,
    0x45, 0x65, 0x56, 0x46, 0x67, 0x63, 0x4a, 0x64, 0x65, 0x6a, 0x4c, 0x0a,
    0x49, 0x61, 0x50, 0x35, 0x56, 0x36, 0x55, 0x75, 0x61, 0x6e, 0x79, 0x67,
    0x42, 0x77, 0x59, 0x46, 0x4b, 0x34, 0x45, 0x45, 0x41, 0x43, 0x4b, 0x68,
    0x5a, 0x41, 0x4e, 0x69, 0x41, 0x41, 0x52, 0x48, 0x67, 0x61, 0x6c, 0x59,
    0x6b, 0x2b, 0x63, 0x6f, 0x4d, 0x2f, 0x64, 0x33, 0x59, 0x33, 0x6f, 0x6c,
    0x37, 0x41, 0x45, 0x47, 0x50, 0x32, 0x65, 0x59, 0x69, 0x2b, 0x2b, 0x34,
    0x2b, 0x78, 0x55, 0x6f, 0x0a, 0x6e, 0x59, 0x55, 0x68, 0x5a, 0x33, 0x65,
    0x41, 0x6e, 0x6f, 0x4a, 0x70, 0x31, 0x63, 0x4a, 0x37, 0x2b, 0x56, 0x32,
    0x58, 0x67, 0x31, 0x65, 0x72, 0x71, 0x6a, 0x45, 0x67, 0x6f, 0x47, 0x7a,
    0x33, 0x2f, 0x45, 0x44, 0x52, 0x6e, 0x31, 0x4f, 0x7a, 0x74, 0x59, 0x4d,
    0x6f, 0x32, 0x37, 0x46, 0x4f, 0x57, 0x69, 0x36, 0x2f, 0x65, 0x33, 0x4b,
    0x53, 0x38, 0x57, 0x59, 0x33, 0x49, 0x49, 0x79, 0x51, 0x0a, 0x54, 0x44,
    0x54, 0x55, 0x61, 0x6f, 0x44, 0x46, 0x74, 0x4b, 0x65, 0x50, 0x77, 0x36,
    0x4a, 0x71, 0x66, 0x51, 0x75, 0x54, 0x48, 0x32, 0x34, 0x63, 0x44, 0x32,
    0x38, 0x77, 0x31, 0x2b, 0x77, 0x3d, 0x0a, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
    0x45, 0x4e, 0x44, 0x20, 0x45, 0x43, 0x20, 0x50, 0x52, 0x49, 0x56, 0x41,
    0x54, 0x45, 0x20, 0x4b, 0x45, 0x59, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x0a
    };
    static const uint32_t ipsec_pem_len = sizeof(ipsec_pem_data);
    char IPSEC_KEY_ID[10] = "Secure";
    uint32_t IPSEC_KEY_ID_LEN = strlen(IPSEC_KEY_ID);

    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);
    uint8_t enc_m1[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11};
    uint8_t enc_m2[32] = {0xA7, 0x3D, 0x02, 0x0C, 0xC4, 0xD7, 0x82, 0x5C,
                          0x93, 0x47, 0xD3, 0x01, 0xBE, 0x27, 0xE2, 0x04,
                          0x07, 0xA5, 0xD7, 0x94, 0x15, 0x44, 0xA8, 0x4E,
                          0x1B, 0xFC, 0xE8, 0x15, 0xF8, 0x5B, 0xE7, 0x90};
    uint8_t enc_m3[16] = {0x2E, 0xF3, 0x94, 0x63, 0x71, 0x30, 0x7A, 0x52,
                          0xBA, 0xAD, 0xD6, 0x57, 0xBD, 0x0E, 0x9A, 0x20};

    ts_pointerType m1_data    = { .data_U8P = enc_m1,  .length_U32 = sizeof(enc_m1) };
    ts_pointerType m2_data    = { .data_U8P = enc_m2,  .length_U32 = sizeof(enc_m2) };
    ts_pointerType m3_data    = { .data_U8P = enc_m3,  .length_U32 = sizeof(enc_m3) };

    res = SecureStorageCreateAndStore_CA(ctx, keyid, keyid_size, &m1_data, &m2_data, &m3_data);
    if (res == TEEC_SUCCESS) {
        printf("\nKey stored successfully (%s) as object 2\n",keyid);
    }
    else {
        printf("\nFailed to store key , either blob exist 0x%08x", res);
    }
    /*  Store IPsec PEM key */
    if (res == TEEC_SUCCESS) {
        res = Privatesecurestorage_opteeapi(ctx, ipsec_pem_data, ipsec_pem_len,
                                                IPSEC_KEY_ID, IPSEC_KEY_ID_LEN);
        if (res == TEEC_SUCCESS) {
            printf("\nIPsec PEM key stored in secure storage\n");
            /* Retrieve to /tmp (writable by all) */
            res = RetrieveIpsecKeyFromOPTEE(ctx, "/persist/ipsec_key.pem",
                                                IPSEC_KEY_ID, IPSEC_KEY_ID_LEN);
            if (res == TEEC_SUCCESS) {
                printf("\nIPsec key saved to /persist/ipsec_key.pem\n");
            } else {
                printf("\nFailed to retrieve IPsec key: 0x%08x\n", res);
            }
        } else {
            printf("\nFailed to store IPsec key: 0x%08x\n", res);
        }
    } else {
        /*for misra*/
    }

    return res;
}

TEEC_Result Aes128Cbcfiledecryption(struct TEE_resource_ctx *ctx) {

    TEEC_Result res = 0;
    uint8_t l_InitialVectorPtr_pU8[16]  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                          0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    uint8_t l_InitialVectorLength_pU8   = 16;
    FILE *l_inputFile_SP = NULL, *l_outputFile_SP = NULL;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    l_inputFile_SP = fopen("/tmp/Toyota-FDC-7XXD-Sw-package.bin", "rb");
    if (l_inputFile_SP != NULL)
    {
        l_outputFile_SP = fopen("/tmp/Toyota-FDC-sw.iso", "wb");
	    if(l_outputFile_SP != NULL)
		{
            res = SecurityManagerAes128CbcDecryptionfile(ctx, keyid, keyid_size, l_InitialVectorPtr_pU8, l_InitialVectorLength_pU8,
            l_inputFile_SP, l_outputFile_SP);
            if (res == TEEC_SUCCESS) {
                printf("\nData decrypted, image stored in /ota_cache/Toyota-FDC-sw.iso\n");
            }
            else {
                printf("\nFile decryption failed 0x%08x", res);
            }
            fclose(l_outputFile_SP);
        }
    }

    return res;
}

TEEC_Result SHA256(struct TEE_resource_ctx *ctx) {

    TEEC_Result res;
    uint8_t data_to_cal_hash[21] = {"Hi hello from visteon"};
    uint8_t Digest[32]       = {0};
    ts_pointerType Plaintext_S;
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = 21;
    ts_pointerType Digest_S;
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 32;
    uint32_t         loopCounter_U32; /** Variable for printf */

    res = Crypto_SHA256(ctx, &Plaintext_S, &Digest_S);
    if (res == TEEC_SUCCESS) {
        printf("\nDigest calculate : ");
        for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
            printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\nDigest calculation failed 0x%08x", res);
    }
    return res;
}

#define DATA_SIZE 4096
#define DATA_SIZE_CIPHER 1024
uint8_t data_to_cal_hash[DATA_SIZE] = {0};
uint8_t data_to_decrypt[DATA_SIZE_CIPHER] = {0};

TEEC_Result SHA256MultiCall(struct TEE_resource_ctx *ctx) {

    TEEC_Result res;
    for (uint32_t i = 0; i < DATA_SIZE; i++) {
        data_to_cal_hash[i] = (uint8_t)(i % 256);
    }
    uint8_t Digest[32]       = {0};
    ts_pointerType Plaintext_S;
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = DATA_SIZE;
    ts_pointerType Digest_S;
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 32;
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */

    res = Crypto_SHA256_Start(ctx);
    if (res == TEEC_SUCCESS) {
        for (loopCounter_U32 = 0; loopCounter_U32 < DATA_SIZE; loopCounter_U32+=CHUNK_SIZE ) {
            res = Crypto_SHA256_Update(ctx, &Plaintext_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation update failed 0x%08x", res);
                return res;
            }
        }
        res = Crypto_SHA256_Final(ctx, &Digest_S);
        if (res != TEEC_SUCCESS){
            printf("\n Digest calculation Final failed 0x%08x", res);
            return res;
        }
        else {
            printf("\nDigest calculate : ");
            for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nDigest calculation start failed 0x%08x", res);
    }
    
    return res;
}

TEEC_Result Aes128Cbcencryptionwithpkcs7pad(struct TEE_resource_ctx *ctx) {

    TEEC_Result res;
    uint8_t aesCbcPlain_pU8[30] = {"hello this string of 30 bytes!"}; /** plain text */
    ts_pointerType aesCbcPlaintext_S; /** CBC plain text in structure format */
    aesCbcPlaintext_S.data_U8P   = &aesCbcPlain_pU8[0];
    aesCbcPlaintext_S.length_U32 = 30u;
    uint8_t aesCbcIv_pU8[16]        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    ts_pointerType aesCbcIv_S;
    aesCbcIv_S.data_U8P             = &aesCbcIv_pU8[0];
    aesCbcIv_S.length_U32           = 16u;
    uint8_t aesCbcCipherOut_pU8[32] = {0};
    ts_pointerType aesCbcCipher_S;
    aesCbcCipher_S.data_U8P         = &aesCbcCipherOut_pU8[0];
    aesCbcCipher_S.length_U32       = 32u;
    uint32_t         loopCounter_U32; /** Variable for printf */
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("\n data to be : ");
    for (loopCounter_U32=0; loopCounter_U32 < aesCbcPlaintext_S.length_U32; loopCounter_U32++) {
        printf("0x%x ",aesCbcPlaintext_S.data_U8P[loopCounter_U32]);
    }
    printf("\n");
    res = Crypto_AES128CbcEncryptionWithPkcs7Pad(ctx, keyid, keyid_size, &aesCbcPlaintext_S, &aesCbcIv_S, &aesCbcCipher_S);
    if (res == TEEC_SUCCESS) {
        printf("\n Encrypted data with padding : ");
        for (loopCounter_U32 = 0; loopCounter_U32 < aesCbcCipher_S.length_U32; loopCounter_U32++)
        {
            printf("0x%2x, ", aesCbcCipher_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\nFile decryption failed 0x%08x", res);
    }

    return res;
}

#ifdef ENABLE_DECRYPT_32_BYTES

TEEC_Result Aes128Cbcdecryptionwithpkcs7pad(struct TEE_resource_ctx *ctx) {

    TEEC_Result res = TEEC_SUCCESS;

    uint8_t iv[AES_BLOCK_SIZE] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    ts_pointerType iv_s;

    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = (uint32_t)strlen(keyid);

    uint8_t expected_plaintext[30] = "hello this string of 30 bytes!";
    uint8_t ciphertext[32] = {
        0x20, 0xe8, 0x9c, 0xc6, 0xb0, 0xe1, 0x8f, 0x23,
        0xb1, 0x2e, 0x20, 0xa8, 0x4c, 0x09, 0x14, 0x01,
        0x54, 0x28, 0x7a, 0x63, 0x1a, 0xe4, 0x9c, 0xc7,
        0x3b, 0x46, 0x6a, 0x4a, 0x4c, 0x15, 0xac, 0xc6
    };

    uint8_t plain1[16] = {0};
    uint8_t plain2[16] = {0};
    uint8_t final_plain[AES_BLOCK_SIZE] = {0};
    uint8_t full_plain[32] = {0};

    ts_pointerType cipher1, plain1_s;
    ts_pointerType cipher2, plain2_s;
    ts_pointerType final_s;

    uint8_t match = 0U;
    uint32_t i = 0U;

    iv_s.data_U8P = iv;
    iv_s.length_U32 = AES_BLOCK_SIZE;

    if (ctx == NULL)
    {
        printf("\n[TEST] Context is NULL\n");
        res = TEEC_ERROR_BAD_PARAMETERS;
    }
    else
    {
        res = Crypto_AES128CBC_Decrypt_Start(ctx, keyid, keyid_size, &iv_s);
        if (res != TEEC_SUCCESS)
        {
            printf("\nDecrypt_Start failed: 0x%08x\n", res);
        }
        else
        {
            /* Process first 16 bytes */
            cipher1.data_U8P = &ciphertext[0];
            cipher1.length_U32 = 16U;
            plain1_s.data_U8P = plain1;
            plain1_s.length_U32 = 16U;

            res = Crypto_AES128CBC_Decrypt_Update(ctx, &cipher1, &plain1_s);
            if (res != TEEC_SUCCESS)
            {
                printf("\nFirst Decrypt_Update failed: 0x%08x\n", res);
            }
            else
            {
                /* Process second 16 bytes */
                cipher2.data_U8P = &ciphertext[16];
                cipher2.length_U32 = 16U;
                plain2_s.data_U8P = plain2;
                plain2_s.length_U32 = 16U;

                res = Crypto_AES128CBC_Decrypt_Update(ctx, &cipher2, &plain2_s);
                if (res != TEEC_SUCCESS)
                {
                    printf("\nSecond Decrypt_Update failed: 0x%08x\n", res);
                }
                else
                {
                    /* Get unpadded last block */
                    final_s.data_U8P = final_plain;
                    final_s.length_U32 = AES_BLOCK_SIZE;

                    res = Crypto_AES128CBC_Decrypt_Final(ctx, &final_s);
                    if (res != TEEC_SUCCESS)
                    {
                        printf("\nDecrypt_Final failed: 0x%08x\n", res);
                    }
                    else
                    {
                        memcpy(&full_plain[0], plain1, 16);
                        memcpy(&full_plain[16], plain2, 16 - AES_BLOCK_SIZE); /* 0 bytes */
                        if (final_s.length_U32 > 0U)
                        {
                            memcpy(&full_plain[16], final_plain, final_s.length_U32);
                        }
                        else
                        {
                            /* for MISRA */
                        }

                        if (final_s.length_U32 == 14U)
                        {
                            match = 1U;
                            for (i = 0U; i < 30U; i++)
                            {
                                if (full_plain[i] != expected_plaintext[i])
                                {
                                    match = 0U;
                                    break;
                                }
                                else
                                {
                                    /* for MISRA */
                                }
                            }

                            if (match == 1U)
                            {
                                printf("\nDecrypted data matches expected plaintext.\n");
                                printf("Decrypted data (30 bytes): ");
                                for (i = 0U; i < 30U; i++)
                                {
                                    printf("0x%02x ", full_plain[i]);
                                }
                                printf("\n");
                            }
                            else
                            {
                                printf("\nDecryption content mismatch\n");
                                res = TEEC_ERROR_BAD_STATE;
                            }
                        }
                        else
                        {
                            printf("\nUnexpected final block size: %u\n", final_s.length_U32);
                            res = TEEC_ERROR_BAD_STATE;
                        }
                    }
                }
            }
        }
    }

    return res;
}

#endif

TEEC_Result Aes128GcmEncryption(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    uint8_t gcm_plaintext_pU8[30] = {"hello this string of 30 bytes!"};
    ts_pointerType gcm_plaintext_S;
    gcm_plaintext_S.data_U8P   = &gcm_plaintext_pU8[0];
    gcm_plaintext_S.length_U32 = 30u;

    uint8_t gcm_iv_pU8[12] = {0xa1, 0xb2, 0xc3, 0xd4, 0xe5, 0xf6,
                              0x00, 0x11, 0x22, 0x33, 0x44, 0x55};  // 96-bit IV for GCM
    ts_pointerType gcm_iv_S;
    gcm_iv_S.data_U8P   = gcm_iv_pU8;
    gcm_iv_S.length_U32 = 12u;

    uint8_t gcm_cipherOut_pU8[30] = {0}; // same length as plaintext
    ts_pointerType gcm_cipher_S;
    gcm_cipher_S.data_U8P   = gcm_cipherOut_pU8;
    gcm_cipher_S.length_U32 = 30u;

    uint8_t gcm_tag_pU8[16] = {0};  // 128-bit tag
    ts_pointerType gcm_tag_S;
    gcm_tag_S.data_U8P   = gcm_tag_pU8;
    gcm_tag_S.length_U32 = 16u;

    char keyid[] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("Plaintext data : ");
    for (uint32_t i = 0; i < gcm_plaintext_S.length_U32; i++) {
        printf("0x%x ", gcm_plaintext_S.data_U8P[i]);
    }
    printf("\n");

    res = Crypto_AES128GcmEncrypt(ctx, keyid, keyid_size,
                                  &gcm_plaintext_S, &gcm_iv_S,
                                  NULL,  // AAD is NULL
                                  &gcm_cipher_S, &gcm_tag_S);
    if (res == TEEC_SUCCESS) {
        printf("Encrypted data : ");
        for (uint32_t i = 0; i < gcm_cipher_S.length_U32; i++) {
            printf("0x%02x, ", gcm_cipher_S.data_U8P[i]);
        }
        printf("\n");

        printf("Authentication Tag : ");
        for (uint32_t i = 0; i < gcm_tag_S.length_U32; i++) {
            printf("0x%02x, ", gcm_tag_S.data_U8P[i]);
        }
        printf("\n");
    } else {
        printf("Encryption failed: 0x%08x", res);
    }

    return res;
}

#ifdef ENABLE_DECRYPT_GCM
TEEC_Result Aes128GcmDecryption(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint8_t aesGcmPlainOut_pU8[30] = {0};
    ts_pointerType aesGcmPlaintextOut_S;
    aesGcmPlaintextOut_S.data_U8P   = &aesGcmPlainOut_pU8[0];
    aesGcmPlaintextOut_S.length_U32 = 30u;

    uint8_t aesGcmIv_pU8[12] = {0xa1, 0xb2, 0xc3, 0xd4, 0xe5, 0xf6,
                              0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    ts_pointerType aesGcmIv_S;
    aesGcmIv_S.data_U8P   = &aesGcmIv_pU8[0];
    aesGcmIv_S.length_U32 = 12u;

    uint8_t aesGcmCipher_pU8[30] = {0x5a, 0x45, 0x7d, 0xc8, 0x82, 0x53, 0xbb, 0xe6,
                                    0xc1, 0x1c, 0x90, 0x96, 0x09, 0x59, 0x7f, 0xcc,
                                    0x71, 0x5d, 0xbc, 0xa6, 0x54, 0xaf, 0xce, 0xab,
                                    0xd0, 0x3c, 0x13, 0x50, 0xea, 0x57};
    ts_pointerType aesGcmCipher_S;
    aesGcmCipher_S.data_U8P   = &aesGcmCipher_pU8[0];
    aesGcmCipher_S.length_U32 = 30u;

    uint8_t aesGcmTag_pU8[16] = {0x46, 0x63, 0xb3, 0x70, 0xf2, 0xf9, 0x2c, 0xff,
                                0xa4, 0xb0, 0x78, 0xef, 0xe0, 0x60, 0xe7, 0x3c};
    ts_pointerType aesGcmTag_S;
    aesGcmTag_S.data_U8P   = &aesGcmTag_pU8[0];
    aesGcmTag_S.length_U32 = 16u;

    uint32_t loopCounter_U32;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    res = Crypto_AES128GcmDecrypt(ctx, keyid, keyid_size, &aesGcmCipher_S, &aesGcmIv_S, &aesGcmTag_S, &aesGcmPlaintextOut_S);
    if (res == TEEC_SUCCESS)
    {
        printf("\nDecrypted GCM Data : ");
        for (loopCounter_U32 = 0; loopCounter_U32 < aesGcmPlaintextOut_S.length_U32; loopCounter_U32++)
        {
            printf("0x%x ", aesGcmPlaintextOut_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else
    {
        printf("\nDecryption failed: 0x%08x", res);
    }

    return res;
}
#endif

#ifdef ENABLE_DECRYPT_GCM_START_UPDATE_FINAL

TEEC_Result Aes128GcmDecryption(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res = TEEC_SUCCESS;
    uint32_t loopCounter_U32 = 0;

    /** GCM IV */
    uint8_t aesGcmIv_pU8[12] = { 0xa1, 0xb2, 0xc3, 0xd4, 0xe5, 0xf6, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };
    ts_pointerType aesGcmIv_S = {
        .data_U8P = &aesGcmIv_pU8[0],
        .length_U32 = sizeof(aesGcmIv_pU8)
    };

    /** GCM ciphertext (input) */
    uint8_t aesGcmCipher_pU8[30] = {
        0x5a, 0x45, 0x7d, 0xc8, 0x82, 0x53, 0xbb, 0xe6,
        0xc1, 0x1c, 0x90, 0x96, 0x09, 0x59, 0x7f, 0xcc,
        0x71, 0x5d, 0xbc, 0xa6, 0x54, 0xaf, 0xce, 0xab,
        0xd0, 0x3c, 0x13, 0x50, 0xea, 0x57
    };
    ts_pointerType aesGcmCipher_S = {
        .data_U8P = &aesGcmCipher_pU8[0],
        .length_U32 = sizeof(aesGcmCipher_pU8)
    };

    /** GCM Tag */
    uint8_t aesGcmTag_pU8[16] = {
        0x46, 0x63, 0xb3, 0x70, 0xf2, 0xf9, 0x2c, 0xff,
        0xa4, 0xb0, 0x78, 0xef, 0xe0, 0x60, 0xe7, 0x3c
    };
    ts_pointerType aesGcmTag_S = {
        .data_U8P = &aesGcmTag_pU8[0],
        .length_U32 = sizeof(aesGcmTag_pU8)
    };

    /** Decryption output buffer */
    uint8_t aesGcmPlainOut_pU8[30] = {0};
    ts_pointerType aesGcmPlaintextOut_S = {
        .data_U8P = &aesGcmPlainOut_pU8[0],
        .length_U32 = sizeof(aesGcmPlainOut_pU8)
    };

    /** Key ID */
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    /** Start decryption context */
    if ((res = Crypto_AES128GCM_Decrypt_Start(ctx, keyid, keyid_size, &aesGcmIv_S)) == TEEC_SUCCESS)
    {
        /** Step 2: Update Ciphertext */
        if ((res = Crypto_AES128GCM_Decrypt_Update(ctx, &aesGcmCipher_S, &aesGcmPlaintextOut_S)) == TEEC_SUCCESS)
        {
            aesGcmPlaintextOut_S.length_U32 = sizeof(aesGcmPlainOut_pU8);
            /** Step 3: Finalize with Authentication Tag */
            if ((res = Crypto_AES128GCM_Decrypt_Final(ctx,  &aesGcmPlaintextOut_S, &aesGcmTag_S)) == TEEC_SUCCESS)
            {
                /** Success: Dump decrypted output */
                printf("\nAES GCM Decryption successful.\nDecrypted Output: ");
                for (loopCounter_U32 = 0U; loopCounter_U32 < aesGcmPlaintextOut_S.length_U32; loopCounter_U32++)
                {
                    printf("0x%02X ", aesGcmPlaintextOut_S.data_U8P[loopCounter_U32]);
                }
                printf("\n");
            }
            else
            {
                printf("AES GCM Decrypt Final failed (tag mismatch?): 0x%08X\n", res);
            }
        }
        else
        {
            printf("AES GCM Decrypt Update failed: 0x%08X\n", res);
        }
    }
    else
    {
        printf("AES GCM Decrypt Start failed: 0x%08X\n", res);
    }

    return res;
}

#endif

#ifdef ENABLE_DECRYPT_GCM_START_UPDATE_FINAL_FILE

TEEC_Result Aes128GcmDecryption(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res                                    = TEEC_SUCCESS;

    uint8_t l_Iv_U8P[IV_SIZE_GCM]                          = {0}; /* iv size has been declared 12 or 16 so check it before proceeding*/
    uint8_t l_CiphertextPtr_pU8[DATA_SIZE_CIPHER]      = {0};
    uint8_t l_PlaintextPtr_pU8[DATA_SIZE_CIPHER]       = {0};
    uint8_t l_DecryptFinalOut_pU8[DATA_SIZE_CIPHER]    = {0};
    uint8_t l_Tag_U8P[AES_GCM_TAG_SIZE]                = {0};

    ts_pointerType aesGcmIv_S                          = { .data_U8P = l_Iv_U8P, .length_U32 = IV_SIZE_GCM };
    ts_pointerType aesGcmCiphertext_S                  = { .data_U8P = l_CiphertextPtr_pU8, .length_U32 = 0U };
    ts_pointerType aesGcmPlaintext_S                   = { .data_U8P = l_PlaintextPtr_pU8, .length_U32 = DATA_SIZE_CIPHER };
    ts_pointerType aesGcmFinalPlaintext_S              = { .data_U8P = l_DecryptFinalOut_pU8, .length_U32 = DATA_SIZE_CIPHER };
    ts_pointerType aesGcmTag_S                         = { .data_U8P = l_Tag_U8P, .length_U32 = AES_GCM_TAG_SIZE };

    FILE *l_inputFile_SP                               = NULL;
    FILE *l_outputFile_SP                              = NULL;
    FILE *l_ivFile_SP                                  = NULL;
    FILE *l_tagFile_SP                                 = NULL;

    size_t bytes_read                                  = 0U;
    size_t bytes_write                                 = 0U;
    size_t iterator                                    = 0U;

    char keyid[15]                                     = "Secure_blob";
    uint32_t keyid_len                                 = (uint32_t)strlen(keyid);

    // Open input binary
    l_inputFile_SP = fopen("/tmp/encrypted_system_partition.bin", "rb");
    if (l_inputFile_SP == NULL) {
        printf(" Failed to open encrypted input file\n");
        res = TEEC_ERROR_GENERIC;
    }
    // Open output file
    if (res == TEEC_SUCCESS) {
        l_outputFile_SP = fopen("/tmp/decrypted_system_partition.bin", "wb");
        if (l_outputFile_SP == NULL) {
            printf(" Failed to open decrypted output file\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    // Open IV and TAG files
    if (res == TEEC_SUCCESS) {
        l_ivFile_SP = fopen("/tmp/encrypted_system_partition.iv", "rb");
        l_tagFile_SP = fopen("/tmp/encrypted_system_partition.tag", "rb");

        if ((l_ivFile_SP == NULL) || (l_tagFile_SP == NULL)) {
            printf(" Failed to open IV or TAG file\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    // Read IV and TAG values
    if (res == TEEC_SUCCESS) {
        if ((fread(l_Iv_U8P, 1U, IV_SIZE_GCM, l_ivFile_SP) != IV_SIZE_GCM) ||
            (fread(l_Tag_U8P, 1U, AES_GCM_TAG_SIZE, l_tagFile_SP) != AES_GCM_TAG_SIZE)) {
            printf(" Failed to read IV or TAG\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    // Close IV and TAG files after read
    if (l_ivFile_SP != NULL) {
        fclose(l_ivFile_SP);
        l_ivFile_SP = NULL;
    }
    if (l_tagFile_SP != NULL) {
        fclose(l_tagFile_SP);
        l_tagFile_SP = NULL;
    }
    // Print IV and TAG for debugging
    if (res == TEEC_SUCCESS) {
        printf("\n IV  : ");
        for (iterator = 0U; iterator < IV_SIZE_GCM; iterator++) {
            printf("0x%02X ", l_Iv_U8P[iterator]);
        }
        printf("\n TAG : ");
        for (iterator = 0U; iterator < AES_GCM_TAG_SIZE; iterator++) {
            printf("0x%02X ", l_Tag_U8P[iterator]);
        }
        printf("\n");
    }
    // Begin Decryption Start
    if (res == TEEC_SUCCESS) {
        res = Crypto_AES128GCM_Decrypt_Start(ctx, keyid, keyid_len, &aesGcmIv_S);
        if (res != TEEC_SUCCESS) {
            printf(" Failed to start GCM decryption: 0x%08X\n", res);
        }
    }
    // Decrypt All Chunks via Update
    while ((res == TEEC_SUCCESS) &&
           ((bytes_read = fread(l_CiphertextPtr_pU8, 1U, DATA_SIZE_CIPHER, l_inputFile_SP)) > 0U)) {

        aesGcmCiphertext_S.length_U32 = (uint32_t)bytes_read;
        res = Crypto_AES128GCM_Decrypt_Update(ctx, &aesGcmCiphertext_S, &aesGcmPlaintext_S);
        if (res != TEEC_SUCCESS) {
            printf(" GCM Decrypt_Update failed: 0x%08X\n", res);
        }
        if (res == TEEC_SUCCESS) {
            bytes_write = fwrite(l_PlaintextPtr_pU8, 1U, aesGcmPlaintext_S.length_U32, l_outputFile_SP);
            if (bytes_write != aesGcmPlaintext_S.length_U32) {
                printf(" Failed to write chunk\n");
                res = TEEC_ERROR_GENERIC;
            }
        }
    }
    // Final Authentication Tag Verification
    if (res == TEEC_SUCCESS) {
        res = Crypto_AES128GCM_Decrypt_Final(ctx, &aesGcmFinalPlaintext_S, &aesGcmTag_S);
        if (res != TEEC_SUCCESS) {
            printf(" AES128 GCM Decrypt_Final failed: 0x%08X\n", res);
        }
    }
    // Final chunk write
    if ((res == TEEC_SUCCESS) && (aesGcmFinalPlaintext_S.length_U32 > 0U)) {
        bytes_write = fwrite(l_DecryptFinalOut_pU8, 1U, aesGcmFinalPlaintext_S.length_U32, l_outputFile_SP);
        if (bytes_write != aesGcmFinalPlaintext_S.length_U32) {
            printf(" Final chunk write failed\n");
            res = TEEC_ERROR_GENERIC;
        }
    }
    // Final success message
    if (res == TEEC_SUCCESS) {
        printf(" AES128 GCM Decryption completed successfully.\n");
    }
    // Clean up open files
    if (l_inputFile_SP != NULL) {
        fclose(l_inputFile_SP);
        l_inputFile_SP = NULL;
    }
    if (l_outputFile_SP != NULL) {
        fclose(l_outputFile_SP);
        l_outputFile_SP = NULL;
    }

    return res;
}
#endif

TEEC_Result Aes128Ecbencryptionwopad(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint32_t    loopCounter_U32;
    char        keyid[]          = "Secure_blob";
    uint32_t    keyid_size       = strlen(keyid); 

    uint8_t aesEcbPlain_pU8[32] = {"hello this string of 32 bytes!!"};
    ts_pointerType aesEcbPlaintext_S;
    aesEcbPlaintext_S.data_U8P      = &aesEcbPlain_pU8[0];
    aesEcbPlaintext_S.length_U32    = 32u;

    uint8_t aesEcbCipherOut_pU8[32] = {0};
    ts_pointerType aesEcbCipher_S;
    aesEcbCipher_S.data_U8P         = &aesEcbCipherOut_pU8[0];
    aesEcbCipher_S.length_U32       = 32u;

    // AES-ECB requires block-aligned input
    if ((aesEcbPlaintext_S.length_U32 % 16u) != 0u)
    {
        printf(" ECB input length (%u) not block aligned (16 bytes)\n", aesEcbPlaintext_S.length_U32);
        return TEEC_ERROR_BAD_PARAMETERS;
    }

    if (aesEcbCipher_S.length_U32 < aesEcbPlaintext_S.length_U32)
    {
        printf(" Output buffer (%u) is smaller than input (%u)\n",
               aesEcbCipher_S.length_U32, aesEcbPlaintext_S.length_U32);
        return TEEC_ERROR_SHORT_BUFFER;
    }

    printf("\n Data to be ECB encrypted: ");
    for (loopCounter_U32 = 0; loopCounter_U32 < aesEcbPlaintext_S.length_U32; loopCounter_U32++) {
        printf("0x%x ", aesEcbPlaintext_S.data_U8P[loopCounter_U32]);
    }
    printf("\n");

    res = Crypto_AES128EcbEncryptionWithNoPad(ctx, keyid, keyid_size, &aesEcbPlaintext_S, &aesEcbCipher_S);
    if (res == TEEC_SUCCESS) {
        printf("\n ECB Encrypted data (NoPad): ");
        for (loopCounter_U32 = 0; loopCounter_U32 < aesEcbCipher_S.length_U32; loopCounter_U32++) {
            printf("0x%x ", aesEcbCipher_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\n ECB Encryption failed: 0x%08x\n", res);
    }

    return res;
}

#ifdef ENABLE_DECRYPT_ECB

TEEC_Result Aes128Ecbdecryptionwopad(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint32_t    loopCounter_U32;
    char        keyid[15]         = "Secure_blob";
    uint32_t    keyid_size        = strlen(keyid);

    uint8_t     aesEcbPlain_pU8[32]      = {0}; /** decrypted output */
    ts_pointerType aesEcbPlaintext_S;
    aesEcbPlaintext_S.data_U8P           = &aesEcbPlain_pU8[0];
    aesEcbPlaintext_S.length_U32         = 32u;

    /** Expected output should match original plain text: "hello this string of 32 bytes!!" */
    uint8_t aesEcbCipher_pU8[32] = {
    0x20, 0xe8, 0x9c, 0xc6, 0xb0, 0xe1, 0x8f, 0x23,
    0xb1, 0x2e, 0x20, 0xa8, 0x4c, 0x09, 0x14, 0x01,
    0x35, 0xd8, 0xfd, 0x84, 0x60, 0xf6, 0x29, 0xa8,
    0xe7, 0xd1, 0x1c, 0xef, 0x2f, 0xe7, 0x12, 0xf2
    };

    ts_pointerType aesEcbCipher_S;
    aesEcbCipher_S.data_U8P             = &aesEcbCipher_pU8[0];
    aesEcbCipher_S.length_U32           = 32u;

    printf("\n Ciphertext to be ECB decrypted: ");
    for (loopCounter_U32 = 0; loopCounter_U32 < aesEcbCipher_S.length_U32; loopCounter_U32++) {
        printf("0x%x ", aesEcbCipher_S.data_U8P[loopCounter_U32]);
    }
    printf("\n");

    res = Crypto_AES128EcbDecryptionWithNoPad(ctx, keyid, keyid_size, &aesEcbCipher_S, &aesEcbPlaintext_S);
    if (res == TEEC_SUCCESS) {
        printf("\n ECB Decrypted output (NoPad): ");
        for (loopCounter_U32 = 0; loopCounter_U32 < aesEcbPlaintext_S.length_U32; loopCounter_U32++) {
            printf("0x%x ", aesEcbPlaintext_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\n ECB Decryption failed: 0x%08x", res);
    }

    return res;
}

#endif

#ifdef ENABLE_DECRYPT_ECB_START_UPDATE_FINAL

TEEC_Result Aes128Ecbdecryptionwopad(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    uint32_t loopCounter_U32;

    uint8_t aesEcbPlain_pU8[32] = {0}; // Output buffer
    ts_pointerType aesEcbPlaintext_S;
    aesEcbPlaintext_S.data_U8P = aesEcbPlain_pU8;
    aesEcbPlaintext_S.length_U32 = sizeof(aesEcbPlain_pU8);

    uint8_t aesEcbPlainExp_pU8[30] = "hello this string of 30 bytes!"; // Expected

    uint8_t aesEcbCipher_pU8[32] = {
    0x20, 0xe8, 0x9c, 0xc6, 0xb0, 0xe1, 0x8f, 0x23,
    0xb1, 0x2e, 0x20, 0xa8, 0x4c, 0x09, 0x14, 0x01,
    0x35, 0xd8, 0xfd, 0x84, 0x60, 0xf6, 0x29, 0xa8,
    0xe7, 0xd1, 0x1c, 0xef, 0x2f, 0xe7, 0x12, 0xf2
    };
    ts_pointerType aesEcbCipher_S;
    aesEcbCipher_S.data_U8P = aesEcbCipher_pU8;
    aesEcbCipher_S.length_U32 = sizeof(aesEcbCipher_pU8);

    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("Expected plaintext: ");
    for (loopCounter_U32 = 0; loopCounter_U32 < sizeof(aesEcbPlainExp_pU8); loopCounter_U32++) {
        printf("0x%x, ", aesEcbPlainExp_pU8[loopCounter_U32]);
    }
    printf("\n");

    res = Crypto_AES128ECB_Decrypt_Start(ctx, keyid, keyid_size);
    if (res == TEEC_SUCCESS) {
        printf("Crypto_AES128ECB_Decrypt_Start: Decryption context initialized with key.\n");

        res = Crypto_AES128ECB_Decrypt_Update(ctx, &aesEcbCipher_S, &aesEcbPlaintext_S);
        if (res == TEEC_SUCCESS) {
            printf("Crypto_AES128ECB_Decrypt_Update: Ciphertext data processed successfully.\n");

            res = Crypto_AES128ECB_Decrypt_Final(ctx, &aesEcbPlaintext_S);
            if (res == TEEC_SUCCESS) {
                printf("Crypto_AES128ECB_Decrypt_Final: Decryption finalized, plaintext output is ready.\n");

                // Length match check
                if (aesEcbPlaintext_S.length_U32 == sizeof(aesEcbPlainExp_pU8)) {
                    int match = 1;
                    for (loopCounter_U32 = 0; loopCounter_U32 < sizeof(aesEcbPlainExp_pU8); loopCounter_U32++) {
                        if (aesEcbPlainExp_pU8[loopCounter_U32] != aesEcbPlaintext_S.data_U8P[loopCounter_U32]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) {
                        printf("Decryption output matches expected plaintext.\n");
                    } else {
                        printf("Decryption output does not match expected plaintext.\n");
                    }
                } else {
                    printf("Mismatch in decrypted length: expected %lu, got %u\n",
                           sizeof(aesEcbPlainExp_pU8), aesEcbPlaintext_S.length_U32);
                }

                printf("Decrypted data (hex): ");
                for (loopCounter_U32 = 0; loopCounter_U32 < aesEcbPlaintext_S.length_U32; loopCounter_U32++) {
                    printf("0x%x ", aesEcbPlaintext_S.data_U8P[loopCounter_U32]);
                }

                printf("\nDecrypted string: %s\n", aesEcbPlaintext_S.data_U8P);

            } else {
                printf("Decrypt_Final failed: 0x%x\n", res);
            }
        } else {
            printf("Decrypt_Update failed: 0x%x\n", res);
        }
    } else {
        printf("Decrypt_Start failed: 0x%x\n", res);
    }

    return res;
}
#endif // ENABLE_DECRYPT_ECB_START_UPDATE_FINAL

#ifdef ENABLE_DECRYPT_ECB_START_UPDATE_FINAL_FILE

TEEC_Result Aes128Ecbdecryptionwopad(struct TEE_resource_ctx *ctx) {
    TEEC_Result     res                   = TEEC_SUCCESS;
    FILE           *l_inputFile_SP        = NULL;
    FILE           *l_outputFile_SP       = NULL;
    uint8_t         l_CiphertextPtr_pU8[DATA_SIZE_CIPHER] = {0};
    uint8_t         l_PlaintextPtr_pU8[DATA_SIZE_CIPHER]  = {0};
    ts_pointerType  aesEcbCiphertext_S;
    ts_pointerType  aesEcbPlaintext_S;
    size_t          bytes_read            = 0U;
    size_t          bytes_written         = 0U;
    char            keyid[]               = "Secure_blob";
    uint32_t        keyid_size            = (uint32_t)strlen(keyid);
    int             continue_loop         = 1;

#ifdef CA_VERBOSE
    printf("\n[CA] Entering Aes128Ecbdecryptionwopad\n");
#endif

    l_inputFile_SP  = fopen("/tmp/encrypted_system_partition.bin", "rb");
    l_outputFile_SP = fopen("/tmp/decrypted_system_partition.bin", "wb");

    if ((l_inputFile_SP == NULL) || (l_outputFile_SP == NULL)) {
        printf("[CA] Unable to open input/output file.\n");
        res = TEEC_ERROR_GENERIC;
    } else {
        res = Crypto_AES128ECB_Decrypt_Start(ctx, keyid, keyid_size);

        if (res != TEEC_SUCCESS) {
            printf("[CA] AES Decryption Start failed: 0x%08x\n", res);
        } else {
            while ((continue_loop == 1) &&
                   ((bytes_read = fread(l_CiphertextPtr_pU8, 1, DATA_SIZE_CIPHER, l_inputFile_SP)) > 0U)) {

                if ((bytes_read % AES128_BLOCK_SIZE_BYTES) != 0U) {
                    printf("[CA] Encrypted data is not aligned to AES block size.\n");
                    res = TEEC_ERROR_BAD_PARAMETERS;
                    continue_loop = 0;
                } else {
                    aesEcbCiphertext_S.data_U8P    = l_CiphertextPtr_pU8;
                    aesEcbCiphertext_S.length_U32  = (uint32_t)bytes_read;

                    aesEcbPlaintext_S.data_U8P     = l_PlaintextPtr_pU8;
                    aesEcbPlaintext_S.length_U32   = (uint32_t)bytes_read;

                    res = Crypto_AES128ECB_Decrypt_Update(ctx, &aesEcbCiphertext_S, &aesEcbPlaintext_S);

                    if (res != TEEC_SUCCESS) {
                        printf("[CA] AES Decrypt Update failed: 0x%08x\n", res);
                        continue_loop = 0;
                    } else {
                        bytes_written = fwrite(l_PlaintextPtr_pU8, 1,
                                               aesEcbPlaintext_S.length_U32, l_outputFile_SP);

                        if (bytes_written != aesEcbPlaintext_S.length_U32) {
                            printf("[CA] File write mismatch\n");
                            res = TEEC_ERROR_GENERIC;
                            continue_loop = 0;
                        }
                    }
                }
            }

            if (res == TEEC_SUCCESS) {
                res = Crypto_AES128ECB_Decrypt_Final(ctx, &aesEcbPlaintext_S);

                if (res != TEEC_SUCCESS) {
                    printf("[CA] AES ECB Decrypt Final failed: 0x%08x\n", res);
                } else {
                    printf("[CA] AES ECB Decryption completed successfully.\n");
                }
            }
        }
    }

    if (l_inputFile_SP  != NULL) { fclose(l_inputFile_SP);  }
    if (l_outputFile_SP != NULL) { fclose(l_outputFile_SP); }

    printf("\n[CA] Exiting Aes128Ecbdecryptionwopad\n");


    return res;
}

#endif // ENABLE_DECRYPT_ECB_START_UPDATE_FINAL_FILE

TEEC_Result Aes128Cbcencryptionwopad(struct TEE_resource_ctx *ctx) {

    TEEC_Result res;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);
    uint8_t aesCbcPlain_pU8[32] = {"hello this string of 32 bytes!!!"}; /** plain text */
    ts_pointerType aesCbcPlaintext_S; /** CBC plain text in structure format */
    aesCbcPlaintext_S.data_U8P   = &aesCbcPlain_pU8[0];
    aesCbcPlaintext_S.length_U32 = 32u;
    uint8_t aesCbcIv_pU8[16]        = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    ts_pointerType aesCbcIv_S;
    aesCbcIv_S.data_U8P             = &aesCbcIv_pU8[0];
    aesCbcIv_S.length_U32           = 16u;
    uint8_t aesCbcCipherOut_pU8[32] = {0};
    ts_pointerType aesCbcCipher_S;
    aesCbcCipher_S.data_U8P         = &aesCbcCipherOut_pU8[0];
    aesCbcCipher_S.length_U32       = 32u;
    uint32_t         loopCounter_U32; /** Variable for printf */


    printf("\n data to be encrypted : ");
    for (loopCounter_U32=0; loopCounter_U32 < aesCbcPlaintext_S.length_U32; loopCounter_U32++) {
        printf("0x%x ",aesCbcPlaintext_S.data_U8P[loopCounter_U32]);
    }
        printf("\n");
    res = Crypto_AES128CbcEncryptionWithNoPad(ctx, keyid, keyid_size, &aesCbcPlaintext_S, &aesCbcIv_S, &aesCbcCipher_S);
    if (res == TEEC_SUCCESS) {
        printf("\n Encrypted data without padding : ");
        for (loopCounter_U32=0; loopCounter_U32 < aesCbcCipher_S.length_U32 ; loopCounter_U32++) {
            printf("0x%x ",aesCbcCipher_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\nEncryption failed 0x%08x", res);
    }


    return res;
}

TEEC_Result Aes128Cbcdecryptionwopad(struct TEE_resource_ctx *ctx) {

    TEEC_Result res;
    uint32_t         loopCounter_U32; /** Variable for printf */
    uint8_t          aesCbcPlain_pU8[32] = {0}; /** plain text */
    uint8_t          aesCbcPlainExp_pU8[32] = {"hello this string of 30 bytes!"}; /** plain text */
    ts_pointerType aesCbcPlaintext_S; /** CBC plain text in structure format */
    aesCbcPlaintext_S.data_U8P   = &aesCbcPlain_pU8[0];
    aesCbcPlaintext_S.length_U32 = 32u;
    uint8_t aesCbcIv_pU8[16]       = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    ts_pointerType aesCbcIv_S;
    aesCbcIv_S.data_U8P          = &aesCbcIv_pU8[0];
    aesCbcIv_S.length_U32        = 16u;
    uint8_t aesCbcCipher_pU8[32]   =   {0x76, 0x16, 0x78, 0x78, 0x19,
                                        0x32, 0x4d, 0xa1, 0x19, 0x74,
                                        0xb5, 0x5f, 0x78, 0x9d, 0x53,
                                        0x6e, 0xd9, 0xc6, 0x89, 0xc6,
                                        0x13, 0x87, 0x1f, 0x8d, 0x63,
                                        0x7a, 0x4d, 0x6c, 0x50, 0x23, 0x69, 0x52};
    ts_pointerType aesCbcCipher_S;
    aesCbcCipher_S.data_U8P         = &aesCbcCipher_pU8[0];
    aesCbcCipher_S.length_U32       = 32u;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("Expected plaintext : ");
    for (loopCounter_U32=0; loopCounter_U32 < sizeof(aesCbcPlainExp_pU8); loopCounter_U32++){
        printf("0x%x, ",aesCbcPlainExp_pU8[loopCounter_U32]);
    }
    printf("\n");
    res = Crypto_AES128CbcDecryptionWithNoPad(ctx, keyid, keyid_size, &aesCbcCipher_S, &aesCbcIv_S, &aesCbcPlaintext_S);
    if (res == TEEC_SUCCESS) {
        printf("\n Decrypted data without padding : ");
        for (loopCounter_U32=0; loopCounter_U32 < aesCbcPlaintext_S.length_U32; loopCounter_U32++) {
            printf("0x%x ",aesCbcPlaintext_S.data_U8P[loopCounter_U32]);
        }
        printf("\n");
    }
    else {
        printf("\n Decryption failed 0x%08x", res);
    }
    
    return res;
}

TEEC_Result Rsassapkcs1v5signverify2k(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    for (uint32_t i = 0; i < DATA_SIZE; i++) {
        data_to_cal_hash[i] = (uint8_t)(i % 256);
    }
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */
    uint8_t key_len = RSA_2K;
    uint8_t Digest[32]       = {0};
    ts_pointerType Plaintext_S;
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = DATA_SIZE;
    ts_pointerType Digest_S;
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 32;
    ts_pointerType signature_S;
    uint8_t signature_pu8[256] = {
        0x43, 0xeb, 0x4d, 0xa5, 0x2f, 0xf8, 0xb6, 0x8c, 0x07, 0x83, 0xf5, 0x4d, 0x39, 0x48, 0xe2, 0xd0
        , 0x7b, 0x2e, 0x2e, 0xbd, 0x72, 0x91, 0x30, 0x29, 0x50, 0x91, 0x5a, 0x78, 0x71, 0x76, 0x59, 0xc7
        , 0xd9, 0xb9, 0x97, 0x32, 0x34, 0x95, 0x06, 0x83, 0x4d, 0x3a, 0x55, 0x92, 0xce, 0x36, 0x8e, 0x2b
        , 0x68, 0x7b, 0xb0, 0x81, 0x5e, 0x07, 0xc2, 0x4b, 0x5b, 0x75, 0x4c, 0x67, 0x55, 0xe8, 0x39, 0x21
        , 0x32, 0x05, 0xed, 0xfd, 0xb7, 0x0d, 0xb4, 0xaa, 0xaf, 0x24, 0x72, 0xbb, 0x6f, 0x04, 0xbc, 0xf1
        , 0x56, 0x8d, 0xa9, 0x84, 0x65, 0x9f, 0x28, 0xf8, 0xbc, 0xed, 0x49, 0xbd, 0x6a, 0x34, 0x65, 0x79
        , 0x7f, 0xb1, 0x9d, 0x2c, 0x94, 0x76, 0x02, 0x45, 0xeb, 0x7d, 0xf7, 0x2b, 0xf7, 0x95, 0x0b, 0x77
        , 0x75, 0x6d, 0x4f, 0x2c, 0x3d, 0xa3, 0xc3, 0x89, 0xe1, 0x18, 0x2d, 0xae, 0xb9, 0xb6, 0xf4, 0xd0
        , 0xc4, 0x75, 0xcf, 0x97, 0x27, 0x3b, 0x0a, 0xd4, 0x45, 0x34, 0x1c, 0x67, 0xbc, 0x29, 0xe6, 0x07
        , 0x6f, 0x99, 0x81, 0x9e, 0xd9, 0xcc, 0xea, 0xc0, 0x27, 0xdf, 0x76, 0x62, 0xd4, 0x00, 0x59, 0xb7
        , 0xba, 0x87, 0x83, 0x35, 0x00, 0xe7, 0xd7, 0x73, 0x98, 0xfa, 0x1c, 0xcc, 0xeb, 0x42, 0xba, 0x68
        , 0x3f, 0x80, 0x12, 0xcb, 0x1b, 0xdd, 0x35, 0xdd, 0xf7, 0xcc, 0xbf, 0x57, 0x71, 0xa8, 0xd3, 0x14
        , 0x9c, 0x70, 0x28, 0x58, 0x1d, 0x22, 0xe2, 0xa8, 0x35, 0x66, 0xc8, 0xc1, 0x89, 0xa4, 0x2c, 0xd6
        , 0x2c, 0xa9, 0xbd, 0x84, 0xa5, 0x12, 0xda, 0xf7, 0x6d, 0x1e, 0xcc, 0xf6, 0x88, 0x65, 0x2b, 0x5b
        , 0x4a, 0x28, 0x23, 0x4b, 0x81, 0xf4, 0xbe, 0xe2, 0xe4, 0x4e, 0xdf, 0xb8, 0x22, 0x32, 0x7a, 0xe9
        , 0x84, 0xa7, 0xf2, 0x3e, 0x07, 0x59, 0xac, 0x4a, 0x61, 0xd4, 0x05, 0xac, 0xbe, 0x61, 0x34, 0xa4
    };
    signature_S.data_U8P = &signature_pu8[0];
    signature_S.length_U32 = 256;
    res = Crypto_SHA256_Start(ctx);
    if (res == TEEC_SUCCESS) {
        for (loopCounter_U32 = 0; loopCounter_U32 < DATA_SIZE; loopCounter_U32+=CHUNK_SIZE ) {
            res = Crypto_SHA256_Update(ctx, &Plaintext_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation update failed 0x%08x", res);
                return res;
            }
        }
        res = Crypto_SHA256_Final(ctx, &Digest_S);
        if (res != TEEC_SUCCESS){
            printf("\n Digest calculation Final failed 0x%08x", res);
            return res;
        }
        else {
            printf("\nDigest calculate : ");
            for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
            }
            printf("\n");
        }
    }
    res = Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify(ctx, &Digest_S, &signature_S,key_len);
    if(res != TEEC_SUCCESS)
    {
        printf("\n Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify failure ");
    }
    else
    {
        printf("Signature Verification 2k Successfull");
    }

    return res;
}

TEEC_Result Rsassapkcs1v5signverify3k(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */
    uint8_t key_len = RSA_3K;
    uint8_t Digest[32]       = {0};
    ts_pointerType Digest_S;
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 32;
    ts_pointerType signature_S;
    uint8_t signature_pu8[SIZE_OF_3k_MODULUS_BYTES];
    size_t bytes_read_sign = 0;
    size_t bytes_read = 0;
    FILE *l_signFile_SP = NULL, *l_dataFile_SP = NULL;
    ts_pointerType Plaintext_S;

    l_signFile_SP = fopen("/update-cache/signature.txt", "rb");
    if (l_signFile_SP != NULL)
    {
        bytes_read_sign = fread(signature_pu8, SIZE_OF_3k_MODULUS_BYTES, SIZE_OF_3k_MODULUS_BYTES, l_signFile_SP);
       if(bytes_read_sign == 0)
       {
          printf("failed to read the signature");
          return 0;
       }
    }
    else{
        printf("Filed to open signature");
    }
#if 0 

    // Signature for the data
    uint8_t data_to_cal_hash[21] = {"Hi hello from visteon"};

    uint8_t signature_pu8[SIZE_OF_3k_MODULUS_BYTES] = {
    0x33, 0x03, 0x97, 0xD0, 0x4B, 0x26, 0x33, 0x46, 0x2A, 0x15, 0xBA, 0xDD, 0xD9, 0xBA, 0x49, 0x7C,  
    0x26, 0x98, 0x4B, 0xF7, 0x92, 0x02, 0x93, 0xBE, 0x1F, 0x3C, 0xB4, 0x79, 0x5F, 0xDD, 0x63, 0x3A,  
    0xBF, 0xDF, 0x54, 0x99, 0x13, 0xBB, 0x0C, 0x33, 0xC8, 0xCB, 0x61, 0xED, 0x1E, 0xFE, 0x6B, 0xD9,  
    0xB9, 0xCB, 0xEA, 0x01, 0xAB, 0x3A, 0xF7, 0x9F, 0x99, 0xE4, 0x7C, 0xCD, 0x0B, 0x36, 0x71, 0x92,  
    0x23, 0x52, 0xF7, 0xC6, 0xDF, 0x8F, 0x1E, 0x55, 0xBA, 0xE7, 0xF3, 0x3C, 0xCC, 0xBE, 0x2D, 0xAA,  
    0x1F, 0xF9, 0xA3, 0xE9, 0x45, 0xB9, 0x43, 0x18, 0xD8, 0xDF, 0x83, 0x03, 0xBE, 0xA1, 0x35, 0xB5,  
    0xCC, 0x90, 0xF5, 0xB8, 0x23, 0x5E, 0xB9, 0x34, 0xA9, 0x43, 0x49, 0x18, 0x75, 0x0D, 0x46, 0x4D,  
    0x81, 0xFD, 0x05, 0x6D, 0x79, 0xC0, 0x9F, 0x1B, 0xF3, 0x2D, 0x89, 0x9D, 0x31, 0x0B, 0xD2, 0x42,  
    0x04, 0x05, 0x2B, 0xE1, 0x0E, 0x28, 0xF8, 0x5D, 0xAF, 0xEB, 0x97, 0x5D, 0xF0, 0xD3, 0x2E, 0xED,  
    0x6F, 0xC8, 0x81, 0x4D, 0x49, 0x50, 0x78, 0x78, 0x07, 0x4D, 0x7F, 0xA7, 0xA9, 0x08, 0x00, 0x54,  
    0xDE, 0x18, 0x71, 0x3A, 0xEB, 0x10, 0xFE, 0xE4, 0x35, 0x53, 0xA6, 0xDC, 0x24, 0x57, 0xD1, 0xF9,  
    0x38, 0xB7, 0x8D, 0xCD, 0xC8, 0xC3, 0x26, 0x74, 0x4C, 0xE2, 0xEC, 0x4E, 0x79, 0x7C, 0xBB, 0xCF,  
    0x14, 0x66, 0x28, 0x9D, 0xAF, 0xBF, 0x3B, 0x5E, 0xD6, 0x84, 0xAE, 0x19, 0x71, 0x5F, 0x40, 0x6C,  
    0x15, 0xCE, 0x33, 0x31, 0x33, 0x2F, 0x88, 0xEF, 0x74, 0xC1, 0xDA, 0xE3, 0x13, 0x1C, 0xE2, 0xF3,  
    0x27, 0xA2, 0xAD, 0x2F, 0xD5, 0x8E, 0x3C, 0x6D, 0xB9, 0x36, 0x62, 0xBF, 0x5B, 0x54, 0x9A, 0xA8,  
    0xC0, 0x12, 0x95, 0x53, 0xFD, 0xC4, 0x3E, 0x85, 0xB7, 0x27, 0x05, 0x14, 0x4E, 0x06, 0xE5, 0x4D,  
    0x1C, 0xD5, 0xF9, 0x61, 0x15, 0xAD, 0x9B, 0x2E, 0x59, 0x37, 0x17, 0xD2, 0x56, 0x03, 0x9A, 0xBC,  
    0x4A, 0xD6, 0x8D, 0x47, 0x27, 0x5C, 0xB1, 0x06, 0xEE, 0xC2, 0xB5, 0x33, 0x85, 0x21, 0xA4, 0x7B,  
    0xE8, 0x9F, 0x46, 0x9C, 0x32, 0xD9, 0x1D, 0x4A, 0x09, 0x0D, 0x3C, 0xBA, 0xA9, 0x57, 0x9B, 0xA3,  
    0xBF, 0x8B, 0x06, 0x8F, 0x61, 0x0F, 0x27, 0xAB, 0x6C, 0xDA, 0x31, 0x40, 0xC6, 0xD0, 0xC3, 0xB2,  
    0x29, 0x76, 0x90, 0x62, 0xC8, 0x35, 0x34, 0x15, 0xEC, 0x90, 0x16, 0x4E, 0x04, 0x12, 0xCF, 0xCC,  
    0x74, 0x88, 0xC0, 0x9F, 0x00, 0x69, 0x91, 0x5B, 0x37, 0x25, 0x4B, 0xF8, 0x84, 0xA0, 0x00, 0x23,  
    0x06, 0x68, 0x59, 0xAE, 0xD6, 0x2D, 0xEE, 0xDB, 0x8D, 0x96, 0xB3, 0xF9, 0x40, 0xFC, 0xAC, 0x28,  
    0x4F, 0xA4, 0x6D, 0x81, 0x4E, 0x5D, 0x58, 0xA1, 0xE0, 0x91, 0x0E, 0xE4, 0x42, 0xB2, 0x42, 0xFD  
    };
#endif
    signature_S.data_U8P = &signature_pu8[0];
    signature_S.length_U32 = 384;
    Plaintext_S.length_U32   = DATA_SIZE; 
    
    res = Crypto_SHA256_Start(ctx);
    if (res == TEEC_SUCCESS) {
        l_dataFile_SP = fopen("/update-cache/ext4-system-partition_23.img", "rb");

        if (l_dataFile_SP != NULL)
        {
            while ((uint8_t)0 != (bytes_read = fread(data_to_cal_hash, 1, DATA_SIZE, l_dataFile_SP))) {
                Plaintext_S.data_U8P     = &data_to_cal_hash[0];
                res = Crypto_SHA256_Update(ctx, &Plaintext_S);
                if (res != TEEC_SUCCESS){
                    printf("\n Digest calculation update failed 0x%08x", res);
                    return res;
                }
            }
            res = Crypto_SHA256_Final(ctx, &Digest_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation Final failed 0x%08x", res);
                return res;
            }
            else {
                printf("\nDigest calculate : ");
                for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                    printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
                }
                printf("\n");
            }
        }
        res = Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify(ctx, &Digest_S, &signature_S,key_len);
        if(res != TEEC_SUCCESS)
        {
            printf("\n Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify failure ");
        }
        else
        {
            printf("Signature Verification 3k Successfull");
        }
    }
    return res;
}

#ifdef ENABLE_DECRYPT_LARGE_DATA

TEEC_Result Aes128Cbcdecryptionwithpkcs7pad_largerchunk(struct TEE_resource_ctx *ctx) {

    TEEC_Result res = 0;
    uint8_t l_InitialVectorPtr_pU8[IV_SIZE]  = {0xFF,0xEE,0xDD,0xCC,0xBB,0xAA,0x99,0x88,
												0x77,0x66,0x55,0x44,0x33,0x22,0x11,0x00};
    ts_pointerType aesCbcIv_S;
    aesCbcIv_S.data_U8P                 = &l_InitialVectorPtr_pU8[0];
    aesCbcIv_S.length_U32               =  IV_SIZE;

    uint8_t l_CiphertextPtr_pU8[DATA_SIZE_CIPHER]  = {0};
    ts_pointerType aesCbcCiphertext_S;

    uint8_t l_PlaintextPtr_pU8[DATA_SIZE_CIPHER]  = {0};
    ts_pointerType aesCbcPlaintext_S;

    FILE *l_inputFile_SP = NULL, *l_outputFile_SP = NULL;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);
    size_t            bytes_read                 =  0;
    size_t            bytes_write                =  0;

    l_inputFile_SP = fopen("/tmp/encrypted_system_partition.bin", "rb");
    if (l_inputFile_SP != NULL)
    {
        l_outputFile_SP = fopen("/tmp/decrypted_system_partition.bin", "wb");
	    if(l_outputFile_SP != NULL)
		{
			aesCbcIv_S.data_U8P                         = &l_InitialVectorPtr_pU8[0];
			aesCbcIv_S.length_U32                       =  IV_SIZE;
			res = Crypto_AES128CBC_Decrypt_Start(ctx, keyid, keyid_size, &aesCbcIv_S);
            while ((uint8_t)0 != (bytes_read = fread(l_CiphertextPtr_pU8, 1, DATA_SIZE_CIPHER, l_inputFile_SP))) {
					if ((res == TEEC_SUCCESS) && (aesCbcPlaintext_S.length_U32 != 0)){
						bytes_write = fwrite(l_PlaintextPtr_pU8, 1, aesCbcPlaintext_S.length_U32, l_outputFile_SP);
						if (bytes_write == aesCbcPlaintext_S.length_U32)
						{
							// for misra;
                            printf("\n written bytes : %lu\n", bytes_write);
						}
						else
						{
							printf("\n Unable to write to FILE\n");	
							break;
						}
					}
					if ((bytes_read % (uint8_t)16) == (uint8_t)0) {
#if 0
                        printf("\nCiphertext : ");
                        for (iterator=0; iterator < 16; iterator++) {
                            printf("0x%2x, ", l_CiphertextPtr_pU8[iterator]);
                        }
                        printf("\n");
#endif
    					if (res != TEEC_SUCCESS) {
        					printf("\n Failed to invoke AES Decryption");
    					}
						else {
                            aesCbcCiphertext_S.data_U8P                 = &l_CiphertextPtr_pU8[0];
                            aesCbcCiphertext_S.length_U32               =  bytes_read;
                            aesCbcPlaintext_S.data_U8P                  = &l_PlaintextPtr_pU8[0];
                            aesCbcPlaintext_S.length_U32                =  bytes_read;
                            res = Crypto_AES128CBC_Decrypt_Update(ctx, &aesCbcCiphertext_S, &aesCbcPlaintext_S);
                            if (res != TEEC_SUCCESS) {
                                printf("\n Crypto_AES128CBC_Decrypt_Update failed 0x%08x", res);
                            }
                            else {
								printf("aesCbcPlaintext_S.length_U32 : %d \n", aesCbcPlaintext_S.length_U32);
                                
                                for (uint32_t idx = 0U; idx < aesCbcPlaintext_S.length_U32; idx++)
                                {
                                    printf("%02X ", aesCbcPlaintext_S.data_U8P[idx]);
                                }
                                printf("\n");

                            }
                            
						}       
					}
			}

			res = Crypto_AES128CBC_Decrypt_Final(ctx, &aesCbcPlaintext_S);
			if (res != TEEC_SUCCESS){
				printf("\n Aes 128 CBC decryption Final failed 0x%08x", res);
			} else {
                printf("After decrypt final aesCbcPlaintext_S.length_U32 : %d \n", aesCbcPlaintext_S.length_U32);
                                
                for (uint32_t idx = 0U; idx < aesCbcPlaintext_S.length_U32; idx++)
                {
                    printf("%02X ", aesCbcPlaintext_S.data_U8P[idx]);
                }
                printf("\n");
                bytes_write = fwrite(l_PlaintextPtr_pU8, 1, aesCbcPlaintext_S.length_U32, l_outputFile_SP);
            }
            
			
			
            if (res == TEEC_SUCCESS) {
                printf("\nData decrypted, image stored in /tmp/Toyota-FDC-sw.iso\n");
            }
            else {
                printf("\nFile decryption failed 0x%08x", res);
            }
            
            fclose(l_outputFile_SP);
        }
    }
    return res;
}

#endif

TEEC_Result Ecdsasignverify(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    ts_pointerType Plaintext_S;
    ts_pointerType signature_S;
    ts_pointerType Digest_S;
    ts_pointerType l_Xcrd_S;
	ts_pointerType  l_Ycrd_S;
	ts_ecdsaPublicKey l_publicKey_S;
    char IPSEC_KEY_ID[] = "Secure";
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen(IPSEC_KEY_ID); // Exclude null terminator
	ts_pointerType l_Private_S;
    uint8_t data_to_cal_hash[] = "Hello ECDSA world";
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */
    uint8_t Digest[48]       = {0};
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = strlen((char*)data_to_cal_hash);
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 48;
    uint8_t signature_pu8[96] = {0};
    signature_S.data_U8P = &signature_pu8[0];
    signature_S.length_U32 = 96;
    const uint8_t X_bytes[48] = {
    0xc4, 0x28, 0xe4, 0x83, 0xe9, 0x41, 0x7f, 0x5b,
    0x94, 0x25, 0xec, 0x4c, 0xa8, 0x5d, 0xac, 0x27,
    0xce, 0x3c, 0xc0, 0xb4, 0x1b, 0x86, 0x84, 0x98,
    0xb0, 0x70, 0x1a, 0x1f, 0xf3, 0xf7, 0x00, 0xe9,
    0x59, 0x5d, 0xa7, 0xce, 0x06, 0x02, 0xc5, 0xf9,
    0x2d, 0x78, 0x93, 0xe6, 0x20, 0x5f, 0x9d, 0x80
    };
    const uint8_t Y_bytes[48] = {
    0x80, 0x9b, 0x9e, 0x5c, 0x9a, 0xe0, 0x6c, 0x88,
    0x28, 0x3f, 0xda, 0x0f, 0xbe, 0x40, 0x03, 0x25,
    0x72, 0x0f, 0xbd, 0x03, 0x2f, 0x7e, 0xbf, 0x72,
    0x33, 0x0c, 0x91, 0x35, 0x28, 0x80, 0x86, 0x02,
    0x35, 0xa7, 0x0f, 0xe1, 0x6d, 0x14, 0x57, 0xc3,
    0x07, 0x62, 0x33, 0x10, 0x93, 0xf2, 0xa9, 0x38
    };
    l_Xcrd_S.data_U8P = malloc(SIZE_OF_ECDSA_X); 
	memcpy(l_Xcrd_S.data_U8P,&X_bytes[0],SIZE_OF_ECDSA_X);
	l_Xcrd_S.length_U32 = SIZE_OF_ECDSA_X;
    l_Ycrd_S.data_U8P = malloc(SIZE_OF_ECDSA_Y); 
	memcpy(l_Ycrd_S.data_U8P,&Y_bytes[0],SIZE_OF_ECDSA_Y);
	l_Ycrd_S.length_U32 = SIZE_OF_ECDSA_Y;
	l_publicKey_S.Xcrd_S = l_Xcrd_S;
	l_publicKey_S.Ycrd_S = l_Ycrd_S;
	const uint8_t Private_bytes[48] = {
        0x43, 0xDE, 0x37, 0xCA, 0xD8, 0x45, 0xCC, 0x1F,
        0x88, 0xE7, 0xEF, 0xCE, 0xAC, 0x77, 0x9B, 0xFA, 
        0xB2, 0xB9, 0xF8, 0x59, 0xF0, 0x1D, 0xB7, 0xF2, 
        0x5B, 0xE6, 0x73, 0x70, 0x41, 0xE7, 0xB4, 0x45, 
        0x05, 0x56, 0x0A, 0x08, 0xDA, 0x43, 0xA4, 0xAB, 
        0x3C, 0xE7, 0x16, 0x88, 0xD7, 0xBA, 0xD1, 0x5F
    };
    l_Private_S.data_U8P = malloc(SIZE_OF_ECDSA_PRIV); 
	memcpy(l_Private_S.data_U8P,&Private_bytes[0],SIZE_OF_ECDSA_PRIV);
	l_Private_S.length_U32 = SIZE_OF_ECDSA_PRIV;
    res = Crypto_SHA384_Start(ctx);
    if (res == TEEC_SUCCESS) {
        for (loopCounter_U32 = 0; loopCounter_U32 < Plaintext_S.length_U32; loopCounter_U32+=CHUNK_SIZE ) {
            res = Crypto_SHA384_Update(ctx, &Plaintext_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation update failed 0x%08x", res);
                return res;
            }
        }
        res = Crypto_SHA384_Final(ctx, &Digest_S);
        if (res != TEEC_SUCCESS){
            printf("\n Digest calculation Final failed 0x%08x", res);
            return res;
        }
        else {
            printf("\nDigest calculate : ");
            for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
            }
            printf("\n");
        }
    }
    res = Crypto_ECDSA_P384_sign_generate(ctx, IPSEC_KEY_ID, IPSEC_KEY_ID_LEN, &Digest_S, &signature_S);
    if(res != TEEC_SUCCESS)
    {
        printf("\n Crypto_ECDSA_PHA256_Sign_generate failure ");
    }
    else
    {
        printf("\nSignature Generated : ");
        for (loopCounter_U32=0; loopCounter_U32 < signature_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",signature_S.data_U8P[loopCounter_U32]);
            }
        printf("\n");
        printf("Signature Generation ECDSA Successfull");
    }
    res = Crypto_ECDSA_P384_Verify(ctx, &Digest_S, &signature_S, &l_publicKey_S);
    if(res != TEEC_SUCCESS)
    {
        printf("\n Crypto_ECDSA_PHA256_Verify failure ");
    }
    else
    {
        printf("Signature Verification ECDSA Successfull");
    }

    return res;
}

TEEC_Result Ecdsasigngenerate(struct TEE_resource_ctx *ctx) {
    TEEC_Result res;
    ts_pointerType Plaintext_S;
    ts_pointerType signature_S;
    ts_pointerType Digest_S;
    
    char IPSEC_KEY_ID[] = "Secure";
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen(IPSEC_KEY_ID); // Exclude null terminator
    
    uint8_t data_to_cal_hash[] = "Hello ECDSA world";
    uint8_t Digest[48] = {0};
    uint8_t signature_pu8[96] = {0};
    uint32_t i;

    // Initialize structures
    Plaintext_S.data_U8P   = data_to_cal_hash;
    Plaintext_S.length_U32 = (uint32_t)strlen((char*)data_to_cal_hash);
    
    Digest_S.data_U8P      = Digest;
    Digest_S.length_U32    = sizeof(Digest);
    
    signature_S.data_U8P   = signature_pu8;
    signature_S.length_U32 = sizeof(signature_pu8);

    // Step 1: Hashing
    res = Crypto_SHA384_Start(ctx);
    if (res != TEEC_SUCCESS) {
        printf("\n SHA384 Start failed: 0x%08x", res);
    }
    else {
        // Only loop if you are actually splitting the data into chunks.
        // If data is small, just call Update once.
        res = Crypto_SHA384_Update(ctx, &Plaintext_S);
        if (res != TEEC_SUCCESS) {
            printf("\n SHA384 Update failed: 0x%08x", res);
        }
        else {
            res = Crypto_SHA384_Final(ctx, &Digest_S);
            if (res != TEEC_SUCCESS) {
                printf("\n SHA384 Final failed: 0x%08x", res);
            }
            else {
                // Step 2: Signing
                printf("\nDigest calculated: ");
                for (i = 0; i < Digest_S.length_U32; i++) printf("%02x ", Digest_S.data_U8P[i]);

                res = Crypto_ECDSA_P384_sign_generate(ctx, IPSEC_KEY_ID, IPSEC_KEY_ID_LEN, &Digest_S, &signature_S);
                if (res != TEEC_SUCCESS) {
                    printf("\n ECDSA Sign failed: 0x%08x", res);
                }
                else {
                    printf("\nSignature Generated: ");
                    for (i = 0; i < signature_S.length_U32; i++) printf("%02x ", signature_S.data_U8P[i]);
                    printf("\nSignature Generation ECDSA Successful");
                }
            }
        }
    }
    return res;
}
TEEC_Result Ecdsa_keygenerate(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint8_t privatekey[48] = {0};
    uint8_t userkey_X[48] = {0};
    uint8_t userkey_Y[48] = {0};
    ts_pointerType PrivateKey_S;
    ts_ecdsaPublicKey PublicKey_S;
    ts_pointerType Plaintext_S;
    ts_pointerType signature_S;
    ts_pointerType Digest_S;
    uint8_t data_to_cal_hash[] = "Hello ECDSA world";
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */
    uint8_t Digest[48]       = {0};
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = strlen((char*)data_to_cal_hash);
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 48;
    uint8_t signature_pu8[96] = {0};
    signature_S.data_U8P = &signature_pu8[0];
    signature_S.length_U32 = 96;
    PrivateKey_S.data_U8P   = &privatekey[0];
    PrivateKey_S.length_U32   = 48;
    PublicKey_S.Xcrd_S.data_U8P = &userkey_X[0];
    PublicKey_S.Xcrd_S.length_U32 = 48;
    PublicKey_S.Ycrd_S.data_U8P = &userkey_Y[0];
    PublicKey_S.Ycrd_S.length_U32 = 48;
    char IPSEC_KEY_ID[] = "Secure";
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen(IPSEC_KEY_ID); 
    res = Crypto_ECDSA_P384_key_generate(ctx, &PrivateKey_S, &PublicKey_S);
    if(res != TEEC_SUCCESS)
    {
        printf("\n Crypto_ECDSA_PHA256_key_generate failure ");
    }
    else
    {
        printf("\nkey Generated : ");
        for (loopCounter_U32=0; loopCounter_U32 < PrivateKey_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PrivateKey_S.data_U8P[loopCounter_U32]);
            }
        printf("\n");
        printf("\nkey Generated : X");
        for (loopCounter_U32=0; loopCounter_U32 < PublicKey_S.Xcrd_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PublicKey_S.Xcrd_S.data_U8P[loopCounter_U32]);
            }
        printf("\n");
        printf("\nkey Generated : Y");
        for (loopCounter_U32=0; loopCounter_U32 <  PublicKey_S.Ycrd_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PublicKey_S.Ycrd_S.data_U8P[loopCounter_U32]);
            }
        printf("\n Signature Generation ECDSA Successfull \n");
    }
    res = Crypto_SHA384_Start(ctx);
    if (res == TEEC_SUCCESS) {
        for (loopCounter_U32 = 0; loopCounter_U32 < Plaintext_S.length_U32; loopCounter_U32+=CHUNK_SIZE ) {
            res = Crypto_SHA384_Update(ctx, &Plaintext_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation update failed 0x%08x", res);
                return res;
            }
        }
        res = Crypto_SHA384_Final(ctx, &Digest_S);
        if (res != TEEC_SUCCESS){
            printf("\n Digest calculation Final failed 0x%08x", res);
            return res;
        }
        else {
            printf("\nDigest calculate : ");
            for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
            }
            printf("\n");
        }
    }
    res = Privatesecurestorage_opteeapi(ctx, PrivateKey_S.data_U8P, PrivateKey_S.length_U32,
                                               IPSEC_KEY_ID, IPSEC_KEY_ID_LEN);
       if (res == TEEC_SUCCESS) 
       {
           printf("\nIPsec PEM key stored in secure storage\n");
       
            res = Crypto_ECDSA_P384_sign_generate(ctx, IPSEC_KEY_ID, IPSEC_KEY_ID_LEN, &Digest_S, &signature_S);
            if(res != TEEC_SUCCESS)
            {
                printf("\n Crypto_ECDSA_PHA256_Sign_generate failure ");
            }
            else
            {
                printf("\nSignature Generated : ");
                for (loopCounter_U32=0; loopCounter_U32 < signature_S.length_U32; loopCounter_U32++) {
                        printf("0x%x ",signature_S.data_U8P[loopCounter_U32]);
                    }
                printf("\n");
                printf("Signature Generation ECDSA Successfull");
            }
        } 
        else {
           printf("\nFailed to store IPsec key: 0x%08x\n", res);
        }
        res = Crypto_ECDSA_P384_Verify(ctx, &Digest_S, &signature_S, &PublicKey_S);
        if(res != TEEC_SUCCESS)
        {
            printf("\n Crypto_ECDSA_PHA256_Verify failure ");
        }
        else
        {
            printf("Signature Verification ECDSA Successfull");
        }



    return res;
}

TEEC_Result Ecdsasignverify_largechunk(struct TEE_resource_ctx *ctx) {
    
    FILE *l_dataFile_SP = NULL;
    size_t bytes_read = 0;
    TEEC_Result res;
    uint8_t privatekey[48] = {0};
    uint8_t userkey_X[48] = {0};
    uint8_t userkey_Y[48] = {0};
    ts_pointerType PrivateKey_S;
    ts_ecdsaPublicKey PublicKey_S;
    ts_pointerType Plaintext_S;
    ts_pointerType signature_S;
    ts_pointerType Digest_S;
    uint8_t data_to_cal_hash[] = "Hello ECDSA world";
    uint32_t         loopCounter_U32 = 0; /** Variable for printf */
    uint8_t Digest[48]       = {0};
    Plaintext_S.data_U8P     = &data_to_cal_hash[0];
    Plaintext_S.length_U32   = strlen((char*)data_to_cal_hash);
    Digest_S.data_U8P        = &Digest[0];
    Digest_S.length_U32      = 48;
    uint8_t signature_pu8[96] = {0};
    signature_S.data_U8P = &signature_pu8[0];
    signature_S.length_U32 = 96;
    PrivateKey_S.data_U8P   = &privatekey[0];
    PrivateKey_S.length_U32   = 48;
    PublicKey_S.Xcrd_S.data_U8P = &userkey_X[0];
    PublicKey_S.Xcrd_S.length_U32 = 48;
    PublicKey_S.Ycrd_S.data_U8P = &userkey_Y[0];
    PublicKey_S.Ycrd_S.length_U32 = 48;
    char IPSEC_KEY_ID[] = "Secure";
    uint32_t IPSEC_KEY_ID_LEN = (uint32_t)strlen(IPSEC_KEY_ID); 
    res = Crypto_ECDSA_P384_key_generate(ctx, &PrivateKey_S, &PublicKey_S);
    if(res != TEEC_SUCCESS)
    {
        printf("\n Crypto_ECDSA_PHA256_key_generate failure ");
    }
    else
    {
        printf("\nkey Generated : ");
        for (loopCounter_U32=0; loopCounter_U32 < PrivateKey_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PrivateKey_S.data_U8P[loopCounter_U32]);
            }
        printf("\n");
        printf("\nkey Generated : X");
        for (loopCounter_U32=0; loopCounter_U32 < PublicKey_S.Xcrd_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PublicKey_S.Xcrd_S.data_U8P[loopCounter_U32]);
            }
        printf("\n");
        printf("\nkey Generated : Y");
        for (loopCounter_U32=0; loopCounter_U32 <  PublicKey_S.Ycrd_S.length_U32; loopCounter_U32++) {
                printf("0x%x ",PublicKey_S.Ycrd_S.data_U8P[loopCounter_U32]);
            }
        printf("\n Signature Generation ECDSA Successfull \n");
    }
    res = Crypto_SHA384_Start(ctx);
    if (res == TEEC_SUCCESS) 
    {
        l_dataFile_SP = fopen("/update-cache/ext4-system-partition.img", "rb");

        if (l_dataFile_SP != NULL)
        {
            while ((uint8_t)0 != (bytes_read = fread(data_to_cal_hash, 1, DATA_SIZE, l_dataFile_SP))) {
                Plaintext_S.data_U8P     = &data_to_cal_hash[0];
                res = Crypto_SHA384_Update(ctx, &Plaintext_S);
                if (res != TEEC_SUCCESS){
                    printf("\n Digest calculation update failed 0x%08x", res);
                    return res;
                }
            }
            res = Crypto_SHA384_Final(ctx, &Digest_S);
            if (res != TEEC_SUCCESS){
                printf("\n Digest calculation Final failed 0x%08x", res);
                return res;
            }
            else {
                printf("\nDigest calculate : ");
                for (loopCounter_U32=0; loopCounter_U32 < Digest_S.length_U32; loopCounter_U32++) {
                    printf("0x%x ",Digest_S.data_U8P[loopCounter_U32]);
                }
                printf("\n");
            }
        }
        res = Privatesecurestorage_opteeapi(ctx, PrivateKey_S.data_U8P, PrivateKey_S.length_U32,
                                               IPSEC_KEY_ID, IPSEC_KEY_ID_LEN);
       if (res == TEEC_SUCCESS) 
       {
           printf("\nIPsec PEM key stored in secure storage\n");
       
            res = Crypto_ECDSA_P384_sign_generate(ctx, IPSEC_KEY_ID, IPSEC_KEY_ID_LEN, &Digest_S, &signature_S);
            if(res != TEEC_SUCCESS)
            {
                printf("\n Crypto_ECDSA_PHA256_Sign_generate failure ");
            }
            else
            {
                printf("\nSignature Generated : ");
                for (loopCounter_U32=0; loopCounter_U32 < signature_S.length_U32; loopCounter_U32++) {
                        printf("0x%x ",signature_S.data_U8P[loopCounter_U32]);
                    }
                printf("\n");
                printf("Signature Generation ECDSA Successfull");
            }
        } 
        else {
           printf("\nFailed to store IPsec key: 0x%08x\n", res);
        }
        res = Crypto_ECDSA_P384_Verify(ctx, &Digest_S, &signature_S, &PublicKey_S);
        if(res != TEEC_SUCCESS)
        {
            printf("\n Crypto_ECDSA_PHA256_Verify failure ");
        }
        else
        {
            printf("\n Signature Verification ECDSA Successfull");
        }
    }
    return res;
}

TEEC_Result certificate_verification(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res = TEEC_ERROR_GENERIC;

    uint8_t l_certificate_buf_SP[4096];
    uint8_t l_ca_certificate_buf_SP[4096];
    uint8_t *l_heap_buf_SP = NULL;
    uint8_t *l_heap1_buf_SP = NULL;

    ts_pointerType Certificate_S;
    ts_pointerType CA_Certificate_S;

    FILE *l_fp_cert_SP = NULL;
    FILE *l_fp_ca_SP   = NULL;
    size_t l_bytes_read_cert_SP = 0;
    size_t l_bytes_read_ca_SP   = 0;

    // ---- Load certificate to verify ----
    l_fp_cert_SP = fopen("/etc/swanctl/x509/device1-cert.pem", "rb");
    if (!l_fp_cert_SP) {
        printf("Error: Unable to open device certificate\n");
    }
    else{
        l_bytes_read_cert_SP = fread(l_certificate_buf_SP, 1, sizeof(l_certificate_buf_SP), l_fp_cert_SP);
        l_heap_buf_SP = malloc(l_bytes_read_cert_SP + 1);
        memcpy(l_heap_buf_SP, l_certificate_buf_SP, l_bytes_read_cert_SP);
        l_heap_buf_SP[l_bytes_read_cert_SP] = '\0';
        fclose(l_fp_cert_SP);

        if (l_bytes_read_cert_SP == 0) {
            printf("Error: Device certificate is empty or could not be read\n");
        }
        else{
            Certificate_S.data_U8P   = &l_heap_buf_SP[0];
            Certificate_S.length_U32 = l_bytes_read_cert_SP + 1;  // Include null terminator length in size

            // ---- Load CA certificate ----
            l_fp_ca_SP = fopen("/etc/swanctl/x509ca/ca-cert.pem", "rb");
            if (!l_fp_ca_SP) {
                printf("Error: Unable to open CA certificate\n");
            }
            else{
                l_bytes_read_ca_SP = fread(l_ca_certificate_buf_SP, 1, sizeof(l_ca_certificate_buf_SP), l_fp_ca_SP);
                l_heap1_buf_SP = malloc(l_bytes_read_ca_SP + 1);
                memcpy(l_heap1_buf_SP, l_ca_certificate_buf_SP, l_bytes_read_ca_SP);
                l_heap1_buf_SP[l_bytes_read_ca_SP] = '\0';
                fclose(l_fp_ca_SP);
                if (l_bytes_read_ca_SP == 0) {
                    printf("Error: CA certificate is empty or could not be read\n");
                }

                CA_Certificate_S.data_U8P   = &l_heap1_buf_SP[0];
                CA_Certificate_S.length_U32 = l_bytes_read_ca_SP + 1; // Include null terminator length in size
            }
        }
    }
        // ---- Invoke TA to verify certificate ----
    res = Crypto_Certificate_Verification(ctx, &Certificate_S, &CA_Certificate_S);
    if (res != TEEC_SUCCESS) {
        printf("\nCertificate_Verify failure (0x%x)\n", res);
    } else {
        printf("\nCertificate Verification Successful\n");
    }

    return res;
}

// CMAC Generation and Verification
static const uint8_t CMAC_TEST_MSG[] = "Hello Visteon, input for AES128CMAC";
uint8_t mac_tag[16] = {0x71, 0x33, 0x34, 0xb6, 0x69, 0xe0, 0x79, 0x1b, 0x3b, 0xd4, 0x3f, 0x55, 0xc2, 0xdd, 0xc5, 0x85};

TEEC_Result Cmac_Generate_Test(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint32_t i;
    uint8_t mac_buf[16] = {0};
    ts_pointerType input_s;
    ts_pointerType mac_s;

    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("\n [TEST STUB] CMAC Gen - KeyID: %s\n", keyid);

    input_s.data_U8P   = (uint8_t *)CMAC_TEST_MSG;
    input_s.length_U32 = sizeof(CMAC_TEST_MSG);

    mac_s.data_U8P     = mac_buf;
    mac_s.length_U32   = sizeof(mac_buf);

    res = Crypto_CMAC_Generate(ctx, keyid, keyid_size, &input_s, &mac_s);

    if (res == TEEC_SUCCESS) {
        printf(" [TEST STUB] Generated Tag: ");
        for(i=0; i<16; i++) printf("%02x", mac_buf[i]);
        printf("\n [TEST STUB] PASS\n");
    } else {
        printf(" [TEST STUB] FAIL (0x%08x)\n", res);
    }
    return res;
}

TEEC_Result Cmac_Verify_Test(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint32_t i;

    ts_pointerType input_s;
    ts_pointerType mac_s;

    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    printf("\n [TEST STUB] CMAC Verify - KeyID: %s\n", keyid);

    input_s.data_U8P   = (uint8_t *)CMAC_TEST_MSG;
    input_s.length_U32 = sizeof(CMAC_TEST_MSG);

    mac_s.data_U8P     = mac_tag;
    mac_s.length_U32   = sizeof(mac_tag);

    printf("   -> Input MAC: ");
    for(i = 0; i < 16; i++) {
        printf("%02x", mac_tag[i]);
    }
    printf("\n");

    printf(" [TEST STUB] Verifying ");
    res = Crypto_CMAC_Verify(ctx, keyid, keyid_size, &input_s, &mac_s);

    if (res == TEEC_SUCCESS) {
        printf(" [TEST STUB] PASS (Signatures Match)\n");
    } else {
        printf(" [TEST STUB] FAIL (0x%x) - Signatures Mismatch\n", res);
    }

    return res;
}

// CMAC GENERATION TEST (Start -> Update -> Finish)
TEEC_Result Cmac_Generate_Test_StartUpdateFinish(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint8_t mac_buf[16] = {0};
    uint32_t i;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    ts_pointerType input_data;
    ts_pointerType output_data;

    input_data.data_U8P     = (uint8_t *)CMAC_TEST_MSG;
    input_data.length_U32   = sizeof(CMAC_TEST_MSG);

    output_data.data_U8P    = mac_buf;
    output_data.length_U32  = sizeof(mac_buf);

    printf("\n [TEST STUB] CMAC Generation (start update finish API)\n");
    printf("   -> Input Data: \"%s\"\n", CMAC_TEST_MSG);

    res = Crypto_CMAC_Gen_Start(ctx, keyid, keyid_size);

    if (res == TEEC_SUCCESS) {

        res = Crypto_CMAC_Gen_Update(ctx, &input_data);

        if (res == TEEC_SUCCESS) {

            res = Crypto_CMAC_Gen_Finish(ctx, &output_data);

            if (res == TEEC_SUCCESS) {
                printf("   -> Generated Tag: ");
                for(i = 0; i < 16; i++) {
                    printf("%02x", mac_buf[i]);
                }
                printf("\n   -> PASS\n");
            } else {
                printf("   -> Finish Failed: 0x%08x\n", res);
            }
        } else {
            printf("   -> Update Failed: 0x%08x\n", res);
        }
    } else {
        printf("   -> Start Failed: 0x%08x\n", res);
    }

    return res;
}

// CMAC VERIFICATION TEST (Start -> Update -> Finish)
TEEC_Result Cmac_Verify_Test_StartUpdateFinish(struct TEE_resource_ctx *ctx)
{
    TEEC_Result res;
    uint32_t i;
    char keyid[15] = "Secure_blob";
    uint32_t keyid_size = strlen(keyid);

    ts_pointerType input_data;
    ts_pointerType mac_s;

    input_data.data_U8P     = (uint8_t *)CMAC_TEST_MSG;
    input_data.length_U32   = sizeof(CMAC_TEST_MSG);

    mac_s.data_U8P   = mac_tag;
    mac_s.length_U32 = sizeof(mac_tag);

    printf("\n [TEST STUB] CMAC Verification (start update finish API)\n");
    printf("   -> Verifying against Hardcoded MAC: ");
    for(i = 0; i < 16; i++) printf("%02x", mac_tag[i]);
    printf("\n");

    res = Crypto_CMAC_Ver_Start(ctx, keyid, keyid_size);

    if (res == TEEC_SUCCESS) {

        res = Crypto_CMAC_Ver_Update(ctx, &input_data);

        if (res == TEEC_SUCCESS) {

            res = Crypto_CMAC_Ver_Finish(ctx, &mac_s);

            if (res == TEEC_SUCCESS) {
                printf("   -> PASS (Signatures Match)\n");
            }
            else if (res == TEE_ERROR_MAC_INVALID) {
                printf("   -> FAIL (MAC Invalid - Mismatch)\n");
            }
            else {
                printf("   -> FAIL (Error 0x%08x)\n", res);
            }
        } else {
            printf("   -> Update Failed: 0x%08x\n", res);
        }
    } else {
        printf("   -> Start Failed: 0x%08x\n", res);
    }

    return res;
}

int main(int argc, char *argv[]) {

    struct TEE_resource_ctx ctx;
    TEEC_Result result = TEEC_ERROR_GENERIC;
    void *request;
    uint32_t key_cnt = 0, key_rev = 0;

    get_args(argc, argv, &request);
    prepare_tee_session_securestorage_crypto(&ctx);

    if (strcmp(request,"storekey") == 0) {
        result = securestorage(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("securestorage pass\n");
        }
        else {
            printf("securestorage fail\n");
        }
    }
    else if (strcmp(request,"decryptfile") == 0) {
        result = Aes128Cbcfiledecryption(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128Cbcfiledecryption pass\n");
        }
        else {
            printf("Aes128Cbcfiledecryption fail\n");
        }
    }
    else if (strcmp(request,"Digest") == 0) {
        for(uint8_t i =0; i < (uint8_t)4; i++){
            result = SHA256MultiCall(&ctx);
            if (result == TEEC_SUCCESS) {
                printf("SHA256 pass\n");
            }
            else {
                printf("SHA256 fail\n");
            }
        }
    }
    else if (strcmp(request,"encryptstringwithpad") == 0) {
        result = Aes128Cbcencryptionwithpkcs7pad(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128Cbcencryptionwithpkcs7pad pass\n");
        }
        else {
            printf("Aes128Cbcencryptionwithpkcs7pad fail\n");
        }
    }
    else if (strcmp(request,"decryptstringwithpad") == 0) {       
        result = Aes128Cbcdecryptionwithpkcs7pad_largerchunk(&ctx);    
        if (result == TEEC_SUCCESS) {
            printf("Aes128Cbcdecryptionwithpkcs7pad pass\n");
        }
        else {
            printf("Aes128Cbcdecryptionwithpkcs7pad fail\n");
        }
    }
    else if (strcmp(request, "encryptstringwithpad_gcm") == 0) {
        result = Aes128GcmEncryption(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128GcmEncryption pass\n");
        }
        else {
            printf("Aes128GcmEncryption fail\n");
        }
    }    
    else if (strcmp(request, "decryptstringwithpad_gcm") == 0) {
        result = Aes128GcmDecryption(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128GcmDecryption pass\n");
        }
        else {
            printf("Aes128GcmDecryption fail\n");
        }        
    }
    else if (strcmp(request, "ECB_encryptstringwopad") == 0) {
        result = Aes128Ecbencryptionwopad(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128Ecbencryptionwopad pass\n");
        } else {
            printf("Aes128Ecbencryptionwopad fail\n");
        }
    }
    else if (strcmp(request, "ECB_decryptstringwopad") == 0) {
        result = Aes128Ecbdecryptionwopad(&ctx);     
        if (result == TEEC_SUCCESS) {
            printf("Aes128Ecbdecryptionwopad pass\n");
        } else {
            printf("Aes128Ecbdecryptionwopad fail\n");
        }
    }                 
    else if (strcmp(request,"encryptstringwopad") == 0) {
        result = Aes128Cbcencryptionwopad(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128Cbcencryptionwopad pass\n");
        }
        else {
            printf("Aes128Cbcencryptionwopad fail\n");
        }
    }
    else if (strcmp(request,"decryptstringwopad") == 0) {
        result = Aes128Cbcdecryptionwopad(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Aes128Cbcdecryptionwopad pass\n");
        }
        else {
            printf("Aes128Cbcdecryptionwopad fail\n");
        }
    }
    else if (strcmp(request,"signverify2k") == 0) {
        result = Rsassapkcs1v5signverify2k(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Rsassapkcs1v5signverify2k pass\n");
        }
        else {
            printf("Rsassapkcs1v5signverify2k fail\n");
        }
    }
    else if (strcmp(request,"signverify3k") == 0) {
        result = Rsassapkcs1v5signverify3k(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Rsassapkcs1v5signverify3k pass\n");
        }
        else {
            printf("Rsassapkcs1v5signverify3k fail\n");
        }
    }
    else if (strcmp(request,"ecdsaverify") == 0) {
        result = Ecdsasignverify(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Ecdsasignverify pass\n");
        }
        else {
            printf("Ecdsasignverify fail\n");
        }
    }
    else if (strcmp(request,"signgenerate") == 0) {
        result = Ecdsasigngenerate(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("Ecdsasign generation pass\n");
        }
        else {
            printf("Ecdsasign generate fail\n");
        }
    }
    else if (strcmp(request,"ecdsahash") == 0) {
        result = Ecdsasignverify_largechunk(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("\nEcdsahash pass\n");
        }
        else {
            printf("\nEcdsahash fail\n");
        }
    }
    else if (strcmp(request,"keygen") == 0) {
        result = Ecdsa_keygenerate(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("\nEcdsa_keygenerate pass\n");
        }
        else {
            printf("\nEcdsa_keygenerate fail\n");
        }
    }
     else if (strcmp(request,"certverify") == 0) {
        result = certificate_verification(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("certificate_verification pass\n");
        }
        else {
            printf("certificate_verification fail\n");
        }
    }
    else if (strcmp(request,"keycnt_rev") == 0) {
        terminate_tee_session_securestorage_crypto(&ctx);
        otp_prepare_tee_session((struct test_ctx *)&ctx);
        result = get_keyrev_keycnt((struct test_ctx *)&ctx, &key_cnt, &key_rev);
        if (result == TEEC_SUCCESS) {
            printf("get_keyrev_keycnt pass - key_cnt : %d , key_rev : %d \n", key_cnt, key_rev);
        }
        else {
            printf("get_keyrev_keycnt:  fail\n");
        }
        otp_terminate_tee_session((struct test_ctx *)&ctx);
    }
    else if (strcmp(request, "cmac_gen") == 0) {
        result = Cmac_Generate_Test(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("CMAC Generation PASS\n");
        } else {
            printf("CMAC Generation FAIL\n");
        }
    }
    else if (strcmp(request, "cmac_verify") == 0) {
        result = Cmac_Verify_Test(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("CMAC Verification PASS\n");
        } else {
            printf("CMAC Verification FAIL\n");
        }
    }
    else if (strcmp(request, "cmac_gen_startupdatefinish") == 0) {
        result = Cmac_Generate_Test_StartUpdateFinish(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("CMAC Generation (Start update finish) PASS\n");
        } else {
            printf("CMAC Generation (Start update finish) FAIL\n");
        }
    }
    else if (strcmp(request, "cmac_verify_startupdatefinish") == 0) {
        result = Cmac_Verify_Test_StartUpdateFinish(&ctx);
        if (result == TEEC_SUCCESS) {
            printf("CMAC Verification (Start update finish) PASS\n");
        } else {
            printf("CMAC Verification (Start update finish) FAIL\n");
        }
    }
    else {
        printf("Invalid option\n");

    }

    terminate_tee_session_securestorage_crypto(&ctx);
    return result;
}
