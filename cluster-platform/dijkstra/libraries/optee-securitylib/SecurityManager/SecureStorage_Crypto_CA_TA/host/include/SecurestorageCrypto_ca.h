/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2022] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file SecurestorageCrypto_ca.h
 *
 * \brief
 * Main Implementation of Securitymanager library optee Client application 
 * optee-os version 4.2.0
 *
 * \version 1.1.0
 * |Version | Date       | Author         | Task Id 		 | Description                                                           						  |
 * |--------|------------|----------------|------------------|------------------------------------------------------------------------------------------------|
 * |1.00.00 | 2024-12-14 | vpandia1       | TFDCX32348-61053 | Implement Secure storage, AES128CBC enc/dec with pkcs7 pad , File decryption with nopad, SHA256|
 * |1.01.00 | 2025-11-27 | hsriniv5       | BMIC29130-38362  | Implement ECDSA key storage, ECDSA Key generate, ECDSA sign generate and verification, SHA384 HASH Calculation|
*/
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 

/* OP-TEE TEE client API (built by optee_client) */
#include <tee_client_api.h>

/* TA API: UUID and command IDs */
#include <SecurestorageCrypto_ta.h>

/**
 * A structure to represent a OPTEE context and session
 */
struct TEE_resource_ctx {
	TEEC_Context ctx;
	TEEC_Session sess;
};

typedef struct {
	uint8_t  *data_U8P;
	uint32_t  length_U32;
}ts_pointerType;

/**
 * A structure to represent a public key.
 */
typedef struct
{
    ts_pointerType modulus_S; /**< The public modulus */
    ts_pointerType exponent_S; /**< The public exponent */
} ts_publicKey;
typedef struct {
    ts_pointerType Xcrd_S;  /**< X coordinate of the public key */
    ts_pointerType Ycrd_S;  /**< Y coordinate of the public key */
} ts_ecdsaPublicKey;

#define AES_GCM_TAG_SIZE 16U
#define AES_GCM_IV_RECOMMENDED_LEN 12U
#define AES_SHA512_SIZE 64U
//#define CA_VERBOSE

/****************************************************************************
** This interface shall used to create a context and open a TEE session
** with respective TA UUID
**
** \param [out] ctx
**
*****************************************************************************/
void prepare_tee_session_securestorage_crypto(struct TEE_resource_ctx *ctx);



/****************************************************************************
** This interface shall used to delete a context and open a TEE session
** with respective TA UUID
**
** \param [in] ctx
** structure to handle TEE context and session open
**
*****************************************************************************/
void terminate_tee_session_securestorage_crypto(struct TEE_resource_ctx *ctx);



/****************************************************************************
** This interface shall used to set the user provided key
** with respective TA UUID
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] key
** pointer to carry user provided key
**
** \param [in] key_len
**  Length of user key
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully for cipher operations
**
*****************************************************************************/
TEEC_Result Crypto_SetuserAesKey(struct TEE_resource_ctx *ctx, uint8_t *key, size_t key_len);


/****************************************************************************
** This interface shall used to set the key from Blob with respective to TA
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] key_id
** pointer to carry the keyid (blob name)
**
** \param [in] keyid_size
**  variable should carry keyid_size (blob name size)
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if keyid setted successfully from requested blob for cipher operations
**
*****************************************************************************/
TEEC_Result Crypto_GetKeyFromBlob(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size);


/****************************************************************************
** This interface shall used to perform AES 128 CBC encryption with Pkcs7 padding
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext to be encrypted
**
** \param [in] InitialVector
** pointer to carry the InitialVector
**
** \param [in] InitialVectorSize
**  Length of InitialVector
**
** \param [out] ciphertext
** pointer where the output encrypted data will be stored.
**
** \param [out] cipherSize
**  Length of cipherSize
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if AES 128 CBC encryption performed successfully
**
*****************************************************************************/
TEEC_Result Crypto_AES128CbcEncryptionWithPkcs7Pad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext,
			const ts_pointerType *InitialVector, ts_pointerType *ciphertext);

/****************************************************************************
** This interface shall used to perform AES 128 CBC decryption with Pkcs7 padding
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] ciphertext
** pointer to carry the ciphertext
**
** \param [in] cipherSize
**  Length of cipher data to be encrypted
**
** \param [in] InitialVector
** pointer to carry the InitialVector
**
** \param [in] InitialVectorSize
**  Length of InitialVector
**
** \param [out] Plaintext
** pointer where the output decrypted data will be stored.
**
** \param [out] PlaintextLen
**  Length of Plaintext
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if AES 128 CBC decryption performed successfully
**
*****************************************************************************/

