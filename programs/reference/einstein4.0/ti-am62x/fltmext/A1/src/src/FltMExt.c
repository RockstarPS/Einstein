/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2025. Visteon Corporation owns all rights to           *
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
 *  File Name         :  FltMExt.c                                            *
 *  Module Short Name :  FltMExt                                               *
 *  Description       :  This file contains implementations of the Fault      *
 *                       Manager Extension Implementation                     *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  CLANG                                                  *
 * Target Hardware  :  Program Dependent                                      *
 *                                                                            *
 ******************************************************************************/
#ifndef FLTMEXT_C
#define FLTMEXT_C
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "FltMExt.h"
#include "Rte_CFltMExt.h"
#include "RstM.h"
#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
#include "FltM_Cfg.h"
#include "DltExt.h"
#endif
#if(DLTEXT_UART_PRINT == STD_ON)
#include "SciDrv.h"
#include <stdio.h>
#endif

/******************************************************************************
 * .............................Global Variables                              *
 ******************************************************************************/

static boolean Supply_Voltage_Fault_Flag = FALSE;
static boolean Backlight_Fault_Flag = FALSE;

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
typedef enum
{
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_START_DELAY = 0U,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_READ_RETAINED_HISTORY,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_PRE_INJECTION,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_INJECTION,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_INJECT_FAULT,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_FINAL_RESULT,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_FINAL,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_PASS,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_ABORT,
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED
} FltMExt_SameFaultResetLoopHwTestStateType;

typedef enum
{
  FLTMEXT_HW_TEST_ABORT_UNEXPECTED_STATE = 0U,
  FLTMEXT_HW_TEST_ABORT_API_FAILURE,
  FLTMEXT_HW_TEST_ABORT_REPORTFAULT_FAILURE
} FltMExt_SameFaultResetLoopHwTestAbortType;

static FltMExt_SameFaultResetLoopHwTestStateType FltMExt_SameFaultHwTestState =
  FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_START_DELAY;
static FltMExt_SameFaultResetLoopHwTestAbortType FltMExt_SameFaultHwTestAbortReason =
  FLTMEXT_HW_TEST_ABORT_UNEXPECTED_STATE;
static uint32 FltMExt_SameFaultHwTestDelayTicks = 0U;
static uint8 FltMExt_SameFaultHwTestRetryCount = 0U;
static uint8 FltMExt_SameFaultHwTestRetainedCount = 0U;
static boolean FltMExt_SameFaultHwTestInjectionIssued = FALSE;
static boolean FltMExt_SameFaultHwTestExpectFinalAction = FALSE;
static boolean FltMExt_SameFaultHwTestFinalActionSeen = FALSE;
#endif
/******************************************************************************
 *                              Macro Definition                              *
 ******************************************************************************/

#define SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK 		                0x409u
#define SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK 		                0x408u

#ifndef FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY
#define FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY                         STD_ON
#endif

#if ((FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY != STD_OFF) && \
     (FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY != STD_ON))
#error "FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY must be STD_OFF or STD_ON"
#endif

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
#if (DLTEXT_UART_PRINT != STD_ON)
#error "FLTM same-Fault reset-loop HW test requires existing asynchronous DltExt UART print support"
#endif
#define FLTMEXT_SAME_FAULT_HW_TEST_MAINFUNCTION_PERIOD_MS                10U
#define FLTMEXT_SAME_FAULT_HW_TEST_START_DELAY_MS                        15000U
#define FLTMEXT_SAME_FAULT_HW_TEST_START_DELAY_TICKS                     \
  (FLTMEXT_SAME_FAULT_HW_TEST_START_DELAY_MS / FLTMEXT_SAME_FAULT_HW_TEST_MAINFUNCTION_PERIOD_MS)
#define FLTMEXT_SAME_FAULT_HW_TEST_UART_MAX_RETRIES                      50U
#endif

/*****************************************************************************
 *                            Static  Declaration                             *
 ******************************************************************************/
static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const ProtectionErrType *ProtectionErr);
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const osErrParamType *pErrParam);
static eFltM_FaultIdType FltMExt_MapService(OsServiceIdType sid);
static eFltM_FaultIdType FltMExt_MapReason(StatusType reason);
#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
static void FltMExt_SameFaultResetLoopHwTest_MainFunction(void);
#endif

/*****************************************************************************
 *                            Function Declaration                          *
 ******************************************************************************/

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_Init
 *  Service ID       : 0x01
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task
 *  Description      : Initializes the FltM Extension module state and
 *                     any SOC/board specific monitors required by FltMExt.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : System basic init completed; clocks/peripherals ready.
 *  Postconditions   : Module is ready; internal flags reset to defaults.
 *  Notes            : Call once during ECU startup before using other APIs.
 * --------------------------------------------------------------- */

void FltMExt_Init(void)
{

}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_DeInit
 *  Service ID       : 0x02
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task
 *  Description      : De-initializes the FltM Extension module, releases
 *                     resources and resets internal state.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : FltMExt_Init has been called.
 *  Postconditions   : Module is stopped; no further processing performed.
 *  Notes            : Typically used during controlled shutdown.
 * --------------------------------------------------------------- */
