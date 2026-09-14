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
*   @file TcpIp_EthSM.h
*   @ingroup TcpIp_EthSM
*   @brief This file provides list of functions provided by TcpIp for EthSM modules. The function prototypes of the 
*   callback functions shall be provided in the file TcpIp_EthSM.h
********************************************************************************************************************/
#ifndef TCPIP_ETHSM_H
#define TCPIP_ETHSM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "TcpIp_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to change the TcpIp state of the communication
*               network identified by EthIf controller index.
*   @param[in]  CtrlIdx  EthIf controller index to identify the communication network where the TcpIp state is
*               requested.
*   @param[in]  State Requested TcpIp state.
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x09
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RequestComMode(uint8 CtrlIdx,TcpIp_StateType State);

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* TCPIP_ETHSM_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
