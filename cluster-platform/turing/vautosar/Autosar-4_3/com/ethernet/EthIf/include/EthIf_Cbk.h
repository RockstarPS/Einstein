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
*   @file EthIf_Cbk.h
*   @ingroup EthIf
*   @brief This file provides list of functions provided for other modules. The function prototypes of the 
*   callback functions shall be provided in the file EthIf_Cbk.h
********************************************************************************************************************/
#ifndef ETHIF_CBK_H
#define ETHIF_CBK_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "EthIf_Types.h"
#include "EthTrcv_Types.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the EthIf Callback AUTOSAR major version */ 
#define ETHIF_CBK_AR_RELEASE_MAJOR_VERSION  4U
/*! @brief Defines the EthIf Callback AUTOSAR minor version */ 
#define ETHIF_CBK_AR_RELEASE_MINOR_VERSION  3U
/*! @brief Defines the EthIf Callback AUTOSAR patch version */ 
#define ETHIF_CBK_AR_RELEASE_PATCH_VERSION  1U

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
#define ETHIF_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      Handles a received frame received by the indexed controller
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  FrameType Frame type of received Ethernet frame
*   @param[in]  IsBroadcast parameter to indicate a broadcast frame
*   @param[in]  PhysAddrPtr Pointer to Physical source address (MAC address in network byte order) of received Ethernet 
*               frame
*   @param[in]  DataPtr Pointer to payload of received Ethernet frame.
*   @param[in]  LenByte Length (bytes) of the payload in received frame
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_RxIndication
( 
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr,
    P2VAR(Eth_DataType,AUTOMATIC,ETHIF_APPL_DATA) DataPtr,
    uint16 LenByte
);
/*!******************************************************************************************************************
*   @brief      Confirms frame transmission by the indexed controller
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  BufIdx Index of the transmitted buffer
*   @param[in]  Result E_OK: The transmission was successful, E_NOT_OK: The transmission failed.
*   @ServiceID  0x11
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_TxConfirmation( uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result );
/*!******************************************************************************************************************
*   @brief      Called asynchronously when mode has been read out. Triggered by previous Eth_SetControllerMode call. 
*               Can directly be called within the trigger functions
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  CtrlMode Notified Ethernet controller mode
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_CtrlModeIndication( uint8 CtrlIdx, Eth_ModeType CtrlMode );
/*!******************************************************************************************************************
*   @brief      Called asynchronously when a mode change has been read out. If the function is triggered by previous 
*               call of EthTrcv_SetTransceiverMode it can directly be called within the trigger function.
*   @param[in]  TrcvIdx Index of the Ethernet transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvMode Notified Ethernet transceiver mode
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same TrcvIdx, reentrant for different
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_TrcvModeIndication( uint8 TrcvIdx, EthTrcv_ModeType TrcvMode );

#define ETHIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ETHIF_CBK_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
