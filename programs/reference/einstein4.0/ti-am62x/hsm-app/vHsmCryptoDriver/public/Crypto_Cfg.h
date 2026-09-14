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
 * \file Crypto_Cfg.h
 *
 * \brief
 *  Crypto Configuration header file in M7
 *
 * \detailed description
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                                      .......|
 * |--------|------------|----------|---------|---------------------------------------------------------|
*  |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation           |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

#include "Std_Types.h"
#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H 
/* Macro contains Total number of crypto job*/
#define TotalnoCryptoJob                                                12UL  //!< total number of crypto job
#define TotalnoCryptoKey                                                22uL
//#define TotalnoCryptoKey                                              18UL  //!< total number of crypto keys
/* Macro contains Job Id of crypto job*/
#define CryptoJobId_EncryptECB                                          0x00UL //!<  Macro contains the job Id of SHA256 Hash
#define CryptoJobId_RNG                                                 0x01UL //!<  Macro contains the job Id of ECC256 signature verify
#define CryptoJobId_ECC256_SignatureVerify                              0x02UL //!<  Macro contains the job Id of SIPHASH 2 4 macgen
#define CryptoJobId_SIPHASH_2_4_MACVerify                               0x03UL //!<  Macro contains the job Id of SIPHASH 2 4 mac verify
#define CryptoJobId_RNG1                                                 0x04UL //!<  Macro contains the job Id of RNG
#define CryptoJobId_VKMS_handleDLC_start                                0x05UL //!<  Macro contains the job Id of VMKS handle DLC start
#define CryptoJobId_VKMS_handleDLC_finish                               0x06UL //!<  Macro contains the job Id of VMKS handle DLC finish
#define CryptoJobId_VKMS_getVerificationHash                            0x07UL //!<  Macro contains the job Id of VKMS getverification Hash
#define CryptoJobId_VKMS_getIdentifyHash                                0x08UL //!<  Macro contains the job Id of VKMS get identify Hash
#define CryptoJobId_VKMS_getPssHash                                     0x09UL //!<  Macro contains the job Id of VKMS get PssHash
#define CryptoJobId_VKMS_MacGenerate                                    0x0AUL //!<  Macro contains the job Id of VKMS Mac generate
#define CryptoJobId_ECDSA_P384_SignGenerate_SHA2_256                    0x0BUL //!<  Macro contains the job Id of Signature generation with ECDSA P384 with SHA2 256 
#define CryptoJobId_ECDSA_P384_SignGenerate_SHA2_512                    0x0CUL //!<  Macro contains the job Id of Signature generation with ECDSA P384 with SHA2 512
#define CryptoJobId_ECDSA_P256_SignVerify_SHA2_512                      0x0DUL //!<  Macro contains the job Id of Signature verification with ECDSA P256 with SHA2 512
#define CryptoJobId_ECDSA_P384_SignVerify_SHA2_512                      0x0EUL //!<  Macro contains the job Id of Signature verification with ECDSA P384 with SHA2 512
#define CryptoJobId_HMAC_Verify_SHA2_512                                0x0FUL //!<  Macro contains the job Id of HMAC verification with SHA2 512
#define CryptoJobId_AES256_GCM_DEC                                      0x10UL //!<  Macro contains the job Id of GCM Decryption
#define CryptoJobId_AES256_CBC_DEC                                      0x11UL //!<  Macro contains the job Id of CBC Decryption
/* Macros contain the key ref ID of Crypto JOB*/
#define CryptochannelKeyID_EncryptECB                                   0x00UL //!<  Macro contains the key Id of RSA Hash
#define CryptochannelKeyID_RSA_SignatureGen                             0x05UL //!<  Macro contains the key Id of RSA SignatureGen 
#define CryptochannelKeyID_ECC256_SignatureVerify                       0x02UL //!<  Macro contains the key Id of ECC256 SignatureVerify
#define CryptochannelKeyID_SIPHASH_2_4_MACGEN                           0x03UL //!<  Macro contains the key Id of SIPHASH_2_4_MACGEN 
#define CryptochannelKeyID_SIPHASH_2_4_MACVerify                        0x04UL //!<  Macro contains the key Id of SIPHASH_2_4_MACVerify
#define CryptochannelKeyID_RNG                                          0x01UL //!<  Macro contains the key Id of RNG
#define CryptochannelKeyID_VKMS_handleDLC_start                         0x06UL //!<  Macro contains the key Id of VKMS handleDLC start
#define CryptochannelKeyID_VKMS_handleDLC_finish                        0x07UL //!<  Macro contains the key Id of VKMS handleDLC finish
#define CryptochannelKeyID_VKMS_getVerificationHash                     0x08UL //!<  Macro contains the key Id of VKMS getVerificationHash
#define CryptochannelKeyID_VKMS_getIdentifyHash                         0x09UL //!<  Macro contains the key Id of VKMS getIdentifyHash
#define CryptochannelKeyID_VKMS_getPssHash                              0x0AUL //!<  Macro contains the key Id of VKMS getPssHash
#define CryptochannelKeyID_VKMS_MacGenerate                             0x0BUL //!<  Macro contains the key Id of VKMS MacGenerate
#define CryptochannelKeyID_VKMS_VKMSKey1                                0x0CUL //!<  Macro contains the key Id of VKMS VKMSKey1
#define CryptochannelKeyID_VKMS_VKMSKey2                                0x0DUL //!<  Macro contains the key Id of VKMS VKMSKey2
#define CryptochannelKeyID_VKMS_getMetadata                             0x0EUL //!<  Macro contains the key Id of VKMS getMetadata
#define CryptochannelKeyID_VKMS_getstatus                               0x0FUL //!<  Macro contains the key Id of VKMS_getstatus
#define CryptochannelKeyID_VKMS_getTrainingCounter                      0x10UL //!<  Macro contains the key Id of VKMS getTrainingCounter 
#define CryptochannelKeyID_VKMS_getVkmsVIN                              0x11UL //!<  Macro contains the key Id of VKMS getVkmsVIN
#define CryptochannelKeyID_ECDSA_P384_SignGenerate_SHA2_256             0x12UL //!<  Macro contains the key Id of Signature generation with ECDSA P384 with SHA2 256
#define CryptochannelKeyID_ECDSA_P384_SignGenerate_SHA2_512             0x13UL //!<  Macro contains the key Id of Signature generation with ECDSA P384 with SHA2 512
#define CryptochannelKeyID_ECDSA_P256_SignVerify_SHA2_512               0x14UL //!<  Macro contains the key Id of Signature Verification with ECDSA P256 with SHA2 512
#define CryptochannelKeyID_ECDSA_P384_SignVerify_SHA2_512               0x15UL //!<  Macro contains the key Id of Signature Verification with ECDSA P384 with SHA2 512
#define CryptochannelKeyID_HMAC_Verify_SHA2_512                         0x16UL //!<  Macro contains the key Id of HMAC Verification with SHA 512
#define CryptochannelKeyID_AES256_GCM_DEC                               0x18UL //!<  Macro contains the key Id of GCM Decryption
#define CryptochannelKeyID_AES256_CBC_DEC                               0x19UL //!<  Macro contains the key Id of CBC Decryption
/* Macros contain the key slot ID of Crypto JOB*/
#define CryptoKeyID_RSA_Hash                                            0x20UL //!<  Macro contains the key slot Id of RSA Hash
#define CryptoKeyID_RSA_SignatureGen                                    0x01UL //!<  Macro contains the key slot Id of RSA SignatureGen 
#define CryptoKeyID_ECC256_SignatureVerify                              0xFFUL //!<  Macro contains the key slot Id of ECC256 SignatureVerify
#define CryptoKeyID_SIPHASH_2_4_MACGEN                                  0xFEUL //!<  Macro contains the key slot Id of SIPHASH_2_4_MACGEN
#define CryptoKeyID_SIPHASH_2_4_MACVerify                               0xFEUL //!<  Macro contains the key slot Id of SIPHASH_2_4_MACVerify
#define CryptoKeyID_RNG                                                 0xFFUL //!<  Macro contains the key slot Id of RNG
#define CryptoKeyID_VKMS_handleDLC_start                                0x02UL //!<  Macro contains the key slot Id of VKMS handleDLC start
#define CryptoKeyID_VKMS_handleDLC_finish                               0x02UL //!<  Macro contains the key slot Id of VKMS handleDLC finish
#define CryptoKeyID_VKMS_getVerificationHash                            0x02UL //!<  Macro contains the key slot Id of VKMS getVerificationHash
#define CryptoKeyID_VKMS_getIdentifyHash                                0x02UL //!<  Macro contains the key slot Id of VKMS getIdentifyHash
#define CryptoKeyID_VKMS_getPssHash                                     0x02UL //!<  Macro contains the key slot Id of  VKMS getPssHash
#define CryptoKeyID_VKMS_MacGenerate                                    0x02UL //!<  Macro contains the key slot Id of VKMS MacGenerate
#define CryptoKeyID_VKMS_VKMSKey1                                       0x01UL //!<  Macro contains the key slot Id of VKMS VKMSKey1
#define CryptoKeyID_VKMS_VKMSKey2                                       0x28BUL //!<  Macro contains the key slot Id of VKMS VKMSKey2
#define CryptoKeyID_VKMS_getMetadata                                    0x00UL //!<  Macro contains the key slot Id of VKMS getMetadata
#define CryptoKeyID_VKMS_getstatus                                      0xFFUL //!<  Macro contains the key slot Id of VKMS_getstatus
#define CryptoKeyID_VKMS_getTrainingCounter                             0xFFUL //!<  Macro contains the key slot Id of VKMS getTrainingCounter 
#define CryptoKeyID_VKMS_getVkmsVIN                                     0xFFUL //!<  Macro contains the key slot Id of getVkmsVIN

