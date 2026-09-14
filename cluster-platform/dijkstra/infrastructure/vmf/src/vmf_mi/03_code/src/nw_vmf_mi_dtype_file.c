/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               nw_vmf_mi_file_types.c
  Description:          multi instance VMF extension 
                        implementation of ipc via file-types like:
                        supported device-types in .ini file = 
                        device_type=VMQ                  ; OpenSynergy message queue
                        device_type=CHAR                 ; character device
                        device_type=BLK                  ; block device
  Project Scope:        multi platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_MI_FILE_C

#include "nw_os_config.h"
#include "nw_config.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_client.h"
#include "nw_vmf_cfg.h"           /* vmf cfg file */

#include "nw_vmf_trace.h"
#include "nw_vmf_ini_parser.h"
#include "nw_vmf_mi.h"


/* CES2014 Linux/Android communication over OpenSynergy VMQ */
#include "vmqport_control.h"
#define VMF_MI_VMQ

/* macros */
#define RD_DELAY_MS     1

/* local data */
static unsigned8            vmf_mi_trid = 0;
static vmf_client_id_t      my_tx_cid=0;            /* globaly used tx cid */


static void *       nw_vmf_mi_dtf_vmf_server_thread(vmf_mi_section_t * p_ass_section);
static void *       nw_vmf_mi_dtf_file_server_thread(vmf_mi_section_t * p_ass_section);
static vmf_ret_t    nw_vmf_mi_dtf_create_vmf_server_thread(vmf_mi_section_t *vmf_mi_section);
static vmf_ret_t    nw_vmf_mi_dtf_create_file_server_thread(vmf_mi_section_t *vmf_mi_section);

static int          nw_mi_open_device       (const char *device_name, vmf_mi_num_dtype dtype,int access);
static int          nw_mi_close_device      (int fd, vmf_mi_num_dtype dtype);
static int          nw_mi_read_device       (int fd, vmf_mi_num_dtype dtype,unsigned8 *buffer,unsigned16 len,unsigned16 timeout);
static int          nw_mi_write_device      (int fd, vmf_mi_num_dtype dtype,unsigned8 *buffer,unsigned16 len);

static int          nw_mi_read_tr_message   (int fd, vmf_mi_num_dtype dtype,unsigned8 comp_type,nw_vmf_mi_transfer_t *p_tr_msg,unsigned16 timeout);
static int          nw_mi_read_tr_message_nc(int fd, vmf_mi_num_dtype dtype,nw_vmf_mi_transfer_t *p_tr_msg,unsigned16 timeout);
static int          nw_mi_read_tr_message_co(int fd, vmf_mi_num_dtype dtype,nw_vmf_mi_transfer_v2_t *p_tr_msg,unsigned16 timeout);

static int          nw_mi_write_tr_message   (int fd, vmf_mi_num_dtype dtype, unsigned8 cotype, nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len);
static int          nw_mi_write_tr_message_co(int fd, vmf_mi_num_dtype dtype, unsigned8 cotype, nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len);
static int          nw_mi_write_tr_message_nc(int fd, vmf_mi_num_dtype dtype, nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len);

  
  
 /**************************************************************************//**
 *
 *   get file-device related values from ini file for a section
 *
 *   \param[in]     arc      
 *   \param[in]     arv      
 *   \return        0 if ok else -1
 *
 ******************************************************************************/
int nw_vmf_mi_dtype_file_readinit(FILE * stream, vmf_mi_section_t *vmf_mi_sections,int section_num,char *p_section_name)
{
    int ret_val=-1;
    int val_len = 0;
    char val[255];
    
    /* argument check */
    if ((NULL != stream) && (NULL != vmf_mi_sections) && (NULL != p_section_name))
    {
        /* read the local device name */
        val_len = ini_parser_get_val(stream,p_section_name,KEY_LOCAL_DEVICE,val,sizeof(val));
        if (val_len > 0)
        {
            nw_os_sstrncpy(vmf_mi_sections[section_num].local_device, val, sizeof(vmf_mi_sections[section_num].local_device));
            VMF_MI_INFO("section[%s] - local_device='%s'",p_section_name,vmf_mi_sections[section_num].local_device);
        }
        else
        {
            vmf_mi_sections[section_num].local_device[0]=0;
        }

        /* read the remote device name */
        val_len = ini_parser_get_val(stream,p_section_name,KEY_REMOTE_DEVICE,val,sizeof(val));
        if (val_len > 0)
        {
            nw_os_sstrncpy(vmf_mi_sections[section_num].remote_device, val, sizeof(vmf_mi_sections[section_num].remote_device));
            VMF_MI_INFO("section[%s] - remote_device='%s'",p_section_name,vmf_mi_sections[section_num].remote_device);
        }
        else
        {
            vmf_mi_sections[section_num].remote_device[0]=0;
        }
        
        
        /* test plausibility */
        /* check if source or dest device was set */
        if ((vmf_mi_sections[section_num].local_device[0]==0) && (vmf_mi_sections[section_num].remote_device[0]==0))
        {
            /* ignore section */
            ret_val = -1;
        }
        else
        {
            ret_val = 0;
        }
    }
    
    return ret_val;    
}




