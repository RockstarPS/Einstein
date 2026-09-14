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
#ifndef SYSTST_H
#define SYSTST_H
/*!***************************************************************************
 * @ingroup
 * @file SysTst.h
 * @brief Header file for SysTst component
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "SysTst_Cfg.h"
/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/

/******************************************************************************
 *  Private Variable Definitions                                               *
 *******************************************************************************/

/******************************************************************************
 *  Private Function Declaration                                                *
 *******************************************************************************/

/******************************************************************************
 *  Public Function Definitions                                                *
 *******************************************************************************/

extern void SysTst_Init(void);

extern void SysTst_MainFunction(void);

#if (STARTUPTEST_ENABLE == STD_ON)
extern  void SysTst_StartupTest(void);
#endif

extern void SysTst_DeInit(void);

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
 Date              :16-Jul-2020
 By                :bbaskara
 Traceability      :RTC
 Change Description:Initial Version for SysTst implementation
 ******************************************************************************/
/*****************************************************************************
 Date              :05-May-2022
 By                :nchellap
 Traceability      :RTC
 Change Description:Coverity and Misra warning Analyse and Fix
******************************************************************************/

 
