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

#include "Std_Types.h"
#include "Rte_Type.h"
#include "Rte_IoHwAb_Type.h"
#include "DisplayCdd_Types.h"
#include "DisplayIfCdd.h"
#include "Rte_CDisplayCdd.h"
#include "IoHwAb_DOut.h"
#include "I2c.h"
//#include "DeserializerCdd.h"
#include "IoHwAb_DIn_Cfg.h"


#define DEBUG_PRINT                    STD_OFF
#define CDISPLAYCDD_ENABLEBISTTEST

#if !defined( NULL_PTR )
    #define DISP_NULL    ((void *) 0)
#else 
	#define DISP_NULL	 NULL_PTR
#endif

/*!  Macro to map the  Initial power state*/
#define cDISPLAYCDD_INIT_POWER_STATE			        eDisplayIdle

// #define DISPLAY2_STARTUP_BYPOLLING
#define PowerCddL_PowerUp_Status 							ePowerCdd_PowerUp
#define PowerCddL_Idle                                      ePowerCdd_Idle
typedef EPowerState PowerState_L;

/*!  Macro to  the Display cdd about total number of Display config  in program (1 to 254)*/
#define cDISPLAYCDD_MAX_DEVICE					          (uint8)1u

#define cDISPLAYCDD_DEVICE_0							  (uint8)0u


#define DISPLAYCDD_INIT_WAITIME        (0u)

/*!  Macro to define the SPI TX buffer size*/
#define DISPLAYCDD_TX_BUF_SIZE                         (uint8)4u
/*!  Macro to define the SPI TX size*/
#define DISPLAYCDD_TRANSFER_SIZE                       (uint8)2u

#define CDISPLAYCDD_USE_IOHWAB_API_REQUIRED

/*!Specify the No of device that we are going to use for autodetect*/
#define CHECK_DISPLAY_COUNT								  (uint8)1u


#define DISPLAYINVALID_ID 						(uint8)0xFF

#define cDisplayBootStrapID						0U

#define cDISPLAY_I2C_RETRYCOUNT					1u
/*time delay needed for disp powerup seq ---config the delay as per the below just use for ref how they r doing it*/
#define RESET_DELAY_TIME          12u
#define SPI_PAGESELCT_WRITE       15u
#define SPI_DATA_WRITE 		      15u
#define STBYB_TIME                100u
#define STBYB_OFF_TIME            35u
#define RESET_DISABLE_TIME        50u
#define DISABLE_3V3_TIME          50u
#define DISPLAY_FAULT_RECOVERY_CHECK	1000 /*1sec*/


/*!  Macro to define the  POWERON_DELAY1
     Runnable - 10ms . Time is 1 * 10 = 10ms*//*20ms delay*/
#define cDISPLAYCDD_POWERON_DELAY0			(uint8)2

/*!  Macro to define the  POWERON_DELAY1
     Runnable - 10ms . Time is 1 * 10 = 10ms*//*40ms delay*/
#define cDISPLAYCDD_POWERON_DELAY1			 (uint8)4
/*!  Macro to define the POWERON_DELAY2
     Runnable - 10ms . Time is 1 * 10 = 10ms*//*50ms delay*/
#define cDISPLAYCDD_POWERON_DELAY2			 (uint8)5
/*!  Macro to define the POWERON_DELAY3 
     Runnable - 10ms . Time is 1 * 10 = 10ms*//*100ms delay*/
#define cDISPLAYCDD_POWERON_DELAY3			 (uint8)10
/*!  Macro to define the POWERON_DELAY4 
     Runnable - 10ms . Time is 1 * 10 = 10ms*//*1sec dealy*/
#define cDISPLAYCDD_POWERON_DELAY4			 (uint8)1000


/*!  Macro to define the  POWEROFF_DELAY1 
     Runnable - 10ms . Time is 1 * 10 = 10 ms*/
#define cDISPLAYCDD_POWEROFF_DELAY1			 (uint8)1


#define eDisplayI2Cdetect   0U
#define eDisplayBootStrap   1U
#define eDisplayMaxIdentify 1U
#define eDisplayNotify_Idle 						0u

#ifndef e_DisplayTianma
#define e_DisplayTianma 0u
#endif

