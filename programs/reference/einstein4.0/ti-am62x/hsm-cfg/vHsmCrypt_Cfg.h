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
 * \file vHsmCrypt_Cfg.h
 *
 * \brief
 * Visteon HSM Crypto Driver Configuration File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

/*****************************************************************************
 *  HEADER FILE GUARD
 *****************************************************************************/
#ifndef VHSMCRYPT_CFG_H
#define VHSMCRYPT_CFG_H

/*****************************************************************************
 *  PRE COMPILED MACROS
 *****************************************************************************/
#define VHSMCRYPT_BLOBS_ENABLED
/**
 ******************************************************************************
 ** \def VHSMCRYPT_DEV_ERROR_DETECT
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) detection of development
 *errors.
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_DEV_ERROR_DETECT
#define VHSMCRYPT_DEV_ERROR_DETECT STD_OFF
#else /* defined(VHSMCRYPT_DEV_ERROR_DETECT) */
#error "VHSMCRYPT_DEV_ERROR_DETECT already defined"
#endif /* !defined(VHSMCRYPT_DEV_ERROR_DETECT) */

/****************
 * FEATURES
 ***************/
/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_ECB_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *ECB APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_2. */
#ifndef VHSMCRYPT_AES_ECB_ENABLED
#define VHSMCRYPT_AES_ECB_ENABLED STD_ON
#else /* defined(VHSMCRYPT_AES_ECB_ENABLED) */
#error "VHSMCRYPT_AES_ECB_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_ECB_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_CBC_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *CBC APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_3. */
#ifndef VHSMCRYPT_AES_CBC_ENABLED
#define VHSMCRYPT_AES_CBC_ENABLED STD_ON
#else /* defined(VHSMCRYPT_AES_CBC_ENABLED) */
#error "VHSMCRYPT_AES_CBC_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_CBC_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_CTR_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *CTR APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_4. */
#ifndef VHSMCRYPT_AES_CTR_ENABLED
#define VHSMCRYPT_AES_CTR_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_AES_CTR_ENABLED) */
#error "VHSMCRYPT_AES_CTR_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_CTR_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_CMAC_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *CMAC APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_5. */
#ifndef VHSMCRYPT_AES_CMAC_ENABLED
#define VHSMCRYPT_AES_CMAC_ENABLED STD_ON.
#else /* defined(VHSMCRYPT_AES_CMAC_ENABLED) */
#error "VHSMCRYPT_AES_CMAC_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_CMAC_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_GCM_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *GCM APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_6. */
#ifndef VHSMCRYPT_AES_GCM_ENABLED
#define VHSMCRYPT_AES_GCM_ENABLED STD_ON
#else /* defined(VHSMCRYPT_AES_GCM_ENABLED) */
#error "VHSMCRYPT_AES_GCM_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_GCM_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of AES
 *Calculation of Decryption Keys APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_1_7. */
#ifndef VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED
#define VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED) */
#error "VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_AES_CALC_DECRYPTION_KEY_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_SHA2_256_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of SHA2
 *256 APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_2_1. */
#ifndef VHSMCRYPT_SHA2_256_ENABLED
#define VHSMCRYPT_SHA2_256_ENABLED STD_ON
#else /* defined(VHSMCRYPT_SHA2_256_ENABLED) */
#error "VHSMCRYPT_SHA2_256_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_SHA2_256_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_SHA1_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of SHA2
 *256 APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_2_1. */
#ifndef VHSMCRYPT_SHA1_ENABLED
#define VHSMCRYPT_SHA1_ENABLED STD_ON
#else /* defined(VHSMCRYPT_SHA1_ENABLED) */
#error "VHSMCRYPT_SHA1_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_SHA1_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_SHA2_512_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of SHA2
 *512 APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_2_2. */
