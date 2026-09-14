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

  Module:               vmf_logger.c
  Description:          vmf logger

  Project Scope:        VMF

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/


#define VMF_LOGGER_C__

#include "nw_vmf_cfg.h"
#include "nw_vmf.h"
#include "nw_vmf_trace_server.h"
#include "nw_vmf_logger.h"
#include "nw_vmf_ini_parser.h"
#include "nw_vmf_debug.h"

/* macros */

#define VMF_LOGGER_ERROR_PRINT(args...)     (void)fprintf(ERROR_CHANNEL,"error:");(void)fprintf(ERROR_CHANNEL,"%s() - ",(char *)__FUNCTION__);(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");delay(100);
#define VMF_LOGGER_INFO_PRINT(args...)      // (void)fprintf(ERROR_CHANNEL,"info :");(void)fprintf(ERROR_CHANNEL,"%s() - ",(char *)__FUNCTION__);(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");delay(100);
#ifndef FOREVER
#define FOREVER true
#endif
#define VMF_REC_TIMOUT                      1000        /* vmf reception timeout in ms */
#define VMF_USB_TRACE_VERSION_L             (0x02)
#define VMF_USB_TRACE_VERSION_H             (0x00)
#define VMF_MI_USB_ERROR_WAIT               (10)         /* time in ms - to prevent deadlock */
// #define HEX_DUMP


/* global data */
static char                     filepath[100]={0};
static unsigned32               vmf_log_written_msgs2cache=0;
static unsigned32               vmf_log_written_msgs2usb=0;
static unsigned32               current_write_buffer_len =0;    /* number of bytes in current write cache */
static  unsigned8               *p_usb_write_buffer=NULL;       /* contains the buffer that is the current write cache */
static unsigned8                *p_usb_write_buffer0=NULL;
static unsigned8                *p_usb_write_buffer1=NULL;
static unsigned8                *p_usb_flush_buffer=NULL;       /* contains the buffer that is currently written to he USB stick */
static unsigned32               vmf_usb_flash_lost_messages=0;
static unsigned32               current_flush_buffer_len=0;    /* number of bytes of the current flush buffer */
static pthread_mutex_t          vmf_log_write_mux = PTHREAD_MUTEX_INITIALIZER;
static int                      curr_file_ix=0;
static unsigned8                vmf_trid=0;
static bool                     vmf_log_init_module_done = false;
static unsigned32               vmf_log_written_msgs2usb_errors=0;
static unsigned32               ftotal_time=0;
static FILE                     *fp=NULL;
static FILE                     *fp_ini=NULL;
static vmf_client_id_t          vmf_client_id=0;
static unsigned32               last_file_write_ms=0;


/* external data */
vmf_logger_info_t               vmf_logger_info;
extern bool                     verbose;

/* local functions */
static void     *nw_vmf_logger_thread(void *pNoArg);
static void     *nw_vmf_logger_write_thread(void *pNoArg);
static vmf_ret_t vmf_logger_write_create_thread(void);
static bool      vmf_log_write_debug_cache(unsigned8 *data, int len);
static int       vmf_memcpy_s (void *dest_buffer, size_t dest_buffer_len, void *src_buffer, size_t src_data_len);
static FILE     *vmf_log_open_debug_file_internal(char *filename);
static void      vmf_log_close_debug_file_internal(FILE *fp);
static void      vmf_log_init_usb_message_header(vmf_usb_trace_header_t *hd);
static char     *vmf_log_get_current_datetime(void);
static bool      vmf_log_init_module(void);
static bool      vmf_log_flush_debug_cache_internal(unsigned8 *data, int len, char *prefix);
static bool      vmf_log_write_logfileindex_ini(char * filename, unsigned16 current_ix);
static bool      vmf_log_trace_send_command(unsigned8 group, unsigned8 event, unsigned8 *data,unsigned16 len);
static bool      vmf_log_read_inifile(vmf_client_id_t cid);
static void      vmf_log_wait_for_inifile(vmf_client_id_t cid);
static vmf_ret_t vmf_log_send_global_filter_severity(vmf_client_id_t cid, unsigned8 severity);
static vmf_ret_t vmf_log_send_filter_severity(vmf_client_id_t cid, unsigned8 trid, unsigned8 severity);
static vmf_ret_t vmf_log_unpack_and_write_msg(vmf_msg_t *pvmf_msg, unsigned16 msg_result_len);





/**************************************************************************//**
 *
 *   Function Name: vmf_logger_create_thread
 *
 *   Description:   create the logger thread
 *
 *   \param         void
 *   \return        bool - true if OK
 *
 ******************************************************************************/
vmf_ret_t vmf_logger_create_thread(void)
{
    int             iRet;
    vmf_ret_t       vmf_ret=VMF_OK;
    pthread_t       th;
    pthread_attr_t  attr;
	char Thread_name[100];

    VMF_LOGGER_INFO_PRINT("vmf_logger_create_thread()");

    /* set thread stack */
    (void) pthread_attr_init( &attr );
    #ifndef __ANDROID__
    if ( pthread_attr_setstacksize(&attr, VMF_LOGGER_STACK_SIZE ) != 0 )
    {
        VMF_LOGGER_ERROR_PRINT("vmf_logger_create_thread() - pthread_attr_setstacksize() failed");
    }
    #endif

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, nw_vmf_logger_thread, NULL);
    (void) pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_LOGGER_ERROR_PRINT("vmf_logger_create_thread() error! errno = %d\n",iRet);
        vmf_ret=VMF_ERROR;
        return vmf_ret;
    }

