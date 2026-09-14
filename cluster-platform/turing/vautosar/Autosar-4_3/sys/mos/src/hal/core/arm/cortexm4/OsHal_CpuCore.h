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

#define OS_SYST_CSR                                    (*((volatile osuint32*)(0xE000E010U)))    
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
    osbool   IsExcFrameValid;  /**< IS Exception frame valid */
    osuint32 MMARErrAddress;   /**< MMAR Error address */
    osuint32 BFARErrAddress;   /**< MMAR Error address */
} ProtErrorInfoType;

typedef struct
{
      osuint32 RegnNumber;           /*  Region number (MPU_RNR). */
      osuint32 RegnBaseAddress;      /*  Region base address (MPU_RBAR). */
      osuint32 RegnSize;
      AccessType RegnAccess;
      osuint32 RegnAttribute; /*  Region attribute (MPU_RASR). */ 
      osuint32 RegnSizeAndEnable;    /* Sub region, size and enable value (MPU_RASR) */    
}OsIntMpuConfigType;


extern void OsCpuHal_EnableMPU (void);
extern osbool OsCpuHal_IsOsTrapRequired(void);
extern void OsCpuHal_ExitPrivilegeMode(void); 
extern osbool OsCpuHal_IsOsPrivilegeMode(void);

__asm osuint32 OsCpuHal_SaveDisableLevel (void)
{
    mrs r0,basepri
    mov r1, #16
    msr basepri,r1

}

__asm void OsCpuHal_RestoreLevel (osuint32 IntStatus)
{
%reg IntStatus  /* If the value is passed through register ie., r0*/
    msr basepri, IntStatus
%mem IntStatus  /* If Intstatus is through a memory, load it to reg and update basepri */
    ldr r6, IntStatus
    msr basepri,r6

}



