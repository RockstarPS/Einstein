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
#include "UclALDebugSyslog_Impl.h"
#include <stdio.h>
#include <syslog.h> 

void UclALDebugSyslog_Impl_IUclALDebug_Initialize(SUclALDebugSyslogInst *pInst, uint8 InstId)
{   
    (void)InstId;
    openlog("UCL", LOG_PID | LOG_CONS, LOG_USER);
    pInst->logLevel = pInst->pCfg->logLevel;
}

void UclALDebugSyslog_Impl_IUclALDebug_Shutdown(SUclALDebugSyslogInst *pInst, uint8 InstId)
{   
    (void)InstId;
    (void)pInst;
    closelog();
}

void UclALDebugSyslog_Impl_IUclALDebug_SetLevel(SUclALDebugSyslogInst *pInst, uint8 InstId, EUclALDebugLevel Level)
{
    (void)InstId;
    pInst->logLevel = Level;
}

void UclALDebugSyslog_Impl_IUclALDebug_Log(SUclALDebugSyslogInst *pInst, uint8 InstId, EUclALDebugLevel Level, char8 *pTag, char8 *pMsg)
{  
    (void)InstId;  
    if ((eUclALDebugLevel_Debug == pInst->logLevel) && (eUclALDebugLevel_Debug <= Level))
    {
        syslog(LOG_DEBUG, "%s: %s", pTag, pMsg);
    }
    else if ((eUclALDebugLevel_Info == pInst->logLevel) && (eUclALDebugLevel_Info <= Level))
    {
        syslog(LOG_INFO, "%s: %s", pTag, pMsg);
    }
    else if ((eUclALDebugLevel_Warn == pInst->logLevel) && (eUclALDebugLevel_Warn <= Level))
    {
        syslog(LOG_WARNING, "%s: %s", pTag, pMsg);
    }
    else if ((eUclALDebugLevel_Error == pInst->logLevel) && (eUclALDebugLevel_Error <= Level))
    {
        syslog(LOG_ERR, "%s: %s", pTag, pMsg);
    }
    else
    {
        //Do Nothing
    }
}

