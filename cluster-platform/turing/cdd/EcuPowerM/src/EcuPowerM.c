//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "EcuPowerM.h"

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================
#define ECUPOWERM_INVALID_SEQ_ID				0xFFu
#define ECUPOWERM_MAX_COMMANDS_PER_CYCLE      	20u 





//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessWaitTime(VAR(uint8, AUTOMATIC)deviceId);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessDevice(VAR(uint8, AUTOMATIC)deviceId);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessSequence(VAR(uint8, AUTOMATIC)deviceId,EcuPowerM_SequenceInfoptrType sequenceptr);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessJob(VAR(uint8, AUTOMATIC)deviceId,EcuPowerM_JobInfoptrType jobptr);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessCommand(VAR(uint8, AUTOMATIC)deviceId,EcuPowerM_CommandInfoptrType  commandptr);
static FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_EvaluateChannelCriteria(EcuPowerM_ChannelRefptrType channelRef,
																			  VAR(uint16, AUTOMATIC) currentValue);
#if (ECUPOWERM_CRITICALSECTION_ENABLE == STD_ON)
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_EnterCriticalSection(void);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ExitCriticalSection(void);
#endif


//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
static VAR(EcuPowerM_InitStatusType, 		ECUWAKEUPM_VAR_CLEARED)   	EcuPowerM_InitStatus;
static VAR(EcuPowerM_CurrentStateType, 		ECUWAKEUPM_VAR_CLEARED) 	EcuPowerM_CurrentStateInfo[ECUPOWERM_MAX_NUM_OF_DEVICES];



//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================



//======================================================================================================================
/** \brief EcuPowerM_Init
 **
 ** This function initializes EcuPowerM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUPOWERM_CODE) EcuPowerM_Init(void)
{

    if (EcuPowerM_InitStatus == ECUPOWERM_S_INITIALIZED)
    {
		/* Power Manager already initialized */
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_INIT, ECUPOWERM_E_ALREADY_INITIALIZED);
    }
	else
	{
		EcuPowerM_InitInternalMemory();
		EcuPowerM_InitStatus = ECUPOWERM_S_INITIALIZED;
	}

    
}

//======================================================================================================================
/** \brief EcuPowerM_InitInternalMemory
 **
 ** This function initializes internal variables.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUPOWERM_CODE) EcuPowerM_InitInternalMemory(void)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	uint8 i;

	for(i=0U; i<ECUPOWERM_MAX_NUM_OF_DEVICES; i++)
	{
		stateInfoptr 					= &EcuPowerM_CurrentStateInfo[i];
		
		stateInfoptr->devState    		= ECUPOWERM_DEVICE_STATE_IDLE;
		stateInfoptr->devPendingRqst   	= ECUPOWERM_RQST_DEVICE_IDLE;
		stateInfoptr->devCurrentRqst  	= ECUPOWERM_RQST_DEVICE_IDLE;
		stateInfoptr->commandState 		= ECUPOWERM_COMMAND_STATE_IN_IDLE;
		stateInfoptr->sequence    		= ECUPOWERM_INVALID_SEQ_ID;
		stateInfoptr->deviceId         	= ECUPOWERM_MAX_NUM_OF_DEVICES;
		stateInfoptr->deviceStatus		= ECUPOWERM_DEV_PWR_STATUS_IDLE;
		stateInfoptr->jobCnt      		= 0u; 
		stateInfoptr->commandCnt  		= 0u;
		stateInfoptr->waitTimer   		= 0u;
	}
	
}


//======================================================================================================================
/** \brief EcuPowerM_DeInit
 **
 ** This function De-initializes EcuPowerM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUPOWERM_CODE) EcuPowerM_DeInit(void)
{
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Power Manager not-initialized */
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_DEINIT, ECUPOWERM_E_UNINIT);
    }
	else
	{
		EcuPowerM_InitInternalMemory();
		EcuPowerM_InitStatus = ECUPOWERM_S_UNINITIALIZED;
	}
}



