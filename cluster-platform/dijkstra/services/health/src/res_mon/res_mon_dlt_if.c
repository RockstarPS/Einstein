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
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "debug.h"
#include "dlt/dlt.h"
#include "dlt/dlt_filetransfer.h"

#include "res_mon.h"
#include "res_mon_package.h"
#include "res_mon_dlt_if.h"

#define MAXSTRLEN 1024

#define RM_APP_DESC      "Resource Monitor Application"
#define RM_CONTEXT_DESC  "Resource Monitor Context"

#define RM_APP     "RESM"
#define RM_CONTEXT "RESC"

#define TIMEOUT                              (20)
#define DELETE_FILE                          (1)
#define UPLOAD_PLAIN_LOG_DUMP_SERVICE_ID     (0x1001)
#define UPLOAD_ENCRYPT_LOG_DUMP_SERVICE_ID   (0x1002)

uint32_t always_encrypt = FALSE;

/*!Declare some context for the file transfer. It's not a must have to do this,
 * but later you can set a filter on this context in the dlt viewer. */
DLT_DECLARE_CONTEXT( rm_ctx )

static int32_t ResMonDltIf_Send( char *file );
static int32_t ResMonDltIf_InjectionCbk( uint32_t service_id, void *data, uint32_t length );

static int32_t ResMonDltIf_Send( char *file )
{
    int32_t ret = RM_FAILED;

    if( 0 == dlt_user_log_file_infoAbout( &rm_ctx, file ) )
    {
        if( 0 == dlt_user_log_file_complete( &rm_ctx, file, DELETE_FILE, TIMEOUT ) )
        {
            ret = RM_OK;
        }
    }

    return ret;
}

int32_t ResMonDltIf_Init( uint32_t encrypt )
{
    int32_t ret = RM_OK;

    char apid[DLT_ID_SIZE];
    char ctid[DLT_ID_SIZE];

    always_encrypt = encrypt;

    dlt_set_id( apid, RM_APP );
    dlt_set_id( ctid, RM_CONTEXT );

    /*Register the application at the dlt-daemon */
    ( void ) dlt_register_app( apid, RM_APP_DESC );

    /*Register the context of the main program at the dlt-daemon */
    DLT_REGISTER_CONTEXT( rm_ctx, ctid, RM_CONTEXT_DESC );

    /*Register injection callback */
    DLT_REGISTER_INJECTION_CALLBACK( rm_ctx, UPLOAD_PLAIN_LOG_DUMP_SERVICE_ID, ResMonDltIf_InjectionCbk );
    DLT_REGISTER_INJECTION_CALLBACK( rm_ctx, UPLOAD_ENCRYPT_LOG_DUMP_SERVICE_ID, ResMonDltIf_InjectionCbk );

    return ret;
}

static int32_t ResMonDltIf_InjectionCbk( uint32_t service_id, void *data, uint32_t length )
{
    int32_t ret = RM_FAILED;
    char file[PACKAGE_PATH_MAX];

    LOGI ( "Service Id %d, Length=%d", service_id, length );

    switch( service_id )
    {
    case UPLOAD_PLAIN_LOG_DUMP_SERVICE_ID:
        if( always_encrypt == TRUE )
        {
            ret = ResMonPackage_Create( TRUE, file, PACKAGE_PATH_MAX );
        }
        else
        {
            ret = ResMonPackage_Create( FALSE, file, PACKAGE_PATH_MAX );
        }
        break;

    case UPLOAD_ENCRYPT_LOG_DUMP_SERVICE_ID:
        ret = ResMonPackage_Create( TRUE, file, PACKAGE_PATH_MAX );
        break;

    default:
        break;
    }

    if( ret == RM_OK )
    {
        ret = ResMonDltIf_Send( file );
    }
    else
    {
        LOGE ( "Create Package Failed %d ", service_id );
    }

    return ret;
}
