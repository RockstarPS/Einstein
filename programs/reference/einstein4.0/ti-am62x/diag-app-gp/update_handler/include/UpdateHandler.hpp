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

#ifndef UPDATE_HANDLER_H
#define UPDATE_HANDLER_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "Std_Types.h"

typedef enum
{
	EDeviceType_NOR = 0,
	EDeviceType_EMMC
}DeviceType;

typedef struct
{
	uint32 StartAddress;
	uint32 EndAddress;
	std :: string PkgName;
}MemoryConfigType;

typedef struct
{
	uint8 CompressionCode;
	std :: string CompressionType;
}DataCompressionType;

class UpdateHandler
{
public:
    virtual ~UpdateHandler()
    {
    }
    uint8 ProgSession();
    uint8 Reset();
	uint8 EraseRoutine(uint32 blkAddress, uint32 blkLength);
	uint8 RequestDownload(uint32 blkAddress, uint32 blkLength, uint8 mode);
	uint8 TransferData(uint32 length, uint8 *DataPtr);
	uint8 TransferExit();
	uint8 SignatureVerification(uint32 blkAddress, uint32 blkLength, uint8 *SignaturePtr, uint32 SignatureLength);
	uint8 Activation();
	uint8 RecoveryPartitionSynchronization(uint8 *SyncStatus);
	uint8 PrimaryPartitionSynchronization(uint8 *SyncStatus);
	uint8 GetblockIndex(uint32 BlockAdderss, uint32 BlockLength, uint8* blockindex);
/// End of user code
};



#endif //UPD_UCL_ADAPTER_COMPONENT_H

