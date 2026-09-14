/****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 ****************************************************************************/
/****************************************************************************
 *  File Name         :  DltExt_Ipc.c                                         *
 *  Module Short Name :  DltExt_Ipc                                           *
 *  Description       :  VIP side IPC handling for DLT Extension              *
 *                                                                            *
 ****************************************************************************/

#include "DltExt_Ipc.h"
#include "DltExt.h"
#include "DltExt_Cfg.h"
#include "MemLib.h"
#include "Rte_DltExt.h"

#if (DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON)

#if (DLTEXT_UART_PRINT == STD_ON)
#include "SciDrv_Types.h"
extern Std_ReturnType DltExt_Uart_Printf(const char *fmt, ...);
#endif
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
#include "Cdd_Ipc.h"
#include "Cdd_IpcCfg.h"
#endif
#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
#include "vDLT_HSM.h"
#endif

/****************************************************************************
 * Local Types
 ****************************************************************************/
typedef SDLTMessageReadRequest DLTMessageReadRequestL;
typedef SDLTMessageReadAck DLTMessageReadAckL;

typedef enum
{
  DLTEXT_IPC_SOURCE_NONE = 0u,
  DLTEXT_IPC_SOURCE_VIP_APP,
  DLTEXT_IPC_SOURCE_VIP_RESET,
  DLTEXT_IPC_SOURCE_DM,
  DLTEXT_IPC_SOURCE_HSM
} DltExt_IpcSourceType;

typedef struct
{
  DltExt_IpcSourceType Source;
  DltExt_SharMemBufferIdType BufferId;
} DltExt_IpcActiveTransferType;

/****************************************************************************
 * Local Macro Definitions
 ****************************************************************************/
#define DLTEXT_IPC_BANK_ID_1                 (1u)
#define DLTEXT_IPC_BANK_ID_2                 (2u)

#define DLTEXT_IPC_BUFFER_MASK_NONE          (0u)
#define DLTEXT_IPC_BUFFER_MASK_VIP1          (0x01u)
#define DLTEXT_IPC_BUFFER_MASK_VIP2          (0x02u)
#define DLTEXT_IPC_BUFFER_MASK_RESET         (0x04u)
#define DLTEXT_IPC_BUFFER_MASK_HSM1          (0x08u)
#define DLTEXT_IPC_BUFFER_MASK_HSM2          (0x10u)
#define DLTEXT_IPC_BUFFER_MASK_DM1           (0x20u)
#define DLTEXT_IPC_BUFFER_MASK_DM2           (0x40u)

#define DLTEXT_IPC_VIP_BUFFER_SIZE_U16       ((uint16)DLT_EXT_APPLOG_SHAREMEM_SIZE)
#define DLTEXT_IPC_RESET_BUFFER_SIZE_U16     ((uint16)DLTEXT_RESET_SHMEM_SIZE)
#define DLTEXT_IPC_TIMER_MAX_BEFORE_TIMEOUT  ((uint32)(DLTEXT_IPC_FLUSH_TIMEOUT_MS - DLTEXT_IPC_MAINFUNCTION_PERIOD_MS))

/****************************************************************************
 * Local Variables
 ****************************************************************************/
#pragma clang section data = ".Sharedata_DltAppInfoBank1"
static uint8 DltExt_AppInfo_Buffer1[DLT_EXT_APPLOG_SHAREMEM_SIZE] = { 0u };
#pragma clang section data = ""

#pragma clang section data = ".Sharedata_DltAppInfoBank2"
static uint8 DltExt_AppInfo_Buffer2[DLT_EXT_APPLOG_SHAREMEM_SIZE] = { 0u };
#pragma clang section data = ""

#pragma clang section data = ".Sharedata_DltResetInfo"
static uint8 DltExt_ResetInfo_SharedDumpBuffer[DLTEXT_RESET_SHMEM_SIZE] = { 0u };
#pragma clang section data = ""

static boolean DltExt_Ipc_GipUpFlag = FALSE;
static uint16 DltExt_Ipc_AppInfoMemPtr = 0u;
static uint8 DltExt_Ipc_AppInfoBufferPtr = DLTEXT_APPLOG_SHAREMEM_BUFFER1;
static volatile uint32 DltExt_Ipc_FlushTimer = 0u;
static volatile boolean DltExt_Ipc_TimerActive = FALSE;
static uint8 DltExt_Ipc_PendingMask = 0u;
static uint8 DltExt_Ipc_RequestActive = 0u;

static DltExt_IpcActiveTransferType DltExt_Ipc_ActiveTransfer = {
  DLTEXT_IPC_SOURCE_NONE,
  DLTEXT_BUFFER_NONE
};

/****************************************************************************
 * Local Function Prototypes
 ****************************************************************************/