TEEC_Result Crypto_AES128CbcDecryptionWithPkcs7Pad(struct TEE_resource_ctx *ctx,const char* key_id, uint32_t keyid_size, const ts_pointerType *ciphertext,
			const ts_pointerType *InitialVector, ts_pointerType *Plaintext);

/****************************************************************************
** This interface is used to perform AES 128 GCM encryption
**
** \param [in] ctx
** Structure containing TEE context and session information
**
** \param [in] key_id
** Pointer to the key identifier used for key retrieval
**
** \param [in] keyid_size
** Size of the key identifier
**
** \param [in] Plaintext
** Pointer structure containing the plaintext to be encrypted
**
** \param [in] InitialVector
** Pointer structure containing the initialization vector (IV)
**
** \param [in] AdditionalData
** Pointer structure containing the additional authenticated data (AAD),
** which is authenticated but not encrypted (can be NULL if not used)
**
** \param [out] ciphertext
** Pointer structure where the encrypted data will be stored
**
** \param [out] Tag
** Pointer structure where the GCM authentication tag will be stored
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if AES 128 GCM encryption is performed successfully
** - TEEC_ERROR_SHORT_BUFFER if the output buffers are too small
** - TEEC_ERROR_ITEM_NOT_FOUND if the key is not found
** - Other TEEC error codes in case of failure
**
*****************************************************************************/
TEEC_Result Crypto_AES128GcmEncrypt(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext,
                                     const ts_pointerType *InitialVector, ts_pointerType *AdditionalData, ts_pointerType *ciphertext, ts_pointerType *Tag);

/****************************************************************************
** This interface is used to perform AES 128 GCM decryption
**
** \param [in] ctx
** Structure containing TEE context and session information
**
** \param [in] key_id
** Pointer to the key identifier used for key retrieval
**
** \param [in] keyid_size
** Size of the key identifier
**
** \param [in] ciphertext
** Pointer structure containing the ciphertext to be decrypted
**
** \param [in] InitialVector
** Pointer structure containing the initialization vector (IV)
**
** \param [in] Tag
** Pointer structure containing the GCM authentication tag
**
** \param [out] Plaintext
** Pointer structure where the decrypted plaintext will be stored
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if AES 128 GCM decryption is performed successfully
** - TEEC_ERROR_SHORT_BUFFER if output buffer is too small
** - TEEC_ERROR_ITEM_NOT_FOUND if key is not found
** - Other TEEC error codes in case of failure
**
*****************************************************************************/
TEEC_Result Crypto_AES128GcmDecrypt(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size,
                                    const ts_pointerType *ciphertext, const ts_pointerType *InitialVector,
                                    const ts_pointerType *Tag, ts_pointerType *Plaintext);

/**
 * @brief Encrypts a plaintext buffer using AES-128 ECB with no padding.
 *
 * @param ctx        Pointer to TEE resource context.
 * @param key_id     Key identifier used to derive or locate the AES key.
 * @param keyid_size Size of the key identifier.
 * @param Plaintext  Pointer to input plaintext data (must be multiple of 16 bytes).
 * @param Ciphertext Pointer to output ciphertext buffer.
 *
 * @return TEEC_Result indicating success or failure.
 */
TEEC_Result Crypto_AES128EcbEncryptionWithNoPad(
    struct TEE_resource_ctx *ctx,
    const char* key_id,
    const uint32_t keyid_size,
    const ts_pointerType *Plaintext,
    ts_pointerType *Ciphertext);

/**
 * @brief Decrypts a ciphertext buffer using AES-128 ECB with no padding.
 *
 * @param ctx        Pointer to TEE resource context.
 * @param key_id     Key identifier used to derive or locate the AES key.
 * @param keyid_size Size of the key identifier.
 * @param Ciphertext Pointer to input ciphertext data (must be multiple of 16 bytes).
 * @param Plaintext  Pointer to output plaintext buffer.
 *
 * @return TEEC_Result indicating success or failure.
 */
TEEC_Result Crypto_AES128EcbDecryptionWithNoPad(
    struct TEE_resource_ctx *ctx,
    const char* key_id,
    const uint32_t keyid_size,
    const ts_pointerType *Ciphertext,
    ts_pointerType *Plaintext);											   

