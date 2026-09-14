#ifndef MAIN_C
#define MAIN_C

#define NVM_TRIPLE_BUFFER_TEST


#include "Stubs.h"
#include "Dio.h"
#include "Os.h"
#include "Spi.h"
#include "NvM.h"
#include "CddIpcAppRProcLinux.h"
#include "Ea.h"
#include "EepDrv.h"
#include "EcuM.h"
#include "I2c.h"
#include "Apm.h"
#include "EcuMExt.h"
#include "IoHwAb.h"
#include "LedDrv.h"
#include "sdl_esm.h"
#include "EccTest.h"
#include "NvMExt.h"
#include "SciDrv.h"
#include "sdl_esm_core.h"
#include "Chimes_Stub.h"

#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/

#ifdef NVM_TRIPLE_BUFFER_TEST
  #include "Rte_MemAbstract_Stub_Safe.h"
#endif

#include "SemaphoreP.h"

void FlsTst_MainFunction(void);
void SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void);
void SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void);
void SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0(void);
void SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0(void);
void SpiApp_McuMcspiJob0EndNotification(void);
void SpiApp_McuMcspiJob1EndNotification(void);
void SpiApp_McspiJob0EndNotificationCAN(void);
void SpiApp_McspiJob1EndNotification(void);
void SpiApp_invCache(uint8 *BufPtr,uint16 LenByte);
void SpiApp_wbCache(uint8 *BufPtr,uint16 LenByte);
void SpiApp_wbInvCache(uint8 *BufPtr,uint16 LenByte);
void SpiApp_McuMcspiSeq0EndNotification(void);
void SpiApp_McuMcspiSeq1EndNotification(void);
void SpiApp_McspiSeq0EndNotificationCAN(void);
void SpiApp_McspiSeq1EndNotification(void);
void SpiApp_Leddrv_McspiSeq2EndNotification(void);
void rCS_UclSystemCallbacks_ErrorNotification(uint8 DLInst, sint32 ErrorCode);
void rCS_UclSystemCallbacks_LinkStatusChanged(uint8 DLInst, sint32 Status);
void CDemApp_Impl_MainFunction(void);
void ComCallout_Impl_MainFunction(void);
void CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction(void);
void CComAbsMdl_stubs_MainFunction (void);
Std_ReturnType DltExt_ResetInfo_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
void CGdtCdd_Impl_MainFunction(void);
void CSigCdd_Impl_MainFunction (void);
Std_ReturnType CGdtCdd_Impl_OnCommand(uint8 Cmd);
void Mcu_Gpt1Notify(void);
void CFltMExt_MainFunction(void);
void CNvMExtSf_MainFunction(void);
void DemExt_MainFunction (void);
void CanIf_EnterCriticalSection(void);
void CanIf_ExitCriticalSection (void);
void CanSM_EnterCriticalSection(void);
void CanSM_ExitCriticalSection (void);
void ComM_EnterCriticalSection (void);
void ComM_ExitCriticalSection (void);
void Ctrl_Dim_Task   (void);
void Det_MainFunction   (void);
void Mdl_Linear_Interpolation_Task (void);
//void Mdl_TurnHazard_Task  (void);
void SlowGaugeAdapter_Task  (void);
void Com_IpduGroupControl (void);
void Com_SetIpduGroup(void);
#ifndef AUTOSAR_ETH_ENABLE
void EthIf_MainFunctionState(void);
void EthSM_MainFunction(void);
void EthTrcv_SetPhyTestMode(void);
void Eth_MdioIrqHdlrfunc(void);
void Eth_RxIrqHdlr_0func(void);
void Eth_TxIrqHdlr_0func(void);
void SoAd_MainFunction(void);
void TcpIp_MainFunction(void);
void CIoExp_IoExp_MainFunction(void);
#endif
void CCDD_FitManager_Impl_MainFunction(void);
void CCDD_McuFit_Impl_MainFunction(void);
void Ctrl_Illumination_Task(void);
void View_Illumination_Task(void);
void TrustedSwc_MainFunction (void);
void RstM_Impl_MainFunction (void);
Std_ReturnType CRtcCdd_Impl_OnCommand(uint8 Cmd);
void CRtcCdd_Impl_MainFunction (void);
Std_ReturnType Rte_Call_rp_Init_rp_Init_Ctrl_Dim_Init(uint8 cmdP);
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAppSlpIM_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEarlyHmi_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCtrl_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrvCdd_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDataAdapter_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand( uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcIllum_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSensorCdd_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand(  uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCmicCdd_Impl_OnCommand(uint8 cmdP );
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEcuWakeupM_Impl_OnCommand( uint8 cmdP );
Std_ReturnType NvM_SingleBlockNotification_SampleBlock1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
Std_ReturnType NvM_SingleBlockNotification_SampleBlock2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
void ClockP_usleep(uint64_t usec);

int32_t SemaphoreP_pend(SemaphoreP_Object *obj, uint32_t timeout)
{

    (void)timeout;
    /* if you want a tiny guard around RM during init/shutdown: */
    //SuspendAllInterrupts();
    return 0;;
}

void SemaphoreP_post(SemaphoreP_Object *obj)
{
    (void)obj;
    //ResumeAllInterrupts();
}

void _DebugP_logZone(uint32_t logZone, char *format, ...)
{

}

int32_t SemaphoreP_constructMutex(SemaphoreP_Object *obj)
{
    return 0;
}

void SemaphoreP_destruct(SemaphoreP_Object *obj)
{
    /* nothing to do */
}

int32_t SemaphoreP_constructBinary(SemaphoreP_Object *obj, uint32_t initCount)
{
    (void)initCount;
    return 0;
}

void ClockP_usleep(uint64_t usec)
{
    (void)usec;
}

#ifdef DSS_TEST_ENABLED

#include "SemaphoreP.h"



/**
 * \brief Semaphore type
 */
typedef enum SemaphoreP_Type_ {
    SemaphoreP_TYPE_BINARY, /**< Binary semaphore */
    SemaphoreP_TYPE_COUNTING, /**< Counting semaphore */
    SemaphoreP_TYPE_MUTEX /**< Mutual exclusion semaphore */
} SemaphoreP_Type;

/**
 * \brief Parameters passed during \ref SemaphoreP_construct
 */
typedef struct SemaphoreP_Params_ {

    uint32_t type; /**< see \ref SemaphoreP_Type */
    uint32_t initCount; /**< initial value of the semaphore. \n
        Only valid for \ref SemaphoreP_TYPE_COUNTING and \ref SemaphoreP_TYPE_BINARY. \n
        MUST be 0 or 1 for \ref SemaphoreP_TYPE_BINARY \n
        Ignored for \ref SemaphoreP_TYPE_MUTEX */
    uint32_t maxCount; /**< max value the semaphore can take. \n
        Only valid for \ref SemaphoreP_TYPE_COUNTING. \n
        MUST be >= SemaphoreP_Params.initCount \n
        Ignored for \ref SemaphoreP_TYPE_MUTEX and \ref SemaphoreP_TYPE_BINARY
        */

} SemaphoreP_Params;

typedef struct SemaphoreP_Struct_ {
    uint32_t type;
    uint32_t maxCount;
    volatile uint32_t count;
    volatile uint32_t nestCount;
} SemaphoreP_Struct;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void SemaphoreP_Params_init(SemaphoreP_Params *params);

int32_t SemaphoreP_construct(SemaphoreP_Object *obj,SemaphoreP_Params *params);

void DssDisplayTest(void);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void SemaphoreP_Params_init(SemaphoreP_Params *params)
{

}

int32_t SemaphoreP_construct(SemaphoreP_Object *obj, SemaphoreP_Params *params)
{
    return 0;
}

int32_t SemaphoreP_constructBinary(SemaphoreP_Object *obj, uint32_t initCount)
{
    return 0;
}

int32_t SemaphoreP_constructCounting(SemaphoreP_Object *obj, uint32_t initCount, uint32_t maxCount)
{
    return 0;
}

int32_t SemaphoreP_constructMutex(SemaphoreP_Object *obj)
{
    return 0;
}

void SemaphoreP_destruct(SemaphoreP_Object *obj)
{
    /* nothing to do */
}


int32_t SemaphoreP_pend(SemaphoreP_Object *obj, uint32_t timeout)
{

    return 0;
}

void SemaphoreP_post(SemaphoreP_Object *obj)
{

}

void _DebugP_logZone(uint32_t logZone, char *format, ...)
{

}

void CacheP_wb(void *addr, uint32_t size, uint32_t type)
{
}


#endif

#ifdef NVM_TRIPLE_BUFFER_TEST
static volatile uint8 Triple_ReadTest = 0;
static volatile uint8 Triple_WriteTest = 0;
static volatile uint32 BsConst_Compensation_Line_Shift_b = 0U;
static volatile uint32 BsConst_Compensation_Line_Slope_m = 0U;
#endif


#if defined(ECC_ICACHE_TEST) || defined(ECC_DCACHE_TEST)
volatile uint8 TestEcc = 0;
volatile uint8 BrkFlag = 1;
#endif   /* #if defined(ECC_ICACHE_TEST) || defined(ECC_DCACHE_TEST) */

extern bool SDL_ESM_getBaseAddr(const SDL_ESM_Inst esmInstType, uint32_t *esmBaseAddr);
extern void FltMExt_MainFunction(void);
extern void FltM_HandlePostReset(void);

int main(void);
int main(void)
{
    #ifdef BOOT_KPI_LOG_EN
    BOOT_KPI_LOG(KPI_ID_VIP_MAIN, "VIP_MAIN");
    #endif   /*BOOT_KPI_LOG_EN*/

    #if defined(ECC_ICACHE_TEST) || defined(ECC_DCACHE_TEST)
    /* This part is the FIT test code for ICACHE and DCACHE test for ECC */
    /* Shall be enabled only for testing */
    while(BrkFlag == 1);
    if(TestEcc == 1)
    {
        EccTest_CacheTest();
    }
    #endif 

    EcuM_Init();

    return 0;
}


uint8 PRAM_SampleBlock1[8];

uint8 ROMDefault_SampleBlock1[8] =
{
    1,2,3,4,5,6,7,8
};
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMSampleBlock1 - CallBack  */
Std_ReturnType NvM_SingleBlockNotification_SampleBlock1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult )
{
    (void)ServiceId;
    (void)JobResult;
    return E_OK;
}

uint8 PRAM_SampleBlock2[16];

uint8 ROMDefault_SampleBlock2[16] =
{
    16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
};
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SampleBlock2 - CallBack  */
Std_ReturnType NvM_SingleBlockNotification_SampleBlock2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult )
{
    (void)ServiceId;
    (void)JobResult;
    return E_OK;
}



