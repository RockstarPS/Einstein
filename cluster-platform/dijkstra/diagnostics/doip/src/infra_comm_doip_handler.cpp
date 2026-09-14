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
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "infra_comm_doip_handler.h"
#include <vector>
#include "dk_logger.h"
#include <iterator>
#include <sstream>

LOG_IMPORT_CONTEXT ( gDoipLogContext );

uint8_t CDoIPHandler::init ( void )
{
    uint8_t i,j;
    uint8_t repeat=0;
    int32_t timerId;
    // mdoIpNoOfSocketsSupported =2;
    // mdoIpNoOfConcurrentSrcAddrSupported=1;
    tcp.reserve( mVlanCount );
    udp.reserve(  mVlanCount );
    sa.reserve(mVlanCount*mdoIpNoOfSocketsSupported);
    sockNr.reserve(mVlanCount*mdoIpNoOfSocketsSupported);
    DoIPSocketState.reserve(mVlanCount*mdoIpNoOfSocketsSupported);
    awaitingAliveCheckResponse.reserve(mVlanCount*mdoIpNoOfSocketsSupported);
    announceCount.reserve(mVlanCount);
    for(j=0; j < mVlanCount; j++)
    {
        repeat =0;
        for ( i = j*mdoIpNoOfSocketsSupported; i < (j+1) * mdoIpNoOfSocketsSupported; i++ ) //total concurrent vlan cnt* number per vlan
        {
            sa.push_back ( 0 );
            sockNr.push_back ( -1 );
            DoIPSocketState.push_back ( SocketStateType_ConnectionInvalid );
            awaitingAliveCheckResponse.push_back ( false );
            ///< Create Timer for Alive Check Response
            timerId = mdoipTimer.addTimer ( [ = ]()
            {
                AliveCheckTimeout ( i );
            } );
            ( void ) saveTimerId ( i, ETimers_AliveCheckResponse, timerId  );
            ///< Create Timer for General Activity
            timerId = mdoipTimer.addTimer ( [ = ]()
            {
                GeneralInactivityTimeout ( i );
            } );
            ( void ) saveTimerId ( i, ETimers_Generalactivity, timerId  );
            ///< Create Timer for Initial Activity
            timerId = mdoipTimer.addTimer ( [ = ]()
            {
                InitialInactivityTimeout ( i );
            } );
            ( void ) saveTimerId ( i, ETimers_InitialInActivity, timerId  );
            if(repeat == 0)
            {
                CSoAdTcp tcpVlanObj;
                tcp.push_back(tcpVlanObj);
                tcp[j].setSoadCallBackIf ( this );
                tcp[j].init();
                repeat =1;
            }
            else
            {
                tcp[j].init();
            }

        }
        timerId = mdoipTimer.addTimer ( [ = ]()
        {
            sendVehicleAnnouncement ( j,NULL );
        } );
        ( void ) saveTimerId ( mUDPProxySocketBase+j, ETimers_AnnounceWait, timerId  );

        timerId = mdoipTimer.addTimer ( [ = ]()
        {
            sendVehicleAnnouncement ( j,NULL );
        } );
        ( void ) saveTimerId ( mUDPProxySocketBase+j, ETimers_AnnounceInterval, timerId  );

        CSoAdUdp udpVlanObj;
        udp.push_back(udpVlanObj);
        udp[j].init();
        udp[j].setSoadCallBackIf ( this );
        uint8_t flagInit=0;
        flag.push_back(flagInit);

    }


    LOGV ( &gDoipLogContext, "Handler Init Done" );
    return 0u;
}