/****************************************************************************
** This interface shall used to perform AES 128 CBC encryption with Pkcs7 padding
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext to be encrypted
**
** \param [in] InitialVector
** pointer to carry the InitialVector
**
** \param [in] InitialVectorSize
**  Length of InitialVector
**
** \param [out] ciphertext
** pointer where the output encrypted data will be stored.
**
** \param [out] cipherSize
**  Length of cipherSize
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if AES 128 CBC encryption performed successfully
**
*****************************************************************************/
TEEC_Result Crypto_AES128CbcEncryptionWithNoPad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *Plaintext,
			const ts_pointerType *InitialVector, ts_pointerType *ciphertext);


/****************************************************************************
** This interface shall used to perform AES 128 CBC decryption with Pkcs7 padding
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] ciphertext
** pointer to carry the ciphertext
**
** \param [in] cipherSize
**  Length of cipher data to be encrypted
**
** \param [in] InitialVector
** pointer to carry the InitialVector
**
** \param [in] InitialVectorSize
**  Length of InitialVector
**
** \param [out] Plaintext
** pointer where the output decrypted data will be stored.
**
** \param [out] PlaintextLen
**  Length of Plaintext
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if AES 128 CBC decryption performed successfully
**
*****************************************************************************/
TEEC_Result Crypto_AES128CbcDecryptionWithNoPad(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *ciphertext,
			const ts_pointerType *InitialVector, ts_pointerType *Plaintext);


/****************************************************************************
** This interface shall used to compute SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext
**
** \param [out] Digest
** pointer to store computed hash
**
** \param [out] DigestSize
**  Length of Digest
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA256(struct TEE_resource_ctx *ctx,
			const ts_pointerType *Plaintext, ts_pointerType *Digest);


/****************************************************************************
** This interface shall used to store the key/data as encrypted persist object
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] key_id
** pointer to carry the keyid (blob name)
**
** \param [in] keyid_size
**  variable should carry keyid_size (blob name size)
**
** \param [in] data
** pointer to carry data/key to stored in persist encrypted blob/object
**
** \param [in] data_len
**  Length of data to be stored in persist object
**
** \param [in] enc_m1
** Encrypted M1 block
**
** \param [in] enc_m2
** Encrypted M2 block (used for decryption).
**
** \param [in] enc_m3
** Encrypted M3 block
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if persist objected created and key/data stored successfully
**
*****************************************************************************/
TEEC_Result SecureStorageCreateAndStore_CA(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size,  const ts_pointerType *enc_m1, const ts_pointerType *enc_m2, const ts_pointerType *enc_m3);



/****************************************************************************
** This interface shall used to decrypt larger chunk/file using persist blob key
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] key_id
** pointer to carry the keyid (blob name)
**
** \param [in] keyid_size
**  variable should carry keyid_size (blob name size)
**
** \param [in] p_InitialVectorPtr_pU8
** pointer to carry the InitialVector
**
** \param [in] p_InitialVectorLength_pU8
**  Length of InitialVector
**
** \param [in] p_cipherTextFile_p
** File  pointer should have input file/chunk name which need to be decrypted
** 
** \param [out] p_plainTextFile_p
** File  pointer should have output file/chunk name were decrypted data 
** will be stored
** 
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if requested chunk/file will be decrypted using persist key blob
**
*****************************************************************************/

TEEC_Result SecurityManagerAes128CbcDecryptionfile(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const uint8_t* p_InitialVectorPtr_pU8,
                                          uint8_t p_InitialVectorLength_pU8, FILE* p_cipherTextFile_p, FILE* p_plainTextFile_p);
								
/****************************************************************************
** This interface shall used to set the user provided key
** with respective TA UUID
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] p_publicKey_SP
** Pointer to public key structure
**
** \param [in] key_len
** To store 2k or 3k key
** key_len = 2 -> to store 2k bits key
** key_len = 3 -> to store 3k bits key
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully for cipher operations
**
*****************************************************************************/
TEEC_Result Crypto_SetuserRsaPubKey(struct TEE_resource_ctx *ctx, const ts_publicKey *p_publicKey_SP, uint8_t key_len);


/****************************************************************************
** This interface shall used to verify the signature using rsa sha256 
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] message
** pointer to carry the digest
**
** \param [in] signature
**  pointer to carry the signature
**
** \param [in] p_publicKey_S
** pointer to carry key
**
** \param [in] key_len
** To check 2k or 3k sign verify
** key_len = 2 -> 2k sign verify
** key_len = 3 -> 3k sign verify
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully for cipher operations
**
*****************************************************************************/
TEEC_Result Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify(struct TEE_resource_ctx *ctx, const ts_pointerType *message, const ts_pointerType *signature, uint8_t key_len); 

