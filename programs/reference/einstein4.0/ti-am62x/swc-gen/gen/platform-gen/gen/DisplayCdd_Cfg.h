/********************************************************************************************************************
 *                                   C O P Y R I G H T                                                               *
 *********************************************************************************************************************
 * Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
 *                                                                                                                   *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
 * rights under all copyright laws to protect this work as a published work, when appropriate.                       *
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
 * without the written authorization of Visteon Corporation.                                                         *
 ********************************************************************************************************************/
/*!*****************************************************************************************************************
 *    @file DisplayCdd_cfg.h
 *    @ingroup Display CDD Configuration
 *    @brief This is Display Pre-compile time configuration header file. It contains definitions of pre-compile time
 *    configuration parameters for the Display module.
 ********************************************************************************************************************/
#ifndef DISPLAYCDD_CFG_H
#define DISPLAYCDD_CFG_H

#include "Rte_Type.h"

#ifndef EBistPatternType
typedef uint8 EBistPatternType;
#endif

#include "Std_Types.h"
#include "IoHwAb_DOut_Cfg.h"
#include "Rte_IoHwAb_Type.h"
#include "DisplayCdd_Types.h"
#include "DisplayIfCdd.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Rte_CDisplayCdd.h"
#include "IoHwAb_DOut.h"
#include "I2c.h"

#if !defined(NULL_PTR)
#define DISP_NULL ((void *)0)
#else
#define DISP_NULL NULL_PTR
#endif

/*!  Macro to inform the Display cdd about total number of Display config  in program (1 to 254)*/

/*!Specify the No of device that we are going to use for autodetect*/
#define CHECK_DISPLAY_COUNT (uint8)2u
#define MAXVALUE (uint8)10u

#define eDisplayI2Cdetect 0U
#define eDisplayBootStrap 1U
#define eDisplayMaxIdentify 2U
typedef uint8 EPowerState;
#define Device (uint8)0u
typedef SDisplaySetPower DisplaySetPowerL;
typedef SDisplayCurrentState DisplayCurrentStateL;
#define DisplayPowerL_On EDisplayPower_On
#define DisplayStateL_On EDisplayState_On
#define EcuAppM_Ucl_Displayshutdown Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData
#define EcuAppM_Ucl_DisplayMgrPowerUp Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData
#define EcuAppM_Ucl_DisplayStatus Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData
#define cDISPLAYCDD_MAX_DEVICE 1u
#define cDISPLAYCDD_DEVICE_0   0u

// Default Value is 2 for Gamma not Supported Programs. Producing misra and coverity warnings if it is less than default val.
#define GMA_WRITE_BUFF_SIZE 2

/*********************************************************************************************
 *     Declare Program Specific Exportable Functions
 **********************************************************************************************/
Std_ReturnType DisplayCdd_Cfg_PreInitCheck(void); // WIll handle PowerComplete status and NVM status
Std_ReturnType DisplayCddCfg_SetState(EDisplayType DeviceId, EDisplayPowerState NewPowerState);
extern Std_ReturnType IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
extern Std_ReturnType IoHwAb_Pwm_SetDuty(IoHwAb_PwmSignalIdType PwmId, uint16 Pwm_Duty, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType DisplayCddCfg_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime);
Std_ReturnType DisplayCddCfg_BistTest_Stop(EDisplayType DeviceId);
void DisplayCdd_Cfg_Init(void);
void DisplayCdd_Cfg_DeInit(void);
void DisplayCdd_TIMainFunction(uint8 DeviceIndex);
#define DISPLAYINVALID_ID (uint8)0xFF

// Specify the index of configured device to start the bootstrap
#define cDisplayBootStrapID 0U

#define cDISPLAY_I2C_RETRYCOUNT 1u

/********************************************************************************************
 *  Total number of backlight chip config
 **********************************************************************************************/
/*! MACRO to store different states of state machine to notify to if module*/
#define eDisplayNotify_Idle 0u
// Define- If notification Required #define CDISPLAYCDD_ENABLE_NOTIFICATION
#ifdef CDISPLAYCDD_ENABLE_NOTIFICATION
#define eDisplayNotify_PowerON_Started 1u
#define eDisplayNotify_PowerON_Completed 2u
#define eDisplayNotify_FaultMonitoring_Started 3u
#define eDisplayNotify_FaultIdentified 4u
#define eDisplayNotify_PowerOFF_Started 5u
#define eDisplayNotify_PowerOFF_Completed 6u
#define eDisplayNotify_MaxState 7u

#endif
/*stubs for RTE*/
#define eDisplayBusy (2U)
#define Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData
#define Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData
#define EcuAppM_Ucl_Displayshutdown Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData
#define EcuAppM_Ucl_DisplayMgrPowerUp Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData
#define EcuAppM_Ucl_DisplayStatus Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData
#define DisplayPowerL_On EDisplayPower_On
#define DisplayStateL_On EDisplayState_On
#define e_DisplaySharp 0u
#define e_DisplayTruly 1U
#define BL_FAULT_MONITORING
#define BCK_FAULT_MONITORING_INTERVAL 10u
#define DEBOUNCE_INTERVAL 5u

