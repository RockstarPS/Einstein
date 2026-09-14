/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file Interrupt_handler.c
 *
 * \brief
 * Interrupt handler for TI M4 core 
 *
 * \version 1.0.0
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 25/Jul/24  | kjohn    | xxxxxx  | Initial version                       |
 * * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

#include "stdint.h"
#include "trace.h"
#include "config.h"

#define UNUSED_PARAM       (void)
#define MEMFAULTADD_ADDR   ((uintptr_t)0xE000ED34U)
#define MEMFAULTADD        ((volatile uint32_t *)MEMFAULTADD_ADDR)

#define NMI_FAULT               (0x01U)
#define HARD_FAULT              (0x02U)
#define MEM_FAULT               (0x04U)
#define USAGE_FAULT             (0x08U)
#define RSRV_HANDLE             (0x10U)
#define SVC_HANDLE              (0x20U)
#define DEBUG_HANDLE            (0x40U)
#define PENDSV_HANDLE           (0x80U)
#define BUS_FAULT               (0x100U)
#define STACK_FAULT             (0x200U)
#define FW_HANDLE               (0x400U)
#define WDG_HANDLE              (0x800U)

extern uint32_t _logHsmFault;
static uint32_t Fault_handler_U32 = 0u; /*For storing in MCU R5 core*/

extern void vHsmFaultLogging(void);
#ifdef FAULTLOGGING
extern void vHsmFault_Logger(uint32_t *stack);
#endif

/*Declarations are in Entry.S file*/

extern void  NMI_Handler(void);
extern void  HardFault_Handler(void);
extern void  MemManage_Handler(void);
extern void  UsageFault_Handler(void);
extern void  Reserved_handler(void);
extern void  SVC_Handler(void);
extern void  DebugMon_Handler(void);
extern void  PendSV_Handler(void);
extern void  BusFault_Handler(void);


void  NMI_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = NMI_FAULT;
    TRACE_info("\r\n NMI Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  HardFault_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = HARD_FAULT;
    TRACE_info("\r\n Hardfault Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  MemManage_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = MEM_FAULT;
    volatile uint32_t *const memfaultadd = MEMFAULTADD;
    TRACE_info("\r\n Memmanage Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    TRACE_info_arg("\r\n Mem Fault address",*memfaultadd);
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}


void  UsageFault_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = USAGE_FAULT;
    TRACE_info("\r\n Usage Fault Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  Reserved_handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = RSRV_HANDLE;
    TRACE_info("\r\n Reserved Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  SVC_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = SVC_HANDLE;
    TRACE_info("\r\n SVC Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  DebugMon_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = DEBUG_HANDLE;
    TRACE_info("\r\n DebugMon Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  PendSV_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = PENDSV_HANDLE;
    TRACE_info("\r\n PendSV Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }
}

void  BusFault_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = BUS_FAULT;
    TRACE_info("\r\n BUS fault Handler");
#ifdef FAULTLOGGING
    vHsmFaultLogging();
#endif
    while(loop == 1u)
    {
      /* Do Nothing */
    }

}

#ifdef FAULTLOGGING


/* Log the last executed address*/
void vHsmFault_Logger(uint32_t *stack)
{
  volatile uint32_t * vHsmlog_PU32 = (uint32_t*)&_logHsmFault;
  uint32_t lr  = stack[5];  // Return address
  uint32_t pc  = stack[6];  // Stack address
  vHsmlog_PU32[0] = pc;
  TRACE_info_arg("\r\n Fault Address: ",pc);
  TRACE_info_arg("\r\n Return Address: ",lr);
}
#endif

#ifdef HSMSTACKPROTECTION
void StackCorruption_Handler(void)
{
    volatile uint32_t loop = 1u;
    Fault_handler_U32 = STACK_FAULT;
    TRACE_info("\r\n Stack Corruption Handler");
    while(loop == 1u)
    {
       /* do Nothing*/
    }
}
#endif

#ifdef HSMWDG_INTERRUPT
void vHsmWdg_Isr(uint32_t a)
{
    UNUSED_PARAM(a);
    volatile uint32_t * vHsmlog_PU32 = (uint32_t*)&_logHsmFault;
    volatile uint32_t loop = 1u;
    volatile uint32_t *const memfaultadd = MEMFAULTADD;
    TRACE_info("\r\n WDG Handler");
    if((Fault_handler_U32 & MEM_FAULT) == MEM_FAULT)
    {
        TRACE_info_arg("\r\n MemFault address: ", *memfaultadd);
    }
    else if (Fault_handler_U32  == 0u)
    {
#ifdef FAULTLOGGING
        vHsmFaultLogging();
#endif
        Fault_handler_U32 = WDG_HANDLE;
    }
    else
    {
        /*Do Nothing*/
    }
    TRACE_info_arg("\r\n Reset reason: ", Fault_handler_U32);
    vHsmlog_PU32[1] = Fault_handler_U32;
    while(loop == 1u)
    {
       /* do Nothing*/
    }
}
#endif

#ifdef VHSMFW_ENABLE
void vHsmFireWall_Isr(uint32_t a)
{
    UNUSED_PARAM(a);
    uint32_t loop = 1u;
    Fault_handler_U32 = FW_HANDLE;
    TRACE_info("\r\n HSM FireWall Violation");
#ifdef FAULTLOGGING
        vHsmFaultLogging();
#endif
    /*log later in DLT*/
    while(loop == 1u)
    {

    }
}
#endif
