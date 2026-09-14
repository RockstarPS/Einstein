//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#ifndef __ECUWAKEUPM_DEFINES_H__
#define __ECUWAKEUPM_DEFINES_H__

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

/*==================[macros]================================================*/

/*------------------[DEM status codes] -------------------------------------*/
/** \brief Type for ICU DEM status */
/* Brief type for ECUWAKEUPM DEM pass status. */
#define ECUWAKEUPM_DEM_EVENT_STATUS_PASSED       ((uint8) 0x00U)
/* Brief type for ECUWAKEUPM DEM failed status. */
#define ECUWAKEUPM_DEM_EVENT_STATUS_FAILED       ((uint8) 0x01U)

/*------------------[Service identifiers]-----------------------------------*/
/** \brief Definition of the service identifier of EcuWakeupM_Init. */
#define ECUWAKEUPM_API_INIT                      			((uint8) 0x00U)

/** \brief Definition of the service identifier of EcuWakeupM_EnableWakeup. */
#define ECUWAKEUPM_API_ENABLE_WAKEUP                   		((uint8) 0x01U)

/** \brief Definition of the service identifier of EcuWakeupM_DisableWakeup. */
#define ECUWAKEUPM_API_DISABLE_WAKEUP                       ((uint8) 0x02U)

/** \brief Definition of the service identifier of EcuWakeupM_EnableAllWakeups. */
#define ECUWAKEUPM_API_ENABLE_ALL_WAKEUPS		            ((uint8) 0x03U)

/** \brief Definition of the service identifier of EcuWakeupM_DisableAllWakeups. */
#define ECUWAKEUPM_API_DISABLE_ALL_WAKEUPS             		((uint8) 0x04U)

/** \brief Definition of the service identifier of EcuWakeupM_SetNotification. */
#define ECUWAKEUPM_API_SET_NOTIFICATION  					((uint8) 0x05U)

/** \brief Definition of the service identifier of EcuWakeupM_ManageWakeup. */
#define ECUWAKEUPM_API_MANAGE_WAKEUP      					((uint8) 0x06U)

/** \brief Definition of the service identifier of EcuWakeupM_CheckWakeup. */
#define ECUWAKEUPM_API_CHECK_WAKEUP       					((uint8) 0x07U)

/** \brief Definition of the service identifier of EcuWakeupM_GetWakeupChannel. */
#define ECUWAKEUPM_API_GET_WAKEUP_CHANNEL           		((uint8) 0x08U)

/** \brief Definition of the service identifier of EcuWakeupM_ScanWakeupChannel. */
#define ECUWAKEUPM_API_SCAN_WAKEUP_CHANNEL           		((uint8) 0x09U)

/** \brief Definition of the service identifier of EcuWakeupM_ScanAllWakeupChannels. */
#define ECUWAKEUPM_API_SCAN_ALL_WAKEUP_CHANNELS             ((uint8) 0x0AU)

/** \brief Definition of the service identifier of EcuWakeupM_ReportWakeupSource. */
#define ECUWAKEUPM_API_REPORT_WAKEUP_SOURCE       			((uint8) 0x0BU)

/** \brief Definition of the service identifier of EcuWakeupM_ReportAllWakeupSources. */
#define ECUWAKEUPM_API_REPORT_ALL_WAKEUP_SOURCES          	((uint8) 0x0CU)


/*------------------[Development errors]------------------------------------*/
/** \brief API service called before EcuWakeupM initialization */
#define ECUWAKEUPM_E_UNINIT               					((uint8) 0x00U)

/** \brief Init API service called more than once */
#define ECUWAKEUPM_E_ALREADY_INITIALIZED                    ((uint8) 0x01U)

/** \brief API service called with invalid wakeup channel  */
#define ECUWAKEUPM_E_PARAM_CHANNEL               			((uint8) 0x02U)

/** \brief API service called with invalid port configurations   */
#define ECUWAKEUPM_E_PORT_CONFIGURATION               		((uint8) 0x03U)

/** \brief API service called with NULL pointer   */
#define ECUWAKEUPM_E_PARAM_POINTER               			((uint8) 0x04U)

/** \brief API service called with NULL pointer   */
#define ECUWAKEUPM_E_INVALID_WAKEUP_SOURCE					((uint8) 0x05U)



#endif //__ECUWAKEUPM_DEFINES_H__

/*==============================================================================================================================================
Date              	: 13-11-23
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
