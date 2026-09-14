/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2021] Visteon Corporation
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
 * \file CryptoCdd.h
 *
 * \brief
 * Main Implementation of Crypto CDD which is a wrapper for the Open Source
 * Apache 2 MbedTLS.
 *
 * \version 1.1.0
 * |Version | Date       | Author   | Task Id | Description                                                           |
 * |--------|------------|----------|---------|-----------------------------------------------------------------------|
 * |1.00.00 | 2021-07-01 | akrish10 | 1382482 | Implement RSAES-OAEP, RSASSA-PSS, RSASSA-PKCS1v1_5.                   |
 * |1.01.00 | 2021-07-02 | akrish10 | 1382482 | Implement Pseudo Random Number Generator.                             |
 * |1.01.01 | 2021-07-05 | akrish10 | 1382482 | Fix verification result updated only in Retval and not in verptr.     |
 * |1.02.00 | 2021-07-28 | akrish10 | 1382482 | Fix sanity checks.                                                    |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          James, Sneha (S.)        | sjames4   | VTSC, Bengaluru, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *
 ******************************************************************************/

/******************************************************************************
 *  HEADER FILE GUARD
 *****************************************************************************/
#ifndef CRYPTOCDD_H
#define CRYPTOCDD_H

/******************************************************************************
 *  INCLUDE
 *****************************************************************************/
#include "Std_Types.h" /* [SWS_BSW_00024] */

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#if (defined CRYPTOCDD_CODE) /* to prevent double definition */
#error CRYPTOCDD_CODE already defined
#endif /* if defined CRYPTOCDD_CODE */

/** \brief definition of the code memory class
**
** To be used for code. */
#define CRYPTOCDD_CODE

#if (defined CRYPTOCDD_CODE_FAST) /* to prevent double definition */
#error CRYPTOCDD_CODE_FAST already defined
#endif /* if defined CRYPTOCDD_CODE_FAST */

/** \brief definition of the code memory class
**
** To be used for code that shall go into fast code memory segments. */
#define CRYPTOCDD_CODE_FAST

#if (defined CRYPTOCDD_CODE_SLOW) /* to prevent double definition */
#error CRYPTOCDD_CODE_SLOW already defined
#endif /* if defined CRYPTOCDD_CODE_SLOW */

/** \brief definition of the code memory class
**
** To be used for code that shall go into slow code memory segments. */
#define CRYPTOCDD_CODE_SLOW

#if (defined CRYPTOCDD_CONFIG_DATA) /* to prevent double definition */
#error CRYPTOCDD_CONFIG_DATA already defined
#endif /* if defined CRYPTOCDD_CONFIG_DATA */

/** \brief definition of the constant memory class
**
** To be used for module configuration constants. */
#define CRYPTOCDD_CONFIG_DATA

#if (defined CRYPTOCDD_CONST) /* to prevent double definition */
#error CRYPTOCDD_CONST already defined
#endif /* if defined CRYPTOCDD_CONST */

/** \brief definition of the constant memory class
**
** To be used for global or static constants. */
#define CRYPTOCDD_CONST

#if (defined CRYPTOCDD_CONST_SAVED_RECOVERY_ZONE) /* to prevent double definition */
#error CRYPTOCDD_CONST_SAVED_RECOVERY_ZONE already defined
#endif /* if defined CRYPTOCDD_CONST_SAVED_RECOVERY_ZONE */

/** \brief definition of the constant memory class
**
** To be used for ROM buffers of variables saved in non-volatile memory. */
#define CRYPTOCDD_CONST_SAVED_RECOVERY_ZONE

#if (defined CRYPTOCDD_INTERNAL_VAR_NO_INIT) /* to prevent double definition */
#error CRYPTOCDD_INTERNAL_VAR_NO_INIT already defined
#endif /* if defined CRYPTOCDD_INTERNAL_VAR_NO_INIT */

/** \brief definition of the variable memory class
**
** To be used for global or static variables which are accessible from a calibration
** tool, which are never cleared and never initialized. */
#define CRYPTOCDD_INTERNAL_VAR_NO_INIT

