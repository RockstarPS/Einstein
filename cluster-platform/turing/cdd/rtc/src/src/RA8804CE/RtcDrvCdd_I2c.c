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
*  File Name         :  RtcDrvCdd_I2c.c                                          *
*  Module Short Name :  RTC                                                  *
*  Description       :  This file contains implementations of the Rtc Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/
#ifndef RTCI2CDRVCDD_C
#define RTCI2CDRVCDD_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "RtcDrvCdd_I2c.h"

/*****************************************************************************
*                            Functions Implementation                         *
******************************************************************************/

void RtcDrvCdd_i2cCbInit(I2c_CircularBuffer_t *pI2c_CB)
{
	pI2c_CB->u8BufferHead = pI2c_CB->u8BufferTail = 0;
}

/*!*****************************************************************************************************************
/// @brief  Write register values to Circular buffer for further processing
///
/// @param  RegAddr:		Start register address
///			u8Length:		Amount of registers to write in sequence
///			pValue: 		Pointer to the uint8 values with required registers values
///			pI2c_CB:		Pointer to Circular buffer

///
/// @return E_INVALID_ARG
/// 		E_OK
///         E_NOT_OK
********************************************************************************************************************/
Std_ReturnType RtcDrvCdd_i2cWriteRegisters(uint8 RegAddr, uint8 *pValues, uint8 u8Length, I2c_CircularBuffer_t *pI2c_CB)
{
	Std_ReturnType RetVal = E_NOT_OK;
	uint8 index;

	if (NULL == pI2c_CB)
    {
    	RetVal = E_INVALID_ARG;
    }
	else
	{
		if(pI2c_CB->u8BufferTail < I2C_CIRCULAR_BUFFER_SIZE)
		{
			/* Assign the first buffer element with starting register address */
			pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferTail][0] = RegAddr;

			/* Copy data to be written in registers*/
			for(index = 0u; index < u8Length; index++)
			{
				pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferTail][index + 1u] = (*(pValues + index));
			}
			pI2c_CB->u8Length[pI2c_CB->u8BufferTail] = u8Length + 1u;
			pI2c_CB->eSequenceType[pI2c_CB->u8BufferTail] = eRtcDrvCdd_I2cWrite;

			/* Shift tail to next or to 0 if reached the end of buffer */
			pI2c_CB->u8BufferTail++;
			pI2c_CB->u8BufferTail &= I2C_CIRCULAR_BUFFER_MASK;

			RetVal = E_OK;
		}
	}

	return RetVal;
}

/*!*****************************************************************************************************************
/// @brief  Read register values by adding write and read using Circular buffer
///			As soon as it's temporary workaround solution - registers to read are hard coded
/// @param  RegAddr:		Start register address RA8804CE_BTC_SEC or RA8804CE_BTC_TEMP
///			pI2c_CB:		Pointer to Circular buffer
///
/// @return E_INVALID_ARG
/// 		E_OK
///         E_NOT_OK
********************************************************************************************************************/
Std_ReturnType RtcDrvCdd_i2cReadRegisters(uint8 RegAddr, I2c_CircularBuffer_t *pI2c_CB)
{
	Std_ReturnType RetVal = E_NOT_OK;

	if (NULL == pI2c_CB)
    {
    	RetVal = E_INVALID_ARG;
    }
	else
	{
		if(pI2c_CB->u8BufferTail < I2C_CIRCULAR_BUFFER_SIZE)
		{
			/* Assign the first buffer element with starting register address */
			pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferTail][0] = RegAddr;
			pI2c_CB->u8Length[pI2c_CB->u8BufferTail] = 1;
			pI2c_CB->eSequenceType[pI2c_CB->u8BufferTail] = eRtcDrvCdd_I2cWrite;

			/* Shift tail to next or to 0 if reached the end of buffer */
			pI2c_CB->u8BufferTail++;
			pI2c_CB->u8BufferTail &= I2C_CIRCULAR_BUFFER_MASK;

			// Read registers to static buffers
			// This is only to check which registers has to be written.
			// Buffer will not be transmitted to I2C bus
			pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferTail][0] = RegAddr;
			pI2c_CB->eSequenceType[pI2c_CB->u8BufferTail] = eRtcDrvCdd_I2cRead;

			/* Shift tail to next or to 0 if reached the end of buffer */
			pI2c_CB->u8BufferTail++;
			pI2c_CB->u8BufferTail &= I2C_CIRCULAR_BUFFER_MASK;

			RetVal = E_OK;
		}
	}

	return RetVal;
}





