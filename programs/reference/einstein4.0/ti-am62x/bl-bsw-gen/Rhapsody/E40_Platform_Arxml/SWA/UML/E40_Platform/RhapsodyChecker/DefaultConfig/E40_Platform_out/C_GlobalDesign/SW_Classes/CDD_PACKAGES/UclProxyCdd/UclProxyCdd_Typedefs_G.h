#ifndef __UclProxyCdd_Typedefs_G_h__
#define __UclProxyCdd_Typedefs_G_h__
#ifndef _QAC_
// *********************************************************************************************************************
// Company:             Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:           This software is JCI property.
//                      Duplication or disclosure without JCI written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:             E40_Platform
// Language:            C
// ---------------------------------------------------------------------------------------------------------------------
// This file contains package types definition
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Fri Jul 26 12:05:08 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              UclProxyCdd (DesignUnit)
// Description:         None
// Owner:               CDD_PACKAGES (Package)
// ---------------------------------------------------------------------------------------------------------------------
// Rhapsody version:    9.0.1
// Generator version:   V3.0.27
// Generator date:      11/12/2014 12:04:26,40
// ---------------------------------------------------------------------------------------------------------------------
// PVCS section start
// PVCS Log:
// $Log: $
// PVCS section end
// *********************************************************************************************************************
#endif // #ifndef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                                   Types definition
// ---------------------------------------------------------------------------------------------------------------------

// Typedef type data_u8_4
#ifndef A2T_TypesProtection_data_u8_4
#define A2T_TypesProtection_data_u8_4
typedef uint8 data_u8_4[4];
#define tdata_u8_4 data_u8_4
#endif

// Typedef type data_u8_12
#ifndef A2T_TypesProtection_data_u8_12
#define A2T_TypesProtection_data_u8_12
typedef uint8 data_u8_12[12];
#define tdata_u8_12 data_u8_12
#endif

// Typedef type data_u8_70
#ifndef A2T_TypesProtection_data_u8_70
#define A2T_TypesProtection_data_u8_70
typedef uint8 data_u8_70[70];
#define tdata_u8_70 data_u8_70
#endif

// Enumeration type EGaugeUnit
#ifndef A2T_TypesProtection_EGaugeUnit
#define A2T_TypesProtection_EGaugeUnit
typedef enum {
    EGaugeUnit_Mph,
    EGaugeUnit_Kmph,
    EGaugeUnit_Centigrade,
    EGaugeUnit_Farenheit,
    EGaugeUnit_Psi,
    EGaugeUnit_Pa,
    EGaugeUnit_Bar,
    EGaugeUnit_Last
} EGaugeUnit;
#define eEGaugeUnit_Mph EGaugeUnit_Mph
#define eEGaugeUnit_Kmph EGaugeUnit_Kmph
#define eEGaugeUnit_Centigrade EGaugeUnit_Centigrade
#define eEGaugeUnit_Farenheit EGaugeUnit_Farenheit
#define eEGaugeUnit_Psi EGaugeUnit_Psi
#define eEGaugeUnit_Pa EGaugeUnit_Pa
#define eEGaugeUnit_Bar EGaugeUnit_Bar
#define eEGaugeUnit_Last EGaugeUnit_Last
#define tEGaugeUnit EGaugeUnit
#endif

// Enumeration type EDomainId
#ifndef A2T_TypesProtection_EDomainId
#define A2T_TypesProtection_EDomainId
typedef enum {
    EDomainId_VP,
    EDomainId_Cluster,
    EDomainId_IVI,
    EDomainId_Last
} EDomainId;
#define eEDomainId_VP EDomainId_VP
#define eEDomainId_Cluster EDomainId_Cluster
#define eEDomainId_IVI EDomainId_IVI
#define eEDomainId_Last EDomainId_Last
#define tEDomainId EDomainId
#endif

// Enumeration type ESystemState
#ifndef A2T_TypesProtection_ESystemState
#define A2T_TypesProtection_ESystemState
typedef enum {
    ESystemState_Off,
    ESystemState_Startup,
    ESystemState_Up,
    ESystemState_FullRun,
    ESystemState_PrepareShutdown,
    ESystemState_Minimal,
    ESystemState_Shutdown,
    ESystemState_Last
} ESystemState;
#define eESystemState_Off ESystemState_Off
#define eESystemState_Startup ESystemState_Startup
#define eESystemState_Up ESystemState_Up
#define eESystemState_FullRun ESystemState_FullRun
#define eESystemState_PrepareShutdown ESystemState_PrepareShutdown
#define eESystemState_Minimal ESystemState_Minimal
#define eESystemState_Shutdown ESystemState_Shutdown
#define eESystemState_Last ESystemState_Last
#define tESystemState ESystemState
#endif

// Enumeration type ECompState
#ifndef A2T_TypesProtection_ECompState
#define A2T_TypesProtection_ECompState
typedef enum {
    ECompState_Init,
    ECompState_Start,
    ECompState_Run,
    ECompState_Stop,
    ECompState_Shutdown,
    ECompState_Last
} ECompState;
#define eECompState_Init ECompState_Init
#define eECompState_Start ECompState_Start
#define eECompState_Run ECompState_Run
#define eECompState_Stop ECompState_Stop
#define eECompState_Shutdown ECompState_Shutdown
#define eECompState_Last ECompState_Last
#define tECompState ECompState
#endif

// Structure type SGaugeInfo
#ifndef A2T_TypesProtection_SGaugeInfo
#define A2T_TypesProtection_SGaugeInfo
typedef struct _SGaugeInfo_tag {
    uint8 id;
    uint16 position;
    sint32 digitalData;
    EGaugeUnit unit;
    uint16 dynData;
} SGaugeInfo;
#define tSGaugeInfo SGaugeInfo
#endif

// Structure type SWarningDisplay
#ifndef A2T_TypesProtection_SWarningDisplay
#define A2T_TypesProtection_SWarningDisplay
typedef struct _SWarningDisplay_tag {
    uint8 show;
    uint16 warningId;
    data_u8_4 dynData;
} SWarningDisplay;
#define tSWarningDisplay SWarningDisplay
#endif

// Structure type SWarningExtDisplay
#ifndef A2T_TypesProtection_SWarningExtDisplay
#define A2T_TypesProtection_SWarningExtDisplay
typedef struct _SWarningExtDisplay_tag {
    uint8 show;
    uint16 warningId;
    data_u8_20 dynData;
} SWarningExtDisplay;
#define tSWarningExtDisplay SWarningExtDisplay
#endif

// Structure type SRTT_Status
#ifndef A2T_TypesProtection_SRTT_Status
#define A2T_TypesProtection_SRTT_Status
typedef struct _SRTT_Status_tag {
    data_u8_35 mask;
} SRTT_Status;
#define tSRTT_Status SRTT_Status
#endif

// Structure type STT_Status
#ifndef A2T_TypesProtection_STT_Status
#define A2T_TypesProtection_STT_Status
typedef struct _STT_Status_tag {
    data_u8_12 mask;
} STT_Status;
#define tSTT_Status STT_Status
#endif

// Structure type SRTT_Toggle
#ifndef A2T_TypesProtection_SRTT_Toggle
#define A2T_TypesProtection_SRTT_Toggle
typedef struct _SRTT_Toggle_tag {
    uint8 positions;
    uint8 display;
} SRTT_Toggle;
#define tSRTT_Toggle SRTT_Toggle
#endif

// Structure type SFRTT_Status
#ifndef A2T_TypesProtection_SFRTT_Status
#define A2T_TypesProtection_SFRTT_Status
typedef struct _SFRTT_Status_tag {
    data_u8_35 mask;
} SFRTT_Status;
#define tSFRTT_Status SFRTT_Status
#endif

// Structure type SPowerSystemStateReqChange
#ifndef A2T_TypesProtection_SPowerSystemStateReqChange
#define A2T_TypesProtection_SPowerSystemStateReqChange
typedef struct _SPowerSystemStateReqChange_tag {
    ESystemState state;
    EDomainId domainId;
} SPowerSystemStateReqChange;
#define tSPowerSystemStateReqChange SPowerSystemStateReqChange
#endif

// Structure type SSlowGuageInfo
#ifndef A2T_TypesProtection_SSlowGuageInfo
#define A2T_TypesProtection_SSlowGuageInfo
typedef struct _SSlowGuageInfo_tag {
    SGaugeInfo gaugeInfo;
} SSlowGuageInfo;
#define tSSlowGuageInfo SSlowGuageInfo
#endif

// Structure type SFastGuageInfo
#ifndef A2T_TypesProtection_SFastGuageInfo
#define A2T_TypesProtection_SFastGuageInfo
typedef struct _SFastGuageInfo_tag {
    SGaugeInfo gaugeInfo_4;
} SFastGuageInfo;
#define tSFastGuageInfo SFastGuageInfo
#endif

// Structure type SWarningStatus
#ifndef A2T_TypesProtection_SWarningStatus
#define A2T_TypesProtection_SWarningStatus
typedef struct _SWarningStatus_tag {
    uint8 visible;
    uint16 warningId;
    SKeyVal1 dynData;
} SWarningStatus;
#define tSWarningStatus SWarningStatus
#endif

// Structure type SWarningDisplayAvailable
#ifndef A2T_TypesProtection_SWarningDisplayAvailable
#define A2T_TypesProtection_SWarningDisplayAvailable
typedef struct _SWarningDisplayAvailable_tag {
    uint8 status;
} SWarningDisplayAvailable;
#define tSWarningDisplayAvailable SWarningDisplayAvailable
#endif

// Structure type SPowerSystemState
#ifndef A2T_TypesProtection_SPowerSystemState
#define A2T_TypesProtection_SPowerSystemState
typedef struct _SPowerSystemState_tag {
    EDomainId domainId;
    ESystemState state;
} SPowerSystemState;
#define tSPowerSystemState SPowerSystemState
#endif

// Structure type SPowerKeepSystemAwake
#ifndef A2T_TypesProtection_SPowerKeepSystemAwake
#define A2T_TypesProtection_SPowerKeepSystemAwake
typedef struct _SPowerKeepSystemAwake_tag {
    EDomainId domainId;
    uint32 timeoutMs;
} SPowerKeepSystemAwake;
#define tSPowerKeepSystemAwake SPowerKeepSystemAwake
#endif

// Structure type SPowerExtendShutdownTime
#ifndef A2T_TypesProtection_SPowerExtendShutdownTime
#define A2T_TypesProtection_SPowerExtendShutdownTime
typedef struct _SPowerExtendShutdownTime_tag {
    EDomainId domainId;
    uint32 timeoutMs;
} SPowerExtendShutdownTime;
#define tSPowerExtendShutdownTime SPowerExtendShutdownTime
#endif

// Structure type SHealthDomainHeartbeat
#ifndef A2T_TypesProtection_SHealthDomainHeartbeat
#define A2T_TypesProtection_SHealthDomainHeartbeat
typedef struct _SHealthDomainHeartbeat_tag {
    EDomainId domainId;
    uint32 seqCnt;
} SHealthDomainHeartbeat;
#define tSHealthDomainHeartbeat SHealthDomainHeartbeat
#endif

// Structure type SHealthDomainFatalError
#ifndef A2T_TypesProtection_SHealthDomainFatalError
#define A2T_TypesProtection_SHealthDomainFatalError
typedef struct _SHealthDomainFatalError_tag {
    EDomainId domainId;
    uint32 compldx;
} SHealthDomainFatalError;
#define tSHealthDomainFatalError SHealthDomainFatalError
#endif

// Enumeration type ECompassValue
#ifndef A2T_TypesProtection_ECompassValue
#define A2T_TypesProtection_ECompassValue
typedef enum {
    ECompassValue_Off,
    ECompassValue_N,
    ECompassValue_NE,
    ECompassValue_E,
    ECompassValue_SE,
    ECompassValue_S,
    ECompassValue_SW,
    ECompassValue_W,
    ECompassValue_NW,
    ECompassValue_Last
} ECompassValue;
#define eECompassValue_Off ECompassValue_Off
#define eECompassValue_N ECompassValue_N
#define eECompassValue_NE ECompassValue_NE
#define eECompassValue_E ECompassValue_E
#define eECompassValue_SE ECompassValue_SE
#define eECompassValue_S ECompassValue_S
#define eECompassValue_SW ECompassValue_SW
#define eECompassValue_W ECompassValue_W
#define eECompassValue_NW ECompassValue_NW
#define eECompassValue_Last ECompassValue_Last
#define tECompassValue ECompassValue
#endif

// Structure type SCompassInfo
#ifndef A2T_TypesProtection_SCompassInfo
#define A2T_TypesProtection_SCompassInfo
typedef struct _SCompassInfo_tag {
    uint32 gpsCoordinatesLatDegDec;
    uint32 gpsCoordinatesLongDegDec;
    uint16 altitude;
    uint8 gpsCoordinatesLatDegInt;
    uint8 gpsCoordinatesLongDegInt;
    uint8 gpsCoordinatesLatLongHemispheres;
    ECompassValue compassDistance;
} SCompassInfo;
#define tSCompassInfo SCompassInfo
#endif

// Structure type SOdometer
#ifndef A2T_TypesProtection_SOdometer
#define A2T_TypesProtection_SOdometer
typedef struct _SOdometer_tag {
    EOdoStatus status;
    uint32 value;
    uint8 unit;
} SOdometer;
#define tSOdometer SOdometer
#endif

