///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2024] Visteon Corporation
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
///
///---------------------------------------------------------------------------------------------------------------------
#include "UclALDebugDLT_Impl.h"
#include "UclALOs.h"

void UclALDebugDLT_Impl_IUclALDebug_Initialize ( SUclALDebugDLTInst *pInst, uint8 InstId )
{
    ( void ) InstId;

    switch ( pInst->pCfg->logLevel )
    {
        case eUclALDebugLevel_Info:
            pInst->DltLogLvl = DLT_LOG_INFO;
            break;

        case eUclALDebugLevel_Warn:
            pInst->DltLogLvl = DLT_LOG_WARN;
            break;

        case eUclALDebugLevel_Error:
            pInst->DltLogLvl = DLT_LOG_ERROR;
            break;

        default:
            pInst->DltLogLvl = DLT_LOG_DEBUG;
            break;
    }

    ( void ) UclALOs_MutexCreate ( 0U, &pInst->wrMutexId );

    ( void ) dlt_register_app ( "UCL", "UCL Stack" );

    ( void ) dlt_register_context_ll_ts ( &pInst->DltContext, "UCLI", "UCL Instance 0", pInst->DltLogLvl, DLT_TRACE_STATUS_OFF );

}

void UclALDebugDLT_Impl_IUclALDebug_Shutdown ( SUclALDebugDLTInst *pInst, uint8 InstId )
{
    ( void ) InstId;

    ( void ) UclALOs_MutexDestroy ( 0U, pInst->wrMutexId );

    ( void ) dlt_unregister_context(&pInst->DltContext);

    ( void ) dlt_unregister_app();

}

void UclALDebugDLT_Impl_IUclALDebug_SetLevel ( SUclALDebugDLTInst *pInst, uint8 InstId, EUclALDebugLevel Level )
{
    ( void ) InstId;

    switch ( Level )
    {
        case eUclALDebugLevel_Info:
            pInst->DltLogLvl = DLT_LOG_INFO;
            break;

        case eUclALDebugLevel_Warn:
            pInst->DltLogLvl = DLT_LOG_WARN;
            break;

        case eUclALDebugLevel_Error:
            pInst->DltLogLvl = DLT_LOG_ERROR;
            break;

        default:
            pInst->DltLogLvl = DLT_LOG_DEBUG;
            break;
    }

    ( void ) dlt_register_context_ll_ts ( &pInst->DltContext, "UCLI", "UCL Instance 0", pInst->DltLogLvl, DLT_TRACE_STATUS_OFF );

}

void UclALDebugDLT_Impl_IUclALDebug_Log ( SUclALDebugDLTInst *pInst, uint8 InstId, EUclALDebugLevel Level,
        const char8 *pTag, const char8 *pMsg )
{
    ( void ) InstId;

    switch ( Level )
    {
        case eUclALDebugLevel_Info:
            pInst->DltLogLvl = DLT_LOG_INFO;
            break;

        case eUclALDebugLevel_Warn:
            pInst->DltLogLvl = DLT_LOG_WARN;
            break;

        case eUclALDebugLevel_Error:
            pInst->DltLogLvl = DLT_LOG_ERROR;
            break;

        default:
            pInst->DltLogLvl = DLT_LOG_DEBUG;
            break;
    }

    if ( DLT_RETURN_TRUE == dlt_user_is_logLevel_enabled ( &pInst->DltContext, pInst->DltLogLvl ) )
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->wrMutexId ) )
        {
            if ( DLT_RETURN_TRUE == dlt_user_log_write_start ( &pInst->DltContext, &pInst->ContextData, pInst->DltLogLvl ) )
            {
                ( void ) dlt_user_log_write_string ( &pInst->ContextData, pTag );
                ( void ) dlt_user_log_write_string ( &pInst->ContextData, pMsg );
                ( void ) dlt_user_log_write_finish ( &pInst->ContextData );
            }
        }
        ( void ) UclALOs_MutexUnlock ( 0U, pInst->wrMutexId );
    }

}
