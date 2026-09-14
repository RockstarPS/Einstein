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
// Date: Thu Apr 17 12:47:36 IST 2025
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.4
//
//---------------------------------------------------------------------------------------------------------------------
#include "hmi_component.h"
#include "rc_utils.h"
#include "rcore_engine_app.hpp"

/// Start of user code : Header user code for file hmi_component.cpp

/// End of user code
extern int32_t rendercoreMain(void);
void HMIComponent::renderCore()
{
	rendercoreMain();
}


bool HMIComponent::onInit()
{
	bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file hmi_component.cpp

/// End of user code

	return ret;
}

bool HMIComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file hmi_component.cpp

/// End of user code

	return ret;
}

bool HMIComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file hmi_component.cpp
	renderCoreThread = std::thread( &HMIComponent::renderCore, this );  
/// End of user code

	return ret;
}

bool HMIComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file hmi_component.cpp

/// End of user code

	return ret;
}

void HMIComponent::worker()
{
/// Start of user code : User code for function worker in file hmi_component.cpp

/// End of user code
}

void HMIComponent::onReceiveDisplayCurrentState(DisplayCurrentState const  & msg)
{
/// Start of user code : User code for function onReceiveDisplayCurrentState in file hmi_component.cpp

/// End of user code
}

void HMIComponent::onReceivePowerSystemState(PowerSystemState const  & msg)
{
/// Start of user code : User code for function onReceivePowerSystemState in file mhmi_component.cpp
	MainHMIInterface *obj_MainHMIInterface = MainHMIInterface::getInstance();
	obj_MainHMIInterface->SetPowerState(msg.state);
/// End of user code
}


/// Start of user code : Footer user code for file hmi_component.cpp

/// End of user code

