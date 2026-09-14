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

#include "PartitionHandler.hpp"
#include "FlashHandler.hpp"
//#include "upd_ucl_adapter_component.h"

extern "C"
{
  #include "metadata.h"
  #include "UPDd.h"
}

LOG_IMPORT_CONTEXT(BlAppGpLogContext);

#define MAX_NUMBER_OF_PARTITION_IN_RECOVERY 	(5u)
#define MAX_NUMBER_OF_PARTITION_IN_APPLICATION 	(8u)

FlashHandler FlsHandler;

PartitionInfo_Type RecoveryPartitionInfo[MAX_NUMBER_OF_PARTITION_IN_RECOVERY] =
{
	{	.PartId = ESwPartId_SBL_Recovery 		, .Name = "SBLRECOVERY" 	, .Destination = "/dev/mtd3", 		.Source="/dev/mtd4",		.DevTyp = EDeviceType_NOR,	.PrimaryUpdateStatus = FALSE },
	{	.PartId = ESwPartId_HSM_Recovery 		, .Name = "HSMRECOVERY" 	, .Destination = "/dev/mtd7", 		.Source="/dev/mtd8",		.DevTyp = EDeviceType_NOR,	.PrimaryUpdateStatus = FALSE },
	{	.PartId = ESwPartId_BL		   			, .Name = "BL"				, .Destination = "/dev/mtd9", 		.Source="/dev/mtd10",		.DevTyp = EDeviceType_NOR,	.PrimaryUpdateStatus = FALSE },
	{	.PartId = ESwPartId_Kernel_Recovery 	, .Name = "KERNELRECOVERY" 	, .Destination = "/dev/mmcblk0",	.Source="/dev/mmcblk0", 	.DevTyp = EDeviceType_EMMC,	.PrimaryUpdateStatus = FALSE },
	{	.PartId = ESwPartId_RootFS_Recovery		, .Name = "ROOTFSRECOVERY" 	, .Destination = "/dev/mmcblk0p3",	.Source="/dev/mmcblk0p4", 	.DevTyp = EDeviceType_EMMC,	.PrimaryUpdateStatus = FALSE },
};

PartitionInfo_Type ApplicationPartitionInfo[MAX_NUMBER_OF_PARTITION_IN_APPLICATION] =
{
	{.PartId = ESwPartId_SBL, .Name = "SBL", .Destination = "/dev/mtd2", .Source = "/dev/mtd1" , .DevTyp = EDeviceType_NOR},
	{.PartId = ESwPartId_HSM, .Name = "HSM", .Destination = "/dev/mtd6", .Source = "/dev/mtd5" , .DevTyp = EDeviceType_NOR},
	{.PartId = ESwPartId_MCU, .Name = "MCU", .Destination = "/dev/mtd12", .Source = "/dev/mtd11" , .DevTyp = EDeviceType_NOR},
	{.PartId = ESwPartId_Kernel, .Name = "KERNEL", .Destination = "/dev/mmcblk0boot1", .Source = "/dev/mmcblk0boot0", .DevTyp = EDeviceType_EMMC},
	{.PartId = ESwPartId_RootFS, .Name = "ROOTFS", .Destination = "/dev/mmcblk0p4", .Source = "/dev/mmcblk0p3", .DevTyp = EDeviceType_EMMC},
	{.PartId = ESwPartId_System, .Name = "SYSTEM", .Destination = "/dev/mmcblk0p6", .Source = "/dev/mmcblk0p5", .DevTyp = EDeviceType_EMMC},
	{.PartId = ESwPartId_Appl, .Name = "APP", .Destination = "/dev/mmcblk0p8", .Source = "/dev/mmcblk0p7", .DevTyp = EDeviceType_EMMC},
	{.PartId = ESwPartId_Asset, .Name = "ASSET", .Destination = "/dev/mmcblk0p10", .Source = "/dev/mmcblk0p9", .DevTyp = EDeviceType_EMMC}
};

