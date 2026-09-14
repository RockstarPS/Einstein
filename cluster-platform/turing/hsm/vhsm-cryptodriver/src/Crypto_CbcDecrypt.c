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
 * \file Crypto_CbcDecrypt.c
 *
 * \brief
 * CBC decrypt implementation in M7
 *
 * \detailed description
 *  This file shall be the CBC decrypt implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                        |
 * 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Umaralli A Rajak Shaikh  | ushaikh   | VTSC, Bengaluru, India
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/*==[Includes]================================================================*/

#include "Crypto_She.h"
#include "Crypto_CbcDecrypt.h"
#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "stub.h"
#include "vHsmCryptoManager.h"
//#include "vHsmIpcHostManager.h"

#if (CRYPTO_CBCDECRYPT_ENABLED == 1)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/
typedef enum
{
    CRYPTO_HSM_SYMDECRYPT_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_HSM_SYMDECRYPT_WAIT /* HSM is waiting on the data from CSM */
}
Crypto_Hsm_SymDecryptWorkType;

typedef struct
{
        VAR(Crypto_SymKeyInfoType,CRY_APPL_DATA) keyInfo;
        P2CONST(uint8,TYPEDEF, CRY_APPL_DATA) initPtr;
        VAR(uint32, CRY_APPL_DATA)            initLen;
        P2CONST(uint8,TYPEDEF,CRY_APPL_DATA)  iputPtr;
        uint32                                iputLen;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    oputPtr;
        P2VAR(uint32, TYPEDEF, CRY_APPL_DATA) oputLenPtr;
        Crypto_Hsm_SymDecryptWorkType         work;
        uint32                                icount;
        uint32                                ocount;
        Crypto_StateType                  state;
        Crypto_StateType                  stateRequested;
        uint8                                 priority;
        uint8                                 faultLog_U8;
        uint8                                 buffer[256];
        uint16                                len;
        boolean                               LockedHsm_E;
        boolean                               Directcall;
}
Crypto_Hsm_SymDecryptStateType;

/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymDecryptFillInputFifo
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptFillInputFifo(void);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymCBCDecryptCallback
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymCBCDecryptCallback(Csm_ReturnType param);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SymDecryptActionOnFault
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptActionOnFault(void);

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_Hsm_SymDecryptStateType, CRY_VAR) Crypto_SymDecryptState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SymDecryptNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_Hsm_CryptCBCDecryptPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_DecryptCBCJob_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_DecryptCBCJob_Error;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

FUNC(void, CRY_CODE) Crypto_SymDecryptInit(void)
{
    Crypto_SymDecryptState_S.state = Crypto_Idle;
    Crypto_SymDecryptState_S.stateRequested = Crypto_Idle;
    Crypto_SymDecryptState_S.initPtr = NULL;
    Crypto_SymDecryptState_S.initLen = 0u;
    Crypto_SymDecryptState_S.iputPtr  = NULL;
    Crypto_SymDecryptState_S.iputLen  = 0u;
    Crypto_SymDecryptState_S.oputPtr  = NULL;
    Crypto_SymDecryptState_S.oputLenPtr  = NULL;
    Crypto_SymDecryptState_S.icount = 0u;
    Crypto_SymDecryptState_S.ocount = 0u;
    Crypto_SymDecryptState_S.LockedHsm_E      = FALSE;
    Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SymDecryptState_S.faultLog_U8 = 0u;
    Crypto_SymDecryptState_S.work = CRYPTO_HSM_SYMDECRYPT_WAIT;
    vHsmCrypt_DecryptCBCJob_Completed = FALSE;
    vHsmCrypt_DecryptCBCJob_Error = FALSE;
    Crypto_SymDecryptState_S.Directcall = FALSE;
}

/*---[Crypto_She_SymDecrypt - direct call with callback update of results from M0P]--------*/
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

)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_SymDecryptConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_src1_U8P;
    P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_src2_U8P;
    uint32 fl_TotalBufflength_U32;
    uint32 fl_PlainTextlength_U32;
    if ((TRUE != Crypto_IsInit()) || (NULL == cfgPtr) || (NULL == keyPtr) || (NULL == initVectorPtr) ||
            (0u == initVectorLength) || (NULL == iputTextPtr) || (0u == iputTextLength) || (NULL == oputTextPtr)||
            (NULL == oputTextLengthPtr))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymDecryptNotif_S.callbackNeeded = FALSE;
        Crypto_SymDecryptNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_SymDecryptConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymDecryptState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymDecryptState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymDecryptState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            if (keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH)
            {
                Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK; 
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymDecryptState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymDecryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Hsm_Start;
                }
                else
                {
                    Crypto_SymDecryptState_S.stateRequested = Crypto_Hsm_Start;
                }
#else
                /*Packing CipherText and IV in a buffer*/
                (void)memset(&Crypto_SymDecryptState_S.buffer[0],0u,sizeof(Crypto_SymDecryptState_S.buffer));
                fl_ptr_src1_U8P = (uint8 *)initVectorPtr;
                fl_ptr_src2_U8P = (uint8 *)iputTextPtr;
                fl_PlainTextlength_U32 = *oputTextLengthPtr;
                /* Packing of CipherText */
                (void)memcpy(&Crypto_SymDecryptState_S.buffer[0],fl_ptr_src1_U8P, initVectorLength);
                /* Packing of Initialisation Vector(IV) */
                (void)memcpy(&Crypto_SymDecryptState_S.buffer[initVectorLength],fl_ptr_src2_U8P, iputTextLength);
                /* Packing length of CipherText */
                (void)memcpy(&Crypto_SymDecryptState_S.buffer[iputTextLength+initVectorLength], (uint8 *)&iputTextLength, 4u);
                /* Packing length of PlainText */
                (void)memcpy(&Crypto_SymDecryptState_S.buffer[iputTextLength+initVectorLength+4U], (uint8 *)&fl_PlainTextlength_U32, 4u);
                fl_TotalBufflength_U32 = initVectorLength + iputTextLength + 8u; /*8u is for length(cipher + plain)*/
                if(INT16_MAX_RANGE >= fl_TotalBufflength_U32)
                {
                Crypto_SymDecryptState_S.len = (uint8)fl_TotalBufflength_U32;
                }
                else
                {
                     /*Handle the case of overflow*/
                }
                Crypto_SymDecryptState_S.state = Crypto_Finish;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymDecryptState_S.LockedHsm_E = TRUE;
                Crypto_SymDecryptState_S.Directcall = TRUE;
                Crypto_SymDecryptState_S.initPtr = initVectorPtr;
                Crypto_SymDecryptState_S.initLen = initVectorLength;
                /* Check if the input and output buffers are valid. */
                if(((iputTextLength % CRYPTO_HSM_BLOCK_LENGTH) == 0U) &&
                        (*oputTextLengthPtr >= iputTextLength))
                {
                    
                    Crypto_SymDecryptState_S.iputPtr     = iputTextPtr;
                    Crypto_SymDecryptState_S.iputLen     = iputTextLength;
                    Crypto_SymDecryptState_S.oputPtr     = oputTextPtr;
                    Crypto_SymDecryptState_S.oputLenPtr  = oputTextLengthPtr;
                    Crypto_SymDecryptState_S.work        = CRYPTO_HSM_SYMDECRYPT_WORK;
                    Crypto_SymDecryptState_S.icount      = iputTextLength;
                    Crypto_SymDecryptState_S.ocount      = 0u;
                    Crypto_SymDecryptState_S.priority   = locCfgPtr->priority;
                    /* Deviation MISRA-2 <+2> */
                    Crypto_SymDecryptState_S.keyInfo.keyId = (keyPtr->data);
                    vHsmCrypt_DecryptCBCJob_Error = FALSE;
					vHsmCrypt_DecryptCBCJob_Completed = FALSE;
					while(FALSE==vHsmCrypt_DecryptCBCJob_Completed)
                    {
                        if(FALSE != vHsmCrypt_DecryptCBCJob_Error)
                        {
                            fl_ret_E = CSM_E_NOT_OK;                    
                            break;
                        }
                        else
                        {
                            Crypto_She_SymDecryptMainFunction();
                            vHsmIpc_HostManager_PeriodicCheck();
                            //CySldIpc_Isr_IpcDrv_Cat2();
                        }
                    }
                    Crypto_SymDecryptState_S.state = Crypto_Idle;
                    vHsmCrypt_DecryptCBCJob_Error = FALSE;
                }
                else
                {
                    if  ( *oputTextLengthPtr < iputTextLength)
                    {
                        /* !LINKSTO CSM0663, 1
                        */
                        fl_ret_E = CSM_E_SMALL_BUFFER;
                    }
                    else
                    {
                        fl_ret_E = CSM_E_NOT_OK;
                    }
                    Crypto_Hsm_SymDecryptCancel();
                }
                vHsmCrypt_DecryptCBCJob_Error = FALSE;
            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif     /*CRYPTO_PRIORITY_ENABLED*/
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymCBCDecryptCallback(Crypto_SymDecryptNotif_S.callbackParamValue);
    return fl_ret_E;
}

#ifdef CBCDECRYPT_STRUPDFIN_ENABLE

/*---[Crypto_She_SymDecryptStart]-------------------------------------------*/

/* !LINKSTO CRYSHE_80, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptStart
(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
  P2CONST(uint8,          AUTOMATIC, CRY_APPL_DATA) initVectorPtr,
      VAR(uint32,         AUTOMATIC               ) initVectorLength
)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_SymDecryptConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) ||
            (keyPtr == NULL) || (initVectorPtr == NULL) ||
            (initVectorLength == 0u))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymDecryptNotif_S.callbackNeeded = FALSE;
        Crypto_SymDecryptNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_SymDecryptConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymDecryptState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymDecryptState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymDecryptState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }

        if (CSM_E_OK == fl_ret_E)
        {
#endif /* CRYPTO_PRIORITY_ENABLED */
            if ( keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH )
            {
                Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymDecryptState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymDecryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Hsm_Start;
                }
                else
                {
                    Crypto_SymDecryptState_S.stateRequested = Crypto_Hsm_Start;
                }
#else
                Crypto_SymDecryptState_S.state = Crypto_Hsm_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */

                Crypto_SymDecryptState_S.priority   = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymDecryptState_S.keyInfo.keyId = (keyPtr->data);
                Crypto_SymDecryptState_S.icount = 0u;
                Crypto_SymDecryptState_S.initPtr = initVectorPtr;
                Crypto_SymDecryptState_S.initLen = initVectorLength;
                vHsmCrypt_DecryptCBCJob_Error = FALSE;
            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif  /* CRYPTO_PRIORITY_ENABLED */
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymCBCDecryptCallback(Crypto_SymDecryptNotif_S.callbackParamValue);
    return fl_ret_E;
}

/*---[Crypto_She_SymDecryptUpdate]------------------------------------------*/

