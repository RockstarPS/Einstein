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
// Date: Tue Mar 04 16:20:30 IST 2025
// User: AANITHA
// System: GIP
// Configuration: Platform
// Project: EU_BMW_MIC
// Message Catalogue version : 1.0.20
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

typedef uint8_t ECompState_t;
#define ECompState_Init        ((ECompState_t)0)
#define ECompState_Start        ((ECompState_t)1)
#define ECompState_Run        ((ECompState_t)2)
#define ECompState_Stop        ((ECompState_t)3)
#define ECompState_Shutdown        ((ECompState_t)4)
#define ECompState_Last        ((ECompState_t)5)

typedef int32_t sint32;

typedef uint8_t EDateFormat_t;
#define EDateFormat_12th        ((EDateFormat_t)0)
#define EDateFormat_24th        ((EDateFormat_t)1)
#define EDateFormat_UNKNOWN        ((EDateFormat_t)255)

typedef uint8 data_u8_8[8];

typedef uint8 data_u8_32[32];

typedef uint8_t EGNSSFixedStatusReceiver_t;
#define EGNSSFixedStatusReceiver_No_fix_no_reception        ((EGNSSFixedStatusReceiver_t)0)
#define EGNSSFixedStatusReceiver_2D_fix        ((EGNSSFixedStatusReceiver_t)1)
#define EGNSSFixedStatusReceiver_3D_fix        ((EGNSSFixedStatusReceiver_t)2)
#define EGNSSFixedStatusReceiver_UNKNOWN        ((EGNSSFixedStatusReceiver_t)255)

typedef uint8 data_u8_336[336];

typedef uint8 data_u8_18[18];

typedef uint8_t GearEnumType_t;
#define Gear_1        ((GearEnumType_t)0)
#define Gear_N        ((GearEnumType_t)1)
#define Gear_2        ((GearEnumType_t)2)
#define Gear_3        ((GearEnumType_t)3)
#define Gear_4        ((GearEnumType_t)4)
#define Gear_5        ((GearEnumType_t)5)
#define Gear_6        ((GearEnumType_t)6)
#define Gear_R        ((GearEnumType_t)7)
#define No_Gear        ((GearEnumType_t)8)
#define Gear_P        ((GearEnumType_t)9)
#define Unknown        ((GearEnumType_t)255)

typedef uint8_t ESidType_t;
#define ESidType_EcuReset        ((ESidType_t)17)
#define ESidType_ReadDid        ((ESidType_t)34)
#define ESidType_WriteDid        ((ESidType_t)46)
#define ESidType_IoCtrl        ((ESidType_t)47)
#define ESidType_RoutineId        ((ESidType_t)49)

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

typedef uint8 data_u8_7168[7168];

typedef uint8_t EUdsTimeout_t;
#define EUdsTimeout_Session        ((EUdsTimeout_t)0)
#define EUdsTimeout_Service        ((EUdsTimeout_t)1)

typedef struct
{
    uint32 PointOne_Time;
    uint32 GPS_Time;
    uint8 Solution_Type;
    uint16 Undulation;
    uint32 Height;
    uint32 Latitude;
    uint32 Longitude;
} SGnssData_t;

typedef uint8_t EMeetGNSSType_t;
#define EMeetGNSSType_ReadData        ((EMeetGNSSType_t)0)
#define EMeetGNSSType_ReadGPIO        ((EMeetGNSSType_t)1)
#define EMeetGNSSType_ReadSwVersionNo        ((EMeetGNSSType_t)2)
#define EMeetGNSSType_UNKNOWN        ((EMeetGNSSType_t)255)

typedef uint8_t EMeetGNSSStatus_t;
#define EMeetGNSSStatus_OK        ((EMeetGNSSStatus_t)0)
#define EMeetGNSSStatus_NOK        ((EMeetGNSSStatus_t)1)
#define EMeetGNSSStatus_BUSY        ((EMeetGNSSStatus_t)2)
#define EMeetGNSSStatus_UNKNOWN        ((EMeetGNSSStatus_t)255)

typedef uint8_t EDidType_t;
#define EDidType_Read        ((EDidType_t)0)
#define EDidType_Write        ((EDidType_t)1)
#define EDidType_Last        ((EDidType_t)2)

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

typedef struct
{
    uint8 MajorVersion;
    uint8 MinorVersion;
    uint8 PatchVersion;
    uint8 ProcessClass;
    uint32 SGBM_ID;
} SSVKType;

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
    bool_t ServiceAvailability;
} BasicRidingFunctionsStatus;

typedef struct
{
    DKMsgBase_t base;
    uint8 dummyByte;
} SwVersionForCRUGetterRequest;

typedef struct
{
    DKMsgBase_t base;
    uint32 gNSSPositionDegreeOfLatitude;
    uint32 gNSSPositionDegreeOfLongitude;
    uint16 gNSSPositionAltitude;
    uint16 gNSSSpeedHorizontal;
    uint16 gNSSCourseangle;
    uint8 gNSSErrorLatitudePosition;
    uint8 gNSSErrorLongitudePosition;
    uint8 gNSSQuantitySatelliteUsage;
    EGNSSFixedStatusReceiver_t gNSSFixedStatusReceiver;
} currentGNSSposition;

