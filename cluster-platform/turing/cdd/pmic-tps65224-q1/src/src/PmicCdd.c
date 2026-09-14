/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
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
 * @file        PmicCdd.c
 * @details     <b> TI PMIC driver for TPS65224 </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef PMICCDD_C_
#define PMICCDD_C_

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

#include "PmicCdd.h"
#include "I2c.h"
#include "Gpt.h"
#include "Dio.h"
#include "CmpLib.h"

#define PMICCDD_SEC_CODE_START
#define PMICCDD_CORE_CONST_SEC_START
#define PMICCDD_CORE_DATA_SEC_START
#define PMICCDD_CORE_BSS_SEC_START

#include "MemMap.h"

/*! @brief  Instance of cmplib life-cycle */
CMPLIB_INSTANCE(PmicCdd)

/* MISRA Rule 20.9: VC_TEST must always be defined before use in #if directives.
   PmicCdd_Cfg.h (included via PmicCdd.h) is the canonical definition source.
   This fallback ensures the macro is never undefined during static analysis. */
#ifndef VC_TEST
#define VC_TEST (STD_OFF)
#endif

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
/* Buffer lengths */
#define PMICCDD_TXBUF_LENGTH                                           3U
#define PMICCDD_RXBUF_LENGTH                                           4U

#define PMICCDD_MAX_I2C_SEQUENCE (uint8)(PmicCdd_SeqQID_count)

#define PMICCDD_MAX_I2C_SEQUENCE_QUEUE ((uint8)((uint32)PmicCdd_SeqQID_count * 2U))

#define PMIC_ADC_CONVERSION_REQUEST_START 0x01U
#define PMIC_ADC_CONVERSION_REQUEST_STOP 0x00U

#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
#define PMICCDD_CRC_LENGTH 1U
#else
#define PMICCDD_CRC_LENGTH 0u
#endif

#if (PMICCDD_ENABLE_WDG == STD_ON)
#define PMIC_WD_BASE_US (550U)     /* 0.55 ms = 550 µs */
#define PMIC_WD_TOL_MIN_NUM (95U)  /* 0.95 multiplier numerator */
#define PMIC_WD_TOL_MAX_NUM (105U) /* 1.05 multiplier numerator */
#define PMIC_WD_TOL_DEN (100U)

#ifndef PMIC_PULSE_MS
#define PMIC_PULSE_MS (5u)
#endif

#ifndef PMIC_PHASE_MARGIN_MS
#define PMIC_PHASE_MARGIN_MS (1U) /* guard margin inside WIN2 */
#endif

#ifndef PMIC_LWENTER_POST_PULSE_MARGIN_MS
#define PMIC_LWENTER_POST_PULSE_MARGIN_MS (2U) /* time after a forced service pulse to let the
                                                   PMIC register it and complete the sequence
                                                   transition; TRIG_WDOG deglitch spec is 30us,
                                                   this is a generous multiple of that */
#endif

#ifndef PMIC_LWENTER_CONFIRM_TIMEOUT_MS
#define PMIC_LWENTER_CONFIRM_TIMEOUT_MS (20U) /* bound on the wd_return_longwin readback-confirm
                                                  retry loop - normally satisfied on the first
                                                  attempt; this only guards against a stuck/
                                                  unresponsive I2C bus so the reset path can't
                                                  hang forever with interrupts masked */
#endif

/* GTC ticks per microsecond - lets the phase math work directly on the us-domain
   window formulas below without losing sub-ms resolution to integer division. */
#define PMIC_GTC_TICKS_PER_US (PMIC_GTC_TICKS_PER_MS / 1000U)

/* Integer-only window time formulas */
#define PMIC_GET_TWINDOW_MIN_US(win) ((((win) + 1U) * PMIC_WD_BASE_US * PMIC_WD_TOL_MIN_NUM) / PMIC_WD_TOL_DEN)
#define PMIC_GET_TWINDOW_MAX_US(win) ((((win) + 1U) * PMIC_WD_BASE_US * PMIC_WD_TOL_MAX_NUM) / PMIC_WD_TOL_DEN)

/* Convert microseconds to milliseconds */
#define US_TO_MS(us) ((us) / 1000U)

/* Calculate GPT reload time from configured values */
#define PMIC_CALC_GPT_RELOAD_MS(win1, win2) \
  (US_TO_MS(PMIC_GET_TWINDOW_MAX_US(win1) + (PMIC_GET_TWINDOW_MIN_US(win2) / 4U)))
#endif

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

typedef enum
{
  PmicCdd_Idle,
  PmicCdd_InitRequested,
  PmicCdd_InitError,
  PmicCdd_SeqFailed,
  PmicCdd_LWEnter_McuReset,
  PmicCdd_InitProgress,
  PmicCdd_InitDone,
  PmicCdd_MainProcess_Idle,
  PmicCdd_MainProcess_SeqReqested,
  PmicCdd_MainProcess_SeqProgress,
  PmicCdd_MainProcess_SeqDone
} ePmicCdd_FSM_StateType;

ePmicCdd_FSM_StateType ePmicCdd_FSM_State = PmicCdd_Idle;
typedef enum
{
  PmicCdd_None = 0,
  PmicCdd_Config2,
  PmicCdd_ReadConfig2,
  PmicCdd_PowerOnConfig,
  PmicCdd_Gpio1,
  PmicCdd_Gpio2,
  PmicCdd_Gpio3,
  PmicCdd_Gpio4,
  PmicCdd_Gpio5,
  PmicCdd_Gpio6,
  PmicCdd_read_WdErrStatus,
  PmicCdd_write_WdErrStatus,
  PmicCdd_LongWindowCfg,
  PmicCdd_WdWin1Cfg,
  PmicCdd_WdWin2Cfg,
  PmicCdd_WdThrCfgRead,
  PmicCdd_WdThrCfg,
  PmicCdd_WdMode,
  PmicCdd_ReadWdMode,
  PmicCdd_FailCnt,
#if (PMICCDD_ENABLE_ESM == STD_ON)
  PmicCdd_EsmDelay1Cfg,
  PmicCdd_EsmDelay2Cfg,
  PmicCdd_EsmModeCfg,
  PmicCdd_EsmHmaxCfg,
  PmicCdd_EsmHminCfg,
  PmicCdd_EsmLmaxCfg,
  PmicCdd_EsmLminCfg,
  PmicCdd_EsmStart,
#endif
#if (PMICCDD_ENABLE_ADC == STD_ON)
  PmicCdd_Write_AdcCtrl,
  PmicCdd_Read_AdcCtrl,
  PmicCdd_Read_AdcResult,
  PmicCdd_Read_AdcResult1,
#endif
  PmicCdd_Read_IntTop,
  PmicCdd_Read_IntBuck,
  PmicCdd_Write_IntBuck,
  PmicCdd_Read_IntLdoVmon,
  PmicCdd_Write_IntLdoVmon,
  PmicCdd_Read_IntGpio,
  PmicCdd_Write_IntGpio,
  PmicCdd_Read_IntStartup,
  PmicCdd_Write_IntStartup,
  PmicCdd_Read_IntMisc,
  PmicCdd_Write_IntMisc,
  PmicCdd_Read_IntModerateError,
  PmicCdd_Write_IntModerateError,
  PmicCdd_Read_IntSevereError,
  PmicCdd_Write_IntSevereError,
  PmicCdd_Read_IntFsmError,
  PmicCdd_Write_IntFsmError,
  PmicCdd_Read_IntEsm,
  PmicCdd_Write_IntEsm,
  PmicCdd_Read_MaskStartup,
  PmicCdd_Write_MaskStartup,
  PmicCdd_Read_RecovCntReg1,
  PmicCdd_Read_RecovCntReg2,
  PmicCdd_Write_RecovCntReg2,
  PmicCdd_Write_SpreadSpectrum,
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
  PmicCdd_Write_Buck1Ctrl,
  PmicCdd_Write_Buck2Ctrl,
  PmicCdd_Write_Buck3Ctrl,
  PmicCdd_Write_Buck4Ctrl,
  PmicCdd_Write_Ldo1Ctrl,
  PmicCdd_Write_Ldo2Ctrl,
  PmicCdd_Write_Ldo3Ctrl,
  PmicCdd_Write_VccaVmonCtrl,
  #endif
  PmicCdd_Write_RegisterLock,
  PmicCdd_Write_RegisterUnlock,
  PmicCdd_Read_DevRev,
  PmicCdd_Read_NvmCode1,
  PmicCdd_Read_NvmCode2,
#ifdef TEST_RW
  PmicCdd_TestRead,
  PmicCdd_TestwdgRead,
#endif
  PmicCdd_SeqQID_count
} ePmicCdd_I2cSeqQIDType;

#if (PMICCDD_ENABLE_ADC == STD_ON)
typedef enum
{
  PmicCdd_ADC_Conv_Idle,
  PmicCdd_ADC_Conv_Requested,
  PmicCdd_ADC_Conv_Started,
  PmicCdd_ADC_Conv_Done,
  PmicCdd_ADC_Read_Result,
  PmicCdd_ADC_Conv_NoInit,
} PmicCdd_Adc_FSM_State_Type;
#endif

typedef void (*PmicCdd_SeQEndCbFuncPtr)(ePmicCdd_I2cSeqQIDType);

typedef struct
{
  ePmicCdd_I2cSeqQIDType eI2cSeqQID;
  uint8 *TxBuffer;
  uint8 *RxBuffer;
  uint8 TxLength;
  uint8 RxLength;
  uint8 DeviceAddress;
  PmicCdd_SeQEndCbFuncPtr PmicCdd_SeQEndCb;
} PmicCdd_I2c_SequenceType;

typedef enum
{
  PMIC_WDG_IDLE = 0u, /* not feeding */
  PMIC_WDG_HIGH_PW,   /* pin HIGH, waiting to end PW */
  PMIC_WDG_LOW_GAP    /* pin LOW, waiting gap (Δt - PW) */
} PmicWdg_IsrStateType;

// Flag to check if CRC is enabled or not
uint8 PmicCdd_CrcEnabled = FALSE;
uint8 PmicCdd_Read_FailCnt = FALSE;
uint8 PmicCdd_TxCrcErrorFlag = FALSE;
uint8 PmicCdd_RxCrcErrorFlag = FALSE;
uint8 PmicCdd_ReceiveCRCError_Count = 0u;
uint8 PmicCdd_TransmitCRCError_Count = 0u;
uint8 PmicCdd_AbistFail = FALSE;
uint8 PmicCdd_EnableBit_Status = FALSE;
uint8 PmicCdd_Reset_Status = FALSE;
uint8 PmicCdd_Buck_Reset_Status = FALSE;
uint8 PmicCdd_Ldo_Reset_Status = FALSE;
uint8 PmicCdd_PowerSupplyFault_Reset_Status = FALSE;
PmicCdd_ResetReasonType PmicCdd_Detailed_Reset_Reason = PmicCdd_Reset_Reason_None;
/* after all initialization status reads and their callbacks complete.
   Keeping a latched value prevents later runtime interrupts from changing the last-reset reason. */
static volatile PmicCdd_ResetReasonType PmicCdd_Latched_Reset_Reason = PmicCdd_Reset_Reason_Not_Ready;
uint8 PmicCdd_ReadIntTop_Status = FALSE;

// SW hang logging Status
volatile uint8 PmicCdd_WdgReset_Request = FALSE;
uint8 PmicCdd_DumpLog_Status = FALSE;
uint8 PmicCdd_PmicWdg_FailInt_Status = FALSE;

/* PC capture via IRQ-banked LR — OS-independent, works on mOS and Vector OS without
   touching any OS delivery files. After ISR Phase 1 (srsfd + cps #SYS), LR_irq is
   copied to the task SYS stack but the banked IRQ register is never cleared by the OS.
   Reading it at the top of the ISR body gives the exact interrupted PC.
   Safe when Cat2 nesting is disabled (standard AUTOSAR flat-level: I-bit stays masked).
   Set PMICCDD_PC_CAPTURE_METHOD = PMICCDD_PC_CAPTURE_DISABLED in PmicCdd_Cfg.h for UT. */
#define PMICCDD_PC_CAPTURE_IRQ_BANKED_LR  0U
#define PMICCDD_PC_CAPTURE_DISABLED       1U

#ifndef PMICCDD_PC_CAPTURE_METHOD
#  define PMICCDD_PC_CAPTURE_METHOD  (PMICCDD_PC_CAPTURE_IRQ_BANKED_LR)
#endif
#if (VC_TEST == STD_ON)
#  undef  PMICCDD_PC_CAPTURE_METHOD
#  define PMICCDD_PC_CAPTURE_METHOD  (PMICCDD_PC_CAPTURE_DISABLED)
#endif

#if (PMICCDD_PC_CAPTURE_METHOD == PMICCDD_PC_CAPTURE_IRQ_BANKED_LR)
/* PRQA S 1006 15 -- ARM inline assembly required for banked-register access; no C equivalent */
static inline uint32 PmicCdd_GetInterruptedPC_BankedLR(void)
{
    uint32 pc;
    uint32 cpsr_saved;
    __asm volatile (
        "mrs  %[cpsr], cpsr    \n"  /* save current mode (SYS) + interrupt mask */
        "cps  #0x12            \n"  /* switch to IRQ mode — I-bit unchanged, stays masked */
        "mov  %[pc], lr        \n"  /* LR_irq = interrupted PC (Phase 1 did sub lr,lr,#4) */
        "msr  cpsr_c, %[cpsr]  \n"  /* restore SYS mode */
        : [pc] "=r"(pc), [cpsr] "=r"(cpsr_saved)
        :
        : "memory"
    );
    return pc;
}
#endif /* PMICCDD_PC_CAPTURE_METHOD == PMICCDD_PC_CAPTURE_IRQ_BANKED_LR */
static uint32 PmicCdd_nINT_SavedPC = 0U;

// Flag that indicates that Mcu_performReset is required once we enter the long window
// Introduced to solve bootloader issue
uint8 PmicCdd_LongWin_PerformMcuReset = FALSE;

// Flag for Register lock status
uint8 PmicCdd_RegisterLock_Status = FALSE;

//making this variable as global to cover the UT. Ignore the KW Warning
static uint8 retryCount = 0U;

/* FSM state preserved across an I2C bus-error retry. File scope for the same
   reason as retryCount above - the UT asserts on them directly. Ignore the KW Warning */
static ePmicCdd_FSM_StateType saved_fsm_state = PmicCdd_InitRequested;
static uint8 fsm_state_saved = FALSE; /* TRUE while saved_fsm_state holds a valid pre-error state */

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

static void PmicCdd_GpioInit(void);

static void PmicCdd_Push_BistPass(void);
static void PmicCdd_Push_SeqAfterCrc(void);
static void PmicCdd_Push_PmicDeviceInfo(void);
static PmicCdd_ResetReasonType PmicCdd_DetermineResetReason(void);

static Std_ReturnType PmicCdd_I2cPushSequence(ePmicCdd_I2cSeqQIDType PushSeqNum);
static Std_ReturnType PmicCdd_I2cPopSequence(ePmicCdd_I2cSeqQIDType *PopSeqNum);
static void PmicCdd_I2cSequence_QueueClear(void);
static boolean PmicCdd_I2cQueueIsEmpty(void);
static void PmicCdd_I2cDispatchNextIfIdle(void);

static Std_ReturnType PmicCdd_I2CASyncTransmit(ePmicCdd_I2cSeqQIDType ePmicCdd_I2cSeqQID);
static Std_ReturnType PmicCdd_I2CSyncTransmit(ePmicCdd_I2cSeqQIDType PmicCddI2cSeqID);

/* I2C Sequence call back declaration */

static void PmicCdd_CBStartWdgGpt(void);

#if (PMICCDD_ENABLE_ADC == STD_ON)
static void PmicCdd_CBReadAdcResults(void);
static void PmicCdd_CBAdcConvStarted(void);
static void PmicCdd_CBReadAdcStatus(void);
static void PmicCdd_Adc_StartConversion(void);
#endif

/* Read Interrupt Status Internal Callback*/

static void PmicCdd_CBReadIntTop(void);
static void PmicCdd_CBReadIntBuck(void);
static void PmicCdd_CBReadIntLdoVmon(void);
static void PmicCdd_CBReadIntGpio(void);
static void PmicCdd_CBReadIntStartup(void);
static void PmicCdd_CBReadIntMisc(void);
static void PmicCdd_CBReadIntModerateError(void);
static void PmicCdd_CBReadIntSevereError(void);
static void PmicCdd_CBReadIntFsmError(void);
static void PmicCdd_CBReadIntEsm(void);
static void PmicCdd_CBReadWdErrStatus(void);
static void PmicCdd_ReadFailCnt(void);
static void PmicCdd_ReadWdModeStatus(void);

static void PmicCdd_Log_FailIntWrite(void);

#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
static void PmicCdd_BuckLdoVccaVmon_Init(void);
static void PmicCdd_InitBuckLdoVccaVmon_Push(void);
#endif

// Register lock and unlock APIs
static void PmicCdd_LockRegisters(void);
static void PmicCdd_UnlockRegisters(void);
static void PmicCdd_CBWriteRegisterLock(void);
static void PmicCdd_CBWriteRegisterUnlock(void);

// Clear Interrupt register based on the Bit set
static void PmicCdd_ClearBuckInt(uint8 Mask);
static void PmicCdd_ClearLdoVmonInt(uint8 Mask);
static void PmicCdd_ClearGpioInt(uint8 Mask);
static void PmicCdd_ClearStartupInt(uint8 Mask);
static void PmicCdd_ClearMiscInt(uint8 Mask);
static void PmicCdd_ClearModerateErrorInt(uint8 Mask);
static void PmicCdd_ClearSevereErrorInt(uint8 Mask);
static void PmicCdd_ClearFsmErrorInt(uint8 Mask);
static void PmicCdd_ClearEsmInt(uint8 Mask);
static void PmicCdd_ClearWdgErrStatusInt(uint8 Mask);

// NvM code check callback
static void PmicCdd_CBCheckNvmCodes(void);

/*Cmplib Function Declaration*/
static Std_ReturnType CmpInit(void);
static Std_ReturnType CmpDeInit(void);
static Std_ReturnType CmpActivation(void);
static Std_ReturnType CmpDeActivation(void);
static Std_ReturnType CmpActive(void);
static Std_ReturnType CmpDiagReturn(void);

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

static uint8 PmicCdd_PowerOnConfigReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio1_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio2_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio3_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio4_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio5_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Gpio6_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_WdErrStatusReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_WdErrStatusReg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];
#if (PMICCDD_ENABLE_WDG == STD_ON)
static uint8 PmicCdd_WdWin1CfgReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_WdWin2CfgReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Wdg_LongWin_Cfg_Tx_Buffer[0x02U + PMICCDD_CRC_LENGTH];
#endif
static uint8 PmicCdd_WdThrCfgReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_WdModeReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_WdModeReg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_WgThrCfgReg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_FailCnt_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_FailCnt_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

#if (PMICCDD_ENABLE_ESM == STD_ON)
/* ESM */
static uint8 PmicCdd_Esm_Delay1_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Delay2_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_ModeCfg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Hmax_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Hmin_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Lmax_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Lmin_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Esm_Start_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
#endif

/* ADC */
#if (PMICCDD_ENABLE_ADC == STD_ON)
static uint8 PmicCdd_Adc_CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Adc_CtrlReg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_Adc_ResultReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Adc_ResultReg1_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Adc_ResultReg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Adc_ResultReg1_RxBuf[0x01U + PMICCDD_CRC_LENGTH];
#endif

/* Interrupts */
static uint8 PmicCdd_IntTop_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntTop_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntBuck_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntBuck_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntLdoVmon_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntLdoVmon_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntGpio_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntGpio_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntStartup_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntStartup_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntMisc_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntMisc_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntModerateError_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntModerateError_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntSevereError_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntSevereError_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntFsmError_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntFsmError_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_IntEsm_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_IntEsm_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_Config2_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_ReadConfig2_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_ReadConfig2_Reg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_MaskStartup_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_MaskStartup_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

/* Reset Counter */
static uint8 PmicCdd_Read_RecovCntReg1_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Read_RecovCntReg1_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_Read_RecovCntReg2_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Read_RecovCntReg2_RxBuf[0x01U + PMICCDD_CRC_LENGTH];

static uint8 PmicCdd_Write_RecovCntReg2_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

/* Spread spectrum */
static uint8 PmicCdd_SpreadSpectrum_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
/* Buck Settings */
static uint8 PmicCdd_Buck1CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Buck2CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Buck3CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Buck4CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

/* Ldo settings */
static uint8 PmicCdd_Ldo1CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Ldo2CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_Ldo3CtrlReg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

/* Enabling OV/UV for VCCA and VMON1 */
static uint8 PmicCdd_Vcca_VmonCtrl_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
#endif

/* Register Lock and Unlock */
static uint8 PmicCdd_RegisterLock_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_RegisterUnlock_TxBuf[0x02U + PMICCDD_CRC_LENGTH];

/* Device Revision and NVM code */
static uint8 PmicCdd_DevRev_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_DevRev_Reg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_NvmCode1_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_NvmCode1_Reg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_NvmCode2_Reg_TxBuf[0x02U + PMICCDD_CRC_LENGTH];
static uint8 PmicCdd_NvmCode2_Reg_RxBuf[0x01U + PMICCDD_CRC_LENGTH];


#ifdef TEST_RW
static uint8 PmicCdd_TestReadReg_TxBuf[0x2U];
static uint8 PmicCdd_TestReadReg_RxBuf[0xFFU];
static uint8 PmicCdd_TestWdgReadReg_TxBuf[0x2U];
static uint8 PmicCdd_TestWdgReadReg_RxBuf[0x0CU];
#endif

