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
 * \file Crypto_CmacGen.c
 *
 * \brief
 * MAC generate implementation in M7
 *
 * \detailed description
 *  This file shall be the MAC generate implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 28/Oct/'22 | svetcha  | 1061554 | AUTOSAR CRY Wrapper                        |
 * 
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

/*==[Includes]================================================================*/

#include "Crypto_She.h"
#include "Crypto_CmacGen.h"
#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "stub.h"
#include "vHsmCryptoManager.h"
//#include "vHsmIpcHostManager.h"
//#include "Csm_TypesConfig.h"

#if (CRYPTO_CMACGENERATE_ENABLED == 1)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

typedef enum
{
    CRYPTO_HSM_SYMMACGEN_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_HSM_SYMMACGEN_WAIT  /* HSM is waiting on the data from CSM */
}
Crypto_Hsm_SymMacGenWorkType;

typedef struct
{
        VAR(Crypto_SymKeyInfoType,CRY_APPL_DATA) keyInfo;
        P2CONST(uint8,TYPEDEF,CRY_APPL_DATA)  datPtr;
        uint32                                datLen;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    macPtr;
        P2VAR(uint32, TYPEDEF, CRY_APPL_DATA) macLenPtr;
        Crypto_Hsm_SymMacGenWorkType             work;
        Crypto_StateType                     state;
        Crypto_StateType                     stateRequested;
        uint8                                 priority;
        uint8                                 faultLog_U8;
        VAR(boolean,CRY_APPL_DATA)            LockedHsm_E;
        VAR(boolean,CRY_APPL_DATA)            trunc;
        boolean                               DirectCall;
}
Crypto_SymMacGenStateType;

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymMacGenCallback
 **
 ** \brief 
 ** 
 **
 ** \param [in] param
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymMacGenCallback(Csm_ReturnType param);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymMacGenActionOnFault
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymMacGenActionOnFault(void);

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_SymMacGenStateType, CRY_VAR) Crypto_SymMacGenState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SymMacGenNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_Hsm_CryptMacGenPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_MacGenJob_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_MacGenJob_Error;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

FUNC(void, CRY_CODE) Crypto_She_SymMacGenInit(void)
{
    Crypto_SymMacGenState_S.state = Crypto_Idle;
    Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
    Crypto_SymMacGenState_S.datPtr  = NULL;
    Crypto_SymMacGenState_S.datLen  = 0U;
    Crypto_SymMacGenState_S.macPtr  = NULL;
    Crypto_SymMacGenState_S.macLenPtr  = NULL;
    Crypto_SymMacGenState_S.LockedHsm_E      = FALSE;
    Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SymMacGenState_S.faultLog_U8 = 0U;
    Crypto_SymMacGenState_S.work = CRYPTO_HSM_SYMMACGEN_WORK;
    vHsmCrypt_MacGenJob_Completed = FALSE;
    vHsmCrypt_MacGenJob_Error = FALSE;
}

#ifdef MAC_GEN_SYNC_JOB_SUPPORT_ENABLE

FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerate_S
(
        P2CONST (void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
        P2CONST (Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
        P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) dataPtr,
        VAR     (uint32,                    CRY_APPL_DATA) dataLength,
        P2VAR   (uint8,          AUTOMATIC, CSM_APPL_DATA) resultPtr,
        P2VAR   (uint32,         AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
        VAR     (boolean,        AUTOMATIC               ) truncationIsAllowed
)
{

    Csm_ReturnType fl_ret_E = CSM_E_OK;
    
    P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (NULL == cfgPtr) || (NULL == keyPtr) || 
    (NULL == dataPtr) || (0U == dataLength) || (NULL == resultPtr) || (NULL == resultLengthPtr))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymMacGenNotif_S.callbackNeeded = FALSE;
        Crypto_SymMacGenNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymMacGenState_S.priority)
        {
            /* !LINKSTO CRYSHE_22, 1
             */
            fl_ret_E = CSM_E_BUSY;
        }
        else
        {
            /* !LINKSTO CRYSHE_23, 1
             */
            fl_ret_E = CSM_E_OK;
            if
            (
                    (CRYPTO_PRIORITY_NONE != Crypto_SymMacGenState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymMacGenState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            if (keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH)
            {
                Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymMacGenState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Finish;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Finish;
                }
#else           
                if(Crypto_Idle == Crypto_SymMacGenState_S.state)
				{
                    Crypto_SymMacGenState_S.state = Crypto_Finish;
                    Crypto_SymMacGenState_S.DirectCall = TRUE;
                    Crypto_SymMacGenState_S.datPtr     = dataPtr;
                    Crypto_SymMacGenState_S.datLen     = dataLength;
                    Crypto_SymMacGenState_S.macPtr    = resultPtr;
                    Crypto_SymMacGenState_S.macLenPtr = resultLengthPtr;
                    Crypto_SymMacGenState_S.trunc     = truncationIsAllowed;
                    Crypto_SymMacGenState_S.work = CRYPTO_HSM_SYMMACGEN_WORK;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                    Crypto_SymMacGenState_S.priority = locCfgPtr->priority;
                    /* Deviation MISRA-2 <+2> */
                    Crypto_SymMacGenState_S.keyInfo.keyId = (keyPtr->data);
                    Crypto_SymMacGenState_S.LockedHsm_E = TRUE;  
                    vHsmCrypt_MacGenJob_Error = FALSE;
                    vHsmCrypt_MacGenJob_Completed = FALSE;
                    while(FALSE==vHsmCrypt_MacGenJob_Completed)
                    {
                        if(FALSE != vHsmCrypt_MacGenJob_Error)
                        {
                            fl_ret_E = CSM_E_NOT_OK;                    
                            break;
                        }
                        else
                        {
                            Crypto_She_MacGenerateMainFunction();
                            vHsmIpc_HostManager_PeriodicCheck();
                            //CySldIpc_Isr_IpcDrv_Cat2();
                        }
                    }
                    Crypto_SymMacGenState_S.state = Crypto_Idle;
                    Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
                }
                else
                {
                    fl_ret_E = CSM_E_NOT_OK;
                }
            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif  /*CRYPTO_PRIORITY_ENABLED*/
    }
    return fl_ret_E;
}
#else /*MAC_GEN_SYNC_JOB_SUPPORT_ENABLE 0 */

/*---[Crypto_She_MacGenerate - direct call with callback update of results from M0P]--------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerate
(
                P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
                P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
                VAR(uint32,            CRY_APPL_DATA) dataLength,
                P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) resultPtr,
                P2VAR(uint32,  AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
                VAR(boolean, AUTOMATIC               ) truncationIsAllowed
)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) || (keyPtr == NULL ) || 
    (dataPtr == NULL) || (dataLength == 0u) || (resultPtr == NULL) || (resultLengthPtr == NULL))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymMacGenNotif_S.callbackNeeded = FALSE;
        Crypto_SymMacGenNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymMacGenState_S.priority)
        {
            /* !LINKSTO CRYSHE_22, 1
             */
            fl_ret_E = CSM_E_BUSY;
        }
        else
        {
            /* !LINKSTO CRYSHE_23, 1
             */
            fl_ret_E = CSM_E_OK;
            if
            (
                    (CRYPTO_PRIORITY_NONE != Crypto_SymMacGenState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymMacGenState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            if ( keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH )
            {
                Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymMacGenState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Finish;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Finish;
                }
#else
                Crypto_SymMacGenState_S.state = Crypto_Finish;
                Crypto_SymMacGenState_S.DirectCall = TRUE;
                Crypto_SymMacGenState_S.datPtr     = dataPtr;
                Crypto_SymMacGenState_S.datLen     = dataLength;
                Crypto_SymMacGenState_S.macPtr    = resultPtr;
                Crypto_SymMacGenState_S.macLenPtr = resultLengthPtr;
                Crypto_SymMacGenState_S.trunc     = truncationIsAllowed;

#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymMacGenState_S.priority = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymMacGenState_S.keyInfo.keyId = (keyPtr->data);
                vHsmCrypt_MacGenJob_Completed = FALSE;
                vHsmCrypt_MacGenJob_Error = FALSE;
            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif  /*CRYPTO_PRIORITY_ENABLED*/
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymMacGenCallback(Crypto_SymMacGenNotif_S.callbackParamValue);
    return fl_ret_E;
}

#endif /*MAC_VERIFY_SYNC_JOB_SUPPORT_ENABLE*/

#ifdef CMACGENERATE_STRUPDFIN_ENABLE

/*---[Crypto_She_MacGenerateStart]-------------------------------------------*/

/* !LINKSTO CRYSHE_80, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateStart
(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr
)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) || (keyPtr == NULL ))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymMacGenNotif_S.callbackNeeded = FALSE;
        Crypto_SymMacGenNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_MacGenerateConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;

        if (locCfgPtr->priority < Crypto_SymMacGenState_S.priority)
        {
            /* !LINKSTO CRYSHE_22, 1
             */
            fl_ret_E = CSM_E_BUSY;
        }
        else
        {
            /* !LINKSTO CRYSHE_23, 1
             */
            fl_ret_E = CSM_E_OK;
            if
            (
                    (CRYPTO_PRIORITY_NONE != Crypto_SymMacGenState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymMacGenState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
            /* CHECK: NOPARSE */
            /* Defensive programming. The true branch cannot be reached with the current state machine */
            if
            (
                    (Crypto_SymMacGenState_S.priority != CRYPTO_PRIORITY_NONE) &&
                    (Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
            )
                /* CHECK: PARSE */
            {
                /* A MAC generation is already running and has to be cancelled. */
                Crypto_SymMacGenCancel();
            }
            if ( keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH )
            {
                Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymMacGenState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymMacGenState_S.stateRequested = Crypto_Start;
                }
#else
                Crypto_SymMacGenState_S.state = Crypto_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymMacGenState_S.priority = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymMacGenState_S.keyInfo.keyId = (keyPtr->data);
                vHsmCrypt_MacGenJob_Error = FALSE;
            }
        }
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymMacGenCallback(Crypto_SymMacGenNotif_S.callbackParamValue);
    return fl_ret_E;
}

/*---[Crypto_She_MacGenerateUpdate]-------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateUpdate
(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
      VAR(uint32,            CRY_APPL_DATA) dataLength
)
{
  //CRYPTO_LOCK_SEM();
  Csm_ReturnType ret = CSM_E_OK;
  if(( Crypto_SymMacGenState_S.state == Crypto_Idle ) ||
     ( Crypto_SymMacGenState_S.state == Crypto_Cancel) ||
     ( Crypto_SymMacGenState_S.state == Crypto_Finish) ||
     ( Crypto_SymMacGenState_S.state == Crypto_Finish_Wait) )
  {
      ret = CSM_E_NOT_OK;
  }
  else
  {
      if
      (
        ( Crypto_SymMacGenState_S.state == Crypto_Update ) &&
        ( Crypto_SymMacGenState_S.work == CRYPTO_HSM_SYMMACGEN_WAIT )
      )
      {
        /* !LINKSTO CRYSHE_209, 1
         */
          Crypto_SymMacGenState_S.datPtr     = dataPtr;
          Crypto_SymMacGenState_S.datLen     = dataLength;
          Crypto_SymMacGenState_S.macPtr     = NULL;
          Crypto_SymMacGenState_S.macLenPtr  = NULL;
          Crypto_SymMacGenState_S.work        = CRYPTO_HSM_SYMMACGEN_WORK;
          vHsmCrypt_MacGenJob_Error = FALSE;
      }
      else if (( Crypto_SymMacGenState_S.state == Crypto_Start ) ||
              ( Crypto_SymMacGenState_S.state ==  Crypto_Start_Wait ))
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        /* Update can only be called once. */
        if (Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
        {
            Crypto_SymMacGenCancel();
        }
        ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacGenState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacGenState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
      }
  }
  //CRYPTO_RELEASE_SEM();

  return ret;
}

