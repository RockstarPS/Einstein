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
 * \file Crypto_EcbEncrypt.c
 *
 * \brief
 * ECB encrypt implementation in M7
 *
 * \detailed description
 *  This file shall be the ECB encrypt implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                        |
 * 
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
#include "Crypto_EcbEncrypt.h"
//#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "stub.h"
#include "vHsmCryptoManager.h"
//#include "vHsmIpcHostManager.h"

#if (CRYPTO_ECBENCRYPT_ENABLED == 1)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/
typedef enum
{
    CRYPTO_SYMBLOCKENCRYPT_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_SYMBLOCKENCRYPT_WAIT /* HSM is waiting on the data from CSM */
}
Cry_Hsm_SymBlockEncryptWorkType;

typedef struct
{
        VAR(Crypto_SymKeyInfoType,CRY_APPL_DATA) keyInfo;
        P2CONST(uint8,TYPEDEF,CRY_APPL_DATA)  iputPtr;
        uint32                                iputLen;
        P2VAR(uint8,TYPEDEF,CRY_APPL_DATA)    oputPtr;
        P2VAR(uint32, TYPEDEF, CRY_APPL_DATA) oputLenPtr;
        Cry_Hsm_SymBlockEncryptWorkType       work;
        uint32                                icount;
        uint32                                ocount;
        Crypto_StateType                     state;
        Crypto_StateType                     stateRequested;
        uint8                                 priority;
        uint8                                 faultLog_U8;
        uint8                                 buffer[256];
        uint16                                len;
        boolean                               LockedHsm_E;
        boolean                               Directcall;
}
Crypto_SymBlockEncryptStateType;
/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_SymBlockEncryptFillInputFifo
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
STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptFillInputFifo(void);

/**
 *********************************************************************************************
 ** \fn Crypto_SymBlockEncryptCallback
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
STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptCallback(Csm_ReturnType param);


/**
 *********************************************************************************************
 ** \fn Crypto_SymBlockEncryptActionOnFault
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
STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptActionOnFault(void);

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_SymBlockEncryptStateType, CRY_VAR) Crypto_SymBlockEncryptState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_SymBlockEncryptNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_CryptECBPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_EncryptJob_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_EncryptJob_Error;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/
FUNC(void, CRY_CODE) Crypto_She_SymBlockEncryptInit(void)
{
    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
    Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Idle;
    Crypto_SymBlockEncryptState_S.iputPtr  = NULL;
    Crypto_SymBlockEncryptState_S.iputLen  = 0;
    Crypto_SymBlockEncryptState_S.oputPtr  = NULL;
    Crypto_SymBlockEncryptState_S.oputLenPtr  = NULL;
    Crypto_SymBlockEncryptState_S.icount = 0u;
    Crypto_SymBlockEncryptState_S.ocount = 0u;
    Crypto_SymBlockEncryptState_S.LockedHsm_E      = FALSE;
    Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_SymBlockEncryptState_S.faultLog_U8 = 0u;
    Crypto_SymBlockEncryptState_S.work = CRYPTO_SYMBLOCKENCRYPT_WAIT;
    vHsmCrypt_EncryptJob_Completed = FALSE;
    vHsmCrypt_EncryptJob_Error = FALSE;
}

/*---[Crypto_She_SymBlockEncrypt - direct call with callback update of results from M0P]--------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncrypt_S
(
    P2CONST (void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
    P2CONST (Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
    P2CONST (uint8,          AUTOMATIC, CRY_APPL_DATA) iputTextPtr,
    VAR     (uint32,         AUTOMATIC               ) iputTextLength,
    P2VAR   (uint8,          AUTOMATIC, CRY_APPL_DATA) oputTextPtr,
    P2VAR   (uint32,         AUTOMATIC, CRY_APPL_DATA) oputTextLengthPtr,
    VAR     (uint8,          AUTOMATIC               ) padding_pkcs7
)
{
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_SymBlockEncryptConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) fl_ptr_src2_U8P;
    uint32 fl_TotalBufflength_U32;
    if ((TRUE != Crypto_IsInit()) || (NULL == cfgPtr) || (NULL == keyPtr) || (NULL == iputTextPtr) || (0u == iputTextLength) || (NULL == oputTextPtr)||
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
        Crypto_SymBlockEncryptNotif_S.callbackNeeded = FALSE;
        Crypto_SymBlockEncryptNotif_S.finishNeeded = FALSE;

        locCfgPtr = (P2CONST(Crypto_She_SymBlockEncryptConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        if (locCfgPtr->priority < Crypto_SymBlockEncryptState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymBlockEncryptState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymBlockEncryptState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }
        if (CSM_E_OK == fl_ret_E)
        {
#endif  /*CRYPTO_PRIORITY_ENABLED*/
            if (keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH)
            {
                Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK; 
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymBlockEncryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymBlockEncryptState_S.state != Crypto_Hsm_Cancel)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Finish;
                }
                else
                {
                    Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Finish;
                }
