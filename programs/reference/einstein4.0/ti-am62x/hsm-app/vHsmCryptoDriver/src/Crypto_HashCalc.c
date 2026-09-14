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
 * \file Crypto_HashCalc.c
 *
 * \brief
 * Hash Calc implementation in M7
 *
 * \detailed description
 *  This file shall be the Hash Calc implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *
 * \version 1.0.00
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 12/Mar/'21 | bjayara2 | 1254751 | Hash Calc for FDS                          |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *			Umaralli A Rajak Shaikh  | ushaikh   | VTSC, Bengaluru, India
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/* !LINKSTO CSM0692, 1
 */

/*==[Includes]================================================================*/
#include "Crypto_She.h"
#include "Crypto_HashCalc.h"
#include "string.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"
#include "Crypto_Cfg.h"
#include "stub.h"

#if (CRYPTO_HASH_CALC_ENABLED == 1)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/
typedef enum
{
    Crypto_HASHCALC_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    Crypto_HASHCALC_WAIT /* HSM is waiting on the data from CSM */
}
Crypto_HashCalcWorkType;

typedef struct
{
        P2CONST(uint8,TYPEDEF,CRY_APPL_DATA)  iputPtr;
        uint32                                iputLen;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    oputPtr;
        P2VAR(uint32, TYPEDEF, CRY_APPL_DATA) oputLenPtr;
        Crypto_HashCalcWorkType           work;
        Crypto_StateType                      state;
        Crypto_StateType                      stateRequested;
        uint32                                icount;
        uint8                                 priority;
        uint8                                 faultLog_U8;
        boolean                               LockedHsm_E;
        boolean                               DirectCall;
}
Crypto_HashCalcStateType;

/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcCancel
 **
 ** \brief 
 ** API to cancel the Hash Calculation job
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
static FUNC(void, CRY_CODE) Crypto_HashCalcCancel(void);

/**
 *********************************************************************************************
 ** \fn Crypto_CSM_HashCalcCallback
 **
 ** \brief 
 ** Calls the callback function, if needed, outside the lock semaphore code
 **
 ** \param [in] param
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
static FUNC(void, CRY_CODE) Crypto_CSM_HashCalcCallback(Csm_ReturnType param);

/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcActionOnFault
 **
 ** \brief 
 ** API to execute when a fault occurs in Hash Calculation
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns none
 **                 
 **
 ********************************************************************************************/
static FUNC(void, CRY_CODE) Crypto_HashCalcActionOnFault(void);

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_HashCalcStateType, CRY_VAR) Crypto_HashCalcState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_HashCalcNotif_S;

//STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptHashCalcPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_HashCalc_Error;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_HashCalc_Completed;

STATIC uint8 vHsmCrypt_InputHash_U8A[256] = {0};

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/
FUNC(void, CRY_CODE) Crypto_HashCalcInit(void)
{
    Crypto_HashCalcState_S.state = Crypto_Idle;
    Crypto_HashCalcState_S.stateRequested = Crypto_Idle;
    Crypto_HashCalcState_S.iputPtr  = NULL;
    Crypto_HashCalcState_S.iputLen  = 0;
    Crypto_HashCalcState_S.icount = 0;
    Crypto_HashCalcState_S.oputPtr  = NULL;
    Crypto_HashCalcState_S.oputLenPtr  = NULL;
    Crypto_HashCalcState_S.LockedHsm_E      = FALSE;
    Crypto_HashCalcState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_HashCalcState_S.work = Crypto_HASHCALC_WAIT;
    vHsmCrypt_HashCalc_Completed = FALSE;
    Crypto_HashCalcState_S.DirectCall = FALSE;
    vHsmCrypt_HashCalc_Error = FALSE;
}

/*---[Crypto_HashCalc - direct call with callback update of results from M0P]--------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_HashCalc(
            P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr,
            const uint8 * p_dataPtr_PU8 ,
            uint32 p_dataLength_U32,
            uint8 *      p_resultPtr_PU8 ,
            uint32 *     p_resultLengthPtr_PU32 ,
            boolean      p_truncationAllowed_BOOL
)
{

    Csm_ReturnType fl_ret_E = CSM_E_OK;
    //P2CONST(Crypto_HashCalcConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) ||
            (p_resultPtr_PU8 == NULL) || (p_resultLengthPtr_PU32 == NULL) ||
            (p_dataPtr_PU8 == NULL) || (p_dataLength_U32 == 0u))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_HashCalcNotif_S.callbackNeeded = FALSE;
        Crypto_HashCalcNotif_S.finishNeeded = FALSE;

        //locCfgPtr = (P2CONST(Crypto_HashCalcConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_HashCalcState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_HashCalcState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_HashCalcState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
                Crypto_HashCalcNotif_S.callbackParamValue = Crypto_CSM_E_BUSY;
            }
        }

        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            /* CHECK: NOPARSE */
            /* Defensive programming. The true branch cannot be reached with the current state machine */
            if
            (
                    (Crypto_HashCalcState_S.priority != CRYPTO_PRIORITY_NONE) &&
                    (Crypto_HashCalcState_S.LockedHsm_E == TRUE)
            )
                /* CHECK: PARSE */
            {
                /* An encryption is already running and has to be cancelled. */
                /* !LINKSTO CRYSHE_26, 1
                 */
                Crypto_HashCalcCancel();
            }

#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            if( Crypto_HashCalcState_S.state != Crypto_Cancel)
            {
                Crypto_HashCalcState_S.state = Crypto_Finish;
            }
            else
            {
                Crypto_HashCalcState_S.stateRequested = Crypto_Finish;
            }
