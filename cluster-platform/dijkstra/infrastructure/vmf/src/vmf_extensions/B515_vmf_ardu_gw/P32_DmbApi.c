#include "stdio.h"
#include "math.h"
#include "P32_DmbApi.h"
#include "P32_BaseFunc.h"
#include "P32_RF_API.h"
#include "P32_DabCtrl.h"
#include "P32_PNS3030RegDef.h"
#include "stub_fkts.h"

/****************************/
/*	DMB Data structure  */
/****************************/
typedef enum
{
	PN_DABDEMOD_AUDIO,
	PN_DABDEMOD_TS,
	PN_DABDEMOD_DATA
} PN_DABDEMOD_MEDIA_TYPE;

typedef struct {
	unsigned char data[4096];
	unsigned char flag;
	unsigned short subchsize;
}MEM_DUMP;

MEM_DUMP ficmem;

//PN_U8 gStatusBuff[110];
PN_DMB_SYS_CONFIG rDmbSysConfig;
PN_U8 gStatusBuff[110];
PN_U8 gFMStatusBuff[50];

PN_DabBufIdx_t	AudBufIdx;
PN_DabBufIdx_t	DataBufIdx;


PN_U8 Reconfig_occurs_flag1 = FALSE;
PN_U8 Reconfig_occurs_flag2 = FALSE;
PN_S32 FM_DC =0;

PN_FmRdsBufIdx_t gFmRdsBufIdx;

#define PN_DMA_FM_BUF_ADDR		0x3ffe1500
#define PN_DMA_DAB_BUF_SIZE		0xB00
#define PN_TDMB_FM_SIZE			2048
#define PN_DAB_DS_MAX_BUFF_SIZE		(1024 + (10*1024))	/* max data buffer size for the data service */
/*
* CRC computation logic
* 
* The logic for this method of calculating the CRC 16 bit polynomial is taken
* from an article by David Schwaderer in the April 1985 issue of PC Tech
* Journal.
*/
/* CRC-CCITT lookup table	*/
/* Polynominal = 0x1021		*/
const PN_U16 crc_ccitt_tab[] =	
{											
	0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
	0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
	0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
	0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
	0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
	0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
	0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
	0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
	0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
	0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
	0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12, 
	0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A, 
	0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41, 
	0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49, 
	0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
	0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78, 
	0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
	0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067, 
	0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
	0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
	0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
	0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
	0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
	0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
	0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
	0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
	0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
	0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
	0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
	0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
	0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
	0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};









/******************************************************************************
**
**  Name: PN_DemodDabAudioBufIdxInit
**
**  Description:    DAB buffer index init
**
**  Parameters:    	None
**
**  Returns:        None
**
**  Revision History:
**   SCR      Date      Author  Description
**  -------------------------------------------------------------------------
**   N/A
******************************************************************************/
PN_VOID PN_DemodDabAudioBufIdxInit(PN_VOID)
{
	AudBufIdx.gDabBufWrIdx = 0;
	AudBufIdx.gDabBufRdIdx = 0;
	AudBufIdx.gDabMaxIdx = PN_DMA_DAB_BUF_SIZE;
}

PN_VOID PN_DemodDmaDabDataBufIdxInit(PN_VOID)
{
	DataBufIdx.gDabBufRdIdx = 0;
	DataBufIdx.gDabBufWrIdx = 0;
	DataBufIdx.gDabFilled = 0;
	DataBufIdx.gDabMaxIdx = PN_DAB_DS_MAX_BUFF_SIZE;
}

PN_VOID PN_DemodFmRdsBufInit(PN_VOID)
{
	gFmRdsBufIdx.BufWrIdx = gFmRdsBufIdx.BufRdIdx = gFmRdsBufIdx.BufStart = PN_DMA_FM_BUF_ADDR;
	gFmRdsBufIdx.BufSize = PN_TDMB_FM_SIZE;
	gFmRdsBufIdx.MaxIdx = PN_DMA_FM_BUF_ADDR + 14*PN_TDMB_FM_SIZE;
}



//receiving SubchSize by Command
//the issue is how to make header and send it.
//FIC Parsing Flag
PN_VOID PN_InitDmbSysConfig(PN_VOID)
{
	memset((PN_U8*)&rDmbSysConfig, 0x0, sizeof(PN_DMB_SYS_CONFIG));
}

PN_VOID PN_SetFicStatus(PN_U8 devId, FIC_STATUS ficStatus)
{
	if( devId == 0 )
		rDmbSysConfig.ficStatus1 = ficStatus;
	else if( devId == 1 )
		rDmbSysConfig.ficStatus2 = ficStatus;
}

PN_VOID PN_SetMemorySize(PN_U8 devId, PN_U8 MemType, PN_U16 size)
{
	if( devId == 0 )
	{
		switch(MemType)
		{
			case PN_FIC_MEN:
				rDmbSysConfig.ficmem1.subchsize = size;
				break;
			case PN_MSC0_MEN:
			case PN_FIDC_MEN:
				rDmbSysConfig.msc0mem1.subchsize = size;
				break;
			case PN_MSC1_MEN:
				rDmbSysConfig.msc1mem1.subchsize = size;
				break;
			case PN_MSC1_FM_MEN:
				rDmbSysConfig.msc1mem1.subchsize = size;
				break;
			case PN_MSC0_RDS_MEN:
				rDmbSysConfig.msc0mem1.subchsize = size;
				break;
			default:
				break;
		}
	}
	else if( devId == 1 )
	{
		switch(MemType)
		{
			case PN_FIC_MEN:
				rDmbSysConfig.ficmem2.subchsize = size;
				break;
			case PN_MSC0_MEN:
			case PN_FIDC_MEN:
				rDmbSysConfig.msc0mem2.subchsize = size;
				break;
			case PN_MSC1_MEN:
				rDmbSysConfig.msc1mem2.subchsize = size;
				break;
			case PN_MSC1_FM_MEN:
				rDmbSysConfig.msc1mem1.subchsize = size;
				break;
			case PN_MSC0_RDS_MEN:
				rDmbSysConfig.msc0mem1.subchsize = size;
				break;
			default:
				break;
		}
	}
}

PN_VOID PN_INTERRUPT_SERVICE_ROUTINE1(PN_U8 pn_type)
{
	PN_U8 int_type_val1=0, int_type_val2=0;
	PN_U8 Reconfig_CIF_Cnt1=0, cur_CIF_Cnt1=0;
	PN_U8 sync_mode1 = 0, reconfig_stat1 =0;
	PN_U8 mon_msc0_total[2];

	PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
	PN3030_Byte_Read(pn_type, INT_E_STATL, &int_type_val1);     // 0x33
	PN3030_Byte_Read(pn_type, INT_E_STATH, &int_type_val2);     // 0x34

	if((int_type_val1 & MSC1_E_INT) || (int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))   // MSC1 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00);  // MSC1 memory control register clear.
			PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x0D);  // MSC1 memory enable.
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, MSC1_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.msc1mem1.data[4], rDmbSysConfig.msc1mem1.subchsize);

			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.

			//DemodCopyMemory(PN_DABDEMOD_AUDIO, rDmbSysConfig.msc1mem1.data, rDmbSysConfig.msc1mem1.subchsize+4);

			rDmbSysConfig.msc1mem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc1mem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.msc1mem1.data[2] = 0x02; // MSC1
			rDmbSysConfig.msc1mem1.data[3] = 0x01; // FLAG
            MakeUsbPacketIsrRcvMsg(&rDmbSysConfig.msc1mem1.data[0],rDmbSysConfig.msc1mem1.subchsize+4);
		}
	}

	if(int_type_val1 & FIC_E_INT) // FIC interrupt
	{
		if(rDmbSysConfig.ficStatus1 == FIC_PARSING)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, FIC_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.ficmem1.data[4], rDmbSysConfig.ficmem1.subchsize);

			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x01); // FIC interrupt status clear

			rDmbSysConfig.ficmem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.ficmem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.ficmem1.data[2] = 0x01; // FIC
			rDmbSysConfig.ficmem1.data[3] = 0x01; // FLAG

                        MakeUsbPacketIsrRcvMsg(&rDmbSysConfig.ficmem1.data[0],rDmbSysConfig.ficmem1.subchsize+4);
		}
		else
		{
			if(int_type_val2 & RE_CONFIG_E_INT) // Re configuration
			{
				if(rDmbSysConfig.ficStatus1 == FIC_PARSED_OK)
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FIC_E_PAGE);
					PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.ficmem1.data[4], rDmbSysConfig.ficmem1.subchsize);

					PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x01); // FIC interrupt status clear

					rDmbSysConfig.ficmem1.data[0] = 0xFF; // SYNC
					rDmbSysConfig.ficmem1.data[1] = 0x0F; // PN_TYPE
					rDmbSysConfig.ficmem1.data[2] = 0x04; // Re_FIC
					rDmbSysConfig.ficmem1.data[3] = 0x02; // FLAG

                                        MakeUsbPacketIsrRcvMsg(&rDmbSysConfig.ficmem1.data[0],rDmbSysConfig.ficmem1.subchsize+4);
				}
			}
		}
	}

