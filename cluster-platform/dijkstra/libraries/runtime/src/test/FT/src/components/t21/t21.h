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
#ifndef T21_H
#define T21_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_t21.h"



using namespace dk::runtime;

class T21 : public dk::runtime::core::Component
{
public:
    explicit T21(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> *pMsgMap, const char *cmpId) : Component(pMsgMap, cmpId)
    {
    }

    ~T21()
    {
    }

    bool onInit();
    bool onExit();
    bool onStart();
    bool onStop();
    void worker(void);

    void onReceiveDkMsgT4Con1Comp2Tx(DkMsg1byte_t & msg);

private:
/// Start of user code : User code for file t21.h
    void testPeriodicTsk21_1sec(void);
/// End of user code
};



#endif //T21_H

