//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
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
#include "EcuBatteryM_Cfg.h"
#include "EcuBatteryM.h"
#include "MemLib.h"
#include "EcuBatteryM_Types.h"
#include "EcuBatteryM_Defines.h"
#if (ECUBATTERYM_REPORT_FAULT_STATUS == STD_ON)
#include "EcuFaultM.h"
#endif

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================

//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================

//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================

//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================


//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================
static VAR(EcuBatteryM_InitStatusType, ECUBATTERYM_VAR_CLEARED  ) EcuBatteryM_InitStatus;
static VAR(EcuBatteryM_ChannelStateType, ECUBATTERYM_VAR_CLEARED) EcuBatteryM_ChannelState[ECUBATTERYM_NUMBER_OF_CHANNELS];
static void EcuBatteryM_ProcessDebounce(boolean conditionMet, boolean *state, uint16 *debounceCounter, uint16 debounceLimit, uint8 faultId, uint16 period);
static void EcuBatteryM_GetThresholdAndHystValues(	VAR(uint8, AUTOMATIC)channel, VAR(EcuBatteryM_ThresholdType, AUTOMATIC)thresholdType,
													P2VAR(uint32, AUTOMATIC, ECUBATTERYM_APPL_DATA)threshold,
													P2VAR(uint32, AUTOMATIC, ECUBATTERYM_APPL_DATA)hysteresis);



//======================================================================================================================
/** \brief EcuBatteryM_Init
 **
 ** This function initializes EcuBatteryM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================

FUNC(void, ECUBATTERYM_CODE)EcuBatteryM_Init(void)
{
  EcuBatteryM_ChannelConfigDataptrType ChannelConfigDataptr;

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_INITIALIZED)
  {
    /* Battery Manager already initialized */
    /* Report Error shall be called */
    EcuBatteryM_ReportError(ECUBATTERYM_API_INIT, ECUBATTERYM_E_ALREADY_INITIALIZED);
  }
  else
  {
    uint8 channel;
    for (channel = 0u; channel < ECUBATTERYM_NUMBER_OF_CHANNELS; channel++)
    {
      ChannelConfigDataptr = &EcuBatteryM_ChannelConfigData[channel];
      if (ChannelConfigDataptr == NULL_PTR)
      {
		EcuBatteryM_ReportError(ECUBATTERYM_API_MONITOR_CHANNEL, ECUBATTERYM_E_NULL_CHANNEL_LIST);
      }
      else
      {
        EcuBatteryM_ChannelState[channel].debounceCounter = 0;
		EcuBatteryM_ChannelState[channel].rawState = ChannelConfigDataptr->initialstate;
        EcuBatteryM_ChannelState[channel].state = ChannelConfigDataptr->initialstate;
        EcuBatteryM_ChannelState[channel].monitorState = ChannelConfigDataptr->defaultMonitoringState;
        EcuBatteryM_ChannelState[channel].monitorDelayTimer = ChannelConfigDataptr->monitorDelayTime;
      }
    }
    EcuBatteryM_InitStatus = ECUBATTERYM_S_INITIALIZED;
  }
}

