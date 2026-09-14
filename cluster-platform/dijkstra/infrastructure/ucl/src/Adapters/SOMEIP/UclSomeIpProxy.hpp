///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLSOMEIPPROXY_HPP
#define UCLSOMEIPPROXY_HPP
#pragma once


#include <iostream>
#include <vector>
#include <unistd.h>
#include <Ucl_Types.h>
#include <vsomeip/vsomeip.hpp>


class CUclSomeIpProxy
{
  public:

    CUclSomeIpProxy();
    ~CUclSomeIpProxy();
    Ucl_ReturnType start();
    Ucl_ReturnType stop();

    static CUclSomeIpProxy &getInstance()
    {
        static CUclSomeIpProxy inst;
        return inst;
    }
    Ucl_ReturnType addSomeIpToTxQueue(uint16  Sx, uint16 Ex, uint8 *Payload, uint16 Size);

  private:
    bool bRequestExit;
    std::shared_ptr<vsomeip::application> UclAppReg;
    uint8 UclServiceRegSucessful;
};

uint8 UclSomeIpProxy_AddSomeIpMsgToTxQueue( uint16 Sx, uint16 Ex, uint8 *pPayload, uint16 Size );

#endif //CUclSomeIpProxy
