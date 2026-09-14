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
*  File Name         :  OsInternal.h                                         *
*  Module Short Name :  mOS internal header for OsAsm                        *
*  Description       :  external declarations (only for system internal use) *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS (stringent relation with macros  populated below)  *
* Target Hardware  :  ARM Cortex M4 series (stringent relation with macros)  *
*                                                                            *
******************************************************************************/
#ifndef OS_INTERNAL_H
#define OS_INTERNAL_H



#define OsNumberOfRxMessages 0
/*---------------------------------------------------------------**
** This file would be a generated file for architecture specific **
**---------------------------------------------------------------*/
#define osqStack1
#define osqStack2
#define osqStack3

#include "intvect.h"
#include "OsStacks_Lcfg.h"
#include "Reg_eSys_IrqSteer.h"
#include "nvic.h"

#define OS_INTERNAL_FPU_ENABLED           STD_ON

#define MOS_API_MPU_SWITCH_ENABLE         STD_OFF

#define MOS_ENABLE_DISABLE_ISR_API        STD_OFF

#define mOS_SUPPORT_INTERNAL_METRICS      STD_OFF

#define OS_CORE_0_OS_ACCESS_ID            0U

#define IMXRT_SYS_TIMER

/*---------------------------------------------------------------**
**             Non-Configurable Parameters - Start               **
**---------------------------------------------------------------*/

#define INVALID_TASK        0xFF
#define INVALID_PRIORITY    0xFF

#define TASK_NONPREEMPTIVE      0
#define TASK_PREEMPTIVE         1

#define ALARM_CALLBACK_ACTION       1
#define ALARM_ACTIVATE_TASK_ACTION  2
#define ALARM_SET_EVENT_ACTION      3

#define M4_EXT_INTR0 32
#define M4_EXT_INTR1 33
#define M4_EXT_INTR2 34
#define M4_EXT_INTR3 35

#define TASK_BASIC      0
#define TASK_EXTENDED         1
#define BUS_MEM_USAGE_FAULT_ENABLE   0x70000uL

#define osStackSizeOfNonPreemptiveTask      sizeof(osSystemStack)


#define osdStackCheck                       1
#define osdStackUsageMeasurement            1
#define osdStackCheckPattern                0xaaaaaaaaUL

#define osdUsedSystemTimer                  osdReloadTimer_Ch0

#define osSystemSWCounter                   OsCounter_0
#define SystemTimer                         OsCounter_0
#define ScheduleTableTimer                  OsCounter_1

#define OSMAXALLOWEDVALUE                   (0xffffffffUL)

/*---------------------------------------------------------------**
**             Non-Configurable Parameters - End               **
**---------------------------------------------------------------*/

#define OsNumberOfStack             3

#define osOffsetOfActiveTaskIndex           0
#define osOffsetOfRequestedTaskIndex        1
#define osOffsetOfActiveTaskPriority        2
#define osOffsetOfRequestedTaskPriority     3
#define osOffsetOfTaskPriorityBits          4
#define osOffsetOfRequestScheduler          6
#define osOffsetOfLockDispatcher            7
#define osOffsetOfIntSaveDisableRequestCounter        8
#define osOffsetOfIntSaveStatus                       9


#define osOffsetOfTaskState                 0
#define osOffsetOfStackAddress              2  //as stack address is a osuint16, compiler inserts padding for TaskState
//#define osSizeOfTaskParamStructure          4

#define osOffsetOfTaskStartAddress          0
#define osOffsetOfTaskStackStartAddress     4
#define osOffsetOfTaskStackSize             6
#define osOffsetOfTaskPriority              8
#define osOffsetOfTaskCategory              9
//#define osSizeOfTcbConfigStructure          10

typedef struct {
  volatile osuint32 CHANnCTL;                          /**< Channel n Control Register, offset: 0x0 */
  volatile osuint32 CHn_MASK[16];                      /**< Channel n Interrupt Mask Register, offset: 0x4 */
  volatile osuint32 CHn_SET[16];                       /**< Channel n Interrupt Set Register, offset: 0x44 */
  volatile const  osuint32 CHn_STATUS[16];                    /**< Channel n Interrupt Status Register, offset: 0x84 */
  volatile osuint32 CHn_MINTDIS;                       /**< Channel n Master Interrupt Disable Register, offset: 0xC4 */
  volatile const osuint32 CHn_MSTRSTAT;                      /**< Channel n Master Status Register, offset: 0xC8 */
} IRQSTEER_Type;


