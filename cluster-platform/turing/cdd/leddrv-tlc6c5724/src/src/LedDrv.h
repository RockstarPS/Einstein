/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  LedDrv.h                                             *
*  Module Short Name :  leddrv-tlc6c5724                                     *
*  VOBName           :                                                       *
*  Author            : sdv                                                   *
*  Description       : This file contains external APIs for LedDrv Module    *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang                                                  *
* Target Hardware  :  Independent                                            *
*                                                                            *
******************************************************************************/
#ifndef LEDDRV_H
#define LEDDRV_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "LedDrv_Cfg.h"
#include "LedDrv_Types.h"


/*============================================================================
**
** Function Name    :   LedDrv_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global 
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern void LedDrv_Init(void);

/*============================================================================
**
** Function Name    :   LedDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the oS.
**                      This function process the requested function of Error
**                      clear, Reset, FC-BC-DC write, GS write and SID read of
**                      LedDrv through Spi.
**
** Invocation       :   Os Scheduling.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern void LedDrv_MainFunction(void);

/*============================================================================
**
** Function Name    :   LedDrv_WriteChannel
**
** Visibility       :   Public
**
** Description      :   This function turn/off the requested Led Channel.
**
** Invocation       :   Application
**
** Inputs           :   LedDrv_LedChannelType ChannelId - Led Channel Id.
**                      boolean OutputSignal - Signal type ON/OFF (0/1)
**
** Outputs          :   E_OK - Success
**                      E_NOT_OK - Failure
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType LedDrv_WriteChannel(LedDrv_LedChannelType ChannelId, boolean OutputSignal);

/*============================================================================
**
** Function Name    :   LedDrv_SetBrightness
**
** Visibility       :   Public
**
** Description      :   The function sets the brightness and Current for the 
**                      requested Led Channel.
**
** Invocation       :   Application
**
** Inputs           :   LedDrv_LedChannelType ChannelId - Led Channel Id.
**                      uint16 BrightnessValue - Brightness Value
**                      uint16 CurrentValue - Current Value
**
** Outputs          :   E_OK - Success
**                      E_NOT_OK - Failure
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType LedDrv_SetBrightness(LedDrv_LedChannelType ChannelId, uint16 BrightnessValue, uint16 CurrentValue);

/*============================================================================
**
** Function Name    :   SpiApp_McuMcspiSeq2EndNotification
**
** Visibility       :   Public
**
** Description      :   Callback function for SPI sequence end.
**
** Invocation       :   I2C
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void LedDrv_McspiJob2EndNotification(void);


#endif /* #ifndef LEDDRV_H */

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 21/Oct/2024
By                : sdv
Traceability      : 
Change Description: Initial Version 
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 19/Nov/2024
By                : sdv
Traceability      : Jira Id: https://visteon.atlassian.net/browse/PE4TI29141-4872
                    https://visteon.atlassian.net/browse/PE4TI29141-4873
Change Description: Phase 1 Implementation
-----------------------------------------------------------------------------------------*/

