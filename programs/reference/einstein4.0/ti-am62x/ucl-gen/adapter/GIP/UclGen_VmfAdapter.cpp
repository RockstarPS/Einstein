//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//
// File generated automatically using Visteon DiCore UCL configuration generator 1.3.3
// Date: Wed Sep 17 12:27:28 IST 2025
// User: SSRINI28
// Gateway: UCL_GW
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------

#include <map>
#include <set>
#include <vector>
#include <Ucl_Types.h>
#include <UclGen_VmfAdapter.hpp>
#include <UclGen_VmfAdapterIds.h>
#include <UclVmfConfig.hpp>

//---------------------------------------------------------------------------------------
// Create an array with Group Ids for all transmit messages, without repetition
//---------------------------------------------------------------------------------------
static const std::set<uint8> TxMessagesGxSet({
    {Gx_PowerSystemState_Tx},
    {Gx_PowerExtendShutdownTime_Tx},
    {Gx_PowerKeepSystemAwake_Tx},
    {Gx_HealthDomainHeartbeat_Tx},
    {Gx_HealthDomainFatalError_Tx},
    {Gx_HealthEventRecord_Tx},
    {Gx_HealthDumpHdrInfo_Tx},
    {Gx_HealthDumpData_Tx},
    {Gx_DisplayCurrentState_Tx},
    {Gx_EmmcErrorNotifier_Tx},
    {Gx_WarningDisplayAvailable_Tx},
    {Gx_WarningStatus_Tx},
    {Gx_SafeHMIReadyStatus_Tx},
    {Gx_MainHMIReadyStatus_Tx},
    {Gx_UpdateShortServiceResp_Tx},
    {Gx_DiagResponse_Tx},
    {Gx_DLTMessageReadAck_Tx},
    {Gx_DLTControlMessageRequest_Tx}
});
static const std::vector<uint8> TxMessagesGxVector(TxMessagesGxSet.begin(), TxMessagesGxSet.end());
uint8 const * const UclGen_GxList = &TxMessagesGxVector[0];    // Group ID list
const uint16 UclGen_GxListLength = static_cast <uint16> (TxMessagesGxVector.size());    // Size of Group ID list


//---------------------------------------------------------------------------------------
// Group / Event Ids mapping to transmit DB indexes
//---------------------------------------------------------------------------------------
const std::pair<std::pair<uint8, uint8>, std::pair<uint8, uint8>> UclGen_GxExToDbIdxTable[UclGen_GxExToDbIdxTableLength] =
{
    //                               Gx        Ex                     TxDbIdx   DuIdx
    std::make_pair( std::make_pair( Gx_PowerSystemState_Tx, Ex_PowerSystemState_Tx), std::make_pair( 0U, 0U)),
    std::make_pair( std::make_pair( Gx_PowerExtendShutdownTime_Tx, Ex_PowerExtendShutdownTime_Tx), std::make_pair( 1U, 0U)),
    std::make_pair( std::make_pair( Gx_PowerKeepSystemAwake_Tx, Ex_PowerKeepSystemAwake_Tx), std::make_pair( 1U, 1U)),
    std::make_pair( std::make_pair( Gx_HealthDomainHeartbeat_Tx, Ex_HealthDomainHeartbeat_Tx), std::make_pair( 2U, 0U)),
    std::make_pair( std::make_pair( Gx_HealthDomainFatalError_Tx, Ex_HealthDomainFatalError_Tx), std::make_pair( 3U, 0U)),
    std::make_pair( std::make_pair( Gx_HealthEventRecord_Tx, Ex_HealthEventRecord_Tx), std::make_pair( 4U, 0U)),
    std::make_pair( std::make_pair( Gx_HealthDumpHdrInfo_Tx, Ex_HealthDumpHdrInfo_Tx), std::make_pair( 5U, 0U)),
    std::make_pair( std::make_pair( Gx_HealthDumpData_Tx, Ex_HealthDumpData_Tx), std::make_pair( 5U, 1U)),
    std::make_pair( std::make_pair( Gx_DisplayCurrentState_Tx, Ex_DisplayCurrentState_Tx), std::make_pair( 6U, 0U)),
    std::make_pair( std::make_pair( Gx_EmmcErrorNotifier_Tx, Ex_EmmcErrorNotifier_Tx), std::make_pair( 7U, 0U)),
    std::make_pair( std::make_pair( Gx_WarningDisplayAvailable_Tx, Ex_WarningDisplayAvailable_Tx), std::make_pair( 8U, 0U)),
    std::make_pair( std::make_pair( Gx_WarningStatus_Tx, Ex_WarningStatus_Tx), std::make_pair( 8U, 1U)),
    std::make_pair( std::make_pair( Gx_SafeHMIReadyStatus_Tx, Ex_SafeHMIReadyStatus_Tx), std::make_pair( 9U, 0U)),
    std::make_pair( std::make_pair( Gx_MainHMIReadyStatus_Tx, Ex_MainHMIReadyStatus_Tx), std::make_pair( 9U, 1U)),
    std::make_pair( std::make_pair( Gx_UpdateShortServiceResp_Tx, Ex_UpdateShortServiceResp_Tx), std::make_pair( 10U, 0U)),
    std::make_pair( std::make_pair( Gx_DiagResponse_Tx, Ex_DiagResponse_Tx), std::make_pair( 11U, 0U)),
    std::make_pair( std::make_pair( Gx_DLTMessageReadAck_Tx, Ex_DLTMessageReadAck_Tx), std::make_pair( 12U, 0U)),
    std::make_pair( std::make_pair( Gx_DLTControlMessageRequest_Tx, Ex_DLTControlMessageRequest_Tx), std::make_pair( 13U, 0U))
};

std::map<std::pair<uint8, uint8>, std::pair<uint8, uint8>> CUclVmfConfig::VmfLookupTable( UclGen_GxExToDbIdxTable,
                &UclGen_GxExToDbIdxTable[UclGen_GxExToDbIdxTableLength] );

Ucl_ReturnType CUclVmfConfig::getVmfGroupList( const uint8 **const GxList, uint16 &NumGroups )
{
    *GxList = UclGen_GxList;
    NumGroups = UclGen_GxListLength;
    return UCL_E_OK;
}

Ucl_ReturnType CUclVmfConfig::lookup( const std::pair<uint8, uint8> GxEx, std::pair<uint8, uint8> &IdxDux )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if (VmfLookupTable.find( GxEx ) != VmfLookupTable.end())
    {
        IdxDux = VmfLookupTable[GxEx];
        Ret = UCL_E_OK;
    }
    return Ret;
}

