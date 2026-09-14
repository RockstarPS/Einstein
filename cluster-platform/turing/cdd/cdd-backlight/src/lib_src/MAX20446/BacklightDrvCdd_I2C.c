//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
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
#include "BacklightDrvCdd_I2C.h"
#include "Rte_Type.h"
#include "BacklightCdd_ErrorHandler.h"
#include "BacklightDrvCdd_I2C_MAX20446.h"

#ifndef BACKLIGHTCDDI2CADAPTER_VARIANT
#error "BACKLIGHTCDDI2CADAPTER_VARIANT is not defined. Please define in cmake with proper variant value"
#endif

//=====================================================================================================================
//  LOCAL FUNCTIONS
//=====================================================================================================================



//=====================================================================================================================
//  INITIALIZED DATA DECLARATIONS (.DATA)
//=====================================================================================================================
#define CBacklightCdd_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

static VAR(uint8,                               CBacklightCdd_VAR_INIT)     BacklightCdd_I2C_txBuf[REG_COUNT_I2C]  = {(uint8) BACKLIGHTDRVCDD_ZERO};
static VAR(uint8,                               CBacklightCdd_VAR_INIT)     BacklightCdd_I2C_rxBuf[REG_COUNT_I2C]  = {(uint8) BACKLIGHTDRVCDD_ZERO};

#define CBacklightCdd_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define CBacklightCdd_START_SEC_CODE
#include "MemMap.h"

//======================================================================================================================
/** \brief BacklightCdd_I2cWriteReg
 **
 ** This function writes a value to a register of the backlight driver via I2C interface.
 **
 ** \param[in] reg           Register address.
 ** \param[in] val           Value to be written.

 **
 ** \return    E_OK          Write operation successful.
 **            E_NOT_OK      Write operation failed.
 **
 ** 
 **/

//====================================================================================================================
Std_ReturnType BacklightCdd_I2cWriteReg(uint8 reg, uint8 val)
{
	Std_ReturnType fl_return_bool = E_NOT_OK;

	static uint8 buf[BACKLIGHTDRVCDD_TWO];

	buf[BACKLIGHTDRVCDD_ZERO] = reg;
	
	buf[BACKLIGHTDRVCDD_ONE] = val;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	if( E_OK == I2c_SetupEB(BkltDev->I2cCfg->i2cChannelWrite, buf, NULL, BACKLIGHTDRVCDD_TWO , BACKLIGHTDRVCDD_ZERO, BkltDev->I2cCfg->deviceaddr))
	{
		if( E_OK == I2c_AsyncTransmit(BkltDev->I2cCfg->i2cSeqIdWrite) )
		{
			fl_return_bool = E_OK;
		}
	}
	
	return fl_return_bool;
}

//======================================================================================================================
/** \brief BacklightCdd_I2cAsyncRegRead
 **
 ** This function does setupEB and AsyncTranmsit for I2c read
 **
 ** \param[in] reg           Register address.
 ** \param[in] index         index to store the value.
 **
 ** \return    E_OK          Read operation successful.
 **            E_NOT_OK      Read operation failed.
 **/
//====================================================================================================================
Std_ReturnType BacklightCdd_I2cAsyncRegRead(uint8 reg, uint8 index)
{
    Std_ReturnType fl_return_bool = E_NOT_OK;

    static uint8 Txbuf[BACKLIGHTDRVCDD_ONE];

    Txbuf[BACKLIGHTDRVCDD_ZERO] = reg;

    const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	#if(BACKLIGHTCDDI2CADAPTER_VARIANT == BACKLIGHTCDDI2CADAPTER_VARIANT_VISTEON_TV2_OLD)
    if( E_OK == I2c_SetupEB(BkltDev->I2cCfg->i2cChannelWrite, &Txbuf[0], NULL, BACKLIGHTDRVCDD_ONE, BACKLIGHTDRVCDD_ZERO, BkltDev->I2cCfg->deviceaddr))
    {
		if( E_OK == I2c_SetupEB(BkltDev->I2cCfg->i2cChannelRead, NULL, &BacklightCdd_I2C_rxBuf[index], BACKLIGHTDRVCDD_ZERO, BACKLIGHTDRVCDD_ONE, BkltDev->I2cCfg->deviceaddr))
		{
			if( E_OK == I2c_AsyncTransmit(BkltDev->I2cCfg->i2cSeqIdRead))
			{
				fl_return_bool = E_OK;
			}
		}
    }
	#else
	if( E_OK == I2c_SetupEB(BkltDev->I2cCfg->i2cChannelWrite, &Txbuf[0], &BacklightCdd_I2C_rxBuf[index], BACKLIGHTDRVCDD_ONE, BACKLIGHTDRVCDD_ONE, BkltDev->I2cCfg->deviceaddr))
	{
		if( E_OK == I2c_AsyncTransmit(BkltDev->I2cCfg->i2cSeqIdRead))
		{
			fl_return_bool = E_OK;
		}
	}
	#endif
    return fl_return_bool;
}