void FltMExt_DeInit(void)
{

}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MainFunction
 *  Service ID       : 0x03
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task (periodic)
 *  Description      : Periodic processing for FltMExt. Polls platform
 *                     health (e.g., VBATT) and reports faults to FltM.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : FltMExt_Init has been called.
 *  Postconditions   : Faults may be reported to FltM based on sampling.
 *  Notes            : Invoke with a fixed cycle time (e.g., 10�100 ms).
 * --------------------------------------------------------------- */
void FltMExt_MainFunction(void)
{
#if (FLTMEXT_VBATT_MONITOR == STD_ON)
  static boolean VoltageFaultActive = FALSE;
  static uint8 UV_Status = 0U;
  static uint8 OV_Status = 0U;
  boolean CurrentFaultActive = FALSE;
  uint8 logdata[5] = {0xAAU, 0xAAU, 0xAAU, 0xAAU, 0xAAU};
    // Implementation of VBATT_MONITOR
    Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(0U, &OV_Status);
    Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(1U, &UV_Status);
    // Safe Action
    //If channel status is 1, trigger the fault
  CurrentFaultActive = (boolean)(((0U != UV_Status) || (0U != OV_Status)) ? TRUE : FALSE);
 
  if ((CurrentFaultActive == TRUE) && (VoltageFaultActive == FALSE))
  {
    VoltageFaultActive = TRUE;
    logdata[0] = 0x00U;
    (void)FltM_ReportFault(VOLTAGE_ERROR, FLTM_ACTIVE, logdata, 5U);
  }
  else if ((CurrentFaultActive == FALSE) && (VoltageFaultActive == TRUE))
  {
    VoltageFaultActive = FALSE;
    logdata[0] = 0x00U;
    (void)FltM_ReportFault(VOLTAGE_ERROR, FLTM_INACTIVE, logdata, 5U);
  }
  else
  {
    /* No state change - do nothing */
  }
#endif

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
  FltMExt_SameFaultResetLoopHwTest_MainFunction();
#endif
}

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
static void FltMExt_SameFaultResetLoopHwTest_StartAbort(
  FltMExt_SameFaultResetLoopHwTestAbortType AbortReason)
{
  FltMExt_SameFaultHwTestAbortReason = AbortReason;
  FltMExt_SameFaultHwTestRetryCount = 0U;
  FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_ABORT;
}

static boolean FltMExt_SameFaultResetLoopHwTest_LogWithRetry(const char *Format)
{
  boolean flDone = FALSE;

  if (E_OK == DltExt_Uart_Printf(Format))
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else if (FltMExt_SameFaultHwTestRetryCount >= FLTMEXT_SAME_FAULT_HW_TEST_UART_MAX_RETRIES)
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else
  {
    FltMExt_SameFaultHwTestRetryCount++;
  }

  return flDone;
}

static boolean FltMExt_SameFaultResetLoopHwTest_LogPreInjection(void)
{
  boolean flDone = FALSE;

  if (E_OK == DltExt_Uart_Printf("SAMEFAULT_RESET_LOOP_TEST: retained=%u, next=Test-Fault",
                                 (uint32)FltMExt_SameFaultHwTestRetainedCount))
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else if (FltMExt_SameFaultHwTestRetryCount >= FLTMEXT_SAME_FAULT_HW_TEST_UART_MAX_RETRIES)
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else
  {
    FltMExt_SameFaultHwTestRetryCount++;
  }

  return flDone;
}

static boolean FltMExt_SameFaultResetLoopHwTest_LogInjection(void)
{
  boolean flDone = FALSE;

  if (E_OK == DltExt_Uart_Printf("SAMEFAULT_RESET_LOOP_TEST: inject Test-Fault ACTIVE"))
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else if (FltMExt_SameFaultHwTestRetryCount >= FLTMEXT_SAME_FAULT_HW_TEST_UART_MAX_RETRIES)
  {
    FltMExt_SameFaultHwTestRetryCount = 0U;
    flDone = TRUE;
  }
  else
  {
    FltMExt_SameFaultHwTestRetryCount++;
  }

  return flDone;
}

static boolean FltMExt_SameFaultResetLoopHwTest_ReadRetainedCount(void)
{
  Std_ReturnType flReadResult;

  flReadResult = RstM_GetEarlyResetCount(
    (eFltM_FaultIdType)FLTM_SAME_FAULT_HW_TEST_FAULT_ID,
    &FltMExt_SameFaultHwTestRetainedCount);

  return (boolean)((flReadResult == E_OK) ? TRUE : FALSE);
}

