/*
 * File: Mdl_Tacho.c
 *
 * Code generated for Simulink model 'Mdl_Tacho'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Aug 21 10:52:24 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_Tacho.h"
#include "Platform_Types.h"
#include "Rte_Type.h"
#include "Rte_Mdl_Tacho.h"
#include "Mdl_Tacho_config.cfg"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_ACTIVE
#error The value of parameter "CLUSTER_ACTIVE" is not defined
#endif

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

#ifndef RTE_E_OK
#error The value of parameter "RTE_E_OK" is not defined
#endif

#ifndef eEngineSpeedIn
#error The value of parameter "eEngineSpeedIn" is not defined
#endif

#ifndef eFUNC_NORTH_AMERICA
#error The value of parameter "eFUNC_NORTH_AMERICA" is not defined
#endif

#ifndef eJust_Received
#error The value of parameter "eJust_Received" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_Mdl_Tacho_T, Mdl_Tacho_VAR_INIT) Mdl_Tacho_ARID_DEF;

/* '<Root>/Data Store Memory10' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_IGN_OFF_ON_Transition(void);
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tac_Accumulation_Processing(void);
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_Hysteris_Process_Output(void);
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_Average_Calculation(void);
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_NE1_Missing_Notify(void);

/* Output and update for atomic system: '<S5>/IGN_OFF_ON_Transition' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_IGN_OFF_ON_Transition(void)
{
  /* Logic: '<S14>/Logical Operator11' incorporates:
   *  Constant: '<S14>/Constant12'
   *  Constant: '<S14>/Constant8'
   *  RelationalOperator: '<S14>/Relational Operator7'
   *  RelationalOperator: '<S14>/Relational Operator8'
   *  UnitDelay: '<S14>/Unit Delay5'
   */
  Mdl_Tacho_ARID_DEF.LogicalOperator11 = ((Mdl_Tacho_ARID_DEF.PrevWUSIgnState ==
    ((IgntionSubstateType)((uint8)IgnOff))) &&
    (Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrpIgnSubst == ((IgntionSubstateType)
    ((uint8)IgnOn))));

  /* Update for UnitDelay: '<S14>/Unit Delay5' */
  Mdl_Tacho_ARID_DEF.PrevWUSIgnState =
    Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrpIgnSubst;
}

/* Output and update for atomic system: '<S15>/Accumulation_Processing' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tac_Accumulation_Processing(void)
{
  /* Switch: '<S20>/Switch3' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S26>/Constant'
   *  Logic: '<S20>/AND'
   *  RelationalOperator: '<S25>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   */
  if ((Mdl_Tacho_ARID_DEF.RxCan_GetSignalValue_o2 != ((uint8)eSIGNAL_MISSING)) &&
      (Mdl_Tacho_ARID_DEF.RxCan_GetSignalValue_o2 != ((uint8)
        eSIGNAL_NEVER_RECEIVED))) {
    /* Switch: '<S20>/Switch' */
    if (Mdl_Tacho_ARID_DEF.DataTypeConversion >= ((uint16)TACHO_THRESHOLD)) {
      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       */
      Mdl_Tacho_ARID_DEF.Switch = ((uint16)TACHO_COUNT_INIT_U16);
    } else {
      /* Switch: '<S21>/Switch' */
      Mdl_Tacho_ARID_DEF.Switch = Mdl_Tacho_ARID_DEF.DataTypeConversion;
    }
  } else {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S20>/Constant3'
     *  Switch: '<S20>/Switch'
     */
    Mdl_Tacho_ARID_DEF.Switch = 0U;
  }

  /* End of Switch: '<S20>/Switch3' */
}

