/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2010. Visteon Corporation owns all rights to           *
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
/*****************************************************************************

File Name        :  WarnMsg_Core_Observer.h
Module Short Name:  MSG_AP
VOBName          :  sw_hmi_ss
Author           :  vrk
Description      :  VIP msg application and frame work.
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/

#ifndef WARNMSG_CORE_OBSERVER_H
#define WARNMSG_CORE_OBSERVER_H

#include "Std_Types.h"
#include "warn_msgDefinition.h"
#include "WarnMsg_Core_Observer_Cfg.h"

/*****************************************************************************
*                                 Global Constant Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the constant.                                                        *
* Purpose, unit and resolution                                               *
******************************************************************************/
/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Declaration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/

/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/
/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
void WarnMsg_Core_Observer_SendStoreWarnToUCL(void);
static void WarnMsg_Core_Observer_UpdateToUCL(eMessageIdentity p_cur_warn_id, uint8 Status , uint8 MsgStatus);
#if WARNMSG_CORE_OBSERVER_CFGD_INSTANCES > 1
void OnDre_UCL_MultiZone_WarnStatus(uint8 inst);
#else
void OnDre_UCL_SingleZone_WarnStatus(void);
#endif

#endif //WARNMSG_CORE_OBSERVER_H

/*End of File*/
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
Date              : 22-05-2025
CDSID             : vrk
Traceability      : TFDCX32348-86429
Change Description: Removed the funtion prototype - WarnMsg_Core_Observer_StoreWarnConfigChk
 ******************************************************************************/
/*End of Revision History*/


