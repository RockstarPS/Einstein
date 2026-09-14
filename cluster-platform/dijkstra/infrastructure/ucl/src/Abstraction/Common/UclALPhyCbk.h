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
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclALPhy
/// UCL Physical Abstraction Layer Callback Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHYCBK_H
#define UCLALPHYCBK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclALPhyCbk_Types.h"

///
/// @brief 	This method will be called when UclALPhy encounters any
///			Fatal Error
///
/// @param InstId Instance Id of the class that implements UclALPhyCbk
/// @param Status Status of the Fatal Error
///
void UclALPhyCbk_FatalError(uint8 InstId, sint32 Status);

///
/// @brief 	This method will be called when UclALPhy receives new
///			data
///
/// @param InstId Instance Id of the class that implements UclALPhyCbk
///
void UclALPhyCbk_ReceiveDataAvailable(uint8 InstId);

///
/// @brief 	This method will be called when Peer Ready Status is
///			changed
///
/// @param InstId Instance Id of the class that implements UclALPhyCbk
/// @param Status Status of the Peer
///
void UclALPhyCbk_PeerReadyStatusChanged(uint8 InstId, EUclALPhyPeerReadyStatus Status);

#ifdef __cplusplus
}
#endif
#endif //UCLALPHYCBK_H
