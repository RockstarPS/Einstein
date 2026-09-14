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

/*************************************************************************//**

  \file                 vmf_mi_mqx.c
  \brief                VMF mi connector for mqx

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              iar
  target                mqx

  *****************************************************************************/
#define __NW_VMF_IPC_MQX_C__

// #define VMF_MI_WAIT_FOR_DEVICES
// #define VMF_MI_ENABLE_COMPRESSION
// #define POLLING_UART

#define PROFILE_A5


#include "vmf.h"

#if VMF_CORE == VS_MICRO_CORE_A5
#undef VMF_MI_ENABLE_COMPRESSION
#endif


#include "vmf_mi_mqx.h"
#include "vmf_mqx_profiler.h"
#ifdef VMF_MI_ENABLE_COMPRESSION
#include "lzrw3.h"
#endif

#if ( VMF_CORE == VS_MICRO_CORE )
/*  macros */
#ifdef VMF_TRACE
#define VMF_TRACE_SCOPE                 (char *)__FUNCTION__
#define MI_INFO(scope,...)              vmf_trace_printf(vmf_trid, 60, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define MI_INFO_1(scope,...)            vmf_trace_printf(vmf_trid, 61, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define MI_INFO_2(scope,...)            vmf_trace_printf(vmf_trid, 62, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define MI_WARNING(scope, ...)          vmf_trace_printf(vmf_trid, 20, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define MI_ERROR(scope, ...)            vmf_trace_printf(vmf_trid, 10, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#else
#define MI_INFO(scope,...)
#define MI_INFO_1(scope,...)
#define MI_INFO_2(scope,...)
#define MI_WARNING(scope,...)
#define MI_ERROR(scope,...)
#endif

#define MI_TH_INFO(scope,...)
#define MI_TH_INFO_1(scope,...)
#define MI_TH_INFO_2(scope,...)
#define MI_TH_WARNING(scope,...)
#define MI_TH_ERROR(scope,...)


#define MI_TASK_VMF_NAME    ("TASK_VMF_MI_VMF")                 /* vmf-mi task name */
#define MI_TASK_SER_NAME    ("TASK_VMF_MI_SER")                 /* vmf-mi task name */
#define MI_STACK_SIZE_VMF   (4000)                              /* stack size in bytes */
#define MI_STACK_SIZE_SER   (4000)                              /* stack size in bytes */
#define MI_TASK_PRIORITY    (7)


/* external and shared memory */
extern vmf_trace_shm_t  vmf_trace_shm;


BOOL vmf_connected = false;

/* module global variables */
static unsigned16   vmf_target_id_a5 = SYSINFO_ALL_TARGETS;
static unsigned16   vmf_target_id_m4 = SYSINFO_ALL_TARGETS;

static struct compress_identity *p_identity;
static unsigned8        *p_pack=NULL;
static unsigned8        *p_unpack=NULL;
static FILE             *mi_fp=NULL;
static vmf_client_id_t  mi_cid=0;
static unsigned8        vmf_trid=0;

/* local functions */
static void         vmf_mqx_mi_vmf_thread   (uint_32 param);
static void         vmf_mqx_mi_serial_thread(uint_32 param);

static void         vmf_mi_init(void);
static unsigned16   nw_mi_write_device(FILE *fp, unsigned8 *data, unsigned16 data_len);
static vmf_ret_t    nw_mi_read_device (FILE *fp, unsigned8 *data, unsigned16 data_len);
static FILE *       vmf_mi_open       (char *devname);
static void         vmf_mi_close      (FILE *fp);

static unsigned16   vmf_mi_calc_cs     (unsigned8 *psrc, unsigned16 len);
static BOOL         vmf_handle_vmf_in_messages(vmf_msg_t *p_vmf_msg);
static vmf_ret_t    vmf_trace_handle_filter_req(vmf_client_id_t cid,vmf_trace_shm_t* p_shm);
static vmf_ret_t    vmf_trace_send_filter_response(vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm);
static vmf_ret_t    vmf_trace_send_filter_request(vmf_client_id_t cid);
static vmf_ret_t    vmf_trace_decode_trace_ctrl(vmf_trace_shm_t* p_shm, vmf_msg_t *p_vmf_msg);
static vmf_ret_t    vmf_trace_decode_sysinfo_ctrl(vmf_trace_shm_t* p_shm, vmf_msg_t *p_vmf_msg);
static vmf_ret_t    vmf_trace_handle_info_req(vmf_cid_t cid, vmf_sysinfo_ctrl_target_info_req_pl_t* ptr);
static vmf_ret_t    vmf_trace_send_info_resp(vmf_cid_t cid, unsigned16 core);
static vmf_ret_t    vmf_trace_handle_target_id_set(vmf_cid_t cid, vmf_sysinfo_ctrl_target_id_set_t* ptr);


