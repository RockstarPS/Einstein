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
// Date: Tue Oct 01 15:54:36 IST 2024
// User: KRAMESH5
// Gateway: UCL_GW
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.2
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
    {Gx_UpdateShortServiceResp_Tx}
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
    std::make_pair( std::make_pair( Gx_UpdateShortServiceResp_Tx, Ex_UpdateShortServiceResp_Tx), std::make_pair( 0U, 0U))
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

