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
#include "Det.h"
#include "Dio.h"

#define I2C_SEC_CODE_START
#define I2C_CORE_CONST_SEC_START
#define I2C_CORE_DATA_SEC_START
#define I2C_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define I2C_NO_PRIORITY              0xFFU
#define I2C_SET_BIT                  0x01U
#define I2C_CLEAR_BIT                0x00U
#define I2C_INTR_ERROR               0x101UL

#define I2C_INTR_NACK              0x0002u /* No acknowledge Interrupt */
#define I2C_INTR_AL                0x0001u /* Arbitration loss Interrupt */
#define I2C_INTR_AERR              0x0080u /* Bus Access Error Interrupt */
#define I2C_INTR_TX                0x0010u /* Transmit Ready Interrupt */
#define I2C_INTR_RX                0x0008u /* Receive Ready Interrupt */
#define I2C_INTR_ARDY              0x0004u
#define I2C_INTR_XUDF              0x0400u
#define I2C_INTR_XDR               0x4000U
#define I2C_INTR_RDR               0x2000U
#define I2C_INTR_BF                0x0100U
#define I2C_INTR_ROVR              (1U << 11)  /* Receive Overrun */



#define I2C_FIFO_SIZE              0x20u
#define I2C_HALF_FIFO_SIZE         0x10u
#define I2C_RX_LENGTH              0x16u
#define I2C_MAX_BUFSTAT_SIZE       0x40u

#define I2C_SYNC_TIMEOUT   (0x00FFFFFFU)   /* Large timeout for polling */
/* ========================== */
/* Error codes for DET report */
/* ========================== */
#define I2C_INT_ALL                 ((uint32) 0x7FFFU)

#define I2C_E_NACK          0x01U    /* Slave responded with NACK     */
#define I2C_E_AL            0x02U    /* Arbitration lost              */
#define I2C_E_TIMEOUT       0x03U    /* Timeout waiting for HW flag   */
#define I2C_E_SEQ_FAILED    0x04U
#define I2C_E_ROVR         0x05U     /* Receive overrun               */
#define I2C_E_AERR         0x06U
#define I2C_E_XUDF         ((uint8)0x07U)  /* Transmit underflow            */

// For testing/debugging
//#define I2C_DEBUG_STATS_ENABLED
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

// Used for debugging
#if I2C_DEBUG_STATS_ENABLED
typedef struct
{
    uint32 IsrEntryCount;          /* total times MasterInterrupt fired */
    uint32 StopCount;              /* times STOP path executed */
    uint32 ErrorCount;             /* times any errorOccurred=true */
    uint32 LastIntrStatus;         /* last IntrStatus seen */
    uint32 LastIntrRawStatus;      /* last IntrRawStatus seen */
    uint32 LastState;              /* last I2c_InternalState[] seen */
    uint32 AerrCount;              /* how many times AERR triggered */
    uint32 NackCount;              /* how many times NACK triggered */
    uint32 AlCount;                /* how many times Arbitration Lost triggered */
    uint32 RovrCount;              /* how many times ROVR triggered */
    uint32 LastSequence;           /* last Sequence index processed */
} I2c_DebugStatsType;

/* Global debug stats (per HW unit if needed) */
volatile I2c_DebugStatsType I2c_DebugStats[I2C_NUMBER_OF_HW_CHANNELS] = {0};
#endif 


typedef struct
{
    /* Tx Length */
    I2c_NumberOfDataType    TxLength; /*number of data transmitted*/
    /* Tx Data Index */
    I2c_NumberOfDataType    TxIndex;
    /* Rx Length */
    I2c_NumberOfDataType    RxLength;
    /* Rx Data Index */
    I2c_NumberOfDataType    RxIndex;
    /* Tx Buffer */
    I2c_DataType*           TxBuffer; /*8 bit data pointer */
    /* Rx Buffer */
    I2c_DataType*           RxBuffer; /*8 bit data pointer */
    /* Slave Address of the device. */
    uint8                 SlaveAddress;
    /* I2c Channel Result */
    I2c_SeqResultType       Result;
    /* Channel queued flag */
    boolean                 IsQueued;
    /* Repeat Start flag */
    boolean                 IsRepeatStart;

} I2c_ChannelInfoType;

typedef struct
{
    /*for transmission time expire*/
    uint16                TimeoutCount;
    /*sequence or channel both are same*/
    I2c_ChannelType         CurrentSeq;
    /*I2C status */
    I2c_StatusType          HwStatus;
    /*to get the current sequence*/
    uint8                 CurrentPriority;
    /*State set TRUE when stop triggered waiting to complete*/
    boolean                 IsStopWait;
} I2c_HwInfoType;

typedef struct
{
    /* I2c Channel Status */
    I2c_StatusType          Status[I2C_NUMBER_OF_HW_CHANNELS];
} I2c_DrvStatusType;

/* structure for maintaining the entire bus status */
typedef struct 
{
    /* busy timeout for MultiMaster where the i2c bus is busy from external Master */
    uint16               BusBusyTimeout;
    /* i2c network status */
    I2c_StatusType       WholeNetworkStatus;
}I2c_BusBusyStateType;

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
static I2c_StatusType          I2c_InternalState[I2C_NUMBER_OF_HW_CHANNELS];
static I2c_DrvStatusType       I2c_DrvStatus;
static I2c_ChannelInfoType     I2c_ChannelInfo[I2C_NUMBER_OF_SW_CHANNELS];
static I2c_HwInfoType          I2c_HwInfo[I2C_NUMBER_OF_HW_CHANNELS];
static I2c_BusBusyStateType    I2c_BusBusyState[I2C_NUMBER_OF_SW_CHANNELS];
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
static void     I2c_HwInit(uint8 I2c_unit_index);
static void     I2c_HwDeInit(I2c_RegisterPtrType I2c_unit);
static void     I2c_StartTransfer(I2c_SequenceType Sequence);
static void     I2C_SetDataRate(I2c_SequenceType Sequence);
static void     I2c_RepeatedStart(I2c_SequenceType Sequence);
static void     I2c_MasterTransferComplete(I2c_RegisterPtrType base, uint8 sequence);
static void     MasterInterrupt(uint8 HwUnitIndexVAr);
static void     I2c_FreeBus(uint8 hw_index, uint8 sequence);
static uint16   I2c_WriteFiFoArray(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size);
static uint16 I2c_XDRWriteFiFoArray(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size);
static void I2c_WriteFiFoWithoutCheck(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size);
static uint16   I2c_ReadFiFoArray(const volatile I2c_RegisterPtrType base, void *rxBuf, uint16 size);
static void I2c_Stop(I2c_RegisterPtrType Reg_pt);
static void I2c_StopWait(uint8 HwUnitIndexVAr);
static uint32 I2CDataCountGet(volatile I2c_RegisterPtrType base);
static uint16 I2C_GetBufferStatus(volatile I2c_RegisterPtrType base);
static void I2CDataCountSet(volatile I2c_RegisterPtrType base, uint8 Sequence);
static uint16 DiffCalculationFunction(uint16 StartValue, uint16 EndValue);
static void I2C_RxDataCountSet(volatile I2c_RegisterPtrType base, uint8 Sequence);
static uint16 RxDiffCalculationFunction(uint16 StartValue, uint16 EndValue);
static void  I2c_DisableSequence(uint8 hw_index, uint8 sequence);
static void  I2c_EnableSequence(uint8 hw_index, uint8 sequence);
static void I2CControllerIntEnableEx(I2c_RegisterPtrType baseAddr, uint32 intFlag);
static void I2CControllerIntDisableEx(I2c_RegisterPtrType baseAddr, uint32 intFlag);
static void I2CControllerIntClearEx(I2c_RegisterPtrType baseAddr, uint32 intFlag);
static void I2c_ReadFiFoWithoutCheck(const volatile I2c_RegisterPtrType base, void *rxBuf, uint16 size);
static uint16 I2C_RxGetBufferStatus(volatile I2c_RegisterPtrType base);
static uint8 I2c_FindAnySequenceForHw(uint8 hw);
static void I2c_TrySlaveBusRecovery(uint8 hwIndex);
static I2c_StatusType I2c_PrepareReadTransfer(I2c_RegisterPtrType I2cUnitPtr, uint8 HwUnitIndex, I2c_SequenceType Sequence);

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
void I2c_Init  (void)
{
    uint8 hw_channel;
    uint8 sw_channel;

    for(hw_channel = 0; hw_channel < I2C_NUMBER_OF_HW_CHANNELS; hw_channel++) 
    {
        I2c_HwInfo[hw_channel].CurrentPriority = I2C_NO_PRIORITY;
        I2c_HwInfo[hw_channel].CurrentSeq = 0u;
        I2c_HwInfo[hw_channel].TimeoutCount = 0x0000u;
        I2c_HwInfo[hw_channel].IsStopWait = FALSE;
        I2c_HwInit(hw_channel);
        I2c_HwInfo[hw_channel].HwStatus = I2C_IDLE;
        I2c_InternalState[hw_channel] = I2C_IDLE;
        I2c_DrvStatus.Status[hw_channel] = I2C_IDLE;
    }
    for(sw_channel = 0; sw_channel < I2C_NUMBER_OF_SW_CHANNELS; sw_channel++)
    {
        I2c_ChannelInfo[sw_channel].SlaveAddress = 0u;
        I2c_ChannelInfo[sw_channel].TxBuffer = NULL;
        I2c_ChannelInfo[sw_channel].RxBuffer = NULL;
        I2c_ChannelInfo[sw_channel].TxLength = 0u;
        I2c_ChannelInfo[sw_channel].TxIndex = 0u;
        I2c_ChannelInfo[sw_channel].RxLength = 0u;
        I2c_ChannelInfo[sw_channel].RxIndex = 0u;
        I2c_ChannelInfo[sw_channel].Result = I2C_SEQ_RESULT_UNDEFINED;
        I2c_ChannelInfo[sw_channel].IsRepeatStart = FALSE;
        I2c_ChannelInfo[sw_channel].IsQueued = FALSE;
        I2c_BusBusyState[sw_channel].WholeNetworkStatus = I2C_IDLE; 
        I2c_BusBusyState[sw_channel].BusBusyTimeout = 0u; 
    }
}

/*============================================================================
**
** Function Name    :   I2c_HwInit
**
** Visibility       :   Static
**
** Description      :   This function will be called to initialise the i2c hw unit.
**
** Invocation       :   I2c_Init
**
** Inputs           :   uint8 I2c_unit_index - Hw unit index.
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void I2c_HwInit(uint8 I2c_unit_index)
{
    I2c_RegisterPtrType i2c_unit; /* i2c register structure */
    if(I2C_NUMBER_OF_HW_CHANNELS > I2c_unit_index)
    {
        i2c_unit = I2c_Config[I2c_unit_index].BaseAddress; /* getting base address from configuration */
        i2c_unit->CON_reg.CON_field.u1I2C_EN = I2C_CLEAR_BIT; 
        /* i2c controller own address setting - required when we are activting as slave */
        i2c_unit->OA_reg.OA_field.u10OA = I2C_CLEAR_BIT;
        /* configuring I2C in normal mode (0) for STB mode (1) */
        i2c_unit->CON_reg.CON_field.u1STB = I2C_CLEAR_BIT; 
        /* Slave Address setting 7-bit slave addressing */
        i2c_unit->CON_reg.CON_field.u1XSA = I2C_CLEAR_BIT; /* 7-bit addressing selection (0) and (1) for 10-bit addressing - 7-bit only supported */
        /* Clear TX FIFO*/
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_CLEAR_BIT;
        /* Clear RX FIFO*/
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_CLEAR_BIT;
        /* Noise filter settings - are controlled internally */
        /*Clear Interrupt requests*/
        i2c_unit->IRQENABLE_SET_reg.u32Register = I2C_CLEAR_BIT;
        i2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;
        i2c_unit->IRQSTATUS_RAW_reg.u32Register = I2C_CLEAR_BIT;
        /* clear the interrupts - all is done in this register */
        i2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
    }
}

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
** Outputs          :   E_OK  : Init Successful
**                      E_NOT_OK : Init Not Successful
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType I2c_DeInit(void)
{
    uint8 hw_channel;
    uint8 sw_channel;
    I2c_RegisterPtrType i2c_unit= NULL;
    Std_ReturnType ret_val = E_NOT_OK;


    for(hw_channel = 0; hw_channel < I2C_NUMBER_OF_HW_CHANNELS; hw_channel++) 
    {
        i2c_unit = I2c_Config[hw_channel].BaseAddress;
        I2c_HwInfo[hw_channel].CurrentPriority = I2C_NO_PRIORITY;
        I2c_HwInfo[hw_channel].CurrentSeq = 0u;
        I2c_HwInfo[hw_channel].TimeoutCount = 0x0000u;
        I2c_HwInfo[hw_channel].IsStopWait = FALSE;
        I2c_HwInfo[hw_channel].HwStatus = I2C_UNINIT;
        I2c_InternalState[hw_channel] = I2C_IDLE;
        I2c_DrvStatus.Status[hw_channel] = I2C_IDLE;
        I2c_HwDeInit(i2c_unit);
        ret_val = E_OK;
    }
    for(sw_channel = 0; sw_channel < I2C_NUMBER_OF_SW_CHANNELS; sw_channel++)
    {
        I2c_ChannelInfo[sw_channel].SlaveAddress = 0u;
        I2c_ChannelInfo[sw_channel].TxBuffer = NULL;
        I2c_ChannelInfo[sw_channel].RxBuffer = NULL;
        I2c_ChannelInfo[sw_channel].TxLength = 0u;
        I2c_ChannelInfo[sw_channel].TxIndex = 0u;
        I2c_ChannelInfo[sw_channel].RxLength = 0u;
        I2c_ChannelInfo[sw_channel].RxIndex = 0u;
        I2c_ChannelInfo[sw_channel].Result = I2C_SEQ_OK;
        I2c_ChannelInfo[sw_channel].IsRepeatStart = FALSE;
        I2c_ChannelInfo[sw_channel].IsQueued = FALSE;
		ret_val = E_OK;
    }
    return ret_val;
}

