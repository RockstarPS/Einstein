//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
/*****************************************************************************
* File Name         :  Lin_Tp_cfg.h                                      *
* Module Short Name :  LinTp                                                 *
* Description       :  Contains LinTp Configuration               *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing C                                               *
*                                                                            *
*****************************************************************************/
#ifndef LIN_TP_CFG_H
#define LIN_TP_CFG_H

#include "LinTp_Types.h"

/*********************************************************************************************************************
*                                 #! LinTp SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the LinTp configuration software Major version */
#define LINTP_CFG_SW_MAJOR_VERSION                    	   1u
/*! @brief Defines the LinTp configuration software Minor version */
#define LINTP_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the LinTp configuration software Patch version */
#define LINTP_CFG_SW_PATCH_VERSION                          0u

/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by LinTp configuration  */
#define LINTP_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by LinTp configuration  */
#define LINTP_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by LinTp configuration  */
#define LINTP_CFG_AR_RELEASE_REVISION_VERSION               1u

/*@brief This macro is used to configure maximum RxNSDu */
#define TP_MAX_RXNSDU       2U

/*@brief This macro is used to configure maximum TxNSDu */
#define TP_MAX_TXNSDU       3U

/**< the pointer to LinTp_RxNSdu */
#define LinTp_GetRxNSduOfPCConfig()                                   LinTp_RxNSdu  

/**< Max number of RP frames */
#define MAX_NO_OF_RP_FRAMES                                             0x0003U                     

/*P2 timer's maximum count for reload */
#define LIN_TP_P2_MAX_COUNT                                           0x50u

/*@brief This function-like macro is used to get the NAD of RxNSdu*/
#define LinTp_GetNADOfRxNSdu(Index)                                   (LinTp_RxNSdu[(Index)].NADOfRxNSdu)

/*@brief This function-ike macro is used to get the number of Response Pending Frames when RCRRP is received*/
#define LinTp_MaxRespPendingFrames_Config()                           MAX_NO_OF_RP_FRAMES    

/*@brief This function-ike macro is used to get Ncr timeout in ticks */
#define LinTp_GetNcrOfRxNSdu(Index)                                   (LinTp_RxNSdu[(Index)].NcrOfRxNSdu)

/*@brief This function-ike macro is used to get RxNSdu external ID */
#define LinTp_GetUpperLayerPduIdOfRxNSdu(Index)                       (LinTp_RxNSdu[(Index)].UpperLayerPduIdOfRxNSdu)

/*@brief This function-like macro is used to get control of the Tp Data Pointer*/
#define LinTp_GetCtrl(Index)                                          (Tp_Ctrl_Ptr[(Index)])

/*@brief This function-like macro is used to get the pointer to LinTp_LinIfToLinTpChannel */
#define LinTp_GetChannelOfLinIfToLinTpChannel(Index)                  (LinTp_LinIfToLinTpChannel[(Index)].ChannelOfLinIfToLinTpChannel)

/*@brief This function-like macro is used to get the size of control pointer */
#define LinTp_GetSizeOfCtrl()                                           1u

/*@brief This function-like macro is used to get the address of control pointer variable */
#define LinTp_GetAddrCtrl(Index)                                        &LinTp_GetCtrl(Index)

/*@brief This function-like macro is used to get the maximum P2 timer value for reloading */
#define LinTp_GetP2Time()                                               0x0Au

#endif
/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================

**============================================================================
**Date               : 15-APRIL-2020
**CDSID              : LMAHENDR
**Traceability       : RTC 
**Change Description : Initial version
**============================================================================
*/
/**********************************************************************************************************************
 *  END OF FILE: LinTp_Cfg.h
 *********************************************************************************************************************/