static boolean DltExt_Ipc_IsTransferIdle(void);
static void DltExt_Ipc_QueuePending(DltExt_SharMemBufferIdType BufferId);
static void DltExt_Ipc_ClearPending(DltExt_SharMemBufferIdType BufferId);
static boolean DltExt_Ipc_GetNextPending(DltExt_SharMemBufferIdType *BufferIdPtr);
static DltExt_IpcSourceType DltExt_Ipc_MapBufferToSource(DltExt_SharMemBufferIdType BufferId);
static Std_ReturnType DltExt_Ipc_SendRequest(DltExt_SharMemBufferIdType BufferId);
static void DltExt_Ipc_HandleResponse(uint8 Status);
static void DltExt_Ipc_CompleteActiveTransfer(void);
static void DltExt_Ipc_ClearLocalBuffer(DltExt_SharMemBufferIdType BufferId);
static Std_ReturnType DltExt_Ipc_FlushCurrentVipBank(void);
static boolean DltExt_Ipc_IsValidDmBankId(uint8 BankId);
static boolean DltExt_Ipc_IsValidHsmBankId(uint8 BankId);
static void DltExt_Ipc_SendAckToDm(uint8 BankId);
#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
static void DltExt_Ipc_SendAckToHsm(uint8 BankId);
void DltExt_Ipc_HsmLogEvent(uint32 data);
#endif
static uint8 DltExt_Ipc_GetBufferMask(DltExt_SharMemBufferIdType BufferId);
static Std_ReturnType DltExt_Ipc_ReadAck(uint8 *AckStatusPtr);

/* Explicit prototypes for exported callbacks */
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
void CddIpc_DM_DltReadyResponse(void);
#endif


/****************************************************************************
 * Local Functions
 ****************************************************************************/