/*============================================================================
**
** Function Name    :   I2c_HwDeInit
**
** Visibility       :   Static
**
** Description      :   This function will be called to shutdown the i2c hw unit.
**
** Invocation       :   I2c_DeInit
**
** Inputs           :   I2c_RegisterPtrType i2c_unit - Hw unit base register address.
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void I2c_HwDeInit(I2c_RegisterPtrType I2c_unit)
{
    /* I2C Port Settings shall be done in port configurations */

    /* Disable I2C */
    I2c_unit->CON_reg.CON_field.u1I2C_EN = I2C_CLEAR_BIT;   /* Disable i2c module */

    /* Clear all interrupts */
    I2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;

    I2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL; /* disable interrupt register */

}

/*============================================================================
**
** Function Name    :   I2C_SetDataRate
**
** Visibility       :   Static
**
** Description      :   This function will be called to set Baud rate for data
                        transfer.
**
** Invocation       :   I2c_StartTransfer
**
** Inputs           :   I2c_SequenceType Sequence - sequence index.
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void I2C_SetDataRate(I2c_SequenceType Sequence)
{
    I2c_RegisterPtrType i2c_unit= NULL;
    if((I2C_NUMBER_OF_SW_CHANNELS > Sequence) && (I2C_NUMBER_OF_HW_CHANNELS > (I2c_ChannelConfig[Sequence].HwUnit)))
    {
        i2c_unit = I2c_Config[(I2c_ChannelConfig[Sequence].HwUnit)].BaseAddress;
        /* no filter configuration is needed since they are taken care along with the clock configuration and data rate selection and prescaler configuring */
        i2c_unit->PSC_reg.PSC_field.u8PSC = I2c_ChannelConfig[Sequence].psc;
        i2c_unit->SCLL_reg.SCLL_field.u8SCLL = I2c_ChannelConfig[Sequence].scll;
        i2c_unit->SCLH_reg.SCLH_field.u8SCLH = I2c_ChannelConfig[Sequence].sclh;
        if (I2c_ChannelConfig[Sequence].TransferMode == I2C_HIGHSPEED_MODE)
        {
            /* HIGH SPEED MODE */
            /* Enable HS Mode (Master Code preamble enabled) */
            i2c_unit->CON_reg.CON_field.u2OPMODE = 1U;
            /* Set Phase 2 High Speed Dividers */
            i2c_unit->SCLL_reg.SCLL_field.u8HSSCLL = I2c_ChannelConfig[Sequence].hsscll;
            i2c_unit->SCLH_reg.SCLH_field.u8HSSCLH = I2c_ChannelConfig[Sequence].hssclh;
        }
        else
        {
            /* Set to Standard/Fast OPMODE */
            i2c_unit->CON_reg.CON_field.u2OPMODE = 0U;
        }
    }
}