TASK(InitTask)
{
    EcuM_StartupTwo();

    (void)TerminateTask();
}

/* Os Idle Task */
TASK(OsTask_IdleTask)
{
    while(1)
    {

    }
}

void UserPreTaskHook(void)
{
#ifdef APM_ENABLED
    TaskType TaskID = INVALID_TASK;
    TaskStateType TaskState = (TaskStateType)0;

    (void)GetTaskID(&TaskID);
    (void)GetTaskState(TaskID, &TaskState);

    Apm_PreTaskProcess(TaskID, TaskState);
#endif
}

void UserPostTaskHook(void)
{
#ifdef APM_ENABLED
    TaskType TaskID = INVALID_TASK;
    TaskStateType TaskState = (TaskStateType)0;

    (void)GetTaskID(&TaskID);
    (void)GetTaskState(TaskID, &TaskState);

    Apm_PostTaskProcess(TaskID, TaskState);
#endif
}

void UserPreISRHook(ISRType x)
{
#ifdef APM_ENABLED
    Apm_PreIsrProcess(x);
#endif
}

void UserPostISRHook(ISRType x)
{
#ifdef APM_ENABLED
    Apm_PostIsrProcess(x);
#endif
}


static void SdkTest(void);


void SpiApp_invCache(uint8 *BufPtr,uint16 LenByte)
{
    (void)LenByte;
}

