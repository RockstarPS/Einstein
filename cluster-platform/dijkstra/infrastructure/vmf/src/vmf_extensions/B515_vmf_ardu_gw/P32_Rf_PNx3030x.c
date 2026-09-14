
//**************************************************************************************************//
//			Conan_Porting_Source : Implementation file
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include "P32_RF_API.h"
#include "P32_RF_PNx3030x.h"
#include "math.h"
#include "P32_PNS3030RegDef.h"

///////////////////////////////////////////////////////////////////////////////////////
PN_FLOAT PNS3030_REFFREQ = (PN_FLOAT)REF_FREQ_DEF;

typedef struct	INIT {
	PN_U8	TAddr;				
	PN_U8	TData;				
} PNS3030_INIT;
PN_U8 TuneBand = 1;

//// MTV1.7.1 init code  by terry [2011.06.22]
const PNS3030_INIT t_FM_INIT[] =   
{
	{  0x27,  0xc2  },
	{  0x2B,  0x88  },
	{  0x2d,  0xf4  },  // 128ms
	{  0x2e,  0xb0  },
	{  0x31,  0x04  },
	{  0x34,  0xf8  },
	{  0x35,  0x20  },  // default:0x20 
	{  0x37,  0x3B  },  // 16.384MHz[0x59], 24.576MHz[0x3B]
	{  0x39,  0x6C  },  // 16.384MHz[0x4C], 24.576MHz[0x6C]
	{  0x3a,  0x55  },
	{  0x3b,  0x73  },
	{  0x3c,  0x00  },
	{  0x3e,  0x00  },
	{  0x3f,  0x00  },
	{  0x40,  0x10  },
	{  0x42,  0x40  },
	{  0x43,  0x36  },  // MTV1.7.1 2011.06.22
	{  0x44,  0x64  },
	{  0x46,  0x07  },  // MTV1.7.1 2011.06.22
	{  0x47,  0xb1  },
	{  0x49,  0x1f  },  // MTV1.7.1 2011.06.22
	{  0x4a,  0x50  },  // MTV1.7.1 2011.06.22
	{  0x4b,  0x90  },  // MTV1.7.1 2011.06.22
	{  0x53,  0x20  },
	{  0x55,  0xd6  },
	{  0x57,  0x10  },
	{  0x5a,  0x03  },  // MTV1.7.1 2011.06.22
	{  0x60,  0x11  },
	{  0x6b,  0xc5  },
	{  0x6e,  0x88  },  // MTV1.7.1 2011.06.22
	{  0x6f,  0x78  },  // MTV1.7.1 2011.06.22
	{  0x72,  0xf0  },
	{  0x73,  0xc8  },
	{  0x74,  0x70  },
	{  0x77,  0x80  },
	{  0x78,  0x47  },
	{  0x84,  0x80  },  // MTV1.7.1 2011.06.22
	{  0x85,  0x90  },  // MTV1.7.1 2011.06.22
	{  0x86,  0x80  },
	{  0x87,  0x98  },
	{  0x8a,  0xf6  },
	{  0x8b,  0x80  },
	{  0x8c,  0x74  },
	{  0x90,  0x11  },  // MTV1.7.1 2011.06.22
	{  0x93,  0x2d  },  // MTV1.7.1 2011.06.22
	{  0x94,  0x26  },  // MTV1.7.1 2011.06.22
	{  0x99,  0xd0  },  // MTV1.7.1 2011.06.22
	{  0x9a,  0x4f  },  // MTV1.7.1 2011.06.22
	{  0x9b,  0x35  },  // MTV1.7.1 2011.06.22
	{  0x9c,  0x7d  },  // MTV1.7.1 2011.06.22
	{  0x9d,  0x66  },  // MTV1.7.1 2011.06.22
	{  0x9e,  0x05  },  // MTV1.7.1 2011.06.22
	{  0x9f,  0x34  },  // MTV1.7.1 2011.06.22
	{  0xa0,  0x3c  },  // MTV1.7.1 2011.06.22
	{  0xa1,  0x5a  },  // MTV1.7.1 2011.06.22
	{  0xa2,  0x8f  },  // MTV1.7.1 2011.06.22
	{  0xa3,  0x5f  },  // MTV1.7.1 2011.06.22
	{  0xa4,  0x15  },  // MTV1.7.1 2011.06.22
	{  0xae,  0x77  },  // MTV1.7.1 2011.06.22
	{  0xaf,  0x01  },
	{  0xb5,  0x5b  },
	{  0xae,  0x37  },
	{  0xbd,  0x3f  },
	{  0xbe,  0x37  },
	{  0xbf,  0x3c  },
	{  0xc0,  0x3f  },
	{  0xc1,  0x39  },
	{  0xc3,  0xdb  },
	{  0xc4,  0x3c  },
	{  0xc5,  0x1e  },
	{  0xc6,  0x6c  },
	{  0xc7,  0x3f  },  // MTV1.7.1 2011.06.22
	{  0xc8,  0x7b  },
	{  0xc9,  0xec  },
	{  0xca,  0x39  },
	{  0xcb,  0x03  },
	{  0xcc,  0x43  },  // MTV1.7.1 2011.06.22
	{  0xcd,  0xb4  },
	{  0xce,  0xec  },
	{  0xcf,  0x1d  },
	{  0xd0,  0xa6  },
	{  0xd1,  0x41  },
	{  0xd2,  0x16  },
	{  0xd3,  0xec  },
	{  0xd4,  0x3f  },
	{  0xd5,  0xc3  },
	{  0xd6,  0x43  },  // MTV1.7.1 2011.06.22
	{  0xd7,  0xbd  },
	{  0xd8,  0xbc  },
	{  0xd9,  0x1b  },
	{  0xda,  0x4b  },
	{  0xdb,  0x3b  },
	{  0xdc,  0x55  },
	{  0xdd,  0xdc  },
	{  0xde,  0x1a  },
	{  0xdf,  0xed  },
	{  0xe0,  0x43  },  // MTV1.7.1 2011.06.22
	{  0xe1,  0xa7  },
	{  0xe2,  0xcc  },
	{  0xe3,  0x1a  },
	{  0xe4,  0x55  },
	{  0xe5,  0x43  },
	{  0xe6,  0x00  },
	{  0xe7,  0x0f  },
	{  0xa5,  0x00  },
	{  0xe9,  0x41  },
	{  0xae,  0x77  },
	{  0xe9,  0x51  }
};

