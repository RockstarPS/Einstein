//#ifndef _PN3030_DMB_API_H_
//#define _PN3030_DMB_API_H_

/********************/
/*   HEADER FILES   */
/********************/
#include "P32_DabCtrl.h"

//#ifdef __cplusplus
//extern "C" {
//#endif

/******************/
/*     DEFINE     */
/******************/
#define PN_FIC_MEN      0
#define PN_FIDC_MEN     1
#define PN_PAD_MEN      2
#define PN_MSC0_MEN     3
#define PN_MSC1_MEN     4
#define PN_FEC_MEN      5
#define PN_MSC1_FM_MEN  6
#define PN_MSC0_RDS_MEN 7

#define TRANSMISSION_MODE_1_E  0x00
#define TRANSMISSION_MODE_2_E  0x01
#define TRANSMISSION_MODE_3_E  0x02
#define TRANSMISSION_MODE_4_E  0x03

#define MSC1_E_OVER_FLOW       0x40
#define MSC1_E_UNDER_FLOW      0x20
#define MSC1_E_INT             0x10
#define MSC0_E_OVER_FLOW       0x08
#define MSC0_E_UNDER_FLOW      0x04
#define MSC0_E_INT             0x02
#define FIC_E_INT              0x01
#define RE_CONFIG_E_INT        0x04


/************************/
/*	DMB Data structure  */
/************************/
typedef struct {
	PN_U8 data[512];
	PN_U16 subchsize;
}MEM_DUMP1;

typedef struct {
	PN_U8 data[4*1024];
	PN_U16 subchsize;
}MEM_DUMP2;

typedef struct {
	PN_U8 data[3*1024];
	PN_U16 subchsize;
}MEM_DUMP3;

typedef enum
{
	FIC_NO_CRC_RECONF  = 0x02,
	FIC_NO_CRC         = 0x01,
	FIC_CRC_ERR        = 0x00,
	FIC_PARSING        = 0x11,
	FIC_PARSED_OK      = 0x21,
	FIC_PARSED_FAIL    = 0x41,
	RE_CONFIG_OK       = 0xA1
}FIC_STATUS;

typedef struct
{
	FIC_STATUS ficStatus1;
	FIC_STATUS ficStatus2;
	MEM_DUMP1  ficmem1;
	MEM_DUMP1  ficmem2;
	MEM_DUMP2  msc1mem1;
	MEM_DUMP2  msc1mem2;
	MEM_DUMP3  msc0mem1;
	MEM_DUMP3  msc0mem2;
}PN_DMB_SYS_CONFIG;

typedef struct _PN_DAB_BUF_MGT
{
	PN_U16 gDabBufWrIdx;            /* DAB Audio Buffer idx */
	PN_U16 gDabBufRdIdx;
	PN_U16 gDabMaxIdx;
	PN_U32 gDabFilled;
} PN_DabBufIdx_t;

typedef struct _PN_FmRdsBufIdx_t
{
	PN_U32 BufWrIdx;            /* FM Audio Buffer idx */
	PN_U32 BufRdIdx;
	PN_U32 BufStart;
	PN_U16 BufSize;
	PN_U32 MaxIdx;
} PN_FmRdsBufIdx_t;


PN_VOID PN_InitDmbSysConfig(PN_VOID);
PN_VOID PN_SetFicStatus(PN_U8 devId,FIC_STATUS ficStatus);
PN_VOID PN_SetMemorySize(PN_U8 devId,PN_U8 MemType,PN_U16 size);
PN_VOID PN_INTERRUPT_SERVICE_ROUTINE1(PN_U8 pn_type);
PN_VOID PN_INTERRUPT_SERVICE_ROUTINE2(PN_U8 pn_type);

