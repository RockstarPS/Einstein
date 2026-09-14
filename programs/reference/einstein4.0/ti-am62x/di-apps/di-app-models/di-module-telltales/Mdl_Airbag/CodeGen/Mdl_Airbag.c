/*
 * File: Mdl_Airbag.c
 *
 * Code generated for Simulink model 'Mdl_Airbag'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jul 25 11:22:54 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_Airbag.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CLUSTER_INACTIVE
#error The value of parameter "CLUSTER_INACTIVE" is not defined
#endif

#ifndef IgnOff
#error The value of parameter "IgnOff" is not defined
#endif

#ifndef NETWORK_NORMAL
#error The value of parameter "NETWORK_NORMAL" is not defined
#endif

#ifndef TT_TURN_OFF
#error The value of parameter "TT_TURN_OFF" is not defined
#endif

#ifndef TT_TURN_ON
#error The value of parameter "TT_TURN_ON" is not defined
#endif

#ifndef eAirbagIn
#error The value of parameter "eAirbagIn" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

/* Model step function for TID1 */
FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Task(void) /* Explicit Task: Mdl_Airbag_Task */
{
  ClusterModes tmpRead_0 = 0U;
  IgntionSubstateType tmpRead = 0U;
  uint8 rtb_RxCan_GetSafeSignalValue_o1 = 0U;
  uint8 rtb_RxCan_GetSafeSignalValue_o2 = 0U;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Airbag_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Airbag_Task_sys'
   */
  /* FunctionCaller: '<S5>/RxCan_GetSafeSignalValue' */
  (void)Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue(((uint8)eAirbagIn),
    &rtb_RxCan_GetSafeSignalValue_o1, &rtb_RxCan_GetSafeSignalValue_o2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Airbag_Task' */

  /* Inport: '<Root>/rpIgnSubstate_IgnitionSubstate' */
  /*  Cluster Inactive , IGN Off Condition and Never Recvd condition */
  /*  Normal CAN Condition, Missing Condition */
  (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&tmpRead);

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Airbag_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_Airbag_Task_sys'
   */
  /* Truth Table: '<S4>/Truth Table' */
  if (((tmpRead_0 == ((ClusterModes)((uint8)CLUSTER_INACTIVE))) || (tmpRead ==
        ((IgntionSubstateType)((uint8)IgnOff)))) ||
      (rtb_RxCan_GetSafeSignalValue_o2 == ((uint8)eSIGNAL_NEVER_RECEIVED))) {
    /*  AirBag TT OFF Status */
    rtb_RxCan_GetSafeSignalValue_o2 = ((uint8)TT_TURN_OFF);
  } else if (((rtb_RxCan_GetSafeSignalValue_o1 == ((uint8)
                CAN_AIRBAG_SIGN_ONE_VALUE)) || (rtb_RxCan_GetSafeSignalValue_o1 ==
    ((uint8)CAN_AIRBAG_SIGN_TWO_VALUE))) || (rtb_RxCan_GetSafeSignalValue_o2 ==
              ((uint8)eSIGNAL_MISSING))) {
    /*  AirBag TT ON Status */
    rtb_RxCan_GetSafeSignalValue_o2 = ((uint8)TT_TURN_ON);
  } else {
    /*  Default */
    /*  AirBag TT OFF Status */
    rtb_RxCan_GetSafeSignalValue_o2 = ((uint8)TT_TURN_OFF);
  }

  /* End of Truth Table: '<S4>/Truth Table' */

  /* Outport: '<Root>/pp_Airbag_TT_Status_CurrentTelltaleStatus' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  (void)Rte_Write_pp_Airbag_TT_Status_CurrentTelltaleStatus((TT_OP_STATES)
    rtb_RxCan_GetSafeSignalValue_o2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_Airbag_Task' */
}

/* Model initialize function */
FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