const PNS3030_INIT t_TDMB_INIT[] =   
{
	{  0x27,  0x96  },  // MTV1.7.1 2011.06.22
	{  0x2B,  0x88  },
	{  0x2d,  0xf4  },  // 128ms
	{  0x2e,  0xb0  },
	{  0x31,  0x04  },
	{  0x34,  0xf8  },
	{  0x35,  0x14  },  // default:0x20 ->0x14 [Band-III only]
	{  0x37,  0x3B  },  // 16.384MHz[0x59], 24.576MHz[0x3B]
	{  0x39,  0x6C  },  // 16.384MHz[0x4C], 24.576MHz[0x6C]
	{  0x3a,  0x42  },  // MTV1.7.1 2011.06.22
	{  0x3b,  0x74  },
	{  0x3c,  0x88  },  // MTV1.7.1 2011.06.22
	{  0x3e,  0x20  },  // MTV1.7.1 2011.06.22
	{  0x3f,  0x0a  },  // MTV1.7.1 2011.06.22
	{  0x40,  0x00  },  // MTV1.7.1 2011.06.22
	{  0x42,  0x00  },  // MTV1.7.1 2011.06.22
	{  0x43,  0x36  },  // MTV1.7.1 2011.06.22
	{  0x44,  0x70  },  // MTV1.7.1 2011.06.22
	{  0x46,  0x07  },  // MTV1.7.1 2011.06.22
	{  0x47,  0xb0  },  // MTV1.7.1 2011.06.22
	{  0x49,  0x1f  },  // MTV1.7.1 2011.06.22
	{  0x4a,  0x50  },  // MTV1.7.1 2011.06.22
	{  0x4b,  0x80  },  
	{  0x53,  0x20  },
	{  0x55,  0xd6  },
	{  0x57,  0x50  },  // MTV1.7.1 2011.06.22
	{  0x5a,  0x83  }, 
	{  0x60,  0x13  },
	{  0x6b,  0xc5  }, 
	{  0x6e,  0x88  },  // MTV1.7.1 2011.06.22
	{  0x6f,  0x78  },  // MTV1.7.1 2011.06.22 
	{  0x72,  0xf0  },
	{  0x73,  0xca  },
	{  0x74,  0x6f  },  // MTV1.7.1 2011.06.22
	{  0x77,  0x80  },
	{  0x78,  0x47  },
	{  0x84,  0x80  },  // MTV1.7.1 2011.06.22
	{  0x85,  0x98  },
	{  0x86,  0x80  },
	{  0x87,  0x98  },
	{  0x8a,  0xf6  },
	{  0x8b,  0x80  },
	{  0x8c,  0x75  },
	//{  0x8d,  0xa8  },  // GVBB max value change by terry 2011.11.01
	{  0x8f,  0xf9  },  
	{  0x90,  0x91  },  
	{  0x93,  0x2d  },  // MTV1.7.1 2011.06.22
	{  0x94,  0x23  },  
	{  0x99,  0x77  },
	{  0x9a,  0x2d  },
	{  0x9b,  0x1e  },
	{  0x9c,  0x47  },
	{  0x9d,  0x3a  },
	{  0x9e,  0x03  },
	{  0x9f,  0x1e  },
	{  0xa0,  0x22  },
	{  0xa1,  0x33  },
	{  0xa2,  0x51  },
	{  0xa3,  0x36  },
	{  0xa4,  0x0c  },
	{  0xae,  0x37  },
	{  0xb5,  0x9b  },
	{  0xbd,  0x45  },	// 0x3d ->0x45 by Raon 20110826
	{  0xbe,  0x68  },	
	{  0xbf,  0x5c  },	
	{  0xc0,  0x33  },	 
	{  0xc1,  0xca  },	
	{  0xc2,  0x43  },	
	{  0xc3,  0x90  },	 
	{  0xc4,  0xec  },   
	{  0xc5,  0x17  },   
	{  0xc6,  0xda  },   
	{  0xc7,  0x41  },   
	{  0xc8,  0x49  }, 
	{  0xc9,  0xbc  }, 
	{  0xca,  0x3a  },   
	{  0xcb,  0x20  },   
	{  0xcc,  0x43  },   
	{  0xcd,  0xa6  },   
	{  0xce,  0x4c  },   
	{  0xcf,  0x1f  },   
	{  0xd0,  0x8d  },   
	{  0xd1,  0x3d  },   
	{  0xd2,  0xdf  }, 
	{  0xd3,  0xa4  }, 
	{  0xd4,  0x30  },   
	{  0xd5,  0x00  }, 
	{  0xd6,  0x41  },
	{  0xd7,  0x81  },  
	{  0xd8,  0xd0  }, 
	{  0xd9,  0x00  },
	{  0xda,  0x00  }, 
	{  0xdb,  0x41  },
	{  0xdc,  0x6d  },
	{  0xdd,  0xac  },
	{  0xde,  0x39  },
	{  0xdf,  0x4e  },
	{  0xe0,  0x43  },
	{  0xe1,  0xa0  },
	{  0xe2,  0x4c  },
	{  0xe3,  0x1d  },
	{  0xe4,  0x99  },
	{  0xe5,  0x3b  },   // 0x43 -> 0x3b by Raon 20110826
	{  0xe6,  0x00  },
	{  0xe7,  0x0d  },
	{  0xa5,  0x00  },
	{  0xe9,  0xC1  },
	{  0xae,  0x77  },
	{  0xe9,  0xD1  }    
	//{  0xe9,  0xc1  }     // 192MHz Test by terry 2011.07.19
};

const PNS3030_INIT t_TDMB_L_INIT[] =   
{
	{  0x27,  0x3e  },  //
	{  0x2B,  0x88  },
	{  0x2d,  0xec  },  // 32ms
	{  0x2e,  0xb0  },
	{  0x31,  0x04  },
	{  0x34,  0x70  },  //
	{  0x35,  0x20  },  // default:0x20 
	{  0x37,  0x3b  },  // MTV1.7.1 2011.06.22
	{  0x39,  0x6c  },  // MTV1.7.1 2011.06.22
	{  0x3a,  0x42  },  // MTV1.7.1 2011.06.22
	{  0x3b,  0xf7  },  //
	{  0x3c,  0x88  },  // MTV1.7.1 2011.06.22
	{  0x3e,  0x20  },  // MTV1.7.1 2011.06.22
	{  0x3f,  0x0a  },  // MTV1.7.1 2011.06.22
	{  0x40,  0x00  },  // MTV1.7.1 2011.06.22
	{  0x42,  0x00  },  // MTV1.7.1 2011.06.22
	{  0x43,  0x34  },  //
	{  0x44,  0x00  },  //
	{  0x46,  0x03  },  //
	{  0x47,  0xb0  },  // MTV1.7.1 2011.06.22
	{  0x49,  0xbf  },  //
	{  0x4a,  0x18  },  //
	{  0x4b,  0x80  },
	{  0x53,  0x20  },
	{  0x55,  0xfa  },  //
	{  0x57,  0x50  },  // MTV1.7.1 2011.06.22
	{  0x5a,  0x83  },
	{  0x60,  0x43  },  //
	{  0x6b,  0xc5  },
	{  0x6e,  0x80  },  //
	{  0x6f,  0x70  },  //
	{  0x72,  0xf0  },
	{  0x73,  0xca  },
	{  0x74,  0x6f  },  // MTV1.7.1 2011.06.22
	{  0x77,  0x80  },
	{  0x78,  0x47  },
	{  0x84,  0x70  },  //
	{  0x85,  0x90  },  //
	{  0x86,  0x70  },  //
	{  0x87,  0x88  },  //
	{  0x8a,  0xf6  },
	{  0x8b,  0x86  },  //
	{  0x8c,  0x7a  },  //
	//{  0x8d,  0xA8  },  // GVBB max value change by terry 2011.11.01
	{  0x8f,  0xfa  },  //
	{  0x90,  0x05  },  //
	{  0x93,  0x2f  },  //
	{  0x94,  0x26  },  //
	{  0x99,  0x77  },
	{  0x9a,  0x2d  },
	{  0x9b,  0x1e  },
	{  0x9c,  0x47  },
	{  0x9d,  0x3a  },
	{  0x9e,  0x03  },
	{  0x9f,  0x1e  },
	{  0xa0,  0x22  },
	{  0xa1,  0x33  },
	{  0xa2,  0x51  },
	{  0xa3,  0x36  },
	{  0xa4,  0x0c  },
	{  0xae,  0x37  },
	{  0xb5,  0x9b  },
	{  0xbd,  0x3d  },	 
	{  0xbe,  0x68  },	
	{  0xbf,  0x5c  },	
	{  0xc0,  0x33  },	 
	{  0xc1,  0xca  },	
	{  0xc2,  0x43  },	
	{  0xc3,  0x90  },	 
	{  0xc4,  0xec  },   
	{  0xc5,  0x17  },   
	{  0xc6,  0xda  },   
	{  0xc7,  0x41  },   
	{  0xc8,  0x49  }, 
	{  0xc9,  0xbc  }, 
	{  0xca,  0x3a  },   
	{  0xcb,  0x20  },   
	{  0xcc,  0x43  },   
	{  0xcd,  0xa6  },   
	{  0xce,  0x4c  },   
	{  0xcf,  0x1f  },   
	{  0xd0,  0x8d  },   
	{  0xd1,  0x3d  },   
	{  0xd2,  0xdf  }, 
	{  0xd3,  0xa4  }, 
	{  0xd4,  0x30  },   
	{  0xd5,  0x00  }, 
	{  0xd6,  0x41  },
	{  0xd7,  0x81  },  
	{  0xd8,  0xd0  }, 
	{  0xd9,  0x00  },
	{  0xda,  0x00  }, 
	{  0xdb,  0x41  },
	{  0xdc,  0x6d  },
	{  0xdd,  0xac  },
	{  0xde,  0x39  },
	{  0xdf,  0x4e  },
	{  0xe0,  0x43  },
	{  0xe1,  0xa0  },
	{  0xe2,  0x4c  },
	{  0xe3,  0x1d  },
	{  0xe4,  0x99  },
	{  0xe5,  0x43  },
	{  0xe6,  0x00  },
	{  0xe7,  0x0d  },
	{  0xa5,  0x00  },
	{  0xe9,  0x41  },
	{  0xae,  0x77  },
	{  0xe9,  0x51  }
};

const PNS3030_INIT t_ISDBT_INIT[] =   
{
		{  0x27,  0x6a  },
		{  0x2d,  0xf4  },  // 128ms
		{  0x2e,  0xb0  },
		{  0x31,  0x04  },
		{  0x34,  0xc0  },
		{  0x35,  0x20  },  // default:0x20 
		{  0x37,  0x7a  },  // 16.384MHz[0x7A], 24.576MHz[0x51]
		{  0x39,  0x7C  },  // 16.384MHz[0x7C], 24.576MHz[0x4C]
		{  0x3a,  0x77  },
		{  0x3b,  0xff  },
		{  0x3c,  0x79  },
		{  0x3e,  0x67  },
		{  0x3f,  0x00  },
		{  0x42,  0x14  },
		{  0x44,  0x40  },
		{  0x47,  0xc0  },
		{  0x49,  0x4f  },
		{  0x4a,  0x10  },
		{  0x53,  0x20  },
		{  0x55,  0xfc  },
		{  0x57,  0x10  },
		{  0x5a,  0x83  },
		{  0x60,  0x13  },
		{  0x6b,  0xc5  },
		{  0x6c,  0x8d  },
		{  0x6d,  0x7d  },
		{  0x72,  0xb0  },
		{  0x73,  0xca  },
		{  0x77,  0x89  },
		{  0x84,  0x90  },
		{  0x85,  0xa0  },
		{  0x86,  0x42  },
		{  0x87,  0x60  },
		{  0x8a,  0xf6  },
		{  0x8b,  0x89  },
		{  0x8c,  0x78  },
		{  0x90,  0x07  },
		{  0xb5,  0x1b  },
		{  0xc0,  0x31  },
		{  0xc1,  0xe8  },
		{  0xc3,  0xa2  },
		{  0xc4,  0xac  },
		{  0xc6,  0xeb  },
		{  0xca,  0x38  },
		{  0xcb,  0x8c  },
		{  0xcd,  0xa1  },
		{  0xce,  0xfc  },
		{  0xd0,  0x3f  },
		{  0xd4,  0x13  },
		{  0xd5,  0xf9  },
		{  0xd7,  0xa6  },
		{  0xd8,  0xac  },
		{  0xd9,  0x16  },
		{  0xda,  0x79  },
		{  0xde,  0x37  },
		{  0xdf,  0x3d  },
		{  0xe1,  0xa0  },
		{  0xe2,  0x0c  },
		{  0xe4,  0x3a  },
		{  0xa5,  0x00  },
};	

