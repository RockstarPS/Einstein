//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include <arpa/inet.h>
#include "nw_vmf.h"
#include "wdg_proxy_comm_if.h"
#include "wdg_proxy_cfg.h"
#include "dk_logger.h"

#define WP_VMF_COMP_ID_IDX       (0u)
#define WP_VMF_MSG_CNT_IDX       (1U)
#define WP_VMF_MSG_DOMAIN_IDX    (2U)
#define WP_VMF_MSG_PAYLOAD_IDX   (3U)

#define WP_VMF_MSG_HEALTH_EVENT_RECORD_LENGTH (8U)
#define DK_MSG_RES_MON_HEALTH_DUMP_GID              (0xE1)
#define DK_MSG_HEALTH_DUMP_PACKAGE_DLT_LOGS_EID     (0x02)
#define RES_MON_COMP_ID                             (10U)
#define RES_MON_COMP_ID_IDX                         (0U)
#define RES_MON_MSG_CNT_IDX                         (1U)

static vmf_client_id_t vmf_client_id = -1;
static uint8_t vmf_msg_cnt = 0;
static uint32_t wdg_hb_seq_cnt = 0;

LOG_IMPORT_CONTEXT( gWPLogContext );

int32_t WdgProxyCommIf_Init ( void )
{
    int32_t ret_init = WP_FAIL;

    if ( -1 == vmf_client_id )
    {
        /* coverity[MISRA C-2012 Directive 19.2 violation] : FALSE */
        vmf_client_id = nw_vmf_connect ( "WdgProxy", NULL, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, MAX_VMF_MESSAGE_LEN );

        if ( 0 > vmf_client_id )
        {
            LOGI ( &gWPLogContext, "nw_vmf_connect failed %d retry later", vmf_client_id );
        }
        else
        {
        	vmf_msg_cnt = 0;
            /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
            LOGI ( &gWPLogContext, "nw_vmf_connect success %d", vmf_client_id );
            ret_init = WP_OK;
        }
    }
    else
    {
        /* Already connected */
        ret_init = WP_OK;
    }

    return ret_init;
}

int32_t WdgProxyCommIf_Shutdown ( void )
{
    if ( 0 <= vmf_client_id )
    {
        ( void ) nw_vmf_disconnect ( vmf_client_id );
        vmf_client_id = -1;
        /* coverity[MISRA C-2012 Directive 1.2 violation] : FALSE */
        LOGI ( &gWPLogContext, "nw_vmf_disconnect success %d", vmf_client_id );
    }

    return WP_OK;
}

int32_t WdgProxyCommIf_SendFatalError ( uint32_t idx )
{
    int32_t ret_error = WP_FAIL;
    vmf_ret_t vmf_result;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint8_t *payload;
    uint8_t  payload_len = 0U;

    /* coverity[MISRA C-2012 Directive 10.1 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_BASIC_MSG_GROUP_ID ( &msg ) = WDG_VMF_GID;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.4 violation] : FALSE */
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = WDG_VMF_FATAL_ERROR_EID;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );

    payload[WP_VMF_COMP_ID_IDX] = WDG_COMP_ID;
    payload_len++;
    vmf_msg_cnt = vmf_msg_cnt+1;
    payload[WP_VMF_MSG_CNT_IDX] = vmf_msg_cnt;
    payload_len++;
    payload[WP_VMF_MSG_DOMAIN_IDX] = WDG_DOMAIN_ID;
    payload_len++;
    /* coverity[MISRA C-2012 Directive 17.8 violation] : FALSE */
    idx = htonl ( idx );
    /* coverity[MISRA C-2012 Directive 21.15 violation] : FALSE */
    ( void ) memcpy ( &payload[WP_VMF_MSG_PAYLOAD_IDX], &idx, sizeof ( int32_t ) );
    payload_len += (uint8_t)sizeof ( int32_t );
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.3 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.4 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( ( &msg ), ( payload_len ) );

    if ( WP_OK == WdgProxyCommIf_Init() )
    {
        vmf_result = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

        if ( VMF_OK == vmf_result )
        {
            ret_error = WP_OK;
        }
    }

    return ret_error;
}

