//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "infra_comm_doip_soad.h"
#include <fcntl.h>
#include <vector>
#include "dk_logger.h"
#include <errno.h>
#include <string.h>
#include <sys/param.h>
#ifdef __linux__
  #include <sys/syscall.h>
  #include <unistd.h>
  #include <linux/sysctl.h>
  #include <netinet/tcp.h>
#else
  #include <sys/sysctl.h>
  #include <netinet/tcp_var.h>
#endif
#include <net/if.h>
#include <ifaddrs.h>
#include <time.h>

LOG_IMPORT_CONTEXT ( gDoipLogContext );
int errno;
#define MAXLINE 1000
struct sockaddr_in ClientSendAddr;

uint8_t CSoAdTcp::init()
{
    ESoadState_t    soadState;
    ///<  Set SO_KEEP Alive properties
    ///< Alive Probe '10'second  '3' Messages at time interval of "0.5 seconds"
 /*#ifdef __linux__
    lParam[3] = TCP_KEEPCNT;
 #else
    lParam[3] = TCPCTL_KEEPCNT;
 #endif*/
  
#ifdef __linux__
    // need to rewrite based on sysctl linux 
#else  
    int lParam[4];
    int ival = 3; ///<  Number of keepalive probe attempts(default is 8)
    lParam[0] = CTL_NET;
    lParam[1] = AF_INET;
    lParam[2] = IPPROTO_TCP;
    lParam[3] = TCPCTL_KEEPCNT;
    sysctl ( lParam, 4, NULL, NULL, &ival, sizeof ( ival ) );
#endif    
/*#ifdef __linux__
    lParam[3] = TCP_KEEPINTVL;
#else    
    lParam[3] = TCPCTL_KEEPINTVL;
#endif */
    
#ifdef __linux__
     // need to rewrite based on sysctl linux 
     //struct __sysctl_args  arg ;
    //  syscall(SYS__sysctl , &arg);
#else   
    lParam[0] = CTL_NET;
    lParam[1] = AF_INET;
    lParam[2] = IPPROTO_TCP;
    lParam[3] = TCPCTL_KEEPINTVL;
    ival = 1; ///<  Half seconds between probe attempts :default is 150 (75 sec)
    sysctl ( lParam, 4, NULL, NULL, &ival, sizeof ( ival ) );
#endif    
    tcpSocketState.push_back ( ESocketState_Init );
    socketHandle.push_back ( -1 );
    connectionHandle.push_back ( -1 );
    socketProtocolIsTcp.push_back ( false );
    maxTester = maxTester + 1;
    soadState = ESoadState_init;
    tcpSocketsOpened = 0;
    mringBuffer.init(&msRingBuff);

    LOGI ( &gDoipLogContext, "soad Init Done " );
    return ( uint8_t ) soadState;
}

void CSoAdTcp::deInit (  )
{
#if 0
    int lParam[4], ival;

    ///<  Set SO_KEEP Alive properties
    ///< Set to the default values
    lParam[0] = CTL_NET;
    lParam[1] = AF_INET;
    lParam[2] = IPPROTO_TCP;
    lParam[3] = TCPCTL_KEEPCNT;
    ival = 8; ///<  Number of keepalive probe attempts(default is 8)
    sysctl ( lParam, 4, NULL, NULL, &ival, sizeof ( ival ) );
    lParam[0] = CTL_NET;
    lParam[1] = AF_INET;
    lParam[2] = IPPROTO_TCP;
    lParam[3] = TCPCTL_KEEPINTVL;
    ival = 150; ///<  Half seconds between probe attempts :default is 150 (75 sec)
    sysctl ( lParam, 4, NULL, NULL, &ival, sizeof ( ival ) );
    tcpSocketState.clear();
    socketHandle.clear();
    connectionHandle.clear();
    socketProtocolIsTcp.clear();
    maxTester = 0;
#endif
    LOGI ( &gDoipLogContext, "soad DeInit Done " );
}