//======================================================================================================================
/** \brief EcuBatteryM_DeInit
 **
 ** This function Deinitializes EcuBatteryM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUBATTERYM_CODE)EcuBatteryM_DeInit(void)
{

  EcuBatteryM_ChannelConfigDataptrType ChannelConfigDataptr;

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_UNINITIALIZED)
  {
    /* Battery Manager not-initialized */
    /* Report Error shall be called */
    EcuBatteryM_ReportError(ECUBATTERYM_API_DEINIT, ECUBATTERYM_E_UNINIT);
  }
  else
  {
    uint8 channel;
    for (channel = 0u; channel < ECUBATTERYM_NUMBER_OF_CHANNELS; channel++)
    {
    	ChannelConfigDataptr = &EcuBatteryM_ChannelConfigData[channel];
    	if (ChannelConfigDataptr == NULL_PTR)
    	{
			EcuBatteryM_ReportError(ECUBATTERYM_API_DEINIT, ECUBATTERYM_E_NULL_CHANNEL_LIST);
    	}
		else
		{
    		EcuBatteryM_ChannelState[channel].debounceCounter = 0;
			EcuBatteryM_ChannelState[channel].rawState = 0;
    		EcuBatteryM_ChannelState[channel].state = 0;
        	EcuBatteryM_ChannelState[channel].monitorState = ChannelConfigDataptr->defaultMonitoringState;
        	EcuBatteryM_ChannelState[channel].monitorDelayTimer = ChannelConfigDataptr->monitorDelayTime;
    	}
	}
    EcuBatteryM_InitStatus = ECUBATTERYM_S_UNINITIALIZED;

  }

}
//======================================================================================================================
/** \brief EcuBatteryM_MonitorChannels
 **
 **
 **
 ** \param[in]  None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUBATTERYM_CODE)EcuBatteryM_MonitorChannels(void)
{
  uint8 channel;
  uint8 enableState;
  EcuBatteryM_ChannelConfigDataptrType ChannelConfigDataptr;
  P2VAR(EcuBatteryM_ChannelStateType, AUTOMATIC, ECUBATTERYM_APPL_DATA)     ChannelStateptr;

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_UNINITIALIZED)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_MONITOR_CHANNELS, ECUBATTERYM_E_UNINIT);
  }
  else
  {
    for (channel = 0; channel < ECUBATTERYM_NUMBER_OF_CHANNELS; channel++)
    {
  		ChannelConfigDataptr = &EcuBatteryM_ChannelConfigData[channel];
    	ChannelStateptr = &EcuBatteryM_ChannelState[channel];
		enableState = ChannelConfigDataptr->enablePolarity;

      	if(ChannelConfigDataptr->enableid != 0xFFFFu)
      	{
        	enableState = Dio_ReadChannel(ChannelConfigDataptr->enableid);
     	}
		if(enableState == (uint8)ChannelConfigDataptr->enablePolarity)
		{
			EcuBatteryM_ProcessDelayTime(channel);
		}
		else
		{
			ChannelStateptr->monitorDelayTimer = ChannelConfigDataptr->monitorDelayTime;
        }

	  	if((ChannelStateptr->monitorState == TRUE)&&(ChannelStateptr->monitorDelayTimer == 0u)
	  	   &&(enableState == ChannelConfigDataptr->enablePolarity))
		{
      		EcuBatteryM_MonitorChannel(channel);
		}
		else
		{
			ChannelStateptr->debounceCounter = 0;
			ChannelStateptr->rawState = 0;
			ChannelStateptr->state = 0;
        }
    }
  }
}
//======================================================================================================================
/** \brief EcuBatteryM_SetMonitoringState
 **
 ** Function called to set the monitoring state of the channel.
 **
 ** \param[in]  channel.
 ** \param[in]  state.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================

FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_SetMonitoringState(uint8 channel,uint8 state)
{

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_UNINITIALIZED)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_SET_MONITOR_STATE, ECUBATTERYM_E_UNINIT);
  }
  else
  {
    if(channel < ECUBATTERYM_NUMBER_OF_CHANNELS)
    {
		if(state != FALSE)
		{
			EcuBatteryM_ChannelState[channel].monitorState = TRUE;
		}
		else
		{
		 	EcuBatteryM_ChannelState[channel].monitorState = FALSE;
        }
    }
  }
}

//======================================================================================================================
/** \brief EcuBatteryM_ProcessDelayTimer
 **
 ** Function called to process the monitoring delay timer. Channel will be monitored after the dealy time.
 **
 ** \param[in]  channel.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUBATTERYM_CODE)EcuBatteryM_ProcessDelayTime(VAR(uint8, AUTOMATIC)channel)
{
	P2VAR(EcuBatteryM_ChannelStateType, AUTOMATIC, ECUBATTERYM_APPL_DATA)     ChannelStateptr;

    ChannelStateptr = &EcuBatteryM_ChannelState[channel];

  	if (ChannelStateptr == NULL_PTR)
  	{
    	EcuBatteryM_ReportError(ECUBATTERYM_API_PROCESS_DELAY_TIME, ECUBATTERYM_E_NULL_CHANNEL_LIST);
  	}
	else
	{
		if(ChannelStateptr->monitorDelayTimer >= ECUBATTERYM_PERIOD_MSEC)
		{
			ChannelStateptr->monitorDelayTimer -= ECUBATTERYM_PERIOD_MSEC;
		}
		else
		{
			ChannelStateptr->monitorDelayTimer = 0u;
		}

    }
}


//======================================================================================================================
/** \brief EcuBatteryM_MonitorChannel
 **
 ** Function called to maintain EcuBatteryM_flag status bytes.
 **
 ** \param[in]  channel.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUBATTERYM_CODE)EcuBatteryM_MonitorChannel(VAR(uint8, AUTOMATIC)channel)
{
  uint32 	thresholdValue  =	0;
  uint32 	hysteresisValue = 	0;
  uint32    cmpLevel 		= 	0;
  uint32 	currentValue    =   0;
  uint8 	value_u8;
  uint8 	error = IOHWAB_E_NO_ERROR;
  boolean 	conditionMet;

  void *    currentValuePtr 	= &currentValue;
  P2VAR(EcuBatteryM_ChannelStateType, AUTOMATIC, ECUBATTERYM_APPL_DATA)     ChannelStateptr;
  EcuBatteryM_ChannelConfigDataptrType ChannelConfigDataptr;

  ChannelConfigDataptr = &EcuBatteryM_ChannelConfigData[channel];

  if (ChannelConfigDataptr == NULL_PTR)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_MONITOR_CHANNEL, ECUBATTERYM_E_NULL_CHANNEL_LIST);
  }
  else if(ChannelConfigDataptr->VoltageSourceApi == NULL_PTR)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_MONITOR_CHANNEL, ECUBATTERYM_E_NULL_VOLTAGE_SOURCE_API);
  }
  else
  {
	ChannelStateptr = &EcuBatteryM_ChannelState[channel];

    switch(ChannelConfigDataptr->monitoringType)
    {
    	case ECUBATTERYM_MONITORING_TYPE_HIGH:

        	(void)ChannelConfigDataptr->VoltageSourceApi(ChannelConfigDataptr->hwid,(void *)currentValuePtr,&error);
   
			if(error == IOHWAB_E_NO_ERROR)
			{
				if (FALSE != ChannelStateptr->state)
				{
					EcuBatteryM_GetThresholdAndHystValues(channel,ECUBATTERYM_THRESHOLD_TYPE_OFF,&thresholdValue,&hysteresisValue);
					cmpLevel = (thresholdValue >= hysteresisValue)? (thresholdValue - hysteresisValue): thresholdValue;
					conditionMet = ((uint32)currentValue <= cmpLevel);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->onToOffDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				else
				{
					EcuBatteryM_GetThresholdAndHystValues(channel,ECUBATTERYM_THRESHOLD_TYPE_ON,&thresholdValue,&hysteresisValue);
					cmpLevel = (uint32)(thresholdValue + hysteresisValue);
					conditionMet = ((uint32)currentValue >= cmpLevel);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->offToOnDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				/* Update Raw status */
				ChannelStateptr->rawState = (uint8)conditionMet;
			}
			
      	break;

    	case ECUBATTERYM_MONITORING_TYPE_LOW:
        	(void)ChannelConfigDataptr->VoltageSourceApi(ChannelConfigDataptr->hwid,(void*)currentValuePtr,&error);

			if(error == IOHWAB_E_NO_ERROR)
			{
				if (FALSE != ChannelStateptr->state)
				{
					EcuBatteryM_GetThresholdAndHystValues(channel,ECUBATTERYM_THRESHOLD_TYPE_OFF,&thresholdValue,&hysteresisValue);
					cmpLevel = (uint32)(thresholdValue + hysteresisValue);
					conditionMet = ((uint32)currentValue >= cmpLevel);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->onToOffDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				else
				{
					EcuBatteryM_GetThresholdAndHystValues(channel,ECUBATTERYM_THRESHOLD_TYPE_ON,&thresholdValue,&hysteresisValue);
					cmpLevel = (thresholdValue >= hysteresisValue)? (thresholdValue - hysteresisValue): thresholdValue;
					conditionMet = (currentValue <= cmpLevel);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->offToOnDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				/* Update Raw status */
				ChannelStateptr->rawState = (uint8)conditionMet;
			}
      	break;

    	case ECUBATTERYM_MONITORING_TYPE_PGOOD:
        	(void)ChannelConfigDataptr->VoltageSourceApi(ChannelConfigDataptr->hwid,(void*)&value_u8,&error);
        	if(error == IOHWAB_E_NO_ERROR)
			{
				if (FALSE != ChannelStateptr->state)
				{
					conditionMet = (value_u8 > ChannelConfigDataptr->offThreshold);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->onToOffDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				else
				{
					conditionMet = (value_u8 < ChannelConfigDataptr->onThreshold);
					EcuBatteryM_ProcessDebounce(conditionMet, &ChannelStateptr->state, &ChannelStateptr->debounceCounter, ChannelConfigDataptr->offToOnDebounce, ChannelConfigDataptr->faultId, ECUBATTERYM_PERIOD_MSEC);
				}
				/* Update Raw status */
				ChannelStateptr->rawState = (uint8)conditionMet;
			}
      	break;

    	default:
      	break;
    }
  }
}

