/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
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
 * \file Crypto_MacVerify.c
 *
 * \brief
 * MAC Verify implementation in M7
 *
 * \detailed description
 *  This file shall be the MAC Verify implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                        |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                      |
 * |1.01.02 | 03/Mar/'21 | bjayara2 | 1251639 | fix -key not stored error must be shown    |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/*==[Includes]================================================================*/

#include "Crypto.h"
#include "Crypto_SymKeyInfo.h"
#include "Crypto_MacVerify.h"
#include "Crypto_CmacGen.h"
#include "string.h"
#include "vHsmCryptoManager.h"
#include "Crypto_She.h"


#if (CRYPTO_MACVERIFY_ENABLED == 1)

/*==[Macros]==================================================================*/
#define CRYPTO_HSM_MAX_CMAC_VERIFY_IN_BITS  (128u)
/*==[Types]===================================================================*/

typedef enum
{
    CRYPTO_SYMMACVER_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_SYMMACVER_WAIT  /* HSM is waiting on the data from CSM */
}
Crypto_SymMacVerWorkType ;

typedef struct
{
        VAR(Crypto_SymKeyInfoType,CRY_APPL_DATA)                    keyInfo;
        P2CONST(uint8,TYPEDEF,CRY_APPL_DATA)                        datPtr;
        uint32                                                      datLen;
        P2CONST(uint8,TYPEDEF, CRY_APPL_DATA)                       macPtr;
        uint32                                                      macLength;
        P2VAR(Csm_VerifyResultType, TYPEDEF, CRY_APPL_DATA)         vfyPtr;
        Crypto_SymMacVerWorkType                                    work;
        Crypto_StateType                                            state;
        Crypto_StateType                                            stateRequested;
        uint8                                                       priority;
        uint8                                                       faultLog_U8;
        VAR(boolean,CRY_APPL_DATA)                                  LockedHsm_E;
        boolean                                                     DirectCall;
        uint8                                                       buffer[256];
        uint16                                                      len;
}
Crypto_SymMacVerStateType;

/*==[Declaration of functions with internal linkage]==========================*/



/** \brief  Calls the callback function, if needed, outside the lock semaphore code.
 **/
STATIC FUNC(void, CRY_CODE) Crypto_SymMacVerCallback(Csm_ReturnType param);

STATIC FUNC(void, CRY_CODE) Crypto_SymMacVerActionOnFault(void);
/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

 

STATIC VAR(Crypto_SymMacVerStateType, CRY_VAR) Crypto_SymMacVerState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SymMacVerNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptMacVerPackedData_S;

 

 

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_MacVerJob_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_MacVerJob_Error;

 


/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

/*---[Crypto_SymMacGenInit]------------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_SymMacVerInit(void)
{
    Crypto_SymMacVerState_S.state = Crypto_Idle;
    Crypto_SymMacVerState_S.stateRequested = Crypto_Idle;
    Crypto_SymMacVerState_S.datPtr  = NULL;
    Crypto_SymMacVerState_S.datLen  = 0u;
    Crypto_SymMacVerState_S.macPtr  = NULL;
    Crypto_SymMacVerState_S.vfyPtr  = NULL;
	Crypto_SymMacVerState_S.macLength  = 0u;
    Crypto_SymMacVerState_S.LockedHsm_E      = FALSE;
    Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SymMacVerState_S.work = CRYPTO_SYMMACVER_WAIT;
    vHsmCrypt_MacVerJob_Completed = FALSE;
    vHsmCrypt_MacVerJob_Error = FALSE;
}
/*---[Crypto_MacVerifyStart]-------------------------------------------*/

