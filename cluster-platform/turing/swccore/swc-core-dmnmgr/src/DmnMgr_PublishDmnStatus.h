//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
/// @file DmnMgr_PublishDmnStatus.h
/// @ingroup PublishDmnStatus
/// @brief Domain Manager Implementation to Publish Domain Status.
/// 1. UCL Link Status
/// 2. UCL Fatal Error
/// 2. Domain Health Status
/// 3. Domain System State
/// 4. Domain Thermal Status ///
//---------------------------------------------------------------------------------------------------------------------

#ifndef DmnMgr_PublishDmnStatus_h
#define DmnMgr_PublishDmnStatus_h "DmnMgr_PublishDmnStatus.h"

#include "DmnMgr_Common.h"
#include "DmnMgr_Main.h"

#if 0
///
/// @brief Publish Domain Status to other SWCs.
///
/// The SDmnInfo structure is used to Publish / Notify various Domain parameters to other SWCs 
typedef struct
{
    EDomainId dmnId;
    EUclLinkState_t linkStatus;
    sint32 uclErrCode;
    EDmnHealthState_t dmnHealthState;
    EDmnSystemState_t state;
	EDmnOverallState_t dmnStatus;
} SDmnInfo;
#endif


#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

Std_ReturnType DmnMgr_SetDmnInfo_dmnId(const EDomainId *pData);



///
/// @brief This method Publishes UCL Link Status Change to other SWCs
///
/// @param  dmnId - Domain to which state change is requested
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_PublishUclLinkStatus(EDomainId dmnId);

///
/// @brief This method Publishes UCL Fatal Error to other SWCs
///
/// @param  dmnId - Domain to which state change is requested
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_PublishUclFatatError(EDomainId dmnId);

///
/// @brief This method Publishes Domains System State Change to other SWCs
///
/// @param  dmnId - Domain to which state change is requested
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_PublishDmnSystemState(EDomainId dmnId);

///
/// @brief This method Publishes Domains Health Status to other SWCs
///		The Health status include HB Miss & Health Fatal Error	
/// @param  dmnId - Domain to which state change is requested
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_PublishDmnHealthStaus(EDomainId dmnId);

///
/// @brief This method Publishes Domain Thermal State to other SWCs
///
/// @param  dmnId - Domain to which state change is requested
///
/// @return DmnMgr_ReturnType
///
DmnMgr_ReturnType DmnMgr_PublishDmnThermalState(EDomainId dmnId);

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

#endif //DmnMgr_PublishDmnStatus_h
