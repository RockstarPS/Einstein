/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mdl_SafetyAdapter.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Mdl_SafetyAdapter
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Mdl_SafetyAdapter>
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

#include "Rte_Mdl_SafetyAdapter.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Mdl_SafetyAdapter.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Mdl_SafetyAdapter_TestDefines(void);


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
 * Boolean: Boolean
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * IoHwAb_AdcSignalIdType: Enumeration of integer in interval [0...17] with enumerators
 *   eIO_ADC_ADC_FUEL_5V_MON (16U)
 *   eIO_ADC_ADC_FUEL_MAIN (17U)
 *   eIO_ADC_IGN_AD (2U)
 *   eIO_ADC_FUEL_SEND_SUB_MICRO_AD (3U)
 *   eIO_ADC_AI_BATTERY (4U)
 *   eIO_ADC_AI_LCD_NTC (5U)
 *   eIO_ADC_AI_TEMP_RTC (6U)
 *   eIO_ADC_Flasher_Diag_sense_1 (7U)
 *   eIO_ADC_STR_SW2_ADIN (8U)
 *   eIO_ADC_STR_SW1_ADIN (9U)
 *   eIO_ADC_RHEO_SW_IN_ADIN (10U)
 *   eIO_ADC_ADC_RHEO_5V_MON_ADIN (11U)
 *   eIO_ADC_Flasher_Diag_sense_2 (12U)
 *   eIO_ADC_AdcChannel_Vdb (13U)
 *   eIO_ADC_AdcChannel_Vtemp (14U)
 *   eIO_ADC_MAX (15U)
 *   eIO_ADC_AI_SAMPLE_1 (0U)
 *   eIO_ADC_AI_SAMPLE_2 (1U)
 * IoHwAb_DInGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 *   eIO_DInGroupIdCount (0)
 * IoHwAb_DInSignalIdType: Enumeration of integer in interval [0...29] with enumerators
 *   eIO_DIN_DI_AL_HAZARD (0U)
 *   eIO_DIN_DI_AH_IGNITION (1U)
 *   eIO_DIN_DI_SMPS_3V3_PG (2U)
 *   eIO_DIN_STOP_LAMP_MCU (3U)
 *   eIO_DIN_DI_AL_BRAKE_LEVEL (4U)
 *   eIO_DIN_DI_AL_OIL_W (5U)
 *   eIO_DIN_DI_AL_DRV_SEAT_BUCKLE (6U)
 *   eIO_DIN_DI_AL_WASHER_LEVEL_SW (7U)
 *   eIO_DIN_ODO_TripKnobInput (8U)
 *   eIO_DIN_DI_AL_VACUUM (9U)
 *   eIO_DIN_DI_LCD_BL_PWR_FAULT (10U)
 *   eIO_DIN_DI_AL_FUEL_LID_EFI_ECU (11U)
 *   eIO_DIN_DI_TT_SHIFT_ERR (12U)
 *   eIO_DIN_MAX (13U)
 *   eIO_DIN_DI_PMIC_INTN (14U)
 *   eIO_DIN_DI_MCU_PORZ (15U)
 *   eIO_DIN_DI_SBATT2_ERR (16U)
 *   eIO_DIN_DI_FALD_PG (17U)
 *   eIO_DIN_DI_MD_TOUCH_INTN (18U)
 *   eIO_DIN_DI_BL_FAULT (19U)
 *   eIO_DIN_DI_SOC_FPDLINK3_LOCK (20U)
 *   eIO_DIN_DI_SOC_FPDLINK3_PASS (21U)
 *   eIO_DIN_DI_ENET_MII_INT (22U)
 *   eIO_DIN_DI_IGN_MON (23U)
 *   eIO_DIN_DI_CABLE_DETECT (24U)
 *   eIO_DIN_DI_TCON_IND_OUT (25U)
 *   eIO_DIN_DI_SPI_CAN_TCON_SDI (26U)
 *   eIO_DIN_DI_MCU_FALD_CONN_CHK (27U)
 *   eIO_DIN_DI_LDO_1V2_FAULTN (28U)
 *   eIO_DIN_DI_TFT_ER_DET (29U)
 * IoHwAb_ErrorType: Enumeration of integer in interval [2...13] with enumerators
 *   E_NO_ERROR (2U)
 *   E_ERROR (3U)
 *   E_ADC_ERROR (4U)
 *   E_DOUT_ID_INVALID (5U)
 *   E_DIN_ID_INVALID (6U)
 *   E_ADC_ID_INVALID (7U)
 *   IOHWAB_E_ADC_ERROR (8U)
 *   IOHWAB_E_ADC_ID_INVALID (9U)
 *   IOHWAB_E_ERROR (10U)
 *   IOHWAB_E_DOUT_ID_INVALID (11U)
 *   IOHWAB_E_NO_ERROR (12U)
 *   IOHWAB_E_DIN_ID_INVALID (13U)
 * VehicleActiveModes: Enumeration of integer in interval [0...2] with enumerators
 *   NETWORK_SLEEP (0U)
 *   NETWORK_NORMAL (1U)
 *   NETWORK_STANDALONE (2U)
 * tRxSafeSignalId: Enumeration of integer in interval [0...37] with enumerators
 *   eSCSBZRIn (0U)
 *   eSCSACCELIn (1U)
 *   ePBKLABIn (2U)
 *   eDBKLABIn (3U)
 *   eABIn (4U)
 *   eB_PKBLPIn (5U)
 *   eB_EPBWLIn (6U)
 *   eB_EPBMIDIn (7U)
 *   eB_CPKBIn (8U)
 *   eVSCOFFIn (9U)
 *   eVSCEXISTIn (10U)
 *   eTRCOFFIn (11U)
 *   eSLP_WLIn (12U)
 *   eMCBWIn (13U)
 *   eECBEXISTIn (14U)
 *   eEBW_MIDIn (15U)
 *   eBRK_MIDIn (16U)
 *   eBHEXISTIn (17U)
 *   eB_EBWIn (18U)
 *   eB_DAINDPIn (19U)
 *   eB_DAINDCIn (20U)
 *   eB_DACINDIn (21U)
 *   eB_BUZZERIn (22U)
 *   eB_BRLVIn (23U)
 *   eB_BRKWIn (24U)
 *   eB_ALSDIn (25U)
 *   eB_ABSIn (26U)
 *   eABS_MIDIn (27U)
 *   ePWIINFOIn (28U)
 *   eTRCCONRRIn (29U)
 *   eTRCCONRLIn (30U)
 *   eTRCCONFRIn (31U)
 *   eTRCCONFLIn (32U)
 *   eB_EBW2In (33U)
 *   eB_BUZZE2In (34U)
 *   eB_BRLV2In (35U)
 *   eB_BRKW2In (36U)
 *   eEndOfRxSafeSignal (37U)
 * tRxSafeSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 *
 *********************************************************************************************************************/


