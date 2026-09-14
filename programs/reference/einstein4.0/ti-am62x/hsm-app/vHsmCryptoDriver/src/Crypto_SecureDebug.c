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
 * \file Crypto_SecureDebug.c
 *
 * \brief
 * Siphash Calc implementation in M7
 *
 * \detailed description
 *  This file shall be the Siphash Mac generate implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *
 * \version 1.0.00
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 17/Aug/'21 | kjohn    | 1254751 | Siphash Calculation                        |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/* !LINKSTO CSM0692, 1
 */

/*==[Includes]================================================================*/

#include "Crypto_She.h"
#include "Crypto_SecureDebug.h"
#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "vHsmCryptoManager.h"
//#include "vHsmCryptoMessageM0P.h"
//#include "vHsmIpcHostManager.h"
#include "Crypto_Cfg.h"

#if (CRYPTO_SECUREDEBUG_ENABLED == 1)

/*==[Macros]==================================================================*/

#define DEBUG_FAULT_COUNTER_MAX_VAL      ((uint32)50000)

/* MAX BUFFER size supported from IPC is 512, so, fixed the number of
 * bytes as 490 here*/
#define SIPHASH_MAX_BUFFER_SIZE ((uint32)490)

/*==[Declaration of functions with external linkage]==========================*/

//extern void CySldIpc_Isr_IpcDrv_Cat2(void);

/*==[Types]===================================================================*/

typedef enum
{
    CRYPTO_HSM_SECUREDEBUG_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_HSM_SECUREDEBUG_WAIT /* HSM is waiting on the data from CSM */
}
Crypto_Hsm_SecureDebugWorkType;



typedef struct
{
        uint8 keyInfo;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    dataPtr;
        uint16                                dataLen;
        uint8                                 VerdataPtr[32];
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    VerPtr;
        uint8                                 VerLen;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    PassVer;
        Crypto_Hsm_SecureDebugWorkType        work;
        Crypto_StateType                      state;
        Crypto_StateType                      stateRequested;
        uint8                                 priority;
        uint8                                 faultLog_U8;
        boolean                               LockedHsm_E;
       //boolean                             DirectCall;
        VAR(boolean,CRY_APPL_DATA)            trunc;
}
Crypto_Hsm_SecureDebugStateType;

/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SecureDebugCancel
 **
 ** \brief 
 ** Cancel a running encryption and free the SHE software lock
 **
 ** \param [in] NONE
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugCancel(void);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SecureDebug_CheckFaultPeriodic
 **
 ** \brief 
 ** Calls the callback function, if needed, outside the lock semaphore code.
 **
 ** \param [in] NONE
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
STATIC FUNC(boolean, CRY_CODE) Crypto_Hsm_SecureDebug_CheckFaultPeriodic(void );


