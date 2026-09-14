
/***************************************************************************
 **
 **  \file CDio_RM.c
 **
 **  \brief Interface to interact with the DIO of TI-AM62P
 **
 **  This file provides functional defines for a DIO module
 **
 **  Component Name: DIO
 **  Archive:
 **  Date: Feb 8 2020
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <sys/resmgr.h>
#include <sys/procmgr.h>
#include <sys/siginfo.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <login.h>              /* Drop root features */
#include <secpol/ids.h>

#include "dk_logger.h"
#include "CDio_RM.h"
#include "CDio_HwIf.h"
#include "CDio_Devctl.h"


#define DIO_RESMGR_MSGSIZE 2048
#define DIO_TASK_PERIODICITY 4u
#define DIRECTION_PATH  "/dev/gpio/gpio%u/direction"
#define VALUE_PATH      "/dev/gpio/gpio%u/value"
/* coverity[cert_dcl37_c_violation] : FALSE */
#define ERROR -1

LOG_DECLARE_CONTEXT ( gResMgrDioLogContext );

static bool g_DIODone = false; /** Variable to handle SIGTERM signal */

static bool dio_fini ( void );
static bool dio_options ( const int argc, char **const argv, ts_dio_addr_t *dioOptionsAddr_p );
static void dio_ExitSignal ( int32_t signo );
static bool dio_count_mask_bits ( ts_dio_addr_t *dioCountAaddr_p );
static bool dio_data_extract ( ts_dio_pindata_t *dioPinData_p, uint32_t pin_U32 );
static bool dio_setup_timer ( ts_dio_dev_t *dioTimerDev_p );
static bool dio_attach_pulse ( ts_dio_dev_t *dioPulseDev_p );
static bool dio_getopt_chk ( char *const p_opt, const int p_argc, char *const p_argv[] );
static void dio_usage ( void );

static int32_t dio_io_open ( resmgr_context_t *dioOpenctp_p, io_open_t  *msg, RESMGR_HANDLE_T *handle, void *extra );
static int32_t dio_io_read ( resmgr_context_t *dioReadctp_p, io_read_t *msg, RESMGR_OCB_T *ocb );
static int32_t dio_io_write ( resmgr_context_t *dioWritectp_p, io_write_t *msg, RESMGR_OCB_T *ocb );
static int32_t dio_io_devctl ( resmgr_context_t *dioDevctlctp_p, io_devctl_t *msg, RESMGR_OCB_T *ocb );
static int32_t dio_periodic_read_check ( message_context_t *dioPeriodicctp_p, int code, unsigned flags, void *handle );
static int32_t dio_init(void);
static int32_t dio_export ( const uint32_t *p_pin_S32 );
static int32_t dio_unexport ( const uint32_t *p_pin_S32 );

static int32_t g_pathID_export_S32;
static int32_t g_pathID_unexport_S32;

static uint32_t g_set_bit_U32 = 1U;
static uint32_t g_clear_bit_U32 = 0U;
static uint32_t g_gpio_id_max_U32 = 0U;

static resmgr_connect_funcs_t  g_connect_funcs; /* Connect functions */
static resmgr_io_funcs_t       g_io_funcs;      /* IO functions */
/* coverity[misra_c_2012_rule_5_9_violation] : FALSE */
static dispatch_t              *g_dpp_SP;       /* Dispatch variable */
static resmgr_attr_t           g_rattr;         /* Resource Manager Attributes structure */
static iofunc_attr_t           g_ioattr;
/* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
static dispatch_context_t      *g_ctp;

static ts_dio_pindata_t g_dio_pindata;


static char *UserParm = NULL;     /* For drop-root  */


 /*!**************************************************************************************************************
    * \fn         void dio_usage ( void ) 
    * \brief      Function will be called if user pass illegal or invalid options
    * \return     none
 ****************************************************************************************************************/
static void dio_usage ( void )
{
    /* coverity[misra_c_2012_rule_21_6_violation] : FALSE */
    (void) fprintf (stderr, "Usage: dio_rm [-b] base_address \n"
                    "[-m]mask_address\n"
                    "where:\n"
                    " b - base address of the dio_bank from 0-4 \n"
                    " m - mask address of the dio bank from 0-4\n"
                    " U - set uid:gid\n");
}

 /*!**************************************************************************************************************
    * \fn         int32_t main ( int argc, char *argv[] ) 
    * \brief      Main function for Display Resource Manager
    * \param[in]  argc int Count of command line parameters for the Resource manager.
    * \param[in]  argv[] char**  Command line parameters for the resource manager
    * \return     int    Return Error code to indicate success or failure 
 ****************************************************************************************************************/
/* coverity[misra_c_2012_rule_8_6_violation] : FALSE */
/* coverity[misra_c_2012_rule_5_8_violation] : FALSE */
int32_t main ( int argc, char *argv[] )
{
    static const char    *dio_progname = "dio_rm";

    int32_t l_return_status_S32 = EXIT_FAILURE;
    bool l_ret_dio_options_BOOL = false;
    bool l_ret_dio_hw_init_BOOL = false;
    bool l_ret_dio_hw_fini_BOOL = false;
    bool l_ret_dio_count_mask_bits_BOOL = false;
    int32_t l_ret_dio_init_S32 = ENOMEM;
    int32_t l_dispatch_return_S32;

    LOG_REGISTER_APP_SLOG2("ResMgrDio","ResMgr_DIO");
    LOG_REGISTER_CONTEXT(gResMgrDioLogContext, "ResMgrDio", "ResMgr_DIO Component", DLT_LOG_INFO);

    LOGI(&gResMgrDioLogContext, "Starting DIO Resmgr %s", dio_progname );
    l_return_status_S32 = EXIT_SUCCESS;
    l_ret_dio_options_BOOL = dio_options ( argc, argv, g_dio_pindata.dio_addr_sa );

    if (UserParm != NULL)
    {
        if(procmgr_ability( 0,
                            PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                            PROCMGR_AOP_ALLOW  | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS| PROCMGR_AID_EOL)
                            != EOK){
            LOGD(&gResMgrDioLogContext, "Unable to gain procmgr abilities for nonroot operation\n");
            l_return_status_S32 = EXIT_FAILURE;
        }

        if(set_ids_from_arg(UserParm) != EOK)
        {
            if(__get_errno_ptr() != NULL)
            {
                /* coverity[cert_con33_c_violation] : FALSE */
                LOGD(&gResMgrDioLogContext, "%s: Unable to drop to user %s: %s", argv[0], UserParm, strerror(errno));
            }
            l_return_status_S32 = EXIT_FAILURE;
        }
    }
    /*DIO Initialization*/
    if ( l_ret_dio_options_BOOL == true )
    {
        LOGD(&gResMgrDioLogContext, "Options parsed successfully " );

            /* Count of set bits based on Mask Address of all Banks */

            l_ret_dio_count_mask_bits_BOOL = dio_count_mask_bits ( g_dio_pindata.dio_addr_sa );

        if ( l_ret_dio_count_mask_bits_BOOL == true )
        {
            LOGD(&gResMgrDioLogContext, "Number of bits set in each bank is calculated successfully " );

                l_ret_dio_hw_init_BOOL = dio_hw_init ( &g_dio_pindata );

            if ( l_ret_dio_hw_init_BOOL == true )
            {
                LOGD(&gResMgrDioLogContext, "Hardware Initialization Done");
                l_ret_dio_init_S32 = dio_init();
                if( EOK == l_ret_dio_init_S32)
                {
                    while ( !g_DIODone )
                    {
                       g_ctp = dispatch_block (g_ctp );

                        /* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
                        if (g_ctp == NULL )
                        {
                            LOGE(&gResMgrDioLogContext, "dispatch_block has failed" );
                            l_return_status_S32 = EXIT_FAILURE;

                                if ( true == g_DIODone )
                                {
                                    l_return_status_S32 = EXIT_SUCCESS;
                               }
                                break;
                            }
                            else
                            {
                                l_return_status_S32 = EXIT_SUCCESS;
                                l_dispatch_return_S32 = dispatch_handler (g_ctp );

                            if ( l_dispatch_return_S32 != ( int32_t ) 0 )
                            {
                                LOGE(&gResMgrDioLogContext, "dispatch_handler has failed" );
                                l_return_status_S32 = EXIT_FAILURE;
                            }
                            else
                            {/*MISRA*/}
                        }
#ifdef VC_UNIT_TEST
                            g_DIODone = true;
#endif
                    }
                }
                else
                {
                    LOGE(&gResMgrDioLogContext, "Failed to create dio device");
                }
            }
            else
            {
                l_return_status_S32 = EXIT_FAILURE;
                LOGE(&gResMgrDioLogContext, "Failed to initialize dio hw layer");
            }
        }
        else
        {
            l_return_status_S32 = EXIT_FAILURE;
            LOGE(&gResMgrDioLogContext, "Failed to count number of mask bits");
        }
    }
    else
    {
        l_return_status_S32 = EXIT_FAILURE;
        LOGE(&gResMgrDioLogContext, "Failed to parse user options");
    }

    /* Deallocate, in case gpio device is created under FS. */
    if ( EOK == l_ret_dio_init_S32 )
    {
        l_ret_dio_hw_fini_BOOL = dio_fini();
        if ( false == l_ret_dio_hw_fini_BOOL )
        {
            LOGE(&gResMgrDioLogContext, "dio_fini has failed" );
            l_return_status_S32 = EXIT_FAILURE;
        }
    }
    
    /* Deallocate, in case of IO Mapping success. */
    if ( true == l_ret_dio_hw_init_BOOL )
    {
        l_ret_dio_hw_fini_BOOL = dio_hw_fini ( &g_dio_pindata );
        if ( false == l_ret_dio_hw_fini_BOOL )
        {
            LOGE(&gResMgrDioLogContext, "dio_hw_fini has failed" );
            l_return_status_S32 = EXIT_FAILURE;
        }
    }
    
    
    //Drop procmgr ability
    if(UserParm != NULL)
    {
        if(procmgr_ability( 0,
                            PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                            PROCMGR_AOP_DENY | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS| PROCMGR_AID_EOL)
                            != EOK){
            LOGD(&gResMgrDioLogContext, "Unable to gain procmgr abilities for nonroot operation\n");
            l_return_status_S32 = EXIT_FAILURE;
        }
        /* coverity[misra_c_2012_rule_21_3_violation] : FALSE */
        free( UserParm);
    }

    LOG_UNREGISTER_CONTEXT(gResMgrDioLogContext);

    return l_return_status_S32;
}

