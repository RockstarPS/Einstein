#ifndef __SECURE_CRYPTO_H__
#define __SECURE_CRYPTO_H__

/* UUID of the trusted application */
#define TA_CRYPTO_UUID_TI \
		{ 0xd8835987u, 0xe194u, 0x428cu, \
			{ 0x99u, 0xfau, 0x09u, 0x96u, 0x10u, 0xf5u, 0xdcu, 0xa3u } }

#define AES_BLOCK_SIZE 16U //AES block size 128-bit
#define AES_128KEY_SIZE 16U //AES 128 -bit key
#define AES_GCM_TAG_LENGTH_BITS 128U
#define AES128_KEY_BITLEN             (128U)
#define AES_GCM_TAG_SIZE_BYTES        (16U)
#define AES_GCM_TAG_SIZE_BITS         (AES_GCM_TAG_SIZE_BYTES * 8U)
#define TEE_MALLOC_FLAG               (0U)
#define MAX_ECB_INPUT_SIZE (1024U)

#define ASYM_2K_KEY_SIZE 256U //RSA block size 2048

#define SIZE_OF_1K_BYTES         1024U
#define SIZE_OF_2k_MODULUS_BYTES 256U
#define SIZE_OF_2k_MODULUS_BITS 2048U
#define SIZE_OF_3k_MODULUS_BYTES 384U
#define SIZE_OF_3k_MODULUS_BITS 3072U
#define SIZE_OF_4K_BYTES        4096U
#define SIZE_OF_EXPONENT 3U
#define SIZE_OF_DER_KEY 270U
#define MAX_CERT_SIZE 8192U

#define RSA_2K 2U
#ifndef RSA_3K
#define RSA_3K 3
#endif

#define SIZE_OF_ECDSA_X 48U //ECDSA Public key size in bytes
#define SIZE_OF_ECDSA_PRIV 48U //ECDSA private key size in bytes
#define SIZE_OF_ECDSA_Y 48U //ECDSA Public key size in bytes 
#define SIZE_OF_ECDSA_BITS 384U //ECDSA Public key size in bits 
#define CHUNK_SIZE 4096U //RSA 4K BITS 
#define DIGEST_LENGTH 32U //SHA 256 DIGEST LENGHT
#define CERTIFICATE_VERIFICATION 512U //CERTIFICATE_VERIFICATION buffer size 


/*
 * TA_CRYPTO_CMD_AES_SETUSERKEY     - 	   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_AES_SETUSERKEY			0U

/*
 * TA_CRYPTO_CMD_AES_ENCRYPT - Encrypt the plaintext using AES key algo
 * param[0] (plaintext)   	   Plaintext to be encrypted
 * param[1] (Iv) 	   		   Initial vector to encrypt
 * param[2] (ciphertext)       Buffer to store cipher text
 */
#define TA_CRYPTO_CMD_AES_ENCRYPT			1U

/*
 * TA_CRYPTO_CMD_AES_DECRYPT - Decrypt the ciphertext using AES key algo
 * param[0] (ciphertext)   	   Ciphertext to be decrypted
 * param[1] (IV) 	   		   Initial vector to encrypt
 * param[2] (plaintext)        Buffer to store decrypted text
 */
#define TA_CRYPTO_CMD_AES_DECRYPT			2U

/*
 * TA_CRYPTO_CMD_AES_SHA256_HASH     - 	   Compute hash for request data 32 bytes since SHA256
 * param[0] (data) 		       		       Data to compute hash and its length
 * param[1] (output_hash) 		   		   Buffer to carry computed hash/digest (32bytes)
 */
#define TA_CRYPTO_CMD_AES_SHA256_HASH		3U

/*
 * TA_CRYPTO_CMD_AES_SETKEY_FROM_BLOB  -   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_AES_SETKEY_FROM_BLOB		4U

/*
 * TA_SECURE_STORAGE_CMD_WRITE_RAW - Create and fill a secure storage file
 * param[0] (memref) stores the symmetric key to be writen in the persistent object
 * param[1] unused
 * param[2] unused
 * param[3] unused
 */
#define TA_SECURE_STORAGE_CMD_WRITE_RAW			5U
/*
 * TA_SECURE_STORAGE_CMD_SECUREBLOB_CHECK - Check for a secure storage blob existance
 * param[0] unused
 * param[1] unused
 * param[2] unused
 * param[3] unused
 */
#define TA_SECURE_STORAGE_CMD_SECUREBLOB_CHECK	6U

/*
 * TA_CRYPTO_CMD_AES_DECRYPT - Decrypt the ciphertext using AES key algo
 * param[0] (ciphertext)   	   ciphertext to be decrypted
 * param[1] (IV) 	   		   initial vector
 * param[2] (plain text) 	   Buffer to carry cipher data
 * param[3] unused
 */
#define TA_CRYPTO_CMD_AES_DECRYPTNOPAD 			7U

/*
 * TA_CRYPTO_CMD_AES_ENCRYPTNOPAD - Encrypt the plaintext using AES key algo without padding
 * param[0] (plaintext)   	   		Plaintext to be encrypted
 * param[1] (IV) 	   		   		initial vector
 * param[2] (ciphertext)   	   		ciphertext to be stored
 * param[3] unused
 */
#define TA_CRYPTO_CMD_AES_ENCRYPTNOPAD			8U

/*
 * TA_CRYPTO_CMD_RSA_SETUSERKEY     - 	   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_RSA_SETUSERPUBKEY			9U

/*
 * TA_CRYPTO_CMD_RSASSA_PKCS1_V1_5_SHA256_VERIFY     - 	   Signature Verfication using rsassa_pkcs_1_5 sha256 algo
 * param[0] 		  		       		   message 
 * param[1] 					 		   signature
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_RSASSA_PKCS1_V1_5_SHA256_VERIFY			10U

/*
 * TA_CRYPTO_CMD_RSA_SETUSERKEY_3K     - 	   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */

#define TA_CRYPTO_CMD_RSA_SETUSERPUBKEY_3K      11U

/*
 * TA_CRYPTO_CMD_AES_SHA256_START    - 	   start hash compute for request data 32 bytes since SHA256
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */

#define TA_CRYPTO_CMD_AES_SHA256_START          12U

/*
 * TA_CRYPTO_CMD_AES_SHA256_HASH     - 	   Update Computed hash for request data 32 bytes since SHA256
 * param[0] (data) 		       		       Data to compute hash and its length
 */

#define TA_CRYPTO_CMD_AES_SHA256_UPDATE         13U

/*
 * TA_CRYPTO_CMD_AES_SHA256_FINISH     - 	   Finalize and generate hash for request data 32 bytes since SHA256
 * param[0] (output_hash) 		   		       Buffer to carry computed hash/digest (32bytes)
 */

#define TA_CRYPTO_CMD_AES_SHA256_FINISH         14U

/*
 * AES-128 CBC Decryption with PKCS7 Padding (multi-call interface)
 */

/*
 * TA_CRYPTO_CMD_AES_CBC_DEC_START - Initialize AES CBC decryption
 * param[0] (key_id)        - Temporary input: Key identifier
 * param[1] (IV)            - Temporary input: 16-byte Initialization Vector
 */
#define TA_CRYPTO_CMD_AES_CBC_DECRYPT_START   15U

/*
 * TA_CRYPTO_CMD_AES_CBC_DEC_UPDATE - Update AES CBC decryption with chunk
 * param[0] (encrypted_chunk) - Temporary input: Encrypted data chunk
 * param[1] (output_plaintext) - Temporary output: Decrypted data chunk
 */
#define TA_CRYPTO_CMD_AES_CBC_DECRYPT_UPDATE   16U

/*
 * TA_CRYPTO_CMD_AES_CBC_DEC_FINISH - Finalize AES CBC decryption, handle padding
 * param[0] (last_encrypted_data) - Temporary input: Remaining data
 * param[1] (output_plaintext)    - Temporary output: Final decrypted and unpadded data
 */
#define TA_CRYPTO_CMD_AES_CBC_DECRYPT_FINISH   17U

/*
 *
 * TA_CRYPTO_CMD_SYM_KEY_CHECK   - To check whether key is setted from the blob.
 *  
 */

#define TA_CRYPTO_CMD_SYM_KEY_CHECK            18U

/****************************************************************************
** TA_CRYPTO_CMD_AES_GCM_ENCRYPT
**
** Command ID used to perform AES 128 GCM encryption using a symmetric key.
**
** Parameters:
** - param[0] (IN): Plaintext buffer to be encrypted
** - param[1] (IN): Initialization Vector (IV) or Additional Authenticated Data (AAD)
**                 Depending on implementation, this may be only IV or a combination.
** - param[2] (OUT): Buffer to store the resulting ciphertext
** - param[3] (OUT): Buffer to store the GCM authentication tag
**
** This command is invoked by the Client Application to request AES 128
** GCM encryption from the Trusted Application (TA).
**
*****************************************************************************/
#define TA_CRYPTO_CMD_AES_GCM_ENCRYPT      19U

/*
 * TA_CRYPTO_CMD_AES_GCM_DECRYPT_START - Start the AES 128 GCM decryption process
 * param[0] (memref) - Initialization Vector (IV) used during decryption
 */
#define TA_CRYPTO_CMD_AES_GCM_DECRYPT 20U

/*
 * TA_CRYPTO_CMD_AES_GCM_DECRYPT_START - Start the AES 128 GCM decryption process
 * param[0] (memref) - Initialization Vector (IV) used during decryption
 */
#define TA_CRYPTO_CMD_AES_GCM_DECRYPT_START 21U

/*
 * TA_CRYPTO_CMD_AES_GCM_DECRYPT_UPDATE - Update the AES 128 GCM decryption process with additional data
 * param[0] (memref) - Ciphertext to be decrypted
 * param[1] (memref) - Additional Authenticated Data (AAD)
 * param[2] (memref) - Buffer to store the decrypted output (Plaintext)
 */
#define TA_CRYPTO_CMD_AES_GCM_DECRYPT_UPDATE 22U

/*
 * TA_CRYPTO_CMD_AES_GCM_DECRYPT_FINAL - Finalize the AES 128 GCM decryption process
 * param[0] (memref) - GCM authentication tag for integrity verification
 */
#define TA_CRYPTO_CMD_AES_GCM_DECRYPT_FINAL 23U

/*
 *
 * TA_CRYPTO_CMD_SYM_KEY_CHECK_ECB   - To check whether key is setted from the blob.
 *  
 */

#define TA_CRYPTO_CMD_SYM_KEY_CHECK_ECB          24U

/*
 * TA_CRYPTO_CMD_AES_ECB_ENCRYPT - Encrypt plaintext using AES ECB algorithm with PKCS#7 padding
 * param[0] (plaintext)         Plaintext to be encrypted
 * param[1] (none)              Not used
 * param[2] (ciphertext)        Buffer to store ciphertext output
 */
#define TA_CRYPTO_CMD_AES_ECB_ENCRYPT		25U

/*
 * TA_CRYPTO_CMD_AES_ECB_DECRYPT - Decrypt ciphertext using AES ECB algorithm with PKCS#7 padding
 * param[0] (ciphertext)        Ciphertext to be decrypted
 * param[1] (none)              Not used
 * param[2] (plaintext)         Buffer to store plaintext output
 */
#define TA_CRYPTO_CMD_AES_ECB_DECRYPT		26U

/*
 * TA_CRYPTO_CMD_AES_ECB_DECRYPT_START - Initialize AES ECB decryption
 * param[0] (key_id)        - Temporary input: Key identifier
 */
#define TA_CRYPTO_CMD_AES_ECB_DECRYPT_START   28U

/*
 * TA_CRYPTO_CMD_AES_ECB_DECRYPT_UPDATE - Update AES ECB decryption with chunk
 * param[0] (encrypted_chunk)     - Temporary input: Encrypted data chunk
 * param[1] (output_plaintext)    - Temporary output: Decrypted data chunk
 */
#define TA_CRYPTO_CMD_AES_ECB_DECRYPT_UPDATE   29U

/*
 * TA_CRYPTO_CMD_AES_ECB_DECRYPT_FINISH - Finalize AES ECB decryption, handle padding
 * param[0] (last_encrypted_data) - Temporary input: Remaining data
 * param[1] (output_plaintext)    - Temporary output: Final decrypted and unpadded data
 */
#define TA_CRYPTO_CMD_AES_ECB_DECRYPT_FINISH   30U


/*
 * TA_CRYPTO_CMD_ECDSA_SETUSERKEY     - 	   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_ECDSA_SETUSERPUBKEY			31U

/*
 * TA_CRYPTO_CMD_ecdsa_p384_VERIFY     - 	   Signature Verfication using ecdsa_p384 algo
 * param[0] 		  		       		   message 
 * param[1] 					 		   signature
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_ecdsa_p384_VERIFY			32U

/*
 * TA_SECURE_STORAGE_CMD_WRITE_PEM_KEY  -     Store a PEM-formatted key securely in OP-TEE storage
 * param[0]                             -     key identifier 
 * param[1]                             -     PEM key data buffer
 * param[2]                             -     unused
 * param[3]                             -     unused
 */
