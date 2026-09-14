/*
 * File: Mdl_Speed.c
 *
 * Code generated for Simulink model 'Mdl_Speed'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Jul  3 12:12:24 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_Speed.h"
#include "Platform_Types.h"
#include "Rte_Type.h"
#include "LookUp_U16_U16_SIMPLEST.h"
#include "Mdl_Digspeed_table_config.cfg"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_ACTIVE
#error The value of parameter "CLUSTER_ACTIVE" is not defined
#endif

#ifndef IgnOff
#error The value of parameter "IgnOff" is not defined
#endif

#ifndef IgnOn
#error The value of parameter "IgnOn" is not defined
#endif

#ifndef eIO_ADC_AI_TEMP_RTC
#error The value of parameter "eIO_ADC_AI_TEMP_RTC" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

#ifndef eVehicleSpeedABSIn
#error The value of parameter "eVehicleSpeedABSIn" is not defined
#endif

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_Mdl_Speed_T, Mdl_Speed_VAR_INIT) Mdl_Speed_ARID_DEF;

/* '<Root>/Data Store Memory' */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Interpolation_Other_Region(VAR(uint16,
  AUTOMATIC) rtu_Spd_Avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT)
  rty_Interpolated_Data, CONST(uint16, AUTOMATIC) rtd_DSpeed_Int_Ref_Other[21]);
static FUNC(void, Mdl_Speed_CODE_LOCAL) Mdl_Speed_EUROPE_UK(VAR(uint16,
  AUTOMATIC) rtu_Spd_Avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT)
  rty_Speed_ind, CONST(uint16, AUTOMATIC) rtd_DSpeed_Int_Ref_Other[21]);
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_target(VAR(uint16, AUTOMATIC)
  rtu_Speed_int, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT) rty_speed_trg);
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_trimming_Init(P2VAR(uint16,
  AUTOMATIC, Mdl_Speed_VAR_INIT) rty_Speed_trim);
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_trimming(VAR(uint16, AUTOMATIC)
  rtu_speed_avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT) rty_Speed_trim);
static FUNC(void, Mdl_Speed_CODE_LOCAL) Interpolation_US_CANADA_MEXICO_Region
  (void);

/* Output and update for atomic system: '<S18>/Subsystem' */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Interpolation_US_CANADA_MEXICO_Region
  (void)
{
  sint32 i;
  uint16 rtb_DataStoreRead3[21];
  for (i = 0; i < 21; i++) {
    /* DataStoreRead: '<S36>/Data Store Read3' */
    rtb_DataStoreRead3[i] = Mdl_Speed_ARID_DEF.DSpeed_Int_Ref_US_CAN_MAX[i];
  }

  /* S-Function (sfix_look1_dyn): '<S36>/Lookup Table Dynamic' incorporates:
   *  Constant: '<S36>/Constant4'
   */
  /* Dynamic Look-Up Table Block: '<S36>/Lookup Table Dynamic'
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Integer        U16
   * Input2  Data Type:  Integer        U16
   * Output0 Data Type:  Integer        U16
   * Round Mode: Simplest
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_U16_U16_SIMPLEST( &(Mdl_Speed_ARID_DEF.LookupTableDynamic),
    &rtb_DataStoreRead3[0], Mdl_Speed_ARID_DEF.DataStoreRead, &SPEED_AVG_REF[0],
    20U);
}

/*
 * Output and update for atomic system:
 *    '<S15>/Subsystem'
 *    '<S14>/Subsystem'
 */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Interpolation_Other_Region(VAR(uint16,
  AUTOMATIC) rtu_Spd_Avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT)
  rty_Interpolated_Data, CONST(uint16, AUTOMATIC) rtd_DSpeed_Int_Ref_Other[21])
{
  sint32 i;
  uint16 rtb_DataStoreRead_c[21];
  for (i = 0; i < 21; i++) {
    /* DataStoreRead: '<S20>/Data Store Read' */
    rtb_DataStoreRead_c[i] = rtd_DSpeed_Int_Ref_Other[i];
  }

  /* S-Function (sfix_look1_dyn): '<S20>/Lookup Table Dynamic' incorporates:
   *  Constant: '<S20>/Constant4'
   */
  /* Dynamic Look-Up Table Block: '<S20>/Lookup Table Dynamic'
   * Input0  Data Type:  Integer        U16
   * Input1  Data Type:  Integer        U16
   * Input2  Data Type:  Integer        U16
   * Output0 Data Type:  Integer        U16
   * Round Mode: Simplest
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_U16_U16_SIMPLEST( &((*rty_Interpolated_Data)), &rtb_DataStoreRead_c[0],
    rtu_Spd_Avg, &SPEED_AVG_REF[0], 20U);
}

/*
 * Output and update for action system:
 *    '<S11>/EUROPE_UK'
 *    '<S11>/ADR_ECE'
 */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Mdl_Speed_EUROPE_UK(VAR(uint16,
  AUTOMATIC) rtu_Spd_Avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT)
  rty_Speed_ind, CONST(uint16, AUTOMATIC) rtd_DSpeed_Int_Ref_Other[21])
{
  /* local block i/o variables */
  uint16 rtb_LookupTableDynamic;

  /* Outputs for Atomic SubSystem: '<S15>/Subsystem' */
  Interpolation_Other_Region(rtu_Spd_Avg, &rtb_LookupTableDynamic,
    rtd_DSpeed_Int_Ref_Other);

  /* End of Outputs for SubSystem: '<S15>/Subsystem' */

  /* SignalConversion generated from: '<S15>/Speed_ind' */
  *rty_Speed_ind = rtb_LookupTableDynamic;
}

