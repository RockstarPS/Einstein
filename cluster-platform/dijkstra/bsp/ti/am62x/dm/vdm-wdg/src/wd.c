/***************************************************************************
 **
 **  \file WD.c
 **
 **  \brief Interface to interact with the RTI watchdog of TI-AM62P
 **
 **  Component Name: WD
 **  Archive:
 **  Date: Jun 17 2025
 **  \author: Krassimire Stoyanov
 **
 **  \copyright 2025 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/
#include <drivers/device_manager/sciclient.h>
#include <drivers/bootloader.h>
#include <sdl/rti/v0/sdl_rti.h>
#include <sdl/sdl_esm.h>
#include <sdl/rti/v0/sdl_ip_rti.h>
#include <sdl/dpl/sdl_dpl.h>
#include <drivers/sciclient.h>
#include <drivers/hw_include/cslr.h>
#include <drivers/hw_include/am62px/cslr_mcu_ctrl_mmr.h>
#include <kernel/dpl/AddrTranslateP.h>
#include "wd.h"

#define RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ        (32U)
#define RTI_CLOCK_SOURCE_12_5MHZ_FREQ_KHZ        (12500U)
#define RTI_CLOCK_SOURCE_25MHZ_FREQ_KHZ        (25000U)

#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_MASK                  (0x00000007U)
#define SDL_MCU_CTRL_MMR0_CFG0_BASE                                         (0x4500000UL)
#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL                               (0x045080B0U)
#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL_MASK                  (0x00000007U)
#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)

#define CFG0_WKUP_CTRL_MMR_WKUP_WWD0_CLKSEL (0x43008380u)

#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL                               (0x00008184U)
#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_SHIFT                 (0x00000000U)
#define SDL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL_MAX                   (0x00000007U)

typedef enum rtiClockSource
{
    RTI_CLOCK_SOURCE_HFOSC0_CLKOUT = 0U,
    /**< to select clock frequency of hfosc0 */
    RTI_CLOCK_SOURCE_LFOSC_CLKOUT = 1U,
    /**< to select clock frequency of lfosc */
    RTI_CLOCK_SOURCE_12_5MHZ = 2U,
    /**< to select clock frequency of 12 MHz */
    RTI_CLOCK_SOURCE_32KHZ = 3U,
    /**< to select clock frequency of 32KHz */
}rtiClockSource_t;
	
static uint32_t Wdg_Status = 0;

static const SDL_ESM_config RTI_esmInitConfig_wkup =
{
    .esmErrorConfig = {0u, 3u}, /* Self test error config */
    .enableBitmap = {0x00000000u, 0x00000000u, 0x0400000u, 0x00000000u,
                },
     /**< All events enable: except timer and self test  events, and Main ESM output */
    /* Temporarily disabling vim compare error as well*/
    .priorityBitmap = {0x00000000u, 0x00000000u, 0x0400000u, 0x00000000u,
                        },
    /**< All events high priority: except timer, selftest error events, and Main ESM output */
    .errorpinBitmap = {0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u,
                      },
    /**< All events high priority: except timer, selftest error events, and Main ESM output */
};

 /*!**************************************************************************************************************
    * \fn         SDL_ESM_applicationCallbackFunction
    * \brief      Callback function for ESM module
    * \param[in]  esmInst - ESM Instance
    * \param[in]  grpChannel - group channel
    * \param[in]  index
	* \param[in]  intSrc - interrupt source
	* \param[in]  arg - argument passed to ESM_Init
    * \return     int    Return Error code to indicate success or failure - usually SDL_PASS
 ****************************************************************************************************************/
