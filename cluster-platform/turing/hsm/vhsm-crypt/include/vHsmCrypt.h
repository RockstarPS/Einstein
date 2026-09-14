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
 * \file vHsmCrypt.h
 *
 * \brief
 * Visteon HSM Crypto Driver
 *
 * Acts as an interface between the interface/service layer and the
 * Infineon Cypress provided HSM Perflib Crypto.
 *
 * \version 1.1.2
 * |Version | Date       | Author   | Task Id         | Description                           |
 * |--------|------------|----------|-----------------|---------------------------------------|
 * |1.00.00 | 2024-08-13 | kjohn    | PE4TI29141-4244 | Create Initial Module.                |
 * *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *
 *
 * \todo Add support for
 * 1. AES GCM
 * 2. ED 25519
 * 3. RSA
 * 4. SHA 2 512
 * 5. SHA 3 256
 * 6. AES MP
 *
 ******************************************************************************/

/******************************************************************************
 *  HEADER FILE GUARD
 *****************************************************************************/
#ifndef VHSM_CRYPT_H
#define VHSM_CRYPT_H
#include "Std_Types.h" /* [SWS_BSW_00024] */
//#include "sa2ul_pka.h"
#include "sa2ul_crypto.h"
#include "aes.h"
#include "aes_kdf.h"
#include "string.h"
#include "trace.h"
#include "vHsmCrypt_Cfg.h" /* [SWS_BSW_00183] */
#include "vHsmCrypt_Utilities.h"


#define NUMBER_OF_RANDOM_GEN_BYTES  ((uint8)32)
#define VHSMCRYPT_HALF_WORD_SIZE    ((uint8)16)
void test_ecdsa_pka(void);
/*****************************************************************************
 *  PUBLIC APIS
 *****************************************************************************/
#ifdef VHSMCRYPT_BLOBS_ENABLED 
void vHsmCrypt_DKEK(void);
void vHsmCrypt_BlobRandomKey(void);
FUNC(Std_ReturnType,CRYPT_CODE) vHsmCrypt_BlobEncapsulation(uint8 * p_Data_pU8, uint32 p_DataSize, uint8 * p_Blob_pU8, uint32 p_BlobSize);
FUNC(Std_ReturnType,CRYPT_CODE) vHsmCrypt_BlobDecapsulation(uint8 * p_Blob_pU8, uint32 p_BlobSize,uint8 * p_Data_pU8, uint32 p_DataSize);
#endif
#if (VHSMCRYPT_VERSION_INFO_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_GetVersionInfo(Std_VersionInfoType* versioninfo_p2s)
 **
 ** \brief Returns the version information of vHsmCrypt
 **
 ** \param[out] versioninfo_p2s Pointer to the Std_VersionInfoType.<br>
 **           Valid Range: full range except NULL.
 **
 *****************************************************************************/
void vHsmCrypt_GetVersionInfo(Std_VersionInfoType* versioninfo_p2s);
#endif /* VHSMCRYPT_VERSION_INFO_API */

#ifdef VHSMCRYPT_FUNCTIONAL_TEST

#if (VHSMCRYPT_AES_ECB_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_ecb_128
 **
 ** \brief Tests ECB 128 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ecb_128(void);
/**
 ******************************************************************************
 ** \fn test_aes_ecb_192
 **
 ** Tests ECB 192 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ecb_192(void);
/**
 ******************************************************************************
 ** \fn test_aes_ecb_256
 **
 ** Tests ECB 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ecb_256(void);
#endif /* VHSMCRYPT_AES_ECB_ENABLED */

#if (VHSMCRYPT_AES_CBC_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_cbc_128
 **
 ** Tests CBC 128 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cbc_128(void);
/**
 ******************************************************************************
 ** \fn test_aes_cbc_192
 **
 ** Tests CBC 192 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cbc_192(void);
/**
 ******************************************************************************
 ** \fn test_aes_cbc_256
 **
 ** Tests CBC 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cbc_256(void);
#endif /* VHSMCRYPT_AES_CBC_ENABLED */

#if (VHSMCRYPT_AES_CTR_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_ctr_128
 **
 ** Tests ctr 128 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ctr_128(void);
/**
 ******************************************************************************
 ** \fn test_aes_ctr_192
 **
 ** Tests ctr 192 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ctr_192(void);
/**
 ******************************************************************************
 ** \fn test_aes_ctr_256
 **
 ** Tests ctr 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_ctr_256(void);
#endif /* VHSMCRYPT_AES_ctr_ENABLED */

#if (VHSMCRYPT_AES_CMAC_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_cmac_128
 **
 ** Tests CMAC 128 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cmac_128(void);
/**
 ******************************************************************************
 ** \fn test_aes_cmac_192
 **
 ** Tests CMAC 192 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cmac_192(void);
/**
 ******************************************************************************
 ** \fn test_aes_cmac_256
 **
 ** Tests CMAC 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_cmac_256(void);
#endif /* VHSMCRYPT_AES_CMAC_ENABLED */

#if (VHSMCRYPT_AES_GCM_ENABLED == STD_ON)
/* Workaround for doxy */
/* \cond EMPTY_LABEL */
/**
 ******************************************************************************
 ** \fn test_aes_gcm_128
 **
 ** Tests GCM 128 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_gcm_128(void);
/**
 ******************************************************************************
 ** \fn test_aes_gcm_192
 **
 ** Tests GCM 192 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_gcm_192(void);
/**
 ******************************************************************************
 ** \fn test_aes_gcm_256
 **
 ** Tests GCM 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_gcm_256(void);

/* \endcond EMPTY_LABEL */

#endif /* VHSMCRYPT_AES_GCM_ENABLED */

#if (VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_calc_decryption_key
 **
 ** Tests AES calculate decryption key and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_calc_decryption_key(void);
#endif /* VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED */

#if (VHSMCRYPT_SHA2_256_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_sha2_256
 **
 ** Tests SHA 2 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_sha2_256(void);
#endif /* VHSMCRYPT_SHA2_256_ENABLED */

#if (VHSMCRYPT_SHA2_512_ENABLED == STD_ON)
/* Workaround for doxy */
/* \cond EMPTY_LABEL */
/**
 ******************************************************************************
 ** \fn test_sha2_512
 **
 ** Tests SHA 2 512 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_sha2_512(void);
#endif /* VHSMCRYPT_SHA2_512_ENABLED */

#if (VHSMCRYPT_SHA3_256_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_sha3_256
 **
 ** Tests SHA 3 256 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_sha3_256(void);
/* \endcond EMPTY_LABEL */
#endif /* VHSMCRYPT_SHA3_256_ENABLED */

#if (VHSMCRYPT_COMPRESS_AES_MP_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_aes_mp
 **
 ** Tests AES MP and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_aes_mp(void);
#endif /* VHSMCRYPT_COMPRESS_AES_MP_ENABLED */

#if (VHSMCRYPT_RSA_EXP_65537_ENABLED == STD_ON)
/* Workaround for doxy */
/* \cond EMPTY_LABEL */
/**
 ******************************************************************************
 ** \fn test_rsa
 **
 ** Tests RSA and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_rsa(void);
#endif /* VHSMCRYPT_RSA_EXP_65537_ENABLED */

#if (VHSMCRYPT_ECDSA_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_ecdsa
 **
 ** Tests ECDSA and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_ecdsa(void);
#endif /* VHSMCRYPT_ECDSA_ENABLED */

#if (VHSMCRYPT_ED25519_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_ed25519
 **
 ** Tests ED25519 and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_ed25519(void);
/* \endcond EMPTY_LABEL */
#endif /* VHSMCRYPT_ED25519_ENABLED */

#if (VHSMCRYPT_TRNG_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_trng
 **
 ** Tests TRNG and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_trng(void);
#endif /* VHSMCRYPT_TRNG_ENABLED */

#if (VHSMCRYPT_PRNG_AES_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn test_prng
 **
 ** Tests PRNG and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_prng(void);
#endif /* VHSMCRYPT_PRNG_AES_ENABLED */

