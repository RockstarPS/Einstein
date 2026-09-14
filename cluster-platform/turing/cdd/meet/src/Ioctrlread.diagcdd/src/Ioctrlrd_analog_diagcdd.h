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
** Description:
**
**
**====================================================================================================================*/
#ifndef IOCTRLRD_ANALOG_DIAGCDD_H
#define IOCTRLRD_ANALOG_DIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Ioctrlrd_analog_diagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef IOCTRlRD_ALALOGIC_SIGNAL_CTRL
#define MEET_MAX_DUTY_RESOL_VALUE       ((uint16)1000)
#endif

#if defined(IOCTRLRD_ANALOG_DIAG) || defined(IOCTRLRD_ANALOG_DIAG_BY_UNIT) || defined(IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib)
#define MANUF_OK                        (0U)
#define MANUF_FAIL                      (1U)
#define MANUF_WAIT                      (2U)

#define MANUF_ADCCMD_START              (0U)
#define MANUF_ADCCMD_STOP               (1U)
#define MANUF_ADCCMD_GETRESULTS         (2U)

#define MANUF_NULL                      ((uint8)0x00U)
#define MANUF_TRUE                      ((uint8)0x01U)
#define MANUF_FALSE                     ((uint8)0x00U)
#define MEET_INC_BY_1                   (1U)
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef enum
{
    IOCTRLRD_RC_NOT_ACTIVE,
    IOCTRLRD_RC_IN_PROGRESS,
    IOCTRLRD_RC_FINISHED_OK,
    IOCTRLRD_RC_FINISHED_NOK,
    IOCTRLRD_RC_STOPPED,
} Manuf_RC_State_t;
#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib

#define IOCTRLRD_ADCCMD_START_WCalib (0U)
#define IOCTRLRD_ADCCMD_STOP_WCalib (1U)
#define IOCTRLRD_ADCCMD_GETRESULTS_WCalib (2U)
#define IOCTRLRD_TRUE_WCalib (1U)
#define IOCTRLRD_FALSE_WCalib (0U)
#define IOCTRLRD_OK_WCalib (0U)
#define IOCTRLRD_FAIL_WCalib (1U)
#define IOCTRLRD_WAIT_WCalib (2U)

typedef enum
{
    Fuel_level_input = 0U,
    Oil_level_input = 1U,
} eAdcUnit_channels_WCalib;

void Ioctrlrd_analog_fuel_level_periodic_func(void);

