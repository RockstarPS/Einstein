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
 * \file Crypto_HashCalc.h
 *
 * \brief
 * Hash calc header in M7
 *
 * \detailed description
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 06/Mar/'21 | bjayara2 | 1254751 |Hash Calc for FDS                      |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Chennai, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_HASH_CALC_H
#define CRYPTO_HASH_CALC_H 1
#define CRYPTO_HASH_CALC_ENABLED   1
/*==[Includes]================================================================*/

#include "Std_Types.h"
#include "stub.h"
#include "Crypto_Cfg.h"

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_HashCalcConfigType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/
extern void HashCalc_callback(Csm_ReturnType Result);

/* Define Callback Notification functions for CSM */
#define CRYPTO_CSM_HASHCALC_CALLBACK_NOTIF   HashCalc_callback
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_CSM_HASHCALC_SERVICE_FINISH_NOTIF


/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcInit
 **
 ** \brief 
 ** API for Initialisation of Hash calculation
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns none
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_HashCalcInit(void);


/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcStart
 **
 ** \brief 
 ** API to Hash Calculation start mode
 **
 ** \param [in] cfgPtr
 ** 
 ** 
 ** This function returns Csm_ReturnType
 ** CSM_E_OK
 ** CSM_E_NOT_OK
 ** CSM_E_BUSY
 ** CSM_E_SMALL_BUFFER
 ** CSM_E_ENTROPY_EXHAUSTION
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcStart(
                P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr);

/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcUpdate
 **
 ** \brief 
 ** API for Update mode of Hash Calculation
 **
 ** \param [in] job
 ** 
 ** 
 ** This function returns Csm_ReturnType
 ** CSM_E_OK
 ** CSM_E_NOT_OK
 ** CSM_E_BUSY
 ** CSM_E_SMALL_BUFFER
 ** CSM_E_ENTROPY_EXHAUSTION 
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcUpdate(
                const uint8 * p_dataPtr_PU8 ,
                uint32 p_dataLength_U32);


/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcFinish
 **
 ** \brief 
 ** API for Finish mode of Hash Calculation
 **
 ** \param [in] p_resultPtr_PU8 
 ** \param [in] p_resultLengthPtr_PU32
 ** \param [in] p_truncationAllowed_BOOL
 ** 
 ** This function returns Csm_ReturnType
 ** CSM_E_OK
 ** CSM_E_NOT_OK
 ** CSM_E_BUSY
 ** CSM_E_SMALL_BUFFER
 ** CSM_E_ENTROPY_EXHAUSTION 
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_HashCalcFinish(
                uint8 *      p_resultPtr_PU8 ,
                uint32 *     p_resultLengthPtr_PU32 ,
                boolean      p_truncationAllowed_BOOL);


/**
 *********************************************************************************************
 ** \fn Crypto_HashCalcMainFunction
 **
 ** \brief 
 ** Hash Calc main function to track the state machine with M0P execution
 ** Use to transfer data to M0P from M7 for Hash calc crypto job and get
 ** back the response from M0P
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns none
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE) Crypto_HashCalcMainFunction(void);

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_HashCalc
 **
 ** \brief 
 ** API for  Hash Calculation
 **
 ** \param [in] cfgPtr 
 ** \param [in] p_dataPtr_PU8
 ** \param [in] p_dataLength_U32
 ** \param [in] p_dataLength_U32
 ** \param [in] p_dataLength_U32
 ** 
 ** This function returns Csm_ReturnType
 ** CSM_E_OK
 ** CSM_E_NOT_OK
 ** CSM_E_BUSY
 ** CSM_E_SMALL_BUFFER
 ** CSM_E_ENTROPY_EXHAUSTION 
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_HashCalc
(
                P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr,
                const uint8 * p_dataPtr_PU8 ,
               uint32 p_dataLength_U32,
               uint8 *      p_resultPtr_PU8 ,
               uint32 *     p_resultLengthPtr_PU32 ,
               boolean      p_truncationAllowed_BOOL
);



#endif  /*CRYPTO_HASH_CALC_H*/
