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
*  File Name         :  LinUartIf.c                                          *
*  Module Short Name :  LinUartIf                                            *
*  Description       :  This file contains implementations of the Lin Driver *
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

/*****************************************************************************
*                               Include files                                *
******************************************************************************/

#include "Lin_UartIf.h"

/*****************************************************************************
*                              Global Variables                              *
******************************************************************************/

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
Lin_ConfigType* pLin_ConfigPtr = &Lin_Config;

/*****************************************************************************
*                               Local Variables                              *
******************************************************************************/

/**
* @brief        Store UART Checksum type
*/
static volatile boolean UART_ChecksumType;

/**
* @brief        Store UART data to send or receive
*/
static uint8 UART_Buffer[LIN_NUM_OF_CHANNELS][UART_MAX_BUFFER_LENGTH_U8];

/**
* @brief        Point to the next byte to send or receive in UART Buffers
*/
static volatile uint8 Lin_UartIf_BufferPtr[LIN_NUM_OF_CHANNELS];

/**
* @brief        Real sizes of UART Buffers
*/
static volatile uint8 Lin_UartIf_BufferLength[LIN_NUM_OF_CHANNELS];

/**
* @brief        Store Wakeup Flag
*/
static volatile uint8 Lin_UartIf_WakeupFlag[LIN_NUM_OF_CHANNELS];

/*****************************************************************************
*                          Local Function Prototypes                         *
******************************************************************************/

static void Lin_UartIf_PIDCalc(uint8 Channel, uint8 FrameID);
static uint32 Lin_UartIf_ChecksumCalc(uint8 Channel, Lin_FrameCsModelType checksumModel);
static void Lin_UartIf_CopyData(uint8 Channel, uint8* LinSduPtr);
static void Lin_UartIf_RxBuffFullInterruptHandler(uint8 Channel, uint32 BytesReceived);

void Lin_UartIf_RxMasterSendResponeIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
);

boolean Lin_UartIf_RxMasterSendSleepIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
);

void Lin_UartIf_RxSlaveSendResponeIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
);

Lin_StatusType Lin_UartIf_HeaderTransGetStatus
(
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus
);
Lin_StatusType Lin_UartIf_DataTransGetStatus
(
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus
);
Lin_StatusType Lin_UartIf_FinishTransGetStatus
(
    const uint8 Channel,
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus,
    uint8* LinSduPtr
);

/*****************************************************************************
*                               Local Functions                              *
******************************************************************************/

/*****************************************************************************
* @brief   Calculate Protected Identifier from the Frame ID.
* @details Calculate Protected Identifier from the Frame ID.
*
* @param[in]   Channel, FrameID - Frame ID.
* @param[out]  void.
*
* @return       void.
*
*
* @note         Internal driver function.
*
******************************************************************************/
static void Lin_UartIf_PIDCalc(uint8 Channel, uint8 FrameID)
{
    uint32 Temp1;
    uint32 Temp2;

    Temp1 = ((uint32)FrameID) & UART_FRAME_ID_MASK_U32;
    Temp2 = FrameID;
    /* Calculate parity bit P1 = !(ID1 ^ ID3 ^ ID4 ^ ID5) */
    Temp1 |= ((((Temp2 >> 1) ^ \
                   (Temp2 >> 3) ^ \
                   (Temp2 >> 4) ^ \
                   (Temp2 >> 5) \
                  )& ((uint32)1U) \
                 ) ^ ((uint32)1U) \
                ) << (uint32)7U;

    /* Calculate parity bit P0 = (ID0 ^ ID1 ^ ID2 ^ ID4) */
    Temp1 |= (((Temp2) ^ \
                  (Temp2 >> 1U) ^ \
                  (Temp2 >> 2U) ^ \
                  (Temp2 >> 4U) \
                 ) & ((uint32)1U) \
                ) << (uint32)6U;

    UART_Buffer[Channel][UART_PID_BYTE_OFFSET_U8] = (uint8)Temp1;
}

