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
 * @file        Dss_IrqCfg.c
 * @details     <b>TI Dss driver Irq</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */


#ifndef DSS_IRQ_CFG_C
#define DSS_IRQ_CFG_C


#include "Dss_IrqCfg.h"
#include "drivers/dss/v0/common/dss_evtMgr.h"

/* Dss Irq for instance 0 */
void Dss_0_Isrfunc(void)
{
    Dss_evtMgrMasterIsr(0);
}

#if 0
/* Dss Irq for instance 1 */
void Dss_1_Isrfunc(void)
{
    Dss_evtMgrMasterIsr(1);
}
#endif

#endif

/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 5/Mar/2024
By                : nchellap
Traceability      : PE4TI29141-381
Change Description: Dss initial proveout
-----------------------------------------------------------------------------------------*/