void SpiApp_wbCache(uint8 *BufPtr,uint16 LenByte)
{
    (void)LenByte;
}

void SpiApp_wbInvCache(uint8 *BufPtr,uint16 LenByte)
{
    (void)LenByte;
}

void SpiApp_McuMcspiJob0EndNotification(void)
{
}
void SpiApp_McuMcspiJob1EndNotification(void)
{
}

void SpiApp_McspiJob0EndNotificationCAN(void)
{

}
void SpiApp_McspiJob1EndNotification(void)
{

}
void SpiEEJobEndNotification(void);

void SpiApp_McuMcspiSeq0EndNotification(void)
{
    SpiEEJobEndNotification();

}
void SpiApp_McuMcspiSeq1EndNotification(void)
{

}

void SpiApp_McspiSeq0EndNotificationCAN(void)
{

}
void SpiApp_McspiSeq1EndNotification(void)
{

}

void SpiApp_Leddrv_McspiSeq2EndNotification(void)
{

}

void SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0(void)
{
}
void SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0(void)
{
}

void rCS_UclSystemCallbacks_ErrorNotification(uint8 DLInst, sint32 ErrorCode)
{
    (void)DLInst;
    (void)ErrorCode;
}
void rCS_UclSystemCallbacks_LinkStatusChanged(uint8 DLInst, sint32 Status)
{
    (void)DLInst;
    (void)Status;
}
//void CDcmApp_Impl_MainFunction(void){}
void CDemApp_Impl_MainFunction(void){}
// void CGdtCdd_Impl_MainFunction(void){}
// void CGdtCdd_Impl_OnCommand(void){}
void OsTask_Can0DataRxEvfunc(void){}
void OsTask_Can1DataRxEvfunc(void){}
void OsTask_FotaEvfunc(void){}
//void CComAbsMdl_OnDataRx_VehicleSpeedABS(void){}
void ComCallout_Impl_MainFunction(void){}
void CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction(void){}
void CComAbsMdl_stubs_MainFunction (void) {}

