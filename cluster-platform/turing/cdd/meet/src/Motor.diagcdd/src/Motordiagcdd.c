/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Motordiagcdd
**
** Description:
**
**
**===================================================================================================================*/

#ifndef MOTORDIAGCDD_C
#define MOTORDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Motordiagcdd.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
// Define the Min and Max limit of the Gauges used
#ifdef CONTINOUS_POINTER_MOVEMENT
#if (NUMBER_OF_MOTORS == 1)
#define MIN Valid_StepperMotorID[0]
#define MAX MIN
#else
#define MIN Valid_StepperMotorID[0]
#define MAX Valid_StepperMotorID[NUMBER_OF_MOTORS - 1]
#endif
#endif
/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef MOTORDIAG_SERVICE
static boolean NVMWriteReq = FALSE;
eRoutineStatus HighCalibCtrl_RCStatus = eROUTINE_INACTIVE;	 // High Calibration Control Routine Status
eRoutineStatus PointerPlacemnt_RCStatus = eROUTINE_INACTIVE; // Pointer PLacement Routine Status
eRoutineStatus SFDROC_RCStatus = eROUTINE_INACTIVE;			 // SFD ROC Routine Status
eRoutineStatus SelfTest_RCStatus = eROUTINE_INACTIVE;
eRoutineStatus Conti_Pointr_Movemnt_RCStatus = eROUTINE_INACTIVE;
static Std_ReturnType HighCalib_ret = E_NOT_OK;
static Std_ReturnType PointerPlacemnt_ret = E_NOT_OK;
static Std_ReturnType SFDROC_ret = E_NOT_OK;
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
sManuf_StprRoutineSts Manuf_StprRoutineControlStatus[NUMBER_OF_MOTORS] = {0};
uint8 Manuf_STPR_Finished[NUMBER_OF_MOTORS] = {0};
uint8 Manuf_STPR_StartFlag[NUMBER_OF_MOTORS] = {0};
uint8 RequestForallChannels = 0U;
uint8 StepIndex = 0U;
StprContPointMovement StepContnuousPointerMovement[NUMBER_OF_MOTORS] = {0};
#endif

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef CONTINOUS_POINTER_MOVEMENT
static uint8 Manuf_StpSetting(uint8 cmd_type, uint8 ch_index);
static uint8 Manuf_Stpr_StartAllGauges(uint8 *Data, uint8 *NegRespCode);
void MotorDiag_CheckCurrentPosition(void);
void MotorDiag_CheckSteadyPosition(void);
void MotorDiag_MOTION_A_TO_B(void);
void MotorDiag_MOTION_B_TO_A(void);
void MotorDiag_Switch_Between_Position(void);
#endif

#ifdef MOTORDIAG_SERVICE
static void Manuf_FillResBufferU16toU8(uint16 *InputData, uint8 *Outputdata, uint8 BufferSize);
/*=====================================================================================================================
**
** Function Name    :  Manuf_FillResBufferU16toU8
**
** Visibility       :  Private
**
** Description      :  Splits one uint16 value into two uint8 values
**                     Extracts MSB and LSB from a uint16 data
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Inputdata: uint16 value(s)
**					   Outputdata: uint8 value(s)
**					   BufferSize: number of uint16 values to be converted to uint8
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static void Manuf_FillResBufferU16toU8(uint16 *InputData, uint8 *Outputdata, uint8 BufferSize)
{
    uint8 LoopIndex;
    uint8 TempIndex;
    uint8 TempVal;

    TempIndex = 0U;
    for (LoopIndex = 0U; LoopIndex < BufferSize; LoopIndex++)
    {
        /* Extract high byte*/
        TempVal = (uint8)((InputData[LoopIndex] & MANUF_HIGHBYTEMASK) >> MANUF_SHIFT8BITS);
        Outputdata[TempIndex] = TempVal;
        /*Extract low byte*/
        TempVal = (uint8)(InputData[LoopIndex] & MANUF_LOWBYTEMASK);
        Outputdata[TempIndex + 1U] = TempVal;
        /*Point to next 16 bit value*/
        TempIndex++;
        TempIndex++;
    }
}

/*=====================================================================================================================
**
** Function Name    :  Manuf_FillResBufferU8toU16
**
** Visibility       :  Private
**
** Description      :  Merges two uint8 values to one uint16 value
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Inputdata: uint8 value(s)
**					   Outputdata: uint16 value(s)
**					   BufferSize: number of uint16 values to be created
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Manuf_FillResBufferU8toU16(const uint8 *InputBuffer, uint16 *OutputBuffer, uint8 BufferSize)
{
    uint8 TempIndex;
    uint8 LoopIndex;
    uint16 TempVal;

    TempIndex = 0U;
    for (LoopIndex = 0U; LoopIndex < BufferSize; LoopIndex++)
    {
        TempVal = ((uint16)((uint16)InputBuffer[TempIndex] << MANUF_SHIFT8BITS) | InputBuffer[(TempIndex + 1U)]);
        OutputBuffer[LoopIndex] = TempVal;
        /*Point to next 16 bit value*/
        TempIndex++;
        TempIndex++;
    }
}
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
/*=====================================================================================================================
**
** Function Name    :  Manuf_Stpr_StartAllGauges
**
** Visibility       :  Private
**
** Description      :  The function will start all the stepper motors if all the stepper motor is configured
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data: the stepper motor ID, Position A, Position B
**					   NegRespCode:to be updated with error code if any
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static uint8 Manuf_Stpr_StartAllGauges(uint8 *Data, uint8 *NegRespCode)
{
    uint8 ResultL = MANUF_OK;
    uint8 Index = 0U;

    for (Index = 0U; Index < NUMBER_OF_MOTORS; Index++)
    {
        if (eROUTINE_INPROGRESS == Manuf_StprRoutineControlStatus[Index].StprReading)
        {
            ResultL = MANUF_FAIL;
            Manuf_StprRoutineControlStatus[Index].StprReading = (uint8)eROUTINE_INPROGRESS;
            break;
        }
    }

    if (MANUF_OK == ResultL)
    {

        for (Index = 0U; Index < NUMBER_OF_MOTORS; Index++)
        {
            ResultL = Manuf_StpSetting(MANUF_STPRCMD_START, Index);
            Manuf_StprRoutineControlStatus[Index].StprReading = eROUTINE_INPROGRESS;
        }
        Data[DATA_BYTE_0] = (uint8)eROUTINE_INPROGRESS;
        *NegRespCode = MANUF_OK;
    }
    else
    {
        Manuf_StprRoutineControlStatus[Index].StprReading = (uint8)eROUTINE_FINISH_NOK;
        Data[DATA_BYTE_0] = (uint8)eROUTINE_FINISH_NOK;
        *NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
    }

    return (ResultL);
}
/*=====================================================================================================================
**
** Function Name    :  Manuf_StpSetting
**
** Visibility       :  Private
**
** Description      :  The start and stop of the stepper motor pointer movement status is updated
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  cmd_type: command for start or stop the pointer movement
**					   ch_index: Id of the stepper motor
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static uint8 Manuf_StpSetting(uint8 cmd_type, uint8 ch_index)
{
    uint8 ResultL = E_OK;

    switch (cmd_type)
    {
    case MANUF_STPRCMD_START:
    {
        Manuf_STPR_Finished[ch_index] = MANUF_FALSE;
        Manuf_STPR_StartFlag[ch_index] = MANUF_TRUE;
    }
    break;
    case MANUF_STPRCMD_STOP:
    {
        Manuf_STPR_StartFlag[ch_index] = MANUF_FALSE;
        Manuf_STPR_Finished[ch_index] = MANUF_TRUE;
    }
    break;

    case MANUF_STPRCMD_GETRESULTS:
    {
        //			if(Manuf_STPR_Finished[ch_index] == MANUF_TRUE)
        //			{
        //				*outbuffer = Manuf_STPR_Result[ch_index];
        //				ResultL = MANUF_OK;
        //			}
        //			else
        //			{
        //				ResultL = MANUF_WAIT;
        /* 			}                                               */
    }
    break;

    default:
        ResultL = E_NOT_OK;
        break;
    }
    return ResultL;
}

/*=====================================================================================================================
**
** Function Name    :  Stpr_Periodic_Function
**
** Visibility       :  Private
**
** Description      :  The stepper motor perform different operations depending on their present state.
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void Stpr_Periodic_Function(void)
{
    for (StepIndex = 0U; StepIndex < NUMBER_OF_MOTORS; StepIndex++)
    {
        if (Manuf_STPR_StartFlag[StepIndex] == MANUF_TRUE)
        {
            switch (StepContnuousPointerMovement[StepIndex].StateId)
            {

            case CHECK_INITIAL_POSITION:
            {
                MotorDiag_CheckCurrentPosition();
            }
            break;
            case CHECK_STEADY_POSITION:
            {
                MotorDiag_CheckSteadyPosition();
            }
            break;
            case MOTION_A_TO_B:
            {
                MotorDiag_MOTION_A_TO_B();
            }
            break;
            case MOTION_B_TO_A:
            {
                MotorDiag_MOTION_B_TO_A();
            }
            break;
            case SWITCH_BTW_POSITION:
            {
                MotorDiag_Switch_Between_Position();
            }
            break;
            }
        }
    }
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_CheckCurrentPosition
**
** Visibility       :  Private
**
** Description      :  The function to check the current position of the stepper motor
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MotorDiag_CheckCurrentPosition(void)
{
    uint8 Index = 0U;

    if (RequestForallChannels == 1U)
    {
        for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
        {
            (void)Continous_Pointer_Movement_RC.GetCurrentPos_MicroStp_Or_Deg(Index, &StepContnuousPointerMovement[Index].PositioninDegree);

            if (StepContnuousPointerMovement[Index].PositioninDegree != StepContnuousPointerMovement[Index].Position_A)
            {
                (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_Deg(Index, &StepContnuousPointerMovement[Index].Position_A);
            }
            StepContnuousPointerMovement[Index].StateId = CHECK_STEADY_POSITION;
        }
    }
    else
    {
        if (StepContnuousPointerMovement[StepIndex].StepperID >= MIN && StepContnuousPointerMovement[StepIndex].StepperID <= MAX)
        {
            (void)Continous_Pointer_Movement_RC.GetCurrentPos_MicroStp_Or_Deg(Index, &StepContnuousPointerMovement[Index].PositioninDegree);

            if (StepContnuousPointerMovement[StepIndex].PositioninDegree != StepContnuousPointerMovement[StepIndex].Position_A)
            {
                (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_Deg((StepContnuousPointerMovement[StepIndex].ReMap_StepperID), &StepContnuousPointerMovement[StepIndex].Position_A);
            }
            StepContnuousPointerMovement[StepIndex].StateId = CHECK_STEADY_POSITION;
        }
    }
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_CheckSteadyPosition
**
** Visibility       :  Private
**
** Description      :  The function to get the current status of the stepper motor
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MotorDiag_CheckSteadyPosition(void)
{
    uint8 Index = 0U;

    if (RequestForallChannels == 1U)
    {
        for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
        {
            (void)Continous_Pointer_Movement_RC.Get_Stepper_Status(Index, &StepContnuousPointerMovement[Index].StepperState);

            if (StepContnuousPointerMovement[Index].StepperState == eStpStat_Ready)
            {
                StepContnuousPointerMovement[Index].StateId = MOTION_A_TO_B;
            }
            else
            {
            }
        }
    }
    else
    {
        if (StepContnuousPointerMovement[StepIndex].StepperID >= MIN && StepContnuousPointerMovement[StepIndex].StepperID <= MAX)
        {
            (void)Continous_Pointer_Movement_RC.Get_Stepper_Status(StepContnuousPointerMovement[StepIndex].ReMap_StepperID, &StepContnuousPointerMovement[StepIndex].StepperState);
            if (StepContnuousPointerMovement[StepIndex].StepperState == eStpStat_Ready)
            {
                StepContnuousPointerMovement[StepIndex].StateId = MOTION_A_TO_B;
            }
            else
            {
            }
        }
        else
        {
        }
    }
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_MOTION_A_TO_B
**
** Visibility       :  Private
**
** Description      :  The function to move the motor from a position A to position B
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MotorDiag_MOTION_A_TO_B(void)
{
    uint8 Index = 0U;

    if (RequestForallChannels == 1U)
    {
        for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
        {
            (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_DegEx(Index, &StepContnuousPointerMovement[Index].Position_B, &StepContnuousPointerMovement[Index].Time);
        }
    }

    else
    {
        if (StepContnuousPointerMovement[StepIndex].StepperID >= MIN && StepContnuousPointerMovement[StepIndex].StepperID <= MAX)
        {
            (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_DegEx(StepContnuousPointerMovement[StepIndex].ReMap_StepperID, &StepContnuousPointerMovement[StepIndex].Position_B, &StepContnuousPointerMovement[StepIndex].Time);
        }
        else
        {
        }
    }
    StepContnuousPointerMovement[StepIndex].StateId = SWITCH_BTW_POSITION;
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_MOTION_B_TO_A
**
** Visibility       :  Private
**
** Description      :  The function to move the motor from a position B to position A
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MotorDiag_MOTION_B_TO_A(void)
{
    uint8 Index = 0U;

    if (RequestForallChannels == 1U)
    {
        for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
        {
            (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_DegEx(Index, &StepContnuousPointerMovement[Index].Position_A, &StepContnuousPointerMovement[Index].Time);
        }
    }
    else
    {
        if (StepContnuousPointerMovement[StepIndex].StepperID >= MIN && StepContnuousPointerMovement[StepIndex].StepperID <= MAX)
        {
            (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_DegEx(StepContnuousPointerMovement[StepIndex].ReMap_StepperID, &StepContnuousPointerMovement[StepIndex].Position_A, &StepContnuousPointerMovement[StepIndex].Time);
        }
        else
        {
        }
    }
    StepContnuousPointerMovement[StepIndex].StateId = SWITCH_BTW_POSITION;
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Switch_Between_Position
**
** Visibility       :  Private
**
** Description      :  The function to check the status of the stepper motor and switch the pointer between position A and B
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
void MotorDiag_Switch_Between_Position(void)
{
    uint8 Index = 0U;

    if (RequestForallChannels == 1U)
    {
        for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
        {
            (void)Continous_Pointer_Movement_RC.Get_Stepper_Status(Index, &StepContnuousPointerMovement[Index].StepperState);
            if (StepContnuousPointerMovement[Index].StepperState == eStpStat_Ready)
            {
                if (StepContnuousPointerMovement[Index].StateId == MOTION_A_TO_B)
                {
                    StepContnuousPointerMovement[Index].StateId = MOTION_B_TO_A;
                }
                else
                {
                    StepContnuousPointerMovement[Index].StateId = MOTION_A_TO_B;
                }
            }
            else
            {
            }
        }
    }
    else
    {
        if (StepContnuousPointerMovement[StepIndex].StepperID >= MIN && StepContnuousPointerMovement[StepIndex].StepperID <= MAX)
        {
            (void)Continous_Pointer_Movement_RC.Get_Stepper_Status(StepContnuousPointerMovement[StepIndex].ReMap_StepperID, &StepContnuousPointerMovement[StepIndex].StepperState);
            if (StepContnuousPointerMovement[StepIndex].StepperState == eStpStat_Ready)
            {
                if (StepContnuousPointerMovement[StepIndex].StateId == MOTION_A_TO_B)
                {
                    StepContnuousPointerMovement[StepIndex].StateId = MOTION_B_TO_A;
                }
                else
                {
                    StepContnuousPointerMovement[StepIndex].StateId = MOTION_A_TO_B;
                }
            }
            else
            {
            }
        }
        else
        {
        }
    }
}
#endif
/*=====================================================================================================================
**  PUBLIC
**====================================================================================================================*/
#ifdef ORDER_IN_USTEPS_OR_DEG
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_Microsteps_Or_Degrees_STA
**
** Visibility       :  Public
**
** Description      :  Service to move the stepper motor to a position defined in microsteps or Degrees. The reference is
**					   the mechanical stop. This service control the stepper-motor without calibration from mechanical stop.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_STA_Diag_FD07
**
** Inputs           :  Data[in]: position in microsteps or degree for the respective gauge
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Order_In_Microsteps_Or_Degrees_STA(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OrderInMicrosteps.MotorDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_Microsteps_Or_Degrees_RCTE
**
** Visibility       :  Public
**
** Description      :  service to return the control to the ECU
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_RCTE_Diag_FD07
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Order_In_Microsteps_Or_Degrees_RCTE(uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OrderInMicrosteps.MotorDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ORDER_IN_VEHICLE_UNIT
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_Vehicle_Unit_STA
**
** Visibility       :  Public
**
** Description      :  Service to move the stepper motor to a gauge position defined in vehicle unit.
**					   This service control the stepper-motor with calibration.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_STA_Diag_FD08
**
** Inputs           :  Data[in]: position of the respective gauge
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Order_In_Vehicle_Unit_STA(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    #ifdef cSpeedo_GaugeID
    uint16 DiagRequestSpeedo = 0;
    uint16 Speedo_GaugeValue = 0U;
    #endif

    #ifdef cTacho_GaugeID
    uint16 DiagRequestTacho = 0;
    uint16 Tacho_GaugeValue = 0U;
    #endif

    #ifdef cFuel_GaugeID
    uint16 DiagRequestFuel = 0;
    uint16 Fuel_GaugeValue = 0U;
    #endif

    #ifdef cEngineTemp_GaugeID
    uint16 DiagRequestECT = 0;
    uint16 ECT_GaugeValue = 0U;
    #endif

    #ifdef cOilPressure_GaugeID
    uint16 DiagRequestOil = 0;
    uint16 OilPressure_GaugeValue = 0U;
    #endif

    #ifdef cTransTemp_GaugeID
    uint16 DiagRequestTransT = 0;
    uint16 TransTemp_GaugeValue = 0U;
    #endif

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        switch (Data[0])
        {
        case SPEEDO_GAUGE:
        {
            #ifdef cSpeedo_GaugeID
            Speedo_GaugeValue = Data[DATA_BYTE_1];
            Speedo_GaugeValue = (Speedo_GaugeValue << 8);
            Speedo_GaugeValue |= Data[DATA_BYTE_2];
            SpeedoGaugeControl.Gauge_ControlVal(Speedo_GaugeValue);
            DiagRequestSpeedo = 1U;
            SpeedoGaugeControl.Gauge_ControlRq(DiagRequestSpeedo);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        case TACHO_GAUGE:
        {
            #ifdef cTacho_GaugeID
            Tacho_GaugeValue = Data[DATA_BYTE_1];
            Tacho_GaugeValue = (Tacho_GaugeValue << 8);
            Tacho_GaugeValue |= Data[DATA_BYTE_2];
            TachoGaugeControl.Gauge_ControlVal(Tacho_GaugeValue);
            DiagRequestTacho = 1U;
            TachoGaugeControl.Gauge_ControlRq(DiagRequestTacho);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        case FUEL_GAUGE:
        {
            #ifdef cFuel_GaugeID
            Fuel_GaugeValue = Data[DATA_BYTE_1];
            Fuel_GaugeValue = (Fuel_GaugeValue << 8);
            Fuel_GaugeValue |= Data[DATA_BYTE_2];
            FuelGaugeControl.Gauge_ControlVal(Fuel_GaugeValue);
            DiagRequestFuel = 1U;
            FuelGaugeControl.Gauge_ControlRq(DiagRequestFuel);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        case ENGINETEMP_GAUGE:
        {
            #ifdef cEngineTemp_GaugeID
            ECT_GaugeValue = Data[DATA_BYTE_1];
            ECT_GaugeValue = (ECT_GaugeValue << 8);
            ECT_GaugeValue |= Data[DATA_BYTE_2];
            EctGaugeControl.Gauge_ControlVal(ECT_GaugeValue);
            DiagRequestECT = 1U;
            EctGaugeControl.Gauge_ControlRq(DiagRequestECT);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        case OILPRESSURE_GAUGE:
        {
            #ifdef cOilPressure_GaugeID
            OilPressure_GaugeValue = Data[DATA_BYTE_1];
            OilPressure_GaugeValue = (OilPressure_GaugeValue << 8);
            OilPressure_GaugeValue |= Data[DATA_BYTE_2];
            OilPrsGaugeControl.Gauge_ControlVal(OilPressure_GaugeValue);
            DiagRequestOil = 1U;
            OilPrsGaugeControl.Gauge_ControlRq(DiagRequestOil);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        case TRANSTEMP_GAUGE:
        {
            #ifdef cTransTemp_GaugeID
            TransTemp_GaugeValue = Data[DATA_BYTE_1];
            TransTemp_GaugeValue = (TransTemp_GaugeValue << 8);
            TransTemp_GaugeValue |= Data[DATA_BYTE_2];
            TransTempGaugeControl.Gauge_ControlVal(TransTemp_GaugeValue);
            DiagRequestTransT = 1U;
            TransTempGaugeControl.Gauge_ControlRq(DiagRequestTransT);
            ret = E_OK;
            #else
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            #endif
        }
        break;
        default:
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
        break;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_Vehicle_Unit_RCTE
**
** Visibility       :  Public
**
** Description      :  Service to return the control to ECU. The gauge control value is set to 0.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_RCTE_Diag_FD08
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Order_In_Vehicle_Unit_RCTE(uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 CtrlRequest_Set = 1U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

        #ifdef cSpeedo_GaugeID
        SpeedoGaugeControl.Gauge_ControlVal(0);
        SpeedoGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        #ifdef cTacho_GaugeID
        TachoGaugeControl.Gauge_ControlVal(0);
        TachoGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        #ifdef cFuel_GaugeID
        FuelGaugeControl.Gauge_ControlVal(0);
        FuelGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        #ifdef cEngineTemp_GaugeID
        EctGaugeControl.Gauge_ControlVal(0);
        EctGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        #ifdef cOilPressure_GaugeID
        OilPrsGaugeControl.Gauge_ControlVal(0);
        OilPrsGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        #ifdef cTransTemp_GaugeID
        TransTempGaugeControl.Gauge_ControlVal(0);
        TransTempGaugeControl.Gauge_ControlRq(CtrlRequest_Set);
        #endif

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef HIGH_CALIBRATION_CONTROL
/*=====================================================================================================================
**
** Function Name    :  Motordiag_High_Calibration_Control_RCStart
**
** Visibility       :  Public
**
** Description      :  Service to search the reference for the pointer position. This service control the stepper-motor with calibration.
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_START_Diag_F104
**
** Inputs           :  Data[in]: Control type for the stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_High_Calibration_Control_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    ErrorCode[0] = 0x00;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (HighCalibCtrl_RCStatus != eROUTINE_INPROGRESS)
        {
            HighCalib_ret = HighCalibControl.MotorDiag_RCStart(Data, ErrorCode);
            if (ErrorCode[0] != 0)
            {
                ret = E_NOT_OK;
            }
            else
            {
                if (HighCalib_ret == E_OK)
                {
                    HighCalibCtrl_RCStatus = eROUTINE_INPROGRESS;
                    Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(HIGH_CALIB_CNTRL, HighCalibCtrl_RCStatus);
                    ret = E_OK;
                }
                else
                {
                    HighCalibCtrl_RCStatus = eROUTINE_FINISH_NOK;
                    ret = E_OK;
                }
            }
        }
        else
        {

            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Already Routine in progress*/
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Motordiag_High_Calibration_Control_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /* This service is not required */
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_High_Calibration_Control_RCStatus
**
** Visibility       :  Public
**
** Description      :  Service to get the status of high calibration homing, which will always return not active
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_RESULTS_Diag_F104
**
** Inputs           :  Data[in]: Control type for the stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_High_Calibration_Control_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        HighCalib_ret = HighCalibControl.MotorDiag_RCResult(Data, ErrorCode);
        if (HighCalib_ret == E_OK)
        {
            HighCalibCtrl_RCStatus = eROUTINE_INACTIVE;
            ret = E_OK;
        }
        else
        {
            HighCalibCtrl_RCStatus = eROUTINE_FINISH_NOK;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef HIGH_IMPEDANCE
/*=====================================================================================================================
**
** Function Name    :  Motordiag_High_Impedance_STA
**
** Visibility       :  Public
**
** Description      :  Service to drive the stepper motors with an external tool. So it need to put motor pins in open circuit without any power
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_STA_Diag_FD09
**
** Inputs           :  Data[in]: Stepper motor to be driven in high impedance
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_High_Impedance_STA(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = HighImpedance.MotorDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_High_Impedance_RCTE
**
** Visibility       :  Public
**
** Description      :  service to return the control to the ECU, which exits from the high impedance mode
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_RCTE_Diag_FD09
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_High_Impedance_RCTE(uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = HighImpedance.MotorDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef LOW_TORQUE
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Low_Torque_STA
**
** Visibility       :  Public
**
** Description      :  Service is used to set lower torque on the stepper motor output by a coil voltage adjustment.
**					   Low torque mode is used for hard point detection.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_STA_Diag_FD0A
**
** Inputs           :  Data[in]: Torque value for the respective stepper motor in percentage
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Low_Torque_STA(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = LowTorque.MotorDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Low_Torque_RCTE
**
** Visibility       :  Public
**
** Description      :  service is used to restore to the previous low torque value for the stepper motor
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_RCTE_Diag_FD0A
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Low_Torque_RCTE(uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = LowTorque.MotorDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef JUMP_IN_USTEPS
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Jump_In_Microsteps_STA
**
** Visibility       :  Public
**
** Description      :  Service is used to validate the Magnetic Offset Calibration. It forces the pointers to jump of a given amount of �Steps.
**					   It can be a forward or backward jump of 32 �Steps max.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_STA_Diag_FD0C
**
** Inputs           :  Data[in]: Jump value of the respective stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Jump_In_Microsteps_STA(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = JumpInMicrosteps.MotorDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Jump_In_Microsteps_RCTE
**
** Visibility       :  Public
**
** Description      :  service to return the control to the ECU, a High calibration as to be done.
**
** Invocation       :  MeetMgr.diagcdd,	Function:IOCTL_RCTE_Diag_FD0C
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Jump_In_Microsteps_RCTE(uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = JumpInMicrosteps.MotorDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef READ_MOTOR_POSITION
/*=====================================================================================================================
**
** Function Name    :  Motordiag_MotorPosition_Reached_Read
**
** Visibility       :  Public
**
** Description      :  reads the status of each stepper motor position reached
**
** Invocation       :  MeetMgr.diagcdd,	Function:Read_Diag_FA17
**
** Inputs           :  Data[out]:status of each stepper motor (0:stepper moving 1:stepper reached final position)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_MotorPosition_Reached_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ReadMotorPosRchd.MotorDiag_Read(&Data[0]);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef CONTINOUS_POINTER_MOVEMENT
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Continuous_Pointer_Movement_RCStart
**
** Visibility       :  Public
**
** Description      :  Service to move the stepper motor between a position A and B
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_START_Diag_F112
**
** Inputs           :  Data[In]:The stepper motor ID, position A and B in microsteps
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStart(uint8 *Data, uint8 *ErrorCode)
{

    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};
    uint8 NegRespCode = 0U;
    uint8 Index = 0U;
    uint8 Count = 0U;

    if (Data[DATA_BYTE_0] == 0x8F)
    {
        RequestForallChannels = 1U;
    }

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (RequestForallChannels == 1)
        {
            for (Count = 0; Count < NUMBER_OF_MOTORS; Count++)
            {
                Manuf_STPR_StartFlag[Count] = MANUF_TRUE;
                StepContnuousPointerMovement[Count].Position_A = (Data[DATA_BYTE_1] << 8);
                StepContnuousPointerMovement[Count].Position_A |= Data[DATA_BYTE_2];
                StepContnuousPointerMovement[Count].Position_B = (Data[DATA_BYTE_3] << 8);
                StepContnuousPointerMovement[Count].Position_B |= Data[DATA_BYTE_4];
                StepContnuousPointerMovement[Count].Time = ((Data[DATA_BYTE_5] * 100) / 2);
            }
            ret = Manuf_Stpr_StartAllGauges(Data, &NegRespCode);
            Data[DATA_BYTE_0] = (uint8)eROUTINE_INPROGRESS;
        }
        else if ((MAX >= Data[DATA_BYTE_0]) && (MIN <= Data[DATA_BYTE_0]))
        {
            switch (Data[DATA_BYTE_0])
            {
            #ifdef cSpeedo_GaugeID
            case SPEEDO_GAUGE:
                Index = cPtrSpeedoView_MotorID;
                break;
            #endif
            #ifdef cTacho_GaugeID
            case TACHO_GAUGE:
                Index = cPtrTachoView_MotorID;
                break;
            #endif
            #ifdef cFuel_GaugeID
            case FUEL_GAUGE:
                Index = cPtrFuelView_MotorID;
                break;
            #endif
            #ifdef cEngineTemp_GaugeID
            case ENGINETEMP_GAUGE:
                Index = cPtrEctView_MotorID;
                break;
            #endif
            #ifdef cOilPressure_GaugeID
            case OILPRESSURE_GAUGE:
                Index = cPtrOilView_MotorID;
                break;
            #endif
            #ifdef cTransTemp_GaugeID
            case TRANSTEMP_GAUGE:
                Index = cPtrTransView_MotorID;
                break;
            #endif
            default:
                break;
            }
            if (eROUTINE_INPROGRESS == Manuf_StprRoutineControlStatus[Index].StprReading)
            {
                ret = E_NOT_OK;
                Data[DATA_BYTE_0] = DCM_E_CONDITIONSNOTCORRECT;
                Manuf_StprRoutineControlStatus[Index].StprReading = (uint8)eROUTINE_FINISH_NOK;
                Data[DATA_BYTE_1] = (uint8)eROUTINE_FINISH_NOK;
            }
            else
            {
                RequestForallChannels = 0U;

                switch (Data[DATA_BYTE_0])
                {
                #ifdef cSpeedo_GaugeID
                case SPEEDO_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrSpeedoView_MotorID].ReMap_StepperID = cPtrSpeedoView_MotorID;
                    StepContnuousPointerMovement[cPtrSpeedoView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrSpeedoView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrSpeedoView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrSpeedoView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrSpeedoView_MotorID;
                }
                break;
                #endif
                #ifdef cTacho_GaugeID
                case TACHO_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrTachoView_MotorID].ReMap_StepperID = cPtrTachoView_MotorID;
                    StepContnuousPointerMovement[cPtrTachoView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrTachoView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrTachoView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrTachoView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrTachoView_MotorID;
                }
                break;
                #endif
                #ifdef cFuel_GaugeID
                case FUEL_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrFuelView_MotorID].ReMap_StepperID = cPtrFuelView_MotorID;
                    StepContnuousPointerMovement[cPtrFuelView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrFuelView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrFuelView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrFuelView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrFuelView_MotorID;
                }
                break;
                #endif
                #ifdef cEngineTemp_GaugeID
                case ENGINETEMP_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrEctView_MotorID].ReMap_StepperID = cPtrEctView_MotorID;
                    StepContnuousPointerMovement[cPtrEctView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrEctView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrEctView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrEctView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrEctView_MotorID;
                }
                break;
                #endif
                #ifdef cOilPressure_GaugeID
                case OILPRESSURE_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrOilView_MotorID].ReMap_StepperID = cPtrOilView_MotorID;
                    StepContnuousPointerMovement[cPtrOilView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrOilView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrOilView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrOilView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrOilView_MotorID;
                }
                break;
                #endif
                #ifdef cTransTemp_GaugeID
                case TRANSTEMP_GAUGE:
                {
                    StepContnuousPointerMovement[cPtrTransView_MotorID].ReMap_StepperID = cPtrTransView_MotorID;
                    StepContnuousPointerMovement[cPtrTransView_MotorID].StepperID = Data[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_1], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrTransView_MotorID].Position_A = buf[DATA_BYTE_0];
                    Manuf_FillResBufferU8toU16(&Data[DATA_BYTE_3], buf, DATA_LEN_1);
                    StepContnuousPointerMovement[cPtrTransView_MotorID].Position_B = buf[DATA_BYTE_0];
                    StepContnuousPointerMovement[cPtrTransView_MotorID].Time = ((Data[DATA_BYTE_5] * 100) / 2);
                    Index = cPtrTransView_MotorID;
                }
                break;
                #endif
                default:
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
                break;
                }
                ret = Manuf_StpSetting(MANUF_STPRCMD_START, Index);
                Manuf_StprRoutineControlStatus[Index].StprReading = eROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = (uint8)eROUTINE_INPROGRESS;
            }
        }
        else
        {
            *ErrorCode = INVALID_MODE;
        }
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Continuous_Pointer_Movement_RCStop
**
** Visibility       :  Public
**
** Description      :  Service to stop the movement of the stepper motor pointer, the pointer is return to 0 deg position
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_STOP_Diag_F112
**
** Inputs           :  Data[In]:The stepper motor ID, position A and B in microsteps
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStop(uint8 *Data, uint8 *ErrorCode)
{

    uint8 Index = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (RequestForallChannels == 1)
        {
            for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
            {
                (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_Deg(Index, 0);
            }

            for (Index = 0; Index < NUMBER_OF_MOTORS; Index++)
            {
                (void)Manuf_StpSetting(MANUF_STPRCMD_STOP, Index);
                Manuf_StprRoutineControlStatus[Index].StprReading = eROUTINE_FINISH_OK;
                StepContnuousPointerMovement[Index].StateId = CHECK_INITIAL_POSITION;
                RequestForallChannels = 0U;

                StepContnuousPointerMovement[Index].StepperState = 0xFFU;
                StepContnuousPointerMovement[Index].StepperID = 0U;
                StepContnuousPointerMovement[Index].ReMap_StepperID = 0U;
                StepContnuousPointerMovement[Index].Position_A = 0U;
                StepContnuousPointerMovement[Index].Position_B = 0U;
                StepContnuousPointerMovement[Index].PositioninDegree = 0U;
                StepContnuousPointerMovement[Index].ReachedPosition = 0U;
                StepContnuousPointerMovement[Index].Time = 0U;
                StepContnuousPointerMovement[Index].Onetimeaction = 0U;
            }

            StepIndex = 0;
            Data[DATA_LEN_0] = eROUTINE_FINISH_OK;
            ret = E_OK;
        }
        else
        {
            if ((Data[DATA_LEN_0] >= MIN && Data[DATA_LEN_0] <= MAX) && (RequestForallChannels == 0))
            {
                switch (Data[DATA_LEN_0])
                {
                #ifdef cSpeedo_GaugeID
                case SPEEDO_GAUGE:
                {
                    Index = cPtrSpeedoView_MotorID;
                }
                break;
                #endif
                #ifdef cTacho_GaugeID
                case TACHO_GAUGE:
                {
                    Index = cPtrTachoView_MotorID;
                }
                break;
                #endif
                #ifdef cFuel_GaugeID
                case FUEL_GAUGE:
                {
                    Index = cPtrFuelView_MotorID;
                }
                break;
                #endif
                #ifdef cEngineTemp_GaugeID
                case ENGINETEMP_GAUGE:
                {
                    Index = cPtrEctView_MotorID;
                }
                break;
                #endif
                #ifdef cOilPressure_GaugeID
                case OILPRESSURE_GAUGE:
                {
                    Index = cPtrOilView_MotorID;
                }
                break;
                #endif
                #ifdef cTransTemp_GaugeID
                case TRANSTEMP_GAUGE:
                {
                    Index = cPtrTransView_MotorID;
                }
                break;
                #endif
                default:
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
                break;
                }
                (void)Continous_Pointer_Movement_RC.SetPos_MicroStp_Or_Deg(Index, 0);
                (void)Manuf_StpSetting(MANUF_STPRCMD_STOP, Index);
                Manuf_StprRoutineControlStatus[Index].StprReading = eROUTINE_FINISH_OK;
                StepContnuousPointerMovement[Index].StateId = CHECK_INITIAL_POSITION;
                StepContnuousPointerMovement[Index].StepperState = 0xFF;
                StepContnuousPointerMovement[Index].StepperID = 0U;
                StepContnuousPointerMovement[Index].ReMap_StepperID = 0U;
                StepContnuousPointerMovement[Index].Position_A = 0U;
                StepContnuousPointerMovement[Index].Position_B = 0U;
                StepContnuousPointerMovement[Index].PositioninDegree = 0U;
                StepContnuousPointerMovement[Index].ReachedPosition = 0U;
                StepContnuousPointerMovement[Index].Time = 0U;
                StepContnuousPointerMovement[Index].Onetimeaction = 0U;
                StepIndex = 0;
                RequestForallChannels = 0U;
                Data[DATA_LEN_0] = eROUTINE_FINISH_OK;
                ret = E_OK;
            }
            else
            {
                Data[DATA_LEN_0] = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Continuous_Pointer_Movement_RCStatus
**
** Visibility       :  Public
**
** Description      :  Service to get the status of the stepper motor
**
** Invocation       :  MeetMgr.diagcdd , Function:RC_RESULTS_Diag_F112
**
** Inputs           :  Data[In]:The stepper motor ID, position A and B in microsteps
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    uint8 Index = 0;
    uint8 Count = 0;

    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if ((Data[DATA_LEN_0] >= MIN && Data[DATA_LEN_0] <= MAX) || (Data[DATA_LEN_0] == 0x8F))
        {
            switch (Data[DATA_LEN_0])
            {
            #ifdef cSpeedo_GaugeID
            case SPEEDO_GAUGE:
            {
                Index = cPtrSpeedoView_MotorID;
            }
            break;
            #endif
            #ifdef cTacho_GaugeID
            case TACHO_GAUGE:
            {
                Index = cPtrTachoView_MotorID;
            }
            break;
            #endif
            #ifdef cFuel_GaugeID
            case FUEL_GAUGE:
            {
                Index = cPtrFuelView_MotorID;
            }
            break;
            #endif
            #ifdef cEngineTemp_GaugeID
            case ENGINETEMP_GAUGE:
            {
                Index = cPtrEctView_MotorID;
            }
            break;
            #endif
            #ifdef cOilPressure_GaugeID
            case OILPRESSURE_GAUGE:
            {
                Index = cPtrOilView_MotorID;
            }
            break;
            #endif
            #ifdef cTransTemp_GaugeID
            case TRANSTEMP_GAUGE:
            {
                Index = cPtrTransView_MotorID;
            }
            break;
            #endif
            case ALL_GAUGES:
            {
                Index = 0x8F;
            }
            break;
            default:
                break;
            }
        }
        else
        {
        }
        if (Index < NUMBER_OF_MOTORS)
        {
            if (Manuf_StprRoutineControlStatus[Index].StprReading == (uint8)eROUTINE_INPROGRESS)
            {
                Conti_Pointr_Movemnt_RCStatus = eROUTINE_INPROGRESS;
            }
            else if (Manuf_StprRoutineControlStatus[Index].StprReading == (uint8)eROUTINE_FINISH_OK)
            {
                Conti_Pointr_Movemnt_RCStatus = eROUTINE_FINISH_OK;
            }
            else
            {
                Conti_Pointr_Movemnt_RCStatus = eROUTINE_INACTIVE;
            }
        }
        else if (Index == 0x8F)
        {
            for (Count = 0; Count < NUMBER_OF_MOTORS; Count++)
            {
                if (Manuf_StprRoutineControlStatus[Count].StprReading == (uint8)eROUTINE_INPROGRESS)
                {
                    Conti_Pointr_Movemnt_RCStatus = eROUTINE_INPROGRESS;
                    break;
                }
                else if (Manuf_StprRoutineControlStatus[Count].StprReading == (uint8)eROUTINE_FINISH_OK)
                {
                    Conti_Pointr_Movemnt_RCStatus = eROUTINE_FINISH_OK;
                }
                else
                {
                    Conti_Pointr_Movemnt_RCStatus = eROUTINE_INACTIVE;
                }
            }
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(CONTI_POINTER_MOVEMENT, Conti_Pointr_Movemnt_RCStatus);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#endif

// Not implemented - Service specific to HUD
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK;
}
// Not implemented - Service specific to HUD
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK;
}
// Not implemented - Service specific to HUD
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK;
}
// Not implemented - Service specific to HUD
Std_ReturnType Motordiag_ReadMotorSpeed_Read(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK;
}

#ifdef POINTER_PLACEMENT_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Routine_RCStart
**
** Visibility       :  Public
**
** Description      :  Service is used to place stepper motor to a position for pointer insertion.
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_START_Diag_F121
**
** Inputs           :  Data[out]: The status of the routine
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Placement_Routine_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        PointerPlacemnt_ret = PointerPlacementRoutine.MotorDiag_RCStart(&Data[0], ErrorCode);
        if (PointerPlacemnt_ret == E_OK)
        {
            PointerPlacemnt_RCStatus = eROUTINE_INPROGRESS;
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(POINTER_PLACEMENT, PointerPlacemnt_RCStatus);
            ret = E_OK;
        }
        else
        {
            PointerPlacemnt_RCStatus = eROUTINE_INACTIVE;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Motordiag_PointerPlacementRoutine_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /* This service is not required */
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Routine_RCStatus
**
** Visibility       :  Public
**
** Description      :   Service returns the status of the Pointer placement routine.
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_RESULTS_Diag_F121
**
** Inputs           :  Data[]:
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Pointer_Placement_Routine_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        PointerPlacemnt_ret = PointerPlacementRoutine.MotorDiag_RCResult(Data, ErrorCode);
        if (PointerPlacemnt_ret == E_OK)
        {
            ret = E_OK;
            switch (Data[DATA_BYTE_0])
            {
            case DATA_BYTE_0:
                PointerPlacemnt_RCStatus = eROUTINE_INACTIVE;
                break;
            case DATA_BYTE_1:
                PointerPlacemnt_RCStatus = eROUTINE_INPROGRESS;
                break;
            case DATA_BYTE_2:
                PointerPlacemnt_RCStatus = eROUTINE_FINISH_OK;
                break;
            case DATA_BYTE_3:
                PointerPlacemnt_RCStatus = eROUTINE_FINISH_NOK;
                break;
            default:
                // do nothing
                break;
            }
            Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(POINTER_PLACEMENT, PointerPlacemnt_RCStatus);
        }
        else
        {
            // do nothing
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef POINTER_POSITION_READ
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Position_Read
**
** Visibility       :  Public
**
** Description      :  service to read the pointer placement position for stepper motor
**
** Invocation       :  MeetMgr.diagcdd,	Function:Read_Diag_FA19
**
** Inputs           :  Data[out]: Pointer placement of each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Placement_Position_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

        #ifdef cSpeedo_GaugeID
        Speedo_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[0], DATA_LEN_1);
        #else
        Data[0] = 0U;
        Data[1] = 0U;
        #endif

        #ifdef cTacho_GaugeID
        Tacho_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[2], DATA_LEN_1);
        #else
        Data[2] = 0U;
        Data[3] = 0U;
        #endif

        #ifdef cFuel_GaugeID
        Fuel_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[4], DATA_LEN_1);
        #else
        Data[4] = 0U;
        Data[5] = 0U;
        #endif

        #ifdef cEngineTemp_GaugeID
        EngTemp_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[6], DATA_LEN_1);
        #else
        Data[6] = 0U;
        Data[7] = 0U;
        #endif

        #ifdef cOilPressure_GaugeID
        OilPrs_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[8], DATA_LEN_1);
        #else
        Data[8] = 0U;
        Data[9] = 0U;
        #endif

        #ifdef cTransTemp_GaugeID
        TransTemp_PointerPlacementPosition.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[10], DATA_LEN_1);
        #else
        Data[10] = 0U;
        Data[11] = 0U;
        #endif

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Position_Write
**
** Visibility       :  Public
**
** Description      :   Service to write the stepper motors to a position for pointer insertion
**
** Invocation       :  MeetMgr.diagcdd,	Function:Write_Diag_FA19
**
** Inputs           :  Data[in]: Pointer placement of each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Placement_Position_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                #ifdef cSpeedo_GaugeID
                Manuf_FillResBufferU8toU16(&Data[0], buf, DATA_LEN_1);
                Speedo_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[0] = 0U;
                Data[1] = 0U;
                #endif

                #ifdef cTacho_GaugeID
                Manuf_FillResBufferU8toU16(&Data[2], buf, DATA_LEN_1);
                Tacho_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[2] = 0U;
                Data[3] = 0U;
                #endif

                #ifdef cFuel_GaugeID
                Manuf_FillResBufferU8toU16(&Data[4], buf, DATA_LEN_1);
                Fuel_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[4] = 0U;
                Data[5] = 0U;
                #endif

                #ifdef cEngineTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[6], buf, DATA_LEN_1);
                EngTemp_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[6] = 0U;
                Data[7] = 0U;
                #endif

                #ifdef cOilPressure_GaugeID
                Manuf_FillResBufferU8toU16(&Data[8], buf, DATA_LEN_1);
                OilPrs_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[8] = 0U;
                Data[9] = 0U;
                #endif

                #ifdef cTransTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[10], buf, DATA_LEN_1);
                TransTemp_PointerPlacementPosition.MotorDiag_Write(buf[0]);
                #else
                Data[10] = 0U;
                Data[11] = 0U;
                #endif

                ret = E_OK;

                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef POINTER_AUTHOMODE_READ
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Mode_Authorisation_Read
**
** Visibility       :  Public
**
** Description      :  service to read Pointer placement mode authorisation
**
** Invocation       :  MeetMgr.diagcdd,	Function:Read_Diag_FA1A
**
** Inputs           :  Data[out]: Pointer placement authorisation mode value (0 - default ; 1- PPMA mode is set)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Pointer_Placement_Mode_Authorisation_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        PointerPlacementModeAutho.MotorDiag_Read(&Data[0]);
        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Placement_Mode_Authorisation_Write
**
** Visibility       :  Public
**
** Description      :  service to write Pointer placement mode authorisation
**
** Invocation       :  MeetMgr.diagcdd,	Function:Write_Diag_FA1A
**
** Inputs           :  Data[in]: Pointer placement authorisation mode value (0 - default ; 1- PPMA mode is set)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Placement_Mode_Authorisation_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                PointerPlacementModeAutho.MotorDiag_Write(Data[0]);
                ret = E_OK;

                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SFD_ROC_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStart
**
** Visibility       :  Public
**
** Description      :  Service allows to initialize and launch the process for auto flip detection in stepper motors.
**					   It returns the flip position for each motor, and used to calculate the rotor offset calibration values.
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_START_Diag_F122
**
** Inputs           :  Data[out]: Flip position values
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        if (SFDROC_RCStatus != eROUTINE_INPROGRESS)
        {
            SFDROC_ret = SFDROC_Calib.MotorDiag_RCStart(Data, ErrorCode);
            if (SFDROC_ret == E_OK)
            {
                SFDROC_RCStatus = eROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SFD_ROC_CALIB, SFDROC_RCStatus);
                ret = E_OK;
            }
            else /*Never happens*/
            {
                SFDROC_RCStatus = eROUTINE_FINISH_NOK;
                Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SFD_ROC_CALIB, SFDROC_RCStatus);
            }
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT; /*Already Routine in progress*/
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Motordiag_StepperFlipDetectionforRotorOffsetCalibration_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /* This service is not required */
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStatus
**
** Visibility       :  Public
**
** Description      :  service to get the status the SFD ROC process
**
** Invocation       :  MeetMgr.diagcdd,	Function:RC_RESULTS_Diag_F122
**
** Inputs           :  Data[out]: Flip position values
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        SFDROC_ret = SFDROC_Calib.MotorDiag_RCResult(Data, ErrorCode);
        ret = E_OK;
        if (SFDROC_ret == E_OK)
        {
            SFDROC_RCStatus = eROUTINE_FINISH_OK;
        }
        else
        {
            SFDROC_RCStatus = eROUTINE_FINISH_NOK;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef SELFTEST_GAUGES
/*=====================================================================================================================
**
** Function Name    :  Motordiag_SelftestStepperStallDetectionRoutine_RCStart
**
** Visibility       :  Public
**
** Description      :  service to start the stepper stall detection routine
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[out]: Stepper motor id,	  position X in 100th degree
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SelfTestStprStallDetect.MotorDiag_RCStart(Data, ErrorCode);
        if (ret == E_OK)
        {
            SelfTest_RCStatus = eROUTINE_INPROGRESS;
        }
        else
        {
            SelfTest_RCStatus = eROUTINE_FINISH_NOK;
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SELFTEST_STEPPER_GAUGES, SelfTest_RCStatus);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

// Not implemented
Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_SelftestStepperStallDetectionRoutine_RCStatus
**
** Visibility       :  Public
**
** Description      :  service to get the status of stepper stall detection routine
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[out]: Stepper motor id
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SelfTestStprStallDetect.MotorDiag_RCResult(Data, ErrorCode);
        if (ret == E_OK)
        {
            SelfTest_RCStatus = eROUTINE_FINISH_OK;
        }
        else
        {
            SelfTest_RCStatus = eROUTINE_FINISH_NOK;
        }
        Data[DATA_BYTE_0] = RoutineCtrlStatusUpdate(SELFTEST_STEPPER_GAUGES, SelfTest_RCStatus);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef MMOS_CALIB_READ
/*=====================================================================================================================
**
** Function Name    :  Motordiag_MMOS_Calibration_Read
**
** Visibility       :  Public
**
** Description      :  service to read the magnetic offset of each motor configured
**
** Invocation       :  MeetMgr.diagcdd,	Function:Read_Diag_FA0F
**
** Inputs           :  Data[out]:the magnetic offset for each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_MMOS_Calibration_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {

        #ifdef cSpeedo_GaugeID
        SpeedoMMOS.MotorDiag_Read(&Data[0]);
        #else
        Data[0] = 0;
        #endif

        #ifdef cTacho_GaugeID
        TachoMMOS.MotorDiag_Read(&Data[1]);
        #else
        Data[1] = 0;
        #endif

        #ifdef cFuel_GaugeID
        FuelMMOS.MotorDiag_Read(&Data[2]);
        #else
        Data[2] = 0;
        #endif

        #ifdef cEngineTemp_GaugeID
        EngTempMMOS.MotorDiag_Read(&Data[3]);
        #else
        Data[3] = 0;
        #endif

        #ifdef cOilPressure_GaugeID
        OilPresureMMOS.MotorDiag_Read(&Data[4]);
        #else
        Data[4] = 0;
        #endif

        #ifdef cTransTemp_GaugeID
        TransTempMMOS.MotorDiag_Read(&Data[5]);
        #else
        Data[5] = 0;
        #endif

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_MMOS_Calibration_Write
**
** Visibility       :  Public
**
** Description      :  service to write the magnetic offset value for each motor configured
**
** Invocation       :  MeetMgr.diagcdd,	Function:Write_Diag_FA0F
**
** Inputs           :  Data[in]:the magnetic offset for each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_MMOS_Calibration_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                #ifdef cSpeedo_GaugeID
                SpeedoMMOS.MotorDiag_Write(Data[0]);
                #else
                Data[0] = 0;
                #endif

                #ifdef cTacho_GaugeID
                TachoMMOS.MotorDiag_Write(Data[1]);
                #else
                Data[1] = 0;
                #endif

                #ifdef cFuel_GaugeID
                FuelMMOS.MotorDiag_Write(Data[2]);
                #else
                Data[2] = 0;
                #endif

                #ifdef cEngineTemp_GaugeID
                EngTempMMOS.MotorDiag_Write(Data[3]);
                #else
                Data[3] = 0;
                #endif

                #ifdef cOilPressure_GaugeID
                OilPresureMMOS.MotorDiag_Write(Data[4]);
                #else
                Data[4] = 0;
                #endif

                #ifdef cTransTemp_GaugeID
                TransTempMMOS.MotorDiag_Write(Data[5]);
                #else
                Data[5] = 0;
                #endif

                ret = E_OK;

                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ZERO_POINT_POSITION_READ
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Read
**
** Visibility       :  Public
**
** Description      :  service to read the starting point of the dial in unit for stepper motor.
**					   The zero angle (Point 0) is measured (in 1/100 degree) from mechanical stop to the starting point of the graduation.
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA27
**
** Inputs           :  Data[out]: contains the starting point of each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifdef cSpeedo_GaugeID
        SpeedoMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[0], DATA_LEN_1);
        #endif

        #ifdef cTacho_GaugeID
        TachoMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[2], DATA_LEN_1);
        #endif

        #ifdef cFuel_GaugeID
        FuelMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[4], DATA_LEN_1);
        #endif

        #ifdef cEngineTemp_GaugeID
        EngTempMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[6], DATA_LEN_1);
        #endif

        #ifdef cOilPressure_GaugeID
        OilPrsMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[8], DATA_LEN_1);
        #endif

        #ifdef cTransTemp_GaugeID
        TransTMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[10], DATA_LEN_1);
        #endif

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Write
**
** Visibility       :  Public
**
** Description      :  service to write the starting point of the dial in unit for stepper motor.
**					   The zero angle (Point 0) is measured (in 1/100 degree) from mechanical stop to the starting point of the graduation.
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA27
**
** Inputs           :  Data[in]: contains the starting point of each stepper motor
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                #ifdef cSpeedo_GaugeID
                Manuf_FillResBufferU8toU16(&Data[0], buf, DATA_LEN_1);
                SpeedoMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                #ifdef cTacho_GaugeID
                Manuf_FillResBufferU8toU16(&Data[2], buf, DATA_LEN_1);
                TachoMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                #ifdef cFuel_GaugeID
                Manuf_FillResBufferU8toU16(&Data[4], buf, DATA_LEN_1);
                FuelMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                #ifdef cEngineTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[6], buf, DATA_LEN_1);
                EngTempMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                #ifdef cOilPressure_GaugeID
                Manuf_FillResBufferU8toU16(&Data[8], buf, DATA_LEN_1);
                OilPrsMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                #ifdef cTransTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[10], buf, DATA_LEN_1);
                TransTMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                #endif

                NVMWriteReq = TRUE;
                ret = DCM_E_PENDING;
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SWZERO_SCALE_PARAMETERS
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Read
**
** Visibility       :  Public
**
** Description      :  service to put all pointer to SW zero position
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2F
**
** Inputs           :  Data[Out]:Software zero scale parameter value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        #ifdef cSpeedo_GaugeID
        SpeedoSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[0], DATA_LEN_1);
        #endif
        #ifdef cTacho_GaugeID
        TachoSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[2], DATA_LEN_1);
        #endif
        #ifdef cFuel_GaugeID
        FuelSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[4], DATA_LEN_1);
        #endif
        #ifdef cEngineTemp_GaugeID
        EngSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[6], DATA_LEN_1);
        #endif
        #ifdef cOilPressure_GaugeID
        OilPrsSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[8], DATA_LEN_1);
        #endif
        #ifdef cTransTemp_GaugeID
        TransTempSWZero.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, &Data[10], DATA_LEN_1);
        #endif

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Write
**
** Visibility       :  Public
**
** Description      :  service to put all pointer to SW zero position
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2F
**
** Inputs           :  Data[in]:Software zero scale parameter value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};
    Std_ReturnType ret = E_NOT_OK;

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                #ifdef cSpeedo_GaugeID
                Manuf_FillResBufferU8toU16(&Data[0], buf, DATA_LEN_1);
                SpeedoSWZero.MotorDiag_Write(buf[0]);
                #endif

                #ifdef cTacho_GaugeID
                Manuf_FillResBufferU8toU16(&Data[2], buf, DATA_LEN_1);
                TachoSWZero.MotorDiag_Write(buf[0]);
                #endif

                #ifdef cFuel_GaugeID
                Manuf_FillResBufferU8toU16(&Data[4], buf, DATA_LEN_1);
                FuelSWZero.MotorDiag_Write(buf[0]);
                #endif

                #ifdef cEngineTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[6], buf, DATA_LEN_1);
                EngSWZero.MotorDiag_Write(buf[0]);
                #endif

                #ifdef cOilPressure_GaugeID
                Manuf_FillResBufferU8toU16(&Data[8], buf, DATA_LEN_1);
                OilPrsSWZero.MotorDiag_Write(buf[0]);
                #endif

                #ifdef cTransTemp_GaugeID
                Manuf_FillResBufferU8toU16(&Data[10], buf, DATA_LEN_1);
                TransTempSWZero.MotorDiag_Write(buf[0]);
                #endif

                NVMWriteReq = TRUE;
                ret = DCM_E_PENDING;
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SPEEDO_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Speedo mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA20
**
** Inputs           :  Data[Out]:X axis position points of Speedo mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SpeedoMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of Speedo mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA20
**
** Inputs           :  Data[In]:X axis position points of Speedo mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = SpeedoMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TACHO_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Tacho mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA21
**
** Inputs           :  Data[Out]:X axis position points of Tacho mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TachoMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of Tacho mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA21
**
** Inputs           :  Data[In]:X axis position points of Tacho mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TachoMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef FUEL_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Fuel gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA22
**
** Inputs           :  Data[Out]:X axis position points of Fuel gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = FuelMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of Fuel gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA22
**
** Inputs           :  Data[In]:X axis position points of Fuel gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = FuelMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ENGTEMP_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Engine temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA23
**
** Inputs           :  Data[Out]:X axis position points of Engine temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = EngTempMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of engine temperature gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA23
**
** Inputs           :  Data[In]:X axis position points of Engine temperature gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = EngTempMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SPEEDO_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of Speedo mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA24
**
** Inputs           :  Data[Out]:Y axis position points of Speedo mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SpeedoMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of Speedo mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA24
**
** Inputs           :  Data[In]:Y axis position points of Speedo mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = SpeedoMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TACHO_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of Tacho mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA25
**
** Inputs           :  Data[Out]:Y axis position points of Tacho mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TachoMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of Tacho mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA25
**
** Inputs           :  Data[In]:Y axis position points of Tacho mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TachoMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef FUEL_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of Fuel gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA26
**
** Inputs           :  Data[Out]:Y axis position points of Fuel gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = FuelMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of Fuel gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA26
**
** Inputs           :  Data[In]:Y axis position points of Fuel gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = FuelMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ENGTEMP_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of Engine temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4A
**
** Inputs           :  Data[Out]:Y axis position points of Engine temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = EngTempMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of Engine temperature gauge mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4A
**
** Inputs           :  Data[In]:Y axis position points of Engine temperature gauge mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = EngTempMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SPEEDO_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of Speedo correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2C
**
** Inputs           :  Data[Out]:X axis calibration points of Speedo correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SpeedoCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Speedo correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2C
**
** Inputs           :  Data[In]:X axis calibration points of Speedo correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = SpeedoCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TACHO_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of Tacho correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2D
**
** Inputs           :  Data[Out]:X axis calibration points of Tacho correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TachoCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Tacho correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2D
**
** Inputs           :  Data[In]:X axis calibration points of Tacho correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TachoCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef FUEL_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of Fuel gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2E
**
** Inputs           :  Data[Out]:X axis calibration points of Fuel gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = FuelCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Fuel gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2E
**
** Inputs           :  Data[In]:X axis calibration points of Fuel gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = FuelCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ENGTEMP_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of Engine temperature gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4B
**
** Inputs           :  Data[Out]:X axis calibration points of Engine temperature gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = EngTempCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Engine temperature gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4B
**
** Inputs           :  Data[In]:X axis calibration points of Engine temperature gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = EngTempCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef SPEEDO_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Speedo correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA28
**
** Inputs           :  Data[Out]:Y axis calibration points of Speedo correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = SpeedoCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Speedo_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of Speedo correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA28
**
** Inputs           :  Data[In]:Y axis calibration points of Speedo correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = SpeedoCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TACHO_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Tacho correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA29
**
** Inputs           :  Data[Out]:Y axis calibration points of Tacho correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TachoCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Tacho_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of Tacho correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA29
**
** Inputs           :  Data[In]:Y axis calibration points of Tacho correction table
**					   Errorcode:to be updated with error code if any
**
** Inputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TachoCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef FUEL_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Fuel gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2A
**
** Inputs           :  Data[Out]:Y axis calibration points of Fuel gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = FuelCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Fuel_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of Fuel gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2A
**
** Inputs           :  Data[In]:Y axis calibration points of Fuel gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = FuelCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef ENGTEMP_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Engine temperature gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA2B
**
** Inputs           :  Data[Out]:Y axis calibration points of Engine temperature gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = EngTempCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Motordiag_EngTemp_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of Engine temperature gauge correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA2B
**
** Inputs           :  Data[In]:Y axis calibration points of Engine temperature gauge correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = EngTempCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef OILPRS_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Oil pressure mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4E
**
** Inputs           :  Data[Out]:X axis position points of Oil pressure mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OilPrsMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of Oil pressure mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4E
**
** Inputs           :  Data[In]:X axis position points of Oil pressure mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = OilPrsMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef OILPRS_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of oil pressure mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA42
**
** Inputs           :  Data[Out]:Y axis position points of oil pressure mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OilPrsMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of oil pressure mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA42
**
** Inputs           :  Data[In]:Y axis position points of oil pressure mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = OilPrsMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef OILPRS_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of oil pressure correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4D
**
** Inputs           :  Data[Out]:X axis calibration points of oil pressure correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OilPrsCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Speedo correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4D
**
** Inputs           :  Data[In]:X axis calibration points of Speedo correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = OilPrsCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef OILPRS_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Oil pressure correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4F
**
** Inputs           :  Data[Out]:Y axis calibration points of oil pressure correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = OilPrsCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_OilPressure_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of oil pressure correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4F
**
** Inputs           :  Data[In]:Y axis calibration points of oil pressure correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = OilPrsCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TRANSTEMP_MAPTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis position points of Trans Temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4B
**
** Inputs           :  Data[Out]:X axis position points of Trans Temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TransTMpgTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Write
**
** Visibility       :  Public
**
** Description      :  writes the X axis position points of Trans Temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4B
**
** Inputs           :  Data[In]:X axis position points of Trans Temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TransTMpgTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
                else
                {
                    // do nothing
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                else
                {
                    // do nothing
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TRANSTEMP_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Read
**
** Visibility       :  Public
**
** Description      :  reads the Y axis position points of Trans Temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA4C
**
** Inputs           :  Data[Out]:Y axis position points of Trans Temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TransTMpgTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_POSITION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Write
**
** Visibility       :  Public
**
** Description      :  writes the Y axis position points of Trans Temperature mapping table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA4C
**
** Inputs           :  Data[In]:Y axis position points of Trans Temperature mapping table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TransTMpgTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TRANSTEMP_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibration_X_Read
**
** Visibility       :  Public
**
** Description      :  reads the X axis calibration points of Trans Temperature correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA60
**
** Inputs           :  Data[Out]:X axis calibration points of Trans Temperature correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TransTCrtnTableXConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibration_X_Write
**
** Visibility       :  Public
**
** Description      :  Writes the X axis calibration points of Trans Temperature correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA60
**
** Inputs           :  Data[In]:X axis calibration points of Trans Temperature correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TransTCrtnTableXConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

#ifdef TRANSTEMP_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibration_Y_Read
**
** Visibility       :  Public
**
** Description      :  Reads the Y axis calibration points of Trans Temperature correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Read_Diag_FA61
**
** Inputs           :  Data[Out]:Y axis calibration points of Trans Temperature correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint16 buf[NUM_OF_CALIBRATION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TransTCrtnTableYConfig.MotorDiag_Read(buf);
        Manuf_FillResBufferU16toU8(buf, Data, NUM_OF_CALIBRATION_POINTS);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_TransTemp_PointerGaugeCalibration_Y_Write
**
** Visibility       :  Public
**
** Description      :  Writes the Y axis calibration points of Trans Temperature correction table
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA61
**
** Inputs           :  Data[In]:Y axis calibration points of Trans Temperature correction table
**					   Errorcode:to be updated with error code if any
**
** Outputs          :   E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode)
{
    uint8 MfgModeActive = 0U;
    Std_ReturnType ret = E_NOT_OK;
    uint8 nvmStatus;
    uint16 buf[NUM_OF_POSITION_POINTS] = {0};

    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        MotorDiagNvmJobResult_U8.MotorDiag_Read(&nvmStatus);
        if (FALSE == NVMWriteReq)
        {
            if (nvmStatus != NVM_REQ_PENDING)
            {
                Manuf_FillResBufferU8toU16(Data, buf, NUM_OF_POSITION_POINTS);
                ret = TransTCrtnTableYConfig.MotorDiag_Write(buf, ErrorCode);
                if (ret == E_OK)
                {
                    NVMWriteReq = TRUE;
                    ret = DCM_E_PENDING;
                }
            }
        }
        else
        {
            if (nvmStatus == NVM_REQ_PENDING)
            {
                ret = DCM_E_PENDING;
            }
            else
            {
                ret = E_NOT_OK;
                if (nvmStatus == NVM_REQ_OK)
                {
                    ret = E_OK;
                }
                NVMWriteReq = FALSE;
                nvmStatus = 0;
                /*clear NVM Jobresult*/
                MotorDiagNvmJobResult_U8.MotorDiag_Write(nvmStatus);
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
#endif

/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and error code update for MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/5/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1326853
** Change Description:  Updated SFD ROC and High calibration routine
**====================================================================================================================*/

/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1262477
** Change Description:  Updated pointer placement routine, SFD ROC, High calibration routine
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : dkasiman
** Traceability      : RTC-1208647
** Change Description: cEngTemp_GaugeID has been renamed to cEngineTemp_GaugeID,SELFTEST_GAUGES macro renamed as
                       SELFTEST_STEPPER_GAUGES return variable updated in Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStatus
                       function.
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 10/Aug/2018
** CDSID             : dkasiman
** Traceability      : RTC-1144520
** Change Description: Compiler warnings fix occurs while less motors are configured.
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 09/Aug/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520
** Change Description: Review comments fixed - Added motor specific macro protection for the continuous pointer movement routine
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 20/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520
** Change Description: Review comments fixed
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 17/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Added Continuous Pointer Movement Service ($F112)
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 13/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Review comments fixed
**=======================================================================================================================*/
/*=====================================================================================================================
** Date              : 03/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Initial version for MeetCdd bookshelf.
**====================================================================================================================*/

#endif
