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
 * \file Crypto_SymKeyExtract.c
 *
 * \brief
 * Key extract implementation in M7
 *
 * \detailed description
 *  This file shall be the Key extract implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
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
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/* !LINKSTO CSM0692, 1
 */

/*==[Includes]================================================================*/
#include "Crypto.h"
#include "Crypto_She.h"
#include "Crypto_SymKeyExtract.h"
#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "vHsmCryptoManager.h"
#if (CRYPTO_SYMKEYEXTRACT_ENABLED == 1)
/*==[Macros]==================================================================*/

/* expression for determination of keyid from dlc */
#define CRYPTO_SYMKEYEXTRACT_SLOT                                                          \
(                                                                                           \
  (uint8)(                                                                                  \
    (uint8)(((P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA))Crypto_SymKeyExtractState_S.buffer)[15U])\
      >> 4U                                                                                 \
  ) &                                                                                       \
  (uint8)0x0FU                                                                              \
)

/** \brief The maximal length of a key container */
#define CRYPTO_SYMKEYEXTRACT_MAX_LEN        ((uint32)64)

/* timeout config for key storage is kept as 5secs*/
/* Fault counter max value arrived by dividing the max timeout of 5000ms
 * by the scheduling rate - 10ms, 1000ms/10ms = 100 */
#define KEY_STORE_FAULT_COUNTER_MAX_VAL      ((uint32)500)
/*==[Types]===================================================================*/

typedef enum
{
  CRYPTO_SYMKEYEXTRACT_WORK,/* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
  CRYPTO_SYMKEYEXTRACT_WAIT/* HSM is waiting on the data from CSM */
}
Crypto_SymKeyExtractWorkType;

typedef struct
{
  Crypto_SymKeyInfoType keyInfo;
  Crypto_SymKeyExtractWorkType work;
  uint32 buffer[CRYPTO_SYMKEYEXTRACT_MAX_LEN/(uint32)sizeof(uint32)];
  uint32 len;
  P2VAR(Csm_SymKeyType,TYPEDEF,CRY_APPL_DATA) keyPtr;
  Crypto_StateType  state;
  Crypto_StateType  stateRequested;
  uint8   priority;
  uint16   faultLog_U8;
  boolean LockedHsm_E;
#if 0 
#if (CRYPTO_FLASH_ARBITRATION_BY_SW == STD_ON)
  uint16  noFlashWriteRetries;
#endif
#endif
}
Crypto_SymKeyExtractStateType;
/*==[Declaration of functions with internal linkage]==========================*/



STATIC FUNC(void, CRY_CODE) Crypto_SymKeyExtractWork(void);

/** \brief  Calls the callback function, if needed, outside the lock semaphore code.
 **/
STATIC FUNC(void, CRY_CODE) Crypto_SymkeyExtractCallback(Csm_ReturnType param);

STATIC FUNC(void, CRY_CODE) Crypto_SymkeyExtractActionOnFault(void);

static FUNC(boolean, CRY_CODE) Crypto_CheckFaultKeyExtractPeriodic(void );


/*==[Variables with internal linkage]=========================================*/

 

STATIC VAR(Crypto_SymKeyExtractStateType, CRY_VAR) Crypto_SymKeyExtractState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SymKeyExtractNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptKeyExtractPackedData_S;



 

 
STATIC VAR(boolean, CRY_VAR) vHsmCrypt_KeyExtract_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_KeyExtract_error;

 

 
STATIC VAR(uint32, CRY_VAR) l_KeyExtractFaultCounter_U32;
 



