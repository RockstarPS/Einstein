
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

  \file                 nw_vmf_status_hander.c
  \brief                network status handler - only used when no external MOST

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/


/* MAIN SWITCH */
#ifndef NW_EXTERNAL_MOST_ENABLED
#define _NW_VMF_STAUS_HDLR


/* For unit testing functions must not be declared static! */
#ifdef UNIT_TEST
#warning "*************** UNIT_TEST ON! ********************"
#define NW_STATIC
#else
#define NW_STATIC static
#endif



/* system includes */
#include "nw_os_config.h"
#include "nw_vmf_cfg.h"           /* vmf cfg file */

#ifdef UNIT_TEST
#include "unit_test.h"
#else
#include "nw_vmf_debug.h"
#endif

/* application includes */
#include "nw_config.h"
#include "nw_vmf.h"
#include "nw_vmf_nw_status_handler.h"
#include "nw_most_defs.h"


#ifdef NW_IPM
#include "nw_ipm_protected.h"
#endif

/* macros */
#define VMF_NW_HANDLER_STACK_SIZE   VMF_NW_STACK_SIZE
#ifndef FOREVER
#define FOREVER                     (true)
#endif
#define WAIT_SOME_TIME              (10)            /* wait time in ms */
#define VMF_NW_STAT_QUEUE_SIZE      (100)           /* size of vmf receive queue */
#define MY_NAME                     "nw_status_handler"

/* local variables */
/* MOST process and VMF server available */
t_nw_msg_header nw_msg_header_list[/*NUM_MOST_PROC_VMF_MSG_GROUPS*/] = {
    RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK,
    RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK,
    RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE,
    RX_MSG_HEAD__SYSTEM_STARTUP_COMPLETE,
    #ifdef NW_IPM
    RX_MSG_HEAD__SYNC_ALLOCATE,
    RX_MSG_HEAD__SYNC_DEALLOCATE,
    RX_MSG_HEAD__SYNC_IN_CONNECT,
    RX_MSG_HEAD__SYNC_IN_DISCONNECT,
    RX_MSG_HEAD__SYNC_OUT_CONNECT,
    RX_MSG_HEAD__SYNC_OUT_DISCONNECT,
    #ifdef RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC
    RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC,
    #endif
    #endif
};

#define NUM_VMF_MSG_GROUPS (sizeof(nw_msg_header_list)/sizeof(t_nw_msg_header))
static unsigned8 groupid_list[NUM_VMF_MSG_GROUPS] = {};

static unsigned8 nm_config_status = MOST_CFG_STATUS_NOTOK;

/* global variabled */
static unsigned8                    ipmMostGenNumber=0;
static bool                         bSystemStartupComplete=false;
static vmf_stat_hdlr_cent_reg_t     my_cr;          /* local central registry */
        vmf_client_id_t             vmf_client_id;


/* local function declarations */
NW_STATIC void              *vmf_nw_status_handler                      (void *pArg);
NW_STATIC vmf_client_id_t   vmf_nw_status_create_connection             (void);
NW_STATIC vmf_ret_t         vmf_nw_status_register_groups               (vmf_client_id_t vmf_client_id);
NW_STATIC vmf_ret_t         vmf_nw_status_message_handler               (vmf_client_id_t vmf_client_id,vmf_msg_t   *pvmf_msg);
NW_STATIC inline vmf_ret_t  vmf_nw_status_basic_message_handler         (vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg);
NW_STATIC inline vmf_ret_t  vmf_nw_status_most_message_handler          (vmf_client_id_t vmf_client_id,vmf_most_msg_t *pvmf_msg);
NW_STATIC inline vmf_ret_t  vmf_nw_status_reg_operation_handler         (vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg);
NW_STATIC inline vmf_ret_t  vmf_nw_status_network_regopraddcomp_handler (vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg);
NW_STATIC inline vmf_ret_t  vmf_nw_status_network_regoprdelcomp_handler (vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg);
NW_STATIC inline bool       vmf_nw_status_init(void);

NW_STATIC inline bool       vmf_nw_status_tx_dev_count                  (vmf_client_id_t vmf_client_id,unsigned8 devcount);
NW_STATIC inline bool       vmf_nw_status_tx_mstmodcomdisc              (vmf_client_id_t vmf_client_id);
NW_STATIC inline bool       vmf_nw_status_tx_mstmodcomcon               (vmf_client_id_t vmf_client_id);
NW_STATIC inline bool       vmf_nw_status_tx_own_devid                  (vmf_client_id_t vmf_client_id,unsigned16 devid);
NW_STATIC inline bool       vmf_nw_status_tx_reg_update                 (vmf_client_id_t vmf_client_id,vmf_stat_hdlr_cent_reg_t *pcr);

NW_STATIC bool              vmf_nw_status_tx_first_status_events        (vmf_client_id_t vmf_client_id);
NW_STATIC bool              vmf_nw_status_tx_status_events              (vmf_client_id_t vmf_client_id);

NW_STATIC inline            unsigned8 nw_vmf_inc_and_get_most_gen_number(void);
NW_STATIC inline            unsigned8 nw_vmf_get_most_gen_number        (void);

