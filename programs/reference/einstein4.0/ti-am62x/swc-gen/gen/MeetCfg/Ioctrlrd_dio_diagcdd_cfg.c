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

#ifndef IOCTRLRD_DIO_DIAGCD_CFG
#define IOCTRLRD_DIO_DIAGCD_CFG

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Platform_Types.h"
#include "Ioctrlrd_dio_diagcdd_cfg.h"


#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
#include "McuExt.h"
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
#include "I2c.h"
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK

#define PF7100_PAGE_SELECT_ADDR       (uint32_t)0x9F
#define OTP_FSOB_SELECT              (uint32_t)0xA0
#define OTP_I2C						 (uint32_t)0xA1
#define OTP_CTRL1					 (uint32_t)0xA2
#define OTP_CTRL2                    (uint32_t)0xA3
#define OTP_CTRL3					 (uint32_t)0xA4
#define OTP_FREQ_CTRL				 (uint32_t)0xA5
#define OTP_SW_RAMP					 (uint32_t)0xA6
#define OTP_PWRON					 (uint32_t)0xA7
#define OTP_WD_CONFIG				 (uint32_t)0xA8
#define OTP_WD_EXPIRE				 (uint32_t)0xA9
#define OTP_WD_COUNTER               (uint32_t)0xAA
#define OTP_FAULT_COUNTERS           (uint32_t)0xAB
#define OTP_FAULT_TIMERS             (uint32_t)0xAC
#define OTP_PWRDN_DLY1				 (uint32_t)0xAD
#define OTP_PWRDN_DLY2				 (uint32_t)0xAE
#define OTP_PWRUP_CTRL				 (uint32_t)0xAF
#define OTP_RESETBMCU_PWRUP          (uint32_t)0xB0
#define OTP_PGOOD_PWRUP				 (uint32_t)0xB1
#define OTP_SW1_VOLT				 (uint32_t)0xB2
#define OTP_SW1_PWRUP				 (uint32_t)0xB3
#define OTP_SW1_CONFIG1				 (uint32_t)0xB4
#define OTP_SW1_CONFIG2				 (uint32_t)0xB5
#define OTP_SW2_VOLT				 (uint32_t)0xB6
#define OTP_SW2_PWRUP				 (uint32_t)0xB7
#define OTP_SW2_CONFIG1				 (uint32_t)0xB8
#define OTP_SW2_CONFIG2     		 (uint32_t)0xB9
#define OTP_SW3_VOLT				 (uint32_t)0xBA
#define OTP_SW3_PWRUP				 (uint32_t)0xBB
#define OTP_SW3_CONFIG1				 (uint32_t)0xBC
#define OTP_SW3_CONFIG2				 (uint32_t)0xBD
#define OTP_SW4_VOLT				 (uint32_t)0xBE
#define OTP_SW4_PWRUP				 (uint32_t)0xBF
#define OTP_SW4_CONFIG1				 (uint32_t)0xC0
#define OTP_SW4_CONFIG2				 (uint32_t)0xC1
#define OTP_SW5_VOLT				 (uint32_t)0xCA
#define OTP_SW5_PWRUP				 (uint32_t)0xCB
#define OTP_SW5_CONFIG1				 (uint32_t)0xCC
#define OTP_SW5_CONFIG2				 (uint32_t)0xCD
#define OTP_LDO1_VOLT				 (uint32_t)0xCE
#define OTP_LDO1_PWRUP				 (uint32_t)0xCF
#define OTP_LDO1_CONFIG				 (uint32_t)0xD0
#define OTP_LDO2_VOLT				 (uint32_t)0xD1
#define OTP_LDO2_PWRUP               (uint32_t)0xD2
#define OTP_LDO2_CONFIG				 (uint32_t)0xD3
#define OTP_VSNVS_CONFIG			 (uint32_t)0xDA
#define OTP_OV_BYPASS1				 (uint32_t)0xDB
#define OTP_OV_BYPASS2				 (uint32_t)0xDC
#define OTP_UV_BYPASS1				 (uint32_t)0xDD
#define OTP_UV_BYPASS2				 (uint32_t)0xDE
#define OTP_ILIM_BYPASS1			 (uint32_t)0xDF
#define OTP_ILIM_BYPASS2			 (uint32_t)0xE0
#define OTP_PROG_IDH				 (uint32_t)0xE1
#define OTP_PROG_IDL				 (uint32_t)0xE2
#define OTP_DEBUG1					 (uint32_t)0xE3

uint32_t Register_address[NO_OF_OTP_PMIC_REGISTERS] = {OTP_FSOB_SELECT,OTP_I2C,OTP_CTRL1,OTP_CTRL2,OTP_CTRL3,OTP_FREQ_CTRL,OTP_SW_RAMP,OTP_PWRON,OTP_WD_CONFIG,OTP_WD_EXPIRE,OTP_WD_COUNTER,OTP_FAULT_COUNTERS,OTP_FAULT_TIMERS,OTP_PWRDN_DLY1,OTP_PWRDN_DLY2,OTP_PWRUP_CTRL,OTP_RESETBMCU_PWRUP,OTP_PGOOD_PWRUP,OTP_SW1_VOLT,OTP_SW1_PWRUP,OTP_SW1_CONFIG1,OTP_SW1_CONFIG2,OTP_SW2_VOLT,OTP_SW2_PWRUP,OTP_SW2_CONFIG1,OTP_SW2_CONFIG2,OTP_SW3_VOLT,OTP_SW3_PWRUP,OTP_SW3_CONFIG1,OTP_SW3_CONFIG2,OTP_SW4_VOLT,OTP_SW4_PWRUP,OTP_SW4_CONFIG1,OTP_SW4_CONFIG2,OTP_SW5_VOLT,OTP_SW5_PWRUP,OTP_SW5_CONFIG1,OTP_SW5_CONFIG2,OTP_LDO1_VOLT,OTP_LDO1_PWRUP,OTP_LDO1_CONFIG,OTP_LDO2_VOLT,OTP_LDO2_PWRUP,OTP_LDO2_CONFIG,OTP_VSNVS_CONFIG,OTP_OV_BYPASS1,OTP_OV_BYPASS2,OTP_UV_BYPASS1,OTP_UV_BYPASS2,OTP_ILIM_BYPASS1,OTP_ILIM_BYPASS2,OTP_PROG_IDH,OTP_PROG_IDL,OTP_DEBUG1};
uint8 Register_value[NO_OF_OTP_PMIC_REGISTERS] = {0xFFu, 0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu,0xFFu};
static uint8 pmic_read_request = 0u;
static uint8 regcount = 0U;

