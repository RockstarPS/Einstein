/*---------------------------------------------------------------------------------------------------------------------

VISTEON CORPORATION CONFIDENTIAL
_______________________________

[2019] Visteon Corporation
All Rights Reserved.

NOTICE: This is an unpublished work of authorship, which contains trade secrets.
Visteon Corporat/ion owns all rights to this work and intends to maintain it in confidence to preserve
its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
under all copyright laws to protect this work as a published work, when appropriate.
Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
/*!*****************************************************************************************************************
*    @file DisplayMgrCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayMgrCdd APIs, which can be used to Activate and decativate and display
********************************************************************************************************************/
 #define DISPLAYMGRCDD_C
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

#ifdef CDISPLAYCDD_ENABLE_AUTOMATICPOWERON
static uint8 InitialPowerOn[cDISPLAYCDD_MAX_DEVICE];
static boolean IsDeviceInitilazed;
#endif

#ifdef CDISPLAYCDD_ENABLE_AUTOMATICPOWERON
static void DisplayMgrCdd_HandleInitilaPowerState(void);
#endif

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayMgrCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
 Std_ReturnType DisplayMgrCdd_Init(void)
{
	Std_ReturnType InitResult = E_OK;
	
	#ifdef CDISPLAYCDD_ENABLE_AUTOMATICPOWERON
		uint8 Device_No;
			
		/*Initialise the variables */
		for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
		{
			InitialPowerOn[Device_No] = eDisplayPowerON;
		}
		
		IsDeviceInitilazed = (boolean)FALSE;
	#endif
	
	return InitResult;
}
/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displayMgrCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/ 
 Std_ReturnType DisplayMgrCdd_DeInit(void)
{
	Std_ReturnType DeInitResult = E_OK;
	return DeInitResult;
}


/*!***************************************************************************************************************** 
*   @brief      The function  is used to perform power handling and fault monitor
*   @param[in]  None
*   @return     None
********************************************************************************************************************/
void DisplayMgrCdd_MainFunction(void)
{
	
	/*Invoke the Driver layer main function to perform Display power , fault sequence */
	DisplayIfCdd_MainFunction();
	
	#ifdef CDISPLAYCDD_ENABLE_AUTOMATICPOWERON
		if((boolean)FALSE == IsDeviceInitilazed )
		{
			(void)DisplayMgrCdd_HandleInitilaPowerState();
		}
	#endif
}

/*!***************************************************************************************************************** 
*   @brief      The function is used to the new state to particular display
*   @param[in]  DeviceId - Device ID - 8inch or 12 inch 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_SetState(EDisplayType DeviceId,EDisplayPowerState NewState )
{
	Std_ReturnType status = E_NOT_OK;
	
	if((DeviceId < cDISPLAYCDD_MAX_DEVICE) && (NewState < cDISPLAYCDD_MAX_POWERSTATES))
	{
		status = DisplayIfCdd_SetState(DeviceId , NewState);
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
Std_ReturnType DisplayMgrCdd_GetStatus(EDisplayType DeviceId, EDisplayStatus *DeviceStatus , EDisplayPowerState *GetPresentPowerState )
{
	Std_ReturnType statusResult = E_NOT_OK;
	
	if(DeviceId < cDISPLAYCDD_MAX_DEVICE)
	{
		statusResult = DispIfCdd_GetDisplayStatus(DeviceId , DeviceStatus , GetPresentPowerState);
	}
	return statusResult;
}

/*!***************************************************************************************************************** 
*   @brief      The function notify the BacklightCdd and the TouchCdd whether the device is ready 
*   @param[in]  DeviceId - Repectice Device ID 
*   @param[in]  EDisplayPowerState - Repectice Device power state- completed / fault occured 
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_NotifyState(EDisplayType DeviceId, EDisplayPowerState PowerState )
{
	Std_ReturnType statusResult = E_NOT_OK;
	
	#ifdef CDISPLAYCDD_ENABLE_NOTIFICATION
		/*Define the RTE call to intimate Appctrl , BacklightCdd and TouchCdd that device state as POWERON , NORMAL , POWEROFF, FAULT state */
		statusResult = DisplayMgrCdd_RTE_AppctrlNotify(DeviceId , PowerState);
		
		if(E_OK == statusResult)
		{
			statusResult = DisplayMgrCdd_RTE_BacklightCddNotify(DeviceId , PowerState);
		}
		
		if(E_OK == statusResult)
		{
			statusResult = DisplayMgrCdd_RTE_TouchCddNotify(DeviceId , PowerState);
		}
	#endif	
	
	statusResult = E_OK;
	return statusResult;
}

#ifdef CDISPLAYCDD_ENABLE_AUTOMATICPOWERON
/*!***************************************************************************************************************** 
*   @brief      The function is used to perform the initial power on automatically if enabled
*   @param[in]  void
*   @return     void 
********************************************************************************************************************/
void DisplayMgrCdd_HandleInitilaPowerState(void)
{
	uint8 Device_No;
	uint8 Get_Device_No;
	Std_ReturnType statusResult = E_NOT_OK;

	for(Device_No = cDISPLAYCDD_DEVICE_0; Device_No < cDISPLAYCDD_MAX_DEVICE; Device_No++)
	{
		DisplayIfCdd_GetDeviceId(Device_No , &Get_Device_No);
	
		if(cDISPLAYCDD_DEVICE_0 != Device_No)
		{
			statusResult = DisplayIfCdd_SetState(Get_Device_No , InitialPowerOn[Device_No]);
				
			if(E_OK == statusResult)
			{
				IsDeviceInitilazed = (boolean)TRUE;
				
			}
		}
	}

}
#endif

#ifdef CDISPLAYCDD_ENABLEBISTTEST
/*!***************************************************************************************************************** 
*   @brief      The function is perorm the BIST test 
*   @param[in]  Device Id - device  For which the Bist test to be performed
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_BISTTest(EDisplayType DeviceId)
{
	Std_ReturnType BistTeststatus = E_NOT_OK;
	
	if(DeviceId < cDISPLAYCDD_MAX_DEVICE)
	{
		BistTeststatus = DisplayDrvCdd_BISTTest(DeviceId);
	}
	return BistTeststatus;
	
}

#endif

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION
/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_SetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength)
{
	Std_ReturnType RetVal;
	
	RetVal = DisplayIfCdd_SetGammaCorrection(GmaSetPtr, datalength);
	return RetVal;
}
/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayMgrCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus)
{
	DisplayIfCdd_GetGammaCorrectionStatus(GmaCrStatus);
}


/*!***************************************************************************************************************** 
*   @brief      To read the gamma settings to be applied from NvM
*   @param[in]  Handle - data handle
*   @param[in]  GmaCrData - Pointer to get the gamma correction data
*   @param[in]  length - length of data to be read
*   @return  Std_ReturnType E_NOT_OK - GammaSettings Read Operation is failed
*                           E_OK - GammaSettings Read Operation is successful
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_ReadGammaSettingsFromNvM(uint8 *Handle, uint8 *GmaCrData, uint16 length)
{
	Std_ReturnType RetVal = E_NOT_OK;
	if((NULL != Handle) && (NULL != GmaCrData) && (length > 0u))
	{
		#ifdef CDISPLAYCDD_READ_GAMMA_SETTING_FROM_NVM
			/* DiaplayCdd_ToDo: Use the correst API to read the gamma settings from NvM */
			RetVal = DisplayMgrCdd_RTE_ReadGammaSettingsFromNvM(Handle, GmaCrData,length);
		#endif
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


