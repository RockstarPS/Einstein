///---------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------
/// 
/// @file DmnMgr_MonitorDmn.h
/// @ingroup MntrDmnStatus
/// @brief Domain Manager Implementation to perform Domain Monitoring Operations.
/// 1. Monitor Domain Heartbeat
/// 2. Monitor Domain Health Fatal Error
/// 3. Monitor Domain System State
/// 4. Monitor UCL Link Status
/// 5. Monitor UCL Fatal Error
/// 6. Monitor Domain Thermal Status ///
//---------------------------------------------------------------------------------------------------------------------//---------------------------------------------------------------------------------------------------------------------

#ifndef DmnMgr_MonitorDmn_h
#define DmnMgr_MonitorDmn_h "DmnMgr_MonitorDmn.h"

#include "DmnMgr_Common.h"
#include "Rte_DmnMgr.h"
#include "Rte_DmnMgr_stubs.h"

#define DMNMGR_START_SEC_CODE_ASIL_B

#include "MemMap.h"
///
/// @brief Reset the Domain Status for specific Domain, and publish the SR port information
///
/// @param  dmnId Domain Id
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_ResetDmnRunTimeStatus(EDomainId dmnId);

///
/// @brief This method Gets RunTime Domain Status
///
/// @param  dmnId Domain Id
/// @param  pDmnSts Pointer the RunTime Status of Domain dmnId
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_GetDmnRunTimeStatus(EDomainId dmnId, SDmnRunTimeStatus **pDmnSts);


void DmnMgr_ConsolidatedDmnStatus(EDomainId dmnId);

#ifdef DMNMGR_MULTIDOMIANS_ENABLE
void DmnMgr_Domainsystemstate(SPowerSystemState *systemstates);
#endif


#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

void DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode);              // this was declared to fix the MISRA warnings
void DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status);                 // this was declared to fix the MISRA warnings

#endif //DmnMgr_MonitorDmn_h
