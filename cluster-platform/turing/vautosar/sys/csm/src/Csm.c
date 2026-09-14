/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
#ifndef CSM_C
#define CSM_C
/*****************************************************************************
* @ingroup Crypto Service Manager
* @file Csm.c
* @brief CSM main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Csm.h"
#include "CryIf.h"
//#include "Rte_Csm.h"
#include "Csm_MemMap.h"
#if (CSM_DEV_ERROR_REPORT == STD_ON)
	#include "Det.h"
#endif
/*******************************************************************************
*  Private Macros Definitions                                                 **
*******************************************************************************/
/* ----- Modes ----- */
/* CSM module status: Uninitialized */
#define CSM_UNINIT                              (0x07u)
/* CSM module status:: Initialized */
#define CSM_INIT                                (0xCBu)
/*  Service idle state */
#define CSM_SERVICE_IDLE      (0u)
/*  Service active state */
#define CSM_SERVICE_ACTIVE    (1u)

/*  Callback is idle and must not be notified to RTE. */
#define CSM_CALLBACK_IDLE     (0xFEu)

#define OFFSET_VALUE  		  (1u)
/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/

static uint8 Csm_IsInitialized = CSM_UNINIT;

/******************************************************************************
*  Private Function Definitions                                                *
*******************************************************************************/
static Std_ReturnType Csm_ProcessJob(uint8 queueIdx, Crypto_JobType * job);

static void Csm_JobSort(uint32 queueIdx); 

static Std_ReturnType Csm_PreConditionCheck(uint32 JobId, Crypto_OperationModeType mode,
                         const uint8 * dataPtr, uint32 dataLength);
void Csm_CallbackNotification(Crypto_JobType * job, Std_ReturnType result);
Std_ReturnType Csm_RandomGenerate(uint32 jobId, uint8 * resultPtr,
			uint32 * resultLengthPtr);
void Csm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_DATA) versionInfo);
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"
/*============================================================================
**
** Function Name    :   Csm_PreConditionCheck
**
** Visibility       :   Private
**
** Description      :   This function verifies the arguments of Job
**
** Invocation       :
**
** Inputs           :  uint32 JobId, Crypto_OperationModeType mode,
                       const uint8 * dataPtr,uint32 dataLength
**
** Outputs          : Std_ReturnType errorId
**
** Critical Section :
**
**==========================================================================*/

static Std_ReturnType Csm_PreConditionCheck(uint32 JobId, Crypto_OperationModeType mode,
                                        const uint8 * dataPtr,
                                        uint32 dataLength)
{
	Std_ReturnType errorId = CSM_E_NO_ERROR;

	/* Check component init condition */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/*Length check*/
	if (0ul == dataLength)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	/* Check for null pointers */
	if ((dataPtr == NULL_PTR) && (((uint8)mode & (uint8)CRYPTO_OPERATIONMODE_UPDATE) == (uint8)CRYPTO_OPERATIONMODE_UPDATE))
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/* Check job range */
	else if (JobId >= TOTAL_NO_CSMJOB)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	/* Misra 15.7 Rule */
	else
	{
		/*Do Nothing */ 
	}
	return errorId;
	
} /* Csm_PreConditionCheck */