int32_t CSoAdTcp::sendIpMessage ( uint8_t socketId, std::vector<uint8_t> &buff )
{
    std::lock_guard<std::mutex> lock ( mSendTcp);
    int32_t Byte_Sent = 0;
    if ( socketProtocolIsTcp.at ( socketId ) == true )
    {
        LOGI ( &gDoipLogContext, "Send Response to tester " );
        Byte_Sent = send ( connectionHandle.at ( socketId ), &buff[0], buff.size(), 0 );
    }

    return Byte_Sent;
}

void  CSoAdTcp::tcpAccepted ( uint8_t vlanNo,uint8_t socketId )
{
#ifdef DOIP_IPV6
    int32_t conectedSocket;
    struct sockaddr_in6 client_addr;
    socklen_t addrlen = sizeof(client_addr);
#else
    int8_t conectedSocket;
    struct sockaddr client_addr;
    uint32_t addrlen = sizeof ( client_addr );
#endif //DOIP_IPV6
    int flags;
    int Ret;

    flags = fcntl ( socketHandle.at ( socketId ), F_GETFL, 0 ); ///< get socket's flags
    flags |= O_NONBLOCK; ///< Add O_NONBLOCK status to socket descriptor's flags
    Ret = fcntl (  socketHandle.at ( socketId ), F_SETFL, flags ); ///< Change the socket as non blocking socket
    conectedSocket = accept ( socketHandle.at ( socketId ), ( struct sockaddr * ) &client_addr, ( socklen_t * ) &addrlen );

    if ( conectedSocket >= 0 )
    {
        LOGI ( &gDoipLogContext, "connected" );
        setSocketState ( socketId, ESocketState_TcpReady );
        connectionHandle.at ( socketId ) = conectedSocket;
        flags = fcntl ( conectedSocket, F_GETFL, 0 ); ///< get socket's flags
        flags |= O_NONBLOCK; ///< Add O_NONBLOCK status to socket descriptor's flags
        soadCallback->tcpConnectionEstablished ( socketId,vlanNo );             ///Send Callback Notification
        ( void ) fcntl ( connectionHandle.at ( socketId ), F_SETFL, O_NONBLOCK );       /// Change the socket as non blocking socket
        setSocketState ( socketId, ESocketState_TcpReady );

    }
    if ( Ret < 0 )
    {
        LOGI ( &gDoipLogContext, "Set Socket Properties Failed", std::string ( strerror ( errno ) ) );
    }

}

void CSoAdTcp::scanSockets ( uint8_t vlanNo,uint8_t i, uint16_t portNum, std::string address )
{
    uint8_t state = getSocketState ( i );

    switch ( ( ESocketState_t ) state )
    {
    ///< Socket in INIT state, Socket needs to be created
    case ESocketState_Init:
        socketCreate ( portNum, address );
        break;
    ///< Socket in Listening state, Waiting for connection from the client
    case ESocketState_TcpListening:
        tcpAccepted ( vlanNo,i );
        break;
    ///< Socket in Ready state, Connection established, wating to receive data from the Client.\n
    case ESocketState_TcpReady:
        rxIndication (vlanNo, i );
        break;
    default:
        LOGI ( &gDoipLogContext, "Default state" );
        break;
    }
}


void CSoAdTcp::socketClose ( uint8_t socketId )
{
    LOGI ( &gDoipLogContext, "SocketClosed" );

    if ( close ( connectionHandle.at ( socketId ) ) >= 0 )
    {
        setSocketState ( socketId, ESocketState_TcpListening );

        if ( tcpSocketsOpened > 0U )
        {
            tcpSocketsOpened -= 1;
        }
    }
}

void CSoAdTcp:: socketCreate ( uint16_t portNum, std::string ipAddress )
{
    int32_t sockFd;
    int retVal = -1;

#ifdef DOIP_IPV6
    struct sockaddr_in6 sLocalAddr;

    sockFd = socket ( PF_INET6, SOCK_STREAM, 0 );
#else
    struct sockaddr_in sLocalAddr;

    sockFd = socket ( PF_INET, SOCK_STREAM, 0 );
#endif //DOIP_IPV6

    if ( sockFd >= 0 )
    {
#ifdef DOIP_IPV6
        ( void ) memset ( &sLocalAddr, 0, sizeof ( sLocalAddr ) );
        sLocalAddr.sin6_family = PF_INET6;
        inet_pton(PF_INET6, ipAddress.c_str(), &sLocalAddr.sin6_addr);
        sLocalAddr.sin6_port = htons ( portNum );
#else
        ( void ) memset ( ( int8_t * ) &sLocalAddr, 0, sizeof ( sLocalAddr ) );

        sLocalAddr.sin_family = PF_INET;
        sLocalAddr.sin_addr.s_addr = inet_addr ( ipAddress.c_str() );
        sLocalAddr.sin_port = htons ( portNum );
#endif //DOIP_IPV6

        LOGI ( &gDoipLogContext, " IP address is ", ipAddress );

        retVal = bind ( sockFd, ( struct sockaddr * ) &sLocalAddr, sizeof ( sLocalAddr ) );

        if ( ( retVal >= 0) ||
                ( ( retVal <  0) && (EADDRINUSE == errno) )
           )
        {
            if( ( retVal <  0) && (EADDRINUSE == errno) )
            {
                LOGW ( &gDoipLogContext, "Address ", ipAddress, " is already in use!" );
            }

            if ( listen ( sockFd, 5 ) == 0 )
            {
                if ( maxTester != 0 )
                {
                    ///< Now the TCP socket is ready for receive/transmit
                    for ( uint8_t i = 0 ; i < maxTester; i++ )
                    {
                        socketHandle.at ( i ) = ( int8_t ) sockFd;
                        socketProtocolIsTcp.at ( i ) = true;
                        setSocketState ( i, ESocketState_TcpListening );
                        LOGV ( &gDoipLogContext, " Socket created" );
                        tcpSocketsOpened = tcpSocketsOpened + 1;
                    }
                }
                else
                {
                    close ( sockFd );
                    LOGW ( &gDoipLogContext, " Number of tester is 0. So that the Created socket closed " );
                }
            }
            else
            {
                close ( sockFd );
                LOGE ( &gDoipLogContext, "Socket listening failed! errno: ", errno, "strerror: ", std::string ( strerror ( errno ) ) );
            }
        }
        else
        {
            close ( sockFd );
            LOGE ( &gDoipLogContext, "Socket binding failed! errno: ", errno, "strerror: ", std::string ( strerror ( errno ) ) );
        }
    }
}

