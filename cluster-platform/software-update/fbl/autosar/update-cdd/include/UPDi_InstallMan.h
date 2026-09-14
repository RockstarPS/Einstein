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

#ifndef UPD_InstallMan_H
#define UPD_InstallMan_H

#include "UPD.h"
#include <stdint.h>

//=====================================================================================================================
/* Global variables */
//=====================================================================================================================

//=====================================================================================================================
/* Public installation interface */
//=====================================================================================================================
/*FOTA or Wired update*/
Std_ReturnType UPDInstallMan_TransferStart(const char* PackageName, uint32_t PackageSize);
Std_ReturnType UPDInstallMan_TransferData( uint32_t Size, uint8_t* data);
Std_ReturnType UPDInstallMan_TransferExit(void);
Std_ReturnType UPDInstallMan_Erase(char* PackageName, uint32_t PackageSize);
Std_ReturnType UPDInstallMan_VerifyTarget(tUPDiTarget* pTarget, tUPDHashInfo *pHash);
Std_ReturnType UPDInstallMan_GetTargetHash(tUPDiTarget* pTarget, tUPDHashInfo* pHash);
Std_ReturnType UPDInstallMan_CopyAllToInactive(void);
/*Resume an installation session*/
Std_ReturnType UPDInstallMan_Resume(const char* PackageName, uint32_t PackageSize, uint32_t* pOffset);
Std_ReturnType UPDiInstallMan_Suspend(void);

//=====================================================================================================================
//  Management interface
//=====================================================================================================================
void UPDInstallMan_Init(void);
void    UPDiInstallMan_Task(void);
boolean UPDiInstallMan_IsBusy(void);
tUPDWorkload UPDiInstallMan_GetWorkload(void);
void UPDiInstallMan_Serialize(tUPDStream *pStream);
void UPDiInstallMan_Deserialize(tUPDStream *pStream);


//=====================================================================================================================
//  Management interface
//=====================================================================================================================
Std_ReturnType UPDInstallMan_ProcessIO(void);
Std_ReturnType UPDiInstallMan_Rewind(uint32_t rewindOffset);
uint32_t UPDiInstallMan_GetImageOffset(void);
void UPDInstallMan_PorcessTargets(void);

#endif /*UPD_InstallMan_H*/