extern void OsCpuHal_DisableMPU (void);
extern void OsCpuHal_MpuInitRegion (const OsIntMpuConfigType* const pMpuConfig);
extern void OsCpuHal_DisableGlobalMPU(void);
extern void OsCpuHal_EnableGlobalMPU(void);
extern osuint32 osGetPRIMASK(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern osuint32 osGetBASEPRI(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

extern void OsHal_Initialize (void);
extern void OsHalPrv_EnableIrqSource (osuint32 IrqSrc);
extern void OsHalPrv_DisableIrqSource (osuint32 IrqSrc);

void OsFaultHandler(osuint32 const *faultStackAddr);
void Os_ProcessingFault(void);

extern void OsHal_CpuTrap(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam);

#define OS_ARCH_INITIALIZE()                osIntArchInitialize();

#define OS_ARCH_SETUP_INTERRUPTS()          osSetupAndEnableConfiguredInterrupts();

#define OsCpuHal_MpuSwitch(x)       OsCpuHal_MpuInitRegion(x)

#define osIsGlobalIntEnabled()    ((osGetBASEPRI() & osdIntCfgMaxSystemPriority) == 0U)

#define BUS_MEM_USAGE_FAULT_ENABLE   0x70000uL

/* Interrupt Control State Register (ICSR) */
# define OS_HAL_ICSR_ADDR       (*(volatile osuint32*) (0xE000ED04UL))

/*  ICSR Regiter: PENDSTSET bit mask.
 *  SysTick exception set-pending bit
 *  Read:
 *  0 = SysTick exception is not pending
 *  1 = SysTick exception is pending.
 */
# define OS_HAL_ICSR_PENDSTSET_BIT (1UL << 26)

# define OS_INT_MPU_MPU_BASE    (0xE000ED90UL)

/*  MPU Type Register (MPU_TYPE). */
# define OS_INT_MPU_MPU_TYPE    (*(volatile uint32*) (OS_INT_MPU_MPU_BASE +  0x0UL))

/*  MPU Control Register (MPU_CTRL). */
# define OS_INT_MPU_MPU_CTRL    (*(volatile uint32*) (OS_INT_MPU_MPU_BASE +  0x4UL))

/*  MPU Region Number Register (MPU_RNR). */
# define OS_INT_MPU_MPU_RNR     (*(volatile uint32*) (OS_INT_MPU_MPU_BASE +  0x8UL))

/*  MPU Region Base Address Register (MPU_RBAR). */
# define OS_INT_MPU_MPU_RBAR    (*(volatile uint32*) (OS_INT_MPU_MPU_BASE +  0xCUL))

/*  MPU Region Attribute and Size Register (MPU_RASR). */
# define OS_INT_MPU_MPU_RASR    (*(volatile uint32*) (OS_INT_MPU_MPU_BASE + 0x10UL))

/*  MPU Control Register, MPU active. */
# define OS_INT_MPU_MPU_CTRL_ENABLE     (1UL << 0)
/*  MPU Control Register, MPU active in HardFault and NMIs. */
# define OS_INT_MPU_MPU_CTRL_HFNMIENA   (1UL << 1)

/*  Region Attribute and Size Register (MPU_RASR): Value to use for a disabled region. */
# define OS_INT_MPU_REGION_DISABLED_VALUE           (0UL)
/*  Region Attribute and Size Register (MPU_RASR): MPU_RASR.ENABLE bit. */
# define OS_INT_MPU_REGION_SIZE_ENABLE              (1UL     << 0)
/*  Region Attribute and Size Register (MPU_RASR): MPU_RASR.SIZE field. */
# define OS_INT_MPU_REGION_SIZE_POWER_OF_TWO(x)     (((x) - 1) << 1)                                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*  Region Attribute and Size Register (MPU_RASR): MPU_RASR.S bit. */
# define OS_INT_MPU_ACCESS_SHAREABLE                (1UL << 18)
/*  Region Attribute and Size Register (MPU_RASR): MPU_RASR.XN bit, allowed value. */
# define OS_INT_MPU_ACCESS_EXECUTE_ALLOWED          (0UL << 28)
/*  Region Attribute and Size Register (MPU_RASR): MPU_RASR.XN bit, forbidden value. */
# define OS_INT_MPU_ACCESS_EXECUTE_FORBIDDEN        (1UL << 28)

/*  \brief  Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: --- User: ---. */
# define OS_INT_MPU_ACCESS_S_NONE_U_NONE              (0UL << 24)
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: RW- User: ---. */
# define OS_INT_MPU_ACCESS_S_RW_U_NONE                (1UL << 24)
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: RW- User: R--. */
# define OS_INT_MPU_ACCESS_S_RW_U_R                   (2UL << 24)
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: RW- User: RW-. */
# define OS_INT_MPU_ACCESS_S_RW_U_RW                  (3UL << 24)
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: R-- User: ---. */
# define OS_INT_MPU_ACCESS_S_R_U_NONE                 (5UL << 24)
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.AP value.
 *  \details Supervisor: R-- User: R--. */
# define OS_INT_MPU_ACCESS_S_R_U_R                    (6UL << 24)

/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Strongly ordered. */
# define OS_INT_MPU_ACCESS_TYPE_STRONGLY_ORDERED               ((0UL << 19) | (0UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Outer and inner Non-cacheable. */
#define OS_INT_MPU_ACCESS_TYPE_NON_CACHEABLE                     ((1UL << 19) | (0UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Outer and Inner Write-Back, Cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE   ((1UL << 19) | (3UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Shared device, Non-cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_SHARED_DEVICE                         ((0UL << 19) | (1UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Non-Shared device, Non-cacheable. */
# define OS_INT_MPU_ACCESS_TYPE_NON_SHARED_DEVICE              ((2UL << 19) | (0UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Outer and inner write-through, no write allocate. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITETHROUGH_NO_ALLOCATE   ((0UL << 19) | (2UL << 16))
/*  \brief   Region Attribute and Size Register (MPU_RASR): MPU_RASR.C,B and TEX value
 *  \details Outer and inner write-back, no write allocate. */
# define OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_NO_ALLOCATE            ((0UL << 19) | (3UL << 16))
/*  \brief   Attributes and size for the maximum stack. */
# define OS_INT_MPU_STACK_MAXSIZE_AND_ATTRIBUTES  ((OS_INT_MPU_ACCESS_S_RW_U_RW)                         | \
                                                  (OS_INT_MPU_REGION_SIZE_ENABLE)                       | \
                                                  (OS_INT_MPU_ACCESS_EXECUTE_ALLOWED)                   | \
                                                  (OS_INT_MPU_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE) | \
                                                  /*(OS_HAL_REGION_MAXSIZE)  */                           )

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
