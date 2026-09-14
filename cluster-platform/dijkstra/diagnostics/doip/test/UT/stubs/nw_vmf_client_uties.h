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

  \file                 nw_vmf_client_uties.h
  \brief                Main routine for the message framework process

  \author               Marko Hammersen
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/

#ifndef _NW_VMF_CLIENT_UTIES_H
#define _NW_VMF_CLIENT_UTIES_H


/* Macro definitons              */
/* MACROS without cast - these MACROS will only work with VMF_BASIC messages */
#define NW_VMF_BASIC_MSG_GROUP(msg)                 ((msg)->msg_base.id.group)
#define NW_VMF_BASIC_MSG_EVENT(msg)                 ((msg)->msg_base.id.event)
#define NW_VMF_BASIC_MSG_TYPE(msg)                  ((msg)->msg_base.base.msg_type)
#define NW_VMF_BASIC_MSG_DATA_LENGTH(msg)           ((msg)->data.length)
#define NW_VMF_BASIC_MSG_DATA_PTR(msg)              (&(msg)->data.pl[0])
#define NW_VMF_BASIC_MSG_TOTAL_LENGTH(msg)          (offsetof(vmf_basic_msg_t,data.pl) + (msg)->data.length)
#define NW_VMF_BASIC_MSG_TOTAL_LENGTH_ALIGNED(msg)  (sizeof(VMF_VAR_BASIC_MSG_TYP((msg)->data.length)))

/* MACROS without cast - these MACROS will only work with VMF_messages */
#define NW_VMF_MSG_EVENT(msg)                       ((msg)->vmf_basic_msg.msg_base.id.event)
#define NW_VMF_MSG_GROUP(msg)                       ((msg)->vmf_basic_msg.msg_base.id.group)
#define NW_VMF_MSG_TYPE(msg)                        ((msg)->vmf_basic_msg.msg_base.base.msg_type)
#define NW_VMF_MSG_DATA_LENGTH(msg)                 ((msg)->vmf_basic_msg.data.length)
#define NW_VMF_MSG_DATA_PTR(msg)                    (&(msg)->vmf_basic_msg.data.pl[0])

/* vmf basic message definitions */
/*! \def VMF_BASIC_MSG_GROUP_ID
    Returns address of message group of a basic message */
#define VMF_BASIC_MSG_GROUP_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.group)

/*! \def VMF_BASIC_MSG_EVENT_ID
    Returns address of event ID of a basic message */
#define VMF_BASIC_MSG_EVENT_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.event)

/*! \def VMF_BASIC_MSG_NEAR_DATA_0
    Returns address of near data byte 0 of a basic message */
#define VMF_BASIC_MSG_NEAR_DATA_0(msg)      (((vmf_basic_msg_t *)msg)->data.pl[0])

/*! \def VMF_BASIC_MSG_NEAR_DATA_1
    Returns address of near data byte 1 of a basic message */
#define VMF_BASIC_MSG_NEAR_DATA_1(msg)      (((vmf_basic_msg_t *)msg)->data.pl[1])

/*! \def VMF_BASIC_MSG_NEAR_DATA_2
    Returns address of near data byte 2 of a basic message */
#define VMF_BASIC_MSG_NEAR_DATA_2(msg)      (((vmf_basic_msg_t *)msg)->data.pl[2])

/*! \def VMF_BASIC_MSG_NEAR_DATA_3
    Returns address of near data byte 3 of a basic message */
#define VMF_BASIC_MSG_NEAR_DATA_3(msg)      (((vmf_basic_msg_t *)msg)->data.pl[3])

/*! \def VMF_BASIC_MSG_PTR_TO_ALL_DATA
    Returns address of first data byte of a basic message */
#define VMF_BASIC_MSG_PTR_TO_ALL_DATA(msg)  (((vmf_basic_msg_t *)msg)->data.pl)

/*! \def VMF_BASIC_MSG_PTR_TO_ALL_DATA
    Returns address of first data byte of a basic message */
#define VMF_BASIC_MSG_PTR_TO_DATA(msg)      (((vmf_msg_t *)msg)->vmf_basic_msg.data.pl)

/*! \def VMF_BASIC_MSG_PTR_TO_FAR_DATA
    Returns address of first far data byte of a basic message */
#define VMF_BASIC_MSG_PTR_TO_FAR_DATA(msg)  (&((vmf_basic_msg_t *)msg)->data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH])

/*! \def VMF_BASIC_MSG_DATA_LENGTH
    __COMPLETE__ data length (near + far) of a basic message */
#define VMF_BASIC_MSG_DATA_LENGTH(msg)      (((vmf_msg_t *)msg)->vmf_basic_msg.data.length)
/*! \vmf MOST message definitions */

/*! \def VMF_BASIC_MSG_DATA_LENGTH
    __COMPLETE__ data length (near + far) of a basic message */
#define VMF_BASIC_MSG_ALL_DATA_LENGTH(msg)      (((vmf_basic_msg_t *)msg)->data.length)

/*! \def VMF_BASIC_MSG_RX_GET_FAR_DATA
    copy far data of a basic message to given buffer (pData parameter) */