/*
 * Output and update for atomic system:
 *    '<S16>/Speed_target_km'
 *    '<S17>/Speed_target_Miles'
 */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_target(VAR(uint16, AUTOMATIC)
  rtu_Speed_int, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT) rty_speed_trg)
{
  uint32 tmp;
  uint16 y;

  /* Math: '<S21>/Mod' incorporates:
   *  Constant: '<S21>/Constant2'
   */
  if (((uint16)RESOLUTION_VAL_100) == 0U) {
    y = rtu_Speed_int;
  } else {
    y = (uint16)(rtu_Speed_int % ((uint16)RESOLUTION_VAL_100));
  }

  /* End of Math: '<S21>/Mod' */

  /* If: '<S21>/If' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Product: '<S21>/Divide'
   */
  if (y < 50U) {
    /* Product: '<S21>/Divide' incorporates:
     *  Constant: '<S21>/Constant3'
     */
    if (((uint16)RESOLUTION_VAL_100) == 0U) {
      y = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      y = (uint16)(((uint32)rtu_Speed_int) / ((uint32)((uint16)
        RESOLUTION_VAL_100)));
    }

    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Product: '<S24>/Multiply' incorporates:
     *  Constant: '<S24>/Constant2'
     *  Product: '<S21>/Divide'
     */
    tmp = ((uint32)y) * ((uint32)((uint16)RESOLUTION_VAL_100));
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    *rty_speed_trg = (uint16)tmp;

    /* End of Product: '<S24>/Multiply' */
    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */
  } else {
    if (((uint16)RESOLUTION_VAL_100) == 0U) {
      /* Product: '<S21>/Divide' */
      y = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      /* Product: '<S21>/Divide' incorporates:
       *  Constant: '<S21>/Constant3'
       */
      y = (uint16)(((uint32)rtu_Speed_int) / ((uint32)((uint16)
        RESOLUTION_VAL_100)));
    }

    /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Product: '<S25>/Multiply' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S25>/Constant2'
     *  Product: '<S21>/Divide'
     *  Sum: '<S25>/Add'
     */
    tmp = ((uint32)((uint16)(((uint32)y) + ((uint32)((uint8)VAL_ONE))))) *
      ((uint32)((uint16)RESOLUTION_VAL_100));
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    *rty_speed_trg = (uint16)tmp;

    /* End of Product: '<S25>/Multiply' */
    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem1' */
  }

  /* End of If: '<S21>/If' */
}

/*
 * System initialize for atomic system:
 *    '<S16>/Speed_trimming_KM'
 *    '<S17>/Speed_trimming_Miles'
 */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_trimming_Init(P2VAR(uint16,
  AUTOMATIC, Mdl_Speed_VAR_INIT) rty_Speed_trim)
{
  /* SystemInitialize for Merge: '<S22>/Merge' */
  *rty_Speed_trim = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S16>/Speed_trimming_KM'
 *    '<S17>/Speed_trimming_Miles'
 */
static FUNC(void, Mdl_Speed_CODE_LOCAL) Speed_trimming(VAR(uint16, AUTOMATIC)
  rtu_speed_avg, P2VAR(uint16, AUTOMATIC, Mdl_Speed_VAR_INIT) rty_Speed_trim)
{
  uint16 y;

  /* Math: '<S22>/Mod' incorporates:
   *  Constant: '<S22>/Constant'
   */
  if (((uint16)RESOLUTION_VAL_100) == 0U) {
    y = rtu_speed_avg;
  } else {
    y = (uint16)(rtu_speed_avg % ((uint16)RESOLUTION_VAL_100));
  }

  /* End of Math: '<S22>/Mod' */

  /* If: '<S22>/If' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Divide'
   */
  if (y < 50U) {
    /* Product: '<S22>/Divide' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    if (((uint16)RESOLUTION_VAL_100) == 0U) {
      y = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      y = (uint16)(((uint32)rtu_speed_avg) / ((uint32)((uint16)
        RESOLUTION_VAL_100)));
    }

    /* Outputs for IfAction SubSystem: '<S22>/Speed_trim_Less_than_0.5' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Product: '<S26>/Multiply' incorporates:
     *  Constant: '<S26>/Constant2'
     *  Product: '<S22>/Divide'
     */
    *rty_Speed_trim = (uint16)(y * ((uint16)RESOLUTION_VAL_100));

    /* End of Outputs for SubSystem: '<S22>/Speed_trim_Less_than_0.5' */
  } else {
    if (((uint16)RESOLUTION_VAL_100) == 0U) {
      /* Product: '<S22>/Divide' */
      y = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      /* Product: '<S22>/Divide' incorporates:
       *  Constant: '<S22>/Constant2'
       */
      y = (uint16)(((uint32)rtu_speed_avg) / ((uint32)((uint16)
        RESOLUTION_VAL_100)));
    }

    /* Outputs for IfAction SubSystem: '<S22>/Speed_trim_greater_than_equal_to_0.5' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Sum: '<S27>/Add' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant2'
     *  Product: '<S22>/Divide'
     *  Product: '<S27>/Multiply'
     */
    *rty_Speed_trim = (uint16)(((uint16)(y * ((uint16)RESOLUTION_VAL_100))) +
      ((uint16)RESOLUTION_VAL_50));

    /* End of Outputs for SubSystem: '<S22>/Speed_trim_greater_than_equal_to_0.5' */
  }

  /* End of If: '<S22>/If' */
}

/* Model step function for TID1 */
FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Task(void) /* Explicit Task: Mdl_Speed_Task */
{
  sint32 rtb_GetProcessedAdc_o1;
  uint32 tmp;
  sint16 rtb_Subtract_j;
  uint16 rtb_speed_int;
  uint16 rtb_speed_int_0;
  ClusterModes tmpRead;
  CountryCode_FuncType tmpRead_0;
  IgntionSubstateType rtb_TmpSignalConversionAtrpIgnS;
  uint8 rtb_GetProcessedAdc_o2;
  uint8 rtb_RxCan_GetSignalValue_o1;
  uint8 rtb_RxCan_GetSignalValue_o2;
  boolean rtb_RelationalOperator1_a;
  boolean rtb_RelationalOperator1_g;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Speed_Task_sys'
   */
  /* SignalConversion generated from: '<S2>/rpIgnSubstate_IgnitionSubstate' incorporates:
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&rtb_TmpSignalConversionAtrpIgnS);

  /* FunctionCaller: '<S42>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(((uint8)eVehicleSpeedABSIn),
    &rtb_RxCan_GetSignalValue_o1, &rtb_RxCan_GetSignalValue_o2);

  /* FunctionCaller: '<S42>/GetProcessedAdc' */
  (void)Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(((uint8)eIO_ADC_AI_TEMP_RTC),
    &rtb_GetProcessedAdc_o1, &rtb_GetProcessedAdc_o2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' */

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Speed_Task_sys'
   */
  /* If: '<S3>/If1' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S3>/Constant3'
   *  DataStoreWrite: '<S38>/Data Store Write1'
   *  Inport: '<Root>/rp_Countrycode_Func_CountryCode_Func'
   *  Outport: '<Root>/pp_SPD_Target2_Status_Spd_Target2_Status'
   *  Outport: '<Root>/pp_SPD_Target_Status_Spd_Target_Status'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  Switch: '<S16>/Switch'
   *  Switch: '<S17>/Switch'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S31>/Unit Delay1'
   */
  if (tmpRead == ((ClusterModes)((uint8)CLUSTER_ACTIVE))) {
    /* Outputs for IfAction SubSystem: '<S3>/Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* RelationalOperator: '<S23>/Relational Operator1' incorporates:
     *  Constant: '<S41>/Constant'
     *  RelationalOperator: '<S41>/Compare'
     */
    rtb_RelationalOperator1_g = (rtb_TmpSignalConversionAtrpIgnS ==
      ((IgntionSubstateType)((uint8)IgnOff)));

    /* Switch: '<S7>/Switch3' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S9>/Constant'
     *  Logic: '<S7>/Logical Operator2'
     *  Logic: '<S7>/OR'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S8>/Compare'
     *  RelationalOperator: '<S9>/Compare'
     */
    if ((rtb_TmpSignalConversionAtrpIgnS == ((IgntionSubstateType)((uint8)IgnOn)))
        && ((rtb_RxCan_GetSignalValue_o2 != ((uint8)eSIGNAL_MISSING)) &&
            (rtb_RxCan_GetSignalValue_o2 != ((uint8)eSIGNAL_NEVER_RECEIVED)))) {
      /* UnitDelay: '<S31>/Unit Delay1' */
      rtb_speed_int = (uint16)rtb_RxCan_GetSignalValue_o1;
    } else {
      /* UnitDelay: '<S31>/Unit Delay1' incorporates:
       *  Constant: '<S7>/Constant3'
       */
      rtb_speed_int = ((uint16)SPEED_ZERO);
    }

    /* End of Switch: '<S7>/Switch3' */

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    if (rtb_speed_int <= ((uint16)MIN_SPEED_VALUE)) {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rtb_speed_int = ((uint16)SPEED_ZERO);
    }

    /* End of Switch: '<S7>/Switch' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant1'
     *  DataStoreRead: '<S39>/Data Store Read1'
     *  DataStoreWrite: '<S39>/Data Store Write'
     *  Sum: '<S39>/Sum'
     */
    if (rtb_RelationalOperator1_g) {
      Mdl_Speed_ARID_DEF.l_Speedin_Collect = (uint32)((uint16)SPEED_ZERO);
    } else {
      Mdl_Speed_ARID_DEF.l_Speedin_Collect += (uint32)rtb_speed_int;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* UnitDelay: '<S39>/Unit Delay' */
    rtb_TmpSignalConversionAtrpIgnS =
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time;

    /* End of Outputs for SubSystem: '<S3>/Subsystem1' */
    /*  USA country Func */
    /*  CANADA Country Func */
    /*  Mexico with MCUID0809 =0 */
    /*  Mexico with MCUID0809 =1 */
    /*  UK country Func */
    /*  EUR country Func */
    /*  Korea with MCUID0810 =0 */
    /*  Korea with MCUID0810 =1 */
    /*  Australia */
    (void)Rte_Read_rp_Countrycode_Func_CountryCode_Func(&tmpRead_0);

    /* Outputs for IfAction SubSystem: '<S3>/Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Truth Table: '<S12>/Truth Table' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Inport: '<Root>/rp_Countrycode_Func_CountryCode_Func'
     */
    switch (tmpRead_0) {
     case ((uint8)C_USA):
      /*  USA */
      rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_USA);
      break;

     case ((uint8)C_CANADA):
      /*  CANADA */
      rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_CANADA);
      break;

     default:
      if ((tmpRead_0 == ((CountryCode_FuncType)((uint8)C_MEXICO))) && (((uint8)
            MCUID0809) == 0U)) {
        /*  MEXICO_FMVSS */
        rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_MEXICO_FMVSS);
      } else if ((tmpRead_0 == ((CountryCode_FuncType)((uint8)C_MEXICO))) &&
                 (((uint8)MCUID0809) == 1U)) {
        /*  MEXICO_UN_R */
        rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_MEXICO_UN_R);
      } else {
        switch (tmpRead_0) {
         case ((uint8)C_UK):
          /*  UK */
          rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_UK);
          break;

         case ((uint8)C_EUROPE):
          /*  EUR */
          rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_EUROPE);
          break;

         default:
          if ((tmpRead_0 == ((CountryCode_FuncType)((uint8)C_KOREA))) &&
              (((uint8)MCUID0810) == 0U)) {
            /*  Korea_FMVSS */
            rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_KOREA_FMVSS);
          } else if ((tmpRead_0 == ((CountryCode_FuncType)((uint8)C_KOREA))) &&
                     (((uint8)MCUID0810) == 1U)) {
            /*  Korea_UN-R */
            rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_KOREA_UN_R);
          } else if (tmpRead_0 == ((CountryCode_FuncType)((uint8)C_ADR))) {
            /*  ADR */
            rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_ADR);
          } else {
            /*  Default */
            /*  ECE */
            rtb_RxCan_GetSignalValue_o1 = ((uint8)eSP_ECE);
          }
          break;
        }
      }
      break;
    }

    /* End of Truth Table: '<S12>/Truth Table' */

    /* Truth Table: '<S13>/Speed_Update' incorporates:
     *  UnitDelay: '<S39>/Unit Delay'
     */
    /*  USA / CANADA / Mexico */
    /*  0degC <= MCU temp */
    /*  -15degC <= MCU temp < 0degC */
    /*  -25degC <= MCU temp < -15degC */
    /*  MCU temp < -25degC */
    if ((((((rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_CANADA)) ||
            (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_USA))) ||
           (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_MEXICO_FMVSS))) ||
          (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_MEXICO_UN_R))) ||
         (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_KOREA_FMVSS))) ||
        (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_KOREA_UN_R))) {
      /*  Speed_update_time 0.28 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_0_28S);
    } else if (rtb_GetProcessedAdc_o1 >= ((sint32)((uint16)
                 AI_TEMP_ADC_COUNT_1891))) {
      /*  Speed_update_time 0.28 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_0_28S);
    } else if (rtb_GetProcessedAdc_o1 >= ((sint32)((uint16)
                 AI_TEMP_ADC_COUNT_1792))) {
      /*  Speed_update_time 0.5 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_0_5S);
    } else if (rtb_GetProcessedAdc_o1 >= ((sint32)((uint16)
                 AI_TEMP_ADC_COUNT_1727))) {
      /*  Speed_update_time 1 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_1S);
    } else if (rtb_GetProcessedAdc_o1 >= ((sint32)((uint16)
                 AI_TEMP_ADC_COUNT_1586))) {
      /*  Speed_update_time 1.5 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_1_5S);
    } else {
      /*  Default */
      /*  Speed_update_time 0.28 S */
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time = ((uint8)SPEED_UPDATE_0_28S);
    }

    /* End of Truth Table: '<S13>/Speed_Update' */

    /* Sum: '<S39>/Add' incorporates:
     *  Constant: '<S39>/Constant'
     *  UnitDelay: '<S39>/Unit Delay1'
     */
    rtb_RxCan_GetSignalValue_o2 = (uint8)(((uint8)VAL_ONE) + ((uint8)
      Mdl_Speed_ARID_DEF.Speed_index_count));

    /* RelationalOperator: '<S31>/Relational Operator1' incorporates:
     *  RelationalOperator: '<S39>/Relational Operator'
     *  UnitDelay: '<S39>/Unit Delay'
     */
    rtb_RelationalOperator1_a = (rtb_RxCan_GetSignalValue_o2 >=
      Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time);

    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S39>/Constant2'
     *  Logic: '<S39>/OR'
     *  UnitDelay: '<S39>/Unit Delay1'
     */
    if (rtb_RelationalOperator1_a || rtb_RelationalOperator1_g) {
      Mdl_Speed_ARID_DEF.Speed_index_count = ((uint16)SPEED_ZERO);
    } else {
      Mdl_Speed_ARID_DEF.Speed_index_count = (uint16)rtb_RxCan_GetSignalValue_o2;
    }

    /* End of Switch: '<S39>/Switch' */

    /* Outputs for Enabled SubSystem: '<S13>/Average_samples_km' incorporates:
     *  EnablePort: '<S38>/Enable'
     */
    if (((uint8)VAL_ONE) == (rtb_RelationalOperator1_a ? ((uint8)1) : ((uint8)0)))
    {
      /* Switch: '<S38>/Switch' incorporates:
       *  Logic: '<S39>/AND'
       *  RelationalOperator: '<S39>/Equal'
       *  UnitDelay: '<S39>/Unit Delay'
       */
      if ((rtb_TmpSignalConversionAtrpIgnS <= ((IgntionSubstateType)
            Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time)) ||
          (!rtb_RelationalOperator1_a)) {
        rtb_RxCan_GetSignalValue_o2 =
          Mdl_Speed_ARID_DEF.l_Prev_Speed_Update_Time;
      }

      /* Product: '<S38>/Divide' incorporates:
       *  DataStoreRead: '<S39>/Data Store Read'
       *  Switch: '<S38>/Switch'
       */
      if (rtb_RxCan_GetSignalValue_o2 == 0U) {
        tmp = ((uint32)(0xFFFFFFFFU));

        /* Divide by zero handler */
      } else {
        tmp = Mdl_Speed_ARID_DEF.l_Speedin_Collect / ((uint32)
          rtb_RxCan_GetSignalValue_o2);
      }

      /* DataTypeConversion: '<S38>/Cast' incorporates:
       *  DataStoreWrite: '<S38>/Data Store Write'
       *  Product: '<S38>/Divide'
       */
      Mdl_Speed_ARID_DEF.Speedin_avg = (uint16)tmp;
      Mdl_Speed_ARID_DEF.l_Speedin_Collect = (uint32)((uint16)SPEED_ZERO);

      /* DataStoreRead: '<S38>/Data Store Read' incorporates:
       *  Constant: '<S38>/Constant'
       *  DataStoreWrite: '<S38>/Data Store Write1'
       */
      Mdl_Speed_ARID_DEF.DataStoreRead = Mdl_Speed_ARID_DEF.Speedin_avg;
    }

    /* End of Outputs for SubSystem: '<S13>/Average_samples_km' */

    /* If: '<S11>/If' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S11>/Constant5'
     *  Constant: '<S11>/Constant6'
     *  Constant: '<S13>/Constant6'
     *  Constant: '<S38>/Constant'
     *  DataStoreWrite: '<S38>/Data Store Write1'
     *  RelationalOperator: '<S13>/Relational Operator1'
     */
    if ((((rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_CANADA)) ||
          (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_USA))) ||
         (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_MEXICO_FMVSS))) ||
        (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_KOREA_FMVSS))) {
      /* Outputs for IfAction SubSystem: '<S11>/US_CAN_MAX' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S18>/Subsystem' */
      Interpolation_US_CANADA_MEXICO_Region();

      /* End of Outputs for SubSystem: '<S18>/Subsystem' */

      /* Merge: '<S11>/Merge2' incorporates:
       *  SignalConversion generated from: '<S18>/Speed_ind'
       */
      Mdl_Speed_ARID_DEF.Merge2_l = Mdl_Speed_ARID_DEF.LookupTableDynamic;

      /* End of Outputs for SubSystem: '<S11>/US_CAN_MAX' */
    } else if (((rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_UK)) ||
                (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_EUROPE))) ||
               (rtb_RxCan_GetSignalValue_o1 == ((uint8)eSP_MEXICO_UN_R))) {
      /* Outputs for IfAction SubSystem: '<S11>/EUROPE_UK' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      Mdl_Speed_EUROPE_UK(Mdl_Speed_ARID_DEF.DataStoreRead,
                          &Mdl_Speed_ARID_DEF.Merge2_l,
                          Mdl_Speed_ARID_DEF.DSpeed_Int_Ref_Other);

      /* End of Outputs for SubSystem: '<S11>/EUROPE_UK' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/ADR_ECE' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      Mdl_Speed_EUROPE_UK(Mdl_Speed_ARID_DEF.DataStoreRead,
                          &Mdl_Speed_ARID_DEF.Merge2_l,
                          Mdl_Speed_ARID_DEF.DSpeed_Int_Ref_Other);

      /* End of Outputs for SubSystem: '<S11>/ADR_ECE' */
    }

    /* End of If: '<S11>/If' */

    /* Switch: '<S16>/Switch' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read2'
     *  DataStoreRead: '<S16>/Data Store Read41'
     *  RelationalOperator: '<S16>/Less Than'
     */
    if (Mdl_Speed_ARID_DEF.Merge2_l <= Mdl_Speed_ARID_DEF.MCUID0262) {
      rtb_speed_int_0 = Mdl_Speed_ARID_DEF.Merge2_l;
    } else {
      rtb_speed_int_0 = Mdl_Speed_ARID_DEF.MCUID0262;
    }

    /* Outputs for Atomic SubSystem: '<S16>/Speed_trimming_KM' */
    Speed_trimming(rtb_speed_int_0, &Mdl_Speed_ARID_DEF.Merge_i);

    /* End of Outputs for SubSystem: '<S16>/Speed_trimming_KM' */

    /* Sum: '<S23>/Subtract' incorporates:
     *  Switch: '<S16>/Switch'
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    rtb_GetProcessedAdc_o1 = ((sint32)Mdl_Speed_ARID_DEF.Merge_i) - ((sint32)
      Mdl_Speed_ARID_DEF.Prev_speed_Int_km);

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/Constant1'
     *  Constant: '<S23>/Constant3'
     *  Logic: '<S23>/Logical Operator'
     *  RelationalOperator: '<S23>/Relational Operator'
     *  RelationalOperator: '<S23>/Relational Operator1'
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    if ((rtb_GetProcessedAdc_o1 <= ((sint32)((sint8)RESOLUTION_VAL_MINUS_100))) ||
        (rtb_GetProcessedAdc_o1 >= ((sint32)((uint16)RESOLUTION_VAL_100)))) {
      Mdl_Speed_ARID_DEF.Prev_speed_Int_km = Mdl_Speed_ARID_DEF.Merge_i;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Outputs for Atomic SubSystem: '<S16>/Speed_target_km' */
    Speed_target(Mdl_Speed_ARID_DEF.Prev_speed_Int_km,
                 &Mdl_Speed_ARID_DEF.pp_SPD_Target_Status_Spd_Target);

    /* End of Outputs for SubSystem: '<S16>/Speed_target_km' */

    /* Product: '<S30>/Divide3' incorporates:
     *  Constant: '<S30>/Constant3'
     *  Constant: '<S30>/Constant4'
     *  Outport: '<Root>/pp_SPD_Target_Status_Spd_Target_Status'
     *  Product: '<S30>/Divide2'
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    if (((uint16)RESOLUTION_VAL_103) == 0U) {
      rtb_speed_int_0 = ((uint16)(65535U));

      /* Divide by zero handler */
    } else {
      rtb_speed_int_0 = (uint16)((((uint32)Mdl_Speed_ARID_DEF.Merge2_l) *
        ((uint32)((uint16)RESOLUTION_VAL_64))) / ((uint32)((uint16)
        RESOLUTION_VAL_103)));
    }

    /* Switch: '<S17>/Switch' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read2'
     *  DataStoreRead: '<S17>/Data Store Read41'
     *  Product: '<S30>/Divide3'
     *  RelationalOperator: '<S17>/Less Than'
     */
    if (rtb_speed_int_0 > Mdl_Speed_ARID_DEF.MCUID0263) {
      rtb_speed_int_0 = Mdl_Speed_ARID_DEF.MCUID0263;
    }

    /* Outputs for Atomic SubSystem: '<S17>/Speed_trimming_Miles' */
    Speed_trimming(rtb_speed_int_0, &Mdl_Speed_ARID_DEF.Merge);

    /* End of Outputs for SubSystem: '<S17>/Speed_trimming_Miles' */

    /* Sum: '<S31>/Subtract' incorporates:
     *  Switch: '<S17>/Switch'
     *  UnitDelay: '<S31>/Unit Delay1'
     */
    rtb_Subtract_j = (sint16)(((sint16)Mdl_Speed_ARID_DEF.Merge) - ((sint16)
      Mdl_Speed_ARID_DEF.Prev_speed_Int));

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant2'
     *  Logic: '<S31>/Logical Operator'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  RelationalOperator: '<S31>/Relational Operator1'
     *  UnitDelay: '<S31>/Unit Delay1'
     */
    if ((rtb_Subtract_j <= ((sint16)((sint8)RESOLUTION_VAL_MINUS_100))) ||
        (((sint32)rtb_Subtract_j) >= ((sint32)((uint16)RESOLUTION_VAL_100)))) {
      Mdl_Speed_ARID_DEF.Prev_speed_Int = Mdl_Speed_ARID_DEF.Merge;
    }

    /* End of Switch: '<S31>/Switch' */

    /* Outputs for Atomic SubSystem: '<S17>/Speed_target_Miles' */
    Speed_target(Mdl_Speed_ARID_DEF.Prev_speed_Int,
                 &Mdl_Speed_ARID_DEF.pp_SPD_Target2_Status_Spd_Targe);

    /* End of Outputs for SubSystem: '<S17>/Speed_target_Miles' */

    /* Outport: '<Root>/pp_SPD_Selection_Table_Speed_Selection_Table' incorporates:
     *  Outport: '<Root>/pp_SPD_Target2_Status_Spd_Target2_Status'
     *  SignalConversion generated from: '<S7>/Spd_Table_selection'
     *  UnitDelay: '<S31>/Unit Delay1'
     */
    (void)Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table
      (rtb_RxCan_GetSignalValue_o1);

    /* Outport: '<Root>/pp_SPD_SP1_In_Status_SP1_In_Status' incorporates:
     *  SignalConversion generated from: '<S7>/Speed_In'
     */
    (void)Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(rtb_speed_int);

    /* Outport: '<Root>/pp_SPD_Trim_Status_Spd_Trim_Status' incorporates:
     *  SignalConversion generated from: '<S7>/speed_trim'
     */
    (void)Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status
      (Mdl_Speed_ARID_DEF.Merge_i);

    /* Outport: '<Root>/pp_SPD_Trim2_Status_Spd_Trim2_Status' incorporates:
     *  SignalConversion generated from: '<S7>/speed_trim2'
     */
    (void)Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status
      (Mdl_Speed_ARID_DEF.Merge);

    /* End of Outputs for SubSystem: '<S3>/Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Outport: '<Root>/pp_SPD_SP1_In_Status_SP1_In_Status' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/Speed_In'
     */
    (void)Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(((uint16)SPEED_ZERO));

    /* Outport: '<Root>/pp_SPD_Target_Status_Spd_Target_Status' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/speed_trg'
     */
    Mdl_Speed_ARID_DEF.pp_SPD_Target_Status_Spd_Target = ((uint16)SPEED_ZERO);

    /* Outport: '<Root>/pp_SPD_Target2_Status_Spd_Target2_Status' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/speed_trg2'
     */
    Mdl_Speed_ARID_DEF.pp_SPD_Target2_Status_Spd_Targe = ((uint16)SPEED_ZERO);

    /* Outport: '<Root>/pp_SPD_Trim_Status_Spd_Trim_Status' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/speed_trim'
     */
    (void)Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status(((uint16)SPEED_ZERO));

    /* Outport: '<Root>/pp_SPD_Trim2_Status_Spd_Trim2_Status' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/speed_trim2'
     */
    (void)Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status(((uint16)SPEED_ZERO));

    /* Outport: '<Root>/pp_SPD_Selection_Table_Speed_Selection_Table' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    (void)Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table(((uint8)
      VAL_ZERO));

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' */
  (void)Rte_Write_pp_SPD_Target_Status_Spd_Target_Status
    (Mdl_Speed_ARID_DEF.pp_SPD_Target_Status_Spd_Target);
  (void)Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status
    (Mdl_Speed_ARID_DEF.pp_SPD_Target2_Status_Spd_Targe);
}

