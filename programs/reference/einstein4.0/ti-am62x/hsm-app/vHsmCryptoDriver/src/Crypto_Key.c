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
 * \file Crypto_key.c
 *
 * \brief
 * Key implementation source file in M7
 *
 * \detailed description
 *  This file shall be the key implementation in M7 sending
 *  command and data to M0P and receiving back data from M0P
 *  Reference is taken from MP21
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 28/Apr/'21 | bjayara2 | 1321475 |ECDSA verify for FDS                   |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/*==[Includes]================================================================*/
#include "Crypto_She.h"
#include "Crypto_Key.h"
#include "Crypto_SymKeyInfo.h"
#include "string.h"
#include "vHsmCryptoManager.h"
#include "Crypto.h"
#include "stub.h"
/*==[Macros]==================================================================*/

/* Fault counter max value arrived by dividing the max timeout of 2000ms
 * by the scheduling rate - 10ms, 2000ms/10ms = 200 */
 /* quasi-sync usage is there for ECDSA key, so, made it to 30000*/
#define KEY_FAULT_COUNTER_MAX_VAL      ((uint32)50000)

#define SIZE_OF_KEY_64                             ((uint32)64)

#define SIZE_OF_KEY_16                              ((uint32)16)
#define SIZE_OF_KEY_32                              ((uint32)32)

#define KEY_ELEMENT_MASK                             ((uint8)3)

#define SAFE_KEY_NO_ID 7

#define ASYM_KEY_NO_ID 2

/*==[Types]===================================================================*/

typedef enum
{
    CRYPTO_HSM_RSAVER_WORK, /* HSM is working on the update provided from CSM,
                               Pack the data to crypto manager and send through IPC
                               to HSM in M0P */
    CRYPTO_HSM_RSAVER_WAIT  /* HSM is waiting on the data from CSM */
}
Crypto_Hsm_RsaVerWorkType ;

typedef struct
{
        uint8 keyInfo;
        Crypto_Hsm_RsaVerWorkType work;
        uint16  len;
        uint8 buffer[512];
        uint32 startAdd_U32;
        uint32 size_U32;
        uint32 signStartAdd_U32;
        uint32 sizeOfSign_U32;
        Crypto_StateType  state;
        Crypto_StateType  stateRequested;
        uint8   priority;
        uint16   faultLog_U8;
        uint8 * result_U8P;
		uint8 *KeyPtr;
        boolean LockedHsm_E;
}
Crypto_Hsm_KeyStateType;

/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_keyCancel
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_keyCancel(void);

/**
 *********************************************************************************************
 ** \fn Crypto_keyActionOnFault
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
STATIC FUNC(void, CRY_CODE) Crypto_keyActionOnFault(void);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_key_CheckFaultPeriodic
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
STATIC FUNC(boolean, CRY_CODE) Crypto_Hsm_key_CheckFaultPeriodic(void );

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_keyCallback
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
STATIC FUNC(void, CRY_CODE) Crypto_Hsm_keyCallback(Csm_ReturnType param);


/*==[Variables with internal linkage]=========================================*/

STATIC VAR(Crypto_Hsm_KeyStateType, CRY_VAR) Crypto_keyState_S;

STATIC VAR(Crypto_NotifType, CRY_VAR) Crypto_keyNotif_S;

STATIC VAR(ts_vHsm_Cryptodata, CRY_VAR) Crypto_Hsm_keyPackedData_S;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_key_Completed;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_key_error;

STATIC VAR(boolean, CRY_VAR) vHsmCrypt_key_not_present;

STATIC VAR(uint8, CRY_VAR) l_KeyArray_U8A[64];

STATIC VAR(uint8, CRY_VAR) l_AsymKeyArray_U8A[144];

STATIC VAR(uint32, CRY_VAR) l_AsymKeyLength_U32 = 0u;

STATIC VAR(uint8, CRY_VAR) l_VerifyKeyArray_U8A[40];
//STATIC VAR(uint8, CRY_VAR) l_Keylength[16];
STATIC VAR(uint8, CRY_VAR) length;

