//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Tue May 26 11:48:08 IST 2026
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef DLT_GATEWAY_COMPONENT_H
#define DLT_GATEWAY_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_dlt_gateway_component.h"
#include "dk_runtime_parserif.h"
#include "dlt_gateway_tcp_server.h"
#include "dlt_gateway_types.h"
#include "dlt_gateway_core_handler.h"


using namespace dk::runtime;

class DltGatewayComponent : public dk::runtime::core::Component
{
public:
    explicit DltGatewayComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~DltGatewayComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveDLTMessageReadRequest(DLTMessageReadRequest const & msg);

    void onReceiveDLTControlMessageReponse(DLTControlMessageReponse const & msg);

private:
/// Start of user code : User code for file dlt_Gateway_component.h
    
    /**
     * @brief INI parser object
     * 
     */
    dk::runtime::core::ParserIf mParserObj;

    /**
     * @brief Global DLT gateway configuration
     * 
     */
    SDltGateWayConfig_t mDltGateWayConfig;

    /**
     * @brief Global Corehandler → TCP server instance* table
     * Key   = pointer to Core Handler
     * Value = pointer to TCP server instance
     * 
     */
    std::unordered_map<DltCoreHandler*, std::unique_ptr<DltTcpServer>> mCoreTcpServer;

    /**
     * @brief ReconnectPolicy instance
     * 
     */
    ReconnectPolicy mReconnectPolicy;

    /**
     * @brief DltCoreHandler instance
     * 
     */
    std::vector<std::unique_ptr<DltCoreHandler>> mpCorehandler;

    /**
     * @brief Global position → CoreHandler* table
     * Key   = Position value from INI (0–7 for a uint8_t status)
     * Value = pointer to the CoreHandler that owns that buffer
     * 
     */
    std::map<uint8_t, DltCoreHandler*> mPosTable;

    /**
     * @brief Running status
     * 
     */
    std::atomic<bool>       mRunning {false};

    /**
     * @brief Dispatch loop thread object
     * 
     */
    std::thread             mDispatchThread;

    /**
     * @brief Dispatch thread Mutex
     * 
     */
    mutable std::mutex      mDispatchMTX;

    /**
     * @brief  Dispatch thread condition variable
     * 
     */
    std::condition_variable mDispatchCV;
    /**
     * @brief  Invalid Frame Drop
     *
     */
    uint32_t mDroppedInvalid;

    /**
     * @brief DLTMessageReadAck status sent at startup to indicate "GIP DLT ready".
     * No buffer bit is set, so VIP can tell it apart from a read ACK, which
     * always echoes a non-zero buffer mask of the DLTMessageReadRequest.
     *
     */
    static constexpr uint8_t DLT_GW_READY_ACK_STATUS = 0x00U;

    /**
     * @brief Set in onStart() when the gateway is ready to serve read requests;
     * cleared by worker() once the ready DLTMessageReadAck has been sent.
     * Only accessed from the application main thread (onStart / onRun).
     *
     */
    bool mReadyAckPending {false};

    /**
     * @brief Send the startup "GIP DLT ready" DLTMessageReadAck to VIP
     *
     */
    void sendDltReadyAck();

    /**
     * @brief Load INI file
     * 
     * @return true 
     * @return false 
     */
    bool loadConfiguration();

    /**
     * @brief Parse INI file
     * 
     * @return true 
     * @return false 
     */
    bool parseConfiguration();

    /**
     * @brief Create CoreHandlers and build position table
     * 
     * @return true 
     * @return false 
     */
    bool coreInitialization();

    /**
     * @brief Dispatch loop
     * Woken by DltCoreHandler::enqueue() via on_message_ready callback.
     * Drains all handlers round-robin and forwards to dlt-daemon.
     * 
     */
    void dispatchLoop();

    /**
     * @brief Retry and connect TCP client to Host
     * 
     */
    void connectTcpClientRetry(DltTcpServer& tcpServer);

    /**
     * @brief Send message to DLT daemon
     * 
     * @param msg : DLT message
     * @param tcpServer : TCP server instance
     * @return true 
     * @return false 
     */

    bool sendToDltDaemon(const SDltMsg_t& msg, DltTcpServer& tcpServer);

/// End of user code
};


#endif //DLT_GATEWAY_COMPONENT_H

