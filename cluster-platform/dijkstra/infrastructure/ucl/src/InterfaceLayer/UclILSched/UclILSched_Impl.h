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
/// UCL Interface Layer Implementation for Message Scheduler. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILSCHED_IMPL_H
#define UCLILSCHED_IMPL_H

#include "UclILSched.h"
#include "UclDLCbk_Types.h"
#include "UclCmnRingBuffer.h"

#define UCLILSCHED_IMPL_MAX_LOCAL_TIMERS (2u)

typedef struct SUclILSchedInst_t SUclILSchedInst;

///
/// @brief Callback function type for local timers
///
typedef void ( *TUclILSchedLocalTimerCbk ) ( SUclILSchedInst *pInst );

///
/// @brief Work data DL instances managed by UclILSched_Impl.
///
/// The SUclILSchedDLData structure defines the work data for DL instances.
///
typedef struct
{
    EUclDLLinkStatus linkStatus;                                ///< Link status of the DL Instance
    uint32 prioQueueLocks[eUclILMsgDbPriorityLevel_Last];       /// < Priority Queue Locks
    SUclCmnRingBuffer prioQueue[eUclILMsgDbPriorityLevel_Last]; /// < Priority Message Queues
} SUclILSchedDLData;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILSchedPrioQueueCfg structure defines the constant configuration data for Priority queues.
///
typedef struct
{
    uint8 *pData;
    uint16 size;
} SUclILSchedPrioQueueCfg;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILSchedDLCfg structure defines the constant configuration data for DL layers.
///
typedef struct
{
    uint8 numDestNodes;                                                  ///< Number of items in the Destination Node IDs list
    uint8 *pDestNodeIds;                                                 ///< Destination Node IDs list
    SUclILSchedPrioQueueCfg prioQueueCfg[eUclILMsgDbPriorityLevel_Last]; ///< Priority Queue Configurations
    SUclILSchedDLData *pData;                                            ///< Work data for the DL Instance
    uint16 txWorkBufferSize;                                             ///< Size of the Transmit work buffer
    uint8 *pTxWorkBuffer;                                                ///< Work Buffer for Transmit Messages
} SUclILSchedDLCfg;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILSchedCfg structure defines the constant configuration data for UclILSched_Impl class.
///
typedef struct
{
    uint8 nodeId;                    ///< Node ID
    uint16 numMsgDbTxMsgs;           ///< Number of Transmit Messages
    const SUclILMsgDbTx *pMsgDbTx;   ///< Transmit message database
    uint16 timerTaskPeriodicityMs;   ///< Periodicity of timre task
    uint16 schedulerPeriodicityMs;   ///< Periodicity of Scheduler processing task
    uint16 periodicMsgPeriodicityMs; ///< Periodicity of Periodic message processing task
    SUclILSchedDLCfg *pDLCfg;        ///< Configuration data for DL instances
    uint16 schedMsgRetryScratchBufferSize;  ///< Sched Retry Buffer Size
    uint8 *pSchedMsgRetryScratchBuffer; ///< Sched Buffer to Retry In-transit Msgs. Size of this buffer should be greatest of
    ///< the sum of all priority queue sizes of all DL instance
} SUclILSchedCfg;

///
/// @brief Private instance data for UclILSched_Impl. \n
/// @ingroup UclIL
///
/// The SUclILSchedInst structure defines the private instance data for UclILSched_Impl class.
///
struct SUclILSchedInst_t
{
    const SUclILSchedCfg *pCfg; ///< Configuration for the UclILSched_Impl instance

    uint8 numIUclDL; ///< Number of connected UclDL instances
    uint8 *pIUclDL;  ///< Instance ID of the connected UclDL instances
    uint8 isInitialized;
    uint32 msgStatusFlagsMutexId;                                              ///< Id for the Mutex to protect Message Status Flags
    uint32 msgSchedulerMutexId;                                                ///< Id for the Mutex to protect Message Scheduler
    uint32 timerTaskId;                                                        ///< Id for the TimerTask
    uint32 localTimers[UCLILSCHED_IMPL_MAX_LOCAL_TIMERS];                      ///< Array of local timers
    TUclILSchedLocalTimerCbk localTimersCbk[UCLILSCHED_IMPL_MAX_LOCAL_TIMERS]; ///< Array of local timers callbacks
};

///
/// @brief This method implements the Initialize API for the IUclILSched Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Initialization Success
/// @return UCL_E_NOK   Initialization Failed
///
Ucl_ReturnType UclILSched_Impl_IUclILSched_Initialize ( SUclILSchedInst *pInst, uint8 InstId );

///
/// @brief This method implements the Shutdown API for the IUclILSched Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Shutdown Success
/// @return UCL_E_NOK   Shutdown Failed
///
Ucl_ReturnType UclILSched_Impl_IUclILSched_Shutdown ( SUclILSchedInst *pInst, uint8 InstId );

///
/// @brief This method implements the Notification API for the IUclILSched Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
/// @param MsgIdx   Message index in the transmit database
/// @param DuIdx    DataUnit index in the transmit message
/// @param pBuffer  Pointer to the buffer (Valid for message based interface)
/// @param Size     Size of the buffer (Valid for message based interface)
///
/// @return None
///
void UclILSched_Impl_IUclILSched_NotifyMessageUpdate ( SUclILSchedInst *pInst, uint8 InstId, uint16 MsgIdx, uint16 DuIdx, uint8 *pBuffer, uint16 Size );

///
/// @brief  This method will be called when UclDL encounters any
///         Fatal Error
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the Fatal Error
///
void UclILSched_Impl_IUclDLCbk_FatalError ( SUclILSchedInst *pInst, uint8 InstId, uint8 Status );

///
/// @brief  This method will be called when UclDL receive a new
///         Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param pMsg   Pointer to the received Ucl Message
///
void UclILSched_Impl_IUclDLCbk_MsgReceived ( SUclILSchedInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg );

///
/// @brief  This method will be called by the UclDL to notify
///         about the transmit status of the Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the requested transmission
///
void UclILSched_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILSchedInst *pInst, uint8 InstId, uint16 MsgId,
        EUclDLAckStatus Status );

///
/// @brief  This method will be called by the UclDL to notify
///         about the change in the Link Status
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the UclDL Link
///
void UclILSched_Impl_IUclDLCbk_LinkStatusChanged ( SUclILSchedInst *pInst, uint8 InstId, EUclDLLinkStatus Status );

#endif //UCLILSCHEDL_IMPL_H
