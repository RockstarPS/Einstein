/********************************************************************************************************************
|    File Name: CanSM_Cbk.h
|
|  Description: Implementation of the AUTOSAR CanSM Interface
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-04-14  00.00.04  MA     Review Comments fixed (Task 808498)
| 2020-03-13  00.00.03  MA     Transceiver and wakeup support State Machine Added
| 2020-02-04  00.00.02  MA     Review Comments fixed (Task 1394516)
| 2019-12-23  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CANSM_CBK_H
#define CANSM_CBK_H

#include "CanSM_Types.h"
#if (CANSM_TRCV_HANDLING == STD_ON)
# include "CanTrcv_GeneralTypes.h"
#endif
/* This callback function notifies the CanSM about a bus-off event on a certain CAN controller,
which needs to be considered with the specified bus-off recovery handling for the impacted CAN network. */
extern void CanSM_ControllerBusOff(uint8 ControllerId);
/* This callback shall notify the CanSM module about a CAN controller mode change. */
extern void CanSM_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
#if (CANSM_TRCV_HANDLING == STD_ON)
/* This callback function shall indicate the CanIf_ClearTrcvWufFlag API process end for the
notified CAN Transceiver. */
extern void CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);
/* This callback function indicates the CheckTransceiverWakeFlag API process
end for the notified CAN Transceiver. */
extern void CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);
/* This callback function indicates that the transceiver is running in PN communication mode. */
extern void CanSM_ConfirmPnAvailability(uint8 TransceiverId);
/* This callback shall notify the CanSM module about a CAN transceiver mode change. */
extern void CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
#endif
#endif