boolean LVSD_Flag = FALSE;
boolean HVSD_Flag = FALSE;

void Get_LVSD_Flag(boolean *flag)
{
    *flag = LVSD_Flag;
}
void Get_HVSD_Flag(boolean *flag)
{
    *flag = HVSD_Flag;
}

Std_ReturnType DltExt_ResetInfo_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult )
{
    (void)ServiceId;
    (void)JobResult;
    return E_OK;
}
#ifndef EHMI_ENABLE

 void CGdtCdd_Impl_MainFunction(void){}
 void CSwcDispMonSf_Impl_MainFunction(void) {}
 Std_ReturnType CGdtCdd_Impl_OnCommand(uint8 Cmd)
 {
    (void)Cmd;
     return E_OK;

 }
 void OsTaskRenderfunc(void)
 {
    (void)TerminateTask();
 }

Std_ReturnType  CSigCdd_Impl_OnCommand( uint8 Cmd )
{
	return E_OK;
}
void CSigCdd_Impl_MainFunction (void)
{

}
Std_ReturnType CSwcDispMonSf_Impl_OnCommand (uint8 Cmd)
{
    (void)Cmd;
    return E_OK;
}
#endif

/**
 * \brief Used to enter interrupt protected area
 */
void SchM_Enter_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void){}
/**
 * \brief Used to exit interrupt protected area
 */
void SchM_Exit_Cdd_Ipc_IPC_EXCLUSIVE_AREA_0(void){}

void NvM_MultiBlockJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);

//void NvMExt_MultipleJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult)
//{
//    NvM_MultiBlockJobEndNotification((uint8)ServiceId, (NvM_RequestResultType)JobResult);
//}


void Mcu_Gpt1Notify(void)
{

}

Std_ReturnType SDR_ESM_errorInsert (const SDL_ESM_Inst esmInstType,
    const SDL_ESM_ErrorConfig_t *esmErrorConfig)
{
    uint32_t   esmInstBaseAddr;
    Std_ReturnType result = E_NOT_OK;

    if (SDL_ESM_getBaseAddr(esmInstType, &esmInstBaseAddr) == ((bool)true)) {
    if (esmErrorConfig != ((void *)0u)) {
    if ((esmErrorConfig->groupNumber < SDL_ESM_MAX_EVENT_MAP_NUM_WORDS)
    && (esmErrorConfig->bitNumber < 32u)) {
    /* Insert error */
    (void)SDL_ESM_setIntrStatusRAW(esmInstBaseAddr,
            (esmErrorConfig->groupNumber*32u)
            + esmErrorConfig->bitNumber);
    result = E_OK;
    }
    }
}

return result;
}
#include <sdl_esm.h>
#include <sdl_rti.h>
#include <hw_types.h>

