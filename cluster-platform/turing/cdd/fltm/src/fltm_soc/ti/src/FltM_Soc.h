/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
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
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_H_
#define  FLTM_SOC_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Types.h"
#include "FltM_Soc_Dcc.h"
#include "FltM_Soc_Ecc.h"
#include "FltM_Soc_FlsIntegrity.h"
#include "FltM_Soc_Pok.h"
#include "FltM_Soc_Ppu.h"
#include "FltM_Soc_PeriodicReadBack.h"
#include "FltM_Soc_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

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
** Function Name    :   FltM_Soc_Init
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
Std_ReturnType FltM_Soc_Init(void);

/*============================================================================
**
** Function Name    :   FltM_Soc_MainFunction
**
** Visibility       :   Public
**
** Description      :   MainFunction Implementation .
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
Std_ReturnType FltM_Soc_MainFunction(void);

/*============================================================================
**
** Function Name    :   FltM_HiInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles high priority ESM interrupts from the system
**                      and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void FltM_HiInterruptHandler(uint8 arg);

/*============================================================================
**
** Function Name    :   FltM_LowInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles low priority ESM interrupts from the system
**                      and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void FltM_LowInterruptHandler(uint8 arg);

/*============================================================================
**
** Function Name    :   FltM_CfgInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles configuration related ESM interrupts from the
**                      system and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
extern void FltM_CfgInterruptHandler(uint8 arg);

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

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
Change Description:Initial commit
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :13-Aug-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-9628
Change Description:Clock Seedvalue calculation and update
-----------------------------------------------------------------------------*/
