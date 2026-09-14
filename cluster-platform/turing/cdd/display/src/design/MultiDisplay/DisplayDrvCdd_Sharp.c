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
*    @file DisplayDrvCdd_Sharp.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayDrvCdd_Sharp APIs. This header file should be included by other  
*    modules that use these APIs this file interacts with driver layer
********************************************************************************************************************/
#define DISPLAYDRVCDD_SHARP_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Cfg.h"

#include "DisplayIfCdd.h"

#ifdef DISPLAYDRVCDD_SHARP_C
#include "DisplayDrvCdd_Sharp.h"
#endif

#include "DisplayDrvCdd_Cbk.h"
#include "DisplayCdd_Types.h"

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


#define     GMA_REG_LEN_SHARP           (uint8)27U
#define     GMA_REG_LEN_DIV_SHARP       (uint8)6U

// SHARP TFT data
#define     GMA_SET_SHARP_SEL_D_A       (uint8)0x1EU        //select data address
#define     GMA_SET_SHARP_SEL_PAGE      (uint8)0X20U        //select page

#define     GMA_SET_SHARP_OTP_D_A       (uint8)0x1DU        //Displaying OTP Reload data address
#define     GMA_SET_SHARP_OTP_D         (uint8)0xF0U        //Displaying OTP Reload data

#define     GMA_SET_SHARP_EN_D_A        (uint8)0x11U        //Enabling D-Gamma data address
#define     GMA_SET_SHARP_EN_D          (uint8)0x30U        //Enabling D-Gamma data

#define     GMA_SET_SHARP_PS_R          (uint8)0X13U        //page select red
#define     GMA_SET_SHARP_PS_G          (uint8)0X14U        //page select green
#define     GMA_SET_SHARP_PS_B          (uint8)0X15U        //page select blue

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
	uint16    				   FaultStatusPin;
	boolean				       FaultStatus;		        	    /* Hold the repective device status as ready , NotReady , Busy*/

}SDisplayDrvSharpInfo;

/*! Hold the Display driver  related information  */
static SDisplayDrvSharpInfo DisplayDrvSharpInfoTable[cDISPLAYCDD_MAX_SHARP_DEVICE];
/*! Hold the driver power down state machine  related information  */
static EDisplaySharpPowerUpStates DisplayDrvSharp_PowerUp_StateMachine[cDISPLAYCDD_MAX_SHARP_DEVICE];
/*! Hold the driver power up state machine  related information  */
static EDisplaySharpPowerDownStates DisplayDrvSharp_PowerDown_StateMachine[cDISPLAYCDD_MAX_SHARP_DEVICE];

/*!Hold the waitime for the execution of power sequence */
static uint8 DisplayDrvCdd_Sharp_Waittime;

/*!Hold the waitime for the execution of power sequence */
static boolean DisplayDrvCdd_Sharp_PowerisUp;

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION

/*! To indicate the current gamma correction Status */
static EGammaCorrectionStatus  GammaCorrectionCurrentStatus;

/*! To indicate the current gamma correction state */
static uint8 GammaCorrectionState;

/*! To indicate the gamma correction sequence state */
static uint8 GammaCorrectionSequenceState;

/*! To store the data transmitted over I2c */
//static uint8 I2c_TxBuffer[GMA_WRITE_BUFF_SIZE];

/*! To store the write index during applying red, green and blue settings in each iteration of gamma settings sequence */
static uint8 Gamma_RGB_WriteIndex;

//RGB - Default values for SHARP
uint8 GammaCorrectionData[(GMA_REG_LEN_SHARP*3)] =
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
static void DisplayDrvCdd_SharpFaultHandle(void);
static void DisplayDrvCdd_SharpMonitorFaultStatus(uint8 deviceIndex);

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
static Std_ReturnType DisplayDrvCdd_SharpLoadGammaSettingsFromNvM(void);
static void DisplayDrvCdd_SharpGammaCorrectionSequenceExecution(void);
static void DisplayDrvCdd_SharpGammaCorrectionSequence(void);
static void DisplayDrvCdd_SharpStartCalibrationProcedure(void);
#endif

static void DisplayDrvCdd_SharpPowerUpSequence(void);
static void DisplayDrvCdd_SharpPowerDownSequence(void);

