/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
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
 * \file vHsmWdg.h
 *
 * \brief
 * HSM Watchdog Implementation for AM62PX HSM M4F core Source File
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include "stdint.h"
#include "hw_rti.h"
#include "vHsmWdg.h"
#include "config.h"
#include "trace.h"
#include "hwip.h"
#include "interrupt.h"
#include "hosts.h"
#include "firewall.h"
#include "sec_proxy_minimal.h"
#ifdef HSMWDG_ENABLE
/* ========================================================================== */
/*                           Macros                                           */
/* ========================================================================== */

#define HSMLOCK0_REGISTER                   (0x43936020U)
#define HSMLOCK1_REGISTER                   (0x43936024U)
#define HSMWDG_WWRTI_CTRL                   (0x43936040U)
#define HSMWDG_WWDT_INTR_EXT_EN             (0x43936704U)

#define HSMLOCK0_UNLOCK                     (0x4658fc21U)
#define HSMLOCK1_UNLOCK                     (0x3ac4f102U)
#define HSMWDG_WWRTI_ALLRESET               (0xAAU)
#define HSMWDG_ENABLE_INTR_EXT              (0x10U)

#define WDG_DWWDPRLD_MULTIPLIER_SHIFT       (13U)
#define WDG_RTIWDKEY_WDKEY_INVALID_WRITE    (0x4444U)

#define WDG_CTL_ENABLED                     (0xA98559DAU)
#define WDG_CTL_DISABLED                    (0x5312ACEDU)

#define WDG_TRIGGER_FIRST_KEY               (0xE51AU)
#define WDG_TRIGGER_SECOND_KEY              (0xA35CU)
#define WDG_TRIGGER_RESET_KEY               (0x2345U)

#define WDG_MAX_PRELOAD_VALUE               (0xFFFU)

#define HSMRTI_BASE_ADDRESS                 (0x43935000U)
#define HSMWDG_DEFAULT_PRIORITY             (0x0U)
#define HSMWDG_EXEPTION_NUMBER              (171)
#define HSMWDG_RESET_REACTION               (0x5U)

#define HSMM4SHPRREG_ADDRESS                (0xE000ED18U)
#define HSMFAULTS_PRIORITY                  ((uint32)1u << 5u)  // prioirty one 
#define HSMFAULT_SETPRIORITY                ((uint32)HSMFAULTS_PRIORITY|((uint32)HSMFAULTS_PRIORITY << 8u)|((uint32)HSMFAULTS_PRIORITY << 16u))


/* WDG Configuration from Config.h*/
#define HSMWDG_RTIFREQUENCY  HSMWDG_RTIFREQUENCYCFG
#define HSMWDG_REACTION      HSMWDG_REACTIONCFG
#define HSMWDG_TIMEOUT       HSMWDG_TIMEOUTCFG
#define HSMWDG_WINDOWSIZE    HSMWDG_WINDOWSIZECFG

#ifdef HSMWDG_INTERRUPT
    #if(HSMWDG_REACTION == HSMWDG_RESET_REACTION)
        #error Disable HSM WDG Interrupt
    #endif
#endif

#ifdef HSMWDG_INTERRUPT
extern void vHsmWdg_Isr(uint32_t a);
#endif
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static FUNC(uint32, WDG_CODE)vHsmWdg_getPreload(uint32 timeoutVal);
#ifdef HSMWDG_INTERRUPT
static void vHsmWdg_InterruptConfig(void);
#endif
static FUNC(Std_ReturnType, WDG_CODE)vHsmWdg_WindowConfig(uint32 Reaction,uint32 timeoutVal,uint32 WindowSize);
static FUNC(void, WDG_CODE) vHsmWdg_clearStatus(void);
static FUNC(void, WDG_CODE) vHsmWdg_Enable(void);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/********************************************************************************
 * \fn vHsmWdg_getPreload
 *
 * Calcualte preload Value using the input timeout value
 *
 * \return <br>
 * This function returns: uint32
 *****************************************************************************/
static FUNC(uint32, WDG_CODE)vHsmWdg_getPreload(uint32 timeoutVal)
{
    uint32 timeoutNumCycles = 0U;
    timeoutNumCycles = ((HSMWDG_RTIFREQUENCY / 1000U) * timeoutVal);
    return timeoutNumCycles;
}

#ifdef HSMWDG_INTERRUPT
/********************************************************************************
 * \fn vHsmWdg_InterruptConfig
 *
 * Config HSM WDG interrupt
 *
 * \return <br>
 * This function returns: none
 *****************************************************************************/
static FUNC(void, WDG_CODE) vHsmWdg_InterruptConfig(void)
{
    sint32 l_retVal = 0;
    struct hwip_params vHsmWdgParam_st;
    vHsmWdgParam_st.priority = HSMWDG_DEFAULT_PRIORITY; /*default Priority*/
    CSL_REG32_WR(HSMM4SHPRREG_ADDRESS,HSMFAULT_SETPRIORITY); /*Chnage priority of MEM,BUS and Usage Faults*/
    mask_interrupts();
    l_retVal = hwip_create(0u,HSMWDG_EXEPTION_NUMBER,vHsmWdg_Isr,&vHsmWdgParam_st);
    if(l_retVal != 0)
    {
       /* error case*/
    }
    l_retVal = hwip_clear_interrupt(HSMWDG_EXEPTION_NUMBER);
    if(l_retVal != 0)
    {
       /*error case*/
    }
    l_retVal = hwip_enable_interrupt(HSMWDG_EXEPTION_NUMBER,NULL);
    if(l_retVal != 0)
    {
       /*error Case*/
    }
    unmask_interrupts();
    CSL_REG32_WR(HSMLOCK0_REGISTER,HSMLOCK0_UNLOCK); /*Unlock LOCK0*/
	CSL_REG32_WR(HSMLOCK1_REGISTER,HSMLOCK1_UNLOCK); /*Unlock LOCK1*/
	CSL_REG32_WR(HSMWDG_WWRTI_CTRL,HSMWDG_WWRTI_ALLRESET); /*Disable Reset*/
	CSL_REG32_WR(HSMWDG_WWDT_INTR_EXT_EN,HSMWDG_ENABLE_INTR_EXT); /*Enable ESM Interrupt*/
	CSL_REG32_WR(HSMLOCK0_REGISTER,0x0); /*Lock LOCK1*/
	CSL_REG32_WR(HSMLOCK1_REGISTER,0x0); /*Lock LOCK2*/
}
#endif
/********************************************************************************
 * \fn vHsmWdg_WindowConfig
 *
 * Config WDG window Reaction and Timeout
 *
 * \return E_OK
 *         E_NOT_OK
 * This function returns: Std_ReturnType
 *****************************************************************************/
static FUNC(Std_ReturnType, WDG_CODE)vHsmWdg_WindowConfig(uint32 Reaction, uint32 timeoutVal,uint32 WindowSize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint32 l_PreloadReg_U32 = 0u;
    uint32 l_PreloadVal_U32 = 0u;
    l_PreloadVal_U32 = vHsmWdg_getPreload(timeoutVal);
    l_PreloadReg_U32 = (l_PreloadVal_U32 >> WDG_DWWDPRLD_MULTIPLIER_SHIFT);
    if (WDG_MAX_PRELOAD_VALUE > l_PreloadReg_U32)
    {
        HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIDWWDSIZECTRL,RTI_RTIDWWDSIZECTRL_DWWDSIZE,WindowSize); /*Set window size by deafult 100% for HSM*/
        HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIDWDPRLD,RTI_RTIDWDPRLD_DWDPRLD,l_PreloadReg_U32); /*Set Preload Value*/
        HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIDWWDRXNCTRL,RTI_RTIDWWDRXNCTRL_DWWDRXN,Reaction);/*Reaction -- Reset or Interrupt*/
        l_RetVal_E = E_OK;
    }
    else
    {
        l_RetVal_E = E_NOT_OK;
    }
    return l_RetVal_E;
}

