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
/*!*****************************************************************************************************************
*   @file       Nm_Cbk.h
*   @ingroup    Nm
*   @brief      This file provides the declaration of the Nm Callback API. This header file should be included by 
*   other modules that use the Nm Callback API.
*   @defgroup   Services
*   @brief      The Network Management (Nm) module coordinates network sleep and wake-up for ECUs, ensuring 
*   efficient communication and power management. It handles network state transitions and monitors node presence
*   in automotive networks.
********************************************************************************************************************/
#ifndef NM_CBK_H
#define NM_CBK_H

#include "Nm_Cfg.h"
#include "ComM_Nm.h"
/*******************************************************************************************************************/
/* Standard Call back Declarations                                                                                 */
/*******************************************************************************************************************/
void Nm_NetworkStartIndication(NetworkHandleType nmNetworkHandle);
void Nm_NetworkMode(NetworkHandleType nmNetworkHandle);
void Nm_BusSleepMode(NetworkHandleType nmNetworkHandle);
void Nm_PrepareBusSleepMode(NetworkHandleType nmNetworkHandle);
#if (NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
void Nm_RemoteSleepIndication(NetworkHandleType nmNetworkHandle);
void Nm_RemoteSleepCancellation(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
void Nm_SynchronizationPoint(NetworkHandleType nmNetworkHandle);
void Nm_CoordReadyToSleepIndication(NetworkHandleType nmNetworkHandle);
void Nm_CoordReadyToSleepCancellation(NetworkHandleType nmNetworkHandle);
#endif
/*******************************************************************************************************************/
/*  Extra Call back Declarations                                                                                   */
/*******************************************************************************************************************/
#if (NM_PDU_RX_INDICATION_ENABLED == STD_ON)
void Nm_PduRxIndication(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
void Nm_StateChangeNotification(NetworkHandleType nmNetworkHandle, Nm_StateType nmPreviousState,
                                Nm_StateType nmCurrentState);
#endif
#if (NM_REPEAT_MSG_IND_ENABLED == STD_ON)
void Nm_RepeatMessageIndication(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
void Nm_TxTimeoutException(NetworkHandleType nmNetworkHandle);
#endif
#if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
void Nm_CarWakeUpIndication(NetworkHandleType nmNetworkHandle);
#endif
#endif /* NM_CBK_H */

/*****************************************************************************************************************
*                                 END OF FILE                                                                    *
******************************************************************************************************************/