//======================================================================================================================
/** \brief EcuBatteryM_GetChannelStatus
**
** This function processes device requests.
**
** \param[in] None.
**
** \return    None.
**
** */
//======================================================================================================================
FUNC(Std_ReturnType, ECUBATTERYM_CODE) EcuBatteryM_GetChannelStatus
  (
  VAR(uint8, AUTOMATIC) channel,
  P2VAR(uint8, AUTOMATIC, ECUBATTERYM_APPL_DATA) status
  )
{
  Std_ReturnType ret = E_NOT_OK;
  P2VAR(EcuBatteryM_ChannelStateType, AUTOMATIC, ECUBATTERYM_APPL_DATA)     stateInfoptr;

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_UNINITIALIZED)
  {
    /* Report Error shall be called */
    EcuBatteryM_ReportError(ECUBATTERYM_API_GET_CHANNEL_STATUS, ECUBATTERYM_E_UNINIT);
  }
  else if(channel >= ECUBATTERYM_NUMBER_OF_CHANNELS)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_GET_CHANNEL_STATUS, ECUBATTERYM_E_PARAM_CHANNEL);
  }
  else
  {
    stateInfoptr = &EcuBatteryM_ChannelState[channel];
    *status = stateInfoptr->state;
    ret = E_OK;
  }

  return ret;

}

