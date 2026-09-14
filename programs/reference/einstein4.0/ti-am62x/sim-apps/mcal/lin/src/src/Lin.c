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
*  File Name         :  Lin.c                                                *
*  Module Short Name :  Lin                                                  *
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

#include "Lin.h"
#include "Lin_UartIf.h"

#if (LIN_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

#if(LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif

/*****************************************************************************
*                              Global Variables                              *
******************************************************************************/

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
Lin_ConfigType* Lin_ConfigPtr = &Lin_Config;

/*****************************************************************************
*                        Global Function Implementation                      *
******************************************************************************/

/*****************************************************************************
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN
*          driver:
*          - Clears the shadow buffer of all available Lin channels
*          - Set LIN channel state machine of all available Lin
*            channels to LIN_CH_SLEEP_STATE for ASR 4.3.1 or
*            LIN_CH_OPERATIONAL for others
*          - Set frame operation state machine of all available LIN
*            channels to LIN_CH_NOT_READY_STATE for ASR 4.3.1 or
*            LIN_CH_READY_STATE for others
*          - Set driver state machine to LIN_INIT.
*
* @param[in] Config        Pointer to LIN driver configuration set.
*
* @return  void
*
* @api
*
* @implements Lin_Init_Activity
*
* @note    Autosar Service ID: 0x00.
* @note    Synchronous, non reentrant function.
*
******************************************************************************/
void Lin_Init(Lin_ConfigType* Config)
{
    Lin_LinDrvStatus = LIN_INIT;
}

/*****************************************************************************
* @brief   Sends a LIN frame.
* @details Sends a LIN header and a LIN response, if necessary. The
*          direction of the frame response (master response, slave
*          response, slave-to-slave communication) is provided by
*          the PduInfoPtr.
*
* @param[in] Channel       LIN channel to be addressed.
* @param[in] PduInfoPtr    pointer to PDU containing the PID,
*                          Checksum model, Response type, Dl and SDU
*                          data pointer.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          PduInfoPtr is NULL or
*                          a timeout occurs or
*                          LIN Channel is in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_SendFrame_Activity
*
* @note    Autosar Service ID: 0x04.
* @note    Asynchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_SendFrame(uint8 Channel, Lin_PduType* PduInfoPtr)
{
    return E_OK;
}

/*****************************************************************************
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          the addressed LIN Channel is not
*                          in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_CheckWakeup_Activity
*
* @note    Autosar Service ID: 0x0A.
* @note    Synchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_CheckWakeup(uint8 Channel)
{
    return E_OK;
}

/*****************************************************************************
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_Wakeup_Activity
*
* @note    Autosar Service ID: 0x07.
* @note    Asynchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_Wakeup(uint8 Channel)
{
    return E_OK;
}

/*****************************************************************************
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without sending a
*          wake up signal to the LIN bus
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_WakeupInternal_Activity
*
* @note    Autosar Service ID: 0x0B.
* @note    Asynchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_WakeupInternal(uint8 Channel)
{
    return E_OK;
}

/*****************************************************************************
* @brief   The service instructs the driver to transmit a
*          go-to-sleep-command on the addressed LIN channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command
*          frame with ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF,
*          0xFF, 0xFF, 0xFF, 0xFF). State transition in
*          LIN_CH_SLEEP_STATE shall be done after the completion of
*          the sleep command transmission regardless of the success
*          (therefore the ISR is responsible to put the channel in
*          LIN_CH_SLEEP_STATE).
*
* @param[in] Channel       LIN channel to be checked.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_GoToSleep_Activity
*
* @note    Autosar Service ID: 0x06.
* @note    Asynchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_GoToSleep(uint8 Channel)
{
    return E_OK;
}

/*****************************************************************************
* @brief   Put a Lin channel in the internal sleep state.
* @details Stops any ongoing transmission, sets the channel
*          state to LIN_CH_SLEEP and put the LIN
*          hardware unit to a reduced power operation mode.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_GoToSleepInternal_Activity
*
* @note    Autosar Service ID: 0x09.
* @note    Synchronous, non reentrant function.
*
******************************************************************************/
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel)
{
    return E_OK;
}

/*****************************************************************************
* @brief   Gets the status of the LIN driver.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in] Channel       LIN channel to be checked.
*
* @param[out] Lin_SduPtr   Lin_SduPtr pointer to pointer to a shadow
*                          buffer or memory mapped LIN Hardware
*                          receive buffer where the current SDU is
*                          stored.
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error rised
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
* @api
*
* @implements Lin_GetStatus_Activity
*
* @note    Autosar Service ID: 0x08.
* @note    Synchronous, non reentrant function.
*
******************************************************************************/
Lin_StatusType Lin_GetStatus(uint8 Channel, uint8* Lin_SduPtr)
{
    return LIN_OPERATIONAL;
}

#if (LIN_VERSION_INFO_API == STD_ON)
/*****************************************************************************
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return                  void.
*
* @api
*
* @pre            Preconditions as text description. Optional tag.
*
* @implements Lin_GetVersionInfo_Activity
*
* @note    Autosar Service ID: 0x01.
* @note    Synchronous, reentrant function.
*
******************************************************************************/
void Lin_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    
}
#endif /* LIN_VERSION_INFO_API == STD_ON */

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
