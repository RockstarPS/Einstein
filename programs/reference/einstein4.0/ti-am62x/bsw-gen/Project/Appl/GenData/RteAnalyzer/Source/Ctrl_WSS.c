/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ctrl_WSS.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Ctrl_WSS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Ctrl_WSS>
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

#include "Rte_Ctrl_WSS.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Ctrl_WSS.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Ctrl_WSS_TestDefines(void);


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
 * Rte_DT_TTBlinkArray_0: Integer in interval [0...255]
 * Rte_DT_TT_OP_Type_0: Integer in interval [0...255]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * BOOL_TYPE: Enumeration of integer in interval [0...1] with enumerators
 *   DBG_TRUE (0U)
 *   DBG_FALSE (1U)
 * ClusterInitModes: Enumeration of integer in interval [0...2] with enumerators
 *   CLUSTER_INIT (0U)
 *   CLUSTER_RUN (1U)
 *   CLUSTER_RUN_READALL (2U)
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * DisplayStatus: Enumeration of integer in interval [0...1] with enumerators
 *   TFTDisplayOFF (0U)
 *   TFTDisplayON (1U)
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 *   eHMI_NOT_READY (0U)
 *   eHMI_READY (1U)
 * HMI_Odo_Type: Enumeration of integer in interval [0...10] with enumerators
 *   eODO_TYPE_OFF (0U)
 *   eODO_TYPE_BLANK (1U)
 *   eODO_TYPE_ODO (2U)
 *   eODO_TYPE_TRIPA (3U)
 *   eODO_TYPE_TRIPB (4U)
 *   eODO_TYPE_OILMIL_DISTANCE (5U)
 *   eODO_TYPE_FUEL_OW_ADV_NOTICE (6U)
 *   eODO_TYPE_FUEL_OVER_WRITE (7U)
 *   eODO_TYPE_POWER_STATUS_ACC (8U)
 *   eODO_TYPE_POWER_STATUS_ON (9U)
 *   eODO_TYPE_OILMIL_DISTANCE_INT (10U)
 * HMI_Screen_Mode: Enumeration of integer in interval [0...9] with enumerators
 *   eSCREENMODE_OFF (0U)
 *   eSCREENMODE_BLANK (1U)
 *   eSCREENMODE_NORMAL (2U)
 *   eSCREENMODE_DISPLAY_ADJ (3U)
 *   eSCREENMODE_WELCOME (4U)
 *   eSCREENMODE_IGNOFF_CHR (5U)
 *   eSCREENMODE_OPENING (6U)
 *   eSCREENMODE_ENDING (7U)
 *   eSCREENMODE_ENDING_IGNOFF_CHR (8U)
 *   eSCREENMODE_RESERVED (9U)
 * HTimer: Enumeration of integer in interval [0...80] with enumerators
 *   eWarningMask_Timerhandle (0U)
 *   eOWC_Timerhandle (1U)
 *   eNWD_Timerhandle (2U)
 *   eWarningBulbCheckMask_Timerhandle (3U)
 *   eInitWarning_TimerHandle (4U)
 *   eInitChimeTimerHandle (5U)
 *   eProgrammingTimerHandle (6U)
 *   eStubCounter_TimerHanlde (7U)
 *   eModeMgrDisplayPowerDownUp (8U)
 *   eModeMgrDisplayFaultAction (9U)
 *   eModeMgrDomanResetAction (10U)
 *   eModeMgrPowerFaultAction (11U)
 *   eEtm4SecTimer (12U)
 *   eEtm1200msecTimer (13U)
 *   eEtm3SecTimer (14U)
 *   eCallbackTimerOdoMdl (15U)
 *   eThrottleTimerOdoMdl (16U)
 *   eChangeupCallbackTimerodoMdl (17U)
 *   eTimerVehicleState (18U)
 *   eTimerVariantConfig (19U)
 *   WARNING_DISPLAY_TIMER_ID (20U)
 *   WARNING_HOLD_TIMER_ID (21U)
 *   WARNING_CYCLE_TIMER_ID (22U)
 *   WARNING_DISPLAYHOLD_TIMER_ID (23U)
 *   WARNING_ACK_TIMER_ID (24U)
 *   eTimerHandle_Sleep (25U)
 *   eInStartCount_TimerHandle (26U)
 *   eVehicleModeCount_TimerHandle (27U)
 *   e10secTimer (28U)
 *   e3secTimer (29U)
 *   e30secTimer (30U)
 *   e2_6secTimer (31U)
 *   eDcmApp5secTimer (32U)
 *   eDcmApp1secTimer (33U)
 *   eLidopen_OFFTimer (34U)
 *   eLidopen_ONTimer (35U)
 *   POPUP_DISPLAY_TIMER_ID (36U)
 *   POPUP_GRP_TAB_TIMER_ID (37U)
 *   eDrvRec5_6Timer (38U)
 *   eDrvRec3_6Timer (39U)
 *   eIDS_1SecTimer (40U)
 *   eIDS3_1SecTimer (41U)
 *   eIDS_3SecTimer (42U)
 *   ePerDispSet100msTimer (43U)
 *   eDrvRec1_2secTimer (44U)
 *   eDrvRec0_8secTimer (45U)
 *   eHMI_Initial_Blank_timer_ID (46U)
 *   eHMI_Fade_in_delay_timer_ID (47U)
 *   eKM6secTimer (48U)
 *   eKM5_8secTimer (49U)
 *   eKM0_6secTimer (50U)
 *   eKM0_2secTimer (51U)
 *   eIgnCANMode_3SecTimer (52U)
 *   eDem2_6secTimer (53U)
 *   eDem5secTimer (54U)
 *   e2FRheo5secTimer (55U)
 *   e2FSTSW5secTimer (56U)
 *   eLSTM3_Timer (57U)
 *   eLSTM4_Timer (58U)
 *   eDem_AFS_5sec_Timer (59U)
 *   WARNING_MSGTIMEOUT_1SEC_TIMER_ID (60U)
 *   eDCMApp_30Sec_Timer (61U)
 *   WRN_ACK_REDISPLAY_TIMER_ID (62U)
 *   eMenuScrollStart1sTimer (63U)
 *   eType4_6secTimer (64U)
 *   eDcmApp_0_35secTimer (65U)
 *   eDcmApp_0_35_1secTimer (66U)
 *   eRemoteCarFindCtrlStateTimer (67U)
 *   eBrake_Red_100msecTimer (68U)
 *   eStreeingSw_ReleaseTimer (69U)
 *   POPUP_SETTING_TIMER_ID (70U)
 *   eMenu100msTimer (71U)
 *   eBuzzerMiddleEast_6secs (72U)
 *   eBuzzerMiddleEast_6secs_2 (73U)
 *   eMaxNumof16BitTimers (74U)
 *   eSleepMaxTimer (75U)
 *   eRentACarTimer (76U)
 *   eDoorWarn_Timer (77U)
 *   eTimerHandleGdtCdd (78U)
 *   eSample32BitTimer (79U)
 *   eTimerMax (80U)
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
 * ModeStatus: Enumeration of integer in interval [0...1] with enumerators
 *   STATUS_OFF (0U)
 *   STATUS_ON (1U)
 * SleepType: Enumeration of integer in interval [0...1] with enumerators
 *   SLEEEP_READY (0U)
 *   SLEEP_NOT_READY (1U)
 * TTFlashMask: Enumeration of integer in interval [0...4] with enumerators
 *   NOT_IN_SYNCH (0U)
 *   FLASH_180DEG_PHASE_SYNCH (1U)
 *   FLASH_360DEG_PHASE_SYNCH (2U)
 *   FLASH_OFF_PERIOD_MASK (4U)
 * TT_ENUM_TYPE: Enumeration of integer in interval [0...92] with enumerators
 *   TT_ABS_INDEX (0U)
 *   TT_AIRBAG_INDEX (1U)
 *   TT_BRAKE_RED_INDEX (2U)
 *   TT_BRAKE_HOLD_INDEX (3U)
 *   TT_BRAKE_YELLOW_INDEX (4U)
 *   TT_PARKING_BRAKE_INDEX (5U)
 *   TT_TRACTION_CTRL_INDEX (6U)
 *   TT_VCS_OFF_INDEX (7U)
 *   TT_ABS_INDEX_US (8U)
 *   TT_BRAKE_RED_INDEX_US (9U)
 *   TT_PARKING_BRAKE_INDEX_US (10U)
 *   TT_SAF_RES4_INDEX (11U)
 *   TT_SAF_RES5_INDEX (12U)
 *   TT_SAF_RES6_INDEX (13U)
 *   TT_SAF_RES7_INDEX (14U)
 *   TT_SAF_RES8_INDEX (15U)
 *   TT_ADAS_INDEX (16U)
 *   TT_AUTO_HIGH_BEAM_INDEX (17U)
 *   TT_BRAKE_HOLD_STANDBY_INDEX (18U)
 *   TT_FUEL_INDEX (19U)
 *   TT_FFOG_INDEX (20U)
 *   TT_HEAD_INDEX (21U)
 *   TT_HIGH_BEAM_INDEX (22U)
 *   TT_PCS_OFF_INDEX (23U)
 *   TT_READY_INDEX (24U)
 *   TT_RFOG_INDEX (25U)
 *   TT_SEAT_BELT_INDEX (26U)
 *   TT_TAIL_LIGHT_INDEX (27U)
 *   TT_TURN_HAZARD_RIGHT_INDEX (28U)
 *   TT_TURN_HAZARD_LEFT_INDEX (29U)
 *   TT_EWT_INDEX (30U)
 *   TT_AAHB_LO_GREEN (31U)
 *   TT_AAHB_SHADED_GREEN (32U)
 *   TT_AAHB_HI_GREEN (33U)
 *   TT_AAHB_HI_WHITE (34U)
 *   TT_ITS_INFRA (35U)
 *   TT_ITS_VEHICLE (36U)
 *   TT_ITS_COMBINATION (37U)
 *   TT_SSS_GREEN (38U)
 *   TT_SSS_AMBER (39U)
 *   TT_LCA_LEFT_WHITE (40U)
 *   TT_LCA_LEFT_GRAY (41U)
 *   TT_LCA_LEFT_GREEN (42U)
 *   TT_LCA_RIGHT_WHITE (43U)
 *   TT_LCA_RIGHT_GRAY (44U)
 *   TT_LCA_RIGHT_GREEN (45U)
 *   TT_LTA_GREEN (46U)
 *   TT_LTA_WHITE (47U)
 *   TT_LTA_AMBER (48U)
 *   TT_CCT_GREEN (49U)
 *   TT_CCT_WHITE (50U)
 *   TT_CCT_AMBER (51U)
 *   TT_RCCT_GREEN (52U)
 *   TT_RCCT_WHITE (53U)
 *   TT_RCCT_AMBER (54U)
 *   TT_ACCDT_WHITE_LV4 (55U)
 *   TT_ACCDT_WHITE_LV3 (56U)
 *   TT_ACCDT_WHITE_LV2 (57U)
 *   TT_ACCDT_WHITE_LV1 (58U)
 *   TT_ACCDT_GREEN_LV4 (59U)
 *   TT_ACCDT_GREEN_LV3 (60U)
 *   TT_ACCDT_GREEN_LV2 (61U)
 *   TT_ACCDT_GREEN_LV1 (62U)
 *   TT_SL_GREEN (63U)
 *   TT_SL_WHITE (64U)
 *   TT_SL_AMBER (65U)
 *   TT_AUTO_LSD_AMBER (66U)
 *   TT_DRIVEMODE_SPORT (67U)
 *   TT_DRIVEMODE_ECO (68U)
 *   TT_DRIVEMODE_CUSTOM (69U)
 *   TT_DRIVEMODE_RANGE (70U)
 *   TT_DRIVEMODE_REARCOMFORT (71U)
 *   TT_DRIVEMODE_SNOW (72U)
 *   TT_DRIVEMODE_TRACK (73U)
 *   TT_LDA_RED (74U)
 *   TT_LDA_AMBER (75U)
 *   TT_LDA_WHITE (76U)
 *   TT_LDA_OFF_AMBER (77U)
 *   TT_LDA_OFF_WHITE (78U)
 *   TT_ECOLAMP (79U)
 *   TT_PS_GREEN (80U)
 *   TT_PKBOPER_TXT (81U)
 *   TT_PKBOPER_IMG (82U)
 *   TT_TPMS_INDEX (83U)
 *   TT_EBPWIND_RED_US (84U)
 *   TT_EBPWIND_RED (85U)
 *   TT_FMSR_AMBER (86U)
 *   TT_FMFR_AMBER (87U)
 *   TT_MULWL_GREEN (88U)
 *   TT_HCS_ACCESS_GREEN (89U)
 *   TT_HCS_LIFT_GREEN (90U)
 *   TT_HCS_LIFT_AMBER (91U)
 *   TT_TOTAL_NUM_OF_TELLTALES (92U)
 * TT_OP_STATES: Enumeration of integer in interval [0...255] with enumerators
 *   TT_TURN_OFF (0U)
 *   TT_TURN_ON (1U)
 *   TT_FLASH_QUARTER_HZ (2U)
 *   TT_FLASH_HALF_HZ (3U)
 *   TT_FLASH_CSNR_HALF_HZ (4U)
 *   TT_FLASH_0_83_HZ (5U)
 *   TT_FLASH_1HZ (6U)
 *   TT_FLASH_1_33_HZ (7U)
 *   TT_FLASH_1_66_HZ (8U)
 *   TT_FLASH_2HZ (9U)
 *   TT_FLASH_2_5_HZ (10U)
 *   TT_FLASH_2_66_HZ (11U)
 *   TT_FLASH_TRNHZ_Normal (12U)
 *   TT_FLASH_TRNHZ_Fast (13U)
 *   TT_FLASH_TRNHZ_FHL (14U)
 *   TT_FLASH_3HZ (15U)
 *   TT_FLASH_4HZ (16U)
 *   TT_FLASH_5HZ (17U)
 *   TT_FLASH_SYNC_QUARTER_HZ (18U)
 *   TT_FLASH_SYNC_HALF_HZ (19U)
 *   TT_FLASH_SYNC_CSNR_HALF_HZ (20U)
 *   TT_FLASH_SYNC_0_83_HZ (21U)
 *   TT_FLASH_SYNC_1HZ (22U)
 *   TT_FLASH_SYNC_1_33_HZ (23U)
 *   TT_FLASH_SYNC_1_66_HZ (24U)
 *   TT_FLASH_SYNC_2HZ (25U)
 *   TT_FLASH_SYNC_2_5_HZ (26U)
 *   TT_FLASH_SYNC_2_66_HZ (27U)
 *   TT_FLASH_TRNHZ_SYNC_Normal (28U)
 *   TT_FLASH_TRNHZ_SYNC_Fast (29U)
 *   TT_FLASH_TRNHZ_SYNC_FHL (30U)
 *   TT_FLASH_SYNC_4HZ (31U)
 *   TT_FLASH_SYNC_5HZ (32U)
 *   TT_CONFIGURED_OFF (255U)
 * TurnStates: Enumeration of integer in interval [0...2] with enumerators
 *   TurnOff (0U)
 *   TurnOn (1U)
 *   TurnBlink (2U)
 * VehicleActiveModes: Enumeration of integer in interval [0...2] with enumerators
 *   NETWORK_SLEEP (0U)
 *   NETWORK_NORMAL (1U)
 *   NETWORK_STANDALONE (2U)
 * eAppMdl: Enumeration of integer in interval [0...11] with enumerators
 *   eSWCApp_SmartKey_Bzr (0U)
 *   eSWCApp_Warn_MFLID (1U)
 *   eSWCApp_Head_TT (2U)
 *   eSWCApp_Tail_TT (3U)
 *   eSWCApp_Fuel (4U)
 *   eSWCApp_Illum (5U)
 *   eSWCApp_Buzzer (6U)
 *   eSWCApp_NVM (7U)
 *   eTFTDisplayOnExceptTurn (8U)
 *   eTurnL_Status (9U)
 *   eTurnR_Status (10U)
 *   eSWCApp_End (11U)
 * eSleepSt: Enumeration of integer in interval [0...1] with enumerators
 *   eSleep_Inactive (0U)
 *   eISleep_Active (1U)
 * tRxSignalId: Enumeration of integer in interval [0...12] with enumerators
 *   eDayNightModeIn (0U)
 *   eIllumination_levelIn (1U)
 *   eAmbient_Light_levelIn (2U)
 *   ePowerModeIn (3U)
 *   eTransportModeIn (4U)
 *   eGearModeIn (5U)
 *   eGearRecommendationIn (6U)
 *   eGearIn (7U)
 *   eWarningIn (8U)
 *   eGearStatusIn (9U)
 *   eEngineSpeedIn (10U)
 *   eTurn_Indicator_ControlIn (11U)
 *   eEndOfRxSignal (12U)
 * tRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tRxSignalStatus: Enumeration of integer in interval [0...4] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (4U)
 *
 * Array Types:
 * ============
 * TTBlinkArray: Array with 16 element(s) of type Rte_DT_TTBlinkArray_0
 * TT_OP_Type: Array with 92 element(s) of type Rte_DT_TT_OP_Type_0
 *
 * Record Types:
 * =============
 * SMainHMIReadyStatus: Record with elements
 *   status of type UInt8
 *
 *********************************************************************************************************************/


