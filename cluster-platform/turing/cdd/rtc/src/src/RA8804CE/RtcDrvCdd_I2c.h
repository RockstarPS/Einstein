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
*  File Name         :  RtcDrvCdd_I2c.h                                          *
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
#ifndef RTCDRVCDD_I2C_H
#define RTCDRVCDD_I2C_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "I2c.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define RA8804CE_I2C_DEVICE_ADDRESS     	(0x32)
#define RA8804CE_I2C_CHANNEL_ID            	(2U)

#define RA8804CE_BTC_REGISTERS_LENGTH		(0x10)
#define MAX_RX_BUFFER_SIZE					(0x08)
#define REGISTER_LENGTH						(0x01)
#define I2C_CIRCULAR_BUFFER_SIZE			(0x10)  //Should be number ^2
#define I2C_CIRCULAR_BUFFER_MASK			(I2C_CIRCULAR_BUFFER_SIZE - 1)

#define RA8804CE_BTC_SEC					(0x00)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    eRtcDrvCdd_I2cWrite,
	eRtcDrvCdd_I2cRead,
}eRtcDrvCdd_I2cSequence;

typedef struct
{
	uint8 I2c_TxBuffer[I2C_CIRCULAR_BUFFER_SIZE][MAX_RX_BUFFER_SIZE];
	uint8 I2c_RxBufferBTC[RA8804CE_BTC_REGISTERS_LENGTH];
	uint8 I2c_RxBackup;
	uint8 u8Length[I2C_CIRCULAR_BUFFER_SIZE];
	eRtcDrvCdd_I2cSequence eSequenceType[I2C_CIRCULAR_BUFFER_SIZE];
	uint8 u8BufferHead;       // current head
	uint8 u8BufferTail;       // current tail
}I2c_CircularBuffer_t;

/*****************************************************************************
*                            Functions Declarations                         *
******************************************************************************/

void RtcDrvCdd_i2cCbInit(I2c_CircularBuffer_t *pI2c_CB);
void RtcDrvCdd_i2cCopyBuffer(uint8 *pBuffer);
Std_ReturnType RtcDrvCdd_i2cWriteRegisters(uint8 RegAddr, uint8 *pValues, uint8 u8Length, I2c_CircularBuffer_t *pI2c_CB);
Std_ReturnType RtcDrvCdd_i2cReadRegisters(uint8 RegAddr, I2c_CircularBuffer_t *pI2c_CB);
Std_ReturnType RtcDrvCdd_i2cCheckIfBufferEmpty(I2c_CircularBuffer_t *pI2c_CB);
Std_ReturnType RtcDrvCdd_i2cProcessCircularBuffer(I2c_CircularBuffer_t *pI2c_CB);



#endif /* RTCDRVCDD_I2C_H */
