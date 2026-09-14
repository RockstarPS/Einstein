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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Wed Oct 21 19:36:46 IST 2020
// User: SSINGH25
// System: GIP
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

//< Message Data Types
typedef uint32_t uint32;

typedef uint8_t uint8;

typedef uint16_t uint16;

typedef uint8 bool_t;

typedef float64_t float64;

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    uint32 var1;
    uint32 var2;
} DkMsgTestMsg_t;

typedef struct
{
    DKMsgBase_t base;
    uint8 var_uint8;
    uint16 var_uint16;
    bool_t var_bool;
} DkMsgTestTransmit_t;

typedef struct
{
    DKMsgBase_t base;
    uint32 var_u32;
} DkMsgTestTransmitU32_t;

typedef struct
{
    DKMsgBase_t base;
    float64 var_f64;
} DkMsgTestTransmitF64_t;

typedef struct
{
    DKMsgBase_t base;
    uint8 var_ru8;
    uint16 var_ru16;
} DkMsgTest2Rcv_t;

typedef struct
{
    DKMsgBase_t base;
    uint8 uint8_t;
} DkMsg1byte_t;

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