// Typedef type data_u8_8
#ifndef A2T_TypesProtection_data_u8_8
#define A2T_TypesProtection_data_u8_8
typedef uint8 data_u8_8[8];
#define tdata_u8_8 data_u8_8
#endif

// Structure type SKeyVal1
#ifndef A2T_TypesProtection_SKeyVal1
#define A2T_TypesProtection_SKeyVal1
typedef struct _SKeyVal1_tag {
    uint8 key;
    uint8 value;
} SKeyVal1;
#define tSKeyVal1 SKeyVal1
#endif

// Structure type SPersRecord1byte
#ifndef A2T_TypesProtection_SPersRecord1byte
#define A2T_TypesProtection_SPersRecord1byte
typedef struct _SPersRecord1byte_tag {
    SKeyVal1 data_10;
} SPersRecord1byte;
#define tSPersRecord1byte SPersRecord1byte
#endif

// Structure type SKeyVal8
#ifndef A2T_TypesProtection_SKeyVal8
#define A2T_TypesProtection_SKeyVal8
typedef struct _SKeyVal8_tag {
    uint8 key;
    data_u8_8 value;
} SKeyVal8;
#define tSKeyVal8 SKeyVal8
#endif

// Structure type SKeyVal4
#ifndef A2T_TypesProtection_SKeyVal4
#define A2T_TypesProtection_SKeyVal4
typedef struct _SKeyVal4_tag {
    uint8 key;
    data_u8_4 value;
} SKeyVal4;
#define tSKeyVal4 SKeyVal4
#endif

// Structure type SPersRecord4byte
#ifndef A2T_TypesProtection_SPersRecord4byte
#define A2T_TypesProtection_SPersRecord4byte
typedef struct _SPersRecord4byte_tag {
    SKeyVal4 data_5;
} SPersRecord4byte;
#define tSPersRecord4byte SPersRecord4byte
#endif

// Structure type SPersRecord8byte
#ifndef A2T_TypesProtection_SPersRecord8byte
#define A2T_TypesProtection_SPersRecord8byte
typedef struct _SPersRecord8byte_tag {
    SKeyVal8 data_2;
} SPersRecord8byte;
#define tSPersRecord8byte SPersRecord8byte
#endif

// Structure type SPersRecord
#ifndef A2T_TypesProtection_SPersRecord
#define A2T_TypesProtection_SPersRecord
typedef struct _SPersRecord_tag {
    SKeyVal8 data;
} SPersRecord;
#define tSPersRecord SPersRecord
#endif

// Structure type SDateTime
#ifndef A2T_TypesProtection_SDateTime
#define A2T_TypesProtection_SDateTime
typedef struct _SDateTime_tag {
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 hour;
    uint8 min;
    uint8 sec;
} SDateTime;
#define tSDateTime SDateTime
#endif

// Structure type SRTC
#ifndef A2T_TypesProtection_SRTC
#define A2T_TypesProtection_SRTC
typedef struct _SRTC_tag {
    SDateTime dateTime;
} SRTC;
#define tSRTC SRTC
#endif

// Enumeration type EOdoStatus
#ifndef A2T_TypesProtection_EOdoStatus
#define A2T_TypesProtection_EOdoStatus
typedef enum {
    EOdoStatus_Ok = 0,
    EOdoStatus_NVMError = 1,
    EOdoStatus_Missing = 2,
    EOdoStatus_Invalid = 4,
    EOdoStatus_DispDashes = 8,
    EOdoStatus_DispError = 16
} EOdoStatus;
#define eEOdoStatus_Ok EOdoStatus_Ok
#define eEOdoStatus_NVMError EOdoStatus_NVMError
#define eEOdoStatus_Missing EOdoStatus_Missing
#define eEOdoStatus_Invalid EOdoStatus_Invalid
#define eEOdoStatus_DispDashes EOdoStatus_DispDashes
#define eEOdoStatus_DispError EOdoStatus_DispError
#define tEOdoStatus EOdoStatus
#endif

// Typedef type data_u8_10
#ifndef A2T_TypesProtection_data_u8_10
#define A2T_TypesProtection_data_u8_10
typedef uint8 data_u8_10[10];
#define tdata_u8_10 data_u8_10
#endif

// Structure type SGearStatus
#ifndef A2T_TypesProtection_SGearStatus
#define A2T_TypesProtection_SGearStatus
typedef struct _SGearStatus_tag {
    data_u8_17 safeEprndlData;
} SGearStatus;
#define tSGearStatus SGearStatus
#endif

// Enumeration type ETrip
#ifndef A2T_TypesProtection_ETrip
#define A2T_TypesProtection_ETrip
typedef enum {
    ETrip_A,
    ETrip_B,
    ETrip_DC,
    ETrip_Last
} ETrip;
#define eETrip_A ETrip_A
#define eETrip_B ETrip_B
#define eETrip_DC ETrip_DC
#define eETrip_Last ETrip_Last
#define tETrip ETrip
#endif

// Structure type STripComputer
#ifndef A2T_TypesProtection_STripComputer
#define A2T_TypesProtection_STripComputer
typedef struct _STripComputer_tag {
    ETrip tripId;
    uint8 hour;
    uint8 minute;
    uint8 second;
    uint32 distance;
    uint32 distanceEV;
    uint8 distanceUnit;
    uint16 avgFuel;
    uint16 avgFuelEV;
    uint16 avgSpeed;
    uint16 avgElectricEfficiency;
    uint8 valid;
    uint16 avgFuelLPG;
} STripComputer;
#define tSTripComputer STripComputer
#endif

// Enumeration type EFuelEconomy
#ifndef A2T_TypesProtection_EFuelEconomy
#define A2T_TypesProtection_EFuelEconomy
typedef enum {
    EFuelEconomy_None,
    EFuelEconomy_DTE,
    EFuelEconomy_IFE,
    EFuelEconomy_IFETBS,
    EFuelEconomy_AFE_A,
    EFuelEconomy_AFE_B,
    EFuelEconomy_FEH,
    EFuelEconomy_DCFE,
    EFuelEconomy_eDCFE,
    EFuelEconomy_LTFE,
    EFuelEconomy_eLTFE,
    EFuelEconomy_RAFE,
    EFuelEconomy_DCAEE,
    EFuelEconomy_Last
} EFuelEconomy;
#define eEFuelEconomy_None EFuelEconomy_None
#define eEFuelEconomy_DTE EFuelEconomy_DTE
#define eEFuelEconomy_IFE EFuelEconomy_IFE
#define eEFuelEconomy_IFETBS EFuelEconomy_IFETBS
#define eEFuelEconomy_AFE_A EFuelEconomy_AFE_A
#define eEFuelEconomy_AFE_B EFuelEconomy_AFE_B
#define eEFuelEconomy_FEH EFuelEconomy_FEH
#define eEFuelEconomy_DCFE EFuelEconomy_DCFE
#define eEFuelEconomy_eDCFE EFuelEconomy_eDCFE
#define eEFuelEconomy_LTFE EFuelEconomy_LTFE
#define eEFuelEconomy_eLTFE EFuelEconomy_eLTFE
#define eEFuelEconomy_RAFE EFuelEconomy_RAFE
#define eEFuelEconomy_DCAEE EFuelEconomy_DCAEE
#define eEFuelEconomy_Last EFuelEconomy_Last
#define tEFuelEconomy EFuelEconomy
#endif

// Typedef type data_u8_5
#ifndef A2T_TypesProtection_data_u8_5
#define A2T_TypesProtection_data_u8_5
typedef uint8 data_u8_5[5];
#define tdata_u8_5 data_u8_5
#endif

// Structure type SFuelEconomy
#ifndef A2T_TypesProtection_SFuelEconomy
#define A2T_TypesProtection_SFuelEconomy
typedef struct _SFuelEconomy_tag {
    EFuelEconomy feType;
    uint16 value;
    uint8 valid;
    data_u8_8 dynData;
} SFuelEconomy;
#define tSFuelEconomy SFuelEconomy
#endif

// Structure type STripResetCmd
#ifndef A2T_TypesProtection_STripResetCmd
#define A2T_TypesProtection_STripResetCmd
typedef struct _STripResetCmd_tag {
    uint16 tripCmdId;
} STripResetCmd;
#define tSTripResetCmd STripResetCmd
#endif

// Typedef type data_u8_20
#ifndef A2T_TypesProtection_data_u8_20
#define A2T_TypesProtection_data_u8_20
typedef uint8 data_u8_20[20];
#define tdata_u8_20 data_u8_20
#endif

// Structure type SHealthDumpGetHdr
#ifndef A2T_TypesProtection_SHealthDumpGetHdr
#define A2T_TypesProtection_SHealthDumpGetHdr
typedef struct _SHealthDumpGetHdr_tag {
    uint8 encrypt;
} SHealthDumpGetHdr;
#define tSHealthDumpGetHdr SHealthDumpGetHdr
#endif

// Structure type SHealthDumpGetData
#ifndef A2T_TypesProtection_SHealthDumpGetData
#define A2T_TypesProtection_SHealthDumpGetData
typedef struct _SHealthDumpGetData_tag {
    uint8 reserved;
} SHealthDumpGetData;
#define tSHealthDumpGetData SHealthDumpGetData
#endif

// Structure type SHealthDumpHdrInfo
#ifndef A2T_TypesProtection_SHealthDumpHdrInfo
#define A2T_TypesProtection_SHealthDumpHdrInfo
typedef struct _SHealthDumpHdrInfo_tag {
    uint32 fileSize;
} SHealthDumpHdrInfo;
#define tSHealthDumpHdrInfo SHealthDumpHdrInfo
#endif

// Structure type SHealthDumpData
#ifndef A2T_TypesProtection_SHealthDumpData
#define A2T_TypesProtection_SHealthDumpData
typedef struct _SHealthDumpData_tag {
    uint32 chunkSize;
    data_u8_32 data;
} SHealthDumpData;
#define tSHealthDumpData SHealthDumpData
#endif

// Typedef type data_u8_32
#ifndef A2T_TypesProtection_data_u8_32
#define A2T_TypesProtection_data_u8_32
typedef uint8 data_u8_32[32];
#define tdata_u8_32 data_u8_32
#endif

// Enumeration type EDidType
#ifndef A2T_TypesProtection_EDidType
#define A2T_TypesProtection_EDidType
typedef enum {
    EDidType_Read,
    EDidType_Write,
    EDidType_Last
} EDidType;
#define eEDidType_Read EDidType_Read
#define eEDidType_Write EDidType_Write
#define eEDidType_Last EDidType_Last
#define tEDidType EDidType
#endif

// Structure type SDiagDIDRequest
#ifndef A2T_TypesProtection_SDiagDIDRequest
#define A2T_TypesProtection_SDiagDIDRequest
typedef struct _SDiagDIDRequest_tag {
    uint16 did;
    EDidType didType;
    uint16 dataLen;
    data_u8_256 data;
} SDiagDIDRequest;
#define tSDiagDIDRequest SDiagDIDRequest
#endif

// Typedef type data_u8_256
#ifndef A2T_TypesProtection_data_u8_256
#define A2T_TypesProtection_data_u8_256
typedef uint8 data_u8_256[256];
#define tdata_u8_256 data_u8_256
#endif

// Enumeration type ERoutineType
#ifndef A2T_TypesProtection_ERoutineType
#define A2T_TypesProtection_ERoutineType
typedef enum {
    ERoutineType_Start,
    ERoutineType_Stop,
    ERoutineType_QueryResults,
    ERoutineType_Last
} ERoutineType;
#define eERoutineType_Start ERoutineType_Start
#define eERoutineType_Stop ERoutineType_Stop
#define eERoutineType_QueryResults ERoutineType_QueryResults
#define eERoutineType_Last ERoutineType_Last
#define tERoutineType ERoutineType
#endif

// Structure type SDiagRoutineRequest
#ifndef A2T_TypesProtection_SDiagRoutineRequest
#define A2T_TypesProtection_SDiagRoutineRequest
typedef struct _SDiagRoutineRequest_tag {
    uint16 routineId;
    ERoutineType routineType;
    uint16 dataLen;
    data_u8_256 data;
} SDiagRoutineRequest;
#define tSDiagRoutineRequest SDiagRoutineRequest
#endif

// Enumeration type EIOCtrlOptType
#ifndef A2T_TypesProtection_EIOCtrlOptType
#define A2T_TypesProtection_EIOCtrlOptType
typedef enum {
    EIOCtrlOptType_returnControlToECU,
    EIOCtrlOptType_resetToDefault,
    EIOCtrlOptType_freezeCurrentState,
    EIOCtrlOptType_shortTermAdjustment,
    EIOCtrlOptType_Last
} EIOCtrlOptType;
#define eEIOCtrlOptType_returnControlToECU EIOCtrlOptType_returnControlToECU
#define eEIOCtrlOptType_resetToDefault EIOCtrlOptType_resetToDefault
#define eEIOCtrlOptType_freezeCurrentState EIOCtrlOptType_freezeCurrentState
#define eEIOCtrlOptType_shortTermAdjustment EIOCtrlOptType_shortTermAdjustment
#define eEIOCtrlOptType_Last EIOCtrlOptType_Last
#define tEIOCtrlOptType EIOCtrlOptType
#endif