/*============================================================================
**
** Function Name    :   I2c_SetupEB
**
** Visibility       :   Public
**
** Description      :   This function makes the buffer to QUEUED state.
**                      This will not trigger the transmission.
**                      If the EB transmission is ongoing, the request will not
**                      be queued.
**
** Invocation       :   Application
**
** Inputs           :   I2c_ChannelType Channel: I2c sw channel number.
**                      const I2c_DataType* TxBufferPtr: Data buffer pointer for Tx.
**                      I2c_DataType* RxBufferPtr: Data buffer pointer for Rx.
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
Std_ReturnType I2c_SetupEB(I2c_ChannelType Channel, I2c_DataType* TxBufferPtr, I2c_DataType* RxBufferPtr, \
                  I2c_NumberOfDataType TxLength, I2c_NumberOfDataType RxLength, uint8 SlaveAddress)
{
    Std_ReturnType ret_val = E_NOT_OK;
    I2c_SeqResultType result;
    boolean valid_buffer_combination = FALSE;
    uint8 hw;

    /* Channel range check */
    if (Channel < I2C_NUMBER_OF_SW_CHANNELS)
    {
        hw = I2c_ChannelConfig[Channel].HwUnit;
        if (hw < I2C_NUMBER_OF_HW_CHANNELS)
        {
            I2c_EnterCriticalSection();
            result = I2c_ChannelInfo[Channel].Result;

            /* HW must be usable */
            if ((I2c_HwInfo[hw].HwStatus != I2C_UNINIT) &&
                (I2c_DrvStatus.Status[hw] != I2C_UNINIT))
            {
                /* Reject if sequence is already participating in a transfer */
                if ((result != I2C_SEQ_BUSY)    &&
                    (result != I2C_SEQ_PENDING) &&
                    (result != I2C_SEQ_QUEUED)  &&
                    (result != I2C_SEQ_RETRY)   &&
                    (result != I2C_SEQ_REJECT))
                {
                    if ((TxLength > 0U) &&
                        (TxBufferPtr != NULL) &&
                        ((RxLength == 0U) ||
                         ((RxLength > 0U) && (RxBufferPtr != NULL))))
                    {
                        /* write-only or write-then-read transaction */
                        valid_buffer_combination = TRUE;
                    }
                    else if ((TxLength == 0U) &&
                             (TxBufferPtr == NULL) &&
                             (RxLength > 0U) &&
                             (RxBufferPtr != NULL))
                    {
                        /* pure-read transaction */
                        valid_buffer_combination = TRUE;
                    }
                    else
                    {
                        /* invalid buffer combination */
                    }

                    if (valid_buffer_combination != FALSE)
                    {
                        I2c_ChannelInfo[Channel].SlaveAddress = SlaveAddress;
                        I2c_ChannelInfo[Channel].TxBuffer = TxBufferPtr;
                        I2c_ChannelInfo[Channel].RxBuffer = RxBufferPtr;
                        I2c_ChannelInfo[Channel].TxLength = TxLength;
                        I2c_ChannelInfo[Channel].RxLength = RxLength;
                        I2c_ChannelInfo[Channel].TxIndex = 0U;
                        I2c_ChannelInfo[Channel].RxIndex = 0U;
                        I2c_ChannelInfo[Channel].IsRepeatStart = FALSE;
                        I2c_ChannelInfo[Channel].IsQueued = FALSE;
                        I2c_ChannelInfo[Channel].Result = I2C_SEQ_OK;
                        ret_val = E_OK;
                    }
                }
            }

            I2c_ExitCriticalSection();
        }
    }

    return ret_val;
}
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
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void I2c_MainFunction(void)
{
    I2c_SequenceType Sequence = I2C_NUMBER_OF_SW_CHANNELS;
    uint8 HwUnitIndex;

    I2c_RegisterPtrType i2c_unit =NULL;
    /*Select the sequence(channel) among the queued, based on priority and HwUnit Status */
    for(Sequence = 0; Sequence< I2C_NUMBER_OF_SW_CHANNELS; Sequence++)
    {
        HwUnitIndex = I2c_ChannelConfig[Sequence].HwUnit;
        if(I2C_NUMBER_OF_HW_CHANNELS > HwUnitIndex)
        {
           i2c_unit = I2c_Config[HwUnitIndex].BaseAddress;
           if(I2c_ChannelInfo[Sequence].IsQueued != FALSE)
            {
                /* Check if Slave Mode Transmission is on going */
                if(i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB != I2C_SET_BIT)
                {
                    if((I2c_HwInfo[HwUnitIndex].HwStatus == I2C_IDLE) || (I2c_HwInfo[HwUnitIndex].HwStatus == I2C_QUEUED))
                    {
                        if(I2c_HwInfo[HwUnitIndex].CurrentPriority > I2c_ChannelConfig[Sequence].SeqPriority)
                        {
                            I2c_HwInfo[HwUnitIndex].CurrentPriority = I2c_ChannelConfig[Sequence].SeqPriority;
                            I2c_HwInfo[HwUnitIndex].CurrentSeq = Sequence;
                            I2c_HwInfo[HwUnitIndex].HwStatus = I2C_QUEUED;
                        }
                    }
                }
             }
        }  
     }
    /* Transmit the selected Sequence for each HwUnit*/
    for(HwUnitIndex = 0; HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS; HwUnitIndex++)
    {
        if(I2c_HwInfo[HwUnitIndex].HwStatus == I2C_QUEUED)
        {
            Sequence = I2c_HwInfo[HwUnitIndex].CurrentSeq;
            /* Clear the Queued Flag */
            I2c_EnterCriticalSection();
            I2c_ChannelInfo[Sequence].IsQueued = FALSE;
            I2c_ExitCriticalSection();
            if((I2c_ChannelInfo[Sequence].TxLength > 0U) || (I2c_ChannelInfo[Sequence].RxLength > 0U))
            {
                I2c_EnterCriticalSection();
                /* Channel Status to BUSY */
                if (I2c_ChannelInfo[Sequence].Result == I2C_SEQ_QUEUED) 
                {
                    I2c_ChannelInfo[Sequence].Result = I2C_SEQ_PENDING;
                }
                /* Update the timeout for the sequence - changed */
                I2c_HwInfo[HwUnitIndex].TimeoutCount = I2C_STOP_TIMEOUT_COUNT;
                /* Hw Unit Status to BUSY */
                I2c_HwInfo[HwUnitIndex].HwStatus = I2C_BUSY;
                /* Driver Status to BUSY */
                I2c_DrvStatus.Status[HwUnitIndex] = I2C_BUSY;
                I2c_InternalState[HwUnitIndex] = I2C_BUSY;
                I2c_ExitCriticalSection();
                /* Trigger for Start of I2c Transfer */
                I2c_StartTransfer(Sequence);
            }
        }
        else if(I2C_BUSY == I2c_HwInfo[HwUnitIndex].HwStatus)
        {
            if (0U != I2c_HwInfo[HwUnitIndex].TimeoutCount)
            {
                /* cs start */
                I2c_EnterCriticalSection();
                I2c_HwInfo[HwUnitIndex].TimeoutCount--;
                if (0U == I2c_HwInfo[HwUnitIndex].TimeoutCount)
                {
                    Sequence = I2c_HwInfo[HwUnitIndex].CurrentSeq;
                    I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
                    I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
                    I2c_HwInfo[HwUnitIndex].CurrentPriority = I2C_NO_PRIORITY;
                    I2c_MasterTransferComplete(I2c_Config[HwUnitIndex].BaseAddress, Sequence); 
                    I2c_HwInfo[HwUnitIndex].IsStopWait = FALSE;
                    I2c_HwInfo[HwUnitIndex].HwStatus = I2C_IDLE;
                    I2c_DrvStatus.Status[HwUnitIndex] = I2C_IDLE;
                    I2c_InternalState[HwUnitIndex] = I2C_IDLE;
                }
                I2c_ExitCriticalSection();
                /*end cs*/
                if((I2c_HwInfo[HwUnitIndex].TimeoutCount == 0U) && (Sequence < I2C_NUMBER_OF_SW_CHANNELS))
                {
                    I2c_TrySlaveBusRecovery(HwUnitIndex);
                    if(I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                    {
                        /* Sequence End Callback Notofication */
                        I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(Sequence, I2C_BUSY, I2C_SEQ_FAILED);
                    }
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    for(Sequence = 0; Sequence< I2C_NUMBER_OF_SW_CHANNELS; Sequence++)
    {
        HwUnitIndex = I2c_ChannelConfig[Sequence].HwUnit;
        if(HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS)
        {
            i2c_unit = I2c_Config[HwUnitIndex].BaseAddress;
            if(I2c_BusBusyState[Sequence].WholeNetworkStatus == I2C_BUSY)
            {
                /* Bus is Busy */
                if(I2C_CLEAR_BIT != i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB)
                {
                    if (0U != I2c_BusBusyState[Sequence].BusBusyTimeout)
                    {            
                        I2c_EnterCriticalSection();
                        I2c_BusBusyState[Sequence].BusBusyTimeout--;
                        if (0U == I2c_BusBusyState[Sequence].BusBusyTimeout)
                        {
                            I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
                            I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
                            I2c_HwInfo[HwUnitIndex].CurrentPriority = I2C_NO_PRIORITY;
                            I2c_HwInfo[HwUnitIndex].HwStatus = I2C_IDLE;
                            I2c_DrvStatus.Status[HwUnitIndex] = I2C_IDLE;
                            I2c_InternalState[HwUnitIndex] = I2C_IDLE;
                            I2c_MasterTransferComplete(I2c_Config[HwUnitIndex].BaseAddress, Sequence);
                            I2c_HwInfo[HwUnitIndex].IsStopWait = FALSE;
                        }
                        I2c_ExitCriticalSection();
                        if (0U == I2c_BusBusyState[Sequence].BusBusyTimeout)
                        {
                            I2c_TrySlaveBusRecovery(HwUnitIndex);
                            I2c_BusBusyState[Sequence].WholeNetworkStatus = I2C_IDLE;
                            if (I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                            {
                                /* Sequence End Callback Notification */
                                I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(Sequence, I2C_BUSY, I2C_SEQ_FAILED);
                            }
                        }
                    }
                }
                else
                {
                    /* add to queue and wait for the next cycle to address it */
                    I2c_EnterCriticalSection();
                    /* Set Queue for the sequence */
                    I2c_ChannelInfo[Sequence].IsQueued = TRUE;
                    I2c_ChannelInfo[Sequence].Result = I2C_SEQ_QUEUED;
                    I2c_BusBusyState[Sequence].WholeNetworkStatus = I2C_IDLE;
                    I2c_BusBusyState[Sequence].BusBusyTimeout = 0u;
                    I2c_ExitCriticalSection();
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }
}


/*============================================================================
**
** Function Name    :   I2c_StartTransfer
**
** Visibility       :   Static
**
** Description      :   This function starts the I2c transfer.
**                      Rest of the transfer will take place in interrupt.
**
** Invocation       :   Main Function.
**
** Inputs           :   I2c_SequenceType Sequence: Sequence/Channel ID
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void I2c_StartTransfer(I2c_SequenceType Sequence)
{
    I2c_RegisterPtrType i2c_unit = NULL;
    I2c_StatusType next_state = I2C_BUSY;
    boolean is_read_only = FALSE;
    uint8 hw;

    if ((I2C_NUMBER_OF_SW_CHANNELS > Sequence) && (I2C_NUMBER_OF_HW_CHANNELS > (I2c_ChannelConfig[Sequence].HwUnit)))
    {
        hw = I2c_ChannelConfig[Sequence].HwUnit;
        i2c_unit = I2c_Config[hw].BaseAddress;

        is_read_only = ((I2c_ChannelInfo[Sequence].TxLength == 0U) &&
                        (I2c_ChannelInfo[Sequence].RxLength > 0U)) ? TRUE : FALSE;

        /* all interrupts are disabled */
        i2c_unit->IRQENABLE_SET_reg.u32Register = I2C_CLEAR_BIT;
        i2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;

        /* clear the interrupts - all is done in this register */
        i2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
        (void)i2c_unit->IRQSTATUS_RAW_reg.u32Register;   /* dummy read to sync */

        /* Clears the FIFOs */
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_CLEAR_BIT;
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_CLEAR_BIT;

        i2c_unit->CON_reg.u32Register = I2C_CLEAR_BIT;

        /* disable i2c module */
        i2c_unit->CON_reg.CON_field.u1I2C_EN = I2C_CLEAR_BIT;

        /* configuring I2C in normal mode (0) for STB mode (1) */
        i2c_unit->CON_reg.CON_field.u1STB = I2C_CLEAR_BIT;

        /* Set the Data rate transfer for the particular SW channel */
        I2C_SetDataRate(Sequence);

        /* TX FIFO threshold only matters for transactions that start in TX mode */
        if (is_read_only == FALSE)
        {
            if (I2c_ChannelInfo[Sequence].TxLength <= I2C_FIFO_SIZE)
            {
                i2c_unit->BUF_reg.BUF_field.u6TXTRSH = I2c_ChannelInfo[Sequence].TxLength;
            }
            else
            {
                i2c_unit->BUF_reg.BUF_field.u6TXTRSH = I2C_HALF_FIFO_SIZE;
            }
        }
        else
        {
            i2c_unit->BUF_reg.BUF_field.u6TXTRSH = I2C_CLEAR_BIT;
        }

        if (I2C_CLEAR_BIT == i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB)
        {
            i2c_unit->CON_reg.CON_field.u1I2C_EN = I2C_SET_BIT;

            if (is_read_only == FALSE)
            {
                I2CDataCountSet(i2c_unit, Sequence);
                i2c_unit->CON_reg.CON_field.u1MST =
                    (I2c_Config[hw].I2C_Mode & 0x00000002UL) >> 1UL;
                i2c_unit->CON_reg.CON_field.u1TRX = I2C_SET_BIT;
                i2c_unit->SA_reg.SA_field.u10SA = I2c_ChannelInfo[Sequence].SlaveAddress;

                if (I2c_ChannelInfo[Sequence].RxLength == 0U)
                {
                    i2c_unit->CON_reg.CON_field.u1STP = I2C_SET_BIT;
                }

                next_state = I2C_BUSY;
            }
            else
            {
                next_state = I2c_PrepareReadTransfer(i2c_unit, hw, Sequence);
            }

            /* Enable interrupt sources to continue transfer */
            I2c_EnterCriticalSection();

            i2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
            (void)i2c_unit->IRQSTATUS_RAW_reg.u32Register;

            /* Enable error + event interrupts */
            i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1NACK_IE = I2C_SET_BIT;
            i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1AL_IE   = I2C_SET_BIT;
            i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1ARDY_IE = I2C_SET_BIT;

            if (is_read_only == FALSE)
            {
                /* Existing async path: start in TX mode */
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1XRDY_IE = I2C_SET_BIT;
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1XDR_IE  = I2C_SET_BIT;
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RRDY_IE = I2C_SET_BIT;
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RDR_IE  = I2C_SET_BIT;
            }
            else
            {
                /* Pure-read path: receive interrupts only */
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RRDY_IE = I2C_SET_BIT;
                i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RDR_IE  = I2C_SET_BIT;
            }

            I2c_HwInfo[hw].HwStatus = I2C_BUSY;
            I2c_HwInfo[hw].CurrentSeq = Sequence;
            I2c_HwInfo[hw].CurrentPriority = I2c_ChannelConfig[Sequence].SeqPriority;
            I2c_HwInfo[hw].TimeoutCount = I2C_STOP_TIMEOUT_COUNT;
            I2c_HwInfo[hw].IsStopWait = FALSE;
            I2c_DrvStatus.Status[hw] = I2C_BUSY;
            I2c_InternalState[hw] = next_state;
            I2c_ChannelInfo[Sequence].Result = I2C_SEQ_BUSY;
            I2c_ChannelInfo[Sequence].IsQueued = FALSE;

            I2c_ExitCriticalSection();

            /* Start condition */
            i2c_unit->CON_reg.CON_field.u1STT = I2C_SET_BIT;
        }
        else
        {
            /* do nothing */
        }
    }
}


/*============================================================================
**
** Function Name    :   I2c_RepeatedStart
**
** Visibility       :   Static
**
** Description      :   This function triggers the I2c Repeated Start.
**
** Invocation       :   ISR.
**
** Inputs           :   I2c_SequenceType Sequence: Sequence/Channel ID
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void I2c_RepeatedStart(I2c_SequenceType Sequence)
{
    I2c_RegisterPtrType i2c_unit= NULL;
    if((I2C_NUMBER_OF_SW_CHANNELS > Sequence) && (I2C_NUMBER_OF_HW_CHANNELS > (I2c_ChannelConfig[Sequence].HwUnit)))
    {
        i2c_unit = I2c_Config[(I2c_ChannelConfig[Sequence].HwUnit)].BaseAddress;
        /* all interrupts are disabled */
        i2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;
        /* clear the interrupts - all is done in this register */
        i2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
        /* Clears the TX FIFO */
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_CLEAR_BIT;
        if(I2c_ChannelInfo[Sequence].RxLength >= 2U)
        {
            i2c_unit->BUF_reg.BUF_field.u6RXTRSH = ((I2c_ChannelInfo[Sequence].RxLength <= I2C_FIFO_SIZE) ?
                     (I2c_ChannelInfo[Sequence].RxLength) : (I2C_RX_LENGTH)); 
            I2c_InternalState[I2c_ChannelConfig[Sequence].HwUnit] = I2C_RX_STATE_1;
        }
        else
        {
            i2c_unit->BUF_reg.BUF_field.u6RXTRSH = I2C_CLEAR_BIT; 
            I2c_InternalState[I2c_ChannelConfig[Sequence].HwUnit] = I2C_RX_STATE_0;
        }
        I2C_RxDataCountSet(i2c_unit,Sequence);
        i2c_unit->CON_reg.CON_field.u1MST = (I2c_Config[I2c_ChannelConfig[Sequence].HwUnit].I2C_Mode & 0x00000002UL) >> 1UL;
        i2c_unit->CON_reg.CON_field.u1TRX = I2C_CLEAR_BIT;
        i2c_unit->SA_reg.SA_field.u10SA = I2c_ChannelInfo[Sequence].SlaveAddress;    
        I2c_EnterCriticalSection();
        /*SetRxInterruptMask*/
        i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RRDY_IE = I2C_SET_BIT;
        i2c_unit->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1RDR_IE = I2C_SET_BIT;
        I2c_ExitCriticalSection();
        i2c_unit->CON_reg.CON_field.u1STT = I2C_SET_BIT;
    }
}


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
Std_ReturnType I2c_AsyncTransmit(I2c_SequenceType Sequence)
{
    Std_ReturnType ret_val;
    ret_val = E_NOT_OK;
    I2c_RegisterPtrType i2c_unit= NULL;
    uint8 HwUnitIndex = 0u;
    if(I2C_NUMBER_OF_SW_CHANNELS > Sequence)
    {
        HwUnitIndex = I2c_ChannelConfig[Sequence].HwUnit;
        if(I2C_NUMBER_OF_HW_CHANNELS > HwUnitIndex)
        {
            i2c_unit = I2c_Config[HwUnitIndex].BaseAddress;
            if(I2c_DrvStatus.Status[HwUnitIndex] != I2C_UNINIT)
            {
                if((I2c_Config[I2c_ChannelConfig[Sequence].HwUnit].I2C_Mode & I2C_MASTER_MODE) != 0U )
                {
                    /* Check whether the bus is busy due to this Micro as Master */
                    if(I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].HwStatus != I2C_BUSY)
                    {
                        /* check if bus is not busy - the whole i2c network */
                        if(I2C_CLEAR_BIT == i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB)
                        {
                            ret_val = E_OK;
                            if((I2c_ChannelInfo[Sequence].TxLength > 0U) || (I2c_ChannelInfo[Sequence].RxLength > 0U))
                            {
                                I2c_EnterCriticalSection();
                                /* Channel Status to BUSY */
                                I2c_ChannelInfo[Sequence].Result = I2C_SEQ_PENDING;
                                /* Update the timeout for the sequence */
                                I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].TimeoutCount = I2C_STOP_TIMEOUT_COUNT;
                                /* Hw Unit Status to BUSY */
                                I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].HwStatus = I2C_BUSY;
                                /* update the current sequence to hw unit structure */
                                I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].CurrentSeq = Sequence;
                                I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].IsStopWait = FALSE;
                                I2c_HwInfo[I2c_ChannelConfig[Sequence].HwUnit].CurrentPriority = I2c_ChannelConfig[Sequence].SeqPriority;
                                /* Driver Status to BUSY */
                                I2c_DrvStatus.Status[HwUnitIndex] = I2C_BUSY;
                                I2c_InternalState[HwUnitIndex] = I2C_BUSY;
                                I2c_ExitCriticalSection(); 
                                /* Start Transfer for the above Set Sequence */
                                I2c_StartTransfer(Sequence);
                            }
                        }
                        else /* Bus Is Busy for the the whole i2c network - this is checked when other i2c modules other than the R5 core i2c */
                        {
                            
                            if(I2c_BusBusyState[Sequence].WholeNetworkStatus != I2C_BUSY)
                            {
                                ret_val = E_NOT_OK;
                                I2c_BusBusyState[Sequence].WholeNetworkStatus = I2C_BUSY;
                                I2c_BusBusyState[Sequence].BusBusyTimeout = I2C_BUSBUSY_TIMEOUT_COUNT;
                                /* Send notification to Application on the bus busy with retry mechanism status */
                                if(I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                                {
                                    /* Sequence End Callback Notfication */
                                    I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(Sequence, I2C_BUSY, I2C_SEQ_RETRY); 
                                }
                            }
                            else
                            {
                                /* Send notification to Application on the bus busy with cancel status of seq */
                                if(I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                                {
                                    /* Sequence End Callback Notfication */
                                    I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(Sequence, I2C_BUSY, I2C_SEQ_CANCELLED);
                                }
                                I2c_EnterCriticalSection();
                                I2c_ChannelInfo[Sequence].Result = I2C_SEQ_CANCELLED;
                                I2c_ExitCriticalSection();
                            }
                            
                        }
                    }    
                    else /* If the internal status of our Master is busy then */
                    {
                        /* check if sequence is not in queue already */
                        if(I2c_ChannelInfo[Sequence].IsQueued != TRUE)
                        {
                            /* add to queue and wait for the next cycle to address it */
                            I2c_EnterCriticalSection(); 
                            /* Set Queue for the sequence */ 
                            I2c_ChannelInfo[Sequence].IsQueued = TRUE;
                            I2c_ChannelInfo[Sequence].Result = I2C_SEQ_QUEUED;
                            I2c_ExitCriticalSection(); 
                            ret_val = E_OK;
                        }
                        /* sequence is in queue already */
                        else
                        {
                            /* reject status of the seq and notify callback to application shows that already in queue */
                            if(I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                            {
                                /* Sequence End Callback Notfication */
                                I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(Sequence, I2C_BUSY, I2C_SEQ_REJECT);
                            }
                        }
                    }
                    
                }
            }
        }
    }
    return ret_val;
}

/*============================================================================
**
** Function Name    :   I2c_ReadFiFoWithoutCheck
**
** Visibility       :   Static
**
** Description      :   This function Get data available in RX FIFO.
**
** Invocation       :   ISR.
**
** Inputs           :   volatile SCB_Reg_st const *base : BaseAddress of current sequence
                        void *rxBuf                    : Rx buffer pointer
                        uint32 size                  : Size to be copied from FIFO to Buffer
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void I2c_ReadFiFoWithoutCheck(const volatile I2c_RegisterPtrType base, void *rxBuf, uint16 size)
{
    uint16 BufferIndex;
    uint8 *buf = (uint8 *) rxBuf;
    /* Get data available in RX FIFO */
    for (BufferIndex = 0U; BufferIndex < size; ++BufferIndex)
    {
        buf[BufferIndex] = base->DATA_reg.DATA_field.u8DATA;
    }
}

/*============================================================================
**
** Function Name    :   I2C_RxGetBufferStatus
**
** Visibility       :   Static
**
** Description      :   This function returns the Rx buffer status
**
** Invocation       :   ISR.
**
** Inputs           :   volatile SCB_Reg_st const *base : BaseAddress of current sequence 
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static uint16 I2C_RxGetBufferStatus(volatile I2c_RegisterPtrType base)
{
    return base->BUFSTAT_reg.BUFSTAT_field.u6RXSTAT;
}

/*============================================================================
**
** Function Name    :   RxDiffCalculationFunction
**
** Visibility       :   Static
**
** Description      :   This function returns the differential Rx buffer status
**
** Invocation       :   ISR.
**
** Inputs           :   uint16 StartValue, uint16 EndValue
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static uint16 RxDiffCalculationFunction(uint16 StartValue, uint16 EndValue)
{
    uint16 RetVal = 0u;
    if(StartValue > EndValue)
    {
        RetVal = StartValue - EndValue;
    }
    else
    {
        RetVal = EndValue - StartValue;
    }

    if(RetVal > I2C_FIFO_SIZE)
    {
        RetVal = I2C_FIFO_SIZE;
    }
    return RetVal;
}

/*============================================================================
**
** Function Name    :   I2c_ReadFiFoArray
**
** Visibility       :   Static
**
** Description      :   This function Get data available in RX FIFO.
**
** Invocation       :   ISR.
**
** Inputs           :   volatile SCB_Reg_st const *base : BaseAddress of current sequence SCB
                        void *rxBuf                    : Rx buffer pointer
                        uint32 size                  : Size to be copied from FIFO to Buffer
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static uint16 I2c_ReadFiFoArray(const volatile I2c_RegisterPtrType base, void *rxBuf, uint16 size)
{
    static volatile uint16 ReadNumToCopy = 0u;
    /* Get available items in RX FIFO */
    ReadNumToCopy = I2C_RxGetBufferStatus(base);
    uint16 numToCopy = 0u;
    if(ReadNumToCopy != 0u)
    {
        numToCopy = I2C_FIFO_SIZE;
        uint16 rxbuffirst = 0;
        uint16 rxbufend = 0;
        rxbuffirst = ReadNumToCopy;
        /* Adjust items which will be read */
        if (numToCopy > size)
        {
            numToCopy = size;
        }
        /* Get data available in RX FIFO */
        I2c_ReadFiFoWithoutCheck(base, rxBuf, numToCopy);

        rxbufend = I2C_RxGetBufferStatus(base);

        if(rxbuffirst == 0u)
        {
            rxbuffirst = I2C_MAX_BUFSTAT_SIZE;
        }
        else
        {
            /* do nothing */
        }
        numToCopy = RxDiffCalculationFunction(rxbuffirst, rxbufend);
    }
    return (numToCopy);
}

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
void I2c_TxRxIsroutine(uint8 HwUnitIndex)
{
    if(HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS)
    {
        /* obtaining the current sequence id for checking the seq result to choose between isr's */
        /* Master Interrupt */
        MasterInterrupt(HwUnitIndex); 
    }
}

/*============================================================================
**
** Function Name    :   I2CDataCountGet
**
** Visibility       :   Public
**
** Description      :   This function returns the data set for particular 
**                      channel
**
** Invocation       :   private.
**
** Inputs           :   volatile I2c_RegisterPtrType base
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static uint32 I2CDataCountGet(volatile I2c_RegisterPtrType base)
{
    return base->CNT_reg.CNT_field.u16DCOUNT;
}

/*============================================================================
**
** Function Name    :   I2CDataCountSet
**
** Visibility       :   Public
**
** Description      :   This function set the data set for particular 
**                      channel
**
** Invocation       :   private.
**
** Inputs           :   volatile I2c_RegisterPtrType base, uint8 Sequence
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static void I2CDataCountSet(volatile I2c_RegisterPtrType base, uint8 Sequence)
{
    base->CNT_reg.CNT_field.u16DCOUNT = I2c_ChannelInfo[Sequence].TxLength;

}

/*============================================================================
**
** Function Name    :   I2C_RxDataCountSet
**
** Visibility       :   Public
**
** Description      :   This function set the data set for particular 
**                      channel
**
** Invocation       :   private.
**
** Inputs           :   volatile I2c_RegisterPtrType base, uint8 Sequence
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static void I2C_RxDataCountSet(volatile I2c_RegisterPtrType base, uint8 Sequence)
{
    base->CNT_reg.CNT_field.u16DCOUNT = I2c_ChannelInfo[Sequence].RxLength;

}

/*============================================================================
**
** Function Name    :   I2C_GetBufferStatus
**
** Visibility       :   Static
**
** Description      :   This function returns the buffer status
**
** Invocation       :   ISR.
**
** Inputs           :   volatile I2c_RegisterPtrType base
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/

static uint16 I2C_GetBufferStatus(volatile I2c_RegisterPtrType base)
{
    return base->BUFSTAT_reg.BUFSTAT_field.u6TXSTAT;
}
/*============================================================================
**
** Function Name    :   I2c_WriteFiFoWithoutCheck
**
** Visibility       :   Static
**
** Description      :   This function put data available in buffer to TX FIFO.
**
** Invocation       :   ISR.
**
** Inputs           :   volatile SCB_Reg_st const *base : BaseAddress of current sequence SCB
                        void *txBuf                    : Rx buffer pointer
                        uint32 size                  : Size to be copied from Buffer to FIFO
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void I2c_WriteFiFoWithoutCheck(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size)
{
    uint16 BufferIndex;
    uint8 *buf = (uint8 *) txBuf;
    /* Put data into TX FIFO */
    for (BufferIndex = 0U; BufferIndex < size; ++BufferIndex)
    {
        base->DATA_reg.DATA_field.u8DATA = buf[BufferIndex];
    }
}

