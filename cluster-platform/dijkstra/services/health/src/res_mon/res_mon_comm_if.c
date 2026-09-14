/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "debug.h"
#include "nw_vmf.h"
#include "res_mon.h"
#include "res_mon_comm_if.h"
#include "res_mon_extract_package.h"
#include "res_mon_package.h"

#define RES_MON_COMP_ID                                   (10U)
#define RES_MON_COMP_ID_IDX                               (0U)
#define RES_MON_MSG_CNT_IDX                               (1U)
#define RES_MON_FILE_SZ_IDX                               (2U)
#define RES_MON_DATA_IDX                                  (6U)
#define RES_MON_DATA_CHUNK_SZ                             (32U)

#define RES_MON_DUMP_TYPE_IDX                             (2U)
#define RES_MON_DUMP_GET_HDR_SIZE                         (3U)

#define DK_MSG_HEALTH_DUMP_GID                            (0xE1)
#define DK_MSG_HEALTH_NUM_GID                             (1U)
#define DK_MSG_HEALTH_DUMP_GET_HDR                        (0xE100)
#define DK_MSG_HEALTH_DUMP_GET_DATA                       (0xE101)
#define DK_MSG_HEALTH_DUMP_PACKAGE_DLT_LOGS               (0xE102)

#define DK_MSG_HEALTH_DUMP_HDR_INFO                       (0xE200)
#define DK_MSG_HEALTH_DUMP_DATA                           (0xE201)

static pthread_t rx_thread_id;
static vmf_client_id_t vmf_client_id = -1;
static uint8_t vmf_msg_cnt = 0;
static uint32_t g_vmf_loop_flag = TRUE;

static int32_t ResMonCommIf_SendHeaderInfo ( package_hdr_t *hdr );
static int32_t ResMonCommIf_SendData (  uint8_t *data, uint32_t size  );
static void* ResMonCommIf_ReceiveThread( void*  arg );

int32_t ResMonCommIf_Init ( void )
{
	int32_t ret = RM_FAILED;
	pthread_attr_t rx_attr;
	vmf_msg_cnt = 0;
	vmf_ret_t vmf_ret;
	VMF_VAR_BASIC_MSG_TYP(MAX_VMF_DATA_LEN)     msg;
	uint8_t group_id = DK_MSG_HEALTH_DUMP_GID;

    if( -1 == (int8_t) vmf_client_id )
    {
        vmf_client_id = nw_vmf_connect ( "ResMon", 0, 0, VMF_CLIENT_QUEUE_SIZE_BIG, (uint16_t) sizeof(msg) );

        if ( 0 > vmf_client_id )
        {
            LOGI ( "nw_vmf_connect failed %d retry later", (uint8_t) vmf_client_id );
        }
        else
        {
            LOGI ( "nw_vmf_connect success %d", (uint8_t) vmf_client_id );
            vmf_ret = nw_vmf_register_msg_group( vmf_client_id, DK_MSG_HEALTH_NUM_GID, &group_id);
            if ( vmf_ret == VMF_OK )
            {
                pthread_attr_init ( &rx_attr );
                pthread_attr_setdetachstate ( &rx_attr, PTHREAD_CREATE_DETACHED );
                if ( EOK == pthread_create ( &rx_thread_id, &rx_attr, &ResMonCommIf_ReceiveThread, NULL ) )
                {
                	ret = RM_OK;
                }
                ( void ) pthread_attr_destroy( &rx_attr );
            }

        }
    }
    else
    {
        /* Already connected */
        ret = RM_OK;
    }

    return ret;
}

int32_t ResMonCommIf_Shutdown ( void )
{
    if ( 0 <= (int8_t) vmf_client_id )
    {
        if ( VMF_OK ==  nw_vmf_disconnect ( vmf_client_id ) )
        {
            LOGI ( "nw_vmf_disconnect success %d", (uint8_t) vmf_client_id );
        }
        else
        {
            LOGE ( "nw_vmf_disconnect error %d", (uint8_t) vmf_client_id );
        }
        vmf_client_id = -1;
        ( void ) pthread_cancel( rx_thread_id );
    }

    return RM_OK;
}

