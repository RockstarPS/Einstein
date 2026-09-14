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
* @file IoHwAb_DOut_Cfg.h
* @brief Configuration definitions for digital output
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Rte_IoHwAb.h"
#include "IoHwAb_PwmIn.h"


#if defined(IOHWAB_PWMIN_ENABLE) && (IOHWAB_PWMIN_ENABLE == STD_ON)
/*****************************************************************************
*  Configuration Definitions                                                 *                                                                                       *
******************************************************************************/
/*period*/
const IoHwAb_PwmInPeriodCfgType IoHwAb_PwmInPeriodCfg[IOHWAB_NUM_OF_PERIOD_SIGNALS] =
                                                                                    {
                                                                                        eIOPeriodInIdSafe_SpeedIn_PWMIN,
                                                                                        eFilter_MovingAvg,
                                                                                        0,
                                                                                        0,
                                                                                        0xFFFFFFFF, 
                                                                                        ICU_RISING_EDGE, 
                                                                                        1, 
                                                                                        IcuConf_IcuChannel_IcuChannel_SPEEDIN_DIGAL_MCU_IN, 
                                                                                        GptConf_GptChannelConfiguration_PIC_Tmr, 
                                                                                        DioConf_DioChannel_DIO_SPEEDIN_DIGAL_MCU_IN    
                                                                                    };




/*Duty*/
const IoHwAb_PwmInDutyCfgType IoHwAb_PwmInDutyCfg[IOHWAB_NUM_OF_DUTY_SIGNALS] =
                                                                                    {
                                                                                        eIODutyInIdSafe_SpeedIn_PWMIN, 
                                                                                        eFilter_Avg,  
                                                                                        0, 
                                                                                        0, 
                                                                                        0xFFFFFFFF,  
                                                                                        1, 
                                                                                        IcuConf_IcuChannel_IcuChannel_SPEEDIN_DIGAL_MCU_IN, 
                                                                                        GptConf_GptChannelConfiguration_PIC_Tmr, 
                                                                                        DioConf_DioChannel_DIO_SPEEDIN_DIGAL_MCU_IN    
                                                                                    };

#endif

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
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Initial Version for IoHwAb_PWmIn safe implementation
******************************************************************************/

