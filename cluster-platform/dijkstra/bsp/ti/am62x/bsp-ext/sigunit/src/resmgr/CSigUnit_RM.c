/*******************************************************************************
 **  \file CSigUnit_RM.c
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: May 11 2020
 **  \author: Dinakar Babu
 **
 **  \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 ***/

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

#include "dk_logger.h"
#include "CSigUnit_Cfg.h"
#include "CSigUnit_RM.h"
#include "CSigUnit_HwIf.h"


#define SIG_UNIT_RESMGR_NPARTS_MAX   (1U)
#define SIG_UNIT_RESMGR_MSGSIZE_MAX  (4096U)
#define IO_ATTR_MODE ( mode_t )S_IFREG | ( mode_t )S_IRUSR | ( mode_t )S_IWUSR | ( mode_t )S_IRGRP | ( mode_t )S_IWGRP | ( mode_t )S_IROTH | ( mode_t )S_IWOTH

LOG_DECLARE_CONTEXT ( gResMgrSigUnitLogContext );

static ts_sigunit_dev_t sigunit_device;


static bool g_sigunit_done_BOOL = false; /** Variable to handle SIGTERM signal */

static int32_t sigunit_io_devctl(resmgr_context_t *sigDevctlctp_p, io_devctl_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP);
static int32_t sigunit_io_open(resmgr_context_t *sigOpenctp_p, io_open_t *p_msg_UP, RESMGR_HANDLE_T *p_handle_SP, void *p_extra_VP);
static uint32_t sigunit_init(ts_sigunit_dev_t *p_sig_create_dev_SP);
static void sigunit_exit_handler(int32_t sig);
static bool sigunit_getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] );
static bool sigunit_options ( const int32_t argc, char *const *const argv, ts_sigunit_dev_t *p_dev_options_SP );
static void sigunit_usage ( void );
static bool sigunit_fini ( const ts_sigunit_dev_t *p_sig_fini_dev_SP );

/*!**************************************************************************************************************
    * \fn      uint32_t sigunit_init(ts_sigunit_dev_t *p_sig_create_dev_SP)
    *          Function name(sigunit_init)      
    * \brief   Function for creating a sigunit device.      
    * \return  int32 - Return value to indicate success or error code
    * \details requirement ID 744949
 ****************************************************************************************************************/
