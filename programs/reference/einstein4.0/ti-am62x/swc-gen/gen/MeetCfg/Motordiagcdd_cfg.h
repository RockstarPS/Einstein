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
** Name:           Motordiagcdd_cfg.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef MOTORDIAGCDD_CFG_H
#define MOTORDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#ifdef MOTORDIAG_SERVICE
#include "StpMgrCdd_Cfg.h"
#include "StpDiagCdd.h"
#include "StpDiagCdd_Cfg.h"
#include "Std_Types.h"
#endif
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
# define DATA_LEN_0						(uint8)0
# define DATA_LEN_1 					(uint8)1
# define DATA_LEN_2						(uint8)2
# define DATA_LEN_3 					(uint8)3
# define DATA_LEN_4 					(uint8)4
# define DATA_LEN_5 					(uint8)5
# define DATA_LEN_6 					(uint8)6
# define NUM_OF_POSITION_POINTS 		(uint8)15
# define NUM_OF_CALIBRATION_POINTS		(uint8)15

/*Routine control type configuration*/
/* Configure 1 for Routine type 1, 2 for Routine type 2 and 3 for Routine type 3*/
# define HIGH_CALIB_CNTRL			(uint8)3
# define POINTER_PLACEMENT			(uint8)3
# define SFD_ROC_CALIB				(uint8)3
# define CONTI_POINTER_MOVEMENT		(uint8)2
# define SELFTEST_STEPPER_GAUGES	(uint8)3

/*configure total number of stepper motors to test continuous pointer movement*/
/*If the service is to test all the gauges (0x8F) define NUMBER_OF_MOTORS = (total number of motors configured)  or only one gauge, define NUMBER_OF_MOTORS=1*/
#define NUMBER_OF_MOTORS 6U 
#define TEST_ALL_GAUGE 1
extern const uint8 Valid_StepperMotorID[NUMBER_OF_MOTORS]; 

/* Define the values for the gauges and this order should match with Driver STP_ARRAY_INSTANCE order.
** Example: Tacho Gauge ID is 0 defined here(Stp mgr Cdd cfg file) then in driver Stp Cdd cfg file STP_INSTANCE should have tacho driver number
** i.e tacho gauge is connected to driver 4,STP_INSTANCE(4) should be defined in driver Stp Cdd Cfg file.*/ 
/*#define cPtrTachoView_MotorID      	((uint8)0UL)
#define cPtrFuelView_MotorID        ((uint8)1UL)
#define cPtrEctView_MotorID    	    ((uint8)2UL)
#define cPtrSpeedoView_MotorID      ((uint8)3UL)
#define cPtrOilView_MotorID 		((uint8)4UL)
#define cPtrTransView_MotorID 		((uint8)5UL)

#define SPEEDO_GAUGE	  ((uint8) 0x80)
#define TACHO_GAUGE		  ((uint8) 0x81)
#define FUEL_GAUGE		  ((uint8) 0x82)
#define ENGINETEMP_GAUGE  ((uint8) 0x83)
#define OILPRESSURE_GAUGE ((uint8) 0x84)
#define TRANSTEMP_GAUGE	  ((uint8) 0x85)
#define ALL_GAUGES		  ((uint8) 0x8F)

#define cSpeedo_GaugeID         ((uint8)1)
#define cTacho_GaugeID          ((uint8)2)
#define cFuel_GaugeID           ((uint8)3)  
#define cEngineTemp_GaugeID        ((uint8)4)   
#define cOilPressure_GaugeID    ((uint8)5)   
#define cTransTemp_GaugeID      ((uint8)6)*/

#define MANUF_OK      (0U)
#define MANUF_FAIL    (1U)
#define MANUF_WAIT	  (2U)

#define MANUF_TRUE    (1U)
#define MANUF_FALSE   (0U)


/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef struct
{
	Std_ReturnType (*MotorDiag_Read) (uint16 *Buffer);
	Std_ReturnType (*MotorDiag_Write) (uint16 *Buffer, uint8 *ErrorCode);
}MotorDiag_TableReadWrite_U16;

typedef struct
{
	void (*MotorDiag_Read) (uint8 *Data);
	void (*MotorDiag_Write) (uint8 Data);
}MotorDiag_ReadWrite_U8;

typedef struct
{
	void (*MotorDiag_Read) (uint16 *Data);
	void (*MotorDiag_Write) (uint16 Data);
}MotorDiag_ReadWrite_U16;

typedef struct
{
	Std_ReturnType (*MotorDiag_STA) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*MotorDiag_RCTE) (uint8 *ErrorCode);
}MotorDiag_IOCntrl;