void CSoAdTcp::rxIndication ( uint8_t vlanNo,uint8_t socketId )
{

    int32_t nBytes;
    std::vector<uint8_t> buff ( tcpStackSize );
    int32_t dataLength = 0;
    std::vector<uint8_t> recvBuf ( tcpStackSize );

    ///< Receive the DoIP message from connected tester over the TCP/IP. \n
    ///< On successful receive of message, Invoke DoIPHandler_ReceiveManager() to decode and process the received DoIP message \n
    ( void ) memset ( ( void * ) &buff[0], 0, tcpStackSize );

    if ( getSocketState ( socketId ) == ESocketState_TcpReady )
    {
        /// -# Get the DoIP Message Length, wait till the complete message receiving \n
        nBytes = recv ( connectionHandle.at ( socketId ), &buff[0], buff.size(), 0 );

        if ( nBytes > 0 )
        {
            if ( mringBuffer.write ( &msRingBuff, &buff[0], ( uint16_t ) nBytes ) != 0u )
            {
                while ( ( int32_t ) readFrameLength ( &msRingBuff ) )
                {
                    dataLength = ( int32_t ) readFrameLength ( &msRingBuff );

                    if ( dataLength != 0 )
                    {
                        ( void ) memset ( ( void * ) &recvBuf[0], 0, tcpStackSize );

                        if ( mringBuffer.read ( &msRingBuff, &recvBuf[0], ( uint16_t ) dataLength ) == dataLength )
                        {
                            LOGV ( &gDoipLogContext, "Received DoiP message sent to Receive Manager " );
                            soadCallback->messageReceived ( false,vlanNo,socketId, &recvBuf, NULL );
                            if(mringBuffer.poll(&msRingBuff,header1) && mringBuffer.poll(&msRingBuff,header2))
                            {
                                mringBuffer.reset(&msRingBuff);

                            }

                        }
                        else
                        {
                            LOGE ( &gDoipLogContext, "No enough data in ring buffer " );
                        }

                    }
                }
            }
        }

        else if ( nBytes == 0 )
        {
            LOGE ( &gDoipLogContext, "TCP client Send Fin/RST packet : Client might be closed " );
            socketClose ( socketId );
            soadCallback->tcpSocketClose ( socketId,vlanNo );             ///Send Callback Notification

        }

        else if ( nBytes == -1 )
        {
            if ( ( errno == ECONNRESET ) || ( errno == ETIMEDOUT ) || ( errno == ENOTCONN ) || ( errno == ESHUTDOWN ) )
            {
                LOGE ( &gDoipLogContext, " A connection was forcibly closed by a peer " );
                LOGE ( &gDoipLogContext, "Socket  Failed , Err No ", "Error Type ", errno, std::string ( strerror ( errno ) ) );
                socketClose ( socketId );
                soadCallback->tcpSocketClose ( socketId,vlanNo );             ///Send Callback Notification

            }
        }
    }
}

uint8_t CSoAdTcp::getSocketState ( uint8_t i )
{
    ESocketState_t ret;

    ret =  tcpSocketState.at ( i );
    return ( uint8_t ) ret;
}

void CSoAdTcp::setSocketState ( uint8_t i, ESocketState_t state )
{
    tcpSocketState.at ( i ) = state;
    LOGI ( &gDoipLogContext, "Socket Index", i, "Socket value ", socketHandle.at ( i ), "Set Socket State ", ( uint32_t ) state );
}

uint32_t CSoAdTcp::readFrameLength ( CRingBuffer::SRingBufferType *msRingBuff )
{
    uint16_t ri = 0u;
    uint16_t index = 0u;
    uint32_t dataLength = 0u;

    ri = msRingBuff->read_index;

    if ( headerLength <= msRingBuff->fill_count )
    {
        index =  ( ri + 4u ) % RING_BUFFER_SIZE;
        dataLength =  ( uint32_t ) msRingBuff->data[index] << 24U;
        index =  ( ri + 5u ) % RING_BUFFER_SIZE;
        dataLength |= ( uint32_t ) msRingBuff->data[index] << 16U;
        index =  ( ri + 6u ) % RING_BUFFER_SIZE;
        dataLength |= ( uint32_t ) msRingBuff->data[index] << 8U;
        index =  ( ri + 7u ) % RING_BUFFER_SIZE;
        dataLength |= ( uint32_t ) msRingBuff->data[index];

        if(dataLength > tcpStackSize)
            dataLength = 0;
        dataLength += headerLength;
        LOGI ( &gDoipLogContext, "dataLength is", dataLength );
        if ( dataLength > msRingBuff->fill_count )
        {
            LOGW ( &gDoipLogContext, "Fill Count is ", msRingBuff->fill_count, " dataLength Is", dataLength );
            dataLength = 0u;
            LOGW ( &gDoipLogContext, "dataLength is greater than the available data in ring buffer " );

        }
    }

    return dataLength;
}

void CSoAdTcp::setSoadCallBackIf ( CSoAdCallbackIf *mpSoAdCallbackIf )
{
    soadCallback = mpSoAdCallbackIf;
}

uint8_t CSoAdTcp::getNumberOfSocketsOpened()
{
    return  tcpSocketsOpened;
}