/*============================================================================
**
** Function Name    :   DiffCalculationFunction
**
** Visibility       :   Static
**
** Description      :   This function returns the differential Rx buffer status
**
** Invocation       :   ISR.
**
** Inputs           :   uint16 StartValue, uint16 EndValue
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

static uint16 DiffCalculationFunction(uint16 StartValue, uint16 EndValue)
{
    uint16 RetVal = 0u;
    if(StartValue > EndValue)
    {
        RetVal = StartValue - EndValue;
    }
    else
    {
        RetVal = EndValue - StartValue;
    }

    if(RetVal > 0x10u)
    {
        RetVal = 0x10u;
    }
    return RetVal;
}

/*============================================================================
**
** Function Name    :   I2c_WriteFiFoWithoutCheck
**
** Visibility       :   Static
**
** Description      :   This function put data available in buffer to TX FIFO.
**
** Invocation       :   ISR.
**
** Inputs           :   volatile SCB_Reg_st const *base : BaseAddress of current sequence SCB
                        void *txBuf                    : Rx buffer pointer
                        uint32 size                  : Size to be copied from Buffer to FIFO
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static volatile uint16 txfifobufferstatus = 0;

static uint16 I2c_XDRWriteFiFoArray(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size)
{
    txfifobufferstatus = I2C_GetBufferStatus(base);
    uint16 numToCopy = 0;
    uint16 availabledata = 0u;
    if(txfifobufferstatus != 0u)
    {
        numToCopy = 0x10u;
        if (numToCopy > size)
        {
            numToCopy = size;
        }
        I2c_WriteFiFoWithoutCheck(base, txBuf, numToCopy);
        availabledata = numToCopy;
    }

    return (availabledata);   
}

static uint16 I2c_WriteFiFoArray(volatile I2c_RegisterPtrType base, void *txBuf, uint16 size)
{
    txfifobufferstatus = I2C_GetBufferStatus(base);
    uint16 numToCopy = 0;
    numToCopy = 0x10u;
    uint16 txbuffirst = 0u;
    uint16 txbufend = 0u;

    txbuffirst = txfifobufferstatus;

    if (numToCopy > size)
    {
        numToCopy = size;
    }
    I2c_WriteFiFoWithoutCheck(base, txBuf, numToCopy);

    txbufend = I2C_GetBufferStatus(base);

    if(txbuffirst == 0u)
    {
        txbuffirst = 0x40u;
    }
    else
    {
        /* do nothing */
    }

    numToCopy = DiffCalculationFunction(txbuffirst, txbufend);
    return (numToCopy);   
}