#else
            if(Crypto_Idle == Crypto_HashCalcState_S.state)
            {    
                Crypto_HashCalcState_S.state        = Crypto_Finish;
                Crypto_HashCalcState_S.DirectCall   = TRUE;
                Crypto_HashCalcState_S.LockedHsm_E  = TRUE;
                Crypto_HashCalcState_S.iputPtr      = p_dataPtr_PU8;
                Crypto_HashCalcState_S.iputLen      = p_dataLength_U32;
                Crypto_HashCalcState_S.oputPtr      = p_resultPtr_PU8;
                Crypto_HashCalcState_S.oputLenPtr   = p_resultLengthPtr_PU32;
                 Crypto_HashCalcState_S.icount      = 0;

#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                vHsmCrypt_HashCalc_Completed = FALSE;
                vHsmCrypt_HashCalc_Error = FALSE;
                while(FALSE == vHsmCrypt_HashCalc_Completed)
                {
                    if(FALSE != vHsmCrypt_HashCalc_Error)
                    {
                        fl_ret_E = CSM_E_NOT_OK;                    
                        break;
                    }
                    else
                    {
                        Crypto_HashCalcMainFunction();
                        vHsmIpc_HostManager_PeriodicCheck();
                    }

                }                
                Crypto_HashCalcState_S.state = Crypto_Idle;
            }
            else
            {
                fl_ret_E = CSM_E_NOT_OK;
            }
 #if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif  /*CRYPTO_PRIORITY_ENABLED*/
    }
    return fl_ret_E;
}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcStart(
                P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_HashCalcConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_HashCalcNotif_S.callbackNeeded = FALSE;
        Crypto_HashCalcNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_HashCalcConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;

        if (locCfgPtr->priority < Crypto_HashCalcState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_HashCalcState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_HashCalcState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
                Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }

        if (CSM_E_OK == fl_ret_E)
        {
            /* CHECK: NOPARSE */
            /* Defensive programming. The true branch cannot be reached with the current state machine */
            if
            (
                    (Crypto_HashCalcState_S.priority != CRYPTO_PRIORITY_NONE) &&
                    (Crypto_HashCalcState_S.LockedHsm_E == TRUE)
            )
                /* CHECK: PARSE */
            {
                /* An encryption is already running and has to be cancelled. */
                /* !LINKSTO CRYSHE_26, 1
                 */
                Crypto_HashCalcCancel();
            }

#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            if( Crypto_HashCalcState_S.state != Crypto_Cancel)
            {
                Crypto_HashCalcState_S.state = Crypto_Start;
            }
            else
            {
                Crypto_HashCalcState_S.stateRequested = Crypto_Start;
            }
#else
            Crypto_HashCalcState_S.state = Crypto_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_HashCalcState_S.priority = locCfgPtr->priority;
            vHsmCrypt_HashCalc_Completed = FALSE;
            vHsmCrypt_HashCalc_Error = FALSE;
        }
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_CSM_HashCalcCallback(Crypto_HashCalcNotif_S.callbackParamValue);
    return fl_ret_E;
}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcUpdate(
                const uint8 * p_dataPtr_PU8 ,
                uint32 p_dataLength_U32)
{
	//CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if ((p_dataPtr_PU8 == NULL) || (p_dataLength_U32 == 0u))
    {
        ret = CSM_E_NOT_OK;
        Crypto_HashCalcCancel();
    }
    if(( Crypto_HashCalcState_S.state == Crypto_Idle ) ||
        ( Crypto_HashCalcState_S.state == Crypto_Cancel) ||
        ( Crypto_HashCalcState_S.state == Crypto_Finish) ||
        ( Crypto_HashCalcState_S.state == Crypto_Finish_Wait))
    {
        ret = CSM_E_NOT_OK;
    }
    if (CSM_E_OK == ret)
    {
        if
        (
                ( Crypto_HashCalcState_S.state == Crypto_Update ) &&
                ( Crypto_HashCalcState_S.work == Crypto_HASHCALC_WAIT )
        )
        {

                Crypto_HashCalcState_S.iputPtr     = p_dataPtr_PU8;
                Crypto_HashCalcState_S.iputLen     = p_dataLength_U32;
                Crypto_HashCalcState_S.oputPtr     = NULL;
                Crypto_HashCalcState_S.oputLenPtr  = NULL;
                Crypto_HashCalcState_S.work        = Crypto_HASHCALC_WORK;
                vHsmCrypt_HashCalc_Error = FALSE;			
        }
        else if
        (
                ( Crypto_HashCalcState_S.state == Crypto_Update ) ||
                ( Crypto_HashCalcState_S.state == Crypto_Start_Wait ) ||
                ( Crypto_HashCalcState_S.state == Crypto_Update_Wait ) ||
                ( Crypto_HashCalcState_S.state == Crypto_Start )
        )
        {
            ret = CSM_E_BUSY;
        }
        else
        {
            ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            if( Crypto_HashCalcState_S.state != Crypto_Cancel)
            {
                Crypto_HashCalcState_S.state = Crypto_Idle;
            }
            else
            {
                Crypto_HashCalcState_S.stateRequested = Crypto_Idle;
            }
    #else
            Crypto_HashCalcState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_HashCalcState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    //CRYPTO_RELEASE_SEM();

    return ret;
}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcFinish(
                uint8 *      p_resultPtr_PU8 ,
                uint32 *     p_resultLengthPtr_PU32 ,
                boolean      p_truncationAllowed_BOOL)
{
    Csm_ReturnType ret = CSM_E_OK;

    //CRYPTO_LOCK_SEM();
    if((p_resultPtr_PU8 == NULL) || (p_resultLengthPtr_PU32 == NULL))
    {
        ret = CSM_E_NOT_OK;
        Crypto_HashCalcCancel();
    }
    if ((*p_resultLengthPtr_PU32 < CRYPTO_HSM_SHA256_BLOCK_LENGTH) && (FALSE == p_truncationAllowed_BOOL))
    {
        /* !LINKSTO CSM0663, 1
         */
        ret = CSM_E_SMALL_BUFFER;
        Crypto_HashCalcCancel();
    }
    if(ret == CSM_E_OK)
    {
        if (( Crypto_HashCalcState_S.state == Crypto_Idle ) ||
                ( Crypto_HashCalcState_S.state == Crypto_Cancel) ||
                ( Crypto_HashCalcState_S.state == Crypto_Finish_Wait))
        {
            ret = CSM_E_NOT_OK;
        }
        else
        {
            if
            (
                    ( Crypto_HashCalcState_S.state == Crypto_Update ) &&
                    ( Crypto_HashCalcState_S.work == Crypto_HASHCALC_WAIT )
            )
            {
                Crypto_HashCalcState_S.state = Crypto_Finish;
                Crypto_HashCalcState_S.oputPtr = p_resultPtr_PU8;
                Crypto_HashCalcState_S.oputLenPtr = p_resultLengthPtr_PU32;
                vHsmCrypt_HashCalc_Error = FALSE;
                ret = CSM_E_OK;
            }
            else if
            (
                    ( Crypto_HashCalcState_S.state == Crypto_Update ) ||
                    ( Crypto_HashCalcState_S.state == Crypto_Start_Wait ) ||
                    ( Crypto_HashCalcState_S.state == Crypto_Update_Wait ) ||
                    ( Crypto_HashCalcState_S.state == Crypto_Start )
            )
            {
                ret = CSM_E_BUSY;
            }
            else
            {
                ret = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_HashCalcState_S.state != Crypto_Cancel)
                {
                    Crypto_HashCalcState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_HashCalcState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_HashCalcState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_HashCalcState_S.priority = CRYPTO_PRIORITY_NONE;
            }
        }
    }

    //CRYPTO_RELEASE_SEM();
    return ret;
}
/*---[Crypto_HashCalcMainFunction]------------------------------------*/

#define CODE_FLASH_END_ADDRESS        ((const uint8 *)0x1040FFFF)
#define CODE_FLASH_START_ADDRESS      ((const uint8 *)0x10000000)

FUNC(void,CRY_CODE) Crypto_HashCalcMainFunction(void)
{
    STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptHashCalcPackedData_S;
    uint8 fl_FlashHashStartAddress_U8[12];
    Std_ReturnType fl_retVal;
    //CRYPTO_LOCK_SEM();
    Crypto_HashCalcNotif_S.callbackNeeded = FALSE;
    Crypto_HashCalcNotif_S.finishNeeded = FALSE;
    switch (Crypto_HashCalcState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_HashCalcState_S.stateRequested)
                {
                    Crypto_HashCalcState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_HashCalcState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /*#if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:
            Crypto_HashCalcState_S.LockedHsm_E = Crypto_LockShe();

            /* !LINKSTO CRYSHE_25, 1
             */
            if (Crypto_HashCalcState_S.LockedHsm_E == TRUE)
            {
                Crypto_CryptHashCalcPackedData_S.KeyId_U8 = 0u;
                Crypto_CryptHashCalcPackedData_S.jobId_E = CID_16_HASH_START;
                Crypto_CryptHashCalcPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_CryptHashCalcPackedData_S.payLoadPtr_U8P = NULL;
                Crypto_CryptHashCalcPackedData_S.payLoadSize = 0u;
                vHsmCrypt_HashCalc_Completed = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_CryptHashCalcPackedData_S))
                {
                    Crypto_HashCalcState_S.state = Crypto_Start_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_HashCalcActionOnFault();
                }
            }
            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_HashCalc_Completed)
            {
                if(FALSE == vHsmCrypt_HashCalc_Error)
                {
                    Crypto_HashCalcState_S.state = Crypto_Update;
                    Crypto_HashCalcState_S.work  = Crypto_HASHCALC_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
                    Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_HashCalcActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                   * if no response for 1sec, then, reset everything*/
                  if (TRUE == Crypto_CheckFaultPeriodic())
                  {
                      Crypto_HashCalcActionOnFault();
                  }
                  else
                  {
                      /* Wait for the fault counter to expire to reset all
                       * which is handled in the above if condition */
                  }
            }
            break;
        case Crypto_Update:
            if ( Crypto_HashCalcState_S.work == Crypto_HASHCALC_WORK )
            {
			if((Crypto_HashCalcState_S.iputPtr >= CODE_FLASH_START_ADDRESS) && 
			(Crypto_HashCalcState_S.iputPtr < CODE_FLASH_END_ADDRESS))
			{
				(void)memcpy(&fl_FlashHashStartAddress_U8[0], &Crypto_HashCalcState_S.iputPtr, 4);
				(void)memcpy(&fl_FlashHashStartAddress_U8[4], &Crypto_HashCalcState_S.iputLen, 4);
				Crypto_CryptHashCalcPackedData_S.payLoadPtr_U8P = (uint8 *)&fl_FlashHashStartAddress_U8;
				Crypto_CryptHashCalcPackedData_S.payLoadSize = 8;
				/* KeyId_U8 carries the meaning of direct indirect address 
                since the KeyId_U8 doesn't have a role in hash finding
                0xFF means, use the payload as address instead of data */
				Crypto_CryptHashCalcPackedData_S.KeyId_U8 = (uint8)0xFF; 
			}
			else
			{
				Crypto_CryptHashCalcPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_HashCalcState_S.iputPtr;
				Crypto_CryptHashCalcPackedData_S.payLoadSize = Crypto_HashCalcState_S.iputLen;
				Crypto_CryptHashCalcPackedData_S.KeyId_U8 = 0u;
			}	

                Crypto_CryptHashCalcPackedData_S.jobId_E = CID_17_HASH_UPDATE;

                Crypto_CryptHashCalcPackedData_S.priority_U8 = (te_jobpriority)0;
                vHsmCrypt_HashCalc_Completed = FALSE;
                fl_retVal = Crypto_SendPackedData(Crypto_CryptHashCalcPackedData_S);
                if (E_OK == fl_retVal)
                {
                    Crypto_HashCalcState_S.state = Crypto_Update_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_HashCalcActionOnFault();
                }
            }
            break;
        case Crypto_Update_Wait:
            if (TRUE == vHsmCrypt_HashCalc_Completed)
            {
                if(FALSE == vHsmCrypt_HashCalc_Error)
                {
                    Crypto_HashCalcState_S.state = Crypto_Update;
                    Crypto_HashCalcState_S.work  = Crypto_HASHCALC_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
                    Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_HashCalcActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_HashCalcActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
            if(FALSE != Crypto_HashCalcState_S.DirectCall)
            {
                /* !LINKSTO CRYSHE_25, 1
                 */
                if (Crypto_HashCalcState_S.LockedHsm_E == TRUE)
                {
                    Crypto_CryptHashCalcPackedData_S.KeyId_U8 = 0u;
                    Crypto_CryptHashCalcPackedData_S.jobId_E = CID_15_HASH_FN;
                    (void)memcpy(&vHsmCrypt_InputHash_U8A[0],Crypto_HashCalcState_S.iputPtr, Crypto_HashCalcState_S.iputLen);
                    Crypto_CryptHashCalcPackedData_S.payLoadPtr_U8P = &vHsmCrypt_InputHash_U8A[0];
                    Crypto_CryptHashCalcPackedData_S.priority_U8 = (te_jobpriority)0;
                    Crypto_CryptHashCalcPackedData_S.payLoadSize = Crypto_HashCalcState_S.iputLen; /* length of direct interface needed */
                    vHsmCrypt_HashCalc_Completed = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_CryptHashCalcPackedData_S))
                    {
                        Crypto_HashCalcState_S.state = Crypto_Finish_Wait;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_HashCalcActionOnFault();
                    }
                }
            }
            else
            {
                Crypto_CryptHashCalcPackedData_S.KeyId_U8 = 0u;
                Crypto_CryptHashCalcPackedData_S.jobId_E = CID_14_HASH_FINISH;
                Crypto_CryptHashCalcPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_CryptHashCalcPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_HashCalcState_S.oputLenPtr;
                Crypto_CryptHashCalcPackedData_S.payLoadSize = 4; /* length of hash needed */
                vHsmCrypt_HashCalc_Completed = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_CryptHashCalcPackedData_S))
                {
                    Crypto_HashCalcState_S.state = Crypto_Finish_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_HashCalcActionOnFault();
                }
            }
            break;
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_HashCalc_Completed)
            {
                Crypto_HashCalcState_S.state = Crypto_Idle;
                Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
                Crypto_HashCalcNotif_S.finishNeeded = TRUE;
                Crypto_HashCalcState_S.work  = Crypto_HASHCALC_WAIT;
                Crypto_HashCalcState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_HashCalc_Error)
                {
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_HashCalcState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_HashCalcActionOnFault();
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
    //CRYPTO_RELEASE_SEM();
    Crypto_CSM_HashCalcCallback(Crypto_HashCalcNotif_S.callbackParamValue);
}