const PN_U8 INIT_SETPUP[44][7] = {  
 /*                   Clock Synthesizer                */ 
   //0xE8/	/0xE9/	/0xEA/	/0xEB/	/0xEC/	/0xED/	/0xEE/	
   { 0x0D,	0x01,	0x1F,	0x27,	0x07,	0x80,	0xB9},  // Based 13     MHz X-tal with  8	  MHz ADC Sampling Clock
   { 0x0D,	0x01,	0x1F,	0x27,	0x07,	0xB0,	0xB9},	// Based 13     MHz X-tal with  9	  MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0F,	0x27,	0x07,	0x60,	0xB8},	// Based 16     MHz X-tal with  8	  MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0F,	0x27,	0x07,	0x6C,	0xB8},	// Based 16     MHz X-tal with  9	  MHz ADC Sampling Clock
   { 0x05,	0x01,	0x1F,	0x27,	0x07,	0x90,	0xB8},	// Based 16     MHz X-tal with  9.6   MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0F,	0x27,	0x07,	0x60,	0xB8},	// Based 16.384 MHz X-tal with  8.192 MHz ADC Sampling Clock
   { 0x10,	0x01,	0x1F,	0x27,	0x07,	0x77,	0xB9},	// Based 16.384 MHz X-tal with  8	  MHz ADC Sampling Clock
   { 0x08,	0x01,	0x1F,	0x27,	0x06,	0xE1,	0xB8},	// Based 16.384 MHz X-tal with  9.6   MHz ADC Sampling Clock
   { 0x06,	0x01,	0x13,	0x25,	0x06,	0x80,	0xB4},	// Based 18     MHz X-tal with  8     MHz ADC Sampling Clock
   { 0x06,	0x01,	0x13,	0x25,	0x06,	0x90,	0xB4},	// Based 18     MHz X-tal with  9     MHz ADC Sampling Clock
   { 0x05,	0x01,	0x13,	0x25,	0x06,	0x80,	0xB4},	// Based 18     MHz X-tal with  9.6   MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0B,   0x23,	0x06,	0x50,	0xB0},	// Based 19.2   MHz X-tal with  8     MHz ADC Sampling Clock
   { 0x19,	0x01,	0x1F,	0x27,	0x07,	0x00, 	0xBA},	// Based 19.2   MHz X-tal with 	8.192 MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0B,	0x23,	0x06,	0x5A,	0xB0},  // Based 19.2   MHz X-tal with 	9	  MHz ADC Sampling Clock
   { 0x04,	0x01,	0x0B,	0x23,	0x06,	0x60,	0xB0},	// Based 19.2   MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x06,	0x01,	0x0F,	0x27,	0x07,	0x60,	0xB8},	// Based 24     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x06,	0x01,	0x0F,	0x27,	0x07,	0x6C,	0xB8},	// Based 24     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x05,	0x01,	0x0B,	0x23,	0x06,	0x60,	0xB0},	// Based 24     MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x06,	0x01,	0x0F,  	0x27,	0x07,	0x60,	0xB8},	// Based 24.576 MHz X-tal with 	8.192 MHz ADC Sampling Clock
   { 0x08,	0x01,	0x13,	0x25,	0x06,	0x7D,	0xB4},	// Based 24.576 MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x0C,	0x01,	0x1F,	0x27,	0x06,	0xE1,	0xB8},	// Based 24.576 MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x0D,	0x01,	0x1F,	0x27,	0x06,	0xC0,	0xB8},	// Based 26     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x0D,	0x01,	0x1F,	0x27,	0x06,	0xD8,	0xB8},	// Based 26     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x09,	0x01,	0x13,	0x25,	0x06,	0x80,	0xB4},	// Based 27     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x06,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 27     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x08,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 32		MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x08,	0x01,	0x0F, 	0x27,	0x07,	0x6C,	0xB8},  // Based 32		MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x1F,	0x27,	0x07,	0x90,	0xB8},	// Based 32		MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x08,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 32.768 MHz X-tal with 	8.192 MHz ADC Sampling Clock
   { 0x20,	0x01,	0x1F,	0x27,	0x07,	0x77,	0xB9},	// Based 32.768 MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x10,	0x01,	0x1F,	0x27,	0x06,	0xE1,	0xB8},	// Based 32.768 MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x09,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 36     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x09,	0x01,	0x0F, 	0x27,	0x07,	0x6C,	0xB8},	// Based 36     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x13,	0x25,	0x06,	0x80,	0xB4},	// Based 36     MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x08,	0x01,	0x0B, 	0x23,	0x06,	0x50,	0xB0},	// Based 38.4   MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x19,	0x01,	0x1F,	0x27,	0x06,	0x00,   0xB9},	// Based 38.4   MHz X-tal with 	8.192 MHz ADC Sampling Clock
   { 0x08,	0x01,	0x0B, 	0x23,	0x06,	0x5A,	0xB0},	// Based 38.4   MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x0F, 	0x27,	0x07,	0x78,	0xB8},	// Based 38.4   MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 40     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x0F, 	0x27,	0x07,	0x6C,	0xB8},  // Based 40     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x19,	0x01,	0x1F,	0x27,	0x06,	0x20,	0xB9},	// Based 40     MHz X-tal with 	9.6   MHz ADC Sampling Clock
   { 0x0C,	0x01,	0x0F, 	0x27,	0x07,	0x60,	0xB8},	// Based 48     MHz X-tal with 	8     MHz ADC Sampling Clock
   { 0x0C,	0x01,	0x0F, 	0x27,	0x07,	0x6C,	0xB8},	// Based 48     MHz X-tal with 	9     MHz ADC Sampling Clock
   { 0x0A,	0x01,	0x0B, 	0x23,	0x06,	0x60,	0xB0}	// Based 48     MHz X-tal with 	9.6   MHz ADC Sampling Clock
};		

