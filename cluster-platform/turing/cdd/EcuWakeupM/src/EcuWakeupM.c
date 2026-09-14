//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#include "EcuWakeupM.h"
#include "EcuWakeupM_Det.h"
#include "SchM_EcuWakeupM.h"

//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================



//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
#define EcuWakeupM_START_SEC_VAR_NO_INIT_8
#include "EcuWakeupM_MemMap.h"

static VAR(EcuWakeupM_InitStatusType, ECUWAKEUPM_VAR_INIT) EcuWakeupM_InitStatus = ECUWAKEUPM_S_UNINITIALIZED;

#define EcuWakeupM_STOP_SEC_VAR_NO_INIT_8
#include "EcuWakeupM_MemMap.h"

// GPIO PORT MODE WILL BE DEFINED,IF ITS NOT DEFINED
#ifndef ECUWAKEUPM_ENABLE_GPIO_MODE
#define ECUWAKEUPM_ENABLE_GPIO_MODE STD_ON
#endif

//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================

#if defined(__ghs__)
#pragma ghs section bss=".buram"
#elif defined(__clang__)
#pragma clang section bss=".buram"
#endif

static VAR(EcuWakeupM_ChannelStateType, ECUWAKEUPM_VAR_NO_INIT) EcuWakeupM_ChannelState[ECUWAKEUPM_NUMBER_OF_CHANNELS];

#if defined(__ghs__)
#pragma ghs section bss=default
#elif defined(__clang__)
#pragma clang section bss=""
#endif


//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
#define EcuWakeupM_START_SEC_CODE
#include "EcuWakeupM_MemMap.h"   

static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnterCriticalSection(void);
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_ExitCriticalSection(void);



//======================================================================================================================
/** \brief EcuWakeupM_Init
 **
 ** This function initializes EcuWakeupM.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_Init(void)
{
    
    if (EcuWakeupM_InitStatus == ECUWAKEUPM_S_INITIALIZED)
    {
		/* Wakeup Manager already initialized */
		/* Report Error shall be called */ 
		EcuWakeupM_ReportError(ECUWAKEUPM_API_INIT, ECUWAKEUPM_E_ALREADY_INITIALIZED);

    }
	else
	{
		VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;
		for(Channel=0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			EcuWakeupM_ChannelState[Channel].NotifyStatus = FALSE;
		}
		EcuWakeupM_InitStatus = ECUWAKEUPM_S_INITIALIZED;
	}
}

