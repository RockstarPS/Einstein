/**
 * @file        OsHalCpu.h
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
 * @details     <b>Internal header which has cpu specific definitions</b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_CPU_HAL_H
#define OS_CPU_HAL_H

#include "OsTypes.h"

#define OsCpuHal_EnterPrivilegeMode()  __asm("svc #1") 

/** The Fault configuration structure. */

#define R0_Pos              (0u)    /**< Position of R0  content in fault structure */
#define R1_Pos              (1u)    /**< Position of R1  content in fault structure */
#define R2_Pos              (2u)    /**< Position of R2  content in fault structure */
#define R3_Pos              (3u)    /**< Position of R3  content in fault structure */
#define R12_Pos             (4u)    /**< Position of R12 content in fault structure */
#define LR_Pos              (5u)    /**< Position of LR  content in fault structure */
#define PC_Pos              (6u)    /**< Position of PC  content in fault structure */
#define PSR_Pos             (7u)    /**< Position of PSR content in fault structure */

# define OS_INT_INTC_CPUSS_CM4_SYSTEM_BASE            (0x4020A000uL)
# define OS_INT_CPUSS_CM4_SYSTEM_INT_CTL(x)           (*(volatile uint32*) (OS_INT_INTC_CPUSS_CM4_SYSTEM_BASE + ((x) * 4UL)))
# define OS_INT_INTC_SYSTEM_INT_CL_ENABLED_BIT        (1uL << 31)

#define OS_SYST_CSR                                    (*((volatile osuint32*)(0xE000E010)))    
#define OsDisableSystickInt()                          (OS_SYST_CSR&=~(1uL<<1))
#define OsEnableSystickInt()                           (OS_SYST_CSR|=(1uL<<1))

#define CM4_SCS_SHCSR       (*(volatile uint32*) (0xE000ED24uL))

#define CM4_CFSR_REGISTER        (*(volatile uint32*) (0xE000ED28uL))
#define IMPRECIS_ERROR 1024uL

/*ProtectionHook error macros*/
#define MMARVALID     (0x80U)
#define MPU_FAULT     (0x3BU)
#define USAGE_FAULT   (0x30F0000U)
#define BUS_FAULT     (0x3F00U)
#define BFARVALID     (0x8000U)

typedef struct
{
    osuint32 r0;               /**< R0 register content */
    osuint32 r1;               /**< R1 register content */
    osuint32 r2;               /**< R2 register content */
    osuint32 r3;               /**< R3 register content */
    osuint32 r12;              /**< R12 register content */
    osuint32 lr;               /**< LR register content */
    osuint32 pc;               /**< PC register content */
    osuint32 psr;              /**< PSR register content */
    osuint32 cfsr;             /**< CFSR register content */
    osbool   IsMMARValid;      /**< IS MMAR valid */
    osbool   IsBFARValid;      /**< IS BFAR valid */
    osuint32 MMARErrAddress;   /**< MMAR Error address */
    osuint32 BFARErrAddress;   /**< MMAR Error address */
} ProtErrorInfoType;

typedef struct
{
      osuint32 RegnNumber;           /*  Region number (MPU_RNR). */
      osuint32 RegnBaseAddress;      /*  Region base address (MPU_RBAR). */
      osuint32 RegnSize;
      AccessType RegnAccess;
      osuint32 RegnAttribute; /*  Region attribute, size and enable value (MPU_RASR). */     
}OsIntMpuConfigType;


extern void OsCpuHal_EnableMPU (void);
extern osbool OsCpuHal_IsOsTrapRequired(void);
extern void OsCpuHal_ExitPrivilegeMode(void);
extern osbool OsCpuHal_IsOsPrivilegeMode(void);

// __asm osuint32 OsCpuHal_SaveDisableLevel (void)
// {
//     mrs r0,basepri
//     mov r1, #16
//     msr basepri,r1

// }

// __asm void OsCpuHal_RestoreLevel (osuint32 IntStatus)
// {
// %reg IntStatus  /* If the value is passed through register ie., r0*/
//     msr basepri, IntStatus
// %mem IntStatus  /* If Intstatus is through a memory, load it to reg and update basepri */
//     ldr r6, IntStatus
//     msr basepri,r6

// }



extern void OsCpuHal_DisableMPU (void);
extern void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig);
extern void OsCpuHal_DisableGlobalMPU(void);
extern void OsCpuHal_EnableGlobalMPU(void);
extern osuint32 osGetPRIMASK(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

extern void OsHal_Initialize (void);
extern void OsHalPrv_EnableIrqSource (osuint32 IrqSrc);
extern void OsHalPrv_DisableIrqSource (osuint32 IrqSrc);

void OsFaultHandler(osuint32 const *faultStackAddr);
void Os_ProcessingFault(void);

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
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS SC3 Support - Initial Version                           **
**----------------------------------------------------------------------------------*/