STATIC VAR(uint8, CRY_VAR) l_Getkey_KeyArray_U8A[10] = {0};

STATIC VAR(uint8, CRY_VAR) l_keyValSet_U8;

STATIC VAR(uint8, CRY_VAR) l_KEY_ID_U8;

STATIC VAR(uint32, CRY_VAR) l_keyFaultCounter_U32;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/
FUNC(void, CRY_CODE) Crypto_she_keyInit(void)
{
    Crypto_keyState_S.state = Crypto_Idle;
    Crypto_keyState_S.stateRequested = Crypto_Idle;

    Crypto_keyState_S.LockedHsm_E = FALSE;
    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
    Crypto_keyState_S.work = CRYPTO_HSM_RSAVER_WORK;
    vHsmCrypt_key_Completed = FALSE;
    vHsmCrypt_key_error = FALSE;
    l_keyFaultCounter_U32 = 0u;
    vHsmCrypt_key_not_present =FALSE;
}

/*---[Crypto_She_SetKey]---------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_SetKey
        (
                uint32 keyId, uint32 keyElementId, 
                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)keyPtr,
                uint32 keyLength
        )
{
    //CRYPTO_LOCK_SEM();
    l_keyValSet_U8 = 0u;
    l_KEY_ID_U8 = crypto_Key[keyId].RefOfKey;
    Csm_ReturnType ret = CSM_E_OK;
    if ((keyPtr == NULL) || ((keyLength != SIZE_OF_KEY_64) && (keyLength != SIZE_OF_KEY_16 ) && (keyLength != SIZE_OF_KEY_32)))
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if(( Crypto_keyState_S.state != Crypto_Idle ) ||
            (Crypto_keyState_S.LockedHsm_E != FALSE))
        {
            ret = CSM_E_NOT_OK;
        }
        else
        {
            Crypto_keyState_S.LockedHsm_E = TRUE;
			if( l_KEY_ID_U8 == ASYM_KEY_NO_ID)
			{
				(void)memcpy(&l_AsymKeyArray_U8A[0],keyPtr,keyLength);
                l_AsymKeyLength_U32 = keyLength;
			}
			else
			{	
              (void)memcpy(&l_KeyArray_U8A[0],keyPtr,keyLength);
			}  
            //l_Keylength[keyLength];
            length=keyLength;
            Crypto_keyState_S.state = Crypto_KeySet;
            l_keyValSet_U8 = KEY_ELEMENT_MASK;
        }
    }

    //CRYPTO_RELEASE_SEM();
    return ret;
}

/*---[Cry_SetKeyValid]---------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_KeysetValid
        (
            uint32 keyId
        )
{
    Csm_ReturnType ret = CSM_E_OK;
    if (l_keyValSet_U8 != KEY_ELEMENT_MASK)
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if( Crypto_keyState_S.state != Crypto_KeySet )
        {
            ret = CSM_E_NOT_OK;
        }
        else
        {
            if(keyId == ASYM_KEY_NO_ID)
            {
                ret = CSM_E_OK;
            }
            else
            {
                Crypto_keyState_S.work = CRYPTO_HSM_RSAVER_WORK;
                Crypto_keyState_S.state = Crypto_KeySetConfirm;
                vHsmCrypt_key_Completed = FALSE;
                l_keyFaultCounter_U32 = 0u;
                vHsmCrypt_key_error = FALSE;
                while (FALSE == vHsmCrypt_key_Completed)
                {
                    if(FALSE != vHsmCrypt_key_error)
                    {
                        ret = CSM_E_NOT_OK;                    
                        break;
                    }
                    else
                    { 
                        Crypto_She_keyMainFunction();
                        vHsmIpc_HostManager_PeriodicCheck();  
                    }

                }
                Crypto_She_keyMainFunction();
                Crypto_keyState_S.LockedHsm_E = FALSE;
                Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
            }
            Crypto_keyState_S.state = Crypto_Idle;
            Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
        }
    }
    return ret;
}

/*---[Cry_GetKey]---------------------------------------------*/

FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_GetKey
(
    uint32 keyId, uint32 keyElementId, uint8 * keyPtr, uint32 * keyLengthPtr
)
{
    Csm_ReturnType ret = CSM_E_OK;
    if ((keyPtr == NULL) || (*(keyLengthPtr) ==0))
    {
        ret = CSM_E_NOT_OK;
    }
    else if(( Crypto_keyState_S.state != Crypto_Idle ) || (Crypto_keyState_S.LockedHsm_E != FALSE))
    {
    
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if((keyId == ASYM_KEY_NO_ID) && (keyElementId == 0u))
        {
            if(*keyLengthPtr >= l_AsymKeyLength_U32)
            {
                (void)memcpy(keyPtr,&l_AsymKeyArray_U8A[0],l_AsymKeyLength_U32);
            }
            else
            {
                ret = CSM_E_NOT_OK;
            }
        }
        else
        {
            Crypto_keyState_S.state  = Crypto_GetKey;
            Crypto_keyState_S.KeyPtr = keyPtr;
            l_Getkey_KeyArray_U8A[0] =(uint8) (keyId);
            l_Getkey_KeyArray_U8A[1] =(uint8) (keyId >> 8);
            l_Getkey_KeyArray_U8A[2] =(uint8) (keyElementId);
            l_Getkey_KeyArray_U8A[3] =(uint8) (keyElementId >> 8);
            l_Getkey_KeyArray_U8A[4] =(uint8) (keyElementId>>16);
            l_Getkey_KeyArray_U8A[5] =(uint8) (keyElementId >> 24);
            (void)memcpy(&l_Getkey_KeyArray_U8A[6],keyLengthPtr,4);
            vHsmCrypt_key_Completed = FALSE;
            l_keyFaultCounter_U32 = 0u;
            vHsmCrypt_key_not_present =FALSE;

            while (FALSE == vHsmCrypt_key_Completed)
            {
                if(FALSE != vHsmCrypt_key_not_present)
                {
                    ret = CSM_E_KEY_NOT_AVAILABLE;                    
                    break;
                }
                else
                { 
                Crypto_She_keyMainFunction();
                vHsmIpc_HostManager_PeriodicCheck();
                }
            }  
            Crypto_She_keyMainFunction();

            if(TRUE == vHsmCrypt_key_not_present)
            {
                ret = CSM_E_KEY_NOT_AVAILABLE;
                vHsmCrypt_key_not_present = FALSE;
            }
        }
    }
    Crypto_keyState_S.LockedHsm_E = FALSE;
    Crypto_keyState_S.state = Crypto_Idle;
    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WORK;
    return ret;
}

/*---[Key_Verify]---------------------------------------------*/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_KeyVerify
        (
                 uint32 keyId, P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR)payload_ptr,
                uint32 payload_size
        )
{
   // //CRYPTO_LOCK_SEM();
    l_keyValSet_U8 = 0u;
    l_KEY_ID_U8 = keyId;
   
    Csm_ReturnType ret = CSM_E_OK;
    if (payload_ptr == NULL)
    {
        ret = CSM_E_NOT_OK;
    }
    else
    {
        if(( Crypto_keyState_S.state != Crypto_Idle ) ||
            (Crypto_keyState_S.LockedHsm_E != FALSE))
        {
            ret = CSM_E_NOT_OK;
        }
        else
        {
            Crypto_keyState_S.LockedHsm_E = TRUE;
			l_VerifyKeyArray_U8A[0] = keyId;
            (void)memcpy(&l_VerifyKeyArray_U8A[1],payload_ptr,payload_size);
            Crypto_keyState_S.state = Crypto_VerifyKey;
           	vHsmCrypt_key_Completed = FALSE;
            l_keyFaultCounter_U32 = 0u;
            vHsmCrypt_key_not_present =FALSE;
			while (FALSE == vHsmCrypt_key_Completed)
            {
				if(FALSE != vHsmCrypt_key_not_present)
				{
					ret = CSM_E_KEY_NOT_AVAILABLE;                    
					break;
				}
				else
				{ 
				   Crypto_She_keyMainFunction();
				   vHsmIpc_HostManager_PeriodicCheck();
				}
            }  
			Crypto_She_keyMainFunction();

			if(TRUE == vHsmCrypt_key_not_present)
			{
				ret = CSM_E_KEY_NOT_AVAILABLE;
				vHsmCrypt_key_not_present = FALSE;
			}
        }
    }
    Crypto_keyState_S.LockedHsm_E = FALSE;
    Crypto_keyState_S.state = Crypto_Idle;
    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WORK;
   // //CRYPTO_RELEASE_SEM();
    return ret;
}

