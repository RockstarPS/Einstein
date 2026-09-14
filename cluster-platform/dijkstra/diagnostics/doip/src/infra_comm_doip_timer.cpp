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
//-----------------------------------------------------------------------------------------------------------------------------
#include <cstdint>
#include "infra_comm_doip_timer.h"
#include "dk_logger.h"

LOG_IMPORT_CONTEXT ( gDoipLogContext );


int32_t CDoIPTimer::addTimer ( const timeoutCallbackfunction_t &timeoutCallbackfunction )
{
    int32_t lTimerId = -1;

    std::lock_guard<std::mutex> doipTimerlock ( mProtectTimerId );

    lTimerId = mTimerId;
    mTimerMap[lTimerId].mTimeoutCallbackfunction = timeoutCallbackfunction;
    mTimerMap[lTimerId].mTimeCount = 0u;
    mTimerId++;
    LOGD ( &gDoipLogContext, "Timer added for TimerId = ", lTimerId );

    return lTimerId;

}

void CDoIPTimer::ResetTimer( )
{
    std::lock_guard<std::mutex> doipTimerlock ( mProtectTimerId );

    mTimerId = 0;
    mTimerMap.clear();

}

void CDoIPTimer::stopTimer ( int32_t timerId )
{
    std::lock_guard<std::mutex> doipTimerlock ( mProtectTimerId );

    /// -# Set the time count of the timer Id to zero.
    if ( mTimerMap.find ( timerId ) != mTimerMap.end() )
    {
        mTimerMap[timerId].mTimeCount = 0u;
    }

    LOGD ( &gDoipLogContext, "Timer stopped for TimerId = ", timerId );
}

void CDoIPTimer::startTimer ( int32_t timerId, uint32_t timerValue )
{
    std::lock_guard<std::mutex> doipTimerlock ( mProtectTimerId );

    /// -# Set the time-out value for requested timer.
    if ( mTimerMap.find ( timerId ) != mTimerMap.end() )
    {
        mTimerMap[timerId].mTimeCount = timerValue;
    }
    else
    {
        printf("not able to find timer\n");
    }


    LOGD ( &gDoipLogContext, "Timer started for TimerId = ", timerId, "timerValue = ", timerValue );
}

void CDoIPTimer::timerBaseTickTask ( void )
{
    std::map<int32_t, STimer_t>::iterator pTimer;

    /// -# Iterate over the available timer and do the following,\n
    for ( pTimer = mTimerMap.begin(); pTimer != mTimerMap.end(); ++pTimer )
    {
        /// <pre>
        ///     If the timer value is greater than zero, decrement the value one.
        /// </pre>

        if ( pTimer->second.mTimeCount > 0u )
        {
            pTimer->second.mTimeCount--;

            // LOGI(&gDoipLogContext,"Timecount", pTimer->second.mTimeCount);
            if ( pTimer->second.mTimeCount == 0u )
            {
                /// <pre>
                ///     If the timer value is equal to zero, then invoke the time out function configured.
                /// </pre>
                LOGI ( &gDoipLogContext, "Timer expired and callback function invoked" );

                if ( pTimer->second.mTimeoutCallbackfunction )
                {
                    pTimer->second.mTimeoutCallbackfunction();
                }
            }
        }
    }
}