#define TA_SECURE_STORAGE_CMD_WRITE_PEM_KEY     33U

/*
 * TA_SECURE_STORAGE_CMD_READ_PEM_KEY   -     Retrieve a PEM-formatted key from OP-TEE secure storage
 * param[0]                             -     key identifier 
 * param[1]                             -     output buffer to receive PEM key data
 * param[2]                             -     unused
 * param[3]                             -     unused
 */
#define TA_SECURE_STORAGE_CMD_READ_PEM_KEY      34U

/*
 * TA_CRYPTO_CMD_ecdsa_p384_SIGN	     - 	   Signature generation using ecdsa_p384 algo
 * param[0] 		  		       		   message 
 * param[1] 					 		   signature
 * param[2]			   		               unused
 */
#define TA_CRYPTO_CMD_ecdsa_p384_SIGN 35U

/*
 * TA_CRYPTO_CMD_ECDSA_SETUSERPRIVKEY     - 	   Set key from persist blob
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */

#define TA_CRYPTO_CMD_ECDSA_SETUSERPRIVKEY 36U

/*
 * TA_CRYPTO_CMD_AES_SHA384_START    	   - 	   start hash compute for request data 48 bytes since SHA384
 * param[0] 		  		       		   unused
 * param[1] 					 		   unused
 * param[2]			   		               unused
 */

#define TA_CRYPTO_CMD_AES_SHA384_START          37U

/*
 * TA_CRYPTO_CMD_AES_SHA384_UPDATE     		- 	   Update Computed hash for request data 48 bytes since SHA384
 * param[0] (data) 		       		       Data to compute hash and its length
 */

#define TA_CRYPTO_CMD_AES_SHA384_UPDATE         38U

/*	
 * TA_CRYPTO_CMD_AES_SHA384_FINISH      	- 	   Finalize and generate hash for request data 48 bytes since SHA384
 * param[0] (output_hash) 		   		       Buffer to carry computed hash/digest (48bytes)
 */

#define TA_CRYPTO_CMD_AES_SHA384_FINISH         39U

/*
 * TA_CRYPTO_CMD_ECDSA_GENERATE		     	- 	   Generate ecdsa  key pair
 * param[0] (Private key)				  	- 	   Buffer to carry ecdsa private key 
 * param[1] 					 		    -	   Buffer to carry ecdsa Public key - X 
 * param[2]			   		                -	   Buffer to carry ecdsa Public key - Y
 */

#define TA_CRYPTO_CMD_ECDSA_GENERATE 			40U

/*
 * TA_CRYPTO_CMD_ECDSA_GENERATE		     	- 	   Certificate verification
 * param[0] (Private key)				  	- 	   Buffer to carry chain certificate
 * param[1] 					 		    -	   Buffer to carry ca certificate
 */

#define TA_CRYPTO_CMD_CERT_VERIFY				41U

#define TA_CRYPTO_CMD_ASM_SETKEY_FROM_BLOB      42U

/*
 * TA_CRYPTO_CMD_CMAC_GENERATE - Generate AES-CMAC
 * param[0] (memref) - Input Data
 * param[1] (memref) - Output MAC (Tag)
 */
#define TA_CRYPTO_CMD_CMAC_GENERATE      43U

/*
 * TA_CRYPTO_CMD_CMAC_VERIFY - Verify AES-CMAC
 * param[0] (memref) - Input Data
 * param[1] (memref) - Input MAC (Tag to verify)
 */
#define TA_CRYPTO_CMD_CMAC_VERIFY        44U

/* CMAC GENERATION IDs */
#define TA_CRYPTO_CMD_CMAC_GEN_START    45U
#define TA_CRYPTO_CMD_CMAC_GEN_UPDATE   46U
#define TA_CRYPTO_CMD_CMAC_GEN_FINISH   47U

/* CMAC VERIFICATION IDs */
#define TA_CRYPTO_CMD_CMAC_VER_START    48U
#define TA_CRYPTO_CMD_CMAC_VER_UPDATE   49U
#define TA_CRYPTO_CMD_CMAC_VER_FINISH   50U

#define TA_CRYPTO_CMD_AES_SHA512_START          51U
#define TA_CRYPTO_CMD_AES_SHA512_UPDATE         52U
#define TA_CRYPTO_CMD_AES_SHA512_FINISH         53U

#endif /* __SECURE_CRYPTO__H__ */
