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
//
/// @mainpage
///
/// @section intro Introduction
///
/// DoIP refers to the mechanism about how the vehicle is diagnosed through internet protocol.
/// DoIP facilitates diagnostics related communication between external test equipments and ECU through IP.
/// Scope of this module is for Vehicle/ECU Software reprogramming. This component supports TCP/IP and UDP
/// communication.
///
/// @section features Features
///  Provides infrastructure for
///    * Routing Activation
///    * Diagnostic message
///    * Alive Check
///    * Multiple Tester
///    * Vehicle Announcement
///    * VehicleIdentification Request and Response
///
/// @section configuration Configuration
///  * doip.ini file holds the configurations specific to all instances of doip.
///  * If this file is not found in the specified path, doip will log the error and
///    proceed with default configuration values.
///  * doip.ini shall have configuration for multiple testers .
///  * The allowed range / values of each config parameter is specified in the default doip
///    configuration file that comes with the doip Specification. User's are expected to set the
///    config values within this range. Values set out of range may result in undefined behaviour.
///  * Any change in default configuration values in doip.ini requires doip restart for
///    the configurations to take effect.
///
/// @defgroup DOIP
///
/// @file infra_comm_doip_component.h
/// @ingroup infra_comm_doip_component
///
/// @brief DoIP Class. DoIP component is maintain the connections states between the Tester and DoIP entity.
///        It services the all the Diagnostic messages. Based on the doip.ini configuration, the Routing Activation and
///        Alive Check Features are supported. If the user doesn't want RoutingActivation and Alive check feature, it can be bypassed
///        by configuring the doip.ini file. DoIP diagnostic message type used to send and receive Diagnostic Message request and response.
///
//---------------------------------------------------------------------------------------------------------------------
#ifndef C_DOIP_H
#define C_DOIP_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_doip_component.h"
#include <vector>
#include "infra_comm_doip_handler.h"
#include "dk_runtime_parserif.h"



using namespace dk::runtime;

class DoipComponent : public dk::runtime::core::Component
{
public:
    explicit DoipComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)
    {
    }

    ~DoipComponent()
    {
    }

    bool onInit();
    bool onExit();
    bool onStart();
    bool onStop();
    void worker(void);

    void onReceiveDoipSetParams(DoipSetParams & msg);

    void onReceiveDoipDiagDataTransferRequest(DoipDiagDataTransferRequest & msg);
    void onReceiveDoipDiagPowerModeStatus(DoipDiagPowerModeStatus & msg);

    void doipIniHandler ( void );

    std::vector <unsigned short> functionalLogicalAddressInfo;


private:
    //const std::string doipIniPath1 = "/tmp/doip.ini";
#ifndef DIAG_BOOT_PATH
    const std::string doipIniPath1 = "/system/etc/doip.ini";
#else
    const std::string doipIniPath1 = "/etc/doip.ini";
#endif
    const std::string doipIniPath2 = "/etc/doip.ini";

    dk::runtime::core::ParserIf mIniParser;

    CDoIPHandler handler;
    void PeriodicTask_1sec ( void );
    void doipTimerTask ( void );

};



#endif //DOIP_COMPONENT_H