/* !LINKSTO CRYSHE_80, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyStart
(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr
)
{
    CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_MacVerifyConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) || (keyPtr == NULL ) )
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    else
    {
         Crypto_SymMacVerNotif_S.callbackNeeded = FALSE;
        Crypto_SymMacVerNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_MacVerifyConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymMacVerState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymMacVerState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymMacVerState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            /* CHECK: NOPARSE */
            /* Defensive programming. The true branch cannot be reached with the current state machine */
            if
            (
                    (Crypto_SymMacVerState_S.priority != CRYPTO_PRIORITY_NONE) &&
                    (Crypto_SymMacVerState_S.LockedHsm_E == TRUE)
            )
                /* CHECK: PARSE */
            {
                /* A MAC generation is already running and has to be cancelled. */
                Crypto_SymMacGenCancel();
            }
            if ( keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH )
            {
                Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacVerState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymMacVerState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymMacVerState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacVerState_S.state != Crypto_Cancel)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymMacVerState_S.stateRequested = Crypto_Start;
                }
#else
                Crypto_SymMacVerState_S.state = Crypto_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymMacVerState_S.priority = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymMacVerState_S.keyInfo.keyId = (keyPtr->data);
                vHsmCrypt_MacVerJob_Error = FALSE;
            }
                Crypto_SymMacVerState_S.LockedHsm_E = TRUE;
                vHsmCrypt_MacVerJob_Error = FALSE;
				vHsmCrypt_MacVerJob_Completed = FALSE;
				while(FALSE==vHsmCrypt_MacVerJob_Completed)
                {
                    if(FALSE != vHsmCrypt_MacVerJob_Error)
                    {
                        fl_ret_E = CSM_E_NOT_OK;
                        break;
                    }
                    else
                    {
                        Crypto_MacVerifyMainFunction();
                        vHsmIpc_HostManager_PeriodicCheck();
                        //CySldIpc_Isr_IpcDrv_Cat2();
                    }
                }
                Crypto_MacVerifyMainFunction();
                if(FALSE != vHsmCrypt_MacVerJob_Error)
                {
                    fl_ret_E = CSM_E_NOT_OK;
                }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif  /*CRYPTO_PRIORITY_ENABLED*/
    }
    CRYPTO_RELEASE_SEM();
    Crypto_SymMacVerCallback(Crypto_SymMacVerNotif_S.callbackParamValue);
    return fl_ret_E;
}

/*---[Crypto_MacVerifyUpdate]-------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyUpdate
(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
      VAR(uint32,            CRY_APPL_DATA) dataLength
)
{
  //CRYPTO_LOCK_SEM();
  Csm_ReturnType ret = CSM_E_OK;
  if(( Crypto_SymMacVerState_S.state == Crypto_Idle ) ||
     ( Crypto_SymMacVerState_S.state == Crypto_Cancel) ||
     ( Crypto_SymMacVerState_S.state == Crypto_Finish) ||
     ( Crypto_SymMacVerState_S.state == Crypto_Finish_Wait) )
  {
      ret = CSM_E_NOT_OK;
  }
  else
  {
      if
      (
        ( Crypto_SymMacVerState_S.state == Crypto_Update ) &&
        ( Crypto_SymMacVerState_S.work == CRYPTO_SYMMACVER_WAIT )
      )
      {
        /* !LINKSTO CRYSHE_209, 1
         */
          Crypto_SymMacVerState_S.datPtr     = dataPtr;
          Crypto_SymMacVerState_S.datLen     = dataLength;
          Crypto_SymMacVerState_S.macPtr     = NULL;
          Crypto_SymMacVerState_S.macLength  = 0;
          Crypto_SymMacVerState_S.work        = CRYPTO_SYMMACVER_WORK;
          vHsmCrypt_MacVerJob_Error = FALSE;
      }
      else if (( Crypto_SymMacVerState_S.state == Crypto_Start ) ||
              ( Crypto_SymMacVerState_S.state ==  Crypto_Start_Wait ))
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        /* Update can only be called once. */
        if (Crypto_SymMacVerState_S.LockedHsm_E == TRUE)
        {
            Crypto_SymMacVerCancel();
        }
        ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if(Crypto_SymMacVerState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacVerState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacVerState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacVerState_S.state = Crypto_Idle;
    #endif  /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1)    */
        Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
      }
  }
  //CRYPTO_RELEASE_SEM();

  return ret;
}