uint8_t PartitionHandler::FlashBinary(const std::string& Destination,const std::string& Source, uint32_t DevTyp)
{
    uint8_t sts;

    if(DevTyp == EDeviceType_EMMC)
    {
        sts = FlsHandler.programEmmcPartition(Destination, Source);
    }
    else if(DevTyp == EDeviceType_NOR)
    {
        sts = FlsHandler.programNORPartition(Destination, Source);
    }
    else
    {
        sts = 1;
    }

	return sts;
}

uint8 PartitionHandler::RecoveryPartitionSync(boolean *SyncStatus)
{
	uint8 RetVal = E_OK;

	ESwPartitionSts_t PartitionStatus;

    uint8 idx = 0, ret = 1;

    LOGI(&BlAppGpLogContext, "start Primary Partition Flashing" );

    for(idx = 0; idx < MAX_NUMBER_OF_PARTITION_IN_RECOVERY; idx++)
    {
		RetVal = E_NOT_OK;

		*SyncStatus = false;

		if(GetPartitionStatus(RecoveryPartitionInfo[idx].PartId, EPartition_A, &PartitionStatus) == E_OK)
		{
			if(PartitionStatus != ESwPartitionSts_Verified)
			{
				ret = FlashBinary(RecoveryPartitionInfo[idx].Destination, RecoveryPartitionInfo[idx].Source, RecoveryPartitionInfo[idx].DevTyp);

				if(ret != 0)
				{
					LOGE(&BlAppGpLogContext, "Primary Partition failed for SWid :" , idx );

					RetVal = E_NOT_OK;

					break;
				}
				else
				{
					RetVal = SetPartitionStatus(RecoveryPartitionInfo[idx].PartId, EPartition_A, ESwPartitionSts_Programmed);

					if(RetVal == E_OK)
					{
						RetVal = SetPartitionStatus(RecoveryPartitionInfo[idx].PartId, EPartition_A, ESwPartitionSts_Verified);

						if(RetVal != E_OK)
						{
							break;
						}
						else
						{
							*SyncStatus = true;
						}
					}
				}
			}
		}
    }

	return RetVal;
}

uint8 PartitionHandler::UpdatePartitionStatus(uint8_t swPartId, ESwPartitionSts_t SwPartStatus)
{
	int32_t sts = -1;

	uint8 idx;

	uint8 RetVal = E_NOT_OK;

	EPartition_t activePart;

	EPartition_t inactivePart;

	std::string cmd;

	sts = Metadata_GetActivePartition(ESwPartId_SBL, &activePart);

	inactivePart = (activePart == EPartition_B) ? EPartition_A : (activePart == EPartition_A) ? EPartition_B : EPartition_Last;

	for(idx = 0; idx < MAX_NUMBER_OF_PARTITION_IN_RECOVERY; idx++)
	{
		if((swPartId == (RecoveryPartitionInfo[idx].PartId))&&(inactivePart != EPartition_Last))
		{
			RecoveryPartitionInfo[idx].PrimaryUpdateStatus = TRUE;

			inactivePart = EPartition_B;

			break;
		}
	}

	if((swPartId == ESwPartId_Kernel)&&(sts == E_OK)&&(SwPartStatus == ESwPartitionSts_Erased))
	{
		if(inactivePart == EPartition_A)
		{
			cmd = "echo 0 > /sys/block/mmcblk0boot0/force_ro";
		}
		else if(inactivePart == EPartition_B)
		{
			cmd = "echo 0 > /sys/block/mmcblk0boot1/force_ro";
		}
		else
		{
			// do nothing.
		}

		sts = system(cmd.c_str());
	}

	if((swPartId == ESwPartId_Kernel)&&(sts == E_OK)&&(SwPartStatus == ESwPartitionSts_Verified))
	{
		if(inactivePart == EPartition_A)
		{
			cmd = "echo 1 > /sys/block/mmcblk0boot0/force_ro";
		}
		else if(inactivePart == EPartition_B)
		{
			cmd = "echo 1 > /sys/block/mmcblk0boot1/force_ro";
		}
		else
		{
			// do nothing.
		}

		sts = system(cmd.c_str());
	}

	if((sts == E_OK)&&(inactivePart != EPartition_Last))
	{
		RetVal = SetPartitionStatus(swPartId, inactivePart, SwPartStatus);
	}

	return RetVal;
}