/*!**************************************************************************************************************
    * \fn         static int32_t dio_init(void)
    * \brief      DIO RM init, creates the path name spaces and the related infrastructure
    * \return     int    Return value to indicate success or error code  
 ****************************************************************************************************************/

static int32_t dio_init(void)
{
    int32_t l_status_dio_init_S32 = EOK;
    bool l_ret_dio_attach_pulse_BOOL = false;
    bool l_ret_dio_setup_timer_BOOL = false;
    struct sigaction sigAct;
    static ts_dio_dev_t g_dio_dev;

    g_dpp_SP = dispatch_create();
    if (NULL == g_dpp_SP)
    {
        if ( __get_errno_ptr() != NULL )
        {
            /* coverity[cert_con33_c_violation] : FALSE */
            LOGE(&gResMgrDioLogContext, "dispatch_create() function Failed %s", strerror (errno));
        }
        l_status_dio_init_S32 = ENOMEM;
    }
    else
    {
        ( void ) memset ( &g_rattr, 0, sizeof ( g_rattr ) );
        g_rattr.msg_max_size = DIO_RESMGR_MSGSIZE;
        g_rattr.nparts_max = 1;
        /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        iofunc_func_init ( _RESMGR_CONNECT_NFUNCS, &g_connect_funcs,
        /* coverity[misra_c_2012_rule_10_3_violation] : FALSE */                   
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */                   
                           _RESMGR_IO_NFUNCS, &g_io_funcs );
        g_connect_funcs.open = dio_io_open;
        g_io_funcs.read = dio_io_read;
        g_io_funcs.read64 = dio_io_read;
        g_io_funcs.write = dio_io_write;
        g_io_funcs.devctl = dio_io_devctl;
        iofunc_attr_init ( &g_ioattr, _S_IFREG | 0666, NULL, NULL );

        /** Register device name */
        g_pathID_export_S32 = resmgr_attach ( g_dpp_SP, &g_rattr, "/dev/gpio/export", _FTYPE_ANY, _RESMGR_FLAG_FTYPEALL, &g_connect_funcs, &g_io_funcs, &g_ioattr );

        if ( g_pathID_export_S32 == -1 )
        {
            LOGE(&gResMgrDioLogContext, "resmgr_attach on /dev/gpio/export pathname has failed" );
            l_status_dio_init_S32 = EXIT_FAILURE;
        }
        else
        {
            g_pathID_unexport_S32 = resmgr_attach ( g_dpp_SP, &g_rattr, "/dev/gpio/unexport", _FTYPE_ANY, _RESMGR_FLAG_FTYPEALL, &g_connect_funcs, &g_io_funcs, &g_ioattr );

            if ( g_pathID_unexport_S32 == -1 )
            {
                LOGE(&gResMgrDioLogContext, "resmgr_attach on /dev/gpio/unexport pathname has failed" );
                l_status_dio_init_S32 = EXIT_FAILURE;
            }
            else
            {
                dio_set_default_data( &g_dio_pindata);
                l_ret_dio_attach_pulse_BOOL = dio_attach_pulse ( &g_dio_dev );

                if ( l_ret_dio_attach_pulse_BOOL == true )
                {
                    l_ret_dio_setup_timer_BOOL = dio_setup_timer ( &g_dio_dev );

                    if ( l_ret_dio_setup_timer_BOOL == true )
                    {
                       g_ctp = dispatch_context_alloc ( g_dpp_SP );
                        LOGD(&gResMgrDioLogContext, "Dispatch allocation done " );
                        /** Provide handling for the SIGTERM signal */
                        ( void ) sigemptyset ( &sigAct.sa_mask );
                        ( void ) sigaddset ( &sigAct.sa_mask, SIGTERM );
                        sigAct.sa_handler = &dio_ExitSignal;
                        sigAct.sa_flags = 0;
                        ( void ) sigaction ( SIGTERM, &sigAct, NULL );

                        /** Background the dio RM */
                         /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
                        ( void ) procmgr_daemon ( 0, (unsigned int)PROCMGR_DAEMON_NOCLOSE | (unsigned int)PROCMGR_DAEMON_NODEVNULL );
                    }
                    else
                    {
                        l_status_dio_init_S32 = EXIT_FAILURE;
                    }
                }
                else
                {
                    l_status_dio_init_S32 = EXIT_FAILURE;
                }
            }
        }
    }
    return l_status_dio_init_S32;
}

/*!**************************************************************************************************************
    * \fn         static bool dio_fini ( void )
    * \brief      Function to free all the resources allocated to the DIO Driver
    * \return     bool    Return value to indicate true or false for the operation done 
 ****************************************************************************************************************/

