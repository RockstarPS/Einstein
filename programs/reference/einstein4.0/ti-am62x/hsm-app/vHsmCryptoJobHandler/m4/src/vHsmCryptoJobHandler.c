/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
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
 * \file vHsmCryptoJobHandler.c
 *
 * \brief
 * Visteon HSM Crypto Manager for Crypto Application support in M0P.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Jul/'24 | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "string.h"
#include "vHsmCryptoManager.h"
#include "vHsmCrypt.h"
#include "vHsmIpcHostManager.h"
#include "vHsmShutdownMgr.h"
#include "vHsmKeyStore.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

#define UNUSED_PARAM     (void)
#define ADDITIONAL_CRYPTO_SUPPORT 0
/* As per the design this is fixed to be 8 bytes (16 in case of --no-short-enum)
 * [no_short enum => 4bytes for each enum]
 * [short enum => 1 byte for each enum])*/
#ifdef NO_SHORT_ENUM
#define CRYPTO_HEADER_SIZE           16
#else /* SHORT_ENUM */
#define CRYPTO_HEADER_SIZE           8
#endif /* NO_SHORT_ENUM */

/* Each buffer size of one IPC buffer in SRAM is */
#define CRYPTO_MAX_PAYLOAD_DATA_SIZE                (IPC_MAX_PAYLOAD_DATA_SIZE - CRYPTO_HEADER_SIZE )

#define VHSM_CRYPTO_MAC_VERIFY_PAYLOADSIZE       5
#define VHSM_CRYPTO_CMAC_GEN_LENGTH              16
#define VHSM_CRYPTO_CMAC_VER_BITLENGTH           128
#define VHSM_CRYPTO_CMAC_MAX_VER_LENGTH          16
#define VHSM_CRYPTO_64_OCTETS_BITLENGTH          512U

#define VHSM_CRYPTO_AES_GCM_AADSIZE              0u
#define VHSM_CRYPTO_AES_GCM_VERRESULTSIZE        4u
#define VHSM_CRYPTO_AES_GCM_MACSIZE              16u
#define VHSM_CRYPTO_AES_GCM_TOTALPAYLOADSIZE     (CRYPTO_MAX_PAYLOAD_DATA_SIZE + VHSM_CRYPTO_AES_GCM_MACSIZE)

#define VHSM_CRYPTO_HMAC_SHA256_KEYSIZE          32
#define VHSM_CRYPTO_HMAC_SHA256_MACSIZE          32

#define HASH_ADDRESS_BYTES                    ((uint32)4)

#define HASH_LENGTH                           ((uint32)4)
#define HASH_CALC_LEN                         ((uint32)32)
#define KEY_CMAC_BIT_SET                      ((uint8)0x80)
#define MAX_KEY_VALUE                         ((uint8)0xF)
#define SIPHASH_MAX_DATA_SIZE                 CRYPTO_MAX_PAYLOAD_DATA_SIZE 
#define SIPHASH_MAX_MAC_SIZE                  ((uint32)8)

#define ED25519VER_MAX_SIZE                   ((uint16)96)
#define JTAGCHECK_MAX_SIZE                    ((uint16)17)
#define JTAGLOCK_MAX_SIZE                     ((uint16)16)
#define INDEX 32
#define AES_BLOCK_SIZE 16
#define VHSM_CRYPTO_AES_CBC_IV_SIZE           ((uint32)16)
LOCAL uint8 l_vHsmCryptoJobKey_U8A[AES_BLOCK_SIZE] = {0};
//LOCAL uint8 pad_len = 0;
LOCAL uint8 l_vHsmCryptoJobKeyCbcEncrypt_U8A[INDEX] = {0};
LOCAL uint8 l_data_pU8[CRYPTO_MAX_PAYLOAD_DATA_SIZE] = {0};
LOCAL uint8 l_aesCbcCipherData_pU8[CRYPTO_MAX_PAYLOAD_DATA_SIZE] = {0};
LOCAL uint32 l_aesCbcIvSize_U16 = 0;
LOCAL uint32 l_dataSize_U32 = 0;
LOCAL uint8 l_vHsmCryptoCbcEncIvBuff_U8A[AES_BLOCK_SIZE]={0};
LOCAL uint8 l_vHsmCryptoBuff_1_U8A[VHSM_CRYPTO_64_OCTETS_BITLENGTH] = {0};
LOCAL uint32 l_aesCbcCipherDataSize_U32 = 0;
LOCAL uint8 l_aesCbcIV_pU8[16] = {0};
LOCAL uint8 l_decKey_pU8[16] = {0};
LOCAL HsmCrpt_AesCmacKeyDataType l_aesCmacMacDerKey_s = {0};
LOCAL uint8 l_aesCmacData_pU8[VHSM_CRYPTO_CMAC_GEN_LENGTH + 1] = {0};
LOCAL uint8 l_aesCmacVerResult_U8A[VHSM_CRYPTO_MAC_VERIFY_PAYLOADSIZE] = { 0 };
LOCAL HsmCrpt_AesCmacKeyDataType l_aesCmacMacVerDerKey_s = {0};
LOCAL uint8 l_vHsmMacVerKeyId_U8 = 0;
LOCAL uint8 l_vHsmCryptoGetKey[48] = {0};
// LOCAL uint8 share_pad = 0;


/******************************************************************************
 * Static type declarations
 *****************************************************************************/
LOCAL uint8 l_vHsmCryptoHashFinal[36];
LOCAL uint8 l_randomdata_AU8[33] = {0};

/*****************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn Crypto_Dummy_Function
 **
 ** Dummy function for the unused Crypto jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 *****************************************************************************/
FUNC (void, CRY_CODE) Crypto_Dummy_Function(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
	UNUSED_PARAM keyId;
	UNUSED_PARAM cryptodata_addr;
	UNUSED_PARAM payload_size;

}

/**
 ******************************************************************************
 ** \fn vHsm_RandomGenerate
 **
 ** Function for the Random Generate Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_RandomGenerate(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
	UNUSED_PARAM keyId;
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    if(payload_size > 0u)
    {
        /* Get the data from Trng */
        if (payload_size <= (uint32)NUMBER_OF_RANDOM_GEN_BYTES)
        {
#if (VHSMCRYPT_TRNG_ENABLED == STD_OFF)
            l_RetVal_E = E_NOT_OK;
#else
            l_RetVal_E = vHsmCrypt_TrngRead(&l_randomdata_AU8[1], (uint8)NUMBER_OF_RANDOM_GEN_BYTES);
#endif
        
            if(E_NOT_OK == l_RetVal_E)
            {
                l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
                l_cryptodatasend.jobId_E = CID_30_RANDOM_CB;
                l_cryptodatasend.KeyId_U8 = 0u;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
                l_cryptodatasend.payLoadSize = 1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if(E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */

                    }
                else
                {
                    /* Data sent through IPC */
                }
            }
            else
            {
                l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_DONE;
                l_cryptodatasend.jobId_E = CID_30_RANDOM_CB;
                l_cryptodatasend.KeyId_U8 = 0u;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
                l_cryptodatasend.payLoadSize = payload_size +(uint16)1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if(E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */

                    }
                else
                {
                    /* Data sent through IPC */
                }
            }
        }
        /* If payload size sent is wrong */
        else
        {
            l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
            l_cryptodatasend.jobId_E = CID_30_RANDOM_CB;
            l_cryptodatasend.KeyId_U8 = 0u;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
            l_cryptodatasend.payLoadSize = 1;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if(E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */
            }
            else
            {
                /* Data sent through IPC */
            }
        }
    }
}

/**
 ******************************************************************************
 ** \fn vHsm_HashCalcFinish
 **
 ** Function for direct Hash Calc  Crypto jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_HashCalc(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    UNUSED_PARAM keyId;
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    uint8 i = 0;
    TRACE_info_arg_hsm("\r\n Payload Size",payload_size);
    TRACE_info("\r\n Hash Input:");
    for(i=0;i<payload_size;i++)
    {
        TRACE_info_arg_hsm(" ",cryptodata_addr[i]);
    }
    l_RetVal_E = vHsmCrypt_Sha2_256(cryptodata_addr, payload_size, &l_vHsmCryptoHashFinal[1], 32);
    if (E_NOT_OK == l_RetVal_E)
    {
        l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_cryptodatasend.jobId_E = CID_13_HASH_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
        l_cryptodatasend.payLoadSize = 1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

        }
        else
        {
            /* Data sent through IPC */
        }
    }
    else
    {
        l_vHsmCryptoHashFinal[0] = (uint8)CRYPTO_JOB_DONE;
        l_cryptodatasend.jobId_E = CID_13_HASH_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_vHsmCryptoHashFinal[0];
        l_cryptodatasend.payLoadSize = (uint16)32 + (uint16)1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

        }
        else
        {
            /* Data sent through IPC */
        }
    }
    TRACE_info("\r\n Crypto JOb done");
}
/**
 ******************************************************************************
 ** \fn vHsm_KeySet
 **
 ** Function for the Setting Key
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_KeySet(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    uint8 l_randomdata_AU8[2] = {0};
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
#ifndef HSM_RECOVERY
    l_RetVal_E =  vHsmKeyStore_SetKey(keyId,cryptodata_addr,payload_size);
#else
    UNUSED_PARAM keyId;
    UNUSED_PARAM cryptodata_addr;
    UNUSED_PARAM payload_size;
#endif
    if(E_NOT_OK == l_RetVal_E)
    {
        l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_cryptodatasend.jobId_E = CID_68_KEYSTORE_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
        l_cryptodatasend.payLoadSize = 1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

            }
        else
        {
            /* Data sent through IPC */
        }
    }
    else
    {
        l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_DONE;
        l_cryptodatasend.jobId_E = CID_68_KEYSTORE_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
        l_cryptodatasend.payLoadSize = (uint16)1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

            }
        else
        {
            /* Data sent through IPC */
        }
    }
}

