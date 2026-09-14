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
#ifndef  FLTM_SOC_POK_H_
#define  FLTM_SOC_POK_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Pok_Cfg.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_POK_ENABLE == STD_ON)
/*============================================================================
**
** Function Name    :   FltM_POK_Init
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to during init
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
extern void FltM_POK_Init(void);

 /*============================================================================
**
** Function Name    :   FltM_POK_CallBackFunc
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to trigger OV/UV error
**
** Invocation       :   Application
**
** Inputs           :   instance -  Instance of POK
**                  :   pPokCfg - Configuration of POK
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern int32_t FltM_POK_CallBackFunc(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,uint32_t grpChannel,
                            uint32_t index,uint32_t intSrc);

/*============================================================================
**
** Function Name    :   FltM_POK_setConfig
**
** Visibility       :   Public
**
** Description      :   The function to be invoked to trigger OV/UV error
**
** Invocation       :   Application
**
** Inputs           :   instance -  Instance of POK
**                  :   pPokCfg - Configuration of POK
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
extern int32_t FltM_POK_setConfig(SDL_POK_Inst instance, SDL_POK_config *pPokCfg);

#endif /*#if(FLTM_POK_ENABLE == STD_ON)*/

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
Date              :20-May-2025
By                :KPALANIV
Traceability      :PE4TI29141-8297
Change Description:POK Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/