static bool dio_fini ( void )
{
    bool l_fini_ret_BOOL = true;
    int32_t  l_export_ret_S32 = 0;
    int32_t  l_unexport_ret_S32 = 0;
    int32_t  l_fini_ret_S32 = 0;
    uint32_t l_pin_U32;
    uint32_t l_pinid_U32;

    l_export_ret_S32 = resmgr_detach ( g_dpp_SP, g_pathID_export_S32, _RESMGR_DETACH_ALL );

    if ( l_export_ret_S32 < 0 )
    {
        l_fini_ret_BOOL = false;
        LOGE(&gResMgrDioLogContext, "resmgr_detach /dev/export ret1 failed: %d", l_export_ret_S32 );
    }
    else
    {
        l_unexport_ret_S32 = resmgr_detach ( g_dpp_SP, g_pathID_unexport_S32, _RESMGR_DETACH_ALL );

        if ( l_unexport_ret_S32 < 0 )
        {
            l_fini_ret_BOOL = false;
            LOGE(&gResMgrDioLogContext, "resmgr_detach /dev/unexport ret2 failed: %d", l_unexport_ret_S32 );
        }
        else {/*MISRA*/}
    }

    for ( l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID; l_pin_U32++ )
    {
        if ( true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL )
        {
            l_pinid_U32 = l_pin_U32;
            l_fini_ret_S32 = dio_unexport ( &l_pinid_U32 );

            if ( l_fini_ret_S32 != EOK )
            {
                l_fini_ret_BOOL = false;
                LOGE(&gResMgrDioLogContext, "unexport on %d failed: %d", l_pinid_U32, l_fini_ret_S32 );
            }
            else
            {
                LOGD(&gResMgrDioLogContext, "unexport on %d is success: %d", l_pinid_U32, l_fini_ret_S32 );
            }
        }
        else {/*MISRA*/}
    }
    (void) dispatch_destroy ( g_dpp_SP );

    /* Added to justify PR Defect 788474 */
    /* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
    if ( NULL ==g_ctp )
    {
        LOGD(&gResMgrDioLogContext, "CTP is already NULL" );
    }
    else
    {
        dispatch_context_free (g_ctp );
    }


    return l_fini_ret_BOOL;
}


/*!**************************************************************************************************************
    * \fn        static int32_t dio_io_open ( resmgr_context_t *dioOpenctp_p, io_open_t *msg, RESMGR_HANDLE_T *handle, void *extra )
    * \brief     Function for open. This function is called when an application calls the open() function.
    * \param[in] dioOpenctp_p - resmgr_context_t* Resource Manager Context
    * \param[in] msg - io_open_t* io_open message structure. Contains the message that the Resource Manager received.
    * \param[in] handle - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                     controlling
    * \param[in] extra - void* Extra information from the library
    * \return    int - Return value to indicate success or error code 
 ****************************************************************************************************************/
/* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
static int32_t dio_io_open ( resmgr_context_t *dioOpenctp_p, io_open_t *msg, RESMGR_HANDLE_T *handle, void *extra )
{
    int32_t l_status_S32 = iofunc_open_default ( dioOpenctp_p, msg, handle, extra );

    if ( EOK != l_status_S32 )
    {
        LOGE(&gResMgrDioLogContext, "Error opening dio device : %d", l_status_S32 );
    }
    else
    {/*MISRA*/}

    return  l_status_S32 ;
}

/*!**************************************************************************************************************
    * \fn         static int32_t dio_io_read ( resmgr_context_t *dioReadctp_p, io_read_t *msg, RESMGR_OCB_T *ocb )
    * \brief      Function for read. This function is called when an application calls the read() function.
    * \param[in]  dioReadctp_p - resmgr_context_t* Resource Manager Context
    * \param[in]  msg - io_read_t message structure. Contains the message that the Resource Manager received.
    * \param[in]  handle - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                     controlling
    * \param[in]  extra - void* Extra information from the library
    * \return     int - Return value to indicate success or error code    
 ****************************************************************************************************************/

/* coverity[misra_c_2012_rule_19_2_violation] : FALSE */
static int32_t dio_io_read ( resmgr_context_t *dioReadctp_p, io_read_t *msg, RESMGR_OCB_T *ocb )
{
    size_t          l_nleft_U64 = 0;
    size_t          l_nbytes_U64;
    uint8_t         l_nparts_U8;
    int32_t         l_status_S32 = EXIT_SUCCESS;
    int32_t         l_bitstatus_S32;
    const char      *buffer_c = NULL;
    uint32_t        l_flag_U32 = 1;
    uint32_t        l_pin_U32;
    uint32_t        l_banknum_U32;

    /*   Here we verify if the client has the access
     * rights needed to read from our device*/
    l_status_S32 = iofunc_read_verify ( dioReadctp_p, msg, ocb, NULL );

    if ( l_status_S32 != EOK )
    {
        LOGE(&gResMgrDioLogContext, "io_read verify failed %d ", l_status_S32 );
    }

    /* We check if our read callback was called because of
     * a pread() or a normal read() call. If pread(), we return
     * with an error code indicating that we don't support it. */
    if ( l_status_S32 == EOK )
    {
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        if ( ( msg->i.xtype & (unsigned int)_IO_XTYPE_MASK ) != (unsigned int)_IO_XTYPE_NONE )
        {
            LOGE(&gResMgrDioLogContext, "no pread is supported %d ", l_status_S32 );
            l_status_S32 = ENOSYS;
        }
    }

    if ( l_status_S32 == EOK )
    {
        for ( l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID; l_pin_U32++ )
        {
            if(true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL)
            {
                l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;

                if ( g_dio_pindata.dio_pin_sa[l_pin_U32].dir_pathID_S32 == dioReadctp_p->id )
                {
                    l_flag_U32 = 0;
                    if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                    {
                        l_bitstatus_S32 = dio_get_dir ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32]);
                    }
                    else
                    {
                        l_bitstatus_S32 = ERROR;
                        LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                    }

                    if ( l_bitstatus_S32 == 0 )
                    {
                        buffer_c = "out\n";
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
                        g_ioattr.nbytes = ( long ) strlen ( buffer_c ) + 1;
                    }
                    else if ( l_bitstatus_S32 == 1 )
                    {
                        buffer_c = "in\n";
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
                        g_ioattr.nbytes = ( long ) strlen ( buffer_c ) + 1;
                    }
                    else
                    {
                        l_status_S32 = EXIT_FAILURE;
                        LOGE(&gResMgrDioLogContext, "Got Invalid Direction value %s and status is %d ",buffer_c, l_status_S32 );
                    }
                }
                else if ( g_dio_pindata.dio_pin_sa[l_pin_U32].val_pathID_S32 ==  dioReadctp_p->id )
                {
                    l_flag_U32 = 0;
                    if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                    {
                        l_bitstatus_S32 = dio_read_channel ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32] );
                    }
                    else
                    {
                        LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                        l_bitstatus_S32 = ERROR;
                    }

                    if ( l_bitstatus_S32 == 1 )
                    {
                        buffer_c = "1\n";
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
                        ocb->attr->nbytes = ( long ) strlen ( buffer_c ) + 1;
                    }
                    else if ( l_bitstatus_S32 == 0 )
                    {
                        buffer_c = "0\n";
                        /* coverity[cert_int31_c_violation] : FALSE */
                        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
                        ocb->attr->nbytes = ( long ) strlen ( buffer_c ) + 1;
                    }
                    else
                    {
                        l_status_S32 = EXIT_FAILURE;
                        LOGE(&gResMgrDioLogContext, "Got Invalid Value %s and status is %d ", buffer_c, l_status_S32 );
                    }
                }
                else {/*MISRA*/}

                if( l_flag_U32 == 0U )
                {
                    l_status_S32 = EXIT_SUCCESS;
                    break;
                }
                else {/*MISRA*/}
            }
            else
            {
                l_status_S32 = EXIT_FAILURE;
                LOGD(&gResMgrDioLogContext, "Pin has not initialized %d", l_pin_U32);
            }
        }
        if ( l_status_S32 == EXIT_SUCCESS )
        {
            l_nleft_U64 = ( size_t ) ocb->attr->nbytes - ( size_t ) ocb->offset;
            l_nbytes_U64 = min ( _IO_READ_GET_NBYTES ( msg ), l_nleft_U64 );

            if ( l_nbytes_U64 > 0U )
            {
                /* set up the return data IOV */                
                /* coverity[cert_exp40_c_violation] : FALSE */
                /* coverity[cert_arr30_c_violation] : FALSE */
                /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
                /* coverity[misra_c_2012_rule_18_4_violation] : FALSE */
                /* coverity[misra_c_2012_rule_11_8_violation] : FALSE */
                SETIOV ( dioReadctp_p->iov, buffer_c + ocb->offset, l_nbytes_U64 );
                /* set up the number of bytes (returned by client's read()) */
                _IO_SET_READ_NBYTES ( dioReadctp_p, ( ssize_t ) l_nbytes_U64 );
                /*
                 * advance the offset by the number of bytes
                 * returned to the client.
                 */
                ocb->offset += (ssize_t)l_nbytes_U64;
                l_nparts_U8 = 1;
                /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
                /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
                l_status_S32 = (int32_t)_RESMGR_NPARTS ( l_nparts_U8 );
            }
            else
            {
                /* they've asked for zero bytes or they've already previously read everything */
                /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
                _IO_SET_READ_NBYTES ( dioReadctp_p, 0 );
                l_nparts_U8 = 0;
                /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
                /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
                l_status_S32 = (int32_t)_RESMGR_NPARTS ( l_nparts_U8 );
            }

            /* mark the access time as invalid (we just accessed it) */
            if ( msg->i.nbytes > g_clear_bit_U32 )
            {
                /* coverity[misra_c_2012_rule_10_4_violation] : FALSE */
                /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
                ocb->attr->flags |= IOFUNC_ATTR_ATIME;
                /* coverity[misra_c_2012_directive_4_9_violation] : FALSE */
                /* coverity[misra_c_2012_rule_10_1_violation] : FALSE */
                l_status_S32 = (int32_t)_RESMGR_NPARTS ( l_nparts_U8 );
            }
            else {/*MISRA*/}
        }
        else {/*MISRA*/}
    }
    else
    {
        l_status_S32 = EXIT_FAILURE;
    }

    return  l_status_S32;
}

