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
// Date: Thu Aug 22 07:38:13 IST 2024
// User: KRAMESH5
// System: GIP
// Configuration: Platform
// Project: TOYOTA_7XXD
// Message Catalogue version : 1.0.2
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef SAFE_HMI_THREAD_IDS_H
#define SAFE_HMI_THREAD_IDS_H

enum TID : unsigned
{
#define PTH_ID
#include "safe_hmi_threads.h"
#undef PTH_ID
	TID_COUNT
};

#endif //SAFE_HMI_THREAD_IDS_H