#else

				if(Crypto_Idle == Crypto_SymBlockEncryptState_S.state)
				{
					/* Packing of PlainText */
					(void)memcpy(&Crypto_SymBlockEncryptState_S.buffer[0],iputTextPtr, iputTextLength);
                    if(INT16_MAX_RANGE >= iputTextLength)
                    {
                        Crypto_SymBlockEncryptState_S.len = (uint16)iputTextLength;
                    }
                    else
                    {
                        /*Handle the case of overflow*/
                    }
					Crypto_SymBlockEncryptState_S.state = Crypto_Finish;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
					Crypto_SymBlockEncryptState_S.Directcall = TRUE;
                    
					/* Check if the input and output buffers are valid. */
					if(((iputTextLength % CRYPTO_HSM_BLOCK_LENGTH) == 0U) &&
							(*oputTextLengthPtr >= iputTextLength))
					{
						Crypto_SymBlockEncryptState_S.oputPtr     = oputTextPtr;
						Crypto_SymBlockEncryptState_S.oputLenPtr  = oputTextLengthPtr;
						Crypto_SymBlockEncryptState_S.work        = CRYPTO_SYMBLOCKENCRYPT_WORK;
						Crypto_SymBlockEncryptState_S.icount      = iputTextLength;
						Crypto_SymBlockEncryptState_S.ocount      = 0u;
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
						Crypto_SymBlockEncryptCancel();
					}
					Crypto_SymBlockEncryptState_S.priority   = locCfgPtr->priority;
					/* Deviation MISRA-2 <+2> */
					Crypto_SymBlockEncryptState_S.keyInfo.keyId = (uint8)(keyPtr->data);
                    Crypto_SymBlockEncryptState_S.LockedHsm_E = TRUE;
					vHsmCrypt_EncryptJob_Error = FALSE;
					vHsmCrypt_EncryptJob_Completed = FALSE;
					while(FALSE==vHsmCrypt_EncryptJob_Completed)
                    {
                        if(FALSE != vHsmCrypt_EncryptJob_Error)
                        {
                            fl_ret_E = CSM_E_NOT_OK;
                            break;
                        }
                        else
                        {
                            Crypto_She_SymBlockEncryptMainFunction();
                            vHsmIpc_HostManager_PeriodicCheck();
                            //CySldIpc_Isr_IpcDrv_Cat2();
                        }
                    }
                    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                    Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
				}
				else
				{
					fl_ret_E = CSM_E_NOT_OK;
				}
            }
#if(CRYPTO_PRIORITY_ENABLED == STD_ON)
        }
#endif     /*CRYPTO_PRIORITY_ENABLED*/
    }
    return fl_ret_E;
}

/*---[Crypto_She_SymBlockEncryptStart]-------------------------------------------*/