void CDoIPHandler::dataReceivedForDoipOrUdsOnIP ( bool isUdp,uint8_t vlanNo, uint8_t SocketId, const std::vector<uint8_t> *rxBuffer, const void *clientAddr )
{
    LOGV ( &gDoipLogContext, "DOIP Message received" );
    uint32_t payLoadLength = 0;
    bool invalidPayloadLengthFlag = false;
    int32_t lpTimerId = -1;
    if(!isUdp)
    {
        SocketId = SOAD_HANDLER_SOCK_INDEX(vlanNo,mdoIpNoOfSocketsSupported,SocketId);
    }
    else
    {
        SocketId =  vlanNo;  //in case of udp, number of sockets = number of Vlans
    }
    if ( ( ( getProtocolVersion ( rxBuffer ) == DOIP_PROTOCOL_VERSION ) && ( getProtocolInverVersion ( rxBuffer ) == DOIP_PROTOCOL_INVERSE_VERSION ) ) ||
            ( ( getProtocolVersion ( rxBuffer ) == DOIP_PROTOCOL_DEFAULT_VERSION ) && ( getProtocolInverVersion ( rxBuffer ) == DOIP_PROTOCOL_INVERSE_DEFAULT_VERSION ) &&
              ( getPayloadType ( rxBuffer ) >= EPayloadType_VehicleIdRequestMessage ) && getPayloadType ( rxBuffer ) <= EPayloadType_VehicleIdRequestVin ) )
    {
        payLoadLength = getPayloadLength ( rxBuffer ) ;

        /*! 1.DoIP Routing Activation Request from tester \n.
        */
        if (( SocketStateType_ConnectionRegistered == DoIPSocketState.at (  SocketId) ) )
        {
            lpTimerId =  getTimerId ( SocketId, ETimers_Generalactivity  );
            restartTimer ( lpTimerId, mdoIpGenericInactiveTimeMs );
        }


        if ( payLoadLength < maxPayloadLength )
        {
            if ( payLoadLength <= doipStackSize )
            {
                switch ( ( EPayloadType_t ) getPayloadType ( rxBuffer ) )
                {
                /*! 1.DoIP Routing Activation Request from tester \n.
                */
                case EPayloadType_RoutingActivaionRequest:      /* Routing Activation request */
                    if(payLoadLength >= EPayLoadLen_RoutingActivationMin)
                    {
                        LOGI ( &gDoipLogContext, "RoutingActivation Request" );
                        routingActivationReq ( SocketId, rxBuffer );
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                /*! 2. DoIP AliveCheck Resposne from tester.\n
                */
                case EPayloadType_AliveCheckResponse:      /* Alive check response */
                    if(payLoadLength == EPayLoadLen_AliveCheckResponse)
                    {
                        LOGI ( &gDoipLogContext, "AlivecheckResposne" );
                        aliveCheckResp ( SocketId, rxBuffer );
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                /*! 3. DoIP Diagnostic message from tester.\n
                */
                case EPayloadType_DiagnosticMessage:     /* Diagnostic message */
                    if(payLoadLength >= EPayLoadLen_DiagnosticMessageMin)
                    {
                        LOGI ( &gDoipLogContext, "Diagnostic Message" );
                        diagnosticMessage ( SocketId, rxBuffer );
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                case EPayloadType_VehicleAnnouncementOrResponse:
                    break;

                case EPayloadType_VehicleIdRequestMessage:
                case EPayloadType_VehicleIdRequestEid:
                case EPayloadType_VehicleIdRequestVin:
                    if((payLoadLength == EPayLoadLen_VehicleIdRequestMessage) || (payLoadLength == EPayLoadLen_VehicleIdRequestEid)|| (payLoadLength == EPayLoadLen_VehicleIdRequestVin))
                    {
                        LOGI ( &gDoipLogContext, "Vehicle Identification request" );
                        vehicleIdentificationRequest ( vlanNo,rxBuffer, clientAddr );
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                case EPayloadType_DiagPowerModeInfoRequest:
                    if(payLoadLength == EPayLoadLen_DiagPowerModeInfoRequest)
                    {
                        LOGI ( &gDoipLogContext, "Power Mode Request from Tester" );
                        diagnosticPowerModeResponse ( vlanNo,( uint8_t ) EDoIPPowerModeType_NotSupported,clientAddr);
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                case EPayloadType_EntityStatusRequest:
                    if(payLoadLength == EPayLoadLen_EntityStatus)
                    {
                        doipEntityStatusResponse(vlanNo,clientAddr);
                    }
                    else
                    {
                        invalidPayloadLengthFlag = true;
                    }

                    break;

                case EPayloadType_GenericHeaderNegativeAck:

                    if ( rxBuffer->size() >= 9  )
                    {
                        LOGE ( &gDoipLogContext, " Negative Acknowledgment Message  received", "Type", +rxBuffer->at ( 9 ) );
                    }
                    else
                    {
                        LOGE ( &gDoipLogContext, "Invalid Negative Acknowledgment Message  received" );
                    }

                    break;

                default:       /*  Negative Acknowledgments */
                    LOGE ( &gDoipLogContext, "Unknown Payload type" );
                    invalidPayloadLengthFlag = false;
                    createAndSendNack ( isUdp, SocketId, EDoIPPatternErr_UnknownPayloadType,clientAddr );
                    break;
                }
                if(invalidPayloadLengthFlag == true)
                {
                    LOGE ( &gDoipLogContext, "Invalid Payload length" );
                    createAndSendNack ( isUdp, SocketId, EDiagMsgResponse_InvalidPayloadLength,clientAddr );
                    // tcp.socketClose ( SocketId );
                    //  doipSocketClose (SocketId );

                }
            }
            else
            {
                LOGE ( &gDoipLogContext, "Diagnostic message Out of Memory" );
                createAndSendNack ( isUdp,SocketId, EDoIPPatternErr_OutOfMemory,clientAddr );
            }
        }
        else
        {
            LOGE ( &gDoipLogContext, "Diagnostic message too large" );
            createAndSendNack ( isUdp, SocketId, EDoIPPatternErr_DiagMessageTooLarge,clientAddr );

        }
    }
    else
    {
        LOGE ( &gDoipLogContext, "Incorrect Pattern format" );
        createAndSendNack ( isUdp, SocketId, EDoIPPatternErr_IncorrectPatternFormat,clientAddr );
        // tcp.socketClose ( SocketId );
        //   doipSocketClose ( SocketId );

    }

}


void CDoIPHandler::doipSocketClose ( uint8_t socketId )
{
    int32_t lpTimerId;

    sa.at ( socketId )        =   0x0;
    awaitingAliveCheckResponse.at ( socketId )    =   false;
    DoIPSocketState.at ( socketId ) = SocketStateType_ConnectionInvalid;


    lpTimerId =  getTimerId ( socketId, ETimers_Generalactivity  );

    if ( lpTimerId >= 0 )
    {
        mdoipTimer.stopTimer ( lpTimerId );
    }
    else
    {
        LOGE ( &gDoipLogContext, "Timer Id not valid" );
    }


    lpTimerId =  getTimerId ( socketId, ETimers_InitialInActivity  );

    if ( lpTimerId >= 0 )
    {
        mdoipTimer.stopTimer ( lpTimerId );
    }
    uint8_t vlanNo = HANDLER_SOAD_VLAN_INDEX(socketId,mdoIpNoOfSocketsSupported) ;
    socketId = HANDLER_SOAD_SOCK_INDEX(socketId,mdoIpNoOfSocketsSupported);
    tcp[vlanNo].socketClose ( socketId );
}


int32_t CDoIPHandler::saveTimerId ( int32_t socketIndex, ETimer_t eTimer, int32_t timerId  )
{
    int32_t Ret = 0x0;

    std::lock_guard<std::mutex> doipTimer ( mProtectTimerMap );

    mTimerId.insert ( std::make_pair ( std::make_pair ( socketIndex, static_cast<uint8_t> ( eTimer ) ), timerId ) );

    return Ret;
}

int32_t CDoIPHandler::getTimerId ( int32_t socketIndex, ETimer_t eTimer  )
{

    int32_t Ret = -1;
    std::map<std::pair<int32_t, uint8_t>, uint32_t>::iterator lpTimerId;

    std::lock_guard<std::mutex> doipTimer ( mProtectTimerMap );

    lpTimerId = mTimerId.find ( std::make_pair ( socketIndex, static_cast<uint8_t> ( eTimer ) ) );

    if ( lpTimerId == mTimerId.end() )
    {
        LOGE ( &gDoipLogContext, "Timer Id not valid" );
    }
    else
    {
        Ret = lpTimerId->second;
    }

    return Ret;
}

void CDoIPHandler::periodicTask ( void )
{
    uint8_t i,j;                       //i for socket j for Vlan
    bool ipConfigured = false;
    int32_t lpTimerId = -1;
    for(j=0; j < mVlanCount; j++)
    {
        ipConfigured =false;
        for ( i = 0U; i < mdoIpNoOfSocketsSupported; i++ )
        {
            if ( (mIpAddress.size() > j)) //!=0 ))
            {
                if( (mIpAddress[j].size() != 0) )
                {
                    tcp[j].scanSockets (j, i, mPortNum[j], mIpAddress[j] );
                    ipConfigured = true;

                }
            }
            else
            {
                //LOGW ( &gDoipLogContext, "NO valid IP address" );
            }
        }
        if ( ipConfigured == true )
        {
            udp[j].scanSockets (j, mPortNum[j],mIpAddress[j]);
        }

        if ( (udp.size() !=0) && ( udp[j].getSocketState() == 0x02 ) && ( flag[j] == 0 ) )
        {
            LOGV ( &gDoipLogContext, "Announce timer Started" );
            lpTimerId = getTimerId ( mUDPProxySocketBase+j, ETimers_AnnounceWait );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.startTimer ( lpTimerId, mdoIpVehicleAnnounceWaitTimeMs );
                flag[j] = 1;
            }
        }
    }
}

uint8_t CDoIPHandler::getProtocolVersion ( const std::vector<uint8_t> *buffer )
{
    uint8_t version = 0;

    if ( buffer->size() > 1 )
    {
        version = buffer->at ( 0 );
        LOGV ( &gDoipLogContext, "Protocol version", ( uint16_t ) version );
    }

    return version;
}


uint8_t CDoIPHandler:: getProtocolInverVersion ( const std::vector<uint8_t> *buffer )
{
    uint8_t inverseVersion = 0;

    if ( buffer->size() > 2 )
    {
        inverseVersion = buffer->at ( 1 );
        LOGV ( &gDoipLogContext, "Protocol Inverse version", ( uint16_t ) inverseVersion );
    }

    return inverseVersion;
}


uint16_t CDoIPHandler::getPayloadType ( const std::vector<uint8_t> *buffer )
{
    uint16_t payloadType = 0;

    if ( buffer->size() > 4 )
    {
        payloadType  = buffer->at ( 2 ) << 8U ;
        payloadType |= buffer->at ( 3 );
        LOGV ( &gDoipLogContext, "Payload type", payloadType );
    }

    return payloadType;
}



uint32_t CDoIPHandler::getPayloadLength ( const std::vector<uint8_t> *buffer )
{
    uint32_t payloadLength = 0 ;

    if ( buffer->size() > 8 )
    {
        payloadLength  = buffer->at ( 4 ) << 24U;
        payloadLength |= buffer->at ( 5 ) << 16U;
        payloadLength |= buffer->at ( 6 ) << 8U;
        payloadLength |= buffer->at ( 7 );
        LOGV ( &gDoipLogContext, "Payload Length", payloadLength );

    }

    return payloadLength;
}


uint16_t CDoIPHandler::getSourceAddress ( const std::vector<uint8_t> *buffer )
{
    uint16_t sourceAddress = 0;

    if ( mdiagOverIPProtocol != 2 )
    {
        if ( buffer->size() > 10 )
        {
            sourceAddress =  buffer->at ( 8 ) << 8U;
            sourceAddress |= buffer->at ( 9 );
            LOGV ( &gDoipLogContext, "Sourrce address", sourceAddress );
        }
    }
    else
    {
        if ( buffer->size() > 2 )
        {
            sourceAddress =  buffer->at ( 0 ) << 8U;
            sourceAddress |= buffer->at ( 1 );
            LOGV ( &gDoipLogContext, "Sourrce address", sourceAddress );
        }
    }
    return sourceAddress;
}

uint16_t CDoIPHandler::getTargetAddress ( const std::vector<uint8_t> *buffer )
{
    uint16_t targetAddress = 0;

    if ( mdiagOverIPProtocol != 2 )
    {
        if ( buffer->size() > 12 )
        {
            targetAddress =  buffer->at ( 10 ) << 8U ;
            targetAddress |= buffer->at ( 11 ) ;
            LOGV ( &gDoipLogContext, "Target address", targetAddress );
        }
    }
    else
    {
        if ( buffer->size() > 4 )
        {
            targetAddress =  buffer->at ( 2 ) << 8U ;
            targetAddress |= buffer->at ( 3 ) ;
            LOGV ( &gDoipLogContext, "Target address", targetAddress );
        }
    }

    return targetAddress;
}


void CDoIPHandler::stop ( void )
{
    LOGV ( &gDoipLogContext, "DoIP handler Stop" );
    int32_t lpTimerId = -1;
    uint8_t j=0;
	uint8_t socketId;
    for(j=0; j<mVlanCount; j++)
    {
        for ( uint8_t i = 0; i < mdoIpNoOfSocketsSupported; i++ )
        {
            int sindex= j*mdoIpNoOfSocketsSupported + i;
			///< socket close
			uint8_t vlanNo = HANDLER_SOAD_VLAN_INDEX(sindex,mdoIpNoOfSocketsSupported) ;
			socketId = HANDLER_SOAD_SOCK_INDEX(sindex,mdoIpNoOfSocketsSupported);
			tcp[vlanNo].socketClose ( socketId );
            sa.at ( sindex ) = 0;
            sockNr.at ( sindex ) = -1;
            DoIPSocketState.at ( sindex ) = SocketStateType_ConnectionInvalid;
            awaitingAliveCheckResponse.at ( sindex ) = false;

            lpTimerId =  getTimerId ( i, ETimers_AliveCheckResponse  );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.stopTimer ( lpTimerId );
            }
            else
            {
                LOGE ( &gDoipLogContext, "Timer Id not valid" );
            }

            lpTimerId =  getTimerId ( i, ETimers_Generalactivity  );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.stopTimer ( lpTimerId );
            }
            else
            {
                LOGE ( &gDoipLogContext, "Timer Id not valid" );
            }


            lpTimerId =  getTimerId ( i, ETimers_InitialInActivity  );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.stopTimer ( lpTimerId );
            }
            else
            {
                LOGE ( &gDoipLogContext, "Timer Id not valid" );
            }

        }


        mdoipTimer.ResetTimer();
        tcp[j].deInit( );
    }
}


bool CDoIPHandler::sourceAddressKnown ( uint16_t sourceAddress )
{
    bool saKnown = false;
    uint8_t i;

    for ( i = 0U; i <  mdoIpsourceAddressCount; i++ )
    {
        if ( mdoIpSourceAddress.at ( i ) == sourceAddress )
        {
            LOGV ( &gDoipLogContext, "Address matches with configuration" );
            saKnown = true;
            break;
        }
    }

    return saKnown;
}

bool CDoIPHandler::routingTypeSupported ( ERoutingActivationType_t activationType )
{
    bool supported = false;

    if ( mdoIpActivationNumber == ( uint8_t ) activationType )
    {
        LOGV ( &gDoipLogContext, "Routing Activation Supported" );
        supported = true;
    }
    else if(ERoutingActivationType_WWH_OBD == ( uint8_t ) activationType )
    {
        LOGV ( &gDoipLogContext, "Routing Activation Supported type WWH_OBD" );
        supported = true;
    }
    else if(ERoutingActivationType_CentralSecurity == ( uint8_t ) activationType)
    {
        LOGV ( &gDoipLogContext, "Routing Activation Supported type Central Security");
        supported = true;

    }

    return supported;

}


bool CDoIPHandler::authenticationRequired ( uint8_t activationType )
{
    bool req = false;

    if ( mdoIpActivationNumber == activationType )
    {
        if ( mdoIpAuthenticationRequired  ==  true )
        {
            /// Authentication required
            req = true;
        }
        else
        {
            /// Authentication Notrequired
            req = false;
        }

    }

    return req;
}

bool CDoIPHandler::doIpauthenticated ( uint8_t activationType )
{
    return false;
}


bool CDoIPHandler::confirmationRequired ( uint8_t activationType )
{
    bool req = false;

    if ( mdoIpActivationNumber == activationType )
    {
        if ( mdoIpConfirmationRequired == true )
        {
            /// confirmation required
            req = true;
        }
        else
        {
            /// confirmation Not required
            req = false;
        }

    }

    return req;
}



bool CDoIPHandler::confirmed ( uint8_t activationType )
{
    return false;
}



uint8_t CDoIPHandler::assignSocket ( uint8_t socketId, uint16_t sourceAddress )
{
    uint8_t numRegisteredSockets = 0U;
    uint8_t i;
    uint8_t status = 0xFFU;

    for ( i = 0U; i < mVlanCount* mdoIpNoOfSocketsSupported; i++ )
    {
        /*! 1. Check The socket availabilty \n
        */
        if ( SocketStateType_ConnectionRegistered == DoIPSocketState.at ( i ) )
        {
            numRegisteredSockets++;
        }
        if((sa.at(i) == sourceAddress) && (i != socketId) && (SocketStateType_ConnectionRegistered == DoIPSocketState.at ( i )))
        {
            LOGE ( &gDoipLogContext, "Routing Activation failed.The Source Address Already Registered" );
            status = ESocketAssignment_Failed;
            routingActivationResponseCode = ERoutingActivationACK_DeniedSocketAlreadyRegistered;
            return status;
        } 
    }

    if ( 0U == numRegisteredSockets )
    {

        if ( SocketStateType_ConnectionEstablished == DoIPSocketState.at ( socketId ))// && (sockNr.at ( i ) == socketId ) )
        {

            registerSocket ( socketId, socketId, sourceAddress );
            status = ESocketAssignment_Successful;


        }
    }
    else
    {
        /*! 2. There is at least one registered socket already. Let's find out if it's this socket..
        */

        /*! -  We found the TCP socket. Is it registered? \n   */

        if ( DoIPSocketState.at ( socketId ) == SocketStateType_ConnectionRegistered )
        {
            /*! -  We found the registered TCP socket. Is it assigned to this tester (SA)? \n */

            if ( sa.at ( socketId ) == sourceAddress )
            {
                status = ESocketAssignment_Successful;
            }
            else
            {
                routingActivationResponseCode = ERoutingActivationACK_DeniedSocketRegistered;
                status = ESocketAssignment_Failed;
            }
        }
    }

    if ( mdoIpAliveCheckRequired == true )
    {
       if( status == 0xFFU ){
            /*!
                *  Previous For loop terminated; that means that the current socket is currently not registered.
                *
                *  Next up: Check if SA is already registered to another socket...
                */
            for ( i = 0U; i < mVlanCount*mdoIpNoOfSocketsSupported; i++ )
            {
                if ( ( sa.at ( i ) == sourceAddress ) && ( SocketStateType_ConnectionRegistered == DoIPSocketState.at ( i ) ) )
                {
                    /*! perform alive check single SA */
                    startSingleSaAliveCheck(sourceAddress);
                    status = ESocketAssignment_Pending;
                }
            }
        }
    }

    /*!
        * Previous For loop terminated; that means that the current SA is not already registered to another socket.
        *
        * Next up: Check to see that there is a free socket slot available..
        */
    if ( ( status == 0xFFU )) //&&  ( numRegisteredSockets < mdoIpNoOfConcurrentSrcAddrSupported* mVlanCount  ) )
    {
        int8_t connectedSocks =0;
        int8_t vlanIndex = (socketId / mdoIpNoOfSocketsSupported);
        int8_t sockStartIndex= vlanIndex * mdoIpNoOfSocketsSupported;

        for(i= sockStartIndex ; i < sockStartIndex +  mdoIpNoOfSocketsSupported ; i++ )
            if(SocketStateType_ConnectionEstablished == DoIPSocketState.at ( i ) )
                connectedSocks++;
        if(connectedSocks < mdoIpNoOfConcurrentSrcAddrSupported )
        {
            if (( SocketStateType_ConnectionEstablished == DoIPSocketState.at ( socketId ) ) )// && (sockNr.at ( i ) == socketId ) )
            {
                registerSocket ( socketId, socketId, sourceAddress );
                status = ESocketAssignment_Successful;
                LOGV ( &gDoipLogContext, "Socket assignment successful ", status  );
            }
        }
    }

    if ( mdoIpAliveCheckRequired == true )
    {
        if ( status == 0xFFU )
        {
            /*!
                * Previous For loop terminated; that means that there are no free slots.
                *
                * Perform alive check on all registered sockets...
                */
            startAllSaAliveCheck();
            status = ( uint8_t ) ESocketAssignment_Pending;
        }
    }



    return status;
}

int32_t CDoIPHandler::prepareRoutingActivationResponse ( uint16_t sourceAddress,  ERoutingActivationACK_t responseCode, uint8_t socketId )
{
    int32_t byteSent;
    std::vector<uint8_t> buffer;
    buffer.push_back ( DOIP_PROTOCOL_VERSION );
    buffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    buffer.push_back ( ( EPayloadType_RoutingActivationResponse >> 8U ) & 0xFFU ); // 0x0006->Routing Activation Response
    buffer.push_back ( ( EPayloadType_RoutingActivationResponse >> 0U ) & 0xFFU );
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );
    buffer.push_back ( 13U );

    /*! DoIP Message Content */
    buffer.push_back ( ( sourceAddress >> 8U ) & 0xFFU );
    buffer.push_back ( ( sourceAddress >> 0U ) & 0xFFU );
    buffer.push_back ( ( mdoIpTargetAddressePhysical >> 8U ) & 0xFFU );
    buffer.push_back ( ( mdoIpTargetAddressePhysical >> 0U ) & 0xFFU );
    buffer.push_back ( responseCode );
    buffer.push_back ( 0U ); // Reserved
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );
    buffer.push_back ( 0U ); // OEM use
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );
    buffer.push_back ( 0U );

    LOGI ( &gDoipLogContext, "Routing Activation Response", buffer );

    uint8_t indexVlan = HANDLER_SOAD_VLAN_INDEX(socketId, mdoIpNoOfSocketsSupported);
    uint8_t socketTcp  = HANDLER_SOAD_SOCK_INDEX(socketId, mdoIpNoOfSocketsSupported);
    byteSent = tcp[indexVlan].sendIpMessage ( socketTcp, buffer );   
    return byteSent;
}


