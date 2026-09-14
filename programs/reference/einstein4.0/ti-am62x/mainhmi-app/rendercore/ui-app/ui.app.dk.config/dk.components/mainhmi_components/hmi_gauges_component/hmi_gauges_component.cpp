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
#include "hmi_gauges_component.h"
#include "rcore_engine_app.hpp"

/// Start of user code : Header user code for file hmi_gauges_component.cpp

/// End of user code



bool HMIGaugesComponent::onInit()
{
	bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file hmi_gauges_component.cpp

/// End of user code

	return ret;
}

bool HMIGaugesComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file hmi_gauges_component.cpp

/// End of user code

	return ret;
}

bool HMIGaugesComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file hmi_gauges_component.cpp

/// End of user code

	return ret;
}

bool HMIGaugesComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file hmi_gauges_component.cpp

/// End of user code

	return ret;
}

void HMIGaugesComponent::worker()
{
/// Start of user code : User code for function worker in file hmi_gauges_component.cpp

/// End of user code
}

void HMIGaugesComponent::onReceiveSlowGaugeInfo(SlowGaugeInfo const  & msg)
{
/// Start of user code : User code for function onReceiveSlowGaugeInfo in file hmi_gauges_component.cpp

/// End of user code
}

void HMIGaugesComponent::onReceiveFastGaugeInfo(FastGaugeInfo const  & msg)
{
/// Start of user code : User code for function onReceiveFastGaugeInfo in file hmi_gauges_component.cpp

	MainHMIInterface *obj_MainHMIInterface = MainHMIInterface::getInstance();
	uint32 sdata = 0;
	uint32 tdata = 0;

	sdata = msg.gaugeInfo[0].digitalData;
	tdata = msg.gaugeInfo[1].digitalData;

	// printf("onReceiveFastGaugeInfo: speed: %d	Tacho: %d \n",sdata, tdata);
	obj_MainHMIInterface->SetSpeedData((sint32)sdata);
	obj_MainHMIInterface->SetTachoData((sint32)tdata);

/// End of user code
}



/// Start of user code : Footer user code for file hmi_gauges_component.cpp

/// End of user code

