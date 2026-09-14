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

File Name        :  WarnMessage_Core_TmrSupport.h
Module Short Name:  MSG_AP
VOBName          :  sw_hmi_ss
Author           :  vrk
Description      :  VIP msg application and frame work.
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/

#ifndef WARNMESSAGE_CORE_TMRSUPPORT_H
#define WARNMESSAGE_CORE_TMRSUPPORT_H

#include "Std_Types.h"


/* Message core macros */
#define   TIMER_CLEAR       0x00u
#define   TIMER_EXPIRED     0x02u
#define   TIMER_RUNNING     0x80u

void WarnMsg_Core_TmrSupport_Start_Timer(uint8 timer_id, uint32 timeout_count, uint16 event);
void WarnMsg_Core_TmrSupport_Stop_Timer(uint8 timer_id);
uint16 WarnMsg_Core_TmrSupport_Check_Timer(uint8 timer_id);

#endif

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
/*End of Revision History*/