uint16_t CSoAdUdp::sendMessage ( uint16_t portNumber, std::vector<uint8_t> &buff, const sockaddr_in *clientAddr )
{
    struct sockaddr_in broadcastAddr; ///< Broadcast address
    ///< Construct local address structure

    if ( clientAddr != NULL )
    {
        memset ( &broadcastAddr, 0, sizeof ( broadcastAddr ) ); /* Zero out structure */
        broadcastAddr = *clientAddr;
        LOGI ( &gDoipLogContext, "port number", ( uint32_t ) portNumber );
        LOGI ( &gDoipLogContext, "broadcast Ip address", ( uint32_t )  broadcastAddr.sin_addr.s_addr );

        if (static_cast<uint32_t>( sendto ( udpSocketHandle, &buff[0], buff.size(), 0, ( struct sockaddr * ) &broadcastAddr, \
                                            sizeof ( broadcastAddr ) )) !=  buff.size() )

        {
            LOGE ( &gDoipLogContext, "sendUDP Message failed. Error code ", ( uint32_t ) errno );
            LOGE ( &gDoipLogContext, " Error Type ", errno, std::string ( strerror ( errno ) ) );
        }
    }
    else
    {
        memset ( &broadcastAddr, 0, sizeof ( broadcastAddr ) ); /* Zero out structure */
        broadcastAddr.sin_family = AF_INET;                  /* Internet address family */
        broadcastAddr.sin_addr.s_addr = INADDR_BROADCAST;    /* Broadcast IP address */
        broadcastAddr.sin_port = htons ( portNumber );      /* Broadcast port */
        if (static_cast<uint32_t>( sendto ( udpSocketHandle, &buff[0], buff.size(), MSG_DONTROUTE, ( struct sockaddr * ) &broadcastAddr, \
                                            sizeof ( broadcastAddr ) )) !=  buff.size() )

        {
            LOGE ( &gDoipLogContext, "sendUDP Message failed. Error code ", ( uint32_t ) errno );
            LOGE ( &gDoipLogContext, " Error Type ", errno, std::string ( strerror ( errno ) ) );
        }
    }

    LOGI ( &gDoipLogContext, "port number", ( uint32_t ) portNumber );
    LOGI ( &gDoipLogContext, "broadcast Ip address", ( uint32_t )  broadcastAddr.sin_addr.s_addr );

    return buff.size();
}

#ifdef DOIP_IPV6
uint16_t CSoAdUdp::sendMessageIPv6 ( uint16_t portNumber, std::vector<uint8_t> &buff, const sockaddr_in6 *clientAddr )
{
    struct sockaddr_in6 clientAddress;
    char addr_str[INET6_ADDRSTRLEN];
    ///< Construct local address structure

    if ( clientAddr != NULL )
    {
        memset ( &clientAddress, 0, sizeof ( clientAddress ) ); /* Zero out structure */
        clientAddress = *clientAddr;
    }
    else
    {
        memset ( &clientAddress, 0, sizeof ( clientAddress ) );                    /* Zero out structure */
        clientAddress.sin6_family = PF_INET6;                                      /* Internet address family */
        inet_pton(PF_INET6, multicastIpAddress.c_str(), &clientAddress.sin6_addr); /* Multicast IP address */
        clientAddress.sin6_port = htons ( portNumber );                            /* Multicast port */
    }

    //For Log Print
    inet_ntop(AF_INET6, &clientAddress.sin6_addr, addr_str, sizeof(addr_str));
    LOGI ( &gDoipLogContext, "port number", ( uint32_t ) portNumber );
    LOGI ( &gDoipLogContext, "multicast Ip address", std::string (addr_str) );

    if ( sendto ( udpSocketHandle, &buff[0], buff.size(), 0, ( struct sockaddr * ) &clientAddress, \
                  sizeof ( clientAddress ) ) !=  buff.size() )

    {
        LOGE ( &gDoipLogContext, "sendUDP Message failed. Error code ", ( uint32_t ) errno );
        LOGE ( &gDoipLogContext, " Error Type ", errno, std::string ( strerror ( errno ) ) );
    }

    return buff.size();
}
#endif // DOIP_IPV6