/*!**************************************************************************************************************
    * \fn           static int32_t dio_io_write ( resmgr_context_t *dioWritectp_p, io_write_t *msg, RESMGR_OCB_T *ocb )
    * \brief        Function for write. This function is called when an application calls the write() function.
    * \param[in]    dioWritectp_p - resmgr_context_t* Resource Manager Context
    * \param[in]    msg - io_write_t* io_write message structure. Contains the message that the Resource Manager received.
    * \param[in]    handle - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                     controlling
    * \param[in]    extra - void* Extra information from the library
    * \return       int - Return value to indicate success or error code 
 ****************************************************************************************************************/

static int32_t dio_io_write ( resmgr_context_t *dioWritectp_p, io_write_t *msg, RESMGR_OCB_T *ocb )
{

    int32_t  l_result_S32;
    int32_t  l_status_S32 = EXIT_SUCCESS;
    bool     l_ret_dio_data_extract_BOOL = false;
    int32_t  l_ret_dio_export_S32 = 0;
    int32_t  l_ret_dio_unexport_S32 = 0;
    int32_t  l_ret_dio_set_dir_S32 = 0;
    int32_t  l_ret_dio_write_chnl_S32 = 0;
    uint32_t l_pin_U32 = 0;
    uint32_t l_flag_U32 = 1;

    uint32_t l_buf_val_U32;
    uint32_t l_banknum_U32;
    uint32_t l_index_U32;
    uint32_t l_data_U32;
    size_t   l_nbytes_U64 = 0;

    const char *l_direction_out_CHAR = "out\n";
    const char *l_direction_in_CHAR = "in\n";

    static char     l_buf_CHAR[DIO_RESMGR_MSGSIZE];

    /* Check the access permissions of the client */
    l_status_S32 = iofunc_write_verify ( dioWritectp_p, msg, ocb, NULL );

    if ( l_status_S32 != EOK )
    {
        LOGE(&gResMgrDioLogContext, "io_write verify failed %d ", l_status_S32 );
    }

    if ( l_status_S32 == EOK )
    {
        /* coverity[misra_c_2012_directive_4_6_violation] : FALSE */
        if ( ( msg->i.xtype & (unsigned int)_IO_XTYPE_MASK ) != (unsigned int)_IO_XTYPE_NONE )
        {
            l_status_S32 = ENOSYS;
            LOGE(&gResMgrDioLogContext, "type checking failed %d ", l_status_S32 );
        }
    }

    if ( l_status_S32 == EOK )
    {
        l_nbytes_U64 = _IO_WRITE_GET_NBYTES ( msg );

        if ( l_nbytes_U64 > ( ( size_t ) dioWritectp_p->info.srcmsglen - ( size_t ) dioWritectp_p->offset - sizeof ( io_write_t ) ) )
        {
            l_status_S32 = EBADMSG;
            LOGE(&gResMgrDioLogContext, "large size of message greater than the available memory %d ", l_status_S32 );
        }
    }

    if ( l_status_S32 == EOK )
    {
        _IO_SET_WRITE_NBYTES ( dioWritectp_p, ( ssize_t ) l_nbytes_U64 );

        ( void ) memset ( l_buf_CHAR, 0, sizeof ( l_buf_CHAR ) );
       
        if ( resmgr_msgread ( dioWritectp_p, l_buf_CHAR, l_nbytes_U64, sizeof ( msg->i ) ) == ERROR )
        {
            l_status_S32 = EXIT_FAILURE;
            LOGE(&gResMgrDioLogContext, "Read a message from a client failed status = %d", l_status_S32 );
        }
        else
        {
            LOGD(&gResMgrDioLogContext, "got write of %d bytes, data: %s", msg->i.nbytes, l_buf_CHAR );

            if ( g_pathID_export_S32 == dioWritectp_p->id )
            {
                l_buf_val_U32 = ( uint32_t ) strtol ( l_buf_CHAR, NULL, 0 );

                if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ERANGE ) ) )
                {
                    l_status_S32 = EXIT_FAILURE;
                    LOGE(&gResMgrDioLogContext, "strtol for export failed, status : %d l_buf_val_U32 is %x ", l_status_S32, l_buf_val_U32 );
                    
                }
                else
                {
                    l_index_U32 = l_buf_val_U32;
                    if(l_buf_val_U32 <  g_gpio_id_max_U32)
                    {
                        if( l_index_U32 < DIO_MAX_ID )
                        {
                            if ( false == g_dio_pindata.dio_pin_sa[l_index_U32].is_valid_BOOL )
                            {
                                l_ret_dio_export_S32 = dio_export ( &l_buf_val_U32 );

                                if ( l_ret_dio_export_S32 == EXIT_FAILURE )
                                {
                                    l_status_S32 = EXIT_FAILURE;
                                    LOGE(&gResMgrDioLogContext, "dio_export failed, status : %d ", l_status_S32 );
                                }
                                else
                                {
                                    /* Function to call in order to extract the data such as Pin number and bank number */
                                    l_ret_dio_data_extract_BOOL = dio_data_extract ( &g_dio_pindata, ( uint32_t ) l_buf_val_U32 );

                                    if ( l_ret_dio_data_extract_BOOL == false )
                                    {
                                        l_status_S32 = EXIT_FAILURE;
                                        LOGE(&gResMgrDioLogContext, "dio_data_extract failed, status : %d ", l_status_S32 );
                                    }
                                    else
                                    {
                                        l_status_S32 = EXIT_SUCCESS;
                                        LOGD(&gResMgrDioLogContext, "dio_data_extract success");
                                    }
                                }
                            }
                            else
                            {
                                LOGD(&gResMgrDioLogContext, "GPIO Pin already exported " );
                            }
                        }
                        else
                        {
                            l_status_S32 = EXIT_FAILURE;
                            LOGE(&gResMgrDioLogContext, "gpio id:%u exceeding DIO MAX ID", l_index_U32);
                        }
                    }
                    else
                    {
                        l_status_S32 = EXIT_FAILURE;
                        LOGE(&gResMgrDioLogContext, "GPIO Pin %d is invalid",l_buf_val_U32);
                    }
                }
            }
            else if ( g_pathID_unexport_S32 == dioWritectp_p->id )
            {
                l_buf_val_U32 = ( uint32_t ) strtol ( l_buf_CHAR, NULL, 0 );

                if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ERANGE ) ) )
                {
                    l_status_S32 = EXIT_FAILURE;
                    LOGE(&gResMgrDioLogContext, "strtol for export failed, status : %d l_buf_val_U32 is %x ", l_status_S32, l_buf_val_U32 );
                }
                else
                {
                    l_index_U32 = l_buf_val_U32;
                    if(l_buf_val_U32 <  g_gpio_id_max_U32)
                    {
                        if( l_index_U32 < DIO_MAX_ID )
                        {
                            if ( true == g_dio_pindata.dio_pin_sa[l_index_U32].is_valid_BOOL )
                            {
                                l_ret_dio_unexport_S32 = dio_unexport ( &l_buf_val_U32 );

                                if ( l_ret_dio_unexport_S32 == EXIT_FAILURE )
                                {
                                    l_status_S32 = EXIT_FAILURE;
                                    LOGE(&gResMgrDioLogContext, "dio_unexport failed, status : %d ", l_status_S32 );
                                }
                                else
                                {
                                    l_status_S32 = EXIT_SUCCESS;
                                    g_dio_pindata.dio_pin_sa[l_index_U32].is_valid_BOOL = false;
                                    LOGD(&gResMgrDioLogContext, "Unexport successful");
                                }
                            }
                        }
                        else
                        {
                            LOGE(&gResMgrDioLogContext, "gpio id:%u exceeding DIO MAX ID", l_index_U32 );
                            l_status_S32 = EXIT_FAILURE;
                        }
                    }
                    else
                    {
                        l_status_S32 = EXIT_FAILURE;
                        LOGE(&gResMgrDioLogContext, "GPIO Pin %d is invalid",l_buf_val_U32);
                    }
                }
            }
            else
            {
                for ( l_pin_U32 = g_clear_bit_U32; l_pin_U32 < DIO_MAX_ID; l_pin_U32++ )
                {
                    if(true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL)
                    {
                        l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;

                        if ( g_dio_pindata.dio_pin_sa[l_pin_U32].dir_pathID_S32 == dioWritectp_p->id )
                        {
                            l_flag_U32 = 0;
                            // direction = l_buf_CHAR;
                            l_result_S32 = strncmp ( l_buf_CHAR, l_direction_out_CHAR, 4 );

                            if ( l_result_S32 == ( int32_t ) 0 )
                            {
                                l_data_U32 = 1;
                            }
                            else
                            {
                                l_result_S32 = strncmp ( l_buf_CHAR, l_direction_in_CHAR, 3 );

                                if ( l_result_S32 == 0 )
                                {
                                    l_data_U32 = 0;
                                }
                                else
                                {
                                    l_status_S32 = EXIT_FAILURE;
                                    LOGE(&gResMgrDioLogContext, "Failed in Strmcmp , status : %d ", l_status_S32 );
                                }
                            }
                            if(l_status_S32 != EXIT_FAILURE)
                            {
                                if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                                {
                                    l_ret_dio_set_dir_S32 = dio_set_dir ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32], l_data_U32 );
                                }
                                else
                                {
                                    l_ret_dio_set_dir_S32 = ERROR;
                                    LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                                }
                                if ( l_ret_dio_set_dir_S32 == -1 )
                                {
                                    l_status_S32 = EXIT_FAILURE;
                                    LOGE(&gResMgrDioLogContext, "l_ret_dio_set_dir_S32 : %d, status : %d ", l_ret_dio_set_dir_S32, l_status_S32 );
                                }
                                else {/*MISRA*/}
                            }
                        }
                        else if ( g_dio_pindata.dio_pin_sa[l_pin_U32].val_pathID_S32 ==  dioWritectp_p->id )
                        {
                            l_flag_U32 = 0;
                            l_buf_val_U32 = ( uint32_t ) strtol ( l_buf_CHAR, NULL, 0 );

                            if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ERANGE ) ) )
                            {
                                l_status_S32 = EXIT_FAILURE;
                                LOGE(&gResMgrDioLogContext, "strtol for export failed, status : %d l_buf_val_U32 is %x ", l_status_S32, l_buf_val_U32 );

                            }
                            else {/*MISRA*/}

                            /* Need to invoke write channel */
                            if ( l_status_S32 != EXIT_FAILURE)
                            {
                                if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                                {
                                    l_ret_dio_write_chnl_S32 = dio_write_channel ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32], ( uint32_t ) l_buf_val_U32 );
                                }
                                else
                                {
                                    l_ret_dio_write_chnl_S32 = ERROR;
                                    LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                                }
                                if ( l_ret_dio_write_chnl_S32 == -1 )
                                {
                                    l_status_S32 = EXIT_FAILURE;
                                    LOGE(&gResMgrDioLogContext, "l_ret_dio_write_chnl_S32 : %d, status : %d ", l_ret_dio_write_chnl_S32, l_status_S32 );
                                }
                                else
                                {
                                    LOGD(&gResMgrDioLogContext, "dio_write_channel SUCCESS");
                                }
                            }
                        }
                        else {/*MISRA*/}

                        if ( ( l_flag_U32 == 0U ) )
                        {
                            break;
                        }
                        else {/*MISRA*/}
                    }
                    else
                    {
                        LOGD(&gResMgrDioLogContext, "Pin has not initialized %d", l_pin_U32);
                    }
                }
            }
        }
        if ( msg->i.nbytes > g_clear_bit_U32 )
        {
            ocb->attr->flags |= (uint32_t)IOFUNC_ATTR_MTIME | (uint32_t)IOFUNC_ATTR_CTIME;
            l_status_S32 = _RESMGR_NPARTS ( 0 );
        }
        else
        {
            l_status_S32 = EXIT_FAILURE;
        }
    }
    else
    {
        LOGE(&gResMgrDioLogContext, "Failed : %d ", l_status_S32 );
        l_status_S32 = EXIT_FAILURE;
    }
    return ( int32_t ) ( l_status_S32 );
}


