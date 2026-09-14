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

#define OsDisableSystickInt()    
#define OsEnableSystickInt()    

/*ProtectionHook error macros*/
#define ASYNC_EXT_ABORT (0x406U)
#define ASYNC_ECC_ABORT (0x408U)

typedef struct
{
    osuint32 FaultInstructionAddr;    /* Address which triggered the fault */
    osuint32 lr;                      /* LR register content */
    osuint32 spsr;                    /* SPSR register content */
    osuint32 DFSR;                    /* DFSR register content */
    osuint32 IFSR;                    /* IFSR register content */
    osuint8  FaultException;          /* 0x1->Data_Abort 0x2->Prefetch_Abort 0x4->Undefined */
    osbool   IsMMARValid;             /* IS MMAR valid */
    osuint32 MMARErrAddress;          /* MMAR Error address, Valid only if IsMMARValid is TRUE */
    osuint32 r0;                      /* R0 during exception entry */
    osuint32 r1;                      /* R1 during exception entry */
    osuint32 r2;                      /* R2 during exception entry */
    osuint32 r3;                      /* R3 during exception entry */
    osuint32 r12;                     /* R12 during exception entry */
} ProtErrorInfoType;

typedef struct
{
      osuint32 RegnNumber;           /*  Region number (MPU_RNR). */
      osuint32 RegnBaseAddress;      /*  Region base address (MPU_RBAR). */
      osuint32 RegnSize;
      AccessType RegnAccess;
      osuint32 RegnAttribute;        /*  Region attributes */     
      osuint32 RegnSizeAndEnable;    /* 0 bit : Enable/Disable, [1:5] - Region size, [8:15] - Sub region Disable */     
}OsIntMpuConfigType;


extern void OsCpuHal_EnableMPU (void);
extern osbool OsCpuHal_IsOsTrapRequired(void);
extern void OsCpuHal_ExitPrivilegeMode(void); 
extern osbool OsCpuHal_IsOsPrivilegeMode(void);

extern void OsCpuHal_DisableMPU (void);
extern void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig);
extern void OsCpuHal_DisableGlobalMPU(void);
extern void OsCpuHal_EnableGlobalMPU(void);
extern osuint32 osGetPRIMASK(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern osuint32 osGetBASEPRI(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

extern void OsHal_Initialize (void);

extern void OsFaultHandler(void);
extern void OsHal_CpuTrap(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam);

osuint32 osMpuIsEnabledAsm(void);
void osMpuEnableAsm(void);
void osMpuRegionDisableAsm(osuint32 RegionId, osuint32 RegionDisableValue);
void osMpuSetRegionAsm(osuint32 regionId, osuint32 regionBaseAddr, osuint32 sizeAndEnble, osuint32 regionAttrs);
extern osuint32 osMpuGetMpuTypeAsm(void);
extern osuint32 osGetDFSR(void);
extern osuint32 osGetDFAR(void);
extern osuint32 osGetIFSR(void);
extern osuint32 osGetIFAR(void);
extern void osDataAbortExpHandler (void);
extern void osPrefetchAbortHandler (void);
extern void osUndefExceptionHandler (void);

#define OS_ARCH_INITIALIZE()                osIntArchInitialize();
#define OS_ARCH_SETUP_INTERRUPTS()          osSetupAndEnableConfiguredInterrupts();
#define OsCpuHal_MpuSwitch(x)       OsCpuHal_MpuInitRegion(x)
#define osdIntIrqBitCheck                 0x80UL
#define osIsGlobalIntEnabled()    ((osGetCPSR() & osdIntIrqBitCheck) == 0U) /*NCHELLAP : Modified for Global interrupt check*/

/*  Region Attribute and Size Register c6: Value to use for a disabled region. */
# define OS_INT_MPU_REGION_DISABLED_VALUE           (0UL << 0)
/*  Region Attribute and Size Register c6: ENABLE bit. */
# define OS_INT_MPU_REGION_SIZE_ENABLE              (1UL     << 0)
/*  Region Attribute and Size Register c6: SIZE field. */
# define OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(x)     (((x) - 1) << 1)


/*  \brief  c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: --- User: ---. */
# define OS_INT_MPU_ACCESS_S_NONE_U_NONE              (0UL << 8)
/*  \brief   c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: RW- User: ---. */
# define OS_INT_MPU_ACCESS_S_RW_U_NONE                (1UL << 8)
/*  \brief   c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: RW- User: R--. */
# define OS_INT_MPU_ACCESS_S_RW_U_R                   (2UL << 8)
/*  \brief   c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: RW- User: RW-. */
# define OS_INT_MPU_ACCESS_S_RW_U_RW                  (3UL << 8)
/*  \brief   c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: R-- User: ---. */
# define OS_INT_MPU_ACCESS_S_R_U_NONE                 (5UL << 8)
/*  \brief   c6, MPU Region Access Control Register: AP value.
 *  \details Supervisor: R-- User: R--. */
# define OS_INT_MPU_ACCESS_S_R_U_R                    (6UL << 8)


/*  c6, MPU Region Access Control Register: S bit. */
# define OS_INT_MPU_ACCESS_SHAREABLE                (1UL << 2)


/*  c6, MPU Region Access Control Register: XN bit, allowed value. */
# define OS_INT_MPU_ACCESS_EXECUTE_ALLOWED          (0UL << 12)
/*  c6, MPU Region Access Control Register: XN bit, forbidden value. */
# define OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN        (1UL << 12)


/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Strongly ordered. */
# define OS_INT_MPU_ACCESS_TYPE_STRONGLY_ORDERED               ((0UL << 3) | (0UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Outer and inner Non-cacheable. */
#define OS_INT_MPU_ACCESS_TYPE_NON_CACHEABLE                     ((1UL << 3) | (0UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Outer and Inner Write-Back, Cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE   ((1UL << 3) | (3UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Shared device, Non-cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_SHARED_DEVICE                         ((0UL << 3) | (0UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Non-Shared device, Non-cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_NON_SHARED_DEVICE              ((2UL << 3) | (0UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Outer and inner write-through, no write allocate. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITETHROUGH_NO_ALLOCATE   ((0UL << 3) | (2UL << 0))
/*  \brief   c6, MPU Region Access Control Register : TEX[2:0],C,B values
 *  \details Outer and inner write-back, no write allocate. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_NO_ALLOCATE            ((0UL << 3) | (3UL << 0))


/*  \brief   Attributes and size for the maximum stack. */
# define OS_INT_MPU_STACK_MAXSIZE_AND_ATTRIBUTES  ((OS_INT_MPU_ACCESS_S_RW_U_RW)                         | \
                                                  (OS_INT_MPU_REGION_SIZE_ENABLE)                       | \
                                                  (OS_INT_MPU_ACCESS_EXECUTE_ALLOWED)                   | \
                                                  (OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE) | \
                                                  /*(OS_HAL_REGION_MAXSIZE)  */                           )


/*  c6, MPU Region Size and Enable Registers : Value for enable/disable Sub region. */
# define OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(x)               (x << 8)

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