/* Test Init API for Wdg RTI ESM source */
void Wdg_ESMInitTest(void)
{
    (void)SDL_ESM_reset(SOC_WKUP_ESM_BASE);
    /* The below function can be changed to force an error for diagnostic
    * reasons. Make sure we're not in force error mode */
    (void)SDL_ESM_setMode(SOC_WKUP_ESM_BASE, ESM_OPERATION_MODE_NORMAL);
    /* Enable this ESM Error Signal */
    (void)SDL_ESM_enableIntr(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_PLS_EVENT0_MCU_RTI0_INTR_WWD_0);
    (void)SDL_ESM_enableIntr(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_CPU0_EXP_INTR_0);
    /* Set the output interrupt priority level */
    (void)SDL_ESM_setIntrPriorityLvl(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_PLS_EVENT0_MCU_RTI0_INTR_WWD_0, ESM_INTR_PRIORITY_LEVEL_HIGH);
    (void)SDL_ESM_setIntrPriorityLvl(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_CPU0_EXP_INTR_0, ESM_INTR_PRIORITY_LEVEL_HIGH);
    /* Enable Error Pin on this ESM Error Signal */
    (void)SDL_ESM_setInfluenceOnErrPin(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_PLS_EVENT0_MCU_RTI0_INTR_WWD_0, TRUE);
    (void)SDL_ESM_setInfluenceOnErrPin(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_CPU0_EXP_INTR_0, TRUE);
    /* Enable for all ESM Error Signals */
    (void)SDL_ESM_enableGlobalIntr((SOC_WKUP_ESM_BASE));
}

/* ISR Handler for WKUP_ESM0 High Priority Interrupts */
ISR(WkupEsmIntr)
{
    uint32_t intrStatus;
    /* Clear RTI interrupt status */
    (void)SDL_RTI_getStatus(SDL_INSTANCE_MCU_RTI0_CFG, &intrStatus);
    (void)SDL_RTI_clearStatus(SDL_INSTANCE_MCU_RTI0_CFG, intrStatus);
    /* Clear the ESM interrupt source */
    (void)SDL_ESM_clearIntrStatus(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_PLS_EVENT0_MCU_RTI0_INTR_WWD_0);
    (void)SDL_ESM_clearIntrStatus(SOC_WKUP_ESM_BASE, SDLR_WKUP_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_CPU0_EXP_INTR_0);
}


  void CFltMExt_MainFunction(void)
  {
    FltMExt_MainFunction();
  }

static volatile uint8 FltM_Report_Test = 0;
static volatile uint8 FltM_Handle_Post  = 0;
static uint8 FltM_Log_Data[5] = {1,2,3,4,5};
 volatile uint8 ChimesTest = 1;
typedef enum
{
    FAULTTEST_UNDEFINED   = 1U,
    FAULTTEST_PREFETCH    = 2U,
    FAULTTEST_DATAABORT   = 3U,
    FAULTTEST_NONE        = 255U
} FaultTestIdType;

static volatile uint8 FaultTestCase = 0;

static void FaultTrigger_Run(FaultTestIdType testId);

