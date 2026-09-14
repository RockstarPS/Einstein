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
 * @file        FltM_Dcc_Cfg.c
 * @details     <b> DCC to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_DCC_CFG_C_
#define  FLTM_SOC_DCC_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#if(FLTM_DCC_ENABLE == STD_ON)
#include "FltM_Soc_Dcc_Cfg.h"

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



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const FltM_Dcc_ConfigType Dcc_Config[DCC_INSTANCE_CONFIGURED] =
{
	{
		/* dccInst */
		SDL_DCC_INST_DCC1,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_0,
		/* refclkFreq */
		25000,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCK1,
		/* monclkFreq */
		200000,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	},
	{
		/* dccInst */
		SDL_DCC_INST_DCC0,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_0,
		/* refclkFreq */
		25000,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCKSRC3,
		/* monclkFreq */
		200000,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	},
	{
		/* dccInst */
		SDL_DCC_INST_DCC0,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_2,
		/* refclkFreq */
		12500,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCKSRC4,
		/* monclkFreq */
		25000,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	},
	{
		/* dccInst */
		SDL_DCC_INST_DCC3,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_0,
		/* refclkFreq */
		25000,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCK1,
		/* monclkFreq */
		125000,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	},
	{
		/* dccInst */
		SDL_DCC_INST_DCC1,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_0,
		/* refclkFreq */
		25000,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCKSRC6,
		/* monclkFreq */
		12500,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	},
	{
		/* dccInst */
		SDL_DCC_INST_DCC2,
		/* refclk - REF CLK */
		SDL_DCC_CLK0_SRC_CLOCK0_0,
		/* refclkFreq */
		25000,
		/* monclk - MON CLK */
		SDL_DCC_CLK1_SRC_CLOCKSRC1,
		/* monclkFreq */
		400000,
		/* mode */
		SDL_DCC_MODE_CONTINUOUS,
		/* intNum */
		0x0,
		/* DriftVal */
		2u
	}
};	

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif /* #if(FLTM_DCC_ENABLE == STD_ON) */
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