#define CDISPLAYCDD_DISPLAY_CHECK_CONFIG_DB \
    {0x1E, 0x16, 0        , 0        , e_DisplayTianma , 1  }\



typedef struct
{
    uint8 address;
    uint8 data;
    uint8 sequence;
    uint8 channel;
    uint8 displayType; /* Nothing But index of device is configured */
    uint8 NvmValue;	   /* What is the corresponding we need to stored in to NVM for the respective device ID */
}DisplayCheckConfigType;



//Default Value is 2 for Gamma not Supported Programs. Producing misra and coverity warnings if it is less than default val.
#define GMA_WRITE_BUFF_SIZE 2

#define DISPLAYCDD_INIT_VALUE      0u
#define DISPLAYCDD_POWERON_DELAY1   1u
#define DISPLAYCDD_POWERON_DELAY2   1u
#define DISPLAYCDD_POWERON_FAULT_CONFIRMATION_TIME     1u    /*Fault confirmation time dueing PowerOn*/
#define DISPLAYCDD_IOHWAB_GET_INPUT_PIN          IoHwAbExt_GetProcessedInput

/**************************** NEED TO CHECK BELOW MACROS AND OTHERS ********************************/

#define DisplayMgrCdd_RTE_BacklightCddNotify(x , y)					Rte_Call_tiCS_TIBacklightCddlNotifyDisplayPower_cBacklightCddlNotifyDisplayPower(x , y)

#define DisplayMgrCdd_RTE_AppctrlNotify(x , y)					    Rte_Call_tiCS_TIAppCtrlNotifyDisplayPower_CAppCtrl_NotifyDisplayPower(x , y)

#define cDISPLAYCDD_RTE_CALL_IOHWAB_SET_OUTPUT_PIN     OsTrustedCall_IoHwAbExt_SetOutputPin

#define cDISPLAYCDD_RTE_CALL_IOHWAB_GET_INPUT_PIN      IoHwAbExt_GetSyncRawInput

#  ifndef eIO_Dout_MDO_TFT_BL_PWR
#   define eIO_Dout_MDO_TFT_BL_PWR IOHWAB_NUM_DOUT_OUTPUT
#  endif

#  ifndef e_Display1025Inch
#   define e_Display1025Inch (0U)
#  endif

#  ifndef eDisplayFault
#   define eDisplayFault (4U)
#  endif

#  ifndef eDisplayIdle
#   define eDisplayIdle (0U)
#  endif

#define SpiConf_SpiSequence_SpiSequence_TFT_DISP  0U
#define SpiConf_SpiChannel_SpiChannel_TFT_DISP    0U

#define I2cHardwareUnit_TFT_DISP_CID            (2u)
#define RI_Call_IoHwAbExt_GetDisplayMode(Data)              DeserializerCdd_GetDisplayMode(Data)
#define DISPLAY_I2C_SLAVE_ADDR                              (0xDEu)/* 7-bit address is 0x6E*/
#define DISP_HW_UNIT_INDEX                                  I2cHardwareUnit_TFT_DISP_CID
/**************************** NEED TO CHECK ABOVE MACROS AND OTHERS ********************************/


/*********************************************************************************************
*     Declare Program Specific Exportable Functions
**********************************************************************************************/
void DisplayCdd_Cfg_Init(void);
void DisplayCdd_Cfg_DeInit(void);
Std_ReturnType DisplayCdd_Cfg_PreInitCheck(void); //WIll handle PowerComplete status and NVM status
Std_ReturnType DisplayCddCfg_SetState(EDisplayType DeviceId,EDisplayPowerState NewPowerState);
Std_ReturnType DisplayCddCfg_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime);
Std_ReturnType DisplayCddCfg_BistTest_Stop(EDisplayType DeviceId);

//Cfg.c functions for DB
void DisplayDrvCdd_DriverInit(uint8 DeviceIndex);
void DisplayDrvCdd_DriverDeInit(uint8 DeviceIndex);
void DisplayCdd_DriverMainFunction(uint8 DeviceIndex);



