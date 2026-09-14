/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2022. Visteon Corporation owns all rights to           *
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
 /******************************************************************************

File Name        :  WarnMsg_Core_TmrSupport.c                                                
Module Short Name:  VIP Warnings application                                                          
Author           :  vrk
VOBName          :  Warning Bookshelf
Description      :  VIP msg application and frame work.                                
Organization     :  Driver Information Software Section,                              
                    Visteon Corporation                                               
 ******************************************************************************/
/******************************************************************************
Compiler Name    :  
Target Processor :
 ******************************************************************************/
#define CWARNMSG_CORE_TMRSUPPORT_C
 /*****************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/
/*Add the System Includes here*/
/******************************************************************************
 *                                 Project Includes                           *
 ******************************************************************************/
#include "Std_Types.h"
#include "WarnMsg_Core_TmrSupport.h"
#include "Rte_WarnMsg_Core_TmrSupport.h"
/******************************************************************************
 *                                 Type Declarations                          *
*******************************************************************************/


/******************************************************************************
 *                                 File Scope Prototypes                      *
*******************************************************************************/

/******************************************************************************
 *                                 Constants                              	  *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the constant.                                                        *
 * purpose, unit and resolution                                               *
 ******************************************************************************/
 
 /*****************************************************************************
 *                                 Manifest Constants                         *
 *----------------------------------------------------------------------------*
 * Definition of Manifest constant shall be followed by a comment that        *
 * explains the purpose of the constant.                                      *
 ******************************************************************************/

/******************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define ZERO_VAL                       0U
#define MSG_SUPPORT_TMR_RUNNING        1U
#define MSG_SUPPORT_TMR_STOPPED        2U
#define SUPPORTED_PERIOD               63536U

/*****************************************************************************
*                                 Globally  accessed Variable Declarations   *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/

/******************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
 ******************************************************************************/ 
static uint32 l_WrnMsgCore_TmrSupport_Timeout_Array_u32[eMaxNumof16BitTimers];
/****************************************************************************
Function Name        : WarnMsg_Core_TmrSupport_Start_Timer
Description          : start timer interface
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void WarnMsg_Core_TmrSupport_Start_Timer(uint8 timer_id, uint32 timeout_count, uint16 event)
{
    if((timer_id < eMaxNumof16BitTimers) && (SUPPORTED_PERIOD >= timeout_count))
    {
        /*Whenver cyclic warnings are displayed, after the 1st warning displayed for 2s, timer is started again without being stopped using the below function 
        TmrExt_Timer.c takes care of clearing the expiry status bit before starting the timer*/
        l_WrnMsgCore_TmrSupport_Timeout_Array_u32[timer_id] = timeout_count;
        Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(timer_id);
    }
}
/****************************************************************************
Function Name        : WarnMsg_Core_TmrSupport_Stop_Timer
Description          : stop timer interface
Invocation           : invoked by message core
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void WarnMsg_Core_TmrSupport_Stop_Timer(uint8 timer_id)
{
    if(timer_id < eMaxNumof16BitTimers)
    {
        l_WrnMsgCore_TmrSupport_Timeout_Array_u32[timer_id] = ZERO_VAL;
        Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(timer_id);
    }
}
/****************************************************************************
Function Name        : WarnMsg_Core_TmrSupport_Check_Timer
Description          : Check timer interface
Invocation           : invoked by message core
Return Value         : TIMER_CLEAR
					   TIMER_EXPIRED
					   TIMER_RUNNING
Critical Section     : None
Parameters           : None
******************************************************************************/
uint16 WarnMsg_Core_TmrSupport_Check_Timer(uint8 timer_id)
{
	uint16 fl_return_u16;
	boolean fl_timer_elapsed_bool;
   
   /*Initialization*/
   fl_return_u16 = TIMER_CLEAR;

    if(timer_id < eMaxNumof16BitTimers)
    {
        Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(timer_id,l_WrnMsgCore_TmrSupport_Timeout_Array_u32[timer_id],&fl_timer_elapsed_bool);

        if(FALSE != fl_timer_elapsed_bool)
        {
            fl_return_u16 = TIMER_EXPIRED;
        }
        else
        {
            if(ZERO_VAL != l_WrnMsgCore_TmrSupport_Timeout_Array_u32[timer_id])
            {
                fl_return_u16 = TIMER_RUNNING;
            }
            else
            {
                fl_return_u16 = TIMER_CLEAR;
            }
        }
    }
    return(fl_return_u16);
}
/****************************************************************************
Function Name        : CWarnMsgCore_TmrSupport_Task
Description          : Task
Invocation           : Scheduler
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
FUNC(void, WarnMsg_Core_TmrSupport_CODE) WarnMsg_Core_TmrSupport_Task(void)
{
	
	/*Dummy Task*/
}

/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                             *
******************************************************************************/
/****************************************************************************
Date              : 19-06-2024
CDSID             : vrk
Traceability      : 
Change Description: Bookshelf component 
 ******************************************************************************/
/****************************************************************************
Date              : 02-09-2024
CDSID             : vrk
Traceability      : 
Change Description: Updated the conditon check for the timer threshold check 
 ******************************************************************************/
/****************************************************************************
Date              : 18-09-2024
CDSID             : vrk
Traceability      : TFDCX32348-41202
Change Description: Removed the 'IsStarted' check to support the Message core.
                    The array - l_WrnMsgCore_TmrSupport_StartedArray_u8 is no 
                    more needed as it was supporting 'IsStated' checks.
 ******************************************************************************/


