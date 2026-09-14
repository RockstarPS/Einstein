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
//=============================================================================
// @file        UpdUpdaterTypes.hpp
// @brief       
//
//---------------------------------------------------------------------------------------------------------------------//


#ifndef __UPD_UPDATER_TYPES__
#define __UPD_UPDATER_TYPES__

#include <cstdint>
#include <memory>
#include <vector>
#include <string>

#include "UPD_Types.h"

#define UPD_INDIRECT_STATUS_REQ_INTERVAL	5000 // 5sec
#define UPD_LOG_LEVEL						UPD_LOG_LEVEL_DEBUG


namespace Visteon
{
namespace Update
{

enum
{
	UPD_LOG_LEVEL_CRITICAL,
	UPD_LOG_LEVEL_ERROR,
	UPD_LOG_LEVEL_INFO,
	UPD_LOG_LEVEL_DEBUG,
	UPD_LOG_LEVEL_VERBOSE
};
typedef uint8_t tUPDLogLevel;

typedef struct
{
	std::string hwID;
	uint32_t    maxDataSize;
} Local_ProxyParams;

typedef struct
{
	bool       is_pending;
	tUPDStatus status;
} tRespStatus;

typedef struct
{
	uint16_t major;
	uint16_t minor;
	uint16_t patch;
} tProtocolVersion;

typedef struct
{
	tUPDMode  mode;
	bool      restartNow;
} tModeRequest;

typedef std::vector<tUPDiTargetState> tUPDTargetStates;  // changed the vector type to tUPDiTargetState from tUPDTagetState

typedef std::vector<uint8_t> tUPDTargets;

typedef struct
{
	tUPDUpdateState   updateState;
	tUPDTargetStates  activeTargetsStates;
	tUPDTargetStates  inactiveTargetsStates;
	uint32_t          installedSize;    // wrt to processPkg for inprogress target
	uint32_t          packageSize;      // wrt to processPkg for inprogress target
	bool              activeBank;       // false = BANKA and true = BANKB
} tUPDStatesInfo;

typedef struct
{
	uint16_t     targetCount;
	uint32_t     queueSize;
	std::string  serviceName;
	std::string  hwId;
	uint32_t     maxDataChunkSize;
} tUPDMetaInfo;

typedef struct
{
	uint8_t          targetId;
	std::string      targetName;
	uint8_t          activehashSize;
	tUPDHashingType  activeHashType;
	std::string      activeHash;
	uint8_t          inactivehashSize;
	tUPDHashingType  inactiveHashType;
	std::string      inactiveHash;
} tUPDTargetInfo;

typedef std::vector<tUPDTargetInfo> tUPDTargetsInfo;

typedef struct
{
	uint8_t          targetId;
	std::string      targetName;
	uint8_t          activeVersionSize;
	std::string      activeVersion;
	uint8_t          inactiveVersionSize;
	std::string      inactiveVersion;
} tUPDTargetInfoVersion;

typedef std::vector<tUPDTargetInfoVersion> tUPDTargetsInfoVer;

typedef struct
{
	tUPDBank         bank;
	uint8_t          target;
	uint8_t          hashSize;
	tUPDHashingType  hashType;
	std::string      hash;
} tUPDVerifyReq;

typedef struct
{
	tUPDBank         bank;
	uint8_t          target;
	uint8_t          versionSize;
	std::string      version;
} tUPDVerifyVerReq;

typedef struct
{
	uint16_t maxRetryCount;
	uint32_t maxRespTimeoutMs;
	uint16_t pendRespSleepMs;
} tUPDReqRespComProp;

typedef struct 
{
	tUPDReqRespComProp startUpdateReqResp;
	tUPDReqRespComProp transferStartReqResp;
	tUPDReqRespComProp transferDataReqResp;
	tUPDReqRespComProp transferExitReqResp; // Required ?? for ADSP testing, exit was taking time for compressed update
	tUPDReqRespComProp verifyReqResp;
	tUPDReqRespComProp validateReqResp;
	tUPDReqRespComProp acivateReqResp;
	tUPDReqRespComProp postAcivateReqResp;
	tUPDReqRespComProp rollbackReqResp;
	tUPDReqRespComProp resumeReqResp;
	tUPDReqRespComProp copyActInactReqResp;
} tUPDReqRespCommProps;

typedef struct
{
	uint16_t interBatchDelayMs;
	uint16_t interTxMs;
	uint32_t maxDataSize;
	uint8_t  batchSizeFF;
	bool     useModeFF;
} tUPDComPramsDataTrnsf;


typedef struct
{
	uint8_t   reqGroupId;
	uint8_t   reqMsgId;
	uint8_t   dataMsgId;
	uint8_t   respGroupId;
	uint8_t   respMsgId;
	uint16_t  resTimeout;
	tUPDComPramsDataTrnsf commPramsFG;
	tUPDComPramsDataTrnsf commPramsBG;
	tUPDReqRespCommProps  reqRespPrams;
} UCL_ProxyParams;

typedef struct
{
	uint16_t  serviceId;
	uint16_t  reqMsgId;
	uint16_t  dataMsgId;
	uint16_t  resTimeout;
	bool      isIndirect;
	bool      isTcpReq;
	tUPDComPramsDataTrnsf commPramsFG;
	tUPDComPramsDataTrnsf commPramsBG;
	tUPDReqRespCommProps  reqRespPrams;
} SOMEIP_ProxyParams;


} // namespace Visteon
} // namespace Update

#endif //__UPD_UPDATER_TYPES__

