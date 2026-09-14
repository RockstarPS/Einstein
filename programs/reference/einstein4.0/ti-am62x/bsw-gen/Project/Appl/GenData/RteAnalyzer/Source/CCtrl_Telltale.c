/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CCtrl_Telltale.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CCtrl_Telltale
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CCtrl_Telltale>
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

#include "Rte_CCtrl_Telltale.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CCtrl_Telltale.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CCtrl_Telltale_TestDefines(void);


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
 * Rte_DT_TTBlinkArray_0: Integer in interval [0...255]
 * Rte_DT_TT_OP_Type_0: Integer in interval [0...255]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * BulbTestStatus: Enumeration of integer in interval [0...45020] with enumerators
 *   BulbStatusNotActive (0U)
 *   BulbStatusActive (45020U)
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 *   eHMI_NOT_READY (0U)
 *   eHMI_READY (1U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * TFTIgnBlankSts_T: Enumeration of integer in interval [0...1] with enumerators
 *   TFTExitBlankOut (0U)
 *   TFTInBlankOut (1U)
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
 *
 * Array Types:
 * ============
 * TTBlinkArray: Array with 16 element(s) of type Rte_DT_TTBlinkArray_0
 * TT_OP_Type: Array with 92 element(s) of type Rte_DT_TT_OP_Type_0
 *
 *********************************************************************************************************************/


#define CCtrl_Telltale_START_SEC_CODE
#include "CCtrl_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCtrl_Telltale_Adapter_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 30ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(BulbTestStatus *data)
 *   Std_ReturnType Rte_Read_rpHmiReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(TFTIgnBlankSts_T *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rpTelltaleIndexStatus_TTIndex(TT_ENUM_TYPE *data)
 *   Std_ReturnType Rte_Read_rpTelltaleIndexStatus_TTStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_EtmSts_CurrentBulbTestStatus(BulbTestStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(const Rte_DT_TTBlinkArray_0 *data)
 *     Argument data: Rte_DT_TTBlinkArray_0* is of type TTBlinkArray
 *   Std_ReturnType Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(TTFlashMask data)
 *   Std_ReturnType Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(const Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *   Std_ReturnType Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(const Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_EcuBatteryMData_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_EcuBatteryMData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Adapter_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Adapter_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Adapter_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BulbTestStatus Read_rpETMBulbTest_CurrentBulbTestStatus;
  HMIReadySts_Type Read_rpHmiReadyState_HMI_ReadyStatus;
  TFTIgnBlankSts_T Read_rpIgnBlankOutCheck_IgnBlankOutCheck;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  TT_ENUM_TYPE Read_rpTelltaleIndexStatus_TTIndex;
  TT_OP_STATES Read_rpTelltaleIndexStatus_TTStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  BulbTestStatus Read_rp_EtmSts_CurrentBulbTestStatus;

  TTBlinkArray Write_ppBlinkStatusArray_TTBlinkStatusArray;
  TT_OP_Type Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus;
  TT_OP_Type Write_ppTelltaleStatusOP_TelltaleOpArray;

  UInt8 Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus_Status = 0U;
  UInt8 Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus_Status = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(&Read_rpETMBulbTest_CurrentBulbTestStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpHmiReadyState_HMI_ReadyStatus(&Read_rpHmiReadyState_HMI_ReadyStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(&Read_rpIgnBlankOutCheck_IgnBlankOutCheck);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTIndex(&Read_rpTelltaleIndexStatus_TTIndex);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTStatus(&Read_rpTelltaleIndexStatus_TTStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rp_EtmSts_CurrentBulbTestStatus(&Read_rp_EtmSts_CurrentBulbTestStatus);
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

  (void)memset(&Write_ppBlinkStatusArray_TTBlinkStatusArray, 0, sizeof(Write_ppBlinkStatusArray_TTBlinkStatusArray));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(Write_ppBlinkStatusArray_TTBlinkStatusArray);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(Rte_InitValue_ppBlinkStatusArray_TTdummyDataForTypes);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus, 0, sizeof(Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_ppTelltaleStatusOP_TelltaleOpArray, 0, sizeof(Write_ppTelltaleStatusOP_TelltaleOpArray));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(Write_ppTelltaleStatusOP_TelltaleOpArray);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(0U, &Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus_Status);
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
    case RTE_E_TI_EcuBatteryMData_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(0U, &Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus_Status);
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
    case RTE_E_TI_EcuBatteryMData_E_NOT_OK:
      fct_error = 1;
      break;
  }

  CCtrl_Telltale_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCtrl_Telltale_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 30ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(BulbTestStatus *data)
 *   Std_ReturnType Rte_Read_rpHmiReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(TFTIgnBlankSts_T *data)
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rpTelltaleIndexStatus_TTIndex(TT_ENUM_TYPE *data)
 *   Std_ReturnType Rte_Read_rpTelltaleIndexStatus_TTStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_EtmSts_CurrentBulbTestStatus(BulbTestStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(const Rte_DT_TTBlinkArray_0 *data)
 *     Argument data: Rte_DT_TTBlinkArray_0* is of type TTBlinkArray
 *   Std_ReturnType Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(TTFlashMask data)
 *   Std_ReturnType Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(const Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *   Std_ReturnType Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(const Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_EcuBatteryMData_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_EcuBatteryMData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BulbTestStatus Read_rpETMBulbTest_CurrentBulbTestStatus;
  HMIReadySts_Type Read_rpHmiReadyState_HMI_ReadyStatus;
  TFTIgnBlankSts_T Read_rpIgnBlankOutCheck_IgnBlankOutCheck;
  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  TT_ENUM_TYPE Read_rpTelltaleIndexStatus_TTIndex;
  TT_OP_STATES Read_rpTelltaleIndexStatus_TTStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  BulbTestStatus Read_rp_EtmSts_CurrentBulbTestStatus;

  TTBlinkArray Write_ppBlinkStatusArray_TTBlinkStatusArray;
  TT_OP_Type Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus;
  TT_OP_Type Write_ppTelltaleStatusOP_TelltaleOpArray;

  UInt8 Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus_Status = 0U;
  UInt8 Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus_Status = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(&Read_rpETMBulbTest_CurrentBulbTestStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpHmiReadyState_HMI_ReadyStatus(&Read_rpHmiReadyState_HMI_ReadyStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(&Read_rpIgnBlankOutCheck_IgnBlankOutCheck);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTIndex(&Read_rpTelltaleIndexStatus_TTIndex);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTStatus(&Read_rpTelltaleIndexStatus_TTStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_CCtrl_Telltale_Rte_Read_rp_EtmSts_CurrentBulbTestStatus(&Read_rp_EtmSts_CurrentBulbTestStatus);
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

  (void)memset(&Write_ppBlinkStatusArray_TTBlinkStatusArray, 0, sizeof(Write_ppBlinkStatusArray_TTBlinkStatusArray));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(Write_ppBlinkStatusArray_TTBlinkStatusArray);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(Rte_InitValue_ppBlinkStatusArray_TTdummyDataForTypes);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus, 0, sizeof(Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_ppTelltaleStatusOP_TelltaleOpArray, 0, sizeof(Write_ppTelltaleStatusOP_TelltaleOpArray));
  fct_status = TSC_CCtrl_Telltale_Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(Write_ppTelltaleStatusOP_TelltaleOpArray);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(0U, &Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus_Status);
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
    case RTE_E_TI_EcuBatteryMData_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(0U, &Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus_Status);
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
    case RTE_E_TI_EcuBatteryMData_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCtrl_Telltale_Impl_OnCommand
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
 *   Std_ReturnType CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CCtrl_Telltale_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CCtrl_Telltale_CODE) CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CCtrl_Telltale_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Init> of PortPrototype <pp_Init>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CCtrl_Telltale_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CCtrl_Telltale_CODE) CCtrl_Telltale_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CCtrl_Telltale_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CCtrl_Telltale_STOP_SEC_CODE
#include "CCtrl_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CCtrl_Telltale_TestDefines(void)
{
  /* Enumeration Data Types */

  BulbTestStatus Test_BulbTestStatus_V_1 = BulbStatusNotActive;
  BulbTestStatus Test_BulbTestStatus_V_2 = BulbStatusActive;

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  TFTIgnBlankSts_T Test_TFTIgnBlankSts_T_V_1 = TFTExitBlankOut;
  TFTIgnBlankSts_T Test_TFTIgnBlankSts_T_V_2 = TFTInBlankOut;

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
