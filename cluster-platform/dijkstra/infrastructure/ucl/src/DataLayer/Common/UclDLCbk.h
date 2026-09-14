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
/// @ingroup UclDL
/// UCL Data Layer Callback Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLDLCBK_H
#define UCLDLCBK_H

#include "UclDLCbk_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief 	This method will be called when UclDL encounters any
///			Fatal Error
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the Fatal Error
///
void UclDLCbk_FatalError(uint8 InstId, EUclDLError Status);

///
/// @brief 	This method will be called when UclDL receive a new
///			Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param pMsg	  Pointer to the received Ucl Message
///
void UclDLCbk_MsgReceived(uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg);

///
/// @brief 	This method will be called by the UclDL to notify
///			about the transmit status of the Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the requested transmission
///
void UclDLCbk_MsgTransmitStatus(uint8 InstId, uint16 MsgId, EUclDLAckStatus Status);

///
/// @brief 	This method will be called by the UclDL to notify
///			about the change in the Link Status
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the UclDL Link
///
void UclDLCbk_LinkStatusChanged(uint8 InstId, EUclDLLinkStatus Status);

#ifdef __cplusplus
}
#endif
#endif //UCLDLCBK_H
