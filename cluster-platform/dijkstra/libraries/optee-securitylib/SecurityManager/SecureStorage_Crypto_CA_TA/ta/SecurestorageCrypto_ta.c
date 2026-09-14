/*
 * Copyright (c) 2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <inttypes.h>
#include <SecurestorageCrypto_ta.h>
#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>
#include <mbedtls/x509_crt.h>
#include <time.h> 
#include <mbedtls/platform_time.h> 
#include <string.h>

struct cryptoKey {
	TEE_ObjectHandle key;
	TEE_OperationHandle SHA256Operation;
	TEE_OperationHandle SHA384Operation;
	TEE_OperationHandle SHA512Operation;
	TEE_OperationHandle AES128CBC_DecryptOp;
	TEE_OperationHandle AES128GCM_DecryptOp; 
	TEE_OperationHandle AES128ECB_DecryptOp;
	TEE_OperationHandle cmac_operation;
	bool AES128CBC_DecryptOpStatus;
	bool AES128GCM_DecryptOpStatus;
	bool AES128ECB_DecryptOpStatus;
};

static TEE_Result optee_crypto_AES128CBC_symkey_setstatus_TA(const struct cryptoKey *state) {

    TEE_Result res = TEE_SUCCESS;
	
	if (state->key == TEE_HANDLE_NULL) {
		res = TEE_ERROR_BAD_STATE;
	}
	else {
		res = TEE_SUCCESS;
	}

	return res;
}

static TEE_Result optee_cryptoset_symkey_in_teeObject_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
    TEE_Result res;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    void *userkey = NULL;
    uint32_t key_size;
    TEE_Attribute attr = { };

    if (param_types != exp_param_types)
	{
		res =  TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		
		// Retrieve key data from the parameters
		key_size = (uint32_t)params[0].memref.size;
		TEE_MemMove(userkey, params[0].memref.buffer, (size_t)key_size);

		// Ensure the key size is correct (e.g., for AES 128-bit key, 16 bytes)
		if (key_size != AES_BLOCK_SIZE) {
			res = TEE_ERROR_BAD_PARAMETERS;
			EMSG("Invalid key size : %#" PRIx32, res);
		}
		else
		{
			// Allocate a transient object to store the key (AES type)
			res = TEE_AllocateTransientObject(TEE_TYPE_AES, (key_size * 8U), &key);
			if (res != TEE_SUCCESS)
			{
				EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
			}
			else
			{
				TEE_InitRefAttribute(&attr, TEE_ATTR_SECRET_VALUE, userkey, (size_t)key_size);
				// Set the key data in the object
				res = TEE_PopulateTransientObject(key, &attr, 1U);
				if (res != TEE_SUCCESS) {
					EMSG("TEE_PopulateTransientObject: %#" PRIx32, res);
					TEE_FreeTransientObject(key);
				}
			}
		}
		TEE_FreeTransientObject(state->key);
		state->key = key;
	}
    
    return res;
}

static TEE_Result optee_cryptoset_asympubkey_in_teeObject_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    void *userkey_Mod = NULL;
    size_t key_size_Mod = 0U;
	void *userkey_Exp = NULL;
    size_t key_size_Exp = 0U;
    TEE_Attribute attr[2] = { };
	
    if (param_types != exp_param_types) 
	{
		res =  TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else 
	{
		key_size_Mod = params[0].memref.size;
		userkey_Mod	   = TEE_Malloc(key_size_Mod, 0U);
		key_size_Exp = params[1].memref.size;
		userkey_Exp	   = TEE_Malloc(key_size_Exp, 0U);
		if ((!userkey_Mod) || (!userkey_Exp))
		{
			res =	 TEE_ERROR_OUT_OF_MEMORY;
		}
		else
		{
			TEE_MemMove(userkey_Mod, params[0].memref.buffer, key_size_Mod);
			TEE_MemMove(userkey_Exp, params[1].memref.buffer, key_size_Exp);
			// Retrieve key data from the parameters
			// Ensure the key size is correct
			if ((key_size_Mod != SIZE_OF_2k_MODULUS_BYTES) || (key_size_Exp != SIZE_OF_EXPONENT)) 
			{
				EMSG("Invalid key size: expected %u modulus bytes %u exponent bytes , got %zu modulus bytes %zu exponent bytes ", SIZE_OF_2k_MODULUS_BYTES, SIZE_OF_EXPONENT, key_size_Mod, key_size_Exp);
				res = TEE_ERROR_BAD_PARAMETERS;
			}
			else
			{
				// Allocate a transient object to store the key
				res = TEE_AllocateTransientObject(TEE_TYPE_RSA_PUBLIC_KEY, (SIZE_OF_2k_MODULUS_BYTES*8U), &key);
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
				}
				
				TEE_InitRefAttribute(&attr[0], TEE_ATTR_RSA_MODULUS, (const void *)userkey_Mod, key_size_Mod);
				TEE_InitRefAttribute(&attr[1], TEE_ATTR_RSA_PUBLIC_EXPONENT, (const void *)userkey_Exp, key_size_Exp);
				// Populate the transient object with the key attribute
				res = TEE_PopulateTransientObject(key, attr, 2U);
				if (res != TEE_SUCCESS) 
				{
					EMSG("TEE_PopulateTransientObject failed: %#" PRIx32, res);
					TEE_FreeTransientObject(key);
					TEE_Free(userkey_Mod);
					TEE_Free(userkey_Exp);
				}
			}
		}
		if (state->key != TEE_HANDLE_NULL) 
		{
        TEE_FreeTransientObject(state->key);
    	}
		state->key = key;
	}
	  
    IMSG("RSA Public key successfully set in the transient object.");
    return res;
}

static TEE_Result optee_cryptoset_asympubkey_3k_in_teeObject_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    void *userkey_Mod = NULL;
    size_t key_size_Mod = 0U;
	void *userkey_Exp = NULL;
    size_t key_size_Exp = 0U;
    TEE_Attribute attr[2] = { };
	
    if (param_types != exp_param_types)
	{
		res =  TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		key_size_Mod = params[0].memref.size;
		userkey_Mod	   = TEE_Malloc(key_size_Mod, 0U);
		key_size_Exp = params[1].memref.size;
		userkey_Exp	   = TEE_Malloc(key_size_Exp, 0U);
		if ((!userkey_Mod) || (!userkey_Exp)) 
		{
			res = TEE_ERROR_OUT_OF_MEMORY;
		}
		else
		{
			TEE_MemMove(userkey_Mod, params[0].memref.buffer, key_size_Mod);
			TEE_MemMove(userkey_Exp, params[1].memref.buffer, key_size_Exp);
			// Retrieve key data from the parameters
			// Ensure the key size is correct
			if ((key_size_Mod != SIZE_OF_3k_MODULUS_BYTES) || (key_size_Exp != SIZE_OF_EXPONENT))
			{
				EMSG("Invalid key size: expected %u modulus bytes %u exponent bytes , got %zu modulus bytes %zu exponent bytes ", SIZE_OF_3k_MODULUS_BYTES, SIZE_OF_EXPONENT, key_size_Mod, key_size_Exp);
				res = TEE_ERROR_BAD_PARAMETERS;
			}
			else
			{
				// Allocate a transient object to store the key
				res = TEE_AllocateTransientObject(TEE_TYPE_RSA_PUBLIC_KEY, (SIZE_OF_3k_MODULUS_BYTES*8U), &key);
				if (res != TEE_SUCCESS)
				{
					EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
				}
				else
				{
					TEE_InitRefAttribute(&attr[0], TEE_ATTR_RSA_MODULUS, userkey_Mod, key_size_Mod);
					TEE_InitRefAttribute(&attr[1], TEE_ATTR_RSA_PUBLIC_EXPONENT, userkey_Exp, key_size_Exp);
					// Populate the transient object with the key attribute
					res = TEE_PopulateTransientObject(key, attr, 2U);
					if (res != TEE_SUCCESS)
					{
						EMSG("TEE_PopulateTransientObject failed: %#" PRIx32, res);
						TEE_FreeTransientObject(key);
						TEE_Free(userkey_Mod);
						TEE_Free(userkey_Exp);
					}
				}
			}
		}
		if (state->key != TEE_HANDLE_NULL) {
        TEE_FreeTransientObject(state->key);
    	}
		state->key = key;
	}
	  
    IMSG("RSA Public key successfully set in the transient object.");
    return res;
}

static TEE_Result CheckSecureBlobExistance_TA(uint32_t param_types, TEE_Param params[4]) {

	//Validate paramater types
	TEE_Result res;
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, 
                        TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
	if (param_types != exp_param_types)
	{
		res = TEE_ERROR_BAD_PARAMETERS;
	}
	//declare required local variables
	else
	{
		TEE_ObjectHandle object; 
		void *keyid;
		uint32_t keyid_size;

		keyid_size = (uint32_t)params[0].memref.size;
		keyid	   = TEE_Malloc((size_t)keyid_size, 0U);
		if (!keyid) 
		{
			res = TEE_ERROR_OUT_OF_MEMORY;
		}
		else
		{
			TEE_MemMove(keyid, params[0].memref.buffer, params[0].memref.size);
			/*
			* Check the object exist.
			*/
			res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE,
							(const void *)keyid, (size_t)keyid_size,
							TEE_DATA_FLAG_ACCESS_READ |
							TEE_DATA_FLAG_SHARE_READ,
							&object);
			if (res == TEE_SUCCESS) {
				TEE_CloseObject(object);
			}
			else
			{
				//
			}
		}

	}
	return res;
}

static TEE_Result optee_cryptoset_symkey_fromblob_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	//Validate paramater types
	TEE_Result res;
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, 
                        TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
	if (param_types != exp_param_types)
	{
		res = TEE_ERROR_BAD_PARAMETERS;
	}
	//declare required local variables
	else
	{
		void *keyid;
		uint32_t keyid_size;
		TEE_ObjectHandle object;
		TEE_ObjectInfo object_info;
		size_t read_bytes;
		void *persist_key;
		TEE_ObjectHandle key = TEE_HANDLE_NULL;
		TEE_Attribute attr = { };

		/*
		 * Safely get the invocation parameters
		 */
		if (param_types != exp_param_types)
		{
			res = TEE_ERROR_BAD_PARAMETERS;
		}
		else{
			//Get the keyid size and allocate memory
			keyid_size = (uint32_t)params[0].memref.size;
			keyid	   = TEE_Malloc((size_t)keyid_size, 0U);
			if (!keyid) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("Unable to allocate memory, res=0x%08x", res);
			}
			else {
				TEE_MemMove(keyid, params[0].memref.buffer, params[0].memref.size);
				/*
				* Check the object exist and can be dumped into output buffer
				* then dump it.
				*/
				res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE,
								(const void *)keyid, (size_t)keyid_size,
								TEE_DATA_FLAG_ACCESS_READ |
								TEE_DATA_FLAG_SHARE_READ,
								&object);
				if (res != TEE_SUCCESS) {
					EMSG("Failed to open persistent object, res=0x%08x", res);
				}
				else {
					res = TEE_GetObjectInfo1(object, &object_info);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_GetObjectInfo1 failed, res=0x%08x", res);
					}
					else {
						persist_key = TEE_Malloc(object_info.dataSize, 0U);
						if (!persist_key) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc: %#" PRIx32, res);
						}
						else {
							res = TEE_ReadObjectData(object, persist_key, object_info.dataSize, &read_bytes);
							if (res != TEE_SUCCESS) {
								EMSG("TEE_ReadObjectData failed, res=0x%08x", res);
							}
							else {
								if ((res != TEE_SUCCESS) || (read_bytes != object_info.dataSize)) {
									EMSG("TEE_ReadObjectData failed 0x%08x, read %lu" PRIu32 " over %lu",
										res, read_bytes, object_info.dataSize);
								}
								else {
									// Allocate a transient object to store the key (AES type)
									res = TEE_AllocateTransientObject(TEE_TYPE_AES, (read_bytes * 8U), &key);
									if (res != TEE_SUCCESS) {
										EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
									}
									else {
										TEE_InitRefAttribute(&attr, TEE_ATTR_SECRET_VALUE, persist_key, (size_t)read_bytes);
										// Set the key data in the object
										res = TEE_PopulateTransientObject(key, &attr, 1U);
										if (res != TEE_SUCCESS) {
											EMSG("TEE_PopulateTransientObject: %#" PRIx32, res);
											TEE_FreeTransientObject(key);
										}
										else {
											TEE_FreeTransientObject(state->key);
											state->key = key;
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}
	return res;
}

// AES CBC Encryption with pkcs11 padding
static TEE_Result optee_cryptoAesCBC_encrypt_with_pkcs11pad_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT, 
                        TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation;
    TEE_Result res;
    void *Plaintext, *CipherDataOut, *iv;
	uint8_t *PaddedData;
    uint32_t  PlaintextLen = 0U, iv_len = 0U;
	size_t CipherDataBufSize = 0U;
    uint32_t PaddingLen = 0U, PaddedLen = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		if (!state->key) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {
			PlaintextLen = (uint32_t)params[0].memref.size;
			Plaintext = TEE_Malloc((size_t)PlaintextLen, 0U);
			if (!Plaintext) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
			}
			else {
				TEE_MemMove(Plaintext, params[0].memref.buffer, (size_t)PlaintextLen);
    			// Calculate required padding (PKCS#7)
    			PaddingLen = AES_BLOCK_SIZE - (PlaintextLen % AES_BLOCK_SIZE);
				if (PlaintextLen > (UINT32_MAX - PaddingLen))
				{
				   res = TEE_ERROR_EXCESS_DATA;
				}
				else
				{
    				PaddedLen = PlaintextLen + PaddingLen;
					PaddedData = (uint8_t *)TEE_Malloc((size_t)PaddedLen, 0U);
    				if (!PaddedData) {
        				res = TEE_ERROR_OUT_OF_MEMORY;
						EMSG("TEE_Malloc Failed %#" PRIx32, res);
					}
					else {
						// Copy original data to padded buffer and apply PKCS#7 padding
    					TEE_MemMove(PaddedData, Plaintext, (size_t)PlaintextLen);
    					TEE_MemFill((&PaddedData[PlaintextLen]), PaddingLen, (size_t)PaddingLen);

    					// Allocate operation handle for AES CBC mode
    					res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CBC_NOPAD, TEE_MODE_ENCRYPT, (AES_BLOCK_SIZE * 8U));
    					if (res != TEE_SUCCESS) {
        					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
    					}
						else {
							// Initialize/setting operation with the key for encryption
    						res = TEE_SetOperationKey(operation, state->key);
    						if (res != TEE_SUCCESS) {
        						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
        						TEE_FreeOperation(operation);
    						}
							else {
								iv_len = (uint32_t)params[1].memref.size;
								iv = TEE_Malloc((size_t)iv_len, 0U);
								if (!iv) {
									res = TEE_ERROR_OUT_OF_MEMORY;
									EMSG("TEE_Malloc Failed %#" PRIx32, res);
									TEE_FreeOperation(operation);
									TEE_Free(PaddedData);
									TEE_Free(Plaintext);
								}
								else {
									TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len); 
									TEE_CipherInit(operation, iv, AES_BLOCK_SIZE);

									CipherDataBufSize = params[2].memref.size;
									CipherDataOut = TEE_Malloc((size_t)CipherDataBufSize, 0U);
									if (!CipherDataOut) {
										res = TEE_ERROR_OUT_OF_MEMORY;
										EMSG("TEE_Malloc Failed %#" PRIx32, res);
										TEE_FreeOperation(operation);
										TEE_Free(PaddedData);
										TEE_Free(Plaintext);
									}
									else {
										res = TEE_CipherUpdate(operation, (const void *)PaddedData, (size_t)PaddedLen, CipherDataOut, &CipherDataBufSize);
										if (res != TEE_SUCCESS) {
											EMSG("TEE_CipherUpdate: %#" PRIx32, res);
										}
										else {
											TEE_MemMove(params[2].memref.buffer, CipherDataOut, (size_t)CipherDataBufSize);
											params[2].memref.size = CipherDataBufSize;
										}
										TEE_Free(Plaintext);
										TEE_Free(CipherDataOut);
										TEE_Free(iv);
										TEE_Free(PaddedData);
										TEE_FreeOperation(operation);
									}
								}
							}
						}
					}
				}
			}
		}
	}
    
    return res;
}

