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
#define DISPLAYDRVCDD_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Cfg.h"

#include "DisplayIfCdd.h"

#include "DisplayDrvCdd.h"


#include "DisplayDrvCdd_Cbk.h"
#include "DisplayCdd_Types.h"

//#include "I2c.h" //ToDo: Need to be reverted

/*=====================================================================================================================
  CONSTANTS & TYPES
=====================================================================================================================*/
/*! @brief Defines the maximum data length of SPI */
#define DISPLAYCDD_INIT_WAITIME        (3u)

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
Description: To hold the details related to Drv
*/
typedef struct 
{
	uint8                      IdentifiedDeviceID;              /* Holds the Identified device ID*/
	boolean				       EnterMeetMode;
	boolean				       DeviceIdentified;		        /* Hold wheyher device is identified or not*/
}SDisplayDrvInfo;

/*! Hold the Display driver  related information  */
//static SDisplayDrvInfo DisplayDrvInfoTable[cDISPLAYCDD_MAX_DEVICE];
static SDisplayDrvInfo DisplayDrvInfoTable;

/*!Hold the retry count during auto detect feature */
static uint8 DisplayDrvCdd_RetryCounttime;

/*!Hold the waitime for the execution of power sequence */
static boolean DisplayDrvCdd_Sharp_PowerisUp;


/*Mutli Display Support implementation */
typedef Std_ReturnType (* TDrv_Call_Init)(uint8 DeviceindexId);
typedef struct 
{
    TDrv_Call_Init Drv_Init;
}CDisplayDrvCddInitCall;
static const CDisplayDrvCddInitCall DisplayCdd_Init[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_INIT}; 

typedef Std_ReturnType (* TDrv_Call_Main)(void);
typedef struct 
{
    TDrv_Call_Main Drv_Main;
}CDisplayDrvCddMainCall;
static const CDisplayDrvCddMainCall DisplayCdd_Main[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_MAIN};


typedef Std_ReturnType (* TDrv_Call_SetState)(uint8 DevInd , uint8 PwrState);
typedef struct 
{
    TDrv_Call_SetState Drv_SetState;
}CDisplayDrvCddSetStateCall;
static const CDisplayDrvCddSetStateCall DisplayCdd_SetState[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_SETSTATE};


typedef Std_ReturnType (* TDrv_Call_SetGamaState)(uint8 *Gamasetptr , uint8 DataLen);
typedef struct 
{
    TDrv_Call_SetGamaState Drv_SetGamaState;
}CDisplayDrvCddSetGamaStateCall;
static const CDisplayDrvCddSetGamaStateCall DisplayCdd_SetGamaState[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_SETGAMASTATE};


typedef void (* TDrv_Call_GetGamaState)(uint8 *GamaGetptr);
typedef struct 
{
    TDrv_Call_GetGamaState Drv_GetGamaState;
}CDisplayDrvCddGetGamaStateCall;
static const CDisplayDrvCddGetGamaStateCall DisplayCdd_GetGamaState[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_GETGAMASTATE};

/*=====================================================================================================================
  LOCAL Functions
=====================================================================================================================*/

#ifdef CDISPLAYCDD_ENABLE_AUTO_DETECTION
	static void DisplayDrvCdd_AutoDetectionSequenceExecution(void);
	static void DisplayDrvCdd_DetectDisplayTypeProcedure(void);
#endif
	
#ifdef CDISPLAYCDD_ENABLE_READ_DISPLAYTYPE_NVM	
	static Std_ReturnType DisplayDrvCdd_ReadDisplayTypeFromNvM(void);
#endif	

extern Std_ReturnType IoHwAb_SetOutputPin(uint8 OutputId, boolean OutputSignal, uint8* ErrorStatus);

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  void
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_Init(void)
{
	
	Std_ReturnType status = E_NOT_OK;
	uint8 Device_No;
	#ifdef CDISPLAYCDD_ENABLE_READ_DISPLAYTYPE_NVM
		Std_ReturnType ReadNvmstatus = E_NOT_OK;
	#endif	
	
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayDrvInfoTable.IdentifiedDeviceID        = cDISPLAYCDD_DEVICE_0; 
		DisplayDrvInfoTable.EnterMeetMode             = (boolean)FALSE;
		DisplayDrvInfoTable.DeviceIdentified          = (boolean)FALSE;		
	}

	#ifdef CDISPLAYCDD_ENABLE_READ_DISPLAYTYPE_NVM
		ReadNvmstatus = DisplayDrvCdd_ReadDisplayTypeFromNvM();
		
		/*Init the respective drv from here*/
		if(E_OK == ReadNvmstatus) 
		{
			(void)DisplayCdd_Init[DisplayDrvInfoTable.IdentifiedDeviceID].Drv_Init(DisplayDrvInfoTable.IdentifiedDeviceID);
		}
	#endif
	
	#ifdef CDISPLAYCDD_ENABLE_AUTO_DETECTION
		DisplayDrvCdd_RetryCounttime = DISPLAYCDD_INIT_WAITIME;
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
Std_ReturnType DisplayDrvCdd_DeInit(void)
{
	Std_ReturnType DeInitResult = E_OK;
	uint8 Device_No;
	
		/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayDrvInfoTable.IdentifiedDeviceID        = cDISPLAYCDD_DEVICE_0; 
		DisplayDrvInfoTable.EnterMeetMode             = (boolean)FALSE;
		DisplayDrvInfoTable.DeviceIdentified          = (boolean)FALSE;		
	}
	
	return DeInitResult;	
	
}