/*!**************************************************************************************************************
    * \fn        static int32_t dio_io_devctl ( resmgr_context_t *dioDevctlctp_p, io_devctl_t *msg, RESMGR_OCB_T *ocb )
    * \brief     Function for devctl. This function is called when an application calls the devctl() function.
    * \param[in] dioDevctlctp_p - resmgr_context_t* Resource Manager Context
    * \param[in] msg - io_devctl_t* io_devctl message structure. Contains the message that the Resource Manager received.
    * \param[in] handle - RESMGR_HANDLE_T* defines the characteristics of the device that the resource manager is
                                     controlling
    * \param[in] extra - void* Extra information from the library
    * \return    int - Return value to indicate success or error code
 ****************************************************************************************************************/


static int32_t dio_io_devctl ( resmgr_context_t *dioDevctlctp_p, io_devctl_t *msg, RESMGR_OCB_T *ocb )
{
    uint32_t l_nbytes_U32;
    int32_t l_bitstatus_S32;
    int32_t l_ret_Dio_set_dir_S32 = 0;
    int32_t l_ret_Dio_write_chnl_S32 = 0;
    int32_t l_status_devctl_S32 = EOK;
    uint32_t l_pin_U32;
    const gpio_buffer_type *l_set_data_dir_SP = NULL;
    gpio_buffer_type *l_get_data_dir_SP = NULL;
    uint32_t l_banknum_U32;

    l_status_devctl_S32 = iofunc_devctl_default ( dioDevctlctp_p, msg, ocb );

    if ( l_status_devctl_S32 != _RESMGR_DEFAULT )
    {
        l_status_devctl_S32 = EAGAIN;
        LOGE(&gResMgrDioLogContext, "Devctl failed status is %d", l_status_devctl_S32 );
    }
    else
    {
        l_nbytes_U32 = 0;

        switch ( msg->i.dcmd )
        {
        case GPIO_DIRECTION_WRITE:
        {
            for (  l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID ; l_pin_U32++ )
            {
                if ( true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL )
                {
                    l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;
                    if ( g_dio_pindata.dio_pin_sa[l_pin_U32].dir_pathID_S32 == dioDevctlctp_p->id )
                    {
                        l_set_data_dir_SP = ( gpio_buffer_type * ) _DEVCTL_DATA (( msg->i ));

                        if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                        {
                            l_ret_Dio_set_dir_S32 = dio_set_dir ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32], (unsigned int)l_set_data_dir_SP->e_direction );
                        }
                        else
                        {
                            l_ret_Dio_set_dir_S32 = ERROR;
                            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                        }
                        if ( l_ret_Dio_set_dir_S32 == -1 )
                        {
                            l_status_devctl_S32 = EINVAL;
                            if ( __get_errno_ptr() != NULL )
                            {
                                LOGE(&gResMgrDioLogContext, "Devctl failed %s and status is %d and data is %d ", strerror ( errno ), l_status_devctl_S32, l_set_data_dir_SP->e_direction );
                            }
                        }
                        else
                        {
                            l_status_devctl_S32 = EOK;
                            LOGD(&gResMgrDioLogContext, "direction %d write using devctl is successful and status is %d ", l_set_data_dir_SP->e_direction, l_status_devctl_S32 );
                        }

                        break;
                    }
                    else {/*MISRA*/}
                }
            }
        }
        break;

        case GPIO_DIRECTION_READ:
        {
            for ( l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID ; l_pin_U32++ )
            {
                if ( true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL )
                {
                    l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;
                    if ( g_dio_pindata.dio_pin_sa[l_pin_U32].dir_pathID_S32 == dioDevctlctp_p->id )
                    {
                        l_get_data_dir_SP = ( gpio_buffer_type * ) _DEVCTL_DATA (( msg->i ));

                        if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                        {
                            l_bitstatus_S32 = dio_get_dir ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32] );
                        }
                        else
                        {
                            l_bitstatus_S32 = ERROR;
                            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                        }
                        if ( l_bitstatus_S32 == 0 )
                        {
                            l_get_data_dir_SP->e_direction = e_gpio_direction_in;
                        }
                        else if ( l_bitstatus_S32 == 1 )
                        {
                            l_get_data_dir_SP->e_direction = e_gpio_direction_out;
                        }
                        else
                        {
                            l_status_devctl_S32 = EINVAL;
                            LOGE(&gResMgrDioLogContext, "direction read using devctl has failed and status is %d ", l_status_devctl_S32 );
                        }
                        break;
                    }
                    else {}
                }
                else {}
            }

            l_nbytes_U32 = (uint32_t)sizeof ( gpio_buffer_type );
            ( void ) memset ( &msg->o, 0, sizeof ( msg->o ) );
            msg->o.nbytes = l_nbytes_U32;
            msg->o.ret_val = l_status_devctl_S32;
            l_status_devctl_S32 = _RESMGR_PTR ( dioDevctlctp_p, &msg->o, sizeof ( msg->o ) + l_nbytes_U32 );
        }
        break;

        case GPIO_VALUE_WRITE:
        {
            for ( l_pin_U32 = 0; l_pin_U32 < DIO_MAX_ID ; l_pin_U32++ )
            {
                if ( true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL )
                {
                    l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;

                    if ( g_dio_pindata.dio_pin_sa[l_pin_U32].val_pathID_S32 == dioDevctlctp_p->id )
                    {
                        l_set_data_dir_SP = ( gpio_buffer_type * ) _DEVCTL_DATA (( msg->i ));

                        /* Read the input message passed with the DEVCTL command */

                        if( l_banknum_U32 < TI_MAX_BANK_PER_DIO)
                        {
                            l_ret_Dio_write_chnl_S32 = dio_write_channel ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32], l_set_data_dir_SP->gpio_value );
                        }
                        else
                        {
                            l_ret_Dio_write_chnl_S32 = ERROR;
                            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                        }
                        if ( l_ret_Dio_write_chnl_S32 == -1 )
                        {
                            l_status_devctl_S32 = EINVAL;
                            if ( __get_errno_ptr() != NULL )
                            {
                                LOGE(&gResMgrDioLogContext, "Devctl failed for write channel %s and status is %d , data is %d ", strerror ( errno ), l_status_devctl_S32, l_set_data_dir_SP->gpio_value  );
                            }
                        }
                        else
                        {
                            l_status_devctl_S32 = EOK;
                            LOGD(&gResMgrDioLogContext, "Value %d write using devctl is successful and status is %d ",l_set_data_dir_SP->gpio_value, l_status_devctl_S32 );
                        }
 
                        break;
                    }
                    else {}
                }
                else {/*MISRA*/}
            }
        }
        break;

        case GPIO_VALUE_READ:
        {
            for ( l_pin_U32 = 0;  l_pin_U32 < DIO_MAX_ID ; l_pin_U32++ )
            {
                if ( true == g_dio_pindata.dio_pin_sa[l_pin_U32].is_valid_BOOL )
                {
                    l_banknum_U32 = g_dio_pindata.dio_pin_sa[l_pin_U32].bank_num_U32;

                    if ( g_dio_pindata.dio_pin_sa[l_pin_U32].val_pathID_S32 == dioDevctlctp_p->id )
                    {
                        l_get_data_dir_SP = ( gpio_buffer_type * ) _DEVCTL_DATA (( msg->i ));

                        if( l_banknum_U32 < TI_MAX_BANK_PER_DIO )
                        {
                            l_bitstatus_S32 = dio_read_channel ( &g_dio_pindata.dio_pin_sa[l_pin_U32], &g_dio_pindata.dio_addr_sa[l_banknum_U32] );
                        }
                        else
                        {
                            l_bitstatus_S32 = ERROR;
                            LOGE(&gResMgrDioLogContext, "Bank num:%u exceeding max bank per DIO", l_banknum_U32);
                        }
                        if ( l_bitstatus_S32 == 1 )
                        {
                            l_get_data_dir_SP->gpio_value = 1;
                        }
                        else if ( l_bitstatus_S32 == 0 )
                        {
                            l_get_data_dir_SP->gpio_value = 0;
                        }
                        else
                        {
                            l_status_devctl_S32 = EINVAL;
                            LOGE(&gResMgrDioLogContext, "Devctl failed for read channel status is %d", l_status_devctl_S32 );
                        }
                        break;
                    }
                    else {/*MISRA*/}
                }
                else {/*MISRA*/}
            }
            l_nbytes_U32 = (uint32_t)sizeof ( gpio_buffer_type );
            ( void ) memset ( &msg->o, 0, sizeof ( msg->o ) );
            msg->o.nbytes = l_nbytes_U32;
            l_status_devctl_S32 = _RESMGR_PTR ( dioDevctlctp_p, &msg->o, sizeof ( msg->o ) + l_nbytes_U32 );
        }
        break;


        default:
            l_status_devctl_S32 = ENOSYS;
            LOGE(&gResMgrDioLogContext, "unknown devctl command status is %d", l_status_devctl_S32 );
            break;

        }
    }
    return  l_status_devctl_S32;
}