PN_S32  PN_BB_RF_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq);
PN_S32  PN_Frequency_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 *tr_mode);
PN_S32  PN_Scan_Init(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 *tr_mode);
PN_VOID PN_Status_Check(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 DMB_play_flag);
PN_VOID PN_Status_Check2(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_U8 DMB_play_flag);
PN_S16  PN_RSSI_Check(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT freq, PN_S8 *sig_bar);
PN_VOID PN_Subchannel_Set(PN_U8 pn_type, PN_U8 service, PN_U8 ADscty, PN_U8 subch, PN_U16 pkt_addr, PN_U8 subch_on, PN_U16 dump_size);
PN_VOID PN_Memory_Setup(PN_U8 pn_type, PN_U8 mem_mode, PN_U16 dump_size);
PN_VOID PN_FIDC_Setup(PN_U8 pn_type, PN_U8 on_off);
PN_U8   PN_REG_Check(PN_U8 pn_type, PN_U8 RW_Type, PN_U8 page, PN_U8 reg_addr, PN_U8 reg_val, PN_U8 rf_set, PN_U8 tuner_type);
PN_VOID PN_FM_Scan_Init(PN_U8 pn_type);
PN_VOID PN_FM_Status_Check(PN_U8 pn_type, PN_U8 tuner_type, PN_U32 frequency);
PN_VOID PN_FM_Status_Hidden(PN_U8 pn_type, PN_U8 tuner_type, PN_U32 frequency);
PN_VOID PN_FM_Stereo_Set(PN_U8 pn_type, PN_U8 stereo);


PN_VOID PN_Service_Reset(PN_U8 pn_type, PN_U8 rst_fic_mem, PN_U8 rst_msc0_mem, PN_U8 rst_msc1_mem);

PN_DabBufIdx_t *PN_GetDabBufIdx(PN_VOID);



/**************************/
/*  Defines for constant  */
/**************************/
#define PN_UIMSG_NAME       "uiMsg"
#define PN_UIMSG_MSG_MAX    15

#define PN_TYPE_DATA        1
#define PN_TYPE_PAD         0

#define SERVICE_NONE        0
#define VIDEO_SERVICE       1
#define AUDIO_SERVICE       2
#define DATA_SERVICE        3
#define PKT_SERVICE         4
#define CAS_SERVICE         5
#define RE_CONFIG_SVR       6
#define VIDEO_SERVICE_MPEGOUT	7

#define SLEEP_OR_CLOSE      0x00
#define CHANNEL_LOCK        0x01
#define CHANNEL_UNLOCK      0x02
#define INTERFACE_ERR       0x04

#define DEBUG_MODE_ENABLE	1
#define DEBUG_MODE_DISABLE	0

//#define FIC_NO_CRC_RECONF	2
//#define FIC_NO_CRC		1
//#define FIC_CRC_ERR		0
//#define FIC_PARSING         0x11
//#define FIC_PARSED_OK       0x21
//#define FIC_PARSED_FAIL     0x41
//#define RE_CONFIG_OK        0xA1

#define SCAN_STATUS         1
#define NO_SCAN_STATUS      0

#define RE_COFIG_DONE       2
#define RE_COFIG_START      1 
#define RE_COFIG_NONE       0

#define MSC0_DUMP_FAIL      0
#define PN3030_MSC0_AUDIO   1
#define PN3030E_MSC0_AUDIO  2
#define PN3030_MSC0_DATA    3
#define PN3030E_MSC0_DATA   4

#define EWS_ENABLE          3
#define EWS_DISABLE         2
#define EWS_END             1
#define EWS_NONE            0

#define KOREA_TDMB_SCAN			   0x10
#define WORLD_DAB_BAND3_SCAN	   0x20
#define WORLD_DAB_LBAND_SCAN	   0x30
#define CHINA_DAB_BAND3_SCAN	   0x40

// Use Silab dump 
#define FIC_DUMP			0
#define MSC1_DUMP			1
#define MSC0_DUMP			2
#define PAD_DUMP			3
#define DUMP_FAIL			4



PN_VOID READ_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value);
PN_VOID WRITE_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 value);
PN_VOID WRITE_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size);
PN_VOID READ_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size);

//#ifdef __cplusplus
//}
//#endif


//#endif