void CDoIPHandler::startSingleSaAliveCheck ( uint16_t sourceAddress )
{
    uint8_t i;
    int32_t lpTimerId = -1;

    for ( i = 0U; i < mVlanCount*mdoIpNoOfSocketsSupported; i++ )
    {
        if ( ( sa.at ( i ) == sourceAddress ) && ( false == awaitingAliveCheckResponse.at ( i ) ) )
        {
            awaitingAliveCheckResponse.at ( i ) = true;
            //poll for timer Id
            lpTimerId = getTimerId ( i, ETimers_AliveCheckResponse );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.startTimer ( lpTimerId, mdoIpAliveCheckresponseTimeMs );
                prepareAndSendAliveCheckReq ( i );
            }
            else
            {
                LOGE ( &gDoipLogContext, "Timer Id not valid" );
            }
        }
    }
}

void CDoIPHandler::startAllSaAliveCheck ( void )
{
    uint8_t i;
    int32_t lpTimerId = -1;

    for ( i = 0U; i <mVlanCount * mdoIpNoOfSocketsSupported; i++ )
    {
        if ( SocketStateType_ConnectionRegistered == DoIPSocketState.at ( i ) )
        {
            awaitingAliveCheckResponse.at ( i ) = true;
            lpTimerId = getTimerId ( i, ETimers_AliveCheckResponse );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.startTimer ( lpTimerId, mdoIpAliveCheckresponseTimeMs );
                prepareAndSendAliveCheckReq ( i );
            }
            else
            {
                LOGE ( &gDoipLogContext, "Timer Id not valid" );
            }

        }
    }
}


void CDoIPHandler::prepareAndSendAliveCheckReq ( uint8_t Socket_Id )
{
    std::vector<uint8_t> txBuffer;
    int32_t bytesSent;
    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_AliveCheckRequest >> 8U ) & 0xffU ); /*  0x0007->Alive check request */
    txBuffer.push_back ( ( EPayloadType_AliveCheckRequest >> 0U ) & 0xffU );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    uint8_t indexVlan = HANDLER_SOAD_VLAN_INDEX(Socket_Id, mdoIpNoOfSocketsSupported);
    uint8_t sockTcp = HANDLER_SOAD_SOCK_INDEX(Socket_Id, mdoIpNoOfSocketsSupported);
    bytesSent = tcp[indexVlan].sendIpMessage ( sockTcp, txBuffer );

    if ( bytesSent == ( int32_t ) txBuffer.size() )
    {
        LOGI ( &gDoipLogContext, "Alive Check request Sent to the tester" );
    }
}


void CDoIPHandler::registerSocket ( uint8_t slotIndex,  uint8_t socketId,  uint16_t sourceAddress )
{
    int32_t lpTimerId = -1;

    //  sockNr.at ( slotIndex )    =   socketId;
    sa.at ( slotIndex )        =   sourceAddress;
    awaitingAliveCheckResponse.at ( slotIndex )    =   false;
    DoIPSocketState.at ( slotIndex ) = SocketStateType_ConnectionRegistered;
    LOGV ( &gDoipLogContext, " Socked Set to TCP Established State", "Socked Id", +socketId, "Socket Index", +slotIndex );

    lpTimerId = getTimerId ( slotIndex, ETimers_InitialInActivity );

    if ( lpTimerId >= 0 )
    {
        LOGV ( &gDoipLogContext, "Stop InitialInactivityTimer", "SlotIndex", slotIndex, "Socket No @ Slot Index", sockNr.at ( slotIndex ), "Source Address Slot Index", sa.at ( slotIndex ) );
        mdoipTimer.stopTimer ( lpTimerId );
    }
    else
    {
        LOGE ( &gDoipLogContext, "Timer Id not found" );
    }

    lpTimerId = getTimerId ( slotIndex, ETimers_Generalactivity );

    if ( lpTimerId >= 0 )
    {
        LOGV ( &gDoipLogContext, "Start General Inactivity Timer", "SlotIndex", slotIndex, "Socket No @ Slot Index", sockNr.at ( slotIndex ), "Source Address Slot Index", sa.at ( slotIndex ) );
        mdoipTimer.startTimer ( lpTimerId, mdoIpGenericInactiveTimeMs );
    }
    else
    {
        LOGE ( &gDoipLogContext, "Timer Id not found" );
    }
}