#ifdef VMF_MI_ENABLE_COMPRESSION
static unsigned16   vmf_mi_decomp_lzrw3(unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);
static unsigned16   vmf_mi_comp_lzrw3  (unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);
#endif


/**************************************************************************//**
 *
 *   Function Name: vmf_mi_mqx_create_thread()
 *
 *   Description:   create and start the vmf_mi_mqx thread
 *
 *   Parameters:     not used
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
BOOL vmf_mi_mqx_create_thread(void *param)
{
    BOOL    bret = FALSE;

    mi_fp = vmf_mi_open(VMF_MI_DEVICE);


    #ifdef VMF_MQX

    /* use native mqx task */
    _task_id vmf_apptask_id;
    TASK_TEMPLATE_STRUCT mqx_vmfapp_template;

    mqx_vmfapp_template.TASK_TEMPLATE_INDEX = 1;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_mqx_mi_vmf_thread;
    mqx_vmfapp_template.TASK_NAME           = MI_TASK_VMF_NAME;
    mqx_vmfapp_template.CREATION_PARAMETER  = (uint_32)(0);
    mqx_vmfapp_template.TASK_STACKSIZE      = MI_STACK_SIZE_VMF;
    mqx_vmfapp_template.TASK_PRIORITY       = MI_TASK_PRIORITY;
    mqx_vmfapp_template.CREATION_PARAMETER  = 0;
    mqx_vmfapp_template.DEFAULT_TIME_SLICE  = 5;
    mqx_vmfapp_template.TASK_ATTRIBUTES = MQX_TIME_SLICE_TASK;
    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }


    mqx_vmfapp_template.TASK_NAME           = MI_TASK_SER_NAME;
    mqx_vmfapp_template.TASK_STACKSIZE      = MI_STACK_SIZE_SER;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_mqx_mi_serial_thread;
    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }

    #else
    /* use OSAL */
    os_task_create_t vmf_apptask     = { MI_STACK_SIZE_VMF, MI_TASK_PRIORITY, vmf_mqx_mi_vmf_thread, 0, FALSE };    /* stack, priority, cannback, arg, use_queue */
    os_task_create_t vmf_apptask_ser = { MI_STACK_SIZE_SER, MI_TASK_PRIORITY, vmf_mqx_mi_serial_thread, 0, FALSE }; /* stack, priority, cannback, arg, use_queue */
    os_task_id_t        vmf_app_task_id;

    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask))
    {
        bret = FALSE;
    }
    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask_ser))
    {
        bret = FALSE;
    }
    #endif

    return bret;
}



/**************************************************************************
 *      local functions
/**************************************************************************/



/**************************************************************************//**
 *
 *   Function Name: vmf_mqx_mi_vmf_thread()
 *
 *   Description:   VMF mi vmf thread
 *                  this thread will receive vmf data
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_mqx_mi_vmf_thread(uint_32 param)
{
    vmf_ret_t       vmf_ret=VMF_ERROR;
    unsigned8       groups[]=VMF_MI_GROUPS;


    /* connect to VMF */
    #ifdef VMF_MI_WAIT_FOR_DEVICES
    while(mi_cid<=0)
    {
        mi_cid = nw_vmf_connect("vmf_mi",NULL,0,5,400);
        if (mi_cid <= 0)
        {
            MI_TH_WARNING("nw_vmf_connect","nw_vmf_connect() failed");
            nw_sleep_ms(WAIT_SOME_TIME);
        }
    }
    #else
    mi_cid = nw_vmf_connect("vmf_mi",NULL,0,VMF_MI_MAX_Q_LEN,sizeof(vmf_msg_t));
    (void)vmf_trace_register(&vmf_trid,"vmf-mi");
    if (mi_cid <= 0)
    {
        MI_TH_ERROR("nw_vmf_connect","nw_vmf_connect() failed");
    }
    #endif
    MI_TH_INFO("nw_vmf_connect","connection to VMF established - mi_cid=%d", mi_cid);

    /* register as spy */
    vmf_ret = nw_vmf_register_spy(mi_cid);  /* forward all messages */
    if (vmf_ret != VMF_OK)
    {
        MI_TH_ERROR("nw_vmf_register_spy","nw_vmf_register_msg_group() failed");
    }


    /* wait until connection to windows wmf was established */
    while(FALSE == vmf_connected)
    {
        nw_sleep_ms(10);
    }

    /* task main loop */
    MI_TH_INFO("nw_vmf_receive","waiting for VMF messages");
    while (VMF_OK == vmf_ret)
    {
        nw_vmf_mi_transfer_v2_t tx_msg; /* stack! */
        vmf_ret_t   ret_val;
        unsigned16  len;

        ret_val = nw_vmf_receive(mi_cid,&(tx_msg.svmf_msg),sizeof(tx_msg.svmf_msg));
        if (ret_val>0)
        {
            unsigned16 cs=0;

            /* forward message to windows VMF */
            //nw_con_HexDump("rx",&tx_msg.svmf_msg,32);
            if (tx_msg.svmf_msg.pl_len > VMF_PL_LEN_MAX)
            {
                /* ignore */
                MI_WARNING("nw_vmf_receive","rx_len=%d > VMF_PL_LEN_MAX",ret_val);
                continue;
            }

            /* prepare message */
            tx_msg.token0 = VALID_TOKEN0;
            tx_msg.token1 = VALID_TOKEN1;
            tx_msg.version_l = VMF_MI_VERISION_L;
            tx_msg.version_h = VMF_MI_VERISION_H;
            tx_msg.svmf_len = VMF_MSG_LEN(tx_msg.svmf_msg.pl_len);
            cs = vmf_mi_calc_cs(&(tx_msg.svmf_msg),tx_msg.svmf_len);
            tx_msg.csum_l = cs & 0xff;
            tx_msg.csum_h = cs >> 8;


#ifdef VMF_MI_ENABLE_COMPRESSION
            tx_msg.comp = COMP_MI_LZWR3;
            if (tx_msg.svmf_len > VMF_MI_COMP_MIN)
            {
                len =  vmf_mi_comp_lzrw3(&tx_msg.svmf_msg, VMF_MSG_LEN(tx_msg.svmf_msg.pl_len), &tx_msg.svmf_msg, sizeof(tx_msg.svmf_msg));
                tx_msg.svmf_len = len;
            }
#else
            tx_msg.comp = COMP_MI_NO;
#endif
            len = nw_mi_write_device(mi_fp,&tx_msg,sizeof(nw_vmf_mi_transfer_v2_header_t)+VMF_MSG_LEN(tx_msg.svmf_msg.pl_len));
            if (len!=sizeof(nw_vmf_mi_transfer_v2_header_t)+VMF_MSG_LEN(tx_msg.svmf_msg.pl_len))
            {
                MI_ERROR("nw_mi_write_device","nw_mi_write_device() failed, bytes written=%d, total bytes=%d",len,sizeof(nw_vmf_mi_transfer_v2_header_t)+VMF_MSG_LEN(tx_msg.svmf_msg.pl_len));
            }
        }
        else
        {
            MI_ERROR("nw_vmf_receive","nw_vmf_receive() failed, error code=%d",ret_val);
        }
    }

    MI_ERROR("task","TASK ended");

}