/*!*****************************************************************************************************************
/// @brief  Check if Circular Buffer has not transmitted messages
///
/// @param  I2c_CB:			Pointer to Circular buffer to be checked structure
///
/// @return E_INVALID_ARG
/// 		E_OK			Buffer is empty
///         E_NOT_OK		Buffer is not empty
********************************************************************************************************************/

Std_ReturnType RtcDrvCdd_i2cCheckIfBufferEmpty(I2c_CircularBuffer_t *pI2c_CB)
{
	Std_ReturnType RetVal = E_NOT_OK;

	if (NULL == pI2c_CB)
    {
    	RetVal = E_INVALID_ARG;
    }
	else
	{
		if ( pI2c_CB->u8BufferHead == pI2c_CB->u8BufferTail )
		{
			RetVal = E_OK;
		}
	}

	return RetVal;
}

/*!*****************************************************************************************************************
/// @brief  Transmit next message to I2C bus
///
/// @param  I2c_CB:			Pointer to Circular buffer to be checked structure
///
/// @return E_INVALID_ARG
/// 		E_OK
///         E_NOT_OK
********************************************************************************************************************/

Std_ReturnType RtcDrvCdd_i2cProcessCircularBuffer(I2c_CircularBuffer_t *pI2c_CB)
{
	I2c_StatusType I2cStatus = I2C_UNINIT;
	Std_ReturnType RetVal = E_NOT_OK;

	if (NULL == pI2c_CB)
    {
    	RetVal = E_INVALID_ARG;
    }
	else
	{
		I2cStatus = I2c_GetStatus(RA8804CE_I2C_CHANNEL_ID);
		if (I2C_IDLE == I2cStatus && pI2c_CB->u8BufferHead < I2C_CIRCULAR_BUFFER_SIZE)   // Check if driver is initialized and ready
		{
			if(pI2c_CB->eSequenceType[pI2c_CB->u8BufferHead] == eRtcDrvCdd_I2cWrite)
			{
				RetVal = I2c_SetupEB(RA8804CE_I2C_CHANNEL_ID, pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferHead], NULL, pI2c_CB->u8Length[pI2c_CB->u8BufferHead], NULL, RA8804CE_I2C_DEVICE_ADDRESS);
			}
			else
			{
				if (pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferHead][0] == RA8804CE_BTC_SEC)
				{
					RetVal = I2c_SetupEB(RA8804CE_I2C_CHANNEL_ID, pI2c_CB->I2c_TxBuffer[pI2c_CB->u8BufferHead], pI2c_CB->I2c_RxBufferBTC, 1u , RA8804CE_BTC_REGISTERS_LENGTH, RA8804CE_I2C_DEVICE_ADDRESS);
				}
			}
			// Execute data exchange
			if(E_OK == RetVal)
			{
				RetVal = I2c_AsyncTransmit(RA8804CE_I2C_CHANNEL_ID);
				if(E_OK == RetVal)
				{
					/* Shift head to next or to 0 if reached the end of buffer */
					pI2c_CB->u8BufferHead++;
					pI2c_CB->u8BufferHead &= I2C_CIRCULAR_BUFFER_MASK;
				}
			}
		}
	}

	return RetVal;
}

#endif /* RTCI2CDRVCDD_C */