/**************************************************************************//**
 *
 *   create the local file-server thread
 *
 *   \param         pointer to associated section
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_mi_dtf_create_vmf_server_thread(vmf_mi_section_t *vmf_mi_section)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;
    vmf_ret_t ret_val=VMF_ERROR;

    VMF_MI_INFO("nw_vmf_mi_dtf_create_vmf_server_thread()");
    
    /* argument check */
    if (NULL == vmf_mi_section)
    {
        VMF_MI_ERROR("nw_vmf_mi_dtf_create_vmf_server_thread() - NULLPOINTER");
        ret_val = (VMF_ERR_NULL_POINTER);
    }
    else
    {
        /* set thread stack */
        (void) pthread_attr_init( &attr );
        if ( pthread_attr_setstacksize(&attr, VMF_MI_STACK_SIZE ) != 0 )
        {
            VMF_MI_ERROR("nw_vmf_mi_dtf_create_vmf_server_thread() - pthread_attr_setstacksize() failed");
        }

        (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
        iRet = pthread_create (&th, &attr, (void * (*)(void *))nw_vmf_mi_dtf_vmf_server_thread, (void *)vmf_mi_section);
        (void) pthread_attr_destroy(&attr);
        if (iRet)
        {
            VMF_MI_ERROR("nw_vmf_mi_dtf_create_vmf_server_thread() error! errno = %d",iRet);
        }
        else
        {
            ret_val = VMF_OK;
            
            nw_os_set_thread_name(th,"vmf-mi_tdt_vmf_server");
            VMF_MI_INFO("nw_vmf_mi_dtf_create_vmf_server_thread() OK");
        }
    }

    return ret_val;
}