/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/
/*---[Crypto_SymKeyExtractInit]------------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_SymKeyExtractInit(void)
{
    Crypto_SymKeyExtractState_S.state = Crypto_Idle;
    Crypto_SymKeyExtractState_S.stateRequested = Crypto_Idle;
    Crypto_SymKeyExtractState_S.len = 0u;
    Crypto_SymKeyExtractState_S.keyPtr = NULL;
    Crypto_SymKeyExtractState_S.LockedHsm_E      = FALSE;
    Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WAIT;
    vHsmCrypt_KeyExtract_Completed = FALSE;
    vHsmCrypt_KeyExtract_error = FALSE;
    l_KeyExtractFaultCounter_U32 = 0u;
}

/*---[Crypto_SymKeyExtractStart]---------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractStart
(
  P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr
)
{
  Csm_ReturnType ret = CSM_E_OK;
  P2CONST(Crypto_SymKeyExtractConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
  //CRYPTO_LOCK_SEM();
  if((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) || (Crypto_SymKeyExtractState_S.state != Crypto_Idle))
  {
    ret = CSM_E_NOT_OK;
  }
 
  if (CSM_E_OK == ret)
  {
    locCfgPtr = (P2CONST(Crypto_SymKeyExtractConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    if( Crypto_SymKeyExtractState_S.state != Crypto_Cancel)
    {
        Crypto_SymKeyExtractState_S.state = Crypto_Start;
    }
    else
    {
        Crypto_SymKeyExtractState_S.stateRequested = Crypto_Start;
    }
#else
    Crypto_SymKeyExtractState_S.state = Crypto_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    Crypto_SymKeyExtractState_S.priority = locCfgPtr->priority;
    Crypto_SymKeyExtractState_S.len = 0;
    Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WORK;
    vHsmCrypt_KeyExtract_Completed = FALSE;
    vHsmCrypt_KeyExtract_error = FALSE;
    l_KeyExtractFaultCounter_U32 = 0u;
  }
  //CRYPTO_RELEASE_SEM();
  return ret;
}

/*---[Crypto_SymKeyExtractUpdate]--------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractUpdate
(
  P2CONST(uint8,AUTOMATIC,CRY_APPL_DATA) dataPtr,
  uint32 dataLength
)
{
  uint32 fl_index_U32;
  P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_U8P;
  Csm_ReturnType ret = CSM_E_OK;

  //CRYPTO_LOCK_SEM();
  if ((dataPtr == NULL) || (dataLength == 0u) || (dataLength > CRYPTO_SYMKEYEXTRACT_MAX_LEN))
  {
      ret = CSM_E_NOT_OK;
      Crypto_SymKeyExtractCancel();
  }
  if(( Crypto_SymKeyExtractState_S.state == Crypto_Idle ) ||
      ( Crypto_SymKeyExtractState_S.state == Crypto_Cancel) ||
      ( Crypto_SymKeyExtractState_S.state == Crypto_Finish) ||
      ( Crypto_SymKeyExtractState_S.state == Crypto_Finish_Wait))
  {
      ret = CSM_E_NOT_OK;
  }
  if(CSM_E_OK == ret)
  {
      if
      (
        (Crypto_SymKeyExtractState_S.state == Crypto_Update) &&
        (Crypto_SymKeyExtractState_S.work == CRYPTO_SYMKEYEXTRACT_WAIT)
      )
      {
        if ((dataLength + Crypto_SymKeyExtractState_S.len) > CRYPTO_SYMKEYEXTRACT_MAX_LEN)
        {
          ret = CSM_E_NOT_OK;
          Crypto_SymKeyExtractState_S.state = Crypto_Idle;
          Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
        }
        else
        {
            /* Deviation MISRA-2 <+1> */
            fl_ptr_U8P = (uint8 *)Crypto_SymKeyExtractState_S.buffer;
            fl_ptr_U8P = &fl_ptr_U8P[Crypto_SymKeyExtractState_S.len];
            for(fl_index_U32 = 0; fl_index_U32 < dataLength; fl_index_U32++)
            {
                fl_ptr_U8P[fl_index_U32] = dataPtr[fl_index_U32];
            }
            Crypto_SymKeyExtractState_S.len += dataLength;
        }
        vHsmCrypt_KeyExtract_error = FALSE;
        Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WORK;
      }
      else if
      (
              ( Crypto_SymKeyExtractState_S.state == Crypto_Update ) ||
              ( Crypto_SymKeyExtractState_S.state == Crypto_Start_Wait ) ||
              ( Crypto_SymKeyExtractState_S.state == Crypto_Update_Wait ) ||
              ( Crypto_SymKeyExtractState_S.state == Crypto_Start )
      )
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        if (Crypto_SymKeyExtractState_S.LockedHsm_E == TRUE)
        {
          Crypto_SymKeyExtractCancel();
        }
        ret = CSM_E_NOT_OK;
        Crypto_SymKeyExtractState_S.state = Crypto_Idle;
        Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
      }
  }
  //CRYPTO_RELEASE_SEM();
  return ret;
}


FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractFinish
(
      VAR(uint8,            CRY_APPL_DATA) keyId
)
{
  Csm_ReturnType ret = CSM_E_OK;

  //CRYPTO_LOCK_SEM();

  if(( Crypto_SymKeyExtractState_S.state == Crypto_Idle ) ||
     ( Crypto_SymKeyExtractState_S.state == Crypto_Cancel) ||
     ( Crypto_SymKeyExtractState_S.state == Crypto_Finish_Wait))
  {
      ret = CSM_E_NOT_OK;
  }
  if(CSM_E_OK == ret)
  {
      if
      (
        (Crypto_SymKeyExtractState_S.state == Crypto_Update) &&
        (Crypto_SymKeyExtractState_S.work == CRYPTO_SYMKEYEXTRACT_WAIT)
      )
      {
        if
        (
          (Crypto_SymKeyExtractState_S.len == CRYPTO_SYMKEYEXTRACT_MAX_LEN) ||
          (Crypto_SymKeyExtractState_S.len == CRYPTO_HSM_BLOCK_LENGTH     ) ||
          (Crypto_SymKeyExtractState_S.len == 1                            )
        )
        {
          Crypto_SymKeyExtractState_S.keyInfo.keyId = keyId;
          Crypto_SymKeyExtractState_S.state  = Crypto_Finish;
          Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WORK;
          ret = CSM_E_OK;
        }
        else
        {
          Crypto_SymKeyExtractState_S.state = Crypto_Idle;
          Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
          ret = CSM_E_NOT_OK;
        }
      }
      else if
      (
        (Crypto_SymKeyExtractState_S.state == Crypto_Update) ||
        (Crypto_SymKeyExtractState_S.state == Crypto_Start)
      )
      {
        ret = CSM_E_BUSY;
      }
      else
      {
        if(Crypto_SymKeyExtractState_S.LockedHsm_E == TRUE)
        {
          Crypto_SymKeyExtractCancel();
        }
        ret = CSM_E_NOT_OK;
        Crypto_SymKeyExtractState_S.state = Crypto_Idle;
        Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
      }
  }
  //CRYPTO_RELEASE_SEM();

  return ret;
}



