/*
 * VISTEON CORPORATION CONFIDENTIAL
 * ________________________________
 *
 * [2017] Visteon Corporation
 * All Rights Reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 * under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 *
 *---------------------------------------------------------------------------------------------------------------------*/
/*! \file wdg_client.h
 *  \ingroup Dijkstra Health Management
 *  \brief Watchdog Client APIs for Dijkstra Health Management System
 *
 *  Watchdog client provides APIs to connect an application to the health monitoring system and to monitor the threads
 *  within the process for proper execution. wdg_proxy needs to be configured appropirately to monitor the application.
*/

#ifndef _WATCHDOGCLIENT_H_
#define _WATCHDOGCLIENT_H_

#include <cstdint>
#include <thread>
#include <chrono>
#include <vector>

#ifdef __QNX__
    #include <ha/ham.h>
#endif
    extern int8_t *__progname;

namespace dk
{
namespace srvc
{
namespace health
{
class WdgClient
{
    public:
        /**
         * \defgroup Watchdog Client ErrorCode
         */
        /**@{*/
        /** API is executed Successfully */
        const static int32_t WDG_OK  = 0;
        /** API failed to execute */
        const static int32_t WDG_ERR = -1;
        /**@{*/

        /**
         * \fn     static WdgClient *getInstance();
         *
         * \brief  Retreives the Watchdog Client instance for the process
         *
         * \return Watchdog Client Instance
         */
        static WdgClient *getInstance();
        ~WdgClient();

        /**
         * \fn    int32_t connect ( const int8_t *pProcessName, uint32_t reqTimeoutPeriodMs, int32_t wdgLowMark, int32_t wdgHighMark );
         *
         * \brief Connects the process to the Watchdog for monitoring
         *
         * \param pProcessName Name of the process. It is also the entity name.
         * \param reqTimeoutPeriodMs Requested watchdog petting period.
         * \param wdgLowMark Watchdog miss low watermark.
         * \param wdgHighMark Watchdog miss high watermark.
         *
         * \return Granted watchdog petting period.
         */
        int32_t connect ( const int8_t * const pProcessName = __progname, const uint32_t reqTimeoutPeriodMs = 1000U, const int32_t wdgLowMark = 1, const int32_t wdgHighMark = 2 );

        /**
         * \fn   int32_t disconnect ( void );
         *
         * \brief Disconnects the process from the Watchdog for monitoring
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t disconnect ( void );

        /**
         * \fn   int32_t start ( int32_t timeoutMs );
         *
         * \brief Start the monitoring of the callee thread
         *
         * \param timeoutMs Watchdog petting period for the thread
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t start ( int32_t timeoutMs );

        /**
         * \fn   int32_t stop ( void );
         *
         * \brief Stop the monitoring of the callee thread
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t stop ( void );

        /**
         * \fn   int32_t pause ( void );
         *
         * \brief Pause the monitoring of the callee thread
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t pause ( void );

        /**
         * \fn   int32_t resume ( void );
         *
         * \brief Resume the monitoring of the callee thread
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t resume ( void );

        /**
         * \fn   void pet ( void );
         *
         * \brief Pet the watchdog for the callee thread
         *
         * \return WDG_OK - Success, WDG_ERR - Failure
         */
        int32_t pet ( void );

    private:

        typedef struct
        {
            std::chrono::steady_clock::time_point lastPetTime;
            int32_t tid = 0;
            int32_t tmo = 0;
            int32_t tmo_reload = 0;
            bool bMonitorActive = false;
        } WdgThreadInfo_t;

        WdgClient();
        static void periodicTask(); ///< Watchdog periodic processing thread

        int32_t* sdWatchdogIsEnabled(int32_t* reqTimeoutPeriodMs);

        int32_t sdKeepAliveEnable();

        static WdgClient *mpWdgClient; ///< Static variable to hold the instance

#ifdef  __linux__
        static int32_t *mpHandle;
        const static uint64_t HBEATMIN = 1000000000UL; ///< minimum hb interval (1000 msec)
#else
        static ham_entity_t *mpHandle; ///< Handle to QNX High Availability Manager connection
#endif
        static std::thread *mpTask; ///< Periodic Task Thread
        static std::vector<WdgThreadInfo_t *> mWdgThreadList; ///< Monitored thread list
        static int32_t mHeartbeatPeriodMs; ///< HAM Hearbeat petting period
        static bool bFatal;
};
}
}
}

#endif /* _WATCHDOGCLIENT_H_ */