/*!*******************************************************************************************************************
    * \fn         static bool dio_getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
    * \brief      Function to check the options passed while starting the Driver
    * \param[out] p_opt char* to be parsed from command line.
    * \param[in]  p_argc int Count of command line parameters for the Resource manager.
    * \param[in]  p_argv[] char**  Command line parameters for the resource manager
    * \return     bool    Return value to indicate true or false for the operation done
 *********************************************************************************************************************/
static bool dio_getopt_chk ( char *const p_opt, const int32_t p_argc, char *const p_argv[] )
{
    bool l_ret_val_BOOL = false;
    int32_t l_getopt_ret_S32;
    l_getopt_ret_S32 = getopt ( p_argc, p_argv, "b:m:U:" );

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

/*!*******************************************************************************************************************
    * \fn         static bool dio_options ( const int32_t argc, char **const argv, ts_dio_addr_t *dioOptionsAddr_p )
    * \brief      Function to take the options to save pyhsical addr of bank and bank's mask passed as input while starting the Driver
    * \param[in]  argc int Count of command line parameters for the Resource manager.
    * \param[in]  argv[] char**  Command line parameters for the resource manager
    * \param[out] dioOptionsAddr_p Array of structure in which physical addr of gpio bank and bank's mask address is stored.
    * \return     bool    Return value to indicate true or false for the operation done
    
 *********************************************************************************************************************/
static bool dio_options ( const int32_t argc, char **const argv, ts_dio_addr_t *dioOptionsAddr_p )
{
    char l_opt_CHAR = '0';
    uint8_t l_bankbase_U8 = 0;
    uint8_t l_bankmask_U8 = 0;
    bool l_ret_BOOL = true;
    int32_t l_status_S32;

    // put ':' in the starting of the
    // string so that program can
    //distinguish between '?' and ':'

    while ( true == dio_getopt_chk ( &l_opt_CHAR, argc, argv ) )
    {
        switch ( l_opt_CHAR )
        {
        case 'b':
            if ( l_bankbase_U8 < TI_MAX_BANK_PER_DIO )
            {
                dioOptionsAddr_p[l_bankbase_U8].physical_addr = ( uint32_t ) strtol ( optarg, NULL, 0 );
                
                if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ERANGE ) ) )
                {
                    l_status_S32 = EXIT_FAILURE;
                    LOGE(&gResMgrDioLogContext, "unable to convert \"physical_addr\" to unsigned int: %s errno=%d\n", optarg, l_status_S32 );
                    l_ret_BOOL = false;
                    
                }
                else
                {
                }

                l_bankbase_U8++;
            }
            else
            {
                LOGE(&gResMgrDioLogContext, "Accessing array that is out of bounds for base address, value is %d ", l_bankbase_U8 );
                l_ret_BOOL = false;
            }

            break;

        case 'm':
            if ( l_bankmask_U8 < TI_MAX_BANK_PER_DIO )
            {
                dioOptionsAddr_p[l_bankmask_U8].bank_mask_addr = ( uint32_t ) strtol ( optarg, NULL, 0 );
                if ( ( __get_errno_ptr() != NULL ) && ( ( errno == EINVAL ) || ( errno == ERANGE ) ) )
                {
                    l_status_S32 = EXIT_FAILURE;
                    LOGE(&gResMgrDioLogContext, "unable to convert \"bank_mask_addr\" to unsigned int: %s errno=%d\n", optarg, l_status_S32 );
                    l_ret_BOOL = false;
                }
                else
                {
                }
                
                l_bankmask_U8++;
            }
            else
            {
                LOGE(&gResMgrDioLogContext, "Accessing array that is out of bounds for mask address, value is %d ", l_bankmask_U8 );
                l_ret_BOOL = false;
            }

            break;

        case 'U':
            /* coverity[cert_mem31_c_violation] : FALSE */
            /* coverity[misra_c_2012_rule_22_1_violation] : FALSE */
	        /* coverity[misra_c_2012_directive_4_13_violation] : FALSE */
            /* coverity[var_assign] : FALSE */
            if (UserParm != NULL) 
                {
                    free(UserParm);  // added is added as part of Klockwork Warning fix to Free existing memory if any
                }
            UserParm = strdup(optarg);        
            break;

        default:
            LOGI(&gResMgrDioLogContext, "unknown option ");
            dio_usage();
            l_ret_BOOL = false;
            break;
        }
    }

    if ( ( TI_MAX_BANK_PER_DIO == l_bankbase_U8 ) && ( TI_MAX_BANK_PER_DIO == l_bankmask_U8 ) )
    {
        l_ret_BOOL = true;
    }
    else
    {
        LOGE(&gResMgrDioLogContext, "Incorrect Options : Please re-check the options passed " );
        dio_usage();
    }

    return l_ret_BOOL;
}


