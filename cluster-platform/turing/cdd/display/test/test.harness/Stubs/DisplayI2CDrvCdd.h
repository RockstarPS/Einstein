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
#ifndef DISPLAYI2CDRVCDD_H
#define DISPLAYI2CDRVCDD_H

#include "Rte_Type.h"
//#include <Std_Types.h>
/*******************************************************************************************************************
*  Function Declarations                                                                                             *
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_I2cWrite(uint8 RegAddr, uint8 *I2c_TxBufferPtr, uint8 TxLength, uint8 DrvI2cChannelId , uint8 DrvI2cSeqId, uint8 TriggeredDevice);

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/

#endif /* DISPLAYI2CDRVCDD_H */