static void FltMExt_SameFaultResetLoopHwTest_SelectNextFault(void)
{
  FltMExt_SameFaultHwTestExpectFinalAction = FALSE;

  if (FltMExt_SameFaultResetLoopHwTest_ReadRetainedCount() == FALSE)
  {
    FltMExt_SameFaultResetLoopHwTest_StartAbort(FLTMEXT_HW_TEST_ABORT_API_FAILURE);
  }
  else if (FltMExt_SameFaultHwTestRetainedCount <= 2U)
  {
    FltMExt_SameFaultHwTestExpectFinalAction =
      (boolean)((FltMExt_SameFaultHwTestRetainedCount == 2U) ? TRUE : FALSE);
    FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_PRE_INJECTION;
  }
  else
  {
    FltMExt_SameFaultResetLoopHwTest_StartAbort(FLTMEXT_HW_TEST_ABORT_UNEXPECTED_STATE);
  }
}

static void FltMExt_SameFaultResetLoopHwTest_InjectFault(void)
{
  uint8 flLogData[5U] = {0xB1U, 1U, FltMExt_SameFaultHwTestRetainedCount, 0U, 0U};

  FltMExt_SameFaultHwTestInjectionIssued = TRUE;

  if (E_OK == FltM_ReportFault(FLTM_SAME_FAULT_HW_TEST_FAULT_ID,
                               FLTM_ACTIVE,
                               flLogData,
                               (uint16)sizeof(flLogData)))
  {
    FltMExt_SameFaultHwTestState = (FltMExt_SameFaultHwTestExpectFinalAction == TRUE) ?
      FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_FINAL_RESULT :
      FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
  }
  else
  {
    FltMExt_SameFaultResetLoopHwTest_StartAbort(FLTMEXT_HW_TEST_ABORT_REPORTFAULT_FAILURE);
  }
}

static void FltMExt_SameFaultResetLoopHwTest_MainFunction(void)
{
  switch (FltMExt_SameFaultHwTestState)
  {
    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_START_DELAY:
      if (FltMExt_SameFaultHwTestDelayTicks >= FLTMEXT_SAME_FAULT_HW_TEST_START_DELAY_TICKS)
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_READ_RETAINED_HISTORY;
      }
      else
      {
        FltMExt_SameFaultHwTestDelayTicks++;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_READ_RETAINED_HISTORY:
      FltMExt_SameFaultResetLoopHwTest_SelectNextFault();
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_PRE_INJECTION:
      if (FltMExt_SameFaultResetLoopHwTest_LogPreInjection() == TRUE)
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_INJECTION;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_LOG_INJECTION:
      if (FltMExt_SameFaultResetLoopHwTest_LogInjection() == TRUE)
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_INJECT_FAULT;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_INJECT_FAULT:
      if (FltMExt_SameFaultHwTestInjectionIssued == FALSE)
      {
        FltMExt_SameFaultResetLoopHwTest_InjectFault();
      }
      else
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_WAIT_FINAL_RESULT:
      if (FltMExt_SameFaultHwTestFinalActionSeen == TRUE)
      {
        FltMExt_SameFaultHwTestRetryCount = 0U;
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_FINAL;
      }
      else
      {
        /* Waiting for FltM to call the harmless test final callback. */
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_FINAL:
      if (FltMExt_SameFaultResetLoopHwTest_LogWithRetry(
            "SAMEFAULT_RESET_LOOP_TEST: FINAL_ACTION") == TRUE)
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_PASS;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_PASS:
      if (FltMExt_SameFaultResetLoopHwTest_LogWithRetry(
            "SAMEFAULT_RESET_LOOP_TEST: PASS; injector disarmed") == TRUE)
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      }
      break;

    case FLTMEXT_SAME_FAULT_HW_TEST_STATE_REPORT_ABORT:
      if ((FltMExt_SameFaultHwTestAbortReason == FLTMEXT_HW_TEST_ABORT_API_FAILURE) &&
          (FltMExt_SameFaultResetLoopHwTest_LogWithRetry(
            "SAMEFAULT_RESET_LOOP_TEST: ABORT retained-history API failure; injector disarmed") == TRUE))
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      }
      else if ((FltMExt_SameFaultHwTestAbortReason == FLTMEXT_HW_TEST_ABORT_REPORTFAULT_FAILURE) &&
               (FltMExt_SameFaultResetLoopHwTest_LogWithRetry(
                 "SAMEFAULT_RESET_LOOP_TEST: ABORT FltM_ReportFault failed; injector disarmed") == TRUE))
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      }
      else if ((FltMExt_SameFaultHwTestAbortReason == FLTMEXT_HW_TEST_ABORT_UNEXPECTED_STATE) &&
               (FltMExt_SameFaultResetLoopHwTest_LogWithRetry(
                 "SAMEFAULT_RESET_LOOP_TEST: ABORT unexpected history state; injector disarmed") == TRUE))
      {
        FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      }
      else
      {
        /* Retry from later 10 ms cycles until the bounded retry policy expires. */
      }
      break;

    default:
      FltMExt_SameFaultHwTestState = FLTMEXT_SAME_FAULT_HW_TEST_STATE_DISARMED;
      break;
  }
}

