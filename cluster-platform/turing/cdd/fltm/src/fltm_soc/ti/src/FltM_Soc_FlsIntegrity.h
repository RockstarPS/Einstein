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
 * @file        FltM_FlsIntegrity.h
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_FLSINTEGRITY_H_
#define  FLTM_FLSINTEGRITY_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_FlsIntegrity_Cfg.h"
#include "FltM_Soc_Cfg.h"
#include "Os.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_FLSINTEGRITY_ENABLE == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_FlashIntegrity_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   FltM_Init
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType FltM_FlashIntegrity_Init(void);

/*============================================================================
**
** Function Name    :   FltM_FlashIntegrity
**
** Visibility       :   Public
**
** Description      :   The function to be invoked for calculating checksum for 
**                      configured text regions
**
** Invocation       :   Runnable/Task
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern boolean FltM_FlashIntegrity(void);

/*============================================================================
**
** Function Name    :   FltM_FlsIntegrity_GetStatus
**
** Visibility       :   Public
**
** Description      :   The function to be invoked for checking the completion & status 
**                      of checksum calculation
**
** Invocation       :   Runnable/Task
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern void FltM_FlsIntegrity_GetStatus(eFltM_FlsIntegrityStatusType *Status);

#endif /*#if(FLTM_FLSINTEGRITY_ENABLE == STD_ON)*/

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
Date              :5-Aug-2025
By                :KPORKODI
Traceability      :PE4TI29141-9645
Change Description:Flash Integrity Implementation
-----------------------------------------------------------------------------*/
