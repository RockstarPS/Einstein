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
/// @defgroup UclTest
/// @brief UCL Test Modules
/// @file
/// @ingroup UclTest
/// UCL Test Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLTEST_H
#define UCLTEST_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclTest_Types.h"

///
/// @brief This method is used to initialize the UclTest Instance
///
/// @param InstId Instance Id to initialize
///
void UclTest_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclTest Instance
///
/// @param InstId Instance Id to shutdown
///
void UclTest_Shutdown(uint8 InstId);

///
/// @brief This method is used to start the UclTest instance
///
/// @param InstId Instance Id to start
///
void UclTest_Start(uint8 InstId);

///
/// @brief This method is used to stop the UclTest instance
///
/// @param InstId Instance Id to stop
///
void UclTest_Stop(uint8 InstId);

#ifdef __cplusplus
}
#endif
#endif //UCLTEST_H