void CSoAdUdp::socketCreate ( uint16_t portNum, std::string ipAddress)
{
    /* Socket */
#ifdef DOIP_IPV6
    struct sockaddr_in6 serverAddr; /* Broadcast Address */
    /* Set socket to allow broadcast */
    char interface_name[20];
    memset ( &serverAddr, 0, sizeof ( serverAddr ) ); /* Zero out structure */
    serverAddr.sin6_family = PF_INET6;                 /* Internet address family */
    serverAddr.sin6_addr = in6addr_any; /* Any incoming interface */
    serverAddr.sin6_port = htons ( 13400 );   /* Broadcast port */

    /* Create socket for sending/receiving datagrams */
    if ( ( udpSocketHandle = socket ( PF_INET6, SOCK_DGRAM, IPPROTO_UDP ) ) < 0 )
    {
        LOGE ( &gDoipLogContext, "UDP PF_INET6 Socket not created" );
    }

#else
    int broadcastPermission;          /* Socket opt to set permission to broadcast */
    struct sockaddr_in serverAddr; /* Broadcast Address */
    /* Set socket to allow broadcast */
    char interface_name[20] = {'\0'};
    memset ( &serverAddr, 0, sizeof ( serverAddr ) ); /* Zero out structure */
    serverAddr.sin_family = AF_INET;                 /* Internet address family */
    serverAddr.sin_addr.s_addr = htonl ( INADDR_ANY ); /* Any incoming interface */
    serverAddr.sin_port = htons ( 13400 );   /* Broadcast port */

    /* Create socket for sending/receiving datagrams */

    if ( ( udpSocketHandle = socket ( PF_INET, SOCK_DGRAM, IPPROTO_UDP ) ) < 0 )
    {
        LOGE ( &gDoipLogContext, "UDP Socket not created" );
    }
#endif
    else
    {
        int flags = fcntl ( udpSocketHandle, F_GETFL );
        flags |= O_NONBLOCK;
        (void)fcntl ( udpSocketHandle, F_SETFL, flags );
        FD_ZERO ( &original_socket );
        FD_ZERO ( &original_stdin );
        FD_ZERO ( &readfds );
        FD_ZERO ( &writefds );
        // add our descriptors to the set (0 - stands for STDIN)
        FD_SET ( udpSocketHandle, &original_socket ); //instead of 0 put socket_fd
        FD_SET ( udpSocketHandle, &readfds );
        FD_SET ( 0, &original_stdin );
        FD_SET ( 0, &writefds );
        // since we got s2 second, it's the "greater", so we use that for
        // the n param in select()
        numfd = udpSocketHandle + 1;
        // wait until either socket has data ready to be recv()d (timeout 10.5 secs)
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        /* extract name of interface in order to bind */
        struct ifaddrs *ifaddr = nullptr;
        struct ifaddrs *ifa = nullptr;
        int family  = 0;
        int s = 0;
        int n = 0;

#ifdef DOIP_IPV6
        struct sockaddr_in6 *in6_temp;
        char if_addr_str[INET6_ADDRSTRLEN];
#else
        char host[NI_MAXHOST];
#endif //DOIP_IPV6

        if (getifaddrs(&ifaddr) == -1) {
            LOGE ( &gDoipLogContext, "getifaddrs faild");
        }
        else
        {
            /* Walk through linked list, maintaining head pointer so we
            can free list later */

            for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
                if (ifa->ifa_addr == NULL)
                    continue;

                family = ifa->ifa_addr->sa_family;

#ifdef DOIP_IPV6
                /* For an AF_INET6 interface address, display the address */

                if (family == AF_INET6) {

                    in6_temp = (struct sockaddr_in6*) ifa->ifa_addr;
                    inet_ntop(AF_INET6, &in6_temp->sin6_addr, if_addr_str, sizeof(if_addr_str));
                    //TODO: Check the method with getnameinfo
                    /*s = getnameinfo((struct sockaddr *)in6_temp,sizeof(struct sockaddr_in),host, NI_MAXHOST,NULL, 0, NI_NUMERICHOST);
                    if (s != 0) {
                    	LOGE ( &gDoipLogContext, "getnameinfo failed" );
                    }*/
                    if(!strcmp(if_addr_str,ipAddress.c_str()))
                    {
                        strcpy(interface_name,ifa->ifa_name);
                        break;
                    }

                }
#else
                /* For an AF_INET* interface address, display the address */

                if (family == AF_INET) {


                    s = getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST,NULL, 0, NI_NUMERICHOST);
                    if (s != 0) {
                        LOGE ( &gDoipLogContext, "getnameinfo failed" );
                    }
                    if(!strcmp(host,ipAddress.c_str()))
                    {
                        strcpy(interface_name,ifa->ifa_name);
                        break;
                    }

                }
#endif //DOIP_IPV6

            }
            freeifaddrs(ifaddr);
        }

        int optval = 1;
        (void)setsockopt ( udpSocketHandle, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof ( optval ) );
        (void)setsockopt ( udpSocketHandle, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof ( optval ) );
        struct ifreq ifr;
        memset(&ifr, 0, sizeof(ifr));
        snprintf(ifr.ifr_name, sizeof(ifr.ifr_name),"%s", interface_name);
        LOGI ( &gDoipLogContext, "Interface name is ", std::string(ifr.ifr_name) );
        if (setsockopt(udpSocketHandle, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr)) < 0) {
            perror("setsockpt");
        }

        if ( bind ( udpSocketHandle, ( struct sockaddr * ) &serverAddr, sizeof ( serverAddr ) ) < 0 )
        {
            LOGE ( &gDoipLogContext, "Bind Failed " );
        }
        else
        {
#ifdef DOIP_IPV6
            ipv6_mreq join_req;

            inet_pton(PF_INET6, multicastIpAddress.c_str(), &join_req.ipv6mr_multiaddr);
            join_req.ipv6mr_interface = if_nametoindex(interface_name);

            if ( setsockopt(udpSocketHandle, IPPROTO_IPV6, IPV6_JOIN_GROUP, &join_req, sizeof(join_req)) < 0 )
            {
                LOGE ( &gDoipLogContext, "UDP Socket option failed" );
            }
            else
            {
                setSocketState ( ESocketStateUdp_Ready );
                LOGI ( &gDoipLogContext, "UDP Socket created" );
            }
#else
            broadcastPermission = 1;
            if ( setsockopt ( udpSocketHandle, SOL_SOCKET, SO_BROADCAST, ( void * ) &broadcastPermission, sizeof ( broadcastPermission ) ) < 0 )
            {
                LOGE ( &gDoipLogContext, "UDP Socket option failed" );
            }
            else
            {
                //(void)fcntl(udpSocketHandle, F_SETFL, O_NONBLOCK);
                setSocketState ( ESocketStateUdp_Ready );
                LOGI ( &gDoipLogContext, "UDP Socket created" );
            }
#endif //DOIP_IPV6
        }
    }

}