/*============================================================================
**
** Function Name    :   Csm_ProcessJob
**
** Visibility       :   Private
**
** Description      :   This function process job request
**
** Invocation       :
**
** Inputs           :  uint8 queueIdx:  identifier of the queue
**					  Crypto_JobType * job :Pointer to the configuration of the job
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType Csm_ProcessJob(uint8 queueIdx, Crypto_JobType * job)
{
	Std_ReturnType retVal = E_NOT_OK;
	uint8 enqueuingEnable = 0u;  
	uint32 channelId = 0ul;
	uint8 QueueStateIndex = 0u;
	
	if ((TOTAL_NO_CSMJOB > queueIdx) && (TOTAL_NO_CSMQUEUE > queueIdx))
	{
		QueueStateIndex = (Csm_QueueState[queueIdx].QueueIdxOfQueueState - OFFSET_VALUE);
		channelId = Csm_QueueInfo[queueIdx].ChannelIdOfQueueInfo;	
		
		/* When the job is active the unified CryIf processing function is called */
		if (job->state == CRYPTO_JOBSTATE_ACTIVE)
		{
			/* Call CryIf_ProcessJob() */
			retVal = CryIf_ProcessJob(queueIdx, job);
		}
		else
		{
			/* Determine if queue is empty and call CryIf processing function if so */
			if (Csm_QueueState[queueIdx].QueueIdxOfQueueState == Csm_QueueInfo[queueIdx].QueueStartIdxOfQueueInfo)
			{
				/* Call CryIf_ProcessJob() */
				retVal = CryIf_ProcessJob(channelId, job);

				/* When return value is either BUSY or QUEUE_FULL enqueuing is mandatory */
				if(job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
				{
					/* If crypto is busy or crypto queue full, further processing is required. */
					if ((retVal == CRYPTO_E_BUSY) || (retVal == CRYPTO_E_QUEUE_FULL))
					{
						enqueuingEnable = 1u;
					}
					else
					{
						enqueuingEnable = 0u;
					}
				}
			}
			/* Queue is not empty */
			/* Synchronous job: the job priority is compared with the highest priority in the queue */
			else if ((job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC) && (TOTAL_NO_CSMJOB > queueIdx))
			{
				/* Sort queue if jobs where enqueued since last Csm_MainFunction call */
				if (Csm_QueueState[queueIdx].SortNeededOfQueueState == 1u)
				{
					/* Sort jobs by priority */
					Csm_JobSort(queueIdx);
					Csm_QueueState[queueIdx].SortNeededOfQueueState = 0u;
				}
				/* Call CryIf processing function if job priority is higher than the highest priority in the queue,
				otherwise return busy */

				if ((TOTAL_NO_CSMQUEUE > QueueStateIndex ) &&  (job->jobInfo->jobPriority > (Csm_Queue[QueueStateIndex].jobInfo->jobPriority)))
				{
					/* Call CryIf_ProcessJob() */
					Csm_QueueState[queueIdx].PauseProcessingOfQueueState = 1u;

					retVal = CryIf_ProcessJob(channelId, job);

					Csm_QueueState[queueIdx].PauseProcessingOfQueueState = 0u;
				}
				else
				{
					retVal = CRYPTO_E_BUSY;
				}
			}
			/* Asynchronous job must be queued */
			else
			{
				enqueuingEnable = 1u;
			}

			/* Enqueuing necessary: Enqueue job if queue is not full, otherwise return that queue is full */
			if(enqueuingEnable == 1u)
			{
				if (Csm_QueueState[queueIdx].QueueIdxOfQueueState < (Csm_QueueInfo[queueIdx].QueueEndIdxOfQueueInfo -  Csm_QueueState[queueIdx].ReservedIndexesOfQueueState))
				{
					/* Job needs to be enqueued */
					if (TOTAL_NO_CSMJOB > Csm_QueueState[queueIdx].QueueIdxOfQueueState)
					{
						Csm_Queue[Csm_QueueState[queueIdx].QueueIdxOfQueueState] = *job;
					}
					if (TOTAL_NO_CSMJOB > queueIdx)
					{
						Csm_QueueState[queueIdx].SortNeededOfQueueState = 1u;
						Csm_QueueState[queueIdx].QueueIdxOfQueueState++;
					}
					retVal = E_OK;
				}
				else
				{
					retVal = CRYPTO_E_QUEUE_FULL;
				}
			}
		}
	}
	else
	{
		/* Do Nothing */
	}

	return retVal;
	
} /* Csm_ProcessJob */
/*============================================================================
**
** Function Name    :   Csm_JobSort
**
** Visibility       :   Private
**
** Description      :   This function is sorting given jobs regarding jobPriority
**
** Invocation       :
**
** Inputs           :  uint8 queueIdx:  identifier of the queue
**
** Outputs          : void
**
** Critical Section :
**
**==========================================================================*/
static void Csm_JobSort(uint32 queueIdx)
{
	Crypto_JobType * tempJob = NULL_PTR;
	uint8 startIdx = 0u;
	uint8 i, j = 0u;
	
	if (queueIdx < TOTAL_NO_CSMQUEUE )
	{
		startIdx = Csm_QueueInfo[queueIdx].QueueStartIdxOfQueueInfo;
	}
	
    if (queueIdx < (uint32)TOTAL_NO_CSMQUEUE )
	{
	for (i = (uint8)(startIdx + OFFSET_VALUE); i < Csm_QueueState[queueIdx].QueueIdxOfQueueState; i++)
	{
		tempJob = &Csm_Queue[i];
		for (j = i; j > startIdx; j--)
		{          
			/* compare the priority of current job and next job in buffer.*/
			/* coverity[sensitive_memory_access] : FALSE */
			if ((Csm_Queue[(j - OFFSET_VALUE)]).jobInfo->jobPriority > (tempJob->jobInfo->jobPriority))
			{
				Csm_Queue[j] = (Csm_Queue[(j - OFFSET_VALUE)]);
			}
			else
			{
				break;
			}

		}
		Csm_Queue[j] = *tempJob;
	}
	}
	
} /* Csm_JobSort */

/*****************************************************************************
 *  GLOBAL FUNCTIONS
******************************************************************************/
/*============================================================================
**
** Function Name    :   Csm_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global 
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :  void
**
** Outputs          : void
**
** Critical Section :
**
**==========================================================================*/

void Csm_Init(void)
{
	uint8 errorId = CSM_E_NO_ERROR;
	uint32 index = 0ul;

	/* Check initialization state */
	if (Csm_IsInitialized == (uint8)CSM_INIT)
	{
		errorId = CSM_E_ALREADY_INITIALIZED;
	}
	else
	{
		/* Initialize job input/output buffer */
		for (index = 0ul; index < TOTAL_NO_CSMJOB; index++)
		{
			Csm_Job[index].state = CRYPTO_JOBSTATE_IDLE;
			Csm_Job[index].jobPrimitiveInputOutput.inputPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.inputLength = 0u;
			Csm_Job[index].jobPrimitiveInputOutput.secondaryInputPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.secondaryInputLength = 0u;
			Csm_Job[index].jobPrimitiveInputOutput.tertiaryInputPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.tertiaryInputLength = 0u;
			Csm_Job[index].jobPrimitiveInputOutput.outputPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.outputLengthPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.secondaryOutputPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.secondaryOutputLengthPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.verifyPtr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.output64Ptr = NULL_PTR;
			Csm_Job[index].jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_START;
			if (TOTAL_NO_CSMJOB > Csm_JobTable[index].JobPrimitiveInfoIdxOfJobTable)
			{
				Csm_Job[index].jobPrimitiveInfo = &Csm_JobPrimitiveInfo[Csm_JobTable[index].JobPrimitiveInfoIdxOfJobTable];
			}
			if (TOTAL_NO_CSMJOB > Csm_JobTable[index].JobInfoIdxOfJobTable)
			{
				Csm_Job[index].jobInfo = &(Csm_JobInfo[Csm_JobTable[index].JobInfoIdxOfJobTable]);
			}
			Csm_Job[index].cryptoKeyId = 0u;
			Csm_Job[index].jobId = Csm_Job[index].jobInfo->jobId;
		}

		/* Init queues */
		for (index = 0ul; index < TOTAL_NO_CSMQUEUE; index++)
		{
			Csm_QueueState[index].QueueIdxOfQueueState = Csm_QueueInfo[index].QueueStartIdxOfQueueInfo;
			Csm_QueueState[index].ReservedIndexesOfQueueState = 0u;
			Csm_QueueState[index].SortNeededOfQueueState = 0u;
			Csm_QueueState[index].PauseProcessingOfQueueState = 0u;
		}
		/* CSM initialized */
		Csm_IsInitialized = CSM_INIT;
	}
	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_INIT_ID, errorId);
		}
	#endif
	
} /* Csm_Init() */

