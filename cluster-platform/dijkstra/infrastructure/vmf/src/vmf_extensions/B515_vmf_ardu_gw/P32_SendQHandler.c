#include "stdio.h"
#include "P32_SendQHandler.h"
#include "P32_CmdDefine.h"
#include "P32_DmbApi.h"
#include "stub_fkts.h"


extern PN_U8 gFMStatusBuff[50];     // noah,
extern PN_U8 gStatusBuff[110];

unsigned char frequency_set_result[16]={00};
unsigned char frequency_scan_result[42]={00};

PN_VOID PN_CmdSendQResp(PN_U8 Direction,PN_U8 Cmd,PN_U8* pData,PN_U16 Len)
{
    /* PIC32-->PC */
    // MakeUsbPacketRcvMsg
    // MakeUsbPacketRcvMsg
    // SendRegStatus
}

PN_VOID PN_CmdDanasMixHandler(PN_U16 Len,PN_U8* pCmd)
{
    PN_U8 cmd;
	PN_U8 tUint8;

    /* for Debug */
    PN_U8 pCmdBuf[64] = {0};

	memset(frequency_scan_result,0, sizeof(frequency_scan_result));
    memcpy(&pCmdBuf, pCmd, 64);

#if 1
	cmd = pCmd[3];
	switch(cmd)	//COMMAND
	{
		case PN_DANASMIX_RESET:         // 0x01
		{
			/* Thread Create!! */
			DEBUG_INFO_HI(TRACE_STUBS,"PN_DANASMIX_RESET");
			break;
		}
				
		case PN_DANASMIX_NTFY_RESET:    // 0x02
		{
			DEBUG_INFO_HI(TRACE_STUBS,"PN_DANASMIX_NTFY_RESET");
			PNS3030D_Rst();   /* PNS3030D Reset */
			break;
		}

		case PN_DANASMIX_GET_VERSION:   // 0x03
		{
			DEBUG_INFO_HI(TRACE_STUBS,"PN_DANASMIX_GET_VERSION");
			PN_SPItoUsbConverterVersion();  /* Get Version to Board */
			break;
		}

		case PN_CMD_GET_NOTY_SIZE_1:    // 0x04
			/* Not used, inform the msg size of Device0 to pc */
			break;
					
		case PN_CMD_GET_NOTY_SIZE_2:    // 0x05
			/* Not used, inform the msg size of Device1 to pc */
			break;
					
		case PN_CMD_GET_NOTY_1:         // 0x06
            /* Not used, push the data as size to pc*/

		case PN_CMD_GET_NOTY_2:         // 0x07
			/* Not used, push the data as size to pc*/
			break;

		case PN_CMD_CLEAR_USBBUF1:      // 0x08  INT Pin Enable
		{
			PN_IrisIntEnable();
			break;
		}

		case PN_CMD_CLEAR_USBBUF2:      // 0x09 INT Pin Disable
		{
			PN_IrisIntDisable();
			break;
		}

		case PN_CMD_INIT_PNS3030: // 0x10
		{
			PN_U8    devId;
			PN_U8    tuner;
			PN_U32   freq;
			PN_FLOAT frequency;
			PN_S32   ret = -1;
			PN_U8    init_status[10]={0,};

			//DAB_FM = 0;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_INIT_PNS3030");
				
			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			//TUNER_TYPE = tuner;

			ret = PN_BB_RF_Init(devId, tuner, frequency);

			memcpy(&init_status[0], &ret, sizeof(PN_S32));

			MakeUsbPacketRcvMsg(&init_status[0],PN_CMD_INIT_PNS3030,4);
			break;
        }

		case PN_CMD_CHANGE_FREQUENCY: // 0x13
		{
			PN_U8    devId;
			PN_U8    tuner;
			PN_U32   freq;
			PN_FLOAT frequency;
			PN_S32   ret = -1;
			PN_U8    tr_mode;
			PN_U8    FIB_NUM;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_CHANGE_FREQUENCY");

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			ret = PN_Frequency_Init(devId, tuner, frequency, &tr_mode);

			if(tr_mode == TRANSMISSION_MODE_1_E)
			{
				FIB_NUM = 12;  // FIB number 12
			}
			else if(tr_mode == TRANSMISSION_MODE_2_E)
			{
				FIB_NUM = 3;   // FIB number  3
			}
			else if(tr_mode == TRANSMISSION_MODE_3_E)
            {
				FIB_NUM = 4;   // FIB number  4
			}
			else if(tr_mode == TRANSMISSION_MODE_4_E)
            {
				FIB_NUM = 6;   // FIB number  6
			}
			
            if(ret == 0)
            {
				PN_SetFicStatus(devId, FIC_PARSING);
				PN_SetMemorySize(devId, PN_FIC_MEN, (FIB_NUM * 32));
				EV_SETUP_FIC_MEM(devId);
				EV_UNMASK_INTERRUPT(devId, PN_FIC_MEN, 0);
            }

			memcpy(&frequency_set_result[0], &devId, sizeof(PN_U8));
			memcpy(&frequency_set_result[1], &tuner, sizeof(PN_U8));
			memcpy(&frequency_set_result[2], &freq, sizeof(PN_U32));
			memcpy(&frequency_set_result[6], &ret, sizeof(PN_S32));
			memcpy(&frequency_set_result[10], &tr_mode, sizeof(PN_U8));
			memcpy(&frequency_set_result[11], &FIB_NUM, sizeof(PN_U8));

			MakeUsbPacketRcvMsg(&frequency_set_result[0],PN_CMD_CHANGE_FREQUENCY,12);
			break;
        }

		case PN_CMD_SET_FREQUENCY: // 0x11
		{
			PN_U8    devId;
			PN_U8    tuner;
			PN_U32   freq;
			PN_FLOAT frequency;
			PN_S32   ret = -1;
			PN_U8    tr_mode;
			PN_U8    FIB_NUM;

			//DAB_FM = 0;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_FREQUENCY");

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			ret = PN_Frequency_Init(devId, tuner, frequency, &tr_mode);

            if(tr_mode == TRANSMISSION_MODE_1_E)
			{
				FIB_NUM = 12;  // FIB number 12
			}
			else if(tr_mode == TRANSMISSION_MODE_2_E)
			{
				FIB_NUM = 3;   // FIB number  3
			}
			else if(tr_mode == TRANSMISSION_MODE_3_E)
			{
				FIB_NUM = 4;   // FIB number  4
			} 
			else if(tr_mode == TRANSMISSION_MODE_4_E)
			{
				FIB_NUM = 6;   // FIB number  6
			}
			
            if(ret == 0)
            {
               	PN_SetFicStatus(devId, FIC_PARSING);
				PN_SetMemorySize(devId, PN_FIC_MEN, (FIB_NUM * 32));
				EV_SETUP_FIC_MEM(devId);
				EV_UNMASK_INTERRUPT(devId, PN_FIC_MEN, 0);
            }

			memcpy(&frequency_set_result[0], &devId, sizeof(PN_U8));
			memcpy(&frequency_set_result[1], &tuner, sizeof(PN_U8));
			memcpy(&frequency_set_result[2], &freq, sizeof(PN_U32));
			memcpy(&frequency_set_result[6], &ret, sizeof(PN_S32));
			memcpy(&frequency_set_result[10], &tr_mode, sizeof(PN_U8));
			memcpy(&frequency_set_result[11], &FIB_NUM, sizeof(PN_U8));

			MakeUsbPacketRcvMsg(&frequency_set_result[0],PN_CMD_SET_FREQUENCY,12);
			break;
		}

		case PN_CMD_SET_SCAN: // 0x12
		{
			PN_U8    devId;
			PN_U8    tuner;
			PN_U32   freq;
			PN_FLOAT frequency;
			PN_S32   ret, scan_ret = -1;
			PN_U8    tr_mode = 0xFF;
			PN_U8    FIB_NUM = 0;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_SCAN");
			
			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			ret = PN_Scan_Init(devId, tuner, frequency, &tr_mode);

			if(tr_mode == TRANSMISSION_MODE_1_E)
			{
               	FIB_NUM = 12;     // FIB number 12
			}
			else if(tr_mode == TRANSMISSION_MODE_2_E)
            {
				FIB_NUM = 3;      // FIB number  3
			}
			else if(tr_mode == TRANSMISSION_MODE_3_E)
            {
				FIB_NUM = 4;      // FIB number  4
			}
			else if(tr_mode == TRANSMISSION_MODE_4_E)
            {
				FIB_NUM = 6;      // FIB number  6
			}
			DEBUG_INFO_HI(TRACE_STUBS,"tr_mode = %d, number of FIBs=%d",tr_mode,FIB_NUM);

			if(ret == 0)
			{
				PN_SetFicStatus(devId, FIC_PARSING);
				PN_SetMemorySize(devId, PN_FIC_MEN, (FIB_NUM * 32));
				EV_SETUP_FIC_MEM(devId);
				EV_UNMASK_INTERRUPT(devId, PN_FIC_MEN, 0);
			}
			memcpy(&frequency_scan_result[0], &devId, sizeof(PN_U8));
			memcpy(&frequency_scan_result[1], &tuner, sizeof(PN_U8));
			memcpy(&frequency_scan_result[2], &freq, sizeof(PN_U32));
			memcpy(&frequency_scan_result[6], &ret, sizeof(PN_S32));
			memcpy(&frequency_scan_result[10], &tr_mode, sizeof(PN_U8));
		    memcpy(&frequency_scan_result[11], &FIB_NUM, sizeof(PN_U8));

			MakeUsbPacketRcvMsg(&frequency_scan_result[0],PN_CMD_SET_SCAN,36);
			break;
        }

        case PN_CMD_CLEAR_USBBUF: // 0x13
		{
			/* SPI Buffer Clear */
			PN_U8 devId;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_CLEAR_USBBUF");

			devId = pCmd[4];

			break;
        }

		case PN_CMD_SET_VOLUME: // 0x21
		{
			PN_U8 SetVolume;
			PN_BOOL minus = 0;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_VOLUME");

			SetVolume = pCmd[4];
			if (pCmd[4] & 0x80)
			{
                SetVolume = (PN_S8)(~pCmd[4]);
				SetVolume++;
				minus = TRUE;
			}
			else
			{
				SetVolume = (PN_S8)(pCmd[4]);
			}

			// Codec Not control yet, PN_DrvCodecUpDownVolume(minus, (PN_S16)SetVolume);
			break;
        }

		case PN_CMD_SET_FIC_STATUS: // 0x30
		{
			PN_U8 devId;
			PN_U8 fic_status;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_FIC_STATUS");

			devId = pCmd[4];
			fic_status = pCmd[5];

			PN_SetFicStatus(devId,fic_status);
			break;
		}
		
		case PN_CMD_ENABLE_FIC: // 0x31
		{
			PN_U8  devId;
			PN_U8  fic_status;
			PN_U16 subch_size;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_ENABLE_FIC");
			
			devId = pCmd[4];
			fic_status = pCmd[5];
			subch_size = (pCmd[6] << 8) + pCmd[7];

			PN_SetFicStatus(devId, FIC_PARSING);
			PN_SetMemorySize(devId, PN_FIC_MEN, subch_size);
			EV_SETUP_FIC_MEM(devId);
			EV_UNMASK_INTERRUPT(devId, PN_FIC_MEN, 0);
			break;
        }

		case PN_CMD_DISABLE_FIC: // 0x32
		{
			PN_U8 devId;
			PN_U8 fic_status;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_DISABLE_FIC");
			
			
			devId = pCmd[4];
			fic_status = pCmd[5];

			PN_SetFicStatus(devId, fic_status);
			PN_Service_Reset(devId, PN_FIC_MEN, 0, 0);
			EV_UNMASK_INTERRUPT(devId, PN_FIC_MEN, 1);
			break;
        }

		case PN_CMD_MEMORY_RESET: // 0x33
		{
			PN_U8 devId;

			devId = pCmd[4];
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_MEMORY_RESET");

			PN_Service_Reset(devId, PN_FIC_MEN, PN_MSC0_MEN, PN_MSC1_MEN);
			EV_SETUP_FIC_MEM(devId);
			break;
        }

		case PN_CMD_MEMORY_SETUP: // 0x34
		{
			PN_U8  devId;
			PN_U8  mem_mode;
			PN_U16 subch_size;
			PN_U8  int_mask;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_MEMORY_SETUP");
			
			devId = pCmd[4];
			mem_mode = pCmd[5];
			subch_size = (pCmd[6] << 8) + pCmd[7];
			int_mask = pCmd[8];

			PN_Memory_Setup(devId, mem_mode, subch_size);
			EV_UNMASK_INTERRUPT(devId, mem_mode, int_mask);
			break;
        }
		
		case PN_CMD_SET_SUBCHANNEL: // 0x35
		{
			PN_U8  devId;
			PN_U8  subch;
			PN_U16 Packet_add;
			PN_U8  service;
			PN_U8  mem_mode;
			PN_U8  subch_on;
			PN_U16 subch_size;
			PN_U8  int_mask;
			PN_U8  ADScty;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_SUBCHANNEL");
			
			devId = pCmd[4];
			subch = pCmd[5];
			Packet_add = (pCmd[6] << 8) + pCmd[7];
			service = pCmd[8];
			mem_mode = pCmd[9];
			subch_on = pCmd[10];
			subch_size = (pCmd[11] << 8) + pCmd[12];
			ADScty = pCmd[13];
			int_mask = pCmd[14];

			PN_Subchannel_Set(devId, service, ADScty, subch, Packet_add, subch_on, subch_size);
			EV_SOFT_RESET(devId,PN_FEC);
			PN_Memory_Setup(devId, mem_mode, subch_size);
			PN_SetMemorySize(devId, mem_mode, subch_size);
			EV_UNMASK_INTERRUPT(devId, mem_mode, int_mask);
			break;
        }

		case PN_CMD_SET_MSC_SIZE: // 0x36
		{
			PN_U8  mem_type;
			PN_U16 mem_size;
			PN_U8  devId;

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_MSC_SIZE");
			
			devId = pCmd[4];
			mem_type = pCmd[5];
			mem_size = (pCmd[6] << 8) + pCmd[7];

			PN_SetMemorySize(devId,mem_type,mem_size);
			break;
        }

		case PN_CMD_FIDC_SETUP: // 0x40
		{
			PN_U8 devId;
			PN_U8 on_off;

			devId = pCmd[4];
			on_off = pCmd[5];

			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_FIDC_SETUP");

			PN_FIDC_Setup(devId, on_off);
            break;
        }

		case PN_CMD_SET_MRC: // 0x50
		{
			PN_U8 devId;
			PN_U8 mrc_state;
			PN_U8 tuner1;
			PN_U8 tuner2;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_SET_MRC");

			devId = pCmd[4];
			mrc_state = pCmd[5];
			tuner1 = pCmd[6];
			tuner2 = pCmd[7];

			EV_MRC_SETUP(devId, mrc_state, tuner1);
			break;
        }

		case PN_CMD_RECONFIGURATION_SET: // 0x60
		{
			PN_U8 devId;
			PN_U8 subch;
			PN_U8 type;
			PN_U16 pkt_addr;
			PN_U16 subch_size;
			PN_U8  ADScty;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_RECONFIGURATION_SET");

			devId = pCmd[4];
			subch = pCmd[5];
			type = pCmd[6];;
			pkt_addr = (pCmd[7] << 8) + pCmd[8];
			subch_size = (pCmd[9] << 8) + pCmd[10];
			ADScty = pCmd[11];

			//EV_SET_RECONFIGURATION(devId, subch, type, pkt_addr);
			EV_SOFT_RESET(devId,PN_FEC);
			PN_Memory_Setup(devId, PN_MSC1_MEN, subch_size);
			PN_SetMemorySize(devId, PN_MSC1_MEN, subch_size);
			break;
        }

		case PN_CMD_REG_CHECK: // 0x70
		{
			PN_U8 devId;
			PN_U8 RW_Type;
			PN_U8 page;
			PN_U8 reg_addr;
			PN_U8 reg_val;
			PN_U8 rf_set;
			PN_U8 tuner_type;
			PN_U8 reg_status[10];
			PN_U8 reg_data;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_REG_CHECK");

			devId = pCmd[4];
			RW_Type = pCmd[5];
			page = pCmd[6];
			reg_addr = pCmd[7];
			reg_val = pCmd[8];
			rf_set = pCmd[9];
			tuner_type = pCmd[10];

			reg_data = PN_REG_Check( devId,  RW_Type,  page,  reg_addr,  reg_val,  rf_set,  tuner_type);

			memcpy(&reg_status[0], &reg_data, sizeof(PN_U8));
			MakeUsbPacketRcvMsg(&reg_status[0],PN_CMD_REG_CHECK,1);
			break;
        }

		case PN_CMD_STATUS_CHECK: // 0x71
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U8 DMB_play_flag;
			PN_U32 freq;
			PN_FLOAT frequency;
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_STATUS_CHECK");

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			DMB_play_flag = pCmd[9];

			memset(&gStatusBuff, 0x0, sizeof(gStatusBuff));

			if(tuner < 14)  //DMB
			{
				frequency = (PN_FLOAT)freq/1000;
				PN_Status_Check(devId, tuner, frequency, DMB_play_flag);
				MakeUsbPacketRcvMsg(&gStatusBuff[0],PN_CMD_STATUS_CHECK,100);
			}
			break;
		}

		case PN_CMD_RSSI_STATUS: // 0x72
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U32 freq;
			PN_FLOAT frequency;
			PN_S16 rssi;
			PN_S8 sig_bar;
			PN_U8 rssi_status[10];
			DEBUG_INFO_HI(TRACE_STUBS,"PN_CMD_RSSI_STATUS");

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			rssi = PN_RSSI_Check(devId, tuner, frequency, &sig_bar);
			memcpy(&rssi_status[0], &rssi, sizeof(PN_S32));
			memcpy(&rssi_status[4], &sig_bar, sizeof(PN_S32));

			MakeUsbPacketRcvMsg(rssi_status,PN_CMD_RSSI_STATUS,8);
			break;
		}

		case PN_CMD_STATUS_CHECK2:      // 0x73
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U8 DMB_play_flag;
			PN_U32 freq;
			PN_FLOAT frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			DMB_play_flag = pCmd[9];

			memset(&gStatusBuff, 0x0, sizeof(gStatusBuff));

			frequency = (PN_FLOAT)freq/1000;
			PN_Status_Check2(devId, tuner, frequency, DMB_play_flag);
			MakeUsbPacketRcvMsg(gStatusBuff,PN_CMD_STATUS_CHECK2,119);
			break;
		}

        /* FM Cmd */
		case PN_CMD_FM_SETUP: // 0x80
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U32 freq;
			PN_FLOAT frequency;
			PN_U16 FM_size;
			PN_U16 RDS_size;

			//DAB_FM = 1;
			//FM_PLAY = 0;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;
			FM_size = (pCmd[9] << 8) + pCmd[10];
			RDS_size = (pCmd[11] << 8) + pCmd[12];

			//TUNER_TYPE = tuner;

			EV_FM_INIT(devId, tuner);
			PN_INIT_TUNER(0x86, tuner, frequency);
			EV_SOFT_RESET(devId,PN_OFDM_FEC);
			EV_INTERRUPT_SETUP(devId);

			PN_IrisIntEnable();

			PN_Memory_Setup(devId, PN_MSC1_FM_MEN, FM_size); // FM data dump
			PN_SetMemorySize(devId, PN_MSC1_FM_MEN, FM_size);
			EV_UNMASK_INTERRUPT(devId, PN_MSC1_FM_MEN, 0);

			PN_Memory_Setup(devId, PN_MSC0_RDS_MEN, RDS_size); // RDS data dump ( threshold method )
			PN_SetMemorySize(devId, PN_MSC0_RDS_MEN, RDS_size);
			EV_UNMASK_INTERRUPT(devId, PN_MSC0_RDS_MEN, 0);
			break;
		}
		
		case PN_CMD_FM_SCAN_INIT: // 0x81
		{
			PN_U8 devId;
			PN_U8 tuner;

			devId = pCmd[4];
			tuner = pCmd[5];

			EV_FM_INIT(devId, tuner);
			PN_INIT_TUNER(devId,tuner,88.0);
			PN_FM_Scan_Init(devId);
			break;
		}
		
		case PN_CMD_FM_SCAN_SETUP: // 0x82
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U32 freq;
			PN_FLOAT frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			CHANGE_TUNER_FREQ(tuner, frequency);
			EV_SOFT_RESET(devId,PN_OFDM_FEC);
            break;
		}
		
		case PN_CMD_FM_STATUS_CHECK: // 0x83
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U32 freq;
			PN_FLOAT frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			PN_FM_Status_Check(devId, tuner, frequency);

		    MakeUsbPacketRcvMsg(&gFMStatusBuff[0],PN_CMD_FM_STATUS_CHECK,20);
			break;
		}
		
		case PN_CMD_FM_STATUS_HIDDEN: // 0x85
		{
			PN_U8 devId;
			PN_U8 tuner;
			PN_U32 freq;
			PN_FLOAT frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (PN_FLOAT)freq/1000;

			PN_FM_Status_Hidden(devId, tuner, frequency);

			MakeUsbPacketRcvMsg(&gFMStatusBuff[0],PN_CMD_FM_STATUS_HIDDEN,55);
			break;
		}
		
		case PN_CMD_FM_STEREO: // Manual Stereo mono change  // 0x84
		{
			PN_U8 devId;
			PN_U8 stereo;

			devId = pCmd[4];
			stereo = pCmd[5];

			PN_FM_Stereo_Set(devId, stereo);
            break;
		}
		
		case PN_CMD_FM_PLAY: // FM Play
		{
			PN_U8 devId;
			PN_U8 play_on;

			devId = pCmd[4];
			play_on = pCmd[5];

			/* Not implemented yet */
			break;
		}

		/* Reg Control */
		case PN_CMD_GET_BYTE_READ: // 0xA0, pCmd[5] : offset, pCmd[6] : data, pCmd[7] : page
		{
			tUint8 = ReadOneRegisterDirect(pCmd[5], pCmd[7]); // ReadOneRegister(unsigned char hex_address, unsigned char mode) ;
			//MakeUsbPacketRcvMsg(&pCmd[0],0x60,64);
			SendRegStatus(pCmd[5], tUint8, PN_CMD_GET_BYTE_READ);
			break;
		}

		case PN_CMD_GET_BYTE_WRITE: // 0xA1, pCmd[5] : offset,pCmd[6] : data, pCmd[7] : page
		{
			WriteOneRegisterDirect(pCmd[5], pCmd[6], pCmd[7]); // WriteOneRegister(unsigned char hex_address, unsigned char Data, unsigned char mode) ;
			tUint8 = ReadOneRegisterDirect(pCmd[5], pCmd[7]); // ReadOneRegister(unsigned char hex_address, unsigned char mode) ;
			//MakeUsbPacketRcvMsg(&pCmd[0],0x60 ,64);
			SendRegStatus(pCmd[5], tUint8, PN_CMD_GET_BYTE_WRITE);
			break;
		}

		case PN_CMD_GET_BURST_READ: // 0xA2, ptr[5] : RegAddr, ptr[6] : lenght(high), ptr[7] : length(low), ptr[8] : tuner_type, ptr[9] : page
		{
			unsigned int length = pCmd[7];
			unsigned char burstdat[256]={0,};

			ReadBurstRegisterDirect(pCmd[5], pCmd[9], (unsigned char*)burstdat, pCmd[7]); // WriteOneRegister(unsigned char hex_address, unsigned char Data, unsigned char mode) ;
			tUint8 = ReadOneRegisterDirect(pCmd[6], pCmd[5]); // ReadOneRegister(unsigned char hex_address, unsigned char mode) ;
			MakeUsbPacketRcvMsg(burstdat,PN_CMD_GET_BURST_READ,length);
			break;
		}

        /* ISDBT */
		case PN_CMD_SET_ISDBT_INIT: // 0xB0
		{
			PN_U8  devId;
			PN_U8  tuner;
			PN_U32 freq;
			double frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (double)freq/1000;

		   /* Not implemented yet */
			break;
		}
		
		case PN_CMD_SET_ISDBT_CHANGE_FREQ: // 0xB1
		{
			PN_U8  devId;
			PN_U8  tuner;
			PN_U32 freq;
			double frequency;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (double)freq/1000;

			/* Not implemented yet */
				break;
		}
		
		case PN_CMD_SET_ISDBT_FASTSCAN: // 0xB2
		{
			PN_U8  devId;
			PN_U8  tuner;
			PN_U32 freq;
			double frequency;
			PN_U8  ISDB_T_channel;

			devId = pCmd[4];
			tuner = pCmd[5];
			freq = (pCmd[6] << 16) + (pCmd[7] << 8) + pCmd[8];
			frequency = (double)freq/1000;

			/* Not implemented yet */
			break;
		}
		default:
			break;
	}//swich case
#endif
}

PN_VOID PN_CmdEvHandler(PN_U16 Len,PN_U8* pCmd)
{
    /* No structure needs */
}

PN_VOID PN_CmdSendQHandler(PN_VOID)
{
   /* No structure needs */
}

PN_VOID PN_CmdSendRstHandler(PN_DEVICEID devId)
{
   PNS3030D_Rst();
}

PN_VOID PN_SPItoUsbConverterVersion(PN_VOID)
{
  /* No structure needs */
}
