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
 * @file        FltM_Cfg.h
 * @details     <b> Fault Manager  </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef FLTM_CFG_H_
#define FLTM_CFG_H_

#include "Std_Types.h"
#include "FltM_Types.h"       // Common FltM type definitions
#include "Dlt.h"              // DLT basic types
#include "Rte_Dlt_Type.h"     // DLT log level constants
#include "Rte_Type.h"         // RTE types for integration

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

/*
 * User Configuration:
 *  - FLTM_MAX_NUM_FAULTS: Number of fault entries (sample value)
 *  - FLTM_NUMBER_OF_DLT_LOGINFO: Number of DLT log info entries (sample value)
 */
#ifndef FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE
#error "FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE must be provided by vp_platform.cmake"
#endif

#if ((FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE != STD_OFF) && \
     (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE != STD_ON))
#error "FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE must be STD_OFF or STD_ON"
#endif

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
#define FLTM_MAX_NUM_FAULTS         88U
#define FLTM_NUM_ACTION_CFG         4U
#else
#define FLTM_MAX_NUM_FAULTS         87U
#define FLTM_NUM_ACTION_CFG         3U
#endif

#define FLTM_NUMBER_OF_DLT_LOGINFO  2U
#define FLTM_NUM_DEBOUNCE_CFG       1U
#define FLTM_NUM_LOG_CFG            3U
#define FLTM_NUM_SEVERITY_CFG       3U
#define FLTM_NUM_RESET_POLICY_CFG   3U

#define FLTM_MAINFUNCTION_PERIOD_MS 10U

#ifndef PERIODIC_READBACK_FAIL
#define PERIODIC_READBACK_FAIL                              (63787U)
#endif

#define FLTM_DEBOUNCE_CFG_IMMEDIATE                         (0U)

#define FLTM_LOG_CFG_FATAL_DLT                              (0U)
#define FLTM_LOG_CFG_ERROR_DLT                              (1U)
#define FLTM_LOG_CFG_INFO_DLT                               (2U)

#define FLTM_SEVERITY_CFG_FATAL                             (0U)
#define FLTM_SEVERITY_CFG_ERROR                             (1U)
#define FLTM_SEVERITY_CFG_INFO                              (2U)