// AES CBC decryption with pkcs11 padding
static TEE_Result optee_cryptoAesCBC_decrypt_with_pkcs11pad_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT, 
                        TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation;
    TEE_Result res;
    uint8_t *PlaintextOut, *CipherData, *iv;
    uint32_t iv_len = 0U, CipherDataLen = 0U, PaddingLen = 0U, padding= 0U;
	size_t PlaintextOutBufSize = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		if (!state->key) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {
			CipherDataLen = (uint32_t)params[0].memref.size;
			CipherData = (uint8_t *)TEE_Malloc((size_t)CipherDataLen, 0U);
			if (!CipherData) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
			}
			else {
				TEE_MemMove(CipherData, params[0].memref.buffer, (size_t)CipherDataLen);
				// Allocate operation handle for AES CBC mode
    			res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CBC_NOPAD, TEE_MODE_DECRYPT, (AES_BLOCK_SIZE * 8U));
    			if (res != TEE_SUCCESS) {
        			EMSG("TEE_AllocateOperation: %#" PRIx32, res);
    			}
				else {
					// Initialize/setting operation with the key for decryption
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
						TEE_FreeOperation(operation);
						TEE_Free(CipherData);
					}
					else {
						iv_len = (uint32_t)params[1].memref.size;
						iv = (uint8_t *)TEE_Malloc((size_t)iv_len, 0U);
						if (!iv) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc Failed %#" PRIx32, res);
							TEE_FreeOperation(operation);
							TEE_Free(CipherData);
						}
						else {
							TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len); 
    						TEE_CipherInit(operation, iv, AES_BLOCK_SIZE);

							PlaintextOutBufSize = params[2].memref.size;
							PlaintextOut = (uint8_t *)TEE_Malloc((size_t)PlaintextOutBufSize, 0U);
							if (!PlaintextOut) {
								res = TEE_ERROR_OUT_OF_MEMORY;
								EMSG("TEE_Malloc Failed %#" PRIx32, res);
								TEE_FreeOperation(operation);
								TEE_Free(CipherData);
								TEE_Free(iv);
							}
							else {
								res = TEE_CipherUpdate(operation, (const void *)CipherData, (size_t)CipherDataLen, PlaintextOut, &PlaintextOutBufSize);
    							if (res != TEE_SUCCESS) {
        							EMSG("TEE_CipherUpdate: %#" PRIx32, res);
        							TEE_FreeOperation(operation);
									TEE_Free(CipherData);
									TEE_Free(iv);
									TEE_Free(PlaintextOut);
    							}
								else {
									if(PlaintextOutBufSize > 0U)
									{
										padding = PlaintextOutBufSize - 1U;
									}
									else
									{
										res = TEE_ERROR_OUT_OF_MEMORY;
										PaddingLen = PlaintextOut[padding];
    									if (PaddingLen > AES_BLOCK_SIZE) {
        									EMSG("Padding Length not matching : %#" PRIx32, res);
        									res = TEE_ERROR_BAD_STATE;
    									}
										else{
										    if( PlaintextOutBufSize < PaddingLen)
										    {
										    	res = TEE_ERROR_OUT_OF_MEMORY;
										    }
										    else
										    {
    									    	PlaintextOutBufSize = PlaintextOutBufSize - PaddingLen;  // Remove padding from the output
										    	TEE_MemMove(params[2].memref.buffer, PlaintextOut, (size_t)PlaintextOutBufSize);
    									    	params[2].memref.size = PlaintextOutBufSize;
											}
											TEE_FreeOperation(operation);
											TEE_Free(CipherData);
											TEE_Free(iv);
											TEE_Free(PlaintextOut);
										}	
									}
								}
							}
						}
					}
				}
			}
		}
	}

    return res;
}

// AES128 GCM encryption TA
static TEE_Result optee_cryptoAesGCM_encrypt_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,  // Plaintext
		                TEE_PARAM_TYPE_MEMREF_INPUT,  // IV
		                TEE_PARAM_TYPE_MEMREF_OUTPUT, // Ciphertext
		                TEE_PARAM_TYPE_MEMREF_OUTPUT);// Auth Tag

	TEE_OperationHandle operation = TEE_HANDLE_NULL;
	TEE_Result res = TEE_SUCCESS;

	void *plaintext = NULL, *iv = NULL, *ciphertext = NULL, *tag = NULL;
	uint32_t plaintext_len = 0U, iv_len = 0U;
	size_t ciphertext_len = 0U, tag_len = 0U;

	if (param_types == exp_param_types)
	{
		if (state->key != TEE_HANDLE_NULL)
		{
			plaintext_len = (uint32_t)params[0].memref.size;
			iv_len        = (uint32_t)params[1].memref.size;
			ciphertext_len = (uint32_t)params[2].memref.size;
			tag_len       = (uint32_t)params[3].memref.size;

			plaintext = TEE_Malloc((size_t)plaintext_len, TEE_MALLOC_FLAG);
			iv        = TEE_Malloc((size_t)iv_len, TEE_MALLOC_FLAG);
			ciphertext = TEE_Malloc((size_t)ciphertext_len, TEE_MALLOC_FLAG);
			tag       = TEE_Malloc((size_t)tag_len, TEE_MALLOC_FLAG);

			if (plaintext && iv && ciphertext && tag)
			{
				TEE_MemMove(plaintext, params[0].memref.buffer, (size_t)plaintext_len);
				TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len);

				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_GCM, TEE_MODE_ENCRYPT, AES128_KEY_BITLEN);
				if (res == TEE_SUCCESS)
				{
					res = TEE_SetOperationKey(operation, state->key);
					if (res == TEE_SUCCESS)
					{
						res = TEE_AEInit(operation, iv, (size_t)iv_len, AES_GCM_TAG_SIZE_BITS, 0U, 0U);
						if (res == TEE_SUCCESS)
						{
							/*
							 * TEE_AEUpdateAAD feeds Additional Authenticated Data (AAD) to the operation.
							 */
							TEE_AEUpdateAAD(operation, NULL, 0U);
							res = TEE_AEEncryptFinal(operation,
							                         plaintext, plaintext_len,
							                         ciphertext, &ciphertext_len,
							                         tag, &tag_len);
							if (res == TEE_SUCCESS)
							{
								TEE_MemMove(params[2].memref.buffer, ciphertext, (size_t)ciphertext_len);
								TEE_MemMove(params[3].memref.buffer, tag, (size_t)tag_len);
								params[2].memref.size = ciphertext_len;
								params[3].memref.size = tag_len;
							}
							else
							{
								EMSG("TEE_AEEncryptFinal failed: %#" PRIx32, res);
							}
						}
						else
						{
							EMSG("TEE_AEInit failed: %#" PRIx32, res);
						}
					}
					else
					{
						EMSG("TEE_SetOperationKey failed: %#" PRIx32, res);
					}
					TEE_FreeOperation(operation);
				}
				else
				{
					EMSG("TEE_AllocateOperation failed: %#" PRIx32, res);
				}
			}
			else
			{
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("Malloc failed for plaintext/iv/ciphertext/tag buffer");
			}

			if (plaintext != NULL){
				TEE_Free(plaintext);
			}
			if (iv != NULL){
				TEE_Free(iv);
			}        
			if (ciphertext != NULL){
				TEE_Free(ciphertext);
			}
			if (tag != NULL){
				TEE_Free(tag);
			}
		}
		else
		{
			res = TEE_ERROR_BAD_STATE;
			EMSG("Key not set, state->key is NULL: %#" PRIx32, res);
		}
	}
	else
	{
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Parameter types mismatch: %#" PRIx32, res);
	}

	return res;
}

