/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  SciDrv_Udma.h                                        *
*  Module Short Name :  SciDrv_Udma                                          *
*  Description       :  This file contains implementations of the SCI Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/



/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#ifndef SCIDRV_UDMA_H
#define SCIDRV_UDMA_H

#include "SciDrv_Types.h"

#if(DMA_PROVEOUT_ENABLED == STD_ON)

#include <stdint.h>
#include <stdbool.h>

/* SciDrv_Udma.h */
Std_ReturnType SciDrv_UdmaAttach(uint8 sw, uint32 udmaInstId, uint32 peerTx, uint32 peerRx);
Std_ReturnType SciDrv_UdmaSubmitTx(uint8 swChn, uint8 *buf, uint32 len);
Std_ReturnType SciDrv_UdmaPrimeRx(uint8 swChn, uint8 *buf, uint32 len);
void           SciDrv_UdmaDetach(uint8 swChn);


boolean SciDrv_UdmaTxDone(uint8 ChannelId);
boolean SciDrv_UdmaRxDone(uint8 ChannelId);
void    SciDrv_UdmaAckTx(uint8 ChannelId);
void    SciDrv_UdmaAckRx(uint8 ChannelId);
#endif /* DMA_PROVEOUT_ENABLED */

#endif /* SCIDRV_UDMA_H */
