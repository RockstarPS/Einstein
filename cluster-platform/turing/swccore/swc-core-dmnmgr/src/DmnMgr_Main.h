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
/// 
/// @file DmnMgr_Main.h
/// @ingroup MntrDmn
/// @brief Domain Manager Implementation of BSW Main Function.
/// 1. Handling of Domain Manager Life Cycle Calls
/// 2. Timer Implementation of Domain UP time detection & Recovery
/// 3. Timer Implementation of System State Change detection & Recovery
/// 4. Timer Implementation of Keep Domain wake for configured time
/// 5. Timer Implementation of extended shutdown time verification
/// 6. Analyze the Domain Status parameters and invoke the recovery mechanism  
/// 7. Detection of Domain Heart Beat Miss 
/// 8. Verification of Domain Sequence Counter values in Heart Beat message for possible GIP only reset ///
//---------------------------------------------------------------------------------------------------------------------//---------------------------------------------------------------------------------------------------------------------

#ifndef DmnMgr_Main_h
#define DmnMgr_Main_h "DmnMgr_Main.h"

#include "DmnMgr_Cfg.h"
#include "DmnMgr_Common.h"
#include "DmnMgr_MonitorDmn.h"
#include "DmnMgr_ControlDmn.h"
#include "Rte_DmnMgr_stubs.h"

typedef struct{
	uint32 elapsedTicks;					///< No of times BSW Main task is schedule
	uint32 systemUpTime;					///< System time at First Domain Manager Schedule
	uint32 systemUpNow;						///< System current time
}SCmnDmnStatus;

#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

uint32 DmnMgr_MainGetElapsedTicks( void );
DmnMgr_ReturnType DmnMgr_MainGetDmnUsrCfg( EDomainId dmnId, const SDmnMgrUsrCfgList **pCfg );

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"


#endif //DmnMgr_Main_h