// AES128 GCM decryption TA
static TEE_Result optee_cryptoAesGCM_decrypt_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,   // Ciphertext
		                TEE_PARAM_TYPE_MEMREF_INPUT,   // IV
		                TEE_PARAM_TYPE_MEMREF_INPUT,   // Tag
		                TEE_PARAM_TYPE_MEMREF_OUTPUT); // Plaintext

	TEE_OperationHandle operation = TEE_HANDLE_NULL;
	TEE_Result res = TEE_SUCCESS;

	void *ciphertext = NULL, *iv = NULL, *tag = NULL, *plaintext = NULL;
	uint32_t ciphertext_len = 0U, iv_len = 0U, tag_len = 0U;
	size_t plaintext_len = 0U;

	if (param_types == exp_param_types)
	{
		if (state->key != TEE_HANDLE_NULL)
		{
			ciphertext_len = (uint32_t)params[0].memref.size;
			iv_len         = (uint32_t)params[1].memref.size;
			tag_len        = (uint32_t)params[2].memref.size;
			plaintext_len  = (uint32_t)params[3].memref.size;

			ciphertext = TEE_Malloc((size_t)ciphertext_len, TEE_MALLOC_FLAG);
			iv         = TEE_Malloc((size_t)iv_len, TEE_MALLOC_FLAG);
			tag        = TEE_Malloc((size_t)tag_len, TEE_MALLOC_FLAG);
			plaintext  = TEE_Malloc((size_t)plaintext_len, TEE_MALLOC_FLAG);

			if (ciphertext && iv && tag && plaintext)
			{
				TEE_MemMove(ciphertext, params[0].memref.buffer, (size_t)ciphertext_len);
				TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len);
				TEE_MemMove(tag, params[2].memref.buffer, (size_t)tag_len);

				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_GCM, TEE_MODE_DECRYPT, AES128_KEY_BITLEN);
				if (res == TEE_SUCCESS)
				{
					res = TEE_SetOperationKey(operation, state->key);
					if (res == TEE_SUCCESS)
					{
						res = TEE_AEInit(operation, iv, (size_t)iv_len, AES_GCM_TAG_SIZE_BITS, 0U, 0U);
						if (res == TEE_SUCCESS)
						{
							/*
							 * TEE_AEDecryptFinal validates and decrypts GCM ciphertext.
							 */
							res = TEE_AEDecryptFinal(operation,
							                         ciphertext, ciphertext_len,
							                         plaintext, &plaintext_len,
							                         tag, (size_t)tag_len);
							if (res == TEE_SUCCESS)
							{
								TEE_MemMove(params[3].memref.buffer, plaintext, (size_t)plaintext_len);
								params[3].memref.size = plaintext_len;
							}
							else
							{
								EMSG("TEE_AEDecryptFinal Failed (auth tag mismatch?): %#" PRIx32, res);
							}
						}
						else
						{
							EMSG("TEE_AEInit Failed: %#" PRIx32, res);
						}
					}
					else
					{
						EMSG("TEE_SetOperationKey Failed: %#" PRIx32, res);
					}
					TEE_FreeOperation(operation);
				}
				else
				{
					EMSG("TEE_AllocateOperation Failed: %#" PRIx32, res);
				}
			}
			else
			{
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("Malloc failed for one of the GCM buffers");
			}

			if (ciphertext != NULL){
				TEE_Free(ciphertext);
			}
			if (iv != NULL){
				TEE_Free(iv);
			}
			if (tag != NULL){
				TEE_Free(tag);
			}        
			if (plaintext != NULL){
				TEE_Free(plaintext);
			}
		}
		else
		{
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state, no key set: %#" PRIx32, res);
		}
	}
	else
	{
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected parameters not matching: %#" PRIx32, res);
	}

	return res;
}
// SHA-256 Hash Computation
static TEE_Result optee_cryptoSha256_hash_TA(uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, 
                        TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation;
    TEE_Result res;
    void *Data_to_computehash, *Digest;
    uint32_t  DataBufSize = 0U;
	size_t DigestSize = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		DataBufSize = (uint32_t)params[0].memref.size;
    	Data_to_computehash = TEE_Malloc((size_t)DataBufSize, 0U);
		if (!Data_to_computehash) {
			res = TEE_ERROR_OUT_OF_MEMORY;
			EMSG("TEE_Malloc Failed %#" PRIx32, res);
		}
		else {
			TEE_MemMove(Data_to_computehash, params[0].memref.buffer, (size_t)DataBufSize);
			DigestSize = params[1].memref.size;
			Digest = TEE_Malloc((size_t)DigestSize, 0U);
			if (!Digest) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
				TEE_Free(Data_to_computehash);
			}
			else {
				// Allocate operation handle for SHA-256
				res = TEE_AllocateOperation(&operation, TEE_ALG_SHA256, TEE_MODE_DIGEST, 0U);
    			if (res != TEE_SUCCESS) {
        			EMSG("TEE_AllocateOperation: %#" PRIx32, res);
        			TEE_Free(Data_to_computehash);
					TEE_Free(Digest);
    			}
				else {
					TEE_DigestUpdate(operation, Data_to_computehash, (size_t)DataBufSize);
					// Finalize the hash
					res = TEE_DigestDoFinal(operation, NULL, 0U, Digest, &DigestSize);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_DigestDoFinal: %#" PRIx32, res);
					}
					else {
						TEE_MemMove(params[1].memref.buffer, Digest, (size_t)DigestSize);
    					params[1].memref.size = DigestSize;
					}
					TEE_FreeOperation(operation);
					TEE_Free(Data_to_computehash);
					TEE_Free(Digest);
				}
			}
		}
	}
    return res;
}

 //SHA256 hash computation start
 static TEE_Result optee_cryptoSha384_hash_start_TA(struct cryptoKey *state) {
 
	 TEE_Result res;
	 // Allocate operation handle for SHA-256
	 res = TEE_AllocateOperation(&state->SHA384Operation, TEE_ALG_SHA384, TEE_MODE_DIGEST, 0U);
	 if (res != TEE_SUCCESS) {
		 EMSG("TEE_AllocateOperation: %#" PRIx32, res);
	 }
	 else{
		//for misra
	 }
	 return res;
 }
 
 //SHA 256 digest update
 static TEE_Result optee_cryptoSha384_hash_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res = TEE_SUCCESS;
	 void *Data_to_computehash;
	 uint32_t  DataBufSize = 0U;
 
	 if (param_types != exp_param_types)
	 {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else
	 {
		 if (!state->SHA384Operation)
		 {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else
		 {
			 DataBufSize = (uint32_t)params[0].memref.size;
			 Data_to_computehash = TEE_Malloc((size_t)DataBufSize, 0U);
			 if (!Data_to_computehash) {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else {
				 TEE_MemMove(Data_to_computehash, params[0].memref.buffer, (size_t)DataBufSize);
				 TEE_DigestUpdate(state->SHA384Operation, Data_to_computehash, (size_t)DataBufSize);
				 TEE_Free(Data_to_computehash);
			 }
		 }
	 }
 
	 return res;
 }
 
 //SHA 256 digest finish
 static TEE_Result optee_cryptoSha384_hash_finish_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res;
	 void *Digest;
	 size_t DigestSize = 0U;
 
	 if (param_types != exp_param_types)
	 {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else
	 {
		 if (!state->SHA384Operation)
		 {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else
		 {
			 DigestSize = params[0].memref.size;
			 Digest = TEE_Malloc((size_t)DigestSize, 0U);
			 if (!Digest)
			 {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else
			 {
				 res = TEE_DigestDoFinal(state->SHA384Operation, NULL, 0U, Digest, &DigestSize);
				 if (res != TEE_SUCCESS) {
					 EMSG("TEE_DigestDoFinal: %#" PRIx32, res);
				 }
				 else {
					 TEE_MemMove(params[0].memref.buffer, Digest, (size_t)DigestSize);
					 params[0].memref.size = DigestSize;
				 }
				 TEE_FreeOperation(state->SHA384Operation);
				 TEE_Free(Digest);
			 }
		 }
	 }
 
	 return res;
 }
 
 //SHA512 hash computation start
 static TEE_Result optee_cryptoSha512_hash_start_TA(struct cryptoKey *state) {
 
	 TEE_Result res;
	 // Allocate operation handle for SHA-512
	 res = TEE_AllocateOperation(&state->SHA512Operation, TEE_ALG_SHA512, TEE_MODE_DIGEST, 0U);
	 if (res != TEE_SUCCESS) {
		 EMSG("TEE_AllocateOperation: %#" PRIx32, res);
	 }
	 else{
		//for misra
	 }
	 return res;
 }
 
 //SHA512 digest update
 static TEE_Result optee_cryptoSha512_hash_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res = TEE_SUCCESS;
	 void *Data_to_computehash;
	 uint32_t  DataBufSize = 0U;
 
	 if (param_types != exp_param_types)
	 {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else
	 {
		 if (!state->SHA512Operation)
		 {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else
		 {
			 DataBufSize = (uint32_t)params[0].memref.size;
			 Data_to_computehash = TEE_Malloc((size_t)DataBufSize, 0U);
			 if (!Data_to_computehash) {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else {
				 TEE_MemMove(Data_to_computehash, params[0].memref.buffer, (size_t)DataBufSize);
				 TEE_DigestUpdate(state->SHA512Operation, Data_to_computehash, (size_t)DataBufSize);
				 TEE_Free(Data_to_computehash);
			 }
		 }
	 }
 
	 return res;
 }
 
 //SHA512 digest finish
 static TEE_Result optee_cryptoSha512_hash_finish_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res;
	 void *Digest;
	 size_t DigestSize = 0U;
 
	 if (param_types != exp_param_types)
	 {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else
	 {
		 if (!state->SHA512Operation)
		 {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else
		 {
			 DigestSize = params[0].memref.size;
			 Digest = TEE_Malloc((size_t)DigestSize, 0U);
			 if (!Digest)
			 {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else
			 {
				 res = TEE_DigestDoFinal(state->SHA512Operation, NULL, 0U, Digest, &DigestSize);
				 if (res != TEE_SUCCESS) {
					 EMSG("TEE_DigestDoFinal: %#" PRIx32, res);
				 }
				 else {
					 TEE_MemMove(params[0].memref.buffer, Digest, (size_t)DigestSize);
					 params[0].memref.size = DigestSize;
				 }
				 TEE_FreeOperation(state->SHA512Operation);
				 TEE_Free(Digest);
			 }
		 }
	 }
 
	 return res;
 }

  //SHA256 hash computation start
 static TEE_Result optee_cryptoSha256_hash_start_TA(struct cryptoKey *state) {
 
	 TEE_Result res;
	 // Allocate operation handle for SHA-256
	 res = TEE_AllocateOperation(&state->SHA256Operation, TEE_ALG_SHA256, TEE_MODE_DIGEST, 0U);
	 if (res != TEE_SUCCESS) {
		 EMSG("TEE_AllocateOperation: %#" PRIx32, res);
	 }
	 else{
		//for misra
	 }
	 return res;
 }
 
 //SHA 256 digest update
 static TEE_Result optee_cryptoSha256_hash_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res = TEE_SUCCESS;
	 void *Data_to_computehash;
	 uint32_t  DataBufSize = 0U;
 
	 if (param_types != exp_param_types) {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else {
		 if (!state->SHA256Operation) {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else {
			 DataBufSize = (uint32_t)params[0].memref.size;
			 Data_to_computehash = TEE_Malloc((size_t)DataBufSize, 0U);
			 if (!Data_to_computehash) {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else {
				 TEE_MemMove(Data_to_computehash, params[0].memref.buffer, (size_t)DataBufSize);
				 TEE_DigestUpdate(state->SHA256Operation, Data_to_computehash, (size_t)DataBufSize);
				 TEE_Free(Data_to_computehash);
			 }
		 }
	 }
 
	 return res;
 }
 
 //SHA 256 digest finish
 static TEE_Result optee_cryptoSha256_hash_finish_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE, 
						 TEE_PARAM_TYPE_NONE);
	 TEE_Result res;
	 void *Digest;
	 size_t DigestSize = 0U;
 
	 if (param_types != exp_param_types) {
		 res = TEE_ERROR_BAD_PARAMETERS;
		 EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	 }
	 else {
		 if (!state->SHA256Operation) {
			 res = TEE_ERROR_BAD_STATE;
			 EMSG("Bad operation setted %#" PRIx32, res);
		 }
		 else {
			 DigestSize = params[0].memref.size;
			 Digest = TEE_Malloc((size_t)DigestSize, 0U);
			 if (!Digest) {
				 res = TEE_ERROR_OUT_OF_MEMORY;
				 EMSG("TEE_Malloc Failed %#" PRIx32, res);
			 }
			 else {
				 res = TEE_DigestDoFinal(state->SHA256Operation, NULL, 0U, Digest, &DigestSize);
				 if (res != TEE_SUCCESS) {
					 EMSG("TEE_DigestDoFinal: %#" PRIx32, res);
				 }
				 else {
					 TEE_MemMove(params[0].memref.buffer, Digest, (size_t)DigestSize);
					 params[0].memref.size = DigestSize;
				 }
				 TEE_FreeOperation(state->SHA256Operation);
				 TEE_Free(Digest);
			 }
		 }
	 }
 
	 return res;
 }

 static TEE_Result optee_cryptoRsaSsaPkcs15Sha256_verify_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
 {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_VALUE_INPUT, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation = TEE_HANDLE_NULL;
    TEE_Result res;
    void *message, *signature;
    uint32_t message_size = 0U, signature_size = 0U;

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters, expected parameters not matching: %#" PRIx32, res);
    } 
	else
	{
        message_size = (uint32_t)params[0].memref.size;
        message = TEE_Malloc((size_t)message_size, 0U);
        if (!message) {
            res = TEE_ERROR_OUT_OF_MEMORY;
            EMSG("TEE_Malloc Failed %#" PRIx32, res);
        } else
		{
            TEE_MemMove(message, params[0].memref.buffer, (size_t)message_size);
            signature_size = (uint32_t)params[1].memref.size;
            signature = TEE_Malloc(signature_size, 0U);
            if (!signature) {
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("TEE_Malloc Failed %#" PRIx32, res);
                TEE_Free(message);
            } 
			else
			{
				TEE_MemMove(signature, params[1].memref.buffer, (size_t)signature_size);
				// Allocate operation handle for RSA verification
				res = TEE_AllocateOperation(&operation, TEE_ALG_RSASSA_PKCS1_V1_5_SHA256, TEE_MODE_VERIFY, (params[2].value.a * SIZE_OF_1K_BYTES));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
					TEE_Free(message);
					TEE_Free(signature);
				}
				else 
				{
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
					EMSG("TEE_SetOperationKey Failed: %#" PRIx32, res);
					TEE_FreeOperation(operation);
					TEE_Free(message);
					TEE_Free(signature);
					}
					else
					{
						res = TEE_AsymmetricVerifyDigest(operation, NULL, 0U, message, message_size, signature, signature_size);
						if (res != TEE_SUCCESS) {
							EMSG("TEE_AsymmetricVerifyDigest Failed: %#" PRIx32, res);
						} 
						else 
						{
							IMSG("Signature verification successfull.");
						}
						TEE_FreeOperation(operation);
						TEE_Free(message);
						TEE_Free(signature);
					}
				}
			}
    	}
	}
    return res;
}

static TEE_Result SecureCreatePersistblobstore_TA(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
				TEE_PARAM_TYPE_MEMREF_INPUT,
				TEE_PARAM_TYPE_NONE,
				TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object;
	TEE_Result res;
	void *key_id;
	uint32_t keyid_size;
	void *data;
	size_t data_sz;
	uint32_t obj_data_flag;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected param type not matching 0x%08x", res);
	}
	else {
		keyid_size = (uint32_t)params[0].memref.size;
		key_id = TEE_Malloc((size_t)keyid_size, 0U);
		if (!key_id) {
			res = TEE_ERROR_OUT_OF_MEMORY;
			EMSG("TEE_Malloc: %#" PRIx32, res);
		}
		else {
			TEE_MemMove(key_id, params[0].memref.buffer, (size_t)keyid_size);
			data_sz = params[1].memref.size;
			data = TEE_Malloc(data_sz, 0U);
			if (!data) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc: %#" PRIx32, res);
			}
			else {
				TEE_MemMove(data, params[1].memref.buffer, data_sz);
				/*
				* Create object in secure storage and fill with data
				*/
				obj_data_flag = TEE_DATA_FLAG_ACCESS_READ |		/* we can later read the oject */
						TEE_DATA_FLAG_ACCESS_WRITE |		/* we can later write into the object */
						TEE_DATA_FLAG_OVERWRITE;		/* destroy existing object of same ID */

				res = TEE_CreatePersistentObject(TEE_STORAGE_PRIVATE,
								(const void *)key_id, (size_t)keyid_size,
								obj_data_flag,
								TEE_HANDLE_NULL,
								NULL, 0U,		/* we may not fill it right now */
								&object);
				if (res != TEE_SUCCESS) {
					EMSG("TEE_CreatePersistentObject failed 0x%08x", res);
					//TEE_Free(data);
				}
				else {
					res = TEE_WriteObjectData(object, (const void *)data, data_sz);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_WriteObjectData failed 0x%08x", res);
						(void) TEE_CloseAndDeletePersistentObject1(object);
					} else {
						TEE_CloseObject(object);
					}
				}
				TEE_Free(key_id);
				TEE_Free(data);
			}
		}
	}

	return res;
}

// AES CBC Encryption without padding
static TEE_Result optee_cryptoAesCBC_encrypt_nopad_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
                        TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation;
    TEE_Result res;
    void *Plaintext, *CipherDataOut, *iv;
    uint32_t  PlaintextLen = 0U, iv_len = 0U;
	size_t CipherDataBufSize = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		if (!state->key) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {
			PlaintextLen = (uint32_t)params[0].memref.size;
			Plaintext = TEE_Malloc((size_t)PlaintextLen, 0U);
			if (!Plaintext) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
			}
			else {
				TEE_MemMove(Plaintext, params[0].memref.buffer, (size_t)PlaintextLen);
				// Allocate operation handle for AES CBC mode
				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CBC_NOPAD, TEE_MODE_ENCRYPT, (AES_BLOCK_SIZE * 8U));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
				}
				else {
					// Initialize/setting operation with the key for encryption
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
						TEE_FreeOperation(operation);
					}
					else {
						iv_len = (uint32_t)params[1].memref.size;
						iv = TEE_Malloc((size_t)iv_len, 0U);
						if (!iv) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc Failed %#" PRIx32, res);
							TEE_FreeOperation(operation);
							TEE_Free(Plaintext);
						}
						else {
							TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len);
							TEE_CipherInit(operation, iv, AES_BLOCK_SIZE);

							CipherDataBufSize = params[2].memref.size;
							CipherDataOut = TEE_Malloc((size_t)CipherDataBufSize, 0U);
							if (!CipherDataOut) {
								res = TEE_ERROR_OUT_OF_MEMORY;
								EMSG("TEE_Malloc Failed %#" PRIx32, res);
								TEE_FreeOperation(operation);
								TEE_Free(Plaintext);
							}
							else {
								res = TEE_CipherUpdate(operation, (const void *)Plaintext, (size_t)PlaintextLen, CipherDataOut, &CipherDataBufSize);
								if (res != TEE_SUCCESS) {
									EMSG("TEE_CipherUpdate: %#" PRIx32, res);
								}
								else {
									TEE_MemMove(params[2].memref.buffer, CipherDataOut, (size_t)CipherDataBufSize);
									params[2].memref.size = CipherDataBufSize;
								}
								TEE_Free(Plaintext);
								TEE_Free(CipherDataOut);
								TEE_Free(iv);
								TEE_FreeOperation(operation);
							}
						}
					}
				}
			}
		}
	}
    
    return res;
}