#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
#define IOCTRLRD_ADCCMD_START_THREE_POINT_CALIB         (0U)
#define IOCTRLRD_ADCCMD_STOP_THREE_POINT_CALIB          (1U)
#define IOCTRLRD_ADCCMD_GETRESULTS_THREE_POINT_CALIB    (2U)
#define IOCTRLRD_OK_THREE_POINT_CALIB                   (0U)
#define IOCTRLRD_FAIL_THREE_POINT_CALIB                 (1U)
#define IOCTRLRD_WAIT_THREE_POINT_CALIB                 (2U)
#define IOCTRLRD_TRUE_THREE_POINT_CALIB                 (1U)
#define IOCTRLRD_FALSE_THREE_POINT_CALIB                (0U)
#if 0
#define MANUF_CALIB_NUM_POINTS_FUEL ((uint8)3)
#endif
#define cConvConst2         ((uint32)2)
#define cMaxU32             ((uint32)4294967295UL)
#endif
/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
#ifdef IOCTRlRD_ALALOGIC_SIGNAL_CTRL
Std_ReturnType Ioctrlrd_analog_diag_InternalAnalogicSignalControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_InternalAnalogicSignalControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCTRLRD_ANALOG_DIAG
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_RCStop(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
extern void Manuf_ANA_AnalogValue_Update(void);
#endif

#ifdef IOCTRLRD_ANALOG_DIAG_BY_UNIT
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_AdcInputReading_byunit_RCStop(uint8 DcmDspStartRoutineIn_AI, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_BY_UNIT_WCalib
Std_ReturnType Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStart_WCalib(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_FuelInputReading_byunit_RCStatus_WCalib(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
#endif

#ifdef IOCTRLRD_FUEL_INPUT_READING_THREE_POINT_CALIB
Std_ReturnType Ioctrlrd_analog_diag_InputReading_three_point_Calib_RCStart(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_analog_diag_InputReading_three_point_Calib_RCStatus(uint8 DcmDspStartRoutineIn_AI, uint8 DcmDspStartRoutineIn_NOS, uint8 *DcmDspStartRoutineOutSignal, uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_ADC_READ_GROUP
#if IOCONTOLRD_ADC_READ_GROUP > 0
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_00(uint8 *Data, uint8 *ErrorCode);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 1
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_01(uint8 *Data, uint8 *ErrorCode);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 2
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_02(uint8 *Data, uint8 *ErrorCode);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 3
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_03(uint8 *Data, uint8 *ErrorCode);
#endif
#if IOCONTOLRD_ADC_READ_GROUP > 4
Std_ReturnType Ioctrlrd_analog_diag_read_ADC_Group_04(uint8 *Data, uint8 *ErrorCode);
#endif
#endif
#ifdef IOCONTOLRD_ADC_READ_SAFE_ENABLE
void Ioctrlrd_analog_diag_IoHwSafe_Read_ADC_Value(uint16 *data, uint8 index);
void Ioctrlrd_analog_diag_IoHwSafe_ADC_Perioc_Task(void);
void Ioctrlrd_analog_diag_IoHwSafe_ADC_Init(void);
#endif
#ifdef IOCTRL_ANALOG_READ_ALL_ADC
Std_ReturnType Ioctrlrd_analog_diag_read_All_Adc(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef IOCTRL_ANALOG_READ_ADC_SINGLE_CH
Std_ReturnType Ioctrlrd_analog_diag_read_Adc_SingleChannel(uint8 channel_id, uint16 *AdcValue);
#endif
#ifdef IOCTRL_FILTER_BYPASS_MODE_ENABLE
Std_ReturnType Ioctrlrd_Filter_Bypass_Mode_STA(uint8 *Data);
Std_ReturnType Ioctrlrd_Filter_Bypass_Mode_RCTE(uint8 *Data);
Std_ReturnType Ioctrld_Read_Filter_Bypass_Mode(uint8 *Data);
#define Ioctrld_Read_Filter_Bypass_Mode(Data) Ioctrld_Filter_Bypass_Mode_Read(Data);
#endif
#ifdef IOCTRL_FUEL_SENDER_READ_ENABLE
Std_ReturnType Ioctrld_Read_Fuel_Sender_1(uint8 *Data);
#define Ioctrld_Read_Fuel_Sender_1(Data) Ioctrld_Fuel_Sender_1_Read(Data)
#endif
#ifdef IOCTRL_FUEL_LEVEL_SENDER_READ_ENABLE
Std_ReturnType Ioctrld_Read_Fuel_Level_Sender_1(uint8 *Data);
#define Ioctrld_Read_Fuel_Level_Sender_1(Data) Ioctrld_Read_Fuel_Level_Sender_AD_Count(Data);
#endif
#ifdef IOCTRL_FUEL_SENDER_2_READ_ENABLE
Std_ReturnType Ioctrld_Read_Fuel_Sender_2(uint8 *Data);
#define Ioctrld_Read_Fuel_Sender_2(Data) Ioctrld_Fuel_Sender_2_Read(Data)
#endif
#ifdef IOCTRL_FUEL_LEVEL_SENDER_2_AD_READ_ENABLE
Std_ReturnType Ioctrld_Read_Fuel_Level_Sender_2(uint8 *Data);
#define Ioctrld_Read_Fuel_Level_Sender_2(Data) Ioctrld_Read_Fuel_Level_Sender2_AD_Count(Data);
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
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1310400
** Change Description:  Three point fuel measurement added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  DutyManipulateWithBCD and DutyManipulateWitDecimal functions moved to mgrdiag
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/11/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1229036
** Change Description:  Implementation : Fuel Input Reading - F106
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/10/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1210657
** Change Description:  Analog input reading by Unit
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Oct/2018
** CDSID             : dkasiman
** Traceability      : RTC-1208647
** Change Description: MANUF_RC_STOPPED enum is added,IOCONTOLRD_ADC_READ_GROUP definition checked
                       Ioctrlrd_analog_diag_read_ADC_Group_xx function definition.
**=======================================================================================================================*/
/*=====================================================================================================================
** Date              :  05/09/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1190004
** Change Description:  New implementation for handling and read ADC values
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1159221
** Change Description: ADC Group wise or individual Channel read function implemented.
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 11/07/2018
** CDSID             : dkasiman
** Traceability      : RTC 1113544
** Change Description: #if changed into #ifdef.
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 23/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113544
** Change Description: Initial version - Ioctrl analog Implementation for Turing Bookshelf.
**=======================================================================================================================*/

#endif /* IOCTRLRD_ANALOG_DIAGCDD_H */
