#include "P32_BaseFunc.h"
#include "P32_Rf_Api.h"
#include "P32_Rf_PNx3030x.h"
#include "P32_Rf_Max2172.h"

/* Initialize Tuner */
PN_S32 PN_INIT_TUNER(PN_U8 pn_type, PN_U8 tuner, PN_FLOAT tuner_freq)
{
	switch(tuner)
	{
		case PNS3030D:
		case PNS3030A:
			PNS3030_Tuner_Init(pn_type, tuner_freq);
			break;
		case MAX2172:
			MAX2172_Tuner_Init(pn_type, tuner_freq);
			break;
		default:
			return PN_FN_FAIL;
	}
	return PN_FN_OK;
}

/* Initialize Tuner */
PN_S32 CHANGE_TUNER_FREQ(PN_U8 tuner, PN_FLOAT tuner_freq)
{
	switch(tuner)
	{
		case PNS3030D:
		case PNS3030A:
			PNS3030_Tuner_ChangeFreq(tuner_freq);
			break;
		case MAX2172:
			MAX2172_Tuner_ChangeFreq(0x86,tuner_freq);
			break;
		default:
			return PN_FN_FAIL;
	}
	return PN_FN_OK;
}

PN_U8 AGC_STAT_TUNER(PN_U8 tuner, PN_S32 *RF_level, PN_U8 *IF_level, PN_U8 *GVBB_level)
{
	PN_S32 DATA0=0;
	PN_U8 DATA1=0;
	PN_U8 DATA2=0;
	switch(tuner)
	{
		case PNS3030D:
		case PNS3030A:
			AGC_STAT_PNS3030(&DATA0, &DATA1, &DATA2);
			break;
		case MAX2172:
			AGC_STAT_MAX2172(0x86, &DATA0, &DATA1);
			break;
		default:
			return PN_FN_FAIL;
	}
	*RF_level = DATA0;
	*IF_level = DATA1;
	return PN_FN_OK;
}

PN_U8 AGC_CON_TUNER(PN_U8 tuner,PN_FLOAT tuner_freq,int post_agc)
{
	switch(tuner)
	{
#if 0	// ksjuny 20140425
		case MAX2171:
			Max2171_AGC_CONTROL(tuner_freq);
			break;
		case MAX2172:
			Max2172_AGC_CONTROL(tuner_freq);
			break;
#endif
		default:
			return PN_FN_FAIL;
	}
	return PN_FN_OK;
}

PN_U8 SLEEP_TUNER(PN_U8 tuner)
{
	switch(tuner)
	{
            default:
		return PN_FN_FAIL;
	}
	return PN_FN_OK;
}

PN_VOID RF_Delay_Us(PN_S32 delay)
{
	Delay_Us(delay);
}

PN_VOID RF_Delay_Ms(PN_S32 delay)
{
	Delay_Ms(delay);
}


float BANDIII_CFREQ_TABLE[4]=
{
	//	(float)180.224,
	(float)184.32,		//18.432
	//	(float)196.608,
	(float)202.752,		//18.432
	//	(float)212.992,
	(float)221.184,		//18.432
	//	(float)229.376,
	(float)239.616		//18.432
};

float LBAND_CFREQ_TABLE[3]=
{
	(float)1456.128,	//18.432
	//	(float)1458.176,	
	(float)1474.56,		//18.432
	//	(float)1490.944,
	(float)1492.992		//18.432
};

PN_S32 T_DMB_CFREQ_SERH(float tuner_freq)
{
	PN_U8 i,j;
	PN_U8 tuner_cfreq_flag = 0;

	if(tuner_freq < BANDIII)
	{
		for(i=0; i<4; i++)
		{
			if(tuner_freq > (BANDIII_CFREQ_TABLE[i]-0.8) && tuner_freq < (BANDIII_CFREQ_TABLE[i]+0.8))
			{
				tuner_cfreq_flag = 1;
				return tuner_cfreq_flag;
			}			
		}
	}
	else
	{
		for(j=0; j<3; j++)
		{
			if(tuner_freq > (LBAND_CFREQ_TABLE[j]-0.8) && tuner_freq < (LBAND_CFREQ_TABLE[j]+0.8))
			{
				tuner_cfreq_flag = 1;
				return tuner_cfreq_flag;
			}			
		}		
	}
	return tuner_cfreq_flag;
}

