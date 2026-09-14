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
#ifndef LINTP_PAR_CFG_H
#define LINTP_PAR_CFG_H

#include "LinTp_Types.h"
#include "Lin_Tp_Cfg.h"


/*This configurable array variable is used to store the details of RxNSdu
  @param - Control Index
  @param - NCR value
  @param - UpperLayerPduId
  @param - NAD
*/
extern LinTp_RxNSduType LinTp_RxNSdu[TP_MAX_RXNSDU];

/*@brief This configurable array variable is used to store the details of control pointer
*/
extern LinTp_ControlType Tp_Ctrl_Ptr[1];

/*@brief This configurable array variable is used to Configure the LinTp channel number*/
extern uint8 LinTp_LinIfToLinTpChannel[1];

/*This configurable array variable is used to store the details of TxNSdu
  @param - Control Index
  @param - NAS value
  @param - NCS value
  @param - AssociatedRxNSduId
  @param - UpperLayerPduId
  @param - NAD
*/
extern LinTp_TxNSduType LinTp_TxNSdu[TP_MAX_TXNSDU];


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


