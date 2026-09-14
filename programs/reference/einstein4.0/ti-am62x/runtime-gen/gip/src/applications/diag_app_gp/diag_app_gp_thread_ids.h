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
// Date: Thu Mar 12 18:15:54 IST 2026
// User: KRAMESH5
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.8
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DIAG_APP_GP_THREAD_IDS_H
#define DIAG_APP_GP_THREAD_IDS_H

enum TID : unsigned
{
#define PTH_ID
#include "diag_app_gp_threads.h"
#undef PTH_ID
	TID_COUNT
};

#endif //DIAG_APP_GP_THREAD_IDS_H

