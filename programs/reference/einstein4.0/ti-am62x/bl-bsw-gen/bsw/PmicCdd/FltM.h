/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2025. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM.h
 * @details     <b> Fault Manager Component to handle all types of faults in 
                    the system which includes both application faults and soc
                    faults. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_H_
#define  FLTM_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#define FLTM_MAX_NUM_FAULTS         28U
#define FLTM_NUMBER_OF_DLT_LOGINFO  2U

#define DMNMGR_GIPHEALTH_ERROR      0xF940
#define PMIC_ABIST_FAIL             0xF941
#define FLTM_BUCK1_OVUV             (63813U)
#define FLTM_BUCK2_OVUV             (63814U)
#define FLTM_BUCK3_OVUV             (63815U)
#define FLTM_BUCK4_OVUV             (63816U)
#define FLTM_LDO1_OVUV              (63817U)
#define FLTM_LDO2_OVUV              (63818U)
#define FLTM_LDO3_OVUV              (63819U)
#define FLTM_VVCA_OVUV              (63820U)
#define FLTM_VMON1_OVUV             (63821U)
#define EXT_WDG_RESET 				(63803U)
#define EXT_WDG_COMM_ERROR 			(63804U)
#define FLTM_ACTIVE (2U)

typedef uint16 eFltM_FaultIdType;

#include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
#endif