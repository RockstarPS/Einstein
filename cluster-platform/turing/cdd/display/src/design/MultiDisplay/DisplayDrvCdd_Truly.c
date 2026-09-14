/*---------------------------------------------------------------------------------------------------------------------

VISTEON CORPORATION CONFIDENTIAL
_______________________________

[2019] Visteon Corporation
All Rights Reserved.

NOTICE: This is an unpublished work of authorship, which contains trade secrets.
Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
under all copyright laws to protect this work as a published work, when appropriate.
Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
/*!*****************************************************************************************************************
*    @file DisplayDrvCdd_Truly.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayDrvCdd_Truly APIs. This header file should be included by other  
*    modules that use these APIs this file interacts with driver layer
********************************************************************************************************************/
#define DISPLAYDRVCDD_TRULY_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Types.h"
#include "DisplayCdd_Cfg.h"

#include "DisplayIfCdd.h"

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
#include "DisplayDrvCdd_Truly.h"
#endif

#include "DisplayDrvCdd_Cbk.h"
#include "DisplayI2CDrvCdd.h"

/*=====================================================================================================================
  CONSTANTS & TYPES
=====================================================================================================================*/
/*! @brief Defines the maximum data length of SPI */
#define DISPLAYCDD_INIT_WAITIME        (0u)

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION

/*! @brief indicates the Idle state of gamma settings */
#define		GMA_SET_STATE_IDLE	 	    			(uint8)0U

/*! @brief indicates the NvM Read of gamma settings has been completed and waiting for display getting powered On */
#define		GMA_SET_STATE_DISPLAY_POWERON_WAIT	 	(uint8)1U

/*! @brief indicates the sequence execution of gamma settings */
#define		GMA_SET_STATE_SEQ_EXECUTION				(uint8)2U

/*! @brief indicates the gamma settings sequence execution completion state */
#define		GMA_SET_STATE_COMPLETED					(uint8)3U

/*! @brief indicates the display auto detection state */
#define		GMA_SET_STATE_DISPLAY_AUTO_DETECT		(uint8)4U



#define		GMA_SET_STEP_IDLE					(uint8)0U
#define		GMA_SET_STEP_OPEN_PAGE				(uint8)1U
#define		GMA_SET_STEP_PASSWARD				(uint8)2U
#define		GMA_SET_STEP_GMA_SET_ADDRESS		(uint8)3U
#define		GMA_SET_STEP_GMA_SET_PERMISSION		(uint8)4U
#define		GMA_SET_STEP_RED					(uint8)5U
#define		GMA_SET_STEP_RED_SETTING			(uint8)6U
#define		GMA_SET_STEP_GREEN					(uint8)7U
#define		GMA_SET_STEP_GREEN_SETTING			(uint8)8U
#define		GMA_SET_STEP_BLUE					(uint8)9U
#define		GMA_SET_STEP_BLUE_SETTING			(uint8)10U


//#define     GMA_REG_LEN_TRULY           (uint8)48U
//#define     GMA_REG_LEN_DIV_TRULY       (uint8)6U
//Divide is data, 1 is data address, 2 is reserved
//#define     GMA_WRITE_BUFF_SIZE         (uint8)((GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY)+1u+2u)
//#define     GMA_READ_BUFF_SIZE          (uint8)2u

#define     TRULY_GMA_REG_LEN_SHARP           (uint8)27U
#define     GMA_REG_LEN_DIV_SHARP       (uint8)6U

//Truly TFT Data
#define     GMA_SET_TRULY_SEL_D_A       (uint8)0x00U        //select data address
#define     GMA_SET_TRULY_SEL_PAGE_5    (uint8)0X54U        //select page-5
#define     GMA_SET_TRULY_SEL_PAGE_0    (uint8)0X04U        //select page-0

#define     GMA_SET_TRULY_OTP_D_A       (uint8)0x08U        //Displaying OTP Reload data address
#define     GMA_SET_TRULY_OTP_D         (uint8)0x58U        //Displaying OTP Reload data

#define     GMA_SET_TRULY_EN_D_A        (uint8)0x11U        //Enabling D-Gamma data address
#define     GMA_SET_TRULY_EN_D          (uint8)0x30U        //Enabling D-Gamma data

