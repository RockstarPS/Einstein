//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
/*****************************************************************************
*  File Name         :  EcuMExt.c                                            *
*  Module Short Name :  EcuMExt                                              *
*  Description       :  This file contains implementations of the Ecu        *
*                       State Manager callouts specified by Autosar          *
*                       This is an intergration code for EcuMgr              *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  CLANG                                                  *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef ECUM_EXT_C
#define ECUM_EXT_C
//
//---------------------------------------------------------------------------------------------------------------------

#define ECUM_CALLOUT_STUBS_SOURCE
#include "EcuM.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */


/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/
#include "EcuMExt.h" 
#include <stdint.h>
#include "Mcu.h"
#include "Dio.h"
#include "Spi.h"
#include "CddIpcAppRProcLinux.h"
#include "DioApp.h"
#include <hw_include/soc.h>
#include <hw_include/lld_gpio.h>
#include <hw_include/arch/lld_arch.h>
#include <hw_include/cslr.h>
#include <drivers/sciclient.h>
#include "AssertLib.h"
#include "NvM.h"
#include "MemIf.h"
#include "Ea.h"
#include "EepDrv.h"
#include "I2c.h"
#include "WdgM.h"
#include "Gpt.h"
#include "Apm.h"
#include "IoHwAb.h"
#include "IoExp.h"
#include "vHsmIpc.h"
#if AUTOSAR_ETH_ENABLE
#include "EthIf.h"
#include "EthSM.h"
#include "TcpIp.h"
#include "SoAd.h"
#include "DoIP.h"
#include "Eth_DrvInit.h"
#endif
#include "ComM.h"
#include "Wdg.h"
#include "SciDrv.h"
#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "CanSM.h"
#include "Com.h"
#include "Dcm.h"
#include "Dem.h"
#include "Lin.h"
#include "PduR.h"
#include "EcuAppM.h"
#include "EcuWakeupM.h"
#include "LinIf.h"
#include "LinNm.h"
#include "LinSm.h"
#include "LinTp.h"
#include "LinTrcv.h"
#include "Xcp.h"
#include "CanNm.h"
#include "Nm.h"
#include "CanIf_Cbk.h"
#include "PmicCdd.h"
#include "LedDrv.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "CanStub.h"
#include "Icu.h"
#include "Port.h"
// #include "RstM.h"
#include "Crypto.h"
#include "SysTst.h"
#include "FltM.h"
#include "CanTrcv.h"
#include "SafeNvM.h"
#include "ComXf.h"
#include "mcasp.h"
#include "Csm.h"
#include "CryIf.h"
#include "ti_drivers_open_close.h"
#include "DltExt.h"
#include "E2EXf.h"
#include "EcuM_PrivateCfg.h"
#include "EcuWakeupM.h"
#ifdef VIP_UART_TEST
    #include "DltExt.h"
#endif

#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/

#include "udma.h"
#include "ti_drivers_config.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define IGN_WAKEUP_THRESHOLD                       500U
#define CHECK_DURATION                             1000U
#define U16_MAX                             ((uint16)0xFFFFU)
#define DIO_MASK                            ((uint32)0x01U)
#define ECUM_POWER_ON 0x3A3A3A3AU
#define ECUM_SLEEP_WAKEUP 0xA5A53A3AU
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================



#define ECUMEXT_DATA_START
#include "MemMap.h"


/* flag to indicate that NvM reading at startup is finished */
static boolean NvM_ReadAll_Finished = FALSE;
volatile uint8 RetStatus = 0;
//#issue Review Problem ID 133351: Name 'IsAWakeup', McuGetResetReason,GetResetReason visibility is too wide.
//#issue Review Problem ID 152118: Static global variable 'IsAWakeup', McuGetResetReason,GetResetReason  only used in 'EcuMExt_Internal_CheckWakeup' has a wide visibility
static boolean IsIgnWakeUpDetected;
static boolean IsWakeUpFromIgn;
static boolean Is_PmicCdd_Wakeup = FALSE;
extern CONST(struct Spi_ConfigType_s, SPI_CONFIG_DATA) SpiDriver;
extern const struct Pwm_ConfigType_s PwmChannelConfigSet;
extern const struct Gpt_ConfigType_s GptChannelConfigSet;
extern const struct Can_ConfigType_s CanConfigSet;

__attribute__((section(".RetentionRAM_Group1")))
static uint32 SleepMagigFlag = ECUM_SLEEP_WAKEUP; //#issue Review Problem ID 149170: Unsigned integer literal '0xA5A53A3A' without the 'U' suffix
static inline uint32 PmicCdd_Reg32_Rd(uint32 addr_u32)
{
    return (*(volatile uint32 *)(addr_u32));
}

#define ECUMEXT_DATA_END
#include "MemMap.h"

#define ECUMEXT_CODE_SEC_START
#include "MemMap.h"

void Pinmux_init(void);
void PowerClock_init(void);

#ifdef DSS_TEST_ENABLED
/* Declaration to resolve compiler warning */
void DssDisplayAppInit(void);
#endif