/**************************************************************************//**
 *
 *   Function Name: vmf_mqx_mi_serial_thread()
 *
 *   Description:   VMF mi serial thread
 *                  this thread will receive the serial data
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_mqx_mi_serial_thread(uint_32 param)
{
    unsigned16              remaining_header_len;
    vmf_ret_t               vmf_ret=VMF_ERROR;
    static nw_vmf_mi_transfer_v2_t rx_msg;          /* do not put on stack! */

    MI_INFO("start","start");

    /* open mi-device */
    if (0 == mi_fp)
    {
        mi_fp = vmf_mi_open(VMF_MI_DEVICE);
        if (NULL == mi_fp)
        {
                MI_ERROR("vmf_mi_open","vmf_mi_open(%s) failed",VMF_MI_DEVICE);
                return;
        }
        MI_INFO("vmf_mi_open","VMF-MI device %s open", VMF_MI_DEVICE);
    }


    /* task main loop */
    while (TRUE)
    {
        vmf_ret_t   rec_len=0;
        unsigned16  total_len=0;
        unsigned16  rx_cs=0;
        unsigned16  calc_cs=0;

        /* sync */
        rec_len =nw_mi_read_device( mi_fp, &(rx_msg.token0), sizeof(rx_msg.token0));
        if (rec_len != sizeof(rx_msg.token0))
        {
            continue;
        }
        if (START_TOKEN == rx_msg.token0)
        {
            vmf_connected = TRUE;
            /* send filter response to gw to allow gateway to register trace clients */
            (void)vmf_trace_handle_filter_req(mi_cid,&vmf_trace_shm);
            (void)vmf_trace_send_filter_request(mi_cid);
            (void)vmf_trace_send_info_resp(mi_cid, VS_MICRO_CORE_M4);   /* send sysinfo-response for both cores */
            (void)vmf_trace_send_info_resp(mi_cid, VS_MICRO_CORE_A5);
            continue;
        }
        else if (rx_msg.token0 != VALID_TOKEN0)
        {
            continue;
        }
        total_len = 1;

        /* sync token 1 */
        rec_len =nw_mi_read_device( mi_fp, &(rx_msg.token1), sizeof(rx_msg.token1));
        if (rec_len != sizeof(rx_msg.token1))
        {
            MI_WARNING("nw_mi_read_device","nw_mi_read_device() failed - returned number of bytes=%d",rec_len);
            continue;
        }
        if (rx_msg.token0 != VALID_TOKEN0)
        {
            MI_WARNING("sync","sync token 2 invalid");
            continue;
        }
        total_len++;

        /* sync received */
        /* get remaining transfer header */
        remaining_header_len = sizeof(nw_vmf_mi_transfer_v2_header_t) - sizeof(rx_msg.token0) - sizeof(rx_msg.token1);
        rec_len=nw_mi_read_device( mi_fp, &(rx_msg.version_l), remaining_header_len);
        if (rec_len != remaining_header_len)
        {
            MI_WARNING("nw_mi_read_device","nw_mi_read_device() failed - returned number of bytes=%d",rec_len);
            continue;
        }
        total_len+=remaining_header_len;

        MI_INFO_1("nw_mi_read_device","try to read payload, len = %d bytes",rx_msg.svmf_len);

        /* get embedded vmf message */
        if (rx_msg.svmf_len >  sizeof(rx_msg.svmf_msg))
        {
            MI_WARNING("msg-len","vmf message len to big len=%d, buffer_len=%d",rx_msg.svmf_len,sizeof(rx_msg.svmf_msg));
            continue;
        }
        rec_len=nw_mi_read_device( mi_fp, &(rx_msg.svmf_msg), rx_msg.svmf_len);
        if (rec_len != rx_msg.svmf_len)
        {
            continue;
        }
        total_len+=rec_len;

        MI_INFO_1("nw_mi_read_device","got payload, len = %d bytes",rec_len);

        /* calc and test cs */
        calc_cs =  ((rx_msg.csum_h) * 256) + rx_msg.csum_l;
        rx_cs = (rx_msg.csum_h * 256) + rx_msg.csum_l;
        if (rx_cs != calc_cs)
        {
            /* cs error */
            continue;
        }

#ifdef VMF_MI_ENABLE_COMPRESSION
        if (COMP_MI_LZWR3 == rx_msg.comp)
        {
            /* uncompress data */
            unsigned16  unpack_len=0;

            unpack_len = vmf_mi_decomp_lzrw3((unsigned8*)&(rx_msg.svmf_msg), rx_msg.svmf_len, (unsigned8*)&(rx_msg.svmf_msg), sizeof(rx_msg.svmf_msg));
            if (0 == unpack_len)
            {
                MI_ERROR("vmf_mi_decomp_lzrw3","vmf_mi_decomp_lzrw3() failed");
            }
        }
#endif

        if (rx_msg.svmf_msg.pl_len > VMF_PL_LEN_MAX)
        {
            /* ignore */
            continue;
        }

        vmf_connected = TRUE;

        /* handle some messages and send unhadled messages to VMF  */
        if (TRUE == vmf_handle_vmf_in_messages(&rx_msg.svmf_msg))
        {
            vmf_ret = nw_vmf_send( mi_cid, &rx_msg.svmf_msg);
            if (vmf_ret != VMF_OK)
            {
                MI_ERROR("nw_vmf_send","nw_vmf_send() failed");
            }
        }
    }

    MI_ERROR("task","TASK ended");
    vmf_mi_close(mi_fp);

}