#endif
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH0(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH1(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH2(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH3(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH4(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH5(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH6(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH7(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH8(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH9(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH10(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH11(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH12(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH13(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH14(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH15(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH19(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH20(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH21(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH22(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH23(boolean led_status);
static void Dio_diag_LED_SetPin_ShortTermAdjustment_Reserved(boolean led_status);
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH0(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH1(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH2(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH3(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH4(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH5(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH6(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH7(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH8(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH9(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH10(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH11(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH12(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH13(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH14(boolean led_status);
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH15(boolean led_status);
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH0(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH1(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH2(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH3(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH4(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH5(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH6(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH7(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH8(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH9(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH10(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH11(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH12(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH13(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH14(boolean led_status);
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH15(boolean led_status);
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH0(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH1(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH2(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH3(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH4(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH5(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH6(boolean led_status);
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_Reserved(boolean led_status);
#endif

#ifdef IO_SELFCHECK_ENABLE
static Std_ReturnType SelfCheck_Read_SW01(uint8 *Data);
static Std_ReturnType SelfCheck_Read_SW02(uint8 *Data);
static Std_ReturnType SelfCheck_Read_SW03(uint8 *Data);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
static void Dio_DOUT_PIN_ShortTermAdjustment_ID0(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_ID1(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_ID2(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_ID3(uint8 pin_status);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
static void Dio_DOUT_PIN_ShortTermAdjustment_PI0(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI1(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI2(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI3(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI4(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI5(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI6(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI7(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI8(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI9(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI10(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI11(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI12(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI13(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI14(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI15(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI16(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI17(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI18(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI19(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI20(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI21(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI22(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI23(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI24(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI25(uint8 pin_status);
static void Dio_DOUT_PIN_ShortTermAdjustment_PI26(uint8 pin_status);
#endif

#ifdef IO_BUTTON_READ_ENABLE
static Std_ReturnType Dio_IOPinInId_Read_SW01(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW02(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW03(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW04(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW05(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW06(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW07(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW08(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW09(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW010(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW011(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW012(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW013(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW014(uint8 *Data);
static Std_ReturnType Dio_IOPinInId_Read_SW015(uint8 *Data);


    static const uint8 ActiveDinBits[DATA_LENGTH_IN_BYTES] = 
    {
        /* FIX (87063-87094): Clean initialization without explicit casts */
        DIN_RESERVED_BITS_BYTE0,
        DIN_RESERVED_BITS_BYTE1,
        DIN_RESERVED_BITS_BYTE2,
        DIN_RESERVED_BITS_BYTE3,
        DIN_RESERVED_BITS_BYTE4,
        DIN_RESERVED_BITS_BYTE5,
        DIN_RESERVED_BITS_BYTE6,
        DIN_RESERVED_BITS_BYTE7,
        DIN_RESERVED_BITS_BYTE8,
        DIN_RESERVED_BITS_BYTE9,
        DIN_RESERVED_BITS_BYTE10,
        DIN_RESERVED_BITS_BYTE11,
        DIN_RESERVED_BITS_BYTE12,
        DIN_RESERVED_BITS_BYTE13,
        DIN_RESERVED_BITS_BYTE14,
        DIN_RESERVED_BITS_BYTE15,
        DIN_RESERVED_BITS_BYTE16,
        DIN_RESERVED_BITS_BYTE17,
        DIN_RESERVED_BITS_BYTE18,
        DIN_RESERVED_BITS_BYTE19,
        DIN_RESERVED_BITS_BYTE20,
        DIN_RESERVED_BITS_BYTE21,
        DIN_RESERVED_BITS_BYTE22,
        DIN_RESERVED_BITS_BYTE23,
        DIN_RESERVED_BITS_BYTE24,
        DIN_RESERVED_BITS_BYTE25,
        DIN_RESERVED_BITS_BYTE26,
        DIN_RESERVED_BITS_BYTE27,
        DIN_RESERVED_BITS_BYTE28,
        DIN_RESERVED_BITS_BYTE29,
        DIN_RESERVED_BITS_BYTE30,
        DIN_RESERVED_BITS_BYTE31
    };
#ifndef eIO_DIN_MCU_WIRELESSCHGR_IN
#define eIO_DIN_MCU_WIRELESSCHGR_IN (10U)
#endif

#endif

#ifdef IO_DOUT_WRITE_ENABLE
static Std_ReturnType Dio_IOPinInId_Write_SW01(boolean OutputSignal);
static Std_ReturnType Dio_IOPinInId_Write_SW02(boolean OutputSignal);
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
static const uint8 ActiveDoutBits[DATA_LENGTH_IN_BYTES] = {  (DOUT_RESERVED_BITS_BYTE0 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE1 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE2 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE3 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE4 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE5 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE6 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE7 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE8 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE9 ),  \
                                                      (DOUT_RESERVED_BITS_BYTE10 ), \
                                                      (DOUT_RESERVED_BITS_BYTE11 ), \
                                                      (DOUT_RESERVED_BITS_BYTE12 ), \
                                                      (DOUT_RESERVED_BITS_BYTE13 ), \
                                                      (DOUT_RESERVED_BITS_BYTE14 ), \
                                                      (DOUT_RESERVED_BITS_BYTE15 ), \
													  (DOUT_RESERVED_BITS_BYTE16 ), \
                                                      (DOUT_RESERVED_BITS_BYTE17 ), \
                                                      (DOUT_RESERVED_BITS_BYTE18 ), \
                                                      (DOUT_RESERVED_BITS_BYTE19 ), \
                                                      (DOUT_RESERVED_BITS_BYTE20 ), \
                                                      (DOUT_RESERVED_BITS_BYTE21 ), \
                                                      (DOUT_RESERVED_BITS_BYTE22 ), \
                                                      (DOUT_RESERVED_BITS_BYTE23 ), \
                                                      (DOUT_RESERVED_BITS_BYTE24 ), \
                                                      (DOUT_RESERVED_BITS_BYTE25 ), \
                                                      (DOUT_RESERVED_BITS_BYTE26 ), \
                                                      (DOUT_RESERVED_BITS_BYTE27 ), \
                                                      (DOUT_RESERVED_BITS_BYTE28 ), \
                                                      (DOUT_RESERVED_BITS_BYTE29 ), \
                                                      (DOUT_RESERVED_BITS_BYTE30 ), \
                                                      (DOUT_RESERVED_BITS_BYTE31 )  };
#endif

#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
static void Dio_InternaldgtlsglCotrl_ShortTermAdjustment_CH0(uint8 Data);
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
static void  Dio_IOPinInId_Read_DOUT0(uint8 *Data);
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
#define MEET_BUZZER_CHIME_ID  1
#define MEET_BUZZER_CHANNEL_ID 1
static Std_ReturnType DIO_BUZZER_CH0_TestBuzzerToneReturnFunction(uint8 *data);
static Std_ReturnType  DIO_BUZZER_CH0_TestBuzzerTone(uint8 *data ,uint8 *Erorcode);
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
static Std_ReturnType  DIO_SPEAKER_CH0_TestspeakerToneReturnFunction(uint8 *Data);//Coverity fix CID : 1592153
static Std_ReturnType  DIO_SPEAKER_CH0_TestspeakerTone (uint8 *data ,uint8 *Erorcode);
static boolean chimesToneControlled = FALSE;
#define DIDFEF3DataSize (0x4u)
//static uint8 SetChimeToneData[DIDFEF3DataSize] = {0u, 0u, 0u, 0u};
#endif

#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
static Std_ReturnType  DIO_SPEAKER_CH0_TestspeakerVolumeReturnFunction(uint8 *Data);
static Std_ReturnType  DIO_SPEAKER_CH0_TestspeakerVolume (uint8 *data ,uint8 *Erorcode);
#endif

#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
static void DIO_All_Lit_LED_Control(uint8 *Data ,uint8 *Errorcode);
static void DIO_All_Lit_LED_ControlReturnFunction(uint8 *Data);
#endif
#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
static Std_ReturnType  DIO_TFT_ConnectionCheck(uint8 *Data ,uint8 *Erorcode);
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK 
static Std_ReturnType DIO_PMICConfigurationCheck(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
static Std_ReturnType DIO_MEET_Deser_ReadStart(uint16 reg ,uint8 *Data);
static Std_ReturnType DIO_MEET_Deser_Write(uint16 reg ,uint8 Data);
#endif
/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
//LED control
const Meet_LEDControlConfigType Meet_LEDControlConfig[LED_CONTROL_NUM_OF_SIGNALS]=
{
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH0,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH1,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH2,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH3,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH4,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH5,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH6,DIO_ACTIVE_HIGH},
	    {&Dio_diag_LED_SetPin_ShortTermAdjustment_CH7,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH8,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH9,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH10,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH11,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH12,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH13,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH14,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH15,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_Reserved,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_Reserved,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_Reserved,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH19,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH20,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH21,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH22,DIO_ACTIVE_HIGH},
		{&Dio_diag_LED_SetPin_ShortTermAdjustment_CH23,DIO_ACTIVE_HIGH},
};
boolean holdTT_ON = FALSE;
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
const Meet_FUELLEDControlConfigType Meet_FUELLEDControlConfig[FUEL_LED_CONTROL_NUM_OF_SIGNALS]=
{
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH0,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH1,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH2,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH3,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH4,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH5,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH6,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH7,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH8,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH9,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH10,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH11,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH12,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH13,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH14,DIO_ACTIVE_HIGH},
	{&Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH15,DIO_ACTIVE_HIGH},
};
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
const Meet_TACHOLEDControlConfigType Meet_TACHOLEDControlConfig[TACHO_LED_CONTROL_NUM_OF_SIGNALS]=
{
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH0,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH1,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH2,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH3,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH4,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH5,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH6,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH7,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH8,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH9,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH10,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH11,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH12,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH13,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH14,DIO_ACTIVE_HIGH,
	&Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH15,DIO_ACTIVE_HIGH,
};
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
const Meet_ECTLEDControlConfigType Meet_ECTLEDControlConfig[ECT_LED_CONTROL_NUM_OF_SIGNALS]=
{
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH0,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH1,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH2,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH3,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH4,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH5,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH6,DIO_ACTIVE_HIGH,
	&Dio_diag_ECTLED_SetPin_ShortTermAdjustment_Reserved,DIO_ACTIVE_HIGH,
};
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
//DOUT port control
const MeetDOUTPORTControlService Meet_DOUT_PORTControlConfig[DOUT_PORTS_MAX][DOUT_BITS_PER_PORT]=
{
    { /* Port 0 */
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI0, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI1, DIO_ACTIVE_LOW},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI2, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI3, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI4, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI5, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI6, DIO_ACTIVE_HIGH},
        {0, &Dio_DOUT_PIN_ShortTermAdjustment_PI7, DIO_ACTIVE_HIGH}
    },
    { /* Port 1 */
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI8, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI9, DIO_ACTIVE_LOW},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI10, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI11, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI12, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI13, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI14, DIO_ACTIVE_HIGH},
        {1, &Dio_DOUT_PIN_ShortTermAdjustment_PI15, DIO_ACTIVE_HIGH}
    },
    { /* Port 2 */
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI16, DIO_ACTIVE_LOW},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI17, DIO_ACTIVE_LOW},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI18, DIO_ACTIVE_LOW},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI19, DIO_ACTIVE_LOW},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI20, DIO_ACTIVE_HIGH},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI21, DIO_ACTIVE_HIGH},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI22, DIO_ACTIVE_HIGH},
        {2, &Dio_DOUT_PIN_ShortTermAdjustment_PI23, DIO_ACTIVE_HIGH}
    },
    { /* Port 3 - Completed to 8 elements */
        {3, &Dio_DOUT_PIN_ShortTermAdjustment_PI24, DIO_ACTIVE_HIGH},
        {3, &Dio_DOUT_PIN_ShortTermAdjustment_PI25, DIO_ACTIVE_HIGH},
        {3, &Dio_DOUT_PIN_ShortTermAdjustment_PI26, DIO_ACTIVE_HIGH},
        {0, NULL_PTR, 0},
        {0, NULL_PTR, 0},
        {0, NULL_PTR, 0},
        {0, NULL_PTR, 0},
        {0, NULL_PTR, 0}
    }
};
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
const MeetDOUTControlService Meet_DOUTControlConfig[DOUT_CONTROL_NUM_OF_SIGNALS]=
{
	&Dio_DOUT_PIN_ShortTermAdjustment_ID0, DIO_ACTIVE_HIGH,
	&Dio_DOUT_PIN_ShortTermAdjustment_ID1, DIO_ACTIVE_LOW,
	&Dio_DOUT_PIN_ShortTermAdjustment_ID2, DIO_ACTIVE_HIGH,
}
#endif
#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
//Input PIN control
const MeetDIO_InternaldgtlsglCotrl Dio_InternaldgtlsglCotrlConfig[DIN_INT_SIGNAL_CONTROL_SIGNALS]=
{
    &Dio_InternaldgtlsglCotrl_ShortTermAdjustment_CH0,DIO_ACTIVE_HIGH,

};
#endif

#ifdef IO_SELFCHECK_ENABLE
//button_check
const Meet_SelfCheckConfigType Meet_SelfCheckConfig[NUM_OF_SELFCHECK] =
{
	{&SelfCheck_Read_SW01},
	{&SelfCheck_Read_SW02},
	{&SelfCheck_Read_SW03},
};
#endif

#ifdef IO_BUTTON_READ_ENABLE
//button_check
const Meet_DinConfigType Meet_DinConfig[DIN_BUTTON_NUM_OF_SIGNALS] =
{
	{&Dio_IOPinInId_Read_SW01,DIO_ACTIVE_LOW},	/*1 - DI_SBATT2_ERR#*/
	{&Dio_IOPinInId_Read_SW02,DIO_ACTIVE_HIGH},	/*2 - DI_MD_TOUCH_INTN*/
	{&Dio_IOPinInId_Read_SW03,DIO_ACTIVE_LOW},	/*3 - DI_FALD_PG-Power Good of FALD Power supply*/
	{&Dio_IOPinInId_Read_SW04,DIO_ACTIVE_LOW},	/*4 - DI_BL_FAULT#*/
	{&Dio_IOPinInId_Read_SW05,DIO_ACTIVE_HIGH},	/*5 - DI_SOC_FPDLINK3_LOCK*/
	{&Dio_IOPinInId_Read_SW06,DIO_ACTIVE_LOW},	/*6 - DI_SOC_FPDLINK3_PASS*/
	{&Dio_IOPinInId_Read_SW07,DIO_ACTIVE_LOW},	/*7 - DI_ENET_MII_INT*/
	{&Dio_IOPinInId_Read_SW08,DIO_ACTIVE_HIGH},	/*8 - DI_IGN_MON*/
	{&Dio_IOPinInId_Read_SW09,DIO_ACTIVE_HIGH},	/*9 - DI_CABLE_DETECT*/
	{&Dio_IOPinInId_Read_SW010,DIO_ACTIVE_HIGH},	/*10 - DI_TCON_IND_OUT*/
	{&Dio_IOPinInId_Read_SW011,DIO_ACTIVE_HIGH},	/*11 - DI_SPI_CAN_TCON_SDI*/
	{&Dio_IOPinInId_Read_SW012,DIO_ACTIVE_HIGH},	/*12 - DI_MCU_FALD_CONN_CHK*/
	{&Dio_IOPinInId_Read_SW013,DIO_ACTIVE_LOW},	/*13 - DI_PMIC_INTN*/
	{&Dio_IOPinInId_Read_SW014,DIO_ACTIVE_HIGH},	/*14 - DI_LDO_1V2_FAULTN*/
	{&Dio_IOPinInId_Read_SW015,DIO_ACTIVE_HIGH},	/*15 - DI_TFT_ER_DET*/
};
#endif

#ifdef IO_DOUT_WRITE_ENABLE
//DigitalOutputs write check
const Meet_DoutConfigType Meet_DoutConfig[DOUT_WRITE_NUM_OF_SIGNALS] =
{
	&Dio_IOPinInId_Write_SW01,DIO_ACTIVE_HIGH,	/*1 - DO_MCU_CMIC_PHOLD- Power Hold signal*/
	&Dio_IOPinInId_Write_SW02,DIO_ACTIVE_HIGH,  /*2 - DO_MCU_CMIC_RES Reset signal (TBD)*/
};
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
//Buzzer Test
const Meet_buzzerToneControlConfigType Meet_buzzerToneControlConfig=
{
    &DIO_BUZZER_CH0_TestBuzzerTone,&DIO_BUZZER_CH0_TestBuzzerToneReturnFunction,

};
#endif

#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
//Speaker Test
const Meet_speakerToneControlConfigType Meet_speakerToneControlConfig=
{
    &DIO_SPEAKER_CH0_TestspeakerTone,&DIO_SPEAKER_CH0_TestspeakerToneReturnFunction,
};
#endif

//Speaker volume Test
#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
const Meet_speakerVolumeControlConfigType Meet_speakerVolumeControlConfig=
{
    &DIO_SPEAKER_CH0_TestspeakerVolume,&DIO_SPEAKER_CH0_TestspeakerVolumeReturnFunction,
};
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
//Dout check
const MeetDIO_InternaldgtlsglDOUTRead Meet_InternaldgtlsglDOUTConfig[DIN_PIN_OUT_READ_NUM_OF_SIGNALS] =
{
    &Dio_IOPinInId_Read_DOUT0,
};
#endif
#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
//All Lit -All Telltale control
const Meet_All_LitControlConfigType Meet__All_LitLEDControlConfig=
{
    &DIO_All_Lit_LED_Control,&DIO_All_Lit_LED_ControlReturnFunction,

};
#endif
#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
extern const MeetDio_ContinuityCheckType Meet_Dio_ConnectionCheckConfig =
{
   &DIO_TFT_ConnectionCheck,
};
#ifdef MEET_GIP_ENABLED
static GIPDataRquestState Ioctrlrd_CurrentGIPState = eGIP_InitiateRequest;
#endif

#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
extern const MeetDio_PMICConfiguration Meet_Dio_PMIC_Configration_Check = 
{
	&DIO_PMICConfigurationCheck,
};
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
const DIO_MEET_DeserConfigType DIO_MEET_DeserConfig =
{
	&DIO_MEET_Deser_ReadStart,
	&DIO_MEET_Deser_Write,
};
#endif

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_LED_SetPin_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control Telltale,
**                      
**
** Invocation       :  Ioctrlrd_dio_diag_LEDTeletale_STA
**
** Inputs           :  led_status -Telltale status
**
** Outputs          :  Void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH0(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_ECB_EPB_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH1(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_BRAKE_HOLD_STANDBY_TT09, led_status, &ErrorStatus);
}
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH2(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    if (led_status == TRUE)
    {
        // (void)Rte_Call_rpIoHwAb_PWM_PwmSetDuty(eIO_PWM_HOLD_TT_MCUOUT, (uint16)IOCONTOLRD_PWM_DUTY_MAX, &ErrorStatus);
        holdTT_ON = TRUE;
    }
    else
    {
        // (void)Rte_Call_rpIoHwAb_PWM_PwmSetDuty(eIO_PWM_HOLD_TT_MCUOUT, (uint16)IOCONTOLRD_PWM_DUTY_MIN, &ErrorStatus);
        holdTT_ON = FALSE;
    }
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH3(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    // (void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_BRAKE_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH4(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_AUTO_HIGH_BEAM_TT06, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH5(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_AIRBAG_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH6(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_ADAS_TT02, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH7(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_ABS_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH8(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_SEAT_BELT_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH9(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_RR_FOG_TT00, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH10(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_READY_TT04, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH11(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_PCS_OFF_TT_MCUOUT, led_status, &ErrorStatus);  compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH12(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    if (led_status == TRUE)
    {
        //(void)Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_HIGH_BEAM_TT_MCUOUT, (uint16)IOCONTOLRD_PWM_DUTY_MAX, &ErrorStatus);
    }
    else
    {
        //(void)Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_HIGH_BEAM_TT_MCUOUT, (uint16)IOCONTOLRD_PWM_DUTY_MIN, &ErrorStatus);
    }
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH13(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_FR_FOG_TT05, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH14(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_FUEL_LEVEL_TT13, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH15(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_PARK_BRAKE_TT_OUT, led_status, &ErrorStatus);  compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH19(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_SLIP_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH20(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_TPMS_TT01, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH21(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_VCS_OFF_TT_MCUOUT, led_status, &ErrorStatus); compiler build
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH22(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    // (void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_TURN_LEFT_TT_MCUOUT, led_status, &ErrorStatus);  compiler build
    // (void)Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_TURN_RIGHT_TT_MCUOUT, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH23(boolean led_status)
{
    IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    //(void)Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_TAIL_TT03, led_status, &ErrorStatus);
}

static void Dio_diag_LED_SetPin_ShortTermAdjustment_Reserved(boolean led_status)
{
    /* Reserved */
}
#endif


#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_FUELLED_SetPin_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control FUEL LED BARS,
**
**
** Invocation       :  Ioctrlrd_dio_diag_LEDTeletale_STA
**
** Inputs           :  led_status -FUEL LED BARS status
**
** Outputs          :  Void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH0(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED00, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH1(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED01, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH2(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED02, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH3(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED03, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH4(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED04, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH5(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED05, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH6(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED06, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH7(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_TEMP_LED_Dimming_LED07, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH8(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED08, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH9(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED09, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH10(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED10, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH11(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED11, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH12(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED12, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH13(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED13, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH14(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED14, led_status, &ErrorStatus);

}
static void Dio_diag_FUELLED_SetPin_ShortTermAdjustment_CH15(boolean led_status)
{

	IoHwAbExt_ErrorType ErrorStatus;

	(void) //Rte_Call_rp_IoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_FUEL_LED_Dimming_LED15, led_status, &ErrorStatus);

}

Std_ReturnType Dio_diag_FUELLED_SetPWM(uint8 action)
{
	Std_ReturnType ret = E_OK;
	/* This function is not in use.

	IoHwAbExt_ErrorType ErrorStatus;
	uint16 DutyVal;

	if(action == eSTA)
	{
		DutyVal = 0x03E8U;
	}
	else
	{
		DutyVal = 0x0000U;
	}

	ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCUOUT_BRGPHSUPLY_FUEL, DutyVal, &ErrorStatus);

	*/
	return ret;
}
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_TACHOLED_SetPin_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control TACHO LED BARS,
**
**
** Invocation       :  Ioctrlrd_dio_diag_LEDTeletale_STA
**
** Inputs           :  led_status - TACHO LED BARS status
**
** Outputs          :  Void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH0(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_1, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH1(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_2, led_status, &ErrorStatus);

}
static void Dio_diag_LED_SetPin_ShortTermAdjustment_CH11(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_3, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH3(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_4, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH4(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_5, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH5(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_6, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH6(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_7, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH7(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_8, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH8(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_9, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH9(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_10, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH10(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_11, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH11(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_White_12, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH12(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_Red_1, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH13(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_Red_2, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH14(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_Red_3, led_status, &ErrorStatus);

}
static void Dio_diag_TACHOLED_SetPin_ShortTermAdjustment_CH15(boolean led_status)
{

	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Tacho_LED_Red_4, led_status, &ErrorStatus);

}
Std_ReturnType Dio_diag_TACHOLED_SetPWM(uint8 action)
{
	Std_ReturnType ret = E_NOT_OK;
	//IoHwAbExt_ErrorType ErrorStatus;
	uint16 DutyVal;

	if(action == eSTA)
	{
		DutyVal = 0x03E8U;
	}
	else
	{
		DutyVal = 0x0000U;
	}

	//ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCUOUT_BRGPHSUPLY_TACHO, DutyVal, &ErrorStatus);

	return ret;
}
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_ECTOLED_SetPin_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control ECT LED BARS,
**
**
** Invocation       :  Ioctrlrd_dio_diag_LEDTeletale_STA
**
** Inputs           :  led_status - ECT LED BARS status
**
** Outputs          :  Void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH0(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_1, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH1(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_2, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH2(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_3, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH3(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_4, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH4(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_5, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH5(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_White_6, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_CH6(boolean led_status)
{
	//IoHwAbExt_ErrorType ErrorStatus;

	//(void) Rte_Call_rpIoHwAbExt_SetLed_LEDDriverSetPin(eIOExt_LED_Temp_Gauge_Red_1, led_status, &ErrorStatus);

}
static void Dio_diag_ECTLED_SetPin_ShortTermAdjustment_Reserved(boolean led_status)
{
	/* Reserved */
}
Std_ReturnType Dio_diag_ECTLED_SetPWM(uint8 action)
{
	Std_ReturnType ret = E_NOT_OK;
	//IoHwAbExt_ErrorType ErrorStatus;
	uint16 DutyVal;

	if(action == eSTA)
	{
		DutyVal = 0x03E8U;
	}
	else
	{
		DutyVal = 0x0000U;
	}

	//ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCUOUT_BRGPHSUPLY_TEMP, DutyVal, &ErrorStatus);

	return ret;
}
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Dio_DOUT_PIN_ID0_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control DOUT PIN
**
**
** Invocation       :  Ioctrlrd_dio_diag_DOUT_STA ,Ioctrlrd_dio_diag_DOUT_RCTE
**
** Inputs           :  pin_status -PIN status
**
** Outputs          :
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_DOUT_PIN_ShortTermAdjustment_ID0(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
	(void) Rte_Call_rp_CS_IoHwAb_Dout_SetOutputPin(eIO_DOUT_Flasher_FL_RL_OUT, (boolean)pin_status, &ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_ID1(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;

	(void) Rte_Call_rp_CS_IoHwAb_Dout_SetOutputPin(eIO_DOUT_Flasher_FR_RR_OUT, (boolean)pin_status, &ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_ID2(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;

	(void) Rte_Call_rp_CS_IoHwAb_Dout_SetOutputPin(eIO_DOUT_Flasher_DEN1, (boolean)pin_status, &ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_ID3(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;

	(void) Rte_Call_rp_CS_IoHwAb_Dout_SetOutputPin(eIO_DOUT_Flasher_DSEL1, (boolean)pin_status, &ErrorStatus);
}
#endif


#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Dio_DOUT_PIN_PI0_ShortTermAdjustment
**
** Visibility       :  private
**
** Description      :  Control DOUT PIN
**
**
** Invocation       :  Ioctrlrd_dio_diag_DOUT_STA ,Ioctrlrd_dio_diag_DOUT_RCTE
**
** Inputs           :  pin_status -PIN status
**
** Outputs          :
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_DOUT_PIN_ShortTermAdjustment_PI0(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  	(void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_EN_5V,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI1(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_LIN_NSLP,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI2(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
 (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MCU_RESETSTAZ,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI3(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
   (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_3V3_DISP,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI4(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TFT_BL_EN,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI5(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MD_TOUCH_RST,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI6(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_VPP_EN,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI7(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MD_GNSS_BOOT_EN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI8(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MD_GNSS_RESETP,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI9(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MD_GNSS_PWR_EN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI10(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_BLU_OPAMP_PWR_EN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI11(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_BLU_DWALED_EN,pin_status,&ErrorStatus);
}

static void Dio_DOUT_PIN_ShortTermAdjustment_PI12(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TCON_BYPASS_MODE,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI13(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TCON_BYPASS_SEL0,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI14(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TCON_BYPASS_SEL1,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI15(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_SOC_FPDLINK3_INTB,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI16(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_SOC_FPDLINK3_BISTEN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI17(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_RTC_INTN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI18(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_EN_BUCK_FALD,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI19(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_1V2_EN,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI20(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_SOC_PWR_LATCH,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI21(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MCU_AMUX_S1,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI22(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MCU_AMUX_S0,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI23(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_TCON_SPI0_CS0,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI24(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_SPI_CAN_CS,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI25(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DESER_SPI1_DO,pin_status,&ErrorStatus);
}
static void Dio_DOUT_PIN_ShortTermAdjustment_PI26(uint8 pin_status)
{
	IoHwAbExt_ErrorType ErrorStatus;
  (void) Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_SOC_TCON_GRBN,pin_status,&ErrorStatus);
}
#endif

#ifdef IO_SELFCHECK_ENABLE
/*=====================================================================================================================
**
** Function Name    :  SelfCheck_Read_SW00
**
** Visibility       :  private
**
** Description      :  Self check DID
**
** Invocation       :  Ioctrlrd_dio_diag_SelfCheck_Read
**
** Inputs           :  Data
**
** Outputs          :  Std_ReturnType
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType SelfCheck_Read_SW01(uint8 *Data)
{
	Std_ReturnType ret = E_OK;
	boolean openDetected;
	boolean shortDetected;

	//(void) Rte_Read_CMeetCdd_rp_Fuel02CoreMdl_status_outputs_Fuel_SenderA_open_detected(&openDetected);

	//(void) Rte_Read_CMeetCdd_rp_Fuel02CoreMdl_status_outputs_Fuel_SenderA_short_detected(&shortDetected);

	if(TRUE == openDetected)
	{
		/*Clearing byte1 bit0 and bit 1 - 00*/
		CLEARBIT( Data[1], 0x01U );
		CLEARBIT( Data[1], 0x02U );
	}
	else if(TRUE == shortDetected)
	{
		/*Setting byte1 bit0 and Clearing byte1 bit1 - 01*/
		SETBIT( Data[1], 0x01U );
		CLEARBIT( Data[1], 0x02U );
	}
	else
	{
		/*Clearing byte1 bit0 and Setting byte1 bit1 - 10*/
		CLEARBIT( Data[1], 0x01U );
		SETBIT( Data[1], 0x02U );
	}

	return ret;
}

static Std_ReturnType SelfCheck_Read_SW02(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	boolean shortToGroundStatus;

	/*Channel number is 0x01 for eIO_ADC_AIN_MCU_STR_SW - SWC*/
	//ret = Rte_Call_rp_get_encode_state_Get_Encode_State(STEERING_WHEEL_SWITCH, &shortToGroundStatus);

	/*shortToGroundStatus = 0u = SWC is shorted to ground*/
	if(0U == shortToGroundStatus)
	{
		/*Setting byte1 bit2 and Clearing byte1 bit3 - 01*/
		SETBIT( Data[1], 0x04U );
		CLEARBIT( Data[1], 0x08U );
	}
	else
	{
		/*Clearing byte1 bit2 and byte1 bit3 - 00*/
		CLEARBIT( Data[1], 0x04U );
		CLEARBIT( Data[1], 0x08U );
	}

	return ret;
}

static Std_ReturnType SelfCheck_Read_SW03(uint8 *Data)
{
	Std_ReturnType ret = E_OK;
	uint8 airbagFb = 0U;

	/* airbag RTE is not yet available. Once RTE is available airbag status has to taken from that.
	 * Hence, forcing it as no fault status*/

	if(airbagFb)
	{
		/*Fault - 0: Clearing byte1 bit4*/
		CLEARBIT( Data[1], 0x10U );
	}
	else
	{
		/*No-Fault - 1: Setting byte1 bit4*/
		SETBIT( Data[1], 0x10U );
	}

	return ret;
}

#endif

#ifdef IO_BUTTON_READ_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Dio_IOPinInId_Read_SW00
**
** Visibility       :  private
**
** Description      :  Ioctrlrd_dio_diag_ButtonCheck_Read
**
** Invocation       :  Ioctrlrd_dio_diag_InternalDigitalSignal_Read
**
** Inputs           :  Data-Get input status of  internal logic signal PIN.
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
/*Note: Assign Dio channels in the order from Byte 0- bit0 to byte n - bit8 as per SRD*/
static Std_ReturnType Dio_IOPinInId_Read_SW01(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
	ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_SBATT2_ERR,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW02(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;	
	ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_MD_TOUCH_INTN,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW03(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
	ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_FALD_PG,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW04(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_BL_FAULT ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW05(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_SOC_FPDLINK3_LOCK ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW06(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_SOC_FPDLINK3_PASS ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW07(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_ENET_MII_INT ,Data,&ErrorStatus);
	return ret;
}

static Std_ReturnType Dio_IOPinInId_Read_SW08(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_IGN_MON ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW09(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_CABLE_DETECT ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW010(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_TCON_IND_OUT ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW011(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_SPI_CAN_TCON_SDI ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW012(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_MCU_FALD_CONN_CHK ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW013(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_PMIC_INTN ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW014(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_LDO_1V2_FAULTN ,Data,&ErrorStatus);
	return ret;
}
static Std_ReturnType Dio_IOPinInId_Read_SW015(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus = IOHWAB_E_ERROR;
    ret = Rte_Call_rpIoHwAb_Din_GetProcessedInput(eIO_DIN_DI_TFT_ER_DET ,Data,&ErrorStatus);
	return ret;
}



boolean DinActiveStatus(uint8 PortByte,uint8 Bitmask)
{
	boolean ret = FALSE;

	if(PortByte < DATA_LENGTH_IN_BYTES)
	{
		if (0U != (uint8)(ActiveDinBits[PortByte] & Bitmask))
		{
			/*Corresponding Digital Pin is Active*/
			ret = TRUE;
		}
	}
	else
	{
		/*PortByte out of range*/
		ret = FALSE;
	}
	return ret;
}
#endif

#ifdef IO_DOUT_WRITE_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Dio_IOPinInId_Write_SW00
**
** Visibility       :  private
**
** Description      :  Ioctrlrd_dio_diag_ButtonCheck_Read
**
** Invocation       :  Ioctrlrd_dio_diag_InternalDigitalSignal_Read
**
** Inputs           :  Data-Get input status of  internal logic signal PIN.
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
/*Note: Assign Dio channels in the order from Byte 0- bit0 to byte n - bit8 as per SRD*/
static Std_ReturnType Dio_IOPinInId_Write_SW01(boolean OutputSignal)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus;

	//ret = Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MCU_CMIC_PHOLD, OutputSignal, &ErrorStatus);

	return ret;
}
static Std_ReturnType Dio_IOPinInId_Write_SW02(boolean OutputSignal)
{
	Std_ReturnType ret = E_NOT_OK;
	IoHwAb_ErrorType ErrorStatus;

	//ret = Rte_Call_rpIoHwAb_DOut_SetOutputPin(eIO_DOUT_DO_MCU_CMIC_RES, OutputSignal, &ErrorStatus);

	return ret;
}
#endif

#ifdef IO_DOUT_WRITE_ENABLE
boolean DoutActiveStatus(uint8 PortByte,uint8 Bitmask)
{
	boolean ret = FALSE;

	if(PortByte < DATA_LENGTH_IN_BYTES)
	{
		if (0U != (ActiveDoutBits[PortByte] & Bitmask))
		{
			/*Corresponding Digital Pin is Active*/
			ret = TRUE;
		}
	}
	else
	{
		/*PortByte out of range*/
		ret = FALSE;
	}
	return ret;
}
#endif

#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DinCtrl_internalsgl_CH0
**
** Visibility       :  private
**
** Description      :  MCU PIN control
**
**
** Invocation       :  Ioctrlrd_dio_diag_InternalDigitalSignalControl_STA ,Ioctrlrd_dio_diag_InternalDigitalSignalControl_RCTE
**
** Inputs           :  Data-SET input PIN state
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Dio_InternaldgtlsglCotrl_ShortTermAdjustment_CH0(uint8 Data)
{
	// Rte_Call_rpIoHwABSet_Impl_SetPin(eIOPinOutId_SEATBELT_PASSENGER_OUT,Data);
}
#endif
#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DIO_BUZZER_CH0_TestBuzzerTone
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestBuzzerTone_STA ,Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE
**
** Inputs           :  Data-SET input PIN state
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_BUZZER_CH0_TestBuzzerTone(uint8 *data ,uint8 *Erorcode)
{
 //(void)Rte_Call_rpMEET_BUZZER_TEST_Request_MEET_BUZZER_TEST_Request(0x01,data[0],data[1]);
    Std_ReturnType ret = E_NOT_OK;
	return ret;
}
/*=====================================================================================================================
**
** Function Name    :  DIO_BUZZER_CH0_TestBuzzerTone
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestBuzzerTone_STA ,Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE
**
** Inputs           :  Data-SET input PIN state
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_BUZZER_CH0_TestBuzzerToneReturnFunction(uint8 *data)
{
	//(void)Rte_Call_rpMEET_BUZZER_TEST_Request_MEET_BUZZER_TEST_Request(0x00,data[0],data[1]);
	Std_ReturnType ret = E_NOT_OK;
	return ret;
}
#endif
#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_Read_TestSpeakerTone
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestSpeakerTone_Read
**
** Inputs           :  void
**
** Outputs          :
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_Read_TestSpeakerTone(uint8 *Data)
{
	Std_ReturnType Ret = E_OK;
	/*The commented code is needed only if Read call is done via DcmExt after a Ioctrl_STA / Iocctrl_RCTE call*/
	/*Data[DIDBYTE0] = SetChimeToneData[DIDBYTE0];
	Data[DIDBYTE1] = SetChimeToneData[DIDBYTE1];
	Data[DIDBYTE2] = SetChimeToneData[DIDBYTE2];
	Data[DIDBYTE3] = SetChimeToneData[DIDBYTE3];*/

	return Ret;
}
/*=====================================================================================================================
**
** Function Name    :  DIO_SPEAKER_CH0_TestspeakerTone
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestSpeakerTone_STA
**
** Inputs           :  Data-Speaker ID
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_SPEAKER_CH0_TestspeakerTone(uint8 *data ,uint8 *Erorcode)
{
  	Std_ReturnType ret = E_NOT_OK;
	//tSndCtrlToneParam pChimeToneCtrlData;
	static uint16 freq = 0U;
    uint8 Data_u8[DIDFEF3DataSize];

    Data_u8[DIDBYTE0]= data[DIDBYTE1];	//freq MSB
    Data_u8[DIDBYTE1]= data[DIDBYTE0];	//freq LSB
    Data_u8[DIDBYTE2]= data[DIDBYTE2];	//volume
    Data_u8[DIDBYTE3]= data[DIDBYTE3];	//Channel ID - Not used for TATAGEN2
	
	freq = (uint16)(Data_u8[DIDBYTE1] | (uint16)(Data_u8[DIDBYTE0] << 8U));

	//pChimeToneCtrlData.AmplitudeFrequency = freq;
	//pChimeToneCtrlData.AmplitudeDutyCycle = (uint16)Data_u8[DIDBYTE2];

	if((freq >= chime_freq_min) && (freq <= chime_freq_max))
	{
		#ifdef CMEETCDD_STUBS_CHIMES
			//Stub_SetDiagToneCtrlStart(&pChimeToneCtrlData, &Err);
		#else
			//ret = CSndCdd_RequestCustomChime( &pChimeToneCtrlData );
		#endif

		chimesToneControlled = TRUE;
		ret = E_OK;
	}
	else
	{
		*Erorcode = DCM_E_CONDITIONSNOTCORRECT;
	}
	return ret;
}
/*=====================================================================================================================
**
** Function Name    :  DIO_SPEAKER_CH0_TestspeakerToneReturnFunction
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone from return back to normal
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE
**
** Inputs           :  Data-Speaker ID
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_SPEAKER_CH0_TestspeakerToneReturnFunction(uint8 *Data)
{
	UNUSED(Data);
	Std_ReturnType ret = E_NOT_OK;
	//SSndChimeDB* pCustomChimeDescP;

	if(FALSE != chimesToneControlled)
    {
		#ifdef CMEETCDD_STUBS_CHIMES
			//Stub_SetDiagToneCtrlStop();
		#else
			//ret = CSndCdd_StopCustomChime();
		#endif
	/*The below commented code is needed only if Read call is done via DcmExt after a Ioctrl_STA call*/
	/*	SetChimeToneData[DIDBYTE0] = 0u;
		SetChimeToneData[DIDBYTE1] = 0u;
		SetChimeToneData[DIDBYTE2] = 0u;
		SetChimeToneData[DIDBYTE3] = 0u;*/

        chimesToneControlled = FALSE;
		ret = E_OK;
    }
	else
	{
		 ret = E_NOT_OK;
	}
	return ret;
}
#endif
#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DIO_SPEAKER_CH0_TestspeakerVolume
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone
**
**
** Invocation       :  Ioctrlrd_dio_diag_TestSpeakerTone_STA
**
** Inputs           :  Data-Speaker ID
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_SPEAKER_CH0_TestspeakerVolume(uint8 *data ,uint8 *Erorcode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 channelNumber = 0u;
	uint8 VolumePercentage;
	
	VolumePercentage = data[0];
	
	if(VolumePercentage > Speaker_Vol_max)
	{
		VolumePercentage = Speaker_Vol_max;
	}
	
	ret = Rte_Call_rp_CS_Sndcdd_Services_UpdateChannelVolume(channelNumber, VolumePercentage);
	
	return ret;

}
/*=====================================================================================================================
**
** Function Name    :  DIO_SPEAKER_CH0_TestspeakerToneReturnFunction
**
** Visibility       :  private
**
** Description      :  Check buzzer Tone from return back to normal
**
**
** Invocation       :  DIO_SPEAKER_CH0_TestspeakerVolumeReturnFunction
**
** Inputs           :  Data-Speaker ID
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DIO_SPEAKER_CH0_TestspeakerVolumeReturnFunction(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 channelNumber = 0u;
	uint8 VolumePercentage = 0x50; // Default volume percentage is set as 80 percent
	ret = Rte_Call_rp_CS_Sndcdd_Services_UpdateChannelVolume(channelNumber, VolumePercentage);
	
	return ret;

}
#endif
#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE

/*=====================================================================================================================
**
** Function Name    :  Dio_IOPinInId_Read_DOUT0
**
** Visibility       :  private
**
** Description      :  Read input PIN status
**
**
** Invocation       :  Ioctrlrd_dio_diag_InternalDigitalSignal_Read
**
** Inputs           :  Data-Read input PIN state
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void  Dio_IOPinInId_Read_DOUT0(uint8 *Data)
{

}
#endif
#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_Read_All_Lit_telltale
**
** Visibility       :  Private
**
** Description      :  this function shall read the status of LED whether it is on/off/nocontrol
**
** Invocation       :  Iocontrol_dio_diagcdd, Ioctrlrd_dio_diag_All_Lit_telltale_Read
**
** Inputs           :  Data[out]: The status of LED is updated in this argument
**
** Outputs          :  E_OK : Success
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_Read_All_Lit_telltale(uint8 *Data)
{

		teSetAllTelltalesDiagCtrl Value;

	    //Rte_Read_rp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData(&Value);
	    if(Value == eAllTTOn)
	    {
	    	Value = DIDONE;
	    }
	    else if(Value == eAllTTOff)
	    {
	    	Value = DIDZERO;
	    }
	    else
	    {
	    	/*No action required*/
	    }
	    Data[0] = (uint8)Value;

	    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  DIO_All_Lit_LED_Control
**
** Visibility       :  Private
**
** Description      :  this function shall turn ON all LED's
**
** Invocation       :  Iocontrol_dio_diagcdd, Function:Ioctrlrd_dio_diag_All_Lit_telltale_RCStart
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void DIO_All_Lit_LED_Control(uint8 *Data ,uint8 *Erorcode)
{
	teSetAllTelltalesDiagCtrl Value;
    if(DIDZERO == *Data)
    {
      //  Value = eAllTTOff;
      //  Rte_Write_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData(Value);
    }
    else if(DIDONE == *Data)
    {
      //  Value = eAllTTOn;
      //  Rte_Write_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData(Value);
    }
    else
    {
        *Erorcode = DCM_E_REQUESTOUTOFRANGE;
    }
}
/*=====================================================================================================================
**
** Function Name    :  DIO_All_Lit_LED_ControlReturnFunction
**
** Visibility       :  Private
**
** Description      :  this function shall turn OFF all LED's
**
** Invocation       :  Iocontrol_dio_diagcdd, Function:Ioctrlrd_dio_diag_All_Lit_telltale_RCStop
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void DIO_All_Lit_LED_ControlReturnFunction(uint8 *Data)
{
	UNUSED(Data);
	teSetAllTelltalesDiagCtrl Value;

   // Rte_Read_rp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData(&Value);
    if(eAllTTNoControl != Value)
    {
   //     Value = eAllTTNoControl;
    //    Rte_Write_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData(Value);
    }
}
#endif

#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
/*=====================================================================================================================
** Function Name    :  DIO_TFT_ConnectionCheck
**
** Visibility       :  Private
**
** Description      :  this function shall read TFT connection status
**
** Invocation       :  Iocontrol_dio_diagcdd, Function:Ioctrlrd_dio_diag_continuity_loop_check
**
** Inputs           :  Data[out]:TFT connection status
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static Std_ReturnType  DIO_TFT_ConnectionCheck(uint8 *Data ,uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

	#ifdef MEET_GIP_ENABLED
    Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
	SDiagResponse_t DiagResp;
	DiagReqType DiagReq; 

	
			DiagReq.ActionP = DiagActionType_Read;		
			DiagReq.ServiceId = cREAD_TFT_CONNECTION_STATUS;
			DiagReq.LengthP = TFT_STATUS_LENGTH;
			DiagReq.DataP[0] = MGRDIAGCDD_READ_ACTION;		
		
			switch(Ioctrlrd_CurrentGIPState)
			{
				case eGIP_InitiateRequest:
				  ret = Meet_Process_Gip_Diag_Request(Ioctrlrd_CurrentGIPState, &DiagReq, ErrorCode);
				  Ioctrlrd_CurrentGIPState = eGIP_WaitForResponse;
					break;
				case eGIP_WaitForResponse:
					ret = Meet_Process_Gip_Diag_Request(Ioctrlrd_CurrentGIPState, &DiagReq, ErrorCode);
					if(ret != DCM_E_PENDING)
					{
					Ioctrlrd_CurrentGIPState = eGIP_InitiateRequest;
					}
					break;
				default:
					/*No action required in default case*/
					break;
			}
			
		if(DCM_E_OK == ret)
		{
			DiagResp = *Diag_TIGIP_GetDiagResponse();
			if(TFT_STATUS_LENGTH == DiagResp.Length)
			{
				Data[DATA_BYTE_0] = DiagResp.DiagRespBuffer[0];
			}
			else
			{
				//Size mismatch
				ret = DCM_E_NOT_OK;
			}
		}
		#endif
		
    return ret;
}
#endif


#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
static Std_ReturnType DIO_PMICConfigurationCheck(uint8* Data, uint8* ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;
	uint32_t Register_address1 = PF7100_PAGE_SELECT_ADDR;
	uint32_t RegisterValueWrite = 1u;
	if(0u == pmic_read_request)
	{
		/*switch to page 1 to read OTP mirror register*/
		McuExt_WritePMIC_Reg(Register_address1,RegisterValueWrite);
		pmic_read_request = 1u;		/*set flag*/
		regcount = 0u;
	}	 
	if(regcount == NO_OF_OTP_PMIC_REGISTERS)
	{
		for(regcount = 0u; regcount < NO_OF_OTP_PMIC_REGISTERS;regcount++)
		{
			/*assign read register value to input Data pointer*/
			Data[regcount] = Register_value[regcount];
	    }
		regcount = 0u;
		pmic_read_request = 0u;		/*clear flag*/
		Ret = E_OK;
	}
	else
	{
		Ret = DCM_E_PENDING;	/*wait till all register read is complete*/
	}    
	return Ret; 	
}
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
void PMIC_Read_Regs(void)
{
    uint32_t Register_value1 = 0xFFu;	//clear
	uint8 index = 0u;
	uint8 singleinstance_readlimit = 20u;

	if(pmic_read_request == 1u)
	{  
		if(regcount < NO_OF_OTP_PMIC_REGISTERS)
        {
			for(index = 0u;index < singleinstance_readlimit; index++)
			{
				if(regcount < NO_OF_OTP_PMIC_REGISTERS)
				{
					McuExt_ReadPMIC_Reg(Register_address[regcount],&Register_value1);	
					Register_value[regcount] = Register_value1;
					regcount++;
				}
				else
				{
					/*all PMIC registers are read, hence end the for loop*/
					index = singleinstance_readlimit;
				}
			}	
        }
		else
		{
			/*do nothing*/
			/*pmic_read_request flag will be cleared in DIO_PMICConfigurationCheck()*/
		}
    }
}	
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
static Std_ReturnType DIO_MEET_Deser_ReadStart(uint16 reg, uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	
	uint8 I2C_Buffer[3];
	I2C_Buffer[0] = (uint8)(reg >> 8);
    I2C_Buffer[1] = (uint8)(reg & 0xFFu);
	
	ret = I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_DES_CID_WR, &I2C_Buffer[0], NULL, 2);
	if (ret == E_OK)
	{
		ret |= I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_DES_CID_RD, NULL, &I2C_Buffer[2], 1);
		if (ret == E_OK)
		{
			ret |= I2c_SyncTransmit(I2cConf_I2cSequence_I2cSequence_DES_CID_RD);
			if (ret == E_OK)
			{
				*Data = I2C_Buffer[2];
			}
		}
		
	}
	
	return ret;
}

static Std_ReturnType DIO_MEET_Deser_Write(uint16 reg, uint8 Data)
{
	Std_ReturnType ret = E_NOT_OK;
	
	uint8 I2C_Buffer[3];
	I2C_Buffer[0] = (uint8)(reg >> 8);
    I2C_Buffer[1] = (uint8)(reg & 0xFFu);
	I2C_Buffer[2] = Data;
	
	ret = I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_DES_CID_WR, &I2C_Buffer[0], NULL, 3);
	if (ret == E_OK)
	{
		ret |= I2c_SyncTransmit(I2cConf_I2cSequence_I2cSequence_DES_CID_WR);
	}
	return ret;
}
#endif

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
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Misra warning fix
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
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Configuration interfaces are added for Duty control (LED, FUEL, ECT, TACHO), SelfCheck and
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
** Date              : 06/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit function implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 18/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113543
** Change Description: Initial version - Ioctrl dio Implementation for Turing Bookshelf.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 30/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1127781
** Change Description: Function name has renamed
**====================================================================================================================*/

#endif
