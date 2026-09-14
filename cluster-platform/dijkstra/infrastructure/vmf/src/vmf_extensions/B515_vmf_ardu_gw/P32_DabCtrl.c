#include "P32_RF_API.h"
#include "P32_RF_PNx3030x.h"
#include "P32_RF_MAX2172.h"
#include "P32_DabCtrl.h"
#include "P32_PNS3030RegDef.h"
#include "P32_BaseFunc.h"
#include "P32_DmbApi.h"
#include "stub_fkts.h"


PN_U8  msc_cer_acc_no1=0, msc_cer_acc_no2=0;
PN_U32 msc_cer_acc1, msc_cer_acc2;
PN_U32 msc_cer_chk1, msc_cer_chk2;
PN_FLOAT CN1=0, CN2=0;
PN_FLOAT CN_S1=0, CN_S2=0;
PN_FLOAT SNR1=0, SNR2=0;
PN_FLOAT TOTAL_CN1=0, TOTAL_CN2=0;

/* PNS3030_RegDef.h */
#define AGC0_E_EN           (0x53)  /// MON PRE START [7]
#define PRE_TH              (0x54)  /// AGC threshold
#define MON_CNT_PRE1_L      (0x66)  /// Display PRE AGC value[1:0]
#define MON_CNT_PRE1_H      (0x67)  /// Display PRE AGC value[9:2]

#define ACTIVE_CH_SET       (0x30)  /// Active channel for Reconfiguration [7]Decoding- 1:enable [6]RS pass - 1:enable [5:0]Subch_ID0


////////////////////////////////////////
// PN3030EV Operation Mode Selection  //
////////////////////////////////////////
PN_S32 EV_OPERATE(PN_U8 pn_type)
{
	PN_U8 chipid;
	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, TOP01_E, &chipid);
	if(chipid != 0x43)
            return PN_FN_FAIL;

	Delay_Ms(1);
	return PN_FN_OK;
}

PN_VOID EV_INIT(PN_U8 pn_type, PN_U8 tuner_type, PN_FLOAT frequency)
{
	EV_INIT_TOP(PN3030E_ADDR, tuner_type);
	EV_INIT_COMM(PN3030E_ADDR, tuner_type);
	EV_INIT_HOST(PN3030E_ADDR, tuner_type);
	EV_INIT_OFDM(PN3030E_ADDR, tuner_type, frequency);
	EV_INIT_FEC(PN3030E_ADDR, tuner_type);
	EV_FM_DEFAULT(PN3030E_ADDR);
}

PN_VOID EV_INIT_TOP(PN_U8 pn_type, PN_U8 tuner_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, TOP05_E, 0x17);     // PN3030EV Tuner enable
	PN3030_Byte_Write(PN3030E_ADDR, TOP06_E, 0x10);
	PN3030_Byte_Write(PN3030E_ADDR, TOP12_E, 0xF5);     // 0x00 --> 0xF5 Not Used PAD disable 2007.07.09 PnpNetwork.

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
	{
		if(REF_FREQ_DEF == 24.576)
			PN3030_Byte_Write(PN3030E_ADDR, TOP07_E, 0x28); // PN3030EV FEC Clock 4MHZ
		else
			PN3030_Byte_Write(PN3030E_ADDR, TOP07_E, 0x08); // PN3030EV FEC Clock 4MHZ
	}
		
	if(tuner_type == MAX2172)
	{
		PN3030_Byte_Write(PN3030E_ADDR, TOP07_E, 0x28); // PN3030EV MRC
		PN3030_Byte_Write(PN3030E_ADDR, TOP10_E, 0x0C); // 2008.08.21 PnpNetwork IF AGC PAD control
	}	
}

PN_VOID EV_INIT_COMM(PN_U8 pn_type, PN_U8 tuner_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR,0x10, 0x91);  // PN3030EV MRC 0x10[0] "0":Normal "1":MRC
	PN3030_Byte_Write(PN3030E_ADDR,0xAF, 0x07);  // by terry 2011.12.26 Fast scan
	PN3030_Byte_Write(PN3030E_ADDR,0xE1, 0x02);
	PN3030_Byte_Write(PN3030E_ADDR,0x3B, 0x3C);  //scan_mode[1:0]

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x35, 0x7B);
		PN3030_Byte_Write(PN3030E_ADDR,0x36, 0x68);	// 0x67 -> 0x68 by terry 2011.11.09
		PN3030_Byte_Write(PN3030E_ADDR,0x3A, 0x44);	// 0dB echo: 0x0E -> 0x0F by terry 2009.09.14 ->0x44 by terry 2011.12.22
		PN3030_Byte_Write(PN3030E_ADDR,0x55,0x0D);	// CO_DC_DEPTH
	}
	else if(tuner_type == MAX2172)
	{
		PN3030_Byte_Write(PN3030E_ADDR,COMM_35, 0x8B);
		PN3030_Byte_Write(PN3030E_ADDR,COMM_36, 0x67);  // 0x67 -> 0x68 by terry 2011.11.09
		PN3030_Byte_Write(PN3030E_ADDR,COMM_3A, 0x1E);  // 0x44 -> 0x3B
	}

	PN3030_Byte_Write(PN3030E_ADDR,0x3C,0x20);   // Power save Symbol offset
	PN3030_Byte_Write(PN3030E_ADDR,0x3D,0x0B);   // Power save user start
	PN3030_Byte_Write(PN3030E_ADDR,0x3D,0x09);   // Power save user start

}

PN_VOID EV_INIT_HOST(PN_U8 pn_type, PN_U8 tuner_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);

	if(tuner_type == MAX2172)
	{
		PN3030_Byte_Write(PN3030E_ADDR, 0x10, 0x00);
		PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_BAUD, 0x32);
		PN3030_Byte_Write(PN3030E_ADDR, RF_E_CON, 0x09);
	}
	
	PN3030_Byte_Write(PN3030E_ADDR, 0x13, 0x16);
	PN3030_Byte_Write(PN3030E_ADDR, 0x14, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0x19, 0x0A);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF0, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF1, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF2, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF3, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF4, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF5, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF6, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF7, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0xF8, 0x00);
	
	PN3030_Byte_Write(PN3030E_ADDR, 0xFB, 0xFF);   //Glitch
	
	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
		PN3030_Byte_Write(PN3030E_ADDR, 0x7D, 0x06);
	
	/*  // PLL_OUT 192MHz used by terry 2011.07.19
	PN3030_Byte_Write(PN3030E_ADDR, 0x18, 0xC0);
	PN3030_Byte_Write(PN3030E_ADDR, 0x19, 0x7F);
	PN3030_Byte_Write(PN3030E_ADDR, 0x1a, 0x8b);
	PN3030_Byte_Write(PN3030E_ADDR, 0x1b, 0x96);
	PN3030_Byte_Write(PN3030E_ADDR, 0x1c, 0xac);
	PN3030_Byte_Write(PN3030E_ADDR, 0x07, 0xf8);    */
	
	PN3030_Byte_Write(PN3030E_ADDR, 0x77, 0x14);   // 2009.3.30 SPI Interface mode.
	//PN3030_Byte_Write(PN3030E_ADDR, 0x77, 0x15); // 2009.3.30 HPI Interface mode.
}

PN_VOID EV_INIT_OFDM(PN_U8 pn_type, PN_U8 tuner_type, PN_FLOAT frequency)
{
	PN_U8 INV_MODE;      /// Parameter value Add by terry 07.02.13 [FREQ_PNCO_HL,FREQ_NPCO_HH, WAGC_COM,AGC_MODE,POST_INIT,AGC_CYCLE]
	PN_U8 FREQ_PNCO_HL;  /// PNCO setting value                                                                         
	PN_U8 FREQ_PNCO_HH;  /// PNCO setting value
	PN_U8 PWM_COM;       /// AGC0,AGC1 source select
	PN_U8 WAGC_COM;      /// NULL_SEL_MODE
	PN_U8 AGC_MODE;      /// Addr 0x53 setting variable for variety tuner & application
	PN_U8 POST_INIT;     /// POST AGC Gain value manual setting 
	PN_U8 AGC_CYCLE;     /// AGC_CYCLE_TRK 
	PN_U8 AGC_CYCLE_L;   /// AGC_CYCLE_TRK L-Band
	PN_U8 AGC_CYCLE_ACK; /// AGC_CYCLE_ACK
	PN_U8 AGC_CYCLE_L_ACK; /// AGC_CYCLE_ACK
	PN_FLOAT adc_sampling;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	switch(tuner_type)
	{
		case PNS3030D:
		case PNS3030A:
			INV_MODE = 1;           // '0':Normal '1':Spectrum inversion
			PWM_COM = 0x08;
			FREQ_PNCO_HL = 0x00;    // IF Frequency = Zero IF
			FREQ_PNCO_HH = 0x00;
			WAGC_COM = 0x02;        // NULL_SEL_MODE
			AGC_MODE = 0x06;        
			POST_INIT = 0x09;
			AGC_CYCLE = 0x10;       // AGC_CYCLE_TRK[Band-III] 
			AGC_CYCLE_L = 0x10;     // AGC_CYCLE_TRK[L-Band]
			AGC_CYCLE_ACK = 0x06;  
			AGC_CYCLE_L_ACK = 0x06;  
			break;
		case MAX2172:
			INV_MODE = 0;
			PWM_COM = 0x08;
			FREQ_PNCO_HL = 0x00;    // IF Frequency = 2.048MHz
			FREQ_PNCO_HH = 0x40;
			WAGC_COM = 0x02;        // NULL_SEL_MODE
			AGC_MODE = 0x17; 
			POST_INIT = 0x09;
			AGC_CYCLE = 0x06;       // AGC_CYCLE_TRK 
			AGC_CYCLE_L = 0x0C;     // AGC_CYCLE_TRK 
			AGC_CYCLE_ACK = 0x00;   // Min '3'
			break;
		default:
			break;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  OFDM Parameter Set by terry 07.01.30 /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR,0x11,0x80); // Tr_mode masking (exception tr_mode1)
	PN3030_Byte_Write(PN3030E_ADDR,0x12,0x04); // LOCK_SEL[6:5],CFREQ_ACK[4:3],CFREQ_TRK[2:1]
	
	PN3030_Byte_Write(PN3030E_ADDR,0x13,0x72); // coarse frequency offset Updated[100KHz] by terry 2009.05.21
	PN3030_Byte_Write(PN3030E_ADDR,0x14,0x63); // coarse frequency offset Updated[100KHz] by terry 2009.05.21
	PN3030_Byte_Write(PN3030E_ADDR,0x15,0x64); // coarse frequency offset Updated[100KHz] by terry 2009.05.21
	PN3030_Byte_Write(PN3030E_ADDR,0x16,0x6C); // CLOCK_POWER_RATIO[7:0]

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x1A,0xB4);
//		PN3030_Byte_Write(PN3030E_ADDR,0x1B,0x96);
//		PN3030_Byte_Write(PN3030E_ADDR,0x1C,0x00);
//		PN3030_Byte_Write(PN3030E_ADDR,0x1E,0x6E);
		PN3030_Byte_Write(PN3030E_ADDR,0x20,0x5B); // TLOOP_SEL: '0' -> '1' by terry 07.02.12
		PN3030_Byte_Write(PN3030E_ADDR,0x38,0x01); // Zero IF Enable - PNS3030 90610
	}
	else if(tuner_type == MAX2172)
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x1A,0x24); // NULL_CNT_MODE
		PN3030_Byte_Write(PN3030E_ADDR,0x1B,0x16);
		PN3030_Byte_Write(PN3030E_ADDR,0x1C,0x01);
		PN3030_Byte_Write(PN3030E_ADDR,0x1E,0x52);
		PN3030_Byte_Write(PN3030E_ADDR,0x20,0x5C); // TLOOP_SEL: '0' -> '1' by terry 07.02.12
	}

    PN3030_Byte_Write(PN3030E_ADDR,0x25,0x09); // PLF_SEL_TIME[4:3], PLF_SEL_AK[2],PLF_SEL_TK[1]
    PN3030_Byte_Write(PN3030E_ADDR,0x44,0x00 | (POST_INIT)); // POST AGC Add by terry 07.01.30
	PN3030_Byte_Write(PN3030E_ADDR,0x46,0xA0); // POST_HTH[15:0] '8000' -> '4000' Add by terry 07.01.30
	PN3030_Byte_Write(PN3030E_ADDR,0x47,0x0F);
	PN3030_Byte_Write(PN3030E_ADDR,0x48,0xB8); // POST_LTH[15:0] '7000' -> '3500'->'3000' Add by terry 07.01.30
	PN3030_Byte_Write(PN3030E_ADDR,0x49,0x0B);

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
		PN3030_Byte_Write(PN3030E_ADDR,PRE_TH, 0x58);
	else if(tuner_type == MAX2172)
		PN3030_Byte_Write(PN3030E_ADDR,0x54, 0x24);
	
	if(frequency > BANDIII)	 // PRE_CYL_TRK[7:0] Band-III=0x10, L-Band=0x20
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x55,AGC_CYCLE_L_ACK); // PRE_CYL_ACK[7:0]
		PN3030_Byte_Write(PN3030E_ADDR,0x56,AGC_CYCLE_L);
	}
	else
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x55,AGC_CYCLE_ACK); // PRE_CYL_ACK[7:0]
		PN3030_Byte_Write(PN3030E_ADDR,0x56,AGC_CYCLE);
	}

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x59,0x51); // PRE_DIV_TRK[7:6],PRE_DIV_ACK[5:4],PRE_DIFF_TH[2:0]
                                          // 2007.04.19 by terry   0x59: 0xA1 --> 0x51  
		PN3030_Byte_Write(PN3030E_ADDR,0x5A,0x1B); // PRE_EXT_TRK[5:3],PRE_EXT_ACK[2:0]   // 0x1C->0x1B by terry 2011.12.22
	}
	else if(tuner_type == MAX2172)
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x59,0xA1); // PRE_DIV_TRK[7:6],PRE_DIV_ACK[5:4],PRE_DIFF_TH[2:0]
		PN3030_Byte_Write(PN3030E_ADDR,0x5A,0x25); // PRE_EXT_TRK[5:3],PRE_EXT_ACK[2:0]
	}

	PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x1C); // TOUT_TH_ACK[5:3],TOUT_TH_TRK[2:0] 0x6A:0x24 -> 0x1C
	PN3030_Byte_Write(PN3030E_ADDR,0x6B,0x2D); // TLOCK_TRK[7:6]='0',TLOCK_ACK[5:4]='2',TOUT_TH_SEL[2:0]='5'
	PN3030_Byte_Write(PN3030E_ADDR,0x6D,0x00); // TIME_FLT_SEL: '1' -> '0' by terry 07.02.12
	PN3030_Byte_Write(PN3030E_ADDR,0x85,0x32); // PLF_IG_ACK[7:4], TLF_IG[3:0]

	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
		PN3030_Byte_Write(PN3030E_ADDR,0x8B,0x34); // AFC_OFF_TRK: '0' -> '1'  by terry 07.02.12 // Crystal ppm caution
	                                      // 0x8B[5:4]AFC_TIME_SEL "2" TLock & Set on time "3" Long time & Set on time
	else if(tuner_type == MAX2172)
		PN3030_Byte_Write(PN3030E_ADDR,0x8B,0x24);
										  
	PN3030_Byte_Write(PN3030E_ADDR,0x8C,0x09); // TII
	PN3030_Byte_Write(PN3030E_ADDR,0x8D,0x0C); // TII_USER_RANK_TH[6:0]
	PN3030_Byte_Write(PN3030E_ADDR,0x8E,0x01); // TII Accumulation set: 1 frame -> 2 frame by terry 07.04.09

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////// 	
	PN3030_Byte_Write(PN3030E_ADDR,INV33_E, 0x00 | (INV_MODE<<1)); // Spectrum Inv mode select
	PN3030_Byte_Write(PN3030E_ADDR,AGC0_E_EN,0x00 | (AGC_MODE));   // AGC0 pin control & TGL_MSB & PWM Inv
	PN3030_Byte_Write(PN3030E_ADDR,0x6F,0x00 | (WAGC_COM));        // NULL_SEL_MODE
	PN3030_Byte_Write(PN3030E_ADDR,AGC_E_SEL,PWM_COM);             // AGC0, AGC1 source select
	
	///////////////////ADD for ADC Clock sampling//////////////////////////////
	switch(tuner_type)
	{
		case PNS3030D:
		case PNS3030A:
		{	
			adc_sampling = ADC_SAMPLING_FOR_DEMOD;
			if(adc_sampling == 8.0){
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); //TNCO
			
			    PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x3c,0x4B); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3d,0x37); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3e,0x89); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3f,0x41); //TNCO
				
#if 1   // 30KHz offset by terry 2011.12.09
				PN3030_Byte_Write(PN3030E_ADDR,0x40,0x8F); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x41,0xC2); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xF5); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x00); //PNCO
#endif		
			}
			else if (adc_sampling  > 8.0 &&  adc_sampling  < 9.0 ){	
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); //TNCO
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x3c,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3d,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3e,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3f,0x40); //TNCO
				
#if 1   // 30KHz offset by terry 2011.12.09
				PN3030_Byte_Write(PN3030E_ADDR,0x40,0x00); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x41,0x00); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xF0); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x00); //PNCO
#endif
			}
			else if(adc_sampling == 9.0){
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x21); //TNCO
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x3c,0xB5); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3d,0x14); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3e,0x41); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3f,0x3A); //TNCO
				
#if 1   // 30KHz offset by terry 2011.12.09
				PN3030_Byte_Write(PN3030E_ADDR,0x40,0x0D); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x41,0x74); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xDA); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x00); //PNCO
#endif
			}
			else if(adc_sampling  > 9.0 &&  adc_sampling  < 10.0){
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x31); //TNCO
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x3c,0x69); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3d,0x03); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3e,0x9D); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3f,0x36); //TNCO
				
#if 1   // 30KHz offset by terry 2011.12.09
				PN3030_Byte_Write(PN3030E_ADDR,0x40,0xCC); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x41,0xCC); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xCC); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x00); //PNCO
#endif
			}
			break;
		}
		case MAX2172:
		{
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); //TNCO
			    
				PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x3c,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3d,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3e,0x00); //TNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x3f,0x40); //TNCO
			break;
		}
		default:
			break;
	}
	
    /////////////////////////////////////////////////////////////////////////////
	if(tuner_type == MAX2172)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,LOOP03_E_HL,0x00 | (FREQ_PNCO_HL)); //PNC0[23:16]
		PN3030_Byte_Write(PN3030E_ADDR,LOOP03_E_HH,0x00 | (FREQ_PNCO_HH)); //PNC0[31:24]
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////// PNS3030 Co-channel Function Parameter Add by terry 07.01.30 ////////////////////////////// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
// 2008.08.01 OFDM parameter change by terry
	PN3030_Byte_Write(PN3030E_ADDR,0x94,0x08); // PNS3030   NULL_CHECK_TIME2[5:3], NULL_CHECK_TIME1[2:0] 0x11 -> 0x08

	PN3030_Byte_Write(PN3030E_ADDR,0x98,0x05); // CO_HTH_M2  2008.11.17 by terry
	PN3030_Byte_Write(PN3030E_ADDR,0x99,0x03); // CO_HTH_M3  2008.11.17 by terry
	PN3030_Byte_Write(PN3030E_ADDR,0x9B,0xCF); // SET_SKIP_CNT_M2  2009.03.07 by terry
	PN3030_Byte_Write(PN3030E_ADDR,0x9C,0x10); // SET_SKIP_CNT_M3  2007.04.26 by terry
	PN3030_Byte_Write(PN3030E_ADDR,0x9D,0x1C); // SET_SKIP_CNT_M4  2009.03.07 by terry

	PN3030_Byte_Write(PN3030E_ADDR,0x9F,0x32); //CO_PWR_STRONG_TH
	PN3030_Byte_Write(PN3030E_ADDR,0xA0,0x90); //CO_PWR_WEAK_TH
	
	PN3030_Byte_Write(PN3030E_ADDR,0xA2,0xA0); // CO_AVR_Pwr
	PN3030_Byte_Write(PN3030E_ADDR,0xA3,0x08); // CO_Man_Mode

	PN3030_Byte_Write(PN3030E_ADDR,0xA4,0x01); // CO_LOCK_MODE[1:0] [0]3 [1]7 [2] 15 [3]31

	PN3030_Byte_Write(PN3030E_ADDR,0xA8,0xF6); // BAND_MAX[11:0] '2550'
	PN3030_Byte_Write(PN3030E_ADDR,0xA9,0x89);
	PN3030_Byte_Write(PN3030E_ADDR,0xAA,0x0C); // BAND_MINH[9:0] '200'
	PN3030_Byte_Write(PN3030E_ADDR,0xAB,0x32); // BAND_MINL[9:0] '200'

	PN3030_Byte_Write(PN3030E_ADDR,0xAC,0x14); // S_AVERAGE_PWR_MIN[7:0] '2'->'20  2007.04.26 by terry
	PN3030_Byte_Write(PN3030E_ADDR,0xAD,0x09); // W_AVERAGE_PWR_MIN[7:0] '2'->'9'  2007.04.26 by terry

	PN3030_Byte_Write(PN3030E_ADDR,0xAE,0xFF); // CO_BAND_MAX_TH[7:0] '255'
	PN3030_Byte_Write(PN3030E_ADDR,0xEB,0x6B); // AGC2 pin Polarity set
	
	
///////////////////////////////////////////////////////////////////////////////////
	if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))
	{
		PN3030_Byte_Write(PN3030E_ADDR,0x93,0x10);   // CO_LTH Masking
		PN3030_Byte_Write(PN3030E_ADDR,0x94,0x29);   // NULL_CHK_TIME: 0x08 -> 0x29
		PN3030_Byte_Write(PN3030E_ADDR,0xA2,0x50);   // CO_AVR_PWR: 0xA0 -> 0x50
		PN3030_Byte_Write(PN3030E_ADDR,0xA4,0x02);   // CO_LOCK_CNT: 7 -> 15
		PN3030_Byte_Write(PN3030E_ADDR,0xAF,0x01);   // Strong Co_channel re-check
	}
}

PN_VOID EV_INIT_FEC(PN_U8 pn_type, PN_U8 tuner_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FIC_E_TH, 0x5F);       // FIC crc error threshold
	PN3030_Byte_Write(PN3030E_ADDR, FIC_E_PRD, 0x7F);      // FIC crc error check period
	PN3030_Byte_Write(PN3030E_ADDR, MSC_E_CERPRD, 0x07);
	PN3030_Byte_Write(PN3030E_ADDR, DD_E_TOPCON, 0xA0);
	PN3030_Byte_Write(PN3030E_ADDR, MPEGIF_E_CON1, 0xD0);  // RS Decoder TEI Enable
	PN3030_Byte_Write(PN3030E_ADDR, SOFT_RST_E_CON, 0x07); // MSC1, MSC0, FIC Memory Soft Reset enable
	PN3030_Byte_Write(PN3030E_ADDR, FEC_E_CON0, 0x10);     // Power save mode: OFF
	PN3030_Byte_Write(PN3030E_ADDR, VITPRD_E_MODE, 0xA0);  // BER monitoring period by terry
	
	//PN3030_Byte_Write(PN3030E_ADDR, 0x7D, 0x10);           // [4] "1": MSC memory(4K+3K) //20110117 by terry
	
	PN3030_Byte_Write(PN3030E_ADDR, 0xE2, 0x05);           // Zero Ber Period Set: 2^18Bit
	PN3030_Byte_Write(PN3030E_ADDR, 0x31, 0x70);   // 0x31[2] "1" Header 4 byte mode "0" 3 byte mode
	                                          //     [1] "1" MSC0 Header Enabel "0" Disable  
}

PN_VOID EV_FM_INIT(PN_U8 pn_type, PN_U8 tuner_type)
{
	EV_INIT_TOP(PN3030E_ADDR, tuner_type);
	EV_INIT_HOST(PN3030E_ADDR, tuner_type);
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, 0x6A, 0x0D);

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, 0x2B, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, 0x30, 0x80);
	
	PN3030_Byte_Write(PN3030E_ADDR, TOP06_E, 0x04);

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, INV33_E, 0x02);
	PN3030_Byte_Write(PN3030E_ADDR, FM3F, 0x10);
	PN3030_Byte_Write(PN3030E_ADDR, FM44, 0x09); // 2007.12.12 by terry  0x0D-> 0x09

	PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x41); //0x41 ==Auto, 0x43 == MONO,  0x45  == STEREO
	PN3030_Byte_Write(PN3030E_ADDR, FMF1, 0xE4);
	PN3030_Byte_Write(PN3030E_ADDR, FMF3, 0x01);
	PN3030_Byte_Write(PN3030E_ADDR, FMF4, 0x20);

	PN3030_Byte_Write(PN3030E_ADDR, FM6D, 0x88);
	PN3030_Byte_Write(PN3030E_ADDR, FMD2, 0x70);
	PN3030_Byte_Write(PN3030E_ADDR, FMF8, 0x8C);
	PN3030_Byte_Write(PN3030E_ADDR, PRE_TH, 0x88); // Pre-AGC Threshold setting   // 2010.08.09 Rev2. by terry 0x20 -> 0x88
	PN3030_Byte_Write(PN3030E_ADDR, 0x55, 0x06);   // 2010.05.03 by terry
	PN3030_Byte_Write(PN3030E_ADDR, 0x56, 0x06);   // 2010.05.03 by terry
	PN3030_Byte_Write(PN3030E_ADDR, 0x59, 0x51);   // 2010.05.03 by terry
	PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x1C);   // 2010.05.03 by terry

        if ((tuner_type == PNS3030D) || (tuner_type == PNS3030A))// IF_Frequency = 500KHz
	{
		PN3030_Byte_Write(PN3030E_ADDR, 0x38, 0x00);
		PN3030_Byte_Write(PN3030E_ADDR, LOOP03_E_HL, 0xA0);
		PN3030_Byte_Write(PN3030E_ADDR, LOOP03_E_HH, 0x0F);   //PNCO sampling 8.192MHz
		PN3030_Byte_Write(PN3030E_ADDR, AGC0_E_EN,   0x06);
	}
	else if(tuner_type == MAX2172)  // IF_Frequency = 1.943MHz
	{
		PN3030_Byte_Write(PN3030E_ADDR, LOOP03_E_HL, 0xB8);
		PN3030_Byte_Write(PN3030E_ADDR, LOOP03_E_HH, 0x3C);
	}

	PN3030_Byte_Write(PN3030E_ADDR, FM85, 0x3A);
	PN3030_Byte_Write(PN3030E_ADDR, AGC_E_SEL, 0x08);

	PN3030_Byte_Write(PN3030E_ADDR, FME5, 0x07);
	PN3030_Byte_Write(PN3030E_ADDR, FMF6, 0xA7); // 32K sampling[0xA7], 128k sampling[0x27]
	PN3030_Byte_Write(PN3030E_ADDR, FMED, 0x01);

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	//PN3030_Byte_Write(PN3030E_ADDR, SOFT_RST_E_CON, 0x00); // MSC1, MSC0, FIC Memory Soft Reset disable
	//PN3030_Byte_Write(PN3030E_ADDR, DD_E_TOPCON, 0xB0);
	PN3030_Byte_Write(pn_type, DD_E_TOPCON, 0xA0);
	PN3030_Byte_Write(PN3030E_ADDR, FM_CON02, 0x05);
}

PN_VOID EV_FM_DEFAULT(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FM44, 0x09);
	PN3030_Byte_Write(PN3030E_ADDR, FM45, 0x04);
	PN3030_Byte_Write(PN3030E_ADDR, FM46, 0xA0);
	PN3030_Byte_Write(PN3030E_ADDR, FM47, 0x0F);
	PN3030_Byte_Write(PN3030E_ADDR, FM48, 0xB8);
	PN3030_Byte_Write(PN3030E_ADDR, FM49, 0x0B);
	PN3030_Byte_Write(PN3030E_ADDR, FM4A, 0x40);
	PN3030_Byte_Write(PN3030E_ADDR, FM4B, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, FM85, 0x35);

	PN3030_Byte_Write(PN3030E_ADDR, FMD2, 0x98);
	PN3030_Byte_Write(PN3030E_ADDR, FME5, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, FME7, 0x08);
	PN3030_Byte_Write(PN3030E_ADDR, FME8, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, FME9, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, FMF5, 0x64);
	PN3030_Byte_Write(PN3030E_ADDR, FMF9, 0x00);

	PN3030_Byte_Write(PN3030E_ADDR, FMF6, 0x27); // 32K sampling
	PN3030_Byte_Write(PN3030E_ADDR, FMED, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, FMD7, 0x49); // RDS test
	PN3030_Byte_Write(PN3030E_ADDR, FMF1, 0x04); // RDS test
	PN3030_Byte_Write(PN3030E_ADDR, FMF4, 0x20); // TRANS MODE SET

	//PN3030_Reg_Page_Sel(PN3030E_ADDR, DPN3030E_ADDR, D_E_PAGE);
	//PN3030_Byte_Write(PN3030E_ADDR, 0x7D, 0x10);           // [4] "1": MSC memory(4K+3K) //20110117 by terry
}

//////////////////////////////////
//  PN3030EV Soft Reset Module   //
//////////////////////////////////
PN_VOID EV_SOFT_RESET(PN_U8 pn_type, PN_U8 flag)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0x48|flag); // FEC reset enable
	PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0xC9); // OFDM & FEC Soft reset
}

//////////////////////////////////
//  PN3030EV Interrupt Setup   //
//////////////////////////////////
PN_VOID EV_INTERRUPT_SETUP(PN_U8 pn_type)
{
	//PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, TOP09_E, 0x00); ///[6]INT1 [5]INT0 - 1: Input mode, 0: Output mode
	PN3030_Byte_Write(PN3030E_ADDR, TOP11_E, 0x00); ///[2]INT1 PAD disable [1]INT0 PAD disable

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_CON00, 0x00); ///[5:3]INT1 out sel [2:0] INI0 out sel - 0:Level, 1:Toggle, 2:"0", 3:"1"
	
  //PN3030_Byte_Write(PN3030E_ADDR, INT_E_CON01, 0x08); ///[3] Interrupt status register clear condition - 0:read data by memory access 1:status register access
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_CON01, 0x00); ///[3] Interrupt status register clear condition - 0:read data by memory access 1:status register access
	
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_CON02, 0x33); ///[5]INT1 pol [4]INT0 pol - 0:Active High, 1:Active Low [3:0] Period = (INT_TIME+1)/8.192MHz
}

PN_VOID EV_UNMASK_INTERRUPT(PN_U8 pn_type, PN_U8 mem_mode, PN_U8 on_off)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	switch(mem_mode)
	{
		case PN_MSC0_MEN:
		case PN_FIDC_MEN:
		case PN_MSC0_RDS_MEN:
			PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK62, 0x0E, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x04, 0);
			PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK64, 0x0E, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x04, 0);
			break;
		case PN_MSC1_MEN:
			PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK62, 0x70, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x04, 0);
			PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK64, 0x70, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x04, 0);
			break;
		case PN_MSC1_FM_MEN:
			PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK62, 0x70, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x04, 0);
			PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK64, 0x70, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x04, 0);
			break;
		case PN_FIC_MEN:
			PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK62, 0x01, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x04, 0);
			PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK64, 0x01, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x04, 0);
			break;
		case PN_FEC_MEN:
			PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x07, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT0_E_MASK63, 0x04, 0);
			PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x07, on_off);
                        PN3030_Interrupt_Write(PN3030E_ADDR, INT1_E_MASK65, 0x04, 0);
			break;
		default:
			break;
	}
}

/////////////////////////////////////
//  PN3030EV Power Control Module   //
/////////////////////////////////////
/* Power Saver Mode --> all power down (excluding interface and map) */
PN_VOID EV_STANDBY_CONTROL(PN_U8 pn_type, PN_S32 stanby)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	if(stanby)
	{
		PN3030_Byte_Write(PN3030E_ADDR, TOP05_E, 0x07);   // INT_CLK_SEL: OSC_CLK
		PN3030_Byte_Write(PN3030E_ADDR, TOP06_E, 0x11);   // STANDBY = 1 (standby set = 1)
	}
	else
	{
		PN3030_Byte_Write(PN3030E_ADDR, TOP05_E, 0x17);   // INT_CLK_SEL: ADC_OSC_IN
		PN3030_Byte_Write(PN3030E_ADDR, TOP06_E, 0x10);   // STANDBY = 0 (standby reset = 0)
	}
}

/* SLEEP Mode --> all power down */
PN_VOID EV_SLEEP_CONTROL(PN_U8 pn_type, PN_U8 sleep, PN_U8 tuner_type, PN_FLOAT frequency)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	if(sleep)
	{
		PN3030_Byte_Write(PN3030E_ADDR, TOP06_E, 0x12); // SLEEP = 1 (sleep set = 1)
	}
	else  // Insert PN3030EV H/W reset control function
	{
		EV_OPERATE(pn_type);
		EV_INIT(pn_type, tuner_type,frequency);
	}
}

PN_VOID EV_RESET_FIC_MEM(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FIC_E_DDCON, 0x10); // FIC memory control register clear.
}

PN_VOID EV_RESET_MSC0_MEM(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00);  // MSC0 memory control register clear.
}

PN_VOID EV_RESET_MSC1_MEM(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00);  // MSC1 memory control register clear.
}

PN_VOID EV_CLEAR_MSC0_SUBCH(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_SUBCH3, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_SUBCH4, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_PKTCH5, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_PKTCH6, 0x00);
}

PN_VOID EV_CLEAR_MSC1_SUBCH(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, ACTIVE_CH_SET, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_SUBCH0, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_SUBCH1, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_SUBCH2, 0x00);
}

PN_VOID EV_SETUP_FIC_MEM(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FIC_E_DDCON, 0x10); /// auto user clr, get fic
	PN3030_Byte_Write(PN3030E_ADDR, FIC_E_DDCON, 0x12); /// FIC enable
}

