/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
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
 *  File Name         :  DltExt.c                                             *
 *  Module Short Name :  DltExt                                               *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace Extension                              *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS Multi                                              *
 * Target Hardware  :  Platform Independent                                   *
 *                                                                            *
 ******************************************************************************/
#ifndef DLTEXT_C
#define DLTEXT_C
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "DltExt.h"
#include "Dlt.h"
#include "DltExt_Ipc.h"
#include "Ea_Cfg.h"
#include "EcuMExt.h"
#include "NvM.h"
#include "NvMExt.h"
#include "Rte_DltExt.h"
#include "Rte_Dlt_Type.h"
#include "Spi.h"
#include "Std_Types.h"

#if (DLTEXT_UART_PRINT == STD_ON)
#include "SciDrv.h"
#include "SciDrv_Types.h"
#include <stdio.h> // for snprintf
#include <string.h> // for strlen
#endif

#if ((DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON) && (DLT_DM_TO_GIP_INTERFACE == STD_ON))
#include "Cdd_Ipc.h"
#include "Cdd_IpcCfg.h"
#endif

#if ((DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON) && (DLT_HSM_TO_GIP_INTERFACE == STD_ON))
#include "vDLT_HSM.h"
#endif

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#define FAULT_CODE_MASK (uint16)(0xFF00u)

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
#define DLTEXT_KPITYPECODE (uint16)(0xFD00u)
#endif

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
#define MAX_UCL_MSG_COUNT_VALUE (uint16)(0xFFFFu)
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
#define LOG_EVENT (uint8)(0u)
#define NO_EVENT_PRESENT (uint8)(2u)
#endif

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
#define KPI_EVENT (uint8)(1u)
#define DLTEXT_MAX_KPIBUF_LEN (uint8)(DLTEXT_KPI1_SIZE + DLTEXT_KPI2_SIZE + DLTEXT_KPI3_SIZE + DLTEXT_KPI4_SIZE)
#define DLTEXT_KPITYPE_NORMAL 0x00U
#define DLTEXT_KPITYPE_TIMEDIFF 0x01u
#define DLTEXT_KPITYPE_METRICS 0x02u
#endif
#if (HARDWARE_FAULTS_EN == STD_ON)
#define NUM_HW_FAULTS (uint8)(27u)
const ResetTypeTable ResetReasonFault[NUM_HW_FAULTS] = {
  /*	Index 1	*/ { MCU_RESET_UNDEFINED, 0xFC01 },
  /*	Index 2	*/ { MCU_POWER_ON_RESET, 0xFC02 },

#if (DLTEXT_PLATFORM_IMX8 == STD_ON)
  /*	Index 3	*/ { MCU_JTAG_RESET, 0xFC02 },
  /*	Index 4	*/ { MCU_SOFTWARE_RESET, 0xFC03 },
  /*	Index 5	*/ { MCU_WATCHDOG_RESET, 0xFC04 },
  /*	Index 6	*/ { MCU_LOCKUP_RESET, 0xFC05 },
  /*	Index 7	*/ { MCU_SNVS_RESET, 0xFC06 },
  /*	Index 8	*/ { MCU_TEMP_RESET, 0xFC07 },
  /*	Index 9	*/ { MCU_MSI_RESET, 0xFC08 },
  /*	Index 10*/ { MCU_UECC_RESET, 0xFC09 },
  /*	Index 11*/ { MCU_SCFW_WDOG_RESET, 0xFC0A },
  /*	Index 12*/ { MCU_ROM_WDOG_RESET, 0xFC0B },
  /*	Index 13*/ { MCU_SECO_RESET, 0xFC0C },
  /*	Index 14*/ { MCU_SCFW_FAULT_RESET, 0xFC0D }
#elif (DLTEXT_PLATFORM_TRAVEO2 == STD_ON)
  /*	Index 3	*/ { MCU_WATCHDOG_RESET, 0xFC09 },
  /*	Index 4	*/ { MCU_ACT_FAULT_RESET, 0xFC08 },
  /*	Index 5	*/ { MCU_DPSLP_FAULT_RESET, 0xFC08 },
  /*	Index 6	*/ { MCU_TEST_DEBUG_RESET, 0xFC07 },
  /*	Index 7	*/ { MCU_SW_RESET, 0 },
  /*	Index 8	*/ { MCU_MCWDT0_RESET, 0xFC0A },
  /*	Index 9	*/ { MCU_MCWDT1_RESET, 0xFC0A },
  /*	Index 10 */ { MCU_MCWDT2_RESET, 0xFC0A },
  /*	Index 11 */ { MCU_MCWDT3_RESET, 0xFC0A },
  /*	Index 12 */ { MCU_XRES_RESET, 0xFC02 },
  /*	Index 13 */ { MCU_BOD_VDDD_RESET, 0xFC03 },
  /*	Index 14 */ { MCU_BOD_VDDA_RESET, 0xFC03 },
  /*	Index 15 */ { MCU_BOD_VCCD_RESET, 0xFC03 },
  /*	Index 16 */ { MCU_OVD_VDDD_RESET, 0xFC04 },
  /*	Index 17 */ { MCU_OVD_VDDA_RESET, 0xFC04 },
  /*	Index 18 */ { MCU_OVD_VCCD_RESET, 0xFC04 },
  /*	Index 19 */ { MCU_OCD_ACTIVE_REGULATOR_RESET, 0xFC05 },
  /*	Index 20 */ { MCU_OCD_DEEPSLEEP_REGULATOR_RESET, 0xFC05 },
  /*	Index 21 */ { MCU_STRUCTURAL_XRES_RESET, 0xFC02 },
  /*	Index 22 */ { MCU_CSV_HF_RESET, 0xFC0B },
  /*	Index 23 */ { MCU_CSV_REF_RESET, 0xFC0C },
  /*	Index 24 */ { MCU_WAKEUP_RESET, 0 },
  /*	Index 25 */ { MCU_REGHC_OCD_RESET, 0 },
  /*	Index 26 */ { MCU_REGHC_PMIC_RESET, 0 },
  /*	Index 27 */ { MCU_PXRES_RESET, 0xFC02 }
#endif
};

#endif /* HARDWARE_FAULTS_EN */

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/* Buffer declaration for log read and write*/
static ADDR_ALIGN uint8 DLT_WriteAddressBuffer[DLT_ADDR_BUFFER_LENGTH];
static ADDR_ALIGN uint8 DLT_RxBuff[DLT_TX_RX_BUFFER_LENGTH];

extern void Fls_MainFunction(void);
// static volatile uint16 vStoredResetCode = 0; ///< variable to store the reset
// code>

static tDltExt_AppLogDataBuffer DltExt_AppLogDataBuffer = { 0U };
static tDltExt_ResetLogDataBuffer DltExt_ResetLogDataBuffer = { 0U };
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
static uint8 DltExtWdgResetCount = 0;
#endif

#if (DLTEXT_USE_SNVM == STD_ON)
static tDltExt_CriticalErrBuffer DltExt_CriticalErrBuffer;
#endif

#if (BURAM_ENABLE == STD_ON) /* If BuRam is Enabled*/
#pragma ghs section bss = ".Sram_DLT"
static DltExt_RstInfoType DltExt_Internal_RstInfo = { 0 };
#pragma ghs section bss = default
#else
static DltExt_RstInfoType DltExt_Internal_RstInfo = { 0 };
#endif

static tDltExt_AppinfoData DltExt_LocalAppinfo = { 0 };

/* Raw reset info is cached in local RAM for update/write flows. */
static boolean DltExt_ResetInfoLoaded = FALSE;
/* Reset history has been fully prepared for startup consumers/replay. */
static boolean DltExt_ResetInfoReady = FALSE;

/* 0 = no reset to send
 * 1 = reset history loaded, must call Dlt_SendLogMessage() once
 * 2 = reset DLT frame sent to shared memory + UCL requested, wait for ACK
 */
#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
static uint8 DltExt_ResetPending = 0U;
#endif

#if (DLTEXT_UART_PRINT == STD_ON)
static boolean DltExt_ResetInfoPrinted = FALSE;
#endif

#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
/*misra_c_2012_rule_8_4_violation:	Object definition does not have a
 * visible prototype - to be deviated*/
tDltExt_CounterInfo vCounterData;
static tDltExt_CounterInfo vCounterDataLocal = { 0 };
static boolean vCounterDataLocal_Flag = FALSE;
#endif /* DLT_FAULTCOUNTER_ENABLE */

static boolean bDltExt_InitCompleted_Status = FALSE;

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
static boolean DltExt_LocalNvMBuffer_Flag = FALSE;
static uint8 u8DltExt_LogTriggered_NvMNotInit = 0u;
// static uint8 DltExt_MainStorageWrite_Flag = FALSE;
static uint32 DltExt_TmStartTime = 0u;
static uint32 DltExt_OnException_Counter = 0u;
static boolean DltExt_AppInfoWriteInProgress = FALSE;
static boolean DltExt_AppInfoWritePending = FALSE;
#endif

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
static tDltExt_UclDataBuffer
    DltExt_UclDataBuffer[DLTEXT_ADDITIONAL_RESET_INFO_SIZE] = { 0 };
static uint8 G_LocalBuff_TailPtr = 0u; /*Tail index of Error code cyclic buffer*/
static uint8 G_LocalBuff_headPtr = 0u; /*Head index of Error code cyclic buffer*/
static uint8 G_Cfg_Fault_index = 0u; /*Configuration index of App Error Category*/
static uint16 KPI_Message_Len = 0U;
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
static tDltExt_KpiCyclicBuffer DltExt_KpiCyclicBuffer[DLTEXT_MAX_KPIBUF_LEN] = { 0 };
static uint32 FirstKPITimestamp[DLTEXT_NUM_KPI] = { 0 };
static uint32 LastKPITimestamp[DLTEXT_NUM_KPI] = { 0 };
static uint8 kpi_localBuff_headIdx[DLTEXT_NUM_KPI] = { 0 };
static uint8 kpi_localBuff_startIdx[DLTEXT_NUM_KPI] = { 0 };
static uint8 KPI_Cfg_idx = 0u;
#endif

#if (HARDWARE_FAULTS_EN == STD_ON)
Mcu_ResetType HwFaultCode;
Dlt_MessageLogInfoType Dlt_log_info = {
  .argCount = 2U,
  .logLevel = HW_FAULT_LOG_LEVEL,
  .options = 0U,
  .appId = { 'D', 'L', 'T', 'X' },
  .contextId = { 'H', 'W', 'F', 'T' },
};
static uint8 Dlt_logData[8] = { 0xFC, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 };
static boolean bStartFlag = TRUE; /* flag to check Reset reasons */
#endif /* HARDWARE_FAULTS_EN */

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
static uint16 DltExt_Ucl_MessageCount = MAX_MSG_COUNT_RESET; // initialize the counter to zero
static SLogDataBasedOnLogEvent DltExt_LogDataBasedOnLogEventTx = { 0 }; /*Local buffer initialization for transmission through Ucl*/
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */
/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

//----------------------------------------------------------------------------------------------------------------------
/// Local function prototypes
//----------------------------------------------------------------------------------------------------------------------
#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
static void SetCounterToDefault(void);
static Std_ReturnType DltExt_UpdateFaultCounter(uint16 eErrorCode);
static void DltExt_UpdateCounterMemoryToNvm(void);
static Std_ReturnType DltExt_GetCounterDatafromNVM(void);
static boolean DltExt_EvalStoredResetCode(void);
#endif /* DLT_FAULTCOUNTER_ENABLE */

#if (DLTEXT_UART_PRINT == STD_ON)
static uint8 DltExt_Uart_TxBuf[DLT_UART_TXBUF_SIZE];
static volatile boolean DltExt_Uart_Busy = FALSE;
static boolean DltExt_Uart_Initialized = FALSE;
static void DltExt_PrintOsDumpShort(const uint8 *DltExt_pDump, uint16 DltExt_DumpLen);
static void DltExt_PrintResetLog(const tDltExt_ResetLogDataBuffer *DltExt_pLog);
static uint32 DltExt_ReadU32LE(const uint8 *p, uint16 off);
static Std_ReturnType DltExt_Uart_Init(void);
#endif

void DltExt_ResetSWHang(void);
void DltExt_RstMPushOsArmDump(const uint8 *DataPtr, uint8 Length);
void DltExt_PmicCddWdgEarlyWarning(uint8 *DataPtr, uint8 Length);

static uint16 DltExt_BuildResetReplayFrame(uint8 *dst, uint16 dstSize, const uint8 *stdHdr, uint16 stdHdrLen);
static void DltExt_ReportResetHistoryAtStartup(void);
static boolean DltExt_IsResetHistoryLog(const uint8 *payLoadHeader, uint16 payLoadHeaderLength);
static uint16 DltExt_BuildVerboseFrame(uint8 *dst, uint16 dstSize, const uint8 *payLoadHeader, uint16 payLoadHeaderLen, const uint8 *payLoad, uint16 payLoadLen);
static void DltExt_InlineReadResetInfo(uint16 NvBlockId_u16);
static Std_ReturnType DltExt_InlineReadResetInfoInternal(uint16 NvBlockId_u16);
static void SetLogsToDefault(void);
static Std_ReturnType DltExt_WritetoNVMBuffer(uint16 eErrorCode, uint32 DltExt_Timestamp, const uint8 *pBuffer, uint16 message_len);
static Dlt_ReturnType DltExt_InlineWritetoNvMemory(uint16 eErrorCode, uint32 DltExt_Timestamp, const uint8 *pBuffer, uint16 message_len);
static Dlt_ReturnType DltExt_Report(uint16 eErrorCode, uint32 DltExt_Timestamp, const uint8 *pBuffer, Dlt_MessageLogLevelType LogLevel, uint16 message_length);
static void DltExt_MemInit(void);
static Dlt_ReturnType DltExt_MessageFiltering(uint8 falutCategory);
static Std_ReturnType DltExt_AdjustHistoryLogForPOR(void);
static void DltExt_CopyResetInfoFromNvmMirror(void);
static void DltExt_CopyResetInfoToNvmMirror(void);
static void DltExt_ClearOsDumpAfterConsume(void);
static void DltExt_UpdateLogMemoryToNvm(void);

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
static Dlt_ReturnType DltExt_KpiBufferHandling(uint16 KPIMessageID, uint32 KPITimestamp, uint8 KPIVarible, uint8 Fault_status, const uint8 *KPISnapshot, uint16 KPI_Msg_Length);
static uint8 Search_KPI_Cfg(uint16 eErrorCode);
#endif

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
static Std_ReturnType DltExt_GetLogDatafromNVM(void);
static Std_ReturnType DltExt_GetResetDatafromNVM(void);
static void DltExt_BlockWriteOnException(uint16 NvBlockId_u16);
static Std_ReturnType DltExt_IsTimerElapsed(uint32 ElapseTime);
static void DltExt_StartTimer(void);
static void DltExt_StoreAppInfoToLocalBuffer(boolean IsNvMInitCompleted);
static Std_ReturnType DltExt_TryTriggerAppInfoNvMWrite(void);
#endif /* DLTEXT_CFG_NVM_BLOCKS_PRESENT */

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
static Std_ReturnType DltExt_UclMessageHandling(uint16 DltextMessage_Id, uint32 DltExtTimestamp, const uint8 *pBuffer);
static uint8 DltExt_Search_Fault_category(uint8 FaultCategory);
static void DltExt_MemCpy(uint8 *DPtr, uint32 Val, uint8 length);
static void DltExt_Ucl_MessageCounter(void);
static void DltExt_UclTransmission(void);
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

extern Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, uint8 *logData, uint16 logDataLength);

/*****************************************************************************
 *                                 Exported Functions                          *
 ******************************************************************************/

/*============================================================================
**
** Function Name    :   DltExt_Init
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void DltExt_Init(void)
{
  /*static tDltExt_LocalConfigDataType DltExt_LocalConfigData;
  DltExt_LocalConfigData.No_of_CyclicBuffer = DltExt_Config.NumCyclicBuffers;
  DltExt_LocalConfigData.Buffer_Length = DltExt_Config.BufferLength;
  DltExt_LocalConfigData.FaultCounter_EN = DltExt_Config.FaultCounterEN;*/

  bDltExt_InitCompleted_Status = FALSE;
  DltExt_ResetInfoLoaded = FALSE;
  DltExt_ResetInfoReady = FALSE;
  #if (DLTEXT_UART_PRINT == STD_ON)
  DltExt_ResetInfoPrinted = FALSE;
  #endif
  #if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  DltExt_ResetPending = 0U;
  #endif
  // FilterConfig = DLTEXT_FILER_CATEGORIES; /* Filtering Configuration */

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  DltExt_LocalNvMBuffer_Flag = FALSE;
  u8DltExt_LogTriggered_NvMNotInit = 0u;
  DltExt_OnException_Counter = 0u;
  DltExt_AppInfoWriteInProgress = FALSE;
  DltExt_AppInfoWritePending = FALSE;
#endif

#if (DLTEXT_USE_SNVM == STD_ON)
  DltExt_CriticalErrBuffer.magicFlag = DLTEXT_MAGIC_FLAG_RESET_VAL;
#endif

/* Intialize the memory pointer to zero and buffer to 1*/
#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  DltExt_Ipc_Init();
#endif

  (void)DltExt_MemInit();

#if (DLTEXT_UART_PRINT == STD_ON)
  (void)DltExt_Uart_Init();
#endif
}

/*============================================================================
**
** Function Name    :   DltExt_DeInit
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

void DltExt_DeInit(void)
{
  /*static tDltExt_LocalConfigDataType DltExt_LocalConfigData;
  DltExt_LocalConfigData.No_of_CyclicBuffer = 0;
  DltExt_LocalConfigData.Buffer_Length = 0;
  DltExt_LocalConfigData.FaultCounter_EN = 0;*/

  bDltExt_InitCompleted_Status = FALSE;
  DltExt_ResetInfoLoaded = FALSE;
  DltExt_ResetInfoReady = FALSE;
  #if (DLTEXT_UART_PRINT == STD_ON)
  DltExt_ResetInfoPrinted = FALSE;
  #endif
  #if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  DltExt_ResetPending = 0U;
  #endif

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  DltExt_LocalNvMBuffer_Flag = FALSE;
  u8DltExt_LogTriggered_NvMNotInit = 0u;
  DltExt_AppInfoWriteInProgress = FALSE;
  DltExt_AppInfoWritePending = FALSE;
#endif

#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  DltExt_Ipc_DeInit();
#endif
}

/*============================================================================
**
** Function Name    :   DltExt_MainFunction
**
** Visibility       :   Public
**
** Description      :   The service represents the interface to be used by basic
**                      software modules or by software components to trace
* parameters.
**
** Invocation       :   OS will invoke this function with 100ms periodicity
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

void DltExt_MainFunction(void)
{
#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  DltExt_Ipc_MainFunction();
#endif

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  boolean bIsNVMJobCompleted = TRUE;
  uint8 idx;
  Std_ReturnType retVal = E_NOT_OK;
  static uint8 flResetCountPrinted = 0u;

  if (FALSE == bDltExt_InitCompleted_Status)
  {
    /* Is application log information ready in mirror RAM?*/
    if (TRUE == DltExt_AppInfoGetNvMReadyStatus())
    {
      /*Get the already stored NVM data to local buffers*/
      (void)DltExt_GetLogDatafromNVM();
#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
      (void)DltExt_GetCounterDatafromNVM();
#endif
      /*Set the start flag to FALSE*/
      bDltExt_InitCompleted_Status = TRUE;
    }
  }

#if (DLTEXT_UART_PRINT == STD_ON)
  if ((flResetCountPrinted == 0u) && (DltExt_ResetInfoReady == TRUE))
  {
    if (E_OK == (DltExt_Uart_Printf("PMIC WDG RESET Count %lu \r\n",
                                    DltExtWdgResetCount)))
    {
      flResetCountPrinted = 1u;
    }
  }
#endif

#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)

  if ((DltExt_ResetPending == 1U) &&
      (DltExt_ResetInfoReady == TRUE))
  {
    /* This creates a DLT header in Dlt.c and triggers DltExt_SendLogMessage()
     * which routes the frame to ResetInfo_SharedDumpBuffer + UCL request.
     */
    DltExt_ReportResetHistoryAtStartup();
    return;
  }
