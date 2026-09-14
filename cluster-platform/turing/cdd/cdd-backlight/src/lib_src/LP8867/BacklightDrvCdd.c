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
#include "Rte_CBacklightCdd.h"
#include "BacklightCdd.h"
#include "BacklightDrvCdd.h"


//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================
#define BACKLIGHTCDD_SAFE_NORMAL   ((uint8)0x00u)
#define BACKLIGHTCDD_SAFE_BLACK    ((uint8)0x01u)


//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Internal_MainFunction(void);
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_UpdatePwmDuty(BacklightCdd_PwmChannelType BkltPwmChnId, 
	                                                                const BacklightCdd_IOFuncType *io);
static FUNC(boolean, CBacklightCdd_CODE) BacklightDrvCdd_IsFaultActive(BacklightDrvCdd_FaultActiveLevelType FltActLvl, boolean FaultSignal);

//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
#define CBacklightCdd_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

static VAR(uint8, 							CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_SafeStatus 				= BACKLIGHTCDD_SAFE_NORMAL;
static VAR(BacklightdCd_DutyOutInfoType,	CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_PwmDutyInfo 			= { (uint16)BACKLIGHTDRVCDD_ZERO, (uint16)BACKLIGHTDRVCDD_ZERO};
static VAR(BacklightDrvCdd_OpStateType, 	CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_OpState 				= BACKLIGHTDRVCDD_STATE_IDLE;
static VAR(uint8,                           CBacklightCdd_VAR_INIT)     BacklightCdd_PON_DelayCounter           = (uint8) BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							CBacklightCdd_VAR_INIT)	    BacklightCdd_FaultDiag_DeBounceCounter 	= (uint8) BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							CBacklightCdd_VAR_INIT)	    BacklightCdd_Error_DeBounceCounter 		= (uint8) BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							CBacklightCdd_VAR_INIT)	    BacklightCdd_ErrorRecovery_RetryCounter = (uint8) BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							CBacklightCdd_VAR_INIT)	    BacklightCdd_FaultPin_DeBounceCounter 	= (uint8) BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							CBacklightCdd_VAR_INIT)	    BacklightCdd_FltMonDlyCntr 	    = (uint8) BACKLIGHTDRVCDD_ZERO;

#define CBacklightCdd_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================

#define CBacklightCdd_START_SEC_CODE
#include "MemMap.h"

//======================================================================================================================
/** \brief BacklightDrvCdd_Init
 **
 ** This function initializes backlight cdd.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Init(void)
{
	BacklightDrvCdd_SafeStatus 						= BACKLIGHTCDD_SAFE_NORMAL;
	BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue 	= (uint16)BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_PwmDutyInfo.LastDutyValue 		= (uint16)BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_OpState 						= BACKLIGHTDRVCDD_STATE_IDLE;
	BacklightCdd_FaultDiag_DeBounceCounter 			= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_Error_DeBounceCounter 				= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_ErrorRecovery_RetryCounter 		= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FaultPin_DeBounceCounter 			= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FltMonDlyCntr               = (uint8) BACKLIGHTDRVCDD_ZERO;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_DeInit
 **
 ** This function de init backlight cdd.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_DeInit(void)
{
	BacklightDrvCdd_SafeStatus 						= BACKLIGHTCDD_SAFE_NORMAL;
	BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue 	= (uint16)BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_PwmDutyInfo.LastDutyValue 		= (uint16)BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_OpState 						= BACKLIGHTDRVCDD_STATE_IDLE;
	BacklightCdd_FaultDiag_DeBounceCounter 			= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_Error_DeBounceCounter 				= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_ErrorRecovery_RetryCounter 		= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FaultPin_DeBounceCounter 			= (uint8) BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FltMonDlyCntr               = (uint8) BACKLIGHTDRVCDD_ZERO;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_RequestPower
 **
 ** This function initializes Backlight driver power up/down sequence.
 **
 ** \param[in] deviceId      Device ID
 **            state         Requested power state
 **  
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_RequestPower
(
	VAR(uint8, AUTOMATIC)deviceId, 
	VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;
	
	BacklightDrvCdd_OpState = (BacklightDrvCdd_OpStateType) state;
	
	ret = E_OK;

	return ret;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_SetBrightness
 **
 ** This function updated Backligh driver pwm duty.
 **
 ** \param[in] deviceId      Device ID
 **            duty          Target duty
 **           
 ** \return    E_OK          Request accepted.
 **            E_NOT_OK      Device busy, Request not accepted
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_SetBrightness
(
	VAR(uint8, AUTOMATIC)deviceId, 
	VAR(uint16, AUTOMATIC)duty
)
{
	Std_ReturnType ret = E_NOT_OK;

	(void)deviceId;

	/*Update the CurrentDutyValue*/
	BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue = duty;
	ret = E_OK;

	return ret;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_GetStatus
 **
 ** This function returns device current status.
 **
 ** \param[in] device        device Id.
 **    
 **
 ** \return    DeviceStatus  Current status of device  
 **            
 **
 ** */
