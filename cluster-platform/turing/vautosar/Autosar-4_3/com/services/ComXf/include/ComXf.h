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
/*!******************************************************************************************************************
*   @file ComXf.h
*   @ingroup ComXf
*   @brief This file provides the declaration of the ComXf API. This header file should be included by other
*   modules that use the ComXf API.
*   @defgroup ComXf
*   @brief The Com transformer is a transformer of the class Serializer. It serializes structured
*   data into a linear form.
********************************************************************************************************************/
#ifndef COMXF_H
#define COMXF_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "TransformerTypes.h"
#include "ComXf_Types.h"
#include "ComXf_Cfg.h"   
#include "ComXf_Lcfg.h"        
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the ComXf SW major version */
#define COMXF_SW_MAJOR_VERSION              1u
/*! @brief Defines the ComXf SW minor version */
#define COMXF_SW_MINOR_VERSION              0u
/*! @brief Defines the ComXf SW patch version */
#define COMXF_SW_PATCH_VERSION              0u
/* Autosar Release */
/*! @brief Defines the ComXf AUTOSAR major version */
#define COMXF_AR_RELEASE_MAJOR_VERSION      4u
/*! @brief Defines the ComXf AUTOSAR minor version */
#define COMXF_AR_RELEASE_MINOR_VERSION      3u
/*! @brief Defines the ComXf AUTOSAR patch version */
#define COMXF_AR_RELEASE_REVISION_VERSION   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of ComXf module. */
#define COMXF_VENDOR_ID                     0x0033u
/*! @brief Defines the Module Id of ComXf module.*/
#define COMXF_MODULE_ID                     175u
/*! @brief Defines the version Id of ComXf module.*/
#define COMXF_INSTANCE_ID                   0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for ComXf_Init function */
#define COMXF_INIT_API                      0x01u
/*! @brief Defines the service Id for ComXf_DeInit function */
#define COMXF_DEINIT_API                    0x02u
/*! @brief Defines the service Id for ComXf_GetVersionInfo function */
#define COMXF_GETVERSIONINFO_API            0x00u
/*! @brief Defines the service Id for ComXf_<transformerId> function */
#define COMXF_TRANSFORMER_API               0x03u
/*! @brief Defines the service Id for ComXf_Inv_<transformerId> function */
#define COMXF_INV_TRANSFORMER_API           0x04u
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief Error code if any other API service, except GetVersionInfo is called before the transformer module was 
    initialized with Init or after a call to DeInit */
#define COMXF_E_UNINIT                       0x01u
/*! @brief Error code if an invalid configuration set was selected */
#define COMXF_E_INIT_FAILED                  0x02u
/*! @brief API service called with wrong parameter */
#define COMXF_E_PARAM                        0x03u
/*! @brief API service called with invalid pointer */
#define COMXF_E_PARAM_POINTER                0x04u
/*! @brief Defines No error id  */
#define COMXF_E_NO_ERROR                     0xFFu

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define COMXF_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service initializes the transformer for the further processing.
*   @param[in]  config Pointer to the transformer’s configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, COMXF_CODE) ComXf_Init( P2CONST(ComXf_ConfigType,AUTOMATIC,COMXF_APPL_VAR) config);
/*!******************************************************************************************************************
*   @brief      This service deinitializes the transformer.
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, COMXF_CODE) ComXf_DeInit(void);
/*!******************************************************************************************************************
*   @brief      This service returns the version information of the called transformer module.
*   @param[out] VersionInfo Pointer to where to store the version information of this module.
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, COMXF_CODE) ComXf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,COMXF_APPL_VAR) VersionInfo 
); 

#define COMXF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMXF_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
