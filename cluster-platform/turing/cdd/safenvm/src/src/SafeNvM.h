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
 * @file        SafeNvM.h
 * @details     
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */

#ifndef SAFENVM_H_
#define SAFENVM_H_


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "SafeNvM_Cfg.h"
#include "Rte_Type.h"

#define SAFENVM_SEC_CODE_START
#define SAFENVM_CORE_CONST_SEC_START
#define SAFENVM_CORE_DATA_SEC_START
#define SAFENVM_CORE_BSS_SEC_START

#include "MemMap.h"

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
extern void SafeNvM_MainFunction(void);
extern void SafeNvM_Init(void);
extern Std_ReturnType SafeNvM_SetWriteBlockReq(uint8 SafeBlockIndex);
extern void SafeNvM_TriggerDataCompare(void);

extern void SafeNvM_NvM_WriteCallback_Original(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult);
extern void SafeNvM_NvM_WriteCallback_Copy1(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult);
extern void SafeNvM_NvM_WriteCallback_Copy2(uint8 SafeBlockIndex, uint8 ServiceId, NvM_RequestResultType JobResult);

//NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult
#define SAFENVM_SEC_CODE_END
#define SAFENVM_CORE_CONST_SEC_END
#define SAFENVM_CORE_DATA_SEC_END
#define SAFENVM_CORE_BSS_SEC_END

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
Date              :  12-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8071
Change Description: Initial Triple Buffer Platform solution Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  27-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8584
Change Description: Design update and review fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  28-May-2025
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-8584
Change Description: Design update and review fix
-----------------------------------------------------------------------------*/


