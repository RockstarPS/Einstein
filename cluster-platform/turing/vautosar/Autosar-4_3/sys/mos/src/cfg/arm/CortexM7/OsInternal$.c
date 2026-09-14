/*-------------------------------------------------------------------------------**
**  ***************************************************************************  **
**                                                                               **
**                CONFIDENTIAL VISTEON CORPORATION                               **
**                                                                               **
**   This is an unpublished work of authorship, which contains trade             **
**   secrets, created in 2013. Visteon Corporation owns all rights to            **
**   this work and intends to maintain it in confidence to preserve              **
**   its trade secret status. Visteon Corporation reserves the right,            **
**   under the copyright laws of the United States or those of any               **
**   other country that may have jurisdiction, to protect this work              **
**   as an unpublished work, in the event of an inadvertent or                   **
**   deliberate unauthorized publication. Visteon Corporation also               **
**   reserves its rights under all copyright laws to protect this                **
**   work as a published work, when appropriate. Those having access             **
**   to this work may not copy it, use it, modify it or disclose the             **
**   information contained in it without the written authorization               **
**   of Visteon Corporation.                                                     **
**                                                                               **
**  ***************************************************************************  **
**  ***************************************************************************  **
**    File Name         :  OsInternal.c                                          **
**    Module Short Name :  OsInternal                                            **
**    Description       :  This file contains the implementation for the         **
**                         architecture specific handling supporting the         **
**                         supporting the operating system                       **
**                                                                               **
**   Organization     :  Driver Information Software Section,                    **
**                       Visteon Software Operation                              **
**                       Visteon Corporation                                     **
**                                                                               **
**   --------------------------------------------------------------------------  **
**   Compiler Name    :  GHS                                                     **
**   Target Hardware  :  ARM Core based CPU                                      **
**                                                                               **
**  ***************************************************************************  **
**-------------------------------------------------------------------------------*/
#ifndef OS_INTERNAL_C
#define OS_INTERNAL_C

#include "OsPrivate.h"
#include "OsInternal.h"

#define  OS_INT_MEMMAP_START
#include "Os_IntMemMap.h"


osuint32 osPrvLastLR = 0x0;

static void osInternalInitSystemInterruptPriority (void);
static void osInternalSetupVTOR (const osVoidFunctionType* VectorTable);
static void osInternalEnableIRQSteer (const osIntIrqChn_t * const pThisIrqParam);
static void osInternalEnableIRQ (const osIntIrqChn_t * const pThisIrqParam);
static void osInternalSetupFpu(void);

/*-----------------------------------------------------**
** const OsStackType OsStacks[OsNumberOfStack]       = **
** {                                                   **
**     {                                               **
**         osdSystemStackStartAddress,                 **
**         osdSystemStackEndAddress,                   **
**     },                                              **
**     {                                               **
**         osdIRQStackStartAddressPtr,                 **
**         osdIRQStackEndAddressPtr,                   **
**     },                                              **
**     {                                               **
**         osdFIQStackStartAddressPtr,                 **
**         osdFIQStackEndAddressPtr,                   **
**     }                                               **
** };                                                  **
**-----------------------------------------------------*/




void osIntArchInitialize (void)
{
    osInternalInitSystemInterruptPriority();
    osInternalSetupVTOR(osIRQTable);    
    osInternalSetupFpu();
}


static void osInternalInitSystemInterruptPriority (void)
{
    OS_INT_NVIC_SHPR1_REG = osdIntCfgNvicSHPRI1;
    OS_INT_NVIC_SHPR2_REG = osdIntCfgNvicSHPRI2;
    OS_INT_NVIC_SHPR3_REG = osdIntCfgNvicSHPRI3;
}

static void osInternalSetupFpu(void)
{
    #ifdef OS_INTERNAL_FPU_ENABLED
    //Disable Lazy Stacking of FPU
    //We will stack FPU registers during context switch
    FPU->FPCCR &= ~(FPU_FPCCR_LSPEN_Msk);
    //Enable FPU in CoProcessor Registers
    SCB->CPACR |= (0xF << 20);
    #endif
}

