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
*   @file CanSM_Cbk.h
*   @ingroup CanSM
*   @brief This file provides list of functions provided for other modules. The function prototypes of the 
*   callback functions shall be provided in the file CanSM_Cbk.h
********************************************************************************************************************/
#ifndef CANSM_CBK_H
#define CANSM_CBK_H

#include "CanSM_Cfg.h"

#define CANSM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This callback function notifies the CanSM about a bus-off event on a certain CAN controller, which 
*               needs to be considered with the specified bus-off recovery handling for the impacted CAN network.
*   @param[in]  ControllerId CAN controller, which detected a bus-off event
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different CanControllers)
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_ControllerBusOff(uint8 ControllerId);
/*!******************************************************************************************************************
*   @brief      This callback shall notify the CanSM module about a CAN controller mode change.
*   @param[in]  ControllerId CAN controller, whose mode has changed
*   @param[in]  ControllerMode Notified CAN controller mode
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different CanControllers)
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode);
#if (CANSM_TRCV_HANDLING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This callback shall notify the CanSM module about a CAN transceiver mode change.
*   @param[in]  TransceiverId CAN transceiver, whose mode has changed
*   @param[in]  TransceiverMode Notified CAN transceiver mode
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode);
#if (CANSM_PNC_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This callback function indicates that the transceiver is running in PN communication mode.
*   @param[in]  Transceiver CAN transceiver, which was checked for PN availability
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_ConfirmPnAvailability(uint8 TransceiverId);
#endif
/*!******************************************************************************************************************
*   @brief      This callback function shall indicate the CanIf_ClearTrcvWufFlag API process end for the notified 
*               CAN Transceiver.
*   @param[in]  Transceiver Affected CAN network
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);
/*!******************************************************************************************************************
*   @brief      This callback function indicates the CanIf_CheckTrcvWakeFlag API process end for the notified CAN 
*               Transceiver.
*   @param[in]  Transceiver Requested Transceiver
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);
#endif
#if (CANSM_ICOM_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall inform about the change of the Icom Configuration of a CAN network.
*   @param[in]  ControllerId CAN Controller Id, whose configuration has changed.
*   @param[in]  ConfigurationId Changed Configuration Id
*   @param[in]  Error ICOM_SWITCH_E_OK: No Error 
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant only for different network handles
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_CurrentIcomConfiguration
(
    uint8 ControllerId, 
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#endif


#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
