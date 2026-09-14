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
#if(DLTEXT_UART_PRINT == STD_ON)
#include "SciDrv.h"
#endif

/******************************************************************************
 * .............................Global Variables                              *
 ******************************************************************************/
#define FLTMEXT_OS_EXCEPTION_ID_UNDEFINED_INSTRUCTION    (1U)
#define FLTMEXT_OS_FAULT_REG_POISON_VALUE                (0x0000DEADUL)
#define CORTST_STR_FAULT_COUNT  "Fault Count %d \r\n"
#define MSRAM_STACK_START_ADDRESS		    0x79100000u	/* Refer Linkerr5.lds file -->MSRAM_STACK_MCU*/
#define MSRAM_STACK_END_ADDRESS		      0x7911FFFFu	/* size of MSRAM_STACK_MCU is 128Kb*/


extern FUNC(void, CBacklightCdd_CODE) CBacklightCdd_EnterSafeState(void);
extern FUNC(void, CBacklightCdd_CODE) CBacklightCdd_ExitSafeState(void);


static boolean Supply_Voltage_Fault_Flag = FALSE;
static boolean Backlight_Fault_Flag = FALSE;
static Os_ExceptionContextType FltMExt_OsExceptionContext;
/******************************************************************************
 *                              Macro Definition                              *
 ******************************************************************************/


/*****************************************************************************
 *                            Static  Declaration                             *
 ******************************************************************************/
static boolean FltMExt_IsPoisonRegisterValue(uint32 RegisterValue);
static boolean FltMExt_IsUndefinedInstructionContext(void);

static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const StatusType ProtectionErr);
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const Os_ErrorInformationType *pErrParam);
static eFltM_FaultIdType FltMExt_MapService(OSServiceIdType sid);
static eFltM_FaultIdType FltMExt_MapReason(StatusType reason);

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
  uint8 logdata[LOGDATA] = {0xAAU, 0xAAU, 0xAAU, 0xAAU, 0xAAU};
 
  (void)Rte_Call_rp_TI_EcuBatteryMData_EcuBatteryM_GetChannelStatus(2U, &OV_Status);
  (void)Rte_Call_rp_TI_EcuBatteryMData_EcuBatteryM_GetChannelStatus(3U, &UV_Status);
 
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
}

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
    // uint8 Iohw_Status = 0u;
    volatile boolean Halt = TRUE;
    static boolean Dcc_Fail_Flag = FALSE;
    static boolean POK_Fault_Flag = FALSE;
    static boolean FlashIntegrity_Fault_Flag = FALSE;
    static boolean CorTst_Fault_Flag = FALSE;
    static boolean WdgM_Fault_Flag = FALSE;
    static boolean Stack_Fault_Flag = FALSE;
    static boolean MPU_Fault_Flag = FALSE;
    static boolean Fwl_Fault_Flag = FALSE;
    static boolean Ecc_Fault_Flag = FALSE;
    uint8 flStoredResetCount = 0U;

    if(FaultId == VOLTAGE_ERROR)
    {
        Supply_Voltage_Fault_Flag = TRUE;
    }
    if(FaultId == BACKLIGHT_ERROR)
    {
        Backlight_Fault_Flag = TRUE;
    }
    if(FaultId == DCC_FAIL)
    {
        Dcc_Fail_Flag = TRUE;
    }
    if(FaultId == POK_FAULT)
    {
        POK_Fault_Flag = TRUE;
    }
    if(FaultId == FALSH_INTEGRITY_FAIL)
    {
        FlashIntegrity_Fault_Flag = TRUE;
    }
    if(FaultId == FLTM_E_CORTST_FAIL)
    {
      CorTst_Fault_Flag = TRUE;
    }
    if(FaultId == WDGM_ALIVE_FAIL)
    {
      WdgM_Fault_Flag = TRUE;
    }
    if(FaultId == FLTM_E_OS_STACKFAULT)
    {
      Stack_Fault_Flag = TRUE;
    }
    if(FaultId == FLTM_E_OS_PROTECTION_MEMORY)
    {
      MPU_Fault_Flag = TRUE;
    }
    if(FaultId == TIFS_SAFETY_CHECK_FWL_FAIL)
    {
      Fwl_Fault_Flag = TRUE;
    }
    if((FaultId == ECC_FAULT) || (FaultId == ECC_2BIT_ERROR))
    {
      Ecc_Fault_Flag = TRUE;
    }

    if(((FaultId == VOLTAGE_ERROR) || (FaultId == BACKLIGHT_ERROR) || (FaultId == DCC_FAIL) || (FaultId == POK_FAULT) || (FaultId == FALSH_INTEGRITY_FAIL) || (FaultId == FLTM_E_CORTST_FAIL) || 
        (FaultId == WDGM_ALIVE_FAIL) || (FaultId == FLTM_E_OS_STACKFAULT) || (FaultId == FLTM_E_OS_PROTECTION_MEMORY) || (FaultId == TIFS_SAFETY_CHECK_FWL_FAIL) || (FaultId == ECC_FAULT) || (FaultId == ECC_2BIT_ERROR)) && 
       ((Supply_Voltage_Fault_Flag == TRUE) || (Backlight_Fault_Flag == TRUE) || (Dcc_Fail_Flag == TRUE) ||(POK_Fault_Flag == TRUE) || (FlashIntegrity_Fault_Flag == TRUE) || (CorTst_Fault_Flag == TRUE) || 
       (WdgM_Fault_Flag == TRUE) || (Stack_Fault_Flag == TRUE) || (MPU_Fault_Flag == TRUE) || (Fwl_Fault_Flag == TRUE) || (Ecc_Fault_Flag == TRUE)))
    {
	  
	    /* Incase of Voltage transition - Handled by BacklightCDD */
      if( (FaultId != VOLTAGE_ERROR) && ( TRUE != Supply_Voltage_Fault_Flag ) )
      {
        (void)CBacklightCdd_EnterSafeState();
      }
      (void)RstM_GetEarlyResetCount(FaultId, &flStoredResetCount);
	    #if(DLTEXT_UART_PRINT == STD_ON)
      (void)DltExt_Uart_Printf(CORTST_STR_FAULT_COUNT, flStoredResetCount);
      const uint8 DltExt_Uart_TxBuf[] = "\r\nTaking FailSafe Action";
      (void)SciDrv_DisableChn(DLT_UART_CH);
      (void)SciDrv_SetAsyncMode(DLT_UART_CH, eSciDrvAsyncMode_Polling);
      (void)SciDrv_EnableChn(DLT_UART_CH);
      (void)SciDrv_SetupEB(DLT_UART_CH, \
                            eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, sizeof(DltExt_Uart_TxBuf));
      (void)SciDrv_SyncTransmit(DLT_UART_CH);
      #endif
    }
    else
    {
      #if(DLTEXT_UART_PRINT == STD_ON)
      uint8 DltExt_Uart_TxBuf[] = "\r\nTaking FailSafe Action";
      (void)SciDrv_DisableChn(DLT_UART_CH);
      (void)SciDrv_SetAsyncMode(DLT_UART_CH, eSciDrvAsyncMode_Polling);
      (void)SciDrv_EnableChn(DLT_UART_CH);
      (void)SciDrv_SetupEB(DLT_UART_CH, \
                          eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, sizeof(DltExt_Uart_TxBuf));
      (void)SciDrv_SyncTransmit(DLT_UART_CH);
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
    // uint8 Iohw_Status = 0u;
    if(FaultId == VOLTAGE_ERROR)
    {
        // Battery Voltage Error recovery action
        Supply_Voltage_Fault_Flag = FALSE;
    }
    if(FaultId == BACKLIGHT_ERROR)
    {
        Backlight_Fault_Flag = FALSE;
    }

    /* Recovery action will be called if FltM_ReportFault is called with
    INACTIVE state - SMs without that mechanism should not be configured here 
    Remover DDC, POK and FLASH INTEGRITY*/

    if((Supply_Voltage_Fault_Flag != TRUE) && (Backlight_Fault_Flag != TRUE))
    {
      (void)CBacklightCdd_ExitSafeState();
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

ProtectionReturnType FltMExt_UserProtectionHook(const StatusType errInfo)
{
  ProtectionReturnType retVal = PRO_IGNORE;
  StatusType osStatus;
  eFltM_FaultIdType faultId;
  FltMExt_ProtErrorInfoType protErrInfo = {0U};
  uint32 dfsrValue;
  uint32 ifsrValue;
  uint32 dfarValue;
  uint32 ifarValue;
  uint32 faultAddress;
  uint16 dumpLength;
  boolean isUndefinedInstruction;
  uint8 logdata[LOGDATA] = {0xAAU, 0xAAU, 0xAAU, 0xAAU, 0xAAU};

  osStatus = Os_GetExceptionContext(&FltMExt_OsExceptionContext);

  if (osStatus == E_OK)
  {
    isUndefinedInstruction = FltMExt_IsUndefinedInstructionContext();

    dfsrValue = (uint32)FltMExt_OsExceptionContext.DataFaultRegisters.DFSR;
    ifsrValue = (uint32)FltMExt_OsExceptionContext.InstructionFaultRegisters.IFSR;
    dfarValue = (uint32)FltMExt_OsExceptionContext.DataFaultRegisters.DFAR;
    ifarValue = (uint32)FltMExt_OsExceptionContext.InstructionFaultRegisters.IFAR;

    if (FltMExt_IsPoisonRegisterValue(dfsrValue) == TRUE)
    {
      dfsrValue = 0U;
    }

    if (FltMExt_IsPoisonRegisterValue(ifsrValue) == TRUE)
    {
      ifsrValue = 0U;
    }

    if (FltMExt_IsPoisonRegisterValue(dfarValue) == TRUE)
    {
      dfarValue = 0U;
    }

    if (FltMExt_IsPoisonRegisterValue(ifarValue) == TRUE)
    {
      ifarValue = 0U;
    }

    faultId = FltMExt_MapProtErrorToFaultId(errInfo);

    protErrInfo.FaultInstructionAddr =
        (osuint32)FltMExt_OsExceptionContext.ExceptionAddress;

    protErrInfo.r0 =
        (osuint32)FltMExt_OsExceptionContext.PreviousModeGpRegisters.R0;
    protErrInfo.r1 =
        (osuint32)FltMExt_OsExceptionContext.PreviousModeGpRegisters.R1;
    protErrInfo.r2 =
        (osuint32)FltMExt_OsExceptionContext.PreviousModeGpRegisters.R2;
    protErrInfo.r3 =
        (osuint32)FltMExt_OsExceptionContext.PreviousModeGpRegisters.R3;
    protErrInfo.r12 =
        (osuint32)FltMExt_OsExceptionContext.PreviousModeGpRegisters.R12;

    if (isUndefinedInstruction == TRUE)
    {
      protErrInfo.FaultException = 0x04U;
      protErrInfo.lr =
          (osuint32)FltMExt_OsExceptionContext.BankedRegisters.BankedUndRegisters.LR_und;
      protErrInfo.spsr =
          (osuint32)FltMExt_OsExceptionContext.BankedRegisters.BankedUndRegisters.SPSR_und;

      protErrInfo.DFSR = 0U;
      protErrInfo.IFSR = 0U;
      protErrInfo.IsMMARValid = FALSE;
      protErrInfo.MMARErrAddress = 0U;
    }
    else
    {
      protErrInfo.lr =
          (osuint32)FltMExt_OsExceptionContext.BankedRegisters.BankedAbtRegisters.LR_abt;
      protErrInfo.spsr =
          (osuint32)FltMExt_OsExceptionContext.BankedRegisters.BankedAbtRegisters.SPSR_abt;

      protErrInfo.DFSR = (osuint32)dfsrValue;
      protErrInfo.IFSR = (osuint32)ifsrValue;

      if (dfsrValue != 0U)
      {
        protErrInfo.FaultException = 0x01U;
        protErrInfo.MMARErrAddress = (osuint32)dfarValue;
      }
      else
      {
        protErrInfo.FaultException = 0x02U;
        protErrInfo.MMARErrAddress = (osuint32)ifarValue;
      }

      if (((protErrInfo.IFSR & FLTMEXT_ASYNC_EXT_ABORT) != FLTMEXT_ASYNC_EXT_ABORT) &&
          ((protErrInfo.IFSR & FLTMEXT_ASYNC_ECC_ABORT) != FLTMEXT_ASYNC_ECC_ABORT) &&
          (protErrInfo.MMARErrAddress != 0U))
      {
        protErrInfo.IsMMARValid = TRUE;
      }
      else
      {
        protErrInfo.IsMMARValid = FALSE;
      }
    }

    if (faultId != 0xFFFFU)
    {
      dumpLength = (uint16)sizeof(FltMExt_ProtErrorInfoType);
      (void)RstM_StageOsArmDump(faultId, &protErrInfo, dumpLength);

      if (isUndefinedInstruction == TRUE)
      {
        faultAddress = (uint32)protErrInfo.FaultInstructionAddr;

        logdata[0] = 0U;
        logdata[1] = (uint8)((faultAddress >> 24U) & 0x000000FFU);
        logdata[2] = (uint8)((faultAddress >> 16U) & 0x000000FFU);
        logdata[3] = (uint8)((faultAddress >> 8U) & 0x000000FFU);
        logdata[4] = (uint8)(faultAddress & 0x000000FFU);

        (void)FltM_ReportFault(faultId, FLTM_ACTIVE, logdata, LOGDATA);
      }
      else if ((ifsrValue != 0U) && (dfsrValue == 0U))
      {
        logdata[0] = (uint8)((ifsrValue & 0x0000000FU) |
                             ((ifsrValue & 0x00000400U) >> 6U));
        logdata[1] = (uint8)((ifsrValue >> 11U) & 0x00000001U);
        logdata[2] = (uint8)((ifsrValue >> 12U) & 0x00000001U);
        logdata[3] = (uint8)((ifsrValue >> 4U) & 0x0000000FU);
        logdata[4] = 0U;

        (void)FltM_ReportFault(faultId, FLTM_ACTIVE, logdata, LOGDATA);
      }
      else if ((dfsrValue != 0U) && (ifsrValue == 0U))
      {
        logdata[0] = (uint8)((dfsrValue & 0x0000000FU) |
                             ((dfsrValue & 0x00000400U) >> 6U));
        logdata[1] = (uint8)((dfsrValue >> 11U) & 0x00000001U);
        logdata[2] = (uint8)((dfsrValue >> 12U) & 0x00000001U);
        logdata[3] = (uint8)((dfsrValue >> 4U) & 0x0000000FU);
        logdata[4] = 0U;

        (void)FltM_ReportFault(faultId, FLTM_ACTIVE, logdata, LOGDATA);
      }
      else
      {
        (void)FltM_ReportFault(faultId, FLTM_ACTIVE, logdata, LOGDATA);
        /* Do nothing */
      }
    }
    else
    {
      /* Do nothing */
    }
  }
  else
  {
    /* Keep PRO_IGNORE */
  }

  return retVal;
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

void FltMExt_UserErrorHook(const Os_ErrorInformationType errParam, const StatusType errStatus)
{
  (void)errStatus; // errStatus can be used for additional filtering if needed
  static volatile uint32 fluserErrorHook = 0U;    //#issue Review Problem ID 134052: Name 'fluserErrorHook' visibility is too wide.
  eFltM_FaultIdType fid = FltMExt_MapOsFatalToFltmFaultId(&errParam);
  uint8 logdata[5] = {0XAA, 0XAA, 0XAA, 0XAA, 0XAA};
  TaskType TaskID;

  (void)GetTaskID(&TaskID);
  /* Send to FltM; FltM_FaultConfig[] decides if this is FATAL (then calls RstM) */
  if(fid != 0xFFFFU)
  {
    logdata[0] = (uint8)((uint32)errParam.Service & 0xFFU); 
    logdata[1] = errParam.DetailedError;
    logdata[2] = errParam.Error;
    logdata[3] = TaskID;
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

/*============================================================================
**
** Function Name    :   FltMExt_PanicHook
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
void FltMExt_PanicHook(const Os_PanicStatusType errParam)
{
    eFltM_FaultIdType fid = FLTM_E_OS_SHUTDOWN;
    uint8 logdata[5] = {0XAA, 0XAA, 0XAA, 0XAA, 0XAA};
    logdata[0] = errParam;
    
    (void)FltM_ReportFault(fid, FLTM_ACTIVE, logdata, 3U);   //#issue Review Problem ID 152461: Index 3 can be used with array '&logdata' of size 1 that results in a pointer pointing outside the array boundary.
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
  FltMExt_ProtErrorInfoType dump;

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

  /* Mark MMAR valid if not async aborts */
  if (((dump.IFSR & FLTMEXT_ASYNC_EXT_ABORT) != FLTMEXT_ASYNC_EXT_ABORT) &&
      ((dump.IFSR & FLTMEXT_ASYNC_ECC_ABORT) != FLTMEXT_ASYNC_ECC_ABORT))
  {
    dump.IsMMARValid = TRUE;
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
static eFltM_FaultIdType FltMExt_MapProtErrorToFaultId(const StatusType ProtectionErr)
{
  eFltM_FaultIdType faultId = 0xFFFFU;
  uint32 dfsrValue;
  uint32 ifsrValue;
  uint32 dfarValue;
  uint32 msram_stack_Start = MSRAM_STACK_START_ADDRESS;
  uint32 msram_stack_End   = MSRAM_STACK_END_ADDRESS; 

  dfsrValue = (uint32)FltMExt_OsExceptionContext.DataFaultRegisters.DFSR;
  ifsrValue = (uint32)FltMExt_OsExceptionContext.InstructionFaultRegisters.IFSR;  
  dfarValue = (uint32)FltMExt_OsExceptionContext.DataFaultRegisters.DFAR;

  if (FltMExt_IsPoisonRegisterValue(dfsrValue) == TRUE)
  {
    dfsrValue = 0U;
  }

  if (FltMExt_IsPoisonRegisterValue(ifsrValue) == TRUE)
  {
    ifsrValue = 0U;
  }

  if (FltMExt_IsUndefinedInstructionContext() == TRUE)
  {
    faultId = E_ARM_UNDEFINED_INSTRUCTION;
  }
  else if ((ProtectionErr == E_OS_PROTECTION_MEMORY) &&
           (ifsrValue != 0U) &&
           (dfsrValue == 0U))
  {
    faultId = E_ARM_PREFETCH_ABORT_R5;
  }
  else if ((ProtectionErr == E_OS_PROTECTION_MEMORY) &&
           (dfsrValue != 0U) &&
           (dfarValue >=  msram_stack_Start) &&
           (dfarValue <=  msram_stack_End))
  {
    faultId = FLTM_E_OS_STACKFAULT;
  }  
  else if ((ProtectionErr == E_OS_PROTECTION_MEMORY) &&
           (dfsrValue != 0U) &&
           (ifsrValue == 0U))
  {
    faultId = FLTM_E_OS_PROTECTION_MEMORY;
  }
  else
  {
    faultId = E_ARM_DATA_ABORT;
  }

  return faultId;
}

/* ---------------------------------------------------------------
 *  Service name     : FltMExt_MapReason
 *  Service ID       : 0x81  (static helper)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Reentrant
 *  Context          : Any
 *  Description      : Maps an OS error reason code (OS enum range 1..25,255)
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
    case 1u:
        fid = FLTM_E_OS_ACCESS;
        break;
    case 2u:
        fid = FLTM_E_OS_CALLLEVEL; /* note: OS typo CALLEVEL vs CALLLEVEL? use your final name */
        break;
    case 3u:
        fid = FLTM_E_OS_ID;
        break;
    case 4u:
        fid = FLTM_E_OS_LIMIT;
        break;
    case 5u:
        fid = FLTM_E_OS_NOFUNC;
        break;
    case 6u:
        fid = FLTM_E_OS_RESOURCE;
        break;
    case 7u:
        fid = FLTM_E_OS_STATE;
        break;
    case 8u:
        fid = FLTM_E_OS_VALUE;
        break;
    case 9u:
        fid = FLTM_E_OS_SERVICEID;
        break;
    case 10u:
        fid = FLTM_E_OS_ILLEGAL_ADDRESS;
        break;
    case 11u:
        fid = FLTM_E_OS_MISSINGEND;
        break;
    case 12u:
        fid = FLTM_E_OS_DISABLEDINT;
        break;
    case 13u:
        fid = FLTM_E_OS_STACKFAULT;
        break;
    case 14u:
        fid = FLTM_E_OS_PROTECTION_MEMORY;
        break;
    case 15u:
        fid = FLTM_E_OS_PROTECTION_TIME;
        break;
    case 16u:
        fid = FLTM_E_OS_PROTECTION_ARRIVAL;
        break;
    case 17u:
        fid = FLTM_E_OS_PROTECTION_LOCKED;
        break;
    case 18u:
        fid = FLTM_E_OS_PROTECTION_EXCEPTION;
        break;
    case 19u:
        fid = FLTM_E_OS_INTERFERENCE_DEADLOCK;
        break; 
    case 20u:
        fid = FLTM_E_OS_NESTING_DEADLOCK;
        break;
    case 21u:
        fid = FLTM_E_OS_SPINLOCK; 
        break;
    case 22u:
        fid = FLTM_E_OS_CORE;
        break;
    case 23u:
        fid = FLTM_E_OS_PARAM_POINTER; 
        break;
    case 241u:
        fid = FLTM_E_OS_SYS_DISABLED;
        break;
    case 242u:
        fid = FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT;
        break;
    case 243u:
        fid = FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY;
        break;
    case 244u:
        fid = FLTM_E_OS_SYS_NO_NTFSTACK;
        break;    
    case 245u:
        fid = FLTM_E_OS_SYS_OVERFLOW;
        break;  
    case 246u:
        fid = FLTM_E_OS_SYS_KILL_KERNEL_OBJ;
        break;
    case 247u:
        fid = FLTM_E_OS_SYS_NO_RESTARTTASK;
        break;  
    case 248u:
        fid = FLTM_E_OS_SYS_CALL_NOT_ALLOWED;
        break;  
    case 249u:
        fid = FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE;
        break; 
    case 250u:
        fid = FLTM_E_OS_SYS_PROTECTION_SYSCALL;
        break; 
    case 251u:
        fid = FLTM_E_OS_SYS_PROTECTION_IRQ;
        break; 
    case 252u:
        fid = FLTM_E_OS_SYS_API_ERROR;
        break;  
    case 253u:
        fid = FLTM_E_OS_SYS_ASSERTION;
        break;                                   
    case 254u:
        fid = FLTM_E_OS_SYS_OVERLOAD;
        break;
    default:
        fid = FLTM_E_OS_SYS_API_ERROR; // Default mapping for unknown reason codes
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
static eFltM_FaultIdType FltMExt_MapService(OSServiceIdType sid)
{
  eFltM_FaultIdType result = FLTM_E_OS_SYS_API_ERROR;  /* Default */
  
  switch (sid)
  {
    /* --- OS STATE / TASK / EVENT SERVICES --- */
    case OSServiceId_ActivateTask:
    case OSServiceId_ActivateTaskAsyn:
    case OSServiceId_TerminateTask:
    case OSServiceId_ChainTask:
    case OSServiceId_GetTaskID:
    case OSServiceId_GetTaskState:
    case OSServiceId_Schedule:
    case OSServiceId_SetEvent:
    case OSServiceId_SetEventAsyn:
    case OSServiceId_ClearEvent:
    case OSServiceId_GetEvent:
    case OSServiceId_WaitEvent:
    case OSServiceId_GetActiveApplicationMode:
    case OSServiceId_CheckTaskMemoryAccess:
    case OSServiceId_ScheduleTableActivateTask:
      result = FLTM_E_OS_STATE;
      break;

    /* --- RESOURCE / SPINLOCK SERVICES --- */
    case OSServiceId_GetResource:
    case OSServiceId_ReleaseResource:
      result = FLTM_E_OS_RESOURCE;
      break;
      
    case OSServiceId_GetSpinlock:
    case OSServiceId_ReleaseSpinlock:
    case OSServiceId_TryToGetSpinlock:
      result = FLTM_E_OS_SPINLOCK;
      break;

    /* --- ALARM / COUNTER / SCHEDULE TABLE (VALUE) --- */
    case OSServiceId_SetRelAlarm:
    case OSServiceId_SetAbsAlarm:
    case OSServiceId_CancelAlarm:
    case OSServiceId_GetAlarm:
    case OSServiceId_GetAlarmBase:
    case OSServiceId_IncrementCounter:
    case OSServiceId_GetCounterValue:
    case OSServiceId_GetElapsedValue:
    case OSServiceId_StartScheduleTableRel:
    case OSServiceId_StartScheduleTableAbs:
    case OSServiceId_StopScheduleTable:
    case OSServiceId_NextScheduleTable:
    case OSServiceId_SyncScheduleTable:
    case OSServiceId_SetScheduleTableAsync:
    case OSServiceId_StartScheduleTableSynchron:
    case OSServiceId_GetScheduleTableStatus:
    case OSServiceId_AlarmActionSetEvent:
    case OSServiceId_AlarmActionActivateTask:
    case OSServiceId_AlarmActionIncrementCounter:
    case OSServiceId_AlarmActionCallback:
    case OSServiceId_ScheduleTableSetEvent:
      result = FLTM_E_OS_VALUE;
      break;

    /* --- ACCESS / TRUSTED FUNCTIONS --- */
    case OSServiceId_GetApplicationID:
    case OSServiceId_GetCurrentApplicationID:
    case OSServiceId_GetApplicationState:
    case OSServiceId_AllowAccess:
    case OSServiceId_CheckObjectAccess:
    case OSServiceId_CheckObjectOwnership:
    case OSServiceId_CallTrustedFunction:
    case OSServiceId_CallFastTrustedFunction:
    case OSServiceId_CallNonTrustedFunction:
      result = FLTM_E_OS_ACCESS;
      break;

    /* --- INTERRUPT CONTROL --- */
    case OSServiceId_TimerIsr:
    case OSServiceId_IsrWrapper:
    case OSServiceId_DisableInterruptSource:
    case OSServiceId_GetISRID:
    case OSServiceId_CheckISRMemoryAccess:
    case OSServiceId_EnableInterruptSource:
    case OSServiceId_ClearPendingInterrupt:
    case OSServiceId_IsInterruptSourceEnabled:
    case OSServiceId_IsInterruptPending:
    case OSServiceId_InitialEnableInterruptSources:
    case OSServiceId_DisableAllInterrupts:
    case OSServiceId_EnableAllInterrupts:
    case OSServiceId_SuspendAllInterrupts:
    case OSServiceId_ResumeAllInterrupts:
    case OSServiceId_SuspendOSInterrupts:
    case OSServiceId_ResumeOSInterrupts:
      result = FLTM_E_OS_SYS_PROTECTION_IRQ;
      break;

    /* --- MULTICORE / CORE SERVICES --- */
    case OSServiceId_GetCoreID:
    case OSServiceId_StartCore:
    case OSServiceId_StartNonAutosarCore:
    case OSServiceId_GetNumberOfActivatedCores:
    case OSServiceId_GetCoreStartState:
      result = FLTM_E_OS_CORE;
      break;

    /* --- SHUTDOWN --- */
    case OSServiceId_ShutdownAllCores:
    case OSServiceId_TerminateApplication:
      result = FLTM_E_OS_SHUTDOWN;
      break;

    /* --- STACK USAGE (Diagnostic Access) --- */
    case OSServiceId_GetTaskStackUsage:
    case OSServiceId_GetISRStackUsage:
    case OSServiceId_GetKernelStackUsage:
    case OSServiceId_GetStartupHookStackUsage:
    case OSServiceId_GetErrorHookStackUsage:
    case OSServiceId_HookCallCallback:
    case OSServiceId_GetShutdownHookStackUsage:
    case OSServiceId_GetProtectionHookStackUsage:
    case OSServiceId_GetNonTrustedFunctionStackUsage:
    case OSServiceId_GetInitHookStackUsage:
      result = FLTM_E_OS_STACKFAULT; /* Or E_OS_ACCESS depending on policy */
      break;

    /* --- EXCEPTION / FAULT CONTEXT --- */
    case OSServiceId_GetExceptionContext:
    case OSServiceId_SetExceptionContext:
    case OSServiceId_GetUnhandledExc:
    case OSServiceId_GetUnhandledIrq:
      result = FLTM_E_OS_SYS_PROTECTION_SYSCALL;
      break;

    case OSServiceId_IocSend:
    case OSServiceId_ControlIdle:
    case OSServiceId_IocWrite:
    case OSServiceId_IocSendGroup:
    case OSServiceId_IocWriteGroup:
    case OSServiceId_IocReceive:
    case OSServiceId_IocReadGroup:
    case OSServiceId_IocEmptyQueue:
    case OSServiceId_AppKill:
    case OSServiceId_GetSemaphore:
    case OSServiceId_ReleaseSemaphore:
    case OSServiceId_BarrierSynchronize:
    case OSServiceId_FrtSetFutureCompareValue:
    case OSServiceId_FrtSetCompareValue:
    case OSServiceId_StartOS:
      result = FLTM_E_OS_SYS_API_ERROR; /* No better category, but can be updated if needed */
      break;

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
static eFltM_FaultIdType FltMExt_MapOsFatalToFltmFaultId(const Os_ErrorInformationType *pErrParam)
{
  eFltM_FaultIdType fid = FLTM_E_OS_SYS_API_ERROR; /* default */


    fid = FltMExt_MapReason(pErrParam->Error);

    /* If still generic (and not explicit SYS_ABORT=21), fall back to service */
    if ((fid == FLTM_E_OS_SYS_API_ERROR) && (pErrParam->Error != 21U))
    {
      fid = FltMExt_MapService(pErrParam->Service);
    }
    /* to be decide as this continuously coming - msavariy*/
    /*Error - 0x04 = E_OS_LIMIT, OsServiceId - 0x30 = OsDlt_OsActivateTask */
    if((pErrParam->Error == 0x04U) && (pErrParam->Service == 0x30U))
    {
      fid = 0xFFFFU;
    }

  return fid;
}

static boolean FltMExt_IsPoisonRegisterValue(uint32 RegisterValue)
{
  boolean retVal = FALSE;

  if (RegisterValue == FLTMEXT_OS_FAULT_REG_POISON_VALUE)
  {
    retVal = TRUE;
  }

  return retVal;
}

static boolean FltMExt_IsUndefinedInstructionContext(void)
{
  boolean retVal = FALSE;

  if ((uint32)FltMExt_OsExceptionContext.ExceptionId ==
      FLTMEXT_OS_EXCEPTION_ID_UNDEFINED_INSTRUCTION)
  {
    retVal = TRUE;
  }

  return retVal;
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