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
#ifndef IOCTRLRD_DIO_DIAGCD_H
#define IOCTRLRD_DIO_DIAGCD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Ioctrlrd_dio_diagcdd_cfg.h"
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
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_LEDControl_DUTY_STA(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_LEDControl_DUTY_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_FUELLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_FUELLEDControl_DUTY_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_ECTLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_ECTLEDControl_DUTY_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_DOUT_STA(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_DOUT_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_DOUT_PORT_Control_STA(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_DOUT_PORT_Control_RCTE(uint8 *ErrorCode);
#define IOCTRL_PORTID  0u
#define IOCTRL_MASK_BYTE  1u
#define IOCTRL_OUTPUT_BYTE 2u
#define SET_PIN_DOUT_INACTIVE ((uint8)0U)
#define SET_PIN_DOUT_ACTIVE ((uint8)1U)
#endif

#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignalControl_STA(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignalControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignal_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IO_BUTTON_READ_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_ButtonCheck_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IO_DOUT_WRITE_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_DigitalOutputs_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IO_SELFCHECK_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_SelfCheck_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_TestBuzzerTone_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerTone_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerTone_RCTE(uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerTone_Read(uint8 *Data);
#define Ioctrlrd_dio_diag_TestSpeakerTone_Read(Data) 		Ioctrlrd_dio_Read_TestSpeakerTone(Data);
#endif

#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolume_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolume_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_All_Lit_telltale_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_All_Lit_telltale_RCStop(uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_All_Lit_telltale_Read(uint8 *Data);
#define Ioctrlrd_dio_diag_All_Lit_telltale_Read(Data) 		Ioctrlrd_dio_Read_All_Lit_telltale(Data);
#endif

#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
Std_ReturnType Ioctrlrd_dio_diag_continuity_loop_check(uint8 *Data);
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
Std_ReturnType Ioctrlrd_dio_diag_PMIC_Configuration_Check_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
Std_ReturnType Ioctrlrd_dio_diag_DeserRead_RCStart(uint16 reg, uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_dio_diag_DeserWrite(uint16 reg, uint8 Data, uint8 *ErrorCode);
#endif

#ifdef SOUNDCHANNELVOLUMECONTROL
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolumeControl_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_PLAY_TONE_CONTROL
Std_ReturnType Ioctrlrd_dio_diag_SpeakerTone_RCStart(uint8 *Data, uint8 *ErrorCode);
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
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  04/Aug/2022
** CDSID             :  rtopani
** Traceability      :  RTC-1730821
** Change Description:  Added Volume control DID to change the acoustic level of chime
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  29/06/2022
** CDSID             :  mprajapa
** Traceability      :  RTC 1697574
** Change Description:  To read, write deserialiser register interfaces are added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/06/2022
** CDSID             :  mpandey2
** Traceability      :  RTC 1653104
** Change Description:  PMIC Configuration Check Read Function and PMIC Read Registers Periodic Function  Implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Duty control (LED, FUEL, ECT, TACHO), SelfCheck and DigitalOutputs interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/Dec/2019
** CDSID             : dkasiman
** Traceability      : RTC-1393187
** Change Description: TFT connection check service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 06/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit Telltale function implementation
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 30/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1127781
** Change Description:Unwanted macro deletd
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 18/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113543
** Change Description: Initial version - Ioctrl dio Implementation for Turing Bookshelf.
**=======================================================================================================================*/

#endif /* IOCTRLRD_DIO_DIAGCD_H */
