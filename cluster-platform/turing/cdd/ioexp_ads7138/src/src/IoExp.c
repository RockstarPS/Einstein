/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  IoExp.c                                              *
*  Module Short Name :  IoExp_ads7138                                        *
*  VOBName           :                                                       *
*  Author            : gthanapp                                              *
*  Description       : This file contains the ExtIO Request handling         *
*                       functionalities                                      *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef IOEXP_C
#define IOEXP_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "IoExp.h"
#include "I2c.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define IOEXP_BIT_VALUE_1                 0x01u
#define IOEXP_BIT_VALUE_4                 0x04u

#define IOEXP_PIN_CFG_ADDR                0x5u

#define IOEXP_GPIO_CFG_ADDR               0x7u

#define IOEXP_GPO_DRV_ADDR                0x9u

#define IOEXP_GEN_CFG_ADDR                0x1u
#define IOEXP_GEN_CFG_DATA                0x2u

#define IOEXP_SEQ_CFG_ADDR                0x10u
#define IOEXP_SEQ_CFG_DATA                0x11u

#define IOEXP_AUTO_CH_SEL_ADDR            0x12u

#define IOEXP_GPO_VALUE_ADDR              0xBu
#define IOEXP_GPI_VALUE_ADDR              0xDu

#define IOEXP_REGWRITE_OPCODE             0x8u
#define IOEXP_REGREAD_OPCODE              0x10u

#define IOEXP_REG_WRITE_TXLENGH           0x3u
#define IOEXP_REG_WRITE_RXLENGH           0u
#define IOEXP_ADC_READ_MAX_RXLENGTH       0x10u

#define IOEXP_REG_READ_TXLENGH            0x2u
#define IOEXP_REG_READ_RXLENGH            0x1u
#define IOEXP_INIT_TX_SIZE                12u

#define IOEXP_UNINIT                      0u
#define IOEXP_INIT_COMPLETED              0x1u
#define IOEXP_INIT_INPROGRESS             0x2u

#define IOEXP_8_BIT_MAX_VAL               255u
#define IOEXP_ADC_BYTES_COUNT             0x2u

#define IOEXP_NO_OF_FUNCTIONS             0x3u
#define IOEXP_MAX_HW_CHANNELS             0x8u

#define IOEXP_DIN                         0u
#define IOEXP_DOUT                        1u
#define IOEXP_AIN                         2u

#define IOEXP_VAL_0                       0u
#define IOEXP_VAL_1                       1u

#define IOEXP_SEQ_IDLE                    0u
#define IOEXP_SEQ_INPROGRESS              1u
#define IOEXP_SEQ_COMPLETED               2u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
	uint8 Default_DO_Val;//contains GPO Default Data 
	uint8 DO_DrvType;    //contains GPO_DRV_CFG Data
}IoExp_Init_DOutCfgType;

typedef struct
{
	uint8 Pin_Cfg;    //contains PIN_CFG Data for both analog and GPIO
	uint8 DOutPin_Cfg;     //contains GPIO_CFG Data
    uint8 DInPin_Cfg;
    uint8 AInPin_Cfg;
}IoExp_Init_GPIOCfgType;

typedef struct 
{
    boolean DigitalInput;
    boolean DigitalOutput;
    boolean AnalogInput;
}IoExp_PinconfigStatusType;

typedef struct
{
    uint8 IoExp_Initstruct[IOEXP_INIT_TX_SIZE];
    uint8 IoExp_InitTxBufferSize;
}IoExp_InitBufferCfgType;

typedef struct
{
    uint8 DIn_Mask;
    uint8 DOut_Mask;
    uint8 AIn_Mask;
}IoExp_MaskType;

typedef struct
{
    uint8 DIn_ResultBuffer[IOEXP_NUM_OF_DI_PINS_CFG_COUNT];
    uint8 DOut_ResultBuffer[IOEXP_NUM_OF_DO_PINS_CFG_COUNT];
    uint16 AIn_ResultBuffer[IOEXP_NUM_OF_AI_PINS_CFG_COUNT];
}IoExp_ResultBufferType;

typedef struct
{
    boolean Last_DInResultStatus;
    boolean Last_DOutResultStatus;
    boolean Last_AInResultStatus;
}IoExp_ResultStatusType;

typedef struct
{
    uint8 AIn_RxBufferSize;
}IoExp_AInBuffeSizeType;

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static IoExp_ResultBufferType IoExp_ResultBuffer;
static IoExp_ResultStatusType IoExp_ResultStatus[IOEXP_NUM_OF_DEVICES] = {0u};
static IoExp_InitBufferCfgType IoExp_InitBuffer[IOEXP_NUM_OF_DEVICES] = {0u};
static IoExp_Init_DOutCfgType IoExp_Init_DOutConfig[IOEXP_NUM_OF_DEVICES] = {0u};
static IoExp_Init_GPIOCfgType IoExp_Init_GPIOConfig[IOEXP_NUM_OF_DEVICES] = {0u};

static IoExp_MaskType IoExp_Mask[IOEXP_NUM_OF_DEVICES] = {0u};

static uint8 IoExp_ADCDataBuffer[IOEXP_ADC_READ_MAX_RXLENGTH] = {0u};                   // for storing the lsb, msb adc results
static uint8 IoExp_Din_TxBuffer[IOEXP_REG_WRITE_TXLENGH] = {0u};
static uint8 IoExp_Dout_TxBuffer[IOEXP_REG_WRITE_TXLENGH] = {0u};
static uint8 IoExp_Ain_TxBuffer[IOEXP_REG_WRITE_TXLENGH] = {0u};
static uint8 IoExp_InitTxBuff[IOEXP_REG_WRITE_TXLENGH] = {0u};
static uint8 IoExp_ADC_ChCount[IOEXP_NUM_OF_DEVICES] = {0u};

static uint8 IoExp_InitStatus = IOEXP_UNINIT;
static uint8 IoExp_InitDeviceIndex = 0u;

static uint8 IoExp_DIRegisterData = 0u;                // for storing the DI data 
static uint8 IoExp_DORegisterData = 0u;                // for storing the DO data
static uint8 IoExp_GlobalCount = 0u;
static uint8 IoExp_LastProcessState = 0xFFu;
static uint8 IoExp_InitArrIndex = 0u;

static uint8 IoExp_SeqStatus = IOEXP_SEQ_IDLE;
/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

