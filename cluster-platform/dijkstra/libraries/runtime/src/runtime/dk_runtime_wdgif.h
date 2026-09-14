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

#ifndef DK_RUNTIME_WDGIF_H
#define DK_RUNTIME_WDGIF_H

#include <iostream>
#include <vector>
#include "dk_runtime_version.h"
#ifdef DK_CDC_WATCHDOG_ENABLED
    #include "HealthIf.hpp"
#endif
#if defined(DK_HAM_WATCHDOG_ENABLED) || defined(DK_SD_WATCHDOG_ENABLED)
    #include "wdg_client.h"
#endif

namespace dk
{
namespace runtime
{
namespace core
{
class WdgIf
{
    public:
        explicit WdgIf() : mWdgEn ( false ) {}
        ~WdgIf() {};
        bool connect ( const char *pProcessName, uint32_t reqTimeoutPeriodMs = 2000U );
        bool disconnect();
        bool start ( uint32_t timeout );
        bool stop();
        bool pause();
		bool resume();
        void sendHeartbeat(); 
        void setWatchdogEnabled ( bool enable );
        bool getWatchdogEnabled();
        uint32_t getGrantedTimeoutMs()
        {
            return mGrantedTimeoutPeriodMs;
        };
    private:
        uint32_t mGrantedTimeoutPeriodMs = 0U; ///< Granted Timeout
        bool mWdgEn; ///< Enable Watchdog
};
}
}
}

#endif // DK_RUNTIME_WDGIF_H