/****************************************************************************
** This interface shall used to start compute SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA256_Start(struct TEE_resource_ctx *ctx);

/****************************************************************************
** This interface shall used to update digest SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA256_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext);

/****************************************************************************
** This interface shall used to finalize and generate the computed SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [out] Digest
** pointer to store computed hash
**
** \param [out] DigestSize
**  Length of Digest
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA256_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest);

/****************************************************************************
** This interface initializes AES-128 CBC decryption by setting up the key and IV.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] Key  
** Pointer to the decryption key (128-bit).
**
** \param [in] IV  
** Pointer to the initialization vector (128-bit).
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if decryption context was initialized successfully.
**
*****************************************************************************/
TEEC_Result Crypto_AES128CBC_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType* iv);

/****************************************************************************
** This interface decrypts a block of ciphertext data using AES-128 CBC.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] Ciphertext  
** Pointer to the buffer where decrypted data will be stored.
**
** \param [out] Plaintext  
** Pointer to the output buffer where the resulting plaintext will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the decryption of the current block was successful.
**
*****************************************************************************/
TEEC_Result Crypto_AES128CBC_Decrypt_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Ciphertext, ts_pointerType *Plaintext);

/****************************************************************************
** This interface finalizes AES-128 CBC decryption and processes the final block.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [out] Plaintext  
** Pointer to the buffer where the final plaintext block will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the final decryption step was completed successfully.
**
*****************************************************************************/
TEEC_Result Crypto_AES128CBC_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext);

/****************************************************************************
** This interface shall used to check the Symmetric key set status
** with respective TA UUID , whether key retrived from blob or not
**
** \param [in] ctx
**
*****************************************************************************/
TEEC_Result Crypto_SymKeyCheckStatus(struct TEE_resource_ctx *ctx);

/****************************************************************************
** This interface initiates AES-128 GCM decryption by setting the IV and verifying key status.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] key_id  
** Pointer to the key identifier used for secure blob retrieval.
**
** \param [in] keyid_size  
** Size of the key identifier buffer.
**
** \param [in] iv  
** Pointer to the IV (Initialization Vector) used in GCM decryption.
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if GCM decryption initialization was successful.
**
*****************************************************************************/
TEEC_Result Crypto_AES128GCM_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType* iv);

/****************************************************************************
** This interface decrypts a block of ciphertext data using AES-128 GCM.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] Ciphertext  
** Pointer to the buffer containing encrypted input data.
**
** \param [out] Plaintext  
** Pointer to the output buffer where the resulting plaintext will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if the decryption of the current block was successful.
**
*****************************************************************************/
TEEC_Result Crypto_AES128GCM_Decrypt_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Ciphertext, ts_pointerType *Plaintext);

/****************************************************************************
** This interface finalizes AES-128 GCM decryption and processes the final block with authentication tag.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [out] Plaintext  
** Pointer to the buffer where the final plaintext block will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if the final decryption and authentication check was successful.
**
*****************************************************************************/
TEEC_Result Crypto_AES128GCM_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext, ts_pointerType *Tag);

/****************************************************************************
** This interface initializes AES-128 ECB decryption by verifying or loading the key.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] key_id  
** Pointer to the decryption key ID.
**
** \param [in] keyid_size  
** Length of the key_id in bytes.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the decryption context was initialized successfully.
**
*****************************************************************************/
TEEC_Result Crypto_AES128ECB_Decrypt_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size);

/****************************************************************************
** This interface decrypts a block of ciphertext data using AES-128 ECB.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] Ciphertext  
** Pointer to the ciphertext buffer to be decrypted.
**
** \param [out] Plaintext  
** Pointer to the output buffer where the resulting plaintext will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the decryption of the current block was successful.
**
*****************************************************************************/
TEEC_Result Crypto_AES128ECB_Decrypt_Update(struct TEE_resource_ctx *ctx, ts_pointerType *Ciphertext, ts_pointerType *Plaintext);

/****************************************************************************
** This interface finalizes AES-128 ECB decryption and processes the last block.
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [out] Plaintext  
** Pointer to the buffer where the final plaintext block will be stored.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the final decryption step was completed successfully.
**
*****************************************************************************/
TEEC_Result Crypto_AES128ECB_Decrypt_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Plaintext);

