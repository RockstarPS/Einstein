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
/// @file
/// @ingroup UclALCrypto
/// UCL Crypto Abstraction Layer Implementation for OpenSSL library.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALCRYPTOOPENSSL_IMPL_H
#define UCLALCRYPTOOPENSSL_IMPL_H

#include "UclALCrypto_Types.h"
#include <openssl/cmac.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

typedef struct SUclALCryptoOpenSSLInst_t SUclALCryptoOpenSSLInst;

///
/// @brief Key structure declaration for SUclALCryptoOpenSSL_Impl.
///
typedef struct SUclALCryptoKey_t
{
    uint8 key[UCLALCRYPTO_KEYSIZE]; ///< Buffer to hold the key data
} SUclALCryptoKey;

///
/// @brief Configuration data for SUclALCryptoOpenSSL_Impl.
///
/// The SUclALCryptoOpenSSLCfg structure defines the constant configuration data for SUclALCryptoOpenSSL_Impl class.
///
typedef struct SUclALCryptoOpenSSLCfg_t
{
    uint8 numKeys;             ///< Number of keys in the list
    SUclALCryptoKey *pKeyList; ///< Keys List
} SUclALCryptoOpenSSLCfg;

///
/// @brief Private instance data for SUclALCryptoOpenSSL_Impl. \n
/// @ingroup UclALCrypto
///
/// The SUclALCryptoOpenSSLInst structure defines the private instance data for SUclALCryptoOpenSSL_Impl class.
///
struct SUclALCryptoOpenSSLInst_t
{
    const SUclALCryptoOpenSSLCfg *pCfg; ///< Configuration for the SUclALCryptoOpenSSL_Impl instance
//	rng_state OpenSSLrng_state;			///< OPENSSL RNG State Variable
	CMAC_CTX *pCmacCtx;                 ///< OpenSSL CMAC context pointer
	EVP_CIPHER_CTX *pAesCtx;            ///< OpenSSL AES CBC context pointer
	EUclALCryptoState State;        ///< State for the SUclALCryptoLTC_Impl instance
};

///
/// @brief This method implements the Initialize API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_Initialize(SUclALCryptoOpenSSLInst *pInst, uint8 InstId);

///
/// @brief This method implements the Shutdown API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_Shutdown(SUclALCryptoOpenSSLInst *pInst, uint8 InstId);

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
                                                           uint16 Size);

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
                                                                  uint8 *pKey, uint16 Size);

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
                                                               EUclALCryptoKeyType KeyId);

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
                                                                 uint8 *pData, uint16 Size);

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
                                                              uint8 *pResult, uint16 *pSize);

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
                                                              EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size);

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
                                                                uint8 *pClearText, uint8 *pCipherText, uint16 Size);

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
                                                                uint8 *pCipherText, uint8 *pClearText, uint16 Size);

///
/// @brief This method implements the CBC_Done API for the IUclALCrypto Interface
///
/// @param pInst Instance data of the crypto
/// @param InstId Instance Id of the callee
///
/// @return UCL_E_OK 	CBC finalization success
///	@return	UCL_E_NOK 	CBC finalization Failed
///
Ucl_ReturnType UclALCryptoOpenSSL_Impl_IUclALCrypto_CBC_Done(SUclALCryptoOpenSSLInst *pInst, uint8 InstId);

#endif //UCLALCRYPTOOPENSSL_IMPL_H
