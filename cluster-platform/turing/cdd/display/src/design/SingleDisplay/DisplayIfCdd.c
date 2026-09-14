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
*    @file DisplayIfCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayIfCdd APIs. This header file should be included by other  
*    modules that use these APIs.
********************************************************************************************************************/
#define DISPLAYIFCDD_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
 
#include "DisplayCdd_Types.h" 
#include "DisplayCdd_Cfg.h"

#include "DisplayMgrCdd.h"
#include "DisplayIfCdd.h"

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TIANMA
#include "DisplayDrvCdd_Tianma.h"
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
#include "DisplayDrvCdd_Sharp.h"
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
#include "DisplayDrvCdd_Truly.h"
#endif


/*
Description: To hold the details related to EEPROM load 
*/
typedef struct 
{
    EDisplayType               DeviceID;                         /* Uinque ID of a device*/
    EDisplayStatus 			   DeviceStatus;		        	/* Hold the repective device status as ready , NotReady , Busy*/
	EDisplayPowerState		   DevicePowerState;				/*Hold the repective device power state as POWERON , NORMAL , FAULT , POWEROFF */

}SDisplayInfo;


/*! Hold the EEPROM related information  */
static SDisplayInfo DisplayInfoTable[cDISPLAYCDD_MAX_DEVICE];
/*! Hold the New Requested Display Power state  */
static EDisplayPowerState DisplayIfCdd_NewPowerState[cDISPLAYCDD_MAX_DEVICE];

/*Hold the Display  related config*/
#if defined(CDISPLAYCDD_ENABLE_DISPLAY_TIANMA) && defined(CDISPLAYCDD_ENABLE_DISPLAY_POWERCONTROL)
const SDisplayDB DisplayInfoDB[cDISPLAYCDD_MAX_DEVICE] = {DISPLAY_CONFIG_DB};
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
const SDisplaySharpDB DisplaySharpInfoDB[cDISPLAYCDD_MAX_DEVICE] = {DISPLAY_SHARP_CONFIG_DB};
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
const SDisplayTrulyDB DisplayTrulyInfoDB[cDISPLAYCDD_MAX_DEVICE] = {DISPLAY_TRULY_CONFIG_DB};
#endif

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_Init(void)
{
	Std_ReturnType status = E_NOT_OK;
	
	uint8 Device_No;
	uint8 Variant_No;
		
	/*Initialise the variables */
    for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		if(Device_No == e_Display8Inch)
		{
			#if defined(CDISPLAYCDD_ENABLE_DISPLAY_TIANMA) && defined(CDISPLAYCDD_ENABLE_DISPLAY_POWERCONTROL)
				Variant_No = 0;
				DisplayInfoTable[Device_No].DeviceID              = DisplayInfoDB[Variant_No].DisplayDeviceId;
			#endif
		}
		else if(Device_No == e_Display12Inch)
		{
			#if defined(CDISPLAYCDD_ENABLE_DISPLAY_TIANMA) && defined(CDISPLAYCDD_ENABLE_DISPLAY_POWERCONTROL)
				Variant_No = 1;
				DisplayInfoTable[Device_No].DeviceID              = DisplayInfoDB[Variant_No].DisplayDeviceId;
			#endif
		}
		else if(Device_No == e_DisplaySharp)	
		{			
			#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
				Variant_No = 0;
				DisplayInfoTable[Device_No].DeviceID              = DisplaySharpInfoDB[Variant_No].DisplayDeviceId;
			#endif
		}
		else if(Device_No == e_DisplayTruly)
		{			
			#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
				Variant_No = 0;
				DisplayInfoTable[Device_No].DeviceID              = DisplayTrulyInfoDB[Variant_No].DisplayDeviceId;
			#endif
		}
		else
		{
			/* do nothing */
		}
		
		DisplayInfoTable[Device_No].DeviceStatus          = cDISPLAYCDD_INIT_DEVICE_STATUS;
		DisplayInfoTable[Device_No].DevicePowerState      = cDISPLAYCDD_INIT_POWER_STATE;		
		
		DisplayIfCdd_NewPowerState[Device_No] = eDisplayIdle;
	}
	
	status = E_OK;
	
	return status;
	
}
/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_DeInit( void)
{
	Std_ReturnType DeInitResult = E_OK;
	return DeInitResult;
	
}

/*!***************************************************************************************************************** 
*   @brief      The function 
*   @param[in]  void
*   @return  	Void
********************************************************************************************************************/
void DisplayIfCdd_MainFunction(void)
{
	
	/*Invoke the Driver layer main function to perform Display power , fault sequence */
	DisplayDrvCdd_MainFunction();

}

void DisplayIfCdd_GetDeviceId(uint8 Index , uint8 *GetDeviceIdNo)
{
	*GetDeviceIdNo = DisplayInfoTable[Index].DeviceID;
	
}

