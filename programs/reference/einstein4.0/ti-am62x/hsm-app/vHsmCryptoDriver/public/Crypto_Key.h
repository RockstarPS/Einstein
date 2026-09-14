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
 * \file Cry_She_key.c
 *
 * \brief
 * Key implementation header file in M7
 *
 * \detailed description
 *  This file shall be the key implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 28/Apr/'21 | bjayara2 | 1321475 |ECDSA verify for FDS                   |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_KEY_H
#define CRYPTO_KEY_H

/*==[Includes]================================================================*/

/*!
 * \defgroup   header_files Dependancy_headers
 */
/*!
 * \brief        The module shall use **Std_Types.h** data types.
 * \addtogroup  header_files
 */
#include "Std_Types.h"
#include "Csm_Types.h"
#include "Crypto_Cfg.h"

/*==[Macros]==================================================================*/
extern void Csm_KeyCallbackNotification(Csm_ReturnType result);
extern void Csm_KeyservicefinishNotification(Csm_ReturnType result);

#define CRYPTO_HSM_CSM_KEY_CALLBACK_NOTIF   Csm_KeyCallbackNotification
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_HSM_CSM_KEY_SERVICE_FINISH_NOTIF Csm_KeyservicefinishNotification

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_she_keyInit
 **
 ** \brief Initialize Crypto_key module.
 **
 ** This function initializes the Crypto_key module. It has to be called
 ** from Crypto_She_Init and before any services of the MAC generate module are used.
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_she_keyInit(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SetKey
 **
 ** \brief 
 ** 
 **
 ** \param [in] keyId         identifier of the key whose key element shall be set
 ** \param [in] keyElementId  identifier of the key element which shall be set
 ** \param [in] keyPtr        pointer to the key data which shall be set as key element
 ** \param [in] keyLength     length of the key element in bytes
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SetKey(
                uint32 keyId, uint32 keyElementId, 
                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)keyPtr,
                uint32 keyLength);