#define ElemID_VKMS_getkey_VIN                                          0xF0010001UL //!<  Macro contains the key Elem Id of VKMS getkey VIN  
#define ElemID_VKMS_Metadata_TrainingCounter                            0xF0010002UL //!<  Macro contains the key Elem Id of VKMS Metadata TrainingCounter 
#define ElemID_VKMS_VKMS_getstatus                                      0xF0010003UL //!<  Macro contains the key Elemt Id of VKMS VKMS getstatus 
#define  Cry_VKMS_handleDLC_start             0x01u //!<  Macro contains the key of VKMS handleDLC start
#define  Cry_VKMS_handleDLC_finish            0x02u //!<  Macro contains the key of VKMS handleDLC finish
#define  Cry_VKMS_getVerificationHash         0x03u //!<  Macro contains the key of VKMS getVerificationHash
#define  Cry_VKMS_getIdentityHash             0x04u //!<  Macro contains the key of VKMS getIdentityHash
#define  Cry_VKMS_getPssHash                  0x05u //!<  Macro contains the key of VKMS getPssHash 


#define  Cry_VKMS_getkey                     0x06u //!<  Macro contains the key of VKMS getkey
#define  Cry_VKMS_getMetadata                0x07u //!<  Macro contains the key of VKMS Metadata
#define  Cry_VKMS_getstatus                  0x08u //!<  Macro contains the key of VKMS_getstatus
#define  Cry_VKMS_getTrainingCounter         0x09u //!<  Macro contains the key of VKMS getTrainingCounter
#define  Cry_VKMS_getVkmsVIN                 0x0Au //!<  Macro contains the key of getVkmsVIN




