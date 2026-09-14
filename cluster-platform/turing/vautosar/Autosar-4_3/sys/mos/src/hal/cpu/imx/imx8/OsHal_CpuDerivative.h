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
*  File Name         :  OsHal_CpuDerivative.h                                *
*  Module Short Name :  OsHal_CpuDerivative                                  *
*  Description       :  Internal header which has cpu specific definitions   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  INDEPENDENT                                            *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_HAL_PROCESSOR_H
#define OS_HAL_PROCESSOR_H

#include "OsTypes.h"

typedef struct
{
    osuint16 osIrqNum;
    osIntLevelType osPrioLevel;
    osVoidFunctionType pIsr;
}osIntIrqChn_t;

typedef struct {
    volatile osuint32 CHANnCTL;                          /**< Channel n Control Register, offset: 0x0 */
    volatile osuint32 CHn_MASK[16];                      /**< Channel n Interrupt Mask Register, offset: 0x4 */
    volatile osuint32 CHn_SET[16];                       /**< Channel n Interrupt Set Register, offset: 0x44 */
    volatile const  osuint32 CHn_STATUS[16];                    /**< Channel n Interrupt Status Register, offset: 0x84 */
    volatile osuint32 CHn_MINTDIS;                       /**< Channel n Master Interrupt Disable Register, offset: 0xC4 */
    volatile const osuint32 CHn_MSTRSTAT;                      /**< Channel n Master Status Register, offset: 0xC8 */
} IRQSTEER_Type;

typedef enum
{
    eOsInterruptChn0, /*!< Interrupt Master 0: interrupt source 63 - 0 */
    eOsInterruptChn1, /*!< Interrupt Master 1: interrupt source 127 - 64 */
    eOsInterruptChn2, /*!< Interrupt Master 2: interrupt source 191 - 128 */
    eOsInterruptChn3, /*!< Interrupt Master 3: interrupt source 255 - 192 */
    eOsInterruptChn4, /*!< Interrupt Master 4: interrupt source 319 - 256 */
    eOsInterruptChn5, /*!< Interrupt Master 5: interrupt source 383 - 320 */
    eOsInterruptChn6, /*!< Interrupt Master 6: interrupt source 447 - 384 */
    eOsInterruptChn7, /*!< Interrupt Master 7: interrupt source 511 - 448 */
} EOsIntChn_t;

