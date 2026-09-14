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
 * @file        FltM._Dcc.h
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_DCC_H_
#define  FLTM_SOC_DCC_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Dcc_Cfg.h"
#include "FltM_Soc_Types.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_DCC_ENABLE == STD_ON)
#define DCC_UINT32_MAX                                          (0xFFFFFFFFu)
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_Dcc_Init
**
** Visibility       :   static
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
extern Std_ReturnType FltM_Dcc_Init(void);

/*============================================================================
**
** Function Name    :   FltM_DCC_ReadBack
**
** Visibility       :   Private
**
** Description      :   Periodic Readback for DCC.
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
extern Std_ReturnType FltM_DCC_ReadBack(void);

/*============================================================================
**
** Function Name    :   FltM_Dcc_Disable
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to disable DCC Feature
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
extern int32_t FltM_Dcc_Disable(void);

/*============================================================================
**
** Function Name    :   FltM_Dcc_InjectFault
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to inject DCC Failure
**
** Invocation       :   Application
**
** Inputs           :   Index of Configuration structure
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern Std_ReturnType FltM_Dcc_InjectFault(uint8 InjectIndex);

/*============================================================================
**
** Function Name    :   FltM_OscClkLossDetection_Enable
**
** Visibility       :   static
**
** Description      :   The Init function is called to enable HFOSC0 clock loss
**                      detection feature.
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
extern void FltM_OscClkLossDetection_Enable(void);

/*============================================================================
**
** Function Name    :   FltM_Dcc_CallBackFunc
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to find the DCC error details
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
extern int32_t FltM_Dcc_CallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                          uint32_t grpChannel,  uint32_t index, uint32_t intSrc);

#endif /*#if(FLTM_DCC_ENABLE == STD_ON)*/

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
Date              :22-Apr-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-7898
Change Description:DCC Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :13-Aug-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-9628
Change Description:Clock Seedvalue calculation and update
-----------------------------------------------------------------------------*/
