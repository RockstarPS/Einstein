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
#include "Rte_CCDD_EcuPowerM.h"

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================
#define ECUPOWERM_INVALID_SEQ_ID				0xFFu
#define ECUPOWERM_MAX_COMMANDS_PER_CYCLE      	20u





//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessWaitTime(void);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessDevice(void);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessSequence(EcuPowerM_SequenceInfoptrType sequenceptr);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessJob(EcuPowerM_JobInfoptrType jobptr);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessCommand(EcuPowerM_CommandInfoptrType  commandptr);
static FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_EvaluateChannelCriteria(EcuPowerM_ChannelRefptrType channelRef,
																			  VAR(uint16, AUTOMATIC) currentValue);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_EnterCriticalSection(void);
static FUNC(void, ECUPOWERM_CODE) EcuPowerM_ExitCriticalSection(void);


//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
static VAR(EcuPowerM_InitStatusType, 		ECUWAKEUPM_VAR_NO_INIT)   	EcuPowerM_InitStatus;
static VAR(EcuPowerM_CurrentStateType, 		ECUWAKEUPM_VAR_NO_INIT) 	EcuPowerM_CurrentStateInfo;
static VAR(EcuPowerM_DevicePwrStatusType, 	ECUWAKEUPM_VAR_NO_INIT) 	deviceStatus[ECUPOWERM_MAX_NUM_OF_DEVICES];



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
	stateInfoptr 					= &EcuPowerM_CurrentStateInfo;

	stateInfoptr->devState    		= ECUPOWERM_DEVICE_STATE_IDLE;
	stateInfoptr->devPendingRqst   	= ECUPOWERM_RQST_DEVICE_IDLE;
	stateInfoptr->devCurrentRqst  	= ECUPOWERM_RQST_DEVICE_IDLE;
	stateInfoptr->commandState 		= ECUPOWERM_COMMAND_STATE_IN_IDLE;
	stateInfoptr->sequence    		= ECUPOWERM_INVALID_SEQ_ID;
	stateInfoptr->device      		= ECUPOWERM_MAX_NUM_OF_DEVICES;
	stateInfoptr->jobCnt      		= 0u;
	stateInfoptr->commandCnt  		= 0u;
	stateInfoptr->waitTimer   		= 0u;

	for(i=0; i<ECUPOWERM_MAX_NUM_OF_DEVICES; i++)
	{
		deviceStatus[i] = ECUPOWERM_DEV_PWR_STATUS_IDLE;
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
FUNC(Std_ReturnType,CCDD_EcuPowerM_CODE) EcuPowerM_RequestPower
(
	VAR(uint8, AUTOMATIC)device,
  	VAR(uint8, AUTOMATIC) request
)
{
	Std_ReturnType ret = E_NOT_OK;
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;

	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_UNINIT);
    }
	else if(device >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_PARAM_DEVICE);
	}
	else if(request >= ECUPOWERM_RQST_DEVICE_POWER_MAX)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_REQUEST_POWER, ECUPOWERM_E_PARAM_DEVICE_REQUEST);
	}
	else
	{
		if(stateInfoptr->device == device)
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
				stateInfoptr->device     		= device;
				stateInfoptr->devPendingRqst	= request;
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
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
    static uint8 Reqstate=0;
	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_MAIN_FUNCTION, ECUPOWERM_E_UNINIT);
    }
	else if(stateInfoptr->devPendingRqst >= ECUPOWERM_RQST_DEVICE_POWER_MAX)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_MAIN_FUNCTION, ECUPOWERM_E_PARAM_DEVICE_REQUEST);
	}
	else
	{
		EcuPowerM_ProcessWaitTime();
		EcuPowerM_ProcessDevice();
		if(Reqstate==0)
		{
			EcuPowerM_RequestPower(0,ECUPOWERM_RQST_DEVICE_POWERUP);
			Reqstate=1;
		}
	}
}