#define     GMA_SET_TRULY_EN_WP_A        (uint8)0x1CU        //Enabling Gamma Reg Write permission address
#define     GMA_SET_TRULY_EN_WP_D        (uint8)0x03U        //Enabling Gamma Reg Write permission

#define     GMA_SET_TRULY_PS_R          (uint8)0X24U        //page select red
#define     GMA_SET_TRULY_PS_G          (uint8)0X34U        //page select green
#define     GMA_SET_TRULY_PS_B          (uint8)0X44U        //page select blue


#endif



/*=====================================================================================================================
  GLOBALS & STATIC
=====================================================================================================================*/

/*
Description: To hold the details related to EEPROM load 
*/
typedef struct 
{
    uint8                      DeviceID;                        /* Uinque ID of a device*/
	uint16 					   DeviceSupplyPin;
    uint16 					   DeviceResetPin;
	uint16 					   DeviceStandbyPin;
	uint16 					   DeviceBacklightPin;
	uint16    				   FaultStatusPin;
	boolean				       FaultStatus;		        	    /* Hold the repective device status as ready , NotReady , Busy*/

}SDisplayDrvTrulyInfo;

/*! Hold the Display driver  related information  */
static SDisplayDrvTrulyInfo DisplayDrvTrulyInfoTable[cDISPLAYCDD_MAX_TRULY_DEVICE];
/*! Hold the driver power down state machine  related information  */
static EDisplayTrulyPowerUpStates DisplayDrvTruly_PowerUp_StateMachine[cDISPLAYCDD_MAX_TRULY_DEVICE];
/*! Hold the driver power up state machine  related information  */
static EDisplayTrulyPowerDownStates DisplayDrvTruly_PowerDown_StateMachine[cDISPLAYCDD_MAX_TRULY_DEVICE];

/*!Hold the waitime for the execution of power sequence */
static uint8 DisplayDrvCdd_Truly_Waittime;

static boolean DisplayDrvCdd_Truly_PowerUpComplete;

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION

/*! To indicate the current gamma correction Status */
static EGammaCorrectionStatus  GammaCorrectionCurrentStatus;

/*! To indicate the current gamma correction state */
static uint8 GammaCorrectionState;

/*! To indicate the gamma correction sequence state */
static uint8 GammaCorrectionSequenceState;

/*! To store the write index during applying red, green and blue settings in each iteration of gamma settings sequence */
static uint8 Gamma_RGB_WriteIndex;