FUNC (void, CRY_CODE) vHsm_KeyGet(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    UNUSED_PARAM payload_size;
    uint8 l_randomdata_AU8[2] = {0};
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    uint16 keySize = 0;
#ifndef HSM_RECOVERY
    uint8 keyelementID = *cryptodata_addr;
    l_RetVal_E =  vHsmKeyStore_GetKey(keyId,keyelementID,&l_vHsmCryptoGetKey[2],&keySize);
#else
    UNUSED_PARAM keyId;
#endif
    if(E_NOT_OK == l_RetVal_E)
    {
        l_randomdata_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_cryptodatasend.jobId_E = CID_68_KEYSTORE_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_randomdata_AU8[0];
        l_cryptodatasend.payLoadSize = 1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

            }
        else
        {
            /* Data sent through IPC */
        }
    }
    else
    {
        l_vHsmCryptoGetKey[0] = (uint8)CRYPTO_JOB_DONE;
        l_vHsmCryptoGetKey[1] = l_RetVal_E;
        l_cryptodatasend.jobId_E = CID_68_KEYSTORE_CB;
        l_cryptodatasend.KeyId_U8 = 0u;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_vHsmCryptoGetKey[0];
        l_cryptodatasend.payLoadSize = (uint16)2+(uint16)keySize;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if(E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */

            }
        else
        {
            /* Data sent through IPC */
        }
    }
}

/**
 ******************************************************************************
 ** \fn vHsm_AesEcbEncrypt
 **
 ** Function for the Encrypt Crypto Job single call
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_AesEcbEncrypt(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    uint16 l_keysize_U16 = 0;
    l_RetVal_E = vHsmKeyStore_GetKey(keyId,0u,&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0],&l_keysize_U16);
    if(E_OK == l_RetVal_E)
    {
        l_dataSize_U32 = payload_size;
        l_RetVal_E = vHsmCrypt_AesEcbEncrypt(&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0],(uint8)l_keysize_U16,cryptodata_addr,payload_size, &l_data_pU8[1],&l_dataSize_U32);
    }
    if (E_NOT_OK == l_RetVal_E)
    {
        l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_cryptodatasend.jobId_E = CID_46_SYM_BLOCK_ENCRYPT_CB;
        l_cryptodatasend.KeyId_U8 = keyId;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
        l_cryptodatasend.payLoadSize = 1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if (E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */
        }
        else
        {
            /* Data sent through IPC */
        }
    }
    else
    {
        if(l_dataSize_U32 < (uint16)CRYPTO_MAX_PAYLOAD_DATA_SIZE)
        {
            l_data_pU8[0] = (uint8)CRYPTO_JOB_DONE;
            l_cryptodatasend.jobId_E = CID_46_SYM_BLOCK_ENCRYPT_CB;
            l_cryptodatasend.KeyId_U8 = keyId;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_data_pU8[0];
            l_cryptodatasend.payLoadSize = l_dataSize_U32 + (uint16)1;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if(E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */

                }
            else
            {
                /* Data sent through IPC */
            }
        }
    }
    (void)memset(&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0], 0, sizeof(l_vHsmCryptoJobKeyCbcEncrypt_U8A));
}

/**
 ******************************************************************************
 ** \fn vHsm_AesEcbDecrypt
 **
 ** Function for the Encrypt Crypto Job single call
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_AesEcbDecrypt(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    uint16 l_keysize_U16 = 0;
    l_RetVal_E = vHsmKeyStore_GetKey(keyId,0u,&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0],&l_keysize_U16);
    if(E_OK == l_RetVal_E)
    {
        l_RetVal_E = vHsmCrypt_AesEcbDecrypt(&l_vHsmCryptoJobKey_U8A[0],(uint8)l_keysize_U16,cryptodata_addr, payload_size, &l_data_pU8[1], &l_dataSize_U32);
    }
    if (E_NOT_OK == l_RetVal_E)
    {
        l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_cryptodatasend.jobId_E = CID_41_SYM_BLOCK_DECRYPT_CB;
        l_cryptodatasend.KeyId_U8 = keyId;
        l_cryptodatasend.priority_U8 = e_priorityunused;
        l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
        l_cryptodatasend.payLoadSize = 1;
        l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        if (E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */
        }
        else
        {
            /* Data sent through IPC */
        }
    }
    else
    {
        if(l_dataSize_U32 < (uint16)CRYPTO_MAX_PAYLOAD_DATA_SIZE)
        {
            l_data_pU8[0] = (uint8)CRYPTO_JOB_DONE;
            l_cryptodatasend.jobId_E = CID_41_SYM_BLOCK_DECRYPT_CB;
            l_cryptodatasend.KeyId_U8 = keyId;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_data_pU8[0];
            l_cryptodatasend.payLoadSize = l_dataSize_U32 + (uint16)1;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if(E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */

                }
            else
            {
                /* Data sent through IPC */
            }
        }
    }
    (void)memset(&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0], 0, sizeof(l_vHsmCryptoJobKeyCbcEncrypt_U8A));
}