extern Std_ReturnType IoHwAb_SetOutputPin(uint8 OutputId, boolean OutputSignal, uint8* ErrorStatus);

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  void
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_SharpInit(uint8 DeviceindexId)
{
	
	Std_ReturnType status = E_NOT_OK;
	uint8 Device_No;
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_SHARP_DEVICE; Device_No++)
	{
		DisplayDrvSharpInfoTable[Device_No].DeviceID         	= DisplaySharpInfoDB[DeviceindexId].DisplayDeviceId;
		DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin     = DisplaySharpInfoDB[DeviceindexId].DisplaySupplyPin;
		DisplayDrvSharpInfoTable[Device_No].DeviceResetPin      = DisplaySharpInfoDB[DeviceindexId].DisplayResetPin;	
		DisplayDrvSharpInfoTable[Device_No].DeviceStandbyPin    = DisplaySharpInfoDB[DeviceindexId].DisplayStandbyPin;
		DisplayDrvSharpInfoTable[Device_No].FaultStatusPin      = DisplaySharpInfoDB[DeviceindexId].DisplayFaultStatusPin;	
		DisplayDrvSharpInfoTable[Device_No].FaultStatus         = (boolean)FALSE;
		
		#ifdef  CDISPLAYCDD_ENABLE_AUTOMATIC_POWERON_FOR_MULTIDISPLAY
			DisplayDrvSharp_PowerUp_StateMachine[Device_No]		   	= eDisplaySharp_PowerON_SupplyPinupdate;
		#else
			DisplayDrvSharp_PowerUp_StateMachine[Device_No]		   	= eDisplaySharp_PowerON_IdleState;
		#endif
		DisplayDrvSharp_PowerDown_StateMachine[Device_No]	        = eDisplaySharp_PowerOFF_IdleState;
	}
	DisplayDrvCdd_Sharp_Waittime = DISPLAYCDD_INIT_WAITIME;
	
	DisplayDrvCdd_Sharp_PowerisUp = (boolean)FALSE;
	
	#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
		GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_None;
		GammaCorrectionState = GMA_SET_STATE_IDLE;
		GammaCorrectionSequenceState = GMA_SET_STEP_IDLE;
		Gamma_RGB_WriteIndex = 0u;
		
		DisplayDrvCdd_SharpStartCalibrationProcedure();
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
Std_ReturnType DisplayDrvCdd_SharpDeInit(void)
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
Std_ReturnType DisplayDrvCdd_SharpSetState(uint8 DeviceIndex , EDisplayPowerState NewPowerState)
{
	Std_ReturnType ret = E_NOT_OK;
	#ifdef CDISPLAYCDD_SUPPORT_MULTIDISPLAY
		DeviceIndex = 0u;	
	#endif	
	
	if(eDisplayPowerON == NewPowerState)
	{
		/*Switch the power up state machine to power on state*/
		DisplayDrvSharp_PowerUp_StateMachine[DeviceIndex] = eDisplaySharp_PowerON_SupplyPinupdate;
		DisplayDrvCdd_SharpPowerUpSequence();
	}
	else if (eDisplayPowerOFF == NewPowerState)
	{
		/*Switch the power down state machine to power off state*/
		DisplayDrvSharp_PowerDown_StateMachine[DeviceIndex] = eDisplaySharp_PowerOFFState;
		DisplayDrvCdd_SharpPowerDownSequence();		
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
void DisplayDrvCdd_SharpMainFunction(void)
{
	uint8 Device_No;
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_SHARP_DEVICE; Device_No++)
	{

		if(DisplayDrvSharp_PowerUp_StateMachine[Device_No] != eDisplaySharp_PowerON_IdleState)
		{
			(void)DisplayDrvCdd_SharpPowerUpSequence();
		}
		else
		{
			/* do nothing */
		}

		if(DisplayDrvSharp_PowerDown_StateMachine[Device_No] != eDisplaySharp_PowerOFF_IdleState)
		{
			(void)DisplayDrvCdd_SharpPowerDownSequence();
		}
		else
		{
			/* do nothing */
		}
	}
	
	#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
		DisplayDrvCdd_SharpGammaCorrectionSequenceExecution();
	#endif
}

/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power up sequence
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_SharpPowerUpSequence(void)
{
	uint8 Device_No;
	Std_ReturnType NotifyResult = E_NOT_OK;
	
	
	#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
	    static Std_ReturnType iohwresult;
		IoHwAb_ErrorType GetErrorStatus;
	#endif
    
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_SHARP_DEVICE; Device_No++)
	{

			switch(DisplayDrvSharp_PowerUp_StateMachine[Device_No])
			{
				case eDisplaySharp_PowerON_IdleState:
				{
					/*Do nothing*/
				}
				break;
				case eDisplaySharp_PowerON_SupplyPinupdate:
				{		
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							//Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin, STD_HIGH , &GetErrorStatus);
							iohwresult = IoHwAb_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin, STD_HIGH);
						#endif
						
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWERON_DELAY1;
						DisplayDrvSharp_PowerUp_StateMachine[Device_No] = eDisplaySharp_PowerON_ResetPinupdate;
					}
				}	
				break;			
				case eDisplaySharp_PowerON_ResetPinupdate:
				{				
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							iohwresult = IoHwAb_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceResetPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceResetPin, STD_HIGH);
						#endif
					
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWERON_DELAY2;
						DisplayDrvSharp_PowerUp_StateMachine[Device_No] = eDisplaySharp_PowerON_StandbyPinupdate;
					}

				}
				break;
				case eDisplaySharp_PowerON_StandbyPinupdate:
				{
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							iohwresult =IoHwAb_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceStandbyPin, STD_HIGH , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceStandbyPin, STD_HIGH);
						#endif
					
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWERON_DELAY3;
						DisplayDrvSharp_PowerUp_StateMachine[Device_No] = eDisplaySharp_NormalState; 
					}						
							 
				}
				break;
				case eDisplaySharp_PowerON_EnableBacklight:
				{	
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							//iohwresult = IoHwAb_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceBacklightPin, STD_HIGH , &GetErrorStatus);
						#else
							//Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceBacklightPin, STD_HIGH);
						#endif
					
						DisplayDrvSharp_PowerUp_StateMachine[Device_No] = eDisplaySharp_NormalState;
					}	 
				}
				break;
				case eDisplaySharp_NormalState:
				{
					/*Notify that power state*/
					NotifyResult = DispIfCdd_NotifyDisplayStatus(DisplayDrvSharpInfoTable[Device_No].DeviceID  , eDisplayNormal);
					
					DisplayDrvCdd_Sharp_PowerisUp = TRUE;
					
					if(E_OK == NotifyResult)
					{
						DisplayDrvSharp_PowerUp_StateMachine[Device_No] = eDisplaySharp_PowerON_FailDetection;
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWERON_DELAY4;
					}
				}
				break;
				case eDisplaySharp_PowerON_FailDetection:
				{	
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						(void)DisplayDrvCdd_SharpMonitorFaultStatus(Device_No);
					}						
							 
				}
				break;		
				case eDisplaySharp_FaultState:
				{
					DisplayDrvCdd_SharpFaultHandle();
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
void DisplayDrvCdd_SharpPowerDownSequence(void)
{
	uint8 Device_No;
	Std_ReturnType NotifyResult = E_NOT_OK;
	
	#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
		IoHwAb_ErrorType GetErrorStatus;
	#endif
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_SHARP_DEVICE; Device_No++)
	{
			switch(DisplayDrvSharp_PowerDown_StateMachine[Device_No])
			{
				case eDisplaySharp_PowerOFF_IdleState:
				{
					/* do nothing */
				}
				break;
				case eDisplaySharp_PowerOFFState:
				{
					DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWEROFF_DELAY2;
					DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFF_StandbyPinUpdate;
				}
				break;
				case eDisplaySharp_PowerOFF_DisableBacklight:
				{        
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{					

						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							//Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceBacklightPin, STD_LOW , &GetErrorStatus);
						#else
							//Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceBacklightPin, STD_LOW);
						#endif
					
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWEROFF_DELAY2;
						DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFF_StandbyPinUpdate;
					}						
				}
				break;
				case eDisplaySharp_PowerOFF_StandbyPinUpdate:
				{        
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{					

						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceStandbyPin, STD_LOW , &GetErrorStatus);
						#else
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceStandbyPin, STD_LOW);
						#endif
					
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWEROFF_DELAY3;
						DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFF_FailDetection;
					}						
				}
				break;
				case eDisplaySharp_PowerOFF_FailDetection:
				{        
					if(DisplayDrvCdd_Sharp_Waittime >=1)
					{
						DisplayDrvCdd_Sharp_Waittime--;
						(void)DisplayDrvCdd_SharpMonitorFaultStatus(Device_No);
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0)
					{
						DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWEROFF_DELAY4;
						DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFF_SupplyResetPinsUpdate;
					}
				}				
				break;	
				case eDisplaySharp_PowerOFF_SupplyResetPinsUpdate:
				{
					if(DisplayDrvCdd_Sharp_Waittime >=1u)
					{
						DisplayDrvCdd_Sharp_Waittime--;
					}
					
					if(DisplayDrvCdd_Sharp_Waittime <= 0u)
					{
						#ifdef CDISPLAYCDD_USE_IOHWAB_API_REQUIRED
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin, STD_LOW , &GetErrorStatus);
							Rte_Call_rpIoHwAb_SetDout_SetOutputPin(DisplayDrvSharpInfoTable[Device_No].DeviceResetPin, STD_LOW , &GetErrorStatus);	
						#else
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceSupplyPin, STD_LOW);
							Dio_WriteChannel(DisplayDrvSharpInfoTable[Device_No].DeviceResetPin, STD_LOW);
						#endif

						DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFFState_Complete;
					}
				}	
				case eDisplaySharp_PowerOFFState_Complete:
				{					
						/*Notify that power state is complete*/
						NotifyResult = DispIfCdd_NotifyDisplayStatus(DisplayDrvSharpInfoTable[Device_No].DeviceID , eDisplayPowerOFF);
						
						DisplayDrvCdd_Sharp_PowerisUp = (boolean)FALSE;
						if(E_OK == NotifyResult)
						{
							DisplayDrvCdd_Sharp_Waittime = cDISPLAYCDD_SHARP_POWERON_DELAY5;
							DisplayDrvSharp_PowerDown_StateMachine[Device_No] = eDisplaySharp_PowerOFF_IdleState;
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
static void DisplayDrvCdd_SharpMonitorFaultStatus(uint8 deviceIndex)
{
	uint8 FaultStatus = STD_HIGH;
	
	FaultStatus = Dio_ReadChannel(DisplayDrvSharpInfoTable[deviceIndex].FaultStatusPin);
	
	if(STD_HIGH == FaultStatus)
	{	
		DisplayDrvSharpInfoTable[deviceIndex].FaultStatus = (boolean)FALSE;	
	}
	else
	{
		DisplayDrvSharpInfoTable[deviceIndex].FaultStatus = (boolean)TRUE;
		/*Switch  the state machine to Fault handle*/
		DisplayDrvSharp_PowerUp_StateMachine[deviceIndex] = eDisplaySharp_FaultState;	
		/*Notify Fault state as occured.*/
		DispIfCdd_NotifyDisplayStatus(DisplayDrvSharpInfoTable[deviceIndex].DeviceID , eDisplayFault);			
	}
}

/*!***************************************************************************************************************** 
*   @brief      The function is resposible for fault handling
*   @param[in]  void
*   @return  void 
********************************************************************************************************************/
static void DisplayDrvCdd_SharpFaultHandle(void)
{
	/* To be implementation in future*/
}


/*!*****************************************************************************************************************
 *   @brief      	To execute gamma correction in the pre-defined sequence
 ********************************************************************************************************************/
static void DisplayDrvCdd_SharpGammaCorrectionSequenceExecution(void)
{
	switch(GammaCorrectionState)
	{
		case GMA_SET_STATE_IDLE:
			break;
			
		case GMA_SET_STATE_DISPLAY_POWERON_WAIT:
			if((boolean)FALSE != DisplayDrvCdd_Sharp_PowerisUp)
			{
				GammaCorrectionState = GMA_SET_STATE_SEQ_EXECUTION;
				GammaCorrectionCurrentStatus = eDisplayCdd_GammaCorrection_OnGoing;
			}
			break;
			
		case GMA_SET_STATE_SEQ_EXECUTION:
			DisplayDrvCdd_SharpGammaCorrectionSequence();
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
 *   @brief      	To execute gamma correction  sequence for SHARP display
 ********************************************************************************************************************/
static void DisplayDrvCdd_SharpGammaCorrectionSequence(void)
{
	uint8 I2c_RegAdd, I2c_TxData;
	Std_ReturnType Ret = E_OK;
	
	
	switch (GammaCorrectionSequenceState)
	{
		case GMA_SET_STEP_IDLE:
			/* Either initialization completed or not yet started */
			break;
			
		case GMA_SET_STEP_OPEN_PAGE:
			I2c_RegAdd = GMA_SET_SHARP_SEL_D_A;
			I2c_TxData = GMA_SET_SHARP_SEL_PAGE;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01 , SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState++;
			break;
			
		case GMA_SET_STEP_PASSWARD:
			I2c_RegAdd = GMA_SET_SHARP_OTP_D_A;
			I2c_TxData = GMA_SET_SHARP_OTP_D;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState++;
			break;			
			
		case GMA_SET_STEP_GMA_SET_ADDRESS:
			I2c_RegAdd = GMA_SET_SHARP_EN_D_A;
			I2c_TxData = GMA_SET_SHARP_EN_D;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState = GammaCorrectionSequenceState + 2u;
			break;
			
		case GMA_SET_STEP_RED:
			/* Page-2 Red color gamma register table */
			I2c_RegAdd = GMA_SET_SHARP_SEL_D_A;
			I2c_TxData = GMA_SET_SHARP_PS_R;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_RED_SETTING:

			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_SHARP)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex;
				I2c_TxData = GammaCorrectionData[Gamma_RGB_WriteIndex];
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
				Gamma_RGB_WriteIndex ++;
			}
			else
			{
				GammaCorrectionSequenceState++;
			}
			break;
			
		case GMA_SET_STEP_GREEN:
			/* Page-3 Green color gamma register table */
			I2c_RegAdd = GMA_SET_SHARP_SEL_D_A;
			I2c_TxData = GMA_SET_SHARP_PS_G;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_GREEN_SETTING:
			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_SHARP)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex;
				I2c_TxData = GammaCorrectionData[GMA_REG_LEN_SHARP + Gamma_RGB_WriteIndex];
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
				Gamma_RGB_WriteIndex ++;
			}
			else
			{
				GammaCorrectionSequenceState++;
			}
			break;
			
		case GMA_SET_STEP_BLUE:
			/* Page-3 Green color gamma register table */
			I2c_RegAdd = GMA_SET_SHARP_SEL_D_A;
			I2c_TxData = GMA_SET_SHARP_PS_B;
			Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
			GammaCorrectionSequenceState++;
			Gamma_RGB_WriteIndex = 0u;
			break;
			
		case GMA_SET_STEP_BLUE_SETTING:
			if (Gamma_RGB_WriteIndex < GMA_REG_LEN_SHARP)
			{
				I2c_RegAdd = Gamma_RGB_WriteIndex;
				I2c_TxData = GammaCorrectionData[(GMA_REG_LEN_SHARP*2) + Gamma_RGB_WriteIndex];
				Ret = DisplayDrvCdd_I2cWrite(I2c_RegAdd, &I2c_TxData, 0x01, SHARP_I2C_CHANNEL , SHARP_I2C_SEQ ,CDISPLAYCDD_SHARP);
				Gamma_RGB_WriteIndex ++;
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
Std_ReturnType DisplayDrvCdd_SharpSetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength)
{
	Std_ReturnType RetVal;
	uint32 index;
	if(GammaCorrectionCurrentStatus != eDisplayCdd_GammaCorrection_OnGoing)
	{
		for (index = 0u; index < (uint32)datalength; index++)
		{
			GammaCorrectionData[index] = (uint8)(*(GmaSetPtr+index));
		}
		
		if((boolean)FALSE != DisplayDrvCdd_Sharp_PowerisUp)
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
void DisplayDrvCdd_SharpGetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
{
	if ((GMA_SET_STEP_IDLE == GammaCorrectionSequenceState) && (GMA_SET_STATE_COMPLETED == GammaCorrectionState))
	{
		*GmaCrStatus = GammaCorrectionCurrentStatus;
	}
}

/*!***************************************************************************************************************** 
*   @brief      To read the TFT type and gamma settings from NvM and to trigger writing of gamma settings in TFT display
********************************************************************************************************************/
static void DisplayDrvCdd_SharpStartCalibrationProcedure(void)
{
	Std_ReturnType RetVal;
	
	RetVal= DisplayDrvCdd_SharpLoadGammaSettingsFromNvM();	
	
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
		if((boolean)FALSE != DisplayDrvCdd_Sharp_PowerisUp)
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
static Std_ReturnType DisplayDrvCdd_SharpLoadGammaSettingsFromNvM(void)
{
	Std_ReturnType RetValue, RetVal = E_NOT_OK;

	/* Read SHARP gamma data from NVM */
	RetVal = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Red_Gamma_Adjustment_Display1_Handle, GammaCorrectionData, GMA_REG_LEN_SHARP);
	RetValue = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Green_Gamma_Adjustment_Display1_Handle, (GammaCorrectionData+GMA_REG_LEN_SHARP), GMA_REG_LEN_SHARP);
	RetVal = (RetVal | RetValue);
	RetValue = DisplayIfCdd_ReadGammaSettingsFromNvM(Array_Blue_Gamma_Adjustment_Display1_Handle, (GammaCorrectionData+(GMA_REG_LEN_SHARP * 2)), GMA_REG_LEN_SHARP);
	RetVal = (RetVal | RetValue);
		
	return RetVal;
}


/*!***************************************************************************************************************** 
*   @brief      Error Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_SharpI2cSeqErrorCallback(void)
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