//======================================================================================================================
/** \brief BacklightCdd_I2cGetRxData
 **
 ** This function Reads value of a register of the backlight driver via I2C interface.
 **
 ** \param[out] val           Value read.
 ** \param[in]  index         index to store the value.
 **/
//====================================================================================================================
void BacklightCdd_I2cGetRxData(uint8 *val, uint8 index)
{
	*val = BacklightCdd_I2C_rxBuf[index];
}

//======================================================================================================================
/** \brief BacklightCdd_I2cGetSeqResult
 **
 ** This function checks the sequence result for the requested I2c sequence
 **
 ** \param[in] seq           I2c sequence value.
 **
 ** \return    I2C_SEQ_OK
 **			   I2C_SEQ_PENDING
 **			   I2C_SEQ_QUEUED
 **			   I2C_SEQ_NACK
 **			   I2C_SEQ_FAILED
 **			   I2C_SEQ_CANCELLED
 **            
 **/
//====================================================================================================================
I2c_SeqResultType BacklightCdd_I2cGetSeqResult(uint8 seq)
{
	I2c_SeqResultType  I2c_SeqResult = I2C_SEQ_FAILED;

	I2c_SeqResult = I2c_GetSequenceResult(seq);

	if((I2C_SEQ_OK != I2c_SeqResult) && (I2C_SEQ_PENDING != I2c_SeqResult))
	{
		I2c_SeqResult = I2C_SEQ_FAILED;
	}

	return I2c_SeqResult;

}

//======================================================================================================================
/** \brief BacklightCdd_I2cCancel
 **
 ** This function cancels the requsted sequence
 **
 ** \param[in] seq           I2c sequence value.
 **
 ** \return    none
 **/
//====================================================================================================================
void BacklightCdd_I2cCancel(uint8 seq)
{
	I2c_Cancel(seq);
}

//======================================================================================================================
/** \brief BacklightDrvCdd_Process_Set_Brightness
 **
 ** This function performs set brightness of the backlight driver by writing necessary configuration values to the driver registers via I2C interface.
 **
 ** \param[in] targetBrightness Target Brightness value.
 **
 ** \return    E_OK          Write operation successful.
 **            E_NOT_OK      Write operation failed..
 **
 ** */
//======================================================================================================================
FUNC(Std_ReturnType, CBacklightCdd_CODE) BacklightDrvCdd_Process_Set_Brightness(uint16 targetBrightness)
{
    Std_ReturnType ret = E_OK;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

	I2c_SeqResultType  I2c_write_GetSeqSts = I2C_SEQ_FAILED;
	I2c_SeqResultType  I2c_read_GetSeqSts  = I2C_SEQ_FAILED;

	I2c_write_GetSeqSts = I2c_GetSequenceResult(BkltDev->I2cCfg->i2cSeqIdWrite);
	I2c_read_GetSeqSts	= I2c_GetSequenceResult(BkltDev->I2cCfg->i2cSeqIdRead);


	if (BacklightChipHandler == NULL)
	{
		ret = E_NOT_OK;  /*No chip configured*/
	}

	if(ret == E_OK )
	{
		BacklightChipHandler->CalcDutyRegisters(targetBrightness , &BacklightCdd_I2C_txBuf );

		if( ( ( I2C_SEQ_OK == I2c_write_GetSeqSts ) || ( I2C_SEQ_CANCELLED == I2c_write_GetSeqSts  ) ) && ( ( I2C_SEQ_OK == I2c_read_GetSeqSts ) || ( I2C_SEQ_CANCELLED == I2c_read_GetSeqSts  ) ) ) 
    	{
		
		    ret = I2c_SetupEB(BkltDev->I2cCfg->i2cChannelWrite, &BacklightCdd_I2C_txBuf, NULL, BACKLIGHTDRVCDD_FIFTEEN , BACKLIGHTDRVCDD_ZERO, BkltDev->I2cCfg->deviceaddr);

    	    if(ret == E_OK)
    	    {
    	        ret = I2c_AsyncTransmit(BkltDev->I2cCfg->i2cSeqIdWrite);
    	    }
    	}
		else
		{
			if(I2C_SEQ_PENDING == I2c_write_GetSeqSts)
			{
				(void)I2c_Cancel(BkltDev->I2cCfg->i2cSeqIdWrite);	
			}

			if(I2C_SEQ_PENDING == I2c_read_GetSeqSts )
			{
				(void)I2c_Cancel(BkltDev->I2cCfg->i2cSeqIdRead);	
			}
			ret = E_NOT_OK;
			
		}
    }

	return ret;
}

