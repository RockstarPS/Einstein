/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DemMaster_0.c
 *        Config:  BMW.dpa"
 *     SW-C Type:  DemMaster_0
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <DemMaster_0>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dem_DTCFormatType
 *   
 *
 * Dem_DTCGroupType
 *   
 *
 * Dem_DTCKindType
 *   
 *
 * Dem_DTCSeverityType
 *   
 *
 * Dem_DTCStatusMaskType
 *   
 *
 * Dem_DTRControlType
 *   
 *
 * Dem_DebounceResetStatusType
 *   
 *
 * Dem_DebouncingStateType
 *   
 *
 * Dem_EventIdType
 *   
 *
 * Dem_EventStatusType
 *   
 *
 * Dem_IndicatorStatusType
 *   
 *
 * Dem_InitMonitorReasonType
 *   
 *
 * Dem_IumprDenomCondIdType
 *   
 *
 * Dem_IumprDenomCondStatusType
 *   
 *
 * Dem_IumprReadinessGroupType
 *   
 *
 * Dem_MonitorStatusType
 *   
 *
 * Dem_OperationCycleIdType
 *   
 *
 * Dem_OperationCycleStateType
 *   
 *
 * Dem_RatioIdType
 *   
 *
 * Dem_UdsStatusByteType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_DemMaster_0.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_DemMaster_0.h"
#include "SchM_Dem.h"
#include "TSC_SchM_Dem.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void DemMaster_0_TestDefines(void);


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
 * Dem_DTCGroupType: Integer in interval [0...16777215]
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_OperationCycleIdType: Integer in interval [0...255]
 * Dem_RatioIdType: Integer in interval [1...65535]
 * boolean: Boolean (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCKindType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_KIND_ALL_DTCS (1U)
 *   DEM_DTC_KIND_EMISSION_REL_DTCS (2U)
 * Dem_DTCSeverityType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_SEVERITY_NO_SEVERITY (0U)
 *   DTC_NO_SEVERITY_BflMask 255U (0b11111111)
 *   DTC_NO_SEVERITY_BflPn 0
 *   DTC_NO_SEVERITY_BflLn 8
 *   DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS (1U)
 *   DTC_CLASS_BflMask 31U (0b00011111)
 *   DTC_CLASS_BflPn 0
 *   DTC_CLASS_BflLn 5
 *   DEM_SEVERITY_WWHOBD_CLASS_A (2U)
 *   DTC_CLASS_BflMask 31U (0b00011111)
 *   DTC_CLASS_BflPn 0
 *   DTC_CLASS_BflLn 5
 *   DEM_SEVERITY_WWHOBD_CLASS_B1 (4U)
 *   DTC_CLASS_BflMask 31U (0b00011111)
 *   DTC_CLASS_BflPn 0
 *   DTC_CLASS_BflLn 5
 *   DEM_SEVERITY_WWHOBD_CLASS_B2 (8U)
 *   DTC_CLASS_BflMask 31U (0b00011111)
 *   DTC_CLASS_BflPn 0
 *   DTC_CLASS_BflLn 5
 *   DEM_SEVERITY_WWHOBD_CLASS_C (16U)
 *   DTC_CLASS_BflMask 31U (0b00011111)
 *   DTC_CLASS_BflPn 0
 *   DTC_CLASS_BflLn 5
 *   DEM_SEVERITY_MAINTENANCE_ONLY (32U)
 *   DTC_SEVERITY_BflMask 224U (0b11100000)
 *   DTC_SEVERITY_BflPn 5
 *   DTC_SEVERITY_BflLn 3
 *   DEM_SEVERITY_CHECK_AT_NEXT_HALT (64U)
 *   DTC_SEVERITY_BflMask 224U (0b11100000)
 *   DTC_SEVERITY_BflPn 5
 *   DTC_SEVERITY_BflLn 3
 *   DEM_SEVERITY_CHECK_IMMEDIATELY (128U)
 *   DTC_SEVERITY_BflMask 224U (0b11100000)
 *   DTC_SEVERITY_BflPn 5
 *   DTC_SEVERITY_BflLn 3
 * Dem_DTRControlType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTR_CTL_NORMAL (0U)
 *   DEM_DTR_CTL_NO_MAX (1U)
 *   DEM_DTR_CTL_NO_MIN (2U)
 *   DEM_DTR_CTL_RESET (3U)
 *   DEM_DTR_CTL_INVISIBLE (4U)
 * Dem_DebounceResetStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DEBOUNCE_STATUS_FREEZE (0U)
 *   DEM_DEBOUNCE_STATUS_RESET (1U)
 * Dem_DebouncingStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_TEMPORARILY_DEFECTIVE (1U)
 *   DEM_TEMPORARILY_DEFECTIVE_BflMask 1U (0b00000001)
 *   DEM_TEMPORARILY_DEFECTIVE_BflPn 0
 *   DEM_TEMPORARILY_DEFECTIVE_BflLn 1
 *   DEM_FINALLY_DEFECTIVE (2U)
 *   DEM_FINALLY_DEFECTIVE_BflMask 2U (0b00000010)
 *   DEM_FINALLY_DEFECTIVE_BflPn 1
 *   DEM_FINALLY_DEFECTIVE_BflLn 1
 *   DEM_TEMPORARILY_HEALED (4U)
 *   DEM_TEMPORARILY_HEALED_BflMask 4U (0b00000100)
 *   DEM_TEMPORARILY_HEALED_BflPn 2
 *   DEM_TEMPORARILY_HEALED_BflLn 1
 *   DEM_TEST_COMPLETE (8U)
 *   DEM_TEST_COMPLETE_BflMask 8U (0b00001000)
 *   DEM_TEST_COMPLETE_BflPn 3
 *   DEM_TEST_COMPLETE_BflLn 1
 *   DEM_DTR_UPDATE (16U)
 *   DEM_DTR_UPDATE_BflMask 16U (0b00010000)
 *   DEM_DTR_UPDATE_BflPn 4
 *   DEM_DTR_UPDATE_BflLn 1
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 *   DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
 *   DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
 *   DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
 *   DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_INDICATOR_OFF (0U)
 *   DEM_INDICATOR_CONTINUOUS (1U)
 *   DEM_INDICATOR_BLINKING (2U)
 *   DEM_INDICATOR_BLINK_CONT (3U)
 *   DEM_INDICATOR_SLOW_FLASH (4U)
 *   DEM_INDICATOR_FAST_FLASH (5U)
 *   DEM_INDICATOR_ON_DEMAND (6U)
 *   DEM_INDICATOR_SHORT (7U)
 * Dem_InitMonitorReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_INIT_MONITOR_CLEAR (1U)
 *   DEM_INIT_MONITOR_RESTART (2U)
 *   DEM_INIT_MONITOR_REENABLED (3U)
 *   DEM_INIT_MONITOR_STORAGE_REENABLED (4U)
 * Dem_IumprDenomCondIdType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_IUMPR_GENERAL_DENOMINATOR (1U)
 *   DEM_IUMPR_DEN_COND_COLDSTART (2U)
 *   DEM_IUMPR_DEN_COND_EVAP (3U)
 *   DEM_IUMPR_DEN_COND_500MI (4U)
 * Dem_IumprDenomCondStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_IUMPR_DEN_STATUS_NOT_REACHED (0U)
 *   DEM_IUMPR_DEN_STATUS_REACHED (1U)
 *   DEM_IUMPR_DEN_STATUS_INHIBITED (2U)
 * Dem_IumprReadinessGroupType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_IUMPR_BOOSTPRS (0U)
 *   DEM_IUMPR_CAT1 (1U)
 *   DEM_IUMPR_CAT2 (2U)
 *   DEM_IUMPR_EGR (3U)
 *   DEM_IUMPR_EGSENSOR (4U)
 *   DEM_IUMPR_EVAP (5U)
 *   DEM_IUMPR_NMHCCAT (6U)
 *   DEM_IUMPR_NOXADSORB (7U)
 *   DEM_IUMPR_NOXCAT (8U)
 *   DEM_IUMPR_OXS1 (9U)
 *   DEM_IUMPR_OXS2 (10U)
 *   DEM_IUMPR_PMFILTER (11U)
 *   DEM_IUMPR_PRIVATE (12U)
 *   DEM_IUMPR_SAIR (13U)
 *   DEM_IUMPR_SECOXS1 (14U)
 *   DEM_IUMPR_SECOXS2 (15U)
 *   DEM_IUMPR_FLSYS (16U)
 *   DEM_IUMPR_ALLGROUPS (255U)
 * Dem_MonitorStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_MONITOR_STATUS_TF (1U)
 *   DEM_MONITOR_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_MONITOR_STATUS_TF_BflPn 0
 *   DEM_MONITOR_STATUS_TF_BflLn 1
 *   DEM_MONITOR_STATUS_TNCTOC (2U)
 *   DEM_MONITOR_STATUS_TNCTOC_BflMask 2U (0b00000010)
 *   DEM_MONITOR_STATUS_TNCTOC_BflPn 1
 *   DEM_MONITOR_STATUS_TNCTOC_BflLn 1
 * Dem_OperationCycleStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_CYCLE_STATE_START (0U)
 *   DEM_CYCLE_STATE_END (1U)
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_UDS_STATUS_TF (1U)
 *   DEM_UDS_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_UDS_STATUS_TF_BflPn 0
 *   DEM_UDS_STATUS_TF_BflLn 1
 *   DEM_UDS_STATUS_TFTOC (2U)
 *   DEM_UDS_STATUS_TFTOC_BflMask 2U (0b00000010)
 *   DEM_UDS_STATUS_TFTOC_BflPn 1
 *   DEM_UDS_STATUS_TFTOC_BflLn 1
 *   DEM_UDS_STATUS_PDTC (4U)
 *   DEM_UDS_STATUS_PDTC_BflMask 4U (0b00000100)
 *   DEM_UDS_STATUS_PDTC_BflPn 2
 *   DEM_UDS_STATUS_PDTC_BflLn 1
 *   DEM_UDS_STATUS_CDTC (8U)
 *   DEM_UDS_STATUS_CDTC_BflMask 8U (0b00001000)
 *   DEM_UDS_STATUS_CDTC_BflPn 3
 *   DEM_UDS_STATUS_CDTC_BflLn 1
 *   DEM_UDS_STATUS_TNCSLC (16U)
 *   DEM_UDS_STATUS_TNCSLC_BflMask 16U (0b00010000)
 *   DEM_UDS_STATUS_TNCSLC_BflPn 4
 *   DEM_UDS_STATUS_TNCSLC_BflLn 1
 *   DEM_UDS_STATUS_TFSLC (32U)
 *   DEM_UDS_STATUS_TFSLC_BflMask 32U (0b00100000)
 *   DEM_UDS_STATUS_TFSLC_BflPn 5
 *   DEM_UDS_STATUS_TFSLC_BflLn 1
 *   DEM_UDS_STATUS_TNCTOC (64U)
 *   DEM_UDS_STATUS_TNCTOC_BflMask 64U (0b01000000)
 *   DEM_UDS_STATUS_TNCTOC_BflPn 6
 *   DEM_UDS_STATUS_TNCTOC_BflLn 1
 *   DEM_UDS_STATUS_WIR (128U)
 *   DEM_UDS_STATUS_WIR_BflMask 128U (0b10000000)
 *   DEM_UDS_STATUS_WIR_BflPn 7
 *   DEM_UDS_STATUS_WIR_BflLn 1
 *
 * Array Types:
 * ============
 * Dem_MaxDataValueType: Array with 1 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define DemMaster_0_START_SEC_CODE
#include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dem_MasterMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_MasterMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DemMaster_0_CODE) Dem_MasterMainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_MasterMainFunction
 *********************************************************************************************************************/

  TSC_Dem_SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
  TSC_Dem_SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
  TSC_Dem_SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_1();
  TSC_Dem_SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_1();
  TSC_Dem_SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_2();
  TSC_Dem_SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_2();
  TSC_Dem_SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_3();
  TSC_Dem_SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_3();
  TSC_Dem_SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_4();
  TSC_Dem_SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_4();

  DemMaster_0_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetDTCOfEvent
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDTCOfEvent> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetDTCOfEvent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCOfEvent);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCOfEvent) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetDTCOfEvent (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetDTCOfEvent(
    EventId,
    DTCFormat,
    DTCOfEvent
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetDTCStatusAvailabilityMask
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDTCStatusAvailabilityMask> of PortPrototype <DemServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, uint8 *DTCStatusMask)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemServices_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetDTCStatusAvailabilityMask_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCStatusMask) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetDTCStatusAvailabilityMask (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetDebouncingOfEvent
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDebouncingOfEvent> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, Dem_DebouncingStateType *DebouncingState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetDebouncingOfEvent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DebouncingState);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DebouncingState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetDebouncingOfEvent (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetDebouncingOfEvent(
    EventId,
    DebouncingState
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventEnableCondition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventEnableCondition> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventEnableCondition(Dem_EventIdType EventId, boolean *ConditionFullfilled)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventEnableCondition_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventEnableCondition(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) ConditionFullfilled);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventEnableCondition(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) ConditionFullfilled) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventEnableCondition (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventEnableCondition(
    EventId,
    ConditionFullfilled
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventExtendedDataRecordEx
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventExtendedDataRecordEx> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL
 *   RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventExtendedDataRecordEx_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventExtendedDataRecordEx (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventExtendedDataRecordEx(
    EventId,
    RecordNumber,
    DestBuffer,
    BufSize
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventFailed
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventFailed> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, boolean *EventFailed)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventFailed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventFailed);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventFailed) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventFailed (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventFailed(
    EventId,
    EventFailed
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventFreezeFrameDataEx
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventFreezeFrameDataEx> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL
 *   RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventFreezeFrameDataEx_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventFreezeFrameDataEx (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventFreezeFrameDataEx(
    EventId,
    RecordNumber,
    DataId,
    DestBuffer,
    BufSize
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventStatus> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventUdsStatus(Dem_EventIdType EventId, Dem_UdsStatusByteType *UDSStatusByte)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventUdsStatus (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventUdsStatus(
    EventId,
    UDSStatusByte
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetEventTested
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEventTested> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetEventTested(Dem_EventIdType EventId, boolean *EventTested)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetEventTested_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventTested);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventTested) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetEventTested (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetEventTested(
    EventId,
    EventTested
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetFaultDetectionCounter
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetFaultDetectionCounter> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, sint8 *FaultDetectionCounter)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetFaultDetectionCounter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetFaultDetectionCounter (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetFaultDetectionCounter(
    EventId,
    FaultDetectionCounter
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMonitorStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetMonitorStatus> of PortPrototype <GeneralEvtInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetMonitorStatus(Dem_EventIdType EventId, Dem_MonitorStatusType *MonitorStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMonitorStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) TSC_Inline_DemSatellite_0_Dem_GetMonitorStatus(Dem_EventIdType EventId, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) MonitorStatus);
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetMonitorStatus(Dem_EventIdType EventId, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) MonitorStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetMonitorStatus (returns application error)
 *********************************************************************************************************************/

  TSC_Inline_DemSatellite_0_Dem_GetMonitorStatus(
    EventId,
    MonitorStatus
  );
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetOperationCycleState> of PortPrototype <OpCycle_DemOperationCycle>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_GetOperationCycleState(Dem_OperationCycleStateType *CycleState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OperationCycle_E_NOT_OK
 *   RTE_E_OperationCycle_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetOperationCycleState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetOperationCycleState(Dem_OperationCycleIdType parg0, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) CycleState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_GetOperationCycleState (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRunRequested
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetPostRunRequested> of PortPrototype <DemServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_PostRunRequested(boolean *IsRequested)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemServices_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRunRequested_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_PostRunRequested(P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) IsRequested) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_PostRunRequested (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <OpCycle_DemOperationCycle>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dem_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OperationCycle_E_NOT_OK
 *   RTE_E_OperationCycle_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetOperationCycleState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetOperationCycleState(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dem_SetOperationCycleState (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DemMaster_0_STOP_SEC_CODE
#include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void DemMaster_0_TestDefines(void)
{
  /* Enumeration Data Types */

  Dem_DTCFormatType Test_Dem_DTCFormatType_V_1 = DEM_DTC_FORMAT_OBD;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_2 = DEM_DTC_FORMAT_UDS;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_3 = DEM_DTC_FORMAT_J1939;

  Dem_DTCKindType Test_Dem_DTCKindType_V_1 = DEM_DTC_KIND_ALL_DTCS;
  Dem_DTCKindType Test_Dem_DTCKindType_V_2 = DEM_DTC_KIND_EMISSION_REL_DTCS;

  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_1 = DEM_SEVERITY_NO_SEVERITY;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_1_BflMask = DTC_NO_SEVERITY_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_1_BflPn = DTC_NO_SEVERITY_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_1_BflLn = DTC_NO_SEVERITY_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_2 = DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_2_BflMask = DTC_CLASS_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_2_BflPn = DTC_CLASS_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_2_BflLn = DTC_CLASS_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_3 = DEM_SEVERITY_WWHOBD_CLASS_A;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_3_BflMask = DTC_CLASS_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_3_BflPn = DTC_CLASS_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_3_BflLn = DTC_CLASS_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_4 = DEM_SEVERITY_WWHOBD_CLASS_B1;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_4_BflMask = DTC_CLASS_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_4_BflPn = DTC_CLASS_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_4_BflLn = DTC_CLASS_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_5 = DEM_SEVERITY_WWHOBD_CLASS_B2;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_5_BflMask = DTC_CLASS_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_5_BflPn = DTC_CLASS_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_5_BflLn = DTC_CLASS_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_6 = DEM_SEVERITY_WWHOBD_CLASS_C;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_6_BflMask = DTC_CLASS_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_6_BflPn = DTC_CLASS_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_6_BflLn = DTC_CLASS_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_7 = DEM_SEVERITY_MAINTENANCE_ONLY;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_7_BflMask = DTC_SEVERITY_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_7_BflPn = DTC_SEVERITY_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_7_BflLn = DTC_SEVERITY_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_8 = DEM_SEVERITY_CHECK_AT_NEXT_HALT;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_8_BflMask = DTC_SEVERITY_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_8_BflPn = DTC_SEVERITY_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_8_BflLn = DTC_SEVERITY_BflLn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_9 = DEM_SEVERITY_CHECK_IMMEDIATELY;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_9_BflMask = DTC_SEVERITY_BflMask;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_9_BflPn = DTC_SEVERITY_BflPn;
  Dem_DTCSeverityType Test_Dem_DTCSeverityType_V_9_BflLn = DTC_SEVERITY_BflLn;

  Dem_DTRControlType Test_Dem_DTRControlType_V_1 = DEM_DTR_CTL_NORMAL;
  Dem_DTRControlType Test_Dem_DTRControlType_V_2 = DEM_DTR_CTL_NO_MAX;
  Dem_DTRControlType Test_Dem_DTRControlType_V_3 = DEM_DTR_CTL_NO_MIN;
  Dem_DTRControlType Test_Dem_DTRControlType_V_4 = DEM_DTR_CTL_RESET;
  Dem_DTRControlType Test_Dem_DTRControlType_V_5 = DEM_DTR_CTL_INVISIBLE;

  Dem_DebounceResetStatusType Test_Dem_DebounceResetStatusType_V_1 = DEM_DEBOUNCE_STATUS_FREEZE;
  Dem_DebounceResetStatusType Test_Dem_DebounceResetStatusType_V_2 = DEM_DEBOUNCE_STATUS_RESET;

  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_1 = DEM_TEMPORARILY_DEFECTIVE;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_1_BflMask = DEM_TEMPORARILY_DEFECTIVE_BflMask;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_1_BflPn = DEM_TEMPORARILY_DEFECTIVE_BflPn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_1_BflLn = DEM_TEMPORARILY_DEFECTIVE_BflLn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_2 = DEM_FINALLY_DEFECTIVE;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_2_BflMask = DEM_FINALLY_DEFECTIVE_BflMask;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_2_BflPn = DEM_FINALLY_DEFECTIVE_BflPn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_2_BflLn = DEM_FINALLY_DEFECTIVE_BflLn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_3 = DEM_TEMPORARILY_HEALED;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_3_BflMask = DEM_TEMPORARILY_HEALED_BflMask;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_3_BflPn = DEM_TEMPORARILY_HEALED_BflPn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_3_BflLn = DEM_TEMPORARILY_HEALED_BflLn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_4 = DEM_TEST_COMPLETE;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_4_BflMask = DEM_TEST_COMPLETE_BflMask;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_4_BflPn = DEM_TEST_COMPLETE_BflPn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_4_BflLn = DEM_TEST_COMPLETE_BflLn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_5 = DEM_DTR_UPDATE;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_5_BflMask = DEM_DTR_UPDATE_BflMask;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_5_BflPn = DEM_DTR_UPDATE_BflPn;
  Dem_DebouncingStateType Test_Dem_DebouncingStateType_V_5_BflLn = DEM_DTR_UPDATE_BflLn;

  Dem_EventStatusType Test_Dem_EventStatusType_V_1 = DEM_EVENT_STATUS_PASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_2 = DEM_EVENT_STATUS_FAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_3 = DEM_EVENT_STATUS_PREPASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_4 = DEM_EVENT_STATUS_PREFAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_5 = DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_6 = DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_7 = DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_8 = DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_9 = DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED;

  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_1 = DEM_INDICATOR_OFF;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_2 = DEM_INDICATOR_CONTINUOUS;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_3 = DEM_INDICATOR_BLINKING;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_4 = DEM_INDICATOR_BLINK_CONT;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_5 = DEM_INDICATOR_SLOW_FLASH;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_6 = DEM_INDICATOR_FAST_FLASH;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_7 = DEM_INDICATOR_ON_DEMAND;
  Dem_IndicatorStatusType Test_Dem_IndicatorStatusType_V_8 = DEM_INDICATOR_SHORT;

  Dem_InitMonitorReasonType Test_Dem_InitMonitorReasonType_V_1 = DEM_INIT_MONITOR_CLEAR;
  Dem_InitMonitorReasonType Test_Dem_InitMonitorReasonType_V_2 = DEM_INIT_MONITOR_RESTART;
  Dem_InitMonitorReasonType Test_Dem_InitMonitorReasonType_V_3 = DEM_INIT_MONITOR_REENABLED;
  Dem_InitMonitorReasonType Test_Dem_InitMonitorReasonType_V_4 = DEM_INIT_MONITOR_STORAGE_REENABLED;

  Dem_IumprDenomCondIdType Test_Dem_IumprDenomCondIdType_V_1 = DEM_IUMPR_GENERAL_DENOMINATOR;
  Dem_IumprDenomCondIdType Test_Dem_IumprDenomCondIdType_V_2 = DEM_IUMPR_DEN_COND_COLDSTART;
  Dem_IumprDenomCondIdType Test_Dem_IumprDenomCondIdType_V_3 = DEM_IUMPR_DEN_COND_EVAP;
  Dem_IumprDenomCondIdType Test_Dem_IumprDenomCondIdType_V_4 = DEM_IUMPR_DEN_COND_500MI;

  Dem_IumprDenomCondStatusType Test_Dem_IumprDenomCondStatusType_V_1 = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
  Dem_IumprDenomCondStatusType Test_Dem_IumprDenomCondStatusType_V_2 = DEM_IUMPR_DEN_STATUS_REACHED;
  Dem_IumprDenomCondStatusType Test_Dem_IumprDenomCondStatusType_V_3 = DEM_IUMPR_DEN_STATUS_INHIBITED;

  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_1 = DEM_IUMPR_BOOSTPRS;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_2 = DEM_IUMPR_CAT1;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_3 = DEM_IUMPR_CAT2;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_4 = DEM_IUMPR_EGR;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_5 = DEM_IUMPR_EGSENSOR;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_6 = DEM_IUMPR_EVAP;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_7 = DEM_IUMPR_NMHCCAT;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_8 = DEM_IUMPR_NOXADSORB;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_9 = DEM_IUMPR_NOXCAT;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_10 = DEM_IUMPR_OXS1;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_11 = DEM_IUMPR_OXS2;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_12 = DEM_IUMPR_PMFILTER;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_13 = DEM_IUMPR_PRIVATE;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_14 = DEM_IUMPR_SAIR;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_15 = DEM_IUMPR_SECOXS1;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_16 = DEM_IUMPR_SECOXS2;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_17 = DEM_IUMPR_FLSYS;
  Dem_IumprReadinessGroupType Test_Dem_IumprReadinessGroupType_V_18 = DEM_IUMPR_ALLGROUPS;

  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_1 = DEM_MONITOR_STATUS_TF;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_1_BflMask = DEM_MONITOR_STATUS_TF_BflMask;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_1_BflPn = DEM_MONITOR_STATUS_TF_BflPn;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_1_BflLn = DEM_MONITOR_STATUS_TF_BflLn;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_2 = DEM_MONITOR_STATUS_TNCTOC;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_2_BflMask = DEM_MONITOR_STATUS_TNCTOC_BflMask;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_2_BflPn = DEM_MONITOR_STATUS_TNCTOC_BflPn;
  Dem_MonitorStatusType Test_Dem_MonitorStatusType_V_2_BflLn = DEM_MONITOR_STATUS_TNCTOC_BflLn;

  Dem_OperationCycleStateType Test_Dem_OperationCycleStateType_V_1 = DEM_CYCLE_STATE_START;
  Dem_OperationCycleStateType Test_Dem_OperationCycleStateType_V_2 = DEM_CYCLE_STATE_END;

  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_1 = DEM_UDS_STATUS_TF;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_1_BflMask = DEM_UDS_STATUS_TF_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_1_BflPn = DEM_UDS_STATUS_TF_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_1_BflLn = DEM_UDS_STATUS_TF_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_2 = DEM_UDS_STATUS_TFTOC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_2_BflMask = DEM_UDS_STATUS_TFTOC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_2_BflPn = DEM_UDS_STATUS_TFTOC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_2_BflLn = DEM_UDS_STATUS_TFTOC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_3 = DEM_UDS_STATUS_PDTC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_3_BflMask = DEM_UDS_STATUS_PDTC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_3_BflPn = DEM_UDS_STATUS_PDTC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_3_BflLn = DEM_UDS_STATUS_PDTC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_4 = DEM_UDS_STATUS_CDTC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_4_BflMask = DEM_UDS_STATUS_CDTC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_4_BflPn = DEM_UDS_STATUS_CDTC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_4_BflLn = DEM_UDS_STATUS_CDTC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_5 = DEM_UDS_STATUS_TNCSLC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_5_BflMask = DEM_UDS_STATUS_TNCSLC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_5_BflPn = DEM_UDS_STATUS_TNCSLC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_5_BflLn = DEM_UDS_STATUS_TNCSLC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_6 = DEM_UDS_STATUS_TFSLC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_6_BflMask = DEM_UDS_STATUS_TFSLC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_6_BflPn = DEM_UDS_STATUS_TFSLC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_6_BflLn = DEM_UDS_STATUS_TFSLC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_7 = DEM_UDS_STATUS_TNCTOC;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_7_BflMask = DEM_UDS_STATUS_TNCTOC_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_7_BflPn = DEM_UDS_STATUS_TNCTOC_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_7_BflLn = DEM_UDS_STATUS_TNCTOC_BflLn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_8 = DEM_UDS_STATUS_WIR;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_8_BflMask = DEM_UDS_STATUS_WIR_BflMask;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_8_BflPn = DEM_UDS_STATUS_WIR_BflPn;
  Dem_UdsStatusByteType Test_Dem_UdsStatusByteType_V_8_BflLn = DEM_UDS_STATUS_WIR_BflLn;
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