/*============================================================================
**
** Function Name    :   DltExt_Ipc_IsTransferIdle
**
** Visibility       :   Private
**
** Description      :   Check whether no GIP read request is currently active
**                      and IPC transfer state machine is free to accept a new
**                      transfer request.
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :   boolean - TRUE if idle, FALSE otherwise
**
** Critical Section :
**
**==========================================================================*/
static boolean DltExt_Ipc_IsTransferIdle(void)
{
  boolean RetVal = FALSE;

  if ((DltExt_Ipc_RequestActive == 0u) && (DltExt_Ipc_ActiveTransfer.Source == DLTEXT_IPC_SOURCE_NONE))
  {
    RetVal = TRUE;
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_GetBufferMask
**
** Visibility       :   Private
**
** Description      :   Convert shared memory buffer id to internal uint8 mask
**                      used for pending bitmap and GIP request status field.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :   uint8 - Internal bit mask / request status value
**
** Critical Section :
**
**==========================================================================*/
static uint8 DltExt_Ipc_GetBufferMask(DltExt_SharMemBufferIdType BufferId)
{
  uint8 Mask = DLTEXT_IPC_BUFFER_MASK_NONE;

  switch (BufferId)
  {
    case DLTEXT_VIP_SHAREMEMBUF1:
      Mask = DLTEXT_IPC_BUFFER_MASK_VIP1;
      break;

    case DLTEXT_VIP_SHAREMEMBUF2:
      Mask = DLTEXT_IPC_BUFFER_MASK_VIP2;
      break;

    case DLTEXT_SHAREMEMRESETBUF:
      Mask = DLTEXT_IPC_BUFFER_MASK_RESET;
      break;

    case DLTEXT_HSM_BUFFER1:
      Mask = DLTEXT_IPC_BUFFER_MASK_HSM1;
      break;

    case DLTEXT_HSM_BUFFER2:
      Mask = DLTEXT_IPC_BUFFER_MASK_HSM2;
      break;

    case DLTEXT_DM_BUFFER1:
      Mask = DLTEXT_IPC_BUFFER_MASK_DM1;
      break;

    case DLTEXT_DM_BUFFER2:
      Mask = DLTEXT_IPC_BUFFER_MASK_DM2;
      break;

    case DLTEXT_BUFFER_NONE:
      Mask = DLTEXT_IPC_BUFFER_MASK_NONE;
      break;

    default:
      Mask = DLTEXT_IPC_BUFFER_MASK_NONE;
      break;
  }

  return Mask;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_ReadAck
**
** Visibility       :   Private
**
** Description      :   Wrapper for GIP ACK read API.
**
** Invocation       :
**
** Inputs           :   AckStatusPtr - Pointer to ACK/NACK status
**
** Outputs          :   Std_ReturnType - E_OK if ACK/NACK read is available
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_Ipc_ReadAck(uint8 *AckStatusPtr)
{
  return DltExt_Ucl_VipToGip_Ack(AckStatusPtr);
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_QueuePending
**
** Visibility       :   Private
**
** Description      :   Add the specified shared memory buffer id into the
**                      pending request bitmap so that it can be serviced later
**                      when the active transfer completes.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_Ipc_QueuePending(DltExt_SharMemBufferIdType BufferId)
{
  uint8 Mask;

  Mask = DltExt_Ipc_GetBufferMask(BufferId);
  DltExt_Ipc_PendingMask |= Mask;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_ClearPending
**
** Visibility       :   Private
**
** Description      :   Remove the specified shared memory buffer id from the
**                      pending request bitmap after the request is accepted or
**                      completed.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static void DltExt_Ipc_ClearPending(DltExt_SharMemBufferIdType BufferId)
{
  uint8 Mask;

  Mask = DltExt_Ipc_GetBufferMask(BufferId);
  DltExt_Ipc_PendingMask &= (uint8)(~Mask);
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_GetNextPending
**
** Visibility       :   Private
**
** Description      :   Get the next pending shared memory buffer request to be
**                      serviced by the IPC transfer state machine.
**
** Invocation       :
**
** Inputs           :   BufferId - Pointer to return next pending buffer id
**
** Outputs          :   boolean - TRUE if one pending request is available,
**                      FALSE otherwise
**
** Critical Section :
**
**==========================================================================*/

static boolean DltExt_Ipc_GetNextPending(DltExt_SharMemBufferIdType *BufferIdPtr)
{
  static const DltExt_SharMemBufferIdType DltExt_Ipc_PendingOrder[] =
  {
    DLTEXT_SHAREMEMRESETBUF,
    DLTEXT_DM_BUFFER1,
    DLTEXT_DM_BUFFER2,
    DLTEXT_HSM_BUFFER1,
    DLTEXT_HSM_BUFFER2,
    DLTEXT_VIP_SHAREMEMBUF1,
    DLTEXT_VIP_SHAREMEMBUF2
  };

  boolean RetVal = FALSE;
  uint8 Index;
  uint8 Mask;

  if (BufferIdPtr != NULL_PTR)
  {
    for (Index = 0u; Index < (uint8)(sizeof(DltExt_Ipc_PendingOrder) / sizeof(DltExt_Ipc_PendingOrder[0])); Index++)
    {
      Mask = DltExt_Ipc_GetBufferMask(DltExt_Ipc_PendingOrder[Index]);
      if ((DltExt_Ipc_PendingMask & Mask) != 0u)
      {
        *BufferIdPtr = DltExt_Ipc_PendingOrder[Index];
        RetVal = TRUE;
        break;
      }
    }
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_MapBufferToSource
**
** Visibility       :   Private
**
** Description      :   Map a shared memory buffer identifier to its owning
**                      IPC source type such as VIP app, VIP reset, DM, or HSM.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :   DltExt_IpcSourceType - Owning source of the buffer
**
** Critical Section :
**
**==========================================================================*/
static DltExt_IpcSourceType DltExt_Ipc_MapBufferToSource(DltExt_SharMemBufferIdType BufferId)
{
  DltExt_IpcSourceType Source = DLTEXT_IPC_SOURCE_NONE;

  switch (BufferId)
  {
  case DLTEXT_VIP_SHAREMEMBUF1:
  case DLTEXT_VIP_SHAREMEMBUF2:
    Source = DLTEXT_IPC_SOURCE_VIP_APP;
    break;

  case DLTEXT_SHAREMEMRESETBUF:
    Source = DLTEXT_IPC_SOURCE_VIP_RESET;
    break;

  case DLTEXT_DM_BUFFER1:
  case DLTEXT_DM_BUFFER2:
    Source = DLTEXT_IPC_SOURCE_DM;
    break;

  case DLTEXT_HSM_BUFFER1:
  case DLTEXT_HSM_BUFFER2:
    Source = DLTEXT_IPC_SOURCE_HSM;
    break;

  case DLTEXT_BUFFER_NONE:
    Source = DLTEXT_IPC_SOURCE_NONE;
    break;

  default:
    Source = DLTEXT_IPC_SOURCE_NONE;
    break;
  }

  return Source;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_SendRequest
**
** Visibility       :   Private
**
** Description      :   Send GIP read request for the specified shared memory
**                      buffer. If a transfer is already active, the request is
**                      retained in pending state for later processing.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :   Std_ReturnType - E_OK if request is accepted now,
**                      E_NOT_OK otherwise
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_Ipc_SendRequest(DltExt_SharMemBufferIdType BufferId)
{
  Std_ReturnType RetVal = E_NOT_OK;
  DLTMessageReadRequestL ReqData;
  DltExt_IpcSourceType Source;
  uint8 StatusValue;

  if (DltExt_Ipc_GipUpFlag == FALSE)
  {
    DltExt_Ipc_QueuePending(BufferId);
    RetVal = E_NOT_OK;
  }
  else
  {
    Source = DltExt_Ipc_MapBufferToSource(BufferId);
    StatusValue = DltExt_Ipc_GetBufferMask(BufferId);

    if ((Source != DLTEXT_IPC_SOURCE_NONE) && (StatusValue != DLTEXT_IPC_BUFFER_MASK_NONE))
    {
      if (DltExt_Ipc_IsTransferIdle() != FALSE)
      {
        ReqData.status = StatusValue;
        RetVal = DltExt_Ucl_VipToGip(&ReqData);

        if (RetVal == E_OK)
        {
          DltExt_Ipc_RequestActive = 1u;
          DltExt_Ipc_ActiveTransfer.Source = Source;
          DltExt_Ipc_ActiveTransfer.BufferId = BufferId;
          DltExt_Ipc_ClearPending(BufferId);
        }
        else
        {
          DltExt_Ipc_QueuePending(BufferId);
        }
      }
      else
      {
        DltExt_Ipc_QueuePending(BufferId);
      }
    }
  }
  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_ClearLocalBuffer
**
** Visibility       :   Private
**
** Description      :   Clear VIP-owned local shared memory buffer content
**                      after GIP processing is completed. Remote DM/HSM buffers
**                      are not cleared here.
**
** Invocation       :
**
** Inputs           :   BufferId - Shared memory buffer identifier
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_Ipc_ClearLocalBuffer(DltExt_SharMemBufferIdType BufferId)
{
  switch (BufferId)
  {
  case DLTEXT_VIP_SHAREMEMBUF1:
    MemLib_MemSet(&DltExt_AppInfo_Buffer1[0], 0x00u, DLT_EXT_APPLOG_SHAREMEM_SIZE);
    break;

  case DLTEXT_VIP_SHAREMEMBUF2:
    MemLib_MemSet(&DltExt_AppInfo_Buffer2[0], 0x00u, DLT_EXT_APPLOG_SHAREMEM_SIZE);
    break;

  case DLTEXT_SHAREMEMRESETBUF:
    MemLib_MemSet(&DltExt_ResetInfo_SharedDumpBuffer[0], 0x00u, DLTEXT_RESET_SHMEM_SIZE);
    break;

  default:
    /* DM/HSM shared buffers are remote-owned and shall be cleared by their side
             * after receiving completion ACK from VIP.
             */
    break;
  }
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_SendAckToDm
**
** Visibility       :   Private
**
** Description      :   Send startup-ready indication or runtime bank-specific
**                      completion ACK from VIP to DM through IPC.
**
** Invocation       :
**
** Inputs           :   DmBankId - DM bank id or startup indication value
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_Ipc_SendAckToDm(uint8 BankId)
{
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
  DltMsgType GipAck;
  Std_ReturnType RetVal;

  GipAck.msgID = DLTEXT_IPC_MSG_ID;
  GipAck.CRC = 0u;
  GipAck.Parameter = BankId;

  RetVal = Cdd_IpcSendMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP14,
                          (const void *)&GipAck,
                          (uint32)sizeof(GipAck));

#if (DLTEXT_UART_PRINT == STD_ON)
  (void)DltExt_Uart_Printf("DLT IPC: Ack to DM bank %u, ret=%u\r\n", BankId, (uint32)RetVal);
#endif
#else
  (void)BankId;
#endif
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_SendAckToHsm
**
** Visibility       :   Private
**
** Description      :   Send startup-ready indication or runtime bank-specific
**                      completion ACK from VIP to HSM.
**
** Invocation       :
**
** Inputs           :   HsmBankId - HSM bank id or startup indication value
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
static void DltExt_Ipc_SendAckToHsm(uint8 BankId)
{
  uint32 AckWord = DLT_BUFF_ACK;

  if (BankId != 0u)
  {
    AckWord |= ((uint32)BankId << 16u);
  }

#if (DLTEXT_UART_PRINT == STD_ON)
  (void)DltExt_Uart_Printf("DLT IPC: Ack to HSM bank %u\r\n", BankId);
#endif

  DltExt_Hsm_IpcAckEvent(AckWord);
}
#endif

/*============================================================================
**
** Function Name    :   DltExt_Ipc_CompleteActiveTransfer
**
** Visibility       :   Private
**
** Description      :   Complete the currently active IPC transfer. Performs
**                      source-specific completion handling such as clearing VIP
**                      local buffers or sending completion ACK to DM/HSM.
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
static void DltExt_Ipc_CompleteActiveTransfer(void)
{
  switch (DltExt_Ipc_ActiveTransfer.Source)
  {
  case DLTEXT_IPC_SOURCE_VIP_APP:
    DltExt_Ipc_ClearLocalBuffer(DltExt_Ipc_ActiveTransfer.BufferId);
    DltExt_Ipc_TimerActive = FALSE;
    DltExt_Ipc_FlushTimer = 0u;
    break;

  case DLTEXT_IPC_SOURCE_VIP_RESET:
    DltExt_Ipc_ClearLocalBuffer(DltExt_Ipc_ActiveTransfer.BufferId);
    break;

  case DLTEXT_IPC_SOURCE_DM:
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
    if (DltExt_Ipc_ActiveTransfer.BufferId == DLTEXT_DM_BUFFER1)
    {
      DltExt_Ipc_SendAckToDm(1u);
    }
    else
    {
      DltExt_Ipc_SendAckToDm(2u);
    }
#endif
    break;

  case DLTEXT_IPC_SOURCE_HSM:
#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
    if (DltExt_Ipc_ActiveTransfer.BufferId == DLTEXT_HSM_BUFFER1)
    {
      DltExt_Ipc_SendAckToHsm(1u);
    }
    else
    {
      DltExt_Ipc_SendAckToHsm(2u);
    }
#endif
    break;

  case DLTEXT_IPC_SOURCE_NONE:
  default:
    /* No action */
    break;
  }
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_HandleResponse
**
** Visibility       :   Private
**
** Description      :   Handle GIP ACK/NACK response for the currently active
**                      transfer. As per architecture, ACK and NACK are treated
**                      equally for completion and source release handling.
**
** Invocation       :
**
** Inputs           :   Status - ACK/NACK status value received from GIP
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void DltExt_Ipc_HandleResponse(uint8 Status)
{
#if (DLTEXT_UART_PRINT == STD_ON)
  (void)DltExt_Uart_Printf("DLT IPC: GIP response %u for buffer 0x%02X\r\n",
                           (uint32)Status,
                           (uint32)DltExt_Ipc_ActiveTransfer.BufferId);
#endif

  /* Per architecture, ACK and NACK are treated equally by VIP/DM/HSM.
     * Completion handling shall release the processed buffer/source in both cases.
     */
  DltExt_Ipc_CompleteActiveTransfer();

  DltExt_Ipc_RequestActive = 0u;
  DltExt_Ipc_ActiveTransfer.Source = DLTEXT_IPC_SOURCE_NONE;
    DltExt_Ipc_ActiveTransfer.BufferId = DLTEXT_BUFFER_NONE;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_FlushCurrentVipBank
**
** Visibility       :   Private
**
** Description      :   Trigger GIP read request for the currently active VIP
**                      application shared memory bank and switch VIP logging to
**                      the alternate bank for subsequent runtime frames.
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :   Std_ReturnType - E_OK if request is accepted,
**                      E_NOT_OK otherwise
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType DltExt_Ipc_FlushCurrentVipBank(void)
{
  DltExt_SharMemBufferIdType FilledBuffer;
  Std_ReturnType RetVal = E_NOT_OK;

  if (DltExt_Ipc_AppInfoMemPtr == 0u)
  {
    RetVal = E_OK;
  }
  else
  {
    if (DltExt_Ipc_AppInfoBufferPtr == DLTEXT_APPLOG_SHAREMEM_BUFFER1)
    {
      FilledBuffer = DLTEXT_VIP_SHAREMEMBUF1;
    }
    else
    {
      FilledBuffer = DLTEXT_VIP_SHAREMEMBUF2;
    }

    RetVal = DltExt_Ipc_SendRequest(FilledBuffer);
    if (RetVal == E_OK)
    {
      if (DltExt_Ipc_AppInfoBufferPtr == DLTEXT_APPLOG_SHAREMEM_BUFFER1)
      {
        DltExt_Ipc_AppInfoBufferPtr = DLTEXT_APPLOG_SHAREMEM_BUFFER2;
      }
      else
      {
        DltExt_Ipc_AppInfoBufferPtr = DLTEXT_APPLOG_SHAREMEM_BUFFER1;
      }

      DltExt_Ipc_AppInfoMemPtr = 0u;
      DltExt_Ipc_TimerActive = FALSE;
      DltExt_Ipc_FlushTimer = 0u;
    }
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_IsValidDmBankId
**
** Visibility       :   Private
**
** Description      :   Validate the DM bank id received through IPC and check
**                      whether it maps to a supported DM shared memory bank.
**
** Invocation       :
**
** Inputs           :   DmBankId - Bank id received from DM
**
** Outputs          :   boolean - TRUE if valid, FALSE otherwise
**
** Critical Section :
**
**==========================================================================*/
static boolean DltExt_Ipc_IsValidDmBankId(uint8 BankId)
{
  boolean RetVal = FALSE;

  if ((BankId == 1u) || (BankId == 2u))
  {
    RetVal = TRUE;
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_IsValidHsmBankId
**
** Visibility       :   Private
**
** Description      :   Validate the HSM bank id received through event
**                      notification and check whether it maps to a supported
**                      HSM shared memory bank.
**
** Invocation       :
**
** Inputs           :   HsmBankId - Bank id received from HSM
**
** Outputs          :   boolean - TRUE if valid, FALSE otherwise
**
** Critical Section :
**
**==========================================================================*/
static boolean DltExt_Ipc_IsValidHsmBankId(uint8 BankId)
{
  boolean RetVal = FALSE;

  if ((BankId == 1u) || (BankId == 2u))
  {
    RetVal = TRUE;
  }

  return RetVal;
}

/****************************************************************************
 * Exported Functions
 ****************************************************************************/
/*============================================================================
**
** Function Name    :   DltExt_Ipc_Init
**
** Visibility       :   Public
**
** Description      :   Initialize the DltExt IPC module internal state,
**                      VIP shared memory buffer pointers, timer state,
**                      pending request tracking, and active transfer context.
**
** Invocation       :   Called during DltExt initialization.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void DltExt_Ipc_Init(void)
{
  DltExt_Ipc_AppInfoMemPtr = 0u;
  DltExt_Ipc_AppInfoBufferPtr = DLTEXT_APPLOG_SHAREMEM_BUFFER1;
  DltExt_Ipc_FlushTimer = 0u;
  DltExt_Ipc_TimerActive = FALSE;
  DltExt_Ipc_PendingMask = 0u;
  DltExt_Ipc_RequestActive = 0u;
  DltExt_Ipc_ActiveTransfer.Source = DLTEXT_IPC_SOURCE_NONE;
  DltExt_Ipc_ActiveTransfer.BufferId = DLTEXT_BUFFER_NONE;
  DltExt_Ipc_GipUpFlag = FALSE;
  
  MemLib_MemSet(&DltExt_AppInfo_Buffer1[0], 0x00u, DLT_EXT_APPLOG_SHAREMEM_SIZE);
  MemLib_MemSet(&DltExt_AppInfo_Buffer2[0], 0x00u, DLT_EXT_APPLOG_SHAREMEM_SIZE);
  MemLib_MemSet(&DltExt_ResetInfo_SharedDumpBuffer[0], 0x00u, DLTEXT_RESET_SHMEM_SIZE);
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_DeInit
**
** Visibility       :   Public
**
** Description      :   Reset the DltExt IPC module internal state to default
**                      values and clear runtime ownership information for
**                      VIP/GIP/DM/HSM IPC handling.
**
** Invocation       :   Called during DltExt de-initialization.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void DltExt_Ipc_DeInit(void)
{
  DltExt_Ipc_AppInfoMemPtr = 0u;
  DltExt_Ipc_AppInfoBufferPtr = DLTEXT_APPLOG_SHAREMEM_BUFFER1;
  DltExt_Ipc_FlushTimer = 0u;
  DltExt_Ipc_TimerActive = FALSE;
  DltExt_Ipc_PendingMask = 0u;
  DltExt_Ipc_RequestActive = 0u;
  DltExt_Ipc_GipUpFlag = FALSE;
  DltExt_Ipc_ActiveTransfer.Source = DLTEXT_IPC_SOURCE_NONE;
  DltExt_Ipc_ActiveTransfer.BufferId = DLTEXT_BUFFER_NONE;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_MainFunction
**
** Visibility       :   Public
**
** Description      :   Main processing function of the DltExt IPC module.
**                      Handles VIP flush timeout monitoring, polls GIP ACK/NACK
**                      response for active transfer, and services any pending
**                      shared memory transfer requests from VIP/DM/HSM.
**
** Invocation       :   OS will invoke this function with configured periodicity.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void DltExt_Ipc_MainFunction(void)
{
  uint8 AckStatus = 0u;
  DltExt_SharMemBufferIdType NextBufferId;
  Std_ReturnType RetVal;

  if(DltExt_Ipc_GipUpFlag == FALSE)
  {
    DltExt_Ipc_GipStatusUp();
    if(DltExt_Ipc_GipUpFlag == FALSE)
    {
      return;
    }
  }

  if (DltExt_Ipc_TimerActive == TRUE)
  {
    if (DltExt_Ipc_FlushTimer < DLTEXT_IPC_TIMER_MAX_BEFORE_TIMEOUT)
    {
      DltExt_Ipc_FlushTimer += DLTEXT_IPC_MAINFUNCTION_PERIOD_MS;
    }
    else
    {
      DltExt_Ipc_FlushTimer = DLTEXT_IPC_FLUSH_TIMEOUT_MS;
    }

    if (DltExt_Ipc_FlushTimer >= DLTEXT_IPC_FLUSH_TIMEOUT_MS)
    {
      if (DltExt_Ipc_AppInfoMemPtr > 0u)
      {
        (void)DltExt_Ipc_FlushCurrentVipBank();
#if (DLTEXT_UART_PRINT == STD_ON)
        (void)DltExt_Uart_Printf("DLT IPC: 3 sec VIP flush timeout\r\n");
#endif
      }
      else
      {
        DltExt_Ipc_TimerActive = FALSE;
        DltExt_Ipc_FlushTimer = 0u;
      }
    }
  }

  if (DltExt_Ipc_RequestActive != 0u)
  {
    RetVal = DltExt_Ipc_ReadAck(&AckStatus);
    if (RetVal == E_OK)
    {
      DltExt_Ipc_HandleResponse(AckStatus);
    }
  }
  else
  {
    if (DltExt_Ipc_GetNextPending(&NextBufferId) == TRUE)
    {
      (void)DltExt_Ipc_SendRequest(NextBufferId);
    }
  }
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_GipStatusUp
**
** Visibility       :   Public
**
** Description      :   Propagate startup readiness indication from GIP to
**                      interested cores. This function sends the default
**                      startup ACK/ready indication to DM and HSM.
**
** Invocation       :   Called when GIP DLT communication becomes ready.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

void DltExt_Ipc_GipStatusUp(void)
{
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
  DltExt_Ipc_SendAckToDm(1u);
#endif

#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
  DltExt_Ipc_SendAckToHsm(1u);
#endif

  DltExt_Ipc_GipUpFlag = TRUE;

#if (DLTEXT_UART_PRINT == STD_ON)
  (void)DltExt_Uart_Printf("DLT IPC: GIP status up\r\n");
#endif
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_PushVipAppFrame
**
** Visibility       :   Public
**
** Description      :   Copy one VIP DLT application frame into the currently
**                      active VIP shared memory bank. If the bank does not
**                      have enough space, the current bank is flushed and the
**                      alternate bank is used.
**
** Invocation       :   Called by DltExt when a normal VIP runtime DLT frame
**                      shall be transferred through shared memory.
**
** Inputs           :   DataPtr  - Pointer to DLT frame buffer
**                  :   Length   - Length of DLT frame in bytes
**
** Outputs          :   Std_ReturnType - E_OK if accepted, E_NOT_OK otherwise
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType DltExt_Ipc_PushVipAppFrame(const uint8 *DataPtr, uint16 Length)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 FreeBytes = 0u;

  if ((DataPtr != NULL_PTR) &&
      (Length > 0u) &&
      (Length <= DLTEXT_IPC_VIP_BUFFER_SIZE_U16))
  {
    if (DltExt_Ipc_TimerActive == FALSE)
    {
      DltExt_Ipc_TimerActive = TRUE;
      DltExt_Ipc_FlushTimer = 0u;
    }

    if (DltExt_Ipc_AppInfoMemPtr <= DLTEXT_IPC_VIP_BUFFER_SIZE_U16)
    {
      FreeBytes = (uint16)(DLTEXT_IPC_VIP_BUFFER_SIZE_U16 - DltExt_Ipc_AppInfoMemPtr);
    }
    else
    {
      FreeBytes = 0u;
    }

    if (Length > FreeBytes)
    {
      RetVal = DltExt_Ipc_FlushCurrentVipBank();

      if ((RetVal == E_OK) && (DltExt_Ipc_AppInfoMemPtr <= DLTEXT_IPC_VIP_BUFFER_SIZE_U16))
      {
        FreeBytes = (uint16)(DLTEXT_IPC_VIP_BUFFER_SIZE_U16 - DltExt_Ipc_AppInfoMemPtr);
      }
      else
      {
        FreeBytes = 0u;
      }
    }
    else
    {
      RetVal = E_OK;
    }

    if ((RetVal == E_OK) && (Length <= FreeBytes))
    {
      if (DltExt_Ipc_AppInfoBufferPtr == DLTEXT_APPLOG_SHAREMEM_BUFFER1)
      {
        MemLib_MemCpy(&DltExt_AppInfo_Buffer1[DltExt_Ipc_AppInfoMemPtr], DataPtr, Length);
      }
      else
      {
        MemLib_MemCpy(&DltExt_AppInfo_Buffer2[DltExt_Ipc_AppInfoMemPtr], DataPtr, Length);
      }

      if (DltExt_Ipc_AppInfoMemPtr <= (uint16)(DLTEXT_IPC_VIP_BUFFER_SIZE_U16 - Length))
      {
        DltExt_Ipc_AppInfoMemPtr = (uint16)(DltExt_Ipc_AppInfoMemPtr + Length);
        RetVal = E_OK;
        if (DltExt_Ipc_TimerActive == FALSE)
        {
          DltExt_Ipc_TimerActive = TRUE;
          DltExt_Ipc_FlushTimer = 0u;
        }
      }
      else
      {
        RetVal = E_NOT_OK;
      }
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_PushVipResetFrame
**
** Visibility       :   Public
**
** Description      :   Copy one VIP reset replay DLT frame into the dedicated
**                      reset shared memory buffer and trigger or queue GIP read
**                      request for the reset buffer.
**
** Invocation       :   Called by DltExt when reset replay frame shall be
**                      transferred through dedicated reset shared memory.
**
** Inputs           :   DataPtr  - Pointer to reset DLT frame buffer
**                  :   Length   - Length of reset DLT frame in bytes
**
** Outputs          :   Std_ReturnType - E_OK if frame is handed over to IPC,
**                      E_NOT_OK otherwise
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType DltExt_Ipc_PushVipResetFrame(const uint8 *DataPtr, uint16 Length)
{
  Std_ReturnType RetVal = E_NOT_OK;

  if ((DataPtr != NULL_PTR) &&
      (Length > 0u) &&
      (Length <= DLTEXT_IPC_RESET_BUFFER_SIZE_U16))
  {
    MemLib_MemSet(&DltExt_ResetInfo_SharedDumpBuffer[0], 0x00u, DLTEXT_RESET_SHMEM_SIZE);
    MemLib_MemCpy(&DltExt_ResetInfo_SharedDumpBuffer[0], DataPtr, Length);

    RetVal = DltExt_Ipc_SendRequest(DLTEXT_SHAREMEMRESETBUF);
    if (RetVal != E_OK)
    {
      DltExt_Ipc_QueuePending(DLTEXT_SHAREMEMRESETBUF);
#if (DLTEXT_UART_PRINT == STD_ON)
      (void)DltExt_Uart_Printf("DLT IPC: reset frame queued\r\n");
#endif
      RetVal = E_OK;
    }
  }

  return RetVal;
}

/*============================================================================
**
** Function Name    :   CddIpc_DM_DltReadyResponse
**
** Visibility       :   Public
**
** Description      :   Receive and process DM buffer ready/full notification.
**                      Validates the received IPC message, identifies the DM
**                      buffer id, and triggers or queues GIP read request for
**                      the corresponding DM shared memory buffer.
**
** Invocation       :   Called from DM IPC ready indication callback path.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void CddIpc_DM_DltReadyResponse(void)
{
#if (DLT_DM_TO_GIP_INTERFACE == STD_ON)
  DltMsgType RespMsg;
  uint32 RespSize = sizeof(RespMsg);
  Std_ReturnType RetVal;
  DltExt_SharMemBufferIdType BufferId;

  RetVal = Cdd_IpcReceiveMsg(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP14,
                             (const void *)&RespMsg,
                             &RespSize);

  if ((RetVal == E_OK) &&
      (RespSize == sizeof(RespMsg)) &&
      (RespMsg.msgID == DLTEXT_IPC_MSG_ID) &&
      (DltExt_Ipc_IsValidDmBankId(RespMsg.Parameter) == TRUE))
  {
    BufferId = (RespMsg.Parameter == 1u) ? DLTEXT_DM_BUFFER1 : DLTEXT_DM_BUFFER2;

    /* If request is already active, SendRequest() will queue this buffer. */
    (void)DltExt_Ipc_SendRequest(BufferId);
  }
  else
  {
#if (DLTEXT_UART_PRINT == STD_ON)
    (void)DltExt_Uart_Printf("DLT IPC: invalid DM ready indication\r\n");
#endif
  }
#endif
}

/*============================================================================
**
** Function Name    :   DltExt_Ipc_HsmLogEvent
**
** Visibility       :   Public
**
** Description      :   Process HSM buffer ready/full notification. Decodes the
**                      buffer/bank id from HSM event data, validates it, and
**                      triggers or queues GIP read request for the corresponding
**                      HSM shared memory buffer.
**
** Invocation       :   Called from HSM log event callback path.
**
** Inputs           :   data - Encoded HSM buffer notification data
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
#if (DLT_HSM_TO_GIP_INTERFACE == STD_ON)
void DltExt_Ipc_HsmLogEvent(uint32 data)
{
  DltExt_SharMemBufferIdType BufferId = DLTEXT_HSM_BUFFER1;
  uint8 BankId = 0u;
  boolean ProcessEvent = FALSE;
  uint32 RawBankId;

  if ((data & DLT_BUFF_FULL_FLG) == DLT_BUFF_FULL_FLG)
  {
    RawBankId = (data >> 16u) & 0xFFu;

    if ((RawBankId == (uint32)DLTEXT_IPC_BANK_ID_1) ||
        (RawBankId == (uint32)DLTEXT_IPC_BANK_ID_2))
    {
      BankId = (uint8)RawBankId;
      ProcessEvent = DltExt_Ipc_IsValidHsmBankId(BankId);
    }

    if (ProcessEvent != FALSE)
    {
      if (BankId == DLTEXT_IPC_BANK_ID_1)
      {
        BufferId = DLTEXT_HSM_BUFFER1;
      }
      else
      {
        BufferId = DLTEXT_HSM_BUFFER2;
      }

      (void)DltExt_Ipc_SendRequest(BufferId);
    }
    else
    {
#if (DLTEXT_UART_PRINT == STD_ON)
      (void)DltExt_Uart_Printf("DLT IPC: invalid HSM bank indication %u\r\n", RawBankId);
#endif
    }
  }
}
#endif

#endif /* DLTEXT_CFG_SHMEM_IPC_PRESENT == STD_ON */
