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

#ifndef DmnMgr_Cfg_h
#define DmnMgr_Cfg_h "DmnMgr_Cfg.h"

#include "Std_Types.h"
#include "Rte_DmnMgr.h"
#include "Os.h"
#include "FltM.h"
#include "vHsmShutdownMgr.h"
#include "Cdd_IpcCfg.h"

#define DMNMGR_MEMSECTION_MAP

#define MANAGED_DOMAINS_CNT				(4u)
#define DMNMGR_MULTIDOMIANS_ENABLE
#define DMNMGR_MEET_SYSTEM_REQUEST

#define DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN

#define DMNMGR_CORE_SHUTDOWN_FAILSAFE_TIME 1200u

#define DMNMGR_TASK_PERIOD_MS			(10u)	///< The periodicity at which Domain Manager Main fucntion is scheduled to run
#define DMNMGR_TASK_PERIOD_PROGRAMSPECIFIC
#define DMNMGR_RTCDATA_NOTNEEDED

#define DMNMGR_FAILSAFESTATE_E4PLATFORM

#define DMNMGR_DM_IPC_SENDMSG               Cdd_IpcSendMsg
#define DMNMGR_HSM_SENDMSG                  HSM_DmnMgr_SystemChangeRequest

#ifndef STD_TYPES_H
#define STD_TYPES_H
#endif

// Unique Fault IDs for Domain Manager Reset and error
#define DMNMGR_GIP_FISRTHB_MISS                       FLTM_E_DMNMGR_GIP_FIRSTHB_MISS
#define DMNMGR_GIP_HB_MISS                            FLTM_E_DMNMGR_GIP_HB_MISS
#define DMNMGR_GIP_LINKUP_FAILED                      FLTM_E_DMNMGR_GIP_LINKUP_FAILED
#define DMNMGR_GIP_HEALTH_FATAL_ERROR                 FLTM_E_DMNMGR_GIP_HEALTH_FATAL_ERROR

///
/// @brief Static Configuration data for Domain Manager.
///
/// The SDmnMgrCfg structure defines the static configuration data for Domain Manager.
///
typedef struct
{
	EDomainId dmnId;						///< Domain Id
	uint16 dmnHBRcvPeriodicityMs;		///< The Periodicity at which HB Msgs from Domain is expected.
	uint8 dmnHBMissCount;				///< Acceptable HB Miss Count before DM initiate GIP Reset.
	uint16 dmnTimeForFirstHBMs;			///< Maximum time to wait for first HB from Domain.
	uint16 dmnTimeForFullRunMs;			///< Maximum time to wait for System State to transition into Full Run.
	uint16 dmnSeqCntrDeviation;			///< Allowed deviation between successive Sequence Counter values from domains.
	uint16 dmnTimeForUclLinkUp;			///< Maximum time to wait for UCL Link Up.
	uint16 dmnTimeForShutdown;			///< Maximum time after the shutdown sent to UCL
	uint32 dmnTimeforCoreShutdown;		///< Maximum wait time after the shutdown sent to Cores
} SDmnMgrUsrCfgList;

typedef struct
{
	uint8 dmnCnt;
	const SDmnMgrUsrCfgList *pDmnMgrCfgList;
}SDmnMgrUsrCfg;
#define DMNMGR_TIMER_IDLE                  (uint8)0xFF
typedef struct
{
    uint16 CurrentTime;
} DmnMgr_TimerType;

extern SDmnMgrUsrCfg * DmnMgr_UserConfigurations(void); 

extern void DmnMgr_ReportGipHealthError(uint16 FaultID);

#define DMNMGR_GET_SYSTEM_TIMER(Value) 			(void)GetCounterValue(SystemTimer,(Value))

extern Std_ReturnType CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP);
#define Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand CUclProxyCdd_Impl_OnCommand

// #define DMNMGR_FAILSAFESTATE_ECURESET_FUSA
//#define DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
//define DMNMGR_MCUEXTPERFORMRESET

#endif //DmnMgr_Cfg_h

/* 
#-------------------------------------------------------------------------------------------------------------------
#    Date    |    User   |       Task        |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 16/02/2024 |  MYALLA   | JLR3C29298-225822 | Health Management(V1)-Domain Manager Functional Testing & Delivery
*/