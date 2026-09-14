/*
 * File: Mdl_wFuelLidOpen.c
 *
 * Code generated for Simulink model 'Mdl_wFuelLidOpen'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Aug 12 13:30:48 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mdl_wFuelLidOpen.h"
#include "Rte_Type.h"
#include "Platform_Types.h"

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

#ifndef UI_WARNING_STATUS_OFF
#error The value of parameter "UI_WARNING_STATUS_OFF" is not defined
#endif

#ifndef UI_WARNING_STATUS_ON
#error The value of parameter "UI_WARNING_STATUS_ON" is not defined
#endif

#ifndef WRN_NORM_FUECAP_02
#error The value of parameter "WRN_NORM_FUECAP_02" is not defined
#endif

#ifndef eSIGNAL_MISSING
#error The value of parameter "eSIGNAL_MISSING" is not defined
#endif

#ifndef eSIGNAL_NEVER_RECEIVED
#error The value of parameter "eSIGNAL_NEVER_RECEIVED" is not defined
#endif

#ifndef eWarningIn
#error The value of parameter "eWarningIn" is not defined
#endif

/* Model step function for TID1 */
FUNC(void, Mdl_wFuelLidOpen_CODE) Mdl_wFuelLidOpen_Task(void)
                                      /* Explicit Task: Mdl_wFuelLidOpen_Task */
{
  ClusterModes tmpRead_0 = 0U;
  IgntionSubstateType tmpRead = 0U;
  uint8 rtb_RxCan_GetSignalValue_o1 = 0U;
  uint8 rtb_RxCan_GetSignalValue_o2 = 0U;

  /* Inport: '<Root>/rp_ClusterMode_WSSCurrentClusterMode' */
  (void)Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wFuelLidOpen_Task' incorporates:
   *  SubSystem: '<Root>/Mdl_wFuelLidOpen_Task_sys'
   */
  /* FunctionCaller: '<S6>/RxCan_GetSignalValue' */
  (void)Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValue(((uint8)eWarningIn),
    &rtb_RxCan_GetSignalValue_o1, &rtb_RxCan_GetSignalValue_o2);

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
   *  RelationalOperator: '<S8>/Compare'
   */
  if (tmpRead_0 != ((ClusterModes)((uint8)CLUSTER_INACTIVE))) {
    /*  IGN OF condition */
    /*  CAN Data Received */
    (void)Rte_Read_rpIgnSubstate_IgnitionSubstate(&tmpRead);

    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Truth Table: '<S9>/Truth Table' incorporates:
     *  Inport: '<Root>/rpIgnSubstate_IgnitionSubstate'
     */
    if (((tmpRead == ((IgntionSubstateType)((uint8)IgnOff))) ||
         (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_MISSING))) ||
        (rtb_RxCan_GetSignalValue_o2 == ((uint8)eSIGNAL_NEVER_RECEIVED))) {
      /* Merge: '<S5>/Merge' */
      /*  WRN_NORM_FUELCAP is OFF */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)UI_WARNING_STATUS_OFF);
    } else if (rtb_RxCan_GetSignalValue_o1 == ((uint8)FUEL_CAN_SIG_VAL_ONE)) {
      /* Merge: '<S5>/Merge' */
      /*  WRN_NORM_FUELCAP  is ON */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)UI_WARNING_STATUS_ON);
    } else {
      /* Merge: '<S5>/Merge' */
      /*  Default */
      /*  WRN_NORM_FUELCAP is OFF */
      rtb_RxCan_GetSignalValue_o2 = ((uint8)UI_WARNING_STATUS_OFF);
    }

    /* End of Truth Table: '<S9>/Truth Table' */
    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S5>/Merge' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_RxCan_GetSignalValue_o2 = ((uint8)UI_WARNING_STATUS_OFF);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  }

  /* End of If: '<S5>/If' */

  /* FunctionCaller: '<S7>/UpdateWarningStatus' */
  Rte_Call_rpUpdateFuelLidOpenWarning_UpdateWarningStatus(((uint8)
    WRN_NORM_FUECAP_02), rtb_RxCan_GetSignalValue_o2, ((uint8)
    UI_WARNING_EVENT_NONE), FUEL_PAYLOAD_INVALID_VALUE);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Mdl_wFuelLidOpen_Task' */
}

/* Output function */
FUNC(void, Mdl_wFuelLidOpen_CODE) Mdl_wFuelLidOpen_Init(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, Mdl_wFuelLidOpen_CODE) mdl_wfuellidopen_init_1(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
