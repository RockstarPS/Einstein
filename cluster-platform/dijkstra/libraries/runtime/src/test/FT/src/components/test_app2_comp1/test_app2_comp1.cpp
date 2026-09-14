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
// Date: Wed Oct 21 19:36:47 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "test_app2_comp1.h"
#include "dk_logger.h"
/// Start of user code : Header user code for file test_app2_comp1.cpp
LOG_DECLARE_CONTEXT(gapp2test);
/// End of user code



bool test_app2_comp1::onInit()
{
	bool ret = true;

	Component::onInit();

/// Start of user code : User code for function onInit in file test_app2_comp1.cpp
	LOG_REGISTER_CONTEXT(gapp2test, "T_A2_C1",  "TEST APP2 COM1", DLT_LOG_VERBOSE);
	LOGV(&gapp2test, "Enter");
/// End of user code

	return ret;
}

bool test_app2_comp1::onExit()
{
	bool ret = true;

	Component::onExit();

/// Start of user code : User code for function onExit in file test_app2_comp1.cpp
	LOGV(&gapp2test, "Enter");
/// End of user code

	return ret;
}

bool test_app2_comp1::onStart()
{
	bool ret = true;

	Component::onStart();

/// Start of user code : User code for function onStart in file test_app2_comp1.cpp
	LOGV(&gapp2test, "Enter");
/// End of user code

	return ret;
}

bool test_app2_comp1::onStop()
{
	bool ret = true;

	Component::onStop();

/// Start of user code : User code for function onStop in file test_app2_comp1.cpp
	LOGV(&gapp2test, "Enter");
/// End of user code

	return ret;
}

void test_app2_comp1::worker()
{
/// Start of user code : User code for function worker in file test_app2_comp1.cpp

/// End of user code
}

void test_app2_comp1::onReceiveDkMsgTestApp2Receive(DkMsgTestTransmit_t & msg)
{
/// Start of user code : User code for function onReceiveDkMsgTestApp2Receive in file test_app2_comp1.cpp
DkMsgTestMsg_t msg2 = {0};

LOGI(&gapp2test, "base.compId: ", msg.base.compId);
LOGI(&gapp2test, "base.msgCnt: ", msg.base.msgCnt);
LOGI(&gapp2test, "var_uint8= ", msg.var_uint8);
LOGI(&gapp2test, "var_bool= ", msg.var_bool);
LOGI(&gapp2test, "var_uint16= ", msg.var_uint16);

msg2.var1 = (uint32)(msg.var_uint8);
msg2.var2 = (uint32)(msg.var_uint16);
DK_RTE_Send_DkMsgTestApp2Transmit(msg2);


/// End of user code
}



/// Start of user code : Footer user code for file test_app2_comp1.cpp

/// End of user code

