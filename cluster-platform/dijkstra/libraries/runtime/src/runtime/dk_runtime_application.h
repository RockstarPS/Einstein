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
/// @mainpage
///
/// @section intro Introduction
///
/// Dijkstra RTE is the software framework that provides the runtime environment for the
/// software components to execute in a Full Operating System environment. Software components implement
/// business logic without worrying about the platform technicalities. Flexible deployment of Software
/// Components between Application Processes to better balance the load. Logical grouping of software
/// components to reduce system load and improve responsiveness.
///
/// @section features Features
///  Provides infrastructure for
///    * Lifecycle Management
///    * Scheduling
///    * Messaging
///    * Health Monitoring
///
/// @section terminology Terminology
///  * Application is a single executable with an operating system process. An application can
///    contain multiple containers
///  * Container is the holder for collection of related components. A container with the collection
///    of components can be assigned to any Application to balance the load
///  * Component is the implementation of the business logic of a specific feature
///  * Local Routing is when messages are routed between Components within the same Application
///  * External Routing is when messages are routed between Components inside different Applications.
///    This will use the platform IPC.
///
/// @section imp_pages Important Pages
///    * @ref release_notes
///
/// @page release_notes Release Notes
///
/// @section comp_info Component Information
/// <table>
/// <tr><th>RTC Artifact <th>Information
/// <tr><td>Project Area <td>CoC Domain Controllers and OS BSP
/// <tr><td>Stream       <td>fpf.dk.dev
/// <tr><td>Component    <td>dk-runtime-core
/// <tr><td>Baseline     <td>exp-20180810-0.5.0
/// </table>
///
/// @section dependencies Dependencies
///   * Dijkstra Runtime Core
///   * Dijkstra Logger
///
/// @section history Change History
/// ### Version 0.6.0
///   * RTC 1197126: Allow applications to disable watchdog feature
///
/// ### Version 0.5.0
///   * RTC 1171917: Component id is missed during de-serialization
///   * RTC 1160872: Dk runtime core - Sleep time Warning message logged for 10ms task
///
/// ### Version 0.4.0
///   * RTC 1152311: Periodic tasks are not scheduled properly
///   * RTC 1152303: High CPU load for DK Applications
///
/// ### Version 0.3.0
///   * RTC 1135387: Runtime support for GM E4
///
/// ### Version 0.2.0
///   * RTC 1098765: DK Runtime Update Component to protect periodic task and message callback with mutex
///
/// ### Version 0.1.0
///   * Initial version
///
/// @defgroup dk_runtime Dijkstra Runtime
///
/// @file dk_runtime_application.h
/// @ingroup dk_runtime
///
/// @brief Dijkstra Runtime Application Class. All Dijkstra Application should inherit and extend this parent class.
///
/// Application is a single executable with an operating system process. An application can contain multiple containers.\n
/// Manages Communication, Health and Logging interface for Dijkstra Components
///
//---------------------------------------------------------------------------------------------------------------------

#ifndef DK_RUNTIME_APPLICATION_H
#define DK_RUNTIME_APPLICATION_H

#include <cstdint>
#include <vector>
#include <string>
#include <cstring>
#include <thread>
#include <chrono>
#include <memory>
#include "dk_runtime_version.h"
#include "dk_runtime_container.h"
#include "dk_runtime_fifoserdes.h"
#include "dk_runtime_ipcmsgif.h"
#include "dk_runtime_wdgif.h"

namespace dk
{
namespace runtime
{
namespace core
{
class Application
{
    public:
        explicit Application ( const char *pAppName ) : mAppName ( pAppName ),
            mDispatchQueue ( 1000U )
        {
        }
        virtual ~Application()
        {
        }

        int32_t run();
        int32_t stop();

        void runIpcMessagePump();
        void runDispatchQueue();

        bool getIsRunning();
        void setWatchdogEnabled ( bool enable );
        uint32_t getWdgWaitTimeout();
        bool WdgStart ( uint32_t timeout );
        void WdgSendHeartbeat();
        bool WdgStop();

        void sendMsgToDisplatchQueue ( MsgSerializer *pMsgSer );
        void sendMsgToIpc ( std::shared_ptr<MsgSerializer> &pMsgSer );

    protected:
        // Methods implemented by the Runtime
        void addContainer() {}

        void addContainer ( Container *pContainer )
        {
            mContainerList.push_back ( pContainer );
        }

        template <typename T1, typename... T2>
        void addContainer ( T1 c, T2... cList )
        {
            mContainerList.push_back ( c );
            addContainer ( cList... );
        }

        // Methods to be overridden by the Application
        virtual bool onInit();
        virtual bool onExit();
        virtual bool onStart();
        virtual bool onStop();
        virtual int32_t onRun();

        std::string mAppName;                    ///< Name of the application
        bool mIsRunning = false;                 ///< Flag that indicates if the application is still running
        std::vector<Container *> mContainerList; ///< List of containers in the application
        FifoSerializer mDispatchQueue;           ///< Dispatch Queue to dispatch messags to containters
        IpcMsgIf mIpcMsgIf;                      ///< IPC Messaging Interface
        WdgIf mWdgIf;                            ///< Watchdog Interface

    private:
        bool initIpcMsgIf();

        osal::Semaphore *mpDispatchQueueSem = nullptr; ///< Semaphore to wait for message in dispatch queue
};
}
}
}
#endif //DK_RUNTIME_APPLICATION_H