typedef struct
{
	void (*Gauge_ControlVal) (uint16 Data);
	void (*Gauge_ControlRq) (uint16 Data);
}MotorDiag_IOCntrl_U16;

typedef struct
{
	Std_ReturnType (*MotorDiag_RCStart) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*MotorDiag_RCStop) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*MotorDiag_RCResult) (uint8 *Data, uint8 *ErrorCode);
}MotorDiag_ROCntrl;

#ifdef CONTINOUS_POINTER_MOVEMENT
typedef struct
{
	Std_ReturnType (*GetCurrentPos_MicroStp_Or_Deg) (uint8 Id, uint16 *Position);
	Std_ReturnType (*SetPos_MicroStp_Or_Deg) (uint8 Id, uint16 *Position);
	Std_ReturnType (*SetPos_MicroStp_Or_DegEx) (uint8 Id, uint16 *Position, uint16 *Time);
	Std_ReturnType (*Get_Stepper_Status) (uint8 Id, uint8 *Status);
}MotorDiag_Continous_Pointer_Movement;
#endif
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#if defined(SPEEDO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 SpeedoMpgTableXConfig;
#endif
#if defined(TACHO_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 TachoMpgTableXConfig;
#endif
#if defined(FUEL_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 FuelMpgTableXConfig;
#endif
#if defined(ENGTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 EngTempMpgTableXConfig;
#endif
#if defined(OILPRS_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 OilPrsMpgTableXConfig;
#endif
#if defined(TRANSTEMP_MAPTABLE_X) ||  defined(ZERO_POINT_POSITION_READ)
extern const MotorDiag_TableReadWrite_U16 TransTMpgTableXConfig;
#endif
#ifdef SPEEDO_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 SpeedoMpgTableYConfig;
#endif
#ifdef TACHO_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 TachoMpgTableYConfig;
#endif
#ifdef FUEL_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 FuelMpgTableYConfig;
#endif
#ifdef ENGTEMP_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 EngTempMpgTableYConfig;
#endif
#ifdef OILPRS_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 OilPrsMpgTableYConfig;
#endif
#ifdef TRANSTEMP_MAPTABLE_Y
extern const MotorDiag_TableReadWrite_U16 TransTMpgTableYConfig;
#endif
#ifdef SPEEDO_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 SpeedoCrtnTableXConfig;
#endif
#ifdef TACHO_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 TachoCrtnTableXConfig;
#endif
#ifdef FUEL_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 FuelCrtnTableXConfig;
#endif
#ifdef ENGTEMP_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 EngTempCrtnTableXConfig;
#endif
#ifdef OILPRS_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 OilPrsCrtnTableXConfig;
#endif
#ifdef TRANSTEMP_CRTNTABLE_X
extern const MotorDiag_TableReadWrite_U16 TransTCrtnTableXConfig;
#endif
#ifdef SPEEDO_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 SpeedoCrtnTableYConfig;
#endif
#ifdef TACHO_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 TachoCrtnTableYConfig;
#endif
#ifdef FUEL_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 FuelCrtnTableYConfig;
#endif
#ifdef ENGTEMP_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 EngTempCrtnTableYConfig;
#endif
#ifdef OILPRS_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 OilPrsCrtnTableYConfig;
#endif
#ifdef TRANSTEMP_CRTNTABLE_Y
extern const MotorDiag_TableReadWrite_U16 TransTCrtnTableYConfig;
#endif
#ifdef READ_MOTOR_POSITION
extern const MotorDiag_ReadWrite_U8 ReadMotorPosRchd;
#endif
#ifdef JUMP_IN_USTEPS
extern const MotorDiag_IOCntrl JumpInMicrosteps;
#endif
#ifdef ORDER_IN_USTEPS_OR_DEG
extern const MotorDiag_IOCntrl OrderInMicrosteps;
#endif
#ifdef HIGH_IMPEDANCE
extern const MotorDiag_IOCntrl HighImpedance;
#endif
#ifdef LOW_TORQUE
extern const MotorDiag_IOCntrl LowTorque;
#endif
#ifdef ORDER_IN_VEHICLE_UNIT
#ifdef cSpeedo_GaugeID
extern const MotorDiag_IOCntrl_U16 SpeedoGaugeControl;
#endif
#ifdef cTacho_GaugeID
extern const MotorDiag_IOCntrl_U16 TachoGaugeControl;
#endif
#ifdef cFuel_GaugeID
extern const MotorDiag_IOCntrl_U16 FuelGaugeControl;
#endif
#ifdef cEngineTemp_GaugeID
extern const MotorDiag_IOCntrl_U16 EctGaugeControl;
#endif
#ifdef cOilPressure_GaugeID
extern const MotorDiag_IOCntrl_U16 OilPrsGaugeControl;
#endif
#ifdef cTransTemp_GaugeID
extern const MotorDiag_IOCntrl_U16 TransTempGaugeControl;
#endif
#endif
#ifdef HIGH_CALIBRATION_CONTROL
extern const MotorDiag_ROCntrl HighCalibControl;
#endif
#ifdef POINTER_PLACEMENT_ROUTINE
extern const MotorDiag_ROCntrl PointerPlacementRoutine;
#endif
#ifdef SFD_ROC_ROUTINE
extern const MotorDiag_ROCntrl SFDROC_Calib;
#endif
#ifdef POINTER_AUTHOMODE_READ
extern const MotorDiag_ReadWrite_U8 PointerPlacementModeAutho;
#endif
#ifdef MMOS_CALIB_READ
#ifdef cSpeedo_GaugeID
extern const MotorDiag_ReadWrite_U8 SpeedoMMOS;
#endif
#ifdef cTacho_GaugeID
extern const MotorDiag_ReadWrite_U8 TachoMMOS;
#endif
#ifdef cFuel_GaugeID
extern const MotorDiag_ReadWrite_U8 FuelMMOS;
#endif
#ifdef cEngineTemp_GaugeID
extern const MotorDiag_ReadWrite_U8 EngTempMMOS;
#endif
#ifdef cOilPressure_GaugeID
extern const MotorDiag_ReadWrite_U8 OilPresureMMOS;
#endif
#ifdef cTransTemp_GaugeID
extern const MotorDiag_ReadWrite_U8 TransTempMMOS;
#endif
#endif
#ifdef POINTER_POSITION_READ
#ifdef cSpeedo_GaugeID
extern const MotorDiag_ReadWrite_U16 Speedo_PointerPlacementPosition;
#endif
#ifdef cTacho_GaugeID
extern const MotorDiag_ReadWrite_U16 Tacho_PointerPlacementPosition;
#endif
#ifdef cFuel_GaugeID
extern const MotorDiag_ReadWrite_U16 Fuel_PointerPlacementPosition;
#endif
#ifdef cEngineTemp_GaugeID
extern const MotorDiag_ReadWrite_U16 EngTemp_PointerPlacementPosition;
#endif
#ifdef cOilPressure_GaugeID
extern const MotorDiag_ReadWrite_U16 OilPrs_PointerPlacementPosition;
#endif
#ifdef cTransTemp_GaugeID
extern const MotorDiag_ReadWrite_U16 TransTemp_PointerPlacementPosition;
#endif
#endif
#ifdef SWZERO_SCALE_PARAMETERS
#ifdef cSpeedo_GaugeID
extern const MotorDiag_ReadWrite_U16 SpeedoSWZero;
#endif
#ifdef cTacho_GaugeID
extern const MotorDiag_ReadWrite_U16 TachoSWZero;
#endif
#ifdef cFuel_GaugeID
extern const MotorDiag_ReadWrite_U16 FuelSWZero;
#endif
#ifdef cEngineTemp_GaugeID
extern const MotorDiag_ReadWrite_U16 EngSWZero;
#endif
#ifdef cOilPressure_GaugeID
extern const MotorDiag_ReadWrite_U16 OilPrsSWZero;
#endif
#ifdef cTransTemp_GaugeID
extern const MotorDiag_ReadWrite_U16 TransTempSWZero;
#endif
#endif
#ifdef CONTINOUS_POINTER_MOVEMENT
extern const MotorDiag_Continous_Pointer_Movement Continous_Pointer_Movement_RC;
#endif

#ifdef SELFTEST_GAUGES
extern const MotorDiag_ROCntrl SelfTestStprStallDetect;
#endif
extern const MotorDiag_ReadWrite_U8 MotorDiagNvmJobResult_U8;
/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/

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
** Date              : 01/Oct/2018 
** CDSID             : dkasiman
** Traceability      : RTC-1208647
** Change Description: cEngTemp_GaugeID has been renamed to cEngineTemp_GaugeID.                       
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 09/Aug/2018 
** CDSID             : gnataraj
** Traceability      : RTC-1144520
** Change Description: Review comments fixed - Removed unused macros
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
/*======================================================================================================================
** Date              : 03/Jul/2018 
** CDSID             : gnataraj
** Traceability      : RTC-1144520, RTC-1145376
** Change Description: Initial verion for MeetCdd bookshelf. 
**=======================================================================================================================*/

#endif