/**
 ******************************************************************************
 ** \fn vHsm_AesCbcEncrypt
 **
 ** Function for the Encrypt Crypto Job single call
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_AesCbcEncrypt(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    //uint8 l_keyId_U8 = keyId;
    uint8 l_padding_U8 = 0;



    (void)memcpy((uint8 *)&l_aesCbcIvSize_U16, &cryptodata_addr[payload_size-9], 4);
    (void)memcpy((uint8 *)&l_dataSize_U32, &cryptodata_addr[payload_size-5], 4);
    (void)memcpy((uint8 *)&l_padding_U8, &cryptodata_addr[payload_size-1], 1);
    (void)memcpy(&l_vHsmCryptoCbcEncIvBuff_U8A[0],&cryptodata_addr[0],l_aesCbcIvSize_U16);
    if(l_aesCbcIvSize_U16 <= payload_size)
    {
         (void)memcpy(&l_vHsmCryptoBuff_1_U8A[0],&cryptodata_addr[l_aesCbcIvSize_U16], l_dataSize_U32);
    }

    // if((sizeof(l_vHsmCryptoBuff_1_U8A) > payload_size ))
    // {
    //     if(l_keyId_U8 < MAX_KEY_VALUE)
    //     {
            /* Key data:should be obtained from Keymanager */
            // l_RetVal_E = vHsmKeyMan_GetKey(keyId, &l_vHsmCryptoJobKey_U8A[0]);
            // if (E_OK == l_RetVal_E)
            // {
            //     l_RetVal_E = vHsmKeyMan_GetKey(20, &l_vHsmCryptoCbcEncIvBuff_U8A[0]);
            // }
            //&l_vHsmCryptoJobKey_U8A[0] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10};

            // &l_vHsmCryptoCbcEncIvBuff_U8A[0] = {0x00,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10};
//         }
//         if (E_OK == l_RetVal_E)
//         {
//             if((l_dataSize_U32 % AES_BLOCK_SIZE) != 0)
//             {
//                 pad_len = AES_BLOCK_SIZE - (l_dataSize_U32 % AES_BLOCK_SIZE);
//                 (void)memset(&l_vHsmCryptoBuff_1_U8A[l_dataSize_U32],pad_len,pad_len);
//                 l_dataSize_U32+=pad_len;
//                 // share_pad = pad_len;
//             }
// #if (VHSMCRYPT_AES_CBC_ENABLED == STD_ON)
            l_RetVal_E = vHsmCrypt_AesCbcEncrypt(&l_vHsmCryptoJobKey_U8A[0] , HSMCRPT_AES_AES128_KEYSIZE_BYTE, &l_vHsmCryptoCbcEncIvBuff_U8A[0], (HsmCrpt_AesKeySizeType)l_aesCbcIvSize_U16,
            &l_vHsmCryptoBuff_1_U8A[0], l_dataSize_U32, &l_data_pU8[1], &l_dataSize_U32);
            if (E_NOT_OK == l_RetVal_E)
            {
                l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
                l_cryptodatasend.jobId_E = CID_56_SYM_ENCRYPT_CB;
                l_cryptodatasend.KeyId_U8 = keyId;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
                l_cryptodatasend.payLoadSize = 1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if (E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */
                }
                else
                {
                    /* Data sent through IPC */
                }
            }
            else
            {
                if(l_dataSize_U32 < (uint16)CRYPTO_MAX_PAYLOAD_DATA_SIZE)
                {
                    l_data_pU8[0] = (uint8)CRYPTO_JOB_DONE;
                    l_cryptodatasend.jobId_E = CID_56_SYM_ENCRYPT_CB;
                    l_cryptodatasend.KeyId_U8 = keyId;
                    l_cryptodatasend.priority_U8 = e_priorityunused;
                    l_cryptodatasend.payLoadPtr_U8P = &l_data_pU8[0];
                    l_cryptodatasend.payLoadSize = l_dataSize_U32 + (uint16)1;
                    l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                    if(E_NOT_OK == l_RetVal_Ipc_E)
                    {
                        /* Message not sent through IPC */

                        }
                    else
                    {
                        /* Data sent through IPC */
                    }
                }
            }
         (void)memset(&l_vHsmCryptoJobKeyCbcEncrypt_U8A[0], 0, sizeof(l_vHsmCryptoJobKeyCbcEncrypt_U8A));