//======================================================================================================================
/** \brief EcuWakeupM_EnableWakeup
 **
 ** This function enables ECU wakeup channel.
 **
 ** \param[in] Channel      Wakeup channel ID.
 ** \param[in] NotifyStatus   Enable/Disable channel wakeup notification.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnableWakeup
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel,
	VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus
)
{

	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_ENABLE_WAKEUP, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_ENABLE_WAKEUP, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{
	    EcuWakeupM_EnterCriticalSection();

		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)             DrvFuncPtr;
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		P2CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)      PortDrvFuncPtr;
#endif
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
		EcuWakeupM_LowlevelDrvFuncTblType                                                   LowlevelDrvFuncPtr;

    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)
		GenericConfigPtr            = ConfigPtr->GenericPtr;	
		PortDrvFuncPtr    			= GenericConfigPtr->GetPortDrvFuncTable();
#endif
		DrvFuncPtr                  = ChannelConfigPtr->GetDrvFuncTable();
		LowlevelDrvFuncPtr 		  	= DrvFuncPtr->LowlevelDrvFunc;
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 
		
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)
		if(ChannelConfigPtr->WakeupType == ECUWAKEUPM_WAKEUP_EXTERNAL)
		{
			if(PortDrvFuncPtr->PortModeToGpioFunc != NULL_PTR)
			{
				PortDrvFuncPtr->PortModeToGpioFunc(ChannelConfigPtr->WakeupPortId);
			}
			else
			{
				if(PortDrvFuncPtr->Port_SetPinModeFunc != NULL_PTR)
				{
					PortDrvFuncPtr->Port_SetPinModeFunc(ChannelConfigPtr->WakeupPortId,ECUWAKEUPM_PORT_MODE_GPIO);
				}
				else
				{
					EcuWakeupM_ReportError(ECUWAKEUPM_API_ENABLE_WAKEUP, ECUWAKEUPM_E_PORT_CONFIGURATION);
				}
			}
		}
#endif		
		LowlevelDrvFuncPtr->SetModeFunc(DrvFuncPtr->NormalMode);
		EcuWakeupM_SetNotification(Channel,NotifyStatus);
		ChannelStatePtr->WakeupStatus = FALSE;
	 
		if(LowlevelDrvFuncPtr->EnableWakeupIsrFunc != NULL_PTR)
		{
			LowlevelDrvFuncPtr->EnableWakeupIsrFunc(ChannelConfigPtr->WakeupChannel);
		}
		LowlevelDrvFuncPtr->EnableWakeupFunc(ChannelConfigPtr->WakeupChannel);
		LowlevelDrvFuncPtr->SetModeFunc(DrvFuncPtr->SleepMode);

		EcuWakeupM_ExitCriticalSection();
	}   
}
//======================================================================================================================
/** \brief EcuWakeupM_DisableWakeup
 **
 ** This function disables ECU wakeup channel.
 **
 ** \param[in] Channel      Wakeup channel ID.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_DisableWakeup
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel
)
{
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_DISABLE_WAKEUP, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_DISABLE_WAKEUP, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{
	    EcuWakeupM_EnterCriticalSection();
		
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)             DrvFuncPtr;
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)	
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		P2CONST(EcuWakeupM_LowlevelPortDrvFuncTbl_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)      PortDrvFuncPtr;
#endif	
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
		EcuWakeupM_LowlevelDrvFuncTblType                                                   LowlevelDrvFuncPtr;

    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)
		GenericConfigPtr            = ConfigPtr->GenericPtr;
		PortDrvFuncPtr    			= GenericConfigPtr->GetPortDrvFuncTable();
#endif	
		DrvFuncPtr                  = ChannelConfigPtr->GetDrvFuncTable();
		LowlevelDrvFuncPtr 		  	= DrvFuncPtr->LowlevelDrvFunc;
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 
	  
#if (ECUWAKEUPM_ENABLE_GPIO_MODE == STD_ON)	  
		if(ChannelConfigPtr->WakeupType == ECUWAKEUPM_WAKEUP_EXTERNAL)
		{
			if(PortDrvFuncPtr->PortModeToAlternateFunc != NULL_PTR)
			{
				PortDrvFuncPtr->PortModeToAlternateFunc(ChannelConfigPtr->WakeupPortId);
			}
			else
			{
				if((PortDrvFuncPtr->Port_SetPinModeFunc != NULL_PTR) && 
				  (ChannelConfigPtr->WakeupPortAlternateMode != ECUWAKEUPM_PORT_MODE_INVALID))
				{
					PortDrvFuncPtr->Port_SetPinModeFunc(ChannelConfigPtr->WakeupPortId,ChannelConfigPtr->WakeupPortAlternateMode);
				}
				else
				{
					EcuWakeupM_ReportError(ECUWAKEUPM_API_DISABLE_WAKEUP, ECUWAKEUPM_E_PORT_CONFIGURATION);
				}
			}
		}
#endif		
		LowlevelDrvFuncPtr->SetModeFunc(DrvFuncPtr->NormalMode);
		if(ChannelStatePtr->NotifyStatus == TRUE)
		{
			LowlevelDrvFuncPtr->DisableNotificationCbk(ChannelConfigPtr->WakeupChannel);
			ChannelStatePtr->NotifyStatus = FALSE;
		}
		if(LowlevelDrvFuncPtr->DisableWakeupIsrFunc != NULL_PTR)
		{
			LowlevelDrvFuncPtr->DisableWakeupIsrFunc(ChannelConfigPtr->WakeupChannel);
		}
		LowlevelDrvFuncPtr->DisableWakeupFunc(ChannelConfigPtr->WakeupChannel);

		EcuWakeupM_ExitCriticalSection();

	}   
}

//======================================================================================================================
/** \brief EcuWakeupM_EnableAllWakeups
 **
 ** This function enables all configured ECU wakeup channels.
 **
 ** \param[in] NotifyStatus      Enable/Disable channel wakeup notification.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnableAllWakeups
(
	VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus
)
{
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;

	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_ENABLE_ALL_WAKEUPS, ECUWAKEUPM_E_UNINIT);
	}
	else
	{
		for(Channel =0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			EcuWakeupM_EnableWakeup(Channel,NotifyStatus);
		}
	}
}

//======================================================================================================================
/** \brief EcuWakeupM_DisableAllWakeups
 **
 ** This function disables all configured ECU wakeup channels.
 **
 ** \param[in] None.
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_DisableAllWakeups(void)
{
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;

	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_DISABLE_ALL_WAKEUPS, ECUWAKEUPM_E_UNINIT);
	}
	else
	{
		for(Channel=0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			EcuWakeupM_DisableWakeup(Channel);
		}
	}

}

//======================================================================================================================
/** \brief EcuWakeupM_SetNotification
 **
 ** This function enables/disables the notification of an ECU wakeup channel.
 **
 ** \param[in] Channel        Wakeup channel ID.
 ** \param[in] NotifyStatus   TRUE/FALSE wakeup notification.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_SetNotification
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel,
	VAR(EcuWakeupM_NotifyStatusType, AUTOMATIC) NotifyStatus
)
{
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_SET_NOTIFICATION, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_SET_NOTIFICATION, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{

	    EcuWakeupM_EnterCriticalSection();
		
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)             DrvFuncPtr;
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
		EcuWakeupM_LowlevelDrvFuncTblType                                                   LowlevelDrvFuncPtr;

    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
		 
		DrvFuncPtr                  = ChannelConfigPtr->GetDrvFuncTable();
		LowlevelDrvFuncPtr 		  	= DrvFuncPtr->LowlevelDrvFunc;
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 
		
		if(NotifyStatus == TRUE)
		{
			LowlevelDrvFuncPtr->EnableNotificationCbk(ChannelConfigPtr->WakeupChannel);
			ChannelStatePtr->NotifyStatus = TRUE;
		}
		else
		{
			LowlevelDrvFuncPtr->DisableNotificationCbk(ChannelConfigPtr->WakeupChannel);
			ChannelStatePtr->NotifyStatus = FALSE;
		} 
		
		EcuWakeupM_ExitCriticalSection();
	}
}


//======================================================================================================================
/** \brief EcuWakeupM_ManageWakeup
 **
 ** This function process the wakeup and notifies wakeup source to service layer .
 **
 ** \param[in] WakeupSource        Wakeup channel ID.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_ManageWakeup
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel
)
{
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_MANAGE_WAKEUP, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_MANAGE_WAKEUP, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{
	
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
    	
    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		GenericConfigPtr            = ConfigPtr->GenericPtr;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 

		EcuWakeupM_DisableWakeup(Channel);
		ChannelStatePtr->WakeupStatus = TRUE;
		if(GenericConfigPtr->EcuAppMCbk != NULL_PTR)
		{
			GenericConfigPtr->EcuAppMCbk(ChannelConfigPtr->EcuMWakeupSource);
		}
		if(ChannelConfigPtr->UserCbk != NULL_PTR)
		{
			ChannelConfigPtr->UserCbk();
		}

	}
}

//======================================================================================================================
/** \brief EcuWakeupM_CheckWakeup
 **
 ** This function calls Check wakeup serivce of the low level layer.
 **
 ** \param[in] WakeupSource        ECUM Wakeup Source ID.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_CheckWakeup
(
	VAR(EcuWakeupM_EcuMWakeupSourceType,AUTOMATIC) WakeupSource
)
{
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_CHECK_WAKEUP, ECUWAKEUPM_E_UNINIT);
	}
	else
	{
	
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)             DrvFuncPtr;
		EcuWakeupM_LowlevelDrvFuncTblType                                                   LowlevelDrvFuncPtr;
		
		VAR(EcuWakeupM_ChannelType, AUTOMATIC) 	Channel;

    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		EcuWakeupM_GetWakeupChannel(WakeupSource,&Channel);
		
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
		DrvFuncPtr                  = ChannelConfigPtr->GetDrvFuncTable();
		LowlevelDrvFuncPtr 		  	= DrvFuncPtr->LowlevelDrvFunc;

		if(LowlevelDrvFuncPtr->CheckWakeupFunc != NULL_PTR)
		{
			LowlevelDrvFuncPtr->CheckWakeupFunc(ChannelConfigPtr->EcuMWakeupSource);
		}
	}
}


//======================================================================================================================
/** \brief EcuWakeupM_GetWakeupChannel
 **
 ** This function returns the wakeup channel corresponding to EcuM wakeup source.
 **
 ** \param[in] WakeupSource        ECUM Wakeup Source ID.
 ** \param[in] ChannelData         Pointer to Channel Data.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_GetWakeupChannel
(
	VAR(EcuWakeupM_EcuMWakeupSourceType,AUTOMATIC) WakeupSource,
	P2VAR(EcuWakeupM_ChannelType, AUTOMATIC, ECUWAKEUPM_APPL_DATA) ChannelData
)
{
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_GET_WAKEUP_CHANNEL, ECUWAKEUPM_E_UNINIT);
	}
	else if(ChannelData == NULL_PTR)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_GET_WAKEUP_CHANNEL, ECUWAKEUPM_E_PARAM_POINTER);
    }
	else 
	{
		
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;

    	ConfigPtr         = &EcuWakeupM_ConfigData;

		for(Channel=0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			ChannelConfigPtr   = &(ConfigPtr->ChannelPtr[Channel]); 
			if(ChannelConfigPtr->EcuMWakeupSource == WakeupSource)
			{
				break;
			}
		}
		if( Channel == ECUWAKEUPM_NUMBER_OF_CHANNELS)
		{
			EcuWakeupM_ReportError(ECUWAKEUPM_API_GET_WAKEUP_CHANNEL, ECUWAKEUPM_E_INVALID_WAKEUP_SOURCE);
		}
		else
		{
			*ChannelData = Channel;  
		}
	}
}

//======================================================================================================================
/** \brief EcuWakeupM_ScanWakeupChannel
 **
 ** This function scans the wakeup channel and marks the wakeup status as True.
 **
 ** \param[in] Channel        Wakeup channel ID.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ScanWakeupChannel
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel
)
{
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_SCAN_WAKEUP_CHANNEL, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_SCAN_WAKEUP_CHANNEL, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{
		
		
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2CONST(EcuWakeupM_LowlevelDrvFunc_t, AUTOMATIC, ECUWAKEUPM_APPL_CONST)             DrvFuncPtr;
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
		EcuWakeupM_LowlevelDrvFuncTblType                                                   LowlevelDrvFuncPtr;
		VAR(EcuWakeupM_EcuMWakeupSourceType, AUTOMATIC) WakeupSource;

    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		GenericConfigPtr            = ConfigPtr->GenericPtr;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
		DrvFuncPtr                  = ChannelConfigPtr->GetDrvFuncTable();
		LowlevelDrvFuncPtr 		  	= DrvFuncPtr->LowlevelDrvFunc;
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 
		
		if((LowlevelDrvFuncPtr != NULL_PTR) && (LowlevelDrvFuncPtr->CheckWakeupIsrFunc != NULL_PTR))
		{  
			if( LowlevelDrvFuncPtr->CheckWakeupIsrFunc(ChannelConfigPtr->WakeupChannel) != 0u)
			{
				ChannelStatePtr->WakeupStatus = TRUE;
			}
		}
		
		/* If Low level driver not maintaining the wakeup status get the status the EcuM BSW module. 
		 * EcuM will be notified by EcuM_CheckWakeup() from the Low level driver ISR.
		 * EcuM_CheckWakeup() will further call low level driver CheckWakeup() call which			
		 * sets the wakeup source status to EcuM module.
		 */
		if( GenericConfigPtr->ReadWakeupFromServiceLayer != NULL_PTR)
		{
			WakeupSource = GenericConfigPtr->ReadWakeupFromServiceLayer();
			if(((WakeupSource) & (ChannelConfigPtr->EcuMWakeupSource)) == ChannelConfigPtr->EcuMWakeupSource)
			{
					ChannelStatePtr->WakeupStatus = TRUE;
			} 
		}
		
	}
}