/*============================================================================
**
** Function Name    :   Masterintprocessing
**
** Visibility       :   Public
**
** Description      :   This function is invoked whenever a Master interrupt 
**                      has occurred.
**
** Invocation       :   Interrupt.
**
** Inputs           :   HwUnitIndexVAr
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void MasterInterrupt(uint8 HwUnitIndexVAr)
{
  I2c_ChannelType Sequence = 0U;
  I2c_RegisterPtrType Reg_pt = NULL;
  uint32 IntrStatus = 0U;
  uint32 IntrRawStatus = 0U;
  boolean errorOccurred = FALSE;
  if (I2C_NUMBER_OF_HW_CHANNELS > HwUnitIndexVAr)
  {
    Reg_pt = I2c_Config[HwUnitIndexVAr].BaseAddress;
    Sequence = I2c_HwInfo[HwUnitIndexVAr].CurrentSeq;
    /* Get the Interrupt Status register data */
    IntrStatus = Reg_pt->IRQSTATUS_reg.u32Register;
    /* Get the Interrupt Raw Status register data */
    IntrRawStatus = Reg_pt->IRQSTATUS_RAW_reg.u32Register;

    #if I2C_DEBUG_STATS_ENABLED
    I2c_DebugStats[HwUnitIndexVAr].IsrEntryCount++;
    I2c_DebugStats[HwUnitIndexVAr].LastIntrStatus = IntrStatus;
    I2c_DebugStats[HwUnitIndexVAr].LastIntrRawStatus = IntrRawStatus;
    I2c_DebugStats[HwUnitIndexVAr].LastState = I2c_InternalState[HwUnitIndexVAr];
    I2c_DebugStats[HwUnitIndexVAr].LastSequence = Sequence;
    #endif


    if (I2C_NUMBER_OF_SW_CHANNELS > Sequence)
    {
      if ((IntrRawStatus & I2C_INTR_AL) != 0U)
      {
        Reg_pt->IRQSTATUS_reg.u32Register = I2C_INTR_AL;
        I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
        #if I2C_DEBUG_STATS_ENABLED
        I2c_DebugStats[HwUnitIndexVAr].ErrorCount++;
        I2c_DebugStats[HwUnitIndexVAr].AlCount++;
        #endif
        I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
        (void)I2c_Det_ReportError(I2C_MASTER_INTERRUPT, I2C_E_AL);
        errorOccurred = TRUE;
      }

      if (((IntrRawStatus & I2C_INTR_NACK) != 0U) && 
          ((I2c_ChannelInfo[Sequence].TxLength > 0U) || (I2c_ChannelInfo[Sequence].RxLength > 0U)))
      {
        Reg_pt->IRQSTATUS_reg.u32Register = I2C_INTR_NACK;
        I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
        #if I2C_DEBUG_STATS_ENABLED
        I2c_DebugStats[HwUnitIndexVAr].ErrorCount++;
        I2c_DebugStats[HwUnitIndexVAr].NackCount++;
        #endif
        I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
        (void)I2c_Det_ReportError(I2C_MASTER_INTERRUPT, I2C_E_NACK);
        errorOccurred = TRUE;
      }

      if ((IntrStatus & I2C_INTR_ROVR) != 0U)
      {
        #if I2C_DEBUG_STATS_ENABLED
        I2c_DebugStats[HwUnitIndexVAr].RovrCount++;
        #endif
        Reg_pt->IRQSTATUS_reg.u32Register = I2C_INTR_ROVR;
        while (Reg_pt->BUFSTAT_reg.BUFSTAT_field.u6RXSTAT > 0U)
        {
          volatile uint32 dummy = Reg_pt->DATA_reg.DATA_field.u8DATA;
          (void)dummy;
        }
        I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
        #if I2C_DEBUG_STATS_ENABLED
        I2c_DebugStats[HwUnitIndexVAr].ErrorCount++;
        #endif
        I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
        (void)I2c_Det_ReportError(I2C_MASTER_INTERRUPT, I2C_E_ROVR);
        errorOccurred = TRUE;
      }

      if ((IntrRawStatus & I2C_INTR_AERR) != 0u)
      {
        #if I2C_DEBUG_STATS_ENABLED
        I2c_DebugStats[HwUnitIndexVAr].AerrCount++;
        #endif
        Reg_pt->IRQSTATUS_reg.u32Register = I2C_INTR_AERR;
      }

      if (errorOccurred != TRUE)
      {
        if ((I2C_CLEAR_BIT != (I2C_INTR_XDR & IntrRawStatus)) && (I2c_ChannelInfo[Sequence].TxLength >= 1U))
        {
          if (I2c_ChannelInfo[Sequence].TxLength > 1U)
          {
            uint16 NumToCopy = I2c_ChannelInfo[Sequence].TxLength - 1U;
            /* Write data into TX FIFO */
            NumToCopy = I2c_XDRWriteFiFoArray(Reg_pt, I2c_ChannelInfo[Sequence].TxBuffer, NumToCopy);
            I2c_ChannelInfo[Sequence].TxIndex += NumToCopy;
            I2c_ChannelInfo[Sequence].TxLength -= NumToCopy;
            I2c_ChannelInfo[Sequence].TxBuffer = &I2c_ChannelInfo[Sequence].TxBuffer[NumToCopy];
          }
          if (I2c_ChannelInfo[Sequence].TxLength == 1U)
          {
            Reg_pt->DATA_reg.DATA_field.u8DATA = I2c_ChannelInfo[Sequence].TxBuffer[0UL];
            /* Increment the Index */
            ++I2c_ChannelInfo[Sequence].TxIndex;
            /* Set Tx length to O after all data transmitted to FIFO */
            I2c_ChannelInfo[Sequence].TxLength = 0U;
            Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
          }
        }
        else if (I2C_CLEAR_BIT != (I2C_INTR_XDR & IntrRawStatus))
        {
          if ((I2c_ChannelInfo[Sequence].TxLength == 0U) && (I2c_ChannelInfo[Sequence].RxLength == 0U))
          {
            Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XDR = I2C_SET_BIT;
            Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1ARDY_IE = I2C_SET_BIT;
            Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
            I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
          }
          else if ((I2c_ChannelInfo[Sequence].TxLength == 0U) && (I2c_ChannelInfo[Sequence].RxLength != 0U))
          {
            if (I2C_CLEAR_BIT == Reg_pt->BUFSTAT_reg.BUFSTAT_field.u6TXSTAT) /*Tx data reg is empty*/
            {
              /* Check if ACK received*/
              if (I2C_CLEAR_BIT == (I2C_INTR_NACK & IntrRawStatus))
              {
                /* This function triggers the I2c Repeated Start for data receive */
                if (I2C_CLEAR_BIT == Reg_pt->CNT_reg.CNT_field.u16DCOUNT)
                {
                  Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XDR = I2C_SET_BIT;
                  I2c_RepeatedStart(Sequence);
                }
              }
              else /* Ack not recieved */
              {
                Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
                I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
                #if I2C_DEBUG_STATS_ENABLED
                I2c_DebugStats[HwUnitIndexVAr].ErrorCount++;
                #endif
                /* Ack not recieved. Issue a STOP by setting Internal State*/
                I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
              }
            }
            else
            {
              /* check for register ready if yes then proceed for Repeated Start */
              if ((I2C_CLEAR_BIT != (I2C_INTR_ARDY & IntrRawStatus))) /* TxSTAT is not empty but the local TxLength is decremented to 0 */
              {
                I2c_RepeatedStart(Sequence);
              }
            }
          }
          else
          {
            // do nothing
          }
        }
        else
        {
          Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XDR = I2C_SET_BIT;
        }

        if (I2C_CLEAR_BIT != (I2C_INTR_TX & IntrRawStatus)) /* check for Transmit Interrupt */
        {
          if (0U != I2c_ChannelInfo[Sequence].TxLength)
          {
            if (1U < I2c_ChannelInfo[Sequence].TxLength)
            {
              /* Get the number of bytes to copy into TX FIFO */
              uint16 NumToCopy = I2c_ChannelInfo[Sequence].TxLength - 1u;
              /* Write data into TX FIFO */
              NumToCopy = I2c_WriteFiFoArray(Reg_pt, I2c_ChannelInfo[Sequence].TxBuffer, NumToCopy);
              I2c_ChannelInfo[Sequence].TxIndex += NumToCopy;
              I2c_ChannelInfo[Sequence].TxLength -= NumToCopy;
              I2c_ChannelInfo[Sequence].TxBuffer = &I2c_ChannelInfo[Sequence].TxBuffer[NumToCopy];
            }

            /* Put the last byte */
            if (1UL == I2c_ChannelInfo[Sequence].TxLength)
            {
              /* Put the last data byte into TX FIFO and make sure that TX
               * underflow will happen after all data is transferred onto the bus.
               */
              Reg_pt->DATA_reg.DATA_field.u8DATA = I2c_ChannelInfo[Sequence].TxBuffer[0UL];
              /* Increment the Index */
              ++I2c_ChannelInfo[Sequence].TxIndex;
              /* Set Tx length to O after all data transmitted to FIFO */
              I2c_ChannelInfo[Sequence].TxLength = 0U;
            }
            /* Complete the transfer */
            if (0UL == I2c_ChannelInfo[Sequence].TxLength)
            {
              Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
            }
            else
            {
              /* Do nothing */
            }
          }
          else
          {
            /* Check whether Data has to be received */
            if (0U != I2c_ChannelInfo[Sequence].RxLength)
            {
              /* Check if ACK received*/
              if (I2C_CLEAR_BIT == (I2C_INTR_NACK & IntrRawStatus))
              {
                /* This function triggers the I2c Repeated Start for data receive */
                I2c_RepeatedStart(Sequence);
              }
              else /* Ack not recieved */
              {
                Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
                I2c_ChannelInfo[Sequence].Result = I2C_SEQ_FAILED;
                #if I2C_DEBUG_STATS_ENABLED
                I2c_DebugStats[HwUnitIndexVAr].ErrorCount++;
                #endif
                /* Ack not recieved. Issue a STOP by setting Internal State*/
                I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
              }
            }
            else
            {
              Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
              I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
            }
          }
        }
        /* Check whether Rx interrupt has occurred */
        if (I2C_CLEAR_BIT != (I2C_INTR_RX & IntrStatus))
        {
          /* Reception of Data if receive lenght is other than 0*/
          if (0U != I2c_ChannelInfo[Sequence].RxLength)
          {
            switch (I2c_InternalState[HwUnitIndexVAr])
            {
            /* Switch case for recepetion of last byte or single data byte*/
            case I2C_RX_STATE_0:
            {
              I2c_ChannelInfo[Sequence].RxBuffer[0UL] = Reg_pt->DATA_reg.DATA_field.u8DATA;
              ++I2c_ChannelInfo[Sequence].RxIndex;
              --I2c_ChannelInfo[Sequence].RxLength;
              if (I2c_ChannelInfo[Sequence].RxLength > 0UL)
              {
                /* Continue the transaction: move pointer send an ACK */
                I2c_ChannelInfo[Sequence].RxBuffer = &I2c_ChannelInfo[Sequence].RxBuffer[1UL];
              }
              else
              {
                if (Reg_pt->CON_reg.CON_field.u1STP != I2C_SET_BIT)
                {
                  Reg_pt->CON_reg.CON_field.u1STP = I2C_SET_BIT;
                }
                Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
                I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
              }
            }
            break;
            /* Switch case for recepetion of data length greater than or equals 2*/
            case I2C_RX_STATE_1:
            {
              /* Get data from RX FIFO */
              uint16 numToCopied = 0;
              numToCopied = I2c_ReadFiFoArray(Reg_pt, I2c_ChannelInfo[Sequence].RxBuffer, I2c_ChannelInfo[Sequence].RxLength);
              I2c_ChannelInfo[Sequence].RxIndex += numToCopied;
              I2c_ChannelInfo[Sequence].RxLength -= numToCopied;
              I2c_ChannelInfo[Sequence].RxBuffer = &I2c_ChannelInfo[Sequence].RxBuffer[numToCopied];
              /* For getting last two byte data */
              if (0u == I2c_ChannelInfo[Sequence].RxLength)
              {
                if (Reg_pt->CON_reg.CON_field.u1STP != I2C_SET_BIT)
                {
                  Reg_pt->CON_reg.CON_field.u1STP = I2C_SET_BIT;
                }
                Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
                I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
              }
              Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1RRDY = I2C_SET_BIT;
              if (2UL > I2c_ChannelInfo[Sequence].RxLength)
              {
                if (1UL == I2c_ChannelInfo[Sequence].RxLength)
                {
                  /* Catch the last byte */
                  /* Set Rx Fifo Level to 0*/
                  Reg_pt->BUF_reg.BUF_field.u6RXTRSH = I2C_CLEAR_BIT;
                  /* Put data into the component buffer */
                  I2c_InternalState[HwUnitIndexVAr] = I2C_RX_STATE_0;
                }
                else
                {
                  /* Stop RX processing */
                  // Reg_pt->CON_reg.CON_field.u1STP = I2C_SET_BIT;
                  Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
                  /* Genrate I2c Stop */
                  I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
                }
              }
              else
              {
                /* Continue the transfer: Adjust the level in RX FIFO */
                Reg_pt->BUF_reg.BUF_field.u6RXTRSH = ((I2c_ChannelInfo[Sequence].RxLength <= 0x20u) ? (I2c_ChannelInfo[Sequence].RxLength) : (0x16u));
              }
            }
            break;
            default:
              /* Do nothing */
              break;
            }
            /* Clear Rx Interrupt */
            Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1RRDY = I2C_SET_BIT;
          }
        }
        if ((I2C_CLEAR_BIT != (I2C_INTR_RDR & IntrStatus)) && (I2c_ChannelInfo[Sequence].RxLength >= 1U))
        {
          if (I2c_ChannelInfo[Sequence].RxLength > 1U)
          {
            /* Write data into TX FIFO */
            uint16 NumToCopy = 0U;
            NumToCopy = I2c_ReadFiFoArray(Reg_pt, I2c_ChannelInfo[Sequence].RxBuffer, I2c_ChannelInfo[Sequence].RxLength);
            I2c_ChannelInfo[Sequence].RxIndex += NumToCopy;
            I2c_ChannelInfo[Sequence].RxLength -= NumToCopy;
            I2c_ChannelInfo[Sequence].RxBuffer = &I2c_ChannelInfo[Sequence].RxBuffer[NumToCopy];
          }
          if (I2c_ChannelInfo[Sequence].RxLength == 1u)
          {
            I2c_ChannelInfo[Sequence].RxBuffer[0UL] = Reg_pt->DATA_reg.DATA_field.u8DATA;
            /* Increment the Index */
            ++I2c_ChannelInfo[Sequence].RxIndex;
            /* Set Tx length to O after all data transmitted to FIFO */
            I2c_ChannelInfo[Sequence].RxLength = 0U;
          }
          if (I2c_ChannelInfo[Sequence].RxLength == 0u)
          {
            if (Reg_pt->CON_reg.CON_field.u1STP != I2C_SET_BIT)
            {
              Reg_pt->CON_reg.CON_field.u1STP = I2C_SET_BIT;
            }
            Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
            I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
          }
        }
        else if ((I2C_CLEAR_BIT != (I2C_INTR_RDR & IntrStatus)) && (I2c_ChannelInfo[Sequence].RxLength == 0U))
        {
          if (Reg_pt->CON_reg.CON_field.u1STP != I2C_SET_BIT)
          {
            Reg_pt->CON_reg.CON_field.u1STP = I2C_SET_BIT;
          }
          Reg_pt->IRQENABLE_SET_reg.IRQENABLE_SET_field.u1BF_IE = I2C_SET_BIT;
          I2c_InternalState[HwUnitIndexVAr] = I2C_STOP;
        }
        else
        {
          /* do nothing */
        }
      }
           /* ========================================================== */
      /* STOP handling (replace SCD with ARDY)                      */
      /* ========================================================== */
      if (I2c_InternalState[HwUnitIndexVAr] == I2C_STOP)
      {
          /* STOP detected if bus is free OR ARDY asserted */
          if ((Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB == I2C_CLEAR_BIT) ||
              ((IntrRawStatus & I2C_INTR_ARDY) != 0U))
          {
              uint32 clearMask = 0U;

              if ((IntrRawStatus & I2C_INTR_ARDY) != 0U)
              {
                  clearMask |= I2C_INTR_ARDY;
              }

              #if I2C_DEBUG_STATS_ENABLED
              I2c_DebugStats[HwUnitIndexVAr].StopCount++;
              I2c_DebugStats[HwUnitIndexVAr].LastState = I2C_STOP;
              #endif

              if ((I2C_CLEAR_BIT != (I2C_INTR_BF & IntrStatus)) &&
                  (Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB == I2C_CLEAR_BIT))
              {
                  /* Normal STOP complete */
                  I2c_Stop(Reg_pt);
                  I2c_InternalState[HwUnitIndexVAr] = I2C_STOP_WAIT;
                  I2c_HwInfo[HwUnitIndexVAr].TimeoutCount = 0x0000;
                  I2c_HwInfo[HwUnitIndexVAr].IsStopWait = FALSE;
                  I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
                  I2c_HwInfo[HwUnitIndexVAr].CurrentPriority = I2C_NO_PRIORITY;

                  if ((I2c_ChannelInfo[Sequence].Result == I2C_SEQ_PENDING) ||
                      (I2c_ChannelInfo[Sequence].Result == I2C_SEQ_BUSY))
                  {
                      I2c_ChannelInfo[Sequence].Result = I2C_SEQ_OK;
                  }

                  I2c_HwInfo[HwUnitIndexVAr].HwStatus = I2C_IDLE;
                  I2c_DrvStatus.Status[HwUnitIndexVAr] = I2C_IDLE;
                  I2c_InternalState[HwUnitIndexVAr] = I2C_IDLE;

                  if (I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
                  {
                      I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(
                          Sequence, I2C_COMPLETE, I2c_ChannelInfo[Sequence].Result);
                  }

                  I2c_ChannelInfo[Sequence].IsQueued = FALSE;
              }
              else if ((Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB == I2C_CLEAR_BIT) &&
                       (I2c_ChannelInfo[Sequence].TxLength == 0U) &&
                       (I2c_ChannelInfo[Sequence].RxLength == 0U))
              {
                  if ((I2c_ChannelInfo[Sequence].Result == I2C_SEQ_PENDING) ||
                      (I2c_ChannelInfo[Sequence].Result == I2C_SEQ_BUSY))
                  {
                      I2c_ChannelInfo[Sequence].Result = I2C_SEQ_OK;
                  }
                  I2c_StopWait(HwUnitIndexVAr);
              }

              else
              {
                /* Do Nothing */
              }

              /* Clear ARDY if it was set */
              if (clearMask != 0U)
              {
                  Reg_pt->IRQSTATUS_reg.u32Register = clearMask;
              }
          }
        }
        else
        {
            if (I2c_InternalState[HwUnitIndexVAr] == I2C_IDLE)
            {
                if ((Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB == I2C_CLEAR_BIT) &&
                        (I2c_ChannelInfo[Sequence].TxLength == 0U) &&
                        (I2c_ChannelInfo[Sequence].RxLength == 0U))
                {
                    if ((I2c_ChannelInfo[Sequence].Result == I2C_SEQ_PENDING) ||
                        (I2c_ChannelInfo[Sequence].Result == I2C_SEQ_BUSY))
                    {
                        I2c_ChannelInfo[Sequence].Result = I2C_SEQ_OK;
                    }
                    I2c_StopWait(HwUnitIndexVAr);
                    I2c_ChannelInfo[Sequence].IsQueued = FALSE;
                }
            }
        }
    }
  }
}

