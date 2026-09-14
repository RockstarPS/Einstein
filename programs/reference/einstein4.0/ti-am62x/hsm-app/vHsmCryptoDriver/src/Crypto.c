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
 * \file Crypto.c
 *
 * \brief
 * Dispatch the crpto services in M7 from CSM
 *
 * \detailed description
 *  This file shall be dispatch the crypto job in M7, IT Receives the Crypto job request from CRYIF and depends on the job request passes the data to to CRY-SHE 
 *  and receiving back data from CRY-SHE and pass this data to CRYIF
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           ...................|
 * |--------|------------|----------|---------|----------------------------------------------------------|
 * |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation            |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Benjamin George Samuel   | bgeorge2  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

/*include files*/
#include "Crypto.h"
#include "Compiler.h"
#include "CryIf.h"
#include "CryIf_Cbk.h"
#include "string.h"
#include "Det.h"
#include "Crypto_CmacGen.h"
#include "Crypto_MacVerify.h"
#include "Crypto_Random.h"
#include "Crypto_CbcDecrypt.h"
#include "Crypto_CbcEncrypt.h"
#include "Crypto_EcbDecrypt.h"
#include "Crypto_EcbEncrypt.h"
#include "Crypto_SymKeyExtract.h"
#include "vHsmCryptoManager.h"
#include "Crypto_EcbEncrypt.h"
#include "Crypto_SymKeyInfo.h"
#include "vHsmDmnMgr.h"
#ifdef TINCRYPT_ENABLED
#include "tinycrypt/sha256.h"
#include "tinycrypt/ecc_dsa.h"
#endif

#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */
#define UPPER_LIMIT_JOB_ID (22)
#define LOWER_LIMIT_JOB_ID (0)

#define RAM_KEY_SIZE ((uint32)16)
#define FLASH_KEY_SIZE ((uint32)64)

#define TESTING_ENABLED                  STD_OFF



#if TESTING_ENABLED 
extern FUNC(void, Crypto_CODE) Crypto_Task(void);
//extern FUNC(void, CRY_CODE) Crypto_SymMacGenCancel(void);
#endif /*TESTING_ENABLED*/
/******** Global Variables **********/
P2VAR(Crypto_JobType,AUTOMATIC,CRY_APPL_DATA) cryptoqueuejob;

Crypto_SymKeyInfoType Crypto_SymKeyInfo;


/**********static Variables***********/
static uint32 Locked_job_status = 0xFFFFFFFF;
static uint8 Crypto_IsInitialized = CRYPTO_UNINIT;
static uint8 Crypto_Callback_status[Totalno4dot2CryptoJob] = {CRYPTO_JOB_IDLE};
/*Variable is used to set the flag for Single call mode*/
static uint8 mode_singlecall[Totalno4dot2CryptoJob] = {SINGLE_CALLMODE_NOT_SET};
/*variable is used to update the job status to follow the job dispatch*/
static uint8 Crypto_job_state[Totalno4dot2CryptoJob] = {CRYPTO_JOB_IDLE};
static uint8 KeyID_map;
static uint8 KeyID_u8;
static Csm_SymKeyType KeyID;
//static uint8 l_key_buffer_U8A[64] = {0u};
//static uint32 l_keyLength_U32;
static uint8 initVector[16] = {0};
uint8 fl_padding_u8 = 0;
static Csm_SymKeyType crpto_KeyID;
uint8 Cipher2[20]={0};
/**
 * structure for Crypto_KeyType
 */
#if 0
const uint8 crypto_Key[Totalno4dot2CryptoKey] =
 {
    /*    Ref     */
    1,2,4,5,6,7,8,9,10,11,12,13,14
};
#endif 
const Crypto_KeyType crypto_Key[TotalnoCryptoKey] = {
    /*    Ref     */
  {CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_0_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_1_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_2_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_3_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_4_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_5_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_6_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_7_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_8_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_9_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_10_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_11_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_12_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_13_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_14_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_15_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_16_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_17_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_18_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_19_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_20_KeyManagement},
	{CryptoConf_CryptoKey_CryptoKey_Csm_KeySlot_255_KeyManagement}};

static Std_ReturnType l_Crypto_main_retVal = E_NOT_OK;
static Std_ReturnType CryptoJob_retval = E_NOT_OK;
//static uint8 l_CBC_IvData_U8A[16];
//static uint32 l_CBC_IvDataLen;
/*==[Declaration of functions with external linkage]==========================*/


/*==[Declaration of functions with internal linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn crypto_precheck
 **
 ** \brief 
 ** API to check Pre-conditions
 **
 ** \param [in] job
 ** 
 ** 
 ** This function returns Std_ReturnType
 ** CRYPTO_E_NO_ERROR: no error occured
 ** CRYPTO_E_UNINIT : module un initialized
 ** CRYPTO_E_INIT_FAILED :Initialisation of CRYPTO module failed
 ** CRYPTO_E_PARAM_POINTER : API request called with invalid parameter (null pointer)
 ** CRYPTO_E_PARAM_HANDLE: API request called with invalid parameter (out of range)
 ** CRYPTO_E_PARAM_VALUE: API request called with invalid parameter (invalid value)
 **                 
 **
 ********************************************************************************************/
