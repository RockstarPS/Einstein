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
*   @file EthSM_Cbk.h
*   @ingroup EthSM
*   @brief This file provides list of functions provided for other modules. The function prototypes of the 
*   callback functions shall be provided in the file EthSM_Cbk.h
********************************************************************************************************************/
#ifndef ETHSM_CBK_H
#define ETHSM_CBK_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "EthSM_Types.h"
#include "EthTrcv_Types.h"
#include "TcpIp_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the EthSM Callback AUTOSAR major version */ 
#define ETHSM_CBK_AR_RELEASE_MAJOR_VERSION  4U
/*! @brief Defines the EthSM Callback AUTOSAR minor version */ 
#define ETHSM_CBK_AR_RELEASE_MINOR_VERSION  3U
/*! @brief Defines the EthSM Callback AUTOSAR patch version */ 
#define ETHSM_CBK_AR_RELEASE_PATCH_VERSION  1U

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      Called when mode has been read out. Either triggered by previous EthIf_GetControllerMode or by 
*   EthIf_SetControllerMode call. Can directly be called within the trigger functions.
*   @param[in]  CtrlIdx Ethernet controller whose mode has changed
*   @param[in]  CtrlMode Notified Ethernet controller mode
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different Ethernet controllers)
********************************************************************************************************************/
extern FUNC(void, ETHSM_CODE) EthSM_CtrlModeIndication ( uint8 CtrlIdx, Eth_ModeType CtrlMode );
/*!******************************************************************************************************************
*   @brief      Called when mode has been read out. Either triggered by previous EthIf_GetTransceiverMode or by 
*   EthIf_SetTransceiverMode call. Can directly be called within the trigger functions.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  TrcvMode Notified Ethernet transceiver mode
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different Ethernet controllers)
********************************************************************************************************************/
extern FUNC(void, ETHSM_CODE) EthSM_TrcvModeIndication ( uint8 CtrlIdx, EthTrcv_ModeType TrcvMode );
/*!******************************************************************************************************************
*   @brief      This service is called by the Ethernet Interface to report a transceiver link state change.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  TransceiverLinkState Actual transceiver link state of the specific network handle
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
extern FUNC(void, ETHSM_CODE) EthSM_TrcvLinkStateChg( uint8 CtrlIdx, EthTrcv_LinkStateType TransceiverLinkState );
/*!******************************************************************************************************************
*   @brief      This service is called by the TcpIp to report the actual TcpIp state (e.g. online, offline).
*   @param[in]  CtrlIdx EthIf controller index to identify the communication network where the TcpIp state is changed
*   @param[in]  TcpIpState Actual TcpIp state of the specific network handle
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
extern FUNC(Std_ReturnType,ETHSM_CODE) EthSM_TcpIpModeIndication( uint8 CtrlIdx, TcpIp_StateType TcpIpState );

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ETHSM_CBK_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
