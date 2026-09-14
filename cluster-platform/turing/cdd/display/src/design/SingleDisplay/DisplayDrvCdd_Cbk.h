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
*    @file DisplayDrvCdd_Cbk.h
*    @ingroup DisplayCdd
*    @brief This file provides the declaration of callback APIs which would be triggered from other modules. 
*			This header file can be included by other modules that invoke these APIs.
********************************************************************************************************************/
#ifndef DISPLAYDRVCDD_CBK_H
#define DISPLAYDRVCDD_CBK_H

/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/

/*!***************************************************************************************************************** 
*   @brief      Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqEndCallback(void);

/*!***************************************************************************************************************** 
*   @brief      Error Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqErrorCallback(void);


/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 02/Oct/2020
By                : asivalin
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
#endif