/*---[Crypto_She_MacGenerateFinish]-------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacGenerateFinish
(
  P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) resultPtr,
  P2VAR(uint32,  AUTOMATIC, CSM_APPL_DATA) resultLengthPtr,
    VAR(boolean, AUTOMATIC               ) truncationIsAllowed
)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if ((resultPtr == NULL) || (resultLengthPtr == NULL))
    {
        ret = CSM_E_NOT_OK;
        Crypto_SymMacGenCancel();
    }
    if(( Crypto_SymMacGenState_S.state == Crypto_Idle ) ||
     ( Crypto_SymMacGenState_S.state == Crypto_Cancel) ||
     ( Crypto_SymMacGenState_S.state == Crypto_Finish_Wait) ||
     (resultPtr == NULL) || (resultLengthPtr == NULL))
    {
      ret = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == ret)
    {
      if
      (
        (Crypto_SymMacGenState_S.state == Crypto_Finish) &&
        (Crypto_SymMacGenState_S.work == CRYPTO_HSM_SYMMACGEN_WAIT)
      )
      {
          Crypto_SymMacGenState_S.macPtr    = resultPtr;
          Crypto_SymMacGenState_S.macLenPtr = resultLengthPtr;
          Crypto_SymMacGenState_S.trunc     = truncationIsAllowed;
          Crypto_SymMacGenState_S.work      = CRYPTO_HSM_SYMMACGEN_WORK;
          ret = CSM_E_OK;
          vHsmCrypt_MacGenJob_Error = FALSE;
      }
      else
      if
      (
        ( Crypto_SymMacGenState_S.state == Crypto_Update ) &&
        ( Crypto_SymMacGenState_S.work == CRYPTO_HSM_SYMMACGEN_WAIT )
      )
      {
        /* Update has not been called. This means we must compute MAC over 0
         * bytes.
         */
          Crypto_SymMacGenState_S.stateRequested = Crypto_Finish;
          Crypto_SymMacGenState_S.trunc     = truncationIsAllowed;
          Crypto_SymMacGenState_S.macLenPtr = resultLengthPtr;
          Crypto_SymMacGenState_S.macPtr    = resultPtr;
          Crypto_SymMacGenState_S.state     = Crypto_Update;
          Crypto_SymMacGenState_S.work      = CRYPTO_HSM_SYMMACGEN_WORK;
          Crypto_SymMacGenState_S.datLen    = 0U;
          ret = CSM_E_OK;
      }
      else if
      (
        ( Crypto_SymMacGenState_S.state == Crypto_Start ) ||
        ( Crypto_SymMacGenState_S.state == Crypto_Start_Wait ) ||
        ( Crypto_SymMacGenState_S.state == Crypto_Update_Wait ) ||
        ( Crypto_SymMacGenState_S.state == Crypto_Update )
      )
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        if(Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
        {
            Crypto_SymMacGenCancel();
        }
        ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacGenState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacGenState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
      }

      if
      (
        (ret == CSM_E_OK) &&
        (Crypto_SymMacGenState_S.trunc == FALSE) &&
        (*Crypto_SymMacGenState_S.macLenPtr < CRYPTO_HSM_BLOCK_LENGTH)
      )
      {
          Crypto_SymMacGenCancel();
        /* !LINKSTO CSM0662, 1
         */
        ret = CSM_E_SMALL_BUFFER;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if( Crypto_SymMacGenState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacGenState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacGenState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacGenState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
      }
    }
  //CRYPTO_RELEASE_SEM();

  return ret;
}

