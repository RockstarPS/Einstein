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
*  MODULE NAME  :  nw_vmf_sql_server.c                                        *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   14th May 2012                                             *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  vmf sql server                                                             *
******************************************************************************/

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_sql_server.h"
#include "nw_vmf_sql_server_types.h"

#include "sqlite3.h"



/* defs and typedefs */
#define MAX_FAR_DATA_LEN        4062
#define SQL_SERVER_NAME    "VmfSql"




/* global data */
unsigned8           vmf_trid;

/* function prototypes */
static vmf_ret_t vmf_sql_receiver       (void);
static vmf_ret_t vmf_sql_msg_parser     (vmf_client_id_t cid, sqlite3 *db_handle, vmf_msg_t *msg);
static vmf_ret_t vmf_sql_msg_send       (unsigned16 vmf_sql_error, vmf_client_id_t cid, unsigned8 event, 
                                         unsigned8 group,  unsigned8 query_num1, unsigned8 query_num2, 
                                         unsigned8 *pdata, unsigned16 data_len);
static unsigned16 nw_vmf_sql_map_error  (int sqlite_error);

/*****************************************************************************
 *
 *   Function Name: main()
 *
 *   Description:   main function of vmf sql server
 *
 *   Parameters:    argc, argv
 *
 *   Return :       0 if OK
 *
 ******************************************************************************/
