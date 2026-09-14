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
*   @file CanSM_TxTimeoutException.h
*   @ingroup CanSM
*   @brief The header file CanSM_TxTimeoutException.h shall provide the callback function CanSM_TxTimeoutException 
*           as optional interface to the CanNm module
********************************************************************************************************************/
#ifndef CANSM_TXTIMEOUTEXCEPTION_H
#define CANSM_TXTIMEOUTEXCEPTION_H

#define CANSM_START_SEC_CODE
#include "MemMap.h"

#if (CANSM_PNC_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This function shall notify the CanSM module, that the CanNm has detected for the affected partial
*               CAN network a tx timeout exception, which shall be recovered within the respective network state 
*               machine of the CanSM module.
*   @param[in]  Channel Affected CAN network
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_TxTimeoutException(NetworkHandleType Channel);
#endif

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANSM_TXTIMEOUTEXCEPTION_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