typedef struct
{
    DKMsgBase_t base;
    data_u8_336 nmeaDataofGNSSReceiverString;
} nmeaDataofGNSSReceiver;

typedef struct
{
    DKMsgBase_t base;
    uint16 bankingAngleOfVehicle;
    uint16 accelerationOfVehicle;
    uint16 yawRateOfVehicle;
    uint16 rollRateOfVehicle;
    uint16 pitchRateOfVehicle;
} vehicleGyroData;

typedef struct
{
    DKMsgBase_t base;
    uint8 swVersionMajorCRU;
    uint8 swVersionMediumCRU;
    uint8 swVersionMinorCRU;
} SwVersionForCRUGetterResponse;

typedef struct
{
    DKMsgBase_t base;
    uint8 swVersionMajorCRU;
    uint8 swVersionMediumCRU;
    uint8 swVersionMinorCRU;
} SwVersionForCRUNotifier;

typedef struct
{
    DKMsgBase_t base;
    bool_t RequestAbsTelltale;
} RequestSafetyTelltales;

typedef struct
{
    DKMsgBase_t base;
    data_u8_18 boostdata;
} SetBoostPattern;

typedef struct
{
    DKMsgBase_t base;
    bool_t bmwHmiState;
} BmwHmiStatus;

typedef struct
{
    DKMsgBase_t base;
    GearEnumType_t GearStatus;
} GearboxData;

typedef struct
{
    DKMsgBase_t base;
    uint16 pGnssMountingImuRoll;
    uint16 pGnssMountingImuYaw;
    uint16 pGnssMountingImuPitch;
    uint8 pGnssReferencePointShift;
    uint8 pGnssLeverarmAntX;
    uint8 pGnssLeverarmAntZ;
    uint8 pGnssLeverarmAntY;
    uint8 pGnssLeverarmModuleZ;
    uint8 pGnssLeverarmModuleY;
    uint8 pGnssLeverarmModuleX;
    uint8 sfBacklightBrightnessDefault;
    uint8 bLThresholdDeviationFromTarget;
    bool_t cruEnable;
} CodingData;

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
    uint32 p2TimeMs;
    uint32 p2StarTimeMs;
    uint32 p4TimeMs;
} UdsServiceSetTimings;

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
    uint8 powerMode;
} DoipDiagPowerModeStatus;

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
    uint8 MagicFlagWriteStatus;
} MagicFlagWriteResp;

typedef struct
{
    DKMsgBase_t base;
    uint8 gnssData;
} RequestGnssDataForDiag;

typedef struct
{
    DKMsgBase_t base;
    uint8 MagicFlag;
} WriteMagicFlagRequest;

typedef struct
{
    DKMsgBase_t base;
    SGnssData_t gnssDiagData;
} SendGnssDataForDiag;

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
    EMeetGNSSType_t requestType;
} MeetGNSSRequest;

typedef struct
{
    DKMsgBase_t base;
    uint16 vehicleSpeed;
} VehicleInfoData;

typedef struct
{
    DKMsgBase_t base;
    SSVKType svkKernel;
    SSVKType svkRecoveryKernel;
    SSVKType svkRootFs;
    SSVKType svkRecoveryRootFs;
    SSVKType svkSystem;
    SSVKType svkVisteonApp;
    SSVKType svkBmwHmiApp;
    SSVKType svkCru;
} BmwSweLogistics;

typedef uint8 data_u8_256[256];

typedef struct
{
    uint8 hour;
    uint8 minutes;
    uint8 seconds;
    uint8 day;
    uint8 month;
    uint16 year;
    EDateFormat_t timeFormat;
} SDateTime;

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
    SDateTime dateTime;
} RTC;

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
    ESidType_t serviceId;
    uint16 didId;
    uint8 controlOpLen;
    data_u8_8 controlOp;
    uint16 dataLen;
    data_u8_256 data;
} VipDiagRequest;

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
} GIP2VIPDiagResp;

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
} VipDiagResponse;

typedef struct
{
    DKMsgBase_t base;
    ESidType_t serviceId;
    uint16 didId;
    uint8 controlOpLen;
    data_u8_8 controlOp;
    uint16 dataLen;
    data_u8_256 data;
} VIP2GIPDiagRequest;

typedef struct
{
    DKMsgBase_t base;
    EMeetGNSSType_t responseType;
    EMeetGNSSStatus_t status;
    uint16 length;
    data_u8_256 data;
} MeetGNSSSResp;

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
    uint16 did;
    EDidType_t didType;
    uint16 dataLen;
    data_u8_256 data;
} DiagDIDRequest;

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

#ifdef __cplusplus
} // runtime
} // dk
#endif
#endif //DK_RUNTIME_TYPES_H