Std_ReturnType Crypto_KeyExchangeCalcPubVal(uint32 cryptoKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyElementCopy(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyExchangeCalcSecret(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr,  uint32 partnerPublicValueLength)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType, CRY_CODE) Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType,CRY_CODE) Crypto_KeyGenerate(uint32 cryptoKeyId)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType,CRY_CODE) Crypto_CertificateVerify(uint32 cryptoKeyId,uint32 verifyCryptoKeyId,uint8 * verifyPtr)
{
    return E_NOT_OK;
}
FUNC(Std_ReturnType,CRY_CODE) Crypto_CertiParse(uint32 cryptoKeyId)
{
    return E_NOT_OK;
}

FUNC(void,CRY_CODE) Crypto_She_keyMainFunction(void)
{
    Crypto_keyNotif_S.callbackNeeded = FALSE;
    Crypto_keyNotif_S.finishNeeded = FALSE;
    switch (Crypto_keyState_S.state)
    {
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
        case Crypto_Hsm_Cancel:
            if (TRUE == Crypto_She_GetCancelIsComplete())
            {
                if(Crypto_Start == Crypto_keyState_S.stateRequested)
                {
                    Crypto_keyState_S.state = Crypto_Start;
                }
                else
                {
                    Crypto_keyState_S.state = Crypto_Idle;
                }
            }
            else
            {
                /* Keep waiting for callback from M0P*/
            }
            break;
#endif /*#if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
        case Crypto_Start:

                Crypto_Hsm_keyPackedData_S.KeyId_U8 =
                        Crypto_keyState_S.keyInfo;
             //   Crypto_Hsm_keyPackedData_S.jobId_E = CID_71_ECDSA_VERIFY_START;
                Crypto_Hsm_keyPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_keyPackedData_S.payLoadPtr_U8P = NULL;
                Crypto_Hsm_keyPackedData_S.payLoadSize = 0u;
                vHsmCrypt_key_Completed = FALSE;
                vHsmCrypt_key_error = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_keyPackedData_S))
                {
                    Crypto_keyState_S.state = Crypto_Start_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_keyActionOnFault();
                }

            break;
        case Crypto_Start_Wait:
            if(TRUE == vHsmCrypt_key_Completed)
            {
                if(FALSE == vHsmCrypt_key_error)
                {
                    Crypto_keyState_S.state = Crypto_Finish;
                    Crypto_keyState_S.work = CRYPTO_HSM_RSAVER_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_keyActionOnFault();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_Hsm_key_CheckFaultPeriodic())
                {
                    Crypto_keyActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_Finish:
            if(Crypto_keyState_S.LockedHsm_E == FALSE)
            {
                Crypto_keyState_S.LockedHsm_E = Crypto_LockShe();
            }
            else
            {
                /* Acquired lock of HSM */        
                if( CRYPTO_HSM_RSAVER_WORK == Crypto_keyState_S.work)
                {
                    /* Acquired lock of HSM */
                    Crypto_Hsm_keyPackedData_S.KeyId_U8 =
                            Crypto_keyState_S.keyInfo;
                  //  Crypto_Hsm_keyPackedData_S.jobId_E = CID_69_ECDSA_VERIFY_FINISH;
                    Crypto_Hsm_keyPackedData_S.priority_U8 = (te_jobpriority)0;
                    Crypto_Hsm_keyPackedData_S.payLoadPtr_U8P = (uint8 *)&Crypto_keyState_S.buffer[0];
                    Crypto_Hsm_keyPackedData_S.payLoadSize = Crypto_keyState_S.len;
                    vHsmCrypt_key_Completed = FALSE;
                    vHsmCrypt_key_error = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_keyPackedData_S))
                    {
                        Crypto_keyState_S.state = Crypto_Finish_Wait;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_keyActionOnFault();
                    }
                }
            }
            break;
        case Crypto_Finish_Wait:
            if (TRUE == vHsmCrypt_key_Completed)
            {
                if(FALSE == vHsmCrypt_key_error)
                {

                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;

                    Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                    Crypto_keyNotif_S.finishNeeded = TRUE;
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_Hsm_key_CheckFaultPeriodic())
                {
                    Crypto_keyActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break;
        case Crypto_KeySetConfirm:
            if( CRYPTO_HSM_RSAVER_WORK == Crypto_keyState_S.work)
            {
                /* Acquired lock of HSM */
                Crypto_Hsm_keyPackedData_S.KeyId_U8 = l_KEY_ID_U8;
				Crypto_Hsm_keyPackedData_S.jobId_E = CID_69_KEYSSETKEY_FN;
                Crypto_Hsm_keyPackedData_S.priority_U8 = (te_jobpriority)0;
                Crypto_Hsm_keyPackedData_S.payLoadPtr_U8P = (uint8 *)&l_KeyArray_U8A[0];
                if((length==16u)||(length==32u))
                {
					if( l_KEY_ID_U8 == SAFE_KEY_NO_ID)
					{
						Crypto_Hsm_keyPackedData_S.payLoadSize = length + 2UL;
					}						
					else
					{						
                        Crypto_Hsm_keyPackedData_S.payLoadSize = length;  //sizeof(l_Keylength); 
					}
                }
                else
                {
                  Crypto_Hsm_keyPackedData_S.payLoadSize = sizeof(l_KeyArray_U8A); 
                }
                vHsmCrypt_key_Completed = FALSE;
                vHsmCrypt_key_error = FALSE;
                if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_keyPackedData_S))
                {
                    Crypto_keyState_S.state = Crypto_KeySetConfirm_Wait;
                    Crypto_ResetFaultCounter();
                }
                else
                {
                    Crypto_keyActionOnFault();
                }
            }
            break;
        case Crypto_KeySetConfirm_Wait:
            if (TRUE == vHsmCrypt_key_Completed)
            {
                if(FALSE == vHsmCrypt_key_error)
                {
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                    Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                }
                else
                {
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;

                    Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
                    Crypto_keyNotif_S.finishNeeded = TRUE;
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                }
               
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                if (TRUE == Crypto_Hsm_key_CheckFaultPeriodic())
                {
                    Crypto_keyActionOnFault();
                    vHsmCrypt_key_error = TRUE;
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
            }
            break; 

         case Crypto_GetKey:
                if (Crypto_keyState_S.LockedHsm_E == FALSE)
                {
                    Crypto_keyState_S.LockedHsm_E = Crypto_LockShe();
                }
                else
                {
					
                   // Crypto_Hsm_keyPackedData_S.jobId_E = CID_108_GETKEY_FN;
                    Crypto_Hsm_keyPackedData_S.priority_U8         = (te_jobpriority)0;
                    Crypto_Hsm_keyPackedData_S.payLoadPtr_U8P      = (uint8 *)&l_Getkey_KeyArray_U8A[0];
                    Crypto_Hsm_keyPackedData_S.payLoadSize         = sizeof(l_Getkey_KeyArray_U8A);
                    vHsmCrypt_key_Completed = FALSE;
                    vHsmCrypt_key_error = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_keyPackedData_S))
                    {
                        Crypto_keyState_S.state = Crypto_GetKey_Wait;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_keyActionOnFault();
                    }
                }   
            break; 
    case Crypto_GetKey_Wait:
            if(TRUE == vHsmCrypt_key_Completed)
            {
                 if(FALSE == vHsmCrypt_key_not_present)
                {
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                   /* Crypto_keyNotif_S.callbackNeeded = FALSE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                    Crypto_keyNotif_S.finishNeeded = TRUE;*/
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                }
                else
                {
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
                   /* Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_KEY_NOT_AVAILABLE;
                    Crypto_keyNotif_S.finishNeeded = FALSE;*/
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                #if 0
                if (TRUE == Crypto_Hsm_key_CheckFaultPeriodic())
                {
                    Crypto_Hsm_key_ActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
                #endif
            }
            break;                             
    case Crypto_VerifyKey:
            if (Crypto_keyState_S.LockedHsm_E == FALSE)
                {
                    Crypto_keyState_S.LockedHsm_E = Crypto_LockShe();
                }
                else
                {
                    Crypto_Hsm_keyPackedData_S.KeyId_U8 = l_KEY_ID_U8;
                  //  Crypto_Hsm_keyPackedData_S.jobId_E = CID_113_VERIFY_KEY_FN;
                    Crypto_Hsm_keyPackedData_S.priority_U8         = (te_jobpriority)0;
                    Crypto_Hsm_keyPackedData_S.payLoadPtr_U8P      = (uint8 *)&l_VerifyKeyArray_U8A[0];
                    Crypto_Hsm_keyPackedData_S.payLoadSize        = sizeof(l_VerifyKeyArray_U8A);
                    vHsmCrypt_key_Completed = FALSE;
                    vHsmCrypt_key_error = FALSE;
                    if(E_OK ==  Crypto_SendPackedData(Crypto_Hsm_keyPackedData_S))
                    {
                       Crypto_keyState_S.state = Crypto_VerifyKey_Wait;
                        Crypto_ResetFaultCounter();
                    }
                    else
                    {
                        Crypto_keyActionOnFault();
                    }
                }   
            break;
	 case Crypto_VerifyKey_Wait:
            if(TRUE == vHsmCrypt_key_Completed)
            {
                 if(FALSE == vHsmCrypt_key_not_present)
                {
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
                    /* !LINKSTO CRYSHE_290_3, 1
                     */
                  /*  Crypto_keyNotif_S.callbackNeeded = FALSE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_OK;
                    Crypto_keyNotif_S.finishNeeded = TRUE;*/
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                }
                else
                {
                    Crypto_keyState_S.state = Crypto_Idle;
                    Crypto_keyState_S.work  = CRYPTO_HSM_RSAVER_WAIT;
                    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
                  /*  Crypto_keyNotif_S.callbackNeeded = TRUE;
                    Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_KEY_NOT_AVAILABLE;
                    Crypto_keyNotif_S.finishNeeded = FALSE;*/
                    Crypto_keyState_S.LockedHsm_E = FALSE;
                    CRYPTO_RELEASE_HSM();
                }
            }
            else
            {
                /* Keep waiting for callback from M0P
                 * if no response for 1sec, then, reset everything*/
                #if 0
                if (TRUE == Crypto_Hsm_key_CheckFaultPeriodic())
                {
                    Crypto_Hsm_key_ActionOnFault();
                }
                else
                {
                    /* Wait for the fault counter to expire to reset all
                     * which is handled in the above if condition */
                }
                #endif
            }
            break;			
        default:
            break;
    }

    Crypto_Hsm_keyCallback(Crypto_keyNotif_S.callbackParamValue);
}
__attribute__((used)) void Crypto_she_keyCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size)
{
    uint8 status = *p_resultBytesInSRAM_U8P;
        switch (Crypto_keyState_S.state)
        {
            case Crypto_Start_Wait:
                vHsmCrypt_key_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_key_error = TRUE;
                }
                break;
            case Crypto_Finish_Wait:
                vHsmCrypt_key_Completed = TRUE;
                if(((uint8)2 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Copy the result data into the memory
                     location shared from application */
                    (void)memcpy((uint8 *)Crypto_keyState_S.result_U8P,
                            (uint8 *)&p_resultBytesInSRAM_U8P[1],
                            (uint16)1);
                }
                else
                {
                    vHsmCrypt_key_error = TRUE;
                }
                break;
            case Crypto_KeySetConfirm_Wait:
                vHsmCrypt_key_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_key_error = TRUE;
                }
                break;
            case Crypto_GetKey_Wait:
                 vHsmCrypt_key_Completed = TRUE;
                if((((uint8)18 == payload_size) || ((uint8)50 == payload_size))&& ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
					memcpy(Crypto_keyState_S.KeyPtr , &p_resultBytesInSRAM_U8P[1],(payload_size-2U));
                }
                else
                {
                    vHsmCrypt_key_not_present = TRUE;
                }
                 break;                
            case Crypto_VerifyKey_Wait:
                vHsmCrypt_key_Completed = TRUE;
                if(((uint8)1 == payload_size) && ((uint8)CRYPTO_JOB_DONE == status)) /* 1 byte status */
                {
                    /* Do nothing, as this is the success case */
                }
                else
                {
                    vHsmCrypt_key_not_present = TRUE;
                }
                 break;                
            default:
                break;
        }
}

