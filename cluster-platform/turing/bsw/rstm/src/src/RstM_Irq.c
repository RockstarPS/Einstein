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
 * @file        RstM_Irq.c
 * @details     <b> TI PMIC driver for TPS65224 </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef  RSTM_IRQ_C_
#define  RSTM_IRQ_C_
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "RstM_Irq.h"


#define RSTM_SEC_CODE_START
#define RSTM_CORE_CONST_SEC_START
#define RSTM_CORE_DATA_SEC_START
#define RSTM_CORE_BSS_SEC_START

#include "MemMap.h"


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#if defined (SOC_AM62PX) || defined (SOC_AM62P)
ISR(MCU_ResetIsolationReq)
{
    RstM_ProcessResetIsolationReq();
}
#endif

#define RSTM_SEC_CODE_STOP
#define RSTM_CORE_CONST_SEC_END
#define RSTM_CORE_DATA_SEC_END
#define RSTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/*---------------------------------------------------------------------------
Date               : 27 Aug 2024
CDSID              : nchellap
Traceability       : PE4TI29141-4360
Change Description : Initial Framework version of RstM
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 11 Sep 2024
CDSID              : nchellap
Traceability       : PE4TI29141-3922
Change Description : RstM - Bookshelf Release & Delivery
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 16 June 2025
CDSID              : sdv
Traceability       : PE4TI29141-8732
Change Description : RstM design change and Initial Implementation of RstM
-----------------------------------------------------------------------------*/
/******************************* End of File *********************************/