/******************************************************************************
* @brief   Calculate LIN Checksum.
* @details Calculate LIN Checksum.
*
* @param[in]   Channel, checksumModel.
* @param[out]  Checksum.
*
* @return       uint32.
*
* @note         Internal driver function.
*
******************************************************************************/
static uint32 Lin_UartIf_ChecksumCalc(uint8 Channel, Lin_FrameCsModelType checksumModel)
{
    uint32 Checksum = (uint32)0U;
    uint32 Carry = (uint32)0U;
    uint32 DataLen = (uint32)0U;
    uint32 Index = (uint32)0U;

    DataLen = ((uint32)Lin_UartIf_BufferLength[Channel]) - ((uint32)3U);
    /* Enhanced Model */
    if(LIN_ENHANCED_CS == checksumModel)
    {
        Checksum = (uint32)UART_Buffer[Channel][UART_PID_BYTE_OFFSET_U8];
    }

    for(Index = (uint32)0U; Index < DataLen; Index++)
    {
        Checksum += (uint32)UART_Buffer[Channel][UART_DATA_OFFSET_U8 + Index];
        Carry = Checksum >> (uint32)8U;
        Checksum = (Checksum & ((uint32)0xFFU)) + Carry;
    }

    Checksum = (~(Checksum)) & ((uint32)0xFFU);
    return Checksum;
}

/******************************************************************************
* @brief   Copy the data received from the UART data registers to LinSduPtr.
* @details This function shall copy the received data in the provided buffer
*          addressed by the LinSduPtr pointer parameter.
*
* @param[in]   Channel to be addressed.
* @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped UART Hardware receive buffer where the current SDU is stored
*
* @return       void.
*
*
* @note         Internal driver function.
*
******************************************************************************/
static void Lin_UartIf_CopyData(uint8 Channel, uint8* LinSduPtr)
{
    uint8 Index;
    uint8 BufferLength;

    BufferLength = (uint8)(Lin_UartIf_BufferLength[Channel] - (uint8)3U);

    for(Index = (uint8)0U; Index < BufferLength; Index++)
    {
        LinSduPtr[Index] = UART_Buffer[Channel][UART_DATA_OFFSET_U8 + Index];
    }
}

/******************************************************************************
* @brief   Interrupt handler for RX Data Register Full on UART.
* @details This function shall manage the RX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed, BytesReceived.
*
* @return       void.
*
* @implements Lin_UartIf_RxBuffFullInterruptHandler_Activity
*
* @note         Internal driver function.
*
******************************************************************************/
static void Lin_UartIf_RxBuffFullInterruptHandler(uint8 Channel, uint32 BytesReceived)
{
    uint8 Temp1;
    uint32 Lin_DataReg;
    uint8 BufferPtr;
    uint8 BufferLength;
    uint8 Lin_Command;
    boolean IsSleepFrame = (boolean)FALSE;

    /* Read the data register */   
    BufferLength = BytesReceived;
    BufferPtr = Lin_UartIf_BufferPtr[Channel];
    Lin_DataReg = UART_Buffer[Channel][BufferLength];

    /* Get Lin Frame Command */
    Lin_Command = Lin_TransmitHeaderCommand[Channel];
    /* Get the last transmitted byte */
    Temp1 = UART_Buffer[Channel][BufferPtr];

    /* Code Flow Error */
    if(BufferPtr >= BufferLength)
    {
        /* Code Flow Error */
    }

    /* The next byte has been received */
    else
    {
        switch(Lin_Command)
        {
            case LIN_TX_MASTER_RES_COMMAND:
                Lin_UartIf_RxMasterSendResponeIsrHandler(Channel, Temp1, BufferLength, Lin_DataReg, BufferPtr);
                break;
            /* Future Implementation
            case LIN_TX_SLEEP_COMMAND:
                IsSleepFrame = Lin_UartIf_RxMasterSendSleepIsrHandler(Channel, Temp1, BufferLength, Lin_DataReg, BufferPtr);
                break;
            */
            case LIN_TX_SLAVE_RES_COMMAND:
                Lin_UartIf_RxSlaveSendResponeIsrHandler(Channel, Temp1, BufferLength, Lin_DataReg, BufferPtr);
                break;
            /* Future Implementation
            case LIN_TX_SLAVE_TO_SLAVE_COMMAND:
                if((uint8)(Lin_DataReg & UART_DATA_8BITS_MASK_U32) != Temp1)
                {
                    Lin_LinChFrameErrorStatus[Channel] = LIN_BIT_ERROR;
                }
                else
                {
                    Lin_LinChFrameStatus[Channel] = LIN_TX_HEADER_COMPLETE_STATE;
                }
                break;
            */
            default:
                /* Code Flow Error */
                break;
        }
    }
    if((boolean)TRUE == IsSleepFrame)
    {
        /* Update Lin_TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
        Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
        /* Enable wake up detection */
    }
    /* Increase Buffer Pointer */
    Lin_UartIf_BufferPtr[Channel]++;
}

