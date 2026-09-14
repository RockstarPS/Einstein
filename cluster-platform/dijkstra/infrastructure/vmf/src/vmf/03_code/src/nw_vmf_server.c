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

  \file                 nw_vmf_server.c
  \brief                Main routine for the message framework process

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/
#define _NW_VMF_SERVER_C_

/* system includes */
#include "nw_vmf_cfg.h"
#include "nw_config.h"

#define DLT_STRING
/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_router.h"
#include "nw_vmf_trace.h"

#ifdef VMF_TRACE
    #include "nw_vmf_trace_server.h"
    #ifdef DLT_GW
        #undef DLT_STRING
        #define DLT_STRING  "VMF-DLT gateway"
        #include "nw_vmf_trace_dlt_gw.h"
    #endif /*DLT_GW*/
#endif /*VMF_TRACE*/

#include "nw_vmf_tardis.h"
#include "nw_vmf_ini_parser.h"

#ifdef VMF_EXTS
#include "vmf_extension_starter.h"
#endif

#ifdef VMF_MI
#include "nw_vmf_mi.h"
#else
#define VMF_MI_VERSION_STRING
#endif

#ifdef VMF_FILE_LOGGING
#include "nw_vmf_logger.h"
#endif

#ifndef __ANDROID__
#include "build_time.h"
#endif

extern char * __progname;
extern char progname[];

#define VMF_SERVER_INFO_PRINT(...)  if(true==verbose){(void)printf(__VA_ARGS__);(void)printf("\n");}
#define VMF_SERVER_INFO_PRINT_2(...)  //if(true==verbose){(void)printf(__VA_ARGS__);(void)printf("\n");}
#define VMF_SERVER_ERROR_PRINT(...) {(void)fprintf(ERROR_CHANNEL,"error: ");(void)fprintf(ERROR_CHANNEL,__VA_ARGS__);(void)fprintf(ERROR_CHANNEL,"\n");}

/* definition of version string */
#ifdef DLT_GW
#define VERSION_STRING  VMF_OS_STRING " " VMF_VERSION_STRING " - " IPC_VERSION_STRING " - " VMF_MI_VERSION_STRING " - " DLT_STRING "\n"
#else
#define VERSION_STRING  VMF_OS_STRING " " VMF_VERSION_STRING " - " IPC_VERSION_STRING " - " VMF_MI_VERSION_STRING "\n"
#endif

#define VMF_TIME_SYNC

/* definitions for ini parser - all strings lower case!  */
#define INI_SECTION_VMF                 "vmf"
#define INI_KEY_VMF_STARTUP_Q           "startup_q"
#define INI_KEY_VMF_DEF_SEVERITY        "default_severity"
#define INI_KEY_VMF_MI                  "vmf_mi"
#define INI_KEY_VMF_TARDIS_NAME         "tardis_name"
#define INI_KEY_VMF_TARDIS_CAT          "tardis_cat"
#define INI_KEY_VMF_TARDIS_BROADCAST    "tardis_broadcast"
#define INI_KEY_VMF_VERBOSE             "verbose"
#define INI_KEY_VMF_VERSION_STRING      "version_string"
#define INI_KEY_VMF_TIME_SERVER_ENABLE  "enable_timeserver"
#define INI_KEY_VMF_TIME_CLIENT_ENABLE  "enable_timeclient"
#define INI_KEY_VMF_TIME_SERVER_INTERVALL "timeserver_intervall"

#define INI_SECTION_TRACE_SEVERITIES    "trace_severities"
#define INI_SECTION_DLT                 "dlt"
#define INI_KEY_DLT_ENABLE_DLT          "enable_dlt"
#define INI_KEY_DLT_MSG_GROUPS          "vmf_msg_groups"


bool                enable_dlt_gw=false;
char                tardis_broadcast_addr[16u] = {"255.255.255.255"};
unsigned8           tardis_category=VMF_TARDIS_TC_INVALID;
char                ini_path[255u]={0u};
char                tardis_name[VMF_MAX_TARDIS_NAME_LEN];
bool                vmf_file_system_access = true;
bool                verbose=false;
bool                enable_timeserver = false;
bool                enable_timeclient = false;
unsigned16          timeserver_intervall =0;
#ifdef VMF_FILE_LOGGING

vmf_logger_info_t   vmf_logger_info={.enabled=false,.max_file_len_kb=VMF_LOGG_MAX_DEBUG_FILE_LEN_KB};
#endif


