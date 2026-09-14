/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
*  File Name         :  OsHalCpu.h                                           *
*  Module Short Name :  Hal Cpu header                                       *
*  Description       :  Internal header which has cpu specific definitions   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GCC		                                             *
* Target Hardware  :  X86                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_CPU_HAL_H
#define OS_CPU_HAL_H

#include "OsTypes.h"


typedef struct
{
      osuint32 RegnNumber;           /*  Region number (MPU_RNR). */
      osuint32 RegnBaseAddress;      /*  Region base address (MPU_RBAR). */
      osuint32 RegnSize;
      AccessType RegnAccess;
      osuint32 RegnAttribute; /*  Region attribute, size and enable value (MPU_RASR). */     
}OsIntMpuConfigType;


extern void OsCpuHal_EnableMPU (void);


extern void OsCpuHal_DisableMPU (void);
extern void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig);
extern void OsCpuHal_DisableGlobalMPU(void);
extern void OsCpuHal_EnableGlobalMPU(void);
extern osuint32 osGetPRIMASK(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/* Os APIs for Enable Interrupt Source */
extern StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending);
/* Os APIs for Disable Interrupt Source */
extern StatusType OsHal_DisableInterruptSource(ISRType ISRID);

extern void OsHal_Initialize (void);

#define OsCpuHal_MpuSwitch(x)       OsCpuHal_MpuInitRegion(x)

#define osIsGlobalIntEnabled()    ((osGetPRIMASK() & 1UL) == 0U)

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
**   Date              : 29-Mar-2024                                                **
**   CDSID             : nvenkat5                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS Simulation Support - Initial Version                    **
**----------------------------------------------------------------------------------*/
