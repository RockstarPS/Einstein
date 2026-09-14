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
/// @ingroup UclALPhy
/// UCL Physical Abstraction Layer Callback Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHYCBKTYPES_H
#define UCLALPHYCBKTYPES_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Ucl_Types.h"

///
/// @brief Status of the Peer
///
typedef enum {
    eUclALPhyPeerReadyStatus_NotReady, ///< Peer not ready to receive the data
    eUclALPhyPeerReadyStatus_Ready,    ///< Peer ready to receive the data
    eUclALPhyPeerReadyStatus_Last      ///< Guard
} EUclALPhyPeerReadyStatus;

#ifdef __cplusplus
}
#endif
#endif //UCLALPHYCBKTYPES_H
