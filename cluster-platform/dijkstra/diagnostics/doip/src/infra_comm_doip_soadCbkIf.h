//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
///
/// @file infra_comm_ooip_soadCbkIf.h
/// @ingroup DOIP
///
/// @brief  CSoAdCallbackIf Class. CSoAdCallbackIf is an interface class. It provides the interafce between Socket Adapter and DoIP
///  message handler. The Recived message from TCP/IP or UDP stack will be notified to the DoIP handler to process the received
///  message.
/// It Provides infrastructure for
///         * Receiving a message from SOAD (TCP/IP or UDP) and notify to DOIP Handler.
//---------------------------------------------------------------------------------------------------------------------
#ifndef INFRA_COMM_DOIP_SOADCBKIF_H
#define INFRA_COMM_DOIP_SOADCBKIF_H

#include<vector>

class CSoAdCallbackIf
{

public:
    ///
    /// @brief This method should be invoked by SOAD on receive data over TCP/IP or UDP stack
    /// @param[in] socketId ID of data received connection. If Data come from different client,
    ///                  the socketId should be difefrent.
    /// @param[in] rxBuffer Buffer to store the received data.
    ///
    virtual void messageReceived ( bool isUdp, uint8_t vlanNo,uint8_t socketId, const std::vector<uint8_t> *rxBuffer, const void *clientAddr ) = 0;
    virtual void tcpConnectionEstablished ( uint8_t socketId, uint8_t vlanNo ) = 0;
    virtual void tcpSocketClose( uint8_t socketId,uint8_t vlanNo) = 0;
};


#endif  //INFRA_COMM_DOIP_SOADCBKIF_H