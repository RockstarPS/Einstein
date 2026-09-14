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
** Name:           Displaycontroldiagcdd_cfg.h
**
** Description:    contains configurable parameters for display control services
**                
**
**====================================================================================================================*/
#ifndef DISPLAYCONTROLDIAGCDD_CFG_H
#define DISPLAYCONTROLDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

#ifdef TFTXYSHIFTCTRLENABLE
/*Configuration for TFT XY Shift Control */
# define XYSHIFTCTRL_MIN_POS			0x00U 	/* minimum positive value allowed for XY Shift Control*/
# define XYSHIFTCTRL_MAX_NEG			0xFFU 	/* maximum negative value allowed for XY Shift Control*/
# define XSHIFTCTRL_MAX_POS 			0x19U 	/*maximum positive value allowed for X Axis Shift Control*/
# define XSHIFTCTRL_MIN_NEG	    		0xE7U 	/*minimum negative value allowed for X Axis Shift Control*/
# define YSHIFTCTRL_MAX_POS 			0x18U 	/*maximum positive value allowed for Y Axis Shift Control*/
# define YSHIFTCTRL_MIN_NEG				0xE9U 	/*minimum negative value allowed for Y Axis Shift Control*/
#endif

#ifdef DISPLAYXYPARAMETERENABLE
/*Configuration for Display X-Y Parameter Reading */
# define NUMOFSHIFTPARAMETER			(uint8)2 	/*X shift and Y Shift*/
# define XYSHIFTPARAMETER_POS		    0x00U 		/*used to denote sign*/
# define XYSHIFTPARAMETER_NEG		    0xFFU 		/*used to denote sign*/
# define XYSHIFTPARAMETER_MAX_POS		0x7FU 		/*maximum positive value allowed for XY Shift Parameter*/
# define XYSHIFTPARAMETER_MIN_NEG		0x80U 		/*minimum negative value allowed for XY Shift Parameter*/
#endif

#ifdef GDTDIAG_TFTPATTERNCTRLENABLE
/*TFT Pattern Control*/
#define GDT_DIAG_EOL_PATTERN   		GFX_SCR_EOL_PATTERN
#define GDT_DIAG_MAX_ANI_ID			ANIM_MAX_ID
#endif

#ifdef LCD_CONTROL_WITH_DUTY
#define LCD_DUTY_CONTREOL_CHANNEL  (2U)
#define LCD_DUTY_CONTROL_BYTE	   (10U)
#endif

#ifdef TFT_CONTROL_WITH_DUTY
#define TFT_DUTY_CONTREOL_CHANNEL  (1U)
#define TFT_DUTY_CONTROL_BYTE	   (6U)
#endif

#ifdef MEET_GIP_ENABLED
#define cIOC_TftPatternControl     ((uint16)0xFE35)
#define cIOC_TftPatternControl_DataLength     ((uint8)0x01U)

#define cIOC_TftFullColorCntrl 	  ((uint32)0xFD0E)
#define cIOC_TftFullColorCntrl_DataLength     ((uint8)0x03U)
#define cIOC_DCICRoutine 	  ((uint32)0xF109)
#define cIOC_DCICRoutine_DataLength     ((uint8)0x05U)
#endif

#ifdef TFTPATTERNCTRLENABLE
/*TFT Pattern Control*/
#define	EOLSCREEN_DISPLAY_PATTERN		(0x00U)	/*EOL Display*/
#define DEFAULT_DISPLAY_PATTERN			(0x01U) /*Red Display*/
#define MAX_PATTERN_NUMBER				(0x28U) /*Number of pattern supported*/
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
#define DISPLAY_TOUCH_TEST_RCTYPE 	(uint8)3
#define MIN_BATTERY_VOLTAGE			(uint16)1850U
#define MAX_BATTERY_VOLTAGE			(uint16)3100U
#define E_PENDING_OK           		0x02U
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
#define TSWI2C_ChCount 			16U
#define TSWI2C_I2CLENGTH 		(uint16)0x01

typedef enum{
	eDisplayI2CSeq_Write	= 0U,
	eDisplayI2CSeq_Read		= 1U,
	eDisplayI2CSeq_Idle		= 2U,
	eDisplayI2CSeq_Error	= 3U,
}eDisplayI2CSeq_StateType;

typedef enum{
	eTSWLink_NOT_TRIGGERED	= 0U,
	eTSWLink_PROGRESS		= 1U,
	eTSWLink_COMPLETED		= 2U,
	eTSWLink_ERROR			= 3U,
	eTSWLink_Failed			= 4U,
}eDisplayTSWLink_StateType;
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
#define TSV_LENGTH 		32U
#define TSVRCTYPE		(uint8)3
#define  TOUCH_DATA_LENGTH 25U
#define MAX_TOUCH_POINT 5U

#endif

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
 
typedef struct
{
    uint8 I2c_Channel;
    uint8 SlaveAddress;
    boolean ActiveStatus;
}I2c_InterfaceValidationType;
 
/* I2C CHANNELS */
#define CHANNEL0 0U
#define CHANNEL1 1U
#define CHANNEL2 2U
#define CHANNEL3 3U
#define CHANNEL4 4U
#define CHANNEL5 5U
#define CHANNEL6 6U
#define MAX_I2C_CHANNEL_ID 7U
/* I2C ADDRESSES */
#define I2C_GMSL1       0x17U
#define I2C_PMIC1      0x12U
#define I2C_RESERVED    0x00U
 
 
extern const I2c_InterfaceValidationType I2c_InterfaceValidation[MAX_I2C_CHANNEL_ID];
 