//RGB - Default values for SHARP
uint8 TrulyGammaCorrectionData[(TRULY_GMA_REG_LEN_SHARP*3)] =
{   //0   1    2     3     4    5     6     7     8      9   A     B     C     D    E     F     10    11    12    13    14    15    16    17    18    19    1A
    0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0xFF, 0x00, 0x55, 0xAA, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   //0   1    2     3     4    5     6     7     8      9   A     B     C     D    E     F     10    11    12    13    14    15    16    17    18    19    1A
    0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0xFF, 0x00, 0x55, 0xAA, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   //0   1    2     3     4    5     6     7     8      9   A     B     C     D    E     F     10    11    12    13    14    15    16    17    18    19    1A
    0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0x0, 0x40, 0x80, 0xC0, 0xFF, 0x00, 0x55, 0xAA, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#endif
/*=====================================================================================================================
  LOCAL Functions
=====================================================================================================================*/
static void DisplayDrvCdd_TrulyFaultHandle(void);
static void DisplayDrvCdd_TrulyMonitorFaultStatus(uint8 deviceIndex);

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
static Std_ReturnType DisplayDrvCdd_TrulyLoadGammaSettingsFromNvM(void);
static void DisplayDrvCdd_TrulyGammaCorrectionSequenceExecution(void);
static void DisplayDrvCdd_TrulyGammaCorrectionSequence(void);
static void DisplayDrvCdd_TrulyStartCalibrationProcedure(void);
#endif

static void DisplayDrvCdd_TrulyPowerUpSequence(void);
static void DisplayDrvCdd_TrulyPowerDownSequence(void);

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  void
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_TrulyInit(uint8 DeviceindexId)
{
	
	Std_ReturnType status = E_NOT_OK;
	uint8 Device_No;
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_TRULY_DEVICE; Device_No++)
	{
			DisplayDrvTrulyInfoTable[Device_No].DeviceID         	= DisplaySharpInfoDB[DeviceindexId].DisplayDeviceId;
			DisplayDrvTrulyInfoTable[Device_No].DeviceSupplyPin     = DisplaySharpInfoDB[DeviceindexId].DisplaySupplyPin;
			DisplayDrvTrulyInfoTable[Device_No].DeviceResetPin      = DisplaySharpInfoDB[DeviceindexId].DisplayResetPin;	
			DisplayDrvTrulyInfoTable[Device_No].DeviceStandbyPin    = DisplaySharpInfoDB[DeviceindexId].DisplayStandbyPin;
			DisplayDrvTrulyInfoTable[Device_No].FaultStatusPin      = DisplaySharpInfoDB[DeviceindexId].DisplayFaultStatusPin;	
			DisplayDrvTrulyInfoTable[Device_No].FaultStatus         = (boolean)FALSE;
			
			#ifdef CDISPLAYCDD_ENABLE_AUTOMATIC_POWERON_INIT
				DisplayDrvTruly_PowerUp_StateMachine[Device_No]		= eDisplayTruly_PowerON_SupplyPinupdate;
			#else
				DisplayDrvTruly_PowerUp_StateMachine[Device_No]		= eDisplayTruly_PowerON_IdleState;
			#endif
			
			DisplayDrvTruly_PowerDown_StateMachine[Device_No]		= eDisplayTruly_PowerOFF_IdleState;
	}
	DisplayDrvCdd_Truly_Waittime = DISPLAYCDD_INIT_WAITIME;
	
	DisplayDrvCdd_Truly_PowerUpComplete = (boolean)FALSE;
	
	#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
		GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_None;
		GammaCorrectionState = GMA_SET_STATE_IDLE;
		GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
		Gamma_RGB_WriteIndex = 0u;
		
		DisplayDrvCdd_TrulyStartCalibrationProcedure();
	#endif
	
	status = E_OK;
	
	return status;
	
}
/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_TrulyDeInit(void)
{
	Std_ReturnType DeInitResult = E_OK;
	
	#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
		GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_None;
		GammaCorrectionState = GMA_SET_STATE_IDLE;
		GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
		Gamma_RGB_WriteIndex = 0u;
	#endif
		
	return DeInitResult;	
	
}

/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_TrulySetState(uint8 DeviceIndex , EDisplayPowerState NewPowerState)
{
	Std_ReturnType ret = E_NOT_OK;
	#ifdef CDISPLAYCDD_SUPPORT_MULTIDISPLAY
		DeviceIndex = 0u;	
	#endif
	
	
	if(eDisplayPowerON == NewPowerState)
	{
		/*Switch the power up state machine to power on state*/
		DisplayDrvTruly_PowerUp_StateMachine[DeviceIndex] = eDisplayTruly_PowerON_SupplyPinupdate;
		DisplayDrvCdd_TrulyPowerUpSequence();
	}
	else if (eDisplayPowerOFF == NewPowerState)
	{
		/*Switch the power down state machine to power off state*/
		DisplayDrvTruly_PowerDown_StateMachine[DeviceIndex] = eDisplayTruly_PowerOFFState;
		DisplayDrvCdd_TrulyPowerDownSequence();		
	}
	else
	{
		/*Do Nothing */
	}
			
	ret = E_OK;
	return ret;
}

/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_TrulyMainFunction(void)
{
	uint8 Device_No;
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_TRULY_DEVICE; Device_No++)
	{
			if(DisplayDrvTruly_PowerUp_StateMachine[Device_No] != eDisplayTruly_PowerON_IdleState)
			{
				(void)DisplayDrvCdd_TrulyPowerUpSequence();
			}
			else
			{
				/* do nothing */
			}

			if(DisplayDrvTruly_PowerDown_StateMachine[Device_No] != eDisplayTruly_PowerOFF_IdleState)
			{
				(void)DisplayDrvCdd_TrulyPowerDownSequence();
			}
			else
			{
				/* do nothing */
			}
	}
	
	#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
		DisplayDrvCdd_TrulyGammaCorrectionSequenceExecution();
	#endif
}