PN_U16 EV_SETUP_MSC0_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen)
{
	PN_U8 msc0_int_usel = 1; /// 0: auto&uclr, 1: user set only
	PN_U8 msc0_en = 1;       /// 0: disable,   1: enable 
	PN_U8 int_type = 0;      /// 0: CIF end,   1: Threshold
	PN_U8 data1, data2;
	PN_U16 msc0_length = 0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);

	if(int_type)
	{
		PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_INTTH_H,(threshold>>8) & 0x0F);
		PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_INTTH_L,(threshold & 0xFF));
	}
	else
	{
		PN3030_Byte_Read(PN3030E_ADDR, MSC0_E_TSIZE_H, &data1);
		PN3030_Byte_Read(PN3030E_ADDR, MSC0_E_TSIZE_L, &data2);
		msc0_length = (data1<<8) | data2;
	}

	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00 | (msc0_int_usel<<3) | (msc0_en<<2) | int_type);
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.

	return msc0_length;
}

PN_U16 EV_SETUP_MSC1_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen)
{
	PN_U8 msc1_length_off = 0;/// 0: subch+16-bit length, 1: subch
	PN_U8 msc1_header_on = 0; /// 0: disable for only one ts buffer, 1: enable for 2~3 ts buffer
	PN_U8 msc1_int_usel = 1;  /// 0: auto&uclr, 1: user set only
	PN_U8 msc1_en = 1;        /// 0: disable,   1: enable 
	PN_U8 int_type = 1;       /// 0: CIF end,   1: Threshold
	PN_U8 data1, data2;
	PN_U16 msc1_length = 0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);

	if(int_type)
	{
		PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_INTTH_H,(threshold>>8) & 0x1F);  // MSC1 Size set change by terry 2011.01.17
		PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_INTTH_L,(threshold & 0xFF));
	}
	else
	{
		PN3030_Byte_Read(PN3030E_ADDR, MSC1_E_TSIZE_H, &data1);
		PN3030_Byte_Read(PN3030E_ADDR, MSC1_E_TSIZE_L, &data2);
		msc1_length = (data1<<8) | data2;
	}

	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00 | (msc1_length_off<<5) | (msc1_header_on<<4) | (msc1_int_usel<<3) | (msc1_en<<2) | int_type);
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.

	return msc1_length;
}

PN_U16 EV_SETUP_MSC1_FM_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen)
{
	PN_U8 msc1_length_off = 0;/// 0: subch+16-bit length, 1: subch
	PN_U8 msc1_header_on = 0; /// 0: disable for only one ts buffer, 1: enable for 2~3 ts buffer
	PN_U8 msc1_int_usel = 1;  /// 0: auto&uclr, 1: user set only
	PN_U8 msc1_en = 1;        /// 0: disable,   1: enable 
	PN_U8 int_type = 1;       /// 0: CIF end,   1: Threshold
	PN_U16 msc1_length = 0;
	PN_U8 data1=0,data2=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);

	if(int_type)
	{
		PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_INTTH_H,(threshold>>8) & 0x0F);
		PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_INTTH_L,(threshold & 0xFF));

		PN3030_Byte_Write(PN3030E_ADDR, 0x45, 0xA0);
	}
	else
	{
		PN3030_Byte_Read(PN3030E_ADDR, MSC1_E_TSIZE_H, &data1);
		PN3030_Byte_Read(PN3030E_ADDR, MSC1_E_TSIZE_L, &data2);
		msc1_length = (data1<<8) | data2;
	}

	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00 | (msc1_length_off<<5) | (msc1_header_on<<4) | (msc1_int_usel<<3) | (msc1_en<<2) | int_type);
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.

	return msc1_length;
}

PN_U16 EV_SETUP_MSC0_RDS_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen)
{
	PN_U8 msc0_int_usel = 1; /// 0: auto&uclr, 1: user set only
	PN_U8 msc0_en = 1;       /// 0: disable,   1: enable
	PN_U8 int_type = 1;      /// 0: CIF end,   1: Threshold
	PN_U8 data1, data2;
	PN_U16 msc0_length = 0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);

	if(int_type)
	{
		PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_INTTH_H,(threshold>>8) & 0x0F);
		PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_INTTH_L,(threshold & 0xFF));
	}
	else
	{
		PN3030_Byte_Read(PN3030E_ADDR, MSC0_E_TSIZE_H, &data1);
		PN3030_Byte_Read(PN3030E_ADDR, MSC0_E_TSIZE_L, &data2);
		msc0_length = (data1<<8) | data2;
	}

	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00 | (msc0_int_usel<<3) | (msc0_en<<2) | int_type);
	PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.

	return msc0_length;
}


PN_VOID EV_SET_PATH_VIDEO_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on)
{
#if 1 // PC play	
	PN_U8 rs_pass = 1;
#else	// Audio Codec play
	PN_U8 rs_pass = 0;
#endif	
	subch = (channel_on << 7) | (rs_pass << 6) | subch;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_SUBCH0, subch);
	PN3030_Byte_Write(PN3030E_ADDR, ACTIVE_CH_SET, subch);
}

PN_VOID EV_SET_PATH_DATA_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on)
{
	PN_U8 rs_pass = 0;
	
	subch = (channel_on << 7) | (rs_pass << 6) | subch;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_SUBCH0, subch);
	PN3030_Byte_Write(PN3030E_ADDR, ACTIVE_CH_SET, subch);
	
	PN3030_Byte_Write(PN3030E_ADDR, 0xE1, (0x80 | subch));   // Zero Ber Monitoring channel set
}

PN_VOID EV_SET_PATH_AUDIO_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on)
{
	subch = (channel_on << 7) | subch;
	PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_SUBCH3, subch);
	PN3030_Byte_Write(PN3030E_ADDR, ACTIVE_CH_SET, subch);
	
	PN3030_Byte_Write(PN3030E_ADDR, 0xE1, (0x80 | subch));   // Zero Ber Monitoring channel set
}

PN_VOID EV_SET_PATH_PKT_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U16 pkt_addr)
{
	PN_U8 channel_on = 1;
	PN_U8 pkt_addr_l, pkt_addr_h;
	
	subch = (channel_on << 7) | subch;
	pkt_addr_l= ((PN_U8)pkt_addr & 0xff);
	pkt_addr_h= (pkt_addr >> 8) & 0x03;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_PKTCH5, subch);
	PN3030_Byte_Write(PN3030E_ADDR, PKTCH5_E_ADDRL, pkt_addr_l);
	PN3030_Byte_Write(PN3030E_ADDR, PKTCH5_E_ADDRH, pkt_addr_h);
	
	PN3030_Byte_Write(PN3030E_ADDR, 0xE1, (0x80 | subch));   // Zero Ber Monitoring channel set
}

PN_U16 EV_GET_SUBCH_SIZE(PN_U8 pn_type, PN_U8 subch)
{
	PN_U16 subch_size;
	PN_U8 ch_size_h, ch_size_l;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, SUBCH_E_MONCON0, (0x80 | subch));

	Delay_Ms(500);

	PN3030_Byte_Read(PN3030E_ADDR, SUBCH_E_MON3_H, &ch_size_h);
	PN3030_Byte_Read(PN3030E_ADDR, SUBCH_E_MON3_L, &ch_size_l);
	subch_size = ((ch_size_h & 0x07) << 8) | ch_size_l;

	return subch_size;
}

PN_VOID EV_SET_RECONFIGURATION(PN_U8 pn_type, PN_U8 subch, PN_U8 type, PN_U16 pkt_addr)
{
	PN_U8 rs_pass = 1;
	PN_U8 channel_on = 1;
	PN_U8 pack_en = 0;
	PN_U8 pkt_addr_l, pkt_addr_h;

	switch (type)
	{
		case 1: // VIDEO_SERVICE
			subch = (channel_on << 7) | (rs_pass << 6) | subch;
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH0_CON, subch);
			break;
		case 2: // AUDIO_SERVICE
			subch = (channel_on << 7) | subch;
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH3_CON, subch);
			break;
		case 3: // DATA_SERVICE
			subch = (channel_on << 7) | subch;
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH0_CON, subch);
			break;
		case 4: // PKT_SERVICE
			subch = (channel_on << 7) | (pack_en << 6) | subch;
			pkt_addr_l= ((PN_U8)pkt_addr & 0xff);
			pkt_addr_h= (pkt_addr >> 8) & 0x03;
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH5_L, subch);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH5_M, pkt_addr_l);
			PN3030_Byte_Write(PN3030E_ADDR, RECONFIG_SUBCH5_H, pkt_addr_h);
			break;
		default:
			break;
	}
}

extern PN_U8 frequency_scan_result[42];
PN_U32 STime=0, ETime=0, DTime=0, TTime=0, STimeMem =0;
#define SCAN_TRACE_MON
//#define MODE1_ONLY    // T-DMB에서만 적용 가능 Only Tr_Mode 1
#if 1
PN_S32 EV_CHANNEL_SCAN_CONTROL(PN_U8 pn_type, PN_S32 tuner_type, PN_FLOAT frequency)
{
	PN_U8 scan_done, OFDM_L=0, ccnt = 0, NULL_C=0, SCV_C=0;
	PN_U8 scan_pwr1=0, scan_pwr2=0, DAB_Mode=0xFF;//, DAB_Mode_Chk=0xFF;
	PN_U8 scan_flag = 0, pre_agc1=0, pre_agc2=0, pre_agc_mon=0, ASCV=0;
	PN_U16 SPower =0, PreGain=0, PreGainTH=0, PWR_TH = 0, ILoopTH =0;
	PN_U8 Cfreq_HTH = 0,Cfreq_LTH=0;
	PN_U8 i=0,j=0, m=0;
	PN_U8 varyLow=0,varyHigh=0;
	PN_U16 varyMon=0;
	PN_U8 MON_FSM=0, FsmCntChk=0;
	PN_U16 fail = 0x0000;
	PN_U8  FecResetCh=0xff;
	PN_U8 FEC_SYNC=0xFF,CoarseFreq=0xFF,NullChCnt=0;
	PN_U8 SamADCType=0;
	PN_U8 rdata0 =0, rdata1=0, rdata2=0, rdata3=0;
	PN_U8 frame_sync_cnt=0;
	PN_U8 Fic_Crc_Num=0;
	PN_U8 test_no = 0;
	PN_U8 CoCH_Chk = 0;
	PN_U8 RF00 = 0;
	PN_U8 SoftRST_Cnt = 0;
	PN_FLOAT fic_cer_chk = 0;
	PN_U8 MonFsm6Cnt = 0;
	PN_U16 NullLenMon=0, PostAgcMon=0;
	PN_U8 buf[64]={0,};
	PN_U8 f9x0f = 0,f9xfb = 0,ffx0f = 0, f6x17=0, f6x18=0, f6x37=0, f6x71=0, f6xce=0, f4x30, f4x3b;
	PN_U8 buf_p4[256] = {0, };
	PN_U8 buf_p6[256] = {0, };
	PN_U8 buf_p7[256] = {0, };
	PN_U8 buf_p9[256] = {0, };
	PN_U8 buf_pf[256] = {0, };
	PN_U16 evcnt=0;
	//STime = PN_SysTickGetTime();
	DEBUG_INFO_HI(TRACE_DAB_CTRL,"entry");
	
	
	/* SCAN Power for ADC sampling clock  */
	if((BANDII < frequency) && ( frequency < BANDIII)) /* Band-III */
	{
		DEBUG_INFO_HI(TRACE_DAB_CTRL,"band-III");
		/* MRC version */
		if(((frequency > 171.5)&&(frequency <= 171.6))||((frequency > 180.0)&&(frequency <= 181.0))
		||((frequency > 188.5)&&(frequency <= 189.1))||((frequency > 195.5)&&(frequency <= 196.5)))
		{
			SamADCType = ADC_8_214MHZ;
		}
		else if((frequency > 196.5)&&(frequency <= 197.0))
		{
			SamADCType = ADC_8_158MHZ;
		}
		else if((frequency > 213.0)&&(frequency <= 213.5))
		{
			SamADCType = ADC_8_170MHZ;
		}
		else
		{
			SamADCType = ADC_8_192MHZ;
		}
	}
	else if(frequency > BANDUHF) 							/* L-Band  */
	{
		DEBUG_INFO_HI(TRACE_DAB_CTRL,"L-band");
		if((frequency > 1458.0)&&(frequency <= 1459.0))
		{
			SamADCType = ADC_8_231MHZ;    /* MRC & Sensitivity optimize by Terry 2013.06.20*/
		}
		else if((frequency > 1473.0)&&(frequency <= 1474.0))
		{
			SamADCType = ADC_8_226MHZ;    /* MRC & Sensitivity optimize by Terry 2013.06.20*/
		}
		else if((frequency > 1475.0)&&(frequency <= 1476.0))
		{
			SamADCType = ADC_8_153MHZ;    /* MRC & Sensitivity optimize by Terry 2013.06.20*/
		}
		else
		{
			SamADCType = ADC_8_192MHZ;
		}
	}
	else
	{
		{
			DEBUG_INFO_HI(TRACE_DAB_CTRL,"?-band");
		}
		SamADCType = ADC_8_192MHZ;
	}

	PN3030_Reg_Page_Sel(PN3030E_ADDR,COMM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR,0x55,0x0D);   // CO_DC_DEPTH

	if((BANDII < frequency) && ( frequency < BANDIII)) /* Band-III */
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, 0x54, 0x7B);
		PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x1B);
		PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);  // BPF BW
		PN3030_Byte_Write(PN3030E_ADDR, 0x4B, 0x8F);
	}
	else    // L-Band
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x1C);
		PN3030_Byte_Write(PN3030E_ADDR, 0x54, 0x78);
		PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);  // BPF BW
		PN3030_Byte_Write(PN3030E_ADDR, 0x4B, 0x8F);
	}
#ifdef MODE1_ONLY   // 국내 T-DMB에서만 Enable 해야함
	PN_U8 DAB_Mode_Chk=0xFF;
	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR,0x11,0x8E); // Tr_mode masking (exception tr_mode1)
#endif

	CHANGE_TUNER_FREQ(tuner_type, frequency);			/* Tuner Freq. Change */

	EV_SOFT_RESET(PN3030E_ADDR,PN_OFDM_FEC);   /* PNS3030 SOFT_RESET */

	fail = 0xFFFF;
	FecResetCh = 0xff;
	//ETime = PN_SysTickGetTime();
	//DTime = ETime - STimeMem;

	#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
		//ETime = PN_SysTickGetTime();
		//DTime = ETime - STime;
		memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
		memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
		memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
		memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
		memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
		memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
		memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
		memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
		memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
		memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
		memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
		memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
		memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
		memcpy(&frequency_scan_result[32], &Fic_Crc_Num,   sizeof(PN_U8));
		memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
	#endif

	DEBUG_INFO_HI(TRACE_DAB_CTRL,"start loop");
	while(1)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, SCANDONE_E, &scan_done);  /* Scan-done flag & scan-out flag check */

		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);		    /* Scan-Power monitoring */
        PN3030_Byte_Read(PN3030E_ADDR, 0x37, &scan_pwr1);
		PN3030_Byte_Read(PN3030E_ADDR, 0x38, &scan_pwr1);
		PN3030_Byte_Read(PN3030E_ADDR, 0x39, &scan_pwr2);
		SPower = (scan_pwr2<<8)|scan_pwr1;

		if(scan_done != 0xff)
		{
			NULL_C = 0;
			SCV_C = 0;
			DEBUG_INFO_HI(TRACE_DAB_CTRL,"scan_done != 0xff");

			PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, 0x53, &pre_agc_mon);
			PN3030_Byte_Write(PN3030E_ADDR, 0x53, (pre_agc_mon | 0x80));	 /* Pre-AGC Gain monitoring One-shot */
			PN3030_Byte_Read(PN3030E_ADDR, 0x66, &pre_agc1);
			PN3030_Byte_Read(PN3030E_ADDR, 0x67, &pre_agc2);
			PreGain = (pre_agc2<<2)|(pre_agc1&0x03);
			PN3030_Byte_Read(PN3030E_ADDR, 0x27, &DAB_Mode);	 			/* DAB TX Mode monitoring */
			DAB_Mode = (DAB_Mode & 0x30)>>4;
			switch(DAB_Mode)
			{
				case 0:
						PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0xB4);
						break;
				case 1:
						PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x44);
						break;
				case 2:
						PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x04);
						break;
				case 3:
						PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x84);
						break;
				default:
						PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0xB4);
						break;
			}

