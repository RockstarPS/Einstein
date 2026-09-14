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
*  File Name         :  Lin.h                                                *
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

#ifndef LIN_H
#define LIN_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Lin_Cfg.h"
#include "Lin_GeneralTypes.h"
#include "EcuM.h"

/*****************************************************************************
*                        Source File Version Information                     *
******************************************************************************/

#define LIN_SW_MAJOR_VERSION                    1u
#define LIN_SW_MINOR_VERSION                    0u
#define LIN_SW_PATCH_VERSION                    0u

#define LIN_VENDOR_ID                           43
#define LIN_MODULE_ID                           82
#define LIN_AR_RELEASE_MAJOR_VERSION            4
#define LIN_AR_RELEASE_MINOR_VERSION            3
#define LIN_AR_RELEASE_REVISION_VERSION         1

/*****************************************************************************
*                               Macro Definitions                            *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/**
@brief  Switches the development error detection and notification on or off.
            true: detection and notification is enabled.
            false: detection and notification is disabled.
*/
#define LIN_DEV_ERROR_DETECT                    STD_OFF
#define LIN_DISABLE_DEM_REPORT_ERROR_STATUS     STD_ON

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Constants                                   *
******************************************************************************/

/**
* @brief            API service used without module initialization
* @details          The LIN Driver module shall report the development error "LIN_E_UNINIT (0x00)", 
*                   when the API Service is used without module initialization.
* 
* @api
*/
#define LIN_E_UNINIT            ((uint8)0x00U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_INVALID_CHANNEL (0x02)", when API Service used with 
*                   an invalid or inactive channel parameter.
* 
* @api
*/
#define LIN_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_INVALID_POINTER (0x03)", when API Service is called 
*                   with invalid configuration pointer.
* 
* @api
*/
#define LIN_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Invalid state transition for the current state
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_STATE_TRANSITION (0x04)", when Invalid state transition 
*                   occurs from the current state.
* 
* @api
*/
#define LIN_E_STATE_TRANSITION  ((uint8)0x04U)

/**
* @brief            API service called with a NULL pointer
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_PARAM_POINTER (0x05)", when API Service is called 
*                   with a NULL pointer. In case of this error, the API service 
*                   shall return immediately without any further action, 
*                   beside reporting this development error.
* 
* @api
*/
#define LIN_E_PARAM_POINTER  ((uint8)0x05U)

 #if (LIN_DEV_ERROR_DETECT == STD_ON)
/**
* @brief            Timeout caused by hardware error
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_TIMEOUT (0x06)", when the error "Timeout caused by hardware error"
*                   has occurred and the reference LinDemEventParameterRefs/LIN_E_TIMEOUT is
*                   not configured.
* 
* @api
*/
#define LIN_E_TIMEOUT       ((uint8)0x06U)
#endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
 
#define LIN_INIT                (0x02U)

 /**
* @brief            LIN Channel states
* @details          go-to-sleep-command has been issued on the bus, LIN channel stay at this state
*                   until Lin_GetStatus() is called
*
* @api
*/
#define LIN_CH_SLEEP_PENDING    ((uint8)0x01U)
 
/**
* @brief            LIN Channel states
* @details          The detection of a wake-up pulse is enabled. The LIN 
*                   hardware is into a low power mode if such a mode is 
*                   provided by the hardware.
* 
* @api
*/
#define LIN_CH_SLEEP_STATE      ((uint8)0x02U)

/**
* @brief            LIN Channel states
* @details          The individual channel has been initialized (using 
*                   at least one statically configured data set) and 
*                   is able to participate in the LIN cluster.
* 
* @api
*/
#define LIN_CH_OPERATIONAL   ((uint8)0x03U)

/**
* @brief            LIN Channel states
* @details          The individual channel is not ready to 
*                   proceess a frame.
* 
* @api
*/
#define LIN_CH_NOT_READY_STATE     ((uint8)0x04U)

/**
* @brief            LIN Channel states
* @details          The individual channel is ready to proceess a frame.
* 
* @api
*/
#define LIN_CH_READY_STATE         ((uint8)0x05U)

/**
* @brief            LIN Channel states
* @details          LIN frame was sent; no errors.
* 
* @api
*/
#define LIN_TX_COMPLETE_STATE      ((uint8)0x06U)

/**
* @brief            LIN Channel states
* @details          LIN frame was received; no errors.
* 
* @api
*/
#define LIN_RX_COMPLETE_STATE      ((uint8)0x07U)

/**
* @brief            LIN Channel states
* @details          State after the LIN frame header was correctly sent.
* 
* @api
*/
#define LIN_CH_RECEIVE_NOTHING_STATE   ((uint8)0x08U)

/**
* @brief            LIN Channel states
* @details          LIN frame is receiving.
* 
* @api
*/
#define LIN_RX_ONGOING_STATE           ((uint8)0x09U)

/**
* @brief            LIN Channel states
* @details          LIN header is transmission.
* 
* @api
*/
#define LIN_TX_HEADER_COMPLETE_STATE           ((uint8)0x10U)

/**
* @brief            Interrupt Errors conditions
* @details          No error occurred on a channel.
* 
* @api
*/
#define LIN_NO_ERROR               ((uint8)0x00U)

/**
* @brief            Interrupt Errors conditions
* @details          Bit error on a channel:
*                   - During response field transmission (Slave and Master modes);
*                   - During header transmission (in Master mode).
* 
* @api
*/
#define LIN_BIT_ERROR              ((uint8)0x01U)

