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
#ifndef __ECUPOWERM_DEFINES_H__
#define __ECUPOWERM_DEFINES_H__

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

/*==================[macros]================================================*/

/*------------------[DEM status codes] -------------------------------------*/
/** \brief Type for ICU DEM status */
/* Brief type for ECUPOWERM DEM pass status. */
#define ECUPOWERM_DEM_EVENT_STATUS_PASSED       ((uint8) 0x00U)
/* Brief type for ECUPOWERM DEM failed status. */
#define ECUPOWERM_DEM_EVENT_STATUS_FAILED       ((uint8) 0x01U)

/*------------------[Service identifiers]-----------------------------------*/
/** \brief Definition of the service identifier of EcuPowerM_Init. */
#define ECUPOWERM_API_INIT                      			((uint8) 0x00U)

/** \brief Definition of the service identifier of EcuPowerM_MainFunction. */
#define ECUPOWERM_API_MAIN_FUNCTION                   		((uint8) 0x01U)

/** \brief Definition of the service identifier of EcuPowerM_ProcessWaitTime. */
#define ECUPOWERM_API_PROCESS_WAIT_TIME                     ((uint8) 0x02U)

/** \brief Definition of the service identifier of EcuPowerM_RequestPower. */
#define ECUPOWERM_API_REQUEST_POWER		            		((uint8) 0x03U)

/** \brief Definition of the service identifier of EcuPowerM_ProcessDevice. */
#define ECUPOWERM_API_PROCESS_DEVICE             			((uint8) 0x04U)

/** \brief Definition of the service identifier of EcuPowerM_ProcessSequence. */
#define ECUPOWERM_API_PROCESS_SEQUENCE  					((uint8) 0x05U)

/** \brief Definition of the service identifier of EcuPowerM_ProcessJob. */
#define ECUPOWERM_API_PROCESS_JOB      						((uint8) 0x06U)

/** \brief Definition of the service identifier of EcuPowerM_ProcessCommand. */
#define ECUPOWERM_API_PROCESS_COMMAND       				((uint8) 0x07U)

/** \brief Definition of the service identifier of EcuPowerM_EvaluateChannelCriteria. */
#define ECUPOWERM_API_EVALUATE_CHANNEL_CRITERIA           	((uint8) 0x08U)

/** \brief Definition of the service identifier of EcuPowerM_EvaluateChannelCriteria. */
#define ECUPOWERM_API_GET_DEVICE_STATUS            			((uint8) 0x09U)

/** \brief Definition of the service identifier of EcuPowerM_DeInit. */
#define ECUPOWERM_API_DEINIT								((uint8) 0x0AU)




/*------------------[Development errors]------------------------------------*/
/** \brief API service called before EcuPowerM initialization */
#define ECUPOWERM_E_UNINIT               					((uint8) 0x00U)

/** \brief Init API service called more than once */
#define ECUPOWERM_E_ALREADY_INITIALIZED                    	((uint8) 0x01U)

/** \brief API service called with invalid device ID  */
#define ECUPOWERM_E_PARAM_DEVICE               				((uint8) 0x02U)

/** \brief API service called with invalid device request   */
#define ECUPOWERM_E_PARAM_DEVICE_REQUEST               		((uint8) 0x03U)

/** \brief API service called with invalid device state   */
#define ECUPOWERM_E_PARAM_DEVICE_STATE               		((uint8) 0x04U)

/** \brief Invalid device power state   */
#define ECUPOWERM_E_DEVICE_POWER_STATE               		((uint8) 0x05U)

/** \brief API service called with null sequence reference   */
#define ECUPOWERM_E_PARAM_SEQUENCE               			((uint8) 0x06U)

/** \brief NULL sequence list   */
#define ECUPOWERM_E_SEQUENCE_REFERENCE               		((uint8) 0x07U)

/** \brief zero or more than configured sequences   */
#define ECUPOWERM_E_NUMBER_OF_SEQUENCES						((uint8) 0x08U)

/** \brief API service called with null job reference   */
#define ECUPOWERM_E_PARAM_JOB								((uint8) 0x09U)

/** \brief Job reference is null   */
#define ECUPOWERM_E_JOB_REFERENCE							((uint8) 0x0AU)

/** \brief Number of Jobs configured zero   */
#define ECUPOWERM_E_NUMBER_OF_JOBS							((uint8) 0x0BU)

/** \brief API service called with null command reference  */
#define ECUPOWERM_E_PARAM_COMMAND							((uint8) 0x0CU)

/** \brief NULL command reference   */
#define ECUPOWERM_E_COMMAND_REFERENCE               		((uint8) 0x0DU)

/** \brief Number of commands configured zero   */
#define ECUPOWERM_E_NUMBER_OF_COMMANDS						((uint8) 0x0EU)

/** \brief Invalid command type   */
#define ECUPOWERM_E_COMMAND_TYPE							((uint8) 0x0FU)

/** \brief Invalid command type  */
#define ECUPOWERM_E_COMMAND									((uint8) 0x10U)

/** \brief Channel reference list is null    */
#define ECUPOWERM_E_NULL_CHANNEL_LIST						((uint8) 0x11U)

/** \brief Null Channel reference    */
#define ECUPOWERM_E_NULL_CHANNEL							((uint8) 0x12U)

/** \brief Invalid channel type of a given command    */
#define ECUPOWERM_E_CHANNEL_TYPE							((uint8) 0x13U)

/** \brief Timeout on wait channel    */
#define ECUPOWERM_E_CHANNEL_WAIT_FAILED						((uint8) 0x14U)

/** \brief Null Driver table reference    */
#define ECUPOWERM_E_DRIVER_TABLE							((uint8) 0x15U)

/** \brief Null Driver API    */
#define ECUPOWERM_E_NULL_DRIVER_API							((uint8) 0x16U)

/** \brief Invalid channel criteria     */
#define ECUPOWERM_E_CHANNEL_CRITERIA						((uint8) 0x17U)
 


#endif //__ECUPOWERM_DEFINES_H__

/*==============================================================================================================================================
Date              	: 05-01-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