#if 1   // Reconfiguration test by terry 2010.08.27
	if(int_type_val2 & RE_CONFIG_E_INT) // Re configuration
	{
		if(rDmbSysConfig.ficStatus1 == FIC_PARSED_OK)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, COMM_8A, &cur_CIF_Cnt1);
			PN3030_Byte_Read(PN3030E_ADDR, COMM_8B, &Reconfig_CIF_Cnt1);

			if(Reconfig_CIF_Cnt1>=10)
			{
				if((cur_CIF_Cnt1 > (Reconfig_CIF_Cnt1-10)) && (cur_CIF_Cnt1 < Reconfig_CIF_Cnt1))
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, 0x0A);
					Reconfig_occurs_flag1 = TRUE;
				}
			}
			else
			{
				if((cur_CIF_Cnt1 > (239 +Reconfig_CIF_Cnt1))||(cur_CIF_Cnt1 < Reconfig_CIF_Cnt1))
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, 0x0A);
					Reconfig_occurs_flag1 = TRUE;
				}
			}

			if(Reconfig_occurs_flag1 == TRUE)
			{
				if(cur_CIF_Cnt1 > Reconfig_CIF_Cnt1)
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Read(PN3030E_ADDR, 0xE9, &sync_mode1);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, (sync_mode1 & 0xF7));
					Reconfig_occurs_flag1 = FALSE;
				}
			}
		}
	}
	else if(Reconfig_occurs_flag1 ==TRUE)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, 0xFB, &reconfig_stat1);
		if((reconfig_stat1 & 0x04)==0)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, 0xE9, &sync_mode1);
			PN3030_Byte_Write(PN3030E_ADDR, 0xE9, (sync_mode1 & 0xF7));
			Reconfig_occurs_flag1 = FALSE;
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0x49);
			PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0xC9); // FEC Soft reset
		}
	}
#endif

	if((int_type_val1 & MSC0_E_INT) || (int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))   // MSC0 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00);  // MSC0 memory control register clear.
			PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x0C);  // MSC0 memory enable.
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, MSC0_E_TSIZE_H, &mon_msc0_total[0], 2);
			rDmbSysConfig.msc0mem1.subchsize = (mon_msc0_total[0] << 8) | mon_msc0_total[1];

			PN3030_Reg_Page_Sel(PN3030E_ADDR, MSC0_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR,0x10,(PN_U8*)&rDmbSysConfig.msc0mem1.data[4],rDmbSysConfig.msc0mem1.subchsize);
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.

			DemodCopyMemory(PN_DABDEMOD_AUDIO, rDmbSysConfig.msc0mem1.data, rDmbSysConfig.msc0mem1.subchsize+4);

			rDmbSysConfig.msc0mem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc0mem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.msc0mem1.data[2] = 0x08; // MSC0
			rDmbSysConfig.msc0mem1.data[3] = 0x01; // FLAG

                         MakeUsbPacketIsrRcvMsg(&rDmbSysConfig.msc0mem1.data[0],rDmbSysConfig.msc0mem1.subchsize+4);
		}
	}
}

PN_VOID PN_INTERRUPT_SERVICE_ROUTINE2(PN_U8 pn_type)
{
	PN_U8 int_type_val1=0, int_type_val2=0;
	PN_U8 Reconfig_CIF_Cnt2=0, cur_CIF_Cnt2=0;
	PN_U8 sync_mode2 = 0, reconfig_stat2=0;
	PN_U8 mon_msc0_total[2];
	PN_U16 total_length=0;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, INT_E_STATL, &int_type_val1);
	PN3030_Byte_Read(PN3030E_ADDR, INT_E_STATH, &int_type_val2);

	if((int_type_val1 & MSC1_E_INT) || (int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))   // MSC1 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x00);  // MSC1 memory control register clear.
			PN3030_Byte_Write(PN3030E_ADDR, MSC1_E_CON, 0x0D);  // MSC1 memory enable.
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, MSC1_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.msc1mem2.data[4], rDmbSysConfig.msc1mem2.subchsize);
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.

			DemodCopyMemory(PN_DABDEMOD_AUDIO, rDmbSysConfig.msc1mem2.data, rDmbSysConfig.msc1mem2.subchsize+4);
#if 1
			rDmbSysConfig.msc1mem2.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc1mem2.data[1] = 0xF0; // PN_TYPE
			rDmbSysConfig.msc1mem2.data[2] = 0x02; // MSC1
			rDmbSysConfig.msc1mem2.data[3] = 0x01; // FLAG

			//PN30xxif_stmbuff_put_2(rDmbSysConfig.msc1mem2.data, rDmbSysConfig.msc1mem2.subchsize+4);
			//xthal_dcache_region_writeback(rDmbSysConfig.msc1mem2.data, rDmbSysConfig.msc1mem2.subchsize+4);
			//xthal_dcache_region_invalidate(rDmbSysConfig.msc1mem2.data, rDmbSysConfig.msc1mem2.subchsize+4);
#endif
		}
	}

	if(int_type_val1 & FIC_E_INT) // FIC interrupt
	{
		if(rDmbSysConfig.ficStatus2 == FIC_PARSING)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, FIC_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.ficmem2.data[4], rDmbSysConfig.ficmem2.subchsize);
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x01); // FIC interrupt status clear

			rDmbSysConfig.ficmem2.data[0] = 0xFF; // SYNC
			rDmbSysConfig.ficmem2.data[1] = 0xF0; // PN_TYPE
			rDmbSysConfig.ficmem2.data[2] = 0x01; // FIC
			rDmbSysConfig.ficmem2.data[3] = 0x01; // FLAG
			//PN30xxif_stmbuff_put_2(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);
			//xthal_dcache_region_writeback(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);
			//xthal_dcache_region_invalidate(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);
		}
		/*else
		{
			if(int_type_val2 & RE_CONFIG_E_INT) // Re configuration
			{
				if(rDmbSysConfig.ficStatus2 == FIC_PARSED_OK)
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FIC_E_PAGE);
					PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.ficmem2.data[4], rDmbSysConfig.ficmem2.subchsize);
					PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x01); // FIC interrupt status clear

					rDmbSysConfig.ficmem2.data[0] = 0xFF; // SYNC
					rDmbSysConfig.ficmem2.data[1] = 0xF0; // PN_TYPE
					rDmbSysConfig.ficmem2.data[2] = 0x04; // RE_FIC
					rDmbSysConfig.ficmem2.data[3] = 0x02; // FLAG

					PN30xxif_stmbuff_put_2(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);

					xthal_dcache_region_writeback(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);
					xthal_dcache_region_invalidate(rDmbSysConfig.ficmem2.data, rDmbSysConfig.ficmem2.subchsize+4);
				}
			}
		}*/
	}

