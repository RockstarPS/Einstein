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
#include "PmicCdd_Types.h"
#include "OsMain.h"
#include "Dio.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define PMICCDD_I2C_CHANNELID                  1u

#define PMICCDD_I2C_SEQUENCE_NUM                1u

#define PMICCDD_I2C_ENABLE_CRC                  STD_ON
#define PMICCDD_I2C_CRC_RETRYCOUNT               3u

#define PMICCDD_ENABLE_WDG      STD_OFF
#define PMICCDD_ENABLE_ESM      STD_OFF

#define   PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM   0x09

#define PMICCDD_CONV_COMPLETED_CB IoHwAb_AdcMuxNotification

#define PMICCDD_RESET_THRESOLD                        0x05u

#define PMICCDD_SS_EN                                STD_OFF  /* Spread Spectrum Enable*/

#define PMICCDD_CHECK_WAKEUP                       EcuMExt_PmicCdd_CheckWakeup
#define PMICCDD_MANAGE_WAKEUP(x)                      EcuMExt_PmicCdd_ManageWakeup(x)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* Error Report API Declaration */
typedef void (*PmicCdd_ReportErrorFuncPtr)(uint64 error);


typedef struct 
{
    uint8 I2cChannelId; /*I2C Channel Id*/
    uint8 I2cSequenceNum; /*I2C Sequence Number*/
    PmicCdd_ReportErrorFuncPtr PmicCdd_ReportError; /* Error Report API*/
}PmicCdd_GeneralConfigType;


typedef struct
{
    uint32 PmicCdd_GptClockSrc_Hertz; /*GPT Clock Source in hertz*/
    uint16 GptReloadTime_mS; /*GPT Reload time*/
    uint16 GptInitialTimeOut_mS; /*GPT Initial time*/
    ePmicCdd_LongWindow_TimeType ePmicCdd_LongWindow_Time; /*Long window timeout value*/
    ePmicCdd_Win1_2_TimeType ePmicCdd_Win1_Time; /*Long window1 timeout value*/
    ePmicCdd_Win1_2_TimeType ePmicCdd_Win2_Time; /*Long window2 timeout value*/
    uint8 WdgFailedThreshold; /*watchdog failed threshold*/
    uint8 WdgResetThreshold; /*watchdog reset threshold*/
    PmicCdd_WdgModeType WdgMode; /*watchdog operating mode - Fixed for Trigger mode as of now*/
    Dio_ChannelType Dio_WdgTriggerPin; /*Dio pin to be used for WDG trigger*/
}PmicCdd_WdgConfigType;


typedef struct
{
    ePmicCdd_Esm_Delay_1_2_TimeType Delay1_Time; /*Delay1 time*/
    ePmicCdd_Esm_Delay_1_2_TimeType Delay2_Time; /*Delay2 time*/
    ePmicCdd_Esm_H_L_Max_Min_TimeType HMAX_Count; /*HMAX count*/
    ePmicCdd_Esm_H_L_Max_Min_TimeType HMIN_Count; /*HMIN count*/
    ePmicCdd_Esm_H_L_Max_Min_TimeType LMAX_Count;/*LMAX count*/
    ePmicCdd_Esm_H_L_Max_Min_TimeType LMIN_Count;/*LMIN count*/
    uint8 EsmMcuErrCntThreshold;/*ESM MCU error count threshold*/
    PmicCdd_EsmModeType EsmMode;/*ESM operating mode*/
}PmicCdd_EsmConfigType;


typedef struct
{
    PmicCdd_AdcDividerType PmicCdd_AdcDivider;
    PmicCdd_AdcConvSourceType PmicCdd_AdcConvSource;
    PmicCdd_AdcConvType PmicCdd_AdcConv;
}PmicCdd_AdcConfType;

typedef struct 
{
    uint8 EnPBVsenseConf;        /*En, PB, Vsense pin selection*/
    uint8 nIntEndrvConf;        /*nINT, EN_DRV pin selection*/
}PmicCdd_OneTimeCOnfType;

typedef struct
{
    PmicCdd_nINTGpio_TrigType PmicCdd_TrigType;
    Dio_ChannelType Dio_nINTPin;
}PmicCdd_nINTGpioConfType;


typedef struct
{
    /* data */
    PmicCdd_GPIO1ConfigType GPIO1; /*GPIO1 Functionality selection*/
    PmicCdd_GPIO2ConfigType GPIO2; /*GPIO2 Functionality selection*/
    PmicCdd_GPIO3ConfigType GPIO3; /*GPIO3 Functionality selection*/
    PmicCdd_GPIO4ConfigType GPIO4; /*GPIO4 Functionality selection*/
    PmicCdd_GPIO5ConfigType GPIO5; /*GPIO5 Functionality selection*/
    PmicCdd_GPIO6ConfigType GPIO6; /*GPIO6 Functionality selection*/
}PmicCdd_GpiosConfigType;

typedef struct 
{
    uint8 PmicCdd_SwChnID; /* Sw Channel ID*/
    uint8 PmicCdd_HwChnID; /* Hw Channel ID*/
    PmicCdd_GpioDirType PmicCdd_GpioDirection; /* GPIO signal direction */
    PmicCdd_GpioOutDriveType PmicCdd_GpioOutDrive; 
    PmicCdd_GpioPuOrPdResistorSelType PmicCdd_GpioPuOrPdResistorSel;
    PmicCdd_GpioPuOrPdActivateType PmicCdd_GpioPuOrPdActivate;
    PmicCdd_GpioDeglitchType PmicCdd_GpioDeglitch;
}PmicCdd_GpioControlParamsType;

typedef struct
{
    PmicCdd_SpreadSpectrumType PmicCdd_SpreadSpectrum;   /* Spead Spectrum Enabling */
    PmicCdd_SpreadSpectrum_ModulationDepType PmicCdd_SpreadSpectrum_ModulationDep; /* Spread Spectrum Modulation Dependent */
}PmicCdd_SpreadSpectrumConfigType;

extern const PmicCdd_WdgConfigType PmicCdd_WdgConf;
extern const PmicCdd_EsmConfigType PmicCdd_EsmConf;
extern const  PmicCdd_GeneralConfigType PmicCdd_GeneralConf;
extern const PmicCdd_GpioControlParamsType PmicCdd_GpioControlParams[PMICCDD_NUMOF_GPIO_PINS];
extern PmicCdd_AdcConfType PmicCdd_AdcConf;
extern PmicCdd_OneTimeCOnfType PmicCdd_OneTimeConf;
extern const PmicCdd_GpiosConfigType PmicCdd_GpiosConfig;
extern PmicCdd_nINTGpioConfType  PmicCdd_nINTGpioConf;
extern const PmicCdd_SpreadSpectrumConfigType PmicCdd_SpreadSpectrumConfig;

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
void PmicCdd_RstM_ReportError(uint8 ApiId, uint8 ErrorId);

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