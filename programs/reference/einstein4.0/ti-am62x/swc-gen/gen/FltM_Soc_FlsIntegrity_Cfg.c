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
 * @file        FltM_Cfg.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_FLSINTEGRITY_CFG_C_
#define  FLTM_SOC_FLSINTEGRITY_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_FlsIntegrity_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if (FLTM_FLSINTEGRITY_ENABLE == STD_ON)
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

extern uint32 __TCMA_TEXTSECTION_START;
extern uint32 __DDR_TEXTSECTION_START;
extern uint32 __TCMA_TEXTSECTION_END;
extern uint32 __DDR_TEXTSECTION_END;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const FltM_FlsIntegrityConfigType FltM_FlsIntegrityConfig[FLS_INTEGRITY_TOTAL_TEXT_REGIONS] =
{
  {
    (uint32)&__TCMA_TEXTSECTION_START,
    (uint32)&__TCMA_TEXTSECTION_END
  },
  {
    (uint32)&__DDR_TEXTSECTION_START,
    (uint32)&__DDR_TEXTSECTION_END
  }
};

#endif /*#if (FLTM_FLSINTEGRITY_ENABLE == STD_ON)*/

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
Date              :  
By                :  
Traceability      : 
Change Description: 
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :18-Aug-2025
By                :KPORKODI
Traceability      :
Change Description:Flash Integrity Implementation
-----------------------------------------------------------------------------*/