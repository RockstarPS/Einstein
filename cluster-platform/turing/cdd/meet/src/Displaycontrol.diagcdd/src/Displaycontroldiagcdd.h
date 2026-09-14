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
** Name:           Displaycontroldiagcdd.h
**
** Description:    contains function prototypes for Display control services
**
**
**====================================================================================================================*/
#ifndef DISPLAYCONTROLDIAGCDD_H
#define DISPLAYCONTROLDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Displaycontroldiagcdd_cfg.h"
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
#ifdef TFTPATTERNCTRLENABLE
Std_ReturnType Displaycontroldiag_TFTPatternControl_Duty_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTPatternControl_Duty_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTFULLCOLORCTRLENABLE
Std_ReturnType Displaycontroldiag_TFTFullColorControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTFullColorControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTONEDOTCTRLENABLE
Std_ReturnType Displaycontroldiag_TFTOneDotUpdateControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTOneDotUpdateControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTXYSHIFTCTRLENABLE
Std_ReturnType Displaycontroldiag_TFTXYShiftControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTXYShiftControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
Std_ReturnType Displaycontroldiag_TFTAdjustableChessboardPatternControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTAdjustableChessboardPatternControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef DISPLAYXYPARAMETERENABLE
Std_ReturnType Displaycontroldiag_DisplayXYParameterReading_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_DisplayXYParameterReading_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
Std_ReturnType Displaycontroldiag_LCDAllSegmentControl_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_LCDAllSegmentControl_RCStop(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
Std_ReturnType Displaycontroldiag_TFTAllLit_ColorControl_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TFTAllLit_ColorControl_RCStop(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
Std_ReturnType Displaycontroldiag_LCDSegmentControl_Duty_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_LCDSegmentControl_Duty_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
Std_ReturnType Displaycontroldiag_VideoCheck_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_VideoCheck_RCTE(uint8 *ErrorCode);
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
Std_ReturnType Displaycontroldiag_DCIC_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_DCIC_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_DCIC_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef DISPLAY_CONTENT_CHECK
Std_ReturnType DisplayContentVerfication_RC_Start(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
Std_ReturnType Displaycontroldiag_I2CTest_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_I2CTest_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_I2CTest_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
Std_ReturnType Displaycontroldiag_TouchTest_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TouchTest_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TouchTest_RCStatus(uint8 *Data, uint8 *ErrorCode);
void Displaycontroldiag_TouchTest_Task(void);
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
Std_ReturnType Displaycontroldiag_TSWI2CREAD_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TSWI2CREAD_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
Std_ReturnType Displaycontroldiag_TouchVerification_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TouchVerification_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Displaycontroldiag_TouchVerification_RCStatus(uint8 *Data, uint8 *ErrorCode);
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
** Date              :  17/April/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1985454
** Change Description:  Touch Screen Verification Routine Services are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  15/Mar/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1951989
** Change Description:  I2C-Read service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  I2C-Test service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Touch-Test service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1310404
** Change Description:  Display content integrity check(SIG unit check) service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1265368
** Change Description:  compiler warning fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  20/9/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1195633
** Change Description:  Video check function added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 11/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit All Segment LCD ON /OFF API  function implemented
** 					   All Lit All TFT color control API  function implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1148635
** Change Description: LCD segment control with or with out illumination
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
** Traceability      :  RTC 1113505
** Change Description:  Initial version - DisplaycontrolDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
#endif /* DISPLAYCONTROLDIAGCDD_H */
