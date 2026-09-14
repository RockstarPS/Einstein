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
**    File Name         :  OsHal_CpuDerivative.c                                 **
**    Module Short Name :  OsHal_CpuDerivative                                   **
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
#ifndef OS_HAL_PROCESSOR
#define OS_HAL_PROCESSOR

/************************************* Includes **********************************/
#include "OsMain.h"
#include "OsPrivate.h"
#include "OsInternal.h"
#include "OsHal_CpuDerivative.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"
/*MISRA RULE 4.8 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 20.1 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 10.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define OS_INT_ARM_CM4_SYS_HANDLERS_MAX (osuint16)15 /* Refer intvect.c */
#define OS_IRQ_64    (osuint16)64

static void OsHalPrv_EnableIRQ (const osIntIrqChn_t * const pThisIrqParam) ;
static void OsHalPrv_GetNVICIrqParam(osIntIrqChn_t* NvicIrqParam, ISRType ISRID);
static void OsHalPrv_EnableIRQSteer (const osuint16 osIrqNum);

/**
 * @brief Service OsHalPrv_osInitSystemInterruptPriority
 * @note  Initializing the interrupt priority
 * @param void
 * @return void
 */
void OsHalPrv_osInitSystemInterruptPriority (void)
{
    OS_INT_NVIC_SHPR1_REG = osdIntCfgNvicSHPRI1;
    OS_INT_NVIC_SHPR2_REG = osdIntCfgNvicSHPRI2;
    OS_INT_NVIC_SHPR3_REG = osdIntCfgNvicSHPRI3;
}

/**
 * @brief Service OsHalPrv_EnableIRQ
 * @note  Enable IRQ
 * @param pThisIrqParam
 * @return void
 */
static void OsHalPrv_EnableIRQ (const osIntIrqChn_t * const pThisIrqParam) 
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

/**
 * @brief Service OsInt_SetupInterrupt
 * @note  Setup IRQ
 * @param pThisIrqParam
 * @return void
 */
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
        OsHalPrv_EnableIRQSteer(cIrqNum);
        //convert the Shared Peripheral Interrupt to M4_EXT_INTRx
        ThisIrq.osIrqNum = cIrqChId; 
        
    }
    /*Finally enable external interrupts in M4 NVIC*/
    OsHalPrv_EnableIRQ(&ThisIrq);

}

/**
 * @brief Service OsHalPrv_GetNVICIrqParam
 * @note  GetNVICIrqParam
 * @param NvicIrqParam
 * @param ISRID
 * @return void
 */
static void OsHalPrv_GetNVICIrqParam(osIntIrqChn_t* NvicIrqParam, ISRType ISRID)
{
    /*  Refer osIRQPrioTable[] & osIRQTable[] in intvect.c
        {LogicalNo,	IRQ#, Priority}, NVIC : InterruptVector
        {0, 015, 128},  015 : SystemTimerISR
		{1, 268, 128},  036 : Can_ISR_B
		{2, 272, 128},  036 : ADC0_ISR
		{3, 114, 128},  033 : GPT_2
		{4, 115, 128},  033 : GPT_3
		{5, 248, 128},  035 : SPI0
		{6, 250, 128},  035 : SPI2
		{7, 022, 128},  022 : GPT_LPIT
		{8, 116, 128},  033 : GPT_4
		{9, 168, 128},  034 : GPIO0_INT */
	if(NULL != NvicIrqParam)
	{
		NvicIrqParam->pIsr = NULL;
		if(ISRID < (ISRType)osdNumberOfConfiguredIRQs)
	    {
	        const osIntPrioType * const pThisIrq = &osIRQPrioTable[ISRID];
	        osuint16 CurOsIPNumber = pThisIrq->osIPNumber;
	        if (CurOsIPNumber > OS_INT_ARM_CM4_SYS_HANDLERS_MAX) //avoid ARM core Sys Handlers
	        {
	            NvicIrqParam->osIrqNum = CurOsIPNumber;
	            if(NvicIrqParam->osIrqNum > OS_IRQ_64)
	            {
	                /* Convert the Shared Peripheral Interrupt to M4_EXT_INTRx */
	                NvicIrqParam->osIrqNum = (osuint16)M4_EXT_INTR0 + (NvicIrqParam->osIrqNum/OS_IRQ_64);
	            }
	            NvicIrqParam->osPrioLevel = pThisIrq->osIPLevel;
	            if(CurOsIPNumber < (osuint16)osdNumberOfIRQs)
	            {
	            	NvicIrqParam->pIsr = osIRQTable[CurOsIPNumber];
	            }
	            /* Refer osIRQPrioTable[] & osIRQTable[] in intvect.c
	               NVIC 015 : SystemTimerISR
	               NVIC 022 : GPT_LPIT
	               NVIC 036 : Can_ISR_B, ADC0_ISR
	               NVIC 033 : GPT_2, GPT_3, GPT_4
	               NVIC 035 : SPI0, SPI2
	               NVIC 034 : GPIO0_INT */
	        }
	    }
	}
}

