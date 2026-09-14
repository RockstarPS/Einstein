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
#include "UclALDebugSlogger_Impl.h"
#include <stdio.h>

// QNX Executable Name
extern char *__progname;

void UclALDebugSlogger_Impl_IUclALDebug_Initialize ( SUclALDebugSloggerInst *pInst, uint8 InstId )
{
    pInst->bufferConfig.buffer_set_name = __progname;
    pInst->bufferConfig.num_buffers = 1;

    switch ( pInst->pCfg->logLevel )
    {
        case eUclALDebugLevel_Info:
            pInst->bufferConfig.verbosity_level = SLOG2_INFO;
            break;

        case eUclALDebugLevel_Warn:
            pInst->bufferConfig.verbosity_level = SLOG2_WARNING;
            break;

        case eUclALDebugLevel_Error:
            pInst->bufferConfig.verbosity_level = SLOG2_ERROR;
            break;

        default:
            pInst->bufferConfig.verbosity_level = SLOG2_DEBUG2;
            break;
    }

    pInst->bufferConfig.buffer_config[0].buffer_name = "UCL Log";
    pInst->bufferConfig.buffer_config[0].num_pages = 8;

    /* Register the buffer set. */
    if ( -1 == slog2_register ( & ( pInst->bufferConfig ), pInst->bufferHandle, 0 ) )
    {
        ( void ) fprintf ( stderr, "Error registering slogger2 buffer!\n" );
        return;
    }

    ( void ) slog2_set_verbosity ( pInst->bufferHandle[0], pInst->bufferConfig.verbosity_level );

    return;
}

void UclALDebugSlogger_Impl_IUclALDebug_Shutdown ( SUclALDebugSloggerInst *pInst, uint8 InstId )
{
    ( void ) slog2_reset();
    return;
}

void UclALDebugSlogger_Impl_IUclALDebug_SetLevel ( SUclALDebugSloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level )
{
    pInst->logLevel = Level;

    switch ( Level )
    {
        case eUclALDebugLevel_Info:
            ( void ) slog2_set_verbosity ( pInst->bufferHandle[0], SLOG2_INFO );
            break;

        case eUclALDebugLevel_Warn:
            ( void ) slog2_set_verbosity ( pInst->bufferHandle[0], SLOG2_WARNING );
            break;

        case eUclALDebugLevel_Error:
            ( void ) slog2_set_verbosity ( pInst->bufferHandle[0], SLOG2_ERROR );
            break;

        default:
            //Do Nothing
            break;
    }

    return;
}

void UclALDebugSlogger_Impl_IUclALDebug_Log ( SUclALDebugSloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level,
        char8 *pTag, char8 *pMsg )
{
    switch ( Level )
    {
        case eUclALDebugLevel_Info:
            ( void ) slog2c ( pInst->bufferHandle[0], 0, SLOG2_INFO, pMsg );
            break;

        case eUclALDebugLevel_Warn:
            ( void ) slog2c ( pInst->bufferHandle[0], 0, SLOG2_WARNING, pMsg );
            break;

        case eUclALDebugLevel_Error:
            ( void ) slog2c ( pInst->bufferHandle[0], 0, SLOG2_ERROR, pMsg );
            break;

        default:
            //Do Nothing
            break;
    }

    return;
}
