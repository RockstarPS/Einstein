//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
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

#pragma once

#include "StdDiagTypes.hpp"

#include <linux/input.h>

namespace SwcDiagGP
{
    class ISystemCalls
    {
    public:
        virtual ~ISystemCalls() noexcept = default;

        virtual int32_t openTouchDevice() = 0;
        virtual void closeTouchDevice(int32_t fd) = 0;
        virtual ssize_t readTouchDevice(const int32_t fd, input_event *buf, const size_t nbytes) = 0;
        virtual E_RESULT writeMagicFlag() = 0;
        virtual void sysReboot() = 0;
    };
}