#define FLTM_DEM_CFG_DCC_FAIL                               (0U)
#define FLTM_DEM_CFG_ECC_FAULT                              (1U)
#define FLTM_DEM_CFG_ECC_1BIT_ERROR                         (2U)
#define FLTM_DEM_CFG_ECC_2BIT_ERROR                         (3U)
#define FLTM_DEM_CFG_OCOC_FAIL                              (4U)
#define FLTM_DEM_CFG_POK_FAULT                              (5U)
#define FLTM_DEM_CFG_TIFS_SAFETY_CHECK_FWL_FAIL             (6U)
#define FLTM_DEM_CFG_BACKLIGHT_ERROR                        (7U)
#define FLTM_DEM_CFG_POWER_ON_RESET                         (8U)
#define FLTM_DEM_CFG_POWER_SUPPLY_FAULT                     (9U)
#define FLTM_DEM_CFG_EXT_WDG_RESET                          (10U)
#define FLTM_DEM_CFG_EXT_WDG_COMM_ERROR                     (11U)
#define FLTM_DEM_CFG_WDGM_ALIVE_FAIL                        (12U)
#define FLTM_DEM_CFG_PMIC_MAXRSTCOUNT_REACHED               (13U)
#define FLTM_DEM_CFG_PMIC_ABIST_FAIL                        (14U)
#define FLTM_DEM_CFG_NVM_INTEGRITY_ERROR                    (15U)
#define FLTM_DEM_CFG_BUCK1_OVUV_ERROR                       (16U)
#define FLTM_DEM_CFG_BUCK2_OVUV_ERROR                       (17U)
#define FLTM_DEM_CFG_BUCK3_OVUV_ERROR                       (18U)
#define FLTM_DEM_CFG_BUCK4_OVUV_ERROR                       (19U)
#define FLTM_DEM_CFG_LDO1_OVUV_ERROR                        (20U)
#define FLTM_DEM_CFG_LDO2_OVUV_ERROR                        (21U)
#define FLTM_DEM_CFG_LDO3_OVUV_ERROR                        (22U)
#define FLTM_DEM_CFG_VVCA_OVUV_ERROR                        (23U)
#define FLTM_DEM_CFG_VMON1_OVUV_ERROR                       (24U)
#define FLTM_DEM_CFG_FLASH_INTEGRITY_FAIL                   (25U)
#define FLTM_DEM_CFG_DMNMGR_GIP_FIRSTHB_MISS                (26U)
#define FLTM_DEM_CFG_SW_MAIN_WARMRSTZ                       (27U)
#define FLTM_DEM_CFG_ARM_PREFETCH_ABORT_R5                  (28U)
#define FLTM_DEM_CFG_ARM_DATA_ABORT                         (29U)
#define FLTM_DEM_CFG_ARM_UNDEFINED_INSTRUCTION              (30U)
#define FLTM_DEM_CFG_OS_STATE                               (31U)
#define FLTM_DEM_CFG_OS_CALLLEVEL                           (32U)
#define FLTM_DEM_CFG_OS_ACCESS                              (33U)
#define FLTM_DEM_CFG_OS_ID                                  (34U)
#define FLTM_DEM_CFG_OS_LIMIT                               (35U)
#define FLTM_DEM_CFG_OS_NOFUNC                              (36U)
#define FLTM_DEM_CFG_OS_RESOURCE                            (37U)
#define FLTM_DEM_CFG_OS_VALUE                               (38U)
#define FLTM_DEM_CFG_OS_SERVICEID                           (39U)
#define FLTM_DEM_CFG_OS_ILLEGAL_ADDRESS                     (40U)
#define FLTM_DEM_CFG_OS_MISSINGEND                          (41U)
#define FLTM_DEM_CFG_OS_DISABLEDINT                         (42U)
#define FLTM_DEM_CFG_OS_STACKFAULT                          (43U)
#define FLTM_DEM_CFG_OS_PROTECTION_MEMORY                   (44U)
#define FLTM_DEM_CFG_OS_PROTECTION_TIME                     (45U)
#define FLTM_DEM_CFG_OS_PROTECTION_ARRIVAL                  (46U)
#define FLTM_DEM_CFG_OS_PROTECTION_LOCKED                   (47U)
#define FLTM_DEM_CFG_OS_PROTECTION_EXCEPTION                (48U)
#define FLTM_DEM_CFG_OS_INTERFERENCE_DEADLOCK               (49U)
#define FLTM_DEM_CFG_OS_NESTING_DEADLOCK                    (50U)
#define FLTM_DEM_CFG_OS_SPINLOCK                            (51U)
#define FLTM_DEM_CFG_OS_CORE                                (52U)
#define FLTM_DEM_CFG_OS_PARAM_POINTER                       (53U)
#define FLTM_DEM_CFG_OS_SHUTDOWN                            (54U)
#define FLTM_DEM_CFG_OS_SYS_API_ERROR                       (55U)
#define FLTM_DEM_CFG_OS_SYS_ASSERTION                       (56U)
#define FLTM_DEM_CFG_OS_SYS_DISABLED                        (57U)
#define FLTM_DEM_CFG_OS_SYS_NO_BARRIER_PARTICIPANT          (58U)
#define FLTM_DEM_CFG_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY     (59U)
#define FLTM_DEM_CFG_OS_SYS_NO_NTFSTACK                     (60U)
#define FLTM_DEM_CFG_OS_SYS_OVERFLOW                        (61U)
#define FLTM_DEM_CFG_OS_SYS_KILL_KERNEL_OBJ                 (62U)
#define FLTM_DEM_CFG_OS_SYS_NO_RESTARTTASK                  (63U)
#define FLTM_DEM_CFG_OS_SYS_CALL_NOT_ALLOWED                (64U)
#define FLTM_DEM_CFG_OS_SYS_FUNCTION_UNAVAILABLE            (65U)
#define FLTM_DEM_CFG_OS_SYS_PROTECTION_SYSCALL              (66U)
#define FLTM_DEM_CFG_OS_SYS_PROTECTION_IRQ                  (67U)
#define FLTM_DEM_CFG_OS_SYS_OVERLOAD                        (68U)
#define FLTM_DEM_CFG_OS_SYS_CROSS_CORE_REQUESTED            (69U)
#define FLTM_DEM_CFG_DM_WDG_FAIL                            (70U)
#define FLTM_DEM_CFG_DMNMGR_GIP_HB_MISS                     (71U)
#define FLTM_DEM_CFG_DMNMGR_GIP_LINKUP_FAILED               (72U)
#define FLTM_DEM_CFG_DMNMGR_GIP_HEALTH_FATAL_ERROR          (73U)
#define FLTM_DEM_CFG_VOLTAGE_ERROR                          (74U)
#define FLTM_DEM_CFG_SW_HANG                                (75U)
#define FLTM_DEM_CFG_BUCK1_OVUV_RESET                       (76U)
#define FLTM_DEM_CFG_BUCK2_OVUV_RESET                       (77U)
#define FLTM_DEM_CFG_BUCK3_OVUV_RESET                       (78U)
#define FLTM_DEM_CFG_BUCK4_OVUV_RESET                       (79U)
#define FLTM_DEM_CFG_LDO1_OVUV_RESET                        (80U)
#define FLTM_DEM_CFG_LDO2_OVUV_RESET                        (81U)
#define FLTM_DEM_CFG_LDO3_OVUV_RESET                        (82U)
#define FLTM_DEM_CFG_VVCA_OVUV_RESET                        (83U)
#define FLTM_DEM_CFG_VMON1_OVUV_RESET                       (84U)
#define FLTM_DEM_CFG_DET_ERROR                              (85U)
#define FLTM_DEM_CFG_PERIODIC_READBACK_FAIL                  (86U)
#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
#define FLTM_DEM_CFG_HW_TEST_RESERVED                       (87U)
#endif

#define FLTM_RESET_POLICY_CFG_RESET_UNTIL_FINAL_ACTION_TH3  (0U)
#define FLTM_RESET_POLICY_CFG_RESET_UNTIL_FINAL_ACTION_TH1  (1U)
#define FLTM_RESET_POLICY_CFG_NONE                          (2U)

#define FLTM_ACTION_CFG_INITIAL_FINAL_RECOVERY              (0U)
#define FLTM_ACTION_CFG_INITIAL_RECOVERY                    (1U)
#define FLTM_ACTION_CFG_NONE                                (2U)

#if (FLTM_SAME_FAULT_RESET_LOOP_HW_TEST_ENABLE == STD_ON)
#define FLTM_ACTION_CFG_HW_TEST_FINAL                       (3U)
#define FLTM_SAME_FAULT_HW_TEST_FAULT_ID                    (0xF9E9U)
#endif



#  ifndef FLTM_E_OS_SYS_API_ERROR
#   define FLTM_E_OS_SYS_API_ERROR (65305U)
#  endif
/** Function pointer typedef for safe action handlers. */
typedef Std_ReturnType (*FltM_ActionFunctionType)(FltM_FaultIdType FaultId);

/**
 * @brief Internal DLT log metadata without log level (common across faults)
 */
typedef struct {
    Dlt_SessionIDType SessionId; /**< DLT session identifier */
    Dlt_MessageArgumentCount argCount;  /**< Number of arguments in the log message */
    Dlt_MessageOptionsType   options;   /**< Log message options */
    Dlt_ApplicationIDType    appId;     /**< Application identifier for the message */
    Dlt_ContextIDType        contextId; /**< Context identifier for the message */
} FltM_Dlt_MessageLogInfoType;

/**
 * @brief Fault Manager configuration entry
 *
 * Defines handling and reporting policy for a specific fault ID.
 */
typedef struct
{
  FltM_FaultIdType FaultId;    /**< Unique fault identifier */
  uint16 SeverityConfigIdx;    /**< Index into FltM_SeverityConfig */
  uint16 DebounceConfigIdx;    /**< Index into FltM_DebounceConfig */
  uint16 LogConfigIdx;         /**< Index into FltM_LogConfig */
  uint16 DemConfigIdx;         /**< Index into FltM_DemConfig */
  uint16 ResetPolicyConfigIdx; /**< Index into FltM_ResetPolicyConfig */
  uint16 ActionConfigIdx;      /**< Index into FltM_ActionConfig */
} FltM_FaultConfigType;

typedef struct
{
  FltM_DebounceTypeType DebounceType; /**< Debounce strategy for the fault */
  uint8 FailCounterThreshold;         /**< Counter threshold for failed state */
  uint8 PassCounterThreshold;         /**< Counter threshold for passed state */
  uint16 DebounceFailTimeMs;          /**< Time threshold for failed state */
  uint16 DebouncePassTimeMs;          /**< Time threshold for passed state */
} FltM_DebounceConfigType;

typedef struct
{
  Dlt_MessageLogLevelType FltMLogLevel; /**< DLT log level used for trace output */
  uint16 DltLogInfoIndex;               /**< Index into FltM_Dlt_MessageLogInfo */
} FltM_LogConfigType;

typedef enum
{
  FLTM_SEVERITY_INFO = 0U,
  FLTM_SEVERITY_WARNING,
  FLTM_SEVERITY_ERROR,
  FLTM_SEVERITY_FATAL
} FltM_SeverityType;

typedef struct
{
  FltM_SeverityType FltMSeverity; /**< FltM-owned severity for policy decisions */
} FltM_SeverityConfigType;

typedef struct
{
  boolean LogDtc;             /**< TRUE when the fault shall report to DEM */
  Dem_EventIdType DemEventId; /**< DEM event ID used for DTC reporting */
} FltM_DemConfigType;

typedef enum
{
  FLTM_RESET_POLICY_NONE = 0U,
  FLTM_RESET_POLICY_RESET_UNTIL_FINAL_ACTION,
  FLTM_RESET_POLICY_RESET_ALWAYS,
  FLTM_RESET_POLICY_FINAL_ACTION_ONLY
} FltM_ResetPolicyModeType;

typedef struct
{
  FltM_ResetPolicyModeType ResetPolicyMode; /**< Reset behavior for this policy */
  uint8 FinalSafeActionThreshold;           /**< Repetition count before final action */
} FltM_ResetPolicyConfigType;

typedef struct
{
  FltM_ActionFunctionType FltM_FirstSafeAction; /**< Handler for initial safe action */
  FltM_ActionFunctionType FltM_FinalSafeAction; /**< Handler for final safe action */
  FltM_ActionFunctionType FltM_RecoveryAction;  /**< Handler for recovery action */
} FltM_ActionConfigType;

/* Extern declarations: user must define these in FltM_Cfg.c */
extern const FltM_FaultConfigType    FltM_FaultConfig[FLTM_MAX_NUM_FAULTS];
extern const FltM_DebounceConfigType FltM_DebounceConfig[FLTM_NUM_DEBOUNCE_CFG];
extern const FltM_LogConfigType FltM_LogConfig[FLTM_NUM_LOG_CFG];
extern const FltM_SeverityConfigType FltM_SeverityConfig[FLTM_NUM_SEVERITY_CFG];
extern const FltM_DemConfigType FltM_DemConfig[FLTM_MAX_NUM_FAULTS];
extern const FltM_ResetPolicyConfigType FltM_ResetPolicyConfig[FLTM_NUM_RESET_POLICY_CFG];
extern const FltM_ActionConfigType FltM_ActionConfig[FLTM_NUM_ACTION_CFG];
extern const FltM_Dlt_MessageLogInfoType  FltM_Dlt_MessageLogInfo[FLTM_NUMBER_OF_DLT_LOGINFO];

extern void FltM_Det_ReportError(uint8 ApiId, uint8 ErrorId);

extern Std_ReturnType FltM_Dem_SetEventStatus(Dem_EventIdType EventId,
                                         Dem_EventStatusType EventStatus);

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif /* FLTM_CFG_H_ */

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