// #endif
//         }
//         else
//         {
//             l_data_AU8[0] = (uint8)CRYPTO_JOB_KEY_NOT_THERE;
//             l_cryptodatasend.jobId_E = CID_56_SYM_ENCRYPT_CB;
//             l_cryptodatasend.KeyId_U8 = keyId;
//             l_cryptodatasend.priority_U8 = e_priorityunused;
//             l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
//             l_cryptodatasend.payLoadSize = 1;
//             l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
//             if (E_NOT_OK == l_RetVal_Ipc_E)
//             {
//                 /* Message not sent through IPC */
//             }
//         }

//     }
//     l_dataSize_U32 = 0;
    // pad_len = 0;

}

/**
 ******************************************************************************
 ** \fn vHsm_AesCbcDecrypt
 **
 ** Function for the Decrypt single call Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_AesCbcDecrypt(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    //uint8 l_keyId_U8 = keyId;
    uint32 l_cipherlength;
//     if(payload_size > 8u)
//     {
        (void)memcpy((uint8 *)&l_aesCbcCipherDataSize_U32, &cryptodata_addr[payload_size-4u],4);
        (void)memcpy((uint8 *)&l_cipherlength, &cryptodata_addr[payload_size-8u], 4);
        (void)memcpy(&l_aesCbcIV_pU8[0],&cryptodata_addr[0],VHSM_CRYPTO_AES_CBC_IV_SIZE);
        (void)memcpy(&l_aesCbcCipherData_pU8[0], &cryptodata_addr[VHSM_CRYPTO_AES_CBC_IV_SIZE], l_cipherlength);
//     }   

//     if(l_keyId_U8 < MAX_KEY_VALUE)
//     {
//         /* Key data:should be obtained from Keymanager */
//         l_RetVal_E = vHsmKeyMan_GetKey(keyId, &l_vHsmCryptoJobKey_U8A[0]);
//         if (E_OK == l_RetVal_E)
//         {
//             l_RetVal_E = vHsmKeyMan_GetKey(20,&l_aesCbcIV_pU8[0]);
//         }
//     }
//     if(E_OK == l_RetVal_E)
//     {
// #if (VHSMCRYPT_AES_CBC_ENABLED == STD_ON)
        // l_RetVal_E = vHsmCrypt_AesCalcDecrKey(&l_vHsmCryptoJobKey_U8A[0],HSMCRPT_AES_AES128_KEYSIZE_BYTE,&l_decKey_pU8[0]);
        // if(l_RetVal_E == E_OK)
        // {
            l_RetVal_E = vHsmCrypt_AesCbcDecrypt(&l_decKey_pU8[0],HSMCRPT_AES_AES128_KEYSIZE_BYTE, 
                                                l_aesCbcIV_pU8, (HsmCrpt_AesKeySizeType) VHSM_CRYPTO_AES_CBC_IV_SIZE,
                                                l_aesCbcCipherData_pU8 , l_aesCbcCipherDataSize_U32, &l_data_pU8[1], &l_aesCbcCipherDataSize_U32);
        // }
// #endif
        if(E_NOT_OK == l_RetVal_E)
        {

            l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
            l_cryptodatasend.jobId_E = CID_51_SYM_DECRYPT_CB;
            l_cryptodatasend.KeyId_U8 = keyId;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
            l_cryptodatasend.payLoadSize = 1;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if(E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */
    
                }
            else
            {
                /* Data sent through IPC */
            }
        }
//         else
//         {
            else if(l_aesCbcCipherDataSize_U32 < (uint32)CRYPTO_MAX_PAYLOAD_DATA_SIZE)
            {
                // if(share_pad != 0)
                // {
                //     (void)memset(&l_data_pU8[l_aesCbcCipherDataSize_U32-share_pad+1],0,share_pad);
                // }
                l_data_pU8[0] = (uint8)CRYPTO_JOB_DONE;
                l_cryptodatasend.jobId_E = CID_51_SYM_DECRYPT_CB;
                l_cryptodatasend.KeyId_U8 = keyId;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_data_pU8[0];
                l_cryptodatasend.payLoadSize = (uint16)l_aesCbcCipherDataSize_U32 + (uint16)1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if(E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */

                    }
                else
                {
                    /* Data sent through IPC */
                }
            }
    //         }
    //         else
    //         {
    //             l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
    //             l_cryptodatasend.jobId_E = CID_51_SYM_DECRYPT_CB;
    //             l_cryptodatasend.KeyId_U8 = keyId;
    //             l_cryptodatasend.priority_U8 = e_priorityunused;
    //             l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
    //             l_cryptodatasend.payLoadSize = 1;
    //             l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
    //             if(E_NOT_OK == l_RetVal_Ipc_E)
    //             {
    //                 /* Message not sent through IPC */

    //             }
    //             else
    //             {
    //                 /* Data sent through IPC */
    //             }
    //         }
    //     }
    // }
    // else
    // {
    //     l_data_AU8[0] = (uint8)CRYPTO_JOB_KEY_NOT_THERE;
    //     l_cryptodatasend.jobId_E = CID_51_SYM_DECRYPT_CB;
    //     l_cryptodatasend.KeyId_U8 = 0u;
    //     l_cryptodatasend.priority_U8 = e_priorityunused;
    //     l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
    //     l_cryptodatasend.payLoadSize = 1;
    //     l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
    //     if(E_NOT_OK == l_RetVal_Ipc_E)
    //     {
    //         /* Message not sent through IPC */

    //     }
    // }
    (void)memset(&l_vHsmCryptoJobKey_U8A[0], 0, sizeof(l_vHsmCryptoJobKey_U8A));
    (void)memset(&l_decKey_pU8[0], 0, sizeof(l_decKey_pU8));
    // l_aesCbcCipherDataSize_U32 = 0;
    // share_pad = 0;
}

