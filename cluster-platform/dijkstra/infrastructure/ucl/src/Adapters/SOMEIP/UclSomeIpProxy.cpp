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
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <iterator>
#include <iomanip>
#include <condition_variable>
#include <math.h>
#include "string.h"
#include <unistd.h>
#include <UclALDebug.h>
#include <UclSys.h>
#include "UclALOs.h"
#include <Ucl_Version.h>
#include <vsomeip/vsomeip.hpp>
#include "UclSomeIpProxy.hpp"
#include "UclSomeIpConfig.hpp"

#define MAX_SOMEIP_DATA_LENGTH 1024
#define UCL_INSTANCEID 0x1

CUclSomeIpProxy::CUclSomeIpProxy()
{
    bRequestExit = false;
    CUclSomeIpProxy::UclServiceRegSucessful = FALSE;
    CUclSomeIpProxy::UclAppReg = nullptr;
}

CUclSomeIpProxy::~CUclSomeIpProxy()
{
}

Ucl_ReturnType CUclSomeIpProxy::start()
{
    uint16 index = 0;
    uint16 SxtoExTxIndex=0x0;
    uint16 SxtoExRxIndex=0X0;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 numServices;
    uint16 methodId;
    uint16 eventGroupId;
    const uint16_t *ServiceList = nullptr;
    std::vector<std::pair<uint16, uint16>> MethodEventGrouplist;
    std::set<vsomeip::eventgroup_t> EventGroupsIdSet;
    std::vector<std::pair<uint16, Func>> MethodRegHandler;

    LOGI(0, "UclGen_SomeIpProxy", "UCL VERSION : %s",UCL_VERSION);


    CUclSomeIpProxy::UclAppReg = vsomeip::runtime::get()->create_application( "UclService" );

    // Get the list of service Ids
    if (CUclSomeIpProxy::UclAppReg != NULL )
    {
        CUclSomeIpProxy::UclAppReg->init();
        LOGI(0, "UclGen_SomeIpAdapter", "%s", "UCL App Created Successfully");
        // Get the list of services
        Ret = CUclSomeIPConfig::getServiceIdGroupList( &ServiceList, numServices );

        for (index = 0; index < numServices; ++index)
        {
            // offer service
            // Search Valid Method Id for service
            Ret = CUclSomeIPConfig::lookupSxtoExTxTable( *ServiceList, MethodRegHandler );
            if (Ret == UCL_E_OK)
            {
                for (SxtoExTxIndex = 0; SxtoExTxIndex < MethodRegHandler.size(); ++SxtoExTxIndex)
                {
                    methodId = MethodRegHandler[SxtoExTxIndex].first;
                    // Update function pointer in the register message handler
                    CUclSomeIpProxy::UclAppReg->register_message_handler( *ServiceList, UCL_INSTANCEID, methodId, MethodRegHandler[SxtoExTxIndex].second );
                    //LOGI(0, "UclGen_SomeIpAdapter", "Registered Method/EventId for ServiceId: %x , MethodId: %x", *ServiceList, methodId);
                }
            }

            Ret = CUclSomeIPConfig::lookupSxtoExRxTable( *ServiceList, MethodEventGrouplist );
            if (Ret == UCL_E_OK)
            {
                for (SxtoExRxIndex = 0; SxtoExRxIndex < MethodEventGrouplist.size(); ++SxtoExRxIndex)
                {
                    methodId = MethodEventGrouplist[SxtoExRxIndex].first;
                    eventGroupId = MethodEventGrouplist[SxtoExRxIndex].second;
                    // convert event group to std::set
                    // publish -subscribe message
                    EventGroupsIdSet.clear();
                    EventGroupsIdSet.insert( eventGroupId );
                    CUclSomeIpProxy::UclAppReg->offer_event( *ServiceList, UCL_INSTANCEID, methodId, EventGroupsIdSet);
                    //LOGI(0, "UclGen_SomeIpAdapter", "Registered Method/EventId for ServiceId: %x , MethodId: %x ,EventGroup: %x", *ServiceList, methodId,eventGroupId);

                }
            }
            CUclSomeIpProxy::UclAppReg->offer_service( *ServiceList, UCL_INSTANCEID ); // instance Id will be '0x1' default
            ServiceList++; // Get the Next Service
        }

        LOGI(0, "UclGen_SomeIpAdapter", "%s", "UCL- SOMEIP Service is Running ");
        CUclSomeIpProxy::UclServiceRegSucessful = TRUE;
        Ret = UclSys_Initialize( 0 );

        if( Ret >= 0 )
        {
            CUclSomeIpProxy::UclAppReg->start();
        }
    }
    else
    {
        LOGI(0, "UclGen_SomeIpAdapter", "%s", "UCL- SOMEIP Service Registration Failed ");

        (void) UclSys_Shutdown( 0 );
    }

    return Ret;

}

