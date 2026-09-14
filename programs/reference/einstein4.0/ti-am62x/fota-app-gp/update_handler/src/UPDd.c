/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

#include <unistd.h>
#include "Std_Types.h"
#include "UPDi.h"
#include "UPDd.h"
#include "UPDi_Target.h"
#include "UPD_IUpdate.h"
#include "UpdateCdd_Types.h"
#include <string.h>
#include <stdio.h>
#include "UPDi_IoAdapter.h"
#include "UPDi_BlockInstaller.h"
#include "UPDi_TarDecoder.h"
#include "UPDi_LzmaDecoder.h"
#include "UPDi_DeltaDecoder.h"
#include "UPDi_BlockDevIoAdapter.h"
#include "UPDi_AesDecoder.h"
#include "UPDi_VdtDecoder.h"
#include "SecurestorageCrypto_ca.h"
#include "metadata.h"

/*************AES decryption variables */
#define SYMMETRIC_KEY_SIZE 16
#define BLOCK_SIZE_SIG (4096u)

const char keyid[15] = "Secure_blob";
uint32_t keyid_size = strlen((const char *)keyid);
struct TEE_resource_ctx ctx1;
TEEC_Result result;
void *request;
uint8_t key[SYMMETRIC_KEY_SIZE+1]     = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};//"1234567890123456";

ts_pointerType aesCbcCipher_S;


uint8_t aesCbcIv_pU8[16+1]        = {0xFF,0xEE,0xDD ,0xCC ,0xBB ,0xAA ,0x99 ,0x88 ,0x77 ,0x66 ,0x55 ,0x44 ,0x33 ,0x22 ,0x11 ,0x00};//"1234567890123456";
ts_pointerType aesCbcIv_S;


ts_pointerType aesCbcPlaintext_S; /** CBC plain text in structure format */

/*************AES decryption variables end*/


UPD_DECLARE_BLOCKDEV_IOADAPTER(
	/*Name*/UPDBlockDevIoAdapter,                    // Name of the IoAdapter structure, can be used as to initialize the IoAdapter attribute within partitions
	/*Areas*/ NULL,             // Structure describing the sectors accessible by UpdCdd
	/*DriverVtbl*/NULL, // Structure containing pointers to functions realizing the FLS interface (Read pointer can be NULL
	/*Buffer size*/0x1000000,                      // Size of the FIFO, it shall be multiple of the page size, minimum two pages
	/*LowBufferThreshold*/ PAGE_SIZE,              // When buffer below the Threshold UpdCdd request new input data. To be adjusted to maximize the update speed
	/*PageSize*/ PAGE_SIZE,                    // Write access are done with a multiple of the page size, check the flash datasheet for best write performance
	/*EnableBlankDetection*/FALSE,			   // When enabled, blank pages are not flashed, because flash is supposed to be blank after erase
	/*BlankPattern*/ 0xFF,					   // Used if EnableBlankDetection is enabled, used to determine is the next page in the buffer need to be written
	/*EnableSectorBufferring*/ FALSE);         // When enabled the sector is buffered first in RAM, the sector is flash is preserved if its content match the buffer.

// ----------------------------------------------------------------------------
// Partitions
// ----------------------------------------------------------------------------

/* NOR */