static void I2c_StopWait(uint8 HwUnitIndexVAr)
{
    I2c_ChannelType Sequence;
    I2c_RegisterPtrType Reg_pt;
    I2c_SeqResultType finalResult;
    if (HwUnitIndexVAr < I2C_NUMBER_OF_HW_CHANNELS)
    {
        Reg_pt  = I2c_Config[HwUnitIndexVAr].BaseAddress;
        Sequence = I2c_HwInfo[HwUnitIndexVAr].CurrentSeq;
        /* Generate STOP and clear IRQs */
        I2c_Stop(Reg_pt);
        I2c_EnterCriticalSection();
        I2c_HwInfo[HwUnitIndexVAr].TimeoutCount    = 0U;
        I2c_HwInfo[HwUnitIndexVAr].IsStopWait      = FALSE;
        I2c_HwInfo[HwUnitIndexVAr].CurrentPriority = I2C_NO_PRIORITY;
        I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
        I2c_ChannelInfo[Sequence].IsQueued      = FALSE;
        /* Only BUSY/PENDING are normalized to OK.
        FAILED / CANCELLED / REJECT are preserved. */
        if ((I2c_ChannelInfo[Sequence].Result == I2C_SEQ_PENDING) ||
            (I2c_ChannelInfo[Sequence].Result == I2C_SEQ_BUSY))
        {
            I2c_ChannelInfo[Sequence].Result = I2C_SEQ_OK;
        }
        finalResult = I2c_ChannelInfo[Sequence].Result;
        /* HW/SW back to IDLE */
        I2c_HwInfo[HwUnitIndexVAr].HwStatus   = I2C_IDLE;
        I2c_DrvStatus.Status[HwUnitIndexVAr]  = I2C_IDLE;
        I2c_InternalState[HwUnitIndexVAr]     = I2C_IDLE;
        I2c_ExitCriticalSection();
        /* Notify application outside critical section */
        if (I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback != NULL)
        {
            I2c_ChannelConfig[Sequence].I2C_EndNotificationCallback(
                Sequence,
                (finalResult == I2C_SEQ_FAILED) ? I2C_BUSY : I2C_COMPLETE,
                finalResult);
        }
    }
}


/*============================================================================
**
** Function Name    :   I2c_Stop
**
** Visibility       :   Private
**
** Description      :   This function Sends the Stop signal.
**
** Invocation       :   ISR.
**
** Inputs           :   I2c_RegisterPtrType Reg_pt: Register Pointer
**
** Outputs          :   None
**
** Critical Section :   NA
**
**==========================================================================*/
#define I2C_STOP_BIT_SET  0x0002u
static void I2c_Stop(I2c_RegisterPtrType Reg_pt)
{
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1AERR = I2C_SET_BIT;
    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1ARDY_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1ARDY = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1RRDY_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1RRDY = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1XRDY_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XRDY = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1XUDF_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XUDF = I2C_SET_BIT; 

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1NACK_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1NACK = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1AL_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1AL = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1XDR_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1XDR = I2C_SET_BIT;

    Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1RDR_IE = I2C_SET_BIT;
    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1RDR = I2C_SET_BIT;
	
	Reg_pt->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1BF_IE = I2C_SET_BIT;

    Reg_pt->IRQSTATUS_reg.IRQSTATUS_field.u1BF = I2C_SET_BIT;
	Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BF   = I2C_CLEAR_BIT;  

    Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR = I2C_CLEAR_BIT;
    Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XDR  = I2C_CLEAR_BIT;
    Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY = I2C_CLEAR_BIT;
    Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY = I2C_CLEAR_BIT;
    Reg_pt->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF = I2C_CLEAR_BIT;
    Reg_pt->IRQSTATUS_RAW_reg.u32Register = I2C_CLEAR_BIT;
    (void)Reg_pt->IRQSTATUS_RAW_reg.u32Register;

}

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
** Critical Section :  Yes
**
**==========================================================================*/
I2c_StatusType I2c_GetStatus(uint8 HwUnitIndex)
{
    I2c_StatusType ret_status;
    /* CS Start */
    I2c_EnterCriticalSection();
    ret_status = I2c_DrvStatus.Status[HwUnitIndex];
    I2c_ExitCriticalSection();
    /* CS End */
    return (ret_status);
}

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
**                     I2C_SEQ_BUSY      : Sequence BUSY.
**                     I2C_SEQ_QUEUED    : Sequence Queued.
**                     I2C_SEQ_FAILED    : Sequence Failed.
**                     I2C_SEQ_CANCELLED : Sequence Cancelled.
** Critical Section :  Yes
**
**==========================================================================*/
I2c_SeqResultType I2c_GetSequenceResult(I2c_SequenceType Sequence)
{
    I2c_SeqResultType ret_result = I2C_SEQ_RESULT_UNDEFINED;
    /* CS Start */
    if(I2C_NUMBER_OF_SW_CHANNELS > Sequence)
    {
        I2c_EnterCriticalSection();
        ret_result = I2c_ChannelInfo[Sequence].Result;
        I2c_ExitCriticalSection();
    }
    /* CS End */
    return (ret_result);
}

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
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void I2c_Cancel(I2c_SequenceType Sequence )
{
    if(Sequence < I2C_NUMBER_OF_SW_CHANNELS)
    {
        /* CS Start */
        I2c_EnterCriticalSection();
        /* For I2c, Sequence and Channel are same */
        if(I2c_ChannelInfo[Sequence].Result == I2C_SEQ_QUEUED)
        {
            I2c_ChannelInfo[Sequence].Result = I2C_SEQ_CANCELLED;
            I2c_ChannelInfo[Sequence].IsQueued = FALSE;
        }
        /* Else, if busy, it shall complete the sequence. */
        /* Any other state, no need to cancel */
        I2c_ExitCriticalSection();
        /* CS End */
    }
}

/*============================================================================
**
** Function Name    :   I2c_Disable
**
** Visibility       :   Public
**
** Description      :   This function disables a particular I2C HW unit at
**                      runtime for diagnostics control. It refuses the request
**                      if the HW unit is BUSY or any SW sequence mapped to the
**                      unit is queued. On success, it uses the internal
**                      sequence-level helper to safely stop the block
**                      (masks IRQs, clears FIFOs/states).
**
** Invocation       :   Diagnostics application / service (e.g., DCM) or Application
**
** Inputs           :   uint8 HwUnitIndex  - I2C HW unit index to disable
**
** Outputs          :   Std_ReturnType
**                          E_OK      : Disable accepted and completed
**                          E_NOT_OK  : Invalid index, unit busy, or sequence queued
**
** Critical Section :   Yes
**
**==========================================================================*/
/* Public: disable a HW unit at runtime for diagnostics */
Std_ReturnType I2c_Disable(uint8 HwUnitIndex)
{
    Std_ReturnType ret_val = E_NOT_OK;
    uint8 anySeq;
    uint8 seq;
    
    if (HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS)
    {
        /* Reject if the HW is busy or anything is queued on this HW */
        if (I2c_DrvStatus.Status[HwUnitIndex] != I2C_BUSY)
        {
            ret_val = E_OK; /* Assume success, will be set to E_NOT_OK if queued sequence found */
            
            for (seq = 0u; seq < I2C_NUMBER_OF_SW_CHANNELS; seq++)
            {
                if ((I2c_ChannelConfig[seq].HwUnit == HwUnitIndex) && ((I2c_ChannelInfo[seq].IsQueued) != 0U))
                {
                    ret_val = E_NOT_OK; /* Don't silently cancel user traffic */
                    break; /* Exit loop early since we found a queued sequence */
                }
            }
            
            /* Only proceed with disable if no queued sequences found */
            if (ret_val == E_OK)
            {
                anySeq = I2c_FindAnySequenceForHw(HwUnitIndex);
                
                I2c_EnterCriticalSection();
                /* Use existing internal helper to shut the block cleanly */
                if (anySeq < I2C_NUMBER_OF_SW_CHANNELS)
                {
                    I2c_DisableSequence(HwUnitIndex, anySeq); /* sets driver state to UNINIT, masks IRQs, clears FIFO */
                }
                else
                {
                    /* No SW sequence mapped: still mark HW as UNINIT and mask interrupts */
                    I2c_RegisterPtrType unit = I2c_Config[HwUnitIndex].BaseAddress;
                    I2c_HwInfo[HwUnitIndex].CurrentPriority = I2C_NO_PRIORITY;
                    I2c_HwInfo[HwUnitIndex].CurrentSeq = 0u;
                    I2c_HwInfo[HwUnitIndex].TimeoutCount = 0u;
                    I2c_HwInfo[HwUnitIndex].IsStopWait = FALSE;
                    I2c_HwInfo[HwUnitIndex].HwStatus = I2C_UNINIT;
                    I2c_DrvStatus.Status[HwUnitIndex] = I2C_UNINIT;
                    I2c_InternalState[HwUnitIndex] = I2C_UNINIT;
                    unit->CON_reg.CON_field.u1I2C_EN = I2C_CLEAR_BIT;
                    unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;
                    unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
                }
                I2c_ExitCriticalSection();
            }
        }
    }
    
    return ret_val;
}

/*============================================================================
**
** Function Name    :   I2c_Enable
**
** Visibility       :   Public
**
** Description      :   This function enables a particular I2C HW unit at
**                      runtime after a diagnostics disable. It asserts I2C_EN
**                      and then reinitializes the unit via the internal
**                      sequence-level helper to bring the driver/HW back to
**                      a known IDLE state.
**
** Invocation       :   Diagnostics application / service (e.g., DCM) or Application
**
** Inputs           :   uint8 HwUnitIndex  - I2C HW unit index to enable
**
** Outputs          :   Std_ReturnType
**                          E_OK      : Enable accepted and completed
**                          E_NOT_OK  : Invalid index
**
** Critical Section :   Yes
**
**==========================================================================*/
/* Public: enable a HW unit at runtime for diagnostics */
Std_ReturnType I2c_Enable(uint8 HwUnitIndex)
{
    Std_ReturnType ret_val = E_NOT_OK;
    I2c_RegisterPtrType base;
    uint8 anySeq=0u;

    if (HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS)
    {
        base = I2c_Config[HwUnitIndex].BaseAddress;
        anySeq = I2c_FindAnySequenceForHw(HwUnitIndex);
        I2c_EnterCriticalSection();
        /* Bring module out of disable first */
        base->CON_reg.CON_field.u1I2C_EN = 1u; /* required before calling internal Enable */  /* :contentReference[oaicite:11]{index=11} */
        if (anySeq < I2C_NUMBER_OF_SW_CHANNELS)
        {
            I2c_EnableSequence(HwUnitIndex, anySeq); /* clears/sets masks & resets SW/HW states to IDLE */
        }
        else
        {
            /* No mapped sequence: just reinitialise HW/SW state */
            I2c_HwInfo[HwUnitIndex].CurrentPriority = I2C_NO_PRIORITY;
            I2c_HwInfo[HwUnitIndex].CurrentSeq = 0u;
            I2c_HwInfo[HwUnitIndex].TimeoutCount = 0u;
            I2c_HwInfo[HwUnitIndex].IsStopWait = FALSE;
            I2c_HwInfo[HwUnitIndex].HwStatus = I2C_IDLE;
            I2c_DrvStatus.Status[HwUnitIndex] = I2C_IDLE;
            I2c_InternalState[HwUnitIndex] = I2C_IDLE;
        } 
        I2c_ExitCriticalSection();

        ret_val = E_OK;
    }

    return ret_val;
}

/*============================================================================
**
** Function Name    :   I2c_FindAnySequenceForHw
**
** Visibility       :   Static
**
** Description      :   Utility to obtain a valid SW sequence mapped to the
**                      given HW unit. Used to supply a sequence parameter for
**                      sequence-level internal helpers. If multiple sequences
**                      map to the HW unit, the first match is returned. If no
**                      mapping exists, 0u is returned as a safe default.
**
** Invocation       :   I2c_Disable, I2c_Enable
**
** Inputs           :   uint8 hw  - I2C HW unit index
**
** Outputs          :   uint8     - SW sequence index associated with the HW unit
**
** Critical Section :   No
**
**==========================================================================*/
/* Find any SW sequence mapped to this HW unit (for housekeeping in static helpers) */
static uint8 I2c_FindAnySequenceForHw(uint8 hw)
{
    uint8 seq;
    uint8 ret_val = I2C_NUMBER_OF_SW_CHANNELS; /* Fallback: safe default; helpers guard bounds */
    
    for (seq = 0u; seq < I2C_NUMBER_OF_SW_CHANNELS; seq++)
    {
        if (I2c_ChannelConfig[seq].HwUnit == hw) 
        {
            ret_val = seq;
            break; /* Exit loop early since we found the sequence */
        }
    }
    
    return ret_val;
}


/*============================================================================
**
** Function Name    :   I2c_DisableSequence
**
** Visibility       :   Private
**
** Description      :   This function disables only a particular SCB module.
**
** Invocation       :   I2c_FreeBus
**
** Inputs           :   uint8 sequence, uint8 hw_index
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

static void  I2c_DisableSequence(uint8 hw_index, uint8 sequence)
{
    if(I2C_NUMBER_OF_HW_CHANNELS > hw_index)
    {
        I2c_RegisterPtrType I2c_unit = NULL;
        I2c_unit = I2c_Config[hw_index].BaseAddress;
        I2c_HwInfo[hw_index].CurrentPriority = I2C_NO_PRIORITY;
        I2c_HwInfo[hw_index].CurrentSeq = 0;
        I2c_HwInfo[hw_index].TimeoutCount = 0x0000;
        I2c_HwInfo[hw_index].IsStopWait = FALSE;
        I2c_HwInfo[hw_index].HwStatus = I2C_UNINIT;
        I2c_DrvStatus.Status[hw_index] = I2C_UNINIT;
        I2c_InternalState[hw_index] = I2C_UNINIT;        
        /* Disable I2C */
        I2c_unit->CON_reg.CON_field.u1I2C_EN =  I2C_CLEAR_BIT; 

        I2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;
        I2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;
    
        if(I2C_NUMBER_OF_SW_CHANNELS > sequence)
        {
            I2c_ChannelInfo[sequence].SlaveAddress = 0;
            I2c_ChannelInfo[sequence].TxBuffer = NULL;
            I2c_ChannelInfo[sequence].RxBuffer = NULL;
            I2c_ChannelInfo[sequence].TxLength = 0;
            I2c_ChannelInfo[sequence].TxIndex = 0;
            I2c_ChannelInfo[sequence].RxLength = 0;
            I2c_ChannelInfo[sequence].RxIndex = 0;
            I2c_ChannelInfo[sequence].Result = I2C_SEQ_OK;
            I2c_ChannelInfo[sequence].IsRepeatStart = FALSE;
            I2c_ChannelInfo[sequence].IsQueued = FALSE;
        }

    }
}

