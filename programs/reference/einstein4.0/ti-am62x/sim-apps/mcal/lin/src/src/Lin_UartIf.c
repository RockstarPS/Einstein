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

/*****************************************************************************
*                          Local Function Prototypes                         *
******************************************************************************/

/*****************************************************************************
*                               Local Functions                              *
******************************************************************************/

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
    return E_OK;
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
    return E_OK;
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
    return E_OK;
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
    return E_OK;
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
    return E_OK;
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
    return LIN_OPERATIONAL;
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