FUNC(void,CRY_CODE) Crypto_SymKeyExtractMainFunction(void)
{
    Crypto_SymKeyExtractNotif_S.callbackNeeded = FALSE;
    Crypto_SymKeyExtractNotif_S.finishNeeded = FALSE;
    switch (Crypto_SymKeyExtractState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Cancel:
            if (TRUE == Crypto_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_SymKeyExtractState_S.stateRequested)
                {
                    Crypto_SymKeyExtractState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymKeyExtractState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /*#if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:
            if(CRYPTO_SYMKEYEXTRACT_WORK == Crypto_SymKeyExtractState_S.work)
            {
                Crypto_SymKeyExtractState_S.state = Crypto_Update;
                Crypto_SymKeyExtractState_S.work  = CRYPTO_SYMKEYEXTRACT_WAIT;

                /* !LINKSTO CRYSHE_290_1, 1
                 */
                Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
                Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
            }
            break;
        case Crypto_Update:
            if ( Crypto_SymKeyExtractState_S.work == CRYPTO_SYMKEYEXTRACT_WORK )
            {
                Crypto_SymKeyExtractState_S.work  = CRYPTO_SYMKEYEXTRACT_WAIT;
#if 0
#if (CRYPTO_FLASH_ARBITRATION_BY_SW == STD_ON)
                Crypto_SymKeyExtractState_S.noFlashWriteRetries = 0U;
#endif
#endif
                /* !LINKSTO CRYSHE_290_1, 1
                 */
                Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
                Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
            }
            break;
        case Crypto_Finish:
            Crypto_SymKeyExtractWork();
            break;
        case Crypto_Finish_Wait:
            if( CRYPTO_SYMKEYEXTRACT_WAIT == Crypto_SymKeyExtractState_S.work)
            {
                if (Crypto_SymKeyExtractState_S.LockedHsm_E == TRUE)
                {
                    Crypto_CryptKeyExtractPackedData_S.KeyId_U8 =
                            Crypto_SymKeyExtractState_S.keyInfo.keyId;
                    Crypto_CryptKeyExtractPackedData_S.jobId_E = CID_62_SYM_EXTRACT_FINISH;
                    Crypto_CryptKeyExtractPackedData_S.priority_U8 = (te_jobpriority)0;
                    Crypto_CryptKeyExtractPackedData_S.payLoadPtr_U8P =
                            (uint8 *)Crypto_SymKeyExtractState_S.buffer;
                    Crypto_CryptKeyExtractPackedData_S.payLoadSize =
                            Crypto_SymKeyExtractState_S.len;
                    vHsmCrypt_KeyExtract_Completed = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_CryptKeyExtractPackedData_S))
                    {
                        Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WORK;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_SymkeyExtractActionOnFault();
                    }
                }
                else
                {
                    Crypto_SymkeyExtractActionOnFault();
                }
            }
            else
            {
                /* CRYPTO_SYMKEYEXTRACT_WORK == Crypto_SymKeyExtractState_S.work */
                if (TRUE == vHsmCrypt_KeyExtract_Completed)
                {
                    if(FALSE == vHsmCrypt_KeyExtract_error)
                    {
                        /* update key info details to the finish
                         * keyptr for any crypto needs */
#if 0
                         memcpy((uint8 *) (Crypto_SymKeyExtractState_S.keyPtr->data),
                                 (uint8 *)&Crypto_SymKeyExtractState_S.keyInfo, sizeof(Crypto_SymKeyInfoType ));

                        Crypto_SymKeyExtractState_S.keyPtr->length =
                                sizeof(Crypto_SymKeyExtractState_S.keyInfo);
#endif                                

                        Crypto_SymKeyInfo = Crypto_SymKeyExtractState_S.keyInfo;
                        Crypto_SymKeyExtractState_S.LockedHsm_E = FALSE;
                        CRYPTO_RELEASE_HSM();
                        Crypto_SymKeyExtractState_S.state = Crypto_Idle;
                        Crypto_SymKeyExtractState_S.work  = CRYPTO_SYMKEYEXTRACT_WAIT;
                        /* !LINKSTO CRYSHE_290_3, 1
                         */
                        Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
                        Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                        //Patch!!!!
                        Crypto_SymKeyExtractNotif_S.finishNeeded = TRUE;
                        Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
                    }
                    else
                    {
                        /* Only do the cancel after the max number
                         * of retries over */
                        {
#if 0
#if (CRYPTO_FLASH_ARBITRATION_BY_SW == STD_ON)
                            /* !LINKSTO CRYSHE_ARM_S6J3200_FLASH_1, 1 */
                            /* Deviation MISRA-1 <+1> */
                            if(Crypto_SymKeyExtractState_S.noFlashWriteRetries <= CRYPTO_FLASHWRITE_MAX_RETRIES)
                            {
                                Crypto_SymKeyExtractState_S.state = Crypto_Finish_Wait;
                                Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WAIT;
                            }
                            else
                            {
                                Crypto_SymKeyExtractState_S.noFlashWriteRetries = 0U;
#endif /* (CRYPTO_FLASH_ARBITRATION_BY_SW == STD_ON) */
#endif
                                /* command processing done */
                                /* !LINKSTO CRYSHE_71, 1
                                 */
                                Crypto_SymKeyExtractState_S.state = Crypto_Idle;
                                Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
                                /* !LINKSTO CRYSHE_290_1, 1
                                 */
                                Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
                                Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                                Crypto_SymKeyExtractState_S.LockedHsm_E = FALSE;
                                CRYPTO_RELEASE_HSM();
                                /* !LINKSTO CRYSHE_290_2, 1
                                 */
                                Crypto_SymKeyExtractNotif_S.finishNeeded = TRUE;
#if 0
#if (CRYPTO_FLASH_ARBITRATION_BY_SW == STD_ON)
                            }
#endif
#endif
                        }
                    }
                }
                else
                {
                    /* Keep waiting for callback from M0P
                     * if no response for 1sec, then, reset everything*/
                    if (TRUE == Crypto_CheckFaultKeyExtractPeriodic())
                    {
                        Crypto_SymkeyExtractActionOnFault();
                    }
                    else
                    {
                        /* Wait for the fault counter to expire to reset all
                         * which is handled in the above if condition */
                    }
                }
            }
            break;
        default:
            break;
    }
    Crypto_SymkeyExtractCallback(Crypto_SymKeyExtractNotif_S.callbackParamValue);
}

