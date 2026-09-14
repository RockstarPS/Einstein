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
/// @file dk_runtime_container.h
/// @ingroup dk_runtime
///
/// @brief Dijkstra Runtime Container Class.
///
/// Container is the holder for collection of related components. A container with the collection of components
/// can be assigned to any Application to balance the load.\n
/// Provides Component Lifecycle hooks, scheduling APIs to create tasks and message routing functionalities
///
//---------------------------------------------------------------------------------------------------------------------

#ifndef DK_RUNTIME_CONTAINER_H
#define DK_RUNTIME_CONTAINER_H

#include <cstdint>
#include <vector>
#include <set>
#include <iostream>
#include "dk_runtime_version.h"
#include "dk_runtime_component.h"
#include "dk_runtime_fifoserdes.h"
#include "DKOsalSemaphore.h"

namespace dk
{
namespace runtime
{
namespace core
{
class Container
{
    public:
        template <typename T1 = Component *, typename... T2>
        explicit Container ( T1 c, T2... cList ) : mRxMsgQueue ( 1000 ),
            mWaitMsgRxSem ( 0 )
        {
            addComponent ( c, cList... );

            for ( auto component : mComponentList )
            {
                std::map<mid_t, func_t> *pMsgMap = component->getMsgMap();

                for ( std::map<mid_t, func_t>::iterator it = pMsgMap->begin(); it != pMsgMap->end(); ++it )
                {
                    mMsgIDs.insert ( it->first );
                }
            }
        }

        virtual ~Container()
        {
        }

        bool onInit();
        bool onExit();
        bool onStart();
        bool onStop();
        void onRxMessage ( MsgDeserializer &msgDes );
        int32_t runMessagePump();
        ///< TODO: the following function should become part of the configuration in future and should disappear
        void getMessageGroups ( std::set<uint8_t> &msgGroups );

    protected:
        void addComponent() {}

        void addComponent ( Component *pComponent )
        {
            mComponentList.push_back ( pComponent );
        }

        template <typename T1, typename... T2>
        void addComponent ( T1 c, T2... cList )
        {
            mComponentList.push_back ( c );
            addComponent ( cList... );
        }

        std::vector<Component *> mComponentList;
        FifoDeserializer mRxMsgQueue;

    private:
        osal::Semaphore mWaitMsgRxSem;
        std::set<uint16_t> mMsgIDs; ///< Message Ids that the componenents in this container subscribed to
};
}
}
}

#endif //DK_RUNTIME_CONTAINER_H
