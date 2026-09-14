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
static void osInternalEnableIRQSteer (const osuint16 osIrqNum);
static void osInternalEnableIRQ (const osIntIrqChn_t * const pThisIrqParam);

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
}


static void osInternalInitSystemInterruptPriority (void)
{
    OS_INT_NVIC_SHPR1_REG = osdIntCfgNvicSHPRI1;
    OS_INT_NVIC_SHPR2_REG = osdIntCfgNvicSHPRI2;
    OS_INT_NVIC_SHPR3_REG = osdIntCfgNvicSHPRI3;
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

    /* SuspendAllInterrupts */
    //ASM_KEYWORD(" cpsid i");
    /* Set priority to interrupt */
    NVIC_Test_SetPriority(pThisIrqParam->osIrqNum, pThisIrqParam->osPrioLevel);
    /* Enable interrupt */
    NVIC_Test_ClearPendingIRQ(pThisIrqParam->osIrqNum);
#ifdef MOS_INTERNAL_VECTOR_WRITE
    /* register interrupt handler */
    //todo: this api needs re-design if this section is enabled
    NVIC_Test_RegisterIsrHandler_basic(pThisIrqParam->osIrqNum,(uint32)pThisIrqParam->pIsr);
#endif
    /* Enable interrupt */
    NVIC_Test_EnableIRQ(pThisIrqParam->osIrqNum);
    /* ResumeAllInterrupts */
    //ASM_KEYWORD(" cpsie i");
}

void OsInt_SetupInterrupt (const osIntIrqChn_t * const pThisIrqParam)
{
    const osuint16 cIrqNum = pThisIrqParam->osIrqNum;
    const osuint8 cIrqChId = (M4_EXT_INTR0 + (cIrqNum/64));
    osIntIrqChn_t ThisIrq = {0,0,NULL};
    
    ThisIrq.osPrioLevel = pThisIrqParam->osPrioLevel;
    ThisIrq.pIsr = pThisIrqParam->pIsr;
    ThisIrq.osIrqNum = cIrqNum;
    
    if(cIrqNum > 64)
    {
        osInternalEnableIRQSteer(cIrqNum);
        //convert the Shared Peripheral Interrupt to M4_EXT_INTRx
        ThisIrq.osIrqNum = cIrqChId; 
        
    }
    /*Finally enable external interrupts in M4 NVIC*/
    osInternalEnableIRQ(&ThisIrq);

}

static void osInternalEnableIRQSteer (const osuint16 osIrqNum)
{
    uint32 u32MaskVal;
    
    
	/* Here are the steps to configure IRQ for MU5
	1.	Find the IRQ interrupt index of MU5 in Shared Peripheral Interrupt Mapping table in Reference Manual

	IRQ index	Source
	216	MU5_INT_A - Interrupts from message unit #5 to #13 (port A)
	232	MU5_INT_B - Interrupts from message unit #5 to #13 (port B)

	/	3. Enable Interrupt Mask bit of MU5 IRQ
	There are 512 interrupts in one channel, therefore there are 16 Interrupt Mask (32-bit) registers (CHn_MASKa[n] with n from index 0 to index 15)

	Calculation of the interrupt mask bit for IRQ of MU5 port A:

	IRQ index of MU 5 is 216, so the Interrupt Mask registers of MU5 IRQ should have index: 15 -(216/32) = 9.
	In register CHn_MASKa[9], you should set bit which has index is 216 - 9*32 = 24 to 1.
    */

	/*Read the Mask Value*/
	u32MaskVal = REG_READ32(IRQSTEER_CHANMASK_ADDR32(osIrqNum));
	u32MaskVal = (u32MaskVal | ((uint32)1UL << ((uint8)osIrqNum & 0x1FU)));
	REG_WRITE32(IRQSTEER_CHANMASK_ADDR32(osIrqNum), (u32MaskVal));


	/*4. Configure Master Interrupt Disable Register

	There are 8 Interrupt Masters for 512 IRQn (from index 0 to 7)

	IRQ index of MU5_INT_A is 216, so the IRQ is belong to the the Master Interrupt index 3. Therefore make sure bit which has index 3 in Master Interrupt Disable Register - CHn_MINTDIS is 0.

	If the MU5 interrupt occurs, it should jump to interrupt handlers for external interrupts 3

	Note:
	If you want to check whether the interrupt occurs, you can check bit which has index 24 in CHn_STATUSa[9], the calcuation is the same is step 3.

	It is also note that you should power up, enable clock and set clock rate for IRQSTEER module first by using SCFW firmware*/

	/*Master Interrupt Disable Register 0 - Enable, 1 - Disable */
	u32MaskVal = REG_READ32(IRQSTEER_CHANMINTDIS_ADDR32);
	u32MaskVal = (u32MaskVal & ((uint32)~((uint32)1UL << ((uint32)(osIrqNum) >> 6))));
	REG_WRITE32(IRQSTEER_CHANMINTDIS_ADDR32, (uint32)(u32MaskVal));

    
}

#define IMX8_SYS_TIMER

void osStartArchTimer (void)
{
#ifdef IMX8_SYS_TIMER
/* ssebast1; System Timer Enabling */
    osSYST_RVR = osdReloadValue;
    osSYST_CSR = 0x00000003; //CLKSOURCE=Processor clock; TICKINT = Asserts SysTick exception; Counter=ENABLE
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


static inline osuint32 __RBIT(osuint32 value)
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

static inline osuint32 __CLZ(osuint32 data)
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


static inline void __DSB(void)
{
  __asm ("dsb 0xF"); //:::memory");
}



static osuint32 IRQSTEER_GetMasterNextInterrupt(IRQSTEER_Type *base, EOsIntChn_t EOsIntChn)
{
    osuint32 regIndex = FSL_FEATURE_IRQSTEER_CHn_MASK_COUNT - 1U - EOsIntChn * 2U;
    osuint32 bitOffset;
    osuint32 IRQn = 512U;

    bitOffset = __CLZ(__RBIT(base->CHn_STATUS[regIndex]));
    /* When no result found, continue the loop to parse the next CHn_STATUS register. */
    if (IRQSTEER_INT_SRC_REG_WIDTH == bitOffset)
    {
        regIndex--;
        bitOffset = __CLZ(__RBIT(base->CHn_STATUS[regIndex]));
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

