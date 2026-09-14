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

#include "UpdateHandler.hpp"
#include "UpdLocalUpdater.hpp"
#include "PartitionHandler.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <condition_variable>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
/// Start of user code : Header user code for file upd_ucl_adapter_component.cpp
#include "SharedMem.h"
extern "C" {
    #include "metadata.h"
	#include "UPDd.h"
    #include "SecurestorageCrypto_ca.h"
}

PartitionHandler ObjPartitionHandler;

LOG_IMPORT_CONTEXT(BlAppGpLogContext);

/// End of user code
using namespace Visteon::Update;

UpdLocalUpdater oUpdLocalUpdater("UpdateCdd");

static uint8_t encrypt_flag = 0;

#define BLOCK_SIZE_SIG 		(4096)
#define RSA_3K 3

MemoryConfigType MemoryConfig[MEMORY_CONFIGURATION_SIZE] = {
	{0x00000000, 0x000FFFFF, "SBL"				},
	{0x00100000, 0x001FFFFF, "SBLRECOVERY"		},
	{0x00200000, 0x0021FFFF, "HSM"				},
	{0x00220000, 0x0023FFFF, "HSMRECOVERY"		},
	{0x00240000, 0x0027FFFF, "BL"				},
	{0x00280000, 0x0067FFFF, "MCU"				},
	{0x00680000, 0x0167FFFF, "KERNEL"			},
	{0x01680000, 0x0267FFFF, "KERNELRECOVERY"	},
	{0x02680000, 0x2267FFFF, "ROOTFS"			},
	{0x22680000, 0x4267FFFF, "ROOTFSRECOVERY"	},
	{0x42680000, 0x4667FFFF, "SYSTEM"			},
	{0x46680000, 0x4E67FFFF, "APP"				},
	{0x4E680000, 0x4F67FFFF, "ASSET"			}
};

DataCompressionType DataCompression[NUM_OF_COMPRESSION_AVAILABLE] = {
	{0x00, ".raw"          },
	{0x01, ".raw.aes128"   },
	{0x10, ".raw.x2"       },
	{0x30, ".dt.x2"        },
	{0x11, ".raw.x2.aes128"},
	{0x31, ".dt.x2.aes128" }
};
uint8 CurrentDownloadPart = 0u;
uint32 END_OFFSET,START_OFFSET;
struct TEE_resource_ctx ctx;
uint8_t signature_pu8[SIZE_OF_3k_MODULUS_BYTES];
ts_pointerType signature_S;
uint8_t partition=0xFF;
uint8_t ChangedPartition=0xFF;
SSwPartitionInfo_t partinfo,AppAinfo,AppBinfo,partKernelA,partKernelB;

uint8 UpdateHandler::ProgSession()
{
	int32_t	MetaDataStatus = eUPD_NotOk;

	uint8 status = E_NOT_OK;

	MetaDataStatus = Metadata_SetBootStatusFlag(EBootStatus_Bootloader);

	if(MetaDataStatus == E_OK)
	{
		status = E_OK;
	}

	return status;
}

uint8 UpdateHandler::Reset()
{
	return ObjPartitionHandler.PreResetRoutine();
}

uint8 UpdateHandler::EraseRoutine(uint32 blkAddress, uint32 blkLength)
{
	uint8 BlockIterator = 0u;
	uint8 status = E_NOT_OK;

	if(GetblockIndex(blkAddress, blkLength, &BlockIterator) == eUPD_Ok)
	{
		status = ObjPartitionHandler.Erase(MemoryConfig[BlockIterator].PkgName);

		if(status == E_OK)
		{
			CurrentDownloadPart = BlockIterator;

			status = ObjPartitionHandler.UpdatePartitionStatus(CurrentDownloadPart, ESwPartitionSts_Erased);
		}
	}

	return status;
}

uint8 UpdateHandler::RequestDownload(uint32 blkAddress, uint32 blkLength, uint8 mode)
{
	uint8 CompressionTypeIterator = 0u;
	uint8 BlockIterator = 0u;
	std :: string PackageName;
	uint8 status = E_NOT_OK;

	for(CompressionTypeIterator = 0u; CompressionTypeIterator < NUM_OF_COMPRESSION_AVAILABLE; CompressionTypeIterator++)
	{
		if( mode == DataCompression[CompressionTypeIterator].CompressionCode)
		{
			break;
		}
	}

	if(CompressionTypeIterator < NUM_OF_COMPRESSION_AVAILABLE)
	{
		if(GetblockIndex(blkAddress, blkLength, &BlockIterator) == eUPD_Ok)
		{
			PackageName = MemoryConfig[BlockIterator].PkgName;

			PackageName.append(DataCompression[CompressionTypeIterator].CompressionType);

			LOGI(&BlAppGpLogContext,"\n Package Name = ",PackageName);

			prepare_tee_session_securestorage_crypto(&ctx1);

			status = oUpdLocalUpdater.uds_service34(PackageName, blkLength);
		}
	}

	return status;
}

uint8 UpdateHandler::TransferData(uint32 length, uint8 *DataPtr)
{
	uint8 status = E_NOT_OK;

	if(DataPtr != NULL)
	{
		status = oUpdLocalUpdater.uds_service36(length, DataPtr);
	}

	return status;
}

uint8 UpdateHandler::TransferExit()
{
	uint8 status = E_NOT_OK;

	terminate_tee_session_securestorage_crypto(&ctx1);

	status = oUpdLocalUpdater.uds_service37();

	if(status == E_OK)
	{
		status = ObjPartitionHandler.UpdatePartitionStatus(CurrentDownloadPart, ESwPartitionSts_Programmed);
	}

	return status;
}

uint8 UpdateHandler::SignatureVerification(uint32 blkAddress, uint32 blkLength, uint8 *SignaturePtr, uint32 SignatureLength)
{
	uint8 status = E_NOT_OK;
	uint8 BlockIterator = 0u;
	std :: string PackageName;
	uint8_t buffer[BLOCK_SIZE_SIG];
	uint16_t bytesRead;
	uint16_t bytesToRead;
	ts_pointerType buffer_s;
	uint32_t remainingBytes=0;
	uint8_t Digest[32]       = {0};
	ts_pointerType Digest_S;
	Digest_S.data_U8P        = &Digest[0];
	Digest_S.length_U32      = 32;
	uint8_t key_len = RSA_3K;
	FILE *fp;
	char PckName[50];
	char PackagePath[50];


	prepare_tee_session_securestorage_crypto(&ctx);

	if(SignaturePtr != NULL)
	{
		signature_S.data_U8P = SignaturePtr;

		signature_S.length_U32 = SignatureLength;

		status = E_OK;
	}

	if(status != E_NOT_OK)
	{
		if(GetblockIndex(blkAddress, blkLength, &BlockIterator) == eUPD_Ok)
		{
			PackageName = MemoryConfig[BlockIterator].PkgName;
		}

		std::strcpy(PckName, PackageName.c_str());

		Metadata_GetActivePartition(ESwPartId_SBL, &partition) ;

		UpdGetPartionAddrAndLen((uint8 *)PckName,partition,&START_OFFSET,&END_OFFSET);

		UpdGetPartionPath(PckName, partition, PackagePath);

		fp = fopen(PackagePath, "rb");


		if (!fp)
		{
			fclose(fp);

			printf("\nDD01: fseek:FAILED\n");

			status = eUPD_NotOk;
		}
	}

	if(status == eUPD_Ok)
	{
		if (Crypto_SHA256_Start(&ctx) != TEEC_SUCCESS)
		{
			fclose(fp);
			status = eUPD_NotOk;
			printf("\nDD01: Crypto_SHA256_Start:FAILED\n");
		}
	}

	if((status == eUPD_Ok)&&(fseek(fp, START_OFFSET, SEEK_SET) == 0))
	{
		remainingBytes = END_OFFSET;

		while (remainingBytes > 0)
		{
			bytesToRead = (remainingBytes > BLOCK_SIZE_SIG) ? BLOCK_SIZE_SIG : remainingBytes;
			bytesRead = fread(buffer, 1, bytesToRead, fp);
			buffer_s.length_U32 = bytesRead;
			buffer_s.data_U8P = &buffer[0];

			if (bytesRead == 0) break; // Stop if no more data to read

			if (Crypto_SHA256_Update(&ctx, &buffer_s) != TEEC_SUCCESS)
			{
				fclose(fp);
				status = eUPD_NotOk;
				printf("\nDD01: Crypto_SHA256_Update:FAILED @ \n");
				break;
			}

			remainingBytes -= bytesRead;
		}

		if(status == eUPD_Ok)
		{
			if (Crypto_SHA256_Final(&ctx, &Digest_S) == TEEC_SUCCESS)
			{
				if(Crypto_RSASSA_PKCS1_v1_5_SHA256_Verify(&ctx, &Digest_S, &signature_S,key_len) != TEEC_SUCCESS)
				{
					status = eUPD_NotOk;
				}
			}

			fclose(fp);
		}

    }

	terminate_tee_session_securestorage_crypto(&ctx);

	if(status == eUPD_Ok)
	{
		if(ObjPartitionHandler.UpdatePartitionStatus(CurrentDownloadPart, ESwPartitionSts_Verified) == eUPD_Ok)
		{
			status = ObjPartitionHandler.UpdatePartitionVersion(CurrentDownloadPart);
		}
	}

	return status;
}