static uint32_t sigunit_init(ts_sigunit_dev_t *p_sig_create_dev_SP)
{
    uint32_t                       l_result_S32 = EOK;
    int32_t                        l_rc_S32;
    static uint8_t                 l_devname_U8[PATH_MAX + 1];
    static iofunc_attr_t           l_ioattr;
    static resmgr_io_funcs_t       ts_sigunit_io_funcs;
    static resmgr_connect_funcs_t  ts_sigunit_connect_funcs;
    static resmgr_attr_t           l_rattr;
    struct sigaction sigAct;

    p_sig_create_dev_SP->dpp_SP = dispatch_create();
    if (NULL == p_sig_create_dev_SP->dpp_SP)
    {
        /* coverity[cert_con33_c_violation] : FALSE */
        LOGE(&gResMgrSigUnitLogContext,"dispatch_create() function Failed %s", strerror (errno));
        l_result_S32 = ENOMEM;
    }
    else
    {
        /* set up resmgr attributes functions */
        (void) memset(&l_rattr, 0, sizeof(l_rattr));
        l_rattr.nparts_max   = SIG_UNIT_RESMGR_NPARTS_MAX;
        l_rattr.msg_max_size = SIG_UNIT_RESMGR_MSGSIZE_MAX;

        (void) memset(&l_ioattr, 0, sizeof(l_ioattr));
        /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
        /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
        iofunc_attr_init(&l_ioattr, (uint32_t)S_IFDIR | IO_ATTR_MODE, NULL, NULL);
        l_ioattr.inode =  SIG_UNIT_EVAL_WIN_MAX + (uint8_t) 1;
        l_ioattr.nbytes = (int64_t)SIG_UNIT_EVAL_WIN_MAX;

        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        iofunc_func_init((uint32_t)_RESMGR_CONNECT_NFUNCS, &ts_sigunit_connect_funcs, (uint32_t)_RESMGR_IO_NFUNCS, &ts_sigunit_io_funcs);
        ts_sigunit_connect_funcs.open = sigunit_io_open;
        ts_sigunit_io_funcs.devctl = sigunit_io_devctl;

        /* register path */
        /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
        (void) snprintf((char *) l_devname_U8, PATH_MAX, "%s%d", DEV_NAME, p_sig_create_dev_SP->devnum_U8);

        p_sig_create_dev_SP->id_INT32 = resmgr_attach(p_sig_create_dev_SP->dpp_SP, &l_rattr, (char *) l_devname_U8, _FTYPE_ANY, 0,
                                        &ts_sigunit_connect_funcs, &ts_sigunit_io_funcs, &l_ioattr);

        if(-1 == p_sig_create_dev_SP->id_INT32)
        {
            /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"resmgr_attach() failed %s", strerror (errno));
            l_result_S32 = EXIT_FAILURE;
        }
        else
        {
            /* drop pathspace ability , not needed anymore */
            l_rc_S32 = procmgr_ability( 0,
                                        PROCMGR_ADN_NONROOT | PROCMGR_AOP_DENY | PROCMGR_AID_PATHSPACE,
                                        PROCMGR_AID_EOL );

            if( EOK != l_rc_S32 )
            {
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext,"procmgr_ability() failed %s", strerror (errno));
                l_result_S32 = EXIT_FAILURE;
            }
            else
            {
                p_sig_create_dev_SP->ctp_UP = dispatch_context_alloc(p_sig_create_dev_SP->dpp_SP);
                /* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
                if(NULL == p_sig_create_dev_SP->ctp_UP)
                {
                    /* coverity[cert_con33_c_violation] : FALSE */
                    LOGE(&gResMgrSigUnitLogContext,"dispatch_context_alloc() failed %s", strerror (errno));
                    l_result_S32 = ENOMEM;
                }
                else
                {
                    ( void ) sigemptyset ( &sigAct.sa_mask );
                    ( void ) sigaddset ( &sigAct.sa_mask, SIGTERM );
                    sigAct.sa_handler = &sigunit_exit_handler;
                    sigAct.sa_flags = 0;
                    ( void ) sigaction ( SIGTERM, &sigAct, NULL );
                }
            }
        }
    }

    return l_result_S32;
}

/*!**************************************************************************************************************
    * \fn      void sigunit_exit_handler(int32_t sig)
    *          Function name(sigunit_exit_handler)      
    * \brief   Function for handling the exit scenario of a sigunit device.      
    * \return  void
    * \details requirement ID 744949
 ****************************************************************************************************************/

static void sigunit_exit_handler(int32_t sig)
{

    (void) sig;
    g_sigunit_done_BOOL = true;
}

