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
* @file IoHwAb_Pwm_Cfg.h
* @brief Configuration header file for PWM output
* ****************************************************************************/
#ifndef IoHwAb_Pwm_Cfg_H
#define IoHwAb_Pwm_Cfg_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/


#include "Std_Types.h"
#include "Rte_Type.h"


//msavariy :-
//typedef uint8 IoHwAb_PwmSignalIdType; //Rte_Type.h

/*****************************************************************************
*  Prublic Macros Definitions                                                *
******************************************************************************/






/**
* @brief Macro to enable the IoHwAb Digital output Module
*/
#define IOHWAB_PWM_ENABLE			STD_OFF
/*****************************************************************************
*  Private Macros Definitions                                                *
******************************************************************************/
#if (IOHWAB_PWM_ENABLE == STD_ON)

#define IOHWAB_NUM_OF_PWM_VARIANT   1u             

#define IOHWAB_MAX_NUM_OF_PWM_VARIANT  1u

/*Macro defines number of PWM period inputs*/
#define IOHWAB_NUM_OF_PWM_OUTPUT   17

#define IOHWAB_MAX_DUTY_VAL             0x8000 
#define IOHWAB_MAX_PERIOD_VAL           0xFFFF

#define IOHWAB_PWMS_STATE_ACTIVE     1u
#define IOHWAB_PWMS_STATE_IDEAL      0u

 #define IOHWAB_PWM_REFRESH_PERCYCLE     1U

//#define IoHwAb_ErrorType  IoHwAbSafe_ErrorType


/*****************************************************************************
*  Type Declarations                                                         *
******************************************************************************/


typedef struct
{
    Pwm_ChannelType   Pwm_ChannelId;  /**< Mcal Pwm channel id*/
	uint8 PwmDuty_ResolutionId;
    uint8 PwmPeriod_ResolutionId;	
} IoHwAb_PwmChannelType;


typedef struct
{
  IoHwAb_PwmChannelType IoHwAb_PwmChannel[IOHWAB_NUM_OF_PWM_VARIANT];
  IoHwAb_PwmSignalIdType  SignalId; 
} IoHwAb_PwmCfgType;

extern const IoHwAb_PwmCfgType IoHwAb_PwmCfg[IOHWAB_NUM_OF_PWM_OUTPUT];
/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/

Std_ReturnType IoHwAb_Pwm_GetCurrentVariant(uint8* PwmVariantId);
Std_ReturnType IoHwAb_Pwm_PreHook(void);
/*****************************************************************************
*  Private Forward Declarations                                          	 *
******************************************************************************/


#endif
#endif /* IOHWAB_PWM_CFG_H */

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
Date              :7-Feb-2020
By                :PPARIMI1
Traceability      :758686: JLR RICM IoHwAb PWM changes				   
Change Description:Initial Version for IoHwAb PWM chnages
******************************************************************************/

