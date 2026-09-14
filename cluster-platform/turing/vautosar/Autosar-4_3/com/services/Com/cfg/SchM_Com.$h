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
*    @file SchM_Com.h
*    @ingroup ComConfiguration
*    @brief This files contains the functions to be included by the schedule Manager.It contains the Main function
*    and the exclusive section API for Com.
*    @defgroup ComConfiguration
*    @brief This files contains the functions to be included by the schedule Manager.
********************************************************************************************************************/
#ifndef SCHM_COM_H
#define SCHM_COM_H

#include "SchM_Com_Type.h"
#include "Os.h"
#include "Com_Types.h"

/*! @brief Defines the enter critical function mapping */
#define Com_EnterCriticalSection() SuspendAllInterrupts()
/*! @brief Defines the exit critical function mapping */
#define Com_ExitCriticalSection() ResumeAllInterrupts()


#define COM_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service performs the processing of the AUTOSAR COM module's receive processing that are not
*   directly handled within the COM's functions invoked by the PDU-R,for example Com_RxIndication.
*   @ServiceID  0x18
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_MainFunctionRx(void);
/*!******************************************************************************************************************
*   @brief      This service performs the processing of the AUTOSAR COM module's transmission activities that are 
*   not directly handled within the COM's function invoked by the RTE, for example Com_SendSignal.
*   @ServiceID  0x19
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_MainFunctionTx(void);
/*!******************************************************************************************************************
*   @brief      This service performs signal gateway part of the AUTOSAR COM module to forward received signals to 
*   be routed.
*   @ServiceID  0x1A
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,COM_CODE) Com_MainFunctionRouteSignals(void);

#define COM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SCHM_COM_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