/* !LINKSTO CRYSHE_86, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptUpdate
(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) iputTextPtr,
      VAR(uint32, AUTOMATIC               ) iputTextLength,
    P2VAR(uint8,  AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
    P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr
)
{
    //CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if ((iputTextPtr == NULL) || (oputTextPtr == NULL) ||
            (oputTextLengthPtr == NULL) || (iputTextLength == 0u) )
        {
            ret = CSM_E_NOT_OK;
        }
    if( ( Crypto_SymDecryptState_S.state == Crypto_Idle ) ||
        ( Crypto_SymDecryptState_S.state == Crypto_Hsm_Cancel) ||
        ( Crypto_SymDecryptState_S.state == Crypto_Finish) ||
        ( Crypto_SymDecryptState_S.state == Crypto_Finish_Wait))
    {
        ret = CSM_E_NOT_OK;
    }
    if(ret == CSM_E_OK)
    {
        if
        (
                ( Crypto_SymDecryptState_S.state == Crypto_Update ) &&
                ( Crypto_SymDecryptState_S.work == CRYPTO_HSM_SYMDECRYPT_WAIT )
        )
        {
            /* Check if the input and output buffers are valid. */
            if ( ((iputTextLength % CRYPTO_HSM_BLOCK_LENGTH    ) == 0U            ) &&
                 (*oputTextLengthPtr                          >= iputTextLength)
            )
            {
                Crypto_SymDecryptState_S.iputPtr     = iputTextPtr;
                Crypto_SymDecryptState_S.iputLen     = iputTextLength;
                Crypto_SymDecryptState_S.oputPtr     = oputTextPtr;
                Crypto_SymDecryptState_S.oputLenPtr  = oputTextLengthPtr;
                Crypto_SymDecryptState_S.work        = CRYPTO_HSM_SYMDECRYPT_WORK;
                Crypto_SymDecryptState_S.icount      += iputTextLength;
                Crypto_SymDecryptState_S.ocount      = 0u;
                vHsmCrypt_DecryptCBCJob_Error = FALSE;
            }
            else
            {
                if  ( *oputTextLengthPtr < iputTextLength)
                {
                    /* !LINKSTO CSM0663, 1
                     */
                    ret = CSM_E_SMALL_BUFFER;
                }
                else
                {
                    ret = CSM_E_NOT_OK;
                }
                Crypto_Hsm_SymDecryptCancel();
            }
        }
        else if
        (
                ( Crypto_SymDecryptState_S.state == Crypto_Update ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Start_Wait ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Update_Wait ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Hsm_Start )
        )
        {
            ret = CSM_E_BUSY;
        }
        else
        {
            ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                    if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
                    {
                        Crypto_SymDecryptState_S.state = Crypto_Idle;
                    }
                    else
                    {
                        Crypto_SymDecryptState_S.stateRequested = Crypto_Idle;
                    }
    #else
                    Crypto_SymDecryptState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    //CRYPTO_RELEASE_SEM();

    return ret;
}

/*---[Crypto_She_SymDecryptFinish]------------------------------------------*/

/* !LINKSTO CRYSHE_95, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymDecryptFinish
(
  P2VAR(uint8,  AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
  P2VAR(uint32, AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr
)
{
    Csm_ReturnType ret;
    /* Deviation MISRA-4 */
    CRYPTO_HSM_UNUSED_PARAMETER(oputTextPtr);
    //CRYPTO_LOCK_SEM();
    if( ( Crypto_SymDecryptState_S.state == Crypto_Idle ) ||
        ( Crypto_SymDecryptState_S.state == Crypto_Hsm_Cancel) ||
        ( Crypto_SymDecryptState_S.state == Crypto_Finish_Wait))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if
        (
                ( Crypto_SymDecryptState_S.state == Crypto_Update ) &&
                ( Crypto_SymDecryptState_S.work == CRYPTO_HSM_SYMDECRYPT_WAIT )
        )
        {
            Crypto_SymDecryptState_S.state = Crypto_Finish;
            vHsmCrypt_DecryptCBCJob_Error = FALSE;
            ret = CSM_E_OK;
        }
        else if
        (
                ( Crypto_SymDecryptState_S.state == Crypto_Update ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Start_Wait ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Update_Wait ) ||
                ( Crypto_SymDecryptState_S.state == Crypto_Hsm_Start )
        )
        {
            ret = CSM_E_BUSY;
        }
        else
        {
            ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            if( Crypto_SymDecryptState_S.state != Crypto_Hsm_Cancel)
            {
                Crypto_SymDecryptState_S.state = Crypto_Idle;
            }
            else
            {
                Crypto_SymDecryptState_S.stateRequested = Crypto_Idle;
            }
    #else
        Crypto_SymDecryptState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    //CRYPTO_RELEASE_SEM();

    return ret;
}

