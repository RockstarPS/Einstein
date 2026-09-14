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
 * \file Crypto_KeyManagement.h
 *
 * \brief
 * Key Management header in M7
 *
 * \detailed description
 *  This file shall be dispatch the crypto job in M7, IT Receives the Crypto job request from CRYIF and depends on the job request passes the data to to CRY-SHE 
 *  and receiving back data from CRY-SHE and pass this data to CRYIF
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           ...................|
 * |--------|------------|----------|---------|----------------------------------------------------------|
 * |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation            |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

#ifndef CRYPTO_KEYMANAGEMENT_H
#define CRYPTO_KEYMANAGEMENT_H

#include "Compiler.h"
//#define CryptoKeyID_ECC256_SignatureVerify             				           0xFFU

#define MAX_ECDSA_SIGNVERIFY_KEYLENGTH                                         64U

#define SIZE_OF_TOTAL_ECDSA_KEY                     ((uint32)64)

#define KEY_ELEMENT_MASK                             ((uint8)3)

#define TS_PARAM_UNUSED(x) (void) (x)

extern FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyValidSet
(
  uint32 CryptoKeyId
);
/**
 *********************************************************************************************
 ** \fn Crypto_KeyElementSet
 **
 ** \brief 
 ** Sets the given key element bytes to the key identified by cryptoKeyId
 **
 ** \param [in] cryptoKeyId   identifier of the key whose key element shall be set
 ** \param [in] keyElementId  identifier of the key element which shall be set
 ** \param [in] keyPtr        pointer to the key data which shall be set as key element
 ** \param [in] keyLength     length of the key element in bytes
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_KEY_WRITE_FAIL: Request failed because write access was denied
 ** CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available
 ** CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match size of provided data                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType,CRY_CODE) Crypto_KeyElementSet(
                    uint32 cryptoKeyId, 
                    uint32 keyElementId, 
                    P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) keyPtr, 
                    uint32 keyLength);

/**
 *********************************************************************************************
 ** \fn Crypto_KeySetValid
 **
 ** \brief 
 ** Sets the key state of the key identified by cryptoKeyId to valid
 **
 ** \param [in] cryptoKeyId   identifier of the key which shall be set to valid
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeySetValid(uint32 cryptoKeyId);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyElementGet
 **
 ** \brief 
 ** Sets the given key element bytes to the key identified by cryptoKeyId
 **
 ** \param [in] cryptoKeyId   identifier of the key whose key element shall be returned
 ** \param [in] keyElementId  identifier of the key element which shall be returned
 ** 
 ** \param [inout] resultLengthPtr  pointer to a memory location in which the length information is stored
 **
 ** \param [out] resultPtr     pointer of the buffer for the returned key element
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available
 ** CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
 ** CRYPTO_E_SMALL_BUFFER:  Provided buffer is too small to store the result                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementGet(
                uint32 cryptoKeyId, 
                uint32 keyElementId, 
                uint8* resultPtr, 
                uint32* resultLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyElementCopy
 **
 ** \brief 
 ** Copies a key element to another key element in the same crypto driver
 **
 ** \param [in] cryptoKeyId           identifier of the key whose key element shall be the source element
 ** \param [in] keyElementId          identifier of the key element which shall be the source for the copy operation
 ** \param [in] targetCryptoKeyId     identifier of the key whose key element shall be the destination element
 ** \param [in] targetKeyElementId    identifier of the key element which shall be the destination for the copy operation
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available
 ** CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
 ** CRYPTO_E_KEY_WRITE_FAIL: Request failed because write access was denied
 ** CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match size of provided data                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementCopy(
             uint32 cryptoKeyId, 
             uint32 keyElementId, 
             uint32 targetCryptoKeyId, 
             uint32 targetKeyElementId);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyCopy
 **
 ** \brief 
 ** Copies a key with all its elements to another key in the same crypto driver
 **
 ** \param [in] cryptoKeyId           identifier of the key whose key element shall be the source element
 ** \param [in] targetCryptoKeyId     identifier of the key whose key element shall be the destination element
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_KEY_NOT_AVAILABLE: Request failed because the key is not available
 ** CRYPTO_E_KEY_READ_FAIL: Request failed because read access was denied
 ** CRYPTO_E_KEY_WRITE_FAIL: Request failed because write access was denied
 ** CRYPTO_E_KEY_SIZE_MISMATCH: Request failed, key element size does not match size of provided data                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyCopy(
                 uint32 cryptoKeyId, 
                 uint32 targetCryptoKeyId);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyElementIdsGet
 **
 ** \brief 
 ** Used to retrieve information which key elements are available in a given key
 **
 ** \param [in] cryptoKeyId             identifier of the key whose available element ids shall be exported
 ** \param [in] keyElementIdsLengthPtr  pointer to the memory location in which the number of key elements
 **                                     in the given key is stored
 ** 
 **
 ** \param [out] keyElementIdsPtr     pointer to the array where the ids of the key elements shall be stored
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_SMALL_BUFFER: Provided buffer is too small to store the result                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementIdsGet(
             uint32 cryptoKeyId, 
             uint32* keyElementIdsPtr, 
             uint32* keyElementIdsLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_RandomSeed
 **
 ** \brief 
 ** Generates the internal seed state using the provided entropy source
 **
 ** \param [in] cryptoKeyId     identifier of the key for which a new seed shall be generated
 ** \param [in] seedPtr         pointer to the memory location which contains the data to feed the seed
 ** \param [in] seedLength      length of the seed in bytes
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed               
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_RandomSeed(
                 uint32 cryptoKeyId, 
                 const uint8* seedPtr, 
                 uint32 seedLength);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyGenerate
 **
 ** \brief 
 ** Generates new key material, store it in the key identified by cryptoKeyId
 **
 ** \param [in] cryptoKeyId   identifier of the key which is to be updated with the generated value
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyGenerate(uint32 cryptoKeyId);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyDerive
 **
 ** \brief 
 ** Derives a new key by using the key elements in the given key  by the cryptoKeyId
 **
 ** \param [in] cryptoKeyId         identifier of the key which is used for key derivation
 ** \param [in] targetCryptoKeyId   identifier of the key which is used to store the derived key
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyDerive(
                 uint32 cryptoKeyId, 
                 uint32 targetCryptoKeyId);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyExchangeCalcPubVal
 **
 ** \brief 
 ** Calculates the public value for the key exchange
 **
 ** \param [in] cryptoKeyId   identifier of the key which shall be used for the key exchange protocol
 ** 
 ** \param [inout] publicValueLengthPtr  pointer to the memory location in which the public value length information is stored
 **
 ** \param [out] publicValuePtr     pointer to the data where the public value shall be stored
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_SMALL_BUFFER:  Provided buffer is too small to store the result                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcPubVal(
         uint32 cryptoKeyId, 
         uint8* publicValuePtr, 
         uint32* publicValueLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_KeyExchangeCalcSecret
 **
 ** \brief 
 ** Calculates the shared secret key for the key exchange with the key material of the 
 ** key identified by the cryptoKeyId and the partner public key
 **
 ** \param [in] cryptoKeyId                identifier of the key which shall be used for the key exchange protocol
 ** \param [in] partnerPublicValuePtr      pointer to the memory location which contains the partner's public value
 ** \param [in] partnerPublicValueLength   length of the partner's public value in bytes
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_SMALL_BUFFER:  Provided buffer is too small to store the result                  
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcSecret(
                 uint32 cryptoKeyId, 
                 const uint8* partnerPublicValuePtr, 
                 uint32 partnerPublicValueLength);

/**
 *********************************************************************************************
 ** \fn Crypto_CertificateParse
 **
 ** \brief 
 ** Parses the certificate data stored in the key element CRYPTO_KE_CERT_DATA and fills the key elements 
 ** CRYPTO_KE_CERT_SIGNEDDATA, CRYPTO_KE_CERT_PARSEDPUBLICKEY and CRYPTO_KE_CERT_SIGNATURE
 **
 ** \param [in] cryptoKeyId   identifier of the key which shall be parsed
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_CertificateParse(uint32 cryptoKeyId);

/**
 *********************************************************************************************
 ** \fn Crypto_CertificateVerify
 **
 ** \brief 
 ** Verifies the certificate stored in the key referenced by cryptoValidateKeyId 
 ** with the certificate stored in the key referenced by cryptoKeyId.
 **
 ** \param [in] cryptoKeyId         identifier of the key which shall be used to validate the certificate
 ** \param [in] verifyCryptoKeyId   Holds the identifier of the key contain
 **
 ** \param [out] verifyPtr  pointer to the memory location which will contain the result of the certificate verification 
 ** 
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_CertificateVerify(
                uint32 cryptoKeyId, 
                uint32 verifyCryptoKeyId, 
                Crypto_VerifyResultType* verifyPtr);

FUNC(Std_ReturnType,CRY_CODE) Crypto_KeyVerify
        (
                 uint32 cryptoKeyId, P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)payload_ptr,
                uint32 payload_size
        );
#endif