//======================================================================================================================
/** \brief EcuPowerM_RequestPower
 **
 ** This function requests device power.
 **
 ** \param[in] device        device Id.
 ** \param[in] request       request type (POWER UP, POWER DOWN).

 **
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_RequestPower
( 
	VAR(uint8, AUTOMATIC)deviceId,
  	VAR(EcuPowerM_DevicePwrRqstType, AUTOMATIC) request
)
{
	Std_ReturnType ret = E_NOT_OK;
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;

    
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_UNINIT);
    }
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_PARAM_DEVICE);
	}
	else if(request >= ECUPOWERM_RQST_DEVICE_POWER_MAX)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_PARAM_DEVICE_REQUEST);
	}
	else
	{
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
		
		if(stateInfoptr->deviceId == deviceId)
		{
			if ((stateInfoptr->devPendingRqst 	 != request)
			   &&(stateInfoptr->devCurrentRqst   != request))
			{
				stateInfoptr->devPendingRqst = request;
				ret = E_OK;  
			} 
		}
		else
		{
			/* Accept new device request only when the current state is idle
			 * and no pending request
			 */
			if ((stateInfoptr->devState    		== ECUPOWERM_DEVICE_STATE_IDLE)  
			  &&(stateInfoptr->devPendingRqst  	== ECUPOWERM_RQST_DEVICE_IDLE))
			{
				stateInfoptr->deviceId     		= deviceId;
				stateInfoptr->devPendingRqst	= request;
				stateInfoptr->deviceStatus		= ECUPOWERM_DEV_PWR_STATUS_IDLE;
				ret = E_OK;  
			}
		}
	}

	return ret;
}


//======================================================================================================================
/** \brief EcuPowerM_MainFunction
 **
 ** Periodic function to service device power requests.
 **
 ** \param[in] None        
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUPOWERM_CODE) EcuPowerM_MainFunction(void)
{
	uint8 i;
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;


    
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_MAIN_FUNCTION, ECUPOWERM_E_UNINIT);
    }
	else 
	{
		for(i=0; i<ECUPOWERM_MAX_NUM_OF_DEVICES; i++)
		{
			stateInfoptr = &EcuPowerM_CurrentStateInfo[i];
			
			if(stateInfoptr->devPendingRqst >= ECUPOWERM_RQST_DEVICE_POWER_MAX)
			{
				EcuPowerM_ReportError(ECUPOWERM_API_MAIN_FUNCTION, ECUPOWERM_E_PARAM_DEVICE_REQUEST);
			}
			else
			{
				EcuPowerM_ProcessWaitTime(i);
				EcuPowerM_ProcessDevice(i);
			}
		}
    }

}

//======================================================================================================================
/** \brief EcuPowerM_ProcessWaitTime
 **
 ** This function counts wait time
 **
 ** \param[in] deviceId.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessWaitTime( VAR(uint8, AUTOMATIC)deviceId )
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_WAIT_TIME, ECUPOWERM_E_UNINIT);

    }
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_WAIT_TIME, ECUPOWERM_E_PARAM_DEVICE);
	}
	else
	{
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
		
		if(stateInfoptr->waitTimer >= ECUPOWERM_PERIOD_MSEC)
		{
			stateInfoptr->waitTimer -= ECUPOWERM_PERIOD_MSEC; 
		}
		else
		{
			stateInfoptr->waitTimer = 0u;
		}

	}

}

//======================================================================================================================
/** \brief EcuPowerM_ProcessDevice
 **
 ** This function prcesses device requests.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessDevice( VAR(uint8, AUTOMATIC)deviceId )
{
    
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     	stateInfoptr;

	

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_UNINIT);

    }
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_PARAM_DEVICE);
	}
	else 
	{
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
		if(stateInfoptr->devState >= ECUPOWERM_DEVICE_STATE_INVALID)
		{
			EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_PARAM_DEVICE_STATE);

		}
		else
		{
			EcuPowerM_DeviceConfigptrType   deviceptr;
			EcuPowerM_SequenceInfoptrType   sequenceptr;
			uint8 index = 0;
		
			switch(stateInfoptr->devState)
			{
				case ECUPOWERM_DEVICE_STATE_IDLE:
					
					if(stateInfoptr->devPendingRqst != ECUPOWERM_RQST_DEVICE_IDLE)
	   				{
						deviceptr  = &EcuPowerM_DeviceConfigTable[stateInfoptr->deviceId];
						
						stateInfoptr->devCurrentRqst		= stateInfoptr->devPendingRqst;
						stateInfoptr->devPendingRqst  		= ECUPOWERM_RQST_DEVICE_IDLE;
						for(index = 0; index < deviceptr->numOfSequences; index++)
						{
							sequenceptr = deviceptr->sequenceptr[index]; 
							if(sequenceptr != NULL_PTR)
							{
								if((((stateInfoptr->devCurrentRqst == ECUPOWERM_RQST_DEVICE_POWERUP)
									&&(sequenceptr->sequenceType == ECUPOWERM_SEQ_POWERUP))
								   	||((stateInfoptr->devCurrentRqst == ECUPOWERM_RQST_DEVICE_POWERDOWN)
								   	&&(sequenceptr->sequenceType == ECUPOWERM_SEQ_POWERDOWN)))) 
								{
									stateInfoptr->sequence = index;
									break;
								}
							}
						}
						if(index == deviceptr->numOfSequences)
						{
							stateInfoptr->sequence = ECUPOWERM_INVALID_SEQ_ID;
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_NUMBER_OF_SEQUENCES);
						}
						else
						{ 
							stateInfoptr->devState    			= ECUPOWERM_DEVICE_STATE_BUSY; 
							stateInfoptr->jobCnt      			= 0u; 
							stateInfoptr->commandCnt  			= 0u;
							stateInfoptr->waitTimer   			= 0u;
							stateInfoptr->deviceStatus      	= ECUPOWERM_DEV_PWR_STATUS_PENDING;
						}
					}
					else
					{
						stateInfoptr->deviceId      			= ECUPOWERM_MAX_NUM_OF_DEVICES;
						stateInfoptr->devCurrentRqst		    = ECUPOWERM_RQST_DEVICE_IDLE;
					}
					
				break;
			    
				case ECUPOWERM_DEVICE_STATE_BUSY:

					if(stateInfoptr->deviceId < ECUPOWERM_MAX_NUM_OF_DEVICES)
					{
						deviceptr  = &EcuPowerM_DeviceConfigTable[stateInfoptr->deviceId];

						if((deviceptr->numOfSequences > 0u) && (stateInfoptr->sequence < deviceptr->numOfSequences))
						{
							sequenceptr = deviceptr->sequenceptr[stateInfoptr->sequence]; 
							if(sequenceptr != NULL_PTR)
							{
								EcuPowerM_ProcessSequence(deviceId,sequenceptr);	
							}
							else
							{
								stateInfoptr->sequence = ECUPOWERM_INVALID_SEQ_ID;
								EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_SEQUENCE_REFERENCE);
							}	
						}
						else
						{
							stateInfoptr->sequence = ECUPOWERM_INVALID_SEQ_ID;
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_NUMBER_OF_SEQUENCES);
						}
					}

				break;
				
				case ECUPOWERM_DEVICE_STATE_COMPLETED:

					stateInfoptr->deviceStatus		 	= ECUPOWERM_DEV_PWR_STATUS_COMPLETED;
					stateInfoptr->devState    			= ECUPOWERM_DEVICE_STATE_IDLE;
					stateInfoptr->devCurrentRqst		= ECUPOWERM_RQST_DEVICE_IDLE; 
					stateInfoptr->sequence   			= ECUPOWERM_INVALID_SEQ_ID;
					stateInfoptr->jobCnt      			= 0u; 
					stateInfoptr->commandCnt  			= 0u;
					stateInfoptr->waitTimer   			= 0u;

				
				break;

				default:
					EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_DEVICE_POWER_STATE);
				break;

			}
		}
	}
}

//======================================================================================================================
/** \brief EcuPowerM_ProcessSequence
 **
 ** This function executes device sequence.
 **
 ** \param[in] sequenceptr        Sequenc pointer
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessSequence
(
	VAR(uint8, AUTOMATIC)deviceId,
	EcuPowerM_SequenceInfoptrType sequenceptr
)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_UNINIT);

    }
	else if(sequenceptr == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_PARAM_SEQUENCE);
	}
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_PARAM_DEVICE);
	}
	else 
	{
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
		
		if(stateInfoptr->devState >= ECUPOWERM_DEVICE_STATE_INVALID)
		{
			EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_PARAM_DEVICE_STATE);

		}
		else
		{
			EcuPowerM_JobInfoptrType jobptr = NULL_PTR; 
			if(sequenceptr->numOfJobs  > 0u)
			{
				if(stateInfoptr->jobCnt < sequenceptr->numOfJobs)
				{ 
					jobptr = sequenceptr->jobptr[stateInfoptr->jobCnt];
				}
				if( jobptr == NULL_PTR)
		   		{ 
					EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_JOB_REFERENCE);
		   		}
		   		else
		   		{
		   			EcuPowerM_ProcessJob(deviceId,jobptr);
					if(stateInfoptr->commandCnt >= jobptr->numOfCommands)
					{
						stateInfoptr->jobCnt++;
						stateInfoptr->commandCnt = 0;
						/* Process interrupt request */
						if ((stateInfoptr->devPendingRqst      != ECUPOWERM_RQST_DEVICE_IDLE)
							&&(stateInfoptr->devPendingRqst    != stateInfoptr->devCurrentRqst) 
							&&(sequenceptr->interruptible  	   == ECUPOWERM_SEQ_INTERRUPTIBLE))
						{
							stateInfoptr->devState = ECUPOWERM_DEVICE_STATE_IDLE; 
						}
						else
						{
							if(stateInfoptr->jobCnt >= sequenceptr->numOfJobs)
							{
								stateInfoptr->devState = ECUPOWERM_DEVICE_STATE_COMPLETED;
							}
						}
					} 
				}
			}
			else
			{
				EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_NUMBER_OF_JOBS);
			}
		}				
	}
}


