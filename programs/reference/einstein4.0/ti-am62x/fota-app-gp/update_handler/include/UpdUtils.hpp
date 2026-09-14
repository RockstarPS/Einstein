//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
//=============================================================================
// @file        UpdUtils.hpp
// @brief       
//
//---------------------------------------------------------------------------------------------------------------------

#ifndef __UPD_UTILS_HPP__
#define __UPD_UTILS_HPP__

#include <string>
#include <cstdint>

#define UPD_DEFAULT_FILE_EXTN		"raw"
#define UPD_LIB_VERSION				"v00.05.70"
#define UPD_STATUS_CHECK_DELAY		100


namespace Visteon
{
namespace Update
{

std::string getTargetFileName(const std::string& targetName, const std::string& fileName);

std::string bytesToHexString(const uint8_t* bytes, size_t len);

bool hexStringToBytes(const std::string& hashString, uint8_t* hashBytes);

bool cstrcpy(char* dest, const char* source, int32_t dest_size, int32_t src_len = -1);

} // namespace Visteon
} // namespace Update

#endif //__UPD_UTILS_HPP__