FUNC(void, CRY_CODE) Crypto_HashCalcCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint32 res_length;
    uint8 status = *p_resultBytesInSRAM_U8P;
    if (Crypto_HashCalcState_S.LockedHsm_E == TRUE)
    {
        switch (Crypto_HashCalcState_S.state)
        {
            case Crypto_Start_Wait:
                vHsmCrypt_HashCalc_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_HashCalc_Error = TRUE;
                }
                break;
            case Crypto_Update_Wait:
                vHsmCrypt_HashCalc_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_HashCalc_Error = TRUE;
                }
                break;
            case Crypto_Finish_Wait:
                res_length= payload_size - 1;
                vHsmCrypt_HashCalc_Completed = TRUE;
                if(Crypto_HashCalcState_S.oputLenPtr != NULL)
                {
                    if(((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                       (*Crypto_HashCalcState_S.oputLenPtr == res_length))
                    {
                        /* Copy the result data into the memory
                           location shared from application */
                        (void)memcpy((uint8 *)Crypto_HashCalcState_S.oputPtr,
                                (uint8 *)&p_resultBytesInSRAM_U8P[1],
                                (uint16)res_length);
                    }
                    else
                    {
                        vHsmCrypt_HashCalc_Error = TRUE;
                    }
                }
                else
                {
                    vHsmCrypt_HashCalc_Error = TRUE;
                }
                break;
            default:
                break;
        }
    }
}

/*==[Definition of functions with internal linkage]===========================*/

static FUNC(void, CRY_CODE) Crypto_HashCalcCancel(void)
{
    Crypto_HashCalcState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_HashCalcState_S.state = Crypto_Cancel;
#else
    Crypto_HashCalcState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_HashCalcState_S.LockedHsm_E == TRUE)
    {
        Crypto_HashCalcState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }
    //(void)Crypto_She_Cancel(e_aesecbencrypt);
}

static FUNC(void, CRY_CODE) Crypto_CSM_HashCalcCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_HashCalcNotif_S.callbackNeeded)
    {
        Crypto_HashCalcNotif_S.callbackNeeded = FALSE;
        CRYPTO_CSM_HASHCALC_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_HashCalcNotif_S.finishNeeded)
    {
        Crypto_HashCalcNotif_S.finishNeeded = FALSE;
        CRYPTO_CSM_HASHCALC_SERVICE_FINISH_NOTIF;
    }
}

static FUNC(void, CRY_CODE) Crypto_HashCalcActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_HashCalcState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_HashCalcState_S.faultLog_U8++;
    }
    Crypto_HashCalcNotif_S.callbackNeeded = TRUE;
    Crypto_HashCalcNotif_S.finishNeeded = TRUE;
    Crypto_HashCalcNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_HashCalcCancel();
    Crypto_ResetFaultCounter();
}

#endif  /*CRYPTO_HASH_CALC_ENABLED*/