void CSoAdUdp::rxIndication(uint8_t vlanNo)
{
#ifdef DOIP_IPV6
    struct sockaddr_in6 clientAddr;
    std::vector<uint8_t> udpRxBuff ( udpStackSize );
    uint16_t recvStringLen = 0;
    unsigned int address_length = sizeof ( struct sockaddr_in6 );
#else
    struct sockaddr_in clientAddr;

    std::vector<uint8_t> udpRxBuff ( udpStackSize );
    uint16_t recvStringLen = 0;
    unsigned int address_length = sizeof ( struct sockaddr_in );
#endif //DOIP_IPV6

    readfds = original_socket;
    writefds = original_stdin;//problem
    int recieve = select ( numfd, &readfds, NULL, NULL, &tv );

    if ( recieve == -1 )
    {
        LOGI ( &gDoipLogContext, "error occurred in select()" ); // error occurred in select()
    }
    else if ( recieve == 0 )
    {

    }
    else
    {
        // one or both of the descriptors have data
        if ( FD_ISSET ( udpSocketHandle, &readfds ) ) //if set to read
        {
            FD_CLR ( udpSocketHandle, &readfds ); //clear the set

            memset ( &clientAddr, 0, sizeof ( clientAddr ) );

            /* Receive a single datagram from the server */
            if ( ( recvStringLen = recvfrom ( udpSocketHandle, &udpRxBuff[0], udpRxBuff.size(), 0,
                                              ( struct sockaddr * ) &clientAddr, &address_length ) ) > 0 )
            {

#ifdef DOIP_IPV6
                setClientPort ( clientAddr.sin6_port );
                LOGI ( &gDoipLogContext, "client port number", htons ( clientAddr.sin6_port ) );
                LOGI ( &gDoipLogContext, "received data on UDP" );
                char if_addr_str[INET6_ADDRSTRLEN];
                inet_ntop(AF_INET6, &(clientAddr.sin6_addr), if_addr_str, sizeof(if_addr_str));
                soadCallbackUdp->messageReceived ( true,vlanNo,0, &udpRxBuff, &clientAddr );

#else
                setClientPort ( clientAddr.sin_port );
                LOGI ( &gDoipLogContext, "client port number", htons ( clientAddr.sin_port ) );
                LOGI ( &gDoipLogContext, "received data on UDP" );
                soadCallbackUdp->messageReceived ( true,vlanNo,0, &udpRxBuff, &clientAddr );

                //  memcpy(&ClientSendAddr, &clientAddr,address_length );
#endif //DOIP_IPV6

            }
        }
    }

}

uint8_t CSoAdUdp::getSocketState()
{
    ESocketStateUdp_t ret;
    ret =  udpSocketState;
    return ( uint8_t ) ret;
}

void CSoAdUdp::setSocketState ( ESocketStateUdp_t state )
{
    udpSocketState = state;
    LOGI ( &gDoipLogContext, "UDP Socket State is ", udpSocketState );

}

void CSoAdUdp::scanSockets ( uint8_t vlanNo,uint16_t portNum,std::string address )
{
    uint8_t state = getSocketState();
    LOGI ( &gDoipLogContext, "Scan SocketSocket ", ( uint32_t ) state );

    switch ( state )
    {
        /// # Socket in INIT state, Socket needs to be created.\n
        
    case ESocketStateUdp_Init:
        socketCreate ( portNum,address);
        break;

    /// # Socket in Ready state, Connection established, wating to receive data from the Client.\n

    case ESocketStateUdp_Ready:
        rxIndication(vlanNo);
        break;

    default:
        break;
    }
}

void CSoAdUdp::socketClose()
{
    LOGI ( &gDoipLogContext, "SocketClosed" );

    if ( close ( udpSocketHandle ) >= 0 )
    {
        setSocketState ( ESocketStateUdp_Init );
    }

}

uint16_t CSoAdUdp::getClientPort()
{
    LOGI ( &gDoipLogContext, "Client port nume", udpDstPortNumber );
    return udpDstPortNumber;
}

void CSoAdUdp::setClientPort ( uint16_t udpPortNumber )
{
    udpDstPortNumber = htons ( udpPortNumber );
}

void CSoAdUdp::init()
{

    setSocketState ( ESocketStateUdp_Init );

    LOGI ( &gDoipLogContext, "soad Init Done " );
}

void CSoAdUdp::setSoadCallBackIf ( CSoAdCallbackIf *mpSoAdCallbackIfUdp )
{
    soadCallbackUdp = mpSoAdCallbackIfUdp;
}