///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////    PNS3030 setting function    //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
PN_VOID Register_MAP_Select(PN_U8 map_sel)
{
	PN3030_Byte_Write(PN3030E_ADDR, 0x03, (DEMOD_OSC_DIV2 | map_sel));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////SetFreq FUNCTION///////////////////////////////////////////
//                                                                                                  //
//    Type :         unsigned char                                                                  //
//    return value : 1: Stable                                                                      //
//    Argument :     PN_U8 ChannelByDecimal                                                         //
//                   ==>ex>CHANNEL 13 is set decimal value 13.                                      //
//    Description : Auto channel setting function                                                   //
//////////////////////////////////////////////////////////////////////////////////////////////////////
PN_U8 PNS3030_SetFreq(PN_FLOAT FREQ,PN_FLOAT iIF) 
{
    PN_U8 DIV_Rate;
    PN_U32 PLLNF, wr_PLLNF_val, rd_PLLNF_val;
    PN_FLOAT PLLFREQ,FLO;
    PN_U8 PLL_Verify_cnt=10;  // PLLNF chacking count
    PN_U8 rd_PLLNF_12,rd_PLLNF_13,rd_PLLNF_14,rd_PLLNF_15;

    FLO=(PN_FLOAT)(FREQ+iIF+0.03);

    Register_MAP_Select(RF_E_PAGE);
    PN3030_Byte_Read(PN3030E_ADDR,0x27, &DIV_Rate);
    DIV_Rate =(DIV_Rate & 0xC0) >>6;  //VCO_DIV_RATIO     
    PLLFREQ = FLO * (1<<DIV_Rate)*2;
		
	PLLNF = (PN_U32)((PLLFREQ/PNS3030_REFFREQ)*1048576);
	
	PN3030_Byte_Write(PN3030E_ADDR,0x23, (PN_U8)((PLLNF>>22)&0xFF));
	PN3030_Byte_Write(PN3030E_ADDR,0x24, (PN_U8)((PLLNF>>14)&0xFF));
	PN3030_Byte_Write(PN3030E_ADDR,0x25, (PN_U8)((PLLNF>>6)&0xFF));	
	PN3030_Byte_Write(PN3030E_ADDR,0x26, (PN_U8)(((PLLNF&0x0000003F)<<2)));
	
	RF_Delay_Ms(1);  //1ms Delay
    PN3030_Byte_Write(PN3030E_ADDR, 0x20, 0x00); //Must be need //by RAON 100503	
	
	RF_Delay_Ms(2);  //2ms Delay
	
	wr_PLLNF_val = PLLNF >> 1;
	do{
		PN3030_Byte_Read(PN3030E_ADDR,0x12, &rd_PLLNF_12);
		PN3030_Byte_Read(PN3030E_ADDR,0x13, &rd_PLLNF_13);
		PN3030_Byte_Read(PN3030E_ADDR,0x14, &rd_PLLNF_14);	
		PN3030_Byte_Read(PN3030E_ADDR,0x15, &rd_PLLNF_15);
		rd_PLLNF_val = (rd_PLLNF_12 << 22)+(rd_PLLNF_13 << 14)+(rd_PLLNF_14 << 6)+(rd_PLLNF_15 >> 2);
	
		if((wr_PLLNF_val == rd_PLLNF_val ) || (wr_PLLNF_val == (PN_U32)(rd_PLLNF_val>>1)))
		{
			if(rd_PLLNF_15 & 0x02)   // PLL_Lock flag check 2011.10.06 
			{
				break;
			}
			else
			{
				PN3030_Byte_Write(PN3030E_ADDR, 0x20, 0x00); //Must be need //by RAON 100503	
				RF_Delay_Ms(2);  //2ms Delay
			}				
		}
		else
		{ 
			PN3030_Byte_Write(PN3030E_ADDR, 0x20, 0x00); //Must be need //by RAON 100503	
			RF_Delay_Ms(2);  //2ms Delay
		}
	}while(PLL_Verify_cnt--);
		
    return PN_FN_OK;
}

PN_S32 PNS3030_Tuner_ChangeFreq(PN_FLOAT tuner_freq)
{
	SetUpClockType(tuner_freq);

    if(tuner_freq < BANDII) 									/// Band-II 
	{
		if(TuneBand != TuneBandII)
			PNS3030_Tuner_Init(0x86,tuner_freq);
		PNS3030_SetFreq(tuner_freq, FM_IF);  
	}
	else if((BANDII < tuner_freq) && ( tuner_freq < BANDIII)) 	/// Band-III 
	{
		if(TuneBand != TuneBandIII)
			PNS3030_Tuner_Init(0x86,tuner_freq);
		PNS3030_SetFreq(tuner_freq, TDMB_IF);  
	}
	else if((tuner_freq > BANDIII) && (tuner_freq < BANDUHF)) 	/// UHF-Band 
	{
		if(TuneBand != TuneUHF)
			PNS3030_Tuner_Init(0x86,tuner_freq);
		PNS3030_SetFreq(tuner_freq, ONESEG_IF);  
	}
	else if(tuner_freq > BANDUHF) 								/// L-Band 
	{
		if(TuneBand != TuneLBand)
			PNS3030_Tuner_Init(0x86,tuner_freq);
		PNS3030_SetFreq(tuner_freq, TDMB_IF);  
	}	
	
	return PN_FN_OK;
}
			
//////////////////////////////////SelectPowerType FUNCTION////////////////////////////////////////////
//                                                                                                  //
//    Type :         void                                                                           //
//    return value : None                                                                           //
//    Argument :     power type, IO Voltage type : refer to MTV_Type_Def.h file                     //
//    Description :  Power type and IO Voltage type sellection                                      //
//                   ==>I2C Write sequency is very important 0x52 => 0x54 => 0x30 => 0x2F           //
//////////////////////////////////////////////////////////////////////////////////////////////////////
PN_VOID SelectPowerType(PN_FLOAT tuner_freq, PN_U8 pow_type, PN_U8 io_type)
{
	PN_U8 REG2F = 0x61;   // DCDC_OUTSEL = 0x03, EXT_IOLDOCON = 0x01
	PN_U8 REG30 = 0xF0;   // IOLDOCON_I2C
	PN_U8 REG52 = 0x07;   // LDODIG_HT = 0x06;
	PN_U8 REG54 = 0x0C;   // LDODIG_I2C = 0x01;  // 0x04 -> 0x0C change by Raon 2011.03.04
	
	if(tuner_freq < BANDII) 									/// Band-II 
	{
		REG54 = 0x0C;
	}
	else if((BANDII < tuner_freq) && ( tuner_freq < BANDIII)) /// Band-III 
	{
		REG54 = 0x1C;  //0x54[4:2] "2" -> "4" 2011.11.21 by Raon -> "7" 2011.12.15 by Raon
	}
	else if((tuner_freq > BANDIII) && (tuner_freq < BANDUHF)) /// UHF-Band 
	{
		REG54 = 0x1C;
	}
	else if(tuner_freq > BANDUHF) 							/// L-Band 
	{
		REG54 = 0x1C;  //0x54[4:2] "2" -> "4" 2011.11.21 by Raon -> "7" 2011.12.15 by Raon
	}
	else
	{
		REG54 = 0x10;
	}

	REG30 = REG30 | (io_type<<1);   // IO Type Select.

	Register_MAP_Select(RF_E_PAGE);	
	switch(pow_type) {

		case USE_POW_EXTERNAL :
             REG2F = REG2F | 0x14; // PDDCDC_I2C = 1, PDLDO12_I2C = 1 ; 
			break;
		case USE_POW_LDO :
             REG2F = REG2F | 0x10; // PDDCDC_I2C = 1, PDLDO12_I2C = 0 ; 
			break;
		case USE_POW_DCDC :
             REG2F = REG2F | 0x04; // PDDCDC_I2C = 0, PDLDO12_I2C = 1 ; 
			break;
		default :
             REG2F = REG2F | 0x10; // Default setting is LDO. 
			break;
	}
	/*Below Power Up sequence is very important.*/
	PN3030_Byte_Write(PN3030E_ADDR, 0x54, REG54);  // 위치 변경 change by Raon 2011.03.04
	PN3030_Byte_Write(PN3030E_ADDR, 0x52, REG52);
	PN3030_Byte_Write(PN3030E_ADDR, 0x30, REG30);
	PN3030_Byte_Write(PN3030E_ADDR, 0x2F, REG2F);	
}

////////////////////////////////////SetUpClockType FUNCTION///////////////////////////////////////////
//                                                                                                  //
//    Type :         void                                                                           //
//    return value : None                                                                           //
//    Argument :     Non : refer to MTV_Type_Def.h file  for CLK_TYPE_SEL                           //
//    Description :  1.set Internal PLL frequency based on External X-tal                           //
//                     ==>Registers from 0xE8 to 0xEE are Write only Registers. Those can't read    //
//                   2. Set Auto Channel Configuration                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////
PN_VOID SetUpClockType(PN_FLOAT frequency)
{
	PN_U8 REGE8;  
	PN_U8 REGE9; 
	PN_U8 REGEA;  
	PN_U8 REGEB;  
	PN_U8 REGEC;  
	PN_U8 REGED;  
	PN_U8 REGEE; 
	PN_U8 u8_ADCType;
	PN_U8 ClkTypeSel;
	
#ifdef USE_POW_DCDC_MODE
	PN_U8 RD15, RD2F;
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////// ADC Sampling Clock select  /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
	if(frequency < BANDII) 									/// Band-II 
	{
		u8_ADCType = ADC_8_192MHZ;
	}
	else if((BANDII < frequency) && ( frequency < BANDIII)) /// Band-III 
	{
		//// New version
		if(frequency <= 171.0) 							 u8_ADCType = ADC_8_192MHZ;
		else if(frequency >171.0 && frequency <= 173.0)  u8_ADCType = ADC_8_0MHZ;
		else if(frequency >173.0 && frequency <= 174.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >174.0 && frequency <= 177.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >177.0 && frequency <= 180.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >180.0 && frequency <= 181.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >181.0 && frequency <= 183.5)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >183.5 && frequency <= 185.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >185.0 && frequency <= 188.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >188.0 && frequency <= 191.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >191.0 && frequency <= 193.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >193.0 && frequency <= 194.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >194.0 && frequency <= 195.5)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >195.5 && frequency <= 196.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >196.0 && frequency <= 197.0)  u8_ADCType = ADC_8_0MHZ;
		else if(frequency >197.0 && frequency <= 204.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >204.0 && frequency <= 206.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >206.0 && frequency <= 208.5)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >208.5 && frequency <= 209.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >209.0 && frequency <= 212.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >212.0 && frequency <= 213.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >213.0 && frequency <= 213.1)  u8_ADCType = ADC_8_0MHZ;
		else if(frequency >213.1 && frequency <= 213.5)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >213.5 && frequency <= 221.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >221.0 && frequency <= 222.0)  u8_ADCType = ADC_8_0MHZ;
		else if(frequency >222.0 && frequency <= 229.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >229.0 && frequency <= 230.0)  u8_ADCType = ADC_9_6MHZ;
		else if(frequency >230.0 && frequency <= 237.0)  u8_ADCType = ADC_8_192MHZ;
		else if(frequency >237.0 && frequency <= 238.0)  u8_ADCType = ADC_8_0MHZ;
		else											 u8_ADCType = ADC_8_192MHZ;
	}
	else if((frequency > BANDIII) && (frequency < BANDUHF)) /// UHF-Band 
	{
		u8_ADCType = ADC_8_192MHZ;
	}
	else if(frequency > BANDUHF) 							/// L-Band 
	{
		if (frequency >1452.0 && frequency <= 1475.0)      u8_ADCType = ADC_8_192MHZ;
		else if (frequency >1475.0 && frequency <= 1476.0) u8_ADCType = ADC_9_6MHZ;
		else if (frequency >1476.0 && frequency <= 1490.0) u8_ADCType = ADC_8_192MHZ;
		else 											   u8_ADCType = ADC_9_6MHZ;
	}
	else
	{
		u8_ADCType = ADC_8_192MHZ;
	}
	