typedef struct
{
  volatile  osuint32 CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile const osuint32 ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile const osuint32 VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile const osuint32 AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile const osuint32 SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile const osuint32 CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile const osuint8  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile const osuint32 SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile const osuint32 CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile const osuint32 HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile const osuint32 DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile const osuint32 MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile const osuint32 BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile const osuint32 AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  volatile  osuint32 PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  volatile  osuint32 DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  volatile  osuint32 ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  volatile  osuint32 MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  volatile  osuint32 ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  osuint32 RESERVED0[5U];
  volatile osuint32 CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_Type;

/**
  \brief  Structure type to access the Floating Point Unit (FPU).
 */
typedef struct
{
                  osuint32 RESERVED0[1U];
  volatile        osuint32 FPCCR;                  /*!< Offset: 0x004 (R/W)  Floating-Point Context Control Register */
  volatile        osuint32 FPCAR;                  /*!< Offset: 0x008 (R/W)  Floating-Point Context Address Register */
  volatile        osuint32 FPDSCR;                 /*!< Offset: 0x00C (R/W)  Floating-Point Default Status Control Register */
  volatile const  osuint32 MVFR0;                  /*!< Offset: 0x010 (R/ )  Media and FP Feature Register 0 */
  volatile const  osuint32 MVFR1;                  /*!< Offset: 0x014 (R/ )  Media and FP Feature Register 1 */
} FPU_Type;

/* Floating-Point Context Control Register Definitions */
#define FPU_FPCCR_LSPEN_Pos                30U                                            /*!< FPCCR: LSPEN Position */
#define FPU_FPCCR_LSPEN_Msk                (1UL << FPU_FPCCR_LSPEN_Pos)                   /*!< FPCCR: LSPEN bit Mask */

/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */
#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
#define FPU_BASE            (SCS_BASE +  0x0F30UL)                    /*!< Floating Point Unit */
#define FPU                 ((FPU_Type       *)     FPU_BASE      )   /*!< Floating Point Unit */

/* IRQSTEER - Peripheral instance base addresses */
/** Peripheral IRQSTEER base address */
#define IRQSTEER_BASE                              (0x51070000u)
/** Peripheral IRQSTEER base pointer */
#define IRQSTEER                                   ((IRQSTEER_Type *)IRQSTEER_BASE)

#define OS_INT_NVIC_SHPR1_REG                   ( * ( ( volatile osuint32 * ) 0xe000e018 ) )
#define OS_INT_NVIC_SHPR2_REG                   ( * ( ( volatile osuint32 * ) 0xe000e01C ) )
#define OS_INT_NVIC_SHPR3_REG                   ( * ( ( volatile osuint32 * ) 0xe000ed20 ) )

#define osdIntCfgNvicSHPRI1                     0UL
#define osdIntCfgNvicSHPRI2                     0UL
#define osdIntCfgNvicSHPRI3                     (osdIntCfgKernelPriority << 24UL)

#define osdIntCfgKernelPriority                 0x80UL

#define osdIntCfgMaxSystemPriority              0x20UL

#define M4_EXT_INTR0 32
#define M4_EXT_INTR1 33
#define M4_EXT_INTR2 34
#define M4_EXT_INTR3 35

#define REG_READ32(address)               (*(volatile uint32*)(address))
#define REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (value))

#define FSL_FEATURE_IRQSTEER_CHn_MASK_COUNT 16U

#define FSL_FEATURE_IRQSTEER_IRQ_START_INDEX 51U  //todo - needs analysis

/*! @brief IRQSTEER interrupt source register width. */
#define IRQSTEER_INT_SRC_REG_WIDTH 32U

/*! @brief IRQSTEER interrupt source mapping register index. */
#define IRQSTEER_INT_SRC_REG_INDEX(irq) \
    ((FSL_FEATURE_IRQSTEER_CHn_MASK_COUNT - 1U) - ((irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX) / IRQSTEER_INT_SRC_REG_WIDTH))

/*! @brief IRQSTEER interrupt source mapping bit offset. */
#define IRQSTEER_INT_SRC_BIT_OFFSET(irq) ((irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX) % IRQSTEER_INT_SRC_REG_WIDTH)

/*! @brief IRQSTEER interrupt source number. */
#define IRQSTEER_INT_SRC_NUM(regIndex, bitOffset) \
    (((FSL_FEATURE_IRQSTEER_CHn_MASK_COUNT - 1U - (regIndex)) * IRQSTEER_INT_SRC_REG_WIDTH) + (bitOffset))

#define osSYST_BASE        (*((volatile osuint32*)(0xE000E010))) /* System Timer Register Base Address */
#define osSYST_CSR         (*((volatile osuint32*)(0xE000E010))) /* System Timer Control & Status Register Address */
#define osSYST_RVR         (*((volatile osuint32*)(0xE000E014))) /* System Timer Reload Value Register Address */
#define osSYST_CVR         (*((volatile osuint32*)(0xE000E018))) /* System Timer Current Value Register Address */
#define osSYST_CALIB       (*((volatile osuint32*)(0xE000E01C))) /* System Timer Calibration Value Register Address */

/* Timer Interrupt call hook */
#define osIntIsrCallHook()

#define OsHal_CpuStartOS(x)                     __asm ("ldr        r0,=osStartOSasmArm "); \
                                                __asm ("bx         r0                  "); \

/* Os APIs for Enable Interrupt Source */
extern StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending);
/* Os APIs for Disable Interrupt Source */
extern StatusType OsHal_DisableInterruptSource(ISRType ISRID);

extern void OsHalPrv_osInitSystemInterruptPriority (void);
extern void osStartArchTimer (void);
extern void osIntArchInitialize (void);
extern void osSetupAndEnableConfiguredInterrupts (void);
extern void osSetupExceptionStacks(void); /* Setup all ARM stacks except user mode stack and system mode stack */
extern osuint32 osGetCPSR(void);
extern void osSetBitsARMCoreSCTLR(osuint32 BitsToSet);
extern void osEnableNMIandAborts(void);
extern void osInternal_IRQSTEER_CommonIRQHandler(EOsIntChn_t EOsIntChn);
extern void OsInt_SetupInterrupt (const osIntIrqChn_t * const pThisIrqParam);
extern void OsHal_CheckIntrPending(void);

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
**   Date              : 27-Jul-2022                                                **
**   CDSID             : rsivaku4                                                   **
**   RTC Id            : 1709142                                                    **
**   Change Description: MPU nesting prevention and Moving Internal.c to HAL        **
**----------------------------------------------------------------------------------**/