//======================================================================================================================
/** \brief EcuBatteryM_GetChannelRawStatus
**
** This function processes device requests.
**
** \param[in] None.
**
** \return    None.
**
** */
//======================================================================================================================
FUNC(Std_ReturnType, ECUBATTERYM_CODE) EcuBatteryM_GetChannelRawStatus
  (
  VAR(uint8, AUTOMATIC) channel,
  P2VAR(uint8, AUTOMATIC, ECUBATTERYM_APPL_DATA) status
  )
{
  Std_ReturnType ret = E_NOT_OK;
  P2VAR(EcuBatteryM_ChannelStateType, AUTOMATIC, ECUBATTERYM_APPL_DATA)     stateInfoptr;

  if (EcuBatteryM_InitStatus == ECUBATTERYM_S_UNINITIALIZED)
  {
    /* Report Error shall be called */
    EcuBatteryM_ReportError(ECUBATTERYM_API_GET_CHANNEL_RAW_STATUS, ECUBATTERYM_E_UNINIT);
  }
  else if(channel >= ECUBATTERYM_NUMBER_OF_CHANNELS)
  {
    EcuBatteryM_ReportError(ECUBATTERYM_API_GET_CHANNEL_RAW_STATUS, ECUBATTERYM_E_PARAM_CHANNEL);
  }
  else
  {
    stateInfoptr = &EcuBatteryM_ChannelState[channel];
    *status = stateInfoptr->rawState;
    ret = E_OK;
  }

  return ret;

}


//======================================================================================================================
/** \brief EcuBatteryM_GetThresholdAndHystValues
**
** This function returns the threshold and hysteresis values.
**
** \param[in] None.
**
** \return    None.
**
** */
//======================================================================================================================