NW_STATIC bool              vmf_nw_status_cr_init       (vmf_stat_hdlr_cent_reg_t *pcr);
NW_STATIC bool              vmf_nw_status_cr_del_entry  (vmf_stat_hdlr_cent_reg_t *pcr,unsigned16 devid,unsigned8 fblockid,unsigned8 instid);
NW_STATIC bool              vmf_nw_status_cr_add_entry  (vmf_stat_hdlr_cent_reg_t *pcr,unsigned16 devid,unsigned8 fblockid,unsigned8 instid);
NW_STATIC bool              vmf_nw_status_check_entry   (vmf_stat_hdlr_cent_reg_t *pcr,unsigned16 devid,unsigned8 fblockid,unsigned8 instid);

/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_create_thread
 *
 *   Description:   create the nw-status Handler Task
 *
 *   \param         void
 *   \return        bool - true if OK
 *
 ******************************************************************************/
bool vmf_nw_status_create_thread(void)
{
    pthread_t th;
    pthread_attr_t  attr;
    int iRet;

    NW_VMF_STAT_DEBUG(3,"mf_nw_status_create_thread()\n");

    /* set thread stack */
    pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_NW_HANDLER_STACK_SIZE ) != 0 )
    {
        NW_VMF_STAT_DEBUG(0,"%s:, mf_nw_status_create_thread() - pthread_attr_setstacksize() failed",MY_NAME);
    }

/* jmerkle      pthread_attr_setstacklazy(&attr,PTHREAD_STACK_LAZY); */

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, vmf_nw_status_handler, NULL);
    pthread_attr_destroy(&attr);
    if (iRet)
    {
        NW_VMF_STAT_DEBUG(0,"%s: mf_nw_status_create_thread() error! errno = %d\n",MY_NAME,iRet);
        return false;
    }

    #ifdef QNX
    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf NW_STAUS handler */
    if ( pthread_setname_np(th, "nw vmf NW_STAUS handler thread") != EOK)
    {
        NW_VMF_STAT_DEBUG(1,"%s:Unable to name nw vmf NW_STAUS handler thread\n",MY_NAME);
    }
    #endif
    #endif

    NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_create_thread() OK\n",MY_NAME);
    return true;

}


/**************************************************************************//**
 *
 *   Function Name: my_trhread_vmf_client_id_get(void)
 *
 *   Description:   returns current vmf client id
 *
 *   \param         void
 *   \return        vmf_client_id_t
 *
 ******************************************************************************/
vmf_client_id_t my_trhread_vmf_client_id_get(void)
{
    return(vmf_client_id);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_handler(uint32_T ulContext)
 *
 *   Description:   nw_status handler thread
 *
 *   \param         void
 *   \return        void
 *
 ******************************************************************************/
NW_STATIC void *vmf_nw_status_handler(void *pNoArg)
{
    vmf_ret_t           vmf_ret=VMF_OK;
    signed16            numBytes;
    static VMF_VAR_MSG_TYP(VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD)   vmf_msg;

    if (!vmf_nw_status_init())
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_handler() init failed\n",MY_NAME);
        return(NULL);         /* stop thread */
    }

    /* try to connect to vmf-server        */
    /* wait until vmf server is accessible */
    while (FOREVER)
    {
        vmf_client_id = vmf_nw_status_create_connection();
        if (vmf_client_id < 0)
        {
            /* retry if there was an error */
            NW_VMF_STAT_DEBUG(3,"%s: Can not register vmf connection\n",MY_NAME);
            delay(WAIT_SOME_TIME);
        }
        else
        {
            /* connection established */
            break;
        }
    }

    /* register to message groups */
    vmf_ret = vmf_nw_status_register_groups(vmf_client_id);
    if (vmf_ret < 0)
    {
        /* exit thread */
        NW_VMF_STAT_DEBUG(0,"%s: terminating thread\n",MY_NAME);
    }

    /* register NETWORK_MASTER FBlockId to vmf server */
    vmf_ret = nw_vmf_register_most_fblock  (vmf_client_id, MOST_FBLOCK_NETWORKMASTER, 0);
    if (vmf_ret < 0)
    {
        /* exit thread */
        NW_VMF_STAT_DEBUG(0,"%s: reg FBlcokId 0x02 failed\n",MY_NAME);
    }

    /* receive messages forever*/
    while (FOREVER)
    {
        numBytes = nw_vmf_receive (vmf_client_id,(vmf_msg_t *)&vmf_msg,sizeof(vmf_msg));
        if (numBytes <= 0)
        {
            /* exit thread */
            NW_VMF_STAT_DEBUG(2,"%s: nw_vmf_receive returned <=0 - ret=%d\n",MY_NAME,numBytes);
            delay(WAIT_SOME_TIME);
        }
        else
        {
            /* message received */
            vmf_ret=vmf_nw_status_message_handler(vmf_client_id,(vmf_msg_t*)&vmf_msg);
        }
    }
    
    return(NULL);
}