#if 1   // Reconfiguration test by terry 2010.08.27
	if(int_type_val2 & RE_CONFIG_E_INT) // Re configuration
	{
		if(rDmbSysConfig.ficStatus1 == FIC_PARSED_OK)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, FIC_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.ficmem1.data[4], rDmbSysConfig.ficmem1.subchsize);

			PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, COMM_8A, &cur_CIF_Cnt2);
			PN3030_Byte_Read(PN3030E_ADDR, COMM_8B, &Reconfig_CIF_Cnt2);

			if(Reconfig_CIF_Cnt2>=10)
			{
				if((cur_CIF_Cnt2 > (Reconfig_CIF_Cnt2-10)) && (cur_CIF_Cnt2 < Reconfig_CIF_Cnt2))
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, 0x0A);
					Reconfig_occurs_flag2 = TRUE;
				}
			}
			else
			{
				if((cur_CIF_Cnt2 > (239 +Reconfig_CIF_Cnt2))&&(cur_CIF_Cnt2 < Reconfig_CIF_Cnt2))
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, 0x0A);
					Reconfig_occurs_flag2 = TRUE;
				}
			}

			if(Reconfig_occurs_flag2 == TRUE)
			{
				if(cur_CIF_Cnt2 > Reconfig_CIF_Cnt2)
				{
					PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
					PN3030_Byte_Read(PN3030E_ADDR, 0xE9, &sync_mode2);
					PN3030_Byte_Write(PN3030E_ADDR, 0xE9, (sync_mode2 & 0xF7));
					Reconfig_occurs_flag2 = FALSE;
				}
			}

			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x01); // FIC interrupt status clear

		/*	rDmbSysConfig.ficmem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.ficmem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.ficmem1.data[2] = 0x04; // Re_FIC
			rDmbSysConfig.ficmem1.data[3] = 0x02; // FLAG

			PN30xxif_stmbuff_put_1(rDmbSysConfig.ficmem1.data, rDmbSysConfig.ficmem1.subchsize+4);

			xthal_dcache_region_writeback(rDmbSysConfig.ficmem1.data, rDmbSysConfig.ficmem1.subchsize+4);
			xthal_dcache_region_invalidate(rDmbSysConfig.ficmem1.data, rDmbSysConfig.ficmem1.subchsize+4);*/
		}
	}
	else if(Reconfig_occurs_flag2 ==TRUE)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR, 0xFB, &reconfig_stat2);
		if((reconfig_stat2 & 0x04)==0)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, FEC_E_PAGE);
			PN3030_Byte_Read(PN3030E_ADDR, 0xE9, &sync_mode2);
			PN3030_Byte_Write(PN3030E_ADDR, 0xE9, (sync_mode2 & 0xF7));
			Reconfig_occurs_flag2 = FALSE;
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0x49);
			PN3030_Byte_Write(PN3030E_ADDR, OFDM_E_CON, 0xC9); // FEC Soft reset
		}
	}
#endif

	if((int_type_val1 & MSC0_E_INT) || (int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))   // MSC0 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x00);  // MSC0 memory control register clear.
			PN3030_Byte_Write(PN3030E_ADDR, MSC0_E_CON, 0x0C);  // MSC0 memory enable.
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.
		}
		else
		{
#if 1 // CIF MODE
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR,MSC0_E_TSIZE_H,&mon_msc0_total[0],2);
			total_length = (mon_msc0_total[0] << 8) | mon_msc0_total[1];

			if(total_length > rDmbSysConfig.msc0mem2.subchsize)
			{
				volatile int a;
				a = 10;
				a = 20;
			}

			PN3030_Reg_Page_Sel(PN3030E_ADDR, MSC0_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR,0x10,(PN_U8*)&rDmbSysConfig.msc0mem2.data[4],total_length);
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL,0x02); // MSC0 Interrupt clear.
/*
			xthal_dcache_region_writeback(rDmbSysConfig.msc0mem2.data, total_length+4);

			if( rDmbSysConfig.msc0mem2.data[4] != 0x04)
			{
				volatile int a;
				rP3_CTRL &= ~(0x0200);
				rP3_DATA |= (0x0200);
				a = 10;
				a = 20;
				rP3_DATA &= ~(0x0200);
				return;
			}
*/
			rDmbSysConfig.msc0mem2.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc0mem2.data[1] = 0xF0; // PN_TYPE
			rDmbSysConfig.msc0mem2.data[2] = 0x08; // MSC0
			rDmbSysConfig.msc0mem2.data[3] = 0x01; // FLAG

			//PN30xxif_stmbuff_put_2(rDmbSysConfig.msc0mem2.data, total_length+4);
			//xthal_dcache_region_writeback(rDmbSysConfig.msc0mem2.data, total_length+4);
			//xthal_dcache_region_invalidate(rDmbSysConfig.msc0mem2.data, total_length+4);
#else // Threshold MODE
			PN3030_Reg_Page_Sel(PN3030E_ADDR, MSC0_E_PAGE);
			PN3030_Burst_Read(PN3030E_ADDR, 0x10, &rDmbSysConfig.msc0mem2.data[4], rDmbSysConfig.msc0mem2.subchsize);
			PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
			PN3030_Byte_Write(PN3030E_ADDR, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.

			rDmbSysConfig.msc0mem2.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc0mem2.data[1] = 0xF0; // PN_TYPE
			rDmbSysConfig.msc0mem2.data[2] = 0x08; // MSC0
			rDmbSysConfig.msc0mem2.data[3] = 0x01; // FLAG
			PN30xxif_stmbuff_put_2(rDmbSysConfig.msc0mem2.data, rDmbSysConfig.msc0mem2.subchsize+4);
			xthal_dcache_region_writeback(rDmbSysConfig.msc0mem2.data, rDmbSysConfig.msc0mem2.subchsize+4);
			xthal_dcache_region_invalidate(rDmbSysConfig.msc0mem2.data, rDmbSysConfig.msc0mem2.subchsize+4);
#endif
		}
	}
}