// AES CBC decryption without padding
static TEE_Result optee_cryptoAesCBC_decrypt_nopad_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT, 
                        TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation;
    TEE_Result res;
    void *PlaintextOut, *CipherData, *iv;
    uint32_t iv_len = 0U, CipherDataLen = 0U;
	size_t PlaintextOutBufSize = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected param type not matching 0x%08x", res);
	}
	else
	{
		if (!state->key) {
			res =  TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {

			CipherDataLen = (uint32_t)params[0].memref.size;
			CipherData = TEE_Malloc((size_t)CipherDataLen, 0U);
			if (!CipherData) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc: %#" PRIx32, res);
			}
			else {
				TEE_MemMove(CipherData, params[0].memref.buffer, CipherDataLen);

				// Allocate operation handle for AES CBC mode
				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CBC_NOPAD, TEE_MODE_DECRYPT, (AES_BLOCK_SIZE * 8U));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
					TEE_Free(CipherData);
				}
				else {
					// Initialize/setting operation with the key for decryption
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
						TEE_Free(CipherData);
						TEE_FreeOperation(operation);
					}
					else {
						iv_len = (uint32_t)params[1].memref.size;
						iv = TEE_Malloc(iv_len, 0U);
						if (!iv) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc: %#" PRIx32, res);
							TEE_Free(CipherData);
							TEE_FreeOperation(operation);
						}
						else {
							TEE_MemMove(iv, params[1].memref.buffer, (size_t)iv_len); 
							TEE_CipherInit(operation, iv, AES_BLOCK_SIZE);

							PlaintextOutBufSize = params[2].memref.size;
							PlaintextOut = TEE_Malloc((size_t)PlaintextOutBufSize, 0U);
							if (!PlaintextOut) {
								res = TEE_ERROR_OUT_OF_MEMORY;
								EMSG("TEE_Malloc: %#" PRIx32, res);
								TEE_Free(CipherData);
								TEE_FreeOperation(operation);
								TEE_Free(iv);
							}
							else {
								res = TEE_CipherUpdate(operation, (const void *)CipherData, (size_t)CipherDataLen, PlaintextOut, &PlaintextOutBufSize);
								if (res != TEE_SUCCESS) {
									EMSG("TEE_CipherUpdate: %#" PRIx32, res);
									TEE_FreeOperation(operation);
								}
								else {
									TEE_MemMove(params[2].memref.buffer, PlaintextOut, (size_t)PlaintextOutBufSize);
									params[2].memref.size = PlaintextOutBufSize;
									TEE_Free(PlaintextOut);
									TEE_Free(CipherData);
									TEE_Free(iv);
									TEE_FreeOperation(operation);
								}
							}
						}
					}
				}				
			}
		}
	}

    return res;
}

static TEE_Result optee_cryptoAesECB_encrypt_nopad_TA(struct cryptoKey *state,
                                                       uint32_t param_types,
                                                       TEE_Param params[4])
{
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_OUTPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
	TEE_OperationHandle operation;
	TEE_Result res;
	void *Plaintext, *CipherDataOut;
	uint32_t PlaintextLen = 0U;
	size_t CipherDataBufSize = 0U;

	if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else
	{
		if (!state->key) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {
			PlaintextLen = (uint32_t)params[0].memref.size;
			Plaintext = TEE_Malloc((size_t)PlaintextLen, 0U);
			if (!Plaintext) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
			}
			else {
				TEE_MemMove(Plaintext, params[0].memref.buffer, PlaintextLen);
				// Allocate operation handle for AES ECB mode
				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_ECB_NOPAD, TEE_MODE_ENCRYPT, (AES_BLOCK_SIZE * 8U));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
				}
				else {
					// Initialize/setting operation with the key for encryption
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
						TEE_FreeOperation(operation);
					}
					else {
						CipherDataBufSize = params[1].memref.size;
						CipherDataOut = TEE_Malloc((size_t)CipherDataBufSize, 0U);
						if (!CipherDataOut) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc Failed %#" PRIx32, res);
							TEE_FreeOperation(operation);
							TEE_Free(Plaintext);
						}
						else {
							// ECB does not use IV, pass NULL
							TEE_CipherInit(operation, NULL, 0U);
							res = TEE_CipherUpdate(operation, (const void *)Plaintext, (size_t)PlaintextLen, CipherDataOut, &CipherDataBufSize);
							if (res != TEE_SUCCESS) {
								EMSG("TEE_CipherUpdate: %#" PRIx32, res);
							}
							else {
								TEE_MemMove(params[1].memref.buffer, CipherDataOut, (size_t)CipherDataBufSize);
								params[1].memref.size = CipherDataBufSize;
							}
							TEE_Free(Plaintext);
							TEE_Free(CipherDataOut);
							TEE_FreeOperation(operation);
						}
					}
				}
			}
		}
	}

	return res;
}

static TEE_Result optee_cryptoAesECB_decrypt_nopad_TA(struct cryptoKey *state,
                                                       uint32_t param_types,
                                                       TEE_Param params[4])
{
    const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_OUTPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
	TEE_OperationHandle operation;
	TEE_Result res;
	void *CiphertextIn, *PlaintextOut;
	uint32_t CiphertextLen = 0U;
	size_t PlaintextOutBufSize = 0U;

	if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected param types not matching: 0x%08" PRIx32, res);
	}
	else
	{
		if (!state->key) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state, no key set: 0x%08" PRIx32, res);
		}
		else {
			CiphertextLen = (uint32_t)params[0].memref.size;
			CiphertextIn = TEE_Malloc((size_t)CiphertextLen, 0U);
			if (!CiphertextIn) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc for ciphertext failed: 0x%08" PRIx32, res);
			}
			else {
				TEE_MemMove(CiphertextIn, params[0].memref.buffer, (size_t)CiphertextLen);

				// Allocate operation handle for AES ECB mode
				res = TEE_AllocateOperation(&operation, TEE_ALG_AES_ECB_NOPAD, TEE_MODE_DECRYPT, (AES_BLOCK_SIZE * 8U));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: 0x%08" PRIx32, res);
					TEE_Free(CiphertextIn);
				}
				else {
					// Initialize/setting operation with the key for decryption
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: 0x%08" PRIx32, res);
						TEE_Free(CiphertextIn);
						TEE_FreeOperation(operation);
					}
					else {
						PlaintextOutBufSize = (uint32_t)params[1].memref.size;
						PlaintextOut = TEE_Malloc((size_t)PlaintextOutBufSize, 0U);
						if (!PlaintextOut) {
							res = TEE_ERROR_OUT_OF_MEMORY;
							EMSG("TEE_Malloc for output buffer failed: 0x%08" PRIx32, res);
							TEE_Free(CiphertextIn);
							TEE_FreeOperation(operation);
						}
						else {
							// ECB does not use IV, just call init with NULL
							TEE_CipherInit(operation, NULL, 0U);

							res = TEE_CipherUpdate(operation, (const void *)CiphertextIn, (size_t)CiphertextLen, PlaintextOut, &PlaintextOutBufSize);
							if (res != TEE_SUCCESS) {
								EMSG("TEE_CipherUpdate failed: 0x%08" PRIx32, res);
							}
							else {
								TEE_MemMove(params[1].memref.buffer, PlaintextOut, (size_t)PlaintextOutBufSize);
								params[1].memref.size = PlaintextOutBufSize;
							}
							TEE_Free(PlaintextOut);
							TEE_Free(CiphertextIn);
							TEE_FreeOperation(operation);
						}
					}
				}
			}
		}
	}

	return res;
}

