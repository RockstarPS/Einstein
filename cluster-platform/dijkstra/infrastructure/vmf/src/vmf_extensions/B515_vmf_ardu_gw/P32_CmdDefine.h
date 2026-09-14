
#ifndef __PN_CMD_DEFIEN_H__
#define __PN_CMD_DEFIEN_H__

/********************************************/
/*	Direction Definitions					*/
/********************************************/
typedef enum
{
	DIR_PN3021P  = 0x66,
	DIR_PN3022	 = 0x99,
	DIR_PNS3030  = 0x77,
	DIR_INVALID  = 0xFF
}PN_DIRECTION;

/*Command interface between PN3022 and HOST PC */
#define PN_DANASMIX_RESET			0x01
#define PN_DANASMIX_NTFY_RESET		0x02
#define PN_DANASMIX_GET_VERSION		0x03
#define PN_CMD_GET_NOTY_SIZE_1		0x04
#define PN_CMD_GET_NOTY_SIZE_2		0x05
#define PN_CMD_GET_NOTY_1			0x06
#define PN_CMD_GET_NOTY_2			0x07
#define PN_CMD_CLEAR_USBBUF1		0x08
#define PN_CMD_CLEAR_USBBUF2		0x09
#define PN_CMD_INIT_PNS3030         0x10
#define PN_CMD_SET_FREQUENCY        0x11
#define PN_CMD_SET_SCAN             0x12
#define PN_CMD_CHANGE_FREQUENCY     0x13
#define PN_CMD_CLEAR_USBBUF 		0x20
#define PN_CMD_SET_VOLUME			0x21
#define PN_CMD_SET_FIC_STATUS       0x30
#define PN_CMD_ENABLE_FIC           0x31
#define PN_CMD_DISABLE_FIC          0x32
#define PN_CMD_MEMORY_RESET         0x33
#define PN_CMD_MEMORY_SETUP         0x34
#define PN_CMD_SET_SUBCHANNEL       0x35
#define PN_CMD_SET_MSC_SIZE	        0x36
#define PN_CMD_FIDC_SETUP           0x40
#define PN_CMD_SET_MRC              0x50
#define PN_CMD_RECONFIGURATION_SET  0x60
#define PN_CMD_REG_CHECK            0x70
#define PN_CMD_STATUS_CHECK         0x71
#define PN_CMD_RSSI_STATUS          0x72
#define PN_CMD_STATUS_CHECK2        0x73
#define PN_CMD_FM_SETUP             0x80
#define PN_CMD_FM_SCAN_INIT         0x81
#define PN_CMD_FM_SCAN_SETUP        0x82
#define PN_CMD_FM_STATUS_CHECK      0x83
#define PN_CMD_FM_STEREO            0x84
#define PN_CMD_FM_STATUS_HIDDEN     0x85
#define PN_CMD_FM_PLAY              0x86
#define PN_CMD_GET_BYTE_READ		0xA0
#define PN_CMD_GET_BYTE_WRITE		0xA1
#define PN_CMD_GET_BURST_READ		0xA2

#define PN_CMD_SET_ISDBT_INIT		0xB0
#define PN_CMD_SET_ISDBT_FASTSCAN   0xB1
#define PN_CMD_SET_ISDBT_CHANGE_FREQ	0xB2


#endif //__PN_CMD_DEFIEN_H__

