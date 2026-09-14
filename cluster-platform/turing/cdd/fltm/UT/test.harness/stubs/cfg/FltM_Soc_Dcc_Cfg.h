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
 * @file        FltM_Dcc_Cfg.h
 * @details     <b> DCC to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */

 #ifndef  FLTM_SOC_DCC_CFG_H_
 #define  FLTM_SOC_DCC_CFG_H_

 /*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "sdl_dcc.h"
#include "sdl_dpl.h"
#include "sdl_esm.h"
#include "sdl_types.h"
#include "cslr_main_ctrl_mmr.h"
#include "lldr_mcu_ctrl_mmr.h"

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
#define FLTM_DCC_ENABLE                                          STD_ON

#if(FLTM_DCC_ENABLE == STD_ON)

#define FLTM_OCOCLKDET_ENABLE                                    STD_ON
#define DCC_FAULT_INJECT_TEST                                    STD_ON
#define DCC_INSTANCE_CONFIGURED                                  7u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct
{
    /* DCC Instance Type */
    SDL_DCC_Inst dccInst;
	/* COUNT0 clock source */
	SDL_DCC_ClkSrc0 refclk;
	/* COUNT0 clock frequency */
	uint32_t refclkFreq;
	/* COUNT1 clock source */
	SDL_DCC_ClkSrc1 monclk;
	/* COUNT1 clock frequency */
	uint32_t monclkFreq;
	/* Mode of operation - Continuous or One Shot */
	SDL_DCC_Mode mode;	
	/* Interrupt Num used in case of single-shot mode */
	uint32_t intNum; 
	/* Percentage deviation of drift allowed */
	uint32_t DriftVal;
	
}FltM_Dcc_ConfigType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
extern const FltM_Dcc_ConfigType Dcc_Config[DCC_INSTANCE_CONFIGURED];

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
Date              :  22-Apr-2025
By                :  rrajago2
Traceability      :  PE4TI29141-7915
Change Description:  Initil configuration of DCC
-----------------------------------------------------------------------------*/
