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
 * @file        FltM_Soc_Pok_Cfg.h
 * @details     <b> Pok to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

 #ifndef  FLTM_SOC_POK_CFG_H_
 #define  FLTM_SOC_POK_CFG_H_

 /*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "sdl_pok.h"
#include "sdl_soc_pok.h"
#include "sdl_pok_def.h"
#include "sdl_types.h"
#include "sdl_esm.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define FLTM_POK_ENABLE                                                STD_ON

#if (FLTM_POK_ENABLE == STD_ON)

#define FLTM_POK_TEST_ENABLE                                           STD_ON
#define FLTM_NUM_POK_CFG                                               9u
#define FLTM_POK_PP_ENABLE_PRG                                         2u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/***************** POK configurations **************************************************/

typedef struct
{
    SDL_POK_Inst instance;
    SDL_POK_config FltM_POK_cfg;
}FltM_POK_config;

extern const FltM_POK_config FltM_POK_init_cfg[FLTM_NUM_POK_CFG];

#endif /*#if (FLTM_POK_ENABLE == STD_ON)*/

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
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/

