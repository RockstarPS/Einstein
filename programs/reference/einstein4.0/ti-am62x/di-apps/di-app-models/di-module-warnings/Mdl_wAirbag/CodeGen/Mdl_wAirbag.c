/*
 * File: Mdl_wAirbag.c
 *
 * Code generated for Simulink model 'Mdl_wAirbag'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Aug 12 13:22:52 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_wAirbag.h"
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

#ifndef UI_WARNING_EVENT_NONE
#error The value of parameter "UI_WARNING_EVENT_NONE" is not defined
#endif

#ifndef WRN_NORM_AIRBAG_03
#error The value of parameter "WRN_NORM_AIRBAG_03" is not defined
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
FUNC(void, Mdl_wAirbag_CODE) Mdl_wAirbag_Task(void) /* Explicit Task: Mdl_wAirbag_Task */
{
  ClusterModes tmpRead_0 = 0U;
  IgntionSubstateType tmpRead = 0U;
  uint8 rtb_RxCan_GetSignalValue_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue_o2 = 0U;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wAirbag_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_wAirbag_Task_sys'
   */
  /* FunctionCaller: '<S6>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_GetSignalValue(((uint8)eAirbagIn),
    &rtb_RxCan_GetSignalValue_o1, &rtb_RxCan_GetSignalValue_o2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wAirbag_Task' */

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wAirbag_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_wAirbag_Task_sys'
   */
  /* If: '<S5>/If' incorporates:
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   */
  if (tmpRead_0 != ((ClusterModes)((uint8)CLUSTER_INACTIVE))) {
    /*  IGN ON Condition */
    /*  CAN Missing Condition */
    (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&tmpRead);

    /* Outputs for IfAction SubSystem: '<S5>/Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Truth Table: '<S9>/Truth Table' incorporates:
     *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
     */
    if ((tmpRead == ((IgntionSubstateType)((uint8)IgnOff))) ||
        (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_NEVER_RECEIVED))) {
      /* Merge: '<S5>/Merge' */
      /*  AirBag Warning OFF Status */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)AIRBAG_SYSTEM_STAT_OFF);
    } else if ((rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_MISSING)) ||
               (rtb_RxCan_GetSignalValue_o1 == ((uint8)CAN_AIRBAG_SIGN_ONE_VALUE)))
    {
      /* Merge: '<S5>/Merge' */
      /*  AirBag Warning ON Status */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)AIRBAG_SYSTEM_STAT_ON);
    } else {
      /* Merge: '<S5>/Merge' */
      /*  Default */
      /*  AirBag Warning OFF Status */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)AIRBAG_SYSTEM_STAT_OFF);
    }

    /* End of Truth Table: '<S9>/Truth Table' */
    /* End of Outputs for SubSystem: '<S5>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action DefaultVal' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S5>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/Air_Bag_warn_Status'
     */
    rtb_RxCan_GetSignalValue_o2 = ((uint8)AIRBAG_SYSTEM_STAT_OFF);

    /* End of Outputs for SubSystem: '<S5>/If Action DefaultVal' */
  }

  /* End of If: '<S5>/If' */

  /* FunctionCaller: '<S7>/UpdateWarningStatus' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  Rte_Call_rpUpdateAirbagWarning_UpdateWarningStatus(((uint8)WRN_NORM_AIRBAG_03),
    rtb_RxCan_GetSignalValue_o2, ((uint8)UI_WARNING_EVENT_NONE), 65535U);

  /* FunctionCaller: '<S6>/UpdateWarningStatus' */
  Rte_Call_rpUpdateAirbagWarning_UpdateWarningStatus(0, 0, 0, 0U);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wAirbag_Task' */
}

/* Output function */
FUNC(void, Mdl_wAirbag_CODE) Mdl_wAirbag_Init(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, Mdl_wAirbag_CODE) mdl_wairbag_init_1(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