//////////////////////////////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////// Clock Synthesizer  //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
	if(REF_FREQ_DEF == 16.384)
	{
		if(u8_ADCType == ADC_8_0MHZ)				ClkTypeSel = XTAL16_384M_ADC_8M;
		else if(u8_ADCType == ADC_8_192MHZ)			ClkTypeSel = XTAL16_384M_ADC_8_192M;
		else if(u8_ADCType == ADC_9_6MHZ)			ClkTypeSel = XTAL16_384M_ADC_9_6M;
		else										ClkTypeSel = XTAL16_384M_ADC_8_192M;
	}
	else if(REF_FREQ_DEF == 24.576)
	{
		if(u8_ADCType == ADC_8_0MHZ)				ClkTypeSel = XTAL24_576M_ADC_8M;
		else if(u8_ADCType == ADC_8_192MHZ)			ClkTypeSel = XTAL24_576M_ADC_8_192M;
		else if(u8_ADCType == ADC_9_6MHZ)			ClkTypeSel = XTAL24_576M_ADC_9_6M;
		else										ClkTypeSel = XTAL24_576M_ADC_8_192M;
	}
	else if(REF_FREQ_DEF == 19.2)
	{
		if(u8_ADCType == ADC_8_0MHZ)				ClkTypeSel = XTAL19_2M_ADC_8M;
		else if(u8_ADCType == ADC_8_192MHZ)			ClkTypeSel = XTAL19_2M_ADC_8_192M;
		else if(u8_ADCType == ADC_9_6MHZ)			ClkTypeSel = XTAL19_2M_ADC_9_6M;
		else										ClkTypeSel = XTAL19_2M_ADC_8_192M;
	}
	else
	{
		if(u8_ADCType == ADC_8_0MHZ)				ClkTypeSel = XTAL24_576M_ADC_8M;
		else if(u8_ADCType == ADC_8_192MHZ)			ClkTypeSel = XTAL24_576M_ADC_8_192M;
		else if(u8_ADCType == ADC_9_6MHZ)			ClkTypeSel = XTAL24_576M_ADC_9_6M;
		else										ClkTypeSel = XTAL24_576M_ADC_8_192M;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
	REGE8 = 0x46 & 0xC0;  
	if((frequency > BANDIII) && (frequency < BANDUHF))  // UHF Add by Raon 2011.03.04
	{
		REGE9 = 0xD4 & 0xF0; 
	}
	else
	{
	    REGE9 = 0x54 & 0xF0;    // Ext X-tal
	    //REGE9 = 0xD4 & 0xF0;      // 192MHz Test by terry 2011.07.19
	}
	REGEA = 0x07 & 0xC0;  
	REGEB = 0x27 & 0xC0;  
	REGEC = 0x1E & 0xC0;  
	REGED = 0x18 & 0x00;  
	REGEE = 0xB8 & 0x00;  
	
#ifdef USE_POW_DCDC_MODE
	Register_MAP_Select(RF_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x2F, &RD2F);
	PN3030_Byte_Write(PN3030E_ADDR, 0x2F, (RD2F & 0xF7));	
#endif
	                    /* Clock Synthesizer */ 
	Register_MAP_Select(RF_E_PAGE);
    PN3030_Byte_Write(PN3030E_ADDR, 0xE8, (REGE8 | INIT_SETPUP[ClkTypeSel][0]));            
	PN3030_Byte_Write(PN3030E_ADDR, 0xE9, (REGE9 | INIT_SETPUP[ClkTypeSel][1]));		    		
	PN3030_Byte_Write(PN3030E_ADDR, 0xEA, (REGEA | INIT_SETPUP[ClkTypeSel][2]));				
	PN3030_Byte_Write(PN3030E_ADDR, 0xEB, (REGEB | INIT_SETPUP[ClkTypeSel][3]));				
	PN3030_Byte_Write(PN3030E_ADDR, 0xEC, (REGEC | INIT_SETPUP[ClkTypeSel][4]));				   
	PN3030_Byte_Write(PN3030E_ADDR, 0xED, (REGED | INIT_SETPUP[ClkTypeSel][5]));				  
	PN3030_Byte_Write(PN3030E_ADDR, 0xEE, (REGEE | INIT_SETPUP[ClkTypeSel][6]));	 
	
#ifdef USE_POW_DCDC_MODE
	PN3030_Reg_Page_Sel(RF_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR,0x15,&RD15);
	if(RD15 & 0x01) 
	{
		 PN3030_Byte_Write(PN3030E_ADDR,0x2F,RD2F);
	}
	else
	{
		// debug message
	}
#endif

	if((frequency > BANDIII) && (frequency < BANDUHF))  // UHF Add by Raon 2011.03.04
	{
		Register_MAP_Select(HOST_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR, 0x1A, 0x8B);
		PN3030_Byte_Write(PN3030E_ADDR, 0x18, 0xC0);
		PN3030_Byte_Write(PN3030E_ADDR, 0x19, 0x03);
		//PN3030_Byte_Write(PN3030E_ADDR, 0x07, 0x00);  // ISDB-T enable flag
	}
	
	EV_INIT_ADC_SET(frequency, 1, u8_ADCType);   // (frequency, tuner_type, ADCType)
}