#if (VHSMCRYPT_SIPHASH_24_ENABLED == STD_ON)
FUNC(Std_ReturnType, CRYPT_CODE) test_siphash(void);
#endif
#if (VHSMCRYPT_AES_HMAC_SHA2_256 == STD_ON)
/**
 ******************************************************************************
 ** \fn test_prng
 **
 ** Tests HMAC and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_hmac_sha2_256(void);
#endif /* VHSMCRYPT_AES_HMAC_SHA2_256 */
#if (VHSMCRYPT_PBKDF2_HMAC_SHA256 == STD_ON)
/**
 ******************************************************************************
 ** \fn test_pbkdf2
 **
 ** Tests HMAC and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRYPT_CODE) test_pbkdf2(void);
#endif /* VHSMCRYPT_PBKDF2_HMAC_SHA256 */

#if (VHSMCRYPT_KDF_VKMS  == STD_ON)
/**
 ******************************************************************************
 ** \fn test_kdf
 **
 ** Tests KDF in counter mode and returns result
 **
 ** \return Std_ReturnType<br>
 ** E_OK if test is successful
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) test_KDF_counter(void);
#endif /* VHSMCRYPT_KDF_VKMS */

#endif /* defined(VHSMCRYPT_FUNCTIONAL_TEST) */

/******************************************************************************
 * AES
 ******************************************************************************/
/*-----------------------------------------------------------------------------
 * AES CALCULATE INVERSE / DECRYPTION KEY
 *---------------------------------------------------------------------------*/
#if ((VHSMCRYPT_AES_ECB_ENABLED == STD_ON) || (VHSMCRYPT_AES_CBC_ENABLED == STD_ON))
#if 0
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCalcDecrKey(
 **     const uint8* const p_KeyPtr_pU8,
 **     const HsmCrpt_AesKeySizeType p_KeyLength_E,
 **     uint8* const p_DecrKeyPtr_pU8);
 **
 ** Calculates inverse key for AES decryption and writes it to the pointer
 ** address.
 **
 ** \param[in] p_KeyPtr_pU8
 **           Pointer to the key.<br>
 **           Valid Range: full range.
 **
 ** \param [in] p_KeyLength_E
 **           Length of encryption and decryption key.<br>
 **           Valid Range: Whole enumeration range.
 **
 ** \param [out] p_DecrKeyPtr_pU8
 **           Pointer to the calculated inverse key.<br>
 **           Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if Decryption Key could be calculated.
 ** - E_NOT_OK if Decryption Key cannot be calculated.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCalcDecrKey(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                         uint8* const p_DecrKeyPtr_pU8);
#endif
#endif /* VHSMCRYPT_AES_ECB_ENABLED || VHSMCRYPT_AES_CBC_ENABLED */

/*-----------------------------------------------------------------------------
 * AES ECB ENCRYPTION
 *---------------------------------------------------------------------------*/
