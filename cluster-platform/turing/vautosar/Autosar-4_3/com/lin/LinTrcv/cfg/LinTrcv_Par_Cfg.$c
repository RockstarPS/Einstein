/****************************************************************
*              CONFIDENTIAL VISTEON CORPORATION
*
* This is an unpublished work of authorship, which contains trade secrets,
* created in 2012. Visteon Corporation owns all rights to this work and
* intends to maintain it in confidence to preserve its trade secret status.
* Visteon Corporation reserves the right, under the copyright laws of the
* United States or those of any other country that may have  jurisdiction,
* to protect this work as an unpublished work, in the event of an
* inadvertent or deliberate unauthorized publication. Visteon Corporation
* also reserves its rights under all copyright laws to protect this work as
* a published work, when appropriate. Those having access to this work may
* not copy it, use it, modify it or disclose the information contained in
* it without the written authorization of Visteon Corporation
*
****************************************************************/
#ifndef LINTRCV_PAR_CFG_C
#define LINTRCV_PAR_CFG_C

#include "LinTrcv_Par_Cfg.h"
#include "Dio_Cfg.h"

/*=============================================================================
*
*  Name:               LinTrcv_Par_Cfg.c
*
*  Description:
*
*  Comments:
*
*
*  Organization:       Driver Information Core Software,
*                      Visteon Automotive Systems
**==========================================================================*/

//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_ChannelUsed       
//                 
// TYPE:    LinTrcv_ChannelUsedType       
//                                                                                                                      
// DESCRIPTION: Configuration to make the Trancsceiver Channel Enable 
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_ChannelUsedType LinTrcv_ChannelUsed[NO_OF_LIN_CHANNEL_USED] = {
  /* Index    ChannelUsed  */
  /*     0 */        TRUE
};

//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_InitState       
//                 
// TYPE:    LinTrcv_TrcvModeType       
//                                                                                                                      
// DESCRIPTION:  Init state of the transceiver normal -  LINTRCV_OP_MODE_NORMAL
//               Init state of the transceiver sleep  -  LINTRCV_OP_MODE_SLEEP
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_TrcvModeType LinTrcv_InitState[NO_OF_LIN_CHANNEL_USED] = {
    /* Index                 */
    /*     0 */ LINTRCV_OP_MODE_NORMAL
};

//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_DioConfiguration       
//                 
// TYPE:    LinTrcv_DioConfigurationType       
//                                                                                                                      
// DESCRIPTION: DioChannel Pin mapping for the the PinEn , PinTx and PinRx 
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_DioConfigurationType LinTrcv_DioConfiguration[NO_OF_LIN_CHANNEL_USED] = {
    /* Index    PinEN                         PinTXD                        PinRXD                         */
  /* { DioConf_DioChannel_LIN_EN, DioConf_DioChannel_LIN_TX, DioConf_DioChannel_LIN_RX } */
  { /*     0 */ 106, 107, 108 }
};


//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_Icu_Channel       
//                 
// TYPE:    LinTrcv_Icu_ChannelType       
//                                                                                                                      
// DESCRIPTION: ICU Channel Mapping for the Transceiver
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_Icu_ChannelType LinTrcv_Icu_Channel[NO_OF_LIN_CHANNEL_USED] = {
    /* Index    IcuChannelSet  IcuChannel                              */
    /* {        TRUE, IcuConf_IcuChannel_IcuChannel_LinWakeup } */
  { /*     0 */          FALSE, 0 }
};


//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_WakeupByBusUsed       
//                 
// TYPE:    LinTrcv_WakeupByBusUsedType       
//                                                                                                                      
// DESCRIPTION: Configuration to enable wakeup by bus
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_WakeupByBusUsedType LinTrcv_WakeupByBusUsed[NO_OF_LIN_CHANNEL_USED] = {

  TRUE
};

//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_WakeupByPinUsed       
//                 
// TYPE:    LinTrcv_WakeupByPinUsedType       
//                                                                                                                      
// DESCRIPTION: Configuration to enable wakeup by PIN
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_WakeupByPinUsedType LinTrcv_WakeupByPinUsed[NO_OF_LIN_CHANNEL_USED] = {
 
  FALSE
};

//----------------------------------------------------------------------------------------------------------------------
// NAME:    LinTrcv_WakeSourceId       
//                 
// TYPE:    LinTrcv_WakeSourceIdType       
//                                                                                                                      
// DESCRIPTION: 
//----------------------------------------------------------------------------------------------------------------------

const LinTrcv_WakeSourceIdType LinTrcv_WakeSourceId[NO_OF_LIN_CHANNEL_USED] = {
  0x00000000UL
};

#endif
/*============================================================================
**Date               : 22-Jul-2019
**CDSID              : ABAVALAT
**Traceability       : 
**Change Description : Initial Version.
**============================================================================*/