/*============================================================================
**
** Function Name    :   I2c_EnableSequence
**
** Visibility       :   Private
**
** Description      :   This function enables only a particular SCB module.
**
** Invocation       :   I2c_FreeBus.
**
** Inputs           :   uint8 sequence, uint8 hw_index
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

static void  I2c_EnableSequence(uint8 hw_index, uint8 sequence)
{
    I2c_RegisterPtrType i2c_unit= NULL; /* i2c register structure */
    /* I2C Port Settings shall be done in port configurations */
    if(I2C_NUMBER_OF_HW_CHANNELS > hw_index)
    {
        i2c_unit = I2c_Config[hw_index].BaseAddress; /* getting base address from configuration */
        /* add address ready from the irqstatus raw register */ 
        /* i2c controller own address setting - required when we are activting as slave */
        i2c_unit->OA_reg.OA_field.u10OA = I2C_CLEAR_BIT;
        i2c_unit->CON_reg.CON_field.u1MST = (I2c_Config[hw_index].I2C_Mode & 0x00000002U) >> 1U;
        i2c_unit->CON_reg.CON_field.u1TRX = I2C_SET_BIT;
        /* configuring I2C in normal mode (0) for STB mode (1) */
        i2c_unit->CON_reg.CON_field.u1STB = I2C_CLEAR_BIT; 
        /* Slave Address setting 7-bit slave addressing */
        i2c_unit->CON_reg.CON_field.u1XSA = I2C_CLEAR_BIT; /* 7-bit addressing selection (0) and (1) for 10-bit addressing */
        /* Clear TX FIFO*/
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = I2C_CLEAR_BIT;
        /* Clear RX FIFO*/
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_SET_BIT;
        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_CLEAR_BIT;
        /* Noise filter settings - are controlled internally */
        /* Enable I2C Module */
        /*Clear Interrupt requests*/
        i2c_unit->IRQENABLE_SET_reg.u32Register = I2C_CLEAR_BIT;
        i2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_INT_ALL;
        i2c_unit->IRQENABLE_CLR_reg.u32Register = I2C_CLEAR_BIT;
        i2c_unit->IRQSTATUS_RAW_reg.u32Register = I2C_CLEAR_BIT;
        /* clear the interrupts - all is done in this register */
        i2c_unit->IRQSTATUS_reg.u32Register = I2C_INT_ALL;


        I2c_HwInfo[hw_index].HwStatus = I2C_IDLE;
        I2c_DrvStatus.Status[hw_index] = I2C_IDLE;
        I2c_InternalState[hw_index] = I2C_IDLE;
   
        if(I2C_NUMBER_OF_SW_CHANNELS > sequence)
        {
            I2c_ChannelInfo[sequence].SlaveAddress = 0;
            I2c_ChannelInfo[sequence].TxBuffer = NULL;
            I2c_ChannelInfo[sequence].RxBuffer = NULL;
            I2c_ChannelInfo[sequence].TxLength = 0;
            I2c_ChannelInfo[sequence].TxIndex = 0;
            I2c_ChannelInfo[sequence].RxLength = 0;
            I2c_ChannelInfo[sequence].RxIndex = 0;
            I2c_ChannelInfo[sequence].Result = I2C_SEQ_OK;
            I2c_ChannelInfo[sequence].IsRepeatStart = FALSE;
            I2c_ChannelInfo[sequence].IsQueued = FALSE;
            I2c_BusBusyState[sequence].WholeNetworkStatus = I2C_IDLE; /* added */
            I2c_BusBusyState[sequence].BusBusyTimeout = 0u; 
        }

    }
}

/*============================================================================
**
** Function Name    :   I2c_FreeBus
**
** Visibility       :   Private
**
** Description      :   This function is called upon to provide the recovery 
**                      on bus.
**
** Invocation       :   I2c_Complete.
**
** Inputs           :   uint8 sequence, uint8 hw_index
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void I2c_FreeBus(uint8 hw_index, uint8 sequence)
{
    I2c_RegisterPtrType i2c_unit= NULL; /* i2c register structure */
    i2c_unit = I2c_Config[(I2c_ChannelConfig[sequence].HwUnit)].BaseAddress;
    I2c_DisableSequence(hw_index, sequence);
    i2c_unit->SYSC_reg.sysc_field.u1SRST = I2C_SET_BIT;
    i2c_unit->CON_reg.CON_field.u1I2C_EN = I2C_SET_BIT;
    I2c_EnableSequence(hw_index, sequence); 
}

/*============================================================================
**
** Function Name    :   I2c_MasterTransferComplete
**
** Visibility       :   Private
**
** Description      :   This function disables the I2c Communication once the
**                      transmission is over.
**
** Invocation       :   ISR.
**
** Inputs           :   I2c_RegisterPtrType Reg_pt: Register Pointer
**
** Outputs          :   None
**
** Critical Section :   NA
**
**==========================================================================*/
static void I2c_MasterTransferComplete(I2c_RegisterPtrType base, uint8 sequence)
{
    uint8 hw_index = I2c_ChannelConfig[sequence].HwUnit;
    (void)hw_index;
    base->CON_reg.CON_field.u1I2C_EN = I2C_CLEAR_BIT;
    /* Disable the interrupt source for master operation */
    /* Disable Rx Interrupt Mask */
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1RRDY_IE = I2C_SET_BIT;
    /* Disable Tx Interrupt Mask */
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1XRDY_IE = I2C_SET_BIT;
    /* Disable Arbitration loss mask bit */
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1AL_IE = I2C_SET_BIT;
    /* Disable Bus Access error mask bit */
    /* Disable NACK mask bit to check on bus busy timeouts */
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1NACK_IE = I2C_SET_BIT;
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1XUDF_IE = I2C_SET_BIT;
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1AERR_IE  = I2C_SET_BIT;
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1ROVR_IE  = I2C_SET_BIT;
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1RDR_IE   = I2C_SET_BIT;
    base->IRQENABLE_CLR_reg.IRQENABLE_CLR_field.u1BF_IE    = I2C_SET_BIT;
    /* Clear RX FIFO from remaining data and level interrupt source */
    base->BUF_reg.BUF_field.u1RXFIFO_CLR = I2C_SET_BIT;
    /* Clear Rx Interrupt */
    base->IRQSTATUS_reg.IRQSTATUS_field.u1RRDY = I2C_SET_BIT;
    /* Single Master - internal device busy as well as the entire bus */
    if(hw_index < I2C_NUMBER_OF_HW_CHANNELS )
    {
        if(I2c_Config[hw_index].MasterSetting == I2C_SINGLE_MASTER)
        {
            if(base->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB != I2C_CLEAR_BIT)
            {
                /* free the bus */
                I2c_FreeBus(hw_index, sequence);   
                /* notification will be done after exiting the critical section */       
            }
        }
        /* Multi Master - internal device not busy but the entire bus busy */
        if(I2c_Config[hw_index].MasterSetting == I2C_MULTI_MASTER)
        {
            if((base->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB != I2C_CLEAR_BIT) && (I2c_HwInfo[hw_index].HwStatus == I2C_IDLE))
            {
                /* notification will be done after exiting the critical section */       
                /* not giving the free bus since we are not the master */     
            }
            if((base->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB != I2C_CLEAR_BIT) && (I2c_HwInfo[hw_index].HwStatus == I2C_BUSY))
            {
                /* free the bus */
                I2c_FreeBus(hw_index, sequence);  
                /* notification will be done after exiting the critical section */ 
            }
        }
    }
}

static void I2CControllerIntEnableEx(I2c_RegisterPtrType baseAddr, uint32 intFlag)
{
    I2c_RegisterPtrType i2cRegs = baseAddr;
    uint32 i2cRegValue = i2cRegs->IRQENABLE_SET_reg.u32Register;
    i2cRegValue |= intFlag;
    i2cRegs->IRQENABLE_SET_reg.u32Register = i2cRegValue;
}

static void I2CControllerIntDisableEx(I2c_RegisterPtrType baseAddr, uint32 intFlag)
{
    I2c_RegisterPtrType i2cRegs = baseAddr;
    i2cRegs->IRQENABLE_CLR_reg.u32Register = intFlag;
}

static void I2CControllerIntClearEx(I2c_RegisterPtrType baseAddr, uint32 intFlag)
{
    I2c_RegisterPtrType i2cRegs = baseAddr;
    i2cRegs->IRQSTATUS_reg.u32Register = intFlag;
}