/*==[Definition of functions with internal linkage]===========================*/

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_keyCallback(Csm_ReturnType param)
{
    if (TRUE == Crypto_keyNotif_S.callbackNeeded)
    {
        Crypto_keyNotif_S.callbackNeeded = FALSE;
        CRYPTO_HSM_CSM_KEY_CALLBACK_NOTIF(param);
    }

    if (TRUE == Crypto_keyNotif_S.finishNeeded)
    {
        Crypto_keyNotif_S.finishNeeded = FALSE;
        CRYPTO_HSM_CSM_KEY_SERVICE_FINISH_NOTIF(param);
    }
}

STATIC FUNC(void, CRY_CODE) Crypto_Hsm_keyCancel(void)
{
    Crypto_keyState_S.priority = CRYPTO_PRIORITY_NONE;
    /* Deviation MISRA-1 <STOP> */
#if (CRYPTO_CANCEL_CALLBACK_USED == 1)
    Crypto_keyState_S.state = Crypto_Hsm_Cancel;
#else
    Crypto_keyState_S.state = Crypto_Idle;
#endif /* #if (CRYPTO_CANCEL_CALLBACK_USED == 1) */
    if(Crypto_keyState_S.LockedHsm_E == TRUE)
    {
        Crypto_keyState_S.LockedHsm_E = FALSE;
        CRYPTO_RELEASE_HSM();
    }
}