#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "Vmf-Logger-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif	

    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_logger_Write__create_thread
 *
 *   Description:   create the logger write thread
 *
 *   \param         void
 *   \return        bool - true if OK
 *
 ******************************************************************************/
static vmf_ret_t vmf_logger_write_create_thread(void)
{
    int             iRet;
    vmf_ret_t       vmf_ret=VMF_OK;
    pthread_t       th;
    pthread_attr_t  attr;
	char Thread_name[100];

    /* set thread stack */
    (void) pthread_attr_init( &attr );
    #ifndef __ANDROID__
    if ( pthread_attr_setstacksize(&attr, VMF_LOGGER_STACK_SIZE ) != 0 )
    {
        VMF_LOGGER_ERROR_PRINT("vmf_logger_write_create_thread() - pthread_attr_setstacksize() failed");
    }
    #endif


    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, nw_vmf_logger_write_thread, NULL);
    (void) pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_LOGGER_ERROR_PRINT("vmf_logger_write_create_thread() error! errno = %d\n",iRet);
        vmf_ret=VMF_ERROR;
        return vmf_ret;
    }
    
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "Vmf-Logger-Write-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif	
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_logger_thread(uint32_T ulContext)
 *
 *   Description:   vmf logger thread
 *
 *   \param         not used
 *   \return        noz used
 *
 ******************************************************************************/
static void *nw_vmf_logger_thread(void *pNoArg)
{
    vmf_ret_t           vmf_ret=VMF_OK;
    unsigned8           groupid_list[]={VMF_TRACE_IN};
    unsigned32          ctime_ms=0;


    /* register to the VMF server - wait for connection */
    VMF_LOGGER_INFO_PRINT("nw_vmf_logger_thread");
    nw_sleep_ms(50);   /* give VMF a chance to start */
    while (FOREVER)
    {
        /* try to connect to vmf-server */
        vmf_client_id = nw_vmf_connect("vmf-logger", NULL,0,VMF_CLIENT_QUEUE_SIZE_BIG,VMF_CLIENT_QUEUE_MSG_SIZE_BIG );
        if (vmf_client_id <= 0)
        {
            nw_sleep_ms(10);
            VMF_LOGGER_INFO_PRINT("connected to VMF failed");
        }
        else
        {
            /* connected */
            VMF_LOGGER_INFO_PRINT("connected to VMF");
            break;
        }
    }

    (void) vmf_log_init_module();

    /* read the ini file for the first time */
    vmf_log_wait_for_inifile(vmf_client_id);

    /* register as spy  */
    vmf_ret = nw_vmf_register_spy(vmf_client_id);
    if (vmf_ret != VMF_OK)
    {
        VMF_LOGGER_ERROR_PRINT("nw_vmf_register_spy() failed\n");
        return NULL;
    }
#if 1
    /* register to VMF_TRACE_IN group */
    vmf_ret = nw_vmf_register_msg_group(vmf_client_id,sizeof(groupid_list),groupid_list);
    if (vmf_ret != VMF_OK)
    {
        VMF_LOGGER_ERROR_PRINT("nw_vmf_register_msg_group() failed\n");
        return NULL;
    }
#endif
    /* pre lock write mutex */
    if (pthread_mutex_lock((&vmf_log_write_mux)) != 0)
    {
        VMF_LOGGER_ERROR_PRINT("pre lock mutex pthread_mutex_lock failed");
        return NULL;
    }

    /* start the write thread */
    vmf_ret =  vmf_logger_write_create_thread();
    if (vmf_ret != VMF_OK)
    {
        VMF_LOGGER_ERROR_PRINT("creation of logger write thread failed ");
        return NULL;
    }

    /* main VMF-reception loop */
    while (FOREVER)
    {
        VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_BIG)   vmf_msg;
#if 1
        vmf_ret = nw_vmf_timed_receive(vmf_client_id,(vmf_msg_t*)&vmf_msg,sizeof(vmf_msg),VMF_REC_TIMOUT);
#else
        vmf_ret = nw_vmf_receive(vmf_client_id,(vmf_msg_t*)&vmf_msg,sizeof(vmf_msg));
#endif
        if (vmf_ret > 0)
        {
            /* write data to cache */
            #ifdef HEX_DUMP
            nw_con_HexDump("vmf-rx msg",(unsigned8 *)&vmf_msg,vmf_ret);
            #endif
            vmf_ret = vmf_log_unpack_and_write_msg((vmf_msg_t*)&vmf_msg, vmf_ret);  /* unpack nested messages */
            if (VMF_OK != vmf_ret)
            {
                VMF_LOGGER_ERROR_PRINT("vmf_log_unpack_and_write_msg error %d",vmf_ret);
            }
        }
        else if (vmf_ret < 0)
        {
            VMF_LOGGER_INFO_PRINT("nw_vmf_timed_receive error %d",vmf_ret);
            nw_sleep_ms(50);  /* retry */
        }
        else
        {
            /* timeout */
        }

        /* test if file-time timeout */
        {
            ctime_ms = nw_os_cfg_get_ms_time();
            if ((ctime_ms - last_file_write_ms) > (vmf_logger_info.max_file_time_s * 1000))
            {
                /* write file now */
                (void)vmf_log_write_debug_cache(NULL, 0);
            }
        }
    }

    return NULL;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_write_debug_cache()
 *
 *   Description:   add a message to the USB write cache
 *
 *   Parameters:    pointer to the message buffer, NULL means write current write
 *                  buffer now
 *                  message len
 *
 *
 *   Return value:  bool - true if success else false
 *
 ******************************************************************************/