#define OS_INT_NVIC_SHPR1_REG                   ( * ( ( volatile osuint32 * ) 0xe000e018 ) )
#define OS_INT_NVIC_SHPR2_REG                   ( * ( ( volatile osuint32 * ) 0xe000e01C ) )
#define OS_INT_NVIC_SHPR3_REG                   ( * ( ( volatile osuint32 * ) 0xe000ed20 ) )

#define osdIntCfgNvicSHPRI1                     0UL
#define osdIntCfgNvicSHPRI2                     0UL
#define osdIntCfgNvicSHPRI3                     (osdIntCfgKernelPriority << 24UL)
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
        osuint32 RESERVED0[1U];
  volatile  osuint32 ICTR;                   /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
  volatile const osuint32 ACTLR;                  /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
} SCnSCB_Type;


typedef struct
{
  volatile  osuint32 CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile const osuint32 ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile const osuint32 VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile const osuint32 AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile const osuint32 SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile const osuint32 CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile const uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
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


typedef struct
{
  volatile const osuint32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile const osuint32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile const osuint32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile const  osuint32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;



/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  volatile const osuint32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        osuint32 RESERVED0[24U];
  volatile const osuint32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        osuint32 RSERVED1[24U];
  volatile const osuint32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        osuint32 RESERVED2[24U];
  volatile const osuint32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        osuint32 RESERVED3[24U];
  volatile const osuint32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        osuint32 RESERVED4[56U];
  volatile const uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        osuint32 RESERVED5[644U];
  volatile  osuint32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;


/**
  \brief  Structure type to access the Instrumentation Trace Macrocell Register (ITM).
 */
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                 /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 8-bit */
    volatile  uint16_t   u16;                /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 16-bit */
    volatile  osuint32   u32;                /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 32-bit */
  }  PORT [32U];                         /*!< Offset: 0x000 ( /W)  ITM Stimulus Port Registers */
        osuint32 RESERVED0[864U];
  volatile const osuint32 TER;                    /*!< Offset: 0xE00 (R/W)  ITM Trace Enable Register */
        osuint32 RESERVED1[15U];
  volatile const osuint32 TPR;                    /*!< Offset: 0xE40 (R/W)  ITM Trace Privilege Register */
        osuint32 RESERVED2[15U];
  volatile const osuint32 TCR;                    /*!< Offset: 0xE80 (R/W)  ITM Trace Control Register */
        osuint32 RESERVED3[29U];
  volatile  osuint32 IWR;                    /*!< Offset: 0xEF8 ( /W)  ITM Integration Write Register */
  volatile const  osuint32 IRR;                    /*!< Offset: 0xEFC (R/ )  ITM Integration Read Register */
  volatile const osuint32 IMCR;                   /*!< Offset: 0xF00 (R/W)  ITM Integration Mode Control Register */
        osuint32 RESERVED4[43U];
  volatile  osuint32 LAR;                    /*!< Offset: 0xFB0 ( /W)  ITM Lock Access Register */
  volatile const  osuint32 LSR;                    /*!< Offset: 0xFB4 (R/ )  ITM Lock Status Register */
        osuint32 RESERVED5[6U];
  volatile const  osuint32 PID4;                   /*!< Offset: 0xFD0 (R/ )  ITM Peripheral Identification Register #4 */
  volatile const  osuint32 PID5;                   /*!< Offset: 0xFD4 (R/ )  ITM Peripheral Identification Register #5 */
  volatile const  osuint32 PID6;                   /*!< Offset: 0xFD8 (R/ )  ITM Peripheral Identification Register #6 */
  volatile const  osuint32 PID7;                   /*!< Offset: 0xFDC (R/ )  ITM Peripheral Identification Register #7 */
  volatile const  osuint32 PID0;                   /*!< Offset: 0xFE0 (R/ )  ITM Peripheral Identification Register #0 */
  volatile const  osuint32 PID1;                   /*!< Offset: 0xFE4 (R/ )  ITM Peripheral Identification Register #1 */
  volatile const  osuint32 PID2;                   /*!< Offset: 0xFE8 (R/ )  ITM Peripheral Identification Register #2 */
  volatile const  osuint32 PID3;                   /*!< Offset: 0xFEC (R/ )  ITM Peripheral Identification Register #3 */
  volatile const  osuint32 CID0;                   /*!< Offset: 0xFF0 (R/ )  ITM Component  Identification Register #0 */
  volatile const  osuint32 CID1;                   /*!< Offset: 0xFF4 (R/ )  ITM Component  Identification Register #1 */
  volatile const  osuint32 CID2;                   /*!< Offset: 0xFF8 (R/ )  ITM Component  Identification Register #2 */
  volatile const  osuint32 CID3;                   /*!< Offset: 0xFFC (R/ )  ITM Component  Identification Register #3 */
} ITM_Type;


