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
 * @file        FltM_Types.h
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
#ifndef  FLTM_TYPES_H_
#define  FLTM_TYPES_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* Enumeration of error types that can be detected by the Fault Manager */
/* To be removed once RTE is generated */
typedef enum
{
    FLTM_PASSED,
	FLTM_FAILED,
}eFaultStatus;

typedef uint16 FltM_FaultIdType;
typedef uint16 eFltM_FaultIdType;
#define POWER_ON_RESET  1
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
/*============================================================================
**
** Function Name    :   FltM_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Init(void);

/*============================================================================
**
** Function Name    :   FltM_HandlePostReset
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_HandlePostReset(void);

/*============================================================================
**
** Function Name    :   FltM_MainFunction
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_MainFunction(void);

/*============================================================================
**
** Function Name    :   FltM_ReportFault
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :   
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
Std_ReturnType FltM_ReportFault(const FltM_FaultIdType faultId, eFaultStatus \
                                 FaultStatus, uint8 *LogData, uint16 LogLength);

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :03-Jun-2025
By                :RRAJAGO2
Traceability      :
Change Description:Initial Implementation
-----------------------------------------------------------------------------*/