uint8 PartitionHandler::UpdatePartitionVersion(uint8_t swPartId)
{
    int32_t sts = -1;

	uint8 idx;

	uint8 RetVal = E_NOT_OK;

	EPartition_t activePart;

	EPartition_t inactivePart;

	SSwPartitionInfo_t activePartitionInfo;

	sts = Metadata_GetActivePartition(ESwPartId_SBL, &activePart);

	inactivePart = (activePart == EPartition_B) ? EPartition_A : (activePart == EPartition_A) ? EPartition_B : EPartition_Last;

    LOGI(&BlAppGpLogContext, "Partition Version Update for SW-ID" , swPartId , " inactivePart: " , inactivePart);

	if((sts == 0)&&(inactivePart != EPartition_Last))
	{
		for(idx = 0; idx < MAX_NUMBER_OF_PARTITION_IN_RECOVERY; idx++)
		{
			if(swPartId == (RecoveryPartitionInfo[idx].PartId))
			{
				inactivePart = EPartition_B;

				break;
			}
		}

		RetVal = SetPartitionVersion(swPartId, inactivePart);
	}

	return RetVal;
}

uint8 PartitionHandler::SetPartitionStatus(uint8_t swPartId, EPartition_t activePart, ESwPartitionSts_t SwPartStatus)
{
    int32_t sts = -1;

	uint8 RetVal = E_NOT_OK;

	uint8 idx;

	SSwPartitionInfo_t activePartitionInfo;

    LOGI(&BlAppGpLogContext, "Updating Partition status for SW ID ", swPartId, " Patition : " , activePart , " Status ", SwPartStatus );

	sts = Metadata_GetPartitionInfo(swPartId, activePart, &activePartitionInfo);

	if(sts == 0)
	{
		activePartitionInfo.status = SwPartStatus;

		sts = Metadata_SetPartitionInfo(swPartId, activePart, &activePartitionInfo);

		if(0 != sts)
		{
			LOGE(&BlAppGpLogContext,"Update Partition status failed with status ",sts);
		}
	}
	else
	{
		LOGE(&BlAppGpLogContext,"Get Partition status failed with status ",sts);
	}

	if(sts == 0)
	{
		RetVal = E_OK;
	}

	return RetVal;
}

uint8 PartitionHandler::GetPartitionStatus(uint8_t swPartId, EPartition_t activePart, ESwPartitionSts_t* SwPartStatus)
{
    int32_t sts = -1;

	uint8 RetVal = E_NOT_OK;

	SSwPartitionInfo_t activePartitionInfo;

	sts = Metadata_GetPartitionInfo(swPartId, activePart, &activePartitionInfo);

	if(sts == 0)
	{
		*SwPartStatus = activePartitionInfo.status;

		RetVal = E_OK;
	}
	else
	{
		LOGE(&BlAppGpLogContext,"Get Partition status failed with status ",sts);
	}

	return RetVal;
}

uint8 PartitionHandler::SetPartitionVersion(uint8_t swPartId, EPartition_t activePart)
{
    int32_t sts = -1;

	uint8 RetVal = E_NOT_OK;

	SSwPartitionInfo_t activePartitionInfo;

	sts = Metadata_GetPartitionInfo(swPartId, activePart, &activePartitionInfo);

	if(sts == 0)
	{
		activePartitionInfo.version.major = activePartitionInfo.version.major + 1;

		LOGI(&BlAppGpLogContext, "Updated Version ", activePartitionInfo.version.major);

		sts = Metadata_SetPartitionInfo(swPartId, activePart, &activePartitionInfo);

		if(0 != sts)
		{
			LOGE(&BlAppGpLogContext,"Update Partition Version failed with status ",sts);
		}
	}
	else
	{
		LOGE(&BlAppGpLogContext,"Get Partition Version failed with status ",sts);
	}

	if(sts == 0)
	{
		RetVal = E_OK;
	}

	return RetVal;
}