/******************************************************************************
* @brief   Interrupt handler for RX Data Register Full on UART.
* @details This function shall manage the RX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*
******************************************************************************/
void Lin_UartIf_RxMasterSendResponeIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
)
{
    /* The last byte has been received */
    if(BufferPtr == (BufferLength - (uint8)1))
    {
        Lin_LinChFrameStatus[Channel] = LIN_TX_COMPLETE_STATE;
    }
}

void Lin_UartIf_RxSlaveSendResponeIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
)
{
    uint8 Lin_FrameID;
    uint8 Lin_Checksum;
    /* Store received data */
    UART_Buffer[Channel][BufferPtr] = Lin_DataReg;
    ESciDrvDirection Direction = eSciDrvDirection_Receive;
    /* Update LIN channel frame operation status to LIN_RX_ONGOING_STATE */
    Lin_LinChFrameStatus[Channel] = LIN_RX_ONGOING_STATE;

    /* The last byte has been received */
    if(BufferPtr == (BufferLength - (uint8)1U))
    {
        Lin_FrameID = UART_Buffer[Channel][UART_PID_BYTE_OFFSET_U8];
        /* Checksum Error */
        switch(Lin_FrameID)
        {
            case UART_MASTER_REQUEST_DIAGNOSTIC_ID_U8:
            case UART_SLAVE_RESPONSE_DIAGNOSTIC_ID_U8:
                Lin_Checksum = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_CLASSIC_CS);
            break;
            default:
                if ((boolean)TRUE == UART_ChecksumType)
                {
                    /* Enhance checksum */
                    Lin_Checksum = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_ENHANCED_CS);
                }
                else
                {
                    /* Classic checksum */
                    Lin_Checksum = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_CLASSIC_CS);
                }
            break;
        }
        if(Lin_Checksum != (uint8)(Lin_DataReg))
        {
            /* Set LIN channel frame error status to LIN_CHECKSUM_ERROR */
            Lin_LinChFrameErrorStatus[Channel] = LIN_CHECKSUM_ERROR;
        }
        else
        {
            /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
            Lin_LinChFrameStatus[Channel] = LIN_RX_COMPLETE_STATE;
        }
    }
    else
    {
        /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
        SciDrv_SetupEB(Channel, Direction, &UART_Buffer[Channel][UART_MAX_BUFFER_LENGTH_U8], BufferLength);
        SciDrv_ASyncReceive(Channel);
        Lin_LinChFrameStatus[Channel] = LIN_RX_COMPLETE_STATE;
    }
    /* Update LIN channel frame operation status to LIN_TX_HEADER_COMPLETE_STATE */
    Lin_LinChFrameStatus[Channel] = LIN_TX_HEADER_COMPLETE_STATE;
}

#if 0
boolean Lin_UartIf_RxMasterSendSleepIsrHandler
(
    uint8 Channel,
    uint8 DataSent,
    uint8 BufferLength,
    uint32 Lin_DataReg,
    uint8 BufferPtr
)
{
    boolean IsSleepFrame = (boolean)FALSE;
    /* Verify received data */
    if((Lin_DataReg & UART_DATA_8BITS_MASK_U32) != DataSent)
    {
        /* Bit error detected */
        Lin_LinChFrameErrorStatus[Channel] = LIN_BIT_ERROR;
        IsSleepFrame = (boolean)TRUE;
    }
    else
    {
        /* The last byte has been received */
        if(BufferPtr == (BufferLength - (uint8)1))
        {
            /* Update Lin_aTransmitHeaderCommand value to LIN_TX_NO_COMMAND */
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
    
            /* Reset buffer length */
            Lin_UartIf_BufferLength[Channel] = (uint8)0U;
        }
        else
        {

        }
    }
    return IsSleepFrame;
}
#endif