#ifdef VMF_TRACE
/* trace severities in ini file */
extern vmf_ini_trace_severity_t    vmf_ini_trace_severities[MAX_VMF_TRACE_TRIDS];
extern unsigned8                   vmf_ini_trace_severities_count;
#endif


/* local functions */
void        usage(void);
vmf_ret_t   nw_vmf_ini_read(void);



#ifdef VMF_GCOV  /* Automatic coverage test after build needs to flush GCOV data on exit! */
#include <signal.h>
extern void __gcov_flush(void);
struct sigaction act;
void sighandler(int signum, siginfo_t *info, void *ptr)
{
    __gcov_flush();
    exit(0);
}
#endif


/***************************************************************************//**
 *
 *   Main entry point for message framework process.
 *      optional arguments
 *      -q              for startup queue enabled
 *      -s nnnn         for default severity
 *   \param[in]     argc -- number of arguments
 *   \param[in]     argv -- pointer to array with arguments
 *   \return        error code
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{

#ifdef VMF_GCOV
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = sighandler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &act, NULL);
#endif

    vmf_ret_t ret_val = 0;
    int         opt=0;
#ifdef VMF_TRACE
    bool        startup_q = false;
    unsigned16  severity=VMF_TRACE_DEF_SEVERITY;
#endif

#ifndef INTEGRITY   /* optarg defined in getopt.h from OS! */
    extern char *optarg;
#endif
    bool exit_vmf = false; 

    NW_VMF_DEBUG_PRINT(NW_VMF_DBG_ASP_ROUTER, NW_VMF_DBG_LVL_INFO, ("vmf_server started\n"));

    /* prepare default tardis name */
    nw_os_sstrncpy(tardis_name, VMF_PROJECT_STRING, sizeof(tardis_name));
    (void) nw_get_app_name(progname,MAX_PROGNAME_LEN);

#if defined __WINDOWS__ || defined INTEGRITY
    (void) printf ("%s",VERSION_STRING);
#endif

#ifdef VMF_PRINT_BUILD_TIME
    (void) printf("\nVMF build time: %s by %s\n", build_time, vmf_user);
#endif


    /* optional arguments                 */
    /* -q       for startup queue enabled */
    /* -s nnnn  for default severity      */
    while ((opt = getopt(argc, argv, "?hHmqs:vc:C:nNt:T:b:B:p:di")) != -1)
    {
        switch (opt)
        {
#ifdef VMF_TRACE
            case 'q':
                startup_q = true;
                (void) vmf_trace_set_def_startup_queue(startup_q);
                break;
#endif

#ifdef VMF_TRACE
            case 's':
            {
                severity = (unsigned16)atoi(optarg);
                if (severity > 255)
                {
                    severity=VMF_TRACE_DEF_SEVERITY;
                }
                (void) vmf_trace_set_def_severity((unsigned8)severity);
                (void) printf("set default trace severity to %d\n",severity);
                /* delete old persistent file so that a new file is created */
                (void) remove(VMF_TRACE_PERSISTENT_DATA);
                break;
            }
#endif
            case 'v':
                /* print VMF version string */
#ifndef __WINDOWS__
                (void) printf ("%s",VERSION_STRING);
#endif
                exit_vmf = true;
                break;

#ifdef VMF_MI
            case 'm':
                /* server is mi-server */
#ifndef __WINDOWS__
                (void) printf ("%s",VERSION_STRING);
#endif
                nw_vmf_mi_enable_server();
                break;
#endif
            case 'n':
            case 'N':
                /* no file system access */
                (void) printf ("%s !Persistent write disabled!\n",VMF_OS_STRING " " VMF_VERSION_STRING );
                vmf_file_system_access = false;
                break;


            case '?':
            case 'h':
            case 'H':
                /* show usage */
                usage();
                exit_vmf = true;
                break;

            case 'p':
                /* get ini path */
                nw_os_sstrncpy(ini_path, optarg, sizeof(ini_path));
                break;


#ifdef VMF_TARDIS
            case 't':
            case 'T':
                /* tardis name */
                nw_os_sstrncpy(tardis_name, optarg, sizeof(tardis_name));
                nw_os_sstrncpy(progname, tardis_name, MAX_PROGNAME_LEN);
                break;

            case 'c':
            case 'C':
                /* tardis command category */
                tardis_category = (unsigned8)atoi(optarg);
                break;

            case 'b':
            case 'B':
                /* tardis broadcast addr */
                (void) strncpy(tardis_broadcast_addr, optarg, sizeof(tardis_broadcast_addr) - 1u); /* don't use nw_os_sstrncpy since this would cut the last sign! */
                break;
#endif
#ifdef DLT_GW
            case 'd':
                /* VMF-dlt gateway */
                enable_dlt_gw = true;
                (void) printf("%s enabled\n",DLT_STRING);
                break;
#endif
            case 'i':
                /* read vmf.ini file */
                (void) nw_vmf_ini_read();
                break;

        }
    }
    
    if(exit_vmf == false)
    {
        /* call pre-init functions */
        nw_vmf_ipc_pre_init();
#ifdef VMF_TRACE
        vmf_trace_server_pre_init();
#endif

        /* start the router */
        if (VMF_OK != nw_vmf_router())
        {
            ret_val = VMF_ERROR;
        }
    }

    return (int)ret_val;

}

