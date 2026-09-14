/*===================================================================================================================
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
**===================================================================================================================
**
** Name:           Motordiagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef MOTORDIAGCDD_H
#define MOTORDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Motordiagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define MANUF_SHIFT8BITS                8U
#define MANUF_LOWBYTEMASK               (0x00FFU)
#define MANUF_HIGHBYTEMASK              (0xFF00U)

#ifdef CONTINOUS_POINTER_MOVEMENT

#define MANUF_OK            (0U)
#define MANUF_FAIL          (1U)
#define MANUF_FALSE         (0U)
#define MANUF_TRUE          (1U)

#define MANUF_STPRCMD_START         ((uint8)(0))
#define MANUF_STPRCMD_STOP          ((uint8)(1))
#define MANUF_STPRCMD_GETRESULTS    ((uint8)(2))

#define CHECK_INITIAL_POSITION      ((uint8)(0))
#define CHECK_STEADY_POSITION       ((uint8)(1))
#define MOTION_A_TO_B               ((uint8)(2))
#define MOTION_B_TO_A               ((uint8)(3))
#define SWITCH_BTW_POSITION         ((uint8)(4))
#define ROTATION_COUNT_LIMIT        ((uint8)(5))
#define TASK_TIME                   ((uint8)(5))
#define HALF_CYCLE_TIME             ((uint8)(2))

#endif

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
#ifdef CONTINOUS_POINTER_MOVEMENT
typedef struct sManuf_RoutineSts
{
    uint8 StprReading;
} sManuf_StprRoutineSts;

typedef struct Stpr_Continuous_PointerMovement
{
    uint16 TimerCounter;
    uint8 StateId;
    uint8 StepperState;
    uint8 StepperID;
    uint8 ReMap_StepperID;
    uint16 Position_A;
    uint16 Position_B;
    uint16 PositioninDegree;
    uint16 ReachedPosition;
    uint16 Time;
    uint8 Onetimeaction;
} StprContPointMovement;
#endif

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
#ifdef ORDER_IN_USTEPS_OR_DEG
Std_ReturnType Motordiag_Order_In_Microsteps_Or_Degrees_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Order_In_Microsteps_Or_Degrees_RCTE(uint8 *ErrorCode);
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
Std_ReturnType Motordiag_Order_In_Vehicle_Unit_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Order_In_Vehicle_Unit_RCTE(uint8 *ErrorCode);
#endif
#ifdef HIGH_CALIBRATION_CONTROL
Std_ReturnType Motordiag_High_Calibration_Control_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_High_Calibration_Control_RCStop(uint8 *Data, uint8 *ErrorCode); /* This service is not required */
Std_ReturnType Motordiag_High_Calibration_Control_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef HIGH_IMPEDANCE
Std_ReturnType Motordiag_High_Impedance_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_High_Impedance_RCTE(uint8 *ErrorCode);
#endif

#ifdef LOW_TORQUE
Std_ReturnType Motordiag_Low_Torque_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Low_Torque_RCTE(uint8 *ErrorCode);
#endif
#ifdef JUMP_IN_USTEPS
Std_ReturnType Motordiag_Jump_In_Microsteps_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Jump_In_Microsteps_RCTE(uint8 *ErrorCode);
#endif

#ifdef READ_MOTOR_POSITION
Std_ReturnType Motordiag_MotorPosition_Reached_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef CONTINOUS_POINTER_MOVEMENT
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Continuous_Pointer_Movement_RCStatus(uint8 *Data, uint8 *ErrorCode);
void Stpr_Periodic_Function(void);
#endif
// not implemented - Service specific to HUD
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_ContinuousMotorMovement_RCStatus(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_ReadMotorSpeed_Read(uint8 *Data, uint8 *ErrorCode);
// not implemented - The implementation is not available in the stepper motor module
Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_SelftestStepperStallDetectionRoutine_RCStatus(uint8 *Data, uint8 *ErrorCode);

#ifdef POINTER_PLACEMENT_ROUTINE
Std_ReturnType Motordiag_Pointer_Placement_Routine_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_PointerPlacementRoutine_RCStop(uint8 *Data, uint8 *ErrorCode); /* This service is not required */
Std_ReturnType Motordiag_Pointer_Placement_Routine_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef POINTER_POSITION_READ
Std_ReturnType Motordiag_Pointer_Placement_Position_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Pointer_Placement_Position_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef POINTER_AUTHOMODE_READ
Std_ReturnType Motordiag_Pointer_Placement_Mode_Authorisation_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Pointer_Placement_Mode_Authorisation_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SFD_ROC_ROUTINE
Std_ReturnType Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_StepperFlipDetectionforRotorOffsetCalibration_RCStop(uint8 *Data, uint8 *ErrorCode); /* This service is not required */
Std_ReturnType Motordiag_Stepper_Flip_Detection_for_Rotor_Offset_Calibration_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef MMOS_CALIB_READ
Std_ReturnType Motordiag_MMOS_Calibration_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_MMOS_Calibration_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef ZERO_POINT_POSITION_READ
Std_ReturnType Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Pointer_Gauge_Calibration_Zero_Point_Position_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SWZERO_SCALE_PARAMETERS
Std_ReturnType Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Pointer_Gauge_Calibration_SWZero_ScaleParameter_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_MAPTABLE_X
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TACHO_MAPTABLE_X
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef FUEL_MAPTABLE_X
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_MAPTABLE_X
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_MAPTABLE_Y
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TACHO_MAPTABLE_Y
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef FUEL_MAPTABLE_Y
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_MAPTABLE_Y
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_CRTNTABLE_X
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TACHO_CRTNTABLE_X
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef FUEL_CRTNTABLE_X
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_CRTNTABLE_X
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_CRTNTABLE_Y
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Speedo_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TACHO_CRTNTABLE_Y
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Tacho_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef FUEL_CRTNTABLE_Y
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_Fuel_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_CRTNTABLE_Y
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_EngTemp_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef OILPRS_MAPTABLE_X
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef OILPRS_MAPTABLE_Y
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef OILPRS_CRTNTABLE_X
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef OILPRS_CRTNTABLE_Y
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_OilPressure_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_MAPTABLE_X
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_X_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_X_Write(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_Y_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Motordiag_TransTemp_PointerGaugeCalibration_Y_Write(uint8 *Data, uint8 *ErrorCode);
#endif
/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 20/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
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
/*======================================================================================================================
** Date              : 03/Jul/2018
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Initial verion for MeetCdd bookshelf.
**=======================================================================================================================*/

#endif