//======================================================================================================================
/** \brief EcuPowerM_ProcessJob
 **
 ** This function services job.
 **
 ** \param[in] jobptr        job pointer.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessJob
(
	VAR(uint8, AUTOMATIC)deviceId,
	EcuPowerM_JobInfoptrType jobptr
)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
    
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_UNINIT);

    }
	else if(jobptr == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_PARAM_JOB);
	}
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_PARAM_DEVICE);
	}
	else
	{
		uint8 maxcmds;
		uint8 cmd;
		EcuPowerM_CommandInfoptrType commandptr; 
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];

		if(jobptr->numOfCommands > 0u)
		{
			maxcmds = (jobptr->numOfCommands  < ECUPOWERM_MAX_COMMANDS_PER_CYCLE) ? jobptr->numOfCommands : ECUPOWERM_MAX_COMMANDS_PER_CYCLE;
			for(cmd = stateInfoptr->commandCnt; cmd < maxcmds; cmd++)
			{
				commandptr = jobptr->commandptr[cmd];
				if(commandptr != NULL_PTR)
				{
					EcuPowerM_ProcessCommand(deviceId,commandptr);
					if(stateInfoptr->commandState == ECUPOWERM_COMMAND_STATE_IN_WAIT)
					{
						break;
					}
				}
				else
				{
					EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_COMMAND_REFERENCE);
				}
			}
			stateInfoptr->commandCnt = cmd; 
		}
		else
		{
			EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_NUMBER_OF_COMMANDS);
		}

	}
}

//======================================================================================================================
/** \brief EcuPowerM_ProcessCommand
 **
 ** This function executes commands in a Job.
 **
 ** \param[in] commandptr        Command pointer
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessCommand
(
	VAR(uint8, AUTOMATIC)deviceId,
	EcuPowerM_CommandInfoptrType commandptr
)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	Std_ReturnType ret = E_OK;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_UNINIT);
    }
	else if(commandptr == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_PARAM_COMMAND);
	}
	else if(commandptr->commandType >= ECUPOWERM_COMMAND_INVALID)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_COMMAND_TYPE);
	}
	else if((commandptr->commandType != ECUPOWERM_COMMAND_WAIT_TIME) && (commandptr->channelRef == NULL_PTR)) 
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_CHANNEL_LIST);
	}
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_PARAM_DEVICE);
	}
	else
	{
		uint8 	channel;
		uint8 	error;
		uint8  	DioValue     = 0u;
		uint16 	currentValue = 0xFFFFu;;
		uint16 	valueRef     = 0u;

		EcuPowerM_ChannelRefptrType  channelRef;
		EcuPowerM_ChannelInfoptrType channelptr;
		EcuPowerM_DrvFuncTblType     drvtableptr;

		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
    	drvtableptr  = &EcuPowerM_LowLevelDrvFuncTable;
				
		switch(commandptr->commandType)
		{
			case ECUPOWERM_COMMAND_READ_CHANNEL:
				stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;
				/* Reserved */ 
				break;
			
			case ECUPOWERM_COMMAND_WRITE_CHANNEL:
				
				stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION; 
				for(channel = 0; channel < commandptr->numOfChannels; channel++)
				{
					channelRef = commandptr->channelRef[channel];
					if(channelRef->channelptr == NULL_PTR)
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_CHANNEL);
					}
					else if(channelRef->channelptr->channelType != ECUPOWERM_CHANNEL_TYPE_DIGITAL)
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_CHANNEL_TYPE);
					}
					else if((drvtableptr->IohwAbsWriteChannel == NULL_PTR)||(drvtableptr->DioWriteChannel == NULL_PTR))
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_DRIVER_API);
					}
					else if((channelRef->apiType >= ECUPOWERM_DRIVER_API_TYPE_INVALID) ||
					        ((channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM) &&
							(channelRef->apiName == NULL_PTR))) 
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_INVALID_API);
					}
					else
					{
						if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM)
						{
							if(channelRef->apiName != NULL_PTR)
							{
								(void)channelRef->apiName(channelRef->channelptr->hwid,(uint16 *)&channelRef->value,&error);
							}
						}
						else if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS) 
						{
							(void)drvtableptr->IohwAbsWriteChannel(channelRef->channelptr->hwid,channelRef->value,&error);	
						}
						else  
						{
							if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_DIO)
							{
								drvtableptr->DioWriteChannel(channelRef->channelptr->hwid,(uint8)channelRef->value);
							}	
						}
					}
				}
				break;

			case ECUPOWERM_COMMAND_WAITON_CHANNEL:
				
				ret = E_OK;
				for(channel = 0; channel < commandptr->numOfChannels; channel++)
				{
					channelRef = commandptr->channelRef[channel];
					if(channelRef->channelptr == NULL_PTR)
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_CHANNEL);
					}
					else if((drvtableptr->IohwAbsAdcReadChannel == NULL_PTR)||(drvtableptr->AdcReadChannel == NULL_PTR))
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_DRIVER_API);
					}
					else if((channelRef->apiType >= ECUPOWERM_DRIVER_API_TYPE_INVALID) ||
					        ((channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM) &&
							(channelRef->apiName == NULL_PTR))) 
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_INVALID_API);
					}
					else
					{				
						channelptr = channelRef->channelptr;
						if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM)
						{
							if(channelRef->apiName != NULL_PTR)
							{
                                (void)channelRef->apiName(channelRef->channelptr->hwid,&valueRef,&error);
								currentValue = valueRef; 
							}
						}
						else
						{
							if(channelptr->channelType == ECUPOWERM_CHANNEL_TYPE_ANALOG)
							{
								if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS) 
								{
									(void)drvtableptr->IohwAbsAdcReadChannel(channelRef->channelptr->hwid,&valueRef,&error);	
								}
								else  
								{
									(void)drvtableptr->AdcReadChannel(channelRef->channelptr->hwid,&valueRef);	
								}
								currentValue = valueRef; 
							}
							else
							{
								if(channelptr->channelType == ECUPOWERM_CHANNEL_TYPE_DIGITAL)
								{
									if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS) 
									{
										(void)drvtableptr->IohwAbsReadChannel(channelRef->channelptr->hwid,&DioValue,&error);
										currentValue = DioValue; 
									}
							   		else  
									{
										currentValue = drvtableptr->DioReadChannel(channelRef->channelptr->hwid);	
									}
								}
							}
						}
						if(E_OK != EcuPowerM_EvaluateChannelCriteria(channelRef,currentValue))
						{
							ret = E_NOT_OK;
						}
					}
				}
				if(ret == E_OK)
				{
					stateInfoptr->waitTimer    = 0;
					stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;
				}
				else
				{
					if(commandptr->timeout == 0u)
					{
						/* Wait till the channel matches the criteria */
						stateInfoptr->waitTimer    = 0;
						stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_WAIT;
					}
					else if((commandptr->timeout > 0u) && (stateInfoptr->commandState == ECUPOWERM_COMMAND_STATE_IN_EXECUTION))
					{
						/* Reload timer */
						stateInfoptr->waitTimer    = commandptr->timeout;
						stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_WAIT;
					}
					else
					{
						if(stateInfoptr->waitTimer > 0u)
						{
							/* Wait for a channel until timeout */
					   		stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_WAIT;
						}
						else
						{

					        if(channelRef->channelptr == NULL_PTR)
					        {
						        EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_CHANNEL);
					        }
					        else
					        {
					            EcuPowerM_UserCallback(channelRef->channelptr->hwid,ECUPOWERM_E_CHANNEL_WAIT_FAILED);
					         	stateInfoptr->commandState  = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;
					            EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_CHANNEL_WAIT_FAILED);
							}
						}
					}
				}

				break;
			
			case ECUPOWERM_COMMAND_WAIT_TIME:
				
				if((commandptr->timeout > 0u) && (stateInfoptr->commandState == ECUPOWERM_COMMAND_STATE_IN_EXECUTION))
				{
					/* Reload timer */
					stateInfoptr->waitTimer    = commandptr->timeout;
					stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_WAIT;
				}
				else
				{
					if(stateInfoptr->waitTimer > 0u)
					{
						/* Wait time between channels*/
					   stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_WAIT;
					}
					else
					{
					   stateInfoptr->commandState  = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;
					}
				}
				break;

			
			case ECUPOWERM_COMMAND_SET_DUTY:

				stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION; 
				for(channel = 0; channel < commandptr->numOfChannels; channel++)
				{
					channelRef = commandptr->channelRef[channel];
					if(channelRef->channelptr == NULL_PTR)
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_CHANNEL);
					}
					else if((channelRef->apiType >= ECUPOWERM_DRIVER_API_TYPE_INVALID) ||
					        ((channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM) &&
							(channelRef->apiName == NULL_PTR))) 
					{
						EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_INVALID_API);
					}
					else 
					{
						channelptr = channelRef->channelptr;
						if(channelptr->channelType != ECUPOWERM_CHANNEL_TYPE_DIGITAL)
						{
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_CHANNEL_TYPE);
						}
						else
						{
							if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_CUSTOM)
							{
								if(channelRef->apiName != NULL_PTR)
								{
									(void)channelRef->apiName(channelRef->channelptr->hwid,(uint16 *)&channelRef->value,&error);
								}
							}
							else if((drvtableptr->IohwAbsSetDuty == NULL_PTR)||(drvtableptr->PwmSetDuty == NULL_PTR))
							{
								EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_DRIVER_API);
							}
							else
							{
								if(channelRef->apiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS)
								{
									(void)drvtableptr->IohwAbsSetDuty(channelptr->hwid,channelRef->value,&error);
								}
								else
								{
									drvtableptr->PwmSetDuty(channelptr->hwid,channelRef->value);
								} 
							}
						}
					}
				}
				
				break;

			
			case ECUPOWERM_COMMAND_SET_PERIOD_AND_DUTY:
				stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;

				/* Currently not supported.Reserved for future */
				break;
			
			
			case ECUPOWERM_COMMAND_CUSTOM:
				stateInfoptr->commandState = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;

				/* Currently not supported.Reserved for future */
				
				break;
		
			default:
				EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_COMMAND);
				
				break;
		}
	}
}
    