static void EcuMExt_CheckIGNPinstatus(void);
static void EcuMExt_GetIgnWakeUpState(boolean *pIsIgnWakeUp); //#issue Review Problem ID 133338: Function or object 'EcuMExt_GetIgnWakeUpState' redeclaration does not include 'static' modifier
static void EcuMExt_PmicCdd_ManageWakeup(PmicCdd_ResetReasonType resetReason);
static void EcuMExt_OnEnterSleep (void);


/* API to check the Wakeup Event by confirming in PMIC and Buram*/
static void EcuMExt_Internal_CheckWakeup(void);
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
/*============================================================================
**
** Function Name    :   EcuMExt_GetNvmReadAllStatus
**
** Visibility       :   Public
**
** Description      :   This interface returns NVM Read All statu.
**
** Invocation       :
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
boolean EcuMExt_GetNvmReadAllStatus(void)
{
    return NvM_ReadAll_Finished;
}

/*============================================================================
**
** Function Name    :   EcuMExt_DeActivateAll
**
** Visibility       :   Public
**
** Description      :   Deactivates immediately all components. Used only by CANoe PC simulation, to simulate shut down of the system.
**
** Invocation       :
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuMExt_DeActivateAll(void)
{
}

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   EcuM_ErrorHook
**
** Visibility       :   Public
**
** Description      :   Handling of runtime errors.Provides the possibility to react on errors which occurs during the runtime of the ECU.
**
** Invocation       :   Called from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_ErrorHook(uint16 reason)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ErrorHook>                         DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    (void)reason;     /* PRQA S 3112 */ /* MD_EcuM_3112 */
    #endif
    /* Add implementation of EcuM_ErrorHook() */

    /* In case of an inconsistent configuration data, abort initialization here */
    if(reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
    {
        DEBUG_ASSERT(FALSE);  //#issue Review Problem ID 27343: Expression is cast to a type of potentially different size
    }

    #if (ECUM_NUMBER_OF_CORES > 1)
    /* In case of an invalid coreId, returned by the OS */
    if (reason == ECUM_E_HOOK_INVALID_COREID)
    DEBUG_ASSERT(FALSE);
    #endif
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_ErrorHook() */

/**********************************************************************************************************************
 *  CALLOUTS FROM THE SHUTDOWN PHASE
 *********************************************************************************************************************/

/*============================================================================
**
** Function Name    :   EcuM_OnGoOffOne
**
** Visibility       :   Public
**
** Description      :   Go Off One callout.This callout can be used to perform user specific code in the Go Off I state of the EcuM which is
**                      executed in context of EcuM_GoDown() prior the BswM and the SchM are de-initialized.
**
** Invocation       :   Called from EcuM_GoDown in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_OnGoOffOne( void )
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffOne>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnGoOffOne() */

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnGoOffOne() */

/*============================================================================
**
** Function Name    :   EcuM_ShutdownOS
**
** Visibility       :   Public
**
** Description      :   Shut down the Os.This callout can be used to shut down the Os. If it is necessary e.g. for safety projects to perform
**                         this in a different context, the context switch can be initiated from here.
**
** Invocation       :   Called from EcuM_GoDown in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_ShutdownOS(Std_ReturnType ErrCode)   //#issue Review Problem ID 27316: Formal parameter 'ErrCode' of function 'EcuM_ShutdownOS' is not used
{
    (void)ErrCode;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ShutdownOS>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_ShutdownOS() */
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_ShutdownOS() */

/*============================================================================
**
** Function Name    :   EcuM_OnGoOffTwo
**
** Visibility       :   Public
**
** Description      :   Go Off Two callout.This callout can be used to perform user specific code in the Go Off II state of the EcuM which is
**                      executed at the beginning of EcuM_Shutdown().
**
**
** Invocation       :   Called from EcuM_Shutdown in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_OnGoOffTwo( void )
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffTwo>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnGoOffTwo() */

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnGoOffTwo() */

/*============================================================================
**
** Function Name    :   EcuM_AL_SwitchOff
**
** Visibility       :   Public
**
** Description      :   Switches off the ECU.This callout implements the shutdown of the power supply of the ECU.
**
** Invocation       :   Called from EcuM_Shutdown in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SwitchOff>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_AL_SwitchOff() */

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_AL_SwitchOff() */

/*============================================================================
**
** Function Name    :   EcuM_AL_Reset
**
** Visibility       :   Public
**
** Description      :   Reset the ECU.This callout implements the code for resetting the ECU.
**
** Invocation       :   Called from EcuM_Shutdown in EcuM.
**
** Inputs           :    Reset - The ID of the current reset mode..
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_Reset>                          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    if(Reset == ECUM_RESET_MCU)
    {
        Mcu_PerformReset();
    }
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_AL_Reset() */



/**********************************************************************************************************************
 *  CALLOUTS FROM THE STARTUP PHASE
 *********************************************************************************************************************/
/*============================================================================
**
** Function Name    :   EcuM_AL_DriverInitZero
**
** Visibility       :   Public
**
** Description      :    Driver Initialization Zero.Provides driver initialization and other hardware-related startup activities for loading the
**                         post-build configuration data.
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_AL_DriverInitZero( void )
{
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_INIT_ZERO, "DRVINIZERO");
    #endif   /*BOOT_KPI_LOG_EN*/
    Det_Init(NULL_PTR);
    return;
}

