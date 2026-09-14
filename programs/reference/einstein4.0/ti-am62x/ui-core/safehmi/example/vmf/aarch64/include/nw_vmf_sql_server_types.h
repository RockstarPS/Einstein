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
*  MODULE NAME  :  nw_vmf_sql_server_types.h                                        *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   14th May 2012                                             *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  public header file of vmf sql server                                              *
******************************************************************************/
#ifndef __VMF_SQL_SERVER_TYPES_H
#define __VMF_SQL_SERVER_TYPES_H


#define VMF_SQL_MAX_COMMAND_LEN         500
#define VMF_SQL_MAX_RESPONSE_LEN        500


/* events of VMF_SQL */
enum
{
    VMF_SQL_INVALID = 0,
    VMF_SQL_COMMAND = 1,
};


/* VMQ_SQL_COMMAND and VMQ_SQL_QUERY event*/
typedef struct
{
    unsigned8   response_group;     /* vmf group     - response receiver group */
    unsigned8   response_event;     /* vmf event     - response reveiver event */
    unsigned8   query_num1;         /* query number1 - can be used to identify a query response */
    unsigned8   query_num2;         /* query number2 - can be used to identify a query response */
    char        sql_cmd[VMF_SQL_MAX_COMMAND_LEN];     /* sql string   */
}vmf_sql_command_data_t;


/* SQL response*/
enum
{
    SQL_OK = 0,     
    SQL_BUSY = 1,       
    SQL_ERROR = 2,          
    SQL_ERR_DB_CORRUPT = 3,         /* database is corrupted    */
    SQL_ERR_DB_LOCKED = 4,          /* database is locked       */
    SQL_ERR_PERMISSION = 5,         /* permission denied        */
    SQL_ERR_FULL = 6,               /* database is full         */
    SQL_ERR_SYNTAX = 7,             /* syntax error             */
    SQL_ERR_MEM = 8,                /* memory error             */
    SQL_NOT_EXECUTED = 9            /* command was not executed */
}sql_error_t;


typedef struct
{
    unsigned16  sql_error;          /* sql error in little endian (low,high)*/
    unsigned8   query_num1;         /* query number1 - can be used to identify a query response */
    unsigned8   query_num2;         /* query number2 - can be used to identify a query response */
    char        sql_response[0];    /* sql response , all fields are text field zero terminated  */
}vmf_sql_response_t;

#endif