/******************************************************************************
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header transmission.
 *
 ******************************************************************************/
Lin_StatusType Lin_UartIf_HeaderTransGetStatus
(
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus
)
{
    Lin_StatusType TempReturn = LIN_NOT_OK;

    switch(ChannelFrameError)
    {
        /* No error has occurred */
        case LIN_NO_ERROR:
            if((LIN_TX_SLAVE_TO_SLAVE_COMMAND == TransmitHeaderCommand) && (LIN_TX_HEADER_COMPLETE_STATE == LinChFrameStatus))
            {
                TempReturn = LIN_TX_OK;
            }
            else if((LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand) && (LIN_TX_HEADER_COMPLETE_STATE == LinChFrameStatus))
            {
                TempReturn = LIN_RX_NO_RESPONSE;
            }
            else
            {
                TempReturn = LIN_TX_BUSY;
            }
            break;
        /* Errors occurred */
        case LIN_BIT_ERROR:
            TempReturn = LIN_TX_HEADER_ERROR;
            break;
        default:
            TempReturn = LIN_NOT_OK;
            break;
    }
    return TempReturn;
}

/******************************************************************************
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 *
 ******************************************************************************/
Lin_StatusType Lin_UartIf_DataTransGetStatus
(
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus
)
{
    Lin_StatusType TempReturn = LIN_NOT_OK;

    switch(ChannelFrameError)
    {
        /* No error has occurred */
        case LIN_NO_ERROR:
            if((LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand) && (LIN_RX_ONGOING_STATE == LinChFrameStatus))
            {
                TempReturn = LIN_RX_BUSY;
            }
            else if ((LIN_TX_SLAVE_TO_SLAVE_COMMAND == TransmitHeaderCommand) && (LIN_TX_COMPLETE_STATE == LinChFrameStatus))
            {
                TempReturn = LIN_TX_OK;
            }
            else
            {
                TempReturn = LIN_TX_BUSY;
            }
            break;
        /* Errors occurred */
        case LIN_BIT_ERROR:
            TempReturn = LIN_TX_ERROR;
            break;
        case LIN_NOISE_ERROR:
            if(LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand)
            {
                TempReturn = LIN_RX_ERROR;
            }
            else
            {
                TempReturn = LIN_TX_ERROR;
            }
            break;
        case LIN_BUFFER_OVER_RUN_ERROR:
        case LIN_FRAMING_ERROR:
            TempReturn = LIN_RX_ERROR;
            break;
        default:
            TempReturn = LIN_NOT_OK;
            break;
    }
    return TempReturn;
}

/******************************************************************************
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 *
 ******************************************************************************/
Lin_StatusType Lin_UartIf_FinishTransGetStatus
(
    const uint8 Channel,
    uint8 ChannelFrameError,
    uint8 TransmitHeaderCommand,
    uint8 LinChFrameStatus,
    uint8* pLinSduPtr
)
{
    Lin_StatusType TempReturn = LIN_NOT_OK;

    switch(ChannelFrameError)
    {
        /* No error has occurred */
        case LIN_NO_ERROR:
            if(LIN_TX_COMPLETE_STATE == LinChFrameStatus)
            {
                TempReturn = LIN_TX_OK;
                Lin_UartIf_BufferLength[Channel] = (uint8)0U;
            }
            else if(LIN_RX_COMPLETE_STATE == LinChFrameStatus)
            {
                /* Copy the data from hardware buffer */
                Lin_UartIf_CopyData(Channel, pLinSduPtr);
                Lin_UartIf_BufferLength[Channel] = (uint8)0U;
                TempReturn = LIN_RX_OK;
            }
            else
            {
                /* Code Flow Error */
                TempReturn = LIN_NOT_OK;
            }
            break;
        /* Errors occurred */
        case LIN_NOISE_ERROR:
            if(LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand)
            {
                TempReturn = LIN_RX_ERROR;
            }
            else
            {
                TempReturn = LIN_TX_ERROR;
            }
            break;
        case LIN_CHECKSUM_ERROR:
        case LIN_BUFFER_OVER_RUN_ERROR:
        case LIN_FRAMING_ERROR:
            TempReturn = LIN_RX_ERROR;
            break;
        default:
            TempReturn = LIN_NOT_OK;
            break;
    }
    return TempReturn;
}

/*****************************************************************************
*                              Global Functions                              *
******************************************************************************/

/******************************************************************************
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
******************************************************************************/
Std_ReturnType Lin_UartIf_InitChannel(uint8 Channel)
{
    Std_ReturnType TmpReturn = (uint8)E_NOT_OK;
    ESciDrvAsyncMode SciAsyncMode = eSciDrvAsyncMode_Interrupt;
    Lin_EnterCriticalSection()
    {
        if((SciDrv_SetAsyncMode(Channel, SciAsyncMode) == E_OK) &&
            (SciDrv_EnableChn(Channel) == E_OK))
        {
            Lin_UartIf_WakeupFlag[Channel] = (uint8)FALSE;
            TmpReturn = E_OK;
        }
    }
    Lin_ExitCriticalSection()
    return TmpReturn;
}

/******************************************************************************
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the Lin_UART_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
******************************************************************************/
Std_ReturnType Lin_UartIf_SendHeader(uint8 Channel, Lin_PduType* PduInfoPtr)
{
    Std_ReturnType TmpReturn = (uint8)E_NOT_OK;
    ESciDrvDirection Direction = eSciDrvDirection_Transmit;

    Lin_EnterCriticalSection()
    {
        TmpReturn = SciDrv_Cancel(Channel, Direction);
    }
    Lin_ExitCriticalSection()

    /*Set up break length*/
    /* Lin_UartIf_SetBreakLength(Channel); */
    
    if((uint8)E_OK == TmpReturn)
    {
        /* Reset error status global flag */
        Lin_LinChFrameErrorStatus[Channel] = LIN_NO_ERROR;
        /* Set checksum type, use for interrupt */
        if (LIN_ENHANCED_CS == PduInfoPtr->Cs)
        {
            /* Update LIN Checksum type to LIN_ENHANCED_CS */
            UART_ChecksumType = (boolean)TRUE;
        }
        else
        {
            /* Update LIN Checksum type to LIN_CLASSIC_CS */
            UART_ChecksumType = (boolean)FALSE;
        }
        /* Set header status to TRUE if master wants to send the response frame */
        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_MASTER_RES_COMMAND;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
        }
        else if(LIN_SLAVE_RESPONSE == PduInfoPtr->Drc)
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLAVE_RES_COMMAND;
            Lin_LinChFrameStatus[Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
            SciDrv_SetupEB(Channel, Direction, &UART_Buffer[Channel][UART_MAX_BUFFER_LENGTH_U8], PduInfoPtr->Dl);
            SciDrv_ASyncReceive(Channel);
        }
        else
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLAVE_TO_SLAVE_COMMAND;
            Lin_LinChFrameStatus[Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
        }
        /* The buffer contains [sync byte, pid, data, checksum] */
        Lin_UartIf_BufferLength[Channel] = (uint8)(((uint8)3U) + ((PduInfoPtr->Dl > UART_MAX_DATA_LENGTH_U8) ? UART_MAX_DATA_LENGTH_U8 : PduInfoPtr->Dl));

        /* Write in the transmission buffer the synchronization byte and the PID */
        UART_Buffer[Channel][UART_SYNCH_BYTE_OFFSET_U8] = UART_SYNC_BYTE_U8;
        Lin_UartIf_PIDCalc(Channel, PduInfoPtr->Pid);

        /* Set Data Direction */
        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
        {
            /* Do not transmit header here because it's a master->slave frame
            the header will be transmitted together with the response when calling SendResponse function */
        }
        else
        {
            /* Transmit Header */
            /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
            Lin_UartIf_BufferPtr[Channel] = UART_SYNCH_BYTE_OFFSET_U8;

            Lin_EnterCriticalSection()
            {
                if((SciDrv_SetupEB(Channel, Direction, &UART_Buffer[Channel][UART_SYNCH_BYTE_OFFSET_U8], Lin_UartIf_BufferLength[Channel]) == E_OK) &&
                    (SciDrv_ASyncTransmit(Channel) == E_OK))
                {
                    TmpReturn = E_OK;
                }
            }
            Lin_ExitCriticalSection()
        }
    }
    return TmpReturn;
}

/******************************************************************************
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            void.
*
******************************************************************************/
void Lin_UartIf_SendResponse(uint8 Channel, Lin_PduType* PduInfoPtr)
{
    uint8 Lin_FrameID;
    uint8 Loop = (uint8)0U;
    ESciDrvDirection Direction = eSciDrvDirection_Transmit;

    /* Tx Buffer Preparation */
    /* Data */
    for(Loop = (uint8)0U; Loop < ((PduInfoPtr->Dl > UART_MAX_DATA_LENGTH_U8) ? UART_MAX_DATA_LENGTH_U8 : PduInfoPtr->Dl); Loop++)
    {
        UART_Buffer[Channel][UART_DATA_OFFSET_U8 + Loop] = PduInfoPtr->SduPtr[Loop];
    }

    /* Checksum */
    Lin_FrameID = PduInfoPtr->Pid;
    switch(Lin_FrameID)
    {
        case UART_MASTER_REQUEST_DIAGNOSTIC_ID_U8:
        case UART_SLAVE_RESPONSE_DIAGNOSTIC_ID_U8:
            UART_Buffer[Channel][Lin_UartIf_BufferLength[Channel] - ((uint8)1U)] = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_CLASSIC_CS);
        break;
        default:
            if ((boolean)TRUE == UART_ChecksumType)
            {
                /* Enhance checksum */
                UART_Buffer[Channel][Lin_UartIf_BufferLength[Channel] - ((uint8)1U)] = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_ENHANCED_CS);
                UART_ChecksumType = (boolean)TRUE;
            }
            else
            {
                /* Classic checksum */
                UART_Buffer[Channel][Lin_UartIf_BufferLength[Channel] - ((uint8)1U)] = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_CLASSIC_CS);
                UART_ChecksumType = (boolean)FALSE;
            }
        break;
    }
    /* Transmit Response */
    /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */

    Lin_UartIf_BufferPtr[Channel] = UART_SYNCH_BYTE_OFFSET_U8;
    Lin_EnterCriticalSection()
    {
        SciDrv_SetupEB(Channel, Direction, &UART_Buffer[Channel][UART_DATA_OFFSET_U8], Lin_UartIf_BufferLength[Channel]);
        SciDrv_ASyncTransmit(Channel);
    }
    Lin_ExitCriticalSection()
}

/******************************************************************************
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
******************************************************************************/
Std_ReturnType Lin_UartIf_CheckWakeup(uint8 Channel)
{
    Std_ReturnType TempReturn;

    TempReturn = Lin_UartIf_WakeupFlag[Channel];

    if((uint8)TRUE == TempReturn)
    {
        /* Reset Wakeup Flag */
        Lin_UartIf_WakeupFlag[Channel] = (uint8)FALSE;
    }
    else
    {
        /* Do nothing */
    }
    return TempReturn;
}

/******************************************************************************
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
******************************************************************************/
void Lin_UartIf_WakeUp(uint8 Channel)
{
    ESciDrvDirection Direction = eSciDrvDirection_Transmit;
    uint8 WakeupByte;

    WakeupByte = (uint8)(UART_MIN_WAKEUP_PULSE_LENGTH_U32) / ((uint32)(1000000U)/(uint32)(pLin_ConfigPtr->Lin_Channel[Channel].ChannelBaudRate));

    WakeupByte = (uint8)(~((uint8)((uint8)((uint32)1U << WakeupByte) - (uint8)1U)));

    Lin_EnterCriticalSection()
    {
        SciDrv_Cancel(Channel, Direction);
        /* Reset Buffer Length if Lin channel already sleep but fame slave not finished */
        if(LIN_CH_SLEEP_STATE == Lin_LinChStatus[Channel])
        {
            if(0U != Lin_UartIf_BufferLength[Channel])
            {
                Lin_UartIf_BufferLength[Channel] = (uint8)0U;
            }
        }
        /* Send Wake up request */
        SciDrv_SetupEB(Channel, Direction, &WakeupByte, UART_WAKEUP_LENGTH_BYTES_U32);
        SciDrv_ASyncTransmit(Channel);
    }
    Lin_ExitCriticalSection()
}