PN_VOID EV_INIT_ADC_SET(PN_FLOAT frequency, PN_U8 tuner_type, PN_U8 ADCType)
{
#ifdef USE_POW_DCDC_MODE
	PN_U8 RD15, RD2F;
#endif 
//////////////////////////////////// ADD for ADC Clock sampling //////////////////////////////////
	if(frequency < BANDII)  // 8MHz일경우 FM sampling 31.25KHz [성능 테스트후 8MHz 사용여부 결정 필요]
	{                       // 9MHz , 9.6MHz sapling 사용 불가함 
		switch(ADCType)
		{
			case ADC_8_0MHZ:      //ADC sampling clock = 8.0MHz
				PN3030_Reg_Page_Sel(PN3030E_ADDR, HOST_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0xC8,0x03); 
			    
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); 
			
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0x00); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x10); //PNCO
				break;
			case ADC_8_192MHZ:	//ADC sampling clock = 8.192MHz
				PN3030_Reg_Page_Sel(PN3030E_ADDR, HOST_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0xC8,0x00); 
			    
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); 
			
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xA0); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x0F); //PNCO
				break;
			default:	//ADC sampling clock = 8.192MHz
				PN3030_Reg_Page_Sel(PN3030E_ADDR, HOST_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0xC8,0x00); 
			    
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); 
			
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
				PN3030_Byte_Write(PN3030E_ADDR,0x42,0xA0); //PNCO
				PN3030_Byte_Write(PN3030E_ADDR,0x43,0x0F); //PNCO
				break;
		} 
		PN3030_Byte_Write(PN3030E_ADDR,0x10,0x48); 
		PN3030_Byte_Write(PN3030E_ADDR,0x10,0xC9); 
	}
	else
	{
		switch(ADCType)
		{
			case ADC_8_0MHZ:      //ADC sampling clock = 8.0MHz
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); 
			
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
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
				break;
			case ADC_8_192MHZ:	//ADC sampling clock = 8.192MHz
			    PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x01); 
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
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
				break;
			case ADC_9_0MHZ:		//ADC sampling clock = 9.0MHz
				PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x21); //TNCO
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
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
				break;
			case ADC_9_6MHZ:	//ADC sampling clock = 9.6MHz
				PN3030_Reg_Page_Sel(PN3030E_ADDR, COMM_E_PAGE);
			    PN3030_Byte_Write(PN3030E_ADDR,0x6A,0x31); //TNCO
			   
				PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
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
				break;	
		}
	#ifdef USE_POW_DCDC_MODE
		PN3030_Reg_Page_Sel(PN3030E_ADDR, RF_E_PAGE);
		PN3030_Byte_Read(PN3030E_ADDR,0x15,&RD15);
		if(RD15 & 0x01) 
		{
			 PN3030_Byte_Write(PN3030E_ADDR,0x2F,RD2F);
		}
		else
		{
			// debug message
		}
	#endif

		PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
		PN3030_Byte_Write(PN3030E_ADDR,0x10,0x48); 
		PN3030_Byte_Write(PN3030E_ADDR,0x10,0xC9); 
	}
}

/////////////////////////////////////////RFInit FUNCTION//////////////////////////////////////////////
//                                                                                                  //
//    Type :         unsigned char                                                                  //
//    return value : 1: Stable                                                                      //
//    Argument :     None                                                                           //
//    Description :  Conan RF Part Init function.                                                   //
//////////////////////////////////////////////////////////////////////////////////////////////////////
PN_U8 PNS3030_Tuner_Init(PN_U8 pn_type, PN_FLOAT tuner_freq)
{	
 	PN_S32 i;
	PN_U8 rfReg_10 = 0;
	PN_U8 rfReg_11 = 0;

	PN_U8 read_val=0;

	SelectPowerType(tuner_freq, POWER_TYPE, IO_TYPE);
	SetUpClockType(tuner_freq);  //Please see MTV_Type_Def.h file for used Clock.


	Register_MAP_Select(RF_E_PAGE);
    if(tuner_freq < BANDII) 								/// Band-II 
	{
		TuneBand = TuneBandII;
		for( i = 0; i < sizeof( t_FM_INIT ) / sizeof( PNS3030_INIT ); i++ ) 
		{
			PN3030_Byte_Write(PN3030E_ADDR, t_FM_INIT[i].TAddr, t_FM_INIT[i].TData);
		}
		PNS3030_SetFreq(tuner_freq, FM_IF);  
	}
	else if((BANDII < tuner_freq) && ( tuner_freq < BANDIII)) /// Band-III 
	{
		TuneBand = TuneBandIII;
		for( i = 0; i < sizeof( t_TDMB_INIT ) / sizeof( PNS3030_INIT ); i++ ) 
		{
			PN3030_Byte_Write(PN3030E_ADDR, t_TDMB_INIT[i].TAddr, t_TDMB_INIT[i].TData);
		}
		PNS3030_SetFreq(tuner_freq, TDMB_IF);  
	}
	else if((tuner_freq > BANDIII) && (tuner_freq < BANDUHF)) /// UHF-Band 
	{
		TuneBand = TuneUHF;
		for( i = 0; i < sizeof( t_ISDBT_INIT ) / sizeof( PNS3030_INIT ); i++ ) 
		{
			PN3030_Byte_Write(PN3030E_ADDR, t_ISDBT_INIT[i].TAddr, t_ISDBT_INIT[i].TData);
		}
		PNS3030_SetFreq(tuner_freq, ONESEG_IF);  
	}
	else if(tuner_freq > BANDUHF) 							/// L-Band 
	{
		TuneBand = TuneLBand;
		for( i = 0; i < sizeof( t_TDMB_L_INIT ) / sizeof( PNS3030_INIT ); i++ ) 
		{
			PN3030_Byte_Write(PN3030E_ADDR, t_TDMB_L_INIT[i].TAddr, t_TDMB_L_INIT[i].TData);
		}
		PNS3030_SetFreq(tuner_freq, TDMB_IF);  
	}

	// Raon tech 2011.08.03 update
	//////////////////////////////CODE PATCH FOR OTP////////////////////////////////////
	PN3030_Byte_Read(PN3030E_ADDR, 0x10, &rfReg_10);
	PN3030_Byte_Read(PN3030E_ADDR, 0x11, &rfReg_11);
    if(1/*((PN_U16)(rfReg_10 << 8) | (PN_U16)(rfReg_11)) != 0xFFFF*/)
    {
		switch( TuneBand )
		{
			case TuneUHF :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0x48); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xE0); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x05); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0x94);   // 128ms
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x25); 
				break;

			case TuneBandII :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0x48); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xE1); 
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x14); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x05); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0x94);   // 128ms
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x25); 
				break;

			case TuneBandIII :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0x48); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xE0); //  by Raon 20110826
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x04); //  by Raon 20110826
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x05); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0x94);   // 128ms
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x25); 
				break;

			case TuneLBand:
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0x48); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xE0); 
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x04); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x05); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0x8C);   // 32ms
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x25); 
				break;
			default:
				break;
		}
		//PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x05); 
		//PN3030_Byte_Write(PN3030E_ADDR,0x2D,0x94);   // 128ms
		//PN3030_Byte_Write(PN3030E_ADDR,0x61,0x25); 
    }
	else
    {
		switch( TuneBand )
		{
			case TuneUHF :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0xC8); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xC0); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x07); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0xF4);   // 128ms 
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x2A); 
				break;

			case TuneBandII :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0xC8); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xB1); 
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x14); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x07); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0xF4);   // 128ms 
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x2A); 
				break;

			case TuneBandIII :
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0xC8); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xB0); 
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x04);  //  by Raon 20110826
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x07); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0xF4);   // 128ms 
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x2A); 
				break;

			case TuneLBand:
				PN3030_Byte_Write(PN3030E_ADDR,0x2C,0xC8); 
				PN3030_Byte_Write(PN3030E_ADDR,0x47,0xB0); 
				PN3030_Byte_Write(PN3030E_ADDR,0x35,0x04); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x07); 
				PN3030_Byte_Write(PN3030E_ADDR,0x2D,0xEC);   // 32ms 
				PN3030_Byte_Write(PN3030E_ADDR,0x61,0x2A); 
				break;
			default:
				break;
		}
		//PN3030_Byte_Write(PN3030E_ADDR,0x2A,0x07); 
		//PN3030_Byte_Write(PN3030E_ADDR,0x2D,0xF4);   // 128ms 
		//PN3030_Byte_Write(PN3030E_ADDR,0x61,0x2A); 
    }

	return PN_FN_OK;						
}		

