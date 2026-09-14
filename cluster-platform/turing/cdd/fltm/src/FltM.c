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
 * @file        FltM.c
 * @details     <b> Fault Manager Component to handle all types of faults in
                    the system which includes both application faults and soc
                    faults. </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef FLTM_C_
#define FLTM_C_

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltM.h"
#include "FltM_Service.h"
#include "FltM_Types.h"
#include "FltM_Cfg.h"
#include "FltM_Soc.h"
#include "Rte_Type.h"
#include "Rte_CFltM.h"
#include "MemLib.h"
#include "CmpLib.h"


#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START
#include "MemMap.h"

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(FltM)

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
typedef struct
{
  uint16 FailTimerMs;
  uint16 PassTimerMs;
  FltM_InternalFltMStatusType FltMStatus;
  FltM_InternalFltMStatusType PreviousFltMStatus;
  uint8 PassDebounceCounter; /* Counter to track the number of times the fault has been detected */
  uint8 FailDebounceCounter; /* Counter to track the number of times the fault has been detected */
  uint8 ActionCounter;   /* Counter to track the number of times the Safety acation is taken  */
  boolean TimeDebounceActive;  /* TRUE once first report is seen for time-based faults */
} FltM_InternalType;

typedef struct
{
  uint16 FltM_ResetFaultId;
  uint8 FltM_ResetResonReceived;
}FltM_ResetStateType;

typedef struct
{
  uint16 LogLength;
  eFltM_FaultStatusType FaultStatus;
  boolean valid;
  uint8 LogData[FLTM_MAX_LOG_LENGTH];
} FltM_LogCacheEntryType;

/* Cache indexed by configuration index. Keep pre-init replay, time-debounce
 * payload, and duplicate-log history separate so their lifecycles do not
 * interfere with each other.
 */
static FltM_LogCacheEntryType gFltM_PreInitQueue[FLTM_MAX_NUM_FAULTS];
static FltM_LogCacheEntryType gFltM_TimeDebounceCache[FLTM_MAX_NUM_FAULTS];
static boolean gFltM_Initialized = FALSE;
#if defined(FLTM_SKIP_SAME_LOG)
static FltM_LogCacheEntryType gFltM_LastReportCache[FLTM_MAX_NUM_FAULTS];
static boolean gFltM_SameFaultReport = FALSE;
#endif
static boolean gFltM_HandlePreFaults = FALSE;

#define FLTM_FATAL_POLICY_NO_ACTION          (0U)
#define FLTM_FATAL_POLICY_REQUEST_RESET      (1U)
#define FLTM_FATAL_POLICY_FINAL_SAFE_ACTION  (2U)

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                                 Static Variables                           *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable:                                                       *
 * purpose           : Interface structure for SDL DPL functions              *
 * critical section : No                                                      *
 * unit             : N/A                                                    *
 * resolution       : N/A                                                    *
 ******************************************************************************/
static FltM_InternalType FltM_Internal[FLTM_MAX_NUM_FAULTS];
static FltM_ResetStateType FltM_ResetState;
static eFltM_FaultStatusType FltM_LastReportedStatus[FLTM_MAX_NUM_FAULTS];


/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/
static Std_ReturnType CmpInit(void);
static Std_ReturnType CmpDeInit(void);
static Std_ReturnType CmpActivation(void);
static Std_ReturnType CmpDeActivation(void);
static Std_ReturnType CmpActive(void);
static Std_ReturnType CmpDiag(void);
static Std_ReturnType CmpDiagReturn(void);

static Std_ReturnType FltM_GetConfigIndexById(uint16 FaultId, uint8 *FaultConfigIndexPtr);
static void FltM_EvaluateCounterDebounceFault(eFltM_FaultStatusType eFaultStatus, FltM_InternalType *FltM_InternalPtr,
                                    const FltM_FaultConfigType *FaultConfigPtr);
static void FltM_FormatLogData(FltM_FaultIdType FaultId, uint8 PackedStatusByte,
                              const uint8 *LogData, uint16 LogLength, uint8 *FormattedLogData, uint16 *TotalLogLength);
static void FltM_HandlePreInitFaults(void);
#if defined(FLTM_SKIP_SAME_LOG)
static void FltM_CheckAndUpdateLastReport(FltM_FaultIdType flConfigIndex, eFltM_FaultStatusType FaultStatus, \
            const uint8 *LogData, uint16 LogLength);
#endif
static void FltM_HandleEvaluatedFault(uint16 flConfigIndex,
                                      eFltM_FaultStatusType FaultStatus,
                                      const uint8 *LogData, uint16 LogLength);
static void FltM_UpdateLogCache(FltM_LogCacheEntryType *entry,
                                eFltM_FaultStatusType FaultStatus,
                                const uint8 *LogData, uint16 LogLength,
                                boolean isValid);
static void FltM_StorePreInitFault(uint16 flConfigIndex, eFltM_FaultStatusType FaultStatus, const uint8 *LogData, uint16 LogLength);
static Std_ReturnType FltM_HandlePreInitFatalFault(uint16 flConfigIndex, eFltM_FaultStatusType FaultStatus, const uint8 *LogData, uint16 LogLength);
static uint8 FltM_GetFatalPolicyAction(FltM_ResetPolicyModeType ResetPolicyMode,
                                       uint8 CurrentCount,
                                       uint8 FinalSafeActionThreshold);
static void FltM_LogFaultIfNeeded(const FltM_FaultConfigType *flFaultConfig,
                                  const uint8 *flFormatLogData,
                                  uint16 flTotalLogLength);
static Std_ReturnType FltM_ExecuteFatalPolicyAction(const FltM_FaultConfigType *flFaultConfig,
                                                    uint8 flFatalPolicyAction,
                                                    boolean flUseSameLogGate,
                                                    const uint8 *flFormatLogData,
                                                    uint16 flTotalLogLength);


/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   CmpInit
**
** Visibility       :   Static
**
** Description      :   Battery Module Component Initialize routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpInit(void)
{
  FltM_Init();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDeInit
**
** Visibility       :   Static
**
** Description      :   Battery Module Component De-Initialize routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDeInit(void)
{
  uint16 flIndex;

  /* Explicit component deinitialization starts a new lifecycle. Clear queued
   * reports here so stale pre-init reports cannot cross that boundary. */
  for (flIndex = 0U; flIndex < FLTM_MAX_NUM_FAULTS; flIndex++)
  {
    FltM_UpdateLogCache(&gFltM_PreInitQueue[flIndex], FLTM_INACTIVE,
                        NULL_PTR, 0U, FALSE);
  }

  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpActivation
**
** Visibility       :   Static
**
** Description      :   Battery Module Component Activation routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpActivation(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDeActivation
**
** Visibility       :   Static
**
** Description      :   Battery Module Component De-Activation routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDeActivation(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpActive
**
** Visibility       :   Static
**
** Description      :   Battery Module Component Active routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpActive(void)
{
  FltM_MainFunction();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDiag
**
** Visibility       :   Static
**
** Description      :   Battery Module Component Diagnostic routine
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDiag(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDiagReturn
**
** Visibility       :   Static
**
** Description      :   Transitional state to clean up after diagnostic state
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK: Succeed
**                      E_NOT_READY: In progress
**                      E_NOT_OK: Failed
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType CmpDiagReturn(void)
{
  return E_OK;
}

/*============================================================================
**
** Function Name    :   FltM_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void FltM_Init(void)
{
  uint8 flIndex;
  Std_ReturnType retval = E_NOT_OK;
  for (flIndex = 0; flIndex < FLTM_MAX_NUM_FAULTS; flIndex++)
  {
    FltM_Internal[flIndex].FltMStatus = FLTM_FAULT_STATUS_GOOD;
    FltM_Internal[flIndex].PreviousFltMStatus = FLTM_FAULT_STATUS_GOOD;
    FltM_Internal[flIndex].PassDebounceCounter = 0;
    FltM_Internal[flIndex].FailDebounceCounter = 0;
    FltM_Internal[flIndex].ActionCounter = 0;
    FltM_Internal[flIndex].FailTimerMs = 0;
    FltM_Internal[flIndex].PassTimerMs = 0;
    FltM_LastReportedStatus[flIndex] = FLTM_INACTIVE;
    FltM_Internal[flIndex].TimeDebounceActive = FALSE;
    /* The BSS-backed pre-init queue may already contain a report received
     * before FltM_Init(). Preserve it for one-time runtime-ready replay. */
    FltM_UpdateLogCache(&gFltM_TimeDebounceCache[flIndex], FLTM_INACTIVE,
                        NULL_PTR, 0U, FALSE);
#if defined(FLTM_SKIP_SAME_LOG)
    FltM_UpdateLogCache(&gFltM_LastReportCache[flIndex], FLTM_INACTIVE,
                        NULL_PTR, 0U, FALSE);
#endif
  }
  FltM_ResetState.FltM_ResetFaultId = 0U;
  FltM_ResetState.FltM_ResetResonReceived = FALSE;
  gFltM_Initialized = FALSE;
  gFltM_HandlePreFaults = FALSE;
#if defined(FLTM_SKIP_SAME_LOG)
  gFltM_SameFaultReport = FALSE;
#endif
  retval = FltM_Soc_Init();

  if(retval == E_NOT_OK)
  {
	  FltM_Det_ReportError(FLTM_INIT_API_ID, FLTM_SOC_INIT_FAILED);
  }
  else
  {
	  /* Do Nothing */
  }
}

/*============================================================================
**
** Function Name    :   FltM_HandlePostReset
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_HandlePostReset(void)
{
  uint8 fl_ConfigIndex = 0U;
  uint8 flResetCount = 0U;
  Std_ReturnType flRetVal = E_NOT_OK;
  const FltM_FaultConfigType *flFaultConfig = NULL_PTR;
  const FltM_DemConfigType *flDemConfig = NULL_PTR;
  FltM_InternalType *flFltM_Internal = NULL_PTR;

  // ToDO - of POR do we need log DLT in startup

  flRetVal = FltM_ServiceGetResetCount(FltM_ResetState.FltM_ResetFaultId, &flResetCount);
  if (flRetVal == E_OK)
  {
    flRetVal = FltM_GetConfigIndexById(FltM_ResetState.FltM_ResetFaultId, &fl_ConfigIndex);
    if ((flRetVal == E_OK) && (fl_ConfigIndex < FLTM_MAX_NUM_FAULTS))
    {
      /* Get the fault configuration based on the index */
      flFaultConfig = &FltM_FaultConfig[fl_ConfigIndex];
      flDemConfig = &FltM_DemConfig[flFaultConfig->DemConfigIdx];
      flFltM_Internal = &FltM_Internal[fl_ConfigIndex];
      flFltM_Internal->ActionCounter =  flResetCount; /* Set the action counter to the reset count */
      if (flDemConfig->LogDtc != FALSE)
      {
        /* Log DTC if configured */
        (void)FltM_ServiceReportDemFailed(flDemConfig->DemEventId);
      }
      else
      {
        /* Do not log DTC */
      }
    }
    else
    {
      FltM_Det_ReportError(FLTM_HANDLE_POST_RESET_API_ID, FLTM_FAULT_CONFIG_ERROR);
    }
  }
  else
  {
    FltM_Det_ReportError(FLTM_HANDLE_POST_RESET_API_ID, FLTM_RSTM_COUNT_ERROR);
  }
}

/*============================================================================
**
** Function Name    :   FltM_MainFunction
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_MainFunction(void)
{
  uint16 flIndex;
  const FltM_FaultConfigType *flCfg;
  FltM_InternalType *flInternal;
  eFltM_FaultStatusType flLastStatus;
  FltM_FaultIdType flFltM_FaultIdType;
  if (FltM_ResetState.FltM_ResetResonReceived == FALSE)
  {
    if (E_OK == FltM_ServiceGetLastResetReason(&flFltM_FaultIdType))
    {
      gFltM_Initialized = TRUE; /* Need NVM data for RESET count before processing faults */
      FltM_ResetState.FltM_ResetResonReceived = TRUE;
      FltM_ResetState.FltM_ResetFaultId = flFltM_FaultIdType;
      if ((FltM_ResetState.FltM_ResetFaultId != PMIC_SLEEP_RESET) && \
                      (FltM_ResetState.FltM_ResetFaultId != POWER_ON_RESET))
      {
        /* Handle the post reset logic */
        FltM_HandlePostReset();
      }
      /* Replay any faults that were reported before initialization.
       * This ensures that faults detected early (before FltM was fully
       * initialized) are properly processed and logged after initialization.
       */
      if (gFltM_HandlePreFaults == FALSE)
      {
        gFltM_HandlePreFaults = TRUE;
        FltM_HandlePreInitFaults();
      }
    }
  }

  /* ---------------------- Time-based debounce handling ---------------------
   */
  for (flIndex = 0U; flIndex < FLTM_MAX_NUM_FAULTS; flIndex++)
  {
    const FltM_DebounceConfigType *flDebounceConfig;
    flCfg = &FltM_FaultConfig[flIndex];
    flDebounceConfig = &FltM_DebounceConfig[flCfg->DebounceConfigIdx];
    flInternal = &FltM_Internal[flIndex];

    if ((flDebounceConfig->DebounceType == FLTM_DEBOUNCE_TYPE_TIME) &&
        (flInternal->TimeDebounceActive != FALSE))
    {
      const FltM_LogCacheEntryType *entry = &gFltM_TimeDebounceCache[flIndex];
      const uint8 *logDataPtr = NULL_PTR;
      uint16 logLen = 0U;
      boolean flWasAlreadyNg = FALSE;
      flLastStatus = FltM_LastReportedStatus[flIndex];

      /* Get stored log data (same as last ReportFault) */
      if ((boolean)entry->valid != FALSE)
      {
        logDataPtr = entry->LogData;
        logLen = entry->LogLength;
      }

      /* ============================= ACTIVE ? NG PATH
       * ============================== */
      if (flLastStatus == FLTM_ACTIVE)
      {
        //Wrap around check
        if(flInternal->FailTimerMs <= (FLTM_UINT16_MAX - FLTM_MAINFUNCTION_PERIOD_MS))
        {
          flInternal->FailTimerMs += FLTM_MAINFUNCTION_PERIOD_MS;
        }
        else
        {
          /* Do nothing */
        }
        
        flInternal->PassTimerMs = 0U;

        /* Trending ACTIVE before threshold */
        if (flInternal->FltMStatus != FLTM_FAULT_STATUS_NG)
        {
          flInternal->PreviousFltMStatus = flInternal->FltMStatus;
          flInternal->FltMStatus = FLTM_FAULT_STATUS_TRANSITION_TO_NG;
        }

        /* NG threshold reached */
        if (flInternal->FailTimerMs >= flDebounceConfig->DebounceFailTimeMs)
        {
          flWasAlreadyNg = ((flInternal->FltMStatus ==
                             FLTM_FAULT_STATUS_NG) ? TRUE : FALSE);
          flInternal->FailTimerMs = flDebounceConfig->DebounceFailTimeMs;

          flInternal->PreviousFltMStatus = flInternal->FltMStatus;
          flInternal->FltMStatus = FLTM_FAULT_STATUS_NG;

          if ((flWasAlreadyNg == FALSE) &&
              (flInternal->ActionCounter < 0xFFu))
          {
            /* Count one confirmed NG episode, not repeated ACTIVE reports. */
            flInternal->ActionCounter++;
          }

          /* Debounce cycle done */
          flInternal->TimeDebounceActive = FALSE;
#if defined(FLTM_SKIP_SAME_LOG)
          gFltM_SameFaultReport = FALSE;
#endif
          FltM_HandleEvaluatedFault(flIndex, FLTM_ACTIVE, logDataPtr, logLen);
        }
      }

      /* ============================= INACTIVE ? GOOD PATH
       * ============================ */
      else if (flLastStatus == FLTM_INACTIVE)
      {
        /* Only meaningful if previously FAILed */
        if (flInternal->FltMStatus == FLTM_FAULT_STATUS_NG)
        {
          //Wrap around check
          if(flInternal->PassTimerMs <= (FLTM_UINT16_MAX - FLTM_MAINFUNCTION_PERIOD_MS))
          {
            flInternal->PassTimerMs += FLTM_MAINFUNCTION_PERIOD_MS;
          }
          else
          {
            /* Do nothing */
          }

          flInternal->FailTimerMs = 0U;

          /* Trending towards recovery */
          if (flInternal->PassTimerMs < flDebounceConfig->DebouncePassTimeMs)
          {
            flInternal->PreviousFltMStatus = flInternal->FltMStatus;
            flInternal->FltMStatus = FLTM_FAULT_STATUS_TRANSITION_TO_GOOD;
          }

          /* PASS threshold reached */
          if (flInternal->PassTimerMs >= flDebounceConfig->DebouncePassTimeMs)
          {
            flInternal->PassTimerMs = flDebounceConfig->DebouncePassTimeMs;

            flInternal->PreviousFltMStatus = flInternal->FltMStatus;
            flInternal->FltMStatus = FLTM_FAULT_STATUS_GOOD;
            flInternal->ActionCounter = 0U;

            /* Debounce done */
            flInternal->TimeDebounceActive = FALSE;

            #if defined(FLTM_SKIP_SAME_LOG)
            FltM_CheckAndUpdateLastReport(flIndex, FLTM_INACTIVE, logDataPtr,
                                          logLen);
            #endif

            FltM_HandleEvaluatedFault(flIndex, FLTM_INACTIVE, logDataPtr, logLen);
          }
        }
        else
        {
          /* Already GOOD or never NG ? no PASS debounce */
          flInternal->PassTimerMs = 0U;
          flInternal->FailTimerMs = 0U;

          /* Abort the pending time-based episode when the fault returned to
           * INACTIVE before reaching NG. This prevents the row from staying
           * armed forever with stale debounce context.
           */
          flInternal->TimeDebounceActive = FALSE;
          FltM_UpdateLogCache(&gFltM_TimeDebounceCache[flIndex],
                              FLTM_INACTIVE, NULL_PTR, 0U, FALSE);

          flInternal->PreviousFltMStatus = flInternal->FltMStatus;
          /* Maintain steady GOOD */
          flInternal->FltMStatus = FLTM_FAULT_STATUS_GOOD;
        }
      }

      /* ============================= Unknown/No-Change PATH
       * =========================== */
      else
      {
        flInternal->PassTimerMs = 0U;
        flInternal->FailTimerMs = 0U;
      }
    }
  }

  (void)FltM_Soc_MainFunction();
}

/*============================================================================
**
** Function Name    :   FltM_ReportFault
**
** Visibility       :   Public
**
** Description      :   TBD
**
** Invocation       :   Application
**
** Inputs           :
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
Std_ReturnType FltM_ReportFault(FltM_FaultIdType FaultId,
                                eFltM_FaultStatusType FaultStatus,
                                uint8 *LogData, uint16 LogLength)
{
  uint16 flConfigIndex = 0U;
  Std_ReturnType flRetVal = E_NOT_OK;
  uint8 flReportedStatus = (FaultStatus & 0x0FU);
  uint8 flResetCount = 0U;
  const FltM_FaultConfigType *flFaultConfig = NULL_PTR;
  const FltM_DebounceConfigType *flDebounceConfig = NULL_PTR;
  FltM_InternalType *flFltM_Internal = NULL_PTR;

  /* Get fault configuration based on fault ID */
  flRetVal = FltM_GetConfigIndexById(FaultId, &flConfigIndex);
  if ((flRetVal == E_OK) && (flConfigIndex < FLTM_MAX_NUM_FAULTS))
  {
    if (gFltM_Initialized == TRUE)
    {
      flFaultConfig = &FltM_FaultConfig[flConfigIndex];
      flDebounceConfig = &FltM_DebounceConfig[flFaultConfig->DebounceConfigIdx];
      flFltM_Internal = &FltM_Internal[flConfigIndex];

      /* Always remember last raw status for debounce */
      FltM_LastReportedStatus[flConfigIndex] = FaultStatus;

      flRetVal = FltM_ServiceGetResetCount(FaultId, &flResetCount);
      if (flRetVal == E_OK)
      {
        if (flFltM_Internal->ActionCounter < flResetCount)
        {
          flFltM_Internal->ActionCounter = flResetCount;
        }
      }
      else
      {
        FltM_Det_ReportError(FLTM_REPORT_FAULT_API_ID, FLTM_RSTM_COUNT_ERROR);
      }
      switch (flDebounceConfig->DebounceType)
      {
        case FLTM_DEBOUNCE_TYPE_COUNTER:
          /* Counter-based debounce is fully handled in ReportFault */
          (void)FltM_EvaluateCounterDebounceFault(FaultStatus, flFltM_Internal,
                                                  flFaultConfig);
        #if defined(FLTM_SKIP_SAME_LOG)
          gFltM_SameFaultReport = FALSE; /* Reset same fault report flag */

          (void)FltM_CheckAndUpdateLastReport(flConfigIndex, FaultStatus,
                                              (const uint8 *)LogData,
                                              LogLength);
        #endif

          /* Execute logging and safe actions based on evaluated status */
          FltM_HandleEvaluatedFault(flConfigIndex, FaultStatus, LogData,
                                    LogLength);
          break;

        case FLTM_DEBOUNCE_TYPE_TIME:
          /* Preserve 0U as an immediate confirmation policy for time debounce.
           * Non-zero thresholds continue to use the MainFunction timing path.
           */
          if ((flReportedStatus == FLTM_ACTIVE) &&
              (flDebounceConfig->DebounceFailTimeMs == 0U))
          {
            boolean flWasAlreadyNg = ((flFltM_Internal->FltMStatus ==
                                       FLTM_FAULT_STATUS_NG) ? TRUE : FALSE);

            flFltM_Internal->TimeDebounceActive = FALSE;
            flFltM_Internal->FailTimerMs = 0U;
            flFltM_Internal->PassTimerMs = 0U;
            FltM_UpdateLogCache(&gFltM_TimeDebounceCache[flConfigIndex],
                                FLTM_INACTIVE, NULL_PTR, 0U, FALSE);

            flFltM_Internal->PreviousFltMStatus = flFltM_Internal->FltMStatus;
            flFltM_Internal->FltMStatus = FLTM_FAULT_STATUS_NG;

            if ((flWasAlreadyNg == FALSE) &&
                (flFltM_Internal->ActionCounter < 0xFFU))
            {
              flFltM_Internal->ActionCounter++;
            }

#if defined(FLTM_SKIP_SAME_LOG)
            gFltM_SameFaultReport = FALSE;
#endif
            FltM_HandleEvaluatedFault(flConfigIndex, FaultStatus, LogData,
                                      LogLength);
          }
          else if ((flReportedStatus == FLTM_INACTIVE) &&
                   (flDebounceConfig->DebouncePassTimeMs == 0U))
          {
            flFltM_Internal->TimeDebounceActive = FALSE;
            flFltM_Internal->FailTimerMs = 0U;
            flFltM_Internal->PassTimerMs = 0U;
            FltM_UpdateLogCache(&gFltM_TimeDebounceCache[flConfigIndex],
                                FLTM_INACTIVE, NULL_PTR, 0U, FALSE);

            flFltM_Internal->PreviousFltMStatus = flFltM_Internal->FltMStatus;
            flFltM_Internal->FltMStatus = FLTM_FAULT_STATUS_GOOD;

#if defined(FLTM_SKIP_SAME_LOG)
            gFltM_SameFaultReport = FALSE;
            FltM_CheckAndUpdateLastReport(flConfigIndex, FaultStatus, LogData,
                                          LogLength);
#endif
            FltM_HandleEvaluatedFault(flConfigIndex, FaultStatus, LogData,
                                      LogLength);
          }
          else
          {
            /* Arm time-based debounce and store latest log data.
             * No logging or safe action happens here; MainFunction will do it
             * when thresholds are reached.
             */
            flFltM_Internal->TimeDebounceActive = TRUE;
            FltM_UpdateLogCache(&gFltM_TimeDebounceCache[flConfigIndex],
                                FaultStatus, (const uint8 *)LogData,
                                LogLength, TRUE);
          }
          break;

        default:
          FltM_Det_ReportError(FLTM_REPORT_FAULT_API_ID, FLTM_FAULT_CONFIG_ERROR);
          flRetVal = E_NOT_OK;
          break;
      }
    }
    else /* If not initialized, store the fault in early queue */
    {
      flFaultConfig = &FltM_FaultConfig[flConfigIndex];
      FltM_LastReportedStatus[flConfigIndex] = FaultStatus;

      if ((flReportedStatus == FLTM_ACTIVE) &&
          (FltM_ServiceIsFatalFault(flFaultConfig) == TRUE))
      {
        flRetVal = FltM_HandlePreInitFatalFault(flConfigIndex, FaultStatus, LogData, LogLength);
      }
      else
      {
        FltM_StorePreInitFault(flConfigIndex, FaultStatus, LogData, LogLength);
        flRetVal = E_OK;
      }
    }
  }
  else
  {
    FltM_Det_ReportError(FLTM_REPORT_FAULT_API_ID, FLTM_FAULT_CONFIG_ERROR);
    flRetVal = E_NOT_OK; /* Fault configuration not found */
  }
  return flRetVal;
}