#endif /*CBCDECRYPT_STRUPDFIN_ENABLE*/ 

/*---[Crypto_She_SymDecryptMainFunction]------------------------------------*/

/* !LINKSTO CRYSHE_100, 1
 */
FUNC(void,CRY_CODE) Crypto_She_SymDecryptMainFunction
        (
                void
        )
{
    //CRYPTO_LOCK_SEM();
    Crypto_SymDecryptNotif_S.callbackNeeded = FALSE;
    Crypto_SymDecryptNotif_S.finishNeeded = FALSE;
    switch (Crypto_SymDecryptState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Hsm_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                if(Crypto_Hsm_Start == Crypto_SymDecryptState_S.stateRequested)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Hsm_Start;
                }
                else
                {
                    Crypto_SymDecryptState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /*#if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
#ifdef CBCDECRYPT_STRUPDFIN_ENABLE
        case Crypto_Hsm_Start:
            Crypto_SymDecryptState_S.LockedHsm_E = Crypto_She_LockShe();

            /* !LINKSTO CRYSHE_25, 1
             */
            if (Crypto_SymDecryptState_S.LockedHsm_E == TRUE)
            {
                Crypto_Hsm_CryptCBCDecryptPackedData_S.KeyId_U32 =
                        Crypto_SymDecryptState_S.keyInfo.keyId;
                Crypto_Hsm_CryptCBCDecryptPackedData_S.jobId_E = CID_54_SYM_DECRYPT_START;
                Crypto_Hsm_CryptCBCDecryptPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadPtr_U8P =
                        (uint8 *)Crypto_SymDecryptState_S.initPtr;
                Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadSize =
                        Crypto_SymDecryptState_S.initLen;
                vHsmCrypt_DecryptCBCJob_Completed = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptCBCDecryptPackedData_S))
                {
                    Crypto_SymDecryptState_S.state = Crypto_Start_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_Hsm_SymDecryptActionOnFault();
                }
            }
            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_DecryptCBCJob_Completed)
            {
                if(FALSE == vHsmCrypt_DecryptCBCJob_Error)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Update;
                    Crypto_SymDecryptState_S.work  = CRYPTO_HSM_SYMDECRYPT_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                    Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_Hsm_SymDecryptActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                   * if no response for 1sec, then, reset everything*/
                  if (TRUE == Crypto_CheckFaultPeriodic())
                  {
                      Crypto_Hsm_SymDecryptActionOnFault();
                  }
                  else
                  {
                      /* Wait for the fault counter to expire to reset all
                       * which is handled in the above if condition */
                  }
            }
            break;
