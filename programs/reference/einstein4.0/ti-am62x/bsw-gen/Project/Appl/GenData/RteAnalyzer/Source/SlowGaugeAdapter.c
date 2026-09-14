/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SlowGaugeAdapter.c
 *        Config:  BMW.dpa
 *     SW-C Type:  SlowGaugeAdapter
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <SlowGaugeAdapter>
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

#include "Rte_SlowGaugeAdapter.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_SlowGaugeAdapter.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void SlowGaugeAdapter_TestDefines(void);


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
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt16: Integer in interval [0...65535]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * EGaugeUnit: Enumeration of integer in interval [0...13] with enumerators
 *   EGaugeUnit_Mph (0U)
 *   EGaugeUnit_Kmph (1U)
 *   EGaugeUnit_Centigrade (2U)
 *   EGaugeUnit_Farenheit (3U)
 *   EGaugeUnit_Psi (4U)
 *   EGaugeUnit_Pa (5U)
 *   EGaugeUnit_Bar (6U)
 *   EGaugeUnit_Kmpl (7U)
 *   EGaugeUnit_Mpg (8U)
 *   EGaugeUnit_Ltr (9U)
 *   EGaugeUnit_Gal (10U)
 *   EGaugeUnit_Km (11U)
 *   EGaugeUnit_Mile (12U)
 *   EGaugeUnit_Last (13U)
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 *   eHMI_NOT_READY (0U)
 *   eHMI_READY (1U)
 * IOCtrl_Type: Enumeration of integer in interval [1...64] with enumerators
 *   eSPEEDO (1U)
 *   eTACHO (2U)
 *   eHVSYS_INDICATOR (4U)
 *   eSPEAKER (8U)
 *   eTELLTALE (16U)
 *   eBUTTONEVENT (32U)
 *   eMIDDISPALY (64U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 *
 * Record Types:
 * =============
 * SGaugeInfo: Record with elements
 *   id of type UInt8
 *   position of type UInt16
 *   digitalData of type SInt32
 *   unit of type EGaugeUnit
 *   dynData of type UInt16
 * SSlowGuageInfo: Record with elements
 *   gaugeInfo of type SGaugeInfo
 *
 *********************************************************************************************************************/


#define SlowGaugeAdapter_START_SEC_CODE
#include "SlowGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SlowGaugeAdapter_Init
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
 *   void SlowGaugeAdapter_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SlowGaugeAdapter_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SlowGaugeAdapter_CODE) SlowGaugeAdapter_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SlowGaugeAdapter_Init
 *********************************************************************************************************************/

  SlowGaugeAdapter_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SlowGaugeAdapter_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
 *   Std_ReturnType Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SlowGaugeInfo_SlowGaugeInfoData(const SSlowGuageInfo *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SlowGaugeAdapter_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SlowGaugeAdapter_CODE) SlowGaugeAdapter_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SlowGaugeAdapter_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  IOCtrl_Type Read_rp_Dcm_appStop_AppId;
  UInt16 Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value;
  UInt8 Read_rp_DispDistanceUnit_DisplayUnit;
  HMIReadySts_Type Read_rp_HMIReadyState_HMI_ReadyStatus;

  SSlowGuageInfo Write_pp_SlowGaugeInfo_SlowGaugeInfoData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rp_Dcm_appStop_AppId(&Read_rp_Dcm_appStop_AppId);
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

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(&Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value);
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

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rp_DispDistanceUnit_DisplayUnit(&Read_rp_DispDistanceUnit_DisplayUnit);
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

  fct_status = TSC_SlowGaugeAdapter_Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(&Read_rp_HMIReadyState_HMI_ReadyStatus);
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

  (void)memset(&Write_pp_SlowGaugeInfo_SlowGaugeInfoData, 0, sizeof(Write_pp_SlowGaugeInfo_SlowGaugeInfoData));
  fct_status = TSC_SlowGaugeAdapter_Rte_Write_pp_SlowGaugeInfo_SlowGaugeInfoData(&Write_pp_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SlowGaugeAdapter_STOP_SEC_CODE
#include "SlowGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void SlowGaugeAdapter_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  EGaugeUnit Test_EGaugeUnit_V_1 = EGaugeUnit_Mph;
  EGaugeUnit Test_EGaugeUnit_V_2 = EGaugeUnit_Kmph;
  EGaugeUnit Test_EGaugeUnit_V_3 = EGaugeUnit_Centigrade;
  EGaugeUnit Test_EGaugeUnit_V_4 = EGaugeUnit_Farenheit;
  EGaugeUnit Test_EGaugeUnit_V_5 = EGaugeUnit_Psi;
  EGaugeUnit Test_EGaugeUnit_V_6 = EGaugeUnit_Pa;
  EGaugeUnit Test_EGaugeUnit_V_7 = EGaugeUnit_Bar;
  EGaugeUnit Test_EGaugeUnit_V_8 = EGaugeUnit_Kmpl;
  EGaugeUnit Test_EGaugeUnit_V_9 = EGaugeUnit_Mpg;
  EGaugeUnit Test_EGaugeUnit_V_10 = EGaugeUnit_Ltr;
  EGaugeUnit Test_EGaugeUnit_V_11 = EGaugeUnit_Gal;
  EGaugeUnit Test_EGaugeUnit_V_12 = EGaugeUnit_Km;
  EGaugeUnit Test_EGaugeUnit_V_13 = EGaugeUnit_Mile;
  EGaugeUnit Test_EGaugeUnit_V_14 = EGaugeUnit_Last;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  IOCtrl_Type Test_IOCtrl_Type_V_1 = eSPEEDO;
  IOCtrl_Type Test_IOCtrl_Type_V_2 = eTACHO;
  IOCtrl_Type Test_IOCtrl_Type_V_3 = eHVSYS_INDICATOR;
  IOCtrl_Type Test_IOCtrl_Type_V_4 = eSPEAKER;
  IOCtrl_Type Test_IOCtrl_Type_V_5 = eTELLTALE;
  IOCtrl_Type Test_IOCtrl_Type_V_6 = eBUTTONEVENT;
  IOCtrl_Type Test_IOCtrl_Type_V_7 = eMIDDISPALY;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;
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