/******************************************************************************
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state 
*          without sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
******************************************************************************/
void Lin_UartIf_WakeupInternal(uint8 Channel)
{
    /* Reset Buffer Length if Lin channel already sleep but fame slave not finished */
    if(LIN_CH_SLEEP_STATE == Lin_LinChStatus[Channel])
    {
        if(0U != Lin_UartIf_BufferLength[Channel])
        {
            Lin_UartIf_BufferLength[Channel] = (uint8)0U;
        }
    }
}

/******************************************************************************
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
******************************************************************************/
Std_ReturnType Lin_UartIf_GoToSleep(uint8 Channel)
{
    Std_ReturnType TmpReturn = (uint8)E_NOT_OK;
    ESciDrvDirection Direction = eSciDrvDirection_Transmit;

    Lin_EnterCriticalSection()
    {
        TmpReturn = SciDrv_Cancel(Channel, Direction);
    }
    Lin_ExitCriticalSection()

    /*Set up break length*/
    /* Lin_UartIf_SetBreakLength(Channel); */

    if((uint8)E_OK == TmpReturn)
    {
        Lin_UartIf_BufferLength[Channel] = UART_MAX_BUFFER_LENGTH_U8;

        /* Prepare header */
        /* Synch byte */
        UART_Buffer[Channel][UART_SYNCH_BYTE_OFFSET_U8] = UART_SYNC_BYTE_U8;

        /* Protected Identifier */
        Lin_UartIf_PIDCalc(Channel, UART_MASTER_REQUEST_DIAGNOSTIC_ID_U8);

        /* The Go to sleep command is (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF) */
        UART_Buffer[Channel][(uint8)2U] = UART_DATA_0_U8;
        UART_Buffer[Channel][(uint8)3U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)4U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)5U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)6U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)7U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)8U] = UART_DATA_255_U8;
        UART_Buffer[Channel][(uint8)9U] = UART_DATA_255_U8;

        /* The Classic checksum for the go to sleep frame is 0x00  */
        UART_Buffer[Channel][Lin_UartIf_BufferLength[Channel] - ((uint8)1U)] = (uint8)Lin_UartIf_ChecksumCalc(Channel, LIN_CLASSIC_CS);

        /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
        Lin_UartIf_BufferPtr[Channel] = UART_SYNCH_BYTE_OFFSET_U8;

        Lin_EnterCriticalSection()
        {
            /* Reset register to send with 8 bit times */
            /* Lin_UartIf_ResetBreakLength(Channel); */

            /* Set header command type is sleep*/
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLEEP_COMMAND;

            /* Set diagnostic command type is sleep*/
            Lin_DiagnosticFrame[Channel] = UART_MASTER_REQUEST_DIAGNOSTIC_ID_U8;

            SciDrv_SetupEB(Channel, Direction, &Lin_DiagnosticFrame[Channel], UART_WAKEUP_LENGTH_BYTES_U32);
            SciDrv_SetupEB(Channel, Direction, &UART_Buffer[Channel][UART_MAX_BUFFER_LENGTH_U8], UART_WAKEUP_LENGTH_BYTES_U32);
        }
        Lin_ExitCriticalSection()
    }
    return TmpReturn;
}

