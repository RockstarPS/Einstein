/*
 * File: View_Speed.c
 *
 * Code generated for Simulink model 'View_Speed'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul  3 16:03:33 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "View_Speed.h"
#include "Platform_Types.h"
#include "Rte_Type.h"
#include "View_Speed_config.cfg"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_INACTIVE
#error The value of parameter "CLUSTER_INACTIVE" is not defined
#endif

#ifndef IgnOff
#error The value of parameter "IgnOff" is not defined
#endif

#ifndef IgnOn
#error The value of parameter "IgnOn" is not defined
#endif

#ifndef RTE_E_MAX_AGE_EXCEEDED
#error The value of parameter "RTE_E_MAX_AGE_EXCEEDED" is not defined
#endif

#ifndef RTE_E_NEVER_RECEIVED
#error The value of parameter "RTE_E_NEVER_RECEIVED" is not defined
#endif

#ifndef eVehicleSpeedABSIn
#error The value of parameter "eVehicleSpeedABSIn" is not defined
#endif

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_View_Speed_T, View_Speed_VAR_INIT) View_Speed_ARID_DEF;

/* '<S10>/Unit Delay2' */
static FUNC(void, View_Speed_CODE_LOCAL) View_Speed_IfActionSubsystem(VAR(uint16,
  AUTOMATIC) rtu_Speed_A_K, VAR(uint16, AUTOMATIC) rtu_Speed_A_M, P2VAR(uint16,
  AUTOMATIC, View_Speed_VAR_INIT) rty_Disp_Speed, P2VAR(uint16, AUTOMATIC,
  View_Speed_VAR_INIT) rty_Disp_Sub_Speed);
static FUNC(void, View_Speed_CODE_LOCAL) Speed_Value_Update(VAR(uint16,
  AUTOMATIC) rtu_speed_trg, VAR(uint16, AUTOMATIC) rtu_speed_trim, VAR(uint16,
  AUTOMATIC) rtu_Prev_Speed, P2VAR(uint16, AUTOMATIC, View_Speed_VAR_INIT)
  rty_Speed);

/*
 * Output and update for action system:
 *    '<S19>/If Action Subsystem'
 *    '<S18>/If Action Subsystem'
 */
static FUNC(void, View_Speed_CODE_LOCAL) View_Speed_IfActionSubsystem(VAR(uint16,
  AUTOMATIC) rtu_Speed_A_K, VAR(uint16, AUTOMATIC) rtu_Speed_A_M, P2VAR(uint16,
  AUTOMATIC, View_Speed_VAR_INIT) rty_Disp_Speed, P2VAR(uint16, AUTOMATIC,
  View_Speed_VAR_INIT) rty_Disp_Sub_Speed)
{
  /* SignalConversion generated from: '<S26>/Speed_A_K' */
  *rty_Disp_Speed = rtu_Speed_A_K;

  /* SignalConversion generated from: '<S26>/Speed_A_M' */
  *rty_Disp_Sub_Speed = rtu_Speed_A_M;
}

/*
 * Output and update for atomic system:
 *    '<S9>/Truth Table'
 *    '<S9>/Truth Table1'
 */
static FUNC(void, View_Speed_CODE_LOCAL) Speed_Value_Update(VAR(uint16,
  AUTOMATIC) rtu_speed_trg, VAR(uint16, AUTOMATIC) rtu_speed_trim, VAR(uint16,
  AUTOMATIC) rtu_Prev_Speed, P2VAR(uint16, AUTOMATIC, View_Speed_VAR_INIT)
  rty_Speed)
{
  /*  Speed trg greater than 2km/h */
  /*  Speed trg less than 2km/h and Prev Speed   greater than 2km/h */
  /*  Speed trg less than 1km/h */
  /*  Speed trg is 2km/h  or Prev_Speed is less than 1km/h */
  /*  Prev_Speed is 1km/h and Speed trim is 0 */
  /*  pre Speed is 0km/h and Other Conditions */
  if (rtu_speed_trg > ((uint16)C_SPEED_2KMPH)) {
    /*  Update Speed_k with Speed trigger */
    *rty_Speed = rtu_speed_trg;
  } else if (rtu_Prev_Speed > ((uint16)C_SPEED_2KMPH)) {
    /*  Update Speed_k with 2km/h */
    *rty_Speed = ((uint16)C_SPEED_2KMPH);
  } else if ((rtu_Prev_Speed == ((uint16)C_SPEED_2KMPH)) && (rtu_speed_trg <=
              ((uint16)C_SPEED_1KMPH))) {
    /*  Update Speed_k with 1km/h */
    *rty_Speed = ((uint16)C_SPEED_1KMPH);
  } else if ((rtu_Prev_Speed == ((uint16)C_SPEED_1KMPH)) && ((rtu_speed_trg ==
               ((uint16)C_SPEED_2KMPH)) || (rtu_speed_trg == ((uint16)
                C_SPEED_ZERO)))) {
    /*  Update Speed_k with Speed trigger */
    *rty_Speed = rtu_speed_trg;
  } else if ((rtu_Prev_Speed == ((uint16)C_SPEED_1KMPH)) && (rtu_speed_trim ==
              ((uint16)C_SPEED_ZERO))) {
    /*  Update Speed_k with 0km/h */
    *rty_Speed = ((uint16)C_SPEED_ZERO);
  } else if ((rtu_Prev_Speed == ((uint16)C_SPEED_ZERO)) && ((rtu_speed_trg ==
               ((uint16)C_SPEED_2KMPH)) || (rtu_speed_trg == ((uint16)
                C_SPEED_1KMPH)))) {
    /*  Update Speed_k with Speed trigger */
    *rty_Speed = rtu_speed_trg;
  } else {
    /*  Default */
    /*  No Change */
    *rty_Speed = rtu_Prev_Speed;
  }
}