/**
* @brief            Interrupt Errors conditions
* @details          Checksum error on a channel.
* 
* @api
*/
#define LIN_CHECKSUM_ERROR         ((uint8)0x02U)

/**
* @brief            Interrupt Errors conditions
* @details          Inconsistent Synch Field.
* 
* @api
*/
#define LIN_SYNCH_FIELD_ERROR      ((uint8)0x03U)

/**
* @brief            Interrupt Errors conditions
* @details          Break Delimiter too short (< 1 bit).
* 
* @api
*/
#define LIN_BREAK_DELIMITER_ERROR  ((uint8)0x04U)

/**
* @brief            Interrupt Errors conditions
* @details          Parity error.
* 
* @api
*/
#define LIN_IDENTIFIER_PARITY_ERROR    ((uint8)0x05U)

/**
* @brief            Interrupt Errors conditions
* @details          Invalid stop bit:
*                   - During reception of any data in the 
*                     response field (Slave and Master modes);
*                   - During reception of Synch or Identifier
*                     Field (Slave mode).
* 
* @api
*/
#define LIN_FRAMING_ERROR          ((uint8)0x06U)

/**
* @brief            Interrupt Errors conditions
* @details          New data byte is received on a channel
*                   and the buffer full flag is not cleared.
* 
* @api
*/
#define LIN_BUFFER_OVER_RUN_ERROR  ((uint8)0x07U)

/**
* @brief            Interrupt Errors conditions
* @details          Noise detected on a received character.
* 
* @api
*/
#define LIN_NOISE_ERROR            ((uint8)0x08U)

/**
* @brief            Interrupt Errors conditions
* @details          Header or Response timeout detected.
* 
* @api
*/
#define LIN_TIMEOUT_ERROR          ((uint8)0x09U)

/**
* @brief            Commands IDs
* @details          Tx frame is a master frame (response is provided by
*                   master).
* 
* @api
*/
#define LIN_TX_MASTER_RES_COMMAND  ((uint8)0x01U)

/**
* @brief            Commands IDs
* @details          Tx frame is a slave frame (response is provided by
*                   slave).
* 
* @api
*/
#define LIN_TX_SLAVE_RES_COMMAND   ((uint8)0x02U)

/**
* @brief            Commands IDs
* @details          Tx frame is a sleep command frame.
* 
* @api
*/
#define LIN_TX_SLEEP_COMMAND       ((uint8)0x03U)

/**
* @brief            Commands IDs
* @details          No tx master command pending.
* 
* @api
*/
#define LIN_TX_NO_COMMAND          ((uint8)0x04U)

/**
* @brief          API functions service IDs.
* @details        Service IDs of the AUTOSAR LIN API.
*/

/**
* @brief            Commands IDs
* @details          Tx frame is a slave frame.
* 
* @api
*/
#define LIN_TX_SLAVE_TO_SLAVE_COMMAND          ((uint8)0x05U)

/*****************************************************************************
*                                 Global Constants                           *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/**
* @brief          Lin Config
*/
extern Lin_ConfigType Lin_Config;

/*****************************************************************************
*                                 Global Variables                           *
******************************************************************************/

/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
Lin_ChannelConfigType Lin_ChannelConfigPtr[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN driver status variable.
* @details        LIN driver state machine.
*/
static Lin_InitStatusType Lin_LinDrvStatus = LIN_UNINIT;

/**
* @brief          LIN channel state variable.
* @details        LIN channel state machine.
*/
volatile uint8 Lin_LinChStatus[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN transmission state variable.
* @details        LIN transmission state machine.
*/
volatile uint8 Lin_LinTxStatus[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN frame state variable.
* @details        LIN frame state.
*/
volatile uint8 Lin_LinChFrameStatus[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN Frame header state variable.
* @details        LIN Frame header state.
*/
static volatile uint8 Lin_LinChHeaderStatus[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN Frame error status variable.
* @details        LIN Frame error status.
*/
volatile uint8 Lin_LinChFrameErrorStatus[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN header command type variable.
* @details        LIN header command type.
*/
uint8 Lin_TransmitHeaderCommand[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN diagnostic command type variable.
* @details        LIN diagnostic command type.
*/
uint8 Lin_DiagnosticFrame[LIN_NUM_OF_CHANNELS];

/**
* @brief          LIN SDU buffer variable.
* @details        LIN SDU buffer to be returned.
*/
uint8 Lin_SduBuffAddress[LIN_NUM_OF_CHANNELS];

/*****************************************************************************
*                                 Local Variables                            *
******************************************************************************/

/*****************************************************************************
*                                 Global Functions                           *
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
void Lin_Init(Lin_ConfigType* Config);

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
Std_ReturnType Lin_SendFrame(uint8 Channel, Lin_PduType* PduInfoPtr);

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
Std_ReturnType Lin_CheckWakeup(uint8 Channel);

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
Std_ReturnType Lin_Wakeup(uint8 Channel);

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
Std_ReturnType Lin_WakeupInternal(uint8 Channel);

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
Std_ReturnType Lin_GoToSleep(uint8 Channel);

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
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel);

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
Lin_StatusType Lin_GetStatus(uint8 Channel, uint8* Lin_SduPtr);

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
void Lin_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif /* LIN_VERSION_INFO_API == STD_ON */

#endif /* LIN_H */

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