void CDoIPHandler::createAndSendDiagnosticNack ( uint8_t  sockNr, uint16_t sourceAddress, uint16_t targetAddress, uint8_t nackCode )
{
    std::vector<uint8_t> txBuffer;
    int32_t  bytesSent;

    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_DiagnosticMessageNegativeAck >> 8U ) & 0xFFU ); /* 0x8003->Diagnostic Negative Response */
    txBuffer.push_back ( ( EPayloadType_DiagnosticMessageNegativeAck >> 0U ) & 0xFFU );
    txBuffer.push_back ( ( doipDiagResLenght >> 24U ) & 0xFFU );  /* Length = 0x00000005 */
    txBuffer.push_back ( ( doipDiagResLenght >> 16U ) & 0xFFU );
    txBuffer.push_back ( ( doipDiagResLenght >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( doipDiagResLenght >> 0U ) & 0xFFU );
    txBuffer.push_back((sourceAddress >> 8U) & 0xFFU);	/* Source Address */
    txBuffer.push_back((sourceAddress >> 0U) & 0xFFU);
    txBuffer.push_back((targetAddress >> 8U) & 0xFFU);	/* Target Address */
    txBuffer.push_back((targetAddress >> 0U) & 0xFFU);
    txBuffer.push_back ( nackCode ); /* Nack Code */

    //rajin. please confirm the order of SA and TA

    uint8_t indexVlan = HANDLER_SOAD_VLAN_INDEX(sockNr,mdoIpNoOfSocketsSupported);
    uint8_t sockTcp   = HANDLER_SOAD_SOCK_INDEX(sockNr,mdoIpNoOfSocketsSupported);
    bytesSent = tcp[indexVlan].sendIpMessage ( sockTcp, txBuffer );

    if ( bytesSent != ( int32_t ) ( txBuffer.size() ) )
    {
        /*Do Nothing*/
    }
    else
    {
        LOGI ( &gDoipLogContext, "Diagnostic message Negative Acknowledgement" );
    }
}

void CDoIPHandler::createAndSendDiagnosticAck ( uint8_t sockNr, uint16_t sourceAddress, uint16_t targetAddress )
{
    int32_t bytesSent;
    std::vector<uint8_t> txBuffer;

    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_DiagnosticMessagePositiveAck >> 8U ) & 0xffU ); /* 0x8002->Diagnostic Positive Response */
    txBuffer.push_back ( ( EPayloadType_DiagnosticMessagePositiveAck >> 0U ) & 0xffU );
    txBuffer.push_back ( ( doipDiagResLenght >> 24U ) & 0xFFU ); /* Length = 0x00000005 */
    txBuffer.push_back ( ( doipDiagResLenght >> 16U ) & 0xFFU );
    txBuffer.push_back ( ( doipDiagResLenght >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( doipDiagResLenght >> 0U ) & 0xFFU );
    txBuffer.push_back ( ( sourceAddress >> 8U ) & 0xFFU ); /* Target Address */
    txBuffer.push_back ( ( sourceAddress >> 0U ) & 0xFFU );
    txBuffer.push_back ( ( targetAddress >> 8U ) & 0xFFU ); /* Source Address */
    txBuffer.push_back ( ( targetAddress >> 0U ) & 0xFFU );
    txBuffer.push_back ( 0 );   /// Ack Code

    uint8_t indexVlan = HANDLER_SOAD_VLAN_INDEX(sockNr, mdoIpNoOfSocketsSupported);
    uint8_t sockTcp   = HANDLER_SOAD_SOCK_INDEX (sockNr, mdoIpNoOfSocketsSupported);
    bytesSent = tcp[indexVlan].sendIpMessage ( sockTcp, txBuffer );
    //bytesSent = tcp.sendIpMessage ( sockNr, txBuffer );

    if ( bytesSent != ( int32_t ) ( txBuffer.size() ) )
    {
        LOGE ( &gDoipLogContext, "Diagnostic message Not send to tester" );
    }
    else
    {
        LOGI ( &gDoipLogContext, "Diagnostic message Positive Acknowledgement" );
    }
}

bool CDoIPHandler::targetAddressSupported ( uint16_t ta )
{
    uint8_t index;
    bool status = false;

    if ( ta == mdoIpTargetAddressePhysical )
    {
        LOGI ( &gDoipLogContext, "Receive Physical Target Address is suppoerted" );
        status = true;
    }
    else
    {
        for ( index = 0U; index < ( mdoIpTargetAddressCount - 1 ); index++ )
        {
            if ( mdoIpTargetAddressesFunctional.at ( index ) == ta )
            {
                LOGI ( &gDoipLogContext, "Receive Functional Target Address is suppoerted" );
                status = true;
                break;
            }
        }
    }

    return status;
}



void CDoIPHandler::routingActivationReq ( uint8_t socketId, const std::vector<uint8_t> *rxBuffer )
{
    uint16_t sourceAddress;
    ERoutingActivationType_t activationType;
    bool         authenticated = false;
    ESocketAssignment_t socketRegistrationSatus;

    /*! -# Handle the Routing activation request \n
           - Check the Socket Availabilty\n
           - On Availabality of Socket, check for authentication and confimation required\n
           - Based on the config_SocketMgruration Routing activation response send to the tester
    */
    if ( ( getPayloadLength ( rxBuffer ) == 7U ) || ( getPayloadLength ( rxBuffer ) == 11U ) )
    {
        sourceAddress = getSourceAddress ( rxBuffer );
        activationType = ( ERoutingActivationType_t ) rxBuffer->at ( 10 );
        LOGV ( &gDoipLogContext, "activation", activationType );

        if ( true == sourceAddressKnown ( sourceAddress ) )
        {
            /*! 1. check for valid sourceAddress */
            LOGV ( &gDoipLogContext, "source address known" );

            if ( routingTypeSupported ( activationType ) )
            {
                /*! 2. check for Routing type Support */
                LOGV ( &gDoipLogContext, "Activation type supported" );
                socketRegistrationSatus = ( ESocketAssignment_t ) assignSocket ( socketId, sourceAddress );

                if ( ESocketAssignment_Successful == socketRegistrationSatus )
                {
                    if ( true == authenticationRequired ( ( uint8_t ) activationType ) )
                    {
                        authenticated = doIpauthenticated ( ( uint8_t ) activationType );
                    }
                    else
                    {
                        authenticated = true;
                    }

                    if ( authenticated )
                    {
                        if ( true == confirmationRequired ( ( uint8_t ) activationType ) )
                        {
                            if ( true == confirmed ( ( uint8_t ) activationType ) )
                            {
                                /*! 3.  Routing successfully activated */
                                routingActivationResponseCode = ERoutingActivationACK_DoneSuccessfully;
                            }
                            else
                            {
                                /*! 4.  Routing will be activated; confirmation required */
                                routingActivationResponseCode = ERoutingActivationACK_DoneConfirmPending;
                            }
                        }
                        else
                        {
                            /*! 5.Routing successfully activated */
                            routingActivationResponseCode = ERoutingActivationACK_DoneSuccessfully;
                        }
                    }
                    else
                    {
                        /*! 6. Routing activation rejected due to missing authentication */
                        routingActivationResponseCode = ERoutingActivationACK_DeniedMissingAuth;
                    }

                    (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, socketId );

                }
                else if ( ESocketAssignment_Pending == socketRegistrationSatus )
                {
                    /*! 7.
                     * Trying to assign a connection slot, but pending
                     * alive check responses before continuing.\n
                     * Continuation handled from DoIp_MainFunction (if a
                     * connection times out and thus becomes free) or from
                     * handleAliveCheckResp (if all connections remain
                     * active)
                     */

                    //  for ( i = 0U; i < mdoIpNoOfSocketsSupported; i++ )
                    {
                        //     if ( ( sockNr.at ( i ) ==  socketId ) && ( SocketStateType_ConnectionEstablished == DoIPSocketState.at ( i ) ) )
                        {
                            //          pendingRoutingActivationSocketIndex = i;
                            //          break;
                        }
                    }
                    pendingRoutingActivationSocketIndex = socketId;

                    pendingRoutingActivationSa = sourceAddress;
                    pendingRoutingActivationSocket = socketId;
                    routingActivationResponseCode = ERoutingActivationACK_DoneSuccessfully;

                }
                else
                {
                    (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, socketId );
                }
            }
            else
            {
                routingActivationResponseCode = ERoutingActivationACK_DeniedUnsupportedRAType;
                (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, socketId );
            }
        }
        else
        {
            /** @req DoIP-059 */
            routingActivationResponseCode = ERoutingActivationACK_DeniedUnknownSA;
            (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, socketId );
        }

        switch ( routingActivationResponseCode )
        {
        case ERoutingActivationACK_DoneSuccessfully: /// Routing activated.
#ifdef DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION                        

            notifyUdsAppOnRoutingActivation(sourceAddress);
            break; 
                             
#endif //DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION                
        case ERoutingActivationACK_DoneConfirmPending: /// Confirmation pending
        case ERoutingActivationACK_DeniedMissingAuth: /// Missing authentication
            break;

        default:
            doipSocketClose ( socketId );

            break;
        }
    }
    else
    {
        createAndSendNack ( false, socketId, EDiagMsgResponse_InvalidPayloadLength,NULL );
        doipSocketClose (socketId );

    }

}

void CDoIPHandler::aliveCheckResp ( uint8_t socketId, const std::vector<uint8_t> *rxBuffer )
{
    uint8_t i;
    uint16_t sourceAddress;
    uint32_t payloadLength = sizeof ( rxBuffer );
    uint8_t remainingConnections = 0U;
    int32_t lpTimerId = -1;
    //rajin
    payloadLength = getPayloadLength ( rxBuffer );
    bool sameSourceAddress = false;

    if ( payloadLength == 2U )
    {
        sourceAddress = getSourceAddress ( rxBuffer );

        //  i=socketId;

        if ( sa.at ( socketId ) == sourceAddress )
        {
            ///< rajin
            if ( pendingRoutingActivationSocket != -1 )
            {
                if ( pendingRoutingActivationSa == sourceAddress )
                {
                    sameSourceAddress = true;
                }
            }

            /*! Alive check response received in time */
            awaitingAliveCheckResponse. at ( socketId ) = false;

            lpTimerId = getTimerId ( socketId, ETimers_AliveCheckResponse );

            if ( lpTimerId >= 0 )
            {
                mdoipTimer.stopTimer ( lpTimerId );
            }
        }



        ///< Connections remaining to receive alive check responses for
        for ( i = 0U; i < mVlanCount * mdoIpNoOfSocketsSupported; i++ )
        {
            if ( true == awaitingAliveCheckResponse.at ( i ) )
            {
                remainingConnections++;
            }
        }


        if ( sameSourceAddress == true )
        {
            if ( pendingRoutingActivationSocket != -1 )
            {
                routingActivationResponseCode = ERoutingActivationACK_DeniedSocketAlreadyRegistered;
                (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, pendingRoutingActivationSocket );
                ///< tcp.socketClose ( pendingRoutingActivationSocket  );
                doipSocketClose (pendingRoutingActivationSocket );
                pendingRoutingActivationSocket = -1;
                pendingRoutingActivationSocketIndex = -1;
            }
        }
        else if (  0U == remainingConnections )
        {
            ///< if '0' remaining connections pending socket if any
            if ( pendingRoutingActivationSocket != -1 )
            {
                routingActivationResponseCode = ERoutingActivationACK_DeniedAllSocketsActive;
                (void)prepareRoutingActivationResponse ( sourceAddress, routingActivationResponseCode, pendingRoutingActivationSocket );
                ///<  tcp.socketClose ( pendingRoutingActivationSocket );
                doipSocketClose (pendingRoutingActivationSocket );
                pendingRoutingActivationSocket = -1;
                pendingRoutingActivationSocketIndex = -1;
            }
        }
        else
        {
            ///< No code Required
        }

    }
    else
    {
        LOGI ( &gDoipLogContext, "No valid payload received " );

    }

}


void CDoIPHandler::AliveCheckTimeout ( uint8_t connectionIndex )
{

    if ( connectionIndex < sa.size() )
    {
        LOGI ( &gDoipLogContext, "Alive Check Timeout for Socket Index =", +connectionIndex, "Source Address ", +sa.at ( connectionIndex ) );
        handleTimeout ( connectionIndex );
    }
    else
    {
        LOGI ( &gDoipLogContext, "Invalid Connection Index received for Alive Check Timeout = ", +connectionIndex );

    }
}

void CDoIPHandler::InitialInactivityTimeout ( uint8_t connectionIndex )
{
    if ( connectionIndex < sa.size() )
    {
        LOGI ( &gDoipLogContext, "Initial Inactivity Timeout for Socket Index =", +connectionIndex, "Source Address ", +sa.at ( connectionIndex ) );
        handleTimeout ( connectionIndex );
    }
    else
    {
        LOGI ( &gDoipLogContext, "Invalid Connection Index received for Initial activity  Timeout = ", connectionIndex );

    }
}


void CDoIPHandler::GeneralInactivityTimeout ( uint8_t connectionIndex )
{
    if ( connectionIndex < sa.size() )
    {
        LOGI ( &gDoipLogContext, "General Inactivity Timeout for Socket Index =", connectionIndex, "Source Address ", sa.at ( connectionIndex ) );
        handleTimeout ( connectionIndex );
    }
    else
    {
        LOGI ( &gDoipLogContext, "Invalid Connection Index received for General activity  Timeout = ", connectionIndex );
    }
}


void CDoIPHandler::handleTimeout ( uint8_t connectionIndex )
{
    routingActivationResponseCode = ERoutingActivationACK_DoneSuccessfully;

    LOGI ( &gDoipLogContext, "HandleTimeout", ( uint16_t ) connectionIndex );
    doipSocketClose ( connectionIndex); // sockNr.at ( connectionIndex ) );

    if ( ( pendingRoutingActivationSocket != -1 ) )
    {
        registerSocket ( pendingRoutingActivationSocketIndex, pendingRoutingActivationSocket, pendingRoutingActivationSa );
        (void)prepareRoutingActivationResponse ( pendingRoutingActivationSa, routingActivationResponseCode, pendingRoutingActivationSocket );
        pendingRoutingActivationSocket = -1;
        pendingRoutingActivationSocketIndex = -1;
    }
    else
    {
        /// Ordinary timeout set connection as free...
        DoIPSocketState.at ( connectionIndex ) = SocketStateType_ConnectionInvalid;
        awaitingAliveCheckResponse.at ( connectionIndex ) = false;
    }
}


void CDoIPHandler::createAndSendNack ( bool isUdp, uint8_t sockNr, uint8_t nackCode,const void *clientAddr  )
{
    int32_t bytesSent;
    std::vector<uint8_t> txBuffer;
    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( 0x00U );
    txBuffer.push_back ( 0x00U );
    txBuffer.push_back ( 0 );
    txBuffer.push_back ( 0 );
    txBuffer.push_back ( 0 );
    txBuffer.push_back ( 1 );
    txBuffer.push_back ( nackCode );
    uint8_t vlanNo = (sockNr/mdoIpNoOfSocketsSupported) ;
    uint8_t socketId = sockNr % mdoIpNoOfSocketsSupported;
    if(isUdp == false )
    {
        bytesSent = tcp[vlanNo].sendIpMessage ( socketId, txBuffer );

        if( (nackCode == EDoIPPatternErr_IncorrectPatternFormat) || (nackCode == EDoIPPatternErr_InvalidPayloadLength ))
        {
            doipSocketClose ( sockNr );
        }

        if ( bytesSent == ( int32_t ) ( doipHeaderLength + 1U ) )
        {
            //cout<<"Sent Negative acknowledgment\n";
        }
    }
    else
    {
#ifdef DOIP_IPV6
        if(clientAddr != NULL) {
            sockaddr_in6 clientAddress = * ( ( sockaddr_in6 * ) clientAddr );
            bytesSent = udp[vlanNo].sendMessageIPv6( mPortNum[vlanNo], txBuffer, &clientAddress);
        } else {
            bytesSent = udp[vlanNo].sendMessageIPv6( mPortNum[vlanNo], txBuffer, NULL);
        }
#else
        sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );

        bytesSent = udp[vlanNo].sendMessage( mPortNum[vlanNo],txBuffer, &clientAddress);
#endif //DOIP_IPv6

        if( (nackCode == EDoIPPatternErr_IncorrectPatternFormat) || (nackCode == EDoIPPatternErr_InvalidPayloadLength ))
        {
            udp[vlanNo].socketClose();
        }

        if ( bytesSent == ( int32_t ) ( doipHeaderLength + 1U ) )
        {
            //cout<<"Sent Negative acknowledgment\n";
        }
    }
}