/*/////////////////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////    [주의]IF_Amp gain에 따라 값이 바뀜    /////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////////////////////////////*/
			/* ADC Sampling Clock에 따른 Autoscan Threshold value*/
			if(frequency > 250.)
				PreGainTH = 355;
			else
				PreGainTH = 390;

			switch(DAB_Mode)
			{
                case 0:
					PWR_TH = 6500;
					ILoopTH = 70;
					Cfreq_HTH = 206;
					Cfreq_LTH = 55;
					break;
				case 1:
					PWR_TH = 950;
					ILoopTH = 70;
					Cfreq_HTH = 242;
					Cfreq_LTH = 14;
					break;
				case 2:
					PWR_TH = 320;
					ILoopTH = 70;
					Cfreq_HTH = 248;
					Cfreq_LTH = 8;
					break;
				case 3:
					PWR_TH = 4000;
					ILoopTH = 70;
					Cfreq_HTH = 230;
					Cfreq_LTH = 26;
					break;
				default:
					PWR_TH = 6500;
					ILoopTH = 70;
					Cfreq_HTH = 206;
					Cfreq_LTH = 55;
					break;
			}

			if(scan_done == 0x01)            /* Not DAB signal channel */
			{
				DEBUG_INFO_HI(TRACE_DAB_CTRL,"Not DAB signal channel");
				scan_flag = 0;
				fail = 0xFF01;
				PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x1C);
				#ifdef SCAN_TRACE_MON /* AutoScan Monitoring by terry 2010.05.13 */
					//ETime = PN_SysTickGetTime();
					//DTime = ETime - STime;
					memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
					memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
					memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
					memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
					memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
					memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
					memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
					memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
					memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
					memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
					memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
					memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
					memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
					memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
					memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
					memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
				#endif
				DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
				return scan_flag;	    /* Auto-scan result return */
			}
			else if(scan_done == 0x03)  /* DAB signal channel */
			{
				DEBUG_INFO_HI(TRACE_DAB_CTRL,"found DAB signal channel");
				PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x1C);
				PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);    /* coarse freq */
				PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);
				PN3030_Byte_Read(PN3030E_ADDR, 0x00, &RF00);
				RF00 = (RF00 & 0xC0)>>6;

			#ifdef MODE1_ONLY   // 국내 T-DMB에서만 Enable 해야함
				if(DAB_Mode > 0)   /* Tr_mode detection miss for T-DMB [Only Tr_Mode 1인 경우에만 사용가능한 조건] */
				{
					scan_flag = 0;
					fail = 0xF002;
					#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
						ETime = PN_SysTickGetTime();
						DTime = ETime - STime;
						memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
						memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
						memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
						memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
						memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
						memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
						memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
						memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
						memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
						memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
						memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
						memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
						memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
						memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
						memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
					#endif
					DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
					return scan_flag;	 /* Auto-scan result return  */
				}
			#endif
				if(RF00 == 0x02)
				{
					PreGainTH = PreGainTH * 0.7;
				}
				
				if((PreGain < PreGainTH) && (PreGain != 0))   /* PreAGC Gain threshold check */
				{
					scan_flag = 0;
					fail = 0xFF04;
					#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
						//ETime = PN_SysTickGetTime();
						//DTime = ETime - STime;
						memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
						memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
						memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
						memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
						memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
						memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
						memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
						memcpy(&frequency_scan_result[23], &RF00, 		sizeof(PN_U8));
						memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
						memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
						memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
						memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
						memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
						memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
						memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
					#endif
					DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);

					return scan_flag;
				}
				else
				{
					for(m =0; m<16; m++)
					{
						DEBUG_INFO_HI(TRACE_DAB_CTRL,"m=%d, PreGain=%d",m,PreGain);
						
						PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);
						PN3030_Byte_Read(PN3030E_ADDR, 0x00, &RF00);
						RF00 = (RF00 & 0xC0)>>6;
						if((RF00 == 0x02) && (m>10))   // ACR
						{
							if((SPower<(PWR_TH/4)) && (SPower != 0))
							{
								scan_flag = 0;
								fail = 0xF303;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &RF00, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;
							}
						}
						else   // Normal And Sensitivity
						{
							if((SPower<PWR_TH) && (SPower != 0))
							{
								scan_flag = 0;
								fail = 0xFF03;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &RF00, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d, SPower=%d, PWR_TH=%d",fail,scan_flag,SPower,PWR_TH);
								return scan_flag;
							}
						}

						///// test code by terry 2011.07.21
						PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);
						PN3030_Byte_Read(PN3030E_ADDR, 0x00, &RF00);
						RF00 = (RF00 & 0xC0)>>6;

						PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
						PN3030_Byte_Read(PN3030E_ADDR, 0xB1, &rdata0);
						PN3030_Byte_Read(PN3030E_ADDR, 0xB5, &rdata1);
						PN3030_Byte_Read(PN3030E_ADDR, 0xB6, &rdata2);
						if((rdata0&0x01) && ((((rdata2 & 0x07)<<8) | (rdata1 & 0xFF))==0) && (CoCH_Chk > 14) && (RF00 == 2)&& (m>14))  // test by terry 2011.11.08
						{
							scan_flag = 0;
							fail = 0x8888;
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
								//ETime = PN_SysTickGetTime();
								//DTime = ETime - STime;
								memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
								memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
								memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
								memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
								memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
								memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
								memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
								memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
								memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
								memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
							#endif
							DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
							return scan_flag;  /* Auto-scan result return */
						}
						if((rdata0&0x01) && ((((rdata2 & 0x07)<<8) | (rdata1 & 0xFF))==0))
						{
							CoCH_Chk++;
						}

						PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);
						PN3030_Byte_Read(PN3030E_ADDR, 0x00, &RF00);
						RF00 = (RF00 & 0xC0)>>6;
						if((SPower<PWR_TH) && (RF00 != 0x02) && (SPower != 0) && (m>13))  // C/N channel
						{
							scan_flag = 0;
							fail = 0xFF33;
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
								//ETime = PN_SysTickGetTime();
								//DTime = ETime - STime;
								memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
								memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
								memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
								memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
								memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
								memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
								memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
								memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
								memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
								memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
							#endif
							DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
							return scan_flag;
						}

						#ifdef MODE1_ONLY_   // Tr_mode 1 only
						PN3030_Byte_Read(PN3030E_ADDR, 0x37, &MON_FSM);
						if(((MON_FSM & 0x07) >= 0x02) && (m>14))
						{
							PN3030_Byte_Read(PN3030E_ADDR, 0x27, &DAB_Mode_Chk);	 /* DAB TX Mode monitoring */
							DAB_Mode_Chk = (DAB_Mode_Chk & 0x30)>>4;
							if(DAB_Mode != DAB_Mode_Chk)
							{
								scan_flag = 0;
								fail = 0xF000;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									ETime = PN_SysTickGetTime();
									DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;
							}
						}
						#endif

						if(m>14)
						{
							scan_flag = 1;
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
								//ETime = PN_SysTickGetTime();
								//DTime = ETime - STime;
								memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
								memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
								memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
								memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
								memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
								memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
								memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
								memcpy(&frequency_scan_result[24], &ASCV, 		sizeof(PN_U8));
								memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
								memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
								memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
								memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
								memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
							#endif

							break;
						}
						Delay_Ms(10);   /* 10ms로 맞춰줘야 함 */
					}

					if(scan_flag == 1)
					{
						m=RF00;
						for(i=0; i < ILoopTH; i++)
						{
							Delay_Ms(10);   /* 10ms로 맞춰줘야 함 */

							PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
							PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);
							PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &varyLow);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &varyHigh);
							varyMon = ((varyHigh & 0x1f) << 8) + varyLow;
							if(((CoarseFreq  < Cfreq_HTH) && (CoarseFreq  > Cfreq_LTH)) && (varyMon > 140))
							{
								SoftRST_Cnt++;
								PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
								PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
								PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
								do
								{
									PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
									PN3030_Byte_Read(PN3030E_ADDR, SCANDONE_E, &scan_done);  /* Scan-done flag & scan-out flag check */
									PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);		    /* Scan-Power monitoring */
									PN3030_Byte_Read(PN3030E_ADDR, 0x38, &scan_pwr1);
									PN3030_Byte_Read(PN3030E_ADDR, 0x39, &scan_pwr2);
									SPower = (scan_pwr2<<8)|scan_pwr1;
								}while((scan_done == 0x00) || (scan_done == 0xFF));
							}

							PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);
							PN3030_Byte_Read(PN3030E_ADDR, 0x00, &RF00);
							RF00 = (RF00 & 0xC0)>>6;
							if((SPower<PWR_TH) && (SPower>0) && (RF00 != 0x02) && (i > 25) && (((CoarseFreq  > Cfreq_HTH) || (CoarseFreq  < Cfreq_LTH))))  /* Scan Power Threshold  */
							{
								scan_flag = 0;
								fail = 0xFF13;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &RF00, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;
							}
							else if((SPower<(PWR_TH*2)) && (SPower != 0) && (RF00 == 0x02) && (i > 35) && (((CoarseFreq  > Cfreq_HTH) || (CoarseFreq  < Cfreq_LTH))))
							{
								scan_flag = 0;
								fail = 0xF403;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &RF00, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;
							}
							else
							{
								scan_flag = 1;
							}

							PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
							PN3030_Byte_Read(PN3030E_ADDR, 0x30, &ASCV);
							ASCV = ASCV&0x0F;
							if((SCV_C > 4) && (ASCV > 9))
							{
								scan_flag = 0;
								fail = 0xFF98;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;  /* Auto-scan result return */
							}
							else if((SCV_C > 6) && (ASCV > 8))
							{
								scan_flag = 0;
								fail = 0xFF88;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;  /* Auto-scan result return */
							}
							else if(((SCV_C > 8) && (ASCV > 7)) && (i > 15))         // ASCV count
							{
								scan_flag = 0;
								fail = 0xFF08;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;  /* Auto-scan result return */
							}
							if(ASCV > 7)
							{
								SCV_C++;
							}

							#ifdef MODE1_ONLY  // Tr_mode 1 only
							PN3030_Byte_Read(PN3030E_ADDR, 0x37, &MON_FSM);
							if(((MON_FSM & 0x07) >= 0x02) && (i > 25))
							{
								PN3030_Byte_Read(PN3030E_ADDR, 0x27, &DAB_Mode_Chk);	 /* DAB TX Mode monitoring */
								DAB_Mode_Chk = (DAB_Mode_Chk & 0x30)>>4;
								if(DAB_Mode != DAB_Mode_Chk)
								{
									scan_flag = 0;
									fail = 0xF100;
									#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										ETime = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
										memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
										memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
									#endif
									DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
									return scan_flag;
								}
							}
							#endif

							/*//////////////////////// FSM Monitoring check////////////////////////////////*/
							PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
							PN3030_Byte_Read(PN3030E_ADDR, 0x37, &MON_FSM);
							MON_FSM = MON_FSM & 0x07;

							if((MON_FSM == 1) && (PreGain < 550) && (SPower < 3000))
							{
								FsmCntChk++;
								if((NullChCnt > 14) && (frequency < 250.))
									FsmCntChk += 3;
							}
							if((MON_FSM == 1) && (FsmCntChk > 20) && (ccnt < 2) &&(i > 30))
							{
								scan_flag = 0;
								fail = 0xFF0A;

								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &NullChCnt,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								FsmCntChk = 0;

								return scan_flag;	/* Auto-scan result return */
							}
							/*///////////////////////////////////////////////////////////////////////////////*/
							/*///////////////////////// Coarse Freq. check///////////////////////////////////*/
							/*///////////////////////////////////////////////////////////////////////////////*/
							PN3030_Byte_Read(PN3030E_ADDR, 0x17, &ccnt);	/* Coarse count check */
							ccnt &= 0x1F;

							PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);

							PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &varyLow);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &varyHigh);
							varyMon = ((varyHigh & 0x1f) << 8) + varyLow;

							PN3030_Field_Write(PN3030E_ADDR, NULL1C_E, 0x10, 0x10);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL26, &rdata1);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL27, &rdata2);
							NullLenMon = ((rdata2 & 0x0f) << 8) + rdata1;

							PN3030_Field_Write(PN3030E_ADDR, 0x44, 0x80, 0x80);
							PN3030_Byte_Read(PN3030E_ADDR, 0x4C, &rdata0);
							PN3030_Byte_Read(PN3030E_ADDR, 0x4D, &rdata1);
							PostAgcMon = ((rdata1 & 0x01)<<8) + rdata0;

							if((MON_FSM == 6) && (ccnt == 1) && (MonFsm6Cnt > 3) && (i > 15))
							{
								scan_flag = 0;     /* OFDM_Lock & FEC_Sync OK */
								fail = 0xFFF0;
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//ETime = PN_SysTickGetTime();
									//DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
									memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
									memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
								#endif
								DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
								return scan_flag;
							}
							if((MON_FSM == 6) && (ccnt == 1) && ((NullLenMon == 0) || (PostAgcMon > 170) || (PostAgcMon < 65)))
							{
								MonFsm6Cnt++;
							}

							if(ccnt > 1)
							{
								test_no++;
								if(((CoarseFreq  > Cfreq_HTH) || (CoarseFreq  < Cfreq_LTH)) && (varyMon < 140))
								{
									for(j=0;j<40;j++)
									{
										Delay_Ms(10);   /* 10ms로 맞춰줘야 함 */
										PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0x12, &OFDM_L);
										PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
										PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &varyLow);
										PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &varyHigh);
										varyMon = ((varyHigh & 0x1f) << 8) + varyLow;
										if((OFDM_L&0x80) && (varyMon > 0))
										{
											PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
											PN3030_Byte_Write(PN3030E_ADDR,0x54,0x58);
											PN3030_Reg_Page_Sel(PN3030E_ADDR,RF_E_PAGE);  // RF_AGC speed
											PN3030_Byte_Write(PN3030E_ADDR, 0x4B, 0x80);  // BPF BW
											PN3030_Reg_Page_Sel(PN3030E_ADDR,COMM_E_PAGE);
											PN3030_Byte_Write(PN3030E_ADDR,0x55,0x15);   // CO_DC_DEPTH
											break;
										}
									}
									if(OFDM_L&0x80)
									{
										PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0xFB, &FEC_SYNC);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTH, &rdata0);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTL, &rdata1);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERH, &rdata2);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERL, &rdata3);
										if(((rdata0<<8) + rdata1) != 0)
										{
											fic_cer_chk = (PN_FLOAT)((PN_FLOAT)((rdata2 << 8) + rdata3) / (PN_FLOAT)((rdata0<<8) + rdata1))* 1000.;
										}
										else
										{
											fic_cer_chk = 1000.;
										}


										FEC_SYNC = FEC_SYNC & 0x03;
										if(FEC_SYNC == 0x03)
										{
											if((fic_cer_chk > 195) && (varyMon < 180))  // fic cer threshold fix
											{
												scan_flag = 0;
												fail = 0xF770;
											}
											else
											{
												scan_flag = 1;     /* OFDM_Lock & FEC_Sync OK */
												fail = 0xFF70;
											}

											#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
												//ETime = PN_SysTickGetTime();
												//DTime = ETime - STime;
												memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
												memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
												memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
												memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
												memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
												memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
												memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
												memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
												memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
												memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
												memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
												memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
												memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
											#endif
											DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
											return scan_flag;
										}
										else
										{
											PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
											PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);    /* coarse freq */

											PN3030_Reg_Page_Sel(PN3030E_ADDR,FEC_E_PAGE);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTH, &rdata0);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTL, &rdata1);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERH, &rdata2);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERL, &rdata3);
											if(((rdata0<<8) + rdata1) != 0)
											{
												fic_cer_chk = (PN_FLOAT)((PN_FLOAT)((rdata2 << 8) + rdata3) / (PN_FLOAT)((rdata0<<8) + rdata1))* 1000.;
											}
											else
											{
												fic_cer_chk = 1000.;
											}

											fic_cer_chk = (PN_FLOAT)((PN_FLOAT)((rdata2 << 8) + rdata3) / (PN_FLOAT)((rdata0<<8) + rdata1))* 1000.;

											scan_flag = 0;
											fail = 0xFF72;    /* FEC_Sync miss */

											if((fic_cer_chk < 195) && (varyMon < 180))  // fic cer threshold fix
											{
												scan_flag = 1;
												fail = 0xF772;

											#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
												//ETime = PN_SysTickGetTime();
												//DTime = ETime - STime;
												memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
												memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
												memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
												memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
												memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
												memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
												memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
												memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
												memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
												memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
												memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
												memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
												memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
											#endif
											DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
											return scan_flag;
											}
										}
									}
									else
									{
										PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);    /* coarse freq */
										scan_flag = 0;     /* OFDM_Unlock */
										fail = 0xFF0B;
									}
									#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//ETime = PN_SysTickGetTime();
										//DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
										memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
										memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
									#endif
									DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
									return scan_flag;                        /* Auto-scan result return	*/
								}
								else
								{
									PN3030_Reg_Page_Sel(PN3030E_ADDR,OFDM_E_PAGE);
									PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
									PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
									SoftRST_Cnt++;
									do
									{
										PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, SCANDONE_E, &scan_done);  /* Scan-done flag & scan-out flag check */
										PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);		    /* Scan-Power monitoring */
										PN3030_Byte_Read(PN3030E_ADDR, 0x38, &scan_pwr1);
										PN3030_Byte_Read(PN3030E_ADDR, 0x39, &scan_pwr2);
										SPower = (scan_pwr2<<8)|scan_pwr1;
									}while((scan_done == 0x00) || (scan_done == 0xFF));
								}
							}
						}
						fail = 0xFF0C;
						scan_flag = 0;
						#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
							//ETime = PN_SysTickGetTime();
							//DTime = ETime - STime;
							memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
							memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
							memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
							memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
							memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
							memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
							memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
							memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
							memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
							memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
							memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
							memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
							memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
							memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
							memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
						#endif
						DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = %04x, scan_flag=%d",fail,scan_flag);
						return scan_flag;
					}
				}
			}
		}
	}
	fail = 0xFF0D;
	#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
		//ETime = PN_SysTickGetTime();
		//DTime = ETime - STime;
		memcpy(&frequency_scan_result[12], &fail,     	sizeof(PN_U16));
		memcpy(&frequency_scan_result[14], &i, 	     	sizeof(PN_U8));
		memcpy(&frequency_scan_result[15], &j, 	      	sizeof(PN_U8));
		memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[17], &SPower,  	sizeof(PN_U16));
		memcpy(&frequency_scan_result[19], &PreGain,  	sizeof(PN_U16));
		memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8));
		memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
		memcpy(&frequency_scan_result[23], &m, 			sizeof(PN_U8));
		memcpy(&frequency_scan_result[24], &SoftRST_Cnt, 		sizeof(PN_U8));
		memcpy(&frequency_scan_result[25], &FsmCntChk,  sizeof(PN_U8));
		memcpy(&frequency_scan_result[26], &frame_sync_cnt,		sizeof(PN_U8));
		memcpy(&frequency_scan_result[27], &FEC_SYNC,   sizeof(PN_U8));
		memcpy(&frequency_scan_result[28], &DTime,      sizeof(PN_U32));
		memcpy(&frequency_scan_result[32], &DAB_Mode,   sizeof(PN_U8));
		memcpy(&frequency_scan_result[33], &varyMon,   sizeof(PN_U16));
	#endif
	DEBUG_INFO_HI(TRACE_DAB_CTRL,"fail = 0xFF0D");
	return scan_flag;     /* Auto-scan result return */
}
#endif