int main (int argc, char *argv[])
{
    
    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, SQL_SERVER_NAME) < 0)
    {
        VMF_TRACE_CO_ERROR("main","CANNOT CONNECT TO VMF TRACER");
    }

    VMF_TRACE_INFO("main", "server startet. PID==%d, Trid=%d", getpid(),vmf_trid);

    /* now receive message forever */
    (void)vmf_sql_receiver();

    VMF_TRACE_INFO("main", "FINISHED!!!");

    return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_sql_receiver(unsigned8 my_message_group)
 *
 *   Description:   start the vmf sql command receiver
 *
 *   Parameters:    void
 *
 *   Return :       vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sql_receiver(void)
{
    VMF_VAR_MSG_TYP(MAX_FAR_DATA_LEN)   my_msg;
    vmf_client_id_t     cid;
    vmf_ret_t           my_ret=VMF_ERROR;
    unsigned16          my_len;
    sqlite3             *db_handle;
    int                 iret;
    unsigned8           groupid_list[]={VMF_SQL};


    VMF_TRACE_INFO( "vmf_sql_receiver", "vmf_sql_receiver started");

    /* connect VMF */
    cid = nw_vmf_connect(SQL_SERVER_NAME, NULL, 0, 100, sizeof(my_msg));
    if (cid < 0)
    {
        VMF_TRACE_ERROR("vmf_sql_receiver", "nw_vmf_connect() failed - error==%d",cid);
        return VMF_ERR_INVALID_CID;
    }

    /* open SQL database */
    iret = sqlite3_open(DATABASE_FILE, &db_handle);
    if (iret != SQLITE_OK)
    {
        VMF_TRACE_ERROR("vmf_sql_receiver", "sqlite3_open(%s) failed - error==%d",DATABASE_FILE,iret);
        return VMF_ERROR;
    }
    
    /* register message group */
    my_ret = nw_vmf_register_msg_group (cid, sizeof(groupid_list), groupid_list);
    if (my_ret < 0)
    {
        VMF_TRACE_ERROR("vmf_sql_receiver", "nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
        return my_ret;
    }

    VMF_TRACE_INFO("vmf_sql_receiver", "connected to vmf - start reception.");

    while (true)
    {
        my_len = nw_vmf_receive (cid, (vmf_msg_t*)&my_msg, sizeof(my_msg));
        if (my_len <= 0)
        {
            VMF_TRACE_ERROR("vmf_sql_receiver", "nw_vmf_receive error = %d",my_len);
            delay(50); /* wait some ms to prevent CPU lock in case of error*/
        }
        else
        {
            VMF_TRACE_INFO("vmf_sql_receiver", "nw_vmf_receive received %d bytes of data",my_len);
            my_ret = vmf_sql_msg_parser(cid,db_handle,(vmf_msg_t *)&my_msg);
                
        }
   }
   return my_ret;
}





/*****************************************************************************
 *
 *   Function Name: parse_vmf_sql_msg()
 *
 *   Description:   parse vmf-sql messages
 *
 *   Parameters:    pointer to vmf message
 *
 *   Return :       vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sql_msg_parser(vmf_client_id_t cid,sqlite3 *db_handle, vmf_msg_t *pvmf_msg)
{
    vmf_basic_msg_t *p_vmf_basic_msg;
    vmf_ret_t       vmf_ret=VMF_OK;
    unsigned8       cmd;
    
    p_vmf_basic_msg = (vmf_basic_msg_t*)&(pvmf_msg->vmf_basic_msg);
    cmd = NW_VMF_BASIC_MSG_EVENT(p_vmf_basic_msg);
    
    if (NW_VMF_BASIC_MSG_GROUP(p_vmf_basic_msg) != VMF_SQL)
    {
        /* ignore event */
        return vmf_ret;
    }
    
    switch (cmd)
    {
        case VMF_SQL_COMMAND:
        {
            vmf_sql_command_data_t *p_cmd;
            sqlite3_stmt *vm;
            char        sql_response[VMF_SQL_MAX_RESPONSE_LEN];
            char        single_val[50];
            unsigned16  single_val_len;
            int         data_type=0;
            int         iret=0;
            unsigned16  vmf_sql_error = SQL_OK;
            unsigned16  data_len=0;
            unsigned8   event=0;
            unsigned8   group=0;
            unsigned8   query_num1=0;
            unsigned8   query_num2=0;
            
            p_cmd = (vmf_sql_command_data_t*)NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_basic_msg);
            VMF_TRACE_INFO("vmf_sql_msg_parser","received sql VMQ_SQL_COMMAND: '%s'",p_cmd->sql_cmd);

            event = p_cmd->response_event;
            group = p_cmd->response_group;
            query_num1 = p_cmd->query_num1;
            query_num2 = p_cmd->query_num2;
            
            sqlite3_prepare(db_handle,p_cmd->sql_cmd, -1, &vm, NULL);

            while(true)
            {
                int num_values=0;
                int cnt;
                
                memset(sql_response,0,sizeof(sql_response));
                data_len = 0;
                
                iret = sqlite3_step(vm);
                
                if (iret == SQLITE_DONE)
                {
                    VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_DONE");
                    break;
                }
                else if (iret == SQLITE_MISUSE )
                {
                    VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_MISUSE");
                    break;
                }
                else 
                {
                    VMF_TRACE_INFO("vmf_sql_msg_parser","sqlite3_step ret=%d",iret);
                }
                
                num_values = sqlite3_data_count(vm);
                VMF_TRACE_INFO("vmf_sql_msg_parser","sqlite3_data_count() returned %d values",num_values);

                if (0 == num_values)
                {
                    VMF_TRACE_INFO("vmf_sql_msg_parser","sqlite3_data_count() = 0!");
                    break;
                }
                
                for (cnt=0; cnt<num_values; cnt++)
                {
                    memset(single_val,0,sizeof(single_val));
                    single_val_len = 0;

                    data_type = sqlite3_column_type(vm,cnt);
                    switch(data_type)
                    {
                        case SQLITE_INTEGER:
                        {
                            snprintf(single_val,sizeof(single_val),"%d",sqlite3_column_int(vm, cnt));
                            single_val_len = strlen(single_val) +1; /* len with zero */
                            VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_INTEGER: single_val=%s",single_val);
                        }
                        break;

                        case SQLITE_TEXT:
                        {
                            strncpy(single_val,(char *)sqlite3_column_text(vm, cnt),sizeof(single_val));
                            single_val_len = strlen(single_val) +1; /* len with zero */
                            VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_TEXT: single_val=%s",single_val);
                        }
                        break;
                        
                        case SQLITE_FLOAT:
                            VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_FLOAT");
                        break;
                        case SQLITE_BLOB:
                            VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_BLOB");
                        break;
                        case SQLITE_NULL:
                            VMF_TRACE_INFO("vmf_sql_msg_parser","SQLITE_NULL");
                        break;

                        default:
                            VMF_TRACE_INFO("vmf_sql_msg_parser","INVALID-Type");
                        break;
                        
                    }
                    if (single_val_len > 0)
                    {
                        (void)nw_os_smemcpy(&(sql_response[data_len]),sizeof(sql_response),single_val,single_val_len);
                        data_len+=single_val_len;
                    }
                }
                VMF_TRACE_INFO("vmf_sql_msg_parser","send=%d bytes to vmf",single_val_len);
                vmf_sql_error = nw_vmf_sql_map_error(iret);
                vmf_ret = vmf_sql_msg_send( vmf_sql_error, cid, event, group, query_num1, query_num2,(unsigned8*)sql_response, data_len);
                if (vmf_ret != VMF_OK)
                {
                    VMF_TRACE_ERROR("vmf_sql_msg_parser", "vmf_sql_msg_send() failed (1)!");                
                }
            }
    
            sqlite3_finalize(vm);
            vmf_sql_error = nw_vmf_sql_map_error(iret);
            /* send empty response as last message  */
            vmf_ret = vmf_sql_msg_send(vmf_sql_error,cid, event, group, query_num1, query_num2, NULL, 0);
            if (vmf_ret != VMF_OK)
            {
                VMF_TRACE_ERROR("vmf_sql_msg_parser", "vmf_sql_msg_send() failed (2)!");                
            }
        }
        break;
        
        default:
            /* ignore event */
        break;
    }

    return vmf_ret;
}