#endif /*CBCDECRYPT_STRUPDFIN_ENABLE*/           
        case Crypto_Update:
            if ( Crypto_SymDecryptState_S.work == CRYPTO_HSM_SYMDECRYPT_WORK )
            {
                /* There is still data left to encrypt. */
                Crypto_Hsm_SymDecryptFillInputFifo();
            }
            break;
        case Crypto_Update_Wait:
            if (TRUE == vHsmCrypt_DecryptCBCJob_Completed)
            {
                if(FALSE == vHsmCrypt_DecryptCBCJob_Error)
                {
                    Crypto_SymDecryptState_S.state = Crypto_Update;
                    Crypto_SymDecryptState_S.work  = CRYPTO_HSM_SYMDECRYPT_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                    Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_Hsm_SymDecryptActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SymDecryptActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
                if(FALSE != Crypto_SymDecryptState_S.Directcall)
                {
                    if(FALSE != Crypto_SymDecryptState_S.LockedHsm_E)
                    {
                        if(INT16_MAX_RANGE >= Crypto_SymDecryptState_S.keyInfo.keyId)
                        {
                            Crypto_Hsm_CryptCBCDecryptPackedData_S.KeyId_U8 =
                                                       (uint8) Crypto_SymDecryptState_S.keyInfo.keyId;
                            Crypto_Hsm_CryptCBCDecryptPackedData_S.jobId_E = CID_53_SYM_DECRYPT_FN;
                            Crypto_Hsm_CryptCBCDecryptPackedData_S.priority_U8 = (te_jobpriority)0;
                            Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadPtr_U8P = 
                                    (uint8 *)&Crypto_SymDecryptState_S.buffer[0];
                            Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadSize = Crypto_SymDecryptState_S.len; 
                            vHsmCrypt_DecryptCBCJob_Completed = FALSE;
                            if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptCBCDecryptPackedData_S))
                            {
                                Crypto_SymDecryptState_S.state = Crypto_Finish_Wait;
                                Crypto_ResetFaultCounter();
                            }
                            else
                            {
                                Crypto_Hsm_SymDecryptActionOnFault();
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
                    if(INT16_MAX_RANGE >= Crypto_SymDecryptState_S.keyInfo.keyId)
                    {
                        Crypto_Hsm_CryptCBCDecryptPackedData_S.KeyId_U8 =
                                                       (uint8) Crypto_SymDecryptState_S.keyInfo.keyId;
                        Crypto_Hsm_CryptCBCDecryptPackedData_S.jobId_E = CID_52_SYM_DECRYPT_FINISH;
                        Crypto_Hsm_CryptCBCDecryptPackedData_S.priority_U8 = (te_jobpriority)0;
                        Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadPtr_U8P = NULL;
                        Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadSize = 0u; /* no payload */
                        vHsmCrypt_DecryptCBCJob_Completed = FALSE;
                        if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_CryptCBCDecryptPackedData_S))
                        {
                            Crypto_SymDecryptState_S.state = Crypto_Finish_Wait;
                            Crypto_ResetFaultCounter();
                        }
                        else
                        {
                            Crypto_Hsm_SymDecryptActionOnFault();
                        }
                    }
                    else 
                    {
                        /*Handle the case of overflow*/
                    }
                }   
            break;
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_DecryptCBCJob_Completed)
            {
                Crypto_SymDecryptState_S.state = Crypto_Idle;
                Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymDecryptNotif_S.finishNeeded = TRUE;
                Crypto_SymDecryptState_S.work  = CRYPTO_HSM_SYMDECRYPT_WAIT;
                Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
                if(FALSE == vHsmCrypt_DecryptCBCJob_Error)
                {
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SymDecryptState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_Hsm_SymDecryptActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        default:
            Crypto_Hsm_SymDecryptActionOnFault();
            break;
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_Hsm_SymCBCDecryptCallback(Crypto_SymDecryptNotif_S.callbackParamValue);
}

FUNC(void, CRY_CODE) Crypto_She_CBCDecryptCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint32 res_length;
    uint8 status = *p_resultBytesInSRAM_U8P;
    if (Crypto_SymDecryptState_S.LockedHsm_E == TRUE)
    {
        switch (Crypto_SymDecryptState_S.state)
        {
            case Crypto_Start_Wait:
                vHsmCrypt_DecryptCBCJob_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_DecryptCBCJob_Error = TRUE;
                }
                break;
             case Crypto_Update_Wait:
                vHsmCrypt_DecryptCBCJob_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_DecryptCBCJob_Error = TRUE;
                }
                
                break;
            case Crypto_Finish_Wait:
                res_length= (uint32)payload_size - (uint32)1;
                vHsmCrypt_DecryptCBCJob_Completed = TRUE;
                if(Crypto_SymDecryptState_S.oputLenPtr != NULL)
                {
                    if(((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                       (Crypto_SymDecryptState_S.icount == res_length))
                    {
                            /* Copy the result data into the memory location shared from application */
                    (void)memcpy((uint8 *)Crypto_SymDecryptState_S.oputPtr,(uint8 *)&p_resultBytesInSRAM_U8P[1],
                                    (uint16)res_length);
                    }
                    else
                    {
                        vHsmCrypt_DecryptCBCJob_Error = TRUE;
                    }
                }
                else
                {
                    vHsmCrypt_DecryptCBCJob_Error = TRUE;
                }
                Crypto_She_SymDecryptMainFunction();
                break;
            default:
                vHsmCrypt_DecryptCBCJob_Error = TRUE;
                break;
        }
    }
}