/***************************************************************************//**
 *
 *   display usage string on console
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
void usage(void)
{
    (void) printf("************************************************************************\n");
    (void) printf("** vmf                                                                **\n");
    (void) printf("************************************************************************\n");
    (void) printf("**                                                                    **\n");
    (void) printf("** usage: vmf [options]                                               **\n");
    (void) printf("**                                                                    **\n");
    (void) printf("**     Opt.           Description                                     **\n");
 #ifdef VMF_TRACE
    (void) printf("**     -q             enable VMF-Trace startup queue                  **\n");
    (void) printf("**     -s <sevirity>  set start severity for all clients              **\n");
 #endif
 #ifdef VMF_MI
    (void) printf("**     -m             start multi instance (mi)server                 **\n");
 #endif
    (void) printf("**     -v             print VMF version string                        **\n");
    (void) printf("**     -n             disable file system access (no persitent data!) **\n");
#ifdef VMF_TARDIS
    (void) printf("**     -t             tardis name      e.g. vmf -t \" Eagle\"         **\n");
    (void) printf("**     -c             tardis category  e.g. vmf -c 5                  **\n");
    (void) printf("**     -b             tardis braodcast addr e.g -b 192.168.1.255      **\n");
#endif
    (void) printf("**     -i             read vmf.ini file                               **\n");
    (void) printf("**     -p             optional ini path e.g. vmf -p \"\\usr\"         **\n");
#ifdef DLT_GW
    (void) printf("**     -d             enable VMF-dlt gateway                          **\n");
#endif
    (void) printf("**                                                                    **\n");
    (void) printf("************************************************************************\n");
}


/***************************************************************************//**
 *
 *   read and parse vmf.ini file
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
vmf_ret_t   nw_vmf_ini_read(void)
{
    FILE *      stream=NULL;
    char        value[255];
    int         ret_len=0;
    vmf_ret_t   vmf_ret=VMF_OK;

#ifdef VMF_TRACE
    char        key[255];
    int         i;
#endif    

    VMF_SERVER_INFO_PRINT("read %s file in %s",VMF_INI_FILE,ini_path);

    /* open ini file and read number of sections */
    /* create file-name with path  */
    stream = ini_parser_open(VMF_INI_FILE);

    if (stream != NULL)
    {
        /* key - verbose */
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_VERBOSE,value,sizeof(value));
        if ((ret_len>0) && ('T'==(char)toupper((int)value[0])))
        {
            verbose=true;
        }
        #ifndef __WINDOWS__         /* already printed in windows*/
        /* key - version_string */
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_VERSION_STRING,value,sizeof(value));
        if ((ret_len>0) && ('T'==(char)toupper((int)value[0])))
        {
            (void) printf ("%s",VERSION_STRING);
        }
        #endif

#ifdef DLT_GW
        /* read the DLT  section */
        /* key enable_dlt */
        ret_len = ini_parser_get_val(stream,INI_SECTION_DLT,INI_KEY_DLT_ENABLE_DLT,value,sizeof(value));
        if ((ret_len>0) && ('T'==(char)toupper((int)value[0])))
        {
            /* enable dlt */
            enable_dlt_gw = true;
            VMF_SERVER_INFO_PRINT("%s enabled",DLT_STRING);
        }
        /* key vmf_msg_groups */
        ret_len = ini_parser_get_val(stream,INI_SECTION_DLT,INI_KEY_DLT_MSG_GROUPS,value,sizeof(value));
        if (ret_len>0)
        {
            unsigned8   groups[MAX_GROUP_NUM];
            int         groups_num=0;
            groups_num = ini_parser_get_byte_list(value,groups,MAX_GROUP_NUM);

            /* register groups at the dlt-gw */
            vmf_ret = nw_vmf_dlt_set_monitor_msg_grps(groups,groups_num);
            if (vmf_ret != VMF_OK)
            {
                VMF_SERVER_ERROR_PRINT("unable to register messages groups to vmf-dlt gateway, error=%d",vmf_ret);
            }
        }
