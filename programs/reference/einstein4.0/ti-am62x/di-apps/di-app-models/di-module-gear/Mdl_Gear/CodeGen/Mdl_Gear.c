/*
 * File: Mdl_Gear.c
 *
 * Code generated for Simulink model 'Mdl_Gear'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Aug 21 15:02:45 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_Gear.h"
#include "Rte_Type.h"
#include "Platform_Types.h"
#include "Mdl_Gear_config.cfg"

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

#ifndef NETWORK_NORMAL
#error The value of parameter "NETWORK_NORMAL" is not defined
#endif

#ifndef NETWORK_STANDALONE
#error The value of parameter "NETWORK_STANDALONE" is not defined
#endif

#ifndef Shift_PosInd_B
#error The value of parameter "Shift_PosInd_B" is not defined
#endif

#ifndef Shift_PosInd_D
#error The value of parameter "Shift_PosInd_D" is not defined
#endif

#ifndef Shift_PosInd_Ind_D
#error The value of parameter "Shift_PosInd_Ind_D" is not defined
#endif

#ifndef Shift_PosInd_Ind_M
#error The value of parameter "Shift_PosInd_Ind_M" is not defined
#endif

#ifndef Shift_PosInd_Ind_S
#error The value of parameter "Shift_PosInd_Ind_S" is not defined
#endif

#ifndef Shift_PosInd_N
#error The value of parameter "Shift_PosInd_N" is not defined
#endif

#ifndef Shift_PosInd_P
#error The value of parameter "Shift_PosInd_P" is not defined
#endif

#ifndef Shift_PosInd_R
#error The value of parameter "Shift_PosInd_R" is not defined
#endif

#ifndef Shift_PosInd_SD
#error The value of parameter "Shift_PosInd_SD" is not defined
#endif

#ifndef eGearIn
#error The value of parameter "eGearIn" is not defined
#endif

#ifndef eGearModeIn
#error The value of parameter "eGearModeIn" is not defined
#endif

#ifndef eGearRecommendationIn
#error The value of parameter "eGearRecommendationIn" is not defined
#endif

#ifndef eGearStatusIn
#error The value of parameter "eGearStatusIn" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_Mdl_Gear_T, Mdl_Gear_VAR_INIT) Mdl_Gear_ARID_DEF;

/* '<S10>/ShiftPosIndStatusData_creator2' */

