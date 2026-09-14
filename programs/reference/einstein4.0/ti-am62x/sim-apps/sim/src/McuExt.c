#include "Std_Types.h"
#include "I2c.h"
void McuExt(void)
{
}

void McuExt_TrustedPerformReset(void)
{
	while(1)
	{
	}
}

void Wdg_SetTriggerCondition_IM(unsigned short timeout)
{
}

void McuExt_PerformReset(void)
{
	while(1)
	{
	}
}

void McuExt_WdgSetTriggerCondition(unsigned short DeviceIndex,unsigned short u16Timeout)
{
   
    Wdg_SetTriggerCondition_IM(u16Timeout);
    
}

unsigned int vHsm_getHsmBootTime (void)
{
	return(0);
}

void CySldIpc_Isr_IpcDrv_Cat2(void){}

void vHsmIpc_Init(void){}

//void HMemDrv_MainFunction(void){}

void OsTask_SafeBsw_0_Wdgm_Checkpoint_10ms(void){}

void Cry_She_Init(void){}

void Icu_EnableOverflowNotification(void){}

void Icu_StartTimestamp(void){}


void Icu_SetActivationCondition(void){}

void Icu_StopTimestamp(void){}

void Icu_GetTimestampIndex(void){}	

void Icu_Isr_Vector_573_Cat2func(void){}

void Icu_Isr_Vector_574_Cat2func(void){}

void Icu_Isr_Vector_584_Cat2func(void){}

void ExtMemMgr_Init(void){}

void ExtMemMgr_MainFunction(void){}

void LighSensor_Init_Configure(void){}

Std_ReturnType I2c_AsyncTransmit(I2c_SequenceType Sequence){}

void LightSensor_StateMachine(void){}

Std_ReturnType I2c_SetupEB(I2c_ChannelType Channel, I2c_DataType* TxBufferPtr, I2c_DataType* RxBufferPtr, \
                  I2c_NumberOfDataType TxLength, I2c_NumberOfDataType RxLength, uint8 SlaveAddress)
				  {}


//void LightSensorInitDeInit_Cbk(void){}

I2c_SeqResultType I2c_GetSequenceResult(I2c_SequenceType Sequence){return(0);}

void ASK_RandInit(uint32 rand_seed){}

typedef enum{
    SEEDKEY_SUCCESS = 0,
    SEEDKEY_FAIL = 1
}SEEDKEY_RT ;
SEEDKEY_RT ASK_Rand8ByteGenerate(uint8 *seed_buffer_8byte){}

SEEDKEY_RT ASK_KeyGenerate(const uint8 *seed_buffer_8byte, uint8 *key_buffer_8byte){}