#endif


        /* read the VMF section */
#ifdef VMF_MI
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_MI,value,sizeof(value));
        if ((ret_len>0) && ('T'==(char)toupper((int)value[0])))
        {
            /* enable dlt */
            nw_vmf_mi_enable_server();
            VMF_SERVER_INFO_PRINT("vmf_mi enabled");
        }
#endif
#ifdef VMF_TRACE
        /* key default_severity*/
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_DEF_SEVERITY,value,sizeof(value));
        if (ret_len>0)
        {
            unsigned16  severity=VMF_TRACE_DEF_SEVERITY;

            severity = (unsigned16)atoi(value);
            if (severity > 255)
            {
                severity=VMF_TRACE_DEF_SEVERITY;
            }
            (void)vmf_trace_set_def_severity((unsigned8)severity);
            VMF_SERVER_INFO_PRINT("set default trace severity to %d",severity);
            /* delete old persistent file so that a new file is created */
            (void)remove(VMF_TRACE_PERSISTENT_DATA);
        }

        /* key startup_q */
        ret_len = ini_parser_get_val(stream,"VMF",INI_KEY_VMF_STARTUP_Q,value,sizeof(value));
        if ((ret_len>0) && ('T'==(char)toupper((int)value[0])))
        {
            /* enable startup queue */
            (void)vmf_trace_set_def_startup_queue(true);
            VMF_SERVER_INFO_PRINT("VMF tracer startup-queue enabled");
        }
#endif

#ifdef VMF_TARDIS
        /* tardis values */
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TARDIS_NAME,value,sizeof(value));
        if (ret_len>0)
        {
            nw_os_sstrncpy(tardis_name, value, sizeof(tardis_name));
            nw_os_sstrncpy(progname, tardis_name, MAX_PROGNAME_LEN);
            VMF_SERVER_INFO_PRINT("VMF tardis-name=%s",tardis_name);
        }
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TARDIS_CAT,value,sizeof(value));
        if (ret_len>0)
        {
            tardis_category = (unsigned8)atoi(value);
            VMF_SERVER_INFO_PRINT("VMF tardis-category='%d'",tardis_category);
        }
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TARDIS_BROADCAST,value,sizeof(value));
        if (ret_len>0)
        {
            (void) strncpy(tardis_broadcast_addr, value, sizeof(tardis_broadcast_addr) - 1u); /* don't use nw_os_sstrncpy since this would cut the last sign! */
            VMF_SERVER_INFO_PRINT("VMF tardis broadcast-address='%s'",tardis_broadcast_addr);
        }
#endif

#ifdef VMF_TIME_SYNC
        /* vmf time server values */
        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TIME_SERVER_ENABLE,value,sizeof(value));
        if ((ret_len > 0) && ('T'==(char)toupper((int)value[0])))
        {
            /* enable time server */
            enable_timeserver = true;
            VMF_SERVER_INFO_PRINT("time-server enabled");
        }

        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TIME_SERVER_INTERVALL,value,sizeof(value));
        if (ret_len>0)
        {
            timeserver_intervall = (unsigned16)atoi(value);
            VMF_SERVER_INFO_PRINT("time-server_intervall=%d",timeserver_intervall);
        }

        ret_len = ini_parser_get_val(stream,INI_SECTION_VMF,INI_KEY_VMF_TIME_CLIENT_ENABLE,value,sizeof(value));
        if ((ret_len > 0) && ('T'==(char)toupper((int)value[0])))
        {
            /* enable time client */
            enable_timeclient = true;
            VMF_SERVER_INFO_PRINT("time-client enabled");
        }

#endif

#ifdef VMF_TRACE
        /* vmf trace severities */
        vmf_ini_trace_severities_count = 0;
        for (i=0; i<MAX_VMF_TRACE_TRIDS; i++)
        {
            ret_len = ini_parser_get_key_num_val(stream, INI_SECTION_TRACE_SEVERITIES, (unsigned16)i,
                                                 &key[0], sizeof(key), &value[0], sizeof(value));
            if (ret_len >= 0)
            {
                if (ret_len < MAX_VMF_TRACE_TRIDS)
                {
                    /* this looks like a valid entry */
                    nw_os_sstrncpy(&vmf_ini_trace_severities[vmf_ini_trace_severities_count].name[0], key, MAX_TRACE_NAME_LEN);
                    vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity = (unsigned8) atoi(value);
                    if (vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity > 127)
                    {
                        vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity = 127;
                    }
                    if (vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity == 0)
                    {
                        vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity = 1;
                    }

                    VMF_SERVER_INFO_PRINT("trace severity for %s = %d", vmf_ini_trace_severities[vmf_ini_trace_severities_count].name,
                                                                        vmf_ini_trace_severities[vmf_ini_trace_severities_count].severity);
                    vmf_ini_trace_severities_count++;
                }
                else
                {
                    /* this is too much --> stop reading */
                    break;
                }
            }
            else if (INI_PARSER_EMPTY_LINE == ret_len)
            {
                /* do nothing */
            }
            else if (INI_PARSER_END_OF_SECTION == ret_len)
            {
                /* end of section --> stop reading */
                break;
            }
            else
            {
                /* error --> stop reading */
                break;
            }
        }
#endif

#ifdef VMF_FILE_LOGGING
        /* read logging section */
        VMF_SERVER_INFO_PRINT_2("read logging section");
        vmf_logger_info.enabled = false;
        ret_len = ini_parser_get_val(stream,VMF_INI_LOGGING_SEC,VMF_INI_LOG_ENABLE_KEY,value,sizeof(value));
        if ((ret_len > 0) && ('T'==(char)toupper((int)value[0])))
        {
            /* logging enabled  */
            vmf_logger_info.enabled = true;
            VMF_SERVER_INFO_PRINT("logging enabled");

            /* get the path */
            ret_len = ini_parser_get_val(stream,VMF_INI_LOGGING_SEC,VMF_INI_LOG_PATH_KEY,vmf_logger_info.path,sizeof(vmf_logger_info.path));
            if (ret_len > 0)
            {
                VMF_SERVER_INFO_PRINT("logging-path=%s",vmf_logger_info.path);
            }

            /* get the max file len */
            ret_len = ini_parser_get_val(stream,VMF_INI_LOGGING_SEC,VMF_INI_LOG_FILE_LEN_KEY,value,sizeof(value));
            if (ret_len > 0)
            {
                vmf_logger_info.max_file_len_kb = atoi(value);
                VMF_SERVER_INFO_PRINT_2("logging_max_file_len=%d",vmf_logger_info.max_file_len_kb);
            }

            /* get the max file time */
            ret_len = ini_parser_get_val(stream,VMF_INI_LOGGING_SEC,VMF_INI_LOG_FILE_TIME_KEY,value,sizeof(value));
            if (ret_len > 0)
            {
                vmf_logger_info.max_file_time_s = atoi(value);
                VMF_SERVER_INFO_PRINT_2("logging_max_file_time_s=%d",vmf_logger_info.max_file_time_s);
            }

            /* check range for logging time and logging file size */
            if ((vmf_logger_info.max_file_time_s > VMF_LOGG_MAX_DEBUG_FILE_TIME_S) || (0 == vmf_logger_info.max_file_time_s))
            {
                VMF_SERVER_INFO_PRINT("max_file_time_s=%d - so set to VMF_LOGG_MAX_DEBUG_FILE_TIME",vmf_logger_info.max_file_time_s);
                vmf_logger_info.max_file_time_s = VMF_LOGG_MAX_DEBUG_FILE_TIME_S;
            }
            if ((vmf_logger_info.max_file_len_kb > VMF_LOGG_MAX_DEBUG_FILE_LEN_KB) || (0 == vmf_logger_info.max_file_len_kb))
            {
                VMF_SERVER_INFO_PRINT("max_file_len_kb=%d - so set to VMF_LOGG_MAX_DEBUG_FILE_LEN",vmf_logger_info.max_file_len_kb);
                vmf_logger_info.max_file_len_kb = VMF_LOGG_MAX_DEBUG_FILE_LEN_KB;
            }

            /* start logging thread */
            vmf_ret = vmf_logger_create_thread();
            if (vmf_ret != VMF_OK)
            {
                VMF_SERVER_ERROR_PRINT("vmf_logger_create_thread() failed");
            }
        }

#endif
        ini_parser_close(stream);

#ifdef VMF_EXTS
        vmf_start_extensions(verbose);
#endif
    }
    else
    {
         VMF_SERVER_ERROR_PRINT("unable to open vmf-ini file: %s",VMF_INI_FILE);
         vmf_ret = VMF_ERROR;
    }
    return vmf_ret;
}


#undef _NW_VMF_SERVER_C_