#define CDISPLAYCDD_DISPLAY_CHECK_CONFIG_DB \
	{0x1E, 0x16, 0, 0, e_DisplaySharp, 1},  \
		{0x00, 0x04, 0, 0, e_DisplayTruly, 2}

#define CDISPLAYCDD_MODULE_ID (0xF7U)
#define CDISPLAYCDD_INSTANCE_ID (0x01U)
#define CDISPLAYCDD_READ_BL_FAULT_ID (0x03U)
#define CDISPLAYCDD_E_READ_BL_FAULT_FAILED (0x01U)
#define CDISPLAYCDD_BL_FAIL_ID (0x03U)
#define CDISPLAYCDD_BL_RECOVERY_ID (0x03U)

typedef struct
{
	uint8 address;
	uint8 data;
	uint8 sequence;
	uint8 channel;
	uint8 displayType; /* Nothing But index of device is configured */
	uint8 NvmValue;	   /* What is the corresponding we need to stored in to NVM for the respective device ID */
} DisplayCheckConfigType;

/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplayIdleState = 0,
	eDisplayEnableState,
	eDisplayPowerWaitState,
	eBackLightEnableState,
	eBackLightEnableWaitState,
	eDisplayWaitState,
	eBackLightDisableState,
	eBackLightDisableWaitState,
	eDisplayDisableState,
} EDisplaypowerStatesHelper;

typedef struct
{
	EDisplaypowerStatesHelper DisplayDrvStateMachine;
	uint8 RequesterPowerState; /*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */
	uint8 DisplayDrvCdd_Waittime;
	boolean FaultStatus;
} sDisplayCommonInfo;

/************************! Map the RTE calls **************************************/
#define cDISPLAYCDD_RTE_CALL_IOHWAB_SET_OUTPUT_PIN(x, y, z) \
	IoHwAb_DOut_SetOutputPin(x, y, z)

#define cDISPLAYCDD_RTE_CALL_IOHWABEXT_SET_OUTPUT_PIN(x, y, z) \
	IoHwAb_DOut_SetOutputPin(x, y, z)

#define DisplayCdd_RTE_ReadDisplayTypeFromNvM(x) \
	Rte_Call_rp_CS_MemAbsGet_Get_Display_Type(x)

#define Rte_Call_rpIoHwAb_Din_GetProcessedInput IoHwAb_GetProcessedInput

/*#define I2c_SetupEB(x , y , z , a) \
SetupEB(x , y , z , a);*/

/*************************************************************************************
 ************************   Init Function List  **************************************
 {Init1},{init2},{init3},{init4}
***************************************************************************************/
#define DISPLAYCDD_INIT \
	{DisplayCdd_Cfg_Init}

/*************************************************************************************
 ************************   Main Function List  **********************************
 {main1},{main2},{main3},{main4}
***************************************************************************************/
#define DISPLAYCDD_MAIN \
	{DisplayCdd_TIMainFunction}

/*************************************************************************************
 ************************   DeInit Function List    **********************************
 {DeInit1},{DeInit2},{DeInit3},{DeInit4}
***************************************************************************************/
#define DISPLAYCDD_DEINIT \
	{DisplayCdd_Cfg_DeInit}

/* Display pre Init condition check strcture
 *1st Data - Should not be equal to NULL else device will be in activation state. If not applicable create a function to send E_OK
 *2nd Data - If Device ID need to get from NVM then pass RTE, else NULL
 *3rd Data - For AutoDetect Method
 *4th Data - Write ID into NVM
 */

/*To hold the Pre Init Check Inputs*/
static const sDisplayPreInitConfigInfo DisplayInitCheck =
	{
		DisplayCdd_Cfg_PreInitCheck,
		NULL,
		eDisplayMaxIdentify,
		NULL,
};
/*This should be removed after RTE iteration*/
typedef enum
{
    BACKLIGHTDRVCDD_STATE_POWER_IDLE = 0u,
    BACKLIGHTDRVCDD_POWER_STATE_POWER_ON,
	BACKLIGHTDRVCDD_POWER_STATE_POWER_OFF
}BacklightDrvCdd_PwrStType;
EDisplaypowerStatesHelper DisplayCdd_Cfg_GetDisplayDrvStateMachine(void);
extern FUNC(Std_ReturnType, CBacklightCdd_CODE) CBacklightCdd_RequestPower(VAR(uint8, AUTOMATIC)deviceId, 
	                                                                  VAR(BacklightDrvCdd_PwrStType, AUTOMATIC)state);
/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Date              : 20/May/2025
By                : abasavar
Traceability      : PE4TI29141-8109
Change Description: Updated Version
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 20/May/2025
By                : abasavar
Traceability      : PE4TI29141-9009
Change Description: BL-Monitoring SM
-------------------------------------------------------------------------------*/
#endif /* DISPLAYCDD_CFG_H */

/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