static void osInternalSetupVTOR (const osVoidFunctionType * VectorTable)
{
    osuint32 VectorTableStartAddress = (osuint32)(VectorTable);

    //Set up VTOR Register to point to the Os Defined vector table
    OS_INT_INTC_SCB_VTOR = VectorTableStartAddress;
}

void osSetupAndEnableConfiguredInterrupts (void)
{
    //osEnableNMIandAborts();
   
   osSetupConfiguredInterrupts();
}

//#define MOS_INTERNAL_VECTOR_WRITE

static void osInternalEnableIRQ (const osIntIrqChn_t * const pThisIrqParam)
{
    /* This SysIntIx NVIC might be enabled if there are more than one system interrupts mapped
     * to the same Index
     * NVIC_GetEnableIRQ returns 1 if Interrupt is enabled already
     * NVIC_GetEnableIRQ returns 0 if Interrupt is disabled */
	if(0 == NVIC_GetEnableIRQ((IRQn_Type)pThisIrqParam->SysIntIx))
    {
        /* SuspendAllInterrupts */
        //ASM_KEYWORD(" cpsid i");
        /* Set priority to interrupt */
        NVIC_SetPriority((IRQn_Type)pThisIrqParam->SysIntIx, pThisIrqParam->osPrioLevel);
        /* Enable interrupt */
        NVIC_ClearPendingIRQ((IRQn_Type)pThisIrqParam->SysIntIx);
    #ifdef MOS_INTERNAL_VECTOR_WRITE
        /* register interrupt handler */
        //todo: this api needs re-design if this section is enabled
        NVIC_RegisterIsrHandler_basic(pThisIrqParam->osIrqNum,(uint32)pThisIrqParam->pIsr);
    #endif
        /* Enable interrupt */
        NVIC_EnableIRQ((IRQn_Type)pThisIrqParam->SysIntIx);
        /* ResumeAllInterrupts */
        //ASM_KEYWORD(" cpsie i");
    }
}

void OsInt_SetupInterrupt (const osIntIrqChn_t * const pThisIrqParam)
{
    /* This service will be called by intvect only if the Interrupt is
     * NOT ARM Core Interrupts! */

    /* Enable the Peripheral Interrupt and assign the CPU mapped Interrupt */
    osInternalEnableIRQSteer(pThisIrqParam);
    //convert the Shared Peripheral Interrupt to M4_EXT_INTRx

    /*Finally enable external interrupts in M7 NVIC*/
    osInternalEnableIRQ(pThisIrqParam);

}

static void osInternalEnableIRQSteer (const osIntIrqChn_t * const pThisIrqParam)
{
    un_CPUSS_CM7_0_SYSTEM_INT_CTL_t unIntCtl0 = { 0ul };
    if(CPUSS->unIDENTITY.stcField.u4MS == CPUSS_MS_ID_CM7_0)
    {
        unIntCtl0.stcField.u4CPU_INT_IDX = (uint8_t)pThisIrqParam->SysIntIx;
        unIntCtl0.stcField.u1CPU_INT_VALID = 1UL;
        CPUSS->unCM7_0_SYSTEM_INT_CTL[pThisIrqParam->osIrqNum].u32Register = unIntCtl0.u32Register;
    }
}

#define CM7_SYS_TIMER
void osStartArchTimer (void)
{
#ifdef CM7_SYS_TIMER
/* ssebast1; System Timer Enabling */
    osSYST_RVR = osdReloadValue;
    osSYST_CSR = 0x00000007; //CLKSOURCE=Core clock; TICKINT = Asserts SysTick exception; Counter=ENABLE
#else
    /* No need to activate the interrupt at the IUNIT, this is already 
      done in osInitISRs */
   osRLT_TMRLR(osdUsedSystemTimer) = osdReloadValue;
   osRLT_TMCSR(osdUsedSystemTimer) = osdTimerInitValue;
#endif
}


void osISRUnhandledException (void)
{
//    osuint32 mode;

    while(1)
    {
        ;
    }
}

void osUnhandledException (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}


void osMemProtectionFault (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}

