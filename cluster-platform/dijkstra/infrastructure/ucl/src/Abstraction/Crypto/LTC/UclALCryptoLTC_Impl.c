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
#include "UclALCryptoLTC_Impl.h"
#include "UclALOs.h"
#include "UclALDebug.h"

///
/// @brief This method implements the Initialize API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_Initialize(SUclALCryptoLTCInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    if (-1 == register_cipher(&rijndael_desc))
    {
        LOGE(0, "UclALCryptoLTC_Impl", "%s", "UclALCryptoLTC_Impl_IUclALCrypto_Initialize: Failed");
        Ret = UCL_E_NOK;
        pInst->State = eUclALCryptoState_Uninitialized;
    }
    else
    {
        Ret = UCL_E_OK;
        pInst->State = eUclALCryptoState_Initialized;
    }

    return Ret;
}

///
/// @brief This method implements the Shutdown API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_Shutdown(SUclALCryptoLTCInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if (CRYPT_OK != unregister_cipher(&rijndael_desc))
    {
        Ret = UCL_E_NOK;
    }

    return Ret;
}

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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_Random(SUclALCryptoLTCInst *pInst, uint8 InstId, uint8 *pResult,
                                                       uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    sint32 Status;
    uint64 EntropyVal;

    if (pResult != NULL)
    {
        Status = rc4_start(&pInst->LTCprng_state);
        if (CRYPT_OK == Status)
        {
            EntropyVal = UclALOs_GetSystemTimeMs(0);
            Status = rc4_add_entropy((uint8 *)&EntropyVal, 8, &pInst->LTCprng_state);
        }
        if (CRYPT_OK == Status)
        {
            Status = rc4_ready(&pInst->LTCprng_state);
        }
        if (CRYPT_OK == Status)
        {
            if (Size == rc4_read(pResult, Size, &pInst->LTCprng_state))
            {
                (void)rc4_done(&pInst->LTCprng_state);
                Ret = UCL_E_OK;
            }
        }
    }

    return Ret;
}

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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_SetSessionKey(SUclALCryptoLTCInst *pInst, uint8 InstId, uint8 *pKey,
                                                              uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((pKey != NULL) && (Size == UCLALCRYPTO_KEYSIZE) && (eUclALCryptoKeyType_SK < pInst->pCfg->numKeys))
    {
        Ret = UclALOs_Memcpy(0, (uint8 *)&(pInst->pCfg->pKeyList[eUclALCryptoKeyType_SK].key), pKey, Size);
    }
    else
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_SetSessionKey: Failed %d", Ret);
    }

    return Ret;
}

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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Start(SUclALCryptoLTCInst *pInst, uint8 InstId,
                                                           EUclALCryptoKeyType KeyId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Idx, Status;

    if (eUclALCryptoKeyType_Last <= KeyId)
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (eUclALCryptoState_Initialized != pInst->State)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Idx = find_cipher("rijndael");

        if (-1 == Idx)
        {
            Ret = UCL_E_NOK;
        }
        else
        {
            Status = omac_init(&pInst->LTCOmacState, Idx, (uint8 *)&(pInst->pCfg->pKeyList[KeyId].key),
                               UCLALCRYPTO_KEYSIZE);

            if (CRYPT_OK == Status)
            {
                Ret = UCL_E_OK;
            }
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Start: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Process(SUclALCryptoLTCInst *pInst, uint8 InstId, uint8 *pData,
                                                             uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Status;

    if ((NULL == pData) || (0 == Size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (pInst->State != eUclALCryptoState_Initialized)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Status = omac_process(&pInst->LTCOmacState, pData, Size);

        if (CRYPT_OK == Status)
        {
            Ret = UCL_E_OK;
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Process: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Done(SUclALCryptoLTCInst *pInst, uint8 InstId, uint8 *pResult,
                                                          uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Status;
    uint32 Size;

    if ((NULL == pResult) || (NULL == pSize) || (0 == *pSize))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (pInst->State != eUclALCryptoState_Initialized)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Size = *pSize;
        Status = omac_done(&pInst->LTCOmacState, pResult, (unsigned long *)&Size);
        if (CRYPT_OK == Status)
        {
            Ret = UCL_E_OK;
            *pSize = Size;
        }
        else
        {
            *pSize = 0;
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CMAC_Done: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CBC_Start(SUclALCryptoLTCInst *pInst, uint8 InstId,
                                                          EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Idx, Status;

    if ((eUclALCryptoKeyType_Last <= KeyId) || (NULL == pIV) || (Size != UCLALCRYPTO_KEYSIZE))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (eUclALCryptoState_Initialized != pInst->State)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Idx = find_cipher("rijndael");

        if (-1 == Idx)
        {
            Ret = UCL_E_NOK;
        }
        else
        {
            Status = cbc_start(Idx, pIV, (uint8 *)&(pInst->pCfg->pKeyList[KeyId].key), UCLALCRYPTO_KEYSIZE, 0,
                               &pInst->LTCCbc);

            if (CRYPT_OK == Status)
            {
                Ret = UCL_E_OK;
            }
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CBC_Start: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CBC_Encrypt(SUclALCryptoLTCInst *pInst, uint8 InstId, uint8 *pClearText,
                                                            uint8 *pCipherText, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Status;

    if ((NULL == pCipherText) || (NULL == pClearText) || (0 == Size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (eUclALCryptoState_Initialized != pInst->State)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Status = cbc_encrypt(pClearText, pCipherText, Size, &pInst->LTCCbc);
        if (CRYPT_OK == Status)
        {
            Ret = UCL_E_OK;
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CBC_Encrypt: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CBC_Decrypt(SUclALCryptoLTCInst *pInst, uint8 InstId,
                                                            uint8 *pCipherText, uint8 *pClearText, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Status;

    if ((NULL == pCipherText) || (NULL == pClearText) || (0 == Size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (eUclALCryptoState_Initialized != pInst->State)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Status = cbc_decrypt(pCipherText, pClearText, Size, &pInst->LTCCbc);

        if (CRYPT_OK == Status)
        {
            Ret = UCL_E_OK;
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CBC_Decrypt: Failed %d", Ret);
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
Ucl_ReturnType UclALCryptoLTC_Impl_IUclALCrypto_CBC_Done(SUclALCryptoLTCInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint8 Status;

    if (eUclALCryptoState_Initialized != pInst->State)
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else
    {
        Status = cbc_done(&pInst->LTCCbc);

        if (CRYPT_OK == Status)
        {
            Ret = UCL_E_OK;
        }
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALCryptoLTC_Impl", "UclALCryptoLTC_Impl_IUclALCrypto_CBC_Done: Failed %d", Ret);
    }

    return Ret;
}
