//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
#ifndef UCLVMFINTERFACE_HPP
#define UCLVMFINTERFACE_HPP
#pragma once

#include "Ucl_Types.h"
extern "C" {
#include "nw_os_config.h"
#include "nw_vmf.h"
}

class CUclVmfInterface
{
  public:
    typedef struct SVmfMsg_t
    {
        uint8 Gx;
        uint8 Ex;
        uint8 Payload[MAX_VMF_DATA_LEN];
        uint16 PayloadSize;
    } SVmfMsg;

    CUclVmfInterface();
    ~CUclVmfInterface();
    Ucl_ReturnType connectToVmf( const uint8 *const groupsListPtr, const uint16 numGroups );
    Ucl_ReturnType sendToVmf( const SVmfMsg * const vmfMsgPtr ) const;
    Ucl_ReturnType receiveFromVmf( SVmfMsg * const vmfMsgPtr ) const;
	Ucl_ReturnType disConnectFromVmf(const uint8 *const groupsListPtr, const uint16 numGroups) const;
  private:
    vmf_client_id_t vmfConnId;
};

#endif //UCLVMFINTERFACE_HPP
