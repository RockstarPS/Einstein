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
** Name:           Ioctrlrd_dio_diagcdd.h
**
** Description:    contains function prototypes for IO Calibration services
**
**
**====================================================================================================================*/
#ifndef IOCALIBDIAGCDD_H
#define IOCALIBDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Iocalibdiagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
#ifdef LEFTSWTBACKLIGHTENABLE
Std_ReturnType Iocalibdiag_LeftSwitchBacklight_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_LeftSwitchBacklight_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
Std_ReturnType Iocalibdiag_RightSwitchBacklight_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_RightSwitchBacklight_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TACHOSCALEILLUMNENABLE
Std_ReturnType Iocalibdiag_TachoScale_Illumination_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_TachoScale_Illumination_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TACHOPTRILLUMNENABLE
Std_ReturnType Iocalibdiag_TachoPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_TachoPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
Std_ReturnType Iocalibdiag_Fuel_TempScale_Illumination_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_Fuel_TempScale_Illumination_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef FUELPTRILLUMNENABLE
Std_ReturnType Iocalibdiag_FuelPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_FuelPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef TEMPPTRILLUMNENABLE
Std_ReturnType Iocalibdiag_TempPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_TempPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
Std_ReturnType IOCalibDiag_Sound_Channel_Volume_OutputRead(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType IOCalibDiag_Sound_Channel_Volume_OutputWrite(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_OutputRead(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_OutputWrite(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
Std_ReturnType Iocalibdiag_FuelSender_Calibration_Table_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_FuelSender_Calibration_Table_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef ANALOGREFERENCECALIBRATION
Std_ReturnType Iocalibdiag_AnalogReferenceCalib_Write(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_AnalogReferenceCalib_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
Std_ReturnType Iocalibdiag_RtcCalibration_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Iocalibdiag_RtcCalibration_RCTE(uint8 *ErrorCode);
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
/*=====================================================================================================================
** Date              :  11/Jan/2023
** CDSID             :  ddanecha
** Traceability      :  RTC-1874182
** Change Description:  RTC calibration interface added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/Sept/2020
** CDSID             :  mprajapa
** Traceability      :  RTC-1777209
** Change Description:  ADC reference calibration service added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/07/2019
** CDSID             :  vsupraja
** Traceability      :  RTC
** Change Description:  Added Read and Write services for Sound Channel Volume and Sound Mixer Volume
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/07/2018
** CDSID             :  gnataraj
** Traceability      :  RTC 1152542
** Change Description:  Added the Read and Write service for Fuel RAD (Fuel Sender Calibration Table) feature
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/06/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  removed extern keyword for function prototypes,comments updated
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