Ucl_ReturnType CUclSomeIpProxy::stop()
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int index = 0;
    uint16 SxtoExTxIndex=0x0;
    uint16 SxtoExRxIndex=0X0;
    uint16 numServices;
    uint16 methodId;
    uint16 eventGroupId;
    const uint16_t *ServiceList = nullptr;
    //std::shared_ptr<vsomeip::application> UclAppReg;
    std::vector<std::pair<uint16_t, uint16_t>> MethodEventGrouplist;
    std::set<vsomeip::eventgroup_t> EventGroupsIdSet;
    std::vector<std::pair<uint16_t, Func>> MethodRegHandler;

    // Get the list of service Ids
    if (CUclSomeIpProxy::UclAppReg != NULL )
    {
        CUclSomeIpProxy::UclServiceRegSucessful = FALSE;
        // Get the list of services
        Ret = CUclSomeIPConfig::getServiceIdGroupList( &ServiceList, numServices );

        for (index = 0; index < numServices; index++)
        {
            // offer service
            // Search Valid Method Id for service
            Ret = CUclSomeIPConfig::lookupSxtoExTxTable( *ServiceList, MethodRegHandler );
            if (Ret == UCL_E_OK)
            {
                for (SxtoExTxIndex = 0; SxtoExTxIndex < MethodRegHandler.size(); ++SxtoExTxIndex)
                {
                    // Update function pointer in the register message handler
                    if (MethodRegHandler[SxtoExTxIndex].second != NULL )
                    {
                        CUclSomeIpProxy::UclAppReg->unregister_message_handler( *ServiceList, UCL_INSTANCEID, MethodRegHandler[SxtoExTxIndex].first );
                    }

                    LOGI(0, "UclGen_SomeIpAdapter", "UnRegistered Method/EventId for ###ServiceId: %d #### MethodId: %d", *ServiceList, MethodRegHandler[index].first);
                }
            }

            Ret = CUclSomeIPConfig::lookupSxtoExRxTable( *ServiceList, MethodEventGrouplist );
            if (Ret == UCL_E_OK)
            {
                for (SxtoExRxIndex = 0; SxtoExRxIndex < MethodEventGrouplist.size(); ++SxtoExRxIndex)
                {
                    methodId = MethodEventGrouplist[SxtoExRxIndex].first;
                    eventGroupId = MethodEventGrouplist[SxtoExRxIndex].second;
                    // convert event group to std::set
                    // publish -subscribe message
                    EventGroupsIdSet.insert( eventGroupId );
                    CUclSomeIpProxy::UclAppReg->stop_offer_event( *ServiceList, UCL_INSTANCEID, methodId );
                    CUclSomeIpProxy::UclAppReg->release_event( *ServiceList, UCL_INSTANCEID, methodId );

                    LOGI(0, "UclGen_SomeIpAdapter", "UnRegistered Method/EventId for ###ServiceId: %d ### MethodId: %d ###EventGrouup :%d", *ServiceList,
                         methodId,eventGroupId);
                }
            }

            CUclSomeIpProxy::UclAppReg->stop_offer_service( *ServiceList, UCL_INSTANCEID ); // instance Id will be '0x1' default
            CUclSomeIpProxy::UclAppReg->release_service( *ServiceList, UCL_INSTANCEID );
            ServiceList++; // Get the Next Service
        }

        LOGI(0, "UclGen_SomeIpAdapter", "%s", "UCL- SOMEIP Service shutdown ");
        //  UclAppReg->remove_application( "UCL service " );
        CUclSomeIpProxy::UclAppReg = nullptr;
        (void) UclSys_Shutdown( 0 );

    }

    return Ret;
}

Ucl_ReturnType CUclSomeIpProxy::addSomeIpToTxQueue( uint16 Sx, uint16 Ex, uint8 *pPayload, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    std::shared_ptr<vsomeip::payload> payload;

    if (Size > MAX_SOMEIP_DATA_LENGTH)
    {
        LOGE(0, "UclProxySomeIp", "AddSomeIpMsgToTxQueue Size Error Sx: %d Ex:%d Size:%d",Sx, Ex, Size);
    }

    else
    {
        if ((CUclSomeIpProxy::UclServiceRegSucessful == TRUE) && (CUclSomeIpProxy::UclAppReg != NULL ))
        {
            payload = vsomeip::runtime::get()->create_payload();
            payload->set_data( pPayload, Size );
            CUclSomeIpProxy::UclAppReg->notify( Sx,UCL_INSTANCEID, Ex, payload );
            Ret = UCL_E_OK;
        }
    }

    return Ret;
}

uint8 UclSomeIpProxy_AddSomeIpMsgToTxQueue( uint16 Sx, uint16 Ex, uint8 *pPayload, uint16 Size )
{
    uint8 Ret = FALSE;

    if (UCL_E_OK == CUclSomeIpProxy::getInstance().addSomeIpToTxQueue( Sx, Ex, pPayload, Size ))
    {
        Ret = TRUE;
    }
    return Ret;
}
