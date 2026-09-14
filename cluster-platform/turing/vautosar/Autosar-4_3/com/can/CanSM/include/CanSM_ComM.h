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
*   @file CanSM_ComM.h
*   @ingroup CanSM
*   @brief This file provides the callback function prototype of the CanSM module used by the ComM module .
********************************************************************************************************************/
#ifndef CANSM_COMM_H
#define CANSM_COMM_H

#define CANSM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service shall change the communication mode of a CAN network to the requested one.
*   @param[in]  network Handle of destined communication network for request
*   @param[in]  ComM_Mode Requested communication mode
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x02
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (only for different network handles)
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) CanSM_RequestComMode(NetworkHandleType network, ComM_ModeType ComM_Mode);
/*!******************************************************************************************************************
*   @brief      This service shall put out the current communication mode of a CAN network
*   @param[in]  network Network handle, whose current communication mode shall be put outHandle of destined 
                communication network for request
*   @param[out] ComM_ModePtr Pointer, where to put out the current communication mode
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType,COMM_CODE) CanSM_GetCurrentComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType,AUTOMATIC,CANSM_APPL_DATA) ComM_ModePtr
);

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANSM_COMM_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