static PmicCdd_I2c_SequenceType PmicCdd_I2c_Sequence[PMICCDD_MAX_I2C_SEQUENCE] =
    {
#ifdef TEST_RW
        {PmicCdd_TestRead, PmicCdd_TestReadReg_TxBuf, PmicCdd_TestReadReg_RxBuf, 0x01u, 0xC8u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_TestwdgRead, PmicCdd_TestWdgReadReg_TxBuf, PmicCdd_TestWdgReadReg_RxBuf, 0x01u, 0x02u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
#endif
        {PmicCdd_Config2, PmicCdd_Config2_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_ReadConfig2, PmicCdd_ReadConfig2_Reg_TxBuf, PmicCdd_ReadConfig2_Reg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_PowerOnConfig, PmicCdd_PowerOnConfigReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio1, PmicCdd_Gpio1_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio2, PmicCdd_Gpio2_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio3, PmicCdd_Gpio3_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio4, PmicCdd_Gpio4_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio5, PmicCdd_Gpio5_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Gpio6, PmicCdd_Gpio6_Reg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},

        /* WD_ERR_STATUS read/clear must stay available regardless of PMICCDD_ENABLE_WDG:
           reset-reason reporting and FSM-error wd_int handling depend on it even when
           this driver isn't actively configuring/running the watchdog. */
        {PmicCdd_read_WdErrStatus, PmicCdd_WdErrStatusReg_TxBuf, PmicCdd_WdErrStatusReg_RxBuf, 0x01u, 0x01u, PMIC_I2C_WDG_DEVICE_ID, &PmicCdd_CBReadWdErrStatus},
        {PmicCdd_write_WdErrStatus, PmicCdd_WdErrStatusReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
#if (PMICCDD_ENABLE_WDG == STD_ON)
        {PmicCdd_WdWin1Cfg, PmicCdd_WdWin1CfgReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
        {PmicCdd_WdWin2Cfg, PmicCdd_WdWin2CfgReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
        {PmicCdd_LongWindowCfg, PmicCdd_Wdg_LongWin_Cfg_Tx_Buffer, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
#endif
        {PmicCdd_WdThrCfgRead, PmicCdd_WdThrCfgReg_TxBuf, PmicCdd_WgThrCfgReg_RxBuf, 0x01u, 0x01u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
        {PmicCdd_WdThrCfg, PmicCdd_WdThrCfgReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
        {PmicCdd_WdMode, PmicCdd_WdModeReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_WDG_DEVICE_ID, &PmicCdd_CBStartWdgGpt},
        {PmicCdd_FailCnt, PmicCdd_FailCnt_TxBuf, PmicCdd_FailCnt_RxBuf, 0x01u, 0x01u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},
        {PmicCdd_ReadWdMode, PmicCdd_WdModeReg_TxBuf, PmicCdd_WdModeReg_RxBuf, 0x01u, 0x01u, PMIC_I2C_WDG_DEVICE_ID, NULL_PTR},

#if (PMICCDD_ENABLE_ESM == STD_ON)
        {PmicCdd_EsmDelay1Cfg, PmicCdd_Esm_Delay1_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmDelay2Cfg, PmicCdd_Esm_Delay2_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmModeCfg, PmicCdd_Esm_ModeCfg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmHmaxCfg, PmicCdd_Esm_Hmax_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmHminCfg, PmicCdd_Esm_Hmin_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmLmaxCfg, PmicCdd_Esm_Lmax_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmLminCfg, PmicCdd_Esm_Lmin_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_EsmStart, PmicCdd_Esm_Start_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
#endif
#if (PMICCDD_ENABLE_ADC == STD_ON)
        {PmicCdd_Write_AdcCtrl, PmicCdd_Adc_CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBAdcConvStarted},
        {PmicCdd_Read_AdcCtrl, PmicCdd_Adc_CtrlReg_TxBuf, PmicCdd_Adc_CtrlReg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadAdcStatus},
        {PmicCdd_Read_AdcResult, PmicCdd_Adc_ResultReg_TxBuf, PmicCdd_Adc_ResultReg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_AdcResult1, PmicCdd_Adc_ResultReg1_TxBuf, PmicCdd_Adc_ResultReg1_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadAdcResults},
#endif
        {PmicCdd_Read_IntTop, PmicCdd_IntTop_TxBuf, PmicCdd_IntTop_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntTop},
        {PmicCdd_Read_IntBuck, PmicCdd_IntBuck_TxBuf, PmicCdd_IntBuck_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntBuck},
        {PmicCdd_Write_IntBuck, PmicCdd_IntBuck_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntLdoVmon, PmicCdd_IntLdoVmon_TxBuf, PmicCdd_IntLdoVmon_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntLdoVmon},
        {PmicCdd_Write_IntLdoVmon, PmicCdd_IntLdoVmon_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntGpio, PmicCdd_IntGpio_TxBuf, PmicCdd_IntGpio_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntGpio},
        {PmicCdd_Write_IntGpio, PmicCdd_IntGpio_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntStartup, PmicCdd_IntStartup_TxBuf, PmicCdd_IntStartup_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntStartup},
        {PmicCdd_Write_IntStartup, PmicCdd_IntStartup_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntMisc, PmicCdd_IntMisc_TxBuf, PmicCdd_IntMisc_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntMisc},
        {PmicCdd_Write_IntMisc, PmicCdd_IntMisc_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntModerateError, PmicCdd_IntModerateError_TxBuf, PmicCdd_IntModerateError_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntModerateError},
        {PmicCdd_Write_IntModerateError, PmicCdd_IntModerateError_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntSevereError, PmicCdd_IntSevereError_TxBuf, PmicCdd_IntSevereError_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntSevereError},
        {PmicCdd_Write_IntSevereError, PmicCdd_IntSevereError_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntFsmError, PmicCdd_IntFsmError_TxBuf, PmicCdd_IntFsmError_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntFsmError},
        {PmicCdd_Write_IntFsmError, PmicCdd_IntFsmError_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_IntEsm, PmicCdd_IntEsm_TxBuf, PmicCdd_IntEsm_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, &PmicCdd_CBReadIntEsm},
        {PmicCdd_Write_IntEsm, PmicCdd_IntEsm_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_MaskStartup, PmicCdd_MaskStartup_TxBuf, PmicCdd_MaskStartup_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_MaskStartup, PmicCdd_MaskStartup_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_RecovCntReg1, PmicCdd_Read_RecovCntReg1_TxBuf, PmicCdd_Read_RecovCntReg1_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_RecovCntReg2, PmicCdd_Read_RecovCntReg2_TxBuf, PmicCdd_Read_RecovCntReg2_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_RecovCntReg2, PmicCdd_Write_RecovCntReg2_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_SpreadSpectrum, PmicCdd_SpreadSpectrum_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
        {PmicCdd_Write_Buck1Ctrl, PmicCdd_Buck1CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Buck2Ctrl, PmicCdd_Buck2CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Buck3Ctrl, PmicCdd_Buck3CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Buck4Ctrl, PmicCdd_Buck4CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Ldo1Ctrl, PmicCdd_Ldo1CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Ldo2Ctrl, PmicCdd_Ldo2CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_Ldo3Ctrl, PmicCdd_Ldo3CtrlReg_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Write_VccaVmonCtrl, PmicCdd_Vcca_VmonCtrl_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
#endif
        {PmicCdd_Write_RegisterLock, PmicCdd_RegisterLock_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, PmicCdd_CBWriteRegisterLock},
        {PmicCdd_Write_RegisterUnlock, PmicCdd_RegisterUnlock_TxBuf, NULL_PTR, 0x02u, 0x00u, PMIC_I2C_USER_DEVICE_ID, PmicCdd_CBWriteRegisterUnlock},
        {PmicCdd_Read_DevRev, PmicCdd_DevRev_Reg_TxBuf, PmicCdd_DevRev_Reg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_NvmCode1, PmicCdd_NvmCode1_Reg_TxBuf, PmicCdd_NvmCode1_Reg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, NULL_PTR},
        {PmicCdd_Read_NvmCode2, PmicCdd_NvmCode2_Reg_TxBuf, PmicCdd_NvmCode2_Reg_RxBuf, 0x01u, 0x01u, PMIC_I2C_USER_DEVICE_ID, PmicCdd_CBCheckNvmCodes},
};

/* WDG Registers*/
static PmicCdd_WdModeReg_t PmicCdd_WdModeReg = {0x00u};
static PmicCdd_WdErrStatusReg_t PmicCdd_WdErrStatusReg = {0x00u};
static PmicCdd_WdErrStatusReg_t PmicCdd_WdErrStatusReg_InitRead = {0x00u};

#if (PMICCDD_ENABLE_ADC == STD_ON)
static PmicCdd_AdCtrl_Reg_t PmicCdd_AdCtrl_Reg = {0x00u};
#endif

/* Interrupt Registers */
static PmicCdd_IntBuck_Reg_t PmicCdd_IntBuck_Reg = {0x00u};
static PmicCdd_IntLdoVmon_Reg_t PmicCdd_IntLdoVmon_Reg = {0x00u};
static PmicCdd_IntGpio_Reg_t PmicCdd_IntGpio_Reg = {0x00u};
static PmicCdd_IntStartup_Reg_t PmicCdd_IntStartup_Reg = {0x00u};
static PmicCdd_IntMisc_Reg_t PmicCdd_IntMisc_Reg = {0x00u};
static PmicCdd_IntModerate_Reg_t PmicCdd_IntModerate_Reg = {0x00u};
static PmicCdd_IntSevereErr_Reg_t PmicCdd_IntSevereErr_Reg = {0x00u};
static PmicCdd_IntFsmErr_Reg_t PmicCdd_IntFsmErr_Reg = {0x00u};
static PmicCdd_IntEsm_Reg_t PmicCdd_IntEsm_Reg = {0x00u};
static PmicCdd_IntSevereErr_Reg_t PmicCdd_IntSevereErr_StartupStatus_Reg = {0x00u};
static PmicCdd_IntModerate_Reg_t PmicCdd_IntModerate_StartupStatus_Reg = {0x00u};
static PmicCdd_IntMisc_Reg_t PmicCdd_IntMisc_StartupStatus_Reg = {0x00u};

#if (PMICCDD_ENABLE_ESM == STD_ON)
/* ESM Registers */
static PmicCdd_EsmMcuStart_Reg_t PmicCdd_EsmMcuStart_Reg = {0x00u};
static PmicCdd_EsmMcuModeCfg_Reg_t PmicCdd_EsmMcuModeCfg_Reg = {0x00u};
static PmicCdd_EsmMcuErrCnt_Reg_t PmicCdd_EsmMcuErrCnt_Reg = {0x00u};
#endif

/* Reset Count Register */
static PmicCdd_Recov_Cnt_Reg2_t PmicCdd_Recov_Cnt_Reg2 = {0x00u};

/* Spread Spectrum Register */
#if (PMICCDD_SS_EN == STD_ON)
static PmicCdd_Spread_Spectrum1_Reg_t PmicCdd_Spread_Spectrum1_Reg = {0x00u};
#endif

/* Register lock and unlock Register */
static PmicCdd_Register_Lock_Reg_t PmicCdd_Register_Lock_Reg = {0x00u};

/* ADC */
#if (PMICCDD_ENABLE_ADC == STD_ON)
static uint16 PmicCdd_Adc_ResultBuffer = 0U;
static uint8 PmicCdd_Adc_Result_Status = E_NOT_OK;
static uint8 PmicCdd_Adc_GroupNotification = 0x0U;
static uint8 PmicCdd_AdcStartConv_Pending = 0U;
static uint8 PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_STOP;
static PmicCdd_Adc_FSM_State_Type PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_NoInit;
#endif

/* FIFO Queue*/
static uint8 PmicCdd_QueueHead = 0U;
static uint8 PmicCdd_QueueTail = 0U;
static uint8 PmicCdd_QueueFull = 0U;
static uint8 PmicCdd_I2c_SequenceQueue[PMICCDD_MAX_I2C_SEQUENCE_QUEUE];
static uint8 PmicCdd_I2c_CurrentSequenceIndex = 0U;

#if (PMICCDD_ENABLE_WDG == STD_ON)
/* Wdg */
static volatile uint32 PmicWdgTimeout = 0U;
static uint32 Pmic_GptTimerTickValue = 0u;
static volatile uint8 Pmic_ResumeKickRequested = 0u; /* 1 => do a one-time immediate rising in ISR */

static volatile uint8 Pmic_Feeding = 0u; /* WdgM-authorized feeding */
static volatile PmicWdg_IsrStateType Pmic_IsrState = PMIC_WDG_IDLE;
static volatile uint8 Pmic_PinHigh = 0u;

/* Tick intervals (derived from clock and your Δt = Pmic_GptTimerTickValue) */
static uint32 Pmic_TicksPw = 0u;  /* pulse width ticks      */
static uint32 Pmic_TicksGap = 0u; /* (Δt - PW) ticks        */

/* Accounting for timeout & time progression */
static uint32 Pmic_LastIntervalTicks = 0u;    /* just-elapsed interval debited in ISR */
static uint64 Pmic_CumTicks = 0u;             /* cumulative elapsed ticks (for logging) */
static uint64 Pmic_LastRiseTick = 0u;         /* timestamp of last rising (logging) */
static volatile uint8 Pmic_TimerRunning = 0u; /* 0: GPT stopped, 1: GPT running */
/* New: GTC-based phase tracking (32-bit, atomic) */
static volatile uint8 Pmic_GtcValid = 0u;       /* we have a last-rise timestamp */
static volatile uint32 Pmic_LastRiseGtc32 = 0u; /* 32-bit low counter at last rising */
static volatile uint8 Pmic_PhaseAlignReq = 0u;  /* ISR shall do one phase-aligned rising */
static volatile uint8 Pmic_WdgPathInitialized = FALSE; /* WdMode write and GPT/DIO setup completed */
static volatile uint8 Pmic_WdgResetCapable = FALSE; /* confirmed enabled short-window reset path */

/* Inline helpers to keep the running-flag in sync */
static inline void Pmic_GptStart(uint32 ticks)
{
  if (PmicCdd_WdgReset_Request == FALSE)
  {
    Gpt_StartTimer(GptConf_GptChannelConfiguration_Gpt_ExtWdg_Win, ticks);
    Pmic_TimerRunning = 1u;
  }
}

static inline void Pmic_GptStop(void)
{
  Gpt_StopTimer(GptConf_GptChannelConfiguration_Gpt_ExtWdg_Win);
  Pmic_TimerRunning = 0u;
}

/* Single, synchronous "stop feeding" transition. MUST be called under the critical section.
 * After this returns the driver is in one unambiguous idle state: pin LOW, feeding off, budget
 * zero, GPT stopped (Pmic_TimerRunning == 0 immediately - no coast tick), state IDLE, and any
 * pending resume/align request cleared. The GTC phase reference (Pmic_LastRiseGtc32/GtcValid) is
 * deliberately preserved so a later PmicCdd_WdgSetTriggerCondition() can resume phase-aligned.
 * This replaces three divergent stop paths (budget-exhausted, WdgM stop, ISR neutral pause) that
 * previously used two different end states and a one-tick GPT re-arm. */
static inline void Pmic_WdgStopFeeding_Locked(void)
{
  if (Pmic_PinHigh != 0u)
  {
    Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);
    Pmic_PinHigh = 0u;
  }
  Pmic_Feeding             = 0u;
  PmicWdgTimeout           = 0u;
  Pmic_IsrState            = PMIC_WDG_IDLE;
  Pmic_LastIntervalTicks   = 0u;
  Pmic_PhaseAlignReq       = 0u;
  Pmic_ResumeKickRequested = 0u;
  Pmic_GptStop(); /* stops now; no re-arm, so Pmic_TimerRunning reflects reality this instant */
}

static uint32 Pmic_ComputeDelayToWin2_ms(uint32 now32);
#endif
static inline uint32 Pmic_ReadGtc32(void)
{
	#if(VC_TEST == STD_OFF)
	/* 32-bit low read is atomic; no need to mask IRQs */
	return *(volatile uint32 *)PMICCDD_GTC_LOW_REG;
	#endif
}

/* PMIC Report Error Status*/
static uint64 PmicCdd_ReportErrorStatus = 0U;

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   CmpInit
**
** Visibility       :   Static
**
** Description      :   PmicCdd Module Component Initialize routine
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
  PmicCdd_Init();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDeInit
**
** Visibility       :   Static
**
** Description      :   PmicCdd Module Component De-Initialize routine
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
** Description      :   PmicCdd Module Component Activation routine
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
** Description      :   PmicCdd Module Component De-Activation routine
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
** Description      :   PmicCdd Module Component Active routine
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
  PmicCdd_MainFunction();
  return E_OK;
}

/*============================================================================
**
** Function Name    :   CmpDiag
**
** Visibility       :   Static
**
** Description      :   PmicCdd Module Component Diagnostic routine
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
** Function Name    :   PmicCdd_Init
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
void PmicCdd_Init(void)
{
  /* Startup Mask Registers */
  static PmicCdd_MaskStartup_Reg_t PmicCdd_MaskStartup_Reg = {0x00u};
  /*CRC Registers */
  static PmicCdd_Config2_Reg_t PmicCdd_Config2_Reg = {0x00u};
  /* Wdg Register */
  static PmicCdd_WdThrCfgReg_t PmicCdd_WdThrCfgReg = {0x00u};
#if (PMICCDD_ENABLE_WDG == STD_ON)
  static PmicCdd_WdWin1CfgReg_t PmicCdd_WdWin1CfgReg = {0x00u};
  static PmicCdd_WdWin2CfgReg_t PmicCdd_WdWin2CfgReg = {0x00u};
  static PmicCdd_WdLongWinCfgReg_t PmicCdd_WdLongWinCfgReg = {0x00u};
#endif
  /* I2c Regs */
  static PmicCdd_PowerOnConfigReg_t PmicCdd_PowerOnConfigReg = {0x00u};

  /* FIFO Queue*/
  PmicCdd_I2c_CurrentSequenceIndex = 0U;
  PmicCdd_QueueHead = 0U;
  PmicCdd_QueueTail = 0U;
  PmicCdd_QueueFull = 0U;

/* ADC */
#if (PMICCDD_ENABLE_ADC == STD_ON)
  PmicCdd_Adc_ResultBuffer = 0U;
  PmicCdd_Adc_Result_Status = E_NOT_OK;
  PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Idle;

  if (PmicCdd_Adc_GroupNotification != 0xFFU)
  {
    PmicCdd_Adc_GroupNotification = 0U;
  }
  PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_STOP;
#endif

  ePmicCdd_I2cSeqQIDType flPmicCdd_I2cSeqQID = PmicCdd_None;

  PmicCdd_EnterCriticalSection();
  PmicCdd_Latched_Reset_Reason = PmicCdd_Reset_Reason_Not_Ready;
  PmicCdd_Detailed_Reset_Reason = PmicCdd_Reset_Reason_None;
  ePmicCdd_FSM_State = PmicCdd_InitRequested;
  PmicCdd_ExitCriticalSection();

  PmicCdd_I2cSequence_QueueClear();

#if (PMICCDD_ENABLE_WDG == STD_ON)

  uint16 win1 = (uint16)PmicCdd_WdgConf.ePmicCdd_Win1_Time;
  uint16 win2 = (uint16)PmicCdd_WdgConf.ePmicCdd_Win2_Time;
  uint16 PmicCdd_GptReloadTime_mS = 0U;

  Pmic_WdgPathInitialized = FALSE;
  Pmic_WdgResetCapable = FALSE;
  PmicCdd_GptReloadTime_mS = PMIC_CALC_GPT_RELOAD_MS(win1, win2);

  PmicWdgTimeout = (uint32)(((uint64)PmicCdd_WdgConf.GptInitialTimeOut_mS *
                             (uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz) /
                            1000u);

  Pmic_GptTimerTickValue = (uint32)(((uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz *
                                     (uint64)PmicCdd_GptReloadTime_mS) /
                                    1000u);

  /* PW ticks = clkHz * (ms / 1000) */
  Pmic_TicksPw = (uint32)(((uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz *
                           (uint64)PMIC_PULSE_MS) /
                          1000u);

  if (Pmic_TicksPw == 0u)
  {
    Pmic_TicksPw = 1u; /* ensure >= 1 tick */
  }

  if (Pmic_TicksPw >= Pmic_GptTimerTickValue)
  {
    /* Invalid timing config (pulse >= cadence). Reporting DET is not enough: the GAP
       subtraction below would underflow to a huge unsigned interval and the ISR would
       then arm the GPT with it, effectively disabling the watchdog feed. Force a safe
       inert state instead and leave feeding off. */
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_WDG_WINDOW_CFG_FAILS);
    Pmic_TicksPw = 0u;
    Pmic_TicksGap = 0u;
    Pmic_Feeding = 0u;
  }
  else
  {
    /* GAP = Δt - PW (PW < Δt is guaranteed here) */
    Pmic_TicksGap = Pmic_GptTimerTickValue - Pmic_TicksPw;

    #if(VC_TEST == STD_OFF) /*In UT env, this will be always true based onPmic_TicksGap = Pmic_GptTimerTickValue - Pmic_TicksPw;
    Instead of removing the check, adding in compilation condition*/
    if ((Pmic_TicksPw + Pmic_TicksGap) != Pmic_GptTimerTickValue)
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_WDG_WINDOW_CFG_FAILS);
    }
    #endif
  }

  Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);
  Pmic_PinHigh = 0u;
  Pmic_IsrState = PMIC_WDG_IDLE;
  Pmic_Feeding = 0u;
  Pmic_LastIntervalTicks = 0u;
  Pmic_CumTicks = 0u;
  Pmic_LastRiseTick = 0u;
  /* Make sure GPT notification is enabled (ISR will own the cadence). */
  Pmic_GptStop();

#endif

#ifdef TEST_RW
  PmicCdd_TestReadReg_TxBuf[0] = 0x00;
  PmicCdd_TestReadReg_TxBuf[1] = 0;

  PmicCdd_TestWdgReadReg_TxBuf[0] = 0x01;
  PmicCdd_TestWdgReadReg_TxBuf[1] = 0;
#endif

  /* Crc Enabling*/
#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
  PmicCdd_Config2_Reg.bits.i2c1_spi_crc_en = 1U;
  PmicCdd_Config2_Reg.bits.i2c2_crc_en = 0U;
  PmicCdd_Config2_Reg_TxBuf[0] = CONFIG_2_REG;
  PmicCdd_Config2_Reg_TxBuf[1] = PmicCdd_Config2_Reg.value;
#else
  PmicCdd_Config2_Reg.bits.i2c1_spi_crc_en = 0;
  PmicCdd_Config2_Reg.bits.i2c2_crc_en = 0;
  PmicCdd_Config2_Reg_TxBuf[0] = CONFIG_2_REG;
  PmicCdd_Config2_Reg_TxBuf[1] = PmicCdd_Config2_Reg.value;
#endif

  PmicCdd_ReadConfig2_Reg_TxBuf[0] = CONFIG_2_REG;

  /* Power On Configuration */
  PmicCdd_PowerOnConfigReg.bits.en_pb_degl = 0U;
  PmicCdd_PowerOnConfigReg.bits.en_pb_vsense_config = PmicCdd_OneTimeConf.EnPBVsenseConf;
  PmicCdd_PowerOnConfigReg.bits.nint_endrv_pu_sel = PMICCDD_DISABLE_NINT_ENDRV_PU_SEL;
  PmicCdd_PowerOnConfigReg.bits.nint_endrv_sel = 0U;
  PmicCdd_PowerOnConfigReg_TxBuf[0] = POWER_ON_CONFIG_REG;
  PmicCdd_PowerOnConfigReg_TxBuf[1] = PmicCdd_PowerOnConfigReg.value;

  /* GPIO Init */
  PmicCdd_GpioInit();

/* Buck Ldo Vcca Vmon Init */
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
  PmicCdd_BuckLdoVccaVmon_Init();
#endif

  /*Wdg Error Status Clear - register pointer/initial mask must be set regardless of
     PMICCDD_ENABLE_WDG, since read/write_WdErrStatus are always pushed (see below). */
  PmicCdd_WdErrStatusReg_TxBuf[0] = WD_ERR_STATUS_REG;
  PmicCdd_WdErrStatusReg.value = 0xFFU;
  PmicCdd_WdErrStatusReg_TxBuf[1] = PmicCdd_WdErrStatusReg.value;

#if (PMICCDD_ENABLE_WDG == STD_ON)
  /*wdg Long Window Configuration  */

  PmicCdd_Wdg_LongWin_Cfg_Tx_Buffer[0] = WD_LONGWIN_CFG_REG;
  PmicCdd_WdLongWinCfgReg.bits.wd_longwin = (0x7Fu & PmicCdd_WdgConf.ePmicCdd_LongWindow_Time);
  PmicCdd_Wdg_LongWin_Cfg_Tx_Buffer[1] = PmicCdd_WdLongWinCfgReg.value;

  /* Window 1 Configuration */
  PmicCdd_WdWin1CfgReg_TxBuf[0] = WD_WIN1_CFG_REG;
  PmicCdd_WdWin1CfgReg.bits.wd_win1 = (0x7Fu & PmicCdd_WdgConf.ePmicCdd_Win1_Time);
  PmicCdd_WdWin1CfgReg_TxBuf[1] = PmicCdd_WdWin1CfgReg.value;

  /* Window 2 Configuration */
  PmicCdd_WdWin2CfgReg_TxBuf[0] = WD_WIN2_CFG_REG;
  PmicCdd_WdWin2CfgReg.bits.wd_win2 = (0x7Fu & PmicCdd_WdgConf.ePmicCdd_Win2_Time);
  PmicCdd_WdWin2CfgReg_TxBuf[1] = PmicCdd_WdWin2CfgReg.value;

  /* Window Threshold Configuration */
  PmicCdd_WdThrCfgReg_TxBuf[0] = WD_THR_CFG_REG;
  PmicCdd_WdThrCfgReg.bits.wd_en = 1u;
  PmicCdd_WdThrCfgReg.bits.wd_fail_th = (0x7u & PmicCdd_WdgConf.WdgFailedThreshold);
  PmicCdd_WdThrCfgReg.bits.wd_rst_en = 1u;
  PmicCdd_WdThrCfgReg.bits.wd_rst_th = (0x7u & PmicCdd_WdgConf.WdgResetThreshold);
  PmicCdd_WdThrCfgReg_TxBuf[1] = PmicCdd_WdThrCfgReg.value;

  /*wdg Mode Configuration */
  PmicCdd_WdModeReg_TxBuf[0] = WD_MODE_REG;
  PmicCdd_WdModeReg.bits.reserved2 = 0u;
  PmicCdd_WdModeReg.bits.wd_cnt_sel = 0u;
  PmicCdd_WdModeReg.bits.wd_endrv_sel = 1u;
  PmicCdd_WdModeReg.bits.wd_mode_select = 0u;
  PmicCdd_WdModeReg.bits.wd_pwrhold = 0u;
  PmicCdd_WdModeReg.bits.wd_return_longwin = 0u;
  PmicCdd_WdModeReg_TxBuf[1] = PmicCdd_WdModeReg.value;
#else
  /* Disable Wdg */
  /* Window Threshold Configuration */
  PmicCdd_WdThrCfgReg_TxBuf[0] = WD_THR_CFG_REG;
  PmicCdd_WdThrCfgReg.bits.wd_en = 0u;
  PmicCdd_WdThrCfgReg.bits.wd_fail_th = (0x7u & PmicCdd_WdgConf.WdgFailedThreshold);
  /* Disable WDG */
  PmicCdd_WdThrCfgReg.bits.wd_rst_en = 0u;
  PmicCdd_WdThrCfgReg.bits.wd_rst_th = (0x7u & PmicCdd_WdgConf.WdgResetThreshold);
  PmicCdd_WdThrCfgReg_TxBuf[1] = PmicCdd_WdThrCfgReg.value;

  /*wdg Mode Configuration */
  PmicCdd_WdModeReg_TxBuf[0] = WD_MODE_REG;
  PmicCdd_WdModeReg.bits.reserved2 = 0u;
  PmicCdd_WdModeReg.bits.wd_cnt_sel = 0u;
  PmicCdd_WdModeReg.bits.wd_endrv_sel = 1u;
  PmicCdd_WdModeReg.bits.wd_mode_select = 0u;
  PmicCdd_WdModeReg.bits.wd_pwrhold = 1u;
  PmicCdd_WdModeReg.bits.wd_return_longwin = 0u;
  PmicCdd_WdModeReg_TxBuf[1] = PmicCdd_WdModeReg.value;

#endif

  /* ADC 12-bit configuration */
#if (PMICCDD_ENABLE_ADC == STD_ON)
  PmicCdd_Adc_CtrlReg_TxBuf[0] = ADC_CTRL_REG;
  PmicCdd_AdCtrl_Reg.bits.adc_rdiv_en = (uint8)PmicCdd_AdcConf.PmicCdd_AdcDivider;
  PmicCdd_AdCtrl_Reg.bits.adc_thermal_sel = 0u;
  PmicCdd_AdCtrl_Reg.bits.adc_cont_conv = 0u;
  PmicCdd_AdCtrl_Reg.bits.adc_start = 1u;
  PmicCdd_AdCtrl_Reg.bits.adc_status = 1u;
  PmicCdd_Adc_CtrlReg_TxBuf[1] = PmicCdd_AdCtrl_Reg.value;
  PmicCdd_Adc_ResultReg_TxBuf[0] = ADC_RESULT_REG_1;
  PmicCdd_Adc_ResultReg1_TxBuf[0] = ADC_RESULT_REG_2;
#endif

  /* Read Int Registers */
  PmicCdd_IntTop_TxBuf[0] = INT_TOP_REG;
  PmicCdd_IntBuck_TxBuf[0] = INT_BUCK_REG;
  PmicCdd_IntBuck_TxBuf[1] = 0xFFU;
  PmicCdd_IntLdoVmon_TxBuf[0] = INT_LDO_VMON_REG;
  PmicCdd_IntLdoVmon_TxBuf[1] = 0xFFU;
  PmicCdd_IntGpio_TxBuf[0] = INT_GPIO_REG;
  PmicCdd_IntGpio_TxBuf[1] = 0xFFU;
  PmicCdd_IntStartup_TxBuf[0] = INT_STARTUP_REG;
  PmicCdd_IntStartup_TxBuf[1] = 0xFFU;
  PmicCdd_IntMisc_TxBuf[0] = INT_MISC_REG;
  PmicCdd_IntMisc_TxBuf[1] = 0xFFU;
  PmicCdd_IntModerateError_TxBuf[0] = INT_MODERATE_ERR_REG;
  PmicCdd_IntModerateError_TxBuf[1] = 0xFFU;
  PmicCdd_IntSevereError_TxBuf[0] = INT_SEVERE_ERR_REG;
  PmicCdd_IntSevereError_TxBuf[1] = 0xFFU;
  PmicCdd_IntFsmError_TxBuf[0] = INT_FSM_ERR_REG;
  PmicCdd_IntFsmError_TxBuf[1] = 0xFFU;
  PmicCdd_IntEsm_TxBuf[0] = INT_ESM_REG;
  PmicCdd_IntEsm_TxBuf[1] = 0xFFU;

#if (PMICCDD_ENABLE_ESM == STD_ON)
  /* Esm Configuration */
  PmicCdd_Esm_Delay1_TxBuf[0] = ESM_MCU_DELAY1_REG;
  PmicCdd_Esm_Delay1_TxBuf[1] = PmicCdd_EsmConf.Delay1_Time; // ESM_MCU_DELAY1_REG

  PmicCdd_Esm_Delay2_TxBuf[0] = ESM_MCU_DELAY2_REG;
  PmicCdd_Esm_Delay2_TxBuf[1] = PmicCdd_EsmConf.Delay2_Time; // ESM_MCU_DELAY2_REG

  PmicCdd_EsmMcuModeCfg_Reg.bits.esm_mcu_en = 1u;
  PmicCdd_EsmMcuModeCfg_Reg.bits.esm_mcu_endrv = 1u;
  PmicCdd_EsmMcuModeCfg_Reg.bits.esm_mcu_err_cnt_th = PmicCdd_EsmConf.EsmMcuErrCntThreshold;
  PmicCdd_EsmMcuModeCfg_Reg.bits.esm_mcu_mode = PmicCdd_EsmConf.EsmMode;

  PmicCdd_Esm_ModeCfg_TxBuf[0] = ESM_MCU_MODE_CFG;
  PmicCdd_Esm_ModeCfg_TxBuf[1] = PmicCdd_EsmMcuModeCfg_Reg.value; // ESM_MCU_MODE_CFG

  PmicCdd_Esm_Hmax_TxBuf[0] = ESM_MCU_HMAX_REG;
  PmicCdd_Esm_Hmax_TxBuf[1] = PmicCdd_EsmConf.HMAX_Count; // ESM_MCU_HMAX_REG

  PmicCdd_Esm_Hmin_TxBuf[0] = ESM_MCU_HMIN_REG;
  PmicCdd_Esm_Hmin_TxBuf[1] = PmicCdd_EsmConf.HMIN_Count; // ESM_MCU_HMIN_REG

  PmicCdd_Esm_Lmax_TxBuf[0] = ESM_MCU_LMAX_REG;
  PmicCdd_Esm_Lmax_TxBuf[1] = PmicCdd_EsmConf.LMAX_Count; // ESM_MCU_LMAX_REG

  PmicCdd_Esm_Lmin_TxBuf[0] = ESM_MCU_LMIN_REG;
  PmicCdd_Esm_Lmin_TxBuf[1] = PmicCdd_EsmConf.LMIN_Count; // ESM_MCU_LMIN_REG

  PmicCdd_Esm_Start_TxBuf[0] = ESM_MCU_START_REG;
  PmicCdd_EsmMcuStart_Reg.bits.esm_mcu_start = 1u;
  PmicCdd_Esm_Start_TxBuf[1] = PmicCdd_EsmMcuStart_Reg.value; // ESM_MCU_START_REG
#endif

  PmicCdd_MaskStartup_TxBuf[0] = MASK_STARTUP_REG;
  PmicCdd_MaskStartup_Reg.bits.enable_mask = 0u;
  PmicCdd_MaskStartup_Reg.bits.soft_reboot_mask = 1u;
  PmicCdd_MaskStartup_Reg.bits.vsense_mask = 0u;
  PmicCdd_MaskStartup_Reg.bits.pb_short_mask = 0u;
  PmicCdd_MaskStartup_Reg.bits.fsd_mask = 1u; /* Mask FSD to avoid false trigger during power on - NVM configured*/
  PmicCdd_MaskStartup_TxBuf[1] = PmicCdd_MaskStartup_Reg.value;

  /* Reset Counter */
  PmicCdd_Read_RecovCntReg1_TxBuf[0] = RECOV_CNT_REG_1;

  PmicCdd_Read_RecovCntReg2_TxBuf[0] = RECOV_CNT_REG_2;

  PmicCdd_Write_RecovCntReg2_TxBuf[0] = RECOV_CNT_REG_2;
  PmicCdd_Recov_Cnt_Reg2.bits.recov_cnt_thr = PMICCDD_RESET_THRESOLD;
  PmicCdd_Recov_Cnt_Reg2.bits.recov_cnt_clr = 0u;
  PmicCdd_Write_RecovCntReg2_TxBuf[1] = PmicCdd_Recov_Cnt_Reg2.value;

  /* Spread Spectrum */
#if (PMICCDD_SS_EN == STD_ON)
  PmicCdd_SpreadSpectrum_TxBuf[0] = SPREAD_SPECTRUM_1_REG;
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_en = (uint8)PmicCdd_SpreadSpectrumConfig.PmicCdd_SpreadSpectrum;
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_depth = (uint8)PmicCdd_SpreadSpectrumConfig.PmicCdd_SpreadSpectrum_ModulationDep;
  PmicCdd_SpreadSpectrum_TxBuf[1] = PmicCdd_Spread_Spectrum1_Reg.value;
#endif

#ifdef TEST_RW
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_TestRead))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Config2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  
  // Unlock the registers
  PmicCdd_UnlockRegisters();
  
  /* Read Trigger Interrupt Top  */
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntTop))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  /* Pop the sequence number first before tranmitting sequnece number to I2C Asyn Tranmsit always*/
  if (E_OK == PmicCdd_I2cPopSequence(&flPmicCdd_I2cSeqQID))
  {
    ePmicCdd_FSM_State = PmicCdd_InitProgress;
    if (E_OK != PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
    }
  }
  else
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  PmicCdd_Push_BistPass();
}
/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   PmicCdd_I2CASyncTransmit
**
** Visibility       :   Static
**
** Description      :   This function triggers the asynchronous transmission for the I2C sequenc.
**
** Invocation       :   Locally to start the new sequnce
**
** Inputs           :   ePmicCdd_I2cSeqQIDType ePmicCdd_I2cSeqQID - I2C transmission Sequnce ID
**
** Outputs          :   E_OK - The Sequence is pushed successfully
**                      E_NOT_OK - The Sequence is not pushed successfully
**
** Critical Section :   Yes
**
**==========================================================================*/
static Std_ReturnType PmicCdd_I2CASyncTransmit(ePmicCdd_I2cSeqQIDType ePmicCdd_I2cSeqQID)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint8 flIndex = 0;
  uint8 flCrcValue = 0;
  uint8 TxBuffer[PMICCDD_TXBUF_LENGTH];
  uint8 flRxCrcLength = 0;

  for (flIndex = 0; flIndex < PMICCDD_MAX_I2C_SEQUENCE; flIndex++)
  {
    if (ePmicCdd_I2cSeqQID == PmicCdd_I2c_Sequence[flIndex].eI2cSeqQID)
    {
      break;
    }
  }

  PmicCdd_I2c_CurrentSequenceIndex = flIndex;

  if (flIndex != PMICCDD_MAX_I2C_SEQUENCE)
  {
// Transmit CRC - if enabled
#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
    if ((PmicCdd_I2c_Sequence[flIndex].RxLength == 0x00u) && (PmicCdd_CrcEnabled == TRUE))
    {
      TxBuffer[flRxCrcLength] = (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].DeviceAddress << 1U);
      flRxCrcLength++;
      TxBuffer[flRxCrcLength] = (uint8)PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].TxBuffer[0U];
      flRxCrcLength++;
      TxBuffer[flRxCrcLength] = PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].TxBuffer[1U];
      flRxCrcLength++;

      flCrcValue = PmicCdd_CalculateCRC8Val(TxBuffer, flRxCrcLength);

      PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].TxBuffer[2U] = flCrcValue;
      PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].TxLength = flRxCrcLength;
    }
    else if ((PmicCdd_I2c_Sequence[flIndex].RxLength != 0x00u) && (PmicCdd_CrcEnabled == TRUE))
    {
      PmicCdd_I2c_Sequence[flIndex].RxLength = 2u;
    }
    else
    {
      // Do Nothing
    }