/* Model step function for TID1 */
FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Task(void) /* Explicit Task: Mdl_Gear_Task */
{
  uint16 rtb_Shift_Ind_Pos = 0U;
  ClusterModes tmpRead = 0U;
  HMIReadySts_Type tmpRead_0 = 0U;
  IgntionSubstateType rtb_TmpSignalConversionAtrpIgnS = 0U;
  VehicleActiveModes rtb_TmpSignalConversionAtrpVehi = 0U;
  uint8 rtb_RxCan_GetSignalValue1_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue1_o2 = 0U;
  uint8 rtb_RxCan_GetSignalValue2_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue2_o2 = 0U;
  uint8 rtb_RxCan_GetSignalValue3_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue3_o2 = 0U;
  uint8 rtb_RxCan_GetSignalValue_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue_o2 = 0U;

  /* Inport: '<Root>/rp_HMI_Ready_Status_HMI_ReadyStatus' */
  (void)Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Gear_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Gear_Task_sys'
   */
  /* FunctionCaller: '<S5>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eGearIn),
    &rtb_RxCan_GetSignalValue_o1, &rtb_RxCan_GetSignalValue_o2);

  /* FunctionCaller: '<S5>/RxCan_GetSignalValue1' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eGearModeIn),
    &rtb_RxCan_GetSignalValue1_o1, &rtb_RxCan_GetSignalValue1_o2);

  /* FunctionCaller: '<S5>/RxCan_GetSignalValue2' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)
    eGearRecommendationIn), &rtb_RxCan_GetSignalValue2_o1,
    &rtb_RxCan_GetSignalValue2_o2);

  /* FunctionCaller: '<S5>/RxCan_GetSignalValue3' */
  (void)Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(((uint8)eGearStatusIn),
    &rtb_RxCan_GetSignalValue3_o1, &rtb_RxCan_GetSignalValue3_o2);

  /* SignalConversion generated from: '<S1>/rpIgnSubstate_IgnitionSubstate' incorporates:
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&rtb_TmpSignalConversionAtrpIgnS);

  /* SignalConversion generated from: '<S1>/rpVehicleAppMode_WSSCurrentVehicleState' incorporates:
   *  Inport: '<Root>/rpVehicleAppMode_WSSCurrentVehicleState'
   */
  (void)Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState
    (&rtb_TmpSignalConversionAtrpVehi);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S4>/AND'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  if ((rtb_RxCan_GetSignalValue1_o2 == ((uint8)eSIGNAL_MISSING)) ||
      (rtb_RxCan_GetSignalValue1_o2 == ((uint8)eSIGNAL_NEVER_RECEIVED))) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_RxCan_GetSignalValue1_o1 = ((uint8)TYPE2_MECH);
  }

  /* End of Switch: '<S4>/Switch' */

  /* If: '<S4>/If' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (tmpRead_0 == ((HMIReadySts_Type)((uint8)HMI_READY))) {
    (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead);

    /* Outputs for IfAction SubSystem: '<S4>/Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Product: '<S11>/Divide' incorporates:
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode'
     */
    if (Mdl_Gear_cTaskPeriod == 0U) {
      rtb_RxCan_GetSignalValue1_o2 = ((uint8)(255U));

      /* Divide by zero handler */
    } else {
      rtb_RxCan_GetSignalValue1_o2 = (uint8)(((uint32)((uint16)Timer_Param)) /
        ((uint32)Mdl_Gear_cTaskPeriod));
    }

    /* If: '<S11>/If' incorporates:
     *  Constant: '<S18>/Constant'
     *  Product: '<S11>/Divide'
     *  RelationalOperator: '<S11>/GreaterThan'
     *  RelationalOperator: '<S18>/Compare'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    if ((rtb_TmpSignalConversionAtrpIgnS != ((IgntionSubstateType)((uint8)IgnOff)))
        && (Mdl_Gear_ARID_DEF.per_check_delay < ((uint16)
          rtb_RxCan_GetSignalValue1_o2))) {
      /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S19>/Constant'
       *  UnitDelay: '<S11>/Unit Delay'
       */
      Mdl_Gear_ARID_DEF.Add = (uint16)(((uint32)((uint8)STATUS_ON)) + ((uint32)
        Mdl_Gear_ARID_DEF.l_300ms_count));

      /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */
    }

    /* End of If: '<S11>/If' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant6'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    if (rtb_TmpSignalConversionAtrpIgnS != 0U) {
      Mdl_Gear_ARID_DEF.per_check_delay = Mdl_Gear_ARID_DEF.Add;
    } else {
      Mdl_Gear_ARID_DEF.per_check_delay = (uint16)((uint8)STATUS_OFF);
    }

    /* End of Switch: '<S11>/Switch' */

    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S17>/Constant'
     *  Logic: '<S11>/OR'
     *  RelationalOperator: '<S16>/Compare'
     *  RelationalOperator: '<S17>/Compare'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    if ((rtb_TmpSignalConversionAtrpIgnS == ((IgntionSubstateType)((uint8)IgnOff)))
        || (tmpRead == ((ClusterModes)((uint8)CLUSTER_INACTIVE)))) {
      Mdl_Gear_ARID_DEF.l_300ms_count = 0U;
    } else {
      Mdl_Gear_ARID_DEF.l_300ms_count = (uint8)Mdl_Gear_ARID_DEF.per_check_delay;
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S13>/Constant'
     *  Logic: '<S10>/AND'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S13>/Compare'
     */
    if ((rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_MISSING)) ||
        (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_NEVER_RECEIVED))) {
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      rtb_RxCan_GetSignalValue_o1 = ((uint8)GEAR_STATUS_OFF);
    }

    /* End of Switch: '<S10>/Switch' */

    /* If: '<S10>/If' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  Product: '<S11>/Divide'
     *  RelationalOperator: '<S11>/Relational Operator1'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    if (((rtb_TmpSignalConversionAtrpVehi == ((VehicleActiveModes)((uint8)
            NETWORK_NORMAL))) && (rtb_TmpSignalConversionAtrpIgnS !=
          ((IgntionSubstateType)((uint8)IgnOn)))) ||
        (Mdl_Gear_ARID_DEF.l_300ms_count != rtb_RxCan_GetSignalValue1_o2)) {
      /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Merge: '<S10>/Merge' incorporates:
       *  Constant: '<S14>/Constant'
       *  DataTypeConversion: '<S14>/Data Type Conversion'
       */
      rtb_Shift_Ind_Pos = (uint16)((uint8)GEAR_STATUS_OFF);

      /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' incorporates:
       *  Constant: '<S14>/Constant1'
       *  Constant: '<S14>/Constant2'
       *  Constant: '<S14>/Constant3'
       *  Constant: '<S14>/Constant4'
       *  Constant: '<S14>/Constant5'
       *  SignalConversion generated from: '<S10>/Signal Conversion'
       *  SignalConversion generated from: '<S14>/Screen_ShiftType'
       *  SignalConversion generated from: '<S14>/Shift_Blink_Pattern'
       *  SignalConversion generated from: '<S14>/Shift_Blink_Pattern3'
       *  SignalConversion generated from: '<S14>/Shift_Down_Ind'
       *  SignalConversion generated from: '<S14>/Shift_Up_Ind'
       */
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_BlinkReq
        = ((uint8)IND_TURN_OFF);
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Up =
        ((uint8)GEAR_STATUS_OFF);
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Down =
        ((uint8)GEAR_STATUS_OFF);
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_DisplayDecState
        = ((uint8)GEAR_STATUS_OFF);
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Screen_ShiftType
        = ((uint8)GEAR_STATUS_OFF);

      /* Outport: '<Root>/pp_ShiftPositionDisplay_ShiftPositionDisplay' incorporates:
       *  Constant: '<S14>/Constant6'
       *  SignalConversion generated from: '<S14>/ShiftDisplayStatus'
       */
      (void)Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(((uint8)
        GEAR_STATUS_OFF));

      /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S10>/Subsystem' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Truth Table: '<S15>/Shift Position Determination' incorporates:
       *  UnitDelay: '<S15>/Unit Delay'
       */
      /*  Check Shift type 1 or 2 */
      /*  Appmode is Standalone or Shift position CAN status is never recived */
      /*  Shift position CAN status is Missing */
      /*  Shift position CAN value is 1 */
      /*  Shift position CAN value is 2 */
      /*  Shift position CAN value is 3 */
      /*  Shift position CAN value is 4 */
      /*  Shift position CAN value is 5 */
      /*  Shift position CAN value is 6 */
      /*  Shift position CAN value is 7 */
      /*  Shift position CAN value is 8 */
      if ((rtb_TmpSignalConversionAtrpVehi != ((VehicleActiveModes)((uint8)
             NETWORK_STANDALONE))) && (rtb_RxCan_GetSignalValue_o2 != ((uint8)
            eSIGNAL_NEVER_RECEIVED))) {
        if (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_MISSING)) {
          /*  Shift position Off */
          Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)STATUS_OFF);
        } else {
          switch (rtb_RxCan_GetSignalValue_o1) {
           case ((uint8)VALUE_ONE):
            /*  Shift position P */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_P);
            break;

           case ((uint8)VALUE_TWO):
            /*  Shift position R */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_R);
            break;

           case ((uint8)VALUE_THREE):
            /*  Shift position N */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_N);
            break;

           case ((uint8)VALUE_FOUR):
            /*  Shift position D */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_D);
            break;

           case ((uint8)VALUE_FIVE):
            /*  Shift position B */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_B);
            break;

           case ((uint8)VALUE_SIX):
            /*  Shift position M */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_M);
            break;

           case ((uint8)VALUE_SEVEN):
            /*  Shift position S */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_S);
            break;

           case ((uint8)VALUE_EIGHT):
            /*  Shift position SD */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)Shift_Pos_RANGE_SD);
            break;

           default:
            /*  Default */
            /*  Shift position Off */
            Mdl_Gear_ARID_DEF.Prev_Shift_Position = ((uint8)STATUS_OFF);
            break;
          }
        }
      } else {
        /*  Maintain Previous Shift position value */
      }

      /* End of Truth Table: '<S15>/Shift Position Determination' */

      /* Truth Table: '<S20>/Gear Step CAN signal Determination' */
      /*  Check Shift type 1 */
      /*  Check Shift type 2 */
      if (rtb_RxCan_GetSignalValue1_o1 == ((uint8)TYPE1_SBW)) {
        /*  Type 1 : SBW */
        rtb_TmpSignalConversionAtrpIgnS = rtb_RxCan_GetSignalValue_o1;
      } else if (((rtb_RxCan_GetSignalValue1_o1 == ((uint8)TYPE2_MECH)) &&
                  (rtb_RxCan_GetSignalValue_o1 >= ((uint8)VALUE_ONE))) &&
                 (rtb_RxCan_GetSignalValue_o1 <= ((uint8)VALUE_TEN))) {
        /*  Type 2 : Mechanical shift */
        rtb_TmpSignalConversionAtrpIgnS = rtb_RxCan_GetSignalValue_o1;
      } else {
        /*  Default */
        /*  Others */
        rtb_TmpSignalConversionAtrpIgnS = ((uint8)VALUE_ZERO);
        rtb_RxCan_GetSignalValue_o2 = ((uint8)eSIGNAL_MISSING);
      }

      /* End of Truth Table: '<S20>/Gear Step CAN signal Determination' */

      /* Truth Table: '<S15>/Gear Step Determination' incorporates:
       *  UnitDelay: '<S15>/Unit Delay1'
       */
      /*  Appmode is Standalone or Gear step CAN status is never recived */
      /*  Gear step CAN status is Missing */
      /*  Normal Gear Step CAN value is 0 to 15 */
      if ((rtb_TmpSignalConversionAtrpVehi != ((VehicleActiveModes)((uint8)
             NETWORK_STANDALONE))) && (rtb_RxCan_GetSignalValue_o2 != ((uint8)
            eSIGNAL_NEVER_RECEIVED))) {
        if (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_MISSING)) {
          /*  Gear step is Off */
          Mdl_Gear_ARID_DEF.Prev_Gear_Step = ((uint8)STATUS_OFF);
        } else if ((rtb_TmpSignalConversionAtrpIgnS >= ((IgntionSubstateType)
                     ((uint8)VALUE_ONE))) && (rtb_TmpSignalConversionAtrpIgnS <=
                    ((IgntionSubstateType)((uint8)VALUE_FIFTEEN)))) {
          /*  Gear step is Current Gear Step CAN value */
          Mdl_Gear_ARID_DEF.Prev_Gear_Step = rtb_TmpSignalConversionAtrpIgnS;
        } else {
          /*  Default */
          /*  Gear step is Off */
          Mdl_Gear_ARID_DEF.Prev_Gear_Step = ((uint8)STATUS_OFF);
        }
      } else {
        /*  Maintains Previous Gear step */
      }

      /* End of Truth Table: '<S15>/Gear Step Determination' */

      /* Truth Table: '<S15>/Determination of Shift Position and Shift Mode and Gear Step' incorporates:
       *  UnitDelay: '<S15>/Unit Delay'
       *  UnitDelay: '<S15>/Unit Delay1'
       */
      /*  Shift Position Determination Range P,R,N,B,SD and Gear Step >0 */
      /*  Shift Position Determination Range P and Gear Step ==0 */
      /*  Shift Position Determination Range R and Gear Step ==0 */
      /*  Shift Position Determination Range N and Gear Step ==0 */
      /*  Shift Position Determination Range D and Gear Step ==0 */
      /*  Shift Position Determination Range B and Gear Step ==0 */
      /*  Shift Position Determination Range SD and Gear Step ==0 */
      /*  Shift Position Determination M and Gear Step 0 */
      /*  Shift Position Determination M and Gear Step >0 */
      /*  Shift Position Determination S and Gear Step =0 */
      /*  Shift Position Determination S and Gear Step >0 */
      /*  Shift Position Determination D and Gear Step 0 */
      /*  Shift Position Determination D and Gear Step >0 */
      if ((((((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                Shift_Pos_RANGE_P)) || (Mdl_Gear_ARID_DEF.Prev_Shift_Position ==
               ((uint8)Shift_Pos_RANGE_N))) ||
             (Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)Shift_Pos_RANGE_R)))
            || (Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
              Shift_Pos_RANGE_B))) || (Mdl_Gear_ARID_DEF.Prev_Shift_Position ==
            ((uint8)Shift_Pos_RANGE_SD))) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step ==
           ((uint8)GEAR_STATUS_OFF))) {
        /*  Shift Position Determination OFF */
        rtb_RxCan_GetSignalValue_o2 = ((uint8)GEAR_STATUS_OFF);
        rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
      } else {
        switch (Mdl_Gear_ARID_DEF.Prev_Shift_Position) {
         case ((uint8)Shift_Pos_RANGE_P):
          /*  Shift Position Determination Range P and Gear Step  0 */
          rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_P);
          rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          break;

         case ((uint8)Shift_Pos_RANGE_R):
          /*  Shift Position Determination Range R and Gear Step  0 */
          rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_R);
          rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          break;

         case ((uint8)Shift_Pos_RANGE_N):
          /*  Shift Position Determination Range N and Gear Step  0 */
          rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_N);
          rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          break;

         case ((uint8)Shift_Pos_RANGE_B):
          /*  Shift Position Determination Range B and Gear Step  0 */
          rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_B);
          rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          break;

         case ((uint8)Shift_Pos_RANGE_SD):
          /*  Shift Position Determination Range SD and Gear Step  0 */
          rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_SD);
          rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          break;

         default:
          if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                Shift_Pos_RANGE_M)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step ==
               ((uint8)GEAR_STATUS_OFF))) {
            /*  Shift Position Determination Range M and Gear Step 0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_M);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          } else if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                       Shift_Pos_RANGE_M)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step >
                      ((uint8)GEAR_STATUS_OFF))) {
            /*  Shift Position Determination Range M and Gear Step >0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_M);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_ON);
          } else if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                       Shift_Pos_RANGE_S)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step ==
                      ((uint8)GEAR_STATUS_OFF))) {
            /*  Shift Position Determination Range S and Gear Step 0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_S);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          } else if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                       Shift_Pos_RANGE_S)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step >
                      ((uint8)GEAR_STATUS_OFF))) {
            /*  Shift Position Determination Range S and Gear Step >0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_S);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_ON);
          } else if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                       Shift_Pos_RANGE_D)) &&
                     ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                        Shift_Pos_RANGE_D)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step
            == ((uint8)GEAR_STATUS_OFF)))) {
            /*  Shift Position Determination Range D and Gear Step  0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_D);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          } else if ((Mdl_Gear_ARID_DEF.Prev_Shift_Position == ((uint8)
                       Shift_Pos_RANGE_D)) && (Mdl_Gear_ARID_DEF.Prev_Gear_Step >
                      ((uint8)GEAR_STATUS_OFF))) {
            /*  Shift Position Determination Range D and Gear Step  > 0 */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)Shift_PosInd_D);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_ON);
          } else {
            /*  Default */
            /*  Shift Position Determination OFF */
            rtb_RxCan_GetSignalValue_o2 = ((uint8)GEAR_STATUS_OFF);
            rtb_TmpSignalConversionAtrpIgnS = ((uint8)GEAR_STATUS_OFF);
          }
          break;
        }
      }

      /* End of Truth Table: '<S15>/Determination of Shift Position and Shift Mode and Gear Step' */

      /* Switch: '<S15>/Shift_Ind_Position' */
      if (rtb_TmpSignalConversionAtrpIgnS != 0U) {
        /* Switch: '<S15>/Shift_Ind_Position' incorporates:
         *  Sum: '<S15>/Add'
         *  UnitDelay: '<S15>/Unit Delay1'
         */
        rtb_Shift_Ind_Pos = (uint16)((uint8)(rtb_RxCan_GetSignalValue_o2 +
          Mdl_Gear_ARID_DEF.Prev_Gear_Step));
      } else {
        /* Switch: '<S15>/Shift_Ind_Position' */
        rtb_Shift_Ind_Pos = (uint16)rtb_RxCan_GetSignalValue_o2;
      }

      /* End of Switch: '<S15>/Shift_Ind_Position' */

      /* Truth Table: '<S15>/Determination of Shift Down' incorporates:
       *  Truth Table: '<S15>/Determination of Shift Up'
       *  UnitDelay: '<S15>/Unit Delay3'
       *  UnitDelay: '<S15>/Unit Delay4'
       */
      /*  Appmode is Standalone or  CAN status is never recived */
      /*  CAN status is Missing */
      /*  Shift down CAN value is 1 */
      if ((rtb_TmpSignalConversionAtrpVehi != ((VehicleActiveModes)((uint8)
             NETWORK_STANDALONE))) && (rtb_RxCan_GetSignalValue2_o2 != ((uint8)
            eSIGNAL_NEVER_RECEIVED))) {
        if (rtb_RxCan_GetSignalValue2_o2 == ((uint8)eSIGNAL_MISSING)) {
          /*  Shift down status is Off */
          Mdl_Gear_ARID_DEF.Prev_Shift_Down_Ind = ((uint8)STATUS_OFF);

          /*  Shift up is Off */
          Mdl_Gear_ARID_DEF.Prev_Shift_Up_Ind = ((uint8)STATUS_OFF);
        } else {
          if (rtb_RxCan_GetSignalValue2_o1 == ((uint8)VALUE_TWO)) {
            /*  Shift down status is On */
            Mdl_Gear_ARID_DEF.Prev_Shift_Down_Ind = ((uint8)STATUS_ON);
          } else {
            /*  Default */
            /*  Shift down status is Off */
            Mdl_Gear_ARID_DEF.Prev_Shift_Down_Ind = ((uint8)STATUS_OFF);
          }

          if (rtb_RxCan_GetSignalValue2_o1 == ((uint8)VALUE_ONE)) {
            /*  Shift up is On */
            Mdl_Gear_ARID_DEF.Prev_Shift_Up_Ind = ((uint8)STATUS_ON);
          } else {
            /*  Default */
            /*  Shift up is Off */
            Mdl_Gear_ARID_DEF.Prev_Shift_Up_Ind = ((uint8)STATUS_OFF);
          }
        }
      } else {
        /*  Previous Shift down status */
        /*  Previous Step Up */
      }

      /* End of Truth Table: '<S15>/Determination of Shift Down' */

      /* Truth Table: '<S15>/Display Blink Effect Determination' incorporates:
       *  UnitDelay: '<S15>/Unit Delay2'
       */
      /*  Appmode is Standalone or  CAN status is never recived */
      /*  CAN status is Missing */
      /*  Shift Up CAN value is 1 */
      /*  Appmode is Standalone or  CAN status is never recived */
      /*  Blink_Pattern Off */
      /*  Blink Pattern 1 */
      /*  Blink Pattern 2 */
      if ((rtb_TmpSignalConversionAtrpVehi != ((VehicleActiveModes)((uint8)
             NETWORK_STANDALONE))) && (rtb_RxCan_GetSignalValue3_o2 != ((uint8)
            eSIGNAL_NEVER_RECEIVED))) {
        if (rtb_RxCan_GetSignalValue3_o2 == ((uint8)eSIGNAL_MISSING)) {
          /*  Shift Blink OFF */
          Mdl_Gear_ARID_DEF.Prev_Shift_Blink_pattern = ((uint8)IND_TURN_OFF);
        } else {
          switch (rtb_RxCan_GetSignalValue3_o1) {
           case ((uint8)Shift_Blink_P1):
            /*  Shift Blink Pattern 1 as 1 Hz */
            Mdl_Gear_ARID_DEF.Prev_Shift_Blink_pattern = ((uint8)IND_FLASH_1HZ);
            break;

           case ((uint8)Shift_Blink_P2):
            /*  Shift Blink Pattern 2 as 4 hz */
            Mdl_Gear_ARID_DEF.Prev_Shift_Blink_pattern = ((uint8)IND_FLASH_4HZ);
            break;

           default:
            /*  Default */
            /*  Shift Blink OFF */
            Mdl_Gear_ARID_DEF.Prev_Shift_Blink_pattern = ((uint8)IND_TURN_OFF);
            break;
          }
        }
      } else {
        /*  No change */
      }

      /* End of Truth Table: '<S15>/Display Blink Effect Determination' */

      /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' incorporates:
       *  Constant: '<S15>/Constant2'
       *  SignalConversion generated from: '<S10>/Signal Conversion'
       *  SignalConversion generated from: '<S15>/DisplayDecState'
       */
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_DisplayDecState
        = ((uint8)VALUE_ONE);

      /* Truth Table: '<S15>/Output of GUI_SHIFT_TYPE' incorporates:
       *  Constant: '<S15>/Constant2'
       *  UnitDelay: '<S15>/Unit Delay3'
       *  UnitDelay: '<S15>/Unit Delay4'
       */
      /*  Display Deceleration status is Off and Shift up or Down is On */
      /*  Display Deceleration status is 1 to 5 */
      if ((((uint8)VALUE_ONE) == ((uint8)STATUS_OFF)) &&
          ((Mdl_Gear_ARID_DEF.Prev_Shift_Up_Ind == ((uint8)STATUS_ON)) ||
           (Mdl_Gear_ARID_DEF.Prev_Shift_Down_Ind == ((uint8)STATUS_ON)))) {
        /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' */
        /*  Screen Shift type is TYPE2 */
        Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Screen_ShiftType
          = ((uint8)TYPE2);
      } else if (((uint8)VALUE_ONE) <= ((uint8)VALUE_FIVE)) {
        /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' */
        /*  Screen Shift type is TYPE3 */
        Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Screen_ShiftType
          = ((uint8)TYPE3);
      } else {
        /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' */
        /*  Default */
        /*  Screen Shift type is TYPE1 */
        Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Screen_ShiftType
          = ((uint8)TYPE1);
      }

      /* End of Truth Table: '<S15>/Output of GUI_SHIFT_TYPE' */

      /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' incorporates:
       *  SignalConversion generated from: '<S10>/Signal Conversion'
       *  SignalConversion generated from: '<S15>/Shift_Blink_Pattern'
       *  SignalConversion generated from: '<S15>/Shift_Down_Ind'
       *  SignalConversion generated from: '<S15>/Shift_Up_Ind'
       *  UnitDelay: '<S15>/Unit Delay2'
       *  UnitDelay: '<S15>/Unit Delay3'
       *  UnitDelay: '<S15>/Unit Delay4'
       */
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_BlinkReq
        = Mdl_Gear_ARID_DEF.Prev_Shift_Blink_pattern;
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Down =
        Mdl_Gear_ARID_DEF.Prev_Shift_Down_Ind;
      Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Up =
        Mdl_Gear_ARID_DEF.Prev_Shift_Up_Ind;

      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S15>/Constant1'
       *  Constant: '<S21>/Constant'
       *  RelationalOperator: '<S21>/Compare'
       */
      if (rtb_Shift_Ind_Pos != ((uint16)((uint8)STATUS_OFF))) {
        rtb_TmpSignalConversionAtrpVehi = ((uint8)STATUS_ON);
      } else {
        rtb_TmpSignalConversionAtrpVehi = ((uint8)STATUS_OFF);
      }

      /* Outport: '<Root>/pp_ShiftPositionDisplay_ShiftPositionDisplay' incorporates:
       *  Switch: '<S15>/Switch'
       */
      (void)Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay((uint8)
        rtb_TmpSignalConversionAtrpVehi);

      /* Switch: '<S15>/Switch1' incorporates:
       *  Constant: '<S15>/Constant3'
       */
      if (((uint8)PGM_LOGIC_ENABLE) == 0U) {
        /* Merge: '<S10>/Merge' */
        rtb_Shift_Ind_Pos = (uint16)rtb_RxCan_GetSignalValue_o1;
      }

      /* End of Switch: '<S15>/Switch1' */
      /* End of Outputs for SubSystem: '<S10>/Subsystem' */
    }

    /* End of If: '<S10>/If' */

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    Mdl_Gear_ARID_DEF.DataTypeConversion = (uint8)rtb_Shift_Ind_Pos;

    /* BusCreator generated from: '<S10>/ShiftPosIndStatusData_creator2' incorporates:
     *  BusCreator: '<S10>/ShiftPosIndStatusData_creator1'
     */
    Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2.status.Shift_Ind_Pos =
      Mdl_Gear_ARID_DEF.DataTypeConversion;

    /* End of Outputs for SubSystem: '<S4>/Subsystem1' */
  }

  /* End of If: '<S4>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Gear_Task' */

  /* Outport: '<Root>/pp_Shift_Position_ShiftPosition' */
  (void)Rte_Write_pp_Shift_Position_ShiftPosition((ShiftPosition)
    Mdl_Gear_ARID_DEF.DataTypeConversion);

  /* Outport: '<Root>/pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData' */
  Mdl_Gear_ARID_DEF.pp_Shiftpos_ShiftPosIndStatus_S =
    Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2;
  (void)Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData
    (&Mdl_Gear_ARID_DEF.pp_Shiftpos_ShiftPosIndStatus_S);
}

/* Model initialize function */
FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Gear_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Gear_Task_sys'
   */
  /* SystemInitialize for IfAction SubSystem: '<S4>/Subsystem1' */
  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  Mdl_Gear_ARID_DEF.l_300ms_count = ((uint8)Init_Count);

  /* End of SystemInitialize for SubSystem: '<S4>/Subsystem1' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Gear_Task' */

  /* SystemInitialize for Outport: '<Root>/pp_Shift_Position_ShiftPosition' */
  (void)Rte_Write_pp_Shift_Position_ShiftPosition((ShiftPosition)
    Mdl_Gear_ARID_DEF.DataTypeConversion);

  /* SystemInitialize for Outport: '<Root>/pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData' */
  Mdl_Gear_ARID_DEF.pp_Shiftpos_ShiftPosIndStatus_S =
    Mdl_Gear_ARID_DEF.ShiftPosIndStatusData_creator2;
  (void)Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData
    (&Mdl_Gear_ARID_DEF.pp_Shiftpos_ShiftPosIndStatus_S);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