/*============================================================================
**
** Function Name    :   Csm_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os. 
**
** Invocation       :   Os Scheduling.
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :
**
**==========================================================================*/
void Csm_MainFunction(void)
{
	Crypto_JobType * job = NULL_PTR;
	Std_ReturnType retVal = E_NOT_OK;
	uint8 queueIdx = 0u;
	uint8 errorId = CSM_E_NO_ERROR;

	/* Check initialization state */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	else
	{
		/* Loop over configured queues */
		for (queueIdx = 0u; queueIdx < TOTAL_NO_CSMJOB; queueIdx++)
		{
			/* Check if queue has entries */
			if (Csm_QueueState[queueIdx].QueueIdxOfQueueState != Csm_QueueInfo[queueIdx].QueueStartIdxOfQueueInfo)
			{
				/* Sort jobs if needed */
				if (Csm_QueueState[queueIdx].SortNeededOfQueueState == 1u)
				{
					/* Sort jobs by priority */
					Csm_JobSort(queueIdx);
					Csm_QueueState[queueIdx].SortNeededOfQueueState = 0u;
				}
				/* Process job if possible (not paused because of active synchronous request): */
				if (( Csm_QueueState[queueIdx].PauseProcessingOfQueueState) != 1u)
				{
					/* Remove job from queue temporarily (reserve a slot) and pass it to underlying crypto. */
					Csm_QueueState[queueIdx].QueueIdxOfQueueState--;
					Csm_QueueState[queueIdx].ReservedIndexesOfQueueState++;
					if(TOTAL_NO_CSMQUEUE > Csm_QueueState[queueIdx].QueueIdxOfQueueState)
					{
						job = &Csm_Queue[Csm_QueueState[queueIdx].QueueIdxOfQueueState];
					}
					
					retVal = CryIf_ProcessJob(Csm_QueueInfo[queueIdx].ChannelIdOfQueueInfo, job);


					/* If job cannot be processed because of busy driver of full queue, job needs to be enqueued again. */
					if ((job != NULL_PTR) && ((retVal == CRYPTO_E_BUSY) || (retVal == CRYPTO_E_QUEUE_FULL)))
					{
						if(TOTAL_NO_CSMQUEUE > Csm_QueueState[queueIdx].QueueIdxOfQueueState)
						{
							Csm_Queue[Csm_QueueState[queueIdx].QueueIdxOfQueueState] = *job;
						}
						Csm_QueueState[queueIdx].SortNeededOfQueueState = 1u;
						Csm_QueueState[queueIdx].QueueIdxOfQueueState++;
					}
					Csm_QueueState[queueIdx].ReservedIndexesOfQueueState--;
				}
			}
		}
	}
	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_MAINFUNCTION_ID, errorId);
		}
	#endif 
	
} /* Csm_MainFunction */

/*============================================================================
**
** Function Name    :   Csm_CallbackNotification
**
** Visibility       :   Public
**
** Description      :   This function notifies User that a job has finished. 
**
** Invocation       :   
**
** Inputs           : Crypto_JobType * job - a pointer to the job, which has finished.
**					  Std_ReturnType result- E_OK ,E_NOT_OK
**
** Outputs          : void
**
** Critical Section :
**
**==========================================================================*/
void Csm_CallbackNotification(Crypto_JobType * job, Std_ReturnType result)
{
	uint8 errorId = CSM_E_NO_ERROR;
	uint32 JobIndex = 0ul;

	/* Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check for null pointers */
	else if (NULL_PTR == job )
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	else if (job->jobInfo->jobId >= TOTAL_NO_CSMJOB)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		/*call back function*/
		JobIndex = job->jobPrimitiveInfo->callbackId;
		if(TOTAL_NO_CSMJOB > JobIndex)
		{
			Csm_CallbackFunc[JobIndex](job, result);
		}
	}
	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_CALLBACKNOTIFICATION_ID, errorId);
		}
	#endif 
	
} /* Csm_CallbackNotification */
/*============================================================================
**
** Function Name    :   Csm_CancelJob
**
** Visibility       :   Public
**
** Description      :   This function cancels the given job from Queue.
**
** Invocation       :   
**
** Inputs           : jobId,mode
**
** Outputs          : E_OK     -Request successful
**                    E_NOT_OK -Request failed
**
** Critical Section :
**
**==========================================================================*/
#if (CSM_CANCELJOB_API == STD_ON)
Std_ReturnType Csm_CancelJob(uint32 jobId, Crypto_OperationModeType mode)
{
	Std_ReturnType retVal = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * CancelJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;
	boolean isJobQueued = FALSE;
	uint8 idx = 0u;
	uint8 queueSize = 0u;

	/* Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check job range */
	else if (jobId >= TOTAL_NO_CSMJOB)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		CancelJob = &Csm_Job[jobId];
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;

		/* Remove asynchronous job from job queue */
		/* coverity[sensitive_memory_access] : FALSE */
		if (CancelJob->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
		{
			if (TOTAL_NO_CSMJOB > queueInfoIdx)
			{    
				/* coverity[sensitive_memory_access] : FALSE */
				queueSize = Csm_QueueState[queueInfoIdx].QueueIdxOfQueueState;
							
				for (idx = Csm_QueueInfo[queueInfoIdx].QueueStartIdxOfQueueInfo; idx < queueSize; idx++)
				{
					 /* coverity[sensitive_memory_access] : FALSE */
					if (Csm_Queue[idx].jobInfo->jobId == jobId)
					{
						/* Job is queued */
						isJobQueued = TRUE;
						/* Decrease queue index */
						/* coverity[sensitive_memory_access] : FALSE */
						if (Csm_QueueState[queueInfoIdx].QueueIdxOfQueueState > 0u) 
						{
							Csm_QueueState[queueInfoIdx].QueueIdxOfQueueState--;
						}
						else
						{
							#if (CSM_DEV_ERROR_REPORT == STD_ON)
								CSM_DET_REPORTERROR(CSM_RANDOMGENERATE_ID, errorId);
							#endif  
						}
					}
					

					/* Shift remaining jobs to the left */
					if ((isJobQueued == TRUE) && (idx < (queueSize - OFFSET_VALUE)))
					{
						if (TOTAL_NO_CSMJOB - OFFSET_VALUE > idx)
						{
						Csm_Queue[idx] = Csm_Queue[idx + OFFSET_VALUE];
						}
					}
				
				}
			}
		}

		/* If job was queued, call configured callback notification function */
		if (isJobQueued == TRUE)
		{
			Csm_CallbackNotification(CancelJob, CRYPTO_E_JOB_CANCELED);
			retVal = E_OK;
		}
		else
		{
			/* else cancel job in lower layer */
			if(TOTAL_NO_CSMQUEUE > queueInfoIdx)
			{
				/* coverity[sensitive_memory_access] : FALSE */
				retVal = CryIf_CancelJob(Csm_QueueInfo[queueInfoIdx].ChannelIdOfQueueInfo, CancelJob);
			}
		}
	}
	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_CANCELJOB_ID, errorId);
		}
	#endif
	return retVal;
	
} /* Csm_CancelJob */
#endif /* # if (CSM_CANCELJOB_API == STD_ON) */
/* Csm Service Functions */
/*============================================================================
**
** Function Name    :   Csm_Hash
**
** Visibility       :   Public
**
** Description      :   This function is used for the hash computation.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the hash shall be computed.
**			      	   dataLength : number of bytes to be hashed.
**	  				   resultPtr : the pointer to the data where the hash value shall be stored.
**	 					resultLengthPtr :  pointer to store the  output length in bytes
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/
#if (CSM_HASH_API == STD_ON)
Std_ReturnType Csm_Hash(uint32 jobId, Crypto_OperationModeType mode,
                            const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * HashJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
	if (((uint8)mode & (uint8)CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH)
	{
		if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_HASH_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		HashJob = &Csm_Job[jobId];

		HashJob->jobPrimitiveInputOutput.mode = mode;
		HashJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		HashJob->jobPrimitiveInputOutput.inputLength = dataLength;
		HashJob->jobPrimitiveInputOutput.outputPtr = resultPtr;
		HashJob->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
		/* Dispatch job if possible */
		Status = Csm_ProcessJob(queueInfoIdx, HashJob);
	}
	return Status;
	
} /* Csm_Hash() */
#endif /* #if (CSM_HASH_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_Encrypt
**
** Visibility       :   Public
**
** Description      :   This function is used for the encryption.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the encrypt shall be computed.
**			      	   dataLength : number of bytes to be encrypted.
**	  				   resultPtr : the pointer to the data where the encrypt value shall be stored.
**	 				   resultLengthPtr :  pointer to store the  output length in bytes
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/
#if (CSM_ENCRYPT_API == STD_ON)
Std_ReturnType Csm_Encrypt(uint32 jobId, Crypto_OperationModeType mode,
                            const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * EncryptJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
	if (((mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)
		|| ((mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH))
	{
		if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_ENCRYPT_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		EncryptJob = &Csm_Job[jobId];

		EncryptJob->jobPrimitiveInputOutput.mode = mode;
		EncryptJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		EncryptJob->jobPrimitiveInputOutput.inputLength = dataLength;
		EncryptJob->jobPrimitiveInputOutput.outputPtr = resultPtr;
		EncryptJob->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, EncryptJob);
	}
	return Status;
	
}/* Csm_Encrypt */
#endif /* #if (CSM_ENCRYPT_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_Decrypt
**
** Visibility       :   Public
**
** Description      :   This function is used for the Decryption.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the Decrypt shall be computed.
**			      	   dataLength : number of bytes to be Decrypted.
**	  				   resultPtr : the pointer to the data where the Decrypt value shall be stored.
**	 				   resultLengthPtr :  pointer to store the  output length in bytes
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/
#if (CSM_DECRYPT_API == STD_ON)
Std_ReturnType Csm_Decrypt(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * DecryptJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
	if (((mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)
		  || ((mode & CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH))
	{
		if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_DECRYPT_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		DecryptJob = &Csm_Job[jobId];

		DecryptJob->jobPrimitiveInputOutput.mode = mode;
		DecryptJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		DecryptJob->jobPrimitiveInputOutput.inputLength = dataLength;
		DecryptJob->jobPrimitiveInputOutput.outputPtr = resultPtr;
		DecryptJob->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, DecryptJob);
	}
	return Status;
	
} /* Csm_Decrypt */
#endif /* #if CSM_DECRYPT_API */
/*============================================================================
**
** Function Name    :   Csm_MacGenerate
**
** Visibility       :   Public
**
** Description      :   This function is used for the mac computation.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the mac shall be computed.
**			      	   dataLength : data length in bytes.
**	  				   macPtr : the pointer to the data where the mac value shall be stored.
**	 				   macLengthPtr :  pointer to store the  output length in bytes
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/

#if (CSM_MACGENERATE_API == STD_ON)
Std_ReturnType Csm_MacGenerate(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, uint8 * macPtr, uint32 * macLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * MacGenJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
  if ((mode & CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH)
	{
		if ((NULL_PTR == macPtr) || (NULL_PTR == macLengthPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_MACGENERATE_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		MacGenJob = &Csm_Job[jobId];

		MacGenJob->jobPrimitiveInputOutput.mode = mode;
		MacGenJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		MacGenJob->jobPrimitiveInputOutput.inputLength = dataLength;
		MacGenJob->jobPrimitiveInputOutput.outputPtr = macPtr;
		MacGenJob->jobPrimitiveInputOutput.outputLengthPtr = macLengthPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, MacGenJob);
	}
	return Status;
	
}/* Csm_MacGenerate */
#endif/* #if (CSM_MACGENERATE_API == STD_ON) */ 
/*============================================================================
**
** Function Name    :   Csm_MacVerify
**
** Visibility       :   Public
**
** Description      :   This function is used for the mac verfification.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the mac shall be computed.
**			      	   dataLength : number of bytes to be verified.
**	  				   macPtr :   mac value to be verified 
**	 				   macLength :  MAC length in BITS to be verified
**					   verifyPtr  :   pointer to store the result of the MAC verification
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/
#if (CSM_MACVERIFY_API == STD_ON)
Std_ReturnType Csm_MacVerify(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, const uint8 * macPtr, uint32 macLength,
                            Crypto_VerifyResultType * verifyPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * MacVerifyJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
	if (0ul == macLength)
	{
		errorId = CSM_E_PARAM_POINTER;
	}
  if ((mode & CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH)
	{
		if ((NULL_PTR == macPtr) || (NULL_PTR == verifyPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_MACVERIFY_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		MacVerifyJob = &Csm_Job[jobId];

		MacVerifyJob->jobPrimitiveInputOutput.mode = mode;
		MacVerifyJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		MacVerifyJob->jobPrimitiveInputOutput.inputLength = dataLength;
		MacVerifyJob->jobPrimitiveInputOutput.secondaryInputPtr = macPtr;
		MacVerifyJob->jobPrimitiveInputOutput.secondaryInputLength = macLength;
		MacVerifyJob->jobPrimitiveInputOutput.verifyPtr = verifyPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, MacVerifyJob);
	}
	return Status;
	
}/* Csm_MacVerify */
#endif/* #if (CSM_MACVERIFY_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_SignatureGenerate
**
** Visibility       :   Public
**
** Description      :   This function is used for the signature generation.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to the data for which the signature shall be computed.
**			      	   dataLength : number of bytes to sign.
**	  				   resultPtr : the pointer to the data where the signature value shall be stored.
**	 				   resultLengthPtr :  pointer to store the  output length in bytes
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/

#if (CSM_SIGNATUREGENERATE_API == STD_ON)
Std_ReturnType Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, uint8 * resultPtr, 
							uint32 * resultLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * SignGenJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
  if ((mode & CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH)
	{
		if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_SIGNATUREVERIFY_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		SignGenJob = &Csm_Job[jobId];

		SignGenJob->jobPrimitiveInputOutput.mode = mode;
		SignGenJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		SignGenJob->jobPrimitiveInputOutput.inputLength = dataLength;
		SignGenJob->jobPrimitiveInputOutput.outputPtr = resultPtr;
		SignGenJob->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, SignGenJob);
	}
	return Status;
	
}/* Csm_SignatureGenerate */
#endif /* #if (CSM_SIGNATUREGENERATE_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_SignatureVerify
**
** Visibility       :   Public
**
** Description      :   This function is used for the signature verification.
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the job.
**				  	   mode     : Indicates which operation mode(s) to perfom.
**				  	   dataPtr  : pointer to be data verified.
**			      	   dataLength : number of bytes to be verified.
**	  				   signaturePtr :   Signature bytes to be verified 
**	 				   signatureLength :  pointer which hold Signature length in bytes to be **										verified
**					   verifyPtr  :   pointer to store the result of the Signature verification
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
**                    CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
**                    CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
** Critical Section :
**
**==========================================================================*/

#if (CSM_SIGNATUREVERIFY_API == STD_ON)
Std_ReturnType Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, const uint8 * signaturePtr, 
							uint32 signatureLength, Crypto_VerifyResultType * verifyPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * SignVerifyJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,dataPtr,dataLength);
	if (0ul == signatureLength)
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_SIGNATUREVERIFY_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		SignVerifyJob = &Csm_Job[jobId];

		SignVerifyJob->jobPrimitiveInputOutput.mode = mode;
		SignVerifyJob->jobPrimitiveInputOutput.inputPtr = dataPtr;
		SignVerifyJob->jobPrimitiveInputOutput.inputLength = dataLength;
		SignVerifyJob->jobPrimitiveInputOutput.secondaryInputPtr = signaturePtr;
		SignVerifyJob->jobPrimitiveInputOutput.secondaryInputLength = signatureLength;
		SignVerifyJob->jobPrimitiveInputOutput.verifyPtr = verifyPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, SignVerifyJob);
	}
	return Status;
	
}/* Csm_SignatureVerify */
#endif /* #if (CSM_SIGNATUREVERIFY_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeySetValid
**
** Visibility       :   Public
**
** Description      :   Sets the key state of the key identified by keyId to valid
**
** Invocation       :
**
** Inputs           :  keyId 	: identifier of the key
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/

#if (CSM_KEY_API == STD_ON)
Std_ReturnType Csm_KeySetValid(uint32 keyId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;

	/* Check initialization  */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* #20 Check key range */
	else if (keyId >= TOTAL_NO_KEY)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		/* #30 Call of CryIf_KeySetValid function */
		Status = CryIf_KeySetValid(Csm_Key[keyId].CryIfKeyIdOfKey);
	}

	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_KEYSETVALID_ID, errorId);
		}
	#endif
	return Status;
	
}/* Csm_KeySetValid */
#endif /* (CSM_KEY_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_KeyElementSet
**
** Visibility       :   Public
**
** Description      :   Sets the given key element bytes to the key identified by keyId
**
** Invocation       :
**
** Inputs           :  keyId 	: identifier of the key
** 					   keyElementId :identifier of the key element to be written.
** 					   keyPtr   : pointer to the key element bytes to be processed
** 					   keyLength : number of key element bytes.
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/

#if (CSM_KEY_API == STD_ON)
Std_ReturnType Csm_KeyElementSet(uint32 keyId, uint32 keyElementId,
                                  const uint8 * keyPtr, uint32 keyLength)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;

	/* Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check for null pointers */
	else if (NULL_PTR == keyPtr)
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/*  Check key range */
	else if (keyId >= TOTAL_NO_KEY)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		/* #40 Call of CryIf_KeyElementSet function */
		Status = CryIf_KeyElementSet(Csm_Key[keyId].CryIfKeyIdOfKey, keyElementId, keyPtr, keyLength);
	}

	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_KEYELEMENTSET_ID, errorId);
		}
	#endif
	return Status;
	
} /* Csm_KeyElementSet() */
#endif /* #if (CSM_KEY_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_KeyElementGet
**
** Visibility       :   Public
**
** Description      :   Gets the given key element bytes to the key identified by keyId
**
** Invocation       :
**
** Inputs           :  keyId 	: identifier of the key
** 					   keyElementId :identifier of the key element to be read.
** 					   keyPtr   : pointer to store the key element bytes
** 					   keyLength : number of key element bytes.
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/

