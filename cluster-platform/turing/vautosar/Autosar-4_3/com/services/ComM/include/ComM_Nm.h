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
*   @file ComM_Nm.h
*   @ingroup ComM
*   @brief This file provides the callback function prototype of the ComM module used by the Network Management
*   Interface module.
********************************************************************************************************************/
#ifndef COMM_NM_H
#define COMM_NM_H

#define COMM_START_SEC_CODE
#include "MemMap.h"
#include "ComM_Types.h"
/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method called by Nm to indicate that a NM-message has been received in the Bus Sleep Mode,
*   what indicates that some nodes in the network have already entered the Network Mode.
*   @param[in]  Channel The Network Channel for which this indication is called.
*   @ServiceID  0x15
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method called by Nm to notify the network management has entered Network Mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x18
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method called by Nm to notify the network management has entered Prepare Bus-Sleep Mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x19
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (but not for the same NM-Channel)
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method called by Nm to notify that the network management has entered Bus-Sleep Mode.
*   This callback function should perform a transition of the hardware and transceiver to bus-sleep mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x1a
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method called by Nm to notify that not all coordinated busses have indicated bus sleep state and
*   on at least on one of the coordinated busses NM is restarted when the Network management interface has started to
*   shut down the coordinated busses.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x1b
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_NM_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
