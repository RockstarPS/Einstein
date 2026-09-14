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
 * @file        PmicCdd_Irq.c
 * @details     <b> TI PMIC driver for TPS65224 </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  FLTM_SOC_IRQ_C_
#define  FLTM_SOC_IRQ_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "FltM_Soc_Irq.h"

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

void FltM_WkupEsmCfgInterruptfunc(void)
{
    FltM_CfgInterruptHandler((uint8)SDL_ESM_INST_WKUP_ESM0);
}

void FltM_WkupEsmHiInterruptfunc(void)
{
    FltM_HiInterruptHandler((uint8)SDL_ESM_INST_WKUP_ESM0);
}

void FltM_WkupEsmLowInterruptfunc(void)
{
    FltM_LowInterruptHandler((uint8)SDL_ESM_INST_WKUP_ESM0);
}

void FltM_FwlExceptionInterruptfunc(void)
{
    #if(FLTM_PPU_ENABLE == STD_ON)
	FltM_FwlExceptionHandler();
    #endif
}

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
Date              :  24-Sep-2024
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-4380
Change Description: PmicCdd ADC Interrupt Mechanism Handling Implementation
-----------------------------------------------------------------------------*/
