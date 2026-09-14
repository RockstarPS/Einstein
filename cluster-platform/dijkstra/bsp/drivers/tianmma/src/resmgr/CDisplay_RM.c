/**********************************************************************************
 **
 **  \file CTianma_Display_RM.c
 **
 **  \brief contains Resource Manager API's used to communicate with Display driver.
 **
 **  Component Name: resmgr_display
 **  Archive:
 **  Date: 04-MAY-2020
 **  Author: Rajasekhar
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (�Materials�) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/
/*********************************************************************************
 * @file          CDisplay_RM.c
 * @ingroup       resmgr_display
 * @author        Rajasekhar
 * @brief        Platform driver to control Tianma Display driver configuration
 **********************************************************************************/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <errno.h>          /* Definitions of Error codes */
#include <stdio.h>          /* Standard library */
#include <stdlib.h>         /* Standard library */
#include <stdbool.h>
#include <string.h>         /* For string operations */
#include <unistd.h>         /* Standard library */
#include <devctl.h>         /* For Devctl funcationality */
#include <sys/iofunc.h>     /* Resource Manager required library */
#include <sys/dispatch.h>   /* Resource Manager required library */
#include <sys/neutrino.h>   /* Resource Manager required library */
#include <sys/procmgr.h>    /* For backgrounding the Resource Manager */
#include <sys/resmgr.h>     /* Resource Manager required library */
#include <sys/siginfo.h>    /* For signal handling */
#include <CDisplay_interface.h>
#include <dlfcn.h>
#include "dk_logger.h"
#include "CDisplay_Devctl.h"
#include "CDisplay_ThermalDev.h"

#ifndef VC_UNIT_TEST
#if VBUILD_QNX_MAJOR_VERSION == 7
    #include <login.h>              /* Drop root features */
#elif VBUILD_QNX_MAJOR_VERSION == 8
    #include <secpol/ids.h>
#else
    #error "Unsupported QNX version! Valid values: 7 or 8"
#endif
#endif

#ifdef VC_UNIT_TEST
#include <login.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* coverity[cert_dcl37_c_violation] : FALSE */
#define ERROR -1
#define DISPLAY_RESMGR_MSGSIZE 2048
#define DISPLAY_RM_POSIX_PATH_MAX 256
#define DISPLAY_RM_PATH_MAX 1048U
#define RM_TRUE (int8_t)1
#define RM_FALSE (int8_t)0
#define THERMAL_TYPE "LCD"
typedef struct sigaction ts_sigAction;

#define IO_ATTR_RW_MODE ( mode_t )S_IFREG | ( mode_t )S_IRUSR | ( mode_t )S_IWUSR | ( mode_t )S_IRGRP | ( mode_t )S_IWGRP | ( mode_t )S_IROTH | ( mode_t )S_IWOTH
#define IO_ATTR_READ_MODE ( mode_t )S_IFREG | ( mode_t )S_IRUSR | ( mode_t )S_IRGRP | ( mode_t )S_IROTH

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
typedef struct
{
    dispatch_t              *p_dpp_SP;                           /* Dispatch variable */
    resmgr_attr_t           ts_rattr;                            /* Resource Manager Attributes structure */
    dispatch_context_t      *p_ctp_UP;                           /* disptach context */
    resmgr_connect_funcs_t  ts_connect_funcs;
    resmgr_io_funcs_t       ts_io_funcs;
    iofunc_attr_t           ioattr_power;                        /* iofunc variable */
    iofunc_attr_t           ioattr_state;                        /* iofunc variable */
    iofunc_attr_t           ioattr_gamma_red;                    /* iofunc variable */
    iofunc_attr_t           ioattr_gamma_blue;                   /* iofunc variable */
    iofunc_attr_t           ioattr_gamma_green;                  /* iofunc variable */
    iofunc_attr_t           ioattr_temp_val;                     /* iofunc variable */
    iofunc_attr_t           ioattr_temp_type;                    /* iofunc variable */
    ts_sigAction            sigAct_S;                            /* signal action structure */
    ts_display_funcs        *drventry_S;
    void                    *P_Dll_Hdl;
    uint32_t                display_unit_U32;                    /* display unit*/
    uint32_t                thermal_unit_U32;                    /* Thermal Unit no */
    int32_t                 display_power_path_id_S32;           /* power pathId of display  */
    int32_t                 display_state_path_id_S32;           /* state pathId of display */
    int32_t                 display_gamma_red_path_id_S32;       /* Gamma Red pathId of display */
    int32_t                 display_gamma_green_path_id_S32;     /* Gamma Green pathId of display */
    int32_t                 display_gamma_blue_path_id_S32;      /* Gamma Blue pathId of display */
    int32_t                 thermal_temp_val_path_id_S32;        /* thermal value pathId of display */
    int32_t                 thermal_temp_type_path_id_S32;       /* thermal type pathId of display */
    uint8_t                 dev_node_CHAR[DISPLAY_RM_PATH_MAX];
    uint8_t                 dl_load_path[DISPLAY_RM_PATH_MAX];
} ts_display_dev;

/* ========================================================================== */
/*                             Global Variables                               */
/* ========================================================================== */
static volatile sig_atomic_t t_display_done_SINT = RM_FALSE;  /** Variable to handle SIGTERM signal */
static ts_display_dev displayDev;                       /*Tianma display Device structure */
static char *UserParm = NULL;     /* For drop-root  */
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
static bool getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] );
static int32_t CDisplay_RM_ParseOptions ( int32_t p_argc_SINT, char *const p_argv_CHAR[], ts_display_dev *p_display_dev_SP );
static int32_t CDisplay_RM_Init ( ts_display_dev *p_display_dev_SP );
static int32_t CDisplay_Hw_Init ( ts_display_dev *p_display_dev_SP );
static void *CDisplay_Dlload ( void **hdl, uint8_t *p_dl_load_path_CHAR );
static void  CDisplay_RM_ExitSignal ( int32_t p_signo_SINT );
static int32_t CDisplay_RM_Terminate ( void );
static int32_t CDisplay_RM_io_open ( resmgr_context_t *p_ctp_SP, io_open_t  *p_msg_UP, RESMGR_HANDLE_T *p_handle_SP, void *p_extra_VP );
static int32_t CDisplay_RM_io_read ( resmgr_context_t *p_ctp_SP, io_read_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP );
static int32_t CDisplay_RM_io_write ( resmgr_context_t *p_ctp_SP, io_write_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP );
static int32_t CDisplay_RM_io_devctl ( resmgr_context_t *p_ctp_SP, io_devctl_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP );
static int32_t CDisplay_RM_Set_Power ( uint8_t *p_power_val_U8 );
static int32_t CDisplay_Deinit ( void );
static void CDisplay_RM_usage ( void );

static void CDisplay_RM_usage ( void )
{
    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
    ( void ) printf ( "Usage: <-p>panel unit \n"
             "<-t>Thermal unit \n"
             "[-d]serial device node path \n"
             "<-l>display lib path \n"
             "<-U>set uid:gid \n" );
}

LOG_DECLARE_CONTEXT ( gResMgrDisplayLogContext );

/*!*******************************************************************************************************************
Function Name: main
@brief     Main function for Display Resource Manager
@param[in] p_argc_SINT int Count of command line parameters for the Resource manager.
@param[in] p_argv_CHAR[] char**  Command line parameters for the resource manager
@return    int32_t    Error code to indicate success or failure
 *********************************************************************************************************************/
int32_t main ( int32_t p_argc_SINT, char *const p_argv_CHAR[] )
{
    int32_t l_exit_value_S32 = EXIT_SUCCESS;
    int32_t l_ret_handler_S32 = EOK;

    LOG_REGISTER_APP_SLOG2("ResMgrDisplay","ResMgr_Display");
    LOG_REGISTER_CONTEXT(gResMgrDisplayLogContext, "ResMgrDisplay", "ResMgr_Display Component", DLT_LOG_WARN);

    LOGI (&gResMgrDisplayLogContext, "starting... Display RM" );
    l_ret_handler_S32 = CDisplay_RM_ParseOptions ( p_argc_SINT, p_argv_CHAR, &displayDev );

    if ( l_ret_handler_S32 == ( uint8_t ) EOK )
    {
        if (UserParm != NULL)
        {
            if(procmgr_ability( 0,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SETGID,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SETUID,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PROT_EXEC,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PATHSPACE,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_POWER,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_SIGNAL,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK | PROCMGR_AID_EOL )
                        != EOK)
            {
                LOGE(&gResMgrDisplayLogContext,"Unable to gain procmgr abilities for nonroot operation\n");
                l_ret_handler_S32 = EXIT_FAILURE;

            }

            if(set_ids_from_arg(UserParm) != EOK)
            {
                if(__get_errno_ptr() != NULL)
                {
                    /* coverity[cert_con33_c_violation] : FALSE */
                    LOGE(&gResMgrDisplayLogContext, "Unable to drop to user %s: %s", UserParm, strerror(errno));
                }
                l_ret_handler_S32 = EXIT_FAILURE;
            }
            //need to set effective userid or effective groupid to 0 , if we need to attach screen to resmgr_display.
            if( seteuid( 0 ) == -1 )
            {
                LOGE(&gResMgrDisplayLogContext,  "Unable to set seteuid to 0\n" );
                l_ret_handler_S32 = EXIT_FAILURE;
            }
        }
        if ( EXIT_SUCCESS == l_ret_handler_S32 )
        {
            /*CDisplay_RM - init sequence */
            l_ret_handler_S32 = CDisplay_RM_Init ( &displayDev );

            if ( EXIT_SUCCESS == l_ret_handler_S32 )
            {
                l_ret_handler_S32 = CDisplay_Hw_Init ( &displayDev );

                if ( EXIT_SUCCESS == l_ret_handler_S32 )
                {
                     /** Provide handling for the SIGTERM signal */
                    ( void ) sigemptyset ( &displayDev.sigAct_S.sa_mask );
                    ( void ) sigaddset ( &displayDev.sigAct_S.sa_mask, SIGTERM );
                    displayDev.sigAct_S.sa_handler = CDisplay_RM_ExitSignal;
                    displayDev.sigAct_S.sa_flags = 0;
                    ( void ) sigaction ( SIGTERM, &displayDev.sigAct_S, NULL );

                     /* background the process */
                    ( void ) procmgr_daemon ( 0, (uint32_t) PROCMGR_DAEMON_NOCLOSE | (uint32_t) PROCMGR_DAEMON_NODEVNULL );

                    /* Receive messages till SIGTERM is sent */
                    while ( RM_FALSE == t_display_done_SINT )
                    {
                        displayDev.p_ctp_UP = dispatch_block ( displayDev.p_ctp_UP );

                        if ( NULL == displayDev.p_ctp_UP )
                        {
                            LOGE (&gResMgrDisplayLogContext, "Dispatch Block Failed" );
                            l_exit_value_S32 = EXIT_FAILURE;

                            if ( RM_TRUE == t_display_done_SINT )
                            {
                                l_exit_value_S32 = EXIT_SUCCESS;
                            }
                             else
                            {
                                /* Do nothing. Compliant to Visteon coding rules */
                            }

                            break;
                        }
                        else
                        {
                            l_ret_handler_S32 = dispatch_handler ( displayDev.p_ctp_UP );

                            if ( l_ret_handler_S32 != ( int32_t ) 0 )
                            {
                                LOGE (&gResMgrDisplayLogContext, "dispatch_handler has failed\n" );
                                l_exit_value_S32 = EXIT_FAILURE;
                            }
                            else
                            {
                                /*MISRA*/
                            }
                        }

#ifdef VC_UNIT_TEST
                        t_display_done_SINT = RM_TRUE;
#endif
                    }
                }
                else
                {
                    l_exit_value_S32 = EXIT_FAILURE;
                    LOGE (&gResMgrDisplayLogContext, "Display RM HwIf Init failed ");
                }
            }
            else
            {
                l_exit_value_S32 = EXIT_FAILURE;
                LOGE (&gResMgrDisplayLogContext, "Display RM init failed" );
            }
        }
    }
    else
    {
        l_exit_value_S32 = EXIT_FAILURE;
        LOGE (&gResMgrDisplayLogContext, "Display RM options parse fail" );
    }

    l_ret_handler_S32 = CDisplay_RM_Terminate();

    if ( EXIT_SUCCESS != l_ret_handler_S32 )
    {
        l_exit_value_S32 = EXIT_FAILURE;
        LOGE (&gResMgrDisplayLogContext, "Display RM Terminate Failed Exiting...." );
    }

    //Drop procmgr ability
    if(UserParm != NULL)
    {
            if(procmgr_ability( 0,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_SETGID,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_SETUID,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_PROT_EXEC,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_PATHSPACE,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_POWER,
                        PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_SIGNAL| PROCMGR_AID_EOL )
                        != EOK)
            {
            LOGE(&gResMgrDisplayLogContext, "Unable to gain procmgr abilities for nonroot operation\n");
            l_exit_value_S32 = EXIT_FAILURE;
            }
        /* coverity[misra_c_2012_rule_21_3_violation] : FALSE */
        free( UserParm);
    }

    LOG_UNREGISTER_CONTEXT(gResMgrDisplayLogContext);

    return l_exit_value_S32;
}

/*!****************************************************************************
Function Name: CDisplay_RM_Init
@brief     Display RM init, creates the path name spaces and the related infrastructure
@param[in] p_display_dev_SP display Device structure
@return    int32_t    success or failure
 *****************************************************************************/