/*!****************************************************************************
    * \fn       static void dio_ExitSignal ( int32_t signo )
    * \brief    Function that is called when the DIO driver is terminated by
                sending a SIGTERM signal
    * \param    signo [in] signalno sent by the user
    * \return   void
 *****************************************************************************/
static void dio_ExitSignal ( int32_t signo )
{
    /* Set the flag to indicate Terminate RM. This will exit the dispatch loop */
    ( void ) signo;
    g_DIODone = true;
}

/*!****************************************************************************
    * \fn        static bool dio_count_mask_bits ( ts_dio_addr_t *dioCountAaddr_p )
    * \brief     Function that is called when the DIO driver is launched to count
                 number of bits set in each mask address, which masked bit indicates
                 the corresponding gpio can be used. Total number of gpio's configured
                 will be calulated by checking the mask of each gpio bank and stored.
    * \param     Array of structure in which bank's mask address is stored
    * \return    bool    Return value to indicate true or false for the operation done
 *****************************************************************************/

static bool dio_count_mask_bits ( ts_dio_addr_t *dioCountAaddr_p )
{
    uint32_t l_bank_U32;
    bool l_ret_BOOL = true ;
    uint32_t l_mask_val_U32;
    uint32_t l_setbits_U32 = 0;

    for ( l_bank_U32 = 0; l_bank_U32 < TI_MAX_BANK_PER_DIO; l_bank_U32++ )
    {
        l_mask_val_U32 = dioCountAaddr_p[l_bank_U32].bank_mask_addr;

        while ( l_mask_val_U32 )
        {
            l_setbits_U32 += l_mask_val_U32 & g_set_bit_U32;
            l_mask_val_U32 >>= g_set_bit_U32;
        }

        dioCountAaddr_p[l_bank_U32].set_bits_count_sa = l_setbits_U32;
        g_gpio_id_max_U32 = g_gpio_id_max_U32 + l_setbits_U32;
        LOGD(&gResMgrDioLogContext, "Bank %d has number of bits set %d", l_bank_U32, l_setbits_U32);
        l_setbits_U32 = g_clear_bit_U32;
    }

    LOGD(&gResMgrDioLogContext, "Done with counting of set bits in each bank" );
    return l_ret_BOOL;
}

/*!****************************************************************************
    * /fn        static bool dio_data_extract ( ts_dio_pindata_t *dioPinData_p, uint32_t pin_U32 )
    * \brief     Function that is called when user request to export a pin
    * \param     Array of structure in which bank base address are stored and gpio pin
    * \return    bool    Return value to indicate true or false for the operation done
 *****************************************************************************/

static bool dio_data_extract ( ts_dio_pindata_t *dioPinData_p, uint32_t pin_U32 )
{
    uint32_t l_dio_id_U32 = 0;
    uint32_t l_index_U32 = 0;
    uint32_t l_bank_U32;
    uint32_t l_mask_U32 ;
    uint32_t l_setBitPos_U32;
    bool l_ret_BOOL = true;

    l_dio_id_U32 = pin_U32;
    l_index_U32 = l_dio_id_U32;

    if ( pin_U32 > DIO_MAX_ID )
    {
        LOGE(&gResMgrDioLogContext, "Invalid DIO_ID passed by user : DIO_ID out of range" );
        l_ret_BOOL = false;
    }
    else
    {
        for ( l_bank_U32 = 0; l_bank_U32 < TI_MAX_BANK_PER_DIO; l_bank_U32++ )
        {
            uint32_t temp_count = dioPinData_p->dio_addr_sa[l_bank_U32].set_bits_count_sa;

            if ((l_dio_id_U32 < temp_count) && (l_index_U32 < 256U) )
            {
                dioPinData_p->dio_pin_sa[l_index_U32].bank_num_U32 = l_bank_U32;
                LOGD(&gResMgrDioLogContext, "Bank Number for DIO pin %d is %d", pin_U32, dioPinData_p->dio_pin_sa[l_index_U32].bank_num_U32 );
                break;
            }
            else
            {

                l_dio_id_U32 = l_dio_id_U32 - temp_count;
            }
        }

        if ( l_bank_U32 < TI_MAX_BANK_PER_DIO )
        {
        uint32_t l_maskVal = dioPinData_p->dio_addr_sa[l_bank_U32].bank_mask_addr;
            l_setBitPos_U32 = 0;

            for ( l_mask_U32 = 0; l_mask_U32 < DIO_PIN_PER_BANK; l_mask_U32++ )
            {
                if ( ( l_maskVal & g_set_bit_U32 ) == g_set_bit_U32 )
                {
                    l_setBitPos_U32++;

                    if ( ( l_dio_id_U32 + g_set_bit_U32 ) == l_setBitPos_U32 )
                    {
                        if((l_index_U32 < DIO_MAX_ID)) // added as a part of klockwork warning fix
                        {
                            dioPinData_p->dio_pin_sa[l_index_U32].chnl_num_U32 = l_mask_U32;
                        LOGD(&gResMgrDioLogContext, "Channel Number for DIO pin %d is %d", pin_U32, dioPinData_p->dio_pin_sa[l_index_U32].chnl_num_U32);
                        }
                    }
                }
                l_maskVal = l_maskVal >> g_set_bit_U32;
            }
        }
        else
        {
            LOGE(&gResMgrDioLogContext, "Invalid DIO_ID passed by user : DIO_ID out of range" );
            l_ret_BOOL = false;
        }
    }

    return l_ret_BOOL;
}

/*!****************************************************************************
    * \fn        static int32_t dio_periodic_read_check ( message_context_t *dioPeriodicctp_p, int code, unsigned flags, void *handle )
    * \brief     Function that is called when 4 seconds timer expires
    * \param     message_context_t *dioPeriodicctp_p, int code, unsigned flags, void *handle
    * \return    int    Return Error code to indicate success or failure
 *****************************************************************************/

