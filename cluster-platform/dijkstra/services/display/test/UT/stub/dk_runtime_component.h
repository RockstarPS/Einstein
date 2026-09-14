//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
///
/// @file dk_runtime_component.h
/// @ingroup dk_runtime
///
/// @brief Dijkstra Runtime Component Class. All Dijkstra Software Components should inherit and extend this parent class.
///
/// Component is the implementation of the business logic of a specific feature.\n
/// Provides Component Lifecycle hooks, scheduling APIs to create tasks and message routing functionalities
///
//---------------------------------------------------------------------------------------------------------------------

#ifndef DK_RUNTIME_COMPONENT_H
#define DK_RUNTIME_COMPONENT_H

#include "dk_runtime_msgserdes.h"
#include "dk_runtime_msgcmn.h"

namespace dk
{
namespace runtime
{
namespace core
{
class Component
{
    public:
        explicit Component ( std::map<mid_t, func_t> *pMsgMap, const char *pCompName ) : mMsgMap ( pMsgMap ), mCompName(pCompName)
        {
        }

        virtual bool onInit();
        virtual bool onExit();
        virtual bool onStart();
        virtual bool onStop();
        
    private:
        std::map<mid_t, func_t> *mMsgMap;   ///< Component Message Map
        const char *mCompName;

};
}
}
}

#endif //DK_RUNTIME_COMPONENT_H
