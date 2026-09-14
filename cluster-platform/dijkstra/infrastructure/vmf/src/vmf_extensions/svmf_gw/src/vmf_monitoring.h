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

  \file                 vmf_monitoring.h
  \brief                header of vmf monitoring for mqx

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef VMF_MONITORING_H__
#define VMF_MONITORING_H__



enum VMF_MON_STATUS
{
    VMF_MON_STATUS_UNKNOWN,
    VMF_MON_STATUS_GREEN,
    VMF_MON_STATUS_YELLOW,
    VMF_MON_STATUS_RED
};

#define VMF_MON_ITEM_NAME_LEN   30
#define VMF_MON_TEXT_LEN        100
#define VMF_MON_VERSION         (unsigned8)1

typedef struct
{
    unsigned8   version;                            /* version of load response - 0x00 for version 0 */
    unsigned8   item_name_len;                      /* len of item_name including terminating zero */
    char        item_name[VMF_MON_ITEM_NAME_LEN];   /* monitor item name – zero terminated */
}vmf_ctrl_monitoring_req_t;

typedef struct
{
    unsigned8   version;                            /* version of load response - 0x00 for version 0 */
    unsigned8   item_name_len;                      /* len of item_name including terminating zero */
    char        item_name[VMF_MON_ITEM_NAME_LEN];   /* monitor item name – zero terminated */
    unsigned8   status;                             /* monitor status */
    unsigned8   text_len;                           /* len of text including terminating zero */
    char        text[VMF_MON_TEXT_LEN];             /* status text – zero terminated  */
}vmf_ctrl_monitoring_resp_t;


/* monitoring items */
#define ITEM_A5_VMF_CORE    "A5_VMF_CORE"
#define ITEM_A5_TRQ         "A5_TR_Q"
#define ITEM_M4_VMF_CORE    "M4_VMF_CORE"
#define ITEM_M4_MCCQ        "M4_MCC_Q"
#define ITEM_UP375_GW_CORE  "UP375_GW_CORE"
#define ITEM_UP375_GW_CONN  "UP375_GW_CONNECTION"


/* function prototypes */
vmf_ret_t  vmf_mon_handle_request(vmf_client_id_t cid, vmf_msg_t *p_vmf_msg);



#endif