/* Output and update for atomic system: '<S21>/Subsystem' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_Hysteris_Process_Output(void)
{
  /* If: '<S32>/If' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant2'
   *  DataStoreRead: '<S21>/Data Store Read'
   *  Logic: '<S32>/Logical Operator'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator1'
   *  RelationalOperator: '<S32>/Relational Operator2'
   */
  if (Mdl_Tacho_ARID_DEF.Current_NE_AVG < ((uint16)TACHO_RPM_THRESHOLD)) {
    /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Merge: '<S32>/Merge' incorporates:
     *  Constant: '<S33>/Constant'
     *  SignalConversion generated from: '<S33>/TachoCalculatedValue_Case1 '
     */
    Mdl_Tacho_ARID_DEF.Merge_a = 0U;

    /* End of Outputs for SubSystem: '<S32>/If Action Subsystem' */
  } else if ((((uint16)TACHO_RPM_THRESHOLD) <= Mdl_Tacho_ARID_DEF.Current_NE_AVG)
             && (Mdl_Tacho_ARID_DEF.Current_NE_AVG < ((uint16)TACHO_HYS_MAX))) {
    /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* If: '<S34>/If' incorporates:
     *  Constant: '<S34>/Constant1'
     *  Constant: '<S34>/Constant2'
     *  DataStoreRead: '<S21>/Data Store Read2'
     *  Logic: '<S34>/Logical Operator'
     *  Logic: '<S34>/Logical Operator1'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator1'
     *  RelationalOperator: '<S34>/Relational Operator2'
     *  RelationalOperator: '<S34>/Relational Operator3'
     *  Sum: '<S34>/Subtract'
     *  Sum: '<S34>/Subtract1'
     */
    if ((Mdl_Tacho_ARID_DEF.Current_NE_AVG < Mdl_Tacho_ARID_DEF.Prev_NE_Out) &&
        (((uint16)(Mdl_Tacho_ARID_DEF.Prev_NE_Out -
                   Mdl_Tacho_ARID_DEF.Current_NE_AVG)) > ((uint16)TACHO_HYS_MIN)))
    {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* Merge: '<S32>/Merge' incorporates:
       *  Constant: '<S36>/Constant2'
       *  Sum: '<S36>/Add'
       */
      Mdl_Tacho_ARID_DEF.Merge_a = (uint16)(Mdl_Tacho_ARID_DEF.Current_NE_AVG +
        ((uint16)TACHO_HYS_MIN));

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */
    } else if ((Mdl_Tacho_ARID_DEF.Current_NE_AVG >
                Mdl_Tacho_ARID_DEF.Prev_NE_Out) && (((uint16)
                 (Mdl_Tacho_ARID_DEF.Current_NE_AVG -
                  Mdl_Tacho_ARID_DEF.Prev_NE_Out)) > ((uint16)TACHO_HYS_MIN))) {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* Merge: '<S32>/Merge' incorporates:
       *  Constant: '<S37>/Constant2'
       *  Sum: '<S37>/Subtract'
       */
      Mdl_Tacho_ARID_DEF.Merge_a = (uint16)(Mdl_Tacho_ARID_DEF.Current_NE_AVG -
        ((uint16)TACHO_HYS_MIN));

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Merge: '<S32>/Merge' incorporates:
       *  SignalConversion generated from: '<S38>/Old_NE_Avg'
       */
      Mdl_Tacho_ARID_DEF.Merge_a = Mdl_Tacho_ARID_DEF.Prev_NE_Out;

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */
    }

    /* End of If: '<S34>/If' */
    /* End of Outputs for SubSystem: '<S32>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Merge: '<S32>/Merge' incorporates:
     *  SignalConversion generated from: '<S35>/Current_NE_AVG'
     */
    Mdl_Tacho_ARID_DEF.Merge_a = Mdl_Tacho_ARID_DEF.Current_NE_AVG;

    /* End of Outputs for SubSystem: '<S32>/If Action Subsystem2' */
  }

  /* End of If: '<S32>/If' */
}

/* Output and update for atomic system: '<S15>/Average_Calculation' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_Average_Calculation(void)
{
  uint32 tmp;

  /* Switch: '<S21>/Switch1' incorporates:
   *  RelationalOperator: '<S29>/Compare'
   */
  if (Mdl_Tacho_ARID_DEF.LogicalOperator11) {
    /* Switch: '<S21>/Switch1' incorporates:
     *  Constant: '<S21>/Constant5'
     */
    Mdl_Tacho_ARID_DEF.Current_NE_AVG = 0U;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  Product: '<S21>/Multiply'
   */
  if (TACHO_RES_DIVIDER == 0U) {
    tmp = ((uint32)(0xFFFFFFFFU));

    /* Divide by zero handler */
  } else {
    tmp = (((uint32)Mdl_Tacho_ARID_DEF.Switch) * TACHO_RESOLUTION) /
      TACHO_RES_DIVIDER;
  }

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Constant: '<S28>/Constant'
   *  DataTypeConversion: '<S21>/Data Type Conversion1'
   *  Product: '<S21>/Divide'
   *  Product: '<S21>/Divide1'
   *  Product: '<S21>/Multiply'
   *  RelationalOperator: '<S28>/Compare'
   *  Sum: '<S21>/Add'
   */
  if (((uint16)((tmp + 5U) / 10U)) < ((uint16)TACHO_RPM_THRESHOLD)) {
    Mdl_Tacho_ARID_DEF.Switch = 0U;
  } else {
    if (TACHO_RES_DIVIDER == 0U) {
      tmp = ((uint32)(0xFFFFFFFFU));

      /* Divide by zero handler */
    } else {
      tmp = (((uint32)Mdl_Tacho_ARID_DEF.Switch) * TACHO_RESOLUTION) /
        TACHO_RES_DIVIDER;
    }

    Mdl_Tacho_ARID_DEF.Switch = (uint16)((tmp + 5U) / 10U);
  }

  /* End of Switch: '<S21>/Switch' */

  /* If: '<S21>/If' incorporates:
   *  Constant: '<S27>/Constant'
   *  DataStoreRead: '<S31>/Data Store Read1'
   *  Product: '<S31>/Divide'
   *  RelationalOperator: '<S27>/Compare'
   */
  if (Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrp_SPD_SP1 > ((uint16)
       SPD_THRESHOLD)) {
    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* Product: '<S30>/Divide' incorporates:
     *  DataStoreRead: '<S30>/Data Store Read1'
     */
    if (Mdl_Tacho_ARID_DEF.N1_i == 0U) {
      /* DataStoreWrite: '<S21>/Data Store Write' */
      Mdl_Tacho_ARID_DEF.Current_NE_AVG = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
       *  Constant: '<S30>/Constant1'
       *  DataStoreRead: '<S30>/Data Store Read'
       *  DataTypeConversion: '<S30>/Data Type Conversion'
       *  Product: '<S30>/Multiply'
       *  Sum: '<S30>/Add'
       *  Sum: '<S30>/Subtract'
       */
      Mdl_Tacho_ARID_DEF.Current_NE_AVG = (uint16)((((((uint32)
        Mdl_Tacho_ARID_DEF.N1_i) - 1U) * ((uint32)
        Mdl_Tacho_ARID_DEF.Current_NE_AVG)) + ((uint32)Mdl_Tacho_ARID_DEF.Switch))
        / ((uint32)Mdl_Tacho_ARID_DEF.N1_i));
    }

    /* End of Product: '<S30>/Divide' */
    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
  } else if (Mdl_Tacho_ARID_DEF.N2_j == 0U) {
    /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
     *  Product: '<S31>/Divide'
     */
    Mdl_Tacho_ARID_DEF.Current_NE_AVG = ((uint16)(65535U));

    /* Product: '<S31>/Divide' */
    /* Divide by zero handler */
  } else {
    /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
     *  Constant: '<S31>/Constant1'
     *  DataStoreRead: '<S31>/Data Store Read'
     *  DataStoreRead: '<S31>/Data Store Read1'
     *  DataTypeConversion: '<S31>/Data Type Conversion'
     *  Product: '<S31>/Divide'
     *  Product: '<S31>/Multiply'
     *  Sum: '<S31>/Add'
     *  Sum: '<S31>/Subtract'
     */
    Mdl_Tacho_ARID_DEF.Current_NE_AVG = (uint16)((((((uint32)
      Mdl_Tacho_ARID_DEF.N2_j) - 1U) * ((uint32)
      Mdl_Tacho_ARID_DEF.Current_NE_AVG)) + ((uint32)Mdl_Tacho_ARID_DEF.Switch))
      / ((uint32)Mdl_Tacho_ARID_DEF.N2_j));

    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */
  }

  /* End of If: '<S21>/If' */

  /* Outputs for Atomic SubSystem: '<S21>/Subsystem' */
  Mdl_Tacho_Hysteris_Process_Output();

  /* End of Outputs for SubSystem: '<S21>/Subsystem' */

  /* DataStoreWrite: '<S21>/Data Store Write1' */
  Mdl_Tacho_ARID_DEF.Prev_NE_Out = Mdl_Tacho_ARID_DEF.Merge_a;
}

