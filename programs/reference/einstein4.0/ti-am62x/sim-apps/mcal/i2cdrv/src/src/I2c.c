/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        I2c.c
 * @details     <b>TI Mcal driver for i2c</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  I2C_C
#define  I2C_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "I2c.h"

#define I2C_SEC_CODE_START
#define I2C_CORE_CONST_SEC_START
#define I2C_CORE_DATA_SEC_START
#define I2C_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
******************************************************************************/

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void I2c_Init(void)
{
}

Std_ReturnType I2c_DeInit(void)
{
    return E_OK;
}

Std_ReturnType I2c_SetupEB(I2c_ChannelType Channel, I2c_DataType* TxBufferPtr, I2c_DataType* RxBufferPtr, \
                  I2c_NumberOfDataType TxLength, I2c_NumberOfDataType RxLength, uint8 SlaveAddress)
{
    return E_OK;
}

void I2c_MainFunction(void)
{
}

Std_ReturnType I2c_AsyncTransmit(I2c_SequenceType Sequence)
{
    return E_OK;
}

void I2c_TxRxIsroutine(uint8 HwUnitIndex)
{
}

I2c_StatusType I2c_GetStatus(uint8 HwUnitIndex)
{
    return I2C_IDLE;
}

I2c_SeqResultType I2c_GetSequenceResult(I2c_SequenceType Sequence)
{
    return I2C_SEQ_OK;
}

void I2c_Cancel(I2c_SequenceType Sequence)
{
}

#define I2C_SEC_CODE_STOP
#define I2C_CORE_CONST_SEC_END
#define I2C_CORE_DATA_SEC_END
#define I2C_CORE_BSS_SEC_END

#include "MemMap.h"

#endif

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 13/Feb/2024
By                : eganesan
Traceability      : 
Change Description: I2c initial release
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 07/Mar/2024
By                : eganesan
Traceability      : 
Change Description: I2c call back update release
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 22/Aug/2024
By                : eganesan
Traceability      : 
Change Description: I2c Multi Slave Handling update release
-----------------------------------------------------------------------------------------*/
