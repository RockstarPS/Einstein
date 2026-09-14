///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include "UclALCryptoOpenSSL_Impl.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include <openssl/rand.h>
#include <openssl/cmac.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <string.h>
#include <stdint.h>

///
/// @brief This method implements the Random API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pResult Pointer to buffer to store the random number
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Random number generation Success
///	@return	UCL_E_NOK 	Random number generation Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_Random(SUclALCryptoOpenSSLInst *pInst, uint8 InstId, uint8 *pResult,
                                                           uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pResult) && (Size > 0))
    {
        if (1 == RAND_bytes(pResult, Size))
        {
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE(0, "UclALCryptoOpenSSL_Impl", "Random: RAND_bytes failed");
        }
    }
    else
    {
        LOGE(0, "UclALCryptoOpenSSL_Impl", "Random: Invalid input arguments");
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}
#if 0 //Disabled the SetSessionKey
///
/// @brief This method implements the SetSessionKey API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pKey Pointer to buffer containing the key
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Session key successfully set
///	@return	UCL_E_NOK 	Session key setting Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_SetSessionKey(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                                  uint8 *pKey, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((pKey != NULL) && (Size == UCLALCRYPTO_KEYSIZE) && (eUclALCryptoKeyType_SK < pInst->pCfg->numKeys))
    {
        Ret = UclALOs_Memcpy(0, (uint8 *)&(pInst->pCfg->pKeyList[eUclALCryptoKeyType_SK].key), pKey, Size);
    }
    else
    {
        LOGE(0, "UclALCryptoOpenSSL_Impl", "UclALCryptoOpenSSL_Impl_IUclALCrypto_SetSessionKey: Failed %d", Ret);
    }

    return Ret;
}
#endif //
///
/// @brief This method implements the CMAC_Start API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param KeyId Key to use for CMAC calculation
///
/// @return UCL_E_OK 	CMAC initialization success
///	@return	UCL_E_NOK 	CMAC initialization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CMAC_Start(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                               EUclALCryptoKeyType KeyId)
{
	Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pInst) && (KeyId < eUclALCryptoKeyType_Last) && (NULL != pInst->pCfg) && (NULL != pInst->pCfg->pKeyList))
    {
        pInst->pCmacCtx = CMAC_CTX_new();
        if (NULL != pInst->pCmacCtx)
        {
            if (1 == CMAC_Init(pInst->pCmacCtx, (uint8 *)&(pInst->pCfg->pKeyList[KeyId].key),
                               UCLALCRYPTO_KEYSIZE, EVP_aes_128_cbc(), NULL))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALCryptoOpenSSL_Impl", "CMAC_Start: Init failed");
                CMAC_CTX_free(pInst->pCmacCtx);
                pInst->pCmacCtx = NULL;
            }
        }
        else
        {
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CMAC_Start: Context allocation failed");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CMAC_Process API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pData Data to perform CMAC calculation
/// @param Size Size of the Data
///
/// @return UCL_E_OK 	CMAC processing success
///	@return	UCL_E_NOK 	CMAC processing Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CMAC_Process(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                                 uint8 *pData, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pInst) && (NULL != pInst->pCmacCtx) && (NULL != pData) && (Size > 0))
    {
        if (1 == CMAC_Update(pInst->pCmacCtx, pData, Size))
        {
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CMAC_Process: Update failed");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CMAC_Done API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pResult Pointer to buffer to copy the result
/// @param pSize [in] Size of the Buffer [out] No of bytes copied
///
/// @return UCL_E_OK 	CMAC finalization success
///	@return	UCL_E_NOK 	CMAC finalization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CMAC_Done(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                              uint8 *pResult, uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    size_t outLen = 0;

    if ((NULL != pInst) && (NULL != pInst->pCmacCtx) && (NULL != pResult) && (NULL != pSize) && (*pSize >= 16))
    {
        if (1 == CMAC_Final(pInst->pCmacCtx, pResult, &outLen))
        {
            *pSize = (uint16)outLen;
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CMAC_Done: Final failed");
            *pSize = 0;
        }

        CMAC_CTX_free(pInst->pCmacCtx);
        pInst->pCmacCtx = NULL;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CBC_Start API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param KeyId Key to use for CBC algorithm
/// @param pIV Initial vector
/// @param Size Size of the initial vector
///
/// @return UCL_E_OK 	CBC initialization success
///	@return	UCL_E_NOK 	CBC initialization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CBC_Start(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                              EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pInst) && (NULL != pIV) && (Size == UCLALCRYPTO_KEYSIZE)) 
	{
        if (pInst->pAesCtx == NULL) 
		{
            pInst->pAesCtx = EVP_CIPHER_CTX_new();
        } 
		else 
		{
            EVP_CIPHER_CTX_reset(pInst->pAesCtx);
        }

        if (NULL != pInst->pAesCtx) 
		{
            if (1 == EVP_EncryptInit_ex(pInst->pAesCtx, EVP_aes_128_cbc(), NULL, (uint8 *)&(pInst->pCfg->pKeyList[KeyId].key), pIV)) 
			{
                Ret = UCL_E_OK;
            } 
			else 
			{
                LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Start: EncryptInit failed");
                EVP_CIPHER_CTX_free(pInst->pAesCtx);
                pInst->pAesCtx = NULL;
            }
        } 
		else 
		{
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Start: Context alloc failed");
        }
    } 
	else 
	{
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CBC_Encrypt API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pClearText Pointer to the buffer that contains the clear text
/// @param pCipherText Pointer to the buffer to copy the encrypted text
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	CBC encryption success
///	@return	UCL_E_NOK 	CBC encryption Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CBC_Encrypt(SUclALCryptoOpenSSLInst *pInst, uint8 InstId,
                                                                uint8 *pClearText, uint8 *pCipherText, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int outLen = 0;
    int finalLen = 0;

    if ((NULL != pInst) && (NULL != pClearText) && (NULL != pCipherText) && (Size > 0))
    {
        if (1 == EVP_EncryptUpdate(pInst->pAesCtx, pCipherText, &outLen, pClearText, Size))
		{
			if (1 == EVP_EncryptFinal_ex(pInst->pAesCtx, pCipherText + outLen, &finalLen))
			{
				Ret = UCL_E_OK;
			}
			else
			{
				LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Encrypt: EncryptFinal failed");
			}
		}
        else
        {
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Encrypt: EncryptUpdate failed");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CBC_Decrypt API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
/// @param pCipherText Pointer to the buffer that contains the encrypted text
/// @param pClearText Pointer to the buffer to copy the clear text
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	CBC decryption success
///	@return	UCL_E_NOK 	CBC decryption Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CBC_Decrypt(SUclALCryptoOpenSSLInst *pInst, uint8 InstId, EUclALCryptoKeyType KeyId, uint8 *pIV,
                                                                uint8 *pCipherText, uint8 *pClearText, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int outLen = 0;
    int finalLen = 0;

    if ((NULL != pInst) && (NULL != pCipherText) && (NULL != pClearText) && (Size > 0)) 
	{
        if (1 == EVP_DecryptInit_ex(pInst->pAesCtx, EVP_aes_128_cbc(), NULL, (uint8 *)&(pInst->pCfg->pKeyList[KeyId].key), pIV)) 
		{
            if (1 == EVP_DecryptUpdate(pInst->pAesCtx, pClearText, &outLen, pCipherText, Size)) 
			{
                if (1 == EVP_DecryptFinal_ex(pInst->pAesCtx, pClearText + outLen, &finalLen)) 
				{
                    Ret = UCL_E_OK;
                } 
				else 
				{
                    LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Decrypt: DecryptFinal failed");
                }
            } 
			else 
			{
                LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Decrypt: DecryptUpdate failed");
            }
        } 
		else 
		{
            LOGE(0, "UclALCryptoOpenSSL_Impl", "CBC_Decrypt: DecryptInit failed");
        }
    } 
	else
	{
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

///
/// @brief This method implements the CBC_Done API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	CBC finalization success
///	@return	UCL_E_NOK 	CBC finalization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CBC_Done(SUclALCryptoOpenSSLInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pInst) && (NULL != pInst->pAesCtx))
    {
        EVP_CIPHER_CTX_free(pInst->pAesCtx);
        pInst->pAesCtx = NULL;
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}