/* Output function */
FUNC(void, Mdl_Speed_CODE) mdl_speed_init_1(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, Mdl_Speed_CODE) Mdl_Speed_Init(void)
{
  {
    sint32 i;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    Mdl_Speed_ARID_DEF.MCUID0809_l = ((uint8)VAL_ZERO);

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    Mdl_Speed_ARID_DEF.MCUID0810_l = ((uint8)VAL_ONE);

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    Mdl_Speed_ARID_DEF.l_digital_speed_Init_MCU = ((uint8)VAL_ZERO);
    for (i = 0; i < 21; i++) {
      /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
      Mdl_Speed_ARID_DEF.DSpeed_Int_Ref_US_CAN_MAX[i] = Initial_data[(i)];

      /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
      Mdl_Speed_ARID_DEF.DSpeed_Int_Ref_Other[i] = Initial_data[(i)];
    }

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    Mdl_Speed_ARID_DEF.MCUID0262 = ((uint16)CNVM_MCUID0262_DEFAULT_VAL);

    /* Start for DataStoreMemory: '<Root>/Data Store Memory44' */
    Mdl_Speed_ARID_DEF.MCUID0263 = ((uint16)CNVM_MCUID0263_DEFAULT_VAL);

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' incorporates:
     *  SubSystem: '<Root>/Mdl_Speed_Task_sys'
     */
    /* SystemInitialize for IfAction SubSystem: '<S3>/Subsystem1' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/Speed_trimming_KM' */
    Speed_trimming_Init(&Mdl_Speed_ARID_DEF.Merge_i);

    /* End of SystemInitialize for SubSystem: '<S16>/Speed_trimming_KM' */

    /* SystemInitialize for Atomic SubSystem: '<S17>/Speed_trimming_Miles' */
    Speed_trimming_Init(&Mdl_Speed_ARID_DEF.Merge);

    /* End of SystemInitialize for SubSystem: '<S17>/Speed_trimming_Miles' */
    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem1' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Speed_Task' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