/* !LINKSTO CRYSHE_80, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptStart
        (
                P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType,AUTOMATIC,CRY_APPL_DATA) keyPtr
        )
{
	//CRYPTO_LOCK_SEM();	
    Csm_ReturnType fl_ret_E = CSM_E_OK;
    P2CONST(Crypto_She_SymBlockEncryptConfigType, AUTOMATIC, CRY_APPL_DATA) locCfgPtr;
    if ((TRUE != Crypto_IsInit()) || (cfgPtr == NULL) || (keyPtr == NULL))
    {
        fl_ret_E = CSM_E_NOT_OK;
    }
    if(CSM_E_OK == fl_ret_E)
    {
        Crypto_SymBlockEncryptNotif_S.callbackNeeded = FALSE;
        Crypto_SymBlockEncryptNotif_S.finishNeeded = FALSE;
 
        locCfgPtr = (P2CONST(Crypto_She_SymBlockEncryptConfigType, AUTOMATIC, CRY_APPL_DATA)) cfgPtr;

        if (locCfgPtr->priority < Crypto_SymBlockEncryptState_S.priority)
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
                    (CRYPTO_PRIORITY_NONE != Crypto_SymBlockEncryptState_S.priority) &&
                    (locCfgPtr->priority   != Crypto_SymBlockEncryptState_S.priority)
            )
            {
                /* !LINKSTO CRYSHE_24, 1
                 */

                /* !LINKSTO CRYSHE_290_3, 1
                 */
                Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_BUSY;
            }
        }

        if (CSM_E_OK == fl_ret_E)
        {
            /* CHECK: NOPARSE */
            /* Defensive programming. The true branch cannot be reached with the current state machine */
            if
            (
                    (Crypto_SymBlockEncryptState_S.priority != CRYPTO_PRIORITY_NONE) &&
                    (Crypto_SymBlockEncryptState_S.LockedHsm_E == TRUE)
            )
                /* CHECK: PARSE */
            {
                /* An encryption is already running and has to be cancelled. */
                /* !LINKSTO CRYSHE_26, 1
                 */
                Crypto_SymBlockEncryptCancel();
            }
            if ( keyPtr->length != CRYPTO_HSM_CONST_KEY_LENGTH )
            {
                Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
                Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                fl_ret_E = CSM_E_NOT_OK;
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymBlockEncryptState_S.state != Crypto_Cancel)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                }
                else
                {
                    Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Idle;
                }
#else
                Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            }
            else
            {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                if( Crypto_SymBlockEncryptState_S.state != Crypto_Cancel)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Start;
                }
#else
                Crypto_SymBlockEncryptState_S.state = Crypto_Start;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
                Crypto_SymBlockEncryptState_S.priority = locCfgPtr->priority;
                /* Deviation MISRA-2 <+2> */
                Crypto_SymBlockEncryptState_S.keyInfo.keyId = (keyPtr->data);
                Crypto_SymBlockEncryptState_S.icount  = 0u;
                vHsmCrypt_EncryptJob_Error = FALSE;
            }
        }
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_SymBlockEncryptCallback(Crypto_SymBlockEncryptNotif_S.callbackParamValue);
    return fl_ret_E;
}

/*---[Crypto_She_SymBlockEncryptUpdate]------------------------------------------*/