/*!***************************************************************************************************************** 
*   @brief      The function is used to the new state to particular display
*   @param[in]  DeviceId - Device ID - Tianma 8inch , Tianma 12 inch , Sharp , Truly 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_SetState(EDisplayType DeviceId,EDisplayPowerState NewState )
{
	Std_ReturnType status = E_NOT_OK;
	uint8 Device_No;
	uint8 Device_Index = 0;
	
	/*check the respective chip to update the status of EEPROM load*/
	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE ; Device_No++)
	{
		if(DeviceId == DisplayInfoTable[Device_No].DeviceID)
		{
			Device_Index = DeviceId;
			/*Accept the new power state if Device is identified*/
			DisplayIfCdd_NewPowerState[DeviceId] = NewState;	
		}
			
	}
	
	if((eDisplayBusy != DisplayInfoTable[Device_Index].DeviceStatus) && (DisplayIfCdd_NewPowerState[Device_Index] != DisplayInfoTable[Device_Index].DevicePowerState))
	{
		/*Set the particular display status as busy indicating , going to perform the requested power state transistion*/
		DisplayInfoTable[Device_Index].DeviceStatus = eDisplayBusy;
		
		/*Call the driver layer to execute the new power state*/
		status = DisplayDrvCdd_SetState(Device_Index , DisplayIfCdd_NewPowerState[Device_Index]);
	}
	return status;
	
}


/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_GetDisplayStatus(EDisplayType DeviceId, EDisplayStatus *GetDeviceStatus , EDisplayPowerState *GetPresentPowerState )
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 Device_No;
	
	
	/*check the respective chip to update the status of EEPROM load*/
	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE ; Device_No++)
	{
		if(DeviceId == DisplayInfoTable[Device_No].DeviceID)
		{
		
			*GetPresentPowerState = DisplayInfoTable[Device_No].DevicePowerState;
			
			*GetDeviceStatus = DisplayInfoTable[Device_No].DeviceStatus;

		}
			
	}
  
	return Status;
}


/*!***************************************************************************************************************** 
*   @brief      
*   @param[in]  DeviceId - Device ID - Tianma 8inch , Tianma 12 inch , Sharp , Truly 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_NotifyDisplayStatus(uint8 DeviceIndex, EDisplayPowerState CompletedPowerState)
{
	Std_ReturnType NotifyStatusResult = E_NOT_OK;
	EDisplayType DeviceID = cDISPLAYCDD_MAX_DEVICE;
	
	if(DeviceIndex < cDISPLAYCDD_MAX_DEVICE )
	{
		
		if((DisplayIfCdd_NewPowerState[DeviceIndex] == CompletedPowerState) || 
		   ((eDisplayNormal == CompletedPowerState)  && (eDisplayPowerON == DisplayIfCdd_NewPowerState[DeviceIndex])))
		{	
			/*Set the particular display status as ready indicating , requested power state transistion is complete*/
			DisplayInfoTable[DeviceIndex].DeviceStatus = eDisplayReady;			
		}
		else if(eDisplayFault == CompletedPowerState)
		{			
			/*Set the particular display status as fault handle if fault is occured in display*/
			DisplayInfoTable[DeviceIndex].DeviceStatus = eDisplayFaultHandle;			
		}		
		else
		{
			/*Set the particular display status as Not ready indicating Failure happened in requested Power state*/
			DisplayInfoTable[DeviceIndex].DeviceStatus = eDisplayNotReady;			
			
		}
		
		/*Clear the DisplayIfCdd_NewPowerState[DeviceIndex]*/
		DisplayIfCdd_NewPowerState[DeviceIndex] = eDisplayIdle;
		
		/*Intimate the IF layer buffers about the power states*/	
		DisplayInfoTable[DeviceIndex].DevicePowerState = CompletedPowerState;
		
		/*Get the respective device ID */
		DeviceID = DisplayInfoTable[DeviceIndex].DeviceID ; 
		/*Call the mgr layer */
		NotifyStatusResult = DisplayMgrCdd_NotifyState( DeviceID , CompletedPowerState);	
	}
	
	return NotifyStatusResult;
	
}

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_SetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength)
{
	Std_ReturnType RetVal = E_NOT_OK;
	
	if(NULL != GmaSetPtr)
	{
		#if defined(CDISPLAYCDD_ENABLE_DISPLAY_SHARP) || defined(CDISPLAYCDD_ENABLE_DISPLAY_TRULY)
			RetVal = DisplayDrvCdd_SetGammaCorrection(GmaSetPtr, datalength);
		#endif	
	}
	return RetVal;
}
  
/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayIfCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
{
	#if defined(CDISPLAYCDD_ENABLE_DISPLAY_SHARP) || defined(CDISPLAYCDD_ENABLE_DISPLAY_TRULY)
		DisplayDrvCdd_GetGammaCorrectionStatus(GmaCrStatus);
	#endif
}

/*!***************************************************************************************************************** 
*   @brief      To request the DisplayMgrCdd to read the gamma settings to be applied from NvM
*   @param[in]  Handle - data handle
*   @param[in]  GmaCrData - Pointer to get the gamma correction data
*   @param[in]  length - length of data to be read
*   @return  Std_ReturnType E_NOT_OK - GammaSettings Read Operation is failed
*                           E_OK - GammaSettings Read Operation is successful
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_ReadGammaSettingsFromNvM(uint8 *Handle, uint8 *GmaCrData, uint16 length)
{
	Std_ReturnType RetVal = E_NOT_OK;
	if((NULL != Handle) && (NULL != GmaCrData) && (length > 0u))
	{
		RetVal = DisplayMgrCdd_ReadGammaSettingsFromNvM(Handle, GmaCrData, length);
	}
	return RetVal;
}

#endif

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


