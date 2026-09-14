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
#include "dlt_gateway_component.h"
#include "dlt_gateway_payload_validate.h"

/// Start of user code : Header user code for file dlt_Gateway_component.cpp
LOG_DECLARE_CONTEXT(gDLTGWLogContext);
/// End of user code


bool DltGatewayComponent::onInit()
{
	bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file dlt_Gateway_component.cpp
    LOG_REGISTER_CONTEXT(gDLTGWLogContext, "DLTG", "DLT Gateway Component", DLT_LOG_INFO);

    LOGV(&gDLTGWLogContext, "Enter");
    if (loadConfiguration())
    {
        LOGI(&gDLTGWLogContext, "config file found");
        parseConfiguration();
    }
    else
    {
        LOGE(&gDLTGWLogContext, "config file not found");
    }
/// End of user code

	return ret;
}

bool DltGatewayComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file dlt_Gateway_component.cpp

/// End of user code

	return ret;
}

bool DltGatewayComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file dlt_Gateway_component.cpp
    mReconnectPolicy = ReconnectPolicy(mDltGateWayConfig.ReconnectIntervalMs,
                                  mDltGateWayConfig.ReconnectMaxRetries,
                                  /*use_backoff=*/true);

    ret = coreInitialization();

    if(ret)
    {
        mRunning = true;
        mDispatchThread = std::thread([this]{ dispatchLoop(); });
    }

/// End of user code

	return ret;
}

bool DltGatewayComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file dlt_Gateway_component.cpp
    mRunning = false;
    mDispatchCV.notify_all();

    for (auto& h : mpCorehandler)
        h->stop();

    if (mDispatchThread.joinable())
        mDispatchThread.join();

    for(auto& tcpServer : mCoreTcpServer)
        tcpServer.second->disconnect();
/// End of user code

	return ret;
}

void DltGatewayComponent::worker()
{
/// Start of user code : User code for function worker in file dlt_Gateway_component.cpp

/// End of user code
}

void DltGatewayComponent::onReceiveDLTMessageReadRequest(DLTMessageReadRequest const  & msg)
{
/// Start of user code : User code for function onReceiveDLTMessageReadRequest in file dlt_Gateway_component.cpp
    const uint8_t status = static_cast<uint8_t>(msg.status[0]);
    LOGI(&gDLTGWLogContext, "Received DLTMessageReadRequest status=", status);

    for (uint8_t bit = 0; bit < 8; ++bit)
    {
        if (!(status & (1u << bit)))
            continue;   // bit not set → skip

        auto it = mPosTable.find(bit);
        if (it == mPosTable.end())
        {
            LOGE(&gDLTGWLogContext, "status bit: ",bit, " set but no buffer has Position: ", bit, " check INI configuration");
            continue;
        }

        it->second->readShmBuffer(bit);
    }
    DLTMessageReadAck ack{};
    ack.status[0] = msg.status[0];
    ack.status[1] = msg.status[1];
    DK_RTE_Send_DLTMessageReadAck(ack);
/// End of user code
}

void DltGatewayComponent::onReceiveDLTControlMessageReponse(DLTControlMessageReponse const& msg)
{
    (void)msg;
}



/// Start of user code : Footer user code for file dlt_Gateway_component.cpp
bool DltGatewayComponent::loadConfiguration()
{
    bool configFound = false;

    if (mParserObj.loadConfiguration(std::string("./dlt_gw.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/etc/dlt_gw.ini")))
    {
        configFound = true;
    }
    else if (mParserObj.loadConfiguration(std::string("/system/etc/dlt_gw.ini")))
    {
        configFound = true;
    }
    else
    {
        LOGE(&gDLTGWLogContext, "No Config file found");
    }
    
    return configFound;
}

bool DltGatewayComponent::parseConfiguration()
{
    uint8_t numCores = 0;
    std::string sectionName = "DltGatewayConfiguration";

    mDltGateWayConfig.ServerIpAddr = mParserObj.getStringValue(sectionName, "ServerIpAddress");
    mDltGateWayConfig.ReconnectIntervalMs = mParserObj.getInt32Value(sectionName, "ReconnectIntervalMS", 0u);
    mDltGateWayConfig.ReconnectMaxRetries = mParserObj.getInt32Value(sectionName, "ReconnectMaxRetries", -1);
    mDltGateWayConfig.TransportTypeStr = mParserObj.getStringValue(sectionName, "TransportType");
    mDltGateWayConfig.NumCores = mParserObj.getInt32Value(sectionName, "NumberOfCores", 0u);

    LOGI(&gDLTGWLogContext, "Server IP address : ", mDltGateWayConfig.ServerIpAddr);
    LOGI(&gDLTGWLogContext, "Reconnect Interval in ms : ", mDltGateWayConfig.ReconnectIntervalMs);
    LOGI(&gDLTGWLogContext, "Reconnect Max Retries : ", mDltGateWayConfig.ReconnectMaxRetries);
    LOGI(&gDLTGWLogContext, "Transport type : ", mDltGateWayConfig.TransportTypeStr);
    LOGI(&gDLTGWLogContext, "Number of cores : ", mDltGateWayConfig.NumCores);

    for( uint8_t coreIdx = 0; coreIdx < mDltGateWayConfig.NumCores; coreIdx++ )
    {
        std::vector<std::string> coreConfigNameList;
        std::vector<std::string> shmAddrNameList;
        std::vector<std::string> shmSizeNameList;
        std::vector<std::string> NumBuffNameList;
        std::string coreConfigName;
        SCoreConfig_t *pCoreConfig;

        mParserObj.getAllValuesForKey(sectionName, "Core_"+std::to_string(coreIdx), coreConfigNameList);

        if(0 == coreConfigNameList.size())
        {
            LOGE(&gDLTGWLogContext, "Missing Core Name ", sectionName);
            continue;
        }

        coreConfigName = coreConfigNameList[0];
        LOGI(&gDLTGWLogContext, "Core_", std::to_string(coreIdx), ": " + coreConfigName);

        pCoreConfig = new SCoreConfig_t;
        pCoreConfig->CoreName = mParserObj.getStringValue(coreConfigName, "Name");
        pCoreConfig->ServerPort = mParserObj.getInt32Value(coreConfigName, "ServerPort", 0u);
        mParserObj.getAllValuesForKey(coreConfigName, "ShmStartAddress", shmAddrNameList);
        mParserObj.getAllValuesForKey(coreConfigName, "ShmSize", shmSizeNameList);
        mParserObj.getAllValuesForKey(coreConfigName, "NumberOfBuffers", NumBuffNameList);

        if( ( 0 == shmAddrNameList.size() ) || ( 0 == shmSizeNameList.size() ) || ( 0 == NumBuffNameList.size() ) )
        {
            LOGE(&gDLTGWLogContext, "Missing Shared memeory address or memory size or number of buffers ", sectionName);
            delete pCoreConfig;
            continue;
        }

        std::string ShmStartAddress = mParserObj.getStringValue(coreConfigName, "ShmStartAddress");
        pCoreConfig->Shm.ShmAddress = std::stoul(ShmStartAddress, nullptr, 16);
        pCoreConfig->Shm.ShmSize = mParserObj.getInt32Value(coreConfigName, "ShmSize", 0u);
        pCoreConfig->NumBuffers = mParserObj.getInt32Value(coreConfigName, "NumberOfBuffers", 0u);
        pCoreConfig->NumBuffers = mParserObj.getInt32Value(coreConfigName, "NumberOfBuffers", 0u);
        pCoreConfig->NumBuffers = mParserObj.getInt32Value(coreConfigName, "NumberOfBuffers", 0u);

        pCoreConfig->transport = parseTransportType(mDltGateWayConfig.TransportTypeStr);


        LOGI(&gDLTGWLogContext, "Core : ", pCoreConfig->CoreName);
        LOGI(&gDLTGWLogContext, "Server Port : ", pCoreConfig->ServerPort);
        LOGI(&gDLTGWLogContext, "Shared memeory address : ", pCoreConfig->Shm.ShmAddress);
        LOGI(&gDLTGWLogContext, "Shared memory size : ", pCoreConfig->Shm.ShmSize);
        LOGI(&gDLTGWLogContext, "Number of buffers : ", pCoreConfig->NumBuffers);

        for(uint8_t buffIdx = 0; buffIdx < pCoreConfig->NumBuffers; buffIdx++)
        {
            SCoreBuffConfig_t *pBuffConfig = new SCoreBuffConfig_t;
            std::vector<std::string> buffConfigNameList;
            std::string buffConfigName;
            std::vector<std::string> buffAddrNameList;
            std::vector<std::string> buffSizeNameList;
            std::vector<std::string> posNameList;

            mParserObj.getAllValuesForKey(coreConfigName, "Buffer_" + std::to_string(buffIdx), buffConfigNameList);

            if(0 == buffConfigNameList.size())
            {
                LOGE(&gDLTGWLogContext, "Missing Buffer Name ", coreConfigName);
                delete pBuffConfig;
                continue;
            }

            buffConfigName = buffConfigNameList[0];
            LOGI(&gDLTGWLogContext, "Buffer_", std::to_string(buffIdx), ": " + buffConfigName);

            mParserObj.getAllValuesForKey(buffConfigName, "BufferStartAddress", buffAddrNameList);
            mParserObj.getAllValuesForKey(buffConfigName, "BufferSize", buffSizeNameList);
            mParserObj.getAllValuesForKey(buffConfigName, "Position", posNameList);

            if( ( 0 == buffAddrNameList.size() ) || ( 0 == buffSizeNameList.size() ) || ( 0 == posNameList.size() ) )
            {
                LOGE(&gDLTGWLogContext, "Missing buffer start address or buffer size or position ", buffConfigName);
                delete pBuffConfig;
                continue;
            }

            std::string BufferStartAddressStr = mParserObj.getStringValue(buffConfigName, "BufferStartAddress");
            pBuffConfig->BufStartAddress = std::stoul(BufferStartAddressStr, nullptr, 16);
            pBuffConfig->BufSize = mParserObj.getInt32Value(buffConfigName, "BufferSize", 0u);
            pBuffConfig->Pos = mParserObj.getInt32Value(buffConfigName, "Position", 0u);

            LOGI(&gDLTGWLogContext, "BufferStartAddress : ", pBuffConfig->BufStartAddress);
            LOGI(&gDLTGWLogContext, "BufferSize : ", pBuffConfig->BufSize);
            LOGI(&gDLTGWLogContext, "Position : ", pBuffConfig->Pos);

            pCoreConfig->BuffConfig.push_back(pBuffConfig);
        }
        mDltGateWayConfig.CoreConfig.push_back(pCoreConfig);
    }

    return true;
}

