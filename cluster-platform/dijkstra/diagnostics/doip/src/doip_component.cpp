//---------------------------------------------------------------------------------------------------------------------
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
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Wed Mar 24 08:12:57 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "doip_component.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

LOG_DECLARE_CONTEXT ( gDoipLogContext );
/// End of user code



bool DoipComponent::onInit()
{
    bool ret = true;

    Component::onInit();
    /// Start of user code : User code for function onInit in file infra_comm_doip.cpp
    LOG_REGISTER_CONTEXT ( gDoipLogContext, "DOIP",  "DoIP Server", DLT_LOG_WARN );
    Component::onInit();
    LOGI ( &gDoipLogContext, "DoIP::onInit" );
    doipIniHandler();
    sleep(1);
    registerTask ( [ = ]()
    {
        PeriodicTask_1sec();
    }, DOIP_COMPONENT_PERIODIC_TIMER_IN_MS );
    registerTask ( [ = ]()
    {
        doipTimerTask();
    }, DOIP_PERIODIC_TIMER_IN_MS );
    LOGI ( &gDoipLogContext, "Registration complete" );
    /// End of user code

    return ret;
}

bool DoipComponent::onExit()
{
    bool ret = true;

    Component::onExit();

    /// Start of user code : User code for function onExit in file infra_comm_doip.cpp
    LOGI ( &gDoipLogContext, "onExit" );
    /// End of user code

    return ret;
}

bool DoipComponent::onStart()
{
    bool ret = true;

    Component::onStart();

    /// Start of user code : User code for function onStart in file infra_comm_doip.cpp
    LOGI ( NULL, "DoIP::onStart" );
    handler.init();

/// End of user code

    return ret;
}

bool DoipComponent::onStop()
{
    bool ret = true;

    Component::onStop();

    /// Start of user code : User code for function onStop in file infra_comm_doip.cpp
    LOGI ( &gDoipLogContext, "DoIP::onStop" );
    handler.stop();
    /// End of user code

    return ret;
}

void DoipComponent::worker()
{
/// Start of user code : User code for function worker in file doip_component.cpp

/// End of user code
}

void DoipComponent::onReceiveDoipSetParams(DoipSetParams & msg)
{
/// Start of user code : User code for function onReceiveDoipSetParams in file doip_component.cpp
    handler.setDoIPParams ( msg );
#ifndef DOIP_IPV6
    LOGI ( &gDoipLogContext, "DoIP::onReceiveDoipSetParams", +msg.ipConfig.ipAddressNetwork1 );
    LOGI ( &gDoipLogContext, "DoIP::onReceiveDoipSetParams", +msg.ipConfig.ipAddressNetwork2 );
    LOGI ( &gDoipLogContext, "DoIP::onReceiveDoipSetParams", +msg.ipConfig.ipAddressHost1 );
    LOGI ( &gDoipLogContext, "DoIP::onReceiveDoipSetParams", +msg.ipConfig.ipAddressHost2 );
    LOGI ( &gDoipLogContext, "DoIP::onReceiveDoipSetParams", msg.ipConfig.portNum );
#endif // DOIP_IPV6
/// End of user code
}

void DoipComponent::onReceiveDoipDiagDataTransferRequest(DoipDiagDataTransferRequest & msg)
{
/// Start of user code : User code for function onReceiveDoipDiagDataTransferRequest in file doip_component.cpp

    LOGI ( &gDoipLogContext, "DoIP::receiveDKMsgDoipDiagDataTransferRequest" );
    handler.dataTrasferRequest ( msg.sourceAddress, msg.targetAddress, msg.targetAddressType, ( uint8_t * ) &msg.data[0], msg.dataLen );
    /// End of user code
/// End of user code
}

void DoipComponent::onReceiveDoipDiagPowerModeStatus(DoipDiagPowerModeStatus & msg)
{
/// Start of user code : User code for function onReceiveDoipDiagPowerModeStatus in file doip_component.cpp

/// End of user code
}





