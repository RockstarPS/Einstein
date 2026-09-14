/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2024. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  PmicCdd_Cfg.h
Module Short Name:  PmicCdd_Cfg.h
VOBName          :
Author           :  SDV
Description      :  This file contains configurations needed for PmicCdd module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#ifndef PMICCDD_CFG_H
#define PMICCDD_CFG_H

#include "Std_Types.h"
#include "OsMain.h"
#include "Dio.h"
#include "Rte_CFltM_Type.h"
#include "EcuMExt.h"

/* Select active variant - configured per project - Overridden to avoid compiler warning */
#define PMICCDD_ACTIVE_VARIANT                          PMICCDD_VARIANT_TPS65224

#include "PmicCdd_Types.h"


/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

#define PMICCDD_I2C_CHANNELID 1u

#define PMICCDD_I2C_SEQUENCE_NUM 1u

#define PMICCDD_I2C_ENABLE_CRC STD_ON
#define PMICCDD_I2C_CRC_RETRYCOUNT 3u
#define PMICCDD_I2C_RETRYCOUNT 5U

#define PMICCDD_ENABLE_WDG STD_ON
#define PMICCDD_ENABLE_ESM STD_OFF


/* ADC - Only available in TPS65224 */
#if (PMICCDD_ACTIVE_VARIANT == PMICCDD_VARIANT_TPS65224)
    #define PMICCDD_ENABLE_ADC          STD_ON
#else
    #define PMICCDD_ENABLE_ADC          STD_OFF
#endif

/* Enabling macro to rewrit the Bucks and Ldos */
#define PMICCDD_ENABLE_BUCKS_LDOS_REWRITE STD_ON

/* macro to decide where to wait for the completion of window 1 + Window2 + Window1/4 time
Enter into longwindow and perform Mcu_Perform reset */
#define PMICCDD_WAIT_FOR_ENTERLONG_WIN STD_ON

// development error macro
#define PMICCDD_DEV_ERROR_DETECT              STD_ON

#undef TEST_SW_HANG
#undef TEST_WDG

/* AM62x R5 free-running timer (32-bit low) */
#ifndef PMICCDD_GTC_LOW_REG
#define PMICCDD_GTC_LOW_REG (0x00A90008U)
#endif
#define PMIC_GTC_TICKS_PER_MS (200000U) /* 200 MHz timer → 200,000 ticks per ms */

#define PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM 0x09U

#define PMICCDD_CONV_COMPLETED_CB IoHwAb_AdcMuxNotification

#define PMICCDD_RESET_THRESOLD 0x00u

#define PMICCDD_SS_EN STD_ON /* Spread Spectrum Enable*/

#define PMICCDD_CHECK_WAKEUP EcuMExt_PmicCdd_CheckWakeup
#define PMICCDD_FLTM_SW_HANG FLTM_E_SW_HANG

#define PMICCDD_FLTM_BUCK1_OVUV                     (FLTM_E_BUCK1_OVUV)
#define PMICCDD_FLTM_BUCK2_OVUV                     (FLTM_E_BUCK2_OVUV)
#define PMICCDD_FLTM_BUCK3_OVUV                     (FLTM_E_BUCK3_OVUV)
#define PMICCDD_FLTM_BUCK4_OVUV                     (FLTM_E_BUCK4_OVUV)
#define PMICCDD_FLTM_LDO1_OVUV                      (FLTM_E_LDO1_OVUV)
#define PMICCDD_FLTM_LDO2_OVUV                      (FLTM_E_LDO2_OVUV)
#define PMICCDD_FLTM_LDO3_OVUV                      (FLTM_E_LDO3_OVUV)
#define PMICCDD_FLTM_VVCA_OVUV                      (FLTM_E_VVCA_OVUV)
#define PMICCDD_FLTM_VMON1_OVUV                     (FLTM_E_VMON1_OVUV)
#define PMIC_ABIST_FAIL                             (FLTM_E_PMIC_ABIST_FAIL)
#define PMICCDD_SAFERECOVERY_POWER_FAULT         (POWER_SUPPLY_FAULT)

/* PMIC Device Information */
#define PMICCDD_DEVICE_ID                          0xAAU
#define PMICCDD_TI_NVM_ID                          0x30U
#define PMICCDD_TI_NVM_REV                         0x01U

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/* Error Report API Declaration */
typedef void (*PmicCdd_ReportErrorFuncPtr)(uint64 error);