PN_S32 MAX2172_CHANNEL_SCAN_CONTROL(PN_U8 pn_type, PN_S32 tuner_type, PN_FLOAT frequency)
{
	PN_U8 scan_done, OFDM_L=0, ccnt = 0, NULL_C=0, SCV_C=0;
	PN_U8 scan_pwr1=0, scan_pwr2=0, DAB_Mode=0, DAB_Mode_Chk =0xFF;
	PN_U8 scan_flag = 0, pre_agc1=0, pre_agc2=0, pre_agc_mon=0, ASCV=0;
	PN_U16 SPower =0, PreGain=0, PreGainTH=0, PWR_TH = 0, ILoopTH =0; 
	PN_U8 Cfreq_HTH = 0,Cfreq_LTH=0;
	PN_U8 i=0,j=0, m=0;
	PN_U8 varyLow,varyHigh;
	PN_U16 varyMon;
	PN_U8 MON_FSM, FsmCntChk=0;
	PN_U8 test0,test1;
	PN_U16 NullLengthMon;
	PN_U16 fail = 0;
	PN_U8 FEC_SYNC=0xFF,CoarseFreq=0xFF, NullTh=0xFF,NullChCnt=0;
	PN_U8 FecResetCh=0xff;
	
	PN_U8 rdata0 =0, rdata1=0, rdata2=0, rdata3=0;
	PN_U8 test_no = 0;
	PN_U8 SoftRST_Cnt = 0;
	PN_FLOAT fic_cer_chk = 0;
	PN_U16 ConstVary=0;

	//일단삭제//STime = PN_SysTickGetTime();

	CHANGE_TUNER_FREQ(tuner_type, frequency);	// Tuner Freq. Change

	//일단삭제, 변수가많음//WRITE_TUNER_REG(pn_type,0x60,0x08,0xB8);  // BB_BW[2:0] Min value set
	//일단삭제AGC_CON_TUNER(pn_type, MAX2172, frequency, 0);	// LNA control
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, 0x54, 0x54); // Pre-AGC Threshold setting

	EV_SOFT_RESET(pn_type, PN_OFDM_FEC);   // PN3030E SOFT_RESET

	fail = 0xFFFF;	
	FecResetCh = 0xff;
	
#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
		//일단삭제//ETime = PN_SysTickGetTime();
		//DTime = ETime - STime;
		memcpy(&frequency_scan_result[12], &fail,	sizeof(PN_U16));
		memcpy(&frequency_scan_result[14], &i,		sizeof(PN_U8));
		memcpy(&frequency_scan_result[15], &j,		sizeof(PN_U8));
		memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
		memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
		memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[23], &m,		sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[24], &ASCV,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[26], &ccnt,	sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[28], &DTime,	sizeof(PN_U32));
		memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
#endif
	
	while(1)
	{			
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, SCANDONE_E, &scan_done); // Scan-done flag & scan-out flag check

		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);		   // Scan-Power monitoring
		PN3030_Byte_Read(PN3030E_ADDR, 0x38, &scan_pwr1);
		PN3030_Byte_Read(PN3030E_ADDR, 0x39, &scan_pwr2);
		SPower = (scan_pwr2<<8)|scan_pwr1;

		if(scan_done != 0xff)
		{
			NULL_C = 0;
			SCV_C = 0;
			PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, 0x53, &pre_agc_mon);
			PN3030_Byte_Write(PN3030E_ADDR, 0x53, (pre_agc_mon | 0x80)); 	// Pre-AGC Gain monitoring One-shot
			PN3030_Byte_Read(PN3030E_ADDR, 0x66, &pre_agc1);
			PN3030_Byte_Read(PN3030E_ADDR, 0x67, &pre_agc2);
			PreGain = (pre_agc2<<2)|(pre_agc1&0x03);
			PN3030_Byte_Read(PN3030E_ADDR, 0x27, &DAB_Mode); // DAB TX Mode monitoring
			DAB_Mode = (DAB_Mode & 0x30)>>4;
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////	  [주의]IF_Amp gain에 따라 값이 바뀜	//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
			if(frequency > 250.)
				PreGainTH = 2;		 
			else
				PreGainTH = 5;

			switch(DAB_Mode)
			{
				case 0:
					PWR_TH = 1100;
					ILoopTH = 70;
					Cfreq_HTH = 206;
					Cfreq_LTH = 55;
					break;
				case 1:
					PWR_TH = 700;
					ILoopTH = 70;
					Cfreq_HTH = 242;
					Cfreq_LTH = 14;
					break;
				case 2:
					PWR_TH = 250;
					ILoopTH = 70;
					Cfreq_HTH = 248;
					Cfreq_LTH = 8;
					break;
				case 3:
					PWR_TH = 1100;
					ILoopTH = 70;
					Cfreq_HTH = 230;
					Cfreq_LTH = 26;
					break;
				default:
					PWR_TH = 1100;
					ILoopTH = 70;
					Cfreq_HTH = 206;
					Cfreq_LTH = 55;
					break;
			}
			
			if(scan_done == 0x01)			 // Not DAB signal channel
			{
				scan_flag = 0;
				fail = 0xFF01;	
				
			#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
				//일단삭제//ETime = PN_SysTickGetTime();
				//DTime = ETime - STime;
				memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
				memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
				memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
				memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
				memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
				memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
				memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
				memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
				memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
				memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
				memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
				memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
				memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
				memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
				memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
				memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
			#endif		
				
				return scan_flag;	 // Auto-scan result return 
			}
			else if(scan_done == 0x03)				// DAB signal channel
			{
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);	 //coarse freq
							
								
				if(SPower<PWR_TH)  // Scan Power Threshold [Exception Max217x]
				{																													  //삼성전기 PreGain[460]
					scan_flag = 0;
					fail = 0xFF03;	
					
				#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
						//일단삭제//ETime = PN_SysTickGetTime();
						DTime = ETime - STime;
						memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
						memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
						memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
						memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
						memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
						memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
						memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
						memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
						memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
						memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
						memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
						memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
				#endif					
					return scan_flag;  // Auto-scan result return 
				}
				else
				{
					if ((PreGain <= PreGainTH)||(PreGain==0))
					{
						scan_flag = 0;
						fail = 0xFF04;	
						
					#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
							//일단삭제//ETime = PN_SysTickGetTime();
							DTime = ETime - STime;
							memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
							memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
							memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
							memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
							memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
							memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
							memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
							memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
					#endif	
						return scan_flag;
					}
					else
					{
						for(m =0; m<20; m++)
						{
							if(SPower < (PWR_TH/10))
							{
								scan_flag = 0;
								fail = 0xFF05;

							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//일단삭제//ETime = PN_SysTickGetTime();
									DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
							#endif								
								return scan_flag;
							}
							
							PN3030_Byte_Read(PN3030E_ADDR, 0x1C, &NullTh);
							PN3030_Byte_Write(PN3030E_ADDR, 0x1C, (NullTh | 0x10));
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL26, &test0);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL27, &test1);
							NullLengthMon = ((test1&0x0F)<<8)|test0;	
																				
							if(NullLengthMon == 0)
								NullChCnt++;
								
							if((NullChCnt > 14) && (m > 17)&& (PreGain < 510)) //삼성전기[450],PNP[410]
							{
								scan_flag = 0;
								fail = 0xFF06;	
								
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//일단삭제//ETime = PN_SysTickGetTime();
									DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
							#endif	
								return scan_flag;							
							}
							else if(m>16)
							{
								fail = 0x1111;
								scan_flag=1;
								break;
							}							
							Delay_Ms(10);
						}
					}
					if(scan_flag == 1)
					{						
						for(i=0; i<ILoopTH; i++)
						{
							Delay_Ms(10);

							PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
							PN3030_Byte_Read(PN3030E_ADDR, 0x30, &ASCV);
							ASCV = ASCV&0x0F;
							if(ASCV > 9)
							{
								scan_flag = 0;
								fail = 0xFF98;	
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//일단삭제//ETime = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
								#endif	
					
								return scan_flag;  /* Auto-scan result return */
							}
							else if((SCV_C > 1) && (ASCV > 8))
							{
								scan_flag = 0;
								fail = 0xFF88;	
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//일단삭제//ETime = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
								#endif	
					
								return scan_flag;  /* Auto-scan result return */
							}										
							else if(((SCV_C > 1) && (ASCV > 7)) && (i > 10))		 // ASCV count
							{
								scan_flag = 0;
								fail = 0xFF08;	
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//일단삭제//ETime = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
								#endif	
					
								return scan_flag;  /* Auto-scan result return */
							}								
							if(ASCV > 6)
							{
								SCV_C++;		
							}	
							
							PN3030_Byte_Read(PN3030E_ADDR, 0x27, &DAB_Mode_Chk);  /* DAB TX Mode monitoring */
							DAB_Mode_Chk = (DAB_Mode_Chk & 0x30)>>4;				
							if(DAB_Mode != DAB_Mode_Chk)
							{
								scan_flag = 0;
								fail = 0xF100;	
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//일단삭제//ETime = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
								#endif	
								return scan_flag; 
							}
																	
							PN3030_Byte_Read(PN3030E_ADDR, 0x37, &MON_FSM);
							MON_FSM = MON_FSM & 0x07;	
							
							// FSM Monitoring check
							//일단삭제AGC_CON_TUNER(pn_type, MAX2172, frequency, 0);	// LNA control
							
							if((MON_FSM == 1) && (PreGain < 500) &&(SPower < 10000))  // SPower<30000: make an exception for Co-channel
							{
								FsmCntChk++;
								if(NullChCnt >= 12)
									FsmCntChk += 2;
							}
							if((MON_FSM == 1) && (FsmCntChk > 14))
							{
								scan_flag = 0;									
								fail = 0xFF0A;	
								
							#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
									//일단삭제//ETime = PN_SysTickGetTime();
									DTime = ETime - STime;
									memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
									memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
									memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
									memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
									memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[22], &NullChCnt,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
									memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
									memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
									memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
									memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
							#endif
								FsmCntChk = 0;									
								return scan_flag;	 // Auto-scan result return 
							}	
																
							/*///////////////////////////////////////////////////////////////////////////////*/
							/*///////////////////////// Coarse Freq. check///////////////////////////////////*/
							/*///////////////////////////////////////////////////////////////////////////////*/
							PN3030_Byte_Read(PN3030E_ADDR, 0x17, &ccnt); /* Coarse count check */
							PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);
							PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &varyLow);
							PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &varyHigh);
							varyMon = ((varyHigh & 0x1f) << 8) + varyLow; 
							ccnt &= 0x1F;

							if(ccnt > 1) 
							{
								test_no++;
								if(((CoarseFreq  > Cfreq_HTH) || (CoarseFreq  < Cfreq_LTH)) && (varyMon < 140))
								{
									for(j=0;j<40;j++)
									{
										Delay_Ms(10);	/* 10ms로 맞춰줘야 함 */
										PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0x12, &OFDM_L);
										PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
										PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &varyLow);
										PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &varyHigh);
										varyMon = ((varyHigh & 0x1f) << 8) + varyLow; 
										if((OFDM_L&0x80) && (varyMon > 0))
										{
											//일단삭제, 변수가많음//WRITE_TUNER_REG(pn_type,0x60,0x08,0xBB);  // BB_BW[2:0] Min value set
											PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
											PN3030_Byte_Write(PN3030E_ADDR, 0x54, 0x24);   // Pre_TH gain
											break;
										}
									}
									if(OFDM_L&0x80)
									{
										PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0xFB, &FEC_SYNC);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTH, &rdata0);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTL, &rdata1);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERH, &rdata2);
										PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERL, &rdata3);
										
										fic_cer_chk = (PN_FLOAT)((PN_FLOAT)((rdata2 << 8) + rdata3) / (PN_FLOAT)((rdata0<<8) + rdata1))* 1000.;
										
										FEC_SYNC = FEC_SYNC & 0x03;
										if(FEC_SYNC == 0x03)
										{											
											if(fic_cer_chk > 198)  // fic cer threshold fix 
											{
												scan_flag = 0;
												fail = 0xF770; 
											}
											else
											{
												scan_flag = 1;	   /* OFDM_Lock & FEC_Sync OK */
												fail = 0xFF70;	
											}
											
										#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
												//일단삭제//ETime = PN_SysTickGetTime();
												DTime = ETime - STime;
												memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
												memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
												memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
												memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
												memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
												memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
												memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
												memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
										#endif
											return scan_flag;
										}
										else 
										{
											PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
											PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);	 /* coarse freq */
											
											PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTH, &rdata0);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTL, &rdata1);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERH, &rdata2);
											PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERL, &rdata3);
											
											fic_cer_chk = (PN_FLOAT)((PN_FLOAT)((rdata2 << 8) + rdata3) / (PN_FLOAT)((rdata0<<8) + rdata1))* 1000.;
											
											scan_flag = 0;
											fail = 0xFF72;	  /* FEC_Sync miss */
											
											if(fic_cer_chk < 198)  // fic cer threshold fix
											{
												scan_flag = 1;
												fail = 0xF772; 
												
										#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
												//일단삭제//ETime = PN_SysTickGetTime();
												DTime = ETime - STime;
												memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
												memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
												memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
												memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
												memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
												memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
												memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
												memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
												memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
												memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
												memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
										#endif												
											return scan_flag;
											}										
										}
									}
									else
									{
										PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, 0x18, &CoarseFreq);	 /* coarse freq */
										scan_flag = 0;	   /* OFDM_Unlock */
										fail = 0xFF0B;	
									}	
								#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
										//일단삭제//Time = PN_SysTickGetTime();
										DTime = ETime - STime;
										memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
										memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
										memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
										memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
										memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
										memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
										memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
										memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
										memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
										memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
								#endif		
									return scan_flag;						 /* Auto-scan result return */
								}
								else
								{
									PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
									PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
									PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
									SoftRST_Cnt++;
									do
									{			
										PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
										PN3030_Byte_Read(PN3030E_ADDR, SCANDONE_E, &scan_done);	/* Scan-done flag & scan-out flag check */
										PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);			/* Scan-Power monitoring */
										PN3030_Byte_Read(PN3030E_ADDR, 0x38, &scan_pwr1);
										PN3030_Byte_Read(PN3030E_ADDR, 0x39, &scan_pwr2);
										SPower = (scan_pwr2<<8)|scan_pwr1;
									}while((scan_done == 0x00) || (scan_done == 0xFF)); 
								}
							}
						}						
						fail = 0xFF0C;	
						scan_flag = 0;
						
					#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
							//일단삭제//ETime = PN_SysTickGetTime();
							DTime = ETime - STime;
							memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
							memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
							memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
							memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
							memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
							memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
							memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
							memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
							memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
							memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
							memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
					#endif							
						return scan_flag;
					}
				}
			}
		}		
	}
	fail = 0xFF0D;	
			
#ifdef SCAN_TRACE_MON  /* AutoScan Monitoring by terry 2010.05.13 */
		//일단삭제//ETime = PN_SysTickGetTime();
		//DTime = ETime - STime;
		memcpy(&frequency_scan_result[12], &fail,		sizeof(PN_U16));
		memcpy(&frequency_scan_result[14], &i,			sizeof(PN_U8));
		memcpy(&frequency_scan_result[15], &j,			sizeof(PN_U8));
		memcpy(&frequency_scan_result[16], &scan_done,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[17], &SPower, 	sizeof(PN_U16));
		memcpy(&frequency_scan_result[19], &PreGain,	sizeof(PN_U16));	
		memcpy(&frequency_scan_result[21], &CoarseFreq, sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[22], &test_no,  sizeof(PN_U8));
		memcpy(&frequency_scan_result[23], &m,			sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[24], &ASCV,		sizeof(PN_U8));
		memcpy(&frequency_scan_result[25], &FsmCntChk,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[26], &ccnt,		sizeof(PN_U8)); 
		memcpy(&frequency_scan_result[27], &FEC_SYNC,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[28], &DTime,		sizeof(PN_U32));
		memcpy(&frequency_scan_result[32], &DAB_Mode,	sizeof(PN_U8));
		memcpy(&frequency_scan_result[33], &ConstVary,	 sizeof(PN_U16));
