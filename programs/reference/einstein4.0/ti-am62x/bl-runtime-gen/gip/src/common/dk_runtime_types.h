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
// Date: Tue Oct 01 17:31:26 IST 2024
// User: KRAMESH5
// System: GIP
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
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
typedef uint16_t uint16;

typedef uint8_t uint8;

typedef uint8 data_u8_64[64];

typedef uint32_t uint32;

typedef uint8 data_u8_2048[2048];

typedef uint8_t ECompState_t;
#define ECompState_Init        ((ECompState_t)0)
#define ECompState_Start        ((ECompState_t)1)
#define ECompState_Run        ((ECompState_t)2)
#define ECompState_Stop        ((ECompState_t)3)
#define ECompState_Shutdown        ((ECompState_t)4)
#define ECompState_Last        ((ECompState_t)5)

typedef int32_t sint32;

typedef uint8 data_u8_256[256];

typedef uint8_t EDisplayStatus_t;
#define EDisplayState_Off        ((EDisplayStatus_t)0)
#define EDisplayState_On        ((EDisplayStatus_t)1)
#define EDisplayState_Error        ((EDisplayStatus_t)2)
#define EDisplayState_Disconnected        ((EDisplayStatus_t)3)
#define EDisplayState_Last        ((EDisplayStatus_t)4)

typedef uint8 data_u8_7168[7168];

typedef uint8 data_u8_17[17];

typedef uint8 data_u8_6[6];

typedef struct
{
    uint8 ipAddressNetwork1;
    uint8 ipAddressNetwork2;
    uint8 ipAddressHost1;
    uint8 ipAddressHost2;
    uint16 portNum;
} SDoIPSetNetworkInformation;

typedef uint8_t EUdsTimeout_t;
#define EUdsTimeout_Session        ((EUdsTimeout_t)0)
#define EUdsTimeout_Service        ((EUdsTimeout_t)1)

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    uint16 msgId;
    uint16 msgSize;
    uint8 sid;
    uint16 length;
    uint8 responseCode;
    uint8 NRC;
    data_u8_64 data;
} UpdateShortServiceResp;

typedef struct
{
    DKMsgBase_t base;
    uint16 msgId;
    uint16 msgSize;
    uint8 memoryType;
    uint8 memoryCmd;
    uint8 sid;
    uint32 length;
    data_u8_64 data;
} UpdateShortServiceReq;

typedef struct
{
    DKMsgBase_t base;
    uint16 msgId;
    uint16 msgSize;
    uint8 memoryType;
    uint8 memoryCmd;
    uint8 sid;
    uint32 length;
    data_u8_2048 data;
} UpdateLongServiceReq;

typedef struct
{
    DKMsgBase_t base;
    uint8 enable;
    uint32 requiredTimeMs;
} PowerSystemStateReqWakeLock;

typedef struct
{
    DKMsgBase_t base;
    ECompState_t state;
} PowerReportCompState;

typedef struct
{
    DKMsgBase_t base;
    sint32 errorCode;
} UclErrorNotify;

typedef struct
{
    DKMsgBase_t base;
    sint32 status;
} UclLinkStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 compIdx;
} HealthGetStatus;

typedef struct
{
    DKMsgBase_t base;
    uint32 timestamp;
    uint16 dataLen;
    data_u8_256 data;
} HealthStatusReport;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
    EDisplayStatus_t state;
} DisplayCurrentState;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
} DisplayGetState;

typedef struct
{
    DKMsgBase_t base;
    uint32 serviceId;
    uint32 blkaddress;
    uint32 blklength;
    uint8 formatId;
    uint8 CompEncId;
    uint32 dataLen;
    data_u8_7168 data;
} DoIPDownloadRequest;

typedef struct
{
    DKMsgBase_t base;
    uint32 serviceId;
    uint32 dataLen;
    data_u8_7168 data;
    uint8 result;
} DoIPDownloadResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 sourceAddress;
    uint16 targetAddress;
    uint8 targetAddressType;
    uint16 dataLen;
    data_u8_7168 data;
    uint8 result;
} DoipDiagDataIndication;

typedef struct
{
    DKMsgBase_t base;
    uint16 targetAddress;
    uint16 sourceAddress;
    uint8 targetAddressType;
    uint8 result;
} DoipDiagDataConfirmation;

typedef struct
{
    DKMsgBase_t base;
    uint8 isVinNumValid;
    uint8 isGidNumValid;
    uint8 isEidNumValid;
    data_u8_17 vinNumber;
    data_u8_6 eidNumber;
    data_u8_6 gidNumber;
    SDoIPSetNetworkInformation ipConfig;
    uint8 isNetWorkConfigValid;
    uint8 gidSyncStatus;
    uint8 isGidSyncStatusValid;
} DoipSetParams;

typedef struct
{
    DKMsgBase_t base;
    uint16 sourceAddress;
    uint16 targetAddress;
    uint8 targetAddressType;
    uint16 dataLen;
    data_u8_7168 data;
    uint8 result;
} DoipDiagDataTransferRequest;

typedef struct
{
    DKMsgBase_t base;
    uint8 powerMode;
} DoipDiagPowerModeStatus;

typedef struct
{
    DKMsgBase_t base;
    EUdsTimeout_t timeoutType;
    uint16 clientAddress;
} UdsTimeout;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 responseType;
    uint16 clientAddress;
} UdsServiceResponseTransmitConfirmation;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 requestType;
    uint16 clientAddress;
    uint16 dataLen;
    data_u8_7168 data;
} UdsServiceReqIndication;

typedef struct
{
    DKMsgBase_t base;
    uint8 serviceId;
    uint8 responseType;
    uint16 clientAddress;
    uint16 dataLen;
    data_u8_7168 data;
} UdsServiceResponseTransmitRequest;

typedef struct
{
    DKMsgBase_t base;
    uint32 p2TimeMs;
    uint32 p2StarTimeMs;
    uint32 p4TimeMs;
} UdsServiceSetTimings;

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