uint8 UpdateHandler::Activation()
{
	uint8 status = E_NOT_OK;
	uint8 partition = 0xFF;
	uint8 ChangedPartition = 0xFF;

	std::mutex m_updater_mtx;
	std::unique_lock<std::mutex> lock(m_updater_mtx);
	std::condition_variable wait_cond;

	if (Metadata_GetActivePartition(ESwPartId_SBL, &partition) == E_OK)
	{
		printf("\n Current activate Partition: %d\n", partition);

		ChangedPartition = (partition == EPartition_B) ? EPartition_A : (partition == EPartition_A) ? EPartition_B : EPartition_Last;

		if (ChangedPartition != EPartition_Last)
		{
			if(ObjPartitionHandler.PartitionValidityCheck(ChangedPartition) == E_OK)
			{
				if(Metadata_SetActivePartition(ESwPartId_SBL, ChangedPartition, TRUE) == E_OK)
				{
					status = E_OK;
				}
			}
		}
	}

	if(status == E_OK)
	{
		wait_cond.wait_for(lock, std::chrono::milliseconds(1000));

		status = Metadata_GetActivePartition(ESwPartId_SBL, &partition);

		printf("\n Active part:%d & changed part %d\n",partition, ChangedPartition);

		if (status == E_OK)
		{
			if(ChangedPartition != partition)
			{
				status = E_NOT_OK;

				printf("\n FOTA activation failed 3");
			}
			else
			{
				status = ObjPartitionHandler.PreResetRoutine();

				printf("\n Activation successful \n");
			}
		}
	}

	return status;
}

uint8 UpdateHandler::RecoveryPartitionSynchronization(uint8 *SyncStatus)
{
	uint8 status = E_NOT_OK;

	status = ObjPartitionHandler.RecoveryPartitionSync(SyncStatus);

	if((status == E_OK)&&(*SyncStatus == true))
	{
		status = ObjPartitionHandler.PreResetRoutine();

		if(status == E_OK)
		{
			// Add command to reboot the entire system.
		}
	}

	return status;
}

uint8 UpdateHandler::PrimaryPartitionSynchronization(uint8 *SyncStatus)
{
	return ObjPartitionHandler.ApplicationPartitionSync(SyncStatus);
}

uint8 UpdateHandler::GetblockIndex(uint32 BlockAdderss, uint32 BlockLength, uint8* blockindex)
{
	uint8 status = E_NOT_OK;

	uint8 BlockIterator = 0u;

	for(BlockIterator = 0u; BlockIterator < MEMORY_CONFIGURATION_SIZE; BlockIterator++)
	{
		if((MemoryConfig[BlockIterator].StartAddress == BlockAdderss) && ((BlockAdderss + BlockLength) <=  (MemoryConfig[BlockIterator].EndAddress)+ 1u))
		{
			*blockindex = BlockIterator;

			status = E_OK;

			break;
		}
	}

	return status;
}

/// End of user code

