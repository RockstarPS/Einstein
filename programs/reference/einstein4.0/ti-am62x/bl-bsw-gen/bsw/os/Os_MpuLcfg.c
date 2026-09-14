/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Os_MpuLcfg.c
*    @ingroup Os Configuration
*    @brief This is Os link time configuration source file. It contains definitions of link time
*    configuration parameters for the Os module.
*    Auto generated code in vAUTOSAR TOOL by MNATRAMI at 2026-04-06 16:31:56.382885
********************************************************************************************************************/

#ifndef OSMPU_LCFG_C
#define OSMPU_LCFG_C


/*****************************************************************************
*                            Include files                                   *
*****************************************************************************/
#include "Os_Lcfg.h"


const OsIntMpuConfigType OsMpu_TrustedSystem[OsNumberOfMPURegions_OsMpu_TrustedSystem] = {

	{
	/* .RegionNumber           = */ 3UL,
	/* .RegionBaseAddress      = */ 0x79120000UL,
	/* .RegionSize             = */ 0x20000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(17) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 5UL,
	/* .RegionBaseAddress      = */ 0x41010400UL,
	/* .RegionSize             = */ 0x8000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_R_U_R | OS_INT_MPU_ACCESS_EXECUTE_ALLOWED | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(15) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 6UL,
	/* .RegionBaseAddress      = */ 0x00000000UL,
	/* .RegionSize             = */ 0x8000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_RW_U_R | OS_INT_MPU_ACCESS_EXECUTE_ALLOWED | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(15) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 10UL,
	/* .RegionBaseAddress      = */ 0x79140000UL,
	/* .RegionSize             = */ 0x8000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_RW_U_R | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(15) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 11UL,
	/* .RegionBaseAddress      = */ 0x79120000UL,
	/* .RegionSize             = */ 0x10000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_R_U_R | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(16) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 13UL,
	/* .RegionBaseAddress      = */ 0x04000000UL,
	/* .RegionSize             = */ 0x4000000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_RW_U_RW | OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN | OS_INT_MPU_ACCESS_TYPE_STRONGLY_ORDERED,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(26) | OS_INT_MPU_REGION_SIZE_ENABLE
	},


	{
	/* .RegionNumber           = */ 14UL,
	/* .RegionBaseAddress      = */ 0x07FF0000UL,
	/* .RegionSize             = */ 0x4000UL,
	/* .AccessType             = */ (AccessType)OS_ACCESS_TYPE_RWX,
	/* .RegionAttribute		   = */ OS_INT_MPU_ACCESS_S_RW_U_R | OS_INT_MPU_ACCESS_EXECUTE_ALLOWED | OS_INT_MPU_ACCESS_TYPE_STRONGLY_ORDERED,
	/* .RegnSizeAndEnable	   = */ OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(0)| OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(14) | OS_INT_MPU_REGION_SIZE_ENABLE
	}

};

const OsMPUAccessGroupConfigType OsMPUAccessGroupConfig[OsMaxAccessGroupIds] = {

	{
	/*Region Count					= */ OsNumberOfMPURegions_OsMpu_TrustedSystem,
	/*OsIntMpuConfigTypeRef			= */ (OsIntMpuConfigType*)&OsMpu_TrustedSystem
	}
};


const OsMpuAccessGroupDiffType OsMpuAccessGroupDiff[OsMaxAccessGroupIds][OsMaxAccessGroupIds] = {
	{ /*OsMpu_TrustedSystem*/
	   {0, NULL}
    }
};



#endif    /* */



/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