boolean I2C_GetStatusOfSDALine(uint8 hw)
{
    boolean status = FALSE;
    uint32 I2C_PortPin_SDA = 0u;
    uint32 I2C_PortPin_SCL = 0u;
    uint8 index = 0u;

    if(I2C_NUMBER_OF_HW_CHANNELS > hw)
    {
        for(index = 0u; index < I2C_NUMBER_OF_FREEBUS_CHANNELS; index++)
        {
            if(I2C_BusFreeConf[index].HwUnit == hw)
            {
                I2C_PortPin_SDA = (I2C_BusFreeConf[index].Instance * PORT_MAX_PIN_ID) + I2C_BusFreeConf[index].I2C_PortPinSda;
                I2C_PortPin_SCL = (I2C_BusFreeConf[index].Instance * PORT_MAX_PIN_ID) + I2C_BusFreeConf[index].I2C_PortPinScl;
                /* Configuring I2C lines as Dio */
                Pinmux_config(I2C_BusFreeConf[index].PinMux_I2C_To_DioIn_Cfg, I2C_BusFreeConf[index].PinmuxInstance);

                Port_SetPinDirection(I2C_PortPin_SDA, PORT_PIN_IN);
                Port_SetPinDirection(I2C_PortPin_SCL, PORT_PIN_IN);

                I2c_EnterCriticalSection();
                if((Dio_ReadChannel(I2C_PortPin_SDA) == STD_LOW) && (Dio_ReadChannel(I2C_PortPin_SCL) == STD_HIGH))
                {
                    status = TRUE;
                }
                I2c_ExitCriticalSection();
                Pinmux_config(I2C_BusFreeConf[index].PinMux_Dio_To_I2C_Cfg, I2C_BusFreeConf[index].PinmuxInstance);
            }
            
        }
    }
    return status;
}
/*============================================================================
**
** Function Name    :   I2c_PrepareReadTransfer
**
** Visibility       :   Static
**
** Description      :   This function prepares the HW for controller receive
**                      mode for a read transaction.
**
** Invocation       :   I2c_StartTransfer
**
** Inputs           :   I2c_RegisterPtrType I2cUnitPtr : Register pointer
**                      uint8 HwUnitIndex              : HW unit index
**                      I2c_SequenceType Sequence      : Sequence/Channel ID
**
** Outputs          :   I2c_StatusType : next receive state
**
** Critical Section :   No
**
**==========================================================================*/
static I2c_StatusType I2c_PrepareReadTransfer(I2c_RegisterPtrType I2cUnitPtr, uint8 HwUnitIndex, I2c_SequenceType Sequence)
{
  I2c_StatusType next_state = I2C_BUSY;

  if ((I2cUnitPtr != NULL) &&
      (HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS) &&
      (Sequence < I2C_NUMBER_OF_SW_CHANNELS))
  {
    if (I2c_ChannelInfo[Sequence].RxLength >= 2U)
    {
      I2cUnitPtr->BUF_reg.BUF_field.u6RXTRSH =
          ((I2c_ChannelInfo[Sequence].RxLength <= I2C_FIFO_SIZE) ?
              (I2c_ChannelInfo[Sequence].RxLength) : (I2C_RX_LENGTH));
      next_state = I2C_RX_STATE_1;
    }
    else
    {
      I2cUnitPtr->BUF_reg.BUF_field.u6RXTRSH = I2C_CLEAR_BIT;
      next_state = I2C_RX_STATE_0;
    }

    I2C_RxDataCountSet(I2cUnitPtr, Sequence);
    I2cUnitPtr->CON_reg.CON_field.u1MST =
        (I2c_Config[HwUnitIndex].I2C_Mode & 0x00000002UL) >> 1UL;
    I2cUnitPtr->CON_reg.CON_field.u1TRX = I2C_CLEAR_BIT;
    I2cUnitPtr->SA_reg.SA_field.u10SA = I2c_ChannelInfo[Sequence].SlaveAddress;
  }

  return next_state;
}
/*============================================================================
**
** Function Name    :   I2c_TrySlaveBusRecovery
**
** Visibility       :   Static
**
** Description      :   This function attempts to recover the I2C bus when a
**                      slave device is holding the bus (SDA stuck low while
**                      SCL is high).
**
** Invocation       :   I2c_MainFunction (timeout handling and bus-busy timeout
**                      paths)
**
** Inputs           :   uint8 hwIndex : Hardware channel index
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void I2c_TrySlaveBusRecovery(uint8 hwIndex)
{
  if (hwIndex < I2C_NUMBER_OF_HW_CHANNELS)
  {
    if (I2C_GetStatusOfSDALine(hwIndex) == TRUE)
    {
      (void)I2c_FreeSlaveBus(hwIndex);
    }
  }
}
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
Std_ReturnType I2c_SyncTransmit(I2c_SequenceType Sequence)
{
    Std_ReturnType ret_val = E_NOT_OK;
    I2c_RegisterPtrType i2c_unit = NULL;
    uint8 HwUnitIndex;
    uint32 timeout;
    uint8 errorCode = 0U;
    uint32 ier_saved = 0U;

    /* ------------------- Validate inputs ------------------- */
    if (Sequence < I2C_NUMBER_OF_SW_CHANNELS)
    {
        HwUnitIndex = I2c_ChannelConfig[Sequence].HwUnit;
        
        if (HwUnitIndex < I2C_NUMBER_OF_HW_CHANNELS)
        {
            i2c_unit = I2c_Config[HwUnitIndex].BaseAddress;

            if (I2c_DrvStatus.Status[HwUnitIndex] != I2C_UNINIT)
            {
                if ((I2c_ChannelInfo[Sequence].TxLength != 0U) ||
                    (I2c_ChannelInfo[Sequence].RxLength != 0U))
                {
                    /* ------------------- Busy check ------------------- */
                    if ((I2c_HwInfo[HwUnitIndex].HwStatus == I2C_IDLE) &&
                        (i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB != 1U))
                    {
                        /* ------------------- Quiesce async + prepare polling ------------------- */
                        ier_saved = i2c_unit->IRQENABLE_SET_reg.u32Register;   /* save current enables */
                        i2c_unit->IRQENABLE_CLR_reg.u32Register = 0xFFFFFFFFu;        /* mask all IRQ sources */

                        I2c_EnterCriticalSection();
                        I2c_HwInfo[HwUnitIndex].HwStatus = I2C_BUSY;                   /* block async submissions */
                        I2c_DrvStatus.Status[HwUnitIndex]     = I2C_BUSY;
                        I2c_HwInfo[HwUnitIndex].CurrentSeq    = Sequence;
                        I2c_HwInfo[HwUnitIndex].CurrentPriority = I2c_ChannelConfig[Sequence].SeqPriority;
                        I2c_ChannelInfo[Sequence].Result      = I2C_SEQ_PENDING;
                        I2c_ChannelInfo[Sequence].IsQueued = FALSE;
                        I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
                        I2c_ExitCriticalSection();

                        /* ------------------- Reset and configure ------------------- */
                        i2c_unit->CON_reg.u32Register = 0U;
                        i2c_unit->CON_reg.CON_field.u1I2C_EN = 0U;
                        i2c_unit->CON_reg.CON_field.u1STB    = 0U;  /* normal mode */

                        /* Clear FIFOs */
                        i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = 1U; i2c_unit->BUF_reg.BUF_field.u1TXFIFO_CLR = 0U;
                        i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = 1U; i2c_unit->BUF_reg.BUF_field.u1RXFIFO_CLR = 0U;

                        i2c_unit->IRQSTATUS_reg.u32Register = i2c_unit->IRQSTATUS_RAW_reg.u32Register;

                        /* Set minimal FIFO thresholds for polling (one-byte granularity) */
                        i2c_unit->BUF_reg.BUF_field.u6TXTRSH = 0U;
                        i2c_unit->BUF_reg.BUF_field.u6RXTRSH = 0U;

                        /* Configure bus speed */
                        I2C_SetDataRate(Sequence);

                        /* Enable module */
                        i2c_unit->CON_reg.CON_field.u1I2C_EN = 1U;

                        /* ========================================================== */
                        /* STEP 1: Transmit phase (write)                             */
                        /* ========================================================== */
                        if (I2c_ChannelInfo[Sequence].TxLength > 0U)
                        {
                            I2CDataCountSet(i2c_unit, Sequence);

                            /* Setup slave addr (write) */
                            i2c_unit->SA_reg.SA_field.u10SA = I2c_ChannelInfo[Sequence].SlaveAddress;
                            i2c_unit->CON_reg.CON_field.u1MST = 1U;
                            i2c_unit->CON_reg.CON_field.u1TRX = 1U; /* Write mode */

                            /* Clear ARDY before starting */
                            i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1ARDY = 1U;

                            /* START condition */
                            i2c_unit->CON_reg.CON_field.u1STT = 1U;

                            while ((I2c_ChannelInfo[Sequence].TxLength > 0U) && (errorCode == 0U))
                            {
                                timeout = I2C_SYNC_TIMEOUT;
                                while ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XRDY == 0U) &&
                                       (i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF == 0U) &&
                                       (--timeout > 0U))
                                {
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK) != 0U)
                                    {
                                        errorCode = I2C_E_NACK;
                                        break;
                                    }
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL) != 0U)
                                    {
                                        errorCode = I2C_E_AL;
                                        break;
                                    }
                                }

                                if ((timeout == 0U) && (errorCode == 0U))
                                {
                                    errorCode = I2C_E_TIMEOUT;
                                    break;
                                }

                                if (errorCode == 0U)
                                {
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1XUDF) != 0U)
                                    {
                                        i2c_unit->DATA_reg.DATA_field.u8DATA = *I2c_ChannelInfo[Sequence].TxBuffer++;
                                        I2c_ChannelInfo[Sequence].TxLength--;
                                        i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1XUDF = 1U; /* clear XUDF */
                                        continue;
                                    }

                                    /* Normal XRDY path */
                                    i2c_unit->DATA_reg.DATA_field.u8DATA = *I2c_ChannelInfo[Sequence].TxBuffer++;
                                    I2c_ChannelInfo[Sequence].TxLength--;

                                    /* Clear XRDY */
                                    i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1XRDY = 1U;
                                }
                            }

                            /* Wait ARDY after Tx */
                            if (errorCode == 0U)
                            {
                                timeout = I2C_SYNC_TIMEOUT;
                                while ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY == 0U) && (--timeout > 0U))
                                {
                                    /* Wait */
                                }
                                if (timeout == 0U)
                                {
                                    errorCode = I2C_E_TIMEOUT;
                                }
                                else
                                {
                                    i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1ARDY = 1U;
                                }
                            }
                        }

                        /* ========================================================== */
                        /* STEP 2: Receive phase (read, possibly with repeated START) */
                        /* ========================================================== */
                        if ((I2c_ChannelInfo[Sequence].RxLength > 0U) && (errorCode == 0U))
                        {
                            /* Program Rx count */
                            i2c_unit->CNT_reg.CNT_field.u16DCOUNT = I2c_ChannelInfo[Sequence].RxLength;

                            /* Setup slave addr (read) */
                            i2c_unit->SA_reg.SA_field.u10SA = I2c_ChannelInfo[Sequence].SlaveAddress;
                            i2c_unit->CON_reg.CON_field.u1MST = 1U;
                            i2c_unit->CON_reg.CON_field.u1TRX = 0U;  /* Read mode */

                            /* Clear ARDY before repeated start */
                            i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1ARDY = 1U;

                            /* Repeated START */
                            i2c_unit->CON_reg.CON_field.u1STT = 1U;

                            i2c_unit->CON_reg.CON_field.u1STP = 1U;  /* STOP after read */

                            while ((I2c_ChannelInfo[Sequence].RxLength > 0U) && (errorCode == 0U))
                            {
                                timeout = I2C_SYNC_TIMEOUT;
                                while ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1RRDY == 0U) &&
                                       (--timeout > 0U))
                                {
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK) != 0U)
                                    {
                                        errorCode = I2C_E_NACK;
                                        break;
                                    }
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL) != 0U)
                                    {
                                        errorCode = I2C_E_AL;
                                        break;
                                    }
                                    if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ROVR) != 0U)
                                    {
                                        errorCode = I2C_E_ROVR;
                                        break;
                                    }
                                }

                                if (timeout == 0U)
                                {
                                    errorCode = I2C_E_TIMEOUT;
                                }

                                if (errorCode == 0U)
                                {
                                    *I2c_ChannelInfo[Sequence].RxBuffer++ = i2c_unit->DATA_reg.DATA_field.u8DATA;
                                    I2c_ChannelInfo[Sequence].RxLength--;

                                    /* Clear RRDY */
                                    i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1RRDY = 1U;
                                }
                            }
                        }

                        /* ========================================================== */
                        /* STEP 3: Finalize (wait for bus free or STOP detected)     */
                        /* ========================================================== */
                        if (errorCode == 0U)
                        {
                            /* If this is write-only (no Rx), request STOP now */
                            if (I2c_ChannelInfo[Sequence].RxLength == 0U)
                            {
                                i2c_unit->CON_reg.CON_field.u1STP = 1U;  /* STOP after write */
                            }

                            timeout = I2C_SYNC_TIMEOUT;
                            while ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1BB == 1U) &&
                                   (--timeout > 0U))
                            {
                                if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1NACK) != 0U)
                                {
                                    errorCode = I2C_E_NACK;
                                    break;
                                }
                                if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AL) != 0U)
                                {
                                    errorCode = I2C_E_AL;
                                    break;
                                }
                            }
                            if (timeout == 0U)
                            {
                                errorCode = I2C_E_TIMEOUT;
                            }

                            /* Clear final ARDY if present */
                            if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1ARDY) != 0U)
                            {
                                i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1ARDY = 1U;
                            }

                            i2c_unit->IRQSTATUS_reg.u32Register = i2c_unit->IRQSTATUS_RAW_reg.u32Register;

                            /* Restore IRQ enables and channel state for async engine */
                            i2c_unit->IRQENABLE_SET_reg.u32Register = ier_saved;  /* re-enable saved IRQs */

                            I2c_EnterCriticalSection();
                            I2c_HwInfo[HwUnitIndex].HwStatus  = I2C_IDLE;
                            I2c_DrvStatus.Status[HwUnitIndex] = I2C_IDLE;
                            I2c_InternalState[HwUnitIndex]    = I2C_IDLE;
                            I2c_ChannelInfo[Sequence].IsQueued      = FALSE;
                            I2c_ChannelInfo[Sequence].IsRepeatStart = FALSE;
                            I2c_ChannelInfo[Sequence].Result = (errorCode == 0U) ? I2C_SEQ_OK : I2C_SEQ_FAILED;
                            I2c_ExitCriticalSection();
                        }

                        /* ========================================================== */
                        /* Final cleanup & return                                     */
                        /* ========================================================== */
                        if ((i2c_unit->IRQSTATUS_RAW_reg.IRQSTATUS_RAW_field.u1AERR) != 0U)
                        {
                            i2c_unit->IRQSTATUS_reg.IRQSTATUS_field.u1AERR = 1U;
                            /* non-fatal, just clear */
                        }

                        /* Update result for upper layer */
                        I2c_ChannelInfo[Sequence].Result = (errorCode == 0U) ? I2C_SEQ_OK : I2C_SEQ_FAILED;

                        /* Reset HW/SW states on success */
                        I2c_HwInfo[HwUnitIndex].HwStatus = I2C_IDLE;
                        I2c_DrvStatus.Status[HwUnitIndex] = I2C_IDLE;

                        if (errorCode != 0U)
                        {
                            I2c_Det_ReportError(I2C_SYNC_TRANSMIT, I2C_SEQ_FAILED);
                            ret_val = E_NOT_OK;
                        }
                        else
                        {
                            ret_val = E_OK;
                        }
                    }
                }
            }
        }
    }
    return ret_val;
}

/*============================================================================
**
** Function Name    : I2c_FreeSlaveBus
**
** Visibility       : Public
**
** Description      : This function is called upon to provide the recovery 
**                      on bus the slave bus.
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
Std_ReturnType I2c_FreeSlaveBus(uint8 hw_index)
{
    Std_ReturnType ret_val = E_NOT_OK;
    uint8 loop = 0u;
    uint16 ticks = 0u;
    uint8 index = 0u;
    uint16 idle_ticks = I2c_FreeBusTicks.Freebus_IdleTicks;
    uint32 I2C_PortPin_SDA = 0u;
    uint32 I2C_PortPin_SCL = 0u;
    I2C_BusFreeConfType *pBusFreeConf = NULL_PTR;

    if(hw_index < I2C_NUMBER_OF_HW_CHANNELS)
    {
        (void)I2c_Disable(hw_index);

        for (index = 0u; index < I2C_NUMBER_OF_FREEBUS_CHANNELS; index++)
        {
            if (I2C_BusFreeConf[index].HwUnit == hw_index)
            {
                pBusFreeConf = &I2C_BusFreeConf[index];
                I2C_PortPin_SDA = (pBusFreeConf->Instance * PORT_MAX_PIN_ID) + pBusFreeConf->I2C_PortPinSda;
                I2C_PortPin_SCL = (pBusFreeConf->Instance * PORT_MAX_PIN_ID) + pBusFreeConf->I2C_PortPinScl;
                /* Configuring I2C lines as Dio */
                Pinmux_config(pBusFreeConf->PinMux_I2C_To_DioOut_Cfg, pBusFreeConf->PinmuxInstance);
                ret_val = E_OK;
                break;
            }
        }

        if(ret_val == E_OK)
        {
            Port_SetPinDirection(I2C_PortPin_SDA, PORT_PIN_OUT);
            Port_SetPinDirection(I2C_PortPin_SCL, PORT_PIN_OUT);

            I2c_EnterCriticalSection();
            /* Generating 9 clock pulses on SCL line */
            for (loop = 0u; loop < I2C_FREEBUS_CLK_EDGES; loop++)
            {
                Dio_WriteChannel(pBusFreeConf->I2C_DioPinSda, STD_HIGH);
                for (ticks = 0u; ticks < idle_ticks; ticks++)
                {
                    /* do nothing */
                }
                Dio_WriteChannel(pBusFreeConf->I2C_DioPinScl, STD_HIGH);
                for (ticks = 0u; ticks < idle_ticks; ticks++)
                {
                    /* do nothing */
                }
                Dio_WriteChannel(pBusFreeConf->I2C_DioPinScl, STD_LOW);
            }
            Dio_WriteChannel(pBusFreeConf->I2C_DioPinSda, STD_LOW);
            Dio_WriteChannel(pBusFreeConf->I2C_DioPinScl, STD_HIGH);
            for (ticks = 0u; ticks < idle_ticks; ticks++)
            {
                /* do nothing */
            }
            Dio_WriteChannel(pBusFreeConf->I2C_DioPinSda, STD_HIGH);
            I2c_ExitCriticalSection();
            Pinmux_config(pBusFreeConf->PinMux_Dio_To_I2C_Cfg, pBusFreeConf->PinmuxInstance);
            (void)I2c_Enable(hw_index);
        }
    }
    return ret_val;
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