/**************************************************************************//**
 *
 *   create the local file-server thread
 *
 *   \param         pointer to associated section
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_mi_dtf_create_file_server_thread(vmf_mi_section_t *vmf_mi_section)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;
    vmf_ret_t ret_val=VMF_ERROR;

    VMF_MI_INFO("nw_vmf_mi_dtf_create_file_server_thread()");
    
    /* argument check */
    if (NULL == vmf_mi_section)
    {
        VMF_MI_ERROR("nw_vmf_mi_dtf_create_file_server_thread() - NULLPOINTER");
        ret_val = (VMF_ERR_NULL_POINTER);
    }
    else
    {
        /* set thread stack */
        (void) pthread_attr_init( &attr );
        if ( pthread_attr_setstacksize(&attr, VMF_MI_STACK_SIZE ) != 0 )
        {
            VMF_MI_ERROR("nw_vmf_mi_dtf_create_file_server_thread() - pthread_attr_setstacksize() failed");
        }

        (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
        iRet = pthread_create (&th, &attr, (void * (*)(void *))nw_vmf_mi_dtf_file_server_thread, (void *)vmf_mi_section);
        (void) pthread_attr_destroy(&attr);
        if (iRet)
        {
            VMF_MI_ERROR("nw_vmf_mi_dtf_create_file_server_thread() error! errno = %d",iRet);
        }
        else
        {
            ret_val = VMF_OK;
            
            nw_os_set_thread_name(th,"vmf-mi_file_server");
            VMF_MI_INFO("nw_vmf_mi_dtf_create_file_server_thread() OK");
        }
    }

    return ret_val;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_vmf_server_thread()
 *   Description:   vmf server thread for MI device-type file
 *                  this thread will receive vmf messages and will forward them via given-device   
 *
 *   \param         pointer to associated section
 *   \return        void *
 *
 ******************************************************************************/
static void * nw_vmf_mi_dtf_vmf_server_thread(vmf_mi_section_t * p_ass_section)
{
    vmf_ret_t           ret_val=VMF_ERROR;
    vmf_ret_t           vmf_rcv_len=0;
    vmf_client_id_t     my_rx_id=0;
    unsigned8           my_section=0;
    vmf_mi_num_dtype    dtype;
    int                 fd=-1;
    char                this_thread_name[30]={0};;
    char                this_device[VMF_MI_MAX_DEVICE_LEN]={0};
    unsigned8           comptype=0;
    bool                allow_backfiring = false;
    
    VMF_MI_INFO("nw_vmf_mi_dtf_vmf_server_thread");

    nw_assert(p_ass_section != NULL);
    if (NULL != p_ass_section)
    {
        /* create and register thread-name */
        (void) snprintf(this_thread_name,sizeof(this_thread_name),"vmfMiVmf-%s",p_ass_section->section_name);
        nw_os_set_current_thread_name(this_thread_name);
        
        /* get the remote device name */
        nw_os_sstrncpy(this_device, p_ass_section->remote_device, sizeof(this_device));
        dtype = p_ass_section->num_dtype;
        comptype =  p_ass_section->comp_type;
        /* Register at VMF Tracer */
        if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
        {
             VMF_MI_ERROR("CANNOT CONNECT TO VMF TRACER!!!");
        }

        my_section = p_ass_section->this_section;
        if (p_ass_section->allow_backfire > 0)
        {
            /* allow backfiring */
            allow_backfiring = true;
        }
        
        VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"w_vmf_mi_vmf_server_thread() created\n");
        
        while(true)
        {
            /* open device */
            fd = nw_mi_open_device(this_device, dtype, O_WRONLY);
            
            if (-1 == fd)
            {
                /* open failed */
                ret_val = VMF_ERROR;
            }
            else if (0 == my_rx_id) /* only connect once */
            {
                VMF_MI_INFO3("nw_vmf_mi_dtf_vmf_server_thread open '%s' OK",this_device);

                /* connect to vmf server and register msg groups  */
                ret_val = nw_vmf_mi_vmf_connect(p_ass_section);
                if (ret_val <= 0)
                {
                    /* invalid cid */
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_dtf_vmf_server_thread vmf_connect() failed");
                }
                else
                {
                    my_rx_id = ret_val;
                    if (0 == my_tx_cid)
                    {
                        my_tx_cid = my_rx_id;       /* this cid is also used for sending to VMF */
                    }
                    VMF_MI_INFO3("nw_vmf_mi_dtf_vmf_server_thread - connected to VMF - cid=%d",my_tx_cid);
                }
            }
            else
            {
                VMF_MI_INFO3("nw_vmf_mi_dtf_vmf_server_thread open '%s' OK",this_device);
                /* already connected to VMF */
            }
            
            /* receive VMF messages and forward them to the remote-device-file */
            while(ret_val >= 0)
            {
                nw_vmf_mi_transfer_t  transfer_buffer={0};   

    //            VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_10,"waiting for vmf message");
                ret_val = (vmf_ret_t)nw_vmf_timed_receive(my_rx_id, (vmf_msg_t *)&(transfer_buffer.vmf_msg),sizeof(transfer_buffer.vmf_msg),VMF_MI_KEEP_ALIVE_TIME); 
                if (ret_val > 0)
                {
                    VMF_MI_INFO3("got vmf message with %d bytes",ret_val);
                    /* only forward message if no backfireing */
                    if ((transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id != my_section) || (false == allow_backfiring))
                    {
                        /* ret_val equals number of bytes to send */
                        vmf_rcv_len = ret_val;
                        
                        VMF_MI_INFO3("send %d bytes to device %s",vmf_rcv_len,this_device);
                        VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,NW_VMF_MI_GET_TRANSFER_MSG_LEN(transfer_buffer.vmf_len),(unsigned8 *)&transfer_buffer);

                        /* send vmf message to remote device */
                        ret_val = nw_mi_write_tr_message(fd, dtype, comptype,&transfer_buffer,vmf_rcv_len);
                        if (ret_val <= 0)
                        {
                            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_receive returned %d",ret_val);
                            nw_sleep_ms(WAIT_SOME_TIME);
                        }
                    }
                    else
                    {
                        VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_19,"prevent backfiring - stored section = %d, mysection = %d",transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id,my_section);
                        VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,transfer_buffer.vmf_len,(unsigned8 *)&transfer_buffer);
                    }
                }
                else if (ret_val == 0)
                {
                    /* timeout */
                    /* send keep alive */
                }
                else
                {
                    /* vmf error */
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_receive returned %d",ret_val);
                    nw_sleep_ms(WAIT_SOME_TIME);
                }
            }

            /* close all used recources */
    #if 0
            if (my_rx_id > 0)
            {
                /* close vmf connection */
                (void)nw_vmf_mi_vmf_disconnect(my_rx_id);
                my_rx_id = 0;
            }
    #endif        
            if (fd != -1)
            {
                VMF_MI_INFO3("nw_vmf_mi_dtf_vmf_server_thread - close device %s -fd =%d",this_device,fd);
                (void) nw_mi_close_device(fd,dtype);
            }
            nw_sleep_ms(WAIT_SOME_TIME);
        }
    }
    else
    {
        VMF_MI_ERROR("p_ass_section=NULL");
    }

    return NULL;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_dtf_file_server_thread()
 *   Description:   file server thread for MI device-type file
 *                  this thread will create and read its local fifo and will
 *                  receive messages from the remote server 
 *                  and will forward them to vmf  
 *
 *   \param         pointer to associated section
 *   \return        void *
 *
 ******************************************************************************/