/**
 *********************************************************************************************
 ** \fn Crypto_Csm_SecureDebugCallback
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
STATIC FUNC(void, CRY_CODE) Crypto_Csm_SecureDebugCallback(Csm_ReturnType param);


/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SecureDebugActionOnFault
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugActionOnFault(void);


/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_Hsm_SecureDebugStateType, CRY_VAR) Crypto_SecureDebugState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SecureDebugNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_Hsm_CryptSecureDebugPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_SecureDebug_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_SecureDebug_Error;

STATIC VAR(uint32, CRY_VAR) l_SecureDebugFaultCounter_U32;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugInit(void)
{
    Crypto_SecureDebugState_S.state = Crypto_Idle;
    Crypto_SecureDebugState_S.stateRequested = Crypto_Idle;
    Crypto_SecureDebugState_S.dataPtr  = NULL;
    Crypto_SecureDebugState_S.dataLen  = 0;
    Crypto_SecureDebugState_S.LockedHsm_E      = FALSE;
    Crypto_SecureDebugState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SecureDebugState_S.faultLog_U8 = 0u;
    Crypto_SecureDebugState_S.work = CRYPTO_HSM_SECUREDEBUG_WORK;
    (void)memset(&Crypto_SecureDebugState_S.VerdataPtr[0],0x00,32u);
    vHsmCrypt_SecureDebug_Completed = FALSE;
    vHsmCrypt_SecureDebug_Error = FALSE;
    l_SecureDebugFaultCounter_U32 = 0u;

}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_SetJtag_Password
        (
            P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) dataPtr,
            VAR(uint16,  AUTOMATIC) dataLen
        )
{
	//CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if ((dataPtr == NULL) ||(dataLen == 0u) || (dataLen != 16u))
    {
        ret = CSM_E_NOT_OK;
    }
    else if (( Crypto_SecureDebugState_S.state != Crypto_Idle ))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        l_SecureDebugFaultCounter_U32 = 0u;
        if(Crypto_SecureDebugState_S.state == Crypto_Idle)
        {
            Crypto_SecureDebugState_S.dataPtr = dataPtr;
            Crypto_SecureDebugState_S.dataLen = dataLen;
            Crypto_SecureDebugState_S.state = Crypto_KeySet;
            vHsmCrypt_SecureDebug_Completed = FALSE;            
            vHsmCrypt_SecureDebug_Error = FALSE;
            ret = CSM_E_OK;
        }
        else
        {
            ret = CSM_E_BUSY;
        }
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Csm_SecureDebugCallback(Crypto_SecureDebugNotif_S.callbackParamValue);
    return ret;
}
FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_CheckJtag_Password
        (
            P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) VerPtr,
            P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) VerLen
        )
{
    Csm_ReturnType ret = CSM_E_OK;
    if ((VerPtr == NULL) ||(*VerLen == 0u) || (*VerLen != 16u))
    {
        ret = CSM_E_NOT_OK;
    }
    else if ((Crypto_SecureDebugState_S.state != Crypto_Idle) || (Crypto_SecureDebugState_S.LockedHsm_E != FALSE))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        l_SecureDebugFaultCounter_U32 = 0u;
        Crypto_SecureDebugState_S.LockedHsm_E = TRUE;
        (void)memcpy(&Crypto_SecureDebugState_S.VerdataPtr[0],(uint8 *)VerLen,1u);
        (void)memcpy(&Crypto_SecureDebugState_S.VerdataPtr[1],(uint8 *)VerPtr,16u);
        Crypto_SecureDebugState_S.VerLen = *VerLen;
        Crypto_SecureDebugState_S.VerPtr = VerLen;
        Crypto_SecureDebugState_S.state = Crypto_GetKey;
        Crypto_SecureDebugState_S.work  = CRYPTO_HSM_SECUREDEBUG_WORK;
        vHsmCrypt_SecureDebug_Completed = FALSE;
        vHsmCrypt_SecureDebug_Error = FALSE;
        while(FALSE == vHsmCrypt_SecureDebug_Completed)
        {
            Crypto_Hsm_SecureDebugMainFunction();
            //CySldIpc_Isr_IpcDrv_Cat2();
            vHsmIpc_HostManager_PeriodicCheck();
            if(FALSE != vHsmCrypt_SecureDebug_Error)
            {
                ret = CSM_E_NOT_OK;
                break;
            }
        }
    }
    Crypto_Hsm_SecureDebugMainFunction(); 
    Crypto_SecureDebugState_S.LockedHsm_E = FALSE;
    Crypto_SecureDebugState_S.state = Crypto_Idle;   
    return ret;    
}

FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_LC_SecureDebug
        (
            void
        )
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if (( Crypto_SecureDebugState_S.state != Crypto_Idle ))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        l_SecureDebugFaultCounter_U32 = 0u;
        if(Crypto_SecureDebugState_S.state == Crypto_Idle)
        {
            Crypto_SecureDebugState_S.state = Crypto_Finish;
            vHsmCrypt_SecureDebug_Completed = FALSE;            
            vHsmCrypt_SecureDebug_Error = FALSE;
            ret = CSM_E_OK;
        }
        else
        {
            ret = CSM_E_BUSY;
        }
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Csm_SecureDebugCallback(Crypto_SecureDebugNotif_S.callbackParamValue);
    return ret;

}
/*---[Crypto_SecureDebugMainFunction]------------------------------------*/
/* !LINKSTO CRYSHE_100, 1
 */