void CNvMExtSf_MainFunction(void)
{
  FaultTrigger_Run(FaultTestCase);

  if(FltM_Handle_Post == 1U)
  {
    FltM_Handle_Post = 0U;
    FltM_HandlePostReset();
  }

  if(FltM_Report_Test == 1U)
  {
    FltM_Report_Test = 0U;
    (void)FltM_ReportFault(DCC_FAIL, FLTM_ACTIVE, &FltM_Log_Data[0], 5U);
  }
  if(FltM_Report_Test == 2U)
  {
    FltM_Report_Test = 0U;
    (void)FltM_ReportFault(ECC_FAULT, FLTM_ACTIVE, &FltM_Log_Data[0], 5U);
  }
  if(FltM_Report_Test == 3U)
  {
    FltM_Report_Test = 0;
    (void)FltM_ReportFault(0xF70AU, FLTM_ACTIVE, &FltM_Log_Data[0], 5U);
  }

  if(FltM_Report_Test == 4U)
  {
        static uint8 Uart_TxBuf[] = "\r\n Main Domain UART test :) ";
      (void)SciDrv_DisableChn(1U);
      (void)SciDrv_SetAsyncMode(1U,eSciDrvAsyncMode_Dma);
      (void)SciDrv_EnableChn(1U);
      (void)SciDrv_SetupEB(1U, \
                          eSciDrvDirection_Transmit, (uint8 *)Uart_TxBuf, sizeof(Uart_TxBuf));
      (void)SciDrv_ASyncTransmit(1U);
      FltM_Report_Test = 0;
  }

  /* Chimes Step 1: AMP_SHUTDOWN pin */
  if(ChimesTest == 1U)
  {
    Dio_WriteChannel(Main_GPIO0_Channel_36, 1U);
      ChimesTest = 2U;
  }
  /* Chimes Step 2: Play Chimes */
  else if(ChimesTest == 2U)
  {
    ChimesTest = 0;
    /*BOOT_KPI_LOG_EN*/ 
    #ifdef BOOT_KPI_LOG_EN
    BOOT_KPI_LOG(KPI_ID_VIP_FIRST_CHIMES_PLAY, "CHIMEPLAY"); 
    #endif 
    (void)Play_Chimes();
  }
  else
  {
        /* Do Nothing */
  }



#ifdef NVM_TRIPLE_BUFFER_TEST
    if(Triple_ReadTest == 1U)
    {
      Triple_ReadTest = 0;
      Rte_Read_BsConst_Compensation_Line_Shift_b_Value(&BsConst_Compensation_Line_Shift_b);
      Rte_Read_BsConst_Compensation_Line_Slope_m_Value(&BsConst_Compensation_Line_Slope_m);
    }

    if(Triple_WriteTest == 1U)
    {
      Triple_WriteTest = 0;
      (void)Rte_Write_BsConst_Compensation_Line_Shift_b_Value(0x12345678);
      (void)Rte_Write_BsConst_Compensation_Line_Slope_m_Value(0x12345678);
    }
  #endif
}


/* ---------------------------------------------------------------
 *  Service name     : FaultTrigger_Run
 *  Service ID       : 0xA1 (test stub)
 *  Synchronous      : Synchronous
 *  Reentrancy       : Non-Reentrant
 *  Context          : Task context (call from app task)
 *  Description      : Triggers a controlled ARM Cortex-R5 exception
 *                     to test FltM/RstM dump + reset handling.
 *  Parameters (in)  : testId - selects which fault to generate
 *  Parameters (out) : None
 *  Return value     : None
 *  Notes            : Causes system crash/reset — use only on test builds!
 * --------------------------------------------------------------- */
static void FaultTrigger_Run(FaultTestIdType testId)
{
    switch (testId)
    {
        case FAULTTEST_UNDEFINED:
            /* Execute an invalid instruction */
            __asm volatile (".word 0xFFFFFFFF\n");
            break;

        case FAULTTEST_PREFETCH:
        {
            /* Jump to unmapped address -> Prefetch abort */
            void (*bad_fn)(void) = (void(*)(void))0xFFFFFFFCU;
            bad_fn();
            break;
        }

        case FAULTTEST_DATAABORT:
        {
            /* Dereference unmapped address -> Data abort */
            volatile uint32 *ptr = (uint32 *)0xFFFFFFFCU;
            (void)(*ptr);
            break;
        }

        default:
            /* No action */
            break;
    }
}