/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptFillInputFifo(void)
{
    Std_ReturnType fl_retVal;

    /* If the RAM key is used, check whether the correct key is loaded
     * into the SHE.
     */
    /* !LINKSTO CRYSHE_41, 1
     */
    if
    (
            (Crypto_SymDecryptState_S.keyInfo.keyId == CRYPTO_SHE_RAM_KEY         ) &&
            (Crypto_SymDecryptState_S.keyInfo.keyNr != Crypto_SymKeyInfo.keyNr)
    )
    {
        Crypto_Hsm_SymDecryptActionOnFault();
    }
    else
    {
    	if(INT16_MAX_RANGE >= Crypto_SymDecryptState_S.keyInfo.keyId)
        
        {
            Crypto_Hsm_CryptCBCDecryptPackedData_S.KeyId_U8 =(uint8) Crypto_SymDecryptState_S.keyInfo.keyId;
            Crypto_Hsm_CryptCBCDecryptPackedData_S.jobId_E = CID_55_SYM_DECRYPT_UPDATE;
            Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_SymDecryptState_S.iputPtr;
            Crypto_Hsm_CryptCBCDecryptPackedData_S.payLoadSize = Crypto_SymDecryptState_S.iputLen;
            Crypto_Hsm_CryptCBCDecryptPackedData_S.priority_U8 = (te_jobpriority)0;
            vHsmCrypt_DecryptCBCJob_Completed = FALSE;
            fl_retVal = Crypto_SendPackedData(Crypto_Hsm_CryptCBCDecryptPackedData_S);
            if (E_OK == fl_retVal)
            {
                Crypto_SymDecryptState_S.state = Crypto_Update_Wait;
                Crypto_ResetFaultCounter();
            }
            else
            {
                Crypto_Hsm_SymDecryptActionOnFault();
            }
		}
        else 
        {
             Crypto_Hsm_SymDecryptActionOnFault();
        }
    }
}

FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptCancel(void)
{
    Crypto_SymDecryptState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SymDecryptState_S.state = Crypto_Hsm_Cancel;
#else
    Crypto_SymDecryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_SymDecryptState_S.LockedHsm_E == TRUE)
    {
        Crypto_SymDecryptState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }
    (void)Crypto_She_Cancel(e_aescbcdecrypt);
}

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymCBCDecryptCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SymDecryptNotif_S.callbackNeeded)
    {
        Crypto_SymDecryptNotif_S.callbackNeeded = FALSE;
        CRYPTO_HSM_CSM_SYMDECRYPT_CALLBACK_NOTIF(param);
        //CRYPTO_HSM_BL_SYMDECRYPT_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SymDecryptNotif_S.finishNeeded)
    {
        Crypto_SymDecryptNotif_S.finishNeeded = FALSE;
        //CRYPTO_HSM_CSM_SYMDECRYPT_SERVICE_FINISH_NOTIF();
    }
}

void Csm_SymDecryptCallbackNotification(Csm_ReturnType result)
{

}

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_SymDecryptActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_SymDecryptState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SymDecryptState_S.faultLog_U8++;
    }
    vHsmCrypt_DecryptCBCJob_Error = TRUE;
    Crypto_SymDecryptNotif_S.callbackNeeded = TRUE;
    Crypto_SymDecryptNotif_S.finishNeeded = TRUE;
    Crypto_SymDecryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_Hsm_SymDecryptCancel();
    Crypto_ResetFaultCounter();
}

#endif /*CRYPTO_CBCDECRYPT_ENABLED*/