/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power up sequence
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_TrulyPowerUpSequence(void)
{
	uint8 Device_No;
	Std_ReturnType NotifyResult = E_NOT_OK;
	
	#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
		IoHwAb_ErrorType GetErrorStatus;
	#endif
    
	/*Initialise the variables */
	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_TRULY_DEVICE; Device_No++)
	{
			switch(DisplayDrvTruly_PowerUp_StateMachine[Device_No])
			{
				case eDisplayTruly_PowerON_IdleState:
				{
					/*Do nothing*/
				}
				break;
				case eDisplayTruly_PowerON_SupplyPinupdate:
				{		
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceSupplyPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceSupplyPin, STD_HIGH);
						#endif
						
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWERON_DELAY1;
						DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_PowerON_ResetStandbyPinupdate;
					}
				}	
				break;			
				case eDisplayTruly_PowerON_ResetStandbyPinupdate:
				{				
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceResetPin, STD_HIGH , &GetErrorStatus);
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceStandbyPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceResetPin, STD_HIGH);
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceStandbyPin, STD_HIGH);
						#endif	
					
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWERON_DELAY2;
						DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_PowerON_FailDetPinupdate;
					}

				}
				break;
				case eDisplayTruly_PowerON_FailDetPinupdate:
				{
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].FaultStatusPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].FaultStatusPin, STD_HIGH);
						#endif
					
						//DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWERON_DELAY3;
						//DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_PowerON_EnableBacklight;
						DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_NormalState;
					}						
							 
				}
				break;
				case eDisplayTruly_PowerON_EnableBacklight:
				{	
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceBacklightPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceBacklightPin, STD_HIGH);
						#endif
					
						DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_NormalState;
					}	 
				}
				break;
				case eDisplayTruly_NormalState:
				{
					/*Notify that power state*/
					NotifyResult = DispIfCdd_NotifyDisplayStatus(DisplayDrvTrulyInfoTable[Device_No].DeviceID  , eDisplayNormal);
					
					DisplayDrvCdd_Truly_PowerUpComplete = (boolean)TRUE;
					
					if(E_OK == NotifyResult)
					{
						DisplayDrvTruly_PowerUp_StateMachine[Device_No] = eDisplayTruly_PowerON_FailDetection;
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWERON_DELAY4;
					}
				}
				break;
				case eDisplayTruly_PowerON_FailDetection:
				{	
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						(void)DisplayDrvCdd_TrulyMonitorFaultStatus(Device_No);
					}						
							 
				}
				break;		
				case eDisplayTruly_FaultState:
				{
					DisplayDrvCdd_TrulyFaultHandle();
				}				
				break;
				default:
				break;
			}
	} 
}