#define Mdl_SafetyAdapter_START_SEC_CODE
#include "Mdl_SafetyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_OnDataRx_B_EBW2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <B_EBW2> of PortPrototype <rp_SR_RxB_EBW2>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_B_EBW2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_B_EBW2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_B_EBW2
 *********************************************************************************************************************/

  Mdl_SafetyAdapter_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_OnDataRx_B_PKBLP
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <B_PKBLP> of PortPrototype <rp_SR_RxB_PKBLP>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_B_PKBLP_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_B_PKBLP(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_B_PKBLP
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_OnDataRx_SCSBZR
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SCSBZR> of PortPrototype <rp_SR_RxSCSBZR>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_SCSBZR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_SCSBZR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_SCSBZR
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_OnDataRx_VSCOFF
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSCOFF> of PortPrototype <rp_SR_RxVSCOFF>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_VSCOFF_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_VSCOFF(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_OnDataRx_VSCOFF
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalClearJustRcvdStatus> of PortPrototype <pp_SafetyAdapter_Just_Rxed_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus(tRxSafeSignalId SignalId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus(tRxSafeSignalId SignalId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalGetJustRcvdStatus> of PortPrototype <pp_SafetyAdapter_Just_Rxed_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus(tRxSafeSignalId SignalId, tRxSafeSignalJustRcvdStatus *pJustRcvdStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus(tRxSafeSignalId SignalId, P2VAR(tRxSafeSignalJustRcvdStatus, AUTOMATIC, RTE_MDL_SAFETYADAPTER_APPL_VAR) pJustRcvdStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_SafetyAdapter_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rp_SR_RxAB_AB(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxABS_MID_ABS_MID(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxBHEXIST_BHEXIST(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxBRK_MID_BRK_MID(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_ABS_B_ABS(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_ALSD_B_ALSD(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BRKW_B_BRKW(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BRKW2_B_BRKW2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BRLV_B_BRLV(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BRLV2_B_BRLV2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BUZZE2_B_BUZZE2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_BUZZER_B_BUZZER(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_CPKB_B_CPKB(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_DACIND_B_DACIND(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_DAINDC_B_DAINDC(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_DAINDP_B_DAINDP(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_EBW_B_EBW(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_EBW2_B_EBW2(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_EPBMID_B_EPBMID(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_EPBWL_B_EPBWL(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxB_PKBLP_B_PKBLP(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxDBKLAB_DBKLAB(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxEBW_MID_EBW_MID(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxECBEXIST_ECBEXIST(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxMCBW_MCBW(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxPBKLAB_PBKLAB(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxPWIINFO_PWIINFO(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxSCSACCEL_SCSACCEL(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxSCSBZR_SCSBZR(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxSLP_WL_SLP_WL(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTRCCONFL_TRCCONFL(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTRCCONFR_TRCCONFR(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTRCCONRL_TRCCONRL(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTRCCONRR_TRCCONRR(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTRCOFF_TRCOFF(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxVSCEXIST_VSCEXIST(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxVSCOFF_VSCOFF(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode(ClusterModes *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode(VehicleActiveModes data)
 *   Std_ReturnType Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate(IgntionSubstateType data)
 *   Std_ReturnType Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1(UInt8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_CommControlActivateRx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_CommControlActivateTx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_CommControlSetDone(Boolean PduInitRequest)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_ReleaseCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_CAN_RequestCommunication(UInt8 Channel)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_ComMExt_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpComMExt_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_IOHWab_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_IOHWab_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_IOHWab_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_IOHWab_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_CCtrl_Telltale_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_CView_Telltale_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Airbag_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_SafetyAdapter_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt8 Read_rp_SR_RxAB_AB;
  UInt8 Read_rp_SR_RxABS_MID_ABS_MID;
  UInt8 Read_rp_SR_RxBHEXIST_BHEXIST;
  UInt8 Read_rp_SR_RxBRK_MID_BRK_MID;
  UInt8 Read_rp_SR_RxB_ABS_B_ABS;
  UInt8 Read_rp_SR_RxB_ALSD_B_ALSD;
  UInt8 Read_rp_SR_RxB_BRKW_B_BRKW;
  UInt8 Read_rp_SR_RxB_BRKW2_B_BRKW2;
  UInt8 Read_rp_SR_RxB_BRLV_B_BRLV;
  UInt8 Read_rp_SR_RxB_BRLV2_B_BRLV2;
  UInt8 Read_rp_SR_RxB_BUZZE2_B_BUZZE2;
  UInt8 Read_rp_SR_RxB_BUZZER_B_BUZZER;
  UInt8 Read_rp_SR_RxB_CPKB_B_CPKB;
  UInt8 Read_rp_SR_RxB_DACIND_B_DACIND;
  UInt8 Read_rp_SR_RxB_DAINDC_B_DAINDC;
  UInt8 Read_rp_SR_RxB_DAINDP_B_DAINDP;
  UInt8 Read_rp_SR_RxB_EBW_B_EBW;
  UInt8 Read_rp_SR_RxB_EBW2_B_EBW2;
  UInt8 Read_rp_SR_RxB_EPBMID_B_EPBMID;
  UInt8 Read_rp_SR_RxB_EPBWL_B_EPBWL;
  UInt8 Read_rp_SR_RxB_PKBLP_B_PKBLP;
  UInt8 Read_rp_SR_RxDBKLAB_DBKLAB;
  UInt8 Read_rp_SR_RxEBW_MID_EBW_MID;
  UInt8 Read_rp_SR_RxECBEXIST_ECBEXIST;
  UInt8 Read_rp_SR_RxMCBW_MCBW;
  UInt8 Read_rp_SR_RxPBKLAB_PBKLAB;
  UInt8 Read_rp_SR_RxPWIINFO_PWIINFO;
  UInt8 Read_rp_SR_RxSCSACCEL_SCSACCEL;
  UInt8 Read_rp_SR_RxSCSBZR_SCSBZR;
  UInt8 Read_rp_SR_RxSLP_WL_SLP_WL;
  UInt8 Read_rp_SR_RxTRCCONFL_TRCCONFL;
  UInt8 Read_rp_SR_RxTRCCONFR_TRCCONFR;
  UInt8 Read_rp_SR_RxTRCCONRL_TRCCONRL;
  UInt8 Read_rp_SR_RxTRCCONRR_TRCCONRR;
  UInt8 Read_rp_SR_RxTRCOFF_TRCOFF;
  UInt8 Read_rp_SR_RxVSCEXIST_VSCEXIST;
  UInt8 Read_rp_SR_RxVSCOFF_VSCOFF;
  ClusterModes Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode;

  UInt8 Call_rpComMExt_CAN_GetCurrentComMode_ComMode = 0U;
  Boolean Call_rpComMExt_GetBusOffStatus_BusOffStatus = FALSE;
  Boolean Call_rpComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL = FALSE;
  Boolean Call_rp_IOHWab_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rp_IOHWab_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rp_IOHWab_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rp_IOHWab_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rp_IOHWab_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rp_IOHWab_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rp_IOHWab_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rp_IOHWab_Din_GetSyncRawInput_ErrorStatus = 0U;
  UInt16 Call_rp_IoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rp_IoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rp_IoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rp_IoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rp_IoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rp_IoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxAB_AB(&Read_rp_SR_RxAB_AB);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxABS_MID_ABS_MID(&Read_rp_SR_RxABS_MID_ABS_MID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxBHEXIST_BHEXIST(&Read_rp_SR_RxBHEXIST_BHEXIST);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxBRK_MID_BRK_MID(&Read_rp_SR_RxBRK_MID_BRK_MID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_ABS_B_ABS(&Read_rp_SR_RxB_ABS_B_ABS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_ALSD_B_ALSD(&Read_rp_SR_RxB_ALSD_B_ALSD);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRKW_B_BRKW(&Read_rp_SR_RxB_BRKW_B_BRKW);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRKW2_B_BRKW2(&Read_rp_SR_RxB_BRKW2_B_BRKW2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRLV_B_BRLV(&Read_rp_SR_RxB_BRLV_B_BRLV);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRLV2_B_BRLV2(&Read_rp_SR_RxB_BRLV2_B_BRLV2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BUZZE2_B_BUZZE2(&Read_rp_SR_RxB_BUZZE2_B_BUZZE2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BUZZER_B_BUZZER(&Read_rp_SR_RxB_BUZZER_B_BUZZER);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_CPKB_B_CPKB(&Read_rp_SR_RxB_CPKB_B_CPKB);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DACIND_B_DACIND(&Read_rp_SR_RxB_DACIND_B_DACIND);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DAINDC_B_DAINDC(&Read_rp_SR_RxB_DAINDC_B_DAINDC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DAINDP_B_DAINDP(&Read_rp_SR_RxB_DAINDP_B_DAINDP);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EBW_B_EBW(&Read_rp_SR_RxB_EBW_B_EBW);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EBW2_B_EBW2(&Read_rp_SR_RxB_EBW2_B_EBW2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EPBMID_B_EPBMID(&Read_rp_SR_RxB_EPBMID_B_EPBMID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EPBWL_B_EPBWL(&Read_rp_SR_RxB_EPBWL_B_EPBWL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_PKBLP_B_PKBLP(&Read_rp_SR_RxB_PKBLP_B_PKBLP);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxDBKLAB_DBKLAB(&Read_rp_SR_RxDBKLAB_DBKLAB);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxEBW_MID_EBW_MID(&Read_rp_SR_RxEBW_MID_EBW_MID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxECBEXIST_ECBEXIST(&Read_rp_SR_RxECBEXIST_ECBEXIST);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxMCBW_MCBW(&Read_rp_SR_RxMCBW_MCBW);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxPBKLAB_PBKLAB(&Read_rp_SR_RxPBKLAB_PBKLAB);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxPWIINFO_PWIINFO(&Read_rp_SR_RxPWIINFO_PWIINFO);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSCSACCEL_SCSACCEL(&Read_rp_SR_RxSCSACCEL_SCSACCEL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSCSBZR_SCSBZR(&Read_rp_SR_RxSCSBZR_SCSBZR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSLP_WL_SLP_WL(&Read_rp_SR_RxSLP_WL_SLP_WL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONFL_TRCCONFL(&Read_rp_SR_RxTRCCONFL_TRCCONFL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONFR_TRCCONFR(&Read_rp_SR_RxTRCCONFR_TRCCONFR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONRL_TRCCONRL(&Read_rp_SR_RxTRCCONRL_TRCCONRL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONRR_TRCCONRR(&Read_rp_SR_RxTRCCONRR_TRCCONRR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCOFF_TRCOFF(&Read_rp_SR_RxTRCOFF_TRCOFF);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxVSCEXIST_VSCEXIST(&Read_rp_SR_RxVSCEXIST_VSCEXIST);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxVSCOFF_VSCOFF(&Read_rp_SR_RxVSCOFF_VSCOFF);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode(&Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode(Rte_InitValue_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(Rte_InitValue_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate(Rte_InitValue_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1(Rte_InitValue_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1(Rte_InitValue_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlActivateRx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlActivateTx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlSetDone(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_GetCurrentComMode(0U, &Call_rpComMExt_CAN_GetCurrentComMode_ComMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_ReleaseCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_RequestCommunication(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_GetBusOffStatus(0U, &Call_rpComMExt_GetBusOffStatus_BusOffStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(&Call_rpComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_ComMExt_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_Init();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetAsyncRawInput(0U, &Call_rp_IOHWab_Din_GetAsyncRawInput_AsyncInput, &Call_rp_IOHWab_Din_GetAsyncRawInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetInputGroup(0, &Call_rp_IOHWab_Din_GetInputGroup_SyncInput, &Call_rp_IOHWab_Din_GetInputGroup_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetProcessedInput(0U, &Call_rp_IOHWab_Din_GetProcessedInput_InputSignal, &Call_rp_IOHWab_Din_GetProcessedInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetSyncRawInput(0U, &Call_rp_IOHWab_Din_GetSyncRawInput_SyncInput, &Call_rp_IOHWab_Din_GetSyncRawInput_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_CCtrl_Telltale_Init();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_CView_Telltale_Init();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_Mdl_Airbag_Init();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rp_IoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rp_IoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(0U, &Call_rp_IoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rp_IoHwAb_ADC_GetProcessedAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc(0U, &Call_rp_IoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rp_IoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Mdl_SafetyAdapter_STOP_SEC_CODE
#include "Mdl_SafetyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Mdl_SafetyAdapter_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_1 = eIO_ADC_ADC_FUEL_5V_MON;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_2 = eIO_ADC_ADC_FUEL_MAIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_3 = eIO_ADC_IGN_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_4 = eIO_ADC_FUEL_SEND_SUB_MICRO_AD;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_5 = eIO_ADC_AI_BATTERY;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_6 = eIO_ADC_AI_LCD_NTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_7 = eIO_ADC_AI_TEMP_RTC;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_8 = eIO_ADC_Flasher_Diag_sense_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_9 = eIO_ADC_STR_SW2_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_10 = eIO_ADC_STR_SW1_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_11 = eIO_ADC_RHEO_SW_IN_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_12 = eIO_ADC_ADC_RHEO_5V_MON_ADIN;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_13 = eIO_ADC_Flasher_Diag_sense_2;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_14 = eIO_ADC_AdcChannel_Vdb;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_15 = eIO_ADC_AdcChannel_Vtemp;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_16 = eIO_ADC_MAX;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_17 = eIO_ADC_AI_SAMPLE_1;
  IoHwAb_AdcSignalIdType Test_IoHwAb_AdcSignalIdType_V_18 = eIO_ADC_AI_SAMPLE_2;

  IoHwAb_DInGroupIdType Test_IoHwAb_DInGroupIdType_V_1 = eIO_DInGroupIdCount;

  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_1 = eIO_DIN_DI_AL_HAZARD;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_2 = eIO_DIN_DI_AH_IGNITION;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_3 = eIO_DIN_DI_SMPS_3V3_PG;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_4 = eIO_DIN_STOP_LAMP_MCU;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_5 = eIO_DIN_DI_AL_BRAKE_LEVEL;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_6 = eIO_DIN_DI_AL_OIL_W;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_7 = eIO_DIN_DI_AL_DRV_SEAT_BUCKLE;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_8 = eIO_DIN_DI_AL_WASHER_LEVEL_SW;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_9 = eIO_DIN_ODO_TripKnobInput;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_10 = eIO_DIN_DI_AL_VACUUM;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_11 = eIO_DIN_DI_LCD_BL_PWR_FAULT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_12 = eIO_DIN_DI_AL_FUEL_LID_EFI_ECU;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_13 = eIO_DIN_DI_TT_SHIFT_ERR;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_14 = eIO_DIN_MAX;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_15 = eIO_DIN_DI_PMIC_INTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_16 = eIO_DIN_DI_MCU_PORZ;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_17 = eIO_DIN_DI_SBATT2_ERR;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_18 = eIO_DIN_DI_FALD_PG;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_19 = eIO_DIN_DI_MD_TOUCH_INTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_20 = eIO_DIN_DI_BL_FAULT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_21 = eIO_DIN_DI_SOC_FPDLINK3_LOCK;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_22 = eIO_DIN_DI_SOC_FPDLINK3_PASS;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_23 = eIO_DIN_DI_ENET_MII_INT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_24 = eIO_DIN_DI_IGN_MON;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_25 = eIO_DIN_DI_CABLE_DETECT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_26 = eIO_DIN_DI_TCON_IND_OUT;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_27 = eIO_DIN_DI_SPI_CAN_TCON_SDI;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_28 = eIO_DIN_DI_MCU_FALD_CONN_CHK;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_29 = eIO_DIN_DI_LDO_1V2_FAULTN;
  IoHwAb_DInSignalIdType Test_IoHwAb_DInSignalIdType_V_30 = eIO_DIN_DI_TFT_ER_DET;

  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_1 = E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_2 = E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_3 = E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_4 = E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_5 = E_DIN_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_6 = E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_7 = IOHWAB_E_ADC_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_8 = IOHWAB_E_ADC_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_9 = IOHWAB_E_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_10 = IOHWAB_E_DOUT_ID_INVALID;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_11 = IOHWAB_E_NO_ERROR;
  IoHwAb_ErrorType Test_IoHwAb_ErrorType_V_12 = IOHWAB_E_DIN_ID_INVALID;

  VehicleActiveModes Test_VehicleActiveModes_V_1 = NETWORK_SLEEP;
  VehicleActiveModes Test_VehicleActiveModes_V_2 = NETWORK_NORMAL;
  VehicleActiveModes Test_VehicleActiveModes_V_3 = NETWORK_STANDALONE;

  tRxSafeSignalId Test_tRxSafeSignalId_V_1 = eSCSBZRIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_2 = eSCSACCELIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_3 = ePBKLABIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_4 = eDBKLABIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_5 = eABIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_6 = eB_PKBLPIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_7 = eB_EPBWLIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_8 = eB_EPBMIDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_9 = eB_CPKBIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_10 = eVSCOFFIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_11 = eVSCEXISTIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_12 = eTRCOFFIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_13 = eSLP_WLIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_14 = eMCBWIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_15 = eECBEXISTIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_16 = eEBW_MIDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_17 = eBRK_MIDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_18 = eBHEXISTIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_19 = eB_EBWIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_20 = eB_DAINDPIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_21 = eB_DAINDCIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_22 = eB_DACINDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_23 = eB_BUZZERIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_24 = eB_BRLVIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_25 = eB_BRKWIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_26 = eB_ALSDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_27 = eB_ABSIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_28 = eABS_MIDIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_29 = ePWIINFOIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_30 = eTRCCONRRIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_31 = eTRCCONRLIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_32 = eTRCCONFRIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_33 = eTRCCONFLIn;
  tRxSafeSignalId Test_tRxSafeSignalId_V_34 = eB_EBW2In;
  tRxSafeSignalId Test_tRxSafeSignalId_V_35 = eB_BUZZE2In;
  tRxSafeSignalId Test_tRxSafeSignalId_V_36 = eB_BRLV2In;
  tRxSafeSignalId Test_tRxSafeSignalId_V_37 = eB_BRKW2In;
  tRxSafeSignalId Test_tRxSafeSignalId_V_38 = eEndOfRxSafeSignal;

  tRxSafeSignalJustRcvdStatus Test_tRxSafeSignalJustRcvdStatus_V_1 = eJust_Received;
  tRxSafeSignalJustRcvdStatus Test_tRxSafeSignalJustRcvdStatus_V_2 = eNot_Just_Received;
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
