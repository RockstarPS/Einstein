/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Iocalibdiagcdd_cfg.c
**
** Description:    contains configurable functions to call RTE /API for each service
**                 
**
**===================================================================================================================*/

#ifndef IOCALIBDIAGCDD_CFG_C
#define IOCALIBDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Iocalibdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
//#undef  RTE_APPLICATION_HEADER_FILE//coverity fix CID : 1717444
//#include "Rte_MDL_Config.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define IOCALIBDIAG_CLR_0 					0
#define IOCALIBDIAG_DATA_BYTE_0 			0
#define IOCALIBDIAG_DATA_BYTE_1 			1
#define IOCALIBDIAG_DATA_BYTE_2 			2
#define IOCALIBDIAG_DATA_BYTE_3 			3
#define IOCALIBDIAG_DATA_BYTE_4 			4
#define IOCALIBDIAG_DATA_BYTE_5 			5
#define IOCALIBDIAG_DATA_BYTE_6 			6
#define IOCALIBDIAG_DATA_BYTE_7 			7
#define IOCALIBDIAG_DATA_BYTE_8 			8
#define IOCALIBDIAG_DATA_BYTE_9 			9
#define IOCALIBDIAG_DATA_BYTE_10 			10
#define IOCALIBDIAG_DATA_BYTE_11 			11
#define IOCALIBDIAG_FF_MASK_BYTE 			(0xFFU)
#define IOCALIBDIAG_SHIFT_DATA_8 			(8U)
#define DEFAULT_ZERO_DATA 					((uint8)0U)
#define MEET_RES_LEN_2 						((uint8)2)
#define MEET_RES_LEN_4 						((uint8)4)

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef LEFTSWTBACKLIGHTENABLE
static Std_ReturnType IOCalibDiag_LeftSwtBackLight_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_LeftSwtBackLight_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
static Std_ReturnType IOCalibDiag_RightSwtBackLight_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_RightSwtBackLight_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef TACHOSCALEILLUMNENABLE
static Std_ReturnType IOCalibDiag_TachoScaleIllumn_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_TachoScaleIllumn_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef TACHOPTRILLUMNENABLE
static Std_ReturnType IOCalibDiag_TachoPtrIllumn_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_TachoPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
static Std_ReturnType IOCalibDiag_FuelTempScaleIllumn_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_FuelTempScaleIllumn_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef FUELPTRILLUMNENABLE
static Std_ReturnType IOCalibDiag_FuelPtrIllumn_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_FuelPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef TEMPPTRILLUMNENABLE
static Std_ReturnType IOCalibDiag_TempPtrIllumn_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_TempPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
#ifdef ANALOGMEASCALIB3POINTFUELLVLENABLE
static Std_ReturnType IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Write(uint8 *Data,uint8 *ErrorCode);
void Meet_Merge_U8Array_To_U32Variable(const uint8 *InputBuffer, uint32 *pVar, const uint8 BufferSize);
void Meet_Separate_U16Variable_To_U8Array(const uint16 InputVariable, uint8 * OutputBuffer, const uint8 BufferSize);
void Meet_Separate_U32Variable_To_U8Array(const uint32 InputVariable, uint8 * OutputBuffer, const uint8 BufferSize);
#else //ANALOGMEASCALIB3POINTFUELLVLENABLE

static Std_ReturnType IOCalibDiag_AnalogMeasCalibFuelLevelInput_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_AnalogMeasCalibFuelLevelInput_Write(uint8 *Data,uint8 *ErrorCode);
#endif
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
static Std_ReturnType IOCalibDiag_AnalogMeasCalibOilLevelInput_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_AnalogMeasCalibOilLevelInput_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
static Std_ReturnType IOCalibDiag_Fuel_RAD_Data_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_Fuel_RAD_Data_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
static Std_ReturnType IOCalibDiag_Sound_Channel_Volume_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_Sound_Channel_Volume_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
static Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef IOCALIB_MODULE_ENABLE_JOBRESULT
static void IOCalibDiag_Nvm_JobResult_Read(uint8* JobStatus);
static void IOCalibDiag_Nvm_JobResult_Write(uint8 JobStatus);
#endif

#ifdef ANALOGREFERENCECALIBRATION
static Std_ReturnType IOCalibDiag_AnalogRefCalib_Read(uint8 *Data);
static Std_ReturnType IOCalibDiag_AnalogRefCalib_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
static Std_ReturnType IocalibdiagConfig_RtcCalibration_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType IocalibdiagConfig_RtcCalibration_RCTE(uint8 *ErrorCode);
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

