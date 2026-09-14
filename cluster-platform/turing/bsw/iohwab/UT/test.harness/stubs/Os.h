/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
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
 * @file        Os.h
 * @details     <b> This file externs the generic APIs of the OS </b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_H
#define OS_H

#include "Std_Types.h"
#include "OsMain.h"
#include "OsScheduleTable.h"
#include "Rte_Type.h"


/*! OS service: osDisableInterruptSource() (Gen6 backward compatibility) */
# define osDisableInterruptSource Os_DisableInterruptSource
/*! OS service: osEnableInterruptSource() (Gen6 backward compatibility) */
# define osEnableInterruptSource  Os_EnableInterruptSource

FUNC(StatusType, OS_CODE) Os_DisableInterruptSource
(
  ISRType ISRID
);

FUNC(ISRType, OS_CODE) OSError_Os_DisableInterruptSource_ISRID(void);

FUNC(StatusType, OS_CODE) Os_EnableInterruptSource
(
  ISRType ISRID,
  boolean ClearPending
);

FUNC(ISRType, OS_CODE) OSError_Os_EnableInterruptSource_ISRID(void);

#endif