/**
  \brief  Structure type to access the Data Watchpoint and Trace Register (DWT).
 */
typedef struct
{
  volatile const osuint32 CTRL;                   /*!< Offset: 0x000 (R/W)  Control Register */
  volatile const osuint32 CYCCNT;                 /*!< Offset: 0x004 (R/W)  Cycle Count Register */
  volatile const osuint32 CPICNT;                 /*!< Offset: 0x008 (R/W)  CPI Count Register */
  volatile const osuint32 EXCCNT;                 /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
  volatile const osuint32 SLEEPCNT;               /*!< Offset: 0x010 (R/W)  Sleep Count Register */
  volatile const osuint32 LSUCNT;                 /*!< Offset: 0x014 (R/W)  LSU Count Register */
  volatile const osuint32 FOLDCNT;                /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
  volatile const  osuint32 PCSR;                   /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
  volatile const osuint32 COMP0;                  /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
  volatile const osuint32 MASK0;                  /*!< Offset: 0x024 (R/W)  Mask Register 0 */
  volatile const osuint32 FUNCTION0;              /*!< Offset: 0x028 (R/W)  Function Register 0 */
        osuint32 RESERVED0[1U];
  volatile const osuint32 COMP1;                  /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
  volatile const osuint32 MASK1;                  /*!< Offset: 0x034 (R/W)  Mask Register 1 */
  volatile const osuint32 FUNCTION1;              /*!< Offset: 0x038 (R/W)  Function Register 1 */
        osuint32 RESERVED1[1U];
  volatile const osuint32 COMP2;                  /*!< Offset: 0x040 (R/W)  Comparator Register 2 */
  volatile const osuint32 MASK2;                  /*!< Offset: 0x044 (R/W)  Mask Register 2 */
  volatile const osuint32 FUNCTION2;              /*!< Offset: 0x048 (R/W)  Function Register 2 */
        osuint32 RESERVED2[1U];
  volatile const osuint32 COMP3;                  /*!< Offset: 0x050 (R/W)  Comparator Register 3 */
  volatile const osuint32 MASK3;                  /*!< Offset: 0x054 (R/W)  Mask Register 3 */
  volatile const osuint32 FUNCTION3;              /*!< Offset: 0x058 (R/W)  Function Register 3 */
} DWT_Type;


/**
  \brief  Structure type to access the Trace Port Interface Register (TPI).
 */
typedef struct
{
  volatile const osuint32 SSPSR;                  /*!< Offset: 0x000 (R/ )  Supported Parallel Port Size Register */
  volatile const osuint32 CSPSR;                  /*!< Offset: 0x004 (R/W)  Current Parallel Port Size Register */
        osuint32 RESERVED0[2U];
  volatile const osuint32 ACPR;                   /*!< Offset: 0x010 (R/W)  Asynchronous Clock Prescaler Register */
        osuint32 RESERVED1[55U];
  volatile const osuint32 SPPR;                   /*!< Offset: 0x0F0 (R/W)  Selected Pin Protocol Register */
        osuint32 RESERVED2[131U];
  volatile const  osuint32 FFSR;                   /*!< Offset: 0x300 (R/ )  Formatter and Flush Status Register */
  volatile const osuint32 FFCR;                   /*!< Offset: 0x304 (R/W)  Formatter and Flush Control Register */
  volatile const  osuint32 FSCR;                   /*!< Offset: 0x308 (R/ )  Formatter Synchronization Counter Register */
        osuint32 RESERVED3[759U];
  volatile const  osuint32 TRIGGER;                /*!< Offset: 0xEE8 (R/ )  TRIGGER */
  volatile const  osuint32 FIFO0;                  /*!< Offset: 0xEEC (R/ )  Integration ETM Data */
  volatile const  osuint32 ITATBCTR2;              /*!< Offset: 0xEF0 (R/ )  ITATBCTR2 */
        osuint32 RESERVED4[1U];
  volatile const  osuint32 ITATBCTR0;              /*!< Offset: 0xEF8 (R/ )  ITATBCTR0 */
  volatile const  osuint32 FIFO1;                  /*!< Offset: 0xEFC (R/ )  Integration ITM Data */
  volatile const osuint32 ITCTRL;                 /*!< Offset: 0xF00 (R/W)  Integration Mode Control */
        osuint32 RESERVED5[39U];
  volatile const osuint32 CLAIMSET;               /*!< Offset: 0xFA0 (R/W)  Claim tag set */
  volatile const osuint32 CLAIMCLR;               /*!< Offset: 0xFA4 (R/W)  Claim tag clear */
        osuint32 RESERVED7[8U];
  volatile const  osuint32 DEVID;                  /*!< Offset: 0xFC8 (R/ )  TPIU_DEVID */
  volatile const  osuint32 DEVTYPE;                /*!< Offset: 0xFCC (R/ )  TPIU_DEVTYPE */
} TPI_Type;