//======================================================================================================================
/** \brief EcuPowerM_EvaluateChannelCriteria
 **
 ** This function validates the channel against current value. 
 **
 ** \param[in] channelRef        channel reference.
 ** \param[in] currentValue      current channel value.
 **
 ** \return    E_NOT_OK          Validation failed.
 **			   E_OK              Validation success.
 ** */
//======================================================================================================================
static FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_EvaluateChannelCriteria
(
	EcuPowerM_ChannelRefptrType channelRef,
	VAR(uint16, AUTOMATIC) currentValue
)
{

	Std_ReturnType ret = E_NOT_OK;
	if(channelRef == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_EVALUATE_CHANNEL_CRITERIA, ECUPOWERM_E_NULL_CHANNEL_LIST);
	}
	else
	{
		switch(channelRef->criteria)
		{
			case ECUPOWERM_CRITERIA_EQUAL:
				if(channelRef->value == currentValue)
				{
					ret = E_OK;
				} 
			break;

			case ECUPOWERM_CRITERIA_LESSER:
				if(channelRef->value < currentValue)
				{
					ret = E_OK;
				} 

			break;

			case ECUPOWERM_CRITERIA_LESSER_THAN_EQUAL:
				if(channelRef->value <= currentValue)
				{
					ret = E_OK;
				} 

			break;

			case ECUPOWERM_CRITERIA_GREATER:
				if(channelRef->value > currentValue)
				{
					ret = E_OK;
				} 
			break;

			case ECUPOWERM_CRITERIA_GREATER_THAN_EQUAL:
				if(channelRef->value >= currentValue)
				{
					ret = E_OK;
				} 
			break;
			
			case ECUPOWERM_CRITERIA_NULL:
				ret = E_OK;
			break;

			default:
				EcuPowerM_ReportError(ECUPOWERM_API_EVALUATE_CHANNEL_CRITERIA, ECUPOWERM_E_CHANNEL_CRITERIA);
			break;
		
		}
	}
	return ret;
}


