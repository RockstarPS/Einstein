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

  \file                 nw_vmf_client_uties.c
  \brief                Main routine for the message framework process

  \author               Marko Hammersen
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/

#include "nw_os_config.h"
/* system includes */
#include "os_types.h"

#ifdef UNIT_TEST
#warning "************************** UNIT_TEST enabled! **********************"
#include "stub_debug_print.h"
#include "nw_config.h"
#else
#include "nw_vmf_debug.h"
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
#include "nw_most_defs.h"
#endif

/* application includes */
#include "nw_vmf.h"
#include "nw_config.h"

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
static unsigned16   u16ownMostAddr = MOST_FAKE_MODE_DEV_ID;
static unsigned8    u8MostMpr = 0;

static bool nw_linear_search(unsigned8 *buffer, unsigned8 key, unsigned16 size);

/***************************************************************************//**
 *
 *   nw_vmf_uties_eval_basic_msg
 *
 *   \param[in]     msg
 *   \return        void
 *
 ******************************************************************************/
void nw_vmf_client_uties_eval_msg(vmf_msg_t * msg)
{
    t_nw_msg_header header;

    if (NULL == msg)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_eval_msg: NULL pointer!\n");
        return;
    }

    if(VMF_EVENT_IS_MOST_MSG(msg))
    {
        /* vmf most msg */
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                           "nw_vmf_client_uties_eval_msg: MOST message\n");
    }
    else
    {
        /* vmf basic msg */
        header = BUILD_NW_MSG_HEADER(VMF_BASIC_MSG_GROUP_ID(((vmf_basic_msg_t *)msg)), VMF_BASIC_MSG_EVENT_ID(msg));
        switch(header)
        {
            case TX_MSG_HEAD__MOST_NB_OWN_NODE_ADDR:
                u16ownMostAddr =  (((unsigned16)VMF_BASIC_MSG_NEAR_DATA_0(msg)) << 8) & 0xFF00;
                u16ownMostAddr |= (((unsigned16)VMF_BASIC_MSG_NEAR_DATA_1(msg)) & 0x00FF);
                NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                                   "nw_vmf_client_uties_eval_msg: own node address %d \n", (int)u16ownMostAddr);
                break;
            case TX_MSG_HEAD__MOST_NUM_NODES_IN_RING:
                u8MostMpr = VMF_BASIC_MSG_NEAR_DATA_0(msg);
                NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                                   "nw_vmf_client_uties_eval_msg: number most nodes %d \n", (int)u8MostMpr);
                break;
            default:
                NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                                   "nw_vmf_client_uties_eval_msg: unknown header %d \n", (int)header);
                break;
        }
    }
    return;
}

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_u16_get_own_most_addr
 *
 *   \param[in]     void
 *   \return        own MOST device address
 *
 ******************************************************************************/
unsigned16 nw_vmf_client_uties_u16_get_own_most_addr(void)
{
    return(u16ownMostAddr);
}

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_u8_get_most_mpr
 *
 *   \param[in]     void
 *   \return        mpr
 *
 ******************************************************************************/
unsigned8 nw_vmf_client_uties_u8_get_most_mpr(void)
{
    return(u8MostMpr);
}


/***************************************************************************//**
 *
 *   nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length
 *
 *   \param[in]     vmf_basic_msg_t * msg, unsigned8 *psource, unsigend16 size
 *   \return        vmf_error_t - VMF_OK or VMF_ERROR
 *
 ******************************************************************************/
vmf_error_t
nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length(vmf_basic_msg_t *msg,
                                                             unsigned8 *pData,
                                                             unsigned16 len)
{

    if (NULL == msg)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length: msg NULL pointer!\n");
        return VMF_ERR_NULL_POINTER;
    }
    
    if ((NULL == pData) && (len > 0))
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length: pData NULL pointer!\n");
        return VMF_ERR_NULL_POINTER;
    }

    if (len > (sizeof(msg->data.pl) - VMF_BASIC_MSG_NEAR_DATA_LENGTH))
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length: len > buffer!\n");
        return VMF_ERR_OUT_OF_RANGE;
    }

    if (len > 0)
    {
        NW_MEMCOPY( (&((vmf_basic_msg_t *)msg)->data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH]),pData,len);
    }
    ((vmf_basic_msg_t *)msg)->data.length = len + VMF_BASIC_MSG_NEAR_DATA_LENGTH;
    return VMF_OK;

}


/*****************************************************************************
 *
 *   Function Name: nw_linear_search(unsigned8 *buffer, unsigned8 key, unsigned16 size)
 *
 *   Description:   search for 'key' in 'buffer' for iterations of 'size'
 *
 *   Parameters:    unsigned8 *buffer, unsigned8 key, unsigned16 size
 *
 *   Function Return value: - if found: true else false
 *
 ******************************************************************************/
static bool nw_linear_search(unsigned8 *buffer, unsigned8 key, unsigned16 size)
{
    bool        found;
    unsigned8   *iterator;
    unsigned8   *end;

    found = false;

    if(buffer != (void *)0)
    {
        iterator    = buffer;
        end         = buffer + size;

        while(iterator != end && false == found)
        {
            if(*iterator == key)
            {
                found = true;
                NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                                        "nw_linear_search: Entry found for key == 0x%x\n", (int)key);
            }
            iterator++;
        }
    }

    if (false == found)
    {
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                           "nw_linear_search: No entry found for key == 0x%x\n", (int)key);
    }

    return(found);
}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_client_uties_generate_groupid_list(unsigned8 *ptr)
 *
 *   Description:   generates list of msg groups to register for
 *
 *   \param[in]     ptr to list
 *   \return        size
 *
 ******************************************************************************/
unsigned16 nw_vmf_client_uties_generate_groupid_list(unsigned8 *tgt_buffer,
                                                    t_nw_msg_header *src_buffer,
                                                    unsigned16 tgt_buffer_length)
{
    unsigned16  size;
    unsigned16  i;


    if( ((void *)0) == tgt_buffer )
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_generate_groupid_list: tgt_buffer NULL pointer!\n");
        return(0);
    }

    if( ((void *)0) == src_buffer )
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_client_uties_generate_groupid_list: src_buffer NULL pointer!\n");
        return(0);
    }

    if(0 == tgt_buffer_length)
    {
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                           "nw_vmf_client_uties_generate_groupid_list: len==0 !\n");
    }

    size = 0;

    for(i = 0; i < tgt_buffer_length; i++)
    {
        if(BROADCAST != NW_MSG__GROUPID(src_buffer[i]))
        {
            /* BROADCAST events are to be ignored */
            if(false == nw_linear_search(&tgt_buffer[0],NW_MSG__GROUPID(src_buffer[i]),size))
            {
                /* need to add entry to list */
                tgt_buffer[size] = NW_MSG__GROUPID(src_buffer[i]);
                NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO,
                       "nw_vmf_client_uties_generate_groupid_list: Added group ID == 0x%x to list\n",(int)NW_MSG__GROUPID(src_buffer[i]));
                size++;
            }
        }
    }

    return(size);
}

#else

/* For compatibility with EINSTEIN / X351 cluster !!! */

/***************************************************************************//**
 *
 *   nw_vmf_uties_eval_basic_msg
 *
 *   \param[in]     msg
 *   \return        void
 *
 ******************************************************************************/
void nw_vmf_client_uties_eval_msg(vmf_msg_t * msg)
{
    UNUSED_PARAM(msg);
    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_CLIENT_LIB,NW_VMF_DBG_LVL_INFO, "nw_vmf_client_uties_eval_msg: empty stub!");
}

#endif