/* !LINKSTO CRYSHE_86, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptUpdate
        (
                P2CONST(uint8,AUTOMATIC,CRY_APPL_DATA) plainTextPtr,
                uint32 plainTextLength,
                P2VAR(uint8,AUTOMATIC,CRY_APPL_DATA) cipherTextPtr,
                P2VAR(uint32,AUTOMATIC,CRY_APPL_DATA) cipherTextLengthPtr
        )
{
	//CRYPTO_LOCK_SEM();
    Csm_ReturnType ret = CSM_E_OK;
    if ((cipherTextPtr == NULL) || (plainTextPtr == NULL) || (cipherTextLengthPtr == NULL))
    {
        ret = CSM_E_NOT_OK;
        Crypto_SymBlockEncryptCancel();
    }
    if(( Crypto_SymBlockEncryptState_S.state == Crypto_Idle ) ||
        ( Crypto_SymBlockEncryptState_S.state == Crypto_Cancel) ||
        ( Crypto_SymBlockEncryptState_S.state == Crypto_Finish) ||
        ( Crypto_SymBlockEncryptState_S.state == Crypto_Finish_Wait))
    {
        ret = CSM_E_NOT_OK;
    }
    if (CSM_E_OK == ret)
    {
        if
        (
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update ) &&
                ( Crypto_SymBlockEncryptState_S.work == CRYPTO_SYMBLOCKENCRYPT_WAIT )
        )
        {
            /* Check if the input and output buffers are valid. */
            if ( ((plainTextLength % CRYPTO_HSM_BLOCK_LENGTH    ) == 0U             ) &&
                    (*cipherTextLengthPtr                      >= plainTextLength)
            )
            {
                Crypto_SymBlockEncryptState_S.iputPtr     = plainTextPtr;
                Crypto_SymBlockEncryptState_S.iputLen     = plainTextLength;
                Crypto_SymBlockEncryptState_S.oputPtr     = cipherTextPtr;
                Crypto_SymBlockEncryptState_S.oputLenPtr  = cipherTextLengthPtr;
                Crypto_SymBlockEncryptState_S.work        = CRYPTO_SYMBLOCKENCRYPT_WORK;
                Crypto_SymBlockEncryptState_S.icount      += plainTextLength;
                Crypto_SymBlockEncryptState_S.ocount      = 0U;
                vHsmCrypt_EncryptJob_Error = FALSE;
            }
            else
            {
                if ( *cipherTextLengthPtr < plainTextLength)
                {
                    /* !LINKSTO CSM0663, 1
                     */
                    ret = CSM_E_SMALL_BUFFER;
                }
                else
                {
                    ret = CSM_E_NOT_OK;
                }
                Crypto_SymBlockEncryptCancel();
            }
        }
        else if
        (
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Start_Wait ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update_Wait ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Start )
        )
        {
            ret = CSM_E_BUSY;
        }
        else
        {
            ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
            if( Crypto_SymBlockEncryptState_S.state != Crypto_Cancel)
            {
                Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
            }
            else
            {
                Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Idle;
            }
    #else
            Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    //CRYPTO_RELEASE_SEM();

    return ret;
}

/*---[Crypto_She_SymBlockEncryptFinish]------------------------------------------*/

/* !LINKSTO CRYSHE_95, 1
 */
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SymBlockEncryptFinish
        (
                void
        )
{
    Csm_ReturnType ret;

    //CRYPTO_LOCK_SEM();
    if (( Crypto_SymBlockEncryptState_S.state == Crypto_Idle ) ||
        ( Crypto_SymBlockEncryptState_S.state == Crypto_Cancel) ||
        ( Crypto_SymBlockEncryptState_S.state == Crypto_Finish_Wait))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if
        (
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update ) &&
                ( Crypto_SymBlockEncryptState_S.work == CRYPTO_SYMBLOCKENCRYPT_WAIT )
        )
        {
            Crypto_SymBlockEncryptState_S.state = Crypto_Finish;
            vHsmCrypt_EncryptJob_Error = FALSE;
            ret = CSM_E_OK;
        }
        else if
        (
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Start_Wait ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Update_Wait ) ||
                ( Crypto_SymBlockEncryptState_S.state == Crypto_Start )
        )
        {
            ret = CSM_E_BUSY;
        }
        else
        {
            ret = CSM_E_NOT_OK;
    #if (CRYPTO_CANCEL_CALLBACK_USED == 1)
                    if( Crypto_SymBlockEncryptState_S.state != Crypto_Cancel)
                    {
                        Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                    }
                    else
                    {
                        Crypto_SymBlockEncryptState_S.stateRequested = Crypto_Idle;
                    }
    #else
                    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
    #endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
            Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    //CRYPTO_RELEASE_SEM();

    return ret;
}
/*---[Crypto_She_SymBlockEncryptMainFunction]------------------------------------*/