void DoipComponent::PeriodicTask_1sec ( void )
{
    handler.periodicTask();
    // LOGI(&gDoipLogContext,"Periodic task");
}

void DoipComponent::doipTimerTask ( void )
{
    handler.doipTimerBaseTick();
    //LOGI(&gDoipLogContext,"TimerTask");
}

void DoipComponent::doipIniHandler ( void )
{

    uint8_t sectionCount ;
    SDoIPConfig_t config = {0};
    char sourceAddress[40];
    char targetAddress[40];
    uint16_t address;
    uint8_t iniParserStatus = 0;
#ifdef DOIP_IPV6
    SDoIPSetNetworkInformationIPv6 networkConfig = {0};
#else
    SDoIPSetNetworkInformation networkConfig = {0};
#endif
    SVehicleInfo_t vehicleInfoConfig;
    std::vector<std::string> vin;
    std::vector<std::string> eid;
    std::vector<std::string> gid;

    LOGI ( &gDoipLogContext, "Ini Handler" );

    if ( mIniParser.loadConfiguration ( doipIniPath1 ) )
    {
        iniParserStatus = 1;
        LOGV ( &gDoipLogContext, "doip ini file found in ", doipIniPath1 );
    }
    else if ( mIniParser.loadConfiguration ( doipIniPath2 ) )
    {
        iniParserStatus = 1;
        LOGV ( &gDoipLogContext, "doip ini file found in ",  doipIniPath2 );
    }

    if ( iniParserStatus == 1 )
    {
        std::vector<std::string> sectionsList;
        std::vector<std::string> values;

        if ( mIniParser.getAllSections ( sectionsList ) )
        {
            sectionCount = sectionsList.size();

            if ( sectionCount )
            {
                LOGI ( &gDoipLogContext, "IniConfig" );
                config.doIpAliveCheckresponseTimeMs     =  mIniParser.getInt32Value ( "DoIPTimers", "DoIPAliveCheckResponseTimoutMs", DOIP_ALIVECHECK_RESPONSE_TIMEOUT );
                config.doIpGenericInactiveTimeMs        =  mIniParser.getInt32Value ( "DoIPTimers", "DoIPGeneralInActivityTimoutMs", DOIP_GENERAL_INACTIVITY_TIMEOUT );
                config.doIpInitialInactiveTimeMs        =  mIniParser.getInt32Value ( "DoIPTimers", "DoIPInitialInActivityTimoutMs", DOIP_INITIAL_ACTIVITY_TIMEOUT );
                config.doIpVehicleAnnounceWaitTimeMs    =  mIniParser.getInt32Value ( "DoIPTimers", "DoIPVehicleAnnounceWaitTimeMs", DOIP_VEHICLE_ANNOUNCE_WAIT_TIMEOUT );
                config.doIpVehicleAnnounceIntervalTimeMs =  mIniParser.getInt32Value ( "DoIPTimers", "DoIPVehicleAnnounceIntervalTimeMs", DOIP_VEHICLE_ANNOUNCE_INTERVAL_TIMEOUT );

                config.doIpRoutingActivationRequired    =  mIniParser.getBoolValue ( "DoIPRoutingActivation", "DoIPRoutingActivationRequired", DOIP_ROUTING_ACTIVATION_REQUIRED );
                config.doIpAliveCheckRequired           =  mIniParser.getBoolValue ( "DoIPRoutingActivation", "DoIPAliveCheckRequired", DOIP_ALIVE_CHECK_REQUIRED );   ;
                config.doIpActivationNumber             =  mIniParser.getInt32Value ( "DoIPRoutingActivation", "DoIPRoutingactivationType", DOIP_ROUTING_ACTIVATION_TYPE );
                config.doIpAuthenticationRequired       =  mIniParser.getBoolValue ( "DoIPRoutingActivation", "DoIPAuthenticationRequired", DOIP_AUTHENTICATION_REQUIRED );
                config.doIpConfirmationRequired         =  mIniParser.getBoolValue ( "DoIPRoutingActivation", "DoIPConfirmationRequired", DOIP_CONFIRMATION_REQUIRED );
                config.doIpConcurrentSrcAddrSupportCnt  =  mIniParser.getInt32Value ( "DoIPNodeConfiguration", "DoIPNoOfConcurrentSrcAddrTobeSupported", DOIP_NO_OF_CONCUR_SRCADDR_TOBE_SUPPORTED );
                config.doIpSourceAddressCount           =  mIniParser.getInt32Value ( "DoIPNodeConfiguration", "DoIPNumberOfSourceAddress", DOIP_NUM_SOURCE_ADDRESS );
                config.doIpVlanCount                    =  mIniParser.getInt32Value ( "DoIPNodeConfiguration", "DoIPNumberOfVLans", DOIP_NUM_VLAN );
                config.doIpTargetAddressCount           =  mIniParser.getInt32Value ( "DoIPNodeConfiguration", "DoIPNumberOfTargetAddress", DOIP_NUM_TARGET_ADDRESS );
                config.doIpTargetAddressePhysical       =  mIniParser.getInt32Value ( "DoIPNodeConfiguration", "DoIPTargetAddressPhysical", DOIP_TARGET_ADDRESS_PHYSICAL );
                config.diagOverIPProtocol               =  mIniParser.getInt32Value ( "DiagOverIPProtocol", "DiagOverIPProtocol", DIAG_OVER_IP_PROTOCOL );
                address = 0 ;

                for ( uint8_t i = 0 ; i < config.doIpSourceAddressCount; i++ )
                {
                    sprintf ( sourceAddress, "DoIPSourceAddress_%d", i );
                    address = ( uint16_t ) mIniParser.getInt32Value ( "DoIPNodeConfiguration", sourceAddress, DOIP_SOURCE_ADDRESS );
                    LOGI ( &gDoipLogContext, "Source Addresses", address );
                    config.doIpSourceAddress.push_back ( address ) ;
                }

                address = 0;

                for ( uint8_t i = 0 ; i < ( config.doIpTargetAddressCount - 1 ); i++ )
                {

                    sprintf ( targetAddress, "DoIPTargetAddressFunctional_%d", i );
                    address = ( uint16_t ) mIniParser.getInt32Value ( "DoIPNodeConfiguration", targetAddress, DOIP_TARGET_ADDRESS_FUNCTIONAL );
                    LOGI ( &gDoipLogContext, "Target Addresses", address );
                    config.doIpTargetAddressesFunctional.push_back ( address );
                }

                if ( mIniParser.getAllKeysFromSection ( "NetworkInfo", values ) == true )
                {
                    if ( values.size() > 0 )
                    {
                        networkConfig.portNum = mIniParser.getInt32Value ( "NetworkInfo", "PortNumber", PORT_NUM );

                        if ( networkConfig.portNum == PORT_NUM )
                        {
#ifdef DOIP_IPV6
                            networkConfig.IPv6Address =  mIniParser.getStringValue ( "NetworkInfo", "IPv6Address");
                            LOGI ( &gDoipLogContext, "Network info configured from INI file" );
                            handler.setNetWorkConfigIPv6 ( networkConfig );
#else
                            networkConfig.ipAddressNetwork1         =  mIniParser.getInt32Value ( "NetworkInfo", "IPAddressNetwork_1", IP_ADDRESS_NETWORK_1 );
                            networkConfig.ipAddressNetwork2         =  mIniParser.getInt32Value ( "NetworkInfo", "IPAddressNetwork_2", IP_ADDRESS_NETWORK_2 );
                            networkConfig.ipAddressHost1            =  mIniParser.getInt32Value ( "NetworkInfo", "IPAddressHost_1", IP_ADDRESS_HOST_1 );
                            networkConfig.ipAddressHost2            =  mIniParser.getInt32Value ( "NetworkInfo", "IPAddressHost_2", IP_ADDRESS_HOST_2 );
                            LOGI ( &gDoipLogContext, "Network info configured from INI file" );
                            handler.setNetWorkConfig ( networkConfig );
#endif //DOIP_IPV6
                        }
                        else
                        {
                            LOGI ( &gDoipLogContext, "No Valid Port Number", networkConfig.portNum );
                        }
                    }
                }
                else
                {
                    LOGI ( &gDoipLogContext, "Network info will be configured through Message" );
                }

                if ( mIniParser.getAllKeysFromSection ( "VehicleInfo", values ) == true )
                {
                    if ( values.size() > 0 )
                    {
                        (void)mIniParser.getAllValuesForKey ( "VehicleInfo", "Vin", vin );
                        (void)mIniParser.getAllValuesForKey ( "VehicleInfo", "Eid", eid );
                        (void)mIniParser.getAllValuesForKey ( "VehicleInfo", "Gid", gid );
                    }

                    for ( std::vector<std::string>::iterator it = vin.begin(); it != vin.end(); ++it )
                    {
                        uint8_t vin = strtoul ( it->c_str(), NULL, 0 );
                        vehicleInfoConfig.vin.push_back ( vin );

                    }

                    for ( std::vector<std::string>::iterator it = eid.begin(); it != eid.end(); ++it )
                    {
                        uint8_t eid = strtoul ( it->c_str(), NULL, 0 );
                        vehicleInfoConfig.eid.push_back ( eid );
                    }

                    for ( std::vector<std::string>::iterator it = gid.begin(); it != gid.end(); ++it )
                    {
                        uint8_t gid = strtoul ( it->c_str(), NULL, 0 );
                        vehicleInfoConfig.gid.push_back ( gid );
                    }

                    handler.setVehicleInfo ( &vehicleInfoConfig );
                    handler.setVehicleInfoSyncState ( 0x00 );
                }
                else
                {
                    LOGI ( &gDoipLogContext, "Vehicle Info Not configured in INI" );
                }
                handler.setVlanCount(config.doIpVlanCount);

            }
        }
    }
    else
    {
        LOGI ( &gDoipLogContext, "Default Configuration" );
        config.doIpAliveCheckresponseTimeMs             =  DOIP_ALIVECHECK_RESPONSE_TIMEOUT;
        config.doIpGenericInactiveTimeMs                =  DOIP_GENERAL_INACTIVITY_TIMEOUT ;
        config.doIpInitialInactiveTimeMs                =  DOIP_INITIAL_ACTIVITY_TIMEOUT;
        config.doIpRoutingActivationRequired            =  ( bool ) DOIP_ROUTING_ACTIVATION_REQUIRED   ;
        config.doIpAliveCheckRequired                   = ( bool ) DOIP_ALIVE_CHECK_REQUIRED  ;
        config.doIpActivationNumber                     =  DOIP_ROUTING_ACTIVATION_TYPE ;
        config.doIpAuthenticationRequired               =  ( bool ) DOIP_AUTHENTICATION_REQUIRED   ;
        config.doIpConfirmationRequired                 =  ( bool ) DOIP_CONFIRMATION_REQUIRED ;
        config.doIpTargetAddressePhysical               =  DOIP_TARGET_ADDRESS_PHYSICAL  ;
        config.doIpTargetAddressCount                   =  DOIP_NUM_TARGET_ADDRESS ;
        config.doIpSourceAddressCount                   =  DOIP_NUM_SOURCE_ADDRESS;
        config.doIpTargetAddressesFunctional.push_back ( DOIP_TARGET_ADDRESS_FUNCTIONAL );
        config.doIpSourceAddress.push_back ( DOIP_SOURCE_ADDRESS );
        config.diagOverIPProtocol                       =  DIAG_OVER_IP_PROTOCOL;
        config.doIpConcurrentSrcAddrSupportCnt = DOIP_NO_OF_CONCUR_SRCADDR_TOBE_SUPPORTED;
        config.doIpVlanCount                     =  DOIP_NUM_VLAN;
    }

    if ( config.doIpConcurrentSrcAddrSupportCnt == 0U )
    {
        config.doIpConcurrentSrcAddrSupportCnt =  config.doIpSourceAddressCount ; ///< Support old doip.ini file
    }

    handler.setDoIPDefaultConfig ( &config );
}


/// End of user code

