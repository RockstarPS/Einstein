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
///
///---------------------------------------------------------------------------------------------------------------------
#include "UclALDebugAlogger_Impl.h"
#include <stdio.h>

void UclALDebugAlogger_Impl_IUclALDebug_Initialize( SUclALDebugAloggerInst *pInst, uint8 InstId )
{
    pInst->logLevel = pInst->pCfg->logLevel;
    return;
}

void UclALDebugAlogger_Impl_IUclALDebug_Shutdown( SUclALDebugAloggerInst *pInst, uint8 InstId )
{
    return;
}

void UclALDebugAlogger_Impl_IUclALDebug_SetLevel( SUclALDebugAloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level )
{
    pInst->logLevel = Level;
    return;
}

void UclALDebugAlogger_Impl_IUclALDebug_Log( SUclALDebugAloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level,
                char8 *pTag, char8 *pMsg )
{
    switch (Level)
    {
        case eUclALDebugLevel_Debug:
            __android_log_buf_write( pInst->pCfg->bufferId, ANDROID_LOG_DEBUG, pTag, pMsg );
            break;

        case eUclALDebugLevel_Info:
            __android_log_buf_write( pInst->pCfg->bufferId, ANDROID_LOG_INFO, pTag, pMsg );
            break;

        case eUclALDebugLevel_Warn:
            __android_log_buf_write( pInst->pCfg->bufferId, ANDROID_LOG_WARN, pTag, pMsg );
            break;

        case eUclALDebugLevel_Error:
            __android_log_buf_write( pInst->pCfg->bufferId, ANDROID_LOG_ERROR,pTag, pMsg );
            break;
        default:
            break;
    }

    return;
}