/**
 *********************************************************************************************
 ** \fn Crypto_She_KeysetValid
 **
 ** \brief 
 ** verification of key setting procedure, must be invoked after Crypto_She_SetKey
 **
 ** \param [in] keyId    identifier of the key which shall be set to valid
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_KeysetValid(uint32 keyId);

/**
 *********************************************************************************************
 ** \fn Crypto_She_GetKey
 **
 ** \brief 
 ** 
 **
 ** \param [in] keyId         identifier of the key whose key element shall be returned
 ** \param [in] keyElementId  identifier of the key element which shall be returned
 **
 ** \param [out] keyPtr        pointer of the buffer for the returned key element
 **
 ** \param [inout] keyLengthPtr  pointer to a memory location in which the length information is stored
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_GetKey(
                uint32 keyId, 
                uint32 keyElementId, 
                uint8 * keyPtr, 
                uint32 * keyLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_She_keyMainFunction
 **
 ** \brief 
 ** Key main function to track the state machine with M0P execution
 ** Use to transfer data to M0P from M7 for RSA verify crypto job and get
 ** back the response from M0P
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE) Crypto_She_keyMainFunction(void);
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_KeyVerify
        (
                 uint32 keyId, P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)payload_ptr,
                uint32 payload_size
        );

/**********************************************************************************************
 * \fn Crypto_CertificateVerify
 * \brief   Verify a certificate
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]    cryptoKeyId              Identifier of the key that shall be used for verification
 *  \param[in]    verifyCryptoKeyId        Identifier of the key that contains the certificate
 *  \param[out]   verifyPtr                Pointer to the memory location where the result of the
 *                                         verification shall be stored
 *
 *  \returns      Result of the request
 *  \retval       E_OK                     Request successful
 *  \retval       E_NOT_OK                 Request failed
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType,CRY_CODE) Crypto_CertificateVerify(uint32 cryptoKeyId,uint32 verifyCryptoKeyId,uint8 * verifyPtr);
/**********************************************************************************************
 * \fn Crypto_CertiParse
 * \brief   Parse a certificate
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]    cryptoKeyId              Identifier of the key that contains the certificate
 *
 *  \returns      Result of the request
 *  \retval       E_OK                     Request successful
 *  \retval       E_NOT_OK                 Request failed
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType,CRY_CODE) Crypto_CertiParse(uint32 cryptoKeyId);
/**********************************************************************************************
 * \fn Crypto_KeyGenerate
 * \brief   Generate a new key
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]  cryptoKeyId              Identifier of the crypto key for which key material shall
 *                                       be generated
 *
 *  \returns    Result of the request
 *  \retval     E_OK                        Request successful
 *  \retval     E_NOT_OK                    Request failed
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType,CRY_CODE) Crypto_KeyGenerate(uint32 cryptoKeyId);
/**********************************************************************************************
 * \fn Crypto_KeyDerive
 * \brief   Derive a key from another key
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]  cryptoKeyId              Identifier of the crypto key that shall be used for
 *                                       derivation
 *  \param[in]  targetCryptoKeyId        Identifier of the crypto key where the derived key shall be
 *                                       stored
 *
 *  \returns    Result of the request
 *  \retval     E_OK                        Request successful
 *  \retval     E_NOT_OK                    Request failed
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
/**********************************************************************************************
 * \fn Crypto_KeyExchangeCalcSecret
 * \brief   Calculate the shared secret for the key exchange
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]    cryptoKeyId              Identifier of the crypto key that shall be used for the
 *                                         key exchange
 *  \param[out]   partnerPublicValuePtr    Pointer to the memory where the public value of the
 *                                         partner is located
 *  \param[in]    partnerPublicValueLength Length of the partner's public value in bytes
 *
 *  \returns      Result of the request
 *  \retval       E_OK                     Request successful
 *  \retval       E_NOT_OK                 Request failed
 *  \retval       CRYPTO_E_SMALL_BUFFER    The provided buffer is too small to store the result
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcSecret(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr,  uint32 partnerPublicValueLength);
/**********************************************************************************************
 * \fn Crypto_KeyElementCopy
 * \brief      Copy a key element
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]  cryptoKeyId                 Identifier of the key whose element shall be copied
 *  \param[in]  keyElementId                Identifier of the key element that shall be copied
 *  \param[in]  targetCryptoKeyId           Identifier of the destination key
 *  \param[in]  targetKeyElementId          Identifier of the destination key element
 *
 *  \returns    Result of the request
 *  \retval     E_OK                        Request successful
 *  \retval     E_NOT_OK                    Request failed
 *  \retval     CRYPTO_E_BUSY               Request failed, crypto driver object is busy
 *  \retval     CRYPTO_E_KEY_READ_FAIL      Read access was denied
 *  \retval     CRYPTO_E_KEY_WRITE_FAIL     Write access was denied
 *  \retval     CRYPTO_E_KEY_NOT_AVAILABLE  The requested key is not available
 *  \retval     CRYPTO_E_KEY_SIZE_MISMATCH  Key element sizes are not compatible
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementCopy(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
/**********************************************************************************************
 * \fn Crypto_KeyCopy
 * \brief      Copy all key elements of a key
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]  cryptoKeyId                 Identifier of the key whose elements shall be copied
 *  \param[in]  targetCryptoKeyId           Identifier of the destination key
 *
 *  \returns    Result of the request
 *  \retval     E_OK                        Request successful
 *  \retval     E_NOT_OK                    Request failed
 *  \retval     CRYPTO_E_KEY_READ_FAIL      Read access was denied
 *  \retval     CRYPTO_E_KEY_WRITE_FAIL     Write access was denied
 *  \retval     CRYPTO_E_KEY_NOT_AVAILABLE  The requested key is not available
 *  \retval     CRYPTO_E_KEY_SIZE_MISMATCH  Key element sizes are not compatible
 *                 
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
/**********************************************************************************************
 * \fn Crypto_KeyExchangeCalcPubVal
 * \brief   Calculate the public value for the key exchange
 *
 *  This function checks the provided parameters and forwards the request to the
 *  process layer
 *
 *  \param[in]    cryptoKeyId              Identifier of the crypto key that shall be used for the
 *                                         key exchange
 *  \param[out]   publicValuePtr           Pointer to the memory location where the public value
 *                                         shall be stored
 *  \param[in,out] publicValueLengthPtr    Pointer to the memory location where the length
 *                                         information shall be
 *                                         stored. On calling this function, this location shall
 *                                         contain the size of the provided buffer.
 *
 *  \returns      Result of the request
 *  \retval       E_OK                     Request successful
 *  \retval       E_NOT_OK                 Request failed
 *  \retval       CRYPTO_E_SMALL_BUFFER    The provided buffer is too small to store the result
 *                 
 ********************************************************************************************/
Std_ReturnType Crypto_KeyExchangeCalcPubVal(uint32 cryptoKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);

#endif /*CRYPTO_KEY_H*/