PN_VOID PN_ISR_FM(PN_U8 pn_type)
{
	PN_U8 int_type_val1=0;

	PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
	PN3030_Byte_Read(pn_type, INT_E_STATL, &int_type_val1);

	if((int_type_val1 & MSC1_E_INT) || (int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC1_E_OVER_FLOW) || (int_type_val1 & MSC1_E_UNDER_FLOW))   // MSC1 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
			PN3030_Byte_Write(pn_type, MSC1_E_CON, 0x00);  // MSC1 memory control register clear.
			PN3030_Byte_Write(pn_type, MSC1_E_CON, 0x0D);  // MSC1 memory enable.
			PN3030_Byte_Write(pn_type, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.
		}
		else
		{
			PN3030_Reg_Page_Sel(pn_type, MSC1_E_PAGE);
			PN3030_Burst_Read(pn_type, 0x10, &rDmbSysConfig.msc1mem1.data[4], rDmbSysConfig.msc1mem1.subchsize);
#if 0 // noah 일단삭제
			if(FM_PLAY)
			{
				DemodFMMemory((PN_U8 *)&rDmbSysConfig.msc1mem1.data[4], rDmbSysConfig.msc1mem1.subchsize);
			}
#endif
			rDmbSysConfig.msc1mem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc1mem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.msc1mem1.data[2] = 0x02; // MSC1
			rDmbSysConfig.msc1mem1.data[3] = 0x01; // FLAG
#if 0 // noah 일단삭제
			PN30xxif_stmbuff_put_1(rDmbSysConfig.msc1mem1.data, rDmbSysConfig.msc1mem1.subchsize+4);
			xthal_dcache_region_writeback(rDmbSysConfig.msc1mem1.data, rDmbSysConfig.msc1mem1.subchsize+4);
			xthal_dcache_region_invalidate(rDmbSysConfig.msc1mem1.data, rDmbSysConfig.msc1mem1.subchsize+4);
#endif
			PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
			PN3030_Byte_Write(pn_type, INT_E_UCLRL, 0x04); // MSC1 Interrupt status clear.
 		}
	}

	if((int_type_val1 & MSC0_E_INT) || (int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))
	{
		if((int_type_val1 & MSC0_E_OVER_FLOW) || (int_type_val1 & MSC0_E_UNDER_FLOW))   // MSC0 memory overflow or under run
		{
			PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
			PN3030_Byte_Write(pn_type, MSC0_E_CON, 0x00);  // MSC0 memory control register clear.
			PN3030_Byte_Write(pn_type, MSC0_E_CON, 0x0D);  // MSC0 memory enable.
			PN3030_Byte_Write(pn_type, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.
		}
		else // Threshold MODE
		{
			PN3030_Reg_Page_Sel(pn_type, MSC0_E_PAGE);
			PN3030_Burst_Read(pn_type, 0x10, &rDmbSysConfig.msc0mem1.data[4], rDmbSysConfig.msc0mem1.subchsize);

			rDmbSysConfig.msc0mem1.data[0] = 0xFF; // SYNC
			rDmbSysConfig.msc0mem1.data[1] = 0x0F; // PN_TYPE
			rDmbSysConfig.msc0mem1.data[2] = 0x08; // MSC0
			rDmbSysConfig.msc0mem1.data[3] = 0x01; // FLAG
#if 0 // noah 일단삭제
			PN30xxif_stmbuff_put_2(rDmbSysConfig.msc0mem1.data, rDmbSysConfig.msc0mem1.subchsize+4);
			xthal_dcache_region_writeback(rDmbSysConfig.msc0mem1.data, rDmbSysConfig.msc0mem1.subchsize+4);
			xthal_dcache_region_invalidate(rDmbSysConfig.msc0mem1.data, rDmbSysConfig.msc0mem1.subchsize+4);
#endif
			PN3030_Reg_Page_Sel(pn_type, DD_E_PAGE);
			PN3030_Byte_Write(pn_type, INT_E_UCLRL, 0x02); // MSC0 Interrupt clear.
 		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// DMB, DAB, DAB+ memory copy to I2S codec                                 //
/////////////////////////////////////////////////////////////////////////////
PN_VOID DemodCopyMemory(PN_U8 type, PN_U8 *srcPtr, PN_U32 siz)
{
#if 0
	PN_U32 remain;
	PN_DabBufIdx_t *pDabBufIdx;
	PN_U8 *tBufStart;

	if (type == PN_DABDEMOD_AUDIO)
	{
		pDabBufIdx = &AudBufIdx;
		tBufStart = 0;//삭제//(PN_U8*)PN_DMA_DAB_BUF_ADDR;

		if((pDabBufIdx->gDabBufWrIdx + siz) > 0xB00)
		{
			pDabBufIdx->gDabBufWrIdx = 0;
		}

		memmove(tBufStart + pDabBufIdx->gDabBufWrIdx, srcPtr, siz);
		memmove(tBufStart + pDabBufIdx->gDabBufWrIdx, (PN_U8*)&siz, 4);
		pDabBufIdx->gDabBufWrIdx += (siz);
		//PN_MediaAudSetBuffer((PN_U8 *)PN_DMA_DAB_BUF_ADDR);
		return;
	}
	else
	{
		pDabBufIdx = &DataBufIdx;
		tBufStart = (PN_U8*)PN_DabDsBuff;
		if ((PN_DAB_DS_MAX_BUFF_SIZE - pDabBufIdx->gDabFilled) < siz)
			return;
		remain = PN_DAB_DS_MAX_BUFF_SIZE - pDabBufIdx->gDabBufWrIdx;
	}

	if (remain >= siz)
	{
		memmove(tBufStart + pDabBufIdx->gDabBufWrIdx, srcPtr, siz);
		pDabBufIdx->gDabBufWrIdx += (siz);
		if (remain == siz)
			pDabBufIdx->gDabBufWrIdx = 0;
	}
	else
	{
		memmove(tBufStart + pDabBufIdx->gDabBufWrIdx, srcPtr, remain);
		pDabBufIdx->gDabBufWrIdx = 0;
		memmove(tBufStart, srcPtr + remain, siz - remain);
		pDabBufIdx->gDabBufWrIdx += (siz - remain);
	}

	pDabBufIdx->gDabFilled += siz;			 //currently filled data count
#endif
}

PN_DabBufIdx_t *PN_GetDabBufIdx(PN_VOID)
{
	return &AudBufIdx;
}



/////////////////////////////////////////////////////////////////////////////
// RF and PN3030EV initialization function                                 //
/////////////////////////////////////////////////////////////////////////////
PN_S32 PN_BB_RF_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq)
{
	if(EV_OPERATE(pn_type) == PN_FN_FAIL)
		return PN_FN_FAIL;

	EV_INIT(pn_type, tuner, freq); 

	PN_INIT_TUNER(pn_type, tuner, freq);

	EV_INTERRUPT_SETUP(pn_type);

	EV_SOFT_RESET(pn_type,PN_OFDM_FEC);

	return PN_FN_OK;
}

PN_S32 PN_Frequency_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 *tr_mode)
{
	EV_INIT(pn_type, tuner, freq); 

	PN_INIT_TUNER(pn_type, tuner, freq);

	EV_INTERRUPT_SETUP(pn_type);

	EV_SOFT_RESET(pn_type,PN_OFDM_FEC);
	
	Delay_Ms(700);	//700ms delay

	switch(tuner)
	{
		case PNS3030D:
		case PNS3030A:
			if(EV_OFDM_LOCK_STAT(pn_type, tuner, tr_mode, 30) == PN_UNLOCK)
				return PN_UNLOCK;
			break;
		case MAX2172:
			if(MAX2172_OFDM_LOCK_STAT(pn_type, tuner, tr_mode, 30) == PN_UNLOCK)
				return PN_UNLOCK;
			break;
			default:
				break;
	}
	return PN_FN_OK;
}

PN_S32 PN_Scan_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 *tr_mode)
{
	DEBUG_INFO_HI("TRACE_SCAN_INIT","entry");
	
	//PN_BB_RF_Init(pn_type,tuner,freq);
	//EV_INIT(pn_type, tuner, freq);          // o
	//PN_INIT_TUNER(pn_type, tuner, freq);    // x
	//EV_INTERRUPT_SETUP(pn_type);            // x
	//EV_SOFT_RESET(pn_type,PN_OFDM_FEC);     // x
	//Delay_Ms(700);	//700ms delay
	
        //EV_INIT_TOP(PN3030E_ADDR, tuner);           // x
	//EV_INIT_COMM(PN3030E_ADDR, tuner);        // x
	//EV_INIT_HOST(PN3030E_ADDR, tuner);        // x
	EV_INIT_OFDM(PN3030E_ADDR, tuner, freq);  // 181280 184008에서 계속 timeout 하지만, OK 잘넘어감
	//EV_INIT_FEC(PN3030E_ADDR, tuner);         // x
        //EV_FM_DEFAULT(PN3030E_ADDR);              // x

	if((tuner == PNS3030D) || (tuner == PNS3030A))
	{
		if(EV_CHANNEL_SCAN_CONTROL(pn_type, tuner, freq))
		{
			if(EV_OFDM_LOCK_STAT(pn_type, tuner, tr_mode, 2) == PN_UNLOCK)
			{
				DEBUG_INFO_HI(TRACE_SCAN_INIT,"EV_CHANNEL_SCAN_CONTROL PN_UNLOCK!");
				return PN_UNLOCK;
			}
			else
			{
				DEBUG_INFO_HI(TRACE_SCAN_INIT,"EV_CHANNEL_SCAN_CONTROL OK!");
				return PN_FN_OK;
			}
		}
		else
		{
			DEBUG_INFO_HI(TRACE_SCAN_INIT,"EV_CHANNEL_SCAN_CONTROL failed");
		}
	}
	else if (tuner == MAX2172)
	{
		if(MAX2172_CHANNEL_SCAN_CONTROL(pn_type, tuner, freq))
		{
			if(MAX2172_OFDM_LOCK_STAT(pn_type, tuner, tr_mode, 100) == PN_UNLOCK)
				return PN_UNLOCK;
			else
				return PN_FN_OK;
		}
	}

	return PN_SCAN_FAIL;
}

