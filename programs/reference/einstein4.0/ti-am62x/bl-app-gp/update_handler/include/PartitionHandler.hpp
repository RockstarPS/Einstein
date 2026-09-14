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

#ifndef PARTITIONHANDLER_COMPONENT_H
#define PARTITIONHANDLER_COMPONENT_H

#include <stdint.h>
#include <string.h>
#include <thread>
#include "Std_Types.h"
#include "dk_logger.h"

typedef struct
{
	uint8 PartId;
	std::string Name;
	std::string Destination;
	std::string Source;
	uint8 DevTyp;
	uint32 Size;
	uint8 PrimaryUpdateStatus;
}PartitionInfo_Type;

class PartitionHandler
{
    public:
        uint8 FlashBinary(const std::string& Destination,const std::string& Source, uint32_t DevTyp);
        uint8 RecoveryPartitionSync(boolean *SyncStatus);
		uint8 UpdatePartitionStatus(uint8 swPartId, uint8 SwPartStatus);
		uint8 SetPartitionStatus(uint8 swPartId, uint8 activePart, uint8 SwPartStatus);
		uint8 GetPartitionStatus(uint8 swPartId, uint8 activePart, uint8* SwPartStatus);
		uint8 UpdatePartitionVersion(uint8 swPartId);
		uint8 SetPartitionVersion(uint8 swPartId, uint8 activePart);
		uint8 GetPartitionVersion(uint8 swPartId, uint8 activePart, uint8* SwVersion);
		uint8 ApplicationPartitionSync(boolean *SyncStatus);
		uint8 PartitionCopy(uint8 partid, uint8 ActivePart);
		uint8 PreResetRoutine(void);
		uint8 PartitionValidityCheck(uint8 activePart);
		uint8 GetblockIndex(uint32 BlockAdderss, uint32 BlockLength, uint8* blockindex);
		uint8 Erase(std::string PackageName);
    private:
};
#endif