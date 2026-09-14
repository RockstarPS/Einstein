/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  FastGaugeAdapter.c
 *        Config:  BMW.dpa
 *     SW-C Type:  FastGaugeAdapter
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <FastGaugeAdapter>
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

#include "Rte_FastGaugeAdapter.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_FastGaugeAdapter.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void FastGaugeAdapter_TestDefines(void);


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
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
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
 * Array Types:
 * ============
 * SGaugeInfo_u32dyn_2: Array with 2 element(s) of type SGaugeInfo_u32dyn
 *
 * Record Types:
 * =============
 * SFastGaugeInfo: Record with elements
 *   gaugeInfo of type SGaugeInfo_u32dyn_2
 * SGaugeInfo_u32dyn: Record with elements
 *   id of type UInt8
 *   position of type UInt16
 *   digitalData of type UInt32
 *   unit of type EGaugeUnit
 *   dynData of type UInt16
 *
 *********************************************************************************************************************/


#define FastGaugeAdapter_START_SEC_CODE
#include "FastGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FastGaugeAdapter_Init
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
 *   void FastGaugeAdapter_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FastGaugeAdapter_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FastGaugeAdapter_Init
 *********************************************************************************************************************/

  FastGaugeAdapter_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FastGaugeAdapter_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_Analog_Tacho_Analog_Tacho(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
 *   Std_ReturnType Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_Digital_Tacho_Digital_Tacho(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_DispSpeedA_DispSpeedVal(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_Display_speed_Value_Digital_Speed_Value(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_Needle_Transparent_Needle_TR(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal(UInt16 *data)
 *   Std_ReturnType Rte_Read_rp_TC_Unit_Digital_TachoUnit(Boolean *data)
 *   Std_ReturnType Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData(const SFastGaugeInfo *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FastGaugeAdapter_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, FastGaugeAdapter_CODE) FastGaugeAdapter_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FastGaugeAdapter_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  UInt16 Read_rp_Analog_Tacho_Analog_Tacho;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  IOCtrl_Type Read_rp_Dcm_appStop_AppId;
  UInt16 Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value;
  UInt16 Read_rp_Digital_Tacho_Digital_Tacho;
  UInt8 Read_rp_DispDistanceUnit_DisplayUnit;
  UInt16 Read_rp_DispSpeedA_DispSpeedVal;
  UInt16 Read_rp_Display_speed_Value_Digital_Speed_Value;
  HMIReadySts_Type Read_rp_HMIReadyState_HMI_ReadyStatus;
  UInt8 Read_rp_Needle_Transparent_Needle_TR;
  UInt8 Read_rp_PowerTrain_State_PowerTrain_Flag;
  UInt16 Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal;
  Boolean Read_rp_TC_Unit_Digital_TachoUnit;
  UInt8 Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM;
  UInt8 Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX;

  SFastGaugeInfo Write_pp_FastGaugeInfo_FastGaugeInfoData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Analog_Tacho_Analog_Tacho(&Read_rp_Analog_Tacho_Analog_Tacho);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Dcm_appStop_AppId(&Read_rp_Dcm_appStop_AppId);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(&Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Digital_Tacho_Digital_Tacho(&Read_rp_Digital_Tacho_Digital_Tacho);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_DispDistanceUnit_DisplayUnit(&Read_rp_DispDistanceUnit_DisplayUnit);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_DispSpeedA_DispSpeedVal(&Read_rp_DispSpeedA_DispSpeedVal);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Display_speed_Value_Digital_Speed_Value(&Read_rp_Display_speed_Value_Digital_Speed_Value);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(&Read_rp_HMIReadyState_HMI_ReadyStatus);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Needle_Transparent_Needle_TR(&Read_rp_Needle_Transparent_Needle_TR);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(&Read_rp_PowerTrain_State_PowerTrain_Flag);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal(&Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_TC_Unit_Digital_TachoUnit(&Read_rp_TC_Unit_Digital_TachoUnit);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM(&Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM);
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

  fct_status = TSC_FastGaugeAdapter_Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX(&Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX);
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

  (void)memset(&Write_pp_FastGaugeInfo_FastGaugeInfoData, 0, sizeof(Write_pp_FastGaugeInfo_FastGaugeInfoData));
  fct_status = TSC_FastGaugeAdapter_Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData(&Write_pp_FastGaugeInfo_FastGaugeInfoData);
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


#define FastGaugeAdapter_STOP_SEC_CODE
#include "FastGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void FastGaugeAdapter_TestDefines(void)
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
