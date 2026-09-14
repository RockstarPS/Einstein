/***************************************************************************

  Module:               vmf_appendix.c
  Description:          connect mqx with the VMF framework to allow the used of the VMF tools

  Project Scope:        mqx

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar / mqx
  Target Hardware:      Any

*****************************************************************************/


#include "os_if.h"
#include "mqx_osal_if.h"

#include <mfs.h>
#include <mqx_inc.h>
#include <charq.h>
#include <stdlib.h>


#include "vmf.h"
#include "vmf_ipc.h"

#if ( VMF_CORE == VS_MICRO_CORE )

#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
#include "fb_comms_if.h"
#include "adc_if.h"
#include "gpio_if.h"
#include "test_device_eeprom_if.h"
#include "util_micro_regs_vybrid.h"
#endif
#include "lzrw3.h"


#define VMF_TRACE_SCOPE                 (char *)__PRETTY_FUNCTION__
#define VMF_DEBUG_PRINT(scope, ...)     VMF_TRACE_PRINTF(vmf_trace_svr_trid, 50, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define VMF_DEBUG_INFO(scope, ...)      VMF_TRACE_PRINTF(vmf_trace_svr_trid, VMF_TRACE_SEVERITY_INFO, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define VMF_DEBUG_WARNING(scope, ...)   VMF_TRACE_PRINTF(vmf_trace_svr_trid, VMF_TRACE_SEVERITY_WARNING, scope, VMF_TRACE_SCOPE, __VA_ARGS__);


static void vmf_mqx_router(uint_32 param);
static void vmf_tx_thread(uint_32 param);
static void vmf_rx_thread(uint_32 param);
static void vmf_rx_thread2(uint_32 param);
static BOOL start_vmf_transmitter(void);
static BOOL start_vmf_receiver(void);



char        servername[IPC_MAX_NAME_LEN];
unsigned8   vmf_trace_svr_trid=0;

/**************************************************************************//**
 *
 *   Function Name: shell_start_vappendix()
 *
 *   Description:   start the VMF appendix
 *
 *   Parameters:    void
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
BOOL vmf_mqx_start_appendix(void)
{

    BOOL bret = TRUE;

    #ifdef VMF_MQX
    /* use native mqx task */

    #define VMF_APP_TASK 1
    _task_id vmf_apptask_id;
    TASK_TEMPLATE_STRUCT mqx_vmfapp_template;

    mqx_vmfapp_template.TASK_TEMPLATE_INDEX = 1;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_mqx_router;
    mqx_vmfapp_template.TASK_NAME           = "TASK_VMF_ROUTER";
    mqx_vmfapp_template.CREATION_PARAMETER  = (uint_32)(0);
    mqx_vmfapp_template.TASK_STACKSIZE      = 4500;
    mqx_vmfapp_template.TASK_PRIORITY       = 7;
    mqx_vmfapp_template.CREATION_PARAMETER  = 0;
    mqx_vmfapp_template.DEFAULT_TIME_SLICE  = 5;
    mqx_vmfapp_template.TASK_ATTRIBUTES = MQX_TIME_SLICE_TASK;


    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }

    #else
    /* use OSAL */
    static os_task_create_t vmf_apptask = { 4500, 40, vmf_mqx_router, 0, FALSE };    /* stack, priority, cannback, arg, use_queue */
    static os_task_id_t     vmf_app_task_id;

    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask))
    {
        bret = FALSE;
    }
    #endif

    vmf_mi_mqx_create_thread(NULL);

    return bret;
}



/**************************************************************************//**
 *
 *   Function Name: start_vmf_receiver()
 *
 *   Description:   start the VMF receiver thread
 *
 *   Parameters:    void
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static BOOL start_vmf_transmitter(void)
{

    BOOL bret = TRUE;

    #ifdef VMF_MQX
    /* use native mqx task */

    #define VMF_APP_TASK 1
    _task_id vmf_apptask_id;
    static TASK_TEMPLATE_STRUCT mqx_vmfapp_template;

    mqx_vmfapp_template.TASK_TEMPLATE_INDEX = 1;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_tx_thread;
    mqx_vmfapp_template.TASK_NAME           = "A5TASK_VMF_TESTTX";
    mqx_vmfapp_template.CREATION_PARAMETER  = (uint_32)(0);
    mqx_vmfapp_template.TASK_STACKSIZE      = 4500;
    mqx_vmfapp_template.TASK_PRIORITY       = 7;
    mqx_vmfapp_template.CREATION_PARAMETER  = 0;
    mqx_vmfapp_template.DEFAULT_TIME_SLICE  = 5;
    mqx_vmfapp_template.TASK_ATTRIBUTES = MQX_TIME_SLICE_TASK;

    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }

    #else
    /* use OSAL */
    static os_task_create_t vmf_apptask = { 4500, 40, vmf_tx_thread, 0, FALSE };    /* stack, priority, cannback, arg, use_queue */
    static os_task_id_t     vmf_app_task_id;


    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask))
    {
        bret = FALSE;
    }
    #endif

    return bret;
}