// Structure type SDiagIOCtrlRequest
#ifndef A2T_TypesProtection_SDiagIOCtrlRequest
#define A2T_TypesProtection_SDiagIOCtrlRequest
typedef struct _SDiagIOCtrlRequest_tag {
    uint16 did;
    EIOCtrlOptType optionCtrl;
    uint16 dataLen;
    data_u8_256 data;
} SDiagIOCtrlRequest;
#define tSDiagIOCtrlRequest SDiagIOCtrlRequest
#endif

// Structure type SDiagResponse
#ifndef A2T_TypesProtection_SDiagResponse
#define A2T_TypesProtection_SDiagResponse
typedef struct _SDiagResponse_tag {
    uint8 responseCode;
    uint16 dataLen;
    data_u8_256 data;
} SDiagResponse;
#define tSDiagResponse SDiagResponse
#endif

// Structure type SConfigRecordExt
#ifndef A2T_TypesProtection_SConfigRecordExt
#define A2T_TypesProtection_SConfigRecordExt
typedef struct _SConfigRecordExt_tag {
    SKeyVal2 data_50;
} SConfigRecordExt;
#define tSConfigRecordExt SConfigRecordExt
#endif

// Structure type SConfigRecord
#ifndef A2T_TypesProtection_SConfigRecord
#define A2T_TypesProtection_SConfigRecord
typedef struct _SConfigRecord_tag {
    SKeyVal2 data;
} SConfigRecord;
#define tSConfigRecord SConfigRecord
#endif

// Enumeration type EPhoneStatus
#ifndef A2T_TypesProtection_EPhoneStatus
#define A2T_TypesProtection_EPhoneStatus
typedef enum {
    EPhoneStatus_Inactive,
    EPhoneStatus_Normal,
    EPhoneStatus_CallWaiting,
    EPhoneStatus_Hold,
    EPhoneStatus_Conference,
    EPhoneStatus_Privacy,
    EPhoneStatus_Last
} EPhoneStatus;
#define eEPhoneStatus_Inactive EPhoneStatus_Inactive
#define eEPhoneStatus_Normal EPhoneStatus_Normal
#define eEPhoneStatus_CallWaiting EPhoneStatus_CallWaiting
#define eEPhoneStatus_Hold EPhoneStatus_Hold
#define eEPhoneStatus_Conference EPhoneStatus_Conference
#define eEPhoneStatus_Privacy EPhoneStatus_Privacy
#define eEPhoneStatus_Last EPhoneStatus_Last
#define tEPhoneStatus EPhoneStatus
#endif

// Typedef type data_u8_36
#ifndef A2T_TypesProtection_data_u8_36
#define A2T_TypesProtection_data_u8_36
typedef uint8 data_u8_36[36];
#define tdata_u8_36 data_u8_36
#endif

// Enumeration type EStringEncoding
#ifndef A2T_TypesProtection_EStringEncoding
#define A2T_TypesProtection_EStringEncoding
typedef enum {
    EStringEncoding_Latin1,
    EStringEncoding_UTF8,
    EStringEncoding_UTF16,
    EStringEncoding_Last
} EStringEncoding;
#define eEStringEncoding_Latin1 EStringEncoding_Latin1
#define eEStringEncoding_UTF8 EStringEncoding_UTF8
#define eEStringEncoding_UTF16 EStringEncoding_UTF16
#define eEStringEncoding_Last EStringEncoding_Last
#define tEStringEncoding EStringEncoding
#endif

// Typedef type data_u8_25
#ifndef A2T_TypesProtection_data_u8_25
#define A2T_TypesProtection_data_u8_25
typedef uint8 data_u8_25[25];
#define tdata_u8_25 data_u8_25
#endif

// Enumeration type EPhoneCmd
#ifndef A2T_TypesProtection_EPhoneCmd
#define A2T_TypesProtection_EPhoneCmd
typedef enum {
    EPhoneCmd_None,
    EPhoneCmd_Accept,
    EPhoneCmd_Reject,
    EPhoneCmd_End,
    EPhoneCmd_SwapCalls,
    EPhoneCmd_ConferenceCalls,
    EPhoneCmd_Privacy,
    EPhoneCmd_Mute,
    EPhoneCmd_NoResponse,
    EPhoneCmd_EndActiveCall,
    EPhoneCmd_EndConferenceCall,
    EPhoneCmd_MuteCall,
    EPhoneCmd_HoldCall,
    EPhoneCmd_JoinCalls,
    EPhoneCmd_Unmute,
    EPhoneCmd_Unhold,
    EPhoneCmd_Last
} EPhoneCmd;
#define eEPhoneCmd_None EPhoneCmd_None
#define eEPhoneCmd_Accept EPhoneCmd_Accept
#define eEPhoneCmd_Reject EPhoneCmd_Reject
#define eEPhoneCmd_End EPhoneCmd_End
#define eEPhoneCmd_SwapCalls EPhoneCmd_SwapCalls
#define eEPhoneCmd_ConferenceCalls EPhoneCmd_ConferenceCalls
#define eEPhoneCmd_Privacy EPhoneCmd_Privacy
#define eEPhoneCmd_Mute EPhoneCmd_Mute
#define eEPhoneCmd_NoResponse EPhoneCmd_NoResponse
#define eEPhoneCmd_EndActiveCall EPhoneCmd_EndActiveCall
#define eEPhoneCmd_EndConferenceCall EPhoneCmd_EndConferenceCall
#define eEPhoneCmd_MuteCall EPhoneCmd_MuteCall
#define eEPhoneCmd_HoldCall EPhoneCmd_HoldCall
#define eEPhoneCmd_JoinCalls EPhoneCmd_JoinCalls
#define eEPhoneCmd_Unmute EPhoneCmd_Unmute
#define eEPhoneCmd_Unhold EPhoneCmd_Unhold
#define eEPhoneCmd_Last EPhoneCmd_Last
#define tEPhoneCmd EPhoneCmd
#endif

// Structure type SPhoneData
#ifndef A2T_TypesProtection_SPhoneData
#define A2T_TypesProtection_SPhoneData
typedef struct _SPhoneData_tag {
    data_u8_36 callerName;
    EStringEncoding callerNameEncodingType;
    data_u8_25 callerNumber;
    uint8 id;
    uint8 callerPhoneType;
} SPhoneData;
#define tSPhoneData SPhoneData
#endif

// Structure type SPhoneCmd
#ifndef A2T_TypesProtection_SPhoneCmd
#define A2T_TypesProtection_SPhoneCmd
typedef struct _SPhoneCmd_tag {
    EPhoneCmd callCmd;
} SPhoneCmd;
#define tSPhoneCmd SPhoneCmd
#endif

// Enumeration type EIgnitionStatus
#ifndef A2T_TypesProtection_EIgnitionStatus
#define A2T_TypesProtection_EIgnitionStatus
typedef enum {
    EIgnitionStatus_Off,
    EIgnitionStatus_Acc,
    EIgnitionStatus_Start,
    EIgnitionStatus_Run,
    EIgnitionStatus_Last
} EIgnitionStatus;
#define eEIgnitionStatus_Off EIgnitionStatus_Off
#define eEIgnitionStatus_Acc EIgnitionStatus_Acc
#define eEIgnitionStatus_Start EIgnitionStatus_Start
#define eEIgnitionStatus_Run EIgnitionStatus_Run
#define eEIgnitionStatus_Last EIgnitionStatus_Last
#define tEIgnitionStatus EIgnitionStatus
#endif

// Structure type SIgnState
#ifndef A2T_TypesProtection_SIgnState
#define A2T_TypesProtection_SIgnState
typedef struct _SIgnState_tag {
    EIgnitionStatus state;
} SIgnState;
#define tSIgnState SIgnState
#endif

// Structure type SHMIStatus
#ifndef A2T_TypesProtection_SHMIStatus
#define A2T_TypesProtection_SHMIStatus
typedef struct _SHMIStatus_tag {
    uint8 status;
} SHMIStatus;
#define tSHMIStatus SHMIStatus
#endif

// Enumeration type EDisplayPower
#ifndef A2T_TypesProtection_EDisplayPower
#define A2T_TypesProtection_EDisplayPower
typedef enum {
    EDisplayPower_Off,
    EDisplayPower_On,
    EDisplayPower_Last
} EDisplayPower;
#define eEDisplayPower_Off EDisplayPower_Off
#define eEDisplayPower_On EDisplayPower_On
#define eEDisplayPower_Last EDisplayPower_Last
#define tEDisplayPower EDisplayPower
#endif

// Structure type SDisplaySetPower
#ifndef A2T_TypesProtection_SDisplaySetPower
#define A2T_TypesProtection_SDisplaySetPower
typedef struct _SDisplaySetPower_tag {
    uint32 displayId;
    EDisplayPower state;
} SDisplaySetPower;
#define tSDisplaySetPower SDisplaySetPower
#endif

// Enumeration type EDisplayHMIStatus
#ifndef A2T_TypesProtection_EDisplayHMIStatus
#define A2T_TypesProtection_EDisplayHMIStatus
typedef enum {
    EDisplayHMIStatus_Ok,
    EDisplayHMIStatus_Off,
    EDisplayHMIStatus_Missing,
    EDisplayHMIStatus_Dashes,
    EDisplayHMIStatus_Error,
    EDisplayHMIStatus_Last
} EDisplayHMIStatus;
#define eEDisplayHMIStatus_Ok EDisplayHMIStatus_Ok
#define eEDisplayHMIStatus_Off EDisplayHMIStatus_Off
#define eEDisplayHMIStatus_Missing EDisplayHMIStatus_Missing
#define eEDisplayHMIStatus_Dashes EDisplayHMIStatus_Dashes
#define eEDisplayHMIStatus_Error EDisplayHMIStatus_Error
#define eEDisplayHMIStatus_Last EDisplayHMIStatus_Last
#define tEDisplayHMIStatus EDisplayHMIStatus
#endif

// Structure type SDisplayCurrentState
#ifndef A2T_TypesProtection_SDisplayCurrentState
#define A2T_TypesProtection_SDisplayCurrentState
typedef struct _SDisplayCurrentState_tag {
    uint32 displayId;
    EDisplayStatus state;
} SDisplayCurrentState;
#define tSDisplayCurrentState SDisplayCurrentState
#endif

// Structure type SWelcomeFarewallData
#ifndef A2T_TypesProtection_SWelcomeFarewallData
#define A2T_TypesProtection_SWelcomeFarewallData
typedef struct _SWelcomeFarewallData_tag {
    uint8 SUSDState;
    uint8 WelcomeScreenState;
    uint8 FarewellScreenState;
} SWelcomeFarewallData;
#define tSWelcomeFarewallData SWelcomeFarewallData
#endif

// Structure type SWelcomeResponse
#ifndef A2T_TypesProtection_SWelcomeResponse
#define A2T_TypesProtection_SWelcomeResponse
typedef struct _SWelcomeResponse_tag {
    uint8 status;
} SWelcomeResponse;
#define tSWelcomeResponse SWelcomeResponse
#endif

// Structure type SControlPopup
#ifndef A2T_TypesProtection_SControlPopup
#define A2T_TypesProtection_SControlPopup
typedef struct _SControlPopup_tag {
    uint8 type;
    uint8 level;
    uint8 status;
} SControlPopup;
#define tSControlPopup SControlPopup
#endif

// Typedef type data_u8_50
#ifndef A2T_TypesProtection_data_u8_50
#define A2T_TypesProtection_data_u8_50
typedef uint8 data_u8_50[50];
#define tdata_u8_50 data_u8_50
#endif

// Structure type SETMData
#ifndef A2T_TypesProtection_SETMData
#define A2T_TypesProtection_SETMData
typedef struct _SETMData_tag {
    uint8 id;
    data_u8_50 data;
} SETMData;
#define tSETMData SETMData
#endif

// Structure type SETMStatus
#ifndef A2T_TypesProtection_SETMStatus
#define A2T_TypesProtection_SETMStatus
typedef struct _SETMStatus_tag {
    data_u8_5 data;
} SETMStatus;
#define tSETMStatus SETMStatus
#endif

// Enumeration type EButtonId
#ifndef A2T_TypesProtection_EButtonId
#define A2T_TypesProtection_EButtonId
typedef enum {
    EButtonId_None,
    EButtonId_Ok,
    EButtonId_Up,
    EButtonId_Down,
    EButtonId_Back,
    EButtonId_Menu,
    EButtonId_Phone,
    EButtonId_Hud,
    EButtonId_Last
} EButtonId;
#define eEButtonId_None EButtonId_None
#define eEButtonId_Ok EButtonId_Ok
#define eEButtonId_Up EButtonId_Up
#define eEButtonId_Down EButtonId_Down
#define eEButtonId_Back EButtonId_Back
#define eEButtonId_Menu EButtonId_Menu
#define eEButtonId_Phone EButtonId_Phone
#define eEButtonId_Hud EButtonId_Hud
#define eEButtonId_Last EButtonId_Last
#define tEButtonId EButtonId
#endif

// Enumeration type EButtonState
#ifndef A2T_TypesProtection_EButtonState
#define A2T_TypesProtection_EButtonState
typedef enum {
    EButtonState_Release,
    EButtonState_Pressed,
    EButtonState_Hold,
    EButtonState_Last
} EButtonState;
#define eEButtonState_Release EButtonState_Release
#define eEButtonState_Pressed EButtonState_Pressed
#define eEButtonState_Hold EButtonState_Hold
#define eEButtonState_Last EButtonState_Last
#define tEButtonState EButtonState
#endif

// Structure type SSWC
#ifndef A2T_TypesProtection_SSWC
#define A2T_TypesProtection_SSWC
typedef struct _SSWC_tag {
    EButtonId buttonId;
    EButtonState buttonStatus;
    uint8 holdTime;
} SSWC;
#define tSSWC SSWC
#endif

// Structure type SSDM
#ifndef A2T_TypesProtection_SSDM
#define A2T_TypesProtection_SSDM
typedef struct _SSDM_tag {
    SSdmArray data;
} SSDM;
#define tSSDM SSDM
#endif

// Structure type SSSTM
#ifndef A2T_TypesProtection_SSSTM
#define A2T_TypesProtection_SSSTM
typedef struct _SSSTM_tag {
    SSdmArray data;
} SSSTM;
#define tSSSTM SSSTM
#endif

// Structure type SSSM
#ifndef A2T_TypesProtection_SSSM
#define A2T_TypesProtection_SSSM
typedef struct _SSSM_tag {
    SSdmArray data;
} SSSM;
#define tSSSM SSSM
#endif

// Structure type SEngineAirFilterState
#ifndef A2T_TypesProtection_SEngineAirFilterState
#define A2T_TypesProtection_SEngineAirFilterState
typedef struct _SEngineAirFilterState_tag {
    uint8 engineAirFilterLife;
    uint8 engineAirFilterMinder;
} SEngineAirFilterState;
#define tSEngineAirFilterState SEngineAirFilterState
#endif

// Structure type SDieselPRTCFilterState
#ifndef A2T_TypesProtection_SDieselPRTCFilterState
#define A2T_TypesProtection_SDieselPRTCFilterState
typedef struct _SDieselPRTCFilterState_tag {
    uint8 active;
    uint8 PFS;
} SDieselPRTCFilterState;
#define tSDieselPRTCFilterState SDieselPRTCFilterState
#endif

// Structure type SEVCoachState
#ifndef A2T_TypesProtection_SEVCoachState
#define A2T_TypesProtection_SEVCoachState
typedef struct _SEVCoachState_tag {
    uint8 activeDispayMask;
    uint16 reqPowerPercent;
    uint16 evModeThesholdPowerPercent;
    uint16 regenModeThesholdPowerPercent;
} SEVCoachState;
#define tSEVCoachState SEVCoachState
#endif

// Structure type SDieselExhaustState
#ifndef A2T_TypesProtection_SDieselExhaustState
#define A2T_TypesProtection_SDieselExhaustState
typedef struct _SDieselExhaustState_tag {
    uint8 defActive;
    uint16 defRange;
    uint8 defMask;
    uint8 defSpeedLimit;
} SDieselExhaustState;
#define tSDieselExhaustState SDieselExhaustState
#endif

// Structure type SDieselAdBlueState
#ifndef A2T_TypesProtection_SDieselAdBlueState
#define A2T_TypesProtection_SDieselAdBlueState
typedef struct _SDieselAdBlueState_tag {
    uint8 text1;
    uint8 text2;
    uint16 value1;
    uint16 value2;
    uint16 value3;
} SDieselAdBlueState;
#define tSDieselAdBlueState SDieselAdBlueState
#endif

// Structure type SEngineInfo
#ifndef A2T_TypesProtection_SEngineInfo
#define A2T_TypesProtection_SEngineInfo
typedef struct _SEngineInfo_tag {
    uint16 hours;
    uint16 idleHours;
    uint8 value;
} SEngineInfo;
#define tSEngineInfo SEngineInfo
#endif

// Structure type SPowerDisState
#ifndef A2T_TypesProtection_SPowerDisState
#define A2T_TypesProtection_SPowerDisState
typedef struct _SPowerDisState_tag {
    uint8 frontPercentFill;
    uint8 backPercentFill;
    uint8 displayAnimation;
} SPowerDisState;
#define tSPowerDisState SPowerDisState
#endif

// Structure type STrailerTPMSState
#ifndef A2T_TypesProtection_STrailerTPMSState
#define A2T_TypesProtection_STrailerTPMSState
typedef struct _STrailerTPMSState_tag {
    uint8 status;
    uint8 thresholdStatus;
    uint8 tireCntStatus;
    uint8 tirePressureNumColor;
    uint8 tireTemperatureNumColor;
    uint8 warningStatus;
    uint8 tireTempPressColor;
} STrailerTPMSState;
#define tSTrailerTPMSState STrailerTPMSState
#endif

// Typedef type data_u8_6
#ifndef A2T_TypesProtection_data_u8_6
#define A2T_TypesProtection_data_u8_6
typedef uint8 data_u8_6[6];
#define tdata_u8_6 data_u8_6
#endif

// Structure type STrailerInfo
#ifndef A2T_TypesProtection_STrailerInfo
#define A2T_TypesProtection_STrailerInfo
typedef struct _STrailerInfo_tag {
    uint8 status;
    uint8 backupAssist;
    uint8 reverseGuidance;
    uint8 blindSpot;
    data_u8_8 accumulatedDistanceStr;
    data_u8_6 fuleEconomyStr;
    data_u8_32 trailerName;
} STrailerInfo;
#define tSTrailerInfo STrailerInfo
#endif

// Structure type SSPRStatus
#ifndef A2T_TypesProtection_SSPRStatus
#define A2T_TypesProtection_SSPRStatus
typedef struct _SSPRStatus_tag {
    uint8 steeringWheelAngle;
    uint8 pitchAngle;
    uint8 rollAngle;
} SSPRStatus;
#define tSSPRStatus SSPRStatus
#endif

// Structure type STrailerLighting
#ifndef A2T_TypesProtection_STrailerLighting
#define A2T_TypesProtection_STrailerLighting
typedef struct _STrailerLighting_tag {
    uint16 mask;
} STrailerLighting;
#define tSTrailerLighting STrailerLighting
#endif

// Structure type SAirFuelRatioState
#ifndef A2T_TypesProtection_SAirFuelRatioState
#define A2T_TypesProtection_SAirFuelRatioState
typedef struct _SAirFuelRatioState_tag {
    uint16 value;
} SAirFuelRatioState;
#define tSAirFuelRatioState SAirFuelRatioState
#endif

// Structure type SAutoStartStopState
#ifndef A2T_TypesProtection_SAutoStartStopState
#define A2T_TypesProtection_SAutoStartStopState
typedef struct _SAutoStartStopState_tag {
    uint8 activeStartStopDisplay;
} SAutoStartStopState;
#define tSAutoStartStopState SAutoStartStopState
#endif

// Structure type STrafficSignRecognition
#ifndef A2T_TypesProtection_STrafficSignRecognition
#define A2T_TypesProtection_STrafficSignRecognition
typedef struct _STrafficSignRecognition_tag {
    uint8 id;
    uint8 speedLimitValue;
    uint8 type;
    uint8 annex;
    uint8 region;
    uint8 color;
    data_u8_2 dynData;
} STrafficSignRecognition;
#define tSTrafficSignRecognition STrafficSignRecognition
#endif

// Typedef type data_u8_2
#ifndef A2T_TypesProtection_data_u8_2
#define A2T_TypesProtection_data_u8_2
typedef uint8 data_u8_2[2];
#define tdata_u8_2 data_u8_2
#endif

// Typedef type data_u8_9
#ifndef A2T_TypesProtection_data_u8_9
#define A2T_TypesProtection_data_u8_9
typedef uint8 data_u8_9[9];
#define tdata_u8_9 data_u8_9
#endif

// Structure type SLaneKeepAssist
#ifndef A2T_TypesProtection_SLaneKeepAssist
#define A2T_TypesProtection_SLaneKeepAssist
typedef struct _SLaneKeepAssist_tag {
    uint8 assistStatus;
    uint8 RTTStatus;
    uint8 markerStatus;
} SLaneKeepAssist;
#define tSLaneKeepAssist SLaneKeepAssist
#endif

// Structure type STrafficJamAssist
#ifndef A2T_TypesProtection_STrafficJamAssist
#define A2T_TypesProtection_STrafficJamAssist
typedef struct _STrafficJamAssist_tag {
    uint8 tjaStatus;
    uint8 DAStatus;
    uint8 laneBias;
} STrafficJamAssist;
#define tSTrafficJamAssist STrafficJamAssist
#endif

// Structure type SEcoAdvice
#ifndef A2T_TypesProtection_SEcoAdvice
#define A2T_TypesProtection_SEcoAdvice
typedef struct _SEcoAdvice_tag {
    uint8 reasonIcon;
    uint8 adviceIcon;
    uint8 adviceIconColor;
    uint8 speedLimit;
} SEcoAdvice;
#define tSEcoAdvice SEcoAdvice
#endif

// Structure type SDASGenData
#ifndef A2T_TypesProtection_SDASGenData
#define A2T_TypesProtection_SDASGenData
typedef struct _SDASGenData_tag {
    uint8 id;
    uint8 RTTStatus;
    uint8 dynData;
} SDASGenData;
#define tSDASGenData SDASGenData
#endif

// Structure type SDriverAssistData
#ifndef A2T_TypesProtection_SDriverAssistData
#define A2T_TypesProtection_SDriverAssistData
typedef struct _SDriverAssistData_tag {
    uint8 id;
    uint8 mode;
    data_u8_9 dynData;
} SDriverAssistData;
#define tSDriverAssistData SDriverAssistData
#endif

// Structure type SKeyVal2
#ifndef A2T_TypesProtection_SKeyVal2
#define A2T_TypesProtection_SKeyVal2
typedef struct _SKeyVal2_tag {
    uint8 key;
    data_u8_2 value;
} SKeyVal2;
#define tSKeyVal2 SKeyVal2
#endif

// Enumeration type EOatStatus
#ifndef A2T_TypesProtection_EOatStatus
#define A2T_TypesProtection_EOatStatus
typedef enum {
    EOatStatus_Ok,
    EOatStatus_Off,
    EOatStatus_DispDashes,
    EOatStatus_Last
} EOatStatus;
#define eEOatStatus_Ok EOatStatus_Ok
#define eEOatStatus_Off EOatStatus_Off
#define eEOatStatus_DispDashes EOatStatus_DispDashes
#define eEOatStatus_Last EOatStatus_Last
#define tEOatStatus EOatStatus
#endif

// Structure type SOAT
#ifndef A2T_TypesProtection_SOAT
#define A2T_TypesProtection_SOAT
typedef struct _SOAT_tag {
    uint16 value;
    EGaugeUnit unit;
    EOatStatus status;
} SOAT;
#define tSOAT SOAT
#endif

// Structure type SGearAnimStatus
#ifndef A2T_TypesProtection_SGearAnimStatus
#define A2T_TypesProtection_SGearAnimStatus
typedef struct _SGearAnimStatus_tag {
    uint8 status;
} SGearAnimStatus;
#define tSGearAnimStatus SGearAnimStatus
#endif

// Structure type SEcoCoachTripState
#ifndef A2T_TypesProtection_SEcoCoachTripState
#define A2T_TypesProtection_SEcoCoachTripState
typedef struct _SEcoCoachTripState_tag {
    uint8 accelScore;
    uint8 decelScore;
    uint8 cruiseScore;
    uint8 shiftScore;
    uint8 ComplianceScore;
    uint8 EcoScore;
    uint8 transmisionType;
    uint16 currentTrip;
    uint8 currentTripUnits;
    uint16 lastTrip;
    uint8 lastTripUnits;
    uint8 msgTextId;
    uint8 validMask;
} SEcoCoachTripState;
#define tSEcoCoachTripState SEcoCoachTripState
#endif

// Structure type STireTempState
#ifndef A2T_TypesProtection_STireTempState
#define A2T_TypesProtection_STireTempState
typedef struct _STireTempState_tag {
    uint8 tireTempUnit;
    uint8 tireTempStat;
    uint16 lfTireTemp;
    uint16 rfTireTemp;
    uint16 lrTireTemp;
    uint16 rrTireTemp;
} STireTempState;
#define tSTireTempState STireTempState
#endif

// Structure type SOffRoadState
#ifndef A2T_TypesProtection_SOffRoadState
#define A2T_TypesProtection_SOffRoadState
typedef struct _SOffRoadState_tag {
    uint8 steeringWheelAngle;
    uint8 pitchAngle;
    uint8 rollAngle;
} SOffRoadState;
#define tSOffRoadState SOffRoadState
#endif

// Structure type SIODGaugeData
#ifndef A2T_TypesProtection_SIODGaugeData
#define A2T_TypesProtection_SIODGaugeData
typedef struct _SIODGaugeData_tag {
    uint8 id;
    uint8 status;
    uint8 unit;
    uint16 value;
} SIODGaugeData;
#define tSIODGaugeData SIODGaugeData
#endif

// Structure type SDriverAssistDisplay
#ifndef A2T_TypesProtection_SDriverAssistDisplay
#define A2T_TypesProtection_SDriverAssistDisplay
typedef struct _SDriverAssistDisplay_tag {
    uint8 display;
    uint8 counter;
} SDriverAssistDisplay;
#define tSDriverAssistDisplay SDriverAssistDisplay
#endif