uint8 PartitionHandler::GetPartitionVersion(uint8 swPartId, uint8 activePart, uint8* SwVersion)
{
	int32_t sts = -1;

	uint8 RetVal = E_NOT_OK;

	SSwPartitionInfo_t activePartitionInfo;

	sts = Metadata_GetPartitionInfo(swPartId, activePart, &activePartitionInfo);

	if(sts == 0)
	{
		*SwVersion = activePartitionInfo.version.major;

		LOGI(&BlAppGpLogContext, "Current Version ", *SwVersion);

		RetVal = E_OK;
	}
	else
	{
		LOGE(&BlAppGpLogContext,"Get Partition Version failed with status ",sts);
	}

	return RetVal;

}

uint8 PartitionHandler::PreResetRoutine(void)
{
	uint8 idx;

	uint8 InvalidatePrimaryPart = FALSE;

	int32_t sts;

	EPartition_t activePart;

	ESwPartitionSts_t PartitionStatus = ESwPartitionSts_Erased;

	uint8 RetVal = E_NOT_OK;

	for(idx = 0; idx < (MAX_NUMBER_OF_PARTITION_IN_RECOVERY); idx++)
	{
		RetVal = E_NOT_OK;

		if(RecoveryPartitionInfo[idx].PrimaryUpdateStatus == TRUE)
		{
			InvalidatePrimaryPart = TRUE;

			(void)GetPartitionStatus(RecoveryPartitionInfo[idx].PartId, EPartition_B, &PartitionStatus);

			if(PartitionStatus == ESwPartitionSts_Verified)
			{
				if( RecoveryPartitionInfo[idx].DevTyp == EDeviceType_NOR)
				{
					RetVal = FlsHandler.NorErase(RecoveryPartitionInfo[idx].Destination);
				}
				else if(RecoveryPartitionInfo[idx].DevTyp == EDeviceType_EMMC)
				{
					if(RecoveryPartitionInfo[idx].PartId != ESwPartId_RootFS_Recovery)
					{
						RetVal = FlsHandler.EMMCErase(RecoveryPartitionInfo[idx].Destination, RecoveryPartitionInfo[idx].Size);
					}
					else
					{
						RetVal = E_OK; // Do not erase the Recovery RootFS, it will corrupt the execution so skip the erase for this partition alone.
					}
				}
				else
				{
					// Wrong state. do nothing.
				}

				if(RetVal == E_OK)
				{
					RetVal = SetPartitionStatus(RecoveryPartitionInfo[idx].PartId, EPartition_A, ESwPartitionSts_Erased);

					if(RetVal != E_OK)
					{
						break;
					}
				}
			}
		}
	}

	sts = Metadata_GetActivePartition(ESwPartId_SBL, &activePart);

	if(sts == E_OK)
	{
		RetVal = PartitionValidityCheck(activePart);
	}

	if((InvalidatePrimaryPart != TRUE)&&(RetVal == E_OK))
	{
		sts = Metadata_SetBootStatusFlag(EBootStatus_Normal);
	}
	else
	{
		sts = Metadata_SetBootStatusFlag(EBootStatus_Bootloader);
	}

	if(sts == E_OK)
	{
		RetVal = E_OK;
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;
}

uint8 PartitionHandler::ApplicationPartitionSync(boolean *SyncStatus)
{
	uint8 RetVal = E_NOT_OK;
	uint8 status = E_NOT_OK;
	EPartition_t ActivePart = EPartition_Last;
	EPartition_t InActivePart = EPartition_Last;
	uint8 SourceVersion = 0u;
	uint8 DestinationVersion = 0u;
	uint8 idx = 0u;
	int32_t sts = -1;

	sts = Metadata_GetActivePartition(ESwPartId_SBL, &ActivePart);

	if(sts == 0)
	{
		if(ActivePart == EPartition_A)
		{
			InActivePart = EPartition_B;
		}
		else if(ActivePart == EPartition_B)
		{
			InActivePart = EPartition_A;
		}
		else
		{
			// Do nothing.
		}
	}

	if(ActivePart != EPartition_Last)
	{
		for(idx = 0u; idx < MAX_NUMBER_OF_PARTITION_IN_APPLICATION; idx++)
		{
			if(GetPartitionVersion(ApplicationPartitionInfo[idx].PartId, ActivePart, &SourceVersion) == E_OK)
			{
				if(GetPartitionVersion(ApplicationPartitionInfo[idx].PartId, InActivePart, &DestinationVersion) == E_OK)
				{
					if(SourceVersion != DestinationVersion)
					{
						status = PartitionCopy(ApplicationPartitionInfo[idx].PartId, ActivePart);

						if(status == E_OK)
						{
							status = SetPartitionVersion(ApplicationPartitionInfo[idx].PartId, InActivePart);

							if(status != E_OK)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}

	if((idx == MAX_NUMBER_OF_PARTITION_IN_APPLICATION)&&(status == E_OK))
	{
		RetVal = E_OK;
	}

	return RetVal;
}

uint8 PartitionHandler::PartitionCopy(uint8 partid, EPartition_t ActivePart)
{
	std::string dest = "";
	std::string src = "";
	uint8 RetVal = E_OK;
	uint8 idx = 0u;

	for(idx = 0; idx < MAX_NUMBER_OF_PARTITION_IN_APPLICATION; idx++)
	{
		if(ApplicationPartitionInfo[idx].PartId == partid)
		{
			if(ActivePart == EPartition_A)
			{
				dest = ApplicationPartitionInfo[idx].Destination;

				src = ApplicationPartitionInfo[idx].Source;
			}
			else if(ActivePart == EPartition_B)
			{
				dest = ApplicationPartitionInfo[idx].Source;

				src = ApplicationPartitionInfo[idx].Destination;
			}
			else
			{
				RetVal = E_NOT_OK;
			}

			if(RetVal != E_NOT_OK)
			{
				RetVal = FlashBinary(dest, src, ApplicationPartitionInfo[idx].DevTyp);
			}
		}
	}

	return RetVal;

}

uint8 PartitionHandler::PartitionValidityCheck(EPartition_t activePart)
{
	uint8 idx;

	ESwPartitionSts_t PartitionStatus = ESwPartitionSts_Erased;

	uint8 RetVal = E_NOT_OK;

	for(idx = 0; idx < ESwPartId_Last; idx++)
	{
		RetVal = GetPartitionStatus(idx, activePart, &PartitionStatus);

		if((RetVal != E_OK)||(PartitionStatus != ESwPartitionSts_Verified))
		{
			break;
		}
		else
		{
		}
	}

	if(idx == ESwPartId_Last)
	{
		RetVal = E_OK;
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;

}

uint8 PartitionHandler::Erase(std::string PackageName)
{
	char PackagePathUpd[100];
	std::string PackagePath;
	uint8 status = E_NOT_OK;
	EPartition_t activePart;

	Metadata_GetActivePartition(ESwPartId_SBL, &activePart) ;

	if(UpdGetPartionPath(PackageName.c_str(), activePart, PackagePathUpd) == E_OK)
	{
		PackagePath = PackagePathUpd;

		if (PackagePath.find("mtd") != std::string::npos)
		{
			//its a MTD device.
			status = FlsHandler.NorErase(PackagePath);
		}
		else
		{
			//its a emmc partition and does not require erase.
			status = E_OK;
		}
	}

	return status;
}


