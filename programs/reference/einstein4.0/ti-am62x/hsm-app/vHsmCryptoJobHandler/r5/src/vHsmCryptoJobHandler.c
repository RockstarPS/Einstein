/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
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
#include "Std_Types.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */

/* Enable this macro for crypto manager test application */
//#define CRYPTO_MANAGER_TEST

/******************************************************************************
 * Static type declarations
 *****************************************************************************/
#ifdef CRYPTO_MANAGER_TEST
uint8 l_RecivedRandom_data20_AU8[21] = {0};
uint8 l_RecivedSymBlockEncrypt_data_AU8[2] = {0};
uint8 l_RecivedSymBlockEncrypt_datafinish_AU8[66] = {0};
uint8 l_RecivedSymBlockDecrypt_data_AU8[2] = {0};
uint8 l_RecivedSymBlockDecrypt_datafinish_AU8[66] = {0};
uint8 l_RecivedSymEncrypt_data_AU8[2] = {0};
uint8 l_RecivedSymEncrypt_datafinish_AU8[66] = {0};
uint8 l_RecivedSymDecrypt_data_AU8[2] = {0};
uint8 l_RecivedSymDecrypt_datafinish_AU8[66] = {0};
uint8 l_RecivedMacVerify_data_AU8[2] = {0};
uint8 l_RecivedMacVerify_datafinish_AU8[6] = {0};
uint8 l_RecivedMacGen_data_AU8[2] = {0};
uint8 l_RecivedMacGen_datafinish_AU8[18] = {0};
#endif
uint8 l_RecivedSymBlock2Encrypt_data_AU8[2] =
{   0};
uint8 l_RecivedSymBlock2Encrypt_datafinish_AU8[82] =
{   0};
uint8 l_RecivedSymBlock2Decrypt_data_AU8[2] =
{   0};
uint8 l_RecivedSymBlock2Decrypt_datafinish_AU8[70] =
{   0};
uint8 l_RecivedSymBlock2Verify_data_AU8[2] =
{   0};
uint8 l_RecivedSymBlock2Verify_datafinish_AU8[6] =
{   0};
uint8 l_Hmac_Recived_data_AU8[2] = { 0 };
uint8 l_Hmac_Recived_datafinish_AU8[34] = { 0 };

#define COMMAND_SUCCESS             ((uint8)1)
#define COMMAND_FAILURE             ((uint8)2)

#define ERASE_COMMAND               ((uint8)1)
#define START_REF_COMMAND           ((uint8)2)
#define UPDATE_REF_COMMAND          ((uint8)3)
#define FINISH_REF_COMMAND          ((uint8)4)
#define MAX_TIMEOUT_COUNTER         (50000u)
#define SIZE_OF_AES_KEY             ((uint8)16)

uint8 l_Sent_Command = 0;
uint8 l_Recd_Command_Status = 0;
/*
LOCAL boolean l_ReflashCompleted = FALSE;
LOCAL boolean l_ReflashError= FALSE;
LOCAL boolean l_HsmVersionInfoCompleted = FALSE;
LOCAL boolean l_HsmVersionInfoError = FALSE;
LOCAL uint32 l_CrccalVal_U32 = 0;
LOCAL uint32 l_CrcAddress_U32 = 0;
LOCAL uint32 l_timeoutcounter_U32 = 0;
LOCAL uint32 l_timeoutcounterInfo_U32 = 0;
LOCAL uint8 l_AESKeyVal_U8[16];
LOCAL uint8 l_HsmDwnVersion_U8A[16] = {0};
LOCAL uint16 l_Versionpayloadsize_U8 = 0;
*/
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
 *****************************************************************************/
FUNC (void, CRY_CODE) Crypto_Dummy_Function(uint8* cryptodata_addr,uint16 payload_size)
{

}

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
FUNC (void, CRY_CODE) Command_Dummy_Function(uint8* commanddata_addr,uint16 payload_size)
{

}
FUNC (void, CRY_CODE) IPC_Funct_Message0(uint8 buffer_id, uint8* buffer_add,uint16 payload_size)
{

}

FUNC (void, CRY_CODE) IPC_Funct_Message1(uint8 buffer_id, uint8* buffer_add,uint16 payload_size)
{

}
FUNC (void, CRY_CODE) IPC_Funct_Message2(uint8 buffer_id, uint8* buffer_add,uint16 payload_size)
{

}


#ifdef CRYPTO_MANAGER_TEST

FUNC (void, CRY_CODE) vHsm_RandomCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(payload_size < 22)
    {
        if(payload_size == 6)
        {
            (void)memcpy((uint8 *)&l_RecivedRandom_data5_AU8[0], (uint8 *)cryptodata_addr, payload_size);
        }
        else if(payload_size == 1)
        {
            (void)memcpy((uint8 *)&l_RecivedRandom_data0_AU8[0], (uint8 *)cryptodata_addr, payload_size);
        }
        else
        {
            (void)memcpy((uint8 *)&l_RecivedRandom_data0_AU8[0], (uint8 *)cryptodata_addr, payload_size);
        }
    }
}
/**
 ******************************************************************************
 ** \fn vHsm_SymEncryptCallbackNotification
 **
 ** Function for the Encrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_SymEncryptCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedSymEncrypt_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedSymEncrypt_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

/**
 ******************************************************************************
 ** \fn vHsm_SymCryptCallbackNotification
 **
 ** Function for the Decrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_SymDecryptCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedSymDecrypt_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedSymDecrypt_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

/**
 ******************************************************************************
 ** \fn vHsm_SymBlockEncryptCallbackNotification
 **
 ** Function for the Block Encrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_SymBlockEncryptCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedSymBlockEncrypt_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedSymBlockEncrypt_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

/**
 ******************************************************************************
 ** \fn vHsm_SymBlockDecryptCallbackNotification
 **
 ** Function for the Block Decrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_SymBlockDecryptCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedSymBlockDecrypt_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedSymBlockDecrypt_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

/**
 ******************************************************************************
 ** \fn vHsm_SymBlockDecryptCallbackNotification
 **
 ** Function for the Block Decrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_MacGenerateCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedMacGen_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedMacGen_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

/**
 ******************************************************************************
 ** \fn vHsm_SymBlockDecryptCallbackNotification
 **
 ** Function for the Block Decrypt Callback Crypto Job
 **
 ** This function returns None
 **
 ** \param [in] uint8* cryptodata_addr
 **             uint16 payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) vHsm_MacVerifyCallbackNotification(uint8* cryptodata_addr,uint16 payload_size)
{
    if(1 == payload_size)
    {
        (void)memcpy((uint8 *)&l_RecivedMacVerify_data_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }
    else
    {
        (void)memcpy((uint8 *)&l_RecivedMacVerify_datafinish_AU8[0], (uint8 *)cryptodata_addr, payload_size);
    }

}

#endif
FUNC (void, CRY_CODE) vHsmWDG_Proxy_Notification(uint8* commanddata_addr,uint16 payload_size)
{
    /*Dummy function for Wdg Proxy*/
}

/* EOF */
