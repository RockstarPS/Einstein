/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CRstM.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CRstM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CRstM>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CRstM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CRstM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CRstM_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * UInt16: Integer in interval [0...65535]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * eFltM_FaultIdType: Enumeration of integer in interval [62977...65535] with enumerators
 *   FLTM_E_OS_ACCESS (65281U)
 *   FLTM_E_OS_CALLLEVEL (65282U)
 *   FLTM_E_OS_ID (65283U)
 *   FLTM_E_OS_LIMIT (65284U)
 *   FLTM_E_OS_NOFUNC (65285U)
 *   FLTM_E_OS_RESOURCE (65286U)
 *   FLTM_E_OS_STATE (65287U)
 *   FLTM_E_OS_VALUE (65288U)
 *   FLTM_E_OS_SERVICEID (65289U)
 *   FLTM_E_OS_ILLEGAL_ADDRESS (65290U)
 *   FLTM_E_OS_MISSINGEND (65291U)
 *   FLTM_E_OS_DISABLEDINT (65292U)
 *   FLTM_E_OS_STACKFAULT (65293U)
 *   FLTM_E_OS_PROTECTION_MEMORY (65294U)
 *   FLTM_E_OS_PROTECTION_TIME (65295U)
 *   FLTM_E_OS_PROTECTION_ARRIVAL (65296U)
 *   FLTM_E_OS_PROTECTION_LOCKED (65297U)
 *   FLTM_E_OS_PROTECTION_EXCEPTION (65298U)
 *   FLTM_E_OS_INTERFERENCE_DEADLOCK (65299U)
 *   FLTM_E_OS_NESTING_DEADLOCK (65300U)
 *   FLTM_E_OS_SPINLOCK (65301U)
 *   FLTM_E_OS_CORE (65302U)
 *   FLTM_E_OS_PARAM_POINTER (65303U)
 *   FLTM_E_OS_SHUTDOWN (65304U)
 *   FLTM_E_OS_SYS_API_ERROR (65305U)
 *   FLTM_E_OS_SYS_ASSERTION (65520U)
 *   FLTM_E_OS_SYS_DISABLED (65521U)
 *   FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT (65522U)
 *   FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (65523U)
 *   FLTM_E_OS_SYS_NO_NTFSTACK (65524U)
 *   FLTM_E_OS_SYS_OVERFLOW (65525U)
 *   FLTM_E_OS_SYS_KILL_KERNEL_OBJ (65526U)
 *   FLTM_E_OS_SYS_NO_RESTARTTASK (65527U)
 *   FLTM_E_OS_SYS_CALL_NOT_ALLOWED (65528U)
 *   FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE (65529U)
 *   FLTM_E_OS_SYS_PROTECTION_SYSCALL (65530U)
 *   FLTM_E_OS_SYS_PROTECTION_IRQ (65531U)
 *   FLTM_E_OS_SYS_OVERLOAD (65532U)
 *   FLTM_E_OS_SYS_CROSS_CORE_REQUESTED (65533U)
 *   E_ARM_NMI_EVENT (64001U)
 *   E_ARM_HARD_FAULT (64002U)
 *   E_ARM_MEMMANAGE_FAULT (64003U)
 *   E_ARM_BUS_FAULT (64004U)
 *   E_ARM_USAGE_FAULT (64005U)
 *   E_ARM_DEBUG_MONITOR (64006U)
 *   E_ARM_PENDING_SV (64007U)
 *   E_ARM_UNDEFINED_INSTRUCTION (64241U)
 *   E_ARM_Supervisor_Call (64242U)
 *   E_ARM_PREFETCH_ABORT (64243U)
 *   E_ARM_DATA_ABORT (64244U)
 *   E_ARM_SUPERVISOR (64245U)
 *   E_ARM_UNDEFINED (64246U)
 *   E_ARM_SVC (64247U)
 *   E_ARM_PREFETCH_ABORT_R5 (64248U)
 *   E_ARM_PREFETCH_ABOR_R5 (64249U)
 *   NVM_E_HARDWARE (64257U)
 *   NVM_E_INTEGRITY_FAILED (64258U)
 *   E_NVM_REQ_FAILED (64259U)
 *   E_NVM_WRONG_BLOCK_ID (64260U)
 *   E_NVM_VERIFY_FAILED (64261U)
 *   E_NVM_LOSS_OF_REDUNDANCY (64262U)
 *   E_NVM_WRITE_FAILED (64263U)
 *   E_NVM_READ_FAILED (64264U)
 *   RESET_UNDEFINED (64512U)
 *   POWER_ON_RESET (64513U)
 *   MCU_PORz (64514U)
 *   SW_MAIN_PORz (64515U)
 *   MCU_RESETz (64516U)
 *   SW_MCU_WARMRSTz (64517U)
 *   MAIN_RESETz_REQ (64518U)
 *   SW_MAIN_WARMRSTz (64519U)
 *   VTM_THERMAL_RESET (64520U)
 *   ESM_ERRORz (64521U)
 *   SMS_COLD_OUT_RST_n (64522U)
 *   SMS_WARM_OUT_RST_n (64523U)
 *   DM_WDT_RST_n (64524U)
 *   DET_ERROR (63745U)
 *   WDGM_ALIVE_FAIL (63746U)
 *   FOTA_RESET (63747U)
 *   DIAG_RESET (63748U)
 *   RAM_TST_ERROR (63749U)
 *   CAN_LOOP_TEST_ERROR (63750U)
 *   FLS_TST_ERROR (63751U)
 *   EARLY_WAKEUP (63752U)
 *   CORE_SYS_TST_ERROR (63753U)
 *   WAKEUP_SEQ_TIMELIMIT_FAULT (63754U)
 *   TFT_RECOVERYTIMELIMIT_FAULT (63755U)
 *   NVM_WRITE_FAIL (63756U)
 *   ADC_TEST (63757U)
 *   WDM_TIMER_FAIL (63758U)
 *   CM_TEST_FAIL (63759U)
 *   DMA_TEST_FAIL (63760U)
 *   PPU_TEST_FAIL (63761U)
 *   POWER_SUPPLY_FAULT (63762U)
 *   ECC_FAULT (63763U)
 *   DCC_FAIL (63764U)
 *   OCOC_FAIL (63765U)
 *   GIP_HEALTH_FAIL (63766U)
 *   HSM_WDG_FAIL (63767U)
 *   POK_FAULT (63768U)
 *   DM_WDG_FAIL (63769U)
 *   FIREWALL_ACCESS_FAIL (63770U)
 *   FALSH_INTEGRITY_FAIL (63771U)
 *   TOG_FAULT (63772U)
 *   VTM_FAULT (63773U)
 *   DM_SAFETY_CHECK_PWR_FAIL (63774U)
 *   DM_SAFETY_CHECK_RES_FAIL (63775U)
 *   TIFS_SAFETY_CHECK_FWL_FAIL (63776U)
 *   SCI_CLIENT_PM_CLOCK_FAIL (63777U)
 *   SCI_CLIENT_PM_RESET_FAIL (63778U)
 *   SCI_CLIENT_PM_LPM_FAIL (63779U)
 *   SCI_CLIENT_RM_IRQ_FAIL (63780U)
 *   SCI_CLIENT_RM_FWL_FAIL (63781U)
 *   SCI_CLIENT_RM_UDMA_FAIL (63782U)
 *   SCI_CLIENT_RM_PSIL_FAIL (63783U)
 *   DM_BOOT_STAGE1_FAIL (63784U)
 *   DM_BOOT_STAGE2_FAIL (63785U)
 *   DM_DDR_FAIL (63786U)
 *   DM_eMMC_FAIL (63787U)
 *   DM_QSPI_FAIL (63788U)
 *   DM_STACK_FAIL (63789U)
 *   DM_OS_ERROR (63790U)
 *   DM_SCI_SERVER_FAIL (63791U)
 *   JTAG_PWD_FEED_FAIL (63792U)
 *   BM_SB_FAIL (63793U)
 *   FBL_SB_FAIL (63794U)
 *   APP_SB_FAIL (63795U)
 *   CRC_SB_FAIL (63796U)
 *   HSM_OS_ERROR (63797U)
 *   HSM_MAC_FAIL (63798U)
 *   HSM_CIPHER_FAIL (63799U)
 *   HSM_KEY_FAIL (63800U)
 *   HSM_SEED_FAIL (63801U)
 *   HSM_FWL_FAIL (63802U)
 *   EXT_WDG_RESET (63803U)
 *   EXT_WDG_COMM_ERROR (63804U)
 *   PMIC_SLEEP_RESET (63805U)
 *   ECC_FAULT_SED (63806U)
 *   FLASH_INTEGRITY_FAIL (63807U)
 *   UNEXPECTED_ERROR (63233U)
 *   DISPLAY_ERROR (63234U)
 *   TEMP_ERROR (63235U)
 *   VOLTAGE_ERROR (63236U)
 *   SAFETY_ERROR (63237U)
 *   SECURITY_ERROR (63238U)
 *   CPU_UTUILISATION_ERROR (63239U)
 *   NETWORK_ERROR (63240U)
 *   PERIPHERAL_ERROR (63241U)
 *   BACKLIGHT_ERROR (63242U)
 *   POWERUP_SOWN_ERROR (63243U)
 *   TIMEOUT_EVENT_MISSING_ERRORS (63244U)
 *   IPCL_VERSION_MISMATCH (63245U)
 *   HEALTH_MON_ERROR (63246U)
 *   UCL_FATAL_ERROR (63247U)
 *   UCL_ERROR_STATUS (63248U)
 *   SOTA_OTA_FOTA_ERROR (63249U)
 *   ODOMETER_ERROR (63250U)
 *   FORCED_BLANK (62977U)
 *   POWER_UP_STATE (62978U)
 *   POWER_DOWN_STATE (62979U)
 *   ILLUMINATION_VALUE (62980U)
 *   NVM_STATUS (62981U)
 *   FEATURE_SLEEP_STATUS (62982U)
 *   NETWORK_STATUS (62983U)
 *   WAKEUP_REASON (62984U)
 *   HMISTATUS (62985U)
 *   MAGIC_FLAGSTATUS (62986U)
 *   FLTM_E_DMNMGR_GIP_FIRSTHB_MISS (63808U)
 *   FLTM_E_PMIC_ABIST_FAIL (63809U)
 *   FLTM_E_PMIC_FAILINT_ERROR (63810U)
 *   FLTM_E_PMIC_RSTINT_ERROR (63811U)
 *   FLTM_E_SW_HANG (63812U)
 *   FLTM_E_BUCK1_OVUV (63813U)
 *   FLTM_E_BUCK2_OVUV (63814U)
 *   FLTM_E_BUCK3_OVUV (63815U)
 *   FLTM_E_BUCK4_OVUV (63816U)
 *   FLTM_E_LDO1_OVUV (63817U)
 *   FLTM_E_LDO2_OVUV (63818U)
 *   FLTM_E_LDO3_OVUV (63819U)
 *   FLTM_E_VVCA_OVUV (63820U)
 *   FLTM_E_VMON1_OVUV (63821U)
 *   FLTM_E_NVM_INTEGRITY_ERROR (63822U)
 *   ECC_1BIT_ERROR (63823U)
 *   ECC_2BIT_ERROR (63824U)
 *   FLTM_PMIC_MAXRSTCOUNT_REACHED (63825U)
 *   FLTM_E_UNKNOWN (65535U)
 *   FLTM_E_DMNMGR_GIP_HB_MISS (63826U)
 *   FLTM_E_DMNMGR_GIP_LINKUP_FAILED (63827U)
 *   FLTM_E_DMNMGR_GIP_HEALTH_FATAL_ERROR (63828U)
 *
 *********************************************************************************************************************/