/*============================================================================
**
** Function Name    :   EcuM_AL_DriverInitOne
**
** Visibility       :   Public
**
** Description      :    Driver Initialization One.Provides driver initialization and other hardware-related startup activities prior the start of the OS.
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_AL_DriverInitOne(const EcuM_ConfigType * ConfigPtr)
{
    static Mcu_ResetType McuGetResetReason;   
    //#issue Review Problem ID 152121: Local variable 'instId' is never used
    (void)(* ConfigPtr);
    Std_ReturnType retVal = E_NOT_OK;
    Mcu_ClockType clockSetting = 0u;
    uint8 clockCfg;
    clockCfg = McuModuleConfiguration_0.Mcu_NumberOfClockConfig;
    McuGetResetReason  = MCU_RESET_UNDEFINED;
    IsWakeUpFromIgn = FALSE;

    Mcu_Init(&McuModuleConfiguration_0);
    McuGetResetReason = Mcu_GetResetReason(); 
    for(clockSetting=0; clockSetting<clockCfg ; clockSetting++)
    {
        retVal = Mcu_InitClock(clockSetting);
        (void)retVal;
    }
    SOC_setEpwmTbClk(0U, TRUE);			 
    SOC_setEpwmTbClk(1U, TRUE);			 
    SOC_setEpwmTbClk(2U, TRUE);
    /* Added this Functionality for Initializing DSS and MCASP clock */
    PowerClock_init();
    Port_Init(&PortConfig_RUN);

	System_init();

    /* Function added to verify if the A53 core is ready for ipc communication */
   // CddIpcCommunicationTest();
    Spi_Init(&SpiDriver);  //#issue Review Problem ID 27334: Incomplete struct type 'Spi_ConfigType_s' is used
    (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    I2c_Init();
    (void)SciDrv_Init(pSciDrvCfg);

    Pwm_Init(&PwmChannelConfigSet);  //issue Review Problem ID 133349: Incomplete struct type 'Pwm_ConfigType_s' is used

    /* Initialize the CddIpc */
    Cdd_IpcInit();

    
    Gpt_Init(&GptChannelConfigSet);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_MCU_TIMER1, 0xFFFFFFFEU);   //#issue Review Problem ID 27336: Unsigned integer literal '0xFFFFFFFE' without the 'U' suffix
    TmExt_Init();

    /*BswFitCdd initialization state*/
    BswFitCdd_Init();
    /* IGN Pin Status Check */
    EcuMExt_CheckIGNPinstatus();
    EcuMExt_GetIgnWakeUpState(&IsWakeUpFromIgn);

#ifdef DSS_TEST_ENABLED
    /* Test Application Driver Init for DSS*/
    DssDisplayAppInit();
#endif
#ifdef ESM_RTI_TEST
    /* Example ESM init for Wdg RTI instance */
    Wdg_ESMInitTest();
    Wdg_Init((const Wdg_ConfigType *) NULL_PTR);
#endif /* ESM_RTI_TEST */
#ifdef APM_ENABLED
    Apm_Init();
#endif
    Icu_Init(&Icu_Config);
    NvM_Init(NULL);
    Ea_Init(NULL);
    EepDrv_Init(NULL);
#if AUTOSAR_ETH_ENABLE
    /* Ethernet stack Initialization */
    Eth_DrvInit();
    EthIf_Init(NULL_PTR);
    EthSM_Init();
    TcpIp_Init(NULL_PTR);
    SoAd_Init(&SoAd_ConfigData);
    DoIP_Init(NULL_PTR);
#endif
	/* CAN stack Initialization */
    Can_Init(&CanConfigSet);
    CanTrcv_Tja1145ATK_Init();
    CanTrcv_InitMemory();
    CanTrcv_Init(NULL_PTR);
    CanIf_Init(NULL_PTR);
    CanSM_Init(NULL_PTR);
    Can_PlatformInit();
    CanTp_Init(NULL_PTR);
    CanNm_Init(NULL_PTR);
    /* LIN stack Initialization */
    //Lin_Init(NULL_PTR);
    //LinIf_Init(NULL_PTR);
    //LinNm_Init(NULL_PTR);
    //LinSM_Init(NULL_PTR);
    //LinTp_Init(NULL_PTR);
    //LinTrcv_Init(NULL_PTR);
    /* com services stack Initialization */
    ComM_Init(NULL_PTR);
    Com_Init(NULL_PTR);
    PduR_Init(NULL_PTR);
    ComXf_Init(NULL_PTR);
    Xcp_Init(NULL_PTR);
    Nm_Init(NULL_PTR);

    Dcm_Init(NULL_PTR);
    Dem_PreInit();
    vHsmIpc_Init();
    Csm_Init();
    CryIf_Init(NULL_PTR);
    CryptoDrv_Init();
    

    if(MCU_POWER_ON_RESET_MCU_DOMAIN == McuGetResetReason)
    {
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_RESET);
    }
    else 
    {
        /* Reset due to any other reason */
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_RESET);
    }
    /*Dio pin to be used for WDG trigger*/
    Dio_WriteChannel(MCU_GPIO0_B01_Ch19, STD_LOW);
    /* GPIO Latch Pin connected to WAKEUP logic set HIGH */
    Dio_WriteChannel(Main_GPIO1_Channel_5, STD_HIGH);
    (void)Drivers_open(); //#issue Review Problem ID 152138: Function 'Drivers_open' is called but has no prototype and The return value of the non-void function 'Drivers_open' shall be used.
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_INIT_ONE, "DRVINIONE"); 
    #endif   /*BOOT_KPI_LOG_EN*/ 
    return;
}