#endif		
	return scan_flag;						 // Auto-scan result return
}

#if 1
////////////////////////////////////////////
// PN3030EV OFDM Lock Status Check Module //
////////////////////////////////////////////
PN_S32 EV_OFDM_LOCK_STAT(PN_U8 pn_type, PN_U8 tuner_type, PN_U8 *tr_mode, PN_U8 check_time)
{
	PN_S32 i;
	PN_U8  lock_stat1, ofdm_lock, s_inv;
	PN_U8  xMonVariLow, xMonVariHigh, Coarse_Freq;
	PN_U16 ConstVary;
	PN_U16 Coarse_Freq_TH1, Coarse_Freq_TH2;

	for(i=0; i<check_time; i++)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, MON_E_OFDM1, &lock_stat1);
		*tr_mode = (lock_stat1 & 0x06) >> 1;
		ofdm_lock = lock_stat1 & BIT_MASK_0_E;
		s_inv = (lock_stat1 & BIT_MASK_3_E) >> 3;
		switch(*tr_mode)
		{
			case 0:
					PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0xB4);
					break;
			case 1:
					PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x44);
					break;
			case 2:
					PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x04);
					break;
			case 3:
					PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x84);
					break;
			default:
					PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0xB4);
					break;
		}

		if(lock_stat1 != 0xff)
		{
			if (ofdm_lock)
			{
				if(*tr_mode == 0)
				{
					Coarse_Freq_TH1 = 205;
					Coarse_Freq_TH2 = 55;
				}
				else if(*tr_mode == 1)
				{
					Coarse_Freq_TH1 = 242;
					Coarse_Freq_TH2 = 14;				
				}
				else if(*tr_mode == 2)
				{
					Coarse_Freq_TH1 = 248;
					Coarse_Freq_TH2 = 8;					
				}
				else
				{
					Coarse_Freq_TH1 = 230;
					Coarse_Freq_TH2 = 26;				
				}				
				// FALSE Lock check
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &xMonVariLow);
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &xMonVariHigh);
				ConstVary = ((xMonVariHigh & 0x1f) << 8) + xMonVariLow;  
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_CFREQ, &Coarse_Freq);
				
				PN3030_Byte_Write(PN3030E_ADDR,0x54,0x58);
				
				if((ConstVary > 145) && ((Coarse_Freq < Coarse_Freq_TH1) && (Coarse_Freq > Coarse_Freq_TH2)))
				{
					PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
					PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
				}
				else
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, FIC_E_PRD, 0x80);
					return PN_FN_OK;      
				}
			}
			else
			{
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x54,0x70);
			}
		}	
		Delay_Ms(50);
	}
	return PN_UNLOCK;
}
#endif

////////////////////////////////////////////
// PN3030EV OFDM Lock Status Check Module //
////////////////////////////////////////////
PN_S32 MAX2172_OFDM_LOCK_STAT(PN_U8 pn_type, PN_U8 tuner_type, PN_U8 *tr_mode, PN_U8 check_time)
{
	PN_U8 i;
	PN_U8  lock_stat1, ofdm_lock, s_inv;
	PN_U8  xMonVariLow, xMonVariHigh, Coarse_Freq;
	PN_U16 ConstVary;
	PN_U16 Coarse_Freq_TH1, Coarse_Freq_TH2;
	PN_U8 FEC_SYNC=0xff,scan_flag=0;
	PN_U8 LockStatCh = 0xff,FecResetCh=0xff;
	PN_U8 LockCntMon=0xff;
		
//	memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
//	memcpy(&frequency_scan_result[28], &LockCntMon, sizeof(PN_U8));	
	for(i=0; i<check_time; i++)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, MON_E_OFDM1, &lock_stat1);
		*tr_mode = (lock_stat1 & 0x06) >> 1;
		ofdm_lock = lock_stat1 & BIT_MASK_0_E;
		s_inv = (lock_stat1 & BIT_MASK_3_E) >> 3;

		if(lock_stat1 != 0xff)
		{
			LockStatCh = 0x99;
//			memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
			if (ofdm_lock)
			{
				if(*tr_mode == 0)
				{
					Coarse_Freq_TH1 = 205;
					Coarse_Freq_TH2 = 55;
				}
				else if(*tr_mode == 1)
				{
					Coarse_Freq_TH1 = 242;
					Coarse_Freq_TH2 = 14;				
				}
				else if(*tr_mode == 2)
				{
					Coarse_Freq_TH1 = 248;
					Coarse_Freq_TH2 = 8;					
				}
				else
				{
					Coarse_Freq_TH1 = 230;
					Coarse_Freq_TH2 = 26;				
				}				
				// FALSE Lock check
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR, PRE_TH, 0x24);		// Pre-AGC Threshold setting
				PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &xMonVariLow);
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &xMonVariHigh);
				ConstVary = ((xMonVariHigh & 0x1f) << 8) + xMonVariLow;  
				PN3030_Byte_Read(PN3030E_ADDR, MON_E_CFREQ, &Coarse_Freq);
				
				if((ConstVary > 145) && ((Coarse_Freq < Coarse_Freq_TH1) && (Coarse_Freq > Coarse_Freq_TH2)))
				{
					FecResetCh = 0x00;
					PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
					PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
					Delay_Ms(300);
				}
				PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
				PN3030_Byte_Read(PN3030E_ADDR, 0xFB, &FEC_SYNC);
				FEC_SYNC = FEC_SYNC & 0x03;
				if(FEC_SYNC == 0x03)
				{
					LockStatCh = 0x11;
					scan_flag = 1;     // OFDM_Lock & FEC_Sync
//					memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
				}
				else if(FEC_SYNC == 0x02)
				{
					Delay_Ms(50);
					LockStatCh = 0x22;
					scan_flag = 0;     // OFDM_Lock & FEC_Miss [Caution: Tr_Mode]
//					memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
				}
				else
				{
					Delay_Ms(50);
					LockStatCh = 0x33;
					scan_flag = 0;     // OFDM_Lock & FEC_Miss
//					memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
				}
				
				if(scan_flag == 1)
				{					
					LockCntMon = i;
//					memcpy(&frequency_scan_result[28], &LockCntMon, sizeof(PN_U8));	
					return PN_FN_OK; 
				}
				else
				{
				}
				LockCntMon = i;
//				memcpy(&frequency_scan_result[28], &LockCntMon, sizeof(PN_U8));	
				return PN_FN_OK; 
			}
			else		// OFDM_UnLock
			{
				LockStatCh = 0x44;	
//				memcpy(&frequency_scan_result[26], &LockStatCh, sizeof(PN_U8));	
			}
		}	
		Delay_Ms(50);
	}
	return PN_UNLOCK;
}

///////////////////////////////////////////////////////
// PN3030EV agc/time/coarse/ofdm lock status display //
///////////////////////////////////////////////////////
PN_VOID EV_ALL_LOCK_STAT(PN_U8 pn_type, PN_U8 *agc_lock, PN_U8 *coarse_lock, PN_U8 *time_lock, PN_U8 *ofdm_lock)
{
	PN_U8  lock_stat1, lock_stat2, tr_mode;
	PN_U8  xMonVariLow, xMonVariHigh, Coarse_Freq;
	PN_U16 ConstVary, Coarse_Freq_TH1, Coarse_Freq_TH2;
	PN_U8  OFDMLockChk = 0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_OFDM1, &lock_stat1);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_OFDM2, &lock_stat2);   // 2007.04.19

	*agc_lock = (lock_stat2 & BIT_MASK_5_E) >> 5;
	*time_lock = (lock_stat2 & BIT_MASK_4_E) >> 4;
	*coarse_lock = (lock_stat2 & BIT_MASK_3_E) >> 3;
	*ofdm_lock = lock_stat1 & BIT_MASK_0_E;
	tr_mode = (lock_stat1 & 0x06) >> 1;
	
	if(lock_stat1 & 0x01)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,0x54,0x58);
		PN3030_Reg_Page_Sel(PN3030E_ADDR, RF_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,0x4B,0x80);   // BPF BW
		OFDMLockChk = 1;
	}
	else
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,0x54,0x70);
		PN3030_Reg_Page_Sel(PN3030E_ADDR, RF_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,0x4B, 0x8F);   // BPF BW
		OFDMLockChk = 0;
	}

	// FALSE Lock check
	if(tr_mode == 0)
	{
		Coarse_Freq_TH1 = 205;
		Coarse_Freq_TH2 = 55;
	}
	else if(tr_mode == 1)
	{
		Coarse_Freq_TH1 = 242;
		Coarse_Freq_TH2 = 14;				
	}
	else if(tr_mode == 2)
	{
		Coarse_Freq_TH1 = 248;
		Coarse_Freq_TH2 = 8;					
	}
	else
	{
		Coarse_Freq_TH1 = 230;
		Coarse_Freq_TH2 = 26;				
	}
	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &xMonVariLow);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &xMonVariHigh);
	ConstVary = ((xMonVariHigh & 0x1f) << 8) + xMonVariLow;  
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_CFREQ, &Coarse_Freq);
	if((ConstVary>145) && ((Coarse_Freq<Coarse_Freq_TH1) && (Coarse_Freq>Coarse_Freq_TH2)) && (OFDMLockChk==1))
	{
		PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0x48); // PN3030EV SOFT_RESET enable
		PN3030_Byte_Write(PN3030E_ADDR,OFDM_E_CON, 0xC9); // PN3030EV SOFT_RESET disable
		OFDMLockChk = 0;
	}
}

///////////////////////////////////////////////////////////////
// PN3030EV- Tr-mode, null length, IQ, variance, SNR display //
///////////////////////////////////////////////////////////////
PN_VOID EV_OFDM_STAT(PN_U8 pn_type, PN_U8 *tr_mode, PN_U16 *null_len, PN_U8 *iq_inv, PN_U16 *con_vari, PN_S32 *snr_bar, PN_S32 *snr, PN_S32 tuner_type, PN_S8 *cfreq)
{
	PN_U8 data1=0, data2=0, data3=0, data4=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, NULL1C_E, 0x10, 0x10);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL26, &data1);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_NULL27, &data2);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_INV, &data3);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_CFREQ, &data4);
	*null_len = ((data2 & 0x0f) << 8) + data1;
	*tr_mode = (data2 & 0x30) >> 4;
	*iq_inv = (data3 & BIT_MASK_3_E) >> 3;
	*cfreq = data4;

	PN3030_Field_Write(PN3030E_ADDR, USAM_E_START, 0x01, 0x01);
 	PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7E, &data1);
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_VARI7F, &data2);
	*con_vari = ((data2 & 0x1f) << 8) + data1;  // PN3030EV variance

	EV_SNR_MON(pn_type);          // PN3030EV SNR value calculation Function by terry 07.02.12
	if(pn_type)
	{
		*snr = (PN_S32)(SNR2 *1000);
		*snr_bar = (PN_S32)(SNR2 * 5);
	}
	else
	{
		*snr = (PN_S32)(SNR1 * 1000);
		*snr_bar = (PN_S32)(SNR1 * 5);
	}
}

PN_VOID EV_OFDM_STAT2(PN_U8 pn_type, PN_U8 *fsm, PN_U8 *adc_over, PN_U8 *ascv, PN_S8 *tscv, PN_U8 *fft_vcnt, PN_U8 *clk_cnt, PN_U8 *tclk_cnt)
{
	PN_U8 rdata0=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x37, &rdata0);
	*fsm = rdata0 & 0x07;
	
	PN3030_Field_Write(PN3030E_ADDR, 0x50, 0x01, 0x01);
	PN3030_Byte_Read(PN3030E_ADDR, 0x52, &rdata0);
	*adc_over = rdata0 & 0xFF;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x30, &rdata0);
	*ascv = rdata0 & 0x0F;
	*tscv = (rdata0 & 0xF0)>>4;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x31, &rdata0);
	*fft_vcnt = rdata0 & 0x7F;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x17, &rdata0);
	*clk_cnt = rdata0 & 0x1F;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x71, &rdata0);
	*tclk_cnt = rdata0 & 0x1F;	
}
PN_VOID EV_OFDM_STAT3(PN_U8 pn_type, PN_S32 *facc, PN_S8 *toffset, PN_S32 *tacc, PN_U16 *sym_offset, PN_U8 *coef, PN_U16 *post_agc, PN_U16 *pre_agc)
{
	PN_U8 rdata0 =0, rdata1=0, rdata2=0, rdata3=0;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, 0x75, 0x40, 0x40);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7A, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7B, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7C, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7D, &rdata3);
	*facc = (rdata3<<24) + (rdata2<<16) + (rdata1<<8) + rdata0;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xB7, &rdata0);
	*toffset = rdata0 & 0xFF;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x76, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x77, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0x78, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, 0x79, &rdata3);
	*tacc = (rdata3<<24) + (rdata2<<16) + (rdata1<<8) + rdata0;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xB8, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB9, &rdata1);
	*sym_offset = ((rdata0 & 0x01)<<8) + rdata1;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x27, &rdata0);
	*coef = (rdata0 & 0xC0) >> 6;
	
	PN3030_Field_Write(PN3030E_ADDR, 0x44, 0x80, 0x80);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4C, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4D, &rdata1);
	*post_agc = ((rdata1 & 0x01)<<8) + rdata0;
	
	PN3030_Field_Write(PN3030E_ADDR, 0x53, 0x80, 0x80);
	PN3030_Byte_Read(PN3030E_ADDR, 0x66, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x67, &rdata1);
	*pre_agc = (rdata1<<2) + (rdata0 & 0x03);
}

PN_VOID EV_OFDM_STAT4(PN_U8 pn_type, PN_U8 *co_ch_sel, PN_U8 *co_ch_cnt, PN_U8 *co_ch_lock, PN_U16 *co_ch_start, PN_U16 *co_ch_end, PN_U16 *co_ch_apwr)
{
	PN_U8 rdata0 =0, rdata1=0, rdata2=0;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x92, &rdata0);
	*co_ch_sel = rdata0 & 0x03; 
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xB1, &rdata0);
	*co_ch_cnt = (rdata0 & 0x3E)>>1; 
	*co_ch_lock = rdata0 & 0x01; 

	PN3030_Byte_Read(PN3030E_ADDR, 0xB2, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB3, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB4, &rdata2);
	*co_ch_start = ((rdata1 & 0x0F)<<8) + rdata0;
	*co_ch_end = (rdata2<<4) + ((rdata1 & 0xF0)>>4);   // bug fix 2011.10.31
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xB5, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB6, &rdata1);
	*co_ch_apwr = ((rdata1 & 0x07)<<8) + rdata0;	
}

PN_VOID EV_OFDM_STAT5(PN_U8 pn_type, PN_S16 *mon_imb_i, PN_S16 *mon_imb_q, PN_U8 *fic_spec_mon)
{
	PN_U8 rdata0 =0, rdata1=0;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, 0x4D, 0x04, 0x00);
	PN3030_Field_Write(PN3030E_ADDR, 0x4D, 0x04, 0x04);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4E, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4F, &rdata1);
	*mon_imb_i = (rdata1 << 8) + rdata0;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x50, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x51, &rdata1);
	*mon_imb_q = (rdata1 << 8) + rdata0;	
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xAC, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xAD, &rdata1);
	if(rdata1 & 0x02)
	{
		*fic_spec_mon = rdata0;
	}
	else
	{
		*fic_spec_mon = 0xAA;
	}
}

PN_VOID EV_OFDM_STAT6(PN_U8 pn_type, PN_U8 *id_on, PN_U16 *pre_des, PN_U16 *post_des,PN_U8 *echo_lock,
                     PN_U8 *echo_pre_lcnt, PN_U8 *echo_post_lcnt, PN_U8 *o_vari,PN_U8 *out_sel,PN_U8 *fec_ndata)
{
	PN_U8 rdata0=0, rdata1=0, rdata2=0;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x44, &rdata0);
	*id_on = rdata0 & 0x01;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x1E, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x1F, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0x20, &rdata2);
	*pre_des = (rdata0 << 4) + (rdata2 & 0x0F);
	*post_des = (rdata1 <<4) + ((rdata2 & 0xF0)>>4);
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x21, &rdata0);
	*echo_lock = (rdata0 & 0x03);
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x22, &rdata0);
	*echo_pre_lcnt = (rdata0 & 0xF0)>>4;
	*echo_post_lcnt = (rdata0 &0x0F);	
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x13, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x14, &rdata1);
	*o_vari = ((rdata0 & 0xF8)<<5) + rdata1;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x15, &rdata0);
	*out_sel = (rdata0 & 0xC0)>>2;
	*fec_ndata = (rdata0 & 0x03);	
}

