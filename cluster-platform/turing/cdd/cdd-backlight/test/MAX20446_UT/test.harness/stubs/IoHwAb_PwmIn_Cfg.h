/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*!***************************************************************************
* @ingroup Input-Output Hardware Abstraction
* @file IoHwAb_PwmIn_Cfg.h
* @brief Configuration header file for digital output
* ****************************************************************************/
#ifndef IoHwAb_PwmIn_Cfg_H
#define IoHwAb_PwmIn_Cfg_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#include "IoHwAb_Filter.h"
#include "Gpt.h"
#include "Icu.h"
#include "Dio.h"
#include  "Std_Types.h"

/*****************************************************************************
*  Prublic Macros Definitions                                                *
******************************************************************************/
/**
* @brief Macro to enable the IoHwAb Digital output Module
*/
#define IOHWAB_PWMIN_ENABLE			STD_ON
/*****************************************************************************
*  Private Macros Definitions                                                *
******************************************************************************/
#if defined(IOHWAB_PWMIN_ENABLE) && (IOHWAB_PWMIN_ENABLE == STD_ON)

/// Macro defines number of PWM period inputs
#define IOHWAB_NUM_OF_PERIOD_SIGNALS   1

/// Macro defines number of PWM duty inputs
#define IOHWAB_NUM_OF_DUTY_SIGNALS   1

#define eIOPeriodInIdSafe_SpeedIn_PWMIN	   0
#define eIODutyInIdSafe_SpeedIn_PWMIN      0

/*****************************************************************************
*  Type Declarations                                                         *
******************************************************************************/

typedef struct
{
    uint8 PeriodId;
    EFilterMethod FilterType_period;
    uint8 FilterCfgIx_period;
    uint8 ResolutionCalc_FilterCfgIx_period;
    uint32 TimerCountMax; ///< Maximum Count Value of corresponding FRT Timer channel
    Icu_ActivationType ActivationEdge; ///< Activation Edge for Icu channel    
    uint16 NotificationInterval; ///< Number of edges/events after which notification function will be invoked
    Icu_ChannelType HwId; ///< HW Id
    Gpt_ChannelType TmrChannelId; ///< Physical TimerChannel
    Dio_ChannelType DioChnlId; ///< Dio Channel Id
}IoHwAb_PwmInPeriodCfgType;

typedef struct
{
    uint8 DutyId;
    EFilterMethod FilterType_duty;
    uint8 FilterCfgIx_duty;
    uint8 ResolutionCalc_FilterCfgIx_duty;
    uint32 TimerCountMax; ///< Maximum Count Value of corresponding FRT Timer channel
    boolean ActiveDutyPolarity; ///< Polarity needs to be considered for pwm duty calculation, 0-active low period, 1-active high period
    Icu_ChannelType HwId; ///< HW Id
    Gpt_ChannelType TmrChannelId; ///< Physical TimerChannel
    Dio_ChannelType DioChnlId; ///< Dio Channel Id
}IoHwAb_PwmInDutyCfgType;



/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/

/*Period*/
extern const IoHwAb_PwmInPeriodCfgType IoHwAb_PwmInPeriodCfg[IOHWAB_NUM_OF_PERIOD_SIGNALS];

/*Duty*/
extern const IoHwAb_PwmInDutyCfgType IoHwAb_PwmInDutyCfg[IOHWAB_NUM_OF_DUTY_SIGNALS];


/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/


#endif
#endif /* IOHWAB_PWMIN_CFG_H */

/*End of File*/
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :nrajaman
Traceability      :
Change Description:Initial Version for IoHwAb_PulseOut safe implementation
******************************************************************************/
/*****************************************************************************
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Initial Version for IoHwAb_PWmIn safe implementation
******************************************************************************/
/*****************************************************************************
Date              :26-Dec-2018
By                :asivalin
Traceability      :1260028: Integrate the latest PIC Integrated IoHwAb base in SP2 & Release.
Change Description:PIC Configuration Update as per Hyundai SP2
******************************************************************************/