static int32_t SDL_ESM_applicationCallbackFunction(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,  uint32_t index, uint32_t intSrc, void *arg)
{
    int32_t retVal = SDL_PASS;

    DebugP_log("\n   Interrupt is generated to ESM\n");
    DebugP_log("   ESM Call back function called : instType 0x%x, intType 0x%x, " \
                "grpChannel 0x%x, index 0x%x, intSrc 0x%x \n",
                esmInst, esmIntrType, grpChannel, index, intSrc);
    DebugP_log("   Take action \n");

    /* For clearing the interrupt */
    //IntrDisable(intSrc);

    return retVal;
}

 /*!**************************************************************************************************************
    * \fn         RTISetClockSource
    * \brief      Select clock source for RTI Watchdog
    * \param[in]  rtiModuleSelect - RTI WD Instance
    * \param[in]  rtiClockSourceSelect - clock source
    * \return     void
 ****************************************************************************************************************/
static void RTISetClockSource(uint32_t rtiModuleSelect,
                              uint32_t rtiClockSourceSelect)
{
    uint32_t baseAddr;
	switch (rtiModuleSelect) {
#if defined (SOC_AM62X)
#if defined (M4F_CORE)
        case SDL_MCU_RTI0_CFG_BASE:
			baseAddr = (uint32_t)SDL_DPL_addrTranslate(SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL, SDL_WKUP_CTRL_MMR0_CFG0_SIZE);
            HW_WR_FIELD32(baseAddr,
                          SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
#endif
#if defined (R5F_CORE)
        case SDL_WKUP_RTI0_CFG_BASE:
			baseAddr = (uint32_t)SDL_DPL_addrTranslate(SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL, SDL_WKUP_CTRL_MMR0_CFG0_SIZE);
            HW_WR_FIELD32(baseAddr,
                          SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
#endif
#endif
#if defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX)
        case SDL_WKUP_RTI0_CFG_BASE:
			baseAddr = CFG0_WKUP_CTRL_MMR_WKUP_WWD0_CLKSEL;
            HW_WR_FIELD32(baseAddr,
                          SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
        case SDL_MCU_RTI0_CFG_BASE:
			baseAddr = (uint32_t)SDL_DPL_addrTranslate(SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL, SDL_WKUP_CTRL_MMR0_CFG0_SIZE);
            HW_WR_FIELD32(baseAddr,
                          SDL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
#endif
	}
}

 /*!**************************************************************************************************************
    * \fn         RTIGetPreloadValue
    * \brief      Select preload value for RTI Watchdog
    * \param[in]  rtiClkSource - clock source
    * \param[in]  rtiClkSource - timeout in milliseconds
    * \return     Number of WD cycles
 ****************************************************************************************************************/
static uint32_t RTIGetPreloadValue(uint32_t rtiClkSource, uint32_t timeoutVal)
{
    uint32_t clkFreqKHz       = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ;
    uint32_t        timeoutNumCycles = 0;

    switch (rtiClkSource)
    {
        case RTI_CLOCK_SOURCE_32KHZ:
		    // special calculation due to reduced precision (it is later divided by 8182, so few bits used at 32KHz), 
			// the possible step is 250ms
		    return (uint32_t)((32768*timeoutVal)/1000-8192); 
        case RTI_CLOCK_SOURCE_LFOSC_CLKOUT:
            clkFreqKHz = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ;
            break;
        case RTI_CLOCK_SOURCE_HFOSC0_CLKOUT:
            clkFreqKHz = (uint32_t) RTI_CLOCK_SOURCE_25MHZ_FREQ_KHZ;
            break;
        case RTI_CLOCK_SOURCE_12_5MHZ:
            clkFreqKHz = (uint32_t) RTI_CLOCK_SOURCE_12_5MHZ_FREQ_KHZ;
        break;
        default:
            break;
    }
    /* Get the clock ticks for given time-out value */
    timeoutNumCycles = timeoutVal * clkFreqKHz;
    return timeoutNumCycles;
}

 /*!**************************************************************************************************************
    * \fn         Wdg_getStatus
    * \brief      Gets and optionally clears the status of RTI Watchdog
    * \param[in]  baseAddr - base address of RTI WD instance
    * \return     WD status register
 ****************************************************************************************************************/
static uint32_t Wdg_getStatus(uint32_t baseAddr, int Clear)
{
	uint32_t ret = HW_RD_REG32(baseAddr + RTI_RTIWDSTATUS); //get the flags
	if (Clear) HW_WR_REG32(baseAddr + RTI_RTIWDSTATUS,ret); // clear the register
    return ret;
}

 /*!**************************************************************************************************************
    * \fn         Wdg_getCounter
    * \brief      Gets the counter of the RTI Watchdog
    * \param[in]  baseAddr - base address of RTI WD instance
    * \return     WD counter register
 ****************************************************************************************************************/
static uint32_t Wdg_getCounter(uint32_t baseAddr)
{
	uint32_t ret = HW_RD_REG32(baseAddr + RTI_RTIDWDCNTR); //get the counter
    return ret;
}

 /*!**************************************************************************************************************
    * \fn         InternalWatchdog_PrintResetStatus
    * \brief      Prints status of RTI Watchdog, taken while enabling WD
    * \return     void
 ****************************************************************************************************************/
void InternalWatchdog_PrintResetStatus(void)
{
	// Message if restarted by WD
	if (Wdg_Status!=0)
		DebugP_log("\r\nRestarted by DM RTI Watchdog - status = 0x%08X\r\n",Wdg_Status);
}

 /*!**************************************************************************************************************
    * \fn         InternalWatchdog_Service
    * \brief      Service (pet) the watchdog
    * \return     void
 ****************************************************************************************************************/
void InternalWatchdog_Service(void)
{
	uint32_t baseAddr = SDL_WKUP_RTI0_CFG_BASE;
	/* First write operation 0xE51A */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
	/* Second write operation 0xA35C */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_SECOND_WRITE);

}

 /*!**************************************************************************************************************
    * \fn         InternalWatchdog_DoReset
    * \brief      Cause the watchdog to reset the system
    * \return     void
 ****************************************************************************************************************/
void InternalWatchdog_DoReset(void)
{
	uint32_t volatile baseAddr = SDL_WKUP_RTI0_CFG_BASE;
	/* First write operation not 0xE51A */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_MASK);
	/* Second write operation not 0xA35C */
	HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
				  RTI_RTIWDKEY_WDKEY,
				  RTI_RTIWDKEY_WDKEY_MASK);

	while(baseAddr);
}




 /*!**************************************************************************************************************
    * \fn         RTIWDStart
    * \brief      Config and start the watchdog
    * \return     void
 ****************************************************************************************************************/
static void	RTIWDStart(SDL_RTI_configParms*pConfig)
{
	uint32_t baseAddr = SDL_WKUP_RTI0_CFG_BASE;
	
	/* Initialize DWD Window size */
	SDL_RTI_writeWinSz(baseAddr, pConfig->SDL_RTI_dwwdWindowSize);
	
    /* Initialize DWD Expiration Period */
    HW_WR_FIELD32(baseAddr + RTI_RTIDWDPRLD,
                     RTI_RTIDWDPRLD_DWDPRLD,
                   (pConfig->SDL_RTI_dwwdPreloadVal >>RTI_DWWDPRLD_MULTIPLIER_SHIFT));

	SDL_RTI_writeReaction(baseAddr, pConfig->SDL_RTI_dwwdReaction);
	
	/* Enable DWWD by writing pre-defined value '0xA98559DA' to RTIDWDCTRL */
	HW_WR_REG32(baseAddr + RTI_RTIDWDCTRL,
				RTI_RTIDWDCTRL_DWDCTRL_ENABLE);

}


 /*!**************************************************************************************************************
    * \fn         InternalWatchdog_Enable
    * \brief      Enable the watchdog, call after system init
    * \return     void
 ****************************************************************************************************************/
void InternalWatchdog_Enable(void)
{
	SDL_RTI_configParms Config;
	static uint32_t arg;

    int status = SOC_moduleClockEnable(TISCI_DEV_WKUP_RTI0,1);
	if(status != SystemP_SUCCESS)
	{
		DebugP_logError("SOC_moduleClockEnable : Fail Status %d \r\n", status);
	}

    status = SOC_moduleSetClockFrequency( TISCI_DEV_WKUP_RTI0, TISCI_DEV_WKUP_RTI0_RTI_CLK, RTI_CLOCK_SOURCE_12_5MHZ_FREQ_KHZ*1000);
	if(status != SystemP_SUCCESS)
	{
		DebugP_logError("SOC_moduleSetClockFrequency : Fail Status %d \r\n", status);
	}

	Wdg_Status = Wdg_getStatus(SDL_WKUP_RTI0_CFG_BASE,1); // store the initial WD status
			
	status = Sciclient_pmSetModuleState(TISCI_DEV_WKUP_RTI0,	
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                            TISCI_MSG_FLAG_AOP,
                                            SystemP_WAIT_FOREVER);	
	if(status != SystemP_SUCCESS)
	{
		DebugP_logError("Sciclient_pmSetModuleState : Fail Status %d \r\n", status);
	}

    status = SDL_ESM_init(SDL_ESM_INST_WKUP_ESM0, &RTI_esmInitConfig_wkup, SDL_ESM_applicationCallbackFunction, (void *)&arg);
	if(status != SDL_PASS)
	{
		DebugP_logError("SDL_ESM_init : Fail Status %d \r\n", status);
	}
				
											
    /* Reset Ctrl belongs to partition 6 of the CTRL MMR */
	{
		uint32_t     rstPartition = 6U;
		uint32_t     baseAddr ;

		SOC_controlModuleUnlockMMR(SOC_DOMAIN_ID_MCU, rstPartition);
		baseAddr = (uint32_t) AddrTranslateP_getLocalAddr(CSL_MCU_CTRL_MMR0_CFG0_BASE);
		CSL_REG32_FINS((baseAddr + CSL_MCU_CTRL_MMR_CFG0_RST_CTRL), MCU_CTRL_MMR_CFG0_RST_CTRL_MCU_ESM_ERROR_RST_EN_Z, 0);
		SOC_controlModuleLockMMR(SOC_DOMAIN_ID_MCU, rstPartition);
	}


    Config.SDL_RTI_dwwdPreloadVal = RTIGetPreloadValue(RTI_CLOCK_SOURCE_12_5MHZ, RTI_WDT_TIMEOUT);
    Config.SDL_RTI_dwwdWindowSize = RTI_DWWD_WINDOWSIZE_100_PERCENT;
    Config.SDL_RTI_dwwdReaction   = RTI_DWWD_REACTION_GENERATE_NMI;
	
    /* Select RTI module clock source */
   // RTISetClockSource(SDL_WKUP_RTI0_CFG_BASE, RTI_CLOCK_SOURCE_12MHZ);
	
	RTIWDStart(&Config);

}

#ifdef RTI_WDT_TEST
void InternalWatchdog_Test(void)
{   int max; // at some point, when max reaches 356 per second (approx.), WD reset is expected
	for (max=RTI_WDT_TIMEOUT/6; max<4*RTI_WDT_TIMEOUT; max++) 
	{
		int r;
		for (r=0; r<=max; r++)
		{
			uint32_t c = Wdg_getCounter(SDL_WKUP_RTI0_CFG_BASE);
			uint32_t s = Wdg_getStatus(SDL_WKUP_RTI0_CFG_BASE,0);
			DebugP_log("cnt0x%08X st0x%08X %d\r\n",c,s,r);
		}
		if (max>337)
		while(1)
		{
			uint32_t c = Wdg_getCounter(SDL_WKUP_RTI0_CFG_BASE);
			uint32_t s = Wdg_getStatus(SDL_WKUP_RTI0_CFG_BASE,0);
			DebugP_log(" cnt0x%08X st0x%08X %d\r\n",c,s,r);
			//InternalWatchdog_DoReset();
		}
		InternalWatchdog_Service();
	}
}
#endif
