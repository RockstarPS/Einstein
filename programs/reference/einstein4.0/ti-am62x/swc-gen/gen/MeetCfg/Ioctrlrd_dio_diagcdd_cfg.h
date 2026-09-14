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
#ifndef IOCTRLRD_DIO_DIAGCD_CFG_H
#define IOCTRLRD_DIO_DIAGCD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/

/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
#define LED_CONTROL_NUM_OF_SIGNALS 				(24U) //Number of Telltale can configure
#define IOCONTOLRD_PWM_DUTY_MAX          (10000U)
#define IOCONTOLRD_PWM_DUTY_MIN          (0U)
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
#define FUEL_LED_CONTROL_NUM_OF_SIGNALS 		(16U)
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
#define TACHO_LED_CONTROL_NUM_OF_SIGNALS 		(16U)
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
#define ECT_LED_CONTROL_NUM_OF_SIGNALS 			(8U)
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
#define DOUT_CONTROL_NUM_OF_SIGNALS		(3U)  //Number of DOUT  can configure
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
#define DOUT_PORTS_MAX		(4U)  //Number of DOUT  can configure
#define DOUT_BITS_PER_PORT              (8U)
typedef uint8 IoHwAbExt_ErrorType;
#endif

#ifdef IO_SELFCHECK_ENABLE
#define MAX_NUM_BUFFER 			((uint8)10)
#define NUM_OF_SELFCHECK		(3U)
#endif

#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
#define DIN_INT_SIGNAL_CONTROL_SIGNALS 	(8U)  //Update this value if new dio signals are added for internal digital signal control
#define DIN_INT_SIGNAL_CTRL_DATALENGTH	(2U)
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
#define NO_OF_OTP_PMIC_REGISTERS (54U)
#endif


#ifdef IO_BUTTON_READ_ENABLE
#define DIN_BUTTON_NUM_OF_SIGNALS      (15U)  //Number of Button input can configure
#define DIN_RESERVED_BITS_BYTE0  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE1  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE2  ((uint8) (0x00u))  
#define DIN_RESERVED_BITS_BYTE3  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE4  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE5  ((uint8) (0x01u))  
#define DIN_RESERVED_BITS_BYTE6  ((uint8) (0x05u)) 
#define DIN_RESERVED_BITS_BYTE7  ((uint8) (0x20u))
#define DIN_RESERVED_BITS_BYTE8  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE9  ((uint8) (0x24u))  
#define DIN_RESERVED_BITS_BYTE10  ((uint8) (0x00u))   
#define DIN_RESERVED_BITS_BYTE11  ((uint8) (0x00u)) 
#define DIN_RESERVED_BITS_BYTE12  ((uint8) (0xA6u)) 
#define DIN_RESERVED_BITS_BYTE13  ((uint8) (0x81u))   
#define DIN_RESERVED_BITS_BYTE14  ((uint8) (0x80u))
#define DIN_RESERVED_BITS_BYTE15  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE16  ((uint8) (0x08u))
#define DIN_RESERVED_BITS_BYTE17  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE18  ((uint8) (0x10u))
#define DIN_RESERVED_BITS_BYTE19  ((uint8) (0x00u))   
#define DIN_RESERVED_BITS_BYTE20  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE21  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE22  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE23  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE24  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE25  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE26  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE27  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE28  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE29  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE30  ((uint8) (0x00u))
#define DIN_RESERVED_BITS_BYTE31  ((uint8) (0x00u))
#endif

#ifdef IO_DOUT_WRITE_ENABLE
#define DOUT_WRITE_NUM_OF_SIGNALS      (2U)  //Number of Button input can configure
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
#define DOUT_RESERVED_BITS_BYTE0   ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE1   ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE2   ((uint8) (0x00u))   
#define DOUT_RESERVED_BITS_BYTE3   ((uint8) (0x00u))   
#define DOUT_RESERVED_BITS_BYTE4   ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE5   ((uint8) (0x00u))   
#define DOUT_RESERVED_BITS_BYTE6   ((uint8) (0x82u))   
#define DOUT_RESERVED_BITS_BYTE7   ((uint8) (0x5Du))   
#define DOUT_RESERVED_BITS_BYTE8   ((uint8) (0xF0u))   
#define DOUT_RESERVED_BITS_BYTE9   ((uint8) (0xD8u))   
#define DOUT_RESERVED_BITS_BYTE10  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE11  ((uint8) (0x80u))
#define DOUT_RESERVED_BITS_BYTE12  ((uint8) (0x58u))   
#define DOUT_RESERVED_BITS_BYTE13  ((uint8) (0x02u))   
#define DOUT_RESERVED_BITS_BYTE14  ((uint8) (0x1Bu))  
#define DOUT_RESERVED_BITS_BYTE15  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE16  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE17  ((uint8) (0x40u))
#define DOUT_RESERVED_BITS_BYTE18  ((uint8) (0x23u))
#define DOUT_RESERVED_BITS_BYTE19  ((uint8) (0x80u))
#define DOUT_RESERVED_BITS_BYTE20  ((uint8) (0x08u))
#define DOUT_RESERVED_BITS_BYTE21  ((uint8) (0xE0u))
#define DOUT_RESERVED_BITS_BYTE22  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE23  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE24  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE25  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE26  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE27  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE28  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE29  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE30  ((uint8) (0x00u))
#define DOUT_RESERVED_BITS_BYTE31  ((uint8) (0x00u))
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
#define DIN_PIN_OUT_READ_NUM_OF_SIGNALS (5U)  //Number of OUTPUT PIN read configure
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
#define DIN_NUM_OF_BUZZER (1U)				  //Number of buzzer can configure
#endif

