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

File Name        :  WarnMsg_Core_Support.c                                                
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
 #define WARNMSG_CORE_SUPPORT_C
 /*****************************************************************************
 *                                 System Includes                            *
 ******************************************************************************/
/*Add the System Includes here*/
/******************************************************************************
 *                                 Project Includes                           *
 ******************************************************************************/
/*RTE Includes*/
#include "Rte_CWarnMsg_Core_Observer.h"
#include "Rte_CWarnMsg_Core_Observer_Type.h"
/*Feature Includes*/
#include "WarnMsg_Core_Observer.h"
#include "WarnMsg_Core_Observer_Warning_Get_status.h"
#include "WarnMsg_Core_Observer_Cfg.h"
#include "warn_msgDefinition.cfg"
/*Global includes*/
#include "string.h"
#include "MemLib.h"
/******************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/******************************************************************************
 *                                 File Scope Prototypes                      *
 ******************************************************************************/

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


/*****************************************************************************
Function Name    : WarnMsg_Core_Observer_Warning_Get_status
Description      : Used to get the msg status from Ctrl_Warning
Invocation       : MSG core
Parameters       : UINT8 *Data
                          - Poniter to varibale, Holds msg status
                    UINT8 Qualifier
                          - msg identifier
Return Value     : SIF_STATUS
Critical Section : None
*****************************************************************************/
#if MSG_NUM_INSTANCES > 1 
SIF_STATUS WarnMsg_Core_Observer_Warning_Get_status(uint16 *Data, WarningId Qualifier, uint8 inst)
#else 
SIF_STATUS WarnMsg_Core_Observer_Warning_Get_status(uint16 *Data, WarningId Qualifier)
#endif
{
    /*Declaration*/

	ExtWarningData fl_warning_info_S;
    uint8 fl_msg_status_U8;
	SIF_STATUS fl_RetVal_enum;

    /*Initialization*/
	fl_RetVal_enum = sif_OK;
    MemLib_MemSet(&fl_warning_info_S, 0, sizeof(ExtWarningData));
	
	/*Invocation of Ctrl_Warning for Warning Status*/
    #ifndef WARNMSG_CORE_OBSERVER_GETWARNSTS
	#error The Get Warning Status function is not mapped in the WarnMsg_Core_Observer_Cfg.
	#else 
	WARNMSG_CORE_OBSERVER_GETWARNSTS (Qualifier, &fl_warning_info_S);
	#endif
		
	/*Check for Retrigger/Forced Request*/
	if((UI_WARNING_EVENT_RETRIGGER == fl_warning_info_S.ExtWarningCurrentEvent) ||
       (UI_WARNING_EVENT_FORCED == fl_warning_info_S.ExtWarningCurrentEvent))
    {
		fl_msg_status_U8 = MSG_CONDITION_OFF;
        if(UI_WARNING_EVENT_RETRIGGER == fl_warning_info_S.ExtWarningCurrentEvent)
        {
             fl_msg_status_U8 = MSG_CONDITION_RETRIGGER;       
        }
        if(UI_WARNING_EVENT_FORCED == fl_warning_info_S.ExtWarningCurrentEvent)
        {
             fl_msg_status_U8 = MSG_CONDITION_FORCED;       
        }
    }
    else
    {
        if(UI_WARNING_STATUS_ON == fl_warning_info_S.ExtWarningCurrentStatus)
        {
            fl_msg_status_U8 = MSG_CONDITION_ACTIVE;
        }
        else
        {
           fl_msg_status_U8 = MSG_CONDITION_OFF; 
        }
    }

	*Data = fl_msg_status_U8;
	
	return (fl_RetVal_enum);
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
Date              : 19-11-2024
CDSID             : vrk
Traceability      : DICMBD-395
Change Description: Updated the the datatype to support Actvive warning status
                    WarningDataS is now ExtWarningData
 ******************************************************************************/
/****************************************************************************
Date              : 16-12-2024
CDSID             : vrk
Traceability      : TFDCX32348-61095
Change Description: Updated to support Multi-instance
 ******************************************************************************/ 
/*End of Revision History*/  


