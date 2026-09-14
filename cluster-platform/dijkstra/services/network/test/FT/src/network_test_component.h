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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.4
// Date: Tue Oct 05 14:20:19 IST 2021
// User: SSHANKA8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef NETWORKIF_APP_COMPONENT_H
#define NETWORKIF_APP_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_messages.h"
#include "dk_runtime_component.h"
#include "dk_runtime_parserif.h"
#include "network_test.h"
//#include "dk_runtime_networkif_app_component.h"



using namespace dk::runtime;

class NetworkifAppComponent : public dk::runtime::core::Component
{
public:
    explicit NetworkifAppComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~NetworkifAppComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);
    
void onReceiveNetworkInterfaceStatus(NetworkInterfaceStatus & msg);

private:

const std::string mIniFilePath1 = "/system/etc/network_test.ini";

const std::string mIniFilePath2 = "/etc/network_test.ini";

dk::runtime::core::ParserIf  mParserObj;

std::string interfaceName;

std::string ipAddress;

std::string broadCastAddress;

std::string netMask;

std::string linkStatus;

std::string vlanName;

std::string phyInterfaceName;

std::string vlanIpAddress;

std::string vlanBroadCastAddress;

std::string vlanNetMask;

uint16_t vlanTag;

uint8_t vlanPriority;

std::string vlanLinkStatus;

uint8_t resp_recved = false;
/// Start of user code : User code for file networkif_app_component.h
bool parseConfiguration(void);

void send_network_modify_vlan_interface(uint8_t req_type);

void send_network_modify_link_status(uint8_t req_type, std::string interfaceName);

void send_network_modify_interface_vlan(uint8_t req_type);

void send_network_modify_interface_phy(uint8_t req_type);

/// End of user code
};



#endif //NETWORKIF_APP_COMPONENT_H