static int32_t ResMonCommIf_SendHeaderInfo ( package_hdr_t *hdr )
{
    int32_t ret = RM_FAILED;
    vmf_ret_t vmf_ret;
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint8_t *payload;
    uint32_t  payload_len = 0;
    uint32_t filesize = 0;

    VMF_BASIC_MSG_GROUP_ID ( &msg ) = ( ( DK_MSG_HEALTH_DUMP_HDR_INFO >> 8U ) & 0x00FF );
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = ( DK_MSG_HEALTH_DUMP_HDR_INFO & 0x00FF );
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );
    payload_len = 0;
    payload[RES_MON_COMP_ID_IDX] = RES_MON_COMP_ID;
    payload_len++;
    payload[RES_MON_MSG_CNT_IDX] = vmf_msg_cnt++;
    payload_len++;
    filesize = htonl ( hdr->filesize );
    memcpy ( &payload[RES_MON_FILE_SZ_IDX], &filesize, sizeof ( uint32_t ) );
    payload_len += sizeof ( uint32_t );
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( &msg, payload_len );

    vmf_ret = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

	if ( VMF_OK == vmf_ret )
	{
		ret = RM_OK;
	}

    return ret;
}

static int32_t ResMonCommIf_SendData (  uint8_t *data, uint32_t size  )
{
    int32_t ret = RM_FAILED;
    vmf_ret_t vmf_ret;
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg;
    uint8_t *payload;
    uint32_t  payload_len = 0;
    uint32_t datasize = 0;

    VMF_BASIC_MSG_GROUP_ID ( &msg ) = ( ( DK_MSG_HEALTH_DUMP_DATA >> 8U ) & 0x00FF );
    VMF_BASIC_MSG_EVENT_ID ( &msg ) = ( DK_MSG_HEALTH_DUMP_DATA & 0x00FF );
    payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA ( &msg );
    payload_len = 0;
    payload[RES_MON_COMP_ID_IDX] = RES_MON_COMP_ID;
    payload_len++;
    payload[RES_MON_MSG_CNT_IDX] = vmf_msg_cnt++;
    payload_len++;
    datasize = htonl ( size );
    memcpy ( &payload[RES_MON_FILE_SZ_IDX], &datasize, sizeof ( uint32_t ) );
    payload_len += sizeof ( uint32_t );
    memcpy ( &payload[RES_MON_DATA_IDX], data, (size_t) size );
    payload_len += size;
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH ( &msg, payload_len );

    vmf_ret = nw_vmf_send_basic ( vmf_client_id, ( vmf_basic_msg_t * ) &msg );

	if ( VMF_OK == vmf_ret )
	{
		ret = RM_OK;
	}

    return ret;
}

static void* ResMonCommIf_ReceiveThread ( void*  arg )
{
	int32_t ret;
    uint8_t *payload;
    int16_t len;
    int32_t mid;
    package_hdr_t hdr;
    uint8_t payload_size = 0;
    char file[PACKAGE_PATH_MAX];
    uint8_t data[RES_MON_DATA_CHUNK_SZ];
	uint32_t size = RES_MON_DATA_CHUNK_SZ;
    VMF_VAR_BASIC_MSG_TYP ( MAX_VMF_DATA_LEN ) msg = {0};

    while ( TRUE == g_vmf_loop_flag )
    {
        len = nw_vmf_receive ( vmf_client_id, ( vmf_msg_t * ) &msg, sizeof ( msg ) );
        if (0 < len)
        {
            mid = (int32_t) ( VMF_BASIC_MSG_GROUP_ID( &msg ) << 8 ) | ( VMF_BASIC_MSG_EVENT_ID( &msg ) );
            VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH( payload_size, &msg );
            payload = ( uint8_t * ) VMF_BASIC_MSG_PTR_TO_FAR_DATA( &msg );
            switch ( mid )
            {
                case DK_MSG_HEALTH_DUMP_GET_HDR:
                {
                    if( payload_size == RES_MON_DUMP_GET_HDR_SIZE )
                    {
                        ret = ResMonExtractPackage_Start ( &hdr, payload[RES_MON_DUMP_TYPE_IDX] );
                        if( ret == RM_OK )
                        {
                            ret = ResMonCommIf_SendHeaderInfo( &hdr );
                            (void) ret;
                        }
                    }
                }
                break;
                case DK_MSG_HEALTH_DUMP_GET_DATA:
                {
                    ret = ResMonExtractPackage_Read ( data, &size );
                    if( ret == RM_OK )
                    {
                        ret = ResMonCommIf_SendData( data, size );
                        (void) ret;
                    }
                }
                break;
                case DK_MSG_HEALTH_DUMP_PACKAGE_DLT_LOGS:
                {
                    (void) ResMonPackage_CreatePackageWithDLTLogs(file, PACKAGE_PATH_MAX);
                }
                break;
                default:
                break;
            }
        }
    }

    return NULL;
}
