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
#include "BacklightDrvCdd_I2C.h"
#include "BacklightDrvCdd_I2C_MAX20446.h"


//=====================================================================================================================
//  PREPROCEESSORS
//=====================================================================================================================
#define BACKLIGHTCDD_SAFE_NORMAL   ((uint8)0x00u)
#define BACKLIGHTCDD_SAFE_BLACK    ((uint8)0x01u)


//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Internal_MainFunction(void);
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_UpdateI2CDuty(void);
static FUNC(boolean, CBacklightCdd_CODE) BacklightDrvCdd_IsFaultActive(BacklightDrvCdd_FaultActiveLevelType FltActLvl, boolean FaultSignal);
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Reg_monitor(void);
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Configuration(void);
//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================


//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
#define CBacklightCdd_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

static VAR(uint8, 								CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_SafeStatus 				= BACKLIGHTCDD_SAFE_NORMAL;
static VAR(BacklightdCd_DutyOutInfoType,  		CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_DutyInfo 			    = { (uint16)BACKLIGHTDRVCDD_ZERO, (uint16)BACKLIGHTDRVCDD_ZERO};
static VAR(BacklightDrvCdd_OpStateType, 		CBacklightCdd_VAR_INIT) 	BacklightDrvCdd_OpState 				= BACKLIGHTDRVCDD_STATE_IDLE;
static VAR(uint8,                               CBacklightCdd_VAR_INIT)     BacklightCdd_PON_DelayCounter           =  BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_FaultDiag_DeBounceCounter 	= BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_Error_DeBounceCounter 		= BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_ErrorRecovery_RetryCounter = BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_FaultPin_DeBounceCounter 	= BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 								CBacklightCdd_VAR_INIT)	    Reg_count                               = BACKLIGHTDRVCDD_ZERO;
static VAR(uint8, 							    CBacklightCdd_VAR_INIT)	    BacklightCdd_FltMonDlyCntr 	    		= BACKLIGHTDRVCDD_ZERO;
static VAR(uint8,                               CBacklightCdd_VAR_INIT)     BacklightCdd_CurrentMonReg              = BACKLIGHTCDD_START_TRANSMIT;
static VAR(BacklightCdd_RegMonCfg,         CBacklightCdd_VAR_INIT)          BacklightCdd_RegRuntimeMonitor[BACKLIGHTCDD_MAX_MON_REGS];
static VAR(uint16, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_I2cWriteRetryCount 	        = BACKLIGHTDRVCDD_ZERO;
static VAR(uint16, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_I2cReadRetryCount 	        =  BACKLIGHTDRVCDD_ZERO;
static VAR(uint16, 								CBacklightCdd_VAR_INIT)	    BacklightCdd_PowerOnRetryCount 	        =  BACKLIGHTDRVCDD_ZERO;

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
	VAR(uint8, AUTOMATIC) RegIndex;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	BacklightDrvCdd_SafeStatus 						= BACKLIGHTCDD_SAFE_NORMAL;
	BacklightDrvCdd_DutyInfo.CurrentDutyValue 	    = BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_DutyInfo.LastDutyValue 		    = BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_OpState 						= BACKLIGHTDRVCDD_STATE_IDLE;
	BacklightCdd_FaultDiag_DeBounceCounter 			=  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_Error_DeBounceCounter 				=  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_ErrorRecovery_RetryCounter 		=  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FaultPin_DeBounceCounter 			=  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FltMonDlyCntr                      =  BACKLIGHTDRVCDD_ZERO;
	Reg_count                                       =  BACKLIGHTDRVCDD_ZERO;
    BacklightCdd_I2cWriteRetryCount 	                =  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_PowerOnRetryCount                  =  BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_I2cReadRetryCount 	                =  BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_I2C_Init();

	if (BkltDev->I2cCfg != NULL_PTR)
    {
        for (RegIndex = 0u; RegIndex < BkltDev->I2cCfg->monitorLen; RegIndex++)
        {
            BacklightCdd_RegRuntimeMonitor[RegIndex].timer         = BkltDev->I2cCfg->monitorRegs[RegIndex].monitorTime;
            BacklightCdd_RegRuntimeMonitor[RegIndex].state         = REGMON_IDLE;
        }
    }
    BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
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
	VAR(uint8, AUTOMATIC) RegIndex;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	BacklightDrvCdd_SafeStatus 						= BACKLIGHTCDD_SAFE_NORMAL;
	BacklightDrvCdd_DutyInfo.CurrentDutyValue 	    = BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_DutyInfo.LastDutyValue 		    = BACKLIGHTDRVCDD_ZERO;
	BacklightDrvCdd_OpState 						= BACKLIGHTDRVCDD_STATE_IDLE;
	BacklightCdd_FaultDiag_DeBounceCounter 			= BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_Error_DeBounceCounter 				= BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_ErrorRecovery_RetryCounter 		= BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FaultPin_DeBounceCounter 			= BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_FltMonDlyCntr                      = BACKLIGHTDRVCDD_ZERO;
	Reg_count                                       = BACKLIGHTDRVCDD_ZERO;
    BacklightCdd_I2cWriteRetryCount 	                = BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_PowerOnRetryCount                  = BACKLIGHTDRVCDD_ZERO;
	BacklightCdd_I2cReadRetryCount 	                = BACKLIGHTDRVCDD_ZERO;
	if (BkltDev->I2cCfg != NULL_PTR)
    {
        for (RegIndex = 0u; RegIndex < BkltDev->I2cCfg->monitorLen; RegIndex++)
        {
            BacklightCdd_RegRuntimeMonitor[RegIndex].timer         = BkltDev->I2cCfg->monitorRegs[RegIndex].monitorTime;
            BacklightCdd_RegRuntimeMonitor[RegIndex].state         = REGMON_IDLE;
        }
    }
    BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
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

	(void)deviceId;
	
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
	BacklightDrvCdd_DutyInfo.CurrentDutyValue = duty;
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
/** \brief BacklightDrvCdd_UpdateDuty
 **
 ** This function initializes  duty.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_UpdateI2CDuty(void)
{
	VAR(Std_ReturnType,            AUTOMATIC) ret = E_NOT_OK;

	/*Check if current duty is different from previous*/
	if(BacklightDrvCdd_DutyInfo.CurrentDutyValue != BacklightDrvCdd_DutyInfo.LastDutyValue)
	{
		/*Set  duty*/
		ret =  BacklightDrvCdd_Process_Set_Brightness(BacklightDrvCdd_DutyInfo.CurrentDutyValue);

		if(ret == E_OK)
		{
			/*Update LastDutyValue*/		
			BacklightDrvCdd_DutyInfo.LastDutyValue = BacklightDrvCdd_DutyInfo.CurrentDutyValue;
		}
	}
	else
	{
		/*Do nothing - As same duty remains*/
	}
}

//======================================================================================================================
/** \brief BacklightDrvCdd_Reg_monitor
 **
 ** This function monitors HW_RST bit every 1sec.
 **
 ** \param[in] None.
 **
 ** \return    None.
 **
 ** */
//======================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Reg_monitor(void)
{
    VAR(uint8,            AUTOMATIC) RegIndex;
    VAR(uint8,            AUTOMATIC) Reg_val;
    VAR(Std_ReturnType,   AUTOMATIC) I2c_read_AsyncSts;
    VAR(I2c_SeqResultType,   AUTOMATIC) I2c_read_GetSeqSts;
	VAR(I2c_SeqResultType,   AUTOMATIC) I2c_write_GetSeqSts;

	const BacklightCdd_IOFuncType *iotbptr = &BacklightCdd_IOTable;

	VAR(IoHwAb_ErrorType, AUTOMATIC) Err;
    
	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

    if (BkltDev->I2cCfg != NULL_PTR)
    {
		for (RegIndex = 0u; RegIndex < BkltDev->I2cCfg->monitorLen; RegIndex++)
		{
			/* Timer countdown, only while idle */
			if (BacklightCdd_RegRuntimeMonitor[RegIndex].state == REGMON_IDLE)
			{
				if (BacklightCdd_RegRuntimeMonitor[RegIndex].timer > BACKLIGHTDRVCDD_ZERO)
				{
					BacklightCdd_RegRuntimeMonitor[RegIndex].timer--;
				}

				if (BacklightCdd_RegRuntimeMonitor[RegIndex].timer == BACKLIGHTDRVCDD_ZERO)
				{
					BacklightCdd_RegRuntimeMonitor[RegIndex].state = REGMON_PENDING;
				}
			}
			
			switch (BacklightCdd_RegRuntimeMonitor[RegIndex].state)
			{
				case REGMON_IDLE:
					/* still counting down */
					break;

				case REGMON_PENDING:
					/* Only proceed if no other register currently in use. */
					if (BacklightCdd_CurrentMonReg == BACKLIGHTCDD_START_TRANSMIT) 
					{
						I2c_read_GetSeqSts  = BacklightCdd_I2cGetSeqResult(BkltDev->I2cCfg->i2cSeqIdRead);
						I2c_write_GetSeqSts = BacklightCdd_I2cGetSeqResult(BkltDev->I2cCfg->i2cSeqIdWrite);

						if ((I2c_read_GetSeqSts != I2C_SEQ_PENDING) && ((I2c_write_GetSeqSts != I2C_SEQ_PENDING)))
						{
							I2c_read_AsyncSts = BacklightCdd_I2cAsyncRegRead(BkltDev->I2cCfg->monitorRegs[RegIndex].Reg, RegIndex);

							if (E_OK == I2c_read_AsyncSts)
							{
								BacklightCdd_CurrentMonReg            = RegIndex;     /* claim the bus */
								BacklightCdd_RegRuntimeMonitor[RegIndex].state = REGMON_BUSY;
							}
						}
						else
						{
							if(I2C_SEQ_PENDING == I2c_read_GetSeqSts)
							{
								BacklightCdd_I2cCancel(BkltDev->I2cCfg->i2cSeqIdRead);
								BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
							}

							if(I2C_SEQ_PENDING == I2c_write_GetSeqSts)
							{
								BacklightCdd_I2cCancel(BkltDev->I2cCfg->i2cSeqIdWrite);
								BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
							}
						}
					}
					break;

				case REGMON_BUSY:

					I2c_read_GetSeqSts  = BacklightCdd_I2cGetSeqResult(BkltDev->I2cCfg->i2cSeqIdRead);

					if (I2c_read_GetSeqSts == I2C_SEQ_OK)
					{
						BacklightCdd_I2cGetRxData(&Reg_val, RegIndex);

						if (((Reg_val & BkltDev->I2cCfg->monitorRegs[RegIndex].mask) !=
							(BkltDev->I2cCfg->monitorRegs[RegIndex].CfgVal & BkltDev->I2cCfg->monitorRegs[RegIndex].mask)))
						{
							switch (BkltDev->I2cCfg->monitorRegs[RegIndex].SafetyAction)
							{
								case BACKLIGHT_INIT:
									BacklightDrvCdd_Init();

									(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

									(void)BacklightDrvCdd_RequestPower(BACKLIGHTDRVCDD_ZERO, BACKLIGHTDRVCDD_POWER_STATE_POWER_ON);
									break;
								case BACKLIGHT_SAFESTATE:
									/* TBD */
									break;
								default:
									break;
							}
						}

						/* release bus, reload timer, go idle */
						BacklightCdd_CurrentMonReg             = BACKLIGHTCDD_START_TRANSMIT;
						BacklightCdd_RegRuntimeMonitor[RegIndex].timer  = BkltDev->I2cCfg->monitorRegs[RegIndex].monitorTime;
						BacklightCdd_RegRuntimeMonitor[RegIndex].state  = REGMON_IDLE;
					}
					else
					{
						if(I2C_SEQ_PENDING == I2c_read_GetSeqSts)
						{
							BacklightCdd_I2cCancel(BkltDev->I2cCfg->i2cSeqIdRead);
							BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
						}
						else
						{
							BacklightCdd_RegRuntimeMonitor[RegIndex].state  = REGMON_PENDING;
							BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;
						}

					}
					break;

				default:
					break;
			}
		}
	}
	else
	{
		/*Invalid - Do Nothing */
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
/** \brief BacklightDrvCdd_Configuration
 **
 ** This function will configure the BL if voltage is normal
 **
 ** \return    none.
 **
 ** */
//======================================================================================================================
static FUNC(void, CBacklightCdd_CODE) BacklightDrvCdd_Configuration(void)
{
	VAR(I2c_SeqResultType, AUTOMATIC) I2c_write_GetSeqSts;
	VAR(I2c_SeqResultType, AUTOMATIC) I2c_read_GetSeqSts;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	const BacklightCdd_IOFuncType *iotbptr = &BacklightCdd_IOTable;

	VAR(IoHwAb_ErrorType, AUTOMATIC) Err;

	if(Reg_count < REG_COUNT_I2C)
	{
		I2c_read_GetSeqSts  = BacklightCdd_I2cGetSeqResult(BkltDev->I2cCfg->i2cSeqIdRead);
		I2c_write_GetSeqSts = BacklightCdd_I2cGetSeqResult(BkltDev->I2cCfg->i2cSeqIdWrite);

		if( ( ( I2C_SEQ_OK == I2c_write_GetSeqSts ) || ( I2C_SEQ_CANCELLED == I2c_write_GetSeqSts  ) ) && ( ( I2C_SEQ_OK == I2c_read_GetSeqSts ) || ( I2C_SEQ_CANCELLED == I2c_read_GetSeqSts  ) ) ) 
		{		
			if(E_OK == BacklightCdd_I2cWriteReg(BkltDev->I2cCfg->RegTable[Reg_count], BkltDev->I2cCfg->data[Reg_count]))
			{
				Reg_count++;
				BacklightCdd_I2cWriteRetryCount = 0u; //reset retry count for next register write
			}
			else 
			{
				if(BacklightCdd_PowerOnRetryCount < BkltDev->PowerOnRecoveryMaxRetryCnt)
				{
					if(BacklightCdd_I2cWriteRetryCount >= BkltDev->I2cFailMaxRetryCount)
					{
						BacklightCdd_PowerOnRetryCount++;
						(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err); 
						/* Go to power on and restart the configuration */
						BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_POWER_ON;
					}
					else
					{
						BacklightCdd_I2cWriteRetryCount++;
					}
				}
				else
				{
					/* report I2C error and move to safe state */
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE;
					BacklightCdd_PowerOnRetryCount = 0u;
				}
			}
		}
		
		else 
		{
			if(I2C_SEQ_PENDING == I2c_read_GetSeqSts)
			{
				BacklightCdd_I2cCancel(BkltDev->I2cCfg->i2cSeqIdRead);	
			}
			
			if(I2C_SEQ_PENDING == I2c_write_GetSeqSts)
			{
				BacklightCdd_I2cCancel(BkltDev->I2cCfg->i2cSeqIdWrite);
			}

			if(BacklightCdd_PowerOnRetryCount < BkltDev->PowerOnRecoveryMaxRetryCnt )
			{
				BacklightCdd_PowerOnRetryCount++;

				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err); 
				/* Go to power on and restart the configuration */
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_POWER_ON;					
			}
			else
			{
				/* report I2C error and move to safe state */
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE;
				BacklightCdd_PowerOnRetryCount = 0u;
			}
		}
	}
	else
	{
		BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
		Reg_count = 0u; //reset register count for next time configuration is needed
		BacklightCdd_I2cWriteRetryCount = 0u; //reset retry count for next time configuration is needed	
		BacklightCdd_PowerOnRetryCount = 0u;
	}
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
    
	VAR(boolean, AUTOMATIC) bFault_state = TRUE;
	
	VAR(boolean, AUTOMATIC) bIsFaultPresent;
	 
    VAR(IoHwAb_ErrorType, AUTOMATIC) Err;

	const BacklightCdd_IOFuncType *iotbptr = &BacklightCdd_IOTable;
	
	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;
                   
	(void)iotbptr->IoHwAbReadChannel(BkltDev->Backlight_FaultPinDInID, &bFault_state, &Err);

	VAR(uint8,  AUTOMATIC) RegIndex;

	bIsFaultPresent = BacklightDrvCdd_IsFaultActive(BkltDev->Backlight_FaultActiveLevel, bFault_state);


	switch(BacklightDrvCdd_OpState)
	{
		/* Check power on request received */
		case BACKLIGHTDRVCDD_STATE_IDLE:                               
		                                                           
			// Do nothing
		break;
		
		/* Run initialization procedure */
		case BACKLIGHTDRVCDD_STATE_POWER_ON: 

			if(OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
			{
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->EnableLevel, &Err); 
				
				BacklightCdd_PON_DelayCounter = 0u;

				if (BkltDev->I2cCfg != NULL_PTR)
   				{
   				    for (RegIndex = 0u; RegIndex < BkltDev->I2cCfg->monitorLen; RegIndex++)
   				    {
   				        BacklightCdd_RegRuntimeMonitor[RegIndex].timer         = BkltDev->I2cCfg->monitorRegs[RegIndex].monitorTime;
   				        BacklightCdd_RegRuntimeMonitor[RegIndex].state         = REGMON_IDLE;
   				        
   				    }
   				}

    			BacklightCdd_CurrentMonReg = BACKLIGHTCDD_START_TRANSMIT;

				Reg_count = 0u;

				BacklightCdd_I2cWriteRetryCount = 0u;

				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT;
			}
		break;
 
		case BACKLIGHTDRVCDD_STATE_POWER_ON_WAIT:

		    if(BACKLIGHTCDD_UINT8_MAX > BacklightCdd_PON_DelayCounter)
			{
				BacklightCdd_PON_DelayCounter++;

				if(OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
				{
					if(BkltDev->PowerOnDelayCnt <= BacklightCdd_PON_DelayCounter)
					{	

						BacklightDrvCdd_DutyInfo.CurrentDutyValue = 0U;
						BacklightDrvCdd_DutyInfo.LastDutyValue	  = 0U;
						
						/*The 0x1F register is read at initial stage which clears the HW_RST bit*/
						if(E_OK != BacklightCdd_I2cAsyncRegRead(DIAG_REGISTER_ADDRESS, 0 ))
						{
							if(BacklightCdd_I2cReadRetryCount < BkltDev->I2cFailMaxRetryCount)
							{
								/*Wait in power-on-wait and try to read for max retry counts*/
								BacklightCdd_I2cReadRetryCount++;
							}
							else
							{
								BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE;
								BacklightCdd_I2cReadRetryCount = 0u;
							}
						}
						else
						{
							BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_CONFIGURE;

							BacklightCdd_PON_DelayCounter = 0u;

							BacklightCdd_FltMonDlyCntr = BkltDev->Backlight_FaultMonDelayCnt;

							BacklightCdd_I2cReadRetryCount = 0u;
						}
					}
				}
				else
				{
					(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;
				}
		    }

		break;

		case BACKLIGHTDRVCDD_STATE_CONFIGURE:
			if( OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
			{
				BacklightDrvCdd_Configuration();
			}
			else
			{
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;
				Reg_count = 0u; //reset register count for next time configuration is needed
				BacklightCdd_I2cWriteRetryCount = 0u; //reset retry count for next time configuration is needed	
				BacklightCdd_PowerOnRetryCount = 0u;
			}
			
		break;

		case BACKLIGHTDRVCDD_STATE_NORMAL:
			/* (1) Voltage range validation based on input from EcuBatteryM */
			if(OperatingVoltage_Normal != CBACKLIGHTCDD_OPERATINGMODE())
			{				
				BacklightDrvCdd_DutyInfo.LastDutyValue = 0u;
				
				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;

			}
			else
			{
				/* (2) Fault monitoring based on DI_MD_BKLT_FAULT */
				/* Fault signal is read via IoHwAb with Debounce */
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
					CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId, 0u);

					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_SAFETYREACTION;
				}

				/* (4) Monitoring required backlight registers*/
				BacklightDrvCdd_Reg_monitor();
			
				BacklightDrvCdd_UpdateI2CDuty();
			}

		break;

		case BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION:

			if(OperatingVoltage_Normal == CBACKLIGHTCDD_OPERATINGMODE())
			{
					
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
						(void) CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId,0u);

						BacklightDrvCdd_UpdateI2CDuty();

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
					(void) CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId, 0u);

					(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_OV_UV_PROTECTION;
				}
				else
				{                                                                     
					(void) CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId,BacklightDrvCdd_DutyInfo.LastDutyValue);

					BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_NORMAL;
				}
			}
		break;

		case BACKLIGHTDRVCDD_STATE_ERROR:

			if(( BACKLIGHTCDD_UINT8_MAX > BacklightCdd_Error_DeBounceCounter) && (BACKLIGHTCDD_UINT8_MAX > BacklightCdd_FaultPin_DeBounceCounter))
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
							BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_CONFIGURE;

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
				(void) CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId, 0u);

				(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE;
			}
			else
			{
				BacklightDrvCdd_OpState = BACKLIGHTDRVCDD_STATE_CONFIGURE;	
			}
		break;
		
		case BACKLIGHTDRVCDD_STATE_PERMANENT_SAFESTATE:
			/* do nothing */
		break;

		case BACKLIGHTDRVCDD_STATE_POWER_OFF: 

			(void) CBacklightCdd_SetBrightnessValue(BkltDev->DeviceId, 0u);
			
			BacklightDrvCdd_DutyInfo.LastDutyValue = 0u;

			(void) iotbptr->IoHwAbWriteChannel(BkltDev->Backlight_EnableDoutID, BkltDev->DisableLevel, &Err);

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
                      Added fault monitoring mask timer to avoid faults during power on.
					  For CUPRA ABT instead of I2c_Channel , I2c_SeqID provided.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 17-04-26
CDSID             	: mmahend2
Traceability      	: ASCDD-357
Change Description	: After Fault recovery action the state updated to BACKLIGHTDRVCDD_STATE_CONFIGURE .
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 17-06-26
CDSID             	: bmahesan
Traceability      	: ASCDD-920
Change Description	: Updated logic to request zero duty for backlight poweroff case MAX20446B/LP8867.
================================================================================================================================================*/