tUPDiPartition Sbl_PartitionA = { .path = "/dev/mtd1", .Address = 0x0, .Size = 0x100000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Sbl_PartitionB = { .path = "/dev/mtd2", .Address = 0x0, .Size = 0x100000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition SblRecovery_PartitionA = { .path = "/dev/mtd4", .Address = 0x0, .Size = 0x100000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition SblRecovery_PartitionB = { .path = "/dev/mtd4", .Address = 0x0, .Size = 0x100000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition Hsm_PartitionA = { .path = "/dev/mtd5", .Address = 0x0, .Size = 0x20000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Hsm_PartitionB= { .path = "/dev/mtd6", .Address = 0x0, .Size = 0x20000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition HsmRecovery_PartitionA = { .path = "/dev/mtd8", .Address = 0x0, .Size = 0x20000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition HsmRecovery_PartitionB = { .path = "/dev/mtd8", .Address = 0x0, .Size = 0x20000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition Bl_PartitionA = { .path = "/dev/mtd10", .Address = 0x0, .Size = 0x40000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Bl_PartitionB = { .path = "/dev/mtd10", .Address = 0x0, .Size = 0x40000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition Mcu_PartitionA = { .path = "/dev/mtd11", .Address = 0x0, .Size = 0x400000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Mcu_PartitionB = { .path = "/dev/mtd12", .Address = 0x0, .Size = 0x400000, .IoAdapter = &UPDBlockDevIoAdapter };

/* EMMC */

tUPDiPartition Kernel_PartitionA = { .path = "/dev/mmcblk0boot0", .Address = 0x0, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Kernel_PartitionB = { .path = "/dev/mmcblk0boot1", .Address = 0x0, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition KernelRecovery_PartitionA = { .path = "/dev/mmcblk0", .Address = 0x2100000, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition KernelRecovery_PartitionB = { .path = "/dev/mmcblk0", .Address = 0x2100000, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition RootFs_PartitionA = { .path = "/dev/mmcblk0p1", .Address = 0x0, .Size = 0x20000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition RootFs_PartitionB = { .path = "/dev/mmcblk0p2", .Address = 0x0, .Size = 0x20000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition RootFsRecovery_PartitionA = { .path = "/dev/mmcblk0p4", .Address = 0x0, .Size = 0x20000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition RootFsRecovery_PartitionB = { .path = "/dev/mmcblk0p4", .Address = 0x0, .Size = 0x20000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition System_PartitionA = { .path = "/dev/mmcblk0p5", .Address = 0x0, .Size = 0x4000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition System_PartitionB = { .path = "/dev/mmcblk0p6", .Address = 0x0, .Size = 0x4000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition App_PartitionA = { .path = "/dev/mmcblk0p7", .Address = 0x0, .Size = 0x8000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition App_PartitionB = { .path = "/dev/mmcblk0p8", .Address = 0x0 , .Size = 0x8000000, .IoAdapter = &UPDBlockDevIoAdapter };

tUPDiPartition Asset_PartitionA = { .path = "/dev/mmcblk0p9", .Address = 0x0, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };
tUPDiPartition Asset_PartitionB = { .path = "/dev/mmcblk0p10", .Address = 0x0, .Size = 0x1000000, .IoAdapter = &UPDBlockDevIoAdapter };

// ----------------------------------------------------------------------------
// PartitionGroups
// ----------------------------------------------------------------------------

tUPDiPartitionGroup Sbl_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "SBL",       .BankA = &Sbl_PartitionA,          .BankB = &Sbl_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup SblRecovery_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "SBLRECOVERY",       .BankA = &SblRecovery_PartitionA,          .BankB = &SblRecovery_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup Hsm_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "HSM",       .BankA = &Hsm_PartitionA,          .BankB = &Hsm_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup HsmRecovery_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "HSMRECOVERY",       .BankA = &HsmRecovery_PartitionA,          .BankB = &HsmRecovery_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup Bl_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "BL",       .BankA = &Bl_PartitionA,          .BankB = &Bl_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup Mcu_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "MCU",       .BankA = &Mcu_PartitionA,          .BankB = &Mcu_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup Kernel_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "KERNEL",       .BankA = &Kernel_PartitionA,          .BankB = &Kernel_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup KernelRecovery_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "KERNELRECOVERY",       .BankA = &KernelRecovery_PartitionA,          .BankB = &KernelRecovery_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup RootFs_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "ROOTFS",       .BankA = &RootFs_PartitionA,          .BankB = &RootFs_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup RootFsRecovery_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "ROOTFSRECOVERY",       .BankA = &RootFsRecovery_PartitionA,          .BankB = &RootFsRecovery_PartitionB,          .BankExt = NULL }
};

tUPDiPartitionGroup System_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "SYSTEM",       .BankA = &System_PartitionA,          .BankB = &System_PartitionB,          .BankExt = NULL }
};
tUPDiPartitionGroup App_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "APP",       .BankA = &App_PartitionA,          .BankB = &App_PartitionB,          .BankExt = NULL }
};
tUPDiPartitionGroup Asset_SinglePartitionTarget_Group[SINGLE_PARTITION_TARGET_GROUP_COUNT] =
{
	{ .Name = "ASSET",       .BankA = &Asset_PartitionA,          .BankB = &Asset_PartitionB,          .BankExt = NULL }
};

// ----------------------------------------------------------------------------
// Targets
// ----------------------------------------------------------------------------

UPD_DECLARE_TARGET(eTargetTypeAB, SBL,            Sbl_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, SBLRECOVERY,    SblRecovery_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, HSM,            Hsm_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, HSMRECOVERY,    HsmRecovery_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, BL,             Bl_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, MCU,            Mcu_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, KERNEL,         Kernel_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, KERNELRECOVERY, KernelRecovery_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, ROOTFS,         RootFs_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, ROOTFSRECOVERY, RootFsRecovery_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, SYSTEM,         System_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, APP,            App_SinglePartitionTarget_Group);
UPD_DECLARE_TARGET(eTargetTypeAB, ASSET,          Asset_SinglePartitionTarget_Group);

// ----------------------------------------------------------------------------
// Installers & Decoders
// ----------------------------------------------------------------------------

tUPDiBlockInstaller blockInstaller =
{
	.Vtbl = &UPDBlockInstaller_Vtbl
};

tUPDiTarDecoderRam tarDecoder_Ram;
tUPDiTarDecoder tarDecoder =
{
	.Vtbl = &UPDTarDecoder_Vtbl,
	.pRam = &tarDecoder_Ram
};

tUPDiLzmaDecoderRam lzmaDecoder_Ram;
tUPDiLzmaDecoder lzmaDecoder =
{
	.Vtbl = &UPDiLzmaDecoder_VTBL,
	.pRam = &lzmaDecoder_Ram
};

tUPDiDeltaDecoderRam deltaDecoder_Ram;
tUPDiDeltaDecoder deltaDecoder =
{
	.Vtbl = &UPDDeltaDecoder_Vtbl,
	.pRam = &deltaDecoder_Ram
};

tUPDiAESDecoderRam oAESDecoder_Ram;
tUPDiAESDecoder oAESDecoder =
{
	.Vtbl = &UPDiAESDecoder_VTBL,
	.pRam = &oAESDecoder_Ram
};

tUPDiDeltaDecoderRam oVdtDecoder_Ram;
tUPDiDeltaDecoder oVdtDecoder =
{
	.Vtbl = &UPDVdtDecoder_Vtbl,
	.pRam = &oVdtDecoder_Ram
};


// ----------------------------------------------------------------------------
// Targets List
// ----------------------------------------------------------------------------

tUPDiTarget *oUPDCdd_Targets[TARGETS_COUNT] =
{
	&SBL,
	&SBLRECOVERY,
	&HSM,
	&HSMRECOVERY,
	&BL,
	&MCU,
	&KERNEL,
	&KERNELRECOVERY,
	&ROOTFS,
	&ROOTFSRECOVERY,
	&SYSTEM,
	&APP,
	&ASSET
};

tUPDiAbstractInstaller *oUPDCdd_Installer[INSTALLERS_COUNT] =
{
	(tUPDiAbstractInstaller*) &blockInstaller,
	(tUPDiAbstractInstaller*) &lzmaDecoder,
	(tUPDiAbstractInstaller*) &tarDecoder,
	(tUPDiAbstractInstaller*) &deltaDecoder,
	(tUPDiAbstractInstaller*) &oAESDecoder,
	(tUPDiAbstractInstaller*) &oVdtDecoder
};

tUPDiUpdateCdd oUPDCdd =
{
	.Mode = eUPDiMode_Reprog,
	.TargetsCount = TARGETS_COUNT, .Targets = oUPDCdd_Targets,
	.InstallersCount = INSTALLERS_COUNT, .Installers =	oUPDCdd_Installer,
};

//=====================================================================================================================
/* Public functions */
//=====================================================================================================================
/*=====================================================================================================================
 * Std_ReturnType void UPDd_Initialize(void)
 * Function description : UPDd.c shall initialize UPD,  load the data from NVM and call  UPD_Deserialize()
 * Input arguments : None
 * Output argument : None
 *=====================================================================================================================*/
void UPDd_Initialize(void)
{
	printf("\nupdate cdd V9.1\n");
	Metadata_Init();
	UPD_Init();
	tUPDBank Bank = eUPDiUpdate_BankInactive;
  	UPD_IUpdate_StartUPDate(Bank);

	//UPD_IUpdate_BootStatus(TRUE);
}

/*=====================================================================================================================
 * Std_ReturnType void UPDd_Shutdown(void)
 * Function description : Suspend UPD, serialize its NVM data and store the content to NVM
 * Input arguments : None
 * Output argument : E_OK - job is completed successfully
 *                   E_PENDING - job is ongoing - keep calling the function until completion
 *                   E_NOT_OK - job is failed
 *=====================================================================================================================*/
Std_ReturnType UPDd_Shutdown(void)
{
	Std_ReturnType Status = UPD_Suspend();

	if (Status == E_OK)
	{
		UPDd_TriggerNvmWrite();
	}

	return Status;
}

//=====================================================================================================================
/* Call-back functions */
//=====================================================================================================================
/*=====================================================================================================================
 * Std_ReturnType void UPDd_CustomValidation(void)
 * Function description : This function is guard condition before entering in state "Validated" and accepting an activation
 * 						  A typical implementation may consist to verify the secure boot signature of the inactive chain
 * Input arguments : None
 * Output argument : E_OK - Entry in State "Validated" is authorized
 *                   E_PENDING - job is ongoing - UPD keep calling the function until completion
 *                   E_NOT_OK - Entry in State "Validated" is forbidden
 *=====================================================================================================================*/
Std_ReturnType UPDd_CustomValidation(void)
{
	return E_OK;
}

/*=====================================================================================================================
 * Std_ReturnType void UPDd_UpdateArbAnchor(void)
 * Function description : This service support the realization of the Anti RollBack (ARB) function.
 *                        If ARB is not required, just return E_OK
 *						  If it is required, this function is called during the final commit.
 *						  Purpose is to update the ARB index / anchor using the index from active chain.
 * Input arguments : None
 * Output argument : E_OK - ARB Index have been updated
 *                   E_PENDING - job is ongoing - UPD keep calling the function until completion
 *                   E_NOT_OK - Something wrong happened.
 *=====================================================================================================================*/
Std_ReturnType UPDd_UpdateArbAnchor(void)
{
	return E_OK;
}
/*=====================================================================================================================
 * void UPDd_ReadHashFromManifest(tUPDdManifest *pManifest, tUPDHashInfo *pHash)
 * Function description : Content of the manifest is project specific, but it shall contain an Hash, checksum or CRC
 *                        This function allow to read the hash from the Manifest
 * Input arguments : pointer to Manifest
 * Output argument : pointer to Hash
 *=====================================================================================================================*/
void UPDd_ReadHashFromManifest(tUPDdManifest *pManifest, tUPDHashInfo *pHash)
{
	if (pManifest == NULL || pHash == NULL)
	{
	}
	else
	{
		pHash->HashType = eUPDiHash_Sha256;
		pHash->HashSize = sizeof(pManifest->GoldenSha256);
		pHash->pHash =  &pManifest->GoldenSha256[0];
	}
	for (uint8 i=0; i<pHash->HashSize; i++)
	{
	}
}

/*=====================================================================================================================
 * void UPDd_WriteHashToManifest(tUPDdManifest *pManifest, tUPDHashInfo *pHash)
 * Function description : Content of the manifest is project specific, but it shall contain an Hash, checksum or CRC
 *                        This function allow to write the hash to the Manifest
 * Input arguments : pointer to Hash
 * Output argument : pointer to Manifest
 *=====================================================================================================================*/
void UPDd_WriteHashToManifest(tUPDdManifest *pManifest, tUPDHashInfo *pHash)
{
	if (pManifest && pHash)
	{
		if ((pHash->HashType == eUPDiHash_Sha256)
				&& (pHash->HashSize == sizeof(pManifest->GoldenSha256))
				&& (pHash->pHash))
		{
			memcpy(pManifest->GoldenSha256, pHash->pHash,
					sizeof(pManifest->GoldenSha256));
		}
	}

	for (uint8 i=0; i<pHash->HashSize; i++)
	{
	}

}

/*=====================================================================================================================
 * void UPDd_TriggerNvmWrite(void)
 * Function description : This function is called by UPD when it need to store it's data to NVM
 *                        in reaction, this function shall call  UPD_Serialize() and save the data to NVM
 * Input arguments : None
 * Output argument : None
 *=====================================================================================================================*/
void UPDd_TriggerNvmWrite(void)
{
	// TODO:: DO NVM write only if the old data and new data is different
	// DO read before write and then if data changed, then write.
	// FILE *nvmFile = fopen(UPD_CONTEXT_PERSIST_PATH, "wb+");

	// if (nvmFile)
	// {
	// 	tUPDStream Stream;
	// 	uint8 Buffer[2 * DOM0_TARGETS_COUNT_1 * sizeof(tUPDdManifest) + 1024];
	// 	memset(Buffer, 0, sizeof(Buffer));
	// 	UPDi_InitStream(&Stream, Buffer, sizeof(Buffer));

	// 	if (UPD_Serialize(&Stream) == E_OK)
	// 	{
	// 		fwrite(Buffer, sizeof(Buffer), 1, nvmFile);
	// 	}

	// 	fclose(nvmFile);
	// 	sync();
	// }
}

/*=====================================================================================================================
 * void UPDd_TriggerUpdTask(void)
 * Function description : UPD execute IO operations within an internal Task, see UPD_Task() in UPD.h
 *                        When a new operation is queued, UPD call UPDd_TriggerUpdTask() to indicate that the task need
 *                        to be triggered.
 *                        If IO operations are asynchronous it's recommended to trigger the task when the operation is done
 * Input arguments : None
 * Output argument : None
 *=====================================================================================================================*/
void UPDd_TriggerUpdTask(void)
{
}

void UPDd_Task(void)
{
	UPD_Task();
}
/*=====================================================================================================================
 * void UPDd_AutoInspect(void)
 * Function description : Function is automatically called after the hold timeout following a boot
 *                        Purpose is to trigger optional inspection activities
 * Input arguments : None
 * Output argument : None
 *=====================================================================================================================*/
void UPDd_AutoInspect(void)
{
	// By default all active and inactive targets are inspected
	// A possible optimization could be to not inspect targets already verified by secure boot.
	// For example, secure boot may fully verify the active bank already.
	UPDUpdateMan_InspectBank(eUPDiUpdate_BankActive);
	UPDUpdateMan_InspectBank(eUPDiUpdate_BankInactive);
}


/*=====================================================================================================================
 * void UPDd_error_breakpoint(void) AND void UPDd_warning_breakpoint(void)
 * Function description : This functions are called in case of internal error or warning
 *                        It's typically used to set breakpoint and facilitate the debugging
 * Input arguments : None
 * Output argument : None
 *=====================================================================================================================*/
void  UPDd_error_breakpoint(void)
{
}

void  UPDd_warning_breakpoint(void)
{
}

Std_ReturnType UPD_ICry_Hash_Init(tUPDHashInfo* pHash)
{
	return E_OK;
}

Std_ReturnType UPD_ICry_Hash_Update(tUPDHashInfo* pHash, uint8* pBuffer, uint32 Size)
{
	return E_OK;
}

Std_ReturnType UPD_ICry_Hash_Final(tUPDHashInfo* pHash)
{
	return E_OK;
}

Std_ReturnType UPD_ICry_Decrypt_Init(void)
{
	Std_ReturnType Status = E_OK;
	aesCbcIv_S.data_U8P             = &aesCbcIv_pU8[0];
	aesCbcIv_S.length_U32           = 16u;
	//prepare_tee_session_securestorage_crypto(&ctx1);
	uint8_t enc_m1[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11};
	uint8_t enc_m2[32] = {0xA7, 0x3D, 0x02, 0x0C, 0xC4, 0xD7, 0x82, 0x5C,
		  0x93, 0x47, 0xD3, 0x01, 0xBE, 0x27, 0xE2, 0x04,
		  0x07, 0xA5, 0xD7, 0x94, 0x15, 0x44, 0xA8, 0x4E,
		  0x1B, 0xFC, 0xE8, 0x15, 0xF8, 0x5B, 0xE7, 0x90};
	uint8_t enc_m3[16] = {0x2E, 0xF3, 0x94, 0x63, 0x71, 0x30, 0x7A, 0x52,
		  0xBA, 0xAD, 0xD6, 0x57, 0xBD, 0x0E, 0x9A, 0x20};

	// Define ts_pointerType for key and encrypted data
    ts_pointerType m1_data    = { .data_U8P = enc_m1,  .length_U32 = sizeof(enc_m1) };
    ts_pointerType m2_data    = { .data_U8P = enc_m2,  .length_U32 = sizeof(enc_m2) };
    ts_pointerType m3_data    = { .data_U8P = enc_m3,  .length_U32 = sizeof(enc_m3) };

	result = SecureStorageCreateAndStore_CA(&ctx1, keyid, keyid_size, &m1_data, &m2_data, &m3_data);

	if (result == TEEC_SUCCESS) {
		printf("\nKey stored successfully (%s) as object 2\n",keyid);
	}
	else {
	printf("\nFailed to store key , either blob exist 0x%08x\n", result);
	}

	result = Crypto_AES128CBC_Decrypt_Start(&ctx1,keyid,keyid_size,&aesCbcIv_S);
	if (result == TEEC_SUCCESS)
	{
		Status = E_OK;
	}
	else {
		terminate_tee_session_securestorage_crypto(&ctx1);
	}
    return Status;
}

Std_ReturnType UPD_ICry_Decrypt_Update(uint8* pInBuffer, uint32 InSize, uint8* pOutBuffer, uint32* OutSize)
{
	Std_ReturnType Status = E_OK;

	uint32 remainingBytes = 0u;
	uint32 CompletedBytes = 0u;
	uint32 bytesToRead = 0u;

	remainingBytes = InSize;

	while (remainingBytes > 0)
	{
		bytesToRead = (remainingBytes > BLOCK_SIZE_SIG) ? BLOCK_SIZE_SIG : remainingBytes;

		aesCbcCipher_S.data_U8P         = (uint8*)(pInBuffer + CompletedBytes);
		aesCbcCipher_S.length_U32       = bytesToRead;
		aesCbcPlaintext_S.data_U8P      = (uint8*)(pOutBuffer + CompletedBytes);
		aesCbcPlaintext_S.length_U32    = bytesToRead;

		if (Crypto_AES128CBC_Decrypt_Update(&ctx1,&aesCbcCipher_S,&aesCbcPlaintext_S) != TEEC_SUCCESS)
		{
			Status = E_NOT_OK;

			printf("\n Crypto_AES128CBC_Decrypt_Update: FAILED \n");
			break;
		}

		CompletedBytes += bytesToRead;
		remainingBytes -= bytesToRead;
	}

	if (Status == E_OK)
	{
		memcpy(aesCbcIv_pU8,&aesCbcCipher_S.data_U8P[InSize-16],16);
		aesCbcIv_S.data_U8P             = &aesCbcIv_pU8[0];
		aesCbcIv_S.length_U32           = 16u;
		*OutSize = (uint32) InSize;
		printf("\nDecryption passed\n");
	}
	else
	{
		terminate_tee_session_securestorage_crypto(&ctx1);
	}

    return Status;
}

Std_ReturnType UPD_ICry_Decrypt_Final(uint8* pOutBuffer, uint32* OutSize)
{
	Std_ReturnType Status = E_NOT_OK;

	result = Crypto_AES128CBC_Decrypt_Final(&ctx1, &aesCbcPlaintext_S);

	if(result == TEEC_SUCCESS)
    {
        Status = E_OK;
    }

	//terminate_tee_session_securestorage_crypto(&ctx1);

    return Status;
}

Std_ReturnType UpdGetPartionAddrAndLen( uint8* Name, uint8 activePart,uint32 *addr, uint32 *pLen)
{
	uint8 i,j;

	Std_ReturnType status=E_NOT_OK;

	for(i=0;i<TARGETS_COUNT;i++)
	{
		for(j = 0u ;j < oUPDCdd_Targets[i]->GroupsCount;j++)
		{
			//printf("%s %s %d\n",oUPDCdd_Targets[i]->pGroups->Name,Name,strchr((const char *)Name, '.')- (char *)Name);
			if(0== strncmp((char *)oUPDCdd_Targets[i]->pGroups->Name,(const char *)Name,strchr((const char *)Name, '.')- (char *)Name))
			{
				//printf("\npassed\n");
				if(activePart == 1)//if b then read A
				{

					*addr = oUPDCdd_Targets[i]->pGroups->BankA->Address;
					*pLen = oUPDCdd_Targets[i]->pGroups->BankA->Size;
					status=E_OK;
					break;
				}
				else{
					*addr = oUPDCdd_Targets[i]->pGroups->BankB->Address;
					*pLen = oUPDCdd_Targets[i]->pGroups->BankB->Size;
					status=E_OK;
					break;
				}
			}

		}
		if(status==E_OK)
			{
				break;
			}
	}

	return status;
}

Std_ReturnType UpdGetPartionPath(const char* PackageName, uint8 activePart, char* PackagePath)
{
	uint8 i,j;

	Std_ReturnType status=E_NOT_OK;

	for(i=0;i<TARGETS_COUNT;i++)
	{
		for(j = 0u ;j < oUPDCdd_Targets[i]->GroupsCount;j++)
		{
			//printf("%s %s %d\n",oUPDCdd_Targets[i]->pGroups->Name,Name,strchr((const char *)Name, '.')- (char *)Name);
			if(0== strncmp((char *)oUPDCdd_Targets[i]->pGroups->Name,(const char *)PackageName, strchr((const char *)PackageName, '.')- (char *)PackageName))
			{
				//printf("\npassed\n");
				if(activePart == 1)//if b then read A
				{

					strcpy(PackagePath, oUPDCdd_Targets[i]->pGroups->BankA->path);

					status = E_OK;

					break;
				}
				else
				{
					strcpy(PackagePath, oUPDCdd_Targets[i]->pGroups->BankB->path);

					status = E_OK;

					break;
				}
			}

		}

		if(status==E_OK)
		{
			break;
		}
	}

	return status;

}