STATIC FUNC(void, CRY_CODE) Crypto_keyActionOnFault(void)
{
    /* Scenarios landing up here -
     * 1. IPC is not available for transfer of data
     * 2. Error in last transfer
     * 3. No callback called for more than 5sec */
    if(Crypto_keyState_S.faultLog_U8 < FALUT_LOG_MAX_VAL)
    {
        Crypto_keyState_S.faultLog_U8++;
    }
if((Crypto_keyState_S.state != Crypto_KeySetConfirm) &&
   (Crypto_keyState_S.state != Crypto_KeySetConfirm_Wait))
    {
        Crypto_keyNotif_S.callbackNeeded = TRUE;
        Crypto_keyNotif_S.finishNeeded = TRUE;
        Crypto_keyNotif_S.callbackParamValue = CRYPTO_HSM_CSM_E_NOT_OK;
    }
    Crypto_Hsm_keyCancel();
    l_keyFaultCounter_U32 = 0u;
}

/*---[Cry_Hsm_EcdsaVerify_CheckFaultPeriodic]-----------------------------------------------------*/
static FUNC(boolean, CRY_CODE) Crypto_Hsm_key_CheckFaultPeriodic(void )
{
    boolean fl_ret_E = FALSE;
    if(l_keyFaultCounter_U32 >= KEY_FAULT_COUNTER_MAX_VAL )
    {
       fl_ret_E = TRUE;
    }
    else
    {
        l_keyFaultCounter_U32++;
    }

    return(fl_ret_E);
}


