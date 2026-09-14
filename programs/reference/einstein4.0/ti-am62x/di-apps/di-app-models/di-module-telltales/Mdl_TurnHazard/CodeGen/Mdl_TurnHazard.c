/*
 * File: Mdl_TurnHazard.c
 *
 * Code generated for Simulink model 'Mdl_TurnHazard'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 31 15:42:58 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_TurnHazard.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_INACTIVE
#error The value of parameter "CLUSTER_INACTIVE" is not defined
#endif

#ifndef TT_TURN_OFF
#error The value of parameter "TT_TURN_OFF" is not defined
#endif

#ifndef TT_TURN_ON
#error The value of parameter "TT_TURN_ON" is not defined
#endif

#ifndef TurnBlink
#error The value of parameter "TurnBlink" is not defined
#endif

#ifndef TurnOff
#error The value of parameter "TurnOff" is not defined
#endif

#ifndef eSIGNAL_OK
#error The value of parameter "eSIGNAL_OK" is not defined
#endif

#ifndef eTurn_Indicator_ControlIn
#error The value of parameter "eTurn_Indicator_ControlIn" is not defined
#endif

/* Model step function for TID1 */
FUNC(void, Mdl_TurnHazard_CODE) Mdl_TurnHazard_Task(void) /* Explicit Task: Mdl_TurnHazard_Task */
{
  uint8 rtb_RightInd_Sts_Currentelltale;
  uint8 rtb_RxCan_GetSignalValue1_o1;
  uint8 rtb_RxCan_GetSignalValue1_o2;

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode
    (&rtb_RightInd_Sts_Currentelltale);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_TurnHazard_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_TurnHazard_Task_sys'
   */
  /* FunctionCaller: '<S5>/RxCan_GetSignalValue1' */
  (void)Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(((uint8)
    eTurn_Indicator_ControlIn), &rtb_RxCan_GetSignalValue1_o1,
    &rtb_RxCan_GetSignalValue1_o2);

  /* If: '<S4>/If' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (rtb_RightInd_Sts_Currentelltale != ((uint8)CLUSTER_INACTIVE)) {
    /* Outputs for IfAction SubSystem: '<S4>/TT_LOGIC' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Truth Table: '<S9>/Truth Table' */
    /*  TT_Left = Off */
    /*  TT_Right = Off */
    /*  TT_Left = On */
    /*  TT_Right = On */
    /*  Both TT Blink - Hazard */
    if ((rtb_RxCan_GetSignalValue1_o2 != ((uint8)eSIGNAL_OK)) ||
        (rtb_RxCan_GetSignalValue1_o1 == ((uint8)TurnOff))) {
      /*  Left and Right Telltales are off */
      rtb_RightInd_Sts_Currentelltale = ((uint8)TT_TURN_OFF);
      rtb_RxCan_GetSignalValue1_o1 = ((uint8)TT_TURN_OFF);
    } else {
      switch (rtb_RxCan_GetSignalValue1_o1) {
       case ((uint8)cTH_ONE):
        /*  TT_Left = On */
        rtb_RightInd_Sts_Currentelltale = ((uint8)TT_TURN_OFF);
        rtb_RxCan_GetSignalValue1_o1 = ((uint8)TT_TURN_ON);
        break;

       case ((uint8)cTH_TWO):
        /*  TT_Right = On */
        rtb_RightInd_Sts_Currentelltale = ((uint8)TT_TURN_ON);
        rtb_RxCan_GetSignalValue1_o1 = ((uint8)TT_TURN_OFF);
        break;

       case ((uint8)cTH_THREE):
        /*  Both TT Blink - Hazard */
        rtb_RightInd_Sts_Currentelltale = ((uint8)TurnBlink);
        rtb_RxCan_GetSignalValue1_o1 = ((uint8)TurnBlink);
        break;

       default:
        /*  Default */
        /*  Left and Right Telltales are off */
        rtb_RightInd_Sts_Currentelltale = ((uint8)TT_TURN_OFF);
        rtb_RxCan_GetSignalValue1_o1 = ((uint8)TT_TURN_OFF);
        break;
      }
    }

    /* End of Truth Table: '<S9>/Truth Table' */

    /* Outport: '<Root>/pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus' incorporates:
     *  SignalConversion generated from: '<S9>/LeftInd_Sts_CurrentTelltaleStatus'
     */
    (void)Rte_Write_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus
      ((TT_OP_STATES)rtb_RxCan_GetSignalValue1_o1);

    /* Outport: '<Root>/pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus' incorporates:
     *  SignalConversion generated from: '<S9>/RightInd_Sts_CurrentelltaleStatus'
     */
    (void)Rte_Write_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus
      ((TT_OP_STATES)rtb_RightInd_Sts_Currentelltale);

    /* Outport: '<Root>/pp_TurnHazard_TurnL_Sts_LeftIndicatorSts' incorporates:
     *  SignalConversion generated from: '<S9>/TurnL_Sts_LeftIndicatorSts'
     */
    (void)Rte_Write_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts((TurnStates)
      rtb_RxCan_GetSignalValue1_o1);

    /* Outport: '<Root>/pp_TurnHazard_TurnR_Sts_RightIndicatorSts' incorporates:
     *  SignalConversion generated from: '<S9>/TurnR_Sts_RightIndicatorSts'
     */
    (void)Rte_Write_pp_TurnHazard_TurnR_Sts_RightIndicatorSts((TurnStates)
      rtb_RightInd_Sts_Currentelltale);

    /* End of Outputs for SubSystem: '<S4>/TT_LOGIC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Outport: '<Root>/pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/LeftInd_Sts_CurrentTelltaleStatus'
     */
    (void)Rte_Write_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus
      ((TT_OP_STATES)((uint8)TT_TURN_OFF));

    /* Outport: '<Root>/pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/RightInd_Sts_CurrentelltaleStatus'
     */
    (void)Rte_Write_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus
      ((TT_OP_STATES)((uint8)TT_TURN_OFF));

    /* Outport: '<Root>/pp_TurnHazard_TurnL_Sts_LeftIndicatorSts' incorporates:
     *  Constant: '<S8>/Constant2'
     *  SignalConversion generated from: '<S8>/TurnL_Sts_LeftIndicatorSts'
     */
    (void)Rte_Write_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts((TurnStates)((uint8)
      TT_TURN_OFF));

    /* Outport: '<Root>/pp_TurnHazard_TurnR_Sts_RightIndicatorSts' incorporates:
     *  Constant: '<S8>/Constant3'
     *  SignalConversion generated from: '<S8>/TurnR_Sts_RightIndicatorSts'
     */
    (void)Rte_Write_pp_TurnHazard_TurnR_Sts_RightIndicatorSts((TurnStates)
      ((uint8)TT_TURN_OFF));

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_TurnHazard_Task' */
}

/* Model initialize function */
FUNC(void, Mdl_TurnHazard_CODE) Mdl_TurnHazard_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