#define Ctrl_WSS_START_SEC_CODE
#include "Ctrl_WSS_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlWSS_CancelSleep
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CtrlWSS_CancelSleep> of PortPrototype <pp_SleepOperation>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CtrlWSS_CancelSleep(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_CancelSleep_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_CancelSleep(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_CancelSleep (returns application error)
 *********************************************************************************************************************/

  Ctrl_WSS_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlWSS_ReadytoSleep
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CtrlWSS_ReadytoSleep> of PortPrototype <pp_SleepOperation>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CtrlWSS_ReadytoSleep(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_ReadytoSleep_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_ReadytoSleep(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_ReadytoSleep (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlWSS_RequestSleep
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CtrlWSS_RequestSleep> of PortPrototype <pp_SleepOperation>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CtrlWSS_RequestSleep(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_RequestSleep_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ctrl_WSS_CODE) CtrlWSS_RequestSleep(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlWSS_RequestSleep (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_CtrlWSS_NotifyNetworkSleep
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CtrlWSS_NotifyNetworkSleep> of PortPrototype <pp_NotifySleepStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ctrl_WSS_CtrlWSS_NotifyNetworkSleep(UInt8 *NotifyStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_WSS_SWCNotifySleepStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_CtrlWSS_NotifyNetworkSleep_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ctrl_WSS_CODE) Ctrl_WSS_CtrlWSS_NotifyNetworkSleep(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) NotifyStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_CtrlWSS_NotifyNetworkSleep (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_GetVariant_Status
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVariant_Status> of PortPrototype <pp_Variant_status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ctrl_WSS_GetVariant_Status(UInt8 Variant_Ind, UInt8 *Variant_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_GetVariant_Status_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_GetVariant_Status(UInt8 Variant_Ind, P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) Variant_Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_GetVariant_Status
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_Impl_MainFunction
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
 *   Std_ReturnType Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(BOOL_TYPE *data)
 *   Std_ReturnType Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus(BOOL_TYPE *data)
 *   Std_ReturnType Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(Boolean *data)
 *   Std_ReturnType Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(Boolean *data)
 *   Std_ReturnType Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(Boolean *data)
 *   Std_ReturnType Rte_Read_rpTTStsData_TTIndex(TT_ENUM_TYPE *data)
 *   Std_ReturnType Rte_Read_rpTTStsData_TTStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *   Std_ReturnType Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray(Rte_DT_TTBlinkArray_0 *data)
 *     Argument data: Rte_DT_TTBlinkArray_0* is of type TTBlinkArray
 *   Std_ReturnType Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes(TTFlashMask *data)
 *   Std_ReturnType Rte_Read_rp_HMIOdo_Type_HMI_OdoType(HMI_Odo_Type *data)
 *   Std_ReturnType Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
 *   Std_ReturnType Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_IlumDayNightStatus_illumDNStatus(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_Tail_Light_Status_Tail_Light_st(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(TurnStates *data)
 *   Std_ReturnType Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(TurnStates *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppAccModeState_WSSAccState(ModeStatus data)
 *   Std_ReturnType Rte_Write_ppBaModeState_WSSBaState(ModeStatus data)
 *   Std_ReturnType Rte_Write_ppBaOfModeState_WSSBaOfState(ModeStatus data)
 *   Std_ReturnType Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate(IgntionSubstateType data)
 *   Std_ReturnType Rte_Write_ppIgnSubstate_IgnitionSubstate(IgntionSubstateType data)
 *   Std_ReturnType Rte_Write_ppIgpCANModeState_WSSIGPCANState(ModeStatus data)
 *   Std_ReturnType Rte_Write_ppIgpModeState_WSSIGPState(ModeStatus data)
 *   Std_ReturnType Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(ClusterModes data)
 *   Std_ReturnType Rte_Write_pp_HMIReady_HMI_ReadyStatus(HMIReadySts_Type data)
 *   Std_ReturnType Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(ClusterInitModes data)
 *   Std_ReturnType Rte_Write_pp_SleepStatus_Sleep_Status(SleepType data)
 *   Std_ReturnType Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(DisplayStatus data)
 *   Std_ReturnType Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(DisplayStatus data)
 *   Std_ReturnType Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes data)
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
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Boolean *Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(HTimer hTimer)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(HTimer hTimer)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_View_Speed_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BOOL_TYPE Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus;
  BOOL_TYPE Receive_rpCS_EcuMExt_HazardStatus_HazardStatus;
  SMainHMIReadyStatus Receive_rpUclHMIReadySts_MainHMIReadyStatusData;
  Boolean Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted;
  Boolean Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted;
  Boolean Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted;
  TT_ENUM_TYPE Read_rpTTStsData_TTIndex;
  TT_OP_STATES Read_rpTTStsData_TTStatus;
  TT_OP_Type Read_rpTelltaleStatusOP_TelltaleOpArray;
  TTBlinkArray Read_rp_BlinkStsArray_TTBlinkStatusArray;
  TTFlashMask Read_rp_BlinkStsArray_TTdummyDataForTypes;
  HMI_Odo_Type Read_rp_HMIOdo_Type_HMI_OdoType;
  HMI_Screen_Mode Read_rp_HMIScreenMode_HMIScreenMode_Status;
  UInt8 Read_rp_Head_Lamp_Status_Head_Lamp_st;
  UInt8 Read_rp_IlumDayNightStatus_illumDNStatus;
  UInt8 Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc;
  UInt8 Read_rp_ShiftPositionDisp_ShiftPositionDisplay;
  UInt8 Read_rp_Tail_Light_Status_Tail_Light_st;
  TurnStates Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts;
  TurnStates Read_rp_TurnHzdTurnR_Status_RightIndicatorSts;

  UInt8 Call_rpComMExt_CAN_GetCurrentComMode_ComMode = 0U;
  Boolean Call_rpComMExt_GetBusOffStatus_BusOffStatus = FALSE;
  Boolean Call_rpComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL = FALSE;
  UInt16 Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus = 0U;
  SInt32 Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc = 0;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus = 0U;
  UInt16 Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus = 0U;
  UInt32 Call_rpIoHwAb_Din_GetInputGroup_SyncInput = 0U;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetProcessedInput_InputSignal = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus = 0U;
  Boolean Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput = FALSE;
  IoHwAb_ErrorType Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus = 0U;
  UInt8 Call_rp_CS_ComAbsRx_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_ComAbsRx_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  Boolean Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus_Status = FALSE;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  Boolean Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed_IsElapsed = FALSE;
  Boolean Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted_IsStarted = FALSE;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(&Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus(&Receive_rpCS_EcuMExt_HazardStatus_HazardStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(&Receive_rpUclHMIReadySts_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(&Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(&Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(&Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTIndex(&Read_rpTTStsData_TTIndex);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTStatus(&Read_rpTTStsData_TTStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Read_rpTelltaleStatusOP_TelltaleOpArray);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray(Read_rp_BlinkStsArray_TTBlinkStatusArray);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes(&Read_rp_BlinkStsArray_TTdummyDataForTypes);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_HMIOdo_Type_HMI_OdoType(&Read_rp_HMIOdo_Type_HMI_OdoType);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(&Read_rp_HMIScreenMode_HMIScreenMode_Status);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st(&Read_rp_Head_Lamp_Status_Head_Lamp_st);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_IlumDayNightStatus_illumDNStatus(&Read_rp_IlumDayNightStatus_illumDNStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(&Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(&Read_rp_ShiftPositionDisp_ShiftPositionDisplay);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_Tail_Light_Status_Tail_Light_st(&Read_rp_Tail_Light_Status_Tail_Light_st);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(&Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts);
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

  fct_status = TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(&Read_rp_TurnHzdTurnR_Status_RightIndicatorSts);
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

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppAccModeState_WSSAccState(Rte_InitValue_ppAccModeState_WSSAccState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppBaModeState_WSSBaState(Rte_InitValue_ppBaModeState_WSSBaState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppBaOfModeState_WSSBaOfState(Rte_InitValue_ppBaOfModeState_WSSBaOfState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate(Rte_InitValue_ppIgnModeBuzzer_IgnitioBuznstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppIgnSubstate_IgnitionSubstate(Rte_InitValue_ppIgnSubstate_IgnitionSubstate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppIgpCANModeState_WSSIGPCANState(Rte_InitValue_ppIgpCANModeState_WSSIGPCANState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_ppIgpModeState_WSSIGPState(Rte_InitValue_ppIgpModeState_WSSIGPState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(Rte_InitValue_pp_ClusterMode_WSSCurrentClusterMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_HMIReady_HMI_ReadyStatus(Rte_InitValue_pp_HMIReady_HMI_ReadyStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(Rte_InitValue_pp_Init_ClusterMode_WSSCurrentClusterInitMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_SleepStatus_Sleep_Status(Rte_InitValue_pp_SleepStatus_Sleep_Status);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(Rte_InitValue_pp_TFTDisplayOn_TFTDisplayOn);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(Rte_InitValue_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(Rte_InitValue_pp_VehicleAppMode_WSSCurrentVehicleState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateRx(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateTx(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlSetDone(FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_GetCurrentComMode(0U, &Call_rpComMExt_CAN_GetCurrentComMode_ComMode);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ReleaseCommunication(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_RequestCommunication(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_GetBusOffStatus(0U, &Call_rpComMExt_GetBusOffStatus_BusOffStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(&Call_rpComMExt_Get_MCAN_ERR_PIN_Status_fl_pin_status_BOOL);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpComMExt_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_AsyncRawAdc, &Call_rpIoHwAb_ADC_GetAsyncRawAdc_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(0U, &Call_rpIoHwAb_ADC_GetProcessedAdc_ProcessedAdc, &Call_rpIoHwAb_ADC_GetProcessedAdc_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(0U, &Call_rpIoHwAb_ADC_GetSyncRawAdc_SyncRawAdc, &Call_rpIoHwAb_ADC_GetSyncRawAdc_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(0U, &Call_rpIoHwAb_Din_GetAsyncRawInput_AsyncInput, &Call_rpIoHwAb_Din_GetAsyncRawInput_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetInputGroup(0, &Call_rpIoHwAb_Din_GetInputGroup_SyncInput, &Call_rpIoHwAb_Din_GetInputGroup_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetProcessedInput(0U, &Call_rpIoHwAb_Din_GetProcessedInput_InputSignal, &Call_rpIoHwAb_Din_GetProcessedInput_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(0U, &Call_rpIoHwAb_Din_GetSyncRawInput_SyncInput, &Call_rpIoHwAb_Din_GetSyncRawInput_ErrorStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue(0U, &Call_rp_CS_ComAbsRx_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_ComAbsRx_RxCan_GetSignalValue_pSignalStatus);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue(0U, &Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue_pSignalValue);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus();
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
    case RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(&Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus_Status);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep();
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
    case RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep();
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
    case RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep();
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
    case RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(0U, 0U, &Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed_IsElapsed);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(0U, &Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted_IsStarted);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(0U);
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_View_Speed_Init();
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

  fct_status = TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init();
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ctrl_WSS_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: Ctrl_WSS_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ctrl_WSS_CODE) Ctrl_WSS_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_SWCEarlyWakeUpHandle
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SWCEarlyWakeUpHandle> of PortPrototype <pp_EarlyWakeupState>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ctrl_WSS_SWCEarlyWakeUpHandle(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_SWCEarlyWakeUpHandle_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCEarlyWakeUpHandle(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_SWCEarlyWakeUpHandle
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ctrl_WSS_SWCSleepStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SWCSleepStatus> of PortPrototype <pp_AppMdl_Sleep>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ctrl_WSS_SWCSleepStatus(eAppMdl AppModule, eSleepSt SleepStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_SWCSleepStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ctrl_WSS_CODE) Ctrl_WSS_SWCSleepStatus(eAppMdl AppModule, eSleepSt SleepStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ctrl_WSS_SWCSleepStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ctrl_WSS_STOP_SEC_CODE
#include "Ctrl_WSS_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Ctrl_WSS_TestDefines(void)
{
  /* Enumeration Data Types */

  BOOL_TYPE Test_BOOL_TYPE_V_1 = DBG_TRUE;
  BOOL_TYPE Test_BOOL_TYPE_V_2 = DBG_FALSE;

  ClusterInitModes Test_ClusterInitModes_V_1 = CLUSTER_INIT;
  ClusterInitModes Test_ClusterInitModes_V_2 = CLUSTER_RUN;
  ClusterInitModes Test_ClusterInitModes_V_3 = CLUSTER_RUN_READALL;

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  DisplayStatus Test_DisplayStatus_V_1 = TFTDisplayOFF;
  DisplayStatus Test_DisplayStatus_V_2 = TFTDisplayON;

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  HMI_Odo_Type Test_HMI_Odo_Type_V_1 = eODO_TYPE_OFF;
  HMI_Odo_Type Test_HMI_Odo_Type_V_2 = eODO_TYPE_BLANK;
  HMI_Odo_Type Test_HMI_Odo_Type_V_3 = eODO_TYPE_ODO;
  HMI_Odo_Type Test_HMI_Odo_Type_V_4 = eODO_TYPE_TRIPA;
  HMI_Odo_Type Test_HMI_Odo_Type_V_5 = eODO_TYPE_TRIPB;
  HMI_Odo_Type Test_HMI_Odo_Type_V_6 = eODO_TYPE_OILMIL_DISTANCE;
  HMI_Odo_Type Test_HMI_Odo_Type_V_7 = eODO_TYPE_FUEL_OW_ADV_NOTICE;
  HMI_Odo_Type Test_HMI_Odo_Type_V_8 = eODO_TYPE_FUEL_OVER_WRITE;
  HMI_Odo_Type Test_HMI_Odo_Type_V_9 = eODO_TYPE_POWER_STATUS_ACC;
  HMI_Odo_Type Test_HMI_Odo_Type_V_10 = eODO_TYPE_POWER_STATUS_ON;
  HMI_Odo_Type Test_HMI_Odo_Type_V_11 = eODO_TYPE_OILMIL_DISTANCE_INT;

  HMI_Screen_Mode Test_HMI_Screen_Mode_V_1 = eSCREENMODE_OFF;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_2 = eSCREENMODE_BLANK;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_3 = eSCREENMODE_NORMAL;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_4 = eSCREENMODE_DISPLAY_ADJ;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_5 = eSCREENMODE_WELCOME;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_6 = eSCREENMODE_IGNOFF_CHR;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_7 = eSCREENMODE_OPENING;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_8 = eSCREENMODE_ENDING;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_9 = eSCREENMODE_ENDING_IGNOFF_CHR;
  HMI_Screen_Mode Test_HMI_Screen_Mode_V_10 = eSCREENMODE_RESERVED;

  HTimer Test_HTimer_V_1 = eWarningMask_Timerhandle;
  HTimer Test_HTimer_V_2 = eOWC_Timerhandle;
  HTimer Test_HTimer_V_3 = eNWD_Timerhandle;
  HTimer Test_HTimer_V_4 = eWarningBulbCheckMask_Timerhandle;
  HTimer Test_HTimer_V_5 = eInitWarning_TimerHandle;
  HTimer Test_HTimer_V_6 = eInitChimeTimerHandle;
  HTimer Test_HTimer_V_7 = eProgrammingTimerHandle;
  HTimer Test_HTimer_V_8 = eStubCounter_TimerHanlde;
  HTimer Test_HTimer_V_9 = eModeMgrDisplayPowerDownUp;
  HTimer Test_HTimer_V_10 = eModeMgrDisplayFaultAction;
  HTimer Test_HTimer_V_11 = eModeMgrDomanResetAction;
  HTimer Test_HTimer_V_12 = eModeMgrPowerFaultAction;
  HTimer Test_HTimer_V_13 = eEtm4SecTimer;
  HTimer Test_HTimer_V_14 = eEtm1200msecTimer;
  HTimer Test_HTimer_V_15 = eEtm3SecTimer;
  HTimer Test_HTimer_V_16 = eCallbackTimerOdoMdl;
  HTimer Test_HTimer_V_17 = eThrottleTimerOdoMdl;
  HTimer Test_HTimer_V_18 = eChangeupCallbackTimerodoMdl;
  HTimer Test_HTimer_V_19 = eTimerVehicleState;
  HTimer Test_HTimer_V_20 = eTimerVariantConfig;
  HTimer Test_HTimer_V_21 = WARNING_DISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_22 = WARNING_HOLD_TIMER_ID;
  HTimer Test_HTimer_V_23 = WARNING_CYCLE_TIMER_ID;
  HTimer Test_HTimer_V_24 = WARNING_DISPLAYHOLD_TIMER_ID;
  HTimer Test_HTimer_V_25 = WARNING_ACK_TIMER_ID;
  HTimer Test_HTimer_V_26 = eTimerHandle_Sleep;
  HTimer Test_HTimer_V_27 = eInStartCount_TimerHandle;
  HTimer Test_HTimer_V_28 = eVehicleModeCount_TimerHandle;
  HTimer Test_HTimer_V_29 = e10secTimer;
  HTimer Test_HTimer_V_30 = e3secTimer;
  HTimer Test_HTimer_V_31 = e30secTimer;
  HTimer Test_HTimer_V_32 = e2_6secTimer;
  HTimer Test_HTimer_V_33 = eDcmApp5secTimer;
  HTimer Test_HTimer_V_34 = eDcmApp1secTimer;
  HTimer Test_HTimer_V_35 = eLidopen_OFFTimer;
  HTimer Test_HTimer_V_36 = eLidopen_ONTimer;
  HTimer Test_HTimer_V_37 = POPUP_DISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_38 = POPUP_GRP_TAB_TIMER_ID;
  HTimer Test_HTimer_V_39 = eDrvRec5_6Timer;
  HTimer Test_HTimer_V_40 = eDrvRec3_6Timer;
  HTimer Test_HTimer_V_41 = eIDS_1SecTimer;
  HTimer Test_HTimer_V_42 = eIDS3_1SecTimer;
  HTimer Test_HTimer_V_43 = eIDS_3SecTimer;
  HTimer Test_HTimer_V_44 = ePerDispSet100msTimer;
  HTimer Test_HTimer_V_45 = eDrvRec1_2secTimer;
  HTimer Test_HTimer_V_46 = eDrvRec0_8secTimer;
  HTimer Test_HTimer_V_47 = eHMI_Initial_Blank_timer_ID;
  HTimer Test_HTimer_V_48 = eHMI_Fade_in_delay_timer_ID;
  HTimer Test_HTimer_V_49 = eKM6secTimer;
  HTimer Test_HTimer_V_50 = eKM5_8secTimer;
  HTimer Test_HTimer_V_51 = eKM0_6secTimer;
  HTimer Test_HTimer_V_52 = eKM0_2secTimer;
  HTimer Test_HTimer_V_53 = eIgnCANMode_3SecTimer;
  HTimer Test_HTimer_V_54 = eDem2_6secTimer;
  HTimer Test_HTimer_V_55 = eDem5secTimer;
  HTimer Test_HTimer_V_56 = e2FRheo5secTimer;
  HTimer Test_HTimer_V_57 = e2FSTSW5secTimer;
  HTimer Test_HTimer_V_58 = eLSTM3_Timer;
  HTimer Test_HTimer_V_59 = eLSTM4_Timer;
  HTimer Test_HTimer_V_60 = eDem_AFS_5sec_Timer;
  HTimer Test_HTimer_V_61 = WARNING_MSGTIMEOUT_1SEC_TIMER_ID;
  HTimer Test_HTimer_V_62 = eDCMApp_30Sec_Timer;
  HTimer Test_HTimer_V_63 = WRN_ACK_REDISPLAY_TIMER_ID;
  HTimer Test_HTimer_V_64 = eMenuScrollStart1sTimer;
  HTimer Test_HTimer_V_65 = eType4_6secTimer;
  HTimer Test_HTimer_V_66 = eDcmApp_0_35secTimer;
  HTimer Test_HTimer_V_67 = eDcmApp_0_35_1secTimer;
  HTimer Test_HTimer_V_68 = eRemoteCarFindCtrlStateTimer;
  HTimer Test_HTimer_V_69 = eBrake_Red_100msecTimer;
  HTimer Test_HTimer_V_70 = eStreeingSw_ReleaseTimer;
  HTimer Test_HTimer_V_71 = POPUP_SETTING_TIMER_ID;
  HTimer Test_HTimer_V_72 = eMenu100msTimer;
  HTimer Test_HTimer_V_73 = eBuzzerMiddleEast_6secs;
  HTimer Test_HTimer_V_74 = eBuzzerMiddleEast_6secs_2;
  HTimer Test_HTimer_V_75 = eMaxNumof16BitTimers;
  HTimer Test_HTimer_V_76 = eSleepMaxTimer;
  HTimer Test_HTimer_V_77 = eRentACarTimer;
  HTimer Test_HTimer_V_78 = eDoorWarn_Timer;
  HTimer Test_HTimer_V_79 = eTimerHandleGdtCdd;
  HTimer Test_HTimer_V_80 = eSample32BitTimer;
  HTimer Test_HTimer_V_81 = eTimerMax;

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

  ModeStatus Test_ModeStatus_V_1 = STATUS_OFF;
  ModeStatus Test_ModeStatus_V_2 = STATUS_ON;

  SleepType Test_SleepType_V_1 = SLEEEP_READY;
  SleepType Test_SleepType_V_2 = SLEEP_NOT_READY;

  TTFlashMask Test_TTFlashMask_V_1 = NOT_IN_SYNCH;
  TTFlashMask Test_TTFlashMask_V_2 = FLASH_180DEG_PHASE_SYNCH;
  TTFlashMask Test_TTFlashMask_V_3 = FLASH_360DEG_PHASE_SYNCH;
  TTFlashMask Test_TTFlashMask_V_4 = FLASH_OFF_PERIOD_MASK;

  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_1 = TT_ABS_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_2 = TT_AIRBAG_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_3 = TT_BRAKE_RED_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_4 = TT_BRAKE_HOLD_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_5 = TT_BRAKE_YELLOW_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_6 = TT_PARKING_BRAKE_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_7 = TT_TRACTION_CTRL_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_8 = TT_VCS_OFF_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_9 = TT_ABS_INDEX_US;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_10 = TT_BRAKE_RED_INDEX_US;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_11 = TT_PARKING_BRAKE_INDEX_US;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_12 = TT_SAF_RES4_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_13 = TT_SAF_RES5_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_14 = TT_SAF_RES6_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_15 = TT_SAF_RES7_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_16 = TT_SAF_RES8_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_17 = TT_ADAS_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_18 = TT_AUTO_HIGH_BEAM_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_19 = TT_BRAKE_HOLD_STANDBY_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_20 = TT_FUEL_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_21 = TT_FFOG_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_22 = TT_HEAD_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_23 = TT_HIGH_BEAM_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_24 = TT_PCS_OFF_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_25 = TT_READY_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_26 = TT_RFOG_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_27 = TT_SEAT_BELT_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_28 = TT_TAIL_LIGHT_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_29 = TT_TURN_HAZARD_RIGHT_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_30 = TT_TURN_HAZARD_LEFT_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_31 = TT_EWT_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_32 = TT_AAHB_LO_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_33 = TT_AAHB_SHADED_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_34 = TT_AAHB_HI_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_35 = TT_AAHB_HI_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_36 = TT_ITS_INFRA;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_37 = TT_ITS_VEHICLE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_38 = TT_ITS_COMBINATION;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_39 = TT_SSS_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_40 = TT_SSS_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_41 = TT_LCA_LEFT_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_42 = TT_LCA_LEFT_GRAY;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_43 = TT_LCA_LEFT_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_44 = TT_LCA_RIGHT_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_45 = TT_LCA_RIGHT_GRAY;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_46 = TT_LCA_RIGHT_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_47 = TT_LTA_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_48 = TT_LTA_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_49 = TT_LTA_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_50 = TT_CCT_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_51 = TT_CCT_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_52 = TT_CCT_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_53 = TT_RCCT_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_54 = TT_RCCT_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_55 = TT_RCCT_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_56 = TT_ACCDT_WHITE_LV4;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_57 = TT_ACCDT_WHITE_LV3;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_58 = TT_ACCDT_WHITE_LV2;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_59 = TT_ACCDT_WHITE_LV1;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_60 = TT_ACCDT_GREEN_LV4;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_61 = TT_ACCDT_GREEN_LV3;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_62 = TT_ACCDT_GREEN_LV2;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_63 = TT_ACCDT_GREEN_LV1;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_64 = TT_SL_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_65 = TT_SL_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_66 = TT_SL_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_67 = TT_AUTO_LSD_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_68 = TT_DRIVEMODE_SPORT;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_69 = TT_DRIVEMODE_ECO;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_70 = TT_DRIVEMODE_CUSTOM;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_71 = TT_DRIVEMODE_RANGE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_72 = TT_DRIVEMODE_REARCOMFORT;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_73 = TT_DRIVEMODE_SNOW;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_74 = TT_DRIVEMODE_TRACK;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_75 = TT_LDA_RED;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_76 = TT_LDA_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_77 = TT_LDA_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_78 = TT_LDA_OFF_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_79 = TT_LDA_OFF_WHITE;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_80 = TT_ECOLAMP;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_81 = TT_PS_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_82 = TT_PKBOPER_TXT;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_83 = TT_PKBOPER_IMG;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_84 = TT_TPMS_INDEX;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_85 = TT_EBPWIND_RED_US;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_86 = TT_EBPWIND_RED;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_87 = TT_FMSR_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_88 = TT_FMFR_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_89 = TT_MULWL_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_90 = TT_HCS_ACCESS_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_91 = TT_HCS_LIFT_GREEN;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_92 = TT_HCS_LIFT_AMBER;
  TT_ENUM_TYPE Test_TT_ENUM_TYPE_V_93 = TT_TOTAL_NUM_OF_TELLTALES;

  TT_OP_STATES Test_TT_OP_STATES_V_1 = TT_TURN_OFF;
  TT_OP_STATES Test_TT_OP_STATES_V_2 = TT_TURN_ON;
  TT_OP_STATES Test_TT_OP_STATES_V_3 = TT_FLASH_QUARTER_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_4 = TT_FLASH_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_5 = TT_FLASH_CSNR_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_6 = TT_FLASH_0_83_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_7 = TT_FLASH_1HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_8 = TT_FLASH_1_33_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_9 = TT_FLASH_1_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_10 = TT_FLASH_2HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_11 = TT_FLASH_2_5_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_12 = TT_FLASH_2_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_13 = TT_FLASH_TRNHZ_Normal;
  TT_OP_STATES Test_TT_OP_STATES_V_14 = TT_FLASH_TRNHZ_Fast;
  TT_OP_STATES Test_TT_OP_STATES_V_15 = TT_FLASH_TRNHZ_FHL;
  TT_OP_STATES Test_TT_OP_STATES_V_16 = TT_FLASH_3HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_17 = TT_FLASH_4HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_18 = TT_FLASH_5HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_19 = TT_FLASH_SYNC_QUARTER_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_20 = TT_FLASH_SYNC_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_21 = TT_FLASH_SYNC_CSNR_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_22 = TT_FLASH_SYNC_0_83_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_23 = TT_FLASH_SYNC_1HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_24 = TT_FLASH_SYNC_1_33_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_25 = TT_FLASH_SYNC_1_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_26 = TT_FLASH_SYNC_2HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_27 = TT_FLASH_SYNC_2_5_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_28 = TT_FLASH_SYNC_2_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_29 = TT_FLASH_TRNHZ_SYNC_Normal;
  TT_OP_STATES Test_TT_OP_STATES_V_30 = TT_FLASH_TRNHZ_SYNC_Fast;
  TT_OP_STATES Test_TT_OP_STATES_V_31 = TT_FLASH_TRNHZ_SYNC_FHL;
  TT_OP_STATES Test_TT_OP_STATES_V_32 = TT_FLASH_SYNC_4HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_33 = TT_FLASH_SYNC_5HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_34 = TT_CONFIGURED_OFF;

  TurnStates Test_TurnStates_V_1 = TurnOff;
  TurnStates Test_TurnStates_V_2 = TurnOn;
  TurnStates Test_TurnStates_V_3 = TurnBlink;

  VehicleActiveModes Test_VehicleActiveModes_V_1 = NETWORK_SLEEP;
  VehicleActiveModes Test_VehicleActiveModes_V_2 = NETWORK_NORMAL;
  VehicleActiveModes Test_VehicleActiveModes_V_3 = NETWORK_STANDALONE;

  eAppMdl Test_eAppMdl_V_1 = eSWCApp_SmartKey_Bzr;
  eAppMdl Test_eAppMdl_V_2 = eSWCApp_Warn_MFLID;
  eAppMdl Test_eAppMdl_V_3 = eSWCApp_Head_TT;
  eAppMdl Test_eAppMdl_V_4 = eSWCApp_Tail_TT;
  eAppMdl Test_eAppMdl_V_5 = eSWCApp_Fuel;
  eAppMdl Test_eAppMdl_V_6 = eSWCApp_Illum;
  eAppMdl Test_eAppMdl_V_7 = eSWCApp_Buzzer;
  eAppMdl Test_eAppMdl_V_8 = eSWCApp_NVM;
  eAppMdl Test_eAppMdl_V_9 = eTFTDisplayOnExceptTurn;
  eAppMdl Test_eAppMdl_V_10 = eTurnL_Status;
  eAppMdl Test_eAppMdl_V_11 = eTurnR_Status;
  eAppMdl Test_eAppMdl_V_12 = eSWCApp_End;

  eSleepSt Test_eSleepSt_V_1 = eSleep_Inactive;
  eSleepSt Test_eSleepSt_V_2 = eISleep_Active;

  tRxSignalId Test_tRxSignalId_V_1 = eDayNightModeIn;
  tRxSignalId Test_tRxSignalId_V_2 = eIllumination_levelIn;
  tRxSignalId Test_tRxSignalId_V_3 = eAmbient_Light_levelIn;
  tRxSignalId Test_tRxSignalId_V_4 = ePowerModeIn;
  tRxSignalId Test_tRxSignalId_V_5 = eTransportModeIn;
  tRxSignalId Test_tRxSignalId_V_6 = eGearModeIn;
  tRxSignalId Test_tRxSignalId_V_7 = eGearRecommendationIn;
  tRxSignalId Test_tRxSignalId_V_8 = eGearIn;
  tRxSignalId Test_tRxSignalId_V_9 = eWarningIn;
  tRxSignalId Test_tRxSignalId_V_10 = eGearStatusIn;
  tRxSignalId Test_tRxSignalId_V_11 = eEngineSpeedIn;
  tRxSignalId Test_tRxSignalId_V_12 = eTurn_Indicator_ControlIn;
  tRxSignalId Test_tRxSignalId_V_13 = eEndOfRxSignal;

  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tRxSignalStatus Test_tRxSignalStatus_V_1 = eSIGNAL_OK;
  tRxSignalStatus Test_tRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tRxSignalStatus Test_tRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tRxSignalStatus Test_tRxSignalStatus_V_4 = eSIGNAL_INVALID;
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
