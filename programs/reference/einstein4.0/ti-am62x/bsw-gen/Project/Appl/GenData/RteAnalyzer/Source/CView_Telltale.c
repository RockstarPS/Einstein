/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CView_Telltale.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CView_Telltale
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CView_Telltale>
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

#include "Rte_CView_Telltale.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CView_Telltale.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CView_Telltale_TestDefines(void);


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
 * Rte_DT_data_u8_15_0: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
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
 * TTFlashMask: Enumeration of integer in interval [0...4] with enumerators
 *   NOT_IN_SYNCH (0U)
 *   FLASH_180DEG_PHASE_SYNCH (1U)
 *   FLASH_360DEG_PHASE_SYNCH (2U)
 *   FLASH_OFF_PERIOD_MASK (4U)
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
 * data_u8_15: Array with 15 element(s) of type Rte_DT_data_u8_15_0
 *
 * Record Types:
 * =============
 * STT_Status: Record with elements
 *   mask of type data_u8_15
 *
 *********************************************************************************************************************/


#define CView_Telltale_START_SEC_CODE
#include "CView_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CView_Telltale_Impl_MainFunction
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
 *   Std_ReturnType Rte_Read_rpBlinkStatusArray_TTBlinkStatusArray(Rte_DT_TTBlinkArray_0 *data)
 *     Argument data: Rte_DT_TTBlinkArray_0* is of type TTBlinkArray
 *   Std_ReturnType Rte_Read_rpBlinkStatusArray_TTdummyDataForTypes(TTFlashMask *data)
 *   Std_ReturnType Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Rte_DT_TT_OP_Type_0 *data)
 *     Argument data: Rte_DT_TT_OP_Type_0* is of type TT_OP_Type
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_HMIReady_HMI_ReadyStatus(HMIReadySts_Type *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ppTelltaleSts_TT_StatusData(const STT_Status *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CView_Telltale_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CView_Telltale_CODE) CView_Telltale_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CView_Telltale_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  TTBlinkArray Read_rpBlinkStatusArray_TTBlinkStatusArray;
  TTFlashMask Read_rpBlinkStatusArray_TTdummyDataForTypes;
  TT_OP_Type Read_rpTelltaleStatusOP_TelltaleOpArray;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus;
  TT_OP_STATES Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  HMIReadySts_Type Read_rp_HMIReady_HMI_ReadyStatus;

  STT_Status Write_ppTelltaleSts_TT_StatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CView_Telltale_Rte_Read_rpBlinkStatusArray_TTBlinkStatusArray(Read_rpBlinkStatusArray_TTBlinkStatusArray);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rpBlinkStatusArray_TTdummyDataForTypes(&Read_rpBlinkStatusArray_TTdummyDataForTypes);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Read_rpTelltaleStatusOP_TelltaleOpArray);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(&Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_CView_Telltale_Rte_Read_rp_HMIReady_HMI_ReadyStatus(&Read_rp_HMIReady_HMI_ReadyStatus);
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

  (void)memset(&Write_ppTelltaleSts_TT_StatusData, 0, sizeof(Write_ppTelltaleSts_TT_StatusData));
  fct_status = TSC_CView_Telltale_Rte_Write_ppTelltaleSts_TT_StatusData(&Write_ppTelltaleSts_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  CView_Telltale_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CView_Telltale_Impl_OnCommand
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
 *   Std_ReturnType CView_Telltale_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CView_Telltale_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CView_Telltale_CODE) CView_Telltale_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CView_Telltale_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CView_Telltale_Init
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
 *   void CView_Telltale_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CView_Telltale_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CView_Telltale_CODE) CView_Telltale_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CView_Telltale_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CView_Telltale_STOP_SEC_CODE
#include "CView_Telltale_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CView_Telltale_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  TTFlashMask Test_TTFlashMask_V_1 = NOT_IN_SYNCH;
  TTFlashMask Test_TTFlashMask_V_2 = FLASH_180DEG_PHASE_SYNCH;
  TTFlashMask Test_TTFlashMask_V_3 = FLASH_360DEG_PHASE_SYNCH;
  TTFlashMask Test_TTFlashMask_V_4 = FLASH_OFF_PERIOD_MASK;

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