/**
  \brief  Structure type to access the Core Debug Register (CoreDebug).
 */
typedef struct
{
  volatile const osuint32 DHCSR;                  /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register */
  volatile  osuint32 DCRSR;                  /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register */
  volatile const osuint32 DCRDR;                  /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register */
  volatile const osuint32 DEMCR;                  /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
} CoreDebug_Type;

#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)
/**
  \brief  Structure type to access the Memory Protection Unit (MPU).
 */
#if 0
typedef struct
{
  volatile const  osuint32 TYPE;                   /*!< Offset: 0x000 (R/ )  MPU Type Register */
  volatile const osuint32 CTRL;                   /*!< Offset: 0x004 (R/W)  MPU Control Register */
  volatile const osuint32 RNR;                    /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register */
  volatile const osuint32 RBAR;                   /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
  volatile const osuint32 RASR;                   /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register */
  volatile const osuint32 RBAR_A1;                /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register */
  volatile const osuint32 RASR_A1;                /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
  volatile const osuint32 RBAR_A2;                /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register */
  volatile const osuint32 RASR_A2;                /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
  volatile const osuint32 RBAR_A3;                /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register */
  volatile const osuint32 RASR_A3;                /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} MPU_Type;
#endif
#endif


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
    


/* IRQSTEER - Peripheral instance base addresses */
/** Peripheral IRQSTEER base address */
#define IRQSTEER_BASE                              (0x51070000u)
/** Peripheral IRQSTEER base pointer */
#define IRQSTEER                                   ((IRQSTEER_Type *)IRQSTEER_BASE)
/** Array initializer of IRQSTEER peripheral base addresses */
#define IRQSTEER_BASE_ADDRS                        { IRQSTEER_BASE }
/** Array initializer of IRQSTEER peripheral base pointers */
#define IRQSTEER_BASE_PTRS                         { IRQSTEER }


/* Vector Table Offset Register (VTOR). */
# define OS_INT_INTC_SCB_VTOR        (*(volatile uint32*) (0xE000ED08UL))

/* Software Triggered Interrupt Register (STIR). */
# define OS_INT_INTC_STIR            (*(volatile uint32*) (0xE000EF00UL))

/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */

#define SCnSCB              ((SCnSCB_Type    *)     SCS_BASE      )   /*!< System control Register not in SCB */
#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */
#define ITM                 ((ITM_Type       *)     ITM_BASE      )   /*!< ITM configuration struct */
#define DWT                 ((DWT_Type       *)     DWT_BASE      )   /*!< DWT configuration struct */
#define TPI                 ((TPI_Type       *)     TPI_BASE      )   /*!< TPI configuration struct */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< Core Debug configuration struct */

#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)
  #define MPU_BASE          (SCS_BASE +  0x0D90UL)                    /*!< Memory Protection Unit */
  #define MPU               ((MPU_Type       *)     MPU_BASE      )   /*!< Memory Protection Unit */
#endif



/* FPU Registers Abstraction */

