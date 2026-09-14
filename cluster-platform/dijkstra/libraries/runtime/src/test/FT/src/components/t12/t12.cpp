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
// Date: Sun Nov 01 21:09:51 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "t12.h"
#include "t4_app.h"
/// Start of user code : Header user code for file t12.cpp
#define TEST_PERIODIC_TIMER_T12 1000u
LOG_DECLARE_CONTEXT(gtestcon1comp2);
/// End of user code



bool T12::onInit()
{
	bool ret = true;

	Component::onInit();

/// Start of user code : User code for function onInit in file t12.cpp
	LOG_REGISTER_CONTEXT(gtestcon1comp2, "T_A4_C1_C2",  "TEST APP1 CON1 COMP2", DLT_LOG_VERBOSE);
	LOGV(&gtestcon1comp2, "Enter");
	registerTask([=]() { testPeriodicTsk12_1sec(); }, TEST_PERIODIC_TIMER_T12);

/// End of user code

	return ret;
}

bool T12::onExit()
{
	bool ret = true;

	Component::onExit();

/// Start of user code : User code for function onExit in file t12.cpp

/// End of user code

	return ret;
}

bool T12::onStart()
{
	bool ret = true;

	Component::onStart();

/// Start of user code : User code for function onStart in file t12.cpp

/// End of user code

	return ret;
}

bool T12::onStop()
{
	bool ret = true;

	Component::onStop();

/// Start of user code : User code for function onStop in file t12.cpp

/// End of user code

	return ret;
}

void T12::worker()
{
/// Start of user code : User code for function worker in file t12.cpp

/// End of user code
}

void T12::onReceiveDkMsgT4Con1comp1Tx(DkMsg1byte_t & msg)
{
/// Start of user code : User code for function onReceiveDkMsgT4Con1comp1Tx in file t12.cpp
	LOGI(&gtestcon1comp2, "base.compId: ", msg.base.compId);
	LOGI(&gtestcon1comp2, "base.msgCnt: ", msg.base.msgCnt);
	LOGI(&gtestcon1comp2, "uint8: ", msg.uint8_t);
	
	DK_RTE_Send_DkMsgT4Con1Comp2Tx(msg);
/// End of user code
}


/// Start of user code : Footer user code for file t12.cpp
void T12::testPeriodicTsk12_1sec()
{
	DkMsg1byte_t msg = {0};
	msg.uint8_t = 0x2;

	DK_RTE_Send_DkMsgT4Con1Comp2P(msg);
}
/// End of user code