static int32_t CDisplay_RM_Init ( ts_display_dev *p_display_dev_SP )
{
    int32_t l_ret_S32 = EXIT_SUCCESS;
    p_display_dev_SP->p_dpp_SP = dispatch_create();

    if ( NULL == p_display_dev_SP->p_dpp_SP )
    {
        LOGE (&gResMgrDisplayLogContext, "dispatch_create() failed" );
        l_ret_S32 = ENOMEM;
    }
    else
    {
        /* Initialize RM Attributes */
        ( void ) memset ( &p_display_dev_SP->ts_rattr, 0, sizeof ( p_display_dev_SP->ts_rattr ) );
        p_display_dev_SP->ts_rattr.nparts_max     = 1U;     // max ctp_SP->iov[] size
        p_display_dev_SP->ts_rattr.msg_max_size   = DISPLAY_RESMGR_MSGSIZE;  // max size of a message

        /* Initialize functions used to handle message */
        iofunc_func_init (
            /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
            _RESMGR_CONNECT_NFUNCS,
            &p_display_dev_SP->ts_connect_funcs,
            /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
            _RESMGR_IO_NFUNCS,
            &p_display_dev_SP->ts_io_funcs
        );
        p_display_dev_SP->ts_connect_funcs.open = CDisplay_RM_io_open;
        p_display_dev_SP->ts_io_funcs.read      = CDisplay_RM_io_read;
        p_display_dev_SP->ts_io_funcs.write     = CDisplay_RM_io_write;
        p_display_dev_SP->ts_io_funcs.devctl    = CDisplay_RM_io_devctl;

        /* initialize export attribute structure used by the device */
        iofunc_attr_init ( &p_display_dev_SP->ioattr_power, IO_ATTR_RW_MODE, NULL, NULL );
        char l_path_U8P[DISPLAY_RM_PATH_MAX];
        ( void ) memset ( ( void * ) l_path_U8P, 0, DISPLAY_RM_PATH_MAX );
        /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
        ( void ) snprintf ( l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/display/display%u/power", p_display_dev_SP->display_unit_U32 );
        p_display_dev_SP->display_power_path_id_S32 = resmgr_attach ( p_display_dev_SP->p_dpp_SP,
                &p_display_dev_SP->ts_rattr,
                l_path_U8P,
                _FTYPE_ANY,
                0,
                &p_display_dev_SP->ts_connect_funcs,
                &p_display_dev_SP->ts_io_funcs,
                &p_display_dev_SP->ioattr_power );

        if ( ERROR != p_display_dev_SP->display_power_path_id_S32 )
        {
            LOGD (&gResMgrDisplayLogContext,  "attached power path " );
        }
        else
        {
            LOGE(&gResMgrDisplayLogContext, "couldn't attach power path ");
            l_ret_S32 = EXIT_FAILURE;
        }

        if ( EXIT_FAILURE != l_ret_S32)
        {
            iofunc_attr_init ( &p_display_dev_SP->ioattr_state, IO_ATTR_READ_MODE, NULL, NULL );
            if(UserParm != NULL)
            {
                iofunc_attr_init ( &p_display_dev_SP->ioattr_state, IO_ATTR_RW_MODE, NULL, NULL );
            }
            else
            {
                /* MISRA*/
            }
            ( void ) memset ( ( void * ) l_path_U8P, 0, DISPLAY_RM_PATH_MAX );
            /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
            ( void ) snprintf ( l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/display/display%u/state", p_display_dev_SP->display_unit_U32 );
            p_display_dev_SP->display_state_path_id_S32 = resmgr_attach ( p_display_dev_SP->p_dpp_SP,
                    &p_display_dev_SP->ts_rattr,
                    l_path_U8P,
                    _FTYPE_ANY,
                    0,
                    &p_display_dev_SP->ts_connect_funcs,
                    &p_display_dev_SP->ts_io_funcs,
                    &p_display_dev_SP->ioattr_state );

            if ( ERROR != p_display_dev_SP->display_state_path_id_S32 )
            {
                LOGD (&gResMgrDisplayLogContext,  "attached state path " );
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach power state path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
            iofunc_attr_init(&p_display_dev_SP->ioattr_gamma_red, IO_ATTR_RW_MODE, NULL, NULL);
            (void)memset((void *)l_path_U8P, 0, DISPLAY_RM_PATH_MAX);
            /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
            (void)snprintf(l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/display/display%u/gamma_red", p_display_dev_SP->display_unit_U32);
            p_display_dev_SP->display_gamma_red_path_id_S32 = resmgr_attach(p_display_dev_SP->p_dpp_SP,
                                                                        &p_display_dev_SP->ts_rattr,
                                                                        l_path_U8P,
                                                                        _FTYPE_ANY,
                                                                        0,
                                                                        &p_display_dev_SP->ts_connect_funcs,
                                                                        &p_display_dev_SP->ts_io_funcs,
                                                                        &p_display_dev_SP->ioattr_gamma_red);

            if ( ERROR != p_display_dev_SP->display_gamma_red_path_id_S32 )
            {
                LOGD(&gResMgrDisplayLogContext, "attached gamma red path ");
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach gamma red path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
            iofunc_attr_init(&p_display_dev_SP->ioattr_gamma_green, IO_ATTR_RW_MODE, NULL, NULL);
            (void)memset((void *)l_path_U8P, 0, DISPLAY_RM_PATH_MAX);
            /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
            (void)snprintf(l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/display/display%u/gamma_green", p_display_dev_SP->display_unit_U32);
            p_display_dev_SP->display_gamma_green_path_id_S32 = resmgr_attach(p_display_dev_SP->p_dpp_SP,
                                                                        &p_display_dev_SP->ts_rattr,
                                                                        l_path_U8P,
                                                                        _FTYPE_ANY,
                                                                        0,
                                                                        &p_display_dev_SP->ts_connect_funcs,
                                                                        &p_display_dev_SP->ts_io_funcs,
                                                                        &p_display_dev_SP->ioattr_gamma_green);

            if ( ERROR != p_display_dev_SP->display_gamma_green_path_id_S32 )
            {
                LOGD(&gResMgrDisplayLogContext, "attached gamma green path ");
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach gamma green path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
            iofunc_attr_init(&p_display_dev_SP->ioattr_gamma_blue, IO_ATTR_RW_MODE, NULL, NULL);
            (void)memset((void *)l_path_U8P, 0, DISPLAY_RM_PATH_MAX);
            /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
            (void)snprintf(l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/display/display%u/gamma_blue", p_display_dev_SP->display_unit_U32);
            p_display_dev_SP->display_gamma_blue_path_id_S32 = resmgr_attach(p_display_dev_SP->p_dpp_SP,
                                                                        &p_display_dev_SP->ts_rattr,
                                                                        l_path_U8P,
                                                                        _FTYPE_ANY,
                                                                        0,
                                                                        &p_display_dev_SP->ts_connect_funcs,
                                                                        &p_display_dev_SP->ts_io_funcs,
                                                                        &p_display_dev_SP->ioattr_gamma_blue);

            if ( ERROR != p_display_dev_SP->display_gamma_blue_path_id_S32 )
            {
                LOGD(&gResMgrDisplayLogContext, "attached gamma blue path ");
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach gamma blue path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
                iofunc_attr_init ( &p_display_dev_SP->ioattr_temp_val, IO_ATTR_READ_MODE, NULL, NULL );
                if(UserParm != NULL)
                {
                    iofunc_attr_init ( &p_display_dev_SP->ioattr_temp_val, IO_ATTR_RW_MODE, NULL, NULL );
                }
                else
                {
                    /* MISRA*/
                }
                ( void ) memset ( ( void * ) l_path_U8P, 0, DISPLAY_RM_PATH_MAX );
                /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                ( void ) snprintf ( l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/thermal/thermal%u/temperature/value", p_display_dev_SP->thermal_unit_U32 );
                p_display_dev_SP->thermal_temp_val_path_id_S32 = resmgr_attach ( p_display_dev_SP->p_dpp_SP,
                        &p_display_dev_SP->ts_rattr,
                        l_path_U8P,
                        _FTYPE_ANY,
                        0,
                        &p_display_dev_SP->ts_connect_funcs,
                        &p_display_dev_SP->ts_io_funcs,
                        &p_display_dev_SP->ioattr_temp_val );

                if ( ERROR != p_display_dev_SP->thermal_temp_val_path_id_S32 )
                {
                    LOGD (&gResMgrDisplayLogContext,  "attached Temparature val path " );
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach Temparature value path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
                    iofunc_attr_init ( &p_display_dev_SP->ioattr_temp_type, IO_ATTR_READ_MODE, NULL, NULL );
                    if(UserParm != NULL)
                    {
                        iofunc_attr_init ( &p_display_dev_SP->ioattr_temp_type, IO_ATTR_RW_MODE, NULL, NULL );
                    }
                    else
                    {
                        /* MISRA*/
                    }
                    ( void ) memset ( ( void * ) l_path_U8P, 0, DISPLAY_RM_PATH_MAX );
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    ( void ) snprintf ( l_path_U8P, DISPLAY_RM_PATH_MAX, "/dev/thermal/thermal%u/temperature/type", p_display_dev_SP->thermal_unit_U32 );
                    p_display_dev_SP->thermal_temp_type_path_id_S32 = resmgr_attach ( p_display_dev_SP->p_dpp_SP,
                            &p_display_dev_SP->ts_rattr,
                            l_path_U8P,
                            _FTYPE_ANY,
                            0,
                            &p_display_dev_SP->ts_connect_funcs,
                            &p_display_dev_SP->ts_io_funcs,
                            &p_display_dev_SP->ioattr_temp_type );

                    if ( ERROR != p_display_dev_SP->thermal_temp_type_path_id_S32 )
                    {
                        LOGD (&gResMgrDisplayLogContext,  "attached Temparature type path " );
            }
            else
            {
                LOGE(&gResMgrDisplayLogContext, "couldn't attach Temparature type path ");
                l_ret_S32 = EXIT_FAILURE;
            }
        }

        if ( EXIT_FAILURE != l_ret_S32 )
        {
                        p_display_dev_SP->p_ctp_UP = dispatch_context_alloc ( p_display_dev_SP->p_dpp_SP );

                        if ( p_display_dev_SP->p_ctp_UP == NULL )
                        {
                            LOGE (&gResMgrDisplayLogContext, "Dispatch context allocation failed" );
                            l_ret_S32 = EXIT_FAILURE;
                        }
                        else
                        {
                            LOGD (&gResMgrDisplayLogContext,  "Dispatch context allocation Success" );
                        }
                    }
    }

    return l_ret_S32;
}

/*!****************************************************************************
Function Name: CDisplay_Hw_Init
@brief     Function that is called to do IO Mapping with the banks having bits set more than 0
@param[in] p_display_dev_SP display Device structure
@return    int32_t    success or failure
 *****************************************************************************/
static int32_t CDisplay_Hw_Init ( ts_display_dev *p_display_dev_SP )
{
    int32_t     l_status_S32 = EXIT_SUCCESS;
    p_display_dev_SP->drventry_S = NULL;
    void *l_dlhdl = NULL;
    void *l_drventry = NULL;
    l_drventry = CDisplay_Dlload ( &l_dlhdl, p_display_dev_SP->dl_load_path );

    if ( NULL != l_drventry )
    {
        LOGD (&gResMgrDisplayLogContext,  "Display dll load success" );
        p_display_dev_SP->drventry_S = ( ts_display_funcs * ) ( l_drventry );
        p_display_dev_SP->P_Dll_Hdl = l_dlhdl;
        l_status_S32 = p_display_dev_SP->drventry_S->Init_Display();

        if ( EXIT_SUCCESS != l_status_S32 )
        {
            LOGE (&gResMgrDisplayLogContext, "Display Hw init failed" );
        }
        else
        {
            LOGD (&gResMgrDisplayLogContext,  "Display Hw init success" );
        }
    }
    else
    {
        l_status_S32 = EXIT_FAILURE;
        LOGE (&gResMgrDisplayLogContext, "display dll init failed" );
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_RM_io_open
 @brief     Function for open. This function is called when an application
            calls the open() function.
 @param[in] p_ctp_SP - resmgr_context_t* Resource Manager Context
 @param[in] p_msg_UP - io_open_t* io_open message structure. Contains the
            message that the Resource Manager received.
 @param[in] p_handle_SP - RESMGR_HANDLE_T* defines the characteristics of the
            device that the resource manager is controlling
 @param[in] p_extra_VP - void* Extra information from the library
 @return    int32_t - Return value to indicate success or error code
 *****************************************************************************/
static int32_t CDisplay_RM_io_open ( resmgr_context_t *p_ctp_SP, io_open_t  *p_msg_UP, RESMGR_HANDLE_T *p_handle_SP, void *p_extra_VP )
{
    int32_t l_status_S32 = 0;
    l_status_S32 = iofunc_open_default ( p_ctp_SP, p_msg_UP, p_handle_SP, p_extra_VP );

    if ( EOK != l_status_S32 )
    {
        LOGE (&gResMgrDisplayLogContext, "Display RM can't open pathId %d ", p_ctp_SP->id );
        l_status_S32 = ENOMEM;
    }
    else
    {
        LOGD (&gResMgrDisplayLogContext,  "Display RM Open Success" );
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_RM_io_read
 @brief     Function for open. This function is called when an application
            calls the open() function.
 @param[in] p_ctp_SP - resmgr_context_t* Resource Manager Context
 @param[in] p_msg_UP - io_open_t* io_open message structure. Contains the
            message that the Resource Manager received.
 @param[in] p_ocb_SP - RESMGR_OCB_T* RM open control block of the pathname space
 @return    int32_t - Return value to indicate success or error code
 *****************************************************************************/

static int32_t CDisplay_RM_io_read ( resmgr_context_t *p_ctp_SP, io_read_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP )
{
    size_t      l_nleft_U64 = 0;
    size_t      l_nbytes_U64 = 0;
    int32_t     l_nparts_S32 = 0;
    int32_t     l_status_S32 = 0;
    static      uint8_t l_buf_U8[DISPLAY_RESMGR_MSGSIZE];
    uint8_t     l_buf_val_U8 = 0;

    /* Here we verify if the client has the access
     * rights needed to read from our device */
    l_status_S32 = iofunc_read_verify ( p_ctp_SP, p_msg_UP, p_ocb_SP, NULL );

    if ( EOK != l_status_S32 )
    {
        LOGE (&gResMgrDisplayLogContext, "Display RM io read failed" );
    }
    else
    {
        /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
        /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
        if ( ( p_msg_UP->i.xtype & ( uint32_t ) ( _IO_XTYPE_MASK ) ) != ( uint32_t ) ( _IO_XTYPE_NONE  ))
        {
            l_status_S32 = ENOSYS;
        }
        else
        {
            ( void ) memset ( l_buf_U8, 0, sizeof ( l_buf_U8 ) );

            if ( p_ctp_SP->id == displayDev.display_power_path_id_S32 )
            {
                l_status_S32 = displayDev.drventry_S->Get_Display_Power ( &l_buf_val_U8 );

                LOGD (&gResMgrDisplayLogContext,  "*****Display power read success %d", l_buf_val_U8 );

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    ( void ) sprintf  ( ( char * ) l_buf_U8, "%u\n", l_buf_val_U8 );
                    l_nbytes_U64 = strlen ( ( char * ) l_buf_U8 );
                     /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = ( ssize_t ) l_nbytes_U64;
                    LOGD (&gResMgrDisplayLogContext,  "Display power read success %s", l_buf_U8 );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display power read failed" );
                }
            }
            else if ( p_ctp_SP->id == displayDev.display_state_path_id_S32 )
            {
                l_status_S32 = displayDev.drventry_S->Get_Display_state ( l_buf_U8 );

                if ( EOK == l_status_S32 )
                {
                    l_nbytes_U64 = strlen ( ( char * ) l_buf_U8 );
                     /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = ( ssize_t ) l_nbytes_U64;
                    LOGD (&gResMgrDisplayLogContext,  "Display state read success %s", l_buf_U8 );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display state read failed" );
                }
            }
            else if ( p_ctp_SP->id == displayDev.thermal_temp_val_path_id_S32 )
            {
                l_status_S32 = displayDev.drventry_S->Get_Thermal_Temperature_Value ( &l_buf_val_U8 );

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    ( void ) sprintf  ( ( char * ) l_buf_U8, "%u\n", l_buf_val_U8 );
                    /* coverity[cert_int30_c_violation] : FALSE */
                    l_nbytes_U64 = strlen ( ( char * ) l_buf_U8 ) + ( size_t ) 1;
                     /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = ( ssize_t ) l_nbytes_U64;
                    LOGD (&gResMgrDisplayLogContext,  "Display Thermal Temp read success" );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display Thermal Temp read failed" );
                }
            }
            else if ( p_ctp_SP->id == displayDev.thermal_temp_type_path_id_S32 )
            {
                ( void ) strncpy ( ( char * ) l_buf_U8, THERMAL_TYPE, strlen ( THERMAL_TYPE ) + 1U );
                ( void ) strncat ( ( char * ) l_buf_U8, "\n", strlen ( "\n" ) );
                 /* coverity[cert_str32_c_violation] : FALSE */
                 /* coverity[cert_int30_c_violation] : FALSE */
                l_nbytes_U64 = strlen ( ( char * ) l_buf_U8 ) + ( size_t ) 1;
                 /* coverity[cert_int31_c_violation] : FALSE */
                p_ocb_SP->attr->nbytes = ( ssize_t ) l_nbytes_U64;
            }
            else if ( p_ctp_SP->id == displayDev.display_gamma_red_path_id_S32 )
            {
                /* coverity[cert_arr37_c_violation] : FALSE */
                display_gamma_rgb_type_ts *l_out_SP = (display_gamma_rgb_type_ts *)(_DEVCTL_DATA((p_msg_UP->i)));
                l_status_S32 = displayDev.drventry_S->Get_Gamma_RGB_Devctl(&l_out_SP->gamma_red, &l_out_SP->gamma_green, &l_out_SP->gamma_blue);

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    (void)sprintf((char *)l_buf_U8, "%d\n", l_out_SP->gamma_red);
    
                    /* coverity[cert_int30_c_violation] : FALSE */
                    l_nbytes_U64 = strlen((char *)l_buf_U8) + (size_t)1;
                    /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = (ssize_t)l_nbytes_U64;
                    LOGD(&gResMgrDisplayLogContext, "Display Gamma Red read success");
                }
                else
                {
                    LOGE(&gResMgrDisplayLogContext, "Display Gamma Red read failed");
                }
            }
            else if ( p_ctp_SP->id == displayDev.display_gamma_green_path_id_S32 )
            {
                /* coverity[cert_arr37_c_violation] : FALSE */
                display_gamma_rgb_type_ts *l_out_SP = (display_gamma_rgb_type_ts *)(_DEVCTL_DATA((p_msg_UP->i)));
                l_status_S32 = displayDev.drventry_S->Get_Gamma_RGB_Devctl(&l_out_SP->gamma_red, &l_out_SP->gamma_green, &l_out_SP->gamma_blue);

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    (void)sprintf((char *)l_buf_U8, "%d\n", l_out_SP->gamma_green);
                    /* coverity[cert_int30_c_violation] : FALSE */
                    l_nbytes_U64 = strlen((char *)l_buf_U8) + (size_t)1;
                    /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = (ssize_t)l_nbytes_U64;
                    LOGD(&gResMgrDisplayLogContext, "Display Gamma Green read success");
                }
                else
                {
                    LOGE(&gResMgrDisplayLogContext, "Display Gamma Green read failed");
                }
            }
            else if ( p_ctp_SP->id == displayDev.display_gamma_blue_path_id_S32 )
            {
                /* coverity[cert_arr37_c_violation] : FALSE */
                display_gamma_rgb_type_ts *l_out_SP = (display_gamma_rgb_type_ts *)(_DEVCTL_DATA((p_msg_UP->i)));
                l_status_S32 = displayDev.drventry_S->Get_Gamma_RGB_Devctl(&l_out_SP->gamma_red, &l_out_SP->gamma_green, &l_out_SP->gamma_blue);

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
                    (void)sprintf((char *)l_buf_U8, "%d\n", l_out_SP->gamma_blue);
                    /* coverity[cert_int30_c_violation] : FALSE */
                    l_nbytes_U64 = strlen((char *)l_buf_U8) + (size_t)1;
                    /* coverity[cert_int31_c_violation] : FALSE */
                    p_ocb_SP->attr->nbytes = (ssize_t)l_nbytes_U64;
                    LOGD(&gResMgrDisplayLogContext, "Display Gamma Blue read success");
                }
                else
                {
                    LOGE(&gResMgrDisplayLogContext, "Display Gamma Blue read failed");
                }
            }
            else
            {
                /* MISRA */
            }
        }
    }

    if ( EOK == l_status_S32 )
    {
         /* coverity[cert_int31_c_violation] : FALSE */
        l_nleft_U64 = ( size_t ) p_ocb_SP->attr->nbytes - ( size_t ) p_ocb_SP->offset;
        /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
        l_nbytes_U64 = min ( _IO_READ_GET_NBYTES ( p_msg_UP ), l_nleft_U64 );

        if ( l_nbytes_U64 > ( size_t ) 0 )
        {
            /* set up the return data IOV */
            /* coverity[cert_arr30_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_12_3_violation] : FALSE */
            SETIOV ( p_ctp_SP->iov, l_buf_U8 + p_ocb_SP->offset, l_nbytes_U64 );
            /* set up the number of bytes (l_returned by client's read()) */
            _IO_SET_READ_NBYTES ( p_ctp_SP, ( ssize_t ) l_nbytes_U64 );
            p_ocb_SP->offset += ( ssize_t ) l_nbytes_U64;
            l_nparts_S32 = 1;
        }
        else
        {
            _IO_SET_READ_NBYTES ( p_ctp_SP, 0 );
            l_nparts_S32 = 0;
        }

        /* mark the access time as invalid (we just accessed it) */
        if ( p_msg_UP->i.nbytes > ( uint32_t ) 0 )
        {
            p_ocb_SP->attr->flags |= ( uint32_t ) ( IOFUNC_ATTR_ATIME );
        }

        l_status_S32 = _RESMGR_NPARTS ( l_nparts_S32 );
    }
    else
    {
        /* MISRA*/
    }


    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_RM_io_read
 @brief     Function for open. This function is called when an application
            calls the open() function.
 @param[in] p_ctp_SP - resmgr_context_t* Resource Manager Context
 @param[in] p_msg_UP - io_write_t* io_open message structure. Contains the
            message that the Resource Manager received.
 @param[in] p_ocb_SP - RESMGR_OCB_T* RM open control block of the pathname space
 @return    int32_t - Return value to indicate success or error code
 *****************************************************************************/
static int32_t CDisplay_RM_io_write ( resmgr_context_t *p_ctp_SP, io_write_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP )
{
    int32_t l_status_S32 = 0;
    size_t  l_nbytes_U64 = 0;
    uint8_t l_buf_val_U8 = 0;
    int32_t l_buf_val_S32 = 0;
    int32_t l_err_S32 = 0;
    static uint8_t l_buf_U8[DISPLAY_RESMGR_MSGSIZE];
    l_status_S32 = iofunc_write_verify ( p_ctp_SP, p_msg_UP, p_ocb_SP, NULL );

    if ( EOK != l_status_S32 )
    {
        LOGE (&gResMgrDisplayLogContext, "Display RM io write failed" );
    }
    else
    {
        if ( ( p_msg_UP->i.xtype & ( uint32_t ) ( _IO_XTYPE_MASK ) ) != ( uint32_t ) ( _IO_XTYPE_NONE ) )
        {
            l_status_S32 = ENOSYS;
        }
        else
        {

            /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
            l_nbytes_U64 = _IO_WRITE_GET_NBYTES ( p_msg_UP );

            /* coverity[cert_int30_c_violation] : FALSE */
            /* coverity[cert_int31_c_violation] : FALSE */
            if ( l_nbytes_U64 > ( ( size_t ) p_ctp_SP->info.srcmsglen - ( size_t ) p_ctp_SP->offset - sizeof ( io_write_t ) ) )
            {
                l_status_S32 = EBADMSG;
                LOGE (&gResMgrDisplayLogContext, "Display RM Malicious Write request" );
            }
            else
            {
                ( void ) memset ( l_buf_U8, 0, sizeof ( l_buf_U8 ) );
                _IO_SET_WRITE_NBYTES ( p_ctp_SP, ( ssize_t ) l_nbytes_U64 );

                if ( resmgr_msgread ( p_ctp_SP, l_buf_U8, l_nbytes_U64, sizeof ( p_msg_UP->i ) ) == ERROR )
                {
                    l_status_S32 = EXIT_FAILURE;
                    LOGE (&gResMgrDisplayLogContext, "Read message from  client failed l_status_S32 = %d", l_status_S32 );
                }
                else
                {
                    if ( p_ctp_SP->id == displayDev.display_power_path_id_S32 )
                    {
                       errno = 0;
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[cert_exp34_c_violation] : FALSE */
                        /* coverity[cert_err30_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
                        l_buf_val_U8 = ( uint8_t ) strtoul ( ( const char * ) l_buf_U8, NULL, 0 );
                        l_err_S32 = errno;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        if (( l_err_S32 == EINVAL ) || ( l_err_S32 == ERANGE ))
                        {
                            l_status_S32 = EXIT_FAILURE;
                            LOGE (&gResMgrDisplayLogContext, "Invalid Input strtoul failed : %d", l_buf_val_U8 );

                        }
                        else
                        {
                            l_status_S32 = CDisplay_RM_Set_Power ( &l_buf_val_U8 );
                        }
                    }
                    else if ( p_ctp_SP->id == displayDev.display_gamma_red_path_id_S32)
                    {
                        errno = 0;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
                        l_buf_val_S32 = (int32_t)strtoul((const char *)l_buf_U8, NULL, 0);
                        l_err_S32 = errno;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        if ((l_err_S32 == EINVAL) || (l_err_S32 == ERANGE))
                        {
                            l_status_S32 = EXIT_FAILURE;
                            /* coverity[cert_exp33_c_violation] : FALSE */
                            LOGE(&gResMgrDisplayLogContext, "Invalid Input strtoul failed : %d", l_buf_val_S32);
                        }
                        else
                        {
                            l_status_S32 = displayDev.drventry_S->Set_Gamma_RGB_Devctl(l_buf_val_S32, -1, -1);
                        }
                    }
                    else if ( p_ctp_SP->id == displayDev.display_gamma_green_path_id_S32)
                    {
                        errno = 0;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
                        l_buf_val_S32 = (int32_t)strtoul((const char *)l_buf_U8, NULL, 0);
                        l_err_S32 = errno;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        if ((l_err_S32 == EINVAL) || (l_err_S32 == ERANGE))
                        {
                            l_status_S32 = EXIT_FAILURE;
                            /* coverity[cert_exp33_c_violation] : FALSE */
                            LOGE(&gResMgrDisplayLogContext, "Invalid Input strtoul failed : %d", l_buf_val_S32);
                        }
                        else
                        {
                            l_status_S32 = displayDev.drventry_S->Set_Gamma_RGB_Devctl(-1, l_buf_val_S32, -1);
                        }
                    }
                    else if ( p_ctp_SP->id == displayDev.display_gamma_blue_path_id_S32)
                    {
                         errno =0;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
                        l_buf_val_S32 = (int32_t)strtoul((const char *)l_buf_U8, NULL, 0);
                        l_err_S32 = errno;
                        /* coverity[cert_err30_c_violation] : FALSE */
                        if ((l_err_S32 == EINVAL) || (l_err_S32 == ERANGE))
                        {
                            l_status_S32 = EXIT_FAILURE;
                            /* coverity[cert_exp33_c_violation] : FALSE */
                            LOGE(&gResMgrDisplayLogContext, "Invalid Input strtoul failed : %d", l_buf_val_S32);
                        }
                        else
                        {
                            l_status_S32 = displayDev.drventry_S->Set_Gamma_RGB_Devctl(-1, -1, l_buf_val_S32);
                        }
                    }
                    else
                    {
                        l_status_S32 = EBADF;
                        LOGE (&gResMgrDisplayLogContext, "invalid pathname to perform write operation" );
                    }
                }
            }

        }

    }

    if ( l_status_S32 == EOK )
    {
        if ( l_nbytes_U64 > ( size_t ) 0 )
        {
            p_ocb_SP->attr->flags |= (uint32_t)IOFUNC_ATTR_MTIME | (uint32_t)IOFUNC_ATTR_CTIME;
        }

        l_status_S32 = _RESMGR_NPARTS ( 0 );
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: io_devctl
 @brief     Function for devctl. This function is called when an application
            calls a devctl() function.
 @param[in] p_ctp_SP - resmgr_context_t* Resource Manager Context
 @param[in] p_msg_UP - io_devctl_t* io_open message structure. Contains the
            message that the Resource Manager received.
 @param[in] p_ocb_SP - RESMGR_OCB_T* OCB Structure
 @return    int32_t - Return value to indicate success or error code
 *****************************************************************************/

static int32_t CDisplay_RM_io_devctl ( resmgr_context_t *p_ctp_SP, io_devctl_t *p_msg_UP,
                                       RESMGR_OCB_T *p_ocb_SP )
{
    int32_t l_status_S32 = EOK;
    int32_t l_nbytes_S32 = 0;

    l_status_S32 = iofunc_devctl_default ( p_ctp_SP, p_msg_UP, p_ocb_SP );

    /* coverity[cert_int31_c_violation] : FALSE */
    if ( _RESMGR_DEFAULT != l_status_S32 )
    {
        l_status_S32 = EAGAIN;
        LOGE (&gResMgrDisplayLogContext, "Display RM Devctl Default failed " );
    }
    else
    {
        if ( p_ctp_SP->id == displayDev.display_power_path_id_S32 )
        {
            /* coverity[cert_arr37_c_violation] : FALSE */
            display_power_buffer_type_ts *l_out_SP = ( display_power_buffer_type_ts * ) ( _DEVCTL_DATA (( p_msg_UP->i )));

            switch ( p_msg_UP->i.dcmd )
            {
            case POWER_ID_VALUE_READ:
            {
                l_status_S32 = displayDev.drventry_S->Get_Display_Power_Devctl ( &l_out_SP->power_U8 );

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32  = sizeof ( display_power_buffer_type_ts );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display Power read devctl Failed" );
                }

                break;
            }

            case POWER_ID_VALUE_WRITE:
            {
                uint8_t l_power_value_U8 = l_out_SP->power_U8;
                l_status_S32 = CDisplay_RM_Set_Power ( &l_power_value_U8 );

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32  = sizeof ( display_power_buffer_type_ts );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display Power write devctl Failed" );
                }

                break;
            }

            default:
                LOGE (&gResMgrDisplayLogContext, "Display RM Unknown devctl cmd = %d", p_msg_UP->i.dcmd );
                l_status_S32 = EINVAL;
                break;
            }
        }
        else if ( p_ctp_SP->id == displayDev.display_state_path_id_S32 )
        {
            switch ( p_msg_UP->i.dcmd )
            {
            case STATE_ID_VALUE_READ:
            {
                /* coverity[cert_arr37_c_violation] : FALSE */
                display_state_buffer_type_ts *l_out_SP = ( display_state_buffer_type_ts * ) ( _DEVCTL_DATA (( p_msg_UP->i )));
                uint8_t l_state_U8 = 0;
                l_status_S32 = displayDev.drventry_S->Get_Display_state_Devctl ( &l_state_U8 );

                if ( EOK == l_status_S32 )
                {
                    l_out_SP->state = l_state_U8;
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32  = sizeof ( display_state_buffer_type_ts );
                    LOGD (&gResMgrDisplayLogContext,  "Display state read Success" );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display state read devctl Failed" );
                }

                break;
            }

            default:
                LOGE (&gResMgrDisplayLogContext, "Display RM  Unknown devctl cmd = %d", p_msg_UP->i.dcmd );
                l_status_S32 = EINVAL;
                break;
            }

        }
        else if ( p_ctp_SP->id == displayDev.thermal_temp_val_path_id_S32 )
        {
            switch ( p_msg_UP->i.dcmd )
            {
            case THERMAL_TEMPERATURE_READ:
            {
                thermal_temperature_buffer *l_out_SP = NULL;
                uint32_t l_temp_val_U32 = 0;
                l_status_S32 = displayDev.drventry_S->Get_Thermal_Temperature_Value_Devctl ( &l_temp_val_U32 );

                if ( EOK == l_status_S32 )
                {
                    /* coverity[cert_arr37_c_violation] : FALSE */
                    l_out_SP = ( thermal_temperature_buffer * ) _DEVCTL_DATA (( p_msg_UP->i ));
                    l_out_SP->temperature_value = l_temp_val_U32;
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32  = sizeof ( thermal_temperature_buffer );
                    LOGD (&gResMgrDisplayLogContext,  "Display thermal read Success" );
                }
                else
                {
                    LOGE (&gResMgrDisplayLogContext, "Display thermal read devctl Failed" );
                }

                break;
            }

            default:
                LOGE (&gResMgrDisplayLogContext, "Display RM Unknown devctl cmd = %d", p_msg_UP->i.dcmd );
                l_status_S32 = EINVAL;
                break;
            }
        }
        else if ( p_ctp_SP->id == displayDev.thermal_temp_type_path_id_S32 )
        {
            thermal_type_buffer *l_out_SP = NULL;

            switch ( p_msg_UP->i.dcmd )
            {
            case THERMAL_TYPE_READ:
            {
                /* coverity[cert_arr37_c_violation] : FALSE */
                l_out_SP = ( thermal_type_buffer * ) _DEVCTL_DATA (( p_msg_UP->i ));
                ( void ) strncpy ( l_out_SP->thermal_type, THERMAL_TYPE, strlen ( THERMAL_TYPE ) + 1U );
                /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                l_nbytes_S32  = sizeof ( thermal_type_buffer );
                LOGD (&gResMgrDisplayLogContext,  "Display Thermal type read success" );
                break;
            }

            default:
                LOGE (&gResMgrDisplayLogContext, "Display RM Unknown devctl cmd = %d", p_msg_UP->i.dcmd );
                l_status_S32 = EINVAL;
                break;
            }
        }
        else if ( ( p_ctp_SP->id == displayDev.display_gamma_red_path_id_S32 )   ||
                  ( p_ctp_SP->id == displayDev.display_gamma_green_path_id_S32 ) ||
                  ( p_ctp_SP->id == displayDev.display_gamma_blue_path_id_S32 ) )
        {
            /* coverity[cert_arr37_c_violation] : FALSE */
            display_gamma_rgb_type_ts *l_out_SP = (display_gamma_rgb_type_ts *)(_DEVCTL_DATA((p_msg_UP->i)));

            switch ( p_msg_UP->i.dcmd )
            {
            case GAMMA_RGB_VALUE_READ:
            {
                l_status_S32 = displayDev.drventry_S->Get_Gamma_RGB_Devctl(&l_out_SP->gamma_red, &l_out_SP->gamma_green, &l_out_SP->gamma_blue);

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32 = sizeof(display_gamma_rgb_type_ts);
                }
                else
                {
                    LOGE(&gResMgrDisplayLogContext, "Display Gamma RGB devctl Failed");
                }

                break;
            }

            case GAMMA_RGB_VALUE_WRITE:
            {
                int32_t l_gamma_red_S32 = l_out_SP->gamma_red;
                int32_t l_gamma_green_S32 = l_out_SP->gamma_green;
                int32_t l_gamma_blue_S32 = l_out_SP->gamma_blue;

                l_status_S32 = displayDev.drventry_S->Set_Gamma_RGB_Devctl(l_gamma_red_S32, l_gamma_green_S32, l_gamma_blue_S32);

                if ( EOK == l_status_S32 )
                {
                    /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
                    l_nbytes_S32 = sizeof(display_gamma_rgb_type_ts);
                }
                else
                {
                    LOGE(&gResMgrDisplayLogContext, "Display Gamma RGB write devctl Failed");
                }

                break;
            }

            default:
                LOGE(&gResMgrDisplayLogContext, "Display RM Unknown devctl cmd = %d", p_msg_UP->i.dcmd);
                l_status_S32 = EINVAL;
                break;
            }
        }
        else
        {
            /*MISRA*/
        }
    }

    ( void ) memset ( &p_msg_UP->o, 0, sizeof ( p_msg_UP->o ) );
    p_msg_UP->o.ret_val = l_status_S32;
    p_msg_UP->o.nbytes = (uint32_t) l_nbytes_S32;
    /* coverity[misra_c_2012_rule_12_3_violation] : FALSE */
    l_status_S32 = _RESMGR_PTR ( p_ctp_SP, &p_msg_UP->o, sizeof ( p_msg_UP->o ) + (unsigned int)l_nbytes_S32 );

    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_RM_Set_Power
@brief     Display RM set power
@param[in] p_power_val_U8 display power setting
@return    int32_t    success or failure
 *****************************************************************************/
static int32_t CDisplay_RM_Set_Power ( uint8_t *p_power_val_U8 )
{
    int32_t l_status_S32 = EOK;
    l_status_S32 = displayDev.drventry_S->Enable_Display ( p_power_val_U8 );

    if ( EOK != l_status_S32 )
    {
        LOGE (&gResMgrDisplayLogContext, "display set power failed" );
    }
    else
    {
        LOGD (&gResMgrDisplayLogContext,  "display set power to %d success", *p_power_val_U8 );
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: getopt_chk
@brief     Display RM options paring
@param[out] p_opt char* to be parsed from command line.
@param[in] p_argc int Count of command line parameters for the Resource manager.
@param[in] p_argv[] char**  Command line parameters for the resource manager
@return    bool Return value to indicate true or false for the operation done
 *****************************************************************************/
static bool getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
{
    bool l_ret_val_BOOL = false;
    int32_t l_ret_S32 = -1;
    l_ret_S32 = getopt ( p_argc, p_argv, "p:t:d::l:z:" );

    if ( l_ret_S32 < 0 )
    {
        l_ret_val_BOOL = false;
        *p_opt = ( char ) 0;
    }
    else
    {
        l_ret_val_BOOL = true;
        *p_opt = ( char ) l_ret_S32;
    }

    return ( l_ret_val_BOOL );
}
/*!****************************************************************************
Function Name: CDisplay_RM_ParseOptions
@brief     Display RM options paring
@param[in] p_argc_SINT int Count of command line parameters for the Resource manager.
@param[in] p_argv_CHAR[] char**  Command line parameters for the resource manager
@param[out] p_display_dev_SP display Device structure
@return    int32_t    success or failure
 *****************************************************************************/
static int32_t CDisplay_RM_ParseOptions ( int32_t p_argc_SINT, char *const p_argv_CHAR[], ts_display_dev *p_display_dev_SP )
{
    int32_t l_status_S32 = 0;
    char l_opt_CHAR = '\0';
    int32_t l_err_S32 = 0;

    /* Scan the Command line options for the panelunit, thermalunit, adc channel and HW library dl path */
    while ( ( EOK == l_status_S32 ) && ( true == getopt_chk ( &l_opt_CHAR, p_argc_SINT, p_argv_CHAR ) ) )
    {
         /* coverity[cert_str34_c_violation] : FALSE */
        switch ( l_opt_CHAR )
        {
        case 'p':

            /* coverity[cert_int31_c_violation] : FALSE */
            /* coverity[cert_err30_c_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
            errno = 0;
            p_display_dev_SP->display_unit_U32 = ( uint32_t ) ( strtoul ( optarg, NULL, 0 ) );
            l_err_S32 = errno;
            /* coverity[cert_err30_c_violation] : FALSE */
            if ( ( l_err_S32 == EINVAL ) || ( l_err_S32 == ERANGE ) )
            {
                l_status_S32 = EXIT_FAILURE;
                LOGE (&gResMgrDisplayLogContext, "unable to convert \"display unit\" to unsigned int: %s strtoul failed=%d\n", optarg, l_status_S32 );
            }
            else
            {
            }


            break;

        case 't':
            /* coverity[cert_int31_c_violation] : FALSE */
            /* coverity[cert_err30_c_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_7_violation] : FALSE */
            errno = 0;
            p_display_dev_SP->thermal_unit_U32 = ( uint32_t ) ( strtoul ( optarg, NULL, 0 ) );
            l_err_S32 = errno;
            /* coverity[cert_err30_c_violation] : FALSE */
            if ( ( l_err_S32 == EINVAL ) || ( l_err_S32 == ERANGE ) )
            {
                l_status_S32 = EXIT_FAILURE;
                LOGE (&gResMgrDisplayLogContext, "unable to convert \"thermal unit\" to unsigned int: %s strtoul failed=%d\n", optarg, l_status_S32 );
            }
            else
            {
            }


            break;

        case 'd':
            if ( strlen ( optarg ) < DISPLAY_RM_PATH_MAX )
            {
                ( void ) strncpy ( ( char * ) p_display_dev_SP->dev_node_CHAR, optarg, strlen ( optarg ) );
            }
            else
            {
                LOGE (&gResMgrDisplayLogContext, "buffer size is not sufficient to store optarg, check usage" );
                CDisplay_RM_usage();
                l_status_S32 = EXIT_FAILURE;
            }
            break;
        case 'l':
            if ( strlen ( optarg ) < DISPLAY_RM_PATH_MAX )
            {
                ( void ) strncpy ( ( char * ) p_display_dev_SP->dl_load_path, optarg, strlen ( optarg ) );
            }
            else
            {
                LOGE (&gResMgrDisplayLogContext, "buffer size is not sufficient to store optarg, check usage" );
                CDisplay_RM_usage();
                l_status_S32 = EXIT_FAILURE;
            }
            break;

        case '?':
            LOGE (&gResMgrDisplayLogContext, "unidentified options passed to resmgr_display, check usage" );
            CDisplay_RM_usage();
            l_status_S32 = EXIT_FAILURE;
            break;
        case 'U':
            /* coverity[misra_c_2012_rule_22_1_violation] : FALSE */
            /* coverity[cert_mem31_c_violation] : FALSE */
            if (UserParm != NULL) 
                {
                    free(UserParm);  // this if loop is added as part of Klockwork warning fix to Free existing memory if any
                }
            UserParm = strdup(optarg);
            break;
        default:
            CDisplay_RM_usage();
            l_status_S32 = EXIT_FAILURE;
            break;
        }
    }

    if ( ( optind != p_argc_SINT ) || ( ( optind == 1 ) && ( p_argc_SINT == 1 ) ) )
    {
        LOGE (&gResMgrDisplayLogContext, "Mandatory arguments missing, check usage and pass correct args" );
        CDisplay_RM_usage();
        l_status_S32 = EXIT_FAILURE;
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_Dlload
@brief     Display DLL load
@param[out] hdl address of the display drv entry function.
@param[in] p_dl_load_path_CHAR display dll path
@return    void* NULL or address of the display drv entry function
 *****************************************************************************/
static void *CDisplay_Dlload ( void **hdl,  uint8_t *p_dl_load_path_CHAR )
{
    uint8_t l_dllpath[DISPLAY_RM_POSIX_PATH_MAX + 1] = { 0 };
    void *l_dlhdl = NULL;
    void *l_entry = NULL;

    /* coverity[cert_int30_c_violation] : FALSE */
    (void)strlcpy ( ( char * ) l_dllpath, ( char * ) p_dl_load_path_CHAR, strlen ( ( char * ) p_dl_load_path_CHAR ) + 1U );
    l_dlhdl = dlopen ( ( char * ) p_dl_load_path_CHAR, RTLD_NOW );
    if ( l_dlhdl != NULL )
    {
        l_entry = dlsym ( l_dlhdl, "display_drv_entry" );
        if ( l_entry != NULL )
        {
            *hdl = l_dlhdl;
        }
    }
    else
    {
        LOGE (&gResMgrDisplayLogContext, "Failed to load display dll %s ", p_dl_load_path_CHAR );
    }
    /* coverity[cert_mem31_c_violation] : FALSE */
    /* coverity[misra_c_2012_rule_22_1_violation] : FALSE */
    return l_entry;
}

/*!****************************************************************************
Function Name: CDisplay_RM_ExitSignal
@brief     Display RM Exit signal handler
@param[in] p_signo_SINT terminate signal
@return    void
 *****************************************************************************/
static void CDisplay_RM_ExitSignal ( int32_t p_signo_SINT )
{
    /* Set the flag to indicate Terminate RM. This will exit the dispatch loop */
    ( void ) ( p_signo_SINT );
    t_display_done_SINT = RM_TRUE;
}


/*!****************************************************************************
Function Name: CDisplay_RM_Terminate
@brief     Display RM Terminate on exit signal
@param[in] void
@return    int32_t    success or failure
 *****************************************************************************/
static int32_t CDisplay_RM_Terminate ( void )
{
    int32_t l_status_S32 = EXIT_SUCCESS;
    l_status_S32 = CDisplay_Deinit();

    if ( EOK == l_status_S32 )
    {
        LOGD (&gResMgrDisplayLogContext,  "Display HW DeInitialization Success" );
    }
    else
    {
        LOGD (&gResMgrDisplayLogContext,  "Display HW DeInitialization Fail" );
    }

    LOGD (&gResMgrDisplayLogContext,  "Display Power Detach" );
    ( void ) resmgr_detach ( displayDev.p_dpp_SP, displayDev.display_power_path_id_S32, _RESMGR_DETACH_ALL );
    LOGD (&gResMgrDisplayLogContext,  "Display Power state Detach" );
    ( void ) resmgr_detach ( displayDev.p_dpp_SP, displayDev.display_state_path_id_S32, _RESMGR_DETACH_ALL );
    LOGD (&gResMgrDisplayLogContext,  "Display Power Thermal Temp Val Detach" );
    ( void ) resmgr_detach ( displayDev.p_dpp_SP, displayDev.thermal_temp_val_path_id_S32, _RESMGR_DETACH_ALL );
    LOGD (&gResMgrDisplayLogContext,  "Display Power Thermal Temp Type Detach" );
    ( void ) resmgr_detach ( displayDev.p_dpp_SP, displayDev.thermal_temp_type_path_id_S32, _RESMGR_DETACH_ALL );
    LOGD(&gResMgrDisplayLogContext, "Display Gamma Red Detach");
    (void)resmgr_detach(displayDev.p_dpp_SP, displayDev.display_gamma_red_path_id_S32, _RESMGR_DETACH_ALL);
    LOGD(&gResMgrDisplayLogContext, "Display Gamma Green Detach");
    (void)resmgr_detach(displayDev.p_dpp_SP, displayDev.display_gamma_green_path_id_S32, _RESMGR_DETACH_ALL);
    LOGD(&gResMgrDisplayLogContext, "Display Gamma Blue Detach");
    (void)resmgr_detach(displayDev.p_dpp_SP, displayDev.display_gamma_blue_path_id_S32, _RESMGR_DETACH_ALL);

    if ( displayDev.p_ctp_UP != NULL )
    {
        LOGD (&gResMgrDisplayLogContext,  "Dispatch context free" );
        dispatch_context_free ( displayDev.p_ctp_UP );
    }
    else
    {
        /* Do nothing. Compliant to Visteon coding rules */
    }

    if ( displayDev.p_dpp_SP != NULL )
    {
        l_status_S32 = dispatch_destroy ( displayDev.p_dpp_SP );

        if ( ERROR == l_status_S32 )
        {
            l_status_S32 = EXIT_FAILURE;
            LOGE (&gResMgrDisplayLogContext, "Display RM Dispatch wasn't destroyed" );
        }
        else
        {
            LOGD (&gResMgrDisplayLogContext,  "Display RM Dispatch destroyed" );
        }
    }
    else
    {
        /* Do nothing. Compliant to Visteon coding rules */
    }

    return l_status_S32;
}

/*!****************************************************************************
Function Name: CDisplay_Deinit
@brief     Display HW Deinit during termination of RM on exit signal
@param[in] void
@return    int32_t    success or failure
 *****************************************************************************/
static int32_t CDisplay_Deinit ( void )
{
    int32_t l_status_S32 = EOK;
    if(NULL != displayDev.P_Dll_Hdl)
    {
        l_status_S32 = displayDev.drventry_S->Deinit_Display ( );

        if ( EXIT_SUCCESS != l_status_S32 )
        {
            LOGE (&gResMgrDisplayLogContext, "Display Shut Down failed" );
        }
        else
        {
            LOGD (&gResMgrDisplayLogContext,  "Display Shut Down success" );
            l_status_S32 = dlclose ( displayDev.P_Dll_Hdl );

            if ( EXIT_SUCCESS != l_status_S32 )
            {
                LOGE (&gResMgrDisplayLogContext, "Display DLL handle close failed" );
            }
            else
            {
                LOGD (&gResMgrDisplayLogContext,  "Display DLL handle close success" );
            }
        }
    }
    else
    {
        LOGD (&gResMgrDisplayLogContext,  "Display DLL handle is already NULL, Nothing to cleanup " );
    }
    return l_status_S32;
}
/*********************************************************************************
 * @Version          Version 1.0
 * @ingroup          resmgr_display
 * @author           Rajasekhar
 * @brief            Initial version implemented for the Display Resource Manager
 **********************************************************************************/
 /*********************************************************************************
 * @Version          Version 1.1
 * @ingroup          resmgr_display
 * @author           Vela
 * @brief            Implementation of Display Gamma Correction
 **********************************************************************************/
 
 
