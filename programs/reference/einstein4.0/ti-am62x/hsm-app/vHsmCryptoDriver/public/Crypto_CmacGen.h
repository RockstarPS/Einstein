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
 * \file Crypto_CmacGen.h
 *
 * \brief
 * MAC generate header in M7
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
 *          Umaralli A Rajak Shaikh  | ushaikh   | VTSC,Bengaluru , India
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_CMACGEN_H
#define CRYPTO_CMACGEN_H 1
#define CRYPTO_CMACGENERATE_ENABLED 1
#define MAC_GEN_SYNC_JOB_SUPPORT_ENABLE 1
#define CMACGENERATE_STRUPDFIN_ENABLE 0

#include "Crypto_She.h"
#include "Crypto.h"
#include "Crypto_SymKeyInfo.h"
//#include "Crypto_MacGenerate.h"
//#include "Cry_She_MacGenerateConfig.h"

#if (CRYPTO_CMACGENERATE_ENABLED == 1)

/*==[Macros]==================================================================*/

extern void Crypto_CMacGen_callback(Csm_ReturnType result);
extern void Csm_MacGenerateServiceFinishNotification(void);
//extern void CySldIpc_Isr_IpcDrv_Cat2 (void);

/* Define Callback Notification functions for CSM */
#define CRYPTO_HSM_CSM_SYMMACGEN_CALLBACK_NOTIF        Crypto_CMacGen_callback
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_HSM_CSM_SYMMACGEN_SERVICE_FINISH_NOTIF     Csm_MacGenerateServiceFinishNotification

/*==[Types]===================================================================*/

/* !LINKSTO CSM0544, 1
 */
typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_She_MacGenerateConfigType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_SymMacGenInit
 **
 ** \brief Initialize CryShe MAC generate module.
 **
 ** This function initializes the MAC generate module. It has to be called
 ** from Crypto_She_Init and before any services of the MAC generate module are used.
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_She_SymMacGenInit(void);

#if (MAC_GEN_SYNC_JOB_SUPPORT_ENABLE == 1)
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerate_S
(
    P2CONST (void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
    P2CONST (Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
    P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) dataPtr,
    VAR     (uint32,                    CRY_APPL_DATA) dataLength,
    P2VAR   (uint8,          AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR   (uint32,         AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
    VAR     (boolean,        AUTOMATIC               ) truncationIsAllowed
);
#else /* MAC_GEN_SYNC_JOB_SUPPORT_ENABLE 0*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerate
(
                P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
                P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
                VAR(uint32,            CRY_APPL_DATA) dataLength,
                P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) resultPtr,
                P2VAR(uint32,  AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
                VAR(boolean, AUTOMATIC               ) truncationIsAllowed
);
#endif /* MAC_GEN_SYNC_JOB_SUPPORT_ENABLE */

#ifdef CMACGENERATE_STRUPDFIN_ENABLE

/**
 *********************************************************************************************
 ** \fn Crypto_She_MacGenerateStart
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
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateStart(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_She_MacGenerateUpdate
 **
 ** \brief This function streams data into the SHE. Since the SHE can only generate
 ** the MAC over a single block of data whose size must be known from the
 ** beginning, this function can only be called once.
 ** 
 **
 ** \param [in] dataPtr     Pointer to data.
 ** \param [in] dataLength  Length of data
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK      If the update was successfully requested.
 ** \retval   CSM_E_NOT_OK  If the service has not been started or the
 **                         update function has been called more than
 **                         once.
 ** \retval   CSM_E_BUSY    If this service is already starting.
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateUpdate(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
      VAR(uint32,            CRY_APPL_DATA) dataLength);


/**
 *********************************************************************************************
 ** \fn Crypto_She_MacGenerateFinish
 **
 ** \brief 
 ** 
 **
 **  \param[out]     resultPtr            A pointer to the buffer where the
 **                                      generated MAC result should be stored.
 **                                      If the result does not fit into the
 **                                      given buffer, and truncation is allowed,
 **                                      the result will be truncated.
 ** \param[out]     resultLengthPtr      On calling the function it is the amount
 **                                      of bytes of resultPtr. After finishing of
 **                                      function call it is the actual length of
 **                                      the generated MAC result.
 ** \param[in]      truncationIsAllowed  A flag that states whether truncation of
 **                                      the generated MAC result is allowed.
 **                                      TRUE  = truncation is allowed.
 **                                      FALSE = truncation is not allowed.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK            If the finish was successfully requested.
 ** \retval   CSM_E_NOT_OK        If the service has not been started.
 ** \retval   CSM_E_SMALL_BUFFER  If the result buffer is too small for the
 **                               MAC and truncation is not allowed.
 ** \retval   CSM_E_BUSY          If this service is already starting or updating.
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateFinish(
  P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) resultPtr,
  P2VAR(uint32,  AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
    VAR(boolean, AUTOMATIC               ) truncationIsAllowed);

#endif /*CMACGENERATE_STRUPDFIN_ENABLE*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_MacGenerateMainFunction
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
FUNC(void,CRY_CODE) Crypto_She_MacGenerateMainFunction(void);
/**
 *********************************************************************************************
 ** \fn Crypto_SymMacGenCancel
 **
 ** \brief 
 ** Cancels the mac generate job
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
 FUNC(void, CRY_CODE) Crypto_SymMacGenCancel(void);


#endif /* CRYPTO_CMACGENERATE_ENABLED */

#endif /* CRYPTO_CMACGEN_H */




