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
/// @file DmnMgr_ControlDmn.h
/// @ingroup CtrlDmn
/// @brief Domain Manager Implementation to perform Domain Control Operations.
/// 1. Save Health Report
/// 2. Initiate Domain Reset
/// 3. Request Domain State Change
/// 4. Get RTC Data and publish to all connected domains ///
//---------------------------------------------------------------------------------------------------------------------
#ifndef DmnMgr_ControlDmn_h
#define DmnMgr_ControlDmn_h "DmnMgr_ControlDmn.h"

#include "DmnMgr_Common.h"

#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"
///
/// @brief This method implements the Domain reset request to mode manager
///
/// @param dmnId
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_DmnCtrlResetDmn(EDomainId dmnId, uint16 FaultID);

#ifdef HEALTHLOGGING_ENABLE
void DmnMgr_ControlDmnSaveHealthReport(EDomainId DmnID, EDmnHealthState_t dmnHealthState);
#endif

///
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Periodic Function to collect RTC Data from CAN
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_DmnCtrlReqRTCData(void);/*3.3-4*/

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

Std_ReturnType DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState);               // this was declared to fix the MISRA warnings
void DmnMgr_DmnSystemStateChangeStatus(EDomainId DmnId, EDmnChangeReqStatus_t *DmnStatus);           // this was declared to fix the MISRA warnings
Std_ReturnType DmnMgr_StartDomainMonitoring(EDomainId DmnID);                                        // this was declared to fix the MISRA warnings   
Std_ReturnType DmnMgr_StopDomainMonitoring(EDomainId DmnID);                                         // this was declared to fix the MISRA warnings   

#endif //DmnMgr_ControlDmn_h
