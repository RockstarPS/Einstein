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
*    @file DisplayMgrCdd.h
*    @ingroup DisplayCdd
*    @brief This file provides the declaration of the DisplayMgrCdd APIs. This header file should be included by other  
*    modules that use these APIs.
********************************************************************************************************************/
#ifndef DISPLAYMGRCDD_H
#define DISPLAYMGRCDD_H

#include "DisplayCdd_Types.h"
#include "DisplayCdd_Cfg.h"
#include "Rte_Type.h"
//#include "Rte_EcuAppM_Type.h"
/*******************************************************************************************************************
*  Function Declarations                                                                                             *
********************************************************************************************************************/


/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayMgrCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
 void DisplayMgrCdd_Init(void);

/*!*****************************************************************************************************************
*   @brief      The function de-initialize the displayMgrCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayMgrCdd_DeInit(void);

/***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayMgrCdd_MainFunction(void);

/*!***************************************************************************************************************** 
*   @brief      The function is used to the new state to particular display
*   @param[in]  DeviceId - Device ID - 8inch or 12 inch 
*               NewState  - New state as POWERON , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DisplayMgrCdd_SetState(EDisplayType DeviceId,EDisplayPowerState NewState );

/*!***************************************************************************************************************** 
*   @brief      The function gets the current status of the display
*   @param[in]  EDisplayType this parameter specifies which display
*   @param[out]  EDisplayCddStatus this parameter is used to get the status
*   @param[out]  EDisplayPowerState this parameter is used to get the present power state
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispMgrCdd_GetDisplayStatus(EDisplayType DeviceId, EDisplayCddStatus *DeviceStatus , EDisplayPowerState *GetPresentPowerState );

/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) DisplayMgrCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime);

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
FUNC(Std_ReturnType, DisplayCdd_CODE) DisplayMgrCdd_BistTest_Stop(EDisplayType DeviceId);
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
Change Description: Updated to support single display and Multiple display.
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
#endif /* DISPLAYMGRCDD_H */