/**
 ******************************************************************************
 ** \fn vHsm_MacGenerate
 **
 ** Function for direct Mac Generation in Crypto jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_MacGenerate(uint8 keyId, uint8* const cryptodata_addr,uint16 payload_size)
{
    //l_vHsmMacGenKeyId_U8 = keyId;
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    // if (sizeof(l_vHsmCryptoBuff_1_U8A) > payload_size)
    // {
        l_dataSize_U32 = payload_size;
// #if (VHSMCRYPT_AES_CMAC_ENABLED == STD_ON)
        (void)memcpy(&l_vHsmCryptoBuff_1_U8A[0],cryptodata_addr, l_dataSize_U32);

        // if(l_vHsmMacGenKeyId_U8 < MAX_KEY_VALUE)
        // {
            /* Key data:should be obtained from Keymanager */
            //l_RetVal_E = vHsmKeyMan_GetKey(keyId, &l_vHsmCryptoJobKey_U8A[0]);
            /*l_RetVal_E = vHsmKeyMan_GetKey((KEY_CMAC_BIT_SET | l_vHsmMacGenKeyId_U8), &l_vHsmCryptoJobKey_U8A[0]);*/
            //l_RetVal_E = vHsmKeyMan_GetED25519Key(l_vHsmMacGenKeyId_U8, &l_vHsmCryptoJobKey_U8A[0]);
            //l_RetVal_E = E_OK;
        // }
        // if (E_NOT_OK == l_RetVal_E)
        // {
        //     l_data_AU8[0] = (uint8)CRYPTO_JOB_KEY_NOT_THERE;
        //     l_cryptodatasend.jobId_E = CID_19_MAC_GEN_CB;
        //     l_cryptodatasend.KeyId_U8 = keyId;
        //     l_cryptodatasend.priority_U8 = e_priorityunused;
        //     l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
        //     l_cryptodatasend.payLoadSize = 1;
        //     l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
        //     if(E_NOT_OK == l_RetVal_Ipc_E)
        //     {
        //         /* Message not sent through IPC */

        //     }
        // }
        // else
        // {

        l_RetVal_E = vHsmCrypt_AesCmacGenerate(&l_vHsmCryptoJobKey_U8A[0], HSMCRPT_AES_AES128_KEYSIZE_BYTE, &l_vHsmCryptoBuff_1_U8A[0], (uint32) l_dataSize_U32, &l_aesCmacData_pU8[1],  (uint32)VHSM_CRYPTO_CMAC_GEN_LENGTH);
            // l_RetVal_E = vHsmCrypt_AesCmacCalcSubKeys(&l_vHsmCryptoJobKey_U8A[0],HSMCRPT_AES_AES128_KEYSIZE_BYTE,&l_aesCmacMacDerKey_s);
            // if(E_OK == l_RetVal_E)
            // {
            //     l_RetVal_E = vHsmCrypt_AesCmacCommonStart(&l_aesCmacMacDerKey_s);
            //     if(E_OK == l_RetVal_E)
            //     {
            //         l_RetVal_E = vHsmCrypt_AesCmacCommonUpdate(&l_vHsmCryptoBuff_1_U8A[0], (uint32) l_dataSize_U32);
            //         if(E_OK == l_RetVal_E)
            //         {
            //             l_RetVal_E = vHsmCrypt_AesCmacGenerateFinish(&l_aesCmacData_pU8[1] , (uint32)VHSM_CRYPTO_CMAC_GEN_LENGTH);
            //         }
            //     }
            // }


            // l_RetVal_E = vHsmCrypt_AesCmacGenerate(&l_aesCmacMacDerKey_s, &l_vHsmCryptoBuff_1_U8A[0],
            //               l_dataSize_U32, &l_aesCmacData_pU8[1],
            //               (uint32)VHSM_CRYPTO_CMAC_GEN_LENGTH);
            if (E_NOT_OK == l_RetVal_E)
            {
                l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
                l_cryptodatasend.jobId_E = CID_19_MAC_GEN_CB;
                l_cryptodatasend.KeyId_U8 = keyId;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
                l_cryptodatasend.payLoadSize = 1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if (E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */
                }
                else
                {
                    /* Data sent through IPC */
                }
            }
            else
            {
                l_aesCmacData_pU8[0] = (uint8)CRYPTO_JOB_DONE;
                l_cryptodatasend.jobId_E = CID_19_MAC_GEN_CB;
                l_cryptodatasend.KeyId_U8 = keyId;
                l_cryptodatasend.priority_U8 = e_priorityunused;
                l_cryptodatasend.payLoadPtr_U8P = &l_aesCmacData_pU8[0];
                l_cryptodatasend.payLoadSize = (uint16)VHSM_CRYPTO_CMAC_GEN_LENGTH + (uint16)1;
                l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
                if (E_NOT_OK == l_RetVal_Ipc_E)
                {
                    /* Message not sent through IPC */
                }
                else
                {
                    /* Data sent through IPC */
                }
            }
        //}
        (void)memset(&l_vHsmCryptoJobKey_U8A[0], 0, sizeof(l_vHsmCryptoJobKey_U8A));
        (void)memset(&l_aesCmacMacDerKey_s, 0, sizeof(l_aesCmacMacDerKey_s));
