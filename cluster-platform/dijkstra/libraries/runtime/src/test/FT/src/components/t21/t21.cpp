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
#include "t21.h"
#include "t4_app.h"

/// Start of user code : Header user code for file t21.cpp
#define TEST_PERIODIC_TIMER_T21 1000u
LOG_DECLARE_CONTEXT(gtestcon2comp1);
/// End of user code



bool T21::onInit()
{
	bool ret = true;

	Component::onInit();

/// Start of user code : User code for function onInit in file t21.cpp
	LOG_REGISTER_CONTEXT(gtestcon2comp1, "T_A4_C2_C1",  "TEST APP1 CON2 COMP1", DLT_LOG_VERBOSE);
	LOGV(&gtestcon2comp1, "Enter");
	registerTask([=]() { testPeriodicTsk21_1sec(); }, TEST_PERIODIC_TIMER_T21);
/// End of user code

	return ret;
}

bool T21::onExit()
{
	bool ret = true;

	Component::onExit();

/// Start of user code : User code for function onExit in file t21.cpp

/// End of user code

	return ret;
}

bool T21::onStart()
{
	bool ret = true;

	Component::onStart();

/// Start of user code : User code for function onStart in file t21.cpp

/// End of user code

	return ret;
}

bool T21::onStop()
{
	bool ret = true;

	Component::onStop();

/// Start of user code : User code for function onStop in file t21.cpp

/// End of user code

	return ret;
}

void T21::worker()
{
/// Start of user code : User code for function worker in file t21.cpp

/// End of user code
}

void T21::onReceiveDkMsgT4Con1Comp2Tx(DkMsg1byte_t & msg)
{
/// Start of user code : User code for function onReceiveDkMsgT4Con1Comp2Tx in file t21.cpp
	LOGI(&gtestcon2comp1, "base.compId: ", msg.base.compId);
	LOGI(&gtestcon2comp1, "base.msgCnt: ", msg.base.msgCnt);
	LOGI(&gtestcon2comp1, "uint8: ", msg.uint8_t);
/// End of user code
}


/// Start of user code : Footer user code for file t21.cpp
void T21::testPeriodicTsk21_1sec()
{
	DkMsg1byte_t msg = {0};
	msg.uint8_t = 0x3;

	DK_RTE_Send_DkMsgT4Con2Comp1P(msg);
}
/// End of user code

