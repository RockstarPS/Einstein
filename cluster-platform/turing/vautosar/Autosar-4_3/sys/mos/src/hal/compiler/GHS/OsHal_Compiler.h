/**
 * @file        OsHal_CompilerGHS.h
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

#ifndef OS_CPU_HAL_COMPILER_GHS_H
#define OS_CPU_HAL_COMPILER_GHS_H


/************************************* Includes **********************************/

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

#include "Compiler.h"


#define OS_ASM_START      __asm

#define OS_ASM_END        

#ifndef LOCAL
#define LOCAL               static
#endif

#define OS_LOCAL            LOCAL

#define OS_INLINE           INLINE

#define OS_CONST            CONST

#define OS_STATIC_INLINE    LOCAL INLINE

#define OS_ALIGN(x)         __attribute__((aligned(x)))

#define OS_PACKED           __attribute__((packed))

#define OS_PACKED_STRUCT    __attribute__((packed, aligned(1)))


#define OS_HAL_COMPILER_BARRIER()   __asm("DSB");  \ /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
                                    __asm("ISB"); /*MISRA RULE 1.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define OS_CODE             //__attribute__((section(".text.os")))

#define OS_VAR_MEMCLASS

#define OS_VAR_NOCACHE_MEMCLASS



extern FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_SetMpuRegion(OsIntMpuConfigType *pRegionConfig);
extern FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_DisableMpu(void);
extern FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_EnableMpu(void);
extern FUNC(void, OS_CODE) Os_Hal_Compiler_CortexM_DisableMpuRegion(osuint8 regionNum, osuint8 disabled);


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
