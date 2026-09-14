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
*    @file DisplayDrvCdd_Sharp.h
*    @ingroup DisplayCdd
*    @brief This file provides the declaration of the DisplayDrvCdd_Sharp APIs. This header file should be included by other  
*    modules that use these APIs.
********************************************************************************************************************/
#ifndef DISPLAYDRVCDD_H
#define DISPLAYDRVCDD_H

/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/

/*!***************************************************************************************************************** 
*   @brief      The function initialize the displaydrvCdd layer
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/ 
Std_ReturnType DisplayDrvCdd_Init(void);

/*!***************************************************************************************************************** 
*   @brief      The function get triggered by DisplayIfCdd and it does start the activation sequence of display
*   @param[in]  void
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_DeInit(void);


/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_MainFunction(void);

/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetState(uint8 DeviceIndex , EDisplayPowerState NewPowerState);

/*!***************************************************************************************************************** 
*   @brief      To enter into auto detect mode if system is in MEET mode
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_IsDeviceIdentified(void);

/*!***************************************************************************************************************** 
*   @brief      To trigger the gamma correction operation
*   @param[in]  GmaSetPtr - Pointer having the gamma correction settings to be updated
*   @param[in]  datalength - Lenght of the data available in buffer pointer
*   @return  Std_ReturnType E_NOT_OK - Request not accepted
*                           E_OK - Request accepted
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetGammaCorrection(uint8 *DrvGmaSetPtr, uint8 Drvdatalength);

/*!***************************************************************************************************************** 
*   @brief      To get the current status of triggered gamma correction operation
*   @param[out]  GmaCrStatus - Pointer to update the gamma correction status
********************************************************************************************************************/
void DisplayDrvCdd_GetGammaCorrectionStatus(EGammaCorrectionStatus *DrvGmaCrStatus);

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 22/June/2020
By                : nrajaman
Traceability      : RTC # 835355
Change Description: Added Power and SPI sequence for 12 inch tianma display. 
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/
#endif

