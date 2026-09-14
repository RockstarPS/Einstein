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
#include "test_app1_comp1.h"
#include "test_app1.h"

/// Start of user code : Header user code for file test_app1_component.cpp
using namespace std;
#define TEST_PERIODIC_TIMER 1000u
LOG_DECLARE_CONTEXT(gtestcomp);
/// End of user code



bool test_app1_comp1::onInit()
{
	bool ret = true;

	Component::onInit();

/// Start of user code : User code for function onInit in file test_app1_component.cpp
	LOG_REGISTER_CONTEXT(gtestcomp, "T_A1_C1",  "TEST APP1 COM1", DLT_LOG_VERBOSE);
	LOGV(&gtestcomp, "Enter");
	registerTask([=]() { testPeriodicTask_1sec(); }, TEST_PERIODIC_TIMER);

	mParser.loadConfiguration("/tmp/test.ini");

	std::vector<std::string> totalSec;
	std::vector<std::string> valueList;
	std::vector<std::string> allKeys;
	std::vector<std::string> keylists;

	mParser.getAllSections(totalSec);

	for(auto &x : totalSec )
	{
		LOGI(&gtestcomp, "Section: ", x);
		var_int = mParser.getInt32Value(x, "parsed_int", l_int);
		var_float = mParser.getFloat64Value(x, "parsed_float", l_float);
		var_bool = mParser.getBoolValue(x, "parsed_bool", l_bool);

		LOGV(&gtestcomp, "parsed_int: ", var_int);
		LOGV(&gtestcomp, "parsed_float: ", var_float);
		LOGV(&gtestcomp, "parsed_bool: ", var_bool);

		mParser.getAllValuesForKey(x, "value_list", valueList);
		mParser.getAllKeysFromSection(x, keylists);

		for(string &str : valueList)
			LOGI(&gtestcomp, "value: ", str);

		for(string key : keylists)
			allKeys.push_back(key);

		LOGI(&gtestcomp, "Keys: " );
		for(auto it = allKeys.begin(); it !=allKeys.end();it++)
			cout<<*it<<", ";

		valueList.clear();
		allKeys.clear();
		keylists.clear();
		cout<<"\n";
	}
	return ret;
}

bool test_app1_comp1::onExit()
{
	bool ret = true;

	Component::onExit();

/// Start of user code : User code for function onExit in file test_app1_component.cpp
	LOGV(&gtestcomp, "Enter");
	
/// End of user code

	return ret;
}

bool test_app1_comp1::onStart()
{
	bool ret = true;

	Component::onStart();

/// Start of user code : User code for function onStart in file test_app1_component.cpp
	LOGV(&gtestcomp, "Enter");
/// End of user code

	return ret;
}

bool test_app1_comp1::onStop()
{
	bool ret = true;

	Component::onStop();

/// Start of user code : User code for function onStop in file test_app1_comp1.cpp
	LOGV(&gtestcomp, "Enter");
/// End of user code

	return ret;
}

void test_app1_comp1::worker()
{
/// Start of user code : User code for function worker in file test_app1_comp1.cpp

/// End of user code
}

void test_app1_comp1::onReceiveDkMsgTestMsgReceive(DkMsgTestMsg_t & msg)
{
/// Start of user code : User code for function onReceiveDkMsgTestMsgReceive in file test_app1_component.cpp
LOGI(&gtestcomp, "base.compId: ", msg.base.compId);
LOGI(&gtestcomp, "base.msgCnt: ", msg.base.msgCnt);
LOGI(&gtestcomp, "VAR1: ", msg.var1);
LOGI(&gtestcomp, "VAR2: ", msg.var2);

DkMsgTest2Rcv_t msg3 = {0};
msg3.var_ru8 = (uint8)(msg.var1);
msg3.var_ru16 = (uint16)(msg.var2);
DK_RTE_Send_DkMsgTest2Receive(msg3);

/// End of user code
}



/// Start of user code : Footer user code for file test_app1_comp1.cpp
void test_app1_comp1:: testPeriodicTask_1sec(void)
{
	DkMsgTestTransmit_t msg = {0};
	DkMsgTestTransmitU32_t msg2 = {0};
	DkMsgTestTransmitF64_t msg4 = {0};

	msg.var_bool = 0x0;
	msg.var_uint8 = 0x1;
	msg.var_uint16 = 0x2;
	msg2.var_u32 = 0x3;
	msg4.var_f64 = 5.5;

	DK_RTE_Send_DkMsgTestMsgTransmit(msg);
	DK_RTE_Send_DkMsgTestTransmitU32(msg2);
	DK_RTE_Send_DkMsgTestTransmitF64(msg4);
}
/// End of user code

