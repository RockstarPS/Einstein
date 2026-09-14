/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  RstM_Types.h                                         *
*  Module Short Name :  RstM                                                 *
*  Description       :  This file contains Reset manger types implementation *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Compiler Independent                                   *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef RSTM_TYPES_H
#define RSTM_TYPES_H

#include "Os.h"
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Rte_RstM_Type.h"
#include "FltM_Types.h"
#include "RstM_Cfg.h"

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
/* Det Api Id Definition */
#define RSTM_INIT                                                        (0x0u)
#define RSTM_GETLASTRESET                                                (0x1u)
#define RSTM_REQUESTSWRESET                                              (0x2u)
#define RSTM_GETRESETHISTORY                                             (0x3u)
#define RSTM_GETRESETCOUNT                                               (0x4u)
#define RSTM_STAGEOSARMDUMP                                              (0x5u)
 
/* Det Error Definition */
#define RSTM_NULL_POINTER_ERROR                                          (0x0u)
#define RSTM_LENGTH_MISMATCH_ERROR                                       (0x1u)
#define RSTM_INVALID_RESET_TYPE_ERROR                                    (0x2u)
#define RSTM_INVALID_FAULT_ID                                            (0x3u)


#define RSTM_LASTESTRESET_INDEX                                             0u
#define RSTM_FAULT_CATEGORY_VALID                                      (0xF0U)
#define NONE (0U)
#define PMIC_RESET (1U)
#define MCU_RESET (2U)

/*****************************************************************************
*                                 Type Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define RSTM_SEC_CODE_STOP
#define RSTM_CORE_CONST_SEC_END
#define RSTM_CORE_DATA_SEC_END
#define RSTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif /* RSTM_TYPES_H */
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
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
/*---------------------------------------------------------------------------
Date               : 17 June 2025
CDSID              : sdv
Traceability       : PE4TI29141-8732
Change Description : RstM design change and Initial Implementation of RstM
                     Logic Fix
-----------------------------------------------------------------------------*/
/******************************* End of File *********************************/