/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_MainFunction(void)
{
	uint8 Device_No;
	
	/*Activate the respective drv main function here  */
	(void)DisplayCdd_Main[DisplayDrvInfoTable.IdentifiedDeviceID].Drv_Main();
			
	#ifdef CDISPLAYCDD_ENABLE_AUTO_DETECTION
		DisplayDrvCdd_AutoDetectionSequenceExecution();
	#endif
}


/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetState(uint8 DeviceIndex , EDisplayPowerState NewPowerState)
{
	Std_ReturnType ret = E_NOT_OK;
	
	if(eDisplayPowerON == NewPowerState)
	{
		DisplayDrvInfoTable.IdentifiedDeviceID        = DeviceIndex; 
		DisplayDrvInfoTable.DeviceIdentified          = (boolean)TRUE;	

	}
	else if (eDisplayPowerOFF == NewPowerState)
	{
		DisplayDrvInfoTable.IdentifiedDeviceID        = DeviceIndex; 
		DisplayDrvInfoTable.DeviceIdentified          = (boolean)TRUE;		
	}
	else
	{
		/*Do Nothing */
	}
	
	if(cDISPLAYCDD_DEVICE_0 != DisplayDrvInfoTable.IdentifiedDeviceID)
	{
		(void)DisplayCdd_SetState[DeviceIndex].Drv_SetState(DeviceIndex , NewPowerState);
	}
	else
	{
		(void)DisplayCdd_Init[DisplayDrvInfoTable.IdentifiedDeviceID].Drv_Init(DisplayDrvInfoTable.IdentifiedDeviceID);
	}
		
	ret = E_OK;
	
	return ret;
}



#ifdef CDISPLAYCDD_ENABLE_READ_DISPLAYTYPE_NVM
/*!***************************************************************************************************************** 
*   @brief      To read the TFT type from NvM if present or enter into auto detect mode in MEET mode
********************************************************************************************************************/
static Std_ReturnType DisplayDrvCdd_ReadDisplayTypeFromNvM(void)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 DeviceType;
	static uint8 tmpDeviceType;
	
	RetVal= DisplayIfCdd_ReadDisplayTypeFromNvM(&DeviceType);
	
	if(E_OK == RetVal)
	{
		if((DeviceType != cDISPLAYCDD_DEVICE_0) && (DeviceType < cDISPLAYCDD_MAX_DEVICE))
		{
			DisplayDrvInfoTable.IdentifiedDeviceID        = DeviceType; 
			DisplayDrvInfoTable.DeviceIdentified          = (boolean)TRUE;	
		}	
        else
		{
			/*If the stored device is invalid*/
			RetVal = E_NOT_OK;
		}
	}

	return RetVal;	
	
}
#endif

#ifdef CDISPLAYCDD_ENABLE_AUTO_DETECTION
/*!***************************************************************************************************************** 
*   @brief      To enter into auto detect mode if system is in MEET mode
********************************************************************************************************************/
static void DisplayDrvCdd_DetectDisplayTypeProcedure(void)
{
	Std_ReturnType RetVal;
	boolean MeetModeFlagStatus
	
	RetVal= DisplayIfCdd_ReadMeetModeFlag(&MeetModeFlagStatus);	
	
	if(E_OK == RetVal)
	{
		if(CDISPLAYCDD_MANUFACTURINGMODE == MeetModeFlagStatus)
		{
			DisplayDrvCdd_AutoDetectionSequenceExecution();
		}
	}	
	
}

