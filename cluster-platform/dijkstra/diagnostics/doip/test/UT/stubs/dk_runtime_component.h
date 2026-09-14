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

#include <cstdint>
#include <thread>
#include <vector>
#include <mutex>
//#include "dk_runtime_version.h"
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

        virtual ~Component()
        {
        }

        void onRxMessage ( MsgDeserializer &msgDes );

        std::map<mid_t, func_t> *getMsgMap()
        {
            return mMsgMap;
        };

        virtual bool onInit();
        virtual bool onExit();
        virtual bool onStart();
        virtual bool onStop();

    protected:

        /// Periodic Task Callback Type
        typedef std::function<void ( void ) > TaskCallback_t;

        /// Task registration function
        int32_t registerTask ( const TaskCallback_t &taskCbk, const uint32_t periodMs );
        bool startTask ( int32_t taskId );
        bool stopTask ( int32_t taskId );

    private:
        const uint32_t MAX_TASKS_COUNT = 10U;    ///< Max Task Count
        const uint32_t  MIN_SLEEP_TIME_MS = 5U;  ///< Min sleep time in milliseconds
        const uint32_t  MAX_SLEEP_TIME_MS = 1000U; ///< Max sleep time in milliseconds

        /// Periodic Task Control Block
        typedef struct
        {
            bool running;
            uint32_t period;
            uint32_t start;
            TaskCallback_t cbk;
        } TaskControl_t;

        uint32_t nowTimeMs();
        void periodicTaskThread();

        std::map<mid_t, func_t> *mMsgMap;   ///< Component Message Map
        //std::vector<TaskControl_t> mvTasks; ///< Task List
        //std::thread *mpPthreadTask = NULL;  ///< Periodic Task Thread
        std::mutex mExecGuardMutex;         ///< Mutex to synchornize task and message handlers
        bool mIsStarted = false;                    ///< Flag to maintain component running status
        const char *mCompName;


};
}
}
}

#endif //DK_RUNTIME_COMPONENT_H