#endif /*CMACGENERATE_STRUPDFIN_ENABLE*/

/*---[Crypto_She_MacGenerateMainFunction]-------------------------------------------*/
FUNC(void,CRY_CODE) Crypto_She_MacGenerateMainFunction
(
  void
)
{
    //CRYPTO_LOCK_SEM();
    Crypto_SymMacGenNotif_S.callbackNeeded = FALSE;
    Crypto_SymMacGenNotif_S.finishNeeded = FALSE;
    switch (Crypto_SymMacGenState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_SymMacGenState_S.stateRequested)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymMacGenState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:
            Crypto_SymMacGenState_S.LockedHsm_E = Crypto_LockShe();

            /* !LINKSTO CRYSHE_25, 1
             */
            if(Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
            {
                /*Crypto_Hsm_CryptMacGenPackedData_S.KeyId_U8 =
                        Crypto_SymMacGenState_S.keyInfo.keyId;
                Crypto_Hsm_CryptMacGenPackedData_S.jobId_E = CID_22_MAC_GEN_START;
                Crypto_Hsm_CryptMacGenPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_CryptMacGenPackedData_S.payLoadPtr_U8P =
                        NULL;
                Crypto_Hsm_CryptMacGenPackedData_S.payLoadSize = 0u;*/
                vHsmCrypt_MacGenJob_Completed = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptMacGenPackedData_S))
                {
                    Crypto_SymMacGenState_S.state = Crypto_Start_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
            }
            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_MacGenJob_Completed)
            {
                if(FALSE == vHsmCrypt_MacGenJob_Error)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Update;
                    Crypto_SymMacGenState_S.work  = CRYPTO_HSM_SYMMACGEN_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                    Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Update:
            if ( Crypto_SymMacGenState_S.work == CRYPTO_HSM_SYMMACGEN_WORK )
            {
                /* Pack data to do MAC generate */
                /*Crypto_Hsm_CryptMacGenPackedData_S.KeyId_U8 =
                        Crypto_SymMacGenState_S.keyInfo.keyId;
                Crypto_Hsm_CryptMacGenPackedData_S.jobId_E = CID_23_MAC_GEN_UPDATE;
                Crypto_Hsm_CryptMacGenPackedData_S.payLoadPtr_U8P =
                        (uint8 *)Crypto_SymMacGenState_S.datPtr;
                Crypto_Hsm_CryptMacGenPackedData_S.payLoadSize = Crypto_SymMacGenState_S.datLen;
                Crypto_Hsm_CryptMacGenPackedData_S.priority_U8 = (te_jobpriority)0;*/
                vHsmCrypt_MacGenJob_Completed = FALSE;
                if (E_OK == Crypto_SendPackedData(Crypto_Hsm_CryptMacGenPackedData_S))
                {
                    Crypto_SymMacGenState_S.state = Crypto_Update_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for updates from CSM application */
            }
            break;
        case Crypto_Update_Wait:
            if (TRUE == vHsmCrypt_MacGenJob_Completed)
            {
                if(FALSE == vHsmCrypt_MacGenJob_Error)
                {
                    Crypto_SymMacGenState_S.state = Crypto_Finish;
                    if(Crypto_SymMacGenState_S.stateRequested == Crypto_Finish)
                    {
                        /* Already finish alone sent from CSM appln for
                        calculating MAC over 0 bytes */
                        Crypto_SymMacGenState_S.work  = CRYPTO_HSM_SYMMACGEN_WORK;
                    }
                    else
                    {
                        /* To receive finish from CSM appln */
                        Crypto_SymMacGenState_S.work  = CRYPTO_HSM_SYMMACGEN_WAIT;
                    }
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                    Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
                if
                (
                        (Crypto_SymMacGenState_S.keyInfo.keyId == CRYPTO_SHE_RAM_KEY         ) &&
                        (Crypto_SymMacGenState_S.keyInfo.keyNr != Crypto_SymKeyInfo.keyNr)
                )
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
                else
                {
                    if(FALSE != Crypto_SymMacGenState_S.DirectCall)
                    {
                        if(FALSE != Crypto_SymMacGenState_S.LockedHsm_E)
                        {
                            if(INT16_MAX_RANGE >= Crypto_SymMacGenState_S.keyInfo.keyId)
                            {
                                Crypto_Hsm_CryptMacGenPackedData_S.KeyId_U8 =
                                        (uint8)Crypto_SymMacGenState_S.keyInfo.keyId;
                                Crypto_Hsm_CryptMacGenPackedData_S.jobId_E = CID_21_MAC_GEN_FN;
                                Crypto_Hsm_CryptMacGenPackedData_S.priority_U8 = (te_jobpriority)0;
                                Crypto_Hsm_CryptMacGenPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_SymMacGenState_S.datPtr;
                                Crypto_Hsm_CryptMacGenPackedData_S.payLoadSize = Crypto_SymMacGenState_S.datLen; /* no payload */
                                vHsmCrypt_MacGenJob_Completed = FALSE;
                                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptMacGenPackedData_S))
                                {
                                    Crypto_SymMacGenState_S.state = Crypto_Finish_Wait;
                                    Crypto_ResetFaultCounter();
                                }
                                else
                                {
                                    Crypto_Hsm_SymMacGenActionOnFault();
                                }
                            }
                            else
                            {
                                /*Handle the case of overflow*/
                            }
                        }   
                    }
                    else
                    {
                        if(INT16_MAX_RANGE >= Crypto_SymMacGenState_S.keyInfo.keyId)
                        {
                            Crypto_Hsm_CryptMacGenPackedData_S.KeyId_U8 =
                                        (uint8)Crypto_SymMacGenState_S.keyInfo.keyId;
                            Crypto_Hsm_CryptMacGenPackedData_S.jobId_E = CID_21_MAC_GEN_FN;
                            Crypto_Hsm_CryptMacGenPackedData_S.priority_U8 = (te_jobpriority)0;
                            Crypto_Hsm_CryptMacGenPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_SymMacGenState_S.datPtr;
                            Crypto_Hsm_CryptMacGenPackedData_S.payLoadSize = Crypto_SymMacGenState_S.datLen; /* no payload */
                            vHsmCrypt_MacGenJob_Completed = FALSE;
                            if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptMacGenPackedData_S))
                            {
                                Crypto_SymMacGenState_S.state = Crypto_Finish_Wait;
                                Crypto_ResetFaultCounter();
                            }
                            else
                            {
                                Crypto_Hsm_SymMacGenActionOnFault();
                            }
                        }
                        else
                        {
                            /*Handle the case of overflow*/
                        }
                    }
                }
            break;
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_MacGenJob_Completed)
            {
                Crypto_SymMacGenState_S.state = Crypto_Idle;
                Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacGenNotif_S.finishNeeded = TRUE;
                Crypto_SymMacGenState_S.work  = CRYPTO_HSM_SYMMACGEN_WAIT;
                Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_MacGenJob_Error)
                {
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SymMacGenState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SymMacGenActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        default:
            Crypto_Hsm_SymMacGenActionOnFault();
            break;
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymMacGenCallback(Crypto_SymMacGenNotif_S.callbackParamValue);
}