#endif

    RetVal = I2c_SetupEB(PmicCdd_GeneralConf.I2cChannelId, PmicCdd_I2c_Sequence[flIndex].TxBuffer,
                         PmicCdd_I2c_Sequence[flIndex].RxBuffer, PmicCdd_I2c_Sequence[flIndex].TxLength,
                         PmicCdd_I2c_Sequence[flIndex].RxLength, PmicCdd_I2c_Sequence[flIndex].DeviceAddress);

    if (E_OK == RetVal)
    {
      RetVal = I2c_AsyncTransmit(PmicCdd_GeneralConf.I2cChannelId);

      if (RetVal == E_NOT_OK)
      {
        PmicCdd_Det_ReportError(PMICCDD_MAIN_FUNCTION, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
      }
      // Same Sequence ID for all the Data transfer
    }
  }

  return RetVal;
}

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   PmicCdd_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending transmissions
**                      according to the priority.
**
** Invocation       :   Os Scheduleing.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

void PmicCdd_MainFunction(void)
{
  static PmicCdd_WdFailCntReg_t PmicCdd_WdFailCntReg = {0x00u};
  Dio_ChannelType flLevel = STD_LOW;
#ifdef TEST_SW_HANG
  static volatile uint32 testcount = 0;
  static volatile uint32 TestGtcCurrent = 0;
  static volatile uint32 nowGtc = 0;
  static volatile uint32 TestGtc = 0;
  static volatile uint8 WdgFailCntOld = 0;
  uint32 startGtc, delayTicks;

  /* Choose random delay in [50 ms, 480 ms] */
  const uint32 minDelayMs = 340U;
  const uint32 rangeMs = 50U;
  uint32 flElapsedTime = Pmic_ReadGtc32();
  uint32 delayMs = minDelayMs + ((flElapsedTime * 1103515245U + 12345U) % rangeMs);
  delayTicks = delayMs * 200000U; /* convert ms→ticks @ 200 MHz */

  //Dio_FlipChannel(Main_GPIO0_Channel_36); /* Toggle for measurement */

  testcount++;
  if (testcount >= 500U)
  {
    testcount = 0U;
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
    DltExt_Uart_Printf("SW Going hang for %lu ms\r\n", delayMs);
#endif
#endif

    /* Hang until GTC shows that delay has really elapsed */
    startGtc = Pmic_ReadGtc32();
    do
    {
      Dio_FlipChannel(Main_GPIO1_Channel_6);
      nowGtc = Pmic_ReadGtc32();
    } while ((uint32)(nowGtc - startGtc) < delayTicks);
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
    DltExt_Uart_Printf("Last Wdg Trigger Time  %lu ms\r\n", (nowGtc - Pmic_LastRiseGtc32) / 200000U);
#endif
#endif
  }
  else
  {
    PmicCdd_ReadFailCnt();
    if (PmicCdd_Read_FailCnt == TRUE)
    {
      PmicCdd_Read_FailCnt = FALSE;
      PmicCdd_WdFailCntReg.value = PmicCdd_FailCnt_RxBuf[0];
      if (WdgFailCntOld != PmicCdd_WdFailCntReg.bits.wd_fail_cnt)
      {
        TestGtcCurrent = Pmic_ReadGtc32();
        if (nowGtc != 0)
        {
          if (TestGtcCurrent > nowGtc)
          {
            TestGtc = TestGtcCurrent - nowGtc;
          }
          else
          {
            TestGtc = 0;
          }
        }
        TestGtc /= 200000;
        WdgFailCntOld = PmicCdd_WdFailCntReg.bits.wd_fail_cnt;
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
        DltExt_Uart_Printf("WDG FAIL CNT %lu Delta Time %lu mS\r\n", PmicCdd_WdFailCntReg.bits.wd_fail_cnt, TestGtc);
#endif
#endif
      }
    }
  }
#endif

  PmicCddWdgEarlyWarning SWHangDumpClear;
  // Handling the SW hang case
  if (PmicCdd_DumpLog_Status == TRUE)
  {
    PmicCdd_ReadFailCnt();
    if (PmicCdd_Read_FailCnt == TRUE)
    {
      PmicCdd_ReadWdModeStatus();
      PmicCdd_WdFailCntReg.value = PmicCdd_FailCnt_RxBuf[0];
      /* Window 1+window2 is required to actually clear the fail cnt - without getting clear if we exit LW
          there is a chance of Wdg getting serviced in the Bad window which cause the Reset */

      if (PmicCdd_WdFailCntReg.bits.wd_fail_cnt == 0x0u)
      {
        SWHangDumpClear.FaultId = 0x00;
        SWHangDumpClear.pc = 0x00U;
        SWHangDumpClear.rev = 0x00;
        PmicCdd_Read_FailCnt = FALSE;
        PmicCdd_DumpLog_Status = FALSE;
        PmicCdd_PmicWdg_FailInt_Status = FALSE;
        PmicCdd_WdErrStatus_ClearAllInterrupts();
        PmicCdd_Callout_WdgEarlyWarning(&SWHangDumpClear, 6U);
      }
    }
  }

#ifdef TEST_WDG
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_TestwdgRead))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif

#if (PMICCDD_ENABLE_WDG == STD_ON)
  if (PmicCdd_LongWin_PerformMcuReset != TRUE)
  {
#endif
    if ((PmicCdd_TxCrcErrorFlag != TRUE) && (PmicCdd_RxCrcErrorFlag != TRUE))
    {
      #if (PMICCDD_ENABLE_ADC == STD_ON)
      if (PmicCdd_Adc_Request_state == PMIC_ADC_CONVERSION_REQUEST_START)
      {
        PmicCdd_AdcStartConv_Pending++;
        if (PmicCdd_AdcStartConv_Pending >= 2U)
        {
          PmicCdd_AdcStartConv_Pending = 0U;
          // to resolve the issue of  Adc stop if Wdg triggering stops in middle and reports Fail interrupt
          if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntTop))
          {
            PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
          }
          else
          {
            PmicCdd_EnterCriticalSection();
            PmicCdd_ReadIntTop_Status = TRUE;
            PmicCdd_ExitCriticalSection();
          }
          PmicCdd_Adc_StartConversion();
        }
      }
      #endif

      flLevel = Dio_ReadChannel(PmicCdd_nINTGpioConf.Dio_nINTPin);
      if((flLevel == STD_LOW) && (PmicCdd_ReadIntTop_Status == FALSE))
      {
        if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntTop))
        {
          PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
        }
        else
        {
          PmicCdd_EnterCriticalSection();
          PmicCdd_ReadIntTop_Status = TRUE;
          PmicCdd_ExitCriticalSection();
        }
      }
    }
#if (PMICCDD_ENABLE_WDG == STD_ON)
  }
#endif

}

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   PmicCdd_WdgSetTriggerCondition
**
** Visibility       :   Public
**
** Description      :   Set the watchdog trigger condition. Timeout is the budget (ms) for which
**                      this driver may keep pulsing the PMIC WITHOUT a further authorisation from
**                      WdgM. Timeout==0 stops feeding immediately. A non-zero Timeout refreshes
**                      the budget and, if the GPT is stopped, re-arms it phase-aligned to WIN2.
**
** ---------------------------------------------------------------------------
** HOW TO CONFIGURE Timeout (WdgMTriggerConditionValue) - FTTI BUDGET
** ---------------------------------------------------------------------------
** Timeout is dead time in the FTTI: it buys no diagnostic value, it exists only to cover
** WdgM's own call jitter. Keep it at the floor and spend the remaining FTTI on the PMIC
** fail-counter windows, which DO buy value (glitch tolerance + the WD_FAIL_TH warning
** stage before the reset). Two fault classes reach the safe state by different routes:
**
**   (a) WdgM detects       -> WdgM calls SetTriggerCondition(0), feeding stops at T_detect
**   (b) WdgM itself dies   -> GPT ISR keeps feeding until this Timeout budget expires
**       (a full core hang with interrupts masked is benign here: no ISR => no pulses,
**        so the PMIC starts timing out immediately and the budget never applies)
**
** Both must fit the FTTI, so:
**
**   FTTI >= max( T_detect_WdgM , Timeout ) + N_bad * t_SEQ_MAX
**
**     N_bad     = WD_FAIL_TH + WD_RST_TH + 1        (wd_cnt_sel=0; halve if wd_cnt_sel=1)
**     t_SEQ_MAX = ((WD_WIN1+1) + (WD_WIN2+1)) * 0.55 * 1.05  ms   [SLVSGG7 Eq.5 + Eq.7]
**
** Use t_SEQ_MAX (not nominal): during fail-down no trigger arrives, so every bad event
** costs a full free-running WIN1+WIN2 at the slow-oscillator corner.
**
** Lower bound - so normal operation never trips (budget is debited in the ISR at Dt
** granularity and stop_now fires when the remainder cannot cover the NEXT interval, so
** real feeding time is [Timeout - Dt, Timeout]):
**
**   Timeout >= T_supervision_cycle + Dt + jitter
**     Dt = tWIN1_MAX + tWIN2_MIN/4 = PMIC_CALC_GPT_RELOAD_MS(WD_WIN1, WD_WIN2)
**
** Worked example - FTTI 500 ms, WIN1=WIN2=90 (50.05 ms nominal), wd_cnt_sel=0:
**   t_SEQ_MAX = 105.105 ms,  Dt = 64 ms
**   FAIL_TH=1, RST_TH=1 -> N_bad=3 -> Timeout <= 500 - 315.3 = 184.7 ms
**   Timeout = 150 ms    -> worst case 465.3 ms (35 ms margin), needs T_sc <= 86 ms
**
** NOTE: WdgM refreshes the FULL Timeout while global status is OK, FAILED **and** EXPIRED
** (WdgM.c) - only STOPPED passes 0. A supervision FAILURE therefore does not shorten the
** chain; sizing must assume the full Timeout is always granted right up to the fault.
** ---------------------------------------------------------------------------
**
** Invocation       :    WdgIf
**
** Inputs           :   uint8 DeviceIndex - Device Index
**                      uint16 Timeout - feeding budget in ms (0 = stop now). See FTTI notes above.
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/

