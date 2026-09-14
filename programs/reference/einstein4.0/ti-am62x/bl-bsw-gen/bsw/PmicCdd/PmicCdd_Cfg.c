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

File Name        :  PmicCdd_Cfg.c
Module Short Name:  PmicCdd_Cfg.c
VOBName          :  
Author           :  SDV
Description      :  This file contains configurations needed for PmicCdd module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#ifndef PMICCDD_CFG_C
#define PMICCDD_CFG_C


#include "PmicCdd_Cfg.h"
#include "Det.h"
#include "Rte_Type.h"
//#include "Rte_RstM_Type.h"
#include "FltM.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const PmicCdd_GeneralConfigType PmicCdd_GeneralConf =
{
    1U,          /*I2C Channel Id*/
    1U,          /*I2C Sequence Number*/
    NULL_PTR,   /* Error Report API*/
};

const PmicCdd_WdgConfigType PmicCdd_WdgConf =
{
    25000000U,       /* GPT Clock Source in hertz */
    500U,            /* GptInitialTimeOut_mS */
    PMICCDD_LONG_WINDOW_2000MS, /* Long window timeout value in mS */
    PMICCDD_WINDOW_1_2_50050US, /*window1 timeout value*/
    PMICCDD_WINDOW_1_2_50050US, /*window2 timeout value*/
    2U,         /*watchdog failed threshold*/
    2U,         /*watchdog reset threshold*/
    Pmic_TriggerMode,   /*watchdog operating mode - Fixed for Trigger mode as of now*/
    MCU_GPIO0_B01_Ch19  /*Dio pin to be used for WDG trigger*/
};

const PmicCdd_EsmConfigType PmicCdd_EsmConf =
{
    PMICCDD_ESM_DELAY_1_2_496MS, /*Delay1 time*/
    PMICCDD_ESM_DELAY_1_2_496MS, /*Delay2 time*/
    PMICCDD_ESM_H_L_MAX_MIN_3648US, /*HMAX count*/
    PMICCDD_ESM_H_L_MAX_MIN_3648US, /*HMIN count*/
    PMICCDD_ESM_H_L_MAX_MIN_3648US,/*LMAX count*/
    PMICCDD_ESM_H_L_MAX_MIN_3648US, /*LMIN count*/
    7U,/*ESM MCU error count threshold*/
    Level_Mode /*ESM operating mode*/
};

PmicCdd_OneTimeCOnfType PmicCdd_OneTimeConf = 
{
    PMICCDD_ENABLE,
    PMICCDD_NINT
};

PmicCdd_nINTGpioConfType PmicCdd_nINTGpioConf =
{
    PMICCDD_GPIO_TRIG_TYPE_FALL_EDGE,
    CAN_TRCV_MCU_MCAN_0
};


const PmicCdd_GpiosConfigType PmicCdd_GpiosConfig = 
{ 
    .GPIO1 = Pmic_GPIO1_Gpio,
    .GPIO2 = Pmic_GPIO2_TrigWdog,
    .GPIO3 = Pmic_GPIO3_Nsleep1,
    .GPIO4 = Pmic_GPIO4_Nsleep1,
    .GPIO5 = Pmic_GPIO5_ADC_In,
    .GPIO6 = Pmic_GPIO6_nErr_MCU
};



const PmicCdd_GpioControlParamsType PmicCdd_GpioControlParams[PMICCDD_NUMOF_GPIO_PINS] =
{
    {
        0,
        PMICCDD_GPIO1,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },
    {
        1,
        PMICCDD_GPIO2,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },
    {
        2,
        PMICCDD_GPIO3,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },
    {
        3,
        PMICCDD_GPIO4,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },
    {
        4,
        PMICCDD_GPIO5,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },
    {
        5,
        PMICCDD_GPIO6,
        Pmic_GpioInput,
        Pmic_PushPull,
        Pmic_PullDownRes,
        Pmic_PullUpOrDown_Deactivated,
        Pmic_NoDeglitch
    },


};

PmicCdd_AdcConfType PmicCdd_AdcConf =
{
    Pmic_Divideractive,
    Pmci_ADCIn,
    Pmic_AdcContionousConv
};

const PmicCdd_SpreadSpectrumConfigType PmicCdd_SpreadSpectrumConfig =
{
    PmicCdd_SpreadSpectrum_Deactivated,
    PmicCdd_SpreadSpectrum_4
};

const PmicCdd_BuckCtrlParamsType PmicCdd_BuckCtrlParams[PMICCDD_NUMOF_BUCKS] =
{
    {
        PMICCDD_BUCK1,
        PmicCdd_BuckEn_Enabled,
        PmicCdd_BuckFpwmMode_Enabled,
        PmicCdd_BuckVmon_Enabled,
        PmicCdd_BuckPullDown_Activated
    },
    {
        PMICCDD_BUCK2,
        PmicCdd_BuckEn_Disabled,
        PmicCdd_BuckFpwmMode_Enabled,
        PmicCdd_BuckVmon_Disabled,
        PmicCdd_BuckPullDown_Activated
    },
    {
        PMICCDD_BUCK3,
        PmicCdd_BuckEn_Enabled,
        PmicCdd_BuckFpwmMode_Enabled,
        PmicCdd_BuckVmon_Enabled,
        PmicCdd_BuckPullDown_Activated
    },
    {
        PMICCDD_BUCK4,
        PmicCdd_BuckEn_Enabled,
        PmicCdd_BuckFpwmMode_Enabled,
        PmicCdd_BuckVmon_Enabled,
        PmicCdd_BuckPullDown_Activated
    }
};

const PmicCdd_LdoCtrlParamsType PmicCdd_LdoCtrlParams[PMICCDD_NUMOF_LDOS] = 
{
    {
        PmicCdd_LdoEn_Enabled,
        PmicCdd_LdoVmon_Enabled,
        PmicCdd_LdoDischarge_Enabled
    },
    {
        PmicCdd_LdoEn_Enabled,
        PmicCdd_LdoVmon_Enabled,
        PmicCdd_LdoDischarge_Enabled
    },
    {
        PmicCdd_LdoEn_Enabled,
        PmicCdd_LdoVmon_Enabled,
        PmicCdd_LdoDischarge_Enabled
    }
};

const PmicCdd_VccaVmonParamsType PmicCdd_VccaVmonParams =
{
    PmicCdd_VccaVmonEnabled,
    PmicCdd_Vmon1VmonEnabled,
    PmicCdd_Vmon2VmonDisabled,
    PmicCdd_deglitch_0
};
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void PmicCdd_EnterCriticalSection(void)
{
   // osSuspendAllInterrupts();
}
void PmicCdd_ExitCriticalSection(void)
{
    //osResumeAllInterrupts();
}


void PmicCdd_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError(65224U,0x01, ApiId, ErrorId);
    while(1);
}

void PmicCdd_RstM_ReportError(uint8 ErrorCode, uint8 ErrorId)
{
	//void(ErrorCode);
	//void(ErrorId);
}

void PmicCdd_Callout_SMError_Report(uint8 ErrorCode, uint8 ErrorId)
{
	//void(ErrorCode);
	//void(ErrorId);
}

void PmicCdd_Callout_WdgEarlyWarning(const uint8 *DataPtr, uint8 Length)
{
    
}


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