#endif
typedef enum{
    eDisplayROUTINE_INACTIVE      = 0U,
	eDisplayROUTINE_FINISH_OK     = 1U,
	eDisplayROUTINE_EcuSTOPPED    = 2U,
	eDisplayROUTINE_TesterSTOPPED = 4U,
    eDisplayROUTINE_FINISH_NOK 	  = 6U,
    eDisplayROUTINE_INPROGRESS    = 8U,
}eDisplayRoutineStatus;

typedef struct
{
	Std_ReturnType (*DisplayCtrlDiag_STA) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlDiag_RCTE) (uint8 *ErrorCode);
}DisplayCtrlDiag_IOCTL;

typedef struct
{
	Std_ReturnType (*DisplayCtrlDiag_Read) (uint8 *Data);
	Std_ReturnType (*DisplayCtrlDiag_Write) (uint8 *Data, uint8 *ErrorCode);
}DisplayCtrlDiag_ReadWrite;

typedef struct
{
	Std_ReturnType (*DisplayCtrlDiag_Start) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlDiag_Stop) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlDiag_Result) (uint8 *Data, uint8 *ErrorCode);	
}DisplayCtrlDiag_RCTL;

#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
typedef struct
{
	Std_ReturnType (*DisplayCtrlAllLCDsegment_Start) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlAllLCDsegment_Stop) (uint8 *Data, uint8 *ErrorCode);
}DisplayCtrlAllSegmentDiag;
#endif

#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
typedef struct
{
	Std_ReturnType (*DisplayCtrlAllTFTColor_Start) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlAllTFTColor_Stop) (uint8 *Data, uint8 *ErrorCode);
}DisplayCtrlAllLitTFTDiag;
#endif

#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
typedef struct
{
	Std_ReturnType (*DisplayCtrlLCDDiag_STA) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlLCDDiag_RCTE) (uint8 *ErrorCode);
}DisplayCtrlLCDDiag_IOCTL;
#endif
#ifdef DISPLAY_CONTENT_CHECK
Std_ReturnType DisplayCtrlDiag_ePRNDL_RGBChecksum_monitor_start (uint8 *Data);
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
typedef struct
{
	Std_ReturnType (*DisplayCtrlDiag_TouchTest_PreCondition) (uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlDiag_TouchTest_Read) (uint8 *Data);
	Std_ReturnType (*DisplayCtrlDiag_TouchTest_Write) (uint8 *Data);
	void (*DisplayCtrlDiag_TouchTest_PostCondition)	(void);
}DisplayTouchTest;
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
typedef struct
{
	Std_ReturnType (*DisplayCtrlI2CRead_Start) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*DisplayCtrlI2CRead_Result) (uint8 *Data, uint8 *ErrorCode);	
}DisplayCtrlI2CRead;
#endif
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef TFTPATTERNCTRLENABLE
extern const DisplayCtrlDiag_IOCTL TFTPatternCtrlConfig;
#endif

#ifdef TFTFULLCOLORCTRLENABLE
extern const DisplayCtrlDiag_IOCTL TFTFullColorCtrlConfig;
#endif

#ifdef TFTONEDOTCTRLENABLE
extern const DisplayCtrlDiag_IOCTL TFTOneDotCtrlConfig;
#endif

#ifdef TFTXYSHIFTCTRLENABLE
extern const DisplayCtrlDiag_IOCTL TFTXYShiftCtrlConfig;
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
extern const DisplayCtrlDiag_IOCTL TFTAdjChessPtrnCtrlConfig;
#endif

#ifdef DISPLAYXYPARAMETERENABLE
extern const DisplayCtrlDiag_ReadWrite DisplayXYParameterConfig;
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
extern const DisplayCtrlDiag_RCTL DisplaySplSeqConfig;
#endif

#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
extern const DisplayCtrlAllSegmentDiag DisplayCtrlAllSegmentConfig;
#endif

#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
extern const DisplayCtrlAllLitTFTDiag DisplayCtrlAllLitTFTConfig;
#endif

#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
extern const DisplayCtrlLCDDiag_IOCTL LCDSegmentCtrlConfig;
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
extern const DisplayCtrlDiag_IOCTL TFTVideoCheckConfig;
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
extern const DisplayCtrlDiag_RCTL DisplayContentIntegrity;
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
extern const DisplayCtrlDiag_RCTL DisplayI2CTestConfig;
extern void Displaycontroldiag_I2CTest_Task(void);
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
extern const DisplayTouchTest DisplayTouchTestConfig;
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
extern const DisplayCtrlI2CRead DisplayI2CReadConfig;
extern void Displaycontroldiag_TswI2CRead_Task(void);
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
extern const DisplayCtrlDiag_RCTL DisplayTouchVerificationConfig;
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
** Date              :  17/April/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1985454
** Change Description:  Touch Screen Verification Routine Services are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Touch-Test and Display Pattern service related implementation added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 
** Change Description:  Display content integrity check(SIG unit check) service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 05/Feb/2019
** CDSID             : razhakes
** Traceability      : RTC 1263596
** Change Description: For Display module Update VIP - GIP communication , service id and datalength macros are added
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
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features , macros typecasted as uint
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1113505
** Change Description:  Initial version - DisplaycontrolDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif


