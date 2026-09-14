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
 * @file        FltM_Service_Tv2.c
 * @details     <b> TV2 Fault Manager service binding for the internal
                    service contract. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef FLTM_SERVICE_TV2_C_
#define FLTM_SERVICE_TV2_C_

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltM_Service.h"
#include "Dlt.h"
#include "MemLib.h"
#include "Mcu.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START
#include "MemMap.h"

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/
extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo,
                                         uint8 *logData, uint16 logDataLength);

static void FltM_DltLogFault(const FltM_FaultConfigType *flFaultConfig, const uint8 *flFormatLogData,
                             uint16 flTotalLogLength);
static Std_ReturnType FltM_ServiceGetFaultConfigIndex(FltM_FaultIdType FaultId, uint16 *ConfigIndex);
static void FltM_ServiceIncrementResetCount(uint16 ConfigIndex);

/*****************************************************************************
 *                                File scope data                            *
 ******************************************************************************/
/* Temporary non-retained storage. TV2 reset-loop prevention requires a
 * retained/no-init backend for production.
 */
static uint8 FltM_ServiceResetCount[FLTM_MAX_NUM_FAULTS];

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_DltLogFault
**
** Visibility       :   Static
**
** Description      :   Logs fault information using the DLT logging interface.
**
** Invocation       :   Internal
**
** Inputs           :   flFaultConfig     - Pointer to fault configuration
**                      flFormatLogData   - Pointer to formatted log data
**                      flTotalLogLength  - Length of formatted log data
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_DltLogFault(const FltM_FaultConfigType *flFaultConfig, const uint8 *flFormatLogData,
                             uint16 flTotalLogLength)
{
  const FltM_LogConfigType *flLogConfig = &FltM_LogConfig[flFaultConfig->LogConfigIdx];
  Dlt_MessageLogInfoType flDltLogInfo;
  Dlt_SessionIDType flDltSessionId = 0U;
  uint16 flMaxLogLength = FLTM_MAX_LOG_LENGTH + 3U;
  uint16 flSafeTotalLogLength = 0U;
  uint32 flCopyLength = 0U;
  uint8 flMutableLogData[FLTM_MAX_LOG_LENGTH + 3U];

  flDltLogInfo.argCount = FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].argCount;
  flDltLogInfo.options = FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].options;

  (void)MemLib_MemCpy(flDltLogInfo.appId, FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].appId,
                      (uint32)sizeof(Dlt_ApplicationIDType));
  (void)MemLib_MemCpy(flDltLogInfo.contextId, FltM_Dlt_MessageLogInfo[flLogConfig->DltLogInfoIndex].contextId,
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
  else
  {
    /* Invalid bounded log length, nothing to send. */
  }
}

/*============================================================================
**
** Function Name    :   FltM_ServiceLogFault
**
** Visibility       :   Global
**
** Description      :   TV2 service binding for fault logging.
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
  Std_ReturnType flRetVal = E_NOT_OK;

  if ((flFaultConfig != NULL_PTR) &&
      (flFormatLogData != NULL_PTR))
  {
    FltM_DltLogFault(flFaultConfig, flFormatLogData, flTotalLogLength);
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
** Description      :   TV2 service binding for reset request handling.
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
  uint16 flConfigIndex = 0U;

  if ((flFaultConfig != NULL_PTR) &&
      (flFormatLogData != NULL_PTR))
  {
    flRetVal = FltM_ServiceGetFaultConfigIndex(flFaultConfig->FaultId, &flConfigIndex);
    if (flRetVal == E_OK)
    {
      FltM_ServiceIncrementResetCount(flConfigIndex);
      (void)flFormatLogData;
      (void)flTotalLogLength;
      Mcu_PerformReset();
      flRetVal = E_OK;
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceExecuteFirstSafeAction
**
** Visibility       :   Global
**
** Description      :   TV2 service binding for first safe action handling.
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
** Description      :   TV2 service binding for final safe action handling.
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
** Description      :   TV2 service binding for recovery action handling.
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
** Description      :   TV2 binding reset-count retrieval.
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
  uint16 flConfigIndex = 0U;

  if (Count != NULL_PTR)
  {
    flRetVal = FltM_ServiceGetFaultConfigIndex(FaultId, &flConfigIndex);
    if (flRetVal == E_OK)
    {
      *Count = FltM_ServiceResetCount[flConfigIndex];
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceGetEarlyResetCount
**
** Visibility       :   Global
**
** Description      :   TV2 binding early reset-count retrieval.
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
  return FltM_ServiceGetResetCount(FaultId, Count);
}

/*============================================================================
**
** Function Name    :   FltM_ServiceClearResetCount
**
** Visibility       :   Global
**
** Description      :   TV2 binding reset-count clear on confirmed recovery.
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
Std_ReturnType FltM_ServiceClearResetCount(FltM_FaultIdType FaultId)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint16 flConfigIndex = 0U;

  flRetVal = FltM_ServiceGetFaultConfigIndex(FaultId, &flConfigIndex);
  if (flRetVal == E_OK)
  {
    FltM_ServiceResetCount[flConfigIndex] = 0U;
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceGetLastResetReason
**
** Visibility       :   Global
**
** Description      :   TV2 binding startup reset-reason behavior.
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
#ifdef POWER_ON_RESET
    *FaultId = POWER_ON_RESET;
#else
    *FaultId = 0U;
#endif
    flRetVal = E_OK;
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceReportDemFailed
**
** Visibility       :   Global
**
** Description      :   TV2 binding for DEM failed-status reporting.
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

/*============================================================================
**
** Function Name    :   FltM_ServiceGetFaultConfigIndex
**
** Visibility       :   Static
**
** Description      :   Maps FaultId to configuration index for TV2
**                      per-fault reset counters.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId, ConfigIndex
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_ServiceGetFaultConfigIndex(FltM_FaultIdType FaultId, uint16 *ConfigIndex)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint16 flIndex = 0U;

  if (ConfigIndex != NULL_PTR)
  {
    for (flIndex = 0U; flIndex < FLTM_MAX_NUM_FAULTS; flIndex++)
    {
      if (FltM_FaultConfig[flIndex].FaultId == FaultId)
      {
        *ConfigIndex = flIndex;
        flRetVal = E_OK;
        break;
      }
    }
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_ServiceIncrementResetCount
**
** Visibility       :   Static
**
** Description      :   Saturating increment for TV2 per-fault reset count.
**
** Invocation       :   Internal
**
** Inputs           :   ConfigIndex
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_ServiceIncrementResetCount(uint16 ConfigIndex)
{
  if (FltM_ServiceResetCount[ConfigIndex] < 0xFFU)
  {
    FltM_ServiceResetCount[ConfigIndex]++;
  }
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
Date              :10-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add initial TV2 FltM service binding.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :10-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add TV2 per-fault reset-counter backend and confirmed
                   recovery clear handling.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Integrate E4 reset-storm handling, including reset-policy,
                    severity, debounce, and service-layer updates.
-----------------------------------------------------------------------------*/