/* Model step function for TID1 */
FUNC(void, View_Speed_CODE) View_Speed_Task(void) /* Explicit Task: View_Speed_Task */
{
  uint16 rtb_Merge;
  uint16 tmpRead;
  uint16 tmpRead_0;
  uint16 tmpRead_1;
  uint16 tmpRead_3;
  ClusterModes tmpRead_2;
  IgntionSubstateType rtb_TmpSignalConversionAtrpIgnS;
  uint8 rtb_RxCan_GetSignalValue_o1;
  uint8 rtb_RxCan_GetSignalValue_o2;
  uint8 rtb_TmpSignalConversionAtrp_SPD;

  /* RootInportFunctionCallGenerator generated from: '<Root>/View_Speed_Task' incorporates:
   *  SubSystem: '<Root>/View_Speed_Task_sys'
   */
  /* FunctionCaller: '<S6>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eVehicleSpeedABSIn),
    &rtb_RxCan_GetSignalValue_o1, &rtb_RxCan_GetSignalValue_o2);

  /* SignalConversion generated from: '<S2>/rpIgnSubstate_IgnitionSubstate' incorporates:
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&rtb_TmpSignalConversionAtrpIgnS);

  /* SignalConversion generated from: '<S2>/rp_SPD_Selection_Table_Speed_Selection_Table' incorporates:
   *  Inport: '<Root>/rp_SPD_Selection_Table_Speed_Selection_Table'
   */
  (void)Rte_Read_rp_SPD_Selection_Table_Speed_Selection_Table
    (&rtb_TmpSignalConversionAtrp_SPD);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/View_Speed_Task' */

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead_2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/View_Speed_Task' incorporates:
   *  SubSystem: '<Root>/View_Speed_Task_sys'
   */
  /* If: '<S5>/If' incorporates:
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/rp_SPD_SP1_In_Status_SP1_In_Status'
   *  Inport: '<Root>/rp_SPD_Target2_Status_Spd_Target2_Status'
   *  Inport: '<Root>/rp_SPD_Target_Status_Spd_Target_Status'
   *  Inport: '<Root>/rp_SPD_Trim2_Status_Spd_Trim2_Status'
   *  Inport: '<Root>/rp_SPD_Trim_Status_Spd_Trim_Status'
   */
  if (tmpRead_2 != ((ClusterModes)((uint8)CLUSTER_INACTIVE))) {
    (void)Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(&tmpRead);

    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outport: '<Root>/pp_Display_speed_Value_Digital_Speed_Value' incorporates:
     *  Inport: '<Root>/rp_SPD_SP1_In_Status_SP1_In_Status'
     *  SignalConversion generated from: '<S9>/Speed_Val'
     */
    (void)Rte_Write_pp_Display_speed_Value_Digital_Speed_Value(tmpRead);

    /* Product: '<S9>/Max_t1_count_250ms' incorporates:
     *  Constant: '<S9>/Constant18'
     *  Constant: '<S9>/Constant19'
     */
    if (View_Speed_cTaskPeriod == 0U) {
      tmpRead = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      tmpRead = (uint16)(((uint32)((uint16)IGN_TRAN_TIMER_MS)) / ((uint32)
        View_Speed_cTaskPeriod));
    }

    /* Outputs for Atomic SubSystem: '<S9>/Debounce timer for Ignoring samples' */
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S9>/Constant12'
     *  Constant: '<S9>/Constant8'
     *  Logic: '<S9>/Logical Operator11'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S9>/Relational Operator7'
     *  RelationalOperator: '<S9>/Relational Operator8'
     *  UnitDelay: '<S9>/Unit Delay5'
     */
    if ((View_Speed_ARID_DEF.PrevWUSIgnState1 == ((IgntionSubstateType)((uint8)
           IgnOff))) && (rtb_TmpSignalConversionAtrpIgnS ==
                         ((IgntionSubstateType)((uint8)IgnOn)))) {
      /* Switch: '<S10>/Switch2' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      View_Speed_ARID_DEF.Igntran_timer_count = 0U;
    } else {
      /* Switch: '<S10>/Switch2' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Sum: '<S10>/Sum'
       *  UnitDelay: '<S10>/Unit Delay2'
       */
      View_Speed_ARID_DEF.Igntran_timer_count++;
    }

    /* End of Switch: '<S10>/Switch2' */
    /* End of Outputs for SubSystem: '<S9>/Debounce timer for Ignoring samples' */
    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */

    /* SignalConversion generated from: '<S9>/Display_unit' incorporates:
     *  Inport: '<Root>/rp_DispDistanceUnit_DisplayUnit'
     */
    (void)Rte_Read_rp_DispDistanceUnit_DisplayUnit
      (&View_Speed_ARID_DEF.Display_unit);
    (void)Rte_Read_rp_SPD_Trim2_Status_Spd_Trim2_Status(&tmpRead_3);
    (void)Rte_Read_rp_SPD_Target2_Status_Spd_Target2_Status(&rtb_Merge);
    (void)Rte_Read_rp_SPD_Trim_Status_Spd_Trim_Status(&tmpRead_1);
    (void)Rte_Read_rp_SPD_Target_Status_Spd_Target_Status(&tmpRead_0);

    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S9>/Debounce timer for Ignoring samples' */
    /* Switch: '<S10>/Switch3' incorporates:
     *  Inport: '<Root>/rp_SPD_Target2_Status_Spd_Target2_Status'
     *  Inport: '<Root>/rp_SPD_Target_Status_Spd_Target_Status'
     *  Inport: '<Root>/rp_SPD_Trim2_Status_Spd_Trim2_Status'
     *  Inport: '<Root>/rp_SPD_Trim_Status_Spd_Trim_Status'
     *  Product: '<S9>/Max_t1_count_250ms'
     *  RelationalOperator: '<S10>/Relational Operator4'
     *  UnitDelay: '<S10>/Unit Delay2'
     */
    if (View_Speed_ARID_DEF.Igntran_timer_count >= ((uint32)tmpRead)) {
      View_Speed_ARID_DEF.Igntran_timer_count = (uint32)tmpRead;
    }

    /* End of Switch: '<S10>/Switch3' */
    /* End of Outputs for SubSystem: '<S9>/Debounce timer for Ignoring samples' */

    /* Truth Table: '<S9>/Truth Table' incorporates:
     *  UnitDelay: '<S9>/Unit Delay2'
     */
    Speed_Value_Update(tmpRead_0, tmpRead_1, View_Speed_ARID_DEF.Prev_Speed_k,
                       &View_Speed_ARID_DEF.Prev_Speed_k);

    /* Product: '<S9>/Divide2' incorporates:
     *  Constant: '<S9>/Constant2'
     *  UnitDelay: '<S9>/Unit Delay2'
     */
    if (((uint16)RESOLUTION_100) == 0U) {
      tmpRead_1 = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      tmpRead_1 = (uint16)(((uint32)View_Speed_ARID_DEF.Prev_Speed_k) / ((uint32)
        ((uint16)RESOLUTION_100)));
    }

    /* Truth Table: '<S9>/Truth Table1' incorporates:
     *  UnitDelay: '<S9>/Unit Delay1'
     */
    Speed_Value_Update(rtb_Merge, tmpRead_3, View_Speed_ARID_DEF.Prev_Speed_m,
                       &View_Speed_ARID_DEF.Prev_Speed_m);

    /* Product: '<S9>/Divide1' incorporates:
     *  Constant: '<S9>/Constant5'
     *  UnitDelay: '<S9>/Unit Delay1'
     */
    if (((uint16)RESOLUTION_100) == 0U) {
      tmpRead_3 = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      tmpRead_3 = (uint16)(((uint32)View_Speed_ARID_DEF.Prev_Speed_m) / ((uint32)
        ((uint16)RESOLUTION_100)));
    }

    /* If: '<S11>/If' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S11>/Constant5'
     *  Constant: '<S11>/Constant6'
     */
    if (((rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_USA)) ||
         (rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_UK))) ||
        (rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_KOREA_FMVSS))) {
      /* Outputs for IfAction SubSystem: '<S11>/USA_UK' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* If: '<S19>/If' incorporates:
       *  Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal'
       *  Product: '<S9>/Divide1'
       *  Product: '<S9>/Divide2'
       */
      if (View_Speed_ARID_DEF.Display_unit == 0U) {
        /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        View_Speed_IfActionSubsystem(tmpRead_1, tmpRead_3, &rtb_Merge,
          &View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis);

        /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal' incorporates:
         *  Constant: '<S27>/Constant'
         *  SignalConversion generated from: '<S27>/Disp_Sub_Speed'
         */
        View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis = ((uint16)C_BLANK);

        /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
      }

      /* End of If: '<S19>/If' */
      /* End of Outputs for SubSystem: '<S11>/USA_UK' */
    } else if ((rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_CANADA)) ||
               (rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_EUROPE))) {
      /* Outputs for IfAction SubSystem: '<S11>/CANADA_EUROPE' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      /* If: '<S17>/If' incorporates:
       *  Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal'
       *  Product: '<S9>/Divide1'
       *  Product: '<S9>/Divide2'
       */
      if (View_Speed_ARID_DEF.Display_unit == 0U) {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        /* Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal' incorporates:
         *  Constant: '<S22>/Constant'
         *  SignalConversion generated from: '<S22>/Disp_Sub_Speed'
         */
        View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis = ((uint16)C_BLANK);

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S23>/Action Port'
         */
        View_Speed_IfActionSubsystem(tmpRead_3, tmpRead_1, &rtb_Merge,
          &View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis);

        /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
      }

      /* End of If: '<S17>/If' */
      /* End of Outputs for SubSystem: '<S11>/CANADA_EUROPE' */
    } else if ((rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_MEXICO_FMVSS)) ||
               (rtb_TmpSignalConversionAtrp_SPD == ((uint8)eSP_MEXICO_UN_R))) {
      /* Outputs for IfAction SubSystem: '<S11>/MEXICO' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* If: '<S18>/If' incorporates:
       *  Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal'
       *  Product: '<S9>/Divide1'
       *  Product: '<S9>/Divide2'
       */
      if (View_Speed_ARID_DEF.Display_unit == 0U) {
        /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        View_Speed_IfActionSubsystem(tmpRead_1, tmpRead_3, &rtb_Merge,
          &View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis);

        /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S25>/Action Port'
         */
        View_Speed_IfActionSubsystem(tmpRead_3, tmpRead_1, &rtb_Merge,
          &View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis);

        /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
      }

      /* End of If: '<S18>/If' */
      /* End of Outputs for SubSystem: '<S11>/MEXICO' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/ADR_ECE' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* If: '<S16>/If' incorporates:
       *  Constant: '<S20>/Constant1'
       *  Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal'
       *  SignalConversion generated from: '<S20>/Disp_Sub_Speed'
       */
      View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis = ((uint16)C_BLANK);

      /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */
      /* End of Outputs for SubSystem: '<S11>/ADR_ECE' */
    }

    /* End of If: '<S11>/If' */

    /* Update for UnitDelay: '<S9>/Unit Delay5' */
    View_Speed_ARID_DEF.PrevWUSIgnState1 = rtb_TmpSignalConversionAtrpIgnS;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Outport: '<Root>/pp_Display_speed_Value_Digital_Speed_Value' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/Out1'
     */
    (void)Rte_Write_pp_Display_speed_Value_Digital_Speed_Value((uint16)0U);

    /* Outport: '<Root>/pp_SubDisplaySpeed_Value_SubDispSpeedVal' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/Out2'
     */
    View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis = 0U;

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
  }

  /* End of If: '<S5>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/View_Speed_Task' */

  /* Outport: '<Root>/pp_SubSpeedUnit_Value_SubSpeedunit' */
  (void)Rte_Write_pp_SubSpeedUnit_Value_SubSpeedunit
    (View_Speed_ARID_DEF.Display_unit);
  (void)Rte_Write_pp_SubDisplaySpeed_Value_SubDispSpeedVal
    (View_Speed_ARID_DEF.pp_SubDisplaySpeed_Value_SubDis);
}

/* Output function */
FUNC(void, View_Speed_CODE) view_speed_init_1(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, View_Speed_CODE) View_Speed_Init(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  View_Speed_ARID_DEF.NVM_MCUID0256 = ((uint16)C_MCUID0256_VALUE);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  View_Speed_ARID_DEF.NVM_MCUID0257 = ((uint8)C_MCUID0257_VALUE);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  View_Speed_ARID_DEF.NVM_MCUID0260 = ((uint16)C_MCUID0260_VALUE);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  View_Speed_ARID_DEF.NVM_MCUID0261 = ((uint8)C_MCUID0261_VALUE);

  /* SystemInitialize for Outport: '<Root>/pp_SubSpeedUnit_Value_SubSpeedunit' */
  (void)Rte_Write_pp_SubSpeedUnit_Value_SubSpeedunit
    (View_Speed_ARID_DEF.Display_unit);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
