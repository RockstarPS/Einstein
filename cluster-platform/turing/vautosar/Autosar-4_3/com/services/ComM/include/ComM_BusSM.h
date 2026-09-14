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
*   @file ComM_BusSM.h
*   @ingroup ComM
*   @brief This file provides the callback function prototype of the ComM module used by the <Bus>SM module i,e.
*   CanSM ,LinSM etc..
********************************************************************************************************************/
#ifndef COMM_BUSSM_H
#define COMM_BUSSM_H

#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method called by <Bus>SM module to indicate the actual bus mode by the corresponding Bus State
*   Manager.ComM shall propagate the indicated state to the users with means of the RTE and BswM.
*   @param[in]  Channel The Network Channel for which indication request is called.
*   @param[in]  ComMode ComM mode requested by the user.
*               - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*               - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*               - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @ServiceID  0x33
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_BUSSM_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