/**********************************************************************************************************************
* EcumExt_IsResetPath
*
* To get the status of the reset reason form AppCtrl for CmpLib wakeup state implementation
**********************************************************************************************************************/
Std_ReturnType EcumExt_IsResetPath(void)
{
  Std_ReturnType RetVal;

  RetVal = FALSE;

  return RetVal;
}

#if (ECUM_SLEEPMODELIST == STD_ON)
/*============================================================================
**
** Function Name    :   EcuM_AL_DriverRestartList
**
** Visibility       :   Public
**
** Description      :    Re-Initialize Drivers.Provides driver re-initialization after regaining from a low power mode.
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void)
{

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_AL_DriverRestartList  */

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}
#endif

void EcuM_AL_DriverRestart(const EcuM_ConfigType * ConfigPtr)
{
    (void)ConfigPtr;

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_AL_DriverRestartList  */

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/*============================================================================
**
** Function Name    :   EcuM_AL_DriverInitTwo
**
** Visibility       :   Public
**
** Description      :   Driver Initialization Two.Provides driver initialization and other hardware-related startup activities after the start of the OS
**                      but prior NvM data is available.
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType * ConfigPtr)
{
    static volatile uint32_t wkup_mmr_src_reg;   //#issue Review Problem ID 149061: Extern global variable 'wkup_mmr_src_reg' only used in 'EcuM_AL_DriverInitTwo' has a wide visibility
    static volatile uint32_t mcu_mmr_src_reg;

    (void)ConfigPtr;
    CanStub_StartEarlyCommunication();
    wkup_mmr_src_reg = PmicCdd_Reg32_Rd(PMIC_WKUP_MMR_SRC_REG_ADDR);
    mcu_mmr_src_reg  = PmicCdd_Reg32_Rd(PMIC_MCU_MMR_SRC_REG_ADDR);

#ifdef APM_ENABLED
    /* Start APM Measurement */
    Apm_StartMeasurement();
#endif
    SysTst_Init();
    EcuWakeupM_Init();
    EcuAppM_Init();
    IoExp_Init();
    IoHwAb_Init();
    //Enabling for PmicCdd nINt pin 
    Icu_EnableNotification(0);
    WdgM_Init(&WdgM_ConfigParam[0]);
    (void)WdgM_SetMode(WDGM_SLOW_MODE,0U);
    EcuWakeupM_ReportAllWakeupSources();
    (void)E2EXf_Init(NULL); //#issue Review Problem ID 152141: The return value of the non-void function 'E2EXf_Init' shall be used.
//#issue Review Problem ID 152139: Function 'E2EXf_Init' is called but has no prototype


#ifdef PLATFORM_ECUM_CONTROL
    EcuMExt_RequestRUN(0);
#endif
    
#if LED_DRV_ENABLE
    LedDrv_Init();
#endif
    Dlt_Init(NULL);
    DltExt_Init();

    #ifdef VIP_UART_TEST
    #if (DLTEXT_UART_PRINT == STD_ON)
      (void)DltExt_Uart_Printf("wkup_mmr_src_reg=0x%08X, mcu_mmr_src_reg=0x%08X\r\n", wkup_mmr_src_reg, mcu_mmr_src_reg); //#issue Review Problem ID 149162: The return value of the non-void function 'DltExt_Uart_Printf' shall be used.
    #endif
    #endif

	(void)RstM_EnableResetIsolation(); //Return value must be used or cast to void
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_INIT_TWO, "DRVINITWO"); 
    #endif   /*BOOT_KPI_LOG_EN*/

    return;
    /**********************************************************************************************************************
     * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
     *********************************************************************************************************************/
}

/*============================================================================
**
** Function Name    :   EcuM_NvmExt_ReadAll_Start
**
** Visibility       :   Public
**
** Description      :  NvmExt ReadAll Start call for speedup process
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_NvmExt_ReadAll_Start (void)
{
    /*NvM_ReadAll();*/ /* NCHELLAP Commented out for NVM Read ALL to be invoked from EcuAppM */
}

/*============================================================================
**
** Function Name    :   EcuM_AL_DriverInitThree
**
** Visibility       :   Public
**
** Description      :   Driver Initialization Three.Provides driver initialization and other hardware-related startup activities with available NvM data
**
** Invocation       :   Called  from EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_AL_DriverInitThree (const EcuM_ConfigType * ConfigPtr)
{
    (void)ConfigPtr;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitThree>                DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #ifdef VIP_UART_TEST
   (void)DltExt_Uart_Printf("VIP is Booted Up!!\r\n");
   #endif
   /* Below two Api's are added to transmit CAN message after ReadAll 
      This to be removed once actual CAN Tx is done in application */
    // ComM_TestActivate();
    // stackTest();
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/*============================================================================
**
** Function Name    :   EcuM_StartOS
**
** Visibility       :   Public
**
** Description      :   Starts the Os.The Os is started in context of this callout. If some preparation is needed like starting cores,
**                        this can be done before.
**
** Invocation       :   Called  from EcuM_Init in EcuM.
**
** Inputs           :    appMode - The application mode which shall be passed to the OS.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_StartOS(AppModeType appMode)
{
    (void)appMode;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartOS>                           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_StartOS() */
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_StartOS() */