PN_S32 AGC_STAT_PNS3030(PN_S32 *RF_level, PN_U8 *IF_level, PN_U8 *GVBB_level)
{
	PN_U8 temp;
	
	Register_MAP_Select(RF_E_PAGE);
	PN3030_Byte_Read(PN3030E_ADDR, 0x00, &temp);
	*IF_level   = temp;
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x02, &temp);
	*RF_level   = (PN_S32)(temp>>1);	
	
	PN3030_Byte_Read(PN3030E_ADDR, 0x04, &temp);
	*GVBB_level = temp;
	
	return PN_FN_OK;
}

PN_S32 PNS3030_AGC_CONTROL(PN_U8 pn_type,PN_FLOAT tuner_freq)
{
	return PN_FN_OK;
}	


/***************************************************************************/
/*
	brief		Get the RSSI level
	param[out]	sig_level	RSSI 
	param[out]	IF_level	IF strength
	param[out]	GVBB_level	GVBB strength
	return		None
	author 		28/06/2012 Richard <superyj@conversdigital.com>
*/
/***************************************************************************/
void PN_DrvSLRfGetRssi(PN_U8 pn_type, PN_FLOAT* sig_level, PN_S32* sig_bar, PN_U32 freq)
{
	PN_FLOAT RF_LEVEL = 0.;
	PN_U8 GVRF = 0;      /* RF page 0x00 */
	PN_S32 GVBB_ANA = 0;  /* RF page 0x02 */
	PN_U8 GVBB_DIG = 0;  /* RF page 0x04 */
	//PN_U8 SamADCType = 0;
	PN_S32 Pre_AGC = 0;
	PN_FLOAT frequency; 

	frequency = (PN_FLOAT)freq / 1000;

    /* New version PNS3030A by terry */
	AGC_STAT_PNS3030(&GVBB_ANA, &GVRF, &GVBB_DIG);
	Pre_AGC = SLAGC_STAT_PN302X();
	
	if (frequency < BANDII) 								/* Band-II RSSI Calculation */
	{
		RF_LEVEL = (PN_FLOAT)(-((((GVRF & 0x30) >> 4) * 12. ) + ((GVRF & 0x0F) * 3.0) + ((GVBB_ANA & 0x0F) * 3.0) + ((GVBB_DIG & 0x7F) * 0.4)) + ((frequency / 110) * 20) - 17); 
		if ((GVRF & 0xC0) == 0x40)
		{
			RF_LEVEL += 19. ;
		}
		else
		{
			RF_LEVEL += 26. ;
		}
	}
	else if ((BANDII < frequency) && ( frequency < BANDIII)) /* Band-III RSSI Calculation */
	{
		if (GVRF & 0x30)
		{
			RF_LEVEL = (PN_FLOAT)(-((((GVRF & 0x30) >> 4) * 12. ) + ((GVRF & 0x0F) * 2.8) - ((Pre_AGC * 2.4) / 13) + 131));
			if ((GVRF & 0x30) == 0x20)
			{
				RF_LEVEL += 1; 
			}
			if ((frequency > 220. ) && ((GVRF & 0x0F) == 0x08))
			{
				RF_LEVEL += 2;
			}
			if ((GVBB_DIG & 0x7F) > 40)
			{
				RF_LEVEL += 1;	
			}
		}
		else
		{ 
			RF_LEVEL = (PN_FLOAT)(-((((GVRF & 0x30) >> 4) * 12. ) + ((GVRF & 0x0F) * 2.8) - ((Pre_AGC * 1.1) / 12.55) + 79));
		}
		if ((GVRF & 0xC0) == 0x40)
		{
			RF_LEVEL -= 2;
		}
	}
	else if ((frequency > BANDIII) && (frequency < BANDUHF)) /* UHF-Band RSSI Calculation */
	{
		RF_LEVEL = (PN_FLOAT)(-((((GVRF & 0x30) >> 4) * 9.5) + ((GVRF & 0x0F) * 3.0) + ((GVBB_ANA & 0x0F) * 3.0) + ((GVBB_DIG & 0x7F) * 0.5)) + 20.); 
		if ((GVRF & 0xC0) == 0x30)
		{
			RF_LEVEL += 15. ;
		}
		else
		{
			RF_LEVEL += 20. ;
		}
	}
	else if (frequency > BANDUHF) 							/* L-Band RSSI Calculation */
	{
		RF_LEVEL = (PN_FLOAT)(-((((GVRF & 0x30) >> 4) * 12. ) + ((GVRF & 0x0F) * 3.0) + ((GVBB_ANA & 0x0F) * 2.8) + ((GVBB_DIG & 0x7F) * 0.5)) + 30.); 
	}

	//*sig_level = (PN_S16)(RF_LEVEL * 10);
	*sig_level = RF_LEVEL;
	*sig_bar = (PN_S8)((((120 + RF_LEVEL) * 100 ) / 130));	
	return ;
}

/***************************************************************************/
/*
	brief		Get the pre-agc value
	param[in]	None
	return		Pre-agc gain
	author 		28/06/2012 Richard <superyj@conversdigital.com>
*/
/***************************************************************************/
PN_S32  SLAGC_STAT_PN302X(PN_VOID)
{
	PN_U8 agc_val0, agc_val1;
	PN_S32 agc;

	PN3030_Reg_Page_Sel(PN3030E_ADDR, OFDM_E_PAGE);
	PN3030_Field_Write(PN3030E_ADDR, MON_PRE_START, 0x80, 0x80); /* One shot value for PRE AGC value read */
	PN3030_Byte_Read(PN3030E_ADDR, MON_CNT_PRE1_L, &agc_val0);
	PN3030_Byte_Read(PN3030E_ADDR, MON_CNT_PRE1_H, &agc_val1);
	agc = (agc_val1 << 2) | (agc_val0 & 0x03);	
	return agc;
}

