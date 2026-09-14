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
 * @file        FltM_Service.h
 * @details     <b> Internal service seam declarations for Fault Manager
                    external side effects. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef FLTM_SERVICE_H_
#define FLTM_SERVICE_H_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
Std_ReturnType FltM_ServiceLogFault(const FltM_FaultConfigType *flFaultConfig,
                                    const uint8 *flFormatLogData, uint16 flTotalLogLength);
Std_ReturnType FltM_ServiceRequestReset(const FltM_FaultConfigType *flFaultConfig,
                                        uint8 *flFormatLogData, uint16 flTotalLogLength);
Std_ReturnType FltM_ServiceExecuteFirstSafeAction(const FltM_FaultConfigType *flFaultConfig);
Std_ReturnType FltM_ServiceExecuteFinalSafeAction(const FltM_FaultConfigType *flFaultConfig);
Std_ReturnType FltM_ServiceExecuteRecoveryAction(const FltM_FaultConfigType *flFaultConfig);
Std_ReturnType FltM_ServiceGetResetCount(FltM_FaultIdType FaultId, uint8 *Count);
Std_ReturnType FltM_ServiceGetEarlyResetCount(FltM_FaultIdType FaultId, uint8 *Count);
Std_ReturnType FltM_ServiceClearResetCount(FltM_FaultIdType FaultId);
Std_ReturnType FltM_ServiceGetLastResetReason(FltM_FaultIdType *FaultId);
Std_ReturnType FltM_ServiceReportDemFailed(Dem_EventIdType EventId);
boolean FltM_ServiceIsFatalFault(const FltM_FaultConfigType *flFaultConfig);

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
Date              :09-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add internal FltM service interface for external service
                   binding.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :10-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add reset-count clear service API to the common FltM
                   service contract.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Integrate E4 reset-storm handling, including reset-policy,
                    severity, debounce, and service-layer updates.
-----------------------------------------------------------------------------*/
