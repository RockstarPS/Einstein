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
/// UCL Phy Abstraction Layer Hardware Callback Interface
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALHWCBK_H
#define UCLALHWCBK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclALHwCbk_Types.h"

///
/// @brief This method is used to notify about the DMA Transmit Complete Callback
///
/// @param InstId Instance Id to route the event to
///
/// @return None
///
void UclALHwCbk_TransmitComplete(uint8 InstId);

///
/// @brief This method is used to notify about the DMA Receive Complete Callback
///
/// @param InstId Instance Id to route the event to
///
/// @return None
///
void UclALHwCbk_ReceiveComplete(uint8 InstId);

///
/// @brief This method is used to notify about the GPIO change notification
///
/// @param InstId Instance Id to route the event to
/// @param gpioNum Gpio Number that changed state
///
/// @return None
///
void UclALHwCbk_GpioChanged(uint8 InstId, uint32 gpioNum);

#ifdef __cplusplus
}
#endif
#endif //UCLALHWCBK_H