static void * nw_vmf_mi_dtf_file_server_thread(vmf_mi_section_t * p_ass_section)
{
    vmf_ret_t           ret_val=VMF_OK;
    unsigned8           my_section=0;
    int                 fd=-1;
    vmf_mi_num_dtype    dtype;
    char                this_thread_name[30]={0};;
    char                this_device[VMF_MI_MAX_DEVICE_LEN]={0};
    unsigned8           comptype=0;
    
    VMF_MI_INFO("nw_vmf_mi_dtf_file_server_thread");
    nw_assert(p_ass_section != NULL);

    if (NULL != p_ass_section)
    {
        /* create and register thread-name */
        (void) snprintf(this_thread_name,sizeof(this_thread_name),"vmfMiVmf-%s",p_ass_section->section_name);
        nw_os_set_current_thread_name(this_thread_name);
        
        /* get the local device name */
        nw_os_sstrncpy(this_device, p_ass_section->local_device, sizeof(this_device));
        dtype = p_ass_section->num_dtype;
        
        /* Register at VMF Tracer */
        if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
        {
             VMF_MI_ERROR("CANNOT CONNECT TO VMF TRACER!!!");
        }
        
        my_section = p_ass_section->this_section;
        comptype =  p_ass_section->comp_type;
        VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_server_thread() created\n");
        
        while(true)
        {
            /* open device */
            fd = nw_mi_open_device(this_device, dtype, O_RDONLY| O_CREAT);
            if (-1 == fd)
            {
                /* open failed */
                VMF_MI_INFO2("nw_vmf_mi_dtf_file_server_thread - error opening device %s -fd =%d",this_device,fd);
                ret_val = VMF_ERROR;
            }
            else if (0 == my_tx_cid) /* only connect once */
            {
                
                VMF_MI_INFO3("nw_vmf_mi_dtf_file_server_thread open %s OK",this_device);

                /* connect to vmf server and register msg groups  */
                VMF_MI_INFO2("nw_vmf_mi_dtf_file_server_thread connect to VMF");
                ret_val = nw_vmf_mi_vmf_connect(p_ass_section);
                if (ret_val <= 0)
                {
                    /* invalid cid */
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_dtf_file_server_thread vmf_connect() failed");
                }
                else
                {
                    VMF_MI_INFO2("nw_vmf_mi_dtf_file_server_thread - connected to VMF - cid=%d",ret_val);
                    my_tx_cid = ret_val;
                }
            }
            else
            {
                VMF_MI_INFO3("nw_vmf_mi_dtf_file_server_thread open '%s' OK",this_device);
                VMF_MI_INFO3("nw_vmf_mi_dtf_file_server_thread - already connected to VMF - cid=%d",my_tx_cid);
                /* already connected to VMF */
            }
            
            /* receive device message and forward it to the remote-device */
            while(ret_val >= 0)
            {
                nw_vmf_mi_transfer_t  transfer_buffer;   

                VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_10,"waiting for file message");
                ret_val = (vmf_ret_t)nw_mi_read_tr_message(fd, p_ass_section->num_dtype,comptype,&transfer_buffer,0); 
                if (ret_val > 0)
                {
                    VMF_MI_INFO3("got %d bytes from %s",transfer_buffer.vmf_len,this_device);
                    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"got message from device %s with %d bytes",this_device,ret_val);
                    /* only forward message if no backfireing */
                    if (transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id != my_section)
                    {
                        transfer_buffer.vmf_len = ret_val;
                        VMF_MI_INFO3("send %d bytes to vmf",transfer_buffer.vmf_len);
                        VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,transfer_buffer.vmf_len,(unsigned8 *)&transfer_buffer);

                        /* send vmf message */
                        ret_val = vmf_mi_vmf_sender(my_tx_cid,(vmf_msg_t*)&(transfer_buffer.vmf_msg),transfer_buffer.vmf_len,my_section);
                        if (ret_val != VMF_OK)
                        {
                            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf send failed -- return value = %d",ret_val);
                            nw_con_HexDump("vmf_mi_send error:",(unsigned8*)&(transfer_buffer.vmf_msg),transfer_buffer.vmf_len);
                        }
                    }
                    else
                    {
                        VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_19,"prevent backfiring - stored section = %d, mysection = %d",transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id,my_section);
                        VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,transfer_buffer.vmf_len,(unsigned8 *)&transfer_buffer);
                    }
                }
                else if (ret_val == 0)
                {
                    /* timeout */
                    VMF_MI_INFO("nw_vmf_mi_dtf_file_server_thread - nw_mi_read_device returned 0");
                    nw_sleep_ms(WAIT_SOME_TIME);
                }
                else
                {
                    /* error */
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_mi_read_device returned %d",ret_val);
                    nw_sleep_ms(WAIT_SOME_TIME);
                }
            }

            /* close all used recources */
    #if 0
            if (my_tx_cid > 0)
            {
                /* close vmf connection */
                VMF_MI_INFO("nw_vmf_mi_dtf_file_server_thread - disconnected from VMF- cid=%d",my_tx_cid);
                (void)nw_vmf_mi_vmf_disconnect(my_tx_cid);
                my_tx_cid = 0;
            }
    #endif        
            if (fd != -1)
            {
                VMF_MI_INFO3("nw_vmf_mi_dtf_file_server_thread - close device %s -fd =%d",this_device,fd);
                (void) nw_mi_close_device(fd,dtype);
            }
            nw_sleep_ms(WAIT_SOME_TIME);
        }
    }
    else
    {
        VMF_MI_ERROR("p_ass_section=NULL");
    }
    
    return NULL;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_start_dtf_instance(vmf_mi_section_t *vmf_mi_sections)
 *
 *   Description:   start a new file device-type instance
 *
 *   \param         pointer to all sections, section number
 *   \return        void
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_start_dtf_instance(vmf_mi_section_t *vmf_mi_sections,int section_num)
{
    vmf_ret_t vmf_ret=VMF_ERROR;
    
    VMF_MI_INFO("nw_vmf_mi_start_dtf_instance() - section_name = %s",vmf_mi_sections[section_num].section_name);
    if (vmf_mi_sections[section_num].remote_device[0] != 0)
    {
        /* start a vmf server thread for this section  */
        VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"create vmf-server thread %s",vmf_mi_sections[section_num].section_name);
        VMF_MI_INFO("nw_vmf_mi_start_dtf_instance() - remote_device = %s",vmf_mi_sections[section_num].remote_device);
        vmf_ret=nw_vmf_mi_dtf_create_vmf_server_thread(&vmf_mi_sections[section_num]);
    }

    nw_sleep_ms(100);
    if (vmf_mi_sections[section_num].local_device[0] != 0)
    {
        /* start a file server thread */
        VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"create file-server thread %s",vmf_mi_sections[section_num].section_name);
        VMF_MI_INFO("nw_vmf_mi_start_dtf_instance() - local_device = %s",vmf_mi_sections[section_num].local_device);
        vmf_ret=nw_vmf_mi_dtf_create_file_server_thread(&vmf_mi_sections[section_num]);
    }

    return vmf_ret;
}

 
/**************************************************************************//**
 *
 *   Function Name: nw_mi_open_device()
 *
 *   Description:   open a device
 *
 *   \param         device name[input]
 *   \param         device type[input]
 *   \return        fd if OK else -1
 *
 ******************************************************************************/
