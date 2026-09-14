/*
 * File: Mdl_Dim.c
 *
 * Code generated for Simulink model 'Mdl_Dim'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Aug 27 01:26:00 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_Dim.h"
#include "Rte_Type.h"
#include "Platform_Types.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_ACTIVE
#error The value of parameter "CLUSTER_ACTIVE" is not defined
#endif

#ifndef NETWORK_NORMAL
#error The value of parameter "NETWORK_NORMAL" is not defined
#endif

#ifndef eDayNightModeIn
#error The value of parameter "eDayNightModeIn" is not defined
#endif

#ifndef eIllumination_levelIn
#error The value of parameter "eIllumination_levelIn" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_Mdl_Dim_T, Mdl_Dim_VAR_INIT) Mdl_Dim_ARID_DEF;

/* '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' */

/* Model step function for TID1 */
FUNC(void, Mdl_Dim_CODE) Mdl_Dim_Task(void) /* Explicit Task: Mdl_Dim_Task */
{
  ClusterModes tmpRead_1;
  DisplayStatus tmpRead_0;
  VehicleActiveModes tmpRead;
  uint8 rtb_RxCan_GetSignalValue1_o2;
  uint8 rtb_Switch;
  uint8 rtb_Switch1;
  uint8 rtb_Switch2;

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead_1);

  /* Inport: '<Root>/rp_TFTDisplayOn_TFTDisplayOn' */
  (void)Rte_Read_rp_TFTDisplayOn_TFTDisplayOn(&tmpRead_0);

  /* Inport: '<Root>/rpVehicleAppMode_WSSCurrentVehicleState' */
  (void)Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(&tmpRead);

  /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate
    (&Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.power_mode);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Dim_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Dim_Task_sys'
   */
  /* FunctionCaller: '<S5>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eDayNightModeIn),
    &rtb_Switch1, &rtb_Switch);

  /* FunctionCaller: '<S5>/RxCan_GetSignalValue1' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)
    eIllumination_levelIn), &rtb_Switch2, &rtb_RxCan_GetSignalValue1_o2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Dim_Task' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Dim_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Dim_Task_sys'
   */
  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Logic: '<S4>/AND2'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   */
  if ((rtb_Switch != ((uint8)eSIGNAL_NEVER_RECEIVED)) && (rtb_Switch != ((uint8)
        eSIGNAL_MISSING))) {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.Illumination_Mode =
      rtb_Switch1;
  } else {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.Illumination_Mode = ((uint8)
      DEFAULT_MODE);
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
   *  BusCreator: '<S1>/IllumCtrl_Ip_Data_creator'
   *  Constant: '<S4>/Constant6'
   */
  Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.battery_status = ((uint8)
    ZERO_VAL);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S4>/AND1'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (((tmpRead_0 == ((DisplayStatus)((uint8)STATUS_ON))) && (tmpRead ==
        ((VehicleActiveModes)((uint8)NETWORK_NORMAL)))) && (tmpRead_1 ==
       ((ClusterModes)((uint8)CLUSTER_ACTIVE)))) {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.Illumination_Sts = ((uint8)
      STATUS_ON);
  } else {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.Illumination_Sts = ((uint8)
      STATUS_OFF);
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Logic: '<S4>/AND3'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   */
  if ((rtb_RxCan_GetSignalValue1_o2 != ((uint8)eSIGNAL_NEVER_RECEIVED)) &&
      (rtb_RxCan_GetSignalValue1_o2 != ((uint8)eSIGNAL_MISSING))) {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.step_value = rtb_Switch2;
  } else {
    /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
     *  Constant: '<S4>/Constant4'
     */
    Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.step_value = ((uint8)
      DEFAULT_STEP);
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Outport: '<Root>/pp_IllumCtrl_Ip_IllumCtrl_Ip_Data' incorporates:
   *  BusCreator: '<S1>/IllumCtrl_Ip_Data_creator'
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Constant7'
   *  Constant: '<S4>/Constant8'
   */
  Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.step_direction = ((uint8)
    ZERO_VAL);
  Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.switch_type = ((uint8)
    SWITCHING_MECHANISM);
  Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da.Derating_Value = ((uint8)
    ZERO_VAL);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Dim_Task' */
  (void)Rte_Write_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data
    (&Mdl_Dim_ARID_DEF.pp_IllumCtrl_Ip_IllumCtrl_Ip_Da);
}

/* Model initialize function */
FUNC(void, Mdl_Dim_CODE) Mdl_Dim_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