/* coverity[misra_c_2012_rule_5_8_violation] : FALSE */
int main(int argc, char *const *const argv)
{

    int32_t l_result_S32 = EXIT_SUCCESS;
    uint32_t l_ret_sigunit_create_device_U32 = ENOMEM;
    bool l_ret_sig_hw_init_BOOL = false;
    bool l_ret_sig_hw_fini_BOOL = false;
    bool l_ret_sig_options_BOOL = false;
    int32_t l_ret_dispatch_handler_S32;

    LOG_REGISTER_APP_SLOG2("ResMgrSigUnit","ResMgr_SU");
    LOG_REGISTER_CONTEXT(gResMgrSigUnitLogContext, "ResMgrSigUnit", "ResMgr_SU Component", DLT_LOG_INFO);

    LOGI(&gResMgrSigUnitLogContext,"Starting SigUnit Resmgr ... ");

    if ( ThreadCtl( _NTO_TCTL_IO, NULL ) == -1 )
    {
        LOGE(&gResMgrSigUnitLogContext,"Failed to provide register access to thread" );
        l_result_S32 = EXIT_FAILURE;
    }
    else
    {
        l_ret_sig_options_BOOL = sigunit_options ( argc, argv, &sigunit_device );
        if(true == l_ret_sig_options_BOOL)
        {
            LOGD(&gResMgrSigUnitLogContext," Signature Unit ID %d", sigunit_device.devnum_U8 );

            l_ret_sig_hw_init_BOOL = sigunit_hw_init(&sigunit_device);

            if( true == l_ret_sig_hw_init_BOOL )
            {
                l_ret_sigunit_create_device_U32 = (uint32_t) sigunit_init(&sigunit_device);
                if(EOK == (int32_t) l_ret_sigunit_create_device_U32)
                {
                    while (!g_sigunit_done_BOOL)
                    {
                        sigunit_device.ctp_UP = dispatch_block(sigunit_device.ctp_UP);
                        /* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
                        if (sigunit_device.ctp_UP == NULL)
                        {
                            /* coverity[cert_con33_c_violation] : FALSE */
                            LOGE(&gResMgrSigUnitLogContext,"Dispatch Block Failed %s",strerror ( errno ) );

                            if ( EINTR == errno )
                            {
                                l_result_S32 = EXIT_SUCCESS;
                            }
                            else
                            {
                                l_result_S32 = EXIT_FAILURE;
                            }
                            break;
                        }
                        else
                        {
                            l_ret_dispatch_handler_S32 = dispatch_handler(sigunit_device.ctp_UP);
                            if ( l_ret_dispatch_handler_S32 != ( int32_t ) 0 )
                            {
                                /* coverity[cert_con33_c_violation] : FALSE */
                                LOGE(&gResMgrSigUnitLogContext,"dispatch_handler has failed: %s\n", strerror ( errno ) );
                                l_result_S32 = EXIT_FAILURE;
                            }
                            else
                            {
                                /*MISRA*/
                            }
                        }
#ifdef VC_UNIT_TEST
                        g_sigunit_done_BOOL = true;
#endif
                    }
                }
                else
                {
                    l_result_S32 = EXIT_FAILURE;
                    LOGE(&gResMgrSigUnitLogContext,"Create Device Failed %d", l_result_S32);
                }
            }
            else
            {
                l_result_S32 = EXIT_FAILURE;
                LOGE(&gResMgrSigUnitLogContext,"Failed to do sig_hw_init %d", l_result_S32);
            }
        }
        else
        {
            l_result_S32 = EXIT_FAILURE;
            LOGE(&gResMgrSigUnitLogContext,"Failed to Parse Options %d", l_result_S32);
        }
    }


    /* Deallocate, in case signiture unit device is created under FS. */
    if ( EOK == (int32_t) l_ret_sigunit_create_device_U32 )
    {
        l_ret_sig_hw_fini_BOOL = sigunit_fini(&sigunit_device);
        if ( false == l_ret_sig_hw_fini_BOOL )
        {
            /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrSigUnitLogContext,"sig_fini has failed: %s\n", strerror ( errno ) );
            l_result_S32 = EXIT_FAILURE;
        }
    }

    /* Deallocate, in case of IO Mapping success. */
    if ( true == l_ret_sig_hw_init_BOOL )
    {
        l_ret_sig_hw_fini_BOOL = sigunit_hw_fini ( &sigunit_device );
        if ( false == l_ret_sig_hw_fini_BOOL )
        {
            LOGE(&gResMgrSigUnitLogContext,"sigunit_hw_fini failed" );
            l_result_S32 = EXIT_FAILURE;
        }
    }

    LOG_UNREGISTER_CONTEXT(gResMgrSigUnitLogContext);

    return l_result_S32;
}