static int nw_mi_open_device(const char *device_name, vmf_mi_num_dtype dtype,int access)
{
    int fd=-1;
        
    switch(dtype)
    {
        case NDT_FIFO:
        {
            if (access & O_CREAT)
            {
                mode_t oldmask;
                
                /* try to delete old FIFO before creating a new one */
#ifdef NW_REMOVE
                (void)NW_REMOVE(device_name);
#endif                
                /* create the fifo */
                oldmask = umask(S_IRWXU);
                if (mkfifo(device_name, S_IRWXU) != 0)
                {
                    VMF_MI_ERROR("nw_mi_open_device mkfifo(%s) failed",device_name);
                }
                (void)umask(oldmask);
            }
            fd = open(device_name,access);
        }
        break;
            
        case NDT_BLK:
            /* no break */
        case NDT_CHAR:
        {
#ifdef NW_REMOVE
            (void)NW_REMOVE(device_name);
#endif
            fd = open(device_name,access);
#if 0
            if (access == O_RDONLY)
            {
                VMF_MI_INFO("nw_mi_open_device O_RDONLY %s - fs=%d, access=%d",device_name,fd,access);
            }
            else if (access == O_WRONLY)
            {
                VMF_MI_INFO("nw_mi_open_device O_WRONLY %s - fs=%d, access=%d",device_name,fd,access);
            }
            else if (access == O_CREAT)
            {
                VMF_MI_INFO("nw_mi_open_device O_CREAT %s - fs=%d, access=%d",device_name,fd,access);
            }
#endif
        }
        break;
            
#ifndef INTEGRITY
        case NDT_VMQ:
            #ifdef VMF_MI_VMQ
            fd = open_vmqportdev_by_portname(device_name, access);
            #endif
        break;
#endif            

        case NDT_TCP:
            /* no break */
        default:
            /* invalid type */
            fd = -1;
        break;
            
    }

    return fd;
}

/**************************************************************************//**
 *
 *   Function Name: nw_mi_close_device()
 *
 *   Description:   close a device
 *
 *   \param         fd
 *   \param         device type[input]
 *   \return        0 OK else -1
 *
 ******************************************************************************/
static int nw_mi_close_device(int fd, vmf_mi_num_dtype dtype)
{
    int retval=-1;
    
    if (-1 != fd)
    {
        switch(dtype)
        {
            case NDT_FIFO:
            /* no break */
            case NDT_BLK:
            /* no break */
            case NDT_CHAR:
            {
                retval = close(fd);
            }
                break;
                
            case NDT_VMQ:
                #ifdef VMF_MI_VMQ
                retval= close(fd);
                #endif
            break;
                
            case NDT_TCP:
            /* no break */
            default:
            /* invalid type */
            break;
        }
    }
                
    return retval;
}



/**************************************************************************//**
 *
 *   Function Name: nw_mi_write_device()
 *
 *   Description:   write message to a device 
 *
 *   \param         device name[input]
 *   \param         device type[input]
 *   \param         buffer to vmf message[output]
 *   \param         size of vmf buffer[input]
 *   \param         timeout[output]
 *   \return        number of read bytes
 *
 ******************************************************************************/
static int nw_mi_write_device(int fd, vmf_mi_num_dtype dtype,unsigned8 *buffer, unsigned16 len)
{
    int retval=0;;

    UNUSED_PARAM(dtype);

    retval = write(fd, buffer, len);
    return retval;
}




/**************************************************************************//**
 *
 *   Function Name: nw_mi_read_device()
 *
 *   Description:   read message from a device with timeout
 *                  read exactly the number of "len" bytes
 *   \param         device name[input]
 *   \param         device type[input]
 *   \param         buffer to vmf message[output]
 *   \param         size of vmf buffer[input]
 *   \param         timeout[output]
 *   \return        number of read bytes or 0 in case of timeout or error
 *
 ******************************************************************************/
static int nw_mi_read_device(int fd, vmf_mi_num_dtype dtype,unsigned8 *buffer,unsigned16 len,unsigned16 timeout)
{       
    int retval=0;
    int cu_to=0;
    int cu_len=0;

    UNUSED_PARAM(dtype);

    while (cu_len < len)
    {
        retval = read(fd, &buffer[cu_len], len);
        cu_len += retval;
        if (0 == retval)
        {
            nw_sleep_ms(RD_DELAY_MS);
            cu_to +=RD_DELAY_MS;
            if ((cu_to > timeout) && (timeout > 0))
            {
                cu_len = 0;
                break;
            }
        }
        else if (retval < 0)
        {
            cu_len = retval;
            nw_sleep_ms(RD_DELAY_MS);
            VMF_MI_ERROR("nw_mi_read_device() read returned=%d",retval);
        }
    }
    VMF_MI_INFO("nw_mi_read_device() done cu_len=%d",cu_len);
    
    return cu_len;
}



/**************************************************************************//**
 *
 *   Function Name: nw_mi_read_tr_message()
 *
 *   Description:   read a transfer message
 *                  the call will only return with a full valid message or timeout
 *   \param         device name[input]
 *   \param         device type[input]
 *   \param         pointer to transfer message[output]
 *   \param         size of vmf buffer[input]
 *   \param         timeout[output]
 *   \return        length of the transfer-msg or 0 if timeout or <0 if error
 *
 ******************************************************************************/
static int nw_mi_read_tr_message(int fd, vmf_mi_num_dtype dtype,unsigned8 comp_type,nw_vmf_mi_transfer_t *p_tr_msg,unsigned16 timeout)
{
    int retval=0;
    
    if (MI_NO_COMP == comp_type)
    {
        retval = nw_mi_read_tr_message_nc(fd, dtype, p_tr_msg, timeout);
    }
    else
    {
        nw_vmf_mi_transfer_v2_t vmf_mi_tr_v2;
        retval =  nw_mi_read_tr_message_co(fd, dtype, &vmf_mi_tr_v2, timeout);
    }
    return retval;
}


/**************************************************************************//**
 *
 *   Function Name: nw_mi_read_tr_message_nc()
 *
 *   Description:   read a not compressed transfer message
 *                  the call will only return with a full valid message or timeout
 *   \param         device name[input]
 *   \param         device type[input]
 *   \param         pointer to transfer message[output]
 *   \param         size of vmf buffer[input]
 *   \param         timeout[output]
 *   \return        length of the transfer-msg or 0 if timeout or <0 if error
 *
 ******************************************************************************/
