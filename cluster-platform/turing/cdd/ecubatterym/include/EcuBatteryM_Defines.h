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
#ifndef __ECUBATTERYM_DEFINES_H__
#define __ECUBATTERYM_DEFINES_H__

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

/*==================[macros]================================================*/

/*------------------[DEM status codes] -------------------------------------*/
/** \brief Type for ICU DEM status */
/* Brief type for ECUPOWERM DEM pass status. */
#define ECUBATTERYM_DEM_EVENT_STATUS_PASSED       ((uint8) 0x00U)
/* Brief type for ECUPOWERM DEM failed status. */
#define ECUBATTERYM_DEM_EVENT_STATUS_FAILED       ((uint8) 0x01U)

/*------------------[Service identifiers]-----------------------------------*/
/** \brief Definition of the service identifier of EcuBatteryM_Init. */
#define ECUBATTERYM_API_INIT                      			((uint8) 0x00U)

/** \brief Definition of the service identifier of EcuBatteryM_Monitorchannels. */
#define ECUBATTERYM_API_MONITOR_CHANNELS       				((uint8) 0x01U)

/** \brief Definition of the service identifier of EcuBatteryM_DeInit. */
#define ECUBATTERYM_API_DEINIT								((uint8) 0x02U)

/** \brief Definition of the service identifier of EcuBatteryM_Monitorchannel. */
#define ECUBATTERYM_API_MONITOR_CHANNEL                      ((uint8) 0x03U)

/** \brief Definition of the service identifier of EcuBatteryM_GetChannelStatus. */
#define ECUBATTERYM_API_GET_CHANNEL_STATUS                    ((uint8) 0x04U)

/** \brief Definition of the service identifier of EcuBatteryM_SetMonitoringState. */
#define ECUBATTERYM_API_SET_MONITOR_STATE					((uint8) 0x05U)
 
/** \brief Definition of the service identifier of EcuBatteryM_ProcessDelayTime. */
#define ECUBATTERYM_API_PROCESS_DELAY_TIME					((uint8) 0x06U)

/** \brief Definition of the service identifier of EcuBatteryM_GetChannelRawStatus. */
#define ECUBATTERYM_API_GET_CHANNEL_RAW_STATUS              ((uint8) 0x07U)

/** \brief Definition of the service identifier of EcuBatteryM_GetThresholdAndHystValues. */
#define ECUBATTERYM_API_GET_THRESHOLD_HYST_VALUES           	((uint8) 0x08U)

/*------------------[Development errors]------------------------------------*/
/** \brief API service called before EcuPowerM initialization */
#define ECUBATTERYM_E_UNINIT               					((uint8) 0x00U)

/** \brief Init API service called more than once */
#define ECUBATTERYM_E_ALREADY_INITIALIZED                   ((uint8) 0x01U)

/** \brief Channel reference list is null    */
#define ECUBATTERYM_E_NULL_CHANNEL_LIST						((uint8) 0x02U)
  
/** \brief Invalid Voltage source API SPECIFICATION*/
#define ECUBATTERYM_E_NULL_VOLTAGE_SOURCE_API				((uint8) 0x03U)

/** \brief API service called with invalid CHANNEL  */
#define ECUBATTERYM_E_PARAM_CHANNEL                          	((uint8) 0x04U)

/** \brief API service called with invalid CHANNEL  */
#define ECUBATTERYM_E_INVALID_THRESHOLD_TYPE                   	((uint8) 0x05U)
 


#endif //__ECUBATTERYM_DEFINES_H__

/*==============================================================================================================================================
Date              	: 08-03-2026
CDSID             	: skiranku
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