/******************************************************************************************************************************************
************************************ CBC_decryption *********************************************
** Function: optee_crypto_AES128CBC_decrypt_start_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128CBC_decrypt_start_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
	(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    void  *iv = NULL;
    size_t  iv_len = 0U;

    if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
	}
	else {
		if (state->key == TEE_HANDLE_NULL) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("Bad Key state no key setted %#" PRIx32, res);
		}
		else {
			if (state->AES128CBC_DecryptOpStatus == false) {  // TEE_HANDLE_NULL = 0 -> false
#ifdef CFG_CRYPTO_DEBUG
				DMSG("In AES128CBC_DecryptOpStatus setting \n");
#endif
				// Allocate operation handle for AES CBC mode
				res = TEE_AllocateOperation(&state->AES128CBC_DecryptOp, TEE_ALG_AES_CBC_NOPAD, TEE_MODE_DECRYPT, (AES_BLOCK_SIZE * 8U));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
				}
				else {
					// Initialize/setting operation with the key for decryption
					res = TEE_SetOperationKey(state->AES128CBC_DecryptOp, state->key);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_SetOperationKey: %#" PRIx32, res);
						TEE_FreeOperation(state->AES128CBC_DecryptOp);
					} else {
						state->AES128CBC_DecryptOpStatus = true;
					}
				}
			}
			iv_len = params[0].memref.size;
			iv = TEE_Malloc(iv_len, 0U);
			if (!iv) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("TEE_Malloc Failed %#" PRIx32, res);
				TEE_FreeOperation(state->AES128CBC_DecryptOp);
			}
			else {
				TEE_MemMove(iv, params[0].memref.buffer, iv_len);
				TEE_CipherInit(state->AES128CBC_DecryptOp, iv, AES_BLOCK_SIZE);
				TEE_Free(iv);
			}
		}
	}
	
    return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128CBC_decrypt_update_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128CBC_decrypt_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
        (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    uint32_t CipherDataLen = 0u;
	size_t PlaintextOutBufSize = 0u;
	void *CipherData = NULL, *PlaintextOut = NULL;

    if (param_types != exp_param_types) {  // Validating input parameter type
		res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters, expected output buffer: %#" PRIx32 "\n", res);
	} 
	else {
        if (state->AES128CBC_DecryptOp == TEE_HANDLE_NULL) {
			res = TEE_ERROR_BAD_STATE;
        	EMSG("Decrypt operation not initialized or setter: %#" PRIx32 "\n", res);
		} else {
			CipherDataLen = (uint32_t)params[0].memref.size;
			CipherData = TEE_Malloc((size_t)CipherDataLen, 0u);
            if (CipherData == NULL) {        // Checking for ciphertext buffer overflow
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("Failed to allocate cipher input buffer : %#" PRIx32 "\n", res);
            } else {
				PlaintextOutBufSize = params[1].memref.size;
				PlaintextOut = TEE_Malloc((size_t)PlaintextOutBufSize, 0u);
            	if (PlaintextOut == NULL) {       // Checking for ciphertext buffer overflow
                	res = TEE_ERROR_OUT_OF_MEMORY;
                	EMSG("Failed to allocate Output buffer : %#" PRIx32 "\n", res);
            	} else {
					TEE_MemMove(CipherData, params[0].memref.buffer, (size_t)CipherDataLen);
					res = TEE_CipherUpdate(state->AES128CBC_DecryptOp, (const void *)CipherData, (size_t)CipherDataLen, PlaintextOut, &PlaintextOutBufSize);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_CipherUpdate: %#" PRIx32, res);
						TEE_FreeOperation(state->AES128CBC_DecryptOp);
					}
					else {
						TEE_MemMove(params[1].memref.buffer, PlaintextOut, (size_t)PlaintextOutBufSize);
						params[1].memref.size = PlaintextOutBufSize;
					}
					TEE_Free(PlaintextOut);
					TEE_Free(CipherData);
            	}
			}
		}
	}

    return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128CBC_decrypt_final_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128CBC_decrypt_final_TA(uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
        (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_OUTPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
	uint32_t PlainDataNonPadLen = 0u, PlaintextOutBufSize = 0u, padding = 0U, pad =0U;
	uint32_t PaddingLen = 0u, loopiterator = 0U;
	uint8_t *PlainDataNonPad = NULL;

    if (param_types != exp_param_types) {  // Validating input parameter type
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected output buffer: %#" PRIx32 "\n", res);
	} 
	else {
		PlainDataNonPadLen = (uint32_t)params[0].memref.size;
		PlainDataNonPad = (uint8_t *)TEE_Malloc((size_t)PlainDataNonPadLen, 0u);
		if (PlainDataNonPad == NULL) {        // Checking for ciphertext buffer overflow
			res = TEE_ERROR_OUT_OF_MEMORY;
			EMSG("Failed to allocate PlainDataNonPad input buffer : %#" PRIx32 "\n", res);
		} else {
			PlaintextOutBufSize = (uint32_t)params[1].memref.size;
			TEE_MemMove(PlainDataNonPad, params[0].memref.buffer, (size_t)PlainDataNonPadLen);
#ifdef CFG_CRYPTO_DEBUG
			DMSG("Final buffer size before padding removal: %u", PlainDataNonPadLen);
#endif
			if(PlainDataNonPadLen > 0U)
			{
				padding = PlainDataNonPadLen - 1U;
			}
			else{
				//misra
			}		
			PaddingLen = PlainDataNonPad[padding];
			if ((PaddingLen < 1U) || (PaddingLen > AES_BLOCK_SIZE)) {
				//EMSG("Padding Length not matching : %#" PRIx32, res);
				//res = TEE_ERROR_BAD_STATE;
			}
			else {
				pad = padding - loopiterator;
				for (loopiterator = 0U; loopiterator < PaddingLen; loopiterator++) {
					if ((PlainDataNonPad[pad]) != PaddingLen) {
						// Invalid padding
					}
				}
#ifdef CFG_CRYPTO_DEBUG
				DMSG("Detected padding length: %u", PaddingLen);
#endif
				if(PlainDataNonPadLen < PaddingLen)
				{
					res = TEE_ERROR_OUT_OF_MEMORY;

				}
				else
				{
					PlaintextOutBufSize = PlainDataNonPadLen - PaddingLen;  // Remove padding from the output
				
#ifdef CFG_CRYPTO_DEBUG				
					DMSG("Final buffer size after padding removal: %u", PlaintextOutBufSize);
#endif				
				}
			}

			TEE_MemMove(params[1].memref.buffer, PlainDataNonPad, (size_t)PlaintextOutBufSize);
			params[1].memref.size = PlaintextOutBufSize;

		}
		TEE_Free(PlainDataNonPad);
		PlainDataNonPad = NULL;
	}

    return res;
}

/******************************************************************************************************************************************
************************************ GCM_decryption *********************************************
** Function: optee_crypto_AES128GCM_decrypt_start_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128GCM_decrypt_start_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE,
		                TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);

	TEE_Result res = TEE_SUCCESS;
	void *iv = NULL;
	size_t iv_len = 0U;

	if (param_types == exp_param_types)
	{
		if (state->key != TEE_HANDLE_NULL)
		{
			if (state->AES128GCM_DecryptOpStatus == false)  // TEE_HANDLE_NULL = 0 -> false
			{
#ifdef CFG_CRYPTO_DEBUG
				DMSG("Allocating GCM Decrypt operation handle");
#endif
				res = TEE_AllocateOperation(&state->AES128GCM_DecryptOp,
				                            TEE_ALG_AES_GCM,
				                            TEE_MODE_DECRYPT,
				                            (AES_BLOCK_SIZE * 8U));
				if (res == TEE_SUCCESS)
				{
					res = TEE_SetOperationKey(state->AES128GCM_DecryptOp, state->key);
					if (res == TEE_SUCCESS)
					{
						state->AES128GCM_DecryptOpStatus = true;
					}
					else
					{
						EMSG("TEE_SetOperationKey failed: %#" PRIx32, res);
						TEE_FreeOperation(state->AES128GCM_DecryptOp);
						state->AES128GCM_DecryptOp = TEE_HANDLE_NULL;
					}
				}
				else
				{
					EMSG("TEE_AllocateOperation failed: %#" PRIx32, res);
				}
			}

			if (res == TEE_SUCCESS)
			{
				iv_len = params[0].memref.size;
				iv = TEE_Malloc(iv_len, 0U);
				if (iv != NULL)
				{
					TEE_MemMove(iv, params[0].memref.buffer, iv_len);

					res = TEE_AEInit(state->AES128GCM_DecryptOp,
					                 iv, iv_len,
					                 AES_GCM_TAG_LENGTH_BITS, 0U, 0U);
					TEE_Free(iv);
					iv = NULL;

					if (res == TEE_SUCCESS)
					{
						TEE_AEUpdateAAD(state->AES128GCM_DecryptOp, NULL, 0U);
						// No error return, since TEE_AEUpdateAAD() returns void
					}
					else
					{
						EMSG("TEE_AEInit failed: %#" PRIx32, res);
					}
				}
				else
				{
					res = TEE_ERROR_OUT_OF_MEMORY;
					EMSG("TEE_Malloc for IV failed");
					TEE_FreeOperation(state->AES128GCM_DecryptOp);
					state->AES128GCM_DecryptOp = TEE_HANDLE_NULL;
				}
			}
		}
		else
		{
			res = TEE_ERROR_BAD_STATE;
			EMSG("Key is not set. state->key is NULL");
		}
	}
	else
	{
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameter types: %#" PRIx32, param_types);
	}

	return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128GCM_decrypt_update_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128GCM_decrypt_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
	const uint32_t exp_param_types =
		(uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_OUTPUT,
						TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
	TEE_Result res = TEE_SUCCESS;
	void *cipher_data = NULL, *plain_out = NULL;
	uint32_t cipher_len = 0u;
	size_t plain_len = 0u;

	if (param_types != exp_param_types) {
		res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters, expected param types mismatch: %#" PRIx32, res);
	} 
	else {
		if (state->AES128GCM_DecryptOp == TEE_HANDLE_NULL) {
			res = TEE_ERROR_BAD_STATE;
			EMSG("AES128GCM DecryptOp not initialized: %#" PRIx32, res);
		}
		else {
			cipher_len = (uint32_t)params[0].memref.size;
			cipher_data = TEE_Malloc((size_t)cipher_len, 0u);
			if (!cipher_data) {
				res = TEE_ERROR_OUT_OF_MEMORY;
				EMSG("Malloc failed for cipher input buffer: %#" PRIx32, res);
			}
			else {
				plain_len = params[1].memref.size;
				plain_out = TEE_Malloc((size_t)plain_len, 0u);
				if (!plain_out) {
					res = TEE_ERROR_OUT_OF_MEMORY;
					EMSG("Malloc failed for output buffer: %#" PRIx32, res);
				} else {
					TEE_MemMove(cipher_data, params[0].memref.buffer, (size_t)cipher_len);

					res = TEE_AEUpdate(state->AES128GCM_DecryptOp, (const void *)cipher_data, (size_t)cipher_len, plain_out, &plain_len);
					if (res != TEE_SUCCESS) {
						EMSG("TEE_AEUpdate failed: %#" PRIx32, res);
					}
					else {
						TEE_MemMove(params[1].memref.buffer, plain_out, (size_t)plain_len);
						params[1].memref.size = plain_len;
					}
					TEE_Free(plain_out);
				}
				TEE_Free(cipher_data);
			}
		}
	}

	return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128GCM_decrypt_final_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128GCM_decrypt_final_TA(struct cryptoKey *state,
                                                         uint32_t param_types,
                                                         TEE_Param params[4])
{
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    TEE_Result res = TEE_SUCCESS;

    if (param_types == exp_param_types)
    {
        if (params[0].memref.size != 16U) {
            EMSG("Invalid authentication tag size: %lu", params[0].memref.size);
            res = TEE_ERROR_BAD_PARAMETERS;
        }
		else{
    	    DMSG("Auth Tag Size     : %lu", params[0].memref.size);
    	    DMSG("Plaintext Buf Size: %lu", params[1].memref.size);

    	    // No more ciphertext input needed
    	    res = TEE_AEDecryptFinal(state->AES128GCM_DecryptOp,
    	                             NULL, 0U,                                       // no ciphertext
    	                             params[1].memref.buffer, &params[1].memref.size, // plaintext output
    	                             params[0].memref.buffer, params[0].memref.size); // auth tag input

    	    if (res != TEE_SUCCESS) {
    	        EMSG("TEE_AEDecryptFinal failed (auth tag mismatch?): 0x%" PRIx32, res);
    	    }
		}
    }
    else
    {
        EMSG("Invalid param types for GCM decrypt final: 0x%" PRIx32, param_types);
        res = TEE_ERROR_BAD_PARAMETERS;
    }

    return res;
}

/******************************************************************************************************************************************
************************************ ECB_decryption *********************************************
** Function: optee_crypto_AES128ECB_decrypt_start_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128ECB_decrypt_start_TA(struct cryptoKey *state, uint32_t param_types) {
    const uint32_t exp_param_types =
        (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE);

    TEE_Result res = TEE_SUCCESS;

    if (param_types != exp_param_types)
	{
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters for ECB decrypt start: 0x%08" PRIx32, res);
    }
    else if (state->key == TEE_HANDLE_NULL)
	{
        res = TEE_ERROR_BAD_STATE;
        EMSG("Key not set in secure state: 0x%08" PRIx32, res);
    }
    else
	{
        res = TEE_AllocateOperation(&state->AES128ECB_DecryptOp,
                                    TEE_ALG_AES_ECB_NOPAD,
                                    TEE_MODE_DECRYPT,
                                    AES_BLOCK_SIZE * 8U);
        if (res != TEE_SUCCESS)
		{
            EMSG("TEE_AllocateOperation failed: 0x%08" PRIx32, res);
        }
        else
		{
            res = TEE_SetOperationKey(state->AES128ECB_DecryptOp, state->key);
            if (res != TEE_SUCCESS)
			{
                EMSG("TEE_SetOperationKey failed: 0x%08" PRIx32, res);
                TEE_FreeOperation(state->AES128ECB_DecryptOp);
                state->AES128ECB_DecryptOp = TEE_HANDLE_NULL;
                state->AES128ECB_DecryptOpStatus = false;
            }
            else
			{
                // ECB mode doesn't use IV — Init cipher context once
                TEE_CipherInit(state->AES128ECB_DecryptOp, NULL, 0U);
                state->AES128ECB_DecryptOpStatus = true;
                IMSG("ECB Decrypt Start - Operation initialized successfully.");
            }
        }
    }

    return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128ECB_decrypt_update_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128ECB_decrypt_update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
     const uint32_t exp_param_types =
        (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                        TEE_PARAM_TYPE_MEMREF_OUTPUT,
                        TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE);

    TEE_Result res = TEE_SUCCESS;
    void *cipher_in = NULL, *plain_out = NULL;
    uint32_t in_len = 0U, out_len = 0U;
	size_t actual_out_len = 0U;

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameter types for ECB decrypt update: 0x%08" PRIx32, res);
    }
    else if ((state->AES128ECB_DecryptOp == TEE_HANDLE_NULL) ||
             (state->AES128ECB_DecryptOpStatus == false)) {
        res = TEE_ERROR_BAD_STATE;
        EMSG("Decrypt operation is not initialized or active: 0x%08" PRIx32, res);
    }
    else {
        in_len = (uint32_t)params[0].memref.size;
        out_len = (uint32_t)params[1].memref.size;

        IMSG("ECB Decrypt Update - InputLen: %u, OutputBufSize: %u", in_len, out_len);

        if ((in_len == 0U) || (out_len == 0U) || ((in_len % AES_BLOCK_SIZE) != 0U)) {
            res = TEE_ERROR_BAD_PARAMETERS;
            EMSG("Invalid input/output lengths: inLen = %u, outLen = %u", in_len, out_len);
        }
        else if (out_len < in_len) {
            res = TEE_ERROR_SHORT_BUFFER;
            EMSG("Output buffer too small: inLen = %u, outLen = %u", in_len, out_len);
        }
        else {
            cipher_in  = TEE_Malloc((size_t)in_len, 0U);
            plain_out  = TEE_Malloc((size_t)out_len, 0U);

            if ((cipher_in == NULL) || (plain_out == NULL)) {
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("Memory allocation failed for buffers in decrypt update: 0x%08" PRIx32, res);
            }
            else {
                TEE_MemMove(cipher_in, params[0].memref.buffer, (size_t)in_len);

                actual_out_len = (size_t)out_len;

                res = TEE_CipherUpdate(state->AES128ECB_DecryptOp,
                                       (const void *)cipher_in,
                                       (size_t)in_len,
                                       plain_out,
                                       &actual_out_len);

                if (res == TEE_SUCCESS) {
					if (params[1].memref.buffer != NULL) {
						TEE_MemMove(params[1].memref.buffer, plain_out, (size_t)actual_out_len);
						params[1].memref.size = actual_out_len;
						IMSG("ECB Decrypt Update - Success. OutLen: %lu", actual_out_len);
					} else {
						res = TEE_ERROR_BAD_PARAMETERS;
						EMSG(" TA : Output buffer is NULL");
					}
				}
                else {
                    EMSG("TEE_CipherUpdate failed: 0x%08" PRIx32, res);
                }

                TEE_Free(cipher_in);
                TEE_Free(plain_out);
            }
        }
    }

    return res;
}

/******************************************************************************************************************************************
** Function: optee_crypto_AES128ECB_decrypt_final_TA
********************************************************************************************************************************************/

static TEE_Result optee_crypto_AES128ECB_decrypt_final_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types =
        (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE,
                        TEE_PARAM_TYPE_NONE);

    TEE_Result res = TEE_SUCCESS;
    (void)params;

    // Debug print for parameter validation
    IMSG("ECB Decrypt Final - Received param_types: 0x%08" PRIx32, param_types);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameter types for ECB decrypt final: 0x%08" PRIx32, res);
    }
    else if ((state->AES128ECB_DecryptOp == TEE_HANDLE_NULL) ||
             (state->AES128ECB_DecryptOpStatus == false)) {
        res = TEE_ERROR_BAD_STATE;
        EMSG("Final called without active operation: 0x%08" PRIx32, res);
    }
    else {
        TEE_FreeOperation(state->AES128ECB_DecryptOp);
        state->AES128ECB_DecryptOp = TEE_HANDLE_NULL;
        state->AES128ECB_DecryptOpStatus = false;
        IMSG("ECB Decrypt Final - Operation cleaned up.");
    }

    return res;
}

static TEE_Result optee_cryptoset_asymkey_fromblob_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) 
{
    TEE_Result res = TEE_SUCCESS;
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, 
                                                               TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
    TEE_ObjectHandle object = TEE_HANDLE_NULL;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    TEE_ObjectInfo object_info;
    TEE_Attribute attrs[4]; 
    
    void *keyid = NULL;
    void *persist_key = NULL;
	uint8_t *key_bytes = NULL;
    uint32_t keyid_size = 0U;
    size_t read_bytes = 0;

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Param types mismatch: 0x%08x", res);
    }
    else {
        keyid_size = (uint32_t)params[0].memref.size;
        keyid = TEE_Malloc((size_t)keyid_size, 0U);
        if (!keyid) {
            res = TEE_ERROR_OUT_OF_MEMORY;
        }
        else {
            TEE_MemMove(keyid, params[0].memref.buffer, params[0].memref.size);

            res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE,
                                           keyid, (size_t)keyid_size,
                                           TEE_DATA_FLAG_ACCESS_READ | TEE_DATA_FLAG_SHARE_READ,
                                           &object);
            if (res != TEE_SUCCESS) {
                EMSG("Failed to open persistent object: 0x%08x", res);
            }
            else {
                res = TEE_GetObjectInfo1(object, &object_info);
                if (res != TEE_SUCCESS) {
                    EMSG("GetObjectInfo failed: 0x%08x", res);
                }
                else {
                    persist_key = TEE_Malloc(object_info.dataSize, 0U);
                    if (!persist_key) {
                        res = TEE_ERROR_OUT_OF_MEMORY;
                        EMSG("TEE_Malloc: %#" PRIx32, res);
                    }
                    else {
                        res = TEE_ReadObjectData(object, persist_key, object_info.dataSize, &read_bytes);
                        if ((res != TEE_SUCCESS) || (read_bytes != (object_info.dataSize))) {	
                            EMSG("TEE_ReadObjectData failed 0x%08x, read %u" PRIu32 " over %lu",
                                        res, (uint32_t)read_bytes, object_info.dataSize);
                        }
                        else {
                            res = TEE_AllocateTransientObject(TEE_TYPE_ECDSA_KEYPAIR, 384, &key);
                            if (res != TEE_SUCCESS) {
                                EMSG("AllocateTransientObject failed: 0x%08x", res);
                            }
                            else {
								key_bytes = (uint8_t *)persist_key;
                                TEE_InitValueAttribute(&attrs[0], TEE_ATTR_ECC_CURVE, TEE_ECC_CURVE_NIST_P384, 0);
                                
                                TEE_InitRefAttribute(&attrs[1], TEE_ATTR_ECC_PRIVATE_VALUE, key_bytes, SIZE_OF_ECDSA_PRIV);
                                TEE_InitRefAttribute(&attrs[2], TEE_ATTR_ECC_PUBLIC_VALUE_X, &key_bytes[48], SIZE_OF_ECDSA_PRIV);
                                TEE_InitRefAttribute(&attrs[3], TEE_ATTR_ECC_PUBLIC_VALUE_Y, &key_bytes[96], SIZE_OF_ECDSA_PRIV);

                                IMSG("read_bytes = %zu", read_bytes);
                                
                                res = TEE_PopulateTransientObject(key, attrs, 4U);
                                
                                if (res != TEE_SUCCESS) {
                                    EMSG("Populate failed: 0x%08x", res);
                                    TEE_FreeTransientObject(key);
                                }
                                else {
                                    if (state->key != TEE_HANDLE_NULL) {
                                        TEE_FreeTransientObject(state->key);
                                    }
                                    state->key = key;
                                    IMSG("Asymmetric ECDSA P384 key loaded.");
                                }
                            }
                        }
                        TEE_Free(persist_key);
                    }
                }
                TEE_CloseObject(object);
            }
            TEE_Free(keyid);
        }
    }
    return res;
}

