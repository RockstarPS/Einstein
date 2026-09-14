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

#include "wdg_proxy.h"
#include "dk_logger.h"
#include <signal.h>

void handle_sigterm(int signum) 
{
    // Perform any necessary cleanup
    WdgProxy_onStop ();
    WdgProxy_onShutdown();
    exit(0);
}

/* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
LOG_DECLARE_CONTEXT ( gWPLogContext );
/* coverity[MISRA C-2012 Directive 8.4 violation] : FALSE */

/* coverity[MISRA C-2012 Directive 5.8 violation] : FALSE */
/* coverity[MISRA C-2012 Directive 8.7 and 8.9 violation] : FALSE */
    uint8_t g_exit_U8 = 1U;
int main ( void )
{
#ifdef __linux__
    LOG_REGISTER_APP_DLT ( "WP", "Watchdog Proxy" );
#else
    LOG_REGISTER_APP_SLOG2 ( "WP", "Watchdog Proxy" );
#endif

#ifdef DEBUG_LOGGING_ENABLED
    LOG_REGISTER_CONTEXT ( (gWPLogContext), "WP ", "Watchdog Proxy", DLT_LOG_VERBOSE );
#else
    LOG_REGISTER_CONTEXT ( (gWPLogContext), "WP ", "Watchdog Proxy", DLT_LOG_WARN );
#endif

    // Register the signal handler
    signal(SIGTERM, handle_sigterm);

    if ( WP_OK == WdgProxy_onInit() )
    {
/* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
        LOGI ( &gWPLogContext, "WdgProxy_onInit Success" );

        if ( WP_OK == WdgProxy_onStart() )
        {
/* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "WdgProxy_onStart Success" );

            while ( g_exit_U8 == 1U )
            {
                WdgProxy_worker();
            }
        }
        else
        {
/* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGE ( &gWPLogContext, "WdgProxy_onStart Failed" );
        }
    }
    else
    {
/* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
        LOGE ( &gWPLogContext, "WdgProxy_onInit Failed" );
    }
/* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    LOG_UNREGISTER_CONTEXT( (gWPLogContext) );

    return EXIT_SUCCESS;
}