/*============================================================================
**
** Function Name    :   FltM_GetFaultStatus
**
** Visibility       :   Public
**
** Description      :   Returns the evaluated public fault status for the
**                      requested logical fault.
**
** Invocation       :   Application
**
** Inputs           :   FaultId      - Logical fault identifier
**                      FaultStatus  - Pointer to public compatibility status
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   Yes
**
**==========================================================================*/
Std_ReturnType FltM_GetFaultStatus(FltM_FaultIdType FaultId,
                                   FltM_PublicFaultStatusType *FaultStatus)
{
  uint8 flConfigIndex = 0U;
  Std_ReturnType flRetVal = E_NOT_OK;

  if (FaultStatus == NULL_PTR)
  {
    FltM_Det_ReportError(FLTM_GET_FAULT_STATUS_API_ID, FLTM_NULL_PTR_ERROR);
  }
  else
  {
    flRetVal = FltM_GetConfigIndexById(FaultId, &flConfigIndex);
    if ((flRetVal == E_OK) && (flConfigIndex < FLTM_MAX_NUM_FAULTS))
    {
      switch (FltM_Internal[flConfigIndex].FltMStatus)
      {
        case FLTM_FAULT_STATUS_GOOD:
          *FaultStatus = FLTM_PUBLIC_STATUS_INACTIVE;
          break;

        case FLTM_FAULT_STATUS_TRANSITION_TO_NG:
          *FaultStatus = FLTM_PUBLIC_STATUS_ACTIVE;
          break;

        case FLTM_FAULT_STATUS_NG:
        case FLTM_FAULT_STATUS_TRANSITION_TO_GOOD:
          /* Recovery debounce still represents a declared fault to pollers. */
          *FaultStatus = FLTM_PUBLIC_STATUS_FAULT_DECLARED;
          break;

        default:
          *FaultStatus = FLTM_PUBLIC_STATUS_INACTIVE;
          break;
      }
    }
    else
    {
      FltM_Det_ReportError(FLTM_GET_FAULT_STATUS_API_ID, FLTM_FAULT_CONFIG_ERROR);
      flRetVal = E_NOT_OK;
    }
  }

  return flRetVal;
}