/*!enum EDisplaypowerStatesHelper defines the different phases of activation */
typedef enum
{
	eDisplayIdleState = 0u,
	eDisplayPowerONStatePinupdate= 1u,
	eDisplayPowerON_3v3_EnableState =2u,
	eDisplayResetPinONState = 3u,
	eDisplaySPI_CONFIGURE_SPIState = 4u,
	eDisplaySPI_StartSPIState = 5u,
	eDisplaySPI_SendCommand1State = 6u,
	eDisplaySPI_ReadCommand1_ConfirmState = 7u,
	eDisplaySPI_SendCommand2State = 8u,
	eDisplaySPI_ReadCommand2_ConfirmState = 9u,
	eDisplaySPI_WAIT_FINISHState = 10u,
	eDisplayPowerON_STBYState = 11u,
	eDisplayPowerON_ErrorState = 12u,
	eDisplayPowerON_DoneState = 13u,
	eDisplayPowerOFFState = 14u, //need to modify this
	eDisplayPowerOFF_SPIOffState = 15u,
	eDisplayPowerOFF_STBYBOffState = 16u,
	eDisplayResetPinOFFState = 17u,
	eDisplayPowerOFF_3v3_DisableState = 18u,
	eDisplayPowerOFF_DoneState = 19u,
	eDisplayFaultState = 20u
}EDisplaypowerStatesHelper;

/*!enum for BIST Pattern control states */
typedef enum
{
    eDISPLAYCDD_TSTPTN_SUSPENDED        = 0u,
    eDISPLAYCDD_TSTPTN_WATING_STOP_REQUEST   = 1u,
    eDISPLAYCDD_TSTPTN_CONTROL_PATERN   = 2u,
    eDISPLAYCDD_TSTPTN_BUSY             = 3u
}EDisplayBistContrlState;

typedef struct 
{
    uint8                      DeviceID;                        /* Uinque ID of a device*/
	uint8					   DisplayDrvCdd_Waittime;          /* Hold the wait time */
	uint16 					   DeviceSupplyPin;
    uint16 					   DeviceResetPin;
	uint16 					   DeviceStandbyPin;
	uint8			   		   RequesterPowerState;				/*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */
	uint16    				   FaultStatusPin;
	uint16                     FaultConfirmTime;
	boolean				       FaultStatus;		        	    /* Hold the repective device status as ready , NotReady , Busy*/
	EDisplaypowerStatesHelper	   DisplayDrvStateMachine;			/* Hold the drvstatemachine current state */
	


}SDisplayDrvInfo;


/*
Description: To hold the details related to Display config
*/

typedef struct
{
	EDisplayType			   DisplayDeviceId;                          /* Represent the device ID     				 */
	uint16 					   DisplaySupplyPin;                         /* Represent the device supply pin		         */
    uint16 					   DisplayResetPin;                          /* Represent the device reset pin		         */
	uint16 					   DisplayStandbyPin;                        /* Represent the device standby pin		     */
	uint16    				   DisplayFaultStatusPin;                    /*Represent the device fault status pin		 */
}SDisplayDB;


//tamil
/************************! Map the RTE calls **************************************/

/*************************************************************************************
 ************************	Init Function List	**************************************
 {Init1},{init2},{init3},{init4}
***************************************************************************************/
#define DISPLAYCDD_INIT\
					   DisplayDrvCdd_DriverInit\

/*************************************************************************************
 ************************	Main Function List	**********************************
 {main1},{main2},{main3},{main4}
***************************************************************************************/
#define DISPLAYCDD_MAIN\
                        DisplayCdd_DriverMainFunction\

/*************************************************************************************
 ************************	DeInit Function List	**********************************
 {DeInit1},{DeInit2},{DeInit3},{DeInit4}
***************************************************************************************/
#define DISPLAYCDD_DEINIT\
						DisplayDrvCdd_DriverDeInit\

/*************************************************************************************
 ************************I2C Write**********************************
***************************************************************************************/
#define DISPLAYDRVCDD_I2C_WRITE\
                        DisplayDrvCdd_I2C_Write\

/*************************************************************************************
 ************************I2C Read**********************************
***************************************************************************************/
#define DISPLAYDRVCDD_I2C_READ\
                        DisplayDrvCdd_I2C_Read\

#define DISPLAY_TIANMA_CONFIG_DB\
                          {\
                           e_Display1025Inch,\
						   eIO_DI_DISP_PON,\
						   eIO_DO_DISP_RESET,\
						   eIO_DI_DISP_PON,\
                           eIO_DI_DISP_FDET,\
                          }\



