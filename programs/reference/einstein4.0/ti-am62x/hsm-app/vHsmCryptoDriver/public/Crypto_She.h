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
 * \file Crypto_She.h
 *
 * \brief
 * Cry interface header in M7
 *
 * \detailed description
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 28/Oct/'22 | svetcha  | 1061554 | AUTOSAR CRY Wrapper                   |
 * 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Chennai, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_SHE_H
#define CRYPTO_SHE_H 

/*==[Includes]================================================================*/
#include "Std_Types.h"
#include "Csm_Types.h"
#include "Crypto_Cancel.h"
#include "vHsmCryptoManager.h"
#include "Crypto_Cfg.h"
#include "stub.h"

/*==[Macros]==================================================================*/
#ifndef STATIC
#define STATIC static
#endif /* STATIC */

#define FALUT_LOG_MAX_VAL      ((uint8)250)

#define INT16_MIN_RANGE                   ((uint32)0)

#define INT16_MAX_RANGE                   ((uint32)65535)

/** \brief Priority threshold for canceling a blocked functionality */
#define CRYPTO_HSM_CANCEL_PRIO_THRESHOLD 200U

/** \brief AUTOSAR locking */
#if CSM_LINK==STD_ON
//#define CRYPTO_LOCK_SEM() SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0()
//#define CRYPTO_RELEASE_SEM() SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0()
#else
//#define CRYPTO_LOCK_SEM() SchM_Enter_CryShe_EXCLUSIVE_AREA_0()
//#define CRYPTO_RELEASE_SEM() SchM_Exit_CryShe_EXCLUSIVE_AREA_0()
#endif


/* Define the below macro to 1 if the callback for cancel command */
#define CRYPTO_CANCEL_CALLBACK_USED  0

/** \brief Default Lowest HSM Priority */
#define CRYPTO_PRIORITY_NONE 0

/** \brief Block Length of HSM */
#define CRYPTO_HSM_BLOCK_LENGTH 16

/** \brief Block Length of HSM for SHA256 */
#define CRYPTO_HSM_SHA256_BLOCK_LENGTH 32


/** \brief Constant key length given by the SHE hardware. **/
#define CRYPTO_HSM_CONST_KEY_LENGTH  (sizeof(Crypto_SymKeyInfoType))

/** \brief The Cry driver shall implicitly repeat requests if the HSM
           reports a memory error during flash key updates **/
#define CRYPTO_HSM_FLASH_ARBITRATION_BY_SW STD_OFF

#if (defined EB_STATIC_CHECK)
/** \brief This macro can be used to avoid compiler warnings
 * It is left empty to not product a false positive for MISRA 14.2 */
#define CRYPTO_UNUSED_PARAMETER(x)
#else
/** \brief This macro can be used to avoid compiler warnings */
#define CRYPTO_UNUSED_PARAMETER(x) ((void) (x))
#endif

/** \brief Redefinition of CSM return type values for CSM**/
#define CRYPTO_HSM_CSM_E_OK                          CSM_E_OK
#define CRYPTO_HSM_CSM_E_NOT_OK                      CSM_E_NOT_OK
#define CRYPTO_HSM_CSM_E_BUSY                        CSM_E_BUSY
#define CRYPTO_HSM_CSM_E_KEY_NOT_AVAILABLE           CSM_E_KEY_NOT_AVAILABLE

/** brief SHE ram key slot. to adapt to old my MP21 project **/
#define CRYPTO_SHE_RAM_KEY 0xEU

/*==[Types]===================================================================*/

typedef enum
{
    Crypto_Idle,
    Crypto_Cancel,
    Crypto_Start,
    Crypto_Start_Wait,
    Crypto_Update,
    Crypto_Update_Wait,
    Crypto_Finish,
    Crypto_Finish_Wait,
    Crypto_KeySet,
    Crypto_KeySet_Wait,
    Crypto_KeySetConfirm,
    Crypto_KeySetConfirm_Wait,
    Crypto_GetKey,
    Crypto_GetKey_Wait,
    Crypto_VerifyKey,
    Crypto_VerifyKey_Wait            
} Crypto_StateType;

typedef struct
{
        VAR(uint8, CRY_APPL_DATA) callbackNeeded;
        VAR(uint8, CRY_APPL_DATA) finishNeeded;
        VAR(Csm_ReturnType, CRY_APPL_DATA) callbackParamValue;
}
Crypto_NotifType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/


/**
 *********************************************************************************************
 ** \fn Crypto_IsInit
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(boolean, CRY_CODE) Crypto_IsInit(void);


/**
 *********************************************************************************************
 ** \fn Crypto_LockShe
 **
 ** \brief 
 **
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(boolean, CRY_CODE) Crypto_LockShe(void);

/**
 *********************************************************************************************
 ** \fn Crypto_ReleaseShe
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_ReleaseShe(void);

/**
 *********************************************************************************************
 ** \fn Crypto_SendPackedData
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_SendPackedData(ts_vHsm_Cryptodata p_Cryptodata_S);

/**
 *********************************************************************************************
 ** \fn Crypto_ResetFaultCounter
 **
 ** \brief 
 **
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_ResetFaultCounter(void);

/**
 *********************************************************************************************
 ** \fn Crypto_CheckFaultPeriodic
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(boolean, CRY_CODE) Crypto_CheckFaultPeriodic(void);

FUNC(void, CRY_CODE) Crypto_Internal_Init(void);
/** \brief Locking and unlocking HSM */
#define CRYPTO_LOCK_HSM() Crypto_LockShe()
#define CRYPTO_RELEASE_HSM() Crypto_ReleaseShe()

#endif /* CRYPTO_H */