/*============================================================================
**                          Static Functions
============================================================================*/
/*============================================================================
**
** Function Name    :   FltM_CheckAndUpdateLastReport
**
** Visibility       :   Static
**
** Description      :   Compares the current fault report with the previously
**                      stored report for the given fault index. If both the
**                      fault status and associated log data are identical,
**                      sets the gFltM_SameFaultReport flag to TRUE to avoid
**                      duplicate logging. Updates the stored entry with the
**                      latest fault information for future comparisons.
**
** Invocation       :   Internal
**
** Inputs           :   flConfigIndex - Index of the fault configuration
**                      FaultStatus   - Current fault status
**                      LogData       - Pointer to the fault-specific log data
**                      LogLength     - Length of the log data
**
** Outputs          :   None
**
** Critical Section :   Yes (operates on global duplicate-log cache and modifies
**                      gFltM_SameFaultReport)
**
**==========================================================================*/
#if defined(FLTM_SKIP_SAME_LOG)
static void FltM_CheckAndUpdateLastReport(FltM_FaultIdType flConfigIndex,
                                          eFltM_FaultStatusType FaultStatus,
                                          const uint8 *LogData,
                                          uint16 LogLength)
{
  gFltM_SameFaultReport = FALSE;
  if (flConfigIndex < FLTM_MAX_NUM_FAULTS)
  {
    FltM_LogCacheEntryType *entry = &gFltM_LastReportCache[flConfigIndex];
    uint16 safeLen = 0U;
    uint32 compareLen = 0U;

    if ((LogData != NULL_PTR) && (LogLength > 0U))
    {
      if (LogLength < FLTM_MAX_LOG_LENGTH)
      {
        safeLen = LogLength;
      }
      else
      {
        safeLen = FLTM_MAX_LOG_LENGTH;
      }
    }

    /* ----------------- EQUALITY CHECK ---------------- */
    if ((boolean)entry->valid == TRUE)
    {
      boolean sameFault = (boolean)(entry->FaultStatus == FaultStatus);
      boolean sameLength = (boolean)(entry->LogLength == safeLen);
      boolean sameData = TRUE;

      if (safeLen > 0U)
      {
        if (LogData != NULL_PTR)
        {
          compareLen = safeLen;
          sameData = MemLib_MemCmp(entry->LogData, LogData,
                                   compareLen);
        }
      }
      if ((sameFault == TRUE) && (sameLength == TRUE) && (sameData == TRUE))
      {
        gFltM_SameFaultReport = TRUE;
      }
    }
    FltM_UpdateLogCache(entry, FaultStatus, LogData, LogLength, TRUE);
  }
}
#endif

/*============================================================================
**
** Function Name    :   FltM_HandlePreInitFaults
**
** Visibility       :   Static
**
** Description      :   Replays any faults that were reported before FltM was
*                         initialized.
**                      Ensures that early detected faults are processed and
*                         logged after initialization.
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
static void FltM_HandlePreInitFaults(void)
{
  FltM_FaultIdType FaultId = 0U;
  uint8 faultIdIndex = 0U;
  FltM_LogCacheEntryType *entry = NULL_PTR;
  /* Replay any early faults that were reported before initialization. */
  for (faultIdIndex = 0U; faultIdIndex < FLTM_MAX_NUM_FAULTS;
       faultIdIndex++)
  {
    entry = &gFltM_PreInitQueue[faultIdIndex];
    if (entry->valid != FALSE)
    {
      /* Replay the latest pre-init report for this fault. */
      FaultId = FltM_FaultConfig[faultIdIndex].FaultId;
      (void)FltM_ReportFault(FaultId, entry->FaultStatus, entry->LogData,
                             entry->LogLength);
      FltM_UpdateLogCache(entry, FLTM_INACTIVE, NULL_PTR, 0U, FALSE);
    }
  }
}
/*============================================================================
**
** Function Name    :   FltM_GetConfigIndexById
**
** Visibility       :   Static
**
** Description      :   Get fault configuration by fault ID
**
** Invocation       :   Internal
**
** Inputs           :   faultId - Fault ID to search for
**
** Outputs          :   Pointer to fault configuration or NULL if not found
**
** Critical Section :   No
**
**==========================================================================*/
static Std_ReturnType FltM_GetConfigIndexById(uint16 FaultId, uint8 *FaultConfigIndexPtr)
{
  uint8 flIndex = 0;
  Std_ReturnType flReturnVal = E_NOT_OK;

  *FaultConfigIndexPtr = 0xFFU; /* Initialize to invalid index */
  for (flIndex = 0; flIndex < FLTM_MAX_NUM_FAULTS; flIndex++)
  {
    if (FltM_FaultConfig[flIndex].FaultId == FaultId)
    {
      *FaultConfigIndexPtr = flIndex;
      flReturnVal = E_OK;
      break;
    }
  }
  return flReturnVal;
}

/*============================================================================
**
** Function Name    :   FltM_EvaluateCounterDebounceFault
**
** Visibility       :   Static
**
** Description      :   Evaluate counter-based debounce transitions
**
** Invocation       :   Internal
**
** Inputs           :   eFaultStatus, FltM_InternalPtr, FaultConfigPtr
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_EvaluateCounterDebounceFault(eFltM_FaultStatusType eFaultStatus, \
                    FltM_InternalType *FltM_InternalPtr, const FltM_FaultConfigType *FaultConfigPtr)
{
    eFltM_FaultStatusType flFltMStatus = (eFltM_FaultStatusType)(eFaultStatus & 0x0FU);
    const FltM_DebounceConfigType *flDebounceConfig = &FltM_DebounceConfig[FaultConfigPtr->DebounceConfigIdx];
    uint8 flFailThreshold = (uint8)flDebounceConfig->FailCounterThreshold;
    uint8 flPassThreshold = (uint8)flDebounceConfig->PassCounterThreshold;
    boolean flWasAlreadyNg = FALSE;

    switch (flFltMStatus)
    {
    /* ============================================================
     * ACTIVE ? FAIL PATH
     * ============================================================ */
    case FLTM_ACTIVE:
    {
        /* reset PASS direction */
        FltM_InternalPtr->PassDebounceCounter = 0U;
        /* Count FAIL attempts */
        if (FltM_InternalPtr->FailDebounceCounter < flFailThreshold)
        {
            FltM_InternalPtr->FailDebounceCounter++;
        }
        /* Direction change ? immediate NG transition */
        if ((FltM_InternalPtr->FltMStatus != FLTM_FAULT_STATUS_NG) &&
            (FltM_InternalPtr->FailDebounceCounter < flFailThreshold))
        {
          FltM_InternalPtr->PreviousFltMStatus = FltM_InternalPtr->FltMStatus;
            FltM_InternalPtr->FltMStatus = FLTM_FAULT_STATUS_TRANSITION_TO_NG;
        }
        /* Full FAIL reached */
        if (FltM_InternalPtr->FailDebounceCounter >= flFailThreshold)
        {
            flWasAlreadyNg = ((FltM_InternalPtr->FltMStatus ==
                               FLTM_FAULT_STATUS_NG) ? TRUE : FALSE);
            FltM_InternalPtr->PreviousFltMStatus = FltM_InternalPtr->FltMStatus;
            FltM_InternalPtr->FltMStatus = FLTM_FAULT_STATUS_NG;

            if ((flWasAlreadyNg == FALSE) &&
                (FltM_InternalPtr->ActionCounter < 0xFFu))
            {
              /* One NG episode */
              FltM_InternalPtr->ActionCounter++;
            }

            /* Reset counter for next episode */
            FltM_InternalPtr->FailDebounceCounter = 0U;
        }
    }
    break;

    /* ============================================================
     * INACTIVE ? PASS PATH
     * ============================================================ */
    case FLTM_INACTIVE:
    {
        /* reset FAIL direction */
        FltM_InternalPtr->FailDebounceCounter = 0U;

        /* Count PASS attempts */
        if (FltM_InternalPtr->PassDebounceCounter < flPassThreshold)
        {
            FltM_InternalPtr->PassDebounceCounter++;
        }
        /* FAIL abort (TRANSITION_TO_NG ? INACTIVE) */
        if ((FltM_InternalPtr->FltMStatus == FLTM_FAULT_STATUS_TRANSITION_TO_NG) &&
            (FltM_InternalPtr->PassDebounceCounter < flPassThreshold))
        {
            FltM_InternalPtr->PreviousFltMStatus = FltM_InternalPtr->FltMStatus;
            /* Abort NG attempt, no PASS transition */
            FltM_InternalPtr->FltMStatus = FLTM_FAULT_STATUS_GOOD;
            FltM_InternalPtr->PassDebounceCounter = 0U;
        }
        /* trending to GOOD */
        else if ((FltM_InternalPtr->FltMStatus == FLTM_FAULT_STATUS_NG) &&
                 (FltM_InternalPtr->PassDebounceCounter < flPassThreshold))
        {
            FltM_InternalPtr->PreviousFltMStatus = FltM_InternalPtr->FltMStatus;
            FltM_InternalPtr->FltMStatus = FLTM_FAULT_STATUS_TRANSITION_TO_GOOD;
        }
        else
        {
            /* do nothing */
        }
        /* FULL PASS reached */
        if (FltM_InternalPtr->PassDebounceCounter >= flPassThreshold)
        {
            FltM_InternalPtr->PreviousFltMStatus = FltM_InternalPtr->FltMStatus;
            /* NG ? GOOD completed (debounced PASS) */
            FltM_InternalPtr->FltMStatus    = FLTM_FAULT_STATUS_GOOD;
            FltM_InternalPtr->ActionCounter = 0U;

            /* Reset counter */
            FltM_InternalPtr->PassDebounceCounter = 0U;
        }
        else 
        {
           /* do nothimg*/
        }
    }
    break;

    default:
        break;
    }
}

static uint8 FltM_GetFatalPolicyAction(FltM_ResetPolicyModeType ResetPolicyMode,
                                       uint8 CurrentCount,
                                       uint8 FinalSafeActionThreshold)
{
  uint8 flAction = FLTM_FATAL_POLICY_NO_ACTION;

  switch(ResetPolicyMode)
  {
    case FLTM_RESET_POLICY_NONE:
      flAction = FLTM_FATAL_POLICY_NO_ACTION;
      break;

    case FLTM_RESET_POLICY_RESET_ALWAYS:
      flAction = FLTM_FATAL_POLICY_REQUEST_RESET;
      break;

    case FLTM_RESET_POLICY_FINAL_ACTION_ONLY:
      flAction = FLTM_FATAL_POLICY_FINAL_SAFE_ACTION;
      break;

    case FLTM_RESET_POLICY_RESET_UNTIL_FINAL_ACTION:
      flAction = (CurrentCount >= FinalSafeActionThreshold) ?
                 FLTM_FATAL_POLICY_FINAL_SAFE_ACTION :
                 FLTM_FATAL_POLICY_REQUEST_RESET;
      break;

    default:
      /* Preserve legacy behavior for invalid configuration. */
      flAction = (CurrentCount >= FinalSafeActionThreshold) ?
                 FLTM_FATAL_POLICY_FINAL_SAFE_ACTION :
                 FLTM_FATAL_POLICY_REQUEST_RESET;
      break;
  }

  return flAction;
}

static Std_ReturnType FltM_ExecuteFatalPolicyAction(const FltM_FaultConfigType *flFaultConfig,
                                                    uint8 flFatalPolicyAction,
                                                    boolean flUseSameLogGate,
                                                    const uint8 *flFormatLogData,
                                                    uint16 flTotalLogLength)
{
  Std_ReturnType flRetVal = E_OK;

  switch (flFatalPolicyAction)
  {
    case FLTM_FATAL_POLICY_FINAL_SAFE_ACTION:
      if (flUseSameLogGate == TRUE)
      {
        FltM_LogFaultIfNeeded(flFaultConfig, flFormatLogData, flTotalLogLength);
      }
      else
      {
        (void)FltM_ServiceLogFault(flFaultConfig, flFormatLogData,
                                   flTotalLogLength);
      }
      flRetVal = FltM_ServiceExecuteFinalSafeAction(flFaultConfig);
      break;

    case FLTM_FATAL_POLICY_REQUEST_RESET:
      flRetVal = FltM_ServiceRequestReset(flFaultConfig, flFormatLogData,
                                          flTotalLogLength);
      break;

    case FLTM_FATAL_POLICY_NO_ACTION:
    default:
      break;
  }

  return flRetVal;
}

static void FltM_LogFaultIfNeeded(const FltM_FaultConfigType *flFaultConfig,
                                  const uint8 *flFormatLogData,
                                  uint16 flTotalLogLength)
{
#if defined(FLTM_SKIP_SAME_LOG)
  if (gFltM_SameFaultReport == FALSE)
#endif
  {
    (void)FltM_ServiceLogFault(flFaultConfig, flFormatLogData,
                               flTotalLogLength);
  }
}

/*============================================================================
**
** Function Name    :   FltM_HandleEvaluatedFault
**
** Visibility       :   Static
**
** Description      :   to Handle Evaluated Fault actions like logging and safe actions
**
** Invocation       :   Internal
**
** Inputs           :   
**
** Outputs          :   
**
** Critical Section :   No
**
**==========================================================================*/

static void FltM_HandleEvaluatedFault(uint16 flConfigIndex,
                                      eFltM_FaultStatusType FaultStatus,
                                      const uint8 *LogData, uint16 LogLength)
{
  uint8 flFormatLogData[FLTM_MAX_LOG_LENGTH + 3U];
  uint16 flTotalLogLength = 0U;
  uint8 localFaultStatus;
  boolean flIsNgEntry;
  boolean flIsRecoveryEntry;
  const FltM_FaultConfigType *flFaultConfig;
  const FltM_LogConfigType *flLogConfig;
  const FltM_ResetPolicyConfigType *flResetPolicyConfig;
  FltM_InternalType *flInternal;
  uint8 flFatalPolicyAction;

  flFaultConfig = &FltM_FaultConfig[flConfigIndex];
  flLogConfig = &FltM_LogConfig[flFaultConfig->LogConfigIdx];
  flResetPolicyConfig = &FltM_ResetPolicyConfig[flFaultConfig->ResetPolicyConfigIdx];
  flInternal = &FltM_Internal[flConfigIndex];
  flIsNgEntry = (((flInternal->FltMStatus == FLTM_FAULT_STATUS_NG) &&
                  (flInternal->PreviousFltMStatus != FLTM_FAULT_STATUS_NG)) ?
                 TRUE : FALSE);
  flIsRecoveryEntry = (((flInternal->FltMStatus == FLTM_FAULT_STATUS_GOOD) &&
                        ((flInternal->PreviousFltMStatus == FLTM_FAULT_STATUS_NG) ||
                         (flInternal->PreviousFltMStatus == FLTM_FAULT_STATUS_TRANSITION_TO_GOOD))) ?
                       TRUE : FALSE);

  /* Prepare formatted log */
  localFaultStatus = (uint8)((FaultStatus & 0x0FU) << 4U);
  localFaultStatus = (uint8)(localFaultStatus | (flLogConfig->FltMLogLevel & 0x0FU));

  (void)FltM_FormatLogData(flFaultConfig->FaultId, localFaultStatus, LogData,
                           LogLength, flFormatLogData, &flTotalLogLength);

  switch (flInternal->FltMStatus)
  {
  case FLTM_FAULT_STATUS_GOOD:
  {
    if (flIsRecoveryEntry == FALSE)
    {
      break;
    }
    FltM_LogFaultIfNeeded(flFaultConfig, flFormatLogData, flTotalLogLength);
    /* Reset ActionCounter (new NG episodes start fresh) */
    flInternal->ActionCounter = 0U;
    (void)FltM_ServiceClearResetCount(flFaultConfig->FaultId);
    (void)FltM_ServiceExecuteRecoveryAction(flFaultConfig);
  }
  break;

  case FLTM_FAULT_STATUS_NG:
  {
    /* Repeated ACTIVE while NG is the same fault episode. */
    if (flIsNgEntry == FALSE)
    {
      break;
    }
    /* NG side effects are transition-based, not report-based. */
    if (FltM_ServiceIsFatalFault(flFaultConfig) == FALSE)
    {
      FltM_LogFaultIfNeeded(flFaultConfig, flFormatLogData, flTotalLogLength);
      (void)FltM_ServiceExecuteFirstSafeAction(flFaultConfig);
      break;
    }
    flFatalPolicyAction = FltM_GetFatalPolicyAction(flResetPolicyConfig->ResetPolicyMode,
                                                    flInternal->ActionCounter,
                                                    flResetPolicyConfig->FinalSafeActionThreshold);
    (void)FltM_ExecuteFatalPolicyAction(flFaultConfig,
                                        flFatalPolicyAction,
                                        TRUE,
                                        flFormatLogData,
                                        flTotalLogLength);
  }
  break;
    /* ============================================================
    * 3. TRANSITION STATES ? NO LOGGING
    * ============================================================ */
  case FLTM_FAULT_STATUS_TRANSITION_TO_NG:
  case FLTM_FAULT_STATUS_TRANSITION_TO_GOOD:
      /* Intentionally no log here: avoids NVM wear */
      break;

  default:
    /* Nothing */
    break;
  }
}

/*============================================================================
**
** Function Name    :   FltM_FormatLogData
**
** Visibility       :   Static
**
** Description      :   Formats the DLT payload for a fault event, including
**                      fault ID, packed status byte, and additional log data.
**
** Invocation       :   Internal
**
** Inputs           :   FaultId         - Fault identifier
**                      PackedStatusByte - Packed runtime-log status byte
**                      LogData         - Pointer to additional log data
**                      LogLength       - Length of additional log data
**
** Outputs          :   FormattedLogData - Pointer to buffer for formatted data
**                      TotalLogLength   - Pointer to total length of formatted data
**
** Critical Section :   No
**
**==========================================================================*/
static void FltM_FormatLogData(FltM_FaultIdType FaultId, uint8 PackedStatusByte,
                               const uint8 *LogData, uint16 LogLength, uint8 *FormattedLogData, uint16 *TotalLogLength)
{
  uint16 flCopyLength = 0U;
  uint8 flIndex = 0U;
  FormattedLogData[0] = (uint8)((FaultId >> 8U) & 0xFFU); /* Copy MSB */
  FormattedLogData[1] = (uint8)(FaultId & 0xFFU);          /* Copy FaultId to log data */
  FormattedLogData[2] = PackedStatusByte;
  /* Copy user provided additional log data (bytes 3-7). */
  if ((LogData != NULL_PTR) && (LogLength > 0U))
  {
    flCopyLength = (LogLength > FLTM_MAX_LOG_LENGTH) ? FLTM_MAX_LOG_LENGTH : LogLength; /* Limit to 5 bytes */
    for (flIndex = 0U; flIndex < flCopyLength; flIndex++)
    {
      FormattedLogData[flIndex + 3U] = LogData[flIndex];
    }
    *TotalLogLength = flCopyLength + 3U; /* +1 for byte 0 */
  }
  else
  {
    /* No additional data, only byte 0 and fault id */
    *TotalLogLength = 3u;
  }
}

/*============================================================================
**
** Function Name    :   FltM_UpdateLogCache
**
** Visibility       :   Static
**
** Description      :   Stores fault status and optional payload in an
**                      internal cache entry. If LogData is NULL, payload
**                      length is normalized to zero and the buffer is cleared.
**
** Invocation       :   Internal
**
** Inputs           :   entry, FaultStatus, LogData, LogLength, isValid
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
static void FltM_UpdateLogCache(FltM_LogCacheEntryType *entry,
                                eFltM_FaultStatusType FaultStatus,
                                const uint8 *LogData, uint16 LogLength,
                                boolean isValid)
{
  uint16 safeLen = 0U;
  uint32 copyLen = 0U;

  if (entry != NULL_PTR)
  {
    if ((LogData != NULL_PTR) && (LogLength > 0U))
    {
      if (LogLength < FLTM_MAX_LOG_LENGTH)
      {
        safeLen = LogLength;
      }
      else
      {
        safeLen = FLTM_MAX_LOG_LENGTH;
      }
    }

    entry->FaultStatus = FaultStatus;
    entry->LogLength = safeLen;
    entry->valid = isValid;

    (void)MemLib_MemSet(entry->LogData, 0x00U, FLTM_MAX_LOG_LENGTH);

    if (safeLen > 0U)
    {
      copyLen = safeLen;
      (void)MemLib_MemCpy(entry->LogData, LogData, copyLen);
    }
  }
}

/*============================================================================
**
** Function Name    :   FltM_StorePreInitFault
**
** Visibility       :   Static
**
** Description      :   Stores pre-init non-fatal fault information for replay
**                      after FltM initialization.
**
** Invocation       :   Internal
**
** Inputs           :   flConfigIndex, FaultStatus, LogData, LogLength
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
static void FltM_StorePreInitFault(uint16 flConfigIndex, eFltM_FaultStatusType FaultStatus, const uint8 *LogData, uint16 LogLength)
{
  FltM_UpdateLogCache(&gFltM_PreInitQueue[flConfigIndex], FaultStatus,
                      LogData, LogLength, TRUE);
}

/*============================================================================
**
** Function Name    :   FltM_HandlePreInitFatalFault
**
** Visibility       :   Static
**
** Description      :   Handles fatal ACTIVE faults before FltM initialization
**                      is complete. This path bypasses the early queue,
**                      reads current reset count through the configured
**                      FltM service binding, and decides whether to request
**                      reset or trigger final safe action.
**
** Invocation       :   Internal
**
** Inputs           :   flConfigIndex, FaultStatus, LogData, LogLength
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   Yes
**==========================================================================*/
static Std_ReturnType FltM_HandlePreInitFatalFault(uint16 flConfigIndex, eFltM_FaultStatusType FaultStatus, const uint8 *LogData, uint16 LogLength)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint8 flStoredResetCount = 0U;
  uint8 flEffectiveCount = 0U;
  uint8 flFormatLogData[FLTM_MAX_LOG_LENGTH + 3U];
  uint16 flTotalLogLength = 0U;
  uint8 localFaultStatus = 0U;
  uint8 flFatalPolicyAction;
  const FltM_FaultConfigType *flFaultConfig = NULL_PTR;
  const FltM_LogConfigType *flLogConfig = NULL_PTR;
  const FltM_ResetPolicyConfigType *flResetPolicyConfig = NULL_PTR;

  flFaultConfig = &FltM_FaultConfig[flConfigIndex];
  flLogConfig = &FltM_LogConfig[flFaultConfig->LogConfigIdx];
  flResetPolicyConfig = &FltM_ResetPolicyConfig[flFaultConfig->ResetPolicyConfigIdx];

  localFaultStatus = (uint8)((FaultStatus & 0x0FU) << 4U);
  localFaultStatus = (uint8)(localFaultStatus | (flLogConfig->FltMLogLevel & 0x0FU));

  (void)FltM_FormatLogData(flFaultConfig->FaultId,
                           localFaultStatus,
                           LogData,
                           LogLength,
                           flFormatLogData,
                           &flTotalLogLength);

  flRetVal = FltM_ServiceGetEarlyResetCount(flFaultConfig->FaultId, &flStoredResetCount);
  if (flRetVal != E_OK)
  {
    flStoredResetCount = 0U;
  }

  flEffectiveCount = flStoredResetCount;
  if (flEffectiveCount < 0xFFU)
  {
    /* Include the current fatal episode before threshold comparison. */
    flEffectiveCount++;
  }

  flFatalPolicyAction = FltM_GetFatalPolicyAction(flResetPolicyConfig->ResetPolicyMode,
                                                  flEffectiveCount,
                                                  flResetPolicyConfig->FinalSafeActionThreshold);

  flRetVal = FltM_ExecuteFatalPolicyAction(flFaultConfig,
                                           flFatalPolicyAction,
                                           FALSE,
                                           flFormatLogData,
                                           flTotalLogLength);
  if ((flFatalPolicyAction == FLTM_FATAL_POLICY_FINAL_SAFE_ACTION) &&
      (flRetVal != E_OK))
  {
    FltM_Det_ReportError(FLTM_REPORT_FAULT_API_ID, FLTM_FAULT_CONFIG_ERROR);
  }

  return flRetVal;
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
Date              :03-Jun-2025
By                :RRAJAGO2
Traceability      :
Change Description:Initial Framework Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :16-Jun-2025
By                :MSAVARIY
Traceability      :
Change Description:FltM, FltM_Common requirement implementation
                        https://visteon.atlassian.net/browse/PE4TI29141-8791
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :18-Nov-2025
By                :MSAVARIY
Traceability      :
Change Description:Time Debounce implementation
                       https://visteon.atlassian.net/browse/PE4TI29141-10705
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :26-Jan-2026
By                :SDC
Traceability      :
Change Description:Safe Recovery Implementation for Fault Manager
                       https://visteon.atlassian.net/browse/PE4TI29141-11472
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :09-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Add public fault-status API and internal-to-public status
                   mapping. Align time-debounce recovery handling so the
                   evaluated GOOD transition is visible to recovery handling.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :10-May-2026
By                :MSAVARIY
Traceability      :
Change Description:Clear service-backed reset count on confirmed recovery.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Integrate E4 reset-storm handling, including reset-policy,
                    severity, debounce, and service-layer updates.
-----------------------------------------------------------------------------*/
