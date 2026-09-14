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
 * @file        FltM_Service_E4.c
 * @details     <b> E4 Fault Manager service binding for the internal service
                    contract. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef FLTM_SERVICE_E4_C_
#define FLTM_SERVICE_E4_C_

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltM_Service.h"
#include "Rte_CFltM.h"
#include "Dlt.h"
#include "MemLib.h"
#include "RstM.h"
#include "Dem.h"

/*****************************************************************************
 *                         Limited Scope Prototypes                           *
 ******************************************************************************/
extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo,
                                         uint8 *logData, uint16 logDataLength);

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_ServiceLogFault
**
** Visibility       :   Global
**
** Description      :   Service seam for future adapter extraction of fault
**                      logging.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig, flFormatLogData, flTotalLogLength
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceLogFault(const FltM_FaultConfigType *flFaultConfig,
                                    const uint8 *flFormatLogData, uint16 flTotalLogLength)
{
  const FltM_LogConfigType *flLogConfig = NULL_PTR;
  Dlt_MessageLogInfoType flDltLogInfo;
  Dlt_SessionIDType flDltSessionId = 0U;
  Std_ReturnType flRetVal = E_NOT_OK;
  uint16 flMaxLogLength = FLTM_MAX_LOG_LENGTH + 3U;
  uint16 flSafeTotalLogLength = 0U;
  uint32 flCopyLength = 0U;
  uint8 flMutableLogData[FLTM_MAX_LOG_LENGTH + 3U];

  if ((flFaultConfig != NULL_PTR) &&
      (flFormatLogData != NULL_PTR))
  {
    flLogConfig = &FltM_LogConfig[flFaultConfig->LogConfigIdx];
    flDltLogInfo.argCount = FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].argCount;
    flDltLogInfo.options = FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].options;
    (void)MemLib_MemCpy(flDltLogInfo.appId,
                        FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].appId,
                        (uint32)sizeof(Dlt_ApplicationIDType));
    (void)MemLib_MemCpy(flDltLogInfo.contextId,
                        FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].contextId,
                        (uint32)sizeof(Dlt_ContextIDType));
    flDltLogInfo.logLevel = flLogConfig->FltMLogLevel;
    flDltSessionId = FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].SessionId;
    if (flTotalLogLength <= flMaxLogLength)
    {
      flSafeTotalLogLength = flTotalLogLength;
    }
    else
    {
      flSafeTotalLogLength = flMaxLogLength;
    }

    if (flSafeTotalLogLength > 0U)
    {
      flCopyLength = flSafeTotalLogLength;
      (void)MemLib_MemCpy(flMutableLogData, flFormatLogData, flCopyLength);
      (void)Dlt_SendLogMessage(flDltSessionId, &flDltLogInfo, flMutableLogData, flSafeTotalLogLength);
    }
    flRetVal = E_OK;
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceRequestReset
**
** Visibility       :   Global
**
** Description      :   Service seam for future adapter extraction of reset
**                      request handling.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig, flFormatLogData, flTotalLogLength
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceRequestReset(const FltM_FaultConfigType *flFaultConfig,
                                        uint8 *flFormatLogData, uint16 flTotalLogLength)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if ((flFaultConfig != NULL_PTR) &&
      (flFormatLogData != NULL_PTR))
  {
    flRetVal = RstM_RequestSwReset(flFaultConfig->FaultId, flFormatLogData, flTotalLogLength);
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceExecuteFirstSafeAction
**
** Visibility       :   Global
**
** Description      :   Service seam for future adapter extraction of first
**                      safe action handling.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceExecuteFirstSafeAction(const FltM_FaultConfigType *flFaultConfig)
{
  const FltM_ActionConfigType *flActionConfig = NULL_PTR;
  Std_ReturnType flRetVal = E_NOT_OK;

  if (flFaultConfig != NULL_PTR)
  {
    flActionConfig = &FltM_ActionConfig[flFaultConfig->ActionConfigIdx];
    if (flActionConfig->FltM_FirstSafeAction != NULL_PTR)
    {
      flRetVal = flActionConfig->FltM_FirstSafeAction(flFaultConfig->FaultId);
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceExecuteFinalSafeAction
**
** Visibility       :   Global
**
** Description      :   Service seam for future adapter extraction of final
**                      safe action handling.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceExecuteFinalSafeAction(const FltM_FaultConfigType *flFaultConfig)
{
  const FltM_ActionConfigType *flActionConfig = NULL_PTR;
  Std_ReturnType flRetVal = E_NOT_OK;

  if (flFaultConfig != NULL_PTR)
  {
    flActionConfig = &FltM_ActionConfig[flFaultConfig->ActionConfigIdx];
    if (flActionConfig->FltM_FinalSafeAction != NULL_PTR)
    {
      flRetVal = flActionConfig->FltM_FinalSafeAction(flFaultConfig->FaultId);
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceExecuteRecoveryAction
**
** Visibility       :   Global
**
** Description      :   Service seam for future adapter extraction of recovery
**                      action handling.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceExecuteRecoveryAction(const FltM_FaultConfigType *flFaultConfig)
{
  const FltM_ActionConfigType *flActionConfig = NULL_PTR;
  Std_ReturnType flRetVal = E_NOT_OK;

  if (flFaultConfig != NULL_PTR)
  {
    flActionConfig = &FltM_ActionConfig[flFaultConfig->ActionConfigIdx];
    if (flActionConfig->FltM_RecoveryAction != NULL_PTR)
    {
      flRetVal = flActionConfig->FltM_RecoveryAction(flFaultConfig->FaultId);
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceGetResetCount
**
** Visibility       :   Global
**
** Description      :   Service seam for reset-count retrieval.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId, Count
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceGetResetCount(FltM_FaultIdType FaultId, uint8 *Count)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if (Count != NULL_PTR)
  {
    flRetVal = RstM_GetResetCount(FaultId, Count);
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceGetEarlyResetCount
**
** Visibility       :   Global
**
** Description      :   Service seam for pre-init reset-count retrieval.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId, Count
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceGetEarlyResetCount(FltM_FaultIdType FaultId, uint8 *Count)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if (Count != NULL_PTR)
  {
    flRetVal = RstM_GetEarlyResetCount(FaultId, Count);
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceClearResetCount
**
** Visibility       :   Global
**
** Description      :   E4 binding keeps reset-history clear behavior
**                      unchanged in this phase.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId
**
** Outputs          :   E_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceClearResetCount(FltM_FaultIdType FaultId)
{
  (void)FaultId;

  return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceGetLastResetReason
**
** Visibility       :   Global
**
** Description      :   Service seam for last-reset reason retrieval.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceGetLastResetReason(FltM_FaultIdType *FaultId)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if (FaultId != NULL_PTR)
  {
    flRetVal = RstM_GetLastResetReason(FaultId);
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceReportDemFailed
**
** Visibility       :   Global
**
** Description      :   Service seam for DEM failed-status reporting.
**
** Invocation       :   Internal
**
** Inputs           :   EventId
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_ServiceReportDemFailed(Dem_EventIdType EventId)
{
  return FltM_Dem_SetEventStatus(EventId, DEM_EVENT_STATUS_FAILED);
}

/* Fatal policy is driven by explicit FltM severity config.
 * DLT log level remains dedicated to logging output.
 */
boolean FltM_ServiceIsFatalFault(const FltM_FaultConfigType *flFaultConfig)
{
  const FltM_SeverityConfigType *flSeverityConfig = NULL_PTR;
  boolean flRetVal = FALSE;

  if (flFaultConfig != NULL_PTR)
  {
    flSeverityConfig = &FltM_SeverityConfig[flFaultConfig->SeverityConfigIdx];
    if (flSeverityConfig->FltMSeverity == FLTM_SEVERITY_FATAL)
    {
      flRetVal = TRUE;
    }
  }

  return flRetVal;
}

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
Change Description:Rename current FltM service seam as explicit E4 service
                   binding.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :10-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add E4 no-op reset-count clear service to keep current
                   reset-history behavior unchanged.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Integrate E4 reset-storm handling, including reset-policy,
                    severity, debounce, and service-layer updates.
-----------------------------------------------------------------------------*/
