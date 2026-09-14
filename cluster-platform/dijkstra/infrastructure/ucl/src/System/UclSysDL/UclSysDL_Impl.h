///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclSysDL
/// Ucl System Implementation for Ucl DL ONLY Stack. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCSYS_IMPL_H
#define UCSYS_IMPL_H

#include "Ucl_Types.h"
#include "UclDL_Types.h"
#include "UclDLCbk_Types.h"

///
/// @brief Application callback function type for UclDL FatalError
///
typedef void (*TUclFatalErrorFunc)(uint8 DLInst, uint8 Status);

///
/// @brief Application callback function type for UclDL MsgReceived
///
typedef void (*TUclMsgReceivedFunc)(uint8 DLInst, EUclDLRxStatus Status, SUclDLMsg *pMsg);

///
/// @brief Application callback function type for UclDL MsgTransmitStatus
///
typedef void (*TUclMsgTransmitStatusFunc)(uint8 DLInst, uint16 MsgId, EUclDLAckStatus Status);

///
/// @brief Application callback function type for UclDL LinkStatusChanged
///
typedef void (*TUclLinkStatusChangedFunc)(uint8 DLInst, EUclDLLinkStatus Status);

///
/// @brief Configuration data for UclSysDL_Impl. \n
///
/// The SUclSysDLCfg structure defines the constant configuration data for UclSysDL_Impl class.
///
typedef struct SUclSysDLCfg_t
{
  TUclFatalErrorFunc pFatalErrorFunc;               ///< UCL Fatal Error Callback
  TUclMsgReceivedFunc pMsgReceivedFunc;             ///< UCL New Message Received Callback
  TUclMsgTransmitStatusFunc pMsgTransmitStatusFunc; ///< UCL Transmit Message Status Callback
  TUclLinkStatusChangedFunc pLinkStatusChangedFunc; ///< UCL Link Status Callback
} SUclSysDLCfg;

///
/// @brief Private instance data for UclSysDL_Impl. \n
///        UclSysDL_Impl is for DL ONLY Systems
///
/// @ingroup UclSys
///
/// The SUclSysDLInst structure defines the private instance data for UclSys_Impl class.
///
typedef struct SUclSysDLInst_t
{
  uint8 numIUclALOs;    ///< Number of OS Instances
  uint8 *pIUclALOs;     ///< List of OS Instances Ids
  uint8 numIUclDL;      ///< Number of UCL Data Layer Instances
  uint8 *pIUclDL;       ///< List of UCL Data Layer Instances Ids
  uint8 numIUclALDebug; ///< Number of Debug Instances
  uint8 *pIUclALDebug;  ///< List of Debug Instances Ids

  uint8 UclSysState;        ///< Ucl System State
  const SUclSysDLCfg *pCfg; ///< Ucl System Configuration
} SUclSysDLInst;

//Implementation for interface IUclSys
Ucl_ReturnType UclSysDL_Impl_IUclSys_Initialize(SUclSysDLInst *pInst, uint8 InstId);
Ucl_ReturnType UclSysDL_Impl_IUclSys_Shutdown(SUclSysDLInst *pInst, uint8 InstId);
Ucl_ReturnType UclSysDL_Impl_IUclSys_Task(SUclSysDLInst *pInst, uint8 InstId);
Ucl_ReturnType UclSysDL_Impl_IUclSys_Send(SUclSysDLInst *pInst, uint8 InstId, uint8 DLInst, SUclDLMsg *pMsg);

//Implementation for provided port IUclDLCbk
void UclSysDL_Impl_IUclDLCbk_FatalError(SUclSysDLInst *pInst, uint8 InstId, uint8 Status);
void UclSysDL_Impl_IUclDLCbk_MsgReceived(SUclSysDLInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg);
void UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus(SUclSysDLInst *pInst, uint8 InstId, uint16 MsgId, EUclDLAckStatus Status);
void UclSysDL_Impl_IUclDLCbk_LinkStatusChanged(SUclSysDLInst *pInst, uint8 InstId, EUclDLLinkStatus Status);

#endif //UCSYS_IMPL_H