PN_VOID EV_OFDM_STAT7(PN_U8 pn_type, PN_U16 *notACS_fic, PN_U16 *notACS_msc, PN_U16 *renorm_fic,PN_U16 *renorm_msc
                     ,PN_U16 *total_subchsize, PN_U16 *current_subchsize, PN_U8 *cif_cnt, PN_U8 *recon_cif)
{
	PN_U8 rdata0=0, rdata1=0;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x80, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x81, &rdata1);
	*notACS_fic = (rdata0 << 8) + rdata1;	
	PN3030_Byte_Read(PN3030E_ADDR, 0x82, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x83, &rdata1);
	*notACS_msc = (rdata0 << 8) + rdata1;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x84, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x85, &rdata1);
	*renorm_fic = (rdata0 << 8) + rdata1;	
	PN3030_Byte_Read(PN3030E_ADDR, 0x86, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x87, &rdata1);
	*renorm_msc = (rdata0 << 8) + rdata1;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xB0, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB1, &rdata1);
	*total_subchsize = ((rdata0 & 0x03) << 8) + rdata1;
	PN3030_Byte_Read(PN3030E_ADDR, 0xB2, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xB3, &rdata1);
	*current_subchsize = ((rdata0 & 0x03) << 8) + rdata1;	
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x8A, &rdata0);
	*cif_cnt = rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x8B, &rdata0);
	*recon_cif = rdata0;	
}

PN_VOID EV_OFDM_STAT8(PN_U8 pn_type, PN_U8 *scan_mon, PN_U16 *mon_scan_pwr)
{
	PN_U8 rdata0=0, rdata1=0;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x37, &rdata0);
	*scan_mon = rdata0 & 0x0F;
	PN3030_Byte_Read(PN3030E_ADDR, 0x38, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x39, &rdata1);
	*mon_scan_pwr = (rdata1 << 8) + rdata0;	
}

PN_VOID EV_RF_STAT(PN_U8 pn_type, PN_U8 *rf_reg00, PN_U8 *rf_reg01, PN_U8 *rf_reg02, PN_U8 *rf_reg04, PN_U8 *rf_reg15)
{
	PN_U8 rdata0=0;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  RF_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x00, &rdata0);
	*rf_reg00 = rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x01, &rdata0);
	*rf_reg01 = rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x02, &rdata0);
	*rf_reg02 = rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x04, &rdata0);
	*rf_reg04 = rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x15, &rdata0);
	*rf_reg15 = rdata0;
}

//////////////////////////////////////////////////////////////////////
// PN3030EV- Monitoring the FEC Status - Pre_Viterbi Error Status   //
//////////////////////////////////////////////////////////////////////
PN_VOID EV_CHANNEL_STAT(PN_U8 pn_type, PN_U8 *fic_crc, PN_U16 *fic_val, PN_U16 *fic_cnt, PN_U32 *msc_val, PN_U32 *msc_cnt, PN_U32 *zero_ber)
{
	PN_U8 fic_sync;
	PN_U8 rdata0, rdata1, rdata2, rdata3;
	PN_U8 rcnt0, rcnt1, rcnt2, rcnt3;

	///FIC Sync detector
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR,TS1_E_SYNC, &rdata0);
	fic_sync = (rdata0 & BIT_MASK_4_E) >> 4;

	if(fic_sync != 0x01)
	{	
		*fic_crc = 0xFF;
		*fic_val = 1;
		*fic_cnt = 1;	
		*msc_cnt = 1;
		*msc_val = 1;
		return;
	}

	///FIB CRC error number
	PN3030_Byte_Read(PN3030E_ADDR, MON_E_FIB, &rdata0);
	*fic_crc = rdata0;

	///FIC CER
	PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERH, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CERL, &rdata0);
	*fic_val = (rdata1 << 8) | rdata0;

	PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTH, &rcnt1);
	PN3030_Byte_Read(PN3030E_ADDR, FIC_E_CNTL, &rcnt0);
	*fic_cnt = (rcnt1 << 8) | rcnt0;

	///MSC CER
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CNTHH, &rdata3);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CNTHL, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CNTLH, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CNTLL, &rdata0);
	*msc_cnt = (rdata3 << 24) | (rdata2 << 16) | (rdata1 << 8) | rdata0;

	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERHH, &rcnt3);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERHL, &rcnt2);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERLH, &rcnt1);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERLL, &rcnt0);
	*msc_val = (rcnt3 << 24) | (rcnt2 << 16) | (rcnt1 << 8) | rcnt0;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xE1, &rdata0);
	if(rdata0 & 0x80)
	{	
		PN3030_Byte_Read(PN3030E_ADDR, 0xE3, &rdata2);
		PN3030_Byte_Read(PN3030E_ADDR, 0xE4, &rdata1);
		PN3030_Byte_Read(PN3030E_ADDR, 0xE5, &rdata0);
		*zero_ber = (0x00 << 24) |((rdata2&0x0F) << 16) | (rdata1 << 8) | rdata0;
	}
	else
	{
		*zero_ber = 262144;
	}
}

PN_VOID EV_CONSTELL_STAT(PN_U8 pn_type, PN_S8 *mon_diff_i, PN_S8 *mon_diff_q)
{
	PN_S8 rdata0 =0;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, 0x2A, 0x01, 0x01);
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, 0x23, 0xFF);
	PN3030_Byte_Write(PN3030E_ADDR, 0x23, 0x00);

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x2D, &rdata0);
	*mon_diff_i = (rdata0 & 0x3F);
	PN3030_Byte_Read(PN3030E_ADDR, 0x2E, &rdata0);
	*mon_diff_q = (rdata0&0x3F);
}

PN_VOID EV_TII_MON_STAT(PN_U8 pn_type, PN_U8 *tii_c1, PN_U8 *tii_p1, PN_U16 *tii_s1)
{
	PN_U8 rdata0, rdata1;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x34, &rdata0);
	if((rdata0 & 0x40)>>6)   			// TII Interrupt check
	{
		PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x00);
		PN3030_Byte_Read(PN3030E_ADDR, 0x5C, &rdata0);
		PN3030_Byte_Read(PN3030E_ADDR, 0x5D, &rdata1);
		*tii_c1 = rdata0;
		*tii_p1 = rdata1;
		
		PN3030_Byte_Write(PN3030E_ADDR, 0x5A, 0x01);      // TII Power Monitoring set
		PN3030_Byte_Read(PN3030E_ADDR, 0x5C, &rdata0);
		PN3030_Byte_Read(PN3030E_ADDR, 0x5D, &rdata1);
		*tii_s1 = (rdata0 << 8) + rdata1;
		
		PN3030_Byte_Write(PN3030E_ADDR, 0x36, 0x40);		 // TII Interrupt clear
	}
}

PN_VOID EV_CHANNEL_STAT2(PN_U8 pn_type, PN_U8 *fec_sync_f,PN_U8 *rnorm_cnt)
{
	PN_U8 rdata0=0, rdata1=0;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR,0xD7, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR,0xFB, &rdata1);   // Reconfig_status
	*fec_sync_f = ((rdata0 & 0x10)>>4) | (rdata1 & 0x04);
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xEC, &rdata0);
	*rnorm_cnt = rdata0;	
}

//////////////////////////////////////////////////////////////////////////
// PN3030EV- Monitoring the FEC Status - Post_Viterbi(RS) Error Status  //
//////////////////////////////////////////////////////////////////////////
PN_VOID EV_RS_STAT(PN_U8 pn_type, PN_U8 *rs_sync, PN_U32 *bit_cnt, PN_U32 *bit_val, PN_U16 *alarm_err)
{
	PN_U8 rdata0=0, rdata1=0, rdata2=0;
	PN_U8 rcnt0=0, rcnt1=0, rcnt2=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR,TS1_E_SYNC, &rdata0);
	*rs_sync = (rdata0 & BIT_MASK_3_E) >> 3;

	if(*rs_sync != 0x01)
	{
		*bit_cnt = 1;
		*bit_val = 1;
		*alarm_err = 0xFF;
		return;
	}

	//PN3030EV RS bit error rate
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITPRDH, &rcnt2);
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITPRDM, &rcnt1);
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITPRDL, &rcnt0);
	*bit_cnt = (rcnt2 << 16) | (rcnt1 << 8) | rcnt0;

	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITERRH, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITERRM, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_BITERRL, &rdata0);
	*bit_val = (rdata2 << 16) | (rdata1 << 8) | rdata0;

	//PN3030EV RS alarm error rate
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_PKTERRH, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, TS1_E_PKTERRL, &rdata0);
	*alarm_err = (rdata1 << 8) | rdata0;
}

PN_VOID EV_SNR_MON(PN_U8 pn_type) // PN3030EV SNR value calculation Function by terry 07.02.12
{
	PN_FLOAT MSC_CN=0;
	PN_U8 msc_cer_HH=0, msc_cer_HL=0, msc_cer_LH=0, msc_cer_LL=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERHH, &msc_cer_HH); // MSC_CER read 32bit
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERHL, &msc_cer_HL);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERLH, &msc_cer_LH);
	PN3030_Byte_Read(PN3030E_ADDR, MSC_E_CERLL, &msc_cer_LL);

	if(pn_type)
	{
		msc_cer_chk2 = ((msc_cer_HH << 24) | (msc_cer_HL << 16) | (msc_cer_LH << 8) | msc_cer_LL);	
		if(msc_cer_chk2 > 90000)                                    // MSC_CER_reg 90000 ~
		{
			MSC_CN = (PN_FLOAT)9.;
		}
		else if((msc_cer_chk2 > 25000) && (msc_cer_chk2 <= 90000))  // MSC_CER_reg 25000 ~ 90000
		{
			MSC_CN = (PN_FLOAT)((-3.)*msc_cer_chk2/65000)+(PN_FLOAT)13.15;
		}    
		else if((msc_cer_chk2 > 5000) && (msc_cer_chk2 <= 25000))   // MSC_CER_reg 5000 ~ 25000
		{
			MSC_CN = (PN_FLOAT)((-2.)*msc_cer_chk2/20000)+(PN_FLOAT)14.5;
		}    
		else if((msc_cer_chk2 > 1000) && (msc_cer_chk2 <= 5000))    // MSC_CER_reg 1000 ~ 5000
		{
			MSC_CN = (PN_FLOAT)((-3.)*msc_cer_chk2/4000.)+(PN_FLOAT)17.75;
		}
		else if((msc_cer_chk2 > 100 ) && (msc_cer_chk2 <= 1000))    // MSC_CER_reg 100 ~ 1000
		{
			MSC_CN = (PN_FLOAT)((-2.)*msc_cer_chk2/900.)+(PN_FLOAT)19.22;
		}
		else if((msc_cer_chk2 > 2) && (msc_cer_chk2 <= 100))        // MSC_CER_reg 2 ~ 100
		{
			MSC_CN = (PN_FLOAT)((-4.)*msc_cer_chk2/98.)+(PN_FLOAT)23.13;
		}
		else if(msc_cer_chk2 <= 2)                                  // MSC_CER_reg   ~ 2
		{
    		MSC_CN = (PN_FLOAT)25.;
		}
		
		if(msc_cer_acc_no2 < 2)        // TOTAL C/N accumulation= '2' 
		{
			TOTAL_CN2 = TOTAL_CN2 + MSC_CN ;	
  			msc_cer_acc_no2++;
		}
		else                          // TOTAL C/N값을 누적하여 SNR value calculation
		{
			CN2 = (TOTAL_CN2 + CN_S2)/(PN_FLOAT)3.;
			CN_S2 = CN2;
			SNR2 = CN2 - (PN_FLOAT)5.;
			msc_cer_acc_no2 = 0;       // TOTAL C/N accumulation count reset  
			TOTAL_CN2 = 0;             // TOTAL C/N value reset 
		}
	}
	else
	{
		msc_cer_chk1 = ((msc_cer_HH << 24) | (msc_cer_HL << 16) | (msc_cer_LH << 8) | msc_cer_LL);	
		if(msc_cer_chk1 > 90000)                                    // MSC_CER_reg 90000 ~
		{
			MSC_CN = (PN_FLOAT)9.;
		}
		else if((msc_cer_chk1 > 25000) && (msc_cer_chk1 <= 90000))  // MSC_CER_reg 25000 ~ 90000
		{
			MSC_CN = (PN_FLOAT)((-3.)*msc_cer_chk1/65000)+(PN_FLOAT)13.15;
		}    
		else if((msc_cer_chk1 > 5000) && (msc_cer_chk1 <= 25000))   // MSC_CER_reg 5000 ~ 25000
		{
			MSC_CN = (PN_FLOAT)((-2.)*msc_cer_chk1/20000)+(PN_FLOAT)14.5;
		}    
		else if((msc_cer_chk1 > 1000) && (msc_cer_chk1 <= 5000))    // MSC_CER_reg 1000 ~ 5000
		{
			MSC_CN = (PN_FLOAT)((-3.)*msc_cer_chk1/4000.)+(PN_FLOAT)17.75;
		}
		else if((msc_cer_chk1 > 100 ) && (msc_cer_chk1 <= 1000))    // MSC_CER_reg 100 ~ 1000
		{
			MSC_CN = (PN_FLOAT)((-2.)*msc_cer_chk1/900.)+(PN_FLOAT)19.22;
		}
		else if((msc_cer_chk1 > 2) && (msc_cer_chk1 <= 100))        // MSC_CER_reg 2 ~ 100
		{
			MSC_CN = (PN_FLOAT)((-4.)*msc_cer_chk1/98.)+(PN_FLOAT)23.13;
		}
		else if(msc_cer_chk1 <= 2)                                  // MSC_CER_reg   ~ 2
		{
    		MSC_CN = (PN_FLOAT)25.;
		}
		
		if(msc_cer_acc_no1 < 2)        // TOTAL C/N accumulation= '2' 
		{
			TOTAL_CN1 = TOTAL_CN1 + MSC_CN ;	
  			msc_cer_acc_no1++;
		}
		else                          // TOTAL C/N값을 누적하여 SNR value calculation
		{
			CN1 = (TOTAL_CN1 + CN_S1)/(PN_FLOAT)3.;
			CN_S1 = CN1;
			SNR1 = CN1 - (PN_FLOAT)5.;
			msc_cer_acc_no1 = 0;       // TOTAL C/N accumulation count reset  
			TOTAL_CN1 = 0;             // TOTAL C/N value reset 
		}
	}
}

/* TII Status function */
PN_VOID EV_TII1_STAT(PN_U8 pn_type, PN_S32 *tii_c, PN_S32 *tii_p, PN_S32 *tii_s, PN_S32 *tii_t)
{
	PN_U8 rdata0=0, rdata1=0;
    
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, INT_E_STATH, &rdata0);
	if((rdata0 & BIT_MASK_6_E) >> 6)
	{
		PN3030_Byte_Write(PN3030E_ADDR, TII_MOM_SEL,0x00);   /// TII Comb,Pattern
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII0_H, &rdata0);
		*tii_c=rdata0;
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII0_L, &rdata0);
		*tii_p=rdata0;
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII_TOWER, &rdata0);
		*tii_t=rdata0;

		PN3030_Byte_Write(PN3030E_ADDR, TII_MOM_SEL,0x01);   /// TII Strength
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII0_H, &rdata0);
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII0_L, &rdata1);
		*tii_s=(rdata0<<8) | rdata1;
	
//		PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
//		PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRH, 0x40);
	}
}

PN_VOID EV_TII2_STAT(PN_U8 pn_type, PN_S32 *tii_c2, PN_S32 *tii_p2, PN_S32 *tii_s2, PN_S32 *tii_t2)
{
	PN_U8 rdata0=0, rdata1=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FEC_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, INT_E_STATH, &rdata0);
	if((rdata0 & BIT_MASK_6_E) >> 6)
	{
		PN3030_Byte_Write(PN3030E_ADDR, TII_MOM_SEL,0x00);   /// TII Comb,Pattern

		PN3030_Byte_Read(PN3030E_ADDR, MON_TII1_H, &rdata0);
		*tii_c2=rdata0;
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII1_L, &rdata0);
		*tii_p2=rdata0;
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII_TOWER, &rdata0);
		*tii_t2=rdata0;

		PN3030_Byte_Write(PN3030E_ADDR, TII_MOM_SEL,0x01);   /// TII Strength
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII1_H, &rdata0);
		PN3030_Byte_Read(PN3030E_ADDR, MON_TII1_L, &rdata1);
		*tii_s2=(rdata0<<8) | rdata1;
	
		PN3030_Reg_Page_Sel(PN3030E_ADDR,  DD_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRH, 0x40);
	}
}

////////////////////////////////////////////
// PN3030EV- Monitoring the MRC Status    //
////////////////////////////////////////////
PN_VOID EV_MRC_STATUS(PN_U8 pn_type, PN_U8 *mrc_mode, PN_U8 *frame_sync, PN_U8 *symbol_sync)
{
	PN_U8 diversity_status=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, COMM_15, &diversity_status);

	*mrc_mode    = (diversity_status & 0x0C) >> 2; // [3:2] OUT_SEL : MRC Mode [0] MIX (Master+Slave) [1] Master only [2] Slave only
	*frame_sync  = (diversity_status & 0x02) >> 1; // Frame Sync  : [0] Fail [1] OK
	*symbol_sync = diversity_status & 0x01;        // Symbol Sync : [0] Fail [1] OK
}

