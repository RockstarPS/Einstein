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
/*                                                                            *
*******************************************************************************
*  PROJECT NAME :  VMF_TRACE                                                  *
*******************************************************************************
*  MODULE NAME  :  vmf_trace.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :  13 July 2009                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by VMF_TRACE                                                    *
******************************************************************************/
#ifndef __VMF_TRACE_H
#define __VMF_TRACE_H
#include <varargs.h>
#ifdef __cplusplus
extern "C" {
#endif

#if defined(WIN32) || defined(_WINDOWS)
#define DLL_EXPORT  __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#include "nw_os_config.h"


/* definitions */
#define VMF_TRACE_TRID_INVALID      (0)         /* TRID 0 = Innvaid vor single trid */
#define VMF_TRID_VMF                (1)         /* TRID 1 = VMF */

/* trace macros */

#ifdef VMF_TRACE
    #define VMF_TRACE_REGISTER(handle,name)             vmf_trace_register(handle,name)
    #define VMF_TRACE_REGISTER_C(handle,name,time)    	vmf_trace_register_c(handle,name,time)
    #define VMF_TRACE_REGISTER_Z(handle,name)      		vmf_trace_register_c(handle,name,0)
    #define VMF_TRACE_PRINT(a,b,c,d,e)          		vmf_trace(a,b,c,d,e)
    #define VMF_TRACE_PRINTF(a,b,c,d,e,...)     		vmf_trace_printf(a,b,c,d,e,##__VA_ARGS__)
    #define VMF_TRACE_HEX(a,b,c,d,e,f)          		vmf_trace_hex(a,b,c,d,e,f)
    #define VMF_TRACE_SET_SEVERITY(a,b)         		vmf_trace_set_severity(a,b)
    
#else
    #ifndef WIN32
        #define VMF_TRACE_REGISTER(a,b)             (VMF_OK)      
		#define VMF_TRACE_PRINT(a,b,c,d,e)          printf(d);printf(" ");printf(e);printf("\n");fflush(ERROR_CHANNEL);
		#define VMF_TRACE_PRINTF(a,b,c,d,...)		printf(__VA_ARGS__);printf("\n");fflush(ERROR_CHANNEL);
        #define VMF_TRACE_HEX(a,b,c,d,e,f)          
        #define VMF_TRACE_SET_SEVERITY(a,b)         
    #else
        #define VMF_TRACE_REGISTER(a,b)             (VMF_OK)
        #define VMF_TRACE_PRINT(a,b,c,d,e)          printf(d);printf(" ");printf(e);printf("\n");fflush(ERROR_CHANNEL);
        #define VMF_TRACE_PRINTF(a,b,c,d,args...)   printf(args);printf("\n");fflush(ERROR_CHANNEL);
        #define VMF_TRACE_HEX(a,b,c,d,e,f)          
        #define VMF_TRACE_SET_SEVERITY(a,b)         
    #endif
#endif



/*! predefined severities */
#ifdef __cplusplus
typedef enum vmf_trace_severity_t
#else
enum
#endif
{
    /* errors */
    VMF_TRACE_SEVERITY_ERROR = 0,
    VMF_TRACE_SEVERITY_ERROR_1,
    VMF_TRACE_SEVERITY_ERROR_2,
    VMF_TRACE_SEVERITY_ERROR_3,
    VMF_TRACE_SEVERITY_ERROR_4,
    VMF_TRACE_SEVERITY_ERROR_5,
    VMF_TRACE_SEVERITY_ERROR_6,
    VMF_TRACE_SEVERITY_ERROR_7,
    VMF_TRACE_SEVERITY_ERROR_8,
    VMF_TRACE_SEVERITY_ERROR_9,
    VMF_TRACE_SEVERITY_ERROR_10,
    VMF_TRACE_SEVERITY_ERROR_11,
    VMF_TRACE_SEVERITY_ERROR_12,
    VMF_TRACE_SEVERITY_ERROR_13,
    VMF_TRACE_SEVERITY_ERROR_14,
    VMF_TRACE_SEVERITY_ERROR_15,
    VMF_TRACE_SEVERITY_ERROR_16,
    VMF_TRACE_SEVERITY_ERROR_17,
    VMF_TRACE_SEVERITY_ERROR_18,
    VMF_TRACE_SEVERITY_ERROR_19,
    
    /* warnings */
    VMF_TRACE_SEVERITY_WARNING = 30,
    VMF_TRACE_SEVERITY_WARNING_1,
    VMF_TRACE_SEVERITY_WARNING_2,
    VMF_TRACE_SEVERITY_WARNING_3,
    VMF_TRACE_SEVERITY_WARNING_4,
    VMF_TRACE_SEVERITY_WARNING_5,
    VMF_TRACE_SEVERITY_WARNING_6,
    VMF_TRACE_SEVERITY_WARNING_7,
    VMF_TRACE_SEVERITY_WARNING_8,
    VMF_TRACE_SEVERITY_WARNING_9,
    VMF_TRACE_SEVERITY_WARNING_10,
    VMF_TRACE_SEVERITY_WARNING_11,
    VMF_TRACE_SEVERITY_WARNING_12,
    VMF_TRACE_SEVERITY_WARNING_13,
    VMF_TRACE_SEVERITY_WARNING_14,
    VMF_TRACE_SEVERITY_WARNING_15,
    VMF_TRACE_SEVERITY_WARNING_16,
    VMF_TRACE_SEVERITY_WARNING_17,
    VMF_TRACE_SEVERITY_WARNING_18,
    VMF_TRACE_SEVERITY_WARNING_19,

    /* trace messages */
    VMF_TRACE_SEVERITY_INFO = 60,
    VMF_TRACE_SEVERITY_INFO_1,
    VMF_TRACE_SEVERITY_INFO_2,
    VMF_TRACE_SEVERITY_INFO_3,
    VMF_TRACE_SEVERITY_INFO_4,
    VMF_TRACE_SEVERITY_INFO_5,
    VMF_TRACE_SEVERITY_INFO_6,
    VMF_TRACE_SEVERITY_INFO_7,
    VMF_TRACE_SEVERITY_INFO_8,
    VMF_TRACE_SEVERITY_INFO_9,
    VMF_TRACE_SEVERITY_INFO_10,
    VMF_TRACE_SEVERITY_INFO_11,
    VMF_TRACE_SEVERITY_INFO_12,
    VMF_TRACE_SEVERITY_INFO_13,
    VMF_TRACE_SEVERITY_INFO_14,
    VMF_TRACE_SEVERITY_INFO_15,
    VMF_TRACE_SEVERITY_INFO_16,
    VMF_TRACE_SEVERITY_INFO_17,
    VMF_TRACE_SEVERITY_INFO_18,
    VMF_TRACE_SEVERITY_INFO_19,
    VMF_TRACE_SEVERITY_INFO_20
}VMF_TRACE_SEVERIETIES;


/* definition of standard severities that should be used */
#define VMF_TRACE_SEV_STD_ERROR     VMF_TRACE_SEVERITY_ERROR_19
#define VMF_TRACE_SEV_STD_WARNING   VMF_TRACE_SEVERITY_WARNING_19
#define VMF_TRACE_SEV_STD_INFO      VMF_TRACE_SEVERITY_INFO_19
#define VMF_TRACE_SEV_STD_HEX       VMF_TRACE_SEVERITY_INFO_20

#define VMF_TRACE_SEV_OTF_ERROR     VMF_TRACE_SEVERITY_ERROR_19
#define VMF_TRACE_SEV_OTF_WARNING   VMF_TRACE_SEVERITY_WARNING_19
#define VMF_TRACE_SEV_OTF_TRACE     VMF_TRACE_SEVERITY_INFO_19
#define VMF_TRACE_SEV_OTF_HEX       VMF_TRACE_SEVERITY_INFO_20


/* Macros */

#ifdef UNIT_TEST
#define NW_STATIC   
#else
#define NW_STATIC   static  
#endif



/*! vmf-trace-framework function declaration */
DLL_EXPORT  void        vmf_trace_server_pre_init(void);
DLL_EXPORT  vmf_ret_t   vmf_trace_register    (unsigned8 *trid,char *trid_name);
DLL_EXPORT  vmf_ret_t 	vmf_trace_register_c  (unsigned8 *ptrid,char *trid_name,unsigned32 collector_timeout);
DLL_EXPORT  vmf_ret_t   vmf_trace             (unsigned8 trid,unsigned8 severity,char *task,char *scope,char *message);
DLL_EXPORT  vmf_ret_t   vmf_trace_printf      (unsigned8 trid,unsigned8 severity,char *task,char *scope,char *__format, ... );
DLL_EXPORT  vmf_ret_t   vmf_trace_hex         (unsigned8 trid,unsigned8 severity,char *task,char *scope,unsigned8 len,unsigned8 *data);
DLL_EXPORT  vmf_ret_t   vmf_trace_set_severity(unsigned8 trid,unsigned8 severity);

DLL_EXPORT  unsigned32  vmf_trace_get_time_in_ms(void);
DLL_EXPORT  bool vmf_trace_check_filter(unsigned8 trid,unsigned8 severity);


#ifdef __cplusplus
}
#endif

#endif


