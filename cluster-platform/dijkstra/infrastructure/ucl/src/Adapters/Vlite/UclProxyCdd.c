///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///---------------------------------------------------------------------------------------------------------------------

#include "UclSys.h"
#include <string.h>
#include "types.h"
#include "os_if.h"
#include "power_report_cws_if.h"
#include "UclProxyCdd.h"
#include "UclProxyCdd_resource.h"
#include "UclALHwCbk.h"
#include "portman_if.h"
#include "Rte_UclProxyCdd.h"
/// ===========================================================================
///
/// Private Type / Structure Definitions
///
/// ========================================================================
static wake_state_t UclProxyCdd_cws;
static wake_state_t UclProxyCdd_dws;

/// ===========================================================================
///
/// Variable
///
/// ========================================================================

/// ===========================================================================
///
///  Name:           UclProxyCdd_execute_wake_transitions
///
///  Description:    UclProxyCdd task component OS context platform wake state
///                  transition handler.
///
/// ========================================================================
static void UclProxyCdd_execute_wake_transitions( void );

///===========================================================================
///
///  Name:           COMPONENT CMP_UCLPROXYCDD
///
///  Description:    UCL component task.
///
/// ========================================================================

COMPONENT( CMP_UCLPROXYCDD )
{
    event_mask_type l_event_mask;

    l_event_mask = os_event_get( CMP_UCLPROXYCDD );

    os_event_clear( CMP_UCLPROXYCDD_TASK_ID,(l_event_mask & (EV_UCL_WAKE_TRANSITION | EV_UCLPROXYCDD_TASK_TMO | EV_UCL_PHY_EVENT_TX | EV_EW_UCL_PHY_EVENT_TX | EV_EP_UCL_PHY_EVENT_TX)) );

    if (0u != (l_event_mask & EV_UCL_WAKE_TRANSITION))
    {
        UclProxyCdd_execute_wake_transitions();
    }
    if (0u != (l_event_mask & EV_UCLPROXYCDD_TASK_TMO))
    {
        UclSys_Task( 0 );
    }
    if (0u != (l_event_mask & EV_UCL_PHY_EVENT_TX))
    {
        UclALHwCbk_TransmitComplete( 0 );
    }
    if (0u != (l_event_mask & EV_EW_UCL_PHY_EVENT_TX))
    {
        UclALHwCbk_TransmitComplete( 1 );
    }
}

///===========================================================================
///
///  Name:           UclProxyCdd_reset
///
///  Description:    UclProxyCdd task component bootstrap context 'reset' handler.
///
/// ========================================================================

void uclproxycdd_reset( reset_t reset_kind )
{

    UclProxyCdd_cws = WS_OFF;
    UclProxyCdd_dws = WS_OFF;
}

///===========================================================================
///
///  Name:           uclproxycdd_wakeup
///
///  Description:    UclProxyCdd task component bootstrap context 'wakeup' handler.
///
/// ========================================================================

void uclproxycdd_wakeup( void )
{
    UclProxyCdd_cws = WS_OFF;
    UclProxyCdd_dws = WS_OFF;
}

///===========================================================================
///
///  Name:           uclproxycdd_finalize
///
/// Description:    UclProxyCdd task component bootstrap context 'finalize' handler.
///
/// ========================================================================

void uclproxycdd_finalize( void )
{
    UclProxyCdd_cws = WS_OFF;
    UclProxyCdd_dws = WS_OFF;
}

///===========================================================================
///
///  Name:           uclproxycdd_set_desired_wake_state
///
///  Description:    Set the current state
///
/// ========================================================================

wake_state_t uclproxycdd_set_desired_wake_state( wake_state_t desired_wake_state )
{
    wake_state_t l_wake_state;

    l_wake_state = UclProxyCdd_cws;

    if ((WS_IDLE == desired_wake_state) || (WS_HALTED == desired_wake_state) ||
            (WS_RUNNING == desired_wake_state) || (WS_OFF == desired_wake_state) ||
            (WS_TRANSITIONING == desired_wake_state) || (WS_BOOTSTRAP == desired_wake_state))
    {
        UclProxyCdd_dws = desired_wake_state;

        if (UclProxyCdd_cws != UclProxyCdd_dws)
        {
            os_event_set( CMP_UCLPROXYCDD, EV_UCL_WAKE_TRANSITION );
            l_wake_state = WS_TRANSITIONING;
        }
    }

    return (l_wake_state);
}

///===========================================================================
///
///  Name:           UclProxyCdd_execute_wake_transitions
///
///  Description:    UclProxyCdd task component OS context platform wake state
///                  transition handler.
///
/// ========================================================================
void UclProxyCdd_execute_wake_transitions( void )
{
    if (UclProxyCdd_cws != UclProxyCdd_dws)
    {
        switch (UclProxyCdd_dws)
        {
        case WS_IDLE:
        {
            if ((WS_OFF == UclProxyCdd_cws) || (WS_HALTED == UclProxyCdd_cws) || (WS_RUNNING == UclProxyCdd_cws))
            {
                UclProxyCdd_cws = UclProxyCdd_dws;
            }
            else
            {
                UclProxyCdd_dws = UclProxyCdd_cws;
            }
            break;
        }

        case WS_HALTED:
        {
            UclProxyCdd_cws = UclProxyCdd_dws;
            break;
        }

        case WS_RUNNING:
        {
            if ((WS_IDLE == UclProxyCdd_cws) || (WS_HALTED == UclProxyCdd_cws))
            {

                (void)UclSys_Initialize( 0 );

                UclProxyCdd_cws = UclProxyCdd_dws;
                os_alarm_periodic( EV_UCLPROXYCDD_TASK_TMO, 4 );
            }
            else
            {
                UclProxyCdd_dws = UclProxyCdd_cws;
            }

            break;
        }

        case WS_OFF:
        {
            if (WS_IDLE == UclProxyCdd_cws)
            {
                os_alarm_cancel( EV_UCLPROXYCDD_TASK_TMO );
                (void)UclSys_Shutdown( 0 );
                UclProxyCdd_cws = UclProxyCdd_dws;
            }
            else
            {
                UclProxyCdd_dws = UclProxyCdd_cws;
            }
            break;
        }

        case WS_TRANSITIONING:
        case WS_BOOTSTRAP:
        default:
        {
            UclProxyCdd_dws = UclProxyCdd_cws;
            break;
        }
        }

        if (UclProxyCdd_cws == UclProxyCdd_dws)
        {
            power_report_wake_state( CMP_UCLPROXYCDD, UclProxyCdd_cws );
        }
    }
}