// Enumeration type EMediaText
#ifndef A2T_TypesProtection_EMediaText
#define A2T_TypesProtection_EMediaText
typedef enum {
    EMediaText_None,
    EMediaText_CDFileName,
    EMediaText_CDTrackName,
    EMediaText_DABBlockNumber,
    EMediaText_HDRadioSongTitle,
    EMediaText_HDRadioArtistName,
    EMediaText_SyncSongTitle,
    EMediaText_SyncArtist,
    EMediaText_SyncTitleAdj,
    EMediaText_SyncArtistAdj,
    EMediaText_RadioShortStation,
    EMediaText_RadioProgramName,
    EMediaText_RadioLongStation,
    EMediaText_SDARSArtistName,
    EMediaText_SyncSourceInfo,
    EMediaText_Last
} EMediaText;
#define eEMediaText_None EMediaText_None
#define eEMediaText_CDFileName EMediaText_CDFileName
#define eEMediaText_CDTrackName EMediaText_CDTrackName
#define eEMediaText_DABBlockNumber EMediaText_DABBlockNumber
#define eEMediaText_HDRadioSongTitle EMediaText_HDRadioSongTitle
#define eEMediaText_HDRadioArtistName EMediaText_HDRadioArtistName
#define eEMediaText_SyncSongTitle EMediaText_SyncSongTitle
#define eEMediaText_SyncArtist EMediaText_SyncArtist
#define eEMediaText_SyncTitleAdj EMediaText_SyncTitleAdj
#define eEMediaText_SyncArtistAdj EMediaText_SyncArtistAdj
#define eEMediaText_RadioShortStation EMediaText_RadioShortStation
#define eEMediaText_RadioProgramName EMediaText_RadioProgramName
#define eEMediaText_RadioLongStation EMediaText_RadioLongStation
#define eEMediaText_SDARSArtistName EMediaText_SDARSArtistName
#define eEMediaText_SyncSourceInfo EMediaText_SyncSourceInfo
#define eEMediaText_Last EMediaText_Last
#define tEMediaText EMediaText
#endif

// Typedef type data_u8_42
#ifndef A2T_TypesProtection_data_u8_42
#define A2T_TypesProtection_data_u8_42
typedef uint8 data_u8_42[42];
#define tdata_u8_42 data_u8_42
#endif

// Typedef type data_u8_40
#ifndef A2T_TypesProtection_data_u8_40
#define A2T_TypesProtection_data_u8_40
typedef uint8 data_u8_40[40];
#define tdata_u8_40 data_u8_40
#endif

// Typedef type data_u8_130
#ifndef A2T_TypesProtection_data_u8_130
#define A2T_TypesProtection_data_u8_130
typedef uint8 data_u8_130[130];
#define tdata_u8_130 data_u8_130
#endif

// Structure type SMediaText
#ifndef A2T_TypesProtection_SMediaText
#define A2T_TypesProtection_SMediaText
typedef struct _SMediaText_tag {
    EMediaText id;
    data_u8_40 text;
    EStringEncoding type;
} SMediaText;
#define tSMediaText SMediaText
#endif

// Structure type SMediaTextExt
#ifndef A2T_TypesProtection_SMediaTextExt
#define A2T_TypesProtection_SMediaTextExt
typedef struct _SMediaTextExt_tag {
    EMediaText id;
    data_u8_130 text;
    EStringEncoding type;
} SMediaTextExt;
#define tSMediaTextExt SMediaTextExt
#endif

// Structure type SSDARSData
#ifndef A2T_TypesProtection_SSDARSData
#define A2T_TypesProtection_SSDARSData
typedef struct _SSDARSData_tag {
    uint16 channelNumber;
    data_u8_130 title;
    EStringEncoding titleType;
    uint8 valid;
} SSDARSData;
#define tSSDARSData SSDARSData
#endif

// Structure type SRadioData
#ifndef A2T_TypesProtection_SRadioData
#define A2T_TypesProtection_SRadioData
typedef struct _SRadioData_tag {
    uint16 AMFreq;
    uint16 FMFreq;
    uint8 valid;
    uint16 FMFreqRDS;
} SRadioData;
#define tSRadioData SRadioData
#endif

// Structure type SExtETMStatus
#ifndef A2T_TypesProtection_SExtETMStatus
#define A2T_TypesProtection_SExtETMStatus
typedef struct _SExtETMStatus_tag {
    uint8 value;
} SExtETMStatus;
#define tSExtETMStatus SExtETMStatus
#endif

// Structure type SIODSettings
#ifndef A2T_TypesProtection_SIODSettings
#define A2T_TypesProtection_SIODSettings
typedef struct _SIODSettings_tag {
    data_u8_2 dynData;
} SIODSettings;
#define tSIODSettings SIODSettings
#endif

// Structure type SMaintStatus
#ifndef A2T_TypesProtection_SMaintStatus
#define A2T_TypesProtection_SMaintStatus
typedef struct _SMaintStatus_tag {
    uint8 status;
    uint8 value;
    uint8 state;
} SMaintStatus;
#define tSMaintStatus SMaintStatus
#endif

// Structure type SLHIStatus
#ifndef A2T_TypesProtection_SLHIStatus
#define A2T_TypesProtection_SLHIStatus
typedef struct _SLHIStatus_tag {
    uint8 active;
} SLHIStatus;
#define tSLHIStatus SLHIStatus
#endif

// Structure type SNaviData
#ifndef A2T_TypesProtection_SNaviData
#define A2T_TypesProtection_SNaviData
typedef struct _SNaviData_tag {
    data_u8_42 streetName;
    EStringEncoding streetNameType;
    uint8 turnIconId;
    uint8 speedLimitValue;
    uint8 navBarGraphSteps;
    uint16 naviDistanceWhole;
    uint16 naviDistanceTenth;
    uint8 naviDistanceUnit;
    ENavStatus navBarGraphStatus;
    ENavStatus naviSpeedLimitStatus;
    ENaviSpeedSign naviSpeedSignType;
    ENavStatus naviOffRoute;
    ENavStatus naviRoute;
    ENaviUnits naviDistancetoDestUnits;
    ECompassValue naviCompass;
    uint16 naviDistancetoDest;
    uint8 naviTimetoDestDays;
    uint8 naviTimetoDestHours;
    uint8 naviTimetoDestMinutes;
} SNaviData;
#define tSNaviData SNaviData
#endif

// Structure type SNaviCmd
#ifndef A2T_TypesProtection_SNaviCmd
#define A2T_TypesProtection_SNaviCmd
typedef struct _SNaviCmd_tag {
    uint8 naviCmd;
} SNaviCmd;
#define tSNaviCmd SNaviCmd
#endif

// Structure type SDistanceToEmpty
#ifndef A2T_TypesProtection_SDistanceToEmpty
#define A2T_TypesProtection_SDistanceToEmpty
typedef struct _SDistanceToEmpty_tag {
    EFuelEconomy feType;
    uint16 value;
    uint8 unit;
    uint8 valid;
    data_u8_5 dynData;
} SDistanceToEmpty;
#define tSDistanceToEmpty SDistanceToEmpty
#endif

// Enumeration type ETripCmd
#ifndef A2T_TypesProtection_ETripCmd
#define A2T_TypesProtection_ETripCmd
typedef enum {
    ETripCmd_AFE_A,
    ETripCmd_AFE_B,
    ETripCmd_TCAFE_B,
    ETripCmd_TCT_A,
    ETripCmd_TCT_B,
    ETripCmd_TCO_A,
    ETripCmd_TCO_B,
    ETripCmd_TCAFE_A,
    ETripCmd_LS,
    ETripCmd_TCAS_A,
    ETripCmd_TCAS_B,
    ETripCmd_FEH,
    ETripCmd_Last
} ETripCmd;
#define eETripCmd_AFE_A ETripCmd_AFE_A
#define eETripCmd_AFE_B ETripCmd_AFE_B
#define eETripCmd_TCAFE_B ETripCmd_TCAFE_B
#define eETripCmd_TCT_A ETripCmd_TCT_A
#define eETripCmd_TCT_B ETripCmd_TCT_B
#define eETripCmd_TCO_A ETripCmd_TCO_A
#define eETripCmd_TCO_B ETripCmd_TCO_B
#define eETripCmd_TCAFE_A ETripCmd_TCAFE_A
#define eETripCmd_LS ETripCmd_LS
#define eETripCmd_TCAS_A ETripCmd_TCAS_A
#define eETripCmd_TCAS_B ETripCmd_TCAS_B
#define eETripCmd_FEH ETripCmd_FEH
#define eETripCmd_Last ETripCmd_Last
#define tETripCmd ETripCmd
#endif

// Enumeration type EDisplayUnit
#ifndef A2T_TypesProtection_EDisplayUnit
#define A2T_TypesProtection_EDisplayUnit
typedef enum {
    EDisplayUnit_Mph,
    EDisplayUnit_Kmph,
    EDisplayUnit_Centigrade,
    EDisplayUnit_Farenheit,
    EDisplayUnit_Psi,
    EDisplayUnit_Pa,
    EDisplayUnit_Bar,
    EDisplayUnit_Last
} EDisplayUnit;
#define eEDisplayUnit_Mph EDisplayUnit_Mph
#define eEDisplayUnit_Kmph EDisplayUnit_Kmph
#define eEDisplayUnit_Centigrade EDisplayUnit_Centigrade
#define eEDisplayUnit_Farenheit EDisplayUnit_Farenheit
#define eEDisplayUnit_Psi EDisplayUnit_Psi
#define eEDisplayUnit_Pa EDisplayUnit_Pa
#define eEDisplayUnit_Bar EDisplayUnit_Bar
#define eEDisplayUnit_Last EDisplayUnit_Last
#define tEDisplayUnit EDisplayUnit
#endif

// Structure type SDTEHistory
#ifndef A2T_TypesProtection_SDTEHistory
#define A2T_TypesProtection_SDTEHistory
typedef struct _SDTEHistory_tag {
    uint8 dtehistoryused;
} SDTEHistory;
#define tSDTEHistory SDTEHistory
#endif

// Typedef type data_u8_3
#ifndef A2T_TypesProtection_data_u8_3
#define A2T_TypesProtection_data_u8_3
typedef uint8 data_u8_3[3];
#define tdata_u8_3 data_u8_3
#endif

// Structure type SGALCarPlayData
#ifndef A2T_TypesProtection_SGALCarPlayData
#define A2T_TypesProtection_SGALCarPlayData
typedef struct _SGALCarPlayData_tag {
    data_u8_7 dynData;
} SGALCarPlayData;
#define tSGALCarPlayData SGALCarPlayData
#endif

// Structure type SSetupSpeed
#ifndef A2T_TypesProtection_SSetupSpeed
#define A2T_TypesProtection_SSetupSpeed
typedef struct _SSetupSpeed_tag {
    uint8 speedstatus;
} SSetupSpeed;
#define tSSetupSpeed SSetupSpeed
#endif

// Structure type SSpeedLockStatus
#ifndef A2T_TypesProtection_SSpeedLockStatus
#define A2T_TypesProtection_SSpeedLockStatus
typedef struct _SSpeedLockStatus_tag {
    uint8 speedlockstatus;
} SSpeedLockStatus;
#define tSSpeedLockStatus SSpeedLockStatus
#endif

// Structure type SRearBeltMonitor
#ifndef A2T_TypesProtection_SRearBeltMonitor
#define A2T_TypesProtection_SRearBeltMonitor
typedef struct _SRearBeltMonitor_tag {
    uint8 count;
    uint8 seatselection;
    uint8 seatselectionvalue;
} SRearBeltMonitor;
#define tSRearBeltMonitor SRearBeltMonitor
#endif

// Structure type SRangeDisplay
#ifndef A2T_TypesProtection_SRangeDisplay
#define A2T_TypesProtection_SRangeDisplay
typedef struct _SRangeDisplay_tag {
    uint8 mode;
    uint8 unit;
    EDisplayHMIStatus status;
    uint16 value;
} SRangeDisplay;
#define tSRangeDisplay SRangeDisplay
#endif

// Structure type SListCmd
#ifndef A2T_TypesProtection_SListCmd
#define A2T_TypesProtection_SListCmd
typedef struct _SListCmd_tag {
    EListRequest listRequestCmd;
    uint16 focusItemIndex;
    uint16 activeListIndex;
    uint16 parentListIndex;
    uint16 itemInfoNbrItem;
    uint8 prefetchRequestActionCmd;
    EPrefetchReqMenu prefetchRequestMenuTypeCmd;
} SListCmd;
#define tSListCmd SListCmd
#endif

// Structure type SListTimeout
#ifndef A2T_TypesProtection_SListTimeout
#define A2T_TypesProtection_SListTimeout
typedef struct _SListTimeout_tag {
    uint8 timeout;
} SListTimeout;
#define tSListTimeout SListTimeout
#endif

// Enumeration type EDisplayStatus
#ifndef A2T_TypesProtection_EDisplayStatus
#define A2T_TypesProtection_EDisplayStatus
typedef enum {
    EDisplayState_Off,
    EDisplayState_On,
    EDisplayState_Error,
    EDisplayState_Disconnected,
    EDisplayState_Last
} EDisplayStatus;
#define eEDisplayState_Off EDisplayState_Off
#define eEDisplayState_On EDisplayState_On
#define eEDisplayState_Error EDisplayState_Error
#define eEDisplayState_Disconnected EDisplayState_Disconnected
#define eEDisplayState_Last EDisplayState_Last
#define tEDisplayStatus EDisplayStatus
#endif