#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
#define DATA_BIT_0	0x01U
#define DATA_BIT_1	0x02U
#define DATA_BIT_2	0x04U
#define DATA_BIT_3	0x08U
#define DATA_BIT_4	0x10U
#define DATA_BIT_5	0x20U
#define DATA_BIT_6	0x40U
#define DATA_BIT_7	0x80U
#define eIO_DIN_Reserved 0x0U
#endif

#define NO_OF_BITS_IN_BYTE 	  (8U)
#define DATA_LENGTH_IN_BYTES  (32U)
#define TOTAL_BYTES			  (2U)

#define	OUTPUT_HIGH		(1U)
#define	OUTPUT_LOW		(0U)

#define DIO_ACTIVE_HIGH		(1U)
#define	DIO_ACTIVE_LOW		(0U)

#ifdef LED_CONTROl_WITH_DUTY
#define LED_DUTY_CONTROL_CHANNEL  (0U)
#define LED_DUTY_CONTROL_BYTE	   (4U)
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
#define chime_freq_min	(uint16)600u
#define chime_freq_max	(uint16)20000u
#endif

#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
#define Speaker_Vol_min	(uint8)0u
#define Speaker_Vol_max (uint8)99u
#endif

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
typedef struct
{
	void (*LEDControlFunction) (uint8 led_status);
	uint8   DIO_LogicLevel;

}Meet_LEDControlConfigType;
extern boolean holdTT_ON;
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
typedef struct
{
	void (*LEDControlFunction) (uint8 led_status);
	uint8   DIO_LogicLevel;

}Meet_FUELLEDControlConfigType;
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
typedef struct
{
	void (*LEDControlFunction) (uint8 led_status);
	uint8   DIO_LogicLevel;

}Meet_TACHOLEDControlConfigType;
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
typedef struct
{
	void (*LEDControlFunction) (uint8 led_status);
	uint8   DIO_LogicLevel;

}Meet_ECTLEDControlConfigType;
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
typedef struct
{
	void (*Dio_DOUTFunction) (uint8 pinstatus);
	uint8  DIO_LogicLevel;
}MeetDOUTControlService;
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
typedef struct
{
	uint8 PortId;
	void (*Dio_DOUTPORTFunction) (uint8 pinstatus);
	uint8  DIO_LogicLevel;
}MeetDOUTPORTControlService;
#endif
#ifdef IO_SELFCHECK_ENABLE
typedef struct
{
	Std_ReturnType (*SelfCheckFunction) (uint8 *Data);
}Meet_SelfCheckConfigType;
#endif

#ifdef IO_BUTTON_READ_ENABLE
typedef struct
{
	Std_ReturnType (*DinReadingFunction) (uint8 *Data);
	uint8  DIO_LogicLevel;
}Meet_DinConfigType;
#endif

#ifdef IO_DOUT_WRITE_ENABLE
typedef struct
{
	Std_ReturnType (*DoutWritingFunction) (uint8 Data);
	uint8  DIO_LogicLevel;
}Meet_DoutConfigType;
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
typedef struct
{
	Std_ReturnType (*BuzzerToneControlFunction) (uint8 *Data,uint8 *errorcode);
	Std_ReturnType (*BuzzerToneControlReturnFunction)	(uint8 *errorcode);
}Meet_buzzerToneControlConfigType;
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
typedef struct
{
	Std_ReturnType (*speakerToneControlFunction) (uint8 *Data,uint8 *errorcode);
	Std_ReturnType (*speakerToneControlReturnFunction)	(uint8 *errorcode);
}Meet_speakerToneControlConfigType;
#endif
#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
typedef struct
{
	Std_ReturnType (*speakerVolumeControlFunction) (uint8 *Data,uint8 *errorcode);
	Std_ReturnType (*speakerVolumeControlReturnFunction)	(uint8 *errorcode);
}Meet_speakerVolumeControlConfigType;
#endif
#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
typedef struct
{
	void (*Dio_InternalDigitalCtrlFunction) (uint8 Data);
	uint8  DIO_LogicLevel;
}MeetDIO_InternaldgtlsglCotrl;
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
typedef struct
{
	void (*DinInternaldgtlsglDOUTRead) (uint8 *Data);
}MeetDIO_InternaldgtlsglDOUTRead;
#endif
#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
typedef struct
{
	void (*AllLitLEDControlStart) (uint8 *Data,uint8 *errorcode);
	void (*AllLitLEDControlStop)	(uint8 *errorcode);
}Meet_All_LitControlConfigType;
#endif
#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
typedef struct
{
	Std_ReturnType (*TFTConnectionCheck) (uint8 *Data,uint8 *errorcode);
}MeetDio_ContinuityCheckType;

