/**
 * @file        OsHal_CompilerGHS.c
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @details     <b>Internal File</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

#ifndef OS_CPU_HAL_COMPILER_GHS_C
#define OS_CPU_HAL_COMPILER_GHS_C


/************************************* Includes **********************************/
#include "OsPrivate.h"
#include "OsMain.h"
#include "OsHal_Compiler.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"


/**
 * @brief       This function is used to set the MPU region.
 * @param       pRegionConfig   Pointer to the region configuration structure.
 * @return      None.
 * @attention   User shall call this API only after the MPU is disabled
 *              by calling the API Os_Hal_Compiler_CortexR5F_DisableMpu().
 *              User shall only enable the MPU after setting up the regions.
 * @note        Compiler    : CLang-C \n
 * Target Hw   : Independent
 * 
*/
FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_SetMpuRegion(OsIntMpuConfigType *pRegionConfig)
{
    
}

/**
 * @brief       This function is used to disable the MPU.
 * @return      None.
 * @note        Compiler    : CLang-C \n
 * Target Hw   : Independent
 * 
*/
FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_DisableMpu(void)
{
    
}


/**
 * @brief       This function is used to enable the MPU.
 * @return      None.
 * @note        Compiler    : CLang-C \n
 * Target Hw   : Independent
 * 
*/
FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_EnableMpu(void)
{
    
}

/**
 * 
*/
FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_DisableMpuRegion(osuint8 regionNum, osuint8 disabled)
{
    
}





#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**   ------------------------------------------------------------------------------ **
**   Date              : 20-FEB-2024                                                **
**   CDSID             : ssukuma1                                                   **
**   Ref Id            : PE4TI29141-1825                                            **
**   Change Description: Compiler Abstraction Layer for GHS compiler                **
**----------------------------------------------------------------------------------**/
