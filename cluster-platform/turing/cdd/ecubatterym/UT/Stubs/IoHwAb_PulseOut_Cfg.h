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
* @file IoHwAb_PulseOut_Cfg.h
* @brief Configuration header file for Pulse out module
* ****************************************************************************/
#ifndef IOHWAB_PULSEOUT_CFG_H
#define IOHWAB_PULSEOUT_CFG_H
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Rte_Type.h"
#include "Dio.h"
#include "Gpt.h"
/*****************************************************************************
*  Public Macros Definitions                                                 *                                                                                      
******************************************************************************/
/**
* @brief Macro to enable the IoHwAb Pulse output Module
*/
#define IOHWAB_PULSEOUT_ENABLE							STD_OFF
/*****************************************************************************
*  Private Macros Definitions                                                *                                                                                       
******************************************************************************/
#if (IOHWAB_PULSEOUT_ENABLE == STD_ON)
  
#endif
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