#if (CSM_KEY_API == STD_ON)
Std_ReturnType Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, uint8 * keyPtr,
                                            uint32 * keyLengthPtr)
{
	Std_ReturnType retVal = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;

	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check for null pointers */
	else if ((NULL_PTR == keyPtr)
	|| (keyLengthPtr == NULL_PTR))
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/* Check key range */
	else if (keyId >= TOTAL_NO_KEY)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		/* Call of CryIf_KeyElementGet function */
		retVal = CryIf_KeyElementGet(Csm_Key[keyId].CryIfKeyIdOfKey, keyElementId, keyPtr, keyLengthPtr);
	}
	#if (CSM_DEV_ERROR_REPORT == STD_ON)
		if (errorId != CSM_E_NO_ERROR)
		{
			CSM_DET_REPORTERROR(CSM_KEYELEMENTGET_ID, errorId);
		}
	#endif
	return retVal;
	
} /* Csm_KeyElementGet */
#endif /* #if (CSM_KEY_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_RandomGenerate
**
** Visibility       :   Public
**
** Description      :   This function is used for generation of random numbers
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the Job
** 					   resultPtr :Pointer stored the generated random number. 
** 					   resultLengthPtr   : pointer to store the length 
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_RANDOMGENERATE_API == STD_ON)
Std_ReturnType Csm_RandomGenerate(uint32 jobId, uint8 * resultPtr,
			uint32 * resultLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * RNGJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/*  Check for null pointers */
	else if ((NULL_PTR == resultPtr)
	|| (NULL_PTR == resultLengthPtr))
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/*  Check job range */
	else if (jobId >= TOTAL_NO_CSMJOB )
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		RNGJob = &Csm_Job[jobId];

		RNGJob->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
		RNGJob->jobPrimitiveInputOutput.outputPtr = resultPtr;
		RNGJob->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr;
		/* Dispatch job if possible */
		Status = Csm_ProcessJob(queueInfoIdx, RNGJob);
	}

	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_RANDOMGENERATE_ID, errorId);
		#endif  
	}
	return Status;
	
} /* Csm_RandomGenerate */
#endif /* #if (CSM_RANDOMGENERATE_API == STD_ON) */

#if (CSM_GETVERSIONINFO_ENABLED == STD_ON)
/* !LINKSTO CSM0705, 1
 */