//======================================================================================================================
/** \brief EcuWakeupM_CheckAllWakeups
 **
 ** This function scans all the wakeup channels and  marks the wakeup status as True.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ScanAllWakeupChannels(void)
{
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_SCAN_ALL_WAKEUP_CHANNELS, ECUWAKEUPM_E_UNINIT);
	}
	else
	{
		VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;
		
		for(Channel=0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			EcuWakeupM_ScanWakeupChannel(Channel);
		}
	}
}


//======================================================================================================================
/** \brief EcuWakeupM_ReportWakeup
 **
 ** This function check the respective channel and report wakeup source to higher layer.
 **
 ** \param[in] Channel        Wakeup channel ID.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(EcuWakeupM_WakeupReportStatusType, ECUWAKEUPM_CODE)EcuWakeupM_ReportWakeupSource
(
	VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel
)
{
	VAR(EcuWakeupM_WakeupReportStatusType, AUTOMATIC) Status = FALSE;
	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_REPORT_WAKEUP_SOURCE, ECUWAKEUPM_E_UNINIT);
	}
	else if( Channel >= ECUWAKEUPM_NUMBER_OF_CHANNELS)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_REPORT_WAKEUP_SOURCE, ECUWAKEUPM_E_PARAM_CHANNEL);
	}
	else
	{
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		P2CONST(EcuWakeupM_ChannelConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         ChannelConfigPtr;
		P2VAR(EcuWakeupM_ChannelStateType, AUTOMATIC, ECUWAKEUPM_APPL_DATA)                 ChannelStatePtr;
		
    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		GenericConfigPtr            = ConfigPtr->GenericPtr;
		ChannelConfigPtr            = &(ConfigPtr->ChannelPtr[Channel]); 
		ChannelStatePtr   			= &(EcuWakeupM_ChannelState[Channel]); 
		
		if(FALSE != ChannelStatePtr->WakeupStatus)
		{
			if(GenericConfigPtr->NotifyWakeupToServiceLayer != NULL_PTR)
			{
				GenericConfigPtr->NotifyWakeupToServiceLayer(ChannelConfigPtr->EcuMWakeupSource);
			}
			if(GenericConfigPtr->EcuAppMCbk != NULL_PTR)
			{
				GenericConfigPtr->EcuAppMCbk(ChannelConfigPtr->EcuMWakeupSource);
			}
			Status = TRUE;
			ChannelStatePtr->WakeupStatus = FALSE;
		}
	}
	return Status; 
}


//======================================================================================================================
/** \brief EcuWakeupM_ReportAllWakeupSources
 **
 ** This function checks all channels and report wakeup source to higher layer.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, ECUWAKEUPM_CODE)EcuWakeupM_ReportAllWakeupSources(void)
{
	VAR(EcuWakeupM_WakeupReportStatusType, AUTOMATIC) Status = FALSE;
    	
	if(EcuWakeupM_InitStatus != ECUWAKEUPM_S_INITIALIZED)
	{
		EcuWakeupM_ReportError(ECUWAKEUPM_API_REPORT_ALL_WAKEUP_SOURCES, ECUWAKEUPM_E_UNINIT);
	}
	else
	{
		P2CONST(EcuWakeupM_ConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)                ConfigPtr;
		P2CONST(EcuWakeupM_GenericConfigDataType, AUTOMATIC, ECUWAKEUPM_APPL_CONST)         GenericConfigPtr;
		VAR(EcuWakeupM_ChannelType, AUTOMATIC) Channel;
		
    	ConfigPtr         			= &EcuWakeupM_ConfigData;
		GenericConfigPtr            = ConfigPtr->GenericPtr;


		for(Channel=0; Channel < ECUWAKEUPM_NUMBER_OF_CHANNELS; Channel++)
		{
			if( FALSE != EcuWakeupM_ReportWakeupSource(Channel))
			{
				Status = TRUE;
			} 
		}
		if(Status == FALSE)
		{
			/* No wakeup detected report Wakeup source as POWER */
			if(GenericConfigPtr->NotifyWakeupToServiceLayer != NULL_PTR)
			{
				GenericConfigPtr->NotifyWakeupToServiceLayer(GenericConfigPtr->EcuMWakeupsourcePower);
			}
			if(GenericConfigPtr->EcuAppMCbk != NULL_PTR)
			{
				GenericConfigPtr->EcuAppMCbk(GenericConfigPtr->EcuMWakeupsourcePower);
			}
		}
	}
}

//======================================================================================================================
/** \brief EcuWakeupM_EnterCriticalSection
 **
 ** This function enters exclusive area (call SchM module).
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_EnterCriticalSection(void)
{
	SchM_Enter_EcuWakeupM_ECUWAKEUPM_EXCLUSIVE_AREA_0();
  
}

//======================================================================================================================
/** \brief EcuWakeupM_ExitCriticalSection
 **
 **  This function exits exclusive area (call SchM module).
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, ECUWAKEUPM_CODE) EcuWakeupM_ExitCriticalSection(void)
{
	SchM_Exit_EcuWakeupM_ECUWAKEUPM_EXCLUSIVE_AREA_0();
}

#define EcuWakeupM_STOP_SEC_CODE
#include "EcuWakeupM_MemMap.h"  

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/






