/*
 * File: Ctrl_warning.c
 *
 * Code generated for Simulink model 'Ctrl_warning'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec  2 17:54:09 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ctrl_warning.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef TotalNumOfWarnings
#error The variable for the parameter "TotalNumOfWarnings" is not defined
#endif

#ifndef UI_WARNING_EVENT_FORCED
#error The variable for the parameter "UI_WARNING_EVENT_FORCED" is not defined
#endif

#ifndef UI_WARNING_EVENT_NONE
#error The variable for the parameter "UI_WARNING_EVENT_NONE" is not defined
#endif

#ifndef UI_WARNING_EVENT_RETRIGGER
#error The variable for the parameter "UI_WARNING_EVENT_RETRIGGER" is not defined
#endif

#ifndef UI_WARNING_STATUS_OFF
#error The variable for the parameter "UI_WARNING_STATUS_OFF" is not defined
#endif

#ifndef UI_WARNING_STATUS_ON
#error The variable for the parameter "UI_WARNING_STATUS_ON" is not defined
#endif

#ifndef WRNG_NOTIFIED_NONE
#error The variable for the parameter "WRNG_NOTIFIED_NONE" is not defined
#endif

#ifndef WRNG_NOTIFIED_SHOW
#error The variable for the parameter "WRNG_NOTIFIED_SHOW" is not defined
#endif

/* Exported data definition */

/* Definition for custom storage class: FileScope */
static VAR(uint8, Ctrl_warning_VAR) l_WarnAttriArr_A;
static VAR(uint16, Ctrl_warning_VAR) l_warningBit_Position;
static VAR(uint16, Ctrl_warning_VAR) l_warningByte_Position;

/* Block signals (default storage) */
VAR(B_Ctrl_warning_T, Ctrl_warning_VAR) Ctrl_warning_B;
static FUNC(void, Ctrl_warning_CODE_LOCAL) update_MasterWarning_Lamp(VAR
  (WarningId, AUTOMATIC) rtu_warningID, VAR(WarningStatus, AUTOMATIC)
  rtu_WarningStatus);

/* Output and update for atomic system: '<S31>/MasterLampStatus' */
static FUNC(void, Ctrl_warning_CODE_LOCAL) update_MasterWarning_Lamp(VAR
  (WarningId, AUTOMATIC) rtu_warningID, VAR(WarningStatus, AUTOMATIC)
  rtu_WarningStatus)
{
  uint16 rtb_Product;
  uint8 rtb_BitwiseOperator2;
  uint8 rtb_ShiftArithmetic;

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S41>/Constant'
   *  DataStoreWrite: '<S33>/Data Store Write'
   *  RelationalOperator: '<S41>/Compare'
   *  Selector: '<S33>/Selector1'
   */
  if (rtu_warningID < ((WarningId)WARN_LAMP_CONFIGURED)) {
    l_WarnAttriArr_A = WARN_ATTRIBUTES_ARRAY[(sint32)rtu_warningID];
  }

  /* End of Switch: '<S33>/Switch1' */

  /* S-Function (sfix_bitop): '<S33>/Bitwise Operator2' incorporates:
   *  Constant: '<S33>/Constant4'
   *  DataStoreRead: '<S33>/Data Store Read1'
   */
  rtb_BitwiseOperator2 = (uint8)((sint32)(((sint32)l_WarnAttriArr_A) & ((sint32)
    ((uint8)MASTER_LAMP_MASK))));

  /* Product: '<S33>/WarningByte' incorporates:
   *  Constant: '<S33>/Constant2'
   */
  l_warningByte_Position = (uint16)((((uint32)((uint8)BASE_DATA_TYPE)) == 0U) ?
    MAX_uint32_T : ((uint32)(((uint32)rtu_warningID) / ((uint32)((uint8)
    BASE_DATA_TYPE)))));

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Constant2'
   */
  rtb_Product = (uint16)((uint32)(((uint32)l_warningByte_Position) * ((uint32)
    ((uint8)BASE_DATA_TYPE))));

  /* Switch: '<S33>/Switch' incorporates:
   *  RelationalOperator: '<S33>/Relational Operator'
   *  Sum: '<S33>/Add'
   *  Sum: '<S33>/Add1'
   */
  if (rtb_Product >= ((uint16)rtu_warningID)) {
    l_warningBit_Position = (uint16)((sint32)(((sint32)rtb_Product) - ((sint32)
      rtu_warningID)));
  } else {
    l_warningBit_Position = (uint16)((sint32)(((sint32)rtu_warningID) - ((sint32)
      rtb_Product)));
  }

  /* End of Switch: '<S33>/Switch' */

  /* ArithShift: '<S33>/Shift Arithmetic' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  rtb_ShiftArithmetic = (uint8)((sint32)((uint32)(((uint32)1) << ((uint32)
    l_warningBit_Position))));

  /* Outputs for Atomic SubSystem: '<S33>/SetMasterWarningLamp' */
  /* If: '<S42>/If' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S49>/Compare'
   *  Switch: '<S46>/Switch1'
   */
  if (rtb_BitwiseOperator2 == ((uint8)RED)) {
    /* Outputs for IfAction SubSystem: '<S42>/UpdateRedLamp' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S48>/Constant'
     *  RelationalOperator: '<S48>/Compare'
     */
    if (l_warningByte_Position < ((uint16)TotalNumOfWarnings)) {
      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S47>/Constant'
       *  RelationalOperator: '<S47>/Compare'
       */
      if (rtu_WarningStatus == ((WarningStatus)((uint8)UI_WARNING_STATUS_ON))) {
        /* Assignment: '<S45>/Assignment' incorporates:
         *  DataStoreRead: '<S45>/Data Store Read'
         *  DataStoreWrite: '<S45>/Data Store Write'
         *  S-Function (sfix_bitop): '<S45>/Bitwise Operator2'
         *  Selector: '<S45>/Selector1'
         */
        l_MasterWarning_Lamp_Red[(sint32)l_warningByte_Position] = (uint8)
          ((sint32)(((sint32)l_MasterWarning_Lamp_Red[(sint32)
                     l_warningByte_Position]) | ((sint32)rtb_ShiftArithmetic)));
      } else {
        /* Assignment: '<S45>/Assignment' incorporates:
         *  DataStoreRead: '<S45>/Data Store Read'
         *  DataStoreWrite: '<S45>/Data Store Write'
         *  S-Function (sfix_bitop): '<S45>/Bitwise Operator1'
         *  S-Function (sfix_bitop): '<S45>/Bitwise Operator3'
         *  Selector: '<S45>/Selector1'
         */
        l_MasterWarning_Lamp_Red[(sint32)l_warningByte_Position] = (uint8)
          ((sint32)(((sint32)l_MasterWarning_Lamp_Red[(sint32)
                     l_warningByte_Position]) & ((sint32)((uint8)((sint32)
               (~rtb_ShiftArithmetic))))));
      }

      /* End of Switch: '<S45>/Switch' */
    }

    /* End of Switch: '<S45>/Switch1' */
    /* End of Outputs for SubSystem: '<S42>/UpdateRedLamp' */
  } else {
    /* Outputs for IfAction SubSystem: '<S42>/UpdateYellowLamp' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    if ((rtb_BitwiseOperator2 == ((uint8)YELLOW)) && (l_warningByte_Position <
         ((uint16)TotalNumOfWarnings))) {
      /* Switch: '<S46>/Switch' incorporates:
       *  Constant: '<S50>/Constant'
       *  RelationalOperator: '<S50>/Compare'
       *  Switch: '<S46>/Switch1'
       */
      if (rtu_WarningStatus == ((WarningStatus)((uint8)UI_WARNING_STATUS_ON))) {
        /* Assignment: '<S46>/Assignment' incorporates:
         *  DataStoreRead: '<S46>/Data Store Read1'
         *  DataStoreWrite: '<S46>/Data Store Write1'
         *  S-Function (sfix_bitop): '<S46>/Bitwise Operator2'
         *  Selector: '<S46>/Selector1'
         */
        l_MasterWarning_Lamp_Yellow[(sint32)l_warningByte_Position] = (uint8)
          ((sint32)(((sint32)l_MasterWarning_Lamp_Yellow[(sint32)
                     l_warningByte_Position]) | ((sint32)rtb_ShiftArithmetic)));
      } else {
        /* Assignment: '<S46>/Assignment' incorporates:
         *  DataStoreRead: '<S46>/Data Store Read1'
         *  DataStoreWrite: '<S46>/Data Store Write1'
         *  S-Function (sfix_bitop): '<S46>/Bitwise Operator3'
         *  S-Function (sfix_bitop): '<S46>/Bitwise Operator4'
         *  Selector: '<S46>/Selector1'
         */
        l_MasterWarning_Lamp_Yellow[(sint32)l_warningByte_Position] = (uint8)
          ((sint32)(((sint32)l_MasterWarning_Lamp_Yellow[(sint32)
                     l_warningByte_Position]) & ((sint32)((uint8)((sint32)
               (~rtb_ShiftArithmetic))))));
      }

      /* End of Switch: '<S46>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S42>/UpdateYellowLamp' */
  }

  /* End of If: '<S42>/If' */
  /* End of Outputs for SubSystem: '<S33>/SetMasterWarningLamp' */
}

