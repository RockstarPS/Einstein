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

//< Message Data Types
typedef uint8_t EDomainId_t;
#define EDomainId_VP        ((EDomainId_t)0)
#define EDomainId_Cluster        ((EDomainId_t)1)
#define EDomainId_IVI        ((EDomainId_t)2)
#define EDomainId_Last        ((EDomainId_t)3)

typedef uint8_t ESystemState_t;
#define ESystemState_Off        ((ESystemState_t)0)
#define ESystemState_Startup        ((ESystemState_t)1)
#define ESystemState_Up        ((ESystemState_t)2)
#define ESystemState_FullRun        ((ESystemState_t)3)
#define ESystemState_PrepareShutdown        ((ESystemState_t)4)
#define ESystemState_Minimal        ((ESystemState_t)5)
#define ESystemState_Meet        ((ESystemState_t)6)
#define ESystemState_Shutdown        ((ESystemState_t)7)
#define ESystemState_Last        ((ESystemState_t)8)

typedef uint32_t uint32;

typedef uint16_t uint16;

typedef uint8_t uint8;

typedef int8_t sint8;

typedef struct
{
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 hour;
    uint8 min;
    uint8 sec;
} SDateTime_t;
typedef uint8_t ECompState_t;
#define ECompState_Init        ((ECompState_t)0)
#define ECompState_Start        ((ECompState_t)1)
#define ECompState_Run        ((ECompState_t)2)
#define ECompState_Stop        ((ECompState_t)3)
#define ECompState_Shutdown        ((ECompState_t)4)
#define ECompState_Last        ((ECompState_t)5)

typedef int32_t sint32;

typedef uint8 data_u8_8[8];

typedef uint8 data_u8_32[32];

typedef uint8_t EDisplayPower_t;
#define EDisplayPower_Off        ((EDisplayPower_t)0)
#define EDisplayPower_On        ((EDisplayPower_t)1)
#define EDisplayPower_Last        ((EDisplayPower_t)2)

typedef uint8_t EDisplayStatus_t;
#define EDisplayState_Off        ((EDisplayStatus_t)0)
#define EDisplayState_On        ((EDisplayStatus_t)1)
#define EDisplayState_Error        ((EDisplayStatus_t)2)
#define EDisplayState_Disconnected        ((EDisplayStatus_t)3)
#define EDisplayState_Last        ((EDisplayStatus_t)4)

typedef uint8 data_u8_64[64];

typedef uint8 data_u8_2048[2048];

typedef struct
{
    uint8 Shift_Ind_Pos;
    uint8 Shift_Ind_BlinkReq;
    uint8 Shift_Ind_Up;
    uint8 Shift_Ind_Down;
    uint8 Shift_Ind_DisplayDecState;
    uint8 Shift_Ind_Screen_ShiftType;
} SShiftInd;

typedef uint8 data_u8_10[10];

typedef uint8 data_u8_15[15];

typedef uint8 data_u8_2[2];

typedef uint8_t EGaugeUnit_t;
#define EGaugeUnit_Mph        ((EGaugeUnit_t)0)
#define EGaugeUnit_Kmph        ((EGaugeUnit_t)1)
#define EGaugeUnit_Centigrade        ((EGaugeUnit_t)2)
#define EGaugeUnit_Farenheit        ((EGaugeUnit_t)3)
#define EGaugeUnit_Psi        ((EGaugeUnit_t)4)
#define EGaugeUnit_Pa        ((EGaugeUnit_t)5)
#define EGaugeUnit_Bar        ((EGaugeUnit_t)6)
#define EGaugeUnit_Kmpl        ((EGaugeUnit_t)7)
#define EGaugeUnit_Mpg        ((EGaugeUnit_t)8)
#define EGaugeUnit_Ltr        ((EGaugeUnit_t)9)
#define EGaugeUnit_Gal        ((EGaugeUnit_t)10)
#define EGaugeUnit_Km        ((EGaugeUnit_t)11)
#define EGaugeUnit_Mile        ((EGaugeUnit_t)12)
#define EGaugeUnit_Last        ((EGaugeUnit_t)13)

typedef struct
{
    uint8 id;
    uint16 position;
    uint32 digitalData;
    EGaugeUnit_t unit;
    uint32 dynData;
} SGaugeInfo_u32dyn;

typedef uint8_t ERoutineType_t;
#define ERoutineType_Start        ((ERoutineType_t)0)
#define ERoutineType_Stop        ((ERoutineType_t)1)
#define ERoutineType_QueryResults        ((ERoutineType_t)2)
#define ERoutineType_Last        ((ERoutineType_t)3)

