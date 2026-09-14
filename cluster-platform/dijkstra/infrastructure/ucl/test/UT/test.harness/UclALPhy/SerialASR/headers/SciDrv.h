//---------------------------------------------------------------------------------------------------------------------
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

#ifndef SCIDRV_H
#define SCIDRV_H

#include "SciDrv_Types.h"
#include "SciDrv_Cfg.h"

//=====================================================================================================================
//  Function Prototype Declarations
//=====================================================================================================================
extern Std_ReturnType SciDrv_Init(const SSciDrvCfg *pConfig);
extern void SciDrv_DeInit(void);
extern ESciDrvStatus SciDrv_GetStatus(void);
extern Std_ReturnType SciDrv_EnableChn(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_DisableChn(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_SetupEB(TSciDrvChn SciDrvChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length);
extern Std_ReturnType SciDrv_WriteIB(TSciDrvChn SciDrvChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length);
extern Std_ReturnType SciDrv_ReadIB(TSciDrvChn SciDrvChn, ESciDrvDirection Direction, uint8* pBuffer, uint16 Length);
extern Std_ReturnType SciDrv_ASyncTransmit(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_ASyncReceive(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_SetAsyncMode(TSciDrvChn SciDrvChn, ESciDrvAsyncMode SciDrvMode);
extern Std_ReturnType SciDrv_Cancel(TSciDrvChn SciDrvChn, ESciDrvDirection Direction);
extern ESciDrvChnResult SciDrv_GetChnResult(TSciDrvChn SciDrvChn, ESciDrvDirection Direction, uint32 *pLength);
extern Std_ReturnType SciDrv_SyncTransmit(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_SyncReceive(TSciDrvChn SciDrvChn);
extern Std_ReturnType SciDrv_SetSyncMode(TSciDrvChn SciDrvChn, ESciDrvSyncMode SciDrvMode);
extern Std_ReturnType SciDrv_SetLoopBackMode(TSciDrvChn SciDrvChn, uint8 bEnable);

//=====================================================================================================================
//  DMA Hooks
//=====================================================================================================================
extern void SciDrv_HwTransmitDMACallback(const TSciDrvChn SciDrvHwChn);
extern void SciDrv_HwReceiveDMACallback(const TSciDrvChn SciDrvHwChn);

//=====================================================================================================================
//  ISR Hooks
//=====================================================================================================================
extern void SciDrv_TransmitISR(const TSciDrvChn SciDrvHwChn);
extern void SciDrv_ReceiveISR(const TSciDrvChn SciDrvHwChn);
extern void SciDrv_ErrorISR(const TSciDrvChn SciDrvHwChn);

#endif /* SCIDRV_H */