/* Model step function for TID1 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Task(void) /* Sample time: [0.1s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetActiveWarningStatus(VAR(WarningId,
  AUTOMATIC) CurrentWarning, P2VAR(ExtWarningData, AUTOMATIC, Ctrl_warning_VAR)
  CurrentWarningStatus)
{
  sint32 i;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_GetActiveWarningStatus' */
  /* If: '<S1>/If' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   *  SignalConversion: '<S1>/TmpSignal ConversionAtCurrentWarningOutport1'
   */
  if (CurrentWarning < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S1>/ValidWarning' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Selector: '<S14>/Selector' incorporates:
     *  DataStoreRead: '<S14>/Data Store Read'
     */
    *CurrentWarningStatus = l_ArbtnWarnData_S[(sint32)CurrentWarning];

    /* End of Outputs for SubSystem: '<S1>/ValidWarning' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/InvldWarning' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* BusAssignment: '<S13>/Bus Assignment' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant3'
     */
    CurrentWarningStatus->ExtWarningCurrentStatus = ((uint8)
      UI_WARNING_STATUS_OFF);
    CurrentWarningStatus->ExtWarningCurrentEvent = ((uint8)UI_WARNING_EVENT_NONE);
    for (i = 0; i < 8; i++) {
      CurrentWarningStatus->ExtWarningCurrentPayload[i] = 0U;
    }

    /* End of BusAssignment: '<S13>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/InvldWarning' */
  }

  /* End of If: '<S1>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_GetActiveWarningStatus' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningDisplayedPayload(VAR
  (WarningId, AUTOMATIC) CurWarningId, VAR(uint8, AUTOMATIC) DisplayedPayload[8])
{
  sint32 i;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_GetWarningDisplayedPayload' */
  /* If: '<S2>/If' incorporates:
   *  Constant: '<S15>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   *  SignalConversion: '<S2>/TmpSignal ConversionAtCurWarningIdOutport1'
   */
  if (CurWarningId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S2>/ValidWarnInvoked' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Selector: '<S16>/Selector1' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read2'
     */
    Ctrl_warning_B.Selector1 = l_DisplayedPayload_A[(sint32)CurWarningId];

    /* End of Outputs for SubSystem: '<S2>/ValidWarnInvoked' */
  }

  /* End of If: '<S2>/If' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtDisplayedPayloadInport1' */
  for (i = 0; i < 8; i++) {
    DisplayedPayload[i] = Ctrl_warning_B.Selector1.WarningPayloadRecd[i];
  }

  /* End of SignalConversion: '<S2>/TmpSignal ConversionAtDisplayedPayloadInport1' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_GetWarningDisplayedPayload' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningDisplayedStatus(VAR
  (WarningId, AUTOMATIC) CurWarningId, P2VAR(uint8, AUTOMATIC, Ctrl_warning_VAR)
  DisplayedStatus)
{
  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_GetWarningDisplayedStatus' */
  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtCurWarningIdOutport1'
   */
  if (CurWarningId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* SignalConversion: '<S3>/TmpSignal ConversionAtDisplayedStatusInport1' incorporates:
     *  DataStoreRead: '<S3>/Data Store Read'
     *  Selector: '<S3>/Selector'
     */
    *DisplayedStatus = (uint8)l_DisplydWrnSts_E[(sint32)CurWarningId];
  } else {
    /* SignalConversion: '<S3>/TmpSignal ConversionAtDisplayedStatusInport1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    *DisplayedStatus = ((uint8)WRNG_NOTIFIED_NONE);
  }

  /* End of Switch: '<S3>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_GetWarningDisplayedStatus' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Get_Red_MasterLamp_Status(P2VAR(uint8,
  AUTOMATIC, Ctrl_warning_VAR) LampStatus)
{
  uint16 fl_RedLampIdx_u16;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_Get_Red_MasterLamp_Status' */
  /* SignalConversion: '<S4>/TmpSignal ConversionAtLampStatusInport1' incorporates:
   *  Chart: '<S4>/Chart'
   */
  /*  Master warning Lamp Status  */
  *LampStatus = 0U;

  /* Chart: '<S4>/Chart' */
  for (fl_RedLampIdx_u16 = 0U; fl_RedLampIdx_u16 < ((uint16)TotalNumOfWarnings);
       fl_RedLampIdx_u16 = (uint16)((sint32)(((sint32)fl_RedLampIdx_u16) + 1)))
  {
    if (((sint32)l_MasterWarning_Lamp_Red[(fl_RedLampIdx_u16)]) != 0) {
      /* SignalConversion: '<S4>/TmpSignal ConversionAtLampStatusInport1' */
      *LampStatus = 1U;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_Get_Red_MasterLamp_Status' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Get_Yellow_MasterLamp_Status(P2VAR
  (uint8, AUTOMATIC, Ctrl_warning_VAR) LampStatus)
{
  uint16 fl_YellowLampIdx_u16;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_Get_Yellow_MasterLamp_Status' */
  /* SignalConversion: '<S5>/TmpSignal ConversionAtLampStatusInport1' incorporates:
   *  Chart: '<S5>/Chart'
   */
  /*  Master warning Lamp Status  */
  *LampStatus = 0U;

  /* Chart: '<S5>/Chart' */
  for (fl_YellowLampIdx_u16 = 0U; fl_YellowLampIdx_u16 < ((uint16)
        TotalNumOfWarnings); fl_YellowLampIdx_u16 = (uint16)((sint32)(((sint32)
          fl_YellowLampIdx_u16) + 1))) {
    if (((sint32)l_MasterWarning_Lamp_Yellow[(fl_YellowLampIdx_u16)]) != 0) {
      /* SignalConversion: '<S5>/TmpSignal ConversionAtLampStatusInport1' */
      *LampStatus = 1U;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_Get_Yellow_MasterLamp_Status' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_SetWarningDisplayedPayload(VAR
  (WarningId, AUTOMATIC) CurWarningId, CONST(uint8, AUTOMATIC)
  CurWarningDispPayload[8])
{
  sint32 i;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_SetWarningDisplayedPayload' */
  /* If: '<S6>/If' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S20>/Compare'
   *  SignalConversion: '<S6>/TmpSignal ConversionAtCurWarningIdOutport1'
   */
  if (CurWarningId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S6>/ValidPayload' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* BusAssignment: '<S21>/Bus Assignment' incorporates:
     *  SignalConversion: '<S6>/TmpSignal ConversionAtCurWarningDispPayloadOutport1'
     */
    for (i = 0; i < 8; i++) {
      l_DisplayedPayload_A[(sint32)CurWarningId].WarningPayloadRecd[(i)] =
        CurWarningDispPayload[i];
    }

    /* End of BusAssignment: '<S21>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S6>/ValidPayload' */
  }

  /* End of If: '<S6>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_SetWarningDisplayedPayload' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_SetWarningDisplayedStatus(VAR
  (WarningId, AUTOMATIC) CurWarningId, VAR(WarningDisplayedStatus, AUTOMATIC)
  CurWarningDispStatus)
{
  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_SetWarningDisplayedStatus' */
  /* If: '<S7>/If' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S22>/Compare'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtCurWarningIdOutport1'
   */
  if (CurWarningId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S7>/StatusofValidWarningID' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Assignment: '<S23>/Assignment' incorporates:
     *  DataStoreWrite: '<S23>/Data Store Write'
     *  SignalConversion: '<S7>/TmpSignal ConversionAtCurWarningDispStatusOutport1'
     */
    l_DisplydWrnSts_E[(sint32)CurWarningId] = CurWarningDispStatus;

    /* If: '<S23>/If' incorporates:
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     *  SignalConversion: '<S7>/TmpSignal ConversionAtCurWarningDispStatusOutport1'
     */
    if (CurWarningDispStatus == ((WarningDisplayedStatus)((uint8)
          WRNG_NOTIFIED_SHOW))) {
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* BusAssignment: '<S25>/Bus Assignment' incorporates:
       *  Constant: '<S25>/Constant'
       */
      l_ArbtnWarnData_S[(sint32)CurWarningId].ExtWarningCurrentEvent = ((uint8)
        UI_WARNING_EVENT_NONE);

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
    }

    /* End of If: '<S23>/If' */
    /* End of Outputs for SubSystem: '<S7>/StatusofValidWarningID' */
  }

  /* End of If: '<S7>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_SetWarningDisplayedStatus' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_UpdateExtdPayload(VAR(WarningId,
  AUTOMATIC) WarningCurId, CONST(uint8, AUTOMATIC) WarningPayload[8])
{
  sint32 i;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_UpdateExtdPayload' */
  /* If: '<S9>/If' incorporates:
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S28>/Compare'
   *  SignalConversion: '<S9>/TmpSignal ConversionAtWarningCurIdOutport1'
   */
  if (WarningCurId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S9>/VldWarnId' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Assignment: '<S29>/Assignment' incorporates:
     *  Constant: '<S29>/Constant'
     *  DataStoreWrite: '<S29>/Data Store Write'
     */
    l_ExtdPayoadCalld_u8[(sint32)WarningCurId] = ((uint8)EXTD_PAYLOAD_AVBLSTS);

    /* BusAssignment: '<S29>/Bus Assignment' incorporates:
     *  SignalConversion: '<S9>/TmpSignal ConversionAtWarningPayloadOutport1'
     */
    for (i = 0; i < 8; i++) {
      l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[(i)] =
        WarningPayload[i];
    }

    /* End of BusAssignment: '<S29>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S9>/VldWarnId' */
  }

  /* End of If: '<S9>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_UpdateExtdPayload' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_UpdateWarningStatus(VAR(WarningId,
  AUTOMATIC) WarningCurId, VAR(WarningStatus, AUTOMATIC) WarningCurStatus, VAR
  (WarningEvent, AUTOMATIC) WarningCurEvent, VAR(uint32, AUTOMATIC)
  WarningPayload)
{
  sint32 i;

  /* Outputs for Function Call SubSystem: '<Root>/Ctrl_warning_UpdateWarningStatus' */
  /* If: '<S10>/If' incorporates:
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S30>/Compare'
   *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurIdOutport1'
   *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurStatusOutport1'
   */
  if (WarningCurId < ((WarningId)((uint16)TotalNumOfWarnings))) {
    /* Outputs for IfAction SubSystem: '<S10>/UpdateWarningProperties' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* BusAssignment: '<S31>/Bus Assignment' incorporates:
     *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurStatusOutport1'
     */
    l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentStatus =
      WarningCurStatus;

    /* Outputs for Atomic SubSystem: '<S31>/EventUpdates' */
    /* If: '<S32>/If' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S38>/Constant'
     *  Constant: '<S39>/Constant'
     *  DataStoreRead: '<S37>/Data Store Read'
     *  If: '<S37>/If'
     *  Logic: '<S37>/Logical Operator'
     *  RelationalOperator: '<S35>/Compare'
     *  RelationalOperator: '<S38>/Compare'
     *  RelationalOperator: '<S39>/Compare'
     *  Selector: '<S37>/Selector'
     *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurStatusOutport1'
     */
    if (WarningCurStatus == ((WarningStatus)((uint8)UI_WARNING_STATUS_OFF))) {
      /* Outputs for IfAction SubSystem: '<S32>/EventNone' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* BusAssignment: '<S36>/Bus Assignment' incorporates:
       *  Constant: '<S36>/Constant'
       */
      l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentEvent = ((uint8)
        UI_WARNING_EVENT_NONE);

      /* End of Outputs for SubSystem: '<S32>/EventNone' */
    } else {
      /* Outputs for IfAction SubSystem: '<S32>/EventUpdate' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      if ((l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentEvent !=
           ((uint8)UI_WARNING_EVENT_RETRIGGER)) && (l_ArbtnWarnData_S[(sint32)
           WarningCurId].ExtWarningCurrentEvent != ((uint8)
            UI_WARNING_EVENT_FORCED))) {
        /* Outputs for IfAction SubSystem: '<S37>/UpdateEvent' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* If: '<S37>/If' incorporates:
         *  BusAssignment: '<S40>/Bus Assignment'
         *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurEventOutport1'
         */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentEvent =
          WarningCurEvent;

        /* End of Outputs for SubSystem: '<S37>/UpdateEvent' */
      }

      /* End of Outputs for SubSystem: '<S32>/EventUpdate' */
    }

    /* End of If: '<S32>/If' */
    /* End of Outputs for SubSystem: '<S31>/EventUpdates' */

    /* Outputs for Atomic SubSystem: '<S31>/MasterLampStatus' */
    update_MasterWarning_Lamp(WarningCurId, WarningCurStatus);

    /* End of Outputs for SubSystem: '<S31>/MasterLampStatus' */

    /* Outputs for Atomic SubSystem: '<S31>/Payloadpdates' */
    /* If: '<S34>/If' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S54>/Constant'
     *  DataStoreRead: '<S53>/Data Store Read'
     *  If: '<S53>/If1'
     *  RelationalOperator: '<S52>/Compare'
     *  RelationalOperator: '<S54>/Compare'
     *  Selector: '<S53>/Selector'
     *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningCurStatusOutport1'
     */
    if (WarningCurStatus == ((WarningStatus)((uint8)UI_WARNING_STATUS_OFF))) {
      /* Outputs for IfAction SubSystem: '<S34>/ClearPayload' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      /* BusAssignment: '<S51>/Bus Assignment' */
      for (i = 0; i < 8; i++) {
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[(i)] =
          0U;
      }

      /* End of BusAssignment: '<S51>/Bus Assignment' */
      /* End of Outputs for SubSystem: '<S34>/ClearPayload' */
    } else {
      /* Outputs for IfAction SubSystem: '<S34>/PayloadUpdate' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      if (l_ExtdPayoadCalld_u8[(sint32)WarningCurId] != ((uint8)
           EXTD_PAYLOAD_AVBLSTS)) {
        /* Outputs for IfAction SubSystem: '<S53>/UpdateRecdPayload' incorporates:
         *  ActionPort: '<S55>/Action Port'
         */
        /* If: '<S53>/If1' incorporates:
         *  Assignment: '<S55>/Assignment'
         *  BusAssignment: '<S55>/Bus Assignment'
         *  Constant: '<S55>/Constant'
         *  Constant: '<S55>/Constant1'
         *  Constant: '<S55>/Constant2'
         *  Constant: '<S55>/Constant3'
         *  DataStoreWrite: '<S55>/Data Store Write1'
         *  DataTypeConversion: '<S55>/Data Type Conversion'
         *  DataTypeConversion: '<S55>/Data Type Conversion1'
         *  DataTypeConversion: '<S55>/Data Type Conversion2'
         *  DataTypeConversion: '<S55>/Data Type Conversion3'
         *  MATLAB Function: '<S56>/bit_shift'
         *  MATLAB Function: '<S57>/bit_shift'
         *  MATLAB Function: '<S58>/bit_shift'
         *  S-Function (sfix_bitop): '<S55>/Bitwise AND'
         *  S-Function (sfix_bitop): '<S55>/Bitwise AND1'
         *  S-Function (sfix_bitop): '<S55>/Bitwise AND2'
         *  S-Function (sfix_bitop): '<S55>/Bitwise AND3'
         *  SignalConversion: '<S10>/TmpSignal ConversionAtWarningPayloadOutport1'
         */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[0] =
          (uint8)((uint32)(WarningPayload & 255U));

        /* Outputs for Atomic SubSystem: '<S55>/Bit Shift' */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[1] =
          (uint8)((uint32)(((uint32)(WarningPayload & 65280U)) >> ((uint32)8)));

        /* End of Outputs for SubSystem: '<S55>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S55>/Bit Shift1' */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[2] =
          (uint8)((uint32)(((uint32)(WarningPayload & 16711680U)) >> ((uint32)16)));

        /* End of Outputs for SubSystem: '<S55>/Bit Shift1' */

        /* Outputs for Atomic SubSystem: '<S55>/Bit Shift2' */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[3] =
          (uint8)((uint32)(((uint32)(WarningPayload & 4278190080U)) >> ((uint32)
                    24)));

        /* End of Outputs for SubSystem: '<S55>/Bit Shift2' */
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[4] =
          ((uint8)WRN_PAYLOAD_INITVAL);
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[5] =
          ((uint8)WRN_PAYLOAD_INITVAL);
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[6] =
          ((uint8)WRN_PAYLOAD_INITVAL);
        l_ArbtnWarnData_S[(sint32)WarningCurId].ExtWarningCurrentPayload[7] =
          ((uint8)WRN_PAYLOAD_INITVAL);

        /* End of Outputs for SubSystem: '<S53>/UpdateRecdPayload' */
      }

      /* End of Outputs for SubSystem: '<S34>/PayloadUpdate' */
    }

    /* End of If: '<S34>/If' */
    /* End of Outputs for SubSystem: '<S31>/Payloadpdates' */
    /* End of Outputs for SubSystem: '<S10>/UpdateWarningProperties' */
  }

  /* End of If: '<S10>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ctrl_warning_UpdateWarningStatus' */
}

/* Output function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Warning_Group_update()
{
  /* (no output/update code required) */
}

/* Model initialize function */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