/*!***************************************************************************************************************** 
*   @brief      To etect the TFT type and writing into NVM during manufacturing Mode
********************************************************************************************************************/
void DisplayDrvCdd_AutoDetectionSequenceExecution(void)
{
	Std_ReturnType Result;

    switch(u8TftAutoDetectStep)
    {
        case 0: //idle

        break;
        case 1:
            if( cFalse != bIsTftAccessAllowed )
            {
                Result = CIoHwAb_Impl_GetPin(CXDR_DisplayDrv_eIOPinInId_LCD_CHECK, (uint8 *)&u8TftConnected);
                if((TFT_CONNECTED_YES == u8TftConnected))//Display connected
                {
                    Result = SRV_Cfg_ReadManufacturing_Mode(&gu8IsManufacturingMode);
                    if((MANUFACTURINGMODE == gu8IsManufacturingMode) && (S_OK == Result))
                    {
                        u8TftAutoDetectStep = 2;//set first step of TFT auto dectect
                    }
                    else
                    {
                        u8TftAutoDetectStep = 0;//exist Display detect
                    }
                }
                else//TFT is not connected
                {
                    u8TftAutoDetectStep = 0;//exist Display detect
                }
            }
        break;
        case 2://detect SHARP first
            u8TftType = TFT_TYPE_SHARP;
            if( cFalse != bIsTftAccessAllowed )
            {
                I2cSingleReadBuff[0] = 0;
                I2cSingleReadBuff[1] = 0;
                u8TftAutoDetectStep = 5;
            }
        break;
        case 5://select page
            Result = IicWrOneByte(0x1E, 0X16);
            if(E_OK == Result)
            {
                u8TftAutoDetectStep = 6;
            }
            else//write not OK, enter next Display detect
            {
                u8TftAutoDetectStep = 9;
            }
            break;
        case 6://write first
            Result = IicWrOneByte(0x02, 0X01);
            if(E_OK == Result)
            {
                u8TftAutoDetectStep = 7;
            }
            else//write not OK, enter next Display detect
            {
                u8TftAutoDetectStep = 9;
            }
        break;
        case 7://read data
            Result = IicRdOneByte(0x02);
            if(E_OK == Result)
            {
                u8TftAutoDetectStep = 8;
            }
            else//write not OK, enter next Display detect
            {
                u8TftAutoDetectStep = 9;
            }
        break;
        case 8://judge result
            if(0x01 == I2cSingleReadBuff[0])//Current TFT type is SHARP, ready to write NVM
            {
                u8TftAutoDetectStep = 14;
                u8TftType = TFT_TYPE_SHARP;
            }
            else
            {
                u8TftAutoDetectStep = 9;//detect SHARP failed, ready to detect TRULY
            }
        break;
        case 9://set TFT type to TRULY, then detect
            u8TftType = TFT_TYPE_TRULY;
            if( cFalse != bIsTftAccessAllowed )
            {
                I2cSingleReadBuff[0] = 0;
                I2cSingleReadBuff[1] = 0;
                u8TftAutoDetectStep = 10;
            }
        break;
        case 10://enable address operate
            Result = IicWrOneByte(0x00, 0X04);
            if(E_OK == Result)
            {
                u8TftAutoDetectStep = 11;
            }
            else//write not OK, enter next Display detect
            {
                u8TftAutoDetectStep = 13;
            }
        break;
        case 11://write 0x8F first
            Result = IicWrOneByte(0x02, 0X8f);
            if(E_OK == Result)
            {
                u8TftAutoDetectStep = 12;
            }
            else//write not OK, enter next Display detect
            {
                u8TftAutoDetectStep = 13;
            }
        break;
        case 12://then read
            (void)IicRdOneByte(0x02);
            u8TftAutoDetectStep = 13;
        break;
        case 13://judge result
            if(0x8F == I2cSingleReadBuff[0])//current Display is TRULY
            {
                u8TftAutoDetectStep = 14;
                u8TftType = TFT_TYPE_TRULY;
            }
            else//detect failed
            {
                u8GammaWriteIndex++;
                if(TFT_AUTO_DETECT_TIME_MAX == u8GammaWriteIndex)
                {
                    u8GammaWriteIndex = 0;
                    u8TftAutoDetectStep = 14;
                    u8TftType = TFT_TYPE_ERR;
                }
                else
                {
                    u8TftAutoDetectStep = 2;
                }
            }

        break;
        case 14://write TFT type into NVM
            u8TftAutoDetectStep = 0;
            (void)SRV_Cfg_WriteDisplay_Type(u8TftType);
        break;
        default:
        break;
    }
}

#endif


/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @param[in]  datalength - Lenght of the data available in buffer pointer
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetGammaCorrection(uint8 *DrvGmaSetPtr, uint8 Drvdatalength)
{
	Std_ReturnType RetVal = E_NOT_OK;
	
	if(cDISPLAYCDD_DEVICE_0 != DisplayDrvInfoTable.IdentifiedDeviceID)
	{
		RetVal = DisplayCdd_SetGamaState[DisplayDrvInfoTable.IdentifiedDeviceID].Drv_SetGamaState(DrvGmaSetPtr , Drvdatalength);
	}
	
	return RetVal;
}

/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayDrvCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *DrvGmaCrStatus)
{
	if(cDISPLAYCDD_DEVICE_0 != DisplayDrvInfoTable.IdentifiedDeviceID)
	{
		(void)DisplayCdd_GetGamaState[DisplayDrvInfoTable.IdentifiedDeviceID].Drv_GetGamaState(DrvGmaCrStatus);
	}
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

