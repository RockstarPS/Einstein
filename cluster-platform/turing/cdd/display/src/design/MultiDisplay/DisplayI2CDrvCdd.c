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
*    @file DisplayI2CDrvCdd.c
*    @ingroup DisplayCdd
*    @brief This file provides the Definitions of the isplay I2C Drv APIs, which can be used to transfer datas
********************************************************************************************************************/
 #define DISPLAYI2CDRVCDD_C
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/

#include "DisplayCdd_Cfg.h"


/*! To store the data transmitted over I2c */
static uint8 I2c_TxBuffer[GMA_WRITE_BUFF_SIZE];

static uint8 I2CTrigerDeviceId;

/*Mutli Display Support implementation */
typedef void (* TDrv_Call_I2CCallback)(void);
typedef struct 
{
    TDrv_Call_I2CCallback Drv_I2CCallback;
}CDisplayDrvCddI2CCallbackCall;
static const CDisplayDrvCddI2CCallbackCall DisplayCdd_I2CCallback[cDISPLAYCDD_MAX_DEVICE] = {DISPLAYSHARPCDD_I2CCallback};

/*!***************************************************************************************************************** 
*   @brief      To pack the datas to be transferred over I2c and to trigger the transmission.
*   @param[in]  RegAddr - Register Address on which data to be written
*   @param[out]  I2c_TxBufferPtr - Pointer having the Data to be written
*   @param[in]  TxLength - Number of data bytes to be transferred after register address
*   @return  Std_ReturnType E_NOT_OK - Failure in triggering Data Transmission
*                           E_OK - Data Transmission is triggered successfully
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_I2cWrite(uint8 RegAddr, uint8 *I2c_TxBufferPtr, uint8 TxLength , uint8 DrvI2cChannelId , uint8 DrvI2cSeqId , uint8 TriggeredDevice)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 I2cChannelId, I2cSeqId, DataLength;
	uint8 index;
	
	if((NULL != I2c_TxBufferPtr) && (TxLength > 0u))
	{
		/* Copy register address */
		I2c_TxBuffer[0] = RegAddr;
		DataLength = TxLength + 1u;
		
		/* Copy register data */
		for(index = 0u; index < TxLength; index++)
		{
			I2c_TxBuffer[index+1u] = (*(I2c_TxBufferPtr + index));
		}
		
		
		I2CTrigerDeviceId = TriggeredDevice;
		
		I2cChannelId = DrvI2cChannelId;
		I2cSeqId     = DrvI2cSeqId;

		RetVal = I2c_SetupEB(I2cChannelId, I2c_TxBuffer, NULL, DataLength);
		
		if(E_OK == RetVal)
		{
			RetVal = I2c_AsyncTransmit(I2cSeqId);
		}
    }
	return RetVal;	
}

/*!***************************************************************************************************************** 
*   @brief      Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqEndCallback(void)
{
	/*For future purpose */
}

/*!***************************************************************************************************************** 
*   @brief      Error Callback notification function from I2cDrv for the previously triggered sequence
********************************************************************************************************************/
void DisplayDrvCdd_I2cSeqErrorCallback(void)
{
	
	(void)DisplayCdd_I2CCallback[2].Drv_I2CCallback();
	
	 I2CTrigerDeviceId = 0;
}

/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 1/feb/2021
By                : nirajan
Traceability      : RTC #
Change Description: Initial Version
-------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 2/Feb/2020
By                : nrajaman
Traceability      : RTC # 1199099
Change Description: Updated to support multi display during Run time
-----------------------------------------------------------------------------------------*/

