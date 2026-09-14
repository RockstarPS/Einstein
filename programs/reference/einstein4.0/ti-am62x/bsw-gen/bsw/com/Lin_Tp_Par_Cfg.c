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
* File Name         :  Lin_Tp_Par_Cfg.c                                      *
* Module Short Name :  LinIf                                                 *
* Description       :  Contains LinIp Funtional Implementations              *
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

#include "Lin_Tp_Cfg.h"
#include "LinTp_Types.h"
#include "LinTp_Par_Cfg.h"

/*This configurable array variable is used to store the details of RxNSdu
  @param - Control Index
  @param - NCR value
  @param - UpperLayerPduId
  @param - NAD
*/
LinTp_RxNSduType LinTp_RxNSdu[TP_MAX_RXNSDU] = {                
    /* Index    CtrlIdx  Ncr      UpperLayerPduId   NAD  */     
  { /*     0 */      0U, 0x0010U,       2,          0x01U },  
  { /*     1 */      0U, 0x0010U,       3,          0x00U }   
};

/*@brief This configurable array variable is used to store the details of control pointer
*/
LinTp_ControlType Tp_Ctrl_Ptr[1];

/*@brief Configure the LinTp channel number*/
uint8 LinTp_LinIfToLinTpChannel[1] = { 
    /* Index    Channel */
   /*     0 */ 0 
};

/*This configurable array variable is used to store the details of TxNSdu
  @param - Control Index
  @param - NAS value
  @param - NCS value
  @param - AssociatedRxNSduId
  @param - UpperLayerPduId
  @param - NAD
*/
LinTp_TxNSduType LinTp_TxNSdu[TP_MAX_TXNSDU] = {
    /* Index    CtrlIdx  Nas      Ncs      AssociatedRxNSduId  UpperLayerPduId    NAD          Comment                                                               Referable Keys */
  { /*     0 */      0U, 0x000BU, 0x0010U,                 0U,      1,            0x01U },  
  { /*     1 */      0U, 0x000BU, 0x0010U,                 1U,      2,            0x00U },  
  { /*     2 */      0U, 0x000BU, 0x0010U,               255U,      3,            0x7EU }   
};

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