typedef struct
{
  uint8 I2cChannelId;                             /*I2C Channel Id*/
  uint8 I2cSequenceNum;                           /*I2C Sequence Number*/
  PmicCdd_ReportErrorFuncPtr PmicCdd_ReportError; /* Error Report API*/
} PmicCdd_GeneralConfigType;

typedef struct
{
  uint32 PmicCdd_GptClockSrc_Hertz;                      /*GPT Clock Source in hertz*/
  uint16 GptInitialTimeOut_mS;                           /*GPT Initial time*/
  ePmicCdd_LongWindow_TimeType ePmicCdd_LongWindow_Time; /*Long window timeout value*/
  ePmicCdd_Win1_2_TimeType ePmicCdd_Win1_Time;           /*Long window1 timeout value*/
  ePmicCdd_Win1_2_TimeType ePmicCdd_Win2_Time;           /*Long window2 timeout value*/
  uint8 WdgFailedThreshold;                              /*watchdog failed threshold*/
  uint8 WdgResetThreshold;                               /*watchdog reset threshold*/
  PmicCdd_WdgModeType WdgMode;                           /*watchdog operating mode - Fixed for Trigger mode as of now*/
  Dio_ChannelType Dio_WdgTriggerPin;                     /*Dio pin to be used for WDG trigger*/
} PmicCdd_WdgConfigType;

typedef struct
{
  ePmicCdd_Esm_Delay_1_2_TimeType Delay1_Time;  /*Delay1 time*/
  ePmicCdd_Esm_Delay_1_2_TimeType Delay2_Time;  /*Delay2 time*/
  ePmicCdd_Esm_H_L_Max_Min_TimeType HMAX_Count; /*HMAX count*/
  ePmicCdd_Esm_H_L_Max_Min_TimeType HMIN_Count; /*HMIN count*/
  ePmicCdd_Esm_H_L_Max_Min_TimeType LMAX_Count; /*LMAX count*/
  ePmicCdd_Esm_H_L_Max_Min_TimeType LMIN_Count; /*LMIN count*/
  uint8 EsmMcuErrCntThreshold;                  /*ESM MCU error count threshold*/
  PmicCdd_EsmModeType EsmMode;                  /*ESM operating mode*/
} PmicCdd_EsmConfigType;

typedef struct
{
  PmicCdd_AdcDividerType PmicCdd_AdcDivider;
  PmicCdd_AdcConvSourceType PmicCdd_AdcConvSource;
  PmicCdd_AdcConvType PmicCdd_AdcConv;
} PmicCdd_AdcConfType;

typedef struct
{
  uint8 EnPBVsenseConf; /*En, PB, Vsense pin selection*/
  uint8 nIntEndrvConf;  /*nINT, EN_DRV pin selection*/
} PmicCdd_OneTimeCOnfType;

typedef struct
{
  PmicCdd_nINTGpio_TrigType PmicCdd_TrigType;
  Dio_ChannelType Dio_nINTPin;
} PmicCdd_nINTGpioConfType;

typedef struct
{
  /* data */
  PmicCdd_GPIO1ConfigType GPIO1; /*GPIO1 Functionality selection*/
  PmicCdd_GPIO2ConfigType GPIO2; /*GPIO2 Functionality selection*/
  PmicCdd_GPIO3ConfigType GPIO3; /*GPIO3 Functionality selection*/
  PmicCdd_GPIO4ConfigType GPIO4; /*GPIO4 Functionality selection*/
  PmicCdd_GPIO5ConfigType GPIO5; /*GPIO5 Functionality selection*/
  PmicCdd_GPIO6ConfigType GPIO6; /*GPIO6 Functionality selection*/
} PmicCdd_GpiosConfigType;

typedef struct
{
  uint8 PmicCdd_SwChnID;                     /* Sw Channel ID*/
  uint8 PmicCdd_HwChnID;                     /* Hw Channel ID*/
  PmicCdd_GpioDirType PmicCdd_GpioDirection; /* GPIO signal direction */
  PmicCdd_GpioOutDriveType PmicCdd_GpioOutDrive;
  PmicCdd_GpioPuOrPdResistorSelType PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_GpioPuOrPdActivateType PmicCdd_GpioPuOrPdActivate;
  PmicCdd_GpioDeglitchType PmicCdd_GpioDeglitch;
} PmicCdd_GpioControlParamsType;

