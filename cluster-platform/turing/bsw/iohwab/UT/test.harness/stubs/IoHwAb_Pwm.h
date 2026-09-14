//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef IoHwAb_Pwm_H
#define IoHwAb_Pwm_H

#include "IoHwAb_Pwm_Cfg.h"



#if (IOHWAB_PWM_ENABLE == STD_ON)
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================



//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================
/*Define the type for periodId */

extern void IoHwAb_Pwm_Init(void);
extern void IoHwAb_Pwm_DeInit(void);
extern void IoHwAb_Pwm_MainFunction(void); 
extern void IoHwAb_PWM_Edge_Notify(IoHwAb_PwmSignalIdType PwmID);

/* Set the duty*/
/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetDuty is in Os_TrustedServiceCfg.h and does not have any functional impact.*/
extern Std_ReturnType IoHwAb_Pwm_SetDuty(IoHwAb_PwmSignalIdType PwmId, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus);

/*Set Period and duty */
/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetDutyAndPeriod is in Os_TrustedServiceCfg.h and does not have any functional impact.*/
extern Std_ReturnType IoHwAb_Pwm_SetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId , uint32 Pwm_Period, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus);

/* Set channel state to Ideal - LOW */
/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetIdeal is in Os_TrustedServiceCfg.h and does not have any functional impact.*/
extern Std_ReturnType IoHwAb_Pwm_SetIdeal(IoHwAb_PwmSignalIdType PwmId,  IoHwAb_ErrorType* ErrorStatus);


#endif

#endif /* IoHwAb_Pwm_H*/

/* End of File*/
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
/*****************************************************************************
Date              :2-Jun-2020
By                :bbaskara
Traceability      :877370: IoHwAb:Compiler warning due to same macro usage in
                    PWM & Dout
Change Description:Updated the Macro name
******************************************************************************/
/*****************************************************************************
Date              :29-April-2021
By                :akv
Traceability      :1307388: IoHwAb pwm : wrong check
Change Description: Wrong check against the resolution multiplier is removed.
					boundary check for pwm duty is added.
******************************************************************************/
/*****************************************************************************
Date              :30-April-2021
By                :akv
Traceability      :1259373: IoHwAb_Pwm periodic refresh issue.
Change Description: closing bracket are corrected to proper place
******************************************************************************/
/*****************************************************************************
Date              :25-July-2021
By                :akv
Traceability      :1400410: Nissan C53L: Compiler Warning in IoHwAb_Pwm.c file
Change Description: New line is aded at the end of the file.
******************************************************************************/
/*****************************************************************************
Date              :02-Aug-2022
By                :jkanikal
Traceability      :1710112:[vautosar]iohwab quality
Change Description:IoHwAb Audit Fix Coverity Misra warnings fix
******************************************************************************/
/*****************************************************************************
Date              :17-Aug-2022
By                :jkanikal
Traceability      :1736922: [vautosar]BSW general requirements for IOHW
Change Description:Added Misra warning comments as per bsw generalrequiremenr
******************************************************************************/
/*****************************************************************************
Date              :18-Aug-2023
By                :abandlap
Traceability      :vAutosar IoHwAb Streamline Update
Change Description:Added a timer support function for pwm configured channel.
******************************************************************************/
/*****************************************************************************
Date              :13-Jun-2024
By                :msavariy
Traceability      : https://visteon.atlassian.net/browse/NS30479-87888
Change Description: PMW HW which doesn't support wait for period to complete, the logic updated 
                    to use PWM edge notification to update new period.
******************************************************************************/