//======================================================================================================================
FUNC(EDeviceStatus, CBacklightCdd_CODE) BacklightDrvCdd_GetStatus
(
	VAR(uint8, AUTOMATIC)deviceId
)
{
	(void)deviceId;

	return (EDeviceStatus) BacklightDrvCdd_OpState;	
}
//======================================================================================================================
/** \brief BacklightDrvCdd_EnterSafeState
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_EnterSafeState(void)
{
	BacklightDrvCdd_SafeStatus = BACKLIGHTCDD_SAFE_BLACK;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_ExitSafeState
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_ExitSafeState(void)
{
	BacklightDrvCdd_SafeStatus = BACKLIGHTCDD_SAFE_NORMAL;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_MainFunction
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_MainFunction(void)
{
	BacklightDrvCdd_Internal_MainFunction();
}

//======================================================================================================================
/** \brief BacklightDrvCdd_UpdatePwmDuty
 **
 ** This function initializes PWM duty.
 **
 ** \param[in] BkltPwmChnId PWM channel ID.
 **            io           IO FUNCTION TABLE
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_UpdatePwmDuty(BacklightCdd_PwmChannelType BkltPwmChnId, const BacklightCdd_IOFuncType *io)
{
	VAR(IoHwAb_ErrorType, AUTOMATIC) Err;

	/*Check if current duty is different from previous*/
	if(BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue != BacklightDrvCdd_PwmDutyInfo.LastDutyValue)
	{
		if (BACKLIGHTDRVCDD_STATE_SAFETYREACTION != BacklightDrvCdd_OpState)
		{
			/*Set PWM duty*/
			(void)io->IoHwAbSetDuty(BkltPwmChnId, BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue, &Err);
		}

		/*Update LastDutyValue*/		
		BacklightDrvCdd_PwmDutyInfo.LastDutyValue = BacklightDrvCdd_PwmDutyInfo.CurrentDutyValue;
	}
	else
	{
		/*Do nothing - As same duty remains*/
	}
}

//======================================================================================================================
/** \brief BacklightDrvCdd_IsFaultActive
 **
 ** This function Validates backlight fault.
 **
 ** \param[in] BacklightDrvCdd_FaultActiveLevelType Fault signal active level.
 **            boolean                              debounces signal level
 **
 ** \return    boolen.
 **
 ** */
//======================================================================================================================
static FUNC(boolean, CBacklightCdd_CODE) BacklightDrvCdd_IsFaultActive(BacklightDrvCdd_FaultActiveLevelType FltActLvl, boolean FaultSignal)
{
	boolean FaultActive;
	
  /*|=====================================|
	| Config      |    Input  |    Output |
	|=====================================| 
	| ACTIVE_LOW  |    FALSE  |    TRUE   |
	| ACTIVE_LOW  |    TRUE   |    FALSE  |
	| ACTIVE_HIGH |    TRUE   |    TRUE   |
	| ACTIVE_HIGH |    FALSE  |    FALSE  |
	|=====================================|*/
	
	if(FltActLvl == BACKLIGHTDRVCDD_FAULT_ACTIVE_ON_LOW)
	{
		FaultActive = (FaultSignal == FALSE);
	}
	else
	{
		FaultActive =  FaultSignal;
	}

	return FaultActive;
}