FUNC(void, CRY_CODE) Crypto_KeyExtractCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint8 status = *p_resultBytesInSRAM_U8P;
    if (Crypto_SymKeyExtractState_S.LockedHsm_E == TRUE)
    {
        switch (Crypto_SymKeyExtractState_S.state)
        {
            case Crypto_Finish_Wait:
                vHsmCrypt_KeyExtract_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_KeyExtract_error = TRUE;
                }
                break;
            default:
                break;
        }
    }
}
/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_SymkeyExtractCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SymKeyExtractNotif_S.callbackNeeded)
    {
        Crypto_SymKeyExtractNotif_S.callbackNeeded = FALSE;
        CRYPTO_CSM_SYMKEYEXTRACT_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SymKeyExtractNotif_S.finishNeeded)
    {
        Crypto_SymKeyExtractNotif_S.finishNeeded = FALSE;
        CRYPTO_CSM_SYMKEYEXTRACT_SERVICE_FINISH_NOTIF;
    }
}

FUNC(void, CRY_CODE) Crypto_SymKeyExtractCancel(void)
{
    Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SymKeyExtractState_S.state = Crypto_Cancel;
#else
    Crypto_SymKeyExtractState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_SymKeyExtractState_S.LockedHsm_E != FALSE)
    {
        Crypto_SymKeyExtractState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }

}

STATIC FUNC(void, CRY_CODE) Crypto_SymkeyExtractActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 5sec */
    if(Crypto_SymKeyExtractState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SymKeyExtractState_S.faultLog_U8++;
    }
    Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
    Crypto_SymKeyExtractNotif_S.finishNeeded = TRUE;
    Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_SymKeyExtractCancel();
    l_KeyExtractFaultCounter_U32 = 0u;
}