/**********************************************************************************************************************
 *  CALLOUTS FROM THE SLEEP PHASE
 *********************************************************************************************************************/

#if (( ECUM_NUMBER_OF_CORES > 1 ) && (ECUM_SLEEPMODELIST == STD_ON))
/*============================================================================
**
** Function Name    :   EcuM_WaitForSlaveCores
**
** Visibility       :   Public
**
** Description      :   Synchronization with slave cores.Slave cores can be triggered in context of this callout to enter their sleep state.
**
** Invocation       :   Called  from EcuM_EnterSleep in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_WaitForSlaveCores(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_WaitForSlaveCores>                 DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_WaitForSlaveCores() */

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_WaitForSlaveCores() */
#endif

#if(ECUM_SLEEPMODELIST == STD_ON)
/*============================================================================
**
** Function Name    :   EcuM_CheckRamHash
**
** Visibility       :   Public
**
** Description      :   Checks the RAM hash.This callout can be used to check the RAM hash after the ECU has regained from a low power mode.
**
** Invocation       :   Called  from EcuM_InternalEnterHaltMode in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_GenerateRamHash(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GenerateRamHash>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_GenerateRamHash() */

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_GenerateRamHash() */

/*============================================================================
**
** Function Name    :   EcuM_CheckRamHash
**
** Visibility       :   Public
**
** Description      :   Checks the RAM hash.This callout can be used to check the RAM hash after the ECU has regained from a low power mode.
**
** Invocation       :   Called  from EcuM_InternalEnterHaltMode in EcuM.
**
** Inputs           :    None.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_CheckRamHash(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckRamHash>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_CheckRamHash() */

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_CheckRamHash() */

/*============================================================================
**
** Function Name    :   EcuM_McuSetMode
**
** Visibility       :   Public
**
** Description      :   Sets the Mcu mode.
**                        The Mcu mode for a reduced power mode, a sleep mode or to restore the normal mcu mode can be performed
**                        in this callout. If some preparation is needed like enabling or disabling of interrupts, this can also
**                        be done inside this callout.
**
** Invocation       :   Called  from  EcuM.
**
** Inputs           :    McuMode - The ID of the Mcu mode which shall be set.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode)
{
    (void)McuMode;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_McuSetMode>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_McuSetMode() */
    /* GPIO Latch Pin set LOW to enter suicide mode Since all wakeups are deactivated */
    Dio_WriteChannel(Main_GPIO1_Channel_5, STD_LOW);
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_McuSetMode() */

/*============================================================================
**
** Function Name    :   EcuM_EnableWakeupSources
**
** Visibility       :   Public
**
** Description      :   Enable wakeup sources..Enable wakeup interrupts for the specific sources which should be active for the upcoming sleep phase..
**
** Invocation       :   Called  from EcuM_EnterSleep in EcuM
**
** Inputs           :    wakeupSource - The wakeup source to start, passed as a bitmask.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_EnableWakeupSources (EcuM_WakeupSourceType wakeupSource )
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_EnableWakeupSources>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
    /* Add implementation of EcuM_EnableWakeupSources() */
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_EnableWakeupSources() */

/*============================================================================
**
** Function Name    :   EcuM_StartWakeupSources
**
** Visibility       :   Public
**
** Description      :   Starts procedure for validation of a wakeup source
**
** Invocation       :   Called  from  EcuM
**
** Inputs           :   wakeupSource - The wakeup source to start validation for, passed as a bitmask.
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    (void)wakeupSource;
}

/*============================================================================
**
** Function Name    :   EcuM_StopWakeupSources
**
** Visibility       :   Public
**
** Description      :   Stops procedure for validation of a wakeup source
**
** Invocation       :   Called  from  EcuM
**
** Inputs           :   wakeupSource - The wakeup source to stop validation for, passed as a bitmask.
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    (void)wakeupSource;
}

/*============================================================================
**
** Function Name    :   EcuM_CheckValidation
**
** Visibility       :   Public
**
** Description      :   Checks if a given wakeup source is valid
**
** Invocation       :   Called  from  EcuM
**
** Inputs           :   wakeupSource - The wakeup source to check for validation, passed as a bitmask.
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
void EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
    (void)wakeupSource;
}
/*============================================================================
**
** Function Name    :   EcuM_DisableWakeupSources
**
** Visibility       :   Public
**
** Description      :   Disable wakeup sources.Disable wakeup interrupts for the specific sources which were active in the past sleep phase.
**
** Invocation       :   Called  from  EcuM
**
** Inputs           :    wakeupSource - The wakeup source to start, passed as a bitmask.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource )
{
    (void)wakeupSource;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DisableWakeupSources>              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_DisableWakeupSources() */
#endif