/*****************************************************************************
 *
 *   Function Name: vmf_sql_msg_send()
 *
 *   Description:   send the sql response to a vmf client
 *
 *   Parameters:    client id
 *                  event
 *                  group
 *                  query num 1
 *                  query num 2
 *                  pointer to response data
 *                  len of response data
 *
 *   Return :       vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sql_msg_send( unsigned16 vmf_sql_error,vmf_client_id_t cid, unsigned8 event, 
                                   unsigned8 group, unsigned8 query_num1, unsigned8 query_num2, 
                                   unsigned8 *pdata, unsigned16 data_len)
{
    vmf_ret_t           vmf_ret = VMF_OK;
    vmf_basic_msg_t     vmf_basic_msg;
    vmf_sql_response_t  *psql_resp;

    
    /* prepare payload*/
    psql_resp = (vmf_sql_response_t*)NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = group;
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = event;
    
    psql_resp->query_num1 = query_num1;
    psql_resp->query_num2 = query_num2;
    psql_resp->sql_error = vmf_sql_error;

    /* copy sql-response to vmf message */
    if (data_len > 0)
    {
        nw_os_smemcpy(psql_resp->sql_response,VMF_SQL_MAX_RESPONSE_LEN,pdata,data_len);
    }
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = sizeof(vmf_sql_response_t) + data_len;
    
    /* send data to VMF */
    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_basic_msg);
    if(vmf_ret < 0)
    {
       VMF_TRACE_ERROR("vmf_sql_msg_send", "nw_vmf_send_basic failed with %d",vmf_ret);
    }
    
    return vmf_ret;
    
    
}


/*****************************************************************************
 *
 *   Function Name: nw_vmf_sql_map_error()
 *
 *   Description:   map sqlite error into vmf sql errors
 *
 *   Parameters:    sqlite error
 *
 *   Return :       vmf sql error
 *
 ******************************************************************************/
static unsigned16 nw_vmf_sql_map_error(int sqlite_error)
{
    unsigned16  vmf_sql_ret=SQL_ERROR;
    
    switch(sqlite_error)
    {
        case SQLITE_DONE:
            VMF_TRACE_INFO("nw_vmf_sql_map_error", "SQLITE_DONE = SQL_OK");
            vmf_sql_ret = SQL_OK;
        break;

        case SQLITE_ROW:
            VMF_TRACE_INFO("nw_vmf_sql_map_error", "SQLITE_ROW = SQL_OK");
            vmf_sql_ret = SQL_OK;
        break;
        
        case SQLITE_OK:
            VMF_TRACE_INFO("nw_vmf_sql_map_error", "SQLITE_OK = SQL_OK");
            vmf_sql_ret = SQL_OK;
        break;
        
        case SQLITE_MISUSE:
            VMF_TRACE_WARNING("nw_vmf_sql_map_error", "SQLITE_MISUSE = SQL_NOT_EXECUTED");
            vmf_sql_ret=SQL_NOT_EXECUTED;
        break;

        case SQLITE_BUSY:
            VMF_TRACE_WARNING("nw_vmf_sql_map_error", "SQLITE_BUSY = SQL_BUSY");
            vmf_sql_ret=SQL_BUSY;
        break;

        case SQLITE_NOMEM:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_NOMEM = SQL_ERR_MEM");
            vmf_sql_ret=SQL_ERR_MEM;
        break;

        case SQLITE_FULL:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_FULL = SQL_ERR_FULL");
            vmf_sql_ret=SQL_ERR_FULL;
        break;

        case SQLITE_NOTADB:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_NOTADB = SQL_ERR_DB_CORRUPT");
            vmf_sql_ret=SQL_ERR_DB_CORRUPT;
        break;

        case SQLITE_FORMAT:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_FORMAT = SQL_ERR_DB_CORRUPT");
            vmf_sql_ret=SQL_ERR_DB_CORRUPT;
        break;

        case SQLITE_CORRUPT:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_CORRUPT = SQL_ERR_DB_CORRUPT");
            vmf_sql_ret=SQL_ERR_DB_CORRUPT;
        break;

        case SQLITE_READONLY:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_READONLY = SQL_ERR_PERMISSION");
            vmf_sql_ret=SQL_ERR_PERMISSION;
        break;

        case SQLITE_AUTH:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_AUTH = SQL_ERR_PERMISSION");
            vmf_sql_ret=SQL_ERR_PERMISSION;
        break;

        case SQLITE_PERM :
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_PERM = SQL_ERR_PERMISSION");
            vmf_sql_ret=SQL_ERR_PERMISSION;
        break;
        
        case SQLITE_ERROR:
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE_ERROR = SQL_ERROR");
            vmf_sql_ret=SQL_ERROR;
        break;
        
        default:    
            VMF_TRACE_ERROR("nw_vmf_sql_map_error", "SQLITE error %d = SQL_ERROR",sqlite_error);
            vmf_sql_ret=SQL_ERROR;
        break;
    }
    
    
    return vmf_sql_ret;
}