/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power down sequence
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_TrulyPowerDownSequence(void)
{
	uint8 Device_No;
	Std_ReturnType NotifyResult = E_NOT_OK;
	
	IoHwAb_ErrorType GetErrorStatus;
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_TRULY_DEVICE; Device_No++)
	{
			switch(DisplayDrvTruly_PowerDown_StateMachine[Device_No])
			{
				case eDisplayTruly_PowerOFF_IdleState:
				{
					/* do nothing */
				}
				break;
				case eDisplayTruly_PowerOFFState:
				{
					DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWEROFF_DELAY2;
					DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFF_StandbyPinUpdate;
				}
				break;
				case eDisplayTruly_PowerOFF_DisableBacklight:
				{        
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{					

						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceBacklightPin, STD_LOW , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceBacklightPin, STD_LOW);
						#endif
					
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWEROFF_DELAY2;
						DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFF_StandbyPinUpdate;
					}						
				}
				break;
				case eDisplayTruly_PowerOFF_StandbyPinUpdate:
				{        
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{					

						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceStandbyPin, STD_LOW , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceStandbyPin, STD_LOW);
						#endif
					
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWEROFF_DELAY3;
						DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFF_FailDetection;
					}						
				}
				break;
				case eDisplayTruly_PowerOFF_FailDetection:
				{        
					if(DisplayDrvCdd_Truly_Waittime >=1)
					{
						DisplayDrvCdd_Truly_Waittime--;
						(void)DisplayDrvCdd_TrulyMonitorFaultStatus(Device_No);
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].FaultStatusPin, STD_LOW , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].FaultStatusPin, STD_LOW);
						#endif
						
						DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWEROFF_DELAY4;
						DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFF_SupplyResetPinsUpdate;
					}
				}				
				break;	
				case eDisplayTruly_PowerOFF_SupplyResetPinsUpdate:
				{
					if(DisplayDrvCdd_Truly_Waittime >=1u)
					{
						DisplayDrvCdd_Truly_Waittime--;
					}
					
					if(DisplayDrvCdd_Truly_Waittime <= 0u)
					{
						
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceSupplyPin, STD_LOW , &GetErrorStatus);
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvTrulyInfoTable[Device_No].DeviceResetPin, STD_LOW , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceSupplyPin, STD_LOW);
							Dio_WriteChannel(DisplayDrvTrulyInfoTable[Device_No].DeviceResetPin, STD_LOW);
						#endif
						
						DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFFState_Complete;
					}
				}	
				case eDisplayTruly_PowerOFFState_Complete:
				{					
						/*Notify that power state is complete*/
						NotifyResult = DispIfCdd_NotifyDisplayStatus(DisplayDrvTrulyInfoTable[Device_No].DeviceID  , eDisplayPowerOFF);
						
						DisplayDrvCdd_Truly_PowerUpComplete = (boolean)FALSE;
						
						if(E_OK == NotifyResult)
						{
							DisplayDrvCdd_Truly_Waittime = cDISPLAYCDD_TRULY_POWERON_DELAY5;
							DisplayDrvTruly_PowerDown_StateMachine[Device_No] = eDisplayTruly_PowerOFF_IdleState;
						}						
				}	
				break;
				default:
				break;
			}
	} 
}

/*!***************************************************************************************************************** 
*   @brief        This function is used to monitor the fault status pin
*   @param[in]    Device index
*   @return   	  void
********************************************************************************************************************/
static void DisplayDrvCdd_TrulyMonitorFaultStatus(uint8 deviceIndex)
{
	uint8 FaultStatus = STD_HIGH;
	
	FaultStatus = Dio_ReadChannel(DisplayDrvTrulyInfoTable[deviceIndex].FaultStatusPin);
	
	if(STD_HIGH == FaultStatus)
	{	
		DisplayDrvTrulyInfoTable[deviceIndex].FaultStatus = (boolean)FALSE;	
	}
	else
	{
		DisplayDrvTrulyInfoTable[deviceIndex].FaultStatus = (boolean)TRUE;
		/*Switch  the state machine to Fault handle*/
		DisplayDrvTruly_PowerUp_StateMachine[deviceIndex] = eDisplayTruly_FaultState;	
		/*Notify Fault state as occured.*/
		DispIfCdd_NotifyDisplayStatus(DisplayDrvTrulyInfoTable[deviceIndex].DeviceID  , eDisplayFault);			
	}
}

/*!***************************************************************************************************************** 
*   @brief      The function is resposible for fault handling
*   @param[in]  void
*   @return  void 
********************************************************************************************************************/
static void DisplayDrvCdd_TrulyFaultHandle(void)
{
	/* To be implementation in future*/
}



/*!*****************************************************************************************************************
 *   @brief      	To execute gamma correction in the pre-defined sequence
 ********************************************************************************************************************/
static void DisplayDrvCdd_TrulyGammaCorrectionSequenceExecution(void)
{
	switch(GammaCorrectionState)
	{
		case GMA_SET_STATE_IDLE:
			break;
			
		case GMA_SET_STATE_DISPLAY_POWERON_WAIT:
			if((boolean)FALSE != DisplayDrvCdd_Truly_PowerUpComplete)
			{
				GammaCorrectionState = GMA_SET_STATE_SEQ_EXECUTION;
				GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_OnGoing;
			}
			break;
			
		case GMA_SET_STATE_SEQ_EXECUTION:
			DisplayDrvCdd_TrulyGammaCorrectionSequence();
			break;
			
		case GMA_SET_STATE_DISPLAY_AUTO_DETECT:
			/* not supported now */
			break;
			
		case GMA_SET_STATE_COMPLETED:
			break;
			
		default:
			break;
	}
}

