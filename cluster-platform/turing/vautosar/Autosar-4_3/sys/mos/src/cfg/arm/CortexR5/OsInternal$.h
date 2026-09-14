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
* Target Hardware  :  ARM Cortex Rx seriex (stringent relation with macros)  *
*                                                                            *
******************************************************************************/
#ifndef OS_INTERNAL_H
#define OS_INTERNAL_H

/*---------------------------------------------------------------**
** This file would be a generated file for architecture specific **
**---------------------------------------------------------------*/
#define osqStack1
#define osqStack2
#define osqStack3

#include "intvect.h"
#include "OsStacks_Lcfg.h"


#define TASK_BASIC      0
#define TASK_EXTENDED         1

#define osdIntIrqBitCheck                 0x80UL

#define OS_CORE_0_OS_ACCESS_ID         0x00u

#define OS_INTERNAL_FPU_ENABLED STD_OFF
#define MOS_API_MPU_SWITCH_ENABLE     STD_OFF

#define INVALID_TASK        0xFF
#define INVALID_PRIORITY    0xFF

#define TASK_NONPREEMPTIVE      0
#define TASK_PREEMPTIVE         1

#define ALARM_CALLBACK_ACTION       1
#define ALARM_ACTIVATE_TASK_ACTION  2
#define ALARM_SET_EVENT_ACTION      3

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
#define osStackSizeOfNonPreemptiveTask      sizeof(osSystemStack)

#define osdStackCheck                       1
#define osdStackUsageMeasurement            1
#define osdStackCheckPattern                0xaaaaaaaaUL

#define osdUsedSystemTimer                  osdReloadTimer_Ch48

#define OsCounter_0                         ((CounterType) 0)
#define OsCounter_1                         ((CounterType) 1)
#define osSystemSWCounter                   OsCounter_0
#define SystemTimer                         OsCounter_0
#define ScheduleTableTimer                  OsCounter_1

#define OSMAXALLOWEDVALUE                   (0xffffffffUL)

/******************************************************/
/* ssebast1; Added while integrating mOS for GAC SmartCore */
#define osdSysCallTableMax                  2
/*********************************************************/

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

#define osIntStartOS(x)                     __asm ("ldr        r0,=osStartOSasmArm "); \
                                            __asm ("bx         r0                  "); \


#define osDisableLevel()       __asm("   cpsid i ; globally disable interrupts"); \
                                __asm("   isb     ; instruction synchronization barrier")
                                
#define osEnableLevel()        __asm("   cpsie i ; globally enable interrupts")

/* Need to be defined based on the micro used */
#define TI_AM62P
/* Need to be defined based on the TIMER used for Os in TI AM62P */
#define osMCU_TIMER    MCU_TIMER0_BASEADDR

#ifdef GAC_SMARTCORE
    #define osIntIsrCallHook()                  osRLT_TMCSR(osdUsedSystemTimer) |= (1<<17); /* acknowledge the interrupt */
    /* BootROM */
    #define osEXCFG_BASE            0xfffefc00UL
    #define osEXCFG_UNLOCK          (*((volatile osuint32*)(osEXCFG_BASE+0x00000358UL)))
    #define osEXCFG_CNFG            (*((volatile osuint32*)(osEXCFG_BASE+0x00000360UL)))
    #define osEXCFG_UNDEFINACT      (*((volatile osuint32*)(0x00000000+0x00000024UL)))
    #define osEXCFG_SVCINACT        (*((volatile osuint32*)(0x00000000+0x00000028UL)))
    #define osEXCFG_PABORTINACT     (*((volatile osuint32*)(0x00000000+0x0000002CUL)))
    #define osEXCFG_DABORTINACT     (*((volatile osuint32*)(0x00000000+0x00000030UL)))
#endif

