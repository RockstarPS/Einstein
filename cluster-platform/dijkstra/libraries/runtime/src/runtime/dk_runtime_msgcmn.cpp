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

#include "dk_runtime_msgcmn.h"

namespace dk
{
namespace runtime
{
namespace core
{

std::map<mid_t, func_t> createMap ( uint16_t size, const MsgCmn *msgList )
{
    std::map<mid_t, func_t> map;

    for ( uint16_t i = 0U; i < size; i++ )
    {
        map[msgList[i].msgId] = msgList[i].func;
    }

    return map;
}
}
}
}
