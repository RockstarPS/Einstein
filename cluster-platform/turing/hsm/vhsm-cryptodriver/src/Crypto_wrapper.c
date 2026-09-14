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
 * \file Crypto_wrapper.c
 *
 * \brief
 * Dispatch the crpto services in M7 from CSM
 *
 * \details description
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
 *          Malarvizhi Marimuthu     | mmarimu2  | VTSC, Chennai, India
 *          Baliga Baskaran          | bbaskara  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
/*.......Include files.......*/
#include "Crypto_wrapper.h"
#include "Crypto_Cfg.h"
/*........Global/static Variables.......*/
Crypto_JobType * queuejob; //!< Variable holds the current running job

/* Variable stores the CRYSHE callback ststus using JOB ID*/
static uint8 Callback4dot3_status [TotalnoCryptoJob] = {CRYPTO4DOT3_JOB_IDLE};

/* Variable stores the Running JOB ID*/
static uint32 Locked_job4dot3_status = 0xFFFFFFFFU;

/* Variable stores the Cryto initialization status*/
static uint8 Crypto4dot3_IsInitialized = CRYPTO4DOT3_UNINIT;

/*Variable is used to set the flag for Single call mode*/
static uint8 mode4dot3_singlecall[TotalnoCryptoJob] = {SINGLE_CALLMODE_NOT_SET};

/*variable is used to update the job status to follow the job dispatch*/
static uint8 Crypto4dot3_job_state[TotalnoCryptoJob] = {CRYPTO4DOT3_JOB_IDLE};

/*........static APIs.......*/

FUNC(void,CRY_CODE) Cry_Hsm_HashCalcMainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_EcdsaVerifyMainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_SiphashMacGenMainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_VKMS_MainFunction(void);
FUNC(void,CRY_CODE) Cry_vkms_MacGenerateMainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_SiphashMacVerMainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_VKMS_MainFunction(void);
FUNC(void,CRY_CODE) Cry_Hsm_SecureDebugMainFunction(void);
FUNC(void, CRY_CODE) CryIf4dot3_CallbackNotification(Crypto_JobType *jobId, Std_ReturnType result);


/*....This function Process the job service as start, update and finish.....*/
static Std_ReturnType Crypto4dot3_ProcessJobService(Crypto_JobType * job) ;

/* ...This function verifies the arguments of Job....*/
static Std_ReturnType crypto4dot3_precheck(Crypto_JobType * job);

/* ..This function invoke the CRY-SHE APIs to do the start process of the cryto job ..*/
Std_ReturnType Crypto4dot3_Start_process (Crypto_JobType * job);

/* ..This function invoke the CRY-SHE APIs to do the update process of the cryto job..*/
Std_ReturnType Crypto4dot3_Update_process (Crypto_JobType * job);

/* ..This function invoke the CRY-SHE APIs to do the start process of the cryto job..*/
Std_ReturnType Crypto4dot3_Finish_process (Crypto_JobType * job);

extern Csm_ReturnType Crypto_RandGen4Dot3CSM(P2CONST(void, AUTOMATIC, CRY_APPL_DATA) cfgPtr, P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) resultPtr,
                  uint32 resultLength_U32);
/**
 *  Crypto4dot3_init
 *
 * This function initializes the module. It has to be called to init this module
 */
void Crypto4dot3_init(void)
{
      Crypto4dot3_IsInitialized = CRYPTO4DOT3_INIT;
      queuejob = NULL_PTR;
      /*unlock the locked job variable with Maximum value*/
      Locked_job4dot3_status = 0xFFFFFFFFUL;
}

/*....Periodically invoked API....*/
/**
 *  Crypto4dot3_MainFunction
 *
 * This function is used to track the state machine with CRY-SHE execution
 * Used to transfer crypto job data from CSM4.3  to CRYSHE and getback the response from CRYSHE
 *
 */
void Crypto4dot3_MainFunction(void)
{
  static Std_ReturnType main_retVal = E_NOT_OK;
  Crypto_JobType * job = queuejob;
  /* Check init condition */
  if (CRYPTO4DOT3_INIT == Crypto4dot3_IsInitialized)
  {
    /* Check job is valid */
    if (job != NULL_PTR )
    {
      /* Invoked APIs Periodically from CRY_SHE depends on processing Job */
      if(main_retVal == CRYPTO_E_BUSY)
      {
        switch (job->jobPrimitiveInfo->primitiveInfo->service)
        {
            case CRYPTO_HASH:
              Cry_Hsm_HashCalcMainFunction();
            break;
            case CRYPTO_SIGNATUREVERIFY:
              Cry_Hsm_EcdsaVerifyMainFunction();
            break;
            case CRYPTO_MACGENERATE:
                if(job->jobInfo->jobId == CryptoJobId_SIPHASH_2_4_MACGEN)
                {
                    Cry_Hsm_SiphashMacGenMainFunction();
                }
                else if((job->jobInfo->jobId >= CryptoJobId_VKMS_getVerificationHash)
                        && (job->jobInfo->jobId <= CryptoJobId_VKMS_getPssHash))
                {
                   Cry_Hsm_VKMS_MainFunction();
                }
                else if(job->jobInfo->jobId == CryptoJobId_VKMS_MacGenerate)
                {
                   Cry_vkms_MacGenerateMainFunction();
                }
                else
                {
                  main_retVal = E_NOT_OK;
                }
            break;
            case CRYPTO_MACVERIFY:
              Cry_Hsm_SiphashMacVerMainFunction();
            break;
            case CRYPTO_DECRYPT:
              Cry_Hsm_VKMS_MainFunction();
            break;
            case CRYPTO_ENCRYPT:
              Cry_Hsm_VKMS_MainFunction();
            break;
            default:
              //main_retVal = E_NOT_OK;
            break;
        }
      }

      /* Process the service request*/
      main_retVal = Crypto4dot3_ProcessJobService(job);
      /* Callback Notification*/
      /*Depends on job process response make the queue is availble for next job*/
      if(main_retVal != CRYPTO_E_BUSY)
      {
          CryIf4dot3_CallbackNotification(job, main_retVal);
        /*job is removed in queue buffer */
        queuejob = NULL_PTR;
        if(job->state != CRYPTO_JOBSTATE_ACTIVE)
        {
          /*unlock the job with Maximum value*/
          Locked_job4dot3_status = 0xFFFFFFFFUL;
        }
      }
    }
    Cry_Hsm_VKMS_MainFunction();
  }
  Cry_Hsm_SecureDebugMainFunction();
}
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
Std_ReturnType Crypto4dot3_ProcessJob(uint32 objectId, Crypto_JobType * job)
{
  Std_ReturnType retVal = E_OK;
#if (CRYPTO_DEV_ERROR_REPORT == STD_ON)
  Std_ReturnType ret_E_val = CRYPTO_E_NO_ERROR;
#endif
  if(TotalnoCryptoChannel <= objectId)
  {
#if (CRYPTO_DEV_ERROR_REPORT == STD_ON)
    ret_E_val = CRYPTO_E_PARAM_HANDLE;
#endif
    retVal = E_NOT_OK;
  }
  else if(CRYPTO_KEYSETVALID < job->jobPrimitiveInfo->primitiveInfo->service)
  {
#if (CRYPTO_DEV_ERROR_REPORT == STD_ON)
    ret_E_val = CRYPTO_E_PARAM_HANDLE;
#endif
    retVal = E_NOT_OK;
  }
  else if((job!=NULL_PTR) && (crypto4dot3_precheck(job) == CRYPTO_WRAPPER_E_NO_ERROR))
  { 
      /* Process synchronous job */
      if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC)
      {
        if (job->jobInfo->jobId == CryptoJobId_RNG)
        {
          static uint8 rng_priority =1;
          retVal = (uint8)Crypto_RandGen4Dot3CSM(&rng_priority , job->jobPrimitiveInputOutput.outputPtr, *(job->jobPrimitiveInputOutput.outputLengthPtr));
        }
#ifdef SIPHASH_MAC_VERIFY_SYNC_JOB_SUPPORT_ENABLE
        else if (job->jobInfo->jobId == CryptoJobId_SIPHASH_2_4_MACVerify)
        {
                /*invoked CRY_SHE API*/
          retVal = (uint8)Cry_Hsm_SiphashMacVerification((uint8 *)job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,(uint8 *)job->jobPrimitiveInputOutput.secondaryInputPtr,
                                                                  job->jobPrimitiveInputOutput.secondaryInputLength ,(uint8 *)job->jobPrimitiveInputOutput.verifyPtr);
        }
#endif
#ifdef SIPHASH_MAC_GEN_SYNC_JOB_SUPPORT_ENABLE
        else if (job->jobInfo->jobId == CryptoJobId_SIPHASH_2_4_MACGEN)
        {
                  /*invoked CRY_SHE API*/
          retVal =(uint8)Cry_Hsm_SiphashMacGenerate((uint8 *)job->jobPrimitiveInputOutput.inputPtr,job->jobPrimitiveInputOutput.inputLength,
                 job->jobPrimitiveInputOutput.outputPtr,*(job->jobPrimitiveInputOutput.outputLengthPtr));

        }
#endif
        else
        {
          /* Other synchronous Jobs are not suppoted by External Interface*/
          retVal = E_NOT_OK;
        }
      }
      /* process asynchronous job*/
      else
      {
        /*Set job in queue depends on already occupied job*/
        retVal = CRYPTO_E_QUEUE_FULL;
        if (queuejob == NULL_PTR)
        {
          if ((Locked_job4dot3_status == 0xFFFFFFFFU)|| (Locked_job4dot3_status == job->jobInfo->jobId ))
          {
            /*job is set in queue*/
            queuejob = job;
            retVal = E_OK;
          }
        }
      }

  }
  else
  {
    retVal = E_NOT_OK;
  }
#if (CRYPTO_DEV_ERROR_REPORT == STD_ON)
  if(CRYPTO_E_NO_ERROR != ret_E_val)
  {
    CRYPTO_DET_REPORTERROR(CRYPTO_PROCESSJO_ID,ret_E_val);
  }
#endif
  return retVal;
}
/* Precondition check API */
static Std_ReturnType crypto4dot3_precheck(Crypto_JobType * job)
{
  Std_ReturnType errorId = CRYPTO_WRAPPER_E_NO_ERROR;

  /* Check component init condition */
  if (CRYPTO4DOT3_INIT != Crypto4dot3_IsInitialized)
  {
    errorId = CRYPTO_WRAPPER_E_UNINIT;
  }
  /* Check job range */
  else if ((job == NULL_PTR) || (job->jobInfo->jobId >= TOTAL_NO_CSMJOB))
  {
    errorId = CRYPTO_WRAPPER_E_PARAM_VALUE;
  }
  else
  {
    /* code */
  }
  return errorId;
}
/*Process the job service as start, update and finish*/
static Std_ReturnType Crypto4dot3_ProcessJobService(Crypto_JobType * job)
{
  static Std_ReturnType Job_retval = E_NOT_OK;
  if((job != NULL_PTR) && (job->jobInfo->jobId < TotalnoCryptoJob))
  {
    /*Job has been processed based on mode*/
    if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_SINGLECALL)
    {
         /* Automatic calling of "start - update - finish" in single call mode */
        if (Crypto4dot3_job_state[job->jobInfo->jobId] == (uint8)0)
        {

          if((job->jobInfo->jobId >= CryptoJobId_VKMS_handleDLC_start) && (job->jobInfo->jobId <= CryptoJobId_VKMS_getPssHash))
          {
                job->jobPrimitiveInputOutput.mode    = CRYPTO_OPERATIONMODE_FINISH;
                mode4dot3_singlecall[job->jobInfo->jobId] = SINGLE_CALLMODE_SET;
                Crypto4dot3_job_state[job->jobInfo->jobId] = 4;
          }
          else
          {
              job->jobPrimitiveInputOutput.mode    = CRYPTO_OPERATIONMODE_START;
              mode4dot3_singlecall[job->jobInfo->jobId] = SINGLE_CALLMODE_SET;
          }
        }
    }
    if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_START)
    {
        switch (Crypto4dot3_job_state[job->jobInfo->jobId])
        {
          case 0:
            Job_retval = Crypto4dot3_Start_process(job);
            if(Job_retval == (uint8)E_OK)
            {
              /*set driver status as busy if job process is success in driver*/
              job->state = CRYPTO_JOBSTATE_ACTIVE;
              Job_retval = CRYPTO_E_BUSY;
              /*The below variable value is increased to follow
              the job process in Asynchronus mode (state Machine)*/
              Crypto4dot3_job_state[job->jobInfo->jobId] = 1;
            }
          break;
          case 1:
            /*...check call back status from crypto driver*/
            if(Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_OK)
            {
              Callback4dot3_status[job->jobInfo->jobId] = CRYPTO4DOT3_JOB_IDLE;
              /*The below variable value is increased to follow
              the job process in Asynchronus mode (state Machine)*/
              Crypto4dot3_job_state[job->jobInfo->jobId] =2;
              /* Set the job mode as update if single call mode flag is set*/
              if (mode4dot3_singlecall[job->jobInfo->jobId] == SINGLE_CALLMODE_SET)
              {
                job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_UPDATE;
              }
              else
              {
                Job_retval = E_OK;
              }
            }
            else if(Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_NOT_OK)
            {
              /*...error occured in crypto driver...*/
              Job_retval = E_NOT_OK;
            }
            else
            {
              /* code */
            }
          break;
          default:
            //Job_retval = E_NOT_OK;
          break;
        }
    }
    if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_UPDATE)
    {
        switch (Crypto4dot3_job_state[job->jobInfo->jobId])
        {
           case 2:
            /*...CRY-SHE update api is invoked for Hash job....*/
            if((job->jobInfo->jobId == CryptoJobId_SHA256_Hash) || (job->jobInfo->jobId == CryptoJobId_VKMS_MacGenerate))
            {
              Job_retval = Crypto4dot3_Update_process (job);
              if(Job_retval == (uint8)E_OK)
              {
                /*set driver status as busy if job process is success in driver*/
                Job_retval = CRYPTO_E_BUSY;
                /*The below variable value is increased to follow
                the job process in Asynchronus mode (state Machine)*/
                Crypto4dot3_job_state[job->jobInfo->jobId] = 3;
               }
            }
            else
            {
              /*...Set retvalue as success because Update mode is only availbe for Hash calculation in CRY-SHE*/
              if(mode4dot3_singlecall[job->jobInfo->jobId] == SINGLE_CALLMODE_NOT_SET)
              {
                Job_retval = E_OK;
                Crypto4dot3_job_state[job->jobInfo->jobId] = 4;
              }
              else if(mode4dot3_singlecall[job->jobInfo->jobId] == SINGLE_CALLMODE_SET)
              {
                Job_retval = CRYPTO_E_BUSY;
                Crypto4dot3_job_state[job->jobInfo->jobId] = 4;
                job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_FINISH;
              }
              else
              {
                /* code */
              }

            }
          break;
          case 3:
            /*...check call back status from crypto driver...*/
            if (Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_OK)
            {
              Callback4dot3_status[job->jobInfo->jobId] = CRYPTO4DOT3_JOB_IDLE;
              /*The below variable value is increased to follow
              the job process in Asynchronus mode (state Machine)*/
              Crypto4dot3_job_state[job->jobInfo->jobId] = 4;
              if (mode4dot3_singlecall[job->jobInfo->jobId] == SINGLE_CALLMODE_SET)
              {
                job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_FINISH;
              }
              else
              {
                Job_retval = E_OK;
              }
            }
            else if(Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_NOT_OK)
            {
              /*...error occured in crypto driver...*/
              Job_retval = E_NOT_OK;
            }
            else
            {
              /* code */
            }
          break;
          default:
            //Job_retval = E_NOT_OK;
          break;
        }
    }
    if(job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_FINISH)
    {
        switch (Crypto4dot3_job_state[job->jobInfo->jobId])
        {
          case 4:
            Job_retval = Crypto4dot3_Finish_process (job );
            if(Job_retval == (uint8) E_OK)
            {
              /*set driver status as busy if job process is success in driver*/
              Job_retval = CRYPTO_E_BUSY;
              /*The below variable value is increased to follow
              the job process in Asynchronus mode (state Machine)*/
              Crypto4dot3_job_state[job->jobInfo->jobId] =5;
            }
          break;
          case 5:
            /*...check Finish service status from crypto driver*/
            if (Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_OK)
            {
              job->state = CRYPTO_JOBSTATE_IDLE;
              /*Init the required variables because Job is successfully finished*/
              Callback4dot3_status[job->jobInfo->jobId]   = CRYPTO4DOT3_JOB_IDLE;
              Crypto4dot3_job_state[job->jobInfo->jobId]  = CRYPTO4DOT3_JOB_IDLE;
              mode4dot3_singlecall[job->jobInfo->jobId]   = SINGLE_CALLMODE_NOT_SET;
              Job_retval = E_OK;
            }
            else if(Callback4dot3_status[job->jobInfo->jobId] == CRYSHE_CALLBACK_NOT_OK)
            {
              /*...error occured in crypto driver...*/
              Job_retval = E_NOT_OK;
            }
            else
            {
              /* code */
            }
          break;
          default:
            //Job_retval = E_NOT_OK;
          break;
        }
    }
    if(Job_retval == (uint8) E_NOT_OK )
    {
      job->state = CRYPTO_JOBSTATE_IDLE;
      mode4dot3_singlecall[job->jobInfo->jobId] = SINGLE_CALLMODE_NOT_SET;
      Crypto4dot3_job_state[job->jobInfo->jobId] = 0;
    }
  }
  return Job_retval;
}
