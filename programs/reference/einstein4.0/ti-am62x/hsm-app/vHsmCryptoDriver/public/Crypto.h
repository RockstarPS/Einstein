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
 * \file Crypto.h
 *
 * \brief
 *  dispatch the crpto services Header file  in M7
 *
 * \detailed description
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                                      .......|
 * |--------|------------|----------|---------|---------------------------------------------------------|
*  |1.00.00 | 29/Aug/'22 | svetcha  | 1713112 |Initial Dispatch crpto services implementation           |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_H
#define CRYPTO_H

#define FUNC(rettype, memclass) rettype

#include "Csm_Types.h"
#include "Crypto_Cfg.h"
#include "Stubs.h"
#include "Compiler_Cfg.h"
// #include "Crypto_KeyManagementn.h"
#include "Compiler.h"
/*
typedef struct Crypto_KeyType
{
  uint32 RefOfKey; < refofkey
} Crypto_KeyType;*/
extern const Crypto_KeyType crypto_Key[TotalnoCryptoKey];

/**
 *********************************************************************************************
 ** \fn Crypto_Init
 **
 ** \brief 
 ** Initialization of crypto driver
 **
 ** \param [in] NONE
 ** 
 ** \param [out]  NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) CryptoDrv_Init(void);

/**
 *********************************************************************************************
 ** \fn Crypto_GetVersionInfo
 **
 ** \brief 
 ** Gives the version information of this module.
 **
 ** \param [in] versioninfo Pointer to store the version information
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_GetVersionInfo(
                  P2VAR (Std_VersionInfoType, AUTOMATIC, CRY_APPL_DATA) versioninfo);


/**
 *********************************************************************************************
 ** \fn Crypto_ProcessJob
 **
 ** \brief 
 ** Performs the crypto primitive, that is configured in the job parameter
 **
 ** \param [in] objectId   Holds the identifier of the Crypto Driver Object
 ** 
 ** \param [inout] job  Pointer to the configuration of the job
 **
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_BUSY: Request Failed, Crypto Driver Object is Busy
 ** CRYPTO_E_KEY_NOT_VALID: Request failed, because the key is not valid
 ** CRYPTO_E_KEY_SIZE_MISMATCH: Request failed,because a key element has the wrong size
 ** CRYPTO_E_QUEUE_FULL:Request failed, the queue is full
 ** CRYPTO_E_ENTROPY_EXHAUSTION: Request failed, the entropy is exhausted
 ** CRYPTO_E_SMALL_BUFFER:  Provided buffer is too small to store the result  
 ** CRYPTO_E_COUNTER_OVERFLOW: The counter is overflowed
 ** CRYPTO_E_JOB_CANCELED: synchronous Job has been canceled                
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessJob(
                 uint32 objectId, 
                 P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);


/**
 *********************************************************************************************
 ** \fn Crypto_MainFunction
 **
 ** \brief 
 ** Periodically invoked API
 **
 ** \param [in] NONE
 ** 
 ** \param [out]  NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE)Crypto_MainFunction(void);

/**
 *********************************************************************************************
 ** \fn Crypto_CancelJob
 **
 ** \brief 
 ** Removes the provided job from the queue and cancels the processing of the job if possible
 **
 ** \param [in] objectId   Holds the identifier of the Crypto Driver Object
 ** 
 ** \param [inout] job  Pointer to the configuration of the job
 **
 ** This function returns Std_ReturnType
 ** E_OK: Request successful
 ** E_NOT_OK: Request Failed
 ** CRYPTO_E_JOB_CANCELED: synchronous Job has been canceled                
 **
 **
 ********************************************************************************************/
FUNC(Std_ReturnType, CRY_CODE) Crypto_CancelJob(uint32 objectId, 
                                              P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA)job);

#endif /*CRYPTO_H*/
