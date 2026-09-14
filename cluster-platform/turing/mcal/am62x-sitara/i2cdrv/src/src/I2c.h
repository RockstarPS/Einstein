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
 * @file        I2c.h
 * @details     <b>TI Mcal driver for i2c</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

#ifndef  I2C_H
#define  I2C_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "I2c_Types.h"
#include "I2c_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/



/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   I2c_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   I2c_ConfigType * ConfigPtr - Pointer to a configuration type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void I2c_Init(void);

/*============================================================================
**
** Function Name    :   I2c_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function is called to initialise the Global
**                      and Static variables of this module to initial/ default values.
**
** Invocation       :   Function could be called from interrupt level or from task level
**
** Inputs           :
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType I2c_DeInit(void);

/*============================================================================
**
** Function Name    :   I2c_SetupEB
**
** Visibility       :   Public
**
** Description      :   This function setsups the I2c External Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   I2c_ChannelType Channel: I2c sw channel number.
**                      I2c_DataType* DataBufferPtr: Data buffer for Tx/Rx.
**                      I2c_NumberOfDataType TxLength: Transmission Length.
**                      I2c_NumberOfDataType RxLength: Reception Length.
**                      uint8 SlaveAddress: Device Slave Address.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType I2c_SetupEB(I2c_ChannelType Channel, I2c_DataType* TxBufferPtr, I2c_DataType* RxBufferPtr, \
                         I2c_NumberOfDataType TxLength, I2c_NumberOfDataType RxLength, uint8 SlaveAddress);

/*============================================================================
**
** Function Name    :   I2c_AsyncTransmit
**
** Visibility       :   Public
**
** Description      :   This function triggers the asynchronous transmission.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :   I2c_SequenceType Sequence: The sequence number to be triggered.
**
** Outputs          :  E_OK: If tx/rx accepted.
**                     E_NOT_OK: If tx/rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
extern Std_ReturnType I2c_AsyncTransmit(I2c_SequenceType Sequence);
/*============================================================================
**
** Function Name    :   I2c_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending transmissions
**                      according to the priority.
**
** Invocation       :   Os Scheduleing.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void I2c_MainFunction(void);

/*============================================================================
**
** Function Name    :   I2c_TxRxIsroutine
**
** Visibility       :   Public
**
** Description      :   This ISR is invoked whenever a transmission complete
**                      or reception of a byte is done.
**
** Invocation       :   Interrupt.
**
** Inputs           :   uint8 I2c_unit_index: Hw Unit Index
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void I2c_TxRxIsroutine(uint8 HwUnitIndex);

/*============================================================================
**
** Function Name    :   I2c_Cancel
**
** Visibility       :   Public
**
** Description      :   This function cancels an already triggered sequence, if
**                      it is not taken for transmission (still queued).
**
** Invocation       :   Application.
**
** Inputs           :   I2c_SequenceType Sequence: Sequence ID.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
extern void I2c_Cancel(I2c_SequenceType Sequence );

/*============================================================================
**
** Function Name    :   I2c_GetSequenceResult
**
** Visibility       :   Public
**
** Description      :   This function returns the Sequence Result.
**
** Invocation       :   Application
**
** Inputs           :   I2c_SequenceType Sequence: Sequence ID.
**
** Outputs          :  I2c_SeqResultType
**                     I2C_SEQ_OK        : Sequence OK.
**                     I2C_SEQ_PENDING   : Sequence Pending.
**                     I2C_SEQ_QUEUED    : Sequence Queued.
**                     I2C_SEQ_NACK      : Sequence NACK.
**                     I2C_SEQ_FAILED    : Sequence Failed.
**                     I2C_SEQ_CANCELLED : Sequence Cancelled.
** Critical Section :
**
**==========================================================================*/
extern I2c_SeqResultType I2c_GetSequenceResult(I2c_SequenceType Sequence);

/*============================================================================
**
** Function Name    :   I2c_GetStatus
**
** Visibility       :   Public
**
** Description      :   This function returns the I2c driver status.
**
** Invocation       :   Application
**
** Inputs           :   void
**
** Outputs          :  I2C_UNINIT: If I2c not initialized.
**                     I2C_BUSY: If I2c line busy.
**                     I2C_IDLE: If I2c Idle.
**
** Critical Section :
**
**==========================================================================*/
extern I2c_StatusType I2c_GetStatus(uint8 HwUnitIndex);

/*============================================================================
**
** Function Name    : I2c_SyncTransmit
**
** Visibility       : Public
**
** Description      : This function performs synchronous I2C transmit and receive
**                    using polling logic. It blocks until the transfer is complete.
**
** Invocation       : Application
**
** Inputs           : I2c_SequenceType Sequence - Sequence/Channel ID
**
** Outputs          : E_OK: If transfer successful
**                    E_NOT_OK: If transfer failed
**
** Critical Section : Yes
**
**==========================================================================*/
Std_ReturnType I2c_SyncTransmit(I2c_SequenceType Sequence);

/*============================================================================
**
** Function Name    : I2c_FreeBus
**
** Visibility       : Public
**
** Description      : This function is called upon to provide the recovery 
**                      on bus slave bus.
**
** Invocation       : Application
**
** Inputs           : uint8 I2c_unit_index: Hw Unit Index
**
** Outputs          : E_OK: If transfer successful
**                    E_NOT_OK: If transfer failed
**
** Critical Section : Yes
**
**==========================================================================*/
extern Std_ReturnType I2c_FreeSlaveBus(uint8 hw_index);
/*============================================================================
**
** Function Name    :   I2C_GetStatusOfSDALine
**
** Visibility       :   Public
**
** Description      :   Checks whether the I2C bus is in a slave-stuck condition
**                      for the specified hardware instance.
**                      TRUE  = SDA is LOW while SCL is HIGH
**                      FALSE = No SDA-stuck-low condition detected
**
** Invocation       :   Can be called anytime after I2c_Init()
**
** Inputs           :   uint8 hw - I2C hardware instance number (0-based)
**
** Outputs          :   boolean
**
** Critical Section :   None
**
**==========================================================================*/
extern boolean I2C_GetStatusOfSDALine(uint8 hw);

extern Std_ReturnType I2c_Disable(uint8 HwUnitIndex);
extern Std_ReturnType I2c_Enable(uint8 HwUnitIndex);
#endif /* I2C_H */

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 13/Feb/2024
By                : eganesan
Traceability      : 
Change Description: I2c initial release
-----------------------------------------------------------------------------------------*/

