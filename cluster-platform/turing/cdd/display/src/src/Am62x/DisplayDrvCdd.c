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
*    @file DisplayDrvCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the DisplayDrvCdd APIs. This header file should be included by other  
*    modules that use these APIs this file interacts with driver layer
********************************************************************************************************************/

/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/
#include "DisplayCdd_Types.h"
#include "DisplayCdd_Cfg.h"
#include "DisplayIfCdd.h"
#include "DisplayDrvCdd.h"

static Std_ReturnType DisplayDrvI2CSendDetect(DisplayCheckConfigType lcdConfig);
/*=====================================================================================================================
  CONSTANTS & TYPES
=====================================================================================================================*/
#define CDisplayCdd_START_SEC_CONST_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

static const CDisplayDrvCddInitCall DisplayCdd_Init[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYCDD_INIT}; 
static const CDisplayDrvCddDeInitCall DisplayCdd_DeInit[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYCDD_DEINIT}; 
static const CDisplayDrvCddMainCall DisplayCdd_Main[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYCDD_MAIN};
const DisplayCheckConfigType DisplayCheckConfig[CHECK_DISPLAY_COUNT]= {CDISPLAYCDD_DISPLAY_CHECK_CONFIG_DB };

#define CDisplayCdd_STOP_SEC_CONST_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

#define CDisplayCdd_START_SEC_VAR_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

static DetectionStates displayCheckState = SEND_COMMAND;


#define CDisplayCdd_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>

#define CDisplayCdd_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h> 
static uint8 currentDisplayCheck;
static uint8 DispI2cRetryCount;

#define CDisplayCdd_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>
/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  void
********************************************************************************************************************/ 
#define CDisplayCdd_START_SEC_CODE
#include <CDisplayCdd_MemMap.h>

void DisplayDrvCdd_Init(uint8 Device_No)
{
     DispI2cRetryCount = cDISPLAY_I2C_RETRYCOUNT;
     currentDisplayCheck = cDISPLAYCDD_DEVICE_0;

    /* Initialize the Device mapped under Device No's Index */
    if(cDISPLAYCDD_MAX_DEVICE > Device_No)
    {
        if(DisplayCdd_Init[Device_No].Drv_Init != DISP_NULL)
        {
            DisplayCdd_Init[Device_No].Drv_Init(Device_No);
        }
    }
}

/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/ 
void DisplayDrvCdd_DeInit(uint8 Device_No)
{
    /* DeInitialize the Device mapped under Device No's Index */
    if(cDISPLAYCDD_MAX_DEVICE > Device_No)
    {
        if(DisplayCdd_DeInit[Device_No].Drv_DeInit != DISP_NULL)
        {
            DisplayCdd_DeInit[Device_No].Drv_DeInit(Device_No);
        }
    }
}

/*!***************************************************************************************************************** 
*   @brief       Periodic function  is used to perform power handling and fault monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_MainFunction(uint8 Device_No)
{
    if(cDISPLAYCDD_MAX_DEVICE > Device_No)
	{
        DisplayCdd_Main[Device_No].Drv_Main(Device_No);
    }
}

/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetState(EDisplayType DeviceId, EDisplayPowerState NewPowerState)
{
	Std_ReturnType ret = E_NOT_OK;
    if(cDISPLAYCDD_MAX_DEVICE > DeviceId)
    {
        ret= DisplayCddCfg_SetState(DeviceId,NewPowerState);
    }	
	return ret;
}

/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @param[in]  PatternHoldTime - Pattern Hold Time
*   @return     Std_ReturnType E_NOT_OK - Failed
*                              E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime)
{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayCddCfg_BistTest_Start(DeviceId, BistPatternType, PatternHoldTime);

    return BistResult;  
}

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return     Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_BistTest_Stop(EDisplayType DeviceId)
{
    Std_ReturnType BistResult = E_NOT_OK;

    BistResult = DisplayCddCfg_BistTest_Stop(DeviceId);

    return BistResult;
}

void DisplayDetectI2CMethod(void)
{
	uint8 displayi2cstatus    = E_NOT_OK;

	if(currentDisplayCheck < cDISPLAYCDD_MAX_DEVICE)
	{
		if(DispI2cRetryCount != 0U)
		{
			displayi2cstatus = DisplayDrvI2CSendDetect(DisplayCheckConfig[currentDisplayCheck]);
            
			if(((uint8)E_OK == displayi2cstatus) && (cDISPLAYCDD_MAX_DEVICE > DisplayCheckConfig[currentDisplayCheck].displayType))
			{
                //Update Identified device detail
                DisplayIfCdd_UpdateIdentifiedDeviceStatus(DisplayCheckConfig[currentDisplayCheck].displayType, TRUE);

                //current display check identified Display and Write data to NVM.
                if(DisplayInitCheck.displayWriteNVMDisplayType!=DISP_NULL)
                {
                    (void)DisplayInitCheck.displayWriteNVMDisplayType(DisplayCheckConfig[currentDisplayCheck].NvmValue);
                }

                //init the the respective display
                (void)DisplayDrvCdd_Init(DisplayCheckConfig[currentDisplayCheck].displayType);
            }
			else
			{
				//Try once again
				//here is possibility I2C to be not ready on first loop, else enter into autodetect i2cmode only if i2c is ready
				DispI2cRetryCount --;
				displayCheckState = SEND_COMMAND;
			}
		}
		else
		{
			currentDisplayCheck ++;
		}
	}
    else
    {
     //   retry count expired device not identified. need to identify safety action
    }
}

static Std_ReturnType DisplayDrvI2CSendDetect(DisplayCheckConfigType lcdConfig)
{
    Std_ReturnType retL = E_OK;

    return retL;
}

#define CDisplayCdd_STOP_SEC_CODE
#include <CDisplayCdd_MemMap.h>

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 17/Jul/2023
By                : vvijaya5
Traceability      : RTC #
Change Description: Review comment fix and memmap addition
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 21/Jan/2025
By                : kmadhuso
Traceability      : RTC #
Change Description: Adapatation to new I2C driver on I2c_GetStatus API 
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 21/Jan/2025
By                : kmadhuso
Traceability      : JIRA #REN31759-24956
Change Description: BIST Trigger and Stop interfaces added
-------------------------------------------------------------------------------*/