#if (VHSMCRYPT_AES_ECB_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbEncryptStart(
 const uint8* const           p_KeyPtr_pU8,
 const HsmCrpt_AesKeySizeType p_KeyLength_E);
 **
 ** Performs AES Key loading for AES encryption in ECB mode.
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the key.
 **                       Valid Range: full range.
 **
 ** \param [in] p_KeyLength_E
 **                       Length of encryption key in bytes.
 **                       Valid Range: Whole enumeration range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbEncryption could start.
 ** - E_NOT_OK if any of the inputs were not valid.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbEncryptStart(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbEncryptUpdate(
 **    const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
 **    uint8* const p_CipherTextPtr_pU8);
 **
 ** Performs AES encryption in ECB mode.
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the input Plain Text to be encrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Plain and
 ** output Cipher Text in bytes.
 ** Length of the input shall be a multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text Length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbEncryption could update.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbEncryptUpdate(const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* const p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbEncryptFinish
 **
 ** Empty function to follow pattern Start - Update - Finish for AES ECB
 ** Encryption.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text Length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbEncryptFinish(uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbEncryptCancel
 **
 ** Cancels an ongoing vHsmCrypt_AesEcbEncrypt operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbEncryptCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbEncrypt(
 **  const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
 **  const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
 **  uint8* const p_CipherTextPtr_pU8);
 **
 ** Wrapper to call Start Update and Finish
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the key.
 **                       The decryption key has to be derived by using
 **                       Valid Range: full range.
 **
 ** \param [in] p_KeyLength_E
 **                       Length of encryption key in bytes.
 **                       Valid Range: Whole enumeration range.
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the input Plain Text to be encrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Plain and
 ** output Cipher Text in bytes.
 ** Length of the input and output shall be a multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text Length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbEncryption could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbEncrypt(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                        uint8* const p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);


/*-----------------------------------------------------------------------------
 * AES ECB DECRYPTION
 *---------------------------------------------------------------------------*/
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbDecryptStart(
 **    const uint8* const           p_DecrKeyPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_DecrKeyLength_E);
 **
 ** Performs AES Key loading for AES decryption in ECB mode
 **
 ** \param [in] p_DecrKeyPtr_pU8
 ** Pointer to the decryption key.
 ** Valid Range: full range.
 **
 ** \param [in] p_DecrKeyLength_E
 ** Length of the decryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbDecryption could start.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbDecryptStart(const uint8* const p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbDecryptUpdate(
 **    const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
 **    uint8* const p_PlainTextPtr_pU8);
 **
 ** Performs AES decryption in ECB mode.
 **
 ** \param [in] p_CipherTextPtr_pU8
 ** Pointer to the input Cipher Text to be decrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Cipher and
 ** output Plain Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_plainTextLengthPtr_pU32
 ** Pointer to the Plain Text Length.
 ** Valid Range: full range
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbDecryption could update.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbDecryptUpdate(const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* const p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbDecryptFinish
 **
 ** Empty function to follow pattern Start - Update - Finish for AES ECB
 ** Decryption.
 **
 ** 
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_plainTextLengthPtr_pU32
 ** Pointer to the output Cipher Text Length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbDecryptFinish(uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbDecryptCancel
 **
 ** Cancels an ongoing vHsmCrypt_AesEcbDecrypt operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbDecryptCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesEcbDecrypt(
 **    const uint8* const           p_DecrKeyPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_DecrKeyLength_E,
 **    const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
 **    uint8* const p_PlainTextPtr_pU8);
 **
 ** Performs AES decryption in ECB mode.
 ** Works only in single call mode.
 **
 ** \param [in] p_DecrKeyPtr_pU8
 ** Pointer to the decryption key.
 ** The decryption key has to be derived by using HsmCrpt_AesCalcDecrKey.
 ** Valid Range: full range.
 **
 ** \param [in] p_DecrKeyLength_E
 ** Length of the decryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \param [in] p_CipherTextPtr_pU8
 ** Pointer to the input Cipher Text to be decrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Cipher and
 ** output Plain Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_plainTextLengthPtr_pU32
 ** Pointer to the output Cipher Text Length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesEcbDecryption could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbDecrypt(const uint8* const p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E,
                        const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                        uint8* const p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

#endif /* VHSMCRYPT_AES_ECB_ENABLED */

/******************************************************************************
 AES CBC
 *****************************************************************************/
#if (VHSMCRYPT_AES_CBC_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcEncryptStart(
 **    const uint8* p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
 **    const uint8*                 p_InitialVectorPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_InitialVectorLength_E);
 **
 ** Performs AES key and init vector loading for AES encryption in CBC mode.
 **
 ** \param [in] p_KeyPtr_pU8
 ** Pointer to the key.
 ** Valid Range: full range.
 **
 ** \param [in] p_KeyLength_E
 ** Length of encryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \param [in] p_InitialVectorPtr_pU8
 ** Pointer to the initial vector of 16 byte.
 ** Valid Range: full range.
 **
 ** \param [in] p_InitialVectorLength_E
 ** Size of Initial Vector (must be 16 bytes)
 ** Valid Range: 16...16
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcEncryption could start.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncryptStart(const uint8* p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                             const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E);

/**
 ******************************************************************************
 ** \fn FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_AesCbcEncryptUpdate
 **                     (const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
 **                      uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
 **
 ** Performs AES encryption in CBC mode.
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the input Plain Text to be encrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Plain and
 ** output Cipher Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcEncryption could update.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncryptUpdate(const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcEncryptFinish
 **
 ** Empty function to follow pattern Start - Update - Finish for AES CBC
 *Encryption.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcEncryptFinish(uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcEncryptCancel
 **
 ** Cancels an ongoing vHsmCrypt_AesCbcEncrypt operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcEncryptCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcEncrypt(
 **    const uint8* p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
 **    const uint8*                 p_InitialVectorPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_InitialVectorLength_E,
 **    const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
 **    uint8* p_CipherTextPtr_pU8);
 **
 ** Performs AES encryption in CBC mode.
 ** Works only in single call mode.
 **
 ** \param [in] p_KeyPtr_pU8
 ** Pointer to the key.
 ** Valid Range: full range.
 **
 ** \param [in] p_KeyLength_E
 ** Length of encryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \param [in] p_InitialVectorPtr_pU8
 ** Pointer to the initial vector of 16 byte.
 ** Valid Range: full range.
 **
 ** \param [in] p_InitialVectorLength_E
 ** Pointer to the initial vector of 16 byte.
 ** Valid Range: full range.
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the input Plain Text to be encrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Plain and
 ** output Cipher Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_CipherTextPtr_pU8
 ** Pointer to the output Cipher Text.
 ** Valid Range: full range.
 **
 ** \param [inout] p_CipherLengthPtr
 ** Pointer to the output Cipher Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcEncryption could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncrypt(const uint8* p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E,
                        const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32, uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr);
/******************************************************************************
 AES CBC Decrypt
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcDecryptStart(
 **    const uint8*                 p_DecrKeyPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_DecrKeyLength_E,
 **    const uint8*                 p_InitialVectorPtr_pU8,
 **    const HsmCrpt_AesKeySizeType p_InitialVectorLength_E);
 **
 ** Performs AES key and init vector loading for AES decryption in CBC mode.
 **
 ** \param [in] p_DecrKeyPtr_pU8
 ** Pointer to the decryption key.
 ** The decryption key has to be derived by using HsmCrpt_AesCalcDecrKey.
 ** Valid Range: full range.
 **
 ** \param [in] p_DecrKeyLength_E
 ** Length of the decryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \param [in] p_InitialVectorPtr_pU8
 ** Pointer to the initial vector of 16 byte.
 ** Valid Range: full range.
 **
 ** \param [in] p_InitialVectorLength_E
 ** Length of the initial vector. Must be 16 bytes.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcDecryption could be started.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecryptStart(const uint8* p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E,
                             const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcDecryptUpdate(const uint8* p_CipherTextPtr_pU8,
 **                                   const uint32 p_TextLength_U32,
 **                                   uint8*       p_PlainTextPtr_pU8);
 **
 ** Performs AES decryption in CBC mode.
 **
 ** \param [in] p_CipherTextPtr_pU8
 ** Pointer to the input Cipher Text to be decrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Cipher and
 ** output Plain Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text.
 ** Valid Range: full range.
 **
 ** \param [out] p_plainTextLengthPtr_pU32
 ** Pointer to the Plain Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcDecryption could be updated.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecryptUpdate(const uint8* p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcDecryptFinish
 **
 ** Empty function to follow pattern Start - Update - Finish for AES CBC
 *Encryption.
 **
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text.
 ** Valid Range: full range.
 **
 ** \param [out] p_plainTextLengthPtr_pU32
 ** Pointer to the Plain Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcDecryptFinish(uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCbcDecryptCancel
 **
 ** Cancels an ongoing vHsmCrypt_AesCbcDecrypt operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcDecryptCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_AesCbcDecrypt
 **
 ** Performs AES decryption in CBC mode.
 ** Works only in single call mode.
 **
 ** \param [in] p_DecrKeyPtr_pU8
 ** Pointer to the decryption key.
 ** Valid Range: full range.
 **
 ** \param [in] p_DecrKeyLength_E
 ** Length of the decryption key in bytes.
 ** Valid Range: Whole enumeration range.
 **
 ** \param [in] p_InitialVectorPtr_pU8
 ** Pointer to the initial vector of 16 byte.
 ** Valid Range: full range.
 **
 ** \param [in] p_InitialVectorLength_E
 ** Length of initial vector.
 ** Valid Range: 16 bytes
 **
 ** \param [in] p_CipherTextPtr_pU8
 ** Pointer to the input Cipher Text to be decrypted.
 ** Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 ** Length of the input Cipher and
 ** output Plain Text in bytes.
 ** Length of the input and output will be rounded down
 ** to the next multiple of 16 bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x0FFF_FFFF.
 **
 ** \param [out] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text.
 ** Valid Range: full range.
 **
 ** \param [out] p_plainTextLengthPtr_pU32
 ** Pointer to the Plain Text length.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if AesCbcDecryption could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecrypt(const uint8* p_DecrKeyPtr_pU8, const uint8  p_DecrKeyLength_E,
                        const uint8* p_InitialVectorPtr_pU8, const uint8  p_InitialVectorLength_E,
                        const uint8* p_CipherTextPtr_pU8, const uint32 p_TextLength_U32, uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32);

#endif /* VHSMCRYPT_AES_CBC_ENABLED */

/******************************************************************************
 CTR
 *****************************************************************************/
/* ToDo */

/******************************************************************************
 CMAC
 *****************************************************************************/

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCmacGenerate(
 **    const HsmCrpt_AesCmacKeyDataType* const p_AesCmacKeysPtr_pS,
 **    const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
 **    uint8* const p_AesCmacGenPtr_pU8, const uint32 p_AesCmacGenLength_U32);
 **
 ** Generate AES CMAC for a given message and a secret key and write CMAC
 ** from register buffer to output buffer.
 ** If the output buffer is less than 16 bytes, only the first part
 ** of the output CMAC will be written to this buffer.
 ** If the output is larger than 16 bytes, the first 16 bytes
 ** will be overwritten by the output CMAC.
 **
 ** \param [in] p_AesCmacKeysPtr_pS
 ** Pointer to the CMAC Key structure.
 ** Valid Range: full range.
 **
 ** \param [in] p_AesCmacKeyLength_pU8
 ** Length of message.
 ** Valid Range: Full range.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of message.
 ** Valid Range: 0 .. 0x10000000.
 **
 ** \param [out] p_AesCmacGenPtr_pU8
 ** Pointer to the buffer for generated CMAC.
 ** Valid Range: full range.
 **
 ** \param [in] p_AesCmacGenLength_U32
 ** Size of output buffer.
 ** Valid Range: 1 .. 0xFFFFFFFF.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if vHsmCrypt_AesCmacGenerate could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCmacGenerate(const uint8* const p_AesCmacKeysPtr_pS,const uint8 p_AesCmacKeyLength_pU8, const uint8* const p_MsgPtr_pU8,
                          const uint32 p_MsgLength_U32, uint8* const p_AesCmacGenPtr_pU8,
                          const uint32 p_AesCmacGenLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCmacVerify(
 **    const HsmCrpt_AesCmacKeyDataType* const p_AesCmacKeysPtr_pS,
 **    const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
 **    const uint8* const p_AesCmacVerPtr_pU8, const uint8 p_AesCmacVerBits_U8,
 **    uint32* const p_ResultPtr_pU32);
 **
 ** Verifies AES CMAC for a given message and a secret key.
 ** When calculated CMAC matches referenced CMAC
 ** result is HSMCRPT_AES_CMAC_VERIFICATION_OK,
 ** otherwise HSMCRPT_AES_CMAC_VERIFICATION_NOT_OK.
 **
 ** \param [in] p_AesCmacKeysPtr_pS
 ** Pointer to the CMAC Key structure.
 ** Valid Range: full range.
 **
 ** \param [in] p_AesCmacKeyLength_pU8
 ** Length of message.
 ** Valid Range: Full Range.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of message.
 ** Valid Range: 0 .. 0x10000000.
 **
 ** \param [in] p_AesCmacVerPtr_pU8
 ** Pointer to the CMAC for verification.
 ** Valid Range: full range.
 **
 ** \param [in] p_AesCmacVerBits_U8
 ** Number of bits to use for verification starting from MSB.
 ** Valid Range: 1 .. 128
 **
 ** \param [out] p_ResultPtr_pU32
 ** Pointer to the verification result.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if vHsmCrypt_AesCmacVerify could be performed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCmacVerify(const uint8* const p_AesCmacKeysPtr_pS,const uint8 p_AesCmacKeyLength_pU8, const uint8* const p_MsgPtr_pU8,
                        const uint32 p_MsgLength_U32, const uint8* const p_AesCmacVerPtr_pU8,
                        const uint8 p_AesCmacVerBits_U8, uint32* const p_ResultPtr_pU32);


#if 0
#if (VHSMCRYPT_CANCEL_API == STD_ON)

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesCmacCommonCancel
 **
 ** Cancels an ongoing vHsmCrypt_AesCmac operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCmacCommonCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

#endif /* VHSMCRYPT_AES_CMAC_ENABLED */

/******************************************************************************
 AES GCM
 *****************************************************************************/
#if (VHSMCRYPT_AES_GCM_ENABLED == STD_ON)
/* Workaround for doxy */
/* \cond EMPTY_LABEL */
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmEncrypt(
 **   const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **   const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32,
 **   const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
 **   const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
 **   uint8* const p_OutMsgPtr_pU8, uint8* const p_OutMacPtr_pU8,
 **   const uint32 p_MacLength_U32);
 **
 ** Function performs AES GCM encryption.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of encryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Plain Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Plain Text in bytes.
 **                     Valid Range: full range.
 **
 ** \param OutMsgPtr [out]
 **                     Pointer to the output Cipher Text.
 **                     Valid Range: full range.
 **
 ** \param OutMacPtr [out]
 **                     Pointer to the memory to store MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of MAC in bytes.
 **                     Valid Range: 1..16
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncrypt(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_E,
                        const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                        const uint32 p_AadLength_U32, const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                        uint8* const p_OutMsgPtr_pU8, uint32 * p_OutMsgLength_pU32, uint8* const p_OutMacPtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmDecrypt(
 **   const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **   const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32,
 **   const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
 **   const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
 **   uint8* const p_OutMsgPtr_pU8, const uint8* const p_MacPtr_pU8,
 **   const uint32 p_MacLength_U32, const uint32 p_MacBitLength_32,
 **   uint8* const p_VerResultPtr_pU8);
 **
 ** Function performs AES GCM decryption.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of decryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Cipher Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Cipher Text in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param OutMsgPtr [out]
 **                     Pointer to the output Plain Text.
 **                     Valid Range: full range.
 **
 ** \param MacPtr [in]
 **                     Pointer to the MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of MAC in bytes.
 **                     given as input or output.
 **                     Valid Range: 1..16
 **
 ** \param MacBitLength [in]
 **                     Length of input MAC in bits
 **                     that is used for MAC verification.
 **                     Valid Range: 0..128
 **
 ** \param VerResultPtr [out]
 **                     Pointer to the verification result.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecrypt(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                        const uint32 p_AadLength_U32, const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                        uint8* const p_OutMsgPtr_pU8, const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32);
#if 0
/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmVerify(
 **   const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **   const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32,
 **   const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
 **   const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
 **   const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32,
 **   const uint32 p_MacBitLength_U32, uint8* const p_VerResultPtr_pU8);
 **
 ** Function performs AES GCM verification.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of decryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Cipher Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Cipher Text in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MacPtr [in]
 **                     Pointer to the input MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of input MAC in bytes.
 **                     given as input or output.
 **                     Valid Range: 1..16
 **
 ** \param MacBitLength [in]
 **                     Length of input MAC in bits
 **                     that is used for MAC verification.
 **                     Valid Range: 0..128
 **
 ** \param VerResultPtr [out]
 **                     Pointer to the verification result.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmVerify(const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
                       const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                       const uint32 p_AadLength_U32, const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                       const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32, const uint32 p_MacBitLength_U32,
                       uint8* const p_VerResultPtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmEncryptStart(
 **   const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **   const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);
 **
 ** Function performs Start phase of AES GCM encryption.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of encryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptStart(const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
                             const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmEncryptUpdate(const uint8* const p_AadPtr_pU8,
 **                                   const uint32       p_AadLength_U32,
 **                                   const uint8* const p_MsgPtr_pU8,
 **                                   const uint32       p_MsgLength_U32,
 **                                   uint8* const       p_OutMsgPtr_pU8);
 **
 ** Function performs Update phase of AES GCM encryption.
 **
 ** At least Start phase should be completed before
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Plain Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Plain Text in bytes.
 **                     Valid Range: full range.
 **
 ** \param OutMsgPtr [out]
 **                     Pointer to the output Cipher Text.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptUpdate(const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
                              const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                              uint8* const p_OutMsgPtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmEncryptFinish(uint8* const p_OutMacPtr_pU8,
 **                                     const uint32 p_MacLength_U32);
 **
 ** Function performs Finish phase of AES GCM encryption.
 **
 ** At least Start or Start-update phase should be completed before.
 **
 ** \param OutMacPtr [out]
 **                     Pointer to the memory to store MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of MAC in bytes.
 **                     Valid Range: 1..16
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptFinish(uint8* const p_OutMacPtr_pU8, const uint32 p_MacLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmDecryptStart(
 **     const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **     const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);
 **
 ** Function performs Start phase of AES GCM decryption.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of decryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptStart(const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
                             const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmDecryptUpdate(const uint8* const p_AadPtr_pU8,
 **                                   const uint32       p_AadLength_U32,
 **                                   const uint8* const p_MsgPtr_pU8,
 **                                   const uint32       p_MsgLength_U32,
 **                                   uint8* const       p_OutMsgPtr_pU8);
 **
 ** Function performs Update phase of AES GCM decryption.
 **
 ** At least Start phase should be completed before.
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Cipher Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Cipher Text in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param OutMsgPtr [out]
 **                     Pointer to the output Plain Text.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptUpdate(const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
                              const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                              uint8* const p_OutMsgPtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmDecryptFinish(const uint8* const p_MacPtr_pU8,
 **                                   const uint32       p_MacLength_U32,
 **                                   const uint32       p_MacBitLength_U32,
 **                                   uint8* const       p_VerResultPtr_pU8);
 **
 ** Function performs Finish phase of AES GCM decryption.
 **
 ** At least Start or Start-update phase should be completed before.
 **
 ** \param MacPtr [in]
 **                     Pointer to the MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of MAC in bytes.
 **                     given as input or output.
 **                     Valid Range: 1..16
 **
 ** \param MacBitLength [in]
 **                     Length of input MAC in bits
 **                     that is used for MAC verification.
 **                     Valid Range: 0..128
 **
 ** \param VerResultPtr [out]
 **                     Pointer to the verification result.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptFinish(const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32,
                              const uint32 p_MacBitLength_U32, uint8* const p_VerResultPtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmVerifyStart(
 **     const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType
 *p_KeyLength_E,
 **     const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);
 **
 ** Function performs Start phase of AES GCM verification.
 **
 ** \param KeyPtr [in]
 **                     Pointer to the key.
 **                     Valid Range: full range.
 **
 ** \param KeyLength [in]
 **                     Length of decryption key.
 **                     Valid Range: Whole enumeration range.
 **
 ** \param IvPtr [in]
 **                     Pointer to the IV.
 **                     Valid Range: full range.
 **
 ** \param IvLength [in]
 **                     Length of IV in bytes.
 **                     Valid Range: 0..16
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmVerifyStart(const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
                            const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmVerifyUpdate(const uint8* const p_AadPtr_pU8,
 **                                  const uint32       p_AadLength_U32,
 **                                  const uint8* const p_MsgPtr_pU8,
 **                                  const uint32       p_MsgLength_U32);
 **
 ** Function performs Update phase of AES GCM verification.
 **
 ** At least Start phase should be completed before.
 **
 ** \param AadPtr [in]
 **                     Pointer to the AAD.
 **                     Valid Range: full range.
 **
 ** \param AadLength [in]
 **                     Length of AAD in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 ** \param MsgPtr [in]
 **                     Pointer to the Cipher Text.
 **                     Valid Range: full range.
 **
 ** \param MsgLength [in]
 **                     Length of Cipher Text in bytes.
 **                     Valid Range: n * 16 byte block, n = 0..0x1000000
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmVerifyUpdate(const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
                             const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_AesGcmVerifyFinish(const uint8* const p_MacPtr_pU8,
 **                                  const uint32       p_MacLength_U32,
 **                                  const uint32       p_MacBitLength_U32,
 **                                  uint8* const       p_VerResultPtr_pU8);
 **
 ** Function performs Finish phase of AES GCM verification.
 **
 ** At least Start or Start-update phase should be completed before.
 **
 ** \param MacPtr [in]
 **                     Pointer to the input MAC.
 **                     Valid Range: full range.
 **
 ** \param MacLength [in]
 **                     Length of input MAC in bytes.
 **                     given as input or output.
 **                     Valid Range: 1..16
 **
 ** \param MacBitLength [in]
 **                     Length of input MAC in bits
 **                     that is used for MAC verification.
 **                     Valid Range: 0..128
 **
 ** \param VerResultPtr [out]
 **                     Pointer to the verification result.
 **                     Valid Range: full range.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmVerifyFinish(const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32,
                             const uint32 p_MacBitLength_U32, uint8* const p_VerResultPtr_pU8);
#endif
/* \endcond EMPTY_LABEL */
#endif /* VHSMCRYPT_AES_GCM_ENABLED */

/******************************************************************************
 SHA2-256
 *****************************************************************************/
#if (VHSMCRYPT_SHA2_256_ENABLED == STD_ON)
#if 0
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_256_Start
 **
 ** Performs SHA2-256 initialization. Note, this function has to be called
 ** before any data is processed with the function HsmCrpt_Sha2_256_Update.
 **
 ** \return Std_ReturnType<br>
 ** This function always returns:
 ** - E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Start(void);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_256_Update(const uint8* const p_MsgPtr_pU8,
 **                               const uint32       p_MsgLength_U32);
 **
 ** Performs SHA2-256 message processing. Note, the HsmCrpt_Sha2_256_Start
 ** function has to be called before processing any data with this function.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after start.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Update(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_256_Finish(uint8* const p_DigestPtr_pU8,
 **                               const uint32 p_DigestLength_U32);
 **
 ** Performs SHA2-256 padding calculation.
 ** Either Start Phase or Start and Update phase has to be executed before.
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after update.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Finish(uint8* const p_DigestPtr_pU8, const uint32 p_DigestLength_U32);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_256_Cancel
 **
 ** Cancels an ongoing vHsmCrypt_SHA2_256 operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_256_Cancel(void);

#endif /* VHSMCRYPT_CANCEL_API */
#endif
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_256(const uint8* const p_MsgPtr_pU8,
 **                        const uint32       p_MsgLength_U32,
 **                        uint8* const       p_DigestPtr_pU8,
 **                        const uint32       p_DigestLength_U32);
 **
 ** Performs hash calculation for a given message using SHA2-256 algorithm.
 ** Works only in single call mode.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Sha2_256(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Sha2_384(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Sha2_512(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);

#endif /* VHSMCRYPT_SHA2_256_ENABLED */

#if (VHSMCRYPT_SHA1_ENABLED == STD_ON)  
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha1(const uint8* const p_MsgPtr_pU8,
 **                        const uint32       p_MsgLength_U32,
 **                        uint8* const       p_DigestPtr_pU8,
 **                        const uint32       p_DigestLength_U32);
 **
 ** Performs hash calculation for a given message using SHA1 algorithm.
 ** Works only in single call mode.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/  

FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha1(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
        const uint32 p_DigestLength_U32);
#endif

/******************************************************************************
 SHA2-512
 *****************************************************************************/
#if (VHSMCRYPT_SHA2_512_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_512_Start
 **
 ** Performs SHA2-512 initialization. Note, this function has to be called
 ** before any data is processed with the function HsmCrpt_Sha2_512_Update.
 **
 ** \return Std_ReturnType<br>
 ** This function always returns:
 ** - E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_512_Start(void);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_512_Update(const uint8* const p_MsgPtr_pU8,
 **                               const uint32       p_MsgLength_U32);
 **
 ** Performs SHA2-512 message processing. Note, the HsmCrpt_Sha2_512_Start
 ** function has to be called before processing any data with this function.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after start.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_512_Update(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_512_Finish(uint8* const p_DigestPtr_pU8,
 **                               const uint32 p_DigestLength_U32);
 **
 ** Performs SHA2-512 padding calculation.
 ** Either Start Phase or Start and Update phase has to be executed before.
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after update.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_512_Finish(uint8* const p_DigestPtr_pU8, const uint32 p_DigestLength_U32);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_512_Cancel
 **
 ** Cancels an ongoing vHsmCrypt_SHA2_512 operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha2_512_Cancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha2_512(const uint8* const p_MsgPtr_pU8,
 **                        const uint32       p_MsgLength_U32,
 **                        uint8* const       p_DigestPtr_pU8,
 **                        const uint32       p_DigestLength_U32);
 **
 ** Performs hash calculation for a given message using SHA2-512 algorithm.
 ** Works only in single call mode.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Sha2_512(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);

#endif /* VHSMCRYPT_SHA2_512_ENABLED */

/******************************************************************************
 SHA3-256
 *****************************************************************************/
#if (VHSMCRYPT_SHA3_256_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha3_256_Start
 **
 ** Performs SHA3-256 initialization. Note, this function has to be called
 ** before any data is processed with the function HsmCrpt_Sha3_256_Update.
 **
 ** \return Std_ReturnType<br>
 ** This function always returns:
 ** - E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha3_256_Start(void);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha3_256_Update(const uint8* const p_MsgPtr_pU8,
 **                               const uint32       p_MsgLength_U32);
 **
 ** Performs SHA3-256 message processing. Note, the HsmCrpt_Sha3_256_Start
 ** function has to be called before processing any data with this function.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after start.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha3_256_Update(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha3_256_Finish(uint8* const p_DigestPtr_pU8,
 **                               const uint32 p_DigestLength_U32);
 **
 ** Performs SHA3-256 padding calculation.
 ** Either Start Phase or Start and Update phase has to be executed before.
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after update.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha3_256_Finish(uint8* const p_DigestPtr_pU8, const uint32 p_DigestLength_U32);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha3_256_Cancel
 **
 ** Cancels an ongoing vHsmCrypt_Sha3_256 operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_Sha3_256_Cancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_Sha3_256(const uint8* const p_MsgPtr_pU8,
 **                        const uint32       p_MsgLength_U32,
 **                        uint8* const       p_DigestPtr_pU8,
 **                        const uint32       p_DigestLength_U32);
 **
 ** Performs hash calculation for a given message using Sha3-256 algorithm.
 ** Works only in single call mode.
 **
 ** \param [in] p_MsgPtr_pU8
 ** Pointer to the message for which hash should be calculated.
 ** Valid Range: full range.
 **
 ** \param [in] p_MsgLength_U32
 ** Length of the input message in bytes.
 ** Valid Range: 0..0x10000000
 **
 ** \param [out] p_DigestPtr_pU8
 ** Pointer to the digest of message.
 ** Valid Range: full range.
 **
 ** \param [in] p_DigestLength_U32
 ** Length of the buffer in bytes to store digest.
 ** If this buffer is larger than 32 bytes, the remaining
 ** data will be left unchanged.
 ** Valid Range: 1..0xFFFFFFFF
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Sha3_256(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);

#endif /* VHSMCRYPT_SHA3_256_ENABLED */

/******************************************************************************
 AES COMPRESS MP
 *****************************************************************************/
#if (VHSMCRYPT_COMPRESS_AES_MP_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_CompressAesMpStart
 **
 ** Function performs Start phase of compression by Miyaguchi-Preneel algorithm.
 **
 ** \return Std_ReturnType<br>
 ** Always return E_OK
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_CompressAesMpStart(void);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_CompressAesMpUpdate(
 **      const uint8* p_PlainTextPtr_pU8, const uint32 p_PlainTextLength_U32);
 **
 ** Function performs Update phase of compression by Miyaguchi-Preneel algorithm.
 **
 ** Start phase should be completed before.
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text to be compressed.
 ** Valid Range: full range.
 **
 ** \param [in] p_PlainTextLength_U32
 ** Length of the input Plain Text in bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x1000000.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after start.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_CompressAesMpUpdate(const uint8* p_PlainTextPtr_pU8, const uint32 p_PlainTextLength_U32);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_CompressAesMpFinish(uint8* p_CompressedMsgPtr_pU8);
 **
 ** Function performs Finish phase of compression by Miyaguchi-Preneel algorithm.
 **
 ** Either Start Phase or Start and Update phase has to be executed before.
 **
 ** \param [out] p_CompressedMsgPtr_pU8
 ** Pointer to the 16 byte long output buffer where
 ** the compressed text will be stored.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed and if we are called after update.
 ** - E_NOT_OK if any of the inputs / state is invalid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_CompressAesMpFinish(uint8* p_CompressedMsgPtr_pU8);

#if (VHSMCRYPT_CANCEL_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_CompressAesMpCancel
 **
 ** Cancels an ongoing vHsmCrypt_CompressAesMp operation.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - Always returns E_OK.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_CompressAesMpCancel(void);

#endif /* VHSMCRYPT_CANCEL_API */

/**
 ******************************************************************************
 ** \fn vHsmCrypt_CompressAesMp(const uint8* p_PlainTextPtr_pU8,
 **                             const uint32 p_PlainTextLength_U32,
 **                             uint8*       p_CompressedMsgPtr_pU8);
 **
 ** Performs plaintext compression by Miyaguchi-Preneel algorithm.
 ** Accepts input data which size is not zero and is multiple of 16.
 ** Works only in single call mode.
 **
 **
 ** \param [in] p_PlainTextPtr_pU8
 ** Pointer to the Plain Text to be compressed.
 ** Valid Range: full range.
 **
 ** \param [in] p_PlainTextLength_U32
 ** Length of the input Plain Text in bytes.
 ** Valid Range: n * 16 byte block, n = 0..0x1000000.
 **
 ** \param [out] p_CompressedMsgPtr_pU8
 ** Pointer to the 16 byte long output buffer where
 ** the compressed text will be stored.
 ** Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_CompressAesMp(const uint8* p_PlainTextPtr_pU8, const uint32 p_PlainTextLength_U32,
                        uint8* p_CompressedMsgPtr_pU8);

#endif /* VHSMCRYPT_COMPRESS_AES_MP_ENABLED */

/******************************************************************************
 RSA
 *****************************************************************************/
/* ToDo */

/******************************************************************************
 ECDSA
 *****************************************************************************/
#if (VHSMCRYPT_ECDSA_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_EcdsaVer
 **
 ** Function performs ECDSA verification operation.
 **
 ** \param p_SigPtr_pS [in]
 **           Pointer to the input signature structure
 **           which contains R and S components.
 **           Valid Range: full range.
 **
 ** \param p_PubKeyPtr_pS [in]
 **           Pointer to the key structure which contains
 **           X, Y and CurveId fields.
 **           Valid Range: full range.
 **
 ** \param p_HashPtr_pU8 [in]
 **           Pointer to the input hash to be verified.
 **           Valid Range: full range.
 **
 ** \param p_HashSize_U32 [in]
 **           Size of the input hash.
 **           Valid Range: 0..0xFFFFFFFF
 **
 ** \param p_VerResultPtr_pU8 [in]
 **           Pointer to the result of comparison.
 **           Valid range: HSMCRPT_ECDSAVER_VERIFICATION_OK if blocks are equal,
 **           otherwise HSMCRPT_ECDSAVER_VERIFICATION_NOT_OK.
 **
 *****************************************************************************/
FUNC (Std_ReturnType, CRYPT_CODE) vHsmCrypt_EcdsaVerFinish(const uint8 * p_xyPublicKey_pU8, const uint8 * p_rsSignature_pU8, const uint8 * p_MsgPtr_pU8, uint32 p_Msglen_U32,uint8 * output_buffer );
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_EcdsaVer(
        const struct ecdsa_sig * p_SigPtr_pS,
        const struct ec_point * p_PubKeyPtr_pS,
        const uint32 * const  p_HashPtr_pU8,
        const uint32     p_HashSize_U32,
        uint8 * const    p_VerResultPtr_pU8);
void test_ecdsa(void);

#endif /* VHSMCRYPT_ECDSA_ENABLED */

/******************************************************************************
 ED25519
 *****************************************************************************/
/* ToDo */

/******************************************************************************
 TRNG
 *****************************************************************************/
#if (VHSMCRYPT_TRNG_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_TrngRead(uint8* const p_DstPtr_pU8,
 **                        const uint8  p_SizeByte_U8);
 **
 ** If the output buffer size is equal or less to the available random data,
 ** the data will be copied to the buffer.
 ** If the output buffer size is larger, no data will be copied and
 ** the function returns an error.
 ** If the output buffer size is equal to zero, no data will be copied and
 ** the function returns an error.
 **
 ** \param [out] p_DstPtr_pU8
 ** Pointer to the memory to copy random data.
 ** Valid Range: full range.
 **
 ** \param [in] p_SizeByte_U8
 ** Requested size of random data in bytes.
 ** Valid Range: n = 0..(HSMCRPT_CFGINT_TRNG_BUFFER_SIZE_WORD << 2) byte.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if random data with requested size is available.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_TrngRead(uint8* const p_DstPtr_pU8, const uint8 p_SizeByte_U8);
/**
 ******************************************************************************
 ** \fn vHsmTrng_Init(void);
 **
 ** Initializes SA3UL TRNG engine
 **
 ** \return void
 ** This function returns void
 *****************************************************************************/
void vHsmTrng_Init(void);

#endif /* VHSMCRYPT_TRNG_ENABLED */

/******************************************************************************
 PRNG
 *****************************************************************************/
#if (VHSMCRYPT_PRNG_AES_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_PrngSeed(const uint8* p_EntropyPtr_pU8,
 **                        const uint32 p_EntropyLength_U32,
 **                        const uint8* p_KeyPtr_pU8,
 **                        uint8*       p_PrngKeyPtr_pU8,
 **                        uint8*       p_PrngStatePtr_pU8);
 **
 ** Performs seed generation for PRNG based on entropy data,
 ** a key and a PRNG state.
 **
 ** \param [in] p_EntropyPtr_pU8
 **                       Pointer to the Entropy.
 **                       Valid Range: full range.
 **
 ** \param [in] p_EntropyLength_U32
 **                       Length of the Entropy.
 **                       Valid Range: n * 16 byte block, n = 0..0x1000000.
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the 128 bit key.
 **                       Valid Range: full range.
 **
 ** \param [out] p_PrngKeyPtr_pU8
 **                       Pointer to the buffer for storage of calculated
 *PrngKey.
 **                       Valid buffer size: 16 bytes.
 **                       Valid Range: full range.
 **
 ** \param [inout] p_PrngStatePtr_pU8
 **                       Pointer to the PrngState.
 **                       Valid array size: 16 bytes.
 **                       Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if seed is valid and we were able to generate a key ptr and state
 **   ptr.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_PrngSeed(const uint8* p_EntropyPtr_pU8, const uint32 p_EntropyLength_U32, const uint8* p_KeyPtr_pU8,
                   uint8* p_PrngKeyPtr_pU8, uint8* p_PrngStatePtr_pU8);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_PrngGenerate(const uint8* p_PrngKeyPtr_pU8,
 **                            uint8*       p_PrngStatePtr_pU8);
 **
 ** Calculate a pseudo-random number based on an input state.
 ** The input state has to be initialized by the PRNG seeding function before
 ** first usage of this function.
 ** Returns 16 byte of random data in PrngState.
 **
 ** \param [in] p_PrngKeyPtr_pU8
 **                       Pointer to the PrngKey.
 **                       Valid array size: 16 bytes.
 **                       Valid Range: full range.
 **
 ** \param [inout] p_PrngStatePtr_pU8
 **                       Pointer to the PrngState.
 **                       After this function is called the value of PrngState
 **                       contains the new random number.
 **                       Valid array size: 16 bytes.
 **                       Valid Range: full range.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if we were able to generate a pseudo random number.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_PrngGenerate(const uint8* p_PrngKeyPtr_pU8, uint8* p_PrngStatePtr_pU8);

#endif /* VHSMCRYPT_PRNG_AES_ENABLED */

#if (VHSMCRYPT_AES_HMAC_SHA2_256 == STD_ON)
#if 0
/**
 ******************************************************************************
 ** \fnvHsmCrypt_Hmac_Sha2_256_Start(
 **   const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_U32)
 **
 ** Performs HMAC_SHA2-256 initialization. This function should be called
 ** before updation.
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the Key.
 **                       Valid Range: full range.
 **
 ** \param [in] p_KeyLength_U32
 **                       Length of p_KeyPtr_pU8.
 **                       Valid Range: full range except 0.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if we were able to generate a pseudo random number.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Hmac_Sha2_256_Start(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_U32,
                              Std_ReturnType (*p_ShaStart_pf)(void),
                              Std_ReturnType (*p_ShaUpdate_pf)(const uint8*, const uint32),
                              Std_ReturnType (*p_ShaFinish_pf)(uint8* const, const uint32));
/**
 ******************************************************************************
 ** \fn vHsmCrypt_HmacSha2_256_Update(
 **   const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32);
 **
 ** Performs HMAC message processing. Note, the vHsmCrypt_Hmac_Sha2_256_Start
 ** function has to be called before processing any data with this function.
 **
 ** \param [in] p_PlainTextPtr_pU8
 **                       Plain text over which HMAC has to be calculated.
 **                       Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 **                       Length of p_PlainTextPtr_pU8.
 **                       Valid Range: full range except 0.
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if Sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Hmac_Sha2_256_Update(const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                               Std_ReturnType (*p_ShaUpdate_pf)(const uint8*, const uint32));

/**
 ******************************************************************************
 ** \fn vHsmCrypt_HmacSha2_256_Finish(
 **   uint8* const p_Hmac_pU8);
 **
 ** HMAC: Keyed-Hashing for Message Authentication based on RFC 2104.
 **
 ** \param [in/out] p_Hmac_pU8
 **                       Calculated HMAC(SHA2-256).
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Hmac_Sha2_256_Finish(uint8* const p_Hmac_pU8, Std_ReturnType (*p_ShaStart_pf)(void),
                               Std_ReturnType (*p_ShaUpdate_pf)(const uint8*, const uint32),
                               Std_ReturnType (*p_ShaFinish_pf)(uint8* const, const uint32));
#endif
/**
 ******************************************************************************
 ** \fn vHsmCrypt_HmacSha2_256(
 **   const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_U32,
 **   const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
 **   uint8* const p_Hmac_pU8);
 **
 ** HMAC: Keyed-Hashing for Message Authentication based on RFC 2104.
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the Key.
 **                       Valid Range: full range.
 **
 ** \param [in] p_KeyLength_U32
 **                       Length of p_KeyPtr_pU8.
 **                       Valid Range: full range except 0.
 **
 ** \param [in] p_PlainTextPtr_pU8
 **                       Plain text over which HMAC has to be calculated.
 **                       Valid Range: full range.
 **
 ** \param [in] p_TextLength_U32
 **                       Length of p_PlainTextPtr_pU8.
 **                       Valid Range: full range except 0.
 **
 ** \param [in/out] p_Hmac_pU8
 **                       Calculated HMAC(SHA2-256).
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if we were able to generate a pseudo random number.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Hmac_Sha2_256(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_U32,
                        const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32, uint8* const p_Hmac_pU8,Std_ReturnType (*p_Sha_pf)(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                        const uint32 p_DigestLength_U32));
void test_hmac_sha2_256(void);
#endif /* VHSMCRYPT_AES_HMAC_SHA2_256 */
#if (VHSMCRYPT_PBKDF2_HMAC_SHA256 == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Pbkdf2_Hmac_Sha256(const uint8* const p_PasswordPtr_pU8,
 ** const uint32 p_PasswordLength_U32,const uint8* const p_SaltPtr_pU8,
 ** const uint32 p_SaltLength_U32, const uint32 p_Iteration_Count_U32,
 ** const uint8* const p_DigestPtr_pU8, const uint32 p_DkLength_U32);
 **
 ** PBKDF2- password based key derivation function version 2
 **
 ** \param [in] p_PasswordPtr_pU8
 **                       Pointer to the Password.
 **                       Valid Range: full range.
 **
 ** \param [in] p_PasswordLength_U32
 **                       Length of p_PasswordPtr_pU8.
 **                       Valid Range: Greater or equal to 32 bytes.
 **
 ** \param [in] p_SaltPtr_pU8
 **                       Pointer to the Salt.
 **                       Valid Range: full range.
 **
 ** \param [in] p_SaltLength_U32
 **                       Length of p_SaltPtr_pU8.
 **                       Valid Range: Min 16 bytes.
 **
 ** \param [in] p_Iteration_Count_U32
 **                       Iteration Count.
 **                       Valid Range: Greater than or equal to 1000.
 **
 ** \param [out] p_DigestPtr_pU8
 **                       Pointer to Derived Key.
 **
 ** \param [in] p_DkLength_U32
 **                       Length of the derived key.
 **                       Valid Range: Greater than 14 bytes
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if we were able to generate a pseudo random number.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Pbkdf2_Hmac_Sha256(const uint8* const p_PasswordPtr_pU8, const uint32 p_PasswordLength_U32,
        const uint8* const p_SaltPtr_pU8, const uint32 p_SaltLength_U32, const uint32 p_Iteration_Count_U32,
        uint8* const p_DigestPtr_pU8, const uint32 p_DkLength_U32);
#endif /*VHSMCRYPT_PBKDF2_HMAC_SHA256*/

#if (VHSMCRYPT_KDF_VKMS == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_KDF_Counter(uint8 p_RLength_U32, const uint8* const p_KeyPtr_pU8,
 ** uint32 p_KeyLength_U32, const uint8* const p_Label_pU8, uint32 p_LabelLength_U32,
 ** const uint8* const p_ContextPtr_pU8, uint32 p_ContextLength_U32, uint32 p_outLength_U32,
 ** const uint8* const p_outPtr_pU8)
 **
 ** Key Derivation Function in Counter mode for VKMS
 **
 ** \param [in] p_RLength_U32
 **                       Length of counter.
 **                       Valid Range: 1 byte to 4 bytes.
 **
 ** \param [in] p_KeyPtr_pU8
 **                       Pointer to the Key.
 **                       Valid Range: full range.
 **
 ** \param [in] p_KeyLength_U32
 **                       Length of p_KeyPtr_pU8.
 **                       Valid Range:Refer VKMS doc.
 **
 ** \param [in] p_Label_pU8
 **                       Pointer to the LABEL.
 **                       Value: "VKMS".
 **
 ** \param [in] p_LabelLength_U32
 **                       Length of p_Label_pU8.
 **                       Valid Range: 4 bytes.
 **
 ** \param [in] p_ContextPtr_pU8
 **                       Pointer to the Context.
 **                       Valid Range: Parameter set2.
 **
 ** \param [in] p_ContextLength_U32
 **                       Length of Context.
 **                       Valid Range: 4 bytes
 **
 ** \param [in] p_DerivedKeyLength_U32
 **                       Length of output pointer.
 **                       Valid Range: Full range.
 **
 ** \param [out] p_outPtr_pU8
 **                       pointer to derived key.
 **                       Valid Range: Greater than 14 bytes
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if we were able to erive key.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_KDF_Counter(uint8 p_CounterLength_U8, const uint8* const p_KeyPtr_pU8, uint32 p_KeyLength_U32,
                      const uint8* const p_Label_pU8, uint32 p_LabelLength_U32, const uint8* const p_ContextPtr_pU8,
                      uint32 p_ContextLength_U32, uint16 p_DerivedKeyLength_U16, uint8* const p_DerivedKey_pU8,
                      Std_ReturnType (*p_funcSHA2_fn)(const uint8*, const uint32, uint8*, const uint32));
FUNC(Std_ReturnType, CRYPT_CODE)
KDF_COUNTER(uint32 p_CounterLength_U32, const uint8* const p_KeyPtr_pU8, uint32 p_KeyLength_U32,
            const uint8* const p_Label_pU8, uint32 p_LabelLength_U32, const uint8* const p_ContextPtr_pU8,
            uint32 p_ContextLength_U32, uint32 p_DerivedKeyLength_U32, uint8* const p_DerivedKey_pU8);
#endif /*VHSMCRYPT_KDF_VKMS*/

#ifdef AUTEHENTICATED_DEBUG_ENABLE


/**
 ******************************************************************************
 ** \fn vHsmDAP_IpcNotifyInt_ISR(void);
 **
 ** Authenticated debug support in IPC channel 3, ISR notify for the same
 **
 **
 ** \param [in] None
 **
 ** \param [out] None
 **
 ** \return Std_ReturnType<br>
 ** This function returns:
 ** - E_OK if sanity check passed.
 ** - E_NOT_OK if any of the inputs were not valid.
 *****************************************************************************/
FUNC(void, CRYPT_CODE) vHsmDAP_IpcNotifyInt_ISR(void);

Std_ReturnType vHSM_LC_ReadUniqueID(void);

void vHSM_LC_Init(void);

Std_ReturnType vHSM_LC_TransitionToSecure(void);
Std_ReturnType vHSM_LC_NAR_setting(void);
Std_ReturnType vHSM_LC_TransitionToSecureWithDebug(void);

#endif /* AUTEHENTICATED_DEBUG_ENABLE */

#ifdef TVII_SECURE_BOOT_ENABLE
FUNC(Std_ReturnType, CRYPT_CODE) TOC2_Check(void);
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_M7_Authentication_BM(void);
FUNC(void, CRYPT_CODE) vHsmCrypt_M7_Authentication_BL_APP(void);
#endif

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_RSA_Verify(const uint8* p_RSAVerifyPackedData, uint8* output_buffer);
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_RSA_Verify_Start(uint8 p_keyId_U8);


#if (VHSMCRYPT_SIPHASH_24_ENABLED == STD_ON)
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_Start(uint32 p_jobid_pU32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_Update(uint8* p_MsgPtr_pU8,uint32 p_MsgLength_U32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_Finish(uint8* p_DigestPtr_pU8,uint32 p_DigestLength_U32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24(uint32 p_JobId_U32,uint8* p_MsgPtr_pU8, uint32 p_MsgLength_U32, uint8* p_DigestPtr_pU8,
                    uint32 p_DigestLength_U32);
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_MacVerify(uint32 p_keyId_U32,uint8* p_MsgPtr_pU8, uint32 p_MsgLength_U32, uint8* p_MacPtr_pU8,
                    uint32 p_MacLength_U32,uint8 * const  p_VerResultPtr_pU8);

#endif



#if (VHSMCRYPT_PRNG_AES_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_PrngSeedGenerate
 **
 ** To be invoked in main.c after init of crypto engine
 **
 ** This function returns none
 **
 ** \param [in] none
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_PrngSeedGenerate(void);

/**
 ******************************************************************************
 ** \fn vHsmCrypt_PrngRead
 **
 ** To be invoked in crypto application for M7 app needs
 **
 ** This function returns none
 **
 ** \param [in] none
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_PrngRead(uint8* const p_DstPtr_pU8, const uint8 p_SizeByte_U8);
#endif /* VHSMCRYPT_PRNG_AES_ENABLED */

#if (VHSMCRYPT_GET_AES_KEY_API == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_GetAESKey
 **
 ** To be invoked for getting the derived key for device key
 **
 ** This function returns none
 **
 ** \param [in] none
 **
 *****************************************************************************/
FUNC (uint8 , CRYPT_CODE) * vHsmCrypt_GetAESKey(void);
#endif /* VHSMCRYPT_GET_AES_KEY_API */
#if (VHSMCRYPT_ECDSA_ENABLED == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_Ed25519Ver
 **
 ** Function performs Ed25519 verification operation.
 **
 ** \param p_PubKeyPtr [in]
 **           Pointer to the public key.
 **           The public key has to be given in little-endian byte order.
 **           Key size must be 32 bytes.
 **           Valid Range: full range.
 **
 ** \param p_DigestPtr [in]
 **           Pointer to the input hash to be verified.
 **           Digest size must be 64 bytes.
 **           Valid Range: full range.
 **
 ** \param p_SigPtr [in]
 **           Pointer to the input hash to be verified.
 **           Valid Range: full range.
 **
 ** \param p_VerResultPtr_pU8 [in]
 **           Pointer to the result of comparison.
 **           Valid range: E_OK if blocks are equal,
 **           otherwise E_NOT_OK.
 **
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_Ed25519Ver(const uint8* const p_PubKeyPtr, const uint8* const p_DigestPtr, const uint8* const p_SigPtr,
                     uint8* const p_VerResultPtr);
FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Ed25519Id(uint8* p_outBuff_pU8);
FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Ed25519Verify(uint8 p_KeyId_U8,uint8* p_InputBuff_pU8,uint8* p_VerPtr_pU8);
FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_Sha2_512(const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32, uint8* const p_DigestPtr_pU8,
                   const uint32 p_DigestLength_U32);
void test_eddsa(void);
void test_aes(void);
#endif
#if (VHSMCRYPT_REFLASH_CRC == STD_ON)
/**
 ******************************************************************************
 ** \fn vHsmCrypt_ReflashCalculateCRC32
 **
 ** Function To Generate CRC for Given data
 **
 ** \param p_Crc_DataPtr_U8P [in]
 **           Pointer to the data for which the CRC to be calculated.
 **           Valid Range: full range.
 **
 ** \param p_CrcLength_U32 [in]
 **           Number of bytes to be taken for calculation.
 **           Valid Range: full range.
 **
 ** \param p_CrcStartValue_U32 [in]
 **           CRC Start value, if this is a continuation of 
**            previous CRC calculation. Crc_IsFirstCall shall be 
**            FALSE for this to be considered.
 **           Valid Range: full range.
 **
 ** \param p_CrcIsFirstCall [in]
 **           TRUE if this is the first call for CRC calculation. Start Value will be 0xFFFFFFFF.
**            FALSE if this is a continuation of precious CRC calculation.
 **  This function return the CRC
 **
 *****************************************************************************/
FUNC(uint32,CRYPT_CODE) vHsmCrypt_ReflashCalculateCRC32(const uint8 *p_Crc_DataPtr_U8P, uint32 p_CrcLength_U32, uint32 p_CrcStartValue_U32, boolean p_CrcIsFirstCall);

#endif
#endif /* VHSM_CRYPT_H */

/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the start of header file.
 *
 *  MODULE VERSION
 *  ---------------------------------------------------------------------------
 *  Refer to the VERSION INFORMATION SECTION in module's internal header file.
 ******************************************************************************/

/* EOF */
