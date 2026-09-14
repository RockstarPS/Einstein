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

#include <pthread.h>
#include <iostream>
#ifdef __linux__
#include <systemd/sd-daemon.h>
#endif

#include "dk_logger.h"
#include "wdg_client.h"

#define MSEC_NS               (1000000UL)

LOG_DECLARE_CONTEXT ( gWCLogContext );

using namespace dk::srvc::health;

WdgClient *WdgClient::mpWdgClient = nullptr;
std::thread *WdgClient::mpTask = nullptr;

#ifdef  __linux__
int32_t *WdgClient::mpHandle = nullptr;
#else
ham_entity_t *WdgClient::mpHandle = nullptr;
#endif
std::vector<WdgClient::WdgThreadInfo_t *> WdgClient::mWdgThreadList;
bool WdgClient::bFatal = false;
int32_t WdgClient::mHeartbeatPeriodMs = 0;

WdgClient *WdgClient::getInstance()
{
    if ( nullptr == mpWdgClient )
    {
        mpWdgClient = new WdgClient();
    }

    return mpWdgClient;
}

WdgClient::WdgClient()
{
    mpHandle = nullptr;

    LOG_REGISTER_CONTEXT ( gWCLogContext, "WC  ", "Watchdog Client", DLT_LOG_VERBOSE );
}

WdgClient::~WdgClient()
{
    try {
        LOG_UNREGISTER_CONTEXT ( gWCLogContext );
    } catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    } catch ( ... ) {
        std::cout << "Caught Exception: LOG_UNREGISTER_CONTEXT failed" << '\n';
    }
}

int32_t WdgClient::connect ( const int8_t * const pProcessName, const uint32_t reqTimeoutPeriodMs, const int32_t wdgLowMark, const int32_t wdgHighMark )
{
    mHeartbeatPeriodMs = WDG_ERR;

#ifdef  __linux__
    (void) pProcessName;
    (void) reqTimeoutPeriodMs;
    (void) wdgLowMark;
    (void) wdgHighMark;
    mHeartbeatPeriodMs = sdKeepAliveEnable();
#else
    if ( 0 == access ( "/proc/ham", F_OK ) )
    {
        uint64_t timeout = HAMHBEATMIN;

        if ( reqTimeoutPeriodMs > ( timeout / MSEC_NS ) )
        {
            timeout = (static_cast<uint64_t> ( reqTimeoutPeriodMs) * MSEC_NS );
        }

        mpHandle = ham_attach_self ( reinterpret_cast<const char *>(pProcessName), timeout, wdgLowMark, wdgHighMark, 0U );

        if ( nullptr != mpHandle )
        {
            mHeartbeatPeriodMs = (static_cast<int32_t> (timeout) / static_cast<int32_t> (MSEC_NS) );
            LOGI ( &gWCLogContext, "HAM Connection Success" );

            mpTask = new (std::nothrow) std::thread ( &WdgClient::periodicTask );

            if ( nullptr != mpTask )
            {
                const auto handle = mpTask->native_handle();
                ( void ) pthread_setname_np ( handle, "WdgClientMon" );
                LOGI ( &gWCLogContext, "Monitoring thread creation success" );
                bFatal = false;
            }
            else
            {
                LOGE ( &gWCLogContext, "Monitoring thread creation failed" );
            }
        }
        else
        {
            LOGE ( &gWCLogContext, "HAM Connection Failed" );
        }
    }

#endif

    return mHeartbeatPeriodMs;
}

int32_t WdgClient::disconnect ( void )
{
    int32_t ret = WDG_ERR;

    if ( nullptr != mpHandle )
    {
#ifdef  __QNX__
        if ( 0 == ham_detach_self ( mpHandle, 0U ) )
        {
            ret = WDG_OK;
        }
#else
        ret = WDG_OK;
#endif
    }

    mpHandle = nullptr;

    return ret;
}

void WdgClient::periodicTask()
{
    const int32_t period = mHeartbeatPeriodMs / 2;
    std::chrono::steady_clock::time_point nextStartTime{ std::chrono::steady_clock::now() };

    while ( nullptr != mpHandle )
    {
        nextStartTime = std::chrono::steady_clock::now() + std::chrono::milliseconds ( period );

        for ( uint32_t idx = 0U; idx < mWdgThreadList.size(); idx++ )
        {
            WdgThreadInfo_t *const pRec = mWdgThreadList[idx];

            if ( true == pRec->bMonitorActive )
            {
                if ( pRec->tmo > 0 )
                {
                    pRec->tmo = pRec->tmo - period;
                }
                else
                {
                    LOGE ( &gWCLogContext, "tid-", pRec->tid, " failed to check-in" );
                    bFatal = true;
                }
            }
        }

        if ( true != bFatal )
        {
#ifdef  __linux__
            (void) sd_notify(0, "WATCHDOG=1");
#else
            ( void ) ham_heartbeat();
#endif
        }

        std::this_thread::sleep_until ( nextStartTime );
    }
}

