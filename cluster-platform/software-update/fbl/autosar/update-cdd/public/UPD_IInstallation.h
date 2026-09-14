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
# ifndef UPD_IInstallation_H
# define UPD_IInstallation_H

# include "UPD_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

//=====================================================================================================================
//  Public installation interface
//=====================================================================================================================
/* FOTA or Wired update */
Std_ReturnType UPD_IInstallation_TransferStart(const char* pPackageName, uint32_t PackageSize);
Std_ReturnType UPD_IInstallation_TransferData(uint32_t Size, uint8_t* data);
Std_ReturnType UPD_IInstallation_TransferExit(void);

/* Resume an installation session.*/
Std_ReturnType UPD_IInstallation_Resume(const char *PackageName,uint32_t PackageSize, uint32_t* pOffset);

/*FOTA only*/
/* copy related inactive partitions to active partitions.*/
Std_ReturnType UPD_IInstallation_CopyToInactive(uint8_t TargetId);
/* For all Uninstalled targets, copy all inactive partitions to active partitions.*/
Std_ReturnType UPD_IInstallation_CopyAllToInactive(void);

#ifdef __cplusplus
}
#endif

# endif /*UPD_IInstallation_H*/