/*---[Crypto_MacVerifyFinish]-------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyFinish
(
  P2CONST(uint8,                AUTOMATIC, CSM_APPL_DATA) macPtr,
      VAR(uint32,               AUTOMATIC               ) macLength,
    P2VAR(Csm_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) resultPtr
)
{
  Csm_ReturnType ret = CSM_E_OK;

  //CRYPTO_LOCK_SEM();
  if ((macPtr == NULL) || (resultPtr == NULL) ||
          (macLength == 0u))
      {
          Crypto_SymMacVerCancel();
          ret = CSM_E_NOT_OK;
      }
  if(( Crypto_SymMacVerState_S.state == Crypto_Idle ) ||
     ( Crypto_SymMacVerState_S.state == Crypto_Cancel) ||
     ( Crypto_SymMacVerState_S.state == Crypto_Finish_Wait))
  {
      ret = CSM_E_NOT_OK;
  }
  if(CSM_E_OK == ret)
  {
      if
      (
        (Crypto_SymMacVerState_S.state == Crypto_Finish) &&
        (Crypto_SymMacVerState_S.work == CRYPTO_SYMMACVER_WAIT)
      )
      {
          Crypto_SymMacVerState_S.macPtr    = macPtr;
          Crypto_SymMacVerState_S.macLength = macLength;
          Crypto_SymMacVerState_S.vfyPtr = resultPtr;
          Crypto_SymMacVerState_S.work      = CRYPTO_SYMMACVER_WORK;
          ret = CSM_E_OK;
      }
      else
      if
      (
        ( Crypto_SymMacVerState_S.state == Crypto_Update ) &&
        ( Crypto_SymMacVerState_S.work == CRYPTO_SYMMACVER_WAIT )
      )
      {
        /* Update has not been called. This means we must compute MAC over 0
         * bytes.
         */
          Crypto_SymMacVerState_S.stateRequested = Crypto_Finish;
          Crypto_SymMacVerState_S.macLength = macLength;
          Crypto_SymMacVerState_S.macPtr    = macPtr;
          Crypto_SymMacVerState_S.work      = CRYPTO_SYMMACVER_WORK;
          Crypto_SymMacVerState_S.datLen    = 0U;
          vHsmCrypt_MacVerJob_Error = FALSE;
          ret = CSM_E_OK;
      }
      else if
      (
        ( Crypto_SymMacVerState_S.state == Crypto_Start ) ||
        ( Crypto_SymMacVerState_S.state == Crypto_Start_Wait ) ||
        ( Crypto_SymMacVerState_S.state == Crypto_Update ) ||
        ( Crypto_SymMacVerState_S.state == Crypto_Update_Wait )
      )
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        if(Crypto_SymMacVerState_S.LockedHsm_E == TRUE)
        {
            Crypto_SymMacVerCancel();
        }
        ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if( Crypto_SymMacVerState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacVerState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacVerState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacVerState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1)   */
        Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
      }

      if
      (
        (ret == CSM_E_OK) &&
        (Crypto_SymMacVerState_S.macLength > CRYPTO_HSM_MAX_CMAC_VERIFY_IN_BITS)
      )
      {
          Crypto_SymMacVerCancel();
        /* !LINKSTO CSM0662, 1
         */
        ret = CSM_E_SMALL_BUFFER;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        if( Crypto_SymMacVerState_S.state != Crypto_Cancel)
        {
            Crypto_SymMacVerState_S.state = Crypto_Idle;
        }
        else
        {
            Crypto_SymMacVerState_S.stateRequested = Crypto_Idle;
        }
    #else
        Crypto_SymMacVerState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
      }
  }
  //CRYPTO_RELEASE_SEM();

  return ret;
}

/*---[Crypto_MacVerifyMainFunction]------------------------------------------*/

/* !LINKSTO CRYSHE_252, 1
 */
FUNC(void,CRY_CODE) Crypto_MacVerifyMainFunction
(
  void
)
{
    Crypto_SymMacVerNotif_S.callbackNeeded = FALSE;
    Crypto_SymMacVerNotif_S.finishNeeded = FALSE;

    switch (Crypto_SymMacVerState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Cancel:
            if (TRUE == Crypto_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_SymMacVerState_S.stateRequested)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymMacVerState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything
                 * and do not give cancel here as the origin is cancel
                 * command callback not happened*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    if(Crypto_SymMacVerState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
                    {
                        Crypto_SymMacVerState_S.faultLog_U8++;
                    }
                    if(Crypto_SymMacVerState_S.stateRequested != Crypto_Finish)
                    {
                        Crypto_SymMacVerState_S.state =
                                Crypto_SymMacVerState_S.stateRequested;
                    }
                    else
                    {
                        Crypto_SymMacVerState_S.state = Crypto_Idle;
                    }
                    Crypto_ResetFaultCounter();
                }
            }
            break;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:
            Crypto_CryptMacVerPackedData_S.KeyId_U8 =
                (uint8)Crypto_SymMacVerState_S.keyInfo.keyId;
            Crypto_CryptMacVerPackedData_S.jobId_E = CID_27_MAC_VER_START;
            Crypto_CryptMacVerPackedData_S.priority_U8 = (te_jobpriority)0;
            Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P =
                NULL;
            Crypto_CryptMacVerPackedData_S.payLoadSize = 0u;
            vHsmCrypt_MacVerJob_Completed = FALSE;
            if (E_OK == Crypto_SendPackedData(Crypto_CryptMacVerPackedData_S))
            {
                Crypto_SymMacVerState_S.state = Crypto_Start_Wait;
                Crypto_ResetFaultCounter();
            }
            else
            {
                Crypto_SymMacVerActionOnFault();
            }
            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_MacVerJob_Completed)
            {
                if(FALSE == vHsmCrypt_MacVerJob_Error)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Update;
                    Crypto_SymMacVerState_S.work  = CRYPTO_SYMMACVER_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                    Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymMacVerActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_SymMacVerActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Update:
            if ( Crypto_SymMacVerState_S.work == CRYPTO_SYMMACVER_WORK )
            {
                /* Pack data to do MAC verify */
                Crypto_CryptMacVerPackedData_S.KeyId_U8 =
                        (uint8)Crypto_SymMacVerState_S.keyInfo.keyId;
                Crypto_CryptMacVerPackedData_S.jobId_E = CID_28_MAC_VER_UPDATE;
                Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P =
                        (uint8 *)Crypto_SymMacVerState_S.datPtr;
                Crypto_CryptMacVerPackedData_S.payLoadSize = Crypto_SymMacVerState_S.datLen;
                Crypto_CryptMacVerPackedData_S.priority_U8 = (te_jobpriority)0;
                vHsmCrypt_MacVerJob_Completed = FALSE;
                if (E_OK == Crypto_SendPackedData(Crypto_CryptMacVerPackedData_S))
                {
                    Crypto_SymMacVerState_S.state = Crypto_Update_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_SymMacVerActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for updates from CSM application */
            }
            break;
        case Crypto_Update_Wait:
            if (TRUE == vHsmCrypt_MacVerJob_Completed)
            {
                if(FALSE == vHsmCrypt_MacVerJob_Error)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Finish;
                    if(Crypto_SymMacVerState_S.stateRequested == Crypto_Finish)
                    {
                        /* Already finish alone sent from CSM appln for
                        calculating MAC over 0 bytes */
                        Crypto_SymMacVerState_S.work  = CRYPTO_SYMMACVER_WORK;
                    }
                    else
                    {
                        /* To receive finish from CSM appln */
                        Crypto_SymMacVerState_S.work  = CRYPTO_SYMMACVER_WAIT;
                    }
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                    Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymMacVerActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_SymMacVerActionOnFault();
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
                        (Crypto_SymMacVerState_S.keyInfo.keyId == CRYPTO_SHE_RAM_KEY         ) &&
                        (Crypto_SymMacVerState_S.keyInfo.keyNr != Crypto_SymKeyInfo.keyNr)
                )
                {
                    Crypto_SymMacVerActionOnFault();
                }
                else
                {
                    if(FALSE != Crypto_SymMacVerState_S.DirectCall)
                    {
                        if(FALSE != Crypto_SymMacVerState_S.LockedHsm_E)
                        {
                            if(INT16_MAX_RANGE >= Crypto_SymMacVerState_S.keyInfo.keyId)
                            {
                                Crypto_CryptMacVerPackedData_S.KeyId_U8             = (uint8)Crypto_SymMacVerState_S.keyInfo.keyId;
                                Crypto_CryptMacVerPackedData_S.jobId_E              = CID_26_MAC_VER_FN;
                                Crypto_CryptMacVerPackedData_S.priority_U8          = (te_jobpriority)0;
                                //Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P       = (uint8 *)Crypto_SymMacVerState_S.macPtr;
                                Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P       = (uint8 *)&Crypto_SymMacVerState_S.buffer[0];
                                //Crypto_CryptMacVerPackedData_S.payLoadSize          = Crypto_SymMacVerState_S.macLength;
                                Crypto_CryptMacVerPackedData_S.payLoadSize          = Crypto_SymMacVerState_S.len;
                                vHsmCrypt_MacVerJob_Completed                       = FALSE;
                                if (E_OK == Crypto_SendPackedData(Crypto_CryptMacVerPackedData_S))
                                {
                                Crypto_SymMacVerState_S.state = Crypto_Finish_Wait;
                                Crypto_ResetFaultCounter();
                                }
                                else
                                {
                                Crypto_SymMacVerActionOnFault();
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
                        if(INT16_MAX_RANGE >= Crypto_SymMacVerState_S.keyInfo.keyId)
                        {
                                 Crypto_CryptMacVerPackedData_S.KeyId_U8             = (uint8)Crypto_SymMacVerState_S.keyInfo.keyId;
                                Crypto_CryptMacVerPackedData_S.jobId_E              = CID_25_MAC_VER_FINISH;
                                Crypto_CryptMacVerPackedData_S.priority_U8          = (te_jobpriority)0;
                                //Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P       = (uint8 *)Crypto_SymMacVerState_S.macPtr;
                                Crypto_CryptMacVerPackedData_S.payLoadPtr_U8P       = (uint8 *)&Crypto_SymMacVerState_S.buffer[0];
                                //Crypto_CryptMacVerPackedData_S.payLoadSize          = Crypto_SymMacVerState_S.macLength;
                                Crypto_CryptMacVerPackedData_S.payLoadSize          = Crypto_SymMacVerState_S.len;
                                vHsmCrypt_MacVerJob_Completed                       = FALSE;
                                if (E_OK == Crypto_SendPackedData(Crypto_CryptMacVerPackedData_S))
                                {
                                Crypto_SymMacVerState_S.state = Crypto_Finish_Wait;
                                Crypto_ResetFaultCounter();
                                }
                                else
                                {
                                Crypto_SymMacVerActionOnFault();
                                }
                        }
                        else
                        {
                            /*Handle the case of overflow*/
                        }
                    }
                }
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_MacVerJob_Completed)
            {
                Crypto_SymMacVerState_S.state = Crypto_Idle;
                Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacVerNotif_S.finishNeeded = TRUE;
                Crypto_SymMacVerState_S.work  = CRYPTO_SYMMACVER_WAIT;
                Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_MacVerJob_Error)
                {
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SymMacVerState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_SymMacVerActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        default:
            break;
    }
    Crypto_SymMacVerCallback(Crypto_SymMacVerNotif_S.callbackParamValue);
}

FUNC(void, CRY_CODE) Crypto_MacVerCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    static uint32 fl_MacVerResLen;
    uint32 result_val;
    uint8 status = *p_resultBytesInSRAM_U8P;
    switch (Crypto_SymMacVerState_S.state)
    {
    case Crypto_Start_Wait:
        vHsmCrypt_MacVerJob_Completed = TRUE;
        if (((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
        {
            /* Do nothing, as this is the success case */
        }
        else
        {
            vHsmCrypt_MacVerJob_Error = TRUE;
        }
        break;
    case Crypto_Update_Wait:
        vHsmCrypt_MacVerJob_Completed = TRUE;
        if (((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
        {
            /* Do nothing, as this is the success case */
        }
        else
        {
            vHsmCrypt_MacVerJob_Error = TRUE;
        }
        break;
    case Crypto_Finish_Wait:
        fl_MacVerResLen = (uint32)payload_size - (uint32)1;
        vHsmCrypt_MacVerJob_Completed = TRUE;
        //if (Crypto_SymMacVerState_S.vfyPtr != NULL)
        //{
            if (((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                ((uint32)0x04 == fl_MacVerResLen))
            {
                /* Copy the result data verify result is
                             * 4 bytes, into the memory
                        location shared from application */
                (void)memcpy((uint8 *)&result_val,
                             (uint8 *)&p_resultBytesInSRAM_U8P[1],
                             (uint16)4);
                if (result_val == (0x01u))
                {
                    /*  *(Crypto_SymMacVerState_S.vfyPtr) = CSM_E_VER_NOT_OK; */
                    *(Crypto_SymMacVerState_S.vfyPtr) = CSM_E_VER_NOT_OK;
                }
                else
                {
                    /*   *(Crypto_SymMacVerState_S.vfyPtr) = CSM_E_VER_OK; */
                    *(Crypto_SymMacVerState_S.vfyPtr) = CSM_E_VER_OK;
                }
            }
            else
            {
                vHsmCrypt_MacVerJob_Error = TRUE;
            }
        // }
        // else
        // {
        //     vHsmCrypt_MacVerJob_Error = TRUE;
        // }
        break;
    default:
        break;
    }
}

/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_SymMacVerCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SymMacVerNotif_S.callbackNeeded)
    {
        Crypto_SymMacVerNotif_S.callbackNeeded = FALSE;
        CRYPTO_CSM_MACVERIFY_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SymMacVerNotif_S.finishNeeded)
    {
        Crypto_SymMacVerNotif_S.finishNeeded = FALSE;
        CRYPTO_CSM_MACVERIFY_SERVICE_FINISH_NOTIF;
    }
}


FUNC(void, CRY_CODE) Crypto_SymMacVerCancel(void)
{
    Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SymMacVerState_S.state = Crypto_Cancel;
#else
    Crypto_SymMacVerState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_SymMacVerState_S.LockedHsm_E != FALSE)
    {
        Crypto_SymMacVerState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }
    (void)Crypto_She_Cancel(e_aescmaccommon);
}

STATIC FUNC(void, CRY_CODE) Crypto_SymMacVerActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_SymMacVerState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SymMacVerState_S.faultLog_U8++;
    }
    Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
    Crypto_SymMacVerNotif_S.finishNeeded = TRUE;
    Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_SymMacVerCancel();
    Crypto_ResetFaultCounter();
}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacVerify_S
(
                P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
                P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
                VAR(uint32,            CRY_APPL_DATA) dataLength,
                P2CONST(uint8,                AUTOMATIC, CSM_APPL_DATA) macPtr,
                VAR(uint32,               AUTOMATIC               ) macLength,
                P2VAR(Csm_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) resultPtr
)
{
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    uint32 fl_TotalBufflength_U32;
    P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_src1_U8P;
    P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_src2_U8P;
    P2CONST(Crypto_She_MacVerifyConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (keyPtr == NULL)||(cfgPtr == NULL) ||
        (dataPtr == NULL) || (dataLength == 0u) || (macPtr == NULL) || (macLength == 0u) || (resultPtr == NULL))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymMacVerNotif_S.callbackNeeded = FALSE;
        Crypto_SymMacVerNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_MacVerifyConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymMacVerState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymMacVerState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymMacVerState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }

        if (CSM_E_OK == fl_ret_E)
        {
#endif   /*CRYPTO_PRIORITY_ENABLED*/
            if (keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH)
            {
                Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymMacVerNotif_S.callbackNeeded = TRUE;
                Crypto_SymMacVerNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacVerState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Hsm_Idle;
                }
                else
                {
                    Crypto_SymMacVerState_S.stateRequested = Crypto_Hsm_Idle;
                }
#else
                Crypto_SymMacVerState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymMacVerState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymMacVerState_S.state = Crypto_Hsm_Finish;
                }
                else
                {
                    Crypto_SymMacVerState_S.stateRequested = Crypto_Hsm_Finish;
                }
#else
                
                /*Packing Inputdata and InputMac to buffer*/
                (void)memset(&Crypto_SymMacVerState_S.buffer[0], 0U, sizeof(Crypto_SymMacVerState_S.buffer));
                fl_ptr_src1_U8P = (uint8 *)dataPtr;
                fl_ptr_src2_U8P = (uint8 *)macPtr;
                (void)memcpy(&Crypto_SymMacVerState_S.buffer[0],fl_ptr_src1_U8P, dataLength);
                (void)memcpy(&Crypto_SymMacVerState_S.buffer[0U+dataLength],fl_ptr_src2_U8P, macLength);
                (void)memcpy(&Crypto_SymMacVerState_S.buffer[dataLength+macLength],(uint8 *)&dataLength,4U);
                (void)memcpy(&Crypto_SymMacVerState_S.buffer[dataLength+macLength+4U], (uint8 *)&macLength,4U);
                fl_TotalBufflength_U32 = dataLength+macLength+8uL;
                if(INT16_MAX_RANGE >= fl_TotalBufflength_U32) 
                {
                    Crypto_SymMacVerState_S.len = (uint8)fl_TotalBufflength_U32;
                }
                else
                {
                     /*Handle the case of overflow*/
                }
                 
                Crypto_SymMacVerState_S.state       = Crypto_Finish;
                Crypto_SymMacVerState_S.DirectCall  = TRUE; 
                Crypto_SymMacVerState_S.vfyPtr      = resultPtr;
                Crypto_SymMacVerState_S.work        = CRYPTO_SYMMACVER_WORK;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymMacVerState_S.priority = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymMacVerState_S.keyInfo.keyId = (keyPtr->data);
                Crypto_SymMacVerState_S.LockedHsm_E = TRUE;
                vHsmCrypt_MacVerJob_Completed = FALSE;
                vHsmCrypt_MacVerJob_Error = FALSE;

                while(FALSE == vHsmCrypt_MacVerJob_Completed)
                {
                    if(FALSE != vHsmCrypt_MacVerJob_Error)
                    {
                        fl_ret_E = CSM_E_NOT_OK;                    
                        break;
                    }
                    else
                    {
                        Crypto_MacVerifyMainFunction();
                        vHsmIpc_HostManager_PeriodicCheck();
                        //CySldIpc_Isr_IpcDrv_Cat2();
                    }

                }
                Crypto_SymMacVerState_S.state = Crypto_Idle;
                Crypto_SymMacVerState_S.priority = CRYPTO_PRIORITY_NONE;

            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif /*CRYPTO_PRIORITY_ENABLED*/
    }
    return fl_ret_E;
}


#endif /* #if (CRYPTO_MACVERIFY_ENABLED == 1) */