/*!*****************************************************************************************************************
 *   @brief      	To execute gamma correction  sequence for Truly display
 ********************************************************************************************************************/
static void DisplayDrvCdd_TrulyGammaCorrectionSequence(void)
{
	uint8 I2c_RegAdd, I2c_TxData;
	Std_ReturnType Ret = E_OK;
	
	switch (GammaCorrectionSequenceState)
	{
		case GMA_SET_STEP_IDLE:
			/* Either initialization completed or not yet started */
			break;
			
		case GMA_SET_STEP_OPEN_PAGE:
			I2c_RegAdd = GMA_SET_TRULY_SEL_D_A;
			I2c_TxData = GMA_SET_TRULY_SEL_PAGE_5;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01 , TRULY_I2C_CHANNEL , TRULY_I2C_SEQ  ,CDISPLAYCDD_TRULY );	 /* open page passward */
			GammaCorrectionSequenceState++;
			break;
			
		case GMA_SET_STEP_PASSWARD:
			I2c_RegAdd = GMA_SET_TRULY_OTP_D_A;
			I2c_TxData = GMA_SET_TRULY_OTP_D;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			break;			
			
		case GMA_SET_STEP_GMA_SET_ADDRESS:
			I2c_RegAdd = GMA_SET_TRULY_SEL_D_A;
			I2c_TxData = GMA_SET_TRULY_SEL_PAGE_0;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			break;
			
		case GMA_SET_STEP_GMA_SET_PERMISSION:
			I2c_RegAdd = GMA_SET_TRULY_EN_WP_A;
			I2c_TxData = GMA_SET_TRULY_EN_WP_D;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			break;
			
		case GMA_SET_STEP_RED:
			/* Page-2 Red color gamma register table */
			I2c_RegAdd = GMA_SET_TRULY_SEL_D_A;
			I2c_TxData = GMA_SET_TRULY_PS_R;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_RED_SETTING:

			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_TRULY)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex + 1u;
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &TrulyGammaCorrectionData[Gamma_RGB_WriteIndex], (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY), TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
				Gamma_RGB_WriteIndex += (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY);
			}
			else
			{
				GammaCorrectionSequenceState++;
			}
			break;
			
		case GMA_SET_STEP_GREEN:
			/* Page-3 Green color gamma register table */
			I2c_RegAdd = GMA_SET_TRULY_SEL_D_A;
			I2c_TxData = GMA_SET_TRULY_PS_G;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_GREEN_SETTING:
			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_TRULY)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex + 1u;
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &TrulyGammaCorrectionData[GMA_REG_LEN_TRULY + Gamma_RGB_WriteIndex], (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY), TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
				Gamma_RGB_WriteIndex += (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY);
			}
			else
			{
				GammaCorrectionSequenceState++;
			}
			break;
			
		case GMA_SET_STEP_BLUE:
			/* Page-4 Green color gamma register table */
			I2c_RegAdd = GMA_SET_TRULY_SEL_D_A;
			I2c_TxData = GMA_SET_TRULY_PS_B;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_BLUE_SETTING:
			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_TRULY)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex + 1u;
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &TrulyGammaCorrectionData[(GMA_REG_LEN_TRULY * 2u) + Gamma_RGB_WriteIndex], (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY), TRULY_I2C_CHANNEL , TRULY_I2C_SEQ ,CDISPLAYCDD_TRULY);
				Gamma_RGB_WriteIndex += (GMA_REG_LEN_TRULY/GMA_REG_LEN_DIV_TRULY);
			}
			else
			{
				GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
				GammaCorrectionState = GMA_SET_STATE_COMPLETED;
				GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_Success;
			}
			break;
			
		default:
			GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
			break;
	}
	
	if(E_OK != Ret)
	{
		GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
		GammaCorrectionState = GMA_SET_STATE_COMPLETED;
		GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_Failure;
	}
}