STATIC FUNC(void, CRY_CODE) Crypto_SymKeyExtractWork(void)
{
            /* !LINKSTO CRYSHE_70, 1
             */
    if (Crypto_SymKeyExtractState_S.len == 1) /* x.len == 1 */
    {
#if 0         
        Crypto_SymKeyExtractState_S.keyInfo.keyId = keyId;
       
        Crypto_SymKeyExtractState_S.keyInfo.keyNr = Crypto_SymKeyInfo.keyNr + 0U;
        /* Deviation MISRA-2 <+4> */
        (void)memcpy((uint8 *)(Crypto_SymKeyExtractState_S.keyPtr->data),
                     (uint8 *)&Crypto_SymKeyExtractState_S.keyInfo, sizeof(Crypto_SymKeyInfoType));

        Crypto_SymKeyExtractState_S.keyPtr->length =
            sizeof(Crypto_SymKeyExtractState_S.keyInfo);
#endif
        Crypto_SymKeyInfo = Crypto_SymKeyExtractState_S.keyInfo;

        /* command processing done */
        /* !LINKSTO CRYSHE_71, 1
                 */
        Crypto_SymKeyExtractState_S.state = Crypto_Idle;
        Crypto_SymKeyExtractState_S.priority = CRYPTO_PRIORITY_NONE;
        /* !LINKSTO CRYSHE_290_1, 1
                 */
        Crypto_SymKeyExtractNotif_S.callbackNeeded = TRUE;
        Crypto_SymKeyExtractNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
        Crypto_SymKeyExtractState_S.LockedHsm_E = FALSE;
        /* !LINKSTO CRYSHE_290_2, 1
                 */
        Crypto_SymKeyExtractNotif_S.finishNeeded = TRUE;
    }
    else
    {
        if (Crypto_SymKeyExtractState_S.LockedHsm_E == FALSE)
        {
            Crypto_SymKeyExtractState_S.LockedHsm_E = Crypto_LockShe();
        }
        else
        {
            /* Acquired lock of HSM */
            if (Crypto_SymKeyExtractState_S.len == CRYPTO_SYMKEYEXTRACT_MAX_LEN) /* x.len == 64 */
            {
                /* load encoded key */
                /* !LINKSTO CRYSHE_15_1, 1
             */
                /* Deviation MISRA-2 <+1> */
                if (CRYPTO_SYMKEYEXTRACT_SLOT == CRYPTO_SHE_RAM_KEY)
                {
                    /* !LINKSTO CRYSHE_40, 1
                 */
                    Crypto_SymKeyExtractState_S.keyInfo.keyNr = Crypto_SymKeyInfo.keyNr + 1U;
                }
                else
                {
                    Crypto_SymKeyExtractState_S.keyInfo.keyNr = Crypto_SymKeyInfo.keyNr + 0U;
                }
                /* Deviation MISRA-2 <+1> */
                Crypto_SymKeyExtractState_S.keyInfo.keyId = CRYPTO_SYMKEYEXTRACT_SLOT;
                Crypto_SymKeyExtractState_S.state = Crypto_Finish_Wait;
                Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WAIT;
            }
            else
            {
                /* !LINKSTO CRYSHE_69, 1
             */
                if (Crypto_SymKeyExtractState_S.len == CRYPTO_HSM_BLOCK_LENGTH) /* x.len == 16 */
                {
                    /* load plain key */
                    /* !LINKSTO CRYSHE_15_2, 1
                 */
                    Crypto_SymKeyExtractState_S.keyInfo.keyId = CRYPTO_SHE_RAM_KEY;
                    Crypto_SymKeyExtractState_S.keyInfo.keyNr = Crypto_SymKeyInfo.keyNr + 1U;
                    Crypto_SymKeyExtractState_S.state = Crypto_Finish_Wait;
                    Crypto_SymKeyExtractState_S.work = CRYPTO_SYMKEYEXTRACT_WAIT;
                }
            }
        }
    }
}

/*---[Crypto_CheckFaultKeyExtractPeriodic]-----------------------------------------------------*/
static FUNC(boolean, CRY_CODE) Crypto_CheckFaultKeyExtractPeriodic(void )
{
    boolean fl_ret_E = FALSE;
    if(l_KeyExtractFaultCounter_U32 >= KEY_STORE_FAULT_COUNTER_MAX_VAL )
    {
        fl_ret_E = TRUE;
    }
    else
    {
        l_KeyExtractFaultCounter_U32++;
    }
    return(fl_ret_E);
}

#endif
/*****************************************************************************
Date              :30/Dec/2020
By                :bjayara2
Traceability      : 1061554: [VW FPK8] HSM: AUTOSAR CRY Wrapper
Change Description: Initial version
 ******************************************************************************/