#define HASH_MAX_SUPPORT_LENGTH                       448U        //!< Maximum hash length supported by M0
#define MAX_ECDSA_SIGNVERIFY_KEYLENGTH                64U         //!< Maximum ECDSA Sign verify keylength 
#define CRYPTO4DOT3_INIT                                (uint8)0       //!<  Macro contains the Cryto init value
#define CRYPTO4DOT3_UNINIT                              (uint8)1        //!<  Macro contains the Cryto uninit value
#define CRYPTO4DOT3_JOB_IDLE                            (uint8)0       //!<  Macro contains the Cryto job idle stae value
#define CRYSHE_CALLBACK_OK                         (uint8)1       //!<  Macro contains the CRYSHE callback status
#define CRYSHE_CALLBACK_NOT_OK                     (uint8)2       //!<  Macro contains the CRYSHE callback status


/* Macros contain the Cryto error check value*/
# define CRYPTO_WRAPPER_E_NO_ERROR                          (0xFFu) //!<  used to check if no error occurred - use a value unequal to any error code 
# define CRYPTO_WRAPPER_E_UNINIT                            (0x00u) //!< API service used without module initialization 
# define CRYPTO_WRAPPER_E_PARAM_POINTER                     (0x02u) //!< API request called with invalid parameter (null pointer) 
# define CRYPTO_WRAPPER_E_PARAM_VALUE                       (0x04u) //!< API request called with invalid parameter (invalid value) 

