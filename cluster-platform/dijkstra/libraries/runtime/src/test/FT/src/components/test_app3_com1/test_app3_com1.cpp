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
#include "test_app3_com1.h"
#include  "test_app3.h"
#include "dk_runtime_application.h"
#include "dk_runtime_wdgif.h"
#include <pthread.h>

/// Start of user code : Header user code for file test_app3_com1.cpp
LOG_DECLARE_CONTEXT(test3comp);
/// End of user code



bool test_app3_com1::onInit()
{
	bool ret = true;

	Component::onInit();

/// Start of user code : User code for function onInit in file test_app3_com1.cpp
	LOG_REGISTER_CONTEXT(test3comp, "T_A3_C1",  "TEST APP3 COM1", DLT_LOG_VERBOSE);
	LOGV(&test3comp, "Enter");
	/// End of user code
	m_t1 = std::thread(&test_app3_com1::func_thread1, this);
	m_t2 = std::thread(&test_app3_com1::func_thread2, this);

	auto handle = m_t1.native_handle();
	( void ) pthread_setname_np ( handle, "func_thread1" );
	handle = m_t2.native_handle();
	( void ) pthread_setname_np ( handle, "func_thread2" );

	return ret;
}

bool test_app3_com1::onExit()
{
	bool ret = true;

	Component::onExit();

/// Start of user code : User code for function onExit in file test_app3_com1.cpp
	LOGV(&test3comp, "Enter");
	m_t1.join();
	m_t2.join();
/// End of user code

	return ret;
}

bool test_app3_com1::onStart()
{
	bool ret = true;

	Component::onStart();

/// Start of user code : User code for function onStart in file test_app3_com1.cpp
	LOGV(&test3comp, "Enter");
/// End of user code

	return ret;
}

bool test_app3_com1::onStop()
{
	bool ret = true;

	Component::onStop();

/// Start of user code : User code for function onStop in file test_app3_com1.cpp
	LOGV(&test3comp, "Enter");
/// End of user code

	return ret;
}

void test_app3_com1::worker()
{
/// Start of user code : User code for function worker in file test_app3_com1.cpp
/// End of user code
}




/// Start of user code : Footer user code for file test_app3_com1.cpp
void test_app3_com1::func_thread1()
{
	int th_count = 10;
	gApp.WdgStart(2000);

	while ( th_count > 0 )
	{
		LOGV(&test3comp,"petting from thread id - ", gettid(), "th_count: ", th_count);
		gApp.WdgSendHeartbeat();
	    th_count--;
	    delay ( 2500 );
	}
	gApp.WdgStop();

}

void test_app3_com1::func_thread2()
{
	int th_count = 10;
	gApp.WdgStart(2000);

	while ( th_count > 0 )
	{
		LOGV(&test3comp,"petting from thread id - ", gettid(), "th_count: ", th_count);
		gApp.WdgSendHeartbeat();
	    th_count--;
	    delay ( 2000 );
	}
	gApp.WdgStop();

}
/// End of user code

