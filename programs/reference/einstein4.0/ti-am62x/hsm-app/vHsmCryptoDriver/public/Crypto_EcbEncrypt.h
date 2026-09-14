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
 * \file Crypto_EcbEncrypt.h
 *
 * \brief
 * ECB Encrypt header in M7
 *
 * \detailed description
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                   |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                 |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_ECBENCRYPT_H
#define CRYPTO_ECBENCRYPT_H 1
#define CRYPTO_ECBENCRYPT_ENABLED 1

/*==[Includes]================================================================*/

#include "Crypto_She.h"
#include "Crypto.h"
#include "Crypto_SymKeyInfo.h"

#if (CRYPTO_ECBENCRYPT_ENABLED == 1)

/*==[Macros]==================================================================*/

extern void Csm_SymBlockEncryptCallbackNotification(Csm_ReturnType result);
extern void Csm_SymBlockEncryptServiceFinishNotification(void);
//extern void CySldIpc_Isr_IpcDrv_Cat2 (void);

/* Define Callback Notification functions for CSM */
#define CRYPTO_CSM_SYMBLOCKENCRYPT_CALLBACK_NOTIF        Csm_SymBlockEncryptCallbackNotification
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_CSM_SYMBLOCKENCRYPT_SERVICE_FINISH_NOTIF     Csm_SymBlockEncryptServiceFinishNotification

/*==[Types]===================================================================*/

/* !LINKSTO CSM0544, 1
 */
typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_She_SymBlockEncryptConfigType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymBlockEncryptInit
 **
 ** \brief Initialize CryShe block encrypt module.
 **
 ** This function initializes the block encrypt module. It has to be called 
 ** from Crypto_Init and before any services of the block encrypt module are used.
 ** 
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_She_SymBlockEncryptInit(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymEncrypt_S
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncrypt_S
(
    P2CONST (void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
    P2CONST (Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
    P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) iputTextPtr,
    VAR     (uint32,         AUTOMATIC               ) iputTextLength,
    P2VAR   (uint8,          AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
    P2VAR   (uint32,         AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr,
    VAR     (uint8,          AUTOMATIC               ) padding_pkcs7
);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymBlockEncryptStart
 **
 ** \brief 
 ** 
 **
 ** \param [in] cfgPtr
 ** \param [in] keyPtr
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptStart(
                P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType,AUTOMATIC,CRY_APPL_DATA) keyPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymBlockEncryptUpdate
 **
 ** \brief 
 ** 
 **
 ** \param [in] plainTextPtr
 ** \param [in] plainTextLength
 **
 ** \param [out] cipherTextPtr
 ** \param [out] cipherTextLengthPtr
 **
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptUpdate(
                P2CONST(uint8,AUTOMATIC,CRY_APPL_DATA) plainTextPtr,
                uint32 plainTextLength,
                P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) cipherTextPtr,
                P2VAR(uint32,AUTOMATIC,CRY_APPL_DATA) cipherTextLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymBlockEncryptFinish
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptFinish(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymBlockEncryptMainFunction
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE) Crypto_She_SymBlockEncryptMainFunction(void);

/**
 *********************************************************************************************
 ** \fn Crypto_SymBlockEncryptCancel
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_SymBlockEncryptCancel(void);


#endif /* CRYPTO_ECBENCRYPT_ENABLED */

#endif /* CRYPTO_ECBENCRYPT_H */