/*!**************************************************************************************************************
    * \fn         int32_t sigunit_io_open(resmgr_context_t *sigOpenctp_p, io_open_t *p_msg_UP, RESMGR_HANDLE_T *p_handle_SP, void *p_extra_VP)
    * \brief      Function for open. This function is called when an application calls the open() function.
    * \param[in]  sigOpenctp_p - resmgr_context_t* Resource Manager Context
    * \param[in]  p_msg_UP - io_open_t* io_open message structure. Contains the message that the Resource Manager received.
    * \param[in]  p_handle_SP - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                     controlling
    * \param[in]  p_extra_VP - void* Extra information from the library
    * \return     int32 - Return value to indicate success or error code
    * \details    requirement ID 744947
 ****************************************************************************************************************/
/* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
static int32_t sigunit_io_open(resmgr_context_t *sigOpenctp_p, io_open_t *p_msg_UP, RESMGR_HANDLE_T *p_handle_SP, void *p_extra_VP)
{
    int32_t l_status_S32;

    l_status_S32 = iofunc_open_default (sigOpenctp_p, p_msg_UP, p_handle_SP, p_extra_VP);
    if ( EOK != l_status_S32 )
    {
        LOGE(&gResMgrSigUnitLogContext,"Error opening sigunit device : %d\n ", l_status_S32);
    }
    else
    {/*MISRA*/}

    return  ( l_status_S32 );
}

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_io_devctl(resmgr_context_t *sigDevctlctp_p, io_devctl_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP)
    * \brief      Function for devctl. This function is called when an application calls the devctl() function.
    * \param[in]  sigDevctlctp_p - resmgr_context_t* Resource Manager Context
    * \param[in]  p_msg_UP - io_devctl_t* io_open message structure. Contains the message that the Resource Manager received.
    * \param[in]  p_handle_SP - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                                controlling
    * \return     int32 - Return value to indicate success or error code
    * \details    requirement ID 744949, 744956, 744957, 744958 744959, 744960, 744952
 ****************************************************************************************************************/
/* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
static int32_t sigunit_io_devctl(resmgr_context_t *sigDevctlctp_p, io_devctl_t *p_msg_UP, RESMGR_OCB_T *p_ocb_SP)
{
    int32_t                   l_status_S32;
    int32_t                   l_ret_sigunit_S32 = 0;
    uint64_t                  l_nbytes_U64 = 0;
    const uint8_t             *l_pData_U8;
    const ts_SSigUnitCfg_t    *pSigUnitCfg;
    const ts_SSigUnitWinCfg_t *pSigUnitWinCfg;
    ts_SSigUnitGetWinStatus_t *pSigUnitWinStatus;

    /* coverity[cert_int31_c_violation] : FALSE */
    l_status_S32 = iofunc_devctl_default (sigDevctlctp_p, p_msg_UP, p_ocb_SP);
    /* coverity[misra_c_2012_rule_10_8_violation] : FALSE */
    /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
    /* coverity[cert_int31_c_violation] : FALSE */
    if (l_status_S32 != (int32_t) _RESMGR_DEFAULT)
    {
        l_status_S32 = EAGAIN;
        LOGE(&gResMgrSigUnitLogContext,"iofunc_devctl_default() failed %d ",  l_status_S32);
    }
    else
    {
        switch (p_msg_UP->i.dcmd)
        {
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_INITIALIZE:
            /* coverity[cert_arr37_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_11_5_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            pSigUnitCfg = (ts_SSigUnitCfg_t *)_DEVCTL_DATA((p_msg_UP->i));
            l_ret_sigunit_S32 = sigunit_initialize(&sigunit_device, pSigUnitCfg);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext,"failed in sigunit_initialize %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                LOGD(&gResMgrSigUnitLogContext,"sigunit_initialize using devctl is successful and status is %d \n ", l_status_S32 );
            }

            break;
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_EVAL_WIN_SETUP:
            /* coverity[cert_arr37_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_11_5_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            pSigUnitWinCfg = (ts_SSigUnitWinCfg_t *)_DEVCTL_DATA((p_msg_UP->i));
            l_ret_sigunit_S32 = sigunit_eval_win_setup(&sigunit_device, pSigUnitWinCfg);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext,"failed in sigunit_eval_win_setup %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup using devctl is successful and status is %d \n ", l_status_S32 );
            }
            break;
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_EVAL_WIN_START:
            /* coverity[cert_arr37_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_11_5_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            l_pData_U8 = (uint8_t *)_DEVCTL_DATA((p_msg_UP->i));
            /* coverity[memory_access] : FALSE */
            l_ret_sigunit_S32 = sigunit_eval_win_start(&sigunit_device, *l_pData_U8);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext,"failed in sigunit_eval_win_start %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_start using devctl is successful and status is %d \n ", l_status_S32 );
            }
            break;
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_EVAL_WIN_STOP:
            /* coverity[cert_arr37_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_11_5_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            l_pData_U8 = (uint8_t *)_DEVCTL_DATA((p_msg_UP->i));
            /* coverity[memory_access] : FALSE */
            l_ret_sigunit_S32 = sigunit_eval_win_stop(&sigunit_device, *l_pData_U8);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext,"failed in sigunit_eval_win_stop %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_stop using devctl is successful and status is %d \n ", l_status_S32 );
            }
            break;
        /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
        /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_EVAL_WIN_GET_STS:            
            /* coverity[cert_arr37_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_11_5_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            pSigUnitWinStatus = (ts_SSigUnitGetWinStatus_t *)_DEVCTL_DATA((p_msg_UP->i));
            l_ret_sigunit_S32 = sigunit_eval_win_status(&sigunit_device, pSigUnitWinStatus);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext," failed in sigunit_eval_win_status %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                //LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_status using devctl is successful and status is %d \n ", l_status_S32 );
            }
            l_nbytes_U64 = sizeof(ts_SSigUnitGetWinStatus_t);
            break;
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        case SIG_UNIT_DCMD_SHUTDOWN:
            l_ret_sigunit_S32 = sigunit_shutdown(&sigunit_device);
            if ( l_ret_sigunit_S32 == -1 )
            {
                l_status_S32 = EINVAL;
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGE(&gResMgrSigUnitLogContext," failed in sigunit_shutdown %s and status is %d \n ", strerror ( errno ), l_status_S32);
            }
            else
            {
                l_status_S32 = EOK;
                LOGD(&gResMgrSigUnitLogContext,"sigunit_shutdown using devctl is successful and status is %d \n ", l_status_S32 );
            }

            break;
        default:
            l_status_S32 = EINVAL;
            break;
        }

        if(EOK == l_status_S32)
        {
            (void) memset (&p_msg_UP->o, 0, sizeof (p_msg_UP->o));
            p_msg_UP->o.ret_val = l_status_S32;
            p_msg_UP->o.nbytes = (uint32_t) l_nbytes_U64;

            /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
            /* coverity[misra_c_2012_rule_12_3_violation] : FALSE */
            /* coverity[misra_c_2012_rule_13_4_violation] : FALSE */
            /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
            l_status_S32 = _RESMGR_PTR(sigDevctlctp_p, &p_msg_UP->o, sizeof(p_msg_UP->o) + l_nbytes_U64);
        }
    }
    return(l_status_S32);
}


/*!**************************************************************************************************************
    * \fn         static bool sigunit_getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
    * \brief      Function to check the options passed while starting the Driver
    * \return     l_ret_val_BOOL
                  true when success
                  false when failed
    * \details    requirement ID 744947
 ****************************************************************************************************************/

static bool sigunit_getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
{
    bool l_ret_val_BOOL = false;
    int32_t l_getopt_ret_S32;
    l_getopt_ret_S32 = getopt ( p_argc, p_argv, "u:" );

    if ( l_getopt_ret_S32 < 0 )
    {
        l_ret_val_BOOL = false;
        *p_opt = ( char ) 0;
    }
    else
    {
        l_ret_val_BOOL = true;
        *p_opt = ( char ) l_getopt_ret_S32;
    }

    return ( l_ret_val_BOOL );
}

