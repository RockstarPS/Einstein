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
** Name:           Ioctrlrd_dio_diagcdd
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef MOTORDIAGCDD_CFG_C
#define MOTORDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Motordiagcdd_cfg.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/


/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#if defined(SPEEDO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_SpeedoMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_SpeedoMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#if defined(TACHO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_TachoMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TachoMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#if defined(FUEL_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_FuelMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_FuelMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#if defined(ENGTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_EngTempMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_EngTempMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#if defined(OILPRS_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_OilPrsMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_OilPrsMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#if defined(TRANSTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
static Std_ReturnType MotorDiag_TransTempMpgTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TransTempMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_MAPTABLE_Y
static Std_ReturnType MotorDiag_SpeedoMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_SpeedoMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TACHO_MAPTABLE_Y
static Std_ReturnType MotorDiag_TachoMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TachoMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef FUEL_MAPTABLE_Y
static Std_ReturnType MotorDiag_FuelMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_FuelMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_MAPTABLE_Y
static Std_ReturnType MotorDiag_EngTempMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_EngTempMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef OILPRS_MAPTABLE_Y
static Std_ReturnType MotorDiag_OilPrsMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_OilPrsMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
static Std_ReturnType MotorDiag_TransTempMpgTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TransTempMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_CRTNTABLE_X
static Std_ReturnType MotorDiag_SpeedoCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_SpeedoCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TACHO_CRTNTABLE_X
static Std_ReturnType MotorDiag_TachoCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TachoCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef FUEL_CRTNTABLE_X
static Std_ReturnType MotorDiag_FuelCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_FuelCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_CRTNTABLE_X
static Std_ReturnType MotorDiag_EngTempCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_EngTempCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef OILPRS_CRTNTABLE_X
static Std_ReturnType MotorDiag_OilPrsCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_OilPrsCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
static Std_ReturnType MotorDiag_TransTempCrtnTableX_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TransTempCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef SPEEDO_CRTNTABLE_Y
static Std_ReturnType MotorDiag_SpeedoCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_SpeedoCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TACHO_CRTNTABLE_Y
static Std_ReturnType MotorDiag_TachoCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TachoCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef FUEL_CRTNTABLE_Y
static Std_ReturnType MotorDiag_FuelCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_FuelCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef ENGTEMP_CRTNTABLE_Y
static Std_ReturnType MotorDiag_EngTempCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_EngTempCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef OILPRS_CRTNTABLE_Y
static Std_ReturnType MotorDiag_OilPrsCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_OilPrsCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
static Std_ReturnType MotorDiag_TransTempCrtnTableY_Read(uint16 *Buffer);
static Std_ReturnType MotorDiag_TransTempCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode);
#endif
#ifdef READ_MOTOR_POSITION
static void MotorDiag_MotorPosRchd_Read(uint8 *Data);
#endif
#ifdef JUMP_IN_USTEPS
static Std_ReturnType MotorDiag_Jump_In_Microsteps_STA(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType MotorDiag_Jump_In_Microsteps_RCTE(uint8 *ErrorCode);
#endif
#ifdef ORDER_IN_USTEPS_OR_DEG
static Std_ReturnType Motordiag_Order_In_MicrostepsorDegrees_STA(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType Motordiag_Order_In_MicrostepsorDegrees_RCTE(uint8 *ErrorCode);
#endif
#ifdef HIGH_IMPEDANCE
static Std_ReturnType HighImpedance_STA(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType HighImpedance_RCTE(uint8 *ErrorCode);
#endif
#ifdef LOW_TORQUE
static Std_ReturnType LowTorque_STA(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType LowTorque_RCTE(uint8 *ErrorCode);
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
#ifdef cSpeedo_GaugeID
static void SpeedoGaugeControl_Val(uint16 Data);
static void SpeedoGaugeControl_Req(uint16 Data);
#endif
#ifdef cTacho_GaugeID
static void TachoGaugeControl_Val(uint16 Data);
static void TachoGaugeControl_Req(uint16 Data);
#endif
#ifdef cFuel_GaugeID
static void FuelGaugeControl_Val(uint16 Data);
static void FuelGaugeControl_Req(uint16 Data);
#endif
#ifdef cEngineTemp_GaugeID
static void EctGaugeControl_Val(uint16 Data);
static void EctGaugeControl_Req(uint16 Data);
#endif
#ifdef cOilPressure_GaugeID
static void OilPrsGaugeControl_Val(uint16 Data);
static void OilPrsGaugeControl_Req(uint16 Data);
#endif
#ifdef cTransTemp_GaugeID
static void TransTempGaugeControl_Val(uint16 Data);
static void TransTempGaugeControl_Req(uint16 Data);
#endif
#endif
#ifdef HIGH_CALIBRATION_CONTROL
static Std_ReturnType HighCalib_Start(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType HighCalib_Stop(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType HighCalib_Result(uint8 *Data, uint8 *ErrorCode );
#endif
#ifdef POINTER_PLACEMENT_ROUTINE
static Std_ReturnType PointerPlacement_Start(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType PointerPlacement_Stop(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType PointerPlacement_Result(uint8 *Data, uint8 *ErrorCode );
#endif
#ifdef SFD_ROC_ROUTINE
static Std_ReturnType SFDROC_Calib_Start(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType SFDROC_Calib_Stop(uint8 *Data, uint8 *ErrorCode );
static Std_ReturnType SFDROC_Calib_Result(uint8 *Data, uint8 *ErrorCode );
#endif
#ifdef POINTER_AUTHOMODE_READ
static void MotorDiag_PPMA_Read(uint8 *Data);
static void MotorDiag_PPMA_Write(uint8 Data);
#endif
#ifdef MMOS_CALIB_READ
#ifdef cSpeedo_GaugeID
static void Speedo_MMOS_Read(uint8 *Data);
static void Speedo_MMOS_Write(uint8 Data);
#endif
#ifdef cTacho_GaugeID
static void Tacho_MMOS_Read(uint8 *Data);
static void Tacho_MMOS_Write(uint8 Data);
#endif
#ifdef cFuel_GaugeID
static void Fuel_MMOS_Read(uint8 *Data);
static void Fuel_MMOS_Write(uint8 Data);
#endif
#ifdef cEngineTemp_GaugeID
static void EngTemp_MMOS_Read(uint8 *Data);
static void EngTemp_MMOS_Write(uint8 Data);
#endif
#ifdef cOilPressure_GaugeID
static void OilPrs_MMOS_Read(uint8 *Data);
static void OilPrs_MMOS_Write(uint8 Data);
#endif
#ifdef cTransTemp_GaugeID
static void TransTemp_MMOS_Read(uint8 *Data);
static void TransTemp_MMOS_Write(uint8 Data);
#endif
#endif
#ifdef POINTER_POSITION_READ
#ifdef cSpeedo_GaugeID
static void MotorDiag_SpeedoPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_SpeedoPointerPlacmnt_Write(uint16 Data);
#endif
#ifdef cTacho_GaugeID
static void MotorDiag_TachoPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_TachoPointerPlacmnt_Write(uint16 Data);
#endif
#ifdef cFuel_GaugeID
static void MotorDiag_FuelPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_FuelPointerPlacmnt_Write(uint16 Data);
#endif
#ifdef cEngineTemp_GaugeID
static void MotorDiag_EngTempPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_EngTempPointerPlacmnt_Write(uint16 Data);
#endif
#ifdef cOilPressure_GaugeID
static void MotorDiag_OilPrsPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_OilPrsPointerPlacmnt_Write(uint16 Data);
#endif
#ifdef cTransTemp_GaugeID
static void MotorDiag_TransTempPointerPlacmnt_Read(uint16 *Data);
static void MotorDiag_TransTempPointerPlacmnt_Write(uint16 Data);
#endif
#endif
#ifdef SWZERO_SCALE_PARAMETERS
#ifdef cSpeedo_GaugeID
static void MotorDiag_SpeedoSWZeroValue_Read(uint16 *Data);
static void MotorDiag_SpeedoSWZeroValue_Write(uint16 Data);
#endif
#ifdef cTacho_GaugeID
static void MotorDiag_TachoSWZeroValue_Read(uint16 *Data);
static void MotorDiag_TachoSWZeroValue_Write(uint16 Data);
#endif
#ifdef cFuel_GaugeID
static void MotorDiag_FuelSWZeroValue_Read(uint16 *Data);
static void MotorDiag_FuelSWZeroValue_Write(uint16 Data);
#endif
#ifdef cEngineTemp_GaugeID
static void MotorDiag_EngSWZeroValue_Read(uint16 *Data);
static void MotorDiag_EngSWZeroValue_Write(uint16 Data);
#endif
#ifdef cOilPressure_GaugeID
static void MotorDiag_OilPrsSWZeroValue_Read(uint16 *Data);
static void MotorDiag_OilPrsSWZeroValue_Write(uint16 Data);
#endif
#ifdef cTransTemp_GaugeID
static void MotorDiag_TransTSWZeroValue_Read(uint16 *Data);
static void MotorDiag_TransTSWZeroValue_Write(uint16 Data);
#endif
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
static Std_ReturnType MotorDiag_GetCurrentPos_MicroStp_Or_Deg(uint8 Index,uint16 *Position);
static Std_ReturnType MotorDiag_SetPos_MicroStp_Or_Deg(uint8 Index,uint16 *Position);
static Std_ReturnType MotorDiag_SetPos_MicroStp_Or_DegEx(uint8 Index,uint16 *Position, uint16 *Time);
static Std_ReturnType MotorDiag_Get_Stepper_Status(uint8 Index, uint8 *ErrorCode );
#endif
#ifdef SELFTEST_GAUGES
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
//NVM job status Read and Write
static void MotorDiag_Nvm_JobResult_Read(uint8* JobStatus);
static void MotorDiag_Nvm_JobResult_Write(uint8 JobStatus);
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef CONTINOUS_POINTER_MOVEMENT
/*Provide the StepperMotors configured in the ascending order.*/
/*Speedo= 80, Tacho= 81, Fuel= 82, EngineTemp= 83, OilPressure= 84, TransmissionTemp= 85, AllGauges = 8F*/
/*If the service is to test all the gauges or only one gauge, define NUMBER_OF_MOTORS and the respective gauge ID in the array*/
//const uint8 Valid_StepperMotorID[NUMBER_OF_MOTORS]={80,81,82,83,84,85}; 
const uint8 Valid_StepperMotorID[NUMBER_OF_MOTORS]={80,81,82}; 
#endif
#if defined(SPEEDO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 SpeedoMpgTableXConfig=
{
	&MotorDiag_SpeedoMpgTableX_Read,&MotorDiag_SpeedoMpgTableX_Write,
};
#endif
#if defined(TACHO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 TachoMpgTableXConfig=
{
	&MotorDiag_TachoMpgTableX_Read,&MotorDiag_TachoMpgTableX_Write,
};
#endif
#if defined(FUEL_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 FuelMpgTableXConfig=
{
	&MotorDiag_FuelMpgTableX_Read,&MotorDiag_FuelMpgTableX_Write,
};
#endif
#if defined(ENGTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 EngTempMpgTableXConfig=
{
	&MotorDiag_EngTempMpgTableX_Read,&MotorDiag_EngTempMpgTableX_Write,
};
#endif
#if defined(OILPRS_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 OilPrsMpgTableXConfig=
{
	&MotorDiag_OilPrsMpgTableX_Read,&MotorDiag_OilPrsMpgTableX_Write,
};
#endif
#if defined(TRANSTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
const MotorDiag_TableReadWrite_U16 TransTMpgTableXConfig=
{
	&MotorDiag_TransTempMpgTableX_Read,&MotorDiag_TransTempMpgTableX_Write,
};
#endif
#ifdef SPEEDO_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 SpeedoMpgTableYConfig=
{
	&MotorDiag_SpeedoMpgTableY_Read,&MotorDiag_SpeedoMpgTableY_Write,
};
#endif
#ifdef TACHO_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 TachoMpgTableYConfig=
{
	&MotorDiag_TachoMpgTableY_Read,&MotorDiag_TachoMpgTableY_Write,
};
#endif
#ifdef FUEL_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 FuelMpgTableYConfig=
{
	&MotorDiag_FuelMpgTableY_Read,&MotorDiag_FuelMpgTableY_Write,
};
#endif
#ifdef ENGTEMP_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 EngTempMpgTableYConfig=
{
	&MotorDiag_EngTempMpgTableY_Read,&MotorDiag_EngTempMpgTableY_Write,
};
#endif
#ifdef OILPRS_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 OilPrsMpgTableYConfig=
{
	&MotorDiag_OilPrsMpgTableY_Read,&MotorDiag_OilPrsMpgTableY_Write,
};
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
const MotorDiag_TableReadWrite_U16 TransTMpgTableYConfig=
{
	&MotorDiag_TransTempMpgTableY_Read,&MotorDiag_TransTempMpgTableY_Write,
};
#endif
#ifdef SPEEDO_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 SpeedoCrtnTableXConfig=
{
	&MotorDiag_SpeedoCrtnTableX_Read,&MotorDiag_SpeedoCrtnTableX_Write,
};
#endif
#ifdef TACHO_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 TachoCrtnTableXConfig=
{
	&MotorDiag_TachoCrtnTableX_Read,&MotorDiag_TachoCrtnTableX_Write,
};
#endif
#ifdef FUEL_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 FuelCrtnTableXConfig=
{
	&MotorDiag_FuelCrtnTableX_Read,&MotorDiag_FuelCrtnTableX_Write,
};
#endif
#ifdef ENGTEMP_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 EngTempCrtnTableXConfig=
{
	&MotorDiag_EngTempCrtnTableX_Read,&MotorDiag_EngTempCrtnTableX_Write,
};
#endif
#ifdef OILPRS_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 OilPrsCrtnTableXConfig=
{
	&MotorDiag_OilPrsCrtnTableX_Read,&MotorDiag_OilPrsCrtnTableX_Write,
};
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
const MotorDiag_TableReadWrite_U16 TransTCrtnTableXConfig=
{
	&MotorDiag_TransTempCrtnTableX_Read,&MotorDiag_TransTempCrtnTableX_Write,
};
#endif
#ifdef SPEEDO_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 SpeedoCrtnTableYConfig=
{
	&MotorDiag_SpeedoCrtnTableY_Read,&MotorDiag_SpeedoCrtnTableY_Write,
};
#endif
#ifdef TACHO_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 TachoCrtnTableYConfig=
{
	&MotorDiag_TachoCrtnTableY_Read,&MotorDiag_TachoCrtnTableY_Write,
};
#endif
#ifdef FUEL_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 FuelCrtnTableYConfig=
{
	&MotorDiag_FuelCrtnTableY_Read,&MotorDiag_FuelCrtnTableY_Write,
};

#endif
#ifdef ENGTEMP_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 EngTempCrtnTableYConfig=
{
	&MotorDiag_EngTempCrtnTableY_Read,&MotorDiag_EngTempCrtnTableY_Write,
};
#endif
#ifdef OILPRS_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 OilPrsCrtnTableYConfig=
{
	&MotorDiag_OilPrsCrtnTableY_Read,&MotorDiag_OilPrsCrtnTableY_Write,
};
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
const MotorDiag_TableReadWrite_U16 TransTCrtnTableYConfig=
{
	&MotorDiag_TransTempCrtnTableY_Read,&MotorDiag_TransTempCrtnTableY_Write,
};
#endif
#ifdef READ_MOTOR_POSITION
const MotorDiag_ReadWrite_U8 ReadMotorPosRchd=
{
	&MotorDiag_MotorPosRchd_Read, 
};
#endif
#ifdef JUMP_IN_USTEPS
const MotorDiag_IOCntrl JumpInMicrosteps=
{
	&MotorDiag_Jump_In_Microsteps_STA, &MotorDiag_Jump_In_Microsteps_RCTE,
};
#endif
#ifdef ORDER_IN_USTEPS_OR_DEG
const MotorDiag_IOCntrl OrderInMicrosteps=
{
	&Motordiag_Order_In_MicrostepsorDegrees_STA, &Motordiag_Order_In_MicrostepsorDegrees_RCTE,
};
#endif
#ifdef HIGH_IMPEDANCE
const MotorDiag_IOCntrl HighImpedance=
{
	&HighImpedance_STA, &HighImpedance_RCTE,
};
#endif
#ifdef LOW_TORQUE
const MotorDiag_IOCntrl LowTorque=
{
	&LowTorque_STA, &LowTorque_RCTE,
};
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
#ifdef cSpeedo_GaugeID
const MotorDiag_IOCntrl_U16 SpeedoGaugeControl=
{
	&SpeedoGaugeControl_Val, &SpeedoGaugeControl_Req,
};
#endif
#ifdef cTacho_GaugeID
const MotorDiag_IOCntrl_U16 TachoGaugeControl=
{
	&TachoGaugeControl_Val, &TachoGaugeControl_Req,
};
#endif
#ifdef cFuel_GaugeID
const MotorDiag_IOCntrl_U16 FuelGaugeControl=
{
	&FuelGaugeControl_Val, &FuelGaugeControl_Req,
};
#endif
#ifdef cEngineTemp_GaugeID
const MotorDiag_IOCntrl_U16 EctGaugeControl=
{
	&EctGaugeControl_Val, &EctGaugeControl_Req,
};
#endif
#ifdef cOilPressure_GaugeID
const MotorDiag_IOCntrl_U16 OilPrsGaugeControl=
{
	&OilPrsGaugeControl_Val, &OilPrsGaugeControl_Req,
};
#endif
#ifdef cTransTemp_GaugeID
const MotorDiag_IOCntrl_U16 TransTempGaugeControl=
{
	&TransTempGaugeControl_Val, &TransTempGaugeControl_Req,
};
#endif
#endif
#ifdef HIGH_CALIBRATION_CONTROL
const MotorDiag_ROCntrl HighCalibControl=
{
	&HighCalib_Start, &HighCalib_Stop, &HighCalib_Result
};
#endif
#ifdef POINTER_PLACEMENT_ROUTINE
const MotorDiag_ROCntrl PointerPlacementRoutine=
{
	&PointerPlacement_Start, &PointerPlacement_Stop, &PointerPlacement_Result
};
#endif
#ifdef SFD_ROC_ROUTINE
const MotorDiag_ROCntrl SFDROC_Calib=
{
	&SFDROC_Calib_Start, &SFDROC_Calib_Stop, &SFDROC_Calib_Result
};
#endif
#ifdef POINTER_AUTHOMODE_READ
const MotorDiag_ReadWrite_U8 PointerPlacementModeAutho=
{
	&MotorDiag_PPMA_Read, &MotorDiag_PPMA_Write,
};
#endif
#ifdef MMOS_CALIB_READ
#ifdef cSpeedo_GaugeID
const MotorDiag_ReadWrite_U8 SpeedoMMOS=
{
	&Speedo_MMOS_Read, &Speedo_MMOS_Write,
};
#endif
#ifdef cTacho_GaugeID
const MotorDiag_ReadWrite_U8 TachoMMOS=
{
	&Tacho_MMOS_Read, &Tacho_MMOS_Write,
};
#endif
#ifdef cFuel_GaugeID
const MotorDiag_ReadWrite_U8 FuelMMOS=
{
	&Fuel_MMOS_Read, &Fuel_MMOS_Write,
};
#endif
#ifdef cEngineTemp_GaugeID
const MotorDiag_ReadWrite_U8 EngTempMMOS=
{
	&EngTemp_MMOS_Read, &EngTemp_MMOS_Write,
};
#endif
#ifdef cOilPressure_GaugeID
const MotorDiag_ReadWrite_U8 OilPresureMMOS=
{
	&OilPrs_MMOS_Read, &OilPrs_MMOS_Write,
};
#endif
#ifdef cTransTemp_GaugeID
const MotorDiag_ReadWrite_U8 TransTempMMOS=
{
	&TransTemp_MMOS_Read, &TransTemp_MMOS_Write,
};
#endif
#endif
#ifdef POINTER_POSITION_READ
#ifdef cSpeedo_GaugeID
const MotorDiag_ReadWrite_U16 Speedo_PointerPlacementPosition=
{
	&MotorDiag_SpeedoPointerPlacmnt_Read, &MotorDiag_SpeedoPointerPlacmnt_Write,
};
#endif
#ifdef cTacho_GaugeID
const MotorDiag_ReadWrite_U16 Tacho_PointerPlacementPosition=
{
	&MotorDiag_TachoPointerPlacmnt_Read, &MotorDiag_TachoPointerPlacmnt_Write,
};
#endif
#ifdef cFuel_GaugeID
const MotorDiag_ReadWrite_U16 Fuel_PointerPlacementPosition=
{
	&MotorDiag_FuelPointerPlacmnt_Read, &MotorDiag_FuelPointerPlacmnt_Write,
};
#endif
#ifdef cEngineTemp_GaugeID
const MotorDiag_ReadWrite_U16 EngTemp_PointerPlacementPosition=
{
	&MotorDiag_EngTempPointerPlacmnt_Read, &MotorDiag_EngTempPointerPlacmnt_Write,
};
#endif
#ifdef cOilPressure_GaugeID
const MotorDiag_ReadWrite_U16 OilPrs_PointerPlacementPosition=
{
	&MotorDiag_OilPrsPointerPlacmnt_Read, &MotorDiag_OilPrsPointerPlacmnt_Write,
};
#endif
#ifdef cTransTemp_GaugeID
const MotorDiag_ReadWrite_U16 TransTemp_PointerPlacementPosition=
{
	&MotorDiag_TransTempPointerPlacmnt_Read, &MotorDiag_TransTempPointerPlacmnt_Write,
};
#endif
#endif
#ifdef SWZERO_SCALE_PARAMETERS
#ifdef cSpeedo_GaugeID
const MotorDiag_ReadWrite_U16 SpeedoSWZero=
{
	&MotorDiag_SpeedoSWZeroValue_Read, &MotorDiag_SpeedoSWZeroValue_Write,
};
#endif
#ifdef cTacho_GaugeID
const MotorDiag_ReadWrite_U16 TachoSWZero=
{
	&MotorDiag_TachoSWZeroValue_Read, &MotorDiag_TachoSWZeroValue_Write,
};
#endif
#ifdef cFuel_GaugeID
const MotorDiag_ReadWrite_U16 FuelSWZero=
{
	&MotorDiag_FuelSWZeroValue_Read, &MotorDiag_FuelSWZeroValue_Write,
};
#endif
#ifdef cEngineTemp_GaugeID
const MotorDiag_ReadWrite_U16 EngSWZero=
{
	&MotorDiag_EngSWZeroValue_Read, &MotorDiag_EngSWZeroValue_Write,
};
#endif
#ifdef cOilPressure_GaugeID
const MotorDiag_ReadWrite_U16 OilPrsSWZero=
{
	&MotorDiag_OilPrsSWZeroValue_Read, &MotorDiag_OilPrsSWZeroValue_Write,
};
#endif
#ifdef cTransTemp_GaugeID
const MotorDiag_ReadWrite_U16 TransTempSWZero=
{
	&MotorDiag_TransTSWZeroValue_Read, &MotorDiag_TransTSWZeroValue_Write,
};
#endif
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
const MotorDiag_Continous_Pointer_Movement Continous_Pointer_Movement_RC=
{
	&MotorDiag_GetCurrentPos_MicroStp_Or_Deg, &MotorDiag_SetPos_MicroStp_Or_Deg, &MotorDiag_SetPos_MicroStp_Or_DegEx, &MotorDiag_Get_Stepper_Status,
};
#endif
#ifdef SELFTEST_GAUGES
const MotorDiag_ROCntrl SelfTestStprStallDetect=
{
	&MotorDiag_SelfTestStprStallDetection_RCStart,&MotorDiag_SelfTestStprStallDetection_RCStop,&MotorDiag_SelfTestStprStallDetection_RCStatus,
};
#endif
//Read/Write NVM Job Status
const MotorDiag_ReadWrite_U8 MotorDiagNvmJobResult_U8=
{
	&MotorDiag_Nvm_JobResult_Read,&MotorDiag_Nvm_JobResult_Write,
};
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#if defined(SPEEDO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of speedo mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static Std_ReturnType MotorDiag_SpeedoMpgTableX_Read(uint16 *Buffer)
{
	return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of speedo mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
	return E_OK; /*to be replaced with RTE*/ 
}
#endif
#if defined(TACHO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of tacho mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoMpgTableX_Read(uint16 *Buffer)
{
	return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of tacho mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
	return E_OK; /*to be replaced with RTE*/ 
}
#endif
#if defined(FUEL_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of fuel gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelMpgTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of fuel gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#if defined(ENGTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of Engine temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempMpgTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of Engine temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#if defined(OILPRS_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of oil pressure gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsMpgTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of oil pressure gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#if defined(TRANSTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempMpgTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis position points of trans temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempMpgTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempMpgTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis position points of trans temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_X_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempMpgTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef SPEEDO_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of speedo mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of speedo mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TACHO_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of tacho mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of tacho mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef FUEL_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of fuel gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of fuel gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef ENGTEMP_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of Engine temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of Engine temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef OILPRS_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of oil pressure gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of oil pressure gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_OilPressure_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempMpgTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis position points of trans temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Read
**
** Inputs           :  Buffer:to read the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempMpgTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempMpgTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis position points of trans temperature gauge mapping table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_TransTemp_PointerGaugeCalibrationPointPosition_Y_Write
**
** Inputs           :  Buffer:to write the position points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempMpgTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef SPEEDO_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of speedo correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibration_X_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
static Std_ReturnType MotorDiag_SpeedoCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TACHO_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of tacho correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibration_X_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
static Std_ReturnType MotorDiag_TachoCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef FUEL_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of fuel gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibration_X_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
static Std_ReturnType MotorDiag_FuelCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef ENGTEMP_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of Engine temperature gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibration_X_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
static Std_ReturnType MotorDiag_EngTempCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef OILPRS_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of oil pressure correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsCrtnTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis calibration points of oil pressure correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempCrtnTableX_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read X axis calibration points of trans temperature correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempCrtnTableX_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempCrtnTableX_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write X axis calibration points of trans temperature correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempCrtnTableX_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef SPEEDO_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of speedo correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibration_Y_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of speedo correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Speedo_PointerGaugeCalibration_Y_Write
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SpeedoCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TACHO_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of tacho correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibration_Y_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of tacho correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Tacho_PointerGaugeCalibration_Y_Write
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TachoCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef FUEL_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of fuel gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibration_Y_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of fuel gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Fuel_PointerGaugeCalibration_Y_Write
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_FuelCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef ENGTEMP_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of Engine temperature gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibration_Y_Read
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of Engine temperature gauge correction table
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_EngTemp_PointerGaugeCalibration_Y_Write
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_EngTempCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef OILPRS_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of oil pressure correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of oil pressure correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_OilPrsCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempCrtnTableY_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Y axis calibration points of trans temperature correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to read the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempCrtnTableY_Read(uint16 *Buffer)
{
     return E_OK; /*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempCrtnTableY_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Y axis calibration points of trans temperature correction table
**                      
** Invocation       :  Motor.diagcdd , Function:
**
** Inputs           :  Buffer:to write the calibration points
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_TransTempCrtnTableY_Write(uint16 *Buffer, uint8 *ErrorCode)
{
     return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef READ_MOTOR_POSITION
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_MotorPosRchd_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to verify the motor position reached or not.
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[out]:Motor position Status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_MotorPosRchd_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef MMOS_CALIB_READ
#ifdef cSpeedo_GaugeID
/*=====================================================================================================================
**
** Function Name    :  Speedo_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  Service read the magnetic offset of the speedo meter
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Speedo_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  Speedo_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  Service write the magnetic offset of the speedo meter to the NVM
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:NVM job status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Speedo_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTacho_GaugeID
/*=====================================================================================================================
**
** Function Name    :  Tacho_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Tacho_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  Tacho_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Tacho_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cFuel_GaugeID
/*=====================================================================================================================
**
** Function Name    :  Fuel_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Fuel_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  Fuel_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Fuel_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cEngineTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  EngTemp_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void EngTemp_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  EngTemp_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void EngTemp_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cOilPressure_GaugeID
/*=====================================================================================================================
**
** Function Name    :  OilPrs_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void OilPrs_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  OilPrs_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void OilPrs_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTransTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  TransTemp_MMOS_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TransTemp_MMOS_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  TransTemp_MMOS_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Magnetic offset value
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TransTemp_MMOS_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#endif
#ifdef JUMP_IN_USTEPS
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Jump_In_Microsteps_STA
**
** Visibility       :  Private 
**
** Description      :       
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[out]:Motor position Status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_Jump_In_Microsteps_STA(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Jump_In_Microsteps_RCTE
**
** Visibility       :  Private 
**
** Description      :       
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
static Std_ReturnType MotorDiag_Jump_In_Microsteps_RCTE(uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef ORDER_IN_USTEPS_OR_DEG
/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_MicrostepsorDegrees_STA
**
** Visibility       :  Private 
**
** Description      :  Service to move the stepper motor to a position defined in microsteps or Degrees.
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Order_In_Microsteps_Or_Degrees_STA
**
** Inputs           :  Data[in]:osition in microsteps or degree
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Motordiag_Order_In_MicrostepsorDegrees_STA(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  Motordiag_Order_In_MicrostepsorDegrees_RCTE
**
** Visibility       :  Private 
**
** Description      :   service to return the control to the ECU        
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Order_In_Microsteps_Or_Degrees_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Motordiag_Order_In_MicrostepsorDegrees_RCTE(uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef HIGH_IMPEDANCE
/*=====================================================================================================================
**
** Function Name    :  HighImpedance_STA
**
** Visibility       :  Private 
**
** Description      :  Service to drive the stepper motors with an external tool.
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_High_Impedance_STA
**
** Inputs           :  Data[in]: Stepper motor to be driven in high impedance
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HighImpedance_STA(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  HighImpedance_RCTE
**
** Visibility       :  Private 
**
** Description      :  service to exits from the high impedance mode 
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_High_Impedance_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HighImpedance_RCTE( uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef LOW_TORQUE
/*=====================================================================================================================
**
** Function Name    :  LowTorque_STA
**
** Visibility       :  Private 
**
** Description      :  Service is used to set lower torque on the stepper motor    
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Low_Torque_STA
**
** Inputs           :  Data[in]: Torque value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType LowTorque_STA(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  LowTorque_RCTE
**
** Visibility       :  Private 
**
** Description      :  service is used to restore to the previous low torque value      
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Low_Torque_RCTE
**
** Inputs           :   Errorcode:to be updated with error code if any
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType LowTorque_RCTE(uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
#ifdef cSpeedo_GaugeID
/*=====================================================================================================================
**
** Function Name    :  SpeedoGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :   Service to move the speedo meter to a position defined in vehicle unit.
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Order_In_Vehicle_Unit_STA
**
** Inputs           :  Data[In]:position of the respective gauge
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void SpeedoGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  SpeedoGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  Service to request speedo meter to move to a position defined in vehicle unit.
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Order_In_Vehicle_Unit_STA
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void SpeedoGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTacho_GaugeID
/*=====================================================================================================================
**
** Function Name    :  TachoGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :  Service to move the tacho meter to a position defined in vehicle unit.
**                      
** Invocation       :  Motor.diagcdd , Function:Motordiag_Order_In_Vehicle_Unit_STA
**
** Inputs           :  Data[In]:position of the respective gauge
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TachoGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  TachoGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TachoGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cFuel_GaugeID
/*=====================================================================================================================
**
** Function Name    :  FuelGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void FuelGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  FuelGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void FuelGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cEngineTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  EctGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void EctGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  EctGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void EctGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cOilPressure_GaugeID
/*=====================================================================================================================
**
** Function Name    :  OilPrsGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void OilPrsGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  OilPrsGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void OilPrsGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTransTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  TransTempGaugeControl_Val
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TransTempGaugeControl_Val(uint16 Data)
{
	/*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  TransTempGaugeControl_Req
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void TransTempGaugeControl_Req(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#endif
#ifdef HIGH_CALIBRATION_CONTROL
/*=====================================================================================================================
**
** Function Name    :  HighCalib_Start
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HighCalib_Start(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  HighCalib_Stop
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HighCalib_Stop(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  HighCalib_Result
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType HighCalib_Result(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef POINTER_PLACEMENT_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  PointerPlacement_Start
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType PointerPlacement_Start(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  PointerPlacement_Stop
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType PointerPlacement_Stop(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  PointerPlacement_Result
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType PointerPlacement_Result(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef SFD_ROC_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  SFDROC_Calib_Start
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType SFDROC_Calib_Start(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  SFDROC_Calib_Stop
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType SFDROC_Calib_Stop(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  SFDROC_Calib_Result
**
** Visibility       :  Private 
**
** Description      :  
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType SFDROC_Calib_Result(uint8 *Data, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif
#ifdef POINTER_POSITION_READ
#ifdef cSpeedo_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read speedo gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_SpeedoPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write speedo gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_SpeedoPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTacho_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read tacho gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TachoPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write tacho gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TachoPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cFuel_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read fuel gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_FuelPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write fuel gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_FuelPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cEngineTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read engine temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_EngTempPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngTempPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write engine temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_EngTempPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTransTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read trans temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TransTempPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTempPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write trans temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TransTempPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cOilPressure_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsPointerPlacmnt_Read
**
** Visibility       :  Private 
**
** Description      :  service to read oil temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_OilPrsPointerPlacmnt_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsPointerPlacmnt_Write
**
** Visibility       :  Private 
**
** Description      :  service to write oil temperature gauge pointer placement
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_OilPrsPointerPlacmnt_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#endif
#ifdef SWZERO_SCALE_PARAMETERS
#ifdef cSpeedo_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read speedo gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_SpeedoSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SpeedoSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write speedo gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_SpeedoSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTacho_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read tacho gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TachoSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TachoSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write tacho gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TachoSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cFuel_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read fuel gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_FuelSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_FuelSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write fuel gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_FuelSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cEngineTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read engine temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_EngSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_EngSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write engine temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_EngSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cOilPressure_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read trans temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_OilPrsSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_OilPrsSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write trans temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_OilPrsSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef cTransTemp_GaugeID
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTSWZeroValue_Read
**
** Visibility       :  Private 
**
** Description      :  service to read oil temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TransTSWZeroValue_Read(uint16* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_TransTSWZeroValue_Write
**
** Visibility       :  Private 
**
** Description      :  service to write oil temperature gauge SW zero scale parameter value 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_TransTSWZeroValue_Write(uint16 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#endif
#ifdef POINTER_AUTHOMODE_READ
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_PPMA_Read
**
** Visibility       :  Private 
**
** Description      :  service to read Pointer placement mode authorisation
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: 
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_PPMA_Read(uint8* Data)
{
	/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_PPMA_Write
**
** Visibility       :  Private 
**
** Description      :  service to write Pointer placement mode authorisation
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Magnetic offset value
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_PPMA_Write(uint8 Data)
{
	/*to be replaced with RTE*/ 
}
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_GetCurrentPos_MicroStp_Or_Deg
**
** Visibility       :  Private 
**
** Description      :  To get the current position of the motor 
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]:Position : Position in MicroStep or Degree
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_GetCurrentPos_MicroStp_Or_Deg(uint8 Index, uint16 *Position )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SetPos_MicroStp_Or_Deg
**
** Visibility       :  Private 
**
** Description      :  To move to the requested position
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Position : Position in MicroStep or Degree
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SetPos_MicroStp_Or_Deg(uint8 Index, uint16 *Position )
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SetPos_MicroStp_Or_DegEx
**
** Visibility       :  Private 
**
** Description      :  To move to the requested position within the time requested
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:Position : Position in MicroStep or Degree
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SetPos_MicroStp_Or_DegEx(uint8 Index,uint16 *Position, uint16 *Time)
{
	return E_OK;/*to be replaced with RTE*/ 
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Get_Stepper_Status
**
** Visibility       :  Private 
**
** Description      :  To get the current status of the stepper motor
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Status of the stepper motor
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_Get_Stepper_Status(uint8 Index, uint8 *ErrorCode )
{
	return E_OK;/*to be replaced with RTE*/ 
}
#endif

#ifdef SELFTEST_GAUGES
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SelfTestStprStallDetection_RCStart
**
** Visibility       :  Private
**
** Description      :  To start the self test of gauges
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Status of the self test start routine
**
** Outputs          :  NA
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStart(uint8 *Data, uint8 *ErrorCode)
{
	return E_OK;/*to be replaced with RTE*/
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SelfTestStprStallDetection_RCStop
**
** Visibility       :  Private
**
** Description      :  To stop the self test of gauges
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Status of the self test stop routine
**
** Outputs          :  NA
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStop(uint8 *Data, uint8 *ErrorCode)
{
	return E_OK;/*to be replaced with RTE*/
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_SelfTestStprStallDetection_RCStatus
**
** Visibility       :  Private
**
** Description      :  To provide status of the self test of gauges
**
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]: Status of the self test of gauges routine
**
** Outputs          :  NA
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType MotorDiag_SelfTestStprStallDetection_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
	return E_OK;/*to be replaced with RTE*/
}
#endif
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Nvm_JobResult_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read NVM job status
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[Out]:NVM job status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_Nvm_JobResult_Read(uint8* JobStatus)
{
	
}
/*=====================================================================================================================
**
** Function Name    :  MotorDiag_Nvm_JobResult_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write NVM job status
**                      
** Invocation       :  Motor.diagcdd
**
** Inputs           :  Data[In]:NVM job status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void MotorDiag_Nvm_JobResult_Write(uint8 JobStatus)
{
	
}
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
** Date              : 01/Oct/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1208647
** Change Description: cEngTemp_GaugeID has been renamed to cEngineTemp_GaugeID.                       
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 10/Aug/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1144520
** Change Description: Number of motors reduced.
**=======================================================================================================================*/
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
/*=====================================================================================================================
** Date              : 03/Jul/2018 
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Initial verion for MeetCdd bookshelf. 
**====================================================================================================================*/

#endif
