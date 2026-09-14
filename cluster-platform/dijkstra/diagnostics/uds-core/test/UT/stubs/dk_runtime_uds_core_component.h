//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.4
// Date: Tue Oct 05 14:20:19 IST 2021
// User: SSHANKA8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_RUNTIME_UDS_CORE_COMPONENT_H
#define DK_RUNTIME_UDS_CORE_COMPONENT_H

#include "dk_runtime_messages.h"
#include "dk_runtime_component.h"
#include "fota_gp_app.h"

#ifdef __cplusplus
namespace dk
{
namespace runtime
{
#endif

#define DK_RTE_Send_UdsTimeout(x) gApp.sendUdsTimeout((x));

#define DK_RTE_Send_UdsServiceResponseTransmitConfirmation(x) gApp.sendUdsServiceResponseTransmitConfirmation((x));

#define DK_RTE_Send_DoipDiagDataTransferRequest(x) gApp.sendDoipDiagDataTransferRequest((x));

#define DK_RTE_Send_UdsServiceReqIndication(x) gApp.sendUdsServiceReqIndication((x));

#define DK_RTE_Send_UdsTimeout_DTool(x) gApp.sendUdsTimeout_DTool((x));

#define DK_RTE_Send_UdsServiceResponseTransmitConfirmation_DTool(x) gApp.sendUdsServiceResponseTransmitConfirmation_DTool((x));

#define DK_RTE_Send_DoipDiagDataTransferRequest_DTool(x) gApp.sendDoipDiagDataTransferRequest_DTool((x));

#define DK_RTE_Send_UdsServiceReqIndication_DTool(x) gApp.sendUdsServiceReqIndication_DTool((x));


#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_UDS_CORE_COMPONENT_H