PN_VOID EV_MRC_SETUP(PN_U8 pn_type, PN_U8 mrc_state, PN_U8 tuner_type)
{
	PN_U8 ofdm_coef_sel = 0;
	
	if(mrc_state) // MRC Enable
	{
		// 0x04[5:3] PI_SEL = 5 ==> Master/Slave 동일
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 0, OFDM_E_PAGE);
		PN3030_Byte_Write(0, TOP04_E, 0x68);
		
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 1, OFDM_E_PAGE);
		PN3030_Byte_Write(1, TOP04_E, 0x68);

		// 0x0C[7:0] = 0xC0(Master)/0xE0(Slave) ==> 2-diversity only
		PN3030_Byte_Write(0, TOP12_E, 0xC0);
		PN3030_Byte_Write(1, TOP12_E, 0xE0);
		
		PN3030_Byte_Write(0, 0x19, 0x50);    // Coef manual set "0" by terry
		PN3030_Byte_Write(1, 0x19, 0x50);
		PN3030_Byte_Read(0, 0x1A, &ofdm_coef_sel);
		PN3030_Byte_Write(0, 0x1A, (ofdm_coef_sel | 0x01));
		PN3030_Byte_Read(1, 0x1A, &ofdm_coef_sel);
		PN3030_Byte_Write(1, 0x1A, (ofdm_coef_sel | 0x01));

		// 0x10[7:0] = 0x85(Master)/0x83(Slave)
		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 0, COMM_E_PAGE);
		PN3030_Byte_Write(0, COMM_10, 0x85);

		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 1, COMM_E_PAGE);
		PN3030_Byte_Write(1, COMM_10, 0x83);
	}
	else // MRC Disable
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 0, OFDM_E_PAGE);
		PN3030_Byte_Write(0, TOP04_E, 0x40);
		
		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 1, OFDM_E_PAGE);
		PN3030_Byte_Write(1, TOP04_E, 0x40);

		PN3030_Byte_Write(0, TOP12_E, 0xF5);
		PN3030_Byte_Write(1, TOP12_E, 0xF5);
		
		PN3030_Byte_Write(0, 0x19, 0x10);    // Coef Auto set by terry
		PN3030_Byte_Write(1, 0x19, 0x10);

		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 0, COMM_E_PAGE);
		PN3030_Byte_Write(0, COMM_10, 0x91);

		PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);//PN3030_Reg_Page_Sel(PN3030E_ADDR, 1, COMM_E_PAGE);
		PN3030_Byte_Write(1, COMM_10, 0x91);
	}
}

////////////////////////////////////////////
//  Monitoring PN3030EV Pre_AGC Status    //
////////////////////////////////////////////
PN_S32 EV_AGC_STAT(PN_U8 pn_type)
{
	PN_U8 agc_val0, agc_val1;
	PN_S32 agc;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, AGC0_E_EN, 0x80, 0x80); // One shot value for PRE AGC value read
	PN3030_Byte_Read(PN3030E_ADDR, MON_CNT_PRE1_L, &agc_val0);
	PN3030_Byte_Read(PN3030E_ADDR, MON_CNT_PRE1_H, &agc_val1);
	agc = (agc_val1 << 2) | (agc_val0 & 0x03);

	return agc;
}

PN_S32 EV_POST_AGC_STAT(PN_U8 pn_type)
{
	PN_U8 agc_val0, agc_val1;
	PN_S32 post_agc;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, MON_POST_START, 0x80, 0x80); //One shot value for POST AGC value read
	PN3030_Byte_Read(PN3030E_ADDR, MON_POST_GAIN_L, &agc_val0);
	PN3030_Byte_Read(PN3030E_ADDR, MON_POST_GAIN_H, &agc_val1);
	post_agc = ((agc_val1 & BIT_MASK_0_E) << 8) | agc_val0;

	return post_agc;
}

PN_VOID EV_RSSI_STAT(PN_U8 pn_type, PN_S16 *sig_level, PN_S8 *sig_bar, PN_FLOAT frequency)
{
	PN_FLOAT RF_LEVEL = 0.;
	PN_U8 GVRF = 0;      // RF page 0x00
	PN_S32 GVBB_ANA = 0;  // RF page 0x02
	PN_U8 GVBB_DIG = 0;  // RF page 0x04
	//PN_U8 SamADCType=0;
	PN_S32 Pre_AGC = 0;

        /// New version PNS3030A by terry
	AGC_STAT_TUNER(PNS3030A, &GVBB_ANA, &GVRF, &GVBB_DIG);
	Pre_AGC = EV_AGC_STAT(pn_type);
	
	if(frequency < BANDII) 								/// Band-II RSSI Calculation
	{
		RF_LEVEL = -((((GVRF&0x30)>>4)*12.)+((GVRF&0x0F)*3.0)+((GVBB_ANA&0x0F)*3.0)+((GVBB_DIG&0x7F)*0.4))+((frequency / 110)*20)-17; 
		((GVRF & 0xC0) == 0x40)? (RF_LEVEL += 19.) : (RF_LEVEL += 26.);	
	}
	else if((BANDII < frequency) && ( frequency < BANDIII)) /// Band-III RSSI Calculation
	{
		if(GVRF & 0x30)
		{
			RF_LEVEL = -((((GVRF&0x30)>>4)*12.)+((GVRF&0x0F)*2.8)-((Pre_AGC*2.4)/13)+131);
			if((GVRF&0x30)== 0x20)
				RF_LEVEL += 1; 
			if((frequency > 220.) && ((GVRF & 0x0F) == 0x08))
				RF_LEVEL += 2;
			if((GVBB_DIG&0x7F) > 40)
				RF_LEVEL += 1;	
		}
		else
		{ 
			RF_LEVEL = -((((GVRF&0x30)>>4)*12.)+((GVRF&0x0F)*2.8)-((Pre_AGC*1.1)/12.55)+79);
		}
		if((GVRF&0xC0) == 0x40)
			RF_LEVEL -= 2;
	}
	else if((frequency > BANDIII) && (frequency < BANDUHF)) /// UHF-Band RSSI Calculation
	{
		RF_LEVEL = -((((GVRF&0x30)>>4)*9.5)+((GVRF&0x0F)*3.0)+((GVBB_ANA&0x0F)*3.0)+((GVBB_DIG&0x7F)*0.5))+20.; 
		((GVRF & 0xC0) == 0x30)? (RF_LEVEL += 15.) : (RF_LEVEL += 20.);
	}
	else if(frequency > BANDUHF) 							/// L-Band RSSI Calculation
	{
		RF_LEVEL = -((((GVRF&0x30)>>4)*12.)+((GVRF&0x0F)*3.0)+((GVBB_ANA&0x0F)*2.8)+((GVBB_DIG&0x7F)*0.5))+30.; 
		//((GVRF & 0x30) >= 0x10)? (((GVRF & 0xC0) == 0x40)? (RF_LEVEL) : (RF_LEVEL += 8.)) : (RF_LEVEL);
	}

	*sig_level = RF_LEVEL * 10;
	*sig_bar = (((120 + RF_LEVEL) * 100 )/130);
}

/////////////////////MAX2172 RSSI TEST UPDATE 2008.09.25 ///////////////////////
/// MAX2172+PN3030EV: It is impossibe to implement over RF_Level -30dBm
PN_VOID EV_MAX2172_RSSI_STAT(PN_U8 pn_type, PN_S16 *sig_level, PN_S8 *sig_bar, PN_FLOAT Frequency)
{
	PN_U8 LNA_LEVEL;
	PN_FLOAT RF_LEVEL;
	PN_S32 data;
	PN_U8 GVBB_DIG = 0;  // RF page 0x04

	AGC_STAT_TUNER(MAX2172, &data, &LNA_LEVEL, &GVBB_DIG); // MAX2171 Digital RF/IF step value

	RF_LEVEL = (PN_FLOAT)data;  //RF RSSI function

	*sig_level = RF_LEVEL * 10;
//	*sig_bar = (PN_S32)(((115+RF_LEVEL)/100) * 100);
	*sig_bar = (PN_S32)(115000+data);
	
	//모르겠음 세개의변수//AGC_CON_TUNER(pn_type, MAX2172, Frequency, 0);
	
}

//////////////////////////////////////////////
// PN3030EV- Monitoring FM OFDM lock status //
//////////////////////////////////////////////
PN_S32 EV_FM_LOCK_STAT(PN_U8 pn_type)
{
	PN_U32 i;
	PN_U8 Data0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);

	for(i=0; i<50; i++)
	{
		PN3030_Byte_Read(PN3030E_ADDR, FMEF, &Data0);
		if(Data0 == 0x01)
		{
			return PN_FN_OK; 
		}
		Delay_Ms(20);
	}
	return PN_FN_FAIL;
}

PN_VOID EV_FMRDS_STAT(PN_U8 pn_type, PN_U8 *fm_lock, PN_U8 *rds_lock, PN_U8 *rds_gain, PN_U8 *osc57_offset, PN_U8 *fm_cnt)
{
	PN_U8 Data0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	
	PN3030_Byte_Read(PN3030E_ADDR, FMEF, &Data0);
	*fm_lock = Data0 & BIT_MASK_0_E;
	
	PN3030_Byte_Read(PN3030E_ADDR, FMDB, &Data0);
	*rds_lock = Data0 & BIT_MASK_0_E;

	PN3030_Byte_Read(PN3030E_ADDR, FME7, &Data0);
	*rds_gain = Data0;

	PN3030_Byte_Read(PN3030E_ADDR, FMF9, &Data0);
	*osc57_offset = Data0;						// Offset value of OSC57 frequency

	PN3030_Byte_Read(PN3030E_ADDR, FMEE, &Data0);
	*fm_cnt = Data0;
}

PN_VOID EV_FMRDS_STAT2(PN_U8 pn_type, PN_U8 *fm_adc_over, PN_U16 *fm_post_agc, PN_U16 *fm_pre_agc, PN_S32 *fm_facc, PN_S32 *fm_tacc)
{
	PN_U8 Data0;
	PN_U8 rdata0,rdata1,rdata2,rdata3;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, 0x50, 0x00, 0x01);
	PN3030_Field_Write(PN3030E_ADDR, 0x50, 0x00, 0x00);
	PN3030_Byte_Read(PN3030E_ADDR, 0x52, &Data0);
	*fm_adc_over = Data0 & 0xFF;                // ADC overflow monitoring
	
	PN3030_Field_Write(PN3030E_ADDR, 0x44, 0x80, 0x80);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4C, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4D, &rdata1);
	*fm_post_agc = ((rdata1 & 0x01)<<8) + rdata0;	// Post_agc monitoring
	
	PN3030_Field_Write(PN3030E_ADDR, 0x53, 0x80, 0x80);
	PN3030_Byte_Read(PN3030E_ADDR, 0x66, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x67, &rdata1);
	*fm_pre_agc = (rdata1<<2) + (rdata0 & 0x03);	// Pre_agc monitoring
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, 0x75, 0x40, 0x40);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7A, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7B, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7C, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, 0x7D, &rdata3);
	*fm_facc = (rdata3<<24) + (rdata2<<16) + (rdata1<<8) + rdata0;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x76, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x77, &rdata1);
	PN3030_Byte_Read(PN3030E_ADDR, 0x78, &rdata2);
	PN3030_Byte_Read(PN3030E_ADDR, 0x79, &rdata3);
	*fm_tacc = (rdata3<<24) + (rdata2<<16) + (rdata1<<8) + rdata0;
}

PN_VOID EV_FMRDS_STAT3(PN_U8 pn_type,PN_U8 *fm_mode, PN_U8 *filter_coef, PN_S16 *mon_imb_i, PN_S16 *mon_imb_q, 
                       PN_U8 *hpf_th_h, PN_U8 *hpf_th_l,PN_U16 *mon_hpf_noise, PN_U8 *noise_status, PN_U8 *fm_scan_en)
{
	PN_U8 rdata0,rdata1;
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	
	PN3030_Byte_Read(PN3030E_ADDR, 0xF0, &rdata0);
	*fm_mode = (rdata0 & 0x06)>>1;
	PN3030_Byte_Read(PN3030E_ADDR, 0xF6, &rdata0);
	*filter_coef = (rdata0 & 0x38) >> 3;	
	
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  COMM_E_PAGE);
	
	PN3030_Field_Write(PN3030E_ADDR, 0x4D, 0x04, 0x00);
	PN3030_Field_Write(PN3030E_ADDR, 0x4D, 0x04, 0x04);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4E, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x4F, &rdata1);
	*mon_imb_i = (rdata1 << 8) + rdata0;	
	PN3030_Byte_Read(PN3030E_ADDR, 0x50, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x51, &rdata1);
	*mon_imb_q = (rdata1 << 8) + rdata0;
		
	PN3030_Byte_Read(PN3030E_ADDR, 0x6B, &rdata0);
	*hpf_th_h = rdata0 & 0xFF;
	PN3030_Byte_Read(PN3030E_ADDR, 0x6C, &rdata0);
	*hpf_th_l = rdata0 & 0xFF;	
	PN3030_Byte_Read(PN3030E_ADDR, 0x6D, &rdata0);
	PN3030_Byte_Read(PN3030E_ADDR, 0x6E, &rdata1);
	*mon_hpf_noise = (rdata1 << 8) + rdata0;
	PN3030_Byte_Read(PN3030E_ADDR, 0x6F, &rdata0);
	*noise_status = rdata0 & 0x01;
	PN3030_Byte_Read(PN3030E_ADDR, 0x70, &rdata0);
	*fm_scan_en = rdata0 & 0x01;
}

PN_VOID EV_FMRDS_ERR(PN_U8 pn_type, PN_S32 *dc_val, PN_U8 *fm_vary, PN_S32 *rds_toffset)
{
	PN_U8 Data0=0 , Data1=0, Data2=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR,  FM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FMF7, 0x03);		///FM Variance, DC value display start

	PN3030_Byte_Read(PN3030E_ADDR, 0xD8, &Data0);
	PN3030_Byte_Read(PN3030E_ADDR, 0xD9, &Data1);
	PN3030_Byte_Read(PN3030E_ADDR, 0xDA, &Data2);
	*rds_toffset = (Data2 << 16) | (Data1 << 8) | Data0;
	
	PN3030_Byte_Read(PN3030E_ADDR, FMFC, &Data0);
	PN3030_Byte_Read(PN3030E_ADDR, FMFD, &Data1);
	PN3030_Byte_Read(PN3030E_ADDR, FMFE, &Data2);
	*dc_val = ((0x00 << 24) | (Data2 & 0x1F) << 16) | (Data1 << 8) | Data0;

	PN3030_Byte_Read(PN3030E_ADDR, FMFF, &Data0);
	*fm_vary = Data0;
}

//////////////////////////////////////////////
// PN3030EV RF Devide control by IIC Module //
//////////////////////////////////////////////
PN_S32 EV_WRITE_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 value)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CHIPADDR,chip_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_LOCAL_WADDR,reg_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_BAUD,0x32);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CON,0x09);        ///Tuner address on/register address on
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_BURST_L,0x01);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_WDATA_ADDR, RF_E_WDATA00);

	PN3030_Byte_Write(PN3030E_ADDR, RF_E_WDATA00,value);

	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_CON,0x01);
	Delay_Ms(1);
	
	return PN_FN_OK; 
}

PN_S32 EV_WRITE_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size)
{
	PN_S32 i = 0;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CHIPADDR, chip_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_LOCAL_WADDR, reg_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_BAUD, 0x32);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CON, 0x09);         ///Tuner address on/register address off
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_BURST_L, size);     ///Tuner burst length
//	PN3030_Byte_Write(PN3030E_ADDR, RF_E_BURST_L,0x01+size); ///Tuner burst length
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_WDATA_ADDR, RF_E_WDATA00);  /// I2C Output data Length

//	PN3030_Byte_Write(PN3030E_ADDR,RF_E_WDATA00,reg_addr);
	while(1)
	{
		PN3030_Byte_Write(PN3030E_ADDR, RF_E_WDATA00+i,*value);
		value++;
		i++;
		if(i == size)	break;		
	}
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_CON, 0x05); //I2C Start, IIC enable
	Delay_Ms(2);
	return PN_FN_OK; 
}

PN_S32 EV_READ_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CHIPADDR, chip_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_LOCAL_WADDR, reg_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_BAUD, 0x32);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CON, 0x09);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_BURST_L, 0x01);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_RDATA_ADDR, RF_E_RDATA00);

	//RF tuner I2C W/R START
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_CON,0x07); //I2C Start, IIC enable

	Delay_Ms(1);

	PN3030_Byte_Read(PN3030E_ADDR,RF_E_RDATA00,value);
	return PN_FN_OK; 
}

PN_S32 EV_READ_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size)
{
	PN_S32 i;
	PN3030_Reg_Page_Sel(PN3030E_ADDR,  HOST_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CHIPADDR,chip_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_LOCAL_WADDR,reg_addr);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_BAUD,0x32);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_CON,0x09);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_BURST_L,size);
	PN3030_Byte_Write(PN3030E_ADDR, RF_E_RDATA_ADDR,RF_E_RDATA00);

	PN3030_Byte_Write(PN3030E_ADDR, RF_E_I2C_CON, 0x07);

	Delay_Ms(2);

	for(i=0;i<size;i++)
		PN3030_Byte_Read(PN3030E_ADDR,RF_E_RDATA00+i,(value+i));

	return PN_FN_OK; 
}
