///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclIL
/// UCL Interface Layer Implementation for Message Router. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILROUTER_IMPL_H
#define UCLILROUTER_IMPL_H

#include "UclILRouter.h"
#include "UclDLCbk_Types.h"
#include "UclCmnRingBuffer.h"

#define UCLILROUTER_IMPL_MAX_LOCAL_TIMERS (1u)

typedef struct SUclILRouterInst_t SUclILRouterInst;

///
/// @brief Callback function type for local timers
///
typedef void ( *TUclILRouterLocalTimerCbk ) ( SUclILRouterInst *pInst );

///
/// @brief Configuration data for UclILRouter_Impl.
///
/// The SUclDLCfg structure defines the constant configuration data for UclILRouter_Impl class.
///
typedef struct
{
    uint8 nodeId;                         ///< Node ID
    uint16 numMsgDbRxMsgs;                ///< Number of Receive Messages
    const SUclILMsgDbRx *pMsgDbRx;        ///< Receive message database
    uint16 periodicMsgCheckPeriodicityMs; ///< Periodicity of Periodicity check processing task
    uint16 timerTaskPeriodicityMs;        ///< Periodicity of Scheduler processing task
    uint16 rxWorkBufferSize;              ///< Size of the Receive work buffer
    uint8 *pRxWorkBuffer;                 ///< Work Buffer for Receive Messages
} SUclILRouterCfg;

///
/// @brief Private instance data for UclILRouter_Impl. \n
/// @ingroup UclIL
///
/// The SUclILRouterInst structure defines the private instance data for UclILRouter_Impl class.
///
struct SUclILRouterInst_t
{
    const SUclILRouterCfg *pCfg; ///< Configuration for the UclILRouter_Impl instance

    uint8 numIUclDL; ///< Number of connected UclDL instances
    uint8 *pIUclDL;  ///< Instance ID of the connected UclDL instances

    uint32 msgStatusFlagsMutexId;                                                ///< Id for the Mutex to protect Message Status Flags   
    uint32 timerTaskId;                                                          ///< Id for the TimerTask
    uint32 localTimers[UCLILROUTER_IMPL_MAX_LOCAL_TIMERS];                       ///< Array of local timers
    TUclILRouterLocalTimerCbk localTimersCbk[UCLILROUTER_IMPL_MAX_LOCAL_TIMERS]; ///< Array of local timers callbacks
};

///
/// @brief This method implements the Initialize API for the IUclILRouter Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Initialization Success
/// @return UCL_E_NOK   Initialization Failed
///
Ucl_ReturnType UclILRouter_Impl_IUclILRouter_Initialize ( SUclILRouterInst *pInst, uint8 InstId );

///
/// @brief This method implements the Shutdown API for the IUclILRouter Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Shutdown Success
/// @return UCL_E_NOK   Shutdown Failed
///
Ucl_ReturnType UclILRouter_Impl_IUclILRouter_Shutdown ( SUclILRouterInst *pInst, uint8 InstId );

///
/// @brief  This method will be called when UclDL encounters any
///         Fatal Error
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the Fatal Error
///
void UclILRouter_Impl_IUclDLCbk_FatalError ( SUclILRouterInst *pInst, uint8 InstId, uint8 Status );

///
/// @brief  This method will be called when UclDL receive a new
///         Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param pMsg   Pointer to the received Ucl Message
///
void UclILRouter_Impl_IUclDLCbk_MsgReceived ( SUclILRouterInst *pInst, uint8 InstId, EUclDLRxStatus Status,
        SUclDLMsg *pMsg );

///
/// @brief  This method will be called by the UclDL to notify
///         about the transmit status of the Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the requested transmission
///
void UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILRouterInst *pInst, uint8 InstId, uint16 MsgId,
        EUclDLAckStatus Status );

///
/// @brief  This method will be called by the UclDL to notify
///         about the change in the Link Status
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the UclDL Link
///
void UclILRouter_Impl_IUclDLCbk_LinkStatusChanged ( SUclILRouterInst *pInst, uint8 InstId, EUclDLLinkStatus Status );

#endif //UCLILROUTER_IMPL_H