/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_message_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for vmf messages
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_nw_status_message_handler(vmf_client_id_t vmf_client_id,vmf_msg_t *pvmf_msg)   /**< IN vmf message */
{
    vmf_ret_t           vmf_ret=VMF_ERROR;

    if (NULL == pvmf_msg)
    {
        NW_VMF_STAT_DEBUG(0,"vmf_nw_status_message_handler: NULL pointer (vmf message)!\n");
        return VMF_ERR_NULL_POINTER;
    }

    /* distinguish between different message types */
    switch (pvmf_msg->vmf_most_msg.msg_base.base.msg_type)
    {
        case MSG_TYPE_MOST_MESSAGE:
            /* received a MOST message */
            vmf_ret = vmf_nw_status_most_message_handler(vmf_client_id,(vmf_most_msg_t *)pvmf_msg);
        break;

        case MSG_TYPE_BASIC_MESSAGE:
            /* received a basic message */
            vmf_ret = vmf_nw_status_basic_message_handler(vmf_client_id,(vmf_basic_msg_t*)pvmf_msg);
        break;


        default:
            /* control or other data that not be receied here !*/
            /* invalid here                                    */
            vmf_ret = VMF_ERROR;
        break;
    }
    return(vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_basic_message_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for vmf basic messages
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC inline vmf_ret_t vmf_nw_status_basic_message_handler(vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg)   /**< IN vmf basic message */
{
    vmf_ret_t vmf_ret = VMF_OK;
    t_nw_msg_header header;

    /* NULL pointer check not necessary since it is done above in vmf_nw_status_message_handler ! */

    header = BUILD_NW_MSG_HEADER(pvmf_msg->msg_base.id.group,pvmf_msg->msg_base.id.event);

    /* distinguish between different message groups */
    switch (header)
    {
        /* received a MOST FBlock registration event */

        case RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK\n");
            vmf_ret = vmf_nw_status_reg_operation_handler(vmf_client_id,pvmf_msg);
            break;

        case RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK\n");
            vmf_ret = vmf_nw_status_reg_operation_handler(vmf_client_id,pvmf_msg);
            break;

        case RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE\n");
            vmf_ret = vmf_nw_status_reg_operation_handler(vmf_client_id,pvmf_msg);
            break;

        case RX_MSG_HEAD__SYSTEM_STARTUP_COMPLETE:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYSTEM_STARTUP_COMPLETE\n");
                /* store that startup is complete */
            bSystemStartupComplete = true;
            break;

/* MOST synchronous request for audio video purposes */
#ifdef NW_IPM
        #ifdef RX_MSG_HEAD__SYNC_ALLOCATE
        case RX_MSG_HEAD__SYNC_ALLOCATE:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_ALLOCATE\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_DEALLOCATE
        case RX_MSG_HEAD__SYNC_DEALLOCATE:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_DEALLOCATE\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_IN_CONNECT
        case RX_MSG_HEAD__SYNC_IN_CONNECT:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_IN_CONNECT\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_IN_DISCONNECT
        case RX_MSG_HEAD__SYNC_IN_DISCONNECT:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_IN_DISCONNECT\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_OUT_CONNECT
        case RX_MSG_HEAD__SYNC_OUT_CONNECT:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_OUT_CONNECT\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_OUT_DISCONNECT
        case RX_MSG_HEAD__SYNC_OUT_DISCONNECT:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_OUT_DISCONNECT\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif

        #ifdef RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC
        case RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC:
            NW_VMF_STAT_DEBUG(5,"vmf_nw_status_basic_message_handler: RX_MSG_HEAD__SYNC_MLB_CHANNEL_SYNC\n");
            nw_ipm_void_process_fw_request((vmf_msg_t*)pvmf_msg);
            break;
        #endif
#endif /* NW_IPM */

        default:
            /* invalid data received - ignore !*/
            vmf_ret=VMF_ERROR;
        break;
    }

    return(vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_most_message_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for vmf most messages
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_nw_status_most_message_handler(vmf_client_id_t vmf_client_id, vmf_most_msg_t *pvmf_msg)   /**< IN vmf most message */
{
    if(VMF_MOST_MSG_FBLOCKID(pvmf_msg) != MOST_FBLOCK_NETWORKMASTER)
    {
        /* should never happen */
        return(VMF_ERROR);
    }

    if(VMF_MOST_MSG_INSTID(pvmf_msg) != 0)
    {
        NW_VMF_STAT_DEBUG(0,"vmf_nw_status_most_message_handler: invalid InstID\n");

        /* send invalid instId */
        vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
        vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

        VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
        VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
        VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
        VMF_MOST_MSG_INSTID(pmsg)        = VMF_MOST_MSG_INSTID(pvmf_msg);
        VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
        VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_ERR_OPTYPE;
        VMF_MOST_MSG_DATA_LENGTH(pmsg)   = 1;
        VMF_MOST_MSG_PTR_TO_DATA(pmsg)[0]= MOST_ERR_INSTID;

        (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
        return(VMF_OK);
    }

    if(VMF_MOST_MSG_OPTYPE(pvmf_msg) != MOST_OP_GET)
    {
        NW_VMF_STAT_DEBUG(0,"vmf_nw_status_most_message_handler: invalid OpType\n");

        /* send invalid op type */
        vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
        vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

        VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
        VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
        VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
        VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
        VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
        VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_ERROR;
        VMF_MOST_MSG_DATA_LENGTH(pmsg)   = 2;
        VMF_MOST_MSG_PTR_TO_DATA(pmsg)[0]= MOST_ERR_OPTYPE;
        VMF_MOST_MSG_PTR_TO_DATA(pmsg)[1]= VMF_MOST_MSG_OPTYPE(pvmf_msg);

        (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
        return(VMF_OK);
    }

    if(VMF_MOST_MSG_DATA_LENGTH(pvmf_msg) != 0)
    {
        NW_VMF_STAT_DEBUG(0,"vmf_nw_status_most_message_handler: invalid data length\n");

        /* send invalid length */
        vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
        vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

        VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
        VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
        VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
        VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
        VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
        VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_ERROR;
        VMF_MOST_MSG_DATA_LENGTH(pmsg)   = 1;
        VMF_MOST_MSG_PTR_TO_DATA(pmsg)[0]= MOST_ERR_LENGTH;

        (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
        return(VMF_OK);
    }

    switch(VMF_MOST_MSG_FUNCID(pvmf_msg))
    {
        case MOST_FUNC_FUNCID:
            {
                NW_VMF_STAT_DEBUG(5,"vmf_nw_status_most_message_handler: Nm.FunctionIds.Get\n");

                static unsigned8 my_funcids[] = {0x00,0x1a,0x00,0xa0,0x20};
                vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
                vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

                VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
                VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
                VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
                VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
                VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
                VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_STATUS;
                VMF_MOST_MSG_DATA_LENGTH(pmsg)   = (unsigned16)sizeof(my_funcids);
                NW_MEMCOPY( (void*)VMF_MOST_MSG_PTR_TO_DATA(pmsg),
                            (void*)my_funcids,
                            (unsigned16)sizeof(my_funcids));

                (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
            }
            break;

        case MOST_NM_FUNC_CONFIG:
            {
                NW_VMF_STAT_DEBUG(5,"vmf_nw_status_most_message_handler: Nm.Config.Get\n");

                vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
                vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

                VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
                VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
                VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
                VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
                VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
                VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_STATUS;
                VMF_MOST_MSG_DATA_LENGTH(pmsg)   = 1;
                VMF_MOST_MSG_PTR_TO_DATA(pmsg)[0]= nm_config_status;

                (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
            }
            break;
        case MOST_NM_FUNC_CENT_REG:
            {
                NW_VMF_STAT_DEBUG(5,"vmf_nw_status_most_message_handler: Nm.CentralRegistry.Get\n");

                vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
                vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

                VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
                VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
                VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
                VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
                VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
                VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_STATUS;
                VMF_MOST_MSG_DATA_LENGTH(pmsg)   = (unsigned16)my_cr.num_entries * 4;
                NW_MEMCOPY ((void*)(VMF_MOST_MSG_PTR_TO_DATA(pmsg)),
                            (void*)&(my_cr.cr_entry),
                            VMF_MOST_MSG_DATA_LENGTH(pmsg));

                (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
            }
            break;
        default:
            {
                NW_VMF_STAT_DEBUG(5,"vmf_nw_status_most_message_handler: Invalid NM FunctionID\n");

                /* send invalid function ID */
                vmf_most_msg_t  msg;            /* prevent strict aliasing warning */
                vmf_most_msg_t *pmsg = (vmf_most_msg_t *)&msg;

                VMF_MOST_MSG_TARGET_ADDR(pmsg)   = VMF_MOST_MSG_SOURCE_ADDR(pvmf_msg);
                VMF_MOST_MSG_SOURCE_ADDR(pmsg)   = VMF_MOST_MSG_TARGET_ADDR(pvmf_msg);
                VMF_MOST_MSG_FBLOCKID(pmsg)      = MOST_FBLOCK_NETWORKMASTER;
                VMF_MOST_MSG_INSTID(pmsg)        = MOST_INST_ANY;
                VMF_MOST_MSG_FUNCID(pmsg)        = VMF_MOST_MSG_FUNCID(pvmf_msg);
                VMF_MOST_MSG_OPTYPE(pmsg)        = MOST_OP_ERROR;
                VMF_MOST_MSG_DATA_LENGTH(pmsg)   = 3;
                VMF_MOST_MSG_PTR_TO_DATA(pmsg)[0]= MOST_ERR_FKTID;
                VMF_MOST_MSG_PTR_TO_DATA(pmsg)[1]= (unsigned8)(VMF_MOST_MSG_FUNCID(pvmf_msg) >> 8);
                VMF_MOST_MSG_PTR_TO_DATA(pmsg)[2]= (unsigned8)VMF_MOST_MSG_FUNCID(pvmf_msg);

                (void)nw_vmf_send_most_ctrl(vmf_client_id, pmsg);
            }
            break;
    }
    return(VMF_OK);

}

/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_reg_operation_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for the reg operation events
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC inline vmf_ret_t vmf_nw_status_reg_operation_handler(vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg)   /**< IN vmf basic message */
{
    vmf_ret_t           vmf_ret=VMF_OK;
    t_nw_msg_header header;
    static bool bFirstRegOprComplete=false;

    /* distinguish between different message events */
    header = BUILD_NW_MSG_HEADER(pvmf_msg->msg_base.id.group,pvmf_msg->msg_base.id.event);

    switch (header)
    {
        case RX_MSG_HEAD__REG_OF_PWR_GRP_COMPLETE:
            /* registration of one startup group is complete */
            NW_VMF_STAT_DEBUG(3,"%s: RegOprComplete received\n",MY_NAME);
            /* send network status events */
            if (!bFirstRegOprComplete)
            {
                (void)vmf_nw_status_tx_first_status_events(vmf_client_id);
                /* store that we once received a RegOprComplete */
                bFirstRegOprComplete = true;
            }
            else
            {
                (void)vmf_nw_status_tx_status_events(vmf_client_id);
            }
        break;

        case RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK:
            NW_VMF_STAT_DEBUG(3,"%s: RegOprAddComp received\n",MY_NAME);
            /* add an entry to the CR */
            vmf_ret = vmf_nw_status_network_regopraddcomp_handler(vmf_client_id,pvmf_msg);

            /* send network status events */
            if ((bSystemStartupComplete) && (VMF_OK==vmf_ret))
            {
                (void)vmf_nw_status_tx_status_events(vmf_client_id);
            }
        break;

        case RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK:
            NW_VMF_STAT_DEBUG(3,"%s: RegOprDelComp received\n",MY_NAME);
            /* del entry in CR */
            vmf_ret = vmf_nw_status_network_regoprdelcomp_handler(vmf_client_id,pvmf_msg);

            /* send network status events */
            if ((bSystemStartupComplete) && (VMF_OK==vmf_ret))
            {
                (void)vmf_nw_status_tx_status_events(vmf_client_id);
            }
        break;

        default:
            /* ignore all other events */
        break;
    }

    return(vmf_ret);
 }



/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_network_regoprdelcomp_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for RegOprDelComp event
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC inline vmf_ret_t vmf_nw_status_network_regoprdelcomp_handler(vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg)   /**< IN vmf basic message */
{
    unsigned8   fblock_id;
    unsigned8   inst_id;

    /* check if data present */
    if (VMF_BASIC_MSG_ALL_DATA_LENGTH(pvmf_msg) < 2)
    {
        NW_VMF_STAT_DEBUG(2,"%s:vmf_nw_status_network_regoprdelcomp_handler() empty message received\n",MY_NAME);
        return VMF_ERROR;
    }

    /* get fblock and inst_id from  data */
    fblock_id = VMF_BASIC_MSG_NEAR_DATA_0(pvmf_msg);
    inst_id   = VMF_BASIC_MSG_NEAR_DATA_1(pvmf_msg);

    NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_network_regoprdelcomp_handler() fblock_id=0x%x,inst_id=0x%x\n",MY_NAME,fblock_id,inst_id);

    /* add an entry to the cr */
    if (!vmf_nw_status_cr_del_entry(&my_cr,NW_STAT_HDLR_DEF_DEV_ID,fblock_id,inst_id))
    {
        NW_VMF_STAT_DEBUG(2,"%s:vmf_nw_status_network_regoprdelcomp_handler() error adding entry to CR\n",MY_NAME);
        return VMF_ERROR;
    }

    return VMF_OK;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_network_regopraddcomp_handler(vmf_msg_t   *pvmf_msg)
 *
 *   Description:   handler for RegOprAddComp event
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     *vmf message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC inline vmf_ret_t vmf_nw_status_network_regopraddcomp_handler(vmf_client_id_t vmf_client_id,vmf_basic_msg_t *pvmf_msg)   /**< IN vmf basic message */
{
    unsigned8   fblock_id;
    unsigned8   inst_id;

    /* check if data present */
    if (VMF_BASIC_MSG_ALL_DATA_LENGTH(pvmf_msg) < 2)
    {
        NW_VMF_STAT_DEBUG(2,"%s:vmf_nw_status_network_regopraddcomp_handler() empty message received\n",MY_NAME);
        return VMF_ERROR;
    }


 //   NW_VMF_STAT_DEBUG(3,"%s d0=0x%x,d1=0x%x,d2=0x%x,d3=0x%x \n",MY_NAME,VMF_BASIC_MSG_NEAR_DATA_0(pvmf_msg),VMF_BASIC_MSG_NEAR_DATA_1(pvmf_msg),VMF_BASIC_MSG_NEAR_DATA_2(pvmf_msg),VMF_BASIC_MSG_NEAR_DATA_3(pvmf_msg));


    /* get fblock and inst_id from  data */
    fblock_id = VMF_BASIC_MSG_NEAR_DATA_0(pvmf_msg);
    inst_id   = VMF_BASIC_MSG_NEAR_DATA_1(pvmf_msg);

    NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_network_regopraddcomp_handler() fblock_id=0x%x,inst_id=0x%x\n",MY_NAME,fblock_id,inst_id);

    /* add an entry to the cr */
    if (!vmf_nw_status_cr_add_entry(&my_cr,NW_STAT_HDLR_DEF_DEV_ID,fblock_id,inst_id))
    {
        NW_VMF_STAT_DEBUG(2,"%s:vmf_nw_status_network_regopraddcomp_handler() error adding entry to CR\n",MY_NAME);
        return VMF_ERROR;
    }

    return VMF_OK;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_create_connection(void)
 *
 *   Description:   create a connection to the VMFServer
 *
 *   \param         void
 *   \return        vmf_client_id_t client id
 *
 ******************************************************************************/
NW_STATIC vmf_client_id_t vmf_nw_status_create_connection(void)
 {
    vmf_client_id_t             vmf_client_id;

    /*---------------------------------------------------
         register to the VMF server (via VMFClient)
      --------------------------------------------------- */

    /* connect to vmf-server via vmf-client lib */
    vmf_client_id = nw_vmf_connect(  MY_NAME,                                /* channel name or NULL  */
                                     NULL,                                   /* rx callback or NULL */
                                     0,                                      /* thread priority of rx callback function */
                                     VMF_NW_STAT_QUEUE_SIZE,                 /* VMF queue size */
                                     VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD );   /* VMF message size */

    if (vmf_client_id < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s: Can not connect to the vmf-server - error=%d\n",MY_NAME,vmf_client_id);
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_create_connection() OK! QUEUE_MSG_SIZE=%d\n",MY_NAME,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    }

    return vmf_client_id;
 }

/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_register_groups(void)
 *
 *   Description:   register to message groups
 *
 *   \param[in]     vmf_client_id
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_nw_status_register_groups(vmf_client_id_t vmf_client_id) /**< IN client id */
{
    unsigned16  size;
    vmf_ret_t   vmf_ret=VMF_OK;

    size = nw_vmf_client_uties_generate_groupid_list(   &groupid_list[0],
                                                        &nw_msg_header_list[0],
                                                        NUM_VMF_MSG_GROUPS);


    if( size == 0)
    {
        vmf_ret = VMF_ERROR;
        NW_VMF_STAT_DEBUG(0,"%s: Can not register msg-groups, no groupId list defined- error=%d\n",MY_NAME,vmf_ret);
        return(vmf_ret);
    }

    vmf_ret = nw_vmf_register_msg_group (vmf_client_id,size,&groupid_list[0]);

    if (vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s: Can not register msg-groups - error=%d\n",MY_NAME,vmf_ret);
    }
    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_init(void)
 *
 *   Description:   global init
 *
 *   \param         void
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_init(void)
{
    return vmf_nw_status_cr_init(&my_cr);
}




/**************************************************************************//**
 *  functions to send events
 ******************************************************************************/

 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_reg_update(void)
 *
 *   Description:   send the MstModCntrRegUpdate with the CR
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     pointer to CR
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_tx_reg_update( vmf_client_id_t vmf_client_id,      /**< IN client id */
                                                vmf_stat_hdlr_cent_reg_t *pcr)      /**< IN pointer to CR */
{
    vmf_ret_t                     vmf_ret;
    vmf_basic_msg_t               msg;
    unsigned16                    cr_size;

    VMF_BASIC_MSG_GROUP_ID(&msg)    = NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NM_CENTRAL_REGISTRY);
    VMF_BASIC_MSG_EVENT_ID(&msg)    = NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NM_CENTRAL_REGISTRY);
    VMF_BASIC_MSG_NEAR_DATA_0(&msg) = nw_vmf_get_most_gen_number();                 /* most gen number ?? */
    VMF_BASIC_MSG_NEAR_DATA_1(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_2(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_3(&msg) = MOST_PROCESS_SIG;

    /* copy CR to message */
    cr_size = (sizeof(vmf_stat_hdlr_cent_reg_entry_t))*pcr->num_entries;
    VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg) = VMF_BASIC_MSG_NEAR_DATA_LENGTH+cr_size;
    NW_MEMCOPY ((void*)(VMF_BASIC_MSG_PTR_TO_FAR_DATA(&msg)),(void*)(pcr->cr_entry),cr_size);

    vmf_ret = nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t*)&msg);

    if(vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_tx_reg_update() error sending basic message error=%d, msg_len=%d\n",MY_NAME,vmf_ret,VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg));
        return false;
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_tx_reg_update() send, msg_len=%d\n",MY_NAME,VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg));

    }

    return true;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_own_devid(void)
 *
 *   Description:   send the MstModOwnLogDevId
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     own device id
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_tx_own_devid(  vmf_client_id_t vmf_client_id,      /**< IN client id     */
                                                unsigned16 devid)                   /**< IN own device id */
{
    vmf_ret_t          vmf_ret;
    vmf_basic_msg_t    msg;

    VMF_BASIC_MSG_GROUP_ID(&msg)    = NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR);
    VMF_BASIC_MSG_EVENT_ID(&msg)    = NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR);
    VMF_BASIC_MSG_NEAR_DATA_0(&msg) = GET_HB(devid);
    VMF_BASIC_MSG_NEAR_DATA_1(&msg) = GET_LB(devid);
    VMF_BASIC_MSG_NEAR_DATA_2(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_3(&msg) = MOST_PROCESS_SIG;
    VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg)  = 4;

    vmf_ret = nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t*)&msg);
    if(vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_tx_own_devid() error sending basic message error=%d, msg_len=%d\n",MY_NAME,vmf_ret,sizeof(msg));
        return false;
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_tx_own_devid() send, msg_len=%d\n",MY_NAME,sizeof(msg));
    }

    return true;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_dev_count(void)
 *
 *   Description:   send the MstModStoreDevCount
 *
 *   \param[in]     vmf_client_id
 *   \param[in]     number of most devices
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_tx_dev_count(  vmf_client_id_t vmf_client_id,      /**< IN client id     */
                                                unsigned8 devcount)                 /**< number of most devices */
{
    vmf_ret_t          vmf_ret;
    vmf_basic_msg_t    msg;

    VMF_BASIC_MSG_GROUP_ID(&msg)    = NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NUM_NODES_IN_RING);
    VMF_BASIC_MSG_EVENT_ID(&msg)    = NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NUM_NODES_IN_RING);
    VMF_BASIC_MSG_NEAR_DATA_0(&msg) = devcount;
    VMF_BASIC_MSG_NEAR_DATA_1(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_2(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_3(&msg) = MOST_PROCESS_SIG;
    VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg)  = 4;

    vmf_ret = nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t*)&msg);
    if(vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_tx_dev_count() error sending basic message error=%d, msg_len=%d\n",MY_NAME,vmf_ret,sizeof(msg));
        return false;
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_tx_dev_count() send, msg_len=%d\n",MY_NAME,sizeof(msg));
    }

    return true;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_mstmodcomdisc(void)
 *
 *   Description:   send the MstModComDisConnect event
 *
 *   \param[in]     vmf_client_id
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_tx_mstmodcomdisc (vmf_client_id_t vmf_client_id)      /**< IN client id     */
{
    vmf_ret_t          vmf_ret;
    vmf_basic_msg_t    msg;

    nm_config_status = MOST_CFG_STATUS_NOTOK;

    VMF_BASIC_MSG_GROUP_ID(&msg)    = NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NM_CONFIG_NOT_OK);
    VMF_BASIC_MSG_EVENT_ID(&msg)    = NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NM_CONFIG_NOT_OK);
    VMF_BASIC_MSG_NEAR_DATA_0(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_1(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_2(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_3(&msg) = MOST_PROCESS_SIG;
    VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg)  = 4;

    vmf_ret = nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t*)&msg);
    if(vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_tx_mstmodcomdisc() error sending basic message error=%d, msg_len=%d\n",MY_NAME,vmf_ret,sizeof(msg));
        return false;
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_tx_mstmodcomdisc()  send, msg_len=%d\n",MY_NAME,sizeof(msg));
    }

    return true;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_mstmodcomcon(void)
 *
 *   Description:   send the MstModComConnect event
 *
 *   \param[in]     vmf_client_id
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC inline bool vmf_nw_status_tx_mstmodcomcon ( vmf_client_id_t vmf_client_id)      /**< IN client id     */
{
    vmf_ret_t          vmf_ret;
    vmf_basic_msg_t    msg;

    nm_config_status = MOST_CFG_STATUS_OK;

    VMF_BASIC_MSG_GROUP_ID(&msg)    = NW_MSG__GROUPID(TX_MSG_HEAD__MOST_NM_CONFIG_OK);
    VMF_BASIC_MSG_EVENT_ID(&msg)    = NW_MSG__EVENTID(TX_MSG_HEAD__MOST_NM_CONFIG_OK);
    VMF_BASIC_MSG_NEAR_DATA_0(&msg) = nw_vmf_inc_and_get_most_gen_number();    /* most gen number ?? */
    VMF_BASIC_MSG_NEAR_DATA_1(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_2(&msg) = 0;
    VMF_BASIC_MSG_NEAR_DATA_3(&msg) = MOST_PROCESS_SIG;
    VMF_BASIC_MSG_ALL_DATA_LENGTH(&msg)  = 4;

    vmf_ret = nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t*)&msg);
    if(vmf_ret < 0)
    {
        NW_VMF_STAT_DEBUG(0,"%s:vmf_nw_status_tx_mstmodcomcon() error sending basic message error=%d, msg_len=%d\n",MY_NAME,vmf_ret,sizeof(msg));
        return false;
    }
    else
    {
        NW_VMF_STAT_DEBUG(3,"%s:vmf_nw_status_tx_mstmodcomcon() send, msg_len=%d\n",MY_NAME,sizeof(msg));
    }

    return true;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_first_status_events(void)
 *
 *   Description:   send MstModComDisConnect,
 *                       MstModStoreDevCount,
 *                       MstModOwnLogDevId,
 *                       MstModComConnect,
 *                       MstModCntrRegUpdate
 *
 *   \param[in]     vmf_client_id
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_tx_first_status_events (vmf_client_id_t vmf_client_id)      /**< IN client id     */
{
    /* send MstModComDisConnect */
    if (!vmf_nw_status_tx_mstmodcomdisc (vmf_client_id))
    {
        return false;
    }

    /* send MstModStoreDevCount */
    if (!vmf_nw_status_tx_dev_count (vmf_client_id,NW_STAT_HDLR_DEF_COUNT))
    {
        return false;
    }

    /* send MstModOwnLogDevId */
    if (!vmf_nw_status_tx_own_devid (vmf_client_id,NW_STAT_HDLR_DEF_DEV_ID))
    {
        return false;
    }

    /* send MstModComConnect */
    if (!vmf_nw_status_tx_mstmodcomcon (vmf_client_id))
    {
        return false;
    }

    /* send MstModCntrRegUpdate */
    if (!vmf_nw_status_tx_reg_update (vmf_client_id,&my_cr))
    {
        return false;
    }

    return true;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_tx_status_events(void)
 *
 *   Description:   send
 *                       MstModStoreDevCount,
 *                       MstModOwnLogDevId,
 *                       MstModCntrRegUpdate
 *
 *   \param[in]     vmf_client_id
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_tx_status_events (vmf_client_id_t vmf_client_id)      /**< IN client id     */
{
    /* send MstModStoreDevCount */
    if (!vmf_nw_status_tx_dev_count (vmf_client_id,NW_STAT_HDLR_DEF_COUNT))
    {
        return false;
    }

    /* send MstModOwnLogDevId */
    if (!vmf_nw_status_tx_own_devid (vmf_client_id,NW_STAT_HDLR_DEF_DEV_ID))
    {
        return false;
    }

    /* send MstModCntrRegUpdate */
    if (!vmf_nw_status_tx_reg_update (vmf_client_id,&my_cr))
    {
        return false;
    }

    return true;
}





/*=============================================================================
 * Abstract:  nw_vmf_get_and_inc_most_gen_number
 *
 * Remark:    Increments Most Generation number and return it
 *
 *   \param         void
 *   \return        most_gen_number
 *
 *=============================================================================*/
NW_STATIC inline unsigned8 nw_vmf_inc_and_get_most_gen_number(void)
{
    return (++ipmMostGenNumber);
}


/*=============================================================================
 * Abstract:  nw_vmf_get_most_gen_number
 *
 * Remark:    get the  Most Generation number
 *
 *   \param         void
 *   \return        most_gen_number
 *
 *=============================================================================*/
NW_STATIC inline unsigned8 nw_vmf_get_most_gen_number(void)
{
    return (ipmMostGenNumber);
}



/**************************************************************************//**
 *  functions to handle local central registy
 ******************************************************************************/


 /**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_cr_init(void)
 *
 *   Description:   init the CR
 *
 *   \param[in/out] pointer to CR
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_cr_init( vmf_stat_hdlr_cent_reg_t *pcr)
{
    if (NULL == pcr)
    {
        NW_VMF_STAT_DEBUG(0,"%s: vmf_nw_status_cr_init - NULL pointer\n",MY_NAME);
        return false;
    }

    pcr->num_entries = 0;
    return true;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_cr_add_entry(void)
 *
 *   Description:   add an entry to the CR
 *
 *   \param[in/out] pointer to CR
 *   \param[in]     device id
 *   \param[in]     fblock id
 *   \param[in]     inst id
 *
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_cr_add_entry( vmf_stat_hdlr_cent_reg_t *pcr,/*!< INPUT pointer to cr  */
                                        unsigned16 devid,           /*!< INPUT device id  */
                                        unsigned8 fblockid,         /*!< INPUT FBlock ID  */
                                        unsigned8 instid)           /*!< INPUT Instance ID  */
{
        if (NULL == pcr)
        {
            NW_VMF_STAT_DEBUG(0,"%s: vmf_nw_status_cr_add_entry - NULL pointer\n",MY_NAME);
            return false;
        }

        NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_cr_add_entry - devid=0x%x, fblockid=0x%x, instid=0x%x\n",MY_NAME,devid,fblockid,instid);

        /* test id entry will fit into the CR */
        if (pcr->num_entries >= NW_STAT_HDLR_CENT_REG_ENTRIES)
        {
            NW_VMF_STAT_DEBUG(0,"%s: vmf_nw_status_cr_add_entry - CR overflow\n",MY_NAME);
            return false;
        }


        /* test id entry already part of CR */
        if (vmf_nw_status_check_entry(pcr,devid,fblockid,instid))
        {
            /* do not add to CR */
            return true;
        }

        /* add entry to the CR */
        pcr->cr_entry[pcr->num_entries].device_id.l= GET_LB(devid);
        pcr->cr_entry[pcr->num_entries].device_id.h= GET_HB(devid);
        pcr->cr_entry[pcr->num_entries].fblock_id  = fblockid;
        pcr->cr_entry[pcr->num_entries].inst_id    = instid;
        pcr->num_entries++;
        return true;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_cr_del_entry(void)
 *
 *   Description:   del an entry from the CR
 *
 *   \param[in/out] pointer to CR
 *   \param[in]     device id
 *   \param[in]     fblock id
 *   \param[in]     inst id
 *
 *   \return        bool - true if success
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_cr_del_entry( vmf_stat_hdlr_cent_reg_t *pcr,/*!< INPUT pointer to cr  */
                                        unsigned16 devid,           /*!< INPUT device id  */
                                        unsigned8 fblockid,         /*!< INPUT FBlock ID  */
                                        unsigned8 instid)           /*!< INPUT Instance ID  */
{
        unsigned8 cnt;

        if (NULL == pcr)
        {
            NW_VMF_STAT_DEBUG(0,"%s: vmf_nw_status_cr_del_entry - NULL pointer\n",MY_NAME);
            return false;
        }

        NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_cr_del_entry - devid=0x%x, fblockid=0x%x, instid=0x%x\n",MY_NAME,devid,fblockid,instid);


        /* remove entry from CR and move the remains up the list*/
        /* search for entry */
        for (cnt=0; cnt<pcr->num_entries; cnt++)
        {
            if ((pcr->cr_entry[cnt].fblock_id == fblockid) &&
                (pcr->cr_entry[cnt].inst_id == instid))
            {
                /* found entry */
                NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_cr_del_entry - entry found at pos%d\n",MY_NAME,cnt);
                
                /* move the remains up the list */
                pcr->num_entries--;             
                for (;cnt<pcr->num_entries; cnt++)
                {
                    pcr->cr_entry[cnt] = pcr->cr_entry[cnt+1];
                }               
                break;
            }
        }

        return true;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_check_entry(void)
 *
 *   Description:   check if an entry already excists in the CR
 *
 *   \param[in/out] pointer to CR
 *   \param[in]     device id
 *   \param[in]     fblock id
 *   \param[in]     inst id
 *
 *   \return        bool - true entry exist
 *
 ******************************************************************************/
NW_STATIC bool vmf_nw_status_check_entry( vmf_stat_hdlr_cent_reg_t *pcr,/*!< INPUT pointer to cr  */
                                        unsigned16 devid,           /*!< INPUT device id  */
                                        unsigned8 fblockid,         /*!< INPUT FBlock ID  */
                                        unsigned8 instid)           /*!< INPUT Instance ID  */
{
        unsigned8 cnt;

        if (NULL == pcr)
        {
            NW_VMF_STAT_DEBUG(0,"%s: vmf_nw_status_check_entry - NULL pointer\n",MY_NAME);
            return false;
        }

        NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_check_entry - devid=0x%x, fblockid=0x%x, instid=0x%x\n",MY_NAME,devid,fblockid,instid);


        /* search for entry */
        for (cnt=0; cnt<pcr->num_entries; cnt++)
        {
            if ((pcr->cr_entry[cnt].fblock_id == fblockid) &&
                (pcr->cr_entry[cnt].inst_id == instid))
            {
                /* found entry */
                NW_VMF_STAT_DEBUG(3,"%s: vmf_nw_status_check_entry - entry found at pos%d\n",MY_NAME,cnt);
                return true;
            }
        }

        return false;
}

#undef _NW_VMF_STAUS_HDLR
#endif