#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
void PMIC_Read_Regs(void);
#endif


#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
typedef struct
{
	Std_ReturnType (*PMICConfigurationCheck) (uint8 *Data, uint8 *errorcode);
}MeetDio_PMICConfiguration;
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
typedef struct
{
	Std_ReturnType (*MEET_Deser_ReadStart) (uint16 reg, uint8 *Data);
	Std_ReturnType (*MEET_Deser_Write) (uint16 reg, uint8 Data);
}DIO_MEET_DeserConfigType;
#endif
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
extern const Meet_LEDControlConfigType Meet_LEDControlConfig[LED_CONTROL_NUM_OF_SIGNALS];
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
extern const Meet_FUELLEDControlConfigType Meet_FUELLEDControlConfig[FUEL_LED_CONTROL_NUM_OF_SIGNALS];
extern Std_ReturnType Dio_diag_FUELLED_SetPWM(uint8 action);
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
extern const Meet_TACHOLEDControlConfigType Meet_TACHOLEDControlConfig[TACHO_LED_CONTROL_NUM_OF_SIGNALS];
extern Std_ReturnType Dio_diag_TACHOLED_SetPWM(uint8 action);
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
extern const Meet_ECTLEDControlConfigType Meet_ECTLEDControlConfig[ECT_LED_CONTROL_NUM_OF_SIGNALS];
extern Std_ReturnType Dio_diag_ECTLED_SetPWM(uint8 action);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
extern const MeetDOUTControlService Meet_DOUTControlConfig[DOUT_CONTROL_NUM_OF_SIGNALS];
#endif
#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
extern const MeetDOUTPORTControlService Meet_DOUT_PORTControlConfig[DOUT_PORTS_MAX][DOUT_BITS_PER_PORT];
#endif
#ifdef IO_SELFCHECK_ENABLE
extern const Meet_SelfCheckConfigType Meet_SelfCheckConfig[NUM_OF_SELFCHECK];
#endif
#ifdef IO_BUTTON_READ_ENABLE
extern const Meet_DinConfigType Meet_DinConfig[DIN_BUTTON_NUM_OF_SIGNALS];
#endif
#ifdef IO_DOUT_WRITE_ENABLE
extern const Meet_DoutConfigType Meet_DoutConfig[DOUT_WRITE_NUM_OF_SIGNALS];
#endif
#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
extern const Meet_buzzerToneControlConfigType Meet_buzzerToneControlConfig;
#endif
#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
extern const Meet_speakerToneControlConfigType Meet_speakerToneControlConfig;
#endif
#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
extern const Meet_speakerVolumeControlConfigType Meet_speakerVolumeControlConfig;
#endif
#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
extern const MeetDIO_InternaldgtlsglDOUTRead Meet_InternaldgtlsglDOUTConfig[DIN_PIN_OUT_READ_NUM_OF_SIGNALS];
#endif
#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
extern const MeetDIO_InternaldgtlsglCotrl Dio_InternaldgtlsglCotrlConfig[DIN_INT_SIGNAL_CONTROL_SIGNALS];
#endif
#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
extern const Meet_All_LitControlConfigType Meet__All_LitLEDControlConfig;
#endif
#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
extern const MeetDio_ContinuityCheckType Meet_Dio_ConnectionCheckConfig;
#endif
#ifdef IO_BUTTON_READ_ENABLE
extern boolean DinActiveStatus(uint8 PortByte,uint8 Bitmask);
#endif
#ifdef IO_DOUT_WRITE_ENABLE
extern boolean DoutActiveStatus(uint8 PortByte,uint8 Bitmask);
#endif
#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
Std_ReturnType Ioctrlrd_dio_Read_All_Lit_telltale(uint8 *Data);
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
Std_ReturnType Ioctrlrd_dio_Read_TestSpeakerTone(uint8 *Data);
#endif


#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
extern const MeetDio_PMICConfiguration Meet_Dio_PMIC_Configration_Check;
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
extern const DIO_MEET_DeserConfigType DIO_MEET_DeserConfig;
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
** Change Description:  Configuration interfaces are added to read and write deserialiser register
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/06/2022
** CDSID             :  mpandey2
** Traceability      :  RTC 1653104
** Change Description:  PMIC Configuration Check and PMIC Read Registers Periodic Function  Implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix and Minor update.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Typedef and related macros added for Duty control (LED, FUEL, ECT, TACHO), SelfCheck and
** 						DigitalOutputs.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/Dec/2019
** CDSID             : dkasiman
** Traceability      : RTC-1393187 
** Change Description: TFT connection check service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/06/2018
** CDSID             : rkathir1
** Traceability      : RTC 1148632
** Change Description: Speaker function implement
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1151247
** Change Description: IOCONTROl with duty function implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 06/06/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit function implementation
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 18/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113543
** Change Description: Initial version - Ioctrl dio Implementation for Turing Bookshelf.
**=======================================================================================================================*/

#endif