LOCAL FUNC(Std_ReturnType, CRY_CODE) crypto_precheck(P2VAR(Crypto_JobType,AUTOMATIC,CRY_APPL_DATA) job);

/**
 *********************************************************************************************
 ** \fn Crypto_ProcessJobService
 **
 ** \brief 
 ** API to process job in start-update-finish mode
 **
 ** \param [in] objectId
 ** \param [in] job
 ** 
 ** This function returns Std_ReturnType
 ** CRYPTO_E_NO_ERROR: no error occured
 ** CRYPTO_E_UNINIT : module un initialized
 ** CRYPTO_E_INIT_FAILED :Initialisation of CRYPTO module failed
 ** CRYPTO_E_PARAM_POINTER : API request called with invalid parameter (null pointer)
 ** CRYPTO_E_PARAM_HANDLE: API request called with invalid parameter (out of range)
 ** CRYPTO_E_PARAM_VALUE: API request called with invalid parameter (invalid value)
 **                 
 **
 ********************************************************************************************/
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessJobService(uint32 objectId, 
                    P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job) ;

/**
 *********************************************************************************************
 ** \fn Crypto_Start_process
 **
 ** \brief 
 ** API to process job in start mode
 **
 ** \param [in] job
 ** 
 ** 
 ** This function returns Std_ReturnType
 ** CSM_E_OK: 
 ** CSM_E_NOT_OK:
 **                 
 **
 ********************************************************************************************/
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Start_process(
                  P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);

/**
 *********************************************************************************************
 ** \fn Crypto_Update_process
 **
 ** \brief 
 ** API to process job in update mode
 **
 ** \param [in] job
 ** 
 ** 
 ** This function returns Std_ReturnType
 ** CSM_E_OK: 
 ** CSM_E_NOT_OK:
 **                 
 **
 ********************************************************************************************/
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Update_process(
                  P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);

/**
 *********************************************************************************************
 ** \fn Crypto_Finish_process
 **
 ** \brief 
 ** API to process job in finish mode
 **
 ** \param [in] job
 ** 
 ** 
 ** This function returns Std_ReturnType
 ** CSM_E_OK: 
 ** CSM_E_NOT_OK:
 **                 
 **
 ********************************************************************************************/
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Finish_process(
                  P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);


/**
 *********************************************************************************************
 ** \fn HashCalc_callback
 **
 ** \brief 
 ** Calls the callback function, if needed, outside the lock semaphore code
 **
 ** \param [in] param
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) HashCalc_callback(Csm_ReturnType Result);

LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_EncryptSinglecall(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);
static FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessSyncJobs(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);
#if (CRYPTO_SIGNATURE_VERIFICATION == STD_ON)
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_SignVerSinglecall(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job);
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_SignatureVerify(Crypto_AlgorithmFamilyType familyType,const uint8  *signature,uint32  signatureLength,const uint8*  hash,uint32 hashLength,uint32  cryptoKeyId,Crypto_VerifyResultType* result);
#endif
/*==[Defination of functions with external linkage]==========================*/


FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessJob(uint32 objectId, P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
    Std_ReturnType retVal = CSM_E_NOT_OK;
    if((job != NULL_PTR) && (crypto_precheck(job) == CRYPTO_E_NO_ERROR))
    {
      /* Process synchronous job */
      if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC)
      {      
        retVal = Crypto_ProcessSyncJobs(job);
      }
      else
      {
        /*process asynchronous job*/
        retVal = CRYPTO_E_QUEUE_FULL;
        if (cryptoqueuejob == NULL_PTR) 
        {
          if ((Locked_job_status == 0xFFFFFFFFuL)|| (Locked_job_status == job->jobInfo->jobId ))
          {
            /*job is set in queue*/
            cryptoqueuejob = job;
            l_Crypto_main_retVal= CRYPTO_E_BUSY;
            retVal = E_OK;
          }
        }
      }
    }
  return retVal;
}

static FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessSyncJobs(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 job_priority = 1u;
  job->cryptoKeyId = crypto_Key[job->jobPrimitiveInfo->cryIfKeyId].RefOfKey;
  switch (job->jobPrimitiveInfo->primitiveInfo->service)
  {
  case CRYPTO_RANDOMGENERATE:
#if (CRYPTO_RANDOM_ENABLED == STD_ON)
    retVal = Crypto_RandGen4Dot3CSM(&job_priority,job->jobPrimitiveInputOutput.outputPtr,*job->jobPrimitiveInputOutput.outputLengthPtr);
#endif
    break;
  case CRYPTO_ENCRYPT:
    retVal = Crypto_EncryptSinglecall(job);
    break;
  case CRYPTO_SIGNATUREVERIFY:
#if (CRYPTO_SIGNATURE_VERIFICATION == STD_ON)
    retVal = Crypto_SignVerSinglecall(job);
#endif
    break;
  default:
    break;
  }
  return retVal;
}

#if (CRYPTO_SIGNATURE_VERIFICATION == STD_ON)
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_SignVerSinglecall(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  Std_ReturnType ret = E_NOT_OK;
  uint8 i = 1u;
  sint8 retsha = 0;
  uint8 hash[64];
  uint32 hashlen = 0;
  struct tc_sha256_state_struct shactx;
  TCSha256State_t currentState = &shactx;
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily)
  {
  case CRYPTO_ALGOFAM_SHA2_256:
    (void)tc_sha256_init (&currentState);
    retsha = tc_sha256_update(&currentState, job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);
    if(ret == 1 ){
      retsha =  tc_sha256_final(&hash[0],&currentState);
    }
    hashlen = 32u;
    break;
  default:
    break;
  }
  if(1 == retsha)
  {
    ret = Crypto_SignatureVerify(job->jobPrimitiveInfo->primitiveInfo->algorithm.family,job->jobPrimitiveInputOutput.secondaryInputPtr,job->jobPrimitiveInputOutput.secondaryInputLength,&hash[0],hashlen,job->cryptoKeyId,job->jobPrimitiveInputOutput.verifyPtr);
  }
  return ret;
}
#endif
#if (CRYPTO_SIGNATURE_VERIFICATION == STD_ON)
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_SignatureVerify(Crypto_AlgorithmFamilyType familyType,
        const uint8                *signature,
        uint32                     signatureLength,
        const uint8*               hash,
        uint32                     hashLength,
        uint32                     cryptoKeyId,
        Crypto_VerifyResultType*   result)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 pubkey_U8A[64] = {0};
    sint8 retecc = 0;
    uint32 keylength_U32 = 64u;
    retVal = Crypto_She_GetKey(cryptoKeyId,0,&pubkey_U8A[0],&keylength_U32);
    if(E_OK == retVal)
    {
      switch (familyType)
      {
      case CRYPTO_ALGOFAM_ECCNIST:
#if(CRYPTO_ECDSA_ENABLED == STD_ON)
        retecc = uECC_verify(&pubkey_U8A[0],hash,hashLength,signature,uECC_secp256r1());
        if(retecc == 1)
        {
          *result = 0u;
          retVal = E_OK;
        }
#endif
        break;
        default:
        break;
      }
    }
    return retVal;
}
#endif
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_EncryptSinglecall(P2VAR (Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  Std_ReturnType ret = E_NOT_OK;
  uint8 i = 1u;
  crpto_KeyID.length = 8;
  crpto_KeyID.data = (uint32)job->cryptoKeyId;
  if(job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)
  {
    if(job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB)
    {
#if(CRYPTO_ECBENCRYPT_ENABLED == STD_ON)
      ret = Crypto_She_SymBlockEncrypt_S(&i,&crpto_KeyID,job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr,0u);
#endif    
    } 
  }
  return ret;
}

FUNC(Std_ReturnType,CRY_CODE) Crypto_CancelJob (uint32 objectId, 
              P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA)job)
{
  uint32 jobref = job->jobInfo->jobId;
  /*...Process the cancel request if job is occupied...*/
  if ((cryptoqueuejob != NULL_PTR) && (cryptoqueuejob->jobInfo->jobId == job->jobInfo->jobId))
  {
    jobref -= LOWER_LIMIT_JOB_ID;
    /*...CRY-SHE cancel APIs are invoked to cancel the job */
    switch (job->jobPrimitiveInfo->primitiveInfo->service) 
    {
#if (CSM_HASH_API == STD_ON)      
      case CRYPTO_HASH:
        Crypto_HashCalcCancel(); 
      break;
#endif

#if (CSM_MACGENERATE_API == STD_ON)
    case CRYPTO_MACGENERATE:
      Crypto_SymMacGenCancel();
    break;
#endif

#if (CSM_MACVERIFY_API == STD_ON)
      case CRYPTO_MACVERIFY:
        Crypto_SymMacVerCancel();
      break;
#endif
#if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON))
      case CRYPTO_ENCRYPT:
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC)
        {
          Crypto_Hsm_SymEncryptCancel();
        }
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB)
        {
          Crypto_SymBlockEncryptCancel();
        }
      break;
#endif /* #if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON)) */        
#if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))  
      case CRYPTO_DECRYPT:        
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC)
        {
          Crypto_SymDecryptCancel();
        }
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB)
        {
          Crypto_SymBlockDecryptCancel();
        }
      break;
#endif     /* #if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))   */   
#if (CSM_SYM_KEY_EXTRACT_API == STD_ON)
      case CRYPTO_KEYSETVALID:
        Crypto_SymKeyExtractCancel();
      break;
#endif
#if (CSM_RANDOMGENERATE_API == STD_ON)
      case CRYPTO_RANDOMGENERATE:
        Crypto_RandomCancel();
      break;
#endif      
      default: 
      break;
    }
    /*...Requested job is cancelled...*/
    cryptoqueuejob = NULL_PTR;
    Crypto_job_state[jobref] = CRYPTO_JOB_IDLE;
    Crypto_Callback_status[jobref]  = CRYPTO_JOB_IDLE;
    mode_singlecall[jobref]  = SINGLE_CALLMODE_NOT_SET;
    Locked_job_status = 0xFFFFFFFF; /*job lock is released*/
   // CryIf_CallbackNotification(job, CRYPTO_E_JOB_CANCELED);
  }
  else
  {
    /* Cancel request is not processed becasue requested job is not available in the queue*/
   // CryIf_CallbackNotification(job, CSM_E_NOT_OK);
  }
  return CSM_E_OK;
}


/*===================================[Definition of functions with internal linkage]===========================*/

/* API to process the job in start-update-finish modes*/
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_ProcessJobService(uint32 objectId, 
                    P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  uint32 jobref = job->jobInfo->jobId;
  if((job->jobInfo->jobId) < UPPER_LIMIT_JOB_ID)
  {
    jobref -= LOWER_LIMIT_JOB_ID;
    /*Job has been processed based on mode*/
        if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_SINGLECALL)
        {
            switch (Crypto_job_state[jobref]) 
            {
              /* Automatic calling of "start - update - finish" in single call mode */
              case 0:
                  if((job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_ENCRYPT)||(job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_MACGENERATE)
                  || (job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_RANDOMGENERATE))
                  {
                      job->jobPrimitiveInputOutput.mode    = CRYPTO_OPERATIONMODE_FINISH;
                      mode_singlecall[jobref] = SINGLE_CALLMODE_SET;
                      Crypto_job_state[jobref] = 4;
                  }
                  else
                  {
                      job->jobPrimitiveInputOutput.mode    = CRYPTO_OPERATIONMODE_START;
                      mode_singlecall[jobref] = SINGLE_CALLMODE_SET;
                  }
                  break; //case 0
              default:
                  break; //default
            }
        }

        if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_START)
        {
            switch (Crypto_job_state[jobref]) 
            {
              case 0:
                  CryptoJob_retval = Crypto_Start_process(job);
                  if(CryptoJob_retval == (uint8)E_OK)
                  {
                    Crypto_Callback_status[jobref] = CRYPTO_JOB_IDLE;
                    /*set driver status as busy if job process is success in driver*/
                    job->state = CRYPTO_JOBSTATE_ACTIVE;
                    CryptoJob_retval = CRYPTO_E_BUSY;
                    /*  The below variable value is increased to follow 
                    the job process in Asynchronus mode (state Machine)*/
                    Crypto_job_state[jobref] =1;
                  }
                break; //case 0
              case 1:
                  /*...check call back status from crypto driver*/
                  if (Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_OK)
                  {
                    Crypto_Callback_status[jobref] = CRYPTO_JOB_IDLE;
                    /*The below variable value is increased to follow 
                    the job process in Asynchronus mode (state Machine)*/
                    Crypto_job_state[jobref] =2;
                    /* Set the job mode as update if single call mode flag is set*/
                    if (mode_singlecall[jobref] ==SINGLE_CALLMODE_SET)
                    {
                      job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_UPDATE;
                    }
                    else
                    {
                      CryptoJob_retval = E_OK;
                    }
                  }
                  if(Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_NOT_OK)
                  {
                    /*...error occured in crypto driver...*/
                  CryptoJob_retval = E_NOT_OK;
                  }
                break; //case 1
              default:
                break; //default
            }
        }

        if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_UPDATE)
        {
          switch (Crypto_job_state[jobref]) 
            {
              case 2:

                CryptoJob_retval = Crypto_Update_process (job);
                if(CryptoJob_retval == E_OK)
                {
                  /*set driver status as busy if job process is success in driver*/
                  CryptoJob_retval = CRYPTO_E_BUSY;
                  /*The below variable value is increased to follow 
                  the job process in Asynchronus mode (state Machine)*/
                  Crypto_job_state[jobref] =3;
                }
                break; // case 2              
              case 3:
                /*...check call back status from crypto driver...*/
                if (Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_OK)
                {
                  Crypto_Callback_status[jobref] = CRYPTO_JOB_IDLE;
                  /*The below variable value is increased to follow 
                  the job process in Asynchronus mode (state Machine)*/
                  Crypto_job_state[jobref] = 4;
                  if (mode_singlecall[jobref] == SINGLE_CALLMODE_SET)
                  {
                    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_FINISH;
                  }
                  else
                  {
                    CryptoJob_retval = E_OK;
                  }
                }
                if(Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_NOT_OK)
                {
                  /*...error occured in crypto driver...*/
                  CryptoJob_retval = E_NOT_OK;
                }
                break; //case 3
              default:
                break; //default
            }
        }

        if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_FINISH)
        {
          switch (Crypto_job_state[jobref]) 
          {
            case 4:
              CryptoJob_retval = Crypto_Finish_process(job);
              if(CryptoJob_retval == E_OK)
              {
                /*set driver status as busy Crypto_Callback_statusif job process is success in driver*/
                CryptoJob_retval = CRYPTO_E_BUSY;
                /*The below variable value is increased to follow 
                  the job process in Asynchronus mode (state Machine)*/
                Crypto_job_state[jobref] =5;
                Crypto_Callback_status[jobref] = CRYPTO_JOB_IDLE;
              }
              break; //case 4
            case 5:
            /*...check Finish service status from crypto driver*/
              if (Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_OK)
              {
                job->state = CRYPTO_JOBSTATE_IDLE;
                /*Init the required variables because Job is successfully finished*/
                Crypto_Callback_status[jobref]   = CRYPTO_JOB_IDLE;
                Crypto_job_state[jobref]  = CRYPTO_JOB_IDLE;
                mode_singlecall[jobref]   = SINGLE_CALLMODE_NOT_SET;
                CryptoJob_retval = E_OK;
                /*Release the Job*/
                //Locked_job_status == 0xFFFFFFFF;
                
              }
              if(Crypto_Callback_status[jobref] == CRYPTO_CALLBACK_NOT_OK)
              {
                /*...error occured in crypto driver...*/
                CryptoJob_retval = E_NOT_OK;
              }
              break; //case 5
            default:
              break; //default
          }
        }
    if(CryptoJob_retval == (uint8) E_NOT_OK )
    {
      job->state = CRYPTO_JOBSTATE_IDLE;
      mode_singlecall[jobref] = SINGLE_CALLMODE_NOT_SET;
      Crypto_job_state[jobref]  = CRYPTO_JOB_IDLE;
    }
  }
  return CryptoJob_retval;
}


LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Start_process(P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  Std_ReturnType Flret_value=E_NOT_OK;
  Csm_ReturnType start_ret_value = CSM_E_NOT_OK;
  Locked_job_status = job->jobInfo->jobId;

  LOCAL uint8 job_priority = 1;

  //KeyID_map = (uint8)(job->jobPrimitiveInfo.cryIfKeyId);
  //KeyID_map = (uint8)(job->jobInfo->jobId);
  KeyID_map = (uint8)(job->jobInfo->jobId);
  crpto_KeyID.length = 8;
  crpto_KeyID.data = (uint32)crypto_Key[KeyID_map].RefOfKey;
/*...Process the requested crypto service...*/
  switch (job->jobPrimitiveInfo->primitiveInfo->service) 
  {
#if (CSM_HASH_API == STD_ON)
    case CRYPTO_HASH:
      /*...Hash Calculation using SHA256*/
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_SHA2_256)
      {
        /*invoked CRY_SHE API*/
        start_ret_value = Crypto_HashCalcStart(&job_priority); 
      }
    break;
#endif
#if (CSM_MACGENERATE_API == STD_ON)
    case CRYPTO_MACGENERATE:
      if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
            (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
      {
          /*invoked CRY_SHE API*/
          start_ret_value = Crypto_She_MacGenerateStart(&job_priority, &KeyID);

      }
    break;
#endif
#if (CSM_MACVERIFY_API == STD_ON)
      case CRYPTO_MACVERIFY:
        /*...Mac Verify using CMAC...*/
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
                (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
        {
          /*invoked CRY_SHE API*/
          start_ret_value = Crypto_MacVerifyStart(&job_priority, &KeyID);
        }
      break;
#endif
#if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON))
      case CRYPTO_ENCRYPT:
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
          (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
        {
          //start_ret_value = Crypto_She_SymEncryptStart(&job_priority, KeyID, &l_CBC_IvData_U8A[0], l_CBC_IvDataLen);     
        }
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
                (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
        {
          start_ret_value = Crypto_She_SymBlockEncryptStart(&job_priority,  &KeyID);
        }
      break;
#endif /* #if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON)) */        
#if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))  
      case CRYPTO_DECRYPT:        
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
                    (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
        {
          start_ret_value = Crypto_SymDecryptStart(&job_priority, KeyID_u8, 
                                &l_CBC_IvData_U8A[0], l_CBC_IvDataLen);
        }
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES) &&
                    (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
        {
          start_ret_value = Crypto_SymBlockDecryptStart(&job_priority, KeyID_u8);
        }    
      break;
#endif     /* #if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))   */  
#if (CSM_SYM_KEY_EXTRACT_API == STD_ON)
      case CRYPTO_KEYSETVALID:
        if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_NOT_SET)&&
                (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_NOT_SET))
        {
          if(l_keyLength_U32 != 0u)
          {
            start_ret_value = Crypto_SymKeyExtractStart(&job_priority);
          }
          else
          {
            start_ret_value = CSM_E_OK;
          }          
        }
      break;
#endif
      default: 
      break;
  }
  if(start_ret_value == CSM_E_OK)
  {
    Flret_value = E_OK;
  }
return Flret_value;
}

LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Update_process(
                  P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
 Std_ReturnType fl_ret_value=E_NOT_OK;
 Csm_ReturnType update_ret_value = CSM_E_NOT_OK;
/*...Process the requested crypto service...*/
    switch (job->jobPrimitiveInfo->primitiveInfo->service) 
    {
#if (CSM_HASH_API == STD_ON)
#if 0
        case CRYPTO_HASH:
        /*...Hash Calculation using SHA256*/
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_SHA2_256)
            {
                /*invoked CRY_SHE API*/
                update_ret_value = Crypto_HashCalcUpdate (job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength ); 
            }
        break;
#endif 
#endif
#if (CSM_MACGENERATE_API == STD_ON)
        case CRYPTO_MACGENERATE:
            /*...Mac Generation using SIPHASH_2_4*/
            if((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
            (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
            {
              /*invoked CRY_SHE API*/
                update_ret_value = Crypto_She_MacGenerateUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength);
            }
        break;
#endif
#if (CSM_MACVERIFY_API == STD_ON)
        case CRYPTO_MACVERIFY:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
            {
              /*invoked CRY_SHE API*/
                update_ret_value =  Crypto_MacVerifyUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength);
            }
        break;
#endif
#if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON))
        case CRYPTO_ENCRYPT:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
            {
              /*invoked CRY_SHE API*/
                //update_ret_value =  Crypto_She_SymEncryptUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
            }
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
            {
              /*invoked CRY_SHE API*/
                update_ret_value =  Crypto_She_SymBlockEncryptUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
            }
        break;
#endif
#if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON)) 
        case CRYPTO_DECRYPT:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
            {
              /*invoked CRY_SHE API*/
                update_ret_value =  Crypto_SymDecryptUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
            }
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
            {
              /*invoked CRY_SHE API*/
                update_ret_value =  Crypto_SymBlockDecryptUpdate(job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
            }
        break;
#endif
#if (CSM_SYM_KEY_EXTRACT_API == STD_ON)
        case CRYPTO_KEYSETVALID:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_NOT_SET)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_NOT_SET))
            {
              /*invoked CRY_SHE API*/
              if(l_keyLength_U32 != 0u)
              {
                update_ret_value =  Crypto_SymKeyExtractUpdate(&l_key_buffer_U8A[0], l_keyLength_U32);
              }
              else
              {
                update_ret_value = CSM_E_OK;
              }  
            }
        break;
#endif
        default: 
        break;
    }
    if(update_ret_value == CSM_E_OK)
    {
      fl_ret_value = E_OK;
    }
return fl_ret_value;
}
LOCAL FUNC(Std_ReturnType, CRY_CODE) Crypto_Finish_process(
                  P2VAR(Crypto_JobType, AUTOMATIC, CRY_APPL_DATA) job)
{
  Std_ReturnType fl_retVal=E_NOT_OK; 
  Csm_ReturnType finish_ret_value=CSM_E_NOT_OK;

  //LOCAL uint8 job_priority = (uint8)job->jobInfo->jobPriority;
  LOCAL uint8 job_priority = 1;
  KeyID_map = (uint8)(job->jobInfo->jobId);
  crpto_KeyID.length = 8;
  crpto_KeyID.data = crypto_Key[KeyID_map].RefOfKey;
  uint8 Resuilt_S1 = 0;
/*...Process the requested crypto service...*/
    switch (job->jobPrimitiveInfo->primitiveInfo->service) 
    {
#if (CSM_HASH_API == STD_ON)
        case CRYPTO_HASH:
        /*...Hash Calculation using SHA256*/
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_SHA2_256)
            {
                /*invoked CRY_SHE API*/
                finish_ret_value = Crypto_HashCalcFinish(job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr,TRUE);  
            }
        break;
#endif
#if (CSM_MACGENERATE_API == STD_ON)
        case CRYPTO_MACGENERATE:
            /*...Mac Generation using AES_CMAC*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
            (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
            {
                /*invoked CRY_SHE API*/
                //crpto_KeyID.data = 1;
                //finish_ret_value = Crypto_She_MacGenerateFinish(job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr,TRUE);
                Crypto_She_MacGenerate_S(&job_priority, &crpto_KeyID, job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr, (boolean)Resuilt_S1);
            }
        break;
#endif
#if (CSM_MACVERIFY_API == STD_ON)
         case CRYPTO_MACVERIFY:
         /*...Mac Verify using AES_CMAC...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CMAC))
            {
                /*invoked CRY_SHE API*/
                finish_ret_value = Crypto_MacVerifyFinish((uint8 *)job->jobPrimitiveInputOutput.secondaryInputPtr,job->jobPrimitiveInputOutput.secondaryInputLength,
                                                                                 (uint8 *)job->jobPrimitiveInputOutput.verifyPtr);
            }
        break;
#endif
#if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON))
        case CRYPTO_ENCRYPT:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
            {
              //crpto_KeyID.data = 1;
              /*invoked CRY_SHE API*/
                //finish_ret_value =  Crypto_She_SymEncryptFinish(job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
                //finish_ret_value = Crypto_She_SymEncrypt_S(job_priority, crpto_KeyID, (const uint8*)initVector, sizeof(initVector), job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr, fl_padding_u8);
                finish_ret_value = Crypto_She_SymEncrypt_S(&job_priority, &crpto_KeyID, (const uint8*)initVector, sizeof(initVector), job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr, fl_padding_u8);
                (void)memcpy(&Cipher2[0],job->jobPrimitiveInputOutput.outputPtr,16);
            }
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
            {
              /*invoked CRY_SHE API*/
                //finish_ret_value = Crypto_SymBlockEncryptFinish();
                crpto_KeyID.data = 1;
                Crypto_She_SymBlockEncrypt_S(&job_priority, &crpto_KeyID, job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr, fl_padding_u8);
                (void)memcpy(&Cipher2[0],job->jobPrimitiveInputOutput.outputPtr,16);
            }
        break;
#endif
#if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))  
        case CRYPTO_DECRYPT:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC))
            {
              /*invoked CRY_SHE API*/
                finish_ret_value =  Crypto_SymDecryptFinish(job->jobPrimitiveInputOutput.outputPtr,job->jobPrimitiveInputOutput.outputLengthPtr);
            }
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB))
            {
              /*invoked CRY_SHE API*/
                finish_ret_value =  Crypto_SymBlockDecryptFinish();
            }
        break;
#endif
#if (CSM_SYM_KEY_EXTRACT_API == STD_ON)
        case CRYPTO_KEYSETVALID:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_NOT_SET)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_NOT_SET))
            {
              /*invoked CRY_SHE API*/ /* Need to change the parameter type in csm_types.h*/
              if(l_keyLength_U32 != 0u)
              {
                finish_ret_value =  Crypto_SymKeyExtractFinish(KeyID_u8);
                l_keyLength_U32 = 0u;
              }
              else
              {
                finish_ret_value = CSM_E_OK;
              }              
            }
        break;
#endif
        case CRYPTO_RANDOMGENERATE:
         /*...Mac Verify using SIPHASH_2_4...*/
            if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_RNG)&&
             (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_NOT_SET))
            {
              /*invoked CRY_SHE API*/
              finish_ret_value =  Crypto_RandGen4Dot3CSM(&job_priority,job->jobPrimitiveInputOutput.outputPtr,*(job->jobPrimitiveInputOutput.outputLengthPtr));
            }
        break;
        default: 
        break;
    }
    if(finish_ret_value == CSM_E_OK)
    {
       fl_retVal = E_OK;
    }
return fl_retVal;
}
/*=============================================[SANITY CHECK]==================================================*/

LOCAL FUNC(Std_ReturnType, CRY_CODE) crypto_precheck(
                   P2VAR(Crypto_JobType,AUTOMATIC,CRY_APPL_DATA) job)
{
  Std_ReturnType errorId = CRYPTO_E_NO_ERROR;

  /* check init condition of driver */
  if(CRYPTO_INIT != Crypto_IsInitialized)
  {
    errorId = CRYPTO_E_UNINIT;
  }
#if 0  
  else if(job->jobInfo->jobId == CryptoJobId_RNG)
  {
    errorId = CRYPTO_E_NO_ERROR;
  }
   /*Length check for hash request*/
  else if ((HASH_MAX_SUPPORT_LENGTH <job->jobPrimitiveInputOutput.inputLength) && (job->jobPrimitiveInfo->primitiveInfo->service==CRYPTO_HASH))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  /* Check for null pointers */
  else if ((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && ((job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_UPDATE) || (job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_SINGLECALL)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* Check job range */
  else if (job->jobInfo->jobId >= TOTAL_NO_4dot2CSMJOB)
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
#endif
  return errorId;
}


/*=============================================[HASH CALCULATION APIs]===============================================*/

#if 0

FUNC(void, CRY_CODE) HashCalc_callback(Csm_ReturnType Result)
{
  if((cryptoqueuejob != NULL_PTR) && (cryptoqueuejob->jobInfo->jobId < Totalno4dot2CryptoJob))
  {
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[cryptoqueuejob->jobInfo->jobId]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[cryptoqueuejob->jobInfo->jobId] = CRYPTO_CALLBACK_NOT_OK;
    }
  }
}
#endif 

/*============================================[CRYPTO RSA VERIFY APIs]=========================================*/

//#define FUNC(void, CRY_CODE) void  // fix for klockwork Warning: ERROR

FUNC(void, CRY_CODE) CryptoDrv_Init(void)
{
  Crypto_IsInitialized = CRYPTO_INIT;
  cryptoqueuejob = NULL_PTR;
  /* unlocking the job variable with maximum value */
      Locked_job_status = 0xFFFFFFFFUL;
  Crypto_Internal_Init();
}

FUNC(void, CRY_CODE) Crypto_GetVersionInfo (
              P2VAR (Std_VersionInfoType, AUTOMATIC, CRY_APPL_DATA) versioninfo)
{
  versioninfo->vendorID = VENDOR_ID;
  versioninfo->moduleID = MODULE_ID;
  versioninfo->sw_major_version = MAJOR_VERSION;
  versioninfo->sw_minor_version = MINOR_VERSION;
  versioninfo->sw_patch_version = PATCH_VERSION;
}

FUNC(void,CRY_CODE)Crypto_MainFunction(void) 
{

#if TESTING_ENABLED 
    Crypto_Task();
#endif /*TESTING_ENABLED*/
  uint32 objectId = 0;
  Crypto_JobType * job = cryptoqueuejob; 
  /* Check init condition */
  if (CRYPTO_INIT == Crypto_IsInitialized)
  {
    /* Check job is valid */
    if (job != NULL_PTR )
    {
      /* Invoked APIs Periodically from CRY_SHE depends on processing Job */
      if(l_Crypto_main_retVal == CRYPTO_E_BUSY)
      {
        switch (job->jobPrimitiveInfo->primitiveInfo->service) 
        {         
#if (CSM_HASH_API == STD_ON)
          case CRYPTO_HASH:
            Crypto_HashCalcMainFunction();
          break;
#endif
#if (CSM_MACGENERATE_API == STD_ON)        
          case CRYPTO_MACGENERATE:
            Crypto_She_MacGenerateMainFunction();
          break;
#endif
#if (CSM_MACVERIFY_API == STD_ON)
          case CRYPTO_MACVERIFY:
            Crypto_MacVerifyMainFunction();
          break;
#endif
#if (CSM_RANDOMGENERATE_API == STD_ON)
          case CRYPTO_RANDOMGENERATE:
            //Crypto_RandomGenerateMainFunction();
            Crypto_RandomGen4dot3MainFunction();
          break;
#endif
#if (CSM_RANDOMSEED_API == STD_ON)
          case CRYPTO_RANDOMSEED:
            Crypto_RandomSeedMainFunction();
          break;
#endif
#if ((CSM_ENCRYPT_API == STD_ON) ||  (CSM_SYM_BLOCK_ENCRYPT_API == STD_ON))
          case CRYPTO_ENCRYPT:
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC)
            {
              Crypto_She_SymEncryptMainFunction();
            }
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB)
            {
              Crypto_She_SymBlockEncryptMainFunction();
            }
          break;
#endif
#if ((CSM_DECRYPT_API == STD_ON) || (CSM_SYM_BLOCK_DECRYPT_API == STD_ON))
          case CRYPTO_DECRYPT:
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC)
            {
              Crypto_SymDecryptMainFunction();
            }
            if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_ECB)
            {
              Crypto_SymBlockDecryptMainFunction();
            }
          break;
#endif
#if (CSM_SYM_KEY_EXTRACT_API == STD_ON)
          case CRYPTO_KEYSETVALID:
            Crypto_SymKeyExtractMainFunction();
          break; 
#endif            
          default:
          break;
        }
      }
      /* Process the service request*/
      l_Crypto_main_retVal = Crypto_ProcessJobService(objectId, job);
      /*Depends on job process response make the queue is availble for next job*/
      if(l_Crypto_main_retVal != CRYPTO_E_BUSY)
      {
      /* Callback Notification*/
        CryIf_CallbackNotification(job, l_Crypto_main_retVal);        
        /*job is removed in queue buffer */
        cryptoqueuejob = NULL_PTR;
        Crypto_Callback_status[job->jobInfo->jobId] = CRYPTO_JOB_IDLE;
        if(job->state != CRYPTO_JOBSTATE_ACTIVE)
        {
          /*unlock the job with Maximum value*/
          Locked_job_status = 0xFFFFFFFF;
        }   
      }
    }
  }//vHsmIpc_HostManager_PeriodicCheck();
  vHsmDmnMgr_MainFunction();
}


FUNC(void, CRY_CODE) Crypto_CMacGen_callback(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACGEN]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACGEN] = CRYPTO_CALLBACK_NOT_OK;
    }
}

FUNC(void, CRY_CODE) Crypto_HmacGen_callback(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACGEN]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACGEN] = CRYPTO_CALLBACK_NOT_OK;
    }
}

FUNC(void, CRY_CODE) Crypto_CMacVerify_callback(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACVERIFY]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACVERIFY] = CRYPTO_CALLBACK_NOT_OK;
    }
}

#if 0
FUNC(void, CRY_CODE) HashCalc_callback(Csm_ReturnType Result)
{
   if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACVERIFY]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_AES_CMACVERIFY] = CRYPTO_CALLBACK_NOT_OK;
    }
}
#endif


FUNC(void, CRY_CODE) Crypto_SymKeyExtractCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMKEYEXTRACT]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMKEYEXTRACT] = CRYPTO_CALLBACK_NOT_OK;
    }
}

FUNC(void, CRY_CODE) Crypto_RandomCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_RNG_GEN] = CRYPTO_CALLBACK_OK;
    }
    else
    {
        Crypto_Callback_status[CryptoJobId_RNG_GEN] = CRYPTO_CALLBACK_NOT_OK;
    }

}


FUNC(void, CRY_CODE) Crypto_SymBlockDecryptCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMBLK_DECRYPT]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMBLK_DECRYPT] = CRYPTO_CALLBACK_NOT_OK;
    }
}

FUNC(void, CRY_CODE) Crypto_SymBlockEncryptCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMBLK_ENCRYPT]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_SYMBLK_ENCRYPT] = CRYPTO_CALLBACK_NOT_OK;
    }
}

#if 0
FUNC(void, CRY_CODE) Crypto_SymDecryptCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_CBC_DECRYPT]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_CBC_DECRYPT] = CRYPTO_CALLBACK_NOT_OK;
    }
}

FUNC(void, CRY_CODE) Crypto_SymEncryptCallbackNotification(Csm_ReturnType Result)
{
    if (CSM_E_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_CBC_ENCRYPT]= CRYPTO_CALLBACK_OK;
    }
    else if (CSM_E_NOT_OK == Result)
    {
        Crypto_Callback_status[CryptoJobId_CBC_ENCRYPT] = CRYPTO_CALLBACK_NOT_OK;
    }
}
#endif


void Csm_KeyservicefinishNotification(Csm_ReturnType result,uint8 *resultptr)
{

}


void Csm_KeyCallbackNotification(Csm_ReturnType result)
{
}
/*EOL*/
