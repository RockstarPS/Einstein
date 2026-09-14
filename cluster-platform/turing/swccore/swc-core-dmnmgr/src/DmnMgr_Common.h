//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
//--------------------------------------------------------------------------------------------------------------------

#ifndef DmnMgr_Common_h
#define DmnMgr_Common_h "DmnMgr_Common.h"

#include <Rte_DmnMgr.h>
#include "Rte_DmnMgr_stubs.h"
#include "DmnMgr_Types.h"
#include "DmnMgr_Cfg.h"

#define DMNMGR_START_SEC_CONST_8
#include "MemMap.h"

#ifndef DMNMGR_TASK_PERIOD_PROGRAMSPECIFIC
#define DMNMGR_TASK_PERIOD_MS			(4u)	///< The periodicity at which Domain Manager Main fucntion is scheduled to run
#endif
#define DMNMGR_RTC_UPDATE_PERIOD_MS     (10000u)
#define UNKNOWN							(0xFFu)
#if 0
#define EThermalStatus_Normal			((EThermalStatus_t)(0u))  misra_c_2012_rule_2_5_violation 
#define	EThermalStatus_Active			((EThermalStatus_t)(1u))  misra_c_2012_rule_2_5_violation 
#define	EThermalStatus_Critical			((EThermalStatus_t)(2u))  misra_c_2012_rule_2_5_violation 
#define	EThermalStatus_Last				((EThermalStatus_t)(3u))   misra_c_2012_rule_2_5_violation 
#endif
#define UINT8_MAX_VALUE                 (0xFFu)
#define UINT32_MAX_VALUE                (0xFFFFFFFFu)

#ifdef DMNMGR_MULTIDOMIANS_ENABLE
#define DMNMGR_DM_SHUTDOWN              (0xFAFBFCFA)
#endif

#ifdef HEALTHLOGGING_ENABLE
/* Healthlog Report codes/Reset Reasons from DmnMgr */
#define DMNMGR_ICOM_UCL_NOT_START                     (uint16)0xFD00  /* UCL communication never established */
#define DMNMGR_ICOM_UCL_FAILURE                       (uint16)0xFD01  /* UCL communication failure */
#define DMNMGR_ICOM_GIP_PP_NOT_RECEIVED               (uint16)0xFE00  /* GIP Pong never received during initial detection */
#define DMNMGR_ICOM_GIP_PP_STOPPED                    (uint16)0xFE01  /* GIP Pong stopped after initial detection */
#define DMNMGR_ICOM_GIP_PP_MISMATCH                   (uint16)0xFE02  /* GIP Pong sequence ID mismatch */
#define DMNMGR_ICOM_GIP_FATAL_ERROR                   (uint16)0xFE03  /* GIP process health fatal error */
#define DMNMGR_ICOM_GIP_SHUTDOWN_TIMEOUT              (uint16)0xFE04  /* GIP not responding to the shutdown state request */
#endif

#define DMNMGR_UCL_E_DATA_LOSS  (-52) //This value should be same as UCL_E_DATA_LOSS 

#define DMNMGR_STOP_SEC_CONST_8
#include "MemMap.h"


///
/// @brief Domain Health State definitions
///

typedef EDmnHealthState_t EDmnResetReason_t; 
///
/// @brief Domain Health State definitions
///

///
/// @brief Domain Thermal State definitions
///
typedef uint8	EThermalStatus_t;


///
/// @brief RunTime Counters to track the various error scenerios encountered.
///
/// The SDmnErrStats structure shall help in debugging undefined behaviours & interactions with other domain.
///
typedef struct
{
	uint16 linkUpbfrDownErrCnt;		///< Repeated LinkUp Scenerios. Received Link Up When the Link is already UP
	uint16 linkDownbfrUpErrCnt;		///< Repeated LinkDown Scenerios. Received Link Down When the Link is already Down
	sint32 invalidLinkStatus;		///< Received Invalid Link Status
	uint16 dmnFirstLinkUpExpiry;	///< A count of number of times the first Link Up not received before expected time.
	uint16 dmnFirstHBExpiry;		///< A count of number of times the first HB not received before expected time.
	uint16 RcvdInvalidSeqCnt;		///< A count of number of times Invalid sequence COunter is received
}SDmnErrStats;

///
/// @brief Collective Domain Running Status of each Managed Domain.
///
/// The SDmnRunTimeStatus structure defines the Link, System, Health & Thermal status of each Managed Domain.
///
typedef struct
{
    EDomainId dmnId;						///< Domain Id
		
	//UCL Related Configurations
	boolean isFirstLinkUpRcvd;				///< Verify if first LinkUp is received after ignition ON
	EUclLinkState_t dmnUclLinkState;		///< Current Domain Link Status
	sint32 dmnUclFatalErrorRcvd;				///< UCL Fatal Error Received
    
	//Domain System State Related Configuration
	ESystemState dmnCurSystemState;	///< Domain current System State
	ESystemState dmnReqSystemState;	///< Domain Requested System State
	EDmnChangeReqStatus_t dmnStateChangeReqStatus;///< The status of the State Change Requst >
	
	//Domain HB Related Configuration
	uint8 dmnHBMissCount;					///< Domain HB Miss Count
	uint32 dmnLastSeqCount;					///< Last received Sequence Counter of Domain HB Message 
	uint32 dmnHBLastRcvTime;				///< Domain HB Last Received Time
	
	// Various Domain States
	EDmnResetReason_t dmnLastRstReason;		///< Domain Last Reset reason received from health manager
	EDmnHealthState_t dmnHealthState;		///< Domain Health State. 
											///< If Heart Beat is received @Configured periodicity, domain health status is Active
											///< If heart beat miss exceeds configured HB miss count, domain health staus is HB_Miss
											///< If health fatal error is received, domain health staus is Fatal_Error
	#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
    UInt32 compldx;
	#endif
	EThermalStatus_t dmnThermalState;		///< Domain Thermal State
	EDmnOverallState_t dmnStatus;
	
	//Domain Manager Timing Configurations
	uint32 dmnExtendShutDownTimeMs;			///< Requested Extended Shutdown time in ms
	uint32 dmnKeepSystemAwakeMs;			///< Requested System Awake time in ms
	uint32 dmnShutDownWaitTime;				///< Updated Domain Shut Down wait time if dmnExtendShutDownTimeMs > 0
	uint32 dmnSystemAwakeWaitTime;			///< Updated Domain Awake wait time if dmnKeepSystemAwakeMs > 0;
	uint32 dmnUpWaitTime;					///< Time to wait for Link Up & First Heart beat from VIP	
	
	//Domain Manager Statistics
	SDmnErrStats ErrStatus;					///< Counters to track the various error scenerios encountered. 
											///< This element shall help in debugging undefined behaviours.
} SDmnRunTimeStatus;


#endif //DmnMgr_Common_h