static TEE_Result optee_cryptoset_asympubkey_ecdsa_in_teeObject_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_NONE,
						TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    uint8_t *userkey_X = NULL;
    size_t key_size_X = 0;
	uint8_t *userkey_Y = NULL;
    size_t key_size_Y = 0;
    TEE_Attribute attr[3] = { };
	
    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
    } else {
        key_size_X = params[0].memref.size;
        userkey_X = TEE_Malloc(key_size_X, 0);
        key_size_Y = params[1].memref.size;
        userkey_Y = TEE_Malloc(key_size_Y, 0);

        if ((!userkey_X) || (!userkey_Y)) {
            res = TEE_ERROR_OUT_OF_MEMORY;
            if (userkey_X) { 
				TEE_Free(userkey_X); 
			} else { 
				/* for MISRA */ 
			}
            if (userkey_Y) { 
				TEE_Free(userkey_Y); 
			} else { 
				/* for MISRA */ 
			}
        } else {
            TEE_MemMove(userkey_X, params[0].memref.buffer, key_size_X);
            TEE_MemMove(userkey_Y, params[1].memref.buffer, key_size_Y);

            if ((key_size_X != SIZE_OF_ECDSA_X) || (key_size_Y != SIZE_OF_ECDSA_Y)) {
                EMSG("Invalid key size: expected %u X bytes %u Y bytes , got %zu X bytes %zu Y bytes ",
                     SIZE_OF_ECDSA_X, SIZE_OF_ECDSA_Y, key_size_X, key_size_Y);
                res = TEE_ERROR_BAD_PARAMETERS;
                TEE_Free(userkey_X);
                TEE_Free(userkey_Y);
            } else {
                res = TEE_AllocateTransientObject(TEE_TYPE_ECDSA_PUBLIC_KEY, (SIZE_OF_ECDSA_BITS), &key);
                if (res != TEE_SUCCESS) {
                    EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
                    TEE_Free(userkey_X);
                    TEE_Free(userkey_Y);
                } else {
                    TEE_InitValueAttribute(&attr[0], TEE_ATTR_ECC_CURVE, TEE_ECC_CURVE_NIST_P384, 0);
                    TEE_InitRefAttribute(&attr[1], TEE_ATTR_ECC_PUBLIC_VALUE_X, userkey_X, key_size_X);
                    TEE_InitRefAttribute(&attr[2], TEE_ATTR_ECC_PUBLIC_VALUE_Y, userkey_Y, key_size_Y);

                    res = TEE_PopulateTransientObject(key, attr, 3);
                    if (res != TEE_SUCCESS) {
                        EMSG("TEE_PopulateTransientObject failed: %#" PRIx32, res);
                        TEE_FreeTransientObject(key);
                        TEE_Free(userkey_X);
                        TEE_Free(userkey_Y);
                    } else {
                        /* Success path assign key to state */
                        if (state->key != TEE_HANDLE_NULL) {
                            TEE_FreeTransientObject(state->key);
                        } else {
                            /* for MISRA */
                        }
                        state->key = key;
                        IMSG("ECDSA Public key successfully set in the transient object.");
                    }
                }
            }
        }
    }

    return res;
}


static TEE_Result optee_cryptoset_asymprivkey_ecdsa_in_teeObject_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_MEMREF_INPUT,
						TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    TEE_ObjectHandle key = TEE_HANDLE_NULL;
    void *privatekey = NULL;
    size_t key_size = 0U;
	void *userkey_X = NULL;
    size_t key_size_X = 0U;
	void *userkey_Y = NULL;
    size_t key_size_Y = 0U;
    TEE_Attribute attr[4] = { };

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
    } 
	else {
        key_size = params[0].memref.size;
        privatekey = TEE_Malloc(key_size, 0U);
		key_size_X = params[1].memref.size;
        userkey_X = TEE_Malloc(key_size_X, 0U);
        key_size_Y = params[2].memref.size;
        userkey_Y = TEE_Malloc(key_size_Y, 0U);

        if ((!privatekey)  || (!userkey_X) || (!userkey_Y)) {
            res = TEE_ERROR_OUT_OF_MEMORY;
            if (privatekey != NULL) { 
				TEE_Free(privatekey); 
			} else { 
				/* for MISRA */ 
			}
			res = TEE_ERROR_OUT_OF_MEMORY;
            if (userkey_X != NULL) { 
				TEE_Free(userkey_X); 
			} else { 
				/* for MISRA */ 
			}
            if (userkey_Y != NULL) { 
				TEE_Free(userkey_Y); 
			} else { 
				/* for MISRA */ 
			}
        } else {
            TEE_MemMove(privatekey, params[0].memref.buffer, key_size);
			TEE_MemMove(userkey_X, params[1].memref.buffer, key_size_X);
            TEE_MemMove(userkey_Y, params[2].memref.buffer, key_size_Y);

            if ((key_size != SIZE_OF_ECDSA_PRIV) || (key_size_X != SIZE_OF_ECDSA_X) || (key_size_Y != SIZE_OF_ECDSA_Y)){
                EMSG("Invalid key size: expected %u priv bytes %u X bytes %u Y bytes , got %zu Priv bytes %zu X bytes %zu Y bytes ",
                     SIZE_OF_ECDSA_PRIV, SIZE_OF_ECDSA_X, SIZE_OF_ECDSA_Y, key_size, key_size_X, key_size_Y);
                res = TEE_ERROR_BAD_PARAMETERS;
                TEE_Free(privatekey);
				TEE_Free(userkey_X);
                TEE_Free(userkey_Y);
            } 
			else {
                res = TEE_AllocateTransientObject(TEE_TYPE_ECDSA_KEYPAIR, (SIZE_OF_ECDSA_BITS), &key);
                if (res != TEE_SUCCESS) {
                    EMSG("TEE_AllocateTransientObject: %#" PRIx32, res);
                    TEE_Free(privatekey);
					TEE_Free(userkey_X);
                    TEE_Free(userkey_Y);
                } else {
                    TEE_InitValueAttribute(&attr[0], TEE_ATTR_ECC_CURVE, TEE_ECC_CURVE_NIST_P384, 0U);
                    TEE_InitRefAttribute(&attr[1], TEE_ATTR_ECC_PRIVATE_VALUE, privatekey, key_size);
					TEE_InitRefAttribute(&attr[2], TEE_ATTR_ECC_PUBLIC_VALUE_X, userkey_X, key_size_X);
                    TEE_InitRefAttribute(&attr[3], TEE_ATTR_ECC_PUBLIC_VALUE_Y, userkey_Y, key_size_Y);

                    res = TEE_PopulateTransientObject(key, attr, 4U);
                    if (res != TEE_SUCCESS) {
                        EMSG("TEE_PopulateTransientObject failed: %#" PRIx32, res);
                        TEE_FreeTransientObject(key);
                        TEE_Free(privatekey);
						TEE_Free(userkey_X);
                        TEE_Free(userkey_Y);
                    } else {
                        /* Success path assign key to state */
                        if (state->key != TEE_HANDLE_NULL) {
                            TEE_FreeTransientObject(state->key);
                        } else {
                            /* for MISRA */
                        }
                        state->key = key;
                        IMSG("ECDSA Public key successfully set in the transient object.");
                    }
                }
            }
        }
    }

    return res;
}

static TEE_Result optee_cryptoEcdsaP384_verify_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[3])
 {
	 const uint32_t exp_param_types =
		 (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation = TEE_HANDLE_NULL;
    TEE_Result res;
    void *message, *signature;
    uint32_t message_size = 0U, signature_size = 0U;

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters, expected parameters not matching: %#" PRIx32, res);
    } 
	else
	{
        message_size = (uint32_t)params[0].memref.size;
        message = TEE_Malloc((size_t)message_size, 0U);
        if (!message) {
            res = TEE_ERROR_OUT_OF_MEMORY;
            EMSG("TEE_Malloc Failed %#" PRIx32, res);
        } else
		{
            TEE_MemMove(message, params[0].memref.buffer, (size_t)message_size);
            signature_size = (uint32_t)params[1].memref.size;
            signature = TEE_Malloc((size_t)signature_size, 0U);
            if (!signature) {
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("TEE_Malloc Failed %#" PRIx32, res);
                TEE_Free(message);
            } 
			else
			{
				TEE_MemMove(signature, params[1].memref.buffer, (size_t)signature_size);
				// Allocate operation handle for RSA verification
				res = TEE_AllocateOperation(&operation, TEE_ALG_ECDSA_P384, TEE_MODE_VERIFY, (SIZE_OF_ECDSA_BITS));
				if (res != TEE_SUCCESS) {
					EMSG("TEE_AllocateOperation: %#" PRIx32, res);
					TEE_Free(message);
					TEE_Free(signature);
				}
				else 
				{
					res = TEE_SetOperationKey(operation, state->key);
					if (res != TEE_SUCCESS) {
					EMSG("TEE_SetOperationKey Failed: %#" PRIx32, res);
					TEE_FreeOperation(operation);
					TEE_Free(message);
					TEE_Free(signature);
					}
					else
					{
						res = TEE_AsymmetricVerifyDigest(operation, NULL, 0U, message, message_size, signature, signature_size);
						if (res != TEE_SUCCESS) {
							EMSG("TEE_AsymmetricVerifyDigest Failed: %#" PRIx32, res);
						} 
						else 
						{
							IMSG("Signature verification successfull.");
						}
						TEE_FreeOperation(operation);
						TEE_Free(message);
						TEE_Free(signature);
					}
				}
			}
    	}
	}
    return res;
}

static TEE_Result optee_cryptoEcdsaP384_sign_generate_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, 
                                                               TEE_PARAM_TYPE_MEMREF_OUTPUT, 
                                                               TEE_PARAM_TYPE_NONE, 
                                                               TEE_PARAM_TYPE_NONE);
    TEE_OperationHandle operation = TEE_HANDLE_NULL;
    TEE_Result res = TEE_SUCCESS;
    void *message = NULL;
    void *signature = NULL;
    uint32_t message_size = 0U;
    size_t signature_size = 0U;

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
		EMSG("Invalid parameters , expected parameters not matching: %#" PRIx32, res);
    }
    else {
        if (state->key == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
            EMSG("No key loaded in session state");
        }
        else {
            message_size = (uint32_t)params[0].memref.size;
            message = TEE_Malloc((size_t)message_size, 0U);
            if (!message) {
                res = TEE_ERROR_OUT_OF_MEMORY;
            }
            else {
                signature_size = params[1].memref.size;
                signature = TEE_Malloc(signature_size, 0U);
                if (!signature) {
                    res = TEE_ERROR_OUT_OF_MEMORY;
                }
                else {
					IMSG("state->key = %p", state->key);
					IMSG("Digest len = %u", message_size);
                    TEE_MemMove(message, params[0].memref.buffer, (size_t)message_size);
                    
                    res = TEE_AllocateOperation(&operation, TEE_ALG_ECDSA_P384, TEE_MODE_SIGN, 384);
                    if (res != TEE_SUCCESS) {
                        EMSG("TEE_AllocateOperation failed: %#" PRIx32, res);
                    }
                    else {
                        res = TEE_SetOperationKey(operation, state->key);
                        if (res != TEE_SUCCESS) {
                            EMSG("TEE_SetOperationKey failed: %#" PRIx32, res);
                        }
                        else {
                            res = TEE_AsymmetricSignDigest(operation, NULL, 0U, 
                                                           message, (size_t)message_size, 
                                                           signature, &signature_size);
                            if (res != TEE_SUCCESS) {
                                EMSG("TEE_AsymmetricSignDigest failed: %#" PRIx32, res);
                            }
                            else {
                                TEE_MemMove(params[1].memref.buffer, signature, signature_size);
                                params[1].memref.size = (uint32_t)signature_size;
                                IMSG("Signature generated successfully.");
                            }
                        }
                        TEE_FreeOperation(operation);
                    }
                    TEE_Free(signature);
                }
                TEE_Free(message);
            }
        }
    }
    return res;
}

static TEE_Result optee_generate_ecdsa_in_teeObject_TA(uint32_t param_types, TEE_Param params[4]) {
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                    TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                    TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                    TEE_PARAM_TYPE_NONE);
    TEE_Result res = TEE_SUCCESS;
    TEE_ObjectHandle key_handle = TEE_HANDLE_NULL;
    TEE_Attribute attr[1] = { };
	size_t size_d = 0U;
	size_t size_x = 0U;
    size_t size_y = 0U;


    if (param_types != exp_param_types) 
	{
        EMSG("Invalid parameters, expected parameters not matching: %#" PRIx32, param_types);
        res = TEE_ERROR_BAD_PARAMETERS;
    }
	else{
    	res = TEE_AllocateTransientObject(TEE_TYPE_ECDSA_KEYPAIR, SIZE_OF_ECDSA_BITS, &key_handle);
    	if (res != TEE_SUCCESS) {
    	    EMSG("TEE_AllocateTransientObject failed: %#" PRIx32, res);
    	}
		else
		{
    		TEE_InitValueAttribute(&attr[0], TEE_ATTR_ECC_CURVE, TEE_ECC_CURVE_NIST_P384, 0U);
    		res = TEE_GenerateKey(key_handle, SIZE_OF_ECDSA_BITS, attr, 1U);
    		if (res != TEE_SUCCESS) {
    		    EMSG("Failed to generate ECDSA key pair: 0x%x", res);
    		    if (key_handle != TEE_HANDLE_NULL) {
    		    TEE_FreeTransientObject(key_handle);
    			}
    		}
			else
			{
    			IMSG("ECDSA P-384 key pair generated successfully. Extracting components...");

    			size_d = params[0].memref.size;
    			size_x = params[1].memref.size;
    			size_y = params[2].memref.size;

    			// Extract Private Key (d)
    			res = TEE_GetObjectBufferAttribute(key_handle, TEE_ATTR_ECC_PRIVATE_VALUE, params[0].memref.buffer, &size_d);
    			if (res != TEE_SUCCESS) {
    			    EMSG("Failed to get private value: 0x%x", res);
    			    if (key_handle != TEE_HANDLE_NULL) {
    			    TEE_FreeTransientObject(key_handle);
   					}
    			}
				else{
				    params[0].memref.size = size_d;
					// Extract Public Key X
    				res = TEE_GetObjectBufferAttribute(key_handle, TEE_ATTR_ECC_PUBLIC_VALUE_X, params[1].memref.buffer, &size_x);
    				if (res != TEE_SUCCESS) {
    				    EMSG("Failed to get public X value: 0x%x", res);
    				    if (key_handle != TEE_HANDLE_NULL) {
    				    TEE_FreeTransientObject(key_handle);
    					}
    				}
					else{
					    params[1].memref.size = size_x;
						// Extract Public Key Y
    					res = TEE_GetObjectBufferAttribute(key_handle, TEE_ATTR_ECC_PUBLIC_VALUE_Y, params[2].memref.buffer, &size_y);
    					if (res != TEE_SUCCESS) {
    					    EMSG("Failed to get public Y value: 0x%x", res);
    					    if (key_handle != TEE_HANDLE_NULL) {
    					    TEE_FreeTransientObject(key_handle);
    						}
    					}
						else{
						    params[2].memref.size = size_y;
						}
					}
				}
    			IMSG("\n ECDSA P-384 generated and extracted: d=%lu X=%lu Y=%lu bytes \n",
    			     params[0].memref.size, params[1].memref.size, params[2].memref.size);
			}
		}
	}

    return res;
}

