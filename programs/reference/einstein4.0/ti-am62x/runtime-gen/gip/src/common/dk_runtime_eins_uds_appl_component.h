//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Fri Oct 31 17:48:26 IST 2025
// User: PSIVAKU7
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_RUNTIME_EINS_UDS_APPL_COMPONENT_H
#define DK_RUNTIME_EINS_UDS_APPL_COMPONENT_H

#include "dk_runtime_messages.h"
#include "dk_runtime_component.h"
#include "diag_app_gp.h"

#ifdef __cplusplus
namespace dk
{
namespace runtime
{
#endif

#define DK_RTE_Send_DoipSetParams(x) gApp.sendDoipSetParams((x));

#define DK_RTE_Send_DoipDiagPowerModeStatus(x) gApp.sendDoipDiagPowerModeStatus((x));

#define DK_RTE_Send_UdsServiceResponseTransmitRequest(x) gApp.sendUdsServiceResponseTransmitRequest((x));

#define DK_RTE_Send_UdsServiceSetTimings(x) gApp.sendUdsServiceSetTimings((x));

#define DK_RTE_Send_GipDiagRequest(x) gApp.sendGipDiagRequest((x));

#define DK_RTE_Send_DoIPDownloadRequest(x) gApp.sendDoIPDownloadRequest((x));

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_EINS_UDS_APPL_COMPONENT_H