/*============================================================================
**
** Function Name    :   EcuM_CheckWakeup
**
** Visibility       :   Public
**
** Description      :   Interface for wakeup check
**
** Invocation       :   Called  from EcuM_InternalEnterPollingMode in EcuM
**
** Inputs           :    wakeupSource - The wakeup source to start, passed as a bitmask.
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
void EcuM_CheckWakeup ( EcuM_WakeupSourceType wakeupSource )/* PRQA S 1503 */ /* MD_MSR_14.1 */
{
    Std_ReturnType CanStatus;
#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* Do not remove the following function call. It is necessary for the CheckWakeup timeout mechanism */
    EcuM_StartCheckWakeup(wakeupSource);
#endif

    // /**********************************************************************************************************************
    // * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckWakeup>                       DO NOT CHANGE THIS COMMENT!
    // *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    (void)wakeupSource; /* PRQA S 3112 */ /* MD_EcuM_3112 */
#endif
    /* Add implementation of EcuM_CheckWakeup() */
    // See Specification of ECU State Manager -- CAN Wake-up Sequences where in EcuM_CheckWakeup is calling CanIf_CheckWakeup
    CanStatus = CanIf_CheckWakeup(wakeupSource);
    if((uint8)E_OK == CanStatus)
    {
        // Can drviver itsef do not call CanIf_ControllerModeIndication(ControllerId,CAN_CONTROLLER_STOPPED) in case of Early Wake Up,
        // so calling it here:
    	CanIf_ControllerModeIndication(0u, CANIF_CS_STOPPED);
    }

    EcuWakeupM_CheckWakeup(wakeupSource);
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_CheckWakeup() */


/**********************************************************************************************************************
 *  CALLOUTS FROM THE UP PHASE
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  On Entry / Exit callouts for EcuM Fixed Statemachine
 *********************************************************************************************************************/
# if(ECUM_FIXED_BEHAVIOR == STD_ON)
/*============================================================================
**
** Function Name    :   EcuM_OnEnterRun
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the run state is about to be entered.
**
** Invocation       :   Called  from EcuM_ActEnterRun in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnEnterRun(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnEnterRun>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnEnterRun() */

/*============================================================================
**
** Function Name    :   EcuM_OnExitRun
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the run state is about to be leaved.
**
** Invocation       :   Called  from EcuM_Statemachine in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnExitRun(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnExitRun>                         DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnExitRun() */
    //EcuWakeupM_EnableAllWakeups(TRUE);
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnExitRun() */

# if (ECUM_SLEEPMODELIST == STD_ON)
/*============================================================================
**
** Function Name    :   EcuM_OnGoSleep
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the go sleep state is about to be entered.
**
** Invocation       :   Called  from EcuM_Statemachine in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnGoSleep(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoSleep>                         DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnGoSleep() */
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnGoSleep() */
# endif
/*============================================================================
**
** Function Name    :   EcuM_OnPrepShutdown
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the prepare shutdown state is about to be entered.
**
** Invocation       :   Called  from EcuM_Statemachine in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnPrepShutdown(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnPrepShutdown>                    DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnPrepShutdown() */

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnPrepShutdown() */

/*============================================================================
**
** Function Name    :   EcuM_OnExitPostRun
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the post run state is about to be leaved.
**
** Invocation       :   Called  from EcuM_Statemachine in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnExitPostRun(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnExitPostRun>                     DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnExitPostRun() */
    // (void)Rte_Call_If_CS_EcumExt_Swc_CallOut_EcuM_OnExitPostRun();
// #ifdef PLATFORM_COMM_CONTROL
    // EcuMExt_DisableComCommunication();
// #endif
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnExitPostRun() */

//#if(ECUM_INCLUDE_NVRAM_MGR == STD_ON)
/*============================================================================
**
** Function Name    :   EcuM_OnFailedNvmWriteAllJobReaction
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the NvM WriteAll was not successful.
**
** Invocation       :   Called  from EcuM_WaitOnNvMWriteAll in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnFailedNvmWriteAllJobReaction(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnFailedNvmWriteAllJobReaction>    DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnFailedNvmWriteAllJobReaction() */

    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnFailedNvmWriteAllJobReaction() */
//#endif

/*============================================================================
**
** Function Name    :   EcuM_OnWakeupReaction
**
** Visibility       :   Public
**
** Description      :   This callout allows the system designer to notify that the wakeup reaction state is about to be entered.
**
** Invocation       :   Called  from EcuM_Statemachine in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
EcuM_WakeupReactionType EcuM_OnWakeupReaction(EcuM_WakeupReactionType wact)
{
    (void)wact;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnWakeupReaction>                  DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    /* Add implementation of EcuM_OnWakeupReaction() */

    return 1U;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnWakeupReaction() */

/*============================================================================
**
** Function Name    :   EcuM_OnRTEStartup
**
** Visibility       :   Public
**
** Description      :   User-specific code, prior to the Rte is started is implemeted here.
**
** Invocation       :   Called  from EcuM_StartupTwo in EcuM.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, ECUM_CODE) EcuM_OnRTEStartup(void)
{
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnRTEStartup>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
    // (void)Rte_Call_If_CS_EcumExt_Swc_CallOut_EcuM_OnRTEStartup();
    #ifdef BOOT_KPI_LOG_EN
        BOOT_KPI_LOG(KPI_ID_VIP_RTE_START, "RTE_START");
    #endif   /*BOOT_KPI_LOG_EN*/
    return;
    /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnRTEStartup() */

#endif
/*============================================================================
**
** Function Name    :   NvM_MultiBlockJobEndNotification
**
** Visibility       :   Public
**
** Description      :   Notification from NvM that the memory has been read/write.
**
** Invocation       :   Called  from NVM.
**
** Inputs           :    ServiceId - Id of NVM service
**
** Outputs          :    JobResult - result from operation
**
** Critical Section :
**
**==========================================================================*/

boolean Get_NvMReadAllResult(void)
{
    return NvM_ReadAll_Finished;
}


/*============================================================================
**
** Function Name    :   EcuMExt_MainFunction
**
** Visibility       :   Public
**
** Description      :   EcumExt main function.
**
** Invocation       :   Called periodically from OsTask_10msEcuM on 10ms periodic event.
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/

void EcuMExt_MainFunction( void )
{
    static boolean flWakeState = FALSE;
    static PmicCdd_ResetReasonType flGetResetReason;
    Lin_DrvTest();
#ifdef APM_ENABLED
    Apm_MainFunction();
#endif

    // Double check for Wakeup - Using PMIC and Buram
    if(flWakeState == FALSE)   //Expression 'flWakeState' used in the condition always yields the same result
    {
        if((Is_PmicCdd_Wakeup == TRUE) && (NvM_ReadAll_Finished == TRUE))
        {
            flGetResetReason = PmicCdd_GetResetReason();
            EcuMExt_Internal_CheckWakeup();
            EcuMExt_PmicCdd_ManageWakeup(flGetResetReason);
            flWakeState = TRUE;
        }
    }
}

/*============================================================================
**
** Function Name    :   EcuM_OnEnterSleep
**
** Visibility       :   Public
**
** Description      :   This call allows the system designer to implement the
**                      activities to be done before entering into MCU Sleep
**
** Invocation       :   On entry of SLEEP state
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_OnEnterSleep (void)
{
    E2EXf_DeInit();
}

/*============================================================================
**
** Function Name    :   EcuMExt_OnEnterSleep
**
** Visibility       :   Private
**
** Description      :   This call allows the system designer to implement the
**                      activities to be done before entering into MCU Sleep
**
** Invocation       :   On entry of SLEEP state
**
** Inputs           :    None
**
** Outputs          :    None
**
** Critical Section :
**
**==========================================================================*/
static void EcuMExt_OnEnterSleep (void)
{


}
/*============================================================================
**
** Function Name    :   EcuMExt_ReleaseRUN
**
** Visibility       :   Public
**
** Description      :   This call allows to call EcuM_ReleaseRUN
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuMExt_ReleaseRUN(EcuM_UserType user)
{
    Std_ReturnType retval;

    retval = EcuM_ReleaseRUN(user);

    return retval;
}

/*============================================================================
**
** Function Name    :   EcuMExt_RequestRUN
**
** Visibility       :   Public
**
** Description      :   This call allows to call EcuM_RequestRUN
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuMExt_RequestRUN(EcuM_UserType user)
{
     Std_ReturnType retval;

    retval = EcuM_RequestRUN(user);

    return retval;
}

/*============================================================================
**
** Function Name    :   NvM_MultiBlockJobEndNotification
**
** Visibility       :   Public
**
** Description      :   Notification from NvM that the memory has been read/write.
**
** Invocation       :   Called  from NVM.
**
** Inputs           :    ServiceId - Id of NVM service
**
** Outputs          :    JobResult - result from operation
**
** Critical Section :
**
**==========================================================================*/
void NvM_MultiBlockJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult)
{
  if (ServiceId == NVM_READ_ALL)
  {
    if (JobResult != (uint8)NVM_REQ_PENDING)
    {
      NvM_ReadAll_Finished = TRUE;
      Dem_Init(NULL_PTR);
      EcumExt_SafeNvM_TriggerDataCompare();
      EcuM_CB_NfyNvMJobEnd((uint8) ServiceId,(NvM_RequestResultType) JobResult);
      if(JobResult == NVM_REQ_OK)
      {
        #ifdef VIP_UART_TEST
        #if (DLTEXT_UART_PRINT == STD_ON)
            (void)DltExt_Uart_Printf("\r\n NvM ReadAll success ! \r\n");
        #endif
        #endif
      }
      else
      {
        #ifdef VIP_UART_TEST
        #if (DLTEXT_UART_PRINT == STD_ON)
            (void)DltExt_Uart_Printf("\r\n NvM ReadAll failed ! \r\n");
        #endif
        #endif
      }
    }
  }
}

