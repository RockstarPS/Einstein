#ifndef __PNS3030_RF_CTRL_H__
#define __PNS3030_RF_CTRL_H__
 
#ifdef __cplusplus
extern "C" {
#endif

//=============<< Register Functions (Access CONAN Register) >>=============//
PN_VOID Register_MAP_Select(PN_U8 map_sel);

PN_U8 	PNS3030_Tuner_Init(PN_U8 pn_type,PN_FLOAT tuner_freq);
PN_U8 	PNS3030_SetFreq(PN_FLOAT FREQ,PN_FLOAT iIF); 
PN_S32 	PNS3030_Tuner_ChangeFreq(PN_FLOAT tuner_freq);
PN_VOID SelectPowerType(PN_FLOAT tuner_freq, PN_U8 pow_type, PN_U8 io_type);
PN_VOID SetUpClockType(PN_FLOAT frequency);
PN_VOID EV_INIT_ADC_SET(PN_FLOAT frequency, PN_U8 tuner_type, PN_U8 ADCType);
PN_S32 	AGC_STAT_PNS3030(PN_S32 *RF_level, PN_U8 *IF_level, PN_U8 *GVBB_level);
PN_S32 	PNS3030_AGC_CONTROL(PN_U8 pn_type,PN_FLOAT tuner_freq);
void	PN_DrvSLRfGetRssi(PN_U8 pn_type,PN_FLOAT* sig_level, PN_S32* sig_bar, PN_U32 freq);
PN_S32  SLAGC_STAT_PN302X(PN_VOID);
//==============================<<  External Clock Types  >>============================//
#define XTAL13M_ADC_8M			0
#define XTAL13M_ADC_9M			1
#define XTAL16M_ADC_8M			2
#define XTAL16M_ADC_9M			3
#define XTAL16M_ADC_9_6M		4
#define XTAL16_384M_ADC_8_192M  5
#define XTAL16_384M_ADC_8M		6  
#define XTAL16_384M_ADC_9_6M    7	
#define XTAL18M_ADC_8M			8
#define XTAL18M_ADC_9M			9
#define XTAL18M_ADC_9_6M		10
#define XTAL19_2M_ADC_8M		11
#define XTAL19_2M_ADC_8_192M	12
#define	XTAL19_2M_ADC_9M	    13
#define	XTAL19_2M_ADC_9_6M		14
#define	XTAL24M_ADC_8M			15
#define	XTAL24M_ADC_9M			16
#define	XTAL24M_ADC_9_6M		17
#define	XTAL24_576M_ADC_8_192M	18
#define	XTAL24_576M_ADC_8M		19
#define	XTAL24_576M_ADC_9_6M	20
#define	XTAL26M_ADC_8M			21
#define	XTAL26M_ADC_9M			22
#define	XTAL27M_ADC_8M			23
#define	XTAL27M_ADC_9M			24
#define	XTAL32M_ADC_8M			25
#define	XTAL32M_ADC_9M			26
#define	XTAL32M_ADC_9_6M		27
#define	XTAL32_768M_ADC_8_192M	28
#define	XTAL32_768M_ADC_8M		29
#define	XTAL32_768M_ADC_9_6M	30
#define	XTAL36M_ADC_8M			31
#define	XTAL36M_ADC_9M			32
#define	XTAL36M_ADC_9_6M		33
#define	XTAL38_4M_ADC_8M		34
#define	XTAL38_4M_ADC_8_192M	35
#define	XTAL38_4M_ADC_9M		36
#define	XTAL38_4M_ADC_9_6M		37
#define	XTAL40M_ADC_8M			38
#define	XTAL40M_ADC_9M			39
#define	XTAL40M_ADC_9_6M		40
#define	XTAL48M_ADC_8M			41
#define	XTAL48M_ADC_9M			42
#define	XTAL48M_ADC_9_6M		43

#define ADC_SAMPLING_8M          8.0
#define ADC_SAMPLING_8_192M      8.192
#define ADC_SAMPLING_9M          9.0
#define ADC_SAMPLING_9_6M        9.6

#define ONESEG_IF  -0.5
#define TDMB_IF      0
#define FM_IF       0.5

//======================================================================================//

//======================<<  Internal Power&I/O Voltage  Types  >>=======================//
#define USE_POW_EXTERNAL  0
#define USE_POW_LDO       1
#define USE_POW_DCDC      2
#define USE_IO_2_5V       0
#define USE_I0_3_3V       1
#define USE_IO_1_8V       2

//======================================================================================//
#define TuneBandII  0
#define TuneBandIII 1
#define TuneUHF     2
#define TuneLBand   3


//============<<Below Define must sync with HW & Solution configuration///>>=============//
//#define XTAL16_384M
#define XTAL24_576M
//#define XTAL19_2M
//==============================<<  H/W Type Selection  >>==============================//
#ifdef XTAL16_384M
	#define REF_FREQ_DEF	16.384
	#define CLK_TYPE_SEL	XTAL16_384M_ADC_8_192M
#endif

#ifdef XTAL24_576M
	#define REF_FREQ_DEF	24.576
	#define CLK_TYPE_SEL	XTAL24_576M_ADC_8_192M    //External Clock Type Define with ADC Sampling Clock 
#endif

#ifdef XTAL19_2M
	#define REF_FREQ_DEF	19.2
	#define CLK_TYPE_SEL	XTAL19_2M_ADC_8_192M    //External Clock Type Define with ADC Sampling Clock 
#endif

#define DEMOD_0SC_DIV2_ON  0x80
#define DEMOD_0SC_DIV2_OFF 0x00

#if ( CLK_TYPE_SEL >= XTAL32M_ADC_8M)
#define DEMOD_OSC_DIV2 DEMOD_0SC_DIV2_ON
#else
#define DEMOD_OSC_DIV2 DEMOD_0SC_DIV2_OFF
#endif 

//#define ADC_SAMPLING_FOR_DEMOD  ADC_SAMPLING_8M   //ADC Sampling selection for Demodulator Setting :: must be sync with CLK_TYPE_SEL.
#define ADC_SAMPLING_FOR_DEMOD  ADC_SAMPLING_8_192M   //ADC Sampling selection for Demodulator Setting :: must be sync with CLK_TYPE_SEL.
//#define ADC_SAMPLING_FOR_DEMOD  ADC_SAMPLING_9_6M   //ADC Sampling selection for Demodulator Setting :: must be sync with CLK_TYPE_SEL.

#define ADC_NOT_DEFINE (0xFF)
#define ADC_8_0MHZ     1
#define ADC_8_192MHZ   2
#define ADC_9_0MHZ     3
#define ADC_9_6MHZ     4

/* for PN3034P + PNS3030A MRC by terry 20130618*/
#define ADC_8_153MHZ			(5)
#define ADC_8_158MHZ			(6)
#define ADC_8_170MHZ			(7)
#define ADC_8_214MHZ			(8)
#define ADC_8_226MHZ			(9)
#define ADC_8_231MHZ			(10)

#define POWER_TYPE				USE_POW_LDO        
#define IO_TYPE					USE_I0_3_3V

#ifdef __cplusplus
}
#endif

//======================================================================================//
#endif  //END OF __PNS3030_RF_CTRL_H__