/*!**********************************************************************************************************************
** \brief BacklightDrvCdd_ManageConfigRegI2CTransmission
**
** Function to configure the registers according to User provided 
**
** \param[in] targetBrightness Target Brightness value.
**
** \return    BACKLIGHTCDD_REG_WRITE_SUCCESS    Write operation successful.
**           BACKLIGHTCDD_REG_WRITE_ERROR      Write operation failed.
**
*************************************************************************************************************************/
FUNC(BACKLIGHTCDD_InitRegCfgStateType, CBacklightCdd_CODE) BacklightDrvCdd_ManageConfigRegI2CTransmission
(
	VAR(uint16, AUTOMATIC) targetBrightness
)
{
    BACKLIGHTCDD_InitRegCfgStateType ret;

    Std_ReturnType	i2cRetl = E_NOT_OK;

    I2c_SeqResultType  i2cSeqRes = I2C_SEQ_FAILED ;

	const BacklightCdd_DeviceConfigType *BkltDev = BacklightConfig.DeviceTable;

    /* Act Based upon Sequence result*/
    i2cSeqRes = I2c_GetSequenceResult(BkltDev->I2cCfg->i2cSeqIdWrite);
	
	switch (i2cSeqRes)
	{
		case I2C_SEQ_OK:
			i2cRetl = BacklightDrvCdd_Process_Set_Brightness(targetBrightness);
			break;
		case I2C_SEQ_BUSY:
			/* Do Nothing - wait till seq is ok */
			break;
		
		case I2C_SEQ_FAILED:
			BacklightCdd_ReportError(BACKLIGHTCDD_API_REGISTER_I2CTRANSMISSION , BACKLIGHTCDD_INIT_REG_I2CFAILED);
			i2cRetl = E_NOT_OK;
			break;
		
		default:
			BacklightCdd_ReportError(BACKLIGHTCDD_API_REGISTER_I2CTRANSMISSION , BACKLIGHTCDD_E_PARAM_DEVICE);
			i2cRetl = E_NOT_OK;
			break;
	}
    switch( i2cRetl )
	{
		case E_OK:
			ret = BACKLIGHTCDD_REG_WRITE_SUCCESS;
			break;
	
		case E_NOT_OK:
			BacklightCdd_ReportError(BACKLIGHTCDD_API_REGISTER_I2CTRANSMISSION , BACKLIGHTCDD_INIT_REG_I2CFAILED);
			ret = BACKLIGHTCDD_REG_WRITE_ERROR;
			break;
		
		default:
			BacklightCdd_ReportError(BACKLIGHTCDD_API_REGISTER_I2CTRANSMISSION , BACKLIGHTCDD_INIT_REG_I2CFAILED);
			ret = BACKLIGHTCDD_REG_WRITE_ERROR;
			break;
	}
    return ret;
}
    

#define CBacklightCdd_STOP_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************************************
*                                 END OF FILE                                                                      
***********************************************************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*==============================================================================================================================================
Date              	: 03-12-25
CDSID             	: yviswana
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 03-17-26
CDSID             	: bmahesan
Traceability      	: ASCDD-241
Change Description	: Updated Version for MAX20446B/LP8867.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 04-07-26
CDSID             	: mmahend2
Traceability      	: ASCDD-106 , ASCDD-357
Change Description	: 1) Fixed KW warnings. 2) Updated Backlight Fault monitoring Logic
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 17-04-26
CDSID             	: mmahend2
Traceability      	: ASCDD-357
Change Description	: For CUPRA ABT instead of I2c_Channel , I2c_SeqID provided.
================================================================================================================================================*/

