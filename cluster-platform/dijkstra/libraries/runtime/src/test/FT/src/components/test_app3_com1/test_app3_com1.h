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
#ifndef TEST_APP3_COM1_H
#define TEST_APP3_COM1_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_test_app3_com1.h"



using namespace dk::runtime;

class test_app3_com1 : public dk::runtime::core::Component
{
public:
    explicit test_app3_com1(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)

    {
    }

    ~test_app3_com1()
    {
    }

    bool onInit();
    bool onExit();
    bool onStart();
    bool onStop();
    void worker(void);


private:
/// Start of user code : User code for file test_app3_com1.h

    void func_thread1();
    void func_thread2();
    std::thread m_t1;
    std::thread m_t2;
/// End of user code
};



#endif //TEST_APP3_COM1_H