#endif

  /* To write AppInfo Block Run Time */
  if (TRUE == bDltExt_InitCompleted_Status)
  {
    /* Is the last NvM job completed?*/
    bIsNVMJobCompleted = DltExt_isNVMJobCompleted_Data();

    /* Clear software latch only after NvM callback/status confirms completion */
    if ((TRUE == DltExt_AppInfoWriteInProgress) &&
        (TRUE == bIsNVMJobCompleted))
    {
      DltExt_AppInfoWriteInProgress = FALSE;
    }

    /* If buffered data exists, flush only when no AppInfo write is already
     * outstanding. */
    if (((DltExt_LocalNvMBuffer_Flag == TRUE) ||
         (DltExt_AppInfoWritePending == TRUE)) &&
        (FALSE == DltExt_AppInfoWriteInProgress))
    {
      /* If there was any update before NvM is ready, update that to local RAM
       * first*/
      if ((0u != u8DltExt_LogTriggered_NvMNotInit) &&
          (DLTEXT_LAST_APP_HISTORY_NUM >= u8DltExt_LogTriggered_NvMNotInit))
      {
        for (idx = (DLTEXT_LAST_APP_HISTORY_NUM - 1u);
             idx >= u8DltExt_LogTriggered_NvMNotInit;
             idx--)
        {
          MemLib_MemCpy(&DltExt_AppLogDataBuffer.code[idx],
                        &DltExt_AppLogDataBuffer.code[idx - 1u],
                        DLTEXT_ADDITIONAL_APPLOG_INFO_SIZE);
        }

        /* if previous NvM job is not completed store it in a local NvM buffer
         */
        /*misra_c_2012_rule_10_6_violation:	Assigning composite expression
         * "u8DltExt_LogTriggered_NvMNotInit * 11" of width 8 to a target of
         * width 32 - to be deviated*/
        MemLib_MemCpy(&DltExt_AppLogDataBuffer,
                      &DltExt_LocalAppinfo.AppLogDataBuffer,
                      u8DltExt_LogTriggered_NvMNotInit *
                          DLTEXT_ADDITIONAL_APPLOG_INFO_SIZE);
        /* Clear the flag*/
        u8DltExt_LogTriggered_NvMNotInit = 0u;
      }
      else
      {
        /* Normal busy-write case: latest consolidated snapshot is already
         * available in local shadow buffer. Restore it before deferred flush. */
        MemLib_MemCpy(&DltExt_AppLogDataBuffer,
                      &DltExt_LocalAppinfo,
                      DLTEXT_APPLOGDATA_SIZE);
      }

      retVal = DltExt_TryTriggerAppInfoNvMWrite();

      if (retVal == E_OK)
      {
        DltExt_LocalNvMBuffer_Flag = FALSE;
        DltExt_AppInfoWritePending = FALSE;
      }
      else
      {
        DltExt_LocalNvMBuffer_Flag = TRUE;
        DltExt_AppInfoWritePending = TRUE;
      }
    }

#if (DLTEXT_USE_SNVM == STD_ON)
    if ((bIsNVMJobCompleted == TRUE) &&
        (DltExt_CriticalErrBuffer.magicFlag == DLTEXT_MAGIC_FLAG_VAL) &&
        (DltExt_OnException_Counter == 0u))
    {

      for (idx = (DLTEXT_TOTAL_NUM_OF_RESET_HISTORY - 1u); idx > 0u; idx--)
      {
        // use meblib_cpy
        MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[idx],
                      &DltExt_ResetLogDataBuffer.code[idx - 1u],
                      DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
      }

      /* Clear Latest Index Data*/
      MemLib_MemSet(&DltExt_ResetLogDataBuffer.code[0][0], 0x00U, DLTEXT_ADDITIONAL_RESET_INFO_SIZE);

      /* Copy snvm Buffer criticalErrBuff to ResetLogDataBuffer*/
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[0][0],
                    &DltExt_CriticalErrBuffer.code,
                    DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer.unexpectedResetCode[0],
                    &DltExt_CriticalErrBuffer.code,
                    2u);
      DltExt_ResetLogDataBuffer.unexpectedResetCode[2] = 1u;

      /*Copy to vNvMData Buffer for NVM write to main storage*/
      MemLib_MemCpy(&DltExt_Internal_RstInfo.RstHistory[0],
                    &DltExt_ResetLogDataBuffer,
                    DLTEXT_RESET_HISTORY_MAX_SIZE);
      DltExt_MainStorageWrite_Flag = TRUE;
      DltExt_CriticalErrBuffer.magicFlag = DLTEXT_MAGIC_FLAG_RESET_VAL;

      MemLib_MemSet(&DltExt_CriticalErrBuffer.code[0], 0x00u, (uint32)sizeof(DltExt_CriticalErrBuffer.code));

      /* SNvm WRITE */
      (void)DLTEXT_SET_DLT_FETAL_STORAGE((uint8 *)&DltExt_CriticalErrBuffer);
    }

    if (DltExt_MainStorageWrite_Flag == TRUE)
    {
      DLTEXT_SET_DLT_MAIN_STORAGE((uint8 *)&DltExt_Internal_RstInfo);
      DltExt_MainStorageWrite_Flag = FALSE;
    }

#endif

#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
    bIsNVMJobCompleted = DltExt_isNVMJobCompleted_Counter();

    if ((vCounterDataLocal_Flag == TRUE) && (bIsNVMJobCompleted == TRUE))
    {
      /*misra_c_2012_rule_12_3_violation: These expressions uses the comma
       * operator - To Be Deviated*/
      DltExt_MemAbsSet_Set_NVM_HM_Data_Generic_Reset_Counter(
          vCounterDataLocal.DltExt_Generic_Reset_Counter);
      DltExt_MemAbsSet_Set_NVM_HM_Data_Illegal_Memory_Address_Reset_Counter(
          vCounterDataLocal.DltExt_Illegal_Memory_Address_Reset_Counter);
      DltExt_MemAbsSet_Set_NVM_HM_Stack_Overflow_Reset_Counter(
          vCounterDataLocal.DltExt_StackOverflowReset_Counter);
      DltExt_MemAbsSet_Set_NVM_HM_Illegal_Opcode_Reset_Counter(
          vCounterDataLocal.DltExt_IllegalOpCodeReset_Counter);
      DltExt_MemAbsSet_Set_NVM_HM_Power_ON_Reset_Counter(
          vCounterDataLocal.DltExt_PowerON_Counter);
      DltExt_MemAbsSet_Set_NVM_HM_Watchdog_timer_Reset_Counter(
          vCounterDataLocal.DltExt_WatchdogTimerReset_Counter);
      /*once local data is written to NvM set the flag to FALSE*/

      vCounterDataLocal_Flag = FALSE;
    }
#endif /* DLT_FAULTCOUNTER_ENABLE */
  }
#endif

#if (HARDWARE_FAULTS_EN == STD_ON)
  if (bStartFlag)
  { /* To log the reset related faults */
    uint8 index;
    HwFaultCode = DLTEXT_GET_RESET_REASON();
    for (index = 0u; index < NUM_HW_FAULTS; index++)
    {
      if (ResetReasonFault[index].ResetCode == HwFaultCode)
      {
        Dlt_logData[0] = (uint8)(ResetReasonFault[index].Dlt_FaultCode >> 8);
        Dlt_logData[1] = (uint8)ResetReasonFault[index].Dlt_FaultCode;
        (void)Dlt_SendLogMessage(0u, &Dlt_log_info, &Dlt_logData[0], 8u);
        bStartFlag = FALSE;
      }
    }
  }
#endif /* HARDWARE_FAULTS_EN */

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
  /*Ucl Transmission*/
  (void)DltExt_UclTransmission();
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to set counters and latest reset to default state.
///
/// @param void
///
/// @return void
//----------------------------------------------------------------------------------------------------------------------

static void DltExt_MemInit(void)
{
#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  uint8 Start_Ptr_Idx;
  uint8 Kpi_Start_Ptr;
  uint8 Kpi_Loop_x;
  uint8 kpi_timestamp_x;
#endif
  /*Set counters and logs to default together*/
  SetLogsToDefault();
#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
  SetCounterToDefault();
#endif

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  MemLib_MemSet(&DltExt_KpiCyclicBuffer, 0x00u, (uint32)sizeof(DltExt_KpiCyclicBuffer));
#endif

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
  MemLib_MemSet(&DltExt_UclDataBuffer, 0x00u, (uint32)sizeof(DltExt_UclDataBuffer));
  MemLib_MemSet(&DltExt_LogDataBasedOnLogEventTx, 0x00u, (uint32)sizeof(DltExt_LogDataBasedOnLogEventTx));
  DltExt_Ucl_MessageCount = MAX_MSG_COUNT_RESET; // initialize the counter to zero

  G_LocalBuff_TailPtr = 0u;
  G_LocalBuff_headPtr = 0u;
  G_Cfg_Fault_index = 0u;
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  KPI_Cfg_idx = 0u;

  for (kpi_timestamp_x = 0u; kpi_timestamp_x < DLTEXT_NUM_KPI; kpi_timestamp_x++)
  {
    FirstKPITimestamp[kpi_timestamp_x] = 0u;
    LastKPITimestamp[kpi_timestamp_x] = 0u;
  }

  kpi_localBuff_headIdx[0] = 0u;
  kpi_localBuff_startIdx[0] = 0u;

  for (Kpi_Loop_x = 1u; Kpi_Loop_x < DLTEXT_NUM_KPI; Kpi_Loop_x++)
  {
    Kpi_Start_Ptr = 0u;
    for (Start_Ptr_Idx = 0u; Start_Ptr_Idx <= (Kpi_Loop_x - 1u); Start_Ptr_Idx++)
    {
      Kpi_Start_Ptr = (uint8)(Kpi_Start_Ptr + vKPIData_Cfg[Start_Ptr_Idx].Kpi_Buffer_Size);
    }
    kpi_localBuff_startIdx[Kpi_Loop_x] = Kpi_Start_Ptr;
    kpi_localBuff_headIdx[Kpi_Loop_x] = Kpi_Start_Ptr;
  }
#endif
}

static void SetLogsToDefault(void)
{
  /*Reset local fault code buffers*/
  MemLib_MemSet(&DltExt_ResetLogDataBuffer, 0x00u, (uint32)sizeof(DltExt_ResetLogDataBuffer));
  MemLib_MemSet(&DltExt_AppLogDataBuffer, 0x00u, (uint32)sizeof(DltExt_AppLogDataBuffer));

#if (BURAM_ENABLE == STD_OFF)
  MemLib_MemSet(&DltExt_Internal_RstInfo, 0x00u, (uint32)sizeof(DltExt_Internal_RstInfo));
#endif

  MemLib_MemSet(&DltExt_LocalAppinfo, 0x00u, (uint32)sizeof(DltExt_LocalAppinfo));
}

#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to set all the counters to default state.
///
/// @param void
///
/// @return void
//----------------------------------------------------------------------------------------------------------------------