/****************************************************************************
** This interface shall used to set the user provided key
** with respective TA UUID
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] p_publicKey_SP
** Pointer to public key structure
**
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully for cipher operations
**
*****************************************************************************/
TEEC_Result Crypto_SetuserEcdsaPubKey(struct TEE_resource_ctx *ctx, const ts_ecdsaPublicKey *p_publicKey_SP);

/****************************************************************************
** This interface shall used to verify the signature using ecdsa p384 
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] message
** pointer to carry the digest
**
** \param [in] signature
**  pointer to carry the signature
**
** \param [in] p_publicKey_SP
**  pointer to carry the public key
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if ecdsa signature verification
**
*****************************************************************************/
TEEC_Result Crypto_ECDSA_P384_Verify(struct TEE_resource_ctx *ctx, const ts_pointerType *message, const ts_pointerType *signature, const ts_ecdsaPublicKey *p_publicKey_SP);

/****************************************************************************
** This interface shall used to generate the signature using ecdsa p384 
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] message
** pointer to carry the digest
**
** \param [in] signature
**  pointer to carry the signature
**
** \param [in] p_privateKey_SP
**  pointer to carry the privake key 
**  
** \param [in] p_publicKey_SP
**  pointer to carry the public key
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if ecdsa signature generation successfully
**
*****************************************************************************/
TEEC_Result Crypto_ECDSA_P384_sign_generate(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size, const ts_pointerType *message, ts_pointerType *signature);

/****************************************************************************
** This interface shall used to set the user provided key
** with respective TA UUID
**
** \param [in] ctx
** structure where TEE context and session open
**
**\param [in] p_privateKey_SP
** Pointer to private key structure
**
** \param [in] p_publicKey_SP
** Pointer to public key structure
**
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully 
**
*****************************************************************************/
TEEC_Result Crypto_SetuserEcdsaPrivKey(struct TEE_resource_ctx *ctx, const ts_pointerType *p_privateKey_SP, const ts_ecdsaPublicKey *p_publicKey_SP);

/****************************************************************************
** This interface shall used to generate the ecdsa key
**
** \param [in] ctx
** structure where TEE context and session open
**
**\param [out] p_privateKey_SP
** Pointer to private key structure
**
** \param [out] p_publicKey_SP
** Pointer to public key structure
**
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if user key setted successfully 
**
*****************************************************************************/
TEEC_Result Crypto_ECDSA_P384_key_generate(struct TEE_resource_ctx *ctx, ts_pointerType *p_privateKey_SP, ts_ecdsaPublicKey *p_publicKey_SP);

/****************************************************************************
** This interface is used to initialize and perform operations related to
** private secure storage using the OP-TEE API.
**
** \param [in] ctx
** Structure where the TEE context and session are managed.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the secure storage operation was initialized
**   and executed successfully.
** - Appropriate TEEC error code if initialization or access fails.
**
*****************************************************************************/
TEEC_Result Privatesecurestorage_opteeapi(struct TEE_resource_ctx *ctx, uint8_t *pem_data, uint32_t pem_len, char *key_id, uint32_t key_id_len);

/****************************************************************************
** This interface is used to retrieve the IPSec key from the OP-TEE secure
** storage and export it to a specified StrongSwan configuration path.
**
** \param [in] ctx
** Structure where the TEE context and session are managed.
**
** \param [in] swanctl_path
** Path to the StrongSwan configuration file (swanctl) where
** the retrieved key will be stored or updated.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if the IPSec key is successfully retrieved and
**   stored in the specified swanctl path.
** - Appropriate TEEC error code if retrieval or export fails.
**
*****************************************************************************/
TEEC_Result RetrieveIpsecKeyFromOPTEE(struct TEE_resource_ctx *ctx, const char *output_path, char *key_id, uint32_t key_id_len);
/****************************************************************************
** This interface shall used to start compute SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA384_Start(struct TEE_resource_ctx *ctx);

/****************************************************************************
** This interface shall used to update digest SHA384 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA384_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext);

/****************************************************************************
** This interface shall used to finalize and generate the computed SHA256 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [out] Digest
** pointer to store computed hash
**
** \param [out] DigestSize
**  Length of Digest
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA256
**
*****************************************************************************/
TEEC_Result Crypto_SHA384_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest);

