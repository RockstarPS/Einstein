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
 * \file Crypto_Random.c
 *
 *  Random generate implementation in M7
 *  This file shall be the Random generate implementation in M7 sending
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
#include "Crypto_Random.h"
#include "string.h"
#include "stub.h"
#include "vHsmCryptoManager.h"


#if (CRYPTO_RANDOM_ENABLED == 1)

/*==[Macros]==================================================================*/
/* CSM 4.3 interface  */
#define RANDOM_GEN_FAULT_COUNTER_MAX_VAL      ((uint32)10000)

/*==[Types]===================================================================*/

typedef enum
{
    Crypto_HSM_RandomSeedIdle,
    Crypto_HSM_RandomSeedStart,
    Crypto_HSM_RandomSeedUpdate,
    Crypto_HSM_RandomSeedFinish,
    Crypto_HSM_RandomSeedFinishWait,
} Crypto_RandomSeedStateType;

typedef enum
{
  Crypto_RandomSeedNeedStart,
  Crypto_RandomSeedFirst,
  Crypto_RandomSeedSecond,
  Crypto_RandomSeedDone
}
Crypto_RandomSeedAttemptType;

typedef struct
{
        uint8*       resultPtr_pU8;
        uint32                      resultLength_U32;
        Crypto_RandomSeedStateType seedState;
        Crypto_StateType           generateState_E;
        uint8                       priority_U8;
        boolean                     LockedHsm_E;
        boolean                     syncCall_Bool;
        te_cryptojobid              jobId_E;
        uint8                       faultLog_U8;
        Crypto_RandomSeedAttemptType attempt;
} Crypto_RandomStateType;


/*==[Declaration of functions with internal linkage]==========================*/


/** \brief  Calls the callback function, if needed, outside the lock semaphore
 *code.
 **/
STATIC FUNC(void, CRY_CODE) Crypto_RandomCallback(Csm_ReturnType param);

STATIC FUNC(boolean, CRY_CODE) Crypto_RandomGen_CheckFaultPeriodic(void );

//extern void CySldIpc_Isr_IpcDrv_Cat2(void);

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/


STATIC VAR(Crypto_RandomStateType, CRY_VAR) Crypto_RandomState_4dot3_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_RandomNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptoRandomPackedData4dot3_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_TrngRead_4dot3_Done;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_TrngRead_4dot3_Error;

STATIC VAR(uint32, CRY_VAR) l_RandomGenFaultCounter_U32;

 


/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/


/*---[Crypto_RandomInit]------------------------------------------------*/

FUNC(void, CRY_CODE) Crypto_RandomInit(void)
{
    Crypto_RandomState_4dot3_S.resultPtr_pU8    = NULL;
    Crypto_RandomState_4dot3_S.seedState = Crypto_HSM_RandomSeedIdle;
    Crypto_RandomState_4dot3_S.generateState_E  = Crypto_Idle;
    Crypto_RandomState_4dot3_S.resultLength_U32 = 0u;
    Crypto_RandomState_4dot3_S.LockedHsm_E      = FALSE;
    Crypto_RandomState_4dot3_S.faultLog_U8 = 0u;
    Crypto_RandomState_4dot3_S.syncCall_Bool = FALSE;
    Crypto_RandomState_4dot3_S.priority_U8 = CRYPTO_PRIORITY_NONE; 
    vHsmCrypt_TrngRead_4dot3_Done = FALSE;
    vHsmCrypt_TrngRead_4dot3_Error = FALSE;
    l_RandomGenFaultCounter_U32 = 0u;
}



/*---[Crypto_RandomGenerate - CSM 4.3 interface]-------------------------------------*/

/* !LINKSTO CRYSHE_276, 1
 */
FUNC(Csm_ReturnType, CRY_CODE)Crypto_RandGen4Dot3CSM
        (P2CONST(void, AUTOMATIC, CRY_APPL_DATA) cfgPtr,
        P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) resultPtr,
        uint32 resultLength_U32)
{
    Csm_ReturnType l_ret_E;
    //CRYPTO_LOCK_SEM();    
    P2CONST(Crypto_RandomConfigType, AUTOMATIC, CRY_APPL_DATA) l_cfg_pS; 


    /* Convert void pointer to our type */
    l_cfg_pS =
            (P2CONST(Crypto_RandomConfigType, AUTOMATIC, CRY_APPL_DATA))cfgPtr;

    /* Deviation MISRA-1 <+1> */
    if (TRUE != Crypto_IsInit())
    {
        l_ret_E = CSM_E_NOT_OK;
    }
    else if(resultLength_U32 > CRYPTO_HSM_BLOCK_LENGTH)
    {
        l_ret_E = CSM_E_ENTROPY_EXHAUSTION;
    }
    else
    {
        /* !LINKSTO CRYSHE_23, 1
         */
        l_ret_E = CSM_E_OK;
        l_RandomGenFaultCounter_U32 = 0u;
        Crypto_RandomState_4dot3_S.generateState_E  = Crypto_Update;
        Crypto_RandomState_4dot3_S.priority_U8      = l_cfg_pS->priority;
        Crypto_RandomState_4dot3_S.resultLength_U32 = resultLength_U32;
        Crypto_RandomState_4dot3_S.resultPtr_pU8    = resultPtr;
        Crypto_RandomState_4dot3_S.jobId_E = CID_31_RANDOM_GEN;
        Crypto_RandomState_4dot3_S.LockedHsm_E = TRUE;
        vHsmCrypt_TrngRead_4dot3_Done = FALSE;
        vHsmCrypt_TrngRead_4dot3_Error = FALSE;
        Crypto_RandomState_4dot3_S.syncCall_Bool = TRUE;
        while (FALSE == vHsmCrypt_TrngRead_4dot3_Done)
        {
            Crypto_RandomGen4dot3MainFunction();
            vHsmIpc_HostManager_PeriodicCheck();           
            if(FALSE != vHsmCrypt_TrngRead_4dot3_Error)
            {
                l_ret_E = CSM_E_NOT_OK;
                break;
            }

        }
        Crypto_RandomState_4dot3_S.LockedHsm_E = FALSE;
        Crypto_RandomState_4dot3_S.generateState_E = Crypto_Idle;
        Crypto_RandomState_4dot3_S.priority_U8 = CRYPTO_PRIORITY_NONE;
    }
    //CRYPTO_RELEASE_SEM();    
    return l_ret_E;

}
/*---[Crypto_RandomGen4dot3MainFunction]-------------------------------------*/
FUNC(void, CRY_CODE) Crypto_RandomGen4dot3MainFunction(void)
{
    if (Crypto_RandomState_4dot3_S.generateState_E == Crypto_Update)
    {
        if (Crypto_RandomState_4dot3_S.LockedHsm_E == TRUE)
        {
            /* pack the crypto data */
            Crypto_CryptoRandomPackedData4dot3_S.payLoadPtr_U8P = (uint8 *)&Crypto_RandomState_4dot3_S.resultLength_U32;
            Crypto_CryptoRandomPackedData4dot3_S.payLoadSize  = Crypto_RandomState_4dot3_S.resultLength_U32; /* result length is 4 bytes length*/
            Crypto_CryptoRandomPackedData4dot3_S.jobId_E = Crypto_RandomState_4dot3_S.jobId_E;
            Crypto_CryptoRandomPackedData4dot3_S.priority_U8 = (te_jobpriority)0;
            Crypto_CryptoRandomPackedData4dot3_S.KeyId_U8 = 0u;
            if(E_OK ==  Crypto_SendPackedData(Crypto_CryptoRandomPackedData4dot3_S))
            {
                Crypto_RandomState_4dot3_S.generateState_E = Crypto_Finish;
                /* start a timer to check for failing scenarios */
                Crypto_ResetFaultCounter();
            }
            else
            {
                if(Crypto_RandomState_4dot3_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
                {
                    Crypto_RandomState_4dot3_S.faultLog_U8++;
                }
                vHsmCrypt_TrngRead_4dot3_Error = TRUE;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    if (Crypto_RandomState_4dot3_S.generateState_E == Crypto_Finish)
    {
        if (vHsmCrypt_TrngRead_4dot3_Done == TRUE)
        {

            /* To release the lock on Hsm usage after completion
             * of crypto job */

            Crypto_RandomState_4dot3_S.LockedHsm_E = FALSE;
            Crypto_RandomState_4dot3_S.priority_U8 = CRYPTO_PRIORITY_NONE;

            Crypto_RandomState_4dot3_S.generateState_E = Crypto_Idle;
            Crypto_RandomState_4dot3_S.priority_U8     = CRYPTO_PRIORITY_NONE;
        }
        else
        {

            if (TRUE == Crypto_RandomGen_CheckFaultPeriodic() && (TRUE == Crypto_RandomState_4dot3_S.syncCall_Bool))
            {
                if(Crypto_RandomState_4dot3_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
                {
                    Crypto_RandomState_4dot3_S.faultLog_U8++;
                }
                vHsmCrypt_TrngRead_4dot3_Error = TRUE;
                Crypto_RandomState_4dot3_S.LockedHsm_E = FALSE;
                Crypto_RandomState_4dot3_S.priority_U8 = CRYPTO_PRIORITY_NONE;
                Crypto_ResetFaultCounter();
            }
        }
    }
    else
    {
        /* Do nothing */
    }    
}


/*----------------------------------------------------------------------------*/
/*==[Definition of functions with internal
 * linkage]===========================*/


FUNC(void, CRY_CODE) Crypto_RandomCancel(void)
{
    /* Deviation MISRA-1 <STOP> */
    if(Crypto_RandomState_4dot3_S.LockedHsm_E != FALSE)
    {
        Crypto_RandomState_4dot3_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();    
    }
    Crypto_RandomState_4dot3_S.priority_U8 = CRYPTO_PRIORITY_NONE;
}

STATIC FUNC(void, CRY_CODE) Crypto_RandomCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_RandomNotif_S.callbackNeeded)
    {
        Crypto_RandomNotif_S.callbackNeeded = FALSE;
        CRYPTO_HSM_CSM_RANDOM_CALLBACK_NOTIFICATION(param);
    }

    if (TRUE == Crypto_RandomNotif_S.finishNeeded)
    {
        Crypto_RandomNotif_S.finishNeeded = FALSE;
    }
}


FUNC(void, CRY_CODE) Crypto_RandomNumberGenCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint8 status = *p_resultBytesInSRAM_U8P;
    if((CRYPTO_JOB_DONE == status) && (33u >= payload_size))
    {
        if ((Crypto_RandomState_4dot3_S.LockedHsm_E == TRUE) && (vHsmCrypt_TrngRead_4dot3_Done == FALSE))
        {
            vHsmCrypt_TrngRead_4dot3_Done = TRUE;
            Crypto_RandomState_4dot3_S.generateState_E = Crypto_Finish;
                /* Copy the result data into the memory
                location shared from application */
                (void)memcpy((uint8 *)Crypto_RandomState_4dot3_S.resultPtr_pU8,
                        (uint8 *)&p_resultBytesInSRAM_U8P[1],
                        (uint16)Crypto_RandomState_4dot3_S.resultLength_U32);
        }    
    }
}

/*---[Crypto_RandomGen_CheckFaultPeriodic used in CSM 4.3 API]----------------------------------------*/
STATIC FUNC(boolean, CRY_CODE) Crypto_RandomGen_CheckFaultPeriodic(void )
{
    boolean fl_ret_E = FALSE;

    if(l_RandomGenFaultCounter_U32 >= RANDOM_GEN_FAULT_COUNTER_MAX_VAL )
    {
       fl_ret_E = TRUE;
    }
    else
    {
        l_RandomGenFaultCounter_U32++;
    }

    return(fl_ret_E);
}


#endif /* #if (CRYPTO_RANDOM_ENABLED == 1) */