/**************************************************************************//**
 *
 *   Function Name: vmf_mi_init()
 *
 *   Description:   init function
 *
 *   Parameters:    NOT USED
 *
 *   Return value:  void
 *
 ******************************************************************************/
static void vmf_mi_init(void)
{
}




/**************************************************************************//**
 *
 *   Function Name: vmf_mi_open()
 *
 *   Description:   open the vmf_mi device
 *
 *   Parameters:
 *   \param         device name[input]
 *
 *   Return value:  file handle or NULL
 *
 ******************************************************************************/
static FILE * vmf_mi_open(char *devname)
{
    FILE * fp=NULL;
    _mqx_uint   flags=0;

    _io_fclose(stdout);     /* I know ... but I have to get rid of the echo and Xon/Xoff */
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
    flags = IO_SERIAL_RAW_IO | IO_SERIAL_NON_BLOCKING;
#else
    flags = IO_SERIAL_RAW_IO;
#endif
    fp = _io_fopen(VMF_MI_DEVICE, (char *)flags);
    return fp;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mi_close()
 *
 *   Description:   close the vmf_mi device
 *
 *   Parameters:
 *   \param         device handle[input]
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static void vmf_mi_close(FILE *fp)
{
    vmf_ret_t ret_val = VMF_ERROR;

    if (NULL == fp)
    {
        /* already closed */
        return;
    }

    fclose(fp);
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mi_send()
 *
 *   Description:   send a raw buffer
 *
 *   Parameters:
 *   \param         data-buffer[input]
 *   \param         number of bytes[input]
 *
 *   Return value:  \return number of bytes writte
 *
 ******************************************************************************/
static vmf_ret_t nw_mi_write_device(FILE *fp, unsigned8 *data,unsigned16 data_len)
{
    vmf_ret_t ret_val = VMF_ERROR;
    int cnt;

    #ifdef POLLING_UART
    for (cnt=0;cnt<data_len;cnt++)
    {
        ret_val = fwrite(&data[cnt],sizeof(unsigned8),1,fp);
        nw_sleep_ms(0); // yield
    }
    ret_val = data_len;
    #else
    ret_val = fwrite(data,sizeof(unsigned8),data_len,fp);
    #endif
    return ret_val;
}






/**************************************************************************//**
 *
 *   Function Name: vmf_mi_send()
 *
 *   Description:   send a raw buffer
 *
 *   Parameters:
 *   \param         data-buffer[input]
 *   \param         number of bytes to receive[input]
 *   \param         number of bytes received[output]
 *
 *   Return value:  \return number of bytes received or vmf_error_t
 *
 ******************************************************************************/
static vmf_ret_t nw_mi_read_device( FILE *fp, unsigned8 *data, unsigned16 num_bytes)
{
    vmf_ret_t   ret_val = VMF_ERROR;
    int         sum =0;
    while(sum < num_bytes)
    {
//        ret_val = fread(&data[sum],sizeof(unsigned8),num_bytes-sum,stdin);
        ret_val = fread(&data[sum],sizeof(unsigned8),1,stdin);
        if (ret_val > 0)
        {
            sum += ret_val;
            nw_sleep_ms(0);
        }
        else
        {
            nw_sleep_ms(0);
        }
    }

    return sum;
}





#ifdef VMF_MI_ENABLE_COMPRESSION

/**************************************************************************//**
 *
 *   Function Name: vmf_mi_decomp_lzrw3()
 *
 *   Description:   decompress lzrw3 compressed data
 *
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
static unsigned16 vmf_mi_decomp_lzrw3(unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned32 l_st_buff_len=dest_buff_len;

    if (NULL == p_unpack)
    {
        struct compress_identity *p_identity;

        lzrw3_compress(COMPRESS_ACTION_IDENTITY,NULL,NULL,0,NULL,&p_identity);
        p_unpack = nw_os_malloc(p_identity->memory);
        if (NULL == p_unpack)
        {
            return false;
        }
    }
    lzrw3_compress(COMPRESS_ACTION_DECOMPRESS,p_unpack,psrc, src_len,pdest,&l_st_buff_len);

    return l_st_buff_len;
}

/**************************************************************************//**
 *
 *   Function Name: vmf_mi_comp_lzrw3()
 *
 *   Description:   compress data with lzrw3
 *
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
static unsigned16 vmf_mi_comp_lzrw3(unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned32 l_st_buff_len=dest_buff_len;

    if (NULL == p_pack)
    {
        struct compress_identity *p_identity;

        lzrw3_compress(COMPRESS_ACTION_IDENTITY,NULL,NULL,0,NULL,&p_identity);
        p_pack = nw_os_malloc(p_identity->memory);
        if (NULL == p_pack)
        {
            return false;
        }
    }

    lzrw3_compress(COMPRESS_ACTION_COMPRESS,p_pack,psrc, src_len,pdest,&l_st_buff_len);

    return l_st_buff_len;
}

#endif

/**************************************************************************//**
 *
 *   Function Name: vmf_mi_calc_cs()
 *
 *   Description:   calculate the checksum of the given buffer
 *                  the checksum is calculated by adding eache byte in the buffer
 *                  an overflow is igneored
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *
 *   \return        checksum
 *
 ******************************************************************************/
static unsigned16 vmf_mi_calc_cs(unsigned8 *psrc, unsigned16 len)
{
        unsigned16  cs=0;
        unsigned16  cnt=0;

        for (cnt=0;cnt<len;cnt++)
        {
            cs += psrc[cnt];
        }
        return cs;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_decode_ctrl()
 *
 *   Description:   decode a vmf trace control message
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_decode_trace_ctrl(vmf_trace_shm_t* p_shm, vmf_msg_t *p_vmf_msg)
{
    vmf_trace_ctrl_pl_t *pctrl_pl=NULL;
    vmf_ret_t           vmf_ret=VMF_OK;

    pctrl_pl = NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg);

    switch (NW_VMF_BASIC_MSG_EVENT(p_vmf_msg))
    {
        case VMF_TRACE_CTRL_FILTER_SET:
        {
            unsigned8   trid;                   /* trace id or 0x00 for all Trace-Tasks */
            unsigned8   severity;               /* trace only messages with a severity >=  */
            unsigned8   trace_active;           /* 0x01 if trace for this trace_sif is enabled */

            trid = pctrl_pl->u.flt_severity.trid;
            severity = pctrl_pl->u.flt_severity.severity;
            trace_active = pctrl_pl->u.flt_severity.trace_active;
            vmf_ret = vmf_trace_filter(trid,severity,trace_active);
            MI_INFO ("vmf_trace_filter","VMF_TRACE_CTRL_FILTER_SET trid=%d, severity=%d, trace_active=%d, ret=%d",trid,severity,trace_active,vmf_ret);
        }
        break;

        case VMF_TRACE_CTRL_REQ_CONN_NAMES:
        {
            vmf_ret = nw_vmf_register_spy(mi_cid);  /* this will send all process names  */

        }
        break;

        case VMF_TRACE_CTRL_CONNECTION_NAMES:
        {
            MI_INFO("VMF_TRACE_CTRL_CONNECTION_NAMES","VMF_TRACE_CTRL_CONNECTION_NAMES %s",NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            vmf_ret = false;

        }
        break;

        case VMF_TRACE_CTRL_FILTER_REQ:
        {
            /* send filter response */
            MI_INFO("VMF_TRACE_CTRL_FILTER_REQ","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_FILTER_REQ");
            vmf_ret= vmf_trace_handle_filter_req(mi_cid,p_shm);
        }
        break;

        case VMF_TRACE_DOWNLOAD_REQUEST:
            /* this is part of the VMF-Download protocol */
            /* forward this message to the DAB_SPI task */
            os_message_send(TASK_DAB_SPI,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
        break;

        default:
        /* ignore */
        break;
    }
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_decode_sysinfo_ctrl()
 *
 *   Description:   decode a vmf sysinfo control message
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_decode_sysinfo_ctrl(vmf_trace_shm_t* p_shm, vmf_msg_t *p_vmf_msg)
{
    BOOL                bret=FALSE;
    vmf_ret_t           vmf_ret=VMF_OK;

    MI_INFO("SYSINFO_CTRL","entry");

    bret = FALSE;
    switch (NW_VMF_BASIC_MSG_EVENT(p_vmf_msg))
    {
        case VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ:
        #ifdef PROFILE_A5
        {
            vmf_sysinfo_pid_name_req_pl_t *ptr;
            MI_INFO("SYSINFO_CTRL","VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ");

            ptr = (vmf_sysinfo_pid_name_req_pl_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            if (SYSINFO_ALL_PIDS == ptr->pid)
            {
                /* send all pids */
                vmf_ret = vmf_sysinfo_send_all_process_names(mi_cid);
            }
            else if (SYSINFO_UPDATE_PIDS == ptr->pid)
            {
                /* send only updated pids */
                vmf_ret = vmf_sysinfo_send_updated_process_names(mi_cid);
            }
            else
            {   /* send only this pid */
                vmf_ret = vmf_sysinfo_send_process_name(mi_cid, (pid_t)ptr->pid);
            }
        }
        #else
        {
            /* send message to other core */
            os_message_send(TASK_VMF_MCC_M4,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(p_vmf_msg)),p_vmf_msg);
        }
        #endif
        break;

        case VMF_SYSINFO_CTRL_PROFILER_START:
        {
            #ifdef PROFILE_A5
            vmf_sysinfo_start_req_pl_t *ptr;
            ptr = (vmf_sysinfo_start_req_pl_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            vmf_profiler_install(ptr->int_time);
            #else
            /* send message to other core */
            os_message_send(TASK_VMF_MCC_M4,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(p_vmf_msg)),p_vmf_msg);
            #endif
        }
        break;

        case VMF_SYSINFO_CTRL_PROFILER_STOP:
        {
            /* de-install the isr */
            vmf_profiler_install(0);
            /* send message to other core */
            os_message_send(TASK_VMF_MCC_M4,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(p_vmf_msg)),p_vmf_msg);
        }
        break;

        case VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ:
        {
            #ifdef PROFILE_A5
            MI_INFO("SYSINFO_CTRL","VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ");
            vmf_ret = vmf_sysinfo_get_requested_pids((unsigned8 *)NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            #else
            /* send message to other core */
            os_message_send(TASK_VMF_MCC_M4,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(p_vmf_msg)),p_vmf_msg);
            #endif
        }
        break;

        case VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ:
        {
            MI_INFO("SYSINFO_CTRL","VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ");
            vmf_sysinfo_get_requested_pids(NULL);

            /* send message to other core */
            os_message_send(TASK_VMF_MCC_M4,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(p_vmf_msg)),p_vmf_msg);
        }
        break;

        case VMF_SYSINFO_CTRL_TARGET_INFO_REQ:
        {
            /* info request */
            vmf_sysinfo_ctrl_target_info_req_pl_t   *ptr;

            MI_INFO("SYSINFO_CTRL","VMF_SYSINFO_CTRL_TARGET_INFO_REQ");
            ptr = (vmf_sysinfo_ctrl_target_info_req_pl_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));

            vmf_ret = vmf_trace_handle_info_req(mi_cid,ptr);
        }
        break;


        case VMF_SYSINFO_CTRL_TARGET_ID_SET:
        {
            vmf_sysinfo_ctrl_target_id_set_t *ptr;

            MI_INFO("SYSINFO_CTRL","VMF_SYSINFO_CTRL_TARGET_ID_SET");
            ptr = (vmf_sysinfo_ctrl_target_id_set_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));

            vmf_ret = vmf_trace_handle_target_id_set(mi_cid,ptr);
        }
        break;

        default:
            MI_WARNING("default","VMF_TRACE_SYSINFO_CTRL invalid cmd=%d",NW_VMF_BASIC_MSG_EVENT(p_vmf_msg));
            /* ignore */
        break;

    }
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_handle_target_id_set()
 *
 *   Description:   set new target id
 *
 *   Parameters:    cid
 *                  taget info payload
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_handle_target_id_set(vmf_cid_t cid, vmf_sysinfo_ctrl_target_id_set_t* ptr)
{
    unsigned16  target_id;
    vmf_ret_t   ret=VMF_OK;

    /* is this message for me ?*/
    if (strncmp(ptr->target_name,VMF_PROFILER_TARGET_NAME,TARGET_NAME_LEN) != 0)
    {
        /* not for me */
        MI_INFO("SYSINFO_CTRL","message for different target =%s",ptr->target_name);
        return ret;
    }
    /* compare core */
    if (strncmp(ptr->target_name,VMF_PROFILER_CORE_NAME_M4,CORE_NAME_LEN)==0)
    {
        /* M4 */
        MI_INFO("SYSINFO_CTRL"," set new target-id for M4 =%d",ptr->target_id);
        vmf_target_id_m4 = ptr->target_id;
    }
    else
    {
        /* A5 */
        MI_INFO("SYSINFO_CTRL"," set new target-id for A5 =%d",ptr->target_id);
        vmf_target_id_a5 = ptr->target_id;
    }

    return ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_handle_info_req()
 *
 *   Description:   handle VMF_SYSINFO_CTRL_TARGET_INFO_REQ
 *
 *   Parameters:    cid
 *                  taget info payload
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_handle_info_req(vmf_cid_t cid, vmf_sysinfo_ctrl_target_info_req_pl_t* ptr)
{
    unsigned16  target_id;
    vmf_ret_t   ret;

    MI_INFO("SYSINFO_CTRL","entry");

    if (NULL == ptr)
    {
        MI_ERROR("SYSINFO_CTRL","ptr == NULL");
        return VMF_ERR_NULL_POINTER;
    }
    target_id = ptr->target_id;

    if (target_id == vmf_target_id_a5)
    {
        /* M4 or all targets */
        ret = vmf_trace_send_info_resp(cid, VS_MICRO_CORE_A5);
    }

    if (target_id == vmf_target_id_m4)
    {
        /* M4 or all targets */
        ret = vmf_trace_send_info_resp(cid, VS_MICRO_CORE_M4);
    }

    return ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_info_req()
 *
 *   Description:   send VMF_SYSINFO_CTRL_TARGET_INFO_RESP
 *
 *   Parameters:    cid
 *                  target_id
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_send_info_resp(vmf_cid_t cid, unsigned16 core)
{

    vmf_ret_t ret = VMF_OK;
    VMF_VAR_MSG_TYP(sizeof(vmf_sysinfo_data_target_info_resp_pl_t)) vmf_basic_msg;
    vmf_sysinfo_data_target_info_resp_pl_t  *pl=NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg);

    MI_INFO("SYSINFO_CTRL","entry");

    /* set payload */
    pl->version = VMF_PROFILER_NS_VERSION;
    pl->fill = 0;


    strncpy(pl->target_name,VMF_PROFILER_TARGET_NAME,sizeof(pl->target_name));

    if (VS_MICRO_CORE_A5 == core )
    {
        strncpy(pl->core_name,VMF_PROFILER_CORE_NAME_A5,sizeof(pl->core_name));
        pl->target_id = vmf_target_id_a5;
    }
    else
    {
        strncpy(pl->core_name,VMF_PROFILER_CORE_NAME_M4,sizeof(pl->core_name));
        pl->target_id = vmf_target_id_m4;
    }

    pl->vmf_version = SVMF_VERSION;
    pl->bit_mask = BIT_SVMF | BIT_MEM  | BIT_LOAD;

    /* prepare payload*/
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = VMF_TRACE_SYSINFO_DATA;
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = VMF_SYSINFO_DATA_TARGET_INFO_RESP;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = sizeof(vmf_sysinfo_data_target_info_resp_pl_t);

    /* send data to VMF */
    ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_basic_msg);
    if(ret < 0)
    {
        MI_ERROR("SYSINFO_CTRL","vmf_sysinfo_send_name_resp(): nw_vmf_send_basic() failed");
    }

    return ret;
}

/**************************************************************************//**
 *
 *   Function Name: vmf_handle_vmf_in_messages(void)
 *
 *   Description:   set the trave filter for a trace client
 *
 *   Parameters:    vmf_msg
 *
 *   Function Return value: - true if message has to be forwarded to VMF
 *
 ******************************************************************************/
BOOL vmf_handle_vmf_in_messages(vmf_msg_t *p_vmf_msg)
{
    BOOL            bret = TRUE;
    vmf_ret_t       vmf_ret;
    vmf_trace_ctrl_pl_t *ptrace_ctrl=NULL;

    if (NW_VMF_BASIC_MSG_TYPE(p_vmf_msg) != SVMF_BASIC_MSG)
    {
        /* only send basic messages to router */
        return FALSE;
    }

    /* message is a basic message */
    switch(NW_VMF_BASIC_MSG_GROUP(p_vmf_msg))
    {
        case VMF_TRACE_CTRL:
        {
            vmf_ret = vmf_trace_decode_trace_ctrl(&vmf_trace_shm, p_vmf_msg);
            bret = TRUE;   /* forward message to vmf */
        }
        break;

        case VMF_TRACE_SYSINFO_CTRL:
        {
            vmf_ret = vmf_trace_decode_sysinfo_ctrl(&vmf_trace_shm, p_vmf_msg);
            bret = TRUE;   /* forward message to vmf */
        }
        break;

        case VMF_DYN_0:
        /* no break */
        case DAB_SPI_TASK_IN:
        {
            /* forward message to DAB_SPI_TASK */
            os_message_send(TASK_DAB_SPI,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            bret = FALSE;   /* no need to forward message to vmf */
        }
        break;

        case DAB_TASK_IN:
        {
            /* forward message to DAB Task*/
            os_message_send(TASK_DAB,NW_VMF_BASIC_MSG_EVENT(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_LENGTH(p_vmf_msg),NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
            bret = FALSE;   /* no need to forward message to vmf */
        }
        break;

        default:
            /* foward message to VMF */
            bret = TRUE;
            break;

    }
    return bret;
}
#endif



#if ( VS_MICRO_CORE_A5 == VS_MICRO_CORE )
 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_filter_response()
 *
 *   Description:   send a trace filters of a single trace client to the windows client
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     trid        filters response of this client is send
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_send_filter_response(vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret=VMF_OK;

    // if (strlen(p_shm->task[trid].name) > 0)
    {
        vmf_trace_ctrl_pl_t pl;
        unsigned16 len;

        pl.u.flt_response.severity    = p_shm->task[trid].severity;
        pl.u.flt_response.trid        = trid;
        pl.u.flt_response.trace_active= p_shm->task[trid].trace_active;
        strncpy(pl.u.flt_response.name,p_shm->task[trid].name,MAX_TRACE_NAME_LEN);
        pl.u.flt_response.name[MAX_TRACE_NAME_LEN] = 0;     /* set string delimiter */
                                                            /* length of .name is MAX_TRACE_NAME_LEN+1 */
        len = sizeof(vmf_trace_ctrl_filter_response_t); // - MAX_TRACE_NAME_LEN + strlen(pl.u.flt_response.name) +1;

        /* transfer this filter to the client */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_RESP,&pl,len);
        if (VMF_OK != vmf_ret)
        {
            MI_ERROR("vmf_trace_send_ctrl","vmf_trace_send_ctrl() failed error = %d",vmf_ret);
        }
        else
        {
//            VMF_TRACE_INFO_PRINT("vmf_trace_server","vmf_trace_send_filter_response","send filter: trid-name=%s, severity=%d, trace_active=%d",pl.flt_response.name,pl.flt_response.severity,pl.flt_response.trace_active);
        }
    }
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_filter_request()
 *
 *   Description:   send a trace filters of a single trace client to the windows client
 *
 *   \param[in]     cid         tx client id
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_send_filter_request(vmf_client_id_t cid)
{
    vmf_ret_t           vmf_ret=VMF_OK;

    {
        vmf_trace_ctrl_pl_t pl;

        /* transfer this filter to the client */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_REQ,&pl,0);
        if (VMF_OK != vmf_ret)
        {
            MI_ERROR("vmf_trace_send_ctrl","vmf_trace_send_ctrl() failed error = %d",vmf_ret);
        }
        else
        {
//            VMF_TRACE_INFO_PRINT("vmf_trace_server","vmf_trace_send_filter_request","send filter: trid-name=%s, severity=%d, trace_active=%d",pl.flt_response.name,pl.flt_response.severity,pl.flt_response.trace_active);
        }
    }
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_handle_filter_req()
 *
 *   Description:   send trace filters of both cores to the windows client
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_handle_filter_req(vmf_client_id_t cid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret=VMF_OK;
    unsigned8           cnt;

    MI_INFO("vmf_trace_server","vmf_trace_handle_filter_req","enter function");
    if (NULL == p_shm)
    {
       MI_ERROR("arg-test","p_shm=NULL!");
        return VMF_ERR_NULL_POINTER;
    }

    /* send all current filters of both cores ! */
    for (cnt=1; cnt<MAX_VMF_TRACE_TRIDS ;cnt++)
    {
        if (p_shm->task[cnt].name[0] != 0)  /* in use ? */
        {
            vmf_ret = vmf_trace_send_filter_response(cid,cnt,p_shm);
        }
    }
    return vmf_ret;
}







#endif