FUNC(void,CRY_CODE) Crypto_Hsm_SecureDebugMainFunction
        (
                void
        )
{
    Crypto_SecureDebugNotif_S.callbackNeeded = FALSE;
    Crypto_SecureDebugNotif_S.finishNeeded = FALSE;
    switch (Crypto_SecureDebugState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Hsm_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                Crypto_SecureDebugState_S.state = Crypto_Idle;
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_KeySet:
            if(Crypto_SecureDebugState_S.LockedHsm_E == FALSE)
            {
                Crypto_SecureDebugState_S.LockedHsm_E = Crypto_LockShe();
            }
            else
            {
                Crypto_Hsm_CryptSecureDebugPackedData_S.KeyId_U8 = 0u;
                Crypto_Hsm_CryptSecureDebugPackedData_S.jobId_E = CID_122_JTAG_SETPASSWORD_GEN;
                Crypto_Hsm_CryptSecureDebugPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadPtr_U8P = Crypto_SecureDebugState_S.dataPtr;
                Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadSize = (uint16)Crypto_SecureDebugState_S.dataLen;
                vHsmCrypt_SecureDebug_Completed = FALSE;
                vHsmCrypt_SecureDebug_Error = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptSecureDebugPackedData_S))
                {
                    Crypto_SecureDebugState_S.state = Crypto_KeySet_Wait;
                    Crypto_ResetFaultCounter();;
                }
                else
                {
                    Crypto_Hsm_SecureDebugActionOnFault();
                }
            }
                
            break;
        case Crypto_KeySet_Wait:
            if(TRUE == vHsmCrypt_SecureDebug_Completed)
            {
                Crypto_SecureDebugState_S.state = Crypto_Idle;
                Crypto_SecureDebugNotif_S.callbackNeeded = TRUE;
                Crypto_SecureDebugNotif_S.finishNeeded = TRUE;
                Crypto_SecureDebugState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_SecureDebug_Error)
                {
                    Crypto_SecureDebugNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SecureDebugNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SecureDebugState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SecureDebugActionOnFault();
                    CRYPTO_RELEASE_HSM();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_GetKey:
            Crypto_Hsm_CryptSecureDebugPackedData_S.KeyId_U8 =0u;
            Crypto_Hsm_CryptSecureDebugPackedData_S.jobId_E = CID_123_JTAG_CHECKPASSWORD_GEN;
            Crypto_Hsm_CryptSecureDebugPackedData_S.priority_U8 = (te_jobpriority)0;
            Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadPtr_U8P = &Crypto_SecureDebugState_S.VerdataPtr[0];
            Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadSize = Crypto_SecureDebugState_S.VerLen + 1u; /* no payload */
            vHsmCrypt_SecureDebug_Completed = FALSE;
            vHsmCrypt_SecureDebug_Error = FALSE;
            if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptSecureDebugPackedData_S))
            {
                Crypto_SecureDebugState_S.state = Crypto_GetKey_Wait;
            }
            else
            {
                Crypto_Hsm_SecureDebugActionOnFault();
            }
            break;
        case Crypto_GetKey_Wait:
            if(TRUE == vHsmCrypt_SecureDebug_Completed)
            {
                Crypto_SecureDebugState_S.state = Crypto_Idle;
                Crypto_SecureDebugNotif_S.callbackNeeded = FALSE;
                Crypto_SecureDebugNotif_S.finishNeeded = FALSE;
                Crypto_SecureDebugState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SecureDebugState_S.LockedHsm_E = FALSE;
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_Hsm_SecureDebug_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SecureDebugActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
            if (Crypto_SecureDebugState_S.LockedHsm_E == FALSE)
            {
                Crypto_SecureDebugState_S.LockedHsm_E = Crypto_LockShe();
            }
            else
            {
                Crypto_Hsm_CryptSecureDebugPackedData_S.KeyId_U8 =0u;
                //Crypto_Hsm_CryptSecureDebugPackedData_S.jobId_E = CID_112_JTAG_LC_SECUREDEBUG_FN;
                Crypto_Hsm_CryptSecureDebugPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadPtr_U8P = NULL;
                Crypto_Hsm_CryptSecureDebugPackedData_S.payLoadSize = 0u ; /* no payload */
                vHsmCrypt_SecureDebug_Completed = FALSE;
                vHsmCrypt_SecureDebug_Error = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptSecureDebugPackedData_S))
                {
                    Crypto_SecureDebugState_S.state = Crypto_Finish_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_Hsm_SecureDebugActionOnFault();
                }
            }
            break;
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_SecureDebug_Completed)
            {
                Crypto_SecureDebugState_S.state = Crypto_Idle;
                Crypto_SecureDebugNotif_S.callbackNeeded = TRUE;
                Crypto_SecureDebugNotif_S.finishNeeded = TRUE;
                Crypto_SecureDebugState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_SecureDebug_Error)
                {
                    Crypto_SecureDebugNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SecureDebugNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SecureDebugState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_Hsm_SecureDebug_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SecureDebugActionOnFault();
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
    Crypto_Csm_SecureDebugCallback(Crypto_SecureDebugNotif_S.callbackParamValue);

}

FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint8 status = *p_resultBytesInSRAM_U8P;

    switch (Crypto_SecureDebugState_S.state)
    {
    case Crypto_KeySet_Wait :
        vHsmCrypt_SecureDebug_Completed = TRUE;
        if (((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
        {
            /* Do nothing, as this is the success case */
        }
        else
        {
            vHsmCrypt_SecureDebug_Error = TRUE;
        }
        break;
    case Crypto_GetKey_Wait:
        vHsmCrypt_SecureDebug_Completed = TRUE;
        if((2u == payload_size) && ((uint8)CRYPTO_JOB_DONE == status))
        {
            (void)memcpy((uint8 *)Crypto_SecureDebugState_S.VerPtr,(uint8 *)&p_resultBytesInSRAM_U8P[1],1u);
        }
        else
        {
            vHsmCrypt_SecureDebug_Error = TRUE;
        }
        break;
    default:
        break;
    }
}

/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugCancel(void)
{
    Crypto_SecureDebugState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SecureDebugState_S.state = Crypto_Hsm_Cancel;
#else
    Crypto_SecureDebugState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_SecureDebugState_S.LockedHsm_E == TRUE)
    {
        Crypto_SecureDebugState_S.LockedHsm_E = FALSE;
    }
    //(void)Crypto_She_Cancel(e_aesecbencrypt);
}

STATIC FUNC(void, CRY_CODE) Crypto_Csm_SecureDebugCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SecureDebugNotif_S.callbackNeeded)
    {
        Crypto_SecureDebugNotif_S.callbackNeeded = FALSE;
        CRYPTO_HSM_CSM_SECUREDEBUG_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SecureDebugNotif_S.finishNeeded)
    {
        Crypto_SecureDebugNotif_S.finishNeeded = FALSE;
        //CRYPTO_HSM_CSM_SECUREDEBUG_SERVICE_FINISH_NOTIF;
    }
}
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_SecureDebugState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SecureDebugState_S.faultLog_U8++;
    }
    vHsmCrypt_SecureDebug_Error = TRUE;
    Crypto_SecureDebugNotif_S.callbackNeeded = TRUE;
    Crypto_SecureDebugNotif_S.finishNeeded = TRUE;
    Crypto_SecureDebugNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_Hsm_SecureDebugCancel();
    l_SecureDebugFaultCounter_U32 = 0u;
}
STATIC FUNC(boolean, CRY_CODE) Crypto_Hsm_SecureDebug_CheckFaultPeriodic(void )
{
    boolean fl_ret_E = FALSE;
    if(l_SecureDebugFaultCounter_U32 >= DEBUG_FAULT_COUNTER_MAX_VAL )
    {
        fl_ret_E = TRUE;
    }
    else
    {
        l_SecureDebugFaultCounter_U32++;
    }
    return(fl_ret_E);
}



#endif /* CRYPTO_SECUREDEBUG_ENABLED */