#define VMF_BASIC_MSG_RX_GET_FAR_DATA(pData,msg,u16length) \
    {\
        if((((vmf_basic_msg_t *)msg)->data.length) > VMF_BASIC_MSG_NEAR_DATA_LENGTH)\
        {\
            memcpy( pData,(&((vmf_basic_msg_t *)msg)->data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH]),u16length);\
        }\
        else{}\
    }

/*! \def VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH
    Returns far data size in given parameter "target_size" */
#define VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH(target_size,msg) \
    {\
        if((((vmf_basic_msg_t *)msg)->data.length) > VMF_BASIC_MSG_NEAR_DATA_LENGTH)\
        {\
            target_size = (((vmf_basic_msg_t *)msg)->data.length) - VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
        }\
        else \
        {\
            target_size = 0;\
        }\
    }

/*! \def VMF_BASIC_MSG_SET_FAR_DATA_LENGTH
    set far data length of VMF message struct */
#define VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(msg,len) \
    {\
        ((vmf_basic_msg_t *)msg)->data.length = len + VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
    }
    
    

    
/*! \vmf MOST message definitions */

/*! \def VMF_EVENT_MSG_TYPE
    Address of msg type */
#define VMF_EVENT_MSG_TYPE(msg)         (((vmf_msg_t *)msg)->vmf_basic_msg.msg_base.base.msg_type)


/*! \def VMF_EVENT_IS_BASIC_MSG
    Check if message is a BASIC message */
#define VMF_EVENT_IS_BASIC_MSG(msg)      (((vmf_msg_t *)msg)->vmf_basic_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE)

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))

/*! \def VMF_EVENT_IS_MOST_MSG
    Check if message is a MOST message */
#define VMF_EVENT_IS_MOST_MSG(msg)      (((vmf_msg_t *)msg)->vmf_basic_msg.msg_base.base.msg_type == MSG_TYPE_MOST_MESSAGE)

/*! \def VMF_MOST_MSG_TARGET_ADDR
    Address of target node of a VMF MOST message */
#define VMF_MOST_MSG_TARGET_ADDR(msg)   (((vmf_most_msg_t *)msg)->tgt_addr)

/*! \def VMF_MOST_MSG_SOURCE_ADDR
    Address of source node of a VMF MOST message */
#define VMF_MOST_MSG_SOURCE_ADDR(msg)   (((vmf_most_msg_t *)msg)->src_addr)

/*! \def VMF_MOST_MSG_FBLOCKID
    Address of FBlock ID of VMF MOST message */
#define VMF_MOST_MSG_FBLOCKID(msg)      (((vmf_most_msg_t *)msg)->fblock_id)

/*! \def VMF_MOST_MSG_INSTID
    Address of Inst ID of VMF MOST message */
#define VMF_MOST_MSG_INSTID(msg)        (((vmf_most_msg_t *)msg)->inst_id)

/*! \def VMF_MOST_MSG_FUNCID
    Address of Function ID of VMF MOST message */
#define VMF_MOST_MSG_FUNCID(msg)        (((vmf_most_msg_t *)msg)->func_id)

/*! \def VMF_MOST_MSG_OPTYPE
    Address of OpType of VMF MOST message */
#define VMF_MOST_MSG_OPTYPE(msg)        (((vmf_most_msg_t *)msg)->op_type)

/*! \def VMF_MOST_MSG_LENGTH
    Address of __DATA__ length of VMF MOST message */
#define VMF_MOST_MSG_DATA_LENGTH(msg)   (((vmf_most_msg_t *)msg)->data.length)

/*! \def VMF_MOST_MSG_PTR_TO_DATA
    Address of data of VMF MOST message */
#define VMF_MOST_MSG_PTR_TO_DATA(msg)   (((vmf_most_msg_t *)msg)->data.pl)





/***************************************************************************//**
 *
 *   nw_vmf_client_uties_eval_msg
 *
 *   \param[in]     void
 *   \return        evaluates a NETWORK_STATUS msg
 *
 ******************************************************************************/
void nw_vmf_client_uties_eval_msg(vmf_msg_t * msg);

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_u16_get_own_most_addr
 *
 *   \param[in]     void
 *   \return        own MOST device address
 *
 ******************************************************************************/
unsigned16 nw_vmf_client_uties_u16_get_own_most_addr(void);

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_u8_get_most_mpr
 *
 *   \param[in]     void
 *   \return        mpr
 *
 ******************************************************************************/
unsigned8 nw_vmf_client_uties_u8_get_most_mpr(void);

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length
 *
 *   \param[in]     vmf_basic_msg_t * msg, unsigned8 *psource, unsigend16 size
 *   \return        vmf_error_t - VMF_OK or VMF_ERROR
 *
 ******************************************************************************/
vmf_error_t nw_vmf_client_uties_copy_basic_tx_msg_far_data_and_length(vmf_basic_msg_t *msg, unsigned8 *pData, unsigned16 size);

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
                                                           unsigned16 tgt_buffer_length);

                                                           
                                                           
#else

/* For compatibility with EINSTEIN / X351 cluster !!! */

/***************************************************************************//**
 *
 *   nw_vmf_client_uties_eval_msg
 *
 *   \param[in]     void
 *   \return        evaluates a NETWORK_STATUS msg
 *
 ******************************************************************************/
//void nw_vmf_client_uties_eval_msg(vmf_msg_t * msg);
    
    
#endif /*#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED)) */

#endif /*  _NW_VMF_CLIENT_UTIES_H */

