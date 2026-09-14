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
 * \file Crypto_She.c
 *
 * \brief
 * Crypto She implementation for HSM from M7
 *
 * \detailed description
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                        |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                      |
 * |1.00.02 | 03/Feb/'21 | bjayara2 | 1214316 | Implement fail safe recovery in both cores |
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
#include "string.h"
#if 0
#include "Crypto_CmacGen.h"
#include "Crypto_MacVerify.h"
#include "Crypto_CbcDecrypt.h"
#include "Crypto_CbcEncrypt.h"
#include "Crypto_SymBlockDecrypt.h"
#include "Crypto_SymBlockEncrypt.h"
#include "Crypto_SymKeyExtract.h"
#endif
#include "Crypto_Random.h"
#include "Crypto_HashCalc.h"
#include "Crypto_Cancel.h"
#if 0
#include "Crypto_SecureDebug.h"
#include "Crypto_HmacGen.h"
#endif
#include "vHsmCryptoManager.h"
#include "vHsmDmnMgr.h"
/*==[Macros]==================================================================*/

#define IPC_HSM_PACK(a)   vHsmCrypto_Manager_SendData(a)

#define QUASI_SYNC
/* For Asynchronous requests - Fault counter max value arrived by 
   dividing the max timeout of 1000ms
 * by the scheduling rate - 10ms, 1000ms/10ms = 100 */
 /* For Quasi sync requests - fault counter value is kept little
  * high as the csm main function gets invoked inline */
#ifdef QUASI_SYNC
#define FAULT_COUNTER_MAX_VAL      ((uint32)50000)
#else
#define FAULT_COUNTER_MAX_VAL      ((uint32)100)
#endif

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/
STATIC VAR(boolean, CRY_VAR) Crypto_Hsm_HsmLocked = FALSE;


STATIC VAR(boolean, CRY_VAR) vHsmCrypt_Init_bool;

STATIC VAR(uint32, CRY_VAR) l_FaultCounter_U32;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/


FUNC(void, CRY_CODE) Crypto_Internal_Init(void)
{
/*initialising of functions*/
    //Crypto_SymMacVerInit();
    Crypto_RandomInit();
   //Crypto_SymDecryptInit();
    //Crypto_She_SymEncryptInit();
    //Crypto_SymBlockDecryptInit();
    //Crypto_SymBlockEncryptInit();
    //Crypto_She_SymMacGenInit();
    //Crypto_SymMacVerInit();
    //Crypto_SymKeyExtractInit();
    Crypto_CancelInit();
    Crypto_HashCalcInit();
   // Crypto_She_SymHmacGenInit();
    vHsmDmnMgr_Init();
  /* initialising SHE Variables*/
  vHsmCrypt_Init_bool = TRUE;
  l_FaultCounter_U32 = 0;

}

FUNC(boolean, CRY_CODE) Crypto_IsInit(void)
{
    return(vHsmCrypt_Init_bool);
}

FUNC(boolean, CRY_CODE) Crypto_LockShe(void)
{
    boolean fl_ret_E = FALSE;

    if (Crypto_Hsm_HsmLocked == FALSE)
    {
        Crypto_Hsm_HsmLocked = TRUE;
        fl_ret_E           = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
    return fl_ret_E;
}

/*---[Crypto_ReleaseShe]-----------------------------------------------------*/
FUNC(void, CRY_CODE) Crypto_ReleaseShe(void)
{
    Crypto_Hsm_HsmLocked = FALSE;
}

/*---[Crypto_SendPackedData]-----------------------------------------------------*/

FUNC(Std_ReturnType, CRY_CODE) Crypto_SendPackedData(ts_vHsm_Cryptodata p_Cryptodata_S )
{
    Std_ReturnType fl_Ret_val_e = E_NOT_OK;
    fl_Ret_val_e = IPC_HSM_PACK(p_Cryptodata_S);
    return(fl_Ret_val_e);
}

/*---[Crypto_StartFaultCounter]-----------------------------------------------------*/

FUNC(void, CRY_CODE) Crypto_ResetFaultCounter(void )
{
	l_FaultCounter_U32 = 0;
}


/*---[Crypto_CheckFaultPeriodic]-----------------------------------------------------*/
FUNC(boolean, CRY_CODE) Crypto_CheckFaultPeriodic(void )
{
    boolean fl_ret_E = FALSE;
    if(l_FaultCounter_U32 >= FAULT_COUNTER_MAX_VAL )
    {
        fl_ret_E = TRUE;
    }
    else
    {
        l_FaultCounter_U32++;
    }
    return(fl_ret_E);
}