static Std_ReturnType IoExp_InternalGetAdcResult(void);
static Std_ReturnType IoExp_InternalWriteChannel(void);
static Std_ReturnType IoExp_InternalReadChannel(void);
static Std_ReturnType IoExp_I2CASyncTransmit(uint8 deviceAddress, uint8* TxBufferPtr, uint8* RxBufferPtr,\
                                            uint8 TxLength, uint8 RxLength);
static void IoExp_InitRegisterUpdate(void);
static void IoExp_ResultUpdate(uint8 RequestType);

static uint8 IoExp_DeviceIDCheck(IoExp_PinType PinType, uint8 ChannelID);
static uint8 IoExp_ChCount(uint8 channel_Mask);

static IoExp_ChannelType IoExp_ChannelIDCheck(IoExp_PinType PinType, uint8 Hw_ID);

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/


/**************************************************************************
Function name   : IoExp_ReadChannel
Arguments       : ChannelId - ID of the channel , 
                : DioResult -DI Result Buffer
Return type     : IoExp_LevelType
Description     : This function is used to Read the Pin Level of the DI channel
**************************************************************************/
IoExp_LevelType IoExp_ReadChannel(IoExp_ChannelType ChannelId)
{
    Std_ReturnType flChLevel = 0;
    uint8 DeviceIndex = 0u;
    if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
    {
        if(IOEXP_NUM_OF_DI_PINS > ChannelId)
        {
            DeviceIndex = IoExp_DeviceIDCheck(DIGITAL_INPUT, (uint8)ChannelId);

            if(E_OK == IoExp_ResultStatus[DeviceIndex].Last_DInResultStatus)
            {
                /* copying the result from internal buffer to Argument input buffer */
                flChLevel = IoExp_ResultBuffer.DIn_ResultBuffer[ChannelId];
            }
        }
        else
        {
            #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
                IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DIREAD_ID,IOEXP_E_CHANNELID);
            #endif
        }
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DIREAD_ID,IOEXP_E_UNINIT);
        #endif
    }
    return flChLevel;
}

/**************************************************************************
Function name   : IoExp_WriteChannel
Arguments       : ChannelId - ID of the channel 
                : Level - Value to be written
Return type     : Std_ReturnType
Description     : This function is used to Write the Pin Level of the DO Pins
**************************************************************************/
Std_ReturnType IoExp_WriteChannel(IoExp_ChannelType ChannelId,IoExp_LevelType Level)
{
    Std_ReturnType return_Val = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
    {
        if(IOEXP_NUM_OF_DO_PINS > ChannelId)
        {
            DeviceIndex = IoExp_DeviceIDCheck(DIGITAL_OUTPUT, (uint8)ChannelId);

            if(E_OK == IoExp_ResultStatus[DeviceIndex].Last_DOutResultStatus)
            {
                IoExp_ResultBuffer.DOut_ResultBuffer[ChannelId] = Level;
                return_Val = E_OK;
            }
            else
            {
                return_Val = E_NOT_OK;
            }
        }
        else
        {
            #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
                IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DOWRITE_ID,IOEXP_E_CHANNELID);
            #endif
            return_Val = E_NOT_OK;
        }
    }
    else
    {
        // #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
        //     IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DOWRITE_ID,IOEXP_E_UNINIT);
        // #endif
        return_Val = E_NOT_OK;
    }
    return return_Val;
}
            

/**************************************************************************
Function name   : IoExp_AnalogRead
Arguments       : ChannelId - ID of the channel 
                : AnalogDataBuffer - Buffer in which Analog data need to be stored
Return type     : Std_ReturnType - E_OK, E_NOT_OK
Description     : This function is used to Read the ADC value of AI Pin
**************************************************************************/
Std_ReturnType IoExp_GetAdcResult(IoExp_ChannelType ChannelId,IoExp_AdcValueType* AnalogDataBuffer)
{
    Std_ReturnType return_Val = E_NOT_OK;
    uint8 DeviceIndex = 0u;

    if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
    {
        if(IOEXP_NUM_OF_AI_PINS > ChannelId)
        {
            DeviceIndex = IoExp_DeviceIDCheck(ANALOG_INPUT, (uint8)ChannelId);

            if(E_OK == IoExp_ResultStatus[DeviceIndex].Last_AInResultStatus)
            {
                *AnalogDataBuffer = IoExp_ResultBuffer.AIn_ResultBuffer[ChannelId];   /* Updating the Input Argument Buffer using AIn Result Buffer value */
                return_Val = E_OK;   
            }
            else
            {
                return_Val = E_NOT_OK;
            }           
        }
        else
        {
           #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
                IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_AINREAD_ID,IOEXP_E_CHANNELID);
           #endif
           return_Val = E_NOT_OK;
        }
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_AINREAD_ID,IOEXP_E_UNINIT);
        #endif
        return_Val = E_NOT_OK;
    }
    return return_Val;
}

/**************************************************************************
Function name   : IoExp_GetAdcGroupResult
Arguments       : 
    Group             -  Specifies the ADC group to read the results from.
    AnalogDataBuffer  -  Pointer to the buffer where ADC results will be stored.
Return type     : Std_ReturnType - Returns E_OK if successful, otherwise E_NOT_OK.
Description     : This function retrieves the ADC conversion results of the specified
                  ADC group and stores them in the provided buffer. 
**************************************************************************/
Std_ReturnType IoExp_GetAdcGroupResult(uint8 Group,IoExp_AdcValueType* AnalogDataBuffer)
{
    Std_ReturnType retVal = E_NOT_OK;
    if((Group == IOEXP_ADC_CONF_GROUP_ID) && (AnalogDataBuffer != NULL))
    {
        MemLib_MemCpy(AnalogDataBuffer, IoExp_ResultBuffer.AIn_ResultBuffer, 
               sizeof(IoExp_ResultBuffer.AIn_ResultBuffer));
        retVal = E_OK;
    }
    return retVal;
}
/**************************************************************************
Function name   : IoExp_MainFunction
Arguments       : None
Return type     : None
Description     : This function should be called periodically for every 10ms
**************************************************************************/
void IoExp_MainFunction(void)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if(IOEXP_UNINIT == IoExp_InitStatus)
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
        IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_MAINFUNC_ID,IOEXP_E_UNINIT);
        #endif
    }
    else if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
    {
        if(IOEXP_SEQ_INPROGRESS != IoExp_SeqStatus)
        {
            IoExp_SeqStatus = IOEXP_SEQ_INPROGRESS;

            if((IOEXP_8_BIT_MAX_VAL & (IoExp_Mask[0].DIn_Mask)) != 0U)
            {
                RetVal = IoExp_InternalReadChannel();
                if(E_OK == RetVal)
                {
                    IoExp_LastProcessState = IOEXP_DIN;
                    IoExp_GlobalCount = IOEXP_DIN;
                }
                else
                {
                    IoExp_ResultStatus[0].Last_DInResultStatus = E_NOT_OK;
                }
            }
            
            else if((IOEXP_8_BIT_MAX_VAL & (IoExp_Mask[0].DOut_Mask)) !=0U)
            {
                RetVal = IoExp_InternalWriteChannel();
                if(E_OK == RetVal)
                {
                    IoExp_LastProcessState = IOEXP_DOUT;
                    IoExp_GlobalCount = IOEXP_DOUT;
                }
                else
                {
                    IoExp_ResultStatus[0].Last_DOutResultStatus = E_NOT_OK;
                }
            }

            else /* if DIN or DOUT not configured, then consider all as AIN */
            {
                RetVal = IoExp_InternalGetAdcResult(); /* Initiating the AInReadChannel Function with 0th channel */
                if(E_OK == RetVal)
                {
                    IoExp_LastProcessState = IOEXP_AIN;
                    IoExp_GlobalCount = IOEXP_AIN;
                }
                else
                {
                    IoExp_ResultStatus[0].Last_AInResultStatus = E_NOT_OK;
                }
            }
        }
    }
    else
    {
        /* Do Nothing*/
    }
}