#define DISPLAY_FAULT_MONITORING	STD_OFF

/* Display pre Init condition check strcture
 *1st Data - Should not be equal to NULL else device will be in activation state. If not applicable create a function to send E_OK
 *2nd Data - If Device ID need to get from NVM then pass RTE, else NULL
 *3rd Data - For AutoDetect Method
 *4th Data - Write ID into NVM
*/

/*To hold the Pre Init Check Inputs*/
static const sDisplayPreInitConfigInfo DisplayInitCheck =\
					{\
						DisplayCdd_Cfg_PreInitCheck,\
						NULL,\
						eDisplayMaxIdentify,\
						NULL,\
					};

/**************************** Display & Touch FW Version Read macros ********************************/
#define FW_VERSION_INIT_VAL					0xFFu
#define TDDI_READ_STEP_1					(1u)
#define TDDI_READ_STEP_2					(2u)
#define TDDI_READ_STEP_3					(3u)
#define FW_VERSION_READ_REG_0				0x1Eu
#define FW_VERSION_READ_CMD_PAGE_DISPLAY	0x10u
#define FW_VERSION_READ_ADDRESS_DISPLAY		0x17u
#define PAGE_SELECT_SIZE					(2u)
#define ADDRESS_SIZE						(1u)
#define I2C_TX_FW_VERSION_USED_BUFFER_SIZE	(3u)
#define I2C_RX_FW_VERSION_MAX_BUFFER_SIZE	(1u)
#define FWVersion_NOT_OK                 	0x01u
#define FWVersion_PENDING                   0x02u
#define FWVersion_OK                        0x00u


Std_ReturnType DisplayCddCfg_GetStateMachineStatus(EDisplayType DeviceId, EDisplaypowerStatesHelper *DisplayDrvStateMachine);
extern Std_ReturnType CDisplayCdd_EnterSafeState(void);
extern Std_ReturnType CDisplayCdd_RestoreNormState(void);
extern Std_ReturnType DisplayDrvCdd_I2C_Write(uint8* TxBuffer, uint8 TxLength);
//extern Std_ReturnType DisplayDrvCdd_I2C_WriteRead(uint8* TxBuffer, uint8 TxLength, uint8* RxBuffer, uint8 RxLength);
//extern void cDeserialiserCdd_Notify_SMFail(SmFailureTypeId FailureID, boolean FailureStatus);
void CDisplayCdd_Restart_DisplayI2C(void);
Std_ReturnType cDisplayCdd_FailT_RegRead (void);
void cDisplayCdd_SetDispAndTouchErrors(void);
extern Std_ReturnType StartRead_Disp_FWVersion(uint8* val);
extern Std_ReturnType StartRead_Touch_FWVersion(uint8* val);
/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/

/* 
#-------------------------------------------------------------------------------------------------------------------
#    Date     |   User   |   Task    |                                     Description
#-------------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------------
# 10/07/2023 | PRAJAMAN  | JLR3C29298-26736  | Coverity Fix - DisplayCdd_Cfg.c
#-------------------------------------------------------------------------------------------------------------------
# 01/09/2023 | BSHANMU4  | JLR3C29298-127414  | EcumExt Mainfunction - ModeCtrl Init Removed
#-------------------------------------------------------------------------------------------------------------------
# 10/08/2023 | TSUBRAMA  | JLR3C29298-114050  | Serializer[981] &Deserializer[988] addition for DSI - DisplayCdd_Cfg.c
#-------------------------------------------------------------------------------------------------------------------
# 20/10/2023 | BSHANMU4  |JLR3C29298-145142 | FCD Display Command & Ctrl Implementation
#-------------------------------------------------------------------------------------------------------------------
# 06/11/2023 |  BSHANMU4 | JLR3C29298-127474| FCD & FDD Cmd & Ctrl Implementation
#-------------------------------------------------------------------------------------------------------------------
# 15/08/2024 | RDARSHAN  |REN31759-19688| TIANMA Display Command & Ctrl Implementation
#-------------------------------------------------------------------------------------------------------------------
# 23/01/2025 | KMADHUSO  |REN31759-22103| TIANMA Display BIST Implementation
#-------------------------------------------------------------------------------------------------------------------
*/

#endif /* DISPLAYCDD_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
