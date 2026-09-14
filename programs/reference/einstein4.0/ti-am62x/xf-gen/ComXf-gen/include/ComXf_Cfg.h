/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComXf_Cfg.h
*    @ingroup ComXfConfiguration
*    @brief This is ComXf Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the ComXf module.
*    @defgroup ComXfConfiguration
*    @brief This contains the configuration files for the ComXf module.
********************************************************************************************************************/
#ifndef COMXF_CFG_H
#define COMXF_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComXf_Types.h" 
#include "Rte.h"
#include "Rte_Type.h"
#include "Com.h"
#define COMXF_SEC_CODE_START
#define COMXF_CORE_CONST_SEC_START
#define COMXF_CORE_DATA_SEC_START
#define COMXF_CORE_BSS_SEC_START
#include "MemMap.h"
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief Switches the development error detection and notification on or off. */
#define COMXF_DEV_ERROR_DETECT               STD_ON
/*! @brief Activate/Deactivate the version information API. */
#define COMXF_VERSION_API                    STD_ON
/********************************************************************************************************************
*  #! ComXf Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief Defines the dummy macro */
#ifndef COMXF_DUMMY_STATEMENT
#define COMXF_DUMMY_STATEMENT(v)
#endif
/*******************************************************************************************************************
*  #! ComXf module configuration                                                                                   *
*******************************************************************************************************************/
/*! @brief Enables/Disables the support for the DEM detection and notification */
#define COMXF_DEM_ERROR_SUPPORT              STD_ON
/*! @brief Enables/Disables the support for the float32 data type */
#define COMXF_BASIC_TYPE_FLOAT32_SUPPORT     STD_ON
/*! @brief Enables/Disables the support for the float64 data type */
#define COMXF_BASIC_TYPE_FLOAT64_SUPPORT     STD_ON
/*! @brief Enables/Disables the support for the uint64 data type */
#define COMXF_BASIC_TYPE_UINT64_SUPPORT      STD_ON
/*! @brief Enables/Disables the support for the sint64 data type */
#define COMXF_BASIC_TYPE_SINT64_SUPPORT      STD_ON
/*! @brief Defines the micro endianess type */
#define COMXF_MICRO_ENDIANESS                COMXF_ENDIANESS_LITTLE

/* #! Defines the ComXf signal id */
#define COMXf_SIGNAL_AIRBAG_ABS_258_CAN0_RX 0U
#define COMXf_SIGNAL_ALIVE_101_CAN0_RX 1U
#define COMXf_SIGNAL_CRC_101_CAN0_RX 2U
#define COMXf_SIGNAL_VEHICLESPEEDABS_ABS_258_CAN0_RX 3U
#define COMXf_SIGNAL_COM_HS_BATTERY_VOLTAGE_CAN0_TX 4U
#define ComXf_Num_Of_Signals    5U
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the ComXf configuration software Major version */
#define COMXF_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the ComXf configuration software Minor version */
#define COMXF_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the ComXf configuration software Patch version */
#define COMXF_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComXf configuration  */
#define COMXF_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by ComXf configuration  */
#define COMXF_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by ComXf configuration  */
#define COMXF_CFG_AR_RELEASE_REVISION_VERSION           1u

/********************************************************************************************************************
* #! ComXf types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/

/*! @brief Defines the config type for the ComXf configuration */
typedef struct 
{
    uint8 dummy;
}ComXf_ConfigType;
#define COMXF_SEC_CODE_STOP
#define COMXF_CORE_CONST_SEC_END
#define COMXF_CORE_DATA_SEC_END
#define COMXF_CORE_BSS_SEC_END

#include "MemMap.h"
#endif /* COMXF_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
*******************************************************************************************************************/