#if (defined CRYPTOCDD_INTERNAL_VAR_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_INTERNAL_VAR_CLEARED already defined
#endif /* if defined CRYPTOCDD_INTERNAL_VAR_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for global or static variables which are accessible from a calibration
** tool, which are cleared to zero after every reset. */
#define CRYPTOCDD_INTERNAL_VAR_CLEARED

#if (defined CRYPTOCDD_INTERNAL_VAR_POWER_ON_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_INTERNAL_VAR_POWER_ON_CLEARED already defined
#endif /* if defined CRYPTOCDD_INTERNAL_VAR_POWER_ON_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for global or static variables which are accessible from a calibration
** tool, which are cleared to zero only after power on reset. */
#define CRYPTOCDD_INTERNAL_VAR_POWER_ON_CLEARED

#if (defined CRYPTOCDD_INTERNAL_VAR_INIT) /* to prevent double definition */
#error CRYPTOCDD_INTERNAL_VAR_INIT already defined
#endif /* if defined CRYPTOCDD_INTERNAL_VAR_INIT */

/** \brief definition of the variable memory class
**
** To be used for global or static variables which are accessible from a calibration
** tool, which are initialized with values after every reset. */
#define CRYPTOCDD_INTERNAL_VAR_INIT

#if (defined CRYPTOCDD_INTERNAL_VAR_POWER_ON_INIT) /* to prevent double definition */
#error CRYPTOCDD_INTERNAL_VAR_POWER_ON_INIT already defined
#endif /* if defined CRYPTOCDD_INTERNAL_VAR_POWER_ON_INIT */

/** \brief definition of the variable memory class
**
** To be used for global or static variables which are accessible from a calibration
** tool, which are initialized with values only after power on reset. */
#define CRYPTOCDD_INTERNAL_VAR_POWER_ON_INIT

#if (defined CRYPTOCDD_CALIB) /* to prevent double definition */
#error CRYPTOCDD_CALIB already defined
#endif /* if defined CRYPTOCDD_CALIB */

/** \brief definition of the constant memory class
**
** To be used for calibration constants. */
#define CRYPTOCDD_CALIB

#if (defined CRYPTOCDD_APPL_DATA) /* to prevent double definition */
#error CRYPTOCDD_APPL_DATA already defined
#endif /* if defined CRYPTOCDD_APPL_DATA */

/** \brief definition of the application data pointer class
**
** To be used for references on application data (expected to
** be in RAM or ROM) passed via API. */
#define CRYPTOCDD_APPL_DATA

#if (defined CRYPTOCDD_APPL_CONST) /* to prevent double definition */
#error CRYPTOCDD_APPL_CONST already defined
#endif /* if defined CRYPTOCDD_APPL_CONST */

/** \brief definition of the constant pointer class
**
** To be used for references on application constants (expected to
** be certainly in ROM, for instance pointer of Init() function)
** passed via API. */
#define CRYPTOCDD_APPL_CONST

#if (defined CRYPTOCDD_VAR_NO_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_NO_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_NO_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables that are never cleared and never
** initialized. */
#define CRYPTOCDD_VAR_NO_INIT

#if (defined CRYPTOCDD_VAR_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables that are cleared to zero after
** every reset. */
#define CRYPTOCDD_VAR_CLEARED

#if (defined CRYPTOCDD_VAR_POWER_ON_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_POWER_ON_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_POWER_ON_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables that are cleared to zero only
** after power on reset.*/
#define CRYPTOCDD_VAR_POWER_ON_CLEARED

#if (defined CRYPTOCDD_VAR_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables that are initialized with values
** after every reset.*/
#define CRYPTOCDD_VAR_INIT

#if (defined CRYPTOCDD_VAR_POWER_ON_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_POWER_ON_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_POWER_ON_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables that are initialized with values
** only after power on reset.*/
#define CRYPTOCDD_VAR_POWER_ON_INIT

#if (defined CRYPTOCDD_VAR_FAST_NO_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_FAST_NO_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_FAST_NO_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables    that have at least one of the
** following properties and are never cleared and never initialized.
**   accessed bitwise
**   frequently used
**   high number of accesses in source code */
#define CRYPTOCDD_VAR_FAST_NO_INIT

#if (defined CRYPTOCDD_VAR_FAST_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_FAST_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_FAST_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables    that have at least one of the
** following properties and are cleared to zero after every reset.
**   accessed bitwise
**   frequently used
**   high number of accesses in source code */
#define CRYPTOCDD_VAR_FAST_CLEARED

#if (defined CRYPTOCDD_VAR_FAST_POWER_ON_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_FAST_POWER_ON_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_FAST_POWER_ON_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables    that have at least one of the
** following properties and are cleared to zero only after power on reset.
**   accessed bitwise
**   frequently used
**   high number of accesses in source code */
#define CRYPTOCDD_VAR_FAST_POWER_ON_CLEARED

#if (defined CRYPTOCDD_VAR_FAST_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_FAST_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_FAST_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables    that have at least one of the
** following properties and are initialized with values after every reset.
**   accessed bitwise
**   frequently used
**   high number of accesses in source code */
#define CRYPTOCDD_VAR_FAST_INIT

#if (defined CRYPTOCDD_VAR_FAST_POWER_ON_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_FAST_POWER_ON_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_FAST_POWER_ON_INIT */

/** \brief definition of the variable memory class
**
** To be used for all global or static variables    that have at least one of the
** following properties and are initialized with values only after power on reset.
**   accessed bitwise
**   frequently used
**   high number of accesses in source code */
#define CRYPTOCDD_VAR_FAST_POWER_ON_INIT

#if (defined CRYPTOCDD_VAR_SAVED_ZONE) /* to prevent double definition */
#error CRYPTOCDD_VAR_SAVED_ZONE already defined
#endif /* if defined CRYPTOCDD_VAR_SAVED_ZONE */

/** \brief definition of the variable memory class
**
** To be used for RAM buffers of variables saved oin non-volatile memory. */
#define CRYPTOCDD_VAR_SAVED_ZONE

#if (defined CRYPTOCDD_VAR_SLOW_NO_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_SLOW_NO_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_SLOW_NO_INIT */

/** \brief definition of the variable memory class
**
** To be used for all infrequently accessed global or static variables that are
** never cleared and never initialized. */
#define CRYPTOCDD_VAR_SLOW_NO_INIT

#if (defined CRYPTOCDD_VAR_SLOW_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_SLOW_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_SLOW_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all infrequently accessed global or static variables that are
** cleared to zero after every reset. */
#define CRYPTOCDD_VAR_SLOW_CLEARED

#if (defined CRYPTOCDD_VAR_SLOW_POWER_ON_CLEARED) /* to prevent double definition */
#error CRYPTOCDD_VAR_SLOW_POWER_ON_CLEARED already defined
#endif /* if defined CRYPTOCDD_VAR_SLOW_POWER_ON_CLEARED */

/** \brief definition of the variable memory class
**
** To be used for all infrequently accessed global or static variables that are
** cleared to zero only after power on reset. */
#define CRYPTOCDD_VAR_SLOW_POWER_ON_CLEARED

#if (defined CRYPTOCDD_VAR_SLOW_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_SLOW_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_SLOW_INIT */

/** \brief definition of the variable memory class
**
** To be used for all infrequently accessed global or static variables that are
** initialized with values after every reset. */
#define CRYPTOCDD_VAR_SLOW_INIT

#if (defined CRYPTOCDD_VAR_SLOW_POWER_ON_INIT) /* to prevent double definition */
#error CRYPTOCDD_VAR_SLOW_POWER_ON_INIT already defined
#endif /* if defined CRYPTOCDD_VAR_SLOW_POWER_ON_INIT */

/** \brief definition of the variable memory class
**
** To be used for all infrequently accessed global or static variables that are
** initialized with values only after power on reset. */
#define CRYPTOCDD_VAR_SLOW_POWER_ON_INIT

/*****************************************************************************
 *  PUBLIC APIS
 *****************************************************************************/