bool DltGatewayComponent::coreInitialization(void)
{
    for (const auto& cc : mDltGateWayConfig.CoreConfig)
    {
        std::unique_ptr<DltCoreHandler> CoreHandler(new DltCoreHandler(*cc, [this]{ mDispatchCV.notify_one(); }));

        if (!CoreHandler->start())
        {
            LOGE(&gDLTGWLogContext, "CoreHandler[%s] start failed : ", cc->CoreName);
            continue;
        }

        if(cc->ServerPort == 0)
        {
            LOGE(&gDLTGWLogContext, "Core: ", cc->CoreName, " has no Server port configured - skipping TCP setup");
            continue;
        }

        std::unique_ptr<DltTcpServer> pTcpServer(new DltTcpServer);
        pTcpServer->configure(mDltGateWayConfig.ServerIpAddr, cc->ServerPort);
    
        if(!pTcpServer->openSocket())
        {
            LOGE(&gDLTGWLogContext, "Core: ", cc->CoreName, " Failed to open TCP socket on port ", cc->ServerPort);
        }

        if(!pTcpServer->connectClient())
        {
            LOGE(&gDLTGWLogContext, "Core: ", cc->CoreName, " Client connect failed on port ", cc->ServerPort, " - will retry on first message");
        }

        // Register every buffer position this core owns in the global position → handler lookup table
        for (const auto& buf : cc->BuffConfig)
        {
            if (mPosTable.count(buf->Pos))
            {
                LOGE(&gDLTGWLogContext, "duplicate Position : ",buf->Pos, "in Core : ", cc->CoreName);
                LOGW(&gDLTGWLogContext, "Each Position must be unique across all cores");
                continue;
            }
            mPosTable[buf->Pos] = CoreHandler.get();

            LOGI(&gDLTGWLogContext, "Pos: ", buf->Pos, " Core: ", cc->CoreName, " Addr:", buf->BufStartAddress ," size:", buf->BufSize);
        }

        mCoreTcpServer[CoreHandler.get()] = std::move(pTcpServer);
        mpCorehandler.push_back(std::move(CoreHandler));
    }

    return true;
}

void DltGatewayComponent::dispatchLoop()
{
    while (mRunning)
    {
        {
            std::unique_lock<std::mutex> lk(mDispatchMTX);
            mDispatchCV.wait_for(lk, std::chrono::milliseconds(50),
                [this] {
                    for (auto& h : mpCorehandler)
                        if (h->hasMessages())
                            return true;
                    return !mRunning.load();
                });
        }

        if (!mRunning) break;

        for (auto& handler : mpCorehandler)
        {
            auto it = mCoreTcpServer.find(handler.get());
            if(it == mCoreTcpServer.end())
            {
                LOGE(&gDLTGWLogContext, "No server configured for this core ", handler->mCoreConfig.CoreName);
                continue;
            }
            DltTcpServer& coreServer = *it->second;
            SDltMsg_t msg;
            while (handler->dequeue(msg, std::chrono::milliseconds(0)))
            {
                if (!sendToDltDaemon(msg, coreServer) && !mRunning)
                    return;
            }
        }
    }
}

bool DltGatewayComponent::sendToDltDaemon(const SDltMsg_t& msg, DltTcpServer& tcpServer)
{
    SScanResult_t scanResult = DltValidator::scanBuffer(msg.payload.data(), msg.length);

    if (scanResult.valid_bytes == 0)
    {
        SValidationResult_t res;
        res.valid = false;
        res.error = scanResult.error;
        LOGE(&gDLTGWLogContext, "contains no valid DLT frames — dropped, error: ", res.reason(), ", bad frames: ",scanResult.frames_bad);
        /*TODO: Identify core name, buffer name and position */
        mDroppedInvalid++;
        return true;   // not a TCP error — don't reconnect
    }

    if (scanResult.frames_bad > 0)
    {
        /*  Partial buffer: some frames good, scan stopped at first bad one */
        SValidationResult_t res;
        res.valid = false;
        res.error = scanResult.error;
        LOGE(&gDLTGWLogContext, "Partial buffer. Sending bytes: ", scanResult.valid_bytes, " Frames ok: ", scanResult.frames_ok," Reason: ",res.reason());
        /*TODO: Identify core name, buffer name and position */
    }
    if (!tcpServer.isConnected())
    {
        LOGE(&gDLTGWLogContext, "TCP down — reconnecting ");
        connectTcpClientRetry(tcpServer);
        if (!tcpServer.isConnected())
            return false;
    }

    if(!tcpServer.sendAll(msg.payload.data(), scanResult.valid_bytes))
    {
        tcpServer.disconnectClient();
        connectTcpClientRetry(tcpServer);
    }

    return true;
}

void DltGatewayComponent::connectTcpClientRetry(DltTcpServer& tcpServer)
{
    mReconnectPolicy.reset();

    while (mRunning && !tcpServer.connectClient())
    {
        if (!mReconnectPolicy.shouldRetry())
        {
            LOGE(&gDLTGWLogContext, "Max reconnect attempts reached");
            mRunning = false;
            return;
        }
        mReconnectPolicy.waitInterval(mRunning);
    }

    if (mRunning)
    {
        mReconnectPolicy.reset();
    }
}

/// End of user code