/****************************************************************************
** This interface shall used to verify the ca and chain of certificate using ecdsa sha384 algo
**
** \param [in] ctx  
** Structure where TEE context and session are stored.
**
** \param [in] certificate  
** Pointer to the chain certificate.
**
** \param [in] ca_cert  
** Pointer to theca certificate.
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if certificate verification is  successfull.
**
*****************************************************************************/
TEEC_Result Crypto_Certificate_Verification(struct TEE_resource_ctx *ctx, const ts_pointerType *p_certificate_SP, const ts_pointerType *p_ca_cert_SP);

TEEC_Result Crypto_GetasymKeyFromBlob(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size);

/****************************************************************************
** This interface is used to perform AES 128 CMAC Generation
**
** \param [in] ctx
** Structure containing TEE context and session information
**
** \param [in] keyid
** Pointer to the key identifier used for key retrieval
**
** \param [in] keyid_size
** Size of the key identifier
**
** \param [in] InputData
** Pointer structure containing the data to be authenticated (MACed)
**
** \param [out] Mac
** Pointer structure where the generated CMAC Tag will be stored
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if AES 128 CMAC generation is performed successfully
** - TEEC_ERROR_SHORT_BUFFER if the output buffer is too small
** - TEEC_ERROR_ITEM_NOT_FOUND if the key is not found
** - Other TEEC error codes in case of failure
****************************************************************************/
TEEC_Result Crypto_CMAC_Generate(struct TEE_resource_ctx *ctx,
                                 const char *key_id,
                                 uint32_t keyid_size,
                                 const ts_pointerType *InputData,
                                 ts_pointerType *Mac);

/****************************************************************************
** This interface is used to perform AES 128 CMAC Verification
**
** \param [in] ctx
** Structure containing TEE context and session information
**
** \param [in] keyid
** Pointer to the key identifier used for key retrieval
**
** \param [in] keyid_size
** Size of the key identifier
**
** \param [in] InputData
** Pointer structure containing the data to be verified
**
** \param [in] Mac
** Pointer structure containing the expected MAC (Tag) to verify against
**
** \return TEEC_Result<br>
** This function returns:
** - TEEC_SUCCESS if the calculated MAC matches the expected MAC
** - TEEC_ERROR_MAC_INVALID if the MAC verification fails
** - TEEC_ERROR_ITEM_NOT_FOUND if the key is not found
** - Other TEEC error codes in case of failure
****************************************************************************/
TEEC_Result Crypto_CMAC_Verify(struct TEE_resource_ctx *ctx,
                               const char *key_id,
                               uint32_t keyid_size,
                               const ts_pointerType *InputData,
                               const ts_pointerType *Mac);


/*******************************************************************************************
** These interfaces are used to perform AES 128 CMAC Generation in start update finish model
********************************************************************************************/
TEEC_Result Crypto_CMAC_Gen_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size);
TEEC_Result Crypto_CMAC_Gen_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *InputChunk);
TEEC_Result Crypto_CMAC_Gen_Finish(struct TEE_resource_ctx *ctx, ts_pointerType *MacOut);

/*******************************************************************************************
** These interfaces are used to perform AES 128 CMAC Verification in start update finish model
********************************************************************************************/
TEEC_Result Crypto_CMAC_Ver_Start(struct TEE_resource_ctx *ctx, const char* key_id, uint32_t keyid_size);
TEEC_Result Crypto_CMAC_Ver_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *InputChunk);
TEEC_Result Crypto_CMAC_Ver_Finish(struct TEE_resource_ctx *ctx, const ts_pointerType *ExpectedMac);
/****************************************************************************
** This interface shall used to start compute SHA512 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA512
**
*****************************************************************************/
TEEC_Result Crypto_SHA512_Start(struct TEE_resource_ctx *ctx);

/****************************************************************************
** This interface shall used to update digest SHA512 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [in] Plaintext
** pointer to carry the Plaintext
**
** \param [in] PlaintextLen
**  Length of Plaintext
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA512
**
*****************************************************************************/
TEEC_Result Crypto_SHA512_Update(struct TEE_resource_ctx *ctx, const ts_pointerType *Plaintext);

/****************************************************************************
** This interface shall used to finalize and generate the computed SHA512 hash for data
**
** \param [in] ctx
** structure where TEE context and session open
**
** \param [out] Digest
** pointer to store computed hash
**
** \param [out] DigestSize
**  Length of Digest
**
** \return TEEC_Result<br>
** This function returns:
** - TEE_SUCCESS if hash calculated for data passed SHA512
**
*****************************************************************************/
TEEC_Result Crypto_SHA512_Final(struct TEE_resource_ctx *ctx, ts_pointerType *Digest);
