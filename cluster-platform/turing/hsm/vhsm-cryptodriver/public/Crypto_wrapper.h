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
 * \file Crypto_wrapper.h
 *
 * \brief
 *  dispatch the crpto services Header file  in M7
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                                      .......|
 * |--------|------------|----------|---------|---------------------------------------------------------|
 * |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation           |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Malarvizhi Marimuthu     | mmarimu2  | VTSC, Chennai, India
 *          Baliga Baskaran          | bbaskara  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_WRAPPER_H
#define CRYPTO_WRAPPER_H 

#include "Std_Types.h"
//#include "vwCsm.h"
#include "Csm.h"
//#include "vHsmCry_She.h"
//#include "vHsmCry_She_Init.h"
//#include "CryIf_Cbk.h"
//#include "Cry_EcdsaVerify.h"
#include "Crypto_HashCalc.h"
//#include "Cry_SiphashCalc.h"
//#include "Cry_SiphashMacVer.h"
//#include "Cry_vkms.h"
#include "Crypto_Cfg.h"
//#include "Cry_vkms_MacGenerate.h"
#include "Crypto_SecureDebug.h"



/**
 *  Crypto_init
 *
 * This function initializes the module. It has to be called to init this module
 */
FUNC(void,CRY_CODE) Crypto4dot3_init(void);

/**
 *  Crypto_MainFunction
 *
 * This function is used to track the state machine with CRY-SHE execution
 * Used to transfer crypto job data from CSM4.3  to CRYSHE and getback the response from CRYSHE
 *
 */
FUNC(void,CRY) Crypto4dot3_MainFunction(void);

/**
 *  Crypto4dot3_ProcessJob
 *
 * This function process job request
 *
 * \param [in] objectId   Holds driver ID
 * \param [in] job     Pointer to the configuration of the job
 *
 * \return This function returns Std_ReturnType
 *                    E_OK                    Request successful.
 *                    E_NOT_OK                Request failed.
 *                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
 *
 */
Std_ReturnType  Crypto4dot3_ProcessJob(uint32 objectId, Crypto_JobType * job);

/**
 *  Crypto4dot3_CancelJob 
 *
 * This function cancels the given job.
 *
 * \param [in] objectId              -   Holds driver ID
 * \param [in] job                   -   Pointer to the configuration of the job
 *
 * \return  This function returns Std_ReturnType
 *                    E_OK                    Request successful.
 *                    E_NOT_OK                Request failed.
 */
Std_ReturnType  Crypto4dot3_CancelJob (uint32 objectId, Crypto_JobType* job);

/**
 *  Crypto_KeyElementGet
 *
 * This function  Gets the given key element bytes to the key identified by keyId
 *
 * \param [in] keyId              -   identifier of the key
 * \param [in] keyElementId       -   identifier of the key element to be read (dummy)
 * \param [out] keyPtr            -   pointer to store the key element bytes
 * \param [in,out] keyLengthPtr    -   Pointer to the number of key element bytes.
 * 
 * \return This function returns Std_ReturnType
 *                    E_OK                    Request successful.
 *                    E_NOT_OK                Request failed.
 *                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *
 */
Std_ReturnType  Crypto4dot3_KeyElementGet (uint32 keyId, uint32 keyElementId, uint8 * keyPtr,uint32 * keyLengthPtr);

/**
 *  Crypto_KeyElementSet 
 *
 * This function  Sets the given key element bytes to the key identified by keyId
 *
 * 
 * \param [in] keyId              -   identifier of the key
 * \param [in] keyElementId       -   identifier of the key element to be read (dummy)
 * \param [out] keyPtr            -   pointer to the key element bytes to be processed
 * \param [in,out] keyLength    -   Pointer to the number of key element bytes.
 *
 * \return This function returns Std_ReturnType
 *                    E_OK                    Request successful.
 *                    E_NOT_OK                Request failed.
 *                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *
 */
Std_ReturnType  Crypto4dot3_KeyElementSet (uint32 keyId, uint32 keyElementId,const uint8 * keyPtr, uint32 keyLength);

/**
 *  Crypto4dot3_KeyValidSet 
 *
 * This function  Sets the key state of the key identified by keyId to valid
 *
 * \param [in] keyId              -   identifier of the key
 *
 * \return This function returns Std_ReturnType
 *                    E_OK                    Request successful.
 *                    E_NOT_OK                Request failed.
 *                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *
 */
Std_ReturnType  Crypto4dot3_KeyValidSet (uint32 keyId);


/**
 * ECDSA_verify_callback
 *
 * This function  Gets the ECDSA sign verify result from CRYSHE and sets the callback status of this job
 *
 * \param [in] Result              -   Holds the result of the job
 */
void  ECDSA_verify_callback(Csm_ReturnType Result);

/**
 * Crypto_HashCalc_callback
 *
 * This function  Gets the HASH calculation job result from CRYSHE and sets the callback status of this job
 *
 * \param [in] Result              -   Holds the result of the job
 *
 */
void Crypto_HashCalc_callback(Csm_ReturnType Result);

/**
 *  SiphashMacGen_callback
 *
 * This function  Gets the SIPHASH MAC generator job result from CRYSHE and sets the callback status of this job
 *
 *
 * \param [in] Result              -   Holds the result of the job
 */
void  SiphashMacGen_callback(Csm_ReturnType Result);

/**
 *  SiphashMacVer_callback
 *
 * This function  Gets the SIPHASH MAC verify job result from CRYSHE and sets the callback status of this job

 *
 * \param [in] Result              -   Holds the result of the job
 */
void SiphashMacVer_callback(Csm_ReturnType Result);

/**
 *  HSM_VKMS_callback
 *
 * This function  Gets the VKMS job result from CRYSHE and sets the callback status of this job
 *
 * This function returns NONE
 *
 * \param [in] Result              -   Holds the result of the job
 */
void  HSM_VKMS_callback(Csm_ReturnType Result);

/**
 *  csm_VKMSMacgen_callback
 *
 * This function  Gets the VKMS MAC Generate job result from CRYSHE and sets the callback status of this job
 *
 * This function returns NONE
 *
 * \param [in] Result              -   Holds the result of the job
 */
void csm_VKMSMacgen_callback(Csm_ReturnType Result);
#endif