#ifdef TI_AM62P
    #define osIntIsrCallHook()  (*((volatile osuint32 *)(0x04800028))) |= (0x1 << 0x1); /* acknowledge the interrupt */
    /* Added for TI AM62Px Micro */
    #define osEXCFG_BASE            0x00000000
    #define osEXCFG_UNDEFINACT      (*((volatile osuint32*)(osEXCFG_BASE+0x00000024UL)))
    #define osEXCFG_SVCINACT        (*((volatile osuint32*)(osEXCFG_BASE+0x00000028UL)))
    #define osEXCFG_PABORTINACT     (*((volatile osuint32*)(osEXCFG_BASE+0x0000002CUL)))
    #define osEXCFG_DABORTINACT     (*((volatile osuint32*)(osEXCFG_BASE+0x00000030UL)))
#endif

/* IUNIT */
#define osIRQ_BASE              0xb0400000UL
#define osIRQ0_NMIVAS           (*((volatile osuint32*)(osIRQ_BASE+0x00000000UL)))
#define osIRQ0_NMIST            (*((volatile osuint32*)(osIRQ_BASE+0x00000004UL)))
#define osIRQ0_IRQVAS           (*((volatile osuint32*)(osIRQ_BASE+0x00000008UL)))
#define osIRQ0_IRQST            (*((volatile osuint32*)(osIRQ_BASE+0x0000000cUL)))
#define osIRQ0_NMIVA(x)         (((volatile osuint32*)(osIRQ_BASE+0x00000010UL))[x])
#define osIRQ0_IRQVA(x)         (((volatile osuint32*)(osIRQ_BASE+0x00000090UL))[x])
#define osIRQ0_NMIPL(x)         (((volatile osuint8*)(osIRQ_BASE+0x00000890UL))[x])
#define osIRQ0_IRQPL(x)         (((volatile osuint8*)(osIRQ_BASE+0x000008b0UL))[x])
#define osIRQ0_IRQCES(x)        (((volatile osuint32*)(osIRQ_BASE+0x00000b80UL))[x])
#define osIRQ0_IRQCEC(x)        (((volatile osuint32*)(osIRQ_BASE+0x00000bc0UL))[x])
#define osIRQ0_IRQCE(x)         (((volatile osuint32*)(osIRQ_BASE+0x00000c00UL))[x])
#define osIRQ0_IRQHC            (*((volatile osuint32*)(osIRQ_BASE+0x00000c48UL)))
#define osIRQ0_IRQPLM           (*((volatile osuint32*)(osIRQ_BASE+0x00000c90UL)))
#define osIRQ0_NESTL            (*((volatile osuint32*)(osIRQ_BASE+0x00000ca0UL)))
#define osIRQ0_CSR              (*((volatile osuint32*)(osIRQ_BASE+0x00000c98UL)))
#define osIRQ0_UNLOCK           (*((volatile osuint32*)(osIRQ_BASE+0x00000d30UL)))

/* Added for TI AM62Px Micro VIM configuration */
#define osVIM_BASE              0x07FF0000UL
#define osVIM_IRQVEC            (0x18u)
#define osVIM_FIQVEC            (0x1Cu)
#define osVIM_ACTIRQ            (0x20u)
#define osVIM_ACTFIQ            (0x24u)
#define osVIM_INT_VEC(x)        (*((volatile osuint32*)(osVIM_BASE + (0x2000u + ((x) * 0x4u)))))
#define osVIM_INT_PRI(x)        (*((volatile osuint32*)(osVIM_BASE + (0x1000u + ((x) * 0x4u)))))
#define osVIM_INT_EN(x)         (*((volatile osuint32*)(osVIM_BASE + (0x408u + (((x)>>5) & 0xFu) * 0x20u))))
#define osVIM_BIT_POS(x)        ( (x) & 0x1Fu )
#define osVIM_INT_DIS(x)        (*((volatile osuint32*)(osVIM_BASE + (0x40Cu + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_STS(x)            (*(volatile osuint32*)(osVIM_BASE + (0x404u + (((x)>> 5) & 0xFu) * 0x20u)))
#define osVIM_INT_TYPE(x)       (*((volatile osuint32*)(osVIM_BASE + (0x41Cu + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_INT_MAP(x)        (*((volatile osuint32*)(osVIM_BASE + (0x418u + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_IRQVECADDR        (*((volatile osuint32*)(osVIM_BASE + (osVIM_IRQVEC))))
#define osVIM_FIQVECADDR        (*((volatile osuint32*)(osVIM_BASE + (osVIM_FIQVEC))))
#define osVIM_ACTIRQADDR        (volatile osuint32*)(osVIM_BASE + (osVIM_IRQVEC))
#define osVIM_GET_STSHWADDR(x)  (volatile osuint32*)(osVIM_BASE + (0x404u + (((x)>> 5) & 0xFu) * 0x20u))