void osDataAbortHandler (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}


static inline osuint32 __OS_RBIT(osuint32 value)
{
  osuint32 result;
  osint32 s = (4 /*sizeof(v)*/ * 8) - 1; /* extra shift needed at end */

  result = value;                      /* r will be reversed bits of v; first get LSB of v */
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                        /* shift when v's highest bits are zero */
  return(result);
}

static inline osuint32 __OS_CLZ(osuint32 data)
    {
      if (data == 0u) { return 32u; }
      
      osuint32 count = 0;
      osuint32 mask = 0x80000000;
      
      while ((data & mask) == 0)
      {
        count += 1u;
        mask = mask >> 1u;
      }
      
      return (count);
    }


static inline void __OS_DSB(void)
{
  __asm ("dsb 0xF"); //:::memory");
}


#if 0 //ssukuma1 - not needed as of now for tvii
static osuint32 IRQSTEER_GetMasterNextInterrupt(IRQSTEER_Type *base, EOsIntChn_t EOsIntChn)
{
    osuint32 regIndex = FSL_FEATURE_IRQSTEER_CHn_MASK_COUNT - 1U - EOsIntChn * 2U;
    osuint32 bitOffset;
    osuint32 IRQn = 512U;

    bitOffset = __OS_CLZ(__OS_RBIT(base->CHn_STATUS[regIndex]));
    /* When no result found, continue the loop to parse the next CHn_STATUS register. */
    if (IRQSTEER_INT_SRC_REG_WIDTH == bitOffset)
    {
        regIndex--;
        bitOffset = __OS_CLZ(__OS_RBIT(base->CHn_STATUS[regIndex]));
    }

    if (IRQSTEER_INT_SRC_REG_WIDTH == bitOffset)
    {
        //Do nothing IRQn is invalid
    }
    else
    {
        //our IRQ STEER Index starts from 32
        //todo - need to analyze why to move the irq steer to 51st Index
        IRQn = (IRQSTEER_INT_SRC_NUM(regIndex, bitOffset)); // + FSL_FEATURE_IRQSTEER_IRQ_START_INDEX);
    }
    
    return IRQn;
}



static uint32 TmExtVar = 0;


void osInternal_IRQSTEER_CommonIRQHandler(EOsIntChn_t EOsIntChn)
{
    IRQSTEER_Type * const base = IRQSTEER;
    osuint32 intSource;
    osuint32 isr;

    TmExtVar++;
    
    intSource = IRQSTEER_GetMasterNextInterrupt(base, EOsIntChn);
    if (512 != intSource)
    {
        isr = *(uint32_t *)(SCB->VTOR + ((osuint32)(intSource) << 2U));

        ((void (*)(void))isr)();
    }
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
    exception return operation might vector to incorrect interrupt */
    __DSB();

}
#endif




void osUndefinedInstructionException (void)
{
    osErrorHook(E_OS_SYS_ABORT);
}


AccessType OsInternalCheckObjAccessRights (const OsMPUAccessGroupConfigType * const pAccessConfig, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    osuint32 Idx;
    MemoryStartAddressType StartAddress = Address;
    MemoryStartAddressType EndAddress =  ((StartAddress + Size)-1);
    osuint32 RegionCount = pAccessConfig->RegionCount;

    for(Idx=0;Idx<RegionCount;Idx++)
    {
        const OsIntMpuConfigType * pMpuConfig = &pAccessConfig->pMpuConfig[Idx];
        const osuint32 RegnStartAddress = pMpuConfig->RegnBaseAddress;
        const osuint32 RegnEndAddress = ((RegnStartAddress + pMpuConfig->RegnSize)-1);
        if((StartAddress >= RegnEndAddress) && (EndAddress <= RegnEndAddress))
        {
            Result = pMpuConfig->RegnAccess;
            break;
        }
    }
    return Result;
}

#define  OS_INT_MEMMAP_END
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
**  ------------------------------------------------------------------------------- **
**                                                                                  **
**  ------------------------------------------------------------------------------- **
**   Date              : 20-Jun-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   Traceability      :------------                                                **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------*/

