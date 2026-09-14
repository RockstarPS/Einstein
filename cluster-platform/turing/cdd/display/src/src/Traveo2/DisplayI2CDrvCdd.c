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
/*****************************************************************************
 *                                 Include Files                              *
 ******************************************************************************/

#include "DisplayCdd_Cfg.h"

#define CDisplayCdd_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>
/*! To store the data transmitted over I2c */
static uint8 I2c_TxBuffer[GMA_WRITE_BUFF_SIZE];

static uint8 I2CTrigerDeviceId;

#define CDisplayCdd_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <CDisplayCdd_MemMap.h>


#define CDisplayCdd_START_SEC_CODE
#include <CDisplayCdd_MemMap.h>
/*!***************************************************************************************************************** 
*   @brief      To pack the datas to be transferred over I2c and to trigger the transmission.
*   @param[in]  RegAddr - Register Address on which data to be written
*   @param[out]  I2c_TxBufferPtr - Pointer having the Data to be written
*   @param[in]  TxLength - Number of data bytes to be transferred after register address
*   @return  Std_ReturnType E_NOT_OK - Failure in triggering Data Transmission
*                           E_OK - Data Transmission is triggered successfully
********************************************************************************************************************/
Std_ReturnType DisplayDrvCdd_I2cWrite(uint8 RegAddr, uint8 *I2c_TxBufferPtr, uint8 TxLength , uint8 TriggeredDevice)
{
	Std_ReturnType DisplayI2C_RetVal = E_NOT_OK;
	uint8 DataLength;
	uint8 index;
	
	if((NULL != I2c_TxBufferPtr) && (TxLength > 0u))
	{
		/* Copy register address */
		I2c_TxBuffer[0] = RegAddr;
		DataLength = TxLength + 1u;
		
		/* Copy register data */
		for(index = 0u; index < TxLength; index++)
		{
			I2c_TxBuffer[index + 1U] = *(I2c_TxBufferPtr + index );
		}
		
		I2CTrigerDeviceId = TriggeredDevice;

		DisplayI2C_RetVal = DisplayDrvCdd_I2C_Write(I2c_TxBuffer, DataLength);
    }
	return DisplayI2C_RetVal;	
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
	if(I2CTrigerDeviceId < cDISPLAYCDD_MAX_DEVICE)
	{
		//Future Purpose -(void)DisplayCdd_I2CCallback[I2CTrigerDeviceId].Drv_I2CCallback();
	}
	
	 I2CTrigerDeviceId = 0;
}

#define CDisplayCdd_STOP_SEC_CODE
#include <CDisplayCdd_MemMap.h>

/*DISPLAYI2C_DRVCDD_C*/
/*----------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 03/Jan/2025
By                : kmadhuso
Traceability      : JIRA # REN31759-24422
Change Description: I2C API access moved out to cfg file, for compatibility with
                    any I2C Version
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 04/Dec/2024
By                : vvijaya5
Traceability      : JIRA # RE29398-649
Change Description: Aligning to the latest I2C Driver.
-------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Date              : 17/Jul/2023
By                : vvijaya5
Traceability      : RTC #
Change Description: Initial version
-------------------------------------------------------------------------------*/
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
/*---------------------------------------------------------------------------------------
Date              : 27/Jan/2026
By                : apawar2
Traceability      : AU29610-212553
Change Description: Compiler warning fix
-----------------------------------------------------------------------------------------*/

