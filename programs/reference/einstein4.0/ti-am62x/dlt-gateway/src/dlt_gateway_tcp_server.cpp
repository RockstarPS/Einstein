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
/**
 * @file dlt_gateway_tcp_server.cpp
 * @author dmuruge5/gsoundar
 * @brief 
 * @version 0.1
 * @date 2026-06-01
 * 
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "dlt_gateway_tcp_server.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gDLTGWLogContext );

void DltTcpServer::configure(std::string host, int32_t port)
{
    mHost = std::move(host);
    mPort = port;
}

bool DltTcpServer::openSocket()
{
    //create socket
    mServerfd = socket(AF_INET, SOCK_STREAM, 0);
    if (mServerfd < 0)
    {
        LOGE(&gDLTGWLogContext, "Socket creation failed: ", strerror(errno));
        return false;
    }

    //socket options
    int opt          = 1;
    int tcp_no_delay = 1;
    (void)setsockopt(mServerfd, SOL_SOCKET,  SO_REUSEADDR, &opt,          sizeof(opt));
    (void)setsockopt(mServerfd, SOL_SOCKET,  SO_KEEPALIVE, &opt,          sizeof(opt));
    (void)setsockopt(mServerfd, IPPROTO_TCP, TCP_NODELAY,  &tcp_no_delay, sizeof(tcp_no_delay));
    (void)setsockopt(mServerfd, SOL_SOCKET,  SO_SNDBUF,    &mTcpBufSize,  sizeof(mTcpBufSize));
    (void)setsockopt(mServerfd, SOL_SOCKET,  SO_RCVBUF,    &mTcpBufSize,  sizeof(mTcpBufSize));

    //fill address
    struct sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port   = htons(static_cast<uint16_t>(mPort));

    if (inet_pton(AF_INET, mHost.c_str(), &serverAddr.sin_addr) <= 0)
    {
        LOGE(&gDLTGWLogContext, "Invalid IP address: ", mHost.c_str());
        (void) close(mServerfd);
        mServerfd = -1;
        return false;
    }

    if (bind(mServerfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        (void)close(mServerfd);
        LOGE(&gDLTGWLogContext, "bind() error : ", strerror(errno));
        return false;
    }

    if (listen(mServerfd, 3) < 0)
    {
        (void)close(mServerfd);
        LOGE(&gDLTGWLogContext, "listen() error : ", strerror(errno));
        return false;
    }

    return true;
}

bool DltTcpServer::connectClient()
{
    sockaddr_in clientAddr {};
    socklen_t addrLen = sizeof(clientAddr);

    mClientFd = accept(mServerfd, reinterpret_cast<sockaddr*>(&clientAddr), &addrLen);

    if (mClientFd > -1)
    {
        LOGI(&gDLTGWLogContext, "Connected to dlt-daemon at ", inet_ntoa(clientAddr.sin_addr), ":", ntohs(clientAddr.sin_port));
        mConnected = true;
    }

    return true;
}

bool DltTcpServer::isConnected() const
{ 
    return mConnected.load();
}

void DltTcpServer::disconnect()
{
    disconnectClient();

    if (mServerfd >= 0)
    { 
        (void) close(mServerfd);
        mServerfd = -1;
    }
}

void DltTcpServer::disconnectClient()
{
    if (mClientFd >= 0)
    { 
        (void) close(mClientFd);
        mClientFd = -1;
    }

    mConnected = false;
}

bool DltTcpServer::sendAll(const void* buf, std::size_t len)
{
    bool ret = true;
    if(mConnected)
    {
        const auto* p = static_cast<const uint8_t*>(buf);
        std::size_t done = 0;
        while (done < len)
        {
            ssize_t n = send(mClientFd, p + done, len - done, MSG_NOSIGNAL);
            if (n <= 0)
            {
                LOGE(&gDLTGWLogContext, "send error", strerror(errno));
                mConnected = false;
                ret = false;
                break;
            }
            done += static_cast<std::size_t>(n);
        }
    }
    else
    {
        ret = false;
    }

    return ret;
}