/******************************************************************************
* @brief   Same function as Lin_UartIf_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
******************************************************************************/
Std_ReturnType Lin_UartIf_GoToSleepInternal(uint8 Channel)
{
    Std_ReturnType TmpReturn = (uint8)E_NOT_OK;
    ESciDrvDirection Direction = eSciDrvDirection_Transmit;

    Lin_EnterCriticalSection()
    {
        TmpReturn = SciDrv_Cancel(Channel, Direction);
    }
    Lin_ExitCriticalSection()

    /* Sleep Command */
    /* Set Channel State to Sleep */
    Lin_LinChStatus[Channel] = LIN_CH_SLEEP_STATE;
    /* Update Lin_TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
    Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
    /* Set LIN transmission state machine to LIN_TX_IDLE */
    Lin_LinTxStatus[Channel] = LIN_TX_IDLE;

    /* Reset buffer length */
    Lin_UartIf_BufferLength[Channel] = (uint8)0U;

    if((uint8)E_OK == TmpReturn)
    {
        /* Enter Sleep mode */
        /* Update Lin_TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
        Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;

        Lin_EnterCriticalSection()
        {
            /* Enable Wakeup */
            /* Update Lin_UartIf_WakeupFlag value to True */
            Lin_UartIf_WakeupFlag[Channel] = (uint8)TRUE;
        }
        Lin_ExitCriticalSection()
    }
    return TmpReturn;
}

/******************************************************************************
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 * @retval LIN_CH_SLEEP     Channel is in sleep mode.
 *
 ******************************************************************************/
Lin_StatusType Lin_UartIf_HardwareGetStatus(uint8 Channel, uint8* LinSduPtr)
{
    uint8 Temp1;
    uint8 Temp2;
    uint8 LinChFrameStatus;
    uint8 TransmitHeaderCommand;
    uint8 ChannelFrameError;
    Lin_StatusType TempReturn = LIN_NOT_OK;

    Temp1 = Lin_UartIf_BufferPtr[Channel];
    Temp2 = Lin_LinTxStatus[Channel];
    TransmitHeaderCommand = Lin_TransmitHeaderCommand[Channel];
    LinChFrameStatus = Lin_LinChFrameStatus[Channel];

    /* Frame transmission */
    if(((uint8)0U) != Temp2)
    {
        ChannelFrameError = Lin_LinChFrameErrorStatus[Channel];
        /* Header transmission */
        if((uint8)(UART_PID_BYTE_OFFSET_U8 + 1U) >= Temp1)
        {
            TempReturn = Lin_UartIf_HeaderTransGetStatus(ChannelFrameError, TransmitHeaderCommand, LinChFrameStatus);
        }
        /* Data transmission */
        else if(Temp2 == LIN_TX_CONFIRMATION_PENDING)
        {
            TempReturn = Lin_UartIf_DataTransGetStatus(ChannelFrameError, TransmitHeaderCommand, LinChFrameStatus);
        }
        /* The last byte has been transmitted/received */
        else if(Temp2 == LIN_TX_CONFIRMATION_SUCCESS)
        {
            TempReturn = Lin_UartIf_FinishTransGetStatus(Channel, ChannelFrameError, TransmitHeaderCommand, LinChFrameStatus, LinSduPtr);
        }
        else
        {
            /* Code Flow Error */
            TempReturn = LIN_NOT_OK;
        }
    }
    /* UartIf is idle */
    else
    {
        TempReturn = LIN_OPERATIONAL;
    }
    return TempReturn;
}

/******************************************************************************
* @brief   Callback function upon successful transmission
* @details This function is called when a LIN frame is 
*          successfully transmitted.
*
* @param[in] Channel, TransmitResult.
*
* @return            void.
*
******************************************************************************/
void Lin_UartIf_TxConfirmation(uint8 Channel, ESciDrvChnResult TransmitResult)
{
    /*  */
}

/******************************************************************************
* @brief   Callback function upon successful reception
* @details This function is called when a LIN frame is 
*          successfully received.
*
* @param[in] Channel, ReceiveResult,
*            SciBytesReceived, SciExtraBytesReceived.
* @return            void.
*
******************************************************************************/
void Lin_UartIf_RxIndication(uint8 Channel, ESciDrvChnResult ReceiveResult, uint32 SciBytesReceived, uint32 SciExtraBytesReceived)
{
    Lin_UartIf_RxBuffFullInterruptHandler(Channel, SciBytesReceived);
}

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : -05-2024                                              */
/*Version           :                                                       */
/*By                : mhishamu                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/