/**************************************************************************
Function name   : IoExp_I2cEndNotification
Arguments       : sequence - I2c Sequence
                : busstate - Current Bus state of I2c Sequence
                : sequencestate - Current sequence state of the I2c Sequence I2C_SEQ_OK,I2C_SEQ_BUSY,I2C_SEQ_QUEUED,
                :                                                            I2C_SEQ_FAILED,I2C_SEQ_CANCELLED
Return type     : Void
Description     : This is the callback function of I2c Sequence
**************************************************************************/

void IoExp_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
    
    Std_ReturnType I2C_RetVal = E_NOT_OK;
    (void)busstate;
    uint8 index = 0;
    
    if(I2C_SEQ_OK == sequencestate)
    {
        if(IOEXP_INIT_INPROGRESS == IoExp_InitStatus)
        {
            if(IoExp_InitArrIndex >= (IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_InitTxBufferSize - IOEXP_VAL_1))
            {
                IoExp_InitDeviceIndex++;
                IoExp_InitArrIndex = 0;
            }
            if(IOEXP_NUM_OF_DEVICES > IoExp_InitDeviceIndex)
            {
                IoExp_InitTxBuff[0]=IOEXP_REGWRITE_OPCODE;
                if(IoExp_InitArrIndex != 0u)
                {
                    IoExp_InitArrIndex++;
                    IoExp_InitTxBuff[1]=IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_Initstruct[IoExp_InitArrIndex];
                }
                else
                {
                    IoExp_InitTxBuff[1]=IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_Initstruct[IoExp_InitArrIndex];
                }
                IoExp_InitArrIndex++;
                IoExp_InitTxBuff[2]=IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_Initstruct[IoExp_InitArrIndex];
                I2C_RetVal = IoExp_I2CASyncTransmit(IOEXP_I2C_DeviceAddress[IoExp_InitDeviceIndex], IoExp_InitTxBuff, NULL,\
                                            IOEXP_REG_WRITE_TXLENGH, IOEXP_REG_WRITE_RXLENGH);
                if(E_NOT_OK == I2C_RetVal)
                {
                    #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
                        IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_CALLBACK_ID,IOEXP_E_I2C_TRANSFER);
                    #endif
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                IoExp_InitStatus = IOEXP_INIT_COMPLETED; /* If all the devices were configured and I2C sequence is ok, Then Init is completed */
            }
        }
        else if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
        {
            IoExp_ResultUpdate(IoExp_LastProcessState);

            if(IoExp_SeqStatus == IOEXP_SEQ_INPROGRESS)
            {
                IoExp_GlobalCount++;
                for(index = (IoExp_GlobalCount / IOEXP_NO_OF_FUNCTIONS);index < IOEXP_NUM_OF_DEVICES; index++)
                {
                    if(IOEXP_DIN == (IoExp_GlobalCount % IOEXP_NO_OF_FUNCTIONS))
                    {
                        if(IOEXP_NUM_OF_DEVICES > (IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS))
                        {
                            if((IOEXP_8_BIT_MAX_VAL & (IoExp_Mask[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].DIn_Mask)) != 0U)
                            {
                                I2C_RetVal = IoExp_InternalReadChannel();
                                if(E_OK == I2C_RetVal)
                                {
                                    IoExp_LastProcessState = IOEXP_DIN;
                                }
                                else
                                {
                                    IoExp_ResultStatus[(IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS].Last_DInResultStatus = E_NOT_OK;
                                }
                                break;
                            }
                            else
                            {
                                IoExp_GlobalCount++;
                            }
                        }
                        else
                        {
                            /*Do Nothing*/
                        }
                    }
                    if(IOEXP_DOUT == (IoExp_GlobalCount % IOEXP_NO_OF_FUNCTIONS))
                    {
                        if(IOEXP_NUM_OF_DEVICES > (IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS))
                        {
                            if((IOEXP_8_BIT_MAX_VAL & (IoExp_Mask[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].DOut_Mask)) !=0U)
                            {
                                I2C_RetVal = IoExp_InternalWriteChannel();
                                if(E_OK == I2C_RetVal)
                                {
                                    IoExp_LastProcessState = IOEXP_DOUT;
                                }
                                else
                                {
                                    IoExp_ResultStatus[(IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS].Last_DOutResultStatus = E_NOT_OK;
                                }
                                break;
                            }
                            else
                            {
                                IoExp_GlobalCount++;
                            }
                        }
                        else
                        {
                            /*Do Nothing*/
                        }
                    }
                    if(IOEXP_AIN == (IoExp_GlobalCount % IOEXP_NO_OF_FUNCTIONS))
                    {
                        if(IOEXP_NUM_OF_DEVICES > (IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS))
                        {
                            if((IOEXP_8_BIT_MAX_VAL & (IoExp_Mask[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].AIn_Mask)) != 0U)
                            {
                                I2C_RetVal = IoExp_InternalGetAdcResult();
                                
                                if(E_OK == I2C_RetVal)
                                {
                                    IoExp_LastProcessState = IOEXP_AIN;
                                }
                                else
                                {
                                    IoExp_ResultStatus[(IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS].Last_AInResultStatus = E_NOT_OK;
                                }
                                break;
                            }
                            else
                            {
                                IoExp_GlobalCount++;
                            }
                        }
                        else
                        {
                            /* Do Nothing */
                        }
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
                if((IOEXP_NUM_OF_DEVICES * IOEXP_NO_OF_FUNCTIONS) <= IoExp_GlobalCount) /* If the global count reaches the maximum limit */
                {
                    IoExp_GlobalCount = 0u;
                    IoExp_SeqStatus = IOEXP_SEQ_COMPLETED;
                }
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* If I2c call back got failed, then result buffer of the failed callback process should be updated as E_NOT_OK*/
    else
    {
        I2c_Cancel(sequence);

        if((IOEXP_INIT_COMPLETED == IoExp_InitStatus) && (IOEXP_VAL_0 != IoExp_GlobalCount))
        {
            if(IOEXP_DIN == IoExp_LastProcessState)
            {
                IoExp_ResultStatus[(IoExp_GlobalCount-IOEXP_VAL_1)/IOEXP_NO_OF_FUNCTIONS].Last_DInResultStatus = E_NOT_OK;
            }
            else if(IOEXP_DOUT == IoExp_LastProcessState)
            {
                IoExp_ResultStatus[(IoExp_GlobalCount-IOEXP_VAL_1)/IOEXP_NO_OF_FUNCTIONS].Last_DOutResultStatus = E_NOT_OK;
            }
            else if(IOEXP_AIN == IoExp_LastProcessState)
            {
                IoExp_ResultStatus[(IoExp_GlobalCount-IOEXP_VAL_1)/IOEXP_NO_OF_FUNCTIONS].Last_AInResultStatus = E_NOT_OK;
            }
            else
            {
                /* Do Nothing */
            }
        }

        IoExp_GlobalCount = 0u;
        IoExp_SeqStatus = IOEXP_SEQ_IDLE;

        if(IOEXP_INIT_INPROGRESS == IoExp_InitStatus)
        {
            IoExp_Init(); /* Try again init */
        }

       #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_CALLBACK_ID,IOEXP_E_I2C_TRANSFER);
        #endif
    }
}

/**************************************************************************
Function name   : IoExp_Init()
Arguments       : None
Return type     : None
Description     : This function is used to Initialise the General config Registers
**************************************************************************/
void IoExp_Init(void)
{
    Std_ReturnType I2C_RetVal = E_NOT_OK;
    IoExp_InitStatus = IOEXP_INIT_INPROGRESS;
    uint8 index;

    for(index = 0u; index < IOEXP_NUM_OF_DEVICES; index++)
    {
        IoExp_ResultStatus[index].Last_AInResultStatus = 0u;
        IoExp_ResultStatus[index].Last_DInResultStatus = 0u;
        IoExp_ResultStatus[index].Last_DOutResultStatus = 0u;

        IoExp_Init_DOutConfig[index].Default_DO_Val = 0u;
        IoExp_Init_DOutConfig[index].DO_DrvType = 0u;

        IoExp_Init_GPIOConfig[index].AInPin_Cfg = 0u;
        IoExp_Init_GPIOConfig[index].DInPin_Cfg = 0u;
        IoExp_Init_GPIOConfig[index].DOutPin_Cfg = 0u;
        IoExp_Init_GPIOConfig[index].Pin_Cfg = 0u;

        IoExp_Mask[index].AIn_Mask = 0u;
        IoExp_Mask[index].DIn_Mask = 0u;
        IoExp_Mask[index].DOut_Mask = 0u;

        IoExp_ADC_ChCount[index] = 0u;
    }

    IoExp_InitRegisterUpdate();

    IoExp_InitTxBuff[0]=IOEXP_REGWRITE_OPCODE;
    IoExp_InitTxBuff[1]= IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_Initstruct[IoExp_InitArrIndex];
    IoExp_InitArrIndex++;
    IoExp_InitTxBuff[2]= IoExp_InitBuffer[IoExp_InitDeviceIndex].IoExp_Initstruct[IoExp_InitArrIndex];

    I2C_RetVal = IoExp_I2CASyncTransmit(IOEXP_I2C_DeviceAddress[IoExp_InitDeviceIndex], IoExp_InitTxBuff, NULL,\
                                            IOEXP_REG_WRITE_TXLENGH, IOEXP_REG_WRITE_RXLENGH);
    if(E_NOT_OK == I2C_RetVal)
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_INIT_ID,IOEXP_E_I2C_TRANSFER);
        #endif
    }
}

/**************************************************************************
Function name   : IoExp_DeInit()
Arguments       : None
Return type     : None
Description     : This function is used to DeInitialise the General config Registers
**************************************************************************/
void IoExp_DeInit(void)
{
    if(IOEXP_INIT_COMPLETED == IoExp_InitStatus)
    {
        IoExp_InitStatus = IOEXP_UNINIT;
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DEINIT_ID,IOEXP_E_UNINIT);
        #endif
    }
}

/**************************************************************************
Function name   : IoExp_InternalReadChannel
Arguments       : None
Return type     : void
Description     : This function is used to trigger the DigitalRead operation inside MainFunction 
**************************************************************************/
static Std_ReturnType IoExp_InternalReadChannel(void)
{
    Std_ReturnType I2c_result = E_NOT_OK;
    uint8 DeviceIndex = 0u;
    uint8 IoExp_DeviceAddress = 0u;

    DeviceIndex = IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS;
    IoExp_DeviceAddress = IOEXP_I2C_DeviceAddress[DeviceIndex]; //Getting device address using Channel ID
    IoExp_Din_TxBuffer[0] = IOEXP_REGREAD_OPCODE;
    IoExp_Din_TxBuffer[1] = IOEXP_GPI_VALUE_ADDR;
    
    I2c_result = IoExp_I2CASyncTransmit(IoExp_DeviceAddress,IoExp_Din_TxBuffer,&IoExp_DIRegisterData,IOEXP_REG_READ_TXLENGH,IOEXP_REG_READ_RXLENGH);
    if(E_OK == I2c_result)
    {
        /* Do Nothing */
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_AINREAD_ID,IOEXP_E_I2C_TRANSFER);
        #endif
    }
return I2c_result;
}

/**************************************************************************
Function name   : IoExp_InternalWriteChannel
Arguments       : None
Return type     : Std_ReturnType
Description     : This function is used to trigger the DigitalWrite operation inside MainFunction
**************************************************************************/
static Std_ReturnType IoExp_InternalWriteChannel(void)
{
    Std_ReturnType I2c_result = E_NOT_OK;
    uint8 IoExp_DeviceAddress = 0u;
    uint8 DeviceIndex = 0u;
    uint8 ArrIndex = 0u;

    DeviceIndex = IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS;
    for(ArrIndex = 0u; ArrIndex < IOEXP_NUM_OF_DO_PINS; ArrIndex++)
    {
        if(DeviceIndex == IoExp_DOutConfig[ArrIndex].DeviceIndex)
        {
            if(STD_HIGH == IoExp_ResultBuffer.DOut_ResultBuffer[IoExp_DOutConfig[ArrIndex].SW_ChannelID])
            {
                IoExp_DORegisterData |= (IOEXP_BIT_VALUE_1 << IoExp_DOutConfig[ArrIndex].HW_ChannelID);
            }
            else
            {
                IoExp_DORegisterData &= ~(IOEXP_BIT_VALUE_1 << IoExp_DOutConfig[ArrIndex].HW_ChannelID);
            }
        }
    }
    IoExp_DeviceAddress = IOEXP_I2C_DeviceAddress[DeviceIndex];
    IoExp_Dout_TxBuffer[0] = IOEXP_REGWRITE_OPCODE;
    IoExp_Dout_TxBuffer[1] = IOEXP_GPO_VALUE_ADDR;
    IoExp_Dout_TxBuffer[2] = IoExp_DORegisterData;

    I2c_result = IoExp_I2CASyncTransmit(IoExp_DeviceAddress,IoExp_Dout_TxBuffer,NULL,IOEXP_REG_WRITE_TXLENGH,IOEXP_REG_WRITE_RXLENGH);
    if(E_OK == I2c_result)
    {
        /* Do Nothing */
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_DOWRITE_ID,IOEXP_E_I2C_TRANSFER);
        #endif
    }
    return I2c_result;
}

/**************************************************************************
Function name   : IoExp_InternalGetAdcResult
Arguments       : None
Return type     : void
Description     : This function is used to trigger the ADCRead operation inside MainFunction 
**************************************************************************/
static Std_ReturnType IoExp_InternalGetAdcResult(void)
{
    Std_ReturnType I2c_result = E_OK;
    uint8 IoExp_DeviceAddress = 0u;
    uint8 DeviceIndex = 0u;
    uint8 IoExp_RxbufferLength = 0u;

    DeviceIndex = IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS;

    IoExp_DeviceAddress = IOEXP_I2C_DeviceAddress[DeviceIndex];
    IoExp_RxbufferLength = IoExp_ADC_ChCount[DeviceIndex] * IOEXP_ADC_BYTES_COUNT;

    IoExp_Ain_TxBuffer[0] = IOEXP_REGWRITE_OPCODE;
    IoExp_Ain_TxBuffer[1] = IOEXP_SEQ_CFG_ADDR;
    IoExp_Ain_TxBuffer[2] = IOEXP_SEQ_CFG_DATA;

    I2c_result = IoExp_I2CASyncTransmit(IoExp_DeviceAddress,IoExp_Ain_TxBuffer,IoExp_ADCDataBuffer,\
                                                        IOEXP_REG_WRITE_TXLENGH,IoExp_RxbufferLength);
return I2c_result;
}
/**************************************************************************
Function name   : IoExp_InitRegisterUpdate
Arguments       : None
Return type     : Void
Description     : This function is used to update the Register values from Configurations for ExpIo Initialisation
**************************************************************************/
static void IoExp_InitRegisterUpdate(void)
{
    uint32 IoExp_ChannelID = 0u;
    uint8 DeviceIndex = 0u;
    uint8 HWIndex = 0u;
    uint8 IoExp_PinIndex = 0u;
    uint8 IoExp_ArrayIndex = 0u;

    if(IOEXP_NUM_OF_DI_PINS > 0u)
    {
        for(IoExp_PinIndex = 0u; IoExp_PinIndex < IOEXP_NUM_OF_DI_PINS; IoExp_PinIndex++)
        {
            IoExp_Init_GPIOConfig[IoExp_DInConfig[IoExp_PinIndex].DeviceIndex].DInPin_Cfg |= (IOEXP_BIT_VALUE_1 << IoExp_DInConfig[IoExp_PinIndex].HW_ChannelID);
            IoExp_Mask[IoExp_DInConfig[IoExp_PinIndex].DeviceIndex].DIn_Mask = IoExp_Init_GPIOConfig[IoExp_DInConfig[IoExp_PinIndex].DeviceIndex].DInPin_Cfg;
        }
    }

    if(IOEXP_NUM_OF_AI_PINS > 0u)
    {
        for(IoExp_PinIndex = 0u; IoExp_PinIndex < IOEXP_NUM_OF_AI_PINS; IoExp_PinIndex++)
        {
            IoExp_Init_GPIOConfig[IoExp_AInConfig[IoExp_PinIndex].DeviceIndex].AInPin_Cfg |= (IOEXP_BIT_VALUE_1 << IoExp_AInConfig[IoExp_PinIndex].HW_ChannelID);
            IoExp_Mask[IoExp_AInConfig[IoExp_PinIndex].DeviceIndex].AIn_Mask = IoExp_Init_GPIOConfig[IoExp_AInConfig[IoExp_PinIndex].DeviceIndex].AInPin_Cfg;
        }
    }

    if(IOEXP_NUM_OF_DO_PINS > 0u)
    {
        for(IoExp_PinIndex = 0u; IoExp_PinIndex < IOEXP_NUM_OF_DO_PINS; IoExp_PinIndex++)
        {
            IoExp_Init_GPIOConfig[IoExp_DOutConfig[IoExp_PinIndex].DeviceIndex].DOutPin_Cfg |= (IOEXP_BIT_VALUE_1 << IoExp_DOutConfig[IoExp_PinIndex].HW_ChannelID);
            IoExp_Mask[IoExp_DOutConfig[IoExp_PinIndex].DeviceIndex].DOut_Mask = IoExp_Init_GPIOConfig[IoExp_DOutConfig[IoExp_PinIndex].DeviceIndex].DOutPin_Cfg;

            if(PUSH_PULL == IoExp_DOutConfig[IoExp_PinIndex].DriveType) // used to update GPO_DRV_CFG reg from the configured GPO pins
            {
                IoExp_Init_DOutConfig[IoExp_DOutConfig[IoExp_PinIndex].DeviceIndex].DO_DrvType |= (IOEXP_BIT_VALUE_1 << IoExp_DOutConfig[IoExp_PinIndex].HW_ChannelID);
            }

            if(STD_HIGH == IoExp_DOutConfig[IoExp_PinIndex].DefaultPinState) //used to initiate the configured GPO pin with default pin state
            {
                IoExp_Init_DOutConfig[IoExp_DOutConfig[IoExp_PinIndex].DeviceIndex].Default_DO_Val |= (IOEXP_BIT_VALUE_1 << IoExp_DOutConfig[IoExp_PinIndex].HW_ChannelID);
            }
        }
    }

    for(DeviceIndex = 0u; DeviceIndex < IOEXP_NUM_OF_DEVICES; DeviceIndex++)
    {
        IoExp_Init_GPIOConfig[DeviceIndex].Pin_Cfg = IoExp_Init_GPIOConfig[DeviceIndex].DInPin_Cfg | IoExp_Init_GPIOConfig[DeviceIndex].DOutPin_Cfg;
    }

    for(DeviceIndex = 0u; DeviceIndex < IOEXP_NUM_OF_DEVICES; DeviceIndex++)
    {
        for(HWIndex = 0u; HWIndex < IOEXP_MAX_HW_CHANNELS; HWIndex++)  /* To update the values from Default DOut Val to DOut Result Buffer */
        {
            if((IoExp_Mask[DeviceIndex].DOut_Mask & (IOEXP_VAL_1 << HWIndex)) != 0U)
            {
                IoExp_ChannelID = IoExp_ChannelIDCheck(DIGITAL_OUTPUT, HWIndex);

                if((IoExp_Init_DOutConfig[DeviceIndex].Default_DO_Val & (IOEXP_VAL_1 << HWIndex)) != 0U)
                {
                    IoExp_ResultBuffer.DOut_ResultBuffer[IoExp_ChannelID] = STD_HIGH;
                }
                else
                {
                    IoExp_ResultBuffer.DOut_ResultBuffer[IoExp_ChannelID] = STD_LOW;
                }       
            }
        }
    }

    for(DeviceIndex = 0u; DeviceIndex < IOEXP_NUM_OF_DEVICES; DeviceIndex++) /* To update the configured ADC channel count per device */
    {
        IoExp_ADC_ChCount[DeviceIndex] = IoExp_ChCount(IoExp_Mask[DeviceIndex].AIn_Mask);
    }
    
/* Sequencing the calculated values in the Init Tx Array */

    for(DeviceIndex = 0u; DeviceIndex < IOEXP_NUM_OF_DEVICES; DeviceIndex++)
    {
        IoExp_ArrayIndex = 0u;
        IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_PIN_CFG_ADDR;
        IoExp_ArrayIndex++;
        IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IoExp_Init_GPIOConfig[DeviceIndex].Pin_Cfg;  /* PIN_CFG reg Used to configure all the pins */
        IoExp_InitBuffer[DeviceIndex].IoExp_InitTxBufferSize = 2u;                                                      /* Minimum Tx Buffer range */

        /* checking the Analog Input Availablity from AIn Mask to check if Adc calibration is need to be set or not */
        if((IOEXP_8_BIT_MAX_VAL & IoExp_Mask[DeviceIndex].AIn_Mask) != 0U) /* If any pin is configured as Analog Input, then PIN_CFG value will be less than 255 */
        {
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_GEN_CFG_ADDR; 
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_GEN_CFG_DATA; /* Used to set ADC Offset Calibration */
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_AUTO_CH_SEL_ADDR; /* Used to configure ADC channels that need to be autosequenced during ADC read */
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IoExp_Mask[DeviceIndex].AIn_Mask;
            IoExp_InitBuffer[DeviceIndex].IoExp_InitTxBufferSize += 4u;
        }
        /* checking the GPIO Availablity from DIn and DOut Mask to check if GPIO_CFG is needed or not */
        if((IOEXP_8_BIT_MAX_VAL & IoExp_Mask[DeviceIndex].DIn_Mask) || (IOEXP_8_BIT_MAX_VAL & IoExp_Mask[DeviceIndex].DOut_Mask))
        {
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_GPIO_CFG_ADDR;
            /* To set pin as DI, GPIO_CFG should be updated with 0. Since IoExp_InitBuffer, default values are 0, Apart from DOutPin_Cfg set bits, all the bits will be in 0. */
            /* Remaining bits apart from DOutPin_Cfg, all the pins are considered as DI in Default */
            IoExp_ArrayIndex++;
            IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IoExp_Init_GPIOConfig[DeviceIndex].DOutPin_Cfg; 
            IoExp_InitBuffer[DeviceIndex].IoExp_InitTxBufferSize += 2u;
            
            /* checking the Digital Output Availablity from GPIO_CFG reg to check if GPO_DRV and Initstate is need to be set or not */
            if((IOEXP_8_BIT_MAX_VAL & IoExp_Mask[DeviceIndex].DOut_Mask) != 0U)
            {
                IoExp_ArrayIndex++;
                IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_GPO_DRV_ADDR;
                IoExp_ArrayIndex++;
                IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IoExp_Init_DOutConfig[DeviceIndex].DO_DrvType;   /* Used to update the Drive type of DO pins */
                IoExp_ArrayIndex++;
                IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IOEXP_GPO_VALUE_ADDR;
                IoExp_ArrayIndex++;
                IoExp_InitBuffer[DeviceIndex].IoExp_Initstruct[IoExp_ArrayIndex]=IoExp_Init_DOutConfig[DeviceIndex].Default_DO_Val; /* Used to provide configured PinLevel to DO Pins */
                IoExp_InitBuffer[DeviceIndex].IoExp_InitTxBufferSize += 4u;
            }
        }
    }
}

/**************************************************************************
Function name   : IoExp_I2CASyncTransmit
Arguments       : deviceAddress - Slave Device Address
                : OpCode - Opcode of the required I2C Action
                : RegisterAddress - Address of the register which need to be Read/Write
                : RegisterData - Data which need to be written in the Register
                : RxBufferPtr - Buffer in which RX data need to be stored
                : TxLength - Length of the Data to be transferred in bytes
                : RxLength - Length of the Data to be Received in bytes
                : I2c_SequenceID - Sequence ID of I2c Channel
Return type     : Std_ReturnType - E_OK, E_NOT_OK
Description     : This function is used to configure I2C channel for data transfer 
**************************************************************************/
static Std_ReturnType IoExp_I2CASyncTransmit(uint8 deviceAddress, uint8* TxBufferPtr, uint8* RxBufferPtr,\
                                            uint8 TxLength, uint8 RxLength)
{
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = I2c_SetupEB(IOEXP_I2C_CHANNELID, TxBufferPtr, RxBufferPtr, TxLength, RxLength, deviceAddress);  /* Same Channel ID for all the Data transfer */
    
    if(E_OK == RetVal)
    {
        RetVal = I2c_AsyncTransmit(IOEXP_I2CSEQUENCE);    /* Same Sequence ID for all the Data transfer */
        if(E_NOT_OK == RetVal)
        {
            #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
                IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_ASYNCTRANSMIT_ID,IOEXP_E_I2C_TRANSFER);
            #endif
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        #if (IOEXP_DEV_ERROR_DETECT == STD_ON)
            IoExp_Det_ReportError(IOEXP_MODULE_ID,IOEXP_INSTANCE_ID,IOEXP_SETUPEB_ID,IOEXP_E_I2C_TRANSFER);
        #endif
    }

    return RetVal;
}
/**************************************************************************
Function name   : IoExp_DeviceIDCheck
Arguments       : PinType - DIGITAL_INPUT/DIGITAL_OUTPUT/ANALOG_INPUT
                : ChannelID - Sw channelID
Return type     : uint8 - Device index of the Sw Channel
Description     : This function is used to Calculate the Corresponding Device Index ID if the SW CH Id is provided
**************************************************************************/
static uint8 IoExp_DeviceIDCheck(IoExp_PinType PinType, uint8 ChannelID)
{
    uint8 ArrIndex = 0u;
    uint8 retval = 0;

    switch(PinType)
    {
        case DIGITAL_INPUT:
            if(IOEXP_NUM_OF_DI_PINS > 0u)
            {
                for(ArrIndex= 0u; ArrIndex < IOEXP_NUM_OF_DI_PINS; ArrIndex++)
                {
                    if(IoExp_DInConfig[ArrIndex].SW_ChannelID == ChannelID)
                    {
                        retval = IoExp_DInConfig[ArrIndex].DeviceIndex;
                    }
                }
            }
        break;
        
        case DIGITAL_OUTPUT:
            if(IOEXP_NUM_OF_DO_PINS > 0u)
            {
                for(ArrIndex= 0u; ArrIndex < IOEXP_NUM_OF_DO_PINS; ArrIndex++)
                {
                    if(IoExp_DOutConfig[ArrIndex].SW_ChannelID == ChannelID)
                    {
                        retval = IoExp_DOutConfig[ArrIndex].DeviceIndex;
                    }
                }
            }
        break;
        
        case ANALOG_INPUT:
            if(IOEXP_NUM_OF_AI_PINS > 0u)
            {
                for(ArrIndex= 0u; ArrIndex < IOEXP_NUM_OF_AI_PINS; ArrIndex++)
                {
                    if(IoExp_AInConfig[ArrIndex].SW_ChannelID == ChannelID)
                    {
                        retval = IoExp_AInConfig[ArrIndex].DeviceIndex;
                    }
                }
            }
        break;
        
        default:
            /* Do Nothing */
        break;
    }
	return retval;
}
/**************************************************************************
Function name   : IoExp_ChannelIDCheck
Arguments       : PinType - DIGITAL_INPUT/DIGITAL_OUTPUT/ANALOG_INPUT
                : Hw_ID - HW pin Bit position
Return type     : uint8 - Configured Channel ID for that HW Pin
Description     : This function is used to Calculate the Corresponding Channel ID if the Hw Pin is provided
**************************************************************************/

static IoExp_ChannelType IoExp_ChannelIDCheck(IoExp_PinType PinType, uint8 Hw_ID)
{

    IoExp_ChannelType channelId = 0u;
    uint32 retval = 0;

    switch(PinType)
    {
        case DIGITAL_INPUT:
            if(IOEXP_NUM_OF_DI_PINS > 0u)
            {
                for(channelId= 0u; channelId < IOEXP_NUM_OF_DI_PINS; channelId++)
                {
                    if(IoExp_DInConfig[channelId].HW_ChannelID == Hw_ID)
                    {
                        if(((IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS) == IoExp_DInConfig[channelId].DeviceIndex)
                        {
                            retval = channelId;
                        }
                    }
                }
            }
        break;
        
        case DIGITAL_OUTPUT:
            if(IOEXP_NUM_OF_DO_PINS > 0u)
            {
                for(channelId= 0u; channelId < IOEXP_NUM_OF_DO_PINS; channelId++)
                {
                    if(IoExp_DOutConfig[channelId].HW_ChannelID == Hw_ID)
                    {
                        if(((IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS) == IoExp_DOutConfig[channelId].DeviceIndex)
                        {
                            retval = channelId;
                        }
                    }
                }
            }
        break;
        
        case ANALOG_INPUT:
            if(IOEXP_NUM_OF_AI_PINS > 0u)
            {
                for(channelId= 0u; channelId < IOEXP_NUM_OF_AI_PINS; channelId++)
                {
                    if(IoExp_AInConfig[channelId].HW_ChannelID == Hw_ID)
                    {
                        if(((IoExp_GlobalCount)/IOEXP_NO_OF_FUNCTIONS) == IoExp_AInConfig[channelId].DeviceIndex)
                        {
                            retval = channelId;
                        }
                    }
                }
            }
        break;
        
        default:
            /* Do Nothing */
        break;
    }
	return retval;
}

/**************************************************************************
Function name   : IoExp_ResultUpdate
Arguments       : RequestType - DIGITAL_INPUT/DIGITAL_OUTPUT/ANALOG_INPUT
Return type     : void
Description     : This function is used to update the latest result of DI/DO/AI 
                                    if the particular callback was I2C_E_OK
**************************************************************************/

static void IoExp_ResultUpdate(uint8 RequestType)
{
    uint8 HwUnitIndex = 0u;
    uint32 ChannelIndex = 0u;
    uint8 Adc_Index = 0u;

    switch(RequestType)
    {
        #if (IOEXP_NUM_OF_DI_PINS > 0u)
        case IOEXP_DIN:

            for (HwUnitIndex = 0u; HwUnitIndex < IOEXP_MAX_HW_CHANNELS; HwUnitIndex++)
            {
                if ((IoExp_Mask[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].DIn_Mask & (IOEXP_BIT_VALUE_1 << HwUnitIndex)) != 0U) /* From the mask, checking which HWChannels were set*/
                {
                    ChannelIndex = IoExp_ChannelIDCheck(DIGITAL_INPUT, HwUnitIndex); /* If the individual HW index is found in particular device, then check its corresponding SW ChannelID */
                    if(FALSE != ((IoExp_DIRegisterData) & (IOEXP_BIT_VALUE_1 << IoExp_DInConfig[ChannelIndex].HW_ChannelID))) /* Checking if the bit is set using Resultbuffer and HW Channel ID */
                    {
                        IoExp_ResultBuffer.DIn_ResultBuffer[IoExp_DInConfig[ChannelIndex].SW_ChannelID] = STD_HIGH; /* Storing DIN Value wrt deviceIndex and ChannelID*/
                    }
                    else
                    {
                        IoExp_ResultBuffer.DIn_ResultBuffer[IoExp_DInConfig[ChannelIndex].SW_ChannelID] = STD_LOW;  /* Storing DIN Value wrt deviceIndex and ChannelID*/
                    }
                }
            }
            IoExp_ResultStatus[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].Last_DInResultStatus = E_OK;
            break;
        #endif

        #if (IOEXP_NUM_OF_AI_PINS > 0u)
        case IOEXP_AIN:

            for (HwUnitIndex = 0u; HwUnitIndex < IOEXP_MAX_HW_CHANNELS; HwUnitIndex++)
            {
                if ((IoExp_Mask[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].AIn_Mask & (IOEXP_BIT_VALUE_1 << HwUnitIndex)) != 0U) /* From the mask, checking which HWChannels were set*/
                {
                    ChannelIndex = IoExp_ChannelIDCheck(ANALOG_INPUT, HwUnitIndex); /* If the individual HW index is found in particular device, then check its corresponding SW ChannelID */
                    IoExp_ResultBuffer.AIn_ResultBuffer[ChannelIndex] = (uint16)((IoExp_ADCDataBuffer[Adc_Index] << IOEXP_BIT_VALUE_4) | IoExp_ADCDataBuffer[Adc_Index+1u]);
                    Adc_Index =Adc_Index + 2u; /* to increment array index by two, once adc input is stored for 1 channel */
                }
            }
            IoExp_ResultStatus[IoExp_GlobalCount/IOEXP_NO_OF_FUNCTIONS].Last_AInResultStatus = E_OK;
            break;
        #endif
        
        default:
            /* Do Nothing */
        break;
    }

    if((IOEXP_NUM_OF_DEVICES * IOEXP_NO_OF_FUNCTIONS) <= IoExp_GlobalCount) /* If the global count reaches the maximum limit */
    {
        IoExp_GlobalCount = 0u;
        IoExp_SeqStatus = IOEXP_SEQ_COMPLETED;
    }
}

/**************************************************************************
Function name   : IoExp_ChCount
Arguments       : Channel Count
Return type     : uint8 - No of channel in a device
Description     : This function is used to calculate no of Ain/Din/Dout channels
                                                present in a particular device
**************************************************************************/
static uint8 IoExp_ChCount(uint8 channel_Mask)
{
    uint8 ch_count = 0u;
    uint8 temp_mask = channel_Mask;
    while (temp_mask != 0U) {
        ch_count += temp_mask & IOEXP_BIT_VALUE_1;
        temp_mask >>= IOEXP_BIT_VALUE_1;
    }

    return ch_count;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_SetupResultBuffer
**
** Visibility       :   Public
**
** Description      :   This function used in Setting up the result buffer for ADC
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**                      uint16* DataResultBufferPtr - Pointer to ADC Result Buffer
**
** Outputs          :  E_OK: ADC Result buffer is setup successfully.
**                     E_NOT_OK: ADC Result buffer is not setup successfully.
**
** Critical Section :  Yes
**
**==========================================================================*/

Std_ReturnType IoExp_Adc_SetupResultBuffer(IoExp_ChannelType ChannelId, uint16* DataResultBufferPtr)
{
    Std_ReturnType fl_Ret_val = E_OK;
    (void)DataResultBufferPtr;
    (void)ChannelId;
    return fl_Ret_val;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_StartGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in start the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/

void IoExp_Adc_StartGroupConversion(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_StopGroupConversion
**
** Visibility       :   Public
**
** Description      :   This function used in stop the ADC conversion
**
** Invocation       :   Application
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  Yes
**
**==========================================================================*/

void IoExp_Adc_StopGroupConversion(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_GetGroupStatus
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          : E_OK
**                    E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/

Std_ReturnType IoExp_Adc_GetGroupStatus(IoExp_ChannelType ChannelId)
{
    Std_ReturnType fl_Ret_val = E_OK;
    (void)ChannelId;
    return fl_Ret_val;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_EnableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
**
** Invocation       :  
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :  
**
**==========================================================================*/


void IoExp_Adc_EnableHardwareTrigger(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_DisableHardwareTrigger
**
** Visibility       :   Public
**
** Description      :  
**
** Invocation       :  
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :  
**
**==========================================================================*/

void IoExp_Adc_DisableHardwareTrigger(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_EnableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This enables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/

void IoExp_Adc_EnableGroupNotification(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

/*============================================================================
**
** Function Name    :   IoExp_Adc_DisableGroupNotification
**
** Visibility       :   Public
**
** Description      :  This disables the ADC group notification
**
** Invocation       :  Public
**
** Inputs           :   IoExp_ChannelType ChannelId - ADC Group
**
** Outputs          :  None
**
** Critical Section :  No
**
**==========================================================================*/

void IoExp_Adc_DisableGroupNotification(IoExp_ChannelType ChannelId)
{
    (void)ChannelId;
}

#endif /* IOEXP_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 08-03-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Release                                       */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 04-06-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: MainFunction Scheduling Defect Fix                    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-07-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      : DICVA-14780                                           */
/*Change Description: ADC Auto-Sequence Mode Integration                    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 12-12-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: IoExp changes to support IoHwAb Adc                   */
/*--------------------------------------------------------------------------*/

