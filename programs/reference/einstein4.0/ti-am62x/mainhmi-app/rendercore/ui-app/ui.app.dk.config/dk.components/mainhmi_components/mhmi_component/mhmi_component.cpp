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
#include "mhmi_component.h"
#include "rcore_engine_app.hpp"

/// Start of user code : Header user code for file mhmi_component.cpp

/// End of user code



bool MHMIComponent::onInit()
{
	bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file mhmi_component.cpp

/// End of user code

	return ret;
}

bool MHMIComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file mhmi_component.cpp

/// End of user code

	return ret;
}

bool MHMIComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file mhmi_component.cpp

/// End of user code

	return ret;
}

bool MHMIComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file mhmi_component.cpp

/// End of user code

	return ret;
}

void MHMIComponent::worker()
{
/// Start of user code : User code for function worker in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveTT_Status(TT_Status const  & msg)
{
/// Start of user code : User code for function onReceiveTT_Status in file mhmi_component.cpp
//0 ->Airbag, 1-> LeftINdicator, 2-> Right Indicator
	MainHMIInterface *obj_MainHMIInterface = MainHMIInterface::getInstance();
	obj_MainHMIInterface->SetTT_data(msg.mask);
/// End of user code
}

void MHMIComponent::onReceiveRTT_Status(RTT_Status const  & msg)
{
/// Start of user code : User code for function onReceiveRTT_Status in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveFRTT_Status(FRTT_Status const  & msg)
{
/// Start of user code : User code for function onReceiveFRTT_Status in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveRTT_Toggle(RTT_Toggle const  & msg)
{
/// Start of user code : User code for function onReceiveRTT_Toggle in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveRTT_Icon(RTT_Icon const  & msg)
{
/// Start of user code : User code for function onReceiveRTT_Icon in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveWarningDisplay(WarningDisplay const  & msg)
{
/// Start of user code : User code for function onReceiveWarningDisplay in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveWarningExtDisplay(WarningExtDisplay const  & msg)
{
/// Start of user code : User code for function onReceiveWarningExtDisplay in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveSlowGaugeInfo(SlowGaugeInfo const  & msg)
{
/// Start of user code : User code for function onReceiveSlowGaugeInfo in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveShiftPosIndStatus(ShiftPosIndStatus const  & msg)
{
/// Start of user code : User code for function onReceiveShiftPosIndStatus in file mhmi_component.cpp

/// End of user code
}

void MHMIComponent::onReceiveIlluminationData(IlluminationData const  & msg)
{
/// Start of user code : User code for function onReceiveIlluminationData in file mhmi_component.cpp

/// End of user code
}



/// Start of user code : Footer user code for file mhmi_component.cpp

/// End of user code

