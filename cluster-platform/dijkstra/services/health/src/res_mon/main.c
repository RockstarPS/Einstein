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
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/slog2.h>
#include "debug.h"
#include "res_mon.h"
#include "res_mon_dlt_if.h"
#include "res_mon_comm_if.h"
#include "res_mon_extract_package.h"
#include "res_mon_procfs.h"
#include "res_mon_ddr_mx8.h"
#include "res_mon_qcom.h"
#include <login.h>
#include <sys/procmgr.h>

#define DEFAULT_DELAY     (1U)

uint8_t g_loop_flag = 1U;

slog2_buffer_set_config_t   slog2_config;
slog2_buffer_t              slog2_handle;
char *UserParm = NULL;     /* For drop-root  */

int32_t main(int32_t argc, char *argv[])
{
    int32_t opt;
    int32_t upload = FALSE;
    int32_t ddr_perf = FALSE;
    int32_t gpu_busy_stats = FALSE;
    int32_t ret;
    int64_t value = 0;
    uint32_t delay = DEFAULT_DELAY;
    uint32_t encrypt = FALSE;
    uint8_t l_ret_res_mon_enable_logging_U8 = EOK;

    if( ThreadCtl(_NTO_TCTL_IO, NULL) == -1 )
    {
    	LOGE ( "%s", "_NTO_TCTL_IO error" );
    }

    while((opt = getopt(argc, argv, "d:uepg:U:")) != -1)
    {
        switch(opt)
        {
        case 'd':
            value = strtol( optarg, NULL, 10 );
            if ( INT_MIN < value && INT_MAX > value )
            {
                delay = value;
            }
            break;
        case 'u':
            upload = TRUE;
            break;
        case 'e':
            encrypt = TRUE;
            break;
        case 'p':
        	ddr_perf = TRUE;
            break;
        case 'g':
        	gpu_busy_stats = TRUE;
            break;
        case 'U':
            if (UserParm != NULL)
            {
                free(UserParm);
            }
            UserParm = strdup(optarg);
            break;
        default:
            break;
        }
    }
    
    l_ret_res_mon_enable_logging_U8 = res_mon_enable_logging();

    if (EOK != (int8_t) l_ret_res_mon_enable_logging_U8)
    {
        LOGE("res_mon_enable_logging() failed %d", l_ret_res_mon_enable_logging_U8 );
    }
    if(UserParm != NULL)
    {
			if(procmgr_ability( 0,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_DEBUG ,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_MEM_READ,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_QUERY,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CHILD_NEWAPP,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_WAIT,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIVREG,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CHANNEL_CONNECT,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CONNECTION,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN_SETUID,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN_SETGID,
					    PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO| PROCMGR_AID_EOL )
					    != EOK){
			LOGE ( "%s", "Unable to gain procmgr abilities for nonroot operation \n" );
			exit(EXIT_FAILURE);
			}

			if(set_ids_from_arg(UserParm) != EOK)
			{
			LOGE ("%s:", "Unable to drop to user %s: %s \n");
			exit(EXIT_FAILURE);
			}
				//need to set effective userid or effective groupid to 0 , if resmon need to connect  to /dev/mq/vmf
			if( seteuid( 0 ) == -1 )
			{
				LOGI( "%s", "Unable to set seteuid to 0\n" );
				exit(EXIT_FAILURE);
			}
    }


    ret  = ResMonCommIf_Init( );
    if( ret != RM_OK )
    {
        LOGE ( "ResMon_CommIfInit Failed: %d", ret );
    }

    /* Initialize file transfer interface (DLT) */
    if( upload == TRUE )
    {
       ret = ResMonDltIf_Init ( encrypt );
        if( ret != RM_OK )
        {
            LOGE ( "ResMonDltIf_Init Failed: %d", ret );
        }
    }

    /* Initialize DDR Perf Mon */
    if( ddr_perf == TRUE )
    {
        ret = ResMonDDR_Init ( );
        if( ret != RM_OK )
        {
            LOGE ( "ResMonDDR_Init Failed: %d", ret );
        }
    }

    /* Initialize file extraction interface (VMF) */
    ret = ResMonExtractPackage_Init ( );
    if( ret != RM_OK )
    {
        LOGE ( "ResMonExtractPackage_Init Failed: %d", ret );
    }

    if( gpu_busy_stats == TRUE )
    {
        ResMonQcom_EnableGPUBusyStats();
    }

    while( 1U == g_loop_flag )
    {
        LOGI ( "%s", "RESMON: START" );
        /* Log info */
        ResMonProcfs_Log ( );
        
        if( ddr_perf == TRUE )
        {
            ResMonDDR_Log ( );
        }
                
        LOGI ( "%s", "RESMON: END" );
        sleep(delay);
    }

    /* Shutdown the Components */
    ( void ) ResMonCommIf_Shutdown ( );

	if(UserParm != NULL)
    {

			if(procmgr_ability( 0,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_DEBUG ,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_MEM_READ,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_XPROCESS_QUERY,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CHILD_NEWAPP,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_WAIT,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIVREG,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CHANNEL_CONNECT,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_CONNECTION,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN_SETUID,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SPAWN_SETGID,
					    PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK,
					    PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO| PROCMGR_AID_EOL )
					    != EOK){
			LOGE ( "%s", "Unable to gain procmgr abilities for nonroot operation \n" );
			exit(EXIT_FAILURE);
			}
    free( UserParm);
    }
    return EXIT_SUCCESS;
}
