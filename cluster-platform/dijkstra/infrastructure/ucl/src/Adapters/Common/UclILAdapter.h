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
/// @defgroup UclILAdapter
/// @brief UCL Adapter Layer handles interface with the communication framework
/// @file
/// @ingroup UclILAdapter
/// UCL Adapter Layer Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILADAPTER_H
#define UCLILADAPTER_H

#include "UclILAdapter_Types.h"
#include "UclVmfAdapterConfig.h" //Fix: warning: implicit declaration of function 'UclVmfProxy_AddVmfMsgToTxQueue'

#ifdef __cplusplus
extern "C" {
#endif


/// Generated APIs implemented by the Adapter
extern void UclGen_Adapter_ErrorNotification ( uint8 DLInst, sint32 ErrorCode );
extern void UclGen_Adapter_LinkStatusChanged ( uint8 DLInst, sint32 Status );
extern void UclGen_Adapter_MessageTransmitStatus ( uint16 MsgId, sint32 Status );
extern void UclGen_Adapter_ReceiveMissingStatus ( uint16 MsgId, sint32 Status );
extern void UclGen_AsrAdapterInit(void);

///
/// @brief This method is used to send Error Notification to the Adapter
///
/// @param DLInst Instance Id to Data Layer
/// @param ErrorCode Error Code.
///
/// @return None
///
#define UCLILAdapter_ErrorNotification UclGen_Adapter_ErrorNotification

///
/// @brief This method is used to send Link Status to the Adapter
///
/// @param DLInst Instance Id to Data Layer
/// @param Status Link Status.
///
/// @return None
///
#define UCLILAdapter_LinkStatusChanged UclGen_Adapter_LinkStatusChanged

///
/// @brief This method is used to send the message transmit status to the Adapter
///
/// @param MsgId Message Id
/// @param Status Message Transmit Status.
///
/// @return None
///
#define UCLILAdapter_MessageTransmitStatus UclGen_Adapter_MessageTransmitStatus

///
/// @brief This method is used to send the message missing status to the Adapter
///
/// @param MsgId Message Id
/// @param Status Message Missing Status.
///
/// @return None
///
#define UCLILAdapter_ReceiveMissingStatus UclGen_Adapter_ReceiveMissingStatus

#ifdef __cplusplus
}
#endif
#endif //UCLILADAPTER_H