/*!**************************************************************************************************************
    * \fn         static bool sigunit_options ( const int32_t argc, char *const *const argv, ts_sigunit_dev_t *p_dev_options_SP )
    * \brief      Function to check the options passed while starting the Driver
    * \return     l_ret_val_BOOL
                  true when success
                  false when failed
    * \details    requirement ID 744947
 ****************************************************************************************************************/
static bool sigunit_options ( const int32_t argc, char *const *const argv, ts_sigunit_dev_t *p_dev_options_SP )
{
    char l_opt = '0';
    bool l_ret_BOOL = true;
    int32_t l_status_S32;
    p_dev_options_SP->devnum_U8 = SIGUNIT_INVALID_DEVID;
    while ( true == sigunit_getopt_chk ( &l_opt, argc, argv ) )
    {
        /* coverity[cert_str34_c_violation] : FALSE */
        switch ( l_opt )
        {
        case 'u':
            errno = EOK;
            /* coverity[cert_int31_c_violation] : FALSE */
            p_dev_options_SP->devnum_U8 = (uint8_t) strtol(optarg, NULL, 0);
            if ( errno != EOK )
            {
                if ( errno == ERANGE )
                {
                    l_status_S32 = errno;
                    /* coverity[cert_con33_c_violation] : FALSE */
                    LOGE(&gResMgrSigUnitLogContext,"Failed strtol in options %s and status is %d \n ", strerror ( errno ), l_status_S32 );
                    l_ret_BOOL = false;
                }
                else {/*MISRA*/}
            }
            else if(SIG_UNIT_MAX < p_dev_options_SP->devnum_U8)
            {
                LOGE(&gResMgrSigUnitLogContext,"in Options() Invalid Device ID %d", p_dev_options_SP->devnum_U8 );
                sigunit_usage();
                l_ret_BOOL = false;
            }
            else {/*MISRA*/}

            break;
        default:
            LOGE(&gResMgrSigUnitLogContext,"in Options() Invalid Option" );
            sigunit_usage();
            l_ret_BOOL = false;
            break;
        }
    }
    return l_ret_BOOL;
}

/*!**************************************************************************************************************
    * \fn         void sigunit_usage ( void )
    * \brief      Function will be called if user pass illegal or invalid options
    * \param      void Usage: resmgr_siguint number
    * \return     void
    * \details    requirement ID 744947
 ****************************************************************************************************************/

static void sigunit_usage ( void )
{
    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
    (void) fprintf ( stderr, "Usage: resmgr_siguint -u [0/3]  \n"
                     "-u signature unit number (0, 1, 2, 3) \n" );
}

/*!**************************************************************************************************************
    * \fn         static bool sigunit_fini ( const ts_sigunit_dev_t *p_sig_fini_dev_SP )
    * \brief      Function to free all the resources allocated to the Signature Unit Driver
    * \param      void
    * \return     l_fini_ret_BOOL
    * \details    requirement ID 744954, 744949
 ****************************************************************************************************************/
static bool sigunit_fini ( const ts_sigunit_dev_t *p_sig_fini_dev_SP )
{
    bool l_fini_ret_BOOL = true;
    int32_t l_sig_ret_S32 = 0;

    l_sig_ret_S32 = resmgr_detach ( p_sig_fini_dev_SP->dpp_SP, p_sig_fini_dev_SP->id_INT32, _RESMGR_DETACH_ALL );

    if ( l_sig_ret_S32 < 0 )
    {
        l_fini_ret_BOOL = false;
        LOGE(&gResMgrSigUnitLogContext," in sig_fini resmgr_detach /dev/sig%d failed", p_sig_fini_dev_SP->devnum_U8 );
    }
    else {/*MISRA*/}

    (void) dispatch_destroy (p_sig_fini_dev_SP->dpp_SP);

    /* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
    if ( NULL == p_sig_fini_dev_SP->ctp_UP )
    {
        LOGI(&gResMgrSigUnitLogContext,"CTP is already NULL" );
    }
    else
    {
        dispatch_context_free ( p_sig_fini_dev_SP->ctp_UP );
    }

    return l_fini_ret_BOOL;
}
