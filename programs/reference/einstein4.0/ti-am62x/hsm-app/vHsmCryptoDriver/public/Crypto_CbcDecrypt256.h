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
 * \file Crypto_CbcDecrypt.h
 *
 * \brief
 * CBC decrypt header in M7
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
 *			Umaralli A Rajak Shaikh  | ushaikh   | VTSC, Bengaluru, India
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

#ifndef CRYPTO_CBCDECRYPT_H
#define CRYPTO_CBCDECRYPT_H 1
#define CRYPTO_CBCDECRYPT_ENABLED 1
#undef CBCDECRYPT_STRUPDFIN_ENABLE

/*==[Includes]================================================================*/
#include "Crypto_She.h"
#include "Crypto.h"
#include "Crypto_SymKeyInfo.h"
//#include "Cry_She_SymDecryptConfig.h"

#if (CRYPTO_CBCDECRYPT_ENABLED == 1)

/*==[Macros]==================================================================*/
extern void Csm_SymDecryptCallbackNotification(Csm_ReturnType result);
extern void Csm_SymDecryptServiceFinishNotification(void);
//extern void CbcDecrypt_FBLNotify_callback(Csm_ReturnType result);
//extern void CySldIpc_Isr_IpcDrv_Cat2 (void);

/* Define Callback Notification functions for CSM */
#define CRYPTO_HSM_CSM_SYMDECRYPT_CALLBACK_NOTIF        Csm_SymDecryptCallbackNotification
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_HSM_CSM_SYMDECRYPT_SERVICE_FINISH_NOTIF     Csm_SymDecryptServiceFinishNotification
/* Define Callback Notification function for BL*/
//#define CRYPTO_HSM_BL_SYMDECRYPT_CALLBACK_NOTIF       CbcDecrypt_FBLNotify_callback

/*==[Types]===================================================================*/

typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_She_SymDecryptConfigType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_SymDecryptInit
 **
 ** \brief Initialize CryShe CBC block decrypt module.
 **
 ** This function initializes the CBC block decrypt module. It has to be called 
 ** from Crypto_Init and before any services of the CBC decrypt module are used.
 ** 
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_SymDecryptInit(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymDecrypt_S
 **
 ** \brief This Function calculate Direct CBC Decryption
 **
 **
 ** \param [in]  cfgPtr
 ** \param [in]  keyPtr
 ** \param [in]  initVectorPtr
 ** \param [in]  initVectorLength
 ** \param [in]  iputTextPtr
 ** \param [in]  iputTextLength
 ** \param [out] oputTextPtr
 ** \param [out] oputTextLengthPtr
 **
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/

FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecrypt_S
(
        P2CONST (void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
        P2CONST (Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
        P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) initVectorPtr,
        VAR     (uint32,         AUTOMATIC               ) initVectorLength,
        P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) iputTextPtr,
        VAR     (uint32,         AUTOMATIC               ) iputTextLength,
        P2VAR   (uint8,          AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
        P2VAR   (uint32,         AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr
);
#ifdef CBCDECRYPT_STRUPDFIN_ENABLE
/**
 *********************************************************************************************
 ** \fn Crypto_She_SymDecryptStart
 **
 ** \brief 
 **
 **
 ** \param [in] cfgPtr
 ** \param [in] keyPtr
 ** \param [in] initVectorPtr
 ** \param [in] initVectorLength
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptStart(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
  P2CONST(uint8,          AUTOMATIC, CRY_APPL_DATA) initVectorPtr,
      VAR(uint32,         AUTOMATIC               ) initVectorLength);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymDecryptUpdate
 **
 ** \brief 
 **
 **
 ** \param [in] iputTextPtr
 ** \param [in] iputTextLength
 ** \param [in] oputTextPtr
 ** \param [in] oputTextLengthPtr
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptUpdate(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) iputTextPtr,
      VAR(uint32, AUTOMATIC               ) iputTextLength,
    P2VAR(uint8,  AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
    P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymDecryptFinish
 **
 ** \brief 
 ** 
 **
 ** \param [in] oputTextPtr
 ** \param [in] oputTextLengthPtr
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptFinish(
  P2VAR(uint8,  AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
  P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr);
  
#endif /*CBCDECRYPT_STRUPDFIN_ENABLE*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymDecryptMainFunction
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
FUNC(void,CRY_CODE) Crypto_She_SymDecryptMainFunction(void);
/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymDecryptCancel
 **
 ** \brief 
 ** Cancels the decryption job and releases she lock
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptCancel(void);

#endif /* #if (CRYPTO_CBCDECRYPT_ENABLED == 1) */

#endif /* CRYPTO_CBCDECRYPT_H */

