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
#include "UclALDebugConsole_Impl.h"
#include "stdio.h"

void UclALDebugConsole_Impl_IUclALDebug_Initialize ( SUclALDebugConsoleInst *pInst, uint8 InstId )
{
    pInst->logLevel = pInst->pCfg->logLevel;
    return;
}

void UclALDebugConsole_Impl_IUclALDebug_Shutdown ( SUclALDebugConsoleInst *pInst, uint8 InstId )
{
    return;
}

void UclALDebugConsole_Impl_IUclALDebug_SetLevel ( SUclALDebugConsoleInst *pInst, uint8 InstId, EUclALDebugLevel Level )
{
    pInst->logLevel = Level;
    return;
}

void UclALDebugConsole_Impl_IUclALDebug_Log ( SUclALDebugConsoleInst *pInst, uint8 InstId, EUclALDebugLevel Level,
        char8 *pTag, char8 *pMsg )
{
    if ( ( eUclALDebugLevel_Debug >= pInst->logLevel ) && ( eUclALDebugLevel_Debug == Level ) )
    {
        ( void ) fprintf ( stderr, "Debug: %s: %s\n", pTag, pMsg );
    }
    else if ( ( eUclALDebugLevel_Info >= pInst->logLevel ) && ( eUclALDebugLevel_Info == Level ) )
    {
        ( void ) fprintf ( stderr, "Info: %s: %s\n", pTag, pMsg );
    }
    else if ( ( eUclALDebugLevel_Warn >= pInst->logLevel ) && ( Level == eUclALDebugLevel_Warn ) )
    {
        ( void ) fprintf ( stderr, "Warn: %s: %s\n", pTag, pMsg );
    }
    else if ( ( eUclALDebugLevel_Error >= pInst->logLevel ) && ( Level == eUclALDebugLevel_Error ) )
    {
        ( void ) fprintf ( stderr, "Error: %s: %s\n", pTag, pMsg );
    }
    else
    {
        //Do Nothing
    }

    return;
}
