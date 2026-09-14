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
 *  File Name         :  RstM.c                                               *
 *  Module Short Name :  RstM                                                 *
 *  Description       :  This file contains implementations of Reset Manager  *
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
#ifndef RSTM_C
#define RSTM_C

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "RstM.h"
#include "FltM.h"
#include "Dlt.h"
#include "DltExt.h"
#include "EcuMExt.h"
#include "Rte_RstM.h"
#include "MemLib.h"
#include "CmpLib.h"

#define RSTM_SEC_CODE_START
#define RSTM_CORE_CONST_SEC_START
#define RSTM_CORE_DATA_SEC_START
#define RSTM_CORE_BSS_SEC_START

#include "MemMap.h"

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(RstM)
/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
/* Structure to hold Fault Category and Fault Code */
typedef struct
{
  uint8 faultCategory; /* First byte: Fault Category */
  uint8 faultCode;     /* Second byte: Fault Code */
} RstM_FaultMessageIDType;

/* Structure to store reset count for each fault ID */
typedef struct
{
  eFltM_FaultIdType faultId; /* Fault ID */
  uint16 resetCount;         /* Reset count for this fault ID */
  boolean isValid;           /* Flag to indicate if this entry is valid */
} RstM_FaultResetCountType;

typedef struct
{
  eFltM_FaultIdType faultId;      /* Fault ID */
  uint8 Dump[RSTM_MAX_DUMP_SIZE]; /* Protection error dump */
  uint8 DumpSize;                 /* Size of the dump */
  boolean isValid;                /* Flag to indicate if this entry is valid */
} RstM_OsArmDumpType;

/*****************************************************************************
 *                  Globally  accessed Variable Declarations                  *
 ******************************************************************************/

/*****************************************************************************
 *                   Locally used Variable Declarations                       *
 ******************************************************************************/
/* Variable to store reset history code from DLTEXT */
tDltExt_ResetLogDataBuffer RstM_RetreivedLogData;

/* Local storage for reset history codes - 12 bytes data only */
static uint8 RstM_ResetHistoryCode[RSTM_LAST_RESET_HISTORY_NUM][RSTM_MAX_RESETCODE_SIZE];

/* Array to store reset count for each fault - size based on history size */
static RstM_FaultResetCountType RstM_FaultResetCount[RSTM_LAST_RESET_HISTORY_NUM];

static RstM_OsArmDumpType RstM_LastOsArmDump;

/* Variable to check the DltExt_GetResetInfo return OK*/
static boolean RstM_ResetHistoryDataValid;

extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, uint8 *logData, uint16 logDataLength);
/*****************************************************************************
 *                   Locally used Function Declarations                       *
 ******************************************************************************/
static Std_ReturnType CmpInit(void);
static Std_ReturnType CmpDeInit(void);
static Std_ReturnType CmpActivation(void);
static Std_ReturnType CmpDeActivation(void);
static Std_ReturnType CmpActive(void);
static Std_ReturnType CmpDiagReturn(void);

static void RstM_CopyResetHistoryData(void);
static void RstM_UpdateResetCounts(void);
static Std_ReturnType RstM_GetConfigIndexById(uint16 FaultId, uint8 *FaultConfigIndexPtr);

/*****************************************************************************
 *                   Locally used Function Definitions                       *
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
  RstM_Init();
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
  RstM_MainFunction();
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
** Function Name    :   RstM_Init
**
** Visibility       :   Public
**
** Description      :   Function to initialize RstM module
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
extern void RstM_Init(void)
{
  /* Initialize reset count array */
  uint8 i;
  for (i = 0u; i < RSTM_LAST_RESET_HISTORY_NUM; i++)
  {
    RstM_FaultResetCount[i].faultId = 0;
    RstM_FaultResetCount[i].resetCount = 0;
    RstM_FaultResetCount[i].isValid = FALSE;
  }

  RstM_ResetHistoryDataValid = FALSE;
}