/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @param[in]  datalength - Lenght of the data available in buffer pointer
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_TrulySetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength)
{
	Std_ReturnType RetVal;
	uint32 index;
	if(GammaCorrectionCurrentStatus != eDisplayCdd_GammaCorrection_OnGoing)
	{
		for (index = 0u; index < (uint32)datalength; index++)
		{
			TrulyGammaCorrectionData[index] = (uint8)(*(GmaSetPtr+index));
		}
		
		if((boolean)FALSE != DisplayDrvCdd_Truly_PowerUpComplete)
		{
			GammaCorrectionState = GMA_SET_STATE_SEQ_EXECUTION;
			GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_OnGoing;
		}
		else
		{
			GammaCorrectionState = GMA_SET_STATE_DISPLAY_POWERON_WAIT;
		}
		
		GammaCorrectionSequenceState = GMA_SET_STEP_OPEN_PAGE;
		RetVal = E_OK;
	}
	else
	{
		RetVal = E_NOT_OK;
	}
	return RetVal;
}

/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayDrvCdd_TrulyGetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
{
	if ((GMA_SET_STEP_IDLE == GammaCorrectionSequenceState) && (GMA_SET_STATE_COMPLETED == GammaCorrectionState))
	{
		*GmaCrStatus = GammaCorrectionCurrentStatus;
	}
}

/*!***************************************************************************************************************** 
*   @brief      To read the TFT type and gamma settings from NvM and to trigger writing of gamma settings in TFT display
********************************************************************************************************************/
static void DisplayDrvCdd_TrulyStartCalibrationProcedure(void)
{
	Std_ReturnType RetVal;
	
	RetVal= DisplayDrvCdd_TrulyLoadGammaSettingsFromNvM();	
	if(E_OK!= RetVal)
	{
		/* If NVM read fail, gamma correction sequence will not be executed */
        if(GMA_SET_STATE_DISPLAY_AUTO_DETECT != GammaCorrectionState)
        {
            GammaCorrectionState = GMA_SET_STATE_IDLE;
        }
	}
	else
	{
		if((boolean)FALSE != DisplayDrvCdd_Truly_PowerUpComplete)
		{
			GammaCorrectionState = GMA_SET_STATE_SEQ_EXECUTION;
			GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_OnGoing;
		}
		else
		{
			GammaCorrectionState = GMA_SET_STATE_DISPLAY_POWERON_WAIT;
		}
		 
		if(GMA_SET_STEP_IDLE == GammaCorrectionSequenceState)
        {
            GammaCorrectionSequenceState = GMA_SET_STEP_OPEN_PAGE;
        }
	}
}

/*!***************************************************************************************************************** 
*   @brief      To load the initial gamma settings from NvM
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
static Std_ReturnType DisplayDrvCdd_TrulyLoadGammaSettingsFromNvM(void)
{
	Std_ReturnType RetValue, RetVal = E_NOT_OK;
	
	/* Read Truly gamma data from NVM */
	RetVal = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Red_Gamma_Adjustment_Display1_Handle, &TrulyGammaCorrectionData, GMA_REG_LEN_TRULY);
	RetValue = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Green_Gamma_Adjustment_Display1_Handle, (TrulyGammaCorrectionData+GMA_REG_LEN_TRULY), GMA_REG_LEN_TRULY);
	RetVal = (RetVal | RetValue);
	RetValue = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Blue_Gamma_Adjustment_Display1_Handle, (TrulyGammaCorrectionData+(GMA_REG_LEN_TRULY * 2)), GMA_REG_LEN_TRULY);
	RetVal = (RetVal | RetValue);
	
	return RetVal;
}


/*!***************************************************************************************************************** 
*   @brief      Error Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_TrulyI2cSeqErrorCallback(void)
{
	GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
	GammaCorrectionState = GMA_SET_STATE_COMPLETED;
	GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_Failure;
}




/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 6/Apr/2020
By                : sgarg1
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Added Power and SPI sequence for 12 inch tianma display. 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Updated PR comments 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 8/July/2020
By                : nrajaman
Traceability      : RTC # 956295
Change Description: Fixed Coverity and Misra Warnings 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/