static void SetCounterToDefault(void)
{
  /*Reset local counter buffers*/
  vCounterData.DltExt_Generic_Reset_Counter = 0; /// set Generic Reset Counter to Default
  vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter = 0; /// set Illegal Memory Address Counter to Default
  vCounterData.DltExt_StackOverflowReset_Counter = 0; /// set Stack Overflow Reset Counter to Default
  vCounterData.DltExt_IllegalOpCodeReset_Counter = 0; /// set Illegal Op-Code Reset Counter to Default
  vCounterData.DltExt_PowerON_Counter = 0; /// set Power On Counter to Default
  vCounterData.DltExt_WatchdogTimerReset_Counter = 0; /// set Watchdog Timer Reset Counter to Default
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to read the stored counter data from NVM.
///
/// @param void
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_GetCounterDatafromNVM(void)
{
  Std_ReturnType uReturn = E_NOT_OK;
  boolean bIsRstCodeAvailable = FALSE;
  /*Read stored counter data from NVM*/
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Data_Generic_Reset_Counter((uint8 *)&vCounterData.DltExt_Generic_Reset_Counter);
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Data_Illegal_Memory_Address_Reset_Counter((uint8 *)&vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter);
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Stack_Overflow_Reset_Counter((uint8 *)&vCounterData.DltExt_StackOverflowReset_Counter);
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Illegal_Opcode_Reset_Counter((uint8 *)&vCounterData.DltExt_IllegalOpCodeReset_Counter);
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Power_ON_Reset_Counter((uint8 *)&vCounterData.DltExt_PowerON_Counter);
  uReturn = DltExt_MemAbsGet_Get_NVM_HM_Watchdog_timer_Reset_Counter(
      (uint8 *)&vCounterData.DltExt_WatchdogTimerReset_Counter);
  if (DltExt_ResetLogDataBuffer.unexpectedResetCode[2] == 1u) // misra
  {
    /* Save reset code and auxiliary data in local buffers */
    vStoredResetCode = DltExt_ResetLogDataBuffer.unexpectedResetCode[1];
    vStoredResetCode = vStoredResetCode << 8;
    vStoredResetCode = (vStoredResetCode + (uint16)DltExt_ResetLogDataBuffer.unexpectedResetCode[0]);

    /* Clear unexpectedResetFlag, unexpectedResetReason and auxiliary data for
     * next cycle */
    DltExt_ResetLogDataBuffer.unexpectedResetCode[2] = 1u; // misra
    DltExt_ResetLogDataBuffer.unexpectedResetCode[0] = 0u;
    DltExt_ResetLogDataBuffer.unexpectedResetCode[1] = 0u;

    bIsRstCodeAvailable = DltExt_EvalStoredResetCode();
    /*If a valid stored reset code is available, store the reset code onto NVM
     * local buffer*/
    if (bIsRstCodeAvailable)
    {
      /* Cleared unexpectedResetFlag, unexpectedResetReason and auxiliary data
       * will be stored to NVM along with reset reasons */
      (void)DltExt_UpdateFaultCounter(vStoredResetCode);
      (void)DltExt_UpdateCounterMemoryToNvm();
      vStoredResetCode = RESET_CODE_DEFAULT;
    }
  }

  return uReturn;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to update the fault counter.
///
/// @param eErrorCode  -
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_UpdateFaultCounter(uint16 eErrorCode)
{
  Std_ReturnType DltExtRetVal = E_NOT_OK;
  uint8 head_idx = 0u;
  uint8 tail_idx = DLT_NUM_ERROR_CODE - 1u;
  uint8 mid_idx = 0u;

  static const tDltExt_ErrCodeCounterMap vCounterMap[DLT_NUM_ERROR_CODE] = {
    ///< Array to map the counters to fault codes>

    { DLT_DET_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_WDGM_ALIVE_SUPERVISION_FAILURE,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_FLS_TST_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_EARLY_WAKEUP, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_NMI_EVENT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_HARD_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_MEMMANAGE_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_BUS_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_USAGE_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_DEBUG_MONITOR, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_PENDING_SV, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_UNDEFINED_INSTRUCTION,
      &vCounterData.DltExt_IllegalOpCodeReset_Counter,
      NULL },
    { DLT_E_ARM_SUPERVISOR_CALL, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_ARM_PREFETCH_ABORT,
      &vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter,
      &vCounterData.DltExt_Generic_Reset_Counter },
    { DLT_E_ARM_DATA_ABORT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_NVM_E_HARDWARE, NULL, NULL },
    { DLT_NVM_E_INTEGRITY_FAILED, NULL, NULL },
    { DLT_E_NVM_REQ_FAILED, NULL, NULL },
    { DLT_E_NVM_WRONG_BLOCK_ID, NULL, NULL },
    { DLT_E_NVM_VERIFY_FAILED, NULL, NULL },
    { DLT_E_NVM_LOSS_OF_REDUNDANCY, NULL, NULL },
    { DLT_E_NVM_WRITE_FAILED, NULL, NULL },
    { DLT_E_NVM_READ_FAILED, NULL, NULL },
    { DLT_RESET_UNDEFINED, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_POWER_ON_RESET, &vCounterData.DltExt_PowerON_Counter, NULL },
#if (DLTEXT_PLATFORM_IMX8 == STD_ON)
    { DLT_JTAG_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_PARTITION_WDOG_RESET,
      &vCounterData.DltExt_WatchdogTimerReset_Counter,
      NULL },
    { DLT_SCU_LOCKUP_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_SNVS_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_TEMP_PANIC_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_MSI_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_ECC_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_SCFW_WDOG_RESET, &vCounterData.DltExt_WatchdogTimerReset_Counter, NULL },
    { DLT_SCU_ROM_WDOG_RESET, &vCounterData.DltExt_WatchdogTimerReset_Counter, NULL },
    { DLT_SECO_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_SCFW_FAULT_RESET, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
#elif (DLTEXT_PLATFORM_TRAVEO2 == STD_ON)
    { DLT_XRES_L, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_BOD, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_OVD, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_OCD, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_HIB_WAKEUP, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_CDBGRSTREQ, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_FAULT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_WDT, &vCounterData.DltExt_WatchdogTimerReset_Counter, NULL },
    { DLT_MCWDT, &vCounterData.DltExt_WatchdogTimerReset_Counter, NULL },
    { DLT_CSV_HF, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_CSV_REF, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
#endif
    { DLT_E_OS_ACCESS, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_CALLEVEL, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_ID, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_LIMIT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_NOFUNC, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_RESOURCE, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_STATE, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_VALUE, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SERVICEID, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_ILLEGAL_ADDRESS,
      &vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter,
      NULL },
    { DLT_E_OS_MISSINGEND, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_DISABLEDINT, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_STACKFAULT, &vCounterData.DltExt_StackOverflowReset_Counter, NULL },
    { DLT_E_OS_PROTECTION_MEMORY,
      &vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter,
      &vCounterData.DltExt_Generic_Reset_Counter },
    { DLT_E_OS_PROTECTION_TIME, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_PROTECTION_ARRIVAL, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_PROTECTION_LOCKED, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_PROTECTION_EXCEPTION,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_INTERFERENCE_DEADLOCK,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_NESTING_DEADLOCK, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SPINLOCK, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_CORE, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_PARAM_POINTER, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SHUTDOWN, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_API_ERROR, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_ASSERTION, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_DISABLED, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_NO_BARRIER_PARTICIPANT,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_SYS_NO_NTFSTACK, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_OVERFLOW, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_KILL_KERNEL_OBJ, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_NO_RESTARTTASK, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_CALL_NOT_ALLOWED,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_SYS_FUNCTION_UNAVAILABLE,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_SYS_PROTECTION_SYSCALL,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL },
    { DLT_E_OS_SYS_PROTECTION_IRQ, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_OVERLOAD, &vCounterData.DltExt_Generic_Reset_Counter, NULL },
    { DLT_E_OS_SYS_CROSS_CORE_REQUESTED,
      &vCounterData.DltExt_Generic_Reset_Counter,
      NULL }
  };

  /*Perform binary search to locate the correct fault code and update the
   * corresponding counters*/
  /*misra_c_2012_rule_15_4_violation:	The loop has more than one iteration
   * terminating break or goto statements - to be deviated*/
  while (head_idx <= tail_idx)
  {
    mid_idx = (head_idx + (uint8)((uint8)(tail_idx - head_idx) / 2u));

    /*Check if code is present at mid*/
    if ((DLT_NUM_ERROR_CODE > mid_idx) &&
        (vCounterMap[mid_idx].errorCode == eErrorCode))
    {
      /* Check if a valid first counter is available and is less than maximum
       * value */
      if ((vCounterMap[mid_idx].first_counter != NULL) &&
          ((*vCounterMap[mid_idx].first_counter) < DLTEXT_UINT8_MAX))
      {
        (*vCounterMap[mid_idx].first_counter)++;
      }

      /* Check if a valid second counter is available and is less than maximum
       * value */
      if ((vCounterMap[mid_idx].second_counter != NULL) &&
          ((*vCounterMap[mid_idx].second_counter) < DLTEXT_UINT8_MAX))
      {
        (*vCounterMap[mid_idx].second_counter)++;
      }

      DltExtRetVal = DLT_E_OK;
      break;
    }

    if (head_idx != tail_idx)
    {
      /*If greater, ignore left half*/
      if ((DLT_NUM_ERROR_CODE > mid_idx) &&
          ((vCounterMap[mid_idx].errorCode) < eErrorCode))
      {
        head_idx = mid_idx + 1u;
      }

      /*If smaller, ignore right half*/
      else
      {
        tail_idx = mid_idx - 1u;
      }
    }
    else
    {
      break;
    }
  }

#if (DLTEXT_USE_ERROR_CFG == STD_ON)
  if (DltExtRetVal == (uint8)E_NOT_OK)
  {

    head_idx = 0u;
    tail_idx = DLT_NUM_ERROR_CFG - 1u;
    /*misra_c_2012_rule_15_4_violation:	The loop has more than one iteration
     * terminating break or goto statements - to be deviated*/
    while (head_idx <= tail_idx)
    {
      mid_idx = (head_idx + (uint8)((uint8)(tail_idx - head_idx) / 2u));

      /*Check if code is present at mid*/
      if ((DLT_NUM_ERROR_CFG > mid_idx) &&
          (vCounterMap_Cfg[mid_idx].errorCode == eErrorCode))
      {
        /* Check if a valid first counter is available and is less than maximum
         * value */
        if ((vCounterMap_Cfg[mid_idx].first_counter != NULL) &&
            ((*vCounterMap_Cfg[mid_idx].first_counter) < DLTEXT_UINT8_MAX))
        {
          (*vCounterMap_Cfg[mid_idx].first_counter)++;
        }

        /* Check if a valid second counter is available and is less than maximum
         * value */
        if ((vCounterMap_Cfg[mid_idx].second_counter != NULL) &&
            ((*vCounterMap_Cfg[mid_idx].second_counter) < DLTEXT_UINT8_MAX))
        {
          (*vCounterMap_Cfg[mid_idx].second_counter)++;
        }

        DltExtRetVal = DLT_E_OK;
        break;
      }
      if (head_idx != tail_idx)
      {
        /*If greater, ignore left half*/
        if ((DLT_NUM_ERROR_CFG > mid_idx) &&
            ((vCounterMap_Cfg[mid_idx].errorCode) < eErrorCode))
        {
          head_idx = mid_idx + 1u;
        }

        /*If smaller, ignore right half*/
        else
        {
          tail_idx = mid_idx - 1u;
        }
      }
      else
      {
        break;
      }
    }
  }
#endif /* DLT_NUM_ERROR_CFG */

  return DltExtRetVal;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to update all counters to NVM
///
/// @param void
///
/// @return void
//----------------------------------------------------------------------------------------------------------------------
static void DltExt_UpdateCounterMemoryToNvm(void)
{
  /*Update counters to NVM*/
  boolean bIsNVMJobCompleted = FALSE;

  bIsNVMJobCompleted = DltExt_isNVMJobCompleted_Counter();

  if ((TRUE == bIsNVMJobCompleted) && (TRUE == bDltExt_InitCompleted_Status))
  {
/* If the previous job is completed then only write new values otherwise store
 * it in a local buffer */
/*misra_c_2012_rule_12_3_violation:	These expressions uses the comma
 * operator - to be deviated*/
#if 0 /* Will be removed after NVM and RTE iteration */
        DltExt_MemAbsSet_Set_NVM_HM_Data_Generic_Reset_Counter(vCounterData.DltExt_Generic_Reset_Counter);
        DltExt_MemAbsSet_Set_NVM_HM_Data_Illegal_Memory_Address_Reset_Counter(vCounterData.DltExt_Illegal_Memory_Address_Reset_Counter);
        DltExt_MemAbsSet_Set_NVM_HM_Stack_Overflow_Reset_Counter(vCounterData.DltExt_StackOverflowReset_Counter);
        DltExt_MemAbsSet_Set_NVM_HM_Illegal_Opcode_Reset_Counter(vCounterData.DltExt_IllegalOpCodeReset_Counter);
        DltExt_MemAbsSet_Set_NVM_HM_Power_ON_Reset_Counter(vCounterData.DltExt_PowerON_Counter);
        DltExt_MemAbsSet_Set_NVM_HM_Watchdog_timer_Reset_Counter(vCounterData.DltExt_WatchdogTimerReset_Counter);
#endif
  }
  else
  {
    // store it in a local buffer
    MemLib_MemCpy(&vCounterDataLocal, &vCounterData, sizeof(vCounterDataLocal));
    // set a flag if Counter data was stored locally due to NvMJob not completed
    vCounterDataLocal_Flag = TRUE;
  }
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to check the vailidity of the stored reset code.
///
/// @param void
///
/// @return uReturn    - boolean return FALSE(0) or TRUE(1)
//----------------------------------------------------------------------------------------------------------------------
static boolean DltExt_EvalStoredResetCode(void)
{
  boolean uReturn = FALSE;
  static const uint8 cTypeCode[NUM_TYPE_CODES] = {
    ///< Array to store type codes>
    DLT_APPLICATION_INFO,
    DLT_APPLICATION_ERROR,
    DLT_FAULT_FORCED_RESET,
    DLT_FAULT_ARM_ERROR,
    DLT_FAULT_NVM_ERROR,
    DLT_FAULT_HW_RESET,
    DLT_FAULT_OS_ERROR
  };
  tTypeCode typeCode = (uint8)((vStoredResetCode & FAULT_CODE_MASK) >> DLT_FAULT_TYPE_OFST);
  uint8 idx;
  /*Check whether the stored reset code contains the valid type code*/
  /*If yes then return 'True'*/
  for (idx = 0; idx < NUM_TYPE_CODES; idx++)
  {
    if ((typeCode != 0u) && (typeCode == cTypeCode[idx]))
    {
      uReturn = TRUE;
      break;
    }
  }
  return uReturn;
}

#endif /* DLT_FAULTCOUNTER_ENABLE */

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to read the stored application info data from NVM.
///
/// @param void
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_GetLogDatafromNVM(void)
{
  Std_ReturnType uReturn = E_OK;
  /* copy the data from mirror RAM to local RAM*/
  DLTEXT_COPY_FROM_APPINFO_MIRRORRAM;

#if (DLTEXT_USE_SNVM == STD_ON)
  (void)DLTEXT_GET_DLT_FETAL_STORAGE((uint8 *)&DltExt_CriticalErrBuffer);

#endif

  return uReturn;
}

/* ============================================================================
 *  DltExt_ReportResetHistoryAtStartup
 *
 *  Called once after NvM reset history is loaded and adjusted.
 *  It re-emits the most recent reset-history entry (index 0) as a normal
 *  DLT log via Dlt_SendLogMessage() using APID="RSTM", CTID="RHIS".
 *
 *  The resulting DLT frame will be seen by Dlt.c exactly like any other log,
 *  and DltExt_SendLogMessage() will route it to the dedicated
 *  DltExt_ResetInfo_SharedDumpBuffer based on APID/CTID.
 * ==========================================================================*/
static void DltExt_ReportResetHistoryAtStartup(void)
{
  /* One-shot DLT log meta for reset-history replay */
  static Dlt_MessageLogInfoType DltExt_ResetHistory_LogInfo = {
    /* argCount:
    * Runtime path uses verbose mode with one argument
    * (raw block → TypeInfo already added by Dlt.c).
    * From Dlt.c point of view this is 1 argument.
    */
    .argCount = 1U,
    .logLevel = DLT_LOG_FATAL,
    .options = DLT_ISMSGVERBOSEMODE_BIT,
    .contextId = { DLTEXT_RESET_CTID_CHAR0,
                   DLTEXT_RESET_CTID_CHAR1,
                   DLTEXT_RESET_CTID_CHAR2,
                   DLTEXT_RESET_CTID_CHAR3 },
    .appId = { DLTEXT_RESET_APID_CHAR0,
               DLTEXT_RESET_APID_CHAR1,
               DLTEXT_RESET_APID_CHAR2,
               DLTEXT_RESET_APID_CHAR3 },
  };

  uint8 payload[DLTEXT_ADDITIONAL_RESET_INFO_SIZE];
  uint16 payloadLen;

  /* Copy “latest” reset history snapshot (index 0) as raw payload.
   * Format is the same compact structure you already store in NvM:
   *   - [0..] MessageID, FaultStatus, timestamp, additional data…
   */
  MemLib_MemCpy(&payload[0],
                &DltExt_ResetLogDataBuffer.code[0][0],
                (uint16)DLTEXT_ADDITIONAL_RESET_INFO_SIZE);

  payloadLen = 8U;

  /* Use the pre-initialized log info with APID "RSTM" / CTID "RHIS". */
  (void)Dlt_SendLogMessage(0u, /* default session id */
                           &DltExt_ResetHistory_LogInfo,
                           &payload[0],
                           (uint8)payloadLen);
}

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   DltExt_StoreAppInfoToLocalBuffer
**
** Visibility       :   Static
**
** Description      :   Stores latest AppInfo snapshot into local shadow
**                      buffer and marks AppInfo NvM write pending.
**
** Invocation       :   Internal
**
** Inputs           :   IsNvMInitCompleted
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_StoreAppInfoToLocalBuffer(boolean IsNvMInitCompleted)
{
  if (IsNvMInitCompleted != TRUE)
  {
    if (DLTEXT_LAST_APP_HISTORY_NUM > u8DltExt_LogTriggered_NvMNotInit)
    {
      u8DltExt_LogTriggered_NvMNotInit++;
    }
  }

  (void)MemLib_MemCpy(&DltExt_LocalAppinfo,
                      &DltExt_AppLogDataBuffer,
                      DLTEXT_APPLOGDATA_SIZE);

  DltExt_LocalNvMBuffer_Flag = TRUE;
  DltExt_AppInfoWritePending = TRUE;
}

/*============================================================================
**
** Function Name    :   DltExt_TryTriggerAppInfoNvMWrite
**
** Visibility       :   Static
**
** Description      :   Triggers one AppInfo NvM write only when NvM is ready
**                      and no AppInfo write is already outstanding.
**
** Invocation       :   Internal
**
** Inputs           :   None
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_TryTriggerAppInfoNvMWrite(void)
{
  Std_ReturnType RetVal = E_NOT_OK;
  boolean bIsNVMJobCompleted = FALSE;

  bIsNVMJobCompleted = DltExt_isNVMJobCompleted_Data();

  if ((TRUE == bDltExt_InitCompleted_Status) &&
      (FALSE == DltExt_AppInfoWriteInProgress) &&
      (TRUE == bIsNVMJobCompleted))
  {
    DLTEXT_COPY_TO_APPINFO_MIRRORRAM;
    RetVal = DLTEXT_WRITE_APPINFO_BLOCK;

    if (RetVal == E_OK)
    {
      DltExt_AppInfoNvMWriteStarted();
      DltExt_AppInfoWriteInProgress = TRUE;
      DltExt_AppInfoWritePending = FALSE;
    }
  }

  return RetVal;
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to read the stored reset info data from NVM and trigger NvM
/// write if the last reset was due to SW Hang
///
/// @param void
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_GetResetDatafromNVM(void)
{
  Std_ReturnType uReturn = E_NOT_OK;
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  uint16 SwHang_id;
  uint8 idx;

  /* Is data ready in mirror RAM?*/
  if (TRUE == DltExt_ResetInfoGetNvMReadyStatus())
  {
    /* Verify the NvM block was read successfully before using its data.
       A VBAT cut during a prior SPI-EEPROM write can leave a partially corrupt block.
       NVM_REQ_INTEGRITY_FAILED means the stored CRC does not match — the mirror RAM
       content is unreliable and must NOT be propagated downstream (e.g. to shared DDR
       or UCL adapters), as a corrupt pointer-sized field there can cause a Data Abort. */
    NvM_RequestResultType flNvMResetBlockStatus = NVM_REQ_NOT_OK;
    if ((E_OK == NvMExt_GetErrorStatus(
           NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo,
           &flNvMResetBlockStatus)) &&
        (flNvMResetBlockStatus == NVM_REQ_OK))
    {
      /* copy the data from mirror RAM*/
      DltExt_CopyResetInfoFromNvmMirror();

      /* copy only reset logs to local RAM*/
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer,
                    &DltExt_Internal_RstInfo.RstHistory,
                    DLTEXT_RESET_HISTORY_MAX_SIZE);

      /* Retrive the Fault ID from SW hang block*/
      SwHang_id = ((DLTEXT_SWHANG_MIRRORRAM[0] << 8) | (DLTEXT_SWHANG_MIRRORRAM[1]));
      /* If the fault id matches i.e last reset was due to SW hang*/
      if (SwHang_id == DLTEXT_SWHANG_FLTID)
      {
        /*Once an error code is reported, remove older reset reasons from the NVM
         * local buffer and maintain only the latest five reset reasons*/
        for (idx = (DLTEXT_TOTAL_NUM_OF_RESET_HISTORY - 1u); idx > 0u; idx--)
        {
          MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[idx],
                        &DltExt_ResetLogDataBuffer.code[idx - 1u],
                        DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
        }

        /* Clear Latest Index Data*/
        MemLib_MemSet(&DltExt_ResetLogDataBuffer.code[0][0], 0x00U, DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
        /* copy the sw hang block*/
        MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[0][0],
                      &DLTEXT_SWHANG_MIRRORRAM,
                      DLTEXT_SWHANG_SIZE);
        /* clear the sw hang block*/
        DltExt_ResetSWHang();
#if (DLTEXT_UART_PRINT == STD_ON)
        (void)DltExt_Uart_Printf(" SW Hang Reset detected. Updating NvM Reset Log Data\r\n");
#endif

        /* Update the NvM struct with latest reset info*/
        MemLib_MemCpy(&DltExt_Internal_RstInfo.RstHistory[0],
                      &DltExt_ResetLogDataBuffer,
                      DLTEXT_RESET_HISTORY_MAX_SIZE);

        /* mark dump invalid for this reset reason */
        DltExt_Internal_RstInfo.OsCpuDump[0] = (uint8)((((uint16)DLTEXT_SWHANG_FLTID) >> 8) & 0xFFu);
        DltExt_Internal_RstInfo.OsCpuDump[1] = (uint8)(((uint16)DLTEXT_SWHANG_FLTID) & 0xFFu);
        DltExt_Internal_RstInfo.OsCpuDump[2] = 0u; /* DumpValid = 0 */
        DltExt_Internal_RstInfo.OsCpuDump[3] = 0xA5u; /* DumpType = SW_HANG marker */
        /*clear the remainder of Dump to avoid sending stale data from previous resets;
        actual dump will be filled later by DltExt_MainFunction if needed*/
        MemLib_MemSet(&DltExt_Internal_RstInfo.OsCpuDump[4], 0xFFu, (uint32)(DLTEXT_OSCPU_DUMP_SIZE - 4u));

        /*Copy data to mirror RAM */
        DltExt_CopyResetInfoToNvmMirror();
        /* Trigger NvM write for reset block and SW hang block*/
        /* the chance of this request getting rejected is 0 since these blocks are
           written only via inline write in case of reset
           Hence return is not checked */
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
        (void)DLTEXT_WRITE_RESETINFO_BLOCK;
        (void)DLTEXT_WRITE_SWHANG_BLOCK;
#endif
    }
    uReturn = E_OK;
    }
    else
    {
      /* NvM block integrity check failed — corrupt data from a partial write.
         Zero out internal struct and mirror so no stale garbage propagates. */
      MemLib_MemSet(&DltExt_Internal_RstInfo, 0x00u, (uint32)sizeof(DltExt_Internal_RstInfo));
      DltExt_CopyResetInfoToNvmMirror();
    }
  }
#endif
  return uReturn;
}
#endif

/*============================================================================
**
** Function Name    :   DltExt_ResetSWHang
**
** Visibility       :   Public
**
** Description      :   The DltExt_ResetSWHang function is called to reset sw
* hang mirror ram
**
** Invocation       :
**
** Inputs           :
**
** Outputs          : none
**
** Critical Section :
**
**==========================================================================*/
void DltExt_ResetSWHang(void)
{
  /* Reset the sw hang mirror ram to zero*/
  MemLib_MemSet(&DLTEXT_SWHANG_MIRRORRAM, 0x00U, DLTEXT_SWHANG_SIZE);
}

static void DltExt_ClearOsDumpAfterConsume(void)
{
  /* Keep history; clear only dump */
  MemLib_MemSet(&DltExt_Internal_RstInfo.OsCpuDump[0],
                0x00u,
                (uint32)DLTEXT_OSCPU_DUMP_SIZE);

  /* Persist updated struct */
  DltExt_CopyResetInfoToNvmMirror();
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  (void)DLTEXT_WRITE_RESETINFO_BLOCK;
#endif
}

static void DltExt_CopyResetInfoFromNvmMirror(void)
{
  /* DltExt_ResetInfo[] layout:
   * [0 .. DLTEXT_RESET_HISTORY_MAX_SIZE-1]                = RstHistory
   * [DLTEXT_RESET_HISTORY_MAX_SIZE .. end of OsCpuDump]   = OsCpuDump
   */
  MemLib_MemCpy((uint8 *)&DltExt_Internal_RstInfo.RstHistory[0],
                (const uint8 *)&DltExt_ResetInfo[0],
                (uint32)DLTEXT_RESET_HISTORY_MAX_SIZE);

  MemLib_MemCpy((uint8 *)&DltExt_Internal_RstInfo.OsCpuDump[0],
                (const uint8 *)&DltExt_ResetInfo[DLTEXT_RESET_HISTORY_MAX_SIZE],
                (uint32)DLTEXT_OSCPU_DUMP_SIZE);
}

static void DltExt_CopyResetInfoToNvmMirror(void)
{
  MemLib_MemCpy((uint8 *)&DltExt_ResetInfo[0],
                (const uint8 *)&DltExt_Internal_RstInfo.RstHistory[0],
                (uint32)DLTEXT_RESET_HISTORY_MAX_SIZE);

  MemLib_MemCpy((uint8 *)&DltExt_ResetInfo[DLTEXT_RESET_HISTORY_MAX_SIZE],
                (const uint8 *)&DltExt_Internal_RstInfo.OsCpuDump[0],
                (uint32)DLTEXT_OSCPU_DUMP_SIZE);
}

/* ============================================================================
 *  Detect whether a given DLT frame belongs to the Reset-History APID/CTID
 *
 *  payLoadHeader:
 *      Pointer to Standard Header (byte 0).
 *      Extended Header immediately follows.
 *
 *  Layout (AUTOSAR DLT, verbose mode):
 *      StdHdr: 16 bytes
 *      ExtHdr:
 *          [16]      MSIN
 *          [17]      NOAR
 *          [18..21]  APID (ASCII)
 *          [22..25]  CTID (ASCII)
 * ==========================================================================*/
static boolean DltExt_IsResetHistoryLog(const uint8 *payLoadHeader,
                                        uint16 payLoadHeaderLength)
{
  if (payLoadHeaderLength < DLT_MAX_HEADER_BUFF_SIZE)
  {
    return FALSE;
  }

  /* APID "RSTM" */
  if ((payLoadHeader[18] != (uint8)'R') ||
      (payLoadHeader[19] != (uint8)'S') ||
      (payLoadHeader[20] != (uint8)'T') ||
      (payLoadHeader[21] != (uint8)'M'))
  {
    return FALSE;
  }

  /* CTID "RHIS" */
  if ((payLoadHeader[22] != (uint8)'R') ||
      (payLoadHeader[23] != (uint8)'H') ||
      (payLoadHeader[24] != (uint8)'I') ||
      (payLoadHeader[25] != (uint8)'S'))
  {
    return FALSE;
  }

  return TRUE;
}

/******************************************************************************
 * Build AUTOSAR verbose payload:
 *
 *   [StdHdr][ExtHdr][TypeInfo (4B BE)][RawPayload...]
 *
 * Returns total frame length written into dst,
 *         or 0 on overflow.
 ******************************************************************************/
static uint16 DltExt_BuildVerboseFrame(uint8 *dst, uint16 dstSize, const uint8 *payLoadHeader, uint16 payLoadHeaderLen, const uint8 *payLoad, uint16 payLoadLen)
{
  uint16 totalLen;
  uint16 writePos;

  /* Total = header + 4-byte TypeInfo + raw payload */
  totalLen = (uint16)(payLoadHeaderLen + 4U + payLoadLen);

  if (totalLen > dstSize)
  {
    return 0U; /* Not enough space → drop */
  }

  /* 1. Copy Std + Ext header */
  MemLib_MemCpy(&dst[0], payLoadHeader, payLoadHeaderLen);

  /* 2. Serialize 4-byte AUTOSAR TypeInfo (big-endian) */
  writePos = payLoadHeaderLen;

  dst[writePos + 0U] = (uint8)((DLTEXT_TYPEINFO_BYTES >> 24) & 0xFFU);
  dst[writePos + 1U] = (uint8)((DLTEXT_TYPEINFO_BYTES >> 16) & 0xFFU);
  dst[writePos + 2U] = (uint8)((DLTEXT_TYPEINFO_BYTES >> 8) & 0xFFU);
  dst[writePos + 3U] = (uint8)(DLTEXT_TYPEINFO_BYTES & 0xFFU);

  writePos += 4U;

  /* 3. Raw payload (MessageId, Status, Timestamp, AdditionalData...) */
  MemLib_MemCpy(&dst[writePos], payLoad, payLoadLen);

  /* Update Length Byte Pos 2 & 3 for this TypeInfo Addition */
  dst[2U] = (uint8)((totalLen >> 8U) & 0xFFU);
  dst[3U] = (uint8)(totalLen & 0xFFU);
  return totalLen;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to update all error code buffer to NVM
///
/// @param void
///
/// @return void
//----------------------------------------------------------------------------------------------------------------------
static void DltExt_UpdateLogMemoryToNvm(void)
{
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  Std_ReturnType RetVal = E_NOT_OK;

  if (TRUE != bDltExt_InitCompleted_Status)
  {
    DltExt_StoreAppInfoToLocalBuffer(FALSE);
  }
  else if (TRUE == DltExt_AppInfoWriteInProgress)
  {
    /* One AppInfo write is already outstanding. Do not call NvM again. */
    DltExt_StoreAppInfoToLocalBuffer(TRUE);
  }
  else
  {
    RetVal = DltExt_TryTriggerAppInfoNvMWrite();

    if (RetVal != E_OK)
    {
      /* Either NvM still busy or write request not accepted. Preserve latest
       * full snapshot locally and retry later from MainFunction(). */
      DltExt_StoreAppInfoToLocalBuffer(TRUE);
    }
  }
#endif
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to write error code to local memory.
///
/// @param eErrorCode  -
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------

static Dlt_ReturnType DltExt_InlineWritetoNvMemory(uint16 eErrorCode,
                                                   uint32 DltExt_Timestamp,
                                                   const uint8 *pBuffer,
                                                   uint16 message_len)
{
  uint8 idx;
  Dlt_ReturnType Return_Val = DLT_E_NOT_OK;

#if (DLT_WRITE_GIPCONSOL_ENABLE == STD_ON)
  uint32_t PrintResetCode;
#endif

  /* IS reset info loaded from NvM?*/
  if (FALSE == DltExt_ResetInfoLoaded)
  {
/* Load the reset info from NvM*/
/* NOTE: Load only reset info since dump would have been updated when this
     * function is invoked*/
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
    DltExt_InlineReadResetInfo(DLTEXT_NVBLOCKDESCRIPTOR_DLT_FETAL_STORAGE);
    #endif
    /* copy the reset info from NVM mirror */
    DltExt_CopyResetInfoFromNvmMirror();
    /* copy only reset logs to local RAM*/
    MemLib_MemCpy(&DltExt_ResetLogDataBuffer,
                  &DltExt_Internal_RstInfo.RstHistory,
                  DLTEXT_RESET_HISTORY_MAX_SIZE);
    /* Mark the label that loading of reset info is over */
    DltExt_ResetInfoLoaded = TRUE;
  }
  /* Procceding with update only after reset info is loaded*/
  /* TODO: what if the inline read fails, it might fail only if he SPI is not
   * initialized, in that case even inline write also will fail*/
  if (DltExt_ResetInfoLoaded == TRUE)
  {
    /* Initialize Return_Val to OK here, as we have started processing */
    Return_Val = DLT_E_OK;

#if (DLTEXT_USE_SNVM == STD_ON)

    DltExt_CriticalErrBuffer.magicFlag = DLTEXT_MAGIC_FLAG_VAL;

    DltExt_CriticalErrBuffer.code[0U] = (uint8)((eErrorCode >> 8U) & 0xFFU);
    DltExt_CriticalErrBuffer.code[1U] = (uint8)(eErrorCode & 0xFFU);

    DltExt_CriticalErrBuffer.code[2U] = (uint8)((DltExt_Timestamp >> 24U) & 0xFFU);
    DltExt_CriticalErrBuffer.code[3U] = (uint8)((DltExt_Timestamp >> 16U) & 0xFFU);
    DltExt_CriticalErrBuffer.code[4U] = (uint8)((DltExt_Timestamp >> 8U) & 0xFFU);
    DltExt_CriticalErrBuffer.code[5U] = (uint8)(DltExt_Timestamp & 0xFFU);

    if (0U < message_len)
    {
      // Additional Data of current FaultCode store it in 6th index
      MemLib_MemCpy(&DltExt_CriticalErrBuffer.code[6U], pBuffer, message_len);
    }
    // for (idx = 6U; idx < (uint8)message_len; idx++)
    // {
    //     DltExt_CriticalErrBuffer.code[idx] = pBuffer[idx];
    // }

#else

    /*Once an error code is reported, remove older reset reasons from the NVM
     * local buffer and maintain only the latest five reset reasons*/
    for (idx = (DLTEXT_TOTAL_NUM_OF_RESET_HISTORY - 1u); idx > 0u; idx--)
    {
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[idx],
                    &DltExt_ResetLogDataBuffer.code[idx - 1u],
                    DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
    }

    /* Clear Latest Index Data*/
    MemLib_MemSet(&DltExt_ResetLogDataBuffer.code[0][0], 0x00U, DLTEXT_ADDITIONAL_RESET_INFO_SIZE);

    // // Current FaultCode store it in 0th index
    DltExt_ResetLogDataBuffer.code[0][0] = (uint8)((eErrorCode >> 8U) & 0xFFU);
    DltExt_ResetLogDataBuffer.code[0][1] = (uint8)(eErrorCode & 0xFFU);

    // // Timestamp of current FaultCode store it in 2nd index
    DltExt_ResetLogDataBuffer.code[0][2] = (uint8)((DltExt_Timestamp >> 24U) & 0xFFU);
    DltExt_ResetLogDataBuffer.code[0][3] = (uint8)((DltExt_Timestamp >> 16U) & 0xFFU);
    DltExt_ResetLogDataBuffer.code[0][4] = (uint8)((DltExt_Timestamp >> 8U) & 0xFFU);
    DltExt_ResetLogDataBuffer.code[0][5] = (uint8)(DltExt_Timestamp & 0xFFU);

    // Additional Data of current FaultCode store it in 6th index
    if (0U < message_len)
    {
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[0][6], pBuffer, message_len);
    }

    MemLib_MemCpy(&DltExt_ResetLogDataBuffer.unexpectedResetCode[0],
                  &DltExt_ResetLogDataBuffer.code[0][0],
                  2);
    DltExt_ResetLogDataBuffer.unexpectedResetCode[2] = 1u;

    // Copy ResetLogDataBuffer Content to DltExt_vNVMData
    MemLib_MemCpy(&DltExt_Internal_RstInfo.RstHistory[0],
                  &DltExt_ResetLogDataBuffer,
                  DLTEXT_RESET_HISTORY_MAX_SIZE);

#endif

#if (BLOCK_WRITE_ON_EXEPTION == STD_ON)
    /* Copy the data to mirror RAM*/
    DltExt_CopyResetInfoToNvmMirror();
//  DltExt_RstMPushOsArmDump(&&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt.BsReten_VisDlt_Element[DLTEXT_RESETLOGDATA_MAX_LEN],)
/* Call blocking write or Inline write for immeadiate action */
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
    if (DltExt_OnException_Counter != 1u)
    {
      DltExt_BlockWriteOnException((uint16)DLTEXT_NVBLOCKDESCRIPTOR_DLT_FETAL_STORAGE);
    }
    else
    {
      Return_Val = DLT_E_NOT_OK;
    }
#endif

#endif

#if (DLT_WRITE_GIPCONSOL_ENABLE == STD_ON)
    /*Store logged reset reason in a special memory region*/
    /*Handled for all the errors except Internal Comm. and GIP Supervision
     * Error*/
    vStoredResetCode = eErrorCode;
    PrintResetCode = (uint32_t)vStoredResetCode;
    /*Print the log data to SCU console*/
    McuExt_SetLogs((uint32_t *)&PrintResetCode);
#endif
  }
  else
  {
    Return_Val = DLT_E_NOT_OK;
  }

  return Return_Val;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to read the reset info from NvM.
///
/// @param NvBlockId_u16  - Block id which stores Reset info
///
/// @return uReturn    - void
//----------------------------------------------------------------------------------------------------------------------

static void DltExt_InlineReadResetInfo(uint16 NvBlockId_u16)
{
  if (E_OK != DltExt_InlineReadResetInfoInternal(NvBlockId_u16))
  {
    MemLib_MemSet(&DltExt_Internal_RstInfo, 0x00u, (uint32)sizeof(DltExt_Internal_RstInfo));
  }
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to read the reset info from NVM using SyncTransmit.
///
/// @param NvBlockId_u16  - Block id which stores Reset info
///
/// @return uReturn    - void
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_InlineReadResetInfoInternal(uint16 NvBlockId_u16)
{
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_OFF)
  (void)NvBlockId_u16;
  return E_NOT_OK;
#else
  Std_ReturnType SpiRetVal = E_NOT_OK;
  Std_ReturnType RetVal = E_NOT_OK;
  static uint8 DLT_LocRxBuff[DLT_SPI_EEPROM_PAGE_SIZE + DLT_COMMAND_BYTES_LENGTH];
  uint16 LengthToCopy;
  uint8 Length;
  uint16 Ea_blockindex_u16;
  uint16 PhyEepAddr_u16;
  uint16 PageAddrOffset;
  uint16 RxBufferIndex;

  if (NvBlockId_u16 >= NVM_NUM_OF_BLOCKS)
  {
    return E_NOT_OK;
  }

  if (TRUE == DltExt_ResetInfoGetNvMReadyStatus())
  {
    DltExt_CopyResetInfoFromNvmMirror();
    return E_OK;
  }

  while (Spi_GetStatus() != SPI_IDLE)
  {
    Spi_MainFunction_Handling();
  }

  Spi_Cancel(DLT_SPI_EEPROM_SEQUENCE);

  if ((SPI_SEQ_OK == Spi_GetSequenceResult(DLT_SPI_EEPROM_SEQUENCE)) ||
      (SPI_SEQ_CANCELLED == Spi_GetSequenceResult(DLT_SPI_EEPROM_SEQUENCE)))
  {
    if (NvM_BlockConfig[NvBlockId_u16].NvBlockBaseNumber == 0u)
    {
      return E_NOT_OK;
    }

    Ea_blockindex_u16 = (uint16)(NvM_BlockConfig[NvBlockId_u16].NvBlockBaseNumber - 1u);

    MemLib_MemSet(&DLT_LocRxBuff[0],
                  0x00U,
                  (uint32)(DLT_SPI_EEPROM_PAGE_SIZE + DLT_COMMAND_BYTES_LENGTH));
    MemLib_MemSet(&DLT_RxBuff[0],
                  0x00U,
                  (uint32)DLTEXT_RESET_HISTORY_MAX_SIZE);

    PhyEepAddr_u16 = Ea_Config[Ea_blockindex_u16].BlockBaseAddress;
    PhyEepAddr_u16 += 2u; /* skip header bytes */

    Length = 0xFFu;
    PageAddrOffset = 0u;
    RxBufferIndex = 0u;
    LengthToCopy = DLTEXT_RESET_HISTORY_MAX_SIZE;

    while (LengthToCopy != 0u)
    {
      if (Length == 0xFFu)
      {
        Length = (uint8)(DLT_SPI_EEPROM_PAGE_SIZE -
                         (PhyEepAddr_u16 % DLT_SPI_EEPROM_PAGE_SIZE));
        if ((uint16)Length > LengthToCopy)
        {
          Length = (uint8)LengthToCopy;
        }
      }
      else if ((uint16)DLT_SPI_EEPROM_PAGE_SIZE < LengthToCopy)
      {
        Length = (uint8)DLT_SPI_EEPROM_PAGE_SIZE;
      }
      else
      {
        Length = (uint8)LengthToCopy;
      }

      DLT_WriteAddressBuffer[0] = DLT_READ_COMMAND;
      DLT_WriteAddressBuffer[1] =
          (uint8)(((uint16)(PhyEepAddr_u16 + PageAddrOffset) & 0xFF00u) >> 8u);
      DLT_WriteAddressBuffer[2] =
          (uint8)((uint16)(PhyEepAddr_u16 + PageAddrOffset) & 0x00FFu);

      SpiRetVal = Spi_SetupEB(DLT_SPI_EEPROM_SEQUENCE,
                              &DLT_WriteAddressBuffer[0],
                              &DLT_LocRxBuff[0],
                              (uint16)(Length + DLT_COMMAND_BYTES_LENGTH));

      if (SpiRetVal != E_OK)
      {
        return E_NOT_OK;
      }

      SpiRetVal = Spi_SyncTransmit(DLT_SPI_EEPROM_SEQUENCE);
      if (SpiRetVal != E_OK)
      {
        return E_NOT_OK;
      }

      MemLib_MemCpy(&DLT_RxBuff[RxBufferIndex],
                    &DLT_LocRxBuff[DLT_COMMAND_BYTES_LENGTH],
                    Length);

      PageAddrOffset = (uint16)(PageAddrOffset + Length);
      RxBufferIndex = (uint16)(RxBufferIndex + Length);
      LengthToCopy = (uint16)(LengthToCopy - Length);
    }

    MemLib_MemCpy(&DltExt_Internal_RstInfo.RstHistory[0],
                  &DLT_RxBuff[0],
                  DLTEXT_RESET_HISTORY_MAX_SIZE);

    RetVal = E_OK;
  }
  return RetVal;
#endif
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief Handler to write the error code to NVM buffer
///
///
/// @param eErrorCode
///
///
/// @return uReturn    - Std_ReturnType return OK(0) or NOT_OK(1)
//----------------------------------------------------------------------------------------------------------------------
static Std_ReturnType DltExt_WritetoNVMBuffer(uint16 eErrorCode,
                                              uint32 DltExt_Timestamp,
                                              const uint8 *pBuffer,
                                              uint16 message_len)
{
  Std_ReturnType uReturn = E_NOT_OK;
  uint8 idx;
  uint8 idx_updt = 0xFFu;
#if (DLT_WRITE_GIPCONSOL_ENABLE == STD_ON)
  uint32_t PrintResetCode = (uint32_t)eErrorCode;
#endif
  /* This block is used to update only add-on data in case application log is
   * already present*/
  /* This can be removed later if not required */
  for (idx = 0; idx < DLTEXT_LAST_APP_HISTORY_NUM; idx++)
  {
    uint16 lerrorcode;
    /* Extracting the error code */
    lerrorcode = (((DltExt_AppLogDataBuffer.code[idx][0]) << 8u) |
                  (DltExt_AppLogDataBuffer.code[idx][1]));
    if (lerrorcode == eErrorCode)
    {
      /* when error code matches, remember the index to store info*/
      idx_updt = idx;
      break;
    }
  }
  /* If no match is found*/
  if (idx_updt == 0xFFu)
  {
    /*Once an error code is reported, remove older reset reasons from the NVM
     * local buffer and maintain only the latest five reset reasons*/
    for (idx = (DLTEXT_LAST_APP_HISTORY_NUM - 1u); idx > 0u; idx--)
    {
      // use meblib_cpy
      MemLib_MemCpy(&DltExt_AppLogDataBuffer.code[idx],
                    &DltExt_AppLogDataBuffer.code[idx - 1u],
                    DLTEXT_ADDITIONAL_APPLOG_INFO_SIZE);
    }
    idx_updt = 0;
  }

  /* Clear Latest Index Data*/
  MemLib_MemSet(&DltExt_AppLogDataBuffer.code[idx_updt][0], 0x00U, DLTEXT_ADDITIONAL_APPLOG_INFO_SIZE);

  // Current FaultCode store it in 0th index
  DltExt_AppLogDataBuffer.code[idx_updt][0] = (uint8)((eErrorCode >> 8U) & 0xFFU);
  DltExt_AppLogDataBuffer.code[idx_updt][1] = (uint8)(eErrorCode & 0xFFU);
  // MemLib_MemCpy(&DltExt_AppLogDataBuffer.code[0][0], &eErrorCode, 2);

  // Timestamp of current FaultCode store it in 2nd index
  // MemLib_MemCpy(&DltExt_AppLogDataBuffer.code[0][2], &DltExt_Timestamp, 4);
  DltExt_AppLogDataBuffer.code[idx_updt][2U] = (uint8)((DltExt_Timestamp >> 24U) & 0xFFU);
  DltExt_AppLogDataBuffer.code[idx_updt][3U] = (uint8)((DltExt_Timestamp >> 16U) & 0xFFU);
  DltExt_AppLogDataBuffer.code[idx_updt][4U] = (uint8)((DltExt_Timestamp >> 8U) & 0xFFU);
  DltExt_AppLogDataBuffer.code[idx_updt][5U] = (uint8)(DltExt_Timestamp & 0xFFU);

  if (0U < message_len)
  {
    // Additional Data of current FaultCode store it in 6th index
    MemLib_MemCpy(&DltExt_AppLogDataBuffer.code[idx_updt][6], pBuffer, message_len);
  }
  /*Write report code in the local NVMData buffer to NVM*/
  DltExt_UpdateLogMemoryToNvm();

#if (DLT_WRITE_GIPCONSOL_ENABLE == STD_ON)
  /*Print the log data to SCU console*/
  McuExt_SetLogs((uint32_t *)&PrintResetCode);
#endif

  return uReturn;
}

#if ((DLT_HSM_TO_GIP_INTERFACE == STD_ON) && (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON))
/*============================================================================
**
** Function Name    :   Hsm_DltExt_IpcLogEvent
**
** Visibility       :   Private
**
** Description      :   Get Buffer Full Indication from HSM
**                      
**
**==========================================================================*/
void Hsm_DltExt_IpcLogEvent(uint32 data)
{
  DltExt_Ipc_HsmLogEvent(data);
}
#endif

/*============================================================================
**
** Function Name    :   DltExt_Report
**
** Visibility       :   Public
**
** Description      :   Handler to process Error Reports and Exceptions from
* Other SWCs, BSWs, CDDs.
**
**
** Invocation       :   OS will invoke this function with 100ms periodicity
**
** Inputs           :   @param eModuleId   	- tDlt_SwcId ID pass by caller
* SWC, who is sending error/exception report.
**                      @param eErrorCode   - tDlt_ErrorCode Type of
* error/exception pass by caller.
**                      @param pBuffer	    - void * data buffer to receive the
* Fault Data, pass by caller.
**                      @param uBufferSize	- uint16 the size of the Fault
* Data pass by caller.
**
** Outputs          :   Std_ReturnType - return E_OK or E_NOT_OK to the caller.
**
** Critical Section :
**
**==========================================================================*/

static Dlt_ReturnType DltExt_Report(uint16 eErrorCode, uint32 DltExt_Timestamp, const uint8 *pBuffer, Dlt_MessageLogLevelType LogLevel, uint16 message_length)
{
  Dlt_ReturnType DltExtRetVal = DLT_E_NOT_OK;
  boolean StoreResetHistory = FALSE;

  // Read message log level type from message for Critical/Non-Critical
  StoreResetHistory = DltExt_ShouldStoreResetHistory(pBuffer, message_length, LogLevel);

  if ((StoreResetHistory == TRUE) && (eErrorCode > 0u))
  {
    // Store critical faultcodes in separate cyclic buffer and inline Nvm write
    DltExtRetVal = DltExt_InlineWritetoNvMemory(eErrorCode, DltExt_Timestamp, pBuffer, message_length);
  }
  else if (eErrorCode > 0u)
  {
    // Store non-critical faultcodes in separate cyclic buffer and normal Nvm
    // write
    (void)DltExt_WritetoNVMBuffer(eErrorCode, DltExt_Timestamp, pBuffer, message_length);
    DltExtRetVal = DLT_E_OK;
#if (DLT_FAULTCOUNTER_ENABLE == STD_ON)
    (void)DltExt_UpdateFaultCounter(eErrorCode);
    (void)DltExt_UpdateCounterMemoryToNvm();
#endif
  }
  else
  {
    DltExtRetVal = DLT_E_NOT_OK;
  }

  return DltExtRetVal;
}

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   DltExt_KpiBufferHandling
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static Dlt_ReturnType DltExt_KpiBufferHandling(uint16 KPIMessageID, uint32 KPITimestamp, uint8 KPIVarible, uint8 Fault_status, const uint8 *KPISnapshot, uint16 KPI_Msg_Length)
{
  Dlt_ReturnType DltExtRetVal = DLT_E_NOT_OK;
  tDltExt_KpiMsg KPIMessage_l;
  uint32 KPI_TimeDiff_L;
  uint32 KPI_TimeDiff_L1;
  KPIMessage_l.KPI_MessageID = KPIMessageID;
  KPIMessage_l.KPI_Timestamp = KPITimestamp;
  KPIMessage_l.KPI_Varible = KPIVarible;
  KPIMessage_l.Faultstatus = Fault_status;

  /* Read the indext of the fault code from KPI Configuration table, return
   * error if not found, KPI_Cfg_Idx*/
  KPI_Cfg_idx = Search_KPI_Cfg(KPIMessageID);

  if (KPI_Cfg_idx != DLT_E_NOT_OK)
  {
    if (vKPIData_Cfg[KPI_Cfg_idx].Ucl_ConfigEn == TRUE)
    {
      if (kpi_localBuff_headIdx[KPI_Cfg_idx] <
          DLTEXT_MAX_KPIBUF_LEN) /* Coverity Fix*/
      {
        /* Based on the KPI_Cfg_idx value cyclicbuff_idx initialization should
         * be done*/
        DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
            .KPIMessage.KPI_MessageID = KPIMessage_l.KPI_MessageID;
        DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
            .KPIMessage.KPI_Timestamp = KPIMessage_l.KPI_Timestamp;
        DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
            .KPIMessage.KPI_Varible = KPIMessage_l.KPI_Varible;
        DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
            .KPIMessage.Faultstatus = KPIMessage_l.Faultstatus;

        if (KPI_Msg_Length > 0u)
        {
          MemLib_MemCpy(
              &DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
                   .KPIMessage.KPI_Snapshot[0],
              KPISnapshot,
              KPI_Msg_Length); //); To add Dynamic length
        }

        if (vKPIData_Cfg[KPI_Cfg_idx].tDltExt_DiffOrMetricsEn ==
            (uint8)DLTEXT_KPITYPE_TIMEDIFF) /*check for Time difference is
                                               Enabled*/
        {
          KPI_TimeDiff_L = KPIMessage_l.KPI_Timestamp - LastKPITimestamp[KPI_Cfg_idx]; /*Calculating Delta value*/
          if (DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
                  .ValidFlag == TRUE)
          {
            if ((kpi_localBuff_headIdx[KPI_Cfg_idx] + 1u) ==
                ((kpi_localBuff_startIdx[KPI_Cfg_idx] +
                  vKPIData_Cfg[KPI_Cfg_idx].Kpi_Buffer_Size)))
            {
              KPI_TimeDiff_L1 =
                  (uint32)(DltExt_KpiCyclicBuffer
                               [kpi_localBuff_headIdx[KPI_Cfg_idx]]
                                   .KPIMessage.DeltaKPI +
                           DltExt_KpiCyclicBuffer
                               [kpi_localBuff_startIdx[KPI_Cfg_idx]]
                                   .KPIMessage.DeltaKPI);
              DltExt_KpiCyclicBuffer[kpi_localBuff_startIdx[KPI_Cfg_idx]]
                  .KPIMessage.DeltaKPI = KPI_TimeDiff_L1;
            }
            else
            {
              KPI_TimeDiff_L1 =
                  (uint32)(DltExt_KpiCyclicBuffer
                               [kpi_localBuff_headIdx[KPI_Cfg_idx]]
                                   .KPIMessage.DeltaKPI +
                           DltExt_KpiCyclicBuffer
                               [kpi_localBuff_headIdx[KPI_Cfg_idx] + 1u]
                                   .KPIMessage.DeltaKPI);
              DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx] + 1u]
                  .KPIMessage.DeltaKPI = KPI_TimeDiff_L1;
            }
          }

          DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]]
              .KPIMessage.DeltaKPI = KPI_TimeDiff_L;

          LastKPITimestamp[KPI_Cfg_idx] = KPIMessage_l.KPI_Timestamp;
          if (FirstKPITimestamp[KPI_Cfg_idx] == 0u)
          {
            FirstKPITimestamp[KPI_Cfg_idx] = KPIMessage_l.KPI_Timestamp;
          }
        }

        DltExt_KpiCyclicBuffer[kpi_localBuff_headIdx[KPI_Cfg_idx]].ValidFlag = TRUE;

        /* Incrementing the Pointer */
        kpi_localBuff_headIdx[KPI_Cfg_idx]++;

        if (kpi_localBuff_headIdx[KPI_Cfg_idx] == (kpi_localBuff_startIdx[KPI_Cfg_idx] +
                                                   vKPIData_Cfg[KPI_Cfg_idx]
                                                       .Kpi_Buffer_Size)) /*Rollover if the head index reaches max
                                                                         length*/
        {
          kpi_localBuff_headIdx[KPI_Cfg_idx] = kpi_localBuff_startIdx[KPI_Cfg_idx];
        }

        DltExtRetVal = DLT_E_OK;
      }
    }
    else
    {
      DltExtRetVal = DLT_E_OK;
    }
  }

  return DltExtRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   DltExt_UclMessageHandling
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)

static Std_ReturnType DltExt_UclMessageHandling(uint16 DltextMessage_Id,
                                                uint32 DltExtTimestamp,
                                                const uint8 *pBuffer)
{
  Dlt_ReturnType DltExtRetValue = DLT_E_NOT_OK;
  uint8 FaultCategory = (uint8)(((DltextMessage_Id >> 8) & 0xffu));
  G_Cfg_Fault_index = DltExt_Search_Fault_category(FaultCategory);
  if (G_Cfg_Fault_index != DLT_E_NOT_OK)
  {
    if (App_error_Catagory[G_Cfg_Fault_index].UCL_Transport_Configuration ==
        TRUE) /*Checking for Configuration enabled or no */
    {
      if (((G_LocalBuff_TailPtr + 1u) % DLTEXT_ADDITIONAL_RESET_INFO_SIZE) !=
          G_LocalBuff_headPtr) /* condition to check Buffer is Full */
      {
        MemLib_MemCpy(&DltExt_UclDataBuffer[G_LocalBuff_TailPtr].Message_ID,
                      &DltextMessage_Id,
                      2); /*Copying of data in the local buffer*/
        MemLib_MemCpy(&DltExt_UclDataBuffer[G_LocalBuff_TailPtr].Time_Stamp,
                      &DltExtTimestamp,
                      4);
        MemLib_MemCpy(&DltExt_UclDataBuffer[G_LocalBuff_TailPtr].Addon_LogData,
                      pBuffer,
                      6);
        DltExt_UclDataBuffer[G_LocalBuff_TailPtr].Valid_Flag = TRUE; /*Check for validity flag*/
        G_LocalBuff_TailPtr = (uint8)((G_LocalBuff_TailPtr + 1u) %
                                      DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
      }
      else
      {
        /*Do Nothing*/
      }
    }
    else
    {
      DltExtRetValue = DLT_E_NOT_OK;
    }
  }
  else
  {
    DltExtRetValue = DLT_E_NOT_OK;
  }
  return DltExtRetValue;
}

/*============================================================================
**
** Function Name    :   DltExt_Ucl_MessageCounter
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static void DltExt_Ucl_MessageCounter(void)
{
  if (DltExt_Ucl_MessageCount == MAX_UCL_MSG_COUNT_VALUE)
  {
    DltExt_Ucl_MessageCount = MAX_MSG_COUNT_RESET;
  }
  else
  {
    (DltExt_Ucl_MessageCount++); /* Message counter increment*/
  }
}
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   Search_KPI_Cfg
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static uint8 Search_KPI_Cfg(uint16 eErrorCode)
{
  uint8 head_Kpi = 0u;
  uint8 tail_Kpi = DLTEXT_NUM_KPI - 1u;
  uint8 mid_Kpi = 0u;
  uint8 Return_Val = DLT_E_NOT_OK;

  while (head_Kpi <= tail_Kpi)
  {
    mid_Kpi = (head_Kpi + (uint8)((uint8)(tail_Kpi - head_Kpi) / 2u));
    if ((DLTEXT_NUM_KPI > mid_Kpi) &&
        (vKPIData_Cfg[mid_Kpi].Kpi_FaultCode == eErrorCode))
    {
      Return_Val = mid_Kpi;
      break;
    }
    if (head_Kpi != tail_Kpi)
    {
      /*If greater, ignore left half*/
      if ((DLTEXT_NUM_KPI > mid_Kpi) &&
          ((vKPIData_Cfg[mid_Kpi].Kpi_FaultCode) < eErrorCode))
      {
        head_Kpi = mid_Kpi + 1u;
      }

      /*If smaller, ignore right half*/
      else
      {
        tail_Kpi = mid_Kpi - 1u;
      }
    }
    else
    {
      break;
    }
  }

  return Return_Val;
}
#endif

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   DltExt_Search_Fault_category
**
** Visibility       :   static
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static uint8 DltExt_Search_Fault_category(uint8 FaultCategory)
{
  uint8 head_fault = 0u;
  uint8 tail_fault = NUM_TYPE_CODES - 1u;
  uint8 mid_fault = 0u;
  uint8 Return_Val = DLT_E_NOT_OK;
  while (head_fault <= tail_fault)
  {
    mid_fault = (head_fault + (uint8)((uint8)(tail_fault - head_fault) / 2u));

    if ((NUM_TYPE_CODES > mid_fault) &&
        (App_error_Catagory[mid_fault].Fault_Category == FaultCategory))
    {
      Return_Val = mid_fault;
      break;
    }

    if (head_fault != tail_fault)
    {
      /*If greater, ignore left half*/
      if ((NUM_TYPE_CODES > mid_fault) &&
          ((App_error_Catagory[mid_fault].Fault_Category) < FaultCategory))
      {
        head_fault = mid_fault + 1u;
      }
      /*If smaller, ignore right half*/
      else
      {
        tail_fault = mid_fault - 1u;
      }
    }
    else
    {
      Return_Val = DLT_E_NOT_OK;
      break;
    }
  }
  return Return_Val;
}
/*============================================================================
**
** Function Name    :   DltExt_MemCpy
**
** Visibility       :   static
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static void DltExt_MemCpy(uint8 *DPtr, uint32 Val, uint8 length)
{
  if (length == 2u)
  {
    *DPtr = (uint8)((Val & 0xFF00u) >> 8u);
    DPtr++;
    *DPtr = (uint8)(Val & 0xffu);
  }
  else if (length == 4u)
  {
    *DPtr = (uint8)((Val & 0xFF000000u) >> 24u);
    DPtr++;
    *DPtr = (uint8)((Val & 0x00FF0000u) >> 16u);
    DPtr++;
    *DPtr = (uint8)((Val & 0x0000FF00u) >> 8u);
    DPtr++;
    *DPtr = (uint8)(Val & 0x000000FFu);
  }
  else
  {
    // do nothing
  }
}
/*============================================================================
**
** Function Name    :   DltExt_UclTransmission
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static void DltExt_UclTransmission(void)
{
#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  uint16 L_KPIExpectedValue = 0u;
  uint32 L_Timestamp_local = 0u;
  uint8 L_WholeExpected = 0u;
  uint8 L_DecimalExpected = 0u;
  uint8 L_Timestamp_Whole = 0u;
  uint8 L_Timestamp_Decimal = 0u;
  uint32 L_Delta_KPI = 0u;
  uint32 L_Delta_KPI_Whole = 0u;
  uint32 L_Delta_KPI_Decimal = 0u;
  uint8 L_metrics_idx = 0u;
  uint8 tail_idx = 0u;
#endif
  SDmnStatus GIPAppStatus = { 0 };
  uint8 BufferReady = NO_EVENT_PRESENT;

  /* Getting UCL Up status */
  (void)DltExt_DmnMgr_SDmnStatus(&GIPAppStatus);

  if (GIPAppStatus.linkStatus == UclLinkStateL_Up) /* Checking UCL Up Status */
  {
    /*Check for any Fault Code data to be sent over UCL*/
    if (DltExt_UclDataBuffer[G_LocalBuff_headPtr].Valid_Flag ==
        TRUE) /*Check for Valid Flag to check if the UCL message is Sent ToDo */
    {
      if (G_LocalBuff_headPtr !=
          G_LocalBuff_TailPtr) /* check for G_LocalBuff_headPtr is not equal to
                                  G_LocalBuff_TailPtr*/
      {
        /* Clear only the payload array, not the entire struct (prevents overwrite) */
        MemLib_MemSet(&DltExt_LogDataBasedOnLogEventTx.data[0], 0x00u, (uint32)sizeof(DltExt_LogDataBasedOnLogEventTx.data));
        (void)DltExt_Ucl_MessageCounter();
        if (G_LocalBuff_headPtr < DLTEXT_ADDITIONAL_RESET_INFO_SIZE)
        {
          /*Copying the Data From Buffer to Local Variables to For Transmitting
           * via UCL */
          DltExt_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[0],
                        (uint32)DltExt_Ucl_MessageCount,
                        2);
          DltExt_MemCpy(
              &DltExt_LogDataBasedOnLogEventTx.data[2],
              (uint32)DltExt_UclDataBuffer[G_LocalBuff_headPtr].Message_ID,
              2);
          DltExt_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[4],
                        DltExt_UclDataBuffer[G_LocalBuff_headPtr].Time_Stamp,
                        4);
          MemLib_MemCpy(
              &DltExt_LogDataBasedOnLogEventTx.data[8],
              &DltExt_UclDataBuffer[G_LocalBuff_headPtr].Addon_LogData,
              6);
          /* Making Valid Flag as false After Transmitting the Message */
          DltExt_UclDataBuffer[G_LocalBuff_headPtr].Valid_Flag = FALSE;
        }
        /* Incrementing the head pointer and Roll over handling */
        G_LocalBuff_headPtr = (G_LocalBuff_headPtr + 1u) % DLTEXT_ADDITIONAL_RESET_INFO_SIZE;
        /* Buffer is populated */
        BufferReady = LOG_EVENT;
      }
    }
    else
    {
#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
      for (tail_idx = 0u; tail_idx < DLTEXT_MAX_KPIBUF_LEN; tail_idx++)
      {
        if (DltExt_KpiCyclicBuffer[tail_idx].ValidFlag == TRUE)
        {
          MemLib_MemSet(&DltExt_LogDataBasedOnLogEventTx.data[0], 0x00u, (uint32)sizeof(DltExt_LogDataBasedOnLogEventTx.data));
          (void)DltExt_Ucl_MessageCounter();
          DltExt_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[0],
                        (uint32)DltExt_Ucl_MessageCount,
                        2u);
          DltExt_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[2],
                        (uint32)DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_MessageID,
                        2u);
          DltExt_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[4],
                        DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Timestamp,
                        4u);
          DltExt_LogDataBasedOnLogEventTx.data[8] =
              DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.Faultstatus;
          DltExt_LogDataBasedOnLogEventTx.data[14] =
              DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Varible;

          if (KPI_Cfg_idx < DLTEXT_NUM_KPI)
          {
            L_Timestamp_local = DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Timestamp;
            L_Timestamp_Whole = (uint8)(L_Timestamp_local / 1000u);
            L_Timestamp_Decimal = (uint8)((L_Timestamp_local % 1000u) / 10u);

            if (vKPIData_Cfg[KPI_Cfg_idx].tDltExt_DiffOrMetricsEn == (uint8)DLTEXT_KPITYPE_NORMAL)
            {
              MemLib_MemCpy(&DltExt_LogDataBasedOnLogEventTx.data[9],
                            &DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Snapshot,
                            KPI_Message_Len);
              BufferReady = KPI_EVENT;
              DltExt_KpiCyclicBuffer[tail_idx].ValidFlag = FALSE;
              break;
            }
            else if (vKPIData_Cfg[KPI_Cfg_idx].tDltExt_DiffOrMetricsEn == (uint8)DLTEXT_KPITYPE_TIMEDIFF)
            {
              L_Timestamp_local =
                  DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Timestamp -
                  FirstKPITimestamp[KPI_Cfg_idx];
              L_Timestamp_Whole = (uint8)(L_Timestamp_local / 1000u);
              L_Timestamp_Decimal = (uint8)((L_Timestamp_local % 1000u) / 10u);

              L_Delta_KPI = DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.DeltaKPI;
              L_Delta_KPI_Whole = (uint8)(L_Delta_KPI / 1000u);
              L_Delta_KPI_Decimal = (uint8)((L_Delta_KPI % 1000u) / 10u);

              DltExt_LogDataBasedOnLogEventTx.data[9] = (uint8)L_Timestamp_Whole;
              DltExt_LogDataBasedOnLogEventTx.data[10] = (uint8)L_Timestamp_Decimal;
              DltExt_LogDataBasedOnLogEventTx.data[11] = (uint8)L_Delta_KPI_Whole;
              DltExt_LogDataBasedOnLogEventTx.data[12] = (uint8)L_Delta_KPI_Decimal;

              BufferReady = KPI_EVENT;
              DltExt_KpiCyclicBuffer[tail_idx].ValidFlag = FALSE;
              break;
            }
            else if (vKPIData_Cfg[KPI_Cfg_idx].tDltExt_DiffOrMetricsEn == (uint8)DLTEXT_KPITYPE_METRICS)
            {
              for (L_metrics_idx = 0u; L_metrics_idx < DLTEXT_NUM_KPI_METRIC; L_metrics_idx++)
              {
                if ((KPI_Metrix_Cfg[L_metrics_idx].Message_Kpi ==
                     DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_MessageID) &&
                    (KPI_Metrix_Cfg[L_metrics_idx].Variable_Kpi ==
                     DltExt_KpiCyclicBuffer[tail_idx].KPIMessage.KPI_Varible))
                {
                  L_KPIExpectedValue = KPI_Metrix_Cfg[L_metrics_idx].Expected_Kpi;
                  DltExt_KpiCyclicBuffer[tail_idx].ValidFlag = FALSE;
                  break;
                }
              }

              L_WholeExpected = (uint8)(L_KPIExpectedValue >> 8);
              L_DecimalExpected = (uint8)(L_KPIExpectedValue & 0xFFu);
              DltExt_LogDataBasedOnLogEventTx.data[9] = L_WholeExpected;
              DltExt_LogDataBasedOnLogEventTx.data[10] = L_DecimalExpected;
              DltExt_LogDataBasedOnLogEventTx.data[11] = L_Timestamp_Whole;
              DltExt_LogDataBasedOnLogEventTx.data[12] = L_Timestamp_Decimal;

              BufferReady = KPI_EVENT;
              DltExt_KpiCyclicBuffer[tail_idx].ValidFlag = FALSE;
              break;
            }
            else
            {
              /* Do Nothing */
            }
          }
        }
      }