#define CRYPTOCDD_START_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <CryptoCdd_MemMap.h>

/**
******************************************************************************
** \fn CryptoCdd_RsaEsOaepSha256(
    const uint8 *p_PublicModulusPtr_pU8, uint32 p_PublicModulusLength_U32,
    const uint8 *p_PublicExponentPtr_pU8, uint32 p_PublicExponentLength_U32,
    const uint8 *p_PlainTextPtr_pU8, uint32 p_PlainTextLength_U32,
    uint8 *p_CipherTextPtr_pU8, uint32 *p_CipherTextLength_pU32);
**
** This interface shall be used to encrypt data with RSAES-OAEP.
**
** \param [in] p_PublicModulusPtr_pU8
** Pointer to the start of Public Key Modulus.
**
** \param [in] p_PublicModulusLength_U32
** Length of Public Key Modulus.
**
** \param [in] p_PublicExponentPtr_pU8
** Pointer to the start of Public Key Exponent.
**
** \param [in] p_PublicExponentLength_U32
** Length of Public Key Exponent.
**
** \param [in] p_PlainTextPtr_pU8
** Pointer to the message which has to be encrypted.
**
** \param [in] p_PlainTextLength_U32
** Length of plaintext message which has to be encrypted.
**
** \param [out] p_CipherTextPtr_pU8
** Pointer to a buffer where the encrypted message has to be stored.
**
** \param [out] p_CipherTextLength_pU32
** Length of the buffer where the encrypted message has to be stored.
**
** \return Std_ReturnType<br>
** This function returns:
** - E_OK if Encryption is successful.
** - E_NOT_OK if encryption could not be done with given parameters.
*****************************************************************************/
FUNC(Std_ReturnType, CRYPTOCDD_CODE)
CryptoCdd_RsaEsOaepSha256(P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicModulusPtr_pU8,
                          VAR(uint32, AUTOMATIC) p_PublicModulusLength_U32,
                          P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicExponentPtr_pU8,
                          VAR(uint32, AUTOMATIC) p_PublicExponentLength_U32,
                          P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PlainTextPtr_pU8,
                          VAR(uint32, AUTOMATIC) p_PlainTextLength_U32,
                          P2VAR(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_CipherTextPtr_pU8,
                          P2VAR(uint32, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_CipherTextLength_pU32);

/**
******************************************************************************
** \fn CryptoCdd_RsaSsaPssSha256NoSalt(
    const uint8 *p_PublicModulusPtr_pU8, uint32 p_PublicModulusLength_U32,
    const uint8 *p_PublicExponentPtr_pU8, uint32 p_PublicExponentLength_U32,
    const uint8 *p_PlainTextPtr_pU8, uint32 p_PlainTextLength_U32,
    const uint8 *p_SigPtr_pU8, uint32 p_SigLength_U32,
    uint8 *p_VerResultPtr_pU8);
**
** This interface shall be used for signature verification via RSASSA-PSS.
**
** \param [in] p_PublicModulusPtr_pU8
** Pointer to the start of Public Key Modulus.
**
** \param [in] p_PublicModulusLength_U32
** Length of Public Key Modulus.
**
** \param [in] p_PublicExponentPtr_pU8
** Pointer to the start of Public Key Exponent.
**
** \param [in] p_PublicExponentLength_U32
** Length of Public Key Exponent.
**
** \param [in] p_PlainTextPtr_pU8
** Pointer to message over which signature has to be verified.
**
** \param [in] p_PlainTextLength_U32
** Length of message over which signature has to be verified.
**
** \param [in] p_SigPtr_pU8
** Pointer to the location of the singature.
**
** \param [in] p_SigLength_U32
** Length of the signature.
**
** \param [out] p_VerResultPtr_pU8
** Pointer to store Verification Result.Verification is OK if value is 0.
**
** \return Std_ReturnType<br>
** This function returns:
** - E_OK if verification started.
** - E_NOT_OK if verification
*****************************************************************************/
FUNC(Std_ReturnType, CRYPTOCDD_CODE)
CryptoCdd_RsaSsaPssSha256NoSalt(P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicModulusPtr_pU8,
                                VAR(uint32, AUTOMATIC) p_PublicModulusLength_U32,
                                P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicExponentPtr_pU8,
                                VAR(uint32, AUTOMATIC) p_PublicExponentLength_U32,
                                P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PlainTextPtr_pU8,
                                VAR(uint32, AUTOMATIC) p_PlainTextLength_U32,
                                P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_SigPtr_pU8,
                                VAR(uint32, AUTOMATIC) p_SigLength_U32,
                                P2VAR(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_VerResultPtr_pU8);

/**
******************************************************************************
** \fn CryptoCdd_RsaSsaPkcs15Sha256(
    const uint8 *p_PublicModulusPtr_pU8, uint32 p_PublicModulusLength_U32,
    const uint8 *p_PublicExponentPtr_pU8, uint32 p_PublicExponentLength_U32,
    const uint8 *p_PlainTextPtr_pU8, uint32 p_PlainTextLength_U32,
    const uint8 *p_SigPtr_pU8, uint32 p_SigLength_U32,
    uint8 *p_VerResultPtr_pU8);
**
** This interface shall be used for signature verification via RSASSA-PSS.
**
** \param [in] p_PublicModulusPtr_pU8
** Pointer to the start of Public Key Modulus.
**
** \param [in] p_PublicModulusLength_U32
** Length of Public Key Modulus.
**
** \param [in] p_PublicExponentPtr_pU8
** Pointer to the start of Public Key Exponent.
**
** \param [in] p_PublicExponentLength_U32
** Length of Public Key Exponent.
**
** \param [in] p_PlainTextPtr_pU8
** Pointer to message over which signature has to be verified.
**
** \param [in] p_PlainTextLength_U32
** Length of message over which signature has to be verified.
**
** \param [in] p_SigPtr_pU8
** Pointer to the location of the singature.
**
** \param [in] p_SigLength_U32
** Length of the signature.
**
** \param [out] p_VerResultPtr_pU8
** Pointer to store Verification Result.Verification is OK if value is 0.
**
** \return Std_ReturnType<br>
** This function returns:
** - E_OK if verification started.
** - E_NOT_OK if verification
*****************************************************************************/
FUNC(Std_ReturnType, CRYPTOCDD_CODE)
CryptoCdd_RsaSsaPkcs15Sha256(P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicModulusPtr_pU8,
                             VAR(uint32, AUTOMATIC) p_PublicModulusLength_U32,
                             P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PublicExponentPtr_pU8,
                             VAR(uint32, AUTOMATIC) p_PublicExponentLength_U32,
                             P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_PlainTextPtr_pU8,
                             VAR(uint32, AUTOMATIC) p_PlainTextLength_U32,
                             P2CONST(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_SigPtr_pU8, uint32 p_SigLength_U32,
                             P2VAR(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_VerResultPtr_pU8);

/**
******************************************************************************
** \fn CryptoCdd_RandomGenerate(P2VAR(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_RandomNumber_pU8,
**                       uint32 p_RandomNumberLength_U32);
**
** This interface shall be used to generate Random Number from MbedTLS.
**
** \param [out] p_RandomNumber_pU8
** Address to store the output random number.
**
** \param [in] p_RandomNumberLength_U32
** Length of the random number to be generated.
**
** \return Std_ReturnType<br>
** This function returns:
** - E_OK if random number was generated.
** - E_NOT_OK if generation fails.
*****************************************************************************/
FUNC(Std_ReturnType, CRYPTOCDD_CODE)
CryptoCdd_RandomGenerate(P2VAR(uint8, AUTOMATIC, CRYPTOCDD_APPL_DATA) p_RandomNumber_pU8,
                         uint32 p_RandomNumberLength_U32);

#define CRYPTOCDD_STOP_SEC_CODE_QM_LOCAL
/* coverity[unnecessary_header] : FALSE */
/* coverity[misra_c_2012_rule_20_1_violation] : FALSE */
#include <CryptoCdd_MemMap.h>

#endif /* CRYPTOCDD_H */