// #endif /*VHSMCRYPT_AES_CMAC_ENABLED*/
//     }

     l_dataSize_U32 = 0;
}

/**
 ******************************************************************************
 ** \fn vHsm_MacVerify
 **
 ** Function for CMAC verify Crypto jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC(void, CRY_CODE) vHsm_MacVerify(uint8 keyId, uint8 *const cryptodata_addr, uint16 payload_size)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Cryptodata l_cryptodatasend = {0};
    uint32 l_cryptoMacVerifyresult_U32 = 0;
    uint8 l_loopcount_U8 = 0;
    uint8 *l_cryptMacpointer = (uint8 *)&l_cryptoMacVerifyresult_U32;
    uint32 verifylength = 0u;
    uint8 l_vHsmCryptoBuff_2_U8A[VHSM_CRYPTO_64_OCTETS_BITLENGTH] = {0};
    uint32 l_MacdataSize_U32 = 0;

    l_vHsmMacVerKeyId_U8 = keyId;
    (void)memcpy((uint8 *)&l_MacdataSize_U32, &cryptodata_addr[payload_size-8u], 4);
    (void)memcpy((uint8 *)&verifylength, &cryptodata_addr[payload_size-4u], 4);
    (void)memcpy(&l_vHsmCryptoBuff_1_U8A[0],&cryptodata_addr[0],l_MacdataSize_U32);

    // if(l_MacdataSize_U32 <= (uint32)payload_size)
    // {
        (void)memcpy(&l_vHsmCryptoBuff_2_U8A[0],&cryptodata_addr[l_MacdataSize_U32], verifylength);
        l_RetVal_E = E_OK;
    // }

    if(((uint8)E_OK == l_RetVal_E) && (l_vHsmMacVerKeyId_U8 < MAX_KEY_VALUE))
    {
        l_RetVal_E = E_OK;
    //     /* Key data:should be obtained from Keymanager */
    //     l_RetVal_E = vHsmKeyMan_GetKey((KEY_CMAC_BIT_SET | l_vHsmMacVerKeyId_U8), &l_vHsmCryptoJobKey_U8A[0]);
    }
    // if (E_OK == l_RetVal_E)
    // {
// #if (VHSMCRYPT_AES_CMAC_ENABLED == STD_ON)
        // l_RetVal_E = vHsmCrypt_AesCmacCalcSubKeys(&l_vHsmCryptoJobKey_U8A[0], HSMCRPT_AES_AES128_KEYSIZE_BYTE, &l_aesCmacMacVerDerKey_s);
        // if (E_NOT_OK != l_RetVal_E)
        // {
            l_RetVal_E = vHsmCrypt_AesCmacVerify(&l_vHsmCryptoJobKey_U8A[0], HSMCRPT_AES_AES128_KEYSIZE_BYTE, &l_vHsmCryptoBuff_1_U8A[0], (uint32)l_MacdataSize_U32,l_vHsmCryptoBuff_2_U8A,(uint8)verifylength, &l_cryptoMacVerifyresult_U32);
        // }
        if (E_OK != l_RetVal_E)
        {
            l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
            l_cryptodatasend.jobId_E = CID_24_MAC_VER_CB;
            l_cryptodatasend.KeyId_U8 = 0u;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
            l_cryptodatasend.payLoadSize = (uint16)1;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if (E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */
            }
            else
            {
                /* Data sent through IPC */
            }
        }
        else
        {
            l_aesCmacVerResult_U8A[0] = (uint8)CRYPTO_JOB_DONE;
            for (l_loopcount_U8 = 1; l_loopcount_U8 < 5u; l_loopcount_U8++)
            {
                l_aesCmacVerResult_U8A[l_loopcount_U8] = *l_cryptMacpointer;
                l_cryptMacpointer++;
            }
            l_cryptodatasend.jobId_E = CID_24_MAC_VER_CB;
            l_cryptodatasend.KeyId_U8 = 0u;
            l_cryptodatasend.priority_U8 = e_priorityunused;
            l_cryptodatasend.payLoadPtr_U8P = &l_aesCmacVerResult_U8A[0];
            l_cryptodatasend.payLoadSize = (uint16)VHSM_CRYPTO_MAC_VERIFY_PAYLOADSIZE;
            l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
            if (E_NOT_OK == l_RetVal_Ipc_E)
            {
                /* Message not sent through IPC */
            }
            else
            {
                /* Data sent through IPC */
            }
        }
        (void)memset(&l_vHsmCryptoJobKey_U8A[0], 0, sizeof(l_vHsmCryptoJobKey_U8A));
        (void)memset(&l_aesCmacMacVerDerKey_s, 0, sizeof(l_aesCmacMacVerDerKey_s));