static int nw_mi_read_tr_message_nc(int fd, vmf_mi_num_dtype dtype,nw_vmf_mi_transfer_t *p_tr_msg,unsigned16 timeout)
{
    int total_len=0;
    int num_bytes;
    int cu_to = 0;
    
    VMF_MI_INFO("nw_mi_read_tr_message() start");
    
    if (NULL != p_tr_msg)
    {
        /* read vmq message */
        if (NDT_VMQ == dtype)
        {
            while(total_len <=0)
            {
                total_len = read(fd, p_tr_msg, sizeof(nw_vmf_mi_transfer_t));
                /* handle timeout */
                if (total_len <=0)
                {
                    cu_to +=RD_DELAY_MS;
                    if ((cu_to > timeout) && (timeout > 0))
                    {
                        total_len=0;
                        break;
                    }
                    nw_sleep_ms(RD_DELAY_MS);
                }
            }
        }
        else
        {
            /* read non vmq message */
            /* wait for sync */
            while(true)
            {
                /* sync token 0 */
                num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->token0), 1, timeout);
                if (num_bytes < 1)
                {
                    nw_sleep_ms(WAIT_SOME_TIME);
                    continue;
                }
                if (VALID_TOKEN0 != p_tr_msg->token0)
                {
                    continue;
                }
                total_len = 1;
                
                /* sync token 1 */
                num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->token1), 1, timeout);
                if (num_bytes < 1)
                {
                    nw_sleep_ms(WAIT_SOME_TIME);
                    continue;
                }
                if (VALID_TOKEN1 != p_tr_msg->token1)
                {
                    continue;
                }
                else
                {
                    total_len++;
                    break;
                }
            }
            
            /* read vmf msg-len */
            p_tr_msg->vmf_len = 0;
            num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->vmf_len), sizeof(p_tr_msg->vmf_len), timeout);
            
            if (num_bytes == sizeof(p_tr_msg->vmf_len))
            {
                total_len+=num_bytes;

                if (p_tr_msg->vmf_len <= sizeof(p_tr_msg->vmf_msg))
                {
                    /* read vmf msg */
                    num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->vmf_msg), p_tr_msg->vmf_len, timeout);
                    total_len+=num_bytes;
                }
                else
                {
                    total_len = num_bytes;
                }
            }
            else
            {
                total_len = num_bytes;
            }
        }
        VMF_MI_INFO("nw_mi_read_tr_message()got vmf message with len %d",p_tr_msg->vmf_len);
    }
    else
    {
        VMF_MI_ERROR("nw_mi_read_tr_message() NULL pointer");
    }
            
    return total_len;
}


/**************************************************************************//**
 *
 *   Function Name: nw_mi_read_tr_message_co()
 *
 *   Description:   read a compressed transfer message
 *                  the call will only return with a full valid message or timeout
 *   \param         device name[input]
 *   \param         device type[input]
 *   \param         pointer to transfer message[output]
 *   \param         size of vmf buffer[input]
 *   \param         timeout[output]
 *   \return        length of the transfer-msg or 0 if timeout or <0 if error
 *
 ******************************************************************************/
static int nw_mi_read_tr_message_co(int fd, vmf_mi_num_dtype dtype,nw_vmf_mi_transfer_v2_t *p_tr_msg,unsigned16 timeout)
{
    int total_len=0;
    int num_bytes;
    
    VMF_MI_INFO("nw_mi_read_tr_message_co() start");
    
    if (NULL != p_tr_msg)
    {
        /* wait for sync */
        while(true)
        {
            /* sync token 0 */
            num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->token0), 1, timeout);
            if (num_bytes < 1)
            {
                nw_sleep_ms(WAIT_SOME_TIME);
                continue;
            }
            if (VALID_TOKEN0 != p_tr_msg->token0)
            {
                continue;
            }
            total_len = 1;
            
            /* sync token 1 */
            num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->token1), 1, timeout);
            if (num_bytes < 1)
            {
                nw_sleep_ms(WAIT_SOME_TIME);
                continue;
            }
            if (VALID_TOKEN1 != p_tr_msg->token1)
            {
                continue;
            }
            else
            {
                total_len++;
                break;
            }
        }
        
        /* read remaining header */
        
        /* read vmf msg-len */
        p_tr_msg->vmf_len = 0;
        num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->version_l), VMF_MI_HEADER_LEN_V2 - total_len, timeout);
        
        if (num_bytes == VMF_MI_HEADER_LEN_V2 - total_len)
        {
            total_len+=num_bytes;
            
            if (p_tr_msg->vmf_len <= sizeof(p_tr_msg->vmf_msg))
            {
                /* read vmf msg */
                num_bytes = nw_mi_read_device(fd, dtype, (unsigned8 *)&(p_tr_msg->vmf_msg), p_tr_msg->vmf_len, timeout);
                total_len+=num_bytes;
            }
            else
            {
                total_len = num_bytes;
            }
        }
        else
        {
            total_len = num_bytes;
        }
        
        VMF_MI_INFO("nw_mi_read_tr_message_co() got vmf message with len %d",p_tr_msg->vmf_len);
    }
    else
    {
        VMF_MI_ERROR("nw_mi_read_tr_message_co() NULL pointer");
    }
        
    return total_len;
}