/* Output and update for atomic system: '<S5>/NE1_Missing_Notify' */
static FUNC(void, Mdl_Tacho_CODE_LOCAL) Mdl_Tacho_NE1_Missing_Notify(void)
{
  uint8 rtb_Divide_k_0;

  /* If: '<S17>/If' incorporates:
   *  Constant: '<S48>/Constant'
   *  RelationalOperator: '<S48>/Compare'
   */
  if (Mdl_Tacho_ARID_DEF.RxCan_GetSignalValue_o2 != ((uint8)
       RTE_E_MAX_AGE_EXCEEDED)) {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* Product: '<S49>/Divide' incorporates:
     *  Constant: '<S49>/Constant'
     *  Constant: '<S49>/Constant3'
     */
    if (Mdl_Tacho_cTaskPeriod == 0U) {
      rtb_Divide_k_0 = ((uint8)(255U));

      /* Divide by zero handler */
    } else {
      rtb_Divide_k_0 = (uint8)(((uint32)((uint8)TACHO_DEBOUNCE_TIME)) / ((uint32)
        Mdl_Tacho_cTaskPeriod));
    }

    /* Switch: '<S52>/Switch2' incorporates:
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S51>/Compare'
     *  RelationalOperator: '<S52>/Relational Operator1'
     */
    if (((uint8)eJust_Received) == 0U) {
      /* Switch: '<S52>/Switch2' incorporates:
       *  Constant: '<S52>/Constant2'
       */
      Mdl_Tacho_ARID_DEF.DebounceIndex = ((uint8)TACHO_COUNT_INIT);
    } else {
      /* Switch: '<S52>/Switch2' incorporates:
       *  Constant: '<S52>/Constant1'
       *  Sum: '<S52>/Sum'
       *  UnitDelay: '<S52>/DebounceIndex'
       */
      Mdl_Tacho_ARID_DEF.DebounceIndex = (uint8)((sint32)(((sint32)
        Mdl_Tacho_ARID_DEF.DebounceIndex) + 1));
    }

    /* End of Switch: '<S52>/Switch2' */

    /* Switch: '<S52>/NE1_Status' incorporates:
     *  Product: '<S49>/Divide'
     *  RelationalOperator: '<S52>/check count'
     */
    if (Mdl_Tacho_ARID_DEF.DebounceIndex >= rtb_Divide_k_0) {
      /* Update for UnitDelay: '<S52>/DebounceIndex' */
      Mdl_Tacho_ARID_DEF.DebounceIndex = rtb_Divide_k_0;
    }

    /* End of Switch: '<S52>/NE1_Status' */
    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
  }

  /* End of If: '<S17>/If' */
}