typedef uint8_t EIOCtrlOptType_t;
#define EIOCtrlOptType_returnControlToECU        ((EIOCtrlOptType_t)0)
#define EIOCtrlOptType_resetToDefault        ((EIOCtrlOptType_t)1)
#define EIOCtrlOptType_freezeCurrentState        ((EIOCtrlOptType_t)2)
#define EIOCtrlOptType_shortTermAdjustment        ((EIOCtrlOptType_t)3)
#define EIOCtrlOptType_Last        ((EIOCtrlOptType_t)4)

typedef uint8_t EDidType_t;
#define EDidType_Read        ((EDidType_t)0)
#define EDidType_Write        ((EDidType_t)1)
#define EDidType_Last        ((EDidType_t)2)

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

typedef uint8_t ESidType_t;
#define ESidType_EcuReset        ((ESidType_t)17)
#define ESidType_ReadDid        ((ESidType_t)34)
#define ESidType_WriteDid        ((ESidType_t)46)
#define ESidType_IoCtrl        ((ESidType_t)47)
#define ESidType_RoutineId        ((ESidType_t)49)

typedef uint8 data_u8_100[100];

typedef uint8_t ELinkStatus_t;
#define ELinkStatus_Up        ((ELinkStatus_t)0)
#define ELinkStatus_Down        ((ELinkStatus_t)1)



typedef uint8_t EVlanRequestType_t;
#define EVlanRequestType_Create        ((EVlanRequestType_t)0)
#define EVlanRequestType_Destroy        ((EVlanRequestType_t)1)

typedef uint8_t EModifyInterfaceReqType_t;
#define EModifyInterfaceReqType_Set        ((EModifyInterfaceReqType_t)0)
#define EModifyInterfaceReqType_Clear        ((EModifyInterfaceReqType_t)1)

typedef uint8_t EnetReqCmd_t;
#define EnetReqType_Reset        ((EnetReqCmd_t)1)
#define EnetReqType_linkStatus        ((EnetReqCmd_t)2)
#define EnetReqType_SqiVal        ((EnetReqCmd_t)3)
#define EnetReqType_WorstSqiVal        ((EnetReqCmd_t)4)
#define EnetReqType_BestSqiVal        ((EnetReqCmd_t)5)
#define EnetReqType_FaultStatus        ((EnetReqCmd_t)6)
#define EnetReqType_CableStatus        ((EnetReqCmd_t)7)
#define EnetReqType_masterSlaveStatus        ((EnetReqCmd_t)8)
#define EnetReqType_Last        ((EnetReqCmd_t)9)

typedef uint8_t EnetReqMode_t;
#define EnetReqMode_Read        ((EnetReqMode_t)0)
#define EnetReqMode_Write        ((EnetReqMode_t)1)
#define EnetReqMode_Last        ((EnetReqMode_t)2)

typedef struct
{
    uint8_t compId;
    uint8_t msgCnt;
} DKMsgBase_t;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    ESystemState_t state;
} PowerSystemState;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 timeoutMs;
} PowerExtendShutdownTime;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 timeoutMs;
} PowerKeepSystemAwake;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    ESystemState_t state;
} PowerSystemStateReqChange;
typedef struct
{
    DKMsgBase_t base;
    SDateTime_t dateTime;
} RTC;

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
} UCL_ERROR_NOTIFY;

typedef struct
{
    DKMsgBase_t base;
    sint32 status;
} UCL_LINK_STATUS;

typedef struct
{
    DKMsgBase_t base;
    uint8 compIdx;
} HealthGetStatus;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 seqCnt;
} HealthDomainHeartbeat;

typedef struct
{
    DKMsgBase_t base;
    EDomainId_t domainId;
    uint32 compIdx;
} HealthDomainFatalError;

typedef struct
{
    DKMsgBase_t base;
    uint8 recordType;
    uint8 recordLen;
    data_u8_8 recordData;
} HealthEventRecord;

typedef struct
{
    DKMsgBase_t base;
    uint32 fileSize;
} HealthDumpHdrInfo;

typedef struct
{
    DKMsgBase_t base;
    uint32 chunkSize;
    data_u8_32 data;
} HealthDumpData;

typedef struct
{
    DKMsgBase_t base;
    uint8 encrypt;
} HealthDumpGetHdr;

typedef struct
{
    DKMsgBase_t base;
    uint8 reserved;
} HealthDumpGetData;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
    EDisplayPower_t state;
} DisplaySetPower;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
} DisplayGetState;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} MainHMIReadyStatus;

typedef struct
{
    DKMsgBase_t base;
    uint32 displayId;
    EDisplayStatus_t state;
} DisplayCurrentState;

typedef struct
{
    DKMsgBase_t base;
    uint32 errorCode;
} EmmcErrorNotifier;

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
    uint8 status;
} SafeHMIReadyStatus;

typedef struct
{
    DKMsgBase_t base;
    SShiftInd status;
} ShiftPosIndStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 visible;
    uint16 warningId;
    data_u8_10 dynData;
} WarningStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 status;
} WarningDisplayAvailable;

typedef struct
{
    DKMsgBase_t base;
    data_u8_15 mask;
} TT_Status;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 mask;
} RTT_Status;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 mask;
} FRTT_Status;

typedef struct
{
    DKMsgBase_t base;
    uint8 positions;
    uint8 display;
} RTT_Toggle;

typedef struct
{
    DKMsgBase_t base;
    data_u8_2 icon;
} RTT_Icon;

typedef struct
{
    DKMsgBase_t base;
    uint8 show;
    uint16 warningId;
    data_u8_8 dynData;
} WarningDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 show;
    uint16 warningId;
    data_u8_8 dynData;
} WarningExtDisplay;

typedef struct
{
    DKMsgBase_t base;
    uint8 data;
    uint8 dayStep;
    uint8 nightStep;
    uint8 daynightStatus;
} IlluminationData;

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
    uint8 serviceId;
    uint8 responseType;
    uint16 clientAddress;
    uint16 dataLen;
    data_u8_7168 data;
} UdsServiceResponseTransmitRequest;

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
    uint32 p2TimeMs;
    uint32 p2StarTimeMs;
    uint32 p4TimeMs;
} UdsServiceSetTimings;

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
    bool_t networkFirewallStatus;
} NetworkModifyFirewallStatus;
typedef struct
{
    DKMsgBase_t base;
    EnetReqCmd_t cmd;
    EnetReqMode_t mode;
    uint8 dataLen;
    data_u8_32 data;
} EnetRegReq;
typedef uint8 data_u8_256[256];

typedef struct
{
    uint8 id;
    uint16 position;
    sint32 digitalData;
    EGaugeUnit_t unit;
    uint16 dynData;
} SGaugeInfo;

typedef SGaugeInfo_u32dyn SGaugeInfo_u32dyn_3[3];

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
    SGaugeInfo_u32dyn_3 gaugeInfo;
} FastGaugeInfo;

typedef struct
{
    DKMsgBase_t base;
    uint8 responseCode;
    uint16 dataLen;
    data_u8_256 data;
} DiagResponse;

typedef struct
{
    DKMsgBase_t base;
    uint16 routineId;
    ERoutineType_t routineType;
    uint16 dataLen;
    data_u8_256 data;
} DiagRoutineRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EIOCtrlOptType_t optionCtrl;
    uint16 dataLen;
    data_u8_256 data;
} DiagIOCtrlRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 did;
    EDidType_t didType;
    uint16 dataLen;
    data_u8_256 data;
} DiagDIDRequest;

typedef struct
{
    DKMsgBase_t base;
    ESidType_t serviceId;
    uint16 didId;
    uint8 controlOpLen;
    data_u8_8 controlOp;
    uint16 dataLen;
    data_u8_256 data;
} GipDiagRequest;

typedef struct
{
    DKMsgBase_t base;
    ESidType_t sid;
    uint16 didId;
    uint8 responseCode;
    uint8 controlOpLen;
    data_u8_8 controlOp;
    uint16 responseLen;
    data_u8_256 response;
} GipDiagResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    ELinkStatus_t linkStatus;
    uint8 ipAddressLength;
    data_u8_256 ipAddress;
} NetworkInterfaceStatus;

typedef struct
{
    DKMsgBase_t base;
    ELinkStatus_t interfaceRequestType;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
} NetworkModifyLinkStatus;

typedef struct
{
    DKMsgBase_t base;
    EVlanRequestType_t requestType;
    uint8 vlanNameLength;
    data_u8_256 vlanName;
    uint16 vlanTag;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    uint8 vlanPriority;
} NetworkModifyVlanInterface;

typedef struct
{
    DKMsgBase_t base;
    EModifyInterfaceReqType_t requestType;
    uint8 interfaceNameLength;
    data_u8_256 interfaceName;
    ELinkStatus_t linkStatus;
    uint8 ipAddressLength;
    data_u8_256 ipAddress;
    uint8 netMaskLength;
    data_u8_256 netMask;
    uint8 broadcastAddressLength;
    data_u8_256 broadcastAddress;
} NetworkModifyInterface;
typedef SGaugeInfo SGaugeInfo_2[2];

typedef struct
{
    DKMsgBase_t base;
    SGaugeInfo_2 gaugeInfo;
} SlowGaugeInfo;

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