void CDoIPHandler::diagnosticMessage ( uint8_t socketId, const std::vector<uint8_t> *rxBuffer )
{
    uint16_t sourceAddress = 0x0000U;
    uint16_t targetAddressDiag = 0x0000U;
    uint8_t knownSource = 0x00U;
    uint8_t diagnosticAckCode ;
    EDiagMsgResponse_t diagnosticNackCode = ( EDiagMsgResponse_t ) 0xFF;
    uint8_t doipResult;
    uint8_t taType = 0xFFU;
    uint8_t buffer[doipStackSize];
    uint32_t    payloadLength;
    uint8_t validLength = 0U;

    /*! -# Check the received diagnostic Message\n
            -  Source Address already config_SocketMgrured or not \n
            -  Target Address already config_SocketMgrured or not \n
        - If routing activation required, Check for the socket has been registered already
        - on Success full verification Send the Diagnostic message to the diagnostic mandger\n

    */
    payloadLength = getPayloadLength ( rxBuffer );

    if ( mdiagOverIPProtocol != 2 )
    {
        if ( ( getPayloadLength ( rxBuffer ) >= 4U ) )
        {
            validLength = 1;
            LOGI ( &gDoipLogContext, "Diagnostic Message with DOIP header" );
        }
    }
    else
    {
        validLength = 1;
        LOGI ( &gDoipLogContext, "Diagnostic Message with Soad header" );

    }
    if ( validLength )
    {
        sourceAddress = getSourceAddress ( rxBuffer );
        targetAddressDiag = getTargetAddress ( rxBuffer );

        /*! -# 1. Check the valid Source Adrress \n
            */
        /*! -# Check if routing activation required, Check for the socket has been registered already
        */
        if ( ( mdoIpRoutingActivationRequired ) == true )
        {
            LOGI ( &gDoipLogContext, "Routing Activation required" );

            if ( ( DoIPSocketState.at ( socketId ) == SocketStateType_ConnectionRegistered ) && ( sa.at ( socketId ) == getSourceAddress ( rxBuffer ) ) )
            {
                LOGI ( &gDoipLogContext, "Source Address Registered" );
                knownSource = 1U;
            }
            else
            {
                LOGI ( &gDoipLogContext, "Source Address Not Registered" );

            }
        }
        else if ( ( DoIPSocketState.at ( socketId ) != SocketStateType_ConnectionRegistered ) && ( sourceAddressKnown ( getSourceAddress ( rxBuffer ) ) == true ) )
        {
            /*! -# If not routing activation required, register the source address and socketID
            */
            LOGI ( &gDoipLogContext, "new Source Address Registered" );
            registerSocket ( socketId, socketId, getSourceAddress ( rxBuffer ) );
            knownSource  =  1U;
        }
        /// what is the point rajin ?
#if 0
        else if ( ( DoIPSocketState.at ( i ) == SocketStateType_ConnectionRegistered ) && ( sourceAddressKnown ( getSourceAddress ( rxBuffer ) ) == true ) )
        {
            /*! -# If not routing activation required, register the source address and socketID
            */
            LOGI ( &gDoipLogContext, " Already Source Address Registered" );
            knownSource  =  1U;
            //break;
        }
#endif



        if ( knownSource == 0x01U )
        {
            /*! -# 2. Check the valid TargetAdrress \n
            */
            if ( targetAddressSupported ( targetAddressDiag ) == true )
            {
                diagnosticAckCode = ( uint8_t ) EDiagMsgResponse_MsgOk;

                taType  = findTargetType ( targetAddressDiag );

                doipResult = diagnosticAckCode;

                /*! 3. Send message to the UDS
                */
                if ( mdiagOverIPProtocol != 2 )
                {
                    std::copy ( rxBuffer->begin() + 12, rxBuffer->end(), buffer );                    
#ifndef DOIP_DIAGACK_WITH_PROPER_TA
                    createAndSendDiagnosticAck ( socketId, mdoIpTargetAddressePhysical, sourceAddress );     /* send positive acknowledgment to the TEster */
#else                    
                    createAndSendDiagnosticAck ( socketId, targetAddressDiag, sourceAddress );               /* send positive acknowledgment to the TEster */
#endif                    
                    messageIndication ( sourceAddress, targetAddressDiag, taType, buffer,  payloadLength - 4U,  doipResult  ); /* Send the UDS mesg to the UDS Manager */
                    //this is needed?          createAndSendDiagnosticAck ( socketId, mdoIpTargetAddressePhysical , sourceAddress );    /* send positive acknowledgment to the TEster */
                }
                else
                {

                    std::copy ( rxBuffer->begin() + 8, rxBuffer->end(), buffer );
                    messageIndication ( sourceAddress, targetAddressDiag, taType, buffer,  payloadLength,  doipResult  );  /* Send the UDS mesg to the UDS Manager */

                }
            }
            else if ( mdiagOverIPProtocol != 2 )
            {
                diagnosticNackCode =  EDiagMsgResponse_UnknowntargetAddr;
            }

        }
        else if ( mdiagOverIPProtocol != 2 )
        {
            diagnosticNackCode = EDiagMsgResponse_InvalidSourceAddr;
        }
    }
    else if ( mdiagOverIPProtocol != 2 )
    {
        createAndSendNack ( false, socketId, EDiagMsgResponse_InvalidPayloadLength,NULL );
        //tcp.socketClose ( socketId );
        doipSocketClose ( socketId );
    }

    if ( ( diagnosticNackCode != ( EDiagMsgResponse_t ) 0xFF ) && ( mdiagOverIPProtocol != 2 ) )
    {
        createAndSendDiagnosticNack (socketId, mdoIpTargetAddressePhysical, sourceAddress, ( uint8_t ) diagnosticNackCode );
    }

}


void CDoIPHandler::dataTrasferRequest ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t TAType, const uint8_t *pMessageData, uint32_t  messageLength )
{
    uint32_t tempmessageLength = messageLength + 4U;    /* Response Length from UDS and 4 bytes of Source/Target address*/
    std::vector<uint8_t> txBuffer;
    int32_t bytesSent =-1;
    uint8_t index ;
    uint8_t socketId = 11U;//0U; rajin
    uint8_t tcpSocketId =0;
    EDiagMsgResponse_t doIPResult = EDiagMsgResponse_MsgOk;
    int32_t lpTimerId = -1;
    if ( mdiagOverIPProtocol != 2 )
    {
        txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
        txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
        txBuffer.push_back ( ( EPayloadType_DiagnosticMessage >> 8U ) & 0xFFU ); /* 0x8002->Diagnostic Positive Response */
        txBuffer.push_back ( ( EPayloadType_DiagnosticMessage >> 0U ) & 0xFFU );
        txBuffer.push_back ( ( tempmessageLength >> 24U ) & 0xFFU ) ; /* Length */
        txBuffer.push_back ( ( tempmessageLength >> 16U ) & 0xFFU );
        txBuffer.push_back ( ( tempmessageLength >> 8U ) & 0xFFU );
        txBuffer.push_back ( ( tempmessageLength >> 0U ) & 0xFFU );
        txBuffer.push_back ( ( sourceAddress >> 8U ) & 0xFFU ); /* Target Address */
        txBuffer.push_back ( ( sourceAddress >> 0U ) & 0xFFU );
        txBuffer.push_back ( ( targetAddress >> 8U ) & 0xFFU ); /* Source Address */
        txBuffer.push_back ( ( targetAddress >> 0U ) & 0xFFU );
    }
    else
    {
        txBuffer.push_back ( ( sourceAddress >> 8U ) & 0xFFU ); /* Target Address */
        txBuffer.push_back ( ( sourceAddress >> 0U ) & 0xFFU );
        txBuffer.push_back ( ( targetAddress >> 8U ) & 0xFFU ); /* Source Address */
        txBuffer.push_back ( ( targetAddress >> 0U ) & 0xFFU );
        txBuffer.push_back ( ( messageLength >> 24U ) & 0xFFU ) ; /* Length */
        txBuffer.push_back ( ( messageLength >> 16U ) & 0xFFU );
        txBuffer.push_back ( ( messageLength >> 8U ) & 0xFFU );
        txBuffer.push_back ( ( messageLength >> 0U ) & 0xFFU );
    }

    std::copy ( &pMessageData[0], &pMessageData[0] + messageLength, back_inserter ( txBuffer ) );
    int8_t vlanNo = -1;
    for ( index = 0U; index < mVlanCount* mdoIpNoOfSocketsSupported; index++ )
    {
        /// 1. Verify the Source  address regisetered amd Target address are same*/
        if ( sa.at ( index )  == targetAddress )
        {
            socketId =index;
            // socketId =  sockNr.at ( index );
            vlanNo = (socketId / mdoIpNoOfSocketsSupported ) ;
            tcpSocketId = socketId % mdoIpNoOfSocketsSupported;
            break;
        }
    }

    if(vlanNo != -1)
    {
        bytesSent = tcp[vlanNo].sendIpMessage ( tcpSocketId, txBuffer );
        if (( SocketStateType_ConnectionRegistered == DoIPSocketState.at (  socketId) ) )
        {
            lpTimerId =  getTimerId ( socketId, ETimers_Generalactivity  );
            restartTimer ( lpTimerId, mdoIpGenericInactiveTimeMs );
        }
    }
    if ( bytesSent == ( int32_t )(txBuffer.size() ))
    {
        LOGV ( &gDoipLogContext, " Sent Confirmation to the UDS for Successful transmission to the tester" );
        /* Send confirmation to the UDS Manager */
        doIPResult =  EDiagMsgResponse_MsgOk;
        messsageConfirmation ( sourceAddress, targetAddress, TAType, ( uint8_t ) doIPResult );
    }
    else
    {
        LOGE ( &gDoipLogContext, " Sent Confirmation to the UDS for UnSuccessful transmission to the tester " );
        doIPResult = EDiagMsgResponse_TargetUnreachable;
        messsageConfirmation ( sourceAddress, targetAddress, TAType, ( uint8_t ) doIPResult );
    }
}

void CDoIPHandler::setDoIPDefaultConfig ( SDoIPConfig_t *DoIPConfig )
{
    mdoIpSourceAddress.clear();
//   DoIPConfig->doIpConcurrentSrcAddrSupportCnt =1;
    mdoIpTargetAddressesFunctional.clear();
    mVlanCount                      =  DoIPConfig->doIpVlanCount;
    mdoIpNoOfSocketsSupported =        ( DoIPConfig->doIpConcurrentSrcAddrSupportCnt ) + 1U ; ///< N+1 TCP sockets
    mdoIpNoOfConcurrentSrcAddrSupported = DoIPConfig->doIpConcurrentSrcAddrSupportCnt;
    mdoIpsourceAddressCount         =   DoIPConfig->doIpSourceAddressCount;

    mdoIpAliveCheckresponseTimeMs   =   DoIPConfig->doIpAliveCheckresponseTimeMs / DOIP_PERIODIC_TIMER_IN_MS; ///< Convert ms to Resolution Ticks
    mdoIpGenericInactiveTimeMs      =   DoIPConfig->doIpGenericInactiveTimeMs / DOIP_PERIODIC_TIMER_IN_MS; ///< Convert ms to Resolution Ticks
    mdoIpInitialInactiveTimeMs      =   DoIPConfig->doIpInitialInactiveTimeMs / DOIP_PERIODIC_TIMER_IN_MS; ///< Convert ms to Resolution Ticks
    mdoIpVehicleAnnounceIntervalTimeMs = DoIPConfig->doIpVehicleAnnounceIntervalTimeMs / DOIP_PERIODIC_TIMER_IN_MS; ///< Convert ms to Resolution Ticks
    mdoIpVehicleAnnounceWaitTimeMs =    DoIPConfig->doIpVehicleAnnounceWaitTimeMs / DOIP_PERIODIC_TIMER_IN_MS; ///< Convert ms to Resolution Ticks

    mdoIpActivationNumber           =   DoIPConfig->doIpActivationNumber;
    mdoIpRoutingActivationRequired  =   DoIPConfig->doIpRoutingActivationRequired;
    mdoIpAliveCheckRequired         =   DoIPConfig->doIpAliveCheckRequired;
    mdoIpAuthenticationRequired     =   DoIPConfig->doIpAuthenticationRequired;
    mdoIpConfirmationRequired       =   DoIPConfig->doIpConfirmationRequired;
    mdoIpTargetAddressePhysical     =   DoIPConfig->doIpTargetAddressePhysical;  /// DoIP Target Address
    mdoIpTargetAddressCount         =   DoIPConfig->doIpTargetAddressCount;
    mdiagOverIPProtocol             =   DoIPConfig->diagOverIPProtocol;


    LOGI ( &gDoipLogContext, "Alive Check Required", +mdoIpAliveCheckRequired );
    std::copy ( DoIPConfig->doIpSourceAddress.begin(), DoIPConfig->doIpSourceAddress.end(), back_inserter ( mdoIpSourceAddress ) );
    std::copy ( DoIPConfig->doIpTargetAddressesFunctional.begin(), DoIPConfig->doIpTargetAddressesFunctional.end(), back_inserter ( mdoIpTargetAddressesFunctional ) );
}

void CDoIPHandler::messageIndication ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t targetAddressType, uint8_t *pMessageData, uint32_t messageLength, uint8_t result )
{
    DoipDiagDataIndication dataInd ;

    //(void)memset(&(dataInd.data[0]),0u,6154);
    ( void ) memset ( & ( dataInd.data[0] ), 0u, messageLength );

    dataInd.sourceAddress = sourceAddress;
    dataInd.targetAddress = targetAddress;
    dataInd.targetAddressType = targetAddressType;
    dataInd.dataLen = messageLength;
    dataInd.result  = result;
    /// copy data
    ( void ) memcpy ( & ( dataInd.data[0] ), pMessageData, messageLength );
    LOGI ( &gDoipLogContext, "DoIP:: Send Diagnostic Data to UDS" );
    DK_RTE_Send_DoipDiagDataIndication ( dataInd );
}

void CDoIPHandler::messsageConfirmation ( uint16_t sourceAddress, uint16_t targetAddress, uint8_t targetAddressType, uint8_t result )
{
    DoipDiagDataConfirmation dataConfirm;
    LOGI ( &gDoipLogContext, "DoIP::Message_Confirmation" );
    dataConfirm.sourceAddress = sourceAddress;
    dataConfirm.targetAddress = targetAddress;
    dataConfirm.targetAddressType = targetAddressType;
    dataConfirm.result  = result;
    DK_RTE_Send_DoipDiagDataConfirmation ( dataConfirm );
}

void CDoIPHandler::doipTimerBaseTick ( void )
{
    mdoipTimer.timerBaseTickTask();
}

void CDoIPHandler::restartTimer ( int32_t timerId, uint32_t timoeCount )
{
    mdoipTimer.startTimer ( timerId, timoeCount );
}

void CDoIPHandler::messageReceived ( bool isUdp, uint8_t vlanNo,uint8_t socketId, const std::vector<uint8_t> *rxBuffer, const void *clientAddr )
{
    if ( mdiagOverIPProtocol != 2 )
    {
        dataReceivedForDoipOrUdsOnIP ( isUdp, vlanNo,socketId, rxBuffer, clientAddr );
    }
    else
    {
        dataReceivedForSoAd ( socketId, rxBuffer );
    }

}

uint8_t  CDoIPHandler::findTargetType ( uint16_t targetAddress )
{
    uint8_t taType = DOIP_TATYPE_PHYSICAL;

    if ( mdiagOverIPProtocol != 2 )
    {
        if ( ( targetAddress <= 0xE3FFU ) && ( targetAddress >= 0xE000U ) )
        {
            taType = DOIP_TATYPE_PHYSICAL;              /* physical address */
            LOGI ( &gDoipLogContext, "TA type is Physical" );
        }
        else if ( ( targetAddress <= 0xEFFFU ) && ( targetAddress >= 0xE400U ) )
        {
            taType = DOIP_TATYPE_FUNCTIONAL;            /* Functional address*/
            LOGI ( &gDoipLogContext, "TA type is Functional" );
        }
        else if ( ( targetAddress <= 0x0DFFU ) && ( targetAddress >= 0x0001U ) )
        {
            taType = DOIP_TATYPE_PHYSICAL;              /* physical address */
            LOGI ( &gDoipLogContext, "TA type is Physical" );
        }
    }
    else
    {
        if ( targetAddress == mdoIpTargetAddressePhysical )
        {
            taType = DOIP_TATYPE_PHYSICAL;      /* physical address */
            LOGI ( &gDoipLogContext, "TA type is Physical" );
        }
        else
        {
            taType = DOIP_TATYPE_FUNCTIONAL;            /* Functional address*/
            LOGI ( &gDoipLogContext, "TA type is Functional" );
        }

    }

    return taType;
}


void CDoIPHandler::dataReceivedForSoAd ( uint8_t SocketId, const std::vector<uint8_t> *rxBuffer )
{
    uint32_t payloadLength;

    payloadLength = getPayloadLength ( rxBuffer );

    if ( payloadLength < maxPayloadLength )
    {
        if ( payloadLength <= doipStackSize )
        {

            diagnosticMessage ( SocketId, rxBuffer );
        }
        else
        {
            createAndSendNack ( false, SocketId, EDiagMsgResponse_OutOfMemory, NULL );
            LOGE ( &gDoipLogContext, " Message Length is too large " );
        }
    }
    else
    {
        createAndSendNack ( false, SocketId, EDiagMsgResponse_InvalidPayloadLength, NULL );
        // tcp.socketClose ( SocketId );
        doipSocketClose ( SocketId );
        LOGE ( &gDoipLogContext, " Invalid payload length " );
    }
}
#ifdef DOIP_IPV6
void CDoIPHandler::setNetWorkConfigIPv6 (  SDoIPSetNetworkInformationIPv6 networkConfig )
{
    mPortNum.push_back(networkConfig.portNum);
    mIpAddress.push_back(networkConfig.IPv6Address);
}
#endif
void CDoIPHandler::setNetWorkConfig (  SDoIPSetNetworkInformation networkConfig )
{
#ifdef DOIP_IPV6
    LOGI ( &gDoipLogContext, "setDoIPParams not support IP version 6" );
#else
#if 0
    mIpAddress.clear();
    std::stringstream  ss1;
    ss1 << networkConfig.ipAddressNetwork1 << networkConfig.ipAddressNetwork2 << networkConfig.ipAddressHost1 << networkConfig.ipAddressHost2;
    mPortNum   = networkConfig.portNum;
    mIpAddress = "192.168.40.2";
#else
    // mIpAddress.clear();

    char buffer[20];
    sprintf ( &buffer[0], "%d.%d.%d.%d", networkConfig.ipAddressNetwork1, networkConfig.ipAddressNetwork2, \
              networkConfig.ipAddressHost1, networkConfig.ipAddressHost2 );

    //std::form
    //std::stringstream  ss1;
    //ss1 << networkConfig.ipAddressNetwork1;
    //ss1 << '.';
    //ss1 << networkConfig.ipAddressNetwork2;
    //ss1 << '.';
    //ss1 << networkConfig.ipAddressHost1;
    //ss1 << '.';
    //ss1 << networkConfig.ipAddressHost2;

    //mPortNum   = networkConfig.portNum;
    //ss1 >> mIpAddress ;
    mPortNum.push_back(networkConfig.portNum);
    mIpAddress.push_back(buffer);
    //mPortNum   = networkConfig.portNum;
    //mIpAddress = buffer;

#endif
#endif //DOIP_IPV6
}

void CDoIPHandler::vehicleIdentificationRequest ( uint8_t vlanNo,const std::vector<uint8_t> *rxBuffer, const void *clientAddr )
{

    //sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );
    int32_t lpTimerId = -1;

    lpTimerId = getTimerId ( mUDPProxySocketBase+vlanNo, ETimers_AnnounceInterval );

    if ( lpTimerId >= 0 )
    {
        mdoipTimer.stopTimer ( lpTimerId );
    }
    else
    {
        LOGE ( &gDoipLogContext, "Timer Id not valid" );
    }

    sendVehicleAnnouncement ( vlanNo, clientAddr );
}

void CDoIPHandler::sendVehicleAnnouncement ( uint8_t vlanNo,const void *clientAddr )
{
    LOGI ( &gDoipLogContext, "Send Vehicle announcement" );
    uint16_t portnum;
    uint16_t bytesSent;
    std::vector<uint8_t> txBuffer;
    int32_t lpTimerId = -1;

    actionRequired = 0x00U;    // No further action required
    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_VehicleAnnouncementOrResponse >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( EPayloadType_VehicleAnnouncementOrResponse >> 0U ) & 0xFFU );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 33U );
    std::copy ( mVin.begin(), mVin.end(), back_inserter ( txBuffer ) );
    txBuffer.push_back ( ( mdoIpTargetAddressePhysical >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( mdoIpTargetAddressePhysical >> 0U ) & 0xFFU );
    std::copy ( mEid.begin(), mEid.end(), back_inserter ( txBuffer ) );
    std::copy ( mGid.begin(), mGid.end(), back_inserter ( txBuffer ) );
    txBuffer.push_back ( vehicleInfoSyncState );
    txBuffer.push_back ( actionRequired );

    if ( vehicleAnnouncementDone == false )
    {
        lpTimerId = getTimerId ( mUDPProxySocketBase+vlanNo, ETimers_AnnounceWait );
        mdoipTimer.stopTimer ( lpTimerId );
    }

    if ( announceCount[vlanNo] < 3 )
    {
        announceCount[vlanNo] = announceCount[vlanNo] + 1;
        portnum = mPortNum[vlanNo];
        lpTimerId = getTimerId ( mUDPProxySocketBase+vlanNo, ETimers_AnnounceInterval );
        mdoipTimer.stopTimer ( lpTimerId );
        vehicleAnnouncementDone = true;
    }
    else
    {
        portnum = udp[vlanNo].getClientPort();
    }

    LOGE ( &gDoipLogContext, " announceCount ", announceCount[vlanNo] );
#ifdef DOIP_IPV6
    if(clientAddr != NULL) {
        sockaddr_in6 clientAddress = * ( ( sockaddr_in6 * ) clientAddr );
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, &clientAddress);
    } else {
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, NULL);
    }
#else
    bytesSent = udp[vlanNo].sendMessage ( portnum, txBuffer, ( sockaddr_in * ) clientAddr );
#endif //DOIP_IPv6

    if ( bytesSent != ( int32_t ) ( doipHeaderLength + 33U ) )
    {
        LOGE ( &gDoipLogContext, " Vehicle ID response not sent successfully." );
    }

    if ( announceCount[vlanNo] < 3 )
    {

        lpTimerId = getTimerId ( mUDPProxySocketBase+vlanNo, ETimers_AnnounceInterval );

        if ( lpTimerId >= 0 )
        {
            mdoipTimer.startTimer ( lpTimerId, mdoIpVehicleAnnounceIntervalTimeMs );
        }
        else
        {
            LOGE ( &gDoipLogContext, "Timer Id not valid" );
        }
    }
}

void CDoIPHandler::setVlanCount(uint8_t count)
{
    LOGV(&gDoipLogContext, "setVlanCount  ", count );
    mVlanCount = count;

}
void CDoIPHandler::setVehicleInfoSyncState ( uint8_t SyncState )
{
    LOGI ( &gDoipLogContext, "setVehicleInfoSyncState ", SyncState );
    vehicleInfoSyncState = SyncState;
}

void CDoIPHandler::setVehicleInfo ( SVehicleInfo_t *vehicleInfo )
{
    mVin.clear();
    mEid.clear();
    mGid.clear();

    for ( std::vector<uint8_t>::iterator it = vehicleInfo->vin.begin(); it != vehicleInfo->vin.end(); it++ )
    {
        mVin.push_back ( *it );
    }

    for ( std::vector<uint8_t>::iterator it = vehicleInfo->eid.begin(); it != vehicleInfo->eid.end(); it++ )
    {
        mEid.push_back ( *it );
    }

    for ( std::vector<uint8_t>::iterator it = vehicleInfo->gid.begin(); it != vehicleInfo->gid.end(); it++ )
    {
        mGid.push_back ( *it );
    }
}

void CDoIPHandler::diagnosticPowerModeResponse ( uint8_t vlanNo,uint8_t powerMode,const void *clientAddr )
{
    uint16_t portnum;
    uint16_t bytesSent;
    std::vector<uint8_t> txBuffer;
    //sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );

    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_DiagPowerModeInfoResponse >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( EPayloadType_DiagPowerModeInfoResponse >> 0U ) & 0xFFU );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 1U );
    txBuffer.push_back ( powerMode );

    portnum = udp[vlanNo].getClientPort();
#ifdef DOIP_IPV6
    if(clientAddr != NULL) {
        sockaddr_in6 clientAddress = * ( ( sockaddr_in6 * ) clientAddr );
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, &clientAddress);
    } else {
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, NULL);
    }
#else
    sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );
    bytesSent = udp[vlanNo].sendMessage ( portnum, txBuffer, &clientAddress );
#endif //DOIP_IPv6

    if ( bytesSent != ( int32_t ) ( doipHeaderLength + 1U ) )
    {
        LOGE ( &gDoipLogContext, "Diag power mode status not sent to Tester " );
    }
}

void CDoIPHandler::doipEntityStatusResponse(uint8_t vlanNo,const void *clientAddr)
{
    uint16_t portnum;
    uint16_t bytesSent;
    std::vector<uint8_t> txBuffer;
    //sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );

    txBuffer.push_back ( DOIP_PROTOCOL_VERSION );
    txBuffer.push_back ( DOIP_PROTOCOL_INVERSE_VERSION );
    txBuffer.push_back ( ( EPayloadType_EntityStatusResponse >> 8U ) & 0xFFU );
    txBuffer.push_back ( ( EPayloadType_EntityStatusResponse >> 0U ) & 0xFFU );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 0U );
    txBuffer.push_back ( 7U );

    txBuffer.push_back ( EDoIPNodeType_Node );              /// Doip Node Type
    txBuffer.push_back ( mdoIpNoOfSocketsSupported - 1U );        /// Number of Testers - 1U
    txBuffer.push_back ( tcp[vlanNo].getNumberOfSocketsOpened() );
    txBuffer.push_back ( ( doipStackSize >> 24U ) & 0xFFU );        /// Max Data Size
    txBuffer.push_back ( ( doipStackSize >> 16U ) & 0xFFU );        /// Max Data Size
    txBuffer.push_back ( ( doipStackSize >> 8U ) & 0xFFU );     /// Max Data Size
    txBuffer.push_back ( ( doipStackSize >> 0U ) & 0xFFU );     /// Max Data Size

    portnum = udp[vlanNo].getClientPort();

#ifdef DOIP_IPV6
    if(clientAddr != NULL) {
        sockaddr_in6 clientAddress = * ( ( sockaddr_in6 * ) clientAddr );
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, &clientAddress);
    } else {
        bytesSent = udp[vlanNo].sendMessageIPv6( portnum, txBuffer, NULL);
    }
#else
    sockaddr_in clientAddress = * ( ( sockaddr_in * ) clientAddr );
    bytesSent = udp[vlanNo].sendMessage ( portnum, txBuffer, &clientAddress );
#endif //DOIP_IPv6

    if ( bytesSent != ( int32_t ) ( doipHeaderLength + 7U ) )
    {
        LOGE ( &gDoipLogContext, "Doip entity status not sent to Tester " );
    }
}


void CDoIPHandler::setDoIPParams (DoipSetParams msg )
{
    uint8_t index;

    std::lock_guard<std::mutex> lock ( mSetDoipParams );

    if ( true == msg.isNetWorkConfigValid )
    {
        setNetWorkConfig ( msg.ipConfig );
    }

    if ( true ==  msg.isVinNumValid  )
    {
        mVin.clear();

        for ( index = 0; index < sizeof ( msg.vinNumber ) ; index++ )
        {
            mVin.push_back ( msg.vinNumber[index] );
        }
    }

    if ( true == msg.isEidNumValid  )
    {
        mEid.clear();

        for ( index = 0; index < sizeof ( msg.eidNumber ) ; index++ )
        {
            mEid.push_back ( msg.eidNumber[index] );
        }
    }

    if ( true == msg.isGidNumValid )
    {
        mGid.clear();

        for ( index = 0; index < sizeof ( msg.gidNumber ) ; index++ )
        {
            mGid.push_back ( msg.gidNumber[index] );
        }
    }

    if ( true == msg.isGidSyncStatusValid )
    {
        setVehicleInfoSyncState ( msg.gidSyncStatus );
    }

}

void CDoIPHandler::tcpConnectionEstablished ( uint8_t socketId,uint8_t vlanNo )
{
    bool isConnectionEstablished = false;
    int32_t lpTimerId;
    int8_t doipSocketIndex = SOAD_HANDLER_SOCK_INDEX(vlanNo,mdoIpNoOfSocketsSupported,socketId);


    LOGV ( &gDoipLogContext, "  Set to TCP Established State", "Socked Id", +socketId );
    //if ( DoIPSocketState.at ( vlanNo*mdoIpNoOfSocketsSupported +socketId ) == SocketStateType_ConnectionInvalid )
    if ( DoIPSocketState.at(doipSocketIndex) == SocketStateType_ConnectionInvalid)
    {
        lpTimerId =  getTimerId ( vlanNo*mdoIpNoOfSocketsSupported +socketId, ETimers_InitialInActivity  );
        restartTimer ( lpTimerId, mdoIpInitialInactiveTimeMs );
        DoIPSocketState.at ( doipSocketIndex ) = SocketStateType_ConnectionEstablished;
        awaitingAliveCheckResponse.at ( doipSocketIndex )    =   false;
        //   sockNr.at ( vlanNo*mdoIpNoOfSocketsSupported +socketId ) = socketId;
        isConnectionEstablished = true;
        LOGW ( &gDoipLogContext, " Socked Set to TCP Established State", "Socked Id", +socketId, "Socket Index" );
        //   break;
    }

    if ( isConnectionEstablished != true )
    {
        LOGE ( &gDoipLogContext, "Unable to set TCP Established State" );
    }
}


void CDoIPHandler::tcpSocketClose( uint8_t socketId,uint8_t vlanNo )
{
    int32_t lpTimerId;
    socketId = SOAD_HANDLER_SOCK_INDEX(vlanNo,mdoIpNoOfSocketsSupported,socketId);
//   for ( i = 0u ; i < mdoIpNoOfSocketsSupported ; i++ )
//   i=socketId;
//   {
//       if ( sockNr.at ( i ) == socketId )
//       {
//           sockNr.at ( i )    =   -1;
    sa.at ( socketId )        =   0x0;
    awaitingAliveCheckResponse.at ( socketId )    =   false;
    DoIPSocketState.at ( socketId ) = SocketStateType_ConnectionInvalid;


    lpTimerId =  getTimerId ( socketId, ETimers_Generalactivity  );

    if ( lpTimerId >= 0 )
    {
        mdoipTimer.stopTimer ( lpTimerId );
    }
    else
    {
        LOGE ( &gDoipLogContext, "Timer Id not valid" );
    }


    lpTimerId =  getTimerId ( socketId, ETimers_InitialInActivity  );

    if ( lpTimerId >= 0 )
    {
        mdoipTimer.stopTimer ( lpTimerId );
    }
    //   break;
//        }
//    }

}

#ifdef DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION
void CDoIPHandler::notifyUdsAppOnRoutingActivation(uint16_t sourceAddress)
{    
    UdsAppRoutingActivationIndication routingActivationInd ;

    routingActivationInd.sourceAddress = sourceAddress;
    routingActivationInd.targetAddress = mdoIpTargetAddressePhysical;
    routingActivationInd.targetAddressType = findTargetType ( mdoIpTargetAddressePhysical );

    LOGI ( &gDoipLogContext, "Notify the application for successful routing activation." );
    DK_RTE_Send_UdsAppRoutingActivationIndication ( routingActivationInd );    
    

}
#endif //DOIP_NOTIFY_APP_ON_ROUTINGACTIVATION 