/* MCU Timer Base address for TI AM62P */
#define MCU_TIMER0_BASEADDR 0x4800000U
#define MCU_TIMER1_BASEADDR 0x4810000U
#define MCU_TIMER2_BASEADDR 0x4820000U
#define MCU_TIMER3_BASEADDR 0x4830000U

/* Added for TI AM62Px Micro TIMER configuration */
#define osMCU_TCLR              (0x38u)
#define osMCU_IRQ_EOI           (0x20u)
#define osMCU_IRQ_STATUS_RAW    (0x24u)
#define osMCU_IRQ_STATUS        (0x28u)
#define osMCU_IRQ_INT_ENABLE    (0x2Cu)
#define osMCU_IRQ_INT_DISABLE   (0x30u)
#define osMCU_TCRR              (0x3cu)
#define osMCU_TLDR              (0x40u)



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
   #define osdReloadTimer_Ch48   12UL
   #define osdReloadTimer_Ch49   13UL
   #define osdNoHwTimer        0xFFUL
/* ssebast1; Reload timer base address to be revisited for Juno micro */ 
#if 1   
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
   #else   
   #if (osdUsedSystemTimer <= osdReloadTimer_Ch49)
      /* Channels 48 & 49 */
      #define osRLT_BASE(x)        (0xb0690000UL+(((x)-12UL)*0x00000400UL))
   #else
   #endif
   #endif

   #endif
   #endif
#else
      #define osRLT_BASE(x)        (0xb0690000UL+(((x)-12UL)*0x00000400UL))
#endif //#if 0

#define osRLT_DMACFG(x)      (*((volatile osuint32*)(osRLT_BASE(x)+0x00000000UL)))
#define osRLT_TMCSR(x)       (*((volatile osuint32*)(osRLT_BASE(x)+0x00000008UL)))
#define osRLT_TMRLR(x)       (*((volatile osuint32*)(osRLT_BASE(x)+0x00000010UL)))
#define osRLT_TMR(x)         (*((volatile osuint32*)(osRLT_BASE(x)+0x00000014UL)))
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


#define osdReloadValue 0xea5fUL
#define osdTimerInitValue 0x1060098UL
#define osAssignStack(stack)    ((osStackDataType*)((&(stack)[0])+(sizeof(stack)/sizeof((stack)[0]))))
#define osBottomOfStack(stack)  ((osStackDataType*)(stack))


extern void osStartArchTimer (void);
extern void osIntArchInitialize (void);
extern void osSetupAndEnableConfiguredInterrupts (void);

extern void osSetupExceptionStacks (void);

osuint32 osGetCPSR(void);
extern void osSetBitsARMCoreSCTLR(osuint32 BitsToSet);
extern void osEnableNMIandAborts(void);
extern osuint32 osMpuGetMpuTypeAsm(void);

#define osIsGlobalEnabled()    ((osGetCPSR()&(1UL<<7))==0)
#define osIsNMIEnabled()       ((osGetCPSR()&(1UL<<6))==0)
#define osGetMode()            (osGetCPSR()&(0x1FUL))


#define osdNumberOfAppModes 1
#define OSDEFAULTAPPMODE 1


#define OsResource ((ResourceType)0)

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
# define OS_INT_MPU_ACCESS_TYPE_SHARED_DEVICE                         ((0UL << 3) | (1UL << 0))
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