/*============================================================================
**
** Function Name    :   EcuMExt_CheckIGNPinstatus
**
** Visibility       :   Private
**
** Description      :   Function is check the Wakeup by Ignition
**
** Invocation       :   Called  from EcuMExt.
**
** Inputs           :    void
**
** Outputs          :    void
**
** Critical Section :
**
**==========================================================================*/
static void EcuMExt_CheckIGNPinstatus(void)
{
    uint32 DioChannelState;
    uint16 HighLevelCnt = 0U;
    uint16 Cnt = CHECK_DURATION;

    while (Cnt > 0U)
    {
        DioChannelState = Dio_ReadChannel(Main_GPIO0_Channel_90);
        if ((DioChannelState & DIO_MASK) == DIO_MASK) /* Check if it is in HIGH level */
        {
            HighLevelCnt++;
        }
        Cnt--;
    }

    if (HighLevelCnt >= IGN_WAKEUP_THRESHOLD)
    {
        IsIgnWakeUpDetected = TRUE;
    }
}

/*============================================================================
**
** Function Name    :   EcuMExt_GetIgnWakeUpState
**
** Visibility       :   Private
**
** Description      :   Function to get the Wakeup Ignition status
**
** Invocation       :   Called  from EcuMExt.
**
** Inputs           :    void
**
** Outputs          :    void
**
** Critical Section :
**
**==========================================================================*/
static void EcuMExt_GetIgnWakeUpState(boolean *pIsIgnWakeUp)
{
    if(NULL_PTR != pIsIgnWakeUp)
    {
        *pIsIgnWakeUp = IsIgnWakeUpDetected;
    }
}