#ifdef LEFTSWTBACKLIGHTENABLE
const IOCalibDiag_ReadWrite LeftSwtBackLightConfig = 
{
	&IOCalibDiag_LeftSwtBackLight_Read,&IOCalibDiag_LeftSwtBackLight_Write,
};
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
const IOCalibDiag_ReadWrite RightSwtBackLightConfig = 
{
	&IOCalibDiag_RightSwtBackLight_Read,&IOCalibDiag_RightSwtBackLight_Write,
};
#endif

#ifdef TACHOSCALEILLUMNENABLE
const IOCalibDiag_ReadWrite TachoScaleIllumnConfig = 
{
	&IOCalibDiag_TachoScaleIllumn_Read,&IOCalibDiag_TachoScaleIllumn_Write,
};
#endif

#ifdef TACHOPTRILLUMNENABLE
const IOCalibDiag_ReadWrite TachoPtrIllumnConfig = 
{
	&IOCalibDiag_TachoPtrIllumn_Read,&IOCalibDiag_TachoPtrIllumn_Write,
};
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
const IOCalibDiag_ReadWrite FuelTempScaleIllumnConfig = 
{
	&IOCalibDiag_FuelTempScaleIllumn_Read,&IOCalibDiag_FuelTempScaleIllumn_Write,
};
#endif

#ifdef FUELPTRILLUMNENABLE
const IOCalibDiag_ReadWrite FuelPtrIllumnConfig = 
{
	&IOCalibDiag_FuelPtrIllumn_Read,&IOCalibDiag_FuelPtrIllumn_Write,
};
#endif

#ifdef TEMPPTRILLUMNENABLE
const IOCalibDiag_ReadWrite TempPtrIllumnConfig = 
{
	&IOCalibDiag_TempPtrIllumn_Read,&IOCalibDiag_TempPtrIllumn_Write,
};
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
#ifdef ANALOGMEASCALIB3POINTFUELLVLENABLE
const IOCalibDiag_ReadWrite AnalogMeas3pointCalibFuelLevelInputConfig = 
{
	&IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Read,&IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Write,
};
#else //ANALOGMEASCALIB3POINTFUELLVLENABLE

const IOCalibDiag_ReadWrite AnalogMeasCalibFuelLevelInputConfig = 
{
	&IOCalibDiag_AnalogMeasCalibFuelLevelInput_Read,&IOCalibDiag_AnalogMeasCalibFuelLevelInput_Write,
};
#endif
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
const IOCalibDiag_ReadWrite AnalogMeasCalibOilLevelInputConfig = 
{
	&IOCalibDiag_AnalogMeasCalibOilLevelInput_Read,&IOCalibDiag_AnalogMeasCalibOilLevelInput_Write,
};
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
const IOCalibDiag_ReadWrite Fuel_Sender_Calib_Table=
{
	&IOCalibDiag_Fuel_RAD_Data_Read,&IOCalibDiag_Fuel_RAD_Data_Write,
};
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
const IOCalibDiag_ReadWrite SoundChannelVolumeConfig=
{
	&IOCalibDiag_Sound_Channel_Volume_Read,&IOCalibDiag_Sound_Channel_Volume_Write,
};
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
const IOCalibDiag_ReadWrite SoundMixerVolumeConfig=
{
	&IOCalibDiag_Sound_Mixer_Volume_Read,&IOCalibDiag_Sound_Mixer_Volume_Write,
};
#endif

#ifdef IOCALIB_MODULE_ENABLE_JOBRESULT
const IOCalibDiag_ReadWrite_U8 IOCalibNvmJobResult_U8=
{
	&IOCalibDiag_Nvm_JobResult_Read,&IOCalibDiag_Nvm_JobResult_Write,
};
#endif

#define TWO_SENDER_TYPE 0x01U
#define TWO_SENDER_TYPE_NVM	0x40U

#ifdef ANALOGREFERENCECALIBRATION
const IOCalibDiag_ReadWrite AnalogReferenceCalibConfig = 
{
	&IOCalibDiag_AnalogRefCalib_Read,&IOCalibDiag_AnalogRefCalib_Write,
};
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
const Iocalibdiag_RtcCalibrationConfigType Iocalibdiag_RtcCalibrationConfig = 
{
	&IocalibdiagConfig_RtcCalibration_STA, &IocalibdiagConfig_RtcCalibration_RCTE,
};

#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
uint8 Arg_Data[3];

#ifdef LEFTSWTBACKLIGHTENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_LeftSwtBackLight_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Left switch board backlight luminosity
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Read
**
** Inputs           :  Data[Out]:Left switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_LeftSwtBackLight_Read(uint8 *Data)
{
	uint16 buffer_16 = 0;

	Rte_Call_rp_CS_MemAbsGet_Get_NV_Zone0_MINLum_NVM(&buffer_16);
	Data[1] = (uint8)(buffer_16 & 0xFF);
	Data[0] = (uint8)(buffer_16 >> 8);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_Zone0_MAXLum_NVM(&buffer_16);
	Data[3] = (uint8)(buffer_16 & 0xFF);
	Data[2] = (uint8)(buffer_16 >> 8);

	return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_LeftSwtBackLight_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Left switch board backlight luminosity
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Write
**
** Inputs           :  Data[In]:Left switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_LeftSwtBackLight_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;
    uint16 buffer_16;
	
	buffer_16 = (uint16)((Data[0]<<8) | (Data[1]&0xFF));
	Ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_Zone0_MINLum_NVM(buffer_16);

	buffer_16 = (uint16)((Data[2]<<8) | (Data[3]&0xFF));
	Ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_Zone0_MAXLum_NVM(buffer_16);
	
	return Ret; 
}
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_RightSwtBackLight_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Right switch board backlight luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_RightSwitchBacklight_Read
**
** Inputs           :  Data[Out]:Right switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_RightSwtBackLight_Read(uint8 *Data)
{
    uint16 buffer_16 = 0;
	Rte_Call_rp_CS_MemAbsGet_Get_NV_Zone3_MINLum_NVM(&buffer_16);
	Data[1] = (uint8)(buffer_16 & 0xFF);
	Data[0] = (uint8)(buffer_16 >> 8);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_Zone3_MAXLum_NVM(&buffer_16);
	Data[3] = (uint8)(buffer_16 & 0xFF);
	Data[2] = (uint8)(buffer_16 >> 8);

	return E_OK; 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_RightSwtBackLight_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Right switch board backlight luminosity 
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_RightSwitchBacklight_Write
**
** Inputs           :  Data[In]:Right switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_RightSwtBackLight_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;
    uint16 buffer_16;
	
	buffer_16 = (uint16)((Data[0]<<8) | (Data[1]&0xFF));
	Ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_Zone3_MINLum_NVM(buffer_16);

	buffer_16 = (uint16)((Data[2]<<8) | (Data[3]&0xFF));
	Ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_Zone3_MAXLum_NVM(buffer_16);
	
	return Ret;
}
#endif

#ifdef TACHOSCALEILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TachoScaleIllumn_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read tacho scale luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TachoScale_Illumination_Read
**
** Inputs           :  Data[Out]:TachoScale Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TachoScaleIllumn_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TachoScaleIllumn_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write tacho scale luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TachoScale_Illumination_Write
**
** Inputs           :  Data[In]:TachoScale Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TachoScaleIllumn_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif


#ifdef TACHOPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TachoPtrIllumn_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Tacho pointer luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TachoPointer_Illumination_Read
**
** Inputs           :  Data[Out]:Tacho pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TachoPtrIllumn_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TachoPtrIllumn_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write Tacho pointer luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TachoPointer_Illumination_Write
**
** Inputs           :  Data[In]:Tacho pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TachoPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_FuelTempScaleIllumn_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read fuel or temperature scale luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_Fuel_TempScale_Illumination_Read
**
** Inputs           :  Data[Out]:Fuel or temperature scale Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_FuelTempScaleIllumn_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_FuelTempScaleIllumn_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write fuel or temperature scale luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_Fuel_TempScale_Illumination_Write
**
** Inputs           :  Data[In]:Fuel or temperature scale Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_FuelTempScaleIllumn_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif

#ifdef FUELPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_FuelPtrIllumn_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read fuel pointer luminosity
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_FuelPointer_Illumination_Read
**
** Inputs           :  Data[Out]:Fuel pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_FuelPtrIllumn_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_FuelPtrIllumn_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write fuel pointer luminosity
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_FuelPointer_Illumination_Write
**
** Inputs           :  Data[In]:Fuel pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_FuelPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif

#ifdef TEMPPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TempPtrIllumn_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read temperature pointer luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TempPointer_Illumination_Read
**
** Inputs           :  Data[Out]:Temperature pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TempPtrIllumn_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_TempPtrIllumn_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write temperature pointer luminosity (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_TempPointer_Illumination_Write
**
** Inputs           :  Data[In]:Temperature pointer Illumination Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_TempPtrIllumn_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
#ifdef ANALOGMEASCALIB3POINTFUELLVLENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Analog Measurement Fuel level input (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Read
**
** Inputs           :  Data[Out]:Analog Measurement (Fuel level input) Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Read(uint8 *Data)
{
    uint32 buffer_32 = 0;
	uint16 buffer_16 = 0;

    Rte_Call_rp_CS_MemAbsGet_Get_NV_AverageFuelADCPoint0(&buffer_32);
	Data[3] = (uint8)(buffer_32 & 0xFF);
	Data[2] = (uint8)((buffer_32 >> 8) & 0xFF);
	Data[1] = (uint8)((buffer_32 >> 16) & 0xFF);
	Data[0] = (uint8)((buffer_32 >> 24) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_RrealPoint0(&buffer_16);
	Data[5] = (uint8)(buffer_16 & 0xFF);
	Data[4] = (uint8)((buffer_16 >> 8) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_AverageFuelADCPoint1(&buffer_32);
	Data[9] = (uint8)(buffer_32 & 0xFF);
	Data[8] = (uint8)((buffer_32 >> 8) & 0xFF);
	Data[7] = (uint8)((buffer_32 >> 16) & 0xFF);
	Data[6] = (uint8)((buffer_32 >> 24) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_RrealPoint1(&buffer_16);
	Data[11] = (uint8)(buffer_16 & 0xFF);
	Data[10] = (uint8)((buffer_16 >> 8) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_AverageFuelADCPoint2(&buffer_32);
	Data[15] = (uint8)(buffer_32 & 0xFF);
	Data[14] = (uint8)((buffer_32 >> 8) & 0xFF);
	Data[13] = (uint8)((buffer_32 >> 16) & 0xFF);
	Data[12] = (uint8)((buffer_32 >> 24) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_RrealPoint2(&buffer_16);
	Data[17] = (uint8)(buffer_16 & 0xFF);
	Data[16] = (uint8)((buffer_16 >> 8) & 0xFF);
	
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Analog Measurement Fuel level input (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Write
**
** Inputs           :  Data[In]:Analog Measurement (Fuel level input) Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeas3pointCalibFuelLevelInput_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
    uint32 buffer_32 = 0;
	uint16 buffer_16 = 0;

	buffer_32 = (uint32) ((Data[0]<<24) | (Data[1]<<16) | (Data[2]<<8) | (Data[3]&0xFF));
    ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_AverageFuelADCPoint0(buffer_32);

	buffer_16 = (uint16) ((Data[4]<<8) | (Data[5]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_RrealPoint0(buffer_16);
			
	buffer_32 = (uint32) ((Data[6]<<24) | (Data[7]<<16) | (Data[8]<<8) | (Data[9]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_AverageFuelADCPoint1(buffer_32);

	buffer_16 = (uint16) ((Data[10]<<8) | (Data[11]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_RrealPoint1(buffer_16);

	buffer_32 = (uint32) (uint32) ((Data[12]<<24) | (Data[13]<<16) | (Data[14]<<8) | (Data[15]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_AverageFuelADCPoint2(buffer_32);

	buffer_16 = (uint16) ((Data[16]<<8) | (Data[17]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_RrealPoint2(buffer_16);
	
    return ret;
}
#else //ANALOGMEASCALIB3POINTFUELLVLENABLE

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeasCalibFuelLevelInput_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Analog Measurement Fuel level input (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Read
**
** Inputs           :  Data[Out]:Analog Measurement (Fuel level input) Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeasCalibFuelLevelInput_Read(uint8 *Data)
{
	Std_ReturnType Ret = E_NOT_OK;
	Std_ReturnType Ret2 = E_NOT_OK;
   	uint16 Buf_x = IOCALIBDIAG_CLR_0;
	uint16 Buf_y = IOCALIBDIAG_CLR_0;	
	
	
	Data[IOCALIBDIAG_DATA_BYTE_0] = DEFAULT_ZERO_DATA;//x0
	Data[IOCALIBDIAG_DATA_BYTE_1] = DEFAULT_ZERO_DATA;//x0
	Data[IOCALIBDIAG_DATA_BYTE_2] = DEFAULT_ZERO_DATA;//y0
	Data[IOCALIBDIAG_DATA_BYTE_3] = DEFAULT_ZERO_DATA;//y0
	Data[IOCALIBDIAG_DATA_BYTE_4] = DEFAULT_ZERO_DATA;//x1
	Data[IOCALIBDIAG_DATA_BYTE_5] = DEFAULT_ZERO_DATA;//x1
	Data[IOCALIBDIAG_DATA_BYTE_6] = DEFAULT_ZERO_DATA;//y1
	Data[IOCALIBDIAG_DATA_BYTE_7] = DEFAULT_ZERO_DATA;//y1
	//Ret = Rte_Call_rp_CS_MemAbsGet_Get_NV_XFuelValue(&Buf_x);
   //Ret2 = Rte_Call_rp_CS_MemAbsGet_Get_NV_YFuelValue(&Buf_y);
	
	//Ret = Rte_Call_rpNV_FuelGainOffset_Get_NV_FuelGainOffset(&Buf_x,&Buf_y);
	Data[IOCALIBDIAG_DATA_BYTE_9] = (uint8) (Buf_x & 0xFFU);
	Data[IOCALIBDIAG_DATA_BYTE_8] = (uint8) ((Buf_x >> IOCALIBDIAG_SHIFT_DATA_8) & 0xFFU);
	Data[IOCALIBDIAG_DATA_BYTE_11] = (uint8) (Buf_y & 0xFFU);
	Data[IOCALIBDIAG_DATA_BYTE_10] = (uint8) ((Buf_y >> IOCALIBDIAG_SHIFT_DATA_8) & 0xFFU);
	return (Ret & Ret2);
	
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeasCalibFuelLevelInput_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Analog Measurement Fuel level input (calibrated value)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Write
**
** Inputs           :  Data[In]:Analog Measurement (Fuel level input) Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeasCalibFuelLevelInput_Write(uint8 *Data,uint8 *ErrorCode)
{
   Std_ReturnType Ret_x = E_NOT_OK;
	Std_ReturnType Ret_y = E_NOT_OK;
	Std_ReturnType Ret = E_NOT_OK;
	uint64 Xf_Cor = IOCALIBDIAG_CLR_0;
	uint64 Xf_Cor1 = IOCALIBDIAG_CLR_0;
	uint64 Xf_Cor2 = IOCALIBDIAG_CLR_0;
	uint32 Yf_Cor = IOCALIBDIAG_CLR_0;
	uint64 Yf_Cor1 = IOCALIBDIAG_CLR_0;
	uint64 Yf_Cor2 = IOCALIBDIAG_CLR_0;
	sint32 Yf_Cor3 = IOCALIBDIAG_CLR_0;
	uint16 RCLUS20 = IOCALIBDIAG_CLR_0;
	uint16 RREAL20 = IOCALIBDIAG_CLR_0;
	uint16 RREAL290 = IOCALIBDIAG_CLR_0;
	uint16 RCLUS290 = IOCALIBDIAG_CLR_0;
	uint16 XFI = IOCALIBDIAG_CLR_0;
	uint16 YFI = IOCALIBDIAG_CLR_0;
	
	RCLUS20		= 	(( Data[IOCALIBDIAG_DATA_BYTE_0]  << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_1]  );
	RREAL20		=	(( Data[IOCALIBDIAG_DATA_BYTE_2]  << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_3]  );
	RCLUS290	=	(( Data[IOCALIBDIAG_DATA_BYTE_4]  << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_5]  );
	RREAL290	=	(( Data[IOCALIBDIAG_DATA_BYTE_6]  << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_7]  );
	XFI			=	(( Data[IOCALIBDIAG_DATA_BYTE_8]  << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_9]  );
	YFI			=	(( Data[IOCALIBDIAG_DATA_BYTE_10] << IOCALIBDIAG_SHIFT_DATA_8) | Data[IOCALIBDIAG_DATA_BYTE_11] );
	
	Xf_Cor = (128000 + XFI);
	Xf_Cor1= ((uint64)(RCLUS290 - RCLUS20));
	Xf_Cor2= ((uint64)(RREAL290 - RREAL20));
	Xf_Cor = ((Xf_Cor)*(Xf_Cor1));
	Xf_Cor = ((Xf_Cor)/(Xf_Cor2));
	Xf_Cor = (Xf_Cor - 128000);

	Yf_Cor = (YFI - 32512) ;
	Yf_Cor1= ((128000 + Xf_Cor) * (uint64)RREAL290 );
	Yf_Cor2= ( ( (128000 + XFI)*(uint64)RCLUS290));
	Yf_Cor3= ((Yf_Cor2 - Yf_Cor1));
	Yf_Cor3= Yf_Cor3 / 25600;
	Yf_Cor = Yf_Cor + Yf_Cor3 ;
	Yf_Cor = Yf_Cor + 32840;
		
   
	/*to be replaced with RTE*/
	//Ret_x = Rte_Call_rp_CS_MemAbsSet_Set_NV_XFuelValue((uint16)Xf_Cor);
    //Ret_y = Rte_Call_rp_CS_MemAbsSet_Set_NV_YFuelValue((uint16)Yf_Cor);
	//Ret = Rte_Call_rpNV_FuelGainOffset_Set_NV_FuelGainOffset((uint16)Xf_Cor,(uint16)Yf_Cor);
	
	if((Ret_x == E_NOT_OK) || (Ret_y == E_NOT_OK))
	{
		Ret = E_NOT_OK;
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;//Application needs to be replaced with required error code.
	}	
	else
	{
		Ret = E_OK;
	}
		
	
   return Ret;  
}

#endif
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeasCalibOilLevelInput_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Analog Measurement (Oil level input)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Read
**
** Inputs           :  Data[In]:Analog Measurement (Oil level input) Calibration value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeasCalibOilLevelInput_Read(uint8 *Data)
{
	uint32 buffer_32 = 0;
	uint16 buffer_16 = 0;

	Rte_Call_rp_CS_MemAbsGet_Get_NV_AverageOilADC5Ohms(&buffer_32);
	Data[3] = (uint8)(buffer_32 & 0xFF);
	Data[2] = (uint8)((buffer_32 >> 8) & 0xFF);
	Data[1] = (uint8)((buffer_32 >> 16) & 0xFF);
	Data[0] = (uint8)((buffer_32 >> 24) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_Voil_5Ohm(&buffer_16);
	Data[5] = (uint8)(buffer_16 & 0xFF);
	Data[4] = (uint8)((buffer_16 >> 8) & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_AverageOilADC18Ohms(&buffer_32);
	Data[9] = (uint8)(buffer_32 & 0xFF);
	Data[8] = (uint8)((buffer_32 >> 8) & 0xFF);
	Data[7] = (uint8)((buffer_32 >> 16) & 0xFF);
	Data[6] = (uint8)((buffer_32 >> 24)  & 0xFF);

	Rte_Call_rp_CS_MemAbsGet_Get_NV_Voil_18Ohm(&buffer_16);
	Data[11] = (uint8)(buffer_16 & 0xFF);
	Data[10] = (uint8)((buffer_16 >> 8) & 0xFF);

  	return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogMeasCalibOilLevelInput_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Analog Measurement (Oil level input)
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Write
**
** Inputs           :  Data[In]:Analog Measurement (Oil level input) Calibration value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogMeasCalibOilLevelInput_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint32 buffer_32 = 0;
	uint16 buffer_16 = 0;

	buffer_32 = (uint32) ((Data[0]<<24) | (Data[1]<<16) | (Data[2]<<8) | (Data[3]&0xFF));
    ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_AverageOilADC5Ohms(buffer_32);

	buffer_16 = (uint16) ((Data[4]<<8) | (Data[5]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_Voil_5Ohm(buffer_16);

	buffer_32 = (uint32) ((Data[6]<<24) | (Data[7]<<16) | (Data[8]<<8) | (Data[9]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_AverageOilADC18Ohms(buffer_32);

	buffer_16 = (uint16) ((Data[10]<<8) | (Data[11]&0xFF));
	ret |= Rte_Call_rp_CS_MemAbsSet_Set_NV_Voil_18Ohm(buffer_16);

    return ret;
}
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Fuel_RAD_Data_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Fuel Sender Calibration Table from NVM
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_FuelSender_Calibration_Table_Read
**
** Inputs           :  Data[In]:Fuel RAD Data
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Fuel_RAD_Data_Read(uint8 *Data)
{
   return E_OK; /*to be replaced with RTE*/ 
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Fuel_RAD_Data_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Fuel Sender Calibration Table to NVM
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_FuelSender_Calibration_Table_Write
**
** Inputs           :  Data[In]:Fuel RAD Data
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Fuel_RAD_Data_Write(uint8 *Data,uint8 *ErrorCode)
{
   return E_OK; /*to be replaced with RTE*/ 
}
#endif
#ifdef IOCALIBSOUNDCHANNELVOLUME
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Channel_Volume_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Sound Channel Volume Calibration Table from NVM
**                      
** Invocation       :  Iocalib.diagcdd, Function:IOCalibDiag_Sound_Channel_Volume_OutputRead
**
** Inputs           :  Data[In]:Sound Channel Volume
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Sound_Channel_Volume_Read(uint8 *Data)
{
	uint16 buffer_16 = 0;

	Rte_Call_rp_CS_MemAbsGet_Get_NV_SpeakerCalibrationGain(&buffer_16);
	Data[1] = (uint8)(buffer_16 & 0xFF);
	Data[0] = (uint8)(buffer_16 >> 8);

	return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Channel_Volume_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Sound Channel Volume Calibration Table to NVM
**                      
** Invocation       :  Iocalib.diagcdd, Function:IOCalibDiag_Sound_Channel_Volume_OutputWrite
**
** Inputs           :  Data[In]:Sound Channel Volume Data
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Sound_Channel_Volume_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;
    uint16 buffer_16;
	
	buffer_16 = (uint16)((Data[0]<<8) | (Data[1]&0xFF));
	Ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_SpeakerCalibrationGain(buffer_16);

	return Ret;
}
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Mixer_Volume_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Sound Mixer output volume
**                      
** Invocation       :  Iocalib.diagcdd, Function:IOCalibDiag_Sound_Mixer_Volume_OutputRead
**
** Inputs           :  Data[In]:Sound Mixer Volume Data
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_Read(uint8 *Data)
{
	Std_ReturnType Ret = E_NOT_OK;

	/*to be replaced with RTE*/
	//Ret = This is sample RTE call - Rte_Call_rpMfgModNvmReadWriteRequest_GetNV_Sound_Mixer_Op_Vol(Data);

	return Ret;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Mixer_Volume_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to Write Sound Mixer Output Volume
**                      
** Invocation       :  Iocalib.diagcdd, Function:IOCalibDiag_Sound_Mixer_Volume_OutputWrite
**
** Inputs           :  Data[In]:Sound Mixer Volume Data
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;

	/*to be replaced with RTE*/
	//Ret = This is sample RTE call - Rte_Call_rpMfgModNvmReadWriteRequest_SetNV_Sound_Mixer_Op_Vol(Data[0]);

	return Ret;
}
#endif
#ifdef IOCALIB_MODULE_ENABLE_JOBRESULT
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Nvm_JobResult_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read NVM job status
**                      
** Invocation       :  Iocalib.diagcdd
**
** Inputs           :  Data[Out]:NVM job status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void IOCalibDiag_Nvm_JobResult_Read(uint8* JobStatus)
{
	//(void)Rte_Read_rp_SR_JobStatus_JobStatus_NV_XFuelValue(JobStatus);
    //(void)Rte_Read_rp_SR_JobStatus_JobStatus_NV_YFuelValue(JobStatus);

}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Nvm_JobResult_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to write NVM job status
**                      
** Invocation       :  Iocalib.diagcdd
**
** Inputs           :  Data[In]:NVM job status
**
** Outputs          :  NA
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void IOCalibDiag_Nvm_JobResult_Write(uint8 JobStatus)
{
	
}
#endif
#ifdef ANALOGMEASCALIB3POINTFUELLVLENABLE
//=======================================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :
//
// DESIGN INFORMATION : Separates 4 bytes variable into single byte array
//=======================================================================================
void Meet_Separate_U32Variable_To_U8Array(const uint32 InputVariable, uint8 * OutputBuffer, const uint8 BufferSize)
{
	uint8 Meet_Cnt = 0;
	uint32 Meet_MaskVar = 0xFF000000;
	uint8 Meet_ShiftVar = 24U;

	for (Meet_Cnt = 0U; Meet_Cnt < BufferSize; Meet_Cnt++)
	{
		OutputBuffer[Meet_Cnt] =  ((uint8)((InputVariable & Meet_MaskVar) >> Meet_ShiftVar));

		Meet_MaskVar = (Meet_MaskVar >> 8U);

		Meet_ShiftVar -= 8U;
	}

}

//=======================================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :
//
// RETURN VALUE :
//
// DESIGN INFORMATION : Separates 2 bytes variable into single byte array
//=======================================================================================
void Meet_Separate_U16Variable_To_U8Array(const uint16 InputVariable, uint8 * OutputBuffer, const uint8 BufferSize)
{
	uint8 Meet_Cnt = 0;
	uint16 Meet_MaskVar = 0xFF00;
	uint8 Meet_ShiftVar = 8U;

	for (Meet_Cnt = 0U; Meet_Cnt < BufferSize; Meet_Cnt++)
	{
		OutputBuffer[Meet_Cnt] =  ((uint8)((InputVariable & Meet_MaskVar) >> Meet_ShiftVar));

		Meet_MaskVar = (Meet_MaskVar >> 8U);

		Meet_ShiftVar -= 8U;
	}

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
///
/// @arg
///
/// @return
///<br>
//---------------------------------------------------------------------------------------------------------------------
void Meet_Merge_U8Array_To_U32Variable(const uint8 *InputBuffer, uint32 *pVar, const uint8 BufferSize)
{
	uint32 tmp = *InputBuffer;
	uint8 Meet_Cnt;

	for (Meet_Cnt = 1U; Meet_Cnt < BufferSize; Meet_Cnt++)
	{
		tmp <<= 8U;
		tmp |=  InputBuffer[Meet_Cnt];
	}
	*pVar = tmp;
}
#endif //ANALOGMEASCALIB3POINTFUELLVLENABLE

#ifdef ANALOGREFERENCECALIBRATION
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogRefCalib_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read Analog Reference Calibration
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Read
**
** Inputs           :  Data[Out]:Analog Reference Calibration value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogRefCalib_Read(uint8 *Data)
{
	uint16 buffer_16 = 0;

	Rte_Call_rp_CS_MemAbsGet_Get_NV_ADC_ref_cal(&buffer_16);
	Data[1] = (uint8)(buffer_16 & 0xFF);
	Data[0] = (uint8)(buffer_16 >> 8);

	return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_AnalogRefCalib_Write
**
** Visibility       :  Private 
**
** Description      :  calls API to read Analog Reference Calibration
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Write
**
** Inputs           :  Data[In]:Analog Reference Calibration value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IOCalibDiag_AnalogRefCalib_Write(uint8 *Data,uint8 *ErrorCode)
{
	Std_ReturnType Ret = E_NOT_OK;
    uint16 buffer_16;
	
	buffer_16 = (uint16)((Data[0]<<8) | (Data[1]&0xFF));
	Ret = Rte_Call_rp_CS_MemAbsSet_Set_NV_ADC_ref_cal(buffer_16);
	
	return Ret; 
}
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
/*=====================================================================================================================
**
** Function Name    :  IocalibdiagConfig_RtcCalibration_STA
**
** Visibility       :  Private 
**
** Description      :  calls API to do STA for rtc calibration
**                      
** Invocation       :  Iocalib.diagcdd, Function: Iocalibdiag_RtcCalibration_STA
**
** Inputs           :  Data[IN]: Calibration parameter
**					   Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success/ E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IocalibdiagConfig_RtcCalibration_STA(uint8 *Data, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 reqCalibFreq = Data[0U];

	if(reqCalibFreq == 0x00U)		//Request for uncalibrated 512Hz frequency  
	{
		//ret = Rte_Call_rp_CS_TIRtcServices_RtcCdd_EnableCalibrationSignalOutput(RTC_CAL_512Hz);
	}
	else if(reqCalibFreq == 0x01U)	//Request for calibrated 1Hz frequency  
	{
		//ret = Rte_Call_rp_CS_TIRtcServices_RtcCdd_EnableCalibrationSignalOutput(RTC_CAL_1Hz);
	}
	else
	{
		*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}

	return ret;
}
/*=====================================================================================================================
**
** Function Name    :  IocalibdiagConfig_RtcCalibration_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls API to do RCTE for rtc calibration
**                      
** Invocation       :  Iocalib.diagcdd, Function: Iocalibdiag_RtcCalibration_RCTE
**
** Inputs           :  Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success/ E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
static Std_ReturnType IocalibdiagConfig_RtcCalibration_RCTE(uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;

	//ret = Rte_Call_rp_CS_TIRtcServices_RtcCdd_DisableCalibrationSignalOutput();

	return ret;
}
#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/Sept/2020
** CDSID             :  mprajapa
** Traceability      :  RTC-1777209
** Change Description:  ADC reference calibration service added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 9/Sept/2019 
** CDSID             : razhakes
** Traceability      : RTC 1368184
** Change Description: Backlight Pwm Read write bytes modified
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/07/2019
** CDSID             :  vsupraja
** Traceability      :  RTC  - 1348007
** Change Description:  Added Read and Write services for Sound Channel Volume and Sound Mixer Volume
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  15/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 
** Change Description:  Three point fuel calibration added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/11/2018
** CDSID             :  gdhilipr	
** Traceability      :  RTC 1227921   
** Change Description:  Added the Analog Measurement Reading - FD30
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/07/2018
** CDSID             :  gnataraj
** Traceability      :  RTC 1152542
** Change Description:  Added the Read and Write service for Fuel RAD (Fuel Sender Calibration Table) feature
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features 
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1122851
** Change Description:  Initial version - IOCalibDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif
