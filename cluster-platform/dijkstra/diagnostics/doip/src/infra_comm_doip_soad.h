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
/// @file infra_comm_doip_soad.h
/// @ingroup DOIP
///
/// @brief CSoAd Class. CSoAd is a class. Socket adapter is act a server, it implements to hanlde the socket transport protocol
///         TCP/IP or UDP. It handle TCP/IP socket creation and connection between clients based on the runtime configuration.
///         Currently there is no support for UDP protocol.
///
/// It provides the infrastructure for
///  -# Create socket based on the received IP address and port Number
///  -# Close Connection, if no valid Connection available.
///  -# Receive data from TCP/IP stack with non blocking event.
///  -# Handling connection between client and server.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef INFRA_COMM_DOIP_SOAD_H
#define INFRA_COMM_DOIP_SOAD_H
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string>
#include "infra_comm_doip_soadCbkIf.h"
#include "infra_comm_doip_ringbuffer.h"
#include<vector>
#include <sys/select.h>
#include <stdlib.h>
#include <mutex>

class CSoAdTcp
{

public:

    ///
    /// @brief  This method used to close the connection.
    ///         This method can be invoked when the connection is not valid or no activity over the connection or
    ///             when the client in disconnected state.
    ///
    /// @param[in]  socketId  Id of the client has been connected.
    ///
    void socketClose ( uint8_t socketId );
    ///
    /// @brief This method hanlde the states for Socket creation, accept connect, receive data
    ///         This method invoked in a periodic task. For every 1 ms the task will be exected
    ///         If TCPSocket state is ESocketState_Init - Socket will be created on the target.
    ///         If TCPSocket state is ESocketState_TcpListening - Wait for client connection
    ///         If TCPSocket state is ESocketState_TcpReady - invoke recv() to receive  data.
    ///
    /// @param[in]  i is define the maximum tester connection. On which connection Data needs to Receieved and
    ///                 Listen if connection closed.
    /// @param[in]  portNum  Port Number to listen on the socket
    /// @param[in]  ipAddress  socket will be created on the receievd IP address
    ///
    void scanSockets ( uint8_t vlanNo,uint8_t i, uint16_t portNum, std::string ipAddress );
    ///
    /// @brief This method intializes the SoketHandle, Connection handle, TCPSocket State and maximum tester
    ///         This method invoked at the initialization CDoIPHanlder Initilization.
    ///
    /// @return This method return the Initstate
    ///
    uint8_t init ( void );
    ///
    /// @brief This method re-intializes the SoketHandle, Connection handle, TCPSocket State and maximum tester
    ///         This method invoked at the re- initialization CDoIPHanlder Initilization.
    ///
    /// @return This method return the Initstate
    ///
    void deInit ( void );
    ///
    /// @brief This method data to the client. This method invoked whenever resposne or request needs to send
    ///             to the client. This hanldes error case like, sending data over the closed connection.
    ///
    /// @param[in] socketId ID of the coenncted tester.
    /// @param[in] buffer  buffer contains data needs to be sent.
    /// @return    returns number of bytes transfered to the client.
    ///
    int32_t sendIpMessage ( uint8_t socketId, std::vector<uint8_t> &buffer ) ;
    ///
    /// @brief This method creates an instance of SoADIfCbk class.
    ///
    /// @param[in] mpSoAdCallbackIf pointer to the CSoAdCallbackIf class.
    ///
    void setSoadCallBackIf ( CSoAdCallbackIf *mpSoAdCallbackIf );
    ///
    /// @brief This method retruns number of sockets opened on the target for the communicationw ith tester.
    ///
    /// @param[in] None.
    ///
    uint8_t getNumberOfSocketsOpened();
    uint8_t getSocketState ( uint8_t i );


    CSoAdTcp()
    {
        maxTester = 0;
        tcpSocketsOpened = 0;
    }

    ~CSoAdTcp()
    {
    }
    CSoAdTcp( const CSoAdTcp &obj) {
        maxTester = obj.maxTester;
        tcpSocketsOpened = obj.maxTester;
    }


private:

    enum ESoadState_t
    {
        ESoadState_unint = 0,
        ESoadState_init,
        ESoadState_Last
    } ;

    enum EDoIpNodeType_t
    {
        DoIpNodeType_Gateway = 0x00,
        DoIpNodeType_Node = 0x01,
        DoIpNodeType_ValidModes,
        DoIpNodeType_Last,
    } ;

    typedef enum
    {
        ESocketState_Uninit = 0,
        ESocketState_Init,
        ESocketState_TcpListening,
        ESocketState_TcpReady,
        ESocketState_Last,
    } ESocketState_t;

    uint8_t maxTester  ;
    uint8_t headerLength = 8;
    uint16_t tcpStackSize = 64512U + 512U;
    uint8_t tcpSocketsOpened  ;
    uint8_t headerCheck = 1;
    uint8_t header1[2]= {0,255};
    uint8_t header2[2]= {2,253};
    std::vector<ESocketState_t> tcpSocketState;
    std::vector<int8_t> socketHandle;
    std::vector<int8_t> connectionHandle;
    std::vector<bool>   socketProtocolIsTcp;

    std::mutex mSendTcp;
    CRingBuffer mringBuffer;
    CRingBuffer::SRingBufferType msRingBuff = {{0}};

    ///
    /// @brief This method create socket on the target with the specified Port number
    ///
    /// @param[in]  portNum  Port Number to listen on the socket
    /// @param[in]  ipAddress  socket will be created on the receievd IP address
    ///
    void socketCreate ( uint16_t portNum, std::string ipAddress );

    ///
    /// @brief This method listen on the configured port number and accept the connection
    ///         request from client.IN this method, the accept call is non blocking
    ///         function call.
    ///
    /// @param[in]  socketId  socket Id is ID for Tester to connect with Server.
    ///
    void tcpAccepted ( uint8_t vlanNo,uint8_t socketId );
    ///
    /// @brief This method receive data from TCP/IP stack. This method write the receievd data
    ///        into ring buffer. Based the minimum length of the received data, the callback function
    ///        called for processing diagnostic message.
    ///
    /// @param[in]  socketId  socket Id is ID of the client which sent data to the server.
    ///
    void rxIndication ( uint8_t vlanNo,uint8_t socketId );
    ///
    /// @brief This method calculate the frame length from the ring buffer. To check the minimum length
    ///        of the receievd data.
    ///
    /// @param[in]  msRingBuff  buffer which contains the data stored from recv method.
    /// @return     this method retruns the framelength.
    ///
    uint32_t readFrameLength ( CRingBuffer::SRingBufferType *msRingBuff );
    ///
    /// @brief This method returns the TCPSocketState.
    ///
    /// @param[in]  i   ID of the client which sent data to the server.
    /// @return     this method retruns the TCP Socket state.
    ///        ESocketState_Init - Socket will be created on the target.
    ///        ESocketState_TcpListening - Wait for client connection
    ///        ESocketState_TcpReady - invoke recv() to receive  data.
    ///
    //  uint8_t getSocketState ( uint8_t i );
    ///
    /// @brief This method set the TCPSocketState.
    ///
    /// @param[in]  i       ID of the client which sent data to the server.
    /// @param[in]  state   State of the TCP Socket state.
    ///        ESocketState_Init - Socket will be created on the target.
    ///        ESocketState_TcpListening - Wait for client connection
    ///        ESocketState_TcpReady - invoke recv() to receive  data.
    ///
    void setSocketState ( uint8_t i, ESocketState_t state );
    ///
    /// @brief pointer to the SOADCallBack Class.
    ///
    CSoAdCallbackIf *soadCallback = nullptr;
};

class CSoAdUdp
{

public:
    CSoAdUdp()
    {

    }

    ~CSoAdUdp()
    {
    }
    CSoAdUdp( const CSoAdUdp &obj) {
    }

#ifdef DOIP_IPV6
    ///
    /// @brief This method send data to the client. This method invoked whenever resposne or request needs to broadcast over the network.
    ///
    /// @param[in] portNumber I port number of the client which is listening on the port for  broadcast data
    /// @param[in] buffer  buffer contains data needs to be sent.
    /// @return    returns number of bytes transfered to the client.
    ///
    uint16_t sendMessageIPv6 ( uint16_t portNumber, std::vector<uint8_t> &buff, const sockaddr_in6 *clientAddr );
#endif //DOIP_IPV6
    ///
    /// @brief This method send data to the client. This method invoked whenever resposne or request needs to broadcast over the network.
    ///
    /// @param[in] portNumber I port number of the client which is listening on the port for  broadcast data
    /// @param[in] buffer  buffer contains data needs to be sent.
    /// @return    returns number of bytes transfered to the client.
    ///
    uint16_t sendMessage ( uint16_t portNumber, std::vector<uint8_t> &buff, const sockaddr_in *clientAddr );
    ///
    /// @brief This method get the client port number
    ///
    /// @return    returns port number of a client which sends the UDP requests.
    ///
    uint16_t getClientPort();
    ///
    /// @brief This method hanlde the states for Socket creation, receive data
    ///         This method invoked in a periodic task. For every 1 ms the task will be exected
    ///         ESocketStateUdp_Init - Socket will be created on the target.
    ///         ESocketStateUdp_Ready - Ready to recive UDP data on the specified port
    ///
    /// @param[in]  portNum  Port Number to create and bin on the socket
    ///
    void scanSockets ( uint8_t vlanNo,uint16_t portNum, std::string ipAddress );
    ///
    /// @brief This method used to get the UDP socket current state
    ///
    /// @return  It returns UDP socket state.
    ///
    uint8_t getSocketState();
    ///
    /// @brief This method creates an instance of SoADIfCbk class.
    ///
    /// @param[in] mpSoAdCallbackIf pointer to the CSoAdCallbackIf class.
    ///
    void setSoadCallBackIf ( CSoAdCallbackIf *mpSoAdCallbackIfUdp );
    ///
    /// @brief This method intializes UDP socket state
    ///
    void init();

    /// @brief  This method used to close the socket.
    ///         This method can be invoked when the bind failed.
    ///
    void socketClose();

private:

    int8_t udpSocketHandle = 0;                         ///< UDP SocketHandle
    uint16_t udpStackSize = 7000;                   ///< UDP buffer size

    fd_set original_socket  = {{0}};
    fd_set original_stdin  = {{0}};
    fd_set readfds = {{0}};
    fd_set writefds = {{0}};
    struct timeval tv = {0};

    int numfd = 0;

    typedef enum
    {
        ESocketStateUdp_Uninit = 0,                     ///< UDP socket un initialized
        ESocketStateUdp_Init = 1,                           ///< UDP Socket Initialized
        ESocketStateUdp_Ready = 2,                          ///< UDP Socket ready to receive data
        ESocketStateUdp_Last = 3
    } ESocketStateUdp_t;

    ESocketStateUdp_t udpSocketState = ESocketStateUdp_Last;                       ///< UDP Socket state
    uint16_t udpDstPortNumber = 0U;                              ///< Port number of a client which sends UDP data to the server

#ifdef DOIP_IPV6
    std::string multicastIpAddress = "ff02::1";
#endif //DOIP_IPV6

    ///
    /// @brief pointer to the SOADCallBack Class.
    ///
    CSoAdCallbackIf *soadCallbackUdp = nullptr;
    ///
    /// @brief This method is creating UDP socket on the target with the specified Port number
    ///
    /// @param[in]  portNum  Port Number to listen and Send data on the socket
    ///
    void socketCreate ( uint16_t portNum, std::string ipAddress );
    ///
    /// @brief This method set the TCPSocketState.
    ///
    /// @param[in]  state   State of the TCP Socket state.
    ///        ESocketStateUdp_Init - Socket will be created on the target.
    ///        ESocketStateUdp_Ready - Ready to recive UDP data on the specified port
    void setSocketState ( ESocketStateUdp_t state );
    ///
    /// @brief This method receive data from UDP stack. The UDP dats can be forwarded to the callback
    ///         function which is called for processing diagnostic message.
    ///
    void rxIndication(uint8_t vlanNo);

    ///
    /// @brief  This method used store the port number pf a node where the UDP data received from
    ///         .
    /// @param[in] portNum port number of a client.
    void setClientPort ( uint16_t portNum );
};


#endif  //INFRA_COMM_DOIP_SOAD_H