//======================================================================================================================
/** \brief EcuPowerM_ProcessWaitTime
 **
 ** This function counts wait time
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessWaitTime(void)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_WAIT_TIME, ECUPOWERM_E_UNINIT);

    }
	else
	{
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
FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessDevice(void)
{

	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     	stateInfoptr;

	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_DEVICE, ECUPOWERM_E_UNINIT);

    }
	else if(stateInfoptr->devState >= ECUPOWERM_DEVICE_STATE_INVALID)
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
					deviceptr  = &EcuPowerM_DeviceConfigTable[stateInfoptr->device];

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
						deviceStatus[stateInfoptr->device] 	= ECUPOWERM_DEV_PWR_STATUS_PENDING;
					}
				}
				else
				{
					stateInfoptr->device      			= ECUPOWERM_MAX_NUM_OF_DEVICES;
					stateInfoptr->devCurrentRqst		= ECUPOWERM_RQST_DEVICE_IDLE;
				}

			break;

			case ECUPOWERM_DEVICE_STATE_BUSY:

				if(stateInfoptr->device < ECUPOWERM_MAX_NUM_OF_DEVICES)
				{
					deviceptr  = &EcuPowerM_DeviceConfigTable[stateInfoptr->device];

					if((deviceptr->numOfSequences > 0u) && (stateInfoptr->sequence < deviceptr->numOfSequences))
					{
						sequenceptr = deviceptr->sequenceptr[stateInfoptr->sequence];
						if(sequenceptr != NULL_PTR)
						{
							EcuPowerM_ProcessSequence(sequenceptr);
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

				deviceStatus[stateInfoptr->device] 	= ECUPOWERM_DEV_PWR_STATUS_COMPLETED;
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
FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessSequence
(
	EcuPowerM_SequenceInfoptrType sequenceptr
)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_UNINIT);

    }
	else if(sequenceptr == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_PARAM_SEQUENCE);
	}
	else if(stateInfoptr->devState >= ECUPOWERM_DEVICE_STATE_INVALID)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_PARAM_DEVICE_STATE);

	}
	else
	{
		EcuPowerM_JobInfoptrType jobptr;
		if(sequenceptr->numOfJobs  > 0u)
		{
			if(stateInfoptr->jobCnt < sequenceptr->numOfJobs)
			{
				jobptr = sequenceptr->jobptr[stateInfoptr->jobCnt];
				if( jobptr != NULL_PTR)
	   			{
	   		   		EcuPowerM_ProcessJob(jobptr);
	   			}
	   			else
	   			{
	   				EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_JOB_REFERENCE);
	   			}
			}
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
		else
		{
			EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_SEQUENCE, ECUPOWERM_E_NUMBER_OF_JOBS);
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
FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessJob
(
	EcuPowerM_JobInfoptrType jobptr
)
{
	P2VAR(EcuPowerM_CurrentStateType, AUTOMATIC, ECUPOWERM_APPL_DATA)     stateInfoptr;
	stateInfoptr = &EcuPowerM_CurrentStateInfo;

    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_UNINIT);

    }
	else if(jobptr == NULL_PTR)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_JOB, ECUPOWERM_E_PARAM_JOB);
	}
	else
	{
		uint8 maxcmds;
		uint8 cmd;
		EcuPowerM_CommandInfoptrType commandptr;
		if(jobptr->numOfCommands > 0u)
		{
			maxcmds = (jobptr->numOfCommands  < ECUPOWERM_MAX_COMMANDS_PER_CYCLE) ? jobptr->numOfCommands : ECUPOWERM_MAX_COMMANDS_PER_CYCLE;
			for(cmd = stateInfoptr->commandCnt; cmd < maxcmds; cmd++)
			{
				commandptr = jobptr->commandptr[cmd];
				if(commandptr != NULL_PTR)
				{
					EcuPowerM_ProcessCommand(commandptr);
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
FUNC(void, ECUPOWERM_CODE) EcuPowerM_ProcessCommand
(
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
	else
	{
		uint8 	channel;
		uint8 	error;
		uint8  	DioValue     = 0u;
		uint16 	currentValue = 0u;;
		uint16 	valueRef     = 0u;


		EcuPowerM_ChannelRefptrType  channelRef;
		EcuPowerM_ChannelInfoptrType channelptr;
		EcuPowerM_DrvFuncTblType     drvtableptr;

		stateInfoptr = &EcuPowerM_CurrentStateInfo;
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
					else
					{
						if(channelRef->channelptr->driverApiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS)
						{
							drvtableptr->IohwAbsWriteChannel(channelRef->channelptr->hwid,channelRef->value,&error);
						}
						else
						{
							drvtableptr->DioWriteChannel(channelRef->channelptr->hwid,(uint8)channelRef->value);
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
					else
					{
						channelptr = channelRef->channelptr;
						if(channelptr->channelType == ECUPOWERM_CHANNEL_TYPE_ANALOG)
						{
							if(channelptr->driverApiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS)
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
								if(channelptr->driverApiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS)
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
					   		stateInfoptr->commandState  = ECUPOWERM_COMMAND_STATE_IN_EXECUTION;
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_CHANNEL_WAIT_FAILED);
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
					else
					{
						channelptr = channelRef->channelptr;

						if(channelptr->channelType != ECUPOWERM_CHANNEL_TYPE_DIGITAL)
						{
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_CHANNEL_TYPE);
						}
						else if((drvtableptr->IohwAbsSetDuty == NULL_PTR)||(drvtableptr->PwmSetDuty == NULL_PTR))
						{
							EcuPowerM_ReportError(ECUPOWERM_API_PROCESS_COMMAND, ECUPOWERM_E_NULL_DRIVER_API);
						}
						else
						{
							if(channelptr->driverApiType == ECUPOWERM_DRIVER_API_TYPE_IOHWABS)
							{
								drvtableptr->IohwAbsSetDuty(channelptr->hwid,channelRef->value,&error);
							}
							else
							{
								drvtableptr->PwmSetDuty(channelptr->hwid,channelRef->value);
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
FUNC(Std_ReturnType, ECUPOWERM_CODE) EcuPowerM_EvaluateChannelCriteria
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
FUNC(Std_ReturnType, CCDD_EcuPowerM_CODE) EcuPowerM_GetDeviceStatus
(
	VAR(uint8, AUTOMATIC) device,
	P2VAR(uint8, AUTOMATIC, ECUPOWERM_APPL_DATA) status
)
{
    Std_ReturnType ret = E_NOT_OK;
    if (EcuPowerM_InitStatus == ECUPOWERM_S_UNINITIALIZED)
    {
		/* Report Error shall be called */
		EcuPowerM_ReportError(ECUPOWERM_API_GET_DEVICE_STATUS, ECUPOWERM_E_UNINIT);
    }
	else if(device >= ECUPOWERM_MAX_NUM_OF_DEVICES)
	{
		EcuPowerM_ReportError(ECUPOWERM_API_GET_DEVICE_STATUS, ECUPOWERM_E_PARAM_DEVICE);
	}
	else
	{
		*status = deviceStatus[device];
		ret = E_OK;
	}

	return ret;

}

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





/*==============================================================================================================================================
Date              	: 01-01-24
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/

