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
*   @file ComM_Com.h
*   @ingroup ComM
*   @brief This file provides the callback function prototype of the ComM module used by the Com module.
********************************************************************************************************************/
#ifndef COMM_COM_H
#define COMM_COM_H

#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This method called by Com module when the EIRA or ERA was updated in COM. The call only informs the
*   ComM about ERA and EIRA changes. The actual handling is done in the next call to ComM_MainFunction_<Channel_Id>
*   with changing the corresponding PN State machine.
*   @ServiceID  0x36
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
*   @note This function is a configuration file and the funtion name _Signal should be replaced by actual signal.
*   This function should be implemented by the configuration source file and calls the ComM_UpdateEiraEraData with
*   the channel Id and the received data.
********************************************************************************************************************/
extern FUNC(void,COMM_CODE) ComM_COMCbk_Signal(void);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_COM_H */
/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
