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
*    @file DisplayIfCdd.h
*    @ingroup DisplayCdd
*    @brief This file provides the declaration of the DisplayIfCdd APIs. This header file should be included by other  
*    modules that use these APIs.
********************************************************************************************************************/
#ifndef DISPLAYIFCDD_H
#define DISPLAYIFCDD_H

/*****************************************************************************
 *                                 Header Includes                          *
 ******************************************************************************/
#include "DisplayCdd_Types.h"
#include "Rte_Type.h"

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayIfCdd_Init(void);

/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayIfCdd_DeInit( void);

/*!***************************************************************************************************************** 
*   @brief       This function is used to monitor the fault and to execute power handle
*   @param[in]  
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed
********************************************************************************************************************/
void DisplayIfCdd_MainFunction(void);

/*!***************************************************************************************************************** 
*   @brief      The function is used to the new state to particular display
*   @param[in]  DeviceId - Device ID - 8inch or 12 inch 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_SetState(EDisplayType DeviceId, EDisplayPowerState NewState );

/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_GetDisplayStatus(EDisplayType DeviceId, EDisplayStatus *GetDeviceStatus , EDisplayPowerState *GetPresentPowerState );

/*!***************************************************************************************************************** 
*   @brief      This function is used to update the  power state is complete or fault is occured.
*   @param[in]  DeviceId - Device ID - 8inch or 12 inch 
*               EDisplayPowerState   - power state as POWERON  , NORMAL , POWEROFF , FAUTLTHANDLE
				DeviceStatus 		 - Display status Ready, Notready, PowerOF or FAULT
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
void DispIfCdd_UpdateDisplayStatus(uint8 DeviceIndex,EDisplayPowerState CompletedPowerState, EDisplayCddStatus Devicestatus);

/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime);

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_BistTest_Stop(EDisplayType DeviceId);

void DisplayIfCdd_UpdateIdentifiedDeviceStatus(EDisplayType IdentifiedDeviceID, boolean IdentifiedDevStatus);

void DisplayIfCdd_UpdateAutoDetect(sDisplayAutoDetect AutoDetect_strctPtr);
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
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 10/Nov/2021
By                : vkathir1
Traceability      : RTC #1487856
Change Description: Updated to support JDI display.
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 10/May/2022
By                : smohame5
Traceability      : RTC #1654608
Change Description: Hannstar driver implementation for display
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 21/Jan/2025
By                : kmadhuso
Traceability      : JIRA #REN31759-24956
Change Description: BIST Trigger and Stop interfaces added
-----------------------------------------------------------------------------------------*/
#endif/* DISPLAYIFCDD_H */