#ifndef VHSMCRYPT_SHA2_512_ENABLED
#define VHSMCRYPT_SHA2_512_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_SHA2_512_ENABLED) */
#error "VHSMCRYPT_SHA2_512_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_SHA2_512_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_SHA3_256_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of SHA3
 *256 APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_2_3. */
#ifndef VHSMCRYPT_SHA3_256_ENABLED
#define VHSMCRYPT_SHA3_256_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_SHA3_256_ENABLED) */
#error "VHSMCRYPT_SHA3_256_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_SHA3_256_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_COMPRESS_AES_MP_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 *Miyaguchi Praneel APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_2_4. */
#ifndef VHSMCRYPT_COMPRESS_AES_MP_ENABLED
#define VHSMCRYPT_COMPRESS_AES_MP_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_COMPRESS_AES_MP_ENABLED) */
#error "VHSMCRYPT_COMPRESS_AES_MP_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_COMPRESS_AES_MP_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_RSA_EXP_65537_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of RSA
 * APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_3_1. */
#ifndef VHSMCRYPT_RSA_EXP_65537_ENABLED
#define VHSMCRYPT_RSA_EXP_65537_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_RSA_EXP_65537_ENABLED) */
#error "VHSMCRYPT_RSA_EXP_65537_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_RSA_EXP_65537_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_ECDSA_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of RSA
 * APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_3_2. */
#ifndef VHSMCRYPT_ECDSA_ENABLED
#define VHSMCRYPT_ECDSA_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_ECDSA_ENABLED) */
#error "VHSMCRYPT_ECDSA_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_ECDSA_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_ED25519_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of RSA
 * APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_3_3. */
#ifndef VHSMCRYPT_ED25519_ENABLED
#define VHSMCRYPT_ED25519_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_ED25519_ENABLED) */
#error "VHSMCRYPT_ED25519_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_ED25519_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_TRNG_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of TRNG
 *APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_4_1. */
#ifndef VHSMCRYPT_TRNG_ENABLED
#define VHSMCRYPT_TRNG_ENABLED STD_ON
#else /* defined(VHSMCRYPT_TRNG_ENABLED) */
#error "VHSMCRYPT_TRNG_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_TRNG_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_PRNG_AES_ENABLED
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of PRNG
 *AES APIs
 **
 *****************************************************************************/
/* Satisfies SWS_VHSMCRYPT_BSW_4_2_4_2. */
#ifndef VHSMCRYPT_PRNG_AES_ENABLED
#define VHSMCRYPT_PRNG_AES_ENABLED STD_OFF
#else /* defined(VHSMCRYPT_PRNG_AES_ENABLED) */
#error "VHSMCRYPT_PRNG_AES_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_PRNG_AES_ENABLED) */

/****************
 * APIs
 ***************/
/**
 ******************************************************************************
 ** \def VHSMCRYPT_VERSION_INFO_API
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 *Version Info APIs
 **
 *****************************************************************************/
/* Satisfies SWS_BSW_00051. */
#ifndef VHSMCRYPT_VERSION_INFO_API
#define VHSMCRYPT_VERSION_INFO_API STD_OFF
#else /* defined(VHSMCRYPT_VERSION_INFO_API) */
#error "VHSMCRYPT_VERSION_INFO_API already defined"
#endif /* !defined(VHSMCRYPT_VERSION_INFO_API) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_INIT_API
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of INIT
 *and DE-INIT APIs
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_INIT_API
#define VHSMCRYPT_INIT_API STD_OFF
#else /* defined(VHSMCRYPT_INIT_API) */
#error "VHSMCRYPT_INIT_API already defined"
#endif /* !defined(VHSMCRYPT_INIT_API) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_CANCEL_API
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 *Cancel API.
 **
 *****************************************************************************/
/* Satisfies ECUC_Spi_00226. */
#ifndef VHSMCRYPT_CANCEL_API
#define VHSMCRYPT_CANCEL_API STD_OFF
#else /* defined(VHSMCRYPT_CANCEL_API) */
#error "VHSMCRYPT_CANCEL_API already defined"
#endif /* !defined(VHSMCRYPT_CANCEL_API) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_HW_STATUS_API
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of HW
 *Status
 ** API.
 **
 *****************************************************************************/
/* Satisfies ECUC_Spi_00229. */
#ifndef VHSMCRYPT_HW_STATUS_API
#define VHSMCRYPT_HW_STATUS_API STD_OFF
#else /* defined(VHSMCRYPT_HW_STATUS_API) */
#error "VHSMCRYPT_HW_STATUS_API already defined"
#endif /* !defined(VHSMCRYPT_HW_STATUS_API) */

#ifndef VHSMCRYPT_SIPHASH_24_ENABLED
#define VHSMCRYPT_SIPHASH_24_ENABLED STD_ON
#else /* defined(VHSMCRYPT_SIPHASH_24_ENABLED) */
#error "VHSMCRYPT_SIPHASH_24_ENABLED already defined"
#endif /* !defined(VHSMCRYPT_SIPHASH_24_ENABLED) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_AES_HMAC_SHA2_256
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 **  HMCA with SHA 256 API.
 **
 *****************************************************************************/
/* Satisfies ECUC_Spi_00229. */
#ifndef VHSMCRYPT_AES_HMAC_SHA2_256
#define VHSMCRYPT_AES_HMAC_SHA2_256 STD_ON
#else /* defined(VHSMCRYPT_AES_HMAC_SHA2_256) */
#error "VHSMCRYPT_AES_HMAC_SHA2_256 already defined"
#endif /* !defined(VHSMCRYPT_AES_HMAC_SHA2_256) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_PBKDF2_HMAC_SHA256
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 **  PBKDF2 with HMAC_SHA 256 API.
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_PBKDF2_HMAC_SHA256
#define VHSMCRYPT_PBKDF2_HMAC_SHA256 STD_ON
#else /* defined(VHSMCRYPT_PBKDF2_HMAC_SHA256) */
#error "VHSMCRYPT_PBKDF2_HMAC_SHA256 already defined"
#endif /* !defined(VHSMCRYPT_PBKDF2_HMAC_SHA256) */


/**
 ******************************************************************************
 ** \def VHSMCRYPT_KDF_VKMS
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 **  KDF in counter Mode VKMS.
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_KDF_VKMS
#define VHSMCRYPT_KDF_VKMS STD_OFF
#else /* defined(VHSMCRYPT_KDF_VKMS) */
#error "VHSMCRYPT_KDF_VKMS already defined"
#endif /* !defined(VHSMCRYPT_KDF_VKMS) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_GET_AES_KEY_API
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 **  GET AES KEY.
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_GET_AES_KEY_API
#define VHSMCRYPT_GET_AES_KEY_API STD_OFF
#else /* defined(VHSMCRYPT_GET_AES_KEY_API) */
#error "VHSMCRYPT_GET_AES_KEY_API already defined"
#endif /* !defined(VHSMCRYPT_GET_AES_KEY_API) */

/**
 ******************************************************************************
 ** \def VHSMCRYPT_REFLASH_CRC
 **
 ** \brief To activate (STD_ON) or deactivate (STD_OFF) the availability of
 **  CRC generator for Reflashing.
 **
 *****************************************************************************/
#ifndef VHSMCRYPT_REFLASH_CRC
#define VHSMCRYPT_REFLASH_CRC STD_OFF
#else /* defined(VHSMCRYPT_REFLASH_CRC) */
#error "VHSMCRYPT_REFLASH_CRC already defined"
#endif /* !defined(VHSMCRYPT_REFLASH_CRC) */

#endif /* !defined(VHSMCRYPT_CFG_H) */
/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the module's public header file.
 *
 *  MODULE VERSION
 *  ---------------------------------------------------------------------------
 *  Refer to the VERSION INFORMATION SECTION in module's internal header file.
 ******************************************************************************/

/* EOF */
