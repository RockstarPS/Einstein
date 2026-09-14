/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @file CanTrcv_Tja1145ATK.h
*   @ingroup CanTrcv
*   @brief This file provides the declaration of the CanTrcv_Tja1145ATK API. This header file should be included by other  
*   modules that use the CanTrcv_Tja1145ATK API.
********************************************************************************************************************/
#ifndef CANTRCV_TJA1145ATK_H
#define CANTRCV_TJA1145ATK_H
#include "CanTrcv.h"
#include "CanTrcv_Tja1145ATK_Cfg.h"

typedef uint8 CanTrcv_Tja1145ATK_InitType;

#define CANTRCV_TJA1145ATK_INIT_STATUS_ACTIVE           0U
#define CANTRCV_TJA1145ATK_INIT_STATUS_NOT_ACTIVE       1U
#define CANTRCV_TJA1145ATK_WRITE_DATA_LENGTH            2U
#define CANTRCV_TJA1145ATK_READ_DATA_LENGTH             2U
#define CANTRCV_TJA1145ATK_WAKEUP_BY_BUS_USED           STD_ON  


/********************************************************************************************************************
*   @brief      Initializes the internal state and hardware interface for the TJA1145ATK CAN transceiver.
*
*   This function performs the following steps:
*     - Sets the initial wakeup reason to error.
*     - Reads the Identification Register (ISR) to verify the presence of the transceiver.
*     - If the transceiver is present, sets the internal status to active.
*     - Reads the Event Capture Status (ECS) and System Event Status (SES) registers to check for power-on events.
*     - Reads the Transceiver Status (TS) register to check for system errors.
*     - Updates the internal wakeup reason based on the register values:
*         - If a power-on event is detected, sets the wakeup reason to power-on.
*         - If a system error is detected, sets the wakeup reason to system error.
*         - Otherwise, the wakeup reason remains as error.
*
*   @param      None
*   @return     None
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTrcv_Tja1145ATK_Init(void);

/********************************************************************************************************************
*   @brief      This method sets the mode of the Transceiver to the value OpMode.
*   @param[in]  TrcvIdx  CAN transceiver TJA1145ATK channed Id to which API call has to be applied.
*   @param[in]  OpMode  This parameter contains the desired operating mode
*   @return     status of the request
*               - E_OK: will be returned if the request for transceiver mode change has been accepted.
*               - E_NOT_OK: will be returned if the request for transceiver mode change has not been accepted or any
*                 parameter is out of the allowed range.
*   @ServiceID  0x01
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_SetOpMode(uint8 TrcvIdx, CanTrcv_TrcvModeType OpMode);

/********************************************************************************************************************
*   @brief      This method gets the mode of the Transceiver and returns it in OpMode.
*   @param[in]  TrcvIdx  CAN transceiver to which API call has to be applied.
*   @param[out] OpMode  Pointer to operation mode of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the operation mode was detected.
*                   - E_NOT_OK: will be returned if the operation mode was not detected.
*   @ServiceID  0x02
*   @Sync/Async synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_GetOpMode(uint8 TrcvIdx, CanTrcv_TrcvModeType* OpMode);

/********************************************************************************************************************
*   @brief      This method gets the wakeup reason for the Transceiver and returns it in parameter Reason.
*   @param[in]  TrcvIdx  CAN transceiver to which API call has to be applied.
*   @param[out] Reason  Pointer to wake up reason of the bus the API is applied to.
*   @return     status of the request
*                   - E_OK: will be returned if the transceiver wakeup reason was provided.
*                   - E_NOT_OK: will be returned if no wake up reason is available or if the service request failed
*                     due to development errors.
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_Tja1145ATK_GetBusWuReason(uint8 TrcvIdx, CanTrcv_TrcvWakeupReasonType *Reason);
#if (CANTRCV_HW_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Reads the TJA1145 transceiver's main status, transceiver status, and WAKE pin status registers via SPI,
*               and returns their combined value through the TrcvSysData parameter.
*               This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @param[out] TrcvSysData  Pointer to a 32-bit variable to be updated with the combined status data.
*   @return     Status of the request:
*                   - E_OK:      The transceiver status was successfully read and returned.
*                   - E_NOT_OK:  The status data is not available or a hardware access error occurred.
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_GetTrcvSystemData(uint8 TrcvIdx, uint32* TrcvSysData);

/********************************************************************************************************************
*   @brief      Clears the Wake-Up Flag (WUF) in the TJA1145 transceiver hardware by writing to the appropriate event
*               status registers via SPI. This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The WUF flag was successfully cleared in the transceiver hardware.
*                   - E_NOT_OK:  The WUF flag could not be cleared or a hardware access error occurred.
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different transceivers
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ClearTrcvWufFlag(uint8 TrcvIdx);

/********************************************************************************************************************
*   @brief      Reads the status of the timeout flag from the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               timeout flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx     Index of the CAN transceiver to which the API call is applied.
*   @param[out] FlagState   Pointer to be updated with the state of the timeout flag.
*   @return     Status of the request:
*                   - E_OK:      The status of the timeout flag was successfully read (not supported for TJA1145).
*                   - E_NOT_OK:  The status of the timeout flag could not be read or is not supported.
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ReadTrcvTimeoutFlag(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagState);

/********************************************************************************************************************
*   @brief      Clears the status of the timeout flag in the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               timeout flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The timeout flag was successfully cleared (not supported for TJA1145).
*                   - E_NOT_OK:  The timeout flag could not be cleared or is not supported.
*   @ServiceID  0x0c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ClearTrcvTimeoutFlag(uint8 TrcvIdx);

/********************************************************************************************************************
*   @brief      Reads the status of the silence flag from the TJA1145 transceiver hardware. For TJA1145, a dedicated
*               silence flag is not supported and this API always returns E_NOT_OK.
*               This API shall exist only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx     Index of the CAN transceiver to which the API call is applied.
*   @param[out] FlagState   Pointer to be updated with the state of the silence flag.
*   @return     Status of the request:
*                   - E_OK:      The status of the silence flag was successfully read (not supported for TJA1145).
*                   - E_NOT_OK:  The status of the silence flag could not be read or is not supported.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_ReadTrcvSilenceFlag(uint8 TrcvIdx, CanTrcv_TrcvFlagStateType* FlagState);

/********************************************************************************************************************
*   @brief      Checks  the wakeup flag in the TJA1145 transceiver hardware by writing to the appropriate
*               event status registers via SPI. This API is available only if Partial Networking (PN) support is enabled.
*   @param[in]  TrcvIdx      Index of the CAN transceiver to which the API call is applied.
*   @return     Status of the request:
*                   - E_OK:      The wakeup flag was successfully checked and cleared in the transceiver hardware.
*                   - E_NOT_OK:  The wakeup flag could not be checked or a hardware access error occurred.
*   @ServiceID  0x0e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
Std_ReturnType CanTrcv_TJA1145ATK_CheckWakeFlag(uint8 TrcvIdx);
#endif
/*!******************************************************************************************************************
*   @brief      This method is the main function for the CAN transceiver driver. It checks for wakeup events on all
*               transceiver channels and handles them appropriately.
*   @return     void
********************************************************************************************************************/
void CanTrcv_Tja1145ATK_MainFunction(void);
#endif /* CANTRCV_TJA1145ATK_H */