static TEE_Result optee_certificate_verification_TA(uint32_t param_types, TEE_Param params[4])
{
    const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(
            TEE_PARAM_TYPE_MEMREF_INPUT,
            TEE_PARAM_TYPE_MEMREF_INPUT,
            TEE_PARAM_TYPE_NONE,
            TEE_PARAM_TYPE_NONE); 
	uint8_t *l_cert_buf_SP = NULL, *l_ca_buf_SP = NULL;
    uint32_t l_cert_len_SP = 0U, l_ca_len_SP = 0U;
    uint32_t l_flags_SP = 0U;
	char l_vrfy_buf_SP[CERTIFICATE_VERIFICATION];
	int ret = 0;
    mbedtls_x509_crt 	l_cert_SP;
    mbedtls_x509_crt l_ca_SP;
    TEE_Result res = TEE_SUCCESS;

    if (param_types != exp_param_types) 
	{
		EMSG("Invalid parameters, expected parameters not matching: %#" PRIx32, res);
		res = TEE_ERROR_BAD_PARAMETERS;
    }
	else
	{
		
    	l_cert_len_SP = (uint32_t)params[0].memref.size;
    	l_ca_len_SP   = (uint32_t)params[1].memref.size;

    	if ((l_cert_len_SP == 0U) || (l_ca_len_SP == 0U) ||
    	    (l_cert_len_SP > MAX_CERT_SIZE) || (l_ca_len_SP > MAX_CERT_SIZE)) {
    	    EMSG("Invalid cert sizes: l_cert_len_SP=%u l_ca_len_SP=%u", l_cert_len_SP, l_ca_len_SP);
    	    res = TEE_ERROR_BAD_PARAMETERS;
    	}
		else
		{
    		/* Allocate +1 to add NULL terminator inside TA */
    		l_cert_buf_SP = (uint8_t *)TEE_Malloc(((size_t)l_cert_len_SP + 1ULL), 0U);
    		l_ca_buf_SP   = (uint8_t *)TEE_Malloc(((size_t)l_ca_len_SP + 1ULL), 0U);
    		if (!l_cert_buf_SP || !l_ca_buf_SP) {
    		    EMSG("TEE_Malloc Failed");
    		    res = TEE_ERROR_OUT_OF_MEMORY;
				TEE_Free(l_cert_buf_SP);
   				TEE_Free(l_ca_buf_SP);
    		}
			else{
    			/* Copy exactly l_cert_len_SP / l_ca_len_SP bytes and add NULs inside TA */
    			TEE_MemMove(l_cert_buf_SP, params[0].memref.buffer, (size_t)l_cert_len_SP);
    			l_cert_buf_SP[l_cert_len_SP] = 0U;

    			TEE_MemMove(l_ca_buf_SP, params[1].memref.buffer, (size_t)l_ca_len_SP);
    			l_ca_buf_SP[l_ca_len_SP] = 0U;

    			mbedtls_x509_crt_init(&l_cert_SP);
    			mbedtls_x509_crt_init(&l_ca_SP);

    			/* Parse CA cert — pass length+1 so PEM parser can see terminating NUL safely */
				ret = mbedtls_x509_crt_parse(&l_ca_SP, (const unsigned char *)l_ca_buf_SP, ((size_t)l_ca_len_SP + 1ULL));
    			if (ret != 0) {
    			    EMSG("CA cert parse failed -0x%x", ret);
    			    res = TEE_ERROR_GENERIC;
    			    mbedtls_x509_crt_free(&l_cert_SP);
   					mbedtls_x509_crt_free(&l_ca_SP);
					TEE_Free(l_cert_buf_SP);
	   				TEE_Free(l_ca_buf_SP);
    			}
				else
				{
    				/* Parse chain cert */
					ret = mbedtls_x509_crt_parse(&l_cert_SP, (const unsigned char *)l_cert_buf_SP, ((size_t)l_cert_len_SP + 1ULL));
    				if (ret != 0) {
    				    EMSG("Cert parse failed -0x%x", ret);
    				    res = TEE_ERROR_GENERIC;
    				    mbedtls_x509_crt_free(&l_cert_SP);
   						mbedtls_x509_crt_free(&l_ca_SP);
						TEE_Free(l_cert_buf_SP);
	   					TEE_Free(l_ca_buf_SP);
    				}
					else{
    					/* Verify */
    					if (mbedtls_x509_crt_verify(&l_cert_SP, &l_ca_SP, NULL, NULL, &l_flags_SP, NULL, NULL) != 0) {
    					    (void) mbedtls_x509_crt_verify_info(l_vrfy_buf_SP, sizeof(l_vrfy_buf_SP), "  ! ", l_flags_SP);
    					    EMSG("Verify failed: %s", l_vrfy_buf_SP);
    					    res = TEE_ERROR_ACCESS_DENIED;
    					    mbedtls_x509_crt_free(&l_cert_SP);
   							mbedtls_x509_crt_free(&l_ca_SP);
							TEE_Free(l_cert_buf_SP);
	   						TEE_Free(l_ca_buf_SP);
    					}
						else{
    						IMSG("Certificate is VALID");
    						res = TEE_SUCCESS;
						}
					}
				}
			}
		}
	}

    return res;
}


/* IPSEC Write function */
static TEE_Result cmd_write_pem_key_TA(uint32_t param_types, TEE_Param params[4])
{
    TEE_Result result = TEE_ERROR_GENERIC;
    TEE_ObjectHandle object = TEE_HANDLE_NULL;
    void *ptr_key_id_buf = NULL;
	const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                       TEE_PARAM_TYPE_MEMREF_INPUT,
                                       TEE_PARAM_TYPE_NONE,
                                       TEE_PARAM_TYPE_NONE);
    if (param_types != exp_param_types)
    {
        result = TEE_ERROR_BAD_PARAMETERS;
        EMSG("WRITE_PEM: invalid param_types 0x%x", param_types);
    }
    else
    {
        size_t key_id_len = params[0].memref.size;
        size_t pem_len = params[1].memref.size;

        if ((params[0].memref.buffer == NULL) || (key_id_len == 0U))
        {
            result = TEE_ERROR_BAD_PARAMETERS;
            EMSG("WRITE_PEM: bad key_id params");
        }
        else if ((params[1].memref.buffer == NULL) || (pem_len == 0U))
        {
            result = TEE_ERROR_BAD_PARAMETERS;
            EMSG("WRITE_PEM: bad PEM buffer params");
        }
        else
        {
            ptr_key_id_buf = TEE_Malloc(key_id_len, 0U);
            if (ptr_key_id_buf != NULL)
            {
                TEE_MemMove(ptr_key_id_buf, params[0].memref.buffer, (uint32_t)key_id_len);

                result = TEE_CreatePersistentObject(TEE_STORAGE_PRIVATE,
                                                    ptr_key_id_buf, key_id_len,
                                                    TEE_DATA_FLAG_ACCESS_READ |
                                                    TEE_DATA_FLAG_ACCESS_WRITE |
                                                    TEE_DATA_FLAG_OVERWRITE,
                                                    TEE_HANDLE_NULL,
                                                    params[1].memref.buffer, pem_len,
                                                    &object);

                if (result != TEE_SUCCESS)
                {
                    EMSG("WRITE_PEM: create failed 0x%x", result);
                }
                else
                {
                    /* Object created and written successfully */
                }

                if (object != TEE_HANDLE_NULL)
                {
                    TEE_CloseObject(object);
                }
                else
                {
                    /* for MISRA */
                }

                TEE_Free(ptr_key_id_buf);
            }
            else
            {
                result = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("WRITE_PEM: allocation failed");
            }
        }
    }

    return result;
}

/*IPSEC Read function */
static TEE_Result cmd_read_pem_key_TA(uint32_t param_types, TEE_Param params[4])
{
    TEE_Result result = TEE_ERROR_GENERIC;
    TEE_ObjectHandle object = TEE_HANDLE_NULL;
    void *ptr_key_id_buf = NULL;
	size_t read_bytes = 0U;

	const uint32_t exp_param_types = (uint32_t)TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                       TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                       TEE_PARAM_TYPE_NONE,
                                       TEE_PARAM_TYPE_NONE);
    if (param_types != exp_param_types)
    {
        result = TEE_ERROR_BAD_PARAMETERS;
        EMSG("READ_PEM: invalid param_types 0x%x", param_types);
    }
    else
    {
        size_t key_id_len = params[0].memref.size;

        if ((params[0].memref.buffer == NULL) || (key_id_len == 0U))
        {
            result = TEE_ERROR_BAD_PARAMETERS;
            EMSG("READ_PEM: bad key_id buffer params");
        }
        else
        {
            ptr_key_id_buf = TEE_Malloc((size_t)key_id_len, 0U);
            if (ptr_key_id_buf != NULL)
            {
                TEE_MemMove(ptr_key_id_buf, params[0].memref.buffer, (size_t)key_id_len);

                result = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE,
                                                  (const void *)ptr_key_id_buf, (size_t)key_id_len,
                                                  TEE_DATA_FLAG_ACCESS_READ |
                                                  TEE_DATA_FLAG_SHARE_READ,
                                                  &object);

                if (result != TEE_SUCCESS)
                {
                    EMSG("READ_PEM: open failed 0x%x", result);
                }
                else
                {
                    TEE_ObjectInfo info;
                    (void)TEE_MemFill(&info, 0U, sizeof(info));
                    result = TEE_GetObjectInfo1(object, &info);

                    if (result != TEE_SUCCESS)
                    {
                        EMSG("READ_PEM: GetInfo failed 0x%x", result);
                    }
                    else
                    {
                        if (params[1].memref.buffer == NULL)
                        {
                            result = TEE_ERROR_BAD_PARAMETERS;
                            EMSG("READ_PEM: output buffer is NULL");
                        }
                        else if (params[1].memref.size < info.dataSize)
                        {
                            params[1].memref.size = info.dataSize;
                            result = TEE_ERROR_SHORT_BUFFER;
                            EMSG("READ_PEM: buffer too short (need %lu)", info.dataSize);
                        }
                        else
                        {
                            result = TEE_ReadObjectData(object,
                                                        params[1].memref.buffer,
                                                        info.dataSize,
                                                        &read_bytes);

                            if ((result != TEE_SUCCESS) || (read_bytes != info.dataSize))
                            {
                                result = TEE_ERROR_CORRUPT_OBJECT;
                                EMSG("READ_PEM: partial/corrupt read");
                            }
                            else
                            {
                                params[1].memref.size = read_bytes;
                            }
                        }
                    }

                    TEE_CloseObject(object);
                }

                TEE_Free(ptr_key_id_buf);
            }
            else
            {
                result = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("READ_PEM: allocation failed");
            }
        }
    }

    return result;
}

static TEE_Result optee_crypto_CMAC_Generate_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    TEE_OperationHandle operation = TEE_HANDLE_NULL;

    uint8_t *InputData = NULL;
    uint32_t InputLen = 0;
    uint8_t *MacDataOut = NULL;
    uint32_t MacDataBufSize = 0;
    size_t MacLen = 16;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters %#x", res);
    }
    else {
        if (state->key == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
            EMSG("Bad Key state, no key setted %#x", res);
        }
        else {
            InputLen = params[0].memref.size;
            InputData = TEE_Malloc(InputLen, 0);

            if (!InputData) {
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("TEE_Malloc Failed %#x", res);
            }
            else {
                TEE_MemMove(InputData, params[0].memref.buffer, InputLen);
                MacDataBufSize = params[1].memref.size;
				
                if (MacDataBufSize < MacLen) {
                    res = TEE_ERROR_SHORT_BUFFER;
                    EMSG("Output buffer too small");
                }
                else {
                    MacDataOut = TEE_Malloc(MacDataBufSize, 0);
                    if (!MacDataOut) {
                        res = TEE_ERROR_OUT_OF_MEMORY;
                        EMSG("Output Malloc Failed %#x", res);
                    }
                    else {
                        res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CMAC, TEE_MODE_MAC, AES128_KEY_BITLEN);
                        if (res != TEE_SUCCESS) {
                            EMSG("Alloc Op Failed %#x", res);
                        }
                        else {
                            res = TEE_SetOperationKey(operation, state->key);
                            if (res != TEE_SUCCESS) {
                                EMSG("Set Key Failed %#x", res);
                            }
                            else {
                                TEE_MACInit(operation, NULL, 0);
                                TEE_MACUpdate(operation, InputData, InputLen);
                                res = TEE_MACComputeFinal(operation, NULL, 0, MacDataOut, &MacLen);

                                if (res != TEE_SUCCESS) {
                                    EMSG("CMAC Gen: ComputeFinal Failed %#x", res);
                                }
                                else {
                                    TEE_MemMove(params[1].memref.buffer, MacDataOut, MacLen);
                                    params[1].memref.size = MacLen;
                                    IMSG("CMAC Generation Successful");
                                }
                            }
                            TEE_FreeOperation(operation);
                        }
                        TEE_Free(MacDataOut);
                    }
                }
                TEE_Free(InputData);
            }
        }
    }

    return res;
}

static TEE_Result optee_crypto_CMAC_Verify_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    TEE_OperationHandle operation = TEE_HANDLE_NULL;

    uint8_t *InputData = NULL;
    uint32_t InputLen = 0;
    uint8_t *InputMac = NULL;
    uint32_t InputMacLen = 0;

    uint8_t *ComputedMac = NULL;
    size_t ComputedLen = 16;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("Invalid parameters %#x", res);
    }
    else {
        if (state->key == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
            EMSG("Bad Key state, no key setted %#x", res);
        }
        else {
            InputLen = params[0].memref.size;
            InputData = TEE_Malloc(InputLen, 0);

            if (!InputData) {
                res = TEE_ERROR_OUT_OF_MEMORY;
                EMSG("Input Malloc Failed");
            }
            else {
                TEE_MemMove(InputData, params[0].memref.buffer, InputLen);

                InputMacLen = params[1].memref.size;
                InputMac = TEE_Malloc(InputMacLen, 0);

                if (!InputMac) {
                    res = TEE_ERROR_OUT_OF_MEMORY;
                    EMSG("InputMac Malloc Failed");
                }
                else {
                    TEE_MemMove(InputMac, params[1].memref.buffer, InputMacLen);

                    ComputedMac = TEE_Malloc(ComputedLen, 0);
                    if (!ComputedMac) {
                        res = TEE_ERROR_OUT_OF_MEMORY;
                        EMSG("ComputedMac Malloc Failed");
                    }
                    else {
                        res = TEE_AllocateOperation(&operation, TEE_ALG_AES_CMAC, TEE_MODE_MAC, (AES_BLOCK_SIZE * 8U));
                        if (res != TEE_SUCCESS) {
                            EMSG("Alloc Op Failed %#x", res);
                        }
                        else {
                            res = TEE_SetOperationKey(operation, state->key);
                            if (res != TEE_SUCCESS) {
                                EMSG("Set Key Failed %#x", res);
                            }
                            else {
                                TEE_MACInit(operation, NULL, 0);
                                TEE_MACUpdate(operation, InputData, InputLen);
                                res = TEE_MACComputeFinal(operation, NULL, 0, ComputedMac, &ComputedLen);

                                if (res != TEE_SUCCESS) {
                                    EMSG("ComputeFinal Failed %#x", res);
                                }
                                else {
                                    if (ComputedLen != InputMacLen) {
                                        res = TEE_ERROR_MAC_INVALID;
                                        EMSG("Length Mismatch");
                                    }
                                    else if (TEE_MemCompare(ComputedMac, InputMac, ComputedLen) != 0) {
                                        res = TEE_ERROR_MAC_INVALID;
                                        EMSG("Mismatch");
                                    }
                                    else {
                                        res = TEE_SUCCESS;
                                        IMSG("CMAC Verification Successful");
                                    }
                                }
                            }
                            TEE_FreeOperation(operation);
                        }
                        TEE_Free(ComputedMac);
                    }
                    TEE_Free(InputMac);
                }
                TEE_Free(InputData);
            }
        }
    }
    return res;
}