/**
 * @brief Service OsHal_EnableInterruptSource
 * @note  Enable InterruptSource
 * @param ISRID
 * @param ClearPending
 * @return StatusType
 */
StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending)
{
	/* In Imx8 programs, IRQ # differs but NVIC register remains same for few ISRs.
	   For Eg: GPT_2 114, GPT_3 115, GPT_4 116 all refers to NVIC Register 33.
	   So, Enabling one IRQ# enables related ISRs also */
	StatusType Status = E_NOT_OK;
	osIntIrqChn_t NvicIrqParam = { 0, 0, NULL };

    OsHalPrv_GetNVICIrqParam(&NvicIrqParam, ISRID);

    if ((ISRID < (ISRType)OsNumberOfIsr) && (NvicIrqParam.pIsr != NULL))
    {
        NVIC_Test_SetPriority((uint8)NvicIrqParam.osIrqNum, NvicIrqParam.osPrioLevel); /* Set priority to interrupt */
    	if(FALSE != ClearPending)
    	{
    		/* Also, Clearing one IRQ# clears related ISRs also */
    		NVIC_Test_ClearPendingIRQ((uint8)NvicIrqParam.osIrqNum);
    	}
    	NVIC_Test_EnableIRQ((uint8)NvicIrqParam.osIrqNum); /* Enable interrupt */
    	Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief Service OsHal_DisableInterruptSource
 * @note  Disable InterruptSource
 * @param ISRID
 * @return StatusType
 */
StatusType OsHal_DisableInterruptSource(ISRType ISRID)
{
	/* In Imx8 programs, IRQ # differs but NVIC register remains same for few ISRs.
	   For Eg: GPT_2 114, GPT_3 115, GPT_4 116 all refers to NVIC Register 33.
	   So, Disabling one IRQ# disables related ISRs also */
	StatusType Status = E_NOT_OK;
	osIntIrqChn_t NvicIrqParam = { 0, 0, NULL };

    OsHalPrv_GetNVICIrqParam(&NvicIrqParam, ISRID);

    if ((ISRID < (ISRType)OsNumberOfIsr) && (NvicIrqParam.pIsr != NULL))
    {
    	NVIC_Test_DisableIRQ((uint8)NvicIrqParam.osIrqNum); /* Disable interrupt */
    	Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief Service OsHalPrv_EnableIRQSteer
 * @note  Enable IRQ Steer
 * @param osIrqNum
 * @return void
 */
static void OsHalPrv_EnableIRQSteer (const osuint16 osIrqNum)
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

/**
 * @brief Service osStartArchTimer
 * @note  Start Timer
 * @param void
 * @return void
 */
void osStartArchTimer (void)
{
/* ssebast1; System Timer Enabling */
    osSYST_RVR = osdReloadValue;
    osSYST_CSR = 0x00000003; //CLKSOURCE=Processor clock; TICKINT = Asserts SysTick exception; Counter=ENABLE
}

/**
 * @brief Service __RBIT
 * @note  Reverse Bit
 * @param value
 * @return osuint32
 */
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

/**
 * @brief Service __CLZ
 * @note  __CLZ
 * @param data
 * @return osuint32
 */
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

/**
 * @brief Service __DSB
 * @note  __DSB
 * @param void
 * @return void
 */
static inline void __DSB(void)
{
  __asm ("dsb 0xF"); //:::memory");
}


/**
 * @brief Service IRQSTEER_GetMasterNextInterrupt
 * @note  Get Master NextInterrupt
 * @param base
 * @param EOsIntChn
 * @return osuint32
 */
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

/**
 * @brief Service osInternal_IRQSTEER_CommonIRQHandler
 * @note  Common IRQ Handler
 * @param EOsIntChn
 * @return void
 */
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

/**
 * @brief Service OsHal_CheckIntrPending
 * @note  Check Pending Timer Exception
 * @param void
 * @return void
 */
void OsHal_CheckIntrPending (void)
{
    /* Check if Systick Pending Bit is Set */
    if((OS_HAL_ICSR_ADDR & OS_HAL_ICSR_PENDSTSET_BIT) == OS_HAL_ICSR_PENDSTSET_BIT)
    {
        /* If Systick timer is pending before exit, OS is Overloaded */
        OsErr_osApplicationErrorHook(OsDlt_OsTickTimer, NULL_PTR , E_OS_OVERLOAD);
    }
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
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
**   ------------------------------------------------------------------------------ **
**   Date              : 27-Jul-2022                                                **
**   CDSID             : rsivaku4                                                   **
**   RTC Id            : 1709142                                                    **
**   Change Description: MPU nesting prevention and Moving Internal.c to HAL        **
**----------------------------------------------------------------------------------**/