//======================================================================================================================
/** \brief BacklightDrvCdd_Internal_MainFunction
 **
 ** This function initializes .
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Internal_MainFunction(void)
{
	VAR(boolean, AUTOMATIC) bFault_state = FALSE;

	VAR(boolean, AUTOMATIC) bIsFaultPresent;
	 
    VAR(IoHwAb_ErrorType, AUTOMATIC) Err;

	const BacklightCdd_IOFuncType *iotbptr = &BacklightCdd_IOTable;
	
	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;
                   
	(void)iotbptr->IoHwAbReadChannel(BkltDev->Backlight_FaultPinDInID, &bFault_state, &Err);

	bIsFaultPresent = BacklightDrvCdd_IsFaultActive(BkltDev->Backlight_FaultActiveLevel, bFault_state);

	switch(BacklightDrvCdd_OpState)
	{
		/* Check power on request received */
		case BACKLIGHTDRVCDD_STATE_IDLE:                               
		                                                           
			//Do nothing

		break;
		
		/* Run initialization procedure */
		case BACKLIGHTDRVCDD_STATE_POWER_ON: 

			if(OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
			{
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->EnableLevel, &Err); 
				
				BacklightCdd_PON_DelayCounter = 0u;
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT;
			}
		break;
 
		case BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT:

		    if(BACKLIGHTCDD_UINT8_MAX > BacklightCdd_PON_DelayCounter)
			{
				BacklightCdd_PON_DelayCounter++;

            	if(BkltDev->PowerOnDelayCnt <= BacklightCdd_PON_DelayCounter)
				{
					(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, BacklightDrvCdd_PwmDutyInfo.LastDutyValue);
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
					BacklightCdd_PON_DelayCounter = 0u;
					BacklightCdd_FltMonDlyCntr = BkltDev->Backlight_FaultMonDelayCnt;
				}
		    }
		break;

		case BACKLIGHTDRVCDD_STATE_NORMAL:
			/* (1) Voltage range validation based on input from EcuBatteryM */
			if(OperatingVoltage_Normal != CBACKLIGHTCDD_OPERATINGMODE())
			{
				(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, 0u);

				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;
			}

			/* (2) Fault monitoring based on DI_MD_BKLT_FAULT */
			/* Fault signal is read via IoHwAb with 40ms Debounce */
			if(BacklightCdd_FltMonDlyCntr > 0u)
			{
				BacklightCdd_FltMonDlyCntr--;
			}
			else
			{
				if(FALSE != bIsFaultPresent)
				{
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_FAULTDIAG;
				}
			}
			
			

			/* (3) Check whether safe state request received from other components*/
			if(BACKLIGHTCDD_SAFE_NORMAL != BacklightDrvCdd_SafeStatus)
			{
				(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, 0u);

				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_SAFETYREACTION;
			}
			BacklightDrvCdd_UpdatePwmDuty(BkltDev->PwmCfg->Backlight_PwmId, iotbptr);
		break;

		case BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION:

			if(OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
			{
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->EnableLevel, &Err);
					
				(void)iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
					
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->EnableLevel, &Err);
					
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT;
			}
		break;


		case BACKLIGHTDRVCDD_STATE_FAULTDIAG:

			if(BACKLIGHTCDD_UINT8_MAX > BacklightCdd_FaultDiag_DeBounceCounter)
			{
				BacklightCdd_FaultDiag_DeBounceCounter++;
				if(BACKLIGHTDRVCDD_SIX/* <....cycles * 10mS (TASK Period) = 60mS */ <= BacklightCdd_FaultDiag_DeBounceCounter)
				{
					if(FALSE != bIsFaultPresent)
					{
						(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId,0u);
						BacklightDrvCdd_UpdatePwmDuty(BkltDev->PwmCfg->Backlight_PwmId, iotbptr);
						BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_ERROR;	
					}
					else
					{
						BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
						BacklightCdd_FaultDiag_DeBounceCounter = 0;
					}
				}
			}
		break;

		case BACKLIGHTDRVCDD_STATE_SAFETYREACTION:

			if(BACKLIGHTCDD_SAFE_NORMAL == BacklightDrvCdd_SafeStatus)
			{
				if(OperatingVoltage_Normal != CBACKLIGHTCDD_OPERATINGMODE())
				{
					(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, 0u);
					(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;
				}
				else
				{                                                                     
					(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId,BacklightDrvCdd_PwmDutyInfo.LastDutyValue);
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
				}
			}
		break;

		case BACKLIGHTDRVCDD_STATE_ERROR:

			if((BACKLIGHTCDD_UINT8_MAX > BacklightCdd_Error_DeBounceCounter) && (BACKLIGHTCDD_UINT8_MAX > BacklightCdd_FaultPin_DeBounceCounter))
			{
				BacklightCdd_Error_DeBounceCounter++;
				
				(void)iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
				
				if(BACKLIGHTDRVCDD_SIX /* <....cycles * 10mS (TASK Period) = 60mS */ <= BacklightCdd_Error_DeBounceCounter)
				{
					(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->EnableLevel, &Err);

					BacklightCdd_FaultPin_DeBounceCounter++;

					if(BACKLIGHTDRVCDD_TWO < BacklightCdd_FaultPin_DeBounceCounter)
					{
						BacklightCdd_Error_DeBounceCounter = 0;
						BacklightCdd_FaultPin_DeBounceCounter = 0;
						if(FALSE != bIsFaultPresent)
						{
							BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_ERRORRECOVERY;
						}
						else
						{
							BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
							BacklightCdd_ErrorRecovery_RetryCounter = 0;
						}
					}

				}
			}
		break;

		case BACKLIGHTDRVCDD_STATE_ERRORRECOVERY:

			if(BACKLIGHTCDD_UINT8_MAX > BacklightCdd_ErrorRecovery_RetryCounter)
			{
				BacklightCdd_ErrorRecovery_RetryCounter++;
				if(BACKLIGHTDRVCDD_THREE >= BacklightCdd_ErrorRecovery_RetryCounter)
				{
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_ERROR;
				}
				else
				{
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_SAFE;
					BacklightCdd_ErrorRecovery_RetryCounter = 0;
				}
			}
		break;
            
		case BACKLIGHTDRVCDD_STATE_SAFE:
		
			if(FALSE != bIsFaultPresent)
			{
				(void) CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, 0u);
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE;
			}
			else
			{	
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
			}
		
		break;
		
		case BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE:
			/* do nothing */
		break;

		case BACKLIGHTDRVCDD_STATE_POWER_OFF: 

			CBacklightCdd_SetBrightnessValue(BkltDev->PwmCfg->Backlight_PwmId, 0u);
			
			BacklightDrvCdd_UpdatePwmDuty(BkltDev->PwmCfg->Backlight_PwmId, iotbptr);

			(void)iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

			BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_IDLE;

		break;
			
		default:
			/* do nothing */
		break;
    }
}

#define CBacklightCdd_STOP_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************************************
*                                 END OF FILE                                                                      
***********************************************************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*==============================================================================================================================================
Date              	: 03-12-25
CDSID             	: yviswana
Traceability      	: ASCDD-241
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 17-03-26
CDSID             	: bmahesan
Traceability      	: ASCDD-241
Change Description	: Updated Version for MAX20446B/LP8867.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 07-04-26
CDSID             	: mmahend2
Traceability      	: ASCDD-357
Change Description	: Updated Fault monitoring logic.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 08-04-26
CDSID             	: mmahend2
Traceability      	: ASCDD-357
Change Description	: Updated Fault monitoring logic.
                      Added fault monitoring mask timer to avoid faults during power on
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 17-06-26
CDSID             	: bmahesan
Traceability      	: ASCDD-920
Change Description	: Updated logic to request zero duty for backlight poweroff case MAX20446B/LP8867.
================================================================================================================================================*/

