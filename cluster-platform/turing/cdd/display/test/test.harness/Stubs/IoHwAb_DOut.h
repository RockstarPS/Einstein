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
* @file IoHwAb_DOut.h
* @brief Types for IoHwAb Digital output signals
* ****************************************************************************/
#ifndef IOHWAB_DOUT_H
#define IOHWAB_DOUT_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_DOut_Cfg.h"
 /*To check if Digital Output is enabled */
#if (IOHWAB_DOUT_ENABLE == STD_ON)
/*****************************************************************************
*  Public Forward Declarations                                          	 *
******************************************************************************/
extern void IoHwAb_DOut_Init(void);
extern void IoHwAb_DOut_DeInit(void);
extern void IoHwAb_DOut_MainFunction(void);
extern Std_ReturnType IoHwAb_DOut_SetOutputPin(IoHwAb_DOutSignalIdType OutputId, boolean OutputSignal, IoHwAb_ErrorType* ErrorStatus);
extern Std_ReturnType IoHwAb_DOut_SetOutputGroup(IoHwAb_DOutGroupIdType OutputGroupId, uint32 OutputGroup, IoHwAb_ErrorType* ErrorStatus);

#endif
#endif /* IOHWAB_DOUT_H*/


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
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/