void PmicCdd_WdgSetTriggerCondition(uint8 DeviceIndex, uint16 Timeout)
{
  (void)DeviceIndex;
  if (PmicCdd_WdModeReg.bits.wd_return_longwin != 1U)
  {
#if (PMICCDD_ENABLE_WDG == STD_ON)
    uint8 flDone = FALSE;
    PmicCdd_EnterCriticalSection();
    if (PmicCdd_WdgReset_Request != FALSE)
    {
      flDone = TRUE;
    }
    /* === STOP servicing immediately === */
    if ((flDone == FALSE) && (Timeout == 0u))
    {
      /* WdgM withdrew authorization: stop synchronously here (we hold the critical section) so
         Pmic_TimerRunning == 0 the instant this returns, rather than deferring the stop to a
         later ISR. The phase reference is preserved for a later aligned resume. */
      Pmic_WdgStopFeeding_Locked();
      flDone = TRUE;
    }

    /* === START or REFRESH servicing === */
    if (flDone == FALSE)
    {
      /* Re-base the pending debit onto the new budget.
         The ISR debits Pmic_LastIntervalTicks - the interval it armed - when that interval
         expires. On a refresh, part of that interval has usually already elapsed and belongs to
         the PREVIOUS budget; charging all of it to the new one shortens the new budget by up to
         a full GAP, which can exhaust it and force an unnecessary stop/re-align cycle.
         Charge only the portion still ahead of us.
         Gpt_ExtWdg_Win is a ONE-SHOT channel, so Gpt_GetTimeRemaining returns 0 once the timer
         has expired - the correct "whole interval already consumed" answer. Gpt_ValueType is
         uint32, same as the target, so no cast is needed. The call takes the GPT's own
         SchM critical section; that nests safely because the OS primitive is nesting-counted. */
      if (Pmic_TimerRunning != 0u)
      {
        Pmic_LastIntervalTicks = Gpt_GetTimeRemaining(GptConf_GptChannelConfiguration_Gpt_ExtWdg_Win);
      }

      /* Budget from now (64-bit safe ms→ticks) */
      PmicWdgTimeout = (uint32)((((uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz) * (uint64)Timeout) / 1000u);

      Pmic_Feeding = 1u;
      /* If GPT died (deep hang), re-arm with phase-aware schedule */
      if (Pmic_TimerRunning == 0u)
      {
        /* Phase-aware (re)start EVERY time we resume feeding */
        uint32 delay_ms = 0u;
        if (Pmic_GtcValid != 0u)
        {
          const uint32 now32 = Pmic_ReadGtc32();
          delay_ms = Pmic_ComputeDelayToWin2_ms(now32); /* returns 0 if already in WIN2 */
        }
        else
        {
          /* 1st time, no reference → fallback ≈ Δt.
             64-bit intermediate: at 25 MHz the product is ~1.6e9, but it exceeds uint32
             above a ~67 MHz GPT clock, so widen rather than depend on the configured rate. */
          delay_ms = (uint32)(((uint64)Pmic_GptTimerTickValue * 1000u) /
                              (uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz);
        }

        if (delay_ms == 0u)
        {
          delay_ms = PMIC_PHASE_MARGIN_MS;
        }

        /* Convert ms → GPT ticks (ceil to ≥1) */
        uint32 delay_ticks = (uint32)(((((uint64)PmicCdd_WdgConf.PmicCdd_GptClockSrc_Hertz) *
                                           (uint64)delay_ms) +
                                       999u) /
                                      1000u);


        /* Reprogram to the aligned expiry so ISR raises at the right moment */
        Pmic_PhaseAlignReq = 1u;
        Pmic_GptStop();             /* clear any pending */
        Pmic_GptStart(delay_ticks); /* ISR will do the rising on expiry */
        Pmic_LastIntervalTicks = delay_ticks; /* charge this wait like any other interval */
#ifdef TEST_SW_HANG
#ifdef VIP_UART_TEST
#if (DLTEXT_UART_PRINT == STD_ON)
        DltExt_Uart_Printf("GPT win2 alignement is  %lu ms\r\n", delay_ms);
#endif
#endif
#endif
      }
    }
    PmicCdd_ExitCriticalSection();
#endif
  }
}

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   PmicCdd_WdgSetMode
**
** Visibility       :   Public
**
** Description      :   Setting up a watchdog timer mode.
**
** Invocation       :   WdgIf
**
** Inputs           :  WdgIf_ModeType WdgMode - Mode of the watchdog
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/

Std_ReturnType PmicCdd_WdgSetMode(WdgIf_ModeType WdgMode)
{
  (void)WdgMode;
  return 0;
}

#if (PMICCDD_ENABLE_WDG == STD_ON)
/*============================================================================
**
** Function Name    :   PmicCdd_EnterWdgLongWin
**
** Visibility       :   Public
**
** Description      :   Enter watchdog Long Window and optionally trigger MCU reset.
**                      CRITICAL: Runs with interrupts masked (exception context). If IsRequiredMcuReset==TRUE,
**                      sends phase-aligned pulse into Window-2, waits confirmation, remaps GPIO2, calls
**                      Mcu_PerformReset(). If reset fails, PMIC Long Window timeout (1900ms) warm-resets SoC.
**
** Invocation       :   RstM_RequestSwReset (fault recovery)
**
** Inputs           :   IsRequiredMcuReset (TRUE=trigger reset; FALSE=enter LongWin only)
**
** Outputs          :   E_OK / E_NOT_OK
**
** Critical Section :   Yes (interrupts masked, I2C, GPIO)
**
**==========================================================================*/
Std_ReturnType PmicCdd_EnterWdgLongWin(boolean IsRequiredMcuReset)
{
  static PmicCdd_WdModeReg_t PmicCdd_ReadWdModeReg = {0x00u};
  Std_ReturnType RetVal = E_NOT_OK;
  volatile boolean i = TRUE;
  I2c_StatusType flI2c_Status = I2C_IDLE;
  ePmicCdd_I2cSeqQIDType flPmicCdd_I2cSeqQID = PmicCdd_None;
  PmicCdd_EnterCriticalSection();
  Pmic_WdgResetCapable = FALSE;
  // Bit to be set to enter into longwindow
  PmicCdd_WdModeReg.bits.wd_return_longwin = 1u;
  PmicCdd_WdModeReg_TxBuf[1] = PmicCdd_WdModeReg.value;

  if (IsRequiredMcuReset == TRUE)
  {
    /* Set reset flag and clear stale I2C sequences before reset flow */
    PmicCdd_LongWin_PerformMcuReset = TRUE;
    flPmicCdd_I2cSeqQID = PmicCdd_WdMode;

    PmicCdd_I2cSequence_QueueClear();
#if (PMICCDD_ENABLE_ADC == STD_ON)
    PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_NoInit;
    PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_STOP;
#endif
    ePmicCdd_FSM_State = PmicCdd_LWEnter_McuReset;
    flI2c_Status = I2c_GetStatus(I2C_PMIC);
    if (flI2c_Status == I2C_BUSY)
    {
      (void)I2c_FreeSlaveBus(I2C_PMIC);
    }

    RetVal = PmicCdd_I2CSyncTransmit(flPmicCdd_I2cSeqQID);
    if (RetVal == E_OK)
    {
#if (PMICCDD_WAIT_FOR_ENTERLONG_WIN == STD_OFF)
      /* Clear any transient WD_ERR_STATUS bits synchronously before resetting - must use the
         blocking transmit, not the async push/ClearAllInterrupts path, since that only starts
         the transfer and cannot guarantee completion before Mcu_PerformReset(). */
      PmicCdd_WdErrStatusReg.value = 0xFFu;
      PmicCdd_WdErrStatusReg_TxBuf[1] = PmicCdd_WdErrStatusReg.value;
      (void)PmicCdd_I2CSyncTransmit(PmicCdd_write_WdErrStatus);
      Mcu_PerformReset();
#else
      /* Why the forced pulse is phase-aligned rather than sent blind.
         Per SLVSGG7 6.3.10.5 ANY trigger pulse ends the current sequence and starts the next
         one - the window it lands in decides only whether it is a GOOD or a BAD event
         (6.3.10.6, Fig. 6-16): in Window-2 -> good event, WD_FAIL_CNT decrements; in Window-1
         -> bad event, WD_TRIG_EARLY + WD_BAD_EVENT and WD_FAIL_CNT INCREMENTS.
         WD_RETURN_LONGWIN only takes effect once the current sequence completes, so either
         window would technically get us into the Long Window. Aligning into Window-2 matters
         because a bad event here costs a WD_FAIL_CNT increment on a device that may already be
         close to (WD_FAIL_TH + WD_RST_TH) - that would turn this orderly diagnostic reset into
         a PMIC watchdog reset, losing the reset-reason distinction we are trying to preserve.
         Reuse the same GTC phase computation used to resume feeding after a hang - pure
         register read + arithmetic, no GPT/interrupt dependency, safe in this context. */
      {
        uint32 flDelayToWin2Ms;
        if (Pmic_GtcValid != 0u)
        {
          flDelayToWin2Ms = Pmic_ComputeDelayToWin2_ms(Pmic_ReadGtc32());
        }
        else
        {
          /* No prior phase info: wait past the LATEST possible end of WIN1, then add the
             margin. Must use WIN1_MAX, not the average - at the slow-oscillator corner WIN1
             runs to (WD_WIN1+1)*0.55*1.05, so an average-based wait still lands inside WIN1
             and the forced pulse becomes a WD_TRIG_EARLY bad event instead of a good event.
             Same bound as safe_win2_start in Pmic_ComputeDelayToWin2_ms - keep them in step. */
          const uint32 flWin1UsMax = PMIC_GET_TWINDOW_MAX_US(PmicCdd_WdgConf.ePmicCdd_Win1_Time);
          flDelayToWin2Ms = US_TO_MS(flWin1UsMax) + 1u + PMIC_PHASE_MARGIN_MS; /* +1 ms: US_TO_MS truncates */
        }

        if (flDelayToWin2Ms > 0u)
        {
          /* Busy-wait until Window-2 active (GTC-based, no interrupts) */
          const uint32 flWin2WaitStartTick = Pmic_ReadGtc32();
          const uint32 flWin2WaitTicks = flDelayToWin2Ms * PMIC_GTC_TICKS_PER_MS;
          #if(VC_TEST == STD_OFF)
          while ((uint32_t)(Pmic_ReadGtc32() - flWin2WaitStartTick) < flWin2WaitTicks)
          {
            /* wait until inside Window-2 */
          }
          #endif
        }
      }

      /* Now inside Window-2: send the service pulse so it lands as a genuine good event and
         ends the sequence immediately. */
      {
        const uint32 flPulseStartTick = Pmic_ReadGtc32();
        /* Ticks measured against Pmic_ReadGtc32() must use the GTC's own tick rate
           (PMIC_GTC_TICKS_PER_MS), not PmicCdd_GptClockSrc_Hertz - that's the GPT
           peripheral's clock, a different domain used only for loading the GPT hardware
           timer (e.g. Pmic_TicksPw). Mixing the two here previously made this pulse and
           margin run ~7x too short. */
        const uint32 flPulseTicks = PMIC_PULSE_MS * PMIC_GTC_TICKS_PER_MS;
        const uint32 flMarginTicks = PMIC_LWENTER_POST_PULSE_MARGIN_MS * PMIC_GTC_TICKS_PER_MS;
        uint32 flMarginStartTick;

        /* Drive the forced service pulse: HIGH for PMIC_PULSE_MS, then LOW */
        Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_HIGH);
        #if(VC_TEST == STD_OFF)
        while ((uint32_t)(Pmic_ReadGtc32() - flPulseStartTick) < flPulseTicks)
        {
          /* hold pulse high */
        }
        #endif
        Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);

        /* Give the PMIC time to register the pulse and complete the sequence transition */
        flMarginStartTick = Pmic_ReadGtc32();
        #if(VC_TEST == STD_OFF)
        while ((uint32_t)(Pmic_ReadGtc32() - flMarginStartTick) < flMarginTicks)
        {
          /* wait out post-pulse margin */
        }
        #endif
      }
      flPmicCdd_I2cSeqQID = PmicCdd_ReadWdMode;
      #if(VC_TEST == STD_OFF)
      PmicCdd_WdModeReg_RxBuf[0] = 0x00u;
      #endif
      PmicCdd_ReadWdModeReg.value = PmicCdd_WdModeReg_RxBuf[0];
      {
        /* Bounded retry: normally satisfied on the first attempt (the PMIC doesn't auto-clear
           this bit, so the readback just confirms what we already wrote). PMIC_LWENTER_CONFIRM_
           TIMEOUT_MS bounds how often we re-check the GTC deadline, not the total time spent here:
           this deadline is only sampled between calls to PmicCdd_I2CSyncTransmit, so a single stuck-
           bus call can itself run longer, since I2c_SyncTransmit chains up to four independent
           I2C_SYNC_TIMEOUT polling waits (Tx byte, ARDY, Rx byte, bus-free) before returning. The
           real worst case here is bounded by that I2C-level timeout, not by this constant - it does
           not hang forever, but it can exceed PMIC_LWENTER_CONFIRM_TIMEOUT_MS with interrupts masked.
           This path is also reached from ARM exception/fault recovery (RstM_RequestSwReset), where
           the bus could genuinely be unresponsive, so that worst case should be included in any
           WCET/safety timing budget for this function. */
        const uint32 flConfirmStartTick = Pmic_ReadGtc32();
        /* Ticks compared against Pmic_ReadGtc32() must use PMIC_GTC_TICKS_PER_MS, not
           PmicCdd_GptClockSrc_Hertz - same clock-domain mismatch as the pulse/margin above. */
        const uint32 flConfirmTimeoutTicks = PMIC_LWENTER_CONFIRM_TIMEOUT_MS * PMIC_GTC_TICKS_PER_MS;
        while ((PmicCdd_ReadWdModeReg.bits.wd_return_longwin == 0U) &&
               ((uint32_t)(Pmic_ReadGtc32() - flConfirmStartTick) < flConfirmTimeoutTicks))
        {
          RetVal = PmicCdd_I2CSyncTransmit(flPmicCdd_I2cSeqQID);
          if (RetVal == E_OK)
          {
            PmicCdd_ReadWdModeReg.value = PmicCdd_WdModeReg_RxBuf[0];
          }
        }
      }
      /* Un-assign GPIO2 from the watchdog-trigger function before resetting, instead of
         disabling the watchdog (WD_EN). Rationale: the trigger pin defaults HIGH for a few ms
         after the SoC reset - until the fresh boot re-inits the pad - and while the PMIC sits in
         Long Window that spurious rising edge is otherwise interpreted as a real watchdog-trigger,
         prematurely exiting Long Window and causing a bad event (WD_ERR_STATUS misreported on the
         next boot). Re-muxing GPIO2 to plain GPIO makes that edge invisible to the watchdog while
         leaving WD_EN=1 - so the Long Window timeout stays armed as a hang backstop (if this reset
         ever fails to take effect, the Long Window still times out and warm-resets the system;
         this is why no re-enable-on-return step is needed). The fresh boot's PmicCdd_GpioInit
         restores GPIO2 as TrigWdog. GPIO2_CONF is a lockable user register (device 0x48), so it
         must be unlocked first; no re-lock is needed since we reset immediately. All writes are
         synchronous so they complete on the bus before Mcu_PerformReset(). */
      {
        PmicCdd_Gpio2_Reg_t flGpio2Reg;
        /* Unlock user registers so GPIO2_CONF becomes writable */
        PmicCdd_Register_Lock_Reg.value = PMICCDD_REG_UNLOCK_VALUE;
        PmicCdd_RegisterUnlock_TxBuf[0] = REGISTER_LOCK_REG;
        PmicCdd_RegisterUnlock_TxBuf[1] = PmicCdd_Register_Lock_Reg.value;
        (void)PmicCdd_I2CSyncTransmit(PmicCdd_Write_RegisterUnlock);
        /* Re-mux GPIO2 to plain GPIO, preserving every other pad setting from init */
        flGpio2Reg.value = PmicCdd_Gpio2_Reg_TxBuf[1];
        flGpio2Reg.bits.gpio2_sel = (uint8)Pmic_GPIO2_Gpio;
        PmicCdd_Gpio2_Reg_TxBuf[1] = flGpio2Reg.value;
        (void)PmicCdd_I2CSyncTransmit(PmicCdd_Gpio2);
      }
      /* Clear any transient WD_ERR_STATUS bits synchronously before resetting - safety net in
         case a bad-event bit was latched before GPIO2 was re-muxed (e.g. from the forced pulse
         landing in Window-1), so a stray bit never gets misread as "watchdog reset" on the next
         boot. Must use the blocking transmit, not the async push/ClearAllInterrupts path, since
         that only starts the transfer and cannot guarantee completion before Mcu_PerformReset(). */
      PmicCdd_WdErrStatusReg.value = 0xFFu;
      PmicCdd_WdErrStatusReg_TxBuf[1] = PmicCdd_WdErrStatusReg.value;
      (void)PmicCdd_I2CSyncTransmit(PmicCdd_write_WdErrStatus);
      /* double check to ensure we are still in long window */
      Mcu_PerformReset();
      /* If Mcu_PerformReset() did not take effect immediately, WD_EN is still 1 and we are still
         in Long Window with GPIO2 no longer a trigger - so the PMIC Long Window timeout will
         warm-reset the system as the hang backstop. No watchdog re-enable is required here.

         CRITICAL BOOT-TIME CONSTRAINT (datasheet SLVSGG7 Eq. 2-3):
         After this reset is initiated, the entire next boot MUST complete watchdog takeover
         (PmicCdd_Init → first I2C write to WdMode → first watchdog feed ISR) within the
         Long Window timeout. Default config: WD_LONGWIN = 2000 ms → actual timeout = 1900 ms MIN.

         Boot timeline (nominal 25°C, optimized build):
         - t=0:    Mcu_PerformReset() triggers warm reset
         - t=0-50 ms:   MCU boot ROM runs
         - t=50-100 ms: Bootloader clocks/DDR init
         - t=100-300 ms: Kernel boot (compressed boot adds ~100 ms)
         - t=300-500 ms: PmicCdd_Init() runs, queue pushes
         - t=500-700 ms: First I2C queue completes, watchdog feed starts
         - MARGIN: 1900 - 700 = 1200 ms (safe)

         RISK FACTORS: If combined, boot can exceed 1900 ms timeout:
         - Debug build with -O0:     adds ~200-300 ms (kernel init slower)
         - Flash erase during boot:   adds ~50-150 ms (unpredictable)
         - Low-temp (-40°C):         clock drift ±10% → Long Window uncertainty ±200 ms

         MITIGATION: Configure Long Window timeout appropriately for your platform boot time.
         Target: Monitor that optimized boot completes PmicCdd_Init by t<1000 ms (leaves 900 ms margin).
         For debug builds, increase WD_LONGWIN to 3000+ ms, or disable watchdog during development. */
	  #if(VC_TEST == STD_OFF)
      while (i == TRUE)
      {
      }
	  #endif
#endif
    }
  }
  else
  {
    PmicCdd_LongWin_PerformMcuReset = FALSE;
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdMode))
    {
      RetVal = E_NOT_OK;
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }
  PmicCdd_ExitCriticalSection();
  return RetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_ExitWdgLongWin
**
** Visibility       :   Public
**
** Description      :   Exit watchdog long window.
**
** Invocation       :   Application
**
** Inputs           :  NA
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/
Std_ReturnType PmicCdd_ExitWdgLongWin(void)
{
  Std_ReturnType RetVal = E_OK;

  PmicCdd_EnterCriticalSection();
  /* Readiness is restored only by the successful WdMode-write callback. */
  Pmic_WdgResetCapable = FALSE;
  PmicCdd_WdModeReg.bits.wd_return_longwin = 0u;
  PmicCdd_WdModeReg.bits.wd_pwrhold = 0u;

  PmicCdd_WdModeReg_TxBuf[1] = PmicCdd_WdModeReg.value;
  PmicCdd_ExitCriticalSection();
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdMode))
  {
    RetVal = E_NOT_OK;
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  return RetVal;
}
#endif

#if (PMICCDD_ENABLE_ADC == STD_ON)
/*============================================================================
**
** Function Name    :   PmicCdd_RdivEnable
**
** Visibility       :   Public
**
** Description      :  This function is used set the rdiv_en bit in ADC_CTRL
**                     reg in rumtime - One time call is recommended before
**                     starting the IoHwAb conversion
**
** Invocation       :  Application
**
** Inputs           :   PmicCdd_AdcDividerType Rdiv_Enable
**
** Outputs          :   E_OK - Success
**                      E_NOT_OK - Failure
**
** Critical Section :  yes
**
**==========================================================================*/
extern Std_ReturnType PmicCdd_RdivEnable(PmicCdd_AdcDividerType Rdiv_Enable)
{
  Std_ReturnType RetVal = E_NOT_OK;
  // Setting the adc_rdiv_en in runtime, whenever the PmicCdd_IoHwAb_Adc_StartGroupConversion
  // is called, the rdiv_en will be changed in the pmic register
  if (ePmicCdd_FSM_State >= PmicCdd_InitProgress)
  {
    PmicCdd_AdCtrl_Reg.bits.adc_rdiv_en = (uint8)Rdiv_Enable;
    PmicCdd_AdCtrl_Reg.bits.adc_thermal_sel = 0u;
    PmicCdd_AdCtrl_Reg.bits.adc_cont_conv = 0u;
    PmicCdd_AdCtrl_Reg.bits.adc_start = 1u;
    PmicCdd_AdCtrl_Reg.bits.adc_status = 1u;
    PmicCdd_Adc_CtrlReg_TxBuf[1] = PmicCdd_AdCtrl_Reg.value;
    RetVal = E_OK;
  }
  return RetVal;
}
#endif

/*============================================================================
**
** Function Name    :   PmicCdd_I2CSyncTransmit
**
** Visibility       :   static
**
** Description      :   Sync Tranmit / Receive
**
** Invocation       :   Private
**
** Inputs           :   ePmicCdd_I2cSeqQIDType PmicCddI2cSeqID - Pmic I2C Sequence ID
**                      uint8 PmicCdd_Trasmit_Receive_Status - TRUE - Transmit; FALSE - Receive
**
** Outputs          :   Std_ReturnType - E_OK - Success; E_NOT_OK - Failure
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType PmicCdd_I2CSyncTransmit(ePmicCdd_I2cSeqQIDType PmicCddI2cSeqID)
{
  Std_ReturnType RetVal = E_OK;
  uint8 flIndex = 0;
  uint8 TxBuffer[PMICCDD_TXBUF_LENGTH];
  uint8 RxBuffer[PMICCDD_RXBUF_LENGTH];
  uint8 flCrcValue = 0;
  uint8 flRxCrcLengthTx = 0;
  uint8 flRxCrcLengthRx = 0;
  ePmicCdd_I2cSeqQIDType flPmicCdd_I2cSeqQID = PmicCdd_None;
  // Getting the corresponding I2C Sequence index
  for (flIndex = 0; flIndex < PMICCDD_MAX_I2C_SEQUENCE; flIndex++)
  {
    if (PmicCddI2cSeqID == PmicCdd_I2c_Sequence[flIndex].eI2cSeqQID)
    {
      break;
    }
  }
  PmicCdd_I2c_CurrentSequenceIndex = flIndex;
  if (flIndex != PMICCDD_MAX_I2C_SEQUENCE)
  {
// Calculate the CRC - as the CRC is enabled at the Pmic initialization
#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
    if ((PmicCdd_I2c_Sequence[flIndex].RxLength == 0x00u) && (PmicCdd_CrcEnabled == TRUE))
    {
      TxBuffer[flRxCrcLengthTx] = (PmicCdd_I2c_Sequence[flIndex].DeviceAddress << 1);
      flRxCrcLengthTx++;
      TxBuffer[flRxCrcLengthTx] = (uint8)PmicCdd_I2c_Sequence[flIndex].TxBuffer[0U];
      flRxCrcLengthTx++;
      TxBuffer[flRxCrcLengthTx] = PmicCdd_I2c_Sequence[flIndex].TxBuffer[1U];
      flRxCrcLengthTx++;

      flCrcValue = PmicCdd_CalculateCRC8Val(TxBuffer, flRxCrcLengthTx);

      PmicCdd_I2c_Sequence[flIndex].TxBuffer[2U] = flCrcValue;
      PmicCdd_I2c_Sequence[flIndex].TxLength = flRxCrcLengthTx;
    }
    else if ((PmicCdd_I2c_Sequence[flIndex].RxLength != 0x00u) && (PmicCdd_CrcEnabled == TRUE))
    {
      PmicCdd_I2c_Sequence[flIndex].RxLength = 2u;
    }
    else
    {
      // Do Nothing
    }
#endif

    RetVal = I2c_SetupEB(PmicCdd_GeneralConf.I2cChannelId, PmicCdd_I2c_Sequence[flIndex].TxBuffer,
                         PmicCdd_I2c_Sequence[flIndex].RxBuffer, PmicCdd_I2c_Sequence[flIndex].TxLength,
                         PmicCdd_I2c_Sequence[flIndex].RxLength, PmicCdd_I2c_Sequence[flIndex].DeviceAddress);

    if (RetVal == E_OK)
    {
      RetVal = I2c_SyncTransmit(PmicCdd_GeneralConf.I2cChannelId);
      if (RetVal == E_NOT_OK)
      {
        PmicCdd_Det_ReportError(PMICCDD_MAIN_FUNCTION, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
      }
      else
      {
#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
        if ((PmicCdd_I2c_Sequence[flIndex].RxLength > 0U) && (PmicCdd_CrcEnabled == TRUE))
        {
          RxBuffer[flRxCrcLengthRx] = (PmicCdd_I2c_Sequence[flIndex].DeviceAddress << 1);
          flRxCrcLengthRx++;
          RxBuffer[flRxCrcLengthRx] = (uint8)PmicCdd_I2c_Sequence[flIndex].TxBuffer[0U];
          flRxCrcLengthRx++;
          RxBuffer[flRxCrcLengthRx] = ((PmicCdd_I2c_Sequence[flIndex].DeviceAddress << 1) | 0x01U);
          flRxCrcLengthRx++;
          RxBuffer[flRxCrcLengthRx] = PmicCdd_I2c_Sequence[flIndex].RxBuffer[0U];
          flRxCrcLengthRx++;

          flCrcValue = PmicCdd_CalculateCRC8Val(RxBuffer, flRxCrcLengthRx);

          // check the calculate crc value with received crc value
          if (PmicCdd_I2c_Sequence[flIndex].RxBuffer[1U] != flCrcValue)
          {
            // CRC mismatch — bounded retry to prevent stack overflow in exception context
            PmicCdd_ReceiveCRCError_Count++;
            if (PmicCdd_ReceiveCRCError_Count >= PMICCDD_I2C_CRC_RETRYCOUNT)
            {
              // Retry threshold exceeded: report error and abort gracefully (LW timeout backstop)
              PmicCdd_Callout_SMError_Report(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_RECEIVE_CRC_FAILED);
              RetVal = E_NOT_OK;
              PmicCdd_ReceiveCRCError_Count = 0U; // reset counter for next transfer
            }
            else
            {
              /* Retry: bounded recursion is eliminated by returning error after threshold.
                 The retry's status MUST be propagated - RetVal still holds the E_OK from the
                 I2c_SyncTransmit above, so discarding it would report success to the caller
                 even when every retry failed CRC, letting it consume corrupt/stale data. */
              flPmicCdd_I2cSeqQID = PmicCdd_I2c_Sequence[flIndex].eI2cSeqQID;
              RetVal = PmicCdd_I2CSyncTransmit(flPmicCdd_I2cSeqQID);
            }
          }
          else
          {
            // CRC match: clear error counter for next transfer
            PmicCdd_ReceiveCRCError_Count = 0U;
          }
        }
#endif
      }
    }
  }
  return RetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_I2cDispatchNextIfIdle
