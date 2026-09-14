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
#ifndef UCLSOMEIPCONFIG_HPP
#define UCLSOMEIPCONFIG_HPP
#pragma once

#include <map>
#include <set>
#include <vector>
#include <vsomeip/vsomeip.hpp>
#include "Ucl_Types.h"

typedef void (*Func)(const std::shared_ptr<vsomeip::message> &_request);

class CUclSomeIPConfig
{
  public:
    static Ucl_ReturnType getServiceIdGroupList( const uint16 **serviceList, uint16 &numServiceIds );
    static Ucl_ReturnType lookupSxtoExTxTable( uint16 Sx, std::vector<std::pair<uint16, Func>> &methodRegHandler );
    static Ucl_ReturnType lookupSxtoExRxTable( uint16 Sx, std::vector<std::pair<uint16, uint16>> &methodEventGrouplist );

  private:
    static std::map<uint16,std::vector<std::pair<uint16,uint16>>> UclGen_SxtoExRxTable;
    static std::map<uint16,std::vector<std::pair<uint16,Func>>> UclGen_SxtoExTxTable;
};

#endif //UCLSOMEIPCONFIG_HPP
