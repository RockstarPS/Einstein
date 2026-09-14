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

#ifndef SCIDRV_TYPES_H
#define SCIDRV_TYPES_H

#include "Std_Types.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
///@brief Sci driver channel ID.
typedef uint8  TSciDrvChn;

///@brief Enum holding the state of SCI driver.
typedef enum ESciDrvStatus_t {
    // The SCI Driver is not initialized or not usable
    eSciDrvStatus_Uninit,
    // The SCI Driver is ready for use
    eSciDrvStatus_Ready,
    // Last Entry
    eSciDrvStatus_Last
} ESciDrvStatus;

///@brief Enum holding the status of SCI channel job.
typedef enum ESciDrvChnResult_t {
    // The last transfer on the SCI Channel has been finished successfully
    eSciDrvChnResult_Ok,
    // The SCI Driver is performing a transfer on the SCI Channel
    eSciDrvChnResult_Busy,
    // The last transfer on the SCI Channel has failed
    eSciDrvChnResult_Failed,
    // The last transfer on the SCI Channel has been cancelled by user
    eSciDrvChnResult_Cancelled,
    // Last Entry
    eSciDrvChnResult_Last
} ESciDrvChnResult;


///@brief Enum holding the Async mode of SCI channel.
typedef enum ESciDrvAsyncMode_t {
    // The SCI driver will use polling mode to perform the Aysnc Transfer
    eSciDrvAsyncMode_Polling,
    // The SCI driver will use Interrupt to perform the Aysnc Transfer
    eSciDrvAsyncMode_Interrupt,
    // The SCI driver will use DMA to perform the Aysnc Transfer
    eSciDrvAsyncMode_Dma,
    // Last Entry
    eSciDrvAsyncMode_Last
} ESciDrvAsyncMode;

///@brief Enum holding the Sync mode of SCI channel.
typedef enum ESciDrvSyncMode_t {
    // The SCI driver will use polling mode to perform the Sync Transfer
    eSciDrvSyncMode_Polling,
    // Last Entry
    eSciDrvSyncMode_Last
} ESciDrvSyncMode;

///@brief Enum holding the Direction of SCI channel.
typedef enum ESciDrvDirection_t {
    // Receive direction
    eSciDrvDirection_Receive,
    // Transmit direction
    eSciDrvDirection_Transmit,
    // Last Entry
    eSciDrvDirection_Last
} ESciDrvDirection;

#endif /* SCIDRV_TYPES_H */
