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
#include "DisplayCdd_Cfg.h"

/*****************************************************************************
 *                                 Function Declarations                          *
 ******************************************************************************/
#if defined(CDISPLAYCDD_ENABLE_DISPLAY_TIANMA) && defined(CDISPLAYCDD_ENABLE_DISPLAY_POWERCONTROL)
 extern const SDisplayDB DisplayInfoDB[cDISPLAYCDD_MAX_DEVICE];
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_SHARP
 extern const SDisplaySharpDB DisplaySharpInfoDB[cDISPLAYCDD_MAX_DEVICE];
#endif

#ifdef CDISPLAYCDD_ENABLE_DISPLAY_TRULY
 extern const SDisplayTrulyDB DisplayTrulyInfoDB[cDISPLAYCDD_MAX_DEVICE];
#endif

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_Init(void);

/*!***************************************************************************************************************** 
*   @brief      The function de-initialize the displayIfCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_DeInit( void);

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
Std_ReturnType DisplayIfCdd_SetState(EDisplayType DeviceId,EDisplayPowerState NewState );

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
*   @brief      This function is used to notify the  power state is complete or fault is occured.
*   @param[in]  DeviceId - Device ID - 8inch or 12 inch 
*               EDisplayPowerState  - power state as POWERON  , NORMAL , POWEROFF , FAUTLTHANDLE       
*   @return  E_OK:           Succeed
*            E_NOT_OK:       Failed 
********************************************************************************************************************/
Std_ReturnType DispIfCdd_NotifyDisplayStatus(uint8 DeviceIndex, EDisplayPowerState CompletedPowerState);

void DisplayIfCdd_GetDeviceId(uint8 Index , uint8 *GetDeviceIdNo);

#ifdef CDISPLAYCDD_ENABLE_GAMMA_CORRECTION

/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_SetGammaCorrection(uint8 *GmaSetPtr, uint8 datalength);
/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayIfCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *GmaCrStatus);

/*!***************************************************************************************************************** 
*   @brief      To request the DisplayMgrCdd to read the gamma settings to be applied from NvM
*   @param[in]  Handle - data handle
*   @param[in]  GmaCrData - Pointer to get the gamma correction data
*   @param[in]  length - length of data to be read
*   @return  Std_ReturnType E_NOT_OK - GammaSettings Read Operation is failed
*                           E_OK - GammaSettings Read Operation is successful
********************************************************************************************************************/
Std_ReturnType DisplayIfCdd_ReadGammaSettingsFromNvM(uint8 *Handle, uint8 *GmaCrData, uint16 length);
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
 
#endif/* DISPLAYIFCDD_H */



