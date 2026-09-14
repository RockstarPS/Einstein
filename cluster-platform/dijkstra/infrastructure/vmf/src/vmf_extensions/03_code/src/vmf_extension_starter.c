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

/***************************************************************************

  Module:               vmf_exension_starter.c
  Description:          this thread will start vmf extensions

  Project Scope:        vmf

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#include "nw_vmf.h"
#include "nw_os_config.h"
#include "nw_config.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_ini_parser.h"
#include "vmf_extension_starter.h"

/* macros */

#if 0
    #ifdef VMF_TRACE
        #define VMF_EXTS_DEBUG_INFO(...)             VMF_TRACE_PRINTF(vmf_exts_trid, VMF_TRACE_SEVERITY_INFO, __func__, VMF_TRACE_EXTS_SCOPE, __VA_ARGS__);
        #define VMF_EXTS_DEBUG_WARNING(...)          VMF_TRACE_PRINTF(vmf_exts_trid, VMF_TRACE_SEVERITY_WARNING, __func__, VMF_TRACE_EXTS_SCOPE, __VA_ARGS__);
        #define VMF_EXTS_DEBUG_ERROR(...)            VMF_TRACE_PRINTF(vmf_exts_trid, VMF_TRACE_SEVERITY_ERROR, __func__, VMF_TRACE_EXTS_SCOPE, __VA_ARGS__);
    #else
        #define VMF_EXTS_DEBUG_INFO( ...)            {printf("info:    ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}
        #define VMF_EXTS_DEBUG_WARNING( ...)         {printf("warning: ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}
        #define VMF_EXTS_DEBUG_ERROR( ...)           {printf("error:   ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");nw_sleep_ms(10);}
    #endif
#else
    #define VMF_EXTS_DEBUG_INFO( ...)
    #define VMF_EXTS_DEBUG_WARNING( ...)
    #define VMF_EXTS_DEBUG_ERROR( ...)
#endif


static  unsigned8           vmf_exts_trid = 0;
static  bool                verbose=false;

/* local functions */
static void *nw_vmf_exts_starter_thread(void *pNoArg);
static void nw_vmf_exts_start_process(char *extension);



/*************************************************************************//**
 *
 *   start all vmf-extensions that are defined in vmf.ini\n
 *
 *
 *
 *   \param[in]     void
 *
 *   \return        void
 *
 ******************************************************************************/

void vmf_start_extensions(bool ver)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;

    VMF_EXTS_DEBUG_INFO("start");
    verbose=ver;

    /* set thread stack */
    (void) pthread_attr_init( &attr );

    #ifndef __ANDROID__
    if ( pthread_attr_setstacksize(&attr, VMF_EXTS_STACK_SIZE ) != 0 )
    {
       VMF_EXTS_DEBUG_ERROR("nw_vmf_mi_create_starter_thread() - pthread_attr_setstacksize() failed");
    }
    #endif

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, (void * (*)(void *))nw_vmf_exts_starter_thread, NULL);
    (void) pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_EXTS_DEBUG_ERROR("pthread_create() failed, errno = %d",iRet);
    }
    else
    {
        nw_os_set_thread_name(th,"nw vmf-mi extension-starter thread");
    }
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_exts_starter_thread(void *pNoArg)
 *
 *   Description:   vmf-extension starter thread
 *
 *   \param         ignore
 *   \return        NULL
 *
 ******************************************************************************/
static void *nw_vmf_exts_starter_thread(void *pNoArg)
{
    FILE *      stream=NULL;
    char        value[255];
    int         ret_len=0;
    int         key_num;
    int         cnt=0;

    VMF_EXTS_DEBUG_INFO("started");

    /* wait until VMF is initialized */
    VMF_EXTS_DEBUG_INFO("register to trace server");
    while(true)
    {
        nw_sleep_ms(100);
        (void)VMF_TRACE_REGISTER(&vmf_exts_trid, VMF_TRACE_EXTS);
        if (vmf_exts_trid>0)
        {
             break;
        }
        cnt++;
    }
    VMF_EXTS_DEBUG_INFO("connected to trace server %d",cnt);

    stream = ini_parser_open(VMF_INI_FILE);

    /* read all keys */
    for (key_num=0;key_num<VMF_EXTS_MAX_KEYS;key_num++)
    {
        /* read a single key */
        char key[255];

        (void) snprintf(key,sizeof(key),"%s%d",INI_KEYS_EXTS,key_num);
        VMF_EXTS_DEBUG_INFO("read section:%s, key:%s",INI_SECTION_EXTS,key);
        ret_len = ini_parser_get_val(stream,INI_SECTION_EXTS,key,value,sizeof(value));
        VMF_EXTS_DEBUG_INFO("ret_len=%d, value=%s",ret_len, value);
        if (ret_len>0)
        {
            /* found a key */
            nw_vmf_exts_start_process(value);
        }
    }
    ini_parser_close(stream);

    return NULL;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_exts_start_process()
 *
 *   Description:   start a vmf extension
 *
 *   \param         name and path of extension
 *   \return        NULL
 *
 ******************************************************************************/
static void nw_vmf_exts_start_process(char *extension)
{
    VMF_EXTS_DEBUG_INFO("start extension %s",extension);
    if (verbose)
    {
        (void) printf("starting VMF server extension %s\n",extension);
    }
    (void) system(extension);
}
