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

#include <cstdint>
#include <vector>

namespace SwcDiagGP
{
    enum E_RESULT : uint8_t
    {
        E_OK = 0U,
        E_NOT_OK = 1U,
        E_PENDING = 2U,

        E_TYPESCOUNT
    };

    enum BANDWIDTHS : uint8_t
    {
        BANDWIDTHS_20 = 0U,
        BANDWIDTHS_40 = 1U,
        BANDWIDTHS_60 = 2U,
        BANDWIDTHS_80 = 3U,
        BANDWIDTHS_100 = 4U,

        BANDWIDTHS_Count
    };

    enum TARGET_SIGNAL : uint8_t
    {
        eMMC = 0x00U,
        NOR = 0x01U,
        EEPROM = 0x02U,
        DDR4 = 0x03U,
        LVDS = 0x04U
    };

    enum SUB_FUNCTION : uint8_t
    {
        subfunction_0 = 0x00U,
        subfunction_1 = 0x01U,
        subfunction_2 = 0x02U,
        subfunction_3 = 0x03U,
        subfunction_4 = 0x04U
    };

    constexpr uint8_t INVALID_ETHERNET_LOAD = 0xFFU;

    enum PERCENTS : uint8_t
    {
        PERCENT_20 = 0U,
        PERCENT_50 = 1U,
        PERCENT_100 = 2U,

        Percentage_Count
    };

    enum class RequestSource
    {
        RequestSource_VIP = 0U,
        RequestSource_GIP = 1U
    };

    struct DiagMessage
    {
        uint8_t service;
        uint16_t DID;
        uint8_t responseCode;
        uint8_t controlOpLen;
        uint8_t subFunction;
        std::vector<uint8_t> DataBuffer;
        RequestSource requestSource;
    };
    
    inline bool operator==(const DiagMessage& lhs, const DiagMessage& rhs)
    {
        return ((lhs.service == rhs.service) &&
               (lhs.DID == rhs.DID) &&
               (lhs.subFunction == rhs.subFunction) &&
               (lhs.responseCode == rhs.responseCode) &&
               (lhs.DataBuffer == rhs.DataBuffer) &&
               (lhs.requestSource == rhs.requestSource));
    }
    
    typedef float float32_t;
    typedef double float64_t;
}