/*============================================================================
**
** Function Name    :   EcuMExt_PmicCdd_CheckWakeup
**
** Visibility       :   Publicc
**
** Description      :   Function to set the Wakeup Status from PmicCdd
**
** Invocation       :   Called from PmicCdd.
**
** Inputs           :    void
**
** Outputs          :    void
**
** Critical Section :
**
**==========================================================================*/
/* API called from PMICCDD to check the wakeup */
void EcuMExt_PmicCdd_CheckWakeup(void)
{
    Is_PmicCdd_Wakeup = TRUE;
}

static void EcuMExt_Internal_CheckWakeup(void)
{
    static PmicCdd_ResetReasonType GetResetReason;
    static boolean IsAWakeup;

    IsAWakeup = FALSE;
    /* Check thi E2E ticket number - 1512612 : Reason why Mcu_GetResetReason is not used*/
    GetResetReason = PmicCdd_GetResetReason();

    if((PmicCdd_Wakeup == GetResetReason) && (SleepMagigFlag == ECUM_SLEEP_WAKEUP))
    {
        IsAWakeup = TRUE;
        if(FALSE != IsWakeUpFromIgn)
        {
            EcuM_SetWakeupEvent(ECUM_WKSOURCE_IGN);
        }
        else
        {
            EcuM_SetWakeupEvent(ECUM_WKSOURCE_RESET);
        }
    }
    else if(PmicCdd_PmicWdg_Reset == GetResetReason)
    {
        /* Reset due to any other reason - Pmic Wdg Reset or Power On for the 1st time */
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_EXTERNAL_WDG);
        IsAWakeup = TRUE;
    }
    else
    {
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_RESET);
    }

    if(IsAWakeup != FALSE)
    {
        //Checking the wakeupEvent
        EcuWakeupM_ScanAllWakeupChannels();
    } 
}

/*============================================================================
**
** Function Name    :   EcuMExt_PmicCdd_ManageWakeup
**
** Visibility       :   Public
**
** Description      :   Function to set the Wakeup Status from PmicCdd
**
** Invocation       :   Called from PmicCdd.
**
** Inputs           :    void
**
** Outputs          :    void
**
** Critical Section :
**
**==========================================================================*/
/* API called from PMICCDD to Report Wakeupsource to EcuAppM */
static void EcuMExt_PmicCdd_ManageWakeup(PmicCdd_ResetReasonType resetReason)
{
    EcuWakeupM_ChannelType Channel;

    if(PmicCdd_PmicWdg_Reset == resetReason)
    {
        // Reset Reason - Pmic Wdg Reset
        EcuWakeupM_GetWakeupChannel(ECUWAKEUPM_WAKEUP_CHANNEL_EXT_WDG,&Channel);
        (void)EcuWakeupM_ReportWakeupSource(Channel); //#issue Review Problem ID 133346: The return value of the non-void function 'EcuWakeupM_ReportWakeupSource' shall be used.
    }
    else if ((PmicCdd_Wakeup == resetReason) && (SleepMagigFlag == ECUM_SLEEP_WAKEUP))
    {
        // Reset Reason - IGN Wakeup
        EcuWakeupM_GetWakeupChannel(ECUWAKEUPM_WAKEUP_CHANNEL_IGN,&Channel);
        (void)EcuWakeupM_ReportWakeupSource(Channel);
    }
    else
    {
        EcuWakeupM_GetWakeupChannel(ECUWAKEUPM_WAKEUP_RESET,&Channel);
        (void)EcuWakeupM_ReportWakeupSource(Channel);
    }

    SleepMagigFlag = ECUM_POWER_ON;
}
/*============================================================================
**
** Function Name    :   EcuMExt_CustomCommandCallout
**
** Invocation       :   Function is called from EcuAppM_Cfg file
**
**
**==========================================================================*/
Std_ReturnType EcuMExt_CustomCommandCallout(uint8 channel, uint16 * value, uint8 * error)
{
    Std_ReturnType retval = E_OK;
    uint16 data = (uint16)0;
    if(value != NULL)
    {
        data = *value;
    }
    #ifndef WIN32 
    (void)OsTrustedCall_IoHwAb_SetOutputPin(channel,(boolean)data, error);
    #endif
    return retval;

}
#define ECUM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ECUMEXT_CODE_SEC_END
#include "MemMap.h"

#endif /*ECUM_EXT_C*/

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 08/Feb/2024
By                : nchellap
Traceability      : BMIC29130-7080
Change Description: EcumExt initial version 
-----------------------------------------------------------------------------------------*/
