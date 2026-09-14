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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Thu Feb 29 13:30:55 IST 2024
// User: KRAMESH5
// System: GIP
// Configuration: Platform_Recovery
// Project: EU_BMW_MIC
// Message Catalogue version : 1.0.3
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef BL_FLAHSHHANDLER_COMPONENT_H
#define BL_FLAHSHHANDLER_COMPONENT_H

#include <stdint.h>
#include <string.h>
#include <thread>
#include <map>
#include "Std_Types.h"
#include "dk_logger.h"

class FlashHandler
{
    public:
        int32_t programEmmcPartition(std::string partition, std::string file);
        int32_t programNORPartition(std::string partition, std::string file);
        int32_t programCompEmmcPartition(std::string partition, std::string file);
		uint8_t NorErase(std::string PackagePath);
		uint8_t EMMCErase(std::string PackagePath, uint32_t size);
    private:
};
#endif