static int32_t dio_periodic_read_check ( message_context_t *dioPeriodicctp_p, int code, unsigned flags, void *handle )
{
    ( void ) dioPeriodicctp_p;
    ( void ) code;
    ( void ) flags;
    ( void ) handle;

    int32_t l_dio_periodic_task_S32 = 0;
    int32_t l_status_S32 = 0;

    l_dio_periodic_task_S32 = dio_periodic_task ( &g_dio_pindata );

    if ( l_dio_periodic_task_S32 != 0 )
    {
        l_status_S32 = 1;
    }

    return l_status_S32;
}

/*!****************************************************************************
    * \fn       static bool dio_attach_pulse ( ts_dio_dev_t *dioPulseDev_p )
    * \brief    Function to attach pulse to the DIO resource manager. This function is called from the main() of DIO resoucre manager
    * \param[in] sigevent structure
    * \return    bool  Return value to indicate true or false for the operation done
 *****************************************************************************/

static bool dio_attach_pulse ( ts_dio_dev_t *dioPulseDev_p )
{
    bool l_status_BOOL = true;
    //  Initialize an event structure, and attach a pulse to it
    dioPulseDev_p->event.sigev_code = ( int16_t ) pulse_attach ( g_dpp_SP, MSG_FLAG_ALLOC_PULSE, 0, dio_periodic_read_check, NULL );

    if ( dioPulseDev_p->event.sigev_code == -1 )
    {
        LOGE(&gResMgrDioLogContext, "Unable to attach timer pulse" );
        l_status_BOOL = false;
    }
    else
    {
        dioPulseDev_p->event.sigev_coid = message_connect ( g_dpp_SP, MSG_FLAG_SIDE_CHANNEL );

        if ( dioPulseDev_p->event.sigev_coid == -1 )
        {
            LOGE(&gResMgrDioLogContext, "Unable to attach pulse to channel" );
            l_status_BOOL = false;
        }
        else
        {
            dioPulseDev_p->event.sigev_notify = SIGEV_PULSE;
            dioPulseDev_p->event.sigev_priority = -1;
            //We could create several timers and use different sigev values for each
            dioPulseDev_p->event.sigev_value.sival_int = 0;
        }
    }

    return l_status_BOOL;
}
/*!****************************************************************************
    * \fn        static bool dio_setup_timer ( ts_dio_dev_t *dioTimerDev_p )
    * \brief     Function to setup timer and attach it to the pulse and the channel of DIO resource manager.
                 This function is called from the main() of DIO resoucre manager
    * \param[in] dio_dev  . This is dio structure
    * \return    bool  Return value to indicate true or false for the operation done
 *****************************************************************************/
static bool dio_setup_timer ( ts_dio_dev_t *dioTimerDev_p )
{
    bool l_status_timer_BOOL = true;
    int32_t l_ret_S32;
    dioTimerDev_p->timer_id = TimerCreate ( CLOCK_MONOTONIC, &dioTimerDev_p->event );

    if ( dioTimerDev_p->timer_id == -1 )
    {
        LOGE(&gResMgrDioLogContext, "Unable to attach Timer to pulse to channel" );
        l_status_timer_BOOL = false;
    }
    else
    {
        dioTimerDev_p->itime.nsec = DIO_TASK_PERIODICITY * 1000000000U;
        dioTimerDev_p->itime.interval_nsec = DIO_TASK_PERIODICITY * 1000000000U;
        l_ret_S32 = TimerSettime ( dioTimerDev_p->timer_id, 0, &dioTimerDev_p->itime, NULL );

        if ( l_ret_S32 == 0 )
        {
            LOGD(&gResMgrDioLogContext, "Timer started Successfully " );
        }
        else
        {
            l_status_timer_BOOL = false;
            LOGE(&gResMgrDioLogContext, "Periodic Timer start Failed " );
        }
    }

    //And now set up our timer to fire every second
    return l_status_timer_BOOL;
}

/*!****************************************************************************
    * \fn        static int32_t dio_export ( const uint32_t *p_pin_S32 )
    * \brief     Function that is called when user request for export
    * \param     *p_pin_S32 "gpio_id" passed by user to export
    * \return    int32_t Return Error code to indicate success or failure
 *****************************************************************************/

static int32_t dio_export ( const uint32_t *p_pin_S32 )
{
    int32_t l_ret_export_S32 = EXIT_SUCCESS;
    int32_t l_pathId_S32;
    char export_path_direction[PATH_MAX];
    char export_path_value[PATH_MAX];

    ( void ) snprintf ( export_path_direction, PATH_MAX, DIRECTION_PATH, *p_pin_S32 );

    ( void ) snprintf ( export_path_value, PATH_MAX, VALUE_PATH, *p_pin_S32 );

    l_pathId_S32 = resmgr_attach ( g_dpp_SP, &g_rattr, export_path_direction, _FTYPE_ANY, 0, &g_connect_funcs, &g_io_funcs, &g_ioattr );

    if ( l_pathId_S32 == -1 )
    {
        LOGE(&gResMgrDioLogContext, "resmgr_attach on direction path has failed" );
        l_ret_export_S32 = EXIT_FAILURE;
    }
    else
    {
        g_dio_pindata.dio_pin_sa[*p_pin_S32].dir_pathID_S32 = l_pathId_S32;

        l_pathId_S32 = resmgr_attach ( g_dpp_SP, &g_rattr, export_path_value, _FTYPE_ANY, 0, &g_connect_funcs, &g_io_funcs, &g_ioattr );

        if ( l_pathId_S32 == -1 )
        {
            LOGE(&gResMgrDioLogContext, "resmgr_attach on value path has failed" );
            l_ret_export_S32 = EXIT_FAILURE;
        }
        else
        {
            g_dio_pindata.dio_pin_sa[*p_pin_S32].val_pathID_S32 = l_pathId_S32;
            g_dio_pindata.dio_pin_sa[*p_pin_S32].is_valid_BOOL = true;
            LOGD(&gResMgrDioLogContext, "Export is successful for the pin %d & status is : %d",*p_pin_S32, l_ret_export_S32 );
        }
    }

    return l_ret_export_S32;
}


/*!****************************************************************************
    * \fn        static int32_t dio_unexport ( const uint32_t *p_pin_S32 )
    * \brief     Function that is called when user request for export
    * \param     *p_pin_S32 "gpio_id" passed by user to export
    * \return    int32_t Return Error code to indicate success or failure
 *****************************************************************************/

static int32_t dio_unexport ( const uint32_t *p_pin_S32 )
{
    int32_t l_ret1_S32;
    int32_t l_ret2_S32;
    int32_t l_ret_unexport_S32 = EXIT_SUCCESS;
    int32_t l_temp_id_S32;
    l_temp_id_S32 = (int32_t)*p_pin_S32;

    if( l_temp_id_S32 < (int32_t)DIO_MAX_ID )
    {
        l_ret1_S32 = resmgr_detach ( g_dpp_SP, g_dio_pindata.dio_pin_sa[l_temp_id_S32].dir_pathID_S32, _RESMGR_DETACH_ALL );
        
        if( l_ret1_S32 < 0)
        {
            l_ret_unexport_S32 = EXIT_FAILURE;
            LOGE(&gResMgrDioLogContext, "resmgr_detach ret1 failed: %d", l_ret1_S32 );
        }
        else
        {
            l_ret2_S32 = resmgr_detach ( g_dpp_SP, g_dio_pindata.dio_pin_sa[l_temp_id_S32].val_pathID_S32, _RESMGR_DETACH_ALL );

            if ( l_ret2_S32 < 0 )
            {
                l_ret_unexport_S32 = EXIT_FAILURE;
                LOGE(&gResMgrDioLogContext, "resmgr_detach ret2 failed: %d", l_ret2_S32 );
            }
            else
            {
                /* coverity[cert_str31_c_violation] : FALSE */
                /* coverity[cert_arr30_c_violation] : FALSE */
                g_dio_pindata.dio_pin_sa[l_temp_id_S32].is_valid_BOOL = false;
                LOGD(&gResMgrDioLogContext, "resmgr_detach is successful" );
            }
        }
    }
    else
    {
        l_ret_unexport_S32 = EXIT_FAILURE;
        LOGE(&gResMgrDioLogContext, "gpio id:%d exceeding DIO MAX ID", l_temp_id_S32);
    }

    return l_ret_unexport_S32;
}