void Csm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_DATA) versionInfo)
{
  if ( NULL_PTR != versionInfo )
  {
    /* !LINKSTO CSM0706, 1 */
    versionInfo->vendorID         = (uint16) CSM_VENDOR_ID;
    versionInfo->moduleID         = (uint16) CSM_MODULE_ID;
    versionInfo->sw_major_version = (uint8) CSM_SW_MAJOR_VERSION ;
    versionInfo->sw_minor_version = (uint8) CSM_SW_MINOR_VERSION ;
    versionInfo->sw_patch_version = (uint8) CSM_SW_PATCH_VERSION ;
  }
}
#endif
/*============================================================================
**
** Function Name    :   Csm_AEADEncrypt
**
** Visibility       :   Public
**
** Description      :   This function is used to perform a AEAD encryption 
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the Job
** 					   mode     : Which mode to perform the operation. 
** 					   plaintextPtr   : pointer to data
** 					   plaintextLength : Pointer to length of the data. 
** 					   associatedDataPtr   : Pointer to the associated data. 
** 					   associatedDataLength : Length of associated Length. 
** 					   ciphertextPtr   : pointer to store the output data.
** 					   ciphertextLengthPtr   : pointer to store output data length.
** 					   tagPtr : Pointer store the generated mac. 
** 					   tagLengthPtr   : pointer to store the length of the generated mac. 
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_AEADENCRYPT_API == STD_ON)
Std_ReturnType Csm_AEADEncrypt(uint32 jobId,Crypto_OperationModeType mode,
	const uint8 * plaintextPtr,uint32 plaintextLength,
	const uint8 * associatedDataPtr,uint32 associatedDataLength,
	uint8 * ciphertextPtr,uint32 * ciphertextLengthPtr,uint8 * tagPtr,
	uint32 * tagLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * AEADEncryptJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;
	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,plaintextPtr,plaintextLength);
	if (((mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)
		|| ((mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH))
	{
		if ((NULL_PTR == ciphertextPtr) || (NULL_PTR == ciphertextLengthPtr) || (NULL_PTR == tagPtr) || (NULL_PTR == tagLengthPtr) || (NULL_PTR == associatedDataPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_AEADENCRYPT_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		AEADEncryptJob = &Csm_Job[jobId];

		AEADEncryptJob->jobPrimitiveInputOutput.mode = mode;
		AEADEncryptJob->jobPrimitiveInputOutput.inputPtr = plaintextPtr;
		AEADEncryptJob->jobPrimitiveInputOutput.inputLength = plaintextLength;
		AEADEncryptJob->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;
		AEADEncryptJob->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;
		AEADEncryptJob->jobPrimitiveInputOutput.secondaryOutputPtr = tagPtr;
		AEADEncryptJob->jobPrimitiveInputOutput.secondaryOutputLengthPtr = tagLengthPtr;
		AEADEncryptJob->jobPrimitiveInputOutput.outputPtr = ciphertextPtr;
		AEADEncryptJob->jobPrimitiveInputOutput.outputLengthPtr = ciphertextLengthPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, AEADEncryptJob);
	}
	return Status;
} 
#endif /* #if (CSM_AEADENCRYPT_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_AEADDecrypt
**
** Visibility       :   Public
**
** Description      :   This function is used to perform a AEAD decryption 
**
** Invocation       :
**
** Inputs           :  jobId 	: identifier of the Job
** 					   mode     : Which mode to perform the operation. 
** 					   ciphertextPtr   : pointer to encrypted data
** 					   ciphertextLength : Pointer to length of the encrypted data. 
** 					   associatedDataPtr   : Pointer to the associated data. 
** 					   associatedDataLength : Length of associated Length. 
** 					   tagPtr : Pointer store the mac. 
** 					   tagLengthPtr   : pointer to store the length of the mac. 
** 					   plaintextPtr   : pointer to store the Decrypted data.
** 					   plaintextLengthPtr   : pointer to store decrypted data length.
** 					   verifyPtr   : pointer to store Verification result.
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_AEADDECRYPT_API == STD_ON)
Std_ReturnType Csm_AEADDecrypt(uint32 jobId,Crypto_OperationModeType mode,const uint8 * ciphertextPtr,uint32 ciphertextLength,
	const uint8 * associatedDataPtr,uint32 associatedDataLength,const uint8 * tagPtr,uint32 tagLength,uint8 * plaintextPtr,
	uint32 * plaintextLengthPtr,Crypto_VerifyResultType * verifyPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	Crypto_JobType * AEEDDecryptJob = NULL_PTR;
	uint8 queueInfoIdx = 0u;

	/* Common Boundary check*/
	errorId = Csm_PreConditionCheck(jobId,mode,ciphertextPtr,ciphertextLength);
	if (((mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)
		  || ((mode & CRYPTO_OPERATIONMODE_FINISH) == (uint8)CRYPTO_OPERATIONMODE_FINISH))
	{
		if ((NULL_PTR == plaintextPtr) || (NULL_PTR == plaintextLengthPtr) || (NULL_PTR == tagPtr) || (NULL_PTR == verifyPtr) || (NULL_PTR == associatedDataPtr))
		{
			errorId = CSM_E_PARAM_POINTER;
		}
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_AEADDECRYPT_ID, errorId);
		#endif  
	}
	else
	{
		queueInfoIdx = Csm_JobTable[jobId].QueueRefIdxOfJobTable;
		AEEDDecryptJob = &Csm_Job[jobId];

		AEEDDecryptJob->jobPrimitiveInputOutput.mode = mode;
		AEEDDecryptJob->jobPrimitiveInputOutput.inputPtr = ciphertextPtr;
		AEEDDecryptJob->jobPrimitiveInputOutput.inputLength = ciphertextLength;
		AEEDDecryptJob->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr;
		AEEDDecryptJob->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength;
		AEEDDecryptJob->jobPrimitiveInputOutput.tertiaryInputPtr = tagPtr;
		AEEDDecryptJob->jobPrimitiveInputOutput.tertiaryInputLength = tagLength;
		AEEDDecryptJob->jobPrimitiveInputOutput.outputPtr = plaintextPtr;
		AEEDDecryptJob->jobPrimitiveInputOutput.outputLengthPtr = plaintextLengthPtr;
		AEEDDecryptJob->jobPrimitiveInputOutput.verifyPtr = verifyPtr;
		/* Process job */
		Status = Csm_ProcessJob(queueInfoIdx, AEEDDecryptJob);
	}
	return Status;
}
#endif /* #if (CSM_AEADECRYPT_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_CertificateParse
**
** Visibility       :   Public
**
** Description      :   This function is used to perform a parsing Certificate 
**
** Invocation       :
**
** Inputs           :  keyId 	: Holds the id of the Certificate to be parsed
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_CERTIFICATEPARSE_API == STD_ON)
Std_ReturnType Csm_CertificateParse(uint32 keyId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check key range */
	else if (keyId >= TOTAL_NO_KEY)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_CertificateParse(Csm_Key[keyId].CryIfKeyIdOfKey);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_CERTIFICATEPARSE_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_CERTIFICATEPARSE_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_CertificateVerify
**
** Visibility       :   Public
**
** Description      :   This function is used to perform Verification of given Certificate 
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key used to validate the certificate
**                     verifyKeyId 	: Holds the id of the Certificate to be Verified
**                     verifyPtr 	: Pointer to Verification Result
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_CERTIFICATEVERIFY_API == STD_ON)
Std_ReturnType Csm_CertificateVerify(uint32 keyId,uint32 verifyKeyId,Crypto_VerifyResultType * verifyPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check Null pointer*/
	else if(NULL_PTR == verifyPtr)
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY) || (verifyKeyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_CertificateVerify(Csm_Key[keyId].CryIfKeyIdOfKey,Csm_Key[verifyKeyId].CryIfKeyIdOfKey,verifyPtr);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_CERTIFICATEVERIFY_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_CERTIFICATEVERIFY_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeyGenerate
**
** Visibility       :   Public
**
** Description      :   This function is used to Generate a Key
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key to be generated
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYGENERATE_API == STD_ON)
Std_ReturnType Csm_KeyGenerate(uint32 keyId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check key range */
	else if (keyId >= TOTAL_NO_KEY)
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyGenerate(Csm_Key[keyId].CryIfKeyIdOfKey);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYGENERATE_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_KEYGENERATE_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeyElementCopy
**
** Visibility       :   Public
**
** Description      :   This function is used to perform Copy of key element 
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key used to be copied
**                     keyElementId : Holds the id of element that needs to be copied
**                     targetKeyId 	: Holds the id of the the key slot where to store
**                     targetKeyElementId 	: Holds the element Id 
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYELEMENTCOPY_API == STD_ON)
Std_ReturnType Csm_KeyElementCopy(uint32 keyId,uint32 keyElementId,uint32 targetKeyId,uint32 targetKeyElementId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY) || (targetKeyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyElementCopy(Csm_Key[keyId].CryIfKeyIdOfKey,keyElementId,Csm_Key[targetKeyId].CryIfKeyIdOfKey,targetKeyElementId);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYELEMENTCOPY_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_KEYELEMENTCOPY_API == STD_ON) */
/*============================================================================
**
** Function Name    :   Csm_KeyCopy
**
** Visibility       :   Public
**
** Description      :   This function is used to perform Copy of key
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key used to be copied
**                     targetKeyId 	: Holds the id of the the key slot where to store
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYCOPY_API == STD_ON)
Std_ReturnType Csm_KeyCopy(uint32 keyId,uint32 targetKeyId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY) || (targetKeyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyCopy(Csm_Key[keyId].CryIfKeyIdOfKey,Csm_Key[targetKeyId].CryIfKeyIdOfKey);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYCOPY_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_KEYCOPY_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeyDerive
**
** Visibility       :   Public
**
** Description      :   This function is used to perform Key deriviation from a given key
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key used derive key
**                     targetKeyId 	: Holds the id of the the derived key
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYDERIVE_API == STD_ON)
Std_ReturnType Csm_KeyDerive(uint32 keyId,uint32 targetKeyId)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY) || (targetKeyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyDerive(Csm_Key[keyId].CryIfKeyIdOfKey,Csm_Key[targetKeyId].CryIfKeyIdOfKey);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYDERIVE_ID, errorId);
		#endif  
	}
	return Status;

}
#endif /* #if (CSM_KEYDERIVE_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeyExchangeCalcSecret
**
** Visibility       :   Public
**
** Description      :   This function is used to perform Key Exchange 
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key to use in key exchange
**                     partnerPublicValuePtr 	: Pointer to Public key value from Partner
**                     partnerPublicValueLength 	: Length of Partner Public key length 
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYEXCHANGECALCSECRET_API == STD_ON)
Std_ReturnType Csm_KeyExchangeCalcSecret(uint32 keyId,const uint8* partnerPublicValuePtr,uint32 partnerPublicValueLength)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check Null pointer*/
	else if(NULL_PTR == partnerPublicValuePtr)
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyExchangeCalcSecret(Csm_Key[keyId].CryIfKeyIdOfKey,partnerPublicValuePtr,partnerPublicValueLength);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYEXCHANGECALCSECRET_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #if (CSM_KEYEXCHANGECALCSECRET_API == STD_ON) */

