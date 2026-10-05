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
// Date: Thu Mar 12 18:15:53 IST 2026
// User: KRAMESH5
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DK_RUNTIME_TYPES_H
#define DK_RUNTIME_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include "dk_runtime_primitive_types.h"

#ifdef __cplusplus
namespace dk
{
namespace runtime
{
#endif


typedef uint32_t uint32;

typedef uint16_t uint16;

typedef uint8_t uint8;

typedef int8_t sint8;

typedef uint8 data_u8_2[2];

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 status;
} DLTMessageReadAck;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 status;
} DLTControlMessageRequest;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 status;
} DLTMessageReadRequest;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 status;
} DLTControlMessageReponse;

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

