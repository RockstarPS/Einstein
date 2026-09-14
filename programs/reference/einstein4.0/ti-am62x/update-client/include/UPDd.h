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

#include "UPD.h"
#include "UPDd_Types.h"
#include "UPDi_Types.h"
#include <errno.h>
#include <stdio.h>

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define UPDd_ERROR(...) printf(__VA_ARGS__); printf("\n"); UPDd_error_breakpoint();
#define UPDd_WARNING(...) printf(__VA_ARGS__); printf("\n"); UPDd_warning_breakpoint();
#define UPDd_INFO(...) /*printf(__VA_ARGS__); printf("\n");*/

extern tUPDiPartitionGroup oAOnlyPartition_Groups[1];

#define UPD_CFLS_IOADAPTER STD_ON
#define UPD_FLS_IOADAPTER STD_OFF
#define APPLICATION_START_ADDRESS 0x100C8000uL
#define BM_START_ADDRESS 0x121F8000uL
#define HSM_START_ADDRESS 0x12000000uL
#define APPLICATION_SIZE 0x338000uL
#define BM_SIZE 0x4000uL
#define HSM_SIZE 0x30000uL

//=====================================================================================================================
//  Public functions
//=====================================================================================================================
void UPDd_Initialize(void);
Std_ReturnType UPDd_Shutdown(void);

Std_ReturnType UPDd_CustomValidation(void);
Std_ReturnType UPDd_UpdateArbAnchor(void);

void UPDd_ReadHashFromManifest(tUPDdManifest* pManifest, tUPDHashInfo* pHashingContext);
void UPDd_WriteHashToManifest(tUPDdManifest* pManifest, tUPDHashInfo* pHashingContext);
void UPDd_TriggerNvmWrite(void);
void UPDd_TriggerUpdTask(void );
void UPDd_AutoInspect(void);

void UPDd_error_breakpoint(void);
void UPDd_warning_breakpoint(void);

extern void FblFlashDrv_Init(void);
extern Std_ReturnType FblFlashDrv_Erase(uint32 addr, uint32 len);
extern Std_ReturnType FblFlashDrv_Write(uint32 addr, uint8 *pBuffer, uint32 pLen);

#endif /* UPDd_H */