/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_FPU     Floating Point Unit (FPU)
  \brief    Type definitions for the Floating Point Unit (FPU)
  @{
 */

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
#define FPU_FPCCR_ASPEN_Pos                31U                                            /*!< FPCCR: ASPEN bit Position */
#define FPU_FPCCR_ASPEN_Msk                (1UL << FPU_FPCCR_ASPEN_Pos)                   /*!< FPCCR: ASPEN bit Mask */

#define FPU_FPCCR_LSPEN_Pos                30U                                            /*!< FPCCR: LSPEN Position */
#define FPU_FPCCR_LSPEN_Msk                (1UL << FPU_FPCCR_LSPEN_Pos)                   /*!< FPCCR: LSPEN bit Mask */

#define FPU_FPCCR_MONRDY_Pos                8U                                            /*!< FPCCR: MONRDY Position */
#define FPU_FPCCR_MONRDY_Msk               (1UL << FPU_FPCCR_MONRDY_Pos)                  /*!< FPCCR: MONRDY bit Mask */

#define FPU_FPCCR_BFRDY_Pos                 6U                                            /*!< FPCCR: BFRDY Position */
#define FPU_FPCCR_BFRDY_Msk                (1UL << FPU_FPCCR_BFRDY_Pos)                   /*!< FPCCR: BFRDY bit Mask */

#define FPU_FPCCR_MMRDY_Pos                 5U                                            /*!< FPCCR: MMRDY Position */
#define FPU_FPCCR_MMRDY_Msk                (1UL << FPU_FPCCR_MMRDY_Pos)                   /*!< FPCCR: MMRDY bit Mask */

#define FPU_FPCCR_HFRDY_Pos                 4U                                            /*!< FPCCR: HFRDY Position */
#define FPU_FPCCR_HFRDY_Msk                (1UL << FPU_FPCCR_HFRDY_Pos)                   /*!< FPCCR: HFRDY bit Mask */

#define FPU_FPCCR_THREAD_Pos                3U                                            /*!< FPCCR: processor mode bit Position */
#define FPU_FPCCR_THREAD_Msk               (1UL << FPU_FPCCR_THREAD_Pos)                  /*!< FPCCR: processor mode active bit Mask */

#define FPU_FPCCR_USER_Pos                  1U                                            /*!< FPCCR: privilege level bit Position */
#define FPU_FPCCR_USER_Msk                 (1UL << FPU_FPCCR_USER_Pos)                    /*!< FPCCR: privilege level bit Mask */

#define FPU_FPCCR_LSPACT_Pos                0U                                            /*!< FPCCR: Lazy state preservation active bit Position */
#define FPU_FPCCR_LSPACT_Msk               (1UL /*<< FPU_FPCCR_LSPACT_Pos*/)              /*!< FPCCR: Lazy state preservation active bit Mask */

/* Floating-Point Context Address Register Definitions */
#define FPU_FPCAR_ADDRESS_Pos               3U                                            /*!< FPCAR: ADDRESS bit Position */
#define FPU_FPCAR_ADDRESS_Msk              (0x1FFFFFFFUL << FPU_FPCAR_ADDRESS_Pos)        /*!< FPCAR: ADDRESS bit Mask */

/* Floating-Point Default Status Control Register Definitions */
#define FPU_FPDSCR_AHP_Pos                 26U                                            /*!< FPDSCR: AHP bit Position */
#define FPU_FPDSCR_AHP_Msk                 (1UL << FPU_FPDSCR_AHP_Pos)                    /*!< FPDSCR: AHP bit Mask */

#define FPU_FPDSCR_DN_Pos                  25U                                            /*!< FPDSCR: DN bit Position */
#define FPU_FPDSCR_DN_Msk                  (1UL << FPU_FPDSCR_DN_Pos)                     /*!< FPDSCR: DN bit Mask */

#define FPU_FPDSCR_FZ_Pos                  24U                                            /*!< FPDSCR: FZ bit Position */
#define FPU_FPDSCR_FZ_Msk                  (1UL << FPU_FPDSCR_FZ_Pos)                     /*!< FPDSCR: FZ bit Mask */

#define FPU_FPDSCR_RMode_Pos               22U                                            /*!< FPDSCR: RMode bit Position */
#define FPU_FPDSCR_RMode_Msk               (3UL << FPU_FPDSCR_RMode_Pos)                  /*!< FPDSCR: RMode bit Mask */

/* Media and FP Feature Register 0 Definitions */
#define FPU_MVFR0_FP_rounding_modes_Pos    28U                                            /*!< MVFR0: FP rounding modes bits Position */
#define FPU_MVFR0_FP_rounding_modes_Msk    (0xFUL << FPU_MVFR0_FP_rounding_modes_Pos)     /*!< MVFR0: FP rounding modes bits Mask */

#define FPU_MVFR0_Short_vectors_Pos        24U                                            /*!< MVFR0: Short vectors bits Position */
#define FPU_MVFR0_Short_vectors_Msk        (0xFUL << FPU_MVFR0_Short_vectors_Pos)         /*!< MVFR0: Short vectors bits Mask */

#define FPU_MVFR0_Square_root_Pos          20U                                            /*!< MVFR0: Square root bits Position */
#define FPU_MVFR0_Square_root_Msk          (0xFUL << FPU_MVFR0_Square_root_Pos)           /*!< MVFR0: Square root bits Mask */

#define FPU_MVFR0_Divide_Pos               16U                                            /*!< MVFR0: Divide bits Position */
#define FPU_MVFR0_Divide_Msk               (0xFUL << FPU_MVFR0_Divide_Pos)                /*!< MVFR0: Divide bits Mask */

#define FPU_MVFR0_FP_excep_trapping_Pos    12U                                            /*!< MVFR0: FP exception trapping bits Position */
#define FPU_MVFR0_FP_excep_trapping_Msk    (0xFUL << FPU_MVFR0_FP_excep_trapping_Pos)     /*!< MVFR0: FP exception trapping bits Mask */

#define FPU_MVFR0_Double_precision_Pos      8U                                            /*!< MVFR0: Double-precision bits Position */
#define FPU_MVFR0_Double_precision_Msk     (0xFUL << FPU_MVFR0_Double_precision_Pos)      /*!< MVFR0: Double-precision bits Mask */

#define FPU_MVFR0_Single_precision_Pos      4U                                            /*!< MVFR0: Single-precision bits Position */
#define FPU_MVFR0_Single_precision_Msk     (0xFUL << FPU_MVFR0_Single_precision_Pos)      /*!< MVFR0: Single-precision bits Mask */

#define FPU_MVFR0_A_SIMD_registers_Pos      0U                                            /*!< MVFR0: A_SIMD registers bits Position */
#define FPU_MVFR0_A_SIMD_registers_Msk     (0xFUL /*<< FPU_MVFR0_A_SIMD_registers_Pos*/)  /*!< MVFR0: A_SIMD registers bits Mask */

/* Media and FP Feature Register 1 Definitions */
#define FPU_MVFR1_FP_fused_MAC_Pos         28U                                            /*!< MVFR1: FP fused MAC bits Position */
#define FPU_MVFR1_FP_fused_MAC_Msk         (0xFUL << FPU_MVFR1_FP_fused_MAC_Pos)          /*!< MVFR1: FP fused MAC bits Mask */

#define FPU_MVFR1_FP_HPFP_Pos              24U                                            /*!< MVFR1: FP HPFP bits Position */
#define FPU_MVFR1_FP_HPFP_Msk              (0xFUL << FPU_MVFR1_FP_HPFP_Pos)               /*!< MVFR1: FP HPFP bits Mask */

#define FPU_MVFR1_D_NaN_mode_Pos            4U                                            /*!< MVFR1: D_NaN mode bits Position */
#define FPU_MVFR1_D_NaN_mode_Msk           (0xFUL << FPU_MVFR1_D_NaN_mode_Pos)            /*!< MVFR1: D_NaN mode bits Mask */

#define FPU_MVFR1_FtZ_mode_Pos              0U                                            /*!< MVFR1: FtZ mode bits Position */
#define FPU_MVFR1_FtZ_mode_Msk             (0xFUL /*<< FPU_MVFR1_FtZ_mode_Pos*/)          /*!< MVFR1: FtZ mode bits Mask */


#define FPU_BASE            (SCS_BASE +  0x0F30UL)                    /*!< Floating Point Unit */
#define FPU                 ((FPU_Type       *)     FPU_BASE      )   /*!< Floating Point Unit */

/*@} end of group CMSIS_FPU */


// ssebast1; added for compilation, used in OsSysCall.c
#define osdSysCallTableMax                  2

#define OS_NS2TICKS_OsCounter_0(x) ( ((TickType)(((((PhysicalTimeType)(x))) + ( 1000000UL  / 2 )) / 1000000UL ))) /*	valid range for x: 0..4294467295	*/
#define OS_US2TICKS_OsCounter_0(x) ( ((TickType)(((((PhysicalTimeType)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/
#define OS_MS2TICKS_OsCounter_0(x) ( ((TickType)(((((PhysicalTimeType)(x))))))) /*	valid range for x: 0..2147483647	*/
#define OS_SEC2TICKS_OsCounter_0(x) ( ((TickType)(((((PhysicalTimeType)(x)) * 1000UL ))))) /*	valid range for x: 0..2147483	*/
#define OS_TICKS2NS_OsCounter_0(x) ( ((PhysicalTimeType)(((((PhysicalTimeType)(x)) * 1000000UL ))))) /*	valid range for x: 0..4294	*/
#define OS_TICKS2US_OsCounter_0(x) ( ((PhysicalTimeType)(((((PhysicalTimeType)(x)) * 1000UL ))))) /*	valid range for x: 0..4294967	*/
#define OS_TICKS2MS_OsCounter_0(x) ( ((PhysicalTimeType)(((((PhysicalTimeType)(x))))))) /*	valid range for x: 0..4294967295	*/
#define OS_TICKS2SEC_OsCounter_0(x) ( ((PhysicalTimeType)(((((PhysicalTimeType)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/

#define osSaveDisableInt(x)                 (x=osSuspendInterruptsAsm())

#define osRestoreEnableInt(x)               if(x==0){ osEnableGlobalInterruptAsm(); }

#define OS_ARCH_INITIALIZE()                osIntArchInitialize();

#define OS_ARCH_SETUP_INTERRUPTS()          osSetupAndEnableConfiguredInterrupts();

#define osIntStartOS(x)                     __asm ("ldr        r0,=osStartOSasmArm ; osStartOSasmArm();"); \
                                            __asm ("bx         r0                  ; switches to ARM mode automatically if required"); \



#define OsIntSaveDisableLevel()           OsCpuHal_SaveDisableLevel()
                                
#define OsIntRestoreLevel(x)              OsCpuHal_RestoreLevel(x)


#define osIntIsrCallHook()


#define REG_READ32(address)               (*(volatile uint32*)(address))
#define REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (value))


/* IUNIT */
#define osIRQ_BASE              0xE000E000UL //0xb0400000UL - ssukuma1 commented this and updated for imx8

/*! NVIC interrupt controller base address. */
# define OS_HAL_INTC_NVIC_BASE     (0xE000E000UL)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! System Exceptions Priority Level Registers (SHPR). */
# define OS_HAL_INTC_NVIC_SHPR(x)    (*(volatile uint8*) (OS_HAL_INTC_NVIC_BASE + 0xD14UL + (x)))                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Set-Enable Registers (ISER). */
# define OS_HAL_INTC_NVIC_ISER(x)    (*(volatile uint32*) (OS_HAL_INTC_NVIC_BASE + 0x100UL + ((x) * 4UL)))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Clear-Enable Registers (ICER). */
# define OS_HAL_INTC_NVIC_ICER(x)    (*(volatile uint32*) (OS_HAL_INTC_NVIC_BASE + 0x180UL + ((x) * 4UL)))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Set-Pending Registers (ISPR). */
# define OS_HAL_INTC_NVIC_ISPR(x)    (*(volatile uint32*) (OS_HAL_INTC_NVIC_BASE + 0x200UL + ((x) * 4UL)))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Clear-Pending Registers (ICPR). */
# define OS_HAL_INTC_NVIC_ICPR(x)    (*(volatile uint32*) (OS_HAL_INTC_NVIC_BASE + 0x280UL + ((x) * 4UL)))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Active Bit Registers (IABR). */
# define OS_HAL_INTC_NVIC_IABR(x)    (*(volatile uint32*) (OS_HAL_INTC_NVIC_BASE + 0x300UL + ((x) * 4UL)))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Priority Registers (IPR). */
# define OS_HAL_INTC_NVIC_IPR(x)     (*(volatile uint8*) (OS_HAL_INTC_NVIC_BASE + 0x400UL + (x)))                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Interrupt Control State Register (ICSR). */
# define OS_HAL_INTC_NVIC_ICSR       (*(volatile uint32*) (0xE000ED04UL))                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! \brief  ICSR Regiter: PENDSET flag mask.
 *  \details
 *  1 = set pending pendSV
 *  0 = do not set pending pendSV.
 */
# define OS_HAL_INTC_NVIC_ICSR_PENDSTSET_BIT (1UL << 26)

/*! Vector Table Offset Register (VTOR). */
# define OS_HAL_INTC_SCB_VTOR        (*(volatile uint32*) (0xE000ED08UL))                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Software Triggered Interrupt Register (STIR). */
# define OS_HAL_INTC_STIR            (*(volatile uint32*) (0xE000EF00UL))                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL                       (0x0U)



 #define osdReloadTimer_Ch0     0UL
   #define osdReloadTimer_Ch1     1UL
   #define osdReloadTimer_Ch2     2UL
   #define osdReloadTimer_Ch3     3UL
   #define osdReloadTimer_Ch16    4UL
   #define osdReloadTimer_Ch17    5UL
   #define osdReloadTimer_Ch18    6UL
   #define osdReloadTimer_Ch19    7UL
   #define osdReloadTimer_Ch32    8UL
   #define osdReloadTimer_Ch33    9UL
   #define osdReloadTimer_Ch34   10UL
   #define osdReloadTimer_Ch35   11UL
   #define osdNoHwTimer        0xFFUL
   
#if (osdUsedSystemTimer <= osdReloadTimer_Ch3)
      /* Channels 0..3 */
      #define osRLT_BASE(x)        (0xb4810000UL+((x)*0x00000400UL))
   #else
   #if (osdUsedSystemTimer <= osdReloadTimer_Ch19)
      /* Channels 16..19 */
      #define osRLT_BASE(x)        (0xb4890000UL+(((x)-4UL)*0x00000400UL))
   #else
   #if (osdUsedSystemTimer <= osdReloadTimer_Ch35)
      /* Channels 32..35 */
      #define osRLT_BASE(x)        (0xb4788000UL+(((x)-8UL)*0x00000400UL))
   #endif
   #endif
   #endif
   
#define osRLT_DMACFG(x)      (*((volatile osuint32*)(osRLT_BASE(x)+0x00000000UL)))
#define osRLT_TMCSR(x)       (*((volatile osuint32*)(osRLT_BASE(x)+0x00000008UL)))
#define osRLT_TMRLR(x)       (*((volatile osuint32*)(osRLT_BASE(x)+0x00000010UL)))
#define osRLT_TMR(x)         (*((volatile osuint32*)(osRLT_BASE(x)+0x00000014UL)))

/* ssebast1; System Timer Registers of i/MX8 */
#define osSYST_BASE        (*((volatile osuint32*)(0xE000E010))) /* System Timer Register Base Address */
#define osSYST_CSR         (*((volatile osuint32*)(0xE000E010))) /* System Timer Control & Status Register Address */
#define osSYST_RVR         (*((volatile osuint32*)(0xE000E014))) /* System Timer Reload Value Register Address */
#define osSYST_CVR         (*((volatile osuint32*)(0xE000E018))) /* System Timer Current Value Register Address */
#define osSYST_CALIB       (*((volatile osuint32*)(0xE000E01C))) /* System Timer Calibration Value Register Address */


#define osdIRQ_Unlock()         (osIRQ0_UNLOCK=0x17ACC911UL)
#define osdIRQ_Lock()           (osIRQ0_UNLOCK=0x17B10C11UL)
#define osdIRQ_CSR_EnableBit    (1UL)
#define osdIRQ_NMIST_SrcMask    0x1fUL
#define osdIRQ_IRQST_SrcMask    0x1ffUL

#define osdBootROM_Unlock()     (osEXCFG_UNLOCK=0xACC5B007UL)
#define osdBootROM_Lock()       (osEXCFG_UNLOCK=0xB007ECF6UL)
#define osdBootROM_isLocked()   ((osEXCFG_CNFG & 1)!=0)
#define osdBootROM_SwitchSets() (osEXCFG_CNFG = (1UL<<8))

#define osHandlesAllIsr         0       //not required for now

#define osdNeedCI707_00027_Workaround   0

#define osdARMModeUser       0x10UL
#define osdARMModeFIQ        0x11UL
#define osdARMModeIRQ        0x12UL
#define osdARMModeSupervisor 0x13UL
#define osdARMModeAbort      0x17UL
#define osdARMModeUndefInstr 0x1BUL
#define osdARMModeSystem     0xFBUL


#define osdReloadValue 0x40F10UL
#define osdTimerInitValue 0x1060098UL

#define osAssignStack(stack)    ((osStackDataType*)((&(stack)[0])+(sizeof(stack)/sizeof((stack)[0]))))
#define osBottomOfStack(stack)  ((osStackDataType*)(stack))

typedef struct
{
    osuint16 osIrqNum;
    osIntLevelType osPrioLevel;
    osVoidFunctionType pIsr;
}osIntIrqChn_t;

extern void osStartArchTimer (void);
extern void osIntArchInitialize (void);
extern void osSetupAndEnableConfiguredInterrupts (void);

extern void osSetupExceptionStacks (void);

osuint32 osGetCPSR(void);
extern void osSetBitsARMCoreSCTLR(osuint32 BitsToSet);
extern void osEnableNMIandAborts(void);

extern void osInternal_IRQSTEER_CommonIRQHandler(EOsIntChn_t EOsIntChn);

extern void OsInt_SetupInterrupt (const osIntIrqChn_t * const pThisIrqParam);

#define osIsGlobalEnabled()    ((osGetCPSR()&(1UL<<7))==0)
#define osIsNMIEnabled()       ((osGetCPSR()&(1UL<<6))==0)
#define osGetMode()            (osGetCPSR()&(0x1FUL))


#define osdNumberOfAppModes 1
#define OSDEFAULTAPPMODE 1

#define OsResource ((ResourceType)0)


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
/*  MPU Control Register, Enable background region. */
# define OS_INT_MPU_MPU_CTRL_PRIVDEFENA (1UL << 2)

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

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
extern AccessType OsInternalCheckObjAccessRights (const OsMPUAccessGroupConfigType * const pAccessConfig, MemoryStartAddressType Address, MemorySizeType Size);
# define OS_INT_MPU_ACCESS_TYPE_SUBREGION_DISABLE(x)               (x << 8)
#endif
