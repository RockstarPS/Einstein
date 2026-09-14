
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

/*!********************************************************************************************************************
* @ingroup GptOutput
* @file IoHwAb_Gpt.c
* @brief Provide interfaces for setting the period & duty values.
* ********************************************************************************************************************/

#include "IoHwAb_Gpt.h"
#include "IoHwAb_Filter.h"
#include "Rte_IoHwAb.h"

#if(IOHWAB_GPT_ENABLE == STD_ON)


/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>


#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>


#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>

/**
* This method is the Gpt_EnableNotification function for IoHwAb Gpt
* @param     channel
* @return    void
*/
void IoHwAb_Gpt_EnableNotification(Gpt_ChannelType channel)
{
    Gpt_EnableNotification(channel);
}


/**
* This method is the Gpt_DisableNotification function for IoHwAb Gpt
* @param     channel
* @return    void
*/
void IoHwAb_Gpt_DisableNotification(Gpt_ChannelType channel)
{
    Gpt_DisableNotification(channel);
}


/**
* This method is the Gpt_StartTimer function for IoHwAb Gpt
* @param     Gpt_ChannelType
* @param     value
* @return    void
*/
void IoHwAb_Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value)
{

    Gpt_StartTimer(channel, value);
}

/**
* This method is the Gpt_StopTimer function for IoHwAb Gpt
* @param     channel
* @return    void
*/
void IoHwAb_Gpt_StopTimer(Gpt_ChannelType channel)
{
    Gpt_StopTimer(channel);

}



#define IoHwAb_STOP_SEC_CODE
#include <IoHwAb_MemMap.h>

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
