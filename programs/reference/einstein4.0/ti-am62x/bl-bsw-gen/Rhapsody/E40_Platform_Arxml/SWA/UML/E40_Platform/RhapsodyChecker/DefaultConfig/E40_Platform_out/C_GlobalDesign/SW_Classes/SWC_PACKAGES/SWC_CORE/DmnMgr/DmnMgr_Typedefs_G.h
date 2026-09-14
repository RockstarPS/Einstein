#ifndef __DmnMgr_Typedefs_G_h__
#define __DmnMgr_Typedefs_G_h__
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
// Generated on Fri Jul 26 12:05:15 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              DmnMgr (DesignUnit)
// Description:         None
// Owner:               SWC_CORE (Package)
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

// Enumeration type EDmnChangeReqStatus_t
#ifndef A2T_TypesProtection_EDmnChangeReqStatus_t
#define A2T_TypesProtection_EDmnChangeReqStatus_t
typedef enum {
    EDmnChangeReqStatus_NoReq = 0,
    EDmnChangeReqStatus_WaitAwakeTime = 1,
    EDmnChangeReqStatus_WaitShutdonwTime = 2,
    EDmnChangeReqStatus_PrevReqPending = 3,
    EDmnChangeReqStatus_ReqSucceed = 4,
    EDmnChangeReqStatus_ReqFail = 5,
    EDmnChangeReqStatus_ReqTimedOut = 6,
    EDmnChangeReqStatus_DmnNotReady = 7
} EDmnChangeReqStatus_t;
#define eEDmnChangeReqStatus_NoReq EDmnChangeReqStatus_NoReq
#define eEDmnChangeReqStatus_WaitAwakeTime EDmnChangeReqStatus_WaitAwakeTime
#define eEDmnChangeReqStatus_WaitShutdonwTime EDmnChangeReqStatus_WaitShutdonwTime
#define eEDmnChangeReqStatus_PrevReqPending EDmnChangeReqStatus_PrevReqPending
#define eEDmnChangeReqStatus_ReqSucceed EDmnChangeReqStatus_ReqSucceed
#define eEDmnChangeReqStatus_ReqFail EDmnChangeReqStatus_ReqFail
#define eEDmnChangeReqStatus_ReqTimedOut EDmnChangeReqStatus_ReqTimedOut
#define eEDmnChangeReqStatus_DmnNotReady EDmnChangeReqStatus_DmnNotReady
#define tEDmnChangeReqStatus_t EDmnChangeReqStatus_t
#endif

// Enumeration type EDmnOverallState_t
#ifndef A2T_TypesProtection_EDmnOverallState_t
#define A2T_TypesProtection_EDmnOverallState_t
typedef enum {
    DMN_NOT_READY = 0,
    DMN_READY = 1
} EDmnOverallState_t;
#define eDMN_NOT_READY DMN_NOT_READY
#define eDMN_READY DMN_READY
#define tEDmnOverallState_t EDmnOverallState_t
#endif

// Enumeration type EDmnHealthState_t
#ifndef A2T_TypesProtection_EDmnHealthState_t
#define A2T_TypesProtection_EDmnHealthState_t
typedef enum {
    EDmnHealth_Active = 0,
    EDmnHealth_UCL_Fatal_Error = 1,
    EDmnHealth_HB_Miss = 2,
    EDmnHealth_Fatal_Error = 3,
    EDmnHealth_Rcvd_Inv_SeqCnt = 4,
    EDmnHealth_First_HB_Rcv_Time_Expired = 5,
    EDmnHealth_First_LinkUp_Time_Expired = 6,
    EDmnHealth_Shutdown_Time_Expired = 7,
    EDmnHealth_Last = 8
} EDmnHealthState_t;
#define eEDmnHealth_Active EDmnHealth_Active
#define eEDmnHealth_UCL_Fatal_Error EDmnHealth_UCL_Fatal_Error
#define eEDmnHealth_HB_Miss EDmnHealth_HB_Miss
#define eEDmnHealth_Fatal_Error EDmnHealth_Fatal_Error
#define eEDmnHealth_Rcvd_Inv_SeqCnt EDmnHealth_Rcvd_Inv_SeqCnt
#define eEDmnHealth_First_HB_Rcv_Time_Expired EDmnHealth_First_HB_Rcv_Time_Expired
#define eEDmnHealth_First_LinkUp_Time_Expired EDmnHealth_First_LinkUp_Time_Expired
#define eEDmnHealth_Shutdown_Time_Expired EDmnHealth_Shutdown_Time_Expired
#define eEDmnHealth_Last EDmnHealth_Last
#define tEDmnHealthState_t EDmnHealthState_t
#endif

// Enumeration type EUclLinkState_t
#ifndef A2T_TypesProtection_EUclLinkState_t
#define A2T_TypesProtection_EUclLinkState_t
typedef enum {
    EUclLinkState_Not_Rcvd = 0,
    EUclLinkState_Down = 1,
    EUclLinkState_Up = 2,
    EUclLinkState_Last = 3
} EUclLinkState_t;
#define eEUclLinkState_Not_Rcvd EUclLinkState_Not_Rcvd
#define eEUclLinkState_Down EUclLinkState_Down
#define eEUclLinkState_Up EUclLinkState_Up
#define eEUclLinkState_Last EUclLinkState_Last
#define tEUclLinkState_t EUclLinkState_t
#endif

// Structure type SDmnRTCData
#ifndef A2T_TypesProtection_SDmnRTCData
#define A2T_TypesProtection_SDmnRTCData
typedef struct _SDmnRTCData_tag {
    uint16 DmnRTCYear;
    uint8 DmnRTCMonth;
    uint8 DmnRTCDay;
    uint8 DmnRTCHour;
    uint8 DmnRTCMin;
    uint8 DmnRTCSec;
} SDmnRTCData;
#define tSDmnRTCData SDmnRTCData
#endif

// Structure type SDmnStatus
#ifndef A2T_TypesProtection_SDmnStatus
#define A2T_TypesProtection_SDmnStatus
typedef struct _SDmnStatus_tag {
    EDomainId dmnId;
    EUclLinkState_t linkStatus;
    sint32 uclErrCode;
    EDmnHealthState_t dmnHealthState;
    ESystemState state;
    EDmnOverallState_t dmnStatus;
} SDmnStatus;
#define tSDmnStatus SDmnStatus
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __DmnMgr_Typedefs_G_h__