//#define VENDOR_ID                      1U
//#define MODULE_ID                      2U
#define MAJOR_VERSION                  1U
#define MINOR_VERSION                  1U
#define PATCH_VERSION                  0U

/* Define Service Finish Notification functions for CSM */
#define CRYPTO_CSM_ECDSAVERIFY_SERVICE_FINISH_NOTIF

#define VCSM_E_OK                                  0
#define VCSM_E_NOT_OK                              1
#if 0
#define CRYPTO_INIT                                0
#define CRYPTO_UNINIT                              1
#define CRYPTO_JOB_IDLE                            0
#define CRYSHE_CALLBACK_OK                         1
#define CRYSHE_CALLBACK_NOT_OK                     2
#define SINGLE_CALLMODE_SET                        1
#define SINGLE_CALLMODE_NOT_SET                    0
#endif

#define HASH_MAX_SUPPORT_LENGTH                                                448U

# define CRYPTO_E_NO_ERROR                          (0xFFu) /* used to check if no error occurred - use a value unequal to any error code */
# define CRYPTO_E_UNINIT                            (0x00u) /* API service used without module initialization */
# define CRYPTO_E_INIT_FAILED                       (0x01u) /* Initialisation of CRYPTO module failed */
# define CRYPTO_E_PARAM_POINTER                     (0x02u) /* API request called with invalid parameter (null pointer) */
# define CRYPTO_E_PARAM_HANDLE                      (0x03u) /* API request called with invalid parameter (out of range) */
# define CRYPTO_E_PARAM_VALUE                       (0x04u) /* API request called with invalid parameter (invalid value) */
# define CRYPTO_E_ALREADY_INITIALIZED               (0x11u) /* The service Crypto_Init() is called while the module is already initialized */

#define CRYPTO_DEV_ERROR_REPORT    STD_OFF
#define CRYPTO_DET_REPORTERROR(API_ID, ERRORID)

#define CRYPTO_INIT_ID            0x00
#define CRYPTO_PROCESSJO_ID       0x03
#define CRYPTO_CANCEL_ID          0x0E
#define CRYPTO_KEYSET_ID          0x04
#define CRYPTO_KEYVALIDSET_ID     0x05
#define CRYPTO_KEYGET_ID          0x06

#define TotalnoCryptoChannel   18u

/**
 * structure for Crypto_KeyType
 */
typedef struct Crypto_KeyType
{
  uint32 RefOfKey; /**< refofkey */
} Crypto_KeyType;


/**
 * crypto keytype
 */
extern const Crypto_KeyType crypto_Key[TotalnoCryptoKey]; 

#define VENDOR_ID                                 0x33u
#define MODULE_ID                                 114u
#define MAJOR_VERSION                             1U
#define MINOR_VERSION                             1U
#define PATCH_VERSION                             0U

#define CRYPTO_INIT                                0
#define CRYPTO_UNINIT                              1

#define CRYPTO_JOB_IDLE                            ((uint8)0)

#define CRYPTO_CALLBACK_OK                         ((uint8)1)
#define CRYPTO_CALLBACK_NOT_OK                     ((uint8)2)



# define CRYPTO_E_NO_ERROR                          (0xFFu) /* used to check if no error occurred - use a value unequal to any error code */
# define CRYPTO_E_UNINIT                            (0x00u) /* API service used without module initialization */
# define CRYPTO_E_INIT_FAILED                       (0x01u) /* Initialisation of CRYPTO module failed */
# define CRYPTO_E_PARAM_POINTER                     (0x02u) /* API request called with invalid parameter (null pointer) */
# define CRYPTO_E_PARAM_HANDLE                      (0x03u) /* API request called with invalid parameter (out of range) */
# define CRYPTO_E_PARAM_VALUE                       (0x04u) /* API request called with invalid parameter (invalid value) */
# define CRYPTO_E_ALREADY_INITIALIZED               (0x11u) /* The service Crypto_Init() is called while the module is already initialized */

#define TOTAL_NO_4dot2CSMJOB                                             10uL
#define Totalno4dot2CryptoKey                                            13uL
#define Totalno4dot2CryptoJob                                            22uL

#define CryptoJobId_SYMBLK_ENCRYPT                                   1U
#define CryptoJobId_SYMBLK_DECRYPT                                   2U
#define CryptoJobId_AES_CMACGEN                                      3U
#define CryptoJobId_AES_CMACVERIFY                                   4U
#define CryptoJobId_CBC_ENCRYPT                                      5U
#define CryptoJobId_CBC_DECRYPT                                      6U
#define CryptoJobId_RNG_SEED                                         7U
#define CryptoJobId_RNG_GEN                                          8U
#define CryptoJobId_SYMKEYEXTRACT                                    9U

#define CryptoKeyId_RNG                                              0U
#define CryptoKeyId_RNG_SEED                                         1U
#define CryptoKeyId_AES_CMACGEN                                      2U
#define CryptoKeyId_AES_CMACVERIFY                                   3U
#define CryptoKeyId_SYMBLK_ENCRYPT                                   4U
#define CryptoKeyId_SYMBLK_DECRYPT                                   5U
#define CryptoKeyId_CBC_ENCRYPT                                      6U
#define CryptoKeyId_CBC_DECRYPT                                      7U
#define CryptoKeyId_SYMKEYEXTRACT                                    8U

#define HASH_MAX_SUPPORT_LENGTH                                      448U

//#define TOTAL_NO_CSMJOB                                             10U
#define TotalnoCryptoKey                                            22uL
//#define TotalnoCryptoJob                                            10U

#define CryptoConf_CryptoDriverObject_CryptoDriverObject            0uL

#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_0_KeyManagement    	0x20uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_1_KeyManagement	  	1uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_2_KeyManagement    	2uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_3_KeyManagement    	3uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_4_KeyManagement    	4uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_5_KeyManagement	  	5uL
#define	CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_6_KeyManagement	  	6uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_7_KeyManagement	    7uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_8_KeyManagement		8uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_9_KeyManagement		9uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_10_KeyManagement		10uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_11_KeyManagement		11uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_12_KeyManagement		12uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_13_KeyManagement		13uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_14_KeyManagement     14uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_15_KeyManagement     15uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_16_KeyManagement     16uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_17_KeyManagement     17uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_18_KeyManagement     18uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_19_KeyManagement     19uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_20_KeyManagement     20uL
#define CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_255_KeyManagement    21uL

#define CRYPTO_WA_DENIED                0x01
#define CRYPTO_WA_INTERNAL_COPY         0x02
#define CRYPTO_WA_ALLOWED               0x03
#define CRYPTO_WA_ENCRYPTED             0x04


//#define CSM_HASH_API                           STD_OFF
#define CSM_MACGENERATE_API                    STD_OFF
#define CSM_MACVERIFY_API                      STD_OFF
#define CSM_RANDOMGENERATE_API                 STD_ON
#define CSM_RANDOMSEED_API                     STD_OFF
#define CSM_ENCRYPT_API                        STD_ON
#define CSM_SYM_BLOCK_ENCRYPT_API              STD_ON
//#define CSM_DECRYPT_API                        STD_OFF
#define CSM_SYM_BLOCK_DECRYPT_API              STD_OFF
#define CSM_SYM_KEY_EXTRACT_API                STD_OFF         
#define CRYPTO_PRIORITY_ENABLED                STD_OFF
#define SINGLE_CALLMODE_SET                        (uint8)1       //!<  Macro contains the single call mode status
#define SINGLE_CALLMODE_NOT_SET                    (uint8)0       //!<  Macro contains the single call mode status
typedef enum
{
   CSM_E_VER_OK,
   CSM_E_VER_NOT_OK
}
Csm_VerifyResultType;

typedef enum
{
   CSM_E_OK,
   CSM_E_NOT_OK,
   CSM_E_BUSY,
   CSM_E_SMALL_BUFFER,
   CSM_E_ENTROPY_EXHAUSTION,
   CSM_E_KEY_NOT_AVAILABLE
}
Csm_ReturnType;

typedef struct
{
  uint32 length;
  uint32 data;
} Csm_SymKeyType;

/* Define the below macro to 1 if the cancel command is used in the system */
#define CRYPTO_CANCEL_ENABLED 1

#endif     /* CRYPTO_CFG_H */