/*============================================================================
** Function Name    :   RstM_GetLastResetReason
**
** Visibility       :   Public
**
** Description      :   Function to be called from other modules to get the last
**                      reset info
**
** Invocation       :   Application
**
** Inputs           :   eFltM_FaultIdType* lastResetInfo - Pointer to store last reset info
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK if failed
**
** Critical Section :   No
**==========================================================================*/
Std_ReturnType RstM_GetLastResetReason(eFltM_FaultIdType *lastResetInfo)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint16 flFaultMessageId = 0;
  RstM_FaultMessageIDType flFaultMessageIdStruct;
  PmicCdd_ResetReasonType flResetReason;

  /* Check if the input pointer is valid */
  if (lastResetInfo != NULL_PTR)
  {
    *lastResetInfo = 0;
    if (RstM_ResetHistoryDataValid == TRUE)
    {
      flResetReason = PmicCdd_GetResetReason();
      if (PmicCdd_PmicWdg_Reset == flResetReason)
      {
        flFaultMessageIdStruct.faultCategory = RstM_ResetHistoryCode[RSTM_LASTESTRESET_INDEX][0];
        flFaultMessageIdStruct.faultCode = RstM_ResetHistoryCode[RSTM_LASTESTRESET_INDEX][1];

        /* Check if the FaultCategory is valid */
        if ((flFaultMessageIdStruct.faultCategory & RSTM_FAULT_CATEGORY_VALID) == RSTM_FAULT_CATEGORY_VALID)
        {
          /* Extract the first 2 bytes from the latest reset history (index 0 - DLEXT specific) */
          /* First byte: Fault Category, Second byte: Fault Code */
          flFaultMessageId = ((uint16)flFaultMessageIdStruct.faultCategory << RSTM_BYTE_BIT_SHIFT) | ((uint16)flFaultMessageIdStruct.faultCode);

          /* Convert the 2-byte FaultMessageId to eFltM_FaultIdType */
          *lastResetInfo = (eFltM_FaultIdType)flFaultMessageId;
          flRetVal = E_OK;
        }
      }
      else if (PmicCdd_PowerOn_Reset == flResetReason)
      {
        /* If PMIC reset reason is PowerOn, set last reset info to 0 */
        *lastResetInfo = POWER_ON_RESET;
        flRetVal = E_OK; // Still return OK, but no valid reset reason
      }
      else if (PmicCdd_Wakeup == flResetReason)
      {
        /* If PMIC reset reason is PowerOn, set last reset info to 0 */
        *lastResetInfo = PMIC_SLEEP_RESET;
        flRetVal = E_OK; // Still return OK, but no valid reset reason
      }
      else
      {
        *lastResetInfo = 0;
      }
    }
  }
  else
  {
    RstM_Det_ReportError(RSTM_GETLASTRESET, RSTM_NULL_POINTER_ERROR);
  }

  return flRetVal;
}

/*============================================================================
** Function Name    :   RstM_RequestSwReset
**
** Visibility       :   Public
**
** Description      :   Logs an error and perform the required reset
**
** Invocation       :   Application
**
** Inputs           :   RstM_ResetLogType ResetLog - Reset log information
**                      that contains fault ID, log data and reset type
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK if failed
**
** Critical Section :   Yes
**==========================================================================*/
Std_ReturnType RstM_RequestSwReset(const eFltM_FaultIdType FaultId, uint8 *LogData, uint16 LogLength)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    Dlt_MessageLogInfoType fllogInfo;
    uint8 flConfigIndex = 0;
    const RstM_FaultConfigType *flFaultConfig = NULL;

    /* Get fault configuration based on fault ID */
    flRetVal = RstM_GetConfigIndexById(FaultId, &flConfigIndex);
    if ((flRetVal == E_OK) && (flConfigIndex < RSTM_MAX_NUM_FAULTS))
    {
      flFaultConfig = &RstM_FaultConfig[flConfigIndex];
    if (LogData != NULL_PTR)
    {
      /* Dlt Log info */
      fllogInfo.argCount = RstM_Dlt_MessageLogInfo.argCount;
      fllogInfo.logLevel = RstM_Dlt_MessageLogInfo.logLevel;
      fllogInfo.options = RstM_Dlt_MessageLogInfo.options;
      
      (void)MemLib_MemCpy(fllogInfo.appId, RstM_Dlt_MessageLogInfo.appId,
                      (uint32)sizeof(Dlt_ApplicationIDType));
      (void)MemLib_MemCpy(fllogInfo.contextId, RstM_Dlt_MessageLogInfo.contextId,
                      (uint32)sizeof(Dlt_ContextIDType));

      /* DLT Implementation to be called*/
      if (RstM_LastOsArmDump.isValid == FALSE)
      {
        RstM_Callout_FltMExt_BuildAndReportOsArmDump(FaultId);
      }
      RstM_LastOsArmDump.isValid = FALSE; // Clear the flag after pushing the dump
      /* Push the OS ARM dump to DLT */
      DltExt_RstMPushOsArmDump(RstM_LastOsArmDump.Dump, RstM_LastOsArmDump.DumpSize);
      /* Send the reset log message to DLT */
      (void)Dlt_SendLogMessage(RstM_Dlt_MessageLogInfo.SessionId, &fllogInfo, LogData, LogLength);

      switch (flFaultConfig->ResetType)
      {
      case PMIC_RESET:
        /* Implement PMIC RESET DLT log*/
        PmicCdd_PerformReset();
        flRetVal = E_OK;

        break;
      case MCU_RESET:
        #if (PMICCDD_ENABLE_WDG == STD_ON)
          /*Enter long window reset Logic*/
          (void)PmicCdd_EnterWdgLongWin(TRUE);
          flRetVal = E_OK;
          break;
        #else
          /* Implement MCU RESET DLT log*/
          Mcu_PerformReset();
          flRetVal = E_OK;
          break;
        #endif
      default:
        flRetVal = E_NOT_OK; // Invalid reset type
        /* Implementation not needed to handle other error severity */
        RstM_Det_ReportError(RSTM_REQUESTSWRESET, RSTM_INVALID_RESET_TYPE_ERROR);
        break;
      }
    }
    else
    {
      RstM_Det_ReportError(RSTM_REQUESTSWRESET, RSTM_NULL_POINTER_ERROR);
      flRetVal = E_NOT_OK;
    }
  }
  else
  {
    RstM_Det_ReportError(RSTM_REQUESTSWRESET, RSTM_INVALID_FAULT_ID);
    flRetVal = E_NOT_OK;
  }
  return flRetVal;
}

/*============================================================================
** Function Name    :   RstM_GetResetHistory
**
** Visibility       :   Public
**
** Description      :   Gets the reset history from the reset log
**
** Invocation       :   Application
**
** Inputs           :   uint8* ResetHistory - Pointer to buffer for reset history
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK if failed
**
** Critical Section :   No
**==========================================================================*/
Std_ReturnType RstM_GetResetHistory(uint8 *ResetHistory)
{
  Std_ReturnType status = E_NOT_OK;
  uint8 flIndex_i, flIndex_j = 0u;
  uint8 *pResetHistory = ResetHistory;

  if (ResetHistory != NULL_PTR)
  {
    /* Copy the reset history codes from local storage to output buffer */
    for (flIndex_i = 0u; flIndex_i < RSTM_LAST_RESET_HISTORY_NUM; flIndex_i++)
    {
      for (flIndex_j = 0u; flIndex_j < RSTM_MAX_RESETCODE_SIZE; flIndex_j++)
      {
        *pResetHistory = RstM_ResetHistoryCode[flIndex_i][flIndex_j];
        pResetHistory++;
      }
    }
    status = E_OK;
  }
  else
  {
    RstM_Det_ReportError(RSTM_GETRESETHISTORY, RSTM_NULL_POINTER_ERROR);
  }

  return status;
}

/*============================================================================
** Function Name    :   RstM_ClearResetHistory
**
** Visibility       :   Public
**
** Description      :   Clears the reset history
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK if failed
**
** Critical Section :   Yes
**==========================================================================*/
Std_ReturnType RstM_ClearResetHistory(void)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint8 flIndex_i, flIndex_j = 0u;

  /* Clear the local reset history codes array */
  for (flIndex_i = 0u; flIndex_i < RSTM_LAST_RESET_HISTORY_NUM; flIndex_i++)
  {
    for (flIndex_j = 0u; flIndex_j < RSTM_MAX_RESETCODE_SIZE; flIndex_j++)
    {
      RstM_ResetHistoryCode[flIndex_i][flIndex_j] = 0x00;
      flRetVal = E_OK;
    }
    /* Clear reset count array */
    RstM_FaultResetCount[flIndex_i].faultId = 0;
    RstM_FaultResetCount[flIndex_i].resetCount = 0;
    RstM_FaultResetCount[flIndex_i].isValid = FALSE;
  }

  return flRetVal;
}

/*============================================================================
** Function Name    :   RstM_GetResetCount
**
** Visibility       :   Public
**
** Description      :   Gets the reset count for the given fault ID
**
** Invocation       :   Application
**
** Inputs           :   eFltM_FaultIdType FaultId - Fault ID
**
**                      uint8* Count - Pointer to store the reset count
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK if failed
**
** Critical Section :   No
**==========================================================================*/
Std_ReturnType RstM_GetResetCount(eFltM_FaultIdType FaultId, UInt8 *count)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  uint8 flCountIndex = 0;

  /* Check if input parameters are valid */
  if ((count != NULL_PTR) && (FaultId != 0u))
  {
    if (RstM_ResetHistoryDataValid == TRUE)
    {
      /* Search for the fault ID in reset count array */
      for (flCountIndex = 0u; flCountIndex < RSTM_LAST_RESET_HISTORY_NUM; flCountIndex++)
      {
        if ((RstM_FaultResetCount[flCountIndex].isValid == TRUE) &&
            (RstM_FaultResetCount[flCountIndex].faultId == FaultId))
        {
          /* Fault ID found, return the count */
          *count = (uint8)RstM_FaultResetCount[flCountIndex].resetCount;
          flRetVal = E_OK;
          break;
        }
      }

      /* If fault ID not found, return count as 0 */
      if (flRetVal == E_NOT_OK)
      {
        *count = 0;
        flRetVal = E_OK; /* Still return OK, but count is 0 */
      }
    }
  }
  else
  {
    RstM_Det_ReportError(RSTM_GETRESETCOUNT, RSTM_NULL_POINTER_ERROR);
  }

  return flRetVal;
}

#if defined (SOC_AM62PX) || defined (SOC_AM62P)
/*============================================================================
** Function Name    :   RstM_EnableResetIsolation
**
** Visibility       :   Public
**
** Description      :   Function to be called to enable the Reset Isolation.
**
**                      MCU domain is exempt from domain resets
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
Std_ReturnType RstM_EnableResetIsolation(void)
{
  Std_ReturnType Status = E_NOT_OK;
  /* Implement the Reset Isolation - MCU domain is exempt from domain resets */
  uint32_t RstM_PscMain2MCUDisable, RstM_PscMCU2MainDisable, RstM_DebugIsolationEnable, RstM_PscMCU2DMDisable;

  /* Disabling Main2MCU PSC. This would restrict the main domain from accessing
  MCU domain peripherals/registers. Care must be taken no Main domain cores access
  MCU domain registers after this */
  RstM_PscMain2MCUDisable = 0;
  /* Disabling MCU2Main PSC. This would restrict the MCU domain from accessing
  Main domain peripherals/registers. Care must be taken no MCU domain cores access
  Main domain registers after this */
  RstM_PscMCU2MainDisable = 0;
  RstM_PscMCU2DMDisable = 0;
  /* Enabling debug isolation will restrict the JTAG access to MCU domain */
  RstM_DebugIsolationEnable = 0;

  Status = SOC_enableResetIsolation(RstM_PscMain2MCUDisable, RstM_PscMCU2MainDisable,
                                    RstM_PscMCU2DMDisable,
                                    RstM_DebugIsolationEnable);

  SOC_controlModuleUnlockMMR(SOC_DOMAIN_ID_MCU, 6u);
  SOC_controlModuleUnlockMMR(SOC_DOMAIN_ID_MCU, 1u);

  /* Block ESM MCU domain reset */
  CSL_REG32_FINS(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_RST_CTRL, \
          MCU_CTRL_MMR_CFG0_RST_CTRL_MCU_ESM_ERROR_RST_EN_Z, 1);

  SOC_controlModuleLockMMR(SOC_DOMAIN_ID_MCU, 6u);
  SOC_controlModuleLockMMR(SOC_DOMAIN_ID_MCU, 1u);


  SOC_controlModuleUnlockMMR(SOC_DOMAIN_ID_WKUP, 0u);

  /* Block ESM MAIN domain reset */
  CSL_REG32_FINS(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_RST_CTRL, \
          WKUP_CTRL_MMR_CFG0_RST_CTRL_MAIN_ESM_ERROR_RST_EN_Z, 1);

  SOC_controlModuleLockMMR(SOC_DOMAIN_ID_WKUP, 0u);

  return Status;
}

/*============================================================================
** Function Name    :   RstM_ProcessResetIsolationReq
**
** Visibility       :   Public
** Description      :   Function to be called to process the Reset Isolation
**
**                      request and perform domain reset
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
void RstM_ProcessResetIsolationReq(void)
{
  uint32 resetSrc;
  uint8 logData[RSTM_LOG_DATA_SIZE] = {0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};

  /* Checking the PSC states and disabling is also not needed. Because if other domain request
  reset we will be doing the entire SOC reset */
  
  /* Clear reset source */
  resetSrc = SOC_getWarmResetCauseMcuDomain();
  
  logData[RSTM_IDX_BYTE_0] = (uint8)(resetSrc & RSTM_BYTE_MASK);                              // Bits [7:0]
  logData[RSTM_IDX_BYTE_1] = (uint8)((resetSrc >> RSTM_SHIFT_8) & RSTM_BYTE_MASK);           // Bits [15:8]
  logData[RSTM_IDX_BYTE_2] = (uint8)((resetSrc >> RSTM_SHIFT_16) & RSTM_BYTE_MASK);          // Bits [23:16]
  logData[RSTM_IDX_BYTE_3] = (uint8)((resetSrc >> RSTM_SHIFT_24) & RSTM_BYTE_MASK);          // Bits [31:24]
  
  SOC_clearResetCauseMainMcuDomain(resetSrc);

  /* Allowing main domain reset to propogate is not suggested as the VIP is using
  DDR, it will get disconnected and single domain will be resetted*/

  /* FltM_ReportFault is called before resetting */
  /* Perform both MCU and MAIN domain reset */
  (void)FltM_ReportFault(SW_MAIN_WARMRSTz, FLTM_ACTIVE, logData, RSTM_LOG_DATA_SIZE);
}
#endif

/*============================================================================
** Function Name    :   RstM_MainFunction
**
** Visibility       :   Public
**
** Description      :   Function to be called from the main function for
**
**                      periodic processing
**
** Invocation       :   Application
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/
void RstM_MainFunction(void)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  /* Function to be called from the main function */
  /* Any code required to be executed before the main function can be added here */
  if ((RstM_ResetHistoryDataValid == FALSE) && (RSTM_NVM_READALL_COMPLETE == TRUE))
  {
    flRetVal = DltExt_GetResetInfo(&RstM_RetreivedLogData);
    if (flRetVal == E_OK)
    {
      RstM_CopyResetHistoryData();
      RstM_UpdateResetCounts();
      RstM_ResetHistoryDataValid = TRUE;
    }
  }
}

/*============================================================================
** Function Name    :   RstM_CopyResetHistoryData
**
** Visibility       :   Private
**
** Description      :   Copies reset history code data from DLT buffer to local
**                      storage
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
static void RstM_CopyResetHistoryData(void)
{
  boolean flStatus = FALSE;
  uint8 i, j;
  uint8 flMaxEntries, flMaxCodeSize;
  /* Determine maximum entries to copy */
  if ((RSTM_LAST_RESET_HISTORY_NUM == DLTEXT_TOTAL_NUM_OF_RESET_HISTORY) && (RSTM_MAX_RESETCODE_SIZE == DLTEXT_ADDITIONAL_RESET_INFO_SIZE))
  {
    flMaxEntries = RSTM_LAST_RESET_HISTORY_NUM;
    flMaxCodeSize = RSTM_MAX_RESETCODE_SIZE;
    flStatus = TRUE;
  }

  if (flStatus != FALSE)
  {
    /* Copy only the code portion from DLT buffer to local storage */
    for (i = 0u; i < flMaxEntries; i++)
    {
      for (j = 0u; j < flMaxCodeSize; j++)
      {
        RstM_ResetHistoryCode[i][j] = RstM_RetreivedLogData.code[i][j];
      }
    }
  }
  else
  {
    RstM_Det_ReportError(RSTM_INIT, RSTM_LENGTH_MISMATCH_ERROR);
  }
}

/*============================================================================
** Function Name    :   RstM_UpdateResetCounts
**
** Visibility       :   Private
**
** Description      :   Updates reset count for each fault ID by analyzing
**
**                      reset history data
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**==========================================================================*/
static void RstM_UpdateResetCounts(void)
{
  uint8 flHistoryIndex = 0;
  uint8 flCountIndex = 0;
  eFltM_FaultIdType flCurrentFaultId = 0;
  boolean flFaultFound = FALSE;
  uint16 flFaultMessageId = 0;

  /* Initialize reset count array if not already done */
  for (flCountIndex = 0u; flCountIndex < RSTM_LAST_RESET_HISTORY_NUM; flCountIndex++)
  {
    if (RstM_FaultResetCount[flCountIndex].isValid == FALSE)
    {
      RstM_FaultResetCount[flCountIndex].faultId = 0;
      RstM_FaultResetCount[flCountIndex].resetCount = 0;
    }
  }

  /* Analyze each entry in reset history */
  for (flHistoryIndex = 0u; flHistoryIndex < RSTM_LAST_RESET_HISTORY_NUM; flHistoryIndex++)
  {
    /* Extract fault message ID from first 2 bytes */
    flFaultMessageId = ((uint16)RstM_ResetHistoryCode[flHistoryIndex][0] << RSTM_BYTE_BIT_SHIFT) |
                       ((uint16)RstM_ResetHistoryCode[flHistoryIndex][1]);

    flCurrentFaultId = (eFltM_FaultIdType)flFaultMessageId;

    /* Skip if fault ID is invalid (0x00) */
    if (((flCurrentFaultId >> RSTM_BYTE_BIT_SHIFT) & RSTM_FAULT_CATEGORY_VALID) == RSTM_FAULT_CATEGORY_VALID)
    {
      flFaultFound = FALSE;

      /* Search if this fault ID already exists in count array */
      for (flCountIndex = 0u; flCountIndex < RSTM_LAST_RESET_HISTORY_NUM; flCountIndex++)
      {
        if ((RstM_FaultResetCount[flCountIndex].isValid == TRUE) &&
            (RstM_FaultResetCount[flCountIndex].faultId == flCurrentFaultId))
        {
          /* Fault ID found, increment count */
          RstM_FaultResetCount[flCountIndex].resetCount++;
          flFaultFound = TRUE;
          break;
        }
      }

      /* If fault ID not found, add new entry */
      if (flFaultFound == FALSE)
      {
        for (flCountIndex = 0u; flCountIndex < RSTM_LAST_RESET_HISTORY_NUM; flCountIndex++)
        {
          if (RstM_FaultResetCount[flCountIndex].isValid == FALSE)
          {
            RstM_FaultResetCount[flCountIndex].faultId = flCurrentFaultId;
            RstM_FaultResetCount[flCountIndex].resetCount = 1u;
            RstM_FaultResetCount[flCountIndex].isValid = TRUE;
            break;
          }
        }
      }
    }
  }
}

/*============================================================================
**
** Function Name    :   RstM_GetConfigIndexById
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
static Std_ReturnType RstM_GetConfigIndexById(uint16 FaultId, uint8 *FaultConfigIndexPtr)
{
  Std_ReturnType flReturnVal = E_NOT_OK;
  uint8 flIndex = 0;

  *FaultConfigIndexPtr = 0xFFu; /* Initialize to invalid index */
  for (flIndex = 0; flIndex < RSTM_MAX_NUM_FAULTS; flIndex++)
  {
    if (RstM_FaultConfig[flIndex].FaultId == FaultId)
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
** Function Name    :   RstM_StageOsArmDump
**
** Visibility       :   Non-Static
**
** Description      :   Stages an OS/ARM dump with the given fault ID.
**                       The fault ID is stored in the first two bytes of
**                       the dump buffer, followed by up to
**                       (RSTM_MAX_DUMP_SIZE - 2) bytes of the provided
**                       dump data. If the provided dump length exceeds
**                       the maximum allowed size, the data is truncated.
**
** Invocation       :   Internal (called by Fault Manager or reset handling logic)
**
** Inputs           :   fid     - Fault ID to be staged in the dump
**                       Dump    - Pointer to dump data buffer
**                       DumpLen - Length of the dump data in bytes
**
** Outputs          :   E_OK      - Data copied successfully without truncation
**                       E_NOT_OK  - Null pointer or data truncated to fit buffer
**
** Critical Section :   No
**
**==========================================================================*/

Std_ReturnType RstM_StageOsArmDump(eFltM_FaultIdType fid, const void *Dump, uint16 DumpLen)
{
  Std_ReturnType ret = E_OK;
  const uint16 headerSize = 2U;
#if (RSTM_MAX_DUMP_SIZE < 2)
#error "RSTM_MAX_DUMP_SIZE must be >= 2"
#endif
  const uint16 maxPayload = (uint16)(RSTM_MAX_DUMP_SIZE - headerSize);
  uint16 copyLen = 0U;

  /* Null pointer only an error if caller asked us to copy something */
  if ((Dump == NULL) && (DumpLen > 0U))
  {
    ret = E_NOT_OK;
    RstM_Det_ReportError(RSTM_STAGEOSARMDUMP, RSTM_NULL_POINTER_ERROR);
    DumpLen = 0U; /* treat as empty payload */
  }

  /* Truncate if needed */
  if (DumpLen > maxPayload)
  {
    copyLen = maxPayload;
  }
  else
  {
    copyLen = DumpLen;
  }

  /* Keep the explicit field update you already had */
  RstM_LastOsArmDump.faultId = fid;
  /* Write fid into the first two bytes of the Dump buffer (little-endian by default) */
  RstM_LastOsArmDump.Dump[0] = (uint8)((((uint16)fid) >> RSTM_BYTE_BIT_SHIFT) & (uint8)0xFFU);
  RstM_LastOsArmDump.Dump[1] = (uint8)(((uint16)fid) & 0xFFU);

  /* Append payload right after the 2-byte FaultID header */
  if (copyLen > 0U)
  {
    (void)MemLib_MemCpy(&RstM_LastOsArmDump.Dump[headerSize], Dump, copyLen);
    RstM_LastOsArmDump.DumpSize = (uint8)(headerSize + copyLen);
  }

  RstM_LastOsArmDump.isValid = TRUE;
  return ret;
}

/*============================================================================
** Function Name    :   RstM_GetEarlyResetCount
**
** Visibility       :   Public
**
** Description      :   Returns reset count for FaultId even before normal
**                      reset-history initialization completes. If normal
**                      reset history is already valid, it reuses the standard
**                      RstM_GetResetCount(); otherwise it reads through DltExt
**                      inline path.
**
** Invocation       :   FltM
**
** Inputs           :   FaultId - Fault ID
**                      Count   - Pointer to returned count
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**==========================================================================*/
Std_ReturnType RstM_GetEarlyResetCount(eFltM_FaultIdType FaultId, uint8 *Count)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if ((Count != NULL_PTR) && (FaultId != 0U))
  {
    if (RstM_ResetHistoryDataValid == TRUE)
    {
      flRetVal = RstM_GetResetCount(FaultId, Count);
    }
    else
    {
      flRetVal = DltExt_PreInitGetResetCount((uint16)FaultId, Count);
    }
  }
  else
  {
    RstM_Det_ReportError(RSTM_GETRESETCOUNT, RSTM_NULL_POINTER_ERROR);
  }

  return flRetVal;
}

#define RSTM_SEC_CODE_STOP
#define RSTM_CORE_CONST_SEC_END
#define RSTM_CORE_DATA_SEC_END
#define RSTM_CORE_BSS_SEC_END

#if defined(RSTM_SEC_CODE_STOP)
#endif

#include "MemMap.h"
#endif /* RSTM_C */
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
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Add early reset-history and global reset-storm counting
                    support while preserving the existing reset request path.
-----------------------------------------------------------------------------*/

/******************************* End of File *********************************/