typedef struct
{
  PmicCdd_SpreadSpectrumType PmicCdd_SpreadSpectrum;                             /* Spead Spectrum Enabling */
  PmicCdd_SpreadSpectrum_ModulationDepType PmicCdd_SpreadSpectrum_ModulationDep; /* Spread Spectrum Modulation Dependent */
} PmicCdd_SpreadSpectrumConfigType;

#if(PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
typedef struct
{
  uint8 PmicCdd_BuckHwChnID;                     /* Buck Hardware Channel ID*/
  PmicCdd_BuckEnType PmicCdd_BuckEnable;         /* Buck Enable/Disable */
  PmicCdd_BuckFpwmEnType PmicCdd_BuckFpwmEnable; /* Buck Forced PWM mode Enable/Disable */
  PmicCdd_BuckVmonEnType PmicCdd_BuckVmonEnable; /* Buck Voltage Monitoring Enable/Disable */
  PmicCdd_BuckPullDownType PmicCdd_BuckPullDown; /* Buck Pull-Down Resistor Enable/Disable */
} PmicCdd_BuckCtrlParamsType;

typedef struct
{
  PmicCdd_LdoEnType PmicCdd_LdoEnable;           /* LDO Enable/Disable */
  PmicCdd_LdoVmonEnType PmicCdd_LdoVmonEnable;   /* LDO Voltage Monitoring Enable/Disable */
  PmicCdd_LdoDischargeType PmicCdd_LdoDischarge; /* LDO Discharge Enable/Disable */
} PmicCdd_LdoCtrlParamsType;
#endif

typedef struct
{
  PmicCdd_VccaVmonEnType PmicCdd_VccaVmonEnable;   /* VCCA Voltage Monitoring Enable/Disable */
  PmicCdd_Vmon1VmonEnType PmicCdd_Vmon1VmonEnable; /* VMON1 Voltage Monitoring Enable/Disable */
  PmicCdd_Vmon2VmonEnType PmicCdd_Vmon2VmonEnable; /* VMON2 Voltage Monitoring Enable/Disable */
  PmciCdd_DeglitchType PmicCdd_VccaVmonDeglitch;   /* VCCA Voltage Monitoring Deglitch Enable/Disable */
} PmicCdd_VccaVmonParamsType;

extern const PmicCdd_WdgConfigType PmicCdd_WdgConf;
extern const PmicCdd_EsmConfigType PmicCdd_EsmConf;
extern const PmicCdd_GeneralConfigType PmicCdd_GeneralConf;
extern const PmicCdd_GpioControlParamsType PmicCdd_GpioControlParams[PMICCDD_NUMOF_GPIO_PINS];
extern PmicCdd_AdcConfType PmicCdd_AdcConf;
extern PmicCdd_OneTimeCOnfType PmicCdd_OneTimeConf;
extern const PmicCdd_GpiosConfigType PmicCdd_GpiosConfig;
extern PmicCdd_nINTGpioConfType PmicCdd_nINTGpioConf;
extern const PmicCdd_SpreadSpectrumConfigType PmicCdd_SpreadSpectrumConfig;
#if(PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
extern const PmicCdd_BuckCtrlParamsType PmicCdd_BuckCtrlParams[PMICCDD_NUMOF_BUCKS];
extern const PmicCdd_LdoCtrlParamsType PmicCdd_LdoCtrlParams[PMICCDD_NUMOF_LDOS];
#endif
extern const PmicCdd_VccaVmonParamsType PmicCdd_VccaVmonParams;

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
void PmicCdd_EnterCriticalSection(void);
void PmicCdd_ExitCriticalSection(void);
void PmicCdd_Det_ReportError(uint8 ApiId, uint8 ErrorId);
void PmicCdd_Callout_SMError_Report(uint8 ErrorCode, uint8 ErrorId);
void EcuMExt_PmicCdd_CheckWakeup(void);
/* Declaration of your API wrapper function */
void PmicCdd_Callout_WdgEarlyWarning(const uint8 *DataPtr, uint8 Length);

extern ePmicCdd_ErrIntType PmicCdd_GeneralConfigPtr(uint64 error);

extern void IoHwAb_AdcMuxNotification(void);

#endif
/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  05-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3280
Change Description: PmicCdd initial release, Added support for WDG and ADC
        Initialization and functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  26-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3709
Change Description: Added support for ESM configuration and Error interrupt checking,
            Reporting and clear functionalities.
-----------------------------------------------------------------------------*/