/**************************************************************************//**
 *
 *   Function Name: start_vmf_receiver()
 *
 *   Description:   start the VMF receiver thread
 *
 *   Parameters:    void
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static BOOL start_vmf_receiver(void)
{

    BOOL bret = TRUE;

    #ifdef VMF_MQX
    /* use native mqx task */

    #define VMF_APP_TASK 1
    _task_id vmf_apptask_id;
    static TASK_TEMPLATE_STRUCT mqx_vmfapp_template;

    mqx_vmfapp_template.TASK_TEMPLATE_INDEX = 1;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_rx_thread;
    mqx_vmfapp_template.TASK_NAME           = "TASK_VMF_TESTRX";
    mqx_vmfapp_template.CREATION_PARAMETER  = (uint_32)(0);
    mqx_vmfapp_template.TASK_STACKSIZE      = 4500;
    mqx_vmfapp_template.TASK_PRIORITY       = 7;
    mqx_vmfapp_template.CREATION_PARAMETER  = 0;
    mqx_vmfapp_template.DEFAULT_TIME_SLICE  = 5;
    mqx_vmfapp_template.TASK_ATTRIBUTES = MQX_TIME_SLICE_TASK;

    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }

    #else
    /* use OSAL */
    static os_task_create_t vmf_apptask = { 4500, 40, vmf_rx_thread, 0, FALSE };    /* stack, priority, cannback, arg, use_queue */
    static os_task_id_t     vmf_app_task_id;


    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask))
    {
        bret = FALSE;
    }
    #endif




    return bret;
}




/**************************************************************************//**
 *
 *   Function Name: shell_vmf_app_thread()
 *
 *   Description:   VMF appendix thread
 *
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_mqx_router(uint_32 param)
{
    nw_vmf_router(0);
}



/**************************************************************************//**
 *
 *   Function Name: vmf_rec_thread()
 *
 *   Description:   VMF receiver thread
 *
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_tx_thread(uint_32 param)
{
    int i,j;
    vmf_client_id_t cid;
    vmf_ret_t       vmf_ret;
    vmf_msg_t       vmf_msg;
    void            *p_work;

    nw_sleep_ms(10);

    vmf_ret = vmf_trace_register(&vmf_trace_svr_trid,"vmf-app");
    if (vmf_ret < 0)
    {
        // VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_register failed - ret=%d\n",vmf_ret);
    }

    cid = nw_vmf_connect("tx_thread",NULL,0,5,400);
    if (cid <= 0)
    {
        return;
    }

    while(TRUE)
    {
        for (j=0;j<10;j++)
        {
            for (i=0;i<10;i++)
            {
                snprintf(vmf_msg.pl,sizeof(vmf_msg.pl),"%d_%d_test12345",i,j);
                vmf_msg.pl_len = strlen(vmf_msg.pl)+1;
                vmf_msg.group = 3;  // VMF_TRACE_IN;
                vmf_msg.event = 2;

                VMF_DEBUG_INFO("loop","%s",vmf_msg.pl);
                nw_sleep_ms(500);
            }
            VMF_DEBUG_WARNING("loop","%s",vmf_msg.pl);
            vmf_ret = nw_vmf_send( cid, &vmf_msg);
            if (vmf_ret != VMF_OK)
            {
                return;
            }
        }
    }
    nw_sleep_ms(10000);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_rx_thread()
 *
 *   Description:   VMF receiver thread
 *
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_rx_thread(uint_32 param)
{
    vmf_client_id_t cid;
    vmf_msg_t       vmf_msg;
    vmf_ret_t       ret_val;
    int             len;
    unsigned8       groups[]={1};


    cid = nw_vmf_connect("rx_thread1",NULL,0,5,sizeof(vmf_msg_t));
    if (cid <= 0)
    {
        return;
    }
    nw_vmf_register_msg_group(cid,sizeof(groups),groups);

    nw_sleep_ms(0);
    while (TRUE)
    {
        volatile unsigned8  src[1024]={0};
        volatile unsigned8  buffer[1024];
        volatile static     unsigned8   staticbuffer[1024];

        ret_val = nw_vmf_receive(cid,&vmf_msg,sizeof(vmf_msg));
        if (ret_val >0)
        {
            len = ret_val;
        }
        else
        {
            nw_sleep_ms(1);
            continue;
        }
        if (NW_VMF_BASIC_MSG_GROUP(&vmf_msg) != 1)
        {
            VMF_DEBUG_WARNING("nw_vmf_receive","received invalid message group=%d, event=%d",NW_VMF_BASIC_MSG_GROUP(&vmf_msg),NW_VMF_BASIC_MSG_EVENT(&vmf_msg));
            continue;   /* ignore */
        }

        /* do some load tests */
        if (NW_VMF_BASIC_MSG_EVENT(&vmf_msg) == 1)
        {
            unsigned32 i;
            for (i = 0; i<1000000;i++)
            {
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");
                asm("nop");         }
        }
        if (NW_VMF_BASIC_MSG_EVENT(&vmf_msg) == 2)
        {
            volatile unsigned32 start;
            volatile unsigned32 stop;
            unsigned32      i;

            start =  nw_os_cfg_get_ms_time();
            for (i=0; i<1000000;i++)
            {
                memcpy(buffer, src,128);
            }
            stop =  nw_os_cfg_get_ms_time();
            VMF_DEBUG_PRINT("memcpy","memcpy time 1 = %d",stop-start);
        }

        if (NW_VMF_BASIC_MSG_EVENT(&vmf_msg) == 3)
        {
            volatile unsigned32 start;
            volatile unsigned32 stop;
            unsigned32      i;

            start =  nw_os_cfg_get_ms_time();
            for (i=0; i<1000000;i++)
            {
                memcpy(staticbuffer, src,1000);
            }
            stop =  nw_os_cfg_get_ms_time();
            VMF_DEBUG_PRINT("memcpy","memcpy time 2 = %d",stop-start);
        }
    }

    nw_sleep_ms(10000);

}



#endif