// CMAC GENERATION (Start, Update, Finish)
static TEE_Result optee_crypto_CMAC_Gen_Start_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Gen Start: Bad Parameters. Expected NONE.");
    }
    else {
        (void)params;

        if (state->cmac_operation != TEE_HANDLE_NULL) {
            TEE_FreeOperation(state->cmac_operation);
            state->cmac_operation = TEE_HANDLE_NULL;
        }

        if (state->key == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
            EMSG("CMAC Gen Start: Key not loaded in session");
        }
        else {
            res = TEE_AllocateOperation(&state->cmac_operation, TEE_ALG_AES_CMAC, TEE_MODE_MAC, (AES_BLOCK_SIZE * 8U));
            if (res != TEE_SUCCESS) {
                EMSG("CMAC Gen Start: Allocate failed 0x%x", res);
            }
            else {
                res = TEE_SetOperationKey(state->cmac_operation, state->key);
                if (res != TEE_SUCCESS) {
                    TEE_FreeOperation(state->cmac_operation);
                    state->cmac_operation = TEE_HANDLE_NULL;
                    EMSG("CMAC Gen Start: SetKey failed 0x%x", res);
                }
                else {
                    TEE_MACInit(state->cmac_operation, NULL, 0);
                }
            }
        }
    }
    return res;
}

static TEE_Result optee_crypto_CMAC_Gen_Update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    void *input_data = NULL;
    uint32_t input_len;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Gen Update: Bad Parameters. Expected 1 Input.");
    }
    else {
        if (state->cmac_operation == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
        }
        else {
            input_len = params[0].memref.size;
            input_data = TEE_Malloc(input_len, 0);

            if (input_data == NULL) {
                res = TEE_ERROR_OUT_OF_MEMORY;
            }
            else {
                TEE_MemMove(input_data, params[0].memref.buffer, input_len);
                TEE_MACUpdate(state->cmac_operation, input_data, input_len);
                TEE_Free(input_data);
            }
        }
    }
    return res;
}

static TEE_Result optee_crypto_CMAC_Gen_Finish_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    size_t mac_len = AES_BLOCK_SIZE;
    uint8_t mac_buf[AES_BLOCK_SIZE];

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_OUTPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Gen Finish: Bad Parameters. Expected 1 Output.");
    }
    else {
        if (state->cmac_operation == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
        }
        else {
            res = TEE_MACComputeFinal(state->cmac_operation, NULL, 0, mac_buf, &mac_len);

            TEE_FreeOperation(state->cmac_operation);
            state->cmac_operation = TEE_HANDLE_NULL;

            if (res == TEE_SUCCESS) {
                if (params[0].memref.size < mac_len) {
                    params[0].memref.size = mac_len;
                    res = TEE_ERROR_SHORT_BUFFER;
                }
                else {
                    TEE_MemMove(params[0].memref.buffer, mac_buf, mac_len);
                    params[0].memref.size = mac_len;
                }
            }
        }
    }
    return res;
}

// CMAC VERIFICATION (Start, Update, Finish)
static TEE_Result optee_crypto_CMAC_Ver_Start_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Ver Start: Bad Parameters. Expected NONE.");
    }
    else {
        (void)params;

        if (state->cmac_operation != TEE_HANDLE_NULL) {
            TEE_FreeOperation(state->cmac_operation);
            state->cmac_operation = TEE_HANDLE_NULL;
        }

        if (state->key == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
            EMSG("CMAC Ver Start: Key not loaded in session");
        }
        else {
            res = TEE_AllocateOperation(&state->cmac_operation, TEE_ALG_AES_CMAC, TEE_MODE_MAC, (AES_BLOCK_SIZE * 8U));
            if (res != TEE_SUCCESS) {
                EMSG("CMAC Ver Start: Allocate failed 0x%x", res);
            }
            else {
                res = TEE_SetOperationKey(state->cmac_operation, state->key);
                if (res != TEE_SUCCESS) {
                    TEE_FreeOperation(state->cmac_operation);
                    state->cmac_operation = TEE_HANDLE_NULL;
                    EMSG("CMAC Ver Start: SetKey failed 0x%x", res);
                }
                else {
                    TEE_MACInit(state->cmac_operation, NULL, 0);
                }
            }
        }
    }
    return res;
}

static TEE_Result optee_crypto_CMAC_Ver_Update_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    void *input_data = NULL;
    uint32_t input_len;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Ver Update: Bad Parameters. Expected 1 Input.");
    }
    else {
        if (state->cmac_operation == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
        }
        else {
            input_len = params[0].memref.size;
            input_data = TEE_Malloc(input_len, 0);

            if (input_data == NULL) {
                res = TEE_ERROR_OUT_OF_MEMORY;
            }
            else {
                TEE_MemMove(input_data, params[0].memref.buffer, input_len);
                TEE_MACUpdate(state->cmac_operation, input_data, input_len);
                TEE_Free(input_data);
            }
        }
    }
    return res;
}

static TEE_Result optee_crypto_CMAC_Ver_Finish_TA(struct cryptoKey *state, uint32_t param_types, TEE_Param params[4])
{
    TEE_Result res = TEE_SUCCESS;
    size_t mac_len = AES_BLOCK_SIZE;
    uint8_t computed_mac[AES_BLOCK_SIZE];
    uint8_t *expected_mac = NULL;

    const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE,
                                                     TEE_PARAM_TYPE_NONE);

    if (param_types != exp_param_types) {
        res = TEE_ERROR_BAD_PARAMETERS;
        EMSG("CMAC Ver Finish: Bad Parameters. Expected 1 Input.");
    }
    else {
        if (state->cmac_operation == TEE_HANDLE_NULL) {
            res = TEE_ERROR_BAD_STATE;
        }
        else {
            expected_mac = TEE_Malloc(params[0].memref.size, 0);
            if (expected_mac == NULL) {
                TEE_FreeOperation(state->cmac_operation);
                state->cmac_operation = TEE_HANDLE_NULL;
                res = TEE_ERROR_OUT_OF_MEMORY;
            }
            else {
                TEE_MemMove(expected_mac, params[0].memref.buffer, params[0].memref.size);

                res = TEE_MACComputeFinal(state->cmac_operation, NULL, 0, computed_mac, &mac_len);

                TEE_FreeOperation(state->cmac_operation);
                state->cmac_operation = TEE_HANDLE_NULL;

                if (res == TEE_SUCCESS) {
                    if (TEE_MemCompare(computed_mac, expected_mac, 16) != 0) {
                        res = TEE_ERROR_MAC_INVALID;
                    }
                }
                TEE_Free(expected_mac);
            }
        }
    }
    return res;
}

TEE_Result TA_CreateEntryPoint(void)
{
	/* Nothing to do */
	return TEE_SUCCESS;
}

void TA_DestroyEntryPoint(void)
{
	/* Nothing to do */
}

TEE_Result TA_OpenSessionEntryPoint(uint32_t __unused param_types,
                                    TEE_Param __unused params[4],
                                    void **session)
{
    TEE_Result res = TEE_SUCCESS;
    struct cryptoKey *state = NULL;

    state = TEE_Malloc(sizeof(*state), 0U);
    if (!state) {
        res = TEE_ERROR_OUT_OF_MEMORY;
    } else {
        /* Initialize all handles to NULL */
        state->key = TEE_HANDLE_NULL;
        state->SHA256Operation = TEE_HANDLE_NULL;
        state->AES128CBC_DecryptOp = TEE_HANDLE_NULL;
        state->AES128GCM_DecryptOp = TEE_HANDLE_NULL;
        state->AES128ECB_DecryptOp = TEE_HANDLE_NULL;

        /* Initialize status l_flags_SP */
        state->AES128CBC_DecryptOpStatus = false;
        state->AES128GCM_DecryptOpStatus = false;
        state->AES128ECB_DecryptOpStatus = false;

        *session = state;
    }

    return res;
}

void TA_CloseSessionEntryPoint(void *session)
{
	struct cryptoKey *state = session;

	TEE_FreeTransientObject(state->key);
    TEE_Free(state);

}

TEE_Result TA_InvokeCommandEntryPoint(void *session,
				      uint32_t command,
				      uint32_t param_types,
				      TEE_Param params[4])
{	
	TEE_Result res = TEE_SUCCESS;
	switch (command) {
    case TA_CRYPTO_CMD_AES_SETUSERKEY :
        res = optee_cryptoset_symkey_in_teeObject_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ENCRYPT:
		res = optee_cryptoAesCBC_encrypt_with_pkcs11pad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_DECRYPT:
		res = optee_cryptoAesCBC_decrypt_with_pkcs11pad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_GCM_ENCRYPT:
    	res = optee_cryptoAesGCM_encrypt_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_GCM_DECRYPT:
		res = optee_cryptoAesGCM_decrypt_TA(session, param_types, params);	
		break;
	case TA_CRYPTO_CMD_AES_GCM_DECRYPT_START:
		res = optee_crypto_AES128GCM_decrypt_start_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_GCM_DECRYPT_UPDATE:
		res = optee_crypto_AES128GCM_decrypt_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_GCM_DECRYPT_FINAL:
		res = optee_crypto_AES128GCM_decrypt_final_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ECB_ENCRYPT:
		res = optee_cryptoAesECB_encrypt_nopad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ECB_DECRYPT:
		res = optee_cryptoAesECB_decrypt_nopad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ECB_DECRYPT_START:
		res = optee_crypto_AES128ECB_decrypt_start_TA(session, param_types);
		break;
	case TA_CRYPTO_CMD_AES_ECB_DECRYPT_UPDATE:
		res = optee_crypto_AES128ECB_decrypt_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ECB_DECRYPT_FINISH:
		res = optee_crypto_AES128ECB_decrypt_final_TA(session, param_types, params);	
		break;
	case TA_CRYPTO_CMD_AES_SHA256_HASH:
		res = optee_cryptoSha256_hash_TA(param_types, params);
		break;
    case TA_CRYPTO_CMD_AES_SETKEY_FROM_BLOB:
        res = optee_cryptoset_symkey_fromblob_TA(session,param_types, params);
		break;
    case TA_SECURE_STORAGE_CMD_WRITE_RAW:
		res = SecureCreatePersistblobstore_TA(param_types, params);
		break;
    case TA_SECURE_STORAGE_CMD_SECUREBLOB_CHECK:
		res = CheckSecureBlobExistance_TA(param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_DECRYPTNOPAD:
		res = optee_cryptoAesCBC_decrypt_nopad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_ENCRYPTNOPAD:
		res = optee_cryptoAesCBC_encrypt_nopad_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_RSA_SETUSERPUBKEY :
		res = optee_cryptoset_asympubkey_in_teeObject_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_RSASSA_PKCS1_V1_5_SHA256_VERIFY: 
		res = optee_cryptoRsaSsaPkcs15Sha256_verify_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_RSA_SETUSERPUBKEY_3K :
		res = optee_cryptoset_asympubkey_3k_in_teeObject_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA512_START :
		res = optee_cryptoSha512_hash_start_TA(session);
		break;
	case TA_CRYPTO_CMD_AES_SHA512_UPDATE :
		res = optee_cryptoSha512_hash_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA512_FINISH :
		res = optee_cryptoSha512_hash_finish_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA256_START :
		res = optee_cryptoSha256_hash_start_TA(session);
		break;
	case TA_CRYPTO_CMD_AES_SHA256_UPDATE :
		res = optee_cryptoSha256_hash_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA256_FINISH :
		res = optee_cryptoSha256_hash_finish_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_CBC_DECRYPT_START :
	 	res = optee_crypto_AES128CBC_decrypt_start_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_CBC_DECRYPT_UPDATE :
	    res = optee_crypto_AES128CBC_decrypt_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_CBC_DECRYPT_FINISH :
		res = optee_crypto_AES128CBC_decrypt_final_TA(param_types, params);
		break;
	case TA_CRYPTO_CMD_SYM_KEY_CHECK :
	 	res = optee_crypto_AES128CBC_symkey_setstatus_TA(session);
		break;
	case TA_CRYPTO_CMD_ECDSA_SETUSERPUBKEY :
		res = optee_cryptoset_asympubkey_ecdsa_in_teeObject_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_ecdsa_p384_VERIFY :
		res = optee_cryptoEcdsaP384_verify_TA(session, param_types, params);
		break;
	case TA_SECURE_STORAGE_CMD_WRITE_PEM_KEY :
		res = cmd_write_pem_key_TA(param_types, params);
		break;
	case TA_SECURE_STORAGE_CMD_READ_PEM_KEY	:
		res = cmd_read_pem_key_TA(param_types, params);
		break;
	case TA_CRYPTO_CMD_ecdsa_p384_SIGN :
		res = optee_cryptoEcdsaP384_sign_generate_TA(session, param_types, params);	
		break;
	case TA_CRYPTO_CMD_ECDSA_SETUSERPRIVKEY :
		res = optee_cryptoset_asymprivkey_ecdsa_in_teeObject_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA384_START :
		res = optee_cryptoSha384_hash_start_TA(session);
		break;
	case TA_CRYPTO_CMD_AES_SHA384_UPDATE :
		res = optee_cryptoSha384_hash_update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_AES_SHA384_FINISH :
		res = optee_cryptoSha384_hash_finish_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_ECDSA_GENERATE :
		res = optee_generate_ecdsa_in_teeObject_TA(param_types, params);
		break;
	case TA_CRYPTO_CMD_CERT_VERIFY :
		res = optee_certificate_verification_TA(param_types, params);
		break;
	case TA_CRYPTO_CMD_ASM_SETKEY_FROM_BLOB :
		res = optee_cryptoset_asymkey_fromblob_TA(session,param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_GENERATE :
		res = optee_crypto_CMAC_Generate_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_VERIFY :
		res = optee_crypto_CMAC_Verify_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_GEN_START :
		res = optee_crypto_CMAC_Gen_Start_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_GEN_UPDATE :
		res = optee_crypto_CMAC_Gen_Update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_GEN_FINISH :
		res = optee_crypto_CMAC_Gen_Finish_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_VER_START :
		res = optee_crypto_CMAC_Ver_Start_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_VER_UPDATE :
		res = optee_crypto_CMAC_Ver_Update_TA(session, param_types, params);
		break;
	case TA_CRYPTO_CMD_CMAC_VER_FINISH :
		res = optee_crypto_CMAC_Ver_Finish_TA(session, param_types, params);
		break;

	default:
		EMSG("Command ID 0x%x is not supported", command);
		res = TEE_ERROR_NOT_SUPPORTED;
		break;
	}
	return res;
}