PN_VOID PN_Status_Check(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 DMB_play_flag)
{
	PN_S16 sig_leval=0;
	PN_S16 rssi_leval=0;
	PN_S8 sig_bar=0;

	PN_U8 tr_mode, iq_inv, cfreq; 
	PN_U16 null_len, con_vari;
	PN_S32 snr, snr_bar; 

	PN_U8  rs_sync; 
	PN_U32 bit_cnt, bit_val; 
	PN_U16 ts_err;

	PN_U8  agc,coarse,time,ofdm; 

	PN_U8  fic_crc; 
	PN_U16 fic_val, fic_cnt; 
	PN_U32 msc_val, msc_cnt;
	PN_U32 zero_ber;

	PN_U8  mode,frame,symbol; 
	PN_S8  mon_diff_i=0, mon_diff_q=0;
	
	PN_U8 tii_c1=0, tii_p1=0;
	PN_U16 tii_s1=0;

	if(DMB_play_flag == 0)
	{
		switch(tuner)
		{
			case PNS3030D:
			case PNS3030A:
				EV_RSSI_STAT(pn_type, &sig_leval, &sig_bar, freq);
				break;
			case MAX2172:
				EV_MAX2172_RSSI_STAT(pn_type, &sig_leval, &sig_bar, freq);
				break;
			default:
				break;
		}
		
		rssi_leval = sig_leval;
		memcpy(&gStatusBuff[0], &rssi_leval, 2); // RSSI sig_level
		memcpy(&gStatusBuff[8], &sig_bar,    2); // RSSI sig_bar
	}

	// OFDM STATUS	
	EV_OFDM_STAT(pn_type, &tr_mode, &null_len, &iq_inv, &con_vari, &snr_bar, &snr, tuner, &cfreq);
	tr_mode = tr_mode + 1;
	memcpy(&gStatusBuff[12], &tr_mode,  1); // TR_MODE	 
	memcpy(&gStatusBuff[13], &null_len, 2); // NULL_LENGTH
	memcpy(&gStatusBuff[15], &iq_inv,   1); // IQ_INV
	memcpy(&gStatusBuff[16], &con_vari, 2); // CON_VARI
	memcpy(&gStatusBuff[18], &snr_bar,  4); // snr_bar
	memcpy(&gStatusBuff[22], &snr,      4); // snr	
	memcpy(&gStatusBuff[26], &cfreq,    1); // CFREQ

	//RS STATUS
	EV_RS_STAT(pn_type, &rs_sync, &bit_cnt, &bit_val, &ts_err);
	memcpy(&gStatusBuff[27], &rs_sync, 1); // rs_sync	 
	memcpy(&gStatusBuff[28], &bit_cnt, 4); // bit_cnt
	memcpy(&gStatusBuff[32], &bit_val, 4); // bit_val
	memcpy(&gStatusBuff[36], &ts_err,  2); // alarm_err

	//LOCK STATUS
	EV_ALL_LOCK_STAT(pn_type, &agc, &coarse, &time, &ofdm);
	memcpy(&gStatusBuff[38], &agc,    1); // AGC_status	 
	memcpy(&gStatusBuff[39], &coarse, 1); // Coarse_Lock_Status
	memcpy(&gStatusBuff[40], &time,   1); // Time_Lock_Status
	memcpy(&gStatusBuff[41], &ofdm,   1); // OFDM_LOCK_Status	 
	
	//FEC STATUS
	EV_CHANNEL_STAT(pn_type, &fic_crc, &fic_val, &fic_cnt, &msc_val, &msc_cnt, &zero_ber);
	memcpy(&gStatusBuff[42], &fic_crc, 1); // fic_crc	 
	memcpy(&gStatusBuff[43], &fic_val, 2); // fic_val
	memcpy(&gStatusBuff[45], &fic_cnt, 2); // fic_cnt
	memcpy(&gStatusBuff[47], &msc_val, 4); // msc_val
	memcpy(&gStatusBuff[51], &msc_cnt, 4); // msc_cnt
	memcpy(&gStatusBuff[55], &zero_ber, 4); // zero_ber

	if(pn_type == 0)
	{
		//MRC STATUS
		EV_MRC_STATUS(pn_type, &mode, &frame, &symbol);
		memcpy(&gStatusBuff[59], &mode,   1); // MRC_Mode	 
		memcpy(&gStatusBuff[60], &frame,  1); // Frame_Sync
		memcpy(&gStatusBuff[61], &symbol, 1); // Symbol_Sync	
	}
	EV_CONSTELL_STAT(pn_type, &mon_diff_i, &mon_diff_q);
	memcpy(&gStatusBuff[62], &mon_diff_i, 1); // Constellation I
	memcpy(&gStatusBuff[63], &mon_diff_q, 1); // Constellation Q
		
	EV_TII_MON_STAT(pn_type, &tii_c1, &tii_p1, &tii_s1);
	memcpy(&gStatusBuff[64], &tii_c1, 1); // TII C1
	memcpy(&gStatusBuff[65], &tii_p1, 1); // TII P1
	memcpy(&gStatusBuff[66], &tii_s1, 2); // TII S1
}