/*============================================================================
**
** Function Name    :   Csm_KeyExchangeCalcPubVal
**
** Visibility       :   Public
**
** Description      :   This function is used to calcualte pub key value for Key Exchange 
**
** Invocation       :
**
** Inputs           :  keyId 	    : Holds the id of the key to use in key exchange
**                     publicValuePtr 	: Pointer to calculated Public key 
**                     publicValueLengthPtr 	: Pointer to Length of calcualted Public key length 
**
** Outputs          : E_OK                    Request successful.
**                    E_NOT_OK                Request failed.
**                    CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
** Critical Section :
**
**==========================================================================*/
#if (CSM_KEYEXCHANGECALCPUBVAL_API == STD_ON)
Std_ReturnType Csm_KeyExchangeCalcPubVal(uint32 keyId,uint8* publicValuePtr,uint32* publicValueLengthPtr)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CSM_E_NO_ERROR;
	/*  Check component init Status */
	if (CSM_INIT != Csm_IsInitialized)
	{
		errorId = CSM_E_UNINIT;
	}
	/* Check Null pointer*/
	else if((NULL_PTR == publicValuePtr) || (NULL_PTR == publicValueLengthPtr))
	{
		errorId = CSM_E_PARAM_POINTER;
	}
	/* Check key range */
	else if ((keyId >= TOTAL_NO_KEY))
	{
		errorId = CSM_E_PARAM_METHOD_INVALID;
	}
	else
	{
		Status = CryIf_KeyExchangeCalcPubVal(Csm_Key[keyId].CryIfKeyIdOfKey,publicValuePtr,publicValueLengthPtr);
	}
	if (CSM_E_NO_ERROR != errorId)
	{
		#if (CSM_DEV_ERROR_REPORT == STD_ON)
			CSM_DET_REPORTERROR(CSM_KEYEXCHANGECALCPUBVAL_ID, errorId);
		#endif  
	}
	return Status;
}
#endif /* #ifndef CSM_C */
#endif /* #if (CSM_KEYEXCHANGECALCPUBVAL_API == STD_ON) */

/*****************************************************************************
 *  END OF FILE: CSM.C
******************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 28-03-2022                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : RTC#1564070                                           */
/*Change Description: Cert-C warning analysis and fix                       */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 28-06-2022                                            */
/*Version           : turing_bsw_csm_0.0.4                                  */
/*By                : jkanikal                                              */
/*Traceability      : RTC#1564070                                           */
/*Change Description: Coverity and Misra analysis and fix	                */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 Coverity violations and justifications
 *****************************************************************************/
/* module specific Coverity deviations:
 *
 * 1. sensitive_memory_access
 * Reason:     Memory leak due to speculative execution. CM4  processor does not support Speculative execution.
 *             So no need of lfence barrier.
 * Risk:       No functional risk.
 * Prevention: Not required.
 * Reference: 
 */

/* EOF */
