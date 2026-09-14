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
* @file IoHwAb_Cbk.h
* @brief Configuration header file for digital output
* ****************************************************************************/
#ifndef IOHWAB_CBK_H
#define IOHWAB_CBK_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/


/*****************************************************************************
*  Public Forward Declarations                                                *                                                                                       *
******************************************************************************/

/**
* @brief 	GPT FRT Timer callback notification.
*/
extern void IoHwAb_PulseOut_Cbk_Notification(void);
extern void IoHwAb_AdcDelay_Notify(void);
extern void IoHwAb_MAI_DIMMING_OUT_STATUS_Nofification(void);
extern void ICU_MDI_IS_MONITORING_Notify(void);

#endif /* IOHWAB_DOUT_CFG_H */

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
Date              :19-Nov-2018
By                :pragesh
Traceability      :RTC# 1238746
Change Description:Initial Version for IoHwAb_PulseOut safe implementation
******************************************************************************/

