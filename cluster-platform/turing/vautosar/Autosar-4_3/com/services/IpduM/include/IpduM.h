/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2020 by Visteon Corporation.       All rights reserved.                                             *
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
*   @file IpduM.h
*   @ingroup IpduM
*   @brief This file provides the declaration of the IpduM API. This header file should be included by other
*   modules that use the IpduM API.
*   @defgroup IpduM
*   @brief This file implements the AUTOSAR IpduM module.
********************************************************************************************************************/

#ifndef IPDUM_H
#define IPDUM_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "IpduM_Cbk.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! Defines the IPDUM SW major version */
#define IPDUM_SW_MAJOR_VERSION                                   0U
/*! Defines the IPDUM SW minor version */
#define IPDUM_SW_MINOR_VERSION                                   0U
/*! Defines the IPDUM SW patch version */
#define IPDUM_SW_PATCH_VERSION                                   1U
/* Autosar Release */
/*! Defines the IPDUM SW major version */
#define IPDUM_AR_RELEASE_MAJOR_VERSION                           4U
/*! Defines the IPDUM SW major version */
#define IPDUM_AR_RELEASE_MINOR_VERSION                           3U
/*! Defines the IPDUM SW major version */
#define IPDUM_AR_RELEASE_REVISION_VERSION                        1U
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! Defines the Vendor Id of IPDUM module.*/
#define IPDUM_VENDOR_ID                                          51U
/*! Defines the Module Id of IPDUM module.*/
#define IPDUM_MODULE_ID                                          52U
/*! Defines the version Id of IPDUM module.*/
#define IPDUM_INSTANCE_ID                                        0U
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
#define IPDUM_INIT_API                                          0x00
#define IPDUM_GETVERSIONINFO_API                                0x01
#define IPDUM_TRANSMIT_API                                      0x03
#define IPDUM_RXINDICATION_API                                  0x42
#define IPDUM_TXCONFIRMATION_API                                0x40
#define IPDUM_TRIGGERTRANSMIT_API                               0x41
#define IPDUM_MAINFUNCTION_API                                  0x10
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
#define IPDUM_E_ALREADY_INITIALIZED                             0x06
#define IPDUM_E_PARAM                                           0x10
#define IPDUM_E_PARAM_POINTER                                   0x11
#define IPDUM_E_UNINIT                                          0x20
#define IPDUM_E_INIT_FAILED                                     0x21
#define IPDUM_E_HEADER                                          0x30
#define IPDUM_E_QUEUEOVFL                                       0x31
/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/
#define IPDUM_E_NO_ERROR                                         0xFFU
#define IPDUM_IGNORE_UNUSED_PARAM(param)                        ((void)(param))
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
extern void IpduM_Init(const IpduM_ConfigType* config);
extern void IpduM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
extern Std_ReturnType IpduM_Transmit(PduIdType PdumTxPduId, const PduInfoType* PduInfoPtr);
extern void IpduM_MainFunction(void);
#endif/* IPDUM_H */