Std_ReturnType FltMExt_SameFaultHwTestFinalAction(FltM_FaultIdType FaultId)
{
  (void)FaultId;
  FltMExt_SameFaultHwTestFinalActionSeen = TRUE;
  return E_OK;
}
#endif


/* ---------------------------------------------------------------
 *  Service name     : FltMExt_InitialSafeAction
 *  Service ID       : 0x04
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Task/ISR2 (implementation dependent)
 *  Description      : Executes the first/initial safe action configured
 *                     for the given FaultId (e.g., limit features).
 *  Parameters (in)  : FaultId  - FltM fault identifier
 *  Parameters (out) : None
 *  Return value     : Std_ReturnType
 *                     E_OK      - Action executed/accepted
 *                     E_NOT_OK  - Action rejected/failed
 *  Preconditions    : FltM has determined the initial action threshold met.
 *  Postconditions   : System may transition to a safer operating mode.
 *  Notes            : Keep execution bounded; avoid blocking calls.
 * --------------------------------------------------------------- */
Std_ReturnType FltMExt_InitialSafeAction (FltM_FaultIdType FaultId)
{
  (void)FaultId;
    // Implementation of initial safe action based on FaultId
    // This is a placeholder; actual implementation will depend on system requirements
    return E_OK; // Assuming E_OK is defined in Std_Types.h for successful operation
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_FinalSafeAction
 *  Service ID       : 0x05
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Task/ISR2 (implementation dependent)
 *  Description      : Executes the final safe action configured for the
 *                     given FaultId (e.g., disable outputs, enter safe mode).
 *  Parameters (in)  : FaultId  - FltM fault identifier
 *  Parameters (out) : None
 *  Return value     : Std_ReturnType
 *                     E_OK      - Action executed/accepted
 *                     E_NOT_OK  - Action rejected/failed
 *  Preconditions    : FltM has determined the final action threshold met.
 *  Postconditions   : System transitions to final safe state if applicable.
 *  Notes            : Must be idempotent; avoid unbounded waits.
 * --------------------------------------------------------------- */
Std_ReturnType FltMExt_FinalSafeAction (FltM_FaultIdType FaultId)
{
    uint8 Iohw_Status = 0u;
    volatile boolean Halt = TRUE;

    if(FaultId == VOLTAGE_ERROR)
    {
        Supply_Voltage_Fault_Flag = TRUE;
    }
    if(FaultId == BACKLIGHT_ERROR)
    {
        Backlight_Fault_Flag = TRUE;
    }
    
    if(((FaultId == VOLTAGE_ERROR) || (FaultId == BACKLIGHT_ERROR)) && 
       ((Supply_Voltage_Fault_Flag == TRUE) || (Backlight_Fault_Flag == TRUE)))
    {

      // Specific handling for power supply and backlight faults
      
      (void)IoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TFT_BL_EN, STD_LOW, &Iohw_Status);
      
    }
    else
    {
#if (DLTEXT_UART_PRINT == STD_ON)
      uint8 DltExt_Uart_TxBuf[64u];
      uint32 DltExt_Written;
      Std_ReturnType flRetVal = E_OK;

      DltExt_Written = snprintf((char *)DltExt_Uart_TxBuf, sizeof(DltExt_Uart_TxBuf), "\r\nTaking FailSafe Action FID=%u\r\n", (uint32)FaultId);

      if ((DltExt_Written > 0) &&
          ((uint32)DltExt_Written < (uint32)sizeof(DltExt_Uart_TxBuf)))
      {
        /* Force UART into blocking polling mode for fatal path logging */
        (void)SciDrv_DisableChn(DLT_UART_CH);
        (void)SciDrv_SetSyncMode(DLT_UART_CH, eSciDrvSyncMode_Polling);
        (void)SciDrv_EnableChn(DLT_UART_CH);

        flRetVal = SciDrv_SetupEB(DLT_UART_CH,
                                  eSciDrvDirection_Transmit,
                                  (uint8 *)DltExt_Uart_TxBuf,
                                  (uint16)DltExt_Written);
        if (flRetVal == E_OK)
        {
          flRetVal = SciDrv_SyncTransmit(DLT_UART_CH);
        }
      }
#endif
      while(Halt == TRUE)
      {
        // Simulate a halt or safe state
      }
    }
    return E_OK; // Assuming E_OK is defined in Std_Types.h for successful operation
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_RecoveryAction
 *  Service ID       : 0x06
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Task/ISR2 (implementation dependent)
 *  Description      : Executes the recovery action configured for the
 *                     given FaultId (e.g., disable outputs, enter safe mode).
 *  Parameters (in)  : FaultId  - FltM fault identifier
 *  Parameters (out) : None
 *  Return value     : Std_ReturnType
 *                     E_OK      - Action executed/accepted
 *                     E_NOT_OK  - Action rejected/failed
 * --------------------------------------------------------------- */
Std_ReturnType FltMExt_RecoveryAction (FltM_FaultIdType FaultId)
{
    uint8 Iohw_Status = 0u;

    // Implementation of recovery action based on FaultId
    // This is a placeholder; actual implementation will depend on system requirements
    if(FaultId == VOLTAGE_ERROR)
    {
        // Battery Voltage Error recovery action
        Supply_Voltage_Fault_Flag = FALSE;
    }
    if(FaultId == BACKLIGHT_ERROR)
    {
        Backlight_Fault_Flag = FALSE;
    }

    if((Supply_Voltage_Fault_Flag != TRUE) && (Backlight_Fault_Flag != TRUE))
    {
        // Specific handling for power supply and backlight faults
        (void)IoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TFT_BL_EN, STD_HIGH, &Iohw_Status);
    }
    
    return E_OK; // Assuming E_OK is defined in Std_Types.h for successful operation
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_UserProtectionHook
 *  Service ID       : 0x07
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Exception/ISR2 (OS Protection Hook)
 *  Description      : SOC-specific handler invoked by the OS Protection Hook.
 *                     Maps the protection error to a FltM FaultId, stages a
 *                     minimal CPU dump (ProtErrorInfoType) via RstM, and
 *                     reports the fault to FltM for policy (fatal vs. log).
 *  Parameters (in)  : errInfo  - ProtectionErrType captured by OS
 *  Parameters (out) : None
 *  Return value     : uint8
 *                     PRO_IGNORE   - RstM/FltM will own escalation/reset
 *                     PRO_SHUTDOWN - Request OS shutdown (not typical here)
 *  Preconditions    : Called by OS via OS_PROTECTION_HOOK macro chain.
 *  Postconditions   : If configured fatal, FltM triggers RstM reset.
 *  Notes            : Keep execution minimal; no blocking; pointer/lifetime
 *                     safe because errInfo is passed by value (copied here).
 * --------------------------------------------------------------- */
/* Called from OS_PROTECTION_HOOK (UserProtectionHook) */

ProtectionRetType FltMExt_UserProtectionHook(ProtectionErrType errInfo)
{
  ProtectionRetType RetVal = PRO_IGNORE;
  eFltM_FaultIdType fid = FltMExt_MapProtErrorToFaultId(&errInfo);
  uint32 dfsrValue = (uint32)errInfo.os_faultFrame.DFSR;
  uint32 ifsrValue = (uint32)errInfo.os_faultFrame.IFSR;
  uint32 Faultaddress = (uint32)errInfo.os_faultFrame.FaultInstructionAddr;
  uint8 logdata[5] = {0xAAU, 0xAAU, 0XAAU, 0XAAU, 0XAAU};

  if (((dfsrValue & SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK) == SDL_EXCEPTION_SYNC_PARITY_OR_ECC_ERROR_MASK) ||
      ((dfsrValue & SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK) == SDL_EXCEPTION_ASYNC_PARITY_OR_ECC_ERROR_MASK))
  {
    RetVal = PRO_IGNORE;
  }
  else if ((errInfo.os_faultFrame.IFSR != 0U) &&
      (errInfo.os_faultFrame.DFSR == 0U))
  {
    if (fid != 0xFFFFU)
    {
      (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (uint32)sizeof(errInfo.os_faultFrame));
      logdata[0] = (uint8)(( (dfsrValue & 0x0000000FU) | ((dfsrValue & 0x00000400U) >> 6U) ) & 0xFFU);
      logdata[1] = (uint8)((ifsrValue >> 12U) & 0x00000001U);

      (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    }
    RetVal = PRO_IGNORE;
  }
  else if ((errInfo.os_faultFrame.DFSR != 0U) &&
           (errInfo.os_faultFrame.IFSR == 0U))
  {
    if (fid != 0xFFFFU)
    {
      (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (uint16)sizeof(errInfo.os_faultFrame));
      logdata[0] = (uint8)(((dfsrValue & 0x0000000FU) | ((dfsrValue & 0x00000400U) >> 6U)) & 0x000000FFU);
      logdata[1] = (uint8)((dfsrValue >> 11U) & 0x00000001U);
      logdata[2] = (uint8)((dfsrValue >> 12U) & 0x00000001U);
      logdata[3] = (uint8)((dfsrValue >> 4U) & 0x0000000FU);
      (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    }
    RetVal = PRO_IGNORE;
  }
  else if ((errInfo.os_faultFrame.DFSR == 0U) &&
           (errInfo.os_faultFrame.IFSR == 0U))
  {
    if (fid != 0xFFFFU)
    {
      (void)RstM_StageOsArmDump(fid, &errInfo.os_faultFrame, (uint16)sizeof(errInfo.os_faultFrame));
      Faultaddress = errInfo.os_faultFrame.FaultInstructionAddr;
      logdata[0] = (uint8)errInfo.CallingTask;
      logdata[1] = (uint8)((Faultaddress >> 24U) & 0xFFU);
      logdata[2] = (uint8)((Faultaddress >> 16U) & 0xFFU);
      logdata[3] = (uint8)((Faultaddress >> 8U) & 0xFFU);
      logdata[4] = (uint8)(Faultaddress & 0xFFU);
      (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
    }
    RetVal = PRO_IGNORE;
  }
  else
  {
    RetVal = PRO_IGNORE;
  }
  return RetVal;
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_UserErrorHook
 *  Service ID       : 0x08
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non Reentrant
 *  Context          : Task (OS Fatal/Application Error Hook)
 *  Description      : CPU-agnostic OS error hook. Maps OS error information
 *                     to a FltM FaultId and reports it to FltM. Severity/
 *                     reset policy is governed by FltM configuration.
 *  Parameters (in)  : errParam - OS error parameters (by value)
 *  Parameters (out) : None
 *  Return value     : void
 *  Preconditions    : Invoked by OS_ERROR_HOOK macro chain.
 *  Postconditions   : Fault may be logged and/or escalated based on config.
 *  Notes            : Does not perform reset directly; FltM->RstM handles it.
 * --------------------------------------------------------------- */

void FltMExt_UserErrorHook(const osErrParamType errParam)
{
  static volatile uint32 fluserErrorHook = 0U;    //#issue Review Problem ID 134052: Name 'fluserErrorHook' visibility is too wide.
  eFltM_FaultIdType fid = FltMExt_MapOsFatalToFltmFaultId(&errParam);
  uint8 logdata[5] = {0XAA, 0XAA, 0XAA, 0XAA, 0XAA};
  /* Send to FltM; FltM_FaultConfig[] decides if this is FATAL (then calls RstM) */
  if(fid != 0xFFFFU)
  {
    logdata[0] = (uint8)((uint32)errParam.OsServiceId & 0xFFU); 
    logdata[1] = errParam.ErrReason;
    logdata[2] = errParam.LastErrReason;
    logdata[3] = errParam.CallingTask;
    (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 5U);
  }
  fluserErrorHook++;
  /* Note: For fatal error hook, OS likely calls osShutdownOS() after this.
     If you later want RstM to own reset exclusively, youd need an OS option
     to skip shutdown, which this hook signature doesnt provide. */
}

/*============================================================================
**
** Function Name    :   FltMExt_UserShutdownHook
**
** Visibility       :   Public
**
** Description      :   Action which must be performed when shutdown error hook is invoked from os 
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void FltMExt_UserShutdownHook(void)
{   
    eFltM_FaultIdType fid = FLTM_E_OS_SHUTDOWN;
    uint8 logdata[1] = {0x00U};
    
    (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 1U);   //#issue Review Problem ID 152461: Index 3 can be used with array '&logdata' of size 1 that results in a pointer pointing outside the array boundary.
   
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_BuildAndReportOsArmDump
 *  Service ID       : 0x90  (static helper or public as per design)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non-Reentrant
 *  Context          : Privileged mode (SVC, IRQ, FIQ, Abort)
 *  Description      : Builds an ARM OS fault frame by reading CPU registers
 *                     (FaultInstructionAddr, LR, SPSR, DFSR, IFSR, MMAR) and
 *                     stages it for reset logging via RstM_StageOsArmDump.
 *  Parameters (in)  : None
 *  Parameters (out) : None
 *  Return value     : None
 *  Preconditions    : pFrame must not be NULL and must point to valid memory.
 *  Postconditions   : Fault frame is populated with current CPU state.
 *  Notes            : Used for non-OS triggered resets (e.g., ECC double-bit)
 *                     where OS does not provide the fault frame.
 * --------------------------------------------------------------- */
void FltMExt_BuildAndReportOsArmDump(eFltM_FaultIdType fid)
{
  ProtErrorInfoType dump;

  /* Clear dump */
  dump.FaultInstructionAddr = 0U;
  dump.lr = 0U;
  dump.spsr = 0U;
  dump.DFSR = 0U;
  dump.IFSR = 0U;
  dump.IsMMARValid = FALSE;
  dump.MMARErrAddress = 0U;

  /* Read CPU registers directly (same as OS does in its abort handlers) */
  __asm volatile("mov %0, lr" : "=r"(dump.lr));
  __asm volatile("mrs %0, spsr" : "=r"(dump.spsr));

  /* Fault status registers (CP15 c5 for DFSR/IFSR, c6 for FAR) */
  __asm volatile("mrc p15, 0, %0, c5, c0, 0" : "=r"(dump.DFSR)); /* DFSR */
  __asm volatile("mrc p15, 0, %0, c5, c0, 1" : "=r"(dump.IFSR)); /* IFSR */

  /* Fault address (IFAR / DFAR) */
  __asm volatile("mrc p15, 0, %0, c6, c0, 0" : "=r"(dump.MMARErrAddress)); /* DFAR/IFAR */

  /* Mark MMAR valid if the active fault status register is not async abort. */
  if (dump.DFSR != 0U)
  {
    if (((dump.DFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) &&
        ((dump.DFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
      dump.IsMMARValid = TRUE;
    }
  }
  else if (dump.IFSR != 0U)
  {
    if (((dump.IFSR & ASYNC_EXT_ABORT) != ASYNC_EXT_ABORT) &&
        ((dump.IFSR & ASYNC_ECC_ABORT) != ASYNC_ECC_ABORT))
    {
      dump.IsMMARValid = TRUE;
    }
  }

  /* Stage dump into RstM */
  (void)RstM_StageOsArmDump(fid, &dump, (uint16)sizeof(dump)); //#issue Review Problem ID 155158: Expression is cast to a type of potentially different size
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapProtErrorToFaultId
 *  Service ID       : 0x80  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any (called from hook)
 *  Description      : Maps a ProtectionErrType (Cortex-R5) into one of the
 *                     three SOC exception FIDs: Prefetch Abort, Data Abort,
 *                     or Undefined Instruction. Returns 0xFFFF if unknown.
 *  Parameters (in)  : ProtectionErr - Pointer to OS protection error info
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Minimal policy�no ECC/Parity classification per spec.
 * --------------------------------------------------------------- */
/* Map ProtectionError + ErrorContext to a FltM faultId */
static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const ProtectionErrType *ProtectionErr)
{
  eFltM_FaultIdType faultId = 0xFFFFU; // Default to invalid fault ID

  if (ProtectionErr == NULL_PTR)
  {
    faultId = 0xFFFFU; // Invalid fault ID 
    //#issue Warning Problem ID 155143: Number of return points RETURN: FltMExt_MapProtErrorToFaultId 2>1
  }
  else
  {
    /* Prefetch Abort path sets IFSR, clears DFSR */
  if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_MEMORY) &&
      (ProtectionErr->os_faultFrame.IFSR != 0U) &&
      (ProtectionErr->os_faultFrame.DFSR == 0U))
  {
    faultId = E_ARM_PREFETCH_ABORT_R5;
  }

  /* Data Abort path sets DFSR, clears IFSR */
  if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_MEMORY) &&
      (ProtectionErr->os_faultFrame.DFSR != 0U) &&
      (ProtectionErr->os_faultFrame.IFSR == 0U))
  {
    faultId = E_ARM_DATA_ABORT;
  }

  /* Undefined Instruction handler: both syndromes zero, exception type */
  if ((ProtectionErr->ProtectionError == E_OS_PROTECTION_EXCEPTION) &&
      (ProtectionErr->os_faultFrame.IFSR == 0U) &&
      (ProtectionErr->os_faultFrame.DFSR == 0U))
  {
    faultId = E_ARM_UNDEFINED_INSTRUCTION;
  }
  }
  return faultId; // Return the mapped fault ID
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapReason
 *  Service ID       : 0x81  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Maps an OS error reason code from OsError.h
 *                     to the FltM fault ID namespace (FLTM_E_OS_*).
 *  Parameters (in)  : reason  - OS reason code
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType (FLTM_E_OS_* or default)
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Keep in sync with OS reason enumeration.
 * --------------------------------------------------------------- */
static eFltM_FaultIdType FltMExt_MapReason(StatusType reason)
{
    eFltM_FaultIdType fid;
    switch (reason)
    {
    case E_OS_ACCESS:
        fid = FLTM_E_OS_ACCESS;
        break;
    case E_OS_CALLEVEL:
        fid = FLTM_E_OS_CALLLEVEL;
        break;
    case E_OS_ID:
        fid = FLTM_E_OS_ID;
        break;
    case E_OS_LIMIT:
        fid = FLTM_E_OS_LIMIT;
        break;
    case E_OS_NOFUNC:
        fid = FLTM_E_OS_NOFUNC;
        break;
    case E_OS_RESOURCE:
        fid = FLTM_E_OS_RESOURCE;
        break;
    case E_OS_STATE:
        fid = FLTM_E_OS_STATE;
        break;
    case E_OS_VALUE:
        fid = FLTM_E_OS_VALUE;
        break;
    case E_OS_SERVICEID:
        fid = FLTM_E_OS_SERVICEID;
        break;
    case E_OS_ILLEGAL_ADDRESS:
        fid = FLTM_E_OS_ILLEGAL_ADDRESS;
        break;
    case E_OS_MISSINGEND:
        fid = FLTM_E_OS_MISSINGEND;
        break;
    case E_OS_DISABLEDINT:
        fid = FLTM_E_OS_DISABLEDINT;
        break;
    case E_OS_STACKFAULT:
        fid = FLTM_E_OS_STACKFAULT;
        break;
    case E_OS_PROTECTION_MEMORY:
        fid = FLTM_E_OS_PROTECTION_MEMORY;
        break;
    case E_OS_PROTECTION_TIME:
        fid = FLTM_E_OS_PROTECTION_TIME;
        break;
    case E_OS_PROTECTION_ARRIVAL:
        fid = FLTM_E_OS_PROTECTION_ARRIVAL;
        break;
    case E_OS_PROTECTION_LOCKED:
        fid = FLTM_E_OS_PROTECTION_LOCKED;
        break;
    case E_OS_PROTECTION_EXCEPTION:
        fid = FLTM_E_OS_PROTECTION_EXCEPTION;
        break;
    case E_OS_SYS_ASSERTION:
        fid = FLTM_E_OS_SYS_ASSERTION;
        break;
    /* Current FltM config has no dedicated IDs for these OS system reasons. */
    case E_OS_SYS_ABORT:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    case E_OS_SYS_API_ERROR:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    case E_OS_SYS_ALARM_MANAGEMENT:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    case E_OS_SYS_WARNING:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    case E_OS_OVERLOAD:
        fid = FLTM_E_OS_SYS_OVERLOAD;
        break;
    default:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;
    }
    return fid; // Return the mapped fault ID
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapService
 *  Service ID       : 0x82  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Fallback mapping: derives a generic FltM fault
 *                     category from the OS Service ID when the reason
 *                     code is generic/unavailable.
 *  Parameters (in)  : sid   - OS Service ID (Autosar/OSEK + impl-specific)
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType (FLTM_E_OS_* category)
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Update when new service IDs are introduced.
 * --------------------------------------------------------------- */
/* Fallback categorization when Reason is unusable (should be rare) */
static eFltM_FaultIdType FltMExt_MapService(OsServiceIdType sid)
{
  eFltM_FaultIdType result = FLTM_E_OS_SYS_API_ERROR;  /* Default */
  
  switch (sid)
  {
    /* Task services */
    case OsDlt_OsActivateTask:
    case OsDlt_OsTerminateTask:
    case OsDlt_OsChainTask:
    case OsDlt_OsSchedule:
    case OsDlt_OsGetTaskID:
    case OsDlt_OsGetTaskState:
     /* Event services */
    case OsDlt_OsSetEvent:
    case OsDlt_OsClearEvent:
    case OsDlt_OsGetEvent:
    case OsDlt_OsWaitEvent:
      result = FLTM_E_OS_STATE;
      break;

    /* Resource services */
    case OsDlt_OsGetResource:
    case OsDlt_OsReleaseResource:
      result = FLTM_E_OS_RESOURCE;
      break;

    /* Alarm/Counter/ScheduleTable */
    case OsDlt_osSetRelAlarm:
    case OsDlt_osCancelAlarm:
    case OsDlt_osGetAlarm:
    case OsDlt_osSetAbsAlarm:
    case OsDlt_OsIncrementCounter:
    case OsDlt_OsGetCounterValue:
    case OsDlt_OsGetElapsedValue:
    case OsDlt_OsStartScheduleTableRel:
    case OsDlt_OsStartScheduleTableAbs:
    case OsDlt_OsStopScheduleTable:
    case OsDlt_OsGetScheduleTableStatus:
      result = FLTM_E_OS_VALUE;
      break;

    /* Interrupt control */
    case OsDlt_DisableInterruptSource:
    case OsDlt_EnableInterruptSource:
      result = FLTM_E_OS_SYS_PROTECTION_IRQ;
      break;

    /* App / trusted function */
    case OsDlt_OsGetApplicationState:
    case OsDlt_OsCallTrustedFunction:
      result = FLTM_E_OS_ACCESS;
      break;

    case OsDlt_osShutdownOS:
      result = FLTM_E_OS_SHUTDOWN;
      break;

    case OsDlt_OsInternalService:
    case OsDlt_OsInvalidService:
    default:
      result = FLTM_E_OS_SYS_API_ERROR;
      break;
  }
  
  return result;
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapOsFatalToFltmFaultId
 *  Service ID       : 0x83  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Determines the FltM fault ID for an OS fatal error,
 *                     preferring explicit reason mapping and falling back
 *                     to service-based categorization when needed.
 *  Parameters (in)  : pErrParam - Pointer to OS fatal error params
 *  Parameters (out) : None
 *  Return value     : eFltM_FaultIdType
 *  Preconditions    : None
 *  Postconditions   : None
 *  Notes            : Single return at end per your style.
 * --------------------------------------------------------------- */
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const osErrParamType *pErrParam)
{
  eFltM_FaultIdType fid = FLTM_E_OS_SYS_API_ERROR; /* default */

  if (pErrParam != NULL_PTR)
  {
    fid = FltMExt_MapReason(pErrParam->ErrReason);

    if (pErrParam->ErrReason == E_OS_INVALID)
    {
      fid = FltMExt_MapService(pErrParam->OsServiceId);
    }

#if (FLTMEXT_SUPPRESS_ACTIVATETASK_LIMIT_NOISY == STD_ON)
    if((pErrParam->ErrReason == E_OS_LIMIT) && (pErrParam->OsServiceId == OsDlt_OsActivateTask))
    {
      fid = 0xFFFFU;
    }
#endif
  }
  return fid;
}

#endif /* FLTMEXT_H */

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===================================================================================================*/
/*---------------------------------------------------------------------------------------------------
Date               : 17-Jun-2025
CDSID              : MSAVARIY
Traceability       :
Change Description : FltMExt Initial Version
                      https://visteon.atlassian.net/browse/PE4TI29141-8791
------------------------------------------------------------------------------------------------------*/
/* end of file ======================================================================================*/