bool vmf_log_write_debug_cache(unsigned8 *data, int len)
{
    static bool incall_write_debug_cache = false;
    bool        bret=false;

    VMF_LOGGER_INFO_PRINT("vmf_log_write_debug_cache %d bytes",len);
    VMF_LOGGER_INFO_PRINT(".");

    /* parameter check */
#if 0
    if (0 == len)
    {
        /* ignore */
        VMF_LOGGER_ERROR_PRINT("len=0");
        return true;
    }
    else if (NULL == data)
    {
        /*ignore?? */
        VMF_LOGGER_ERROR_PRINT("data=NULL");
        return true;
    }
#endif
    if (false == vmf_log_init_module_done)
    {
        /* not yet initialized */
        VMF_LOGGER_ERROR_PRINT("module not initialized");
        return false;
    }

    if (incall_write_debug_cache != false)
    {
        /* already called by another context */
        VMF_LOGGER_ERROR_PRINT("already called by another context");
        return true;
    }
    incall_write_debug_cache = true;

    if (((current_write_buffer_len + len) > (vmf_logger_info.max_file_len_kb*1024)) || (NULL == data))
    {
        /* write data to USB stick */
        /* open or create trace file */
        if (current_write_buffer_len > 0)
        {
            if (NULL == p_usb_flush_buffer)
            {
                vmf_log_written_msgs2cache++;   /* debug only */
                last_file_write_ms = nw_os_cfg_get_ms_time();

                /* last buffer was written */
                current_flush_buffer_len = current_write_buffer_len;
                p_usb_flush_buffer = p_usb_write_buffer;

                /* switch to the other buffer */
                if (p_usb_write_buffer == p_usb_write_buffer0)
                {
                    p_usb_write_buffer = p_usb_write_buffer1;
                }
                else
                {
                    p_usb_write_buffer = p_usb_write_buffer0;
                }
                current_write_buffer_len = 0;

                /* request the logging of a buffer to USB-Flash */
                /* data in p_usb_flush_buffer                   */
                /* len in current_flush_buffer_len              */
                {
                    /* release write mux to start the writing of the buffer  */
                    VMF_LOGGER_INFO_PRINT("release write mux");
                    (void)pthread_mutex_unlock(&vmf_log_write_mux);
                }
            }
            else
            {
                /* writing still in progress - we are loosing data now !! */
                vmf_usb_flash_lost_messages++;
                VMF_LOGGER_INFO_PRINT("vmf_usb_flash_lost_messages=%d",vmf_usb_flash_lost_messages);

            }
        }
    }
    else
    {
        if (len > 0)
        {
            /* add new message to write buffer */
            int  iret=0;
            iret = vmf_memcpy_s(&(p_usb_write_buffer[current_write_buffer_len]),(vmf_logger_info.max_file_len_kb*1024)-current_write_buffer_len,data,len);
            if (iret != 0)
            {
                VMF_LOGGER_ERROR_PRINT("vmf_memcpy_s() failed with %d",iret);
            }
            // VMF_LOGGER_INFO_PRINT("add %d bytes to write cache",len);
            current_write_buffer_len+=len;
        }
    }
    VMF_LOGGER_INFO_PRINT("current_write_buffer_len=%d\n",current_write_buffer_len);

    incall_write_debug_cache = false;
    return bret;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_logger_write_thread(uint32_T ulContext)
 *
 *   Description:   vmf logger write thread
 *                  this thread will write the logged data to a device
 *
 *   \param         not used
 *   \return        not used
 *
 ******************************************************************************/
static void *nw_vmf_logger_write_thread(void *pNoArg)
{
    VMF_LOGGER_INFO_PRINT("nw_vmf_logger_write_thread");

    while (FOREVER)
    {
        /* try to lock write mutex */
        /* because mutex is already locked - the function will block until the mutex is released by the main thread */

        while (pthread_mutex_lock((&vmf_log_write_mux)) != 0)
        {
            VMF_LOGGER_ERROR_PRINT("lock mutex pthread_mutex_lock failed - wait 100ms");
            nw_sleep_ms(100);        /* wait and try again */
        }

        /* write data */
        while(true)
        {
            if ((current_flush_buffer_len > 0) && (p_usb_flush_buffer != NULL))
            {
                 bool bret;
                 VMF_LOGGER_INFO_PRINT("write data to device");

                 bret = vmf_log_flush_debug_cache_internal(p_usb_flush_buffer, current_flush_buffer_len, VMF_TRACE_FILE_NAME_PREFIX);
                 if (false == bret)
                 {
                     VMF_LOGGER_ERROR_PRINT("vmf_log_flush_debug_cache_internal() failed");
                     /* wait for new ini file */
                     vmf_log_wait_for_inifile(vmf_client_id);
                 }
                 else
                 {
                     /* done writing */
                     break;
                 }
            }
        }

        current_flush_buffer_len = 0;
        p_usb_flush_buffer = NULL;
        VMF_LOGGER_INFO_PRINT("writing done");
    }
    return NULL;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_open_debug_file_internal()
 *
 *   Description:   open a debug file or create it if it is not existing
 *
 *   Parameters:    file name
 *
 *
 *   Return value:  bool - true if success else false
 *
 ******************************************************************************/
static FILE * vmf_log_open_debug_file_internal(char *prefix)
{
    FILE *fp = NULL;
    vmf_usb_trace_header_t   l_hd;

    VMF_LOGGER_INFO_PRINT("entry");

    /* argument check */
    if (NULL == prefix)
    {
        VMF_LOGGER_ERROR_PRINT("filename = NULL");
        return NULL;
    }

    /* create message header */
    vmf_log_init_usb_message_header(&l_hd);

    /* create filename */
    #ifndef VMF_LOG_USE_SHORT_FILENAMES
    /* long filenames */
    (void) snprintf(filepath,sizeof(filepath),"%s%s%04d_%s%s", vmf_logger_info.path,prefix, curr_file_ix, vmf_log_get_current_datetime(), VMF_LOG_FILE_EXTENSION);
    #else
    /* 8.3 filenames */
    (void) snprintf(filepath,sizeof(filepath),"%s%s%04d%s", vmf_logger_info.path,prefix, curr_file_ix, VMF_LOG_FILE_EXTENSION);
    #endif
    VMF_LOGGER_INFO_PRINT("current filename =%s",filepath);


    VMF_LOGGER_INFO_PRINT("open %s",filepath);
    fp = fopen(filepath,"wb");    /* open data for write */

    if(fp!=NULL)
    {
        VMF_LOGGER_INFO_PRINT("open OK");
        /* write message header */
        (void)fwrite((unsigned8 *)&l_hd, sizeof(unsigned8), sizeof(vmf_usb_trace_header_t), fp);
    }
    else
    {
        /* open failed */
        VMF_LOGGER_ERROR_PRINT("fopen('%s') failed",filepath);
    }
    return fp;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_close_debug_file_internal()
 *
 *   Description: close the debug file
 *
 *   Parameters:    file handle
 *
 *
 *   Return value:  void
 *
 ******************************************************************************/
static void vmf_log_close_debug_file_internal(FILE *fp)
{
    int ret=0;

    VMF_LOGGER_INFO_PRINT("entry");
    /* argument check */
    if (NULL == fp)
    {
        VMF_LOGGER_INFO_PRINT("fp=NULL");
        return;
    }

    /* try to close the file */
    (void)fflush(fp);
    ret = fclose(fp);
    if(ret != 0)
    {
        /* close failed */
        VMF_LOGGER_ERROR_PRINT("fclose() failed");
    }
    else
    {
        fp = NULL;
        /* get next file number */
        curr_file_ix++;
    }
}



/**************************************************************************//**
 *
 *   Function Name: vmf_log_write_debug_file_internal()
 *
 *   Description:   wrapper for fwrite()
 *
 *   Parameters:    file name
 *
 *
 *   Return value:  number of elements written
 *
 ******************************************************************************/
static size_t vmf_log_write_debug_file_internal(void *ptr, size_t size, size_t count, FILE *stream)
{
    size_t  summ = 0;

#if 1
    size_t  szret =0;
    while (summ < count)
    {
        szret = fwrite(&(((unsigned8*)ptr)[summ]), size, count-summ, stream);
        vmf_log_written_msgs2usb++;
        if (0 == szret)
        {
            /* error */
            vmf_log_written_msgs2usb_errors++;
            VMF_LOGGER_ERROR_PRINT("fwrite() failed");
            nw_sleep_ms(VMF_MI_USB_ERROR_WAIT);
            break;
        }
        else
        {
            vmf_log_written_msgs2usb_errors=0;
        }
        summ += szret;
    }
#else
    summ = fwrite((unsigned8*)ptr, size, count, stream);
#endif
    return summ;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_flush_debug_cache_internal()
 *
 *   Description:   write current debug buffer to USB-stick
 *
 *   Parameters:    pointer to the message buffer
 *                  message len
 *
 *
 *   Return value:  bool - true if success else false
 *
 ******************************************************************************/
static bool vmf_log_flush_debug_cache_internal(unsigned8 *data, int len, char *prefix)
{
    bool        bret=false;
    unsigned32  ctime=0;

    if ((NULL != data) && (len > 0) && (NULL != prefix))
    {
        /* write data to USB stick */
        /* open or create trace file */
        ctime = nw_os_cfg_get_ms_time();
        fp = vmf_log_open_debug_file_internal(prefix);
        if (NULL == fp)
        {
            /* open failed */
            VMF_LOGGER_ERROR_PRINT("open-file failed");
            nw_sleep_ms(VMF_MI_USB_ERROR_WAIT);
            bret=false;
        }
        else
        {
            size_t      szret=0;
            szret = vmf_log_write_debug_file_internal(data, sizeof(unsigned8), len, fp);
            if (szret!=0)
            {
                (void)fflush(fp);
            }
            vmf_log_close_debug_file_internal(fp);
            fp=NULL;
            bret=true;



#ifdef VMF_TRACE_VERIFY_LOGFILE
            /* test if log file was written to the USB stick */
            if (vmf_status.vmf_log_active != false)
            {
                int cnt=0;

                while (true)
                {
                    fp = fopen(filepath,"r");    /* try to open the log-file  */
                    if(fp != NULL)
                    {
                        /* the log file is existing! */
                        (void)fclose(fp);
                        break;
                    }

                    nw_sleep_ms(VMF_TRACE_MAX_VERIFY_TIME);
                    cnt++;
                    if (cnt>VMF_TRACE_MAX_VERIFY_NUM)
                    {
                        /* we give up */
                        break;
                    }
                }
            }
#endif

            /* write current index into index-ini file */
            (void)vmf_log_write_logfileindex_ini(VMF_LOG_INDEX_INI, curr_file_ix);
        }
        if (fp != NULL)
        {
            ftotal_time = nw_os_cfg_get_ms_time()-ctime;
            VMF_LOGGER_INFO_PRINT("write time = %dms",ftotal_time);
        }
    }
    return bret;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_log_init_usb_message_header()
 *
 *   Description:   init the usb file message header
 *
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static void vmf_log_init_usb_message_header(vmf_usb_trace_header_t *hd)
{
    time_t t = time(NULL);
    struct tm *c_tm = localtime(&t);

    if (NULL == hd)
    {
        return;
    }

    if (NULL == c_tm)
    {
        return;
    }

    /* init usb-trace header*/
    memset(hd,0,sizeof(vmf_usb_trace_header_t));

    hd->version_l = VMF_USB_TRACE_VERSION_L;
    hd->version_h = VMF_USB_TRACE_VERSION_H;
    hd->vmf[0]='v';
    hd->vmf[1]='m';
    hd->vmf[2]='f';
    hd->not_used = 0;
    hd->year     = (c_tm->tm_year + 1900) -2000;
    hd->month    = c_tm->tm_mon + 1;
    hd->days     = c_tm->tm_mday;
    hd->hours    = c_tm->tm_hour;
    hd->minutes  = c_tm->tm_min;
    hd->seconds  = c_tm->tm_sec;
}

/**************************************************************************//**
 *
 *   Function Name: vmf_log_get_current_datetime()
 *
 *   Description:   get current date and time as string
 *
 *   Parameters:    void
 *
 *   Return value:  pointer to datetime string
 *
 ******************************************************************************/
static char *vmf_log_get_current_datetime(void)
{
    time_t t = time(NULL);
    static char current_datetime[20];

    struct tm *ltm = localtime(&t);
    current_datetime[0]=0;

    if (ltm != NULL)
    {
        (void)snprintf(current_datetime,sizeof(current_datetime),"%02u%02u%02u_%02u%02u%02u",
                    (ltm->tm_year+ 1900)-2000,
                    ltm->tm_mon + 1,
                    ltm->tm_mday,
                    ltm->tm_hour,
                    ltm->tm_min,
                    ltm->tm_sec);
    }

    return current_datetime;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_init_module()
 *
 *   Description:   init the vmf_logging module
 *
 *   Parameters:    void
 *
 *
 *   Return value:  bool - true if success else false
 *
 ******************************************************************************/
static bool vmf_log_init_module(void)
{
    static      bool init_done = false;
    bool        bret=true;
    size_t      len=0;

    if (init_done != false)
    {
        return true;        /* already initialized */
    }
    init_done = true;

    (void)vmf_trace_register(&vmf_trid,"vmf-mi");

    len = VMF_LOGG_MAX_DEBUG_FILE_LEN_KB*1024+4;   /* length in bytes */
    p_usb_write_buffer0 = malloc(len);
    if (NULL == p_usb_write_buffer0)
    {
        /* malloc failed */
         VMF_LOGGER_ERROR_PRINT("malloc(%d) failed!!",(int)len);
         bret = false;
    }
    p_usb_write_buffer1 = malloc(len);
    if (NULL == p_usb_write_buffer1)
    {
        /* malloc failed */
         VMF_LOGGER_ERROR_PRINT("malloc(%d) failed!!",(int)len);
         bret = false;
    }

    if (true == bret)
    {
        p_usb_write_buffer = p_usb_write_buffer0;
        vmf_log_init_module_done = true;
    }

    return bret;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_log_write_logfileindex_ini()
 *
 *   Description:   write an ini file with the current log file-index
 *
 *   Parameters:    filname
 *                  index
 *
 *   Return value:  true if OK
 *
 ******************************************************************************/
static bool vmf_log_write_logfileindex_ini(char * filename, unsigned16 current_ix)
{
    FILE *fp = NULL;
    bool bret=false;
    char tmp[100];

    /* argument check */
    if (NULL == filename)
    {
        VMF_LOGGER_ERROR_PRINT("filename = NULL");
        return false;
    }

    /* create filename and open file */
    (void) snprintf(tmp,sizeof(tmp),"%s%s", vmf_logger_info.path, filename);
    fp = fopen(tmp,"w");    /* write data */
    if(fp!=NULL)
    {
        int len=0;
        VMF_LOGGER_INFO_PRINT("write %s",tmp);
        /* write ini entry */
        len = snprintf(tmp,sizeof(tmp),"%s\n",VMF_LOG_START_SECTION );                  /* create section */
        (void) fwrite((unsigned8 *)&tmp, sizeof(unsigned8), len, fp);

        len = snprintf(tmp,sizeof(tmp),"%s=%d\n\n",VMF_LOG_START_IX_KEY,current_ix);  /* create key */
        (void) fwrite((unsigned8 *)&tmp, sizeof(unsigned8), len, fp);
        (void) fclose(fp);
        bret = true;
    }
    else
    {
        /* open failed */
        VMF_LOGGER_ERROR_PRINT("fopen('%s') failed",tmp);
        bret = false;
    }
    return bret;

}


/**************************************************************************//**
 *
 *   Function Name: vmf_log_wait_for_inifile()
 *
 *   Description:   wait until USB stick is inserted and read ini file
 *
 *   Parameters:    cid
 *
 *
 *   Return value:  void
 *
 ******************************************************************************/
static void vmf_log_wait_for_inifile(vmf_client_id_t cid)
{
    while(true)
    {
        bool bret;

        bret = vmf_log_read_inifile(vmf_client_id);
        if (false == bret)
        {
            nw_sleep_ms(500);
            continue;           /* retry to read ini file */
        }
        break;
    }
}

/**************************************************************************//**
 *
 *   Function Name: vmf_log_read_inifile()
 *
 *   Description:   read vmf_log.ini from USB stick
 *
 *   Parameters:    cid
 *
 *
 *   Return value:  TRUE if ini file was opened
 *
 ******************************************************************************/
static bool vmf_log_read_inifile(vmf_client_id_t cid)
{
    char filepath[100]={0};
    bool bret = false;
    int  len=0;

    (void) snprintf(filepath,sizeof(filepath),"%s%s", vmf_logger_info.path,VMF_LOG_INI_FILE);
    VMF_LOGGER_INFO_PRINT("open %s",filepath);
    fp_ini = ini_parser_open(filepath);
    if (NULL == fp_ini)
    {
        VMF_LOGGER_INFO_PRINT("open %s failed",filepath);
        return false;
    }
    else
    {
        int     num_procs=0;
        int     severity=0;
        char    val[50];
        char    key_name[100];
        int     current_key_num;
        int     ret_val=0;

        VMF_LOGGER_INFO_PRINT("open %s OK",filepath);

        /* set all trace severities to 0 */
        (void) vmf_log_send_global_filter_severity(cid,0);

        /* handle [vmf_messages] section */
        {
            char        curr_filer[]= MAX_INI_VMF_FILTER_STRING "00";
            unsigned16  cnt;

            /* send vmf messages from ini file via vmf */
            for (cnt=0; cnt<MAX_INI_VMF_MAX_MSG_NUM ;cnt++)
            {
                /* create the key-name */
                (void) snprintf(curr_filer,sizeof(curr_filer),"%s%d",MAX_INI_VMF_FILTER_STRING,cnt);
                len = ini_parser_get_val(fp_ini,VMF_INI_VMF_MSG_SEC,curr_filer,val,sizeof(val));

                if (len > 0)
                {
                    unsigned8   byte_list[MAX_INI_VMF_MAX_PL_LEN+2];

                    /* pars the byte list from the line */
                    len = ini_parser_get_byte_list(val, byte_list, sizeof(byte_list));
                    if (len >= 2)
                    {
                        unsigned16  pl_len;

                        pl_len = len-2;     /* len = len - 1 byte group and 1 byte event*/
                        nw_sleep_ms(10);
                        (void)vmf_log_trace_send_command(byte_list[0], byte_list[1], &(byte_list[2]) ,pl_len);
                    }
                }
            }
        }

        /* handle [trace_severities] section */
        bret = true;                /* a ini file was found! */

        /* loop through all trace severities */
        current_key_num = 0;
        for (num_procs =0; num_procs< MAX_INI_NUM_PROC_SEVERITIES; num_procs++)
        {
            ret_val = ini_parser_get_key_num_val(fp_ini, VMF_INI_SEVERITY_SEC ,current_key_num, key_name, sizeof(key_name), val,sizeof(val));
            if ((ret_val >= 0) && (key_name[0] != 0) && (key_name[0] != 0x0d) && (key_name[0] != 0x0a) )
            {
                unsigned8 ltrid;
                severity=atoi(val);
                /* send severity to vmf */
                if (VMF_TRACE_REGISTER(&ltrid, key_name)==VMF_OK)
                {
                        // VMF_LOGGER_INFO_PRINT("send severity %d for trace-client %s", severity, key_name);
                        nw_sleep_ms(10);
                        (void)vmf_log_send_filter_severity(cid, ltrid, severity);
                }
            }
            else if (INI_PARSER_EMPTY_LINE == ret_val)
            {
                /* empty line - go on */
            }
            else if (INI_PARSER_END_OF_SECTION == ret_val)
            {
                break;      /* no more keys in this section */
            }
            current_key_num++;
        }

        /* read logging section */
        if (vmf_logger_info.enabled)
        {
            /* read max file length */
            len = ini_parser_get_val(fp_ini,VMF_INI_LOGGING_SEC,VMF_INI_LOG_FILE_LEN_KEY,val,sizeof(val));
            if (len>0)
            {
                vmf_logger_info.max_file_len_kb = (unsigned16)atoi(val);
            }

            /* read max file time */
            len = ini_parser_get_val(fp_ini,VMF_INI_LOGGING_SEC,VMF_INI_LOG_FILE_TIME_KEY,val,sizeof(val));
            if (len>0)
            {
                vmf_logger_info.max_file_time_s = (unsigned16)atoi(val);
                VMF_LOGGER_INFO_PRINT("max_file_time_s=%d",vmf_logger_info.max_file_time_s);
            }

            VMF_LOGGER_INFO_PRINT("max_file_time_s=%d",vmf_logger_info.max_file_time_s);
            VMF_LOGGER_INFO_PRINT("max_file_len_kb=%d",vmf_logger_info.max_file_len_kb);

            /* check range for logging time and logging file size */
            if ((vmf_logger_info.max_file_time_s > VMF_LOGG_MAX_DEBUG_FILE_TIME_S) || (0 == vmf_logger_info.max_file_time_s))
            {
                VMF_LOGGER_INFO_PRINT("max_file_time_s=%d - so set to VMF_LOGG_MAX_DEBUG_FILE_TIME",vmf_logger_info.max_file_time_s);
                vmf_logger_info.max_file_time_s = VMF_LOGG_MAX_DEBUG_FILE_TIME_S;
            }
            if ((vmf_logger_info.max_file_len_kb > VMF_LOGG_MAX_DEBUG_FILE_LEN_KB) || (0 == vmf_logger_info.max_file_len_kb))
            {
                VMF_LOGGER_INFO_PRINT("max_file_len_kb=%d - so set to VMF_LOGG_MAX_DEBUG_FILE_LEN",vmf_logger_info.max_file_len_kb);
                vmf_logger_info.max_file_len_kb = VMF_LOGG_MAX_DEBUG_FILE_LEN_KB;
            }
        }

        ini_parser_close(fp_ini);
    }

    /* read current file index from vmf_log_ix.ini */
    (void) snprintf(filepath,sizeof(filepath),"%s%s",vmf_logger_info.path, VMF_LOG_INDEX_INI);
    VMF_LOGGER_INFO_PRINT("read %s",filepath);

    fp_ini = ini_parser_open(filepath);
    if (fp_ini != NULL)
    {
        char    val[10];
        len = ini_parser_get_val(fp_ini,VMF_LOG_START_SECTION,VMF_LOG_START_IX_KEY,val,sizeof(val));
        if (len >= 1)
        {
            curr_file_ix = atoi(val);
            VMF_LOGGER_INFO_PRINT("curr_file_ix=%d",curr_file_ix);
        }
        ini_parser_close(fp_ini);
    }

    VMF_LOGGER_INFO_PRINT("reading ini files done");

    return bret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_log_trace_send_command()
 *
 *   Description:   send a message to vmf
 *
 *   Parameters:    message id
 *                  data buffer
 *                  len of data
 *
 *   Return value:  TRUE if OK
 *
 ******************************************************************************/
static bool vmf_log_trace_send_command(unsigned8 group, unsigned8 event, unsigned8 *data,unsigned16 len)
{
    #define MAX_INI_VMF_PL_LEN          (10)         /* max payload len for vmf messages in vmf_log.ini file */
    bool        bret = true;
    VMF_VAR_BASIC_MSG_TYP(MAX_INI_VMF_PL_LEN) vmf_msg;
    vmf_basic_msg_t   *pvmf_msg=(vmf_basic_msg_t*)&vmf_msg;
    vmf_ret_t   ret_val;

    /* create vmf message */
    NW_VMF_BASIC_MSG_TYPE(pvmf_msg)         = MSG_TYPE_BASIC_MESSAGE;
    NW_VMF_BASIC_MSG_GROUP(pvmf_msg)        = group;
    NW_VMF_BASIC_MSG_EVENT(pvmf_msg)        = event;
    NW_VMF_BASIC_MSG_DATA_LENGTH(pvmf_msg)  = len;
    (void)vmf_memcpy_s(NW_VMF_BASIC_MSG_DATA_PTR(pvmf_msg),MAX_INI_VMF_PL_LEN,data,len);

    ret_val = nw_vmf_send_basic(vmf_client_id, pvmf_msg);   /* use rx cid from vmf receive thread */
    if (VMF_OK != ret_val)
    {
        VMF_LOGGER_INFO_PRINT("nw_vmf_send_basic() failed");
    }
#if 0
    int cnt;
    VMF_LOGGER_INFO_PRINT("send message with group=0x%02x, event=0x%02x, data [ ",group, event);
    for (cnt=0;cnt<len;cnt++)
    {
        VMF_LOGGER_INFO_PRINT("0x%02x ",data[cnt]);
    }
    VMF_LOGGER_INFO_PRINT("] to VMF\n\r");
#endif
    return bret;
}

/*************************************************************************//**
 *
 *   safe memcopy  \n
 *
 *   \param[in] pointer to dest buffer
 *   \param[in] size of dest buffer
 *   \param[in] pointer to source buffer
 *   \param[in] length of source data
 *
 *   \return    0 if OK else error
 *              -1 NULL poointer
 *              -2 dest buffer to small
 *
 ******************************************************************************/
static int vmf_memcpy_s(void *dest_buffer, size_t dest_buffer_len, void *src_buffer, size_t src_data_len)
{
    int     retval=0;

    /* argument check */
    if ((NULL == dest_buffer) || (NULL == src_buffer))
    {
        /* NULL pointer !! */
        retval = -1;
    }
    else if (src_data_len > dest_buffer_len)
    {
        /* data will not fit! */
        retval = -2;
    }
    else
    {
        /* arguments OK so memcpy */
        (void)memcpy(dest_buffer, src_buffer, src_data_len);
    }
    return retval;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_log_send_global_filter_severity()
 *
 *   Description:   send the global filter severity
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     severity    this severity is set for all trids
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_log_send_global_filter_severity(vmf_client_id_t cid, unsigned8 severity)
{
    vmf_ret_t           vmf_ret=VMF_OK;


    {
        vmf_trace_ctrl_pl_t pl;

        pl.flt_severity.trid = 0;                                   /* message to all */
        pl.flt_severity.severity = severity;
        pl.flt_severity.name[0] = 0;
        pl.flt_severity.trace_active = true;                        /* stored trace active status */

        /* transfer the filter request client (zero length payload) */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_SET,&pl,sizeof(vmf_trace_ctrl_filter_severity_t));
        if (VMF_OK != vmf_ret)
        {
            VMF_LOGGER_ERROR_PRINT("vmf_trace_send_ctrl() failed error = %d",vmf_ret);
        }
    }

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_log_send_filter_severity()
 *
 *   Description:   send the filter severity for a trid
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     trid        trace id
 *   \param[in]     severity    this severity is set for all trids
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_log_send_filter_severity(vmf_client_id_t cid, unsigned8 trid, unsigned8 severity)
{
    vmf_ret_t           vmf_ret=VMF_OK;


    {
        vmf_trace_ctrl_pl_t pl;

        pl.flt_severity.trid = trid;
        pl.flt_severity.severity = severity;
        pl.flt_severity.name[0] = 0;
        pl.flt_severity.trace_active = true;                         /* stored trace active status */

        /* transfer the filter request client (zero length payload) */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_SET,&pl,sizeof(vmf_trace_ctrl_filter_severity_t));
        if (VMF_OK != vmf_ret)
        {
            VMF_LOGGER_ERROR_PRINT("vmf_trace_send_ctrl() failed error = %d",vmf_ret);
        }
    }

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_log_unpack_and_write_msg()
 *
 *   Description:   unpack a collector message to a byte array and write message to cache
 *
 *   \param[in]     pointer to vmf message
 *   \param[out]    result buffer
 *   \param[out]    result data len
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_log_unpack_and_write_msg(vmf_msg_t *pvmf_msg, unsigned16 msg_result_len)
{
    #define     len_offset offsetof(vmf_basic_msg_t,data.length)

    vmf_ret_t           vmf_ret=VMF_OK;
    unsigned8           co_msg_type;
    unsigned8           msg_num;
    unsigned8           num_msgs=0;

    if (NULL == pvmf_msg)
    {
        VMF_LOGGER_ERROR_PRINT("NULL pointer");
        return VMF_ERROR;
    }

    co_msg_type = pvmf_msg->vmf_basic_msg.msg_base.base.co_msg_type;

    if ((co_msg_type == COL_VMF_MSG_SPY) || (co_msg_type == COL_VMF_MSG))
    {
        /* unpack the message */
        vmf_basic_msg_t *pvmf_co_msg;
        unsigned8       *p_unpack_msg_ptr=NULL;
        unsigned16      unpack_msg_len=0;
        unsigned16      unpack_msg_pl_len=0;

        pvmf_co_msg = (vmf_basic_msg_t*)pvmf_msg;
        num_msgs = pvmf_co_msg->msg_base.base.vmf_co_num_msgs;

        /* we can not just cast to a vmf_basic_msg_t because the messages */
        /* in the buffer are not aligned !!                               */
        p_unpack_msg_ptr = pvmf_co_msg->data.pl;                                            /* address of first collected VMF msg */
        /* get pl length of the current vmf message */
        memcpy (&unpack_msg_pl_len,&(p_unpack_msg_ptr[len_offset]),sizeof(unsigned16));     /* length of payload oc current message */
        unpack_msg_len = unpack_msg_pl_len + VMF_BASIC_MSG_HEADER_SIZE;                     /* length of current vmf message */

        for (msg_num = 0; msg_num < num_msgs; msg_num++)
        {
#if 0
            vmf_basic_msg_t *ptmp;
            ptmp = (vmf_basic_msg_t*)p_unpack_msg_ptr;

            if (NW_VMF_BASIC_MSG_TYPE(ptmp) == MSG_TYPE_BASIC_EMBEDDED_MESSAGE)             /* !! alignment - will only work for bytes */
            {
                vmf_basic_msg_t *p_emb;
                unsigned16      emb_pl_len=0;

                p_emb = (vmf_basic_msg_t*)ptmp->data.pl;

                /* message is in the payload of this MSG_TYPE_BASIC_EMBEDDED_MESSAGE  */
                memcpy (&emb_pl_len,&(p_unpack_msg_ptr[len_offset]),sizeof(unsigned16));               /* !! alignment - length of payload of current message */
                (void)vmf_log_write_debug_cache((unsigned8 *)p_emb, VMF_BASIC_MSG_LEN(emb_pl_len));
                #ifdef HEX_DUMP
                nw_con_HexDump("embedded msg",(unsigned8 *)p_emb,VMF_BASIC_MSG_LEN(emb_pl_len));
                #endif
            }
            else
#endif
            {
                /* write message direct */
                (void)vmf_log_write_debug_cache((unsigned8 *)p_unpack_msg_ptr, VMF_BASIC_MSG_LEN(unpack_msg_pl_len));
                #ifdef HEX_DUMP
                nw_con_HexDump("unpacked msg",(unsigned8 *)p_unpack_msg_ptr,VMF_BASIC_MSG_LEN(unpack_msg_pl_len));
                #endif
            }
            p_unpack_msg_ptr += unpack_msg_len;     /* addr of next message */
            memcpy (&unpack_msg_pl_len,&(p_unpack_msg_ptr[len_offset]),sizeof(unpack_msg_pl_len));
            unpack_msg_len = unpack_msg_pl_len + VMF_BASIC_MSG_HEADER_SIZE;

        }
    }
    else
    {
        /* write message direct to write cache */
        (void)vmf_log_write_debug_cache((unsigned8 *)pvmf_msg, msg_result_len);
        #ifdef HEX_DUMP
        nw_con_HexDump("native msg",(unsigned8 *)pvmf_msg,msg_result_len);
        #endif
    }

    return vmf_ret;
}




