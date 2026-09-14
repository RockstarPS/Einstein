/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2024. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  Lin_Cfg.h
Module Short Name:  Lin_Cfg.h
VOBName          :  
Author           :  mhishamu
Description      :  This file contains configurations needed for Lin module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef LIN_CFG_H
#define LIN_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "Platform_Types.h"
#include "SciDrv_Irq.h"
#include "EcuM_Types.h"
#include "SciDrv_Types.h"
#include "Dem_Types.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define Lin_EnterCriticalSection()
#define Lin_ExitCriticalSection()

/**
* @brief Enables / Disables version info API
*/
#define LIN_VERSION_INFO_API    (STD_ON)

/**
* @brief Max number of channels supported by Lin Driver.
*/
#define LIN_NUM_OF_CHANNELS     1U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/**
* @brief    Lin Channel Id Type
*/
typedef uint8 Lin_ChannelIdType;

/**
* @brief LIN Channel Configuration Type
*/
typedef struct
{
    /* LIN Channel Baudrate */
    uint32 ChannelBaudRate;
    /* LIN Channel ID */
    Lin_ChannelIdType ChannelId;
    /* LIN Channel Wakeup Support */
    boolean LinChannelWakeupSupport;
    /* LIN Channel EcuM Wakeup Support */
    EcuM_WakeupSourceType LinChannelEcuMWakeupSource;
    /* LIN Clock Reference */
    uint32 ClockRef;
    /* LIN Breaklength */
    uint8 BreakLength;
    /* SciDrv Channel ID */
    TSciDrvChn SciDrvChn;
} Lin_ChannelConfigType;

/**
* @brief LIN Configuration Type
*/
typedef struct 
{
    /* LIN Channel */
    const Lin_ChannelConfigType* Lin_Channel;
    /* LIN number of Channels  */
    Lin_ChannelIdType NumOfChannel;
    /* Dem Event Parameter  */
    Dem_EventIdType DemEventParameter;
} Lin_ConfigType;

/**
* @brief LIN Driver States
*/
typedef enum
{
    /* LIN Uninitialized State */
    LIN_UNINIT = 0,
    /* LIN Initialized State */
    LIN_INIT = 1
}Lin_InitStatusType;

/**
* @brief Channel Info Type
*/
typedef struct
{
    /* LIN Channel Status */
    uint8 ChStatus;
    /* LIN Frame Status */
    uint8 ChFrameStatus;
    /* LIN Header Status */
    uint8 ChHeaderStatus;
    /* LIN Transmit Header Command */
    uint8 TransmitHeaderCommand;
    /* LIN Channel Frame Error Status */
    uint8 LinChFrameErrorStatus;
}Lin_ChannelInfoType;

/*****************************************************************************
*                                 Global Functions                           *
******************************************************************************/
/******************************************************************************
* @brief   Rx Callback for Channel 0
* @details This function is called when a LIN frame is 
*          successfully received on Channel 0.
*
* @param[in] Channel, ReceiveResult,
*            SciBytesReceived, SciExtraBytesReceived.
* @return            void.
*
******************************************************************************/
void Lin_UartIf_RxIndication_0(ESciDrvChnResult ReceiveResult, uint32 SciBytesReceived, uint32 SciExtraBytesReceived);

/******************************************************************************
* @brief   Callback function upon successful transmission
* @details This function is called when a LIN frame is 
*          successfully transmitted.
*
* @param[in] Channel, TransmitResult.
*
* @return            void.
*
******************************************************************************/
void Lin_UartIf_TxConfirmation(uint8 Channel, ESciDrvChnResult TransmitResult);

/******************************************************************************
* @brief   Callback function upon successful reception
* @details This function is called when a LIN frame is 
*          successfully received.
*
* @param[in] Channel, ReceiveResult,
*            SciBytesReceived, SciExtraBytesReceived.
* @return            void.
*
******************************************************************************/
void Lin_UartIf_RxIndication(uint8 Channel, ESciDrvChnResult ReceiveResult, uint32 SciBytesReceived, uint32 SciExtraBytesReceived);

#endif /* LIN_CFG_H */

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : -05-2024                                              */
/*Version           :                                                       */
/*By                : mhishamu                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/