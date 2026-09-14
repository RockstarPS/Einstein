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
** Name:           Ioctrlrd_dio_diagcdd
**
** Description:    contains IO Calibration related services.checks if software in Manufacturing mode before executing service request
**
**
**===================================================================================================================*/

#ifndef IOCALIBDIAGCDD_C
#define IOCALIBDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Iocalibdiagcdd.h"
#include "Iocalibdiagcdd_cfg.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef IOCALIBSERVICESENABLE
static boolean NVMWrtReq = FALSE;
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef LEFTSWTBACKLIGHTENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_LeftSwitchBacklight_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Left switch board backlight luminosity
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA51
**
** Inputs           :  Data[In]:Left switch board backlight luminosity Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_LeftSwitchBacklight_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = LeftSwtBackLightConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_LeftSwitchBacklight_Read
**
** Visibility       :  Public
**
** Description      :  Reads Left switch board backlight luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA51
**
** Inputs           :  Data[Out]:Left switch board backlight Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_LeftSwitchBacklight_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = LeftSwtBackLightConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef RIGHTSWTBACKLIGHTENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_RightSwitchBacklight_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Right switch board backlight luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA52
**
** Inputs           :  Data[In]:Right switch board backlight luminosity Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_RightSwitchBacklight_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = RightSwtBackLightConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_RightSwitchBacklight_Read
**
** Visibility       :  Public
**
** Description      :  Reads Right switch board backlight luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA52
**
** Inputs           :  Data[Out]:Right switch board backlight Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_RightSwitchBacklight_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = RightSwtBackLightConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef TACHOSCALEILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TachoScale_Illumination_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Tacho scale luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA53
**
** Inputs           :  Data[In]:Tacho scale Illumination Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TachoScale_Illumination_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = TachoScaleIllumnConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TachoScale_Illumination_Read
**
** Visibility       :  Public
**
** Description      :  Reads tacho scale luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA53
**
** Inputs           :  Data[Out]:TachoScale Illumination Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TachoScale_Illumination_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = TachoScaleIllumnConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef TACHOPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TachoPointer_Illumination_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Tacho Pointer luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA55
**
** Inputs           :  Data[In]:Tacho Pointer luminosity Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TachoPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = TachoPtrIllumnConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TachoPointer_Illumination_Read
**
** Visibility       :  Public
**
** Description      :  Reads Tacho pointer luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA55
**
** Inputs           :  Data[Out]:Tacho pointer Illumination Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TachoPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = TachoPtrIllumnConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef FUELTEMPSCALEILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelorTempScale_Illumination_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of fuel or temperature scale luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA54
**
** Inputs           :  Data[In]:Fuel or temperature scale Illumination Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_Fuel_TempScale_Illumination_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = FuelTempScaleIllumnConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelorTempScale_Illumination_Read
**
** Visibility       :  Public
**
** Description      :  Reads fuel or temperature scale luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA54
**
** Inputs           :  Data[Out]:Fuel or temperature scale Illumination Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_Fuel_TempScale_Illumination_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = FuelTempScaleIllumnConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef FUELPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelPointer_Illumination_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of fuel pointer luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA57
**
** Inputs           :  Data[In]:Fuel pointer Illumination Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_FuelPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = FuelPtrIllumnConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelPointer_Illumination_Read
**
** Visibility       :  Public
**
** Description      :  Reads fuel pointer luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA57
**
** Inputs           :  Data[Out]:Fuel pointer Illumination Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_FuelPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = FuelPtrIllumnConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef TEMPPTRILLUMNENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TempPointer_Illumination_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of temperature pointer luminosity
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA56
**
** Inputs           :  Data[In]:temperature pointer Illumination Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TempPointer_Illumination_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = TempPtrIllumnConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_TempPointer_Illumination_Read
**
** Visibility       :  Public
**
** Description      :  Reads temperature pointer luminosity (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA56
**
** Inputs           :  Data[Out]:Temperature pointer Illumination Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_TempPointer_Illumination_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = TempPtrIllumnConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef ANALOGMEASCALIBFUELLVLENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Analog Measurement (Fuel level input)
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA30
**
** Inputs           :  Data[In]:Analog Measurement (Fuel level input) Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				#ifndef ANALOGMEASCALIB3POINTFUELLVLENABLE
				ret = AnalogMeasCalibFuelLevelInputConfig.IOCalibDiag_Write(Data, ErrorCode);
				#else
				ret = AnalogMeas3pointCalibFuelLevelInputConfig.IOCalibDiag_Write(Data, ErrorCode);
				#endif
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
				else
				{
					ret = E_NOT_OK;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Read
**
** Visibility       :  Public
**
** Description      :  Reads Analog Measurement Fuel level input (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA30
**
** Inputs           :  Data[Out]:Analog Measurement (Fuel level input) Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_FuelLevelInput_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		#ifndef ANALOGMEASCALIB3POINTFUELLVLENABLE
		ret = AnalogMeasCalibFuelLevelInputConfig.IOCalibDiag_Read(Data);
		#else
		ret = AnalogMeas3pointCalibFuelLevelInputConfig.IOCalibDiag_Read(Data);
		#endif
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef IOCALIBSOUNDCHANNELVOLUME
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Channel_Volume_OutputWrite
**
** Visibility       :  Public
**
** Description      :  Write the Sound Channel Volume
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FD04
**
** Inputs           :  Data[In]:Sound Channel Volume
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType IOCalibDiag_Sound_Channel_Volume_OutputWrite(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = SoundChannelVolumeConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
				else
				{
					ret = E_NOT_OK;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Channel_Volume_OutputRead
**
** Visibility       :  Public
**
** Description      :  Reads Sound Channel Volume
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FD04
**
** Inputs           :  Data[Out]:Sound Channel Volume
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType IOCalibDiag_Sound_Channel_Volume_OutputRead(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = SoundChannelVolumeConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef IOCALIBSOUNDMIXEROUTPUTVOLUME
/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Mixer_Volume_OutputWrite
**
** Visibility       :  Public
**
** Description      :  Writes the Sound Mixer Volume
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FD09
**
** Inputs           :  Data[In]:Sound Mixer Volume
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_OutputWrite(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = SoundMixerVolumeConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
				else
				{
					ret = E_NOT_OK;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}

/*=====================================================================================================================
**
** Function Name    :  IOCalibDiag_Sound_Mixer_Volume_OutputRead
**
** Visibility       :  Public
**
** Description      :  Reads Sound Mixer Volume
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FD09
**
** Inputs           :  Data[Out]:Sound Mixer Volume
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType IOCalibDiag_Sound_Mixer_Volume_OutputRead(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = SoundMixerVolumeConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef ANALOGMEASCALIBOILLVLENABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of Analog Measurement (Oil level input)
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA31
**
** Inputs           :  Data[In]:Analog Measurement (Oil level input) Calibration value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = AnalogMeasCalibOilLevelInputConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Read
**
** Visibility       :  Public
**
** Description      :  Reads Analog Measurement Oil level input (calibrated value)
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA31
**
** Inputs           :  Data[Out]:Analog Measurement (Oil level input) Calibrated value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogMeasurementCalib_OilLevelInput_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = AnalogMeasCalibOilLevelInputConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef FUEL_SENDER_CALIBRATION_TABLE
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelSender_Calibration_Table_Write
**
** Visibility       :  Public
**
** Description      :  the service to store the Fuel RAD data to the Fuel Sender Calibration table
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA06
**
** Inputs           :  Data[In]:Fuel RAD Data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_FuelSender_Calibration_Table_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = Fuel_Sender_Calib_Table.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_FuelSender_Calibration_Table_Read
**
** Visibility       :  Public
**
** Description      :  the service to read the Fuel RAD data from the NVM -Fuel Sender Calibration table
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA06
**
** Inputs           :  Data[Out]:Fuel RAD Data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_FuelSender_Calibration_Table_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = Fuel_Sender_Calib_Table.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef ANALOGREFERENCECALIBRATION
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogReferenceCalib_Write
**
** Visibility       :  Public
**
** Description      :  Calibration of analog reference
**
** Invocation       :  MeetMgr.diagcdd , Function:Write_Diag_FA51
**
** Inputs           :  Data[In]:Analog Refference Calib value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogReferenceCalib_Write(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;
	uint8 nvmStatus;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		IOCalibNvmJobResult_U8.IOCalibDiag_Read(&nvmStatus);
		if (FALSE == NVMWrtReq)
		{
			if (nvmStatus != NVM_REQ_PENDING)
			{
				ret = AnalogReferenceCalibConfig.IOCalibDiag_Write(Data, ErrorCode);
				if (ret == (uint8)E_OK)
				{
					NVMWrtReq = TRUE;
					ret = DCM_E_PENDING;
				}
			}
		}
		else
		{
			if (nvmStatus == NVM_REQ_PENDING)
			{
				ret = DCM_E_PENDING;
			}
			else
			{
				ret = E_NOT_OK;
				if (nvmStatus == NVM_REQ_OK)
				{
					ret = E_OK;
				}
				NVMWrtReq = FALSE;
				nvmStatus = 0;
				/*clear NVM Jobresult*/
				IOCalibNvmJobResult_U8.IOCalibDiag_Write(nvmStatus);
			}
		}
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Iocalibdiag_AnalogReferenceCalib_Read
**
** Visibility       :  Public
**
** Description      :  Reads Analog reference Calibration
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA51
**
** Inputs           :  Data[Out]:Analog Refference Calib value
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_AnalogReferenceCalib_Read(uint8 *Data, uint8 *ErrorCode)
{
	uint8 MfgModeActive = 0U;
	Std_ReturnType ret = E_NOT_OK;

	MGRDIAG_GET_SESSION(&MfgModeActive);
	if (MfgModeActive == MEET_SESSION)
	{
		ret = AnalogReferenceCalibConfig.IOCalibDiag_Read(Data);
	}
	else
	{
		/*invalid mode*/
		*ErrorCode = INVALID_MODE;
	}
	return (ret);
}
#endif

#ifdef IOCALIBDIAG_RTC_CALIBRATION
/*=====================================================================================================================
** Function Name    :  Iocalibdiag_RtcCalibration_STA
**
** Visibility       :  Public
**
** Description      :  RTC calibration STA
**
** Invocation       :  MeetMgr.diagcdd

** Inputs           :  Data[IN]: Calibration parameter
**					   Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success/ E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_RtcCalibration_STA(uint8 *Data, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 MfgModeActive = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);

	if (MfgModeActive == MEET_SESSION)
	{
		ret = Iocalibdiag_RtcCalibrationConfig.RtcCalibration_STA(Data, ErrorCode);
	}
	else
	{
		/*Invalid Mode*/
		*ErrorCode = INVALID_MODE;
	}

	return ret;
}

/*=====================================================================================================================
** Function Name    :  Iocalibdiag_RtcCalibration_RCTE
**
** Visibility       :  Public
**
** Description      :  RTC calibration RCTE
**
** Invocation       :  MeetMgr.diagcdd

** Inputs           :  Errorcode: To be updated with error code if any
**
** Outputs          :  E_OK : Success/ E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Iocalibdiag_RtcCalibration_RCTE(uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 MfgModeActive = 0U;

	MGRDIAG_GET_SESSION(&MfgModeActive);

	if (MfgModeActive == MEET_SESSION)
	{
		ret = Iocalibdiag_RtcCalibrationConfig.RtcCalibration_RCTE(ErrorCode);
	}
	else
	{
		/*Invalid Mode*/
		*ErrorCode = INVALID_MODE;
	}

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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/Jan/2023
** CDSID             :  ddanecha
** Traceability      :  RTC-1874182
** Change Description:  RTC calibration interface added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/Sept/2020
** CDSID             :  mprajapa
** Traceability      :  RTC-1777209
** Change Description:  ADC reference calibration service added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/07/2019
** CDSID             :  vsupraja
** Traceability      :  RTC
** Change Description:  Added Read and Write services for Sound Channel Volume and Sound Mixer Volume
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1297825
** Change Description:  Three point fuel calibration added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  28/08/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1185614
** Change Description:  Unit test defect fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  09/07/2018
** CDSID             :  gnataraj
** Traceability      :  RTC 1152542
** Change Description:  Added the Read and Write service for Fuel RAD (Fuel Sender Calibration Table) feature
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1137720
** Change Description:  warning fixed
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

#endif /* IOCALIBDIAGCDD_C */
