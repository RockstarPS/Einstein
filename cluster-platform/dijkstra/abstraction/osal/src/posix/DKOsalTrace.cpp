/**********************************************************************************
 **
 **  \file osaltrace.cpp
 **
 **  Created on: Apr 25, 2017
 **  \author: VMUTHUSU
 **  | Date       | Author   |Description                                           
 **  |------------|----------|--------------------------------                          
 **  | 2017-04-25 | VMUTHUSU | Create Initial Module.
 **  | 2023-09-20 | damudhar | Added Doxygen document
 **
 ** \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **********************************************************************************/
/**********************************************************************************************************************
 *  HEADER FILE GUARD
 **********************************************************************************************************************/ 
/* Related Header file */
#ifdef _WIN32
#include <unistd.h>            /* added for windows build to enable CLOCK_REALTIME*/
#endif
#include "DKOsalTrace.h"       /* for OSAL_DBG inclusion */
#include <cstdarg>             /* for standard argument list inclusion such as va_start etc for linux build */
/* coverity[misra_cpp_2008_rule_27_0_1_violation] : FALSE */
#include <cstdio>              /*vsnprintf*/
#include <cstdlib>             /*exit*/

/* other library includes */
/* project includes */
#include "DKOsalThread.h"      /* to access Thread Class to get currentThreadID to be printed */

#define MAX_MSG_LEN 128U

namespace dk
{

namespace osal
{
    
#if (OSAL_ENABLE_DEBUG != 0)
void osal_dbg ( const char *fmt, ... )
{
    char buffer[MAX_MSG_LEN];
    va_list args;

    va_start ( args, fmt );
    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    (void) ::vsnprintf ( buffer, MAX_MSG_LEN, fmt, args );
    va_end ( args );

    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    OSAL_OUTPUT_GENERIC ( "OSAL_DEBUG", "0x%08x:0x%08x", Thread::currentProcessId(), Thread::currentThreadId(), buffer );
}
#endif

#if (OSAL_ENABLE_WARNING != 0)
/* coverity[cert_dcl50_cpp_violation] : FALSE */
void osal_warn ( const char *fmt, ... )
{
    char buffer[MAX_MSG_LEN];
    va_list args;

    va_start ( args, fmt );
    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    (void) ::vsnprintf ( buffer, MAX_MSG_LEN, fmt, args );
    va_end ( args );

    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    OSAL_OUTPUT_GENERIC ( "OSAL_WARN", "0x%08x:0x%08x", dk::osal::Thread::currentProcessId(), dk::osal::Thread::currentThreadId(),
            buffer );
}
#endif

#if (OSAL_ENABLE_ERROR != 0)
/* coverity[cert_dcl50_cpp_violation] : FALSE */
void osal_error ( const char *fmt, ... )
{
    char buffer[MAX_MSG_LEN];
    va_list args;

    va_start ( args, fmt );
    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    (void) ::vsnprintf ( buffer, MAX_MSG_LEN, fmt, args );
    va_end ( args );

    /* coverity[misra_cpp_2008_rule_5_2_12_violation] : FALSE */
    OSAL_OUTPUT_GENERIC ( "OSAL_ERROR", "0x%08x:0x%08x", dk::osal::Thread::currentProcessId(), dk::osal::Thread::currentThreadId(),
            buffer );
}
#endif

void osal_abort()
{
    // CIA_MEMORY_BARRIER
#ifndef _WIN32   //added to compile with VS2015
    /* coverity[misra_cpp_2008_rule_7_4_3_violation] : FALSE */
    asm volatile ( "" : : : "memory" );
#endif
    /* coverity[misra_cpp_2008_rule_18_0_3_violation] : FALSE */
    ::exit ( -1 );
}

} /* namespace osal */

} /* namespace dk */
