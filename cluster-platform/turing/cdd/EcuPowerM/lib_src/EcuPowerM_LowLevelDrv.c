//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2024] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
//#include "Rte_CDD_EcuPowerM.h"
#include "EcuPowerM_LowlevelDrv.h"
#include "Dio.h"
#include "Adc.h"
#include "Pwm.h"
#include "IoHwAb_Adc.h"
#include "IoHwAb_DIn.h"
#include "IoHwAb_DOut.h"
#include "IoHwAb_Pwm.h"
#include "IoHwAb.h"



//=====================================================================================================================
//  PRE PROCEESSORS
//=====================================================================================================================


//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================
#if (ECUPOWERM_ANALOG_CHANNEL_READ_API == STD_ON)
FUNC(void, ECUPOWERM_CODE) AnalogChannelRead(	VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
												P2VAR(uint16, AUTOMATIC, ECUPOWERM_APPL_DATA)buffer);
#endif

//=====================================================================================================================
//  CONST DATA DECLARATIONS (.ROM)
//=====================================================================================================================
CONST(EcuPowerM_LowlevelDrvFuncTbl_t,ECUPOWERM_CONST) EcuPowerM_LowLevelDrvFuncTable = {
	
	.DioReadChannel				=  &Dio_ReadChannel,  			
	.DioWriteChannel  			=  &Dio_WriteChannel,
	#if (ECUPOWERM_ANALOG_CHANNEL_READ_API == STD_ON)
	.AdcReadChannel  			=  &AnalogChannelRead,
	#else
	.AdcReadChannel  			=  NULL_PTR,
	#endif
	.IohwAbsReadChannel			=  &IoHwAb_GetSyncRawInput,
	.IohwAbsWriteChannel		=  &IoHwAb_SetOutputPin,
	.IohwAbsAdcReadChannel		=  &IoHwAb_Adc_GetAsyncRawAdc,
	.IohwAbsSetDuty				=  &IoHwAb_Pwm_SetDuty,
	.IohwAbsSetDutyAndPeriod	=  &IoHwAb_Pwm_SetDutyAndPeriod,
	.PwmSetDuty					=  &Pwm_SetDutyCycle,
	.PwmSetDutyAndPeriod		=  &Pwm_SetPeriodAndDuty,
};


	   
//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================


//=====================================================================================================================
//  UNINITIALIZED DATA DECLARATIONS(.BSS)
//=====================================================================================================================
#if (ECUPOWERM_ANALOG_CHANNEL_READ_API == STD_ON)
FUNC(void, ECUPOWERM_CODE) AnalogChannelRead(VAR(EcuPowerM_ChannelIdType, AUTOMATIC) channel,
												P2VAR(uint16, AUTOMATIC, ECUPOWERM_APPL_DATA)buffer)
{

	if(buffer != NULL_PTR)
	{
		(void)Adc_SetupResultBuffer(channel, buffer);
		Adc_StartGroupConversion(channel);
		Adc_ReadGroup(channel, buffer);
	}
}
#endif



/*==============================================================================================================================================
Date              	: 04-01-24
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/