#define CRstM_START_SEC_CODE
#include "CRstM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CRstM_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CRstM_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CRstM_CODE) CRstM_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CRstM_Impl_MainFunction
 *********************************************************************************************************************/

  CRstM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CRstM_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CRstM>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CRstM_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CRstM_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) CRstM_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CRstM_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstM_ClearResetHistory
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstM_ClearResetHistory> of PortPrototype <pp_CS_RstM_ClearResetHistory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RstM_ClearResetHistory(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RstM_ClearResetHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_ClearResetHistory_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) RstM_ClearResetHistory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_ClearResetHistory (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstM_GetLastResetReason
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstM_GetLastResetReason> of PortPrototype <pp_CS_RstM_GetLastResetReason>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RstM_GetLastResetReason(eFltM_FaultIdType *pFaultId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RstM_GetLastResetReason_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetLastResetReason_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) RstM_GetLastResetReason(P2VAR(eFltM_FaultIdType, AUTOMATIC, RTE_CRSTM_APPL_VAR) pFaultId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetLastResetReason (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstM_GetResetCount
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstM_GetResetCount> of PortPrototype <pp_CS_RstM_GetResetCount>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RstM_GetResetCount(eFltM_FaultIdType FaultId, UInt8 *count)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RstM_GetResetCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetResetCount_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) RstM_GetResetCount(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) count) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetResetCount (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstM_GetResetHistory
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstM_GetResetHistory> of PortPrototype <pp_CS_RstM_GetResetHistory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RstM_GetResetHistory(UInt8 *ResetHistory)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RstM_GetResetHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetResetHistory_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) RstM_GetResetHistory(P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) ResetHistory) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_GetResetHistory (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstM_RequestSwReset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstM_RequestSwReset> of PortPrototype <pp_CS_RstM_RequestSwReset>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RstM_RequestSwReset(eFltM_FaultIdType FaultId, UInt8 *LogData, UInt16 LogLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RstM_RequestSwReset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_RequestSwReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CRstM_CODE) RstM_RequestSwReset(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) LogData, UInt16 LogLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstM_RequestSwReset (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CRstM_STOP_SEC_CODE
#include "CRstM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CRstM_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  eFltM_FaultIdType Test_eFltM_FaultIdType_V_1 = FLTM_E_OS_ACCESS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_2 = FLTM_E_OS_CALLLEVEL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_3 = FLTM_E_OS_ID;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_4 = FLTM_E_OS_LIMIT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_5 = FLTM_E_OS_NOFUNC;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_6 = FLTM_E_OS_RESOURCE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_7 = FLTM_E_OS_STATE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_8 = FLTM_E_OS_VALUE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_9 = FLTM_E_OS_SERVICEID;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_10 = FLTM_E_OS_ILLEGAL_ADDRESS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_11 = FLTM_E_OS_MISSINGEND;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_12 = FLTM_E_OS_DISABLEDINT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_13 = FLTM_E_OS_STACKFAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_14 = FLTM_E_OS_PROTECTION_MEMORY;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_15 = FLTM_E_OS_PROTECTION_TIME;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_16 = FLTM_E_OS_PROTECTION_ARRIVAL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_17 = FLTM_E_OS_PROTECTION_LOCKED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_18 = FLTM_E_OS_PROTECTION_EXCEPTION;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_19 = FLTM_E_OS_INTERFERENCE_DEADLOCK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_20 = FLTM_E_OS_NESTING_DEADLOCK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_21 = FLTM_E_OS_SPINLOCK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_22 = FLTM_E_OS_CORE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_23 = FLTM_E_OS_PARAM_POINTER;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_24 = FLTM_E_OS_SHUTDOWN;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_25 = FLTM_E_OS_SYS_API_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_26 = FLTM_E_OS_SYS_ASSERTION;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_27 = FLTM_E_OS_SYS_DISABLED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_28 = FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_29 = FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_30 = FLTM_E_OS_SYS_NO_NTFSTACK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_31 = FLTM_E_OS_SYS_OVERFLOW;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_32 = FLTM_E_OS_SYS_KILL_KERNEL_OBJ;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_33 = FLTM_E_OS_SYS_NO_RESTARTTASK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_34 = FLTM_E_OS_SYS_CALL_NOT_ALLOWED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_35 = FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_36 = FLTM_E_OS_SYS_PROTECTION_SYSCALL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_37 = FLTM_E_OS_SYS_PROTECTION_IRQ;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_38 = FLTM_E_OS_SYS_OVERLOAD;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_39 = FLTM_E_OS_SYS_CROSS_CORE_REQUESTED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_40 = E_ARM_NMI_EVENT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_41 = E_ARM_HARD_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_42 = E_ARM_MEMMANAGE_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_43 = E_ARM_BUS_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_44 = E_ARM_USAGE_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_45 = E_ARM_DEBUG_MONITOR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_46 = E_ARM_PENDING_SV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_47 = E_ARM_UNDEFINED_INSTRUCTION;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_48 = E_ARM_Supervisor_Call;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_49 = E_ARM_PREFETCH_ABORT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_50 = E_ARM_DATA_ABORT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_51 = E_ARM_SUPERVISOR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_52 = E_ARM_UNDEFINED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_53 = E_ARM_SVC;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_54 = E_ARM_PREFETCH_ABORT_R5;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_55 = E_ARM_PREFETCH_ABOR_R5;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_56 = NVM_E_HARDWARE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_57 = NVM_E_INTEGRITY_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_58 = E_NVM_REQ_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_59 = E_NVM_WRONG_BLOCK_ID;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_60 = E_NVM_VERIFY_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_61 = E_NVM_LOSS_OF_REDUNDANCY;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_62 = E_NVM_WRITE_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_63 = E_NVM_READ_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_64 = RESET_UNDEFINED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_65 = POWER_ON_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_66 = MCU_PORz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_67 = SW_MAIN_PORz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_68 = MCU_RESETz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_69 = SW_MCU_WARMRSTz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_70 = MAIN_RESETz_REQ;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_71 = SW_MAIN_WARMRSTz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_72 = VTM_THERMAL_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_73 = ESM_ERRORz;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_74 = SMS_COLD_OUT_RST_n;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_75 = SMS_WARM_OUT_RST_n;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_76 = DM_WDT_RST_n;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_77 = DET_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_78 = WDGM_ALIVE_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_79 = FOTA_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_80 = DIAG_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_81 = RAM_TST_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_82 = CAN_LOOP_TEST_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_83 = FLS_TST_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_84 = EARLY_WAKEUP;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_85 = CORE_SYS_TST_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_86 = WAKEUP_SEQ_TIMELIMIT_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_87 = TFT_RECOVERYTIMELIMIT_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_88 = NVM_WRITE_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_89 = ADC_TEST;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_90 = WDM_TIMER_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_91 = CM_TEST_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_92 = DMA_TEST_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_93 = PPU_TEST_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_94 = POWER_SUPPLY_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_95 = ECC_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_96 = DCC_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_97 = OCOC_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_98 = GIP_HEALTH_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_99 = HSM_WDG_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_100 = POK_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_101 = DM_WDG_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_102 = FIREWALL_ACCESS_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_103 = FALSH_INTEGRITY_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_104 = TOG_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_105 = VTM_FAULT;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_106 = DM_SAFETY_CHECK_PWR_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_107 = DM_SAFETY_CHECK_RES_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_108 = TIFS_SAFETY_CHECK_FWL_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_109 = SCI_CLIENT_PM_CLOCK_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_110 = SCI_CLIENT_PM_RESET_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_111 = SCI_CLIENT_PM_LPM_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_112 = SCI_CLIENT_RM_IRQ_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_113 = SCI_CLIENT_RM_FWL_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_114 = SCI_CLIENT_RM_UDMA_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_115 = SCI_CLIENT_RM_PSIL_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_116 = DM_BOOT_STAGE1_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_117 = DM_BOOT_STAGE2_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_118 = DM_DDR_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_119 = DM_eMMC_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_120 = DM_QSPI_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_121 = DM_STACK_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_122 = DM_OS_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_123 = DM_SCI_SERVER_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_124 = JTAG_PWD_FEED_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_125 = BM_SB_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_126 = FBL_SB_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_127 = APP_SB_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_128 = CRC_SB_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_129 = HSM_OS_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_130 = HSM_MAC_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_131 = HSM_CIPHER_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_132 = HSM_KEY_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_133 = HSM_SEED_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_134 = HSM_FWL_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_135 = EXT_WDG_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_136 = EXT_WDG_COMM_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_137 = PMIC_SLEEP_RESET;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_138 = ECC_FAULT_SED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_139 = FLASH_INTEGRITY_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_140 = UNEXPECTED_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_141 = DISPLAY_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_142 = TEMP_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_143 = VOLTAGE_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_144 = SAFETY_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_145 = SECURITY_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_146 = CPU_UTUILISATION_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_147 = NETWORK_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_148 = PERIPHERAL_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_149 = BACKLIGHT_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_150 = POWERUP_SOWN_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_151 = TIMEOUT_EVENT_MISSING_ERRORS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_152 = IPCL_VERSION_MISMATCH;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_153 = HEALTH_MON_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_154 = UCL_FATAL_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_155 = UCL_ERROR_STATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_156 = SOTA_OTA_FOTA_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_157 = ODOMETER_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_158 = FORCED_BLANK;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_159 = POWER_UP_STATE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_160 = POWER_DOWN_STATE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_161 = ILLUMINATION_VALUE;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_162 = NVM_STATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_163 = FEATURE_SLEEP_STATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_164 = NETWORK_STATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_165 = WAKEUP_REASON;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_166 = HMISTATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_167 = MAGIC_FLAGSTATUS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_168 = FLTM_E_DMNMGR_GIP_FIRSTHB_MISS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_169 = FLTM_E_PMIC_ABIST_FAIL;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_170 = FLTM_E_PMIC_FAILINT_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_171 = FLTM_E_PMIC_RSTINT_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_172 = FLTM_E_SW_HANG;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_173 = FLTM_E_BUCK1_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_174 = FLTM_E_BUCK2_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_175 = FLTM_E_BUCK3_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_176 = FLTM_E_BUCK4_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_177 = FLTM_E_LDO1_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_178 = FLTM_E_LDO2_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_179 = FLTM_E_LDO3_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_180 = FLTM_E_VVCA_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_181 = FLTM_E_VMON1_OVUV;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_182 = FLTM_E_NVM_INTEGRITY_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_183 = ECC_1BIT_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_184 = ECC_2BIT_ERROR;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_185 = FLTM_PMIC_MAXRSTCOUNT_REACHED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_186 = FLTM_E_UNKNOWN;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_187 = FLTM_E_DMNMGR_GIP_HB_MISS;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_188 = FLTM_E_DMNMGR_GIP_LINKUP_FAILED;
  eFltM_FaultIdType Test_eFltM_FaultIdType_V_189 = FLTM_E_DMNMGR_GIP_HEALTH_FATAL_ERROR;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