/* !LINKSTO CRYSHE_100, 1
 */
FUNC(void,CRY_CODE) Crypto_She_SymBlockEncryptMainFunction
        (
                void
        )
{
    //CRYPTO_LOCK_SEM();
    Crypto_SymBlockEncryptNotif_S.callbackNeeded = FALSE;
    Crypto_SymBlockEncryptNotif_S.finishNeeded = FALSE;
    switch (Crypto_SymBlockEncryptState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_SymBlockEncryptState_S.stateRequested)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /*#if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:
            Crypto_SymBlockEncryptState_S.LockedHsm_E = Crypto_LockShe();

            /* !LINKSTO CRYSHE_25, 1
             */
            if (Crypto_SymBlockEncryptState_S.LockedHsm_E == TRUE)
            {
                Crypto_CryptECBPackedData_S.KeyId_U8 =
                        Crypto_SymBlockEncryptState_S.keyInfo.keyId;
                Crypto_CryptECBPackedData_S.jobId_E = CID_49_SYM_BLOCK_ENCRYPT_START;
                Crypto_CryptECBPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_CryptECBPackedData_S.payLoadPtr_U8P =
                        NULL;
                Crypto_CryptECBPackedData_S.payLoadSize = 0u;
                vHsmCrypt_EncryptJob_Completed = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_CryptECBPackedData_S))
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Start_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_SymBlockEncryptActionOnFault();
                }
            }
            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_EncryptJob_Completed)
            {
                if(FALSE == vHsmCrypt_EncryptJob_Error)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Update;
                    Crypto_SymBlockEncryptState_S.work  = CRYPTO_SYMBLOCKENCRYPT_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                    Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymBlockEncryptActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                   * if no response for 1sec, then, reset everything*/
                  if (TRUE == Crypto_CheckFaultPeriodic())
                  {
                      Crypto_SymBlockEncryptActionOnFault();
                  }
                  else
                  {
                      /* Wait for the fault counter to expire to reset all
                       * which is handled in the above if condition */
                  }
            }
            break;
        case Crypto_Update:
            if ( Crypto_SymBlockEncryptState_S.work == CRYPTO_SYMBLOCKENCRYPT_WORK )
            {
                /* There is still data left to encrypt. */
                Crypto_SymBlockEncryptFillInputFifo();
            }
            break;
        case Crypto_Update_Wait:
            if (TRUE == vHsmCrypt_EncryptJob_Completed)
            {
                if(FALSE == vHsmCrypt_EncryptJob_Error)
                {
                    Crypto_SymBlockEncryptState_S.state = Crypto_Update;
                    Crypto_SymBlockEncryptState_S.work  = CRYPTO_SYMBLOCKENCRYPT_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                    Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymBlockEncryptActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_SymBlockEncryptActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
                if(FALSE != Crypto_SymBlockEncryptState_S.Directcall)
                {
                    if(FALSE != Crypto_SymBlockEncryptState_S.LockedHsm_E)
                    {
                        if(INT16_MAX_RANGE >= Crypto_SymBlockEncryptState_S.keyInfo.keyId)
                        {
                            Crypto_CryptECBPackedData_S.KeyId_U8 =
                                    (uint8)Crypto_SymBlockEncryptState_S.keyInfo.keyId;
                            Crypto_CryptECBPackedData_S.jobId_E = CID_48_SYM_BLOCK_ENCRYPT_FN;
                            Crypto_CryptECBPackedData_S.priority_U8 = (te_jobpriority)0;
                            Crypto_CryptECBPackedData_S.payLoadPtr_U8P = 
                                    (uint8 *)&Crypto_SymBlockEncryptState_S.buffer[0];
                            Crypto_CryptECBPackedData_S.payLoadSize = Crypto_SymBlockEncryptState_S.len; 
                            vHsmCrypt_EncryptJob_Completed = FALSE;
                            if(E_OK ==  Crypto_SendPackedData(Crypto_CryptECBPackedData_S))
                            {
                                Crypto_SymBlockEncryptState_S.state = Crypto_Finish_Wait;
                                Crypto_ResetFaultCounter();
                            }
                            else
                            {
                                Crypto_SymBlockEncryptActionOnFault();
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
                    Crypto_CryptECBPackedData_S.KeyId_U8 = 
			                Crypto_SymBlockEncryptState_S.keyInfo.keyId;
                    Crypto_CryptECBPackedData_S.jobId_E = CID_47_SYM_BLOCK_ENCRYPT_FINISH;
                    Crypto_CryptECBPackedData_S.priority_U8 = (te_jobpriority)0;
                    Crypto_CryptECBPackedData_S.payLoadPtr_U8P = NULL;
                    Crypto_CryptECBPackedData_S.payLoadSize = 0; /* no payload */
                    vHsmCrypt_EncryptJob_Completed = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_CryptECBPackedData_S))
                    {
                        Crypto_SymBlockEncryptState_S.state = Crypto_Finish_Wait;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_SymBlockEncryptActionOnFault();
                    }
                }
            break;
        case Crypto_Finish_Wait:
            if(TRUE == vHsmCrypt_EncryptJob_Completed)
            {
                Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
                Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                Crypto_SymBlockEncryptNotif_S.finishNeeded = TRUE;

                if(FALSE == vHsmCrypt_EncryptJob_Error)
                {
                    Crypto_SymBlockEncryptState_S.work  = CRYPTO_SYMBLOCKENCRYPT_WAIT;
                    Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
                    Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                }
                Crypto_SymBlockEncryptState_S.LockedHsm_E = FALSE;
                CRYPTO_RELEASE_HSM();
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_CheckFaultPeriodic())
                {
                    Crypto_SymBlockEncryptActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        default:
            Crypto_SymBlockEncryptActionOnFault();
            break;
    }
    //CRYPTO_RELEASE_SEM();
    Crypto_SymBlockEncryptCallback(Crypto_SymBlockEncryptNotif_S.callbackParamValue);
}

FUNC(void, CRY_CODE) Crypto_She_ECBEncryptCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint32 res_length;
    uint8 status = *p_resultBytesInSRAM_U8P;
    if (Crypto_SymBlockEncryptState_S.LockedHsm_E == TRUE)
    {
        switch (Crypto_SymBlockEncryptState_S.state)
        {
            case Crypto_Start_Wait:
                vHsmCrypt_EncryptJob_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_EncryptJob_Error = TRUE;
                }
                break;
            case Crypto_Update_Wait:
                res_length= payload_size - 1;
                Crypto_SymBlockEncryptState_S.ocount += res_length;
                vHsmCrypt_EncryptJob_Completed = TRUE;
                if(Crypto_SymBlockEncryptState_S.oputLenPtr != NULL)
                {
                    if(((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                       (Crypto_SymBlockEncryptState_S.icount == res_length))
                    {
                        /* Copy the result data into the memory
                           location shared from application */
                        (void)memcpy((uint8 *)Crypto_SymBlockEncryptState_S.oputPtr,
                                (uint8 *)&p_resultBytesInSRAM_U8P[1],
                                (uint16)res_length);
                    }
                    else
                    {
                        vHsmCrypt_EncryptJob_Error = TRUE;
                    }
                }
                else
                {
                    vHsmCrypt_EncryptJob_Error = TRUE;
                }
                break;
            case Crypto_Finish_Wait:
            
                res_length= (uint32)payload_size - (uint32)1;
                vHsmCrypt_EncryptJob_Completed = TRUE;
                if(NULL != Crypto_SymBlockEncryptState_S.oputPtr)
                {
                    if(((uint8)CRYPTO_JOB_DONE == status) && /* 1 byte status */
                       (Crypto_SymBlockEncryptState_S.icount == res_length))
                    {
                            /* Copy the result data into the memory
                        location shared from application */
                            (void)memcpy((uint8 *)Crypto_SymBlockEncryptState_S.oputPtr,
                                    (uint8 *)&p_resultBytesInSRAM_U8P[1],
                                    (uint16)res_length);
                    }
                    else
                    {
                        vHsmCrypt_EncryptJob_Error = TRUE;
                    }
                }
                else
                {
                    vHsmCrypt_EncryptJob_Error = TRUE;
                }
                break;
            default:
                vHsmCrypt_EncryptJob_Error = TRUE;
                break;
        }
    }
}

/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptFillInputFifo(void)
{
    Std_ReturnType fl_retVal;

    /* If the RAM key is used, check whether the correct key is loaded
     * into the SHE.
     */
    /* !LINKSTO CRYSHE_41, 1
     */
    if
    (
            (Crypto_SymBlockEncryptState_S.keyInfo.keyId == CRYPTO_SHE_RAM_KEY         ) &&
            (Crypto_SymBlockEncryptState_S.keyInfo.keyNr != Crypto_SymKeyInfo.keyNr)
    )
    {
        Crypto_SymBlockEncryptActionOnFault();
    }
    else
    {
        Crypto_CryptECBPackedData_S.KeyId_U8 = 
                Crypto_SymBlockEncryptState_S.keyInfo.keyId;
        Crypto_CryptECBPackedData_S.jobId_E = CID_50_SYM_BLOCK_ENCRYPT_UPDATE;
        Crypto_CryptECBPackedData_S.payLoadPtr_U8P = (uint8 *)Crypto_SymBlockEncryptState_S.iputPtr;
        Crypto_CryptECBPackedData_S.payLoadSize = Crypto_SymBlockEncryptState_S.iputLen;
        Crypto_CryptECBPackedData_S.priority_U8 = (te_jobpriority)0;
        vHsmCrypt_EncryptJob_Completed = FALSE;
        fl_retVal = Crypto_SendPackedData(Crypto_CryptECBPackedData_S);
        if (E_OK == fl_retVal)
        {
            Crypto_SymBlockEncryptState_S.state = Crypto_Update_Wait;
            Crypto_ResetFaultCounter();
        }
        else
        {
            Crypto_SymBlockEncryptActionOnFault();
        }
    }
}

FUNC(void, CRY_CODE) Crypto_SymBlockEncryptCancel(void)
{
    Crypto_SymBlockEncryptState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_SymBlockEncryptState_S.state = Crypto_Cancel;
#else
    Crypto_SymBlockEncryptState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_SymBlockEncryptState_S.LockedHsm_E == TRUE)
    {
        Crypto_SymBlockEncryptState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }
    (void)Crypto_She_Cancel(e_aesecbencrypt);
}

STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_SymBlockEncryptNotif_S.callbackNeeded)
    {
        Crypto_SymBlockEncryptNotif_S.callbackNeeded = FALSE;
        CRYPTO_CSM_SYMBLOCKENCRYPT_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_SymBlockEncryptNotif_S.finishNeeded)
    {
        Crypto_SymBlockEncryptNotif_S.finishNeeded = FALSE;
        //CRYPTO_CSM_SYMBLOCKENCRYPT_SERVICE_FINISH_NOTIF();
    }
}

STATIC FUNC(void, CRY_CODE) Crypto_SymBlockEncryptActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 1sec */
    if(Crypto_SymBlockEncryptState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_SymBlockEncryptState_S.faultLog_U8++;
    }
    Crypto_SymBlockEncryptNotif_S.callbackNeeded = TRUE;
    Crypto_SymBlockEncryptNotif_S.finishNeeded = TRUE;
    Crypto_SymBlockEncryptNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    Crypto_SymBlockEncryptCancel();
    Crypto_ResetFaultCounter();
}
void Csm_SymBlockEncryptCallbackNotification(Csm_ReturnType result)
{

}
#endif /* CRYPTO_ECBENCRYPT_ENABLED */