/********************************************************************************
 * \fn vHsmWdg_clearStatus
 *
 * Clear Status of HSM WDG 
 *
 * \return none
 * This function returns: none
 *****************************************************************************/
static FUNC(void, WDG_CODE)vHsmWdg_clearStatus(void)
{
    uint32 l_Status_U32 = HW_RD_REG32(HSMRTI_BASE_ADDRESS + RTI_RTIWDSTATUS);
    HW_WR_REG32(HSMRTI_BASE_ADDRESS + RTI_RTIWDSTATUS, l_Status_U32);
}

/********************************************************************************
 * \fn vHsmWdg_Enable
 *
 * Enable HSM WDG by writing into WDG Regster
 *
 * \return none
 * This function returns: none
 *****************************************************************************/
static FUNC(void, WDG_CODE) vHsmWdg_Enable(void)
{
    /* Enable DWWD by writing pre-defined value '0xA98559DA' to RTIDWDCTRL    */
    HW_WR_REG32(HSMRTI_BASE_ADDRESS + RTI_RTIDWDCTRL,RTI_RTIDWDCTRL_DWDCTRL_ENABLE);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmWdg_SOCReset
 *********************************************************************************************
 */
FUNC(void, WDG_CODE)vHsmWdg_SOCReset(void)
{
    HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIWDKEY,RTI_RTIWDKEY_WDKEY,RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
    HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIWDKEY,RTI_RTIWDKEY_WDKEY,WDG_RTIWDKEY_WDKEY_INVALID_WRITE);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmWdg_Counter
 *********************************************************************************************
 */
FUNC(uint32, WDG_CODE) vHsmWdg_Counter(void)
{
    return HW_RD_REG32(HSMRTI_BASE_ADDRESS + RTI_RTIDWDCNTR);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmWdg_getPreloadCounter
 *********************************************************************************************
 */
FUNC(uint32, WDG_CODE) vHsmWdg_getPreloadCounter(void)
{
    uint32 PreloadVal;
    PreloadVal = HW_RD_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIDWDPRLD,RTI_RTIDWDPRLD_DWDPRLD);
    PreloadVal = (PreloadVal + 1U) << WDG_DWWDPRLD_MULTIPLIER_SHIFT;
    return(PreloadVal);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmWdg_Service
 *********************************************************************************************
 */
FUNC(void, WDG_CODE) vHsmWdg_Service(void)
{
    /*Write WDG key for servicing*/
    HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIWDKEY,RTI_RTIWDKEY_WDKEY,RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
    HW_WR_FIELD32(HSMRTI_BASE_ADDRESS + RTI_RTIWDKEY,RTI_RTIWDKEY_WDKEY,RTI_RTIWDKEY_WDKEY_SECOND_WRITE);
}

/**
 *********************************************************************************************
 ** \copydoc vHsmWdg_Init
 *********************************************************************************************
 */
FUNC(void, WDG_CODE) vHsmWdg_Init(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
#ifdef HSMWDG_INTERRUPT
    vHsmWdg_InterruptConfig();
#endif
    vHsmWdg_clearStatus();
    l_RetVal_E = vHsmWdg_WindowConfig(HSMWDG_REACTION,HSMWDG_TIMEOUT,HSMWDG_WINDOWSIZE);
    if(l_RetVal_E == E_OK)
    {
        vHsmWdg_Enable();
        TRACE_info("\r\n WDG Pass");
    }
    else
    {
        /*Log error*/
        TRACE_info("\r\n WDG failed");
    }
}

#endif /*HSMWDG_ENABLE*/
/*EOF*/