int32_t WdgClient::start ( int32_t timeoutMs )
{
    int32_t ret;

    if ( nullptr != mpHandle )
    {
        if ( timeoutMs < mHeartbeatPeriodMs )
        {
            timeoutMs = mHeartbeatPeriodMs;
        }

        WdgThreadInfo_t * const pRec = new (std::nothrow) WdgThreadInfo_t;

        if ( nullptr != pRec )
        {
            pRec->tid = gettid();
            pRec->lastPetTime = std::chrono::steady_clock::now();
            pRec->tmo = timeoutMs;
            pRec->tmo_reload = timeoutMs;
            pRec->bMonitorActive = true;

            mWdgThreadList.push_back ( pRec );
            ret = WDG_OK;
        }
        else
        {
            ret = WDG_ERR;
        }
    }
    else
    {
        ret = WDG_ERR;
    }

    return ret;
}

int32_t WdgClient::stop ( void )
{
    int32_t ret = WDG_ERR;
    const int32_t tid = gettid();

    if ( nullptr != mpHandle )
    {
        for ( uint32_t idx = 0U; idx < mWdgThreadList.size(); idx++ )
        {
            WdgThreadInfo_t *const pRec = mWdgThreadList[idx];

            if ( pRec->tid == tid )
            {
                ( void ) mWdgThreadList.erase ( mWdgThreadList.begin() + static_cast<int64_t>( idx ) );
                ret = WDG_OK;
                break;
            }
        }
    }

    return ret;
}

int32_t WdgClient::pause ( void )
{
    int32_t ret = WDG_ERR;
    const int32_t tid = gettid();

    if ( nullptr != mpHandle )
    {
        for ( uint32_t idx = 0U; idx < mWdgThreadList.size(); idx++ )
        {
            WdgThreadInfo_t *const pRec = mWdgThreadList[idx];

            if ( pRec->tid == tid )
            {
                pRec->tmo = pRec->tmo_reload;
                pRec->bMonitorActive = false;
                ret = WDG_OK;
                break;
            }
        }
    }

    return ret;
}

int32_t WdgClient::resume ( void )
{
    int32_t ret = WDG_ERR;
    const int32_t tid = gettid();

    if ( nullptr != mpHandle )
    {
        for ( uint32_t idx = 0U; idx < mWdgThreadList.size(); idx++ )
        {
            WdgThreadInfo_t *const pRec = mWdgThreadList[idx];

            if ( pRec->tid == tid )
            {
                pRec->tmo = pRec->tmo_reload;
                pRec->bMonitorActive = true;
                ret = WDG_OK;
                break;
            }
        }
    }

    return ret;
}

int32_t WdgClient::pet ( void )
{
    int32_t ret = WDG_ERR;
    const int32_t tid = gettid();

    if ( nullptr != mpHandle )
    {
        for ( uint32_t idx = 0U; idx < mWdgThreadList.size(); idx++ )
        {
            WdgThreadInfo_t *const pRec = mWdgThreadList[idx];

            if ( ( pRec->tid == tid ) && ( true == pRec->bMonitorActive ) )
            {
                pRec->tmo = pRec->tmo_reload;
                ret = WDG_OK;
                break;
            }
        }
    }

    return ret;
}

int32_t* WdgClient::sdWatchdogIsEnabled(int32_t* reqTimeoutPeriodMs)
{
    int32_t *pRet = nullptr;

#ifdef __linux__
    uint64_t reqTimeoutPeriodUs = 0;

    /*Get the watchdog timeout configured*/
    static int32_t ret = sd_watchdog_enabled(0, &reqTimeoutPeriodUs);

    if(0 < ret)
    {
        if( HBEATMIN <= reqTimeoutPeriodUs )
        {
            *reqTimeoutPeriodMs = (static_cast<int32_t> (reqTimeoutPeriodUs) / static_cast<int32_t> (MSEC_NS) );
        }
        else
        {
            *reqTimeoutPeriodMs = (static_cast<int32_t> (HBEATMIN) / static_cast<int32_t> (MSEC_NS) );
        }

        pRet = &ret;
    }
#endif

    return pRet;
}

int32_t WdgClient::sdKeepAliveEnable()
{
    int32_t ret = WDG_ERR;

#ifdef __linux__
    /*Get the watchdog timeout configured*/
    mpHandle = sdWatchdogIsEnabled( &mHeartbeatPeriodMs );

    if(nullptr != mpHandle)
    {
        LOGI ( &gWCLogContext, "Watchdog is configured in service file. Timeout in Ms: \n", mHeartbeatPeriodMs);

        mpTask = new (std::nothrow) std::thread ( &WdgClient::periodicTask );

        if ( nullptr != mpTask )
        {
            const auto handle = mpTask->native_handle();
            ( void ) pthread_setname_np ( handle, "WdgClientMon" );
            LOGI ( &gWCLogContext, "Monitoring thread creation success" );
            bFatal = false;
            ret = mHeartbeatPeriodMs;
        }
        else
        {
            LOGE ( &gWCLogContext, "Monitoring thread creation failed" );
        }
    }
    else
    {
        LOGE ( &gWCLogContext, "systemd Watchdog supervision mode not enabled in service file");
    }

#endif

    return ret;
}

