/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mdl_Tacho.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Mdl_Tacho
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Mdl_Tacho>
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

#include "Rte_Mdl_Tacho.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Mdl_Tacho.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Mdl_Tacho_TestDefines(void);


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
 * CountryCode_FuncType: Enumeration of integer in interval [0...14] with enumerators
 *   eFUNC_CANADA (0U)
 *   eFUNC_NORTH_AMERICA (1U)
 *   eFUNC_MEXICO (2U)
 *   eFUNC_GENERAL_EXPORT (3U)
 *   eFUNC_UK (4U)
 *   eFUNC_EUROPE (5U)
 *   eFUNC_SOUTH_AFRICA (6U)
 *   eFUNC_MIDDLE_EAST_ASIA (7U)
 *   eFUNC_JAPAN (8U)
 *   eFUNC_INDIA (9U)
 *   eFUNC_KOREA (10U)
 *   eFUNC_TAIWAN (11U)
 *   eFUNC_CHINA (12U)
 *   eFUNC_HONG_KONG (13U)
 *   eFUNC_AUSTRALIA (14U)
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
 *********************************************************************************************************************/


#define Mdl_Tacho_START_SEC_CODE
#include "Mdl_Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Tacho_Init
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
 *   void Mdl_Tacho_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_Init
 *********************************************************************************************************************/

  Mdl_Tacho_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Tacho_Task
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
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_Country_Code_Func_CountryCode_Func(CountryCode_FuncType *data)
 *   Std_ReturnType Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
 *   Std_ReturnType Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(UInt16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_Analog_Tacho_Analog_Tacho(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_Digital_Tacho_Digital_Tacho(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_NE_Out_CalTachoValue(UInt16 data)
 *   Std_ReturnType Rte_Write_pp_Needle_Transparent_Needle_TR(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_Revp_Disp_REVP_DISP(Boolean data)
 *   Std_ReturnType Rte_Write_pp_TC_Unit_Digital_TachoUnit(Boolean data)
 *   Std_ReturnType Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(UInt16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
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
 *   Std_ReturnType Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(UInt16 NE1_SignalVal)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Tacho_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  CountryCode_FuncType Read_rp_Country_Code_Func_CountryCode_Func;
  IOCtrl_Type Read_rp_Dcm_appStop_AppId;
  UInt8 Read_rp_PowerTrain_State_PowerTrain_Flag;
  UInt16 Read_rp_SPD_SP1_In_Status_SP1_In_Status;

  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  UInt8 Call_rp_Get_Variant_Cfg_Get_Variant_Config_State_VariantActiveSt = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Mdl_Tacho_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_Mdl_Tacho_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_Mdl_Tacho_Rte_Read_rp_Country_Code_Func_CountryCode_Func(&Read_rp_Country_Code_Func_CountryCode_Func);
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

  fct_status = TSC_Mdl_Tacho_Rte_Read_rp_Dcm_appStop_AppId(&Read_rp_Dcm_appStop_AppId);
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

  fct_status = TSC_Mdl_Tacho_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(&Read_rp_PowerTrain_State_PowerTrain_Flag);
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

  fct_status = TSC_Mdl_Tacho_Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(&Read_rp_SPD_SP1_In_Status_SP1_In_Status);
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

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Analog_Tacho_Analog_Tacho(Rte_InitValue_pp_Analog_Tacho_Analog_Tacho);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Digital_Tacho_Digital_Tacho(Rte_InitValue_pp_Digital_Tacho_Digital_Tacho);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_NE_Out_CalTachoValue(Rte_InitValue_pp_NE_Out_CalTachoValue);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Needle_Transparent_Needle_TR(Rte_InitValue_pp_Needle_Transparent_Needle_TR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Revp_Disp_REVP_DISP(Rte_InitValue_pp_Revp_Disp_REVP_DISP);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_TC_Unit_Digital_TachoUnit(Rte_InitValue_pp_TC_Unit_Digital_TachoUnit);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM(Rte_InitValue_pp_Tacho_RED_Start_RPM_RED_Start_RPM);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX(Rte_InitValue_pp_Tacho_RPM_MAX_REVP_RPM_MAX);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(Rte_InitValue_pp_Tacho_Revp_RPM_REVP_RPM);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(0U, &Call_rp_Get_Variant_Cfg_Get_Variant_Config_State_VariantActiveSt);
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

  fct_status = TSC_Mdl_Tacho_Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(0U);
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


#define Mdl_Tacho_STOP_SEC_CODE
#include "Mdl_Tacho_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Mdl_Tacho_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  CountryCode_FuncType Test_CountryCode_FuncType_V_1 = eFUNC_CANADA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_2 = eFUNC_NORTH_AMERICA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_3 = eFUNC_MEXICO;
  CountryCode_FuncType Test_CountryCode_FuncType_V_4 = eFUNC_GENERAL_EXPORT;
  CountryCode_FuncType Test_CountryCode_FuncType_V_5 = eFUNC_UK;
  CountryCode_FuncType Test_CountryCode_FuncType_V_6 = eFUNC_EUROPE;
  CountryCode_FuncType Test_CountryCode_FuncType_V_7 = eFUNC_SOUTH_AFRICA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_8 = eFUNC_MIDDLE_EAST_ASIA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_9 = eFUNC_JAPAN;
  CountryCode_FuncType Test_CountryCode_FuncType_V_10 = eFUNC_INDIA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_11 = eFUNC_KOREA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_12 = eFUNC_TAIWAN;
  CountryCode_FuncType Test_CountryCode_FuncType_V_13 = eFUNC_CHINA;
  CountryCode_FuncType Test_CountryCode_FuncType_V_14 = eFUNC_HONG_KONG;
  CountryCode_FuncType Test_CountryCode_FuncType_V_15 = eFUNC_AUSTRALIA;

  IOCtrl_Type Test_IOCtrl_Type_V_1 = eSPEEDO;
  IOCtrl_Type Test_IOCtrl_Type_V_2 = eTACHO;
  IOCtrl_Type Test_IOCtrl_Type_V_3 = eHVSYS_INDICATOR;
  IOCtrl_Type Test_IOCtrl_Type_V_4 = eSPEAKER;
  IOCtrl_Type Test_IOCtrl_Type_V_5 = eTELLTALE;
  IOCtrl_Type Test_IOCtrl_Type_V_6 = eBUTTONEVENT;
  IOCtrl_Type Test_IOCtrl_Type_V_7 = eMIDDISPALY;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

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
