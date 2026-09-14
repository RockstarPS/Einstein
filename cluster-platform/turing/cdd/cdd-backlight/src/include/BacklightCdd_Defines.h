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
#ifndef BACKLIGHTCDD_DEFINES_H
#define BACKLIGHTCDD_DEFINES_H

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

/*==================[macros]================================================*/

/*------------------[DEM status codes] -------------------------------------*/
/** \brief Type for ICU DEM status */
/* Brief type for BACKLIGHTCDD DEM pass status. */
#define BACKLIGHTCDD_DEM_EVENT_STATUS_PASSED       (0x00U)
/* Brief type for BACKLIGHTCDD DEM failed status. */
#define BACKLIGHTCDD_DEM_EVENT_STATUS_FAILED       (0x01U)

/*------------------[Service identifiers]-----------------------------------*/
/** \brief Definition of the service identifier of BacklightCdd_Init. */
#define BACKLIGHTCDD_API_INIT                      			(0x00U)

/** \brief Definition of the service identifier of BacklightCdd_MainFunction. */
#define BACKLIGHTCDD_API_MAIN_FUNCTION                      (0x01U)

/** \brief Definition of the service identifier of CBacklightCdd_RequestPower. */
#define BACKLIGHTCDD_API_REQUEST_POWER		            	(0x02U)

/** \brief Definition of the service identifier of CBacklightCdd_SetBrightness. */
#define BACKLIGHTCDD_API_SET_BRIGHTNESS             		(0x03U)

/** \brief Definition of the service identifier of CBacklightCdd_EnterSafeState. */
#define BACKLIGHTCDD_API_ENTER_SAFE_STATE  					(0x04U)

/** \brief Definition of the service identifier of CBacklightCdd_ExitSafeState. */
#define BACKLIGHTCDD_API_EXIT_SAFE_STATE      				(0x05U)

/** \brief Definition of the service identifier of BacklightCdd_DeInit. */
#define BACKLIGHTCDD_API_DEINIT								(0x06U)

/** \brief Definition of the service identifier of BacklightCdd_SafeStateRqst. */
#define BACKLIGHTCDD_API_SAFESTATUS_REQUEST                 (0x07U)

/** \brief Definition of the service identifier of BacklightCDD_RegI2CTransmission */
#define BACKLIGHTCDD_API_REGISTER_I2CTRANSMISSION           (0x08U)

/** \brief Definition of the service identifier of CBacklightCdd_GetStatus */
#define BACKLIGHTCDD_API_GET_STATUS                         (0x09U)




/*------------------[Development errors]------------------------------------*/
/** \brief API service called before BacklightCdd initialization */
#define BACKLIGHTCDD_E_UNINIT               					(0x00U)

/** \brief Init API service called more than once */
#define BACKLIGHTCDD_E_ALREADY_INITIALIZED                    	(0x01U)

/** \brief API service called with invalid device ID  */
#define BACKLIGHTCDD_E_PARAM_DEVICE               				(0x02U)

/** \brief API service called with invalid device state   */
#define BACKLIGHTCDD_E_PARAM_DEVICE_STATE               		(0x03U)

/** \brief Invalid duty   */
#define BACKLIGHTCDD_E_PARAM_DUTY               		         (0x04U)

/** \brief Invalid Safe status request   */
#define BACKLIGHTCDD_E_PARAM_SAFE_STATUS_REQUEST               	(0x05U)

/** \brief I2C register write failed   */
#define BACKLIGHTCDD_INIT_REG_I2CFAILED               	        (0x07U)

/** \brief Maximum duty for backlight CDD   */
#define BACKLIGHTCDD_MAX_DUTY                                    (0x100U)

/** \brief MACRO for indicating backlight cdd init*/
#define BACKLIGHTCDD_S_INITIALIZED                               (0x01U)

/** \brief MACRO for indicating backlight cdd de-init*/
#define BACKLIGHTCDD_S_UNINITIALIZED                              (0x00U)


/*MACRO for indicating uint8 maximum value*/
#define BACKLIGHTCDD_UINT8_MAX 255u 



/*MACRO for indicating I2cBus free */
#define BACKLIGHTCDD_START_TRANSMIT 0xFFu 


 


#endif //__BACKLIGHTCDD_DEFINES_H__

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
Traceability      	: ASCDD-106
Change Description	: Fixed KW warnings
================================================================================================================================================*/


