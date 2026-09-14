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
** Name:           Iocalibdiagcdd_cfg.h
**
** Description:    contains configurable parameters for IO Calibration services
**                
**
**====================================================================================================================*/
#ifndef IOCALIBDIAGCDD_CFG_H
#define IOCALIBDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef IOCALIBDIAG_RTC_CALIBRATION
/*Macros are taken from RtcCDD module*/
#define RTC_CAL_512Hz 	(0u) 	// 512Hz wave output signal for calibration
#define RTC_CAL_2Hz 	(2u)    // 2Hz wave output signal for calibration
#define RTC_CAL_1Hz 	(3u)    // 1Hz wave output signal for calibration
#endif

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef struct
{
	Std_ReturnType (*IOCalibDiag_Read) (uint8 *Data);
	Std_ReturnType (*IOCalibDiag_Write) (uint8 *Data, uint8 *ErrorCode);
}IOCalibDiag_ReadWrite;

typedef struct
{
	void (*IOCalibDiag_Read) (uint8 *Data);
	void (*IOCalibDiag_Write)(uint8 Data);
}IOCalibDiag_ReadWrite_U8;

#ifdef IOCALIBDIAG_RTC_CALIBRATION
typedef struct
{
	Std_ReturnType (*RtcCalibration_STA) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*RtcCalibration_RCTE)(uint8 *ErrorCode);
}Iocalibdiag_RtcCalibrationConfigType;
#endif
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef LEFTSWTBACKLIGHTENABLE
extern const IOCalibDiag_ReadWrite LeftSwtBackLightConfig;
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
extern const IOCalibDiag_ReadWrite RightSwtBackLightConfig;
#endif

#ifdef TACHOSCALEILLUMNENABLE
extern const IOCalibDiag_ReadWrite TachoScaleIllumnConfig;
#endif

#ifdef TACHOPTRILLUMNENABLE
extern const IOCalibDiag_ReadWrite TachoPtrIllumnConfig;
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
extern const IOCalibDiag_ReadWrite FuelTempScaleIllumnConfig;
#endif

#ifdef FUELPTRILLUMNENABLE
extern const IOCalibDiag_ReadWrite FuelPtrIllumnConfig;
#endif

#ifdef TEMPPTRILLUMNENABLE
extern const IOCalibDiag_ReadWrite TempPtrIllumnConfig;
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
#ifdef ANALOGMEASCALIB3POINTFUELLVLENABLE
extern const IOCalibDiag_ReadWrite AnalogMeas3pointCalibFuelLevelInputConfig;
#else //ANALOGMEASCALIB3POINTFUELLVLENABLE
extern const IOCalibDiag_ReadWrite AnalogMeasCalibFuelLevelInputConfig;
#endif
#endif


#ifdef ANALOGMEASCALIBOILLVLENABLE
extern const IOCalibDiag_ReadWrite AnalogMeasCalibOilLevelInputConfig;
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
extern const IOCalibDiag_ReadWrite SoundChannelVolumeConfig;
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
extern const IOCalibDiag_ReadWrite SoundMixerVolumeConfig;
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
extern const IOCalibDiag_ReadWrite Fuel_Sender_Calib_Table;
#endif

extern const IOCalibDiag_ReadWrite_U8 IOCalibNvmJobResult_U8;

#ifdef ANALOGREFERENCECALIBRATION
extern const IOCalibDiag_ReadWrite AnalogReferenceCalibConfig;
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
extern const Iocalibdiag_RtcCalibrationConfigType Iocalibdiag_RtcCalibrationConfig;
#endif
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
** Date              :  28/Sept/2020
** CDSID             :  mprajapa
** Traceability      :  RTC-1777209
** Change Description:  ADC reference calibration service added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/07/2019
** CDSID             :  vsupraja
** Traceability      :  RTC - 1348007
** Change Description:  Added Read and Write services for Sound Channel Volume and Sound Mixer Volume
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  15/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 
** Change Description:  Three point fuel calibration added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/07/2018
** CDSID             :  gnataraj
** Traceability      :  RTC 1152542
** Change Description:  Added the Read and Write service for Fuel RAD (Fuel Sender Calibration Table) feature
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1122851
** Change Description:  Initial version - IOCalibDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif


