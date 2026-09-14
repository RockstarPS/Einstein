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
*    @file CanSM_Cfg.h
*    @ingroup CanSM" Configuration
*    @brief This is CanSM Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the CanSM module.
*    Auto generated code in SVENKA24 at 2025-03-25 15:35:55.108502
********************************************************************************************************************/
#ifndef CANSM_CFG_H
#define CANSM_CFG_H

#include "SchM_CanSM.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define CANSM_CFG_SW_MAJOR_VERSION                               0U
#define CANSM_CFG_SW_MINOR_VERSION                               0U
#define CANSM_CFG_SW_PATCH_VERSION                               2U
/* Autosar Release */
#define CANSM_CFG_AR_RELEASE_MAJOR_VERSION                       4U
#define CANSM_CFG_AR_RELEASE_MINOR_VERSION                       2U
#define CANSM_CFG_AR_RELEASE_REVISION_VERSION                    1U
/*******************************************************************************************************************/
/*  Configuration Parameters                                                                                       */
/*******************************************************************************************************************/

#define CANSM_TRCV_HANDLING                              STD_ON
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF */
#define CANSM_DEV_ERROR_DETECT                           STD_ON
/*! @brief Activate/Deactivate the version information API  */
#define CANSM_VERSIONINFO_API                            STD_ON
/*! @brief  This parameter configures the name of the <User_GetBusOffDelay> call-out function,
            which is used by CanSM to acquire an additional L1/L2 delay time.This function is
            only called for channels where CanSMEnableBusOffDelay is enabled. */
#define CANSM_GET_BUS_OFF_DELAY_FUNCTION                 STD_ON
/*! @brief  Selects support of Pretended Network features in CanSM. */
#define CANSM_ICOM_SUPPORT                               STD_OFF
/*! @brief Enables or disables support of partial networking. */
#define CANSM_PNC_SUPPORT                                STD_OFF
/*! @brief  Enables or disables support Can_SetBaudrate API */
#define CANSM_SET_BAUD_RATE_API                          STD_OFF
/*! @brief  Determines whether the ECU passive feature is supported by CanSM. */
#define CANSM_TX_OFFLINE_ACTIVE_SUPPORT                  STD_OFF
/*! @brief  Activate/Deactivate the version information API (CanSM_GetVersionInfo). */
#define CANSM_VERSION_INFO_API                           STD_OFF
/*! @brief  Specifies Whether DEM event notification is enable or not */
#define CANSM_DEM_ERROR_REPORT                           STD_OFF
/*! @brief  This parameter defines the cycle time of the function CanSM_MainFunction in milliseconds */
#define CANSM_MAIN_FUNCTION_TIME_PERIOD                  10U
/*! @brief  Specifies the maximum amount of mode request repetitions without a respective mode indication from the CanIf
    module until the CanSM module reports a Default Error to the Det and tries to go back to no communication. */
#define CANSM_MODE_REQUEST_REPETITION_MAX                10U
/*! @brief  Specifies in which time duration(ms) the CanSM module shall repeat mode change requests by using the API
                of the CanIf module*/
#define CANSM_MODE_REQUEST_REPETITION_TIME               1U
#define CanSM_EnterCriticalSection()                     SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1()
#define CanSM_ExitCriticalSection()                      SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1()
#define CANSM_COMM_NUM_OF_NETWORKS                       2U
/*! @brief Defines the number of bus off configuration supported */
#define CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS              2U
/*! @brief Defines the number of number of networks supported */
#define CANSM_NUM_OF_NETWORKS                            2U
#define CANSM_INVALID_CHANNEL                            CANSM_NUM_OF_NETWORKS

#ifndef CANSM_DUMMY_STATEMENT
#define CANSM_DUMMY_STATEMENT(param) ((void)(param))
#endif

#endif /* CANSM_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