/*---[Crypto_She_MacGenCallback]-------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_She_MacGenCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint32 res_length;
    uint32 dataToCopy;
    uint8 status = *p_resultBytesInSRAM_U8P;
    if(Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
    {
        switch (Crypto_SymMacGenState_S.state)
        {
            case Crypto_Start_Wait:
                vHsmCrypt_MacGenJob_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_MacGenJob_Error = TRUE;
                }
                break;
            case Crypto_Update_Wait:
                vHsmCrypt_MacGenJob_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_MacGenJob_Error = TRUE;
                }
                break;
            case Crypto_Finish_Wait:
                res_length= (uint32)payload_size - (uint32)1;
                vHsmCrypt_MacGenJob_Completed = TRUE;
                if(Crypto_SymMacGenState_S.macLenPtr != NULL)
                {
                    dataToCopy = *Crypto_SymMacGenState_S.macLenPtr;
                    if(((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                       (dataToCopy <= res_length))
                    {
                            /* Copy the result data into the memory
                        location shared from application */
                            (void)memcpy((uint8 *)Crypto_SymMacGenState_S.macPtr,
                                    (uint8 *)&p_resultBytesInSRAM_U8P[1],
                                    (uint16)dataToCopy);
                        Crypto_She_MacGenerateMainFunction();
                    }
                    else
                    {
                        vHsmCrypt_MacGenJob_Error = TRUE;
                    }
                }
                else
                {
                    vHsmCrypt_MacGenJob_Error = TRUE;
                }
                break;
            default:
                vHsmCrypt_MacGenJob_Error = TRUE;
                break;
       }
    }
}