//#endif
    // }
    // else
    // {
    //     l_data_AU8[0] = (uint8)CRYPTO_JOB_KEY_NOT_THERE;
    //     l_cryptodatasend.jobId_E = CID_24_MAC_VER_CB;
    //     l_cryptodatasend.KeyId_U8 = 0u;
    //     l_cryptodatasend.priority_U8 = e_priorityunused;
    //     l_cryptodatasend.payLoadPtr_U8P = &l_data_AU8[0];
    //     l_cryptodatasend.payLoadSize = (uint16)1;
    //     l_RetVal_Ipc_E = vHsmCrypto_Manager_SendData(l_cryptodatasend);
    //     if (E_NOT_OK == l_RetVal_Ipc_E)
    //     {
    //         /* Message not sent through IPC */
    //     }
    // }
    l_MacdataSize_U32 = 0;
}

/**
 ******************************************************************************
 ** \fn vHsm_DmnMgrReq
 **
 ** Function to start grace shutdown
 **
 ** This function returns None
 **
 ** \param [in] uint16 payload_size
 **             uint8 keyId
 ** Requierment ID : 
 *****************************************************************************/
FUNC(void, CRY_CODE) vHsm_DmnMgrReq(uint8 *const commanddata_addr, uint16 payload_size)
{
    UNUSED_PARAM(commanddata_addr);
    UNUSED_PARAM(payload_size);
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    Std_ReturnType l_RetVal_Ipc_E = E_NOT_OK;
    uint8 l_data_AU8[2] = {0};
    ts_vHsm_Commanddata l_commanddatasend = {0};
    l_RetVal_E = vHsmDmnMgr_Shutdown();
    if (E_OK != l_RetVal_E)
    {
        l_data_AU8[0] = (uint8)CRYPTO_JOB_NOT_DONE;
        l_commanddatasend.jobId_E = SID_3_DMNMGR_REQ_CB;
        l_commanddatasend.priority_U8 = e_priorityunused;
        l_commanddatasend.payLoadPtr_U8P = &l_data_AU8[0];
        l_commanddatasend.payLoadSize = (uint16)1;
        l_RetVal_Ipc_E = vHsmCrypto_Command_SendData(l_commanddatasend);
        if (E_NOT_OK == l_RetVal_Ipc_E)
        {
            /* Message not sent through IPC */
        }
        else
        {
            /* Data sent through IPC */
        }
    }
}
/************Command Function Definitions************************************/
/**
 ******************************************************************************
 ** \fn Command_Dummy_Function
 **
 ** Dummy function for the unused Command jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8* commanddata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) Command_Dummy_Function(uint8* const commanddata_addr,uint16 payload_size)
{
    UNUSED_PARAM commanddata_addr;
    UNUSED_PARAM payload_size;

}
FUNC (void, CRY_CODE) IPC_Funct_Message0(uint8 buffer_id, const  uint8*  buffer_add,uint16 payload_size)
{

    UNUSED_PARAM payload_size;
    UNUSED_PARAM buffer_add;
    UNUSED_PARAM buffer_id;

}

FUNC (void, CRY_CODE) IPC_Funct_Message1(uint8 buffer_id, const  uint8*  buffer_add,uint16 payload_size)
{
    UNUSED_PARAM payload_size;
    UNUSED_PARAM buffer_add;
    UNUSED_PARAM buffer_id;

}

FUNC (void, CRY_CODE) IPC_Funct_Message2(uint8 buffer_id, const  uint8*  buffer_add,uint16 payload_size)
{
     UNUSED_PARAM payload_size;
     UNUSED_PARAM buffer_add;
     UNUSED_PARAM buffer_id;
}
/* EOF */