/**************************************************************************//**
 *
 *   Function Name: nw_mi_write_tr_message()
 *
 *   Description:   write a message to the selected device 
 *                  
 *   \param         file handle[input]
 *   \param         device type[input]
 *   \param         buffer to vmf message[output]
 *   \param         size of vmf buffer[input]
 *
 *   \return        length of written message
 *
 ******************************************************************************/
static int nw_mi_write_tr_message(int fd, vmf_mi_num_dtype dtype, unsigned8 cotype, nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len)
{
    int retval=0;
    
    if (MI_NO_COMP == cotype)
    {
        retval = nw_mi_write_tr_message_nc(fd, dtype, p_tr_msg, vmf_len);
    }
    else
    {
        retval = nw_mi_write_tr_message_co(fd, dtype, cotype, p_tr_msg, vmf_len);
    }
    return retval;
}


/**************************************************************************//**
 *
 *   Function Name: nw_mi_write_tr_message_nc()
 *
 *   Description:   write a uncompressed message to the selected device
 *                  
 *   \param         file handle[input]
 *   \param         device type[input]
 *   \param         buffer to vmf message[output]
 *   \param         size of vmf buffer[input]
 *
 *   \return        length of written message
 *
 ******************************************************************************/
static int nw_mi_write_tr_message_nc(int fd, vmf_mi_num_dtype dtype,nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len)
{
    int wr_len=0;

    p_tr_msg->token0=VALID_TOKEN0;
    p_tr_msg->token1=VALID_TOKEN1;
    p_tr_msg->vmf_len=vmf_len;
    
    wr_len = nw_mi_write_device(fd, dtype,(unsigned8*)p_tr_msg,  NW_VMF_MI_GET_TRANSFER_MSG_LEN(vmf_len));
    return wr_len;
}



/**************************************************************************//**
 *
 *   Function Name: nw_mi_write_tr_message_co()
 *
 *   Description:   write a compressed message to the selected device
 *                  
 *   \param         file handle[input]
 *   \param         device type[input]
 *   \param         compression type[input]
 *   \param         buffer to vmf message[input]
 *   \return        size of written message
 *
 ******************************************************************************/
static int nw_mi_write_tr_message_co(int fd, vmf_mi_num_dtype dtype, unsigned8 cotype, nw_vmf_mi_transfer_t *p_tr_msg, int vmf_len)
{
    int wr_len=0;
	nw_vmf_mi_transfer_v2_t tr_msg = {0};
	unsigned16 comp_len;

	if(vmf_len < sizeof(tr_msg.vmf_msg))
    {
        comp_len = nw_mi_compress(cotype, (unsigned8*)&(p_tr_msg->vmf_msg),vmf_len,(unsigned8*)&(tr_msg.vmf_msg),sizeof(tr_msg.vmf_msg));
        
        if ((0 == comp_len) || (comp_len >= (vmf_len - 1u)))
        {
            /* use uncompressed message */
            cotype = MI_NO_COMP;
            tr_msg.vmf_len=vmf_len;
            nw_os_smemcpy((unsigned8*)&(p_tr_msg->vmf_msg),vmf_len,(unsigned8*)&(tr_msg.vmf_msg),sizeof(tr_msg.vmf_msg));
        }
        else
        {
            /* use compressed message */
            tr_msg.vmf_len=comp_len;
            /* message is already in tr_msg.vmf_msg */
        }
        
        tr_msg.token0    = VALID_TOKEN0;
        tr_msg.token1    = VALID_TOKEN1;
    
        tr_msg.comp      = cotype;
        tr_msg.version_l = VMF_MI_MINOR_NUMBER;
        tr_msg.version_h = VMF_MI_MAJOR_NUMBER;
		
		wr_len = nw_mi_write_device(fd, dtype,(unsigned8*)&tr_msg,  NW_VMF_MI_GET_TRANSFER_CO_MSG_LEN(vmf_len));
    }
    //wr_len = nw_mi_write_device(fd, dtype,(unsigned8*)p_tr_msg,  NW_VMF_MI_GET_TRANSFER_CO_MSG_LEN(vmf_len));
    return wr_len;
}



