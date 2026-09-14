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
/// @defgroup UclIL
/// @brief UCL Interface Layer handles Scheduling, Routing, Priority Management etc.
/// @file
/// @ingroup UclIL
/// UCL Interface Layer Message Database Type Definitions.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILMSGDBTYPES_H
#define UCLILMSGDBTYPES_H

#include "Ucl_Types.h"
#include "UclILAdapter_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief UCL Transmit Message Status
///
typedef uint8 EUclILMsgDbTxMsgStatus;

//MISRA C++-2008 Rule 2-13-4

#define  eUclILMsgDbTxMsgStatus_Idle (EUclILMsgDbTxMsgStatus)0x00U        ///< Message status is Idle
#define  eUclILMsgDbTxMsgStatus_ReadyToSend (EUclILMsgDbTxMsgStatus)0x01U ///< Message is Ready To Send
#define  eUclILMsgDbTxMsgStatus_Deferred (EUclILMsgDbTxMsgStatus)0x02U    ///< Message is Deferred due to minimum distance constraints
#define  eUclILMsgDbTxMsgStatus_WaitForAck (EUclILMsgDbTxMsgStatus)0x04U  ///< Message waiting for acknowledge
#define  eUclILMsgDbTxMsgStatus_Retry (EUclILMsgDbTxMsgStatus)0x08U       ///< Message scheduled for retry
#define  eUclILMsgDbTxMsgStatus_Error (EUclILMsgDbTxMsgStatus) 0x10U      ///< Error while transmit
#define  eUclILMsgDbTxMsgStatus_SendOnInit (EUclILMsgDbTxMsgStatus)0x20U  ///< Message scheduled for Tx on Init
#define  eUclILMsgDbTxMsgStatus_Last (EUclILMsgDbTxMsgStatus) 0x40U       /*Guard*/

///
/// @brief UCL Receive Message Status
///
typedef uint8 EUclILMsgDbRxMsgStatus;
#define  eUclILMsgDbRxMsgStatus_Idle (EUclILMsgDbRxMsgStatus) 0x00U     ///< Message status is Idle
#define  eUclILMsgDbRxMsgStatus_Missing (EUclILMsgDbRxMsgStatus) 0x01U  ///< Message not reeived withing timeout
#define  eUclILMsgDbRxMsgStatus_Error (EUclILMsgDbRxMsgStatus)0x02U     ///< Error while reception
#define  eUclILMsgDbRxMsgStatus_Recvd (EUclILMsgDbRxMsgStatus)0x03U     ///< Message received
#define  eUclILMsgDbRxMsgStatus_Last (EUclILMsgDbRxMsgStatus) 0x4U     ///< Guard
///
/// @brief UCL Message Tranmsit Scheduling Attribute
///
typedef enum EUclILMsgDbSchedAttrib_t
{
    eUclILMsgDbSchedAttrib_OnChange, ///< Message sent when a signal is changed
    eUclILMsgDbSchedAttrib_OnWrite,  ///< Message sent when a signal is updated
    eUclILMsgDbSchedAttrib_Periodic, ///< Periodic message
    eUclILMsgDbSchedAttrib_Last      ///< Guard
} EUclILMsgDbSchedAttrib;

///
/// @brief UCL Message Priority Level Definitions
///
typedef uint8 EUclILMsgDbPriorityLevel;
#define eUclILMsgDbPriorityLevel_Critical (EUclILMsgDbPriorityLevel)0x00U   ///< Critical message. Highest priority.
#define eUclILMsgDbPriorityLevel_High (EUclILMsgDbPriorityLevel)0x01U        ///< High priority message
#define eUclILMsgDbPriorityLevel_Medium (EUclILMsgDbPriorityLevel)0x02U      ///< Medium priority message
#define eUclILMsgDbPriorityLevel_Low (EUclILMsgDbPriorityLevel)0x03U         ///< Low priority message
#define eUclILMsgDbPriorityLevel_Last (EUclILMsgDbPriorityLevel)0x04U       ///< Guard

///
/// @brief UCL Message Security Level Definitions
///
typedef enum EUclILMsgDbSecurityLevel_t
{
    eUclILMsgDbSecurityLevel_Unsecure,      ///< Unsecure message. Protected with checksum
    eUclILMsgDbSecurityLevel_Authenticated, ///< Authenticated message. Protected with CMAC
    eUclILMsgDbSecurityLevel_Encrypted,     ///< Encrypted message. Encrypted with CBC
    eUclILMsgDbSecurityLevel_Reserved,      ///< Reserved
    eUclILMsgDbSecurityLevel_Last           ///< Guard
} EUclILMsgDbSecurityLevel;

///
/// @brief UCL Message Signal Type Definitions
///
typedef enum EUclILMsgDbSignalType_t
{
    eUclILMsgDbSignalType_Data,  ///< Data Signal Type
    eUclILMsgDbSignalType_Event, ///< Event Signal Type
    eUclILMsgDbSignalType_Last   ///< Guard
} EUclILMsgDbSignalType;