int32_t WdgProxyCommIf_SendHeartbeat ( void )
{
    int32_t ret_send = WP_FAIL;
    vmf_ret_t vmf_result;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.4 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint32_t seq_cnt_be = 0U;
    uint8_t *payload;
    uint8_t  payload_len = 0U;

    /* coverity[MISRA C-2012 Directive 4.9 and 10.1 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.4 and 10.1 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 and 10.1 violation] : FALSE */
    VMF_BASIC_MSG_GROUP_ID ( &msg ) = WDG_VMF_GID;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = WDG_VMF_HEALTHY_EID;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );

    payload[WP_VMF_COMP_ID_IDX] = WDG_COMP_ID;
    payload_len++;
    vmf_msg_cnt = vmf_msg_cnt+1;
    payload[WP_VMF_MSG_CNT_IDX] = vmf_msg_cnt;
    
    payload_len++;
    payload[WP_VMF_MSG_DOMAIN_IDX] = WDG_DOMAIN_ID;
    payload_len++;

    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    seq_cnt_be = htonl ( wdg_hb_seq_cnt );
    /* coverity[MISRA C-2012 Directive 21.15 violation] : FALSE */
    (void)memcpy ( &payload[WP_VMF_MSG_PAYLOAD_IDX], &seq_cnt_be, sizeof ( uint32_t ) );
    payload_len += (uint8_t)sizeof ( uint32_t );
	
	wdg_hb_seq_cnt++;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.3 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( ( &msg ), ( payload_len ) );

    if ( WP_OK == WdgProxyCommIf_Init() )
    {
        /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
        vmf_result = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

        if ( VMF_OK == vmf_result )
        {
            ret_send = WP_OK;
        }
    }

    return ret_send;
}

int32_t WdgProxyCommIf_PackageDLTLogs ( void )
{
    int32_t ret = WP_FAIL;
    vmf_ret_t vmf_result;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint32_t seq_cnt_be = 0U;
    uint8_t *payload;
    uint8_t  payload_len = 0U;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_BASIC_MSG_GROUP_ID ( &msg ) = DK_MSG_RES_MON_HEALTH_DUMP_GID;
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = DK_MSG_HEALTH_DUMP_PACKAGE_DLT_LOGS_EID;
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );

    payload[RES_MON_COMP_ID_IDX] = RES_MON_COMP_ID;
    payload_len++;
    vmf_msg_cnt = vmf_msg_cnt+1;
    payload[RES_MON_MSG_CNT_IDX] = vmf_msg_cnt; 
    payload_len++;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    seq_cnt_be = htonl ( wdg_hb_seq_cnt );
    /* coverity[MISRA C-2012 Directive 21.15 violation] : FALSE */
    (void)memcpy ( &payload[WP_VMF_MSG_PAYLOAD_IDX], &seq_cnt_be, sizeof ( uint32_t ) );
    /* coverity[MISRA C-2012 Directive 10.3 violation] : FALSE */
    payload_len += sizeof ( uint32_t );
	
	wdg_hb_seq_cnt++;
    /* coverity[MISRA C-2012 Directive 4.9 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 10.3 violation] : FALSE */
    /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( ( &msg ), ( payload_len ) );

    if ( WP_OK == WdgProxyCommIf_Init() )
    {
        /* coverity[MISRA C-2012 Directive 11.3 violation] : FALSE */
        vmf_result = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

        if ( VMF_OK == vmf_result )
        {
            ret = WP_OK;
        }
    }

    return ret;
}
/* coverity[MISRA C-2012 Directive 2.7 violation] : FALSE */
/* coverity[MISRA C-2012 Directive 8.7 violation] : FALSE */
int32_t WdgProxyCommIF_SendHealthEvent (uint8_t idx, uint8_t record_type, uint8_t restart_type, uint8_t restart_cnt)
{
    int32_t ret_health = WP_FAIL;
#ifdef WDG_PROXY_HEALTH_EVENT
    vmf_ret_t vmf_result;
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint8_t *payload;
    uint8_t  payload_len = 0U;

    VMF_BASIC_MSG_GROUP_ID ( &msg ) = WDG_VMF_GID;
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = WDG_VMF_HEALTH_EVENT_RECORD_EID;
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );

    payload[WP_VMF_COMP_ID_IDX] = WDG_COMP_ID;
    payload_len++;
    payload[WP_VMF_MSG_CNT_IDX] = vmf_msg_cnt++;
    payload_len++;

    payload[payload_len++] = (WDG_DOMAIN_ID << 6U) | (record_type << 4U) | (0x0FU);
    payload[payload_len++] = WP_VMF_MSG_HEALTH_EVENT_RECORD_LENGTH;

    payload[payload_len++] = idx;
    payload[payload_len++] = restart_type;
    payload[payload_len++] = restart_cnt;
    payload[payload_len++] = 0xFF;
    payload[payload_len++] = 0xFF;
    payload[payload_len++] = 0xFF;
    payload[payload_len++] = 0xFF;
    payload[payload_len++] = 0xFF;

    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( ( &msg ), ( payload_len ) );

    if ( WP_OK == WdgProxyCommIf_Init() )
    {
        vmf_result = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

        if ( VMF_OK == vmf_result )
        {
            ret_health = WP_OK;
        }
    }
#endif

    return ret_health;
}