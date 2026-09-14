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
*    @file CanTp_Lcfg.c
*    @ingroup CanTp Configuration
*    @brief This is CanTp Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the CanTp module.
*    Auto generated code in GARUMUG1 at 2023-02-03 22:46:37.113321
********************************************************************************************************************/
/*******************************************************************************************************************
*  HEADER INCLUDES                                                                                                 *
********************************************************************************************************************/

#include "CanTp.h"
#include "PduR_CanTp.h"
#include "PduR_Cfg.h"
#include "CanIf.h"

/*******************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                         *
********************************************************************************************************************/

/* @brief pointer to the CanTp configuration used in CanTp_Init . No PB config , hence the value is NULL_PTR  */
const CanTp_ConfigType *CanTp_ConfigPtr = NULL_PTR;


/* @brief The Lookup table for the CanTp Tx PDU Id to CanTp Tx NSDU Map */
const CanTp_NSduIdType CanTp_TxPduToNsduMap[CANTP_TXNSDU_PDUID_NUM_OF_PDUID]=
{
    CANTP_PDU_E4_DIAG_RES,   /// DBC Message
};

/* @brief The Lookup table for the CanTp Rx PDU Id to CanTp Rx NSDU Map */
const CanTp_NSduIdType CanTp_RxPduToNsduMap[CANTP_RXNSDU_PDUID_NUM_OF_PDUID]=
{
    CANTP_PDU_E4_DIAG_PHY_REQ,    //DBC
    CANTP_PDU_E4_DIAG_FUNC_REQ, //DBC 
};
/* @brief Defines the configuration table for each CAN N-SDU that the CanTp module transmit via the CanTpChannel 
For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
const CanTp_TxNSduConfigType CanTp_TxNSduConfig[CANTP_NUM_OF_TX_NSDU]=
{
    {  200U,  200U,  180U,  FALSE,  CANTP_STANDARD,  CANTP_ON,  CANTP_CANFD_PHYSICAL,  CANTP_CHANNEL_CANTPCHANNEL0,  64U,  PDUR_SRC_E4_DIAG_RES,  CANIF_PDU_E4_DIAG_RES,  CANTP_RXNSDU_E4_DIAG_PHY_REQ }, /* 0 E4_DIAG_RES */
};

/* @brief The configuration table for each CAN N-SDU that the CanTp module receives via the CanTpChannel .
For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
const CanTp_RxNSduConfigType CanTp_RxNSduConfig[CANTP_NUM_OF_RX_NSDU]=
{
    {  20U,  100U,  200U,  0U,  0U,  0U,  CANTP_STANDARD,  CANTP_ON,  CANTP_CANFD_PHYSICAL,  CANTP_CHANNEL_CANTPCHANNEL0,  PDUR_SRC_E4_DIAG_PHY_REQ,  CANTP_TXNSDU_E4_DIAG_RES,  CANIF_PDU_E4_DIAG_RES, TRUE}, /* 0 E4_DIAG_PHY_REQ */
    {  20U,  100U,  200U,  0U,  0U,  0U,  CANTP_STANDARD,  CANTP_ON,  CANTP_CANFD_FUNCTIONAL,  CANTP_CHANNEL_CANTPCHANNEL1,  PDUR_SRC_E4_DIAG_FUNC_REQ,  CANTP_TXNSDU_E4_DIAG_RES,  CANIF_PDU_E4_DIAG_RES, TRUE}, /* 1 E4_DIAG_FUNC_REQ */
};

/* @brief Configuration table for the supported channels */
const CanTp_ChannelConfigType CanTp_ChannelConfig[CANTP_NUM_OF_CHANNELS]=
{
    {  CANTP_MODE_FULL_DUPLEX,  0U,  0U,  0U,  0U }, /* 0 CanTpChannel0 */
    {  CANTP_MODE_FULL_DUPLEX,  0U,  0U,  1U,  1U }, /* 1 CanTpChannel1 */
};

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