#endif
    }
  }

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  if ((BufferReady == LOG_EVENT) || (BufferReady == KPI_EVENT))
#else
  if (BufferReady == LOG_EVENT)
#endif
  {
    (void)DltExt_Ucl_LogDataBasedOnLogEventData(
        &DltExt_LogDataBasedOnLogEventTx);
  }
  else
  {
    /*Do Nothing*/
  }
}
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */

/* -------------------------------------------------------------------------
 * Build a DLT verbose ResetReplay frame into dst buffer using:
 *   - StdHdr/ExtHdr from payLoadHeader
 *   - ResetCode + AdditionalInfo from history entry (WITHOUT timestamp)
 *   - Patch DLT StdHdr timestamp using the history timestamp
 * ------------------------------------------------------------------------*/
static uint16 DltExt_BuildResetReplayFrame(uint8 *dst, uint16 dstSize, const uint8 *stdHdr, uint16 stdHdrLen)
{
  const uint8 *flResetHistory;
  uint8 payload[DLTEXT_ADDITIONAL_RESET_INFO_SIZE];
  uint16 payloadLen;
  uint16 totalLen;
  uint16 tailOffset;
  uint16 tailLen;
  uint32 HistoryTimeStamp;

  /* Entry 0 = most recent reset */
  flResetHistory = &DltExt_ResetLogDataBuffer.code[0][0];

  /* ----------------------------- Extract ResetCode ----------------------- */
  payload[0] = flResetHistory[0];
  payload[1] = flResetHistory[1];

  /* Timestamp is at bytes [2..5], we REMOVE IT from payload */
  tailOffset = 6U; /* 0..1 ResetCode, 2..5 Timestamp => next is 6 */

  if (tailOffset > DLTEXT_ADDITIONAL_RESET_INFO_SIZE)
  {
    return 0U;
  }

  tailLen = (uint16)(DLTEXT_ADDITIONAL_RESET_INFO_SIZE - tailOffset);

  /* Copy additional info (post-timestamp) */
  MemLib_MemCpy(&payload[2], &flResetHistory[tailOffset], tailLen);

  payloadLen = (uint16)(2U + tailLen); /* ResetCode + tail */

  /* ---------------------- Build full DLT verbose message ---------------- */
  totalLen = DltExt_BuildVerboseFrame(dst, dstSize, stdHdr, stdHdrLen, payload, payloadLen);
  if (totalLen == 0U)
  {
    return 0U;
  }

  /* ---------------------- Patch timestamp in DLT header ------------------ */
  HistoryTimeStamp = ((uint32)flResetHistory[2] << 24U);
  HistoryTimeStamp |= ((uint32)flResetHistory[3] << 16U);
  HistoryTimeStamp |= ((uint32)flResetHistory[4] << 8U);
  HistoryTimeStamp |= (uint32)flResetHistory[5];

  /* Timestamp is always at offset 12..15 in DLT StdHdr */
  dst[12] = (uint8)(HistoryTimeStamp >> 24U);
  dst[13] = (uint8)(HistoryTimeStamp >> 16U);
  dst[14] = (uint8)(HistoryTimeStamp >> 8U);
  dst[15] = (uint8)HistoryTimeStamp;

  return totalLen;
}

/*============================================================================
**
** Function Name    :   DltExt_SendLogMessage
**
** Visibility       :   Public
**
** Description      :   Extension hook called by Dlt whenever a log message
**                      shall be sent. This function:
**                        - extracts FaultCode / KPI payload
**                        - optionally mirrors to UART
**                        - optionally builds AUTOSAR verbose payload
**                        - routes the final DLT frame either to:
**                            * ResetInfo shared buffer (for reset history), or
**                            * AppInfo Bank A/B shared memory (runtime logs)
**                        - updates local NVM / counters using DltExt_Report()
**
**==========================================================================*/

Std_ReturnType DltExt_SendLogMessage(uint8 *payLoadHeader, uint8 *payLoad, uint16 payLoadHeaderLength, uint16 payLoadLength, uint8 logLevel)
{
  (void)payLoadHeaderLength;
  Dlt_ReturnType DltExtRetVal = DLT_E_NOT_OK;
  uint16 FaultCode;
  const uint8 *FaultData = NULL_PTR;
#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  uint8 KPIFaultData = 0U;
#endif
  uint16 messageLen = 0U;
  uint8 byteIdx = 12U;
  uint32 DltExt_Timestamp = 0U;
  uint8 faultCategory;
#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
  /* Local staging buffer to build one complete DLT frame (StdHdr + ExtHdr +
 * Payload) */
  static uint8 DltExt_AppInfo_TempBuffer[DLT_EXT_APPLOG_SHAREMEM_SIZE];
#endif

  /* Basic payload sanity check */
  if ((payLoadHeader == NULL_PTR) || (payLoad == NULL_PTR))
  {
    return DLT_E_NOT_OK;
  }

  if (payLoadLength == 0U)
  {
    /* Nothing to process */
    return DLT_E_NOT_OK;
  }

  faultCategory = payLoad[0U];

  /* Message category based filtering */
  DltExtRetVal = DltExt_MessageFiltering(faultCategory);

  if (DltExtRetVal == DLT_E_OK)
  {
#if (DLTEXT_UART_PRINT == STD_ON)
    /* Mirror raw payload on UART for debugging (non-safety relevant) */
    (void)DltExt_Uart_SendHex(eSciDrvAsyncMode_Polling, payLoad, payLoadLength, "\r\nDLT Fault logged");
#endif

#if (DLT_HEADERUSETIMESTAMP == STD_ON)
    {
      uint32 timeStamp;

      /* Timestamp is encoded in StdHdr at byteIdx..byteIdx+3, big-endian */
      timeStamp = ((uint32)payLoadHeader[byteIdx + 0U] << 24U);
      timeStamp |= ((uint32)payLoadHeader[byteIdx + 1U] << 16U);
      timeStamp |= ((uint32)payLoadHeader[byteIdx + 2U] << 8U);
      timeStamp |= ((uint32)payLoadHeader[byteIdx + 3U]);

      DltExt_Timestamp = timeStamp;
    }
#else
    DltExt_Timestamp = 0U;
#endif /* DLT_HEADERUSETIMESTAMP == STD_ON */

    /* 2 bytes of FaultCode at beginning of payload */
    if (payLoadLength >= 2U)
    {
      messageLen = (uint16)(payLoadLength - 2U);

      FaultCode = (uint16)(((uint16)payLoad[0U] << 8U) | (uint16)payLoad[1U]);

      /* --------------------------------------------------------------------
       * KPI LOG HANDLING
       * ------------------------------------------------------------------*/
#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
      if ((FaultCode & FAULT_CODE_MASK) == DLTEXT_KPITYPECODE)
      {
        if (messageLen >= 1U)
        {
          uint16 flKPI_Message_Len;

          KPIFaultData = payLoad[2U];

          if (messageLen > 1U)
          {
            flKPI_Message_Len = (uint16)(messageLen - 1U);
            FaultData = &payLoad[3U];
          }
          else
          {
            flKPI_Message_Len = 0U;
            FaultData = NULL_PTR;
          }

          DltExtRetVal = DltExt_KpiBufferHandling(FaultCode,
                                                  DltExt_Timestamp,
                                                  KPIFaultData,
                                                  logLevel,
                                                  FaultData,
                                                  flKPI_Message_Len);
        }
        else
        {
          DltExtRetVal = DLT_E_NOT_OK;
        }
      }
      else
#endif
      {
        /* ------------------------------------------------------------------
         * NORMAL FAULT LOG HANDLING (including ResetReplay special case)
         * ----------------------------------------------------------------*/
#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
        {
          uint16 totalLen = 0U;

          /* ------------- RESET HISTORY LOG PATH (ResetReplay) -------------
           * Detect APID/CTID that represent reset history.
           * For this special message, we:
           *   - Build dedicated verbose frame from reset history buffer
           *   - Strip timestamp from payload
           *   - Patch DLT StdHdr timestamp from history entry
           *   - Write ONLY into ResetInfo shared buffer
           *   - Trigger UCL once (DLTEXT_SHAREMEMRESETBUF)
           *   - Do NOT touch Bank A/B here
           */
          if (DltExt_IsResetHistoryLog(payLoadHeader, payLoadHeaderLength) == TRUE)
          {
            uint16 resetFrameLen;

            uint8 DltExt_ResetFrameBuffer[DLTEXT_SIZE_256BYTES] = { 0U };

            resetFrameLen = DltExt_BuildResetReplayFrame(&DltExt_ResetFrameBuffer[0],
                                                         (uint16)DLTEXT_SIZE_256BYTES,
                                                         payLoadHeader,
                                                         payLoadHeaderLength);

            if (resetFrameLen > 0U)
            {
              if (DltExt_Ipc_PushVipResetFrame(&DltExt_ResetFrameBuffer[0], resetFrameLen) == E_OK)
              {
                DltExt_ResetPending = 2U; /* Sent, waiting for ACK */
              }
              else
              {
                /* UCL busy: MainFunction will retry when idle */
                DltExt_ResetPending = 1U;
              }
            }
            /* In all cases for reset-log, we do not go to Bank A/B */
            return E_OK;
          }

          /* ------------- NORMAL RUNTIME LOG PATH -------------
           * Not a reset history message → treat as regular app log.
           * Build verbose (or non-verbose) frame into AppInfo_TempBuffer
           * and feed it to Bank A/B shared memory.
           */
#if (DLT_USEVERBOSEMODE == STD_ON)
          /* AUTOSAR verbose:
           * Build [StdHdr][ExtHdr][TypeInfo][RawPayload data] into temp buffer.
           */
          totalLen = DltExt_BuildVerboseFrame(&DltExt_AppInfo_TempBuffer[0], (uint16)DLT_EXT_APPLOG_SHAREMEM_SIZE, payLoadHeader, payLoadHeaderLength, payLoad, payLoadLength);
#else
          /* Non-verbose fallback: StdHdr + ExtHdr + raw payload */
          totalLen = (uint16)(payLoadHeaderLength + payLoadLength);

          if (totalLen <= (uint16)DLT_EXT_APPLOG_SHAREMEM_SIZE)
          {
            MemLib_MemCpy(&DltExt_AppInfo_TempBuffer[0], payLoadHeader, payLoadHeaderLength);
            MemLib_MemCpy(&DltExt_AppInfo_TempBuffer[payLoadHeaderLength], payLoad, payLoadLength);
          }
          else
          {
            /* Too large for one bank; drop */
            totalLen = 0U;
          }
#endif /* DLT_USEVERBOSEMODE == STD_ON */

          if (totalLen > 0U)
          {
            (void)DltExt_Ipc_PushVipAppFrame(&DltExt_AppInfo_TempBuffer[0], totalLen);
          }
        }
#endif /* DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON */

        /* Prepare pointer to additional fault data for NVM/reporting */
        if (messageLen > 0U)
        {
          FaultData = &payLoad[2U];
        }
        else
        {
          FaultData = NULL_PTR;
        }

        DltExtRetVal = DltExt_Report(FaultCode, DltExt_Timestamp, FaultData, logLevel, messageLen);

#if (DLTEXT_CFG_DIRECT_UCL_TX_PRESENT == STD_ON)
        (void)DltExt_UclMessageHandling(FaultCode, DltExt_Timestamp, &FaultData[0U]);
#endif /* DLTEXT_CFG_DIRECT_UCL_TX_PRESENT */
      }
    }
    else
    {
      /* Not enough bytes for FaultCode; drop */
      DltExtRetVal = DLT_E_NOT_OK;
    }
  }
  else
  {
    /* Filtered out – nothing to do */
  }

  return DltExtRetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_GetTimeStamp
**
** Visibility       :   Public
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
uint32 DltExt_GetTimeStamp(void)
{
  uint32 lTSR;
  uint32 hTSR;
  uint64 fullTicks;
  uint32 msTime;
  /* Ensure atomic read of 64-bit GTC counter */
  SuspendAllInterrupts();
  /* Read low and high 32-bit counters */
  lTSR = *(volatile const uint32 *)(0x00A90008u);
  hTSR = *(volatile const uint32 *)(0x00A9000Cu);
  ResumeAllInterrupts();
  /* Combine to 64-bit timestamp */
  fullTicks = (((uint64)hTSR << 32) | (uint64)lTSR);
  /* Convert GTC cycles → milliseconds
   * GTC = 200 MHz → 1 cycle = 5 ns
   * 1 ms = 200,000 cycles
   */
  msTime = (uint32)(fullTicks / 200000u);
  /* Add offset if required (same behavior as PMICCDD) */
  msTime += DLTEXT_POWERUP_OFFSET;
  return msTime;
}

static Dlt_ReturnType DltExt_MessageFiltering(uint8 falutCategory)
{
  Dlt_ReturnType DltExtRetVal = DLT_E_NOT_OK;
  uint32 ReceivedCategory = 0U;

  switch (falutCategory) /* Checking Fault category */
  {
  case DLT_APPLICATION_INFO:
    ReceivedCategory = 0x2U;
    break;

  case DLT_APPLICATION_ERROR:
    ReceivedCategory = 0x4U;
    break;

  case DLT_FAULT_FORCED_RESET:
    ReceivedCategory = 0x8U;
    break;

  case DLT_FAULT_ARM_ERROR:
    ReceivedCategory = 0x10U;
    break;

  case DLT_FAULT_NVM_ERROR:
    ReceivedCategory = 0x20U;
    break;

  case DLT_FAULT_HW_RESET:
    ReceivedCategory = 0x40U;
    break;

  case DLT_FAULT_OS_ERROR:
    ReceivedCategory = 0x80U;
    break;

#if (DLTEXT_CFG_KPI_PRESENT == STD_ON)
  case DLT_KPI_CATEGORY:
    ReceivedCategory = 0x100U;
    break;
#else
  case DLT_KPI_CATEGORY:
    ReceivedCategory = 0U;
    break;
#endif

  case DLT_GROUP_MSG:
    ReceivedCategory = 0x100U;
    break;

  case DLT_RESET_DATA1:
    ReceivedCategory = 0x100U;
    break;

  case DLT_RESET_DATA2:
    ReceivedCategory = 0x100U;
    break;

  case DLT_FEATURE_STATUS:
    ReceivedCategory = 0x100U;
    break;

  default:
    ReceivedCategory = 0U;
    break;
  }

  if (ReceivedCategory != 0U) /* Filtering Based On Category */
  {
    DltExtRetVal = DLT_E_OK;
  }
  else
  {
    DltExtRetVal = DLT_E_NOT_OK;
  }

  return DltExtRetVal;
}
/*============================================================================
**
** Function Name    :   DltExt_BlockWriteOnException
**
** Visibility       :   Public
**
** Description      :   The DltExt_ResetLogDataStatus function is called to
* know if the message is
**                      critical or non-critical.
**
** Invocation       :
**
** Inputs           : Log_Level
**
** Outputs          : boolean ResetLogData_Flag
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_BlockWriteOnException(uint16 NvBlockId_u16)
{
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_OFF)
  (void)NvBlockId_u16;
  return;
#else
  uint16 NvLength_u16;
  uint16 Crc16_u16 = 0xFFFFU;
  // uint8 *SrcPtr_p;
  // uint8 *DestPtr_p;
  // uint32 fl_temp_u32;
  uint16 Crc_length_16;
  // uint8 BlockWriteDataArray_RD_au8[30u]; /*Block dependent parameter*/
  Boolean first_Occurrence_b = TRUE;
  const uint8 *Crc_DataPtr = NvM_BlockConfig[NvBlockId_u16].RamBlockDataAddress;

  NvLength_u16 = NvM_BlockConfig[NvBlockId_u16].NvBlockLength;
  // MemLib_MemSet(&BlockWriteDataArray_RD_au8, 0, sizeof(uint8) *
  // (uint8)30u);
#if (DLTEXT_PLATFORM_NOT_FEE_NvM == STD_ON)
  uint8 EepDrvBuf_au8[255u];
  uint16 Ea_blockindex_u16;
  uint8 SlaveAddress;
  uint16 PhyEepAddr_u16;
  uint8 *ClientPtr_p;
  uint8 Channel_Id;
  uint16 Crc_lengthTemp_16;
  uint8 loopVariable_u8 = (uint8)1u;
  Channel_Id = (uint8)0u; /* Corresponding Channel ID for EEPROM Channel is
                             passed here */
  SlaveAddress = (uint8)0xA0u;
  uint8 blockCount_u8 = (uint8)0U;
  I2c_StatusType I2cStatus = I2C_CH_ERROR_PRESENT;

  I2cStatus = I2c_GetStatus(EEP24XX_WRITE_CHANNEL);

  if (I2C_BUSY == I2cStatus)
  {
    /**Reinitializing I2C registers to avoid conflicts with existing
     * transmissions**/
    I2c_DeInit();
    I2c_Init(&I2c_Config);
  }
  else
  {
    /* do nothing*/
  }

  /**Calculate CRC**/
  Crc_lengthTemp_16 = NvLength_u16;
  while (loopVariable_u8)
  {
    if (Crc_lengthTemp_16 > NVM_CRC_CALC_MAX_LEN)
    {
      Crc_lengthTemp_16 -= NVM_CRC_CALC_MAX_LEN;
      Crc_length_16 = NVM_CRC_CALC_MAX_LEN;
    }
    else
    {
      loopVariable_u8 = (uint8)0u;
      Crc_length_16 = Crc_lengthTemp_16;
    }
    Crc16_u16 = Crc_CalculateCRC16(Crc_DataPtr, Crc_length_16, Crc16_u16, first_Occurrence_b);
    Crc_DataPtr += Crc_length_16;
    first_Occurrence_b = FALSE;
  }
  /* Append data with CRC*/
  BlockWriteDataArray_RD_au8[NvLength_u16 + 2u] = (uint8)(Crc16_u16 & 0x000000FF);
  BlockWriteDataArray_RD_au8[NvLength_u16 + 3u] = (uint8)((Crc16_u16 & 0x0000FF00) >> 8u);
  /*Ea Header 1*/
  BlockWriteDataArray_RD_au8[0u] = (uint8)(INSTANCE_COUNTER1 << 1u);
  /*Ea Header 2*/
  BlockWriteDataArray_RD_au8[1u] = (uint8)(~BlockWriteDataArray_RD_au8[0u]);

  /*Pack Payload*/
  SrcPtr_p = NvM_BlockConfig[NvBlockId_u16].RamBlockDataAddress;
  DestPtr_p = &BlockWriteDataArray_RD_au8[2u];
  for (fl_temp_u32 = 0u; fl_temp_u32 < (NvLength_u16); fl_temp_u32++)
  {
    *DestPtr_p = *SrcPtr_p;
    DestPtr_p++;
    SrcPtr_p++;
  }

  /*Checking the block type*/
  if (NVM_REDUNDANT_BLOCK == NvM_BlockConfig[NvBlockId_u16].BlockManagementType)
  {
    blockCount_u8 = (uint8)2u;
  }
  else
  {
    blockCount_u8 = (uint8)1u;
  }
  Ea_blockindex_u16 = NvM_BlockConfig[NvBlockId_u16].NvBlockBaseNumber - 1;

  /* Loop continues until all the blocks are loaded with data*/
  while (blockCount_u8 > (uint8)0u)
  {
    blockCount_u8--;
    PhyEepAddr_u16 = Ea_Config[Ea_blockindex_u16].BlockBaseAddress;
    RemainingBytes_u16 = NvLength_u16 + 4u;
    ClientPtr_p = &BlockWriteDataArray_RD_au8[0u];

    /* Loop continues until single block write is complete*/
    while (RemainingBytes_u16 > 0u)
    {
      memset(&EepDrvBuf_au8, 0, sizeof(uint8) * 32u);
      EepDrvBuf_au8[0u] = (PhyEepAddr_u16 >> 8u) & 0x00FF;
      EepDrvBuf_au8[1u] = PhyEepAddr_u16 & 0x00FF;
      // /*Calculating writable maximum length*/
      WriteLength_u16 = (32u - (PhyEepAddr_u16 & (31u)));

      if (WriteLength_u16 > RemainingBytes_u16) // length with Ea headers
      {
        WriteLength_u16 = RemainingBytes_u16;
      }
      MemLib_MemCpy((uint8 *)(&EepDrvBuf_au8[2]), ClientPtr_p, WriteLength_u16);
      /*Transmit data*/
      NvmExt_I2c_SetupEB(&EepDrvBuf_au8[0], (WriteLength_u16 + 2), SlaveAddress);
      I2c_SyncTransmit(Channel_Id, &I2cRequestData);
      /*Calculate attributes for next page write*/
      RemainingBytes_u16 -= WriteLength_u16;
      PhyEepAddr_u16 += WriteLength_u16;
      ClientPtr_p += WriteLength_u16;
      // /* Wait timer for next sector write in eeprom */
      DltExt_NvmDELAY();
    }
    Ea_blockindex_u16++;
    /*Ea Header 1*/
    BlockWriteDataArray_RD_au8[0u] = (uint8)(INSTANCE_COUNTER2 << 1u);
    /*Ea Header 2*/
    BlockWriteDataArray_RD_au8[1u] = (uint8)(~BlockWriteDataArray_RD_au8[0u]);
  }

#elif (DLTEXT_PLATFORM_FEE_NvM == STD_ON)

  uint16 SNvMBlockId_u16 = 0u;

  if (Fls_GetStatusSub() != MEMIF_JOB_OK)
  {
    /**Reinitializing I2C registers to avoid conflicts with existing
     * transmissions**/
    Fls_Cancel();
    // I2c_Init(&I2c_Config);
  }
  else
  {
    /* do nothing*/
  }

  /*copy nvm Rambuffer*/
  SrcPtr_p = NvM_BlockConfig[NvBlockId_u16].RamBlockDataAddress;
  DestPtr_p = &BlockWriteDataArray_RD_au8[0u];
  for (fl_temp_u32 = 0u; fl_temp_u32 < (NvLength_u16); fl_temp_u32++)
  {
    *DestPtr_p = *SrcPtr_p;
    DestPtr_p++;
    SrcPtr_p++;
  }
  /**Calculate CRC**/
  Crc_length_16 = NvLength_u16;
  Crc16_u16 = Crc_CalculateCRC16(Crc_DataPtr, Crc_length_16, Crc16_u16, first_Occurrence_b);

  /* Append the CRC value before writing the data */
  BlockWriteDataArray_RD_au8[NvLength_u16] = (uint8)(Crc16_u16 & 0x000000FFU);
  BlockWriteDataArray_RD_au8[NvLength_u16 + 1u] = (uint8)((Crc16_u16 & 0x0000FF00U) >> 8u);
  BlockWriteDataArray_RD_au8[NvLength_u16 + 2u] = 0x00u;
  BlockWriteDataArray_RD_au8[NvLength_u16 + 3u] = 0x00u;
  /*sNvM write*/
  SNvMBlockId_u16 = NvM_BlockConfig[NvBlockId_u16].NvBlockBaseNumber;
  (void)SNvM_Write(SNvMBlockId_u16, BlockWriteDataArray_RD_au8);
  DltExt_StartTimer();
  do
  {
    SNvM_MainFunction();
    Fls_MainFunction();
  } while ((Fls_GetStatusSub() != MEMIF_JOB_OK) ||
           ((uint8)E_NOT_OK ==
            DltExt_IsTimerElapsed(DLTEXT_ONEXCEPTION_TIMEOUT_US)));

#elif (DLTEXT_PLATFORM_USE_SPI == STD_ON)
  uint16 Crc_lengthTemp_16;
  uint8 loopVariable_u8 = (uint8)1u;
  /**Calculate CRC**/
  Crc_lengthTemp_16 = NvLength_u16;
  while (loopVariable_u8)
  {
    if (Crc_lengthTemp_16 > NVM_CRC_CALC_MAX_LEN)
    {
      Crc_lengthTemp_16 -= NVM_CRC_CALC_MAX_LEN;
      Crc_length_16 = NVM_CRC_CALC_MAX_LEN;
    }
    else
    {
      loopVariable_u8 = (uint8)0u;
      Crc_length_16 = Crc_lengthTemp_16;
    }
    Crc16_u16 = Crc_CalculateCRC16(Crc_DataPtr, Crc_length_16, Crc16_u16, first_Occurrence_b);
    Crc_DataPtr += Crc_length_16;
    first_Occurrence_b = FALSE;
  }
  DLT_WriteDataToNvM(NvBlockId_u16, Crc16_u16);
#endif
#endif
}

/******************************************************************************
Function name   : void DLT_WriteDataToNvM(const DLT_ResetLogType* ResetLog)
Arguments       : DLT_ResetLogType* ResetLog
Return type     : void
Description     : Function to be called from OsPrvSetActiveParam to capture
the current object reference
******************************************************************************/
void DLT_WriteDataToNvM(uint16 NvBlockId_u16, uint16 Crc16_u16)
{
  #if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_OFF)
  (void)NvBlockId_u16;
  (void)Crc16_u16;
  #else
  uint32 LengthToCopy = 0U;
  uint16 Length = 0U;
  uint16 PageAddrOffset = 0U;
  uint32 TxBufferIndex = 0U;
  uint16 Ea_blockindex_u16 = 0u;
  uint16 PhyEepAddr_u16 = 0u;
  uint8 blockCount_u8 = 0u;
  Std_ReturnType SpiRetVal;
  static ADDR_ALIGN uint8 DLT_TxBuffer[DLT_TX_RX_BUFFER_LENGTH];

  /* Cancel if any ongoing transfer in SPI sequence */
  while (Spi_GetStatus() != SPI_IDLE)
  {
    Spi_MainFunction_Handling();
  }
  Spi_Cancel(DLT_SPI_EEPROM_SEQUENCE);

  if ((SPI_SEQ_OK == Spi_GetSequenceResult(DLT_SPI_EEPROM_SEQUENCE)) ||
      (SPI_SEQ_CANCELLED == Spi_GetSequenceResult(DLT_SPI_EEPROM_SEQUENCE)))
  {
    LengthToCopy = NvM_BlockConfig[NvBlockId_u16].NvBlockLength;
    Ea_blockindex_u16 = NvM_BlockConfig[NvBlockId_u16].NvBlockBaseNumber - 1u;

    /* Data to be written copied to source buffer based on length */
    MemLib_MemCpy(&DLT_TxBuffer[TxBufferIndex + 2u],
                  NvM_BlockConfig[NvBlockId_u16].RamBlockDataAddress,
                  LengthToCopy);

    DLT_TxBuffer[TxBufferIndex + LengthToCopy + 2u] = (uint8)(Crc16_u16 & 0x00FFu);
    DLT_TxBuffer[TxBufferIndex + LengthToCopy + 3u] = (uint8)((Crc16_u16 & 0xFF00u) >> 8u);

    /*Checking the block type*/
    if (NVM_REDUNDANT_BLOCK ==
        NvM_BlockConfig[NvBlockId_u16].BlockManagementType)
    {
      blockCount_u8 = (uint8)2u;
    }
    else
    {
      blockCount_u8 = (uint8)1u;
    }

    while (blockCount_u8 > 0u)
    {
      TxBufferIndex = 0u;
      PageAddrOffset = 0u;
      DLT_TxBuffer[TxBufferIndex] = (uint8)(blockCount_u8 << 1u);
      DLT_TxBuffer[TxBufferIndex + 1u] = (uint8)(~DLT_TxBuffer[TxBufferIndex]);
      PhyEepAddr_u16 = Ea_Config[Ea_blockindex_u16].BlockBaseAddress;
      Length = 0xFFu;
      Ea_blockindex_u16++;
      LengthToCopy = (uint32)NvM_BlockConfig[NvBlockId_u16].NvBlockLength + 4u;

      /* Write data to NvM till data length is valid */
      while (LengthToCopy != 0U)
      {
        /* SPI EEPROM Write Enable Command */
        DLT_WriteAddressBuffer[0] = DLT_WRITE_ENABLE_COMMAND;
        SpiRetVal = Spi_SetupEB(DLT_SPI_EEPROM_SEQUENCE,
                                &DLT_WriteAddressBuffer[0],
                                NULL,
                                DLT_WRITE_ENABLE_LENGTH);
        if (E_OK != SpiRetVal)
        {
          return;
        }

        SpiRetVal = Spi_SyncTransmit(DLT_SPI_EEPROM_SEQUENCE);
        if (E_OK != SpiRetVal)
        {
          return;
        }

        if (Length == 0xFFu)
        {
          Length = (uint16)(DLT_SPI_EEPROM_PAGE_SIZE -
                            (PhyEepAddr_u16 % DLT_SPI_EEPROM_PAGE_SIZE));
          if ((uint32)Length > LengthToCopy)
          {
            Length = (uint16)LengthToCopy;
          }
        }
        /* Written data length update */
        else if ((uint32)DLT_SPI_EEPROM_PAGE_SIZE < LengthToCopy)
        {
          Length = DLT_SPI_EEPROM_PAGE_SIZE;
        }
        else
        {
          Length = (uint16)LengthToCopy;
        }

        /* Write command value 1st byte */
        DLT_WriteAddressBuffer[0] = DLT_WRITE_COMMAND;
        /* 16bit Address 2nd & 3rd byte */
        DLT_WriteAddressBuffer[1] = (uint8)(((PhyEepAddr_u16 + PageAddrOffset) >> DLT_BYTE_SHIFT) &
                                            DLT_BYTE_LENGTH);
        DLT_WriteAddressBuffer[2] = (uint8)((PhyEepAddr_u16 + PageAddrOffset) & DLT_BYTE_LENGTH);

        /* Data to be written copied to source buffer based on length */
        MemLib_MemCpy((uint8 *)(&DLT_WriteAddressBuffer[3]),
                      &DLT_TxBuffer[TxBufferIndex],
                      Length);

        /* SPI data transfer to external EEPROM */
        SpiRetVal = Spi_SetupEB(DLT_SPI_EEPROM_SEQUENCE,
                                &DLT_WriteAddressBuffer[0],
                                NULL,
                                (Length + DLT_COMMAND_BYTES_LENGTH));
        if (E_OK != SpiRetVal)
        {
          return;
        }

        SpiRetVal = Spi_SyncTransmit(DLT_SPI_EEPROM_SEQUENCE);
        if (E_OK != SpiRetVal)
        {
          return;
        }

        PageAddrOffset = PageAddrOffset + Length;
        LengthToCopy = LengthToCopy - Length;

        if (DLT_TX_RX_BUFFER_LENGTH > (TxBufferIndex + Length))
        {
          TxBufferIndex = TxBufferIndex + Length;
        }

        /*Wait for RDY bit in Status Register to become zero*/
        if (FALSE == DLT_CheckRdyBit())
        {
          return;
        }
      }

      blockCount_u8--;
    }
  }
  #endif
}
/******************************************************************************
Function name   : boolean DLT_CheckRdyBit(void)
Arguments       : void
Return type     : boolean
Description     : Function to be called from DLT_WriteDataToNvM to check the
                  ready bit of the Status register in EEPROM
******************************************************************************/
boolean DLT_CheckRdyBit(void)
{
  Std_ReturnType SpiRetVal = E_NOT_OK;
  Std_ReturnType TimerElapsedStatus = E_NOT_OK;
  boolean RetVal = FALSE;

  DltExt_StartTimer();

  do
  {
    /* Read Status Register command 1st byte */
    DLT_WriteAddressBuffer[0] = DLT_READ_STATUS_COMMAND;
    DLT_WriteAddressBuffer[1] = 0xFFU;

    SpiRetVal = Spi_SetupEB(DLT_SPI_EEPROM_SEQUENCE,
                            &DLT_WriteAddressBuffer[0],
                            &DLT_RxBuff[0],
                            DLT_READ_STATUS_LENGTH);
    if (E_OK != SpiRetVal)
    {
      break;
    }

    SpiRetVal = Spi_SyncTransmit(DLT_SPI_EEPROM_SEQUENCE);
    if (E_OK != SpiRetVal)
    {
      break;
    }

    TimerElapsedStatus = DltExt_IsTimerElapsed(DLTEXT_ONEXCEPTION_TIMEOUT_US);
  } while ((((DLT_RxBuff[1] & 0x01U) != 0U)) &&
           (TimerElapsedStatus == E_NOT_OK));

  if ((((DLT_RxBuff[1] & 0x01U) == 0U)) &&
      (E_OK == SpiRetVal))
  {
    RetVal = TRUE;
  }

  return RetVal;
}

/*Function to provide delay during inline Nvm write. Not to be used at any other
 * place.*/
#if (DLTEXT_PLATFORM_NOT_FEE_NvM == STD_ON)
static void DltExt_NvmDELAY(void)
{
  volatile uint32 delay_cnt_u32 = NVMEXT_INLINE_DELAY_VALUE;
  while (delay_cnt_u32 > 0u)
  {
    delay_cnt_u32--;
  }
}
#endif

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
/*============================================================================
**
** Function Name    :   DltExt_IsTimerElapsed
**
** Visibility       :   Private
**
** Description      :
**
** Invocation       :
**
** Inputs           :   ElapseTime
**
** Outputs          :   E_OK -> If Timer Elapsed
**                      E_NOT_OK -> If Timer is not elapsed.
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_IsTimerElapsed(uint32 ElapseTime)
{
  Std_ReturnType fl_Return = E_NOT_OK;
  uint32 fl_CurrentTime = (uint32)DLTEXT_GET_CURRENT_TIME_IN_US;
  fl_Return = ((fl_CurrentTime - DltExt_TmStartTime) > ElapseTime)
                  ? (uint8)E_OK
                  : (uint8)E_NOT_OK;
  return fl_Return;
}

/*============================================================================
**
** Function Name    :   DltExt_StartTimer
**
** Visibility       :   Private
**
** Description      :
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_StartTimer(void)
{
  DltExt_TmStartTime = (uint32)DLTEXT_GET_CURRENT_TIME_IN_US;
}

#endif
/*============================================================================
**
** Function Name    :   DltExt_GetResetInfo
**
** Visibility       :   Public
**
** Description      : Function to get the reset info
**
** Invocation       :   FltM
**
** Inputs           :   None
**
** Outputs          :   ptr - Address to which reset info is passed
**
** Critical Section :
**
**==========================================================================*/

Std_ReturnType DltExt_GetResetInfo(uint8 *ptr)
{
  Std_ReturnType retVal = E_NOT_OK;
  #if (DLTEXT_UART_PRINT == STD_ON)
  uint8 flWdgResetCount = 0U;
  uint32 flUartWaitCnt = DLT_UART_BUSY_WAIT_CNT;
  #endif

  /* Prepare reset history for consumers exactly once per startup flow. */
  if (DltExt_ResetInfoReady == FALSE)
  {
    #if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
    /* Is the reset info ready in mirror RAM?*/
    if (E_OK == DltExt_GetResetDatafromNVM())
    {
      /* Reset info is prepared after POR adjustment succeeds. */
      if (DltExt_AdjustHistoryLogForPOR() == E_OK)
      {
        DltExt_ResetInfoLoaded = TRUE;
        DltExt_ResetInfoReady = TRUE;
        #if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)
        DltExt_ResetPending = 1U; /* reset payload needs to be sent once */
        #endif
      }
    }
    #endif
  }

  if (DltExt_ResetInfoReady == TRUE)
  {
    MemLib_MemCpy(ptr, &DltExt_ResetLogDataBuffer, sizeof(DltExt_ResetLogDataBuffer));
    #if (DLTEXT_UART_PRINT == STD_ON)
    if (DltExt_ResetInfoPrinted == FALSE)
    {
      DltExt_PrintResetLog(&DltExt_ResetLogDataBuffer);
      while ((DltExt_Uart_Busy == TRUE) && (flUartWaitCnt > 0U))
      {
        flUartWaitCnt--;
      }
      /* Pass pointer to the staged dump buffer (with 2-byte FID header) */
      DltExt_PrintOsDumpShort(&DltExt_ResetInfo[DLTEXT_RESET_HISTORY_MAX_SIZE], (uint16)DLTEXT_OSCPU_DUMP_SIZE);
      (void)PmicCdd_GetResetCount(&flWdgResetCount);
      DltExtWdgResetCount = flWdgResetCount;
      DltExt_ResetInfoPrinted = TRUE;
    }
    #endif
        /* clear sticky PMIC WDG reset count after consumption.
           Placed outside DLTEXT_UART_PRINT guard — must execute in all build configs. */
		if(DltExtWdgResetCount == 15u)
		{
        	PmicCdd_ClearResetCount();
		}
    retVal = E_OK;
  }

  return retVal;
}

/*============================================================================
**
** Function Name    :   DltExt_AdjustHistoryLogForPOR
**
** Visibility       :   Public
**
** Description      : Function to get the reset info
**
** Invocation       :   FltM
**
** Inputs           :   None
**
** Outputs          :   ptr - Address to which reset info is passed
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_AdjustHistoryLogForPOR(void)
{
  uint8 idx;
  uint8 flfaultIdx;
  Std_ReturnType retVal = E_NOT_OK;
  PmicCdd_ResetReasonType flResetReason;
  Mcu_ResetType flMcuResetReason;
  flMcuResetReason = Mcu_GetResetReason();
  /*Get the last reset reason*/
  flResetReason = PmicCdd_GetResetReason();
/* Removed the previous Reset counter check as that counter will increase 
   If any warm reset happens like BUCK OVUV, LDO OVUV, Wdg , Esm etc */

  if ((flResetReason != PmicCdd_Reset_Reason_Not_Ready) && (flResetReason != PmicCdd_Reset_Reason_None))
  {
    /* IMPORTANT:
     * - For PMIC WDG reset: DO NOT touch OsCpuDump (it contains last fault dump).
     * - For other reset reasons: keep dump unchanged here; if you need to mark
     *   “invalid dump” for UCL, do it in shared DDR buffer, not in NVM dump.
     */
    if ((flResetReason == PmicCdd_PmicWdg_Reset) || (flMcuResetReason == MCU_MAIN_WARM_RESET_MCU_DOMAIN))
    {
      /* Preserve the Os dump for post-reset diagnostics.
      * Do not clear here, otherwise the captured ARM/OS dump is lost
      * before it can be printed or replayed. */
    }
    else
    {
      for (idx = (DLTEXT_TOTAL_NUM_OF_RESET_HISTORY - 1u); idx > 0u; idx--)
      {
        MemLib_MemCpy(&DltExt_ResetLogDataBuffer.code[idx],
                      &DltExt_ResetLogDataBuffer.code[idx - 1u],
                      DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
      }
      /* Clear Latest Index Data*/
      MemLib_MemSet(&DltExt_ResetLogDataBuffer.code[0][0], 0x00U, DLTEXT_ADDITIONAL_RESET_INFO_SIZE);
      if (flResetReason != PmicCdd_PmicWdg_Reset)
      {
        /*Store the reset fault id in local buffer*/
        for (flfaultIdx = 0u; flfaultIdx < PMICCDD_RESET_MAX_FAULT_IDS; flfaultIdx++)
        {
          if (flfaultIdx == flResetReason)
          {
            DltExt_ResetLogDataBuffer.code[0][0] = (uint8)(PmicCddResetFaultIds.FaultIds[flfaultIdx] >> 8);
            DltExt_ResetLogDataBuffer.code[0][1] = (uint8)(PmicCddResetFaultIds.FaultIds[flfaultIdx]);

            if ((flResetReason == PmicCdd_Power_Supply_Fault_Reset) || (flResetReason == PmicCdd_PowerOn_Reset))
            {
              // logging the sub reason for power supply fault in 3rd index as 2nd index is reserved to time stamp
              DltExt_ResetLogDataBuffer.code[0][7] = PmicCdd_GetPwrSpplyFlt_SubResetReason();
            }
            /*Copy the data to nvm buffer*/
            MemLib_MemCpy(&DltExt_Internal_RstInfo.RstHistory[0], &DltExt_ResetLogDataBuffer, DLTEXT_RESET_HISTORY_MAX_SIZE);
            break;
          }
        }
      }
      /* Clear stale OsDump from a previous crash on any non-WDG reset.
         OsDump is preserved across WDG resets (it holds the crash evidence) but is
         meaningless after a genuine POR/SW-reset. Cleared here before the NvM write
         below so both updated history and cleared dump are persisted in one write. */
      MemLib_MemSet(&DltExt_Internal_RstInfo.OsCpuDump[0], 0x00u, (uint32)DLTEXT_OSCPU_DUMP_SIZE);
    }
#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
    /*Copy data to mirror RAM */
    DltExt_CopyResetInfoToNvmMirror();

    /* Trigger NvM write for reset block*/
    (void)DLTEXT_WRITE_RESETINFO_BLOCK;
/* Set the market to indicate that Reset info is loaded*/
#endif
    retVal = E_OK;
  }
  return retVal;
}

/*============================================================================
**
** Function Name    :   DltExt_RstMPushOsArmDump
**
** Visibility       :   Public
**
** Description      : Function to update Os Dump data
**
** Invocation       :   FltM
**
** Inputs           :   DataPtr - Data pointer, Length - Length of data
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
/* In declaration headers too, make DataPtr const if allowed by callers */
void DltExt_RstMPushOsArmDump(const uint8 *DataPtr, uint8 Length)
{
  uint8 copyLength;

  if (DataPtr != NULL_PTR)
  {
    /* Reset the Os dump */
    MemLib_MemSet(&DltExt_Internal_RstInfo.OsCpuDump[0], 0x00U, DLTEXT_SIZE_128BYTES);

    /* Do not modify input parameter directly */
    copyLength = Length;
    if (copyLength > (uint8)DLTEXT_SIZE_128BYTES)
    {
      copyLength = (uint8)DLTEXT_SIZE_128BYTES;
    }

    /* Copy the passed data */
    MemLib_MemCpy(&DltExt_Internal_RstInfo.OsCpuDump[0], DataPtr, copyLength);
  }
}

/*============================================================================
**
** Function Name    :   DltExt_PmicCddWdgEarlyWarning
**
** Visibility       :   Public
**
** Description      : Function to get the reset info
**
** Invocation       :   Pmic
**
** Inputs           :   DataPtr - Data pointer, Length - Length of data
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void DltExt_PmicCddWdgEarlyWarning(uint8 *DataPtr, uint8 Length)
{
  (void)Length;
  /* Reset the SW hang info*/
  DltExt_ResetSWHang();

  /* Copy the passed data*/
  /* Convert the structure to big-endian byte array */
  PmicCddWdgEarlyWarning *pSWHangInfo = (PmicCddWdgEarlyWarning *)DataPtr;

  /* Store FaultId (uint16) in big-endian format: MSB first */
  DLTEXT_SWHANG_MIRRORRAM[0] = (uint8)((pSWHangInfo->FaultId >> 8u) & 0xFFu); /* High byte */
  DLTEXT_SWHANG_MIRRORRAM[1] = (uint8)(pSWHangInfo->FaultId & 0xFFu); /* Low byte */

  /* Store interrupted PC (uint32) in big-endian format: MSB first */
  DLTEXT_SWHANG_MIRRORRAM[2] = (uint8)((pSWHangInfo->pc >> 24u) & 0xFFu); /* Byte 3 (MSB) */
  DLTEXT_SWHANG_MIRRORRAM[3] = (uint8)((pSWHangInfo->pc >> 16u) & 0xFFu); /* Byte 2 */
  DLTEXT_SWHANG_MIRRORRAM[4] = (uint8)((pSWHangInfo->pc >> 8u) & 0xFFu); /* Byte 1 */
  DLTEXT_SWHANG_MIRRORRAM[5] = (uint8)(pSWHangInfo->pc & 0xFFu); /* Byte 0 (LSB) */

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  DltExt_BlockWriteOnException((uint16)DLTEXT_SWHANG_BLOCKID);
#endif
}

#if (DLTEXT_UART_PRINT == STD_ON)

/*============================================================================
**
** Function Name    :   DltExt_Uart_Init
**
** Visibility       :   Public
**
** Description      : Function to get the reset info
**
** Invocation       :   Pmic
**
** Inputs           :   DataPtr - Data pointer, Length - Length of data
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

static Std_ReturnType DltExt_Uart_Init(void)
{
  Std_ReturnType flRetVal;

  flRetVal = SciDrv_SetAsyncMode(DLT_UART_CH, eSciDrvAsyncMode_Interrupt);
  if (flRetVal == E_OK)
  {
    flRetVal = SciDrv_EnableChn(DLT_UART_CH);
    if (flRetVal == E_OK)
    {
      DltExt_Uart_Initialized = TRUE;
    }
  }
  return flRetVal;
}

static uint32 DltExt_ReadU32LE(const uint8 *p, uint16 off)
{
  return ((uint32)p[off + 0u]) |
         ((uint32)p[off + 1u] << 8u) |
         ((uint32)p[off + 2u] << 16u) |
         ((uint32)p[off + 3u] << 24u);
}

static void DltExt_PrintOsDumpShort(const uint8 *DltExt_pDump, uint16 DltExt_DumpLen)
{
  uint16 DltExt_Pos = 0u;
  int DltExt_Written;
  Std_ReturnType DltExt_flRetVal;

  /* header */
  uint16 fid;

  /* decoded fields (payload) */
  uint32 pc, lr, psr, dfsr, ifsr;
  uint8 exc;
  uint8 mmarValid;
  uint32 dfar_off22;
  uint32 dfar_off24;

  const uint16 headerSize = 2u;
  const uint16 minPayloadBytes = 32u; /* your decoder reads up to 24+4 */

  if ((DltExt_pDump == NULL_PTR) || (DltExt_DumpLen < (uint16)(headerSize + minPayloadBytes)))
  {
    return;
  }

  if (DltExt_Uart_Busy == TRUE)
  {
    return;
  }

  /* FaultId in header: you store MSB then LSB */
  fid = (uint16)(((uint16)DltExt_pDump[0u] << 8u) | (uint16)DltExt_pDump[1u]);

  /* Payload starts after 2-byte header */
  pc = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 0u));
  lr = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 4u));
  psr = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 8u));
  dfsr = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 12u));
  ifsr = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 16u));
  exc = DltExt_pDump[headerSize + 20u];
  mmarValid = DltExt_pDump[headerSize + 21u];

  dfar_off22 = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 22u));
  dfar_off24 = DltExt_ReadU32LE(DltExt_pDump, (uint16)(headerSize + 24u));

  DltExt_Written = snprintf((char *)&DltExt_Uart_TxBuf[DltExt_Pos],
                            (size_t)(DLT_UART_TXBUF_SIZE - DltExt_Pos),
                            "\r\n ************* OsDump *************** \
                             \r\nFID=%04X \r\nPC=%08lX \r\nLR=%08lX \r\nPSR=%08lX \r\nDFSR=%08lX \r\nIFSR=%08lX \
                             \r\nExec=%02X \r\nMMAR_VALID ? =%u \r\nDFAR22=%08lX \r\nDFAR24=%08lX\r\n",
                            (unsigned)fid,
                            (unsigned long)pc,
                            (unsigned long)lr,
                            (unsigned long)psr,
                            (unsigned long)dfsr,
                            (unsigned long)ifsr,
                            (unsigned)exc,
                            (unsigned)mmarValid,
                            (unsigned long)dfar_off22,
                            (unsigned long)dfar_off24);

  if (DltExt_Written <= 0)
  {
    return;
  }

  /* Clamp snprintf truncation */
  if (DltExt_Written >= (int)(DLT_UART_TXBUF_SIZE - DltExt_Pos))
  {
    DltExt_Pos = (uint16)(DLT_UART_TXBUF_SIZE - 1u);
  }
  else
  {
    DltExt_Pos = (uint16)DltExt_Written;
  }

  DltExt_flRetVal = DltExt_Uart_Send((const uint8 *)DltExt_Uart_TxBuf, DltExt_Pos);
  (void)DltExt_flRetVal;
}

static void DltExt_PrintResetLog(const tDltExt_ResetLogDataBuffer *DltExt_pLog)
{
  /* declarations at top */
  uint8 DltExt_Row;
  uint8 DltExt_Col;
  uint8 DltExt_Byte;
  uint16 DltExt_Pos;
  int DltExt_Written;
  Std_ReturnType DltExt_flRetVal;

  if (DltExt_pLog == NULL)
  {
    return;
  }

  DltExt_Pos = 0u;

  for (DltExt_Row = 0u;
       ((DltExt_Row < DLTEXT_TOTAL_NUM_OF_RESET_HISTORY) && (DltExt_Pos < (uint16)DLT_UART_TXBUF_SIZE));
       DltExt_Row++)
  {
    /* prefix "ResetLog[N] - " */
    DltExt_Written = snprintf((char *)&DltExt_Uart_TxBuf[DltExt_Pos],
                              ((size_t)DLT_UART_TXBUF_SIZE - (size_t)DltExt_Pos),
                              "ResetLog[%u] - ",
                              (unsigned int)DltExt_Row);
    if (DltExt_Written <= 0)
    {
      break;
    }
    DltExt_Pos = (uint16)(DltExt_Pos + (uint16)DltExt_Written);

    /* 12 bytes "AA " */
    for (DltExt_Col = 0u; ((DltExt_Col < DLTEXT_ADDITIONAL_RESET_INFO_SIZE) &&
                           (DltExt_Pos < (uint16)DLT_UART_TXBUF_SIZE));
         DltExt_Col++)
    {
      DltExt_Byte = DltExt_pLog->code[DltExt_Row][DltExt_Col];
      DltExt_Written = snprintf((char *)&DltExt_Uart_TxBuf[DltExt_Pos], //Array 'DltExt_Uart_TxBuf' of size 256 may use index value(s) 256
                                ((size_t)DLT_UART_TXBUF_SIZE - (size_t)DltExt_Pos),
                                "%02X ",
                                (unsigned int)DltExt_Byte);
      if (DltExt_Written <= 0)
      {
        break;
      }
      DltExt_Pos = (uint16)(DltExt_Pos + (uint16)DltExt_Written);
    }

    /* replace last space with CRLF */
    if ((DltExt_Pos > 0u) && (DltExt_Uart_TxBuf[DltExt_Pos - 1u] == ' '))
    {
      DltExt_Uart_TxBuf[DltExt_Pos - 1u] = '\r';
      if (DltExt_Pos < (DLT_UART_TXBUF_SIZE - 1u))
      {
        DltExt_Uart_TxBuf[DltExt_Pos] = '\n';
        DltExt_Pos++;
      }
    }
  }

  if (DltExt_Pos > 0u)
  {
    DltExt_flRetVal = DltExt_Uart_Send((const uint8 *)DltExt_Uart_TxBuf, DltExt_Pos);
    (void)DltExt_flRetVal;
  }
}

/* Called from SciDrv TX-complete interrupt */
void DltExt_Uart_TxComplete(ESciDrvChnResult result)
{
  (void)result;
  DltExt_Uart_Busy = FALSE;
}

/* make static if not used outside DltExt.c */
Std_ReturnType DltExt_Uart_Send(const uint8 *DataPtr, uint16 Length)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 CopyLength;

  if ((DataPtr != NULL_PTR) && (Length > 0u) && (DltExt_Uart_Initialized == TRUE) && (DltExt_Uart_Busy == FALSE))
  {
    if (Length <= DLT_UART_TXBUF_SIZE)
    {
      CopyLength = Length;

      if (DataPtr != &DltExt_Uart_TxBuf[0])
      {
        MemLib_MemCpy(&DltExt_Uart_TxBuf[0], DataPtr, CopyLength);
      }
      RetVal = SciDrv_SetupEB(DLT_UART_CH, eSciDrvDirection_Transmit, &DltExt_Uart_TxBuf[0], CopyLength);
      if (RetVal == E_OK)
      {
        DltExt_Uart_Busy = TRUE;
        (void)SciDrv_ASyncTransmit(DLT_UART_CH);
      }
    }
  }
  return RetVal;
}

/* ================= Printf-style logging ================= */

Std_ReturnType DltExt_Uart_Printf(const char *fmt, ...)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  if ((fmt != NULL) && (DltExt_Uart_Initialized == TRUE) &&
      (DltExt_Uart_Busy == FALSE))
  {
    va_list args;
    va_start(args, fmt);

    /* vsnprintf ensures null-termination and bounds */
    int len = vsnprintf((char *)DltExt_Uart_TxBuf, (size_t)DLT_UART_TXBUF_SIZE, fmt, args);

    va_end(args);

    if (len > 0)
    {
      uint16 txLen = (uint16)((len < (int)DLT_UART_TXBUF_SIZE)
                                  ? len
                                  : (DLT_UART_TXBUF_SIZE - 1u));

#if (DLT_UART_APPEND_CRLF == STD_ON)
      if ((txLen + 2u) < DLT_UART_TXBUF_SIZE)
      {
        DltExt_Uart_TxBuf[txLen++] = (uint8)'\r';
        DltExt_Uart_TxBuf[txLen++] = (uint8)'\n';
      }
#endif

      flRetVal = SciDrv_SetupEB(DLT_UART_CH, eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, txLen);
      if (flRetVal == E_OK)
      {
        DltExt_Uart_Busy = TRUE;
        (void)SciDrv_ASyncTransmit(DLT_UART_CH);
      }
    }
  }
  return flRetVal;
}

Std_ReturnType DltExt_Uart_SendHex(ESciDrvAsyncMode mode,
                                   const uint8 *DltExt_Bytes,
                                   uint16 DltExt_NBytes,
                                   const char *DltExt_Prefix)
{
  Std_ReturnType DltExt_flRetVal = E_NOT_OK;

  /* Declare variables at top */
  uint32 DltExt_PrefixLen;
  uint32 DltExt_Needed32;
  uint16 DltExt_Pos;
  int DltExt_Written;
  int DltExt_W;
  uint16 DltExt_i;

  if ((DltExt_Bytes != NULL) && (DltExt_NBytes != 0u) &&
      (DltExt_Prefix != NULL))
  {
    if (DltExt_Uart_Busy == FALSE)
    {
      /* Compute required length */
      DltExt_PrefixLen = (uint32)strlen(DltExt_Prefix);
      DltExt_Needed32 = DltExt_PrefixLen + 3u +
                        ((uint32)DltExt_NBytes * (uint32)DLT_UART_HEX_SPACE_PER_BYTE) + 2u;

      if (DltExt_Needed32 <= (uint32)DLT_UART_TXBUF_SIZE)
      {
        DltExt_Pos = 0u;

        /* 1) Write prefix and separator */
        DltExt_Written = snprintf((char *)&DltExt_Uart_TxBuf[DltExt_Pos],
                                  ((size_t)DLT_UART_TXBUF_SIZE - (size_t)DltExt_Pos),
                                  "%s - ",
                                  DltExt_Prefix);
        if ((DltExt_Written > 0) &&
            ((uint16)DltExt_Written < (DLT_UART_TXBUF_SIZE - DltExt_Pos)))
        {
          DltExt_Pos = (uint16)(DltExt_Pos + (uint16)DltExt_Written);

          /* 2) Append hex bytes */
          for (DltExt_i = 0u; DltExt_i < DltExt_NBytes; DltExt_i++)
          {
            if ((DltExt_Pos + 3u) < DLT_UART_TXBUF_SIZE) //Array 'DltExt_Uart_TxBuf' of size 256 may use index value(s) 1..256
            {
              DltExt_W = snprintf((char *)&DltExt_Uart_TxBuf[DltExt_Pos], 4, "%02X ", (unsigned)DltExt_Bytes[DltExt_i]);
              if ((DltExt_W > 0) &&
                  ((DltExt_Pos + (uint16)DltExt_W) <= DLT_UART_TXBUF_SIZE))
              {
                DltExt_Pos = (uint16)(DltExt_Pos + (uint16)DltExt_W);
              }
              else
              {
                break; /* snprintf error or overflow */
              }
            }
            else
            {
              break; /* buffer full */
            }
          }

          if (DltExt_i == DltExt_NBytes)
          {
            /* 3) Remove trailing space if present */
            if ((DltExt_Pos > 0u) &&
                (DltExt_Uart_TxBuf[DltExt_Pos - 1u] == (uint8)' '))
            {
              DltExt_Pos--;
            }

            /* 4) Append CRLF */
            if ((DltExt_Pos + 2u) <= DLT_UART_TXBUF_SIZE)
            {
              DltExt_Uart_TxBuf[DltExt_Pos] = (uint8)'\r';
              DltExt_Pos++;
              DltExt_Uart_TxBuf[DltExt_Pos] = (uint8)'\n';
              DltExt_Pos++;

              if (mode == eSciDrvAsyncMode_Interrupt)
              {
                /* 5) Kick async transmit */
                DltExt_flRetVal =
                    SciDrv_SetupEB(DLT_UART_CH, eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, DltExt_Pos);
                if (DltExt_flRetVal == E_OK)
                {
                  DltExt_Uart_Busy = TRUE;
                  (void)SciDrv_ASyncTransmit(DLT_UART_CH);
                }
              }
              else
              {
                (void)SciDrv_DisableChn(DLT_UART_CH);
                (void)SciDrv_SetSyncMode(DLT_UART_CH, eSciDrvSyncMode_Polling);
                (void)SciDrv_EnableChn(DLT_UART_CH);
                (void)SciDrv_SetupEB(DLT_UART_CH, eSciDrvDirection_Transmit, (uint8 *)DltExt_Uart_TxBuf, DltExt_Pos);
                (void)SciDrv_SyncTransmit(DLT_UART_CH);
              }
            }
            else
            {
              DltExt_flRetVal = E_NOT_OK; /* no room for CRLF */
            }
          }
          else
          {
            DltExt_flRetVal = E_NOT_OK; /* hex loop ended early */
          }
        }
        else
        {
          DltExt_flRetVal = E_NOT_OK; /* prefix formatting failed */
        }
      }
      else
      {
        DltExt_flRetVal = E_NOT_OK; /* line too long */
      }
    }
    else
    {
      DltExt_flRetVal = E_NOT_OK; /* UART busy */
    }
  }
  else
  {
    DltExt_flRetVal = E_NOT_OK; /* invalid input */
  }

  return DltExt_flRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   DltExt_PreInitGetResetCount
**
** Visibility       :   Public
**
** Description      :   Returns count of FaultId occurrences from reset history
**                      using the inline EEPROM/SPI read path before NvM ReadAll
**                      completion. This API does not modify normal startup
**                      state flags used by DltExt_MainFunction().
**
** Invocation       :   RstM
**
** Inputs           :   FaultId - Fault ID to count
**                      Count   - Pointer to returned count
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   No
**==========================================================================*/
Std_ReturnType DltExt_PreInitGetResetCount(uint16 FaultId, uint8 *Count)
{
  Std_ReturnType RetVal = E_NOT_OK;

#if (DLTEXT_CFG_NVM_BLOCKS_PRESENT == STD_ON)
  uint8 Index = 0U;
  uint16 StoredFaultId = 0U;

  if ((Count != NULL_PTR) && (FaultId != 0U))
  {
    *Count = 0U;

    RetVal = DltExt_InlineReadResetInfoInternal((uint16)DLTEXT_NVBLOCKDESCRIPTOR_DLT_FETAL_STORAGE);

    if (RetVal == E_OK)
    {
      MemLib_MemCpy(&DltExt_ResetLogDataBuffer,
                    &DltExt_Internal_RstInfo.RstHistory[0],
                    DLTEXT_RESET_HISTORY_MAX_SIZE);

      for (Index = 0U; Index < DLTEXT_TOTAL_NUM_OF_RESET_HISTORY; Index++)
      {
        StoredFaultId = (uint16)(((uint16)DltExt_ResetLogDataBuffer.code[Index][0] << 8U) |
                                 (uint16)DltExt_ResetLogDataBuffer.code[Index][1]);

        if (StoredFaultId == FaultId)
        {
            (*Count)++;
        }
      }
    }
  }
#else
  (void)FaultId;

  if (Count != NULL_PTR)
  {
    *Count = 0U;
  }
#endif

  return RetVal;
}
#endif /* DLTEXT_C */

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
Date               : 5-May-2025
CDSID              : ssawaria
Traceability       :
Change Description : DltExt Updated - OnException Block Write, SNvM logging,
DltExt_Eraselogdata
------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
Date               : 17-June-2025
CDSID              : kpalaniv
Traceability       :
Change Description : DltExt Updated for E4.0 platform - SPI inline write is
implemented
------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------
Date               : 12-Aug-2025
CDSID              : kpalaniv
Traceability       :
Change Description : DltExt Updated for E4.0 platform - Seperate app and reset
buffer, Sw hang block, update app log in shared memory
------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------
Date               : 26-Aug-2025
CDSID              : kpalaniv
Traceability       :
Change Description : DltExt Updated for E4.0 platform - Updating inline read
in case reset happens before read-all
------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------
Date               : 12-Dec-2025
CDSID              : MSAVARIY
Traceability       : https://visteon.atlassian.net/browse/PE4TI29141-10843
Change Description : DltExt Updated for E4.0 platform - DLT Verbose header update for shared memory
------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :30-Jun-2026
By                :MSAVARIY
Traceability      : PE4TI29141-12520, PE4TI29141-12607, PE4TI29141-12735
Change Description: Add pre-initialization reset-history snapshot and count
                    services for E4 reset-storm evaluation.
-----------------------------------------------------------------------------*/
/* end of file
 * ======================================================================================*/