/* Model step function for TID1 */
FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Task(void) /* Explicit Task: Mdl_Tacho_Task */
{
  sint32 q0;
  uint32 tmp;
  uint16 tmp_0;
  ClusterModes rtb_TmpSignalConversionAtrp_Clu;
  CountryCode_FuncType tmpRead_0;
  sint8 s44_iter;
  uint8 rtb_RxCan_GetSignalValue_o1;
  uint8 tmpRead;
  boolean rtb_Tachometer_applicable_flag;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Tacho_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Tacho_Task_sys'
   */
  /* Outport: '<Root>/pp_NE_Out_CalTachoValue' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  (void)Rte_Write_pp_NE_Out_CalTachoValue((uint16)0U);

  /* FunctionCaller: '<S6>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eEngineSpeedIn),
    &rtb_RxCan_GetSignalValue_o1, &Mdl_Tacho_ARID_DEF.RxCan_GetSignalValue_o2);

  /* SignalConversion generated from: '<S2>/rp_ClusterMode_WSSCurrentClusterMode' incorporates:
   *  Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode'
   */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode
    (&rtb_TmpSignalConversionAtrp_Clu);

  /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  /* Logic: '<S5>/AND' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  DataStoreRead: '<S5>/Data Store Read2'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   */
  if ((rtb_TmpSignalConversionAtrp_Clu == ((ClusterModes)((uint8)CLUSTER_ACTIVE)))
      && (Mdl_Tacho_ARID_DEF.l_Tacho_init_MCUID == ((uint8)VAL_ZERO))) {
    /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
     *  Constant: '<S18>/Constant6'
     */
    Mdl_Tacho_ARID_DEF.l_Tacho_init_MCUID = ((uint8)VAL_ONE);
  }

  /* End of Logic: '<S5>/AND' */
  /* End of Outputs for SubSystem: '<S5>/Subsystem' */

  /* SignalConversion generated from: '<S2>/rpIgnSubstate_IgnitionSubstate' incorporates:
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate
    (&Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrpIgnSubst);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Tacho_Task' */

  /* Inport: '<Root>/rp_PowerTrain_State_PowerTrain_Flag' */
  /*  Tacho gauge applicable check according to PTsys */
  (void)Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Tacho_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Tacho_Task_sys'
   */
  /* Truth Table: '<S5>/Tachometer_applicable_flag' */
  if (((((((tmpRead == ((uint8)PTSYS_DEFAULT)) || (tmpRead == ((uint8)PTSYS_CONV)))
          || (tmpRead == ((uint8)PTSYS_S_S))) || (tmpRead == ((uint8)PTSYS_HV)))
        || (tmpRead == ((uint8)PTSYS_PHV))) || (tmpRead == ((uint8)PTSYS_MOTORHV)))
      || (tmpRead == ((uint8)PTSYS_48V))) {
    /*  Tacho applicable */
    rtb_Tachometer_applicable_flag = TACHO_ENABLE;
  } else {
    /*  Default */
    /*  Tacho not applicable */
    rtb_Tachometer_applicable_flag = TACHO_DISABLE;
  }

  /* End of Truth Table: '<S5>/Tachometer_applicable_flag' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  Mdl_Tacho_ARID_DEF.DataTypeConversion = (uint16)rtb_RxCan_GetSignalValue_o1;

  /* Outputs for Atomic SubSystem: '<S5>/IGN_OFF_ON_Transition' */
  Mdl_Tacho_IGN_OFF_ON_Transition();

  /* End of Outputs for SubSystem: '<S5>/IGN_OFF_ON_Transition' */

  /* SignalConversion generated from: '<S2>/rp_SPD_SP1_In_Status_SP1_In_Status' incorporates:
   *  Inport: '<Root>/rp_SPD_SP1_In_Status_SP1_In_Status'
   */
  (void)Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status
    (&Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrp_SPD_SP1);

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataStoreRead: '<S16>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  Inport: '<Root>/rp_Country_Code_Func_CountryCode_Func'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  if ((((rtb_TmpSignalConversionAtrp_Clu != ((ClusterModes)((uint8)
           CLUSTER_INACTIVE))) &&
        (Mdl_Tacho_ARID_DEF.TmpSignalConversionAtrpIgnSubst !=
         ((IgntionSubstateType)((uint8)IgnOff)))) &&
       (rtb_Tachometer_applicable_flag != TACHO_DISABLE)) &&
      (Mdl_Tacho_ARID_DEF.l_Tacho_init_MCUID == ((uint8)VAL_ONE))) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S15>/Accumulation_Processing' */
    Mdl_Tac_Accumulation_Processing();

    /* End of Outputs for SubSystem: '<S15>/Accumulation_Processing' */

    /* Outputs for Atomic SubSystem: '<S15>/Average_Calculation' */
    Mdl_Tacho_Average_Calculation();

    /* End of Outputs for SubSystem: '<S15>/Average_Calculation' */

    /* Assignment: '<S40>/Assignment' incorporates:
     *  DataStoreRead: '<S40>/Data Store Read'
     */
    Mdl_Tacho_ARID_DEF.NE_IN_ForDigitalTacho[Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex]
      = Mdl_Tacho_ARID_DEF.Switch;

    /* If: '<S41>/If' incorporates:
     *  Constant: '<S41>/Constant1'
     *  DataStoreRead: '<S41>/Data Store Read2'
     */
    if (Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex < ((uint8)TACHO_COUNT_TWO)) {
      /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* DataStoreWrite: '<S42>/Data Store Write' incorporates:
       *  Constant: '<S42>/Constant'
       *  DataStoreRead: '<S42>/Data Store Read1'
       *  Sum: '<S42>/Add'
       */
      Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex += ((uint8)TACHO_COUNT_ONE);

      /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* DataStoreWrite: '<S43>/Data Store Write' incorporates:
       *  Constant: '<S43>/Constant'
       */
      Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex = ((uint8)TACHO_COUNT_INIT);

      /* Sum: '<S44>/Sum' incorporates:
       *  Constant: '<S43>/Constant9'
       *  DataStoreWrite: '<S43>/Data Store Write4'
       */
      Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum = TACHO_VAL_ZERO_U32;

      /* Outputs for Iterator SubSystem: '<S43>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S44>/For Iterator'
       */
      for (s44_iter = 0; s44_iter < ((sint8)TACHO_COUNT_THREE_INT); s44_iter++)
      {
        /* Sum: '<S44>/Sum' incorporates:
         *  DataStoreRead: '<S44>/Data Store Read'
         *  Selector: '<S44>/Selector'
         */
        q0 = (sint32)Mdl_Tacho_ARID_DEF.NE_IN_ForDigitalTacho[s44_iter];
        Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum += /*MW:OvSatOk*/ (uint32)q0;
        if (Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum < ((uint32)q0)) {
          Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum = ((uint32)(0xFFFFFFFFU));
        }

        /* Product: '<S44>/Divide' incorporates:
         *  Constant: '<S44>/Constant'
         *  Sum: '<S44>/Sum'
         */
        if (((uint8)TACHO_VAL_THREE) == 0U) {
          tmp = ((uint32)(0xFFFFFFFFU));

          /* Divide by zero handler */
        } else {
          tmp = Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum / ((uint32)((uint8)
            TACHO_VAL_THREE));
        }

        if (tmp > 65535U) {
          tmp = 65535U;
        }

        /* Product: '<S44>/Divide' */
        Mdl_Tacho_ARID_DEF.Divide = (uint16)tmp;
      }

      /* End of Outputs for SubSystem: '<S43>/For Iterator Subsystem' */

      /* Merge: '<S41>/Merge' incorporates:
       *  SignalConversion generated from: '<S43>/NE_IN_ForDigitalTacho__Out'
       */
      Mdl_Tacho_ARID_DEF.DigitalTacho__Out = Mdl_Tacho_ARID_DEF.Divide;

      /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */
    }

    /* End of If: '<S41>/If' */
    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    (void)Rte_Read_rp_Country_Code_Func_CountryCode_Func(&tmpRead_0);

    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Outport: '<Root>/pp_Analog_Tacho_Analog_Tacho' incorporates:
     *  Inport: '<Root>/rp_Country_Code_Func_CountryCode_Func'
     *  SignalConversion generated from: '<S15>/Tacho_Analog_Out'
     */
    (void)Rte_Write_pp_Analog_Tacho_Analog_Tacho(Mdl_Tacho_ARID_DEF.Merge_a);

    /* Outport: '<Root>/pp_Needle_Transparent_Needle_TR' incorporates:
     *  SignalConversion generated from: '<S15>/HMI_TC_NEEDLE_TRANSPARENT'
     */
    (void)Rte_Write_pp_Needle_Transparent_Needle_TR((uint8)0U);

    /* Outport: '<Root>/pp_TC_Unit_Digital_TachoUnit' incorporates:
     *  Constant: '<S22>/Constant'
     *  RelationalOperator: '<S22>/Compare'
     *  Switch: '<S15>/Switch2'
     */
    (void)Rte_Write_pp_TC_Unit_Digital_TachoUnit(tmpRead_0 ==
      ((CountryCode_FuncType)((uint8)eFUNC_NORTH_AMERICA)));

    /* Outport: '<Root>/pp_Revp_Disp_REVP_DISP' incorporates:
     *  Constant: '<S15>/Constant6'
     *  SignalConversion generated from: '<S15>/HMI_TC_REVP_DISP'
     */
    (void)Rte_Write_pp_Revp_Disp_REVP_DISP(FALSE);

    /* Outport: '<Root>/pp_Tacho_Revp_RPM_REVP_RPM' incorporates:
     *  Constant: '<S15>/Constant7'
     *  SignalConversion generated from: '<S15>/HMI_TC_REVP_RPM'
     */
    (void)Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(((uint16)TACHO_VAL_ZERO_U16));

    /* Outport: '<Root>/pp_Tacho_RED_Start_RPM_RED_Start_RPM' incorporates:
     *  SignalConversion generated from: '<S15>/HMI_TC_RED_START_RPM'
     */
    (void)Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM((uint8)0U);

    /* Math: '<S15>/Mod' incorporates:
     *  Constant: '<S15>/Constant'
     *  DataStoreRead: '<S15>/Data Store Read2'
     */
    if (((uint8)TACHO_TEN) == 0U) {
      rtb_RxCan_GetSignalValue_o1 = Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX;
    } else {
      rtb_RxCan_GetSignalValue_o1 = (uint8)(Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX %
        ((uint8)TACHO_TEN));
    }

    /* End of Math: '<S15>/Mod' */

    /* Switch: '<S15>/Switch1' */
    if (rtb_RxCan_GetSignalValue_o1 != 0U) {
      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/Constant1'
       *  DataStoreRead: '<S15>/Data Store Read4'
       */
      if (((uint8)TACHO_TEN) == 0U) {
        rtb_RxCan_GetSignalValue_o1 = ((uint8)(255U));

        /* Divide by zero handler */
      } else {
        rtb_RxCan_GetSignalValue_o1 = (uint8)(((uint32)
          Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX) / ((uint32)((uint8)TACHO_TEN)));
      }

      /* Switch: '<S15>/Switch1' incorporates:
       *  Constant: '<S15>/Constant2'
       *  Constant: '<S15>/Constant5'
       *  Product: '<S15>/Divide'
       *  Product: '<S15>/Multiply'
       *  Sum: '<S15>/Add'
       */
      rtb_RxCan_GetSignalValue_o1 = (uint8)(((uint8)(rtb_RxCan_GetSignalValue_o1
        * ((uint8)TACHO_TEN))) + ((uint8)TACHO_TEN));
    } else {
      /* Switch: '<S15>/Switch1' incorporates:
       *  DataStoreRead: '<S15>/Data Store Read3'
       */
      rtb_RxCan_GetSignalValue_o1 = Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX;
    }

    /* End of Switch: '<S15>/Switch1' */

    /* Outport: '<Root>/pp_Tacho_RPM_MAX_REVP_RPM_MAX' incorporates:
     *  Constant: '<S15>/Constant8'
     *  Sum: '<S15>/Add1'
     */
    (void)Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX((uint8)
      (rtb_RxCan_GetSignalValue_o1 + ((uint8)TACHO_TEN)));

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S46>/Enable'
     */
    if (Mdl_Tacho_ARID_DEF.Battery_Connect_Flag != ((uint8)TACHO_VAL_ONE)) {
      /* DataStoreWrite: '<S46>/Data Store Write' incorporates:
       *  Constant: '<S46>/Constant'
       */
      Mdl_Tacho_ARID_DEF.Battery_Connect_Flag = ((uint8)TACHO_VAL_ONE);

      /* DataStoreWrite: '<S46>/Data Store Write3' incorporates:
       *  Constant: '<S46>/Constant10'
       */
      Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX = ((uint8)RZ_INIT_VAL);
    }

    /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem' */

    /* Math: '<S47>/Mod' incorporates:
     *  Constant: '<S47>/Constant12'
     *  DataStoreRead: '<S47>/Data Store Read2'
     */
    if (((uint8)TACHO_TEN) == 0U) {
      rtb_RxCan_GetSignalValue_o1 = Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX;
    } else {
      rtb_RxCan_GetSignalValue_o1 = (uint8)(Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX %
        ((uint8)TACHO_TEN));
    }

    /* End of Math: '<S47>/Mod' */

    /* Switch: '<S47>/Switch1' */
    if (rtb_RxCan_GetSignalValue_o1 != 0U) {
      /* Product: '<S47>/Divide' incorporates:
       *  Constant: '<S47>/Constant13'
       *  DataStoreRead: '<S47>/Data Store Read5'
       */
      if (((uint8)TACHO_TEN) == 0U) {
        rtb_RxCan_GetSignalValue_o1 = ((uint8)(255U));

        /* Divide by zero handler */
      } else {
        rtb_RxCan_GetSignalValue_o1 = (uint8)(((uint32)
          Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX) / ((uint32)((uint8)TACHO_TEN)));
      }

      /* Switch: '<S47>/Switch1' incorporates:
       *  Constant: '<S47>/Constant14'
       *  Constant: '<S47>/Constant15'
       *  Product: '<S47>/Divide'
       *  Product: '<S47>/Multiply'
       *  Sum: '<S47>/Add'
       */
      rtb_RxCan_GetSignalValue_o1 = (uint8)(((uint8)(rtb_RxCan_GetSignalValue_o1
        * ((uint8)TACHO_TEN))) + ((uint8)TACHO_TEN));
    } else {
      /* Switch: '<S47>/Switch1' incorporates:
       *  DataStoreRead: '<S47>/Data Store Read3'
       */
      rtb_RxCan_GetSignalValue_o1 = Mdl_Tacho_ARID_DEF.BURAM_RZ_MAX;
    }

    /* End of Switch: '<S47>/Switch1' */

    /* Outport: '<Root>/pp_Tacho_RPM_MAX_REVP_RPM_MAX' incorporates:
     *  Constant: '<S47>/Constant16'
     *  Sum: '<S47>/Add1'
     */
    (void)Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX((uint8)
      (rtb_RxCan_GetSignalValue_o1 + ((uint8)TACHO_TEN)));

    /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    Mdl_Tacho_ARID_DEF.Current_NE_AVG = ((uint16)TACHO_VAL_ZERO_U16);

    /* DataStoreWrite: '<S16>/Data Store Write5' incorporates:
     *  Constant: '<S16>/Constant10'
     */
    Mdl_Tacho_ARID_DEF.DigitalTacho__Out = ((uint16)TACHO_VAL_ZERO_U16);

    /* DataStoreWrite: '<S16>/Data Store Write2' incorporates:
     *  Constant: '<S16>/Constant11'
     */
    Mdl_Tacho_ARID_DEF.RZ_ST = ((uint8)RZ_INIT_VAL);

    /* DataStoreWrite: '<S16>/Data Store Write1' incorporates:
     *  Constant: '<S16>/Constant2'
     */
    Mdl_Tacho_ARID_DEF.Prev_NE_Out = ((uint16)TACHO_VAL_ZERO_U16);

    /* DataStoreWrite: '<S16>/Data Store Write3' incorporates:
     *  Constant: '<S16>/Constant8'
     */
    Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex = ((uint8)TACHO_COUNT_INIT);

    /* Sum: '<S44>/Sum' incorporates:
     *  Constant: '<S16>/Constant9'
     *  DataStoreWrite: '<S16>/Data Store Write4'
     */
    Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum = TACHO_VAL_ZERO_U32;

    /* Outport: '<Root>/pp_Analog_Tacho_Analog_Tacho' incorporates:
     *  Constant: '<S16>/Constant'
     *  SignalConversion generated from: '<S16>/TachCalcValue'
     */
    (void)Rte_Write_pp_Analog_Tacho_Analog_Tacho(((uint16)TACHO_VAL_ZERO_U16));

    /* Outport: '<Root>/pp_Needle_Transparent_Needle_TR' incorporates:
     *  Constant: '<S16>/Constant4'
     *  SignalConversion generated from: '<S16>/Inactive_Needle_Transparent'
     */
    (void)Rte_Write_pp_Needle_Transparent_Needle_TR(((uint8)TACHO_VAL_ZERO));

    /* Outport: '<Root>/pp_TC_Unit_Digital_TachoUnit' incorporates:
     *  Constant: '<S16>/Constant5'
     *  SignalConversion generated from: '<S16>/Inactive_TC_Unit'
     */
    (void)Rte_Write_pp_TC_Unit_Digital_TachoUnit(FALSE);

    /* Outport: '<Root>/pp_Revp_Disp_REVP_DISP' incorporates:
     *  Constant: '<S16>/Constant6'
     *  SignalConversion generated from: '<S16>/Inactive_Revp_Disp'
     */
    (void)Rte_Write_pp_Revp_Disp_REVP_DISP(FALSE);

    /* Outport: '<Root>/pp_Tacho_Revp_RPM_REVP_RPM' incorporates:
     *  Constant: '<S16>/Constant7'
     *  SignalConversion generated from: '<S16>/Inactive_Revp_RPM'
     */
    (void)Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(((uint16)TACHO_VAL_ZERO_U16));

    /* Outport: '<Root>/pp_Tacho_RED_Start_RPM_RED_Start_RPM' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read1'
     */
    (void)Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM
      (Mdl_Tacho_ARID_DEF.RZ_ST);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  }

  /* End of If: '<S5>/If' */

  /* Outputs for Atomic SubSystem: '<S5>/NE1_Missing_Notify' */
  Mdl_Tacho_NE1_Missing_Notify();

  /* End of Outputs for SubSystem: '<S5>/NE1_Missing_Notify' */

  /* Switch: '<S5>/Switch' */
  if (rtb_Tachometer_applicable_flag) {
    tmp_0 = Mdl_Tacho_ARID_DEF.DataTypeConversion;
  } else {
    tmp_0 = Mdl_Tacho_ARID_DEF.DigitalTacho__Out;
  }

  /* Outport: '<Root>/pp_Digital_Tacho_Digital_Tacho' incorporates:
   *  Switch: '<S5>/Switch'
   */
  (void)Rte_Write_pp_Digital_Tacho_Digital_Tacho(tmp_0);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Tacho_Task' */
}