///
/// @brief Holds the work data of the transmit message
///
/// The SUclILMsgDbTxWork structure defines the work data for Transmit messages
///
typedef struct
{
    EUclILMsgDbTxMsgStatus flags; ///< Message Status Flags
    uint64 timeStampMs;           ///< Message last sent timestamp
} SUclILMsgDbTxWork;

///
/// @brief Holds the work data of the received message
///
/// The SUclILMsgDbRxWork structure defines the work data for received messages
///
typedef struct
{
    EUclILMsgDbRxMsgStatus flags; ///< Message Status Flags
    uint64 timeStampMs;           ///< Message last received timestamp
} SUclILMsgDbRxWork;

///
/// @brief Structure for the Ucl Message Database Transmit Signal
///
/// The SUclILMsgDbTxSignal structure holds the details for the transmit signal
///
typedef struct SUclILMsgDbTxSignal_t
{
    uint8 signalId;                       ///< Signal Id. Unique within the message
    EUclILMsgDbSignalType signalType;     ///< Signal Type
    uint16 size;                          ///< Size of the Signal
    TUclTxSignalAdapterFunc pAdapterFunc; ///< Signal Adapter Function
} SUclILMsgDbTxSignal;

///
/// @brief Structure for the Ucl Message Database Receive Signal
///
/// The SUclILMsgDbRxSignal structure holds the details for the receive signal
///
typedef struct SUclILMsgDbRxSignal_t
{
    uint8 signalId;                       ///< Signal Id. Unique within the message
    EUclILMsgDbSignalType signalType;     ///< Signal Type
    uint16 size;                          ///< Size of the Signal
    TUclRxSignalAdapterFunc pAdapterFunc; ///< Signal Adapter Function
} SUclILMsgDbRxSignal;

///
/// @brief Structure for the Ucl Message Tranmsit Data Unit Type
///
/// The SUclILMsgDbTxDataUnit structure holds the details for the transmit data unit
///
typedef struct SUclILMsgDbTxDataUnit_t
{
    uint16 dataUnitId;                       ///< Data UnitId
    uint16 numSignals;                       ///< Number of Signals (Signal Based)
    const SUclILMsgDbTxSignal *pSignalList;  ///< Signal List (Signal Based)
    uint16 msgSize;                          ///< Size of the message (Message Based)
    TUclTxMessageAdapterFunc pMsgAdapterFunc; ///< Adapter Function for transmit DataUnits (Message Based)
} SUclILMsgDbTxDataUnit;

///
/// @brief Structure for the Ucl Message Receive Data Unit Type
///
/// The SUclILMsgDbRxDataUnit structure holds the details for the receive data unit
///
typedef struct SUclILMsgDbRxDataUnit_t
{
    uint16 dataUnitId;                        ///< Data UnitId
    uint16 numSignals;                        ///< Number of Signals (Signal Based)
    const SUclILMsgDbRxSignal *pSignalList;   ///< Signal List (Signal Based)
    uint16 msgSize;                           ///< Size of the message (Message Based)
    TUclRxMessageAdapterFunc pMsgAdapterFunc; ///< Adapter Function for Received DataUnits (Message Based)
} SUclILMsgDbRxDataUnit;

///
/// @brief Structure for the Ucl Message Transmit Database
///
/// The SUclILMsgDbTx structure holds the details for the transmit messages
///
typedef struct SUclILMsgDbTx_t
{
    uint16 msgId;                               ///< Message Id
    uint8 destNodeId;                           ///< Destination Node Id
    uint16 periodictyMs;                        ///< Periodicity of the message
    EUclILMsgDbSecurityLevel securityLevel;     ///< Security Level
    EUclILMsgDbPriorityLevel priorityLevel;     ///< Priority Level
    EUclILMsgDbSchedAttrib schedAttrib;         ///< Scheduler Attribute
    uint8 notifyTxStatus;                       ///< Generates Transmit Status Notification if TRUE
    uint8 sendOnInit;                           ///<Send the Default value on Init>
    SUclILMsgDbTxWork *pWork;                   ///< Transmit work data
    uint16 numDataUnits;                        ///< Number of Data units
    const SUclILMsgDbTxDataUnit *pDataUnitList; ///< Data Unit List
} SUclILMsgDbTx;

///
/// @brief Structure for the Ucl Message Receive Database
///
/// The SUclILMsgDbRx structure holds the details for the received messages
///
typedef struct SUclILMsgDbRx_t
{
    uint16 msgId;                               ///< Message Id
    uint16 periodictyMs;                        ///< Periodicity of the message
    uint8 notifyRxMissingStatus;                ///< Generates Receive Missing Notification if TRUE
    SUclILMsgDbRxWork *pWork;                   ///< Receive work data
    uint16 numDataUnits;                        ///< Number of Data units
    const SUclILMsgDbRxDataUnit *pDataUnitList; ///< Data Unit List
} SUclILMsgDbRx;

#ifdef __cplusplus
}
#endif
#endif //UCLILMSGDBTYPES_H