/*==[Definition of functions with internal linkage]===========================*/

/*---[Crypto_SymMacGenCancel]-------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_SymMacGenCancel(void)
{
    Crypto_SymMacGenState_S.priority = CRYPTO_PRIORITY_NONE;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SymMacGenState_S.state = Crypto_Cancel;
#else
    Crypto_SymMacGenState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
   if(Crypto_SymMacGenState_S.LockedHsm_E == TRUE)
   {
        Crypto_SymMacGenState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
   }
    (void)Crypto_She_Cancel(e_aescmaccommon);
}

/*---[Crypto_Hsm_SymMacGenCallback]-------------------------------------------*/
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymMacGenCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SymMacGenNotif_S.callbackNeeded)
    {
        Crypto_SymMacGenNotif_S.callbackNeeded = FALSE;
        CRYPTO_HSM_CSM_SYMMACGEN_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SymMacGenNotif_S.finishNeeded)
    {
        Crypto_SymMacGenNotif_S.finishNeeded = FALSE;
        //CRYPTO_HSM_CSM_SYMMACGEN_SERVICE_FINISH_NOTIF();
    }
}

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymMacGenActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_SymMacGenState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SymMacGenState_S.faultLog_U8++;
    }
    vHsmCrypt_MacGenJob_Error = TRUE;
    Crypto_SymMacGenNotif_S.callbackNeeded = TRUE;
    Crypto_SymMacGenNotif_S.finishNeeded = TRUE;
    Crypto_SymMacGenNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_SymMacGenCancel();
    Crypto_ResetFaultCounter();
}

#endif /* CRY_SHE_MACGENERATE_ENABLED */



