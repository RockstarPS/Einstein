#ifndef STUBS_H
#define STUBS_H

#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "OsTypes.h"
#include "sdl_esm.h"

#define OS_CODE              /*NCHELLAP Added to resolve compilation error from OS function declaration*/
#define ECUAPPM_CODE         /*NCHELLAP Added to resolve compilation error from EcuAppM function declaration*/
#define ECUAPPM_ERRORHANDLER_CODE         /*NCHELLAP Added to resolve compilation error from EcuAppM function declaration*/
#define ECUAPPM_VAR         /*NCHELLAP Added to resolve compilation error from EcuAppM function declaration*/
#define DCM_CODE
#define EA_CODE
#define NVM_CODE

#define ECUWAKEUPM_CODE
#define ECUWAKEUPM_CONST
#define ECUWAKEUPM_APPL_CONST
#define ECUWAKEUPM_VAR_INIT
#define ECUWAKEUPM_VAR_NO_INIT

#define ECUPOWERM_APPL_CONST
#define ECUPOWERM_APPL_DATA
#define ECUPOWERM_CONST
#define ECUPOWERM_CODE
#ifndef NULL
#define NULL ((void *)0)
#endif

#define CANTP_CODE
#define CANTP_CONST

#define CANTP_PBCFG
#define CANTP_VAR_PBCFG

#define CANTP_VAR_INIT
#define CANTP_VAR_NOINIT

#define CANTP_APPL_DATA
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER0			(1)     /*NCHELLAP Stub Added to resolve compilation error from Gpt_PBCfg.c This is added in TI delivered EcuM.h stub*/
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER1			(2)
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER2			(3)
#define	EcuMConf_EcuMWakeupSource_MCU_TIMER3			(4)

#ifndef Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand
#define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand CSigCdd_Impl_OnCommand
#endif


extern void UserPreISRHook(ISRType x);
extern void UserPostISRHook(ISRType x);
extern void UserPreTaskHook(void);
extern void UserPostTaskHook(void);
extern void UserErrorHook(osErrParamType osErrParam);
extern void UserShutdownHook(void);

//extern ProtectionRetType FltMExt_UserProtectionHook(ProtectionErrType errInfo);
//extern void FltMExt_UserErrorHook(const osErrParamType errParam);

// Typedef type TPulseClientId
#ifndef A2T_TypesProtection_TPulseClientId
#define A2T_TypesProtection_TPulseClientId
typedef uint8 TPulseClientId;
#define tTPulseClientId TPulseClientId
#endif
#ifndef eDO_3V3_DISP
#define eDO_3V3_DISP   0
#endif

#ifndef eDO_DISP_RESET
#define eDO_DISP_RESET   1
#endif

#ifndef eDO_DISP_STBY
#define eDO_DISP_STBY   2
#endif

#ifndef eDO_TFT_BL_EN
#define eDO_TFT_BL_EN   3
#endif

#ifndef eDO_SOC_PWR_LATCH
#define eDO_SOC_PWR_LATCH   4
#endif

#ifndef eDO_1V2_EN
#define eDO_1V2_EN   5
#endif

#ifndef eDO_EN_5V
#define eDO_EN_5V   6
#endif

#ifndef eDO_ENET_EN
#define eDO_ENET_EN   7
#endif

#ifndef eDO_LIN_NSLP
#define eDO_LIN_NSLP   8
#endif

#ifndef eDO_RTC_INTN
#define eDO_RTC_INTN   9
#endif

#ifndef eDO_PWM_DIMMING
#define eDO_PWM_DIMMING   10
#endif


#ifndef eDO_DIO_ADC_GPIO_08
#define eDO_DIO_ADC_GPIO_08   11
#endif

#ifndef eDO_DIO_ADC_GPIO_09
#define eDO_DIO_ADC_GPIO_09   12
#endif

#ifndef eDO_DIO_ADC_GPIO_10
#define eDO_DIO_ADC_GPIO_10   13
#endif

#ifndef eDO_DIO_ADC_GPIO_11
#define eDO_DIO_ADC_GPIO_11   14
#endif

#ifndef eDIN_PMIC_INTN
#define eDIN_PMIC_INTN   0
#endif


#ifndef eDIN_IOEXP_AI_MAIN_PWB_TEMP
#define eDIN_IOEXP_AI_MAIN_PWB_TEMP   1
#endif

#ifndef eDIN_IOEXP_AI_TFT_LED_TEMP
#define eDIN_IOEXP_AI_TFT_LED_TEMP   2
#endif

#ifndef eDIN_IOEXP_AI_FALD_BL_TEMP
#define eDIN_IOEXP_AI_FALD_BL_TEMP   3
#endif

#ifndef eDIN_IOEXP_AI_VBATT_MON
#define eDIN_IOEXP_AI_VBATT_MON   4
#endif

void Wdg_ESMInitTest(void);

#ifndef SIMULATION_BUILD
    extern Std_ReturnType SDR_ESM_errorInsert (const SDL_ESM_Inst esmInstType,
    const SDL_ESM_ErrorConfig_t *esmErrorConfig);
#endif    

//EcuWakeupM Icu Stubs : will be removed once Icu integrated - bmalgeka
typedef enum ETag_Icu_ModeType
{
  ICU_MODE_NORMAL,
  ICU_MODE_SLEEP
} Icu_ModeType;
extern void Icu_SetMode(void);
extern void Icu_EnableEdgeDetection(void);
extern void Icu_DisableEdgeDetection(void);
extern void Icu_GetInputState(void);
extern void Icu_EnableWakeup(void);
extern void Icu_DisableWakeup(void);
extern void Icu_CheckWakeup(void);
extern void Icu_EnableNotification(uint8 channel);
extern void Icu_DisableNotification(uint8 channel);
extern void Port_SetToDioMode(void);
extern void Port_SetToAlternateMode(void);
extern void Port_SetPinMode(void);

void Get_LVSD_Flag(boolean *flag);
void Get_HVSD_Flag(boolean *flag);

/*Stub added for build , need to remove stub when RTE and component updated for cmp library*/
#define ECUAPPM_CODE
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEcuWakeupM_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCmicCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSensorCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcIllum_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CMeetCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDataAdapter_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrvCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCtrl_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEarlyHmi_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand(uint8 cmdP);
extern FUNC(Std_ReturnType, ECUAPPM_CODE)  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAppSlpIM_Impl_OnCommand(uint8 cmdP);
#endif