//======================================================================================================================
/** \brief EcuPowerM_ProcessDevice
 **
 ** This function prcesses device requests.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_GetDeviceStatus
(
	VAR(uint8, AUTOMATIC) deviceId, 
	P2VAR(EcuPowerM_DevicePwrStatusType, AUTOMATIC, ECUPOWERM_APPL_DATA) status
)
{
    Std_ReturnType ret = E_NOT_OK;
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */ 
		EcuPowerM_ReportError(ECUPOWERM_API_GET_DEVICE_STATUS, ECUPOWERM_E_UNINIT);
    }
	else if(deviceId >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_GET_DEVICE_STATUS, ECUPOWERM_E_PARAM_DEVICE);
	}
	else
	{
		stateInfoptr = &EcuPowerM_CurrentStateInfo[deviceId];
		*status = stateInfoptr->deviceStatus; 
		ret = E_OK;
	}
	
	return ret;

}

#if (ECUPOWERM_CRITICALSECTION_ENABLE == STD_ON)
//======================================================================================================================
/** \brief EcuPowerM_EnterCriticalSection
 **
 ** Entry critical section.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================

static FUNC(void, ECUPOWERM_CODE) EcuPowerM_EnterCriticalSection(void)
{

}

//======================================================================================================================
/** \brief EcuPowerM_ExitCriticalSection
 **
 ** Exit critical section.
 **
 ** \param[in] None
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================

static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ExitCriticalSection(void)
{

}
#endif




/*==============================================================================================================================================
Date              	: 01-01-24
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/