/* Output function */
FUNC(void, Mdl_Tacho_CODE) mdl_tacho_init_1(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, Mdl_Tacho_CODE) Mdl_Tacho_Init(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  Mdl_Tacho_ARID_DEF.NVM_MCUID0025 = ((uint8)TACHO_VAL_ZERO);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Mdl_Tacho_ARID_DEF.Current_NE_AVG = ((uint16)NE_AVG_INIT);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  Mdl_Tacho_ARID_DEF.Prev_NE_Out = ((uint16)NE_AVG_INIT);

  /* Start for Sum: '<S44>/Sum' incorporates:
   *  DataStoreMemory: '<Root>/Data Store Memory10'
   */
  Mdl_Tacho_ARID_DEF.fl_digital_odo_Sum = TACHO_VAL_ZERO_U32;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory11' */
  Mdl_Tacho_ARID_DEF.DigitalTacho__Out = ((uint16)TACHO_VAL_ZERO_U16);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  Mdl_Tacho_ARID_DEF.N2_j = ((uint16)N2);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  Mdl_Tacho_ARID_DEF.N1_i = ((uint16)N1);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  Mdl_Tacho_ARID_DEF.DigtalTachoBuffIndex = ((uint8)TACHO_COUNT_INIT);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  Mdl_Tacho_ARID_DEF.l_Tacho_init_MCUID = ((uint8)VAL_ZERO);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  Mdl_Tacho_ARID_DEF.RZ_ST = ((uint8)RZ_INIT_VAL);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
