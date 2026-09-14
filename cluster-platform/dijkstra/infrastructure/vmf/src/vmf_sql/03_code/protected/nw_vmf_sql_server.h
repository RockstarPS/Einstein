/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_sql_server.h                                        *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   14th May 2012                                             *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file of vmf sql server                                              *
******************************************************************************/
#ifndef __VMF_SQL_SERVER_H
#define __VMF_SQL_SERVER_H


#define VMF_TRACE_TASK          "main"
#define VMF_TRACE_TASK_RESULT   "Result"

#ifdef VMF_TRACE
    #define VMF_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
    #define VMF_TRACE_WARNING(scope,  args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK_RESULT,scope, args);
    #define VMF_TRACE_INFO(scope,  args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK_RESULT,scope, args);
#else
    #define VMF_TRACE_ERROR(scope, args...) printf("vmf_sql_svr: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_WARNING(scope, args...) printf("vmf_sql_svr: WARNING "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_INFO(scope,args...)   printf("vmf_sql_svr: INFO"); printf(scope); printf(" -- "); printf(args); printf("\n");
#endif
#define VMF_TRACE_CO_ERROR(scope, args...) printf("vmf_sql_svr: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");

#define DATABASE_FILE "vmf_db.sql"

#endif

