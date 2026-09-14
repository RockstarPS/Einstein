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
/// @defgroup UclALCrypto
/// @brief UCL Crypto Abstraction Layer provides encryption/decryption services
/// @file
/// @ingroup UclALCrypto
/// UCL Crypto Abstraction Layer Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALCRYPTO_H
#define UCLALCRYPTO_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclALCrypto_Types.h"

///
/// @brief This method is used to initialize the UclALCrypto Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclALCrypto_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclALCrypto Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclALCrypto_Shutdown(uint8 InstId);

///
/// @brief This method is used to generate random bytes
///
/// @param InstId Instance Id of the Crypto
/// @param pResult Pointer to buffer to store the random number
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Random number generation Success
///	@return	UCL_E_NOK 	Random number generation Failed
///
Ucl_ReturnType UclALCrypto_Random(uint8 InstId, uint8 *pResult, uint16 Size);

///
/// @brief This method is used to configure the session key
///
/// @param InstId Instance Id of the Crypto
/// @param pKey Pointer to buffer containing the key
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	Session key successfully set
///	@return	UCL_E_NOK 	Session key setting Failed
///
Ucl_ReturnType UclALCrypto_SetSessionKey(uint8 InstId, uint8 *pKey, uint16 Size);

///
/// @brief This method is used to initiate CMAC calculation
///
/// @param InstId Instance Id of the Crypto
/// @param KeyId Key to use for CMAC calculation
///
/// @return UCL_E_OK 	CMAC initialization success
///	@return	UCL_E_NOK 	CMAC initialization Failed
///
Ucl_ReturnType UclALCrypto_CMAC_Start(uint8 InstId, EUclALCryptoKeyType KeyId);

///
/// @brief This method is used to perform CMAC calculation.
/// 	   This api can be called multiple times after CMAC start is called
///
/// @param InstId Instance Id of the Crypto
/// @param pData Data to perform CMAC calculation
/// @param Size Size of the Data
///
/// @return UCL_E_OK 	CMAC processing success
///	@return	UCL_E_NOK 	CMAC processing Failed
///
Ucl_ReturnType UclALCrypto_CMAC_Process(uint8 InstId, uint8 *pData, uint16 Size);

///
/// @brief This method is finalize the CMAC calculation and retrieve the result
///
/// @param InstId Instance Id of the Crypto
/// @param pResult Pointer to buffer to copy the result
/// @param pSize [in] Size of the Buffer [out] No of bytes copied
///
/// @return UCL_E_OK 	CMAC finalization success
///	@return	UCL_E_NOK 	CMAC finalization Failed
///
Ucl_ReturnType UclALCrypto_CMAC_Done(uint8 InstId, uint8 *pResult, uint16 *pSize);

///
/// @brief This method is used to initiate CBC routine
///
/// @param InstId Instance Id of the Crypto
/// @param KeyId Key to use for CBC algorithm
/// @param pIV Initial vector
/// @param Size Size of the initial vector
///
/// @return UCL_E_OK 	CBC initialization success
///	@return	UCL_E_NOK 	CBC initialization Failed
///
Ucl_ReturnType UclALCrypto_CBC_Start(uint8 InstId, EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size);

///
/// @brief This method is used to perform CBC Encryption
/// 	   This api can be called multiple times after CBC start is called
///
/// @param InstId Instance Id of the Crypto
/// @param pClearText Pointer to the buffer that contains the clear text
/// @param pCipherText Pointer to the buffer to copy the encrypted text
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	CBC encryption success
///	@return	UCL_E_NOK 	CBC encryption Failed
///
Ucl_ReturnType UclALCrypto_CBC_Encrypt(uint8 InstId, uint8 *pClearText, uint8 *pCipherText, uint16 Size);

///
/// @brief This method is used to perform CBC Decryption
/// 	   This api can be called multiple times after CBC start is called
///
/// @param InstId Instance Id of the Crypto
/// @param pCipherText Pointer to the buffer that contains the encrypted text
/// @param pClearText Pointer to the buffer to copy the clear text
/// @param Size Size of the buffer
///
/// @return UCL_E_OK 	CBC decryption success
///	@return	UCL_E_NOK 	CBC decryption Failed
///
Ucl_ReturnType UclALCrypto_CBC_Decrypt(uint8 InstId, uint8 *pCipherText, uint8 *pClearText, uint16 Size);

///
/// @brief This method is finalize the CBC routine
///
/// @param InstId Instance Id of the Crypto
///
/// @return UCL_E_OK 	CBC finalization success
///	@return	UCL_E_NOK 	CBC finalization Failed
///
Ucl_ReturnType UclALCrypto_CBC_Done(uint8 InstId);

#ifdef __cplusplus
}
#endif
#endif //UCLALCRYPTO_H
