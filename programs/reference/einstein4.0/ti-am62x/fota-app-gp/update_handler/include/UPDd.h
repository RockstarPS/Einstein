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
# ifndef UPDd_H
# define UPDd_H

#include "UPDi_Types.h"
#include "UPDd_Types.h"
#include <stdio.h>

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define UPDd_ERROR(...) printf(__VA_ARGS__); printf("\n"); UPDd_error_breakpoint();
#define UPDd_WARNING(...) printf(__VA_ARGS__); printf("\n"); UPDd_warning_breakpoint();
#define UPDd_INFO(...) /*printf(__VA_ARGS__); printf("\n");*/
#define UPD_CFLS_IOADAPTER 					STD_ON
#define UPD_AES_DECODER 					STD_ON
#define AES_CYPHER EVP_						aes_128_cbc
#define UPD_FLS_IOADAPTER 					STD_OFF
#define APPLICATION_START_ADDRESS 			0x100C8000uL
#define BM_START_ADDRESS 					0x121F8000uL

#define APPLICATION_SIZE					0x338000uL
#define BM_SIZE 							0x4000uL
#define HSM_SIZE 							0x30000uL

#define TARGETS_COUNT 						(13)
#define INSTALLERS_COUNT					(6)
#define SINGLE_PARTITION_TARGET_GROUP_COUNT (1)
#define TRIPLE_PARTITION_TARGET_GROUP_COUNT (3)
#define NEW_RAW_PART_SIZE               	(0xF000)
#define PAGE_SIZE               			(0x1000)
#define MEMORY_CONFIGURATION_SIZE 			(0x0Du)
#define NUM_OF_COMPRESSION_AVAILABLE 		(0x06u)

extern struct TEE_resource_ctx ctx1;

void UPDd_AdapterInit (void);

// extern void  UPDd_SetDefaultManifest(tUPDdManifest* pManifest); 
extern void UPDd_Task(void);
extern void UPDd_Initialize(void);
extern Std_ReturnType UPDd_Shutdown(void);
extern Std_ReturnType  UPDd_RequestNvmWrite(uint8 address,uint8 size,uint8 *data);
extern Std_ReturnType UPDd_RequestNvmRead(uint8 address,uint8 size,uint8 *data);
extern uint32 UpDdi_GetEraseSize(uint32 address);
extern Std_ReturnType UPDd_GetInitialIV(uint8* IVBufferAddr);
void UPDd_AutoInspect(void);
void UPDd_TriggerNvmWrite(void);
extern void UPDd_error_breakpoint(void);
extern void UPDd_warning_breakpoint(void);
// Std_ReturnType UPDd_GetInactiveBank(tUPDiPartitionGroup* this, tUPDiPartition* pBank);
extern tUPDiPartitionGroup oTV2Partition_Groups[1];
extern Std_ReturnType UpdGetPartionAddrAndLen(uint8* Name,uint8 activePart,uint32 *addr, uint32 *pLen);
extern Std_ReturnType UpdGetPartionPath(const char* PackageName, uint8 activePart, char* PackagePath);
extern Std_ReturnType UPD_ICry_Decrypt_Final(uint8* pOutBuffer, uint32* OutSize);

# endif /*UPDd_H*/