PN_VOID PN_Status_Check2(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 DMB_play_flag)
{
	PN_U8 tr_mode, iq_inv, cfreq; 
	PN_U16 null_len, con_vari;
	PN_S32 snr, snr_bar; 
	
	PN_U8 fsm, adc_over, ascv, fft_vcnt, clk_cnt, tclk_cnt, coef;
	PN_S8 tscv;
	PN_S8 toffset;
	PN_S32 facc, tacc;
	PN_U16 sym_offset, post_agc, pre_agc;

	PN_U8  rs_sync; 
	PN_U32 bit_cnt, bit_val; 
	PN_U16 ts_err;

	PN_U8  agc,coarse,time,ofdm; 

	PN_U8  fic_crc; 
	PN_U16 fic_val, fic_cnt; 
	PN_U32 msc_val, msc_cnt;
	PN_U8 fec_sync_f, rnorm_cnt;
	PN_U32 zero_ber;
	

	PN_U8 co_ch_sel, co_ch_cnt, co_ch_lock;
	PN_U16 co_ch_start, co_ch_end, co_ch_apwr;

	PN_U8  mode,frame,symbol; 
	
	PN_S16 mon_imb_i,mon_imb_q;
    PN_U8 fic_spec_mon;
    
    //Echo Mon STATUS
    PN_U8 id_on;
    PN_U16 pre_des, post_des;
    PN_U8 echo_lock, echo_pre_lcnt, echo_post_lcnt;
    
    PN_U8 o_vari, out_sel, fec_ndata;
    
    PN_U16 notACS_fic, notACS_msc, renorm_fic, renorm_msc, total_subchsize, current_subchsize;
    PN_U8 cif_cnt, recon_cif;
    
    PN_U8 scan_mon;
    PN_U16 mon_scan_pwr;
    
    PN_U8 rf_reg00, rf_reg01, rf_reg02, rf_reg04, rf_reg15;

	//OFDM STATUS	
	EV_OFDM_STAT(pn_type, &tr_mode, &null_len, &iq_inv, &con_vari, &snr_bar, &snr, tuner, &cfreq);
	EV_OFDM_STAT2(pn_type, &fsm, &adc_over, &ascv, &tscv, &fft_vcnt, &clk_cnt, &tclk_cnt);
	EV_OFDM_STAT3(pn_type, &facc, &toffset, &tacc, &sym_offset, &coef, &post_agc, &pre_agc);
	
	tr_mode = tr_mode + 1;
	//LOCK STATUS
	EV_ALL_LOCK_STAT(pn_type, &agc, &coarse, &time, &ofdm);
	
	memcpy(&gStatusBuff[0], &agc,        1); // AGC_status	 
	memcpy(&gStatusBuff[1], &coarse,     1); // Coarse_Lock_Status
	memcpy(&gStatusBuff[2], &time,       1); // Time_Lock_Status
	memcpy(&gStatusBuff[3], &ofdm,       1); // OFDM_LOCK_Status	
	
	memcpy(&gStatusBuff[4], &tr_mode,    1);
	memcpy(&gStatusBuff[5], &iq_inv,     1);
	memcpy(&gStatusBuff[6], &null_len,   2);
	memcpy(&gStatusBuff[8], &con_vari,   2);
	memcpy(&gStatusBuff[10], &cfreq,     1);
	
	memcpy(&gStatusBuff[11], &fsm,       1);   
	memcpy(&gStatusBuff[12], &adc_over,  1);  
	memcpy(&gStatusBuff[13], &ascv,      1);  
	memcpy(&gStatusBuff[14], &tscv,      1);  
	memcpy(&gStatusBuff[15], &fft_vcnt,  1);  
	memcpy(&gStatusBuff[16], &clk_cnt,   1);  
	memcpy(&gStatusBuff[17], &tclk_cnt,  1);  
	
	memcpy(&gStatusBuff[18], &facc,      4);         
	memcpy(&gStatusBuff[22], &toffset,   1);        
	memcpy(&gStatusBuff[23], &tacc,      4);       
	memcpy(&gStatusBuff[27], &sym_offset,2);       
	memcpy(&gStatusBuff[29], &coef,      1);        
	memcpy(&gStatusBuff[30], &post_agc,  2); 	       
	memcpy(&gStatusBuff[32], &pre_agc,   2);        

	//FEC STATUS
	EV_CHANNEL_STAT(pn_type, &fic_crc, &fic_val, &fic_cnt, &msc_val, &msc_cnt, &zero_ber);
	EV_CHANNEL_STAT2(pn_type, &fec_sync_f, &rnorm_cnt);
	//RS STATUS
	EV_RS_STAT(pn_type, &rs_sync, &bit_cnt, &bit_val, &ts_err);
	
	memcpy(&gStatusBuff[34], &fec_sync_f,1); // fec_sync_flag	 
	memcpy(&gStatusBuff[35], &rnorm_cnt, 1); // rnorm_cnt        
	memcpy(&gStatusBuff[36], &fic_crc,   1); // fic_crc
	memcpy(&gStatusBuff[37], &fic_val,   2); // fic_val
	memcpy(&gStatusBuff[39], &fic_cnt,   2); // fic_cnt
	memcpy(&gStatusBuff[41], &msc_val,   4); // msc_val
	memcpy(&gStatusBuff[45], &msc_cnt,   4); // msc_cnt	
	
	if(rs_sync)
	{
		memcpy(&gStatusBuff[49], &rs_sync, 1); 
		memcpy(&gStatusBuff[50], &bit_val, 4); 
		memcpy(&gStatusBuff[54], &bit_cnt, 4); 
		memcpy(&gStatusBuff[58], &ts_err,  2); 	
	}
	else
	{
		memcpy(&gStatusBuff[49], &rs_sync, 1); 
		memcpy(&gStatusBuff[50], &bit_val, 4); 
		memcpy(&gStatusBuff[54], &bit_cnt, 4); 
		memcpy(&gStatusBuff[58], &ts_err,  2); 
	} 
	
	EV_OFDM_STAT4(pn_type, &co_ch_sel, &co_ch_cnt, &co_ch_lock, &co_ch_start, &co_ch_end, &co_ch_apwr);
	memcpy(&gStatusBuff[60], &co_ch_sel,  1);      
	memcpy(&gStatusBuff[61], &co_ch_cnt,  1);        
	memcpy(&gStatusBuff[62], &co_ch_lock, 1);       
	memcpy(&gStatusBuff[63], &co_ch_start,2);       
	memcpy(&gStatusBuff[65], &co_ch_end,  2);       
	memcpy(&gStatusBuff[67], &co_ch_apwr, 2);        

	if(pn_type == 0)
	{		//MRC STATUS
		EV_MRC_STATUS(pn_type, &mode, &frame, &symbol);
		memcpy(&gStatusBuff[69], &mode,   1); // MRC_Mode	 
		memcpy(&gStatusBuff[70], &frame,  1); // Frame_Sync
		memcpy(&gStatusBuff[71], &symbol, 1); // Symbol_Sync	
	}
	EV_OFDM_STAT5(pn_type, &mon_imb_i, &mon_imb_q, &fic_spec_mon);
	memcpy(&gStatusBuff[72], &mon_imb_i,  2);       
	memcpy(&gStatusBuff[74], &mon_imb_q,  2);  
	memcpy(&gStatusBuff[76], &fic_spec_mon, 1);  
	
	EV_OFDM_STAT6(pn_type, &id_on, &pre_des, &post_des,&echo_lock, &echo_pre_lcnt, &echo_post_lcnt, &o_vari,&out_sel,&fec_ndata);
	memcpy(&gStatusBuff[77], &id_on, 1);  
	memcpy(&gStatusBuff[78], &pre_des, 2);  
	memcpy(&gStatusBuff[80], &post_des, 2);  
	memcpy(&gStatusBuff[82], &echo_lock, 1);  
	memcpy(&gStatusBuff[83], &echo_pre_lcnt, 1);  
	memcpy(&gStatusBuff[84], &echo_post_lcnt, 1);  
	
	memcpy(&gStatusBuff[85], &o_vari, 1);  
	memcpy(&gStatusBuff[86], &out_sel, 1);  
	memcpy(&gStatusBuff[87], &fec_ndata, 1);  
	
	EV_OFDM_STAT7(pn_type, &notACS_fic, &notACS_msc, &renorm_fic, &renorm_msc, &total_subchsize, &current_subchsize, &cif_cnt, &recon_cif);
	memcpy(&gStatusBuff[88], &notACS_fic, 2);  
	memcpy(&gStatusBuff[90], &notACS_msc, 2);  
	memcpy(&gStatusBuff[92], &renorm_fic, 2);  
	memcpy(&gStatusBuff[94], &renorm_msc, 2);  
	memcpy(&gStatusBuff[96], &total_subchsize, 2);  
	memcpy(&gStatusBuff[98], &current_subchsize, 2);  
	memcpy(&gStatusBuff[100], &cif_cnt, 1);  
	memcpy(&gStatusBuff[101], &recon_cif, 1); 
	
	EV_OFDM_STAT8(pn_type,&scan_mon, &mon_scan_pwr);
	memcpy(&gStatusBuff[102], &scan_mon, 1); 
	memcpy(&gStatusBuff[103], &mon_scan_pwr, 2); 
	
	EV_RF_STAT(pn_type, &rf_reg00, &rf_reg01, &rf_reg02, &rf_reg04, &rf_reg15);
	memcpy(&gStatusBuff[105], &rf_reg00, 1); 
	memcpy(&gStatusBuff[106], &rf_reg01, 1); 
	memcpy(&gStatusBuff[107], &rf_reg02, 1); 
	memcpy(&gStatusBuff[108], &rf_reg04, 1); 
	memcpy(&gStatusBuff[109], &rf_reg15, 1); 
}

PN_S16 PN_RSSI_Check(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_S8 *sig_bar)
{
	PN_S16 sig_leval=0;
	PN_S16 rssi_leval;
	PN_S8 signal_bar=0;

	switch(tuner)
	{
		case PNS3030D:
		case PNS3030A:
			EV_RSSI_STAT(pn_type, &sig_leval, &signal_bar, freq);
			break;	
		case MAX2172:
			EV_MAX2172_RSSI_STAT(pn_type, &sig_leval, &signal_bar, freq);
			break;
		default:
			break;
	}
	rssi_leval = sig_leval;
	*sig_bar = signal_bar;

	return rssi_leval;
}

PN_VOID PN_Service_Reset(PN_U8 pn_type, PN_U8 rst_fic_mem, PN_U8 rst_msc0_mem, PN_U8 rst_msc1_mem)
{
	if(rst_fic_mem  == PN_FIC_MEN)	{ EV_RESET_FIC_MEM(pn_type);	}
	if(rst_msc0_mem == PN_MSC0_MEN)	{ EV_RESET_MSC0_MEM(pn_type);	EV_CLEAR_MSC0_SUBCH(pn_type);	}
	if(rst_msc1_mem == PN_MSC1_MEN)	{ EV_RESET_MSC1_MEM(pn_type);	EV_CLEAR_MSC1_SUBCH(pn_type);	}
} 

/////////////////////////////////////////////////////////////////////////////
// PN3030EV sub-channel id setting for the audio, data, video service      //
/////////////////////////////////////////////////////////////////////////////
PN_VOID PN_Subchannel_Set(PN_U8 pn_type, PN_U8 service, PN_U8 ADscty, PN_U8 subch, PN_U16 pkt_addr, PN_U8 subch_on, PN_U16 dump_size)
{
	PN_Service_Reset(1, 0, 0, PN_MSC1_MEN);
	PN_Service_Reset(0, 0, 0, PN_MSC1_MEN);
	//Audio//PN_MediaAudioStop(PN_AS_DAB, 0);
	
	switch(service) 
	{
		case AUDIO_SERVICE:
			EV_SET_PATH_AUDIO_SUBCH(pn_type, subch, subch_on);
			//Audio//PN_DemodDabAudioBufIdxInit();
			//Audio//PN_MediaAudioStart(PN_AS_DAB, dump_size, ADscty);
			break;
		case DATA_SERVICE:
			EV_SET_PATH_DATA_SUBCH(pn_type, subch, subch_on);
			//Audio//PN_DemodDabAudioBufIdxInit();
			//PN_DemodDmaDabDataBufIdxInit();
			//Audio//PN_MediaAudioStart(PN_AS_DAB, dump_size, ADscty);
			break;
		case PKT_SERVICE:
			EV_SET_PATH_PKT_SUBCH(pn_type, subch, pkt_addr);
			//Audio//PN_DemodDmaDabDataBufIdxInit();
			break;
		case VIDEO_SERVICE:
			EV_SET_PATH_VIDEO_SUBCH(pn_type, subch, subch_on);
			//Audio//PN_DemodDabAudioBufIdxInit();
			//Audio//PN_MediaAudioStart(PN_AS_DAB, dump_size, ADscty);
			break;
		case RE_CONFIG_SVR:
			break;
		default:
			break;
	}
}

/////////////////////////////////////////////////////////////////////////////
// PN3030EV Memory map control in FIC, PAD, MSC0, MSC1, MSC2, NIS, TII     //
/////////////////////////////////////////////////////////////////////////////
PN_VOID PN_Memory_Setup(PN_U8 pn_type, PN_U8 mem_mode, PN_U16 dump_size)
{
	switch(mem_mode)
	{
		case PN_FIC_MEN:
			EV_SETUP_FIC_MEM(pn_type);
			break;
		case PN_FIDC_MEN:
		case PN_MSC0_MEN:
			EV_SETUP_MSC0_MEM(pn_type, dump_size, dump_size);
			break;
		case PN_MSC1_MEN:
			EV_SETUP_MSC1_MEM(pn_type, dump_size, dump_size);
			break;
		case PN_MSC1_FM_MEN:
			EV_SETUP_MSC1_FM_MEM(pn_type, dump_size, dump_size);
		case PN_MSC0_RDS_MEN:
			EV_SETUP_MSC0_RDS_MEM(pn_type, dump_size, dump_size);
			break;
		default :
			break;
	}
}

PN_VOID PN_FIDC_Setup(PN_U8 pn_type, PN_U8 on_off)
{
	if(on_off)
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, DD_E_TOPCON, 0xA2);

		PN_Memory_Setup(pn_type, PN_FIDC_MEN, 0);
//		PN_SetMemorySize(pn_type, PN_FIDC_MEN, 0);
		EV_UNMASK_INTERRUPT(pn_type, PN_FIDC_MEN, 0);
	}
	else
	{
		PN3030_Reg_Page_Sel(PN3030E_ADDR, DD_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, DD_E_TOPCON, 0xA0);
	}
}






















/////////////////////////////////////////////////////////////////////////////
// RF and PN3030EV initialization function                                 //
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// PN3030EV Register Read, Write check                                     //
/////////////////////////////////////////////////////////////////////////////
PN_U8 PN_REG_Check(PN_U8 pn_type, PN_U8 RW_Type, PN_U8 page, PN_U8 reg_addr, PN_U8 reg_val, PN_U8 rf_set, PN_U8 tuner_type)
{
	PN_U8 reg_data = 0xFF;

	if(rf_set==0)
	{
		if(RW_Type)
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, page);
			PN3030_Byte_Write(PN3030E_ADDR, reg_addr, reg_val);
		}
		else
		{
			PN3030_Reg_Page_Sel(PN3030E_ADDR, page);
			PN3030_Byte_Read(PN3030E_ADDR, reg_addr, &reg_data);
		}
	}
	else
	{
		if(RW_Type)
		{
			EV_WRITE_TUNER_REG(PN3030E_ADDR, page, reg_addr, reg_val);
		}
		else
		{
			EV_READ_TUNER_REG(PN3030E_ADDR, page, reg_addr, &reg_data);
		}
	}

	return reg_data;
}

/////////////////////////////////////////////////////////////////////////////
// PN3030EV access to RF device by using IIC interface                       //
/////////////////////////////////////////////////////////////////////////////
PN_VOID WRITE_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 value)
{
	EV_WRITE_TUNER_REG(pn_type, chip_addr, reg_addr, value);
}

PN_VOID WRITE_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size)
{
	EV_WRITE_TUNER_BURST(pn_type, chip_addr, reg_addr, value, size);
}

PN_VOID READ_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value)
{
	EV_READ_TUNER_REG(pn_type, chip_addr, reg_addr, value);
}

PN_VOID READ_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size)
{
	EV_READ_TUNER_BURST(pn_type, chip_addr, reg_addr, value, size);
}

/////////////////////////////////////////////////////////////////////////////
// FM function                                                                                      //
/////////////////////////////////////////////////////////////////////////////
PN_VOID PN_FM_Scan_Init(PN_U8 pn_type)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);
	PN3030_Byte_Write(PN3030E_ADDR, FMF1, 0xE4);
}

PN_VOID PN_FM_Status_Check(PN_U8 pn_type, PN_U8 tuner_type, PN_U32 frequency)
{
	PN_U8  PILOT_LOCK, RDS_LOCK, RDS_GAIN, PILOT_CNT;
	//PN_S32 FM_DC =0;
	PN_U8  FM_VARIANCE =0;
	PN_S16 FM_RSSI = 0;
	PN_S8 FM_SIG_BAR = 0;
	PN_U8 FM_OSC57 = 0;
	PN_S32 RDS_TOFFSET=0;

	EV_FMRDS_STAT(pn_type, &PILOT_LOCK, &RDS_LOCK, &RDS_GAIN, &FM_OSC57, &PILOT_CNT);
	EV_FMRDS_ERR(pn_type, &FM_DC, &FM_VARIANCE, &RDS_TOFFSET);

	FM_RSSI = PN_RSSI_Check(pn_type, tuner_type, frequency, &FM_SIG_BAR);

#if 1 // FM DC Test

	FM_DC = FM_DC / 2048;

	if(0x200 & FM_DC)
	{
		FM_DC = 0xFFFFFE00 | FM_DC;
	}

#endif

#if 0 // AGC Test
	PN_S32 PRE_AGC, POST_AGC;

	PRE_AGC = EV_AGC_STAT(pn_type); // Pre AGC Test
	POST_AGC = EV_POST_AGC_STAT(pn_type); // Post AGC Test
#endif

#if 0 // Automatic Stereo mono change

static PN_U32 counter = 0;
static PN_FLOAT fData_Sum = 0, fData_RSSI = 0, fData_Vari = 0;

//********************* RSSI Stereo mono change *****************

	fData_Sum += FM_RSSI;
	if (counter == 2)
	{
		fData_RSSI = fData_Sum;
		fData_Sum = 0;
		counter = 0;
	}
	counter++;

	if ((signed int)fData_RSSI > -170.)
	{
//		PNP_FMCB.STEREO_ON = TRUE;
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x45); // STEREO play
	}
	else
	{
//		PNP_FMCB.STEREO_ON = FALSE;
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x43); // MONO play
	}

//********************* Variance Stereo mono change ***************

	fData_Sum += FM_VARIANCE;
	if (counter == 7)
	{
		fData_Vari = fData_Sum;
		fData_Sum = 0;
		counter = 0;
	}
	counter++;

	if ((signed int)fData_Vari < 25.)
	{
//		PNP_FMCB.STEREO_ON = TRUE;
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x45); // STEREO play
	}
	else
	{
//		PNP_FMCB.STEREO_ON = FALSE;
		PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x43); // MONO play
	}

#endif

//********************* FM Status Dispaly **********************

	memcpy(&gFMStatusBuff[0], &PILOT_LOCK, 1);
	memcpy(&gFMStatusBuff[1], &RDS_LOCK, 1);
	memcpy(&gFMStatusBuff[2], &RDS_GAIN, 1);
	memcpy(&gFMStatusBuff[3], &FM_OSC57, 1);
	memcpy(&gFMStatusBuff[4], &PILOT_CNT, 1);
	memcpy(&gFMStatusBuff[5], &FM_DC, 4);
	memcpy(&gFMStatusBuff[9], &FM_VARIANCE, 1);
	memcpy(&gFMStatusBuff[10], &FM_RSSI, 4);
	memcpy(&gFMStatusBuff[14], &FM_SIG_BAR, 1);
}

PN_VOID PN_FM_Status_Hidden(PN_U8 pn_type, PN_U8 tuner_type, PN_U32 frequency)
{
	PN_U8  PILOT_LOCK, RDS_LOCK, RDS_GAIN, PILOT_CNT;
	PN_S32 FM_DC =0;
	PN_U8  FM_VARIANCE =0;
	PN_U8  FM_OSC57 = 0;
	PN_S32 RDS_TOFFSET=0;
	PN_U8  FM_ADC_OVER=0;
	PN_U16 FM_POST_AGC=0, FM_PRE_AGC=0;
	PN_S32 FM_FACC=0, FM_TACC=0;
	PN_U8  FM_MODE,FIL_COEF;
	PN_S16 MON_IMB_I, MON_IMB_Q;
	PN_U16 MON_HPF_NOISE;
	PN_U8  HPF_TH_H,HPF_TH_L, NOISE_STATUS,FM_SCAN_EN;
//	PN_U8  RF_REG00, RF_REG01, RF_REG02, RF_REG04, RF_REG15;

	EV_FMRDS_STAT(pn_type, &PILOT_LOCK, &RDS_LOCK, &RDS_GAIN, &FM_OSC57, &PILOT_CNT);
	EV_FMRDS_ERR(pn_type, &FM_DC, &FM_VARIANCE, &RDS_TOFFSET);
	EV_FMRDS_STAT2(pn_type, &FM_ADC_OVER, &FM_POST_AGC, &FM_PRE_AGC, &FM_FACC, &FM_TACC);
	EV_FMRDS_STAT3(pn_type, &FM_MODE, &FIL_COEF, &MON_IMB_I, &MON_IMB_Q, &HPF_TH_H, &HPF_TH_L,&MON_HPF_NOISE, &NOISE_STATUS, &FM_SCAN_EN);

	memcpy(&gFMStatusBuff[0],  &PILOT_LOCK,  1);
	memcpy(&gFMStatusBuff[1],  &RDS_LOCK,    1);
	memcpy(&gFMStatusBuff[2],  &RDS_GAIN,    1);
	memcpy(&gFMStatusBuff[3],  &FM_OSC57,    1);
	memcpy(&gFMStatusBuff[4],  &PILOT_CNT,   1);
	memcpy(&gFMStatusBuff[5],  &FM_DC,       4);
	memcpy(&gFMStatusBuff[9],  &FM_VARIANCE, 1);
	memcpy(&gFMStatusBuff[10], &FM_POST_AGC, 2);
	memcpy(&gFMStatusBuff[12], &FM_PRE_AGC,  2);
	memcpy(&gFMStatusBuff[14], &FM_ADC_OVER, 1);
	memcpy(&gFMStatusBuff[15], &RDS_TOFFSET, 4);
	memcpy(&gFMStatusBuff[19], &FM_FACC,     4);
	memcpy(&gFMStatusBuff[23], &FM_TACC,     4);

	memcpy(&gFMStatusBuff[27], &FM_MODE,      1);
	memcpy(&gFMStatusBuff[28], &FIL_COEF,     1);
	memcpy(&gFMStatusBuff[29], &MON_IMB_I,    2);
	memcpy(&gFMStatusBuff[31], &MON_IMB_Q,    2);
	memcpy(&gFMStatusBuff[33], &HPF_TH_H,     1);
	memcpy(&gFMStatusBuff[34], &HPF_TH_L,     1);
	memcpy(&gFMStatusBuff[35], &MON_HPF_NOISE,2);
	memcpy(&gFMStatusBuff[37], &NOISE_STATUS, 1);
	memcpy(&gFMStatusBuff[38], &FM_SCAN_EN,   1);

	EV_RF_STAT(pn_type, &gFMStatusBuff[39], &gFMStatusBuff[40], &gFMStatusBuff[41], &gFMStatusBuff[42], &gFMStatusBuff[43]);
/*
	EV_RF_STAT(pn_type, &RF_REG00, &RF_REG01, &RF_REG02, &RF_REG04, &RF_REG15);
	memcpy(&gFMStatusBuff[39], &RF_REG00,     1);
	memcpy(&gFMStatusBuff[40], &RF_REG01,     1);
	memcpy(&gFMStatusBuff[41], &RF_REG02,     1);
	memcpy(&gFMStatusBuff[42], &RF_REG04,     1);
	memcpy(&gFMStatusBuff[43], &RF_REG15,     1); */
}

PN_VOID PN_FM_Stereo_Set(PN_U8 pn_type, PN_U8 stereo)
{
	PN3030_Reg_Page_Sel(PN3030E_ADDR, FM_E_PAGE);

	if(stereo)
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x45); // STEREO play
	else
		PN3030_Byte_Write(PN3030E_ADDR, FMF0, 0x43); // MONO play
}