**
** Visibility       :   Static (Internal)
**
** Description      :   Pop next I2C sequence from queue and start async transmit if FSM is idle.
**                      Handles re-push of failed sequences for safety-critical operations (M5 fix).
**
** Invocation       :   MainFunction, EndNotification, ADC callbacks
**
** Inputs           :   None (uses queue and FSM state)
**
** Outputs          :   Updates FSM to SeqProgress if sequence started; back to Idle on start failure
**
** Critical Section :   Yes (protects queue access and FSM state)
**
**==========================================================================*/
static void PmicCdd_I2cDispatchNextIfIdle(void)
{
  ePmicCdd_I2cSeqQIDType flNextSeq = (ePmicCdd_I2cSeqQIDType)0;
  uint8 flStartNow = 0U;

  PmicCdd_EnterCriticalSection();

  if ((ePmicCdd_FSM_State == PmicCdd_InitDone) || (ePmicCdd_FSM_State == PmicCdd_MainProcess_SeqDone))
  {
    ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;
  }

  if (ePmicCdd_FSM_State == PmicCdd_MainProcess_Idle)
  {
    /* Inline pop (no nested critical section) */
    if ((PmicCdd_QueueHead != PmicCdd_QueueTail) || (PmicCdd_QueueFull == TRUE))
    {
      flNextSeq = (ePmicCdd_I2cSeqQIDType)PmicCdd_I2c_SequenceQueue[PmicCdd_QueueHead];
      PmicCdd_QueueHead = (uint8)((PmicCdd_QueueHead + 1U) % (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE);
      PmicCdd_QueueFull = FALSE;

      ePmicCdd_FSM_State = PmicCdd_MainProcess_SeqProgress;
      flStartNow = 1U;
    }
  }

  PmicCdd_ExitCriticalSection();

  if (flStartNow == 1U)
  {
    if (E_OK != PmicCdd_I2CASyncTransmit(flNextSeq))
    {
      PmicCdd_Det_ReportError(PMICCDD_MAIN_FUNCTION, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);

      PmicCdd_EnterCriticalSection();
      ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;
      PmicCdd_ExitCriticalSection();
    }
  }
}

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   PmicCdd_I2cEndNotification
**
** Visibility       :   Public
**
** Description      :   Callback function for I2C sequence end.
**
** Invocation       :   I2C
**
** Inputs           :   uint8 sequence - Sequence ID
**                      uint8 busstate - Bus State
**                      uint8 sequencestate - Sequence State
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void PmicCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
  // Not used so making as void for Sequence and Busstate
  (void)sequence;
  (void)busstate;
  ePmicCdd_I2cSeqQIDType flPmicCdd_I2cSeqQID;
  uint8 RxBuffer[PMICCDD_RXBUF_LENGTH];
  uint8 flRxCrcLength = 0;
  uint8 flCrcValue = 0;
  static const uint8 maxRetries = PMICCDD_I2C_RETRYCOUNT;
  static uint8 PmicCdd_I2c_FailedTransmitSequenceIndex = 0U;
  /* retryCount, saved_fsm_state and fsm_state_saved are file-scope (see top of file) so the UT can reach them */

  if (I2C_SEQ_OK == sequencestate)
  {
    retryCount = 0;
    /* Restore FSM state after successful retry from bus error (M1 fix: preserve state) */
    if (fsm_state_saved == TRUE)
    {
      ePmicCdd_FSM_State = saved_fsm_state;
      fsm_state_saved = FALSE;
    }
    /* This is needed to identify in which sequence the crc_comm_int is set. when the int get set
    we will be pushing the sequence to read read top, fsm and clear fsm. So if we minus 4 index
    then we'll get the exact sequence where TX CRC / Register lock fault will be found.
    Wrap-safe lookback: PmicCdd_QueueTail is a uint8 that wraps modulo
    PMICCDD_MAX_I2C_SEQUENCE_QUEUE, so a plain "- 4U" underflows to a huge unsigned index (OOB)
    whenever the tail is 0..3. Add the queue size before subtracting so the modulo yields the
    correct in-bounds slot in all cases. */
    PmicCdd_I2c_FailedTransmitSequenceIndex = (uint8)PmicCdd_I2c_SequenceQueue[(uint8)((PmicCdd_QueueTail + (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE - 4U) % (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE)];
// CRC Code - Receive CRC
#if (PMICCDD_I2C_ENABLE_CRC == STD_ON)
    /* 
       (1) On a CRC mismatch the retry below is started, but execution still FALLS THROUGH into
           the normal post-processing further down, so the CORRUPT RxBuffer is consumed anyway
           and a second transfer can be started in the same callback (double-start). A single
           bus-noise burst can therefore surface as a spurious fault report.
       (2) The retry counter is reported-and-reset at the threshold rather than aborting, so the
           mismatch path can re-arm indefinitely while the bus stays noisy.
       (3) with PMICCDD_I2C_ENABLE_CRC == STD_OFF (or before PmicCdd_Config2
           sets PmicCdd_CrcEnabled) received data is consumed with NO integrity check at all.
           Not reachable in production, where CRC is ON.
       Fixing these properly needs the callback restructured so the mismatch path returns early;
       that is deliberately NOT attempted here. Do not treat this block as verified. */
    if ((PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].RxLength > 0U) && (PmicCdd_CrcEnabled == TRUE))
    {
      RxBuffer[flRxCrcLength] = (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].DeviceAddress << 1U);
      flRxCrcLength++;
      RxBuffer[flRxCrcLength] = (uint8)PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].TxBuffer[0U];
      flRxCrcLength++;
      RxBuffer[flRxCrcLength] = ((PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].DeviceAddress << 1U) | 0x01U);
      flRxCrcLength++;
      RxBuffer[flRxCrcLength] = PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].RxBuffer[0U];
      flRxCrcLength++;

      flCrcValue = PmicCdd_CalculateCRC8Val(RxBuffer, flRxCrcLength);

      // check the calculate crc value with received crc value
      if (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].RxBuffer[1U] != flCrcValue)
      {
        PmicCdd_RxCrcErrorFlag = TRUE;
        // CRC mismatch
        PmicCdd_ReceiveCRCError_Count++;
        flPmicCdd_I2cSeqQID = PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].eI2cSeqQID;
        if (PmicCdd_ReceiveCRCError_Count == PMICCDD_I2C_CRC_RETRYCOUNT)
        {
          // Report to RstM
          PmicCdd_ReceiveCRCError_Count = 0U;
            PmicCdd_Callout_SMError_Report(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_RECEIVE_CRC_FAILED);
        }
        (void)PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID);
      }
      else
      {
        // CRC match
        PmicCdd_RxCrcErrorFlag = FALSE;
        PmicCdd_ReceiveCRCError_Count = 0U;
      }
    }
    // CRC Flag Set
    if (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].eI2cSeqQID == PmicCdd_Config2)
    {
      PmicCdd_CrcEnabled = TRUE;
    }

    // FailCnt Read back
    if (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].eI2cSeqQID == PmicCdd_FailCnt)
    {
      PmicCdd_Read_FailCnt = TRUE;
    }
#endif

    if (PmicCdd_ReceiveCRCError_Count == 0U)
    {
      if (PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].PmicCdd_SeQEndCb != NULL_PTR)
      {
        PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].PmicCdd_SeQEndCb(PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].eI2cSeqQID);
      }
    }

    // If there is no CRC mismatch in the received data, then the other sequence can be processed
    if (PmicCdd_ReceiveCRCError_Count == 0U)
    {
      if (ePmicCdd_FSM_State == PmicCdd_InitProgress)
      {
        /* Pop the sequence number first before tranmitting sequnece number to I2C Asyn Tranmsit always*/
        if (E_OK == PmicCdd_I2cPopSequence(&flPmicCdd_I2cSeqQID))
        {
          if (E_OK != PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID))
          {
            /* No re-push during init: auto-start is blocked while FSM==InitProgress, so a
               re-queued entry could never dispatch. Init chain stalls; recovery is re-init. */
            PmicCdd_Det_ReportError(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
          }
        }
        else /* At the end of Init sequence, check if any CRC is there. if yes then retry init sequnce */
        {
          if ((PmicCdd_TxCrcErrorFlag != FALSE) && (PmicCdd_TransmitCRCError_Count < PMICCDD_I2C_CRC_RETRYCOUNT))
          {
            PmicCdd_TxCrcErrorFlag = 0U;
            PmicCdd_Push_SeqAfterCrc();
            if (E_OK == PmicCdd_I2cPopSequence(&flPmicCdd_I2cSeqQID))
            {
              if (E_OK != PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID))
              {
                /* No re-push: init context, same stall limitation as above */
                PmicCdd_Det_ReportError(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
              }
            }
          }
          else
          {
            /* The queue is empty only after the initialization reads, cascaded detail
               reads and their callbacks have completed. Publish the captured reason
               before exposing InitDone to other contexts. */
            PmicCdd_EnterCriticalSection();
            PmicCdd_Latched_Reset_Reason = PmicCdd_DetermineResetReason();
            ePmicCdd_FSM_State = PmicCdd_InitDone;
            PmicCdd_ExitCriticalSection();
          }
        }
      }
      else if (ePmicCdd_FSM_State == PmicCdd_MainProcess_SeqProgress)
      {
        /* Pop the sequence number first before tranmitting sequnece number to I2C Asyn Tranmsit always*/
        if (E_OK == PmicCdd_I2cPopSequence(&flPmicCdd_I2cSeqQID))
        {
          if (E_OK != PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID))
          {
            PmicCdd_Det_ReportError(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
          }
        }
        else
        {
          if ((PmicCdd_TxCrcErrorFlag != FALSE) && (PmicCdd_TransmitCRCError_Count < PMICCDD_I2C_CRC_RETRYCOUNT))
          {
            PmicCdd_TxCrcErrorFlag = 0U;
            ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;

            if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_I2c_FailedTransmitSequenceIndex))
            {
              PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
            }

            
            if (E_OK == PmicCdd_I2cPopSequence(&flPmicCdd_I2cSeqQID))
            {
              if (E_OK != PmicCdd_I2CASyncTransmit(flPmicCdd_I2cSeqQID))
              {
                PmicCdd_Det_ReportError(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);
              }
            }
            else
            {
              // ToDo for any other transmission added later
            }
          }
          else
          {
            ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;

            /* Drain any sequences pushed from callback (ADC result, retries, etc.) */
            PmicCdd_I2cDispatchNextIfIdle();

            /* Check for Any error interrupt is set to notify application if configured */
            if (PmicCdd_ReportErrorStatus != 0U)
            {
              if (PmicCdd_GeneralConf.PmicCdd_ReportError != NULL_PTR)
              {
                PmicCdd_GeneralConf.PmicCdd_ReportError(PmicCdd_ReportErrorStatus);
                PmicCdd_ReportErrorStatus = 0U;
              }
            }
          }
        }
      }
      else
      {
        // Do Nothing
      }
    }
  }
  else if (retryCount < maxRetries)
  {
    /* I2C bus error: save FSM state, force Idle for retry, restore on success (M1 fix) */
    retryCount++;
    if (fsm_state_saved == FALSE) /* only first error saves; consecutive errors must not clobber it with Idle */
    {
      saved_fsm_state = ePmicCdd_FSM_State;
      fsm_state_saved = TRUE;
    }
    ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;
#if (PMICCDD_ENABLE_ADC == STD_ON)
    PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Idle;
#endif
    (void)PmicCdd_I2CASyncTransmit(PmicCdd_I2c_Sequence[PmicCdd_I2c_CurrentSequenceIndex].eI2cSeqQID);
  }
  else
  {
    ePmicCdd_FSM_State = PmicCdd_SeqFailed;
    fsm_state_saved = FALSE; /* discard stale save so it cannot fire after later recovery/re-init */
    PmicCdd_I2cSequence_QueueClear();
    PmicCdd_Det_ReportError(PMICCDD_I2C_CB, PMICCDD_ERROR_I2C_CB_SEQUENCE_FAILED);
  }
}

/*****************************************************************************
 *                               Functions                                    *
 ******************************************************************************/
/*============================================================================
**
** Function Name    :   Gpt_ExtWDNotify
**
** Visibility       :   Public
**
** Description      :   Periodically checks and updates the watchdog timer.
**
** Invocation       :   ISR
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void Gpt_ExtWDNotify(void)
{
  if (PmicCdd_WdModeReg.bits.wd_return_longwin != 1U)
  {
#if (PMICCDD_ENABLE_WDG == STD_ON)
    uint8 stop_now = FALSE;
    uint8 skip_rest = FALSE;
    uint8 did_just_rise = FALSE; /* Skip normal cadence switch if phase-align/resume just performed a rise */
    PmicCdd_EnterCriticalSection();

    /* Reset requested (a GPT notification may already be pending when the reset path stops GPT):
       stop feeding through the same single transition as every other stop. */
    if (PmicCdd_WdgReset_Request != FALSE)
    {
      Pmic_WdgStopFeeding_Locked();
      skip_rest = TRUE;
    }

    /* debit last scheduled interval (PW or GAP) */
    if ((skip_rest == FALSE) && (Pmic_LastIntervalTicks != 0u))
    {
      if (PmicWdgTimeout > Pmic_LastIntervalTicks)
      {
        PmicWdgTimeout -= Pmic_LastIntervalTicks;
      }
      else
      {
        PmicWdgTimeout = 0u;
      }
      Pmic_CumTicks += (uint64)Pmic_LastIntervalTicks;
      Pmic_LastIntervalTicks = 0u;
    }

    /* ISR fired while not feeding -> normalise to the idle state and stop. Two legitimate cases:
     *  1) Bootstrap: PmicCdd_CBStartWdgGpt() arms the GPT with Feeding==0 after Long-Window exit
     *     to produce exactly this first ISR, which establishes the Pmic_TimerRunning==0 baseline
     *     that the first PmicCdd_WdgSetTriggerCondition() needs for a phase-aligned start.
     *  2) A GPT interrupt that latched at the controller just before a synchronous stop and still
     *     fires once. (The primary stop paths - WdgM stop and budget-exhausted - already called
     *     Pmic_WdgStopFeeding_Locked at the source, so this is not where feeding normally stops.)
     * The helper is idempotent, so both cases are safe. */
    if ((skip_rest == FALSE) && (Pmic_Feeding == 0u))
    {
      Pmic_WdgStopFeeding_Locked();
      skip_rest = TRUE;
    }
    if (skip_rest == FALSE)
    {
      /* feeding enabled */
      if (PmicWdgTimeout == 0u)
      {
        stop_now = TRUE;
      }

      /* One-time phase-aligned resume (preferred path after deep hang) */
      if (stop_now == FALSE)
      {
        if (Pmic_PhaseAlignReq != 0u)
        {
          if (PmicWdgTimeout <= Pmic_TicksPw)
          {
            stop_now = TRUE;
          }
          else
          {
            /* RISE now — skip normal cadence switch this invocation to preserve ~5ms pulse */
            Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_HIGH);
            Pmic_PinHigh = 1u;
            Pmic_LastRiseTick = Pmic_CumTicks;

            /* Capture 32-bit GTC for next-resume reference */
            Pmic_LastRiseGtc32 = Pmic_ReadGtc32();
            Pmic_GtcValid = 1u;

            Pmic_GptStop();
            Pmic_GptStart(Pmic_TicksPw);
            Pmic_LastIntervalTicks = Pmic_TicksPw;
            Pmic_IsrState = PMIC_WDG_HIGH_PW;
            did_just_rise = TRUE; /* Prevent switch from immediately driving pin LOW */
          }
          Pmic_PhaseAlignReq = 0u; /* consume request */
        }
        /* Fallback: legacy blind resume (kept for safety) */
        else if (Pmic_ResumeKickRequested != 0u)
        {
          if (PmicWdgTimeout <= Pmic_TicksPw)
          {
            stop_now = TRUE;
          }
          else
          {
            /* RISE now — skip normal cadence switch this invocation to preserve ~5ms pulse */
            Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_HIGH);
            Pmic_PinHigh = 1u;
            Pmic_LastRiseTick = Pmic_CumTicks;

            Pmic_LastRiseGtc32 = Pmic_ReadGtc32();
            Pmic_GtcValid = 1u;

            Pmic_GptStop();
            Pmic_GptStart(Pmic_TicksPw);
            Pmic_LastIntervalTicks = Pmic_TicksPw;
            Pmic_IsrState = PMIC_WDG_HIGH_PW;
            did_just_rise = TRUE; /* Prevent switch from immediately driving pin LOW */
          }
          Pmic_ResumeKickRequested = 0u;
        }
        else
        {
          // do nothing
        }
        /* Normal cadence — skip if we just performed a rise (wait for next ISR invocation to run switch) */
        if (did_just_rise == FALSE)
        {
          switch (Pmic_IsrState)
          {
          case PMIC_WDG_HIGH_PW:
            /* end PW → LOW, then GAP if budget allows */
            Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);
            Pmic_PinHigh = 0u;
            if (PmicWdgTimeout <= Pmic_TicksGap)
            {
              stop_now = TRUE;
              break;
            }
            Pmic_GptStop();
            Pmic_GptStart(Pmic_TicksGap);
            Pmic_LastIntervalTicks = Pmic_TicksGap;
            Pmic_IsrState = PMIC_WDG_LOW_GAP;
            break;

          case PMIC_WDG_LOW_GAP:
            /* end GAP → RISE now, then PW if budget allows */
            if (PmicWdgTimeout <= Pmic_TicksPw)
            {
              stop_now = TRUE;
              break;
            }
            Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_HIGH);
            Pmic_PinHigh = 1u;
            Pmic_LastRiseTick = Pmic_CumTicks;

            Pmic_LastRiseGtc32 = Pmic_ReadGtc32();
            Pmic_GtcValid = 1u;

            Pmic_GptStop();
            Pmic_GptStart(Pmic_TicksPw);
            Pmic_LastIntervalTicks = Pmic_TicksPw;
            Pmic_IsrState = PMIC_WDG_HIGH_PW;
            break;

          default:
            stop_now = TRUE;
            break;
          }
        } /* close if (did_just_rise == FALSE) */
      }
      else
      {
        // do nothing
      }

      if (stop_now != FALSE)
      {
        /* Feeding budget exhausted (can't cover the next pin edge): stop synchronously and land
           in the single idle state. Was previously a re-arm-for-one-tick coast that left
           Pmic_TimerRunning == 1 until a trailing ISR; now it stops immediately. */
        Pmic_WdgStopFeeding_Locked();
      }
    }
    PmicCdd_ExitCriticalSection();
#endif
  }
}

/* Error interrupt Clear function */

/*============================================================================
**
** Function Name    :   PmicCdd_IntBuck_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Buck Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntBuck_ClearAllInterrupts(void)
{
  PmicCdd_IntBuck_Reg.bits.buck1_uvov_int = 1u;
  PmicCdd_IntBuck_Reg.bits.buck2_uvov_int = 1u;
  PmicCdd_IntBuck_Reg.bits.buck3_uvov_int = 1u;
  PmicCdd_IntBuck_Reg.bits.buck4_uvov_int = 1u;
  PmicCdd_IntBuck_TxBuf[1] = PmicCdd_IntBuck_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntBuck))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntLdoVmon_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Ldo and Vmon Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntLdoVmon_ClearAllInterrupts(void)
{
  PmicCdd_IntLdoVmon_Reg.bits.ldo1_uvov_int = 1u;
  PmicCdd_IntLdoVmon_Reg.bits.ldo2_uvov_int = 1u;
  PmicCdd_IntLdoVmon_Reg.bits.ldo3_uvov_int = 1u;
  PmicCdd_IntLdoVmon_Reg.bits.vcca_uvov_int = 1u;
  PmicCdd_IntLdoVmon_Reg.bits.vmon1_uvov_int = 1u;
  PmicCdd_IntLdoVmon_Reg.bits.vmon2_uvov_int = 1u;
  PmicCdd_IntLdoVmon_TxBuf[1] = PmicCdd_IntLdoVmon_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntLdoVmon))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntGpio_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Gpio Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntGpio_ClearAllInterrupts(void)
{
  PmicCdd_IntGpio_Reg.bits.gpio1_int = 1u;
  PmicCdd_IntGpio_Reg.bits.gpio2_int = 1u;
  PmicCdd_IntGpio_Reg.bits.gpio3_int = 1u;
  PmicCdd_IntGpio_Reg.bits.gpio4_int = 1u;
  PmicCdd_IntGpio_Reg.bits.gpio5_int = 1u;
  PmicCdd_IntGpio_Reg.bits.gpio6_int = 1u;

  PmicCdd_IntGpio_TxBuf[1] = PmicCdd_IntGpio_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntGpio))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntStartup_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Startup Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntStartup_ClearAllInterrupts(void)
{
  PmicCdd_IntStartup_Reg.bits.enable_int = 1u;
  PmicCdd_IntStartup_Reg.bits.fsd_int = 1u;
  PmicCdd_IntStartup_Reg.bits.pb_short_int = 1u;
  PmicCdd_IntStartup_Reg.bits.soft_reboot_int = 1u;
  PmicCdd_IntStartup_Reg.bits.vsense_int = 1u;

  PmicCdd_IntStartup_TxBuf[1] = PmicCdd_IntStartup_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntStartup))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntMisc_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Miscellaneous Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntMisc_ClearAllInterrupts(void)
{
  PmicCdd_IntMisc_Reg.bits.bist_pass_int = 1u;
  PmicCdd_IntMisc_Reg.bits.ext_clk_int = 1u;
  PmicCdd_IntMisc_Reg.bits.reg_unlock_int = 1u;
  PmicCdd_IntMisc_Reg.bits.twarn_int = 1u;
  PmicCdd_IntMisc_Reg.bits.pb_long_int = 1u;
  PmicCdd_IntMisc_Reg.bits.pb_fall_int = 1u;
  PmicCdd_IntMisc_Reg.bits.pb_rise_int = 1u;
  PmicCdd_IntMisc_Reg.bits.adc_conv_ready_int = 1u;
  PmicCdd_IntMisc_TxBuf[1] = PmicCdd_IntMisc_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntMisc))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntModerateError_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Moderate Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntModerateError_ClearAllInterrupts(void)
{
  PmicCdd_IntModerate_Reg.bits.tsd_ord_int = 1u;
  PmicCdd_IntModerate_Reg.bits.bist_fail_int = 1u;
  PmicCdd_IntModerate_Reg.bits.reg_crc_err_int = 1u;
  PmicCdd_IntModerate_Reg.bits.recov_cnt_int = 1u;

  PmicCdd_IntModerateError_TxBuf[1] = PmicCdd_IntModerate_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntModerateError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntSevere_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Severe Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntSevere_ClearAllInterrupts(void)
{
  PmicCdd_IntSevereErr_Reg.bits.tsd_imm_int = 1u;
  PmicCdd_IntSevereErr_Reg.bits.vcca_ovp_int = 1u;
  PmicCdd_IntSevereErr_Reg.bits.pfsm_err_int = 1u;
  PmicCdd_IntSevereErr_Reg.bits.bg_xmon_int = 1u;

  PmicCdd_IntSevereError_TxBuf[1] = PmicCdd_IntSevereErr_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntSevereError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntFsmErr_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Fsm Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntFsmErr_ClearAllInterrupts(void)
{
  PmicCdd_IntFsmErr_Reg.bits.imm_shutdown_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.ord_shutdown_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.mcu_pwr_err_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.soc_pwr_err_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.comm_err_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.i2c2_err_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.esm_int = 1u;
  PmicCdd_IntFsmErr_Reg.bits.wd_int = 1u;

  PmicCdd_IntFsmError_TxBuf[1] = PmicCdd_IntFsmErr_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntFsmError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IntEsm_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Esm Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IntEsm_ClearAllInterrupts(void)
{
  PmicCdd_IntEsm_Reg.bits.esm_mcu_fail_int = 1u;
  PmicCdd_IntEsm_Reg.bits.esm_mcu_pin_int = 1u;
  PmicCdd_IntEsm_Reg.bits.esm_mcu_rst_int = 1u;

  PmicCdd_IntEsm_TxBuf[1] = PmicCdd_IntEsm_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntEsm))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_WdErrStatus_ClearAllInterrupts
**
** Visibility       :   Public
**
** Description      :  This clears all the Watchdog Interrupts
**
** Invocation       :  Public
**
** Inputs           :   void
**
** Outputs          :  void
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_WdErrStatus_ClearAllInterrupts(void)
{
  PmicCdd_WdErrStatusReg.bits.wd_longwin_timeout_int = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_timeout = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_trig_early = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_answ_early = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_seq_err = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_answ_err = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_fail_int = 1u;
  PmicCdd_WdErrStatusReg.bits.wd_rst_int = 1u;

  PmicCdd_WdErrStatusReg_TxBuf[1] = PmicCdd_WdErrStatusReg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_write_WdErrStatus))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/* ADC Implementation */
#if (PMICCDD_ENABLE_ADC == STD_ON)
/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_SetupResultBuffer
**
** Visibility       :   Public
**
** Description      :   This function used in Setting up the result buffer for ADC
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**                      PmicCdd_Adc_ResultBufferType* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK: ADC Result buffer is setup successfully.
**                     E_NOT_OK: ADC Result buffer is not setup successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_IoHwAb_Adc_SetupResultBuffer(PmicCdd_Adc_GroupType Group, const uint16 *DataResultBufferPtr)
{
  Std_ReturnType flRetVal = E_NOT_OK;

  /* This CDD uses ReadGroup() to copy the completed sample. The setup API therefore
   * validates the caller-provided buffer but does not retain a pointer-to-const. */
  if (((uint8)Group == PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM) &&
      (DataResultBufferPtr != NULL_PTR) &&
      (ePmicCdd_FSM_State >= PmicCdd_InitDone))
  {
    flRetVal = E_OK;
  }

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_StartGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in start the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_StartGroupConversion(PmicCdd_Adc_GroupType Group)
{
#if (PMICCDD_ENABLE_WDG == STD_ON)
  if (PmicCdd_LongWin_PerformMcuReset != TRUE)
  {
#endif
    if (PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM == (uint8)Group)
    {
      if ((PmicCdd_GpiosConfig.GPIO5 == Pmic_GPIO5_ADC_In) || (PmicCdd_GpiosConfig.GPIO4 == Pmic_GPIO4_ADC_In))
      {
        PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_START;
        PmicCdd_Adc_StartConversion();
      }
    }
#if (PMICCDD_ENABLE_WDG == STD_ON)
  }
#endif
}

/*============================================================================
**
** Function Name    :   PmicCdd_Adc_StartConversion
**
** Visibility       :   Static
**
** Description      :   This function is used to start the ADC conversion.
**                     It checks the current ADC conversion state and
**                     initiates a new conversion request if the state
**                     is either idle or done.
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
static void PmicCdd_Adc_StartConversion(void)
{
  if (ePmicCdd_FSM_State >= PmicCdd_InitDone)
  {
    if ((PmicCdd_Adc_FSM_State == PmicCdd_ADC_Conv_Idle) || (PmicCdd_Adc_FSM_State == PmicCdd_ADC_Conv_Done))
    {
      PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Requested;
      if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_AdcCtrl))
      {
        PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
      }
    }
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_StopGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in stop the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_StopGroupConversion(PmicCdd_Adc_GroupType Group)
{
  if (PmicCdd_AdcConf_AdcGroupId_AdcGroup_ANA_COM == (uint8)Group)
  {
    if ((PmicCdd_GpiosConfig.GPIO5 == Pmic_GPIO5_ADC_In) || (PmicCdd_GpiosConfig.GPIO4 == Pmic_GPIO4_ADC_In))
    {

      if (PmicCdd_Adc_GroupNotification != FALSE)
      {
        PMICCDD_CONV_COMPLETED_CB();
      }
      PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_STOP;
    }
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_ReadGroup
**
** Visibility       :   Public
**
** Description      :   This function used to get the ADC result
**
** Invocation       :   Application
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**                      uint16* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK - ADC Result is read successfully.
**                     E_NOT_OK - ADC Result is not read successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_IoHwAb_Adc_ReadGroup(PmicCdd_Adc_GroupType Group, uint16 *DataResultBufferPtr)
{
  (void)Group;
  Std_ReturnType flRetVal = E_NOT_OK;
  /* NULL guard is part of the same condition so a NULL caller neither dereferences nor
     consumes the pending result (Result_Status stays E_OK for a later valid read). */
  if ((PmicCdd_Adc_Result_Status == E_OK) && (DataResultBufferPtr != NULL_PTR))
  {
    *DataResultBufferPtr = PmicCdd_Adc_ResultBuffer;
    PmicCdd_Adc_Result_Status = E_NOT_OK;
    flRetVal = E_OK;
  }
  return flRetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :
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
void PmicCdd_IoHwAb_Adc_EnableHardwareTrigger(PmicCdd_Adc_GroupType Group)
{
  (void)Group;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :
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
void PmicCdd_IoHwAb_Adc_DisableHardwareTrigger(PmicCdd_Adc_GroupType Group)
{
  (void)Group;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_EnableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This enables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_EnableGroupNotification(PmicCdd_Adc_GroupType Group)
{
  (void)Group;
  PmicCdd_Adc_GroupNotification = 0xFFU;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_DisableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/
void PmicCdd_IoHwAb_Adc_DisableGroupNotification(PmicCdd_Adc_GroupType Group)
{
  (void)Group;
  PmicCdd_Adc_GroupNotification = 0x0U;
}

/*============================================================================
**
** Function Name    :   PmicCdd_IoHwAb_Adc_GetGroupStatus
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   PmicCdd_Adc_GroupType Group - ADC Group
**
** Outputs          :  PMICCDD_ADC_BUSY - ADC is busy
**                     PMICCDD_ADC_STREAM_COMPLETED - ADC is completed
**                     PMICCDD_ADC_ERROR - ADC is in error state
**                     PMICCDD_ADC_IDLE - ADC is in idle state
**
** Critical Section :  No
**
**==========================================================================*/
PmicCdd_Adc_StatusType PmicCdd_IoHwAb_Adc_GetGroupStatus(PmicCdd_Adc_GroupType Group)
{
  (void)Group;
  PmicCdd_Adc_StatusType flRetVal = PMICCDD_ADC_IDLE;
  if (PmicCdd_Adc_FSM_State == PmicCdd_ADC_Conv_Idle)
  {
    flRetVal = PMICCDD_ADC_IDLE;
  }
  else if (PmicCdd_Adc_FSM_State == PmicCdd_ADC_Read_Result)
  {
    flRetVal = PMICCDD_ADC_STREAM_COMPLETED;
  }
  else
  {
    flRetVal = PMICCDD_ADC_BUSY;
  }
  return flRetVal;
}
#endif
/*============================================================================
**
** Function Name    :   PmicCdd_nINTGpioInt
**
** Visibility       :   Public
**
** Description      :  This handles the ADC Conversion by checking the status of Interrupt registers
**
** Invocation       :  ISR
**
** Inputs           :   void
**
** Outputs          :  None
**
** Critical Section :  yes
**
**==========================================================================*/
void PmicCdd_nINTGpioInt(void)
{
  
#if (PMICCDD_PC_CAPTURE_METHOD == PMICCDD_PC_CAPTURE_IRQ_BANKED_LR)
  PmicCdd_nINT_SavedPC = PmicCdd_GetInterruptedPC_BankedLR();
#endif /* PMICCDD_PC_CAPTURE_METHOD == PMICCDD_PC_CAPTURE_IRQ_BANKED_LR */

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntTop))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  else
  {
    PmicCdd_ReadIntTop_Status = TRUE;
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_GetResetReason
**
** Visibility       :   Public
**
** Description      :  This returns the reason for reason of reset
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :  PmicCdd_ResetReasonType - Reset Reason
**                    PmicCdd_PmicWdg_Reset - Pmic Wdg Reset
**                    PmicCdd_PowerOn_Reset - Power On Reset
**
** Critical Section :  yes
**
**==========================================================================*/
PmicCdd_ResetReasonType PmicCdd_GetResetReason(void)
{
  PmicCdd_ResetReasonType flRetVal;

  PmicCdd_EnterCriticalSection();
  flRetVal = PmicCdd_Latched_Reset_Reason;
  PmicCdd_ExitCriticalSection();

  return flRetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_DetermineResetReason
**
** Visibility       :   Static
**
** Description      :   Determines the reset reason captured by the PMIC
**                      initialization status reads. The caller publishes the
**                      returned value only after the initialization queue is empty.
**
** Inputs           :   None
**
** Outputs          :   Captured reset reason
**
** Critical Section :   Caller
**
**==========================================================================*/
static PmicCdd_ResetReasonType PmicCdd_DetermineResetReason(void)
{
  PmicCdd_ResetReasonType flRetVal;

  if (PmicCdd_EnableBit_Status == TRUE)
  {
    flRetVal = PmicCdd_Wakeup; // If enable bit is set, it's a wakeup
  }
  else if (PmicCdd_Reset_Status == TRUE)
  {
    flRetVal = PmicCdd_PmicWdg_Reset; // If reset status is set, it's a watchdog reset
  }
  else if ((PmicCdd_Buck_Reset_Status == TRUE) || (PmicCdd_Ldo_Reset_Status == TRUE))
  {
    flRetVal = PmicCdd_Detailed_Reset_Reason; // If Buck reset status is set, it's a Buck reset
  }
  else if (PmicCdd_PowerSupplyFault_Reset_Status == TRUE)
  {
    // bg_xmon_int, tsd_imm_int, tsd_ord_imm, reg_crc_err_int and twarn_int are categorized as Power Supply Fault Reset
    flRetVal = PmicCdd_Power_Supply_Fault_Reset;
  }
  else if(PmicCdd_AbistFail == TRUE)
  {
    flRetVal = PmicCdd_Abist_Fail_Reset;
  }
  else if(PmicCdd_IntMisc_StartupStatus_Reg.bits.bist_pass_int == 1u)
  {
    flRetVal = PmicCdd_PowerOn_Reset; // Otherwise, it's a power-on reset
  }
  else
  {
    flRetVal = PmicCdd_Mcu_Reset;
  }

  return flRetVal;
}

#if (PMICCDD_ENABLE_WDG == STD_ON)
/*============================================================================
**
** Function Name    :   PmicCdd_GetWdgResetReason
**
** Visibility       :   Public
**
** Description      :  This returns the reason for reason of Wdg reset
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :
**
** Critical Section :  yes
**
**==========================================================================*/
PmicCdd_WdgResetReasonType PmicCdd_GetWdgResetReason(void)
{
  PmicCdd_WdgResetReasonType flRetVal = PmicCdd_WdgReset_Reason_None;

  if(ePmicCdd_FSM_State >= PmicCdd_InitDone)
  {
    if (PmicCdd_WdErrStatusReg_InitRead.value != 0x00u)
    {
      if (PmicCdd_WdErrStatusReg_InitRead.bits.wd_longwin_timeout_int == 1u)
      {
        flRetVal = PmicCdd_WdgLongWin_Timeout;
      }
      else if (PmicCdd_WdErrStatusReg_InitRead.bits.wd_rst_int == 1u)
      {
        if ((PmicCdd_WdErrStatusReg_InitRead.bits.wd_timeout == 1u) && (PmicCdd_WdErrStatusReg_InitRead.bits.wd_trig_early == 0u))
        {
          flRetVal = PmicCdd_WdgTimeout;
        }
        else if ((PmicCdd_WdErrStatusReg_InitRead.bits.wd_timeout == 0u) && (PmicCdd_WdErrStatusReg_InitRead.bits.wd_trig_early == 1u))
        {
          flRetVal = PmicCdd_WdgTrigger_Early;
        }
        else
        {
          /* if wd_rst_int is set to 1, the wd_timeout or wd_trig_early will also be 1 . So double check is not 
          required to check if wd_timeout == 1 && wd_trig_early == 1*/
          flRetVal = PmicCdd_Wdg_Cannot_be_Identified;
        }
      }
      else
      {
        flRetVal = PmicCdd_WdgReset_Reason_None;
      }
    }
  }
  return flRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   PmicCdd_GetPwrSpplyFlt_SubResetReason
**
** Visibility       :   Public
**
** Description      :  This returns the reason for reason of Power Supply Fault reset
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :
**
** Critical Section :  yes
**
**==========================================================================*/
uint8 PmicCdd_GetPwrSpplyFlt_SubResetReason(void)
{
  uint8 SubFaultReason = 0xFFu;

  if (PmicCdd_IntMisc_StartupStatus_Reg.bits.twarn_int == 1u)
  {
    SubFaultReason = PMICCDD_ERROR_TWARN_FAIL;
  }
  else if (PmicCdd_IntSevereErr_StartupStatus_Reg.bits.bg_xmon_int == 1u)
  {
    SubFaultReason = PMICCDD_ERROR_BG_XMON_FAIL;
  }
  else if (PmicCdd_IntSevereErr_StartupStatus_Reg.bits.tsd_imm_int == 1u)
  {
    SubFaultReason = PMICCDD_ERROR_TSD_IMM_FAIL;
  }
  else if (PmicCdd_IntModerate_StartupStatus_Reg.bits.tsd_ord_int == 1u)
  {
    SubFaultReason = PMICCDD_ERROR_TSD_ORD_FAIL;
  }
  else if (PmicCdd_IntModerate_StartupStatus_Reg.bits.reg_crc_err_int == 1u)
  {
    SubFaultReason = PMICCDD_ERROR_CRC_ERR_FAIL;
  }
  else if(PmicCdd_IntMisc_StartupStatus_Reg.bits.bist_pass_int == 1u)
  {
    SubFaultReason = PMICCDD_BIST_PASS;
  }
  else
  {
    SubFaultReason = 0xFFu; // No Sub Fault Reason
  }

  return SubFaultReason;
}

/*============================================================================
**
** Function Name    :   PmicCdd_GetResetCount
**
** Visibility       :   Public
**
** Description      :  This returns the reset count from the PMIC register
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :  E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_GetResetCount(uint8 *PmicReset_Count)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  static PmicCdd_Recov_Cnt_Reg1_t PmicCdd_Recov_Cnt_Reg1 = {0x00u};

  if (PmicReset_Count != NULL_PTR)
  {
    /* Read the recovery count register value */
    PmicCdd_Recov_Cnt_Reg1.value = PmicCdd_Read_RecovCntReg1_RxBuf[0];
    /* Extract the recovery count bits and store directly to output parameter */
    *PmicReset_Count = PmicCdd_Recov_Cnt_Reg1.bits.recov_cnt;
    flRetVal = E_OK;
  }
  return flRetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_ClearResetCount
**
** Visibility       :   Public
**
** Description      :  This function is used to clear Reset Counter
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :  yes
**
**==========================================================================*/
void PmicCdd_ClearResetCount(void)
{
  // Unlocking and locking the registers to write the recovery count clear bit
  PmicCdd_UnlockRegisters();
  PmicCdd_Write_RecovCntReg2_TxBuf[0] = RECOV_CNT_REG_2;
  PmicCdd_Recov_Cnt_Reg2.bits.recov_cnt_thr = PMICCDD_RESET_THRESOLD;
  PmicCdd_Recov_Cnt_Reg2.bits.recov_cnt_clr = 1u;
  PmicCdd_Write_RecovCntReg2_TxBuf[1] = PmicCdd_Recov_Cnt_Reg2.value;

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_RecovCntReg2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  PmicCdd_LockRegisters();
}

/*============================================================================
**
** Function Name    :   PmicCdd_PerformReset
**
** Visibility       :   Public
**
** Description      :  Uses the confirmed PMIC watchdog reset path as the
**                     primary reset mechanism. Returns only when that path
**                     is unavailable or not currently reset-capable.
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   void
**
** Critical Section :  yes
**
**==========================================================================*/
void PmicCdd_PerformReset(void)
{
#if (PMICCDD_ENABLE_WDG == STD_ON)
  uint8 flPmicResetArmed = FALSE;

  PmicCdd_EnterCriticalSection();
  if ((Pmic_WdgPathInitialized != FALSE) &&
      (Pmic_WdgResetCapable != FALSE) &&
      (PmicCdd_WdModeReg.bits.wd_return_longwin == 0U))
  {
    PmicCdd_WdgReset_Request = TRUE;
    Pmic_WdgResetCapable = FALSE;
    Pmic_Feeding = 0u;
    PmicWdgTimeout = 0u;
    Pmic_ResumeKickRequested = 0u;
    Pmic_PhaseAlignReq = 0u;
    Pmic_LastIntervalTicks = 0u;
    if (Pmic_PinHigh != 0u)
    {
      Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);
      Pmic_PinHigh = 0u;
    }
    Pmic_IsrState = PMIC_WDG_IDLE;
    Pmic_GptStop();
    flPmicResetArmed = TRUE;
  }
  PmicCdd_ExitCriticalSection();

  if (flPmicResetArmed != FALSE)
  {
#if (VC_TEST == STD_OFF)
    volatile boolean flWaitForPmicReset = TRUE;

    while (flWaitForPmicReset == TRUE)
    {
      /* PMIC watchdog servicing is disabled; wait for independent reset. */
    }
#endif
  }
#endif
}

#if (PMICCDD_SS_EN == STD_ON)
/*============================================================================
**
** Function Name    :   PmicCdd_EnableSpreadSpectrum
**
** Visibility       :   Public
**
** Description      :  This function is used enable the Spread spsctrum feature
**                      with the default PmicCdd Cfg
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_EnableSpreadSpectrum(void)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  // Unlocking and locking the registers to write the Spread Spectrum enable bit
  PmicCdd_UnlockRegisters();
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_en = (uint8)PmicCdd_SpreadSpectrum_Activated;
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_depth = (uint8)PmicCdd_SpreadSpectrumConfig.PmicCdd_SpreadSpectrum_ModulationDep;
  PmicCdd_SpreadSpectrum_TxBuf[1] = PmicCdd_Spread_Spectrum1_Reg.value;
  flRetVal = E_OK;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_SpreadSpectrum))
  {
    flRetVal = E_NOT_OK;
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  PmicCdd_LockRegisters();
  return flRetVal;
}

/*============================================================================
**
** Function Name    :   PmicCdd_DisableSpreadSpectrum
**
** Visibility       :   Public
**
** Description      :  This function is used disable the Spread spsctrum feature
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_DisableSpreadSpectrum(void)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  // Unlocking and locking the registers to write the Spread Spectrum disable bit
  PmicCdd_UnlockRegisters();
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_en = (uint8)PmicCdd_SpreadSpectrum_Deactivated;
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_depth = (uint8)PmicCdd_SpreadSpectrumConfig.PmicCdd_SpreadSpectrum_ModulationDep;
  PmicCdd_SpreadSpectrum_TxBuf[1] = PmicCdd_Spread_Spectrum1_Reg.value;
  flRetVal = E_OK;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_SpreadSpectrum))
  {
    flRetVal = E_NOT_OK;
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  PmicCdd_LockRegisters();
  return flRetVal;
}
/*============================================================================
**
** Function Name    :   PmicCdd_SetSpreadSpectrum_Depth
**
** Visibility       :   Public
**
** Description      :  This function is used set/change the Spread Spectrum depth
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
Std_ReturnType PmicCdd_SetSpreadSpectrum_Depth(PmicCdd_SpreadSpectrum_ModulationDepType SS_Depth)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  // Unlocking and locking the registers to write the Spread Spectrum depth
  PmicCdd_UnlockRegisters();
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_en = (uint8)PmicCdd_SpreadSpectrum_Activated;
  PmicCdd_Spread_Spectrum1_Reg.bits.ss_depth = (uint8)SS_Depth;
  PmicCdd_SpreadSpectrum_TxBuf[1] = PmicCdd_Spread_Spectrum1_Reg.value;
  flRetVal = E_OK;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_SpreadSpectrum))
  {
    flRetVal = E_NOT_OK;
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  PmicCdd_LockRegisters();
  return flRetVal;
}
#endif

/*============================================================================
**                          Local Functions
**==========================================================================*/

/*============================================================================
**
** Function Name    :   PmicCdd_Push_BistPass
**
** Visibility       :   Static (Internal)
**
** Description      :   Push PowerOnConfig I2C sequence to queue after successful BIST.
**                      Initiates first watchdog mode configuration during initialization.
**
** Invocation       :   MainFunction (Init phase)
**
** Inputs           :   None (uses global I2C sequence queue)
**
** Outputs          :   Pushes sequence to queue; reports error if push fails
**
** Critical Section :   No (queue push has internal protection)
**
**==========================================================================*/
static void PmicCdd_Push_BistPass(void)
{
  // Push Sequence

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_PowerOnConfig))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

#ifdef TEST_RW
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_TestwdgRead))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif

  // GPIO2 - Setting GPIO2 as TRIGGER
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_read_WdErrStatus))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_write_WdErrStatus))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#if (PMICCDD_ENABLE_WDG == STD_ON)
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_LongWindowCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdWin1Cfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdWin2Cfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdThrCfgRead))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdThrCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_WdMode))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  PmicCdd_Push_PmicDeviceInfo();
  PmicCdd_Push_SeqAfterCrc();

#if (PMICCDD_ENABLE_ESM == STD_ON)
  /* ESM Configuration */
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmDelay1Cfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmDelay2Cfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmModeCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmHmaxCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmHminCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmLmaxCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmLminCfg))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_EsmStart))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif
  // Lock the registers after initialization
  PmicCdd_LockRegisters();
}

/*============================================================================
**
** Function Name    :   PmicCdd_Push_SeqAfterCrc
**
** Visibility       :   Static (Internal)
**
** Description      :   Push GPIO and device configuration sequences after CRC init.
**                      Called after CRC engine is enabled; configures GPIO1, GPIO3, and PMIC device info.
**
** Invocation       :   MainFunction (Init phase, after CRC validation)
**
** Inputs           :   None (uses global I2C sequence queue)
**
** Outputs          :   Pushes GPIO and device-info sequences to queue; reports error if push fails
**
** Critical Section :   No (queue push has internal protection)
**
**==========================================================================*/
static void PmicCdd_Push_SeqAfterCrc(void)
{
  // GPIO Configuration
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio1))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio3))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio4))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio5))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Gpio6))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
  PmicCdd_InitBuckLdoVccaVmon_Push();
#endif
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_MaskStartup))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_MaskStartup))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_RecovCntReg1))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_RecovCntReg2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_RecovCntReg2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

#if (PMICCDD_SS_EN == STD_ON)
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_SpreadSpectrum))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif
}

/*============================================================================
**
** Function Name    :   PmicCdd_Push_PmicDeviceInfo
**
** Visibility       :   Static (Internal)
**
** Description      :   Push device revision and NVM code read sequences to queue.
**                      Reads PMIC device ID, revision, and NVM codes for identification/diagnostics.
**
** Invocation       :   MainFunction (Init phase, after GPIO config)
**
** Inputs           :   None (prepares device info read sequences)
**
** Outputs          :   Pushes DevRev, NvmCode1, NvmCode2 read sequences to queue
**
** Critical Section :   No (queue push has internal protection)
**
**==========================================================================*/
static void PmicCdd_Push_PmicDeviceInfo(void)
{
  PmicCdd_DevRev_Reg_TxBuf[0] = (uint8)DEV_REV_REG;
  PmicCdd_NvmCode1_Reg_TxBuf[0] = (uint8)NVM_CODE_1_REG;
  PmicCdd_NvmCode2_Reg_TxBuf[0] = (uint8)NVM_CODE_2_REG;

  /* Push sequences to read PMIC device identification and NVM version */
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_DevRev))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_NvmCode1))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_NvmCode2))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

}

#if (PMICCDD_ENABLE_WDG == STD_ON)
/*============================================================================
**
** Function Name    :   Pmic_ComputeDelayToWin2_ms
**
** Visibility       :   static
**
** Description      :   Pmic_ComputeDelayToWin2_ms
**
** Invocation       :   Local
**
** Inputs           :
**
** Outputs          :
**
**
** Critical Section :
**
**==========================================================================*/

/* Custom recovery policy:
 *   - If inside WIN2 → service immediately
 *   - If inside WIN1 → wait (remaining WIN1) + (WIN2 / 4)
 */
static uint32 Pmic_ComputeDelayToWin2_ms(uint32 now32)
{
  uint32 flRetVal = 0u;

  if (Pmic_GtcValid != 0u)
  {
    /* === Convert configured enum to nominal ms values === */
    const uint32 win1_us_min = PMIC_GET_TWINDOW_MIN_US(PmicCdd_WdgConf.ePmicCdd_Win1_Time);
    const uint32 win1_us_max = PMIC_GET_TWINDOW_MAX_US(PmicCdd_WdgConf.ePmicCdd_Win1_Time);
    const uint32 win2_us_min = PMIC_GET_TWINDOW_MIN_US(PmicCdd_WdgConf.ePmicCdd_Win2_Time);
    const uint32 win2_us_max = PMIC_GET_TWINDOW_MAX_US(PmicCdd_WdgConf.ePmicCdd_Win2_Time);

    /* Use the average (nominal) window duration */
    const uint32 win1_ms = ((win1_us_min + win1_us_max) / 2u) / 1000u;
    const uint32 win2_ms = ((win2_us_min + win2_us_max) / 2u) / 1000u;

    const uint32 win1_ticks = win1_ms * PMIC_GTC_TICKS_PER_MS;
    const uint32 win2_ticks = win2_ms * PMIC_GTC_TICKS_PER_MS;
    const uint32 period_ticks = win1_ticks + win2_ticks;
    const uint32 margin_ticks = PMIC_PHASE_MARGIN_MS * PMIC_GTC_TICKS_PER_MS;

    /* === Phase model (SLVSGG7 6.3.10.5 / 6.3.10.6) ===
     * The PMIC latches the trigger at the RISING EDGE + tWD_pulse deglitch
     * (24/30/36 us, SLVSGG7 p.33) and restarts the sequence there - NOT at the end
     * of our PMIC_PULSE_MS pulse. So Pmic_LastRiseGtc32 IS the sequence origin and
     * nothing is subtracted from the elapsed time; the deglitch is ~6,000 of
     * ~20,000,000 ticks. (An earlier version subtracted the pulse width here, which
     * biased the estimate ~5 ms early and let CASE 1 fire into the next WIN1.)
     *
     * While feeding is stopped the PMIC free-runs one sequence per WIN1+WIN2 (each
     * timeout is a bad event), so phase = elapsed % (WIN1+WIN2).
     */
    const uint32 phase = (period_ticks == 0u)
                           ? 0u
                           : ((uint32)(now32 - Pmic_LastRiseGtc32) % period_ticks);

    /* Bounds that hold at BOTH oscillator corners (+-5%). The nominal window cannot be
     * trusted near an edge: WIN2 has certainly started only after WIN1_MAX, and has
     * certainly not ended before WIN1_MIN + WIN2_MIN. */
    const uint32 safe_win2_start = (win1_us_max * PMIC_GTC_TICKS_PER_US) + margin_ticks;
    const uint32 safe_win2_end = ((win1_us_min + win2_us_min) * PMIC_GTC_TICKS_PER_US) - margin_ticks;
    /* Same construction as PMIC_CALC_GPT_RELOAD_MS: 1/4 into the guaranteed WIN2 */
    const uint32 target_ticks = (win1_us_max + (win2_us_min / 4u)) * PMIC_GTC_TICKS_PER_US;

    uint32 delay_ticks;

    /* CASE 1: provably inside WIN2 at either corner -> service immediately */
    if ((phase >= safe_win2_start) && (phase <= safe_win2_end))
    {
      delay_ticks = 0u;
    }
    /* CASE 2: not yet at the guaranteed WIN2 -> wait to this period's 1/4 point */
    else if (phase < target_ticks)
    {
      delay_ticks = target_ticks - phase;
    }
    /* CASE 3: past the safe part of WIN2 (this sequence may already have timed out)
     *         -> skip to the next period's 1/4 point rather than risk its WIN1 */
    else
    {
      delay_ticks = (period_ticks - phase) + target_ticks;
    }

    /* Convert ticks → ms (ceil) */
    flRetVal = (delay_ticks + (PMIC_GTC_TICKS_PER_MS - 1u)) / PMIC_GTC_TICKS_PER_MS;
  }

  return flRetVal; /* milliseconds */
}

#endif

/**
 * @brief Pushes an I2C sequence number into the sequence queue.
 *
 * @param PushSeqNum The sequence number to be pushed into the queue.
 * @return Std_ReturnType E_OK if the sequence was successfully pushed, E_NOT_OK if the queue is full.
 */
static Std_ReturnType PmicCdd_I2cPushSequence(ePmicCdd_I2cSeqQIDType PushSeqNum)
{
  Std_ReturnType flRetVal = E_NOT_OK;
  ePmicCdd_I2cSeqQIDType flNextSeq = (ePmicCdd_I2cSeqQIDType)0;
  uint8 flStartNow = 0U;

  PmicCdd_EnterCriticalSection();

  if (PmicCdd_QueueFull == FALSE)
  {
    /* Enqueue */
    PmicCdd_I2c_SequenceQueue[PmicCdd_QueueTail] = (uint8)PushSeqNum;
    PmicCdd_QueueTail = (uint8)((PmicCdd_QueueTail + 1U) % (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE);

    if (PmicCdd_QueueTail == PmicCdd_QueueHead)
    {
      PmicCdd_QueueFull = TRUE;
    }

    /* Normalize FSM */
    if ((ePmicCdd_FSM_State == PmicCdd_InitDone) || (ePmicCdd_FSM_State == PmicCdd_MainProcess_SeqDone))
    {
      ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;
    }

    /* Auto-start: inline pop (no nested critical section) */
    if (ePmicCdd_FSM_State == PmicCdd_MainProcess_Idle)
    {
      #if (VC_TEST == STD_OFF)
      if ((PmicCdd_QueueHead != PmicCdd_QueueTail) || (PmicCdd_QueueFull == TRUE))
      {
        flNextSeq = (ePmicCdd_I2cSeqQIDType)PmicCdd_I2c_SequenceQueue[PmicCdd_QueueHead];
        PmicCdd_QueueHead = (uint8)((PmicCdd_QueueHead + 1U) % (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE);
        PmicCdd_QueueFull = FALSE;

        ePmicCdd_FSM_State = PmicCdd_MainProcess_SeqProgress;
        flStartNow = 1U;
      }
      #else
      flStartNow = 1U; // Added to cover the UT
      #endif
    }

    flRetVal = E_OK;
  }

  PmicCdd_ExitCriticalSection();

  if (flStartNow == 1U)
  {
    if (E_OK != PmicCdd_I2CASyncTransmit(flNextSeq))
    {
      PmicCdd_Det_ReportError(PMICCDD_MAIN_FUNCTION, PMICCDD_ERROR_I2C_ASYN_TRANSMIT_FAILED);

      PmicCdd_EnterCriticalSection();
      ePmicCdd_FSM_State = PmicCdd_MainProcess_Idle;
      PmicCdd_ExitCriticalSection();
    }
  }

  return flRetVal;
}

/**
 * @brief Pops the next I2C sequence from the queue.
 *
 * This function retrieves the next I2C sequence from the queue and updates the queue head pointer.
 * If the queue is empty, the function returns E_NOT_OK.
 *
 * @param[out] PopSeqNum Pointer to store the popped sequence number.
 * @return Std_ReturnType E_OK if a sequence was successfully popped, E_NOT_OK otherwise.
 */
static Std_ReturnType PmicCdd_I2cPopSequence(ePmicCdd_I2cSeqQIDType *PopSeqNum)
{
  Std_ReturnType ret = E_NOT_OK;

  if (PopSeqNum != NULL_PTR)
  {
    PmicCdd_EnterCriticalSection();
    if (PmicCdd_I2cQueueIsEmpty() == FALSE)
    {
      *PopSeqNum = (ePmicCdd_I2cSeqQIDType)PmicCdd_I2c_SequenceQueue[PmicCdd_QueueHead];
      PmicCdd_QueueHead = (uint8)((PmicCdd_QueueHead + 1U) % (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE);
      PmicCdd_QueueFull = FALSE;
      ret = E_OK;
    }
    PmicCdd_ExitCriticalSection(); /* Always exit critical section */
  }

  return ret; /* Single return - KW compliant */
}

/**
 * Clears the I2C sequence queue used by the PMIC CDD.
 *
 * This function iterates through the I2C sequence queue and sets each entry to a known value (0xAA).
 * This is typically done to reset the queue to a known state.
 */
static void PmicCdd_I2cSequence_QueueClear(void)
{
  uint8 flIndex = 0u;

  PmicCdd_EnterCriticalSection();
  for (flIndex = 0; flIndex < (uint8)PMICCDD_MAX_I2C_SEQUENCE_QUEUE; flIndex++)
  {
    PmicCdd_I2c_SequenceQueue[flIndex] = 0xAAU;
  }
  PmicCdd_QueueHead = 0U;
  PmicCdd_QueueTail = 0U;
  PmicCdd_QueueFull = FALSE;
  PmicCdd_ExitCriticalSection();
}

static boolean PmicCdd_I2cQueueIsEmpty(void)
{
  return ((PmicCdd_QueueHead == PmicCdd_QueueTail) && (PmicCdd_QueueFull == FALSE)) ? TRUE : FALSE;
}

/* Internal Call backs */

/*============================================================================
**
** Function Name    :   PmicCdd_CBStartWdgGpt
**
** Visibility       :   Static (Callback)
**
** Description      :   I2C end callback: Exit Long Window and start watchdog feed timer.
**                      Called when WdgMode write completes (end of PmicCdd_Init).
**                      Initiates GPT timer for watchdog pulse generation.
**
** Invocation       :   I2C EndNotification callback (async context)
**
** Inputs           :   None (uses global WdMode register and Pmic globals)
**
** Outputs          :   Starts GPT timer; sets initial ISM state to LOW_GAP
**
** Critical Section :   No - runs at I2C callback level; GPT/pin access serialized by callback context
**
**==========================================================================*/
static void PmicCdd_CBStartWdgGpt(void)
{
#if (PMICCDD_ENABLE_WDG == STD_ON)
  PmicCdd_WdThrCfgReg_t flWdThrCfgReg = {0U};

  flWdThrCfgReg.value = PmicCdd_WdThrCfgReg_TxBuf[1];
#endif
  if (PmicCdd_WdModeReg.bits.wd_return_longwin != 1U)
  {
#if (PMICCDD_ENABLE_WDG == STD_ON)
    /* Exiting Long Window: anchor our phase now */
    Dio_WriteChannel(PmicCdd_WdgConf.Dio_WdgTriggerPin, STD_LOW);
    Pmic_PinHigh = 0u;
    Pmic_IsrState = PMIC_WDG_LOW_GAP; /* next ISR will consider a service */
    Pmic_Feeding = 0u;                /* stays disabled until WdgM says OK */
    Pmic_LastIntervalTicks = 0u;
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_Gpt_ExtWdg_Win);
    Pmic_GptStart(Pmic_GptTimerTickValue);
#else
// do nothing
#endif
  }
  else
  {
#if (PMICCDD_ENABLE_WDG == STD_ON)
    Pmic_GptStop();
    Pmic_IsrState = PMIC_WDG_IDLE;
    Pmic_Feeding = 0u;
#endif
  }
#if (PMICCDD_ENABLE_WDG == STD_ON)
  /* A completed WdMode write confirms the current mode. Long-window mode is
   * initialized but is not accepted as a bounded short-window reset path. */
  Pmic_WdgPathInitialized = TRUE;
  Pmic_WdgResetCapable = ((PmicCdd_WdgReset_Request == FALSE) &&
                          (PmicCdd_WdModeReg.bits.wd_return_longwin == 0U) &&
                          (flWdThrCfgReg.bits.wd_en != 0U) &&
                          (flWdThrCfgReg.bits.wd_rst_en != 0U)) ? TRUE : FALSE;
#endif
}

#if (PMICCDD_ENABLE_ADC == STD_ON)
static void PmicCdd_CBReadAdcResults(void)
{
  if (PmicCdd_Adc_FSM_State == PmicCdd_ADC_Read_Result)
  {
    PmicCdd_Adc_ResultBuffer = 0;
    PmicCdd_Adc_ResultBuffer = PmicCdd_Adc_ResultReg_RxBuf[0]; // 11 - 4 bits of ADC Result
    PmicCdd_Adc_ResultBuffer <<= 4;
    PmicCdd_Adc_ResultBuffer |= (PmicCdd_Adc_ResultReg1_RxBuf[0] >> 4); // 3 -0 bits of ADC

    if (PmicCdd_Adc_GroupNotification != FALSE)
    {
      PMICCDD_CONV_COMPLETED_CB();
    }
    PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Idle;
    PmicCdd_Adc_Request_state = PMIC_ADC_CONVERSION_REQUEST_STOP;
    PmicCdd_AdcStartConv_Pending = 0U;
  }
  else
  {
    PmicCdd_Adc_ResultBuffer = 0xFFFFU;
  }
}

static void PmicCdd_CBAdcConvStarted(void)
{
  PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Started;
}

static void PmicCdd_CBReadAdcStatus(void)
{
  PmicCdd_AdCtrl_Reg.value = PmicCdd_Adc_CtrlReg_RxBuf[0];
  PmicCdd_Adc_Result_Status = E_NOT_OK;
  if (PmicCdd_AdCtrl_Reg.bits.adc_status == 0U)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_AdcResult))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }

    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_AdcResult1))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
    PmicCdd_Adc_Result_Status = E_OK;
    PmicCdd_Adc_FSM_State = PmicCdd_ADC_Read_Result;
  }
}
#endif

/* Error interrupt callbacks */

/*============================================================================
**
** Function Name    :   PmicCdd_CBReadIntTop
**
** Visibility       :   Static (Callback)
**
** Description      :   I2C end callback: Read INT_TOP register and cascade-push detail interrupt reads.
**                      Decodes top-level interrupt register to identify which error registers need reading.
**                      Pushes follow-up I2C sequences for each detected error type.
**
** Invocation       :   I2C EndNotification callback (async context)
**
** Inputs           :   INT_TOP register value in PmicCdd_IntTop_RxBuf[0]
**
** Outputs          :   Pushes INT_FSM, INT_SEVERE, INT_MODERATE, INT_MISC, INT_STARTUP, INT_GPIO, INT_LDO, INT_BUCK reads
**
** Critical Section :   No (called within I2C callback; uses critical section internally)
**
**==========================================================================*/
static void PmicCdd_CBReadIntTop(void)
{

  static PmicCdd_IntTop_Reg_t PmicCdd_IntTop_Reg = {0x00u};

  PmicCdd_IntTop_Reg.value = PmicCdd_IntTop_RxBuf[0];
  if (PmicCdd_IntTop_Reg.bits.fsm_err_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntFsmError))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.severe_err_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntSevereError))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.moderate_err_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntModerateError))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.misc_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntMisc))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.startup_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntStartup))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.gpio_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntGpio))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.ldo_vmon_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntLdoVmon))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  if (PmicCdd_IntTop_Reg.bits.buck_int != FALSE)
  {
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntBuck))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }

  PmicCdd_EnterCriticalSection();
  PmicCdd_ReadIntTop_Status = FALSE;
  PmicCdd_ExitCriticalSection();
  
}

static void PmicCdd_CBReadIntBuck(void)
{
  PmicCdd_IntBuck_Reg.value = PmicCdd_IntBuck_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntBuck_Reg.value != 0x00u)
  {
    PmicCdd_Buck_Reset_Status = TRUE;
  }

  if (PmicCdd_IntBuck_Reg.bits.buck1_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BUCK1_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_BUCK1_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Buck1_UVOV_Reset;
    flMask |= PMICCDD_BUCK1UVOV_INT_MASK;
  }
  if (PmicCdd_IntBuck_Reg.bits.buck2_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BUCK2_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_BUCK2_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Buck2_UVOV_Reset;
    flMask |= PMICCDD_BUCK2UVOV_INT_MASK;
  }
  if (PmicCdd_IntBuck_Reg.bits.buck3_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BUCK3_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_BUCK3_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Buck3_UVOV_Reset;
    flMask |= PMICCDD_BUCK3UVOV_INT_MASK;
  }
  if (PmicCdd_IntBuck_Reg.bits.buck4_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BUCK4_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_BUCK4_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Buck4_UVOV_Reset;
    flMask |= PMICCDD_BUCK4UVOV_INT_MASK;
  }

  PmicCdd_ClearBuckInt(flMask);
}

static void PmicCdd_CBReadIntLdoVmon(void)
{
  PmicCdd_IntLdoVmon_Reg.value = PmicCdd_IntLdoVmon_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntLdoVmon_Reg.value != 0x00u)
  {
    PmicCdd_Ldo_Reset_Status = TRUE;
  }

  if (PmicCdd_IntLdoVmon_Reg.bits.ldo1_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_LDO1_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_LDO1_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Ldo1_UVOV_Reset;
    flMask |= PMICCDD_LDO1UVOV_INT_MASK;
  }
  if (PmicCdd_IntLdoVmon_Reg.bits.ldo2_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_LDO2_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_LDO2_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Ldo2_UVOV_Reset;
    flMask |= PMICCDD_LDO2UVOV_INT_MASK;
  }
  if (PmicCdd_IntLdoVmon_Reg.bits.ldo3_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_LDO3_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_LDO3_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Ldo3_UVOV_Reset;
    flMask |= PMICCDD_LDO3UVOV_INT_MASK;
  }
  if (PmicCdd_IntLdoVmon_Reg.bits.vcca_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_VCCA_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_VCCA_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Vcca_UVOV_Reset;
    flMask |= PMICCDD_VCCAUVOV_INT_MASK;
  }
  if (PmicCdd_IntLdoVmon_Reg.bits.vmon1_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_VMON1_UVOV;
      PmicCdd_Callout_SMError_Report(PMICCDD_OVUV_MONITOR, PMICCDD_VMON1_OVUV_FAIL);
    PmicCdd_Detailed_Reset_Reason = PmicCdd_Vmon1_UVOV_Reset;
    flMask |= PMICCDD_VMON1UVOV_INT_MASK;
  }
  if (PmicCdd_IntLdoVmon_Reg.bits.vmon2_uvov_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_VMON2_UVOV;
    flMask |= PMICCDD_VMON2UVOV_INT_MASK;
  }

  PmicCdd_ClearLdoVmonInt(flMask);
}

static void PmicCdd_CBReadIntGpio(void)
{
  PmicCdd_IntGpio_Reg.value = PmicCdd_IntGpio_RxBuf[0];
  uint8 flMask = 0x00u;

    if(PmicCdd_IntGpio_Reg.bits.gpio1_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO1;
        flMask |= PMICCDD_GPIO1_INT_MASK;
    }
    if(PmicCdd_IntGpio_Reg.bits.gpio2_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO2;
        flMask |= PMICCDD_GPIO2_INT_MASK;
    }
    if(PmicCdd_IntGpio_Reg.bits.gpio3_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO3;
        flMask |= PMICCDD_GPIO3_INT_MASK;
    }
    if(PmicCdd_IntGpio_Reg.bits.gpio4_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO4;
        flMask |= PMICCDD_GPIO4_INT_MASK;
    }
    if(PmicCdd_IntGpio_Reg.bits.gpio5_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO5;
        flMask |= PMICCDD_GPIO5_INT_MASK;
    }
    if(PmicCdd_IntGpio_Reg.bits.gpio6_int != FALSE)
    {
        PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_GPIO6;
        flMask |= PMICCDD_GPIO6_INT_MASK;
    }

  PmicCdd_ClearGpioInt(flMask);
}

static void PmicCdd_CBReadIntStartup(void)
{
  PmicCdd_IntStartup_Reg.value = PmicCdd_IntStartup_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntStartup_Reg.bits.vsense_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_VSENSE;
    flMask |= PMICCDD_VSENSE_INT_MASK;
  }
  if (PmicCdd_IntStartup_Reg.bits.soft_reboot_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_SOFT_REBOOT;
    flMask |= PMICCDD_SOFTREBOOT_INT_MASK;
  }
  if (PmicCdd_IntStartup_Reg.bits.pb_short_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_PB_SHORT;
    flMask |= PMICCDD_PB_SHORT_INT_MASK;
  }
  if (PmicCdd_IntStartup_Reg.bits.fsd_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_FSD;
    flMask |= PMICCDD_FSD_INT_MASK;
  }
  if (PmicCdd_IntStartup_Reg.bits.enable_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ENABLE;
    PmicCdd_EnableBit_Status = TRUE;
    flMask |= PMICCDD_ENABLE_INT_MASK;
  }

  if (PmicCdd_EnableBit_Status == TRUE)
  {
    PMICCDD_CHECK_WAKEUP();
  }

  PmicCdd_ClearStartupInt(flMask);
}

static void PmicCdd_CBReadIntMisc(void)
{
  PmicCdd_IntMisc_Reg.value = PmicCdd_IntMisc_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntMisc_Reg.bits.bist_pass_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BIST_PASS;
    PmicCdd_IntMisc_StartupStatus_Reg.value = PmicCdd_IntMisc_RxBuf[0];
    flMask |= PMICCDD_BISTPASS_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.ext_clk_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_EXT_CLK;
    flMask |= PMICCDD_EXTCLK_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.reg_unlock_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_REG_UNLOCK;
    flMask |= PMICCDD_REGUNLOCK_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.twarn_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_TWARN;
    PmicCdd_PowerSupplyFault_Reset_Status = TRUE;
    flMask |= PMICCDD_TWARN_INT_MASK;
    /* The Twarn_int is reported before once it reached the TWARN_LEVEL, So
     reporting it to Fltm */
    PmicCdd_IntMisc_StartupStatus_Reg.value = PmicCdd_IntMisc_RxBuf[0];
    PmicCdd_Callout_SMError_Report(PMICCDD_INIT, PMICCDD_ERROR_TWARN_FAIL);
  }
  if (PmicCdd_IntMisc_Reg.bits.pb_long_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_PB_LONG;
    flMask |= PMICCDD_PBLONG_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.pb_fall_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_PB_FALL;
    flMask |= PMICCDD_PBFALL_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.pb_rise_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_PB_RISE;
    flMask |= PMICCDD_PBRISE_INT_MASK;
  }
  if (PmicCdd_IntMisc_Reg.bits.adc_conv_ready_int != FALSE)
  {
    flMask |= PMICCDD_ADCCONVREADY_INT_MASK;
#if (PMICCDD_ENABLE_ADC == STD_ON)
    if (PmicCdd_Adc_FSM_State == PmicCdd_ADC_Conv_Started)
    {
      PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Done;
      if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_AdcCtrl))
      {
        PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
      }
    }
#endif
  }

  PmicCdd_ClearMiscInt(flMask);
}

static void PmicCdd_CBReadIntModerateError(void)
{
  PmicCdd_IntModerate_Reg.value = PmicCdd_IntModerateError_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntModerate_Reg.bits.tsd_ord_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_TSD_ORD;
    flMask |= PMICCDD_TSDORD_INT_MASK;
    PmicCdd_PowerSupplyFault_Reset_Status = TRUE;
    PmicCdd_IntModerate_StartupStatus_Reg.value = PmicCdd_IntModerateError_RxBuf[0];
    /*If the die temperature reaches Tsd_ordely, then Orderly shutdown is taken from PMIC.
    So No need to log it. It is handled in DltExt */
  }
  if (PmicCdd_IntModerate_Reg.bits.bist_fail_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BIST_FAIL;
    PmicCdd_AbistFail = TRUE;
    flMask |= PMICCDD_BISTFAIL_INT_MASK;
  }
  if (PmicCdd_IntModerate_Reg.bits.reg_crc_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_REG_CRC_ERR;
    flMask |= PMICCDD_REGCRCERR_INT_MASK;
    /* If the CRC for static registers, user registers and SRAM fails, recovery action is
    taken by the PMIC. No need to log it, It is taken care in DltExt  */
    PmicCdd_PowerSupplyFault_Reset_Status = TRUE;
    PmicCdd_IntModerate_StartupStatus_Reg.value = PmicCdd_IntModerateError_RxBuf[0];
  }
  if (PmicCdd_IntModerate_Reg.bits.recov_cnt_int != FALSE)
  {
    flMask |= PMICCDD_RECOVCNT_INT_MASK;
     /* If the recovery count reaches the threshold, it means the PMIC has taken multiple recovery actions for certain faults. We log this event to monitor the health of the PMIC and take necessary actions if it happens frequently. */
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_RECOV_CNT;
  }
  PmicCdd_ClearModerateErrorInt(flMask);
}

static void PmicCdd_CBReadIntSevereError(void)
{
  PmicCdd_IntSevereErr_Reg.value = PmicCdd_IntSevereError_RxBuf[0];
  uint8 flMask = 0x00u;

  if (PmicCdd_IntSevereErr_Reg.bits.tsd_imm_int != FALSE)
  {
    /* If the die temperature reached Tsd_imm, then Immediate shutdown is taken from PMIC.
    No need to log it. It is taken care in DltExt */
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_TSD_IMM;
    flMask |= PMICCDD_TSDIMM_INT_MASK;
    PmicCdd_PowerSupplyFault_Reset_Status = TRUE;
    PmicCdd_IntSevereErr_StartupStatus_Reg.value = PmicCdd_IntSevereError_RxBuf[0];
  }
  if (PmicCdd_IntSevereErr_Reg.bits.vcca_ovp_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_VCCA_OVP;
    flMask |= PMICCDD_VCCAOVP_INT_MASK;
  }
  if (PmicCdd_IntSevereErr_Reg.bits.pfsm_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_PFSM_ERR;
    flMask |= PMICCDD_PFSMERR_INT_MASK;
  }
  if (PmicCdd_IntSevereErr_Reg.bits.bg_xmon_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_BG_XMON;
    flMask |= PMICCDD_BGXMON_INT_MASK;
    PmicCdd_PowerSupplyFault_Reset_Status = TRUE;
    /* As recovery action is taken by the PMIC itself, No need to log it is taken care in DltExt*/
    PmicCdd_IntSevereErr_StartupStatus_Reg.value = PmicCdd_IntSevereError_RxBuf[0];
  }
  PmicCdd_ClearSevereErrorInt(flMask);
}

static void PmicCdd_CBReadIntFsmError(void)
{
  uint8 flMask = 0x00u;
  PmicCdd_IntFsmErr_Reg.value = PmicCdd_IntFsmError_RxBuf[0];
  PmicCdd_IntFsmError_TxBuf[1] = PmicCdd_IntFsmError_RxBuf[0];

  if (PmicCdd_IntFsmErr_Reg.bits.imm_shutdown_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_IMM_SHUTDOWN;
    flMask |= PMICCDD_IMMSHUTDOWN_INT_MASK;
  }
  if (PmicCdd_IntFsmErr_Reg.bits.ord_shutdown_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ORD_SHUTDOWN;
    flMask |= PMICCDD_ORDSHUTDOWN_INT_MASK;
  }
  if (PmicCdd_IntFsmErr_Reg.bits.mcu_pwr_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_MCU_PWR_ERR;
    flMask |= PMICCDD_MCUPWRERR_INT_MASK;
  }
  if (PmicCdd_IntFsmErr_Reg.bits.soc_pwr_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_SOC_PWR_ERR;
    flMask |= PMICCDD_SOCPWRERR_INT_MASK;
  }
  if (PmicCdd_IntFsmErr_Reg.bits.comm_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_COMM_ERR;
    flMask |= PMICCDD_COMMERR_INT_MASK;

    PmicCdd_TxCrcErrorFlag = TRUE;
    PmicCdd_TransmitCRCError_Count++;

    if (PmicCdd_TransmitCRCError_Count == PMICCDD_I2C_CRC_RETRYCOUNT)
    {
      PmicCdd_Callout_SMError_Report(PMICCDD_INIT, PMICCDD_ERROR_I2C_TRANSMIT_REG_UNLOCK_CRC_FAILED);
    }
  }
  else
  {
    if (PmicCdd_TransmitCRCError_Count > 0U)
    {
      PmicCdd_TransmitCRCError_Count = 0U;
    }
  }
  if (PmicCdd_IntFsmErr_Reg.bits.i2c2_err_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_I2C2_ERR;
    flMask |= PMICCDD_I2C2ERR_INT_MASK;
  }
  if (PmicCdd_IntFsmErr_Reg.bits.esm_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ESM;
    flMask |= PMICCDD_ESM_INT_MASK;
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Read_IntEsm))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }
  if (PmicCdd_IntFsmErr_Reg.bits.wd_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD;
    flMask |= PMICCDD_WD_INT_MASK;
    if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_read_WdErrStatus))
    {
      PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
    }
  }
  PmicCdd_ClearFsmErrorInt(flMask);
}

static void PmicCdd_CBReadIntEsm(void)
{
  uint8 flMask = 0x00u;
  PmicCdd_IntEsm_Reg.value = PmicCdd_IntEsm_RxBuf[0];
  if (PmicCdd_IntEsm_Reg.bits.esm_mcu_pin_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ESM_MCU_PIN;
    flMask |= PMICCDD_ESMMCUPIN_INT_MASK;
  }
  if (PmicCdd_IntEsm_Reg.bits.esm_mcu_fail_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ESM_MCU_FAIL;
    flMask |= PMICCDD_ESMMCUFAIL_INT_MASK;
  }
  if (PmicCdd_IntEsm_Reg.bits.esm_mcu_rst_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_ESM_MCU_RST;
    flMask |= PMICCDD_ESMMCURST_INT_MASK;
  }
  PmicCdd_ClearEsmInt(flMask);
}

static void PmicCdd_CBReadWdErrStatus(void)
{
  uint8 flMask = 0x00u;
  PmicCdd_WdErrStatusReg.value = PmicCdd_WdErrStatusReg_RxBuf[0];

  if (PmicCdd_WdErrStatusReg.bits.wd_longwin_timeout_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_LONGWIN_TIMEOUT;
    flMask |= PMICCDD_LONGWINTIMEOUT_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_timeout != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_TIMEOUT;
    flMask |= PMICCDD_WDTIMEOUT_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_trig_early != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_TRIG_EARLY;
    flMask |= PMICCDD_WDTRIGEARLY_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_answ_early != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_ANSW_ERR;
    flMask |= PMICCDD_WDANSWERR_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_seq_err != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_SEQ_ERR;
    flMask |= PMICCDD_WDSEQERR_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_answ_err != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_ANSW_ERR;
    flMask |= PMICCDD_WDANSWERR_INT_MASK;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_fail_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_FAIL_INT;
    flMask |= PMICCDD_WDFAIL_INT_MASK;
    PmicCdd_PmicWdg_FailInt_Status = TRUE;
  }
  if (PmicCdd_WdErrStatusReg.bits.wd_rst_int != FALSE)
  {
    PmicCdd_ReportErrorStatus |= (uint64)PMIC_INT_WD_RST_INT;
    flMask |= PMICCDD_WDRST_INT_MASK;
  }

  if ((PmicCdd_WdErrStatusReg.value != 0x00U) && (ePmicCdd_FSM_State == PmicCdd_InitProgress))
  {
    PmicCdd_Reset_Status = TRUE;
    /* Store initial state specifically for reset reason calculation */
    PmicCdd_WdErrStatusReg_InitRead.value = PmicCdd_WdErrStatusReg_RxBuf[0];
    PMICCDD_CHECK_WAKEUP();
  }

  if ((PmicCdd_PmicWdg_FailInt_Status == TRUE) && (ePmicCdd_FSM_State != PmicCdd_InitProgress))
  {
    // Logging the reset data in the memory in case of SW hang
    PmicCdd_Log_FailIntWrite();
  }

  PmicCdd_ClearWdgErrStatusInt(flMask);
}

static void PmicCdd_Log_FailIntWrite(void)
{
#if (PMICCDD_ENABLE_WDG == STD_ON)
  PmicCddWdgEarlyWarning SWHangDumpLog;
  if (PmicCdd_WdgReset_Request == FALSE)
  {
    SWHangDumpLog.FaultId = PMICCDD_FLTM_SW_HANG;
    SWHangDumpLog.pc = PmicCdd_nINT_SavedPC;
    SWHangDumpLog.rev = 0x00U;
    PmicCdd_Callout_WdgEarlyWarning(&SWHangDumpLog, 6U);
    PmicCdd_DumpLog_Status = TRUE;
  }
#endif
}

static void PmicCdd_ReadFailCnt(void)
{
  PmicCdd_FailCnt_TxBuf[0] = WD_FAIL_CNT_REG;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_FailCnt))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

static void PmicCdd_ReadWdModeStatus(void)
{
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_ReadWdMode))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

static void PmicCdd_GpioInit(void)
{
  static PmicCdd_Gpio1_Reg_t PmicCdd_Gpio1_Reg = {0x00u};
  static PmicCdd_Gpio2_Reg_t PmicCdd_Gpio2_Reg = {0x00u};
  static PmicCdd_Gpio3_Reg_t PmicCdd_Gpio3_Reg = {0x00u};
  static PmicCdd_Gpio4_Reg_t PmicCdd_Gpio4_Reg = {0x00u};
  static PmicCdd_Gpio5_Reg_t PmicCdd_Gpio5_Reg = {0x00u};
  static PmicCdd_Gpio6_Reg_t PmicCdd_Gpio6_Reg = {0x00u};

  PmicCdd_Gpio1_Reg_TxBuf[0] = GPIO1_CONF_REG;
  /* Gpio1 Configuration */
  PmicCdd_Gpio1_Reg.bits.gpio1_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO1].PmicCdd_GpioDirection;
  PmicCdd_Gpio1_Reg.bits.gpio1_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO1].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio1_Reg.bits.gpio1_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO1].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio1_Reg.bits.gpio1_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO1].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio1_Reg.bits.gpio1_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO1].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio1_Reg.bits.gpio1_sel = (uint8)PmicCdd_GpiosConfig.GPIO1;
  PmicCdd_Gpio1_Reg_TxBuf[1] = PmicCdd_Gpio1_Reg.value;

  PmicCdd_Gpio2_Reg_TxBuf[0] = GPIO2_CONF_REG;
  /* Gpio2 Configuration */
  PmicCdd_Gpio2_Reg.bits.gpio2_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO2].PmicCdd_GpioDirection;
  PmicCdd_Gpio2_Reg.bits.gpio2_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO2].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio2_Reg.bits.gpio2_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO2].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio2_Reg.bits.gpio2_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO2].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio2_Reg.bits.gpio2_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO2].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio2_Reg.bits.gpio2_sel = (uint8)PmicCdd_GpiosConfig.GPIO2;
  PmicCdd_Gpio2_Reg_TxBuf[1] = PmicCdd_Gpio2_Reg.value;

  PmicCdd_Gpio3_Reg_TxBuf[0] = GPIO3_CONF_REG;
  /* Gpio3 Configuration */
  PmicCdd_Gpio3_Reg.bits.gpio3_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO3].PmicCdd_GpioDirection;
  PmicCdd_Gpio3_Reg.bits.gpio3_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO3].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio3_Reg.bits.gpio3_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO3].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio3_Reg.bits.gpio3_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO3].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio3_Reg.bits.gpio3_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO3].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio3_Reg.bits.gpio3_sel = (uint8)PmicCdd_GpiosConfig.GPIO3;
  PmicCdd_Gpio3_Reg_TxBuf[1] = PmicCdd_Gpio3_Reg.value;

  PmicCdd_Gpio4_Reg_TxBuf[0] = GPIO4_CONF_REG;
  /* Gpio4 Configuration */
  PmicCdd_Gpio4_Reg.bits.gpio4_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO4].PmicCdd_GpioDirection;
  PmicCdd_Gpio4_Reg.bits.gpio4_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO4].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio4_Reg.bits.gpio4_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO4].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio4_Reg.bits.gpio4_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO4].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio4_Reg.bits.gpio4_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO4].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio4_Reg.bits.gpio4_sel = (uint8)PmicCdd_GpiosConfig.GPIO4;
  PmicCdd_Gpio4_Reg_TxBuf[1] = PmicCdd_Gpio4_Reg.value;

  PmicCdd_Gpio5_Reg_TxBuf[0] = GPIO5_CONF_REG;
  /* Gpio5 Configuration */
  PmicCdd_Gpio5_Reg.bits.gpio5_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO5].PmicCdd_GpioDirection;
  PmicCdd_Gpio5_Reg.bits.gpio5_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO5].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio5_Reg.bits.gpio5_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO5].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio5_Reg.bits.gpio5_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO5].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio5_Reg.bits.gpio5_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO5].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio5_Reg.bits.gpio5_sel = (uint8)PmicCdd_GpiosConfig.GPIO5;
  PmicCdd_Gpio5_Reg_TxBuf[1] = PmicCdd_Gpio5_Reg.value;

  PmicCdd_Gpio6_Reg_TxBuf[0] = GPIO6_CONF_REG;
  /* Gpio6 Configuration */
  PmicCdd_Gpio6_Reg.bits.gpio6_dir = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO6].PmicCdd_GpioDirection;
  PmicCdd_Gpio6_Reg.bits.gpio6_od = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO6].PmicCdd_GpioOutDrive;
  PmicCdd_Gpio6_Reg.bits.gpio6_pu_sel = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO6].PmicCdd_GpioPuOrPdResistorSel;
  PmicCdd_Gpio6_Reg.bits.gpio6_pu_pd_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO6].PmicCdd_GpioPuOrPdActivate;
  PmicCdd_Gpio6_Reg.bits.gpio6_deglitch_en = (uint8)PmicCdd_GpioControlParams[PMICCDD_GPIO6].PmicCdd_GpioDeglitch;
  PmicCdd_Gpio6_Reg.bits.gpio6_sel = (uint8)PmicCdd_GpiosConfig.GPIO6;
  PmicCdd_Gpio6_Reg_TxBuf[1] = PmicCdd_Gpio6_Reg.value;
}

static void PmicCdd_BuckLdoVccaVmon_Init(void)
{
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
  /* Buck Ctrl Register */
  static PmicCdd_Buck1_Ctrl_Reg_t PmicCdd_Buck1Ctrl_Reg = {0x00u};
  static PmicCdd_Buck2_Ctrl_Reg_t PmicCdd_Buck2Ctrl_Reg = {0x00u};
  static PmicCdd_Buck3_Ctrl_Reg_t PmicCdd_Buck3Ctrl_Reg = {0x00u};
  static PmicCdd_Buck4_Ctrl_Reg_t PmicCdd_Buck4Ctrl_Reg = {0x00u};

  /* Ldo Ctrl Tegister */
  static PmicCdd_Ldo1_Ctrl_Reg_t PmicCdd_Ldo1Ctrl_Reg = {0x00u};
  static PmicCdd_Ldo2_Ctrl_Reg_t PmicCdd_Ldo2Ctrl_Reg = {0x00u};
  static PmicCdd_Ldo3_Ctrl_Reg_t PmicCdd_Ldo3Ctrl_Reg = {0x00u};
  /* Vcca Vmon Ctrl Register */
  static PmicCdd_Vcca_VmonCtrl_Reg_t PmicCdd_Vcca_VmonCtrl_Reg = {0x00};

  PmicCdd_Buck1CtrlReg_TxBuf[0] = BUCK1_CTRL_REG;
  /* Buck1 Configuration */
  PmicCdd_Buck1Ctrl_Reg.bits.buck1_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK1].PmicCdd_BuckEnable;
  PmicCdd_Buck1Ctrl_Reg.bits.buck1_fpwm = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK1].PmicCdd_BuckFpwmEnable;
  PmicCdd_Buck1Ctrl_Reg.bits.buck1_vmon_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK1].PmicCdd_BuckVmonEnable;
  PmicCdd_Buck1Ctrl_Reg.bits.buck1_pldn = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK1].PmicCdd_BuckPullDown;
  PmicCdd_Buck1CtrlReg_TxBuf[1] = PmicCdd_Buck1Ctrl_Reg.value;

  PmicCdd_Buck2CtrlReg_TxBuf[0] = BUCK2_CTRL_REG;
  /* Buck2 Configuration */
  PmicCdd_Buck2Ctrl_Reg.bits.buck2_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK2].PmicCdd_BuckEnable;
  PmicCdd_Buck2Ctrl_Reg.bits.buck2_fpwm = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK2].PmicCdd_BuckFpwmEnable;
  PmicCdd_Buck2Ctrl_Reg.bits.buck2_vmon_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK2].PmicCdd_BuckVmonEnable;
  PmicCdd_Buck2Ctrl_Reg.bits.buck2_pldn = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK2].PmicCdd_BuckPullDown;
  PmicCdd_Buck2CtrlReg_TxBuf[1] = PmicCdd_Buck2Ctrl_Reg.value;

  PmicCdd_Buck3CtrlReg_TxBuf[0] = BUCK3_CTRL_REG;
  /* Buck2 Configuration */
  PmicCdd_Buck3Ctrl_Reg.bits.buck3_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK3].PmicCdd_BuckEnable;
  PmicCdd_Buck3Ctrl_Reg.bits.buck3_fpwm = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK3].PmicCdd_BuckFpwmEnable;
  PmicCdd_Buck3Ctrl_Reg.bits.buck3_vmon_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK3].PmicCdd_BuckVmonEnable;
  PmicCdd_Buck3Ctrl_Reg.bits.buck3_pldn = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK3].PmicCdd_BuckPullDown;
  PmicCdd_Buck3CtrlReg_TxBuf[1] = PmicCdd_Buck3Ctrl_Reg.value;

  PmicCdd_Buck4CtrlReg_TxBuf[0] = BUCK4_CTRL_REG;
  /* Buck2 Configuration */
  PmicCdd_Buck4Ctrl_Reg.bits.buck4_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK4].PmicCdd_BuckEnable;
  PmicCdd_Buck4Ctrl_Reg.bits.buck4_fpwm = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK4].PmicCdd_BuckFpwmEnable;
  PmicCdd_Buck4Ctrl_Reg.bits.buck4_vmon_en = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK4].PmicCdd_BuckVmonEnable;
  PmicCdd_Buck4Ctrl_Reg.bits.buck4_pldn = (uint8)PmicCdd_BuckCtrlParams[PMICCDD_BUCK4].PmicCdd_BuckPullDown;
  PmicCdd_Buck4CtrlReg_TxBuf[1] = PmicCdd_Buck4Ctrl_Reg.value;

  PmicCdd_Ldo1CtrlReg_TxBuf[0] = LDO1_CTRL_REG;
  /* LDO1 Configuration */
  PmicCdd_Ldo1Ctrl_Reg.bits.ldo1_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO1].PmicCdd_LdoEnable;
  PmicCdd_Ldo1Ctrl_Reg.bits.ldo1_vmon_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO1].PmicCdd_LdoVmonEnable;
  PmicCdd_Ldo1Ctrl_Reg.bits.ldo1_discharge_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO1].PmicCdd_LdoDischarge;
  PmicCdd_Ldo1CtrlReg_TxBuf[1] = PmicCdd_Ldo1Ctrl_Reg.value;

  PmicCdd_Ldo2CtrlReg_TxBuf[0] = LDO2_CTRL_REG;
  /* LDO1 Configuration */
  PmicCdd_Ldo2Ctrl_Reg.bits.ldo2_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO2].PmicCdd_LdoEnable;
  PmicCdd_Ldo2Ctrl_Reg.bits.ldo2_vmon_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO2].PmicCdd_LdoVmonEnable;
  PmicCdd_Ldo2Ctrl_Reg.bits.ldo2_discharge_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO2].PmicCdd_LdoDischarge;
  PmicCdd_Ldo2CtrlReg_TxBuf[1] = PmicCdd_Ldo2Ctrl_Reg.value;

  PmicCdd_Ldo3CtrlReg_TxBuf[0] = LDO3_CTRL_REG;
  /* LDO1 Configuration */
  PmicCdd_Ldo3Ctrl_Reg.bits.ldo3_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO3].PmicCdd_LdoEnable;
  PmicCdd_Ldo3Ctrl_Reg.bits.ldo3_vmon_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO3].PmicCdd_LdoVmonEnable;
  PmicCdd_Ldo3Ctrl_Reg.bits.ldo3_discharge_en = (uint8)PmicCdd_LdoCtrlParams[PMICCDD_LDO3].PmicCdd_LdoDischarge;
  PmicCdd_Ldo3CtrlReg_TxBuf[1] = PmicCdd_Ldo3Ctrl_Reg.value;

  PmicCdd_Vcca_VmonCtrl_TxBuf[0] = VCCA_VMON_CTRL_REG;
  /* Enabling OV/UV for VCCA and VMON1 */
  PmicCdd_Vcca_VmonCtrl_Reg.bits.vcca_vmon_en = (uint8)PmicCdd_VccaVmonParams.PmicCdd_VccaVmonEnable;
  PmicCdd_Vcca_VmonCtrl_Reg.bits.vmon1_en = (uint8)PmicCdd_VccaVmonParams.PmicCdd_Vmon1VmonEnable;
  PmicCdd_Vcca_VmonCtrl_Reg.bits.vmon2_en = (uint8)PmicCdd_VccaVmonParams.PmicCdd_Vmon2VmonEnable;
  PmicCdd_Vcca_VmonCtrl_Reg.bits.vmon_deglitch_sel = (uint8)PmicCdd_VccaVmonParams.PmicCdd_VccaVmonDeglitch;
  PmicCdd_Vcca_VmonCtrl_TxBuf[1] = PmicCdd_Vcca_VmonCtrl_Reg.value;
#endif
}

static void PmicCdd_InitBuckLdoVccaVmon_Push(void)
{
#if (PMICCDD_ENABLE_BUCKS_LDOS_REWRITE == STD_ON)
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Buck1Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Buck2Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Buck3Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Buck4Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Ldo1Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Ldo2Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_Ldo3Ctrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_VccaVmonCtrl))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
#endif
}

/*============================================================================
**
** Function Name    :   PmicCdd_LockRegisters
**
** Visibility       :   Public
**
** Description      :  This function is used lock the PMIC registers to avoid unintended writes
**                     to PMIC registers expect ADC, ESM , WDG and INT registers
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
static void PmicCdd_LockRegisters(void)
{
  PmicCdd_Register_Lock_Reg.value = PMICCDD_REG_LOCK_VALUE;
  PmicCdd_RegisterLock_TxBuf[0] = REGISTER_LOCK_REG;
  PmicCdd_RegisterLock_TxBuf[1] = PmicCdd_Register_Lock_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_RegisterLock))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

/*============================================================================
**
** Function Name    :   PmicCdd_UnlockRegisters
**
** Visibility       :   Public
**
** Description      :  This function is used unlock the PMIC registers to avoid unintended writes
**                     to PMIC registers expect ADC, ESM , WDG and INT registers
**
** Invocation       :  Application
**
** Inputs           :   void
**
** Outputs          :   E_OK - Success
**                     E_NOT_OK - Fail
**
** Critical Section :  yes
**
**==========================================================================*/
static void PmicCdd_UnlockRegisters(void)
{
  PmicCdd_Register_Lock_Reg.value = PMICCDD_REG_UNLOCK_VALUE;
  PmicCdd_RegisterUnlock_TxBuf[0] = REGISTER_LOCK_REG;
  PmicCdd_RegisterUnlock_TxBuf[1] = PmicCdd_Register_Lock_Reg.value;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_RegisterUnlock))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

static void PmicCdd_CBWriteRegisterLock(void)
{
  // Set the flag to indicate the completion of Register Lock API
  PmicCdd_RegisterLock_Status = TRUE;
}
static void PmicCdd_CBWriteRegisterUnlock(void)
{
  // Set the flag to indicate the completion of Register Unlock API
  PmicCdd_RegisterLock_Status = FALSE;
}

// Clear Interrupt register based on the Bit set
static void PmicCdd_ClearBuckInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntBuck_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntBuck))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearLdoVmonInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntLdoVmon_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntLdoVmon))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearGpioInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntGpio_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntGpio))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearStartupInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntStartup_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntStartup))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }

#if (PMICCDD_ENABLE_ADC == STD_ON)
  if (PmicCdd_EnableBit_Status == TRUE)
  {
    PmicCdd_Adc_FSM_State = PmicCdd_ADC_Conv_Idle;
  }
#endif
}
static void PmicCdd_ClearMiscInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntMisc_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntMisc))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearModerateErrorInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntModerateError_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntModerateError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearSevereErrorInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntSevereError_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntSevereError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearFsmErrorInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntFsmError_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntFsmError))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearEsmInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_IntEsm_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_Write_IntEsm))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}
static void PmicCdd_ClearWdgErrStatusInt(uint8 Mask)
{
  uint8 flBitMask = Mask;
  PmicCdd_WdErrStatusReg_TxBuf[1] = flBitMask;
  if (E_OK != PmicCdd_I2cPushSequence(PmicCdd_write_WdErrStatus))
  {
    PmicCdd_Det_ReportError(PMICCDD_INIT, PMICCDD_ERROR_I2C_PUSH_SEQUENCE_FAILED);
  }
}

static void PmicCdd_CBCheckNvmCodes(void)
{

  if((PmicCdd_DevRev_Reg_RxBuf[0] == PMICCDD_DEVICE_ID) && (PmicCdd_NvmCode1_Reg_RxBuf[0] == PMICCDD_TI_NVM_ID) && (PmicCdd_NvmCode2_Reg_RxBuf[0] == PMICCDD_TI_NVM_REV))
  {
    // Do nothing as the NVM code is matching with expected value
  }
  else
  {
    PmicCdd_Callout_SMError_Report(PMICCDD_INIT, PMICCDD_ERROR_NVM_CODE_MISMATCH);
  }
}

#define PMICCDD_SEC_CODE_STOP
#define PMICCDD_CORE_CONST_SEC_END
#define PMICCDD_CORE_DATA_SEC_END
#define PMICCDD_CORE_BSS_SEC_END

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
Date              :  05-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3280
Change Description: PmicCdd initial release, Added support for WDG and ADC
        Initialization and functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  26-Jun-2024
By                :  MSAVARIY
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-3709
Change Description: Added support for ESM configuration and Error interrupt checking,
            Reporting and clear functionalities.
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  04-Jul-2024
By                :  gthanapp
Traceability      : DICVA-13935
Change Description: Compiler Warning fix
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :  24-Sep-2024
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-4380
Change Description: PmicCdd ADC Interrupt Mechanism Handling Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  24-Mar-2025
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-6866
Change Description: PmicCdd Formal Release - Long Window API update and
                    required documents update like PG, IG, UTP, FTP, Design etc
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  24-Mar-2025
By                :  abasavar
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-9515
Change Description: CMPLIB_INSTANCE Update
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :  09-Feb-2026
By                :  sdv
Traceability      : https://visteon.atlassian.net/browse/PE4TI29141-11485
Change Description: Pmic Safety Implementation
-----------------------------------------------------------------------------*/