static FUNC(void, ECUBATTERYM_CODE)  EcuBatteryM_GetThresholdAndHystValues
(	VAR(uint8, AUTOMATIC)channel,
	VAR(EcuBatteryM_ThresholdType, AUTOMATIC)thresholdType,
	P2VAR(uint32, AUTOMATIC, ECUBATTERYM_APPL_DATA)threshold,
	P2VAR(uint32, AUTOMATIC, ECUBATTERYM_APPL_DATA)hysteresis
)
{
	if(channel >= ECUBATTERYM_NUMBER_OF_CHANNELS)
  	{
    	EcuBatteryM_ReportError(ECUBATTERYM_API_GET_THRESHOLD_HYST_VALUES, ECUBATTERYM_E_PARAM_CHANNEL);
  	}
  	else
	{
  		EcuBatteryM_ChannelConfigDataptrType ChannelConfigDataptr;
  		uint32 	thresholdValue		= 0;
  		uint32 	hysteresisValue		= 0;

  		void *    thresholdValuePtr 	= &thresholdValue;
  		void *    hysteresisValuePtr	= &hysteresisValue;
  		ChannelConfigDataptr = &EcuBatteryM_ChannelConfigData[channel];

		switch(thresholdType)
		{

			case ECUBATTERYM_THRESHOLD_TYPE_ON:

          		if(ChannelConfigDataptr->OnThresholdValueApi != NULL_PTR)
				{
					(void)ChannelConfigDataptr->OnThresholdValueApi((void*)thresholdValuePtr);
				}
				else
				{
					thresholdValue = ChannelConfigDataptr->onThreshold;
				}
				*threshold = (uint32)thresholdValue;

          		if(ChannelConfigDataptr->OnHysteresisValueApi != NULL_PTR)
				{
					(void)ChannelConfigDataptr->OnHysteresisValueApi((void*)hysteresisValuePtr);
				}
				else
				{
					hysteresisValue = ChannelConfigDataptr->onHysteresis;
				}
				*hysteresis = (uint32)hysteresisValue;

			break;

			case ECUBATTERYM_THRESHOLD_TYPE_OFF:

          		if(ChannelConfigDataptr->OffThresholdValueApi != NULL_PTR)
				{
					(void)ChannelConfigDataptr->OffThresholdValueApi((void*)thresholdValuePtr);
				}
				else
				{
					thresholdValue = ChannelConfigDataptr->offThreshold;
				}

				*threshold = (uint32)thresholdValue;

          		if(ChannelConfigDataptr->OffHysteresisValueApi != NULL_PTR)
				{
					(void)ChannelConfigDataptr->OffHysteresisValueApi((void*)hysteresisValuePtr);
				}
				else
				{
					hysteresisValue = ChannelConfigDataptr->offHysteresis;
				}
				*hysteresis = (uint32)hysteresisValue;
			break;

			default:
    			EcuBatteryM_ReportError(ECUBATTERYM_API_GET_THRESHOLD_HYST_VALUES, ECUBATTERYM_E_INVALID_THRESHOLD_TYPE);
			break;
		}

	}
}



//======================================================================================================================
/** \brief EcuBatteryM_GetChannelStatus
**
** This function processes device requests.
**
** \param[in] None.
**
** \return    None.
**
** */
//======================================================================================================================
static void EcuBatteryM_ProcessDebounce(boolean conditionMet, boolean *state, uint16 *debounceCounter, uint16 debounceLimit, uint8 faultId, uint16 period)
{
	if (conditionMet)
  	{
    	if (*debounceCounter >= debounceLimit)
    	{
      		*state = !(*state); // toggle state
      		*debounceCounter = 0;
	  	#if (ECUBATTERYM_REPORT_FAULT_STATUS == STD_ON)
		    EcuFaultM_Status FaultStatus;
			FaultStatus = (*state == 0U)? ECUFAULTM_STATUS_INACTIVE: ECUFAULTM_STATUS_ACTIVE;
			if(faultId != 0xFF) /* 0xFF -> ID for Skipping Fault logging */
			{
	  			EcuFaultM_ReportFault(faultId,FaultStatus, NULL_PTR, 0, ECUFAULTM_FAULT_NORMAL);
			}
	  	#endif


    	}
    	else
    	{
      		*debounceCounter += period;
    	}
  	}
  	else
  	{
    	*debounceCounter = 0;
  	}
}



/*==============================================================================================================================================
Date              		: 08-03-2026
CDSID             		: SKIRANKU
Traceability      		:
Change Description		: Initial Version.
================================================================================================================================================*/

