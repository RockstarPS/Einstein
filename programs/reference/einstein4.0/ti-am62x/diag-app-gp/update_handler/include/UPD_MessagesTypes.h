//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef UPD_MESSAGES_TYPES_H
#define UPD_MESSAGES_TYPES_H

#include "UPD_Types.h" // required for public types exposed by the UpdateService

#define UPD_STATIC_ASSERT(COND,MSG) typedef char static_assertion_##MSG[(COND)?1:-1]

//---------------------------------------------------------------------------------------------------------------------
// Protocol version
//---------------------------------------------------------------------------------------------------------------------
#define UPD_MSG_VERSION_MAJOR 2u
#define UPD_MSG_VERSION_MINOR 0u
#define UPD_MSG_VERSION_PATCH 0u

//---------------------------------------------------------------------------------------------------------------------
// General constants
//---------------------------------------------------------------------------------------------------------------------
#define UPD_MIN_REQ_MESSAGE_SIZE   64  // From QNX to Peripheral
#define UPD_MIN_RESP_MESSAGE_SIZE  64  // From Peripheral to QNX
#define UPD_LONG_REQ_MESSAGE_SIZE  512 // From QNX to Peripheral

// One more message for data transmission, size depends on the backend (UCL, SomeIP) UCL : 256Bytes @10ms => 100s for 2MB on VIP - 50s

#define UPD_MAX_TARGET_COUNT      14  // To keep tUPDMsgResp_GetStates < 64 Bytes
#define UPD_MAX_HASH_SIZE         48  // compatible with SHA384 if required
#define UPD_MAX_VERSION_SIZE      48  // Version format is 2 bytes major, 2 bytes minor, 2 bytes revision. Size to support data also if required (00.00.00.yyyy.mm.dd)
#define UPD_STRING_SIZE           48  // for Service Name, HardwareVersion, Target Name, Package Name
#define UPD_LONG_STRING_SIZE      384 // for Service Name, HardwareVersion, Target Name, Package Name
#define UPD_REQRESP_TIMEOUT_MS    50  // Peripheral shall respond in less than this timeout. (can be UPD_PENDING)

//---------------------------------------------------------------------------------------------------------------------
// General types
//---------------------------------------------------------------------------------------------------------------------

typedef char tUPDMsgString[UPD_STRING_SIZE]; // for Service Name, HardwareVersion, Target Name, Package Name
typedef char tUPDMsgLongString[UPD_LONG_STRING_SIZE]; // for Service Name, HardwareVersion, Target Name, Package Name

//---------------------------------------------------------------------------------------------------------------------
// Minimal Req-Resp
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------
typedef uint8 tUPDMsgReqType; // See #define UPD_REQRESP_<*> for specifc values

typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Payload[UPD_MIN_REQ_MESSAGE_SIZE - sizeof(tUPDMsgReqType)];
} tUPDMsgReq;

typedef struct
{
    tUPDMsgReqType  Request; // 8 bits // Same as tUPDMsgReq.Request
    tUPDStatus      Status;
    uint8           Payload[UPD_MIN_RESP_MESSAGE_SIZE - sizeof(tUPDMsgReqType) - sizeof(tUPDStatus)];
} tUPDMsgResp;


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetProtocolVersion(Bank)
#define UPD_REQRESP_GETPROTOCOLVERSION    0xFFu
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq - (default tUPDMsgReq structure is used without payload)
// Structure to be used for the response: tUPDMsgResp_GetProtocolVersion(tVersion*)
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits 
    tUPDStatus      Status; // 8 bits
    uint16     Major;
    uint16     Minor;
    uint16     Patch;
} tUPDMsgResp_GetProtocolVersion;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetProtocolVersion) <= sizeof(tUPDMsgReq), tUPDMsgResp_GetProtocolVersion_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType StartUpdate(Bank)
#define UPD_REQRESP_START_UPDATE    0x01u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_StartUpdate
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDBank        Bank; // 8 bits
} tUPDMsgReq_StartUpdate;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_StartUpdate) <= sizeof(tUPDMsgReq), tUPDMsgReq_StartUpdate_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Activate()
#define UPD_REQRESP_ACTIVATE        0x02u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq - (default tUPDMsgReq structure is used without payload)
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Rollback() - UpdService::Rollback()
#define UPD_REQRESP_ROLLBACK        0x03u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq - (default tUPDMsgReq structure is used without payload)
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Terminate() - UpdService::Commit() or UpdService::Cancel()
#define UPD_REQRESP_TERMINATE       0x04u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType EnterInMode() - UpdService::EnterInMode()
#define UPD_REQRESP_ENTERINMODE     0x05u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_EnterInMode
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------
typedef tUPDMode tUPDMsgMode;

typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDMsgMode        Mode;  // 8 bits
    boolean            RestartNow;  // 8 bits
} tUPDMsgReq_EnterInMode;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_EnterInMode) <= sizeof(tUPDMsgResp), tUPDMsgReq_EnterInMode_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType PostActivate() - UpdService::PostActivate()
#define UPD_REQRESP_POST_ACTIVATE   0x06u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_PostActivate
// Structure to be used for the response: tUPDMsgResp_PostActivate
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;  // 8 bits
    uint16          Padding2;  // 16 bits
    uint32          TargetMask; // Bit 0 for target 0, Bit N for target N
} tUPDMsgReq_PostActivate;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_PostActivate) <= sizeof(tUPDMsgReq), tUPDMsgReq_PostActivate_is_too_big);

typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDStatus         Status;
    uint16             Padding;
    uint32             SuccessfulTargetMask; // Bit 0 for target 0, Bit N for target N
    uint32             FailedTargetMask; // Bit 0 for target 0, Bit N for target N
} tUPDMsgResp_PostActivate;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_PostActivate) <= sizeof(tUPDMsgResp), tUPDMsgResp_PostActivate_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Commit() - UpdService::Commit()
#define UPD_REQRESP_COMMIT          0x07u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetStates(tStates*) - IUpdService::GetStates()
#define UPD_REQRESP_GETSTATES       0x11u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp_GetStates
//---------------------------------------------------------------------------------------------------------------------
typedef tUPDUpdateState  tUPDMsgUpdateState; // exact states are defined in the Update Service header
typedef tUPDiTargetState tUPDMsgTagetState;  // exact states are defined in the Update Service header

typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status; // 8 bits
    tUPDMsgUpdateState UpdateState; // 16 bits
    tUPDMsgTagetState  ActiveTargetsState[UPD_MAX_TARGET_COUNT];  // 14 * 16 bits
    tUPDMsgTagetState  InactiveTargetsState[UPD_MAX_TARGET_COUNT];  // 14 * 16 bits
    uint8              TargetCount; // 8 bits
    boolean            ActiveSlot;// FALSE = BANKA; TRUE=BANKB
} tUPDMsgResp_GetStates;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetStates) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetStates_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetMetaInfo1(tMeta1*) -  IUpdService::GetMetaInfo()
#define UPD_REQRESP_GETMETA_INFO1        0x12u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp_GetMetaInfo1
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status;// 8 bits
    uint8              TargetCount; // 8 bits
    uint8              Padding; // 8 bits
    uint32             QueueSize;
    tUPDMsgString      ServiceName;
    uint32             MaxDataMsgSize; // 0 is considered as default : 256
} tUPDMsgResp_GetMetaInfo1;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetMetaInfo1) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetMetaInfo1_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetMetaInfo2(tMeta2*)-  IUpdService::GetMetaInfo()
#define UPD_REQRESP_GETMETA_INFO2        0x13u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp_GetMetaInfo2
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status;// 8 bits
    tUPDMsgString      HW_ID;
} tUPDMsgResp_GetMetaInfo2;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetMetaInfo2) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetMetaInfo2_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetTargetMetaInfo1(TargetId, tMeta*) -  IUpdService::GetTargetMetaInfo()
#define UPD_REQRESP_TARGET_GETMETA_INFO1 0x14u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_GetTargetMetaInfo
// Structure to be used for the response: tUPDMsgResp_GetTargetMetaInfo1
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           TargetId; // shall be stricly lower than TargetCount
} tUPDMsgReq_GetTargetMetaInfo;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_GetTargetMetaInfo) <= sizeof(tUPDMsgReq), tUPDMsgReq_GetTargetMetaInfo_is_too_big);

typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDStatus         Status;  // 8 bits
    uint8              TargetId; // 8 bits
    tUPDMsgString      TargetName;
} tUPDMsgResp_GetTargetMetaInfo1;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetTargetMetaInfo1) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetTargetMetaInfo1_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetTargetMetaInfo2(TargetId, tMeta*) - IUpdService::GetTargetMetaInfo()
#define UPD_REQRESP_TARGET_GETMETA_INFO2 0x15u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_GetTargetMetaInfo
// Structure to be used for the response: tUPDMsgResp_GetTargetMetaInfo2
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDStatus         Status; // 8 bits
    uint8              TargetId; // 8 bits
    uint8              ActiveHashSize; // Size in Byte, 4 for CRC32, 32 for SHA256
    tUPDHashingType    ActiveHashType; // 8 bits
    uint8              ActiveHash[UPD_MAX_HASH_SIZE];
} tUPDMsgResp_GetTargetMetaInfo2;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetTargetMetaInfo2) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetTargetMetaInfo2_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetTargetMetaInfo3(TargetId, tMeta*) - IUpdService::GetTargetMetaInfo()
#define UPD_REQRESP_TARGET_GETMETA_INFO3 0x16u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_GetTargetMetaInfo
// Structure to be used for the response: tUPDMsgResp_GetTargetMetaInfo3
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status;// 8 bits
    uint8              TargetId;// 8 bits
    uint8              InactiveHashSize; // Size in Byte, 4 for CRC32, 32 for SHA256
    tUPDHashingType    InactiveHashType; // 8 bits
    uint8              InactiveHash[UPD_MAX_HASH_SIZE];
} tUPDMsgResp_GetTargetMetaInfo3;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetTargetMetaInfo3) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetTargetMetaInfo3_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetTargetMetaInfo4(TargetId, tMeta*) - IUpdService::GetTargetMetaInfo()
#define UPD_REQRESP_TARGET_GETMETA_INFO4 0x17u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_GetTargetMetaInfo
// Structure to be used for the response: tUPDMsgResp_GetTargetMetaInfo4
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status;// 8 bits
    uint8              TargetId;// 8 bits
    uint8              ActiveVersionSize; // Size in Byte of the version string
    uint8              ActiveVersion[UPD_MAX_VERSION_SIZE];
} tUPDMsgResp_GetTargetMetaInfo4;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetTargetMetaInfo4) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetTargetMetaInfo4_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType GetTargetMetaInfo5(TargetId, tMeta*) - IUpdService::GetTargetMetaInfo()
#define UPD_REQRESP_TARGET_GETMETA_INFO5 0x18u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_GetTargetMetaInfo
// Structure to be used for the response: tUPDMsgResp_GetTargetMetaInfo5
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType     Request;// 8 bits
    tUPDStatus         Status;// 8 bits
    uint8              TargetId;// 8 bits
    uint8              InactiveVersionSize; // Size in Byte of the version string
    uint8              InactiveVersion[UPD_MAX_VERSION_SIZE];
} tUPDMsgResp_GetTargetMetaInfo5;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_GetTargetMetaInfo5) <= sizeof(tUPDMsgResp), tUPDMsgResp_GetTargetMetaInfo5_is_too_big);


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Suspend() - IUpdService::Suspend()
#define UPD_REQRESP_SUSPEND              0x21u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType TransferResume() - IUpdService::TransferResume(PackageName,PackageSize)
#define UPD_REQRESP_TRANSFER_RESUME      0x22u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_Resume
// Structure to be used for the response: tUPDMsgResp_Resume
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;
    uint16          Padding2;
    uint32          PackageSize;
    tUPDMsgString   PakageName; // example: VIP_HSM.raw.gz.aes128
} tUPDMsgReq_Resume;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_Resume) <= sizeof(tUPDMsgReq), tUPDMsgReq_Resume_is_too_big);

typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDStatus         Status; // 8 bits
    uint16             Padding;
    uint32             NextOffset;
} tUPDMsgResp_Resume;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_Resume) <= sizeof(tUPDMsgResp), tUPDMsgResp_Suspend_is_too_big);


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType CopyActiveToInactive(TargetMask) - IUpdService::CopyActiveToInactive()
#define UPD_REQRESP_COPY_ACTIVE_TO_INACTIVE   0x31u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_CopyActiveToInactive
// Structure to be used for the response: tUPDMsgResp_CopyActiveToInactive
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;  // 8 bits
    uint16          Padding2;  // 16 bits
    uint32          TargetMask; // Bit 0 for target 0, Bit N for target N
} tUPDMsgReq_CopyActiveToInactive;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_CopyActiveToInactive) <= sizeof(tUPDMsgReq), tUPDMsgReq_CopyActiveToInactive_is_too_big);

typedef struct
{
    tUPDMsgReqType     Request; // 8 bits
    tUPDStatus         Status;  // Status = E_OK indicates that the request have been processed 
                                // but some copies may have failed, see bellow.
    uint16             Padding;
    uint32             SuccessfulTargetMask; // Bit 0 for target 0, Bit N for target N
    uint32             FailedTargetMask; // Bit 0 for target 0, Bit N for target N
} tUPDMsgResp_CopyActiveToInactive;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_CopyActiveToInactive) <= sizeof(tUPDMsgResp), tUPDMsgResp_CopyActiveToInactive_is_too_big);


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Verify(HashType,HashSize,Bank,Target)  - IUpdService::Verify() - TBD
#define UPD_REQRESP_VERIFY_VERSION   0x40u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_VerifyVersion
// Structure to be used for the response: tUPDMsgResp_VerifyVersion
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDBank        Bank;    // NOTE, Bank is unused anymore, Verify always applies the the bank concerned by the update
    uint8           TargetId; // 8 bits
    uint8           VersionSize; // Size in bytes of the version string
    uint8           Version[UPD_MAX_VERSION_SIZE];
} tUPDMsgReq_VerifyVersion;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_VerifyVersion) <= sizeof(tUPDMsgReq), tUPDMsgReq_VerifyVersion_is_too_big);

typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDStatus      Status; // 8 bits
    uint8           TargetId;// 8 bits
    boolean         TargetVerfied;
} tUPDMsgResp_VerifyVersion;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_VerifyVersion) <= sizeof(tUPDMsgResp), tUPDMsgResp_VerifyVersion_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Verify(HashType,HashSize,Bank,Target)  - IUpdService::Verify()
#define UPD_REQRESP_VERIFY           0x41u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_Verify
// Structure to be used for the response: tUPDMsgResp_Verify
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDBank        Bank;    // NOTE, Bank is unused anymore, Verify always applies the the bank concerned by the update
    uint8           TargetId; // 8 bits
    uint8           HashSize; // Size in Byte, 4 for CRC32, 32 for SHA256
    tUPDHashingType HashType; // 8 bits
    uint8           Hash[UPD_MAX_HASH_SIZE];
} tUPDMsgReq_Verify;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_Verify) <= sizeof(tUPDMsgReq), tUPDMsgReq_Verify_is_too_big);

typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDStatus      Status; // 8 bits
    uint8           TargetId;// 8 bits
    boolean         TargetVerfied;
} tUPDMsgResp_Verify;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_Verify) <= sizeof(tUPDMsgResp), tUPDMsgResp_Verify_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType Validate() - IUpdService::Validate()
// Verfies the secure boot signatures for inactive chain
#define UPD_REQRESP_VALIDATE         0x42u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType TransferStart(PakageName,PackageSize,tStatus*)  - IUpdService::ProcessPackage()
#define UPD_REQRESP_TRANFER_START    0x51u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_TransferStart
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;
    uint16          Padding2;
    uint32          PackageSize;
    tUPDMsgString   PakageName; // example: VIP_HSM.raw.gz.aes128
} tUPDMsgReq_TransferStart;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_TransferStart) <= sizeof(tUPDMsgReq), tUPDMsgReq_TransferStart_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType TransferData(Offset,Size,Data,TransferState*)  - IUpdService::ProcessPackage()
#define UPD_REQRESP_TRANSFER_DATA    0x52u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_TransferData
// Structure to be used for the response: tUPDMsgResp_TransferData
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;
    uint16          Padding2;
    uint32          Offset;
    uint32          Size;
    // Max data size is not imposed, it depends on the communication backend
    uint8           Data[1];
} tUPDMsgReq_TransferData;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_TransferData) <= sizeof(tUPDMsgReq), tUPDMsgReq_TransferData_is_too_big);

typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDStatus      Status; // 8 bits
    uint16          Padding;
    uint32          NextOffset;
    uint32          AvailableQueueSize;
} tUPDMsgResp_TransferData;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_TransferData) <= sizeof(tUPDMsgResp), tUPDMsgResp_TransferData_is_too_big);


//UPD_REQ_TRANSFER_DATA_FF is not supported in version 1.0.0 of the protocol
//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType TransferDataFF(Offset,Size,Data,TransferState*)  - IUpdService::ProcessPackage()
#define UPD_REQ_TRANSFER_DATA_FF 0x53u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_TransferData
// Structure to be used for the response: None
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType TransferExit() - IUpdService::ProcessPackage()
#define UPD_REQRESP_TRANSFER_EXIT    0x54u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp_TransferExit
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDStatus      Status; // 8 bits
    // KPIs
    uint8           IoLoad;     //Percentage of time spent with a non-empty Io queue 
    uint8           UpdateLoad; //Percentage of time spent with a non-empty update queue 
    uint32          TansferDurationMs;
    uint32          MaxQueueOccupation;
    uint32          AverageQueueOccupation;
    uint32          MinQueueOccupation;
} tUPDMsgResp_TransferExit;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_TransferExit) <= sizeof(tUPDMsgResp), tUPDMsgResp_TransferExit_is_too_big);


//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType IndirectTransferStart(PakageName,PackageOffset,PackageSize)  - IUpdService::ProcessPackage()
#define UPD_REQRESP_INDIRECT_TRANFER_START   0x61u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq_TransferStart
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    uint8           Padding1;
    uint16          Padding2;
    uint32              PackageSize;    // Size of the image within the container
    uint32              PackageOffset;  // Offset of the image within the container
    tUPDMsgLongString   PackagePath;    // tarball path from the NFS folder + path of the image within the container
} tUPDMsgReq_IndirectTransferStart;
UPD_STATIC_ASSERT(sizeof(tUPDMsgReq_IndirectTransferStart) <= UPD_LONG_REQ_MESSAGE_SIZE, tUPDMsgReq_IndirectTransferStart_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType IndirectTransferStatus(PakageName,PackageSize,tStatus*)  - IUpdService::ProcessPackage()
#define UPD_REQRESP_INDIRECT_TRANFER_STATUS  0x62u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp_IndirectTransferStatus
//---------------------------------------------------------------------------------------------------------------------
typedef struct
{
    tUPDMsgReqType  Request; // 8 bits
    tUPDStatus      Status; // 8 bits - eUPD_Pending during installation / eUPD_Ok or eUPD_NotOk at the end
    uint16          Padding;
    uint32          PackageSize; // Size of the image within the container
    uint32          InstalledSize; // shall be = to PackageSize when transfer is completed.
                                   // It is used to report the progress and can be an approximation
} tUPDMsgResp_IndirectTransferStatus;
UPD_STATIC_ASSERT(sizeof(tUPDMsgResp_IndirectTransferStatus) <= sizeof(tUPDMsgResp), tUPDMsgResp_IndirectTransferStatus_is_too_big);

//---------------------------------------------------------------------------------------------------------------------
// <ReqResp> Std_ReturnType IndirectTransferCancel()  - IUpdService::ProcessPackage()
#define UPD_REQRESP_INDIRECT_TRANFER_CANCEL  0x63u
//---------------------------------------------------------------------------------------------------------------------
// Structure to be used for the request: tUPDMsgReq
// Structure to be used for the response: tUPDMsgResp
//---------------------------------------------------------------------------------------------------------------------

#endif
