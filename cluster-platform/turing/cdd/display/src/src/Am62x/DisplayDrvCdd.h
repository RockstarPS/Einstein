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
*    @file DisplayDrvCdd.h
*    @ingroup DisplayCdd
*    @brief This file provides the declaration of the DisplayDrvCdd APIs. This header file should be included by other  
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
*   @return  void
********************************************************************************************************************/ 
void DisplayDrvCdd_Init(uint8 Device_No);

/*!***************************************************************************************************************** 
*   @brief      The function get triggered by DisplayIfCdd and it does start the activation sequence of display
*   @param[in]  void
*   @return  void
********************************************************************************************************************/
void DisplayDrvCdd_DeInit(uint8 Device_No);


/*!***************************************************************************************************************** 
*   @brief       This function is used to perform power handle and Fault Monitor
*   @param[in]   None
*   @return      None
********************************************************************************************************************/
void DisplayDrvCdd_MainFunction(uint8 Device_No);

/*!***************************************************************************************************************** 
*   @brief      The function is used to set the new power state for the particular device 
*   @param[in]  DeviceIndex - Repective Device Index
*   @param[in]  NewPowerState - Next power state
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_SetState( EDisplayType DeviceId, EDisplayPowerState NewPowerState);

/*!***************************************************************************************************************** 
*   @brief       
*   @param[in]  
*   @param[in]  
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success
********************************************************************************************************************/
void DisplayDetectI2CMethod(void);

/*!***************************************************************************************************************** 
*   @brief      The function is to perform the BIST test 
*   @param[in]  Device Id - For which the Bist test to be performed
*   @param[in]  BistPatternType - Pattern Identifier
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_BistTest_Start(EDisplayType DeviceId, EBistPatternType BistPatternType, uint8 PatternHoldTime);

/*!***************************************************************************************************************** 
*   @brief      The function is to stop the BIST test 
*   @param[in]  Device Id - For which the Bist test to be disabled
*   @return  Std_ReturnType E_NOT_OK - Failed
*                           E_OK - Success 
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_BistTest_Stop(EDisplayType DeviceId);

Std_ReturnType DisplayDrvCdd_I2cWrite(uint8 RegAddr, uint8 *I2c_TxBufferPtr, uint8 TxLength , uint8 TriggeredDevice);

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
/*---------------------------------------------------------------------------------------
Date              : 11/11/2022
By                : agopi
Traceability      : RTC #REN31759-24956 
Change Description: Updated BISTTest Header From TianmaDrvFile
-----------------------------------------------------------------------------------------*/
#endif

