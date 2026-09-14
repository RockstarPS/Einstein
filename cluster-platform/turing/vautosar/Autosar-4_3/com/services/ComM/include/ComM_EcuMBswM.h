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
*   @file ComM_EcuMBswM.h
*   @ingroup ComM
*   @brief This file provides the callback function prototype of the ComM module used by the EcuM module and BswM
*   module.
********************************************************************************************************************/
#ifndef COMM_ECUMBSWM_H
#define COMM_ECUMBSWM_H
#include "ComM_Types.h"
#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method called by EcuM to notify wake up on the corresponding channel.
*   @param[in]  Channel The Network Channel for which wakeup notification is called.
*   @ServiceID  0x2A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel);

#if (STD_ON == COMM_PNC_SUPPORT)
/********************************************************************************************************************
*   @brief      This method called by EcuM to notify wake up on the corresponding PNC .
*   @param[in]  PncId Identifier of the partial network cluster
*   @ServiceID  0x37
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_EcuM_PNCWakeUpIndication( PNCHandleType PncId );
#endif
/*!******************************************************************************************************************
*   @brief      This method called by EcuM or BswM to indicate when communication is allowed.
*   If EcuM/Fixed is used then this method is called by EcuM.
*   If EcuM/Flex is used then this method is called by BswM.
*   @param[in]  Channel The Network Channel for which communication request is called.
*   @param[in]  Allowed value of communication request.
*               - TRUE: Communication is allowed.
*               - FALSE: Communication is not allowed.
*   @ServiceID  0x35
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_ECUMBSWM_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
