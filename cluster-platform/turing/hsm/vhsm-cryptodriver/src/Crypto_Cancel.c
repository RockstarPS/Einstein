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
 * \file Cry_She_Cancel.c
 *
 * \details
 * Cry She cancel implementation for HSM from M7,
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                        |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                      |
 * |1.00.02 | 03/Mar/'21 | bjayara2 | 1251639 | fix -key not stored error must be shown    |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Chennai, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/*==[Includes]================================================================*/
#include "Crypto_She.h"
#include "Crypto_Cancel.h"
#include "string.h"
#include "stub.h"
#include "vHsmCryptoManager.h"
//#include "vHsmIpcHostManager.h"

#define CRYPTO_CANCEL_ENABLED 1

#if (CRYPTO_CANCEL_ENABLED == 1)

/*==[Macros]==================================================================*/


/*==[Types]===================================================================*/
typedef enum
{
    Crypto_Hsm_CancelIdle = 0u,
    Crypto_Hsm_CancelStart,
    Crypto_Hsm_CancelTrack
} Crypto_Hsm_CancelEnumType;

typedef struct
{
    Crypto_Hsm_CancelEnumType  cancelstatus;
    boolean                 LockedHsm_E;
    te_cryptojobid          jobId_E;
    uint8                   faultLog_U8;
} Crypto_Hsm_CancelStateType;

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_Hsm_CancelStateType, CRY_VAR) Crypto_CancelState_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_Hsm_CryptoCancelPackedData_S;

STATIC VAR(te_canceljobid, CRY_VAR) l_canceljob_e;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

/*---[Crypto_She_CancelInit]------------------------------------------------*/

FUNC(void, CRY_CODE) Crypto_CancelInit(void)
{
    Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelIdle;
    Crypto_CancelState_S.LockedHsm_E = FALSE;
    Crypto_CancelState_S.jobId_E = (te_cryptojobid)0;
}

/*---[Crypto_She_Cancel]------------------------------------------------*/
FUNC(boolean, CRY_CODE)Crypto_She_Cancel(te_canceljobid p_cancelJob_e)
{
    boolean fl_ret_bool = FALSE;
    if((Crypto_Hsm_CancelIdle == Crypto_CancelState_S.cancelstatus) &&
            (FALSE != Crypto_IsInit()))
    {

        l_canceljob_e = p_cancelJob_e;
        /* Pack the data */
        Crypto_Hsm_CryptoCancelPackedData_S.KeyId_U8 = 0u;
        Crypto_Hsm_CryptoCancelPackedData_S.jobId_E = CID_67_CRYPTO_JOB_CANCEL_UPDATE;
        Crypto_Hsm_CryptoCancelPackedData_S.payLoadPtr_U8P = &l_canceljob_e;
        Crypto_Hsm_CryptoCancelPackedData_S.payLoadSize = 1u;
        Crypto_Hsm_CryptoCancelPackedData_S.priority_U8 = (te_jobpriority)0;
        Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelStart;
        if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptoCancelPackedData_S))
        {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelTrack;
            fl_ret_bool = TRUE;
#else
            Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelIdle;
            Crypto_CancelState_S.LockedHsm_E = FALSE;
            vHsmIpc_HostManager_PeriodicCheck();
            fl_ret_bool = TRUE;
#endif
        }
        else
        {
            Crypto_CancelState_S.faultLog_U8++;
            Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelIdle;
            Crypto_CancelState_S.LockedHsm_E = FALSE;
        }

    }
    return fl_ret_bool;
}

/*---[Crypto_She_CancelCallback]------------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_She_CancelCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    uint8 fl_result_U8 = *p_resultBytesInSRAM_U8P;
    CRYPTO_RELEASE_HSM();
    if ((Crypto_CancelState_S.LockedHsm_E == TRUE) &&
            (Crypto_Hsm_CancelTrack == Crypto_CancelState_S.cancelstatus))
    {
        Crypto_CancelState_S.LockedHsm_E = FALSE;
        Crypto_CancelState_S.cancelstatus = Crypto_Hsm_CancelIdle;
        if( (((uint8)CRYPTO_JOB_DONE) == fl_result_U8) && ((uint16)0x01 == payload_size))
        {

        }
        else
        {
            /* Re-issue the cancel command? */
            Crypto_She_Cancel(l_canceljob_e);
        }

    }
#else
    CRYPTO_UNUSED_PARAMETER(p_resultBytesInSRAM_U8P);
    CRYPTO_UNUSED_PARAMETER(payload_size);
#endif
}

/*---[Cry_She_CancelCallback]------------------------------------------------*/
FUNC(boolean, CRY_CODE)Crypto_She_GetCancelIsComplete(void)
{
    boolean fl_ret_val = FALSE;
    if((Crypto_CancelState_S.cancelstatus) == Crypto_Hsm_CancelIdle)
    {
        fl_ret_val = TRUE;
    }
    return(fl_ret_val);
}

#endif /*CRYPTO_CANCEL_ENABLED*/



