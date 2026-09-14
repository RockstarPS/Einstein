
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

#include <iostream>
#include <thread>
#include <cstring>
#include <ctime>
#include <chrono>
#ifdef __QNX__
#include <process.h>
#endif
#include "dk_runtime_wdgif.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

#if defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
    using namespace dk::srvc::health;
#endif

bool WdgIf::connect ( const char *pProcessName, uint32_t reqTimeoutPeriodMs )
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_CDC_WATCHDOG_ENABLED)
        if ( CdcRuntime::HealthIf::HEALTHIF_STATUS_OK == CdcRuntime::HealthIf::Register ( pProcessName, reqTimeoutPeriodMs ) )
        {
            ret = true;
            mGrantedTimeoutPeriodMs = reqTimeoutPeriodMs;
            LOGI ( &gRTELogContext, "CDC Watchdog register Success" );
        }
        else
        {
            LOGE ( &gRTELogContext, "CDC Watchdog register failed" );
            mWdgEn = false;
        }
#elif defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        ( void ) pProcessName;
        ( void ) reqTimeoutPeriodMs;
        int32_t lGrantedTimeoutPeriodMs = WdgClient::getInstance()->connect();

        if ( WdgClient::WDG_ERR != lGrantedTimeoutPeriodMs )
        {
            ret = true;
            mGrantedTimeoutPeriodMs = static_cast<uint32_t> ( lGrantedTimeoutPeriodMs );
            LOGI ( &gRTELogContext, "HAM Watchdog register Success" );
        }
        else
        {
            LOGE ( &gRTELogContext, "HAM Watchdog register failed" );
            mWdgEn = false;
        }
#else
        //Dummy for Testing
        mGrantedTimeoutPeriodMs = reqTimeoutPeriodMs;
        ret = true;
#endif
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}

bool WdgIf::disconnect()
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_CDC_WATCHDOG_ENABLED)
        if ( CdcRuntime::HealthIf::HEALTHIF_STATUS_OK == CdcRuntime::HealthIf::Unregister() )
#elif defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->disconnect( ))
#endif
        {
            LOGI ( &gRTELogContext, "Watchdog disconnect success" );
            ret = true;
        }
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}

void WdgIf::setWatchdogEnabled ( bool enable )
{
    mWdgEn = enable;
}

bool WdgIf::getWatchdogEnabled()
{
    return mWdgEn;
}

bool WdgIf::start ( uint32_t timeout )
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_CDC_WATCHDOG_ENABLED)
        if ( CdcRuntime::HealthIf::HEALTHIF_STATUS_OK == CdcRuntime::HealthIf::Start ( timeout ) )
#elif defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->start ( static_cast<int32_t> ( timeout ) ) )
#endif
        {
            ret = true;
        }
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}

bool WdgIf::stop()
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_CDC_WATCHDOG_ENABLED)
        if ( CdcRuntime::HealthIf::HEALTHIF_STATUS_OK == CdcRuntime::HealthIf::Stop() )
#elif defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->stop( ))
#endif
        {
            ret = true;
        }
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}

bool WdgIf::resume()
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->resume( ))
#endif
        {
            ret = true;
        }
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}

bool WdgIf::pause()
{
    bool ret = false;

    if ( mWdgEn )
    {
#if defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->pause( ))
#endif
        {
            ret = true;
        }
    }
    else
    {
        //Watchdog disabled
        ret = false;
    }

    return ret;
}


void WdgIf::sendHeartbeat ( void ) //replaced pet with sendHeartbeat to compiler with VS2015
{

    if ( mWdgEn )
    {
#if defined(DK_CDC_WATCHDOG_ENABLED)
        if ( CdcRuntime::HealthIf::HEALTHIF_STATUS_OK == CdcRuntime::HealthIf::Report() )
        {
            //Do Nothing
        }
        else
        {

            LOGI ( &gRTELogContext, "Watchdog report failed" );
        }

#elif defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
        if ( WdgClient::WDG_OK == WdgClient::getInstance()->pet( ) )
        {
            //Do Nothing
        }
        else
        {

            LOGI ( &gRTELogContext, "Watchdog report failed" );
        }

#endif
    }
    else
    {
        //Watchdog disabled

    }
}