void DemExt_MainFunction (void){}
void FlsTst_MainFunction(void){}
//EcuWakeupM Icu Stubs : will be removed once Icu integrated - bmalgeka
void Icu_SetMode(void){}
void Icu_EnableEdgeDetection(void){}
void Icu_DisableEdgeDetection(void){}
void Icu_GetInputState(void){}
void Icu_EnableWakeup(void){}
void Icu_DisableWakeup(void){}
void Icu_CheckWakeup(void){}
//void Icu_EnableNotification(void){}
//void Icu_DisableNotification(void){}
void Port_SetToDioMode(void){}
void Port_SetToAlternateMode(void){}
void Port_SetPinMode(void){}
//void OsTask_ModeMgtfunc(void){}
//void Ctrl_WSS_Impl_MainFunction(void){}
//void CCtrl_Telltale_Adapter_Task(void){}
//void CCtrl_Telltale_Impl_MainFunction(void){}
//void CView_Telltale_Impl_MainFunction(void){}
//void CWarnMsg_Core_Observer_Impl_MainFunction(void){}
void CanIf_EnterCriticalSection(void){}
void CanIf_ExitCriticalSection (void){}
void CanSM_EnterCriticalSection(void){}
void CanSM_ExitCriticalSection (void){}
void ComM_EnterCriticalSection           (void){}
void ComM_ExitCriticalSection     (void){}
void Ctrl_Dim_Task   (void){}
//void Ctrl_warning_Task  (void){}
void Det_MainFunction   (void){}
//void FastGaugeAdapter_Task  (void){}
//void Mdl_Airbag_Task     (void){}
//void Mdl_Dim_Task    (void){}
//void Mdl_Gear_Task   (void){}
void Mdl_Linear_Interpolation_Task (void){}
// void Mdl_SafetyAdapter_OnDataRx_B_EBW2     (void){}
// void Mdl_SafetyAdapter_OnDataRx_B_PKBLP  (void){}
// void Mdl_SafetyAdapter_OnDataRx_SCSBZR  (void){}
// void Mdl_SafetyAdapter_OnDataRx_VSCOFF (void){}
//void Mdl_SafetyAdapter_Task     (void){}
//void Mdl_Speed_Task   (void){}
//void Mdl_Tacho_Task (void){}
//void Mdl_TurnHazard_Task  (void){}
//void Mdl_wAirbag_Task   (void){}
//void Mdl_wFuelLidOpen_Task  (void){}
// void OnDre_UCL_HudWarnStatus  (void){}
// void OnDre_UCL_WarnStatus   (void){}
void SlowGaugeAdapter_Task  (void){}
//void View_Speed_Task      (void){}
//void WarnMsg_Core_TmrSupport_Task    (void){}
void Com_IpduGroupControl (void){}
void Com_SetIpduGroup(void){}
#ifndef AUTOSAR_ETH_ENABLE
void EthIf_MainFunctionState(void){}
void EthSM_MainFunction(void){}
void EthTrcv_SetPhyTestMode(void){}
void Eth_MdioIrqHdlrfunc(void){}
void Eth_RxIrqHdlr_0func(void){}
void Eth_TxIrqHdlr_0func(void){}
void SoAd_MainFunction(void){}
void TcpIp_MainFunction(void){}
void CIoExp_IoExp_MainFunction(void){}
#endif
void CCDD_FitManager_Impl_MainFunction(void){}
void CCDD_McuFit_Impl_MainFunction(void){}
void Ctrl_Illumination_Task(void){}
void View_Illumination_Task(void){}
void TrustedSwc_MainFunction (void){}
void RstM_Impl_MainFunction (void){}
void DltExt_OnDreDLTMessageReadAckData(void){}
//Below stubs functions to be removed once the respective component integrated
// FUNC(Std_ReturnType, CWarnMsg_Core_Observer_CODE) CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
// FUNC(Std_ReturnType, Ctrl_Illumination_CODE) Ctrl_Illumination_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
// FUNC(Std_ReturnType, View_Illumination_CODE) View_Illumination_Impl_OnCommand(ECmpCmd cmdP)
// {

// }
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEcuWakeupM_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCmicCdd_Impl_OnCommand(uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSensorCdd_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcIllum_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand(  uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDataAdapter_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrvCdd_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCtrl_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEarlyHmi_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType  Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAppSlpIM_Impl_OnCommand( uint8 Cmd )
{
    (void)Cmd;
    return E_OK;
}
Std_ReturnType Rte_Call_rp_Init_rp_Init_Ctrl_Dim_Init(uint8 Cmd)
{
    (void)Cmd;
    return E_OK;
}

#ifndef RTCCDD_ENABLE
void CRtcCdd_Impl_MainFunction (void)
{

}
Std_ReturnType CRtcCdd_Impl_OnCommand(uint8 Cmd)
{
    (void)Cmd;
    return E_OK;
}
#endif

#endif /* MAIN_C */