// Structure type SAWDGaugeData
#ifndef A2T_TypesProtection_SAWDGaugeData
#define A2T_TypesProtection_SAWDGaugeData
typedef struct _SAWDGaugeData_tag {
    uint8 AWDGauge_FrontLeftPixelFill;
    uint8 AWDGauge_FrontRightPixelFill;
    uint8 AWDGauge_RearLeftPixelFill;
    uint8 AWDGauge_RearRightPixelFill;
} SAWDGaugeData;
#define tSAWDGaugeData SAWDGaugeData
#endif

// Structure type SElectricEfficiencyFunction
#ifndef A2T_TypesProtection_SElectricEfficiencyFunction
#define A2T_TypesProtection_SElectricEfficiencyFunction
typedef struct _SElectricEfficiencyFunction_tag {
    uint16 efficiency;
    uint8 efficiencyStatus;
    uint8 range;
    uint8 rangeStatus;
} SElectricEfficiencyFunction;
#define tSElectricEfficiencyFunction SElectricEfficiencyFunction
#endif

// Structure type SControlPopupStatus
#ifndef A2T_TypesProtection_SControlPopupStatus
#define A2T_TypesProtection_SControlPopupStatus
typedef struct _SControlPopupStatus_tag {
    uint8 status;
} SControlPopupStatus;
#define tSControlPopupStatus SControlPopupStatus
#endif

// Structure type SSwUpdateResponse
#ifndef A2T_TypesProtection_SSwUpdateResponse
#define A2T_TypesProtection_SSwUpdateResponse
typedef struct _SSwUpdateResponse_tag {
    uint8 serviceId;
    uint8 status;
    uint32 data;
} SSwUpdateResponse;
#define tSSwUpdateResponse SSwUpdateResponse
#endif

// Structure type SSwUpdateEraseSwPartReq
#ifndef A2T_TypesProtection_SSwUpdateEraseSwPartReq
#define A2T_TypesProtection_SSwUpdateEraseSwPartReq
typedef struct _SSwUpdateEraseSwPartReq_tag {
    uint8 swPartId;
    uint8 serviceId;
} SSwUpdateEraseSwPartReq;
#define tSSwUpdateEraseSwPartReq SSwUpdateEraseSwPartReq
#endif

// Structure type SSwUpdateDownloadSwPartReq
#ifndef A2T_TypesProtection_SSwUpdateDownloadSwPartReq
#define A2T_TypesProtection_SSwUpdateDownloadSwPartReq
typedef struct _SSwUpdateDownloadSwPartReq_tag {
    uint8 swPartId;
    uint32 startAddress;
    uint32 length;
    uint8 serviceId;
} SSwUpdateDownloadSwPartReq;
#define tSSwUpdateDownloadSwPartReq SSwUpdateDownloadSwPartReq
#endif

// Structure type SSwUpdateUploadSwPartReq
#ifndef A2T_TypesProtection_SSwUpdateUploadSwPartReq
#define A2T_TypesProtection_SSwUpdateUploadSwPartReq
typedef struct _SSwUpdateUploadSwPartReq_tag {
    uint8 swPartId;
    uint32 startAddress;
    uint32 bufferId;
    uint32 dataLen;
    uint32 length;
    uint8 serviceId;
} SSwUpdateUploadSwPartReq;
#define tSSwUpdateUploadSwPartReq SSwUpdateUploadSwPartReq
#endif

// Structure type SSwUpdateDataTransferReq
#ifndef A2T_TypesProtection_SSwUpdateDataTransferReq
#define A2T_TypesProtection_SSwUpdateDataTransferReq
typedef struct _SSwUpdateDataTransferReq_tag {
    uint32 bufferId;
    uint32 startAddress;
    uint32 dataLen;
    uint8 serviceId;
} SSwUpdateDataTransferReq;
#define tSSwUpdateDataTransferReq SSwUpdateDataTransferReq
#endif

// Structure type SEcoCoachDisplay
#ifndef A2T_TypesProtection_SEcoCoachDisplay
#define A2T_TypesProtection_SEcoCoachDisplay
typedef struct _SEcoCoachDisplay_tag {
    sint16 value;
    uint8 status;
    uint8 visible;
} SEcoCoachDisplay;
#define tSEcoCoachDisplay SEcoCoachDisplay
#endif

// Structure type SChecksumValue1
#ifndef A2T_TypesProtection_SChecksumValue1
#define A2T_TypesProtection_SChecksumValue1
typedef struct _SChecksumValue1_tag {
    data_u8_30 checksumData1;
} SChecksumValue1;
#define tSChecksumValue1 SChecksumValue1
#endif

// Typedef type data_u32_3
#ifndef A2T_TypesProtection_data_u32_3
#define A2T_TypesProtection_data_u32_3
typedef uint32 data_u32_3[3];
#define tdata_u32_3 data_u32_3
#endif

// Structure type SSdmArray
#ifndef A2T_TypesProtection_SSdmArray
#define A2T_TypesProtection_SSdmArray
typedef struct _SSdmArray_tag {
    uint8 id;
    uint8 mode;
    uint16 mask;
} SSdmArray;
#define tSSdmArray SSdmArray
#endif

// Structure type SSDMExt
#ifndef A2T_TypesProtection_SSDMExt
#define A2T_TypesProtection_SSDMExt
typedef struct _SSDMExt_tag {
    SSdmArray data;
} SSDMExt;
#define tSSDMExt SSDMExt
#endif

// Structure type SRTT_Icon
#ifndef A2T_TypesProtection_SRTT_Icon
#define A2T_TypesProtection_SRTT_Icon
typedef struct _SRTT_Icon_tag {
    data_u8_6 icon;
} SRTT_Icon;
#define tSRTT_Icon SRTT_Icon
#endif

// Typedef type data_u8_1
#ifndef A2T_TypesProtection_data_u8_1
#define A2T_TypesProtection_data_u8_1
typedef uint8 data_u8_1;
#define tdata_u8_1 data_u8_1
#endif

// Structure type SWelcomeScreens
#ifndef A2T_TypesProtection_SWelcomeScreens
#define A2T_TypesProtection_SWelcomeScreens
typedef struct _SWelcomeScreens_tag {
    data_u8_21 DynData;
} SWelcomeScreens;
#define tSWelcomeScreens SWelcomeScreens
#endif

// Structure type SLocalHazardInformation
#ifndef A2T_TypesProtection_SLocalHazardInformation
#define A2T_TypesProtection_SLocalHazardInformation
typedef struct _SLocalHazardInformation_tag {
    uint16 LHIDistance;
    uint8 LHIUnits;
    uint8 LHIDisplayStatus;
} SLocalHazardInformation;
#define tSLocalHazardInformation SLocalHazardInformation
#endif

// Structure type SHighVoltageBatteryDisplay
#ifndef A2T_TypesProtection_SHighVoltageBatteryDisplay
#define A2T_TypesProtection_SHighVoltageBatteryDisplay
typedef struct _SHighVoltageBatteryDisplay_tag {
    uint8 batterySOC;
    uint16 batteryPercMC;
    uint8 electricRangeKm;
    uint8 electricRangeMi;
} SHighVoltageBatteryDisplay;
#define tSHighVoltageBatteryDisplay SHighVoltageBatteryDisplay
#endif

// Structure type SWarningsTPMSData
#ifndef A2T_TypesProtection_SWarningsTPMSData
#define A2T_TypesProtection_SWarningsTPMSData
typedef struct _SWarningsTPMSData_tag {
    data_u8_22 warningsTPMSData;
} SWarningsTPMSData;
#define tSWarningsTPMSData SWarningsTPMSData
#endif

// Typedef type data_u8_22
#ifndef A2T_TypesProtection_data_u8_22
#define A2T_TypesProtection_data_u8_22
typedef uint8 data_u8_22[22];
#define tdata_u8_22 data_u8_22
#endif

// Structure type SIlluminationData
#ifndef A2T_TypesProtection_SIlluminationData
#define A2T_TypesProtection_SIlluminationData
typedef struct _SIlluminationData_tag {
    uint8 data;
} SIlluminationData;
#define tSIlluminationData SIlluminationData
#endif

// Enumeration type ElistItemId
#ifndef A2T_TypesProtection_ElistItemId
#define A2T_TypesProtection_ElistItemId
typedef enum {
    EListItemId_Header,
    EListItemId_Item1,
    EListItemId_Item2,
    EListItemId_Item3,
    EListItemId_Item4,
    EListItemId_Item5,
    EListItemId_Last
} ElistItemId;
#define eEListItemId_Header EListItemId_Header
#define eEListItemId_Item1 EListItemId_Item1
#define eEListItemId_Item2 EListItemId_Item2
#define eEListItemId_Item3 EListItemId_Item3
#define eEListItemId_Item4 EListItemId_Item4
#define eEListItemId_Item5 EListItemId_Item5
#define eEListItemId_Last EListItemId_Last
#define tElistItemId ElistItemId
#endif

// Enumeration type EDataType
#ifndef A2T_TypesProtection_EDataType
#define A2T_TypesProtection_EDataType
typedef enum {
    EDataType_GenericText,
    EDataType_MediaType,
    EDataType_NaviPOI,
    EDataType_PhoneCalledId,
    EDataType_RadioStation,
    EDataType_RadioMixedPresets,
    EDataType_RadioSource,
    EDataType_Last
} EDataType;
#define eEDataType_GenericText EDataType_GenericText
#define eEDataType_MediaType EDataType_MediaType
#define eEDataType_NaviPOI EDataType_NaviPOI
#define eEDataType_PhoneCalledId EDataType_PhoneCalledId
#define eEDataType_RadioStation EDataType_RadioStation
#define eEDataType_RadioMixedPresets EDataType_RadioMixedPresets
#define eEDataType_RadioSource EDataType_RadioSource
#define eEDataType_Last EDataType_Last
#define tEDataType EDataType
#endif

// Enumeration type EListItemObjectType
#ifndef A2T_TypesProtection_EListItemObjectType
#define A2T_TypesProtection_EListItemObjectType
typedef enum {
    EListItemObjectType_ListLabel,
    EListItemObjectType_Entry,
    EListItemObjectType_List,
    EListItemObjectType_Invalid,
    EListItemObjectType_Last
} EListItemObjectType;
#define eEListItemObjectType_ListLabel EListItemObjectType_ListLabel
#define eEListItemObjectType_Entry EListItemObjectType_Entry
#define eEListItemObjectType_List EListItemObjectType_List
#define eEListItemObjectType_Invalid EListItemObjectType_Invalid
#define eEListItemObjectType_Last EListItemObjectType_Last
#define tEListItemObjectType EListItemObjectType
#endif

// Enumeration type EListServer
#ifndef A2T_TypesProtection_EListServer
#define A2T_TypesProtection_EListServer
typedef enum {
    EListServer_None,
    EListServer_NaviInfo,
    EListServer_GenericMedia,
    EListServer_PhoneInfo,
    EListServer_Radio,
    EListServer_ConsideratePrompt,
    EListServer_Last
} EListServer;
#define eEListServer_None EListServer_None
#define eEListServer_NaviInfo EListServer_NaviInfo
#define eEListServer_GenericMedia EListServer_GenericMedia
#define eEListServer_PhoneInfo EListServer_PhoneInfo
#define eEListServer_Radio EListServer_Radio
#define eEListServer_ConsideratePrompt EListServer_ConsideratePrompt
#define eEListServer_Last EListServer_Last
#define tEListServer EListServer
#endif

// Enumeration type ELbpListStatus
#ifndef A2T_TypesProtection_ELbpListStatus
#define A2T_TypesProtection_ELbpListStatus
typedef enum {
    ELbpListStatus_Inactive,
    ELbpListStatus_Valid,
    ELbpListStatus_Updating,
    ELbpListStatus_Reserved,
    ELbpListStatus_Last
} ELbpListStatus;
#define eELbpListStatus_Inactive ELbpListStatus_Inactive
#define eELbpListStatus_Valid ELbpListStatus_Valid
#define eELbpListStatus_Updating ELbpListStatus_Updating
#define eELbpListStatus_Reserved ELbpListStatus_Reserved
#define eELbpListStatus_Last ELbpListStatus_Last
#define tELbpListStatus ELbpListStatus
#endif

// Enumeration type EItemIcon
#ifndef A2T_TypesProtection_EItemIcon
#define A2T_TypesProtection_EItemIcon
typedef enum {
    EItemIcon_None,
    EItemIcon_Home,
    EItemIcon_Mobile,
    EItemIcon_Office,
    EItemIcon_N,
    EItemIcon_NE,
    EItemIcon_E,
    EItemIcon_SE,
    EItemIcon_S,
    EItemIcon_SW,
    EItemIcon_W,
    EItemIcon_NW,
    EItemIcon_AM,
    EItemIcon_CD,
    EItemIcon_SDARS,
    EItemIcon_AudioVideoIn,
    EItemIcon_UserDevUSB,
    EItemIcon_UserDevPhone,
    EItemIcon_UserDevMediaPlayer,
    EItemIcon_UserDevSDCard,
    EItemIcon_UserDevWiFi,
    EItemIcon_UserDevBluetoothAudio,
    EItemIcon_LineIn,
    EItemIcon_FM,
    EItemIcon_DAB,
    EItemIcon_Preset_AM,
    EItemIcon_Preset_FM,
    EItemIcon_Preset_DAB,
    EItemIcon_Preset_SDARS,
    EItemIcon_Incoming,
    EItemIcon_Outgoing,
    EItemIcon_Missed
} EItemIcon;
#define eEItemIcon_None EItemIcon_None
#define eEItemIcon_Home EItemIcon_Home
#define eEItemIcon_Mobile EItemIcon_Mobile
#define eEItemIcon_Office EItemIcon_Office
#define eEItemIcon_N EItemIcon_N
#define eEItemIcon_NE EItemIcon_NE
#define eEItemIcon_E EItemIcon_E
#define eEItemIcon_SE EItemIcon_SE
#define eEItemIcon_S EItemIcon_S
#define eEItemIcon_SW EItemIcon_SW
#define eEItemIcon_W EItemIcon_W
#define eEItemIcon_NW EItemIcon_NW
#define eEItemIcon_AM EItemIcon_AM
#define eEItemIcon_CD EItemIcon_CD
#define eEItemIcon_SDARS EItemIcon_SDARS
#define eEItemIcon_AudioVideoIn EItemIcon_AudioVideoIn
#define eEItemIcon_UserDevUSB EItemIcon_UserDevUSB
#define eEItemIcon_UserDevPhone EItemIcon_UserDevPhone
#define eEItemIcon_UserDevMediaPlayer EItemIcon_UserDevMediaPlayer
#define eEItemIcon_UserDevSDCard EItemIcon_UserDevSDCard
#define eEItemIcon_UserDevWiFi EItemIcon_UserDevWiFi
#define eEItemIcon_UserDevBluetoothAudio EItemIcon_UserDevBluetoothAudio
#define eEItemIcon_LineIn EItemIcon_LineIn
#define eEItemIcon_FM EItemIcon_FM
#define eEItemIcon_DAB EItemIcon_DAB
#define eEItemIcon_Preset_AM EItemIcon_Preset_AM
#define eEItemIcon_Preset_FM EItemIcon_Preset_FM
#define eEItemIcon_Preset_DAB EItemIcon_Preset_DAB
#define eEItemIcon_Preset_SDARS EItemIcon_Preset_SDARS
#define eEItemIcon_Incoming EItemIcon_Incoming
#define eEItemIcon_Outgoing EItemIcon_Outgoing
#define eEItemIcon_Missed EItemIcon_Missed
#define tEItemIcon EItemIcon
#endif

// Enumeration type EListRequest
#ifndef A2T_TypesProtection_EListRequest
#define A2T_TypesProtection_EListRequest
typedef enum {
    EListRequest_GetPhoneList,
    EListRequest_DialPhoneList,
    EListRequest_GetRadioSources,
    EListRequest_ListenRadioSource,
    EListRequest_GetEntertainSources,
    EListRequest_ListenEntertainSource,
    EListRequest_GetNavListEListRequest_GetNavList,
    EListRequest_SelectNavList,
    EListRequest_GetFuelStationsList,
    EListRequest_SelectFuelStationList,
    EListRequest_GetRadioSourcesNextResponse,
    EListRequest_Invalid = 255
} EListRequest;
#define eEListRequest_GetPhoneList EListRequest_GetPhoneList
#define eEListRequest_DialPhoneList EListRequest_DialPhoneList
#define eEListRequest_GetRadioSources EListRequest_GetRadioSources
#define eEListRequest_ListenRadioSource EListRequest_ListenRadioSource
#define eEListRequest_GetEntertainSources EListRequest_GetEntertainSources
#define eEListRequest_ListenEntertainSource EListRequest_ListenEntertainSource
#define eEListRequest_GetNavListEListRequest_GetNavList EListRequest_GetNavListEListRequest_GetNavList
#define eEListRequest_SelectNavList EListRequest_SelectNavList
#define eEListRequest_GetFuelStationsList EListRequest_GetFuelStationsList
#define eEListRequest_SelectFuelStationList EListRequest_SelectFuelStationList
#define eEListRequest_GetRadioSourcesNextResponse EListRequest_GetRadioSourcesNextResponse
#define eEListRequest_Invalid EListRequest_Invalid
#define tEListRequest EListRequest
#endif

// Enumeration type EPrefetchReqMenu
#ifndef A2T_TypesProtection_EPrefetchReqMenu
#define A2T_TypesProtection_EPrefetchReqMenu
typedef enum {
    EPrefetchReqMenu_None,
    EPrefetchReqMenu_Audio,
    EPrefetchReqMenu_Phone,
    EPrefetchReqMenu_Navigation,
    EPrefetchReqMenu_Last
} EPrefetchReqMenu;
#define eEPrefetchReqMenu_None EPrefetchReqMenu_None
#define eEPrefetchReqMenu_Audio EPrefetchReqMenu_Audio
#define eEPrefetchReqMenu_Phone EPrefetchReqMenu_Phone
#define eEPrefetchReqMenu_Navigation EPrefetchReqMenu_Navigation
#define eEPrefetchReqMenu_Last EPrefetchReqMenu_Last
#define tEPrefetchReqMenu EPrefetchReqMenu
#endif

// Enumeration type ENavStatus
#ifndef A2T_TypesProtection_ENavStatus
#define A2T_TypesProtection_ENavStatus
typedef enum {
    ENavStatus_Inactive,
    ENavStatus_Active,
    ENavStatus_Last
} ENavStatus;
#define eENavStatus_Inactive ENavStatus_Inactive
#define eENavStatus_Active ENavStatus_Active
#define eENavStatus_Last ENavStatus_Last
#define tENavStatus ENavStatus
#endif

// Enumeration type ENaviSpeedSign
#ifndef A2T_TypesProtection_ENaviSpeedSign
#define A2T_TypesProtection_ENaviSpeedSign
typedef enum {
    ENaviSpeedSign_NA,
    ENaviSpeedSign_ROW,
    ENaviSpeedSign_Last
} ENaviSpeedSign;
#define eENaviSpeedSign_NA ENaviSpeedSign_NA
#define eENaviSpeedSign_ROW ENaviSpeedSign_ROW
#define eENaviSpeedSign_Last ENaviSpeedSign_Last
#define tENaviSpeedSign ENaviSpeedSign
#endif

// Enumeration type ENaviUnits
#ifndef A2T_TypesProtection_ENaviUnits
#define A2T_TypesProtection_ENaviUnits
typedef enum {
    ENaviUnits_Unknown,
    ENaviUnits_Kilometer,
    ENaviUnits_Meter,
    ENaviUnits_FT,
    ENaviUnits_Miles,
    ENaviUnits_Last
} ENaviUnits;
#define eENaviUnits_Unknown ENaviUnits_Unknown
#define eENaviUnits_Kilometer ENaviUnits_Kilometer
#define eENaviUnits_Meter ENaviUnits_Meter
#define eENaviUnits_FT ENaviUnits_FT
#define eENaviUnits_Miles ENaviUnits_Miles
#define eENaviUnits_Last ENaviUnits_Last
#define tENaviUnits ENaviUnits
#endif

// Enumeration type ECurrentCallID
#ifndef A2T_TypesProtection_ECurrentCallID
#define A2T_TypesProtection_ECurrentCallID
typedef enum {
    ECurrentCallID_Primary,
    ECurrentCallID_Secondary,
    ECurrentCallID_None,
    ECurrentCallID_Last
} ECurrentCallID;
#define eECurrentCallID_Primary ECurrentCallID_Primary
#define eECurrentCallID_Secondary ECurrentCallID_Secondary
#define eECurrentCallID_None ECurrentCallID_None
#define eECurrentCallID_Last ECurrentCallID_Last
#define tECurrentCallID ECurrentCallID
#endif

// Enumeration type EInCallStatus
#ifndef A2T_TypesProtection_EInCallStatus
#define A2T_TypesProtection_EInCallStatus
typedef enum {
    EInCallStatus_False,
    EInCallStatus_True,
    EInCallStatus_Last
} EInCallStatus;
#define eEInCallStatus_False EInCallStatus_False
#define eEInCallStatus_True EInCallStatus_True
#define eEInCallStatus_Last EInCallStatus_Last
#define tEInCallStatus EInCallStatus
#endif

// Enumeration type EPhoneIDType
#ifndef A2T_TypesProtection_EPhoneIDType
#define A2T_TypesProtection_EPhoneIDType
typedef enum {
    EPhoneIDType_Unknown,
    EPhoneIDType_Current,
    EPhoneIDType_Secondary,
    EPhoneIDType_Last
} EPhoneIDType;
#define eEPhoneIDType_Unknown EPhoneIDType_Unknown
#define eEPhoneIDType_Current EPhoneIDType_Current
#define eEPhoneIDType_Secondary EPhoneIDType_Secondary
#define eEPhoneIDType_Last EPhoneIDType_Last
#define tEPhoneIDType EPhoneIDType
#endif

// Enumeration type EPhoneLevel
#ifndef A2T_TypesProtection_EPhoneLevel
#define A2T_TypesProtection_EPhoneLevel
typedef enum {
    EphoneLevel_0,
    EphoneLevel_1,
    EphoneLevel_2,
    EphoneLevel_3,
    EphoneLevel_4,
    EphoneLevel_5,
    EphoneLevel_Inactive,
    EphoneLevel_Last
} EPhoneLevel;
#define eEphoneLevel_0 EphoneLevel_0
#define eEphoneLevel_1 EphoneLevel_1
#define eEphoneLevel_2 EphoneLevel_2
#define eEphoneLevel_3 EphoneLevel_3
#define eEphoneLevel_4 EphoneLevel_4
#define eEphoneLevel_5 EphoneLevel_5
#define eEphoneLevel_Inactive EphoneLevel_Inactive
#define eEphoneLevel_Last EphoneLevel_Last
#define tEPhoneLevel EPhoneLevel
#endif

// Enumeration type EPhoneNetwork
#ifndef A2T_TypesProtection_EPhoneNetwork
#define A2T_TypesProtection_EPhoneNetwork
typedef enum {
    EPhoneNetwork_NoNetwork,
    EPhoneNetwork_InNetwork,
    EPhoneNetwork_Roaming,
    EPhoneNetwork_NoLinkToPhone,
    EPhoneNetwork_NotSupported,
    EPhoneNetwork_Inactive,
    EPhoneNetwork_Last
} EPhoneNetwork;
#define eEPhoneNetwork_NoNetwork EPhoneNetwork_NoNetwork
#define eEPhoneNetwork_InNetwork EPhoneNetwork_InNetwork
#define eEPhoneNetwork_Roaming EPhoneNetwork_Roaming
#define eEPhoneNetwork_NoLinkToPhone EPhoneNetwork_NoLinkToPhone
#define eEPhoneNetwork_NotSupported EPhoneNetwork_NotSupported
#define eEPhoneNetwork_Inactive EPhoneNetwork_Inactive
#define eEPhoneNetwork_Last EPhoneNetwork_Last
#define tEPhoneNetwork EPhoneNetwork
#endif

// Structure type SPhoneGenericData
#ifndef A2T_TypesProtection_SPhoneGenericData
#define A2T_TypesProtection_SPhoneGenericData
typedef struct _SPhoneGenericData_tag {
    uint8 muteStatus;
    EPhoneStatus phoneStatus;
    uint16 callDuration;
    EPhoneCmd callCmd;
    ECurrentCallID currentCall;
    ENavStatus phoneDisconnect;
    EInCallStatus incommingCall;
    uint8 phoneCallCount;
    EPhoneIDType callIDType;
    EPhoneLevel phoneBatt;
    EPhoneLevel phoneSignal;
    EPhoneNetwork phoneNetwork;
} SPhoneGenericData;
#define tSPhoneGenericData SPhoneGenericData
#endif

// Structure type SMediaStatus
#ifndef A2T_TypesProtection_SMediaStatus
#define A2T_TypesProtection_SMediaStatus
typedef struct _SMediaStatus_tag {
    data_u8_9 dynData;
} SMediaStatus;
#define tSMediaStatus SMediaStatus
#endif

// Structure type SSDMGenericData
#ifndef A2T_TypesProtection_SSDMGenericData
#define A2T_TypesProtection_SSDMGenericData
typedef struct _SSDMGenericData_tag {
    data_u8_3 SDMGenericData;
} SSDMGenericData;
#define tSSDMGenericData SSDMGenericData
#endif

// Structure type SSSTMExt
#ifndef A2T_TypesProtection_SSSTMExt
#define A2T_TypesProtection_SSSTMExt
typedef struct _SSSTMExt_tag {
    SSdmArray data;
} SSSTMExt;
#define tSSSTMExt SSSTMExt
#endif

// Structure type SSSMExt
#ifndef A2T_TypesProtection_SSSMExt
#define A2T_TypesProtection_SSSMExt
typedef struct _SSSMExt_tag {
    SSdmArray data;
} SSSMExt;
#define tSSSMExt SSSMExt
#endif

// Structure type SInfotainmentGenericData
#ifndef A2T_TypesProtection_SInfotainmentGenericData
#define A2T_TypesProtection_SInfotainmentGenericData
typedef struct _SInfotainmentGenericData_tag {
    uint8 genericData;
} SInfotainmentGenericData;
#define tSInfotainmentGenericData SInfotainmentGenericData
#endif

// Structure type SPrefetchData
#ifndef A2T_TypesProtection_SPrefetchData
#define A2T_TypesProtection_SPrefetchData
typedef struct _SPrefetchData_tag {
    uint8 characterCoding;
    ElistItemId listItemId;
    uint8 listItemItemLoaded;
    EDataType listItemDataType;
    EListItemObjectType listItemObjectType;
    uint8 listItemActivationEvent;
    EItemIcon listItemIcon;
    EItemIcon listItemIcon3;
    EItemIcon listItemIcon2;
    data_u8_54 listItemData1;
    data_u8_22 listItemData2;
    uint8 listItemStaticItem;
    uint8 listItemObjectState;
} SPrefetchData;
#define tSPrefetchData SPrefetchData
#endif

// Typedef type data_u8_54
#ifndef A2T_TypesProtection_data_u8_54
#define A2T_TypesProtection_data_u8_54
typedef uint8 data_u8_54[54];
#define tdata_u8_54 data_u8_54
#endif

// Structure type SPrefetchStatus
#ifndef A2T_TypesProtection_SPrefetchStatus
#define A2T_TypesProtection_SPrefetchStatus
typedef struct _SPrefetchStatus_tag {
    uint16 status;
} SPrefetchStatus;
#define tSPrefetchStatus SPrefetchStatus
#endif

// Structure type SPrefetchGenericData
#ifndef A2T_TypesProtection_SPrefetchGenericData
#define A2T_TypesProtection_SPrefetchGenericData
typedef struct _SPrefetchGenericData_tag {
    EListServer serverId;
    EListServer serverId2;
    uint16 listId;
    uint8 lbpListServer;
    uint16 lbpListId;
    ELbpListStatus lbpListStatus;
    uint8 nbrOfItems;
} SPrefetchGenericData;
#define tSPrefetchGenericData SPrefetchGenericData
#endif

// Structure type SSafeTT_Status
#ifndef A2T_TypesProtection_SSafeTT_Status
#define A2T_TypesProtection_SSafeTT_Status
typedef struct _SSafeTT_Status_tag {
    data_u8_5 safeTTData;
} SSafeTT_Status;
#define tSSafeTT_Status SSafeTT_Status
#endif

// Structure type SSwUpdateMetaReadReq
#ifndef A2T_TypesProtection_SSwUpdateMetaReadReq
#define A2T_TypesProtection_SSwUpdateMetaReadReq
typedef struct _SSwUpdateMetaReadReq_tag {
    uint32 startAddress;
    uint8 paramId;
    uint32 length;
    uint8 serviceId;
} SSwUpdateMetaReadReq;
#define tSSwUpdateMetaReadReq SSwUpdateMetaReadReq
#endif

// Structure type SSwUpdateMetaWriteReq
#ifndef A2T_TypesProtection_SSwUpdateMetaWriteReq
#define A2T_TypesProtection_SSwUpdateMetaWriteReq
typedef struct _SSwUpdateMetaWriteReq_tag {
    uint32 startAddress;
    uint8 paramId;
    uint32 data;
    uint32 length;
    uint8 serviceId;
} SSwUpdateMetaWriteReq;
#define tSSwUpdateMetaWriteReq SSwUpdateMetaWriteReq
#endif

// Structure type SErrorStateCmdResp
#ifndef A2T_TypesProtection_SErrorStateCmdResp
#define A2T_TypesProtection_SErrorStateCmdResp
typedef struct _SErrorStateCmdResp_tag {
    uint8 errorStateResponse;
} SErrorStateCmdResp;
#define tSErrorStateCmdResp SErrorStateCmdResp
#endif

// Structure type SErrorStateCmdReq
#ifndef A2T_TypesProtection_SErrorStateCmdReq
#define A2T_TypesProtection_SErrorStateCmdReq
typedef struct _SErrorStateCmdReq_tag {
    uint8 errorStateAction;
} SErrorStateCmdReq;
#define tSErrorStateCmdReq SErrorStateCmdReq
#endif

// Typedef type data_u8_7
#ifndef A2T_TypesProtection_data_u8_7
#define A2T_TypesProtection_data_u8_7
typedef uint8 data_u8_7[7];
#define tdata_u8_7 data_u8_7
#endif

// Structure type SHmiChecksumDataType
#ifndef A2T_TypesProtection_SHmiChecksumDataType
#define A2T_TypesProtection_SHmiChecksumDataType
typedef struct _SHmiChecksumDataType_tag {
    data_u32_3 dispCtrlChecksumValue;
    uint8 regionid;
    uint8 assetid;
} SHmiChecksumDataType;
#define tSHmiChecksumDataType SHmiChecksumDataType
#endif

// Structure type SAdjLimit
#ifndef A2T_TypesProtection_SAdjLimit
#define A2T_TypesProtection_SAdjLimit
typedef struct _SAdjLimit_tag {
    uint8 AdjLimit;
} SAdjLimit;
#define tSAdjLimit SAdjLimit
#endif

// Typedef type data_u8_17
#ifndef A2T_TypesProtection_data_u8_17
#define A2T_TypesProtection_data_u8_17
typedef uint8 data_u8_17[17];
#define tdata_u8_17 data_u8_17
#endif

// Structure type SIODRBM
#ifndef A2T_TypesProtection_SIODRBM
#define A2T_TypesProtection_SIODRBM
typedef struct _SIODRBM_tag {
    data_u8_20 dynData;
} SIODRBM;
#define tSIODRBM SIODRBM
#endif

// Typedef type data_u8_30
#ifndef A2T_TypesProtection_data_u8_30
#define A2T_TypesProtection_data_u8_30
typedef uint8 data_u8_30[30];
#define tdata_u8_30 data_u8_30
#endif

// Structure type SChecksumValue2
#ifndef A2T_TypesProtection_SChecksumValue2
#define A2T_TypesProtection_SChecksumValue2
typedef struct _SChecksumValue2_tag {
    data_u8_30 checksumData2;
} SChecksumValue2;
#define tSChecksumValue2 SChecksumValue2
#endif

// Structure type SChecksumValue3
#ifndef A2T_TypesProtection_SChecksumValue3
#define A2T_TypesProtection_SChecksumValue3
typedef struct _SChecksumValue3_tag {
    data_u8_30 checksumData3;
} SChecksumValue3;
#define tSChecksumValue3 SChecksumValue3
#endif

// Structure type SChecksumValue4
#ifndef A2T_TypesProtection_SChecksumValue4
#define A2T_TypesProtection_SChecksumValue4
typedef struct _SChecksumValue4_tag {
    data_u8_30 checksumData4;
} SChecksumValue4;
#define tSChecksumValue4 SChecksumValue4
#endif

// Structure type SHighVoltageBatteryBEVDisplay
#ifndef A2T_TypesProtection_SHighVoltageBatteryBEVDisplay
#define A2T_TypesProtection_SHighVoltageBatteryBEVDisplay
typedef struct _SHighVoltageBatteryBEVDisplay_tag {
    uint8 batterySOC;
    uint8 chargeColor;
    uint8 chargeIcon;
    uint8 destinationFlag;
    uint8 SoCDestFlag;
    uint8 percentDestination;
    uint8 HVBPower;
} SHighVoltageBatteryBEVDisplay;
#define tSHighVoltageBatteryBEVDisplay SHighVoltageBatteryBEVDisplay
#endif

// Structure type SPowerDistributionBEV
#ifndef A2T_TypesProtection_SPowerDistributionBEV
#define A2T_TypesProtection_SPowerDistributionBEV
typedef struct _SPowerDistributionBEV_tag {
    uint8 frontFill;
    uint8 rearFill;
    uint8 fMotorMode;
    uint8 rMotorMode;
} SPowerDistributionBEV;
#define tSPowerDistributionBEV SPowerDistributionBEV
#endif

// Typedef type data_u8_21
#ifndef A2T_TypesProtection_data_u8_21
#define A2T_TypesProtection_data_u8_21
typedef uint8 data_u8_21[21];
#define tdata_u8_21 data_u8_21
#endif

// Typedef type data_u8_35
#ifndef A2T_TypesProtection_data_u8_35
#define A2T_TypesProtection_data_u8_35
typedef uint8 data_u8_35[35];
#define tdata_u8_35 data_u8_35
#endif

// Structure type SNotReadyToDrive
#ifndef A2T_TypesProtection_SNotReadyToDrive
#define A2T_TypesProtection_SNotReadyToDrive
typedef struct _SNotReadyToDrive_tag {
    uint8 ShutdownChargeStatusText;
    uint8 ChargeNowDuration;
    uint8 EndChargeTimeDay;
    uint8 EndChargeTimeHours;
    uint8 EndChargeTimeMinutes;
    uint8 StartChargeTimeDay;
    uint8 StartChargeTimeHours;
    uint8 StartChargeTimeMinutes;
    uint8 PowerOnChargeStatusText;
    uint8 DestChargeEndTimeDay;
    uint8 DestChargeEndTimeHours;
    uint8 DestChargeEndTimeMinutes;
    uint8 TargetSoc;
    uint16 NotReadyToDriveFlags;
} SNotReadyToDrive;
#define tSNotReadyToDrive SNotReadyToDrive
#endif

// Typedef type data_u8_14
#ifndef A2T_TypesProtection_data_u8_14
#define A2T_TypesProtection_data_u8_14
typedef uint8 data_u8_14[14];
#define tdata_u8_14 data_u8_14
#endif

// Structure type SElectricRange
#ifndef A2T_TypesProtection_SElectricRange
#define A2T_TypesProtection_SElectricRange
typedef struct _SElectricRange_tag {
    uint16 electricRange;
    uint8 electricRangeColorStatus;
    uint16 distanceToDestination;
    uint8 displayDistanceStatus;
    uint8 stackGaugeIcons;
} SElectricRange;
#define tSElectricRange SElectricRange
#endif

// Structure type SDAMyView
#ifndef A2T_TypesProtection_SDAMyView
#define A2T_TypesProtection_SDAMyView
typedef struct _SDAMyView_tag {
    data_u8_8 myViewDynData;
} SDAMyView;
#define tSDAMyView SDAMyView
#endif

// Structure type SDAMenu
#ifndef A2T_TypesProtection_SDAMenu
#define A2T_TypesProtection_SDAMenu
typedef struct _SDAMenu_tag {
    uint8 header;
    uint8 DAViewID;
} SDAMenu;
#define tSDAMenu SDAMenu
#endif

// Structure type SDAHMIPoup
#ifndef A2T_TypesProtection_SDAHMIPoup
#define A2T_TypesProtection_SDAHMIPoup
typedef struct _SDAHMIPoup_tag {
    data_u8_2 DAHMIpopupDynData;
} SDAHMIPoup;
#define tSDAHMIPoup SDAHMIPoup
#endif

// Structure type SBMInitialDisplayStatus
#ifndef A2T_TypesProtection_SBMInitialDisplayStatus
#define A2T_TypesProtection_SBMInitialDisplayStatus
typedef struct _SBMInitialDisplayStatus_tag {
    uint8 BMInitialDisplay;
} SBMInitialDisplayStatus;
#define tSBMInitialDisplayStatus SBMInitialDisplayStatus
#endif

// Typedef type data_u8_39
#ifndef A2T_TypesProtection_data_u8_39
#define A2T_TypesProtection_data_u8_39
typedef uint8 data_u8_39[39];
#define tdata_u8_39 data_u8_39
#endif

// Structure type SVehicleFleetPhoneNumberSt
#ifndef A2T_TypesProtection_SVehicleFleetPhoneNumberSt
#define A2T_TypesProtection_SVehicleFleetPhoneNumberSt
typedef struct _SVehicleFleetPhoneNumberSt_tag {
    data_u8_39 VehicleFleetPhoneNumberSt;
} SVehicleFleetPhoneNumberSt;
#define tSVehicleFleetPhoneNumberSt SVehicleFleetPhoneNumberSt
#endif

// Structure type SFleetMenuWarnStatus
#ifndef A2T_TypesProtection_SFleetMenuWarnStatus
#define A2T_TypesProtection_SFleetMenuWarnStatus
typedef struct _SFleetMenuWarnStatus_tag {
    uint8 fleetMenuWarnStatus;
} SFleetMenuWarnStatus;
#define tSFleetMenuWarnStatus SFleetMenuWarnStatus
#endif

// Structure type SHealthEventRecord
#ifndef A2T_TypesProtection_SHealthEventRecord
#define A2T_TypesProtection_SHealthEventRecord
typedef struct _SHealthEventRecord_tag {
    uint8 recordType;
    uint8 recordLen;
    data_u8_8 recordData;
} SHealthEventRecord;
#define tSHealthEventRecord SHealthEventRecord
#endif

// Typedef type data_u8_1_copy
#ifndef A2T_TypesProtection_data_u8_1_copy
#define A2T_TypesProtection_data_u8_1_copy
typedef uint8 data_u8_1_copy[8];
#define tdata_u8_1_copy data_u8_1_copy
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __UclProxyCdd_Typedefs_G_h__
